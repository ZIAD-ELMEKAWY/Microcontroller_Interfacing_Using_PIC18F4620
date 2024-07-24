/* 
 * File:   ECU_Layer_Init.h
 * Author: Ziad
 *
 * Created on 24 june, 2024, 07:52 ?
 */

#include "ECU_Layer_Init.h"

/******************************** keypad object ********************/
/*
keypad_t Keypad_1 = 
{ 
    // Rows
    .keypad_row_pins[0].port = PORTC_INDEX ,
    .keypad_row_pins[0].pin = PIN0 ,
    .keypad_row_pins[0].direction = GPIO_DIRECTION_OUTPUT ,
    .keypad_row_pins[0].logic = GPIO_LOW , 
            
    .keypad_row_pins[1].port = PORTC_INDEX ,
    .keypad_row_pins[1].pin = PIN1 ,
    .keypad_row_pins[1].direction = GPIO_DIRECTION_OUTPUT ,
    .keypad_row_pins[1].logic = GPIO_LOW,
            
    .keypad_row_pins[2].port = PORTC_INDEX ,
    .keypad_row_pins[2].pin = PIN2 ,
    .keypad_row_pins[2].direction = GPIO_DIRECTION_OUTPUT ,
    .keypad_row_pins[2].logic = GPIO_LOW,
            
    .keypad_row_pins[3].port = PORTC_INDEX ,
    .keypad_row_pins[3].pin = PIN3 ,
    .keypad_row_pins[3].direction = GPIO_DIRECTION_OUTPUT ,
    .keypad_row_pins[3].logic = GPIO_LOW,
    
    // Columns 
    .keypad_column_pins[0].port = PORTC_INDEX ,
    .keypad_column_pins[0].pin = PIN4 ,
    .keypad_column_pins[0].direction =  GPIO_DIRECTION_INPUT,
    .keypad_column_pins[0].logic = GPIO_LOW , 
            
    .keypad_column_pins[1].port = PORTC_INDEX ,
    .keypad_column_pins[1].pin = PIN5 ,
    .keypad_column_pins[1].direction = GPIO_DIRECTION_INPUT ,
    .keypad_column_pins[1].logic = GPIO_LOW,
            
    .keypad_column_pins[2].port = PORTC_INDEX ,
    .keypad_column_pins[2].pin = PIN6 ,
    .keypad_column_pins[2].direction = GPIO_DIRECTION_INPUT ,
    .keypad_column_pins[2].logic = GPIO_LOW,
            
    .keypad_column_pins[3].port = PORTC_INDEX ,
    .keypad_column_pins[3].pin = PIN7 ,
    .keypad_column_pins[3].direction = GPIO_DIRECTION_INPUT ,
    .keypad_column_pins[3].logic = GPIO_LOW,
};
*/
/******************************** LCD object ********************/
/*
// LCD 4-Bit
chr_lcd_4bit_t lcd_1 =
{ 
    .lcd_data[0].port  = PORTD_INDEX ,
    .lcd_data[0].pin = PIN0 ,
    .lcd_data[0].direction = GPIO_DIRECTION_OUTPUT ,
    .lcd_data[0].logic = GPIO_LOW ,
    
    .lcd_data[1].port  = PORTD_INDEX ,
    .lcd_data[1].pin = PIN1 ,
    .lcd_data[1].direction = GPIO_DIRECTION_OUTPUT ,
    .lcd_data[1].logic = GPIO_LOW ,
    
    .lcd_data[2].port  = PORTD_INDEX ,
    .lcd_data[2].pin = PIN2 ,
    .lcd_data[2].direction = GPIO_DIRECTION_OUTPUT ,
    .lcd_data[2].logic = GPIO_LOW ,
    
    .lcd_data[3].port  = PORTD_INDEX ,
    .lcd_data[3].pin = PIN3 ,
    .lcd_data[3].direction = GPIO_DIRECTION_OUTPUT ,
    .lcd_data[3].logic = GPIO_LOW ,
    
    .lcd_rs = PORTD_INDEX ,
    .lcd_rs.pin = PIN4 ,
    .lcd_rs.direction = GPIO_DIRECTION_OUTPUT ,
    .lcd_rs.logic = GPIO_LOW ,
    
    .lcd_en = PORTD_INDEX ,
    .lcd_en.pin = PIN5 ,
    .lcd_en.direction = GPIO_DIRECTION_OUTPUT ,
    .lcd_en.logic = GPIO_LOW 
};

// LCD 8-Bit
chr_lcd_8bit_t lcd_2 =
{
    .lcd_rs = PORTC_INDEX ,
    .lcd_rs.pin = PIN6 ,
    .lcd_rs.direction = GPIO_DIRECTION_OUTPUT ,
    .lcd_rs.logic = GPIO_LOW ,
    
    .lcd_en = PORTC_INDEX ,
    .lcd_en.pin = PIN7 ,
    .lcd_en.direction = GPIO_DIRECTION_OUTPUT ,
    .lcd_en.logic = GPIO_LOW , 
    
    .lcd_data[0].port  = PORTD_INDEX ,
    .lcd_data[0].pin = PIN0 ,
    .lcd_data[0].direction = GPIO_DIRECTION_OUTPUT ,
    .lcd_data[0].logic = GPIO_LOW ,
    
    .lcd_data[1].port  = PORTD_INDEX ,
    .lcd_data[1].pin = PIN1 ,
    .lcd_data[1].direction = GPIO_DIRECTION_OUTPUT ,
    .lcd_data[1].logic = GPIO_LOW ,
    
    .lcd_data[2].port  = PORTD_INDEX ,
    .lcd_data[2].pin = PIN2 ,
    .lcd_data[2].direction = GPIO_DIRECTION_OUTPUT ,
    .lcd_data[2].logic = GPIO_LOW ,
    
    .lcd_data[3].port  = PORTD_INDEX ,
    .lcd_data[3].pin = PIN3 ,
    .lcd_data[3].direction = GPIO_DIRECTION_OUTPUT ,
    .lcd_data[3].logic = GPIO_LOW ,
    
    .lcd_data[4].port  = PORTD_INDEX ,
    .lcd_data[4].pin = PIN4 ,
    .lcd_data[4].direction = GPIO_DIRECTION_OUTPUT ,
    .lcd_data[4].logic = GPIO_LOW ,
    
    .lcd_data[5].port  = PORTD_INDEX ,
    .lcd_data[5].pin = PIN5 ,
    .lcd_data[5].direction = GPIO_DIRECTION_OUTPUT ,
    .lcd_data[5].logic = GPIO_LOW ,
    
    .lcd_data[6].port  = PORTD_INDEX ,
    .lcd_data[6].pin = PIN6 ,
    .lcd_data[6].direction = GPIO_DIRECTION_OUTPUT ,
    .lcd_data[6].logic = GPIO_LOW ,
    
    .lcd_data[7].port  = PORTD_INDEX ,
    .lcd_data[7].pin = PIN7 ,
    .lcd_data[7].direction = GPIO_DIRECTION_OUTPUT ,
    .lcd_data[7].logic = GPIO_LOW 
};
*/
/******************************** LED object ********************/

/******************************** Seven Segment object ********************/



void ecu_layer_initialize (void)
{
    Std_ReturnType ret = E_NOK ;
    //ret = Keypad_initialize(&Keypad_1);
    //ret = LCD_4bit_Initialize(&(lcd_1));
    //ret = LCD_8bit_Initialize(&(lcd_2));
    
}