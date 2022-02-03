 /**
 * @file EEPROM_interface.h
 * @author Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief 
 * @version 0.1
 * @copyright Copyright (c) 2022
 */

 /** @addtogroup HAL_drivers
  * @{
  * @addtogroup EEPROM_drivers
  * @{
  */
 
#ifndef _EEPROM_INTERFACE_H_
#define _EEPROM_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"
 
 /**
 * @brief Send a byte of data to the EEPROM
 * @param data 
 * @param address 
 */
void EEPROM_sendByte(const uint8_t data, const uint16_t address);

 /**
 * @brief Read a byte of data from the EEPROM, the byte will be stored 
 * in the memory location addressed by var.
 * @param var 
 * @param address 
 */
void EEPROM_readByte(uint8_t * const var, const uint16_t address);

 /**
 * @brief Send sequence of data addressed by `sequence` to the EEPROM across the I^{2}C bus
 * @bug Sending more than 12 bytes across the I2C bus causes errors.
 * @param sequence 
 * @param firstAddress 
 * @param sequenceSize 
 * @note The data that will be stored is addressed by `sequence` and `fisrtAddress` is
 * the first address in the EEPROM of the data that will be stored
 * @code EEPROM_sendSequence("CoolStuff", 10, 9);
 * @endcode 
 */
void EEPROM_sendSequence(uint8_t * const sequence, const uint16_t firstAddress, const uint16_t sequenceSize);

 /**
 * @brief Read sequence of data from the EEPROM and store them in a memory location addressed by `sequence`
 * @param sequence 
 * @param firstAddress 
 * @param sequenceSize 
 * @note In the code bellow the data will be stored in the `buff` starting from the
 * address 20 in the EEPROM till address 1019 
 * @code 
 * uint8_t buff[1000];
 * EEPROM_readSequence(buff, 20, 1000);
 * @endcode 
 */
void EEPROM_readSequence(uint8_t * const sequence, const uint16_t firstAddress, const uint16_t sequenceSize);

#endif /* _EEPROM_INTERFACE_H_ */
/*@}@}*/
