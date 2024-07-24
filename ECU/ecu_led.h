/* 
 * File:   ecu_led.h
 * Author: hp
 *
 * Created on 09 ?????, 2023, 10:18 ?
 */

#ifndef ECU_LED_H
#define	ECU_LED_H
/* Section : includes */
#include "../MCAL_Layer/GPIO/hal_GPIO.h"
#include "ecu_led_cfg.h"


/* Section : Macro Declarations */

/* Section : Macro Function Declarations */

/* Section : Data Type Declarations */
typedef enum 
{
    LED_OFF,
    LED_ON
}led_status_t;

typedef struct
{
    uint8 port_name  : 4;
    uint8 pin        : 3;
    uint8 led_status : 1;
}led_t;

/* Section : Function Declarations */
Std_ReturnType led_intialize(const led_t *led);
Std_ReturnType led_turn_on  (const led_t *led);
Std_ReturnType led_turn_off (const led_t *led);
Std_ReturnType led_toggle   (const led_t *led);

#endif	/* ECU_LED_H */

