/* 
 * File:   mcal_interrupt_gen_config.h
 * Author: Ziad
 * Created on July 17, 2024, 11:19 AM
 */

#ifndef MCAL_INTERRUPT_GEN_CONFIG_H
#define	MCAL_INTERRUPT_GEN_CONFIG_H

/******************** Section : includes ********************/
/******************** Section : Data Type Declarations ********************/
#define INTERRUPT_FEATURE_ENABLE 1U

/******************** Section : Macro Declarations ********************/

//#define _INTERRUPT_PERIORITY_LEVELS_ENABLE              INTERRUPT_FEATURE_ENABLE
#define _EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE         INTERRUPT_FEATURE_ENABLE
#define _EXTERNAL_INTERRUPT_OnChange_FEATURE_ENABLE     INTERRUPT_FEATURE_ENABLE

#define _ADC_INTERRUPT_FEATURE_ENABLE                   INTERRUPT_FEATURE_ENABLE

#define _TIMER0_INTERRUPT_FEATURE_ENABLE                INTERRUPT_FEATURE_ENABLE
#define _TIMER1_INTERRUPT_FEATURE_ENABLE                INTERRUPT_FEATURE_ENABLE
#define _TIMER2_INTERRUPT_FEATURE_ENABLE                INTERRUPT_FEATURE_ENABLE
#define _TIMER3_INTERRUPT_FEATURE_ENABLE                INTERRUPT_FEATURE_ENABLE

#define _EUSART_Tx_INTERRUPT_FEATURE_ENABLE             INTERRUPT_FEATURE_ENABLE
#define _EUSART_Rx_INTERRUPT_FEATURE_ENABLE             INTERRUPT_FEATURE_ENABLE

#define _MSSP_I2C_INTERRUPT_FEATURE_ENABLE              INTERRUPT_FEATURE_ENABLE

#define _CPI_INTERRUPT_FEATURE_ENABLE                   INTERRUPT_FEATURE_ENABLE

/******************** Section : Macro Function Declarations ********************/

/******************** Section : Function Declarations ********************/

#endif	/* MCAL_INTERRUPT_GEN_CONFIG_H */

