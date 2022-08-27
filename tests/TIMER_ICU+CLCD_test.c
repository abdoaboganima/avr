/**
 *
 * @file       TIMER_ICU_test.c
 * @brief      Testing for the ICU timer module + CLCD
 * @author     Abdulrahman Aboghanima
 * @date       Sep 15 21:02:57 2021
 * @copyright  Copyright (c) 2022
 * @version    0.2
 * 
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/CLCD/CLCD_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/Timers/TIMER_interface.h"


#include <util/delay.h>

static uint16_t periodTicks=0, onTicks=0;

void ICU(void)
{
  static uint8_t counter=0;
  static uint16_t reading1, reading2;
  if(counter==0){
    reading1=ICU_readInputCapture();
  }
  
  else if(counter==1){
    reading2=ICU_readInputCapture();
    periodTicks=reading2-reading1;
    ICU_setTriggerEdge(ICU_FALLING_EDGE);  
  }
  else if(counter==2){
    onTicks=ICU_readInputCapture()-reading2;
    ICU_disableInterrupt();
  }
  counter++;
}


int main(void)
{

  /*Setting the OC0 to be output. It outputs the PWM signal*/
  DIO_SetPinDirection(DIO_PORTD, DIO_PIN6, DIO_PORT_INPUT);
  /*Setting the Input Capture pin to be input*/
  DIO_SetPinDirection(DIO_PORTB, DIO_PIN3, DIO_PORT_OUTPUT);


  ICU_init();   /*Input Capture Unit initialization*/
  CLCD_init();  /*CLCD initialization*/


  /*Setting the function that will be called by the ISR of the ICU*/
  ICU_setCallBack(&ICU);

  
  TIMER_setCompareMatchValue(timer0, 99);
 
  
  /*For counting only, It's used by the ICU*/
  TIMER_init(timer1, normal, divided_by_64);

  /*For generating PWM, the signal that we would like to test it*/
  TIMER_init(timer0, fast_PWM, divided_by_64);

  /*Global Interrupt Enable */
  GIE_enable();

  while(1){

    while(periodTicks==0 && onTicks==0);
    CLCD_GoTOXY(0, 0);
    CLCD_SendString("periodTicks: ");
    CLCD_SendString(utoa(periodTicks, 10));
    CLCD_GoTOXY(1,0);
    CLCD_SendString("onTicks: ");
    CLCD_SendString(utoa(onTicks, 10));
    
  }


  return 0;
}
