/**
 * @file ADC_config.h
 * @author Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief User configuration for the ADC
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
 * @addtogroup ADC_config
 * @{
 */
#ifndef _ADC_CONFIG_H_
#define _ADC_CONFIG_H_




/**
 * ADC_PRESCALER
 * @note Choose the devision factor between the XTAL frequency and the input clock to ADC
 * @note You can choose:
 *  DIV_BY_2    <br>    
 *  DIV_BY_4    <br>
 *  DIV_BY_8    <br>
 *  DIV_BY_16   <br>
 *  DIV_BY_32   <br>
 *  DIV_BY_64   <br>
 *  DIV_BY_128  <br>
 */
#define ADC_PRESCALER DIV_BY_128


#endif /* _ADC_CONFIG_H_ */
/*@}@}@}*/