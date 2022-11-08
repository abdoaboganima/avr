 /**
 * @file EEPROM_program.c
 * @author Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief  Contains functions declaration for the EEPROM module 
 * @version 0.2
 * @date 2022-02-03
 * @todo Fix or remove the delays. Include the in the I2C driver
 * @copyright Copyright (c) 2022
 */
#include "EEPROM_interface.h"
#include "EEPROM_config.h"
#include "../../MCAL/TWI/TWI_interface.h"
#include "../../LIB/STD_TYPES.h"
#include <util/delay.h>

#define EEPROM_ADDRESS ( 0b1010000 | (A2_PIN<<2) )

/*
Suppose you would like to access memory which address is : X9X8X7X6X5X4X3X2X1X0
So in order to access that location you have to through the following address in the I^{2}C Bus
|---+---+---+---+----+----+----|
| 1 | 0 | 1 | 0 | A2 | X9 | X8 |
|---+---+---+---+----+----+----|

*/

/*The address of the `AT24C08A` consists of 3 pats
      1- 1010 Selects the `AT24C08A`
      2- A2 select which `AT24C08A` you will communicate with, you can connect up to two
      3  The two LSB selects the block number in the memory 
  */


extern void EEPROM_writeByte(const uint8_t data, const uint16_t address)
{

  /*Slave address (1 0 1 0 [A2] [X9] [X8]) where X9X8 is the num of block*/
  uint8_t device_address= EEPROM_ADDRESS | (address>>8);
  /*The address of the byte in the block(block consists of 256 bytes)*/
  uint8_t data_location = (uint8_t) address;

  TWI_write_byte(device_address, data_location, data);
}

extern void EEPROM_readByte(uint8_t * const var, const uint16_t address)
{
  /*Slave address (1 0 1 0 [A2] [X9] [X8]) where X9X8 is the num of block*/
  uint8_t device_address= EEPROM_ADDRESS | (address>>8);
  /*The address of the byte in the block(block consists of 256 bytes)*/
  uint8_t data_location = (uint8_t) address;

  *var=TWI_read_byte(device_address, data_location);
}

extern void EEPROM_writePage(const uint8_t * const sequence, const uint16_t firstAddress, const uint8_t pageSize)
{
  TWI_sendStartCondition();
  /*Send slave address (which consists also of the number of block)*/
  TWI_sendSlaveAddressWithWrite(EEPROM_ADDRESS | (firstAddress>>8));
  /*Send the address of the byte in the block (block consists of 256 bytes)*/
  TWI_masterWrite((uint8_t)firstAddress);
  for(uint8_t i=0; i<pageSize; i++){
    TWI_masterWrite(sequence[i]);
  }
  TWI_sendStopCondition();
}

extern void EEPROM_readSequence(uint8_t * const sequence, const uint16_t firstAddress, const uint16_t sequenceSize)
{
  TWI_sendStartCondition();
  TWI_sendSlaveAddressWithWrite(( EEPROM_ADDRESS  | (firstAddress>>8) ));
  TWI_masterWrite( (uint8_t) firstAddress);
  TWI_sendRepeatedStartCondition();
  TWI_sendSlaveAddressWithRead( EEPROM_ADDRESS | (firstAddress>>8) );
  for(uint16_t i=0; i<sequenceSize; i++){
    TWI_masterRead(sequence+i, sequenceSize-i);
  }
 
  TWI_sendStopCondition();
}
