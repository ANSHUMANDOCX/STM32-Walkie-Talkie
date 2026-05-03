#ifndef WALKIE_TALKIE_H
#define WALKIE_TALKIE_H

#include "stm32f4xx_hal.h"
#include <stdint.h>
#include <stdbool.h>

/* ─── Audio ─────────────────────────────────────────── */
#define AUDIO_SAMPLE_RATE       8000
#define CODEC2_SAMPLES_PER_FRAME 160        // @ 2400 bps mode
#define DMA_BUFFER_SIZE         (CODEC2_SAMPLES_PER_FRAME * 2)  // ping-pong

/* ─── LoRa / SX1278 ─────────────────────────────────── */
#define LORA_FREQUENCY          433000000UL // 433 MHz
#define LORA_SF                 7           // Spreading Factor
#define LORA_BW                 125000UL    // Bandwidth 125 kHz
#define LORA_CR                 5           // Coding rate 4/5
#define LORA_PREAMBLE           8
#define LORA_TX_POWER           17          // dBm
#define LORA_PACKET_SIZE        50          // bytes per LoRa packet

/* ─── Battery ───────────────────────────────────────── */
#define BAT_ADC_FULL            3723        // ADC value @ 4.2V (with divider)
#define BAT_ADC_EMPTY           2689        // ADC value @ 3.0V (with divider)
#define BAT_LOW_THRESHOLD       20          // % — warn user
#define BAT_CRITICAL_THRESHOLD  10          // % — critical warning

/* ─── GPIO pin aliases ──────────────────────────────── */
// LoRa
#define LORA_NSS_PIN            GPIO_PIN_9
#define LORA_NSS_PORT           GPIOA
#define LORA_RST_PIN            GPIO_PIN_8
#define LORA_RST_PORT           GPIOA
#define LORA_DIO0_PIN           GPIO_PIN_10
#define LORA_DIO0_PORT          GPIOA
#define LORA_DIO1_PIN           GPIO_PIN_0
#define LORA_DIO1_PORT          GPIOB

// PTT
#define PTT_PIN                 GPIO_PIN_13
#define PTT_PORT                GPIOC

// LEDs
#define LED_TX_PIN              GPIO_PIN_14
#define LED_TX_PORT             GPIOB
#define LED_RX_PIN              GPIO_PIN_15
#define LED_RX_PORT             GPIOB
#define LED_STAT_PIN            GPIO_PIN_13
#define LED_STAT_PORT           GPIOB

// Charging
#define CHRG_STAT_PIN           GPIO_PIN_14
#define CHRG_STAT_PORT          GPIOC
#define STDBY_STAT_PIN          GPIO_PIN_15
#define STDBY_STAT_PORT         GPIOC

/* ─── Buzzer tones (TIM3 period values @ 96MHz/100 PSC) */
#define BUZZER_TONE_HIGH        999         // ~960 Hz
#define BUZZER_TONE_MID         1499        // ~640 Hz
#define BUZZER_TONE_LOW         1999        // ~480 Hz
#define BUZZER_OFF              0

/* ─── System state ──────────────────────────────────── */
typedef enum {
    STATE_RX_IDLE,
    STATE_RECEIVING,
    STATE_TX_PENDING,
    STATE_TRANSMITTING,
    STATE_CHARGING,
    STATE_LOW_BATTERY
} WalkieTalkieState;

/* ─── Extern handles (from main.c / CubeMX) ─────────── */
extern SPI_HandleTypeDef  hspi1;   // Ra-02
extern SPI_HandleTypeDef  hspi2;   // Nokia 5110
extern I2S_HandleTypeDef  hi2s3;   // MAX98357A
extern ADC_HandleTypeDef  hadc1;   // MAX9814
extern TIM_HandleTypeDef  htim2;   // ADC trigger
extern TIM_HandleTypeDef  htim3;   // Buzzer PWM
extern DMA_HandleTypeDef  hdma_adc1;
extern DMA_HandleTypeDef  hdma_spi3_tx;

/* ─── Audio buffers ─────────────────────────────────── */
extern volatile int16_t  adc_buf[DMA_BUFFER_SIZE];   // mic input
extern volatile int16_t  i2s_buf[DMA_BUFFER_SIZE];   // speaker output

/* ─── Public API ─────────────────────────────────────── */
void WalkieTalkie_Init(void);
void WalkieTalkie_Run(void);

#endif /* WALKIE_TALKIE_H */
