/**
 *
 * @file       DIO_program.c
 * @brief      Contains functions definitions of the `DIO` Module
 * @author     Abdulrahman Aboghanima
 * @date       Tue Aug 18 18:01:26 2021
 * @copyright  Copyright (c) 2022
 * @version    0.3
 * 
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_register.h"

uint8_t DIO_SetPinDirection(DIO_Port_t Port, DIO_Pin_t Pin, DIO_PinState_t Direction)
{
  uint8_t Local_ErrorState=0;
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
uint8_t DIO_SetPortDirection(DIO_Port_t Port, DIO_PinState_t Direction)
{
  uint8_t Local_ErrorState=0;

  switch(Port){
  case DIO_PORTA: DDRA = Direction; break;
  case DIO_PORTB: DDRB = Direction; break;
  case DIO_PORTC: DDRC = Direction; break;
  case DIO_PORTD: DDRD = Direction; break;
  default: Local_ErrorState=1; break;
  }

  return Local_ErrorState;
}

uint8_t DIO_SetPinValue(DIO_Port_t Port, DIO_Pin_t Pin, DIO_PinValue_t Value)
{
  uint8_t Local_ErrorState=0;
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

uint8_t DIO_TogglePinValue(DIO_Port_t Port, DIO_Pin_t Pin)
{
  uint8_t Local_ErrorState=0;

  if(Pin<=DIO_PIN7){  
    switch(Port){                             
    case DIO_PORTA: TOGGLE_BIT(PORTA, Pin); break;
    case DIO_PORTB: TOGGLE_BIT(PORTB, Pin); break;
    case DIO_PORTC: TOGGLE_BIT(PORTC, Pin); break;
    case DIO_PORTD: TOGGLE_BIT(PORTD, Pin); break;
    default: Local_ErrorState=1; break;            
    }
  }
  
  return Local_ErrorState;
}

uint8_t DIO_SetPortValue(DIO_Port_t Port, uint8_t Value)
{
  uint8_t Local_ErrorState=0;
        
  switch(Port){                                   
  case DIO_PORTA: PORTA=Value; break;   
  case DIO_PORTB: PORTB=Value; break;   
  case DIO_PORTC: PORTC=Value; break;   
  case DIO_PORTD: PORTD=Value; break;   
  default: Local_ErrorState=1; break;                  
  }                                                      

  
  return Local_ErrorState;
}

uint8_t DIO_GetPinValue(DIO_Port_t Port, DIO_Pin_t Pin, DIO_PinValue_t *puint8_tValue)
{
  uint8_t Local_ErrorState=0;

  if((Pin <= DIO_PIN7 ) && (puint8_tValue!=NULL))
    switch(Port){                        
    case DIO_PORTA: *puint8_tValue=GET_BIT(PINA, Pin); break;
    case DIO_PORTB: *puint8_tValue=GET_BIT(PINB, Pin); break;
    case DIO_PORTC: *puint8_tValue=GET_BIT(PINC, Pin); break;
    case DIO_PORTD: *puint8_tValue=GET_BIT(PIND, Pin); break;
    default: Local_ErrorState=1; break;       
    }
  else
    Local_ErrorState=1;
  return Local_ErrorState;
}
