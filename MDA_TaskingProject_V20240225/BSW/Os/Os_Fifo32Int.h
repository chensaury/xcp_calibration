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
 * \ingroup     Os_Fifo
 * \defgroup    Os_Fifo32 Fifo 32 bit
 * \brief       Queue data structure for 32 bit data types.
 * \details
 * See \ref Os_Fifo.
 *
 * \{
 *
 * \file          Os_Fifo32Int.h
 * \brief         Contains the FIFO interface definition.
 * \details       --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_FIFO32INT_H
# define OS_FIFO32INT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os kernel module dependencies */
# include "Os_CommonInt.h"
# include "Os_FifoInt.h"

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
struct Os_Fifo32WriteConfigType_Tag;
typedef struct Os_Fifo32WriteConfigType_Tag Os_Fifo32WriteConfigType;

struct Os_Fifo32ReadConfigType_Tag;
typedef struct Os_Fifo32ReadConfigType_Tag Os_Fifo32ReadConfigType;


/*! Represents a single element of a FIFO. */
typedef struct
{
  uint32 Value;                                                   /*!< The managed value. */
}Os_Fifo32NodeType;


/*! Defines the runtime data of a FIFO. */
typedef struct
{
  Os_FifoIdxType WriteIdx;                                        /*!< Position of the next write to the queue. */
}Os_Fifo32WriteType;


/*! Defines the runtime data of a FIFO. */
typedef struct
{
  Os_FifoIdxType ReadIdx;                                         /*!< Position of the last read from the queue. */
}Os_Fifo32ReadType;


/*! Defines the configuration data of a Fifo. */
struct Os_Fifo32WriteConfigType_Tag
{
  P2VAR(Os_Fifo32WriteType, AUTOMATIC, OS_VAR_NOINIT) Dyn;       /*!< Pointer to the runtime write data. */
  P2CONST(Os_Fifo32ReadType, AUTOMATIC, OS_VAR_NOINIT) Read;     /*!< Pointer to the runtime read data. */
  P2VAR(Os_Fifo32NodeType, AUTOMATIC, OS_APPL_DATA) Data;         /*!< Pointer to the queue array. */
  Os_FifoIdxType Size;                                            /*!< The queue size. */
};


/*! Defines the configuration data of a Fifo. */
struct Os_Fifo32ReadConfigType_Tag
{
  P2VAR(Os_Fifo32ReadType, AUTOMATIC, OS_VAR_NOINIT) Dyn;        /*!< Pointer to the runtime read data. */
  P2CONST(Os_Fifo32WriteType, AUTOMATIC, OS_VAR_NOINIT) Write;   /*!< Pointer to the runtime write data. */
  P2CONST(Os_Fifo32NodeType, AUTOMATIC, OS_APPL_DATA) Data;       /*!< Pointer to the queue array. */
  Os_FifoIdxType Size;                                            /*!< The queue size. */
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
 *  FIFO Write Functions
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_Fifo32WriteInit()
 **********************************************************************************************************************/
/*! \brief          Initialize the write part of a queue.
 *  \details        This function may also be used in combination with Os_Fifo32ReadInit() to clear queue.
 *                  This function is called in Init-Step2 for global objects and in Init-Step4 for core local objects.
 *
 *  \param[in,out]  Fifo The FIFO instance. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Fifo32WriteInit,
(
  P2CONST(Os_Fifo32WriteConfigType, AUTOMATIC, OS_APPL_DATA) Fifo
));


/***********************************************************************************************************************
 *  Os_Fifo32IndicesInRangeOnWrite()
 **********************************************************************************************************************/
/*! \brief          Checks whether or not indices are in range.
 *  \details        This function checks the read index as well as the write index.
 *
 *  \param[in]      Fifo The FIFO instance. Parameter must not be NULL.
 *
 *  \retval         !0 Read and write index are in range.
 *  \retval         0  Read or write index are out of range.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_Fifo32IndicesInRangeOnWrite,
(
  P2CONST(Os_Fifo32WriteConfigType, AUTOMATIC, OS_APPL_DATA) Fifo
));


/***********************************************************************************************************************
 *  Os_Fifo32Enqueue()
 **********************************************************************************************************************/
/*! \brief          Writes an element at the next write position of the queue.
 *  \details        --no details--
 *
 *  \param[in,out]  Fifo    The FIFO instance. Parameter must not be NULL.
 *  \param[in]      Value   The value to be enqueued.
 *
 *  \retval         OS_FIFOWRITERESULT_OK              If writing succeeded.
 *  \retval         OS_FIFOWRITERESULT_BUFFEROVERFLOW  If the queue is already full.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different FIFOs
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_FifoWriteResultType, OS_CODE,
OS_ALWAYS_INLINE, Os_Fifo32Enqueue,
(
  P2CONST(Os_Fifo32WriteConfigType, AUTOMATIC, OS_APPL_DATA) Fifo,
  uint32 Value
));


/***********************************************************************************************************************
 *  Os_Fifo32IsFull()
 **********************************************************************************************************************/
/*! \brief          Returns whether a queue is full.
 *  \details        --no details--
 *
 *  \param[in]      Fifo  The FIFO to query. Parameter must not be NULL.
 *
 *  \retval         !0    If the queue is full.
 *  \retval         0     If the queue has one used element at least.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CONST, OS_ALWAYS_INLINE,
Os_Fifo32IsFull,
(
  P2CONST(Os_Fifo32WriteConfigType, AUTOMATIC, OS_APPL_DATA) Fifo
));


/***********************************************************************************************************************
 *  FIFO Read Functions
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_Fifo32ReadInit()
 **********************************************************************************************************************/
/*! \brief          Initialize the read part of a queue.
 *  \details        This function may also be used in combination with Os_Fifo32WriteInit() to clear the queue.
 *                  This function is called in Init-Step2 for global objects and in Init-Step4 for core local objects.
 *
 *  \param[in,out]  Fifo    The FIFO instance. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different FIFOs
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Fifo32ReadInit,
(
  P2CONST(Os_Fifo32ReadConfigType, AUTOMATIC, OS_APPL_DATA) Fifo
));


/***********************************************************************************************************************
 *  Os_Fifo32IndicesInRangeOnRead()
 **********************************************************************************************************************/
/*! \brief          Checks whether or not indices are in range
 *  \details        This function checks the read index as well as the write index.
 *
 *  \param[in]      Fifo The FIFO instance. Parameter must not be NULL.
 *
 *  \retval         !0 Read and write index are in range.
 *  \retval         0  Read or write index are out of range.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_Fifo32IndicesInRangeOnRead,
(
  P2CONST(Os_Fifo32ReadConfigType, AUTOMATIC, OS_APPL_DATA) Fifo
));


/***********************************************************************************************************************
 *  Os_Fifo32Dequeue()
 **********************************************************************************************************************/
/*! \brief          Returns the eldest element in the queue and removes it.
 *  \details        --no details--
 *
 *  \param[in,out]  Fifo    The FIFO instance. Parameter must not be NULL.
 *
 *  \return         Returns the value of the eldest element.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different FIFOs
 *  \synchronous    TRUE
 *
 *  \pre            The queue is not empty.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE uint32, OS_CODE, OS_ALWAYS_INLINE, Os_Fifo32Dequeue,
(
  P2CONST(Os_Fifo32ReadConfigType, AUTOMATIC, OS_APPL_DATA) Fifo
));


/***********************************************************************************************************************
 *  Os_Fifo32IsEmpty()
 **********************************************************************************************************************/
/*! \brief          Returns whether a queue is empty.
 *  \details        --no details--
 *
 *  \param[in]      Fifo The FIFO to query. Parameter must not be NULL.
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
Os_Fifo32IsEmpty,
(
  P2CONST(Os_Fifo32ReadConfigType, AUTOMATIC, OS_APPL_DATA) Fifo
));


/***********************************************************************************************************************
 *  Os_Fifo32EmptyQueue()
 **********************************************************************************************************************/
/*! \brief          Empties the queue from the receiver side.
 *  \details        --no details--
 *
 *  \param[in,out]  Fifo    The FIFO instance. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CONST, OS_ALWAYS_INLINE,
Os_Fifo32EmptyQueue,
(
  P2CONST(Os_Fifo32ReadConfigType, AUTOMATIC, OS_APPL_DATA) Fifo
));


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_FIFO32INT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Fifo32Int.h
 **********************************************************************************************************************/
