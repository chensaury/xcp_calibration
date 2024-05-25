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
 *         File:  PduR_RmTp_TxInst.c
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

#define PDUR_BM_SOURCE
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR.h"
#include "PduR_Bm.h"
#include "PduR_RmTp_TxInst.h"
#include "PduR_Lock.h"
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

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_LoAndUpTransmit
 *********************************************************************************************************************/
/*! \brief      This function triggers the transmission on the destination bus(es). In case of a
 *              1:N routing including a upper layer module StartOfReception/ CopyRxData/
 *              and the Indication API of the upper layer is called.
 *  \details    -
 *  \param[in]  rmGDestRomIdx    Routing Manager GDest Idx.
 *  \return     E_OK             successful transmission.
 *              E_NOT_OK         transmission failing
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_LoAndUpTransmit(PduR_RmGDestRomIterType rmGDestRomIdx);
#endif

#if ((PDUR_UPTPOFMMROM == STD_ON) && (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_UpTransmit
 *********************************************************************************************************************/
/*! \brief      This function triggers the reception in an upper layer module in case of an
 *              1:N routing including an upper layer module StartOfReception/ CopyRxData/
 *              an the Indication API of the upper layer is called.
 *  \details    -
 *  \param[in]  rmGDestRomIdx           Routing Manager GDest Idx.
 *  \trace      SPEC-2020176
 *  \return     BUFREQ_OK               Buffer request was successful.
 *              BUFREQ_E_NOT_OK         Currently no buffer available.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_UpTransmit(PduR_RmGDestRomIterType rmGDestRomIdx);
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_LoTransmit
 *********************************************************************************************************************/
/*! \brief      This function triggers the transmission in an lower layer module.
 *  \details    -
 *  \param[in]  rmGDestRomIdx Routing Manager GDest Idx.
 *  \return     E_OK          Transmission successful.
 *              E_NOT_OK      Transmission not successful.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_LoTransmit(PduR_RmGDestRomIterType rmGDestRomIdx);
#endif

#define PDUR_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#if ((PDUR_UPTPOFMMROM == STD_ON) && (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_UpTransmit
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
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_UpTransmit(PduR_RmGDestRomIterType rmGDestRomIdx)
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  BufReq_ReturnType retValBufReq;
  PduLengthType bufferSizePtr = 0u;
  PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx = PduR_GetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx));
  PduR_FmFifoRomIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx));
  PduR_FmFifoElementRamIterType fmFifoElementRamTPReadIdx = PduR_GetFmFifoElementRamReadIdxOfFmFifoRam(fmFifoRomIdx);
  PduR_RmSrcRomIterType rmSrcIdx = PduR_GetRmSrcRomIdxOfRmDestRom(PduR_GetRmDestRomIdxOfFmFifoElementRam(fmFifoElementRamTPReadIdx));
  /* If MetaData are available the pUpperLayerInfo points to MetaData */
  {
# if (PDUR_METADATA_SUPPORT == STD_ON )
    if(PduR_IsMetaDataLengthUsedOfRmBufferedTpPropertiesRom(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx)))
    {
      PduInfoType metaInfo;
      PduR_Bm_GetDataAsPtr(bmTxBufferInstanceRomIdx, &metaInfo, PduR_GetMetaDataLengthOfRmBufferedTpPropertiesRom(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx)));   /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */

      retValBufReq = PduR_GetUpTpStartOfReceptionFctPtrOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(rmGDestRomIdx)) (PduR_GetDestHndOfRmGDestRom(rmGDestRomIdx), &metaInfo, (PduLengthType) PduR_Bm_GetTotalDataTranferredLength(bmTxBufferInstanceRomIdx), &bufferSizePtr);    /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
    }
    else
# endif
    {
      retValBufReq = PduR_GetUpTpStartOfReceptionFctPtrOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(rmGDestRomIdx)) (PduR_GetDestHndOfRmGDestRom(rmGDestRomIdx), (P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)) NULL_PTR, (PduLengthType) PduR_Bm_GetTotalDataTranferredLength(bmTxBufferInstanceRomIdx), &bufferSizePtr);     /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
    }
  }
  if(retValBufReq == BUFREQ_OK)
  {
    /* RfC 52242 - Transport Protocol Gateway Reception to upper layer modules is not functional */
    /* \trace SPEC-2020098 */
    if(bufferSizePtr < PduR_Bm_GetTotalDataTranferredLength(bmTxBufferInstanceRomIdx))
    {
      PduR_GetUpTpTpRxIndicationFctPtrOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(rmGDestRomIdx)) (PduR_GetDestHndOfRmGDestRom(rmGDestRomIdx), E_NOT_OK);      /* SBSW_PDUR_API_CALL_FORWARDING_ID_ONLY */
    }
    else
    {
      PduInfoType info;

      PduR_Bm_GetDataAsPtr(bmTxBufferInstanceRomIdx, &info, PduR_Bm_GetLinearDataSizeInstance(bmTxBufferInstanceRomIdx));       /* SBSW_PDUR_API_CALL_FORWARDING_ID_ONLY */

      if(BUFREQ_OK == PduR_GetUpTpCopyRxDataFctPtrOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(rmGDestRomIdx)) (PduR_GetDestHndOfRmGDestRom(rmGDestRomIdx), &info, &bufferSizePtr))     /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
      {
        PduR_GetUpTpTpRxIndicationFctPtrOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(rmGDestRomIdx)) (PduR_GetDestHndOfRmGDestRom(rmGDestRomIdx), E_OK);        /* SBSW_PDUR_API_CALL_FORWARDING_ID_ONLY */
        retVal = E_OK;
      }
      else      /* \trace SPEC-2020102 */
      {
        PduR_GetUpTpTpRxIndicationFctPtrOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(rmGDestRomIdx)) (PduR_GetDestHndOfRmGDestRom(rmGDestRomIdx), E_NOT_OK);    /* SBSW_PDUR_API_CALL_FORWARDING_ID_ONLY */
      }
    }
  }
  if(E_OK == retVal)
  {
    PduR_RmTp_TxInst_TxConfirmation(rmGDestRomIdx, E_OK);
  }
  else
  {
    PduR_RmTp_TxInst_TxConfirmation(rmGDestRomIdx, E_NOT_OK);
  }
  PDUR_DUMMY_STATEMENT(rmSrcIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return retVal;
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
  PduR_RmTp_TxInst_LoTransmit
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_LoTransmit(PduR_RmGDestRomIterType rmGDestRomIdx)
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */

  PduInfoType info;
  PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx = PduR_GetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx));
  PduR_FmFifoRomIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx));
  PduR_FmFifoElementRamIterType fmFifoElementRamTPReadIdx = PduR_GetFmFifoElementRamReadIdxOfFmFifoRam(fmFifoRomIdx);
  PduR_RmSrcRomIterType rmSrcIdx = PduR_GetRmSrcRomIdxOfRmDestRom(PduR_GetRmDestRomIdxOfFmFifoElementRam(fmFifoElementRamTPReadIdx));

  /* Get Data Pointer for Transmit */
  PduR_Bm_CopyDataAsPtr(bmTxBufferInstanceRomIdx, &info, PduR_Bm_GetTotalDataTranferredLength(bmTxBufferInstanceRomIdx));       /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
# if (PDUR_METADATA_SUPPORT == STD_ON)
  if(PduR_IsMetaDataLengthUsedOfRmBufferedTpPropertiesRom(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx)))
  {
    /* Get Meta Daten Pointer for Transmit */
    PduR_Bm_GetDataAsPtr(bmTxBufferInstanceRomIdx, &info, (PduR_BmTxBufferArrayRamIterType) PduR_GetMetaDataLengthOfRmBufferedTpPropertiesRom(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx)));       /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
  }
# endif
  /* Correction of the length according to AUTOSAR */
  info.SduLength = (PduLengthType) PduR_Bm_GetTotalDataTranferredLength(bmTxBufferInstanceRomIdx);

  if(E_OK == PduR_GetLoTpTransmitFctPtrOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(rmGDestRomIdx)) (PduR_GetDestHndOfRmGDestRom(rmGDestRomIdx), &info))        /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
  {
    retVal &= E_OK;
  }
  else
  {
    PduR_RmTp_TxInst_TxConfirmation(rmGDestRomIdx, E_NOT_OK);
  }
  PDUR_DUMMY_STATEMENT(rmSrcIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return retVal;
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
  PduR_RmTp_TxInst_LoAndUpTransmit
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *********************************************************************************************************************/

LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_LoAndUpTransmit(PduR_RmGDestRomIterType rmGDestRomIdx)
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  /* Confirmations are decremented in the Context of LoAndUpTransmit and CopyTxData */
  {
    /* Iterate over all routing destinations (1:N) */
    if(PduR_GetDirectionOfRmGDestRom(rmGDestRomIdx) == PDUR_TX_DIRECTIONOFRMGDESTROM)   /* COV_PDUR_FEATURE_ALWAYS_TRUE */
    {
      retVal = PduR_RmTp_TxInst_LoTransmit(rmGDestRomIdx);
    }
# if (PDUR_UPTPOFMMROM == STD_ON)
    else
    {
      retVal = PduR_RmTp_TxInst_UpTransmit(rmGDestRomIdx);
    }
# endif
  }
  return retVal;
}
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_TriggerTransmit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_TriggerTransmit(PduR_RmDestRomIterType rmDestRomIdx, PduR_RmGDestRomIterType rmGDestRomIdx)
{
  /* if any routings is sucessfull return E_OK */
  return (PduR_GetPduR_RmTp_TxInst_TriggerTransmitOfRmTxInstSmRom(PduR_GetTpTxInstSmStateOfRmGDestTpTxStateRam(PduR_GetRmGDestTpTxStateRamIdxOfRmGDestRom(rmGDestRomIdx)))[PduR_GetPduRDestPduProcessingOfRmGDestRom(rmGDestRomIdx)] (rmDestRomIdx, rmGDestRomIdx));    /* SBSW_PDUR_CSL03 */
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_TriggerTransmit_RmTxinstIdle
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
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_TriggerTransmit_RmTxinstIdle(PduR_RmDestRomIterType rmDestRomIdx, PduR_RmGDestRomIterType rmGDestRomIdx)       /* COV_PDUR_CROSSCORE_ROUTINGS_ONLY */
{
  PduR_SetTpTxInstSmStateOfRmGDestTpTxStateRam(PduR_GetRmGDestTpTxStateRamIdxOfRmGDestRom(rmGDestRomIdx), PDUR_RM_TXINST_ACTIVE_TPTXINSTSMSTATEOFRMGDESTTPTXSTATERAM);  /* SBSW_PDUR_CSL03 */
  PDUR_DUMMY_STATEMENT(rmDestRomIdx);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return PduR_RmTp_TxInst_LoAndUpTransmit(rmGDestRomIdx);
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_TriggerTransmit_RmTxinstWaiting
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_TriggerTransmit_RmTxinstWaiting(PduR_RmDestRomIterType rmDestRomIdx, PduR_RmGDestRomIterType rmGDestRomIdx)    /* COV_PDUR_NO_DEFERRED_TP_ROUTING */
{
  Std_ReturnType retVal = E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_SetTpTxInstSmStateOfRmGDestTpTxStateRam(PduR_GetRmGDestTpTxStateRamIdxOfRmGDestRom(rmGDestRomIdx), PDUR_RM_TXINST_WAITING_TPTXINSTSMSTATEOFRMGDESTTPTXSTATERAM); /* SBSW_PDUR_CSL03 */

# if (PDUR_DEFERREDEVENTCACHEROM == STD_ON)
  {
    /* Put destination handle into the deferred event queue */
    PduR_CoreManagerRomIdxOfMmRomType srcCoreIdx = PduR_GetCoreManagerRomIdxOfMmRom(PduR_GetMmRomIdxOfRmSrcRom(PduR_GetRmSrcRomIdxOfRmDestRom(rmDestRomIdx)));
    PduR_CoreManagerRomIdxOfMmRomType destCoreIdx = PduR_GetCoreManagerRomIdxOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(rmGDestRomIdx));

    (void) PduR_EvC_Put(PduR_GetDeferredEventCacheRomIdxOfSrcCoreRom(PduR_GetSrcCoreRomStartIdxOfCoreManagerRom(destCoreIdx) + srcCoreIdx), rmGDestRomIdx);
  }
# endif
  PDUR_DUMMY_STATEMENT(rmDestRomIdx);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return retVal;
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_TriggerTransmit_FatalError
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_TriggerTransmit_FatalError(PduR_RmDestRomIterType rmDestRomIdx, PduR_RmGDestRomIterType rmGDestRomIdx) /* COV_PDUR_FATAL_ERROR */
{
  PduR_Det_ReportError(PDUR_RM_TPTRIGGERTRANSMIT_FATALERROR, PDUR_E_FATAL);
  PDUR_DUMMY_STATEMENT(rmDestRomIdx);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(rmGDestRomIdx);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return E_NOT_OK;
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_CopyTxData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_CopyTxData(PduR_RmGDestRomIterType rmGDestRomIdx, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr)      /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  return (PduR_GetPduR_RmTp_TxInst_CopyTxDataOfRmTxInstSmRom(PduR_GetTpTxInstSmStateOfRmGDestTpTxStateRam(PduR_GetRmGDestTpTxStateRamIdxOfRmGDestRom(rmGDestRomIdx)))[PduR_GetPduRDestPduProcessingOfRmGDestRom(rmGDestRomIdx)] ((PduR_RmGDestRomIterType) rmGDestRomIdx, info->SduLength, info->SduDataPtr, retry, availableDataPtr)); /* SBSW_PDUR_CSL03 */
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_CopyTxData_RmTxinstActive
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
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_CopyTxData_RmTxinstActive(PduR_RmGDestRomIterType rmGDestRomIdx,
                                                                              PduLengthType pduLength,
                                                                              SduDataPtrType sduDataPtr,
                                                                              P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr)
{
  BufReq_ReturnType retVal;     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  /* Get instance specific Tx Buffer element */
  PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx = PduR_GetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx));

  retVal = PduR_Bm_GetData(bmTxBufferInstanceRomIdx, (PduR_BmTxBufferArrayRamIterType) pduLength, sduDataPtr);  /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
  *availableDataPtr = (PduLengthType) PduR_Bm_GetTotalDataSizeInstance(bmTxBufferInstanceRomIdx);       /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */

  PDUR_DUMMY_STATEMENT(retry);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return retVal;
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
 /**********************************************************************************************************************
 * PduR_RmTp_TxInst_CopyTxData_RmTxinstAborted
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_CopyTxData_RmTxinstAborted(PduR_RmGDestRomIterType rmGDestRomIdx, PduLengthType pduLength,
                                                                               SduDataPtrType sduDataPtr,
                                                                               P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC,
                                                                                                                                              PDUR_APPL_DATA) availableDataPtr)
{
  PDUR_DUMMY_STATEMENT(rmGDestRomIdx);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(pduLength);      /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(sduDataPtr);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(retry);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(availableDataPtr);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return BUFREQ_E_NOT_OK;
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_CopyTxData_UnexpectedCall
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_CopyTxData_UnexpectedCall(PduR_RmGDestRomIterType rmGDestRomIdx, PduLengthType pduLength,
                                                                              SduDataPtrType sduDataPtr,
                                                                              P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr)
{
  PduR_Det_ReportError(PDUR_RMTP_TXINSTSM_COPYTXDATA_UNEXPECTEDCALL, PDUR_E_UNEXPECTED_CALL);
  PDUR_DUMMY_STATEMENT(rmGDestRomIdx);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(pduLength);      /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(sduDataPtr);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(retry);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(availableDataPtr);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return BUFREQ_E_NOT_OK;
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_TxConfirmation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_TxInst_TxConfirmation(PduR_RmGDestRomIterType rmGDestRomIdx, Std_ReturnType result)
{
  /* Handle global routing state */
  PduR_GetPduR_RmTp_TxInst_TxConfirmationOfRmTxInstSmRom(PduR_GetTpTxInstSmStateOfRmGDestTpTxStateRam(PduR_GetRmGDestTpTxStateRamIdxOfRmGDestRom(rmGDestRomIdx)))[PduR_GetPduRDestPduProcessingOfRmGDestRom(rmGDestRomIdx)] ((PduR_RmGDestRomIterType) rmGDestRomIdx, result);  /* SBSW_PDUR_CSL03 */
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_TxConfirmation_RmTxinstActiveOrRmTxinstAborted
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_TxInst_TxConfirmation_RmTxinstActiveOrRmTxinstAborted(PduR_RmGDestRomIterType rmGDestRomIdx, Std_ReturnType result)
{
  PduR_FmFifoRomIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx));
  PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx = PduR_GetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx));
  PduR_SetTpTxInstSmStateOfRmGDestTpTxStateRam(PduR_GetRmGDestTpTxStateRamIdxOfRmGDestRom(rmGDestRomIdx), PDUR_RM_TXINST_IDLE_TPTXINSTSMSTATEOFRMGDESTTPTXSTATERAM);    /* SBSW_PDUR_CSL03 */
  PduR_Bm_ResetTxBufferInstance(bmTxBufferInstanceRomIdx);
  PduR_DecPendingConfirmationsOfFmFifoRam(fmFifoRomIdx);        /* SBSW_PDUR_CSL03 */
  PduR_GetFctPtrOfRmTp_FinishTransmission_TpTxSmStateHandler(PduR_GetTpTxSmStateOfFmFifoRam(fmFifoRomIdx)) (rmGDestRomIdx, result);     /* SBSW_PDUR_CSL03 */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_TxConfirmation_UnexpectedCall
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_TxInst_TxConfirmation_UnexpectedCall(PduR_RmGDestRomIterType rmGDestRomIdx, Std_ReturnType result)
{
  PduR_Det_ReportError(PDUR_RMTP_TXINSTSM_TPTXCONFIRMATION_UNEXPECTEDCALL, PDUR_E_UNEXPECTED_CALL);
  PDUR_DUMMY_STATEMENT(rmGDestRomIdx);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_CancelTransmit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_CancelTransmit(PduR_RmDestRomIterType rmGDestRomIdx)   /* COV_PDUR_FATAL_ERROR */
{
  return (PduR_GetPduR_RmTp_TxInst_CancelTransmitOfRmTxInstSmRom(PduR_GetTpTxInstSmStateOfRmGDestTpTxStateRam(PduR_GetRmGDestTpTxStateRamIdxOfRmGDestRom(rmGDestRomIdx)))[PduR_GetPduRDestPduProcessingOfRmGDestRom(rmGDestRomIdx)] (rmGDestRomIdx));   /* SBSW_PDUR_CSL03 */
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_CancelTransmit_FatalError
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_CancelTransmit_FatalError(PduR_RmDestRomIterType rmGDestRomIdx)        /* COV_PDUR_FATAL_ERROR */
{
  PduR_Det_ReportError(PDUR_RMTP_TXINSTSM_TPCANCELTRANSMIT_FATALERROR, PDUR_E_FATAL);
  PDUR_DUMMY_STATEMENT(rmGDestRomIdx);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return E_NOT_OK;
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_CancelTransmit_RmTxinstActive
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_CancelTransmit_RmTxinstActive(PduR_RmDestRomIterType rmGDestRomIdx)
{
  PduR_SetTpTxInstSmStateOfRmGDestTpTxStateRam(PduR_GetRmGDestTpTxStateRamIdxOfRmGDestRom(rmGDestRomIdx), PDUR_RM_TXINST_ABORTED_TPTXINSTSMSTATEOFRMGDESTTPTXSTATERAM); /* SBSW_PDUR_CSL01 */
  return E_OK;
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_CancelTransmit_RmTxinstWaiting
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_CancelTransmit_RmTxinstWaiting(PduR_RmDestRomIterType rmGDestRomIdx)   /* COV_PDUR_NO_DEFERRED_TP_ROUTING */
{
  PduR_FmFifoRomIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx));
  PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx = PduR_GetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx));
  PduR_SetTpTxInstSmStateOfRmGDestTpTxStateRam(PduR_GetRmGDestTpTxStateRamIdxOfRmGDestRom(rmGDestRomIdx), PDUR_RM_TXINST_IDLE_TPTXINSTSMSTATEOFRMGDESTTPTXSTATERAM);    /* SBSW_PDUR_CSL03 */
  PduR_Bm_ResetTxBufferInstance(bmTxBufferInstanceRomIdx);
  PduR_DecPendingConfirmationsOfFmFifoRam(fmFifoRomIdx);        /* SBSW_PDUR_CSL03 */
  PduR_GetFctPtrOfRmTp_FinishTransmission_TpTxSmStateHandler(PduR_GetTpTxSmStateOfFmFifoRam(fmFifoRomIdx)) (rmGDestRomIdx, E_NOT_OK);   /* SBSW_PDUR_CSL03 */
  return E_OK;
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_CancelTransmit_RmTxinstAborted
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_CancelTransmit_RmTxinstAborted(PduR_RmDestRomIterType rmGDestRomIdx)   /* COV_PDUR_DUMMY_FUNCTION */
{
  /* nothing to do */
  PDUR_DUMMY_STATEMENT(rmGDestRomIdx);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return E_OK;
}
#endif

#if((PDUR_MAIN_FUNCTION == STD_ON) && (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_MainFunction
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_TxInst_MainFunction(PduR_RmGDestRomIterType rmGDestRomIdx)
{
  if((PduR_GetPduRDestPduProcessingOfRmGDestRom(rmGDestRomIdx) == PDUR_DEFERRED_PDURDESTPDUPROCESSINGOFRMGDESTROM) && (PDUR_RM_TXINST_WAITING_TPTXINSTSMSTATEOFRMGDESTTPTXSTATERAM == PduR_GetTpTxInstSmStateOfRmGDestTpTxStateRam(PduR_GetRmGDestTpTxStateRamIdxOfRmGDestRom(rmGDestRomIdx)))) /* COV_PDUR_CROSSCORE_ROUTINGS_ONLY */
  {
    PduR_Lock_LockRoutingPathByGDestPdu(rmGDestRomIdx);
    {
      PduR_SetTpTxInstSmStateOfRmGDestTpTxStateRam(PduR_GetRmGDestTpTxStateRamIdxOfRmGDestRom(rmGDestRomIdx), PDUR_RM_TXINST_ACTIVE_TPTXINSTSMSTATEOFRMGDESTTPTXSTATERAM);      /* SBSW_PDUR_CSL03 */
      (void) PduR_RmTp_TxInst_LoAndUpTransmit(rmGDestRomIdx);
    }
    PduR_Lock_UnlockRoutingPathByGDestPdu(rmGDestRomIdx);
  }
}       /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: PduR_RmTp_TxInst.c
 *********************************************************************************************************************/
