/* 
 * File:   ecu_keypad.c
 * Author: Ziad
 *
 * Created on 23 jun, 2024, 10:51 ?
 */


#include "ecu_keypad.h"


static const uint8 btn_values [ECU_KEYPAD_ROW][ECU_KEYPAD_COLUMN]=
{
    {'7' , '8' , '9' , '/'},
    {'4' , '5' , '6' , '*'},
    {'1' , '2' , '3' , '-'},
    {'#' , '0' , '=' , '+'}
};

/**
 * @name   Keypad_initialize
 * @param  keypad_obj 
 * @return Status of the function 
 *              (E_OK) : The function done successfully
 *              (E_NOK): The function has issue to perform this action
 */
Std_ReturnType Keypad_initialize(const keypad_t *keypad_obj)
{
    Std_ReturnType ret = E_OK ;
    uint8 rows_counter    = 0 ;
    uint8 columns_counter = 0 ;
    if(NULL == keypad_obj)
    {
        ret = E_NOK;
    }
    else
    {
        for(rows_counter =0 ; rows_counter<ECU_KEYPAD_ROW ; rows_counter++ )
        {
            ret = gpio_pin_intialize(&(keypad_obj->keypad_row_pins[rows_counter]));
        }
        for(columns_counter =0 ; columns_counter<ECU_KEYPAD_COLUMN ; columns_counter++ )
        {
            ret = gpio_pin_direction_intialize(&(keypad_obj->keypad_column_pins[columns_counter]));
        }
    }
    return ret;
    
}

/**
 * @name   Keypad_get_value
 * @param  keypad_obj , value
 * @return Std_ReturnTypeStatus of the function 
 *              (E_OK) : The function done successfully
 *              (E_NOK): The function has issue to perform this action
 */
Std_ReturnType Keypad_get_value (const keypad_t *keypad_obj , uint8 *value)
{
    Std_ReturnType ret = E_OK ;
    uint8 rows_counter    , columns_counter  , l_counter;
    uint8 column_logic = 0 ;
    if((NULL == keypad_obj) || (NULL == value))
    {
        ret = E_NOK;
    }
    else
    {
        for (rows_counter = 0; rows_counter < ECU_KEYPAD_ROW ; rows_counter++) 
        {
            for(l_counter = 0; l_counter < ECU_KEYPAD_ROW ; l_counter++)
            {
                ret = gpio_pin_write_logic(&(keypad_obj->keypad_row_pins[l_counter]) , GPIO_LOW);
            }
            gpio_pin_write_logic(&(keypad_obj->keypad_row_pins[rows_counter]) , GPIO_HIGH);
            for (columns_counter = 0; columns_counter < ECU_KEYPAD_COLUMN ; columns_counter++) 
            {
                ret = gpio_pin_read_logic(&(keypad_obj->keypad_column_pins[columns_counter]) , &column_logic);
                if(column_logic == GPIO_HIGH)
                {
                    *value = btn_values [rows_counter][columns_counter] ; 
                }
            }
        }
    }
    return ret; 
}

// Helper function
uint8 Keypad_Convert_from_char_to_int (uint8 value)
{
    uint8 ret = 0 ;
    switch(value)
    {
        case '0': ret = 0 ; break;
        case '1': ret = 1 ; break;
        case '2': ret = 2 ; break;
        case '3': ret = 3 ; break;
        case '4': ret = 4 ; break;
        case '5': ret = 5 ; break;
        case '6': ret = 6 ; break;
        case '7': ret = 7 ; break;
        case '8': ret = 8 ; break;
        case '9': ret = 9 ; break;
        default : ret =10 ; break;    
    }
    return ret;
}