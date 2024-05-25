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
 *         File:  PduR_Bm.h
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
#if !defined (PDUR_BM_H)
# define PDUR_BM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/* \trace SPEC-2020230, SPEC-38402 */

# include "PduR_Types.h"
# include "PduR_Cfg.h"
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
#  include "Det.h"
# endif
# include "PduR_Lcfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define PDUR_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

# if(PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
  PduR_Bm_Init
**********************************************************************************************************************/
/*! \brief       This function initializes the BufferManager.
 *  \details     -
 *  \pre         PduR_InitMemory() has been executed, if the start up code does not initialize variables.
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 ********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Bm_Init(void);
# endif

# if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_PutData
 *********************************************************************************************************************/
/*! \brief      Call to put data into the buffer.
 *  \details -
 *  \param[in]  txBufferElementIdx       read index in the transport protocol Tx buffer
 *  \param[in] pduLength                 length to copy.
 *  \param[in] sduDataPtr                data pointer.
 *  \pre         PduR_Init() is executed successfully.
 *  \return      BUFREQ_OK                Copy action was successful.
 *               BUFREQ_E_NOT_OK          Copy action was not successful.
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_PutData(PduR_BmTxBufferRomIterType txBufferElementIdx, PduR_BmTxBufferArrayRamIterType pduLength, CONST(SduDataPtrType, AUTOMATIC) sduDataPtr);
# endif

# if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_PutDataAsPtr
 *********************************************************************************************************************/
/*! \brief       Call to put data into the buffer.
 *  \details     -
 *  \param[in]   txBufferElementIdx       read index in the transport protocol Tx buffer
 *  \param[in]   info                     data pointer.
 *  \pre         PduR_Init() is executed successfully.
 *  \return      BUFREQ_OK                Copy action was successful.
 *               BUFREQ_E_NOT_OK          Copy action was not successful.
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_PutDataAsPtr(PduR_BmTxBufferRomIterType txBufferElementIdx, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);     /* COV_PDUR_IF_ONLY */
# endif

# if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetData
 *********************************************************************************************************************/
/*!  \brief      Call to get queued data from the buffer.
 *   \details -
 *   \param[in]  bmTxBufferInstanceRomIdx instance Idx
 *   \param[in]  pduLength                 length to copy.
 *   \param[out] sduDataPtr                data pointer.
 *   \pre         PduR_Init() is executed successfully.
 *   \return     BUFREQ_OK              Copy action was successful.
 *               BUFREQ_E_NOT_OK        Copy action was not successful.
 *   \context    TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_GetData(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamIterType pduLength, CONST(SduDataPtrType, AUTOMATIC) sduDataPtr);
# endif

# if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
* PduR_Bm_CopyData
*********************************************************************************************************************/
/*! \brief      Read Data from the TxBuffer. Last is Best semantic.
 *  \details    -
 *  \param[in]  bmTxBufferInstanceRomIdx  TxBuffer instance element index
 *  \param[in]  pduLength                 length to copy.
 *  \param[out] sduDataPtr                data pointer.
 *  \pre         PduR_Init() is executed successfully.
 *  \context    TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \note       This function only reads data without move.
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Bm_CopyData(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamIterType pduLength, CONST(SduDataPtrType, AUTOMATIC) sduDataPtr);
# endif

# if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_ResetTxBuffer
 *********************************************************************************************************************/
/*! \brief      Reset Buffer element: Read, WriteIndex, data and buffer size information, Buffer state.
 *  \details -
 *  \param[in]  txBufferElementStateIdx  read index in the transport protocol Tx buffer.
 *  \pre         PduR_Init() is executed successfully.
 *  \context    TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Bm_ResetTxBuffer(PduR_BmTxBufferRomIterType txBufferElementStateIdx);
# endif

# if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_ResetTxBufferInstance
 *********************************************************************************************************************/
/*! \brief       Reset Instance Buffer element: Read, WriteIdx, data and buffer size information, Buffer state.
 *  \details     -
 *  \param[in]   bmTxBufferInstanceRomIdx  instance Idx.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Bm_ResetTxBufferInstance(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx);
# endif

# if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_AssignAssociatedBuffer2DestinationInstance
 *********************************************************************************************************************/
/*! \brief       Assign the associated buffer to the destinations instance.
 *  \details     -
 *  \param[in]   bmTxBufferRomIdx          Index of the Tx buffer.
 *  \param[in]   bmTxBufferInstanceRomIdx  Instance Index of the Tx buffer.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Bm_AssignAssociatedBuffer2DestinationInstance(PduR_BmTxBufferRomIterType bmTxBufferRomIdx, PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx);
# endif

# if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetLinearDataSize
 *********************************************************************************************************************/
/*! \brief       Get the data size which is available without doing a wrap around.
 *  \details     -
 *  \param[in]   bmTxBufferRomIdx  index to the BmTxBuffer element
 *  \return      the calculated linear data size
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(PduR_BmTxBufferArrayRamIterType, PDUR_CODE) PduR_Bm_GetLinearDataSize(PduR_BmTxBufferRomIterType bmTxBufferRomIdx);
# endif

# if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetLinearDataSizeInstance
 *********************************************************************************************************************/
/*! \brief       Get the data size which is available without doing a wrap around.
 *  \details     -
 *  \param[in]   bmTxBufferInstanceRomIdx  index to the BmTxBuffer element
 *  \return      the calculated linear data size
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(PduR_BmTxBufferArrayRamIterType, PDUR_CODE) PduR_Bm_GetLinearDataSizeInstance(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx);
# endif

# if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetTotalDataSizeInstance
 *********************************************************************************************************************/
/*! \brief       Get the total data size which is available
 *  \details     -
 *  \param[in]   bmTxBufferInstanceRomIdx  index to the BmTxBuffer element
 *  \return      the calculated total data size
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(PduR_BmTxBufferArrayRamIterType, PDUR_CODE) PduR_Bm_GetTotalDataSizeInstance(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx);
# endif

# if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetTotalBufferSize
 *********************************************************************************************************************/
/*! \brief       Get the total free buffer size which is available
 *  \details     -
 *  \param[in]   bmTxBufferRomIdx  index to the BmTxBuffer element
 *  \return      the calculated total free buffer size
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(PduR_BmTxBufferArrayRamIterType, PDUR_CODE) PduR_Bm_GetTotalBufferSize(PduR_BmTxBufferRomIterType bmTxBufferRomIdx);
# endif

# if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_AllocateTxBuffer
 *********************************************************************************************************************/
/*! \brief       Search a suitable buffer from the buffer pool.
 *  \details     -
 *  \param[in]   bmTxBufferRomIndStartId   TxBuffer Indirection StartIdx
 *  \param[in]   bmTxBufferRomIndEndIdx    TxBuffer Indirection EndIdx
 *  \param[in]   fmFifoElementRamWriteIdx  Current write FIFO Idx
 *  \param[in]   pduLength                 SDU length which must be routed
 *  \param[out]  bufferSizePtr             Available buffer
 *  \param[out]  allocatedTxBufferIdxPtr   Id of tha allocated TxBuffer
 *  \param[in]   considerSmallerBuffer     true, if smaller buffer than the pduLength shall be used as alternative.
 *                                         This shall only be true in Tp routing context.
 *  \return      BUFREQ_OK                 Buffer request was successful.
 *               BUFREQ_E_NOT_OK           Currently no buffer is available or a buffer request occurs for a 1:N routing
 *                                         and no buffer is available to store the complete frame to the buffer.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_AllocateTxBuffer(PduR_BmTxBufferIndRomIterType bmTxBufferRomIndStartId,
                                                            PduR_BmTxBufferIndRomIterType bmTxBufferRomIndEndIdx,
                                                            PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx,
                                                            PduR_BmTxBufferArrayRamLengthOfBmTxBufferRomType pduLength,
                                                            P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr,
                                                            P2VAR(PduR_BmTxBufferRomIdxOfBmTxBufferIndRomType, AUTOMATIC, PDUR_APPL_DATA) allocatedTxBufferIdxPtr, boolean considerSmallerBuffer);
# endif

# if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_CopyDataAsPtr
 *********************************************************************************************************************/
/*! \brief       Get the Buffer Data as a Pointer to the data.
 *  \details     -
 *  \param[in]   bmTxBufferInstanceRomIdx  TxBuffer ID
 *  \param[out]  info                      PduInfo Pointer to the Data.
 *  \param[in]   length                    Length of the requested Data.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Bm_CopyDataAsPtr(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, PduR_BmTxBufferArrayRamIterType length);
# endif

# if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetDataAsPtr
 *********************************************************************************************************************/
/*! \brief       Get the Buffer Data as a Pointer to the data.
 *  \details     -
 *  \param[in]   bmTxBufferInstanceRomIdx  TxBuffer ID
 *  \param[out]  info                      PduInfo Pointer to the Data.
 *  \param[in]   length                    Length of the requested Data.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Bm_GetDataAsPtr(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, PduR_BmTxBufferArrayRamIterType length);
# endif

# if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_CopyDataAsPtr
 *********************************************************************************************************************/
/*! \brief       The total length of the transferred data.
 *  \details     -
 *  \param[in]   bmTxBufferInstanceRomIdx  TxBuffer ID
 *  \return      Length of the transferred data.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(PduR_BmTxBufferArrayRamLengthOfBmTxBufferRomType, PDUR_CODE) PduR_Bm_GetTotalDataTranferredLength(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx);
# endif

# define PDUR_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */
#endif /* PDUR_BM_H */
/**********************************************************************************************************************
 *  END OF FILE: PduR_Bm.h
 *********************************************************************************************************************/
