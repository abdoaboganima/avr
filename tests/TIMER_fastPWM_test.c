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

int main(void)
{

  /*Setting the OC0 pin to be output*/
  DIO_SetPinDirection(DIO_PORTB, DIO_PIN3, DIO_PIN_OUTPUT);

  /*Setting the OC1A pin to be output*/
  DIO_SetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT);

  /*Initialization of timer0 to be in the fast PWM mode*/
  TIMER_init(timer0, fast_PWM, divided_by_8);

  /*Setting the duty cycle, choose value from 0:255*/
  TIMER_setCompareMatchValue(timer0, 200);


  /*Initialization of timer1 to be in the fast PWM mode*/
  TIMER_init(timer1, fast_PWM, divided_by_8);

  /*Setting the duty cycle to be 50%*/
  TIMER1_setChannelAComapareMatchValue(4000);
  TIMER1_setICR(40000);  

  
  while(1){

    
  }


  return 0;
}
