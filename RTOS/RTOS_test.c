/**
 *
 * @file       RTOS_test.c
 * @brief      
 * @author     Abdulrahman Aboghanima
 * @date       Mon Apr 25 11:19:17 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */
#include "../MCAL/DIO/DIO_interface.h"
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "RTOS_interface.h"

void LED1(void);
void LED2(void);
void LED3(void);

int main()
{

  DIO_SetPortDirection(DIO_PORTA, DIO_PORT_HIGH);
  DIO_SetPinValue(DIO_PORTA, DIO_PIN0, DIO_PIN_HIGH);
  DIO_SetPinValue(DIO_PORTA, DIO_PIN1, DIO_PIN_HIGH);
  DIO_SetPinValue(DIO_PORTA, DIO_PIN2, DIO_PIN_HIGH);

  RTOS_create_task(0, 1000, LED1); /*Task that's executed every 1000 systick (us)*/
  RTOS_create_task(1, 2000, LED1); /*Task that's executed every 2000 systick (us)*/
  RTOS_create_task(2, 3000, LED1); /*Task that's executed every 3000 systick (us)*/
  
  RTOS_start();

  while(1){
    /*Do nothing*/
  }
  return 0;
}


void LED1(void)
{
  static uint8_t state=0;
  TOGGLE_BIT(state, 0);
  DIO_SetPinValue(DIO_PORTA, DIO_PIN0, state);
}

void LED2(void)
{
  static uint8_t state=0;
  TOGGLE_BIT(state, 0);
  DIO_SetPinValue(DIO_PORTA, DIO_PIN1, state);
}

void LED3(void)
{
  static uint8_t state=0;
  TOGGLE_BIT(state, 0);
  DIO_SetPinValue(DIO_PORTA, DIO_PIN2, state);  
}
