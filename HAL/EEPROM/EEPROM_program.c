 /**
 * @file EEPROM_program.c
 * @author Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-03
 * @todo Fix or remove the delays. Include the in the I2C driver
 * @copyright Copyright (c) 2022
 */
#include "EEPROM_interface.h"
#include "EEPROM_config.h"
#include "../../MCAL/TWI/TWI_interface.h"
#include "../../LIB/STD_TYPES.h"
#include <util/delay.h>
/*
Suppos you would like to access memory which address is : X9X8X7X6X5X4X3X2X1X0
So in order to access that location you have to through the following address in the I^{2}C Bus
|---+---+---+---+----+----+----|
| 1 | 0 | 1 | 0 | A2 | X9 | X8 |
|---+---+---+---+----+----+----|

*/

static inline void EEPROM_sendAddress(const uint16_t address)
{
  TWI_sendStartCondition();
  _delay_ms(50);
  /*The address of the `AT24C08A` consists of 3 pats
      1- 1010 Selects the `AT24C08A`
      2- A2 select which `AT24C08A` you will communicate with, you can connect up to two
      3  The two LSB selects the block number in the memory 
  */
  TWI_sendSlaveAddressWithWrite( 0b1010000 | (A2_PIN<<2) |(address>>8) );
  _delay_ms(50);
  TWI_masterWriteDataByte( (uint8_t) address);
  _delay_ms(50);
}

void EEPROM_sendByte(const uint8_t data, const uint16_t address)
{
  EEPROM_sendAddress(address);
  TWI_masterWriteDataByte(data);
  TWI_sendStopCondition();
  _delay_ms(50);
}

void EEPROM_readByte(uint8_t * const var, const uint16_t address)
{
  EEPROM_sendAddress(address);
  _delay_ms(50);
  TWI_sendRepeatedStartCondition();
  _delay_ms(50);
  TWI_sendSlaveAddressWithRead( 0b1010000 | (A2_PIN<<2) | (address>>8) );
  _delay_ms(50);
  TWI_masterReadDataByte(var);
  _delay_ms(50);
  TWI_sendStopCondition();
  _delay_ms(50);
}

void EEPROM_sendSequence(uint8_t * const sequence, const uint16_t firstAddress, const uint16_t sequenceSize)
{
  EEPROM_sendAddress(firstAddress);
  for(uint16_t i=0; i<sequenceSize; i++){ 
    TWI_masterWriteDataByte(sequence[i]);
    _delay_ms(50);
  }
 
  TWI_sendStopCondition();
  _delay_ms(50);

}

void EEPROM_readSequence(uint8_t * const sequence, const uint16_t firstAddress, const uint16_t sequenceSize)
{
  EEPROM_sendAddress(firstAddress);
  TWI_sendRepeatedStartCondition();
  TWI_sendSlaveAddressWithRead( 0b1010000 | (A2_PIN<<2) | (firstAddress>>8) );
  for(uint16_t i=0; i<sequenceSize; i++)
    TWI_masterReadDataByte(sequence+i);
 
  TWI_sendStopCondition();
  _delay_ms(50);
}
