/* 
 * File:   hal_timer2.h
 * Author: Ziad Elmekawy
 *
 * Created on 04 August, 2024, 01:08 
 */

#ifndef HAL_TIMER2_H
#define	HAL_TIMER2_H

/************************** Section : includes **************************/
#include "../MCAL_std_Types.h"
#include "pic18f4620.h"
#include "../../MCAL_Layer/GPIO/hal_GPIO.h"
#include   "../../MCAL_Layer/Interrupt/mcal_internal_interrupt.h"

/************************** Section : Macro Declarations **************************/
/* Timer1 Clock source ( Timer or counter ) */
#define TIMER2_TIMER_MODE               0
#define TIMER2_COUNTER_MODE             1

/************************** Section : Macro Function Declarations **************************/
#define TIMER2_MODULE_ENABLE()    (T2CONbits.TMR2ON = 1)
#define TIMER2_MODULE_DISABLE()   (T2CONbits.TMR2ON = 0)
/* Timer2 Input Clock pre-scaler value */
#define TIMER2_PRESCALER_SELECT(_PRESCALER_)        (T2CONbits.T2CKPS = _PRESCALER_)
/* Timer2 Input Clock post-scaler value */
#define TIMER2_POSTSCALER_SELECT(_POSTSCALER_)      (T2CONbits.TOUTPS = _POSTSCALER_ )



/************************** Section : Data Type Declarations **************************/
typedef enum {
    TIMER2_PRESCALER_DIV_BY_1= 0 ,
    TIMER2_PRESCALER_DIV_BY_4 ,
    TIMER2_PRESCALER_DIV_BY_16
}timer2_prescaler_select_t;

typedef enum {
    TIMER2_POSTSCALER_DIV_BY_1= 0 ,
    TIMER2_POSTSCALER_DIV_BY_2 ,
    TIMER2_POSTSCALER_DIV_BY_3 ,
    TIMER2_POSTSCALER_DIV_BY_4 ,
    TIMER2_POSTSCALER_DIV_BY_5 ,
    TIMER2_POSTSCALER_DIV_BY_6 ,
    TIMER2_POSTSCALER_DIV_BY_7 ,
    TIMER2_POSTSCALER_DIV_BY_8 ,
    TIMER2_POSTSCALER_DIV_BY_9 ,
    TIMER2_POSTSCALER_DIV_BY_10 ,
    TIMER2_POSTSCALER_DIV_BY_11 ,
    TIMER2_POSTSCALER_DIV_BY_12 ,
    TIMER2_POSTSCALER_DIV_BY_13 ,
    TIMER2_POSTSCALER_DIV_BY_14 ,
    TIMER2_POSTSCALER_DIV_BY_15 ,
    TIMER2_POSTSCALER_DIV_BY_16
}timer2_postscaler_select_t;

typedef struct 
{
#if _TIMER2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    void (* TMR2_InterruptHandler)(void);
    interrupt_periority_cfg periority ;
#endif
    timer2_prescaler_select_t prescaler_value ;
    timer2_postscaler_select_t postscaler_value ;
    uint8 timer2_preload_value ;
    uint8 timer2_reserved : 8;
    
}timer2_t;



/************************** Section : Function Declarations **************************/
Std_ReturnType Timer2_Init (const timer2_t *timer);
Std_ReturnType Timer2_DeInit (const timer2_t *timer);
Std_ReturnType Timer2_Write_Value (const timer2_t *timer , uint16 value);
Std_ReturnType Timer2_Read_Value  (const timer2_t *timer , uint16 *value);

#endif	/* HAL_TIMER2_H */

