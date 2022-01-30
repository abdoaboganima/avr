/**
 * @file ADC_interface.h
 * @author Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief Contains the prototypes for some ADC functions 
 * @version 0.1
 * @date Thu Sep  9 17:03:16 2021
 * @copyright Copyright (c) 2022
 * 
 */
/**
 * @addtogroup MCAL_drivers
 * @{
 * @addtogroup ADC_drivers
 * @{
 */ 
#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"
/**
 * @brief Initialize the ADC peripheral
 * 
 */
void ADC_init(void);

/**
 * @brief Start Synchronous conversion from a specific channel, the  value of the conversion is 
 * stored in the memory location addressed by `reading`
 * 
 * @param channel 
 * @param reading 
 */
void ADC_StartSynchConversion(uint8_t channel, uint16_t *reading);

/**
 * @brief Start Asynchronous conversion from a specific channel, the value of the conversion is
 * stored in a memory location addressed ny `reading`
 * @note After the conversion, the function addressed by `callBackFunction` will be executed
 * 
 * @param channel 
 * @param reading 
 * @param callBackFunction 
 */
void ADC_StartAsynchConversion(uint8_t channel, uint16_t *reading, void (*callBackFunction)(void));

/**
 * @addtogroup ADC_PRESCALERS
 * @{
 */ 
#define DIV_BY_2      1
#define DIV_BY_4      2
#define DIV_BY_8      3
#define DIV_BY_16     4
#define DIV_BY_32     5
#define DIV_BY_64     6
#define DIV_BY_128    7
/* @}*/

#endif /* _ADC_INTERFACE_H_ */



/* @}@}*/
