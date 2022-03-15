/**
 * @file       MPU6050_config.h
 * @brief      Contains configuration for the `MPU6050`
 * @author     Abdulrahman Aboghanima
 * @date       Fri Mar  4 20:22:46 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 *
 */

#ifndef _MPU6050_CONFIG_H_
#define _MPU6050_CONFIG_H_


/**
 * The full-scale range of the acceleration (upper and lower limit).
 * @note You can choose an option from the following:<br>
 *   `NEGATIVE_2G_TO_POSITIVE_2G`   <br>
 *   `NEGATIVE_4G_TO_POSITIVE_4G`   <br>
 *   `NEGATIVE_8G_TO_POSITIVE_8G`   <br>
 *   `NEGATIVE_16G_TO_POSITIVE_16G` <br>
 */
#define ACCEL_RANGE NEGATIVE_2G_TO_POSITIVE_2G



/**
 * The full-scale range of the gyroscope (upper and lower limit).
 * @note You can choose an option from the following:<br>
 *   `NEGATIVE_250_TO_POSITIVE_250`    <br>
 *   `NEGATIVE_500_TO_POSITIVE_500`    <br>
 *   `NEGATIVE_1000_TO_POSITIVE_1000`  <br>
 *   `NEGATIVE_2000_TO_POSITIVE_2000`  <br>
 */
#define GYRO_RANGE  NEGATIVE_250_TO_POSITIVE_250


#endif /* _MPU6050_CONFIG_H_ */
