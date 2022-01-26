#include "EEPROM_interface.h"
#include "../../MCAL/TWI/TWI_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include <util/delay.h>
void EEPROM_sendByte(u8 data, u16 address)
{
  TWI_sendStartCondition();
  _delay_ms(50);
  TWI_sendSlaveAddressWithWrite( 0b1010000 | (address>>8) );
  _delay_ms(50);
  TWI_masterWriteDataByte( (u8) address);
  _delay_ms(50);
  TWI_masterWriteDataByte(data);
  _delay_ms(50);
  TWI_sendStopCondition();
  _delay_ms(50);
  
}

void EEPROM_readByte(u8 *var, u16 address)
{
  TWI_sendStartCondition();
  _delay_ms(50);
  TWI_sendSlaveAddressWithWrite( 0b1010000 | (address>>8) );
  _delay_ms(50);
  TWI_masterWriteDataByte((u8)address);
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
