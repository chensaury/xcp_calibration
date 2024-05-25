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
 * \ingroup     Os_Kernel
 * \defgroup    Os_Lock Lock
 * \brief       Lock base type for strictly LIFO used locks.
 * \details
 * \{
 *
 * \file
 * \brief       Interface to lock objects.
 * \details     --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_LOCKINT_H
# define OS_LOCKINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Lock_Types.h"

/* Os module dependencies */
# include "Os_Application_Types.h"
# include "Os_ErrorInt.h"

/* Os Hal dependencies */
#include "Os_Hal_CompilerInt.h"



/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/*! End marker of linked list of locks. */
#define OS_LOCK_LIST_END            ((P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST))(NULL_PTR))

/*! Link value, if the lock is not part of a list/occupied. */
#define OS_LOCK_NOT_LINKED          ((P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST))(~((Os_Hal_AddressType)0)))


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! Type of lock object. */
typedef enum
{
  OS_LOCKTYPE_RESOURCE_STANDARD,    /*!< Standard resources. */
  OS_LOCKTYPE_RESOURCE_INTERRUPT,   /*!< Interrupt resources. */
  OS_LOCKTYPE_SPINLOCK              /*!< Spinlock. */
} Os_LockTypeType;


/*! Dynamic information of a lock. */
struct Os_LockType_Tag
{
  /*! \brief Pointer to next element in the list of occupied locks.
   *  \details  If the lock is free, this pointer has the value OS_LOCK_NOT_LINKED.
   *            If the lock is the last element in the list, this pointer has the value OS_LOCK_LIST_END. */
  P2CONST(Os_LockConfigType, TYPEDEF, OS_CONST) Next;
};


/*! Lock which has to be nested strictly LIFO. */
struct Os_LockConfigType_Tag
{
  /*! Dynamic information. */
  P2VAR(Os_LockType, TYPEDEF, OS_VAR_NOINIT) Dyn;

  /*! Reference to applications which are allowed to access this object. */
  Os_AppAccessMaskType AccessingApplications;

  /*! Type of the synchronization mechanism. */
  Os_LockTypeType Type;
};



/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  Os_LockListInit()
 **********************************************************************************************************************/
/*! \brief          Initialize a list of locks.
 *  \details        Set list pointer to OS_LOCK_LIST_END.
 *                  This function is called in Init-Step3 for some objects. For all lock objects it is called in
 *                  Init-Step4.
 *
 *  \param[in]      LockList  The list of locks to init. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_LockListInit,
(
  P2VAR(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) LockList
));


/***********************************************************************************************************************
 *  Os_LockListPush()
 **********************************************************************************************************************/
/*! \brief          Insert a lock into a linked list of locks.
 *  \details        Used to implement GetSpinlock() and GetResource().
 *
 *  \param[in,out]  LockList  List of locks where the given element shall be inserted. Parameter must not be NULL.
 *  \param[in,out]  Lock      Lock to insert. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            The given Lock must not be contained in any lock list.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_LockListPush,
(
  P2VAR(Os_LockListType, AUTOMATIC, OS_CONST) LockList,
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) Lock
));


/***********************************************************************************************************************
 *  Os_LockListPop()
 **********************************************************************************************************************/
/*! \brief          Removes a lock from a linked list of locks.
 *  \details        Used to implement ReleaseSpinlock() and ReleaseResource().
 *
 *  \param[in,out]  LockList  List of locks where the given element shall be removed from. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            LockList must not be empty.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_LockListPop,
(
  P2VAR(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) LockList
));


/***********************************************************************************************************************
 *  Os_LockListDelete()
 **********************************************************************************************************************/
/*! \brief          Removes a lock from a linked list of locks.
 *  \details        --no details--
 *
 *  \param[in,out]  LockList  List of locks where the given element shall be removed from. Parameter must not be NULL.
 *  \param[in,out]  Lock      Lock which shall be removed. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_LockListDelete,
(
  P2VAR(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) LockList,
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) Lock
));


/***********************************************************************************************************************
 *  Os_LockListNext()
 **********************************************************************************************************************/
/*! \brief          Moves the list top to the next element within the list.
 *  \details        --no details--
 *
 *  \param[in]      Lock  Pointer to lock list entry. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \return         Pointer to the next lock in the list.
 *
 *  \pre            Lock list must not be empty.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_LockListNext,
(
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) Lock
));

/***********************************************************************************************************************
 *  Os_LockListNextIterator()
 **********************************************************************************************************************/
/*! \brief          Computes the next pointer to the lock list and returns it.
 *  \details        --no details--
 *
 *  \param[in]      Iterator  Pointer to the current pointer to the first/next entry in the lock list.
 *                            Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \return         Pointer to the next pointer to the lock list.
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Lock list must not be empty.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE,
OS_ALWAYS_INLINE, Os_LockListNextIterator,
(
  P2CONST(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) Iterator
));


/***********************************************************************************************************************
 *  Os_LockListIsEmpty()
 **********************************************************************************************************************/
/*! \brief          Checks whether the given list of locks is empty (Not OS_CHECK_FAILED) or not (OS_CHECK_FAILED).
 *  \details        --no details--
 *
 *  \param[in]      LockList  List of locks which shall be checked. Parameter must not be NULL.
 *
 *
 *  \retval         !0      The list is empty.
 *  \retval         0       The list is not empty.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_LockListIsEmpty,
(
  P2CONST(Os_LockListType, AUTOMATIC, OS_CONST) LockList
));


/***********************************************************************************************************************
 *  Os_LockListIsTopRes()
 **********************************************************************************************************************/
/*! \brief          Returns whether the the top element of the lock list is a resource lock (!0) or not (0).
 *  \details        --no details--
 *
 *  \param[in]      LockList      The lock list to test. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_LockListIsTopRes,
(
  P2CONST(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) LockList
));


/***********************************************************************************************************************
 *  Os_LockListCheckTopIsRes()
 **********************************************************************************************************************/
/*! \brief          Returns whether the head element in the given list of locks is a resource.
 *  \details        --no details--
 *
 *  \param[in]      LockList    The lock list. Parameter must not be NULL.
 *
 *  \retval         Not OS_CHECK_FAILED    Top element is a resource.
 *  \retval         OS_CHECK_FAILED        Top element is not a resource.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_LockListCheckTopIsRes,
(
  P2CONST(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) LockList
));


/***********************************************************************************************************************
 *  Os_LockListIsTopSpinlock()
 **********************************************************************************************************************/
/*! \brief          Returns whether the head element in the given list of locks is a spinlock.
 *  \details        --no details--
 *
 *  \param[in]      LockList    The lock list. Parameter must not be NULL.
 *
 *  \retval         !0      Top element is a spinlock.
 *  \retval         0       Top element is not a spinlock.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_LockListIsTopSpinlock,
(
  P2CONST(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) LockList
));


/***********************************************************************************************************************
 *  Os_LockListCheckTopIsSpinlock()
 **********************************************************************************************************************/
/*! \brief          Returns whether the head element in the given list of locks is a spinlock.
 *  \details        --no details--
 *
 *  \param[in]      LockList    The lock list. Parameter must not be NULL.
 *
 *  \retval         Not OS_CHECK_FAILED    Top element is a spinlock.
 *  \retval         OS_CHECK_FAILED        Top element is not a spinlock.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_LockListCheckTopIsSpinlock,
(
  P2CONST(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) LockList
));


/***********************************************************************************************************************
 *  Os_LockListGetTop()
 **********************************************************************************************************************/
/*! \brief          Returns the top element of the given lock list.
 *  \details        --no details--
 *
 *  \param[in]      LockList    The lock list. Parameter must not be NULL.
 *
 *  \return         The top element of the list.
 *  \retval         NULL_PTR  If list is empty.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_LockListGetTop,
(
  P2CONST(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) LockList
));


/***********************************************************************************************************************
 *  Os_LockListCheckIsListTop()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given lock is the head element in the given list of locks.
 *  \details        --no details--
 *
 *  \param[in]      LockList  The list of locks where the given lock is in. Parameter must not be NULL.
 *  \param[in]      Lock      The lock to check. Parameter must not be NULL.
 *
 *  \retval         Not OS_CHECK_FAILED   Given lock is the head element in the list of locks.
 *  \retval         OS_CHECK_FAILED       Given lock is not the head element in the list of locks.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_LockListCheckIsListTop,
(
  P2CONST(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) LockList,
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) Lock
));


/***********************************************************************************************************************
 *  Os_LockInit()
 **********************************************************************************************************************/
/*! \brief          Initialize a given lock.
 *  \details        Set the next pointer to OS_LOCK_NOT_LINKED so the lock is available and can be occupied.
 *                  This function is called in Init-Step2 for all spinlock objects and in Init-Step4 for all
 *                  resource objects.
 *
 *  \param[in]      Lock      The lock to init. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_LockInit,
(
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) Lock
));


/***********************************************************************************************************************
 *  Os_LockIsIntResource()
 **********************************************************************************************************************/
/*! \brief          Returns whether a lock is of type interrupt resource.
 *  \details        --no details--
 *
 *  \param[in]      Lock  The resource to query. Parameter must not be NULL.
 *
 *  \retval         !0  Given lock is an interrupt resource.
 *  \retval         0   Given lock is not an interrupt resource.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_LockIsIntResource,
(
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) Lock
));


/***********************************************************************************************************************
 *  Os_LockIsResource()
 **********************************************************************************************************************/
/*! \brief          Returns whether a lock is of type resource.
 *  \details        --no details--
 *
 *  \param[in]      Lock  The resource to query. Parameter must not be NULL.
 *
 *  \retval         !0  Given lock is an resource.
 *  \retval         0   Given lock is not an resource.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_LockIsResource,
(
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) Lock
));


/***********************************************************************************************************************
 *  Os_LockGetAccessingApplications()
 **********************************************************************************************************************/
/*! \brief          Returns list of applications, which are allowed to access the given object.
 *  \details        --no details--
 *
 *  \param[in]      Lock      The lock to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_AppAccessMaskType, OS_CODE,
OS_ALWAYS_INLINE, Os_LockGetAccessingApplications,
(
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) Lock
));


/***********************************************************************************************************************
 *  Os_LockCheckIsAvailable()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given lock is available (Not OS_CHECK_FAILED) or already
 *                  occupied (OS_CHECK_FAILED).
 *  \details        If the lock is part of a linked list, it is already occupied.
 *
 *  \param[in]      Lock      The lock to query. Parameter must not be NULL.
 *
 *  \retval         Not OS_CHECK_FAILED   Given lock is available.
 *  \retval         OS_CHECK_FAILED       Given lock is already occupied.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_LockCheckIsAvailable,
(
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) Lock
));


/***********************************************************************************************************************
 *  Os_LockCheckIsOccupied()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given lock is occupied (Not OS_CHECK_FAILED) or available (OS_CHECK_FAILED).
 *  \details        Returns negated value of Os_LockCheckIsAvailable().
 *
 *  \param[in]      Lock      The lock to query. Parameter must not be NULL.
 *
 *  \retval         Not OS_CHECK_FAILED   Given lock is occupied.
 *  \retval         OS_CHECK_FAILED       Given lock is available.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_LockCheckIsOccupied,
(
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) Lock
));


/***********************************************************************************************************************
 *  Os_LockGetDyn()
 **********************************************************************************************************************/
/*! \brief          Returns dynamic part of lock.
 *  \details        --no details--
 *
 *  \param[in]      Lock      The lock to query. Parameter must not be NULL.
 *
 *  \return         Dynamic part of lock.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_LockType, TYPEDEF, OS_VAR_NOINIT), OS_CODE,
OS_ALWAYS_INLINE, Os_LockGetDyn,
(
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) Lock
));


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_LOCKINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_LockInt.h
 **********************************************************************************************************************/
