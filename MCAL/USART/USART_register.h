 /**
 * @file USART_register.h
 * @author Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief The IO memory mapped addresses of the USART
 * @version 0.1
 * @copyright Copyright (c) 2022
 */
#ifndef _USART_REGISTER_H_
#define _USART_REGISTER_H_

#define  UDR             *((volatile uint8_t*) 0x2c)

#define  UCSRA           *((volatile uint8_t*) 0x2b)

#define  UCSRA_MPCM  0   
#define  UCSRA_U2X   1
#define  UCSRA_PE    2
#define  UCSRA_DOR   3
#define  UCSRA_FE    4
#define  UCSRA_UDRE  5 
#define  UCSRA_TXC   6
#define  UCSRA_RXC   7


#define  UCSRB           *((volatile uint8_t*) 0x2a)

#define  UCSRB_TXB8   0
#define  UCSRB_RXB8   1
#define  UCSRB_UCSZ2  2
#define  UCSRB_TXEN   3
#define  UCSRB_RXEN   4
#define  UCSRB_UDRIE  5
#define  UCSRB_TXCIE  6
#define  UCSRB_RXCIE  7


#define  UCSRC           *((volatile uint8_t*) 0x40)

#define  UCSRC_UCPOL  0
#define  UCSRC_UCSZ0  1
#define  UCSRC_UCSZ1  2
#define  UCSRC_USBS   3
#define  UCSRC_UPM0   4
#define  UCSRC_UPM1   5
#define  UCSRC_UMSEL  6
#define  UCSRC_URSEL  7

#define  UBRRH           *((volatile uint8_t*) 0x40)
#define  UBRRL           *((volatile uint8_t*) 0x29)

/* #define             *((volatile uint8_t*) ) */
/* #define             *((volatile uint8_t*) ) */
/* #define             *((volatile uint8_t*) ) */
/* #define             *((volatile uint8_t*) ) */
/* #define             *((volatile uint8_t*) ) */
/* #define             *((volatile uint8_t*) ) */

#endif /* _USART_REGISTER_H_ */
