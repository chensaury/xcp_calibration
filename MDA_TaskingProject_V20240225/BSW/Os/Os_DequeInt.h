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
 * \defgroup    Os_Deque Deque
 * \brief       Double-ended queue data structure.
 * \details
 * Provides a double-ended queue (dequeue or deque). A deque is an abstract data type that generalizes a queue,
 * for which elements can be added to or removed from either the front (head) or back (tail).
 * For our scheduler it is sufficient to add elements at the front and back. All elements will be removed only from
 * the front.
 *
 * ![Data Structure](CmpPrimitivesDequeue.png)
 *
 * \see [Deque](http:\\en.wikipedia.org/wiki/Double-ended_queue)
 * \see [Circular buffer](http:\\en.wikipedia.org/wiki/Circular_buffer)
 *
 * \{
 *
 * \file          Os_DequeInt.h
 * \brief         Contains the deque interface definition.
 * \details       --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_DEQUEINT_H
# define OS_DEQUEINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os kernel module dependencies */
# include "Os_Common_Types.h"
# include "Os_Task_Types.h"

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
/*! Defines the configuration data of a Deque. */
typedef struct
{
  /*! The read index of the deque (points to the buffer element which shall be read next). */
  uint32 ReadIdx;

  /*! The write index of the deque (points to the buffer element which shall be written next). */
  uint32 WriteIdx;
}Os_DequeType;

/*! Represents a single element of a Deque. */
typedef struct
{
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_APPL_DATA) Value; /*!< A pointer to the managed value. */
}Os_DequeNodeType;


/*! Defines the configuration data of a Deque. */
typedef struct
{
  /*! \brief    The dynamic part of a FIFO queue.
   *  \details  Just read and write index, buffer has separate pointer. */
  P2VAR(Os_DequeType, AUTOMATIC, OS_APPL_DATA) Dyn;

  /*! The data buffer of the deque */
  P2VAR(Os_DequeNodeType, AUTOMATIC, OS_APPL_DATA) Buffer;

  /*! The configured size of the data buffer */
  uint32 Size;

}Os_DequeConfigType;

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  Os_DequeIdxDecrement()
 **********************************************************************************************************************/
/*! \brief          Decrements a queue index with respect to the queue size.
 *  \details        --no details--
 *
 *  \param[in,out]  Index The index to be decremented. Parameter must not be NULL.
 *  \param[in]      Size  The size of the queue. The value must be bigger than *Index.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different queues.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            *Index must be in range [0 ... Size-1]
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_DequeIdxDecrement,
(
  P2VAR(uint32, AUTOMATIC, OS_APPL_DATA) Index,
  const uint32 Size
));


/***********************************************************************************************************************
 *  Os_DequeIdxIncrement()
 **********************************************************************************************************************/
/*! \brief          Increments a queue index with respect to the queue size.
 *  \details        --no details--
 *
 *  \param[in,out]  Index The index to be incremented. Parameter must not be NULL.
 *  \param[in]      Size  The size of the queue. The value must be bigger than *Index.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different queues.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            *Index must be in range [0 ... Size-1]
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_DequeIdxIncrement,
(
  P2VAR(uint32, AUTOMATIC, OS_APPL_DATA) Index,
  const uint32 Size
));


/***********************************************************************************************************************
 *  Os_DequeInit()
 **********************************************************************************************************************/
/*! \brief          Initialize the queue. This function may also be used to clear the queue.
 *  \details        This function is called in Init-Step3 and Init-Step4 in order to handle the situation that
 *                  Init-Step3 is optional.
 *
 *  \param[in,out]  Deque The deque instance. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different queues.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_DequeInit,
(
  P2CONST(Os_DequeConfigType, AUTOMATIC, OS_APPL_DATA) Deque
));


/***********************************************************************************************************************
 *  Os_DequeDeleteTop()
 **********************************************************************************************************************/
/*! \brief          Removes the front element from the queue.
 *  \details        --no details--
 *
 *  \param[in,out]  Deque The deque instance. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different queues.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Deque must not be empty.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_DequeDeleteTop,
(
  P2CONST(Os_DequeConfigType, AUTOMATIC, OS_APPL_DATA) Deque
));


/***********************************************************************************************************************
 *  Os_DequeEnqueue()
 **********************************************************************************************************************/
/*! \brief          Writes an element to the back position of the queue.
 *  \details        --no details--
 *
 *  \param[in,out]  Deque The deque instance. Parameter must not be NULL.
 *  \param[in]      Value The value to be added. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different queues.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Deque must not be full.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_DequeEnqueue,
(
  P2CONST(Os_DequeConfigType, AUTOMATIC, OS_APPL_DATA) Deque,
  P2CONST(Os_TaskConfigType, TYPEDEF, AUTOMATIC) Value
));


/***********************************************************************************************************************
 *  Os_DequePrepend()
 **********************************************************************************************************************/
/*! \brief          Writes an element to the front position of the queue.
 *  \details        --no details--
 *
 *  \param[in,out]  Deque The deque instance. Parameter must not be NULL.
 *  \param[in]      Value The value to be added. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different queues.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Deque must not be full.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_DequePrepend,
(
  P2CONST(Os_DequeConfigType, AUTOMATIC, OS_APPL_DATA) Deque,
  P2CONST(Os_TaskConfigType, TYPEDEF, AUTOMATIC) Value
));


/***********************************************************************************************************************
 *  Os_DequePeek()
 **********************************************************************************************************************/
/*! \brief          Returns the front element without removing it.
 *  \details      --no details--
 *
 *  \param[in,out]  Deque The deque instance. Parameter must not be NULL.
 *
 *  \return         Returns the value pointer.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different queues.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Deque must not be empty.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CODE), AUTOMATIC,
OS_ALWAYS_INLINE, Os_DequePeek,
(
  P2CONST(Os_DequeConfigType, AUTOMATIC, OS_APPL_DATA) Deque
));


/***********************************************************************************************************************
 *  Os_DequeDelete()
 **********************************************************************************************************************/
/*! \brief          Deletes all elements with the given Value pointer.
 *  \details        --no details--
 *
 *  \param[in,out]  Deque The deque instance. Parameter must not be NULL.
 *  \param[in]      Value The value to be removed. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different queues.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_DequeDelete,
(
  P2CONST(Os_DequeConfigType, AUTOMATIC, OS_APPL_DATA) Deque,
  P2CONST(Os_TaskConfigType, TYPEDEF, AUTOMATIC) Value
));


/***********************************************************************************************************************
 *  Os_DequeIsEmpty()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given queue is empty.
 *  \details        --no details--
 *
 *  \param[in]      Deque The deque to query. Parameter must not be NULL.
 *
 *  \retval         !0    If the queue is empty.
 *  \retval         0     If the queue contains one element at least.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CONST, OS_ALWAYS_INLINE,
Os_DequeIsEmpty,
(
  P2CONST(Os_DequeConfigType, AUTOMATIC, OS_APPL_DATA) Deque
));


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/



# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_DEQUEINT_H */


/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_DequeInt.h
 **********************************************************************************************************************/
