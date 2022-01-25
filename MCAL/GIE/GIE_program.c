#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_register.h"

void GIE_enable(void)
{
  SET_BIT(SREG, SREG_INTERRUPT_EN);
}
void GIE_disable(void)
{
  
  CLEAR_BIT(SREG, SREG_INTERRUPT_EN);
}
