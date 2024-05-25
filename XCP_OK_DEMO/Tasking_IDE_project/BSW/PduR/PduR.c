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
 *         File:  PduR.c
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
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/
/* *INDENT-OFF* */
/* PRQA  S 1881 EOF */ /* MD_MSR_AutosarBoolean */
/* PRQA  S 4304 EOF */ /* MD_MSR_AutosarBoolean */
/* PRQA  S 4404 EOF */ /* MD_MSR_AutosarBoolean */
/* *INDENT-ON* */

#define PDUR_SOURCE
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR.h"
#include "PduR_Bm.h"
#include "PduR_Fm.h"
#include "PduR_Sm.h"
#include "PduR_RmIf.h"
#include "PduR_RmTp.h"
#include "PduR_RmTp_TxInst.h"
#include "PduR_McQ.h"
#include "PduR_Lock.h"
#include "SchM_PduR.h"

#if(PDUR_MULTICORE == STD_ON)
# include "Os.h"
#endif

#if ((PDUR_BSWMPDURRXINDICATIONCALLBACKOFRXIF2DEST == STD_ON) || (PDUR_BSWMPDURTPRXINDICATIONCALLBACKOFRXTP2DEST == STD_ON) || (PDUR_BSWMPDURTPSTARTOFRECEPTIONCALLBACKOFRXTP2DEST == STD_ON) || (PDUR_BSWMPDURTRANSMITCALLBACKOFTX2LO == STD_ON) || (PDUR_BSWMPDURTXCONFIRMATIONCALLBACKOFTXIF2UP == STD_ON) || (PDUR_BSWMPDURTPTXCONFIRMATIONCALLBACKOFTXTP2SRC == STD_ON))
# include "BswM_PduR.h"
#endif

#if(PDUR_USE_ECUM_BSW_ERROR_HOOK == STD_ON)
# include "EcuM_Error.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#if(PDUR_RPGROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Init_RmDestRpgRom
 *********************************************************************************************************************/
/*! \brief      This function initializes the PDUR routing path groups.
 *  \details     -
 *  \pre        PduR_InitMemory() has been executed, if the start up code does not initialize variables.
 *  \note       The function must be called on task level and has not to be interrupted.
 *              by other administrative function calls.
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Init_RmDestRpgRom(void);
#endif

#if(PDUR_RMGDESTNTO1INFORAMIDXOFRMGDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Rm_MultipleSourceHandler_Init
 *********************************************************************************************************************/
/*! \brief      This function initializes the PDUR fan in RAM variables.
 *  \details     -
 *  \pre        PduR_InitMemory() has been executed, if the start up code does not initialize variables.
 *  \note       The function must be called on task level and has not to be interrupted
 *              by other administrative function calls.
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Rm_MultipleSourceHandler_Init(void);
#endif

#if ((PDUR_RPGROM == STD_ON) && (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_DisableIfRoutingAction
 *********************************************************************************************************************/
/*! \brief      This function flushes the Interface queue if the queue is in use while the RoutingPathGroup
 *              is disabled.
 *  \details    -
 *  \param[in]  rmDestRomIdx  Gateway Id used for state handling.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_DisableIfRoutingAction(PduR_RmDestRomIterType rmDestRomIdx);
#endif

#if ((PDUR_IFCANCELTRANSMITSUPPORTEDOFMMROM == STD_ON) || (PDUR_TPCANCELTRANSMITSUPPORTEDOFMMROM == STD_ON))
/**********************************************************************************************************************
 * PduR_Rm_CancelTransmit_MultiDest
 *********************************************************************************************************************/
/*!
 * \brief    The function calls the CancelTransmit function for every destination
 * \details     -
 * \param[in]   rmSrcIdx            internal RmSrcRom index
 * \return      Std_ReturnType
 *               E_OK              Cancellation was executed successfully by all the destination modules.
 *               E_NOT_OK          Cancellation was rejected by the destination module.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
**********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_Rm_CancelTransmit_MultiDest(PduR_RmSrcRomIterType rmSrcIdx);
#endif

#if ((PDUR_MAIN_FUNCTION == STD_ON) && ((PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON) || (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)))
/**********************************************************************************************************************
  PduR_DispatchMainfuntion
**********************************************************************************************************************/
/*! \brief      This function calls the corresponding Mainfunction for the rmGDestRomIdx
 *  \details    -
 *  \param[in]  rmGDestRomIdx    internal RmGDestRom index
 *  \pre        -
 ********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_DispatchMainfuntion(PduR_RmGDestRomIterType rmGDestRomIdx);
#endif

#if(PDUR_DEFERREDEVENTCACHEROM == STD_ON)
/**********************************************************************************************************************
  PduR_EvC_Init
**********************************************************************************************************************/
/*! \brief      This function initializes the deferred event cache.
 *  \details    -
 *  \pre        -
 ********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_EvC_Init(void);
#endif

#if (PDUR_DEFERREDEVENTCACHEROM == STD_ON)
/**********************************************************************************************************************
 * PduR_EvC_ReadFlush
 *********************************************************************************************************************/
/*! \brief       Flush the event queue by setting the read pointer equal to the write pointer
 *  \details -
 *  \param[in]   deferredEventCacheIdx    Id of the correct queue to be used
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \note        This function must only be called by the reader core!
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_EvC_ReadFlush(PduR_DeferredEventCacheRomIdxOfSrcCoreRomType deferredEventCacheIdx);
#endif

#if (PDUR_DEFERREDEVENTCACHEROM == STD_ON)
/**********************************************************************************************************************
 * PduR_EvC_IsFull
 *********************************************************************************************************************/
/*! \brief       Checks if the queue is full.
 *  \details -
 *  \param[in]   deferredEventCacheIdx    Id of the correct queue to be used
 *  \return      true                     Queue is full.
 *               false                    Queue is not full.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean, PDUR_CODE) PduR_EvC_IsFull(PduR_DeferredEventCacheRomIdxOfSrcCoreRomType deferredEventCacheIdx);
#endif

/**********************************************************************************************************************
 * LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * GLOBAL AND LOCAL FUNCTIONS
 *********************************************************************************************************************/
#define PDUR_START_SEC_CODE
#include "MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

#if(PDUR_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 * PduR_GetVersionInfo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, PDUR_APPL_DATA) versionInfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
# if (PDUR_DEV_ERROR_DETECT == STD_ON)  /* COV_PDUR_VAR_DEV_ERROR_DETECT */
  /* Check parameter 'ConfigPtr' */
  if(versionInfo == NULL_PTR)
  {
    errorId = PDUR_E_PARAM_POINTER;
  }
  else
# endif
  {
    versionInfo->vendorID = (uint16) PDUR_VENDOR_ID;    /* SBSW_PDUR_GETVERSION_PARAM */
    versionInfo->moduleID = (uint8) PDUR_MODULE_ID;     /* SBSW_PDUR_GETVERSION_PARAM */
    versionInfo->sw_major_version = (uint8) PDUR_SW_MAJOR_VERSION;      /* SBSW_PDUR_GETVERSION_PARAM */
    versionInfo->sw_minor_version = (uint8) PDUR_SW_MINOR_VERSION;      /* SBSW_PDUR_GETVERSION_PARAM */
    versionInfo->sw_patch_version = (uint8) PDUR_SW_PATCH_VERSION;      /* SBSW_PDUR_GETVERSION_PARAM */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_VERSIONINFO, errorId);
  }
# else
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif
}       /* End of PduR_GetVersionInfo() */
#endif

/**********************************************************************************************************************
 * PduR_GetConfigurationId
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(PduR_PBConfigIdType, PDUR_CODE) PduR_GetConfigurationId(void)
{
  uint16 configID = 0u;         /* PRQA S 2981 */ /* MD_MSR_RetVal */
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_INVALID_REQUEST;
  }
  else
  {
    configID = PduR_GetConfigId();
  }
  /* ----- Development Error Report --------------------------------------- */
#if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_CONFIGURATIONID, errorId);
  }
#else
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
#endif
  return configID;
}       /* End of PduR_GetConfigurationId() */

/* Upper Layer Interface APIs */
#if (PDUR_TX2LO == STD_ON)
/**********************************************************************************************************************
 * PduR_UpTransmit
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
FUNC(Std_ReturnType, PDUR_CODE) PduR_UpTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_INVALID_REQUEST;
  }
# if (PDUR_DEV_ERROR_DETECT == STD_ON)  /* COV_PDUR_VAR_DEV_ERROR_DETECT */
  else if((id >= PduR_GetSizeOfTx2Lo())
#  if (PDUR_INVALIDHNDOFTX2LO == STD_ON)
          || (PduR_IsInvalidHndOfTx2Lo(id))
#  endif
    )
  {
    errorId = PDUR_E_PDU_ID_INVALID;
  }
# endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
# if (PDUR_BSWMPDURTRANSMITCALLBACKOFTX2LO == STD_ON)
    if(PduR_IsBswMPduRTransmitCallbackOfTx2Lo(id))
    {
      BswM_PduR_Transmit(id, info);     /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
    }
# endif
    {
      { /* 1:N Tx If API Forwarding; 1:1 Tx Tp API Forwarding */
        retVal = PduR_GetRmTransmitFctPtr(PduR_GetRmTransmitFctPtrIdxOfTx2Lo(id)) (PduR_GetRmSrcRomIdxOfTx2Lo(id), info);       /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_TX, errorId);
  }
# else
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return retVal;
}
#endif

/* Communication Interface APIs */
#if (PDUR_RXIF2DEST == STD_ON)
/**********************************************************************************************************************
 * PduR_LoIfRxIndication
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
FUNC(void, PDUR_CODE) PduR_LoIfRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_INVALID_REQUEST;
  }
# if (PDUR_DEV_ERROR_DETECT == STD_ON)  /* COV_PDUR_VAR_DEV_ERROR_DETECT */
  else if((RxPduId >= PduR_GetSizeOfRxIf2Dest())
#  if (PDUR_INVALIDHNDOFRXIF2DEST == STD_ON)
          || (PduR_IsInvalidHndOfRxIf2Dest(RxPduId))
#  endif
    )
  {
    errorId = PDUR_E_PDU_ID_INVALID;
  }
# endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
# if (PDUR_BSWMPDURRXINDICATIONCALLBACKOFRXIF2DEST == STD_ON)
    if(PduR_IsBswMPduRRxIndicationCallbackOfRxIf2Dest(RxPduId))
    {
      BswM_PduR_RxIndication(RxPduId, info);    /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
    }
# endif
    {
      (void) PduR_RmIf_RxIndication_MultiIf(PduR_GetRmSrcRomIdxOfRxIf2Dest(RxPduId), info);     /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_IFRXIND, errorId);
  }
# else
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif

  PDUR_DUMMY_STATEMENT(RxPduId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_TXCONFIRMATIONUSEDOFTXIF2UP == STD_ON)
/**********************************************************************************************************************
 * PduR_LoIfTxConfirmation
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
FUNC(void, PDUR_CODE) PduR_LoIfTxConfirmation(PduIdType TxPduId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_INVALID_REQUEST;
  }
# if (PDUR_DEV_ERROR_DETECT == STD_ON)  /* COV_PDUR_VAR_DEV_ERROR_DETECT */
  else if((TxPduId >= PduR_GetSizeOfTxIf2Up())
#  if (PDUR_INVALIDHNDOFTXIF2UP == STD_ON)
          || (PduR_IsInvalidHndOfTxIf2Up(TxPduId))
#  endif
    )
  {
    errorId = PDUR_E_PDU_ID_INVALID;
  }
# endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
# if (PDUR_BSWMPDURTXCONFIRMATIONCALLBACKOFTXIF2UP == STD_ON)
    if(PduR_IsBswMPduRTxConfirmationCallbackOfTxIf2Up(TxPduId))
    {
      BswM_PduR_TxConfirmation(TxPduId);
    }
# endif
# if (PDUR_TXCONFIRMATIONUSEDOFTXIF2UP == STD_ON)       /* COV_PDUR_VAR_LINIF_SPECIAL_CONFIGURATION */
    if(PduR_IsTxConfirmationUsedOfTxIf2Up(TxPduId))     /* COV_PDUR_FEATURE_ALWAYS_TRUE */
    {
      PduR_RmIf_MultipleSourceHandler_TxConfirmation(PduR_GetRmGDestRomIdxOfTxIf2Up(TxPduId));
    }
# endif
  }

  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_IFTXCFM, errorId);
  }
# else
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif

  PDUR_DUMMY_STATEMENT(TxPduId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if ((PDUR_TRIGGERTRANSMITSUPPORTEDOFRMSRCROM == STD_ON) || (PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
/**********************************************************************************************************************
 * PduR_LoIfTriggerTransmit
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
FUNC(Std_ReturnType, PDUR_CODE) PduR_LoIfTriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_INVALID_REQUEST;
  }
# if (PDUR_DEV_ERROR_DETECT == STD_ON)  /* COV_PDUR_VAR_DEV_ERROR_DETECT */
  else if((TxPduId >= PduR_GetSizeOfTxIf2Up())
#  if (PDUR_INVALIDHNDOFTXIF2UP == STD_ON)
          || (PduR_IsInvalidHndOfTxIf2Up(TxPduId))
#  endif
    )
  {
    errorId = PDUR_E_PDU_ID_INVALID;
  }
# endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    retVal = PduR_RmIf_MultipleSourceHandler_TriggerTransmit(PduR_GetRmGDestRomIdxOfTxIf2Up(TxPduId), info);    /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_TT, errorId);
  }
# else
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif

  PDUR_DUMMY_STATEMENT(TxPduId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return retVal;
}
#endif
/* Transport Protocol APIs */
#if (PDUR_RXTP2DEST == STD_ON)
/**********************************************************************************************************************
 * PduR_LoTpStartOfReception
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
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpStartOfReception(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, PduLengthType TpSduLength,
                                                             P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;   /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_INVALID_REQUEST;
  }
# if (PDUR_DEV_ERROR_DETECT == STD_ON)  /* COV_PDUR_VAR_DEV_ERROR_DETECT */
  else if((id >= PduR_GetSizeOfRxTp2Dest())
#  if (PDUR_INVALIDHNDOFRXTP2DEST == STD_ON)
          || (PduR_IsInvalidHndOfRxTp2Dest(id))
#  endif
    )
  {
    errorId = PDUR_E_PDU_ID_INVALID;
  }
# endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
# if (PDUR_BSWMPDURTPSTARTOFRECEPTIONCALLBACKOFRXTP2DEST == STD_ON)
    if(PduR_IsBswMPduRTpStartOfReceptionCallbackOfRxTp2Dest(id))
    {
      BswM_PduR_TpStartOfReception(id, info, TpSduLength, bufferSizePtr);       /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
    }
# endif
    {
      PduR_RmSrcRomIdxOfRxTp2DestType rmSrcRomIdx = PduR_GetRmSrcRomIdxOfRxTp2Dest(id);
# if (PDUR_EXISTS_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON)
      PduR_RmDestRomStartIdxOfRmSrcRomType rmDestRomIdx = PduR_GetRmDestRomStartIdxOfRmSrcRom(rmSrcRomIdx);
#  if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
      if((PduR_GetRmDestRomLengthOfRmSrcRom(rmSrcRomIdx) == 1u) && (PduR_GetRoutingTypeOfRmDestRom(rmDestRomIdx) == PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM))      /* COV_PDUR_FEATURE_ALWAYS_TRUE */
#  endif
      { /* 1:1 Rx API Forwarding */
#  if (PDUR_RPGROM == STD_ON)
        if((!PduR_IsRmDestRpgRomUsedOfRmDestRom(rmDestRomIdx)) || (0u != PduR_GetEnabledCntOfRmDestRpgRam(PduR_GetRmDestRpgRomIdxOfRmDestRom(rmDestRomIdx))))
#  endif
        {
          PduR_RmGDestRomIdxOfRmDestRomType rmGDestRomIdx = PduR_GetRmGDestRomIdxOfRmDestRom(rmDestRomIdx);
          retVal = PduR_GetUpTpStartOfReceptionFctPtrOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(rmGDestRomIdx)) (PduR_GetDestHndOfRmGDestRom(rmGDestRomIdx), info, TpSduLength, bufferSizePtr);       /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
        }
      }
# endif
# if ((PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON) && (PDUR_EXISTS_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON))
      else
# endif
# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
      { /* buffered Tp Routings */
        retVal = PduR_RmTp_StartOfReception(rmSrcRomIdx, info, TpSduLength, bufferSizePtr);     /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
      }
# endif
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_SOR, errorId);
  }
# else
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(TpSduLength);    /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(bufferSizePtr);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return retVal;
}
#endif
#if (PDUR_RXTP2DEST == STD_ON)
/**********************************************************************************************************************
 * PduR_LoTpCopyRxData
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
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpCopyRxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;   /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_INVALID_REQUEST;
  }
# if (PDUR_DEV_ERROR_DETECT == STD_ON)  /* COV_PDUR_VAR_DEV_ERROR_DETECT */
  else if((id >= PduR_GetSizeOfRxTp2Dest())
#  if (PDUR_INVALIDHNDOFRXTP2DEST == STD_ON)
          || (PduR_IsInvalidHndOfRxTp2Dest(id))
#  endif
    )
  {
    errorId = PDUR_E_PDU_ID_INVALID;
  }
# endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    {
      PduR_RmSrcRomIdxOfRxTp2DestType rmSrcRomIdx = PduR_GetRmSrcRomIdxOfRxTp2Dest(id);
# if (PDUR_EXISTS_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON)
      PduR_RmDestRomStartIdxOfRmSrcRomType rmDestRomIdx = PduR_GetRmDestRomStartIdxOfRmSrcRom(rmSrcRomIdx);
#  if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
      if((PduR_GetRmDestRomLengthOfRmSrcRom(rmSrcRomIdx) == 1u) && (PduR_GetRoutingTypeOfRmDestRom(rmDestRomIdx) == PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM))      /* COV_PDUR_FEATURE_ALWAYS_TRUE */
#  endif
      { /* 1:1 Rx API Forwarding */
#  if (PDUR_RPGROM == STD_ON)
        if((!PduR_IsRmDestRpgRomUsedOfRmDestRom(rmDestRomIdx)) || (0u != PduR_GetEnabledCntOfRmDestRpgRam(PduR_GetRmDestRpgRomIdxOfRmDestRom(rmDestRomIdx))))
#  endif
        {
          PduR_RmGDestRomIdxOfRmDestRomType rmGDestRomIdx = PduR_GetRmGDestRomIdxOfRmDestRom(rmDestRomIdx);
          retVal = PduR_GetUpTpCopyRxDataFctPtrOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(rmGDestRomIdx)) (PduR_GetDestHndOfRmGDestRom(rmGDestRomIdx), info, bufferSizePtr);  /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
        }
      }
# endif
# if ((PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON) && (PDUR_EXISTS_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON))
      else
# endif
# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
      { /* buffered Tp Routings */
        retVal = PduR_RmTp_CopyRxData(rmSrcRomIdx, info, bufferSizePtr);        /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
      }
# endif
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_CPYRX, errorId);
  }
# else
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(bufferSizePtr);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return retVal;
}
#endif
#if(PDUR_TXTP2SRC == STD_ON)
/**********************************************************************************************************************
 * PduR_LoTpCopyTxData
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
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpCopyTxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
                                                       P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;   /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_INVALID_REQUEST;
  }
# if (PDUR_DEV_ERROR_DETECT == STD_ON)  /* COV_PDUR_VAR_DEV_ERROR_DETECT */
  else if((id >= PduR_GetSizeOfTxTp2Src())
#  if (PDUR_INVALIDHNDOFTXTP2SRC == STD_ON)
          || (PduR_IsInvalidHndOfTxTp2Src(id))
#  endif
    )
  {
    errorId = PDUR_E_PDU_ID_INVALID;
  }
# endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    retVal = PduR_RmTp_MultipleSourceHandler_CopyTxData(PduR_GetRmGDestRomIdxOfTxTp2Src(id), info, retry, availableDataPtr);    /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_CPYTX, errorId);
  }
# else
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(retry);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(availableDataPtr);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return retVal;
}
#endif
#if (PDUR_RXTP2DEST == STD_ON)
/**********************************************************************************************************************
 * PduR_LoTpRxIndication
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
FUNC(void, PDUR_CODE) PduR_LoTpRxIndication(PduIdType id, Std_ReturnType result)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_INVALID_REQUEST;
  }
# if (PDUR_DEV_ERROR_DETECT == STD_ON)  /* COV_PDUR_VAR_DEV_ERROR_DETECT */
  else if((id >= PduR_GetSizeOfRxTp2Dest())
#  if (PDUR_INVALIDHNDOFRXTP2DEST == STD_ON)
          || (PduR_IsInvalidHndOfRxTp2Dest(id))
#  endif
    )
  {
    errorId = PDUR_E_PDU_ID_INVALID;
  }
# endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
# if (PDUR_BSWMPDURTPRXINDICATIONCALLBACKOFRXTP2DEST == STD_ON)
    if(PduR_IsBswMPduRTpRxIndicationCallbackOfRxTp2Dest(id))
    {
      BswM_PduR_TpRxIndication(id, result);
    }
# endif
    {
      PduR_RmSrcRomIdxOfRxTp2DestType rmSrcRomIdx = PduR_GetRmSrcRomIdxOfRxTp2Dest(id);
# if (PDUR_EXISTS_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON)
      PduR_RmDestRomStartIdxOfRmSrcRomType rmDestRomIdx = PduR_GetRmDestRomStartIdxOfRmSrcRom(rmSrcRomIdx);
#  if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
      if((PduR_GetRmDestRomLengthOfRmSrcRom(rmSrcRomIdx) == 1u) && (PduR_GetRoutingTypeOfRmDestRom(rmDestRomIdx) == PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM))      /* COV_PDUR_FEATURE_ALWAYS_TRUE */
#  endif
      { /* 1:1 Rx API Forwarding */
        PduR_RmGDestRomIdxOfRmDestRomType rmGDestRomIdx = PduR_GetRmGDestRomIdxOfRmDestRom(rmDestRomIdx);
        PduR_GetUpTpTpRxIndicationFctPtrOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(rmGDestRomIdx)) (PduR_GetDestHndOfRmGDestRom(rmGDestRomIdx), result);      /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
      }
# endif
# if ((PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON) && (PDUR_EXISTS_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON))
      else
# endif
# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
      { /* buffered Tp Routings */
        PduR_RmTp_TpRxIndication(rmSrcRomIdx, result);
      }
# endif
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_TPRXIND, errorId);
  }
# else
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif
#if (PDUR_TXTP2SRC == STD_ON)
/**********************************************************************************************************************
 * PduR_LoTpTxConfirmation
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
FUNC(void, PDUR_CODE) PduR_LoTpTxConfirmation(PduIdType id, Std_ReturnType result)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_INVALID_REQUEST;
  }
# if (PDUR_DEV_ERROR_DETECT == STD_ON)  /* COV_PDUR_VAR_DEV_ERROR_DETECT */
  else if((id >= PduR_GetSizeOfTxTp2Src())
#  if (PDUR_INVALIDHNDOFTXTP2SRC == STD_ON)
          || (PduR_IsInvalidHndOfTxTp2Src(id))
#  endif
    )
  {
    errorId = PDUR_E_PDU_ID_INVALID;
  }
# endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
# if (PDUR_BSWMPDURTPTXCONFIRMATIONCALLBACKOFTXTP2SRC == STD_ON)
    if(PduR_IsBswMPduRTpTxConfirmationCallbackOfTxTp2Src(id))
    {
      BswM_PduR_TpTxConfirmation(id, result);
    }
# endif
    PduR_RmTp_MultipleSourceHandler_TpTxConfirmation(PduR_GetRmGDestRomIdxOfTxTp2Src(id), result);
  }

  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_TPTXCFM, errorId);
  }
# else
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif
/* CancelReceive global without UseTag API */
#if (PDUR_CANCELRECEIVESUPPORTEDOFMMROM == STD_ON)
/**********************************************************************************************************************
 * PduR_CancelReceive
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
FUNC(Std_ReturnType, PDUR_CODE) PduR_CancelReceive(PduIdType id)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_INVALID_REQUEST;
  }
# if (PDUR_DEV_ERROR_DETECT == STD_ON)  /* COV_PDUR_VAR_DEV_ERROR_DETECT */
  else if((id >= PduR_GetSizeOfRxTp2Src())
#  if (PDUR_INVALIDHNDOFRXTP2SRC == STD_ON)
          || (PduR_IsInvalidHndOfRxTp2Src(id))
#  endif
    )
  {
    errorId = PDUR_E_PDU_ID_INVALID;
  }
# endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    PduR_RmDestRomIdxOfRxTp2SrcType rmDestRomIdx = PduR_GetRmDestRomIdxOfRxTp2Src(id);
    PduR_RmSrcRomIdxOfRmDestRomType rmSrcRomIdx = PduR_GetRmSrcRomIdxOfRmDestRom(rmDestRomIdx);
    PduR_MmRomIdxOfRmSrcRomType mmRomIdx = PduR_GetMmRomIdxOfRmSrcRom(rmSrcRomIdx);

    if(PduR_IsCancelReceiveSupportedOfMmRom(mmRomIdx))  /* COV_PDUR_FEATURE_ALWAYS_TRUE */
    {
# if (PDUR_RPGROM == STD_ON)
      if((!PduR_IsRmDestRpgRomUsedOfRmDestRom(rmDestRomIdx)) || (0u != PduR_GetEnabledCntOfRmDestRpgRam(PduR_GetRmDestRpgRomIdxOfRmDestRom(rmDestRomIdx))))
# endif
      {
        PduR_SrcHndOfRmSrcRomType srcHnd = PduR_GetSrcHndOfRmSrcRom(rmSrcRomIdx);
        retVal = PduR_GetLoTpCancelReceiveFctPtrOfMmRom(mmRomIdx) (srcHnd);     /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_ONLY */
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_CRX, errorId);
  }
# else
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return retVal;
}
#endif
#if (PDUR_CHANGEPARAMETERSUPPORTEDOFMMROM == STD_ON)
/* ChangeParameter global without UseTag  API */
/**********************************************************************************************************************
 * PduR_ChangeParameter
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
FUNC(Std_ReturnType, PDUR_CODE) PduR_ChangeParameter(PduIdType id, TPParameterType parameter, uint16 value)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_INVALID_REQUEST;
  }
# if (PDUR_DEV_ERROR_DETECT == STD_ON)  /* COV_PDUR_VAR_DEV_ERROR_DETECT */
  else if((id >= PduR_GetSizeOfRxTp2Src())
#  if (PDUR_INVALIDHNDOFRXTP2SRC == STD_ON)
          || (PduR_IsInvalidHndOfRxTp2Src(id))
#  endif
    )
  {
    errorId = PDUR_E_PDU_ID_INVALID;
  }
# endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    PduR_RmDestRomIdxOfRxTp2SrcType rmDestRomIdx = PduR_GetRmDestRomIdxOfRxTp2Src(id);
    PduR_RmSrcRomIdxOfRmDestRomType rmSrcRomIdx = PduR_GetRmSrcRomIdxOfRmDestRom(rmDestRomIdx);
    PduR_MmRomIdxOfRmSrcRomType mmRomIdx = PduR_GetMmRomIdxOfRmSrcRom(rmSrcRomIdx);

    if(PduR_IsChangeParameterSupportedOfMmRom(mmRomIdx))        /* COV_PDUR_FEATURE_ALWAYS_TRUE */
    {
      PduR_SrcHndOfRmSrcRomType srcHnd = PduR_GetSrcHndOfRmSrcRom(rmSrcRomIdx);
      retVal = PduR_GetLoTpChangeParameterFctPtrOfMmRom(mmRomIdx) (srcHnd, parameter, value);   /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_ONLY */
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_CHPARA, errorId);
  }
# else
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(parameter);      /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(value);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return retVal;
}
#endif
/* Communication Interface / Transport Protocol APIs */
#if ((PDUR_IFCANCELTRANSMITSUPPORTEDOFMMROM == STD_ON) || (PDUR_TPCANCELTRANSMITSUPPORTEDOFMMROM == STD_ON))
/**********************************************************************************************************************
 * PduR_CancelTransmit
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
FUNC(Std_ReturnType, PDUR_CODE) PduR_CancelTransmit(PduIdType id)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_INVALID_REQUEST;
  }
# if (PDUR_DEV_ERROR_DETECT == STD_ON)  /* COV_PDUR_VAR_DEV_ERROR_DETECT */
#  if (PDUR_TX2LO == STD_ON)    /* COV_PDUR_VAR_DEPENDENT_SWITCH */
  else if((id >= PduR_GetSizeOfTx2Lo())
#   if (PDUR_INVALIDHNDOFTX2LO == STD_ON)
          || (PduR_IsInvalidHndOfTx2Lo(id))
#   endif
    )
  {
    errorId = PDUR_E_PDU_ID_INVALID;
  }
#  endif
# endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
# if (PDUR_CANCELTRANSMITUSEDOFTX2LO  == STD_ON)        /* COV_PDUR_VAR_DEPENDENT_SWITCH */
    if(PduR_IsCancelTransmitUsedOfTx2Lo(id))    /* COV_PDUR_FEATURE_ALWAYS_TRUE */
    {
      retVal = PduR_Rm_CancelTransmit_MultiDest(PduR_GetRmSrcRomIdxOfTx2Lo(id));
    }
# endif
  }
  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_CTX, errorId);
  }
# else
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return retVal;
}
#endif

#if ((PDUR_IFCANCELTRANSMITSUPPORTEDOFMMROM == STD_ON) || (PDUR_TPCANCELTRANSMITSUPPORTEDOFMMROM == STD_ON))
/**********************************************************************************************************************
 * PduR_Rm_CancelTransmit_MultiDest
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_Rm_CancelTransmit_MultiDest(PduR_RmSrcRomIterType rmSrcIdx)
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */

  PduR_RmDestRomIterType rmDestIdx;

  for(rmDestIdx = PduR_GetRmDestRomStartIdxOfRmSrcRom(rmSrcIdx); rmDestIdx < PduR_GetRmDestRomEndIdxOfRmSrcRom(rmSrcIdx); rmDestIdx++)
  {
# if (PDUR_RPGROM == STD_ON)
    if((!PduR_IsRmDestRpgRomUsedOfRmDestRom(rmDestIdx)) || (0u != PduR_GetEnabledCntOfRmDestRpgRam(PduR_GetRmDestRpgRomIdxOfRmDestRom(rmDestIdx))))
# endif
    {
      switch (PduR_GetRoutingTypeOfRmDestRom(rmDestIdx))
      {
# if ((PDUR_EXISTS_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON) && (PDUR_IFCANCELTRANSMITSUPPORTEDOFMMROM == STD_ON))
        case PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM:
          if(PduR_IsIfCancelTransmitSupportedOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(PduR_GetRmGDestRomIdxOfRmDestRom(rmDestIdx))))        /* COV_PDUR_FEATURE_ALWAYS_TRUE */
          {
            retVal &= PduR_RmIf_MultipleSourceHandler_CancelTransmit(rmDestIdx);
          }
          break;
# endif
# if ((PDUR_EXISTS_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON) && (PDUR_TPCANCELTRANSMITSUPPORTEDOFMMROM == STD_ON))
        case PDUR_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM:
          if(PduR_IsTpCancelTransmitSupportedOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(PduR_GetRmGDestRomIdxOfRmDestRom(rmDestIdx))))        /* COV_PDUR_FEATURE_ALWAYS_TRUE */
          {
            retVal &= PduR_RmTp_MultipleSourceHandler_CancelTransmit(rmDestIdx);
          }
          break;
# endif
        default:       /* COV_PDUR_MISRA */
          /* Nothing to do: This should never be reached */
          break;
      }
    }
  }

  PDUR_DUMMY_STATEMENT(rmSrcIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return retVal;
}
#endif

/**********************************************************************************************************************
 * PduR_Init
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
FUNC(void, PDUR_CODE) PduR_Init(P2CONST(PduR_PBConfigType, AUTOMATIC, PDUR_PBCFG) ConfigPtr)
{
/* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if(PduR_IsInitialized() == TRUE)
  {
    errorId = PDUR_E_ALREADY_INITIALIZED;
  }
  else
  {
#if(PDUR_USE_INIT_POINTER == STD_ON)
    PduR_ConfigDataPtr = ConfigPtr;
    if(PduR_ConfigDataPtr == NULL_PTR)
    {
# if(PDUR_USE_ECUM_BSW_ERROR_HOOK == STD_ON)    /* COV_PDUR_VAR_DEPENDENT_SWITCH */
      EcuM_BswErrorHook(PDUR_MODULE_ID, ECUM_BSWERROR_NULLPTR);
# endif
      errorId = PDUR_E_NULL_POINTER;
    }
# if (PDUR_FINALMAGICNUMBER == STD_ON)  /* COV_PDUR_VAR_DEPENDENT_SWITCH */
    else if(PduR_GetFinalMagicNumber() != PDUR_FINAL_MAGIC_NUMBER)
    {
#  if(PDUR_USE_ECUM_BSW_ERROR_HOOK == STD_ON)   /* COV_PDUR_VAR_DEPENDENT_SWITCH */
      EcuM_BswErrorHook(PDUR_MODULE_ID, ECUM_BSWERROR_MAGICNUMBER);
#  endif
      errorId = PDUR_E_INIT_FAILED;
      PduR_ConfigDataPtr = (const PduR_PBConfigType *) NULL_PTR;
    }
    else
    {
      /* nothing to do */
    }
# endif
#else
    if(ConfigPtr != NULL_PTR)
    {
      errorId = PDUR_E_INIT_FAILED;
    }
#endif
    if(errorId == PDUR_E_NO_ERROR)
    {
#if(PDUR_RPGROM == STD_ON)
      PduR_Init_RmDestRpgRom();
#endif
#if(PDUR_RMGDESTNTO1INFORAMIDXOFRMGDESTROM == STD_ON)
      PduR_Rm_MultipleSourceHandler_Init();
#endif

#if(PDUR_BMTXBUFFERRAM == STD_ON)
      PduR_Bm_Init();
#endif

#if(PDUR_FMFIFORAM == STD_ON)
      PduR_Fm_Init();
#endif

#if (PDUR_SMDATAPLANEROM == STD_ON)
      PduR_Sm_Init();
#endif

#if (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
      PduR_RmIf_Init_FiFoRoutingState();
#endif
#if (PDUR_DEDICATEDTXBUFFEROFRMBUFFEREDIFPROPERTIESROM == STD_ON)
      PduR_RmIf_Init_DedicatedTxBuffer();
#endif
#if(PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON)
      PduR_RmIf_Init_TTSingleBuffer();
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
      PduR_RmTp_Init();
#endif

#if (PDUR_DEDICATEDTXBUFFEROFRMBUFFEREDTPPROPERTIESROM == STD_ON)
      PduR_RmTp_Init_DedicatedTxBuffer();
#endif

#if(PDUR_MCQBUFFERROM == STD_ON)
      PduR_McQ_Init();
#endif

#if (PDUR_DEFERREDEVENTCACHEROM == STD_ON)
      PduR_EvC_Init();
#endif

#if (PDUR_SPINLOCKRAM == STD_ON)
      PduR_Lock_Init();
#endif

      PduR_SetInitialized(TRUE);        /* SBSW_PDUR_CSL_VAR_ACCESS */
    }
  }
  /* ----- Development Error Report --------------------------------------- */
#if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_INIT, errorId);
  }
#else
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
#endif
}       /* End of PduR_Init() */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

#if (PDUR_MAIN_FUNCTION == STD_ON)
/**********************************************************************************************************************
  PduR_MainFunction
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
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_MainFunction(void)
{
# if(PDUR_MULTICORE == STD_ON)
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
# endif
  /* If PduR is initialized */
  if(PduR_IsInitialized())
  {
# if (PDUR_DEFERREDEVENTCACHEROM == STD_ON)
    boolean processAllDestinations;
# endif
    PduR_CoreManagerRomIterType coreManagerRomIdx = 0;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
# if(PDUR_MULTICORE == STD_ON)
    PduR_CoreId2CoreManagerRomIterType coreId = (PduR_CoreId2CoreManagerRomIterType) GetCoreID();
    coreManagerRomIdx = PduR_GetCoreManagerRomIdxOfCoreId2CoreManagerRom(coreId); /* PRQA S 2842 */ /* MD_PduR_2842 */
#  if (PDUR_DEV_ERROR_DETECT == STD_ON) /* COV_PDUR_VAR_DEV_ERROR_DETECT */
    if(coreId >= PduR_GetSizeOfCoreId2CoreManagerRom())
    {
      errorId = PDUR_E_INVALID_CORE_ID;
    }else
#   if(PDUR_INVALIDHNDOFCOREID2COREMANAGERROM == STD_ON)
    if(PduR_IsInvalidHndOfCoreId2CoreManagerRom(coreId))
    {
      errorId = PDUR_E_INVALID_CORE_ID;
    }else
#   endif
#  endif
# endif
    {
# if ((PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON) || (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON))
#  if (PDUR_DEFERREDEVENTCACHEROM == STD_ON)
      {
        PduR_SrcCoreRomEndIdxOfCoreManagerRomType srcCoreRomIdx;
        boolean anyEventQueueHasOverflown = FALSE;

        /* Check if any event queue has overflown */
        for(srcCoreRomIdx = PduR_GetSrcCoreRomStartIdxOfCoreManagerRom(coreManagerRomIdx); srcCoreRomIdx < PduR_GetSrcCoreRomEndIdxOfCoreManagerRom(coreManagerRomIdx); srcCoreRomIdx++)
        {
          boolean isEvCFull = PduR_EvC_IsFull(PduR_GetDeferredEventCacheRomIdxOfSrcCoreRom(srcCoreRomIdx));
          anyEventQueueHasOverflown = anyEventQueueHasOverflown | isEvCFull;
        }
        processAllDestinations = anyEventQueueHasOverflown;

        /* In case of an overflown event queue, flush all queues and apply fallback strategy to process all destinations */
        if(processAllDestinations == TRUE)
        {
          /* Flush Queues */
          for(srcCoreRomIdx = PduR_GetSrcCoreRomStartIdxOfCoreManagerRom(coreManagerRomIdx); srcCoreRomIdx < PduR_GetSrcCoreRomEndIdxOfCoreManagerRom(coreManagerRomIdx); srcCoreRomIdx++)
          {
            PduR_EvC_ReadFlush(PduR_GetDeferredEventCacheRomIdxOfSrcCoreRom(srcCoreRomIdx));
          }
        }
        /* Otherwise, process deferred event cache and call the corresponding Mainfunction */
        else
        {
          for(srcCoreRomIdx = PduR_GetSrcCoreRomStartIdxOfCoreManagerRom(coreManagerRomIdx); srcCoreRomIdx < PduR_GetSrcCoreRomEndIdxOfCoreManagerRom(coreManagerRomIdx); srcCoreRomIdx++)
          {
            PduR_RmGDestRomIterType rmGDestRomIdx;
            PduR_DeferredEventCacheRomIdxOfSrcCoreRomType deferredEventCacheRomIdx = PduR_GetDeferredEventCacheRomIdxOfSrcCoreRom(srcCoreRomIdx);
            PduR_DeferredEventCacheArrayRamLengthOfDeferredEventCacheRomType readLimit = PduR_GetDeferredEventCacheArrayRamLengthOfDeferredEventCacheRom(deferredEventCacheRomIdx);

            while(PduR_EvC_Get(deferredEventCacheRomIdx, &rmGDestRomIdx) == E_OK)       /* SBSW_PDUR_STACK_VARIABLE */
            {
              PduR_DispatchMainfuntion(rmGDestRomIdx);
              readLimit--;
              if(readLimit == 0u)       /* COV_PDUR_DEFERRED_EVENT_CACHE_READLIMIT */
              {
                break;
              }
            }
          }
        }
      }
#  endif

#  if (PDUR_DEFERREDEVENTCACHEROM == STD_ON)
      if(processAllDestinations == TRUE)
#  endif
      {
        PduR_MmRomIndIterType mmIndIdx;
        for(mmIndIdx = PduR_GetMmRomIndStartIdxOfCoreManagerRom(coreManagerRomIdx); mmIndIdx < PduR_GetMmRomIndEndIdxOfCoreManagerRom(coreManagerRomIdx); mmIndIdx++)
        {
          PduR_MmRomIterType mmIdx = PduR_GetMmRomInd(mmIndIdx);

          PduR_RmGDestRomIterType rmGDestRomIdx;
          for(rmGDestRomIdx = PduR_GetRmGDestRomStartIdxOfMmRom(mmIdx); rmGDestRomIdx < PduR_GetRmGDestRomEndIdxOfMmRom(mmIdx); rmGDestRomIdx++)
          {
            PduR_DispatchMainfuntion(rmGDestRomIdx);
          }
        }
      }
# endif

# if (PDUR_MCQBUFFERROM == STD_ON)
      /* Process deferred If Pdus which are handled by the multicore queue in context of cyclic MainFunction */
      PduR_McQ_MainFunction((PduR_CoreManagerRomIdxOfMmRomType) coreManagerRomIdx);
# endif
    }
  }

# if(PDUR_MULTICORE == STD_ON)
  /* ----- Development Error Report --------------------------------------- */
#  if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_MAINFUNCTION_TX, errorId);
  }
#  else
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
#  endif
# endif
}       /* PRQA S 6030, 6050, 6080, 6010 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF, MD_MSR_STPTH */
#endif

#if(PDUR_RPGROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Init_RmDestRpgRom
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Init_RmDestRpgRom(void)
{
  {
    PduR_RmDestRpgRomIterType rmDestRpgRomIdx;
    for(rmDestRpgRomIdx = 0u; rmDestRpgRomIdx < PduR_GetSizeOfRmDestRpgRom(); rmDestRpgRomIdx++)
    {
      PduR_SetEnabledCntOfRmDestRpgRam(rmDestRpgRomIdx, PduR_GetInitialEnabledCntOfRmDestRpgRom(rmDestRpgRomIdx));      /* SBSW_PDUR_CSL01 */
    }
  }
  {
    PduR_RpgRamIterType rpgIdx;
    for(rpgIdx = 0u; rpgIdx < PduR_GetSizeOfRpgRam(); rpgIdx++)
    {
      PduR_SetEnabledOfRpgRam(rpgIdx, PduR_IsEnabledAtInitOfRpgRom(rpgIdx));    /* SBSW_PDUR_CSL01 */ /* PRQA S 2995, 2996 */ /* MD_PduR_2995_2996 */
    }
  }
}
#endif

#if(PDUR_RMGDESTNTO1INFORAMIDXOFRMGDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Rm_MultipleSourceHandler_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Rm_MultipleSourceHandler_Init(void)
{
  PduR_RmGDestRomIterType rmGDestRomIdx;
  for(rmGDestRomIdx = 0u; rmGDestRomIdx < PduR_GetSizeOfRmGDestRom(); rmGDestRomIdx++)
  {
    PduR_Rm_MultipleSourceHandler_Reset(rmGDestRomIdx);
  }
}
#endif

/**********************************************************************************************************************
 * PduR_Rm_GetSrcDestPdu
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_Rm_GetSrcDestPdu(PduR_RmGDestRomIterType rmGDestRomIdx, P2VAR(PduR_RmDestRomIterType, AUTOMATIC, PDUR_APPL_DATA) rmDestRomIdx)
{
  Std_ReturnType retVal = E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

#if(PDUR_RMGDESTNTO1INFORAMIDXOFRMGDESTROM == STD_ON)
  if(PduR_IsRmGDestNto1InfoRamUsedOfRmGDestRom(rmGDestRomIdx))  /* COV_PDUR_NTO1_NO_BUFFER_GW_ONLY_ROUTINGPATHS */
  {
    PduR_RmDestRomIterType localRmDestRomIdx = PduR_GetRmDestRomIdxOfRmGDestNto1InfoRam(PduR_GetRmGDestNto1InfoRamIdxOfRmGDestRom(rmGDestRomIdx));
    if(localRmDestRomIdx != PDUR_NO_RMDESTROMIDXOFRMGDESTNTO1INFORAM)   /* COV_PDUR_NTO1_NO_BUFFER_GW_ONLY_ROUTINGPATHS */
    {
      *rmDestRomIdx = localRmDestRomIdx;        /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
    }
    else
    {
      retVal = E_NOT_OK;
    }
  }
  else
#endif
  {
    *rmDestRomIdx = PduR_GetRmDestRomIdxOfRmGDestRom(rmGDestRomIdx);    /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
  }

  return retVal;
}

#if(PDUR_RMGDESTNTO1INFORAMIDXOFRMGDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Rm_MultipleSourceHandler_Reset
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Rm_MultipleSourceHandler_Reset(PduR_RmGDestRomIterType rmGDestRomIdx)
{
  if(PduR_IsRmGDestNto1InfoRamUsedOfRmGDestRom(rmGDestRomIdx))
  {
    PduR_RmGDestNto1InfoRamIdxOfRmGDestRomType rmGDestNto1InfoIdx = PduR_GetRmGDestNto1InfoRamIdxOfRmGDestRom(rmGDestRomIdx);

    PduR_SetTransmissionActiveOfRmGDestNto1InfoRam(rmGDestNto1InfoIdx, FALSE);  /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
    PduR_SetRmDestRomIdxOfRmGDestNto1InfoRam(rmGDestNto1InfoIdx, PDUR_NO_RMDESTROMIDXOFRMGDESTNTO1INFORAM);     /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
}
#endif

/**********************************************************************************************************************
 * PduR_InitMemory
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_InitMemory(void)
{
  PduR_SetInitialized(FALSE);   /* SBSW_PDUR_CSL_VAR_ACCESS */
#if(PDUR_USE_INIT_POINTER == STD_ON)
  PduR_ConfigDataPtr = (P2CONST(PduR_PBConfigType, PDUR_VAR_ZERO_INIT, PDUR_PBCFG)) NULL_PTR;
#endif
}       /* End of PduR_InitMemory() */

#if (PDUR_RPGROM == STD_ON)
/**********************************************************************************************************************
 * PduR_EnableRouting
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_EnableRouting(PduR_RoutingPathGroupIdType id)
{
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  /* ----- Development Error Checks ------------------------------------- */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_UNINIT;
  }
# if (PDUR_DEV_ERROR_DETECT == STD_ON)  /* COV_PDUR_VAR_DEV_ERROR_DETECT */
  else if(id >= PduR_GetSizeOfRpgRom())
  {
    errorId = PDUR_E_ROUTING_PATH_GROUP_ID_INVALID;
  }
#  if(PDUR_INVALIDHNDOFRPGROM == STD_ON)
  else if(PduR_IsInvalidHndOfRpgRom(id))
  {
    errorId = PDUR_E_ROUTING_PATH_GROUP_ID_INVALID;
  }
#  endif
# endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    if(!PduR_IsEnabledOfRpgRam(id))
    {
      PduR_RmDestRpgRomIndIterType rmDestRpgRomIndIdx;
      for(rmDestRpgRomIndIdx = PduR_GetRmDestRpgRomIndStartIdxOfRpgRom(id); rmDestRpgRomIndIdx < PduR_GetRmDestRpgRomIndEndIdxOfRpgRom(id); rmDestRpgRomIndIdx++)
      {
        PduR_RmDestRpgRomIndType rmDestRpgRomIdx = PduR_GetRmDestRpgRomInd(rmDestRpgRomIndIdx);
        PduR_RmDestRomIterType rmDestRomIdx = PduR_GetRmDestRomIdxOfRmDestRpgRom(rmDestRpgRomIdx);
        PduR_Lock_LockRoutingPathByDestPdu(rmDestRomIdx);
        {
          PduR_SetEnabledCntOfRmDestRpgRam(rmDestRpgRomIdx, PduR_GetEnabledCntOfRmDestRpgRam(rmDestRpgRomIdx) + 1u);    /* SBSW_PDUR_CSL03 */
        }
        PduR_Lock_UnlockRoutingPathByDestPdu(rmDestRomIdx);
      }
      PduR_SetEnabledOfRpgRam(id, TRUE);        /* SBSW_PDUR_CSL01 */
    }
  }
  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_ENABLEROUTING, errorId);
  }
# else
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif
}       /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#if (PDUR_RPGROM == STD_ON)
/**********************************************************************************************************************
 * PduR_DisableRouting
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_DisableRouting(PduR_RoutingPathGroupIdType id)
{
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  /* ----- Development Error Checks ------------------------------------- */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_UNINIT;
  }
# if (PDUR_DEV_ERROR_DETECT == STD_ON)  /* COV_PDUR_VAR_DEV_ERROR_DETECT */
  else if(id >= PduR_GetSizeOfRpgRom())
  {
    errorId = PDUR_E_ROUTING_PATH_GROUP_ID_INVALID;
  }
#  if(PDUR_INVALIDHNDOFRPGROM == STD_ON)
  else if(PduR_IsInvalidHndOfRpgRom(id))
  {
    errorId = PDUR_E_ROUTING_PATH_GROUP_ID_INVALID;
  }
#  endif
# endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    if(PduR_IsEnabledOfRpgRam(id))
    {
      PduR_RmDestRpgRomIndIterType rmDestRpgRomIndIdx;
      for(rmDestRpgRomIndIdx = PduR_GetRmDestRpgRomIndStartIdxOfRpgRom(id); rmDestRpgRomIndIdx < PduR_GetRmDestRpgRomIndEndIdxOfRpgRom(id); rmDestRpgRomIndIdx++)
      {
        PduR_RmDestRpgRomIndType rmDestRpgRomInd = PduR_GetRmDestRpgRomInd(rmDestRpgRomIndIdx);
        PduR_RmDestRomIterType rmDestRomIdx = PduR_GetRmDestRomIdxOfRmDestRpgRom(rmDestRpgRomInd);
        PduR_Lock_LockRoutingPathByDestPdu(rmDestRomIdx);
        {
# if (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
          if(PDUR_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == PduR_GetRoutingTypeOfRmDestRom(rmDestRomIdx))   /* COV_PDUR_FEATURE_ALWAYS_TRUE */
          {
            PduR_DisableIfRoutingAction(rmDestRomIdx);
          }
# endif
# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
          if(PDUR_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == PduR_GetRoutingTypeOfRmDestRom(rmDestRomIdx))
          {
            PduR_RmGDestRomIterType rmGDestRomIdx = PduR_GetRmGDestRomIdxOfRmDestRom(PduR_GetRmDestRomIdxOfRmDestRpgRom(rmDestRpgRomInd));
            PduR_FmFifoRomIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx));
            PduR_FmFifoElementRamIterType fmFifoElementRamTPReadIdx = PduR_GetFmFifoElementRamReadIdxOfFmFifoRam(fmFifoRomIdx);
            PduR_StateOfFmFifoElementRamType fifoSmState = PduR_GetStateOfFmFifoElementRam(fmFifoElementRamTPReadIdx);

            PduR_GetFctPtrOfFm_TpDisableRouting_FmSmStateHandler(fifoSmState) (rmGDestRomIdx);  /* SBSW_PDUR_CSL03 */
          }
# endif
          PduR_SetEnabledCntOfRmDestRpgRam(rmDestRpgRomInd, (PduR_GetEnabledCntOfRmDestRpgRam(rmDestRpgRomInd) - 1u));  /* SBSW_PDUR_CSL03 */
        }
        PduR_Lock_UnlockRoutingPathByDestPdu(rmDestRomIdx);
      }
      PduR_SetEnabledOfRpgRam(id, FALSE);       /* SBSW_PDUR_CSL01 */
    }
  }
  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_DISABLEROUTING, errorId);
  }
# else
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif
}       /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#if ((PDUR_RPGROM == STD_ON) && (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_DisableIfRoutingAction
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_DisableIfRoutingAction(PduR_RmDestRomIterType rmDestRomIdx)
{
  PduR_RmGDestRomIterType rmGDestIdx = PduR_GetRmGDestRomIdxOfRmDestRom(rmDestRomIdx);
# if ((PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
  if(PduR_IsFmFifoInstanceRomUsedOfRmGDestRom(rmGDestIdx))      /* COV_PDUR_FEATURE_ALWAYS_TRUE */
  {
    PduR_RmBufferedIfPropertiesRomIdxOfRmGDestRomType rmBufferedIfPropertiesRomIdx = PduR_GetRmBufferedIfPropertiesRomIdxOfRmGDestRom(rmGDestIdx);

    if(PduR_GetFillLevelOfFmFifoRam(PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestIdx))) > 0u)
    {
      PduR_Fm_FlushFiFo(rmGDestIdx);
    }
    PduR_SetIfSmStateOfRmBufferedIfPropertiesRam(rmBufferedIfPropertiesRomIdx, PduR_GetNextState_For_Init_If_Routing_StateOfIfRoutingStateTable(PduR_GetFifoTypeOfRmBufferedIfPropertiesRom(rmBufferedIfPropertiesRomIdx)));    /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
# endif
# if(PDUR_RMGDESTNTO1INFORAMIDXOFRMGDESTROM == STD_ON)
  PduR_Rm_MultipleSourceHandler_Reset(rmGDestIdx);
# endif
  PDUR_DUMMY_STATEMENT(rmGDestIdx);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if ((PDUR_MAIN_FUNCTION == STD_ON) && ((PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON) || (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)))
/**********************************************************************************************************************
 * PduR_DispatchMainfuntion
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_DispatchMainfuntion(PduR_RmGDestRomIterType rmGDestRomIdx)
{
# if(PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
  if(PduR_IsRmBufferedIfPropertiesRomUsedOfRmGDestRom(rmGDestRomIdx))   /* COV_PDUR_FEATURE_ALWAYS_TRUE */
  {
    PduR_RmIf_MainFunction(rmGDestRomIdx);
  }
# endif
# if(PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
  if(PduR_IsRmGDestTpTxStateRamUsedOfRmGDestRom(rmGDestRomIdx))
  {
    PduR_RmTp_TxInst_MainFunction(rmGDestRomIdx);
  }
# endif
}
#endif

#if (PDUR_DEFERREDEVENTCACHEROM == STD_ON)
/**********************************************************************************************************************
 * PduR_EvC_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_EvC_Init(void)
{
  PduR_DeferredEventCacheRomIterType deferredEventCacheRomIdx;
  for(deferredEventCacheRomIdx = 0u; deferredEventCacheRomIdx < PduR_GetSizeOfDeferredEventCacheRom(); deferredEventCacheRomIdx++)
  {
    PduR_DeferredEventCacheArrayRamStartIdxOfDeferredEventCacheRomType startIdxOfBuffer = PduR_GetDeferredEventCacheArrayRamStartIdxOfDeferredEventCacheRom(deferredEventCacheRomIdx);

    PduR_SetDeferredEventCacheArrayRamReadIdxOfDeferredEventCacheRam(deferredEventCacheRomIdx, startIdxOfBuffer);       /* SBSW_PDUR_CSL02 */
    PduR_SetDeferredEventCacheArrayRamWriteIdxOfDeferredEventCacheRam(deferredEventCacheRomIdx, startIdxOfBuffer);      /* SBSW_PDUR_CSL02 */
  }
}
#endif

#if (PDUR_DEFERREDEVENTCACHEROM == STD_ON)
/**********************************************************************************************************************
 * PduR_EvC_Put
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
FUNC(Std_ReturnType, PDUR_CODE) PduR_EvC_Put(PduR_DeferredEventCacheRomIdxOfSrcCoreRomType deferredEventCacheIdx, PduR_RmGDestRomIterType rmGDestRomIdx)
{
  Std_ReturnType retVal = E_NOT_OK;

  SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
  {
    PduR_DeferredEventCacheArrayRamReadIdxOfDeferredEventCacheRamType readIdx = PduR_GetDeferredEventCacheArrayRamReadIdxOfDeferredEventCacheRam(deferredEventCacheIdx);
    PduR_DeferredEventCacheArrayRamWriteIdxOfDeferredEventCacheRamType writeIdx = PduR_GetDeferredEventCacheArrayRamWriteIdxOfDeferredEventCacheRam(deferredEventCacheIdx);

    if(writeIdx < PduR_GetSizeOfDeferredEventCacheArrayRam())   /* COV_PDUR_VAR_FATAL_ERROR */
    {
      PduR_DeferredEventCacheArrayRamStartIdxOfDeferredEventCacheRomType startIdxOfBuffer = PduR_GetDeferredEventCacheArrayRamStartIdxOfDeferredEventCacheRom(deferredEventCacheIdx);
      PduR_DeferredEventCacheArrayRamEndIdxOfDeferredEventCacheRomType endIdxOfBuffer = PduR_GetDeferredEventCacheArrayRamEndIdxOfDeferredEventCacheRom(deferredEventCacheIdx) - 1u;    /* ComStackLibs EndIdx is actually the first out of bounds index */

      /* If event cache is full, return E_NOT_OK */
      if(PduR_EvC_IsFull(deferredEventCacheIdx) == TRUE)
      {
        /* Buffer is full */
        retVal = E_NOT_OK;
      }
      /* else if write index < read index, put rmGDestRomIdx into cache and increase write idx */
      else if(writeIdx < readIdx)       /* write is possible until read Idx is reached. Could be too small though */
      {
        PduR_SetRmGDestRomIdxOfDeferredEventCacheArrayRam(writeIdx, (PduR_RmGDestRomIdxOfDeferredEventCacheArrayRamType) rmGDestRomIdx);        /* SBSW_PDUR_EVC_PUT_RTCHECK */
        PduR_SetDeferredEventCacheArrayRamWriteIdxOfDeferredEventCacheRam(deferredEventCacheIdx, writeIdx + 1u);        /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
        retVal = E_OK;
      }
      /* else */
      else
      { /* readIdx < writeIdx OR readIdx == writeIdx */
        /* put rmGDestRomIdx into cache */
        PduR_SetRmGDestRomIdxOfDeferredEventCacheArrayRam(writeIdx, (PduR_RmGDestRomIdxOfDeferredEventCacheArrayRamType) rmGDestRomIdx);        /* SBSW_PDUR_EVC_PUT_RTCHECK */

        /* Wrap around write index if required or increase write index otherwise */
        if(writeIdx == endIdxOfBuffer)
        {
          PduR_SetDeferredEventCacheArrayRamWriteIdxOfDeferredEventCacheRam(deferredEventCacheIdx, startIdxOfBuffer);   /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
        }
        else
        {
          PduR_SetDeferredEventCacheArrayRamWriteIdxOfDeferredEventCacheRam(deferredEventCacheIdx, writeIdx + 1u);      /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
        }
        retVal = E_OK;
      }
    }
    else
    {
      PduR_Det_ReportError(PDUR_EVC_PUT, PDUR_E_FATAL);
    }
  }
  SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();

  return retVal;
}
#endif

#if (PDUR_DEFERREDEVENTCACHEROM == STD_ON)
/**********************************************************************************************************************
 * PduR_EvC_Get
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
FUNC(Std_ReturnType, PDUR_CODE) PduR_EvC_Get(PduR_DeferredEventCacheRomIdxOfSrcCoreRomType deferredEventCacheIdx, P2VAR(PduR_RmGDestRomIterType, AUTOMATIC, PDUR_APPL_DATA) rmGDestRomIdxPtr)
{
  Std_ReturnType retVal;

  SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
  {
    PduR_DeferredEventCacheArrayRamReadIdxOfDeferredEventCacheRamType readIdx = PduR_GetDeferredEventCacheArrayRamReadIdxOfDeferredEventCacheRam(deferredEventCacheIdx);
    PduR_DeferredEventCacheArrayRamWriteIdxOfDeferredEventCacheRamType writeIdx = PduR_GetDeferredEventCacheArrayRamWriteIdxOfDeferredEventCacheRam(deferredEventCacheIdx);

    /* If buffer is empty, return E_NOT_OK */
    if(readIdx == writeIdx)
    {
      retVal = E_NOT_OK;
    }
    /* Otherwise */
    else
    {
      PduR_DeferredEventCacheArrayRamStartIdxOfDeferredEventCacheRomType startIdxOfBuffer = PduR_GetDeferredEventCacheArrayRamStartIdxOfDeferredEventCacheRom(deferredEventCacheIdx);
      PduR_DeferredEventCacheArrayRamEndIdxOfDeferredEventCacheRomType endIdxOfBuffer = PduR_GetDeferredEventCacheArrayRamEndIdxOfDeferredEventCacheRom(deferredEventCacheIdx) - 1u;    /* ComStackLibs EndIdx is actually the first out of bounds index */

      /* Read RmGDestRomIdx from Cache */
      *rmGDestRomIdxPtr = PduR_GetRmGDestRomIdxOfDeferredEventCacheArrayRam(readIdx);   /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */

      /* Increase read index to next element. Wrap around if required. */
      if(readIdx == endIdxOfBuffer)
      {
        PduR_SetDeferredEventCacheArrayRamReadIdxOfDeferredEventCacheRam(deferredEventCacheIdx, startIdxOfBuffer);      /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
      }
      else
      {
        PduR_SetDeferredEventCacheArrayRamReadIdxOfDeferredEventCacheRam(deferredEventCacheIdx, readIdx + 1u);  /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
      }

      /* Return E_OK */
      retVal = E_OK;
    }
  }
  SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();

  return retVal;
}
#endif

#if (PDUR_DEFERREDEVENTCACHEROM == STD_ON)
/**********************************************************************************************************************
 * PduR_EvC_ReadFlush
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_EvC_ReadFlush(PduR_DeferredEventCacheRomIdxOfSrcCoreRomType deferredEventCacheIdx)
{
  PduR_SetDeferredEventCacheArrayRamReadIdxOfDeferredEventCacheRam(deferredEventCacheIdx, PduR_GetDeferredEventCacheArrayRamWriteIdxOfDeferredEventCacheRam(deferredEventCacheIdx));    /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
}
#endif

#if (PDUR_DEFERREDEVENTCACHEROM == STD_ON)
/**********************************************************************************************************************
 * PduR_EvC_IsFull
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean, PDUR_CODE) PduR_EvC_IsFull(PduR_DeferredEventCacheRomIdxOfSrcCoreRomType deferredEventCacheIdx)
{
  boolean retVal;

  SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
  {
    PduR_DeferredEventCacheArrayRamReadIdxOfDeferredEventCacheRamType readIdx = PduR_GetDeferredEventCacheArrayRamReadIdxOfDeferredEventCacheRam(deferredEventCacheIdx);
    PduR_DeferredEventCacheArrayRamWriteIdxOfDeferredEventCacheRamType writeIdx = PduR_GetDeferredEventCacheArrayRamWriteIdxOfDeferredEventCacheRam(deferredEventCacheIdx);

    PduR_DeferredEventCacheArrayRamStartIdxOfDeferredEventCacheRomType startIdxOfBuffer = PduR_GetDeferredEventCacheArrayRamStartIdxOfDeferredEventCacheRom(deferredEventCacheIdx);
    PduR_DeferredEventCacheArrayRamEndIdxOfDeferredEventCacheRomType endIdxOfBuffer = PduR_GetDeferredEventCacheArrayRamEndIdxOfDeferredEventCacheRom(deferredEventCacheIdx) - 1u;      /* ComStackLibs EndIdx is actually the first out of bounds index */

    if(((writeIdx + 1u) == readIdx) || ((readIdx == startIdxOfBuffer) && (writeIdx == endIdxOfBuffer)))
    {
      /* Buffer is full */
      retVal = TRUE;
    }
    else
    {
      retVal = FALSE;
    }
  }
  SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();

  return retVal;
}
#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * GLOBAL MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/
/* module specific MISRA deviations:
    MD_PduR_0311:
    Reason:     Dangerous pointer cast results in loss of const qualification.
    Risk:       Write operation to ROM
    Prevention: Reviewed the complete code sequence. Only read operations are performed

  MD_PduR_1505:  Misra Rule 8.7
     Reason:      It depends on the configuration if the function is only referenced in the translation unit is is defined or not.
     Risk:        No risk.
     Prevention:  No prevention necessary.

  MD_PduR_1336: Misra Rule 8.2
     Reason:      No identifier name needed in a function pointer typedef.
     Risk:        No risk, because only warning that with a identifier name the readability is better.
     Prevention:  No prevention necessary.

  MD_PduR_2842
     Reason:      Index Access using the ComStackLib.
     Risk:        No risk, because qualified use-case CSL02 of ComStackLib.
     Prevention:  No prevention necessary.

  MD_PduR_2983: Misra Rule 2.2
     Reason:      The value is modified to be used in the next iteration. It depends on the configuration if the loop consists of more than one iteration.
     Risk:        No risk, as the assigned value is only not used subsequently.
     Prevention:  No prevention necessary.

  MD_PduR_2985: Misra Rule 2.2
     Reason:      The value of the result is only that of the left-hand operand for the first iteration. It depends on the configuration it there will be more than one iteration step.
     Risk:        No risk, as the bitwise operation is only redundant.
     Prevention:  No prevention necessary.

  MD_PduR_2995_2996: Misra Rule 2.2
     Reason:      Depending on the configuration the check might always be true or false.
     Risk:        No risk, as the evaluation of the boolean expression depends on the configuration.
     Prevention:  No prevention necessary.

  MD_PduR_2991: Misra Rule 14.3
     Reason:      The value of the if-controlling expression depends on the configuration.
     Risk:        No risk.
     Prevention:  No prevention necessary.

  MD_PduR_2880: Misra Rule 2.1
     Reason:      Code might not be reachable depending on the configuration.
     Risk:        No risk.
     Prevention:  No prevention necessary.
*/

/* *INDENT-OFF* */
/* SBSW_JUSTIFICATION_BEGIN

  \ID SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION
    \DESCRIPTION The index is passed to an internal function as parameter and is used within the function to write to a memory location.
    \COUNTERMEASURE \N The index is read by the calling function using the ComStackLib macros. The ComStackLib ensures that the index is valid.

  \ID SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION
    \DESCRIPTION A pointer is written or passed to a function. The pointer can possibly be used to write to the corresponding memory location.
    \COUNTERMEASURE \N The calling function ensures that the pointer is valid.

  \ID SBSW_PDUR_STACK_VARIABLE
    \DESCRIPTION A pointer is passed to a function. The pointer can possibly be used to write to the corresponding memory location.
    \COUNTERMEASURE \N The pointer points to a local stack variable, therefore it's always valid.

  \ID SBSW_PDUR_GETVERSION_PARAM
    \DESCRIPTION    The PduR_GetVersionInfo writes to the 'versioninfo' pointer parameter. It is checked against NULL,
                    but this does not guarantee that the referenced memory is valid.
    \COUNTERMEASURE \N  Pointers passed to public PduR APIs point to a valid memory range. A general countermeasure is included in the safety manual.

  \ID SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR
    \DESCRIPTION    The API is called with an Id and a pointer.
                    The API call is forwarded using a function pointer which is read using ComStackLib macros.

    \COUNTERMEASURE \N The function pointer is read using the passed Id and ComStackLib macros.
                       The Id is a SNV provided by the lower layer. It is checked when it was first passed to the PduR module.
                       The pointer is either forwarded and assumed to be valid or it is a local stack variable.

  \ID SBSW_PDUR_API_CALL_FORWARDING_ID_ONLY
    \DESCRIPTION    The API is called with an Id.
                    The API call is forwarded using a function pointer which is read using ComStackLib macros.
    \COUNTERMEASURE \R The function pointer is read using the passed Id and ComStackLib macros.
                       The Id is a SNV provided by the lower layer.
                       It is checked when it was first passed to the PduR module.

  \ID SBSW_PDUR_MEM_CPY_FIFOMGR
    \DESCRIPTION Call to copy RAM data to RAM
    \COUNTERMEASURE \N The passed pointers are either read by ComStackLib macros or are passed through and checked by one of the calling functions.
                       The size of the copy operation is always equal or less than the size of the destination buffer. This is ensured by the calling function.

  \ID SBSW_PDUR_MEM_CPY_RAM2RAM
    \DESCRIPTION Call to copy RAM data to RAM
    \COUNTERMEASURE \R The passed pointers are either read by ComStackLib macros or are passed through and checked by one of the calling functions.
                    \R The size of the copy operation is checked against the remaining free buffer space.

  \ID SBSW_PDUR_WRITE_TRANSMIT_OR_INDICATION_QUEUE
    \DESCRIPTION Data is written into the indication or transmit queue.
    \COUNTERMEASURE \R The passed index will always be within range of the indication or transmit queue as it is caluclated considering the length of the queue.

  \ID SBSW_PDUR_CORE_ID_RTCHECK
    \DESCRIPTION Array write access. Core Id is retrieved over OS API and respective counter is modified.
    \COUNTERMEASURE  \R Runtime check assures, core Id is always within the bounds of counter array.

  \ID SBSW_PDUR_MCQ_RAMARRAY_RTCHECK
    \DESCRIPTION Array write access. Write Idx is calculated from caller.
    \COUNTERMEASURE  \R Runtime check assures, write idx is always within the bound of the RamArray.

  \ID SBSW_PDUR_MCQ_RAMARRAY_RTCHECK_FCTCALL
    \DESCRIPTION The address of the provided destination pointer is retrieved via CSL Macros. Source pointer is only read.
    \COUNTERMEASURE  \R Runtime check assures, that the destination has enough space to store the data.

  \ID SBSW_PDUR_EVC_PUT_RTCHECK
    \DESCRIPTION Array write access. Write Idx is read from Ram.
    \COUNTERMEASURE  \R Runtime check assures, write idx is always within the bounds.

  \ID SBSW_PDUR_FCT_CALL_P2CONST
    \DESCRIPTION Function call with constant P2CONST / CONSTP2CONST.
    \COUNTERMEASURE  \N The function is call with pointer for reading purpose only. Content of pointer is not modified.

  \ID SBSW_PDUR_CSL01
    \DESCRIPTION Index Access is using ComStackLib
    \COUNTERMEASURE  \N Qualified use-case CSL01 of ComStackLib.

  \ID SBSW_PDUR_CSL02
    \DESCRIPTION  Access of Table1, via indirection over Table2
                  with same index using ComStackLib.
    \COUNTERMEASURE \N Qualified use-case CSL02 of ComStackLib

  \ID SBSW_PDUR_CSL03
    \DESCRIPTION Access to Table1 via indirection over Table2.
    \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_PDUR_CSL_VAR_ACCESS
    \DESCRIPTION A ComStackLib generated variable is accessed.
    \COUNTERMEASURE \N The variable is written using a generated macro of the CSL. It immediately dereferences the variables address without pointer arithmetic.

  SBSW_JUSTIFICATION_END */

/*
  SBSW_PDUR_CSL01 Boundary check using generated identifiers:
  Table1 -- Size of the table itself

  SBSW_PDUR_CSL02 Arrays of same size:
  Table1 -- SizeRelation --> Table2

  SBSW_PDUR_CSL03: Usage of modelled indirections:
  Table1 -- Key Size Relation --> Table2
*/

/* COV_JUSTIFICATION_BEGIN
  \ID COV_PDUR_FEATURE_ALWAYS_TRUE
    \ACCEPT TX
    \ACCEPT TF tx tf
    \ACCEPT TF tf xf
    \ACCEPT TF tf tf tf xf
    \ACCEPT TF tf tx
    \ACCEPT XF tf xf
    \ACCEPT TX tx tx
    \REASON Depending on the configuration the feature check can always be true. In this case the compiler removes the check.

  \ID COV_PDUR_NO_DEFERRED_TP_ROUTING
    \ACCEPT X
    \REASON Function is never covered in configurations without deferred Tp routing paths. The function is always referenced by a function pointer.

  \ID COV_PDUR_CROSSCORE_ROUTINGS_ONLY
    \ACCEPT TF tx tf
    \ACCEPT TX
    \ACCEPT XF
    \ACCEPT X
    \REASON Condition can't be covered in configurations with only cross-core routing paths.

  \ID COV_PDUR_ONLY_DIRECT_BUFFER
    \ACCEPT TX
    \REASON In configurations with only direct buffers this is always true. Buffer can't run out in the WAIT_FOR_RXINDICATION state as there always will be the shadow buffer.

  \ID COV_PDUR_ONLY_TT_SINGLE_BUFFER
    \ACCEPT XX
    \ACCEPT X
    \REASON The code can't be covered in configurations where only trigger transmit single buffer are used. The buffer is never empty and can't be flushed.

  \ID COV_PDUR_ONLY_SHARED_OR_DEDICATED_BUFFER
    \ACCEPT TX
    \ACCEPT XF
    \ACCEPT XX
    \REASON This configuration has only shared or dedicated buffer.

  \ID COV_PDUR_NO_RP_WITH_MIXED_RPG
    \ACCEPT TX
    \REASON This condition is always true if only routing paths exist which destinations are assigned to none or the same routing path group.

  \ID COV_PDUR_NO_NTO1_ROUTINGPATHS
    \ACCEPT TX
    \REASON This condition is always true if no N:1 routing paths were configured.

  \ID COV_PDUR_NTO1_GW_ONLY_ROUTINGPATHS
    \ACCEPT TX
    \REASON This condition is always true if there are only N:1 gateway only routing paths configured.

  \ID COV_PDUR_NTO1_NO_BUFFER_GW_ONLY_ROUTINGPATHS
    \ACCEPT XF
    \ACCEPT XX
    \REASON This condition is never true if only no buffer gateway only N:1 routing paths exist.

  \ID COV_PDUR_RPG_FEATURE_CHECK
    \ACCEPT TF xf tf
    \ACCEPT TF tx tf
    \ACCEPT TX tf tx
    \REASON For postbuild configurations the feature has a runtime feature check. For none-postbuild configurations with routing path groups the first condition is always false.

  \ID COV_PDUR_RPG_FWD_CHECK
    \ACCEPT TF xf tf
    \ACCEPT TF tx tf
    \ACCEPT TX xf tx
    \REASON For postbuild configurations the feature has a runtime feature check. For none-postbuild configurations with routing path groups the first condition is always false.
            For gateway only configurations the last condition is always true as this conditions only checks the RPG status of API forwarding routing paths.

  \ID COV_PDUR_CONDITIONAL_DEPENDENCE
    \ACCEPT TF tf tf tx
    \ACCEPT TF tf tx tf
    \REASON The conditions are not independent due to short-circuit evaluation.

  \ID COV_PDUR_MISRA
    \ACCEPT X
    \ACCEPT TX
    \REASON [MSR_COV_MISRA]

  \ID COV_PDUR_IF_SDU_LENGTH_HANDLING
    \ACCEPT TX
    \ACCEPT XF
    \ACCEPT XX
    \REASON  If the provided length is greater than the maximum buffer size the value is truncated to this value. Therefore the code code not be reached in case of communication interface routing.

  \ID COV_PDUR_TX_BUFFER_USED
    \ACCEPT TX
    \REASON This statement could only reach in case of transport protocol routing. In case of a communication interface routing the buffer is always used because each destination has its own buffer.

  \ID COV_PDUR_TP_ONLY
   \ACCEPT X
   \REASON This function is only called in case of transport protocol routing. But it is active because of the Routing manager API are shared between transport protocol and communication interface.

  \ID COV_PDUR_IF_ONLY
   \ACCEPT X
   \ACCEPT XX
   \REASON This function is only called if buffered transport protocol routing paths exist. This is not the case for communication interface only configurations.

  \ID COV_PDUR_BUFFER_CALCULATION
   \ACCEPT X
   \REASON This function is not called in the context of this state. It still exists to have a correct and complete calculation function.

  \ID COV_PDUR_SINGLE_INSTANCE
   \ACCEPT TX
   \ACCEPT TF tf tx
   \REASON This statement could only reach in case of transport protocol routing. In case of a communication interface routing each destination has its own buffer and therefore multi Instance condition could never be fulfilled.

  \ID COV_PDUR_FATAL_ERROR
    \ACCEPT X
    \ACCEPT XF
    \ACCEPT TX
    \ACCEPT TF tx tf
    \REASON Fatal error check.

  \ID COV_PDUR_ROBUSTNESS
    \ACCEPT TF tx tf
    \ACCEPT TX tx tx
    \ACCEPT XF
    \ACCEPT TF tf tx tf
    \REASON This check increases robustness. Under normal circumstances it is never false/true.

  \ID COV_PDUR_MCQ_MAIN_FUNCTION_THRESHOLD
    \ACCEPT XF
    \REASON Threshold shall never be violated in the Unit TestSuite. However, threshold check is required to avoid an endless loop under high load.

  \ID COV_PDUR_DUMMY_FUNCTION
    \ACCEPT X
    \REASON Depending on the configuration the dummy function is not callable in all configuration variants.
            It is just a dummy function with out influencing the control- and data flow.

  \ID COV_PDUR_VAR_FATAL_ERROR
    \ACCEPT TX
    \REASON Fatal error check.

  \ID COV_PDUR_VAR_DEV_ERROR_DETECT
    \ACCEPT TX
    \REASON Det error detection must always be enabled for SafeBsw.

  \ID COV_PDUR_ERROR_NOTIFICATION
    \ACCEPT XF
    \REASON Always false. Feature is not part of SafeBsw.

  \ID COV_PDUR_VAR_DEPENDENT_SWITCH
    \ACCEPT TX
    \ACCEPT TX tx tx
    \REASON The nested switch depends on a previous switch.

  \ID COV_PDUR_VAR_NO_RX_ONLY_CONFIG
    \ACCEPT TX
    \REASON Rx only configurations are not possible. Therefore this switch is always true.

  \ID COV_PDUR_VAR_LINIF_SPECIAL_CONFIGURATION
    \ACCEPT TX
    \REASON This can only be false for LinIf BswModule. Otherwise this Code part is always active if the API is active.

  \ID COV_PDUR_DEFERRED_EVENT_CACHE_READLIMIT
    \ACCEPT XF
    \REASON Statement is only true when events are queued again while others are read at the same time

  \ID COV_PDUR_WRAPPER_FUNC
    \ACCEPT X
    \REASON The wrapper function may not be needed in some configurations.

COV_JUSTIFICATION_END */

/* *INDENT-ON* */

/**********************************************************************************************************************
 * END OF FILE: PduR.c
 *********************************************************************************************************************/
