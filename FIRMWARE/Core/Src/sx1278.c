#include "sx1278.h"
#include "walkie_talkie.h"

/* ─── Internal helpers ───────────────────────────────── */
static void     SX1278_Select(void)   { HAL_GPIO_WritePin(LORA_NSS_PORT, LORA_NSS_PIN, GPIO_PIN_RESET); }
static void     SX1278_Deselect(void) { HAL_GPIO_WritePin(LORA_NSS_PORT, LORA_NSS_PIN, GPIO_PIN_SET);   }

static uint8_t SX1278_ReadReg(uint8_t addr) {
    uint8_t tx = addr & 0x7F, rx = 0;
    SX1278_Select();
    HAL_SPI_Transmit(&hspi1, &tx, 1, HAL_MAX_DELAY);
    HAL_SPI_Receive(&hspi1,  &rx, 1, HAL_MAX_DELAY);
    SX1278_Deselect();
    return rx;
}

static void SX1278_WriteReg(uint8_t addr, uint8_t val) {
    uint8_t buf[2] = { addr | 0x80, val };
    SX1278_Select();
    HAL_SPI_Transmit(&hspi1, buf, 2, HAL_MAX_DELAY);
    SX1278_Deselect();
}

/* ─── Reset ──────────────────────────────────────────── */
void SX1278_Reset(void) {
    HAL_GPIO_WritePin(LORA_RST_PORT, LORA_RST_PIN, GPIO_PIN_RESET);
    HAL_Delay(10);
    HAL_GPIO_WritePin(LORA_RST_PORT, LORA_RST_PIN, GPIO_PIN_SET);
    HAL_Delay(10);
}

/* ─── Mode ───────────────────────────────────────────── */
void SX1278_SetMode(uint8_t mode) {
    SX1278_WriteReg(REG_OP_MODE, MODE_LONG_RANGE | mode);
}

/* ─── Init ───────────────────────────────────────────── */
bool SX1278_Init(uint32_t frequency, uint8_t sf, uint32_t bw,
                 uint8_t cr, uint8_t preamble, uint8_t power) {

    SX1278_Reset();

    // Check version register — should be 0x12
    uint8_t ver = SX1278_ReadReg(REG_VERSION);
    if (ver != 0x12) return false;

    // Sleep mode to configure
    SX1278_SetMode(MODE_SLEEP);
    HAL_Delay(10);

    // Set frequency
    uint64_t frf = ((uint64_t)frequency << 19) / 32000000UL;
    SX1278_WriteReg(REG_FRF_MSB, (uint8_t)(frf >> 16));
    SX1278_WriteReg(REG_FRF_MID, (uint8_t)(frf >>  8));
    SX1278_WriteReg(REG_FRF_LSB, (uint8_t)(frf >>  0));

    // PA config — use PA_BOOST pin for Ra-02
    if (power > 17) power = 17;
    SX1278_WriteReg(REG_PA_CONFIG, PA_BOOST | (power - 2));
    SX1278_WriteReg(REG_PA_DAC, (power == 20) ? 0x87 : 0x84);

    // LNA — max gain, boost on
    SX1278_WriteReg(REG_LNA, 0x23);

    // Modem config 1 — bandwidth + coding rate + implicit header off
    uint8_t bw_bits;
    if      (bw <= 7800)   bw_bits = 0;
    else if (bw <= 10400)  bw_bits = 1;
    else if (bw <= 15600)  bw_bits = 2;
    else if (bw <= 20800)  bw_bits = 3;
    else if (bw <= 31250)  bw_bits = 4;
    else if (bw <= 41700)  bw_bits = 5;
    else if (bw <= 62500)  bw_bits = 6;
    else if (bw <= 125000) bw_bits = 7;
    else if (bw <= 250000) bw_bits = 8;
    else                   bw_bits = 9;
    SX1278_WriteReg(REG_MODEM_CONFIG1, (bw_bits << 4) | ((cr - 4) << 1) | 0);

    // Modem config 2 — SF + CRC on
    SX1278_WriteReg(REG_MODEM_CONFIG2, (sf << 4) | 0x04);

    // Modem config 3 — low data rate optimize if needed
    if ((bw == 125000 && sf >= 11) || (bw == 250000 && sf == 12))
        SX1278_WriteReg(REG_MODEM_CONFIG3, 0x08);
    else
        SX1278_WriteReg(REG_MODEM_CONFIG3, 0x00);

    // Preamble length
    SX1278_WriteReg(REG_PREAMBLE_MSB, 0x00);
    SX1278_WriteReg(REG_PREAMBLE_LSB, preamble);

    // Sync word — 0x12 for private network
    SX1278_WriteReg(REG_SYNC_WORD, 0x12);

    // SF6 detection
    if (sf == 6) {
        SX1278_WriteReg(REG_DETECTION_OPTIMIZE,  0xC5);
        SX1278_WriteReg(REG_DETECTION_THRESHOLD, 0x0C);
    } else {
        SX1278_WriteReg(REG_DETECTION_OPTIMIZE,  0xC3);
        SX1278_WriteReg(REG_DETECTION_THRESHOLD, 0x0A);
    }

    // FIFO base addresses
    SX1278_WriteReg(REG_FIFO_TX_BASE_ADDR, 0x00);
    SX1278_WriteReg(REG_FIFO_RX_BASE_ADDR, 0x00);

    // DIO0 mapping — RX_DONE and TX_DONE both map to DIO0
    SX1278_WriteReg(REG_DIO_MAPPING1, 0x00);

    // Go to standby
    SX1278_SetMode(MODE_STDBY);

    return true;
}

/* ─── TX ─────────────────────────────────────────────── */
void SX1278_SetTxMode(void) {
    SX1278_WriteReg(REG_DIO_MAPPING1, 0x40); // DIO0 = TX_DONE
    SX1278_SetMode(MODE_STDBY);
    SX1278_WriteReg(REG_FIFO_ADDR_PTR, 0x00);
}

void SX1278_Send(uint8_t *data, uint8_t len) {
    SX1278_SetMode(MODE_STDBY);
    SX1278_WriteReg(REG_FIFO_ADDR_PTR, 0x00);
    SX1278_WriteReg(REG_PAYLOAD_LENGTH, len);

    SX1278_Select();
    uint8_t addr = REG_FIFO | 0x80;
    HAL_SPI_Transmit(&hspi1, &addr, 1, HAL_MAX_DELAY);
    HAL_SPI_Transmit(&hspi1, data, len, HAL_MAX_DELAY);
    SX1278_Deselect();

    SX1278_SetMode(MODE_TX);
}

/* ─── RX ─────────────────────────────────────────────── */
void SX1278_SetRxMode(void) {
    SX1278_WriteReg(REG_DIO_MAPPING1, 0x00); // DIO0 = RX_DONE
    SX1278_WriteReg(REG_FIFO_RX_BASE_ADDR, 0x00);
    SX1278_WriteReg(REG_FIFO_ADDR_PTR, 0x00);
    SX1278_SetMode(MODE_RX_CONTINUOUS);
}

uint8_t SX1278_Receive(uint8_t *buf, uint8_t maxLen) {
    uint8_t len = SX1278_ReadReg(REG_RX_NB_BYTES);
    if (len > maxLen) len = maxLen;

    uint8_t curr = SX1278_ReadReg(REG_FIFO_RX_CURR_ADDR);
    SX1278_WriteReg(REG_FIFO_ADDR_PTR, curr - len);

    SX1278_Select();
    uint8_t addr = REG_FIFO & 0x7F;
    HAL_SPI_Transmit(&hspi1, &addr, 1, HAL_MAX_DELAY);
    HAL_SPI_Receive(&hspi1, buf, len, HAL_MAX_DELAY);
    SX1278_Deselect();

    return len;
}

/* ─── IRQ ────────────────────────────────────────────── */
uint8_t SX1278_GetIRQFlags(void) {
    return SX1278_ReadReg(REG_IRQ_FLAGS);
}

void SX1278_ClearIRQ(void) {
    SX1278_WriteReg(REG_IRQ_FLAGS, 0xFF);
}

/* ─── RSSI / SNR ─────────────────────────────────────── */
int16_t SX1278_GetRSSI(void) {
    return -164 + SX1278_ReadReg(REG_PKT_RSSI_VALUE);
}

int8_t SX1278_GetSNR(void) {
    return (int8_t)SX1278_ReadReg(REG_PKT_SNR_VALUE) / 4;
}
