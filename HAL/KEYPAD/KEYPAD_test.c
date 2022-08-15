/**
 *
 * @file       KEYPAD_test.c
 * @brief      Contains some tests for the KEYPAD module
 * @author     Abdulrahman Aboghanima
 * @date       Mon Aug 15 22:44:41 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */

#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"
#include "../CLCD/CLCD_interface.h"


int main()
{
  
  CLCD_init();
  KEYPAD_init();

  while(1){

    uint8_t data=KEYPAD_getPressedKey();
    if(data!=NO_KEY_PRESSED)
      CLCD_SendData(data);
  }
  
  return 0;
}
