/**
 *
 * @file       EXTI_register.h
 * @brief      Register Definition file for the `EXTI` 
 * @author     Abdulrahman Aboghanima
 * @date       Feb 02 23:07:51 2022
 * @copyright  Copyright (c) 2022
 * @version    0.2
 * 
 */

#ifndef _EXTI_REGISTER_H_
#define _EXTI_REGISTER_H_


#define HW_REG8(REG)    *((volatile uint8_t*) REG)



/*General Interrupt Control Register*/
#define GICR        HW_REG8(0x5B)

#define GICR_INT1   7
#define GICR_INT0   6
#define GICR_INT2   5


/* General Interrupt Flag Register*/
#define GIFR         HW_REG8(0x5A)


/*MCU Control Register*/
#define MCUCR        HW_REG8(0x55)
#define MCUCR_ISC11  3
#define MCUCR_ISC10  2
#define MCUCR_ISC01  1
#define MCUCR_ISC00  0



/*MCU Control and Status Register*/
#define MCUCSR       HW_REG8(0x54)
#define MCUCSR_ISC2  6


#endif /* _EXTI_REGISTER_H_ */
