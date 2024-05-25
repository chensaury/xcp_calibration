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
 *  \ingroup     Os_Kernel
 *  \defgroup    Os_Event  Event
 *  \brief       Event management
 *  \details
 *
 *  \trace CREQ-106
 *
 *  \{
 *
 *  \file
 *  \brief       Internal event management interface.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_EVENTINT_H
# define OS_EVENTINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os module dependencies */
# include "Os_CommonInt.h"
# include "Os_Task_Types.h"
# include "Os_Error_Types.h"

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
/*! Event management state for one task.
 * \details Two masks are required (Waiting and Set), because events can be set, before the task is waiting for it. */
typedef struct
{
   /*! Event mask to save events the task is waiting for. */
   volatile EventMaskType Waiting;

   /*! Event mask to save events which have been set. */
   volatile EventMaskType Triggered;
} Os_EventStateType;

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  Os_EventInit()
 **********************************************************************************************************************/
/*! \brief          Initialize a given event management state.
 *  \details        Called for the first time in Init-Step3 and later on whenever a task is started.
 *
 *  \param[in,out]  Events  Event management state to initialize. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_EventInit,
(
  P2VAR(Os_EventStateType, AUTOMATIC, OS_VAR_NOINIT) Events
));


/***********************************************************************************************************************
 *  Os_EventSetLocal()
 **********************************************************************************************************************/
/*! \brief          Local function to set events on the local core.
 *  \details        --no details--
 *
 *  \param[in,out]  Task        The task which shall be modified. Parameter must not be NULL.
 *  \param[in]      Mask        The events which shall be set.
 *
 *  \retval         OS_STATUS_OK        No errors.
 *  \retval         OS_STATUS_STATE_1   (EXTENDED status:) Events can not be set as the referenced task is in the
 *                                      SUSPENDED state.
 *  \retval         OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given object's owner application is not accessible.
 *
 *  \context        TASK|ISR2
 *
 *  \reentrant      TRUE for different tasks.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            The given task is assigned to the local core.
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_EventSetLocal
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task,
  EventMaskType Mask
);


/***********************************************************************************************************************
 *  Os_EventSetInternal()
 **********************************************************************************************************************/
/*! \brief          Internal function to set events.
 *  \details
 *  This function performs no error reporting. This is up to the caller.  Because, this function could be called as part
 *  of a cross core call, where error reporting shall be performed on the calling core.  This function performs no task
 *  switch. This is up to the caller.  Because this function may be called on interrupt and on task level.  This
 *  function may call the protection hook with E_OS_PROTECTION_ARRIVAL, if the task's interarrival time is not met.
 *
 *  \param[in,out]  Task        The task which shall be modified. Parameter must not be NULL.
 *  \param[in]      Mask        The events which shall be set.
 *
 *  \return         See \ref Os_EventSetLocal() and \ref Os_XSigSend_SetEventAsync().
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different tasks.
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_EventSetInternal
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task,
  EventMaskType Mask
);


/***********************************************************************************************************************
 *  Os_EventGetLocal()
 **********************************************************************************************************************/
/*! \brief          Writes the event mask, containing all events the given task is currently waiting for.
 *  \details        --no details--
 *
 *  \param[in,out]  Task    The task object which contains the event object of interest. Parameter must not be NULL.
 *  \param[out]     Mask    Pointer where the result shall be stored.  Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK              No errors.
 *  \retval         OS_STATUS_STATE_1         (EXTENDED status:) Task is suspended.
 *  \retval         OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Task's owner application is not accessible.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_EventGetLocal
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task,
  EventMaskRefType Mask
);


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_Api_SetEvent()
 **********************************************************************************************************************/
/*! \brief        OS service SetEvent().
 *  \details      For further details see SetEvent().
 *
 *  \param[in]    TaskID          See SetEvent().
 *  \param[in]    Mask            See SetEvent().
 *
 *  \retval       OS_STATUS_OK                No error.
 *  \retval       OS_STATUS_ID_1              (EXTENDED status:) Invalid TaskID.
 *  \retval       OS_STATUS_NOEXTENDEDTASK_1  (EXTENDED status:) Task is no extended task.
 *  \retval       OS_STATUS_STATE_1           (EXTENDED status:) Events can not be set as the referenced task is in the
 *                                            SUSPENDED state.
 *  \retval       OS_STATUS_NOTACCESSIBLE_1   (Service Protection:) Given object's owner application is not accessible.
 *  \retval       OS_STATUS_ACCESSRIGHTS_1    (Service Protection:) Caller's access rights are not sufficient.
 *  \retval       OS_STATUS_CALLEVEL          (Service Protection:) Called from invalid context.
 *  \retval       OS_STATUS_DISABLEDINT       (Service Protection:) Caller is in interrupt API sequence.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See SetEvent().
 *
 *  \trace        CREQ-155, CREQ-40
 *  \trace        SPEC-64284, SPEC-64287, SPEC-64290, SPEC-64291, SPEC-64292, SPEC-64017, SPEC-64053, SPEC-66492
 *  \trace        SPEC-63709, SPEC-63752, SPEC-63980
 *  \trace        SPEC-63854 If asynchronous XSignal is enabled this requirement is not fulfilled.
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_SetEvent
(
  TaskType TaskID,
  EventMaskType Mask
);


/***********************************************************************************************************************
 *  Os_Api_ClearEvent()
 **********************************************************************************************************************/
/*! \brief        OS service ClearEvent().
 *  \details      For further details see ClearEvent().
 *
 *  \param[in]    Mask                See ClearEvent().
 *
 *  \retval       OS_STATUS_OK                No error.
 *  \retval       OS_STATUS_NOEXTENDEDTASK_CALLER   (EXTENDED status:) Task is no extended task.
 *  \retval       OS_STATUS_CALLEVEL          (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_DISABLEDINT       (Service Protection:) Caller is in interrupt API sequence.
 *
 *  \context      TASK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See ClearEvent().
 *
 *  \trace        CREQ-53, CREQ-40
 *  \trace        SPEC-64285, SPEC-64286, SPEC-64288, SPEC-64289, SPEC-64017, SPEC-63980
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_ClearEvent
(
  EventMaskType Mask
);


/***********************************************************************************************************************
 *  Os_Api_GetEvent()
 **********************************************************************************************************************/
/*! \brief        OS service GetEvent().
 *  \details      For further details see GetEvent().
 *
 *  \param[in]    TaskID          See GetEvent().
 *  \param[out]   Mask            See GetEvent().
 *
 *  \retval       OS_STATUS_OK                No error.
 *  \retval       OS_STATUS_ID_1              (EXTENDED status:) Invalid TaskID.
 *  \retval       OS_STATUS_NOEXTENDEDTASK_1  (EXTENDED status:) Task is no extended task.
 *  \retval       OS_STATUS_STATE_1           (EXTENDED status:) Referenced task is in SUSPENDED state.
 *  \retval       OS_STATUS_CALLEVEL          (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_DISABLEDINT       (Service Protection:) Caller is in interrupt API sequence.
 *  \retval       OS_STATUS_NOTACCESSIBLE_1   (Service Protection:) Given object's owner application is not accessible.
 *  \retval       OS_STATUS_ACCESSRIGHTS_1    (Service Protection:) Caller's access rights are not sufficient.
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See GetEvent().
 *
 *  \trace        CREQ-129, CREQ-40
 *  \trace        SPEC-64306, SPEC-64316, SPEC-64322, SPEC-64344, SPEC-64354, SPEC-64017, SPEC-63709, SPEC-63752
 *  \trace        SPEC-63980
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_GetEvent
(
  TaskType TaskID,
  EventMaskRefType Mask
);


/***********************************************************************************************************************
 *  Os_Api_WaitEvent()
 **********************************************************************************************************************/
/*! \brief        OS service WaitEvent().
 *  \details      For further details see WaitEvent().
 *
 *  \param[in]    Mask  See WaitEvent().
 *
 *  \retval       OS_STATUS_OK              No error.
 *  \retval       OS_STATUS_NOEXTENDEDTASK_CALLER   (EXTENDED status:) Task is no extended task.
 *  \retval       OS_STATUS_RESOURCE        (EXTENDED status:) Task still occupies resources.
 *  \retval       OS_STATUS_SPINLOCK        (EXTENDED status:) Task still holds spinlocks.
 *  \retval       OS_STATUS_CALLEVEL        (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_DISABLEDINT     (Service Protection:) Caller is in interrupt API sequence.
 *
 *  \context      TASK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See WaitEvent().
 *
 *  \trace        CREQ-68, CREQ-40
 *  \trace        SPEC-64295, SPEC-64297, SPEC-64308, SPEC-64321, SPEC-64323, SPEC-64365, SPEC-64017, SPEC-63702
 *  \trace        SPEC-63980
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_WaitEvent
(
  EventMaskType Mask
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_EVENTINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_EventInt.h
 **********************************************************************************************************************/
