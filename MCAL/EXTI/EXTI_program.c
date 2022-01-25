#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "EXTI_interface.h"
#include "EXTI_register.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

void EXTI_Int0_Init(void)
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


  /* Peripheral interrupt enable for INT0*/
#if INT0_INITIAL_STATE==ENABLED
  SET_BIT(GICR, GICR_INT0);
#elif
  CLEAR_BIT(GICR, GICR_INT0);
#else
#error "Wrong INT0_INITIAL_STATE option"
#endif
}


void EXTI_Int1_Init(void)
{
  
}
void EXTI_Int2_Init(void)
{
  
}

void EXTI_disableInterrupt(u8 INT_ID)
{
  CLEAR_BIT(GICR, INT_ID);
}


void EXTI_enableInterrupt(u8 INT_ID)
{
  SET_BIT(GICR, INT_ID);
}


/*Global pointer to function*/
void (*EXTI_Int0Func)(void)=NULL;
void (*EXTI_Int1Func)(void)=NULL;
void (*EXTI_Int2Func)(void)=NULL;



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


void __vector_1(void)
{
  EXTI_Int0Func();
}

void __vector_2(void)
{
  EXTI_Int1Func();
}

void __vector_3(void)
{
  EXTI_Int2Func();
}



/*For prebuild configuration*/
void EXTI_Int0SetSenseControl(u8 sense)
{
  switch(sense){

  case FALLING_EDGE: SET_BIT(MCUCR, MCUCR_ISC01); CLEAR_BIT(MCUCR, MCUCR_ISC00); break;
  case RISING_EDGE:  SET_BIT(MCUCR, MCUCR_ISC00); SET_BIT(MCUCR, MCUCR_ISC01); break;
  case LOW_LEVEL:    CLEAR_BIT(MCUCR, MCUCR_ISC00); CLEAR_BIT(MCUCR, MCUCR_ISC01); break;
  case ANY_LOGICAL_CHANGE: SET_BIT(MCUCR, MCUCR_ISC00); CLEAR_BIT(MCUCR, MCUCR_ISC01);break;
  default:
    break;
  }
 
}
