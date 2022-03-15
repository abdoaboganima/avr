/**
 * @file       MPU6050_interface.h
 * @brief      The interface file of the MPU6050 
 * @author     Abdulrahman Aboghanima
 * @date       Fri Mar  4 19:30:46 2022
 * @copyright  Copyright (c) 2022
 * @version    
 *
 */

#ifndef _MPU6050_INTERFACE_H_
#define _MPU6050_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"

/**
 * Defines three variables 
 * which specify the acceleration in the 3-axes.
 */
typedef struct{
  uint16_t x; /**<The acceleration in the x direction */
  uint16_t y; /**<The acceleration in the y direction */
  uint16_t z; /**<The acceleration in the z direction */
} MPU6050_ACCEL_t;

/**
 * Defines three variables 
 * which specify the angles in the 3-axes.
 */
typedef struct{
  uint16_t x;
  uint16_t y;
  uint16_t z;
} MPU6050_GYRO_t;

/**
 * @brief  Initialization of the MPU6050 Module.
 * @param  None
 * @return None
 * @note   This initialization depends in the configuration file (`MPU6050_config.h`)
 */
extern void MPU6050_init(void);



/**
 * @brief  Read the acceleration of the x component 
 * @param  None
 * @return double
 * @code double ax = MPU6050_read_accel_X(void); @endcode 
 */
extern double MPU6050_read_accel_X(void);

/**
 * @brief  Read the acceleration of the y component 
 * @param  None
 * @return double
 */
extern double MPU6050_read_accel_Y(void);

/**
 * @brief  Read the acceleration of the z component 
 * @param  None
 * @return double
 */
extern double MPU6050_read_accel_Z(void);



/**
 * @brief  Read the angle of the x component 
 * @param  None
 * @return double
 */
extern double MPU6050_read_gyro_X(void);

/**
 * @brief  Read the angle of the y component 
 * @param  None
 * @return double
 */
extern double MPU6050_read_gyro_Y(void);

/**
 * @brief  Read the angle of the z component 
 * @param  None
 * @return double
 */
extern double MPU6050_read_gyro_Z(void);


/**
 * @brief Reads the temperature using MPU6050
 * @param None
 * @return double (temperature)
 * @note The temperature is in Celsius.
 */
extern double MPU6050_read_temp(void);



/**
 * @todo Implementation
 */
extern void MPU6050_read_accel(MPU6050_ACCEL_t *accel_3D_values);

/**
 * @todo Implementation
 */
extern void MPU6050_read_gyro(MPU6050_GYRO_t  *gyro_3D_values);
#endif /* _MPU6050_INTERFACE_H_ */
