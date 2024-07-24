# PIC18F4620-Driver
Driver for PIC18F4620 with many projects. 

#Layers
  1) MCAL layer
       a) Device config
       b) MCAL_STD_Types ( standard types )
       c) STD_Libraries  ( standard libraries )
       d) Compiler
       e) GPIO
         * hal_GPIO
       f) Interrupt
         * MCAL_External_Interrupt
         * MCAL_Internal_Interrupt
         * MCAL_Interrupt_Manager
         * MCAL_Interrupt_Config ( in header file )
       g) Timer
         * HAL_Timer0
     
-------------------------------------------------------------------------------------------------------------------------
  2) ECU layer
       a) ECU_Layer_Initialization : is used to initialize ECU modules instead of initialize it in application layer (readability).
       b) Button
         * Button
         * Button_config ( in header file )
       c) CHAR_LCD
         * hal_GPIO
         * hal_GPIO_config ( in header file )
       d) DC_Motor
         * DC_Motor
         * DC_Motor_Config ( in header file )
       e) Keypad
         * Keypad
         * Keypad_Config ( in header file )
       f) Seven Segment
         * Seven_Segment
         * Seven_Segment_Config ( in header file )
       g) Relay
         * Relay
         * Relay_Config
------------------------------------------------------------------------------------------------------------------------
  3) Application Layer

------------------------------------------------------------------------------------------------------------------------
