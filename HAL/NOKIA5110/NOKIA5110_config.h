/**
 *
 * @file       NOKIA5110_config.h
 * @brief      Contains user configuration for the NOKIA5110 LCD
 * @author     Abdulrahman Aboghanima
 * @date       Tue Aug  9 17:21:11 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */

#ifndef _NOKIA5110_CONFIG_H_
#define _NOKIA5110_CONFIG_H_


/**
 * The `CTRL_PORT` has two pins, SCE and D_C, used for controlling the LCD
 */
#define CTRL_PORT DIO_PORTA

/**
 * SCE, Chip Enable, Control operation of the LCD, It's active low pin 
 * if SCE=HIGH, LCD ignores the DATA
 * if SCE=LOW, LCD receives the DATA
 */
#define SCE DIO_PIN0

/**
 * D_C = HIGH it's data.
 * D_C = LOW it's Command
 */
#define D_C DIO_PIN1

/**
 * RST : RESET Pin (Active Low) 
 */
#define RST DIO_PIN2


#endif /* _NOKIA5110_CONFIG_H_ */
