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
 * \addtogroup Os_PriorityQueue
 * \{
 *
 * \file        Os_PriorityQueue.c
 * \brief       General implementation of the PriorityQueue implemented as binary heap.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777, 0779, 0828  EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */


#define OS_PRIORITYQUEUE_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_PriorityQueue.h"

/* Os kernel module dependencies */
#include "Os_Cfg.h"
#include "Os_Common_Types.h"
#include "Os_Job.h"
#include "Os_Error.h"


/***********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! Sibling identifier */
typedef enum
{
  OS_PRIORITYQUEUESIBLING_LEFT  = 1,    /*!< Left sibling selector */
  OS_PRIORITYQUEUESIBLING_RIGHT = 2     /*!< Right sibling selector */
}Os_PriorityQueueSiblingType;

/***********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/
/*! Heap traversing result  */
typedef enum
{
  OS_PRIORITYQUEUEPOSITION_UNCHANGED,   /*!< Node position is unchanged. */
  OS_PRIORITYQUEUEPOSITION_MOVED        /*!< Node position changed. */
}Os_PriorityQueuePositionType;


/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define OS_START_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */



/***********************************************************************************************************************
 *  Os_PriorityQueueSiblingIndex()
 **********************************************************************************************************************/
/*! \brief          Returns the index of a child selected by parameter nodeIdx.
 *  \details        --no details--
 *
 *  \param[in]      NodeIdx     The index of the leaf.
 *  \param[in]      Sibling     The identifier of a sibling.
 *
 *  \return         The sibling's node index.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            (2 * NodeIdx) + Sibling must not exceed (2^15)-1.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_PriorityQueueNodeIdxType, OS_CODE, OS_ALWAYS_INLINE,
Os_PriorityQueueSiblingIndex,
(
  Os_PriorityQueueNodeIdxType NodeIdx,
  Os_PriorityQueueSiblingType Sibling
));


/***********************************************************************************************************************
 *  Os_PriorityQueueParentIndex()
 **********************************************************************************************************************/
/*! \brief          Returns the index of the parent. If the root node is given as argument, the behavior is undefined.
 *  \details        --no details--
 *
 *  \param[in]      NodeIdx     The index of the leaf. NodeIdx must not be OS_PRIORITYQUEUE_ROOT_IDX and
 *                              (NodeIdx - 1) / 2 must be in range 0 .. (2^15)-1.
 *
 *  \return         The parant's node index.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_PriorityQueueNodeIdxType, OS_CODE, OS_ALWAYS_INLINE,
Os_PriorityQueueParentIndex,
(
  Os_PriorityQueueNodeIdxType NodeIdx
));


/***********************************************************************************************************************
 *  Os_PriorityQueueHeapUp()
 **********************************************************************************************************************/
/*! \brief            Moves up the node specified by nodeIdx until it is at the correct place.
 *  \details          Os_PriorityQueueHeapUp restores the heap's shape property for a single node, if the node's
 *                    Parent has a lower priority.
 *
 *  \param[in,out]    PriorityQueue The priority queue. Parameter must not be NULL.
 *  \param[in]        NodeIdx       The index of the node which may have to be moved up.
 *                                  (NodeIdx - 1) / 2 must be in range 0 .. (2^15)-1.
 *
 *  \retval           OS_PRIORITYQUEUEPOSITION_UNCHANGED  If the node has not been moved.
 *  \retval           OS_PRIORITYQUEUEPOSITION_MOVED      If the node has been moved.
 *
 *  \context          ANY
 *
 *  \reentrant        TRUE
 *  \synchronous      TRUE
 *
 *  \pre              Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_PriorityQueuePositionType, OS_CODE, OS_ALWAYS_INLINE,
Os_PriorityQueueHeapUp,
(
  P2CONST(Os_PriorityQueueConfigType, AUTOMATIC, OS_CONST) PriorityQueue,
  Os_PriorityQueueNodeIdxType NodeIdx
));


/***********************************************************************************************************************
 *  Os_PriorityQueueHeapDown()
 **********************************************************************************************************************/
/*! \brief           Moves down the node specified by NodeIdx until it is at the correct place.
 *  \details         Os_PriorityQueueHeapDown restores the heap's shape property for a single node, if one of the node's
 *                   siblings has a higher priority.
 *
 *  \param[in,out]   PriorityQueue The priority queue. Parameter must not be NULL.
 *  \param[in]       NodeIdx       The index of the node which may have to be moved down.
 *
 *  \retval          OS_PRIORITYQUEUEPOSITION_UNCHANGED   If the node has not been moved.
 *  \retval          OS_PRIORITYQUEUEPOSITION_MOVED       If the node has been moved.
 *
 *  \context         OS_INTERNAL
 *
 *  \reentrant       TRUE
 *  \synchronous     TRUE
 *
 *  \pre             (2 * NodeIdx) + OS_PRIORITYQUEUESIBLING_LEFT and (2 * NodeIdx) + OS_PRIORITYQUEUESIBLING_RIGHT
 *                   must not exceed (2^15)-1.
 *  \pre             The first unused priority queue node contains a stopper element which is a copy of the element at
 *                   NodeIdx. Therefore, we can ignore the special case that a left sibling exists but no right one.
 *  \pre             Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_PriorityQueuePositionType, OS_CODE, OS_ALWAYS_INLINE,
Os_PriorityQueueHeapDown,
(
  P2CONST(Os_PriorityQueueConfigType, AUTOMATIC, OS_CONST) PriorityQueue,
  Os_PriorityQueueNodeIdxType NodeIdx
));


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  Os_PriorityQueueSiblingIndex()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_PriorityQueueNodeIdxType, OS_CODE, OS_ALWAYS_INLINE,
Os_PriorityQueueSiblingIndex,
(
  Os_PriorityQueueNodeIdxType NodeIdx,
  Os_PriorityQueueSiblingType Sibling
))
{
  /* #10   Calculate the sibling index and return the calculated value */
  return (Os_PriorityQueueNodeIdxType)((2u * NodeIdx) + (uint16_least)Sibling);
}


/***********************************************************************************************************************
 *  Os_PriorityQueueParentIndex()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_PriorityQueueNodeIdxType, OS_CODE, OS_ALWAYS_INLINE,
Os_PriorityQueueParentIndex,
(
    Os_PriorityQueueNodeIdxType NodeIdx
))
{
  /* #10 Check that given index is not the root. */
  Os_Assert((Os_StdReturnType)(NodeIdx != OS_PRIORITYQUEUE_ROOT_IDX));                                                  /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

  /* #20 Return the parent's node index. */
  return ((NodeIdx - (uint16_least)1) / (uint16_least)2);
}


/***********************************************************************************************************************
 *  Os_PriorityQueueHeapUp()
 **********************************************************************************************************************/
/*!
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_PriorityQueuePositionType, OS_CODE, OS_ALWAYS_INLINE,
Os_PriorityQueueHeapUp,
(
  P2CONST(Os_PriorityQueueConfigType, AUTOMATIC, OS_CONST) PriorityQueue,
  Os_PriorityQueueNodeIdxType NodeIdx
))
{
  /* #10 Set result to OS_PRIORITYQUEUEPOSITION_UNCHANGED. */
  Os_PriorityQueuePositionType result = OS_PRIORITYQUEUEPOSITION_UNCHANGED;
  Os_PriorityQueueNodeIdxType parent;
  Os_PriorityQueueNodeIdxType current = NodeIdx;

  /* #20 Loop while NodeIdx is not equal to OS_PRIORITYQUEUE_ROOT_IDX. */
  while(current > OS_PRIORITYQUEUE_ROOT_IDX)
  {
    /* #30 Calculate the parentIdx. */
    parent = Os_PriorityQueueParentIndex(current);

    /* #40 If the node[NodeIdx] has a higher priority than its parent: */
    if(Os_JobPriorityCompare(PriorityQueue->Queue[current].Data, PriorityQueue->Queue[parent].Data) != 0u)              /* SBSW_OS_PQ_JOBPRIORITYCOMPARE_001 */
    {
      P2CONST(Os_JobConfigType, AUTOMATIC, OS_APPL_DATA) tmpNode;

      /* #50 Swap the node and its parent. */
      tmpNode = PriorityQueue->Queue[parent].Data;
      PriorityQueue->Queue[parent].Data = PriorityQueue->Queue[current].Data;                                           /* SBSW_OS_PQ_DATA_INDEX_001 */
      PriorityQueue->Queue[current].Data = tmpNode;                                                                     /* SBSW_OS_PQ_DATA_INDEX_001 */

      /* #60 Update nodeIdx to the parentIdx. */
      current = parent;

      /* #70 Set result to OS_PRIORITYQUEUEPOSITION_MOVED */
      result = OS_PRIORITYQUEUEPOSITION_MOVED;
    }
    /* #80 Otherwise */
    else
    {
      /* #90 Shape property fulfilled -> abort */
      break;
    }
  }
  /* #100 Return the result. */
  return result;
}


/***********************************************************************************************************************
 *  Os_PriorityQueueHeapDown()
 **********************************************************************************************************************/
/*!
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
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_PriorityQueuePositionType, OS_CODE, OS_ALWAYS_INLINE,
Os_PriorityQueueHeapDown,
(
  P2CONST(Os_PriorityQueueConfigType, AUTOMATIC, OS_CONST) PriorityQueue,
  Os_PriorityQueueNodeIdxType NodeIdx
))
{
  /* #10   Set result to OS_PRIORITYQUEUEPOSITION_UNCHANGED */
  Os_PriorityQueuePositionType result = OS_PRIORITYQUEUEPOSITION_UNCHANGED;
  Os_PriorityQueueNodeIdxType left;
  Os_PriorityQueueNodeIdxType right;
  Os_PriorityQueueNodeIdxType highPrioSibling;
  Os_PriorityQueueNodeIdxType current = NodeIdx;

  /* #20   Calculate the index of the left sibling (leftIdx). */
  left = Os_PriorityQueueSiblingIndex(current, OS_PRIORITYQUEUESIBLING_LEFT);

  /* #30   Loop while there is a left sibling. */
  while(left < PriorityQueue->Dyn->QueueUsage)
  {
    /* #40   Calculate the index of the right sibling (rightIdx). */
    right = Os_PriorityQueueSiblingIndex(current, OS_PRIORITYQUEUESIBLING_RIGHT);

    /* Note: The right sibling may be no element of the priority queue. However, because of the precondition it
     *       can be used anyhow. */
    /* #50   Select the sibling with the highest priority */
    if(Os_JobPriorityCompare(PriorityQueue->Queue[left].Data, PriorityQueue->Queue[right].Data) != 0u)                  /* SBSW_OS_PQ_JOBPRIORITYCOMPARE_001 */
    {
      highPrioSibling = left;
    }
    else
    {
      highPrioSibling = right;
    }

    /* #60   If the selected sibling has a higher priority then the parent: */
    if(Os_JobPriorityCompare(                                                                                           /* SBSW_OS_PQ_JOBPRIORITYCOMPARE_001 */
          PriorityQueue->Queue[highPrioSibling].Data,
          PriorityQueue->Queue[current].Data
        ) != 0u)
    {
      P2CONST(Os_JobConfigType, AUTOMATIC, OS_APPL_DATA) tmpNode;

      /* #70   Swap the node and the sibling with the higher priority. */
      tmpNode = PriorityQueue->Queue[highPrioSibling].Data;
      PriorityQueue->Queue[highPrioSibling].Data = PriorityQueue->Queue[current].Data;                                  /* SBSW_OS_PQ_DATA_INDEX_001 */
      PriorityQueue->Queue[current].Data = tmpNode;                                                                     /* SBSW_OS_PQ_DATA_INDEX_001 */

      /* #80   Update nodeIdx to the new position. */
      current = highPrioSibling;

      /* #90   Set result to OS_PRIORITYQUEUEPOSITION_MOVED. */
      result = OS_PRIORITYQUEUEPOSITION_MOVED;
    }
    /* #100   otherwise: */
    else
    {
      /* #110  Shape property fulfilled -> abort */
      break;
    }
    /* #120  Calculate the index of the left sibling (leftIdx). */
    left = Os_PriorityQueueSiblingIndex(current, OS_PRIORITYQUEUESIBLING_LEFT);
  }
  /* #130  Return the result. */
  return result;
}



/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  Os_PriorityQueueInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, OS_CODE) Os_PriorityQueueInit
(
  P2CONST(Os_PriorityQueueConfigType, AUTOMATIC, OS_CONST) PriorityQueue
)
{
  /*  #10   Initialize the queue usage counter with '0'. */
  PriorityQueue->Dyn->QueueUsage = 0;                                                                                   /* SBSW_OS_PQ_PRIORITYQUEUEGETDYN_001 */
}


/***********************************************************************************************************************
 *  Os_PriorityQueueInsert()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_PriorityQueueInsert
(
  P2CONST(Os_PriorityQueueConfigType, AUTOMATIC, OS_CONST) PriorityQueue,
  P2CONST(Os_JobConfigType, TYPEDEF, AUTOMATIC) Data
)
{
  /* #10  Assert that the queue has still capacity */
  Os_Assert((Os_StdReturnType)(PriorityQueue->Dyn->QueueUsage < PriorityQueue->QueueSize));                             /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

  /* #20  Append the element after the last used node. */
  PriorityQueue->Queue[PriorityQueue->Dyn->QueueUsage].Data = Data;                                                     /* SBSW_OS_PQ_DATA_INDEX_001 */

  /* #30  Increment the queueUsage counter. */
  PriorityQueue->Dyn->QueueUsage++;                                                                                     /* SBSW_OS_PQ_PRIORITYQUEUEGETDYN_001 */

  /* #40  Reorder the binary tree by calling Os_PriorityQueueHeapUp. */
  (void)Os_PriorityQueueHeapUp(PriorityQueue, (PriorityQueue->Dyn->QueueUsage - 1u));                                   /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_PriorityQueueDeleteTop()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_PriorityQueueDeleteTop
(
  P2CONST(Os_PriorityQueueConfigType, AUTOMATIC, OS_CONST) PriorityQueue
)
{
  /* #10   Assert that the queue is not empty. */
  Os_Assert((Os_StdReturnType)(PriorityQueue->Dyn->QueueUsage > 0u));                                                   /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

  /* #20   Decrement the number of nodes by one. */
  PriorityQueue->Dyn->QueueUsage--;                                                                                     /* SBSW_OS_PQ_PRIORITYQUEUEGETDYN_001 */

  /* #30   Copy the data pointer of the last node into the deleted node. */
  PriorityQueue->Queue[OS_PRIORITYQUEUE_ROOT_IDX].Data = PriorityQueue->Queue[PriorityQueue->Dyn->QueueUsage].Data;     /* SBSW_OS_PQ_DATA_INDEX_001 */

  /* Note: The line above covers the precondition of Os_PriorityQueueHeapDown below */
  /* #40   Restore the shape property by calling Os_PriorityQueueHeapDown(deletedIdx). */
  (void)Os_PriorityQueueHeapDown(PriorityQueue, OS_PRIORITYQUEUE_ROOT_IDX);                                             /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_PriorityQueueDelete()
 **********************************************************************************************************************/
/*!
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
 *
 *
 */
FUNC(Os_PriorityQueueDeleteResultType, OS_CODE) Os_PriorityQueueDelete
(
  P2CONST(Os_PriorityQueueConfigType, AUTOMATIC, OS_CONST) PriorityQueue,
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_APPL_DATA) Data
)
{
  Os_PriorityQueueDeleteResultType result;
  Os_PriorityQueueNodeIdxType idx;
  Os_PriorityQueuePositionType heapDownRetVal;

  /* #10 Search for the index (deleteIdx) of node which points to data. */
  for(idx = OS_PRIORITYQUEUE_ROOT_IDX; idx < PriorityQueue->Dyn->QueueUsage; idx++)                                     /* COV_OS_INVSTATE */
  {
    if (OS_UNLIKELY(PriorityQueue->Queue[idx].Data == Data))
    {
      break;
    }
  }

  /* #20 If this node does not exist: */
  if (OS_UNLIKELY(idx == PriorityQueue->Dyn->QueueUsage))                                                               /* COV_OS_INVSTATE */
  {
    /* #30 Set result to OS_PRIORITYQUEUEDELETE_INEXISTENT. */
    result = OS_PRIORITYQUEUEDELETE_INEXISTENT;
  }
  /* #40 Otherwise: */
  else
  {
    /* #50 Decrement the number of nodes by one. */
    PriorityQueue->Dyn->QueueUsage--;                                                                                   /* SBSW_OS_PQ_PRIORITYQUEUEGETDYN_001 */

    /* #60 If the deleted node is not the last node: */
    if (OS_LIKELY(idx < PriorityQueue->Dyn->QueueUsage))
    {
      /* #70 Copy the data pointer of the last node into the deleted node. */
      PriorityQueue->Queue[idx] = PriorityQueue->Queue[PriorityQueue->Dyn->QueueUsage];                                 /* SBSW_OS_PQ_DATA_INDEX_001 */

      /* Note: The line above covers the precondition of Os_PriorityQueueHeapDown below */
      /* #80 Restore the shape property by calling Os_PriorityQueueHeapDown(deletedIdx). */
      heapDownRetVal = Os_PriorityQueueHeapDown(PriorityQueue, idx);                                                    /* SBSW_OS_FC_PRECONDITION */

      /* #90 If Os_PriorityQueueHeapDown returns OS_PRIORITYQUEUEPOSITION_UNCHANGED: */
      if(heapDownRetVal == OS_PRIORITYQUEUEPOSITION_UNCHANGED)
      {
        /* #100 Restore the shape property by calling Os_PriorityQueueHeapUp(deletedIdx). */
        (void)Os_PriorityQueueHeapUp(PriorityQueue, idx);                                                               /* SBSW_OS_FC_PRECONDITION */
      }
    }
    /* #110 Set result to OS_PRIORITYQUEUEDELETE_OK. */
    result = OS_PRIORITYQUEUEDELETE_OK;
  }
  /* #120 Return the result. */
  return result;
}


#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* module specific MISRA deviations:
 *
 */

/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_OS_PQ_JOBPRIORITYCOMPARE_001
 \DESCRIPTION    Os_JobPriorityCompare is called with values derived from a Queue. The Queue is part of a
                 PriorityQueue which is passed as argument. Precondition ensures that the PriorityQueue pointer is
                 valid. The compliance of the precondition is check during review.
 \COUNTERMEASURE \T [CM_OS_PRIORITYQUEUE_QUEUE_DATA_T]
                 \M [CM_OS_PRIORITYQUEUE_QUEUE_DATA_M]

\ID SBSW_OS_PQ_DATA_INDEX_001
 \DESCRIPTION    Write access to a Data element. The Data element is derived with an index from a Queue object.
                 The Queue is derived from a PriorityQueue which is passed as argument. Precondition ensures that the
                 PriorityQueue pointer is valid. The compliance of the precondition is check during review.
 \COUNTERMEASURE \T [CM_OS_PRIORITYQUEUE_QUEUE_DATA_T]
                 \M [CM_OS_PRIORITYQUEUE_QUEUE_DATA_M]

\ID SBSW_OS_PQ_PRIORITYQUEUEGETDYN_001
 \DESCRIPTION    Write access to a Dyn element. The Dyn element is derived from a PriorityQueue which is passed as
                 argument. Precondition ensures that the PriorityQueue pointer is valid. The compliance of the
                 precondition is check during review.
 \COUNTERMEASURE \T [CM_OS_PRIORITYQUEUE_QUEUE_DATA_T]
                 \M [CM_OS_PRIORITYQUEUE_DYN_M]

SBSW_JUSTIFICATION_END */


/*
\CM CM_OS_PRIORITYQUEUE_QUEUE_DATA_T
      TCASE-345828 ensures consistent management of Data handled by the priority queue class and that the used indieces
      are in a valid range.

\CM CM_OS_PRIORITYQUEUE_QUEUE_DATA_M
      Verify that:
        1. Verify that the Queue pointer of each priority queue is no NULL_PTR and
        2. the size of the Queue is equal QueueSize + 1.
        3. Verify that the queue size is sufficient to handle all client data (in case of counters, the queue size
           has to be at least equal to the number of jobs + 1, handled by the counter).

\CM CM_OS_PRIORITYQUEUE_DYN_M
      Verify that the Dyn pointer of each PriorityQueue object is valid.

\CM CM_OS_PRIORITYQUEUETOPGET_R
      Implementation ensures that the returned pointer is not used for write access if it is a NULL_PTR.
 */


/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_PriorityQueue.c
 **********************************************************************************************************************/
