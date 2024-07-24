/* 
 * File:   mcal_interrupt_manager.h
 * Author: Ziad
 *
 * Created on 17 July 2024, 10:06 
 */

/******************** Section : Includes *************************/
#include "mcal_interrupt_manager.h"

/******************** Section : Functions definitions *************************/
static volatile uint8 RB4_Flag = 1 ,RB5_Flag = 1 ,RB6_Flag = 1 , RB7_Flag = 1   ;

#ifdef _INTERRUPT_PERIORITY_LEVELS_ENABLE
/**
 * @name INTERRUPT_ManagerHigh
 * @return  void
 * @param   void
 * @note    1)  [__interrupt] is used to detect that this function is interrupt ISR not a normal function
 *          2)  [__interrupt] is called an interrupt qualifier
 */
void __interrupt() INTERRUPT_ManagerHigh (void) 
{
    if ((INTCONbits.INT0IE == INTERRUPT_ENABLE) && (INTERRUPT_OCCUR == INTCONbits.INT0IF))
    {
        INT0_ISR();
    }
    else 
    {
        /* Nothing */
    }
    if ((INTCON3bits.INT2IE == INTERRUPT_ENABLE) && (INTERRUPT_OCCUR == INTCON3bits.INT2IF))
    {
        INT2_ISR();
    }
    else 
    {
        /* Nothing */
    }
}

/**
 * @name INTERRUPT_ManagerLow
 * @return  void
 * @param   void
 * @note    1) [__interrupt(low_priority)] is used to detect that this function is interrupt ISR not a normal function
 *          2) [__interrupt(low_priority)] is called an interrupt qualifier
 */
void __interrupt(low_priority) INTERRUPT_ManagerLow(void)
{
    if ((INTCON3bits.INT1IE == INTERRUPT_ENABLE) && (INTERRUPT_OCCUR == INTCON3bits.INT1IF))
    {
        INT1_ISR();
    }
    else 
    {
        /* Nothing */
    }
}

#else
void __interrupt() INTERRUPT_Manager (void) 
{
    /* for INTx */
    if ((INTCONbits.INT0IE == INTERRUPT_ENABLE) && (INTERRUPT_OCCUR == INTCONbits.INT0IF))
    {
        INT0_ISR();
    }
    else 
    {
        /* Nothing */
    }
    if ((INTCON3bits.INT1IE == INTERRUPT_ENABLE) && (INTERRUPT_OCCUR == INTCON3bits.INT1IF))
    {
        INT1_ISR();
    }
    else 
    {
        /* Nothing */
    }
    if ((INTCON3bits.INT2IE == INTERRUPT_ENABLE) && (INTERRUPT_OCCUR == INTCON3bits.INT2IF))
    {
        INT2_ISR();
    }
    else 
    {
        /* Nothing */
    }
    
    /******************************* for RBx On Change external interrupt *******************************/
    /* @note     1) make interrupt when the voltage change form 0 to 5 
     *           2) we add [ RB4_Flag == 1 ] -> to prevent the compiler to get into the low condition 
     */
    
    /*========================== RB4 ==========================*/
    if ((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB4 == GPIO_HIGH) && (RB4_Flag == 1))
    {
        RB4_Flag = 0 ;
        RB4_ISR(0); // 0 if high
    }
    else 
    {
        /* Nothing */
    }
    /* @note     1) make interrupt when the voltage change form 5 to 0 */
    if ((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB4 == GPIO_LOW) && (RB4_Flag == 0))
    {
        RB4_Flag = 1 ;
        RB4_ISR(1);  // 1 if low
    }
    else 
    {
        /* Nothing */
    }
   /*========================== RB5 ==========================*/
    if ((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB5 == GPIO_HIGH) && (RB5_Flag == 1))
    {
        RB5_Flag = 0 ;
        RB5_ISR(0); // 0 if high
    }
    else 
    {
        /* Nothing */
    }
    if ((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB5 == GPIO_LOW) && (RB5_Flag == 0))
    {
        RB5_Flag = 1 ;
        RB5_ISR(1);  // 1 if low
    }
    else 
    {
        /* Nothing */
    }
    /*========================== RB6 ==========================*/
    if ((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB6 == GPIO_HIGH) && (RB6_Flag == 1))
    {
        RB6_Flag = 0 ;
        RB6_ISR(0); // 0 if high
    }
    else 
    {
        /* Nothing */
    }
    if ((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB6 == GPIO_LOW) && (RB6_Flag == 0))
    {
        RB6_Flag = 1 ;
        RB6_ISR(1);  // 1 if low
    }
    else 
    {
        /* Nothing */
    }
    /*========================== RB7 ==========================*/
    if ((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB7 == GPIO_HIGH) && (RB7_Flag == 1))
    {
        RB7_Flag = 0 ;
        RB7_ISR(0); // 0 if high
    }
    else 
    {
        /* Nothing */
    }
    if ((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB7 == GPIO_LOW) && (RB7_Flag == 0))
    {
        RB7_Flag = 1 ;
        RB7_ISR(1);  // 1 if low
    }
    else 
    {
        /* Nothing */
    }
    /******************************* for RBx On Change external interrupt *******************************/
}
#endif
