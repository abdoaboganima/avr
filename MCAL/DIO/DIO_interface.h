/**
 *
 * @file   DIO_interface.h
 * @brief  Contains the macros and functions prototypes for DIO driver
 * @author Abdulrahman Aboghanima
 * @date   Wed Aug 18 20:02:44 2021
 * @version 0.3
 */

/** @addtogroup MCAL_drivers 
 * @{
 *  @addtogroup DIO_drivers 
 * @{
 */
#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"

/**
 * Defines the possible states for the digital I/o pins
 */
typedef enum
  {
   DIO_PIN_INPUT,   /**< The pin is input */
   DIO_PIN_OUTPUT,  /**< The pin is output*/
  } DIO_PinState_t;

/**
 * Defines the possible states for the entire digital I/O port 
 */
typedef enum
  {
   DIO_PORT_INPUT=  0x00, /**< The entire port is input*/
   DIO_PORT_OUTPUT= 0xff, /**< The entire port is output*/
  } DIO_PortState_t;

/**
 * Defines the possible values for the pin
 */
typedef enum
  {
   DIO_PIN_LOW = 0, /**< The pin value is low*/
   DIO_PIN_HIGH =1, /**< The pin value is high*/
  } DIO_PinValue_t;

/**
 * Defines the possible states for the port value
 */
typedef enum
  {   
   DIO_PORT_LOW  = 0x00,  /**< The entire port value is low*/
   DIO_PORT_HIGH =  0xff, /**< The entire port value is high*/
  } DIO_PortValue_t;

/**
 * Defines the possible ports of the micro controller
 */
typedef enum
  {
   DIO_PORTA, /**< PORTA*/
   DIO_PORTB, /**< PORTB*/
   DIO_PORTC, /**< PORTC*/
   DIO_PORTD, /**< PORTD*/ 

  } DIO_Port_t;

/**
 * Defines the possible channels for every port
 */

typedef enum
  {
   DIO_PIN0, /**< channel/pin 0*/
   DIO_PIN1, /**< channel/pin 1*/
   DIO_PIN2, /**< channel/pin 2*/
   DIO_PIN3, /**< channel/pin 3*/
   DIO_PIN4, /**< channel/pin 4*/
   DIO_PIN5, /**< channel/pin 5*/
   DIO_PIN6, /**< channel/pin 6*/
   DIO_PIN7, /**< channel/pin 7*/
  } DIO_Pin_t;


/**
 * @brief Sets the pin direction wether it's input or output
 * @code 
 * //This will set the PIN0 in PORTA to be output
 * DIO_SetPinDirection(DIO_PORTA, DIO_PIN0, DIO_PIN_OUTPUT);
 * @endcode
 * @param Port 
 * @param Pin 
 * @param Direction 
 * @return uint8_t 
 */
uint8_t DIO_SetPinDirection(DIO_Port_t Port, DIO_Pin_t Pin, DIO_PinState_t Direction);

/**
 * @brief Sets the whole port direction wether it's input or output
 * @code
 * //This will set the PORTA to be input
 * DIO_SetPortDirection(DIO_PORTA, DIO_PORT_INPUT);
 * @endcode
 * @param Port 
 * @param Direction 
 * @return uint8_t 
 */
uint8_t DIO_SetPortDirection(DIO_Port_t Port, DIO_PinState_t Direction);

/**
 * @brief Sets a value for a specific pin from a specific port
 * @code
 * //This will set the PIN5 of the PORTA to be HIGH
 * DIO_SetPinValue(DIO_PORTA, DIO_PIN5, DIO_PIN_HIGH);
 * @endcode
 * @param Port 
 * @param Pin 
 * @param Value 
 * @return uint8_t 
 * @pre The direction of the pin should be specified
 * @attention if the direction is DIO_PIN_INPUT and the Value is DIO_PIN_HIGH,
 * the internal pull up resistance will be enabled
 * @post The pin digital value will be `Value` that passed to the function
 */
uint8_t DIO_SetPinValue(DIO_Port_t Port, DIO_Pin_t Pin, DIO_PinValue_t Value);

/**
 * @brief Sets the whole port to a specific value
 * @code
 * //This will set the DIO_PORTA to be 55
 * DIO_SetPortValue(DIO_PORTA, 55);
 * @endcode
 * @param Port 
 * @param Value 
 * @return uint8_t 
 * @pre The direction of the port should be specified
 * @post The port digital value will be `Value` that passed to the function
 */
uint8_t DIO_SetPortValue(DIO_Port_t Port, uint8_t Value);

/**
 * @brief Gets a specific pin value from a specific port and assign that value
 * memory location addressed by puint8_tValue
 * @code
 * //This will set the ptrtou8 to be the value oc the PIN3 in the PORTD
 * DIO_GetPinValue(DIO_PORTD, DIO_PIN3, ptrtou8_t)
 * @endcode
 * @param Port 
 * @param Pin 
 * @param puint8_tValue 
 * @return uint8_t 
 */
uint8_t DIO_GetPinValue(DIO_Port_t Port, DIO_Pin_t Pin, DIO_PinValue_t *puint8_tValue);

/**
 * @brief Toggle a specific pin value
 * @param Port 
 * @param Pin
 * @return uint8_t 
 */
uint8_t DIO_TogglePinValue(DIO_Port_t Port, DIO_Pin_t Pin);

#endif /* _DIO_INTERFACE_H_ */


/** @}@}*/
