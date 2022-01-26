 /**
 * @file EXTI_config.h
 * @author Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief User pre-build configuration for the `EXTI` (external interrupt)
 * @version 0.1
 * @copyright Copyright (c) 2022
 * @todo How on earth there is expansion for the macros below however I don't include anything
 */
#ifndef _EXTI_CONFIG_H_
#define _EXTI_CONFIG_H_

/*INT0 Interrupt Sense Control*/
/*
  Options:
         1- FALLING_EDGE      
         2- RISING_EDGE       
         3- LOW_LEVEL         
         4- ANY_LOGICAL_CHANGE   
*/
#define INT0_ISC RISING_EDGE


/*Peripheral interrupt enable*/
/*
  Options:
         1- Enabled
	 2- Disabled
*/
#define INT0_INITIAL_STATE ENABLED


#endif /* _EXTI_CONFIG_H_ */
