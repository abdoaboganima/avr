#include "TWI_interface.h"
#include "TWI_register.h"
#include "TWI_config.h"
#include "TWI_private.h"
#include "../../LIB/BIT_MATH.h"

#define STATE (TWSR&0xF8)

void TWI_initMaster(void)
{
  /*We need to:
       1- set clock frequency to be 400kbps, So TWBR=2 and TWBS=0
       2- assign the 7 MSB of TWAR to have the slave address
       3- enable the TWI
  */
  /*Set the Clock Frequency*/
  TWBR=0x47;
  TWSR=(0<<TWSR_TWPS0)|(0<<TWSR_TWPS1);
  TWCR=(1<<TWCR_TWEN);
}
void TWI_initSlave(uint8_t slaveAddress)
{
  TWAR=slaveAddress<<1;     /*Assigning an address to a slave*/
  SET_BIT(TWCR, TWCR_TWEN); /*Enable the TWI on the slave*/
}


TWI_errorStatus TWI_sendStartCondition(void)
{
  /*Send start condition on the bus*/
  TWCR=(1<<TWCR_TWINT)|(1<<TWCR_TWEN)|(1<<TWCR_TWSTA);
  /*wait until the operation is finished*/
  while (GET_BIT(TWCR, TWCR_TWINT)==0);
  
  if(STATE!=START) return StartConditionError;

  return NoError;
}
void TWI_sendStopCondition(void)
{
  //Note that TWINT is NOT set after a STOP condition has been sent.
  TWCR = (1<<TWCR_TWINT)|(1<<TWCR_TWEN)|(1<<TWCR_TWSTO);            
}
TWI_errorStatus TWI_sendRepeatedStartCondition(void)
{
  /*Send start condition on the bus*/
  TWCR=(1<<TWCR_TWINT)|(1<<TWCR_TWEN)|(1<<TWCR_TWSTA);
  /*wait until the operation is finished*/
  while (GET_BIT(TWCR, TWCR_TWINT)==0);

  if(STATE!=REPEATED_START)  return RepeatedStartError;

  return NoError;
}

TWI_errorStatus TWI_sendSlaveAddressWithWrite(const uint8_t slaveAddress)
{
  /*Set the slave address with the 7 MSB in the data register*/
  TWDR= (slaveAddress<<1); /*The masking is made to make the first bit 0 for write request*/
  
  TWCR=(1<<TWCR_TWINT)|(1<<TWCR_TWEN);
  while (GET_BIT(TWCR, TWCR_TWINT)==0);  /*wait until the operation is finished*/
  
  if( STATE!=MASTER_TRANS_SLAVE_ADDRESS_WITH_WRITE_AND_ACK_RECEIVED)
    return SlaveAddressWithWriteError;
  
  return NoError;  
}

TWI_errorStatus TWI_sendSlaveAddressWithRead(const uint8_t slaveAddress)
{
  /*Set the slave address with the 7 MSB in the data register*/
  TWDR= (slaveAddress<<1)|1; /*The masking is made to make the first bit 1 for read request*/
  
  TWCR=(1<<TWCR_TWINT)|(1<<TWCR_TWEN);
  while (GET_BIT(TWCR, TWCR_TWINT)==0);
  
  if( STATE!=MASTER_TRANS_SLAVE_ADDRESS_WITH_READ_AND_ACK_RECEIVED)
    return SlaveAddressWithWriteError;
  
  return NoError;
  
}

TWI_errorStatus TWI_masterWrite(const uint8_t data)
{
  TWDR=data;
  TWCR=(1<<TWCR_TWEN)|(1<<TWCR_TWINT);
  while (GET_BIT(TWCR, TWCR_TWINT)==0);  /*wait until the operation is finished*/
  if(STATE!=MASTER_TRANS_DATA_AND_ACK_RECEIVED)  return MasterWriteByteError;

  return NoError;
}
TWI_errorStatus TWI_masterRead(uint8_t * const dataLocation, const uint16_t quantity)
{
  if(quantity==1)
    TWCR=(1<<TWCR_TWINT)|(1<<TWCR_TWEN);
  else
    TWCR=(1<<TWCR_TWINT)|(1<<TWCR_TWEN)|(1<<TWCR_TWEA);;

  while (GET_BIT(TWCR, TWCR_TWINT)==0);   
 
  if(STATE!=MASTER_RECEIVED_DATA_AND_ACK_SENT)  return MasterReadByteError;

  *dataLocation=TWDR;
  
  return NoError;
}

