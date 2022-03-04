/**
 * @file USART_interface.h
 * @author Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief  The user interface of the USART 
 * @version 0.3
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
#include <stdio.h>


/**
 * @brief   Clears the Entire Terminal Screen  
 * @return  None
 * @note    This function clears the entire screen by sending two escape sequences
 */
#define USART_clear_screen() USART_sendStream("\033[H\033[J")



 /**
 * @brief Initialize the USART peripheral
 * @note  This function clear the entire terminal screen
 */
extern void USART_init(void);

 /**
 * @brief Receive data
 * @return uint8_t 
 */
extern uint8_t USART_receive(void);

 /**
 * @brief Send `data`
 * @param data 
 */
extern void USART_send(const uint8_t data);

 /**
 * @brief Receive data and execute the interrupt service routine associated with
 * the complete receive.
 * @param receiveCompleteCallBack 
 * @note `receiveCompleteCallBack` is a pointer to function that will be 
 * executed in the receive complete data ISR
 * @return uint8_t 
 */
extern uint8_t USART_receiveWithInterruptDriven(void (*receiveCompleteCallBack)(void));

 /**
 * @brief Send data and execute the interrupt service routine associated with
 * the complete receive
 * @note `transmissionCompleteCallBack` is a pointer to function that will be 
 * executed in the transmission complete data ISR
 * @param data 
 * @param transmissionCompleteCallBack 
 */
extern void USART_sendWithInterruptDriven(const uint8_t data, void (*transmissionCompleteCallBack)(void));


 /**
 * @brief Send stream of data
 * @param stream 
 */
extern void USART_sendStream(const char *stream);

 /**
 * @brief Disabling the Receiver
 */
extern void USART_disableReceiver(void);

/**
 * @brief  Redirecting the USART stream to the `stdout`
 * @return None
 * @note   After invoking this function you can use `printf()` safely.
 */
extern void USART_redirect_stream_to_stdout(void);


#endif /* _USART_INTERFACE_H_ */

/*@}@}*/
