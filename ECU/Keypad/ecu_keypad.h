/* 
 * File:   ecu_keypad.h
 * Author: hp
 *
 * Created on 23 ?????, 2024, 10:51 ?
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

/*************** Section : includes ***************/
#include "ecu_keypad_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_GPIO.h"

/*************** Section : Macro Declarations ***************/
#define ECU_KEYPAD_ROW      4
#define ECU_KEYPAD_COLUMN   4
/*************** Section : Macro Function Declarations ***************/

/*************** Section : Data Type Declarations ***************/
typedef struct 
{
    pin_config_t keypad_row_pins[ECU_KEYPAD_ROW];
    pin_config_t keypad_column_pins[ECU_KEYPAD_COLUMN];
}keypad_t;


/*************** Section : Function Declarations  ***************/
Std_ReturnType Keypad_initialize(const keypad_t *keypad_obj);
Std_ReturnType Keypad_get_value (const keypad_t *keypad_obj , uint8 *value);

// Helper function
uint8 Keypad_Convert_from_char_to_int (uint8 value);

#endif	/* ECU_KEYPAD_H */

