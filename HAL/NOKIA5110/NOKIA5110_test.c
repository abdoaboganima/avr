#include "NOKIA5110_interface.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


int main()
{

  
  NOKIA5110_init();

  
  NOKIA5110_sendData(0b11111111);

  NOKIA5110_setXY(10,1);
  NOKIA5110_sendData(0b11111111);
  NOKIA5110_sendData(0b01010101);
  NOKIA5110_sendData(0b10101010);
  NOKIA5110_sendData(0b01010101);
  NOKIA5110_sendData(0b10101010);
  NOKIA5110_sendData(0b01010101);
  NOKIA5110_sendData(0b10101010);
  
  while(1){
  }
  return 0;
}
