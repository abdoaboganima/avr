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

/*INTx Interrupt Sense Control*/
/*
  Options:
         1- FALLING_EDGE      
         2- RISING_EDGE       
         3- LOW_LEVEL         
         4- ANY_LOGICAL_CHANGE   
*/
#define INT0_ISC RISING_EDGE
#define INT1_ISC LOW_LEVEL
#define INT2_ISC FALLING_EDGE


/*Peripheral Interrupt Enable*/
/*
  Options:
         1- ENABLED
	 2- DISABLED
*/
#define INT0_INITIAL_STATE ENABLED
#define INT1_INITIAL_STATE ENABLED
#define INT2_INITIAL_STATE ENABLED


#endif /* _EXTI_CONFIG_H_ */
