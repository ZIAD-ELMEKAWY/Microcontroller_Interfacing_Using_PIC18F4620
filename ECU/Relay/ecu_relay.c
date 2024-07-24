/* 
 * File:   ecu_relay.c
 * Author: hp
 *
 * Created on 21 9, 2023, 03:55 
 */

/* Section : Includes*/
#include "ecu_relay.h" 
/* Section : Function Definitions */

/**
 * @brief initialize the relay
 * @param _relay
 * @return Status of the function 
 *              (E_OK) : The function done successfully
 *              (E_NOK): The function has issue to perform this action
 */
Std_ReturnType relay_initialize( const relay_t *_relay )
{
    Std_ReturnType ret = E_OK ;
    if(NULL == _relay)
    {
        ret = E_NOK;
    }
    else
    {
        pin_config_t pin_obj = 
        {
            .port = _relay->relay_port , 
            .pin = _relay->relay_pin , 
            .direction= GPIO_DIRECTION_OUTPUT , 
            .logic = _relay->relay_status 
        };
        gpio_pin_intialize(&pin_obj);
    }
    return ret;
}

/**
 * @brief turn on the relay
 * @param _relay
 * @return Status of the function 
 *              (E_OK) : The function done successfully
 *              (E_NOK): The function has issue to perform this action
 */
Std_ReturnType relay_turn_on  ( const relay_t *_relay )
{
    Std_ReturnType ret = E_OK ;
    if(NULL == _relay)
    {
        ret = E_NOK;
    }
    else
    {
        pin_config_t pin_obj = 
        {
            .port = _relay->relay_port , 
            .pin = _relay->relay_pin , 
            .direction = GPIO_DIRECTION_OUTPUT , 
            .logic = _relay->relay_status 
        };
        gpio_pin_write_logic(&pin_obj , GPIO_HIGH);
    }
    return ret;
}

/**
 * @brief turn off the relay
 * @param _relay
 * @return Status of the function 
 *              (E_OK) : The function done successfully
 *              (E_NOK): The function has issue to perform this action
 */
Std_ReturnType relay_turn_off ( const relay_t *_relay )
{
    Std_ReturnType ret = E_OK ;
    if(NULL == _relay)
    {
        ret = E_NOK;
    }
    else
    {
         pin_config_t pin_obj = 
        {
            .port = _relay->relay_port , 
            .pin = _relay->relay_pin , 
            .direction = GPIO_DIRECTION_OUTPUT , 
            .logic = _relay->relay_status 
        };
        gpio_pin_write_logic(&pin_obj , GPIO_LOW);
    }
    return ret;
}