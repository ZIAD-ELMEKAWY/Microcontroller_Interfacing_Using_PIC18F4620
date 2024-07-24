/* 
 * File:   hal_GPIO.c
 * Author: ziad
 *
 * Created on 09 ?????, 2023, 09:50 ?
 */

#include "hal_GPIO.h"
/* REFRENCE TO THE DATA DIRECTION CONTROL REGISTER */
volatile uint8 *tris_register[] = {&TRISA , &TRISB , &TRISC , &TRISD , &TRISE};
/* REFRENCE TO THE DATA LATCH REGISTER ( READ AND WRITE TO DATA LATCH )*/
volatile uint8 *lat_register[]  = {&LATA , &LATB , &LATC , &LATD , &LATE};
/* REFRENCE TO THE PORT STATUS REGISTER */
volatile uint8 *port_register[] = {&PORTA , &PORTB , &PORTC , &PORTD , &PORTE};

/* Section : Function Definitions */

/**
 * 
 * @param _pin_config points to the configuration 
 * @ref   pin_config_t 
 * @return Status of the function 
 *              (E_OK) : The function done successfully
 *              (E_NOK): The function has issue to perform this action
 */
#if GPIO_PORT_PIN_CONFIGURATIONS==CONFIG_ENABLE              // Lock to activate pin configuration
Std_ReturnType gpio_pin_direction_intialize(const pin_config_t *_pin_config)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1 )
    {
        ret = E_NOK;          // if pointer equals to NULL            
    }
    else
    {
        switch(_pin_config->direction)
        {
            case GPIO_DIRECTION_OUTPUT:
                CLEAR_BIT(*tris_register[_pin_config->port] , _pin_config->pin);
                break;
            case GPIO_DIRECTION_INPUT:
                SET_BIT(*tris_register[_pin_config->port] , _pin_config->pin);
                break;
            default:
                ret = E_NOK;          // if input is not correct  
        }
    }
    return ret;
}
#endif

/**
 * @prief Initialize the direction of a specific pin @ref   direction_t
 * @param _pin_config points to the configuration    @ref   pin_config_t 
 * @param direction_status
 * @return 
 */
#if GPIO_PORT_PIN_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config , direction_t *direction_status)
{
    Std_ReturnType ret = E_OK; 
    if (NULL == _pin_config || NULL == direction_status || _pin_config->pin > PORT_PIN_MAX_NUMBER-1)
    {
        ret = E_NOK;          // if pointer equals to NULL            
    }
    else
    {
        *direction_status = READ_BIT(*tris_register[_pin_config->port] , _pin_config->pin);
        
    }
    
    return ret;
}
#endif

/**
 * 
 * @param _pin_config points to the configuration 
 * @ref   pin_config_t 
 * @param logic
 * @return 
 */
#if GPIO_PORT_PIN_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config , logic_t logic)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1 )
    {
        ret = E_NOK;          // if pointer equals to NULL            
    }
    else
    {
        switch(logic)
        {
            case GPIO_LOW:
                CLEAR_BIT(*lat_register[_pin_config->port] , _pin_config->pin);
                break;
            case GPIO_HIGH:
                SET_BIT(*lat_register[_pin_config->port] , _pin_config->pin);
                break;
            default: ret = E_NOK ;
        }
    }
    return ret;
}
#endif

/**
 * 
 * @param _pin_config points to the configuration 
 * @ref   pin_config_t 
 * @param logic
 * @return 
 */
#if GPIO_PORT_PIN_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config , logic_t *logic)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config || NULL == logic || _pin_config->pin > PORT_PIN_MAX_NUMBER-1 )
    {
        ret = E_NOK;          // if pointer equals to NULL            
    }
    else
    {
        *logic = READ_BIT(*port_register[_pin_config->port] , _pin_config->pin);
        
    }
    return ret;
}
#endif

/**
 * 
 * @param _pin_config points to the configuration 
 * @ref   pin_config_t 
 * @return 
 */
#if GPIO_PORT_PIN_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1 )
    {
        ret = E_NOK;          // if pointer equals to NULL            
    }
    else
    {
        TOGGLE_BIT(*port_register[_pin_config->port] , _pin_config->pin);
    }
    return ret;
}
#endif

/**
 * 
 * @param _pin_config points to the configuration 
 * @ref   pin_config_t 
 * @return 
 */
#if GPIO_PORT_PIN_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_pin_intialize(const pin_config_t *_pin_config)
{
    Std_ReturnType ret = E_OK;
    if(NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1)
    {
        ret = E_NOK ;
    }
    else
    {
        ret = gpio_pin_direction_intialize(_pin_config);
        ret = gpio_pin_write_logic(_pin_config , _pin_config->logic);
    }
    return ret;
}
#endif 


/**
 * 
 * @param port
 * @param direction
 * @return 
 */
#if GPIO_PORT_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_port_direction_intialize(port_index_t port , uint8 direction )
{
    Std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1)
    {
        ret = E_NOK;
    }
    else
    {
        *tris_register[port] = direction ;
    }
    return ret;
}
#endif

/**
 * 
 * @param port
 * @param direction_status
 * @return 
 */
#if GPIO_PORT_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_port_get_direction_status (port_index_t port , uint8 *direction_status)
{
    Std_ReturnType ret = E_OK;
    if (NULL == direction_status && (port > PORT_MAX_NUMBER-1))
    {
        ret = E_NOK;          // if pointer equals to NULL            
    }
    else
    {
        *direction_status = *tris_register[port];
    }
    return ret;
}
#endif

/**
 * 
 * @param port
 * @param logic
 * @return 
 */

#if GPIO_PORT_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_port_write_logic (port_index_t port , uint8 logic)
{
    Std_ReturnType ret = E_OK;
    if (port > PORT_MAX_NUMBER - 1)
    {
        ret = E_NOK;
    }
    else
    {
        *lat_register[port] = logic;
    }
    return ret;
}
#endif

/**
 * 
 * @param port
 * @param logic
 * @return 
 */

#if GPIO_PORT_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_port_read_logic(port_index_t port , uint8 *logic)
{
    Std_ReturnType ret = E_OK;
    if ( NULL == logic && (port > PORT_MAX_NUMBER-1))
    {
        ret = E_NOK;          // if pointer equals to NULL            
    }
    else
    {
        *logic = lat_register[port];
        
    }    
    return ret;
}
#endif

/**
 * 
 * @param port
 * @return 
 */

#if GPIO_PORT_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_port_toggle_logic(port_index_t port)
{
    Std_ReturnType ret = E_OK;
    if (port > PORT_MAX_NUMBER-1)
    {
        ret = E_NOK;          // if pointer equals to NULL            
    }
    else
    {
         *lat_register[port] ^= PORTC_MASK;
    }    
    return ret;
}

#endif