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
 * \addtogroup Os_Stack
 * \{
 *
 * \file
 * \brief       External interface to \ref Os_Stack.
 * \details     --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_STACK_H
# define OS_STACK_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Stack_Cfg.h"
# include "Os_StackInt.h"

/* Os kernel module dependencies */
# include "Os_Task.h"
# include "Os_Isr.h"
# include "Os_Core.h"
# include "Os_Error.h"

/* Os Hal dependencies */
# include "Os_Hal_Core.h"
# include "Os_Hal_Context.h"



/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_StackIsModuleEnabled()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_StackIsModuleEnabled, ( void ))
{
  return (Os_StdReturnType)(OS_CFG_STACKMODULE  == STD_ON);                                                             /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_StackIsMeasurementEnabled()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_StackIsMeasurementEnabled, ( void ))
{
  return (Os_StdReturnType)(OS_CFG_STACKMEASUREMENT  == STD_ON);                                                        /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_StackIsMonitoringEnabled()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_StackIsMonitoringEnabled, ( void ))
{
  return (Os_StdReturnType)(OS_CFG_STACKMONITORING  == STD_ON);                                                         /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_StackInit()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_StackInit,
(
  P2CONST(Os_StackConfigType, AUTOMATIC, OS_CONST) Stack
))
{

  if(Os_StackIsModuleEnabled() != 0u)
  {
    FUNC(void, OS_CODE) Os_StackInitInternal
    (P2CONST(Os_StackConfigType, AUTOMATIC, OS_CONST) Stack);

    Os_StackInitInternal(Stack);                                                                                        /* SBSW_OS_FC_PRECONDITION */
  }
}


/***********************************************************************************************************************
 *  Os_StackOverflowCheck()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_StackOverflowCheck,( void ))
{
  /* #10 Report protection error if the stack's last element is not equal to the fill pattern. */
  if(Os_StackIsMonitoringEnabled() != 0u)
  {
    P2CONST(Os_StackConfigType, AUTOMATIC, OS_CONST) stack;
    P2VAR(Os_Hal_StackType, AUTOMATIC, OS_VAR_NOINIT) stackEnd;

    stack = Os_CoreGetCurrentStack();
    stackEnd = Os_Hal_StackEndGet(stack->LowAddress, stack->HighAddress);                                               /* SBSW_OS_ST_HAL_STACKENDGET_003 */

    if(OS_UNLIKELY(*(stackEnd) != OS_HAL_STACK_FILL_PATTERN))
    {
      /*! Internal comment removed.
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
 *
 *
 *
 *
 *
 *
       */
      *stackEnd = OS_HAL_STACK_FILL_PATTERN;                                                                            /* SBSW_OS_ST_HAL_STACKENDGET_002 */

      Os_ErrProtectionError(OS_STATUS_STACKFAULT);
    }
  }
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_STACK_H_ */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Stack.h
 **********************************************************************************************************************/
