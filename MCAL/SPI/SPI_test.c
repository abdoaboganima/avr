/**
 *
 * @file       SPI_test.c
 * @brief      Contains tests for the SPI driver
 * @author     Abdulrahman Aboghanima
 * @date       Tue Aug  9 16:41:26 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */

#include "SPI_interface.h"



int main()
{
  
  SPI_initMaster(); /* Master initialization of the SPI*/

  while(1){
    SPI_transceive(0x12); /*Check for this Value using SPI debugger*/
  }
  return 0;
}
