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
 * \defgroup    Os_PriorityQueue Priority Queue
 * \brief       Create and work with [priority queues](http:\\en.wikipedia.org/wiki/Priority_queue).
 * \details
 * The priority queue is implemented using a [binary heap](http:\\en.wikipedia.org/wiki/Binary_heap) (See also
 * [heap](http:\\en.wikipedia.org/wiki/Heap_%28data_structure%29)).
 * The queue is based on a binary heap. The type of the heap (minimum or maximum) is defined by the compare function
 * provided by the user of the heap.
 *
 * Operations which are provided:
 * - Insert a new node.
 * - Get and delete the node with minimum key.
 * - Remove an arbitrary element in the heap.
 *
 * ####Alternatives####
 * We may use a [red-black tree](http:\\en.wikipedia.org/wiki/Red%E2%80%93black_tree) here.
 * Search operations in a red-black tree are *O(log n)*. In binary heap they are *O(n)*. This is interesting for
 * canceling alarms.
 * The red-black tree is currently not implemented, because:
 *  - our previous implementations based on a binary heap (proven in use)
 *  - red-black tree implementation is a bit more complex
 *  - red-black tree needs slightly more memory (cache misses may be more likely)
 *
 * There are measurements required to make a reasonable statement, which implementation is better.
 *
 * \{
 * \file
 * \brief   Provides the API declaration.
 * \details --no details--
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/


#ifndef OS_PRIORITYQUEUEINT_H
# define OS_PRIORITYQUEUEINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_PriorityQueue_Types.h"

/* Os kernel module dependencies */
# include "Os_Counter_Types.h"

/* Os HAL dependencies */
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

/***********************************************************************************************************************
 *  Os_PriorityQueueInit()
 **********************************************************************************************************************/
/*! \brief          Initialize the given priority queue. This function has to be called for each queue once.
 *                  Any other operation on a queue instance may only be performed after calling Os_PriorityQueueInit.
 *  \details        This function is called for the first time in Init-Step3 for the timing protection counter. It is
 *                  called for all counters in Init-Step4.
 *
 *  \param[in,out]  PriorityQueue The priority queue to be initialized. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_PriorityQueueInit
(
  P2CONST(Os_PriorityQueueConfigType, AUTOMATIC, OS_CONST) PriorityQueue
);


/***********************************************************************************************************************
 *  Os_PriorityQueueInsert()
 **********************************************************************************************************************/
/*! \brief          Inserts a new element.
 *  \details        --no details--
 *
 *  \param[in,out]  PriorityQueue The priority queue. Parameter must not be NULL.
 *  \param[in]      Data          Pointer to the data element which shall be inserted. Parameter must not be NULL.
 *
 *  \retval         OS_PRIORITYQUEUEPOSITION_UNCHANGED  The node has not been moved.
 *  \retval         OS_PRIORITYQUEUEPOSITION_MOVED      The node has been moved.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            The priority of the given Data object does not change until deletion.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_PriorityQueueInsert
(
  P2CONST(Os_PriorityQueueConfigType, AUTOMATIC, OS_CONST) PriorityQueue,
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_APPL_DATA) Data
);


/***********************************************************************************************************************
 *  Os_PriorityQueueTopGet()
 **********************************************************************************************************************/
/*! \brief          Returns the element with the highest priority.
 *  \details        --no details--
 *
 *  \param[in]      PriorityQueue The priority queue. Parameter must not be NULL.
 *
 *  \return         Returns the data pointer to the highest priority element.
 *  \retval         NULL_PTR  If The queue is empty.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE P2CONST(Os_JobConfigType, AUTOMATIC, OS_CODE), OS_CODE, OS_ALWAYS_INLINE,
Os_PriorityQueueTopGet,
(
  P2CONST(Os_PriorityQueueConfigType, AUTOMATIC, OS_CONST) PriorityQueue
));


/***********************************************************************************************************************
 *  Os_PriorityQueueDeleteTop()
 **********************************************************************************************************************/
/*! \brief          Deletes the node with the highest priority.
 *   \details       --no details--
 *
 *  \param[in,out]  PriorityQueue The priority queue. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_PriorityQueueDeleteTop
(
  P2CONST(Os_PriorityQueueConfigType, AUTOMATIC, OS_CONST) PriorityQueue
);


/***********************************************************************************************************************
 *  Os_PriorityQueueDelete()
 **********************************************************************************************************************/
/*! \brief          Searches for a node with a data pointer equal to the data parameter and deletes the node.
 *  \details        If there are multiple nodes with equal pointers, the first node found, will be deleted.
 *                  The deleted node does not have to be the one with the highest priority.
 *
 *  \param[in,out]  PriorityQueue The priority queue. Parameter must not be NULL.
 *  \param[in]      Data          Pointer to the data element which shall be deleted. Parameter must not be NULL.
 *
 *  \retval         OS_PRIORITYQUEUEDELETE_OK          The deletion succeeded.
 *  \retval         OS_PRIORITYQUEUEDELETE_INEXISTENT  The element is not part of the queue.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
FUNC(Os_PriorityQueueDeleteResultType, OS_CODE) Os_PriorityQueueDelete
(
  P2CONST(Os_PriorityQueueConfigType, AUTOMATIC, OS_CONST) PriorityQueue,
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_APPL_DATA) Data
);



# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_PRIORITYQUEUEINT_H */

/* module specific MISRA deviations:
 *
 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_PriorityQueue.h
 **********************************************************************************************************************/
