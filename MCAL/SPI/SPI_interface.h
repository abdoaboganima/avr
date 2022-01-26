 /**
 * @file SPI_interface.h
 * @author Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief User interface of the SPI_driver
 * @version 0.1
 * @copyright Copyright (c) 2022
 */

/** @addtogroup MCAL_drivers
 * @{
 * @addtogroup SPI_driver
 * @{
 */

#ifndef _SPI_INTERFACE_H_
#define _SPI_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"

/** @addtogroup SPI_initialization
 * @{*/

 /** @addtogroup SPI_master_initialization
 * @brief Master initialization of the SPI
 * @{*/
void SPI_initMaster(void);
/*@}*/
 
 
 /** @addtogroup SPI_salve_initialization
 * @brief Slave initialization of the SPI
 * @{
 */
void SPI_initSlave(void);
/*@}*/
 /**
 * @brief Send or receive `data`
 * @param data 
 * @return u8 
 */
u8 SPI_transceive(u8 data);

#endif /* _SPI_INTERFACE_H_ */
/*@}@}*/