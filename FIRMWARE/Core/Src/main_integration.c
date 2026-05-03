/* ═══════════════════════════════════════════════════════════
 *  HOW TO INTEGRATE THIS INTO YOUR CUBEMX-GENERATED main.c
 *
 *  CubeMX generates main.c with USER CODE BEGIN/END blocks.
 *  Copy the sections below into the matching blocks in your
 *  main.c. DO NOT replace the entire file.
 * ═══════════════════════════════════════════════════════════ */

/* ── USER CODE BEGIN Includes ── */
#include "walkie_talkie.h"
/* ── USER CODE END Includes ── */


/* ── USER CODE BEGIN 2 ── (after all HAL_Init and MX_ calls) */
WalkieTalkie_Init();
/* ── USER CODE END 2 ── */


/* ── USER CODE BEGIN WHILE ── */
while (1) {
    WalkieTalkie_Run();
    /* USER CODE END WHILE */
    /* USER CODE BEGIN 3 */
}
/* ── USER CODE END 3 ── */


/* ═══════════════════════════════════════════════════════════
 *  FILE STRUCTURE — add these files to your CubeIDE project
 *
 *  Core/Inc/walkie_talkie.h   — main config + state + API
 *  Core/Inc/sx1278.h          — LoRa radio driver header
 *  Core/Inc/nokia5110.h       — LCD driver header
 *  Core/Inc/buzzer.h          — buzzer driver header
 *
 *  Core/Src/walkie_talkie.c   — main app logic + callbacks
 *  Core/Src/sx1278.c          — SX1278 SPI driver
 *  Core/Src/nokia5110.c       — PCD8544 LCD driver + font
 *  Core/Src/buzzer.c          — PWM buzzer tones
 *
 * ═══════════════════════════════════════════════════════════
 *  NEXT STEP — Codec2 integration
 *
 *  1. Clone: https://github.com/drowe67/codec2
 *  2. Copy src/codec2.c and src/codec2.h into Core/Src and Core/Inc
 *  3. In walkie_talkie.c, uncomment the codec2_encode/decode calls
 *     and add:
 *       struct CODEC2 *codec2_state;
 *       codec2_state = codec2_create(CODEC2_MODE_2400);
 *     inside WalkieTalkie_Init() before SX1278_Init()
 *
 * ═══════════════════════════════════════════════════════════
 *  FIRST TEST — without Codec2
 *
 *  The code works without Codec2 for initial testing:
 *  - PTT → raw PCM sent over LoRa (no compression)
 *  - Audio plays back on the other device
 *  - All LEDs, buzzer, LCD, battery % work immediately
 *  - Add Codec2 once everything else is confirmed working
 * ═══════════════════════════════════════════════════════════ */
