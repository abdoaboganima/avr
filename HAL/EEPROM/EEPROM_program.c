#include "EEPROM_interface.h"
#include "EEPROM_config.h"
#include "../../MCAL/TWI/TWI_interface.h"
#include "../../LIB/STD_TYPES.h"

/*
Suppos you would like to access memory which address is : X9X8X7X6X5X4X3X2X1X0
So in order to access that location you have to through the following address in the I^{2}C Bus
|---+---+---+---+----+----+----|
| 1 | 0 | 1 | 0 | A2 | X9 | X8 |
|---+---+---+---+----+----+----|

*/

void EEPROM_sendByte(const uint8_t data, const uint16_t address)
{
  TWI_sendStartCondition();
  /*The address of the `AT24C08A` consists of 3 pats
      1- 1010 Selects the `AT24C08A`
      2- A2 select which `AT24C08A` you will communicate with, you can connect up to two
      3  The two LSB selects the block number in the memory 
  */
  TWI_sendSlaveAddressWithWrite( 0b1010000 | (A2_PIN<<2) |(address>>8) );
  TWI_masterWriteDataByte( (uint8_t) address);
  TWI_masterWriteDataByte(data);
  TWI_sendStopCondition();
  
}

void EEPROM_readByte(uint8_t * const var, const uint16_t address)
{
  TWI_sendStartCondition();
  TWI_sendSlaveAddressWithWrite( 0b1010000 | (A2_PIN<<2) | (address>>8) );
  TWI_masterWriteDataByte((uint8_t)address);
  TWI_sendRepeatedStartCondition();
  TWI_sendSlaveAddressWithRead( 0b1010000 | (A2_PIN<<2) | (address>>8) );
  TWI_masterReadDataByte(var);
  TWI_sendStopCondition();
  
}
