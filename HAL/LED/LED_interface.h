/**
 *
 * @file       LED_interface.h
 * @brief      Contains functions declarations for the LED module
 * @author     Abdulrahman Aboghanima
 * @date       Tue Aug 16 16:37:21 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */


#ifndef _LED_INTERFACE_H_
#define _LED_INTERFACE_H_
#include"../../LIB/STD_TYPES.h"

/**
 * @brief The possible two states of the led
 */
enum led_state {LED_OFF, LED_ON};

/**
 * @brief A led structure
 */
typedef struct {
  uint8_t led_port;   /**<The port which the led connected to*/
  uint8_t led_pin;    /**<The pin which the led connected to*/
  uint8_t led_state;  /**<The current state of the led*/
} LED_t;

/**
 * @brief Initializes the led
 * @param led 
 */
extern void LED_init(const LED_t *const led);

/**
 * @brief Turns on the led
 * @param led 
 */
extern void LED_turnOn(LED_t *const led);

/**
 * @brief Turns off the led
 * @param led 
 */
extern void LED_turnOff(LED_t *const led);

/**
 * @brief Toggles the led
 * @param led 
 */
extern void LED_toggle(LED_t *const led);



#endif /* _LED_INTERFACE_H_ */
