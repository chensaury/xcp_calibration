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
 *         File:  PduR_Bm.c
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
/* PRQA S 3453 EOF */ /* MD_MSR_FctLikeMacro */
/* PRQA S 4558 EOF */ /* MD_MSR_AutosarBoolean */
/* PRQA S 2995 EOF */ /* MD_CSL_ConstantValueAsDefine */
/* *INDENT-ON* */

#define PDUR_BM_SOURCE
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR.h"
#include "PduR_Bm.h"
#include "PduR_Lock.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#define PduR_Core_MemCpyRamToRam(d, s, l)    VStdMemCpyRamToRam((d), (s), (l))
#define PduR_Core_MemCpyRomToRam(d, s, l)    VStdMemCpyRomToRam((d), (s), (l))

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

#if(PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Init_TxBuffer
 *********************************************************************************************************************/
/*! \brief      This function initializes the BufferManager TxBuffer
 *  \details     -
 *  \pre        PduR_InitMemory() has been executed, if the start up code does not initialize variables.
 *  \note       The function must be called on task level and has not to be interrupted.
 *              by other administrative function calls.
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Init_TxBuffer(void);
#endif

#if(PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Init_TxBufferInstance
 *********************************************************************************************************************/
/*! \brief      This function initializes the BufferManager TxBuffer Instance
 *  \details     -
 *  \pre        PduR_InitMemory() has been executed, if the start up code does not initialize variables.
 *  \note       The function must be called on task level and has not to be interrupted.
 *              by other administrative function calls.
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Init_TxBufferInstance(void);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_PutData_StateHandler_BUFFER_EMPTY_OR_WRITE4READ
 *********************************************************************************************************************/
/*! \brief      Helper function which handles the BUFFER_EMPTY or Write4Read state.
 *  \details    -
 *  \param[in]  txBufferElementStateIdx  txBufferElementStateIdx read index in the transport protocol Tx buffer.
 *  \param[in]  pduLength                length to copy.
 *  \param[in]  sduDataPtr               data pointer.
 *  \return     BUFREQ_OK                State change action was successful.
 *              BUFREQ_E_NOT_OK          State change action was not successful.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_PutData_StateHandler_BUFFER_EMPTY_OR_WRITE4READ(PduR_BmTxBufferRomIterType txBufferElementStateIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                                                        CONST(SduDataPtrType, AUTOMATIC) sduDataPtr);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_UpdateInstance_After_PutData
 *********************************************************************************************************************/
/*! \brief      Update Instance after enqueue data.
 *  \details    -
 *  \param[in]  bmTxBufferInstanceRomIdx  instance Idx.
 *  \param[in]  distanceInstReadIdx      distance between Main Read index and instance read index.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_UpdateInstance_After_PutData(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamIterType distanceInstReadIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Put_Between_WriteIdx_EndIdx
 *********************************************************************************************************************/
/*! \brief      The WriteId leading. Add data up to the buffer end.
 *  \details    -
 *  \param[in]  txBufferElementStateIdx  read index in the transport protocol Tx buffer
 *  \param[in]  pduLength                length to copy
 *  \param[in]  sduDataPtr               data pointer
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Put_Between_WriteIdx_EndIdx(PduR_BmTxBufferRomIterType txBufferElementStateIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                       CONST(SduDataPtrType, AUTOMATIC) sduDataPtr);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_UpdateInstance_After_Put_Between_WriteIdx_EndIdx
 *********************************************************************************************************************/
/*! \brief      Update Write Instance after put Data.
 *  \details    -
 *  \param[in]  bmTxBufferInstanceRomIdx  instance Idx.
 *  \param[in]  distanceInstReadIdx       distance between Main Read index and instance read index.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_UpdateInstance_After_Put_Between_WriteIdx_EndIdx(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx,
                                                                                            PduR_BmTxBufferArrayRamIterType distanceInstReadIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Put_Between_WriteIdx_ReadIdx
 *********************************************************************************************************************/
/*! \brief      The WriteId lagging the ReadIdx. Add data to the buffer in this range.
 *  \details    -
 *  \param[in]  txBufferElementStateIdx  read index in the transport protocol Tx buffer
 *  \param[in]  pduLength                length to copy
 *  \param[in]  sduDataPtr               data pointer
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Put_Between_WriteIdx_ReadIdx(PduR_BmTxBufferRomIterType txBufferElementStateIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                        CONST(SduDataPtrType, AUTOMATIC) sduDataPtr);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_UpdateInstance_After_Put_Between_WriteIdx_ReadIdx
 *********************************************************************************************************************/
/*! \brief      Update Write Instance after put Data.
 *  \details    -
 *  \param[in]  bmTxBufferInstanceRomIdx  instance Idx.
 *  \param[in]  distanceInstReadIdx       distance between Main Read index and instance read index.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_UpdateInstance_After_Put_Between_WriteIdx_ReadIdx(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx,
                                                                                             PduR_BmTxBufferArrayRamIterType distanceInstReadIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_UpdateInstance_StateHandler_BUFFER_EMPTY_OR_WRITE4READ
 *********************************************************************************************************************/
/*! \brief      Helper function which handles the BUFFER_EMPTY state.
 *  \details    -
 *  \param[in]  bmTxBufferInstanceRomIdx  instance Idx.
 *  \param[in]  distanceInstReadIdx       distance between Main Read index and instance read index.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_UpdateInstance_StateHandler_BUFFER_EMPTY_OR_WRITE4READ(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx,
                                                                                                  PduR_BmTxBufferArrayRamIterType distanceInstReadIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_PutData_StateHandler_BUFFER_READ4WRITE
 *********************************************************************************************************************/
/*! \brief      Helper function which handles the BUFFER_READ4WRITE state.
 *  \details    -
 *  \param[in]  txBufferElementStateIdx  read index in the transport protocol Tx buffer
 *  \param[in]  pduLength                length to copy
 *  \param[in]  sduDataPtr               data pointer
 *  \return     BUFREQ_OK                State change action was successful.
 *              BUFREQ_E_NOT_OK          State change action was not successful.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_PutData_StateHandler_BUFFER_READ4WRITE(PduR_BmTxBufferRomIterType txBufferElementStateIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                                               CONST(SduDataPtrType, AUTOMATIC) sduDataPtr);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_UpdateInstance_StateHandler_BUFFER_READ4WRITE
 *********************************************************************************************************************/
/*! \brief      Helper function which handles the BUFFER_READ4WRITE state.
 *  \details    -
 *  \param[in]  bmTxBufferInstanceRomIdx  instance Idx
 *  \param[in]  distanceInstReadIdx       distance between Main Read index and instance read index
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_UpdateInstance_StateHandler_BUFFER_READ4WRITE(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx,
                                                                                         PduR_BmTxBufferArrayRamIterType distanceInstReadIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_UpdateMain_After_GetData
 *********************************************************************************************************************/
/*!  \brief      Call to get queued data from the buffer.
 *   \details    -
 *   \param[in]  txBufferElementStateIdx    read index in the transport protocol Tx buffer.
 *   \param[in]  distanceInstReadIdx                              distance between Main Read index and instance read index.
 *   \return     BUFREQ_OK              Copy action was successful.
 *               BUFREQ_E_NOT_OK        Copy action was not successful.
 *   \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_UpdateMain_After_GetData(PduR_BmTxBufferRomIterType txBufferElementStateIdx, PduR_BmTxBufferArrayRamIterType distanceInstReadIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Get_Between_ReadIdx_WriteIdx
 *********************************************************************************************************************/
/*! \brief      The ReadIdx lagging the WriteIdx. Get data in this range.
 *  \details    -
 *  \param[in]  bmTxBufferInstanceRomIdx instance Idx.
 *  \param[in]  pduLength                length to copy.
 *  \param[in]  sduDataPtr               data pointer.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Get_Between_ReadIdx_WriteIdx(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                        CONST(SduDataPtrType, AUTOMATIC) sduDataPtr);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_UpdateMainReadIdx_After_Get_Between_ReadIdx_WriteIdx
 *********************************************************************************************************************/
/*! \brief      Update main Read Idx after data are dequeued from the buffer.
 *  \details    -
 *  \param[in]  txBufferElementStateIdx    read index in the transport protocol Tx buffer.
 *  \param[in]  distanceInstReadIdx        distance between Main Read index and instance read index.
 *                                         desired length.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_UpdateMainReadIdx_After_Get_Between_ReadIdx_WriteIdx(PduR_BmTxBufferRomIterType txBufferElementStateIdx,
                                                                                                PduR_BmTxBufferArrayRamIterType distanceInstReadIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Get_Between_ReadIdx_EndIdx
 *********************************************************************************************************************/
/*! \brief      The ReadIdx is leading. Get data up to the buffer end.
 *  \details    -
 *  \param[in]  bmTxBufferInstanceRomIdx instance Idx.
 *  \param[in]  pduLength                length to copy.
 *  \param[in]  sduDataPtr               data pointer.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Get_Between_ReadIdx_EndIdx(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                      CONST(SduDataPtrType, AUTOMATIC) sduDataPtr);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_UpdateMainReadIdx_After_Get_Between_ReadIdx_EndIdx
 *********************************************************************************************************************/
/*! \brief      Update main ReadIdx after dequeued data from the buffer.
 *  \details    -
 *  \param[in]  txBufferElementStateIdx  1:N buffer specific destinations read pointer.
 *  \param[in]  distanceInstReadIdx      distance between Main Read index and instance read index.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_UpdateMainReadIdx_After_Get_Between_ReadIdx_EndIdx(PduR_BmTxBufferRomIterType txBufferElementStateIdx, PduR_BmTxBufferArrayRamIterType distanceInstReadIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetData_StateHandler_BUFFER_WRITE4READ
 *********************************************************************************************************************/
/*! \brief      Helper function which handles the BUFFER_WRITE4READ state.
 *  \details    -
 *  \param[in]  bmTxBufferInstanceRomIdx instance Idx.
 *  \param[in]  pduLength              length to copy.
 *  \param[in]  sduDataPtr             data pointer.
 *  \return     BUFREQ_OK              State change action was successful.
 *              BUFREQ_E_NOT_OK        State change action was not successful.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_GetData_StateHandler_BUFFER_WRITE4READ(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                                               CONST(SduDataPtrType, AUTOMATIC) sduDataPtr);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_UpdateMain_After_GetData_StateHandler_BUFFER_WRITE4READ
 *********************************************************************************************************************/
/*! \brief                              Update main ReadIdx after dequeued data from the buffer.
 *  \details    -
 *  \param[in]  txBufferElementStateIdx read index in the transport protocol Tx buffer.
 *  \param[in]  distanceInstReadIdx     distance between Main Read index and instance read index.
 *  \return     BUFREQ_OK               State change action was successful.
 *              BUFREQ_E_NOT_OK         State change action was not successful.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_UpdateMain_After_GetData_StateHandler_BUFFER_WRITE4READ(PduR_BmTxBufferRomIterType txBufferElementStateIdx,
                                                                                                                PduR_BmTxBufferArrayRamIterType distanceInstReadIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetData_StateHandler_BUFFER_FULL_OR_READ4WRITE
 *********************************************************************************************************************/
/*! \brief      Helper function which handles the BUFFER_FULL and READ4WRITE state.
 *  \details    -
 *  \param[in]  bmTxBufferInstanceRomIdx instance Idx
 *  \param[in]  pduLength              length to copy
 *  \param[in]  sduDataPtr             data pointer
 *  \return     BUFREQ_OK              State change action was successful.
 *              BUFREQ_E_NOT_OK        State change action was not successful.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_GetData_StateHandler_BUFFER_FULL_OR_READ4WRITE(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx,
                                                                                                       PduR_BmTxBufferArrayRamIterType pduLength, CONST(SduDataPtrType, AUTOMATIC) sduDataPtr);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_UpdateMain_After_GetData_StateHandler_BUFFER_FULL_OR_READ4WRITE
 *********************************************************************************************************************/
/*! \brief      Helper function which handles the BUFFER_FULL and READ4WRITE state.
 *  \details    -
 *  \param[in]  txBufferElementStateIdx  read index in the transport protocol Tx buffer
 *  \param[in]  distanceInstReadIdx                              distance between Main Read index and instance read index
 *  \return     BUFREQ_OK              State change action was successful.
 *              BUFREQ_E_NOT_OK        State change action was not successful.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_UpdateMain_After_GetData_StateHandler_BUFFER_FULL_OR_READ4WRITE(PduR_BmTxBufferRomIterType txBufferElementStateIdx,
                                                                                                                        PduR_BmTxBufferArrayRamIterType distanceInstReadIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Switch_WriteIdx
 *********************************************************************************************************************/
/*! \brief      Set WriteIdx to buffer start Idx.
 *  \details    -
 *  \param[in]  txBufferElementStateIdx   read index in the transport protocol Tx buffer.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Switch_WriteIdx(PduR_BmTxBufferRomIterType txBufferElementStateIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Switch_Instance_WriteIdx
 *********************************************************************************************************************/
/*! \brief      Set Instance WriteIdx to buffer start Idx.
 *  \details    -
 *  \param[in]  bmTxBufferInstanceRomIdx   instance Idx.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Switch_Instance_WriteIdx(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Switch_ReadIdx
 *********************************************************************************************************************/
/*! \brief      Set ReadIdx to buffer start Idx.
 *  \details    -
 *  \param[in]  txBufferElementStateIdx  read index in the transport protocol Tx buffer.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Switch_ReadIdx(PduR_BmTxBufferRomIterType txBufferElementStateIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetLinearBufferSize
 *********************************************************************************************************************/
/*! \brief      Get the free buffer size which is available without doing a wrap around.
 *  \details    -
 *  \param[in]  bmTxBufferRomIdx  index to the BmTxBuffer element
 *  \return     the calculated free buffer size
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduR_BmTxBufferArrayRamIterType, PDUR_CODE) PduR_Bm_GetLinearBufferSize(PduR_BmTxBufferRomIterType bmTxBufferRomIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetTotalDataSize
 *********************************************************************************************************************/
/*! \brief      Get the total data size which is available
 *  \details    -
 *  \param[in]  bmTxBufferRomIdx  index to the BmTxBuffer element
 *  \return     the calculated total data size
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduR_BmTxBufferArrayRamIterType, PDUR_CODE) PduR_Bm_GetTotalDataSize(PduR_BmTxBufferRomIterType bmTxBufferRomIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetLinearBufferSizeInstance
 *********************************************************************************************************************/
/*! \brief      Get the free buffer size which is available without doing a wrap around.
 *  \details    -
 *  \param[in]  bmTxBufferInstanceRomIdx  index to the BmTxBuffer element
 *  \return     the calculated free buffer size
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduR_BmTxBufferArrayRamIterType, PDUR_CODE) PduR_Bm_GetLinearBufferSizeInstance(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetTotalBufferSizeInstance
 *********************************************************************************************************************/
/*! \brief      Get the total free buffer size which is available
 *  \details    -
 *  \param[in]  bmTxBufferInstanceRomIdx  index to the BmTxBuffer element
 *  \return     the calculated total free buffer size
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduR_BmTxBufferArrayRamIterType, PDUR_CODE) PduR_Bm_GetTotalBufferSizeInstance(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Switch_InstanceReadIdx
 *********************************************************************************************************************/
/*! \brief     Helper function to perform a wrap around for the instance specific read idx.
 *  \details    -
 *  \param[in] bmTxBufferInstanceRomIdx instance Idx.
 *  \pre        -
 *  \note      get data from buffer.
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Switch_InstanceReadIdx(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Switch_WriteIdx_And_PutData
 *********************************************************************************************************************/
/*! \brief      Perform wrap around handling for WriteIdx.
 *  \details    -
 *  \param[in]  txBufferElementStateIdx  read index in the transport protocol Tx buffer.
 *  \param[in]  pduLength              length to copy.
 *  \param[in]  sduDataPtr              data pointer.
 *  \pre        -
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Switch_WriteIdx_And_PutData(PduR_BmTxBufferRomIterType txBufferElementStateIdx, PduR_BmTxBufferArrayRamIterType pduLength, SduDataPtrType sduDataPtr);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Switch_InstanceWriteIdx
 *********************************************************************************************************************/
/*! \brief      Perform wrap around handling for Instance WriteIdx.
 *  \details    -
 *  \param[in]  bmTxBufferInstanceRomIdx  instance Idx.
 *  \param[in]  distanceInstReadIdx        distance between Main Read index and instance read index.
 *  \pre        -
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Switch_InstanceWriteIdx(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamIterType distanceInstReadIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_InstanceReadIdx_WrapAround
 **********************************************************************************************************************/
/*! \brief      Perform a wrap around handling for instance ReadIdx.
 *  \details    -
 *  \param[in]  bmTxBufferInstanceRomIdx  instance Idx.
 *  \param[in]  pduLength              length to copy.
 *  \param[in]  sduDataPtr             data pointer.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_InstanceReadIdx_WrapAround(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                      SduDataPtrType sduDataPtr);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Switch_ReadIdx_And_UpdateMainReadIdx
 **********************************************************************************************************************/
/*! \brief      Perform a wrap around handling for instance ReadIdx.
 *  \details    -
 *  \param[in]  txBufferElementStateIdx    read index in the transport protocol Tx buffer.
 *  \param[in]  distanceInstReadIdx        distance between Main Read index and instance read index.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Switch_ReadIdx_And_UpdateMainReadIdx(PduR_BmTxBufferRomIterType txBufferElementStateIdx, PduR_BmTxBufferArrayRamIterType distanceInstReadIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 *  PduR_Bm_UpdateMainReadIdx
**********************************************************************************************************************/
/*!  \brief        Helper function which checks if the main buffer ReadIdx must be moved.
 *   \details      The main read will be moved if the slowest instance read pointer is moved
 *   \param[in]    txBufferElementStateIdx  read index in the transport protocol Tx buffer
 *   \return       BUFREQ_OK              Update successful.
 *                 BUFREQ_E_NOT_OK        Update not successful.
 *   \pre        -
***********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_UpdateMainReadIdx(PduR_BmTxBufferRomIterType txBufferElementStateIdx);
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_AssignAssociatedBufferInstance2DestinationInstance
 *********************************************************************************************************************/
/*! \brief     This function assign the associated buffer instancee to the destinations instance.
 *  \details   -
 *  \param[in] bmTxBufferInstanceRomIdx   instance Idx
 *  \param[in] bmTxBufferRomIdx    Index of the Tx buffer
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_AssignAssociatedBufferInstance2DestinationInstance(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferRomIterType bmTxBufferRomIdx);
#endif

#define PDUR_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Init_TxBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Init_TxBuffer(void)
{
  PduR_BmTxBufferRomIterType txBufferStateIdx;
  for(txBufferStateIdx = 0u; txBufferStateIdx < PduR_GetSizeOfBmTxBufferRam(); txBufferStateIdx++)
  {
    PduR_Bm_ResetTxBuffer(txBufferStateIdx);
  }
}
#endif

#if(PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Init_TxBufferInstance
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Init_TxBufferInstance(void)
{
  PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx;
  for(bmTxBufferInstanceRomIdx = 0u; bmTxBufferInstanceRomIdx < PduR_GetSizeOfBmTxBufferInstanceRam(); bmTxBufferInstanceRomIdx++)
  {
    PduR_Bm_ResetTxBufferInstance(bmTxBufferInstanceRomIdx);
  }
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_PutData_StateHandler_BUFFER_EMPTY_OR_WRITE4READ
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
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_PutData_StateHandler_BUFFER_EMPTY_OR_WRITE4READ(PduR_BmTxBufferRomIterType txBufferElementStateIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                                                        CONST(SduDataPtrType, AUTOMATIC) sduDataPtr)
{
  BufReq_ReturnType retVal = BUFREQ_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if(PduR_Bm_GetLinearBufferSize(txBufferElementStateIdx) > pduLength)
  {
    PduR_Bm_Put_Between_WriteIdx_EndIdx(txBufferElementStateIdx, pduLength, sduDataPtr);        /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
    if(pduLength != 0u)
    {
      PduR_SetPduRBufferStateOfBmTxBufferRam(txBufferElementStateIdx, PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERRAM);   /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
    }
  }
  else if(PduR_Bm_GetLinearBufferSize(txBufferElementStateIdx) == pduLength)
  {
    if(PduR_Bm_GetLinearBufferSize(txBufferElementStateIdx) == PduR_Bm_GetTotalBufferSize(txBufferElementStateIdx))
    {
      PduR_Bm_Put_Between_WriteIdx_EndIdx(txBufferElementStateIdx, pduLength, sduDataPtr);      /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
      PduR_Bm_Switch_WriteIdx(txBufferElementStateIdx);
      PduR_SetPduRBufferStateOfBmTxBufferRam(txBufferElementStateIdx, PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERRAM); /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
    }
    else
    {
      PduR_Bm_Put_Between_WriteIdx_EndIdx(txBufferElementStateIdx, pduLength, sduDataPtr);      /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
      PduR_Bm_Switch_WriteIdx(txBufferElementStateIdx);
      PduR_SetPduRBufferStateOfBmTxBufferRam(txBufferElementStateIdx, PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERRAM);   /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
    }
  }
  else if(PduR_Bm_GetTotalBufferSize(txBufferElementStateIdx) > pduLength)
  {
    PduR_Bm_Switch_WriteIdx_And_PutData(txBufferElementStateIdx, pduLength, sduDataPtr);        /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
    PduR_SetPduRBufferStateOfBmTxBufferRam(txBufferElementStateIdx, PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERRAM);     /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
  else if(PduR_Bm_GetTotalBufferSize(txBufferElementStateIdx) == pduLength)
  {
    PduR_Bm_Switch_WriteIdx_And_PutData(txBufferElementStateIdx, pduLength, sduDataPtr);        /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
    PduR_SetPduRBufferStateOfBmTxBufferRam(txBufferElementStateIdx, PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERRAM);   /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
  else
  {
    /* Tp will never request more buffer than the PDUR has provided */
    retVal = BUFREQ_E_NOT_OK;
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_AssignAssociatedBuffer2DestinationInstance
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Bm_AssignAssociatedBuffer2DestinationInstance(PduR_BmTxBufferRomIterType bmTxBufferRomIdx, PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx)
{
  if(bmTxBufferInstanceRomIdx > PduR_GetBmTxBufferInstanceRomEndIdxOfBmTxBufferRom(bmTxBufferRomIdx))   /* COV_PDUR_FATAL_ERROR */
  {
    PduR_Det_ReportError(PDUR_RMTP_ASSIGNASSOCIATEDBUFFER2DESTINATION, PDUR_E_FATAL);
  }
  else
  {
    PduR_SetTxBufferUsedOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, TRUE);        /* SBSW_PDUR_CSL03 */
    PduR_Bm_AssignAssociatedBufferInstance2DestinationInstance(bmTxBufferInstanceRomIdx, bmTxBufferRomIdx);
    PduR_SetBmTxBufferArrayRamInstanceStopIdxOfBmTxBufferRam(bmTxBufferRomIdx, (((PduR_BmTxBufferArrayRamInstanceStopIdxOfBmTxBufferRamType) bmTxBufferInstanceRomIdx) + 1u));  /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_AssignAssociatedBufferInstance2DestinationInstance
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_AssignAssociatedBufferInstance2DestinationInstance(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferRomIterType bmTxBufferRomIdx)
{
  PduR_SetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(bmTxBufferRomIdx));       /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  PduR_SetBmTxBufferArrayRamWriteIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(bmTxBufferRomIdx));     /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  PduR_SetPduRBufferStateOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, PduR_GetPduRBufferStateOfBmTxBufferRam(bmTxBufferRomIdx));   /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
* PduR_Bm_CopyData
*********************************************************************************************************************/
/*!
* Internal comment removed.
 *
 *
 *
*********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Bm_CopyData(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamIterType pduLength, CONST(SduDataPtrType, AUTOMATIC) sduDataPtr)     /* COV_PDUR_IF_ONLY */
{
  PduR_BmTxBufferRomIterType bmTxBufferRomIdx = PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx);
  PDUR_DUMMY_STATEMENT(bmTxBufferInstanceRomIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  /* Dequeue Data */
  PduR_Core_MemCpyRamToRam(sduDataPtr, PduR_GetAddrBmTxBufferArrayRam(PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(bmTxBufferRomIdx)), pduLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_PDUR_MEM_CPY_FIFOMGR */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetLinearBufferSize
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduR_BmTxBufferArrayRamIterType, PDUR_CODE) PduR_Bm_GetLinearBufferSize(PduR_BmTxBufferRomIterType bmTxBufferRomIdx)
{
  PduR_BmTxBufferArrayRamIterType retVal = 0u;  /* PRQA S 2981 */ /* MD_MSR_RetVal */

  switch (PduR_GetPduRBufferStateOfBmTxBufferRam(bmTxBufferRomIdx))
  {
    case PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      retVal = PduR_GetBmTxBufferArrayRamEndIdxOfBmTxBufferRom(bmTxBufferRomIdx) - PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(bmTxBufferRomIdx);
      break;
    }
    case PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      retVal = PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(bmTxBufferRomIdx) - PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(bmTxBufferRomIdx);
      break;
    }
    case PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERRAM:      /* COV_PDUR_BUFFER_CALCULATION */
    {
      retVal = 0u;
      break;
    }
    case PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      retVal = PduR_GetBmTxBufferArrayRamEndIdxOfBmTxBufferRom(bmTxBufferRomIdx) - PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(bmTxBufferRomIdx);
      break;
    }
    default:   /* COV_PDUR_MISRA */
      break;
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetTotalDataSize
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduR_BmTxBufferArrayRamIterType, PDUR_CODE) PduR_Bm_GetTotalDataSize(PduR_BmTxBufferRomIterType bmTxBufferRomIdx)
{
  PduR_BmTxBufferArrayRamIterType retVal = 0u;  /* PRQA S 2981 */ /* MD_MSR_RetVal */

  switch (PduR_GetPduRBufferStateOfBmTxBufferRam(bmTxBufferRomIdx))
  {
    case PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERRAM:        /* COV_PDUR_BUFFER_CALCULATION */
    {
      retVal = PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(bmTxBufferRomIdx) - PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(bmTxBufferRomIdx);
      break;
    }
    case PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      retVal =
        PduR_GetBmTxBufferArrayRamLengthOfBmTxBufferRom(bmTxBufferRomIdx) - (PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(bmTxBufferRomIdx) -
                                                                             PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(bmTxBufferRomIdx));
      break;
    }
    case PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      retVal = PduR_GetBmTxBufferArrayRamLengthOfBmTxBufferRom(bmTxBufferRomIdx);
      break;
    }
    case PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERRAM:     /* COV_PDUR_BUFFER_CALCULATION */
    {
      retVal = 0u;
      break;
    }
    default:   /* COV_PDUR_MISRA */
      break;
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetLinearBufferSizeInstance
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduR_BmTxBufferArrayRamIterType, PDUR_CODE) PduR_Bm_GetLinearBufferSizeInstance(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx)
{
  PduR_BmTxBufferArrayRamIterType retVal = 0u;  /* PRQA S 2981 */ /* MD_MSR_RetVal */

  switch (PduR_GetPduRBufferStateOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx))
  {
    case PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:
    {
      retVal =
        PduR_GetBmTxBufferArrayRamEndIdxOfBmTxBufferRom(PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx)) -
        PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx);
      break;
    }
    case PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:
    {
      retVal = PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx) - PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx);
      break;
    }
    case PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:      /* COV_PDUR_BUFFER_CALCULATION */
    {
      retVal = 0u;
      break;
    }
    case PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:
    {
      retVal =
        PduR_GetBmTxBufferArrayRamEndIdxOfBmTxBufferRom(PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx)) -
        PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx);
      break;
    }
    default:   /* COV_PDUR_MISRA */
      break;
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetTotalBufferSizeInstance
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduR_BmTxBufferArrayRamIterType, PDUR_CODE) PduR_Bm_GetTotalBufferSizeInstance(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx)
{
  PduR_BmTxBufferArrayRamIterType retVal = 0u;  /* PRQA S 2981 */ /* MD_MSR_RetVal */

  switch (PduR_GetPduRBufferStateOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx))
  {
    case PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:
    {
      retVal =
        PduR_GetBmTxBufferArrayRamLengthOfBmTxBufferRom(PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx)) -
        (PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx) - PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx));
      break;
    }
    case PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:        /* COV_PDUR_BUFFER_CALCULATION */
    {
      retVal = PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx) - PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx);
      break;
    }
    case PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:      /* COV_PDUR_BUFFER_CALCULATION */
    {
      retVal = 0u;
      break;
    }
    case PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:
    {
      retVal = PduR_GetBmTxBufferArrayRamLengthOfBmTxBufferRom(PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx));
      break;
    }
    default:   /* COV_PDUR_MISRA */
      break;
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_GetData(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamIterType pduLength, CONST(SduDataPtrType, AUTOMATIC) sduDataPtr) /* PRQA S 1505 */ /* MD_PduR_1505 */
{
  BufReq_ReturnType retVal = BUFREQ_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  switch (PduR_GetPduRBufferStateOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx))
  {
    case PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:
    {
      retVal = PduR_Bm_GetData_StateHandler_BUFFER_WRITE4READ(bmTxBufferInstanceRomIdx, pduLength, sduDataPtr); /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
      break;
    }
    case PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:
    {
      retVal = PduR_Bm_GetData_StateHandler_BUFFER_FULL_OR_READ4WRITE(bmTxBufferInstanceRomIdx, pduLength, sduDataPtr); /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
      break;
    }
    case PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:
    {
      retVal = PduR_Bm_GetData_StateHandler_BUFFER_FULL_OR_READ4WRITE(bmTxBufferInstanceRomIdx, pduLength, sduDataPtr); /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
      break;
    }
    case PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:     /* COV_PDUR_ONLY_TT_SINGLE_BUFFER */
    {
      if(pduLength != 0u)       /* COV_PDUR_ONLY_TT_SINGLE_BUFFER */
      {
        /* nothing to do no data available */
        retVal = BUFREQ_E_BUSY;
      }
      break;
    }
    default:   /* COV_PDUR_MISRA */
      break;
  }
  if((retVal == BUFREQ_OK) && (pduLength != 0u))
  {
    retVal = PduR_Bm_UpdateMainReadIdx(PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx));
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_UpdateMain_After_GetData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_UpdateMain_After_GetData(PduR_BmTxBufferRomIterType txBufferElementStateIdx, PduR_BmTxBufferArrayRamIterType distanceInstReadIdx)
{
  BufReq_ReturnType retVal = BUFREQ_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  switch (PduR_GetPduRBufferStateOfBmTxBufferRam(txBufferElementStateIdx))
  {
    case PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      retVal = PduR_Bm_UpdateMain_After_GetData_StateHandler_BUFFER_WRITE4READ(txBufferElementStateIdx, distanceInstReadIdx);
      break;
    }
    case PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      retVal = PduR_Bm_UpdateMain_After_GetData_StateHandler_BUFFER_FULL_OR_READ4WRITE(txBufferElementStateIdx, distanceInstReadIdx);
      break;
    }
    case PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      retVal = PduR_Bm_UpdateMain_After_GetData_StateHandler_BUFFER_FULL_OR_READ4WRITE(txBufferElementStateIdx, distanceInstReadIdx);
      break;
    }
    case PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERRAM:     /* COV_PDUR_FATAL_ERROR */
    {
      /* not enough data available is not possible in this function. */
      PduR_Det_ReportError(PDUR_GW_BUFMGR_UPDATEMAIN_AFTER_GETDATA, PDUR_E_FATAL);
      retVal = BUFREQ_E_BUSY;
      break;
    }
    default:   /* COV_PDUR_MISRA */
      break;
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Get_Between_ReadIdx_WriteIdx
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
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Get_Between_ReadIdx_WriteIdx(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                        CONST(SduDataPtrType, AUTOMATIC) sduDataPtr)
{
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  /* ----- Development Error Checks ------------------------------------- */
  if((PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx) + pduLength) > PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx)))   /* COV_PDUR_FATAL_ERROR */
  {
    errorId = PDUR_E_FATAL;
  }
  else
  {
    /* Dequeue Data */
    PduR_Core_MemCpyRamToRam(sduDataPtr, PduR_GetAddrBmTxBufferArrayRam(PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx)), pduLength);        /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_PDUR_MEM_CPY_RAM2RAM */
    PduR_SetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx) + pduLength); /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)        /* COV_PDUR_FATAL_ERROR */
  {
    PduR_Det_ReportError(PDUR_FCT_GW_BUFMGR_GET_BETWEEN_READIDX_WRITEIDX, errorId);
  }
# endif
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_UpdateMainReadIdx_After_Get_Between_ReadIdx_WriteIdx
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
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_UpdateMainReadIdx_After_Get_Between_ReadIdx_WriteIdx(PduR_BmTxBufferRomIterType txBufferElementStateIdx, PduR_BmTxBufferArrayRamIterType distanceInstReadIdx)
{
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  /* ----- Development Error Checks ------------------------------------- */
  if((PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(txBufferElementStateIdx) + distanceInstReadIdx) > PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(txBufferElementStateIdx))    /* COV_PDUR_FATAL_ERROR */
  {
    errorId = PDUR_E_FATAL;
  }
  else
  {
    PduR_SetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(txBufferElementStateIdx, (PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(txBufferElementStateIdx) + distanceInstReadIdx));       /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)        /* COV_PDUR_FATAL_ERROR */
  {
    PduR_Det_ReportError(PDUR_FCT_GW_BUFMGR_GET_BETWEEN_READIDX_WRITEIDX, errorId);
  }
# endif
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetData_StateHandler_BUFFER_FULL_OR_READ4WRITE
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
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_GetData_StateHandler_BUFFER_FULL_OR_READ4WRITE(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx,
                                                                                                       PduR_BmTxBufferArrayRamIterType pduLength, CONST(SduDataPtrType, AUTOMATIC) sduDataPtr)
{
  BufReq_ReturnType retVal = BUFREQ_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  /* main Tx buffer element */
  if(PduR_Bm_GetLinearDataSizeInstance(bmTxBufferInstanceRomIdx) == pduLength)
  {
    if(PduR_Bm_GetLinearDataSizeInstance(bmTxBufferInstanceRomIdx) == PduR_Bm_GetTotalDataSizeInstance(bmTxBufferInstanceRomIdx))
    {
      PduR_Bm_Get_Between_ReadIdx_EndIdx(bmTxBufferInstanceRomIdx, pduLength, sduDataPtr);      /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
      PduR_Bm_Switch_InstanceReadIdx(bmTxBufferInstanceRomIdx);
      PduR_SetPduRBufferStateOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM);       /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
    }
    else
    {
      PduR_Bm_Get_Between_ReadIdx_EndIdx(bmTxBufferInstanceRomIdx, pduLength, sduDataPtr);      /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
      PduR_Bm_Switch_InstanceReadIdx(bmTxBufferInstanceRomIdx);
      PduR_SetPduRBufferStateOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM);  /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
    }
  }
  else if(PduR_Bm_GetLinearDataSizeInstance(bmTxBufferInstanceRomIdx) > pduLength)
  {
    PduR_Bm_Get_Between_ReadIdx_EndIdx(bmTxBufferInstanceRomIdx, pduLength, sduDataPtr);        /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
    PduR_SetPduRBufferStateOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM);    /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
  else if(PduR_Bm_GetTotalDataSizeInstance(bmTxBufferInstanceRomIdx) > pduLength)
  {
    PduR_Bm_InstanceReadIdx_WrapAround(bmTxBufferInstanceRomIdx, pduLength, sduDataPtr);        /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
    PduR_SetPduRBufferStateOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM);    /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
  else if(PduR_Bm_GetTotalDataSizeInstance(bmTxBufferInstanceRomIdx) == pduLength)
  {
    PduR_Bm_InstanceReadIdx_WrapAround(bmTxBufferInstanceRomIdx, pduLength, sduDataPtr);        /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
    PduR_SetPduRBufferStateOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM); /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
  else
  {
    retVal = BUFREQ_E_BUSY;
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_UpdateMain_After_GetData_StateHandler_BUFFER_FULL_OR_READ4WRITE
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
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_UpdateMain_After_GetData_StateHandler_BUFFER_FULL_OR_READ4WRITE(PduR_BmTxBufferRomIterType txBufferElementStateIdx,
                                                                                                                        PduR_BmTxBufferArrayRamIterType distanceInstReadIdx)
{
  BufReq_ReturnType retVal = BUFREQ_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  if(PduR_Bm_GetLinearDataSize(txBufferElementStateIdx) == distanceInstReadIdx)
  {
    if(PduR_Bm_GetLinearDataSize(txBufferElementStateIdx) == PduR_Bm_GetTotalDataSize(txBufferElementStateIdx))
    {
      PduR_Bm_UpdateMainReadIdx_After_Get_Between_ReadIdx_EndIdx(txBufferElementStateIdx, distanceInstReadIdx);
      PduR_Bm_Switch_ReadIdx(txBufferElementStateIdx);
      PduR_SetPduRBufferStateOfBmTxBufferRam(txBufferElementStateIdx, PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERRAM);        /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
    }
    else
    {
      PduR_Bm_UpdateMainReadIdx_After_Get_Between_ReadIdx_EndIdx(txBufferElementStateIdx, distanceInstReadIdx);
      PduR_Bm_Switch_ReadIdx(txBufferElementStateIdx);
      PduR_SetPduRBufferStateOfBmTxBufferRam(txBufferElementStateIdx, PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERRAM);   /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
    }
  }
  else if(PduR_Bm_GetLinearDataSize(txBufferElementStateIdx) > distanceInstReadIdx)
  {
    PduR_Bm_UpdateMainReadIdx_After_Get_Between_ReadIdx_EndIdx(txBufferElementStateIdx, distanceInstReadIdx);
    PduR_SetPduRBufferStateOfBmTxBufferRam(txBufferElementStateIdx, PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERRAM);     /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
  else if(PduR_Bm_GetTotalDataSize(txBufferElementStateIdx) > distanceInstReadIdx)
  {
    PduR_Bm_Switch_ReadIdx_And_UpdateMainReadIdx(txBufferElementStateIdx, distanceInstReadIdx);
    PduR_SetPduRBufferStateOfBmTxBufferRam(txBufferElementStateIdx, PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERRAM);     /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
  else if(PduR_Bm_GetTotalDataSize(txBufferElementStateIdx) == distanceInstReadIdx)     /* COV_PDUR_FATAL_ERROR */
  {
    PduR_Bm_Switch_ReadIdx_And_UpdateMainReadIdx(txBufferElementStateIdx, distanceInstReadIdx);
    PduR_SetPduRBufferStateOfBmTxBufferRam(txBufferElementStateIdx, PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERRAM);  /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
  else
  {
    /* not enough data available is not possible in this function. */
    PduR_Det_ReportError(PDUR_GW_BUFMGR_UPDATEMAIN_AFTER_GETDATA_STATEHANDLER_BUFFER_FULL_OR_READ4WRITE, PDUR_E_FATAL);
    retVal = BUFREQ_E_BUSY;
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Get_Between_ReadIdx_EndIdx
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
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Get_Between_ReadIdx_EndIdx(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                      CONST(SduDataPtrType, AUTOMATIC) sduDataPtr)
{
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  /* ----- Development Error Checks ------------------------------------- */
  if((PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx) + pduLength) > (PduR_GetBmTxBufferArrayRamEndIdxOfBmTxBufferRom(PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx))))   /* COV_PDUR_FATAL_ERROR */
  {
    errorId = PDUR_E_FATAL;
  }
  else
  {
    /* Dequeue Data */
    PduR_Core_MemCpyRamToRam(sduDataPtr, PduR_GetAddrBmTxBufferArrayRam(PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx)), pduLength);        /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_PDUR_MEM_CPY_RAM2RAM */
    PduR_SetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, (PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx) + pduLength));       /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)        /* COV_PDUR_FATAL_ERROR */
  {
    PduR_Det_ReportError(PDUR_FCT_GW_BUFMGR_GET_BETWEEN_READIDX_ENDIDX, errorId);
  }
# endif
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_UpdateMainReadIdx_After_Get_Between_ReadIdx_EndIdx
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
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_UpdateMainReadIdx_After_Get_Between_ReadIdx_EndIdx(PduR_BmTxBufferRomIterType txBufferElementStateIdx, PduR_BmTxBufferArrayRamIterType distanceInstReadIdx)
{
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  /* ----- Development Error Checks ------------------------------------- */
  if((PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(txBufferElementStateIdx) + distanceInstReadIdx) > PduR_GetBmTxBufferArrayRamEndIdxOfBmTxBufferRom(txBufferElementStateIdx))      /* COV_PDUR_FATAL_ERROR */
  {
    errorId = PDUR_E_FATAL;
  }
  else
  {
    PduR_SetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(txBufferElementStateIdx, (PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(txBufferElementStateIdx) + distanceInstReadIdx));       /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)        /* COV_PDUR_FATAL_ERROR */
  {
    PduR_Det_ReportError(PDUR_FCT_GW_BUFMGR_GET_BETWEEN_READIDX_ENDIDX, errorId);
  }
# endif
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetData_StateHandler_BUFFER_WRITE4READ
 *********************************************************************************************************************/
/*!
 *Internal comment removed.
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
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_GetData_StateHandler_BUFFER_WRITE4READ(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                                               CONST(SduDataPtrType, AUTOMATIC) sduDataPtr)
{
  BufReq_ReturnType retVal = BUFREQ_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  if(PduR_Bm_GetLinearDataSizeInstance(bmTxBufferInstanceRomIdx) == pduLength)
  {
    PduR_Bm_Get_Between_ReadIdx_WriteIdx(bmTxBufferInstanceRomIdx, pduLength, sduDataPtr);      /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
    PduR_SetPduRBufferStateOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM); /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
  else if(PduR_Bm_GetLinearDataSizeInstance(bmTxBufferInstanceRomIdx) > pduLength)
  {
    PduR_Bm_Get_Between_ReadIdx_WriteIdx(bmTxBufferInstanceRomIdx, pduLength, sduDataPtr);      /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
  }
  else
  {
    /* not enough data available */
    retVal = BUFREQ_E_BUSY;
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetData_StateHandler_BUFFER_WRITE4READ
 *********************************************************************************************************************/
/*!
 *Internal comment removed.
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
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_UpdateMain_After_GetData_StateHandler_BUFFER_WRITE4READ(PduR_BmTxBufferRomIterType txBufferElementStateIdx,
                                                                                                                PduR_BmTxBufferArrayRamIterType distanceInstReadIdx)
{
  BufReq_ReturnType retVal = BUFREQ_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  if(PduR_Bm_GetLinearDataSize(txBufferElementStateIdx) == distanceInstReadIdx)
  {
    PduR_Bm_UpdateMainReadIdx_After_Get_Between_ReadIdx_WriteIdx(txBufferElementStateIdx, distanceInstReadIdx);
    PduR_SetPduRBufferStateOfBmTxBufferRam(txBufferElementStateIdx, PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERRAM);  /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
  else if(PduR_Bm_GetLinearDataSize(txBufferElementStateIdx) > distanceInstReadIdx)     /* COV_PDUR_FATAL_ERROR */
  {
    PduR_Bm_UpdateMainReadIdx_After_Get_Between_ReadIdx_WriteIdx(txBufferElementStateIdx, distanceInstReadIdx);
  }
  else
  {
    /* not enough data available is not possible in this function. */
    PduR_Det_ReportError(PDUR_GW_BUFMGR_UPDATEMAIN_AFTER_GETDATA_STATEHANDLER_BUFFER_WRITE4READ, PDUR_E_FATAL);
    retVal = BUFREQ_E_BUSY;
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_PutData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_UpdateInstance_After_PutData(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamIterType distanceInstReadIdx)
{
  switch (PduR_GetPduRBufferStateOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx))
  {
    case PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:
    {
      PduR_Bm_UpdateInstance_StateHandler_BUFFER_EMPTY_OR_WRITE4READ(bmTxBufferInstanceRomIdx, distanceInstReadIdx);
      break;
    }
    case PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:
    {
      PduR_Bm_UpdateInstance_StateHandler_BUFFER_EMPTY_OR_WRITE4READ(bmTxBufferInstanceRomIdx, distanceInstReadIdx);
      break;
    }
    case PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:
    {
      PduR_Bm_UpdateInstance_StateHandler_BUFFER_READ4WRITE(bmTxBufferInstanceRomIdx, distanceInstReadIdx);
      break;
    }
    case PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      if(distanceInstReadIdx != 0u)
      {
        /* nothing to do, no buffer available */
      }
      break;
    }
    default:   /* COV_PDUR_MISRA */
      break;
  }
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Put_Between_WriteIdx_ReadIdx
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
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Put_Between_WriteIdx_ReadIdx(PduR_BmTxBufferRomIterType txBufferElementStateIdx, PduR_BmTxBufferArrayRamIterType pduLength, CONST(SduDataPtrType, AUTOMATIC) sduDataPtr)     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  /* ----- Development Error Checks ------------------------------------- */
  if((PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(txBufferElementStateIdx) + pduLength) > PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(txBufferElementStateIdx))      /* COV_PDUR_FATAL_ERROR */
  {
    errorId = PDUR_E_FATAL;
  }
  else
  {
    /* Dequeue Data */
    PduR_Core_MemCpyRamToRam(PduR_GetAddrBmTxBufferArrayRam(PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(txBufferElementStateIdx)), sduDataPtr, pduLength);        /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_PDUR_MEM_CPY_RAM2RAM */
    PduR_SetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(txBufferElementStateIdx, (PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(txBufferElementStateIdx) + pduLength));       /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)        /* COV_PDUR_FATAL_ERROR */
  {
    PduR_Det_ReportError(PDUR_FCT_GW_BUFMGR_PUT_BETWEEN_WRITEIDX_READIDX, errorId);
  }
# endif
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_UpdateInstance_After_Put_Between_WriteIdx_ReadIdx
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
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_UpdateInstance_After_Put_Between_WriteIdx_ReadIdx(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx,
                                                                                             PduR_BmTxBufferArrayRamIterType distanceInstReadIdx)
{
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  /* ----- Development Error Checks ------------------------------------- */
  if((PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx) + distanceInstReadIdx) > PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx))  /* COV_PDUR_FATAL_ERROR */
  {
    errorId = PDUR_E_FATAL;
  }
  else
  {
    PduR_SetBmTxBufferArrayRamWriteIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, (PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx) + distanceInstReadIdx));   /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)        /* COV_PDUR_FATAL_ERROR */
  {
    PduR_Det_ReportError(PDUR_FCT_GW_BUFMGR_PUT_BETWEEN_WRITEIDX_READIDX, errorId);
  }
# endif
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_PutData_StateHandler_BUFFER_READ4WRITE
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
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_PutData_StateHandler_BUFFER_READ4WRITE(PduR_BmTxBufferRomIterType txBufferElementStateIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                                               CONST(SduDataPtrType, AUTOMATIC) sduDataPtr)
{
  BufReq_ReturnType retVal = BUFREQ_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  if(PduR_Bm_GetLinearBufferSize(txBufferElementStateIdx) == pduLength)
  {
    PduR_Bm_Put_Between_WriteIdx_ReadIdx(txBufferElementStateIdx, pduLength, sduDataPtr);       /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
    PduR_SetPduRBufferStateOfBmTxBufferRam(txBufferElementStateIdx, PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERRAM);   /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
  else if((PduR_Bm_GetLinearBufferSize(txBufferElementStateIdx) > pduLength))
  {
    PduR_Bm_Put_Between_WriteIdx_ReadIdx(txBufferElementStateIdx, pduLength, sduDataPtr);       /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */

  }
  else
  {
    /* Not enough free buffer space available. Tp will never request more buffer than the PDUR has provided */
    retVal = BUFREQ_E_NOT_OK;
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_UpdateInstance_StateHandler_BUFFER_READ4WRITE
 *********************************************************************************************************************/
/*!
* This function is is called to update the instance parameters after data is copied to the buffer between read and write index
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
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_UpdateInstance_StateHandler_BUFFER_READ4WRITE(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx,
                                                                                         PduR_BmTxBufferArrayRamIterType distanceInstReadIdx)
{
  if(PduR_Bm_GetLinearBufferSizeInstance(bmTxBufferInstanceRomIdx) == distanceInstReadIdx)
  {
    PduR_Bm_UpdateInstance_After_Put_Between_WriteIdx_ReadIdx(bmTxBufferInstanceRomIdx, distanceInstReadIdx);
    PduR_SetPduRBufferStateOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERRAM);  /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
  else if((PduR_Bm_GetLinearBufferSizeInstance(bmTxBufferInstanceRomIdx) > distanceInstReadIdx))
  {
    PduR_Bm_UpdateInstance_After_Put_Between_WriteIdx_ReadIdx(bmTxBufferInstanceRomIdx, distanceInstReadIdx);
  }
  else
  {
    /* Not enough free buffer space available. Tp will never request more buffer than the PDUR has provided */
  }
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_UpdateInstance_StateHandler_BUFFER_EMPTY_OR_WRITE4READ
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
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_UpdateInstance_StateHandler_BUFFER_EMPTY_OR_WRITE4READ(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx,
                                                                                                  PduR_BmTxBufferArrayRamIterType distanceInstReadIdx)
{
  if(PduR_Bm_GetLinearBufferSizeInstance(bmTxBufferInstanceRomIdx) > distanceInstReadIdx)
  {
    PduR_Bm_UpdateInstance_After_Put_Between_WriteIdx_EndIdx(bmTxBufferInstanceRomIdx, distanceInstReadIdx);
    if(distanceInstReadIdx != 0u)
    {
      PduR_SetPduRBufferStateOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM);  /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
    }
  }
  else if(PduR_Bm_GetLinearBufferSizeInstance(bmTxBufferInstanceRomIdx) == distanceInstReadIdx)
  {
    if(PduR_Bm_GetLinearBufferSizeInstance(bmTxBufferInstanceRomIdx) == PduR_Bm_GetTotalBufferSizeInstance(bmTxBufferInstanceRomIdx))
    {
      PduR_Bm_UpdateInstance_After_Put_Between_WriteIdx_EndIdx(bmTxBufferInstanceRomIdx, distanceInstReadIdx);
      PduR_Bm_Switch_Instance_WriteIdx(bmTxBufferInstanceRomIdx);
      PduR_SetPduRBufferStateOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM);        /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
    }
    else
    {
      PduR_Bm_UpdateInstance_After_Put_Between_WriteIdx_EndIdx(bmTxBufferInstanceRomIdx, distanceInstReadIdx);
      PduR_Bm_Switch_Instance_WriteIdx(bmTxBufferInstanceRomIdx);
      PduR_SetPduRBufferStateOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM);  /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
    }
  }
  else if(PduR_Bm_GetTotalBufferSizeInstance(bmTxBufferInstanceRomIdx) > distanceInstReadIdx)
  {
    PduR_Bm_Switch_InstanceWriteIdx(bmTxBufferInstanceRomIdx, distanceInstReadIdx);
    PduR_SetPduRBufferStateOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM);    /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
  else if(PduR_Bm_GetTotalBufferSizeInstance(bmTxBufferInstanceRomIdx) == distanceInstReadIdx)
  {
    PduR_Bm_Switch_InstanceWriteIdx(bmTxBufferInstanceRomIdx, distanceInstReadIdx);
    PduR_SetPduRBufferStateOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM);  /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
  else
  {
    /* Tp will never request more buffer than the PDUR has provided */
  }
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Put_Between_WriteIdx_EndIdx
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
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Put_Between_WriteIdx_EndIdx(PduR_BmTxBufferRomIterType txBufferElementStateIdx, PduR_BmTxBufferArrayRamIterType pduLength, CONST(SduDataPtrType, AUTOMATIC) sduDataPtr)      /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  /* ----- Development Error Checks ------------------------------------- */
  if((PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(txBufferElementStateIdx) + pduLength) > (PduR_GetBmTxBufferArrayRamEndIdxOfBmTxBufferRom(txBufferElementStateIdx)))     /* COV_PDUR_FATAL_ERROR */
  {
    errorId = PDUR_E_FATAL;
  }
  else
  {
    /* Enqueue Data */
    PduR_Core_MemCpyRamToRam(PduR_GetAddrBmTxBufferArrayRam(PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(txBufferElementStateIdx)), sduDataPtr, pduLength);        /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_PDUR_MEM_CPY_RAM2RAM */
    PduR_SetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(txBufferElementStateIdx, (PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(txBufferElementStateIdx) + pduLength));       /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)        /* COV_PDUR_FATAL_ERROR */
  {
    PduR_Det_ReportError(PDUR_FCT_GW_BUFMGR_PUT_BETWEEN_WRITEIDX_ENDIDX, errorId);
  }
# endif
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_UpdateInstance_After_Put_Between_WriteIdx_EndIdx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_UpdateInstance_After_Put_Between_WriteIdx_EndIdx(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx,
                                                                                            PduR_BmTxBufferArrayRamIterType distanceInstReadIdx)
{
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  /* ----- Development Error Checks ------------------------------------- */
  /* main Tx buffer element */
  PduR_BmTxBufferRomIterType txBufferElementStateIdx = PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx);
  if((PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx) + distanceInstReadIdx) > PduR_GetBmTxBufferArrayRamEndIdxOfBmTxBufferRom(txBufferElementStateIdx))    /* COV_PDUR_FATAL_ERROR */
  {
    errorId = PDUR_E_FATAL;
  }
  else
  {
    PduR_SetBmTxBufferArrayRamWriteIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, (PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx) + distanceInstReadIdx));   /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)        /* COV_PDUR_FATAL_ERROR */
  {
    PduR_Det_ReportError(PDUR_FCT_GW_BUFMGR_PUT_BETWEEN_WRITEIDX_ENDIDX, errorId);
  }
# endif
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(txBufferElementStateIdx);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Switch_WriteIdx
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
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Switch_WriteIdx(PduR_BmTxBufferRomIterType txBufferElementStateIdx)
{
  PduR_SetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(txBufferElementStateIdx, PduR_GetBmTxBufferArrayRamStartIdxOfBmTxBufferRom(txBufferElementStateIdx));       /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Switch_Instance_WriteIdx
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
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Switch_Instance_WriteIdx(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx)
{
  PduR_BmTxBufferRomIterType txBufferElementStateIdx = PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx);
  PduR_SetBmTxBufferArrayRamWriteIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, PduR_GetBmTxBufferArrayRamStartIdxOfBmTxBufferRom(txBufferElementStateIdx));      /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */

  PDUR_DUMMY_STATEMENT(txBufferElementStateIdx);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Switch_ReadIdx
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
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Switch_ReadIdx(PduR_BmTxBufferRomIterType txBufferElementStateIdx)
{
  PduR_SetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(txBufferElementStateIdx, PduR_GetBmTxBufferArrayRamStartIdxOfBmTxBufferRom(txBufferElementStateIdx));        /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Switch_InstanceReadIdx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Switch_InstanceReadIdx(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx)
{
  /* main Tx buffer element */
  PduR_BmTxBufferRomIdxOfBmTxBufferInstanceRomType txBufferElementStateIdx = PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx);
  PduR_SetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, PduR_GetBmTxBufferArrayRamStartIdxOfBmTxBufferRom(txBufferElementStateIdx));       /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */

  PDUR_DUMMY_STATEMENT(txBufferElementStateIdx);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Switch_WriteIdx_And_PutData
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
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Switch_WriteIdx_And_PutData(PduR_BmTxBufferRomIterType txBufferElementStateIdx, PduR_BmTxBufferArrayRamIterType pduLength, SduDataPtrType sduDataPtr)
{
  PduR_BmTxBufferArrayRamIterType pduLengthHead, pduLengthTail;
  pduLengthTail = PduR_Bm_GetLinearBufferSize(txBufferElementStateIdx);
  pduLengthHead = pduLength - pduLengthTail;
  PduR_Bm_Put_Between_WriteIdx_EndIdx(txBufferElementStateIdx, pduLengthTail, sduDataPtr);      /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
  PduR_Bm_Switch_WriteIdx(txBufferElementStateIdx);
  PduR_Bm_Put_Between_WriteIdx_ReadIdx(txBufferElementStateIdx, pduLengthHead, &sduDataPtr[pduLengthTail]);     /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Switch_InstanceWriteIdx
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
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Switch_InstanceWriteIdx(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamIterType distanceInstReadIdx)
{
  PduR_BmTxBufferArrayRamIterType taillength = PduR_Bm_GetLinearBufferSizeInstance(bmTxBufferInstanceRomIdx);
  PduR_BmTxBufferArrayRamIterType headlenght = distanceInstReadIdx - taillength;
  PduR_Bm_UpdateInstance_After_Put_Between_WriteIdx_EndIdx(bmTxBufferInstanceRomIdx, taillength);
  PduR_Bm_Switch_Instance_WriteIdx(bmTxBufferInstanceRomIdx);
  PduR_Bm_UpdateInstance_After_Put_Between_WriteIdx_ReadIdx(bmTxBufferInstanceRomIdx, headlenght);
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Switch_ReadIdx_And_UpdateMainReadIdx
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
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Switch_ReadIdx_And_UpdateMainReadIdx(PduR_BmTxBufferRomIterType txBufferElementStateIdx, PduR_BmTxBufferArrayRamIterType distanceInstReadIdx)
{
  PduR_BmTxBufferArrayRamIterType taillength = PduR_Bm_GetLinearDataSize(txBufferElementStateIdx);
  PduR_BmTxBufferArrayRamIterType headlength = distanceInstReadIdx - taillength;
  PduR_Bm_UpdateMainReadIdx_After_Get_Between_ReadIdx_EndIdx(txBufferElementStateIdx, taillength);
  PduR_Bm_Switch_ReadIdx(txBufferElementStateIdx);
  PduR_Bm_UpdateMainReadIdx_After_Get_Between_ReadIdx_WriteIdx(txBufferElementStateIdx, headlength);
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_InstanceReadIdx_WrapAround
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
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_InstanceReadIdx_WrapAround(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamIterType pduLength, SduDataPtrType sduDataPtr)
{
  PduR_BmTxBufferArrayRamIterType pduLengthHead, pduLengthTail;
  pduLengthTail = PduR_Bm_GetLinearDataSizeInstance(bmTxBufferInstanceRomIdx);
  pduLengthHead = pduLength - pduLengthTail;
  PduR_Bm_Get_Between_ReadIdx_EndIdx(bmTxBufferInstanceRomIdx, PduR_Bm_GetLinearDataSizeInstance(bmTxBufferInstanceRomIdx), sduDataPtr);        /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
  PduR_Bm_Switch_InstanceReadIdx(bmTxBufferInstanceRomIdx);
  PduR_Bm_Get_Between_ReadIdx_WriteIdx(bmTxBufferInstanceRomIdx, pduLengthHead, &sduDataPtr[pduLengthTail]);    /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
*  PduR_Bm_UpdateMainReadIdx
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
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_UpdateMainReadIdx(PduR_BmTxBufferRomIterType txBufferElementStateIdx)
{
  BufReq_ReturnType retVal = BUFREQ_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_BmTxBufferArrayRamIterType deltaInstIdxMainIdxTailMainIdx = 0u;
  PduR_BmTxBufferArrayRamIterType deltaInstIdxMainIdxTailInstIdx = 0u;
  boolean bIsAnyInstanceFull = FALSE;
  PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx;
  PduR_BmTxBufferArrayRamStartIdxOfBmTxBufferRomType txBufferArrayStartIdx = PduR_GetBmTxBufferArrayRamStartIdxOfBmTxBufferRom(txBufferElementStateIdx);
  PduR_BmTxBufferArrayRamIterType txBufferArrayEndIdx = PduR_GetBmTxBufferArrayRamEndIdxOfBmTxBufferRom(txBufferElementStateIdx);
  PduR_BmTxBufferArrayRamIterType mainReadIdx = PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(txBufferElementStateIdx);
  PduR_BmTxBufferArrayRamIterType currentBeforeDestReadIdx = mainReadIdx;
  PduR_BmTxBufferArrayRamIterType currentAfterDestReadIdx = txBufferArrayEndIdx;        /* Start search at the end of the TxBuffer */
  for(bmTxBufferInstanceRomIdx = PduR_GetBmTxBufferInstanceRomStartIdxOfBmTxBufferRom(txBufferElementStateIdx);
      bmTxBufferInstanceRomIdx < PduR_GetBmTxBufferArrayRamInstanceStopIdxOfBmTxBufferRam(txBufferElementStateIdx); bmTxBufferInstanceRomIdx++)
  {
    if(PduR_IsTxBufferUsedOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx))    /* COV_PDUR_TX_BUFFER_USED */
    {
      /* Iterate over all Instance Read Idx's */
      PduR_BmTxBufferArrayRamIterType txInstanceReadIdx = PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx);
      /* Search the Index which is next to the Main Read */
      /* Scenario 1 */
      if(mainReadIdx == txInstanceReadIdx)
      {
        if(PduR_GetPduRBufferStateOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx) == PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERRAM)        /* COV_PDUR_SINGLE_INSTANCE */
        {
          if(((txBufferArrayStartIdx <= txInstanceReadIdx) && (txInstanceReadIdx <= currentBeforeDestReadIdx))) /* COV_PDUR_ROBUSTNESS */
          {
            deltaInstIdxMainIdxTailMainIdx = ((txBufferArrayEndIdx - mainReadIdx) + (txInstanceReadIdx - txBufferArrayStartIdx));       /* PRQA S 2985 */ /* MD_PduR_2985 */
            currentBeforeDestReadIdx = txInstanceReadIdx;
          }
        }
        else
        {
          /* main read index is still equal instance read index */
          bIsAnyInstanceFull = TRUE;
        }
      }
      /* Scenario 2 */
      else if((mainReadIdx < txInstanceReadIdx) && (txInstanceReadIdx < currentAfterDestReadIdx))       /* COV_PDUR_SINGLE_INSTANCE */
      {
        currentAfterDestReadIdx = txInstanceReadIdx;
        deltaInstIdxMainIdxTailInstIdx = (txInstanceReadIdx - mainReadIdx);
      }
      /* Scenario 3 */
      else if(((txBufferArrayStartIdx <= txInstanceReadIdx) && (txInstanceReadIdx < currentBeforeDestReadIdx))) /* COV_PDUR_ROBUSTNESS */
      {
        currentBeforeDestReadIdx = txInstanceReadIdx;
        deltaInstIdxMainIdxTailMainIdx = ((txBufferArrayEndIdx - mainReadIdx) + (txInstanceReadIdx - txBufferArrayStartIdx));   /* PRQA S 2985 */ /* MD_PduR_2985 */
      }
      else
      {
        /* nothing to do */
      }
    }
  }
  if(!bIsAnyInstanceFull)       /* COV_PDUR_SINGLE_INSTANCE */
  {
    /* Check if currentAfterDestReadIdx != BmTxBufferArrayRamEndIdx */
    if((mainReadIdx < currentAfterDestReadIdx) && (currentAfterDestReadIdx < txBufferArrayEndIdx))      /* COV_PDUR_ROBUSTNESS */
    {
      retVal = PduR_Bm_UpdateMain_After_GetData(txBufferElementStateIdx, deltaInstIdxMainIdxTailInstIdx);
    }
    else if((txBufferArrayStartIdx <= currentBeforeDestReadIdx) && (currentBeforeDestReadIdx <= mainReadIdx))   /* COV_PDUR_ROBUSTNESS */
    {
      retVal = PduR_Bm_UpdateMain_After_GetData(txBufferElementStateIdx, deltaInstIdxMainIdxTailMainIdx);
    }
    else
    {
      PduR_Det_ReportError(PDUR_GW_BUFMGR_UPDATEMAINREADIDX, PDUR_E_FATAL);
    }
  }
  else
  {
    /* no Update because the slowest Instance does not move! */
  }
  return retVal;
}       /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#if(PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Bm_Init(void)
{
  /* Init Buffer manager */
  PduR_Bm_Init_TxBuffer();
  PduR_Bm_Init_TxBufferInstance();
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_PutData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_PutData(PduR_BmTxBufferRomIterType txBufferElementIdx, PduR_BmTxBufferArrayRamIterType pduLength, CONST(SduDataPtrType, AUTOMATIC) sduDataPtr)
{
  BufReq_ReturnType retVal = BUFREQ_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx;
  switch (PduR_GetPduRBufferStateOfBmTxBufferRam(txBufferElementIdx))
  {
    case PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      retVal = PduR_Bm_PutData_StateHandler_BUFFER_EMPTY_OR_WRITE4READ(txBufferElementIdx, pduLength, sduDataPtr);      /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
      break;
    }
    case PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      retVal = PduR_Bm_PutData_StateHandler_BUFFER_EMPTY_OR_WRITE4READ(txBufferElementIdx, pduLength, sduDataPtr);      /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
      break;
    }
    case PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      retVal = PduR_Bm_PutData_StateHandler_BUFFER_READ4WRITE(txBufferElementIdx, pduLength, sduDataPtr);       /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
      break;
    }
    case PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      if(pduLength != 0u)
      {
        /* nothing to do, no buffer available return BUFREQ_E_NOT_OK */
        retVal = BUFREQ_E_NOT_OK;
      }
      break;
    }
    default:   /* COV_PDUR_MISRA */
      break;
  }
  for(bmTxBufferInstanceRomIdx = PduR_GetBmTxBufferInstanceRomStartIdxOfBmTxBufferRom(txBufferElementIdx);
      bmTxBufferInstanceRomIdx < PduR_GetBmTxBufferArrayRamInstanceStopIdxOfBmTxBufferRam(txBufferElementIdx); bmTxBufferInstanceRomIdx++)
  {
    PduR_Bm_UpdateInstance_After_PutData(bmTxBufferInstanceRomIdx, (pduLength));
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetDataAsPtr
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_PutDataAsPtr(PduR_BmTxBufferRomIterType txBufferElementIdx, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)      /* COV_PDUR_IF_ONLY */
{
  info->SduDataPtr = PduR_GetAddrBmTxBufferArrayRam(PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(txBufferElementIdx));      /* SBSW_PDUR_STACK_VARIABLE */
  info->SduLength = (PduLengthType) PduR_Bm_GetLinearBufferSize(txBufferElementIdx);    /* SBSW_PDUR_STACK_VARIABLE */
  return PduR_Bm_PutData(txBufferElementIdx, info->SduLength, info->SduDataPtr);        /* SBSW_PDUR_STACK_VARIABLE */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_ResetTxBuffer
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
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Bm_ResetTxBuffer(PduR_BmTxBufferRomIterType txBufferElementStateIdx)
{
  PduR_SetRxLengthOfBmTxBufferRam(txBufferElementStateIdx, PduR_GetBmTxBufferArrayRamLengthOfBmTxBufferRom(txBufferElementStateIdx));   /* SBSW_PDUR_CSL01 */
  PduR_SetTpBufMgrStateOfBmTxBufferRam(txBufferElementStateIdx, PDUR_BUFFER_IDLE_TPBUFMGRSTATEOFBMTXBUFFERRAM); /* SBSW_PDUR_CSL01 */
  PduR_SetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(txBufferElementStateIdx, (PduR_GetBmTxBufferArrayRamStartIdxOfBmTxBufferRom(txBufferElementStateIdx)));      /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  PduR_SetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(txBufferElementStateIdx, (PduR_GetBmTxBufferArrayRamStartIdxOfBmTxBufferRom(txBufferElementStateIdx)));     /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  PduR_SetPduRBufferStateOfBmTxBufferRam(txBufferElementStateIdx, PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERRAM);    /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  PduR_SetBmTxBufferArrayRamInstanceStopIdxOfBmTxBufferRam(txBufferElementStateIdx, PduR_GetBmTxBufferInstanceRomStartIdxOfBmTxBufferRom(txBufferElementStateIdx));     /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */

  PDUR_DUMMY_STATEMENT(txBufferElementStateIdx);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
  PduR_Bm_ResetTxBufferInstance
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
  *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Bm_ResetTxBufferInstance(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx)
{
  PduR_BmTxBufferRomIdxOfBmTxBufferInstanceRomType txBufferElementStateIdx = PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx);
  PduR_SetTxBufferUsedOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, FALSE); /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  PduR_SetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, (PduR_GetBmTxBufferArrayRamStartIdxOfBmTxBufferRom((txBufferElementStateIdx))));   /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  PduR_SetBmTxBufferArrayRamWriteIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, (PduR_GetBmTxBufferArrayRamStartIdxOfBmTxBufferRom(txBufferElementStateIdx)));    /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  PduR_SetPduRBufferStateOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERRAM);   /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */

  PDUR_DUMMY_STATEMENT(bmTxBufferInstanceRomIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(txBufferElementStateIdx);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetLinearDataSize
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(PduR_BmTxBufferArrayRamIterType, PDUR_CODE) PduR_Bm_GetLinearDataSize(PduR_BmTxBufferRomIterType bmTxBufferRomIdx) /* PRQA S 1505 */ /* MD_PduR_1505 */
{
  PduR_BmTxBufferArrayRamIterType retVal = 0u;  /* PRQA S 2981 */ /* MD_MSR_RetVal */

  switch (PduR_GetPduRBufferStateOfBmTxBufferRam(bmTxBufferRomIdx))
  {
    case PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      retVal = PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(bmTxBufferRomIdx) - PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(bmTxBufferRomIdx);
      break;
    }
    case PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    case PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      retVal = PduR_GetBmTxBufferArrayRamEndIdxOfBmTxBufferRom(bmTxBufferRomIdx) - PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(bmTxBufferRomIdx);
      break;
    }
    case PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERRAM:     /* COV_PDUR_BUFFER_CALCULATION */
    {
      retVal = 0u;
      break;
    }
    default:   /* COV_PDUR_MISRA */
      break;
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetLinearDataSizeInstance
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(PduR_BmTxBufferArrayRamIterType, PDUR_CODE) PduR_Bm_GetLinearDataSizeInstance(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx) /* PRQA S 1505 */ /* MD_PduR_1505 */
{
  PduR_BmTxBufferArrayRamIterType retVal = 0u;  /* PRQA S 2981 */ /* MD_MSR_RetVal */

  switch (PduR_GetPduRBufferStateOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx))
  {
    case PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:
    {
      retVal = PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx) - PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx);
      break;
    }
    case PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:
    case PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:
    {
      retVal =
        PduR_GetBmTxBufferArrayRamEndIdxOfBmTxBufferRom(PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx)) -
        PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx);
      break;
    }
    case PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:     /* COV_PDUR_BUFFER_CALCULATION */
    {
      retVal = 0u;
      break;
    }
    default:   /* COV_PDUR_MISRA */
      break;
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetTotalBufferSize
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(PduR_BmTxBufferArrayRamIterType, PDUR_CODE) PduR_Bm_GetTotalBufferSize(PduR_BmTxBufferRomIterType bmTxBufferRomIdx)        /* PRQA S 1505 */ /* MD_PduR_1505 */
{
  PduR_BmTxBufferArrayRamIterType retVal = 0u;  /* PRQA S 2981 */ /* MD_MSR_RetVal */

  switch (PduR_GetPduRBufferStateOfBmTxBufferRam(bmTxBufferRomIdx))
  {
    case PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      retVal =
        PduR_GetBmTxBufferArrayRamLengthOfBmTxBufferRom(bmTxBufferRomIdx) - (PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(bmTxBufferRomIdx) -
                                                                             PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(bmTxBufferRomIdx));
      break;
    }
    case PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERRAM:        /* COV_PDUR_BUFFER_CALCULATION */
    {
      retVal = PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(bmTxBufferRomIdx) - PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(bmTxBufferRomIdx);
      break;
    }
    case PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERRAM:      /* COV_PDUR_BUFFER_CALCULATION */
    {
      retVal = 0u;
      break;
    }
    case PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      retVal = PduR_GetBmTxBufferArrayRamLengthOfBmTxBufferRom(bmTxBufferRomIdx);
      break;
    }
    default:   /* COV_PDUR_MISRA */
      break;
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetTotalDataSizeInstance
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(PduR_BmTxBufferArrayRamIterType, PDUR_CODE) PduR_Bm_GetTotalDataSizeInstance(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx)  /* PRQA S 1505 */ /* MD_PduR_1505 */
{
  PduR_BmTxBufferArrayRamIterType retVal = 0u;  /* PRQA S 2981 */ /* MD_MSR_RetVal */

  switch (PduR_GetPduRBufferStateOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx))
  {
    case PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:        /* COV_PDUR_BUFFER_CALCULATION */
    {
      retVal = PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx) - PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx);
      break;
    }
    case PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:
    {
      retVal =
        PduR_GetBmTxBufferArrayRamLengthOfBmTxBufferRom(PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx)) -
        (PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx) - PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx));
      break;
    }
    case PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:
    {
      retVal = PduR_GetBmTxBufferArrayRamLengthOfBmTxBufferRom(PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx));
      break;
    }
    case PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:     /* COV_PDUR_BUFFER_CALCULATION */
    {
      retVal = 0u;
      break;
    }
    default:   /* COV_PDUR_MISRA */
      break;
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON )
/**********************************************************************************************************************
 * PduR_Bm_AllocateTxBuffer
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
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_AllocateTxBuffer(PduR_BmTxBufferIndRomIterType bmTxBufferRomIndStartId,
                                                            PduR_BmTxBufferIndRomIterType bmTxBufferRomIndEndIdx,
                                                            PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx,
                                                            PduR_BmTxBufferArrayRamLengthOfBmTxBufferRomType pduLength,
                                                            P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr,
                                                            P2VAR(PduR_BmTxBufferRomIdxOfBmTxBufferIndRomType, AUTOMATIC, PDUR_APPL_DATA) allocatedTxBufferIdxPtr, boolean considerSmallerBuffer)
{
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;   /* PRQA S 2981 */ /* MD_MSR_RetVal */
  /* Get the assigned FifoElement */
  PduR_BmTxBufferRomIdxOfBmTxBufferIndRomType lastSuitableBmTxBufferRomIdx = 0u;
  boolean lastSuitableBmTxBufferRomIdxFound = FALSE;
  PduR_BmTxBufferIndRomIterType bmTxBufferRomIndIdx;
  if(PduR_IsDedicatedTxBufferOfFmFifoElementRam(fmFifoElementRamWriteIdx))      /* COV_PDUR_ONLY_SHARED_OR_DEDICATED_BUFFER */
  {
    PduR_BmTxBufferRomIterType txBufferRomIdx = PduR_GetBmTxBufferRomIdxOfFmFifoElementRam(fmFifoElementRamWriteIdx);
    PduR_SetRxLengthOfBmTxBufferRam(txBufferRomIdx, pduLength); /* SBSW_PDUR_CSL03 */
    *allocatedTxBufferIdxPtr = (PduR_BmTxBufferRomIdxOfBmTxBufferIndRomType) txBufferRomIdx;    /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
    *bufferSizePtr = (PduLengthType) PduR_GetBmTxBufferArrayRamLengthOfBmTxBufferRom(txBufferRomIdx);   /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
    retVal = BUFREQ_OK;
  }
  else
  {
# if (PDUR_SPINLOCKRAM == STD_ON)
    PduR_Lock_LockBuffersByTxBufferInd(bmTxBufferRomIndStartId);
# endif
    {
      for(bmTxBufferRomIndIdx = bmTxBufferRomIndStartId; bmTxBufferRomIndIdx < bmTxBufferRomIndEndIdx; bmTxBufferRomIndIdx++)   /* COV_PDUR_ONLY_SHARED_OR_DEDICATED_BUFFER */
      {
        PduR_BmTxBufferRomIdxOfBmTxBufferIndRomType bmTxBufferRomIdx = PduR_GetBmTxBufferRomIdxOfBmTxBufferIndRom(bmTxBufferRomIndIdx);
        /* Buffer available? */
        if((PDUR_BUFFER_IDLE_TPBUFMGRSTATEOFBMTXBUFFERRAM == PduR_GetTpBufMgrStateOfBmTxBufferRam(bmTxBufferRomIdx)))   /* COV_PDUR_ONLY_SHARED_OR_DEDICATED_BUFFER */
        {
          if(PduR_GetBmTxBufferArrayRamLengthOfBmTxBufferRom(bmTxBufferRomIdx) >= pduLength)    /* COV_PDUR_IF_SDU_LENGTH_HANDLING */
          {
            /* Initialize buffer and assign to FifoElement */
            PduR_SetTpBufMgrStateOfBmTxBufferRam(bmTxBufferRomIdx, PDUR_BUFFER_RX_ACTIVE_TPBUFMGRSTATEOFBMTXBUFFERRAM); /* SBSW_PDUR_CSL03 */
            PduR_SetRxLengthOfBmTxBufferRam(bmTxBufferRomIdx, pduLength);       /* SBSW_PDUR_CSL03 */
            *allocatedTxBufferIdxPtr = bmTxBufferRomIdx;        /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
            /* Assign amount of available buffer */
            *bufferSizePtr = (PduLengthType) PduR_GetBmTxBufferArrayRamLengthOfBmTxBufferRom(bmTxBufferRomIdx); /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
            retVal = BUFREQ_OK;
            break;
          }
          else if(considerSmallerBuffer == TRUE)        /* COV_PDUR_MISRA */
          {
            /* This buffer is not large enough to hold the complete message but the buffer is available and could be used in case no other buffer is available. Reason: the buffer is large enough to hold at least one tpChunk. */
            lastSuitableBmTxBufferRomIdx = bmTxBufferRomIdx;
            lastSuitableBmTxBufferRomIdxFound = TRUE;
          }
          else
          {
            /* nothing to be done */
          }
        }
      }
      /* No suitable buffer found which is large enough to store the full TP PDU. Use ring buffer mechanism (routing-on-the-fly) instead. */
      if(retVal != BUFREQ_OK)   /* COV_PDUR_IF_SDU_LENGTH_HANDLING */
      {
        /* The received TP PDU is larger than the largest available TP buffer element. The routing is executed using a ring buffer mechanism (routing on the fly) that allows a smaller receive buffer. */
        if(lastSuitableBmTxBufferRomIdxFound == TRUE)   /* COV_PDUR_IF_SDU_LENGTH_HANDLING */
        {
          /* Routing is possible, but the gateway will use the ring-buffer mechanism to perform routing. Routing must not be 1:N routing. */
          /* Initialize buffer and assign to FifoElement */
          PduR_SetTpBufMgrStateOfBmTxBufferRam(lastSuitableBmTxBufferRomIdx, PDUR_BUFFER_RX_ACTIVE_TPBUFMGRSTATEOFBMTXBUFFERRAM);       /* SBSW_PDUR_CSL03 */
          PduR_SetRxLengthOfBmTxBufferRam(lastSuitableBmTxBufferRomIdx, pduLength);     /* SBSW_PDUR_CSL03 */
          *allocatedTxBufferIdxPtr = lastSuitableBmTxBufferRomIdx;      /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
          /* Assign amount of available buffer */
          *bufferSizePtr = (PduLengthType) PduR_GetBmTxBufferArrayRamLengthOfBmTxBufferRom(lastSuitableBmTxBufferRomIdx);       /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
          retVal = BUFREQ_OK;
        }
        else
        {
          /* Currently no buffer is available that would allow routing of a routing relation with the configured chunk size. 1:N routing relations can only be routed if a buffer of the I-PDU size is available. 1:1 routing relation can be routed principally but not at the current time. Prevented by validation! */
          retVal = BUFREQ_E_NOT_OK;
        }
      }
    }
# if (PDUR_SPINLOCKRAM == STD_ON)
    PduR_Lock_UnlockBuffersByTxBufferInd(bmTxBufferRomIndStartId);
# endif
  }
  return retVal;
}       /* PRQA S 6060, 6080 */ /* MD_MSR_STPAR, MD_MSR_STMIF */
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON )

/**********************************************************************************************************************
 * PduR_Bm_CopyDataAsPtr
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Bm_CopyDataAsPtr(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, PduR_BmTxBufferArrayRamIterType length)    /* COV_PDUR_ONLY_TT_SINGLE_BUFFER */
{
  info->SduDataPtr = PduR_GetAddrBmTxBufferArrayRam(PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx));        /* SBSW_PDUR_STACK_VARIABLE */
  if(length > PduR_Bm_GetLinearDataSizeInstance(bmTxBufferInstanceRomIdx))      /* COV_PDUR_ROBUSTNESS */
  {
    info->SduLength = (PduLengthType) PduR_Bm_GetLinearDataSizeInstance(bmTxBufferInstanceRomIdx);      /* SBSW_PDUR_STACK_VARIABLE */
  }
  else
  {
    info->SduLength = (PduLengthType) length;   /* SBSW_PDUR_STACK_VARIABLE */
  }
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON )

/**********************************************************************************************************************
 * PduR_Bm_GetDataAsPtr
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Bm_GetDataAsPtr(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, PduR_BmTxBufferArrayRamIterType length)     /* COV_PDUR_IF_ONLY */
{
  info->SduDataPtr = PduR_GetAddrBmTxBufferArrayRam(PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx));        /* SBSW_PDUR_STACK_VARIABLE */
  if(length > PduR_Bm_GetLinearDataSizeInstance(bmTxBufferInstanceRomIdx))      /* COV_PDUR_ROBUSTNESS */
  {
    info->SduLength = (PduLengthType) PduR_Bm_GetLinearDataSizeInstance(bmTxBufferInstanceRomIdx);      /* SBSW_PDUR_STACK_VARIABLE */
  }
  else
  {
    info->SduLength = (PduLengthType) length;   /* SBSW_PDUR_STACK_VARIABLE */
  }
  (void) PduR_Bm_GetData(bmTxBufferInstanceRomIdx, info->SduLength, info->SduDataPtr);  /* SBSW_PDUR_STACK_VARIABLE */

}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON )
/**********************************************************************************************************************
 * PduR_Bm_GetTotalDataTranferredLength
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(PduR_BmTxBufferArrayRamLengthOfBmTxBufferRomType, PDUR_CODE) PduR_Bm_GetTotalDataTranferredLength(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx)     /* COV_PDUR_IF_ONLY */
{
  PduR_BmTxBufferRomIterType txBufferElementStateIdx = PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx);
  PDUR_DUMMY_STATEMENT(bmTxBufferInstanceRomIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return PduR_GetRxLengthOfBmTxBufferRam(txBufferElementStateIdx);
}

#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: PduR_Bm.c
 *********************************************************************************************************************/
