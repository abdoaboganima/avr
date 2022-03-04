/**
 * @file      USART_program.c
 * @author    Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief     The implementations of the USART functions
 * @version   0.3
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "USART_register.h"
#include "USART_interface.h"
#include "USART_config.h"
#include <stdio.h>


/* These two functions should have these parameters because of the `fdevopen`*/
static int USART_putchar(const char c, FILE *stream);
static int USART_getchar(FILE *stream);



extern void __vector_13(void) __attribute__((signal));  /* USART Rx Complete */
extern void __vector_15(void) __attribute__((signal));  /* USART Tx Complete */


static void (*receiveComplete)(void)=NULL;
static void (*transmissionComplete)(void)=NULL;


static FILE USART_stream=FDEV_SETUP_STREAM(USART_putchar, USART_getchar, _FDEV_SETUP_RW);



extern void USART_init(void)
{
  /*
    If you would like to write on the `UCSRC` the `URSEL` bit must be set, 
    else the data will be written to the `UBRRH`*/
  
  uint8_t UCSRC_value=0b10000110;     /*Selects the character size to be 8-bit*/
  UCSRC=UCSRC_value;
  UBRRL=F_CPU/16/BAUD_RATE-1;         /*Baud rate 9600 bit/second */
  
  /* Enable Receiving and transmitting*/
  SET_BIT(UCSRB, UCSRB_RXEN);
  SET_BIT(UCSRB, UCSRB_TXEN);

  /*Clear the screen*/
  USART_clear_screen();
}


extern void USART_send(const uint8_t data)
{
  if(data=='\n') USART_send('\r');
  while(GET_BIT(UCSRA, UCSRA_UDRE)==0);     /* Wait until the USART Data register is Empty*/
  UDR=data;                                 /* Note: Writing on `UDR` clears the UDRE flag*/
}

extern uint8_t USART_receive(void)
{
  while(GET_BIT(UCSRA, UCSRA_RXC)==0);      /* Busy Waiting: Wait until the receiving is complete*/
  return UDR;                               /* Note: Reading `UDR` Clears the RXC flag*/
}

static int USART_putchar(const char c, FILE *stream)
{
  if(c=='\n') USART_putchar('\r', stream);  /* Add the carriage return to make the newline begin from 1st character*/
  while(GET_BIT(UCSRA, UCSRA_UDRE)==0);
  UDR=c;
  return 0;
}

static int USART_getchar(FILE *stream)
{
  while(GET_BIT(UCSRA, UCSRA_RXC)==0);
  return UDR;                         
}


extern uint8_t USART_receiveWithInterruptDriven(void (*receiveCompleteCallBack)(void))
{
  receiveComplete=receiveCompleteCallBack;  /* This will be called in the ISR of receive complete*/
  SET_BIT(UCSRB, UCSRB_RXCIE);              /* Receive Complete Interrupt Enable */
  while(GET_BIT(UCSRA, UCSRA_RXC)==0);      /* Wait until the receive is complete*/
  return UDR;
}

extern void USART_sendWithInterruptDriven(const uint8_t data, void (*transmissionCompleteCallBack)(void))
{
  transmissionComplete=transmissionCompleteCallBack;
  while(GET_BIT(UCSRA, UCSRA_UDRE)==0);    /* Wait till the `UDR` is empty*/
  SET_BIT(UCSRB, UCSRB_TXCIE);             /* Tranmission Complete Interrupt Enable */
  UDR=data;
}

extern void USART_sendStream(const char *stream)
{
  while(*stream)
    USART_send(*stream++);
}

extern void USART_disableReceiver(void)
{
  CLEAR_BIT(UCSRB, UCSRB_RXEN);
}


extern inline void USART_redirect_stream_to_stdout(void)
{
  stdout = &USART_stream;
}



/* Interrupt service routines vectors */
extern void __vector_13(void) 
{
  receiveComplete();
  CLEAR_BIT(UCSRB, UCSRB_RXCIE);       /* Receive Complete Interrupt Disable */
}

extern void __vector_15(void)
{
  transmissionComplete();
  CLEAR_BIT(UCSRB, UCSRB_TXCIE);      /* Transmission Complete Interrupt Disable*/
}
