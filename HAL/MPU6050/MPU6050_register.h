/**
 * @file       MPU6050_register.h
 * @brief      Contains the registers addresses of the MPU6050
 * @author     Abdulrahman Aboghanima
 * @date       Fri Mar  4 19:15:37 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1  
 *
 */

#ifndef _MPU6050_REGISTER_H_
#define _MPU6050_REGISTER_H_

#define SELF_TEST_X              13
#define SELF_TEST_Y              14
#define SELF_TEST_Z              15
#define SELF_TEST_A              16

#define SMPLRT_DIV               25

#define CONFIG                   26
#define GYRO_CONFIG              27
#define ACCEL_CONFIG             28

#define FIFO_EN                  35

#define FIFO_EN_SLV0             0
#define FIFO_EN_SLV1             1
#define FIFO_EN_SLV2             2
#define FIFO_EN_ACCEL            3
#define FIFO_EN_ZG               4
#define FIFO_EN_YG               5
#define FIFO_EN_XG               6
#define FIFO_EN_TEMP             7


#define INT_ENABLE               56

#define ACCEL_XOUT_H             59
#define ACCEL_XOUT_L             60
#define ACCEL_YOUT_H             61
#define ACCEL_YOUT_L             62
#define ACCEL_ZOUT_H             63
#define ACCEL_ZOUT_L             64
#define TEMP_OUT_H               65
#define TEMP_OUT_L               66



#define GYRO_XOUT_H              67
#define GYRO_XOUT_L              68
#define GYRO_YOUT_H              69
#define GYRO_YOUT_L              70
#define GYRO_ZOUT_H              71
#define GYRO_ZOUT_L              72



#define USER_CTRL                106

#define USER_CTRL_SIG_COND_RESET 0
#define USER_CTRL_I2C_MST_RESET  1
#define USER_CTRL_FIFO_RESET     2
#define USER_CTRL_I2C_IF_DIS     4
#define USER_CTRL_I2C_MST_EN     5
#define USER_CTRL_FIFO_EN        6


#define PWR_MGMT_1               107
#define PWR_MGMT_2               108


#define FIFO_COUNTH              114
#define FIFO_COUNTL              115
#define FIFO_R_W                 116
#define WHO_AM_I                 117


#endif /* _MPU6050_REGISTER_H_ */
