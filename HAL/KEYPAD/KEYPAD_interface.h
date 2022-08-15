/**
 *
 * @file       KEYPAD_interface.h
 * @brief      Contains functions declarations for keypad
 * @author     Abdulrahman Aboghanima
 * @date       Mon Aug 15 21:19:10 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */


#ifndef _KEYPAD_INTERFACE_H_
#define _KEYPAD_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"


 /**
 * @brief Initializes the KEYPAD
 */
extern void KEYPAD_init(void);



 /**
 * @brief Returns the pressed key, if there is no pressed key the value of 
 * the macro `NO_KEY_PRESSED` will be returned
 * @return uint8_t 
 * @code 
 * uint8_t data=KEYPAD_getPressedKey();
 * while(data!=NO_KEY_PRESSED)
 *    do_stuff(data); //for example
 * @endcode
 */
extern uint8_t KEYPAD_getPressedKey(void);


/**
 * Value that's returned by `KEYPAD_getPressedKey()` if there is no key pressed
 * @see KEYPAD_getPressedKey()
 */
#define NO_KEY_PRESSED 0xff


#endif /* _KEYPAD_INTERFACE_H_ */
