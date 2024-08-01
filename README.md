# PIC18F4620-Driver
![]([https://myoctocat.com/assets/images/base-octocat.svg](https://5.imimg.com/data5/TY/EM/MY-3386804/pic18f4620-i-2fp-pic-microcontroller-1000x1000.png))
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
  4) Project Layer
       a) Traffic Control ( is an aaplication.c ) 

------------------------------------------------------------------------------------------------------------------------
