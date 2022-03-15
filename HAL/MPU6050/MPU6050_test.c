#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/USART/USART_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TWI/TWI_interface.h"
#include "MPU6050_interface.h"
#include "MPU6050_config.h"
#include <stdio.h>

#include <util/delay.h>

int main()
{

  DIO_SetPortDirection(DIO_PORTD, DIO_PORT_OUTPUT);

  USART_init();
  USART_redirect_stream_to_stdout();

  TWI_initMaster();
  MPU6050_init();

  
  
  while(1){
  
    double gx= MPU6050_read_gyro_X();
    double gy= MPU6050_read_gyro_Y();
    double gz= MPU6050_read_gyro_Z();

    double x = MPU6050_read_accel_X();
    double z = MPU6050_read_accel_Z();
    double y = MPU6050_read_accel_Y();
    double t = MPU6050_read_temp();
    printf("\n<<<<.............Testing the MPU6050.............>>>>\n");
    printf("ACCELEROMETER: ");
    printf("ax=%f, ay=%f, az=%f m/s^2\n", x, y, z);
    printf("GYROSCOPE    : ");
    printf("gx=%f, gy=%f, gz=%f deg/s\n", gx, gy, gz);
    printf("Temperature  : %f degC\n", t);
    _delay_ms(1000);
  }
  return 0;

}
