/* 
 * File:   ecu_sev_seg.h
 * Author: Ziad
 * Created on 24 July, 2024, 04:25 
 */

#ifndef ECU_SEV_SEG_H
#define	ECU_SEV_SEG_H

/* Section : includes */
#include "../../MCAL_Layer/GPIO/hal_GPIO.h"
#include "ecu_sev_seg_cfg.h"

/* Section : Macro Declarations */
#define SEGMENT_PIN0    0
#define SEGMENT_PIN1    1
#define SEGMENT_PIN2    2
#define SEGMENT_PIN3    3

/* Section : Macro Function Declarations */

/* Section : Data Type Declarations */
typedef enum {
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE
}segment_type_t;

typedef struct {
    pin_config_t segment_pins[4] ;
    segment_type_t segment_type ;
}segment_t;


/* Section : Function Declarations */
Std_ReturnType Seven_Segment_Initialize   (const segment_t *seg);
Std_ReturnType Seven_Segment_Write_Number (const segment_t *seg , uint8 number);

#endif	/* ECU_SEV_SEG_H */

