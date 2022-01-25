#ifndef _TWI_PRIVATE_H_
#define _TWI_PRIVATE_H_

/* Status Code for Master Transmitter Mode */
#define START                                                     0x08
#define REPEATED_START                                            0x10
#define MASTER_TRANS_SLAVE_ADDRESS_WITH_WRITE_AND_ACK_RECEIVED    0x18
#define MASTER_TRANS_SLAVE_ADDRESS_WITH_WRITE_AND_NACK_RECEIVED   0x20
#define MASTER_TRANS_DATA_AND_ACK_RECEIVED                        0x28
#define MASTER_TRANS_DATA_AND_NACK_RECEIVED                       0x30
//#define 

/* Status Codes for Master Receiver Mode*/
#define MASTER_TRANS_SLAVE_ADDRESS_WITH_READ_AND_ACK_RECEIVED     0x40
#define MASTER_TRANS_SLAVE_ADDRESS_WITH_READ_AND_NACK_RECEIVED    0x48
#define MASTER_RECEIVED_DATA_AND_ACK_SENT                         0x50
#define MASTER_RECEIVED_DATA_AND_NACK_SENT                        0x58

/* #define  */
/* #define  */


#endif /* _TWI_PRIVATE_H_ */
