/**
 *
 * @file       PORT_interface.h
 * @brief      Contains functions declarations for the `PORT` module
 * @author     Abdulrahman Aboghanima
 * @date       Mon Aug 15 17:06:50 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */

#ifndef _PORT_INTERFACE_H_
#define _PORT_INTERFACE_H_


/**
 * @brief initializes the port with the values defined in the `PORT_config.h`
 * @param void
 * @return void
 * @post The DIO pins will be initialized using pre-build configuration
 */
extern void PORT_init(void);

#endif /* _PORT_INTERFACE_H_ */
