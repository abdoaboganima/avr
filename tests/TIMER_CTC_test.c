/*
 * main.c
 *
 *  Created on: Sep 13, 2021
 *      Author: Abdulrahman Aboghanima
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/CLCD/CLCD_config.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/Timers/TIMER_interface.h"
#include <util/delay.h>

void func(void)
{
  DIO_TogglePinValue(DIO_PORTA, DIO_PIN0);
  _delay_ms(1000);
}

int main(void)
{

  /*Setting the OC0 pin to be output*/
  DIO_SetPinDirection(DIO_PORTB, DIO_PIN3, DIO_PIN_OUTPUT);

  /*Setting the OC1A pin to be output*/
  DIO_SetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT);


  DIO_SetPinDirection(DIO_PORTA, DIO_PIN0, DIO_PIN_OUTPUT);
  DIO_SetPinValue(DIO_PORTA, DIO_PIN0, DIO_PIN_HIGH);
  


  /*Initialization of timer0 to be in the CTC mode*/
  TIMER_init(timer0, CTC, divided_by_1);     /*The input frequency is 8MHz*/
  TIMER_setCompareMatchValue(timer0, 99);
  /*The frequency of OC0 should be (F_CPU/(2*N*(1+OCR0)))= 40kHz*/
  TIMER_CTC_toggleOCxOnCompareMatch(timer0);


  /*Initialization of timer1 to be in the CTC mode*/
  TIMER_init(timer1, CTC, divided_by_8);     /*The input frequency is 1 MHz*/
  TIMER1_setChannelAComapareMatchValue(99);
  /*The frequency of OC0 should be (F_CPU/(2*N*(1+OCR1A)))= 5kHz*/
  TIMER_CTC_toggleOCxOnCompareMatch(timer1);
  

  while(1);

  return 0;
}
