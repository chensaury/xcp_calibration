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
 *         File:  PduR_RmIf.c
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
/* PRQA  S 1881 EOF */ /* MD_MSR_AutosarBoolean */
/* PRQA  S 4304 EOF */ /* MD_MSR_AutosarBoolean */
/* PRQA  S 4404 EOF */ /* MD_MSR_AutosarBoolean */
/* *INDENT-ON* */

#define PDUR_RMIF_SOURCE
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR.h"
#include "PduR_Bm.h"
#include "PduR_Fm.h"
#include "PduR_McQ.h"
#include "PduR_Lock.h"
#include "PduR_RmIf.h"
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
#if ((PDUR_EXISTS_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM == STD_ON) && ((PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON)))
/**********************************************************************************************************************
 * PduR_RmIf_PerformImmediateDestinationDataProcessing
 *********************************************************************************************************************/
/*! \brief      Perform routing to destination module.
 *  \details    -
 *  \param[in]  rmGDest                        Routing manager indirection Idx to global destination Pdu table.
 *  \param[in]  rmDest                         Routing manager indirection Idx.
 *  \param[in]  info                           Pointer to the destination buffer and the number of bytes to copy.
 *  \param[in]  fmFifoElementRamIdx            Fifo element Idx.
 *  \param[in]  useLock                        Shall the 'transmissionActive' Flag be set and considered for this transmission
 *  \return     E_OK                           The transmission was successfully.
 *              E_NOT_OK                       The transmission fails.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_RmIf_PerformImmediateDestinationDataProcessing(PduR_RmGDestRomIdxOfRmDestRomType rmGDest, PduR_RmDestRomIterType rmDest,
                                                                                                 P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
                                                                                                 PduR_FmFifoElementRamWriteIdxOfFmFifoRamType fmFifoElementRamIdx, boolean useLock);
#endif

#if ((PDUR_EXISTS_DEFERRED_PDURDESTPDUPROCESSINGOFRMGDESTROM == STD_ON) && (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmIf_PerformDeferredDestinationDataProcessing
 *********************************************************************************************************************/
/*! \brief      Switch state to wait for deferred processing.
 *  \details    -
 *  \param[in]  rmDest                         Routing manager indirection Idx to destination Pdu table.
 *  \param[in]  rmGDest                        Routing manager indirection Idx to global destination Pdu table.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmIf_PerformDeferredDestinationDataProcessing(PduR_RmDestRomIterType rmDest, PduR_RmGDestRomIdxOfRmDestRomType rmGDest);
#endif

#if ((PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmIf_CalcDlc
 *********************************************************************************************************************/
/*! \brief      Check if the DLC is shorter than the initial configured DLC. If the DLC is shorter the short DLC is
 *              returned. If the DLC is greater the initial DLC is returned.
 *  \details    -
 *  \param[in]  rmGDest           routing manager indirection Idx.
 *  \param[in]  info              contains the data pointer and its length.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduLengthType, PDUR_CODE) PduR_RmIf_CalcDlc(PduR_RmGDestRomIdxOfRmDestRomType rmGDest, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
#endif

#if((PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmIf_CopyRxData
 *********************************************************************************************************************/
/*! \brief     Copy data to the buffer and performe state handling
 *  \details    -
 *  \param[in] fmFifoElementRamIdx   fifo element Idx.
 *  \param[in] pduLength             length to copy.
 *  \param[in] sduDataPtr            data pointer.
 *  \pre       -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmIf_CopyRxData(PduR_FmFifoElementRamIterType fmFifoElementRamIdx, PduR_BmTxBufferArrayRamIterType pduLength, SduDataPtrType sduDataPtr);
#endif

#if((PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmIf_TransmitPreparation
 *********************************************************************************************************************/
/*! \brief      Perform buffer assignment and state handling before data transmission
 *  \details    -
 *  \param[in]  rmGDest routing manager indirection Idx.
 *  \param[in]  fmFifoElementRamIdx   fifo element Idx.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmIf_TransmitPreparation(PduR_RmGDestRomIterType rmGDest, PduR_FmFifoElementRamIterType fmFifoElementRamIdx);
#endif

#if ((PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmIf_FifoHandling
 *********************************************************************************************************************/
/*! \brief      Perform D-Fifo and TT- Fifo buffer and transmission handling
 *  \details    -
 *  \param[in]  rmDest   routing manager indirection Idx.
 *  \param[in]  rmGDest  routing manager indirection Idx to global destination Pdu table.
 *  \param[in]  info     Info pointer contains data and length
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmIf_FifoHandling(PduR_RmDestRomIterType rmDest, PduR_RmGDestRomIdxOfRmDestRomType rmGDest, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
#endif

#if(PDUR_EXISTS_IF_NOBUFFER_GATEWAY_ROUTINGTYPEOFRMDESTROM == STD_ON )
/**********************************************************************************************************************
   PduR_RmIf_RxIndicationNoBuffer
**********************************************************************************************************************/
/*! \brief       The function is called by the PduR to indicate the complete reception of a communication interface I-PDU.
 *  \details     The PDU Router evaluates the Gw I-PDU handle and performs appropriate handle and port conversion.
 *               The call is routed to an IF module using the appropriate I-PDU handle of the destination layer.
 *  \param[in]   rmDestIdx         ID of the received gateway I-PDU
 *  \param[in]   info              Payload information of the received I-PDU (pointer to data and data length).
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       SPEC-1096, SPEC-2020151
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmIf_RxIndicationNoBuffer(PduR_RmDestRomIterType rmDestIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
#endif

#if((PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
/**********************************************************************************************************************
   PduR_RmIf_Forward2Buffer
**********************************************************************************************************************/
/*! \brief       The function is forwards the If Pdu to the corresponding buffer handling function.
 *  \details     -
 *  \param[in]   rmDestIdx         ID of the received gateway I-PDU
 *  \param[in]   info              Payload information of the received I-PDU (pointer to data and data length).
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       SPEC-1096, SPEC-2020151
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmIf_Forward2Buffer(PduR_RmDestRomIterType rmDestIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
#endif

#if(PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON)
/**********************************************************************************************************************
   PduR_RmIf_RxIndicationTTSingleBuffer
**********************************************************************************************************************/
/*! \brief       The function is called by the PduR to indicate the complete reception of a communication interface I-PDU.
 *  \details     The PDU Router evaluates the Gw I-PDU handle and performs appropriate handle and port conversion.
 *               The call is routed to an IF module using the appropriate I-PDU handle of the destination layer.
 *  \param[in]   rmDestIdx         ID of the received gateway I-PDU
 *  \param[in]   info              Payload information of the received I-PDU (pointer to data and data length).
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       SPEC-1096, SPEC-2020151
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmIf_RxIndicationTTSingleBuffer(PduR_RmDestRomIterType rmDestIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
#endif

#if((PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
/**********************************************************************************************************************
   PduR_RmIf_RxIndicationFifoBuffer
**********************************************************************************************************************/
/*! \brief       The function is called by the PduR to indicate the complete reception of a communication interface I-PDU.
 *  \details     The PDU Router evaluates the Gw I-PDU handle and performs appropriate handle and port conversion.
 *               The call is routed to an IF module using the appropriate I-PDU handle of the destination layer.
 *  \param[in]   rmDestIdx         ID of the received gateway I-PDU
 *  \param[in]   info              Payload information of the received I-PDU (pointer to data and data length).
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       SPEC-1096, SPEC-2020151
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmIf_RxIndicationFifoBuffer(PduR_RmDestRomIterType rmDestIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
#endif

#if ((PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmIf_FiFoDataProcessing
 *********************************************************************************************************************/
/*! \brief      Perform D-Fifo and TT- Fifo buffer and transmission handling
 *  \details    -
 *  \param[in]  rmDest               routing manager indirection Idx.
 *  \param[in]  rmGDest              routing manager indirection Idx to global destination Pdu table.
 *  \param[in]  fmFifoElementRamIdx  specific Fifo Element RAM index.
 *  \param[in]  pduLength            length to copy.
 *  \param[in]  sduDataPtr           data pointer.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_RmIf_FiFoDataProcessing(PduR_RmDestRomIterType rmDest, PduR_RmGDestRomIterType rmGDest,
                                                                          PduR_FmFifoElementRamWriteIdxOfFmFifoRamType * fmFifoElementRamIdx,
                                                                          PduR_BmTxBufferArrayRamLengthOfBmTxBufferRomType pduLength, SduDataPtrType sduDataPtr);
#endif

#if(PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmIf_SingleBufferHandling
 *********************************************************************************************************************/
/*! \brief     perform Single buffer Fifo buffer and transmission handling ()
 *  \details   -
 *  \param[in] rmDest         routing manager indirection Idx.
 *  \param[in] rmGDest        routing manager indirection Idx to global destination Pdu table.
 *  \param[in] info           Info pointer contains data and length.
 *  \param[in] destPduInfo    Info pointer contains data and max Pdu length.
 *  \pre       -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmIf_SingleBufferHandling(PduR_RmDestRomIterType rmDest, PduR_RmGDestRomIdxOfRmDestRomType rmGDest, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
                                                                  P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) destPduInfo);
#endif

#if( (PDUR_EXISTS_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON) || (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON) || (PDUR_EXISTS_IF_NOBUFFER_GATEWAY_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
  PduR_RmIf_MultipleSourceHandler_Transmit
**********************************************************************************************************************/
/*! \brief        The function is called by the PduR to trigger the transmission on the destination buses in case of a
 *                FanIn routing.
 *   \details     The PDU Router evaluates the Gw I-PDU handle and performs appropriate handle and port conversion.
 *                The call is routed to multiple IF module using the appropriate I-PDU handle of the destination layer.
 *   \param[in]   rmDestRomIdx              ID of the destination Pdu
 *   \param[in]   info                      Pointer to the destination buffer and the number of bytes to copy.
 *   \param[in]   useLock                   shall the 'transmissionActive' Flag be set and considered for this transmission
 *   \return      Std_ReturnType            Result of the multiple transmission.
 *                            E_OK          The transmission was successfully .\n
 *                            E_NOT_OK      The transmission fails.
 *   \pre         -
 *   \context     TASK|ISR1|ISR2
 *   \reentrant   TRUE
 *   \synchronous TRUE
**********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_RmIf_MultipleSourceHandler_Transmit(PduR_RmDestRomIterType rmDestRomIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, boolean useLock);
#endif

#if(PDUR_HASIFTXFIFOOFGENERALPROPERTIESROM == STD_ON)
/**********************************************************************************************************************
  PduR_RmIf_TxConfirmation
**********************************************************************************************************************/
/*! \brief       The function is called by the PduR to indicate the complete transmission of a communication interface I-PDU.
 *  \details     The PDU Router evaluates the Gw I-PDU handle and performs appropriate handle and port conversion.
 *               The call is routed to an upper IF module using the appropriate I-PDU handle of the destination layer.
 *  \param[in]   rmGDestRomIdx           ID of the transmitted GwIf I-PDU
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
***********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmIf_TxConfirmation(PduR_RmGDestRomIdxOfTxIf2UpType rmGDestRomIdx);
#endif

#if((PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) ||(PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
/**********************************************************************************************************************
  PduR_RmIf_TriggerTransmit
**********************************************************************************************************************/
/*! \brief       The function is called by the PduR to request the PduR TX I-PDU data before transmission.
 *  \details     The PDU Router evaluates the Gw I-PDU handle and performs appropriate handle and port conversion.
 *               The call is routed to an upper IF module using the appropriate I-PDU handle of the destination layer.
 *  \param[in]   rmDestIdx         ID of the GwIf I-PDU that will be transmitted.
 *  \param[in]   info              Payload information of the received I-PDU (pointer to data and data length).
 *  \return      Std_ReturnType    E_OK:     The SDU has been copied and the SduLength indicates
 *                                           the number of copied bytes.
 *                                 E_NOT_OK: The SDU has not been copied and the SduLength has not been set.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous FALSE
 *  \trace       SPEC-1096, SPEC-2020151
**********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_RmIf_TriggerTransmit(PduR_RmDestRomIterType rmDestIdx, CONSTP2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
#endif

#if (PDUR_EXISTS_IF_NOBUFFER_GATEWAY_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
  PduR_RmIf_ProcessNoBufferedGwRouting
**********************************************************************************************************************/
/*! \brief       The function is called by the PduR to process no buffered gateway If Pdus
 *  \details     -
 *  \param[in]   rmDestIdx         ID of the GwIf I-PDU that will be transmitted.
 *  \param[in]   info              Payload information of the received I-PDU (pointer to data and data length).
 *  \return      Std_ReturnType    E_OK:     The SDU has been copied and the SduLength indicates
 *                                           the number of copied bytes.
 *                                 E_NOT_OK: The SDU has not been copied and the SduLength has not been set.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
**********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_RmIf_ProcessNoBufferedGwRouting(PduR_RmDestRomIterType rmDestIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
#endif

#if (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
  PduR_RmIf_ProcessBufferedRouting
**********************************************************************************************************************/
/*! \brief       The function is called by the PduR to process buffered If Pdus
 *  \details     -
 *  \param[in]   rmSrcIdx          Source Id.
 *  \param[in]   rmDestIdx         Destintaion Id.
 *  \param[in]   rmGDestRomIdx     G Dest Rom Table Id.
 *  \param[in]   info              Payload information of the received I-PDU (pointer to data and data length).
 *  \return      Std_ReturnType    E_OK:     The SDU has been copied and the SduLength indicates
 *                                           the number of copied bytes.
 *                                 E_NOT_OK: The SDU has not been copied and the SduLength has not been set.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
**********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_RmIf_ProcessBufferedRouting(PduR_RmSrcRomIterType rmSrcIdx, PduR_RmDestRomIterType rmDestIdx, PduR_RmGDestRomIterType rmGDestRomIdx,
                                                                              P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
#endif

#if ((PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmIf_AssignAssociatedBuffer2Destination
 *********************************************************************************************************************/
/*! \brief                           Assign the associated buffer to the destinations before the Transmit function is called.
 *  \details -
 *  \param[in]   bmTxBufferRomIdx      Index of the Tx buffer.
 *  \param[in]   rmGDestRomIdx         global destination Pdu Idx.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmIf_AssignAssociatedBuffer2Destination(PduR_BmTxBufferRomIterType bmTxBufferRomIdx, PduR_RmGDestRomIterType rmGDestRomIdx);
#endif

#if ((PDUR_EXISTS_DEFERRED_PDURDESTPDUPROCESSINGOFRMGDESTROM == STD_ON) && (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmIf_GetBufferedPduInfo
 *********************************************************************************************************************/
/*! \brief      Get the PduInfo stored in the TxBuffer.
 *  \details    -
 *  \param[in]  rmGDest                        Routing manager indirection Idx.
 *  \param[in]  info                           Empty PduInfo which will be filled with data.
 *  \param[in]  peekedfmFifoElementRamReadIdx  Index of the current element which is used by the routing.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmIf_GetBufferedPduInfo(PduR_RmGDestRomIterType rmGDest, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
                                                                P2VAR(PduR_FmFifoElementRamIterType, AUTOMATIC, PDUR_APPL_DATA) peekedfmFifoElementRamReadIdx);
#endif

#define PDUR_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * PduR_RmIf_Init_DedicatedTxBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
#if (PDUR_DEDICATEDTXBUFFEROFRMBUFFEREDIFPROPERTIESROM == STD_ON)
FUNC(void, PDUR_CODE) PduR_RmIf_Init_DedicatedTxBuffer(void)
{
  PduR_RmGDestRomIterType rmGDestRomIdx;
  for(rmGDestRomIdx = 0u; rmGDestRomIdx < PduR_GetSizeOfRmGDestRom(); rmGDestRomIdx++)
  {
    if(PduR_IsRmBufferedIfPropertiesRomUsedOfRmGDestRom(rmGDestRomIdx)) /* COV_PDUR_FEATURE_ALWAYS_TRUE */ /* PRQA S 2995, 2996, 2991 */ /* MD_PduR_2995_2996, MD_PduR_2995_2996, MD_PduR_2991 */
    {
      PduR_RmBufferedIfPropertiesRomIdxOfRmGDestRomType rmBufferedIfPropertiesRomIdx = PduR_GetRmBufferedIfPropertiesRomIdxOfRmGDestRom(rmGDestRomIdx);

      if(PduR_IsDedicatedTxBufferOfRmBufferedIfPropertiesRom(rmBufferedIfPropertiesRomIdx))     /* COV_PDUR_ONLY_DIRECT_BUFFER */ /* PRQA S 2995, 2996, 2991 */ /* MD_PduR_2995_2996, MD_PduR_2995_2996, MD_PduR_2991 */
      {
        if(PduR_IsFmFifoInstanceRomUsedOfRmGDestRom(rmGDestRomIdx))     /* COV_PDUR_FATAL_ERROR */ /* PRQA S 2995, 2996, 2991 */ /* MD_PduR_2995_2996, MD_PduR_2995_2996, MD_PduR_2991 */
        {
          PduR_FmFifoRomIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx));
          PduR_FmFifoElementRamIterType possilbeFmFifoElementRamIdx;
          for(possilbeFmFifoElementRamIdx = PduR_GetFmFifoElementRamStartIdxOfFmFifoRom(fmFifoRomIdx); possilbeFmFifoElementRamIdx < PduR_GetFmFifoElementRamEndIdxOfFmFifoRom(fmFifoRomIdx);
              possilbeFmFifoElementRamIdx++)
          {
            PduR_FmFifoElementRamWriteIdxOfFmFifoRamType fmFifoElementRamIdx = 0u;
            if(PduR_Fm_AssignFifoElement(fmFifoRomIdx, &fmFifoElementRamIdx) == E_OK)   /* SBSW_PDUR_STACK_VARIABLE */ /* COV_PDUR_FATAL_ERROR */
            {
              PduLengthType bufferSizePtr = 0u;
              PduR_BmTxBufferRomIdxOfBmTxBufferIndRomType allocatedTxBufferIdxPtr = 0u;
              if(PduR_Bm_AllocateTxBuffer(PduR_GetBmTxBufferIndRomStartIdxOfRmBufferedIfPropertiesRom(rmBufferedIfPropertiesRomIdx), PduR_GetBmTxBufferIndRomEndIdxOfRmBufferedIfPropertiesRom(rmBufferedIfPropertiesRomIdx), fmFifoElementRamIdx, 0u, &bufferSizePtr, &allocatedTxBufferIdxPtr, FALSE) == BUFREQ_OK)   /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */ /* COV_PDUR_FATAL_ERROR */
              {
                PduR_Fm_AssignTxBuffer2FifoElement(fmFifoElementRamIdx, allocatedTxBufferIdxPtr);
                PduR_SetStateOfFmFifoElementRam(fmFifoElementRamIdx, PDUR_FM_ALLOCATED_WITH_BUFFER_STATEOFFMFIFOELEMENTRAM);    /* SBSW_PDUR_CSL03 */
                PduR_SetDedicatedTxBufferOfFmFifoElementRam(fmFifoElementRamIdx, TRUE); /* SBSW_PDUR_CSL03 */
              }
              else
              {
                PduR_Det_ReportError(PDUR_RMIF_INIT_DEDICATEDTXBUFFER, PDUR_E_FATAL);
              }
            }
            else
            {
              PduR_Det_ReportError(PDUR_RMIF_INIT_DEDICATEDTXBUFFER, PDUR_E_FATAL);
            }
          }
        }
        else
        {
          PduR_Det_ReportError(PDUR_RMIF_INIT_DEDICATEDTXBUFFER, PDUR_E_FATAL); /* PRQA S 2880 */ /* MD_PduR_2880 */
        }
      }
    }
  }
}       /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

/**********************************************************************************************************************
 * PduR_RmIf_Init_TTSingleBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
#if (PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON)
FUNC(void, PDUR_CODE) PduR_RmIf_Init_TTSingleBuffer(void)
{
  PduR_RmGDestRomIterType rmGDestRomIdx;
  for(rmGDestRomIdx = 0u; rmGDestRomIdx < PduR_GetSizeOfRmGDestRom(); rmGDestRomIdx++)
  {
    if(PduR_IsRmBufferedIfPropertiesRomUsedOfRmGDestRom(rmGDestRomIdx) && PduR_IsFiFoInitValuesUsedOfRmBufferedIfPropertiesRom(PduR_GetRmBufferedIfPropertiesRomIdxOfRmGDestRom(rmGDestRomIdx)))        /* COV_PDUR_FEATURE_ALWAYS_TRUE */ /* PRQA S 2995, 2996, 2991 */ /* MD_PduR_2995_2996, MD_PduR_2995_2996, MD_PduR_2991 */
    {
      if(PduR_IsFmFifoInstanceRomUsedOfRmGDestRom(rmGDestRomIdx))       /* COV_PDUR_FATAL_ERROR */ /* PRQA S 2995, 2996, 2991 */ /* MD_PduR_2995_2996, MD_PduR_2995_2996, MD_PduR_2991 */
      {
        PduR_RmBufferedIfPropertiesRomIdxOfRmGDestRomType rmBufferedIfPropertiesRomIdx = PduR_GetRmBufferedIfPropertiesRomIdxOfRmGDestRom(rmGDestRomIdx);
        PduR_FmFifoRomIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx));
        PduR_FmFifoElementRamIterType fmFifoElementRamIdx;

        for(fmFifoElementRamIdx = PduR_GetFmFifoElementRamStartIdxOfFmFifoRom(fmFifoRomIdx); fmFifoElementRamIdx < PduR_GetFmFifoElementRamEndIdxOfFmFifoRom(fmFifoRomIdx); fmFifoElementRamIdx++)
        {
          PduR_BmTxBufferRomIterType bmTxBufferRomIdx = PduR_GetBmTxBufferRomIdxOfFmFifoElementRam(fmFifoElementRamIdx);
          PduR_BmTxBufferArrayRamIterType pduLength = PduR_GetFiFoInitValuesLengthOfRmBufferedIfPropertiesRom(rmBufferedIfPropertiesRomIdx);
          SduDataPtrType sduDataPtr = (SduDataPtrType) PduR_GetAddrFiFoInitValues(PduR_GetFiFoInitValuesStartIdxOfRmBufferedIfPropertiesRom(rmBufferedIfPropertiesRomIdx));     /* PRQA S 0311 */ /* MD_PduR_0311 */

          PduR_GetFctPtrOfFm_ActivateWrite_FmSmStateHandler(PduR_GetStateOfFmFifoElementRam(fmFifoElementRamIdx)) (fmFifoElementRamIdx);        /* SBSW_PDUR_CSL03 */
          (void) PduR_Bm_PutData(bmTxBufferRomIdx, pduLength, sduDataPtr);      /* SBSW_PDUR_STACK_VARIABLE */
          PduR_GetFctPtrOfFm_FinishWrite_FmSmStateHandler(PduR_GetStateOfFmFifoElementRam(fmFifoElementRamIdx)) (fmFifoElementRamIdx, E_OK);    /* SBSW_PDUR_CSL03 */
          PduR_RmIf_AssignAssociatedBuffer2Destination(bmTxBufferRomIdx, rmGDestRomIdx);
        }
      }
      else
      {
        PduR_Det_ReportError(PDUR_RMIF_INIT_TTSINGLEBUFFER, PDUR_E_FATAL);      /* PRQA S 2880 */ /* MD_PduR_2880 */
      }
    }
  }
}
#endif

#if (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmIf_Init_FiFoRoutingState
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmIf_Init_FiFoRoutingState(void)
{
  PduR_RmBufferedIfPropertiesRomIterType rmBufferedIfPropertiesRamIdx;
  for(rmBufferedIfPropertiesRamIdx = 0u; rmBufferedIfPropertiesRamIdx < PduR_GetSizeOfRmBufferedIfPropertiesRam(); rmBufferedIfPropertiesRamIdx++)
  {
    PduR_SetIfSmStateOfRmBufferedIfPropertiesRam(rmBufferedIfPropertiesRamIdx, PduR_GetNextState_For_Init_If_Routing_StateOfIfRoutingStateTable(PduR_GetFifoTypeOfRmBufferedIfPropertiesRom(rmBufferedIfPropertiesRamIdx)));    /* SBSW_PDUR_CSL01 */
  }
}
#endif

#if((PDUR_EXISTS_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON) || (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON) || (PDUR_EXISTS_IF_NOBUFFER_GATEWAY_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmIf_MultipleSourceHandler_Transmit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_RmIf_MultipleSourceHandler_Transmit(PduR_RmDestRomIterType rmDestRomIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, boolean useLock)
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_Lock_LockRoutingPathByDestPdu(rmDestRomIdx);
  {
    PduR_RmGDestRomIdxOfRmDestRomType rmGDestRomIdx = PduR_GetRmGDestRomIdxOfRmDestRom(rmDestRomIdx);

# if(PDUR_RMGDESTNTO1INFORAMIDXOFRMGDESTROM == STD_ON)
    if(PduR_IsRmGDestNto1InfoRamUsedOfRmGDestRom(rmGDestRomIdx))
    {
      PduR_RmGDestNto1InfoRamIdxOfRmGDestRomType rmGDestNto1InfoIdx = PduR_GetRmGDestNto1InfoRamIdxOfRmGDestRom(rmGDestRomIdx);

      if(!PduR_IsTransmissionActiveOfRmGDestNto1InfoRam(rmGDestNto1InfoIdx))    /* COV_PDUR_NTO1_GW_ONLY_ROUTINGPATHS */
      {
        PduR_SetRmDestRomIdxOfRmGDestNto1InfoRam(rmGDestNto1InfoIdx, (PduR_RmDestRomIdxOfRmGDestNto1InfoRamType) rmDestRomIdx); /* SBSW_PDUR_CSL03 */
        PduR_SetTransmissionActiveOfRmGDestNto1InfoRam(rmGDestNto1InfoIdx, useLock);    /* SBSW_PDUR_CSL03 */

        retVal = PduR_GetLoIfTransmitFctPtrOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(rmGDestRomIdx)) (PduR_GetDestHndOfRmGDestRom(rmGDestRomIdx), info);     /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
        if(retVal != E_OK)
        {
          PduR_Rm_MultipleSourceHandler_Reset(rmGDestRomIdx);
        }
      }
    }
    else
# endif
    {
      retVal = PduR_GetLoIfTransmitFctPtrOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(rmGDestRomIdx)) (PduR_GetDestHndOfRmGDestRom(rmGDestRomIdx), info);       /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
    }
  }
  PduR_Lock_UnlockRoutingPathByDestPdu(rmDestRomIdx);

  PDUR_DUMMY_STATEMENT(useLock);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}
#endif

#if ((PDUR_TRIGGERTRANSMITSUPPORTEDOFRMSRCROM == STD_ON) || (PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmIf_MultipleSourceHandler_TriggerTransmit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmIf_MultipleSourceHandler_TriggerTransmit(PduR_RmGDestRomIdxOfTxIf2UpType rmGDestRomIdx, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  {
    PduR_RmDestRomIterType rmDestRomIdx;

    if(PduR_Rm_GetSrcDestPdu(rmGDestRomIdx, &rmDestRomIdx) == E_OK)     /* SBSW_PDUR_STACK_VARIABLE */ /* COV_PDUR_NO_NTO1_ROUTINGPATHS */
    {
# if ((PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
      if(PduR_GetRoutingTypeOfRmDestRom(rmDestRomIdx) == PDUR_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM)       /* COV_PDUR_FATAL_ERROR */
      {
        retVal = PduR_RmIf_TriggerTransmit(rmDestRomIdx, info); /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
      }
      else
# endif
# if (PDUR_TRIGGERTRANSMITSUPPORTEDOFRMSRCROM == STD_ON)
      if(PduR_IsTriggerTransmitSupportedOfRmSrcRom(PduR_GetRmSrcRomIdxOfRmDestRom(rmDestRomIdx)))       /* COV_PDUR_FATAL_ERROR */
      {
        retVal = PduR_GetUpIfTriggerTransmitFctPtrOfMmRom(PduR_GetMmRomIdxOfRmSrcRom(PduR_GetRmSrcRomIdxOfRmDestRom(rmDestRomIdx))) (PduR_GetSrcHndOfRmSrcRom(PduR_GetRmSrcRomIdxOfRmDestRom(rmDestRomIdx)), info);     /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
      }
      else
# endif
      {
        PduR_Det_ReportError(PDUR_RMIF_MULTIPLESOURCEHANDLER_TRIGGERTRANSMIT, PDUR_E_PDU_ID_INVALID);
      }
    }
    else
    {
      PduR_Det_ReportError(PDUR_RMIF_MULTIPLESOURCEHANDLER_TRIGGERTRANSMIT, PDUR_E_PDU_ID_INVALID);
    }
  }
  return retVal;
}
#endif

#if ((PDUR_IFCANCELTRANSMITSUPPORTEDOFMMROM == STD_ON) && (PDUR_EXISTS_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmIf_MultipleSourceHandler_CancelTransmit
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
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmIf_MultipleSourceHandler_CancelTransmit(PduR_RmDestRomIterType rmDestRomIdx)
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
        retVal = PduR_GetLoIfCancelTransmitFctPtrOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(rmGDestRomIdx)) (PduR_GetDestHndOfRmGDestRom(rmGDestRomIdx));     /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
      }
      else
      {
        PduR_Det_ReportError(PDUR_RMIF_MULTIPLESOURCEHANDLER_CANCELTRANSMIT, PDUR_E_UNEXPECTED_CALL);
      }
    }
    else
# endif
    {
      retVal = PduR_GetLoIfCancelTransmitFctPtrOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(rmGDestRomIdx)) (PduR_GetDestHndOfRmGDestRom(rmGDestRomIdx));       /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
    }
  }
  PduR_Lock_UnlockRoutingPathByDestPdu(rmDestRomIdx);
  return retVal;
}
#endif

#if (PDUR_TXCONFIRMATIONUSEDOFTXIF2UP == STD_ON)
/**********************************************************************************************************************
 * PduR_RmIf_MultipleSourceHandler_TxConfirmation
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
FUNC(void, PDUR_CODE) PduR_RmIf_MultipleSourceHandler_TxConfirmation(PduR_RmGDestRomIdxOfTxIf2UpType rmGDestRomIdx)
{
  PduR_RmDestRomIterType rmDestRomIdx;

  /* #10 Get RmDest index of GDestPdu. If index is ambiguous, call DET */
  if(PduR_Rm_GetSrcDestPdu(rmGDestRomIdx, &rmDestRomIdx) == E_OK)       /* SBSW_PDUR_STACK_VARIABLE */ /* COV_PDUR_NO_NTO1_ROUTINGPATHS */
  {
# if (PDUR_RMGDESTNTO1INFORAMIDXOFRMGDESTROM == STD_ON)
    /* #20 Reset RAM variables which hold the N:1 routing information */
    PduR_Rm_MultipleSourceHandler_Reset(rmGDestRomIdx);
# endif
# if ((PDUR_TXCONFIRMATIONSUPPORTEDOFRMSRCROM == STD_ON) && ((PDUR_EXISTS_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM == STD_ON) || ((PDUR_EXISTS_DEFERRED_PDURDESTPDUPROCESSINGOFRMGDESTROM == STD_ON) && (PDUR_MCQBUFFERROM == STD_ON))))
    {
      PduR_RmSrcRomIdxOfRmDestRomType rmSrcRomIdx = PduR_GetRmSrcRomIdxOfRmDestRom(rmDestRomIdx);
      /* #30 If upper layer requires a Tx Confirmation */
      if(PduR_IsTxConfirmationSupportedOfRmSrcRom(rmSrcRomIdx)) /* COV_PDUR_FEATURE_ALWAYS_TRUE */
      {
        switch (PduR_GetPduRDestPduProcessingOfRmGDestRom(rmGDestRomIdx))
        {
#  if (PDUR_EXISTS_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM == STD_ON)
            /* #40 If Processing type is immediate, call upper layer IF confirmation */
          case PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM:       /* COV_PDUR_CROSSCORE_ROUTINGS_ONLY */
            PduR_GetUpIfTxConfirmationFctPtrOfMmRom(PduR_GetMmRomIdxOfRmSrcRom(rmSrcRomIdx)) (PduR_GetSrcHndOfRmSrcRom(rmSrcRomIdx));   /* SBSW_PDUR_API_CALL_FORWARDING_ID_ONLY */
            break;
#  endif
#  if ((PDUR_EXISTS_DEFERRED_PDURDESTPDUPROCESSINGOFRMGDESTROM == STD_ON) && (PDUR_MCQBUFFERROM == STD_ON))
            /* #50 Otherwise if processing is of type DEFERRED and routing type is not IF-buffered */
          case PDUR_DEFERRED_PDURDESTPDUPROCESSINGOFRMGDESTROM:
#   if (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
            if(PduR_GetRoutingTypeOfRmDestRom(rmDestRomIdx) != PDUR_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM)
#   endif
            {
              /* Destination core in this context is the core of the SrcPdu */
              PduR_CoreManagerRomIdxOfMmRomType destCoreIdx = PduR_GetCoreManagerRomIdxOfMmRom(PduR_GetMmRomIdxOfRmSrcRom(PduR_GetRmSrcRomIdxOfRmDestRom(rmDestRomIdx)));
              PduR_CoreManagerRomIdxOfMmRomType srcCoreIdx = PduR_GetCoreManagerRomIdxOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(rmGDestRomIdx));

              /* #60 Write Tx Confirmation into multicore queue if queue is not full, otherwise call DET */
              if(PduR_McQ_WriteTxConfirmation(PduR_GetMcQBufferRomIdxOfSrcCoreRom(PduR_GetSrcCoreRomStartIdxOfCoreManagerRom(destCoreIdx) + srcCoreIdx), rmSrcRomIdx) == E_NOT_OK)
              {
                PduR_Det_ReportError(PDUR_FCT_RMIF_TXCONF, PDUR_E_MCQ_QUEUE_OVERFLOW);
              }
            }
            break;
#  endif
          default:     /* COV_PDUR_MISRA */
            /* Nothing to do: This should never be reached */
            break;
        }
      }
    }
# endif

# if(PDUR_HASIFTXFIFOOFGENERALPROPERTIESROM == STD_ON)
    /* #70 If Routing Type is IF-Buffered, indicate the complete transmission */
    if(PduR_GetRoutingTypeOfRmDestRom(rmDestRomIdx) == PDUR_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM) /* COV_PDUR_FEATURE_ALWAYS_TRUE */
    {
      PduR_RmIf_TxConfirmation(rmGDestRomIdx);
    }
# endif
  }
  else
  {
    PduR_Det_ReportError(PDUR_RMIF_MULTIPLESOURCEHANDLER_TXCONFIRMATION, PDUR_E_PDU_ID_INVALID);
  }
}       /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#if ((PDUR_MAIN_FUNCTION == STD_ON) && (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmIf_GetBufferedPduInfo
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmIf_GetBufferedPduInfo(PduR_RmGDestRomIterType rmGDest, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,    /* PRQA S 1505 */ /* MD_PduR_1505 */
                                                                P2VAR(PduR_FmFifoElementRamIterType, AUTOMATIC, PDUR_APPL_DATA) peekedfmFifoElementRamReadIdx)
{
  PduR_FmFifoInstanceRamIterType fmFifoRomInstanceIdx = PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDest);
  PduR_FmFifoRamIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(fmFifoRomInstanceIdx);
  *peekedfmFifoElementRamReadIdx = PduR_GetFmFifoElementRamReadIdxOfFmFifoRam(fmFifoRomIdx);    /* SBSW_PDUR_STACK_VARIABLE */

  /* Read data from the TxBuffer */
  /* #10 Perform buffer assignment and state handling */
  PduR_RmIf_TransmitPreparation(rmGDest, *peekedfmFifoElementRamReadIdx);
  {
    PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx =
      PduR_GetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom
                                                          (PduR_GetRmGDestRomIdxOfRmDestRom(PduR_GetRmDestRomIdxOfFmFifoElementRam(*peekedfmFifoElementRamReadIdx))));

    /* #20 Get the stored PduInfo from the TxBuffer and return E_OK */
    PduR_Bm_CopyDataAsPtr(bmTxBufferInstanceRomIdx, info, PduR_Bm_GetLinearDataSizeInstance(bmTxBufferInstanceRomIdx)); /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
  }
}
#endif

#if ((PDUR_EXISTS_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM == STD_ON) && ((PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON)))
/**********************************************************************************************************************
 * PduR_RmIf_PerformImmediateDestinationDataProcessing
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_RmIf_PerformImmediateDestinationDataProcessing(PduR_RmGDestRomIdxOfRmDestRomType rmGDest, PduR_RmDestRomIterType rmDest, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, PduR_FmFifoElementRamWriteIdxOfFmFifoRamType fmFifoElementRamIdx, boolean useLock)     /* COV_PDUR_CROSSCORE_ROUTINGS_ONLY */
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* Perform transmission to destination module */
  PduR_RmIf_TransmitPreparation(rmGDest, fmFifoElementRamIdx);
  retVal = PduR_RmIf_MultipleSourceHandler_Transmit(rmDest, info, useLock);     /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */

  return retVal;
}
#endif

#if ((PDUR_EXISTS_DEFERRED_PDURDESTPDUPROCESSINGOFRMGDESTROM == STD_ON) && (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmIf_PerformDeferredDestinationDataProcessing
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmIf_PerformDeferredDestinationDataProcessing(PduR_RmDestRomIterType rmDest, PduR_RmGDestRomIdxOfRmDestRomType rmGDest)
{
  PduR_RmBufferedIfPropertiesRomIdxOfRmGDestRomType rmBufferedIfPropertiesRomIdx = PduR_GetRmBufferedIfPropertiesRomIdxOfRmGDestRom(rmGDest);

  PduR_SetIfSmStateOfRmBufferedIfPropertiesRam(rmBufferedIfPropertiesRomIdx, PDUR_WAIT_FOR_DEFERRED_PROCESSING_IFSMSTATEOFRMBUFFEREDIFPROPERTIESRAM);   /* SBSW_PDUR_CSL03 */

# if (PDUR_DEFERREDEVENTCACHEROM == STD_ON)
  {
    /* Put destination handle into the deferred event queue */
    PduR_CoreManagerRomIdxOfMmRomType srcCoreIdx = PduR_GetCoreManagerRomIdxOfMmRom(PduR_GetMmRomIdxOfRmSrcRom(PduR_GetRmSrcRomIdxOfRmDestRom(rmDest)));
    PduR_CoreManagerRomIdxOfMmRomType destCoreIdx = PduR_GetCoreManagerRomIdxOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(rmGDest));

    (void) PduR_EvC_Put(PduR_GetDeferredEventCacheRomIdxOfSrcCoreRom(PduR_GetSrcCoreRomStartIdxOfCoreManagerRom(destCoreIdx) + srcCoreIdx), rmGDest);
  }
# endif
  PDUR_DUMMY_STATEMENT(rmDest); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if(PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmIf_SingleBufferHandling
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
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmIf_SingleBufferHandling(PduR_RmDestRomIterType rmDest, PduR_RmGDestRomIdxOfRmDestRomType rmGDest, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
                                                                  P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) destPduInfo)
{
  PduR_FmFifoRomIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDest));
  PduR_FmFifoElementRamWriteIdxOfFmFifoRamType fmFifoElementRamIdx = 0u;
  PduR_RmBufferedIfPropertiesRomIdxOfRmGDestRomType rmBufferedIfPropertiesRomIdx = PduR_GetRmBufferedIfPropertiesRomIdxOfRmGDestRom(rmGDest);

  PduR_Fm_FlushFiFo(rmGDest);
  PduR_SetIfSmStateOfRmBufferedIfPropertiesRam(rmBufferedIfPropertiesRomIdx, PDUR_WAIT_FOR_RXINDICATION_IFSMSTATEOFRMBUFFEREDIFPROPERTIESRAM);  /* PRQA S 2842 */ /* MD_PduR_2842 */ /* SBSW_PDUR_CSL03 */
  if(PduR_Fm_AssignFifoElement(fmFifoRomIdx, &fmFifoElementRamIdx) == E_OK)     /* SBSW_PDUR_STACK_VARIABLE */ /* COV_PDUR_FATAL_ERROR */
  {
    PduLengthType bufferSizePtr = 0;
    PduR_BmTxBufferRomIdxOfBmTxBufferIndRomType allocatedTxBufferIdxPtr = 0u;
    /* Update fill level */
    PduR_IncFillLevelOfFmFifoRam(fmFifoRomIdx); /* SBSW_PDUR_CSL03 */
    if(PduR_Bm_AllocateTxBuffer(PduR_GetBmTxBufferIndRomStartIdxOfRmBufferedIfPropertiesRom(rmBufferedIfPropertiesRomIdx), PduR_GetBmTxBufferIndRomEndIdxOfRmBufferedIfPropertiesRom(rmBufferedIfPropertiesRomIdx), fmFifoElementRamIdx, (PduR_BmTxBufferArrayRamLengthOfBmTxBufferRomType) info->SduLength, &bufferSizePtr, &allocatedTxBufferIdxPtr, FALSE) == BUFREQ_OK)     /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */ /* COV_PDUR_FATAL_ERROR */
    {
      PduR_Fm_AssignTxBuffer2FifoElement(fmFifoElementRamIdx, allocatedTxBufferIdxPtr);
      PduR_SetStateOfFmFifoElementRam(fmFifoElementRamIdx, PDUR_FM_ALLOCATED_WITH_BUFFER_STATEOFFMFIFOELEMENTRAM);      /* SBSW_PDUR_CSL01 */
      PduR_SetRmDestRomIdxOfFmFifoElementRam(fmFifoElementRamIdx, (PduR_RmDestRomIdxOfFmFifoElementRamType) rmDest);    /* SBSW_PDUR_CSL01 */
      PduR_RmIf_CopyRxData(fmFifoElementRamIdx, (PduR_BmTxBufferArrayRamIterType) destPduInfo->SduLength, destPduInfo->SduDataPtr);     /* SBSW_PDUR_STACK_VARIABLE */

      switch (PduR_GetPduRDestPduProcessingOfRmGDestRom(rmGDest))
      {
# if (PDUR_EXISTS_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM == STD_ON)
        case PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM: /* COV_PDUR_CROSSCORE_ROUTINGS_ONLY */
        {
          if(E_OK != PduR_RmIf_PerformImmediateDestinationDataProcessing(rmGDest, rmDest, destPduInfo, fmFifoElementRamIdx, FALSE))     /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
          {
            PduR_Det_ReportError(PDUR_RMIF_SINGLEBUFFERHANDLING, PDUR_E_PDU_INSTANCES_LOST);
          }
          break;
        }
# endif
# if (PDUR_EXISTS_DEFERRED_PDURDESTPDUPROCESSINGOFRMGDESTROM == STD_ON)
        case PDUR_DEFERRED_PDURDESTPDUPROCESSINGOFRMGDESTROM:
        {
          PduR_RmIf_PerformDeferredDestinationDataProcessing(rmDest, rmGDest);
          break;
        }
# endif
        default:       /* COV_PDUR_MISRA */
          /* Nothing to do: This should never be reached */
          break;
      }
    }
    else
    {
      PduR_Det_ReportError(PDUR_RMIF_SINGLEBUFFERHANDLING, PDUR_E_FATAL);
    }
  }
  else
  {
    PduR_Det_ReportError(PDUR_RMIF_SINGLEBUFFERHANDLING, PDUR_E_FATAL);
  }
}       /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if ((PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmIf_FifoHandling
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmIf_FifoHandling(PduR_RmDestRomIterType rmDest, PduR_RmGDestRomIdxOfRmDestRomType rmGDest, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  PduR_GetFctPtrOfRmIf_FifoHandling_StateHandler(PduR_GetIfSmStateOfRmBufferedIfPropertiesRam(PduR_GetRmBufferedIfPropertiesRomIdxOfRmGDestRom(rmGDest))) (rmDest, rmGDest, info);      /* SBSW_PDUR_CSL03 */
}
#endif

#if ((PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmIf_FifoHandling_StateHandler_WAIT_FOR_RXINDICATION
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmIf_FifoHandling_StateHandler_WAIT_FOR_RXINDICATION(PduR_RmDestRomIterType rmDest, PduR_RmGDestRomIdxOfRmDestRomType rmGDest,
                                                                                P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  PduR_FmFifoElementRamWriteIdxOfFmFifoRamType fmFifoElementRamIdx;

  if(PduR_RmIf_FiFoDataProcessing(rmDest, rmGDest, &fmFifoElementRamIdx, (PduR_BmTxBufferArrayRamLengthOfBmTxBufferRomType) info->SduLength, info->SduDataPtr) == E_OK) /* SBSW_PDUR_STACK_VARIABLE */ /* COV_PDUR_ONLY_DIRECT_BUFFER */
  {
    switch (PduR_GetPduRDestPduProcessingOfRmGDestRom(rmGDest))
    {
# if (PDUR_EXISTS_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM == STD_ON)
      case PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM:   /* COV_PDUR_CROSSCORE_ROUTINGS_ONLY */
      {
        if(E_OK != PduR_RmIf_PerformImmediateDestinationDataProcessing(rmGDest, rmDest, info, fmFifoElementRamIdx, TRUE))       /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
        {
          PduR_Fm_FlushFiFo(rmGDest);
          PduR_Det_ReportError(PDUR_FCT_RMIF_FQ, PDUR_E_PDU_INSTANCES_LOST);
        }
        break;
      }
# endif
# if (PDUR_EXISTS_DEFERRED_PDURDESTPDUPROCESSINGOFRMGDESTROM == STD_ON)
      case PDUR_DEFERRED_PDURDESTPDUPROCESSINGOFRMGDESTROM:
      {
        PduR_RmIf_PerformDeferredDestinationDataProcessing(rmDest, rmGDest);

#  if (PDUR_TXCONFIRMATIONSUPPORTEDOFRMSRCROM == STD_ON)        /* COV_PDUR_FEATURE_ALWAYS_TRUE */
        {
          /* Call upper layer confirmation immediately */
          PduR_RmSrcRomIdxOfRmDestRomType rmSrcRomIdx = PduR_GetRmSrcRomIdxOfRmDestRom(rmDest);
          if(PduR_IsTxConfirmationSupportedOfRmSrcRom(rmSrcRomIdx))
          {
            PduR_GetUpIfTxConfirmationFctPtrOfMmRom(PduR_GetMmRomIdxOfRmSrcRom(rmSrcRomIdx)) (PduR_GetSrcHndOfRmSrcRom(rmSrcRomIdx));   /* SBSW_PDUR_API_CALL_FORWARDING_ID_ONLY */
          }
        }
#  endif
        break;
      }
# endif
      default: /* COV_PDUR_MISRA */
        /* Nothing to do: This should never be reached */
        break;

    }
  }
}
#endif

#if ((PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmIf_FifoHandling_StateHandler_QueueNotEmpty
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
FUNC(void, PDUR_CODE) PduR_RmIf_FifoHandling_StateHandler_QueueNotEmpty(PduR_RmDestRomIterType rmDest, PduR_RmGDestRomIdxOfRmDestRomType rmGDest, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  PduR_FmFifoElementRamWriteIdxOfFmFifoRamType fmFifoElementRamIdx;
  if(PduR_RmIf_FiFoDataProcessing(rmDest, rmGDest, &fmFifoElementRamIdx, (PduR_BmTxBufferArrayRamLengthOfBmTxBufferRomType) info->SduLength, info->SduDataPtr) != E_OK) /* SBSW_PDUR_STACK_VARIABLE */
  {
    PduR_Fm_FlushFiFo(rmGDest);
    PduR_Det_ReportError(PDUR_FCT_RMIF_FQ, PDUR_E_PDU_INSTANCES_LOST);
# if(PDUR_RMGDESTNTO1INFORAMIDXOFRMGDESTROM == STD_ON)
    PduR_Rm_MultipleSourceHandler_Reset(rmGDest);
# endif

# if (PDUR_ERROR_NOTIFICATION == STD_ON)        /* COV_PDUR_ERROR_NOTIFICATION */
    ErrorNotificationQueueOverflow(PduR_GetDestHndOfRmGDestRom(rmGDest));
# endif
    if(PduR_RmIf_FiFoDataProcessing(rmDest, rmGDest, &fmFifoElementRamIdx, (PduR_BmTxBufferArrayRamLengthOfBmTxBufferRomType) info->SduLength, info->SduDataPtr) == E_OK)       /* SBSW_PDUR_STACK_VARIABLE */ /* COV_PDUR_FATAL_ERROR */
    {
      switch (PduR_GetPduRDestPduProcessingOfRmGDestRom(rmGDest))
      {
# if (PDUR_EXISTS_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM == STD_ON)
        case PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM: /* COV_PDUR_CROSSCORE_ROUTINGS_ONLY */
        {
          if(E_OK != PduR_RmIf_PerformImmediateDestinationDataProcessing(rmGDest, rmDest, info, fmFifoElementRamIdx, TRUE))     /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
          {
            PduR_Fm_FlushFiFo(rmGDest);
          }
          break;
        }
# endif
# if (PDUR_EXISTS_DEFERRED_PDURDESTPDUPROCESSINGOFRMGDESTROM == STD_ON)
        case PDUR_DEFERRED_PDURDESTPDUPROCESSINGOFRMGDESTROM:
        {
          PduR_RmIf_PerformDeferredDestinationDataProcessing(rmDest, rmGDest);

#  if (PDUR_TXCONFIRMATIONSUPPORTEDOFRMSRCROM == STD_ON)        /* COV_PDUR_FEATURE_ALWAYS_TRUE */
          {
            /* Call upper layer confirmation immediately */
            PduR_RmSrcRomIdxOfRmDestRomType rmSrcRomIdx = PduR_GetRmSrcRomIdxOfRmDestRom(rmDest);
            if(PduR_IsTxConfirmationSupportedOfRmSrcRom(rmSrcRomIdx))   /* COV_PDUR_FEATURE_ALWAYS_TRUE */
            {
              PduR_GetUpIfTxConfirmationFctPtrOfMmRom(PduR_GetMmRomIdxOfRmSrcRom(rmSrcRomIdx)) (PduR_GetSrcHndOfRmSrcRom(rmSrcRomIdx)); /* SBSW_PDUR_API_CALL_FORWARDING_ID_ONLY */
            }
          }
#  endif
          break;
        }
# endif
        default:       /* COV_PDUR_MISRA */
          /* Nothing to do: This should never be reached */
          break;
      }
    }
  }
# if ((PDUR_EXISTS_DEFERRED_PDURDESTPDUPROCESSINGOFRMGDESTROM == STD_ON) && (PDUR_TXCONFIRMATIONSUPPORTEDOFRMSRCROM == STD_ON))
  else
  {
    if(PduR_GetPduRDestPduProcessingOfRmGDestRom(rmGDest) == PDUR_DEFERRED_PDURDESTPDUPROCESSINGOFRMGDESTROM)   /* COV_PDUR_FEATURE_ALWAYS_TRUE */
    {
      /* Call upper layer confirmation immediately */
      PduR_RmSrcRomIdxOfRmDestRomType rmSrcRomIdx = PduR_GetRmSrcRomIdxOfRmDestRom(rmDest);
      if(PduR_IsTxConfirmationSupportedOfRmSrcRom(rmSrcRomIdx))
      {
        PduR_GetUpIfTxConfirmationFctPtrOfMmRom(PduR_GetMmRomIdxOfRmSrcRom(rmSrcRomIdx)) (PduR_GetSrcHndOfRmSrcRom(rmSrcRomIdx));       /* SBSW_PDUR_API_CALL_FORWARDING_ID_ONLY */
      }
    }
  }
# endif
}
#endif

/**********************************************************************************************************************
 * PduR_RmIf_FiFoDataProcessing
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
#if ((PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_RmIf_FiFoDataProcessing(PduR_RmDestRomIterType rmDest, PduR_RmGDestRomIterType rmGDest,
                                                                          PduR_FmFifoElementRamWriteIdxOfFmFifoRamType * fmFifoElementRamIdx,
                                                                          PduR_BmTxBufferArrayRamLengthOfBmTxBufferRomType pduLength, SduDataPtrType sduDataPtr)
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_FmFifoRomIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDest));
  if(PduR_Fm_AssignFifoElement(fmFifoRomIdx, fmFifoElementRamIdx) == E_OK)      /* SBSW_PDUR_STACK_VARIABLE */
  {
    PduR_RmBufferedIfPropertiesRomIdxOfRmGDestRomType rmBufferedIfPropertiesRomIdx = PduR_GetRmBufferedIfPropertiesRomIdxOfRmGDestRom(rmGDest);
    PduLengthType bufferSizePtr = 0u;
    PduR_BmTxBufferRomIdxOfBmTxBufferIndRomType allocatedTxBufferIdxPtr = 0u;
    /* Update fill level */
    PduR_IncFillLevelOfFmFifoRam(fmFifoRomIdx); /* SBSW_PDUR_CSL03 */
    if(PduR_Bm_AllocateTxBuffer(PduR_GetBmTxBufferIndRomStartIdxOfRmBufferedIfPropertiesRom(rmBufferedIfPropertiesRomIdx), PduR_GetBmTxBufferIndRomEndIdxOfRmBufferedIfPropertiesRom(rmBufferedIfPropertiesRomIdx), *fmFifoElementRamIdx, pduLength, &bufferSizePtr, &allocatedTxBufferIdxPtr, FALSE) == BUFREQ_OK)     /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
    {
      PduR_Fm_AssignTxBuffer2FifoElement(*fmFifoElementRamIdx, allocatedTxBufferIdxPtr);
      PduR_SetStateOfFmFifoElementRam(*fmFifoElementRamIdx, PDUR_FM_ALLOCATED_WITH_BUFFER_STATEOFFMFIFOELEMENTRAM);     /* SBSW_PDUR_CSL01 */
      PduR_SetRmDestRomIdxOfFmFifoElementRam(*fmFifoElementRamIdx, (PduR_RmDestRomIdxOfFmFifoElementRamType) rmDest);   /* SBSW_PDUR_CSL01 */
      PduR_RmIf_CopyRxData(*fmFifoElementRamIdx, pduLength, sduDataPtr);        /* SBSW_PDUR_STACK_VARIABLE */
      retVal = E_OK;
    }
    else
    {
      PduR_Fm_FreeFifoElement(fmFifoRomIdx, *fmFifoElementRamIdx);
    }
  }
  return retVal;
}
#endif

#if(PDUR_EXISTS_IF_NOBUFFER_GATEWAY_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmIf_RxIndicationNoBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmIf_RxIndicationNoBuffer(PduR_RmDestRomIterType rmDestIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  PduR_Lock_LockRoutingPathByDestPdu(rmDestIdx);
  if(E_OK != PduR_RmIf_MultipleSourceHandler_Transmit(rmDestIdx, info, FALSE))  /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
  {
    PduR_Det_ReportError(PDUR_FCT_RMIF_FQ, PDUR_E_PDU_INSTANCES_LOST);
  }
  PduR_Lock_UnlockRoutingPathByDestPdu(rmDestIdx);
}
#endif

#if((PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmIf_Forward2Buffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmIf_Forward2Buffer(PduR_RmDestRomIterType rmDestIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
# if(PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON)
  if(PduR_GetFifoTypeOfRmBufferedIfPropertiesRom(PduR_GetRmBufferedIfPropertiesRomIdxOfRmGDestRom(PduR_GetRmGDestRomIdxOfRmDestRom(rmDestIdx))) == PDUR_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM)  /* COV_PDUR_FEATURE_ALWAYS_TRUE */
  {
    PduR_RmIf_RxIndicationTTSingleBuffer(rmDestIdx, info);      /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
  }
# endif
# if(((PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON)) && (PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
  else
# endif
# if((PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
  {
    PduR_RmIf_RxIndicationFifoBuffer(rmDestIdx, info);  /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
  }
# endif
}
#endif

#if(PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmIf_RxIndicationTTSingleBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmIf_RxIndicationTTSingleBuffer(PduR_RmDestRomIterType rmDestIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  PduR_RmGDestRomIdxOfRmDestRomType rmGDest = PduR_GetRmGDestRomIdxOfRmDestRom(rmDestIdx);
  PduInfoType destPduInfo;
  PduR_Lock_LockRoutingPathByDestPdu(rmDestIdx);
  destPduInfo.SduDataPtr = info->SduDataPtr;
  destPduInfo.SduLength = PduR_RmIf_CalcDlc(rmGDest, info);     /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
  PduR_RmIf_SingleBufferHandling(rmDestIdx, rmGDest, info, &destPduInfo);       /* SBSW_PDUR_STACK_VARIABLE */
  PduR_Lock_UnlockRoutingPathByDestPdu(rmDestIdx);
}
#endif

#if((PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
 /**********************************************************************************************************************
 * PduR_RmIf_RxIndicationFifoBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmIf_RxIndicationFifoBuffer(PduR_RmDestRomIterType rmDestIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  PduR_RmGDestRomIdxOfRmDestRomType rmGDest = PduR_GetRmGDestRomIdxOfRmDestRom(rmDestIdx);
  PduInfoType destPduInfo;
  PduR_Lock_LockRoutingPathByDestPdu(rmDestIdx);
  destPduInfo.SduDataPtr = info->SduDataPtr;
  destPduInfo.SduLength = PduR_RmIf_CalcDlc(rmGDest, info);     /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
  PduR_RmIf_FifoHandling(rmDestIdx, rmGDest, &destPduInfo);     /* SBSW_PDUR_STACK_VARIABLE */
  PduR_Lock_UnlockRoutingPathByDestPdu(rmDestIdx);
}
#endif

#if((PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
 /**********************************************************************************************************************
 * PduR_RmIf_CopyRxData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmIf_CopyRxData(PduR_FmFifoElementRamIterType fmFifoElementRamIdx, PduR_BmTxBufferArrayRamIterType pduLength, SduDataPtrType sduDataPtr)
{
  PduR_BmTxBufferRomIterType bmTxBufferRomIdx = PduR_GetBmTxBufferRomIdxOfFmFifoElementRam(fmFifoElementRamIdx);
  PduR_SetStateOfFmFifoElementRam(fmFifoElementRamIdx, PDUR_FM_ALLOCATED_WITH_BUFFER_STATEOFFMFIFOELEMENTRAM);  /* SBSW_PDUR_CSL01 */
  PduR_GetFctPtrOfFm_ActivateWrite_FmSmStateHandler(PduR_GetStateOfFmFifoElementRam(fmFifoElementRamIdx)) (fmFifoElementRamIdx);        /* SBSW_PDUR_CSL03 */
  (void) PduR_Bm_PutData(bmTxBufferRomIdx, pduLength, sduDataPtr);      /* SBSW_PDUR_STACK_VARIABLE */
  PduR_GetFctPtrOfFm_FinishWrite_FmSmStateHandler(PduR_GetStateOfFmFifoElementRam(fmFifoElementRamIdx)) (fmFifoElementRamIdx, E_OK);    /* SBSW_PDUR_CSL03 */
}
#endif

#if((PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
 /**********************************************************************************************************************
 * PduR_RmIf_TransmitPreparation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmIf_TransmitPreparation(PduR_RmGDestRomIterType rmGDest, PduR_FmFifoElementRamIterType fmFifoElementRamIdx)
{
  PduR_BmTxBufferRomIterType bmTxBufferRomIdx = PduR_GetBmTxBufferRomIdxOfFmFifoElementRam(fmFifoElementRamIdx);
  PduR_RmBufferedIfPropertiesRomIdxOfRmGDestRomType rmBufferedIfPropertiesRomIdx = PduR_GetRmBufferedIfPropertiesRomIdxOfRmGDestRom(rmGDest);
  PduR_SetIfSmStateOfRmBufferedIfPropertiesRam(rmBufferedIfPropertiesRomIdx, PduR_GetNextState_For_Wait_For_RxIndicationOfIfRoutingStateTable(PduR_GetFifoTypeOfRmBufferedIfPropertiesRom(rmBufferedIfPropertiesRomIdx)));      /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  PduR_RmIf_AssignAssociatedBuffer2Destination(bmTxBufferRomIdx, rmGDest);
  PduR_GetFctPtrOfFm_ActivateRead_FmSmStateHandler(PduR_GetStateOfFmFifoElementRam(fmFifoElementRamIdx)) (fmFifoElementRamIdx); /* SBSW_PDUR_CSL03 */
}
#endif

#if((PDUR_EXISTS_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON) || (PDUR_EXISTS_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON) || (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON) || (PDUR_EXISTS_IF_NOBUFFER_GATEWAY_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmIf_RxIndication_MultiIf
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
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmIf_RxIndication_MultiIf(PduR_RmSrcRomIterType rmSrcIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */

  {
    /* ----- Implementation ----------------------------------------------- */
    PduR_RmDestRomIterType rmDestIdx;

# if (PDUR_SMDATAPLANEROM == STD_ON)
    /* #10 Call switching manager filter function if configured */
    if(PduR_IsSmSrcRomUsedOfRmSrcRom(rmSrcIdx))
    {
      PduR_SmSrcRomIdxOfRmSrcRomType smSrcRomIdx = PduR_GetSmSrcRomIdxOfRmSrcRom(rmSrcIdx);
      PduR_GetSmSrcFilterFctPtr(PduR_GetSmSrcFilterFctPtrIdxOfSmSrcRom(smSrcRomIdx)) (smSrcRomIdx, info);       /* SBSW_PDUR_CSL03 */
    }
# endif

    /* #20 For each destination of 1:N Routing */
    for(rmDestIdx = PduR_GetRmDestRomStartIdxOfRmSrcRom(rmSrcIdx); rmDestIdx < PduR_GetRmDestRomEndIdxOfRmSrcRom(rmSrcIdx); rmDestIdx++)
    {
# if (PDUR_RPGROM == STD_ON)
      /* #30 If Routing path group is enabled */
      if((!PduR_IsRmDestRpgRomUsedOfRmDestRom(rmDestIdx)) || (0u != PduR_GetEnabledCntOfRmDestRpgRam(PduR_GetRmDestRpgRomIdxOfRmDestRom(rmDestIdx))))
# endif
      {
# if (PDUR_SMDATAPLANEROM == STD_ON)
        PduR_RmGDestRomIterType rmGDestRomIdx = PduR_GetRmGDestRomIdxOfRmDestRom(rmDestIdx);
        PduR_FilterReturnType filterResult = PDUR_FILTER_PASS;
        /* #40 If Switching manager destination filter function passes or is not configured */
        if(PduR_IsSmGDestRomUsedOfRmGDestRom(rmGDestRomIdx))
        {
          PduR_SmGDestRomIdxOfRmGDestRomType smGDestRomIdx = PduR_GetSmGDestRomIdxOfRmGDestRom(rmGDestRomIdx);
          filterResult = PduR_GetSmGDestFilterFctPtr(PduR_GetSmGDestFilterFctPtrIdxOfSmGDestRom(smGDestRomIdx)) (smGDestRomIdx, info);  /* SBSW_PDUR_CSL03 */
        }
        if(filterResult == PDUR_FILTER_PASS)
# endif
        {
# if (PDUR_MCQBUFFERROM == STD_ON)
          PduR_CoreManagerRomIdxOfMmRomType destCoreIdx = PduR_GetCoreManagerRomIdxOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(PduR_GetRmGDestRomIdxOfRmDestRom(rmDestIdx)));
          PduR_CoreManagerRomIdxOfMmRomType srcCoreIdx = PduR_GetCoreManagerRomIdxOfMmRom(PduR_GetMmRomIdxOfRmSrcRom(PduR_GetRmSrcRomIdxOfRmDestRom(rmDestIdx)));

          /* #50 In IF-cross-core routing use case, write data into multicore queue and return E_OK. Call DET, if queue is already full and return E_NOT_OK */
          if((srcCoreIdx != destCoreIdx)
#  if (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
             && (PduR_GetRoutingTypeOfRmDestRom(rmDestIdx) != PDUR_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM)
#  endif
            )   /* COV_PDUR_CROSSCORE_ROUTINGS_ONLY */
          {
            if(PduR_McQ_WriteData(PduR_GetMcQBufferRomIdxOfSrcCoreRom(PduR_GetSrcCoreRomStartIdxOfCoreManagerRom(destCoreIdx) + srcCoreIdx), (PduR_RmDestRomEndIdxOfRmSrcRomType) rmDestIdx, info) == E_OK)     /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
            {
              retVal &= E_OK;
            }
            else
            {
              PduR_Det_ReportError(PDUR_FCT_MULTIIFRXIND, PDUR_E_MCQ_QUEUE_OVERFLOW);
              retVal &= E_NOT_OK;
            }
          }
          /* #60 otherwise, call destination Indication function and return it's result */
          else
# endif
          {
            retVal &= PduR_RmIf_DispatchIfDestPdu((PduR_RmDestRomEndIdxOfRmSrcRomType) rmDestIdx, info);        /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
          }
        }
      }
      /* #70 Otherwise return E_OK */
    }
  }

  PDUR_DUMMY_STATEMENT(rmSrcIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(retVal); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return retVal;
}
#endif

#if((PDUR_EXISTS_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON) || (PDUR_EXISTS_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON) || (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON) || (PDUR_EXISTS_IF_NOBUFFER_GATEWAY_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmIf_DispatchIfDestPdu
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmIf_DispatchIfDestPdu(PduR_RmDestRomEndIdxOfRmSrcRomType rmDestRomIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */

  PduR_RmGDestRomIdxOfRmDestRomType rmGDestRomIdx = PduR_GetRmGDestRomIdxOfRmDestRom(rmDestRomIdx);

  switch (PduR_GetRoutingTypeOfRmDestRom(rmDestRomIdx))
  {
# if (PDUR_EXISTS_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON)
    case PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM:
      PduR_GetUpIfRxIndicationFctPtrOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(rmGDestRomIdx)) (PduR_GetDestHndOfRmGDestRom(rmGDestRomIdx), info);    /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
      retVal = E_OK;
      break;
# endif
# if (PDUR_EXISTS_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON)
    case PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM:
      retVal = PduR_RmIf_MultipleSourceHandler_Transmit(rmDestRomIdx, info, !PduR_IsRmDestRomUsedOfRmGDestRom(rmGDestRomIdx));  /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
      break;
# endif
# if (PDUR_EXISTS_IF_NOBUFFER_GATEWAY_ROUTINGTYPEOFRMDESTROM == STD_ON)
    case PDUR_IF_NOBUFFER_GATEWAY_ROUTINGTYPEOFRMDESTROM:
      retVal = PduR_RmIf_ProcessNoBufferedGwRouting(rmDestRomIdx, info);        /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
      break;
# endif
# if (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
    case PDUR_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM:
      retVal = PduR_RmIf_ProcessBufferedRouting(PduR_GetRmSrcRomIdxOfRmDestRom(rmDestRomIdx), rmDestRomIdx, rmGDestRomIdx, info);       /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
      break;
# endif
    default:   /* COV_PDUR_MISRA */
      /* Nothing to do: This should never be reached */
      break;
  }

  return retVal;
}
#endif

#if (PDUR_EXISTS_IF_NOBUFFER_GATEWAY_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmIf_ProcessNoBufferedGwRouting
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_RmIf_ProcessNoBufferedGwRouting(PduR_RmDestRomIterType rmDestIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
# if (PDUR_DEV_ERROR_DETECT == STD_ON)  /* COV_PDUR_VAR_DEV_ERROR_DETECT */
  /* Check parameter 'info' */
  if(info == NULL_PTR)  /* COV_PDUR_CROSSCORE_ROUTINGS_ONLY */
  {
    errorId = PDUR_E_PARAM_POINTER;
  }
  else if(info->SduDataPtr == NULL_PTR) /* COV_PDUR_CROSSCORE_ROUTINGS_ONLY */
  {
    errorId = PDUR_E_PARAM_POINTER;
  }
  else
# endif
  {
    PduR_RmIf_RxIndicationNoBuffer(rmDestIdx, info);    /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
    retVal = E_OK;
  }
/* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)        /* COV_PDUR_CROSSCORE_ROUTINGS_ONLY */
  {
    PduR_Det_ReportError(PDUR_FCT_MULTIIFRXIND, errorId);
  }
# endif
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return retVal;
}
#endif

#if (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmIf_ProcessBufferedRouting
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_RmIf_ProcessBufferedRouting(PduR_RmSrcRomIterType rmSrcIdx, PduR_RmDestRomIterType rmDestIdx, PduR_RmGDestRomIterType rmGDestRomIdx,
                                                                              P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
# if (PDUR_DEV_ERROR_DETECT == STD_ON)  /* COV_PDUR_VAR_DEV_ERROR_DETECT */
  /* Check parameter 'info' */
  if(info == NULL_PTR)
  {
    errorId = PDUR_E_PARAM_POINTER;
  }
  else if(info->SduDataPtr == NULL_PTR)
  {
    errorId = PDUR_E_PARAM_POINTER;
  }
  else
# endif
  {
# if (PDUR_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM == STD_ON)
    if((PduR_GetPduLengthHandlingStrategyOfRmDestRom(rmDestIdx) == PDUR_SHORTEN_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM)
       || (info->SduLength <= PduR_GetMaxPduLengthOfRmBufferedIfPropertiesRom(PduR_GetRmBufferedIfPropertiesRomIdxOfRmGDestRom(rmGDestRomIdx))))
# endif
    {
# if (PDUR_TRIGGERTRANSMITSUPPORTEDOFRMSRCROM == STD_ON)
      if(PduR_IsTriggerTransmitSupportedOfRmSrcRom(rmSrcIdx))
      {
        uint8 sduData[PDUR_MAX_TRIGGER_TRANSMIT_PDU_SIZE] = { 0u };
        PduInfoType pduInfo;
        pduInfo.SduDataPtr = sduData;
        pduInfo.SduLength = PduR_GetMaxPduLengthOfRmBufferedIfPropertiesRom(PduR_GetRmBufferedIfPropertiesRomIdxOfRmGDestRom(rmGDestRomIdx));

        retVal &= PduR_GetUpIfTriggerTransmitFctPtrOfMmRom(PduR_GetMmRomIdxOfRmSrcRom(rmSrcIdx)) (PduR_GetSrcHndOfRmSrcRom(rmSrcIdx), &pduInfo);        /* SBSW_PDUR_CSL03 */
        PduR_RmIf_Forward2Buffer(rmDestIdx, &pduInfo);  /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
      }
      else
# endif
      {
        PduR_RmIf_Forward2Buffer(rmDestIdx, info);      /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
        retVal &= E_OK;
      }
    }
  }
/* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_MULTIIFRXIND, errorId);
  }
# endif
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(rmSrcIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(rmGDestRomIdx);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return retVal;
}
#endif

#if ((PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmIf_TriggerTransmit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_RmIf_TriggerTransmit(PduR_RmDestRomIterType rmDestIdx, CONSTP2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  /* ----- Development Error Checks ------------------------------------- */
# if (PDUR_DEV_ERROR_DETECT == STD_ON)  /* COV_PDUR_VAR_DEV_ERROR_DETECT */
  /* Check parameter 'info' */
  if(info == NULL_PTR)
  {
    errorId = PDUR_E_PARAM_POINTER;
  }
  else if(info->SduDataPtr == NULL_PTR)
  {
    errorId = PDUR_E_PARAM_POINTER;
  }
  else
# endif
  {
    PduR_Lock_LockRoutingPathByDestPdu(rmDestIdx);
    {
      PduR_RmGDestRomIterType rmGDestIdx = PduR_GetRmGDestRomIdxOfRmDestRom(rmDestIdx);
      PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx = PduR_GetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestIdx));

      if(bmTxBufferInstanceRomIdx != PDUR_NO_BMTXBUFFERINSTANCEROMIDXOFFMFIFOINSTANCERAM)       /* COV_PDUR_ONLY_DIRECT_BUFFER */
      {
        if(info->SduLength >= ((PduR_BmTxBufferArrayRamIterType) PduR_Bm_GetLinearDataSizeInstance(bmTxBufferInstanceRomIdx)))
        {
          PduR_RmBufferedIfPropertiesRomIdxOfRmGDestRomType rmBufferedIfPropertiesRomIdx = PduR_GetRmBufferedIfPropertiesRomIdxOfRmGDestRom(rmGDestIdx);
          info->SduLength = (PduLengthType) PduR_Bm_GetLinearDataSizeInstance(bmTxBufferInstanceRomIdx);        /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
          PduR_Bm_CopyData(bmTxBufferInstanceRomIdx, (PduR_BmTxBufferArrayRamIterType) info->SduLength, info->SduDataPtr);      /* SBSW_PDUR_STACK_VARIABLE */

# if (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON)
          if(PduR_GetIfSmStateOfRmBufferedIfPropertiesRam(rmBufferedIfPropertiesRomIdx) == PDUR_WAIT_FOR_TRIGGERTRANSMIT_IFSMSTATEOFRMBUFFEREDIFPROPERTIESRAM)
# endif
          {
            /* The Queue is not empty in this states return E_OK */
            PduR_SetIfSmStateOfRmBufferedIfPropertiesRam(rmBufferedIfPropertiesRomIdx, PduR_GetNextState_For_Wait_For_TriggerTransmitOfIfRoutingStateTable(PduR_GetFifoTypeOfRmBufferedIfPropertiesRom(rmBufferedIfPropertiesRomIdx))); /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
            retVal = E_OK;
          }
# if (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON)
          else
          {
            PduR_Fm_FlushFiFo(rmGDestIdx);
#  if(PDUR_RMGDESTNTO1INFORAMIDXOFRMGDESTROM == STD_ON)
            PduR_Rm_MultipleSourceHandler_Reset(rmGDestIdx);
#  endif
          }
# endif
        }
      }
    }
    PduR_Lock_UnlockRoutingPathByDestPdu(rmDestIdx);
  }
  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_RMIF_TXTT, errorId);
  }
# else
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif
  return retVal;
}       /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#if(PDUR_HASIFTXFIFOOFGENERALPROPERTIESROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmIf_TxConfirmation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmIf_TxConfirmation(PduR_RmGDestRomIdxOfTxIf2UpType rmGDestRomIdx)
{
  PduR_Lock_LockRoutingPathByGDestPdu(rmGDestRomIdx);
  {
    PduR_GetFctPtrOfRmIf_TxConfirmation_StateHandler(PduR_GetIfSmStateOfRmBufferedIfPropertiesRam(PduR_GetRmBufferedIfPropertiesRomIdxOfRmGDestRom(rmGDestRomIdx))) ((PduR_RmGDestRomIterType) rmGDestRomIdx);  /* SBSW_PDUR_CSL03 */
  }
  PduR_Lock_UnlockRoutingPathByGDestPdu(rmGDestRomIdx);
}
#endif

#if(PDUR_HASIFTXFIFOOFGENERALPROPERTIESROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmIf_TxConfirmation_StateHandler_WAIT_FOR_TXCONFIRMATION
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmIf_TxConfirmation_StateHandler_WAIT_FOR_TXCONFIRMATION(PduR_RmGDestRomIterType rmGDestRomIdx)
{
  PduR_RmBufferedIfPropertiesRomIdxOfRmGDestRomType rmBufferedIfPropertiesRomIdx = PduR_GetRmBufferedIfPropertiesRomIdxOfRmGDestRom(rmGDestRomIdx);
  PduR_FmFifoInstanceRamIterType fmFifoRomInstanceIdx = PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx);

  PduR_FmFifoRamIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(fmFifoRomInstanceIdx);
  PduR_FmFifoElementRamIterType fmFifoElementRamReadIdx = PduR_GetFmFifoElementRamReadIdxOfFmFifoRam(fmFifoRomIdx);
  PduR_FmFifoElementRamIterType peekedfmFifoElementRamReadIdx;
  PduR_GetFctPtrOfFm_FinishRead_FmSmStateHandler(PduR_GetStateOfFmFifoElementRam(fmFifoElementRamReadIdx)) (fmFifoElementRamReadIdx, E_OK);     /* SBSW_PDUR_CSL03 */
  PduR_Bm_ResetTxBufferInstance(PduR_GetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx)));
  PduR_SetIfSmStateOfRmBufferedIfPropertiesRam(rmBufferedIfPropertiesRomIdx, PduR_GetNextState_For_Init_If_Routing_StateOfIfRoutingStateTable(PduR_GetFifoTypeOfRmBufferedIfPropertiesRom(rmBufferedIfPropertiesRomIdx)));      /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  if(PduR_Fm_Peek(fmFifoRomIdx, &peekedfmFifoElementRamReadIdx) == E_OK)        /* SBSW_PDUR_STACK_VARIABLE */
  {
    PduR_RmIf_TransmitPreparation(rmGDestRomIdx, peekedfmFifoElementRamReadIdx);
    {
      PduInfoType destPduInfo;
      PduR_RmDestRomIdxOfFmFifoElementRamType rmDestRomIdx = PduR_GetRmDestRomIdxOfFmFifoElementRam(peekedfmFifoElementRamReadIdx);
      PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx = PduR_GetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx));
      PduR_Bm_CopyDataAsPtr(bmTxBufferInstanceRomIdx, &destPduInfo, PduR_Bm_GetLinearDataSizeInstance(bmTxBufferInstanceRomIdx));       /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
      if(E_OK != PduR_RmIf_MultipleSourceHandler_Transmit(rmDestRomIdx, &destPduInfo, TRUE))    /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
      {
        PduR_Fm_FlushFiFo(rmGDestRomIdx);
        PduR_Det_ReportError(PDUR_FCT_RMIF_TXCONF, PDUR_E_PDU_INSTANCES_LOST);
      }
    }
  }
}       /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if(PDUR_HASIFTXFIFOOFGENERALPROPERTIESROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmIf_TxConfirmation_StateHandler_UnexpectedCall
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmIf_TxConfirmation_StateHandler_UnexpectedCall(PduR_RmGDestRomIterType rmGDestRomIdx)
{
  PduR_Fm_FlushFiFo(rmGDestRomIdx);
# if(PDUR_RMGDESTNTO1INFORAMIDXOFRMGDESTROM == STD_ON)
  PduR_Rm_MultipleSourceHandler_Reset(rmGDestRomIdx);
# endif
  PduR_Det_ReportError(PDUR_FCT_RMIF_TXCONF, PDUR_E_PDU_INSTANCES_LOST);
}
#endif

#if((PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmIf_CalcDlc
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
LOCAL_INLINE FUNC(PduLengthType, PDUR_CODE) PduR_RmIf_CalcDlc(PduR_RmGDestRomIdxOfRmDestRomType rmGDest, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  /* if the length is shorter or equal use the provided length */
  PduLengthType dataLengthcopy = info->SduLength;
  /* MaxPduLength of no buffer routings is set to the maximum allowed value for this datatype, thus disabling this check */
  if(info->SduLength > PduR_GetMaxPduLengthOfRmBufferedIfPropertiesRom(PduR_GetRmBufferedIfPropertiesRomIdxOfRmGDestRom(rmGDest)))
  {
    /* if the provided length is greater than the maximum buffer size the value is truncated to this value. */
    dataLengthcopy = PduR_GetMaxPduLengthOfRmBufferedIfPropertiesRom(PduR_GetRmBufferedIfPropertiesRomIdxOfRmGDestRom(rmGDest));
  }
  PDUR_DUMMY_STATEMENT(rmGDest);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return dataLengthcopy;
}
#endif

#if ((PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmIf_AssignAssociatedBuffer2Destination
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_RmIf_AssignAssociatedBuffer2Destination(PduR_BmTxBufferRomIterType bmTxBufferRomIdx, PduR_RmGDestRomIterType rmGDestRomIdx)
{
  PduR_BmTxBufferInstanceRomStartIdxOfBmTxBufferRomType bmTxBufferInstanceRomIdx = PduR_GetBmTxBufferInstanceRomStartIdxOfBmTxBufferRom(bmTxBufferRomIdx);
  PduR_Bm_AssignAssociatedBuffer2DestinationInstance(bmTxBufferRomIdx, bmTxBufferInstanceRomIdx);
  PduR_SetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx), bmTxBufferInstanceRomIdx);       /* SBSW_PDUR_CSL03 */
}
#endif

#if((PDUR_MAIN_FUNCTION == STD_ON) && (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmIf_MainFunction
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
FUNC(void, PDUR_CODE) PduR_RmIf_MainFunction(PduR_RmGDestRomIterType rmGDestRomIdx)
{
  /* #10 If Pdu is a deferred IF-Pdu and processing is required */
  if(PduR_IsRmBufferedIfPropertiesRomUsedOfRmGDestRom(rmGDestRomIdx) && (PduR_GetIfSmStateOfRmBufferedIfPropertiesRam(PduR_GetRmBufferedIfPropertiesRomIdxOfRmGDestRom(rmGDestRomIdx)) == PDUR_WAIT_FOR_DEFERRED_PROCESSING_IFSMSTATEOFRMBUFFEREDIFPROPERTIESRAM))      /* COV_PDUR_ROBUSTNESS */
  {
    PduR_Lock_LockRoutingPathByGDestPdu(rmGDestRomIdx);
    {
      switch (PduR_GetDirectionOfRmGDestRom(rmGDestRomIdx))
      {
# if(PDUR_EXISTS_TX_DIRECTIONOFRMGDESTROM == STD_ON)    /* COV_PDUR_VAR_NO_RX_ONLY_CONFIG */
          /* #20 If direction of global dest Pdu is TX */
        case PDUR_TX_DIRECTIONOFRMGDESTROM:
        {
          PduR_FmFifoElementRamIterType peekedfmFifoElementRamReadIdx = 0u;
          PduInfoType destPduInfo;

          /* #30 Get buffered PduInfo and trigger the transmission on the destination buses */
          PduR_RmIf_GetBufferedPduInfo(rmGDestRomIdx, &destPduInfo, &peekedfmFifoElementRamReadIdx);    /* SBSW_PDUR_STACK_VARIABLE */
          {
            Std_ReturnType retValTramsmit = E_NOT_OK;   /* PRQA S 2981 */ /* MD_MSR_RetVal */
            PduR_RmDestRomIdxOfFmFifoElementRamType rmDestRomIdx = PduR_GetRmDestRomIdxOfFmFifoElementRam(peekedfmFifoElementRamReadIdx);

#  if(PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON)
            if(PduR_GetFifoTypeOfRmBufferedIfPropertiesRom(PduR_GetRmBufferedIfPropertiesRomIdxOfRmGDestRom(rmGDestRomIdx)) == PDUR_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM)      /* COV_PDUR_FEATURE_ALWAYS_TRUE */ /* PRQA S 2995, 2996, 2991 */ /* MD_PduR_2995_2996, MD_PduR_2995_2996, MD_PduR_2991 */
            {
              retValTramsmit = PduR_RmIf_MultipleSourceHandler_Transmit(rmDestRomIdx, &destPduInfo, FALSE);     /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
            }
            else
#  endif
            {
              retValTramsmit = PduR_RmIf_MultipleSourceHandler_Transmit(rmDestRomIdx, &destPduInfo, TRUE);      /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */ /* PRQA S 2880 */ /* MD_PduR_2880 */
            }

            /* #40 Reset routing if transmit failed and release the TxBuffer */
            if(retValTramsmit != E_OK)
            {
              PduR_Fm_FlushFiFo(rmGDestRomIdx);
              PduR_Det_ReportError(PDUR_FCT_MAINFUNCTION_TX, PDUR_E_PDU_INSTANCES_LOST);
            }
          }
          break;
        }
# endif
# if(PDUR_EXISTS_RX_DIRECTIONOFRMGDESTROM == STD_ON)
          /* #50 If direction of global dest Pdu is RX, get buffered PduInfo and call upper layer IF Rx Indication function */
        case PDUR_RX_DIRECTIONOFRMGDESTROM:
        {
          PduR_FmFifoElementRamIterType peekedfmFifoElementRamReadIdx = 0u;
          PduInfoType destPduInfo;

          PduR_RmIf_GetBufferedPduInfo(rmGDestRomIdx, &destPduInfo, &peekedfmFifoElementRamReadIdx);    /* SBSW_PDUR_STACK_VARIABLE */
          PduR_RmIf_TransmitPreparation(rmGDestRomIdx, peekedfmFifoElementRamReadIdx);
          PduR_GetUpIfRxIndicationFctPtrOfMmRom(PduR_GetMmRomIdxOfRmGDestRom(rmGDestRomIdx)) (PduR_GetDestHndOfRmGDestRom(rmGDestRomIdx), &destPduInfo);        /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */

          break;
        }
# endif
        default:       /* COV_PDUR_MISRA */
          /* Will never be reached */
          break;
      }
    }
    PduR_Lock_UnlockRoutingPathByGDestPdu(rmGDestRomIdx);
  }
}       /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: PduR_RmIf.c
 *********************************************************************************************************************/
