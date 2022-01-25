#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_register.h"

u8 DIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction)
{
  u8 Local_ErrorState=0;
  if(Pin<=DIO_PIN7){
    
    if(Direction==DIO_PIN_INPUT){
      switch(Port){
      case DIO_PORTA: CLEAR_BIT(DDRA, Pin); break;
      case DIO_PORTB: CLEAR_BIT(DDRB, Pin); break;
      case DIO_PORTC: CLEAR_BIT(DDRC, Pin); break;
      case DIO_PORTD: CLEAR_BIT(DDRD, Pin); break;
      default: Local_ErrorState=1; break;
      }
    }
    else if(Direction==DIO_PIN_OUTPUT){
      switch(Port){
      case DIO_PORTA: SET_BIT(DDRA, Pin); break;
      case DIO_PORTB: SET_BIT(DDRB, Pin); break;
      case DIO_PORTC: SET_BIT(DDRC, Pin); break;
      case DIO_PORTD: SET_BIT(DDRD, Pin); break;
      default: Local_ErrorState=1; break;
      }
    }
    else
      Local_ErrorState=1;
  }
  else
    Local_ErrorState=1;

  return Local_ErrorState;
}
u8 DIO_SetPortDirection(u8 Port, u8 Direction)
{
  u8 Local_ErrorState=0;

  switch(Port){
  case DIO_PORTA: DDRA = Direction; break;
  case DIO_PORTB: DDRB = Direction; break;
  case DIO_PORTC: DDRC = Direction; break;
  case DIO_PORTD: DDRD = Direction; break;
  default: Local_ErrorState=1; break;
  }

  return Local_ErrorState;
}
u8 DIO_SetPinValue(u8 Port, u8 Pin, u8 Value)
{
  u8 Local_ErrorState=0;
  if(Pin<=DIO_PIN7){
    
    if(Value==DIO_PIN_HIGH){
      switch(Port){                             
      case DIO_PORTA: SET_BIT(PORTA, Pin); break;
      case DIO_PORTB: SET_BIT(PORTB, Pin); break;
      case DIO_PORTC: SET_BIT(PORTC, Pin); break;
      case DIO_PORTD: SET_BIT(PORTD, Pin); break;
      default: Local_ErrorState=1; break;            
      }
    }
    else if(Value==DIO_PIN_LOW){
      switch(Port){                                       
      case DIO_PORTA: CLEAR_BIT(PORTA, Pin); break; 
      case DIO_PORTB: CLEAR_BIT(PORTB, Pin); break; 
      case DIO_PORTC: CLEAR_BIT(PORTC, Pin); break; 
      case DIO_PORTD: CLEAR_BIT(PORTD, Pin); break; 
      default: Local_ErrorState=1; break;                       
      }
    }
    else
      Local_ErrorState=1;
  }
  else
    Local_ErrorState=1;
  
  return Local_ErrorState;
}
u8 DIO_SetPortValue(u8 Port, u8 Value)
{
  u8 Local_ErrorState=0;
        
  switch(Port){                                   
  case DIO_PORTA: PORTA=Value; break;   
  case DIO_PORTB: PORTB=Value; break;   
  case DIO_PORTC: PORTC=Value; break;   
  case DIO_PORTD: PORTD=Value; break;   
  default: Local_ErrorState=1; break;                  
  }                                                      

  
  return Local_ErrorState;
}
u8 DIO_GetPinValue(u8 Port, u8 Pin, u8 *pu8Value)
{
  u8 Local_ErrorState=0;

  if((Pin <= DIO_PIN7 ) && (pu8Value!=NULL))
    switch(Port){                        
    case DIO_PORTA: *pu8Value=GET_BIT(PINA, Pin); break;
    case DIO_PORTB: *pu8Value=GET_BIT(PINB, Pin); break;
    case DIO_PORTC: *pu8Value=GET_BIT(PINC, Pin); break;
    case DIO_PORTD: *pu8Value=GET_BIT(PIND, Pin); break;
    default: Local_ErrorState=1; break;       
    }
  else
    Local_ErrorState=1;
  return Local_ErrorState;
}
