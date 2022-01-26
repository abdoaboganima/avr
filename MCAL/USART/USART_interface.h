 /**
 * @file USART_interface.h
 * @author Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief  The user interface of the USART 
 * @version 0.1
 * @copyright Copyright (c) 2022
 */
/** @addtogroup MCAL_drivers
 * @{
 * @addtogroup USART_driver
 * @{
 */
#ifndef _USART_INTERFACE_H_
#define _USART_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"



 /**
 * @brief Initialize the USART peripheral
 * 
 */
void USART_init(void);

 /**
 * @brief Receive data
 * 
 * @return u8 
 */
u8 USART_receive(void);

 /**
 * @brief Send `data`
 * 
 * @param data 
 */
void USART_send(u8 data);

 /**
 * @brief Send stream of data
 * 
 * @param stream 
 */
void USART_sendStream(char *stream);

#endif /* _USART_INTERFACE_H_ */

/*@}@}*/