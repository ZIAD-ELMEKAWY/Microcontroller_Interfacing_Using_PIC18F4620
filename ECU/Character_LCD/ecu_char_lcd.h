/* 
 * File:   ecu_char_lcd.h
 * Author: ziad
 *
 * Created on 09 ?????, 2024, 05:45 ?
 */

#ifndef ECU_CHAR_LCD_H
#define	ECU_CHAR_LCD_H

/* Section : includes */
#include "ecu_char_lcd_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_GPIO.h" 

/* Section : Macro Declarations */
#define _LCD_CLEAR                                      0x01
#define _LCD_RETURN_HOME                                0x02
#define _LCD_ENTRY_M0ODE                                0x06
#define _LCD_CURSOR_OFF_DISPLAY_ON                      0x0C
#define _LCD_CURSOR_OFF_DISPLAY_OFF                     0x08
#define _LCD_CURSOR_ON_BLINK_ON                         0x0F
#define _LCD_CURSOR_ON_BLINK_OFF                        0x0E
#define _LCD_DISPLAY_SHIFT_RIGHT                        0x1C
#define _LCD_DISPLAY_SHIFT_LEFT                         0x18
#define _LCD_8BIT_MODE_2_LINE                           0x38
#define _LCD_4BIT_MODE_2_LINE                           0x28
#define _LCD_CGRAM_START                                0x40
#define _LCD_DDRAM_START                                0x80


#define ROW1    1
#define ROW2    2
#define ROW3    3
#define ROW4    4




/* Section : Macro Function Declarations */

/* Section : Data Type Declarations */
// Make two structure to make two LCD at the same time 
typedef struct{
    pin_config_t lcd_rs ;
    pin_config_t lcd_en ;
    pin_config_t lcd_data[4];
}chr_lcd_4bit_t;

typedef struct{
    pin_config_t lcd_rs ;
    pin_config_t lcd_en ;
    pin_config_t lcd_data[8];
}chr_lcd_8bit_t;
/* Section : Function Declarations */

// 4-bit
Std_ReturnType LCD_4bit_Initialize          (const chr_lcd_4bit_t *lcd );
Std_ReturnType LCD_4bit_Send_Command        (const chr_lcd_4bit_t *lcd , uint8 command);
Std_ReturnType LCD_4bit_Send_Char_Data      (const chr_lcd_4bit_t *lcd , uint8 data);
Std_ReturnType LCD_4bit_Send_Char_Data_Pos  (const chr_lcd_4bit_t *lcd , uint8 data , uint8 row , uint8 column);
Std_ReturnType LCD_4bit_Send_String         (const chr_lcd_4bit_t *lcd , uint8 *str );
Std_ReturnType LCD_4bit_Send_String_Pos     (const chr_lcd_4bit_t *lcd , uint8 *str , uint8 row , uint8 column);
Std_ReturnType LCD_4bit_Send_Custome_Char   (const chr_lcd_4bit_t *lcd , const uint8 _char[] , uint8 row , uint8 column , uint8 mem_pos);

//8-bit
Std_ReturnType LCD_8bit_Initialize          (const chr_lcd_8bit_t *lcd );
Std_ReturnType LCD_8bit_Send_Command        (const chr_lcd_8bit_t *lcd , uint8 command);
Std_ReturnType LCD_8bit_Send_Char_Data      (const chr_lcd_8bit_t *lcd , uint8 data);
Std_ReturnType LCD_8bit_Send_Char_Data_Pos  (const chr_lcd_8bit_t *lcd , uint8 data , uint8 row , uint8 column);
Std_ReturnType LCD_8bit_Send_String         (const chr_lcd_8bit_t *lcd , uint8 *str);
Std_ReturnType LCD_8bit_Send_String_Pos     (const chr_lcd_8bit_t *lcd , uint8 *str , uint8 row , uint8 column);
Std_ReturnType LCD_8bit_Send_Custome_Char   (const chr_lcd_8bit_t *lcd , const uint8 _char[] , uint8 row , uint8 column , uint8 mem_pos);

// Helper Function
Std_ReturnType convert_uint8_to_string              (uint8 value  , uint8 *str);
Std_ReturnType convert_uint16_to_string             (uint16 value , uint8 *str);
Std_ReturnType convert_uint32_to_string             (uint32 value , uint8 *str);
static Std_ReturnType LCD_Send_4bits                (const chr_lcd_4bit_t *lcd , uint8 _data_command);
static Std_ReturnType LCD_4bit_Send_Enable_Signal   (const chr_lcd_4bit_t *lcd );
static Std_ReturnType LCD_4bit_set_cursor           (const chr_lcd_4bit_t *lcd , uint8 row , uint8 column);
static Std_ReturnType LCD_8bit_Send_Enable_Signal   (const chr_lcd_8bit_t *lcd );
static Std_ReturnType LCD_8bit_set_cursor           (const chr_lcd_8bit_t *lcd , uint8 row , uint8 column);


#endif	/* ECU_CHAR_LCD_H */

