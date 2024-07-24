/* 
 * File:   ecu_char_lcd.h
 * Author: ziad
 *
 * Created on 09 ?????, 2024, 05:45 ?
 */

/********************* Section : Include  *******************/
#include "ecu_char_lcd.h"

/********************* Section : Function Definition *******************/
// 4-bit
Std_ReturnType LCD_4bit_Initialize (const chr_lcd_4bit_t *lcd )
{
    Std_ReturnType ret = E_OK;
    uint8 l_data_pins_counter ;
    if(NULL == lcd)
    {
        ret = E_NOK;
    }
    else 
    {
        ret = gpio_pin_intialize(&(lcd->lcd_rs));
        ret = gpio_pin_intialize(&(lcd->lcd_en));
        for (l_data_pins_counter =0 ; l_data_pins_counter<4 ; l_data_pins_counter++)
        {
            ret = gpio_pin_intialize(&(lcd->lcd_data[l_data_pins_counter]));
        }
        __delay_ms(20);
        ret = LCD_4bit_Send_Command(lcd , _LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = LCD_4bit_Send_Command(lcd , _LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        ret = LCD_4bit_Send_Command(lcd , _LCD_8BIT_MODE_2_LINE);   
        ret = LCD_4bit_Send_Command(lcd , _LCD_CLEAR);
        ret = LCD_4bit_Send_Command(lcd , _LCD_RETURN_HOME);
        ret = LCD_4bit_Send_Command(lcd , _LCD_ENTRY_M0ODE);
        ret = LCD_4bit_Send_Command(lcd , _LCD_CURSOR_OFF_DISPLAY_ON);
        ret = LCD_4bit_Send_Command(lcd , _LCD_4BIT_MODE_2_LINE);
        ret = LCD_4bit_Send_Command(lcd , 0x80);         // start of line one
    }
    return ret ;
}
Std_ReturnType LCD_4bit_Send_Command   (const chr_lcd_4bit_t *lcd , uint8 command)
{
    Std_ReturnType ret = E_OK;
    if(NULL == lcd)
    {
        ret = E_NOK;
    }
    else 
    {
        ret = gpio_pin_write_logic(&(lcd->lcd_rs),GPIO_LOW);     // to send command RS must be low
        ret = LCD_Send_4bits(lcd , (command >> 4));
        ret = LCD_4bit_Send_Enable_Signal(lcd);
        ret = LCD_Send_4bits(lcd , command );
        ret = LCD_4bit_Send_Enable_Signal(lcd);
    }
    return ret ;
}
Std_ReturnType LCD_4bit_Send_Char_Data (const chr_lcd_4bit_t *lcd , uint8 data)
{
    Std_ReturnType ret = E_OK;
    if(NULL == lcd)
    {
        ret = E_NOK;
    }
    else 
    {
        ret = gpio_pin_write_logic(&(lcd->lcd_rs),GPIO_HIGH);     // to send data RS must be high
        ret = LCD_Send_4bits(lcd , (data >> 4));
        ret = LCD_4bit_Send_Enable_Signal(lcd);
        ret = LCD_Send_4bits(lcd , data );
        ret = LCD_4bit_Send_Enable_Signal(lcd);
    }
    return ret ;
}
Std_ReturnType LCD_4bit_Send_Char_Data_Pos (const chr_lcd_4bit_t *lcd , uint8 data , uint8 row , uint8 column)
{
    Std_ReturnType ret = E_OK;
    if(NULL == lcd)
    {
        ret = E_NOK;
    }
    else 
    {
        ret = LCD_4bit_set_cursor(lcd , row , column);
        ret = LCD_4bit_Send_Char_Data(lcd , data);
    }
    return ret ;
}

Std_ReturnType LCD_4bit_Send_String    (const chr_lcd_4bit_t *lcd , uint8 *str )
{
    Std_ReturnType ret = E_OK;
    if((NULL == lcd) || (NULL == str))
    {
        ret = E_NOK;
    }
    else 
    {
        while(*str)
        {
            ret = LCD_4bit_Send_Char_Data(lcd , *str++); 
        }
    }
    return ret ;
}

Std_ReturnType LCD_4bit_Send_String_Pos    (const chr_lcd_4bit_t *lcd , uint8 *str , uint8 row , uint8 column)
{
    Std_ReturnType ret = E_OK;
    if((NULL == lcd) || (NULL == str))
    {
        ret = E_NOK;
    }
    else 
    {
        ret = LCD_4bit_set_cursor(lcd , row , column);
        while(*str)
        {
            ret = LCD_4bit_Send_Char_Data(lcd , *str++); 
        }
    }
    return ret ;
}
Std_ReturnType LCD_4bit_Send_Custome_Char  (const chr_lcd_4bit_t *lcd , const uint8 _char[] , uint8 row , uint8 column , uint8 mem_pos)
{
    Std_ReturnType ret = E_OK;
    uint8 lcd_counter ;
    if(NULL == lcd)
    {
        ret = E_NOK;
    }
    else 
    {
        ret = LCD_4bit_Send_Command(lcd ,(_LCD_CGRAM_START+(mem_pos*8)) );
        for (lcd_counter = 0 ; lcd_counter<=7 ; ++lcd_counter)
        {
            ret = LCD_4bit_Send_Char_Data(lcd , _char[lcd_counter]);
        }
        ret = LCD_4bit_Send_Char_Data_Pos(lcd , mem_pos , row , column);
    }
    return ret ;
}
/***********************************************************************************************************************************************/
//8-bit
Std_ReturnType LCD_8bit_Initialize (const chr_lcd_8bit_t *lcd )
{
    Std_ReturnType ret = E_OK;
    uint8 l_data_pins_counter ;
    if(NULL == lcd)
    {
        ret = E_NOK;
    }
    else 
    {
        ret = gpio_pin_intialize(&(lcd->lcd_rs));
        ret = gpio_pin_intialize(&(lcd->lcd_en));
        for (l_data_pins_counter =0 ; l_data_pins_counter<8 ; l_data_pins_counter++)
        {
            ret = gpio_pin_intialize(&(lcd->lcd_data[l_data_pins_counter]));
        }
        __delay_ms(20);
        ret = LCD_8bit_Send_Command(lcd , _LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = LCD_8bit_Send_Command(lcd , _LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        ret = LCD_8bit_Send_Command(lcd , _LCD_8BIT_MODE_2_LINE);   
        ret = LCD_8bit_Send_Command(lcd , _LCD_CLEAR);
        ret = LCD_8bit_Send_Command(lcd , _LCD_RETURN_HOME);
        ret = LCD_8bit_Send_Command(lcd , _LCD_ENTRY_M0ODE);
        ret = LCD_8bit_Send_Command(lcd , _LCD_CURSOR_OFF_DISPLAY_ON);
        ret = LCD_8bit_Send_Command(lcd , _LCD_8BIT_MODE_2_LINE);
        ret = LCD_8bit_Send_Command(lcd , 0x80);         // start of line one
    }
    return ret ;
}
Std_ReturnType LCD_8bit_Send_Command   (const chr_lcd_8bit_t *lcd , uint8 command)
{
    Std_ReturnType ret = E_OK;
    uint8 pin_counter ;
    if(NULL == lcd)
    {
        ret = E_NOK;
    }
    else 
    {
        ret = gpio_pin_write_logic(&(lcd->lcd_rs),GPIO_LOW);     // to send command RS must be low
        for(pin_counter =0 ; pin_counter < 8 ; ++pin_counter)
        {
            ret = gpio_pin_write_logic(&(lcd->lcd_data[pin_counter]), ((command>>pin_counter) & (uint8)0x01));
        }
        ret = LCD_8bit_Send_Enable_Signal(lcd);
    }
    return ret ;
}
Std_ReturnType LCD_8bit_Send_Char_Data (const chr_lcd_8bit_t *lcd , uint8 data)
{
    Std_ReturnType ret = E_OK;
    uint8 pin_counter ;
    if(NULL == lcd)
    {
        ret = E_NOK;
    }
    else 
    {
        ret = gpio_pin_write_logic(&(lcd->lcd_rs),GPIO_HIGH);
        for(pin_counter =0 ; pin_counter < 8 ; ++pin_counter)
        {
            ret = gpio_pin_write_logic(&(lcd->lcd_data[pin_counter]), ((data>>pin_counter) & (uint8)0x01));
        }
        ret = LCD_8bit_Send_Enable_Signal(lcd);
    }
    return ret ;
}
Std_ReturnType LCD_8bit_Send_Char_Data_Pos (const chr_lcd_8bit_t *lcd , uint8 data , uint8 row , uint8 column)
{
    Std_ReturnType ret = E_OK;
    if(NULL == lcd)
    {
        ret = E_NOK;
    }
    else 
    {
        ret = LCD_8bit_set_cursor(lcd , row , column );
        ret = LCD_8bit_Send_Char_Data(lcd , data) ;
    }
    return ret ;
}
Std_ReturnType LCD_8bit_Send_String    (const chr_lcd_8bit_t *lcd , uint8 *str)
{
    Std_ReturnType ret = E_OK;
    if((NULL == lcd) || (str == NULL))
    {
        ret = E_NOK;
    }
    else 
    {
        while(*str)
        {
            ret = LCD_8bit_Send_Char_Data(lcd , *str++); 
        }
    }
    return ret ;
}

Std_ReturnType LCD_8bit_Send_String_Pos    (const chr_lcd_8bit_t *lcd , uint8 *str , uint8 row , uint8 column)
{
    Std_ReturnType ret = E_OK;
    if((NULL == lcd) || (str == NULL))
    {
        ret = E_NOK;
    }
    else 
    {
        ret = LCD_8bit_set_cursor(lcd , row , column );
        while(*str)
        {
            ret = LCD_8bit_Send_Char_Data(lcd , *str++); 
        }
    }
    return ret ;
}
Std_ReturnType LCD_8bit_Send_Custome_Char  (const chr_lcd_8bit_t *lcd , const uint8 _char[] , uint8 row , uint8 column , uint8 mem_pos)
{
    Std_ReturnType ret = E_OK;
    uint8 lcd_counter = 0 ;
    if(NULL == lcd)
    {
        ret = E_NOK;
    }
    else 
    {
        ret = LCD_8bit_Send_Command(lcd ,(_LCD_CGRAM_START+(mem_pos*8)) );
        for (lcd_counter = 0 ; lcd_counter<=7 ; ++lcd_counter)
        {
            ret = LCD_8bit_Send_Char_Data(lcd , _char[lcd_counter]);
        }
        ret = LCD_8bit_Send_Char_Data_Pos(lcd , mem_pos , row , column);
    }
    return ret ;
}

/***********************************************************************************************************************************************/
// Helper Function
Std_ReturnType convert_uint8_to_string  (uint8 value  , uint8 *str)
{
    Std_ReturnType ret = E_OK;
    if(NULL == str)
    {
        ret = E_NOK;
    }
    else 
    {
        memset(str , '\0' , 4);
        sprintf(str , "%i" , value);
    }
    return ret ;
}
Std_ReturnType convert_uint16_to_string (uint16 value , uint8 *str)
{
    Std_ReturnType ret = E_OK;
    if(NULL == str)
    {
        ret = E_NOK;
    }
    else 
    {
        memset(str , '\0' , 6);
        sprintf(str , "%i" , value);
    }
    return ret ;
}
Std_ReturnType convert_uint32_to_string   (uint32 value , uint8 *str)
{
    Std_ReturnType ret = E_OK;
    if(NULL == str)
    {
        ret = E_NOK;
    }
    else 
    {
        memset(str , '\0' , 11);
        sprintf(str , "%i" , value);
    }
    return ret ;
}
static Std_ReturnType LCD_Send_4bits(const chr_lcd_4bit_t *lcd , uint8 _data_command)
{
    Std_ReturnType ret = E_OK;
    if(NULL == lcd)
    {
        ret = E_NOK;
    }
    else 
    {
        ret = gpio_pin_write_logic(&(lcd->lcd_data[0]), ((_data_command>>0) & (uint8)0x01));
        ret = gpio_pin_write_logic(&(lcd->lcd_data[1]), ((_data_command>>1) & (uint8)0x01));
        ret = gpio_pin_write_logic(&(lcd->lcd_data[2]), ((_data_command>>2) & (uint8)0x01));
        ret = gpio_pin_write_logic(&(lcd->lcd_data[3]), ((_data_command>>3) & (uint8)0x01));
    }
    return ret ;
}
static Std_ReturnType LCD_4bit_Send_Enable_Signal(const chr_lcd_4bit_t *lcd )
{
    Std_ReturnType ret = E_OK;
    if(NULL == lcd)
    {
        ret = E_NOK;
    }
    else 
    {
        ret = gpio_pin_write_logic(&(lcd->lcd_en), GPIO_HIGH);
        __delay_us(5);
        ret = gpio_pin_write_logic(&(lcd->lcd_en), GPIO_LOW);
    }
    return ret ;
}
static Std_ReturnType LCD_8bit_Send_Enable_Signal(const chr_lcd_8bit_t *lcd )
{
    Std_ReturnType ret = E_OK;
    if(NULL == lcd)
    {
        ret = E_NOK;
    }
    else 
    {
        ret = gpio_pin_write_logic(&(lcd->lcd_en), GPIO_HIGH);
        __delay_us(5);
        ret = gpio_pin_write_logic(&(lcd->lcd_en), GPIO_LOW);
    }
    return ret ;
}
static Std_ReturnType LCD_8bit_set_cursor(const chr_lcd_8bit_t *lcd , uint8 row , uint8 column)
{
    Std_ReturnType ret = E_OK;
    column-- ;  
    if(NULL == lcd)
    {
        ret = E_NOK;
    }
    else 
    {
        switch (row)
        {
        case ROW1 : 
            ret = LCD_8bit_Send_Command(lcd , (0x80+column)); 
            break ;
        case ROW2 : 
            ret = LCD_8bit_Send_Command(lcd , (0xc0+column)); 
            break ;
        case ROW3 : 
            ret = LCD_8bit_Send_Command(lcd , (0x94+column)); 
            break ;
        case ROW4 : 
            ret = LCD_8bit_Send_Command(lcd , (0xd4+column)); 
            break ;
        }
    }
    return ret ;
}

static Std_ReturnType LCD_4bit_set_cursor(const chr_lcd_4bit_t *lcd , uint8 row , uint8 column)
{
    Std_ReturnType ret = E_OK;
    column-- ;  
    if(NULL == lcd)
    {
        ret = E_NOK;
    }
    else 
    {
        switch (row)
        {
        case ROW1 : 
            ret = LCD_4bit_Send_Command(lcd , (0x80+column)); 
            break ;
        case ROW2 : 
            ret = LCD_4bit_Send_Command(lcd , (0xc0+column)); 
            break ;
        case ROW3 : 
            ret = LCD_4bit_Send_Command(lcd , (0x94+column)); 
            break ;
        case ROW4 : 
            ret = LCD_4bit_Send_Command(lcd , (0xd4+column)); 
            break ;
        }
    }
    return ret ;
}
/***********************************************************************************************************************************************/