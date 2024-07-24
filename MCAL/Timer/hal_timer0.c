/* 
 * File:   hal_timer0.h
 * Author: Ziad
 *
 * Created on 16 july, 2024, 07:16 ?
 */

/************************ Section : Includes ************************/
#include "hal_timer0.h"

/************************ Section : Function Definitions ************************/
Std_ReturnType Timer0_Init (const timer0_t *timer)
{
    Std_ReturnType ret = E_OK ;
    if(timer == NULL)
    {
        ret = E_NOK ;
    }
    else
    {
        
    }
    return ret ;
}

Std_ReturnType Timer0_DeInit (const timer0_t *timer)
{
    Std_ReturnType ret = E_OK ;
    if(timer == NULL)
    {
        ret = E_NOK ;
    }
    else
    {
        
    }
    return ret ;
}

Std_ReturnType Timer0_Write_Value (const timer0_t *timer , uint16 value)
{
    Std_ReturnType ret = E_OK ;
    if(timer == NULL)
    {
        ret = E_NOK ;
    }
    else
    {
        
    }
    return ret ;
}

Std_ReturnType Timer0_Read_Value  (const timer0_t *timer , uint16 *value)
{
    Std_ReturnType ret = E_OK ;
    if((timer == NULL) || (value == NULL))
    {
        ret = E_NOK ;
    }
    else
    {
        
    }
    return ret ;
}