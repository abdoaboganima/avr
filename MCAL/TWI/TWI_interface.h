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
void TWI_initSlave(u8 slaveAddress);


TWI_errorStatus TWI_sendStartCondition(void);
TWI_errorStatus TWI_sendRepeatedStartCondition(void);
void TWI_sendStopCondition(void);

TWI_errorStatus TWI_sendSlaveAddressWithWrite(u8 slaveAddress);
TWI_errorStatus TWI_sendSlaveAddressWithRead(u8 slaveAddress);

TWI_errorStatus TWI_masterWriteDataByte(u8 data);
TWI_errorStatus TWI_masterReadDataByte(u8 *dataLocation);



#endif /* _TWI_INTERFACE_H_ */
