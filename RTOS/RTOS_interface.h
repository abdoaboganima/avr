/**
 *
 * @file       RTOS_interface.h
 * @brief      Contains functions prototypes for the RTOS stack
 * @author     Abdulrahman Aboghanima
 * @date       Sun Apr 24 17:49:17 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */

#ifndef _RTOS_INTERFACE_H_
#define _RTOS_INTERFACE_H_
#include "../LIB/STD_TYPES.h"

void RTOS_start(void);
void RTOS_create_task(uint8_t priority, uint16_t periodicity, void (*taskFunction)(void), uint16_t firstDelay);

void RTOS_suspend_task(uint8_t priority);
void RTOS_resume_task(uint8_t priority);
void RTOS_delete_task(uint8_t priority);
#endif /* _RTOS_INTERFACE_H_ */
