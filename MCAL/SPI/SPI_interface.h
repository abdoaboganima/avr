#ifndef _SPI_INTERFACE_H_
#define _SPI_INTERFACE_H_

#include "SPI_register.h"
#include "../../LIB/STD_TYPES.h"

#include "../../LIB/BIT_MATH.h"

void SPI_initMaster(void);
void SPI_initSlave(void);
u8 SPI_transceive(u8 data);

#endif /* _SPI_INTERFACE_H_ */
