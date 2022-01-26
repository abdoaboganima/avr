 /*****************************************************************************
 * @file CLCD_config.h
 * @author Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-26
 * 
 * @copyright Copyright (c) 2022
 * 
 ****************************************************************************/
/** @addtogroup HAL_drivers
 * @{
 * @addtogroup CLCD_drivers
 * @{
 * @addtogroup CLCD_config
 * @{
 */

#ifndef _CLCD_CONFIG_H_
#define _CLCD_CONFIG_H_

#include "../../MCAL/DIO/DIO_interface.h"

 /**
 * Choose the DATA PORT of the CLCD
 */
#define CLCD_DATA_PORT DIO_PORTB
 
 /**
 * Choose the Control PORT of the CLCD
 */
#define CLCD_CTRL_PORT DIO_PORTA

 
#define CLCD_RS_PIN    DIO_PIN0
#define CLCD_RW_PIN    DIO_PIN1
#define CLCD_EN_PIN     DIO_PIN2

 /**
 * @brief Choose the mode option of the CLCD
 * @note You can select the `MODE_4_BIT` or `MODE_8_BIT`
 * @note In 4-bit mode:
 * 				Connect the 4-most Significant Bit of the LCD_DATA_PORT
 * 				with the 4-most significant bits of the microcontroller.
 */
#define CLCD_MODE MODE_4_BIT


#endif /* _CLCD_CONFIG_H_ */
/*@}@}@}*/