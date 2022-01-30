#include "EEPROM_interface.h"
#include "../../MCAL/TWI/TWI_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include <util/delay.h>
void EEPROM_sendByte(uint8_t data, uint16_t address)
{
  TWI_sendStartCondition();
  _delay_ms(50);
  TWI_sendSlaveAddressWithWrite( 0b1010000 | (address>>8) );
  _delay_ms(50);
  TWI_masterWriteDataByte( (uint8_t) address);
  _delay_ms(50);
  TWI_masterWriteDataByte(data);
  _delay_ms(50);
  TWI_sendStopCondition();
  _delay_ms(50);
  
}

void EEPROM_readByte(uint8_t *var, uint16_t address)
{
  TWI_sendStartCondition();
  _delay_ms(50);
  TWI_sendSlaveAddressWithWrite( 0b1010000 | (address>>8) );
  _delay_ms(50);
  TWI_masterWriteDataByte((uint8_t)address);
  _delay_ms(50);
  TWI_sendRepeatedStartCondition();
  _delay_ms(50);
  TWI_sendSlaveAddressWithRead( 0b1010000 | (address>>8) );
  _delay_ms(50);
  TWI_masterReadDataByte(var);
  _delay_ms(50);
  TWI_sendStopCondition();
  _delay_ms(50);
  
}
