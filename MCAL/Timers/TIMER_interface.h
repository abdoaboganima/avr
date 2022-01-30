#ifndef _TIMER_INTERFACE_H_
#define _TIMER_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"
#include "TIMER_register.h"

#define TIMER1_readTimerValue() TCNT1

#define ICU_enableInterrupt()   SET_BIT(TIMSK, TIMSK_TICIE1)
#define ICU_disableInterrupt()  CLEAR_BIT(TIMSK, TIMSK_TICIE1)
#define ICU_readInputCapture()  ICR1


#define ICU_RISING_EDGE   1
#define ICU_FALLING_EDGE  2

void TIMER0_init(void);
void TIMER0_init_fastPWM(void);
void TIMER0_setCompareMatchValue(uint8_t value);
void TIMER0_setCallBack(void (*callBackFunc)(void));


/*Timer 1 functions*/
void TIMER1_init(void);
void TIMER1_init_fastPWM(void);

void TIMER1_setICR(uint16_t inputCaptureValue);

void TIMER1_setChannelAComapareMatchValue(uint16_t channelACompareMatchValue);
void TIMER1_setChannelBComapareMatchValue(uint16_t channelBCompareMatchValue);

void TIMER1_setTimerValue(const uint16_t timer1Value);
//uint16_t TIMER1_readTimerValue(void);


void ICU_init(void);
void ICU_setTriggerEdge(uint8_t edge);
//void ICU_enableInterrupt(void);
//void ICU_disableInterrupt(void);
//uint16_t ICU_readInputCapture(void);
void ICU_setCallBack(void (*callBackFunc)(void));
#endif /* _TIMER_INTERFACE_H_ */
