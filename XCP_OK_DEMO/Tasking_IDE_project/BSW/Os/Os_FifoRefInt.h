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
 * \defgroup    Os_FifoRef Fifo Ref
 * \brief       Queue data structure for void pointer types with Read/Write functions implemented as function pointers.
 * \details     This allows to read/write complex data of arbitrary size.
 * See \ref Os_Fifo.
 *
 * \{
 *
 * \file
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

#ifndef OS_FIFOREFINT_H
# define OS_FIFOREFINT_H
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
struct Os_FifoRefWriteConfigType_Tag;
typedef struct Os_FifoRefWriteConfigType_Tag Os_FifoRefWriteConfigType;

struct Os_FifoRefReadConfigType_Tag;
typedef struct Os_FifoRefReadConfigType_Tag Os_FifoRefReadConfigType;

/*! \brief Callback to read data from the given index of the array.
 *  \details The caller has to ensure that the given index is within a valid range.
 *
 *  \param[in] Buffer   The array to read from.
 *  \param[in] Idx      The array index to read from.
 *  \param[in] Data     The data to write.
 */
typedef P2FUNC(void, OS_CODE, Os_FifoRefReadCbk)
(
  P2CONST(void, AUTOMATIC, TYPEDEF) Buffer,
  Os_FifoIdxType Idx,
  P2VAR(void, AUTOMATIC, TYPEDEF) DataRef
);


/*! \brief   Callback to write data to the given index within the array.
 *  \details The caller has to ensure that the given index is within a valid range.
 *  \param[in] Buffer       The array to write to.
 *  \param[in] Idx          The array index where to write.
 *  \param[in] Data         The data to write.
 */
typedef P2FUNC(void, OS_CODE, Os_FifoRefWriteCbk)
(
  P2VAR(void, AUTOMATIC, TYPEDEF) Buffer,
  Os_FifoIdxType Idx,
  P2CONST(void, AUTOMATIC, TYPEDEF) Data
);


/*! Defines the runtime data of a FIFO. */
typedef struct
{
  Os_FifoIdxType WriteIdx;                                        /*!< Position of the next write to the queue. */
}Os_FifoRefWriteType;


/*! Defines the runtime data of a FIFO. */
typedef struct
{
  Os_FifoIdxType ReadIdx;                                         /*!< Position of the last read from the queue. */
}Os_FifoRefReadType;


/*! Defines the configuration data of a Fifo. */
struct Os_FifoRefWriteConfigType_Tag
{
  P2VAR(Os_FifoRefWriteType, AUTOMATIC, OS_VAR_NOINIT) Dyn;      /*!< Pointer to the runtime write data. */
  P2CONST(Os_FifoRefReadType, AUTOMATIC, OS_VAR_NOINIT) Read;    /*!< Pointer to the runtime read data. */
  P2VAR(void, AUTOMATIC, OS_APPL_DATA) Data;                      /*!< Pointer to the queue array. */
  Os_FifoIdxType Size;                                            /*!< The queue size. */
  Os_FifoRefWriteCbk WriteCbk;                                    /*!< Function which is used to write to the array. */
};


/*! Defines the configuration data of a Fifo. */
struct Os_FifoRefReadConfigType_Tag
{
  P2VAR(Os_FifoRefReadType, AUTOMATIC, OS_VAR_NOINIT) Dyn;       /*!< Pointer to the runtime read data. */
  P2CONST(Os_FifoRefWriteType, AUTOMATIC, OS_VAR_NOINIT) Write;  /*!< Pointer to the runtime write data. */
  P2CONST(void, AUTOMATIC, OS_APPL_DATA) Data;                    /*!< Pointer to the queue array. */
  Os_FifoIdxType Size;                                            /*!< The queue size. */
  Os_FifoRefReadCbk ReadCbk;                                      /*!< Function which is used to read from the array. */
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
 *  Os_FifoRefWriteInit()
 **********************************************************************************************************************/
/*! \brief          Initialize the write part of a queue.
 *  \details        This function may also be used in combination with Os_FifoRefReadInit() to clear queue.
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
Os_FifoRefWriteInit,
(
  P2CONST(Os_FifoRefWriteConfigType, AUTOMATIC, OS_APPL_DATA) Fifo
));


/***********************************************************************************************************************
 *  Os_FifoRefIndicesInRangeOnWrite()
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
Os_FifoRefIndicesInRangeOnWrite,
(
  P2CONST(Os_FifoRefWriteConfigType, AUTOMATIC, OS_APPL_DATA) Fifo
));


/***********************************************************************************************************************
 *  Os_FifoRefEnqueue()
 **********************************************************************************************************************/
/*! \brief          Writes an element at the next write position of the queue.
 *  \details        --no details--
 *
 *  \param[in,out]  Fifo    The FIFO instance. Parameter must not be NULL.
 *  \param[in]      Value   The value to be enqueued. Parameter must not be NULL.
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
OS_ALWAYS_INLINE, Os_FifoRefEnqueue,
(
  P2CONST(Os_FifoRefWriteConfigType, AUTOMATIC, OS_APPL_DATA) Fifo,
  P2CONST(void, TYPEDEF, AUTOMATIC) Value
));


/***********************************************************************************************************************
 *  Os_FifoRefIsFull()
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
Os_FifoRefIsFull,
(
  P2CONST(Os_FifoRefWriteConfigType, AUTOMATIC, OS_APPL_DATA) Fifo
));


/***********************************************************************************************************************
 *  FIFO Read Functions
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_FifoRefReadInit()
 **********************************************************************************************************************/
/*! \brief          Initialize the read part of a queue.
 *  \details        This function may also be used in combination with Os_FifoRefWriteInit() to clear the queue.
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
Os_FifoRefReadInit,
(
  P2CONST(Os_FifoRefReadConfigType, AUTOMATIC, OS_APPL_DATA) Fifo
));


/***********************************************************************************************************************
 *  Os_FifoRefIndicesInRangeOnRead()
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
Os_FifoRefIndicesInRangeOnRead,
(
  P2CONST(Os_FifoRefReadConfigType, AUTOMATIC, OS_APPL_DATA) Fifo
));


/***********************************************************************************************************************
 *  Os_FifoRefDequeue()
 **********************************************************************************************************************/
/*! \brief          Returns the eldest element in the queue and removes it.
 *  \details        --no details--
 *
 *  \param[in,out]  Fifo    The FIFO instance. Parameter must not be NULL.
 *  \param[out]     DataRef Pointer to the location to receive the data. Parameter must not be NULL.
 *
 *  \return         Returns the value of the eldest element.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different FIFOs
 *  \synchronous    TRUE
 *
 *  \pre            The queue is not empty.
 *  \pre            The destination DataRef pointer is a valid and writeable.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_FifoRefDequeue,
(
  P2CONST(Os_FifoRefReadConfigType, AUTOMATIC, OS_APPL_DATA) Fifo,
  P2VAR(void, TYPEDEF, AUTOMATIC) DataRef
));


/***********************************************************************************************************************
 *  Os_FifoRefIsEmpty()
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
Os_FifoRefIsEmpty,
(
  P2CONST(Os_FifoRefReadConfigType, AUTOMATIC, OS_APPL_DATA) Fifo
));


/***********************************************************************************************************************
 *  Os_FifoRefEmptyQueue()
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
Os_FifoRefEmptyQueue,
(
  P2CONST(Os_FifoRefReadConfigType, AUTOMATIC, OS_APPL_DATA) Fifo
));


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_FIFOREFINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_FifoRefInt.h
 **********************************************************************************************************************/
