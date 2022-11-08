/**
 *
 * @file       LM35_program.c
 * @brief      Contains functions defintions for the LM35 module
 * @author     Abdulrahman Aboghanima
 * @date       Sun Sep 11 02:50:43 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */

#include "../../MCAL/ADC/ADC_interface.h"

extern void LM35_init(void)
{
  ADC_init();
}

extern float LM35_getTemp(ADC_channel channel)
{
  uint16_t reading;
  ADC_startSynchConversion(channel, &reading);
  /*Note: Every 10mV gives 1deg C */
  return ((float)500/(float)1024)*(float)reading;
}
