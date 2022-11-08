/**
 *
 * @file       LM35_interface.h
 * @brief      Contains functions declarations for the LM35(temperature sensor)
 * @author     Abdulrahman Aboghanima
 * @date       Sun Sep 11 02:48:15 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */

#include "../../MCAL/ADC/ADC_interface.h"

/**
 * @brief Gets the temperature from the LM35
 * @pre   The `ADC` module must be initialized.
 * @param channel, the channel to which the LM35 is connected 
 * @return The converted temperature 
 */
extern float LM35_getTemp(ADC_channel channel);
