/**
 *
 * @file       EXTI+DIO_test.c
 * @brief      Contains integration test for the `DIO` and `EXTI` modules
 * @author     Abdulrahman Aboghanima
 * @date       Wed Aug 17 19:16:44 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/EXTI/EXTI_config.h"

#include <util/delay.h>

void routine(void)
{
  DIO_SetPinValue(DIO_PORTB, DIO_PIN0, DIO_PIN_LOW);
  _delay_ms(500);
  DIO_SetPinValue(DIO_PORTB, DIO_PIN0, DIO_PIN_HIGH);
  _delay_ms(500);
}


int  main(void)
{

  /*Set a pin in PORTB to be output to notice the effect of interrupt*/
  DIO_SetPinDirection(DIO_PORTB, DIO_PIN0, DIO_PIN_OUTPUT);
  DIO_SetPinValue(DIO_PORTB, DIO_PIN0, DIO_PIN_HIGH);
	
  /*The Pin of the External Interrupt INT0 to be input*/
  DIO_SetPinDirection(DIO_PORTD, DIO_PIN2, DIO_PIN_INPUT);
  DIO_SetPinValue(DIO_PORTD, DIO_PIN2, DIO_PIN_HIGH);//For pull-up resistance

  /*The Pin of the External Interrupt INT1 to be input*/
  DIO_SetPinDirection(DIO_PORTD, DIO_PIN3, DIO_PIN_INPUT);
  DIO_SetPinValue(DIO_PORTD, DIO_PIN3, DIO_PIN_HIGH);//For pull-up resistance


  /*The Pin of the External Interrupt INT2 to be input*/
  DIO_SetPinDirection(DIO_PORTB, DIO_PIN2, DIO_PIN_INPUT);
  DIO_SetPinValue(DIO_PORTB, DIO_PIN2, DIO_PIN_HIGH);//For pull-up resistance

  
  EXTI_Int0_init();
  EXTI_Int1_init();
  EXTI_Int2_init();
 
  GIE_enable(); //General interrupt enable
  //  EXTI_Int0SetSenseControl(FALLING_EDGE);

  EXTI_Int0SetCallBack(&routine);
  EXTI_Int1SetCallBack(&routine);
  EXTI_Int2SetCallBack(&routine);

  
  
  while(1);
}
