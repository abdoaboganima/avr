/**
 *
 * @file       TIMER_interface.h
 * @brief      Contains functions declarations for the Timer periheral
 * @author     Abdulrahman Aboghanima
 * @date       Jan 31 09:16:44 2022
 * @copyright  Copyright (c) 2022
 * @version    0.2
 *
 */

#ifndef _TIMER_INTERFACE_H_
#define _TIMER_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"
#include "TIMER_register.h"

/**
 * @brief Modes of Operations for timers
 */
typedef enum
{
  normal,  /**<  Normal mode */
  PWM,     /**<  Pulse Width Modulation*/
  CTC,     /**<  Clear Timer on Compare match*/
  fast_PWM /**<  Fast Pulse Width Modulation*/
} timer_mode;

typedef enum
{
  timer0, /**< Timer 0, An 8-bit Timer*/
  timer1, /**< Timer 1, A  16-bit Timer*/
  timer2  /**< Timer 2, An 8-bit Timer*/
} timer_id;

/**
 * @brief The prescaler of the Clock that triggers the timer
 */
typedef enum
{
  no_clock,       /**< No clock source (Timer/Counter stopped).*/
  divided_by_1,   /**< No prescaling*/
  divided_by_8,   /**< The CPU clock is divided by 8*/
  divided_by_64,  /**< The CPU clock is divided by 64*/
  divided_by_256, /**< The CPU clock is divided by 256*/
  divided_by_1024 /**< The CPU clock is divided by 1024*/
} prescaler;

#define ICU_RISING_EDGE 1
#define ICU_FALLING_EDGE 2

/**
 * @brief Initializes the timer peripheral with specific timer id
 * @param timer The timer id which is timer0, timer1, timer2
 * @param mode The mode of the timer 
 * @param value The prescaler value
 * @see `timer_id`, `timer_mode`, `prescaler`
 */
extern void TIMER_init(const timer_id timer, const timer_mode mode, const prescaler value);

/**
 * @brief Sets the Compare match value for a specific timer
 * @param timer
 * @param value
 * @note Until now this function doesn't set the compare match value for the
 * timer1, instead you have to use either `TIMER1_setChannelAComapareMatchValue()` 
 * or `TIMER1_setChannelBComapareMatchValue()` depending on the application.
 */
extern void TIMER_setCompareMatchValue(const timer_id timer, const uint8_t value);



extern void TIMER_CTC_setOCxOnCompareMatch(const timer_id timer);
extern void TIMER_CTC_clearOCxOnCompareMatch(const timer_id timer);
extern void TIMER_CTC_toggleOCxOnCompareMatch(const timer_id timer);



extern void TIMER1_setChannelAComapareMatchValue(const uint16_t channelACompareMatchValue);
extern void TIMER1_setChannelBComapareMatchValue(const uint16_t channelBCompareMatchValue);
extern void TIMER1_setICR(const uint16_t inputCaptureValue);

/**
 * @brief Sets a value for a timer 
 * @param timer 
 * @param timerValue 
 */
extern void TIMER_setTimerValue(const timer_id timer, const uint16_t timerValue);

/**
 * @brief Handles the ISR, Interrupt Service Routine, for the three timers in the normal modes
 * by passing a callback function to be executed in the ISR
 * @param timer 
 * @param callBackFunc 
 * @note Make sure that the function you pass is small as possible.
 */
extern void TIMER_normalModeOverflowSetCallBack(const timer_id timer, void (*callBackFunc)(void));

extern void ICU_init(void);
extern void ICU_setTriggerEdge(const uint8_t edge);
extern void ICU_setCallBack(void (*callBackFunc)(void));

extern uint16_t ICU_readInputCapture(void);

#endif /* _TIMER_INTERFACE_H_ */
