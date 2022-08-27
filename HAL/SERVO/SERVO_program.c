/**
 *
 * @file       SERVO_program.c
 * @brief      Contains functions definitions for the SERVO motot
 * @author     Abdulrahman Aboghanima
 * @date       Tue Aug 23 22:30:23 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */

#include "../../LIB/STD_TYPES.h"
#include  "../../MCAL/Timers/TIMER_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "SERVO_interface.h"

uint16_t map(uint8_t valueA, uint8_t rangeA_min, uint8_t rangeA_max, uint16_t rangeB_min, uint16_t rangeB_max)
{
  double value= (double)(rangeB_max-rangeB_min)*(valueA-rangeA_min)/(rangeA_max-rangeA_min)+rangeB_min;
  return value;
}



extern void SERVO_init(SERVO_pin pin)
{
  /*Using timer1 in the fast PWM mode with an input clock: 8MHz/8=1MHz*/
  TIMER_init(timer1, fast_PWM, divided_by_8);

  /*Since the timer tick takes 1us, 
    then 20000 takes 20ms which is the period needed by the servo motor*/
  TIMER1_setICR(20000);
  
  switch(pin){
  case OC1A:
    /*Setting the OC1A pin to be output*/
    DIO_SetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT);
    break;
  case OC1B:
    /*Setting the OC1B pin to be output*/
    DIO_SetPinDirection(DIO_PORTD, DIO_PIN4, DIO_PIN_OUTPUT); 
    break;
  }

}


extern void SERVO_angle(SERVO_pin pin, uint8_t angle)
{
  
  /*    
	 On                  On
         ___                 ___
	|   |      off      |   |        off
     ___|   |_______________|   |_______________
	
  
  */

  uint16_t onTime=map(angle, 0, 180, 1000, 2000);

  /*Depending on the initialization of the timer,
    OC1A/OC1B will be set from 0:onTime-1 and
    will be cleared from onTime:20000*/
  switch(pin){
  case OC1A:
    TIMER1_setChannelAComapareMatchValue(onTime-1);
  break;
  case OC1B:
    TIMER1_setChannelBComapareMatchValue(onTime-1);
    break;
  }


}

