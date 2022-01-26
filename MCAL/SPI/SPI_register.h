 /**
 * @file SPI_register.h
 * @author Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief The IO and regisers memory mapped addresses
 * @version 0.1
 * @copyright Copyright (c) 2022
 */
#ifndef _SPI_REGISTER_H_
#define _SPI_REGISTER_H_


#define SPDR     *((volatile u8*) 0x2f )
#define SPSR     *((volatile u8*) 0x2e )

#define SPSR_SPIF    7           /* SPI Interrupt Flag */
#define SPSR_WCOL    6           /* Write COLlision Flag */
#define SPSRSPI2X    0           /* Double SPI Speed Bit */


#define SPCR     *((volatile u8*) 0x2d )

#define SPCR_SPIE    7           /* SPI Interrupt Enable */
#define SPCR_SPE     6           /* SPI Enable */
#define SPCR_DORD    5           /* Data Order. If it's set, the LSB of the data word is transmitted first. 
				    If it's zero, the MSB of the data word is transmitted first */
#define SPCR_MSTR    4           /* Master/Slave Select */
#define SPCR_CPOL    3           /* Clock Polarity */
#define SPCR_CPHA    2           /* Clock Phase */
#define SPCR_SPR1    1           /* SPI clock select bit 1 */
#define SPCR_SPR0    0           /* SPI clock select bit 0 */



#endif /* _SPI_REGISTER_H_ */
