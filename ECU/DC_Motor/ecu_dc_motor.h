/* 
 * File:   ecu_dc_motor.h
 * Author: hp
 *
 * Created on 29 ??????, 2023, 11:19 ?
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/* Section : includes */
#include "ecu_dc_motor_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_GPIO.h"

/* Section : Macro Declarations */
#define DC_MOTOR_ON_STATUS  0x01U
#define DC_MOTOR_OFF_STATUS 0x00U

/* Section : Macro Function Declarations */


/* Section : Data Type Declarations */

typedef struct    // size of 1 byte
{
    pin_config_t dc_motor_pin[2];        //object of struct type pin_config_t  
}dc_motor_t;

/* Section : Function Declarations */
Std_ReturnType dc_motor_initialize (const dc_motor_t *dc_motor);
Std_ReturnType dc_motor_move_right (const dc_motor_t *dc_motor);
Std_ReturnType dc_motor_move_left  (const dc_motor_t *dc_motor);
Std_ReturnType dc_motor_stop       (const dc_motor_t *dc_motor);

#endif	/* ECU_DC_MOTOR_H */

