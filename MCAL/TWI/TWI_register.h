#ifndef _TWI_REGISTER_H_
#define _TWI_REGISTER_H_
#include "../../LIB/STD_TYPES.h"

#define TWBR  *((volatile u8*) 0x20)  /*TWI Bit Rate Register*/

#define TWCR  *((volatile u8*) 0x56)  /*TWI Control Register*/

#define TWCR_TWIE   0                 /* TWI Interrupt Enable */
#define TWCR_TWEN   2                 /* TWI Enable  */
#define TWCR_TWWC   3                 /* TWI Write Collision Flag */
#define TWCR_TWSTO  4                 /* TWI Stop Condition */
#define TWCR_TWSTA  5                 /* TWI Start Condition */
#define TWCR_TWEA   6                 /* TWI Enable Acknowledge */
#define TWCR_TWINT  7                 /* TWI Interrupt Flag */

#define TWSR  *((volatile u8*) 0x21)  /*TWI Status Register*/
#define TWSR_TWPS0   0
#define TWSR_TWPS1   1

#define TWDR  *((volatile u8*) 0x23)  /*TWI Data Register*/

#define TWAR  *((volatile u8*) 0x22)  /*TWI (slave) Address Register*/
#define TWAR_TWGCE 0

#endif /* _TWI_REGISTER_H_ */
