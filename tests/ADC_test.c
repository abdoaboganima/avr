/**
 *
 * @file       ADC_test.c
 * @brief      Contains test for ADC
 * @author     Abdulrahman Aboghanima
 * @date       Fri Aug 26 17:18:26 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */

#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#include <util/delay.h>

int main()
{
  /*Setting the Pin0 of the PORTA to ne input for the ADC*/
  DIO_SetPinDirection(DIO_PORTA, DIO_PIN0, DIO_PIN_INPUT);
  /*Setting both PORT C, D as the output of the converted analog value*/
  DIO_SetPortDirection(DIO_PORTC, DIO_PORT_OUTPUT);
  DIO_SetPortDirection(DIO_PORTD, DIO_PORT_OUTPUT);
  
  ADC_init();

  uint16_t reading;

  while(1){
    ADC_startSynchConversion(adc0, &reading);
    DIO_SetPortValue(DIO_PORTC, reading);
    DIO_SetPortValue(DIO_PORTD, reading>>8);  
    _delay_ms(500);
  }
  return 0;
}
