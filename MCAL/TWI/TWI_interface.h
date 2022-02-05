#ifndef _TWI_INTERFACE_H_
#define _TWI_INTERFACE_H_

#include "TWI_register.h"

typedef enum{
  NoError,
  StartConditionError,
  RepeatedStartError,
  SlaveAddressWithWriteError,
  SlaveAddressWithReadError,
  MasterWriteByteError,
  MasterReadByteError
}TWI_errorStatus;


void TWI_initMaster(void);
void TWI_initSlave(const uint8_t slaveAddress);


TWI_errorStatus TWI_sendStartCondition(void);
TWI_errorStatus TWI_sendRepeatedStartCondition(void);
void TWI_sendStopCondition(void);

TWI_errorStatus TWI_sendSlaveAddressWithWrite(const uint8_t slaveAddress);
TWI_errorStatus TWI_sendSlaveAddressWithRead(const uint8_t slaveAddress);

TWI_errorStatus TWI_masterWrite(const uint8_t data);
TWI_errorStatus TWI_masterRead(uint8_t * const dataLocation, const uint16_t quantity);



#endif /* _TWI_INTERFACE_H_ */
