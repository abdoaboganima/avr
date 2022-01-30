/**
 * @file CLCD_interface.h
 * @author Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief User interface of the `CLCD`
 * @version 0.1
 * @copyright Copyright (c) 2022
 */

/**   @addtogroup HAL_drivers
 * @{ @addtogroup CLCD_drivers
 * @{
 */


#ifndef _CLCD_INTERFACE_H_
#define _CLCD_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"

/** @addtogroup CLCD_initialization
 *  @brief Initializes the Crystal LCD
 * @{
 */
void CLCD_Init(void);
/*@}*/

/**
 * @brief Sends a string to the LCD
 * @param string 
 */
void CLCD_SendString(const char *string);

/**
 * @brief Moves the curser to a specific location in the screen \f${(x, y)}\f$
 * @param XPos 
 * @param YPos 
 */
void CLCD_GoTOXY(const uint8_t XPos, const uint8_t YPos);

/**
 * @brief Send a special character that is NOT an ASCII character
 * You can made any character you would like and the bits values of that character are saved
 * into the charArray
 * 
 * @note You can use this link: https://maxpromer.github.io/LCD-Character-Creator/ to generate yours
 * @param charArray 
 * @param charIndex 
 * @param XPos 
 * @param YPos 
 */
void CLCD_SendSpecialChar(const uint8_t *charArray, const uint8_t charIndex, const uint8_t XPos, const uint8_t YPos);

/**
 * @brief Clears the LCD 
 */
void CLCD_Clear(void);

/**
 * @brief Blinks the curser of the LCD 
 */
void CLCD_Blink(void);

/**
 * @brief Converts unsigned value of base x to an ASCII character
 * TODO : Implement that function in the string library 
 * @param value 
 * @param base 
 * @return char* 
 */
char *utoa(uint32_t value, uint8_t base);
#endif /* _CLCD_INTERFACE_H_ */

/*@}@}*/