#ifndef _EEPROM_INTERFACE_H_
#define _EEPROM_INTERFACE_H_
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
void EEPROM_sendByte(u8 data, u16 address);
void EEPROM_readByte(u8 *var, u16 address);
#endif /* _EEPROM_INTERFACE_H_ */
