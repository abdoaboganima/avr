#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "USART_register.h"
#include "USART_interface.h"

void USART_init(void)
{

  /*
    If you would like to write on the `UCSRC` the `URSEL` must be set, 
    else the data will be written to the ``
   */
  u8 UCSRC_value=0b10000110;            /*Selects the characte size to be 8-bit*/
  UCSRC=UCSRC_value;

  UBRRL=51;                             /*Baud rate 9600 bit/second */
  
  /* Enable Receving and transmitting*/
  SET_BIT(UCSRB, UCSRB_RXEN);
  SET_BIT(UCSRB, UCSRB_TXEN);
  
}


u8 USART_receive(void)
{
  while(GET_BIT(UCSRA, UCSRA_RXC)==0);   /*Busy Waiting: Wait until the receiving is complete*/
  return UDR;
}

void USART_send(u8 data)
{
  while(GET_BIT(UCSRA, UCSRA_UDRE)==0); /* Wait unti the USART Data register is Empty*/
  UDR=data;
}

void USART_sendStream(char *stream)
{
  u8 i=0;
  while(stream[i]!=0)
    USART_send(stream[i++]);
}
