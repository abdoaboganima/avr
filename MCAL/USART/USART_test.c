/*******************************************************
 *
 * @file       USART_test.c
 * @brief      Tests for the USART driver
 * @author     Abdulrahman Aboghanima
 * @date       Sun Feb 20 22:55:31 2022
 * @copyright  Copyright (c) 2022
 * @version    0.2
 *
 *******************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../DIO/DIO_interface.h"
#include "../GIE/GIE_interface.h"
#include "USART_interface.h"
#include <util/delay.h>
#include <stdio.h>


/* The following two functions are used as a call back for the ISRs of the USART*/
void blink1(void)
{
  DIO_SetPinValue(DIO_PORTD, DIO_PIN6, 1);
  _delay_ms(1000);
  DIO_SetPinValue(DIO_PORTD, DIO_PIN6, 0);
  _delay_ms(1000);
  DIO_SetPinValue(DIO_PORTD, DIO_PIN6, 1);
  _delay_ms(1000);
  DIO_SetPinValue(DIO_PORTD, DIO_PIN6, 0);
}
void blink2(void)
{
  DIO_SetPinValue(DIO_PORTD, DIO_PIN5, 1);
  _delay_ms(1000);
  DIO_SetPinValue(DIO_PORTD, DIO_PIN5, 0);
}
int main(void)
{

  DIO_SetPortDirection(DIO_PORTD, DIO_PORT_OUTPUT);
  GIE_enable();
  USART_init();
  USART_redirect_stream_to_stdout();
  uint8_t data;

  while(1){
    printf("\n.............Testing the USART.............\n");
    printf("Testing printf()\n");
    printf("Done   \n");

    printf("Testing: USART_sendStream()\n");
    USART_sendStream("------------------------------\n");
    USART_sendStream(">Testing not interrupt driven data transmission..\n");
    USART_sendStream(">>>1- Sending `k`: ");
    USART_send('k');
    USART_sendStream("\n>>>2- Receiving a letter: ");
    data=USART_receive();
    USART_sendStream("\n      You entered: ");
    USART_send(data);

    USART_sendStream("\n>Testing interrupt driven data transmission..");
    USART_sendStream("\n>>>1- Sending `k` with led blinking after transmission complete: ");
    USART_sendWithInterruptDriven('k', blink1); _delay_ms(1000);
    USART_sendStream("\n>>>2- Receiving a letter: ");
    data=USART_receiveWithInterruptDriven(blink2);
    USART_sendStream("\n      You entered: ");
    USART_send(data);
  
  }
	
  return 0;
}
