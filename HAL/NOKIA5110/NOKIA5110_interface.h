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
extern void NOKIA5110_sendCommand(const uint8_t command);

/**
 * @brief Sending Data to the NOKia5110 LCD
 * @param data
 * @return void
 */
extern void NOKIA5110_sendData(const uint8_t data);

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

/**
 * @brief Sets NOKIA5110 display to be in the normal mode
 * @param void
 * @return void
 * @see NOKIA5110_setNormalMode()
 * @see NOKIA5110_setInverseVideoMode()
 * @see NOKIA5110_setBlankMode()
 * @see NOKIA5110_setAllSegmentsON()
 * @note The display is set to the normal mode during the initialization
 */
extern void NOKIA5110_setNormalMode(void);

/**
 * @brief Sets NOKIA5110 display to be in the inverse video mode
 * @param void
 * @return void
 * @see NOKIA5110_setNormalMode()
 * @see NOKIA5110_setInverseVideoMode()
 * @see NOKIA5110_setBlankMode()
 * @see NOKIA5110_setAllSegmentsON()
 * @note Then displayed bits will be flipped
 * @note If you have decoded data in the normal mode, 
 *       you have to flip its bits value in the inverse mode (i.e. ~data)
 */
extern void NOKIA5110_setInverseVideoMode(void);

/**
 * @brief Sets NOKIA5110 display to be in the Blank mode
 * @param void
 * @return void
 * @see NOKIA5110_setNormalMode()
 * @see NOKIA5110_setInverseVideoMode()
 * @see NOKIA5110_setBlankMode()
 * @see NOKIA5110_setAllSegmentsON()
 */
extern void NOKIA5110_setBlankMode(void);


/**
 * @brief Sets NOKIA5110 display all segments to be on
 * @param void
 * @return void
 * @see NOKIA5110_setNormalMode()
 * @see NOKIA5110_setInverseVideoMode()
 * @see NOKIA5110_setBlankMode()
 * @see NOKIA5110_setAllSegmentsON() 
 * @bug Cannot go back to the normal mode after using this mode
 */
extern void NOKIA5110_setAllSegmentsON(void);


extern void NOKIA5110_clearDisplay(void);
extern void NOKIA5110_setContrast(uint8_t contrast);

#endif /* _NOKIA5110_INTERFACE_H_ */
