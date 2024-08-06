/* 
 * File:   hal_timer3.h
 * Author: Ziad Elmekawy 
 *
 * Created on 04 August, 2024, 01:49 
 */

#ifndef HAL_TIMER3_H
#define	HAL_TIMER3_H
 
/************************** Section : includes **************************/
#include "../MCAL_std_Types.h"
#include "pic18f4620.h"
#include "../../MCAL_Layer/GPIO/hal_GPIO.h"
#include   "../../MCAL_Layer/Interrupt/mcal_internal_interrupt.h"

/************************** Section : Macro Declarations **************************/
/* Timer1 Clock source ( Timer or counter ) */
#define TIMER3_TIMER_MODE               0
#define TIMER3_COUNTER_MODE             1
/* Timer1 External Clock Input Synchronization */
#define TIMER3_ASYNCH_COUNTER_MODE      1
#define TIMER3_SYNCH_COUNTER_MODE       0
/* Timer1 16-Bit Read/Write Mode */
#define TIMER3_RW_REG_8BIT_MODE         0
#define TIMER3_RW_REG_16BIT__MODE       1

/************************** Section : Macro Function Declarations **************************/
#define TIMER3_MODULE_ENABLE()                      (T3CONbits.TMR3ON = 1)
#define TIMER3_MODULE_DISABLE()                     (T3CONbits.TMR3ON = 0)
/* Timer3 Clock source ( Timer or counter ) */
#define TIMER3_TIMER_MODE_ENABLE()                  (T3CONbits.TMR3CS = 0)
#define TIMER3_COUNTER_MODE_ENABLE()                (T3CONbits.TMR3CS = 1)
/* Timer3 External Clock Input Synchronization */
#define TIMER3_ASYNCH_COUNTER_MODE_ENABLE()         (T3CONbits.T3SYNC = 1)
#define TIMER3_SYNCH_COUNTER_MODE_ENABLE()          (T3CONbits.T3SYNC = 0)
/* Timer3 Input Clock pre-scaler value */
#define TIMER3_PRESCALER_SELECT(_PRESCALER_)       (T3CONbits.T3CKPS = _PRESCALER_)


/* Timer3 16-Bit Read/Write Mode */
#define TIMER3_RW_REG_8BIT_MODE_ENABLE()            (T3CONbits.RD16 = 0)
#define TIMER3_RW_REG_16BIT_MODE_ENABLE()           (T3CONbits.RD16 = 1)

/************************** Section : Data Type Declarations **************************/
typedef enum {
    TIMER3_PRESCALER_DIV_BY_1= 0 ,
    TIMER3_PRESCALER_DIV_BY_2 ,
    TIMER3_PRESCALER_DIV_BY_4 ,
    TIMER3_PRESCALER_DIV_BY_8 
}timer3_prescaler_select_t;


typedef struct 
{
#if _TIMER3_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    void (* TMR3_InterruptHandler)(void);
    interrupt_periority_cfg priority ;
#endif
    timer3_prescaler_select_t prescaler_value ;
    uint16 timer3_preload_value ;
    uint8 timer3_register_size : 1;
    uint8 timer3_counter_mode  : 1;
    uint8 timer3_mode          : 1;
    uint8 timer3_reserved      : 5;
    
}timer3_t;



/************************** Section : Function Declarations **************************/
Std_ReturnType Timer3_Init        (const timer3_t *timer);
Std_ReturnType Timer3_DeInit      (const timer3_t *timer);
Std_ReturnType Timer3_Write_Value (const timer3_t *timer , uint16 value);
Std_ReturnType Timer3_Read_Value  (const timer3_t *timer , uint16 *value);



#endif	/* HAL_TIMER3_H */

