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
 * \defgroup    Os_Fifo Fifo
 * \brief       Queue data structure.
 * \details
 * The FIFO is organized as a circular buffer.
 * The FIFO has a write index and a read index. In order to support cross core communication write and read index are
 * organized in different objects. The queue is empty, if write and read index are identical. The
 * queue is treated as full if the incremented write index equals the read index. Therefore the buffer can hold
 * Fifo->Size-1 elements. The maximum Fifo->Size is 255 elements.
 * (depending on the range of Os_FifoIdxType).
 *
 * ![Data Structure](CmpPrimitivesFifo.png)
 *
 * \see [Circular buffer](http:\\en.wikipedia.org/wiki/Circular_buffer)
 *
 * \{
 *
 * \file          Os_FifoInt.h
 * \brief         This file provides common functions for FIFO handling.
 * \details       --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_FIFOINT_H
# define OS_FIFOINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os kernel module dependencies */

/* Os Hal dependencies */
# include "Os_Common_Types.h"
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
/*! Define an Index into or the size of a Fifo queue */
typedef uint8_least Os_FifoIdxType;

/*! Return codes of the functions Os_FifoWriteFrontValue() and Os_FifoWriteBackValue(). */
typedef enum
{
  OS_FIFOWRITERESULT_OK,                   /*!< Writing to the queue succeeded. */
  OS_FIFOWRITERESULT_BUFFEROVERFLOW        /*!< Writing to the queue failed, because it is full. */
}Os_FifoWriteResultType;


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  Os_FifoIdxIncrement()
 **********************************************************************************************************************/
/*! \brief          Increments a queue index with respect to the queue size.
 *  \details        --no details--
 *
 *  \param[in,out]  Index The index to be incremented. Parameter must not be NULL.
 *  \param[in]      Size  The size of the queue. The value must be greater than *Index.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different FIFOs
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_FifoIdxIncrement,
(
  P2VAR(Os_FifoIdxType, AUTOMATIC, TYPEDEF) Index,
  Os_FifoIdxType Size
));


/***********************************************************************************************************************
 *  Os_FifoIsFull()
 **********************************************************************************************************************/
/*! \brief          Returns whether a queue is full.
 *  \details        --no details--
 *
 *  \param[in]      WriteIdx  The write index of a FIFO. The index must be smaller than Size.
 *  \param[in]      ReadIdx   The read index of a FIFO. The index must be smaller than Size.
 *  \param[in]      Size      The size of the queue.
 *
 *  \retval         !0    If the queue is full.
 *  \retval         0     If the queue has one unused element at least.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CONST, OS_ALWAYS_INLINE,
Os_FifoIsFull,
(
  Os_FifoIdxType WriteIdx,
  Os_FifoIdxType ReadIdx,
  Os_FifoIdxType Size
));


/***********************************************************************************************************************
 *  Os_FifoIsEmpty()
 **********************************************************************************************************************/
/*! \brief          Returns whether a queue is empty.
 *  \details        --no details--
 *
 *  \param[in]      WriteIdx  The write index of a FIFO.
 *  \param[in]      ReadIdx   The read index of a FIFO.
 *
 *  \retval         !0    If the queue is empty.
 *  \retval         0     If the queue contains one element at least.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CONST, OS_ALWAYS_INLINE,
Os_FifoIsEmpty,
(
  Os_FifoIdxType WriteIdx,
  Os_FifoIdxType ReadIdx
));


/***********************************************************************************************************************
 *  Os_FifoEmptyQueue()
 **********************************************************************************************************************/
/*! \brief          Empties the queue from the receiver side.
 *  \details        --no details--
 *
 *  \param[in]      WriteIdx  The write index of a FIFO. Parameter must not be NULL.
 *  \param[in,out]  ReadIdx   The read index of a FIFO. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CONST, OS_ALWAYS_INLINE,
Os_FifoEmptyQueue,
(
  P2CONST(Os_FifoIdxType, AUTOMATIC, TYPEDEF) WriteIdx,
  P2VAR(Os_FifoIdxType, AUTOMATIC, TYPEDEF) ReadIdx
));


/***********************************************************************************************************************
 *  Os_FifoIndicesInRange()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given indexes are in range.
 *  \details        --no details--
 *
 *  \param[in]      WriteIdx  The write index of a FIFO.
 *  \param[in]      ReadIdx   The read index of a FIFO.
 *  \param[in]      Size      The size of the FIFO
 *
 *  \retval         !0        Read and write index are in range.
 *  \retval         0         Read or write index are out of range.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CONST, OS_ALWAYS_INLINE,
Os_FifoIndicesInRange,
(
  Os_FifoIdxType WriteIdx,
  Os_FifoIdxType ReadIdx,
  Os_FifoIdxType Size
));


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_FIFOINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_FifoInt.h
 **********************************************************************************************************************/
