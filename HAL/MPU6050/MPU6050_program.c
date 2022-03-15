/**
 * @file       MPU6050_program.c
 * @brief      Contains functions definitions of the `MPU6050`
 * @author     Abdulrahman Aboghanima
 * @date       Fri Mar  4 19:30:08 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 *
 */

#include "MPU6050_config.h"
#include "MPU6050_private.h"
#include "MPU6050_register.h"
#include "MPU6050_interface.h"
#include "../../MCAL/TWI/TWI_interface.h"

#define MPU6050_ADDRESS 0x68

/**
 * @note: I used a global constant variable to avoid repeated division and multiplication.
 * @note: `MPU6050_read_accel_X()`, `MPU6050_read_accel_Y()`, `MPU6050_read_accel_Z()`
 *       use this variable in order to calibrate the output
 */
static const double accel_scale=ACCEL_SCALE;


extern void MPU6050_init(void)
{

  TWI_write_byte(MPU6050_ADDRESS, PWR_MGMT_1,   0x01); 
  TWI_write_byte(MPU6050_ADDRESS, SMPLRT_DIV,   0x07);
  TWI_write_byte(MPU6050_ADDRESS, CONFIG,       0x00);
  TWI_write_byte(MPU6050_ADDRESS, GYRO_CONFIG,  0x18);  /*Sending GYRO  Configuration*/
  TWI_write_byte(MPU6050_ADDRESS, ACCEL_CONFIG, ACCEL_CONFIG_VLAUE); /*Sending ACCEL Configuration*/
  TWI_write_byte(MPU6050_ADDRESS, INT_ENABLE,   0x01);
  
}


extern double MPU6050_read_accel_X(void)
{
  uint8_t xout_l = TWI_read_byte(MPU6050_ADDRESS, ACCEL_XOUT_L);
  uint8_t xout_h = TWI_read_byte(MPU6050_ADDRESS, ACCEL_XOUT_H);
  double   xout   = (xout_h<<8)|(xout_l);
  return xout*accel_scale; /*Acceleration in x (m/s^2)*/
}

extern double MPU6050_read_accel_Y(void)
{
  uint8_t yout_l = TWI_read_byte(MPU6050_ADDRESS, ACCEL_YOUT_L);
  uint8_t yout_h = TWI_read_byte(MPU6050_ADDRESS, ACCEL_YOUT_H);
  double   yout   = ((yout_h<<8)|(yout_l));
  return yout*accel_scale; /*Acceleration in y (m/s^2)*/
}

extern double MPU6050_read_accel_Z(void)
{
  uint8_t zout_l = TWI_read_byte(MPU6050_ADDRESS, ACCEL_ZOUT_L);
  uint8_t zout_h = TWI_read_byte(MPU6050_ADDRESS, ACCEL_ZOUT_H);
  double   zout   = (double)((zout_h<<8)|(zout_l));
  return zout*accel_scale;
    
}


extern double MPU6050_read_gyro_X(void)
{
  uint8_t xout_l = TWI_read_byte(MPU6050_ADDRESS, GYRO_XOUT_L);
  uint8_t xout_h = TWI_read_byte(MPU6050_ADDRESS, GYRO_XOUT_H);
  double   xout   = (xout_h<<8)|(xout_l);
  return xout/16.384;
}

extern double MPU6050_read_gyro_Y(void)
{
  uint8_t yout_l = TWI_read_byte(MPU6050_ADDRESS, GYRO_YOUT_L);
  uint8_t yout_h = TWI_read_byte(MPU6050_ADDRESS, GYRO_YOUT_H);
  double   yout   = (yout_h<<8)|(yout_l);
  return yout/16.384;
}

extern double MPU6050_read_gyro_Z(void)
{
  uint8_t zout_l = TWI_read_byte(MPU6050_ADDRESS, GYRO_ZOUT_L);
  uint8_t zout_h = TWI_read_byte(MPU6050_ADDRESS, GYRO_ZOUT_H);
  double   z_out  = (zout_h<<8)|(zout_l);
  return z_out/16.384;
}


extern double MPU6050_read_temp(void)
{
  uint8_t out_l = TWI_read_byte(MPU6050_ADDRESS, TEMP_OUT_L);
  uint8_t out_h = TWI_read_byte(MPU6050_ADDRESS, TEMP_OUT_H);
  double   out  = (out_h<<8)|(out_l);
  return (out/340.0) + 36.53;
}

extern void MPU6050_read_accel(MPU6050_ACCEL_t *accel_3D_values);
extern void MPU6050_read_gyro(MPU6050_GYRO_t  *gyro_3D_values);
