/**
 *
 * @file       EXTI_private.h
 * @brief      Contains private macros for the EXTI, External Interrupt, module
 * @author     Abdulrahman Aboghanima
 * @date       Feb 02 18:09:53 2022
 * @copyright  Copyright (c) 2022
 * @version    0.2
 * 
 */

#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_


#define _VECTOR(N) __vector_ ## N

#define INT0_vect _VECTOR(1)  /* External Interrupt Request 0*/
#define INT1_vect _VECTOR(2)  /* External Interrupt Request 1*/
#define INT2_vect _VECTOR(3)  /* External Interrupt Request 2*/



#endif /* _EXTI_PRIVATE_H_ */
