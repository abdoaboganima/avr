/**
 *
 * @file       GIE_program.c
 * @brief      Contains functions implementations of the `GIE`
 * @author     Abdulrahman Aboghanima
 * @date       Sun Apr 24 17:44:14 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_register.h"

extern void GIE_enable(void)
{
  SET_BIT(SREG, SREG_INTERRUPT_EN);
}

extern void GIE_disable(void)
{  
  CLEAR_BIT(SREG, SREG_INTERRUPT_EN);
}
