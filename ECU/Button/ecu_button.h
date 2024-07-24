/* 
 * File:   ecu_button.h
 * Author: hp
 *
 * Created on 05 ??????, 2023, 04:19 ?
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

/* Section : Includes */
#include "../../MCAL_Layer/GPIO/hal_GPIO.h"
#include "ecu_button_cfg.h"

/* Section : Macro Declarations */

/* Section : Macro Function Declarations */

/* Section : Data Type Declarations */
typedef enum
{
    BUTTON_PRESSED,
    BUTTON_RELEASED        
}button_state_t;

typedef enum
{
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW
}button_active_t;

typedef struct 
{
    pin_config_t button_pin ;
    button_state_t button_state ;
    button_active_t button_connection ;      
}button_t;

/* Section : Software interfaces Declarations */
Std_ReturnType button_intialize   (const button_t *btn );
Std_ReturnType button_read_status (const button_t *btn , button_state_t *btn_state);

#endif	/* ECU_BUTTON_H */

