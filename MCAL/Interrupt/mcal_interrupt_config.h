/* 
 * File:   mcal_interrupt_config.h
 * Author: Ziad
 * Created on 17 July 2024, 10:03 
 */

#ifndef MCAL_INTERRUPT_CONFIG_H
#define	MCAL_INTERRUPT_CONFIG_H

/******************** Section : includes ********************/
#include "../MCAL_std_Types.h"
#include "pic18f4620.h"
#include "mcal_interrupt_gen_config.h"
#include "../../MCAL_Layer/GPIO/hal_GPIO.h"

/******************** Section : Macro Declarations ********************/
#define INTERRUPT_ENABLE        1
#define INTERRUPT_DISABLE       0

#define INTERRUPT_OCCUR         1
#define INTERRUPT_NOT_OCCUR     0

#define INTERRUPT_PERIORITY_ENABLE          1
#define INTERRUPT_PERIORITY_DISABLE         0
/******************** Section : Macro Function Declarations ********************/
/**
 * @note    1- Don't leave space between Function name and this () [ error : unexpected expression if you leave space ]
 * @example  INTERRUPT_GlobalInterruptHighEnable () -> [error ]
 *           INTERRUPT_GlobalInterruptHighEnable() ->  [No error ]
 */
#ifdef _INTERRUPT_PERIORITY_LEVELS_ENABLE 

#define INTERRUPT_PeriortyLevelEnable()           (RCONbits.IPEN = 1)    // this macro will enable Peripheral Interrupt
#define INTERRUPT_PeriortyLevelDisable()          (RCONbits.IPEN = 0)    // this macro will disable Peripheral Interrupt

#define INTERRUPT_GlobalInterruptHighEnable()     (INTCONbits.GIEH = 1)    // this macro will enable high periority global interrupts
#define INTERRUPT_GlobalInterruptHighDisable()    (INTCONbits.GIEH = 0)    // this macro will disable high periority global interrupts

#define INTERRUPT_GlobalInterruptLowEnable()      (INTCONbits.GIEL = 1)    // this macro will enable low periority global interrupts
#define INTERRUPT_GlobalInterruptLowDisable()     (INTCONbits.GIEL = 0)    // this macro will disable low periority global interrupts

#else

#define INTERRUPT_GlobalInterruptEnable()     (INTCONbits.GIE = 1)          // this macro will enable periority global interrupts
#define INTERRUPT_GlobalInterruptDisable()    (INTCONbits.GIE = 0)          // this macro will disable periority global interrupts

#define INTERRUPT_PeripheralInterruptEnable()     (INTCONbits.PEIE = 1)    // this macro will enable Peripheral Interrupt
#define INTERRUPT_PeripheralInterruptDisable()    (INTCONbits.PEIE = 0)    // this macro will disable Peripheral Interrupt

#endif
 

/******************** Section : Data Type Declarations ********************/

typedef enum 
{
    INTERRUPT_LOW_PRIORITY = 0,
    INTERRUPT_HIGH_PRIORITY
}interrupt_periority_cfg;
/******************** Section : Function Declarations ********************/

#endif	/* MCAL_INTERRUPT_CONFIG_H */

