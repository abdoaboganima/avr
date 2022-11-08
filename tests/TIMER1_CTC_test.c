#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/USART/USART_interface.h"

#include "../MCAL/Timers/TIMER_interface.h"

#include <util/delay.h>


void func1(void)
{
  USART_sendStream("Func1\n");
}


void func2(void)
{
  USART_sendStream("Func2\n");
}

int main(void)
{

  /*Setting the OC0 pin to be output*/
  DIO_SetPinDirection(DIO_PORTB, DIO_PIN3, DIO_PIN_OUTPUT);

  /*Setting the OC1A pin to be output*/
  DIO_SetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT);
  /*Setting the OC1B pin to be output*/
  DIO_SetPinDirection(DIO_PORTD, DIO_PIN4, DIO_PIN_OUTPUT);

  /*Setting the UART TX pin to be output*/
  DIO_SetPinDirection(DIO_PORTD, DIO_PIN1, DIO_PIN_OUTPUT);
  
  USART_init();

  /*Initialization of timer1 to be in the CTC mode*/
  TIMER_init(timer1, fast_PWM, divided_by_8);     /*The input frequency is 1 MHz*/
  TIMER1_setChannelAComapareMatchValue(1000);
  TIMER1_setChannelBComapareMatchValue(249);
  TIMER1_setChannelAComapareMatchCallBack(func1);
  TIMER1_setChannelBComapareMatchCallBack(func2);

  TIMER1_setICR(2000);

  GIE_enable();
   
  while(1);

  return 0;
}
