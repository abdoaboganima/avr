 /**
 * @file WDT_program.c
 * @author Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief The implementations of the `Wathchdog Timer`'s function
 * @version 0.1
 * @copyright Copyright (c) 2022
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "WDT_interface.h"

void WDT_enable()
{
  SET_BIT(WDTCR, WDTCR_WDE);
}

void WDT_sleep(uint8_t prescaler)
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
