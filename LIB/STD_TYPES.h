 /**
 * @file STD_TYPES.h
 * @author Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief stdint types for the `avr-gcc` compiler
 * @version 0.2
 * @code #include "STD_TYPES.h" @endcode
 * @copyright Copyright (c) 2022
 */

#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_




/** @addtogroup STD_TYPES
 * @{
 */ 

/**
 * 1-Byte Data Type
 */
typedef unsigned char uint8_t;
typedef signed char int8_t;

/**
 * 2-Byte Data Type
 * @note The size of `int` in `avr-gcc` compiler is a 2-byte
 */
typedef unsigned int uint16_t;
typedef signed int int16_t;

/**
 * 4-bytes Data Type
 */
typedef unsigned long int uint32_t;
typedef signed long int int32_t;

/* Floating Data Type*/
typedef float f32;
typedef double f64;

/*}@*/

#define NULL 0

#endif /* _STD_TYPES_H_ */
