/* 
 * File:   ecu_relay.h
 * Author: hp
 *
 * Created on 21 ??????, 2023, 03:54 ?
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H


/* Section : includes */
#include "ecu_relay_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_GPIO.h"

/* Section : Macro Declarations */
#define RELAY_ON_STATUS  0x01U
#define RELAY_OFF_STATUS  0x00U

/* Section : Macro Function Declarations */

/* Section : Data Type Declarations */ 
typedef struct    // size of 1 byte
{
    uint8 relay_port   : 4 ;
    uint8 relay_pin    : 3 ;
    uint8 relay_status : 1 ;
}relay_t;



/* Section : Function Declarations */
Std_ReturnType relay_initialize( const relay_t *_relay );
Std_ReturnType relay_turn_on  ( const relay_t *_relay );
Std_ReturnType relay_turn_off ( const relay_t *_relay );

#endif	/* ECU_RELAY_H */

