/* 
 * File:   ecu_dc_motor.c
 * Author: hp
 *
 * Created on 29 ??????, 2023, 11:20 ?
 */

/* Section : Includes*/
#include "ecu_dc_motor.h"




/* Section : Function Definitions */

/**
 * @brief intialize dc motor
 * @param dc_motor
 * @return 
 */
Std_ReturnType dc_motor_initialize(const dc_motor_t *dc_motor)
{
    Std_ReturnType ret = E_OK;
    
    if(NULL == dc_motor)
    {
        ret = E_NOK;
    }
    else
    {
        gpio_pin_intialize(&(dc_motor->dc_motor_pin[0]));
        gpio_pin_intialize(&(dc_motor->dc_motor_pin[1]));
    }
    return ret ;
}

/**
 * @brief move DC motor right
 * @param dc_motor
 * @return 
 */
Std_ReturnType dc_motor_move_right(const dc_motor_t *dc_motor)
{
    Std_ReturnType ret = E_OK;
    
    if(NULL == dc_motor)
    {
        ret = E_NOK;
    }
    else
    {  
        gpio_pin_write_logic(&(dc_motor->dc_motor_pin[0]) , GPIO_HIGH);
        gpio_pin_write_logic(&(dc_motor->dc_motor_pin[1]) , GPIO_LOW);
    } 
    return ret ; 
}

/**
 * @brief move DC motor left
 * @param dc_motor
 * @return 
 */
Std_ReturnType dc_motor_move_left(const dc_motor_t *dc_motor)
{
    Std_ReturnType ret = E_OK;
    
    if(NULL == dc_motor)
    {
        ret = E_NOK;
    }
    else
    {
        gpio_pin_write_logic(&(dc_motor->dc_motor_pin[0]) , GPIO_LOW);
        gpio_pin_write_logic(&(dc_motor->dc_motor_pin[1]) , GPIO_HIGH);
    }
    return ret ;
}

/**
 * @brief stop DC motor   
 * @param dc_motor
 * @return 
 */
Std_ReturnType dc_motor_stop(const dc_motor_t *dc_motor)
{
    Std_ReturnType ret = E_OK;
    
    if(NULL == dc_motor)
    {
        ret = E_NOK;
    }
    else
    {
        gpio_pin_write_logic(&(dc_motor->dc_motor_pin[0]) , GPIO_LOW);
        gpio_pin_write_logic(&(dc_motor->dc_motor_pin[1]) , GPIO_LOW);
    }
    return ret ;
}