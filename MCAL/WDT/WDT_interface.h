 /**
 * @file WDT_interface.h
 * @author Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief The user interface of the `Wathchdog Timer`
 * @version 0.1
 * @copyright Copyright (c) 2022
 */

/** @addtogroup MCAL_drivers
 * @{
 * @addtogroup Watchdog_Timer
 * @{
 */

#ifndef _WDT_INTERFACE_H_
#define _WDT_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"
#define WDTCR           *((volatile uint8_t*) 0x41)      /*Watchdog timer Control and status Register*/
#define WDTCR_WDP0      0                           /*Watchdog Timer Prescaler 0*/
#define WDTCR_WDP1      1                           /*Watchdog Timer Prescaler 1*/
#define WDTCR_WDP2      2                           /*Watchdog Timer Prescaler 2*/
#define WDTCR_WDE       3                           /*Watchdog Enable*/
#define WDTCR_WDTOE     4                           /*Watchdog Turn-off Enable*/

//#define WDT_enable()  {SET_BIT(WDTCR, WDTCR_WDE); SET_BIT(WDTCR, WDTCR_WDTOE);}
 /**
 * @brief Enable the Watchdog timer
 * 
 */
void WDT_enable(void);

 /**
 * @brief 
 * @param prescaler 
 */
void WDT_sleep(uint8_t prescaler);

 /**
 * @brief Disable Watchdog timer
 * @bug There is a problem with disabling the watchdog timer!
 * @todo fix the `WDT_disable()` bug
 */
void WDT_disable(void);

#endif /* _WDT_INTERFACE_H_ */
/*@}@}*/