#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "WDT_interface.h"

void WDT_enable()
{
  SET_BIT(WDTCR, WDTCR_WDE);
}

void WDT_sleep(u8 prescaler)
{
WDTCR &=0b11111000;
WDTCR |=prescaler;
}

//TODO
/*There is a problem with disabling the watchdog timer!*/
void WDT_disable(void)
{
//asm("wdr");
  WDTCR=0b00010000;
  WDTCR =0b00011000;
  WDTCR =0;
}
