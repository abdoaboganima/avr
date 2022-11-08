#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/USART/USART_interface.h"
#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/LM35/LM35_interface.h"
#include "../HAL/CLCD/CLCD_config.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/Timers/TIMER_interface.h"
#include <util/delay.h>
#include <stdio.h>

float takeAvg(void)
{
  float reading1=LM35_getTemp(adc0);
  float reading2=LM35_getTemp(adc1);
  return (reading1+reading2)/2 ; 
}

float avg_temp=0;

static volatile uint16_t numOfOverflowsInHighTemp=0;
static volatile uint16_t numOfOverflowsInLowTemp=0;
void timer_ovf_callback()
{
  if((uint8_t)avg_temp>25){
    numOfOverflowsInHighTemp++;
    numOfOverflowsInLowTemp=0;
  }
  else if((uint8_t)avg_temp<23){
    numOfOverflowsInHighTemp=0;
    numOfOverflowsInLowTemp++;
  }
  else{
    numOfOverflowsInLowTemp=0;
    numOfOverflowsInHighTemp=0;
  }
  
  if(numOfOverflowsInHighTemp>300)
    printf("Fan++++\n");
  if(numOfOverflowsInLowTemp>100)
    printf("Fan----\n");
  
}

int main()
{
  /*Setting the Pin0 of the PORTA to be input for the ADC*/
  DIO_SetPinDirection(DIO_PORTA, DIO_PIN0, DIO_PIN_INPUT);

  ADC_init();
  USART_init();
  TIMER_init(timer0, normal, divided_by_1024);
  TIMER_normalModeOverflowSetCallBack(timer0, timer_ovf_callback);
  USART_redirect_stream_to_stdout();
  GIE_enable();

  while(1){
    avg_temp=takeAvg();
    printf("avg temp=%f\n", avg_temp);
    printf("HighTemp Overflows=%d\n", numOfOverflowsInHighTemp);
    printf("LowTemp Overflows=%d\n", numOfOverflowsInLowTemp);
    
  }

  return 0;
  
}
