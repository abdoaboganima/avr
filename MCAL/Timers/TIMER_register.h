/**
 *
 * @file       TIMER_register.h
 * @brief      Contains Registers definitions for the Timer perigheral
 * @author     Abdulrahman Aboghanima
 * @date       Jan 31 05:35:44 2022
 * @copyright  Copyright (c) 2022
 * @version    0.2
 * 
 */


#ifndef _TIMER_REGISTER_H_
#define _TIMER_REGISTER_H_


#define HW_REG8(x)   *((volatile uint8_t*) x)
#define HW_REG16(x)  *((volatile uint16_t*) x)


/* Timer/counter0 control Register */
#define TCCR0                   HW_REG8(0x53)

#define TCCR0_CS00              0                  /*Prescaler bit0*/
#define TCCR0_CS01              1                  /*Prescaler bit1*/ 
#define TCCR0_CS02              2                  /*Prescaler bit2*/
#define TCCR0_WGM01             3                  /*Waveform Generation Mode bit0*/
#define TCCR0_COM00             4                  /**/
#define TCCR0_COM01             5                  /**/
#define TCCR0_WGM00             6                  /*Waveform Generation Mode bit1*/



/* Timer/ counter register  */
#define TCNT0 HW_REG8(0x52)

/*Output Compare Register 0*/
#define OCR0  HW_REG8(0x5c)        /* Output Compare Register 0  */




/*Timer/Counter Interrupt Mask Register*/
#define TIMSK HW_REG8(0x59)

#define TIMSK_TOIE0             0 /* Timer/Counter0 Overflow Interrupt Enable*/
#define TIMSK_OCIE0             1 /* Timer/Counter0 Output Compare Match Interrupt Enable*/
#define TIMSK_TOIE1             2 /* Timer/Counter1 Overflow Interrupt Enable*/
#define TIMSK_OCIE1B            3
#define TIMSK_OCIE1A            4
#define TIMSK_TICIE1            5 
#define TIMSK_TOIE2             6 /* Timer/Counter2 Overflow Interrupt Enable*/
#define TIMSK_OCIE2             7 /*Timer/Counter1 Output Compare Match Interrupt Enable*/


/*Timer/Counter1 Control Register A*/
#define TCCR1A       HW_REG8(0x4f)

#define TCCR1A_WGM10            0
#define TCCR1A_WGM11            1
#define TCCR1A_FOC1B            2
#define TCCR1A_FOC1A            3
#define TCCR1A_COM1B0           4
#define TCCR1A_COM1B1           5
#define TCCR1A_COM1A0           6
#define TCCR1A_COM1A1           7



/*Timer/Counter1 Control Register B*/
#define TCCR1B       HW_REG8(0x4e)
#define TCCR1B_CS10             0             /**/
#define TCCR1B_CS11             1             /**/
#define TCCR1B_CS12             2             /**/
#define TCCR1B_WGM12            3             /* Waveform Generation Mode. NOTE: Consider Also the Bits of TCCR1A*/
#define TCCR1B_WGM13            4             /* Waveform Generation Mode. NOTE: Consider Also the Bits of TCCR1A*/
#define TCCR1B_ICES1            6             /* Input Capture Edge Select */
#define TCCR1B_ICNC1            7             /* Input Capture Noise Canceler*/





/*Timer/counter1 register*/
#define TCNT1H       HW_REG8(0x4d)
#define TCNT1L       HW_REG8(0x4c)
#define TCNT1        HW_REG16(0x4c)

#define OCR1AH       HW_REG8(0x4b)
#define OCR1AL       HW_REG8(0x4a)
#define OCR1A        HW_REG16(0x4a)
#define OCR1BH       HW_REG8(0x49)
#define OCR1BL       HW_REG8(0x48)
#define OCR1B        HW_REG16(0x48)

#define ICR1H        HW_REG8(0x47)
#define ICR1L        HW_REG8(0x46)
#define ICR1         HW_REG16(0x46)



#define TCCR2        HW_REG8(0x45)


#define TCCR2_CS20   0
#define TCCR2_CS21   1   
#define TCCR2_CS22   2
#define TCCR2_WGM21  3
#define TCCR2_COM20  4
#define TCCR2_COM21  5
#define TCCR2_WGM20  6
#define TCCR2_FOC2   7



#define TCNT2        HW_REG8(0x44)

#endif /* _TIMER_REGISTER_H_ */
