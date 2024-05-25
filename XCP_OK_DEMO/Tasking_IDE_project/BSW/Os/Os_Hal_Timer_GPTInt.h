/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**
 * \ingroup     Os_Hal
 * \addtogroup  Os_Hal_Timer
 *
 * \{
 *
 * \file       Os_Hal_Timer_GPTInt.h
 * \brief      This file contains hardware specific declaration of GPT module
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/


#ifndef OS_HAL_TIMER_GPTINT_H
# define OS_HAL_TIMER_GPTINT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Timer_GPT_Types.h"

/* Os kernel module dependencies */

/* Os Hal dependencies */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* GPT120 registers, GPT1 group */
/*! Offset of T2, which is used to hold the reload value */
# define OS_HAL_TIMER_GPT_T2_OFFSET                  0x34u
/*! Offset of T3, which is used as counter register */
# define OS_HAL_TIMER_GPT_T3_OFFSET                  0x38u
/*! Offset of T2CON, which is used to configure T2 */
# define OS_HAL_TIMER_GPT_T2CON_OFFSET               0x10u
/*! Value of T2CON, when T2 is in reload mode */
# define OS_HAL_TIMER_GPT_T2CON_USE_AS_RELOAD        0x00000027uL
/*! Offset of T3CON, which is used to configure T3 */
# define OS_HAL_TIMER_GPT_T3CON_OFFSET               0x14u
/*! Bit value for T3CON register if the counting direction is downwards */
# define OS_HAL_TIMER_GPT_T3CON_COUNTING_DOWN        0x00000080uL
/*! Bit value for T3CON register to start the counter */
# define OS_HAL_TIMER_GPT_T3CON_T3R                  0x00000040uL


/* GPT120 registers, GPT2 group */
/*! Offset of T6, which is used as counter register */
# define OS_HAL_TIMER_GPT_T6_OFFSET                  0x44u
/*! Offset of CAPREL, which is used to hold the reload value */
# define OS_HAL_TIMER_GPT_CAPREL_OFFSET              0x30u
/*! Offset of T6CON, which is used to configure T6 */
# define OS_HAL_TIMER_GPT_T6CON_OFFSET               0x20u
/*! Bit value for T6CON register if the counting direction is downwards */
# define OS_HAL_TIMER_GPT_T6CON_COUNTING_DOWN        0x00000080uL
/*! Bit value for T6CON register to start the counter */
# define OS_HAL_TIMER_GPT_T6CON_T6R                  0x00000040uL
/*! Bit value for T6CON register to use CAPREL as the reload value */
# define OS_HAL_TIMER_GPT_T6CON_T6SR                 0x00008000uL




/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! Programmable interval timer configuration information. */
struct Os_Hal_TimerPitConfigType_Tag
{
  /*! This is the address of the counter register */
  uint32 CounterRegisterAddress;

  /*! This is the address of the configuration register for the counter register */
  uint32 CounterConfRegisterAddress;

  /*! This is the value to be written into the configuration register for the counter register */
  uint32 CounterConfRegisterValue;

  /*! This is the address of the register holding the reload value */
  uint32 ReloadRegisterAddress;

  /*! This is the address of the configuration register for the register holding the reload value */
  uint32 ReloadConfRegisterAddress;

  /*! This is the value to be written into the configuration register for the register holding the reload value */
  uint32 ReloadConfRegisterValue;

  /*! This is the reload value */
  uint16 ReloadValue;

  /*! This is the address of the interrupt source register used by this timer */
  uint32 InterruptSRCRegisterAddress;
};

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  Os_Hal_TimerPitInit()
 **********************************************************************************************************************/
/*! \brief          Initialize a programmable interval timer hardware using the given configuration.
 *  \details
 *  The kernel uses this function during OS initialization to initialize hardware timers.
 *  Enable the interrupt source of the hardware timer.
 *
 *  \param[in]      TimerConfig     Timer hardware configuration. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 *  \pre            Concurrent access is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerPitInit,
(
  P2CONST(Os_Hal_TimerPitConfigType, AUTOMATIC, OS_CONST) TimerConfig
));


/***********************************************************************************************************************
 *  Os_Hal_TimerPitAckAndReload()
 **********************************************************************************************************************/
/*! \brief          Acknowledge the timer interrupt and reload the compare value of the PIT.
 *  \details
 *  The kernel uses this function to implement the PIT ISR. It is used to clear the pending timer interrupt flag.
 *  This function should reload the compare value, if the timer hardware doesn't perform this automatically.
 *
 *  \param[in]      TimerConfig     Timer hardware configuration. Parameter must not be NULL.
 *
 *  \context        ISR2|OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerPitAckAndReload,
(
  P2CONST(Os_Hal_TimerPitConfigType, AUTOMATIC, OS_CONST) TimerConfig
));


/***********************************************************************************************************************
 *  Os_Hal_TimerPitIsPending()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given timer hardware has a pending interrupt.
 *  \details
 *  The kernel uses this function to detect job overload.
 *
 *  \param[in]      TimerConfig     Timer hardware configuration. Parameter must not be NULL.
 *
 *  \retval         !0    Interrupt pending.
 *  \retval         0     No interrupt pending.
 *
 *  \context        ISR2|OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 *  \pre            Concurrent access is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE uint32, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerPitIsPending,
(
  P2CONST(Os_Hal_TimerPitConfigType, AUTOMATIC, OS_CONST) TimerConfig
));


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_TIMER_GPTINT_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_GPTInt.h
 *********************************************************************************************************************/
