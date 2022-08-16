/**
 *
 * @file       NOKIA5110_program.c
 * @brief      Contains NOKIA5110 functions definitions
 * @author     Abdulrahman Aboghanima
 * @date       Tue Aug  9 13:36:05 2022
 * @copyright  Copyright (c) 2022
 * @version    0.2
 * 
 */

#include "NOKIA5110_interface.h"
#include "NOKIA5110_config.h"
#include "NOKIA5110_private.h"
#include "../../MCAL/SPI/SPI_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"

static uint8_t mode=NORMAL_MODE;

extern void NOKIA5110_reset(void)
{
  DIO_SetPinValue(CTRL_PORT, RST, DIO_PIN_LOW);
  DIO_SetPinValue(CTRL_PORT, RST, DIO_PIN_HIGH);
}

extern void NOKIA5110_setXY(const uint8_t x, const uint8_t y)
{
  if( (x>83) || (y>5) ) /*Bad input*/
    return; /* Do nothing*/
  
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
  NOKIA5110_setNormalMode();

}

extern void NOKIA5110_sendCommand(const uint8_t command)
{
  /*Outputting 0 to the D/C' pin*/
  DIO_SetPinValue(CTRL_PORT, D_C, DIO_PIN_LOW);
  SPI_transceive(command);
}


extern void NOKIA5110_sendData(const uint8_t data)
{
  /*Outputting 1 to the D/C' pin*/
  DIO_SetPinValue(CTRL_PORT, D_C, DIO_PIN_HIGH);
  SPI_transceive(data);
}


extern void NOKIA5110_setNormalMode(void)
{
  NOKIA5110_sendCommand(NORMAL_MODE);
  mode=NORMAL_MODE;
}

extern void NOKIA5110_setInverseVideoMode(void)
{
  NOKIA5110_sendCommand(INVERSE_MODE);
  mode=INVERSE_MODE;
}

extern void NOKIA5110_setBlankMode(void)
{
  NOKIA5110_sendCommand(BLANK_MODE);
  mode=BLANK_MODE;
}

extern void NOKIA5110_setAllSegmentsON(void)
{
  NOKIA5110_sendCommand(ALL_SEGMENTS_ON);
  mode=ALL_SEGMENTS_ON;
}


extern void NOKIA5110_clearDisplay(void)
{

  /*From the current address pointer, begin writing 0x00 over it. 
   *The address pointer wraps around and begins from address(0, 0) if it exceeds address(83, 5)
   */
  for (uint16_t i=0; i < (MAX_X*MAX_Y)/8; ++i)
    NOKIA5110_sendData(0x00);

  /*Set cursor to address then first bit*/
  NOKIA5110_setXY(0, 0);
}


extern void NOKIA5110_sendChar(const char character)
{
  /*Send the character byte by byte*/
  for(uint8_t i=0; i<5; i++)
    NOKIA5110_sendData(ASCII[character-0x20][i]);
  
  NOKIA5110_sendData(0x00); /*vertical line padding*/
  
}


extern void NOKIA5110_sendString(const char *string)
{
  while(*string)
    NOKIA5110_sendChar(*string++);
}


extern void NOKIA5110_drawFullImage(const uint8_t *image)
{
  /*Set the cursor to the address(0, 0)*/
  NOKIA5110_setXY(0, 0);

  /*Send the image byte by byte*/
  for (uint16_t i=0; i < (MAX_X*MAX_Y)/8; ++i)
    NOKIA5110_sendData(image[i]);
  
}
