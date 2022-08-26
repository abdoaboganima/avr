/**
 *
 * @file       LED_test.c
 * @brief      Contains some tests for the LED module
 * @author     Abdulrahman Aboghanima
 * @date       Tue Aug 16 16:49:16 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */

#include "LED_interface.h"
#include <util/delay.h>
#include "../../MCAL/DIO/DIO_interface.h"

int main()
{
  LED_t led1={DIO_PORTA, DIO_PIN2, LED_ON};
  LED_t led2={DIO_PORTB, DIO_PIN3, LED_OFF};
  LED_t led3={DIO_PORTC, DIO_PIN1, LED_OFF};
  LED_t led4={DIO_PORTD, DIO_PIN7, LED_ON};
  
  
  LED_init(&led1);
  LED_init(&led2);
  LED_init(&led3);
  LED_init(&led4);
  _delay_ms(2000);


  LED_turnOff(&led1);
  LED_turnOff(&led4);
  LED_turnOn(&led2);
  LED_turnOn(&led3);
  _delay_ms(2000);

  while(1){
    LED_toggle(&led1);
    LED_toggle(&led2);
    LED_toggle(&led3);
    LED_toggle(&led4);
    _delay_ms(2000);
  }

  

  
  return 0;
}
