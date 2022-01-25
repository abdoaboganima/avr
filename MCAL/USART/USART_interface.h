#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "USART_register.h"



void USART_init(void);
u8 USART_receive(void);
void USART_send(u8 data);
void USART_sendStream(char *stream);
