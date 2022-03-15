/**
 * @file       MPU6050_private.h
 * @brief      Contains private prototypes and data for the MPU6050 
 * @author     Abdulrahman Aboghanima
 * @date       Fri Mar  4 20:23:25 2022
 * @copyright  Copyright (c) 2022
 * @version    
 *
 */

#ifndef _MPU6050_PRIVATE_H_
#define _MPU6050_PRIVATE_H_

#define NEGATIVE_2G_TO_POSITIVE_2G       0 
#define NEGATIVE_4G_TO_POSITIVE_4G       1
#define NEGATIVE_8G_TO_POSITIVE_8G       2
#define NEGATIVE_16G_TO_POSITIVE_16G     3
				         
#define NEGATIVE_250_TO_POSITIVE_250     4
#define NEGATIVE_500_TO_POSITIVE_500     5
#define NEGATIVE_1000_TO_POSITIVE_1000   6
#define NEGATIVE_2000_TO_POSITIVE_2000   7 


#include "MPU6050_config.h"

#if ACCEL_RANGE==NEGATIVE_2G_TO_POSITIVE_2G
#define ACCEL_CONFIG_VLAUE  0x00
#define ACCEL_SCALE 2*9.8/32678.0


#elif ACCEL_RANGE==NEGATIVE_4G_TO_POSITIVE_4G 
#define ACCEL_CONFIG_VLAUE  0x08
#define ACCEL_SCALE 4*9.8/32678.0


#elif ACCEL_RANGE==NEGATIVE_8G_TO_POSITIVE_8G 
#define ACCEL_CONFIG_VLAUE  0x10
#define ACCEL_SCALE 8*9.8/32678.0


#elif ACCEL_RANGE==NEGATIVE_16G_TO_POSITIVE_16G 
#define ACCEL_CONFIG_VLAUE  0x18
#define ACCEL_SCALE 16*9.8/32678.0


#else
#error "Wrong Option in ACCEL_RANGE"


#endif


#if GYRO_RANGE==NEGATIVE_250_TO_POSITIVE_250
#define GYRO_CONFIG_VLAUE  0x00

#elif GYRO_RANGE==NEGATIVE_500_TO_POSITIVE_500 
#define GYRO_CONFIG_VLAUE  0x08

#elif GYRO_RANGE==NEGATIVE_1000_TO_POSITIVE_1000 
#define GYRO_CONFIG_VLAUE  0x10

#elif GYRO_RANGE==NEGATIVE_2000_TO_POSITIVE_2000 
#define GYRO_CONFIG_VLAUE  0x18

#else
#error "Wrong Option in GYRO_RANGE"

#endif






#endif /* _MPU6050_PRIVATE_H_ */
