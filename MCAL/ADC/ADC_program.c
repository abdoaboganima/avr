#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_register.h"


static uint8_t ADC_BusyState=IDLE;
static uint16_t *ptrToReading=NULL;
static void (*ADC_callBackFunction)(void)=NULL;



void ADC_init(void)
{

  /*AVCC, With external capacitor at AREF pin*/
  SET_BIT(ADMUX, ADMUX_REFS0);
  CLEAR_BIT(ADMUX, ADMUX_REFS1);

  /*Set Prescaler to divide by 128*/
  ADCSRA&=0b11111000;
  ADCSRA|=ADC_PRESCALER;
  
  /*Enable the ADC Peripheral*/
  SET_BIT(ADCSRA, ADCSRA_ADEN);
  
}



void ADC_selectChannel(ADC_channel channel)
{
  /*CLEAR the MUX bits in ADMUX register and Specify a Channel*/
  ADMUX &=0b11100000;
  ADMUX |=channel;  
}

void ADC_startSynchConversion(ADC_channel channel, uint16_t * const reading)
{
  if(ADC_BusyState==BUSY)
    return;
  ADC_BusyState=BUSY;

  /*Select the desired channel */
  ADC_selectChannel(channel) ;

  /*Start Conversion*/
  SET_BIT(ADCSRA, ADCSRA_ADSC);

  /*Polling (busy waiting) until the conversion complete flag is set*/
  while((GET_BIT(ADCSRA, ADCSRA_ADIF))==0);

  /*Clear the conversion completeness flag*/
  SET_BIT(ADCSRA, ADCSRA_ADIF); //Setting this bit to one makes the flag=0!

  *reading= ADC;
  ADC_BusyState=IDLE;
}

void ADC_startAsynchConversion(ADC_channel channel, uint16_t * const reading, void (*callBackFunction)(void))
{
  if(ADC_BusyState==BUSY)
    return;
  ADC_BusyState=BUSY;
  /* 
     Since after the conversion there is an interrupt service routine to be
     executed, so we will use `reading` and `callBackfunction` to be hanled
     by the ISR
     NOTE: They are useless unless the conversion happens.
   */
  ptrToReading=reading;
  ADC_callBackFunction=callBackFunction;
  
  /*Select the desired channel */
  ADC_selectChannel(channel) ;

  /*Start Conversion*/         
  SET_BIT(ADCSRA, ADCSRA_ADSC);

  /*ADC interrupt Enable*/
  SET_BIT(ADCSRA, ADCSRA_ADIE);
  
}

void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
  /*This assigns the reading of the ADC to the `*reading` in the `ADC_StartAsynchConversion`*/
  *ptrToReading=ADC;

  /*Invoke the callbackfunction*/
  ADC_callBackFunction();

  /*Disable the ADC conversion complete interrupt*/
  CLEAR_BIT(ADCSRA, ADCSRA_ADIE);

  /*Make ADC state idle*/
  ADC_BusyState=IDLE;
}
