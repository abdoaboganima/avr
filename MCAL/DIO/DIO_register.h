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

#define HW_REG8(x)   *((volatile uint8_t*) x)


#define PORTA  HW_REG8(0x3b)
#define DDRA   HW_REG8(0x3a)
#define PINA   HW_REG8(0x39)

#define PORTB  HW_REG8(0x38)
#define DDRB   HW_REG8(0x37)
#define PINB   HW_REG8(0x36)

#define PORTC  HW_REG8(0x35)
#define DDRC   HW_REG8(0x34) 
#define PINC   HW_REG8(0x33)

#define PORTD  HW_REG8(0x32)
#define DDRD   HW_REG8(0x31)
#define PIND   HW_REG8(0x30)

#endif /* _DIO_REGISTER_H_ */
