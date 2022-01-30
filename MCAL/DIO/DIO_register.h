/*******************************************************
 *
 * @file   DIO_register.h
 * @brief  contains the addresses of the register
 * @author Abdulrahman Aboghanima
 * @date   Wed Aug 18 16:37:25 2021
 *
 *******************************************************/

#ifndef _DIO_REGISTER_H_
#define _DIO_REGISTER_H_

#define PORTA  *((volatile uint8_t*) 0x3b)
#define DDRA   *((volatile uint8_t*) 0x3a)
#define PINA   *((volatile uint8_t*) 0x39)

#define PORTB  *((volatile uint8_t*) 0x38)
#define DDRB   *((volatile uint8_t*) 0x37)
#define PINB   *((volatile uint8_t*) 0x36)

#define PORTC  *((volatile uint8_t*) 0x35)
#define DDRC   *((volatile uint8_t*) 0x34) 
#define PINC   *((volatile uint8_t*) 0x33)

#define PORTD  *((volatile uint8_t*) 0x32)
#define DDRD   *((volatile uint8_t*) 0x31)
#define PIND   *((volatile uint8_t*) 0x30)

#endif /* _DIO_REGISTER_H_ */
