/**
 *
 * @file       GIE_register.h
 * @brief      Register definition file of the `GIE` module.
 * @author     Abdulrahman Aboghanima
 * @date       Sun Apr 24 17:44:48 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */

#ifndef _GIE_REGISTER_H_
#define _GIE_REGISTER_H_

#define SREG *((volatile uint8_t*) 0x5f)
#define SREG_INTERRUPT_EN 7
#endif /* _GIE_REGISTER_H_ */
