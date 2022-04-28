/**
 *
 * @file       RTOS_program.c
 * @brief      Contains function implementation of the `RTOS` stack
 * @author     Abdulrahman Aboghanima
 * @date       Sun Apr 24 18:02:39 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */


#include "../MCAL/Timers/TIMER_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../LIB/STD_TYPES.h"
#include "RTOS_config.h"
#include "RTOS_interface.h"
#include "RTOS_private.h"

Task_t system_tasks[TASK_NUM]={{NULL}};			  
			  
void RTOS_start(void)
{
  TIMER0_setCallBack(&scheduler);  /*Assigning a function to be called in the ISR of the TIMER0*/
  GIE_enable();                    /*Enable Global Interrupt*/
  TIMER0_init();                   /*Initialize TIMER0*/
  TIMER0_setCompareMatchValue(125);/**/
}


void RTOS_create_task(uint8_t priority, uint16_t periodicity, void (*taskFunction)(void), uint16_t firstDelay)
{
  /*Initialization of the periodicity of the task*/
  system_tasks[priority].periodicity=periodicity;

  /*Initialization of the defined function of the task*/
  system_tasks[priority].taskFunc=taskFunction;

  /*Initialization of the state of the task*/
  system_tasks[priority].state=TASK_RESUMED;

  /*Initialization of the first delay of a task*/
  system_tasks[priority].firstDelay=firstDelay;
}



void RTOS_suspend_task(uint8_t priority)
{
  system_tasks[priority].state=TASK_SUSPENDED;
}
void RTOS_resume_task(uint8_t priority)
{
  system_tasks[priority].state=TASK_RESUMED;
}
void RTOS_delete_task(uint8_t priority)
{
  system_tasks[priority].taskFunc=NULL;
}

void scheduler(void)
{
  static uint16_t tick_counter=0;
  tick_counter++;
  
  for (uint8_t task_counter=0; task_counter < TASK_NUM; ++task_counter){

    if (system_tasks[task_counter].state==TASK_RESUMED){
      
      if( ( tick_counter % system_tasks[task_counter].periodicity )== 0)
	system_tasks[tick_counter].taskFunc(); //Invoke the task function

      else  { /*Do nothing*/ }
    }
    
    else{ /*Task is suspended, do nothing*/}
  }
}
