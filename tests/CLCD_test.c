/**
 *
 * @file       CLCD_test.c
 * @brief      Contains some tests format the CLCD
 * @author     Abdulrahman Aboghanima
 * @date       Aug 21 21:37:21 2021
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */

#include "../LIB/STD_TYPES.h"
#include "../HAL/CLCD/CLCD_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#include <util/delay.h>

int main(void){

  const uint8_t customChar[][8] = {
				   {0x00, 0x00, 0x07, 0x14, 0x1F, 0x00, 0x10, 0x00},
				   {0x00, 0x00, 0x04, 0x04, 0x1F, 0x00, 0x00, 0x00},
				   {0x06, 0x06, 0x06, 0x06, 0x1E, 0x00, 0x00, 0x00},
				   {0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x04, 0x08},
				   {0x00, 0x0C, 0x02, 0x01, 0x1F, 0x00, 0x00, 0x00},
				   {0x00, 0x00, 0x0E, 0x0A, 0x1F, 0x00, 0x00, 0x00},
				   {0x00, 0x00, 0x04, 0x11, 0x11, 0x11, 0x0E, 0x00}
  };
  
  CLCD_init();

  for(uint8_t i=0; i<7; i++)
    CLCD_SendSpecialChar(customChar[i], i, 0, 12-i);
  
  CLCD_GoTOXY(1, 6);
  CLCD_SendString(utoa(1234, 10));

  while(1){

    CLCD_Clear();
    CLCD_GoTOXY(0, 0);
    CLCD_SendString("Welcome to Repo");
    _delay_ms(100);
    CLCD_Clear();
    CLCD_GoTOXY(1, 1);
    CLCD_SendString("Welcome to Repo");
    _delay_ms(100);
    
  }

  return 0;

}
