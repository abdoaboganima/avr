/**
 *
 * @file       EEPROM_test.c
 * @brief      Contains some tests for the EEPROM module
 * @author     Abdulrahman Aboghanima
 * @date       Oct 15 20:48:29 2021
 * @copyright  Copyright (c) 2022
 * @version    0.2
 * 
 */

#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/USART/USART_interface.h"
#include "../MCAL/TWI/TWI_interface.h"
#include "../HAL/EEPROM/EEPROM_interface.h"
#include <util/delay.h>


char *data="My name is Abdulrahman.\nIlove Embedded Systems So much. :) ;)\n";
char buffer[1024];

int main(void)
{
  DIO_SetPinDirection(DIO_PORTD, DIO_PIN0, DIO_PIN_INPUT);
  DIO_SetPinDirection(DIO_PORTD, DIO_PIN1, DIO_PIN_OUTPUT);
  
  DIO_SetPortDirection(DIO_PORTC, DIO_PORT_OUTPUT);

  TWI_initMaster();
  USART_init();
  USART_sendStream("Testing EEPROM\n\n");


  USART_sendStream("Reading the Entire EEPROM:\n");
  /*Reading the entire contents of the EEPROM and saving it into `buffer`*/
  EEPROM_readSequence((uint8_t*)buffer, 0, 1024);

  for(uint16_t i=0; i<1024; i++){
    USART_send(buffer[i]);
    if(i%64==0)
      USART_send('\n');
  }

  
  EEPROM_writePage((uint8_t*)data, 0, 16);
  EEPROM_writePage((uint8_t*)&data[16], 16, 16);
  EEPROM_writePage((uint8_t*)&data[32], 32, 16);

  EEPROM_readSequence((uint8_t*)buffer, 0, 48);

  
  while(1){
    
    _delay_ms(6000);
    USART_sendStream("\n\nRead from EEPROM:\n\n");

    for(uint8_t i=0; i<48; i++)
      USART_send(buffer[i]);
    
    USART_sendStream("\n\n");

  }

  return 0;
}
