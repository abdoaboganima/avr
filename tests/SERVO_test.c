/**
 *
 * @file       SERVO_test.c
 * @brief      Contains test for the SERVO Motor
 * @author     Abdulrahman Aboghanima
 * @date       Tue Aug 23 22:57:28 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */

#include "../HAL/SERVO/SERVO_interface.h"
#include <util/delay.h>

int main()
{
  /*Initialization of the servo motor*/
  SERVO_init(OC1A);

  
  while(1){
    SERVO_angle(OC1A, 0);
    _delay_ms(1000);

    SERVO_angle(OC1A, 45);
    _delay_ms(1000);

    SERVO_angle(OC1A, 90);
    _delay_ms(1000);
  
    SERVO_angle(OC1A, 180);
    _delay_ms(1000);
  }


  return 0;
}
