/* 
 * File:   mcal_external_interrupt.c
 * Author: Ziad
 *
 * Created on 17 July, 2024, 10:04 
 */


/******************** Section : Includes *************************/
#include "mcal_external_interrupt.h"

/*************************** Helper Function Declaration **********************/
static void (*INT0_InterruptHandler)(void) = NULL ;
static void (*INT1_InterruptHandler)(void) = NULL ;
static void (*INT2_InterruptHandler)(void) = NULL ;

static void (*RB4_InterruptHandler_HIGH)(void) = NULL ;
static void (*RB4_InterruptHandler_LOW )(void) = NULL ;
static void (*RB5_InterruptHandler_HIGH)(void) = NULL ;
static void (*RB5_InterruptHandler_LOW )(void) = NULL ;
static void (*RB6_InterruptHandler_HIGH)(void) = NULL ;
static void (*RB6_InterruptHandler_LOW )(void) = NULL ;
static void (*RB7_InterruptHandler_HIGH)(void) = NULL ;
static void (*RB7_InterruptHandler_LOW )(void) = NULL ;

static Std_ReturnType Interrupt_INTx_Enable           (const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Disable          (const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Periority_Init   (const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Edge_Init        (const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Pin_Init         (const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Clear_Flag       (const interrupt_INTx_t *int_obj);

static Std_ReturnType INT0_SetInterruptHandler       (void (*InterruptHandler)(void));
static Std_ReturnType INT1_SetInterruptHandler       (void (*InterruptHandler)(void));
static Std_ReturnType INT2_SetInterruptHandler       (void (*InterruptHandler)(void));
static Std_ReturnType Interrupt_INTx_SetInterruptHandler    (const interrupt_INTx_t *int_obj);

static Std_ReturnType Interrupt_RBx_Enable           (const interrupt_RBx_t *int_obj);
static Std_ReturnType Interrupt_RBx_Disable          (const interrupt_RBx_t *int_obj);
static Std_ReturnType Interrupt_RBx_Periority_Init   (const interrupt_RBx_t *int_obj);
static Std_ReturnType Interrupt_RBx_Pin_Init         (const interrupt_RBx_t *int_obj);

/******************** Section : Functions definitions *************************/
/**************************** INTx Function definitions ***********************/

/**
 * @name  Interrupt_INTx_Initialize
 * @param int_obj
 * @return 
 */
Std_ReturnType Interrupt_INTx_Initialize    (const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK ;
    if (int_obj == NULL)
    {
        ret = E_NOK ;
    }
    else
    {
        /* Disable the external interrupt */
        ret = Interrupt_INTx_Disable(int_obj);
        /* Clear the external interrupt Flag : mean didn't occur */
        ret = Interrupt_INTx_Clear_Flag(int_obj);
        /* configure the external interrupt edge */
        ret = Interrupt_INTx_Edge_Init(int_obj);
        #ifdef _INTERRUPT_PERIORITY_LEVELS_ENABLE 
        /* configure the external interrupt priority */
        ret = Interrupt_INTx_Periority_Init(int_obj);
        #endif
        /* configure the external interrupt I/O pins */
        ret = Interrupt_INTx_Pin_Init(int_obj);
        /* configure default interrupt callback */
        ret = Interrupt_INTx_SetInterruptHandler(int_obj);
        /* Enable the external interrupt  */
        ret = Interrupt_INTx_Enable(int_obj);
    }
    return ret ;
}

/********************* ISR Function ***********************/
void INT0_ISR (void)
{
    /* The INT0 external interrupt occurred ( must be cleared is software )*/
    EXT_INT0_InterruptFlagClear();
    /* code */
    
    /* Callback function gets called every time this ISR executes */
    if(INT0_InterruptHandler) { INT0_InterruptHandler();}
}

void INT1_ISR (void)
{
    /* The INT1 external interrupt occurred ( must be cleared is software )*/
    EXT_INT1_InterruptFlagClear();
    /* code */
    
    /* Callback function gets called every time this ISR executes */
    if(INT1_InterruptHandler) { INT1_InterruptHandler();}
}

void INT2_ISR (void)
{
    /* The INT2 external interrupt occurred ( must be cleared is software )*/
    EXT_INT2_InterruptFlagClear();
    /* code */
    
    /* Callback function gets called every time this ISR executes */
    if(INT2_InterruptHandler) { INT2_InterruptHandler();}
}
/**************************************** RBx on change type *************************/
/* =========================== RB4 =============================*/
void RB4_ISR  (uint8 RB4_Source )
{
    /* The INT0 external interrupt occurred ( must be cleared is software )*/
    EXT_RBx_InterruptFlagClear();
    /* code */
    
    /* Callback function gets called every time this ISR executes */
    if (0 == RB4_Source)
    {
        if(RB4_InterruptHandler_HIGH) { RB4_InterruptHandler_HIGH();}
        else {/* Nothing */}
    }
    else if (1 == RB4_Source)
    {
        if(RB4_InterruptHandler_LOW) { RB4_InterruptHandler_LOW();}
        else {/* Nothing */}
    }
    else {/* Nothing */}
}
/* =========================== RB5 =============================*/
void RB5_ISR  (uint8 RB5_Source)
{
    /* The INT0 external interrupt occurred ( must be cleared is software )*/
    EXT_RBx_InterruptFlagClear();
    /* code */
    
    /* Callback function gets called every time this ISR executes */
    if (0 == RB5_Source)
    {
        if(RB5_InterruptHandler_HIGH) { RB5_InterruptHandler_HIGH();}
        else {/* Nothing */}
    }
    else if (1 == RB5_Source)
    {
        if(RB5_InterruptHandler_LOW) { RB5_InterruptHandler_LOW();}
        else {/* Nothing */}
    }
    else {/* Nothing */}
}
/* =========================== RB6 =============================*/
void RB6_ISR  (uint8 RB6_Source)
{
    /* The INT0 external interrupt occurred ( must be cleared is software )*/
    EXT_RBx_InterruptFlagClear();
    /* code */
    
    /* Callback function gets called every time this ISR executes */
    if (0 == RB6_Source)
    {
        if(RB6_InterruptHandler_HIGH) { RB6_InterruptHandler_HIGH();}
        else {/* Nothing */}
    }
    else if (1 == RB6_Source)
    {
        if(RB6_InterruptHandler_LOW) { RB6_InterruptHandler_LOW();}
        else {/* Nothing */}
    }
    else {/* Nothing */}
}
/* =========================== RB7 =============================*/
void RB7_ISR  (uint8 RB7_Source)
{
    /* The INT0 external interrupt occurred ( must be cleared is software )*/
    EXT_RBx_InterruptFlagClear();
    /* code */
    
    /* Callback function gets called every time this ISR executes */
    if (0 == RB7_Source)
    {
        if(RB7_InterruptHandler_HIGH) { RB7_InterruptHandler_HIGH();}
        else {/* Nothing */}
    }
    else if (1 == RB7_Source)
    {
        if(RB7_InterruptHandler_LOW) { RB7_InterruptHandler_LOW();}
        else {/* Nothing */}
    }
    else {/* Nothing */}
}
/************************************************************************************/
/**
 * @name  Interrupt_INTx_Deinitialize
 * @param int_obj
 * @return 
 */
Std_ReturnType Interrupt_INTx_Deinitialize  (const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK ;
    if (int_obj == NULL)
    {
        ret = E_NOK ;
    }
    else
    {
        ret = Interrupt_INTx_Disable(int_obj);
    }
    return ret ;
}

/************************** RBx Function Declaration *************************/
/**
 * @name  Interrupt_RBx_Initialize
 * @param int_obj
 * @return 
 */
Std_ReturnType Interrupt_RBx_Initialize     (const interrupt_RBx_t *int_obj)
{
    Std_ReturnType ret = E_OK ;
    if (int_obj == NULL)
    {
        ret = E_NOK ;
    }
    else
    {
        /* Disable the interrupt RBx */
        EXT_RBx_InterruptDisable();
        /* Clear the flag for the interrupt RBx */
        EXT_RBx_InterruptFlagClear();
#ifdef _INTERRUPT_PERIORITY_LEVELS_ENABLE 
            INTERRUPT_PeriortyLevelEnable();
            if (INTERRUPT_LOW_PRIORITY == int_obj->priority){
                INTERRUPT_GlobalInterruptLowEnable();
                EXT_RBx_InterruptLowPerioritySet();
            }
            else if (INTERRUPT_HIGH_PRIORITY == int_obj->priority){
                INTERRUPT_GlobalInterruptHighEnable();
                EXT_RBx_InterruptHighPerioritySet();
            }
            else{/*nothing*/}
#else
            INTERRUPT_GlobalInterruptEnable();
            INTERRUPT_PeripheralInterruptEnable();
#endif
            /* Initialize the RBx to be input */
            ret = gpio_pin_direction_intialize(&(int_obj->mcu_pin));
            /* Initialize the callback functions */
         switch(int_obj->mcu_pin.pin)
         {
            case PIN4 :
                RB4_InterruptHandler_HIGH = (int_obj->EXT_InterruptHandlerHigh);
                RB4_InterruptHandler_LOW  = (int_obj->EXT_InterruptHandlerLow );
                break ;
            case PIN5 :
                RB5_InterruptHandler_HIGH = (int_obj->EXT_InterruptHandlerHigh);
                RB5_InterruptHandler_LOW  = (int_obj->EXT_InterruptHandlerLow );
                break ; 
            case PIN6 :
                RB6_InterruptHandler_HIGH = (int_obj->EXT_InterruptHandlerHigh);
                RB6_InterruptHandler_LOW  = (int_obj->EXT_InterruptHandlerLow );
                break ; 
            case PIN7 :
                RB7_InterruptHandler_HIGH = (int_obj->EXT_InterruptHandlerHigh);
                RB7_InterruptHandler_LOW  = (int_obj->EXT_InterruptHandlerLow );
                break ;
            default : 
                ret = E_NOK ;
         }
        /* Enable the interrupt RBx */
        EXT_RBx_InterruptEnable();
    }
    return ret ;
}

/**
 * @name  Interrupt_RBx_Deinitialize
 * @param int_obj
 * @return 
 */
Std_ReturnType Interrupt_RBx_Deinitialize   (const interrupt_RBx_t *int_obj)
{
    Std_ReturnType ret = E_OK ;
    if (int_obj == NULL)
    {
        ret = E_NOK ;
    }
    else
    {
        
    }
    return ret ;
}

/********************* Helper Function ***********************/
/**
 * @name  Interrupt_INTx_Enable
 * @param int_obj
 * @return 
 */
static Std_ReturnType Interrupt_INTx_Enable           (const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK ;
    if (int_obj == NULL)
    {
        ret = E_NOK ;
    }
    else
    {
        switch (int_obj->source)
        {
            case INTERRUPT_EXTERNAL_INT0 : 
                INTERRUPT_PeriortyLevelEnable();
#ifdef _INTERRUPT_PERIORITY_LEVELS_ENABLE 
                INTERRUPT_GlobalInterruptHighEnable();
#else
                INTERRUPT_GlobalInterruptEnable();
                INTERRUPT_PeripheralInterruptEnable();
#endif
                
                EXT_INT0_InterruptEnable() ; 
                ret = E_OK ; 
                break ;
            case INTERRUPT_EXTERNAL_INT1 : 
#ifdef _INTERRUPT_PERIORITY_LEVELS_ENABLE 
                INTERRUPT_PeriortyLevelEnable();
                if (INTERRUPT_LOW_PRIORITY == int_obj->priority){
                    INTERRUPT_GlobalInterruptLowEnable();
                }
                else if (INTERRUPT_HIGH_PRIORITY == int_obj->priority){
                    INTERRUPT_GlobalInterruptHighEnable();
                }
                else{/*nothing*/}
#else
                INTERRUPT_GlobalInterruptEnable();
                INTERRUPT_PeripheralInterruptEnable();
#endif
                EXT_INT1_InterruptEnable() ; 
                ret = E_OK ; 
                break ;
            case INTERRUPT_EXTERNAL_INT2 : 
#ifdef _INTERRUPT_PERIORITY_LEVELS_ENABLE 
                INTERRUPT_PeriortyLevelEnable();
                if (INTERRUPT_LOW_PRIORITY == int_obj->priority){
                    INTERRUPT_GlobalInterruptLowEnable();
                }
                else if (INTERRUPT_HIGH_PRIORITY == int_obj->priority){
                    INTERRUPT_GlobalInterruptHighEnable();
                }
                else{/*nothing*/}
#else
                INTERRUPT_GlobalInterruptEnable();
                INTERRUPT_PeripheralInterruptEnable();
#endif
                EXT_INT2_InterruptEnable() ; 
                ret = E_OK ;
                break ;
            default : 
                ret = E_NOK ;
                break ;
        }
    }
    return ret ;
}

/**
 * @naem  Interrupt_INTx_Disable
 * @param int_obj
 * @return Std_ReturnType
 */
static Std_ReturnType Interrupt_INTx_Disable          (const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK ;
    if (int_obj == NULL)
    {
        ret = E_NOK ;
    }
    else
    {
        switch (int_obj->source)
        {
            case INTERRUPT_EXTERNAL_INT0 : 
                EXT_INT1_InterruptDisable() ; 
                ret = E_OK ; 
                break ;
            case INTERRUPT_EXTERNAL_INT1 : 
                EXT_INT1_InterruptDisable() ; 
                ret = E_OK ; 
                break ;
            case INTERRUPT_EXTERNAL_INT2 : 
                EXT_INT2_InterruptDisable() ; 
                ret = E_OK ;
                break ;
            default : 
                ret = E_NOK ;
                break ;
        }
    }
    return ret ;
} 

/**
 * @name  Interrupt_INTx_Periority_Init
 * @param int_obj
 * @return Std_ReturnType
 */
#ifdef _INTERRUPT_PERIORITY_LEVELS_ENABLE 
static Std_ReturnType Interrupt_INTx_Periority_Init   (const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK ;
    if (int_obj == NULL)
    {
        ret = E_NOK ;
    }
    else
    {
        switch (int_obj->source)
        {
            case INTERRUPT_EXTERNAL_INT1 :
                if (INTERRUPT_LOW_PRIORITY == int_obj->priority){EXT_INT1_InterruptLowPerioritySet();}
                else if (INTERRUPT_HIGH_PRIORITY == int_obj->priority){EXT_INT1_InterruptHighPerioritySet();}
                else{/*nothing*/}
                EXT_INT1_InterruptDisable() ; 
                ret = E_OK ; 
                break ;
            case INTERRUPT_EXTERNAL_INT2 : 
                if (INTERRUPT_LOW_PRIORITY == int_obj->priority){EXT_INT2_InterruptLowPerioritySet();}
                else if (INTERRUPT_HIGH_PRIORITY == int_obj->priority){EXT_INT2_InterruptHighPerioritySet();}
                else{/*nothing*/}
                EXT_INT2_InterruptDisable() ; 
                ret = E_OK ;
                break ;
            default : 
                ret = E_NOK ;
                break ;
        }
    }
    return ret ;
}
#endif

/**
 * @name  Interrupt_INTx_Edge_Init
 * @param int_obj
 * @return Std_ReturnType
 */
static Std_ReturnType Interrupt_INTx_Edge_Init        (const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK ;
    if (int_obj == NULL)
    {
        ret = E_NOK ;
    }
    else
    {
        switch (int_obj->source)
        {
            case INTERRUPT_EXTERNAL_INT0 : 
                if (INTERRUPT_FALLING_EDGE == int_obj->edge){EXT_INT0_FallingEdgeSet();}
                else if (INTERRUPT_RISING_EDGE == int_obj->edge ){EXT_INT0_RisingEdgeSet();}
                else {/*Nothing*/}
                EXT_INT1_InterruptDisable() ; 
                ret = E_OK ; 
                break ;
            case INTERRUPT_EXTERNAL_INT1 : 
                if (INTERRUPT_FALLING_EDGE == int_obj->edge){EXT_INT1_FallingEdgeSet();}
                else if (INTERRUPT_RISING_EDGE == int_obj->edge ){EXT_INT1_RisingEdgeSet();}
                else {/*Nothing*/}
                EXT_INT1_InterruptDisable() ; 
                ret = E_OK ; 
                break ;
            case INTERRUPT_EXTERNAL_INT2 : 
                if (INTERRUPT_FALLING_EDGE == int_obj->edge){EXT_INT2_FallingEdgeSet();}
                else if (INTERRUPT_RISING_EDGE == int_obj->edge ){EXT_INT2_RisingEdgeSet();}
                else {/*Nothing*/}
                EXT_INT2_InterruptDisable() ; 
                ret = E_OK ;
                break ;
            default : 
                ret = E_NOK ;
                break ;
        }
    }
    return ret ;
}

/**
 * @name  Interrupt_INTx_Pin_Init
 * @param int_obj
 * @return Std_ReturnType
 */
static Std_ReturnType Interrupt_INTx_Pin_Init         (const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK ;
    if (int_obj == NULL)
    {
        ret = E_NOK ;
    }
    else
    {
        ret = gpio_pin_direction_intialize(&(int_obj->mcu_pin));
    }
    return ret ;
}

/**
 * @name  Interrupt_INTx_Clear_Flag
 * @param int_obj
 * @return Std_ReturnType
 */
static Std_ReturnType Interrupt_INTx_Clear_Flag         (const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK ;
    if (int_obj == NULL)
    {
        ret = E_NOK ;
    }
    else
    {
        switch (int_obj->source)
        {
            case INTERRUPT_EXTERNAL_INT0 : 
                EXT_INT0_InterruptFlagClear();
                ret = E_OK ; 
                break ;
            case INTERRUPT_EXTERNAL_INT1 : 
                EXT_INT1_InterruptFlagClear();
                ret = E_OK ; 
                break ;
            case INTERRUPT_EXTERNAL_INT2 : 
                EXT_INT2_InterruptFlagClear();
                ret = E_OK ;
                break ;
            default : 
                ret = E_NOK ;
                break ;
        }
    }
    return ret ;
}

/**
 * @name  INT0_SetInterruptHandler
 * @param INT1_InterruptHandler
 * @return Std_ReturnType
 */
static Std_ReturnType INT0_SetInterruptHandler       (void (*InterruptHandler)(void))
{
    Std_ReturnType ret = E_OK ;
    if( InterruptHandler == NULL)
    {
        ret = E_NOK ;
    }
    else
    {
        INT0_InterruptHandler = InterruptHandler ;
        ret = E_OK;
    }
    return ret ;
}

/**
 * @name  INT1_SetInterruptHandler
 * @param INT1_InterruptHandler
 * @return Std_ReturnType
 */
static Std_ReturnType INT1_SetInterruptHandler       (void (*InterruptHandler)(void))
{
    Std_ReturnType ret = E_OK ;
    if( InterruptHandler == NULL)
    {
        ret = E_NOK ;
    }
    else
    {
        INT1_InterruptHandler = InterruptHandler ;
        ret = E_OK;
    }
    return ret ;
}

/**
 * @name  INT2_SetInterruptHandler
 * @param INT1_InterruptHandler
 * @return Std_ReturnType
 */
static Std_ReturnType INT2_SetInterruptHandler       (void (*InterruptHandler)(void))
{
    Std_ReturnType ret = E_OK ;
    if( InterruptHandler == NULL)
    {
        ret = E_NOK ;
    }
    else
    {
        INT2_InterruptHandler = InterruptHandler ;
        ret = E_OK;
    }
    return ret ;
}

/**
 * @name  Interrupt_INTx_SetInterruptHandler
 * @param int_obj
 * @return Std_ReturnType
 */
static Std_ReturnType Interrupt_INTx_SetInterruptHandler    (const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK ;
    if(int_obj == NULL)
    {
        ret = E_NOK ;
    }
    else
    {
        switch (int_obj->source)
        {
            case INTERRUPT_EXTERNAL_INT0 : 
                ret = INT0_SetInterruptHandler(int_obj->EXT_InterruptHandler); 
                break ;
            case INTERRUPT_EXTERNAL_INT1 : 
                ret = INT1_SetInterruptHandler(int_obj->EXT_InterruptHandler);  
                break ;
            case INTERRUPT_EXTERNAL_INT2 : 
                ret =  INT2_SetInterruptHandler(int_obj->EXT_InterruptHandler); 
                break ;
            default : 
                ret = E_NOK ;
                break ;
        }
    }
    return ret ;
}

