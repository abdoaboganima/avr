 /**
 * @file EEPROM_interface.h
 * @author Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief  Contains functions declaration for the EEPROM module
 * @version 0.2
 * @copyright Copyright (c) 2022
 */

 
#ifndef _EEPROM_INTERFACE_H_
#define _EEPROM_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"
 
 /**
 * @brief Send a byte of data to the EEPROM
 * @param data 
 * @param address 
 */
extern void EEPROM_writeByte(const uint8_t data, const uint16_t address);

 /**
 * @brief Read a byte of data from the EEPROM, the byte will be stored 
 * in the memory location addressed by `var`.
 * @param var 
 * @param address 
 */
extern void EEPROM_readByte(uint8_t * const var, const uint16_t address);

 /**
 * @brief Send sequence of data addressed by `sequence` to the EEPROM across the I^{2}C bus
 * @bug Sending more than 12 bytes across the I2C bus causes errors.
 * @param sequence 
 * @param firstAddress 
 * @param sequenceSize 
 * @note The data that will be stored is addressed by `sequence` and `fisrtAddress` is
 * the first address in the EEPROM of the data that will be stored
 * @code EEPROM_writePage("CoolStuff", 10, 9);
 * @endcode 
 */
extern void EEPROM_writePage(const uint8_t * const sequence, const uint16_t firstAddress, const uint8_t pageSize);

 /**
 * @brief Read sequence of data from the EEPROM and store them in a memory location addressed by `sequence`
 * @param sequence 
 * @param firstAddress 
 * @param pageSize
 * @note In the code bellow the data will be stored in the `buff` starting from the
 * address 20 in the EEPROM till address 1019 
 * @code 
 * uint8_t buff[1000];
 * EEPROM_readSequence(buff, 20, 1000);
 * @endcode 
 * @note The maximum size of the page must be 16-byte
 */
extern void EEPROM_readSequence(uint8_t * const sequence, const uint16_t firstAddress, const uint16_t sequenceSize);


#endif /* _EEPROM_INTERFACE_H_ */
