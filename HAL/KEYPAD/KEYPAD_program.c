/**
 *
 * @file       KEYPAD_program.c
 * @brief      Contains functions definitions for the keypad 
 * @author     Abdulrahman Aboghanima
 * @date       Mon Aug 15 21:23:19 2022
 * @copyright  Copyright (c) 2022
 * @version    0.1
 * 
 */

#include "KEYPAD_config.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_private.h"
#include "KEYPAD_register.h" 
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"


/*
  Every row is connected to an output pin.
  Every column is connected to an input pin.
  Every key in the keypad is acting as a switch,
  if any key is pressed, the output line will be connected to
  the input line.
  We iterate throw every row and sets it to low,
  then we check the value of the input of every column.
  Since we know which row is set to low and checked for
  every column and know which column now has low input,
  we can discover then pressed keypad !
  
  |------+------+------+------+
  |    7 |    8 |    9 | /    | > ROW0 
  |    4 |    5 |    6 | *    | > ROW1 
  |    1 |    2 |    3 | -    | > ROW2 
  |    O |    0 |    = | +    | > ROW3 
  |------+------+------+------+
      ^      ^      ^     ^             
     COL0   COL1   COL2  COL3          

*/

extern void KEYPAD_init(void)
{

  /*Setting the pins of the rows as high*/
  DIO_SetPinDirection(KEYPAD_PORT, KEYPAD_ROW0, DIO_PIN_OUTPUT);
  DIO_SetPinDirection(KEYPAD_PORT, KEYPAD_ROW1, DIO_PIN_OUTPUT);
  DIO_SetPinDirection(KEYPAD_PORT, KEYPAD_ROW2, DIO_PIN_OUTPUT);
  DIO_SetPinDirection(KEYPAD_PORT, KEYPAD_ROW3, DIO_PIN_OUTPUT);

  /*Setting the pins of the columns as low*/
  DIO_SetPinDirection(KEYPAD_PORT, KEYPAD_COL0, DIO_PIN_INPUT);
  DIO_SetPinDirection(KEYPAD_PORT, KEYPAD_COL1, DIO_PIN_INPUT);
  DIO_SetPinDirection(KEYPAD_PORT, KEYPAD_COL2, DIO_PIN_INPUT);
  DIO_SetPinDirection(KEYPAD_PORT, KEYPAD_COL3, DIO_PIN_INPUT);

  /*Setting the values of the columns pins to high in order to 
    enable the pull-up resistance*/
  DIO_SetPinValue(KEYPAD_PORT, KEYPAD_COL0, DIO_PIN_HIGH);
  DIO_SetPinValue(KEYPAD_PORT, KEYPAD_COL1, DIO_PIN_HIGH);
  DIO_SetPinValue(KEYPAD_PORT, KEYPAD_COL2, DIO_PIN_HIGH);
  DIO_SetPinValue(KEYPAD_PORT, KEYPAD_COL3, DIO_PIN_HIGH);
  
}

extern uint8_t KEYPAD_getPressedKey(void)
{
  uint8_t col_idx, row_idx;
  uint8_t keypad_arr[4][4]=KEYPAD_ARRAY;

  uint8_t keypad_rows[ROW_NUM]={KEYPAD_ROW0, KEYPAD_ROW1, KEYPAD_ROW2, KEYPAD_ROW3};
  uint8_t keypad_cols[COL_NUM]={KEYPAD_COL0, KEYPAD_COL1, KEYPAD_COL2, KEYPAD_COL3};
  
  
  for (row_idx=0; row_idx < ROW_NUM; ++row_idx){

    /*Activate the current row by setting its value to low*/
    DIO_SetPinValue(KEYPAD_PORT, keypad_rows[row_idx], DIO_PIN_LOW);

    /*Iterate through each column*/
    for (col_idx=0; col_idx < COL_NUM; ++col_idx){

      uint8_t curr_state;

      /* Read the value of each column*/
      DIO_GetPinValue(KEYPAD_PORT, keypad_cols[col_idx], &curr_state);

      /*If the value of the current column is low, then it's the pressed key*/
      if(DIO_PIN_LOW==curr_state){
        
	/*Busy Waiting until the pressed key is released*/
	while(DIO_PIN_LOW==curr_state)
	  DIO_GetPinValue(KEYPAD_PORT, keypad_cols[col_idx], &curr_state);  
	
	/* Return the pressed key value associated in the configuration file*/
	return keypad_arr[row_idx][col_idx];
      }
	
    }
    /* Deactivate the current row by setting it to high*/
    DIO_SetPinValue(KEYPAD_PORT, keypad_rows[row_idx], DIO_PIN_HIGH);
  }
  

  return NO_KEY_PRESSED;
}

