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
 */
void USART_init(void);

 /**
 * @brief Receive data
 * @return uint8_t 
 */
uint8_t USART_receive(void);

 /**
 * @brief Send `data`
 * @param data 
 */
void USART_send(const uint8_t data);

 /**
 * @brief Receive data and execute the interrupt service routine associated with
 * the complete receive.
 * @param receiveCompleteCallBack 
 * @note `receiveCompleteCallBack` is a pointer to function that will be 
 * executed in the receive complete data ISR
 * @return uint8_t 
 */
uint8_t USART_receiveWithInterruptDriven(void (*receiveCompleteCallBack)(void));

 /**
 * @brief Send data and execute the interrupt service routine associated with
 * the complete receive
 * @note `transmissionCompleteCallBack` is a pointer to function that will be 
 * executed in the transmission complete data ISR
 * @param data 
 * @param transmissionCompleteCallBack 
 */
void USART_sendWithInterruptDriven(const uint8_t data, void (*transmissionCompleteCallBack)(void));


 /**
 * @brief Send stream of data
 * @param stream 
 */
void USART_sendStream(const char *stream);

 /**
 * @brief Diasbling the Receiver
 */
void USART_disableReceiver(void);

void __vector_13(void) __attribute__((signal));
void __vector_15(void) __attribute__((signal));


#endif /* _USART_INTERFACE_H_ */

/*@}@}*/
