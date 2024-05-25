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
 * \addtogroup     Os_UserInterface
 * \{
 *
 * \file
 * \brief       This file contains all data types which are exposed to the user.
 * \trace       SPEC-63736
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef  OSINT_H
# define OSINT_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Lcfg.h"
# include "Os_Types.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_OsInt.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  DeclareEvent()
 **********************************************************************************************************************/
/*! \brief    OSEK backward compatibility. Needs to be empty!
 *  \details  --no details--
 *  \param[in]  EventID    The event which shall be declared.
 *  \trace      CREQ-133
 *  \trace      SPEC-63736
 **********************************************************************************************************************/
# define DeclareEvent(EventID)

/***********************************************************************************************************************
 *  DeclareAlarm()
 **********************************************************************************************************************/
/*! \brief      OSEK backward compatibility. Needs to be empty!
 *  \details  --no details--
 *  \param[in]  AlarmId    The alarm which shall be declared.
 *  \trace      CREQ-32
 *  \trace      SPEC-63736
 **********************************************************************************************************************/
#define DeclareAlarm(AlarmId)


/***********************************************************************************************************************
 *  ALARMCALLBACK()
 **********************************************************************************************************************/
/*! \def        ALARMCALLBACK()
 *  \brief      Alarm-callback routine declaration macro.
 *  \details    This macro builds the alarm-callback routine declaration for a given alarm-callback name.
 *              Alarm-callbacks are executed with disabled interrupts.
 *
 *  \param[in]  AlarmCbkName  The task name.
 *
 *  \trace      CREQ-142
 *  \trace      SPEC-63736
 **********************************************************************************************************************/
#define ALARMCALLBACK(AlarmCbkName) void Os_Cbk_##AlarmCbkName(void)                                                    /* PRQA S 0342, 3453 */ /* MD_MSR_Rule20.10_0342, MD_MSR_FctLikeMacro */


/***********************************************************************************************************************
 *  DeclareResource()
 **********************************************************************************************************************/
/*! \brief      OSEK backward compatibility. Needs to be empty!
 *  \details  --no details--
 *  \param[in]  ResId    The resource which shall be declared.
 *  \trace      CREQ-163
 *  \trace      SPEC-67376
 **********************************************************************************************************************/
# define DeclareResource(ResId)


/***********************************************************************************************************************
 *  DeclareTask()
 **********************************************************************************************************************/
/*! \brief    OSEK backward compatibility. Needs to be empty!
 *  \details  --no details--
 *  \param[in]  TaskId    The task which shall be declared.
 *  \trace      CREQ-135
 *  \trace      SPEC-63736
 **********************************************************************************************************************/
# define DeclareTask(TaskId)


/***********************************************************************************************************************
 *  TASK()
 **********************************************************************************************************************/
/*! \def        TASK()
 *  \brief      Task function declaration macro.
 *  \details    This macro builds the task function declaration for a given task name.
 *              With the macro TASK() the user may use the same name for "task identification" and "name of task
 *              function". The task identification will be generated from the TaskName during system generation time.
 *
 *  \param[in]  TaskName  The task name.
 *  \trace      SPEC-63736
 **********************************************************************************************************************/
# define TASK(TaskName)       void Os_Task_##TaskName(void)                                                             /* PRQA S 0342 */  /* MD_MSR_Rule20.10_0342 */


/***********************************************************************************************************************
 *  ISR()
 **********************************************************************************************************************/
/*! \def        ISR()
 *  \brief      Category 2 ISR function declaration macro.
 *  \details    This macro builds the category 2 ISR function declaration for a given ISR name.
 *              With the macro ISR() the user may use the same name for "ISR identification" and "name of ISR function".
 *              The ISR identification will be generated from the IsrName during system generation time.
 *
 *  \param[in]  IsrName  The ISR name.
 *  \trace      SPEC-63736
 **********************************************************************************************************************/
# define ISR(IsrName)       void Os_Isr_##IsrName(void)                                                                 /* PRQA S 0342 */  /* MD_MSR_Rule20.10_0342 */


/***********************************************************************************************************************
 *  OS_ISR1()
 **********************************************************************************************************************/
/*! \def        OS_ISR1()
 *  \brief      Category 1 ISR function declaration macro.
 *  \details    This macro builds the category 1 ISR function declaration for a function name.
 *
 *  \param[in]  IsrName  The ISR name.
 **********************************************************************************************************************/
# define OS_ISR1(IsrName)       OS_HAL_ISR1_DEFINE(IsrName)                                                             /* PRQA S 3453 */  /* MD_MSR_FctLikeMacro */


/***********************************************************************************************************************
 *  OS_ISR0()
 **********************************************************************************************************************/
/*! \def        OS_ISR0()
 *  \brief      Category 0 ISR function declaration macro.
 *  \details    This macro builds the category 0 ISR function declaration for a function name.
 *
 *  \param[in]  IsrName  The ISR name.
 **********************************************************************************************************************/
# define OS_ISR0(IsrName)       OS_HAL_ISR0_DEFINE(IsrName)                                                             /* PRQA S 3453 */  /* MD_MSR_FctLikeMacro */


/***********************************************************************************************************************
 *  OSMEMORY_IS_READABLE()
 **********************************************************************************************************************/
/*! \brief        OS service OSMEMORY_IS_READABLE().
 * \details       The system service returns whether or not a memory region is readable. The input to this macro
 *                is considered to the the output of one of the functions CheckTaskMemoryAccess or CheckISRMemoryAccess.
 *
 *  \param[in]    x                   A value of type AccessType as returned from functions CheckTaskMemoryAccess and
 *                                    CheckISRMemoryAccess
 *
 *  \retval       0                   No read access is granted at least for a part of the memory region.
 *  \retval       any_other           Read access is granted for the full memory region.
 *
 *  \context      Any
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        SPEC-2088243
 **********************************************************************************************************************/
# define OSMEMORY_IS_READABLE(x) ( ((uint32)(x)) & ((uint32)(OS_MEM_ACCESS_TYPE_READ)) )                                /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/***********************************************************************************************************************
 *  OSMEMORY_IS_WRITEABLE()
 **********************************************************************************************************************/
/*! \brief        OS service OSMEMORY_IS_WRITEABLE().
 * \details       The system service returns whether or not a memory region is writable. The input to this macro
 *                is considered to the the output of one of the functions CheckTaskMemoryAccess or CheckISRMemoryAccess.
 *
 *  \param[in]    x                   A value of type AccessType as returned from functions CheckTaskMemoryAccess and
 *                                    CheckISRMemoryAccess
 *
 *  \retval       0                   No write access is granted at least for a part of the memory region.
 *  \retval       any_other           Write access is granted for the full memory region.
 *
 *  \context      Any
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        SPEC-2088243
 **********************************************************************************************************************/
# define OSMEMORY_IS_WRITEABLE(x) ( ((uint32)(x)) & ((uint32)(OS_MEM_ACCESS_TYPE_WRITE)) )                              /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/***********************************************************************************************************************
 *  OSMEMORY_IS_EXECUTABLE()
 **********************************************************************************************************************/
/*! \brief        OS service OSMEMORY_IS_EXECUTABLE().
 * \details       The system service returns whether or not code in a memory region is executeable. The input to
 *                this macro is considered to the the output of one of the functions CheckTaskMemoryAccess or
 *                CheckISRMemoryAccess.
 *
 *  \param[in]    x                   A value of type AccessType as returned from functions CheckTaskMemoryAccess and
 *                                    CheckISRMemoryAccess
 *
 *  \retval       0                   No execution right is granted at least for a part of the memory region.
 *  \retval       any_other           Execution right is granted for the complete memory region.
 *
 *  \context      Any
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        SPEC-2088243
 **********************************************************************************************************************/
# define OSMEMORY_IS_EXECUTABLE(x) ( ((uint32)(x)) & ((uint32)(OS_MEM_ACCESS_TYPE_EXECUTE)) )                           /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/***********************************************************************************************************************
 *  OSMEMORY_IS_STACKSPACE()
 **********************************************************************************************************************/
/*! \brief        OS service OSMEMORY_IS_STACKSPACE().
 * \details       The system service returns whether or not a memory region is stack space. The input to
 *                this macro is considered to the the output of one of the functions CheckTaskMemoryAccess or
 *                CheckISRMemoryAccess.
 *
 *  \param[in]    x                   A value of type AccessType as returned from functions CheckTaskMemoryAccess and
 *                                    CheckISRMemoryAccess
 *
 *  \retval       0                   The memory region is not fully located in stack space.
 *  \retval       any_other           The memory region is completely located in stack space.
 *
 *  \context      Any
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        SPEC-2088243
 **********************************************************************************************************************/
# define OSMEMORY_IS_STACKSPACE(x) ( ((uint32)(x)) & ((uint32)(OS_MEM_ACCESS_TYPE_STACK)) )                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  USER CALLOUT PROTOTYPES
 **********************************************************************************************************************/
# if OS_CFG_STARTUPHOOK_SYSTEM == STD_ON
#  define OS_START_SEC_STARTUPHOOK_CODE
#  include "MemMap.h"                                                                                                   /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  StartupHook()
 **********************************************************************************************************************/
/*! \brief        User hook which is called after OS startup and before scheduling.
 *  \details      This hook routine is called by the operating system at the end of the operating system
 *                initialization and before the scheduler is running.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Interrupts locked to Cat2.
 *  \pre          Trusted access rights.
 *
 *  \trace        CREQ-45
 *  \trace        SPEC-67587, SPEC-67588
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(void, OS_STARTUPHOOK_CODE) StartupHook(void);

#  define OS_STOP_SEC_STARTUPHOOK_CODE
#  include "MemMap.h"                                                                                                   /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif


# if OS_CFG_SHUTDOWNHOOK_SYSTEM == STD_ON
#  define OS_START_SEC_SHUTDOWNHOOK_CODE
#  include "MemMap.h"                                                                                                   /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  ShutdownHook()
 **********************************************************************************************************************/
/*! \brief        User hook which is called during system shut down.
 *  \details      This hook routine is called by the operating system when the OS service ShutdownOS has been called.
 *                This routine is called during the operating system shut down, e.g. in case of a fatal error.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Interrupts locked to TP lock level.
 *  \pre          Trusted access rights.
 *
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(void, OS_SHUTDOWNHOOK_CODE) ShutdownHook(StatusType Fatalerror);
#  define OS_STOP_SEC_SHUTDOWNHOOK_CODE
#  include "MemMap.h"                                                                                                   /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif


# if OS_CFG_ERRORHOOK_SYSTEM == STD_ON
#  define OS_START_SEC_ERRORHOOK_CODE
#  include "MemMap.h"                                                                                                   /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  ErrorHook()
 **********************************************************************************************************************/
/*! \brief        User hook for centralized application error handling.
 *  \details      This hook routine is called by the OS, if an application error is detected.
 *
 *  \param[in]    Error    The error which caused the call to the error hook.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Interrupts locked to Cat2.
 *  \pre          Trusted access rights.
 *
 *  \trace        CREQ-26
 *  \trace        SPEC-67579, SPEC-67580, SPEC-67581, SPEC-67582
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(void, OS_ERRORHOOK_CODE) ErrorHook(StatusType Error);

#  define OS_STOP_SEC_ERRORHOOK_CODE
#  include "MemMap.h"                                                                                                   /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* OS_CFG_ERRORHOOK_SYSTEM */


# if OS_CFG_PROTECTIONHOOK_SYSTEM == STD_ON
#  define OS_START_SEC_PROTECTIONHOOK_CODE
#  include "MemMap.h"                                                                                                   /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  ProtectionHook()
 **********************************************************************************************************************/
/*! \brief        User hook for protection error handling.
 *  \details      The protection hook is always called if a serious error occurs. E.g. exceeding the
 *                worst case execution time or violating against the memory protection.
 *
 *  \param[in]    Fatalerror    The error which caused the call to the protection hook.
 *
 *  \retval       PRO_IGNORE
 *  \retval       PRO_TERMINATETASKISR
 *  \retval       PRO_TERMINATEAPPL
 *  \retval       PRO_TERMINATEAPPL_RESTART
 *  \retval       PRO_SHUTDOWN
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Interrupts locked to TP lock level.
 *  \pre          Trusted access rights.
 *
 *  \trace        CREQ-38
 *  \trace        SPEC-63913, SPEC-63777, SPEC-63832, SPEC-63844
 **********************************************************************************************************************/
FUNC(ProtectionReturnType, OS_PROTECTIONHOOK_CODE) ProtectionHook(StatusType Fatalerror);

#  define OS_STOP_SEC_PROTECTIONHOOK_CODE
#  include "MemMap.h"                                                                                                   /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* OS_CFG_PROTECTIONHOOK_SYSTEM */


# if OS_CFG_PRETASKHOOK == STD_ON
#  define OS_START_SEC_PRETASKHOOK_CODE
#  include "MemMap.h"                                                                                                   /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  PreTaskHook()
 **********************************************************************************************************************/
/*! \brief        User hook for tracing/debugging purpose.
 *  \details      Called each time directly after a new task enters the RUNNING state.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Interrupts locked to TP lock level.
 *  \pre          Trusted access rights.
 *
 *  \trace        CREQ-71
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(void, OS_PRETASKHOOK_CODE) PreTaskHook(void);

#  define OS_STOP_SEC_PRETASKHOOK_CODE
#  include "MemMap.h"                                                                                                   /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* OS_CFG_PRETASKHOOK */


# if OS_CFG_POSTTASKHOOK == STD_ON
#  define OS_START_SEC_POSTTASKHOOK_CODE
#  include "MemMap.h"                                                                                                   /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  PostTaskHook()
 **********************************************************************************************************************/
/*! \brief        User hook for tracing/debugging purpose.
 *  \details      Called each time the current task leaves RUNNING state.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Interrupts locked to TP lock level.
 *  \pre          Trusted access rights.
 *
 *  \trace        CREQ-165
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(void, OS_POSTTASKHOOK_CODE) PostTaskHook(void);

#  define OS_STOP_SEC_POSTTASKHOOK_CODE
#  include "MemMap.h"                                                                                                   /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* OS_CFG_POSTTASKHOOK */


# if OS_CFG_PANICHOOK == STD_ON
# define OS_START_SEC_PANICHOOK_CODE
# include "MemMap.h"                                                                                                    /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  Os_PanicHook()
 **********************************************************************************************************************/
/*! \brief        User hook which is called if an inconsistent OS state is detected and regular Shutdown cannot be
 *                reached.
 *  \details      --no details--
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Interrupts locked to TP lock level.
 *  \pre          Trusted access rights.
 **********************************************************************************************************************/
FUNC(void, OS_PANICHOOK_CODE) Os_PanicHook(void);

# define OS_STOP_SEC_PANICHOOK_CODE
# include "MemMap.h"                                                                                                    /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* OS_CFG_PANICHOOK */


#endif /* OSINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: OsInt.h
 **********************************************************************************************************************/
