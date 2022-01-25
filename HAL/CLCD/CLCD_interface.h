

#ifndef _CLCD_INTERFACE_H_
#define _CLCD_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"

void CLCD_Init(void); 
void CLCD_SendString(const char *string);
void CLCD_GoTOXY(const u8 XPos, const u8 YPos);
void CLCD_SendSpecialChar(const u8 *charArray, const u8 charIndex, const u8 XPos, const u8 YPos);
void CLCD_Clear(void);
void CLCD_Blink(void);
char *utoa(u32 value, u8 base);
#endif /* _CLCD_INTERFACE_H_ */
