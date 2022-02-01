 /**
 * @file USART_program.c
 * @author Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief  The implementations of the USART functions
 * @version 0.1
 * @copyright Copyright (c) 2022
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "USART_register.h"
#include "USART_interface.h"
#include "USART_config.h"

static void (*receiveComplete)(void)=NULL;
static void (*transmissionComplete)(void)=NULL;

void USART_init(void)
{
  /*
    If you would like to write on the `UCSRC` the `URSEL` bit must be set, 
    else the data will be written to the `UBRRH`
   */
  uint8_t UCSRC_value=0b10000110;     /*Selects the character size to be 8-bit*/
  UCSRC=UCSRC_value;
  UBRRL=F_CPU/16/BAUD_RATE-1;         /*Baud rate 9600 bit/second */
  
  /* Enable Receiving and transmitting*/
  SET_BIT(UCSRB, UCSRB_RXEN);
  SET_BIT(UCSRB, UCSRB_TXEN);
  
}


uint8_t USART_receive(void)
{
  while(GET_BIT(UCSRA, UCSRA_RXC)==0);      /* Busy Waiting: Wait until the receiving is complete*/
  return UDR;                               /* Note: Reading `UDR` Clears the RXC flag*/
}

void USART_send(const uint8_t data)
{
  while(GET_BIT(UCSRA, UCSRA_UDRE)==0);     /* Wait until the USART Data register is Empty*/
  UDR=data;                                 /* Note: Writing on `UDR` clears the UDRE flag*/
}


uint8_t USART_receiveWithInterruptDriven(void (*receiveCompleteCallBack)(void))
{
  receiveComplete=receiveCompleteCallBack;  /* This will be called in the ISR of receive complete*/
  SET_BIT(UCSRB, UCSRB_RXCIE);              /* Receive Complete Interrupt Enable */
  while(GET_BIT(UCSRA, UCSRA_RXC)==0);      /* Wait until the receive is complete*/
  return UDR;
}

void USART_sendWithInterruptDriven(const uint8_t data, void (*transmissionCompleteCallBack)(void))
{
  transmissionComplete=transmissionCompleteCallBack;
  SET_BIT(UCSRB, UCSRB_TXCIE);             /* Tranmission Complete Interrupt Enable */
  while(GET_BIT(UCSRA, UCSRA_UDRE)==0);    /* Wait till the `UDR` is empty*/
  UDR=data;
}

void USART_sendStream(const char *stream)
{
  uint8_t i=0;
  while(stream[i]!=0)
    USART_send(stream[i++]);
}

void USART_disableReceiver(void)
{
  CLEAR_BIT(UCSRB, UCSRB_RXEN);
}


void __vector_13(void)
{
  receiveComplete();
  CLEAR_BIT(UCSRB, UCSRB_RXCIE);       /* Receive Complete Interrupt Disable */
}
void __vector_15(void)
{
  transmissionComplete();
  CLEAR_BIT(UCSRB, UCSRB_TXCIE);      /* Transmission Complete Interrupt Disable*/
}