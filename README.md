# PIC18F4620-Driver
## Driver for PIC18F4620 with many projects. 
## For more information : [https://rightful-hawk-670.notion.site/microcontroller-38c62297c2804bcc8aa5715c66834b3b?pvs=4](url)
## Layers
  ### 1) __MCAL layer__
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
  ### 2) __ECU layer__
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
 ### 3) __Application Layer__
       a) applicaion ( in header file )
------------------------------------------------------------------------------------------------------------------------
  ### 4) Project 
       a) Traffic Control ( is an aaplication.c ) 
       b) Password security system ( is an aaplication.c )
       c) Joystick wheelchair  ( is an aaplication.c )
       d) Autonomus Car  ( is an aaplication.c )
       e) Interface EUSART Transmit and receive  ( is an aaplication.c )
       f) Calculator  ( is an aaplication.c )
       g) Smart home  ( is an aaplication.c ) 
     
------------------------------------------------------------------------------------------------------------------------
