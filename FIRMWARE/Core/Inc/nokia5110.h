#ifndef NOKIA5110_H
#define NOKIA5110_H

#include "stm32f4xx_hal.h"
#include <stdint.h>
#include <stdbool.h>

/* ─── Display dimensions ─────────────────────────────── */
#define LCD_WIDTH   84
#define LCD_HEIGHT  48
#define LCD_ROWS    6    // 48/8 = 6 rows of bytes

/* ─── PCD8544 Commands ───────────────────────────────── */
#define LCD_CMD_FUNC_SET_BASIC  0x20
#define LCD_CMD_FUNC_SET_EXT    0x21
#define LCD_CMD_DISPLAY_NORMAL  0x0C
#define LCD_CMD_SET_VOP         0xB0  // contrast base
#define LCD_CMD_SET_TEMP        0x04
#define LCD_CMD_SET_BIAS        0x13
#define LCD_CMD_SET_X           0x80
#define LCD_CMD_SET_Y           0x40

/* ─── Public API ─────────────────────────────────────── */
void LCD_Init(void);
void LCD_Clear(void);
void LCD_Update(void);
void LCD_SetCursor(uint8_t x, uint8_t row);
void LCD_DrawChar(char c);
void LCD_DrawString(uint8_t x, uint8_t row, const char *str);
void LCD_DrawInt(uint8_t x, uint8_t row, int32_t val);

/* ─── Screen layout helpers ──────────────────────────── */
void LCD_ShowStatus(const char *status);     // row 0 — TX/RX/IDLE
void LCD_ShowRSSI(int16_t rssi);             // row 1
void LCD_ShowBattery(uint8_t pct);           // row 2
void LCD_ShowCharging(bool charging);        // row 3
void LCD_ShowChannel(uint8_t ch);            // row 4

#endif /* NOKIA5110_H */
