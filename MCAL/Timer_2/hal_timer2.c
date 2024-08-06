/* 
 * File:   hal_timer2.c
 * Author: Ziad Elmekawy
 *
 * Created on 04 August, 2024, 01:08 
 */


/************************ Section : Includes ************************/
#include "hal_timer2.h"


/************************ Section : Helper Function Declarations ************************/


/************************ Section : Function Definitions ************************/

#if _TIMER2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    static volatile void (*TMR2_InterruptHandler)(void) = NULL;
#endif
static volatile uint16 timer2_preload = 0 ;


/**
 * @name  Timer2_Initialization
 * @param timer
 * @return 
 */
Std_ReturnType Timer2_Init (const timer2_t *timer)
{
    Std_ReturnType ret = E_NOK ;
    if (timer == NULL)
    {
        ret = E_NOK ;
    }
    else 
    {
        TIMER2_MODULE_DISABLE();
        TIMER2_PRESCALER_SELECT(timer->prescaler_value);
        TIMER2_POSTSCALER_SELECT(timer->postscaler_value);
        TMR2 = timer->timer2_preload_value ;
        timer2_preload = timer->timer2_preload_value ;
         /* Interrupt Configuration */
#if _TIMER2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TIMER2_InterruptEnable();
        TIMER2_InterruptFlagClear();
        TMR2_InterruptHandler = timer->TMR2_InterruptHandler;
 /* Interrupt Priority configuration */
#if _INTERRUPT_PERIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PeriortyLevelEnable();
        if (timer->periority == INTERRUPT_HIGH_PRIORITY)
        {
            /* Enable all high-priority interrupts */
            INTERRUPT_GlobalInterruptHighEnable();
            TIMER2_HighPrioritySet();
        }
        else if (timer->periority == INTERRUPT_HIGH_PRIORITY)
        {
            /* Enable all unmasked peripheral interrupts */
            INTERRUPT_GlobalInterruptLowEnable();
            TIMER2_LowPrioritySet();
        }
#else 
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif        
#endif
        TIMER2_MODULE_ENABLE();
        ret = E_OK ;
    }
    return ret ;
}

/**
 * @name  Timer2_DeInitialization
 * @param timer
 * @return 
 */
Std_ReturnType Timer2_DeInit (const timer2_t *timer)
{
    Std_ReturnType ret = E_NOK ;
    if (timer == NULL)
    {
        ret = E_NOK ;
    }
    else 
    {
        TIMER2_MODULE_DISABLE();
#if _TIMER2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TIMER2_InterruptDisable();
#endif
        ret = E_OK ;
    }
    return ret ;
}

/**
 * @name  Timer2_Write_Value
 * @param timer
 * @param value
 * @return 
 */
Std_ReturnType Timer2_Write_Value (const timer2_t *timer , uint16 value)
{
    Std_ReturnType ret = E_NOK ;
    if (timer == NULL)
    {
        ret = E_NOK ;
    }
    else 
    {
        TMR2 = value ;
        ret = E_OK ;
    }
    return ret ;
}

/**
 * @name  Timer2_Read_Value
 * @param timer
 * @param value
 * @return 
 */
Std_ReturnType Timer2_Read_Value  (const timer2_t *timer , uint16 *value)
{
    Std_ReturnType ret = E_NOK ;
    if ((timer == NULL) || (value == NULL))
    {
        ret = E_NOK ;
    }
    else 
    {
        *value = TMR2 ;
        ret = E_OK ;
    }
    return ret ;
}

/* ===================== ISR Function ====================== */
/**
 * @name TMR2_ISR
 * @return void 
 * @brief 
 */
void TMR2_ISR (void)
{
    TIMER2_InterruptFlagClear();
    /* to return pre-load values to Timer0 register after overflow */
    TMR2 = timer2_preload ;
    if (TMR2_InterruptHandler)
    {
        TMR2_InterruptHandler();        /* Call the callback function */
    }
}