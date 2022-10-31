/**
 *
 * @file       PORT_program.c
 * @brief      Contains functions definitions for the `PORT` module
 * @author     Abdulrahman Aboghanima
 * @date       Mon Aug 15 17:29:27 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */

#include "PORT_config.h"
#include "PORT_interface.h"
#include "PORT_register.h"
#include "PORT_private.h"



extern void PORT_init(void)
{

  DDRA=PORTA_DIR;
  DDRB=PORTB_DIR;
  DDRC=PORTC_DIR;
  DDRD=PORTD_DIR;
  
  
  PORTA=PORTA_INITIAL_VALUE;
  PORTB=PORTB_INITIAL_VALUE;
  PORTC=PORTC_INITIAL_VALUE;
  PORTD=PORTD_INITIAL_VALUE;
    
}
