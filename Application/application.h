/* 
 * File:   application.h
 * Author: hp
 *
 * Created on 09 ?????, 2023, 10:22 ?
 */

#ifndef APPLICATION_H
#define	APPLICATION_H


/*************** Section : includes ***************/
#include "ECU_Layer/ECU_Layer_Init.h"
#include "MCAL_Layer/Interrupt/mcal_external_interrupt.h"
/*************** Section : Macro Declarations ***************/

/*************** Section : Macro Function Declarations ***************/

/*************** Section : Data Type Declarations ***************/
extern keypad_t Keypad_1 ;
extern led_t led1 ;
extern chr_lcd_4bit_t lcd_1 ;
extern chr_lcd_8bit_t lcd_2 ;
/*************** Section : Function Declarations  ***************/
void application_initialize (void);

#endif	/* APPLICATION_H */

