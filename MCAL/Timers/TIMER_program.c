/**
 *
 * @file       TIMER_program.c
 * @brief      Contains functions definitions for the timer peripheral
 * @author     Abdulrahman Aboghanima
 * @date       Jan 31 21:47:12 2022
 * @copyright  Copyright (c) 2022
 * @version    0.2
 * 
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TIMER_interface.h"
#include "TIMER_config.h"
#include "TIMER_private.h"
#include "TIMER_register.h"




extern void TIMER_setPrescaler(const timer_id timer,  const uint8_t prescaler)
{
  switch (timer){
  case timer0:
    TCCR0 &= PRESCALER_MASK;
    TCCR0 |= prescaler;
    break;

  case timer1:
    TCCR1B &=PRESCALER_MASK;
    TCCR1B |=prescaler;
    break;

  case timer2: break; /*TODO*/

  }
}



/*
  switch (timer){
  case timer0:
    break;
  case timer1:
    break;
  case timer2:
    break;

  default: break;
      
  }
*/

extern void TIMER_setTimerValue(const timer_id timer, const uint16_t timerValue)
{
  switch (timer){
  case timer0:
    TCNT0=timerValue;
    break;

  case timer1:
    TCNT1=timerValue;
    break;

  case timer2:
    TCNT2=timerValue;
    break;
  }
  
}


/* Q: If I used ICR1 as a top, the value of the timer will be compared with OCR1A.
 *    But if I used the OCR1A/OCR1B as a top, 
 *    should OC1A/OC1B cleared on compare match(top) and cleared at bottom?
 * Ans:
 *    Referring to the data sheet(page108), the compare match will be ignored
 */
void TIMER1_setICR(const uint16_t inputCaptureValue)
{
  ICR1=inputCaptureValue;
 
}
void TIMER1_setChannelAComapareMatchValue(const uint16_t channelACompareMatchValue)
{
  OCR1A=channelACompareMatchValue;
}
void TIMER1_setChannelBComapareMatchValue(const uint16_t channelBCompareMatchValue)
{
  OCR1B=channelBCompareMatchValue;
}

void TIMER_setCompareMatchValue(const timer_id timer, const uint8_t value)
{
  switch (timer){
  case timer0:
    OCR0=value;
    break;

  case timer2:
    break;

  default: break;
      
  }

}


void CTC_mode(const timer_id timer)
{
  switch(timer){

  case timer0:
    CLEAR_BIT(TCCR0, TCCR0_WGM00);
    SET_BIT(TCCR0, TCCR0_WGM01);
    break;
    
  case timer1:
    CLEAR_BIT(TCCR1A, TCCR1A_WGM10);
    CLEAR_BIT(TCCR1A, TCCR1A_WGM11);
    SET_BIT(TCCR1B, TCCR1B_WGM12);
    CLEAR_BIT(TCCR1B, TCCR1B_WGM13);
    break;
    
  case timer2:
    CLEAR_BIT(TCCR2, TCCR2_WGM20);
    SET_BIT(TCCR2, TCCR2_WGM21);
    break;
        
  }
}

void fast_PWM_mode(const timer_id timer)
{
  switch (timer){

  case timer0:
    SET_BIT(TCCR0, TCCR0_WGM00);
    SET_BIT(TCCR0, TCCR0_WGM01);
 
    /*Clear in Compare match Set at Bottom*/
    CLEAR_BIT(TCCR0, TCCR0_COM00);
    SET_BIT(TCCR0, TCCR0_COM01);

    break;


  case timer1:

    /*Set the waveform of the fast PWM, the ICR1 will be the TOP*/
    CLEAR_BIT(TCCR1A, TCCR1A_WGM10);
    SET_BIT(TCCR1A, TCCR1A_WGM11);
    SET_BIT(TCCR1B, TCCR1B_WGM12);
    SET_BIT(TCCR1B, TCCR1B_WGM13);

    /*Compare output mode: Clear on Compare match, Set at Bottom*/
    SET_BIT(TCCR1A, TCCR1A_COM1A1);
    CLEAR_BIT(TCCR1A, TCCR1A_COM1A0);

    break;


  case timer2: break; /*TODO*/

      
  }

}

extern void TIMER_CTC_setOCxOnCompareMatch(const timer_id timer)
{
  switch (timer){
  case timer0:
    SET_BIT(TCCR0, TCCR0_COM00);
    SET_BIT(TCCR0, TCCR0_COM01);
    break;
  case timer1:
    break;
  case timer2:
    break;

  }
}

extern void TIMER_CTC_clearOCxOnCompareMatch(const timer_id timer)
{
  switch (timer){
  case timer0:
    CLEAR_BIT(TCCR0, TCCR0_COM00);
    SET_BIT(TCCR0, TCCR0_COM01);
    break;
  case timer1:
    break;
  case timer2:
    break;
    
    }
  
}

extern void TIMER_CTC_toggleOCxOnCompareMatch(const timer_id timer)
{
  switch (timer){
  case timer0:
    SET_BIT(TCCR0, TCCR0_COM00);
    CLEAR_BIT(TCCR0, TCCR0_COM01);
    break;
  case timer1:
    CLEAR_BIT(TCCR1A, TCCR1A_COM1A1);
    SET_BIT(TCCR1A, TCCR1A_COM1A0);
    break;

  case timer2:
    break;

  default: break;
      
  }
    
}

void normal_mode(const timer_id timer)
{
  switch (timer){

  case timer0:
    CLEAR_BIT(TCCR0, TCCR0_WGM00);
    CLEAR_BIT(TCCR0, TCCR0_WGM01);
    break;


  case timer1:

    /*Normal mode*/
    CLEAR_BIT(TCCR1A, TCCR1A_WGM10);
    CLEAR_BIT(TCCR1A, TCCR1A_WGM11);
    CLEAR_BIT(TCCR1B, TCCR1B_WGM12);
    CLEAR_BIT(TCCR1B, TCCR1B_WGM13);
    break;

  case timer2: break; /*TODO*/

  }
}






void TIMER_init(const timer_id timer, const timer_mode mode, const prescaler value)
{
  
  switch(mode){

  case normal:
    normal_mode(timer);
    break;

  case PWM:
    break;

  case CTC:
    CTC_mode(timer);
    break;

  case fast_PWM:
    fast_PWM_mode(timer);
    break;      
  }

  TIMER_setPrescaler(timer, value);
    
}


void ICU_init(void)
{
  /*Set trigger source to rising edge initially*/
  SET_BIT(TCCR1B, TCCR1B_ICES1);

  /*Input capture Interrupt Enable*/
  SET_BIT(TIMSK, TIMSK_TICIE1);
}



void ICU_setTriggerEdge(uint8_t edge)
{
  if(edge==ICU_RISING_EDGE)
    SET_BIT(TCCR1B, TCCR1B_ICES1);
  else
    CLEAR_BIT(TCCR1B, TCCR1B_ICES1);
}

static void (*ICU_callBackFunc)(void)=NULL;
static void (*TIMER0_normalModeOverflow)(void)=NULL;
static void (*TIMER1_normalModeOverflow)(void)=NULL;
static void (*TIMER2_normalModeOverflow)(void)=NULL;


void ICU_setCallBack(void (*callBackFunc)(void))
{
  ICU_callBackFunc=callBackFunc;
}


extern uint16_t ICU_readInputCapture(void)
{
  return ICR1;
}


void TIMER_normalModeOverflowSetCallBack(timer_id timer, void (*callBackFunc)(void))
{
  switch (timer){
  case timer0:
    TIMER0_normalModeOverflow=callBackFunc;
    SET_BIT(TIMSK, TIMSK_TOIE0);   /*Enable overflow interrupt*/
    break;
  case timer1:
    TIMER1_normalModeOverflow=callBackFunc;
    SET_BIT(TIMSK, TIMSK_TOIE1);  /*Enable overflow interrupt*/
    break;
  case timer2:
    TIMER2_normalModeOverflow=callBackFunc;
    SET_BIT(TIMSK, TIMSK_TOIE2);  /*Enable overflow interrupt*/
    break;

  }

}



void TIMER0_OVF_vect(void)__attribute__((signal));
void TIMER0_OVF_vect(void)
{
  if(TIMER0_normalModeOverflow!=NULL)
    TIMER0_normalModeOverflow();
}



void TIMER1_OVF_vect(void)__attribute__((signal));
void TIMER1_OVF_vect(void)
{
  if(TIMER1_normalModeOverflow!=NULL)
    TIMER1_normalModeOverflow();
}



void TIMER2_OVF_vect(void)__attribute__((signal));
void TIMER2_OVF_vect(void)
{
  if(TIMER2_normalModeOverflow!=NULL)
    TIMER2_normalModeOverflow();
}

/*ICU ISR*/
void __vector_6 (void) __attribute__((signal));
void __vector_6(void)
{
  ICU_callBackFunc();
}
