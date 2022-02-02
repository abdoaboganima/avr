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
void EEPROM_sendByte(const uint8_t data,const uint16_t address);

 /**
 * @brief Read a byte of data from the EEPROM, the byte will be stored 
 * in the memory location addressed by var.
 * @param var 
 * @param address 
 */
void EEPROM_readByte(uint8_t * const var, const uint16_t address);

#endif /* _EEPROM_INTERFACE_H_ */
/*@}@}*/
