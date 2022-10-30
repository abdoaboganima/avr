/**
 *
 * @file       DIO_test.c
 * @brief      Contains some tests for the `DIO` module
 * @author     Abdulrahman Aboghanima
 * @date       Sun Oct 30 05:49:22 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */


#include "../MCAL/DIO/DIO_interface.h"


int main(void)
{

  /*Setting port A as output, with all pins high */
  DIO_SetPortDirection(DIO_PORTA, DIO_PORT_OUTPUT);
  DIO_SetPortValue(DIO_PORTA, 0xff);

  /*Setting port B as output, with all pins low */
  DIO_SetPortDirection(DIO_PORTB, DIO_PORT_OUTPUT);
  DIO_SetPortValue(DIO_PORTB, 0x00);

  /*Setting pin0 of port C o be high*/
  DIO_SetPinDirection(DIO_PORTC, DIO_PIN0, DIO_PIN_OUTPUT);
  DIO_SetPinValue(DIO_PORTC, DIO_PIN0, DIO_PIN_HIGH);

  /*Setting pin1 of port D o be high*/
  DIO_SetPinDirection(DIO_PORTD, DIO_PIN1, DIO_PIN_OUTPUT);
  DIO_SetPinValue(DIO_PORTD, DIO_PIN1, DIO_PIN_HIGH);


  /*Setting pin2 of port D o be low*/
  DIO_SetPinDirection(DIO_PORTD, DIO_PIN2, DIO_PIN_OUTPUT);
  DIO_SetPinValue(DIO_PORTD, DIO_PIN2, DIO_PIN_LOW);

  
  while(1){
    
  }
  return 0;
}
