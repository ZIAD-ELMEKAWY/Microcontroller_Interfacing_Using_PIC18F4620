/* 
 * File:   mcal_external_interrupt.h
 * Author: Ziad
 * Created on 17 July, 2024, 10:04 
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/******************** Section : includes ********************/
#include "mcal_interrupt_config.h"

/******************** Section : Macro Declarations ********************/

/******************** Section : Macro Function Declarations ********************/
/* For external interrupt from type INTx */
#ifdef _EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE 
// INT 0
#define EXT_INT0_InterruptDisable()         (INTCONbits.INT0IE = 0)
#define EXT_INT0_InterruptEnable()          (INTCONbits.INT0IE = 1)
#define EXT_INT0_InterruptFlagClear()       (INTCONbits.INT0IF = 0)
#define EXT_INT0_RisingEdgeSet()            (INTCON2bits.INTEDG0 = 1)
#define EXT_INT0_FallingEdgeSet()           (INTCON2bits.INTEDG0 = 0)
// INT 1
#define EXT_INT1_InterruptDisable()         (INTCON3bits.INT1IE = 0)
#define EXT_INT1_InterruptEnable()          (INTCON3bits.INT1IE = 1)
#define EXT_INT1_InterruptFlagClear()       (INTCON3bits.INT1IF = 0)
#define EXT_INT1_RisingEdgeSet()            (INTCON2bits.INTEDG1 = 1)
#define EXT_INT1_FallingEdgeSet()           (INTCON2bits.INTEDG1 = 0)
// INT 2
#define EXT_INT2_InterruptDisable()         (INTCON3bits.INT2IE = 0)
#define EXT_INT2_InterruptEnable()          (INTCON3bits.INT2IE = 1)
#define EXT_INT2_InterruptFlagClear()       (INTCON3bits.INT2IF = 0)
#define EXT_INT2_RisingEdgeSet()            (INTCON2bits.INTEDG2 = 1)
#define EXT_INT2_FallingEdgeSet()           (INTCON2bits.INTEDG2 = 0)
/* For external interrupt PERIORITY_LEVELS */
#ifdef _INTERRUPT_PERIORITY_LEVELS_ENABLE 
//INT1
#define EXT_INT1_InterruptLowPerioritySet()         (INTCON3bits.INT1IP = 0)
#define EXT_INT1_InterruptHighPerioritySet()         (INTCON3bits.INT1IP = 1)
//INT2
#define EXT_INT2_InterruptLowPerioritySet()         (INTCON3bits.INT2IP = 0)
#define EXT_INT2_InterruptHighPerioritySet()         (INTCON3bits.INT2IP = 1)

#endif
#endif

/* For external interrupt from type On change (RBx) */
#ifdef _EXTERNAL_INTERRUPT_OnChange_FEATURE_ENABLE 
#define EXT_RBx_InterruptDisable()         (INTCONbits.RBIE = 0)
#define EXT_RBx_InterruptEnable()          (INTCONbits.RBIE = 1)
#define EXT_RBx_InterruptFlagClear()       (INTCONbits.RBIF = 0)

/* For external interrupt PERIORITY_LEVELS */
#ifdef _INTERRUPT_PERIORITY_LEVELS_ENABLE 
#define EXT_RBx_InterruptLowPerioritySet()         (INTCON2bits.RBIP = 0)
#define EXT_RBx_InterruptHighPerioritySet()         (INTCON2bits.RBIP = 1)

#endif
#endif

/******************** Section : Data Type Declarations ********************/
typedef enum 
{
    INTERRUPT_FALLING_EDGE = 0,
    INTERRUPT_RISING_EDGE
}interrupt_INTx_edge;

typedef enum 
{
    INTERRUPT_EXTERNAL_INT0 = 0,
    INTERRUPT_EXTERNAL_INT1 ,
    INTERRUPT_EXTERNAL_INT2 
}interrupt_INTx_src;



typedef struct 
{
    void (* EXT_InterruptHandler)(void) ;
    pin_config_t        mcu_pin ;
    interrupt_INTx_edge edge ;
    interrupt_INTx_src  source ;
    interrupt_periority_cfg priority ;
}interrupt_INTx_t;

typedef struct 
{
    void (* EXT_InterruptHandlerHigh)(void) ;
    void (* EXT_InterruptHandlerLow )(void) ;
    pin_config_t        mcu_pin ;
    interrupt_periority_cfg priority ;
}interrupt_RBx_t;
/******************** Section : Function Declarations ********************/
/* INTx Function Declaration */
Std_ReturnType Interrupt_INTx_Initialize    (const interrupt_INTx_t *int_obj);
Std_ReturnType Interrupt_INTx_Deinitialize  (const interrupt_INTx_t *int_obj);

/* RBx Function Declaration */
Std_ReturnType Interrupt_RBx_Initialize     (const interrupt_RBx_t *int_obj);
Std_ReturnType Interrupt_RBx_Deinitialize   (const interrupt_RBx_t *int_obj);


#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

