/**
 *
 * @file       TIMER_private.h
 * @brief      Contains private macros for the Timers
 * @author     Abdulrahman Aboghanima
 * @date       Jan 31 06:02:17 2022
 * @copyright  Copyright (c) 2022
 * @version    0.2
 * 
 */


#ifndef _TIMER_PRIVATE_H_
#define _TIMER_PRIVATE_H_

#define PRESCALER_MASK 0b11111000


#define _VECTOR(N) __vector_ ## N



#define TIMER2_COMP_vect   _VECTOR(4)
#define TIMER2_OVF_vect    _VECTOR(5)
#define TIMER1_CAPT_vect   _VECTOR(6)
#define TIMER1_COMPA_vect  _VECTOR(7)
#define TIMER1_COMPB_vect  _VECTOR(8)
#define TIMER1_OVF_vect    _VECTOR(9)
#define TIMER0_COMP_vect   _VECTOR(10)
#define TIMER0_OVF_vect    _VECTOR(11)


#endif /* _TIMER_PRIVATE_H_ */
