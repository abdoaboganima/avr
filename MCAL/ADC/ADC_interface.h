#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"
void ADC_init(void);
void ADC_StartSynchConversion(u8 channel, u16 *reading);
void ADC_StartAsynchConversion(u8 channel, u16 *reading, void (*callBackFunction)(void));

#define DIV_BY_2      1
#define DIV_BY_4      2
#define DIV_BY_8      3
#define DIV_BY_16     4
#define DIV_BY_32     5
#define DIV_BY_64     6
#define DIV_BY_128    7


#endif /* _ADC_INTERFACE_H_ */
