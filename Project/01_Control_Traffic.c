/* 
 * File:   application.c
 * Author: ziad
 *
 * Created on 20 July, 2023
 */

#include "application.h"


led_t led_1 = 
{
    .port_name = PORTC_INDEX ,
    .pin = PIN4 ,
    .led_status = GPIO_LOW
};

led_t led_2 = 
{
    .port_name = PORTC_INDEX ,
    .pin = PIN5 ,
    .led_status = GPIO_LOW
};

led_t led_3 = 
{
    .port_name = PORTC_INDEX ,
    .pin = PIN6 ,
    .led_status = GPIO_LOW
};

segment_t segment_1 =
{
    .segment_pins[0].port = PORTC_INDEX ,
    .segment_pins[0].pin  = PIN0 ,
    .segment_pins[0].direction = GPIO_DIRECTION_OUTPUT ,
    .segment_pins[0].logic = GPIO_LOW ,
    
    .segment_pins[1].port = PORTC_INDEX ,
    .segment_pins[1].pin  = PIN1 ,
    .segment_pins[1].direction = GPIO_DIRECTION_OUTPUT ,
    .segment_pins[1].logic = GPIO_LOW ,
    
    .segment_pins[2].port = PORTC_INDEX ,
    .segment_pins[2].pin  = PIN2 ,
    .segment_pins[2].direction = GPIO_DIRECTION_OUTPUT ,
    .segment_pins[2].logic = GPIO_LOW ,
    
    .segment_pins[3].port = PORTC_INDEX ,
    .segment_pins[3].pin  = PIN3 ,
    .segment_pins[3].direction = GPIO_DIRECTION_OUTPUT ,
    .segment_pins[3].logic = GPIO_LOW ,
    .segment_type = SEGMENT_COMMON_CATHODE
};

int main() 
{
    Std_ReturnType ret = E_NOK ;
    uint8 counter = 0;
    application_initialize();
    ret = led_intialize(&led_1);
    ret = led_intialize(&led_2);
    ret = led_intialize(&led_3);
    ret = Seven_Segment_Initialize(&segment_1);
    
    while(1)
    {
        ret = led_turn_on(&led_1);
        __delay_ms(500);
        for (counter = 0 ; counter <= 9 ; counter++)
        {
            ret = Seven_Segment_Write_Number(&segment_1 , counter) ;
            __delay_ms(500);
        }
        ret = led_turn_off(&led_1);     
        ret = led_turn_on(&led_2);
        __delay_ms(500);
        for (counter = 0 ; counter <= 5 ; counter++)
        {
            ret = Seven_Segment_Write_Number(&segment_1 , counter) ;
            __delay_ms(500);
        }
        ret = led_turn_off(&led_1);
        ret = led_turn_off(&led_2);
        ret = led_turn_on(&led_3);
        __delay_ms(500);
        for (counter = 0 ; counter <= 9 ; counter++)
        {
            ret = Seven_Segment_Write_Number(&segment_1 , counter) ;
            __delay_ms(500);
        }
        ret = led_turn_off(&led_1);
        ret = led_turn_off(&led_2);
        ret = led_turn_off(&led_3);
    }
    return (EXIT_SUCCESS);
}

void application_initialize (void)
{
    Std_ReturnType ret = E_NOK ;
    ecu_layer_initialize();
}

