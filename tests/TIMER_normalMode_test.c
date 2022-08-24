/**
 *
 * @file       TIMER_normalMode_test.c
 * @brief      Contains some test for the timer peripheral in the normal mode
 * @author     Abdulrahman Aboghanima
 * @date       Mon Aug 22 21:44:45 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */

#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/Timers/TIMER_interface.h"
#include <util/delay.h>


/*Toggles LED1*/
void func1(void)
{
  static uint16_t numOfOverflows=0;
  numOfOverflows++;
  if(numOfOverflows==30){
    DIO_TogglePinValue(DIO_PORTA, DIO_PIN0);
    numOfOverflows=0;
  }  
}

/*Toggles LED2*/
void func2(void)
{
  static uint16_t numOfOverflows=0;
  numOfOverflows++;
  if(numOfOverflows==30){
    DIO_TogglePinValue(DIO_PORTA, DIO_PIN1);
    numOfOverflows=0;
  }  
}

int main(void)
{

  DIO_SetPinDirection(DIO_PORTA, DIO_PIN0, DIO_PIN_OUTPUT);
  DIO_SetPinDirection(DIO_PORTA, DIO_PIN1, DIO_PIN_OUTPUT);
  
  DIO_SetPinValue(DIO_PORTA, DIO_PIN0, DIO_PIN_HIGH);
  DIO_SetPinValue(DIO_PORTA, DIO_PIN1, DIO_PIN_HIGH);
  
  /*Initialization of timer0 to be in the normal mode*/
  TIMER_init(timer0, normal, divided_by_1024);     /*The input frequency is 8MHz/1024*/
  TIMER_normalModeOverflowSetCallBack(timer0, func1);


  
  /*Initialization of timer1 to be in the normal mode*/
  TIMER_init(timer1, normal, divided_by_1);     /*The input frequency is 8 MHz*/
  TIMER_normalModeOverflowSetCallBack(timer1, func2);



  /* Global Interrupt Enable*/
  GIE_enable();

  
  while(1){

    
  }


  return 0;
}
