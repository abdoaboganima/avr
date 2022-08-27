/**
 *
 * @file       SERVO_interface.h
 * @brief      Contains functions declarations for the SERVO motor
 * @author     Abdulrahman Aboghanima
 * @date       Tue Aug 23 22:26:39 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */

#ifndef _SERVO_INTERFACE_H_
#define _SERVO_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

typedef enum
  {
   OC1A,
   OC1B
  }SERVO_pin;


/**
 * @brief Initializes the servo motor
 * @param pin to which the servo is connected
 * @return void
 */
extern void SERVO_init(SERVO_pin pin);

/**
 * @brief Sets the angle of the servo from the 0 degree
 * @param pin to which the servo is connected
 * @param angle the angle value must be in the range 0:180
 * @return void
 */
extern void SERVO_angle(SERVO_pin pin, uint8_t angle);

#endif /* _SERVO_INTERFACE_H_ */
