/* 
 * File:   ecu_button.c
 * Author: hp
 *
 * Created on 05 ??????, 2023, 04:19 ?
 */

/* Section : Includes*/
#include "ecu_button.h"

/* Section : Function Definitions */
/**
 * @brief Initialize the assigned pin to be input
 * @param btn
 * @return Status of the function 
 *              (E_OK) : The function done successfully
 *              (E_NOK): The function has issue to perform this action
 */

Std_ReturnType button_intialize(const button_t *btn )
{
    Std_ReturnType ret = E_OK ;
    if(NULL == btn)
    {
        ret = E_NOK;
    }
    else
    {
        ret = gpio_pin_direction_intialize(&btn->button_pin);
    }
    return ret;
}

/**
 * @brief Read the state of the button
 * @param btn
 * @param btn_state
 * @return Status of the function 
 *              (E_OK) : The function done successfully
 *              (E_NOK): The function has issue to perform this action
 */

Std_ReturnType button_read_status(const button_t *btn , button_state_t *btn_state)
{
    Std_ReturnType ret = E_OK ;
    logic_t Pin_Logic_Status = GPIO_LOW ;
    if((NULL == btn) || ( NULL == btn_state))
    {
        ret = E_NOK;
    }
    else
    {
        gpio_pin_read_logic(&(btn->button_pin) , &Pin_Logic_Status );
        if(BUTTON_ACTIVE_HIGH == btn->button_connection)
        {
            if(GPIO_HIGH == Pin_Logic_Status)
            {
                *btn_state = BUTTON_PRESSED;
            }
            else
            {
                *btn_state = BUTTON_RELEASED;
            }
        }
        else if(BUTTON_ACTIVE_LOW == btn->button_connection)
        {
            if(GPIO_HIGH == Pin_Logic_Status)
            {
                *btn_state = BUTTON_RELEASED;
            }
            else
            {
                *btn_state = BUTTON_PRESSED;
            }
        }
        else{/*nothing*/}
        ret = E_OK;
    }
    return ret;
}