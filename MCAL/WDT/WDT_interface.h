#ifndef _WDT_INTERFACE_H_
#define _WDT_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"
#define WDTCR           *((volatile u8*) 0x41)      /*Watchdog timer Control and status Register*/
#define WDTCR_WDP0      0                           /*Watcdog Timer Prescaler 0*/
#define WDTCR_WDP1      1                           /*Watcdog Timer Prescaler 1*/
#define WDTCR_WDP2      2                           /*Watcdog Timer Prescaler 2*/
#define WDTCR_WDE       3                           /*Watchdog Enable*/
#define WDTCR_WDTOE     4                           /*Watchdog Turn-off Enable*/

//#define WDT_enable()  {SET_BIT(WDTCR, WDTCR_WDE); SET_BIT(WDTCR, WDTCR_WDTOE);}

void WDT_enable(void);
void WDT_sleep(u8 prescaler);
void WDT_disable(void);

#endif /* _WDT_INTERFACE_H_ */
