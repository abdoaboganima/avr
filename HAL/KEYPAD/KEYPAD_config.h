/**
 *
 * @file       KEYPAD_config.h
 * @brief      Contains configurations for the keypad
 * @author     Abdulrahman Aboghanima
 * @date       Mon Aug 15 21:21:46 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */

#ifndef _KEYPAD_CONFIG_H_
#define _KEYPAD_CONFIG_H_
#include "../../MCAL/DIO/DIO_interface.h"

 /**
 * @brief The port that keypad connected in
 */
#define KEYPAD_PORT DIO_PORTD



#define KEYPAD_ROW0 DIO_PIN0
#define KEYPAD_ROW1 DIO_PIN1
#define KEYPAD_ROW2 DIO_PIN2
#define KEYPAD_ROW3 DIO_PIN3



#define KEYPAD_COL0 DIO_PIN4
#define KEYPAD_COL1 DIO_PIN5
#define KEYPAD_COL2 DIO_PIN6
#define KEYPAD_COL3 DIO_PIN7



 /**
 * @brief The array of character that you'd like to configure
 */
#define KEYPAD_ARRAY {\
		      {'7', '8', '9', '/'},\
		      {'4', '5', '6', '*'},\
		      {'1', '2', '3', '-'},\
		      {'O', '0', '=', '+'}}


#endif /* _KEYPAD_CONFIG_H_ */
