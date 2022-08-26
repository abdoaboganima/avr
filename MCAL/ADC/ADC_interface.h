/**
 * @file ADC_interface.h
 * @author Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief Contains the prototypes for some ADC functions 
 * @version 0.1
 * @date Thu Sep  9 17:03:16 2021
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"


/**
 * @brief Specify the ADC channel 
 */
typedef enum
  {
   adc0,  /**< ADC channel 0, single ended input */
   adc1,  /**< ADC channel 1, single ended input */
   adc2,  /**< ADC channel 2, single ended input */
   adc3,  /**< ADC channel 3, single ended input */
   adc4,  /**< ADC channel 4, single ended input */
   adc5,  /**< ADC channel 5, single ended input */
   adc6,  /**< ADC channel 6, single ended input */
   adc7   /**< ADC channel 7, single ended input */
  } ADC_channel;

typedef enum
  {
   free_running_mode,
   analog_comparator,
   int0,
   timer0_compare_match,
   timer0_overflow,
   timer1_compare_match_channelB,
   timer1_overflow,
   timer1_capture_event
  }ADC_triggeringSource;


/**
 * @brief Initialize the ADC peripheral
 */
void ADC_init(void);

/**
 * @brief Start Synchronous conversion from a specific channel, the  value of the conversion is 
 * stored in the memory location addressed by `reading`
 * @param channel 
 * @param reading 
 */
void ADC_startSynchConversion(ADC_channel channel, uint16_t * const reading);

/**
 * @brief Start Asynchronous conversion from a specific channel, the value of the conversion is
 * stored in a memory location addressed ny `reading`
 * @param channel 
 * @param reading 
 * @param callBackFunction 
 * @note After the conversion, the function addressed by `callBackFunction` will be executed
 */
void ADC_startAsynchConversion(ADC_channel channel, uint16_t * const reading, void (*callBackFunction)(void));



void ADC_autoTrigger(ADC_channel channel, ADC_triggeringSource source, uint16_t * const reading);


#define DIV_BY_2      1
#define DIV_BY_4      2
#define DIV_BY_8      3
#define DIV_BY_16     4
#define DIV_BY_32     5
#define DIV_BY_64     6
#define DIV_BY_128    7


#endif /* _ADC_INTERFACE_H_ */


