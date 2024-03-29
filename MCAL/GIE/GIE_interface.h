 /**
 * @file GIE_interface.h
 * @author Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief Contains functions declarations for the GIE(Global Interrupt Enable)
 * @version 0.1
 * @copyright Copyright (c) 2022
 * 
 */
/** @addtogroup MCAL_drivers
 * @{
 * @addtogroup GlobalInterrupt
 * @{
 */
#ifndef _GIE_INTERFACE_H_
#define _GIE_INTERFACE_H_

/**
 * @brief Enable Global Interrupt 
 */
extern void GIE_enable(void);

/**
 * @brief Disable Global Interrupt
 */
extern void GIE_disable(void);

#endif /* _GIE_INTERFACE_H_ */
/*@}@}*/
