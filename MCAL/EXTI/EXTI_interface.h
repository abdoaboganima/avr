 /**
 * @file EXTI_interface.h
 * @author Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief User interface of the EXTI(External Interrupt)
 * @version 0.1
 * @copyright Copyright (c) 2022
 */
#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"


#define FALLING_EDGE       1
#define RISING_EDGE        2
#define LOW_LEVEL          3
#define ANY_LOGICAL_CHANGE 4


#define INT0               6
#define INT1               7
#define INT2               5

void EXTI_Int0_Init(void);
void EXTI_Int1_Init(void);
void EXTI_Int2_Init(void);



void EXTI_Int0SetCallBack(void (*Int0Func)(void));
void EXTI_Int1SetCallBack(void (*Int1Func)(void));
void EXTI_Int2SetCallBack(void (*Int2Func)(void));


void EXTI_enableInterrupt(uint8_t INT_ID);                      /*ENABLE An external Interrupt by passing its ID*/
void EXTI_disableInterrupt(uint8_t INT_ID);                     /*DISABLE An external Interrupt by passing its ID*/

/*Interrupt Service Routine(ISR) of INTx*/
void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));





//TODO
/*For prebuild configuration*/
void EXTI_Int0SetSenseControl(uint8_t sense);
void EXTI_Int1SetSenseControl(uint8_t sense);
void EXTI_Int2SetSenseControl(uint8_t sense);
//Also Implement peripheral interrupt enable using prebuild configuration

#endif /* _EXTI_INTERFACE_H_ */
