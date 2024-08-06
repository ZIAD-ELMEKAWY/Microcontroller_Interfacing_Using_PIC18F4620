/* 
 * File:   hal_timer3.c
 * Author: Ziad Elmekawy 
 *
 * Created on 04 August, 2024, 01:49 
 */

/************************ Section : Includes ************************/
#include "hal_timer3.h"


/************************ Section : Helper Function Declarations ************************/
#if _TIMER3_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    static void (*TMR3_InterruptHandler)(void) = NULL;
#endif
static uint16 timer3_preload = 0 ;

static inline void Timer3_Mode_Select (const timer3_t *timer);


/************************ Section : Function Definitions ************************/
/**
 * @name  Timer3_Init
 * @param timer
 * @return 
 */
Std_ReturnType Timer3_Init (const timer3_t *timer)
{
    Std_ReturnType ret = E_NOK ;
    if (timer == NULL)
    {
        ret = E_NOK ;
    }
    else 
    {
        TIMER3_MODULE_DISABLE();
        TIMER3_PRESCALER_SELECT(timer->prescaler_value); 
        Timer3_Mode_Select(timer);
        TMR3H = (timer->timer3_preload_value) >> 8 ;
        TMR3L = (uint8)(timer->timer3_preload_value);
        timer3_preload = timer->timer3_preload_value ;
 /* Interrupt Configuration */
#if _TIMER3_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TIMER3_InterruptEnable();
        TIMER3_InterruptFlagClear();
        TMR3_InterruptHandler = timer->TMR3_InterruptHandler;
 /* Interrupt Priority configuration */
#if _INTERRUPT_PERIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PeriortyLevelEnable();
        if (timer->priority == INTERRUPT_HIGH_PRIORITY)
        {
            /* Enable all high-priority interrupts */
            INTERRUPT_GlobalInterruptHighEnable();
            TIMER3_HighPrioritySet();
        }
        else if (timer->priority == INTERRUPT_HIGH_PRIORITY)
        {
            /* Enable all unmasked peripheral interrupts */
            INTERRUPT_GlobalInterruptLowEnable();
            TIMER3_LowPrioritySet();
        }
#else 
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif        
#endif
        TIMER3_MODULE_ENABLE();
        ret = E_OK ;
    }
    return ret ; 
}

/**
 * @name  Timer3_DeInit
 * @param timer
 * @return 
 */
Std_ReturnType Timer3_DeInit (const timer3_t *timer)
{
    Std_ReturnType ret = E_NOK ;
    if (timer == NULL)
    {
        ret = E_NOK ;
    }
    else 
    {
        TIMER3_MODULE_DISABLE();
#if _TIMER3_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TIMER3_InterruptDisable();
#endif
        ret = E_OK ;
    }
    return ret ; 
}

/**
 * @name  Timer3_Write_Value
 * @param timer
 * @param value
 * @return 
 */
Std_ReturnType Timer3_Write_Value (const timer3_t *timer , uint16 value)
{
    Std_ReturnType ret = E_NOK ;
    if (timer == NULL)
    {
        ret = E_NOK ;
    }
    else 
    {
        TMR3H = (value) >> 8 ;
        TMR3L = (uint8)(value);
        ret = E_OK ;
    }
    return ret ; 
}

/**
 * @name  Timer3_Read_Value
 * @param timer
 * @param value
 * @return 
 */
Std_ReturnType Timer3_Read_Value  (const timer3_t *timer , uint16 *value)
{
    Std_ReturnType ret = E_NOK ;
    uint8 l_tmr3_low =0 , l_tmr3_high = 0 ;
    if ((timer == NULL) || (value == NULL))
    {
        ret = E_NOK ;
    }
    else 
    {
        l_tmr3_low  = TMR3L ;
        l_tmr3_high = TMR3H ;
        *value = (uint16)((l_tmr3_high << 8) + l_tmr3_low);
        ret = E_OK ;
    }
    return ret ; 
}

/**
 * @name  Timer3_Mode_Select
 * @param timer
 * @return void
 */
static inline void Timer3_Mode_Select (const timer3_t *timer)
{
    if(TIMER3_TIMER_MODE == timer->timer3_mode)
    {
        TIMER3_TIMER_MODE_ENABLE();
    }
    else if (TIMER3_COUNTER_MODE == timer->timer3_mode)
    {
        TIMER3_COUNTER_MODE_ENABLE();
        if (TIMER3_ASYNCH_COUNTER_MODE == timer->timer3_counter_mode)
        {
            TIMER3_ASYNCH_COUNTER_MODE_ENABLE() ;
        }
        else if (TIMER3_SYNCH_COUNTER_MODE == timer->timer3_counter_mode)
        {
            TIMER3_SYNCH_COUNTER_MODE_ENABLE() ;
        }
        else
        { /* Nothing */ }
    }
    else
    { /* Nothing */ }
}


/* ===================== ISR Function ====================== */
/**
 * @name TMR3_ISR
 * @return void 
 * @brief 
 */
void TMR3_ISR (void)
{
    TIMER3_InterruptFlagClear();
    /* to return pre-load values to Timer0 register after overflow */
    TMR3H = (timer3_preload) >> 8 ;
    TMR3L = (uint8)(timer3_preload);
    if (TMR3_InterruptHandler)
    {
        TMR3_InterruptHandler();        /* Call the callback function */
    }
}