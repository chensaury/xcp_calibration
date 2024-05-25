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
 * \addtogroup Os_Interrupt
 * \{
 *
 * \file
 * \brief       Internal data types of the interrupt module.
 * \details     --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_INTERRUPT_TYPES_H
# define OS_INTERRUPT_TYPES_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module dependencies */

/* Os kernel module dependencies */

/* Os Hal dependencies */
# include "Os_Hal_Interrupt_Types.h"



/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
struct Os_IntApiStateType_Tag;

/*! Management information for the interrupt API. */
typedef struct Os_IntApiStateType_Tag Os_IntApiStateType;

/*! Type to abstract from the HAL interrupt state type */
typedef struct
{
  /*! Interrupt state to be used for global lock. */
  Os_Hal_IntGlobalStateType Global;

  /*! Interrupt state to be used for level lock. */
  Os_Hal_IntLevelType Level;
} Os_IntStateType;


/*! Type to abstract from the HAL interrupt global flag state type.
    \details This type is used to disable interrupt handling completely.
             Interrupts to be disabled: Cat0, Cat1, Cat2, Timing Protection ISR.
*/
typedef struct
{
  /*! Interrupt state to be used, to disable interrupt handling */
  Os_Hal_IntGlobalStateType State;
} Os_IntGlobalStateType;

/*! Type to abstract from the HAL interrupt level type */
typedef struct
{
  /*! Hardware encoded level state. */
  Os_Hal_IntLevelType State;
} Os_IntLevelType;


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/




#endif /* OS_INTERRUPT_TYPES_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Interrupt_Types.h
 **********************************************************************************************************************/
