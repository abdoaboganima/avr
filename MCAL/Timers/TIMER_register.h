#ifndef _TIMER_REGISTER_H_
#define _TIMER_REGISTER_H_
#include "../../LIB/STD_TYPES.h"



#define TCCR0 *((volatile u8*) 0x53)   //  Timer/counter0 control Registr

#define TCCR0_CS00              0                  /*Prescaler bit0*/
#define TCCR0_CS01              1                  /*Prescaler bit1*/ 
#define TCCR0_CS02              2                  /*Prescaler bit2*/
#define TCCR0_WGM01             3                  /*Waveform Generation Mode bit0*/
#define TCCR0_COM00             4                  /**/
#define TCCR0_COM01             5                  /**/
#define TCCR0_WGM00             6                  /*Waveform Generation Mode bit1*/

#define TCNT0 *((volatile u8*) 0x52)   /* Timer/ counter register  */

/*Output Compare Register 0*/
#define OCR0  *((volatile u8*) 0x5c)        /* Output Compare Register 0  */

#define TIMSK *((volatile u8*) 0x59)    /*Timer/Counter Interrupt Mask Register*/
#define TIMSK_OCIE0             1       /*Timer/Counter0 Output Compare Match Interrupt Enable*/
#define TIMSK_TICIE1            5 


#define TCCR1A       *((volatile u8*)  0x4f)
#define TCCR1B       *((volatile u8*)  0x4e)

#define TCCR1A_WGM10            0
#define TCCR1A_WGM11            1
#define TCCR1A_FOC1B            2
#define TCCR1A_FOC1A            3
#define TCCR1A_COM1B0           4
#define TCCR1A_COM1B1           5
#define TCCR1A_COM1A0           6
#define TCCR1A_COM1A1           7

#define TCCR1B_CS10             0             /**/
#define TCCR1B_CS11             1             /**/
#define TCCR1B_CS12             2             /**/
#define TCCR1B_WGM12            3             /* Waveform Generation Mode. NOTE: Consider Also the Bits of TCCR1A*/
#define TCCR1B_WGM13            4             /* Waveform Generation Mode. NOTE: Consider Also the Bits of TCCR1A*/
#define TCCR1B_ICES1            6             /* Input Capture Edge Select */
#define TCCR1B_ICNC1            7             /* Input Capture Noise Canceler*/





/*Timer/counter1 register*/
#define TCNT1H       *((volatile u8*)  0x4d)
#define TCNT1L       *((volatile u8*)  0x4c)
#define TCNT1        *((volatile u16*) 0x4c)

#define OCR1AH       *((volatile u8*)  0x4b)
#define OCR1AL       *((volatile u8*)  0x4a)
#define OCR1A        *((volatile u16*) 0x4a)
#define OCR1BH       *((volatile u8*)  0x49)
#define OCR1BL       *((volatile u8*)  0x48)
#define OCR1B        *((volatile u16*) 0x48)

#define ICR1H        *((volatile u8*)   0x47)
#define ICR1L        *((volatile u8*)   0x46)
#define ICR1         *((volatile u16*)  0x46)
//#define         *((volatile u8*))

#endif /* _TIMER_REGISTER_H_ */
