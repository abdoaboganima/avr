/**
 *
 * @file       PORT_register.h
 * @brief      Contains register definitions for the `PORT` module
 * @author     Abdulrahman Aboghanima
 * @date       Mon Aug 15 17:31:01 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */

#ifndef _PORT_REGISTER_H_
#define _PORT_REGISTER_H_
#include "../../LIB/STD_TYPES.h"

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



#endif /* _PORT_REGISTER_H_ */
