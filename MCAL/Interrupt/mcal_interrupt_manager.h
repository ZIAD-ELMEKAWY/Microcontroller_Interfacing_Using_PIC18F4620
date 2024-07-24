/* 
 * File:   mcal_interrupt_manager.c
 * Author: Ziad
 *
 * Created on 17 July 2024, 10:06 
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H

/******************** Section : includes ********************/
#include "mcal_interrupt_config.h"

/******************** Section : Macro Declarations ********************/

/******************** Section : Macro Function Declarations ********************/

/******************** Section : Data Type Declarations ********************/

/******************** Section : Function Declarations ********************/

/* for INTx */
void INT0_ISR (void);
void INT1_ISR (void);
void INT2_ISR (void);

/* for RBx */
void RB4_ISR  (uint8 RB4_Source);
void RB5_ISR  (uint8 RB5_Source);
void RB6_ISR  (uint8 RB6_Source);
void RB7_ISR  (uint8 RB7_Source);


#endif	/* MCAL_INTERRUPT_MANAGER_H */

