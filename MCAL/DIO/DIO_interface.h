/*******************************************************
 *
 * @file   DIO_interface.h
 * @breif  Contains the macros and functions prototypes for DIO driver
 * @author Abdulrahman Aboghanima
 * @date   Wed Aug 18 20:02:44 2021
 *
 *******************************************************/

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"

#define DIO_PIN_OUTPUT  1
#define DIO_PIN_INPUT   0

#define DIO_PIN_HIGH    1
#define DIO_PIN_LOW     0

#define DIO_PORT_OUTPUT 0xff
#define DIO_PORT_INPUT  0x00

#define DIO_PORT_HIGH   0xff
#define DIO_PORT_LOW    0x00  

#define DIO_PORTA       0
#define DIO_PORTB       1
#define DIO_PORTC       2
#define DIO_PORTD       3

#define DIO_PIN0        0
#define DIO_PIN1        1
#define DIO_PIN2        2
#define DIO_PIN3        3
#define DIO_PIN4        4
#define DIO_PIN5        5
#define DIO_PIN6        6
#define DIO_PIN7        7


u8 DIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction);

u8 DIO_SetPortDirection(u8 Port, u8 Direction);

u8 DIO_SetPinValue(u8 Port, u8 Pin, u8 Value);

u8 DIO_SetPortValue(u8 Port, u8 Value);

u8 DIO_GetPinValue(u8 Port, u8 Pin, u8 *pu8Value);

#endif /* _DIO_INTERFACE_H_ */
