/*******************************************************
 *
 * @file   DIO_interface.h
 * @brief  Contains the macros and functions prototypes for DIO driver
 * @author Abdulrahman Aboghanima
 * @date   Wed Aug 18 20:02:44 2021
 *
 *******************************************************/
/** @addtogroup MCAL_drivers 
 * @{
 *  @addtogroup DIO_drivers 
 * @{
 */
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

/**
 * @brief Sets the pin direction wether it's input or output
 * @code 
 * //This will set the PIN0 in PORTA to be output
 * DIO_SetPinDirection(DIO_PORTA, DIO_PIN0, DIO_PIN_OUTPUT);
 * @endcode
 * @param Port 
 * @param Pin 
 * @param Direction 
 * @return u8 
 */
u8 DIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction);

/**
 * @brief Sets the whole port direction wether it's input or output
 * @code
 * //This will set the PORTA to be input
 * DIO_SetPortDirection(DIO_PORTA, DIO_PORT_INPUT);
 * @endcode
 * @param Port 
 * @param Direction 
 * @return u8 
 */
u8 DIO_SetPortDirection(u8 Port, u8 Direction);

/**
 * @brief Sets a value for a specific pin from a specific port
 * @code
 * //This will set the PIN5 of the PORTA to be HIGH
 * DIO_SetPinValue(DIO_PORTA, DIO_PIN5, DIO_PIN_HIGH);
 * @endcode
 * @param Port 
 * @param Pin 
 * @param Value 
 * @return u8 
 */
u8 DIO_SetPinValue(u8 Port, u8 Pin, u8 Value);

/**
 * @brief Sets the whole port to a specific value
 * @code
 * //This will set the DIO_PORTA to be 55
 * DIO_SetPortValue(DIO_PORTA, 55);
 * @endcode
 * @param Port 
 * @param Value 
 * @return u8 
 */
u8 DIO_SetPortValue(u8 Port, u8 Value);

/**
 * @brief Gets a specific pin value from a specific port and assign that value
 * memory location addressed by pu8Value
 * @code
 * //This will set the ptrto8 to be the value oc the PIN3 in the PORTD
 * DIO_GetPinValue(DIO_PORTD, DIO_PIN3, ptrtou8)
 * @endcode
 * @param Port 
 * @param Pin 
 * @param pu8Value 
 * @return u8 
 */
u8 DIO_GetPinValue(u8 Port, u8 Pin, u8 *pu8Value);

#endif /* _DIO_INTERFACE_H_ */


/** @}@}*/