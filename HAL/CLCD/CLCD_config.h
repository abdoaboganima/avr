#ifndef _CLCD_CONFIG_H_
#define _CLCD_CONFIG_H_

#include "../../MCAL/DIO/DIO_interface.h"


#define CLCD_DATA_PORT DIO_PORTB
#define CLCD_CTRL_PORT DIO_PORTA

#define CLCD_RS_PIN    DIO_PIN0
#define CLCD_RW_PIN    DIO_PIN1
#define CLCD_EN_PIN     DIO_PIN2

/* Mode options :
           MODE_4_BIT
	   MODE_8_BIT
*/
#define CLCD_MODE MODE_4_BIT
/*	Notes:
 * 		In 4-bit mode:
 * 				Connect the 4-most Significant Bit of the LCD_DATA_PORT
 * 				with the 4-most significant bits of the microcontroller.
 * */


#endif /* _CLCD_CONFIG_H_ */
