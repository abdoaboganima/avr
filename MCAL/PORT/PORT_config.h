/**
 *
 * @file       PORT_config.h
 * @brief      Contains Configuration for the `PORT` module
 * @author     Abdulrahman Aboghanima
 * @date       Mon Aug 15 17:11:52 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * @note       This is pre-build configuration for any port
 *             If you'd like to configure a pin for input choose 0.
 *             If you'd like to configure a pin for output choose 1.
 */

#ifndef _PORT_CONFIG_H_
#define _PORT_CONFIG_H_


/* Choose: 
   0 for input and 
   1 for output
*/

#define PORTA_PIN0_DIR		1
#define PORTA_PIN1_DIR		1
#define PORTA_PIN2_DIR		1
#define PORTA_PIN3_DIR		0
#define PORTA_PIN4_DIR		0
#define PORTA_PIN5_DIR		0
#define PORTA_PIN6_DIR		0
#define PORTA_PIN7_DIR		0


#define PORTB_PIN0_DIR		0
#define PORTB_PIN1_DIR		1
#define PORTB_PIN2_DIR		1
#define PORTB_PIN3_DIR		0
#define PORTB_PIN4_DIR		1
#define PORTB_PIN5_DIR		1
#define PORTB_PIN6_DIR		1
#define PORTB_PIN7_DIR		1



#define PORTC_PIN0_DIR		1
#define PORTC_PIN1_DIR		1
#define PORTC_PIN2_DIR		1
#define PORTC_PIN3_DIR		1
#define PORTC_PIN4_DIR		0
#define PORTC_PIN5_DIR		0
#define PORTC_PIN6_DIR		0
#define PORTC_PIN7_DIR		0


#define PORTD_PIN0_DIR		1
#define PORTD_PIN1_DIR		1
#define PORTD_PIN2_DIR		1
#define PORTD_PIN3_DIR		1
#define PORTD_PIN4_DIR		0
#define PORTD_PIN5_DIR		0
#define PORTD_PIN6_DIR		0
#define PORTD_PIN7_DIR		0



/*
  If the direction is output:
     Choose : 0 for low 
     choose : 1 for high

  If the direction is input:
     choose : 0  for floating
     choose : 1  for pull-up resistance
	   
*/



#define PORTA_PIN0_INITIAL_VALUE		1
#define PORTA_PIN1_INITIAL_VALUE		1
#define PORTA_PIN2_INITIAL_VALUE		1
#define PORTA_PIN3_INITIAL_VALUE		1
#define PORTA_PIN4_INITIAL_VALUE		1
#define PORTA_PIN5_INITIAL_VALUE		1
#define PORTA_PIN6_INITIAL_VALUE		1
#define PORTA_PIN7_INITIAL_VALUE		1


#define PORTB_PIN0_INITIAL_VALUE		0
#define PORTB_PIN1_INITIAL_VALUE		0
#define PORTB_PIN2_INITIAL_VALUE		0
#define PORTB_PIN3_INITIAL_VALUE		0
#define PORTB_PIN4_INITIAL_VALUE		0
#define PORTB_PIN5_INITIAL_VALUE		0
#define PORTB_PIN6_INITIAL_VALUE		0
#define PORTB_PIN7_INITIAL_VALUE		0



#define PORTC_PIN0_INITIAL_VALUE		0
#define PORTC_PIN1_INITIAL_VALUE		0
#define PORTC_PIN2_INITIAL_VALUE		0
#define PORTC_PIN3_INITIAL_VALUE		0
#define PORTC_PIN4_INITIAL_VALUE		1
#define PORTC_PIN5_INITIAL_VALUE		1
#define PORTC_PIN6_INITIAL_VALUE		1
#define PORTC_PIN7_INITIAL_VALUE		1


#define PORTD_PIN0_INITIAL_VALUE		0
#define PORTD_PIN1_INITIAL_VALUE		0
#define PORTD_PIN2_INITIAL_VALUE		0
#define PORTD_PIN3_INITIAL_VALUE		0
#define PORTD_PIN4_INITIAL_VALUE		1
#define PORTD_PIN5_INITIAL_VALUE		1
#define PORTD_PIN6_INITIAL_VALUE		1
#define PORTD_PIN7_INITIAL_VALUE		1




#endif /* _PORT_CONFIG_H_ */
