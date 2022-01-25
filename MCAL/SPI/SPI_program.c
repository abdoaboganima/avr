#include "SPI_register.h"
#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

void SPI_initMaster(void)
{

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

u8 SPI_transceive(u8 data)
{
  SPDR=data;

  while(GET_BIT(SPSR, SPSR_SPIF)==0);
  
  return SPDR;
}
