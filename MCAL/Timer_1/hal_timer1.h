/* 
 * @File:   hal_timer1.h
 * @Author: Zaid Elmekawy
 * @Layer : MCAL
 * Created on 02 July, 2024, 09:38 
 */

#ifndef HAL_TIMER1_H
#define	HAL_TIMER1_H

/********************* Section : includes *********************/
#include "../MCAL_std_Types.h"
#include "pic18f4620.h"
#include "../../MCAL_Layer/GPIO/hal_GPIO.h"
#include   "../../MCAL_Layer/Interrupt/mcal_internal_interrupt.h"

/********************* Section : Macro Declarations *********************/
/* Timer1 Clock source ( Timer or counter ) */
#define TIMER1_TIMER_MODE               0
#define TIMER1_COUNTER_MODE             1
/* Timer1 External Clock Input Synchronization */
#define TIMER1_ASYNCH_COUNTER_MODE      1
#define TIMER1_SYNCH_COUNTER_MODE       0
/* Timer1 Oscillator */
#define TIMER1_OSC_ENABLE               1
#define TIMER1_OSC_DISABLE              0
/* Timer1 16-Bit Read/Write Mode */
#define TIMER1_RW_REG_8BIT_MODE         0
#define TIMER1_RW_REG_16BIT__MODE       1

/********************* Section : Macro Function Declarations *********************/
/* Enable or disable  Timer1 Module */
#define TIMER1_MODULE_ENABLE()                      (T1CONbits.TMR1ON = 1)
#define TIMER1_MODULE_DISABLE()                     (T1CONbits.TMR1ON = 0)
/* Timer1 Clock source ( Timer or counter ) */
#define TIMER1_TIMER_MODE_ENABLE()                  (T1CONbits.TMR1CS = 0)
#define TIMER1_COUNTER_MODE_ENABLE()                (T1CONbits.TMR1CS = 1)
/* Timer1 External Clock Input Synchronization */
#define TIMER1_ASYNCH_COUNTER_MODE_ENABLE()         (T1CONbits.T1SYNC = 1)
#define TIMER1_SYNCH_COUNTER_MODE_ENABLE()          (T1CONbits.T1SYNC = 0)
/* Timer1 Oscillator */
#define TIMER1_OSC_HW_ENABLE()                      (T1CONbits.T1OSCEN = 1)
#define TIMER1_OSC_HW_DISABLE()                     (T1CONbits.T1OSCEN = 0)
/* Timer1 Input Clock pre-scaler value */
#define TIMER1_PRESCALER_SELECT(_PRESCALER_)        (T1CONbits.T1CKPS = _PRESCALER_)
/* Timer1 system clock status ( Reading value only ) */
#define TIMER1_SYSTEM_CLK_STATUS()                  (T1CONbits.T1RUN)
/* Timer1 16-Bit Read/Write Mode */
#define TIMER1_RW_REG_8BIT_MODE_ENABLE()            (T1CONbits.RD16 = 0)
#define TIMER1_RW_REG_16BIT_MODE_ENABLE()           (T1CONbits.RD16 = 1)

/********************* Section : Data Type Declarations *********************/
/* Timer1 Input Clock pre-scaler value */
typedef enum {
    TIMER1_PRESCALER_DIV_BY_1= 0,
    TIMER1_PRESCALER_DIV_BY_2 ,
    TIMER1_PRESCALER_DIV_BY_4 ,
    TIMER1_PRESCALER_DIV_BY_8 
}timer1_prescaler_select_t;

typedef struct 
{
#if _TIMER1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    void (* TMR1_InterruptHandler)(void);
    interrupt_periority_cfg periority ;
#endif
    uint16 timer1_preload_value ;
    uint8 timer1_mode          : 1;     /* @ref  Enable or disable  Timer1 Module */ 
    uint8 timer1_counter_mode  : 1;     /* @ref  Timer1 External Clock Input Synchronization */
    uint8 timer1_osc_cfg       : 1;     /* @ref  Timer1 Oscillator */
    uint8 timer1_prescaler_value : 2 ;  /* @ref  timer1_prescaler_select_t */
    uint8 timer1_reg_rw_mode     : 1 ;  /* @ref  Timer1 16-Bit Read/Write Mode */
    uint8 timer1_reserved      : 2;     /* for another features */
}timer1_t;
/********************* Section : Function Declarations *********************/
Std_ReturnType Timer1_Init (const timer1_t *timer);
Std_ReturnType Timer1_DeInit (const timer1_t *timer);
Std_ReturnType Timer1_Write_Value (const timer1_t *timer , uint16 value);
Std_ReturnType Timer1_Read_Value  ( uint16 *value);

#endif	/* HAL_TIMER1_H */

