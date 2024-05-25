/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 * \defgroup  Os_Kernel Kernel
 * \brief     This component implements the platform independent high level logic of the OS.
 * \details   --no details--
 * \{
 *
 * \file
 * \brief     This interface provides high-level kernel functionality to the low-level \ref Os_Hal implementation.
 * \details   --no details--
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/


#ifndef OS_KERNELINT_H
# define OS_KERNELINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Kernel_Types.h"

/* Os module dependencies */
# include "Os_CoreInt.h"
# include "Os_InterruptInt.h"
# include "Os_TaskInt.h"
# include "Os_IsrInt.h"
# include "Os_HookInt.h"
# include "Os_ServiceFunctionInt.h"
# include "Os_EventInt.h"
# include "Os_CounterInt.h"
# include "Os_TimerInt.h"
# include "Os_AlarmInt.h"
# include "Os_ResourceInt.h"
# include "Os_ErrorInt.h"
# include "Os_ScheduleTableInt.h"
# include "Os_ApplicationInt.h"
# include "Os_PeripheralInt.h"
# include "Os_SpinlockInt.h"
# include "Os_AccessCheckInt.h"
# include "Os_IocInt.h"
# include "Os_MemoryProtectionInt.h"
# include "Os_StackInt.h"

/* Os Hal dependencies */
# include "Os_Hal_CompilerInt.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


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




# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_KERNELINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_KernelInt.h
 **********************************************************************************************************************/
