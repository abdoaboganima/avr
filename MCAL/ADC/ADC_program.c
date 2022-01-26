#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_register.h"


static u8 ADC_BusyState=IDLE;

void ADC_init(void)
{

  /*AVCC with external capacitor at AREF pin >> MADE: ADMUX_REFS0= 1 &ADMUX_REFS1= 0 */
  
  /*AREF, Internal Vref turned off*/
  CLEAR_BIT(ADMUX, ADMUX_REFS0);
  CLEAR_BIT(ADMUX, ADMUX_REFS0);

  /*Activate Left Adjust Result*/
  //SET_BIT(ADMUX, ADMUX_ADLAR);


  /*Set Prescaler to divide by 128*/
  ADCSRA&=0b11111000;
  ADCSRA|=ADC_PRESCALER;
  
  /*Enable the ADC Peripheral*/
  SET_BIT(ADCSRA, ADCSRA_ADEN);
  
}


void ADC_StartSynchConversion(u8 channel, u16 *reading)
{
  if(ADC_BusyState==BUSY)
    return;
  ADC_BusyState=BUSY;
  
  /*CLEAR the MUX bits in ADMUX register and Specify a Channel*/
  ADMUX &=0b11100000;
  ADMUX |=channel;

  /*Start Conversion*/
  SET_BIT(ADCSRA, ADCSRA_ADSC);

  /*Polling (busy waiting) until the conversion complete flag is set*/
  while((GET_BIT(ADCSRA, ADCSRA_ADIF))==0);

  /*Clear the conversion completeness flag*/
  SET_BIT(ADCSRA, ADCSRA_ADIF); //Setting this bit to one makes the flag=0!

  *reading= ADC;
  ADC_BusyState=IDLE;
}

static u16 *ptrToReading=NULL;
static void (*ADC_callBackFunction)(void)=NULL;
void ADC_StartAsynchConversion(u8 channel, u16 *reading, void (*callBackFunction)(void))
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
  
  /*CLEAR the MUX bits in ADMUX register and Specify a Channel*/
  ADMUX &=0b11100000;
  ADMUX |=channel;

  /*Start Conversion*/         
  SET_BIT(ADCSRA, ADCSRA_ADSC);

  /*ADC interrupt Enable*/
  SET_BIT(ADCSRA, ADCSRA_ADIE);
  
}

void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
  *ptrToReading=ADC; /*This assigns the reading of the ADC to the `*reading` in the `ADC_StartAsynchConversion`*/

  /*Invoke the callbackfunction*/
  ADC_callBackFunction();

  /*Disable the ADC conversion complete interrupt*/
  CLEAR_BIT(ADCSRA, ADCSRA_ADIE);

  /*Make ADC state idle*/
  ADC_BusyState=IDLE;
}
