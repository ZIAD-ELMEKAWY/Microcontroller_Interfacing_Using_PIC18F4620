/* 
 * @File:   hai_timer1.c
 * @Author: Zaid Elmekawy
 * @Layer : MCAL
 * Created on 02 July, 2024, 09:38 
 */

/********************* Section : Include ********************/
#include "hal_timer1.h"




/************* Section : Function Definition ****************/
#if _TIMER1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    static void (*TMR1_InterruptHandler)(void) = NULL;
#endif
static volatile uint16 timer1_preload = 0 ;

static inline void Timer1_Mode_Select (const timer1_t *timer);
/**
 * 
 * @param timer
 * @return Std_ReturnType
 */
Std_ReturnType Timer1_Init (const timer1_t *timer)
{
    Std_ReturnType ret = E_NOK ;
    if (timer == NULL)
    {
        ret = E_NOK ;
    }
    else
    {
        TIMER1_MODULE_DISABLE() ;
        TIMER1_PRESCALER_SELECT(timer->timer1_prescaler_value); 
        Timer1_Mode_Select(timer);
        TMR1H = (timer->timer1_preload_value) >>8 ;
        TMR1L = (uint8)(timer->timer1_preload_value);
        timer1_preload = timer->timer1_preload_value ;
 /* Interrupt Configuration */
#if _TIMER1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TIMER1_InterruptEnable();
        TIMER1_InterruptFlagClear();
        TMR1_InterruptHandler = timer->TMR1_InterruptHandler;
 /* Interrupt Priority configuration */
#if _INTERRUPT_PERIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PeriortyLevelEnable();
        if (timer->periority == INTERRUPT_HIGH_PRIORITY)
        {
            /* Enable all high-priority interrupts */
            INTERRUPT_GlobalInterruptHighEnable();
            TIMER1_HighPrioritySet();
        }
        else if (timer->periority == INTERRUPT_HIGH_PRIORITY)
        {
            /* Enable all unmasked peripheral interrupts */
            INTERRUPT_GlobalInterruptLowEnable();
            TIMER1_LowPrioritySet();
        }
#else 
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif        
#endif
        TIMER1_MODULE_ENABLE() ;
        ret = E_OK ;
    }
    return ret ;
}

/**
 * 
 * @param timer
 * @return Std_ReturnType
 */
Std_ReturnType Timer1_DeInit (const timer1_t *timer)
{
    Std_ReturnType ret = E_NOK ;
    if (timer == NULL)
    {
        ret = E_NOK ;
    }
    else
    {
        TIMER1_MODULE_DISABLE();
#if _TIMER1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TIMER1_InterruptDisable();
#endif
        ret = E_OK;
    }
    return ret ;
}

/**
 * 
 * @param timer
 * @param value
 * @return Std_ReturnType
 */
Std_ReturnType Timer1_Write_Value (const timer1_t *timer , uint16 value)
{
    Std_ReturnType ret = E_NOK ;
    if (timer == NULL)
    {
        ret = E_NOK ;
    }
    else
    {
        TMR1H = (value) >>8 ;
        TMR1L = (uint8)(value);
        ret = E_OK ;
    }
    return ret ;
}

/**
 * 
 * @param timer
 * @param value
 * @return Std_ReturnType
 */
Std_ReturnType Timer1_Read_Value  ( uint16 *value)
{
    Std_ReturnType ret = E_NOK ;
    uint8 l_tmr1_low = 0  , l_tmr1_high = 0 ;
    if (value == NULL)
    {
        ret = E_NOK ;
    }
    else
    {
        l_tmr1_low  = TMR1L ;
        l_tmr1_high = TMR1H ;
        *value = (uint16)((l_tmr1_high << 8) + l_tmr1_low);
        ret = E_OK ;
    }
    return ret ;
}

/************************************** Section : Helper function definitions **************************/
/**
 * @name  Timer1_Mode_Select
 * @param timer
 * @returnn void 
 */
static inline void Timer1_Mode_Select (const timer1_t *timer)
{
    if(TIMER1_TIMER_MODE == timer->timer1_mode)
    {
        TIMER1_TIMER_MODE_ENABLE();
    }
    else if (TIMER1_COUNTER_MODE == timer->timer1_mode)
    {
        TIMER1_COUNTER_MODE_ENABLE();
        if (TIMER1_ASYNCH_COUNTER_MODE == timer->timer1_counter_mode)
        {
            TIMER1_ASYNCH_COUNTER_MODE_ENABLE() ;
        }
        else if (TIMER1_SYNCH_COUNTER_MODE == timer->timer1_counter_mode)
        {
            TIMER1_SYNCH_COUNTER_MODE_ENABLE() ;
        }
        else
        { /* Nothing */ }
    }
    else
    { /* Nothing */ }
}

/* ============================= ISR Function ======================*/
/**
 * @name   TMR1_ISR
 * @return void 
 * @brief  
 */
void TMR1_ISR (void)
{
    TIMER1_InterruptFlagClear();
    /* to return pre-load values to Timer0 register after overflow */
    TMR1H = (timer1_preload) >> 8 ;
    TMR1L = (uint8)(timer1_preload);
    if (TMR1_InterruptHandler)
    {
        TMR1_InterruptHandler();        /* Call the callback function */
    }
}