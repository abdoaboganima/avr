/**
 *
 * @file       LED_program.c
 * @brief      Contains function definitions for the LED module
 * @author     Abdulrahman Aboghanima
 * @date       Tue Aug 16 16:42:48 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../LIB/BIT_MATH.h"
#include "LED_interface.h"



extern void LED_init(const LED_t *const led)
{
  DIO_SetPinDirection(led->led_port, led->led_pin, DIO_PIN_OUTPUT);
  DIO_SetPinValue(led->led_port, led->led_pin, led->led_state);
}

extern void LED_turnOn(LED_t *const led)
{
  /*Saving the new state to the led structure*/
  led->led_state=DIO_PIN_HIGH; 
  DIO_SetPinValue(led->led_port, led->led_pin, led->led_state);
}

extern void LED_turnOff(LED_t *const led)
{
  /*Saving the new state to the led structure*/
  led->led_state=DIO_PIN_LOW;
  DIO_SetPinValue(led->led_port, led->led_pin, led->led_state);
}


extern void LED_toggle(LED_t *const led)
{
  /*Toggling the value of the led*/
  DIO_TogglePinValue(led->led_port, led->led_pin);
  /*Getting the current value and saving it into the state*/
  DIO_GetPinValue(led->led_port, led->led_pin, &led->led_state);
}
