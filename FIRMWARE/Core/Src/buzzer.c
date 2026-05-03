#include "buzzer.h"
#include "walkie_talkie.h"

void Buzzer_Init(void) {
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
    Buzzer_Off();
}

static void Buzzer_SetTone(uint32_t period) {
    __HAL_TIM_SET_AUTORELOAD(&htim3, period);
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, period / 2); // 50% duty
}

void Buzzer_Off(void) {
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0);
}

void Buzzer_Beep(uint32_t tone, uint32_t duration_ms) {
    Buzzer_SetTone(tone);
    HAL_Delay(duration_ms);
    Buzzer_Off();
}

void Buzzer_DoubleBeep(void) {
    Buzzer_Beep(BUZZER_TONE_MID, 80);
    HAL_Delay(80);
    Buzzer_Beep(BUZZER_TONE_MID, 80);
}

void Buzzer_TxStart(void) {
    Buzzer_Beep(BUZZER_TONE_HIGH, 100);
}

void Buzzer_TxStop(void) {
    Buzzer_DoubleBeep();
}

void Buzzer_RxReceived(void) {
    Buzzer_Beep(BUZZER_TONE_MID, 60);
}

void Buzzer_LowBattery(void) {
    // Three slow low beeps
    for (int i = 0; i < 3; i++) {
        Buzzer_Beep(BUZZER_TONE_LOW, 200);
        HAL_Delay(200);
    }
}

void Buzzer_CriticalBattery(void) {
    // Five fast low beeps
    for (int i = 0; i < 5; i++) {
        Buzzer_Beep(BUZZER_TONE_LOW, 100);
        HAL_Delay(100);
    }
}

void Buzzer_ChargingComplete(void) {
    Buzzer_Beep(BUZZER_TONE_MID,  150);
    HAL_Delay(50);
    Buzzer_Beep(BUZZER_TONE_HIGH, 150);
}

void Buzzer_PowerOn(void) {
    // Ascending chirp
    Buzzer_Beep(BUZZER_TONE_LOW,  120);
    HAL_Delay(30);
    Buzzer_Beep(BUZZER_TONE_MID,  120);
    HAL_Delay(30);
    Buzzer_Beep(BUZZER_TONE_HIGH, 150);
}
