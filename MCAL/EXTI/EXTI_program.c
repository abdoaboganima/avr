/**
 *
 * @file       EXTI_program.c
 * @brief      Contains functions definitions for the EXTI module
 * @author     Abdulrahman Aboghanima
 * @date       Feb 02 19:43:38 2022
 * @copyright  Copyright (c) 2022
 * @version    0.2
 * @compiler   avr-gcc
 */


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "EXTI_register.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"


/*Global pointer to function*/
void (*EXTI_Int0Func)(void)=NULL;
void (*EXTI_Int1Func)(void)=NULL;
void (*EXTI_Int2Func)(void)=NULL;



void EXTI_Int0_init(void)
{
  /* Set ISC(interrupt sense control) */
#if (INT0_ISC==FALLING_EDGE)
  SET_BIT(MCUCR, MCUCR_ISC01);
  CLEAR_BIT(MCUCR, MCUCR_ISC00);    
#elif (INT0_ISC==RISING_EDGE)
  SET_BIT(MCUCR, MCUCR_ISC00);
  SET_BIT(MCUCR, MCUCR_ISC01);
#elif (INT0_ISC==LOW_LEVEL)
  CLEAR_BIT(MCUCR, MCUCR_ISC00);
  CLEAR_BIT(MCUCR, MCUCR_ISC01);
#elif (INT0_ISC==ANY_LOGICAL_CHANGE)
  SET_BIT(MCUCR, MCUCR_ISC00);
  CLEAR_BIT(MCUCR, MCUCR_ISC01);    
#else
  #error "Wrong Interrupt Sense Control option"
#endif

  

  /*Pre-build configuration: Peripheral interrupt enable for INT0*/
#if INT0_INITIAL_STATE==ENABLED
  SET_BIT(GICR, GICR_INT0);
#elif INT0_INITIAL_STATE==DISABLED
  CLEAR_BIT(GICR, GICR_INT0);
#else
#error "Wrong INT0_INITIAL_STATE option"
#endif
  
}



void EXTI_Int1_init(void)
{
    /* Set ISC(interrupt sense control) */
#if (INT1_ISC==FALLING_EDGE)
  SET_BIT(MCUCR, MCUCR_ISC11);
  CLEAR_BIT(MCUCR, MCUCR_ISC10);    

#elif (INT1_ISC==RISING_EDGE)
  SET_BIT(MCUCR, MCUCR_ISC11);
  SET_BIT(MCUCR, MCUCR_ISC10);

#elif (INT1_ISC==LOW_LEVEL)
  CLEAR_BIT(MCUCR, MCUCR_ISC11);
  CLEAR_BIT(MCUCR, MCUCR_ISC10);

#elif (INT1_ISC==ANY_LOGICAL_CHANGE)
  SET_BIT(MCUCR, MCUCR_ISC10);
  CLEAR_BIT(MCUCR, MCUCR_ISC11);    

#else
  #error "Wrong Interrupt Sense Control option"
#endif

 

  /*Pre-build configuration: Peripheral interrupt enable for INT1*/
#if INT1_INITIAL_STATE==ENABLED
  SET_BIT(GICR, GICR_INT1);
#elif INT1_INITIAL_STATE==DISABLED
  CLEAR_BIT(GICR, GICR_INT1);
#else
#error "Wrong INT1_INITIAL_STATE option"
#endif
  
}


void EXTI_Int2_init(void)
{
  /* Set ISC(interrupt sense control) */
#if (INT2_ISC==FALLING_EDGE)
  CLEAR_BIT(MCUCSR, MCUCSR_ISC2);
#elif (INT2_ISC==RISING_EDGE)
  SET_BIT(MCUCSR, MCUCSR_ISC2);
#else
  #error "Wrong Interrupt Sense Control option"
#endif


  /*Pre-build configuration: Peripheral interrupt enable for INT2*/
#if INT2_INITIAL_STATE==ENABLED
  SET_BIT(GICR, GICR_INT2);
#elif INT2_INITIAL_STATE==DISABLED
  CLEAR_BIT(GICR, GICR_INT2);
#else
#error "Wrong INT2_INITIAL_STATE option"
#endif
  
}


void EXTI_Int0SetCallBack(void (*Int0Func)(void))
{
  EXTI_Int0Func=Int0Func;
}

void EXTI_Int1SetCallBack(void (*Int1Func)(void))
{
  EXTI_Int1Func=Int1Func;
}

void EXTI_Int2SetCallBack(void (*Int2Func)(void))
{
  EXTI_Int2Func=Int2Func;
}



/*Interrupt Service Routine(ISR) of INTx*/

void INT0_vect(void) __attribute__((signal));
void INT0_vect(void)
{
  EXTI_Int0Func();
}

void INT1_vect(void) __attribute__((signal));
void INT1_vect(void)
{
  EXTI_Int1Func();
}

void INT2_vect(void) __attribute__((signal));
void INT2_vect(void)
{
  EXTI_Int2Func();
}



/*For post-build configuration*/
void EXTI_Int0SetSenseControl(const uint8_t sense)
{
  switch(sense){

  case FALLING_EDGE:
    SET_BIT(MCUCR, MCUCR_ISC01);
    CLEAR_BIT(MCUCR, MCUCR_ISC00);
    break;

  case RISING_EDGE:
    SET_BIT(MCUCR, MCUCR_ISC00);
    SET_BIT(MCUCR, MCUCR_ISC01);
    break;

  case LOW_LEVEL:
    CLEAR_BIT(MCUCR, MCUCR_ISC00);
    CLEAR_BIT(MCUCR, MCUCR_ISC01);
    break;

  case ANY_LOGICAL_CHANGE:
    SET_BIT(MCUCR, MCUCR_ISC00);
    CLEAR_BIT(MCUCR, MCUCR_ISC01);
    break;
    
  default: break;


  }
  
}
