/**
 *
 * @file       NOKIA5110_test.c
 * @brief      Contains some tests for the `NOKIA5110` module
 * @author     Abdulrahman Aboghanima
 * @date       Sun Aug 14 06:45:43 2022
 * @copyright  Copyright (c) 2022
 * @version    0.2
 * 
 */

#include "NOKIA5110_interface.h"
#include "util/delay.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


int main()
{
  /*Initialization*/
  NOKIA5110_init();

  /*Setting all bits of address(0, 0)*/
  NOKIA5110_sendData(0b11111111);

  /*Going to address(10, 1)*/
  NOKIA5110_setXY(10,1);

  /*Sending Data*/
  NOKIA5110_sendData(0b11111111);
  NOKIA5110_sendData(0b01010101);
  NOKIA5110_sendData(0b10101010);
  NOKIA5110_sendData(0b01010101);
  NOKIA5110_sendData(0b10101010);
  NOKIA5110_sendData(0b01010101);
  NOKIA5110_sendData(0b10101010);
  _delay_ms(100);

  /*Setting Inverse video mode after some delay*/
  NOKIA5110_setInverseVideoMode();

  /*Sending data in then in the inverse mode*/
  NOKIA5110_setXY(0, 2);           /*Going to address(0, 2)*/
  NOKIA5110_sendData(0b11111111);  /*Will see no difference because of inverse mode*/
  NOKIA5110_sendData(0b00000000);
  NOKIA5110_sendData(0b01010101);
  NOKIA5110_sendData(0b10101010);
  _delay_ms(100);

  

  /*Setting blank mode*/
  NOKIA5110_setBlankMode();

  /*Sending data in blank mode*/
  NOKIA5110_setXY(0, 3);          /*Going to address(0, 3)*/
  NOKIA5110_sendData(0b11111111);
  NOKIA5110_sendData(0b00000000);
  NOKIA5110_sendData(0b01010101);
  NOKIA5110_sendData(0b10101010);
  _delay_ms(100);



  /*Setting Normal Mode, Should */
  NOKIA5110_setNormalMode(); /*Is there any difference in the line3*/
  _delay_ms(1000);
  

  while(1){
    _delay_ms(100);
    NOKIA5110_sendData(0b11111111);
    _delay_ms(100);
    NOKIA5110_sendData(0b00000000);
  
  }
  return 0;
}
