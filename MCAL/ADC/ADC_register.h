/*******************************************************
 *
 * @file   ADC_register.h
 * @brief  Defines the ADC peripherals registers
 * @author Abdulrahman Aboghanima
 * @date   Thu Sep  9 17:03:16 2021
 *
 *******************************************************/



#ifndef _ADC_REGISTER_H_
#define _ADC_REGISTER_H_


/*ADC Multiplexer Selection Register*/
#define ADMUX           *((volatile u8*) 0x27)

#define ADMUX_REFS1      7   //Reference Selection Vt1
#define ADMUX_REFS0      6   //Reference Selection Bit0
#define ADMUX_ADLAR     5   //ADCh Left Adjust Result

/*ADC Control and Status register A*/
#define ADCSRA          *((volatile u8*) 0x26)
#define ADCSRA_ADEN     7  //ADC Enable
#define ADCSRA_ADSC     6  //ADC Start Conversion
#define ADCSRA_ADATE    5  //ADC Auto Trigger Enable
#define ADCSRA_ADIF     4  //ADC Interrupt Flag
#define ADCSRA_ADIE     3  //ADC Interrupt Enable
#define ADCSRA_ADPS2    2  //Prescaler Bit2
#define ADCSRA_ADPS1    1  //Prescaler Bit1
#define ADCSRA_ADPS0    0  //Prescaler Bit0

/*ADC Data register Higher Byte*/
#define ADCH            *((volatile u8*) 0x25)

/*ADC Data Register lower Byte*/ 
#define ADCL            *((volatile u8*) 0x24)
#define ADC             *((volatile u16*) 0x24)


#endif /* _ADC_REGISTER_H_ */
