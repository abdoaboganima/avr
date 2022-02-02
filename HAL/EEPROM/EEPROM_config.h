 /**
 * @file EEPROM_config.h
 * @author Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief User Configuration for `AT24C08A` Serial EEPROM 
 * @version 0.1
 * @date 2022-02-02
 * @copyright Copyright (c) 2022
 */
#ifndef _EEPROM_CONFIG_H_
#define _EEPROM_CONFIG_H_

#define HIGH 1
#define LOW 0
 /**
 * @brief Define the value that connected to the `A2` pin in `AT24C08A`
 * @note From the data sheet in `AT24C08A`, we don't care about the `A0`, `A1` values.
 * @note We are interested in the `A2` only because:
 * <ol>
 * <li>It forms the address of the EEPROM
 * <li>It helps connect another EEPROM by wiring the first one by HIGH and the second by LOW
 * </ol>
 */
#define A2_PIN LOW 

#endif /* _EEPROM_CONFIG_H_ */
