/* 
 * File:   ecu_led.c
 * Author: ziad
 *
 * Created on 09 ?????, 2023, 10:18 ?
 */

/*Section: Includes */
#include "ecu_led.h"

/* Section:  function Definition */
/**
 * @brief Initialized the assigned pin to be output and turn the led off
 * @param led
 * @return status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOK): the function has issue while performing this action
 */
#if GPIO_PORT_PIN_CONFIGURATIONS==CONFIG_ENABLE 
Std_ReturnType led_intialize(const led_t *led)
{
    Std_ReturnType ret = E_OK;
    
    if(NULL == led)
    {
        ret = E_NOK;
    }
    else
    {
        pin_config_t pin_obj = 
        {
        .port = led->port_name , 
        .pin = led->pin , 
        .direction= GPIO_DIRECTION_OUTPUT , 
        .logic = led->led_status 
        };
        gpio_pin_intialize(&pin_obj);
    }
    return ret ;
}
#endif

/**
 * @brief Turn the led on
 * @param led
 * @return status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOK): the function has issue while performing this action
 */
#if GPIO_PORT_PIN_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType led_turn_on  (const led_t *led)
{
    Std_ReturnType ret = E_OK;
    if(NULL == led)
    {
        ret = E_NOK;
    }
    else
    {
        pin_config_t pin_obj = 
        {
        .port = led->port_name , 
        .pin = led->pin , 
        .direction= GPIO_DIRECTION_OUTPUT , 
        .logic = led->led_status 
        };
        gpio_pin_write_logic(&pin_obj , GPIO_HIGH);
    }
    return ret ;
}
#endif

/**
 * @brief Turn the led off
 * @param led
 * @return status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOK): the function has issue while performing this action
 */
#if GPIO_PORT_PIN_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType led_turn_off (const led_t *led)
{
    Std_ReturnType ret = E_OK;
    if(NULL == led)
    {
        ret = E_NOK;
    }
    else
    {
        pin_config_t pin_obj = 
        {
        .port = led->port_name , 
        .pin = led->pin , 
        .direction= GPIO_DIRECTION_OUTPUT , 
        .logic = led->led_status 
        };
        gpio_pin_write_logic(&pin_obj , GPIO_LOW);
    }
    return ret ;
}
#endif

/**
 * @brief Toggle the led 
 * @param led
 * @return status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOK): the function has issue while performing this action
 */
#if GPIO_PORT_PIN_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType led_toggle   (const led_t *led)
{
    Std_ReturnType ret = E_OK;
    if(NULL == led)
    {
        ret = E_NOK;
    }
    else
    {
        pin_config_t pin_obj = 
        {
        .port = led->port_name , 
        .pin = led->pin , 
        .direction= GPIO_DIRECTION_OUTPUT , 
        .logic = led->led_status 
        };
        gpio_pin_toggle_logic(&pin_obj);
    }
    return ret ;
}
#endif