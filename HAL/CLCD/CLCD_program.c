 /**
 * @file CLCD_program.c
 * @author Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief The implementations of the CLCD_drivers
 * @version 0.2
 * @copyright Copyright (c) 2022
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "CLCD_private.h"
#include "CLCD_config.h" 
#include "CLCD_interface.h"
#include <util/delay.h>

static inline void setEnableForSomeTime()
{
  DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_PIN_HIGH);
  _delay_ms(10);

  DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_PIN_LOW);
  _delay_ms(10);
}

static inline void CLCD_SendCommand(const uint8_t Command)
{
  DIO_SetPortValue(CLCD_DATA_PORT, Command);
  
  /* Set RS pin to zero for command*/
  DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_PIN_LOW);

  /* SET RW pin to zero for writing on the LCD*/
  DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_PIN_LOW);

  /* SET Enable for enabling the LCD to read from the data port*/
  setEnableForSomeTime();  
#if CLCD_MODE==MODE_4_BIT
  DIO_SetPortValue(CLCD_DATA_PORT, Command<<4);
  setEnableForSomeTime();
#endif
}
extern void CLCD_SendData(const uint8_t Data)
{
  
  DIO_SetPortValue(CLCD_DATA_PORT, Data);

  /* Set RS pin to ONE for data*/
  DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_PIN_HIGH);

  /* SET RW pin to zero for writing on the LCD*/
  DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_PIN_LOW);


  /* SET Enable for enabling the LCD to read from the data port*/
  setEnableForSomeTime();
#if CLCD_MODE==MODE_4_BIT
  DIO_SetPortValue(CLCD_DATA_PORT, Data<<4);
  setEnableForSomeTime();
#endif
  
}
void CLCD_Clear(void)
{
  CLCD_SendCommand(0b00000010);
}
void CLCD_Blink(void)
{
  CLCD_SendCommand(0b00001111);
}
void CLCD_init(void)
{
  
  DIO_SetPortDirection(CLCD_DATA_PORT, DIO_PORT_OUTPUT);
  DIO_SetPinDirection(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_PIN_OUTPUT);
  DIO_SetPinDirection(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_PIN_OUTPUT);
  DIO_SetPinDirection(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_PIN_OUTPUT);
  
  _delay_ms(40);
#if CLCD_MODE==MODE_8_BIT
  CLCD_SendCommand(0x30);
  CLCD_SendCommand(0x30);
  CLCD_SendCommand(0x30);
  
  CLCD_SendCommand(0b00111000);
  CLCD_SendCommand(0b00001110);
  CLCD_SendCommand(1);
  //CLCD_SendCommand(0b00000110);
#elif CLCD_MODE==MODE_4_BIT
  
  /*These 2-following commands MUST be sent before the finction set*/
  CLCD_SendCommand(0x33);
  CLCD_SendCommand(0x32);

  /*function Set*/
  CLCD_SendCommand(0b00101000);
  /*Display on/off Control*/
  CLCD_SendCommand(0b00001110);
  /*Display Clear*/
  CLCD_SendCommand(0b00000001);
  /*Entry mode set*/
  CLCD_SendCommand(0b00000110);
  
#else
#error "Error in LCD Mode option"
#endif
}

void CLCD_SendString(const char *string)
{
  while(*string!='\0') CLCD_SendData(*string++);
}

void CLCD_GoTOXY(const uint8_t XPos, const uint8_t YPos)
{
  /* Set bit number 7 for Setting DDRAM Address command then send the command */
  /* If the XPos==0, it's the first line, else it is the second*/
  CLCD_SendCommand(0x80|( XPos ? YPos+0x40 : YPos));
}
 
void CLCD_SendSpecialChar(const uint8_t *charArray, const uint8_t charIndex, const uint8_t XPos, const uint8_t YPos)
{
  CLCD_SendCommand(charIndex*8 | 0x40); /* Command for writing on the CGRAM*/

  /*
   * The Data now is going to be sent in the CGRAM 
   *  we specified that in the previous command
   */
  for(uint8_t i=0; i<8; i++)
    CLCD_SendData(charArray[i]);
  CLCD_GoTOXY(XPos, YPos);//This Sets the DDRAM address
  CLCD_SendData(charIndex);
}
char *utoa(uint32_t value, uint8_t base)
{
  static char buff[32]={0};
  uint8_t i=30;
  const char *literals="0123456789abcdef";
  for(; value !=0 ; value/=base)
    buff[i--]=literals[value%base];
  return &buff[i+1];
}
