#ifndef BUZZER_H
#define BUZZER_H

#include "stm32f4xx_hal.h"

void Buzzer_Init(void);
void Buzzer_Beep(uint32_t tone, uint32_t duration_ms);
void Buzzer_DoubleBeep(void);
void Buzzer_TxStart(void);
void Buzzer_TxStop(void);
void Buzzer_RxReceived(void);
void Buzzer_LowBattery(void);
void Buzzer_CriticalBattery(void);
void Buzzer_ChargingComplete(void);
void Buzzer_PowerOn(void);
void Buzzer_Off(void);

#endif /* BUZZER_H */
