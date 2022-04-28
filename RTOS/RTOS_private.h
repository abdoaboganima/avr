/**
 *
 * @file       RTOS_private.h
 * @brief      Contains private functions for the RTOS stack driver
 * @author     Abdulrahman Aboghanima
 * @date       Sun Apr 24 17:53:01 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */

#ifndef _RTOS_PRIVATE_H_
#define _RTOS_PRIVATE_H_
#include "../LIB/STD_TYPES.h"



#define TASK_RESUMED     0
#define TASK_SUSPENDED   1



typedef struct
{
  uint16_t periodicity;
  void (*taskFunc)(void);
  uint8_t state;
  uint8_t firstDelay;
} Task_t;


/**
 * @brief This function is executed at every system tick,
 * and checks for every task's periodicity.
 * If a task has completed its periodicity,
 * then the task will be executed immediately.
 * @param None
 * @return None
 * @note This function is called at every system tick!
 */
void scheduler(void);

#endif /* _RTOS_PRIVATE_H_ */
