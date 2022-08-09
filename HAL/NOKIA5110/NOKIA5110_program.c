/**
 *
 * @file       NOKIA5110_program.c
 * @brief      Contains NOKIA5110 functions definitions
 * @author     Abdulrahman Aboghanima
 * @date       Tue Aug  9 13:36:05 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */

#include "NOKIA5110_interface.h"
#include "NOKIA5110_config.h"
#include "../../MCAL/SPI/SPI_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"


#define CMD  0
#define DATA 1


extern void NOKIA5110_reset(void)
{

  DIO_SetPinValue(CTRL_PORT, RST, DIO_PIN_LOW);
  DIO_SetPinValue(CTRL_PORT, RST, DIO_PIN_HIGH);
}

extern void NOKIA5110_setXY(uint8_t x, uint8_t y)
{
  
  /*Note x range is from 0:83*/
  NOKIA5110_sendCommand(0x80|x);

  /*Note y range is from 0:5*/
  NOKIA5110_sendCommand(0x40|y);
}

extern void NOKIA5110_init(void)
{

  SPI_initMaster();
  DIO_SetPinDirection(CTRL_PORT, SCE, DIO_PIN_OUTPUT);
  DIO_SetPinDirection(CTRL_PORT, D_C, DIO_PIN_OUTPUT);
  DIO_SetPinDirection(CTRL_PORT, RST, DIO_PIN_OUTPUT);

  NOKIA5110_reset(); /*According to the Datasheet a RESET signal must be applied at initialization*/
  
  DIO_SetPinValue(CTRL_PORT, SCE, DIO_PIN_LOW);
  
  NOKIA5110_sendCommand(0x21);
  NOKIA5110_sendCommand(0x90);
  NOKIA5110_sendCommand(0x20);
  NOKIA5110_sendCommand(0x0c);


}

extern void NOKIA5110_sendCommand(uint8_t command)
{
  
  /*Outputting 0 to the D/C' pin*/
  DIO_SetPinValue(CTRL_PORT, D_C, DIO_PIN_LOW);
  SPI_transceive(command);

}

extern void NOKIA5110_sendData(uint8_t data)
{
  
  /*Outputting 1 to the D/C' pin*/
  DIO_SetPinValue(CTRL_PORT, D_C, DIO_PIN_HIGH);
  SPI_transceive(data);

}
