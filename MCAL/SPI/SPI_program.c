 /**
 * @file SPI_program.c
 * @author Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief The implementation of the SPI_driver
 * @version 0.2
 * @copyright Copyright (c) 2022
 */

#include "SPI_register.h"
#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

/**
 * MOSI : Master Output Slave Input
 */
#define MOSI DIO_PIN5

/**
 * MISO : Master Input Slave Output
 */
#define MISO DIO_PIN6

/**
 * SCK : Serial Clock 
 */
#define SCK  DIO_PIN7

void SPI_initMaster(void)
{
  /* Set the MOSI as output*/
  DIO_SetPinDirection(DIO_PORTB, MOSI, DIO_PIN_OUTPUT);
  /* Set the serial Clock as output*/
  DIO_SetPinDirection(DIO_PORTB, SCK, DIO_PIN_OUTPUT);

  /* Master initialization */
  SET_BIT(SPCR, SPCR_MSTR);

  /* Clock Prescaler: divide by 16 */
  SET_BIT(SPCR, SPCR_SPR0);
  CLEAR_BIT(SPCR, SPCR_SPR1);
  CLEAR_BIT(SPCR, SPCR_SPR1);
  

  /* SPI Enable */
  SET_BIT(SPCR, SPCR_SPE);
  
}
void SPI_initSlave(void)
{
  /* Slave initialization*/
  CLEAR_BIT(SPCR, SPCR_MSTR);
  
  /* SPI Enable */
  SET_BIT(SPCR, SPCR_SPE);
  
}

uint8_t SPI_transceive(uint8_t data)
{
  SPDR=data;

  while(GET_BIT(SPSR, SPSR_SPIF)==0);
  
  return SPDR;
}
