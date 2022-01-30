#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TIMER_interface.h"
#include "TIMER_config.h"
#include "TIMER_private.h"
#include "TIMER_register.h"


#define TIMER0 0
#define TIMER1 1
#define TIMER2 2



static inline void setPrescaler(uint8_t timer, uint8_t prescaler)
{
  /*NOTE : prescaler is a 3-bit value*/
  if(timer==TIMER0){
    TCCR0 &= PRESCALER_MASK;
    TCCR0 |= prescaler;
  }
  else if(timer==TIMER1){
    TCCR1B &=PRESCALER_MASK;
    TCCR1B |=prescaler;
    
  }
    
}

void TIMER1_init(void)
{
  /*Set the prescaler*/
  setPrescaler(TIMER1, DIVIDED_BY_8);
}

void TIMER1_setTimerValue(const uint16_t timer1Value)
{
  TCNT1=timer1Value;
}

/*
uint16_t TIMER1_readTimerValue(void)
{
  return TCNT1;
}
*/
void TIMER1_init_fastPWM(void)
{
  /*Set fast PWM mode*/
  SET_BIT(TCCR1A, TCCR1A_COM1A1);
  CLEAR_BIT(TCCR1A, TCCR1A_COM1A0);

  /*Set the waveform of the fas PWM*/
  CLEAR_BIT(TCCR1A, TCCR1A_WGM10);
  SET_BIT(TCCR1A, TCCR1A_WGM11);
  SET_BIT(TCCR1B, TCCR1B_WGM12);
  SET_BIT(TCCR1B, TCCR1B_WGM13);

  /*Set the prescaler*/
  setPrescaler(TIMER1, DIVIDED_BY_8); 
}

void TIMER1_setICR(uint16_t inputCaptureValue)
{
  ICR1=inputCaptureValue;
 
}
void TIMER1_setChannelAComapareMatchValue(uint16_t channelACompareMatchValue)
{
  OCR1A=channelACompareMatchValue;
}
void TIMER1_setChannelBComapareMatchValue(uint16_t channelBCompareMatchValue)
{
  OCR1B=channelBCompareMatchValue;
}
void TIMER0_init_fastPWM(void)
{
  /*Choose Fast PWM mode*/
 SET_BIT(TCCR0, TCCR0_WGM00);
 SET_BIT(TCCR0, TCCR0_WGM01);
 
 /*Clear in Compare match Set on top*/
 CLEAR_BIT(TCCR0, TCCR0_COM00);
 SET_BIT(TCCR0, TCCR0_COM01);

 /*Setting the duty cycle to be 25%*/
 OCR0=64;

 setPrescaler(TIMER0, DIVIDED_BY_8);

}

void TIMER0_setCompareMatchValue(uint8_t value)
{
  OCR0=value;
}

 
 

void TIMER0_init(void)
{
  /*Choose CTC Mode*/
  CLEAR_BIT(TCCR0, TCCR0_WGM00);
  SET_BIT(TCCR0, TCCR0_WGM01);

  /*Output Compare Match interrupt Enable*/
  SET_BIT(TIMSK, TIMSK_OCIE0);

  //OCR0=250;

  /*Prescaler 8*/
  CLEAR_BIT(TCCR0, TCCR0_CS02);
  SET_BIT(TCCR0, TCCR0_CS01);
  CLEAR_BIT(TCCR0, TCCR0_CS00);
}
static void (*TIMER0_callBackFunc)(void)=NULL;


void ICU_init(void)
{
  /*Set trigger source to rising edge initially*/
  SET_BIT(TCCR1B, TCCR1B_ICES1);

  /*Enable Input capture Interrupt Enable*/
  ICU_enableInterrupt();
}

void ICU_setTriggerEdge(uint8_t edge)
{
  if(edge==ICU_RISING_EDGE)
    SET_BIT(TCCR1B, TCCR1B_ICES1);
  else
    CLEAR_BIT(TCCR1B, TCCR1B_ICES1);
}
/*
void ICU_enableInterrupt(void)
{
  SET_BIT(TIMSK, TIMSK_TICIE1);
}

*/
 /*
void ICU_disableInterrupt(void)
{
  CLEAR_BIT(TIMSK, TIMSK_TICIE1);
}

 */
  /*
uint16_t ICU_readInputCapture(void)
{
  return ICR1;
}
  */

static void (*ICU_callBackFunc)(void)=NULL;

void ICU_setCallBack(void (*callBackFunc)(void))
{
  ICU_callBackFunc=callBackFunc;
}
void TIMER0_setCallBack(void (*callBackFunc)(void))
{
  TIMER0_callBackFunc=callBackFunc;
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
  if(TIMER0_callBackFunc!=NULL)
    TIMER0_callBackFunc();
}

/*ICU ISR*/
void __vector_6 (void) __attribute__((signal));
void __vector_6(void)
{
  ICU_callBackFunc();
}
