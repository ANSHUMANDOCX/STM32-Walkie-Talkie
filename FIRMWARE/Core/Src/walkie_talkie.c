#include "walkie_talkie.h"
#include "sx1278.h"
#include "nokia5110.h"
#include "buzzer.h"
#include <string.h>
#include <stdio.h>

/* ─── Audio buffers ──────────────────────────────────── */
volatile int16_t adc_buf[DMA_BUFFER_SIZE];  // mic input (ping-pong)
volatile int16_t i2s_buf[DMA_BUFFER_SIZE];  // speaker output (ping-pong)

/* ─── LoRa packet buffer ─────────────────────────────── */
static uint8_t  lora_tx_buf[LORA_PACKET_SIZE];
static uint8_t  lora_rx_buf[LORA_PACKET_SIZE];

/* ─── State ──────────────────────────────────────────── */
static volatile WalkieTalkieState state = STATE_RX_IDLE;
static volatile bool  lora_irq_flag     = false;
static volatile bool  audio_half_ready  = false;
static volatile bool  audio_full_ready  = false;
static          int16_t rssi_last       = 0;
static          uint8_t battery_pct     = 100;
static          uint32_t bat_check_tick = 0;
static          uint32_t lcd_update_tick= 0;
static          bool    was_charging    = false;

/* ─────────────────────────────────────────────────────── *
 *  BATTERY
 * ─────────────────────────────────────────────────────── */
static uint8_t Battery_ReadPercent(void) {
    /* Battery voltage divider is on a separate ADC channel.
     * Here we do a single software-triggered conversion.
     * Adjust BAT_ADC_FULL / BAT_ADC_EMPTY in walkie_talkie.h
     * to match your actual resistor divider ratio.            */
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 10);
    uint32_t raw = HAL_ADC_GetValue(&hadc1);
    HAL_ADC_Stop(&hadc1);

    if (raw >= BAT_ADC_FULL)  return 100;
    if (raw <= BAT_ADC_EMPTY) return 0;
    return (uint8_t)(((raw - BAT_ADC_EMPTY) * 100UL) /
                     (BAT_ADC_FULL - BAT_ADC_EMPTY));
}

/* ─────────────────────────────────────────────────────── *
 *  AUDIO — DMA callbacks (called from stm32f4xx_it.c)
 * ─────────────────────────────────────────────────────── */
/* Half-complete: first 160 samples of adc_buf are ready   */
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef *hadc) {
    if (hadc->Instance == ADC1) audio_half_ready = true;
}

/* Full-complete: second 160 samples of adc_buf are ready  */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc) {
    if (hadc->Instance == ADC1) audio_full_ready = true;
}

/* ─────────────────────────────────────────────────────── *
 *  AUDIO — process one 160-sample frame
 *  offset = 0 for first half, 160 for second half
 * ─────────────────────────────────────────────────────── */
static void Audio_ProcessFrame(uint16_t offset) {
    if (state != STATE_TRANSMITTING) return;

    /* Step 1: centre the ADC samples (remove DC bias ~2048) */
    int16_t pcm[CODEC2_SAMPLES_PER_FRAME];
    for (int i = 0; i < CODEC2_SAMPLES_PER_FRAME; i++) {
        pcm[i] = (int16_t)adc_buf[offset + i] - 2048;
        pcm[i] <<= 4; // scale 12-bit to 16-bit range
    }

    /* Step 2: Codec2 encode
     * TODO: replace with actual codec2_encode() call once
     * you port the Codec2 library into your project.
     * codec2_encode(codec2_state, lora_tx_buf, pcm);
     * For now we do a simple raw copy for testing:           */
    memcpy(lora_tx_buf, pcm, LORA_PACKET_SIZE);

    /* Step 3: send over LoRa */
    SX1278_Send(lora_tx_buf, LORA_PACKET_SIZE);
}

/* ─────────────────────────────────────────────────────── *
 *  AUDIO — play received frame into I2S buffer
 * ─────────────────────────────────────────────────────── */
static void Audio_PlayFrame(uint8_t *encoded, uint8_t len) {
    /* Step 1: Codec2 decode
     * TODO: replace with actual codec2_decode() call.
     * codec2_decode(codec2_state, pcm, encoded);
     * For now copy directly into i2s_buf for testing:       */
    int16_t pcm[CODEC2_SAMPLES_PER_FRAME];
    memcpy(pcm, encoded, sizeof(pcm));

    /* Step 2: write into the inactive half of i2s_buf       */
    static uint8_t half = 0;
    uint16_t offset = half ? CODEC2_SAMPLES_PER_FRAME : 0;
    memcpy((void*)&i2s_buf[offset], pcm, CODEC2_SAMPLES_PER_FRAME * 2);
    half ^= 1;
}

/* ─────────────────────────────────────────────────────── *
 *  LORA IRQ — called from EXTI interrupt handler
 * ─────────────────────────────────────────────────────── */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if (GPIO_Pin == LORA_DIO0_PIN) {
        lora_irq_flag = true;
    }
}

/* ─────────────────────────────────────────────────────── *
 *  LORA IRQ — handle in main loop (not in ISR)
 * ─────────────────────────────────────────────────────── */
static void LoRa_HandleIRQ(void) {
    uint8_t flags = SX1278_GetIRQFlags();
    SX1278_ClearIRQ();

    if (flags & IRQ_RX_DONE) {
        if (flags & IRQ_PAYLOAD_CRC_ERROR) {
            // CRC error — discard packet
            SX1278_SetRxMode();
            return;
        }
        // Valid packet received
        uint8_t len = SX1278_Receive(lora_rx_buf, LORA_PACKET_SIZE);
        rssi_last   = SX1278_GetRSSI();

        if (state == STATE_RX_IDLE) {
            state = STATE_RECEIVING;
            // Light RX LED
            HAL_GPIO_WritePin(LED_RX_PORT, LED_RX_PIN, GPIO_PIN_SET);
            Buzzer_RxReceived();
        }

        Audio_PlayFrame(lora_rx_buf, len);
        SX1278_SetRxMode(); // stay in RX
    }

    if (flags & IRQ_TX_DONE) {
        // TX complete — go back to RX
        SX1278_SetRxMode();
    }
}

/* ─────────────────────────────────────────────────────── *
 *  PTT — poll in main loop
 * ─────────────────────────────────────────────────────── */
static void PTT_Handle(void) {
    static bool ptt_prev = false;
    bool ptt_now = (HAL_GPIO_ReadPin(PTT_PORT, PTT_PIN) == GPIO_PIN_RESET);

    if (ptt_now && !ptt_prev) {
        // PTT pressed — start TX
        state = STATE_TRANSMITTING;
        SX1278_SetTxMode();
        HAL_GPIO_WritePin(LED_TX_PORT, LED_TX_PIN, GPIO_PIN_SET);
        HAL_GPIO_WritePin(LED_RX_PORT, LED_RX_PIN, GPIO_PIN_RESET);
        Buzzer_TxStart();
        LCD_ShowStatus("  ** TX **  ");
        LCD_Update();
    }

    if (!ptt_now && ptt_prev) {
        // PTT released — back to RX
        state = STATE_RX_IDLE;
        SX1278_SetRxMode();
        HAL_GPIO_WritePin(LED_TX_PORT, LED_TX_PIN, GPIO_PIN_RESET);
        Buzzer_TxStop();
        LCD_ShowStatus("   LISTEN   ");
        LCD_Update();
    }

    ptt_prev = ptt_now;
}

/* ─────────────────────────────────────────────────────── *
 *  CHARGING — poll in main loop
 * ─────────────────────────────────────────────────────── */
static void Charging_Handle(void) {
    bool chrg  = (HAL_GPIO_ReadPin(CHRG_STAT_PORT,  CHRG_STAT_PIN)  == GPIO_PIN_RESET);
    bool stdby = (HAL_GPIO_ReadPin(STDBY_STAT_PORT, STDBY_STAT_PIN) == GPIO_PIN_RESET);

    LCD_ShowCharging(chrg);

    // Detect charge complete transition
    if (stdby && !was_charging) {
        Buzzer_ChargingComplete();
    }
    was_charging = chrg;
}

/* ─────────────────────────────────────────────────────── *
 *  BATTERY — check every 30 seconds
 * ─────────────────────────────────────────────────────── */
static void Battery_Handle(void) {
    uint32_t now = HAL_GetTick();
    if (now - bat_check_tick < 30000) return;
    bat_check_tick = now;

    battery_pct = Battery_ReadPercent();
    LCD_ShowBattery(battery_pct);

    if (battery_pct <= BAT_CRITICAL_THRESHOLD) {
        Buzzer_CriticalBattery();
    } else if (battery_pct <= BAT_LOW_THRESHOLD) {
        Buzzer_LowBattery();
    }
}

/* ─────────────────────────────────────────────────────── *
 *  LCD — refresh every 500ms
 * ─────────────────────────────────────────────────────── */
static void LCD_Handle(void) {
    uint32_t now = HAL_GetTick();
    if (now - lcd_update_tick < 500) return;
    lcd_update_tick = now;

    LCD_ShowRSSI(rssi_last);
    LCD_ShowBattery(battery_pct);

    // Show RX idle if not actively TX/RX
    if (state == STATE_RX_IDLE) {
        LCD_ShowStatus("   LISTEN   ");
        HAL_GPIO_WritePin(LED_RX_PORT, LED_RX_PIN, GPIO_PIN_RESET);
    }

    LCD_Update();
}

/* ─────────────────────────────────────────────────────── *
 *  INIT
 * ─────────────────────────────────────────────────────── */
void WalkieTalkie_Init(void) {
    // LCD
    LCD_Init();
    LCD_Clear();
    LCD_ShowStatus(" WALKIE-TALK");
    LCD_ShowBattery(100);
    LCD_ShowRSSI(0);
    LCD_ShowCharging(false);
    LCD_ShowChannel(1);
    LCD_Update();

    // Buzzer
    Buzzer_Init();
    Buzzer_PowerOn();

    // LoRa
    LCD_ShowStatus(" INIT LORA  ");
    LCD_Update();

    bool ok = SX1278_Init(LORA_FREQUENCY, LORA_SF, LORA_BW,
                          LORA_CR, LORA_PREAMBLE, LORA_TX_POWER);
    if (!ok) {
        LCD_ShowStatus(" LORA FAIL! ");
        LCD_Update();
        Buzzer_Beep(BUZZER_TONE_LOW, 1000);
        while (1); // halt — LoRa init failed
    }

    SX1278_SetRxMode();

    // Start ADC DMA for mic
    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc_buf, DMA_BUFFER_SIZE);

    // Start I2S DMA for speaker (silent buffer to start)
    memset((void*)i2s_buf, 0, sizeof(i2s_buf));
    HAL_I2S_Transmit_DMA(&hi2s3, (uint16_t*)i2s_buf, DMA_BUFFER_SIZE);

    // Start ADC trigger timer
    HAL_TIM_Base_Start(&htim2);

    // Initial battery reading
    battery_pct = Battery_ReadPercent();

    LCD_ShowStatus("   LISTEN   ");
    LCD_ShowBattery(battery_pct);
    LCD_Update();
}

/* ─────────────────────────────────────────────────────── *
 *  MAIN LOOP
 * ─────────────────────────────────────────────────────── */
void WalkieTalkie_Run(void) {
    // Handle LoRa IRQ
    if (lora_irq_flag) {
        lora_irq_flag = false;
        LoRa_HandleIRQ();
    }

    // Handle audio frame (first half of ping-pong buffer)
    if (audio_half_ready) {
        audio_half_ready = false;
        Audio_ProcessFrame(0);
    }

    // Handle audio frame (second half of ping-pong buffer)
    if (audio_full_ready) {
        audio_full_ready = false;
        Audio_ProcessFrame(CODEC2_SAMPLES_PER_FRAME);
    }

    // Poll PTT button
    PTT_Handle();

    // Poll charging status
    Charging_Handle();

    // Check battery level
    Battery_Handle();

    // Refresh LCD
    LCD_Handle();
}
