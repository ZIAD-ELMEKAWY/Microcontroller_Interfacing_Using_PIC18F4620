/* 
 * File:   application.c
 * Author: Ziad Elmekawy 
 *
 * Created on 05 August, 2024
 */


#include "application.h"
#include "MCAL_Layer/Interrupt/mcal_external_interrupt.h"
/* =============== Function Declaration start =============== */
void RB3_HIGH_Int_App_ISR (void);
void RB3_LOW_Int_App_ISR (void);
void RB4_HIGH_Int_App_ISR (void);
void RB4_LOW_Int_App_ISR (void);
void RB5_HIGH_Int_App_ISR (void);
void RB5_LOW_Int_App_ISR (void);
void RB6_HIGH_Int_App_ISR (void);
void RB6_LOW_Int_App_ISR (void);

void Motor_Move_Forward (void);
void Motor_Move_Backward(void);
void Motor_Move_Right   (void);
void Motor_Move_Left    (void);
void Motor_Stop         (void);

/* =============== Function Declaration end  =============== */

/* ============== Interrupts  RBx =============== */
interrupt_RBx_t rb3_int_obj = 
{
    .EXT_InterruptHandlerHigh = RB3_HIGH_Int_App_ISR ,
    .EXT_InterruptHandlerLow  = RB3_LOW_Int_App_ISR ,
    .priority = INTERRUPT_HIGH_PRIORITY ,
    .mcu_pin.port = PORTB_INDEX ,
    .mcu_pin.pin = PIN7 ,
    .mcu_pin.direction = GPIO_DIRECTION_INPUT 
};
interrupt_RBx_t rb4_int_obj = 
{
    .EXT_InterruptHandlerHigh = RB4_HIGH_Int_App_ISR ,
    .EXT_InterruptHandlerLow  = RB4_LOW_Int_App_ISR ,
    .priority = INTERRUPT_HIGH_PRIORITY ,
    .mcu_pin.port = PORTB_INDEX ,
    .mcu_pin.pin = PIN4 ,
    .mcu_pin.direction = GPIO_DIRECTION_INPUT 
};
interrupt_RBx_t rb5_int_obj = 
{
    .EXT_InterruptHandlerHigh = RB5_HIGH_Int_App_ISR ,
    .EXT_InterruptHandlerLow  = RB5_LOW_Int_App_ISR ,
    .priority = INTERRUPT_HIGH_PRIORITY ,
    .mcu_pin.port = PORTB_INDEX ,
    .mcu_pin.pin = PIN5 ,
    .mcu_pin.direction = GPIO_DIRECTION_INPUT 
};
interrupt_RBx_t rb6_int_obj = 
{
    .EXT_InterruptHandlerHigh = RB6_HIGH_Int_App_ISR ,
    .EXT_InterruptHandlerLow  = RB6_LOW_Int_App_ISR ,
    .priority = INTERRUPT_HIGH_PRIORITY ,
    .mcu_pin.port = PORTB_INDEX ,
    .mcu_pin.pin = PIN6 ,
    .mcu_pin.direction = GPIO_DIRECTION_INPUT 
};
/* ==================== LCD 4-Bit ===================== */
chr_lcd_4bit_t lcd_1 =
{ 
    .lcd_data[0].port  = PORTD_INDEX ,
    .lcd_data[0].pin = PIN0 ,
    .lcd_data[0].direction = GPIO_DIRECTION_OUTPUT ,
    .lcd_data[0].logic = GPIO_LOW ,
    
    .lcd_data[1].port  = PORTD_INDEX ,
    .lcd_data[1].pin = PIN1 ,
    .lcd_data[1].direction = GPIO_DIRECTION_OUTPUT ,
    .lcd_data[1].logic = GPIO_LOW ,
    
    .lcd_data[2].port  = PORTD_INDEX ,
    .lcd_data[2].pin = PIN2 ,
    .lcd_data[2].direction = GPIO_DIRECTION_OUTPUT ,
    .lcd_data[2].logic = GPIO_LOW ,
    
    .lcd_data[3].port  = PORTD_INDEX ,
    .lcd_data[3].pin = PIN3 ,
    .lcd_data[3].direction = GPIO_DIRECTION_OUTPUT ,
    .lcd_data[3].logic = GPIO_LOW ,
    
    .lcd_rs = PORTD_INDEX ,
    .lcd_rs.pin = PIN4 ,
    .lcd_rs.direction = GPIO_DIRECTION_OUTPUT ,
    .lcd_rs.logic = GPIO_LOW ,
    
    .lcd_en = PORTD_INDEX ,
    .lcd_en.pin = PIN5 ,
    .lcd_en.direction = GPIO_DIRECTION_OUTPUT ,
    .lcd_en.logic = GPIO_LOW 
};

/* =================== Motors ======================== */
dc_motor_t Motor_1 =
{
   .dc_motor_pin[0].port = PORTC_INDEX , 
   .dc_motor_pin[0].pin  = PIN0 ,
   .dc_motor_pin[0].direction = GPIO_DIRECTION_OUTPUT ,
   .dc_motor_pin[0].logic = GPIO_LOW ,
   
   .dc_motor_pin[1].port = PORTC_INDEX , 
   .dc_motor_pin[1].pin  = PIN1 ,
   .dc_motor_pin[1].direction = GPIO_DIRECTION_OUTPUT ,
   .dc_motor_pin[1].logic = GPIO_LOW 
};

dc_motor_t Motor_2 =
{
   .dc_motor_pin[0].port = PORTC_INDEX , 
   .dc_motor_pin[0].pin  = PIN2 ,
   .dc_motor_pin[0].direction = GPIO_DIRECTION_OUTPUT ,
   .dc_motor_pin[0].logic = GPIO_LOW ,
   
   .dc_motor_pin[1].port = PORTC_INDEX , 
   .dc_motor_pin[1].pin  = PIN3 ,
   .dc_motor_pin[1].direction = GPIO_DIRECTION_OUTPUT ,
   .dc_motor_pin[1].logic = GPIO_LOW 
};

dc_motor_t Motor_3 =
{
   .dc_motor_pin[0].port = PORTC_INDEX , 
   .dc_motor_pin[0].pin  = PIN4 ,
   .dc_motor_pin[0].direction = GPIO_DIRECTION_OUTPUT ,
   .dc_motor_pin[0].logic = GPIO_LOW ,
   
   .dc_motor_pin[1].port = PORTC_INDEX , 
   .dc_motor_pin[1].pin  = PIN5 ,
   .dc_motor_pin[1].direction = GPIO_DIRECTION_OUTPUT ,
   .dc_motor_pin[1].logic = GPIO_LOW 
};

dc_motor_t Motor_4 =
{
   .dc_motor_pin[0].port = PORTC_INDEX , 
   .dc_motor_pin[0].pin  = PIN6 ,
   .dc_motor_pin[0].direction = GPIO_DIRECTION_OUTPUT ,
   .dc_motor_pin[0].logic = GPIO_LOW ,
   
   .dc_motor_pin[1].port = PORTC_INDEX , 
   .dc_motor_pin[1].pin  = PIN7 ,
   .dc_motor_pin[1].direction = GPIO_DIRECTION_OUTPUT ,
   .dc_motor_pin[1].logic = GPIO_LOW 
};

/****************************** ^-^ Main Function Start ^-^ ***********************/
int main() 
{
    Std_ReturnType ret = E_NOK ;
    application_initialize();
    
    ret = LCD_4bit_Send_String_Pos(&lcd_1 , "Joy Stick wheelchair" , 1 , 1);
    ret = LCD_4bit_Send_String_Pos(&lcd_1 , " Using " , 2 , 7 );
    ret = LCD_4bit_Send_String_Pos(&lcd_1 , " PIC18F4620 " , 3 , 5 );
    __delay_ms(3000);
    ret = LCD_4bit_Send_Command(&lcd_1 , _LCD_CLEAR) ;
    
 
    while(1)
    {
           
    }
    return (EXIT_SUCCESS);
}
/****************************** ^-^ Main Function End ^-^ ************************/

/******************* ^-^ application_initialize Function Start ^-^ ****************/
void application_initialize (void)
{
    Std_ReturnType ret = E_NOK ;
    ecu_layer_initialize();
    ret = LCD_4bit_Initialize(&lcd_1);
    ret = dc_motor_initialize(&Motor_1);
    ret = dc_motor_initialize(&Motor_2);
    ret = dc_motor_initialize(&Motor_3);
    ret = dc_motor_initialize(&Motor_4);
    ret = Interrupt_RBx_Initialize(&rb3_int_obj);
    ret = Interrupt_RBx_Initialize(&rb4_int_obj);
    ret = Interrupt_RBx_Initialize(&rb5_int_obj);
    ret = Interrupt_RBx_Initialize(&rb6_int_obj);
    
}
/******************* ^-^ application_initialize Function End ^-^ *****************/

/******************* ^-^  Function Definition Start ^-^ *****************/
void Motor_Move_Forward (void)
{
    Std_ReturnType ret = E_NOK ;
    ret = dc_motor_move_right(&Motor_1);
    ret = dc_motor_move_right(&Motor_2);
    ret = dc_motor_move_right(&Motor_3);
    ret = dc_motor_move_right(&Motor_4);
    
}
void Motor_Move_Backward(void)
{
    Std_ReturnType ret = E_NOK ;
    ret = dc_motor_move_left(&Motor_1);
    ret = dc_motor_move_left(&Motor_2);
    ret = dc_motor_move_left(&Motor_3);
    ret = dc_motor_move_left(&Motor_4);
}
void Motor_Move_Right   (void)
{
    Std_ReturnType ret = E_NOK ;
    ret = dc_motor_move_right(&Motor_2);
    ret = dc_motor_move_right(&Motor_3);
    ret = dc_motor_move_right(&Motor_4);
    ret = dc_motor_stop(&Motor_1);
}
void Motor_Move_Left    (void)
{
    Std_ReturnType ret = E_NOK ;
    ret = dc_motor_move_right(&Motor_1);
    ret = dc_motor_move_right(&Motor_3);
    ret = dc_motor_move_right(&Motor_4);
    ret = dc_motor_stop(&Motor_2);
}
void Motor_Stop         (void)
{
    Std_ReturnType ret = E_NOK ;
    ret = dc_motor_stop(&Motor_1);
    ret = dc_motor_stop(&Motor_2);
    ret = dc_motor_stop(&Motor_3);
    ret = dc_motor_stop(&Motor_4);
}


void RB3_HIGH_Int_App_ISR (void)
{
    Std_ReturnType ret = E_NOK ;
    Motor_Move_Backward();
    ret = LCD_4bit_Send_Command(&lcd_1 , _LCD_CLEAR);
    ret = LCD_4bit_Send_String_Pos(&lcd_1 , " Motor status " , 1 , 1 );
    ret = LCD_4bit_Send_String_Pos(&lcd_1 , " Backward " , 2 , 1 );
    __delay_ms(500);
}
void RB3_LOW_Int_App_ISR (void)
{
    Std_ReturnType ret = E_NOK ;
    Motor_Stop() ;
    ret = LCD_4bit_Send_Command(&lcd_1 , _LCD_CLEAR);
    ret = LCD_4bit_Send_String_Pos(&lcd_1 , " Motor Stop " , 2 , 4 );
    __delay_ms(500);
    ret = LCD_4bit_Send_Command(&lcd_1 , _LCD_CLEAR);
}
void RB4_HIGH_Int_App_ISR (void)
{
    Std_ReturnType ret = E_NOK ;
    Motor_Move_Left();
    ret = LCD_4bit_Send_Command(&lcd_1 , _LCD_CLEAR);
    ret = LCD_4bit_Send_String_Pos(&lcd_1 , " Motor status " , 1 , 1 );
    ret = LCD_4bit_Send_String_Pos(&lcd_1 , " Left " , 2 , 1 );
    __delay_ms(500);
}
void RB4_LOW_Int_App_ISR (void)
{
    Std_ReturnType ret = E_NOK ;
    Motor_Stop() ;
    ret = LCD_4bit_Send_Command(&lcd_1 , _LCD_CLEAR);
    ret = LCD_4bit_Send_String_Pos(&lcd_1 , " Motor Stop " , 2 , 4 );
    __delay_ms(500);
    ret = LCD_4bit_Send_Command(&lcd_1 , _LCD_CLEAR);
}
void RB5_HIGH_Int_App_ISR (void)
{
    Std_ReturnType ret = E_NOK ;
    Motor_Move_Right();
    ret = LCD_4bit_Send_Command(&lcd_1 , _LCD_CLEAR);
    ret = LCD_4bit_Send_String_Pos(&lcd_1 , " Motor status " , 1 , 1 );
    ret = LCD_4bit_Send_String_Pos(&lcd_1 , " Right " , 2 , 1 );
    __delay_ms(500);
}
void RB5_LOW_Int_App_ISR (void)
{
    Std_ReturnType ret = E_NOK ;
    Motor_Stop() ;
    ret = LCD_4bit_Send_Command(&lcd_1 , _LCD_CLEAR);
    ret = LCD_4bit_Send_String_Pos(&lcd_1 , " Motor Stop " , 2 , 4 );
    __delay_ms(500);
    ret = LCD_4bit_Send_Command(&lcd_1 , _LCD_CLEAR);
}
void RB6_HIGH_Int_App_ISR (void)
{
    Std_ReturnType ret = E_NOK ;
    Motor_Move_Forward();
    ret = LCD_4bit_Send_Command(&lcd_1 , _LCD_CLEAR);
    ret = LCD_4bit_Send_String_Pos(&lcd_1 , " Motor status " , 1 , 1 );
    ret = LCD_4bit_Send_String_Pos(&lcd_1 , " Forward " , 2 , 1 );
    __delay_ms(500);
}
void RB6_LOW_Int_App_ISR (void)
{
    Std_ReturnType ret = E_NOK ;
    Motor_Stop() ;
    ret = LCD_4bit_Send_Command(&lcd_1 , _LCD_CLEAR);
    ret = LCD_4bit_Send_String_Pos(&lcd_1 , " Motor Stop " , 2 , 4 );
    __delay_ms(500);
    ret = LCD_4bit_Send_Command(&lcd_1 , _LCD_CLEAR);
}
/******************* ^-^  Function Definition End  ^-^ *****************/
