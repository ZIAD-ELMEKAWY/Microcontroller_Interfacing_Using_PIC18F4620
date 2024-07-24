/* 
 * File:   hal_timer0.h
 * Author: Ziad
 *
 * Created on 16 july, 2024, 07:16 ?
 */

#ifndef HAL_TIMER0_H
#define	HAL_TIMER0_H

/********************* Section : includes *********************/
#include "../MCAL_std_Types.h"
#include "pic18f4620.h"
#include "../../MCAL_Layer/GPIO/hal_GPIO.h"
// #include   "mcal_internal_interrupt_.h"

/********************* Section : Macro Declarations *********************/
#define TIMER0_PRESCALER_ENABLE_CFG     1
#define TIMER0_PRESCALER_DISABLE_CFG    0

#define TIMER0_RISING_EDGE_CFG     1
#define TIMER0_FALLING_EDGE_CFG    0

#define TIMER0_TIMER_MODE     1
#define TIMER0_COUNTER_MODE   0

#define TIMER0_8BIT_REGISTER_MODE     1
#define TIMER0_16BIT_REGISTER_MODE   0

/********************* Section : Macro Function Declarations *********************/
#define TIMER0_PRESCALER_ENABLE()  (T0CONbits.PSA = 0)       // T0CONbits FROM PIC18F4620.h
#define TIMER0_PRESCALER_DISABLE() (T0CONbits.PSA = 1)

#define TIMER0_RISING_EDGE_ENABLE()  (T0CONbits.T0SE = 0)    // T0CONbits FROM PIC18F4620.h
#define TIMER0_FALLING_EDGE_ENABLE() (T0CONbits.T0SE = 1)

#define TIMER0_TIMER_MODE_ENABLE()    (T0CONbits.T0CS= 0)
#define TIMER0_COUNTER_MODE_ENABLE()  (T0CONbits.T0CS= 1)

#define TIMER0_TIMER_MODE_ENABLE()    (T0CONbits.T0CS= 0)
#define TIMER0_COUNTER_MODE_ENABLE()  (T0CONbits.T0CS= 1)

#define TIMER0_8BIT_REGISTER_MODE_ENABLE()    (T0CONbits.T08BIT= 1)
#define TIMER0_16BIT_REGISTER_MODE_ENABLE()   (T0CONbits.T08BIT= 0)

#define TIMER0_MODULE_ENABLE()    (T0CONbits.TMR0ON= 1)
#define TIMER0_MODULE_DISABLE()   (T0CONbits.TMR0ON= 0)

/********************* Section : Data Type Declarations *********************/
typedef enum {
    TIMER0_PRESCALER_DIV_BY_2 ,
    TIMER0_PRESCALER_DIV_BY_4 ,
    TIMER0_PRESCALER_DIV_BY_8 ,
    TIMER0_PRESCALER_DIV_BY_16 ,
    TIMER0_PRESCALER_DIV_BY_32 ,
    TIMER0_PRESCALER_DIV_BY_64 ,
    TIMER0_PRESCALER_DIV_BY_128 ,
    TIMER0_PRESCALER_DIV_BY_256 
}timer0_prescaler_select_t;

typedef struct 
{
    timer0_prescaler_select_t prescaler_value ;
    uint8 timer0_register_size : 1;
    uint8 timer0_counter_edge : 1;
    uint8 timer0_mode         : 1;
    uint8 prescaler_enable : 1;
    
}timer0_t;
/********************* Section : Function Declarations *********************/
Std_ReturnType Timer0_Init (const timer0_t *timer);
Std_ReturnType Timer0_DeInit (const timer0_t *timer);
Std_ReturnType Timer0_Write_Value (const timer0_t *timer , uint16 value);
Std_ReturnType Timer0_Read_Value  (const timer0_t *timer , uint16 *value);

#endif	/* HAL_TIMER0_H */

