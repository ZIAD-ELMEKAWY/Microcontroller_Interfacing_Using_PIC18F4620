/* 
 * File:   ecu_sev_seg.c
 * Author: Ziad
 * Created on 24 July, 2024, 04:25 
 */

/******************************** Section : Includes **************************/
#include "ecu_sev_seg.h"

/************************** Section : Functions definitions *******************/
Std_ReturnType Seven_Segment_Initialize   (const segment_t *seg)
{
    uint8 seg_counter =0;
    Std_ReturnType ret = E_OK;
    if(NULL == seg)
    {
        ret = E_NOK ; 
    }
    else
    {
        ret = gpio_pin_intialize(&(seg->segment_pins[SEGMENT_PIN0]));
        ret = gpio_pin_intialize(&(seg->segment_pins[SEGMENT_PIN1]));
        ret = gpio_pin_intialize(&(seg->segment_pins[SEGMENT_PIN2]));
        ret = gpio_pin_intialize(&(seg->segment_pins[SEGMENT_PIN3]));
        
    }
    return ret ;
}
Std_ReturnType Seven_Segment_Write_Number (const segment_t *seg , uint8 number)
{
    Std_ReturnType ret = E_OK;
    if((NULL == seg) && (number > 9))
    {
        ret = E_NOK ; 
    }
    else
    {
        ret = gpio_pin_write_logic(&(seg->segment_pins[0]) , (number &(0x01)));
        ret = gpio_pin_write_logic(&(seg->segment_pins[1]) , ((number>>1) &(0x01)));
        ret = gpio_pin_write_logic(&(seg->segment_pins[2]) , ((number>>2) &(0x01)));
        ret = gpio_pin_write_logic(&(seg->segment_pins[3]) , ((number>>3) &(0x01)));
    }
    return ret ;
}
