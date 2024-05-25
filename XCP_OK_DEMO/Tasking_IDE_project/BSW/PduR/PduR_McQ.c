/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  PduR_McQ.c
 *      Project:  Gw_AsrPduRCfg5
 *       Module:  MICROSAR PDU Router
 *    Generator:  Configurator 5
 *
 *  Description:  Vector implementation of AUTOSAR PDU Router
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/
/* *INDENT-OFF* */
/* PRQA  S 4304 EOF */ /* MD_MSR_AutosarBoolean */
/* *INDENT-ON* */

#define PDUR_MCQ_SOURCE
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR.h"
#include "PduR_McQ.h"
#include "PduR_RmIf.h"
#include "SchM_PduR.h"
#if (PDUR_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#if(PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_GetTxConfirmationSize
 *********************************************************************************************************************/
/*! \brief      This function returns the size of the TxConfirmation Handle which will be put in the McQ.
 *  \details    -
 *  \return     the size
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(uint8, PDUR_CODE) PduR_McQ_GetTxConfirmationSize(void);
#endif

#if(PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_GetDataHeaderSize
 *********************************************************************************************************************/
/*! \brief      This function returns the size of the header which is put in front of the Pdu in the McQ.
 *  \details    -
 *  \return     the header size
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(uint8, PDUR_CODE) PduR_McQ_GetDataHeaderSize(void);
#endif

#if(PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_WriteUnusedHeader
 *********************************************************************************************************************/
/*! \brief      This function write an unused value to the write position.
 *  \details    -
 *  \param[in]  writeIdx  Index to the position in the queue where the unused Entry shall be written
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_McQ_WriteUnusedHeader(PduR_McQBufferArrayRamWriteIdxOfMcQBufferRamType writeIdx);
#endif

#if(PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_SerializeData
 *********************************************************************************************************************/
/*! \brief      This function serializes the parameter into the queue starting at the writeIdx position.
 *  \details    -
 *  \param[in]  writeIdx      Index to the position in the queue where the data shall be written
 *  \param[in]  rmDestRomIdx  internal Handle Id of the Pdu to be serialized
 *  \param[in]  data          pointer to the data to be serialized
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_McQ_SerializeData(PduR_McQBufferArrayRamWriteIdxOfMcQBufferRamType writeIdx, PduR_RmDestRomEndIdxOfRmSrcRomType rmDestRomIdx,
                                                          CONSTP2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) data);
#endif

#if(PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_SerializeTxConfirmation
 *********************************************************************************************************************/
/*! \brief      This function serializes the tx Confirmation handle into the queue starting at the writeIdx position.
 *  \details    -
 *  \param[in]  writeIdx      Index to the position in the queue where the data shall be written
 *  \param[in]  rmSrcRomIdx   internal Handle Id of the Pdu to be serialized
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_McQ_SerializeTxConfirmation(PduR_McQBufferArrayRamWriteIdxOfMcQBufferRamType writeIdx, PduR_RmSrcRomIdxOfRmDestRomType rmSrcRomIdx);
#endif

#if(PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_GetWriteIdx
 *********************************************************************************************************************/
/*! \brief      Returns a valid write Idx if the data fits into the buffer
 *  \details    -
 *  \param[in]  mcqBufferRomIdx      Id of the queue to be used
 *  \param[out] writeIdx             The returned writeIdx. Only valid for successful return value.
 *  \param[in]  pduLengthWithHeader  length of the data to be put into the queue
 *  \return     E_OK                Data fits into the buffer.
 *              E_NOT_OK            Data does not fit into the buffer.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_McQ_GetWriteIdx(PduR_McQBufferRomIdxOfSrcCoreRomType mcqBufferRomIdx,
                                                                  P2VAR(PduR_McQBufferArrayRamWriteIdxOfMcQBufferRamType, AUTOMATIC, PDUR_APPL_DATA) writeIdx, PduLengthType pduLengthWithHeader);
#endif

#if(PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_DeserializeData
 *********************************************************************************************************************/
/*! \brief       This function deserializes the data which can be found at the readIdx position.
 *  \details     -
 *  \param[in]   readIdx       Index to the position in the queue where the data shall be read
 *  \param[out]  rmDestRomIdx  Internal Handle Id of the deserialized Pdu
 *  \param[out]  data          Data of the deserialized Pdu
 *  \pre         -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_McQ_DeserializeData(PduR_McQBufferArrayRamWriteIdxOfMcQBufferRamType readIdx, P2VAR(PduR_RmDestRomEndIdxOfRmSrcRomType, AUTOMATIC, PDUR_APPL_DATA) rmDestRomIdx,
                                                            P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) data);
#endif

#if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_UpdateWriteIdx
 *********************************************************************************************************************/
/*! \brief       Update the write pointer after a successful write operation.
 *  \details -
 *  \param[in]   mcQBufferRomIdx              Id of the queue to be used
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_McQ_UpdateWriteIdx(PduR_McQBufferRomIdxOfSrcCoreRomType mcQBufferRomIdx);
#endif

#if(PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_ReadTxConfirmation
 *********************************************************************************************************************/
/*! \brief       This function deserializes the tx confirmation handle which can be found at the readIdx position.
 *  \details     -
 *  \param[in]   mcQBufferRomIdx        Id of the queue to be used
 *  \param[in]   readIdx       Index to the position in the queue where the data shall be read
 *  \return      the RmSrcRomIdx
 *  \pre         -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduR_RmSrcRomIdxOfRmDestRomType, PDUR_CODE) PduR_McQ_ReadTxConfirmation(PduR_McQBufferRomIdxOfSrcCoreRomType mcQBufferRomIdx,
                                                                                          PduR_McQBufferArrayRamWriteIdxOfMcQBufferRamType readIdx);
#endif

#if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_ReadData
 *********************************************************************************************************************/
/*! \brief       Read data from the multicore queue.
 *  \details -
 *  \param[in]   mcQBufferRomIdx          Id of the queue to be used
 *  \param[in]   readIdx                  Index to the position in the queue where the data shall be read
 *  \param[out]  rmDestRomIdx             Index to the destination Pdu to be queued
 *  \param[out]  data                     pointer to the data
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_McQ_ReadData(PduR_McQBufferRomIdxOfSrcCoreRomType mcQBufferRomIdx, PduR_McQBufferArrayRamReadIdxOfMcQBufferRamType readIdx,
                                                     P2VAR(PduR_RmDestRomEndIdxOfRmSrcRomType, AUTOMATIC, PDUR_APPL_DATA) rmDestRomIdx, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) data);
#endif

#if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_GetReadIdx
 *********************************************************************************************************************/
/*! \brief       Get a valid readIdx.
 *  \details -
 *  \param[in]   mcqBufferRomIdx          Id of the queue to be used
 *  \param[out]  readIdx                  the valid readIdx.
 *  \return      E_OK                     Some data is available to be read.
 *               E_NOT_OK                 No data is available to be read.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_McQ_GetReadIdx(PduR_McQBufferRomIdxOfSrcCoreRomType mcqBufferRomIdx,
                                                                 P2VAR(PduR_McQBufferArrayRamReadIdxOfMcQBufferRamType, AUTOMATIC, PDUR_APPL_DATA) readIdx);
#endif

#if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_UpdateReadIdx
 *********************************************************************************************************************/
/*! \brief       Update the read pointer after a successful read operation.
 *  \details -
 *  \param[in]   mcQBufferRomIdx        Id of the queue to be used
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_McQ_UpdateReadIdx(PduR_McQBufferRomIdxOfSrcCoreRomType mcQBufferRomIdx);
#endif

#if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQBufferArrayRamWrite
 *********************************************************************************************************************/
/*! \brief       Write the provided byte into the McQBufferArrayRam
 *  \details -
 *  \param[in]   writeIdx               Index of McQBufferArrayRam
 *  \param[in]   byteToBeWritten        Byte to be written into the McQBufferArrayRam
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_McQBufferArrayRamWrite(PduR_McQBufferArrayRamWriteIdxOfMcQBufferRamType writeIdx, uint8 byteToBeWritten);
#endif

#if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_SetMcQBufferArrayRamPendingReadIdx
 *********************************************************************************************************************/
/*! \brief       Set the provided readIdx
 *  \details -
 *  \param[in]   mcQBufferRomIdx         Id of the queue to be used
 *  \param[in]   readIdx                 Value of the read index
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_SetMcQBufferArrayRamPendingReadIdx(PduR_McQBufferRomIterType mcQBufferRomIdx, PduR_McQBufferArrayRamPendingReadIdxOfMcQBufferRamType readIdx);
#endif

#define PDUR_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_19.1 */
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
#if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_McQ_Init(void)
{
  PduR_McQBufferRomIterType mcqBufferRomIdx;
  for(mcqBufferRomIdx = 0u; mcqBufferRomIdx < PduR_GetSizeOfMcQBufferRom(); mcqBufferRomIdx++)
  {
    PduR_McQBufferArrayRamStartIdxOfMcQBufferRomType startIdxOfBuffer = PduR_GetMcQBufferArrayRamStartIdxOfMcQBufferRom(mcqBufferRomIdx);

    PduR_SetMcQBufferArrayRamPendingWriteIdxOfMcQBufferRam(mcqBufferRomIdx, startIdxOfBuffer);  /* SBSW_PDUR_CSL02 */
    PduR_SetMcQBufferArrayRamPendingReadIdx(mcqBufferRomIdx, startIdxOfBuffer);
    PduR_SetMcQBufferArrayRamReadIdxOfMcQBufferRam(mcqBufferRomIdx, startIdxOfBuffer);  /* SBSW_PDUR_CSL02 */
    PduR_SetMcQBufferArrayRamWriteIdxOfMcQBufferRam(mcqBufferRomIdx, startIdxOfBuffer); /* SBSW_PDUR_CSL02 */
  }
}
#endif

#if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_WriteTxConfirmation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_McQ_WriteTxConfirmation(PduR_McQBufferRomIdxOfSrcCoreRomType mcQBufferRomIdx, PduR_RmSrcRomIdxOfRmDestRomType rmSrcRomIdx)
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_McQBufferArrayRamWriteIdxOfMcQBufferRamType writeIdx;

  SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
  /* #10 If confirmation fits into the multicore queue */
  if(PduR_McQ_GetWriteIdx(mcQBufferRomIdx, &writeIdx, PduR_McQ_GetTxConfirmationSize()) == E_OK)        /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  {
    /* #20 Serialize tx Confirmation handle into the queue starting at the writeIdx position */
    PduR_McQ_SerializeTxConfirmation(writeIdx, rmSrcRomIdx);

    /* #30 Update writeIdx and return E_OK */
    PduR_McQ_UpdateWriteIdx(mcQBufferRomIdx);
    retVal = E_OK;
  }
  /* #40 Otherwise return E_NOT_OK */
  else
  {
    retVal = E_NOT_OK;
  }
  SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
  return retVal;
}
#endif

#if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_WriteData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_McQ_WriteData(PduR_McQBufferRomIdxOfSrcCoreRomType mcQBufferRomIdx, PduR_RmDestRomEndIdxOfRmSrcRomType rmDestRomIdx,
                                                   CONSTP2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) data)
{
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_McQBufferArrayRamWriteIdxOfMcQBufferRamType writeIdx;

  /* ----- Development Error Checks ------------------------------------- */
  /* #10 Check input parameters */
# if (PDUR_DEV_ERROR_DETECT == STD_ON)  /* COV_PDUR_VAR_DEV_ERROR_DETECT */
  if(data == NULL_PTR)
  {
    errorId = PDUR_E_PARAM_POINTER;
  }
  else if(data->SduDataPtr == NULL_PTR)
  {
    errorId = PDUR_E_PARAM_POINTER;
  }
  /* #20 If no error occurred */
  else
# endif
  {
    SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
    /* #30 If data fits into the multicore queue, serialize data, update write index and return E_OK */
    if(PduR_McQ_GetWriteIdx(mcQBufferRomIdx, &writeIdx, data->SduLength + PduR_McQ_GetDataHeaderSize()) == E_OK)        /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
    {
      PduR_McQ_SerializeData(writeIdx, rmDestRomIdx, data);     /* SBSW_PDUR_FCT_CALL_P2CONST */
      PduR_McQ_UpdateWriteIdx(mcQBufferRomIdx);
      retVal = E_OK;
    }
    /* #40 Otherwise return E_NOT_OK */
    else
    {
      retVal = E_NOT_OK;
    }
    SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
  }
/* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  /* #50 Otherwise, report DET error */
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_MCQ_WRITE_DATA, errorId);
  }
# endif
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return retVal;
}
#endif

#if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_GetWriteIdx
 *********************************************************************************************************************/
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
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_McQ_GetWriteIdx(PduR_McQBufferRomIdxOfSrcCoreRomType mcqBufferRomIdx,
                                                                  P2VAR(PduR_McQBufferArrayRamWriteIdxOfMcQBufferRamType, AUTOMATIC, PDUR_APPL_DATA) writeIdx, PduLengthType pduLengthWithHeader)
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */

  PduR_McQBufferArrayRamReadIdxOfMcQBufferRamType readIdx = PduR_GetMcQBufferArrayRamReadIdxOfMcQBufferRam(mcqBufferRomIdx);
  PduR_McQBufferArrayRamWriteIdxOfMcQBufferRamType localWriteIdx = PduR_GetMcQBufferArrayRamWriteIdxOfMcQBufferRam(mcqBufferRomIdx);

  PduR_McQBufferArrayRamStartIdxOfMcQBufferRomType startIdxOfBuffer = PduR_GetMcQBufferArrayRamStartIdxOfMcQBufferRom(mcqBufferRomIdx);
  PduR_McQBufferArrayRamEndIdxOfMcQBufferRomType endIdxOfBuffer = PduR_GetMcQBufferArrayRamEndIdxOfMcQBufferRom(mcqBufferRomIdx) - 1u;  /* ComStackLibs EndIdx is actually the first out of bounds index */

  /* #10 If buffer is full, return E_NOT_OK */
  if(((localWriteIdx + 1u) == readIdx) || ((readIdx == startIdxOfBuffer) && (localWriteIdx == endIdxOfBuffer)))
  {
    /* Buffer is full */
    retVal = E_NOT_OK;
  }
  /* #20 else if write index < read index */
  else if(localWriteIdx < readIdx)      /* write is possible until read Idx is reached. Could be too small though */
  {
    PduR_McQBufferArrayRamWriteIdxOfMcQBufferRamType linearBufferSize = readIdx - localWriteIdx - 1u;
    /* #30 If multicore queue has enough space */
    if(linearBufferSize >= pduLengthWithHeader)
    {
      *writeIdx = localWriteIdx;        /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
      /* #40 Set write index to internal write index and increase pending-write-index to next slot */
      PduR_SetMcQBufferArrayRamPendingWriteIdxOfMcQBufferRam(mcqBufferRomIdx, localWriteIdx + pduLengthWithHeader);     /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
      retVal = E_OK;
    }
    /* #50 Otherwise, return E_NOT_OK */
    else
    {
      retVal = E_NOT_OK;
    }
  }
  /* #60 else */
  else
  {     /* readIdx < localWriteIdx OR readIdx == localWriteIdx */
    PduR_McQBufferArrayRamWriteIdxOfMcQBufferRamType linearBufferSizeAtEnd;
    PduR_McQBufferArrayRamWriteIdxOfMcQBufferRamType linearBufferSizeAtFront;

    linearBufferSizeAtEnd = (localWriteIdx == endIdxOfBuffer) ? 0u : (endIdxOfBuffer - localWriteIdx);
    linearBufferSizeAtFront = (readIdx == startIdxOfBuffer) ? 0u : (readIdx - startIdxOfBuffer - 1u);
    /* #70 If there is enough space at the end of the queue, set write index to internal write index and increase pending-write-index to next slot and return E_OK */
    if(linearBufferSizeAtEnd >= pduLengthWithHeader)
    {
      *writeIdx = localWriteIdx;        /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
      /* Update write Idx */
      PduR_SetMcQBufferArrayRamPendingWriteIdxOfMcQBufferRam(mcqBufferRomIdx, localWriteIdx + pduLengthWithHeader);     /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
      retVal = E_OK;
    }
    /* #80 Otherwise, if there is enough space at the beginning of the queue */
    else if(linearBufferSizeAtFront >= pduLengthWithHeader)
    {
      /* #90 Mark remaining bytes at end as unused */
      PduR_McQ_WriteUnusedHeader(localWriteIdx);

      /* #100 Set write index to start index and increase pending-write-index to next slot */
      *writeIdx = startIdxOfBuffer;     /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */

      /* Update write Idx */
      PduR_SetMcQBufferArrayRamPendingWriteIdxOfMcQBufferRam(mcqBufferRomIdx, (PduR_McQBufferArrayRamPendingWriteIdxOfMcQBufferRamType) startIdxOfBuffer + pduLengthWithHeader);        /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */

      /* #110 Return E_OK */
      retVal = E_OK;
    }
    /* #120 Otherwise, return E_NOT_OK */
    else
    {
      /* neither fits at the end nor the beginning: do nothing */
      retVal = E_NOT_OK;
    }
  }

  return retVal;
}
#endif

#if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_GetDataHeaderSize
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(uint8, PDUR_CODE) PduR_McQ_GetDataHeaderSize(void)
{
  return PDUR_MCQ_SIZE_OF_HEADER + sizeof(PduR_RmDestRomEndIdxOfRmSrcRomType) + sizeof(PduLengthType);
}
#endif

#if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_GetTxConfirmationSize
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(uint8, PDUR_CODE) PduR_McQ_GetTxConfirmationSize(void)
{
  return PDUR_MCQ_SIZE_OF_HEADER + sizeof(PduR_RmSrcRomIdxOfRmDestRomType);
}
#endif

#if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_WriteUnusedHeader
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_McQ_WriteUnusedHeader(PduR_McQBufferArrayRamWriteIdxOfMcQBufferRamType writeIdx)
{
  PduR_McQBufferArrayRamWrite(writeIdx, PDUR_MCQ_UNUSED_HEADER);
}
#endif

#if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_SerializeData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_McQ_SerializeData(PduR_McQBufferArrayRamWriteIdxOfMcQBufferRamType writeIdx, PduR_RmDestRomEndIdxOfRmSrcRomType rmDestRomIdx,
                                                          CONSTP2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) data)
{
  PduR_McQBufferArrayRamWriteIdxOfMcQBufferRamType writeIdxIntern = writeIdx;
  /* #10 Set Header Value */
  PduR_McQBufferArrayRamWrite(writeIdxIntern, PDUR_MCQ_DATA_HEADER);
  writeIdxIntern++;
  /* #20 Serialize rmDestRomIdx */
  {
    uint8 rmDestRomIterator = 0u;
    PduR_RmDestRomEndIdxOfRmSrcRomType tempRmDestRomIdx = rmDestRomIdx;
    uint8 shiftOperand = 0u;
    for(; rmDestRomIterator < sizeof(PduR_RmDestRomEndIdxOfRmSrcRomType); rmDestRomIterator++)
    {
      tempRmDestRomIdx = tempRmDestRomIdx >> shiftOperand;      /* PRQA S 2985 */ /* MD_PduR_2985 */
      PduR_McQBufferArrayRamWrite(writeIdxIntern, (uint8) tempRmDestRomIdx);
      shiftOperand = 8u;        /* PRQA S 2983 */ /* MD_PduR_2983 */
      writeIdxIntern++;
    }
  }
  /* #30 Serialize PduLengthType */
  {
    uint8 pduLengthTypeIterator = 0u;
    PduLengthType tempPduLength = data->SduLength;
    for(; pduLengthTypeIterator < sizeof(PduLengthType); pduLengthTypeIterator++)
    {
      PduR_McQBufferArrayRamWrite(writeIdxIntern, (uint8) tempPduLength);
      tempPduLength = tempPduLength >> 8u;      /* PRQA S 2983 */ /* MD_PduR_2983 */
      writeIdxIntern++;
    }
  }
  /* #40 Serialize Payload */
  if((writeIdxIntern + data->SduLength) < PduR_GetSizeOfMcQBufferArrayRam())    /* COV_PDUR_VAR_FATAL_ERROR */
  {
    VStdMemCpyRamToRam(PduR_GetAddrMcQBufferArrayRam(writeIdxIntern), data->SduDataPtr, data->SduLength);       /* SBSW_PDUR_MCQ_RAMARRAY_RTCHECK_FCTCALL */ /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
  }
  else
  {
    PduR_Det_ReportError(PDUR_MCQ_WRITE_DATA, PDUR_E_FATAL);
  }
}
#endif

#if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_SerializeTxConfirmation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_McQ_SerializeTxConfirmation(PduR_McQBufferArrayRamWriteIdxOfMcQBufferRamType writeIdx, PduR_RmSrcRomIdxOfRmDestRomType rmSrcRomIdx)
{
  PduR_McQBufferArrayRamWriteIdxOfMcQBufferRamType writeIdxIntern = writeIdx;
  /* #10 Set Header Value */
  PduR_McQBufferArrayRamWrite(writeIdxIntern, PDUR_MCQ_TXCONFIRMATION_HEADER);
  writeIdxIntern++;
  /* #20 Serialize rmSrcRomIdx */
  {
    uint8 rmSrcRomIterator = 0u;
    uint8 shiftOperand = 0u;
    PduR_RmSrcRomIdxOfRmDestRomType tempRmSrcRomIdx = rmSrcRomIdx;
    for(; rmSrcRomIterator < sizeof(PduR_RmSrcRomIdxOfRmDestRomType); rmSrcRomIterator++)
    {
      tempRmSrcRomIdx = tempRmSrcRomIdx >> shiftOperand;        /* PRQA S 2985 */ /* MD_PduR_2985 */
      PduR_McQBufferArrayRamWrite(writeIdxIntern, (uint8) tempRmSrcRomIdx);
      shiftOperand = 8u;        /* PRQA S 2983 */ /* MD_PduR_2983 */
      writeIdxIntern++; /* PRQA S 2983 */ /* MD_PduR_2983 */
    }
  }
}
#endif

#if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_DeserializeData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_McQ_DeserializeData(PduR_McQBufferArrayRamWriteIdxOfMcQBufferRamType readIdx, P2VAR(PduR_RmDestRomEndIdxOfRmSrcRomType, AUTOMATIC, PDUR_APPL_DATA) rmDestRomIdx,
                                                            P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) data)
{
  PduR_McQBufferArrayRamWriteIdxOfMcQBufferRamType readIdxIntern = readIdx;
  /* skip Header */
  readIdxIntern += PDUR_MCQ_SIZE_OF_HEADER;
  /* #10 Deserialize rmDestRomIdx */
  {
    uint8 rmDestRomIterator = 0u;
    PduR_RmDestRomEndIdxOfRmSrcRomType tempRmDestRomIdx = 0u;
    uint8 offset = 0u;
    for(; rmDestRomIterator < sizeof(PduR_RmDestRomEndIdxOfRmSrcRomType); rmDestRomIterator++)
    {
      tempRmDestRomIdx = tempRmDestRomIdx | (((PduR_RmDestRomEndIdxOfRmSrcRomType) PduR_GetMcQBufferArrayRam(readIdxIntern)) << offset);        /* PRQA S 2985 */ /* MD_PduR_2985 */
      offset += 8u;     /* PRQA S 2983 */ /* MD_PduR_2983 */
      readIdxIntern++;
    }
    *rmDestRomIdx = tempRmDestRomIdx;   /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
  }
  /* #20 Deserialize PduLengthType */
  {
    uint8 pduLengthTypeIterator = 0u;
    PduLengthType tempPduLength = 0u;
    uint8 offset = 0u;
    for(; pduLengthTypeIterator < sizeof(PduLengthType); pduLengthTypeIterator++)
    {
      tempPduLength = tempPduLength | (((PduLengthType) PduR_GetMcQBufferArrayRam(readIdxIntern)) << offset);
      offset += 8u;
      readIdxIntern++;
    }
    data->SduLength = tempPduLength;    /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
  }
  /* #30 Return pointer point to payload */
  data->SduDataPtr = PduR_GetAddrMcQBufferArrayRam(readIdxIntern);      /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
}
#endif

#if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_ReadTxConfirmation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduR_RmSrcRomIdxOfRmDestRomType, PDUR_CODE) PduR_McQ_ReadTxConfirmation(PduR_McQBufferRomIdxOfSrcCoreRomType mcQBufferRomIdx,
                                                                                          PduR_McQBufferArrayRamWriteIdxOfMcQBufferRamType readIdx)
{
  PduR_McQBufferArrayRamWriteIdxOfMcQBufferRamType readIdxIntern = readIdx;
  /* skip Header */
  readIdxIntern += PDUR_MCQ_SIZE_OF_HEADER;
  /* #10 Deserialize rmSrcRomIdx */
  {
    uint8 rmSrcRomIterator = 0u;
    PduR_RmSrcRomIdxOfRmDestRomType tempRmSrcRomIdx = 0u;
    uint8 offset = 0u;
    for(; rmSrcRomIterator < sizeof(PduR_RmSrcRomIdxOfRmDestRomType); rmSrcRomIterator++)
    {
      tempRmSrcRomIdx = tempRmSrcRomIdx | (((PduR_RmSrcRomIdxOfRmDestRomType) PduR_GetMcQBufferArrayRam(readIdxIntern)) << offset);     /* PRQA S 2985 */ /* MD_PduR_2985 */
      offset += 8u;     /* PRQA S 2983 */ /* MD_PduR_2983 */
      readIdxIntern++;
    }

    /* #20 Set pending-read-idx to next element to be read */
    PduR_SetMcQBufferArrayRamPendingReadIdx(mcQBufferRomIdx, readIdxIntern);
    return tempRmSrcRomIdx;
  }
}
#endif

#if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_ReadData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_McQ_ReadData(PduR_McQBufferRomIdxOfSrcCoreRomType mcQBufferRomIdx, PduR_McQBufferArrayRamReadIdxOfMcQBufferRamType readIdx,
                                                     P2VAR(PduR_RmDestRomEndIdxOfRmSrcRomType, AUTOMATIC, PDUR_APPL_DATA) rmDestRomIdx, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) data)
{
  /* #10 Deserialize Data */
  PduR_McQ_DeserializeData(readIdx, rmDestRomIdx, data);        /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
  /* #20 Set the returned ReadIdx as pending ReadIdx: the readIdx will be set to this value if the read is finished */
  PduR_SetMcQBufferArrayRamPendingReadIdx(mcQBufferRomIdx, readIdx + PduR_McQ_GetDataHeaderSize() + data->SduLength);
}
#endif

#if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_GetReadIdx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_McQ_GetReadIdx(PduR_McQBufferRomIdxOfSrcCoreRomType mcqBufferRomIdx,
                                                                 P2VAR(PduR_McQBufferArrayRamReadIdxOfMcQBufferRamType, AUTOMATIC, PDUR_APPL_DATA) readIdx)
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */

  PduR_McQBufferArrayRamReadIdxOfMcQBufferRamType localReadIdx = PduR_GetMcQBufferArrayRamReadIdxOfMcQBufferRam(mcqBufferRomIdx);
  PduR_McQBufferArrayRamWriteIdxOfMcQBufferRamType writeIdx = PduR_GetMcQBufferArrayRamWriteIdxOfMcQBufferRam(mcqBufferRomIdx);

  /* #10 If multicore Queue is empty, return E_NOT_OK */
  if(localReadIdx == writeIdx)
  {
    retVal = E_NOT_OK;
  }
  /* #20 If the current element is marked with the unused pattern, return the start index of the queue, otherwise return the stored read index */
  else
  {
    if(PduR_GetMcQBufferArrayRam(localReadIdx) == PDUR_MCQ_UNUSED_HEADER)
    {   /* adjust localReadIdx if the end of the buffer is not used */
      localReadIdx = PduR_GetMcQBufferArrayRamStartIdxOfMcQBufferRom(mcqBufferRomIdx);
    }
    *readIdx = localReadIdx;    /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
    retVal = E_OK;
  }

  return retVal;
}
#endif

#if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_UpdateReadIdx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_McQ_UpdateReadIdx(PduR_McQBufferRomIdxOfSrcCoreRomType mcQBufferRomIdx)
{
  PduR_SetMcQBufferArrayRamReadIdxOfMcQBufferRam(mcQBufferRomIdx, PduR_GetMcQBufferArrayRamPendingReadIdxOfMcQBufferRam(mcQBufferRomIdx));      /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
}
#endif

#if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQBufferArrayRamWrite
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_McQBufferArrayRamWrite(PduR_McQBufferArrayRamWriteIdxOfMcQBufferRamType writeIdx, uint8 byteToBeWritten)
{
  if(writeIdx < PduR_GetSizeOfMcQBufferArrayRam())      /* COV_PDUR_VAR_FATAL_ERROR */
  {
    PduR_SetMcQBufferArrayRam(writeIdx, byteToBeWritten);       /* SBSW_PDUR_MCQ_RAMARRAY_RTCHECK */
  }
  else
  {
    PduR_Det_ReportError(PDUR_MCQ_WRITE_DATA, PDUR_E_FATAL);
  }
}
#endif

#if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_UpdateWriteIdx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_McQ_UpdateWriteIdx(PduR_McQBufferRomIdxOfSrcCoreRomType mcQBufferRomIdx)
{
  PduR_SetMcQBufferArrayRamWriteIdxOfMcQBufferRam(mcQBufferRomIdx, PduR_GetMcQBufferArrayRamPendingWriteIdxOfMcQBufferRam(mcQBufferRomIdx));    /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
}
#endif

#if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_SetMcQBufferArrayRamPendingReadIdx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_SetMcQBufferArrayRamPendingReadIdx(PduR_McQBufferRomIterType mcQBufferRomIdx, PduR_McQBufferArrayRamPendingReadIdxOfMcQBufferRamType readIdx)
{
  if(readIdx < PduR_GetMcQBufferArrayRamEndIdxOfMcQBufferRom(mcQBufferRomIdx))  /* COV_PDUR_VAR_FATAL_ERROR */
  {
    PduR_SetMcQBufferArrayRamPendingReadIdxOfMcQBufferRam(mcQBufferRomIdx, readIdx);    /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
  else
  {
    PduR_Det_ReportError(PDUR_MCQ_PENDING_READ_IDX, PDUR_E_FATAL);
  }
}
#endif

#if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_MainFunction
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_McQ_MainFunction(PduR_CoreManagerRomIdxOfMmRomType coreManagerRomIdx)
{
  PduR_SrcCoreRomEndIdxOfCoreManagerRomType srcCoreRomIdx;

  /* #10 For each configured MultiCore Queues */
  for(srcCoreRomIdx = PduR_GetSrcCoreRomStartIdxOfCoreManagerRom(coreManagerRomIdx); srcCoreRomIdx < PduR_GetSrcCoreRomEndIdxOfCoreManagerRom(coreManagerRomIdx); srcCoreRomIdx++)
  {
    if(PduR_IsMcQBufferRomUsedOfSrcCoreRom(srcCoreRomIdx))
    {
      PduR_McQBufferArrayRamReadIdxOfMcQBufferRamType readIdx = 0;
      PduR_McQBufferRomIdxOfSrcCoreRomType mcQBufferRomIdx = PduR_GetMcQBufferRomIdxOfSrcCoreRom(srcCoreRomIdx);

      /* Max. number of bytes to be read before stalling to next main function call */
      PduR_McQBufferArrayRamLengthOfMcQBufferRomType readThreshold = PduR_GetMcQBufferArrayRamLengthOfMcQBufferRom(mcQBufferRomIdx);
      PduLengthType numberOfReadBytes = 0;

      /* #20 While MultiCore Queue has stored elements */
      while(PduR_McQ_GetReadIdx(mcQBufferRomIdx, &readIdx) == E_OK)     /* SBSW_PDUR_STACK_VARIABLE */
      {
        switch (PduR_GetMcQBufferArrayRam(readIdx))
        {
            /* #30 If element is type of data, read Pdu, dispatch If-Pdu to destination and update read Index */
          case PDUR_MCQ_DATA_HEADER:
          {
            PduR_RmDestRomEndIdxOfRmSrcRomType rmDestRomIdx;
            PduInfoType info;

            PduR_McQ_ReadData(mcQBufferRomIdx, readIdx, &rmDestRomIdx, &info);  /* SBSW_PDUR_STACK_VARIABLE */
            (void) PduR_RmIf_DispatchIfDestPdu(rmDestRomIdx, &info);    /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
            PduR_McQ_UpdateReadIdx(mcQBufferRomIdx);

            numberOfReadBytes += ((PduLengthType) PduR_McQ_GetDataHeaderSize()) + info.SduLength;
            break;
          }
            /* #40 If element is type of TxConfirmation, read confirmation from Queue, update read Index and call upper layer confirmation */
          case PDUR_MCQ_TXCONFIRMATION_HEADER:
          {
            PduR_RmSrcRomIdxOfRmDestRomType rmSrcRomIdx = PduR_McQ_ReadTxConfirmation(mcQBufferRomIdx, readIdx);
            PduR_McQ_UpdateReadIdx(mcQBufferRomIdx);
            PduR_GetUpIfTxConfirmationFctPtrOfMmRom(PduR_GetMmRomIdxOfRmSrcRom(rmSrcRomIdx)) (PduR_GetSrcHndOfRmSrcRom(rmSrcRomIdx));   /* SBSW_PDUR_API_CALL_FORWARDING_ID_ONLY */

            numberOfReadBytes += ((PduLengthType) PduR_McQ_GetTxConfirmationSize());
            break;
          }
            /* #50 Report an error otherwise */
          default:     /* COV_PDUR_MISRA */
            PduR_Det_ReportError(PDUR_MCQ_MAINFUNCTION, PDUR_E_FATAL);
            /* Nothing to do: When Det report error is switched off */
            break;
        }

        /* #60 If number of read bytes increases the the queue size, stall processing to next main function call */
        if(numberOfReadBytes > readThreshold)   /* COV_PDUR_MCQ_MAIN_FUNCTION_THRESHOLD */
        {
          break;
        }
      }
    }
  }
}       /* PRQA S 6080, 6050 */ /* MD_MSR_STMIF, MD_MSR_STCAL */
#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  END OF FILE: PduR_McQ.c
 *********************************************************************************************************************/
