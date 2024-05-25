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
 *         File:  PduR_RmTp.c
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

#define PDUR_RMTP_SOURCE
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR.h"
#include "PduR_Bm.h"
#include "PduR_Fm.h"
#include "PduR_Lock.h"
#include "PduR_RmTp.h"
#include "PduR_RmTp_TxInst.h"
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
 * PduR_RmTp_ThresholdReached
 *********************************************************************************************************************/
/*! \brief      This function calculates the fill level and returns true if the configured threshold is reached.
 *  \details    -
 *  \param[in]  rmSrcIdx   Routing Manager Src Index
 *  \return                E_OK:     If threshold is reached.
 *                         E_NOT_OK: If threshold is not reached.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_ThresholdReached(PduR_RmSrcRomIterType rmSrcIdx);
#endif

#if(PDUR_EXISTS_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
   PduR_RmTp_MultipleSourceHandler_Transmit
**********************************************************************************************************************/
/*! \brief       The function is called by the PduR to trigger the transmission on the destination buses in case of a
 *                FanIn Transport Protocol Routing.
 *   \details     The PDU Router evaluates the Gw I-PDU handle and performs appropriate handle and port conversion.
 *                The call is routed to multiple TP module using the appropriate I-PDU handle of the destination layer.
 *   \param[in]   rmDestRomIdx             ID of the transmitted GwTp I-PDU.
 *   \param[in]   info                     the pointer to the data
 *   \pre         -
 *   \context     TASK|ISR1|ISR2
 *   \reentrant   TRUE
 *   \synchronous TRUE
**********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_MultipleSourceHandler_Transmit(PduR_RmDestRomIterType rmDestRomIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
  PduR_RmTp_CopyTxData
**********************************************************************************************************************/
/*! \brief      This function is called by the PduR GwTp to query the transmit data of an I-PDU segment.
 *  \details    Each call to this function copies the next part of the transmit.
 *  \param[in]      rmGDestRomIdx       ID of the GwTp I-PDU that will be transmitted.
 *  \param[in]      info              Pointer to the destination buffer and the number of bytes to copy.
 *                                In case of gateway the PDU Router module will copy otherwise the source upper layer
 *                                module will copy the data. If not enough transmit data is available, no data is copied.
 *
 *                                A copy size of 0 can be used to indicate state changes in the retry parameter.
 *  \param[in]  retry             not supported
 *  \param[out] availableDataPtr  Indicates the remaining number of bytes that are available in the PduR Tx buffer.
 *                                AvailableTxDataCntPtr can be used by TP modules that support dynamic payload lengths
 *                                (e.g. Iso FrTp) to determine the size of the following CFs.
 *  \return     BufReq_ReturnType
 *              BUFREQ_OK         The data has been copied to the transmit buffer successful.
 *              BUFREQ_E_NOT_OK   PduR_Init() has not been called
 *                                or the GwTpTxPduId is not valid
 *                                or the GwTpTxPduId is not forwarded in this identity
 *                                or the info is not valid
 *                                or the request was not accepted by the upper layer and no data has been copied.
 *              BUFREQ_E_BUSY     The request cannot be processed because the TX data is not available
 *                                and no data has been copied. The TP layer might retry later the copy process.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       SPEC-1096, SPEC-2020151
**********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_CopyTxData(PduR_RmGDestRomIdxOfTxTp2SrcType rmGDestRomIdx,
                                                                     P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
                                                                     P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr);
#endif

#if (PDUR_METADATA_SUPPORT == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_StartOfReceptionQueueMetaData
 *********************************************************************************************************************/
/*! \brief         This function writes meta data to the Tp buffer and adjusts the info->SduLength
 *                 if meta data is used.
 *  \details       -
 *  \param[in]     rmSrcIdx         Routing Manager Src Index
 *  \param[in]     pduLength        meta data length. (Meta data length are constant ROM)
 *  \param[in,out] sduDataPtr       Meta Data pointer .
 *  \param[out]    bufferSizePtr    pointer to data structure which will be used to return the size of the Pdu which
                                    can be copied to the buffer.
 *  \return        BUFREQ_OK        Buffer request was successful.
 *                 BUFREQ_E_NOT_OK  Currently no buffer available
 *  \pre           -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_StartOfReceptionQueueMetaData(PduR_RmSrcRomIterType rmSrcIdx,
                                                                                        PduR_BmTxBufferArrayRamIterType pduLength,
                                                                                        SduDataPtrType sduDataPtr, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr);
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_AssignAssociatedBuffer2Destination
 *********************************************************************************************************************/
/*! \brief       Assign the associated buffer to the destinations before the Transmit function is called.
 *  \details     -
 *  \param[in]   bmTxBufferRomIdx      Index of the Tx buffer
 *  \param[in]   rmSrcIdx              Routing Manager Src Index
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmTp_AssignAssociatedBuffer2Destination(PduR_BmTxBufferRomIterType bmTxBufferRomIdx, PduR_RmSrcRomIterType rmSrcIdx);
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TriggerTransmissionOfDestinations
 *********************************************************************************************************************/
/*! \brief       Trigger the transmission on all destinations if they are enabled
 *  \details     -
 *  \param[in]   rmSrcIdx       Routing Manager Src Index
 *  \return      E_OK           Transmission was successful on at least one destination
 *               E_NOT_OK       Transmission was not successful on any destination
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TriggerTransmissionOfDestinations(PduR_RmSrcRomIterType rmSrcIdx);
#endif

#define PDUR_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_Init
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_Init(void)
{
  {
    PduR_RmGDestTpTxStateRamIterType rmGDestTpTxStateRamTpIdx;
    for(rmGDestTpTxStateRamTpIdx = 0u; rmGDestTpTxStateRamTpIdx < PduR_GetSizeOfRmGDestTpTxStateRam(); rmGDestTpTxStateRamTpIdx++)
    {
      PduR_SetTpTxInstSmStateOfRmGDestTpTxStateRam(rmGDestTpTxStateRamTpIdx, PDUR_RM_TXINST_IDLE_TPTXINSTSMSTATEOFRMGDESTTPTXSTATERAM); /* SBSW_PDUR_CSL01 */
    }
  }
  {
    PduR_RmBufferedTpPropertiesRomIterType rmBufferedTpPropertiesRamIdx;
    for(rmBufferedTpPropertiesRamIdx = 0u; rmBufferedTpPropertiesRamIdx < PduR_GetSizeOfRmBufferedTpPropertiesRam(); rmBufferedTpPropertiesRamIdx++)
    {
      PduR_SetTpRxSmStateOfRmBufferedTpPropertiesRam(rmBufferedTpPropertiesRamIdx, PDUR_RM_RX_IDLE_TPRXSMSTATEOFRMBUFFEREDTPPROPERTIESRAM);     /* SBSW_PDUR_CSL01 */
      PduR_SetFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(rmBufferedTpPropertiesRamIdx, PDUR_NO_FMFIFOELEMENTRAMIDXOFRMBUFFEREDTPPROPERTIESRAM);     /* SBSW_PDUR_CSL01 */
    }
  }
}
#endif

#if(PDUR_EXISTS_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_MultipleSourceHandler_Transmit
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
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_MultipleSourceHandler_Transmit(PduR_RmDestRomIterType rmDestRomIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)        /* COV_PDUR_CROSSCORE_ROUTINGS_ONLY */
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_Lock_LockRoutingPathByDestPdu(rmDestRomIdx);
  {
    PduR_RmGDestRomIdxOfRmDestRomType rmGDestRomIdx = PduR_GetRmGDestRomIdxOfRmDestRom(rmDestRomIdx);

# if(PDUR_RMGDESTNTO1INFORAMIDXOFRMGDESTROM == STD_ON)
    if(PduR_IsRmGDestNto1InfoRamUsedOfRmGDestRom(rmGDestRomIdx))
    {
      PduR_RmGDestNto1InfoRamIdxOfRmGDestRomType rmGDestNto1InfoIdx = PduR_GetRmGDestNto1InfoRamIdxOfRmGDestRom(rmGDestRomIdx);

      if(!PduR_IsTransmissionActiveOfRmGDestNto1InfoRam(rmGDestNto1InfoIdx))
      {
        PduR_SetRmDestRomIdxOfRmGDestNto1InfoRam(rmGDestNto1InfoIdx, (PduR_RmDestRomIdxOfRmGDestNto1InfoRamType) rmDestRomIdx); /* SBSW_PDUR_CSL03 */
        PduR_SetTransmissionActiveOfRmGDestNto1InfoRam(rmGDestNto1InfoIdx, TRUE);       /* SBSW_PDUR_CSL03 */

        retVal = PduR_GetLoTpTransmitFctPtrOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(rmGDestRomIdx)) (PduR_GetDestHndOfRmGDestRom(rmGDestRomIdx), info);     /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
        if(retVal != E_OK)
        {
          PduR_Rm_MultipleSourceHandler_Reset(rmGDestRomIdx);
        }
      }
    }
    else
# endif
    {
      retVal = PduR_GetLoTpTransmitFctPtrOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(rmGDestRomIdx)) (PduR_GetDestHndOfRmGDestRom(rmGDestRomIdx), info);       /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
    }
  }
  PduR_Lock_UnlockRoutingPathByDestPdu(rmDestRomIdx);

  return retVal;
}
#endif

#if((PDUR_EXISTS_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON) || (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmTp_MultipleSourceHandler_TpTxConfirmation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_MultipleSourceHandler_TpTxConfirmation(PduR_RmGDestRomIdxOfTxTp2SrcType rmGDestRomIdx, Std_ReturnType result)
{
  PduR_Lock_LockRoutingPathByGDestPdu(rmGDestRomIdx);
  {
    PduR_RmDestRomIterType rmDestRomIdx;

    if(PduR_Rm_GetSrcDestPdu(rmGDestRomIdx, &rmDestRomIdx) == E_OK)     /* SBSW_PDUR_STACK_VARIABLE */ /* COV_PDUR_NO_NTO1_ROUTINGPATHS */
    {
# if(PDUR_RMGDESTNTO1INFORAMIDXOFRMGDESTROM == STD_ON)
      PduR_Rm_MultipleSourceHandler_Reset(rmGDestRomIdx);
# endif

      switch (PduR_GetRoutingTypeOfRmDestRom(rmDestRomIdx))
      {
# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
        case PDUR_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM:
          PduR_RmTp_TxInst_TxConfirmation(rmGDestRomIdx, result);
          break;
# endif
# if (PDUR_EXISTS_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON)
        case PDUR_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM:     /* COV_PDUR_CROSSCORE_ROUTINGS_ONLY */
        {
          PduR_RmSrcRomIdxOfRmDestRomType rmSrcRomIdx = PduR_GetRmSrcRomIdxOfRmDestRom(rmDestRomIdx);
          PduR_GetUpTpTpTxConfirmationFctPtrOfMmRom(PduR_GetMmRomIdxOfRmSrcRom(rmSrcRomIdx)) (PduR_GetSrcHndOfRmSrcRom(rmSrcRomIdx), result);   /* SBSW_PDUR_API_CALL_FORWARDING_ID_ONLY */
        }
          break;
# endif
        default:       /* COV_PDUR_MISRA */
          break;
      }
    }
    else
    {
      PduR_Det_ReportError(PDUR_RMTP_MULTIPLESOURCEHANDLER_TPTXCONFIRMATION, PDUR_E_UNEXPECTED_CALL);
    }
  }
  PduR_Lock_UnlockRoutingPathByGDestPdu(rmGDestRomIdx);
}
#endif

#if((PDUR_EXISTS_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON) || (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmTp_MultipleSourceHandler_CopyTxData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_MultipleSourceHandler_CopyTxData(PduR_RmGDestRomIdxOfTxTp2SrcType rmGDestRomIdx, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
                                                                              P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr)
{
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;   /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_Lock_LockRoutingPathByGDestPdu(rmGDestRomIdx);
  {
    PduR_RmDestRomIterType rmDestRomIdx;

    if(PduR_Rm_GetSrcDestPdu(rmGDestRomIdx, &rmDestRomIdx) == E_OK)     /* SBSW_PDUR_STACK_VARIABLE */ /* COV_PDUR_NO_NTO1_ROUTINGPATHS */
    {
# if (PDUR_RPGROM == STD_ON)
      if((!PduR_IsRmDestRpgRomUsedOfRmDestRom(rmDestRomIdx)) || (0u != PduR_GetEnabledCntOfRmDestRpgRam(PduR_GetRmDestRpgRomIdxOfRmDestRom(rmDestRomIdx))))
# endif
      {
        switch (PduR_GetRoutingTypeOfRmDestRom(rmDestRomIdx))
        {
# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
          case PDUR_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM:
            retVal = PduR_RmTp_CopyTxData(rmGDestRomIdx, info, retry, availableDataPtr);        /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
            break;
# endif
# if (PDUR_EXISTS_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON)
          case PDUR_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM:   /* COV_PDUR_CROSSCORE_ROUTINGS_ONLY */
          {
            PduR_RmSrcRomIdxOfRmDestRomType rmSrcRomIdx = PduR_GetRmSrcRomIdxOfRmDestRom(rmDestRomIdx);
            retVal = PduR_GetUpTpCopyTxDataFctPtrOfMmRom(PduR_GetMmRomIdxOfRmSrcRom(rmSrcRomIdx)) (PduR_GetSrcHndOfRmSrcRom(rmSrcRomIdx), info, retry, availableDataPtr);       /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
          }
            break;
# endif
          default:     /* COV_PDUR_MISRA */
            break;
        }
      }
    }
    else
    {
      PduR_Det_ReportError(PDUR_RMTP_MULTIPLESOURCEHANDLER_COPYTXDATA, PDUR_E_UNEXPECTED_CALL);
    }
  }
  PduR_Lock_UnlockRoutingPathByGDestPdu(rmGDestRomIdx);
  return retVal;
}
#endif

#if((PDUR_TPCANCELTRANSMITSUPPORTEDOFMMROM == STD_ON) && (PDUR_EXISTS_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmTp_MultipleSourceHandler_CancelTransmit
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
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_MultipleSourceHandler_CancelTransmit(PduR_RmDestRomIterType rmDestRomIdx)
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_Lock_LockRoutingPathByDestPdu(rmDestRomIdx);
  {
    PduR_RmGDestRomIdxOfRmDestRomType rmGDestRomIdx = PduR_GetRmGDestRomIdxOfRmDestRom(rmDestRomIdx);

# if(PDUR_RMGDESTNTO1INFORAMIDXOFRMGDESTROM == STD_ON)
    if(PduR_IsRmGDestNto1InfoRamUsedOfRmGDestRom(rmGDestRomIdx))
    {
      PduR_RmGDestNto1InfoRamIdxOfRmGDestRomType rmGDestNto1InfoIdx = PduR_GetRmGDestNto1InfoRamIdxOfRmGDestRom(rmGDestRomIdx);
      PduR_RmDestRomIterType lastTxdRmDestRomIdx;
      Std_ReturnType foundSrcPdu = PduR_Rm_GetSrcDestPdu(rmGDestRomIdx, &lastTxdRmDestRomIdx);  /* SBSW_PDUR_STACK_VARIABLE */

      if(PduR_IsTransmissionActiveOfRmGDestNto1InfoRam(rmGDestNto1InfoIdx) && (foundSrcPdu == E_OK) && (rmDestRomIdx == lastTxdRmDestRomIdx))   /* COV_PDUR_ROBUSTNESS */
      {
        retVal = PduR_GetLoTpCancelTransmitFctPtrOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(rmGDestRomIdx)) (PduR_GetDestHndOfRmGDestRom(rmGDestRomIdx));     /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
      }
      else
      {
        PduR_Det_ReportError(PDUR_RMTP_MULTIPLESOURCEHANDLER_CANCELTRANSMIT, PDUR_E_UNEXPECTED_CALL);
      }
    }
    else
# endif
    {
      retVal = PduR_GetLoTpCancelTransmitFctPtrOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(rmGDestRomIdx)) (PduR_GetDestHndOfRmGDestRom(rmGDestRomIdx));       /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
    }
  }
  PduR_Lock_UnlockRoutingPathByDestPdu(rmDestRomIdx);
  return retVal;
}
#endif

#if(PDUR_EXISTS_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_Transmit_MultiDest
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_Transmit_MultiDest(PduR_RmSrcRomIterType rmSrcIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)      /* COV_PDUR_CROSSCORE_ROUTINGS_ONLY */
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_RmDestRomIterType rmDestIdx;

  for(rmDestIdx = PduR_GetRmDestRomStartIdxOfRmSrcRom(rmSrcIdx); rmDestIdx < PduR_GetRmDestRomEndIdxOfRmSrcRom(rmSrcIdx); rmDestIdx++)
  {
    PduR_RmGDestRomIterType rmGDestRomIdx = PduR_GetRmGDestRomIdxOfRmDestRom(rmDestIdx);
    if(PduR_GetDirectionOfRmGDestRom(rmGDestRomIdx) == PDUR_TX_DIRECTIONOFRMGDESTROM)   /* COV_PDUR_FEATURE_ALWAYS_TRUE */
    {
# if (PDUR_RPGROM == STD_ON)
      if((!PduR_IsRmDestRpgRomUsedOfRmDestRom(rmDestIdx)) || (0u != PduR_GetEnabledCntOfRmDestRpgRam(PduR_GetRmDestRpgRomIdxOfRmDestRom(rmDestIdx))))
# endif
      {
        retVal &= PduR_RmTp_MultipleSourceHandler_Transmit(rmDestIdx, info);    /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
      }
    }
  }

  PDUR_DUMMY_STATEMENT(rmSrcIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return retVal;
}
#endif

/**********************************************************************************************************************
 * PduR_RmTp_Init_DedicatedTxBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
#if (PDUR_DEDICATEDTXBUFFEROFRMBUFFEREDTPPROPERTIESROM == STD_ON)
FUNC(void, PDUR_CODE) PduR_RmTp_Init_DedicatedTxBuffer(void)
{
  PduR_RmSrcRomIterType rmSrcRomIdx;
  for(rmSrcRomIdx = 0; rmSrcRomIdx < PduR_GetSizeOfRmSrcRom(); rmSrcRomIdx++)
  {
    if(PduR_IsRmBufferedTpPropertiesRomUsedOfRmSrcRom(rmSrcRomIdx))
    {
      PduR_RmBufferedTpPropertiesRomIdxOfRmSrcRomType rmBufferedTpPropertiesIdx = PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcRomIdx);

      if(PduR_IsDedicatedTxBufferOfRmBufferedTpPropertiesRom(rmBufferedTpPropertiesIdx))
      {
        /* Allocate FiFo element */
        PduR_FmFifoRomIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfRmBufferedTpPropertiesRom(rmBufferedTpPropertiesIdx);
        PduR_FmFifoElementRamIterType possilbeFmFifoElementRamIdx;
        for(possilbeFmFifoElementRamIdx = PduR_GetFmFifoElementRamStartIdxOfFmFifoRom(fmFifoRomIdx); possilbeFmFifoElementRamIdx < PduR_GetFmFifoElementRamEndIdxOfFmFifoRom(fmFifoRomIdx);
            possilbeFmFifoElementRamIdx++)
        {
          PduR_FmFifoElementRamWriteIdxOfFmFifoRamType fmFifoElementRamIdx = 0u;
          if(PduR_Fm_AssignFifoElement(fmFifoRomIdx, &fmFifoElementRamIdx) == E_OK)     /* SBSW_PDUR_STACK_VARIABLE */ /* COV_PDUR_FATAL_ERROR */
          {
            PduLengthType bufferSizePtr = 0u;
            PduR_BmTxBufferRomIdxOfBmTxBufferIndRomType allocatedTxBufferIdxPtr = 0u;
            /* Mapping Src Handle and current Fifo element */
            PduR_SetFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(rmBufferedTpPropertiesIdx, fmFifoElementRamIdx);     /* SBSW_PDUR_CSL03 */

            /* Split Allocate and Assign buffer */
            if(PduR_Bm_AllocateTxBuffer(PduR_GetBmTxBufferIndRomStartIdxOfRmBufferedTpPropertiesRom(rmBufferedTpPropertiesIdx), PduR_GetBmTxBufferIndRomEndIdxOfRmBufferedTpPropertiesRom(rmBufferedTpPropertiesIdx), fmFifoElementRamIdx, 0, &bufferSizePtr, &allocatedTxBufferIdxPtr, TRUE) == BUFREQ_OK)     /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */ /* COV_PDUR_FATAL_ERROR */
            {
              PduR_Fm_AssignTxBuffer2FifoElement(fmFifoElementRamIdx, allocatedTxBufferIdxPtr);
              PduR_SetStateOfFmFifoElementRam(fmFifoElementRamIdx, PDUR_FM_ALLOCATED_WITH_BUFFER_STATEOFFMFIFOELEMENTRAM);      /* SBSW_PDUR_CSL01 */
              PduR_SetDedicatedTxBufferOfFmFifoElementRam(fmFifoElementRamIdx, TRUE);   /* SBSW_PDUR_CSL01 */
            }
            else
            {
              PduR_Det_ReportError(PDUR_RMTP_INIT_DEDICATEDTXBUFFER, PDUR_E_FATAL);
            }
          }
          else
          {
            PduR_Det_ReportError(PDUR_RMTP_INIT_DEDICATEDTXBUFFER, PDUR_E_FATAL);
          }
        }
      }
    }
  }
}       /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#if (PDUR_HASTPTXBUFFEREDFORWARDINGOFGENERALPROPERTIESROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_UpStartOfReception
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_UpStartOfReception(PduR_RmSrcRomIterType rmSrcIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  Std_ReturnType retval = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduLengthType bufferSizePtr = 0u;
  PduLengthType availableDataPtr = 0u;
  PduR_Lock_LockRoutingPathBySrcPdu(rmSrcIdx);
  {
    PduInfoType tempInfo;
    tempInfo.SduLength = info->SduLength;
    tempInfo.SduDataPtr = info->SduDataPtr;
    /* Handle src instance routing state */
    if(BUFREQ_OK == PduR_RmTp_StartOfReception(rmSrcIdx, &tempInfo, tempInfo.SduLength, &bufferSizePtr))        /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
    {
      if(tempInfo.SduLength <= bufferSizePtr)
      {
        PduInfoType copyInfo;
        PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx = PduR_GetFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx));
        PduR_BmTxBufferRomIterType txBufferElementIdx = PduR_GetBmTxBufferRomIdxOfFmFifoElementRam(fmFifoElementRamWriteIdx);

        if(BUFREQ_OK == PduR_Bm_PutDataAsPtr(txBufferElementIdx, &copyInfo))    /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */ /* COV_PDUR_FATAL_ERROR */
        {
          copyInfo.SduLength = info->SduLength; /* pointer shall request the transmitted length, not the available length in the buffer */
          if(BUFREQ_OK == PduR_GetUpTpCopyTxDataFctPtrOfMmRom(PduR_GetMmRomIdxOfRmSrcRom(rmSrcIdx)) (PduR_GetSrcHndOfRmSrcRom(rmSrcIdx), &copyInfo, (P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA)) NULL_PTR, &availableDataPtr))     /* SBSW_PDUR_API_CALL_FORWARDING_ID_ONLY */
          {
            if(availableDataPtr == 0u)
            {
              PduR_RmTp_TpRxIndication((PduR_RmSrcRomIdxOfRxTp2DestType) rmSrcIdx, E_OK);
              PduR_GetUpTpTpTxConfirmationFctPtrOfMmRom(PduR_GetMmRomIdxOfRmSrcRom(rmSrcIdx)) (PduR_GetSrcHndOfRmSrcRom(rmSrcIdx), E_OK);       /* SBSW_PDUR_API_CALL_FORWARDING_ID_ONLY */
              retval = E_OK;
            }
            else
            {
              PduR_RmTp_TpRxIndication((PduR_RmSrcRomIdxOfRxTp2DestType) rmSrcIdx, E_NOT_OK);
              PduR_GetUpTpTpTxConfirmationFctPtrOfMmRom(PduR_GetMmRomIdxOfRmSrcRom(rmSrcIdx)) (PduR_GetSrcHndOfRmSrcRom(rmSrcIdx), E_NOT_OK);   /* SBSW_PDUR_API_CALL_FORWARDING_ID_ONLY */
            }
          }
          else
          {
            PduR_RmTp_TpRxIndication((PduR_RmSrcRomIdxOfRxTp2DestType) rmSrcIdx, E_NOT_OK);
            PduR_GetUpTpTpTxConfirmationFctPtrOfMmRom(PduR_GetMmRomIdxOfRmSrcRom(rmSrcIdx)) (PduR_GetSrcHndOfRmSrcRom(rmSrcIdx), E_NOT_OK);     /* SBSW_PDUR_API_CALL_FORWARDING_ID_ONLY */
          }
        }
        else
        {
          PduR_RmTp_TpRxIndication((PduR_RmSrcRomIdxOfRxTp2DestType) rmSrcIdx, E_NOT_OK);
          PduR_GetUpTpTpTxConfirmationFctPtrOfMmRom(PduR_GetMmRomIdxOfRmSrcRom(rmSrcIdx)) (PduR_GetSrcHndOfRmSrcRom(rmSrcIdx), E_NOT_OK);       /* SBSW_PDUR_API_CALL_FORWARDING_ID_ONLY */
        }
      }
      else
      {
        PduR_GetUpTpTpTxConfirmationFctPtrOfMmRom(PduR_GetMmRomIdxOfRmSrcRom(rmSrcIdx)) (PduR_GetSrcHndOfRmSrcRom(rmSrcIdx), E_NOT_OK); /* SBSW_PDUR_API_CALL_FORWARDING_ID_ONLY */
      }
    }
    else
    {
      PduR_GetUpTpTpTxConfirmationFctPtrOfMmRom(PduR_GetMmRomIdxOfRmSrcRom(rmSrcIdx)) (PduR_GetSrcHndOfRmSrcRom(rmSrcIdx), E_NOT_OK);   /* SBSW_PDUR_API_CALL_FORWARDING_ID_ONLY */
    }
  }
  PduR_Lock_UnlockRoutingPathBySrcPdu(rmSrcIdx);
  PDUR_DUMMY_STATEMENT(availableDataPtr);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return retval;
}       /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_StartOfReception
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_StartOfReception(PduR_RmSrcRomIterType rmSrcIdx, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,       /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
                                                              PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;   /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */

# if (PDUR_DEV_ERROR_DETECT == STD_ON)  /* COV_PDUR_VAR_DEV_ERROR_DETECT */
  /* Check parameter bufferSizePtr */
  if(bufferSizePtr == NULL_PTR)
  {
    errorId = PDUR_E_PARAM_POINTER;
  }
#  if (PDUR_METADATA_SUPPORT == STD_ON)
  else if((PduR_IsMetaDataLengthUsedOfRmBufferedTpPropertiesRom(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx))) && ((info == NULL_PTR) || (info->SduDataPtr == NULL_PTR) || (info->SduLength < (PduLengthType) PduR_GetMetaDataLengthOfRmBufferedTpPropertiesRom(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx)))))        /* COV_PDUR_FEATURE_ALWAYS_TRUE */
  {
    errorId = PDUR_E_PARAM_POINTER;
  }
#  endif
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    PduR_Lock_LockRoutingPathBySrcPdu(rmSrcIdx);
    {
      /* Handle src instance routing state */
      retVal = PduR_GetFctPtrOfRmTp_StartOfReception_TpRxSmStateHandler(PduR_GetTpRxSmStateOfRmBufferedTpPropertiesRam(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx))) (rmSrcIdx, info, TpSduLength, bufferSizePtr); /* SBSW_PDUR_CSL03 */
    }
    PduR_Lock_UnlockRoutingPathBySrcPdu(rmSrcIdx);
  }
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_RMTP_SORX, errorId);
  }
# else
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif
  return retVal;
}
#endif

#if (PDUR_METADATA_SUPPORT == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_StartOfReceptionQueueMetaData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_StartOfReceptionQueueMetaData(PduR_RmSrcRomIterType rmSrcIdx,
                                                                                        PduR_BmTxBufferArrayRamIterType pduLength,
                                                                                        SduDataPtrType sduDataPtr, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr)
{
  PduR_BmTxBufferArrayRamIterType pduLengthIntern = pduLength;
  BufReq_ReturnType retVal;
  PduR_BmTxBufferArrayRamIterType metadataStartPosition =
    pduLengthIntern - (PduR_BmTxBufferArrayRamIterType) PduR_GetMetaDataLengthOfRmBufferedTpPropertiesRom(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx));
  PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx = PduR_GetFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx));
  PduR_BmTxBufferRomIterType bmTxBufferRomIdx = PduR_GetBmTxBufferRomIdxOfFmFifoElementRam(fmFifoElementRamWriteIdx);
  /* Metadata is appended after the payload data */
  /* Length information is used to enqueue the MetaData */
  pduLengthIntern = (PduR_BmTxBufferArrayRamIterType) PduR_GetMetaDataLengthOfRmBufferedTpPropertiesRom(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx));
  /* enqueue data will never fail in this context because the buffer is always empty */
  retVal = PduR_Bm_PutData((PduR_BmTxBufferRomIterType) bmTxBufferRomIdx, pduLengthIntern, &sduDataPtr[metadataStartPosition]); /* SBSW_PDUR_STACK_VARIABLE */
  *bufferSizePtr = (PduLengthType) PduR_Bm_GetTotalBufferSize(bmTxBufferRomIdx);        /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
  return retVal;
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_CopyRxData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_CopyRxData(PduR_RmSrcRomIdxOfRxTp2DestType rmSrcIdx, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
                                                        P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr)
{
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;   /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
# if (PDUR_DEV_ERROR_DETECT == STD_ON)  /* COV_PDUR_VAR_DEV_ERROR_DETECT */

  /* Check parameter 'info' */
  if(info == NULL_PTR)
  {
    errorId = PDUR_E_PARAM_POINTER;
  }
  else if((info->SduLength > 0u) && (info->SduDataPtr == NULL_PTR))
  {
    errorId = PDUR_E_PARAM_POINTER;
  }
  else if(bufferSizePtr == NULL_PTR)
  {
    errorId = PDUR_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    PduR_Lock_LockRoutingPathBySrcPdu(rmSrcIdx);
    {
      /* Handle src instance routing state */
      retVal = PduR_GetFctPtrOfRmTp_CopyRxData_TpRxSmStateHandler(PduR_GetTpRxSmStateOfRmBufferedTpPropertiesRam(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx))) ((PduR_RmSrcRomIterType) rmSrcIdx, info->SduLength, info->SduDataPtr, bufferSizePtr);       /* SBSW_PDUR_CSL03 */
    }
    PduR_Lock_UnlockRoutingPathBySrcPdu(rmSrcIdx);
  }
  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_RMTP_CPYRX, errorId);
  }
# else
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif
  return retVal;
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_AssignAssociatedBuffer2Destination
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmTp_AssignAssociatedBuffer2Destination(PduR_BmTxBufferRomIterType bmTxBufferRomIdx, PduR_RmSrcRomIterType rmSrcIdx)
{
  PduR_RmDestRomStartIdxOfRmSrcRomType rmDestRomIdx;
  PduR_BmTxBufferInstanceRomStartIdxOfBmTxBufferRomType bmTxBufferInstanceRomIdx = PduR_GetBmTxBufferInstanceRomStartIdxOfBmTxBufferRom(bmTxBufferRomIdx);
  for(rmDestRomIdx = PduR_GetRmDestRomStartIdxOfRmSrcRom(rmSrcIdx); rmDestRomIdx < PduR_GetRmDestRomEndIdxOfRmSrcRom(rmSrcIdx); rmDestRomIdx++)
  {
    PduR_RmGDestRomIdxOfRmDestRomType rmGDestRomIdx = PduR_GetRmGDestRomIdxOfRmDestRom(rmDestRomIdx);

    PduR_Bm_AssignAssociatedBuffer2DestinationInstance(bmTxBufferRomIdx, bmTxBufferInstanceRomIdx);
    PduR_SetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx), bmTxBufferInstanceRomIdx);     /* SBSW_PDUR_CSL03 */
    bmTxBufferInstanceRomIdx++;
  }
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TpRxIndication
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_TpRxIndication(PduR_RmSrcRomIdxOfRxTp2DestType rmSrcIdx, Std_ReturnType result)
{
  /* ----- Implementation ----------------------------------------------- */
  PduR_Lock_LockRoutingPathBySrcPdu(rmSrcIdx);
  {
    /* Handle src instance routing state */
    PduR_GetFctPtrOfRmTp_TpRxIndication_TpRxSmStateHandler(PduR_GetTpRxSmStateOfRmBufferedTpPropertiesRam(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx))) ((PduR_RmSrcRomIterType) rmSrcIdx, result);        /* SBSW_PDUR_CSL03 */
  }
  PduR_Lock_UnlockRoutingPathBySrcPdu(rmSrcIdx);
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_CopyTxData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_CopyTxData(PduR_RmGDestRomIdxOfTxTp2SrcType rmGDestRomIdx,
                                                                     P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
                                                                     P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr)
{
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;   /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
# if (PDUR_DEV_ERROR_DETECT == STD_ON)  /* COV_PDUR_VAR_DEV_ERROR_DETECT */
  /* parameter 'Handle Id' already checked by the caller API */
  /* Check parameter 'info' */
  if(info == NULL_PTR)
  {
    errorId = PDUR_E_PARAM_POINTER;
  }
  else if((info->SduLength > 0u) && (info->SduDataPtr == NULL_PTR))
  {
    errorId = PDUR_E_PARAM_POINTER;
  }
  else if(availableDataPtr == NULL_PTR)
  {
    errorId = PDUR_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    PduR_Lock_LockRoutingPathByGDestPdu(rmGDestRomIdx);
    {
      /* Handle global routing state */
      retVal = PduR_RmTp_TxInst_CopyTxData(rmGDestRomIdx, info, retry, availableDataPtr);       /* SBSW_PDUR_CSL03 */
    }
    PduR_Lock_UnlockRoutingPathByGDestPdu(rmGDestRomIdx);
    PDUR_DUMMY_STATEMENT(retry);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_RMTP_CPYTX, errorId);
  }
# else
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif
  return retVal;
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_ThresholdReached
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_ThresholdReached(PduR_RmSrcRomIterType rmSrcIdx)
{
  /* Trigger transmission if required */
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx = PduR_GetFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx));
  PduR_BmTxBufferArrayRamIterType availableTotalDataSize = PduR_Bm_GetLinearDataSize(PduR_GetBmTxBufferRomIdxOfFmFifoElementRam(fmFifoElementRamWriteIdx));
  /* MetaData length are not take into account to calculate the Threshold */
# if (PDUR_METADATA_SUPPORT == STD_ON )
  if(PduR_IsMetaDataLengthUsedOfRmBufferedTpPropertiesRom(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx)))    /* COV_PDUR_FEATURE_ALWAYS_TRUE */
  {
    availableTotalDataSize -= (PduR_BmTxBufferArrayRamIterType) PduR_GetMetaDataLengthOfRmBufferedTpPropertiesRom(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx));
  }
# endif
  /* Threshold reached or reception finished (sub state machine is in IDLE) */
  if(availableTotalDataSize >= PduR_GetTpThresholdOfRmBufferedTpPropertiesRom(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx)))
  {
    retVal = E_OK;
  }
  return retVal;
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TriggerTransmissionOfDestinations
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
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TriggerTransmissionOfDestinations(PduR_RmSrcRomIterType rmSrcIdx)
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_RmDestRomIterType rmDestRomIdx;

  for(rmDestRomIdx = PduR_GetRmDestRomStartIdxOfRmSrcRom(rmSrcIdx); rmDestRomIdx < PduR_GetRmDestRomEndIdxOfRmSrcRom(rmSrcIdx); rmDestRomIdx++)
  {
# if (PDUR_RPGROM == STD_ON)
    if((PduR_IsRmDestRpgRomUsedOfRmDestRom(rmDestRomIdx)) && (0u == PduR_GetEnabledCntOfRmDestRpgRam(PduR_GetRmDestRpgRomIdxOfRmDestRom(rmDestRomIdx))))
    {
      PduR_RmGDestRomIterType rmGDestRomIdx = PduR_GetRmGDestRomIdxOfRmDestRom(rmDestRomIdx);
      PduR_FmFifoRomIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx));
      PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx = PduR_GetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx));
      PduR_SetTpTxInstSmStateOfRmGDestTpTxStateRam(PduR_GetRmGDestTpTxStateRamIdxOfRmGDestRom(rmGDestRomIdx), PDUR_RM_TXINST_IDLE_TPTXINSTSMSTATEOFRMGDESTTPTXSTATERAM);        /* SBSW_PDUR_CSL03 */
      PduR_Bm_ResetTxBufferInstance(bmTxBufferInstanceRomIdx);
      PduR_DecPendingConfirmationsOfFmFifoRam(fmFifoRomIdx);    /* SBSW_PDUR_CSL03 */
      PduR_GetFctPtrOfRmTp_FinishTransmission_TpTxSmStateHandler(PduR_GetTpTxSmStateOfFmFifoRam(fmFifoRomIdx)) (rmGDestRomIdx, E_NOT_OK);       /* SBSW_PDUR_CSL03 */
      retVal &= E_NOT_OK;
    }
    else
# endif
    {
      PduR_RmGDestRomIterType rmGDestRomIdx = PduR_GetRmGDestRomIdxOfRmDestRom(rmDestRomIdx);
# if(PDUR_RMGDESTNTO1INFORAMIDXOFRMGDESTROM == STD_ON)
      if(PduR_IsRmGDestNto1InfoRamUsedOfRmGDestRom(rmGDestRomIdx))
      {
        PduR_RmGDestNto1InfoRamIdxOfRmGDestRomType rmGDestNto1InfoIdx = PduR_GetRmGDestNto1InfoRamIdxOfRmGDestRom(rmGDestRomIdx);

        if(!PduR_IsTransmissionActiveOfRmGDestNto1InfoRam(rmGDestNto1InfoIdx))  /* COV_PDUR_CROSSCORE_ROUTINGS_ONLY */
        {
          PduR_SetRmDestRomIdxOfRmGDestNto1InfoRam(rmGDestNto1InfoIdx, (PduR_RmDestRomIdxOfRmGDestNto1InfoRamType) rmDestRomIdx);       /* SBSW_PDUR_CSL03 */
          PduR_SetTransmissionActiveOfRmGDestNto1InfoRam(rmGDestNto1InfoIdx, TRUE);     /* SBSW_PDUR_CSL03 */

          retVal &= PduR_RmTp_TxInst_TriggerTransmit(rmDestRomIdx, rmGDestRomIdx);
          if(E_OK != retVal)    /* COV_PDUR_CROSSCORE_ROUTINGS_ONLY */
          {
            PduR_Rm_MultipleSourceHandler_Reset(rmGDestRomIdx);
          }
        }
      }
      else
# endif
      {
        retVal &= PduR_RmTp_TxInst_TriggerTransmit(rmDestRomIdx, rmGDestRomIdx);
      }
    }
  }
  return retVal;
}       /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_CheckReady2Transmit_TpTxSmStateHandler_RM_TX_IDLE
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
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_CheckReady2Transmit_TpTxSmStateHandler_RM_TX_IDLE(PduR_RmSrcRomIterType rmSrcIdx)
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_FmFifoRamIterType fmFifoRamIdx = PduR_GetFmFifoRomIdxOfRmBufferedTpPropertiesRom(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx));
  PduR_FmFifoElementRamIterType fmFifoElementRamReadIdx = PduR_GetFmFifoElementRamReadIdxOfFmFifoRam(fmFifoRamIdx);

  if(PduR_RmTp_ThresholdReached(rmSrcIdx) == E_OK)
  {
    PduR_SetTpTxSmStateOfFmFifoRam(fmFifoRamIdx, PDUR_RM_TX_RECEPTION_TRANSMISSION_ACTIVE_TPTXSMSTATEOFFMFIFORAM);      /* SBSW_PDUR_CSL03 */
    PduR_SetPendingConfirmationsOfFmFifoRam(fmFifoRamIdx, PduR_GetRmDestRomLengthOfRmSrcRom(rmSrcIdx)); /* SBSW_PDUR_CSL03 */
    /* Assign Tx Buffer */
    PduR_RmTp_AssignAssociatedBuffer2Destination(PduR_GetBmTxBufferRomIdxOfFmFifoElementRam(fmFifoElementRamReadIdx), rmSrcIdx);
    PduR_GetFctPtrOfFm_ActivateRead_FmSmStateHandler(PduR_GetStateOfFmFifoElementRam(fmFifoElementRamReadIdx)) (fmFifoElementRamReadIdx);       /* SBSW_PDUR_CSL03 */

    retVal = PduR_RmTp_TriggerTransmissionOfDestinations(rmSrcIdx);
    if(retVal != E_OK)
    {
      PduR_SetTpTxSmStateOfFmFifoRam(fmFifoRamIdx, PDUR_RM_TX_RECEPTION_ACTIVE_TPTXSMSTATEOFFMFIFORAM); /* SBSW_PDUR_CSL03 */
    }
  }
  else
  {
    retVal = E_OK;
    PduR_SetTpTxSmStateOfFmFifoRam(fmFifoRamIdx, PDUR_RM_TX_RECEPTION_ACTIVE_TPTXSMSTATEOFFMFIFORAM);   /* SBSW_PDUR_CSL03 */
  }
  return retVal;
}       /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_CheckReady2Transmit_TpTxSmStateHandler_RM_TX_RECEPTION_ACTIVE
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
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_CheckReady2Transmit_TpTxSmStateHandler_RM_TX_RECEPTION_ACTIVE(PduR_RmSrcRomIterType rmSrcIdx)
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_FmFifoRamIterType fmFifoRamIdx = PduR_GetFmFifoRomIdxOfRmBufferedTpPropertiesRom(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx));
  PduR_FmFifoElementRamIterType fmFifoElementRamReadIdx = PduR_GetFmFifoElementRamReadIdxOfFmFifoRam(fmFifoRamIdx);
  PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx = PduR_GetFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx));

  if(fmFifoElementRamWriteIdx == fmFifoElementRamReadIdx)       /* COV_PDUR_NO_NTO1_ROUTINGPATHS */
  {
    if(PduR_RmTp_ThresholdReached(rmSrcIdx) == E_OK)
    {
      PduR_SetTpTxSmStateOfFmFifoRam(fmFifoRamIdx, PDUR_RM_TX_RECEPTION_TRANSMISSION_ACTIVE_TPTXSMSTATEOFFMFIFORAM);    /* SBSW_PDUR_CSL03 */
      PduR_SetPendingConfirmationsOfFmFifoRam(fmFifoRamIdx, PduR_GetRmDestRomLengthOfRmSrcRom(rmSrcIdx));       /* SBSW_PDUR_CSL03 */
      /* Assign Tx Buffer */
      PduR_RmTp_AssignAssociatedBuffer2Destination(PduR_GetBmTxBufferRomIdxOfFmFifoElementRam(fmFifoElementRamReadIdx), rmSrcIdx);
      PduR_GetFctPtrOfFm_ActivateRead_FmSmStateHandler(PduR_GetStateOfFmFifoElementRam(fmFifoElementRamReadIdx)) (fmFifoElementRamReadIdx);     /* SBSW_PDUR_CSL03 */

      retVal = PduR_RmTp_TriggerTransmissionOfDestinations(rmSrcIdx);
      if(retVal != E_OK)
      {
        PduR_SetTpTxSmStateOfFmFifoRam(fmFifoRamIdx, PDUR_RM_TX_RECEPTION_ACTIVE_TPTXSMSTATEOFFMFIFORAM);       /* SBSW_PDUR_CSL03 */
      }
    }
    else
    {
      retVal = E_OK;
    }
  }
  else
  {
    retVal = E_OK;
  }
  return retVal;
}       /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_CheckReady2Transmit_TpTxSmStateHandler_NoAction
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_CheckReady2Transmit_TpTxSmStateHandler_NoAction(PduR_RmSrcRomIterType rmSrcIdx)
{
  PDUR_DUMMY_STATEMENT(rmSrcIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return E_OK;
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_FinishReception_TpTxSmStateHandler_RM_TX_IDLE
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_FinishReception_TpTxSmStateHandler_RM_TX_IDLE(PduR_RmSrcRomIterType rmSrcIdx, Std_ReturnType result)
{
  PduR_FmFifoRamIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfRmBufferedTpPropertiesRom(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx));
  PduR_FmFifoElementRamIterType fmFifoElementRamReadIdx = PduR_GetFmFifoElementRamReadIdxOfFmFifoRam(fmFifoRomIdx);

  if(result == E_OK)    /* COV_PDUR_FATAL_ERROR */
  {
    PduR_SetTpTxSmStateOfFmFifoRam(fmFifoRomIdx, PDUR_RM_TX_RECEPTION_FINISHED_TRANSMISSION_ACTIVE_TPTXSMSTATEOFFMFIFORAM);     /* SBSW_PDUR_CSL01 */
    PduR_SetPendingConfirmationsOfFmFifoRam(fmFifoRomIdx, PduR_GetRmDestRomLengthOfRmSrcRom(rmSrcIdx)); /* SBSW_PDUR_CSL03 */
    /* Assign Tx Buffer */
    PduR_RmTp_AssignAssociatedBuffer2Destination(PduR_GetBmTxBufferRomIdxOfFmFifoElementRam(fmFifoElementRamReadIdx), rmSrcIdx);
    PduR_GetFctPtrOfFm_ActivateRead_FmSmStateHandler(PduR_GetStateOfFmFifoElementRam(fmFifoElementRamReadIdx)) (fmFifoElementRamReadIdx);       /* SBSW_PDUR_CSL03 */

    if(PduR_RmTp_TriggerTransmissionOfDestinations(rmSrcIdx) != E_OK)   /* COV_PDUR_CROSSCORE_ROUTINGS_ONLY */
    {
      PduR_SetTpTxSmStateOfFmFifoRam(fmFifoRomIdx, PDUR_RM_TX_IDLE_TPTXSMSTATEOFFMFIFORAM);     /* SBSW_PDUR_CSL01 */
    }
  }
  else
  {
    PduR_Det_ReportError(PDUR_FINISHRECEPTION, PDUR_E_FATAL);
  }
}       /* PRQA S 6080 */ /* MD_MSR_STMIF */

#endif
#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM  == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_FinishReception_TpTxSmStateHandler_RM_TX_RECEPTION_ACTIVE
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
FUNC(void, PDUR_CODE) PduR_RmTp_FinishReception_TpTxSmStateHandler_RM_TX_RECEPTION_ACTIVE(PduR_RmSrcRomIterType rmSrcIdx, Std_ReturnType result)
{
  PduR_FmFifoRamIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfRmBufferedTpPropertiesRom(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx));
  PduR_FmFifoElementRamIterType fmFifoElementRamReadIdx = PduR_GetFmFifoElementRamReadIdxOfFmFifoRam(fmFifoRomIdx);
  PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx = PduR_GetFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx));

  if(fmFifoElementRamWriteIdx == fmFifoElementRamReadIdx)       /* COV_PDUR_NO_NTO1_ROUTINGPATHS */
  {
    if(result == E_OK)
    {
      PduR_SetTpTxSmStateOfFmFifoRam(fmFifoRomIdx, PDUR_RM_TX_RECEPTION_FINISHED_TRANSMISSION_ACTIVE_TPTXSMSTATEOFFMFIFORAM);   /* SBSW_PDUR_CSL01 */
      PduR_SetPendingConfirmationsOfFmFifoRam(fmFifoRomIdx, PduR_GetRmDestRomLengthOfRmSrcRom(rmSrcIdx));       /* SBSW_PDUR_CSL03 */
      /* Assign Tx Buffer */
      PduR_RmTp_AssignAssociatedBuffer2Destination(PduR_GetBmTxBufferRomIdxOfFmFifoElementRam(fmFifoElementRamReadIdx), rmSrcIdx);
      PduR_GetFctPtrOfFm_ActivateRead_FmSmStateHandler(PduR_GetStateOfFmFifoElementRam(fmFifoElementRamReadIdx)) (fmFifoElementRamReadIdx);     /* SBSW_PDUR_CSL03 */

      if(PduR_RmTp_TriggerTransmissionOfDestinations(rmSrcIdx) != E_OK)
      {
        PduR_GetFctPtrOfFm_FinishWrite_FmSmStateHandler(PduR_GetStateOfFmFifoElementRam(fmFifoElementRamWriteIdx)) (fmFifoElementRamWriteIdx, result);        /* SBSW_PDUR_CSL03 */
        PduR_SetRmDestRomIdxOfFmFifoElementRam((fmFifoElementRamWriteIdx), PDUR_NO_RMDESTROMIDXOFFMFIFOELEMENTRAM);     /* SBSW_PDUR_CSL03 */
        PduR_Fm_ActivateNext(fmFifoRomIdx);
      }
    }
    else
    {
      PduR_GetFctPtrOfFm_FinishWrite_FmSmStateHandler(PduR_GetStateOfFmFifoElementRam(fmFifoElementRamWriteIdx)) (fmFifoElementRamWriteIdx, result);    /* SBSW_PDUR_CSL03 */
      PduR_SetFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx), PDUR_NO_FMFIFOELEMENTRAMIDXOFRMBUFFEREDTPPROPERTIESRAM); /* SBSW_PDUR_CSL03 */
      PduR_SetTpTxSmStateOfFmFifoRam(fmFifoRomIdx, PDUR_RM_TX_IDLE_TPTXSMSTATEOFFMFIFORAM);     /* SBSW_PDUR_CSL01 */
      PduR_SetRmDestRomIdxOfFmFifoElementRam((fmFifoElementRamWriteIdx), PDUR_NO_RMDESTROMIDXOFFMFIFOELEMENTRAM);       /* SBSW_PDUR_CSL03 */
      PduR_Fm_ActivateNext(fmFifoRomIdx);
    }
  }
}       /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_FinishReception_TpTxSmStateHandler_RM_TX_RECEPTION_TRANSMISSION_ACTIVE
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_FinishReception_TpTxSmStateHandler_RM_TX_RECEPTION_TRANSMISSION_ACTIVE(PduR_RmSrcRomIterType rmSrcIdx, Std_ReturnType result)
{
  PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx = PduR_GetFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx));
  PduR_FmFifoRamIterType fmFifoRamIdx = PduR_GetFmFifoRomIdxOfRmBufferedTpPropertiesRom(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx));
  PduR_SetTpTxSmStateOfFmFifoRam(fmFifoRamIdx, PDUR_RM_TX_RECEPTION_FINISHED_TRANSMISSION_ACTIVE_TPTXSMSTATEOFFMFIFORAM);       /* SBSW_PDUR_CSL01 */
  if(result != E_OK)
  {
    PduR_RmTp_CancelTransmitPreparation(fmFifoElementRamWriteIdx);
  }
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_FinishReception_TpTxSmStateHandler_RM_TX_TRANSMISSION_FINISHED
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_FinishReception_TpTxSmStateHandler_RM_TX_TRANSMISSION_FINISHED(PduR_RmSrcRomIterType rmSrcIdx, Std_ReturnType result)
{
  PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx = PduR_GetFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx));
  PduR_FmFifoRamIterType fmFifoRamIdx = PduR_GetFmFifoRomIdxOfRmBufferedTpPropertiesRom(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx));
  PduR_GetFctPtrOfFm_FinishWrite_FmSmStateHandler(PduR_GetStateOfFmFifoElementRam(fmFifoElementRamWriteIdx)) (fmFifoElementRamWriteIdx, result);        /* SBSW_PDUR_CSL03 */
  PduR_SetTpTxSmStateOfFmFifoRam(fmFifoRamIdx, PDUR_RM_TX_IDLE_TPTXSMSTATEOFFMFIFORAM); /* SBSW_PDUR_CSL01 */
  PduR_SetRmDestRomIdxOfFmFifoElementRam((fmFifoElementRamWriteIdx), PDUR_NO_RMDESTROMIDXOFFMFIFOELEMENTRAM);   /* SBSW_PDUR_CSL03 */
  PduR_Fm_ActivateNext(fmFifoRamIdx);
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM   == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_FinishReception_TpTxSmStateHandler_NoAction
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_FinishReception_TpTxSmStateHandler_NoAction(PduR_RmSrcRomIterType rmSrcIdx, Std_ReturnType result)
{
  PDUR_DUMMY_STATEMENT(rmSrcIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
 /**********************************************************************************************************************
 * PduR_RmTp_CancelTransmitPreparation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_CancelTransmitPreparation(PduR_FmFifoElementRamIterType fmFifoElementRamIdx)
{
  PduR_RmSrcRomIterType rmSrcIdx = PduR_GetRmSrcRomIdxOfRmDestRom(PduR_GetRmDestRomIdxOfFmFifoElementRam(fmFifoElementRamIdx));
  PduR_RmDestRomIterType rmDestRomIdx;
  for(rmDestRomIdx = PduR_GetRmDestRomStartIdxOfRmSrcRom(rmSrcIdx); rmDestRomIdx < PduR_GetRmDestRomEndIdxOfRmSrcRom(rmSrcIdx); rmDestRomIdx++)
  {
    PduR_RmGDestRomIterType rmGDestRomIdx = PduR_GetRmGDestRomIdxOfRmDestRom(rmDestRomIdx);
    if(PduR_GetTpTxInstSmStateOfRmGDestTpTxStateRam(PduR_GetRmGDestTpTxStateRamIdxOfRmGDestRom(rmGDestRomIdx)) == PDUR_RM_TXINST_ACTIVE_TPTXINSTSMSTATEOFRMGDESTTPTXSTATERAM)
    {
      (void) PduR_RmTp_TxInst_CancelTransmit(rmGDestRomIdx);
    }
  }
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_FinishTransmission_TpTxSmStateHandler_RM_TX_RECEPTION_FINISHED_TRANSMISSION_ACTIVE
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_FinishTransmission_TpTxSmStateHandler_RM_TX_RECEPTION_FINISHED_TRANSMISSION_ACTIVE(PduR_RmDestRomIterType rmGDestRomIdx, Std_ReturnType result)
{
  PduR_FmFifoRomIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx));
  if(PduR_GetPendingConfirmationsOfFmFifoRam(fmFifoRomIdx) == 0u)
  {
    PduR_FmFifoElementRamIterType fmFifoElementRamReadIdx = PduR_GetFmFifoElementRamReadIdxOfFmFifoRam(fmFifoRomIdx);
    PduR_GetFctPtrOfFm_FinishRead_FmSmStateHandler(PduR_GetStateOfFmFifoElementRam(fmFifoElementRamReadIdx)) (fmFifoElementRamReadIdx, result); /* SBSW_PDUR_CSL03 */
    PduR_SetTpTxSmStateOfFmFifoRam(fmFifoRomIdx, PDUR_RM_TX_IDLE_TPTXSMSTATEOFFMFIFORAM);       /* SBSW_PDUR_CSL03 */
    PduR_Fm_ActivateNext(fmFifoRomIdx);
  }
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_FinishTransmission_TpTxSmStateHandler_RM_TX_RECEPTION_TRANSMISSION_ACTIVE
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_FinishTransmission_TpTxSmStateHandler_RM_TX_RECEPTION_TRANSMISSION_ACTIVE(PduR_RmGDestRomIterType rmGDestRomIdx, Std_ReturnType result)
{
  PduR_FmFifoRomIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx));
  if(PduR_GetPendingConfirmationsOfFmFifoRam(fmFifoRomIdx) == 0u)
  {
    PduR_FmFifoElementRamIterType fmFifoElementRamTPReadIdx = PduR_GetFmFifoElementRamReadIdxOfFmFifoRam(fmFifoRomIdx);
    PduR_SetTpTxSmStateOfFmFifoRam(fmFifoRomIdx, PDUR_RM_TX_TRANSMISSION_FINISHED_TPTXSMSTATEOFFMFIFORAM);      /* SBSW_PDUR_CSL01 */
    PduR_GetFctPtrOfFm_FinishRead_FmSmStateHandler(PduR_GetStateOfFmFifoElementRam(fmFifoElementRamTPReadIdx)) (fmFifoElementRamTPReadIdx, result);     /* SBSW_PDUR_CSL03 */
    if(result != E_OK)
    {
      PduR_RmSrcRomIterType rmSrcIdx = PduR_GetRmSrcRomIdxOfRmDestRom(PduR_GetRmDestRomIdxOfFmFifoElementRam(fmFifoElementRamTPReadIdx));
      PduR_GetFctPtrOfRmTp_CancelReceive_TpRxSmStateHandler(PduR_GetTpRxSmStateOfRmBufferedTpPropertiesRam(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx))) (rmSrcIdx);       /* SBSW_PDUR_CSL03 */
    }
  }
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_FinishTransmission_TpTxSmStateHandler_FatalError
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_FinishTransmission_TpTxSmStateHandler_FatalError(PduR_RmDestRomIterType rmGDestRomIdx, Std_ReturnType result)   /* COV_PDUR_FATAL_ERROR */
{
  PDUR_DUMMY_STATEMENT(rmGDestRomIdx);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM  == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_StartOfReception_TpRxSmStateHandler_RM_RX_IDLE
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
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_StartOfReception_TpRxSmStateHandler_RM_RX_IDLE(PduR_RmSrcRomIterType rmSrcIdx,
                                                                                            P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, PduLengthType TpSduLength, P2VAR(PduLengthType,
                                                                                                                                                                                   AUTOMATIC,
                                                                                                                                                                                   PDUR_APPL_DATA)
                                                                                            bufferSizePtr)
{
  BufReq_ReturnType retVal = BUFREQ_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  /* Allocate FiFo element */
  PduR_FmFifoRomIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfRmBufferedTpPropertiesRom(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx));
  PduR_FmFifoElementRamWriteIdxOfFmFifoRamType fmFifoElementRamIdx = 0u;
  if(PduR_Fm_AssignFifoElement(fmFifoRomIdx, &fmFifoElementRamIdx) == E_OK)     /* SBSW_PDUR_STACK_VARIABLE */
  {
    PduR_BmTxBufferRomIdxOfBmTxBufferIndRomType allocatedTxBufferIdxPtr = 0u;
    /* Update fill level */
    PduR_IncFillLevelOfFmFifoRam(fmFifoRomIdx); /* SBSW_PDUR_CSL03 */
    /* Mapping Src Handle and current Fifo element */
    PduR_SetFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx), fmFifoElementRamIdx);      /* SBSW_PDUR_CSL03 */
    /* Store related routing source in Fifo Manager Ram table: first destination is saved as it is only used to go to the corresponding RmSrc later */
    PduR_SetRmDestRomIdxOfFmFifoElementRam(fmFifoElementRamIdx, (PduR_RmDestRomIdxOfFmFifoElementRamType) PduR_GetRmDestRomStartIdxOfRmSrcRom(rmSrcIdx));       /* SBSW_PDUR_CSL03 */

    /* Split Allocate and Assign buffer */
    if(PduR_Bm_AllocateTxBuffer(PduR_GetBmTxBufferIndRomStartIdxOfRmBufferedTpPropertiesRom(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx)), PduR_GetBmTxBufferIndRomEndIdxOfRmBufferedTpPropertiesRom(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx)), fmFifoElementRamIdx, (PduR_BmTxBufferArrayRamLengthOfBmTxBufferRomType) TpSduLength, bufferSizePtr, &allocatedTxBufferIdxPtr, TRUE) == BUFREQ_OK)   /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
    {
      PduR_Fm_AssignTxBuffer2FifoElement(fmFifoElementRamIdx, allocatedTxBufferIdxPtr);
      PduR_SetStateOfFmFifoElementRam(fmFifoElementRamIdx, PDUR_FM_ALLOCATED_WITH_BUFFER_STATEOFFMFIFOELEMENTRAM);      /* SBSW_PDUR_CSL01 */
# if  (PDUR_METADATA_SUPPORT == STD_ON )
      if(PduR_IsMetaDataLengthUsedOfRmBufferedTpPropertiesRom(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx)))        /* COV_PDUR_FEATURE_ALWAYS_TRUE */
      {
        retVal = PduR_RmTp_StartOfReceptionQueueMetaData(rmSrcIdx, info->SduLength, info->SduDataPtr, bufferSizePtr);   /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
      }
      if(retVal != BUFREQ_OK)   /* COV_PDUR_FATAL_ERROR */
      {
        PduR_Det_ReportError(PDUR_RXSM_STARTOFRECEPTION, PDUR_E_FATAL);
      }
      else
# endif
      {
        PduR_SetTpRxSmStateOfRmBufferedTpPropertiesRam(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx), PDUR_RM_RX_ACTIVE_TPRXSMSTATEOFRMBUFFEREDTPPROPERTIESRAM);     /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
        PduR_GetFctPtrOfFm_ActivateWrite_FmSmStateHandler(PduR_GetStateOfFmFifoElementRam(fmFifoElementRamIdx)) (fmFifoElementRamIdx);  /* SBSW_PDUR_CSL03 */
        /* Call CheckReady2Transmit() of the FIFO Element state machine */
        if((PduR_GetFctPtrOfRmTp_CheckReady2Transmit_TpTxSmStateHandler(PduR_GetTpTxSmStateOfFmFifoRam(fmFifoRomIdx)) (rmSrcIdx)) != E_OK)      /* SBSW_PDUR_CSL03 */
        {
          PduR_GetFctPtrOfRmTp_TpRxIndication_TpRxSmStateHandler(PduR_GetTpRxSmStateOfRmBufferedTpPropertiesRam(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx))) (rmSrcIdx, E_NOT_OK);        /* SBSW_PDUR_CSL03 */
          retVal = BUFREQ_E_NOT_OK;
        }
      }
    }
    else
    {
      PduR_Fm_FreeFifoElement(fmFifoRomIdx, fmFifoElementRamIdx);
      retVal = BUFREQ_E_NOT_OK;
    }
  }
  else
  {
    retVal = BUFREQ_E_NOT_OK;
  }
  PDUR_DUMMY_STATEMENT(rmSrcIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(TpSduLength);    /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(bufferSizePtr);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return retVal;
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM  == STD_ON)
 /**********************************************************************************************************************
 * PduR_RmTp_StartOfReception_TpRxSmStateHandler_UnexpectedCall
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_StartOfReception_TpRxSmStateHandler_UnexpectedCall(PduR_RmSrcRomIterType rmSrcIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
                                                                                                PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr)
{
  PduR_Det_ReportError(PDUR_FCT_SOR, PDUR_E_UNEXPECTED_CALL);
  PDUR_DUMMY_STATEMENT(rmSrcIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(TpSduLength);    /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(bufferSizePtr);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return BUFREQ_E_NOT_OK;
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_CopyRxData_TpRxSmStateHandler_RM_RX_ACTIVE
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_CopyRxData_TpRxSmStateHandler_RM_RX_ACTIVE(PduR_RmSrcRomIterType rmSrcIdx, PduLengthType pduLength,
                                                                                        SduDataPtrType sduDataPtr, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr)
{
  BufReq_ReturnType retVal;

  PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx = PduR_GetFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx));
  PduR_BmTxBufferRomIterType txBufferElementIdx = PduR_GetBmTxBufferRomIdxOfFmFifoElementRam(fmFifoElementRamWriteIdx);

  retVal = PduR_Bm_PutData(txBufferElementIdx, (PduR_BmTxBufferArrayRamIterType) pduLength, sduDataPtr);        /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */

  if(retVal == BUFREQ_OK)
  {
    PduR_FmFifoRamIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfRmBufferedTpPropertiesRom(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx));
    if(PduR_GetFctPtrOfRmTp_CheckReady2Transmit_TpTxSmStateHandler(PduR_GetTpTxSmStateOfFmFifoRam(fmFifoRomIdx)) (rmSrcIdx) != E_OK)    /* SBSW_PDUR_CSL03 */
    {
      retVal = BUFREQ_E_NOT_OK;
    }
  }
  *bufferSizePtr = (PduLengthType) PduR_Bm_GetTotalBufferSize(txBufferElementIdx);      /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
  return retVal;
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_CopyRxData_TpRxSmStateHandler_RM_RX_ABORTED
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_CopyRxData_TpRxSmStateHandler_RM_RX_ABORTED(PduR_RmSrcRomIterType rmSrcIdx, PduLengthType pduLength,
                                                                                         SduDataPtrType sduDataPtr, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr)
{
  PDUR_DUMMY_STATEMENT(rmSrcIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(pduLength);      /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(sduDataPtr);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(bufferSizePtr);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return BUFREQ_E_NOT_OK;
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_CopyRxData_TpRxSmStateHandler_UnexpectedCall
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_CopyRxData_TpRxSmStateHandler_UnexpectedCall(PduR_RmSrcRomIterType rmSrcIdx, PduLengthType pduLength,
                                                                                          SduDataPtrType sduDataPtr, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr)
{
  PduR_Det_ReportError(PDUR_RXSM_COPYRXDATA_UNEXPECTEDCALL, PDUR_E_UNEXPECTED_CALL);
  PDUR_DUMMY_STATEMENT(rmSrcIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(pduLength);      /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(sduDataPtr);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(bufferSizePtr);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return BUFREQ_E_NOT_OK;
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TpRxIndication_TpRxSmStateHandler_RM_RX_ACTIVE_OR_RM_RX_ABORTED
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_TpRxIndication_TpRxSmStateHandler_RM_RX_ACTIVE_OR_RM_RX_ABORTED(PduR_RmSrcRomIterType rmSrcIdx, Std_ReturnType result)
{
  PduR_FmFifoRomIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfRmBufferedTpPropertiesRom(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx));
  PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx = PduR_GetFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx));
  PduR_GetFctPtrOfRmTp_FinishReception_TpTxSmStateHandler(PduR_GetTpTxSmStateOfFmFifoRam(fmFifoRomIdx)) (rmSrcIdx, result);     /* SBSW_PDUR_CSL03 */
  PduR_GetFctPtrOfFm_FinishWrite_FmSmStateHandler(PduR_GetStateOfFmFifoElementRam(fmFifoElementRamWriteIdx)) (fmFifoElementRamWriteIdx, result);        /* SBSW_PDUR_CSL03 */
  PduR_SetFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx), PDUR_NO_FMFIFOELEMENTRAMIDXOFRMBUFFEREDTPPROPERTIESRAM);     /* SBSW_PDUR_CSL03 */
  PduR_SetTpRxSmStateOfRmBufferedTpPropertiesRam(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx), PDUR_RM_RX_IDLE_TPRXSMSTATEOFRMBUFFEREDTPPROPERTIESRAM);     /* SBSW_PDUR_CSL03 */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TpRxIndication_TpRxSmStateHandler_UnexpectedCall
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_TpRxIndication_TpRxSmStateHandler_UnexpectedCall(PduR_RmSrcRomIterType rmSrcIdx, Std_ReturnType result)
{
  PduR_Det_ReportError(PDUR_RMTP_RXSM_TPRXINDICATION_UNEXPECTEDCALL, PDUR_E_UNEXPECTED_CALL);
  PDUR_DUMMY_STATEMENT(rmSrcIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_CancelReceive_TpRxSmStateHandler_RM_RX_ACTIVE
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_CancelReceive_TpRxSmStateHandler_RM_RX_ACTIVE(PduR_RmSrcRomIterType rmSrcIdx)
{
  PduR_SetTpRxSmStateOfRmBufferedTpPropertiesRam(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx), PDUR_RM_RX_ABORTED_TPRXSMSTATEOFRMBUFFEREDTPPROPERTIESRAM);  /* SBSW_PDUR_CSL03 */
  PDUR_DUMMY_STATEMENT(rmSrcIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_CancelReceive_TpRxSmStateHandler_RM_RX_ABORTED
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_CancelReceive_TpRxSmStateHandler_RM_RX_ABORTED(PduR_RmSrcRomIterType rmSrcIdx)  /* COV_PDUR_DUMMY_FUNCTION */
{
  PDUR_DUMMY_STATEMENT(rmSrcIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_CancelReceive_TpRxSmStateHandler_FatalError
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_CancelReceive_TpRxSmStateHandler_FatalError(PduR_RmSrcRomIterType rmSrcIdx)     /* COV_PDUR_FATAL_ERROR */
{
  PduR_Det_ReportError(PDUR_RXSM_TPCANCELRECEIVE_FATALERROR, PDUR_E_FATAL);
  PDUR_DUMMY_STATEMENT(rmSrcIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: PduR_RmTp.c
 *********************************************************************************************************************/
