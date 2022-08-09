/**
 *
 * @file       NOKIA5110_interface.h
 * @brief      Contains prototypes for the NOKIA5110 LCD
 * @author     Abdulrahman Aboghanima
 * @date       Tue Aug  9 13:15:11 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */

#ifndef _NOKIA5110_INTERFACE_H_
#define _NOKIA5110_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

/**
 * @brief Initialization of the NOKIA5110 LCD
 * @param void
 * @return void
 */
extern void NOKIA5110_init(void);

/**
 * @brief Sending Command to the NOKia5110 LCD
 * @param command
 * @return void
 */
extern void NOKIA5110_sendCommand(uint8_t command);

/**
 * @brief Sending Data to the NOKia5110 LCD
 * @param data
 * @return void
 */
extern void NOKIA5110_sendData(uint8_t data);

/**
 * @brief Sending Reset Signal to the NOKia5110 LCD
 * @param void
 * @return void
 */
extern void NOKIA5110_reset(void);

/**
 * @brief Set the x, y of the NOKIA5110 LCD
 * @param x, y
 * @return void
 * @note `x` is from range 0:83, 
 *       `y` is from range 0:5
 */
extern void NOKIA5110_setXY(uint8_t x, uint8_t y);





#endif /* _NOKIA5110_INTERFACE_H_ */
