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
 *         File:  PduR_RmTp.h
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
#if !defined (PDUR_RMTP_H)
# define PDUR_RMTP_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "PduR_Types.h"
# include "PduR_Cfg.h"
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
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_Init
 *********************************************************************************************************************/
/*! \brief       This function initializes the PDUR transport protocol routings.
 *  \details     -
 *  \pre         PduR_InitMemory() has been executed, if the startup code does not initialise variables.
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \note        The function must be called on task level and has not to be interrupted
 *               by other administrative function calls.
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_Init(void);
# endif

# if (PDUR_DEDICATEDTXBUFFEROFRMBUFFEREDTPPROPERTIESROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_Init_DedicatedTxBuffer
 *********************************************************************************************************************/
/*! \brief       This function assign dedicated buffer to routing pathways
 *  \details     -
 *  \pre         PduR_InitMemory() has been executed, if the start up code does not initialize variables.
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \note        The function must be called on task level and has not to be interrupted
 *               by other administrative function calls.
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_Init_DedicatedTxBuffer(void);
# endif

# if((PDUR_EXISTS_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON) || (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
  PduR_RmTp_MultipleSourceHandler_CopyTxData
**********************************************************************************************************************/
/*! \brief       This function is called by the PduR GwTp multiple times to query the transmit data of an I-PDU segment.
 *  \details     Each call to this function copies the next part of the transmit.
 *  \param[in]   rmGDestRomIdx            ID of the transmitted GwIf I-PDU
 *  \param[in]   info                        Pointer to the destination buffer and the number of bytes to copy.
 *                                          In case of gateway the PDU Router module will copy otherwise the source upper layer
 *                                          module will copy the data. If not enough transmit data is available, no data is copied.
 *
 *                                          A copy size of 0 can be used to indicate state changes in the retry parameter.
 *  \param[in]   retry                       not supported
 *  \param[out]  availableDataPtr           Indicates the remaining number of bytes that are available in the PduR Tx buffer.
 *                                          AvailableTxDataCntPtr can be used by TP modules that support dynamic payload lengths
 *                                          (e.g. Iso FrTp) to determine the size of the following CFs.
 *  \return      BufReq_ReturnType
 *               BUFREQ_OK                   The data has been copied to the transmit buffer successfully.
 *               BUFREQ_E_NOT_OK             PduR_Init() has not been called
 *                                          or the GwTpTxPduId is not valid
 *                                          or the GwTpTxPduId is not forwarded in this identity
 *                                          or the info is not valid
 *                                          or the request was not accepted by the upper layer and no data has been copied.
 *               BUFREQ_E_BUSY               The request cannot be processed because the TX data is not available
 *                                           and no data has been copied. The TP layer might retry later the copy process.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
**********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_MultipleSourceHandler_CopyTxData(PduR_RmGDestRomIdxOfTxTp2SrcType rmGDestRomIdx, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
                                                                              P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr);
# endif

# if((PDUR_EXISTS_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON) || (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
  PduR_RmTp_MultipleSourceHandler_TpTxConfirmation
**********************************************************************************************************************/
/*! \brief        The function is called to confirm or abort a transport protocol I-PDU routing.
 *  \details      The PDU Router evaluates the Gw I-PDU handle and performs appropriate handle and port conversion.
 *                The call is routed to an upper Tp module or to the gateway depending on the pending Confirmation.
 *   \param[in]   rmGDestRomIdx          ID of the transmitted GwIf I-PDU
 *   \param[out]  result    not used, but expected due to function pointer table type
 *   \pre         -
 *   \context     TASK|ISR1|ISR2
 *   \reentrant   TRUE
 *   \synchronous TRUE
 **********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_MultipleSourceHandler_TpTxConfirmation(PduR_RmGDestRomIdxOfTxTp2SrcType rmGDestRomIdx, Std_ReturnType result);
# endif

# if((PDUR_TPCANCELTRANSMITSUPPORTEDOFMMROM == STD_ON) && (PDUR_EXISTS_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
   PduR_RmTp_MultipleSourceHandler_CancelTransmit
**********************************************************************************************************************/
/*! \brief        The function is called by the PduR to cancel the transmission on the destination buses in case of a
 *                FanIn Transport Protocol Routing.
 *   \details     The PDU Router evaluates the Gw I-PDU handle and performs appropriate handle and port conversion.
 *                The call is routed to multiple TP module using the appropriate I-PDU handle of the destination layer.
 *   \param[in]   rmDestRomIdx             ID of the transmitted GwTp I-PDU.
 *   \pre         -
 *   \context     TASK|ISR1|ISR2
 *   \reentrant   TRUE
 *   \synchronous TRUE
**********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_MultipleSourceHandler_CancelTransmit(PduR_RmDestRomIterType rmDestRomIdx);
# endif

# if (PDUR_HASTPTXBUFFEREDFORWARDINGOFGENERALPROPERTIESROM == STD_ON)
/**********************************************************************************************************************
  PduR_RmTp_UpStartOfReception
**********************************************************************************************************************/
/*! \brief       Wrapper function for buffered transmit.
 *  \details     -
 *  \param[in]   rmSrcIdx          Routing Manager source Id
 *  \param[in]   info              Pointer to the buffer (SduDataPtr) contains MetaData if this feature is enabled
 *  \return      Std_ReturnType
 *                E_OK              Connection has been accepted. RxBufferSizePtr indicates the available receive buffer.
 *                E_NOT_OK          PduR_Init() has not been called
 *                                  or the GwTpRxPduId is not valid
 *                                  or the GwTpRxPduId is not forwarded in this identity
 *                                  or the info is not valid
 *                                  or the request was not accepted by the upper layer.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       SPEC-1096, SPEC-2020151
***********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_UpStartOfReception(PduR_RmSrcRomIterType rmSrcIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
  PduR_RmTp_StartOfReception
**********************************************************************************************************************/
/*! \brief       This function will be called by the GwTp at the start of receiving an I-PDU.
 *  \details     The I-PDU might be fragmented into multiple N-PDUs
 *               (FF with one or more following CFs) or might consist of a single N-PDU (SF).
 *  \param[in]   rmSrcIdx          Routing Manager source Id
 *  \param[in]   info              Pointer to the buffer (SduDataPtr) contains MetaData if this feature is enabled
 *  \param[in]   TpSduLength       Length of the entire GwTp TP SDU which will be received
 *  \param[out]  bufferSizePtr     Pointer to the receive buffer in the receiving module.
 *                                   This parameter will be used to compute Block Size (BS) in the transport protocol module.
 *  \return      BufReq_ReturnType
 *               BUFREQ_OK         Connection has been accepted. RxBufferSizePtr indicates the available receive buffer.
 *               BUFREQ_E_NOT_OK   PduR_Init() has not been called
 *                                  or the GwTpRxPduId is not valid
 *                                  or the GwTpRxPduId is not forwarded in this identity
 *                                  or the info is not valid
 *                                  or the request was not accepted by the upper layer.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       SPEC-1096, SPEC-2020151
***********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_StartOfReception(PduR_RmSrcRomIterType rmSrcIdx,
                                                              P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
                                                              PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
  PduR_RmTp_CopyRxData
**********************************************************************************************************************/
/*! \brief     This function is called by the PduR if data has to be to copied to the receiving module.
 *  \details   Several calls may be made during one transportation of an I-PDU.
 *  \param[in]   rmSrcIdx         Routing Manager source Id
 *  \param[in]   info               Pointer to the buffer (SduDataPtr) and its length (SduLength)
 *                                containing the data to be copied by PDU Router module in case of gateway
 *                                or upper layer module in case of reception.
 *  \param[out]  bufferSizePtr     Available receive buffer after data has been copied.
 *  \return    BufReq_ReturnType
 *             BUFREQ_OK         Buffer request accomplished successful.
 *             BUFREQ_E_NOT_OK   PduR_Init() has not been called
 *                                  or the GwTpRxPduId is not valid
 *                                  or the GwTpRxPduId is not forwarded in this identity
 *                                  or the info is not valid
 *                                  or the request was not accepted by the upper layer.
 *             BUFREQ_E_BUSY     Currently no buffer of the requested size is available.
 *                               It's up the requester to retry request for a certain time.
 *                               The request was not accepted by the upper layer.
 *             BUFREQ_E_OVFL     The upper TP module is not able to receive the number of bytes.
 *                               The request was not accepted by the upper layer.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       SPEC-1096, SPEC-2020151
**********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_CopyRxData(PduR_RmSrcRomIdxOfRxTp2DestType rmSrcIdx, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
                                                        P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
 /**********************************************************************************************************************
 * PduR_RmTp_CancelTransmitPreparation
 *********************************************************************************************************************/
/*! \brief       This function is called to cancel all destination transmit calls of a source.
 *  \details     -
 *  \param[in]   fmFifoElementRamIdx     Fifo State Id used for state handling.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_CancelTransmitPreparation(PduR_FmFifoElementRamIterType fmFifoElementRamIdx);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
  PduR_RmTp_TpRxIndication
**********************************************************************************************************************/
/*! \brief      The function is called by the PduR GwTp to indicate the complete reception of a GwTp SDU
 *              or to report an error that occurred during reception.
 *  \details    -
 *              The PDU Router evaluates the Gw I-PDU handle and performs appropriate handle and port conversion.
 *              The call is routed to an upper TP module using the appropriate I-PDU handle of the destination layer.
 *  \param[in]      rmSrcIdx                    Routing Manager source Id
 *  \param[out] result                          Result of the TP reception.\n
 *              E_OK                            The TP reception has been completed successfully.\n
 *              E_NOT_OK                        The PDU Router is in the PDUR_UNINIT state\n
 *                                              or the id is not valid\n
 *                                              or the id is not forwarded in this identity\n
 *                                              or the request was not accepted by the destination upper layer.\n
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       SPEC-1096, SPEC-2020151
***********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_TpRxIndication(PduR_RmSrcRomIdxOfRxTp2DestType rmSrcIdx, Std_ReturnType result);
# endif

# if(PDUR_EXISTS_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_Transmit_MultiDest
 *********************************************************************************************************************/
/*!
 * \brief    The function calls the Transmit function for every destination
 * \details     -
 * \param[in]   rmSrcIdx            internal RmSrcRom index
 * \param[in]   info                Pointer to the data to be transmitted
 * \return      Std_ReturnType
 *               E_OK              Transmit was executed successfully by all the destination modules.
 *               E_NOT_OK          Transmit was rejected by the destination module.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
**********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_Transmit_MultiDest(PduR_RmSrcRomIterType rmSrcIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_CheckReady2Transmit_TpTxSmStateHandler_RM_TX_IDLE
 *********************************************************************************************************************/
/*! \brief This function is called to check if the threshold is reached and the transmission could be triggered
 *  \details       -
 *  \param[in]     rmSrcIdx Routing Manager source Id.
 *  \pre           -
 *  \context       TASK|ISR1|ISR2
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_CheckReady2Transmit_TpTxSmStateHandler_RM_TX_IDLE(PduR_RmSrcRomIterType rmSrcIdx);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_CheckReady2Transmit_TpTxSmStateHandler_RM_TX_RECEPTION_ACTIVE
 *********************************************************************************************************************/
/*! \brief This function is called to check if the threshold is reached and the transmission could be triggered
 *  \details -
 *  \param[in]     rmSrcIdx Routing Manager source Id
 *  \pre           -
 *  \context       TASK|ISR1|ISR2
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_CheckReady2Transmit_TpTxSmStateHandler_RM_TX_RECEPTION_ACTIVE(PduR_RmSrcRomIterType rmSrcIdx);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_CheckReady2Transmit_TpTxSmStateHandler_NoAction
 *********************************************************************************************************************/
/*! \brief This function is called to check if the threshold is reached and the transmission could be triggered
 *  \details -
 *  \param[in]    rmSrcIdx Routing Manager source Id
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_CheckReady2Transmit_TpTxSmStateHandler_NoAction(PduR_RmSrcRomIterType rmSrcIdx);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_FinishReception_TpTxSmStateHandler_RM_TX_IDLE
 *********************************************************************************************************************/
/*! \brief This function is called if the reception is finished to set the suitable state a and
 *         to trigger the transmission
 *  \details -
 *  \param[in]   rmSrcIdx Routing Manager source Id.
 *  \param[out]  result  result of the reception.
 *               E_OK    successful.
 *               E_NO_OK not successful.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_FinishReception_TpTxSmStateHandler_RM_TX_IDLE(PduR_RmSrcRomIterType rmSrcIdx, Std_ReturnType result);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_FinishReception_TpTxSmStateHandler_RM_TX_TRANSMISSION_FINISHED
 *********************************************************************************************************************/
/*! \brief This function is called if the reception is finished to set the suitable state a and
 *         to trigger the transmission
 *  \details -
 *  \param[in]   rmSrcIdx Routing Manager source Id.
 *  \param[out]  result   result of the reception.
 *               E_OK     successful
 *               E_NO_OK not successful.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_FinishReception_TpTxSmStateHandler_RM_TX_TRANSMISSION_FINISHED(PduR_RmSrcRomIterType rmSrcIdx, Std_ReturnType result);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_FinishReception_TpTxSmStateHandler_RM_TX_RECEPTION_ACTIVE
 *********************************************************************************************************************/
/*! \brief This function is called if the reception is finished to set the suitable state a and
 *         to trigger the transmissiong
 *  \details -
 *  \param[in]   rmSrcIdx Routing Manager source Id.
 *  \param[out]  result   result of the reception.
 *               E_OK     successful.
 *               E_NO_OK  not successful.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_FinishReception_TpTxSmStateHandler_RM_TX_RECEPTION_ACTIVE(PduR_RmSrcRomIterType rmSrcIdx, Std_ReturnType result);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_FinishReception_TpTxSmStateHandler_RM_TX_RECEPTION_TRANSMISSION_ACTIVE
 *********************************************************************************************************************/
/*! \brief This function is called if the reception is finished to set the suitable state a and
 *         to trigger the transmission
 *  \details -
 *  \param[in]   rmSrcIdx Routing Manager source Id.
 *  \param[out]  result  result of the reception.
 *               E_OK    successful
 *               E_NO_OK not successful.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2.
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_FinishReception_TpTxSmStateHandler_RM_TX_RECEPTION_TRANSMISSION_ACTIVE(PduR_RmSrcRomIterType rmSrcIdx, Std_ReturnType result);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_FinishReception_TpTxSmStateHandler_NoAction
 *********************************************************************************************************************/
/*! \brief This function is called if the reception is finished to set the suitable state a and
 *         to trigger the transmission
 *  \details -
 *  \param[in]   rmSrcIdx Routing Manager source Id.
 *  \param[out]  result  result of the reception.
 *               E_OK    successful
 *               E_NO_OK not successful.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_FinishReception_TpTxSmStateHandler_NoAction(PduR_RmSrcRomIterType rmSrcIdx, Std_ReturnType result);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_FinishTransmission_TpTxSmStateHandler_RM_TX_RECEPTION_FINISHED_TRANSMISSION_ACTIVE
 *********************************************************************************************************************/
/*! \brief This function is called if the transmission is finished o set the suitable state a and
 *         trigger the next pending routing
 *  \details -
 *  \param[in]   rmGDestRomIdx Routing Manager destination Id.
 *  \param[out]  result   result of the transmission.
 *               E_OK     successful
 *               E_NO_OK not successful.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_FinishTransmission_TpTxSmStateHandler_RM_TX_RECEPTION_FINISHED_TRANSMISSION_ACTIVE(PduR_RmDestRomIterType rmGDestRomIdx, Std_ReturnType result);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_FinishTransmission_TpTxSmStateHandler_RM_TX_RECEPTION_TRANSMISSION_ACTIVE
 *********************************************************************************************************************/
/*! \brief This function is called if the transmission is finished o set the suitable state a and
 *         trigger the next pending routing
 *  \details -
 *  \param[in]   rmGDestRomIdx Routing Manager destination Id.
 *  \param[out]  result   result of the transmission.
 *               E_OK     successful
 *               E_NO_OK not successful.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_FinishTransmission_TpTxSmStateHandler_RM_TX_RECEPTION_TRANSMISSION_ACTIVE(PduR_RmGDestRomIterType rmGDestRomIdx, Std_ReturnType result);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_FinishTransmission_TpTxSmStateHandler_FatalError
 *********************************************************************************************************************/
/*! \brief This function is called if the transmission is finished o set the suitable state a and
 *         trigger the next pending routing
 *  \details -
 *  \param[in]   rmGDestRomIdx Routing Manager destination Id.
 *  \param[out]  result   result of the transmission.
 *               E_OK     successful
 *               E_NO_OK not successful.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_FinishTransmission_TpTxSmStateHandler_FatalError(PduR_RmDestRomIterType rmGDestRomIdx, Std_ReturnType result);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM  == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_StartOfReception_TpRxSmStateHandler_RM_RX_IDLE
 *********************************************************************************************************************/
/*! \brief      The function is called by the PduR GwTp to start a reception of a GwTp SDU
 *  \details    Rx State machine in state "IDLE" The call is routed to RxSm
 *  \param[in]     rmSrcIdx                      Routing Manager source Id
 *  \param[in]     info                            Pointer to the buffer (SduDataPtr) and its length (SduLength)
 *  \param[in]     TpSduLength       Length of the entire GwTp TP SDU which will be received
 *  \param[out]    bufferSizePtr                   Pointer to the receive buffer in the receiving module.
 *  \return      BufReq_ReturnType
 *               BUFREQ_OK         routing accepted and buffer allocated.
 *               BUFREQ_E_NOT_OK   routing not accepted (FIFO full) no Tp buffer available.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       SPEC-1096, SPEC-2020151
***********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_StartOfReception_TpRxSmStateHandler_RM_RX_IDLE(PduR_RmSrcRomIterType rmSrcIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
                                                                                            PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM  == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_StartOfReception_TpRxSmStateHandler_UnexpectedCall
 *********************************************************************************************************************/
/*! \brief      The function is called if the start of reception is called unexpectedly.
 *  \details    Rx State machine in state "Active or Aborted"
 *  \param[in]  rmSrcIdx            Routing Manager source Id
 *  \param[in]  info                Pointer to the buffer (SduDataPtr) and its length (SduLength)
 *  \param[in]  TpSduLength         Length of the entire GwTp TP SDU which will be received
 *  \param[out] bufferSizePtr       Pointer to the receive buffer in the receiving module.
 *  \return      BufReq_ReturnType
 *               BUFREQ_E_NOT_OK   unexpected call
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       SPEC-1096, SPEC-2020151
***********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_StartOfReception_TpRxSmStateHandler_UnexpectedCall(PduR_RmSrcRomIterType rmSrcIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
                                                                                                PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr);
# endif


# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
  PduR_RmTp_CopyRxData_TpRxSmStateHandler_RM_RX_ACTIVE
**********************************************************************************************************************/
/*! \brief     This function is called by the PduR if data has to be copied to the tx buffer
 *  \details   Several calls may be made during one transportation of an I-PDU.
 *             Rx State machine in state "Active"
 *  \param[in]  rmSrcIdx          Routing Manager source Id
  * \param[in] pduLength         length to copy.
 *  \param[in] sduDataPtr        data pointer (containing the data to be copied by PDU Router module in case of gateway
 *                               or upper layer module in case of reception).
 *  \param[out] bufferSizePtr     Available receive buffer after data has been copied.
 *  \return    BufReq_ReturnType
 *             BUFREQ_OK         Copy data were successful.
 *             BUFREQ_E_NOT_OK   Copy data fails.
 *             BUFREQ_E_BUSY     Currently no buffer of the requested size is available.
 *                               It's up the requester to retry request for a certain time.
 *                               The request was not accepted by the upper layer.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       SPEC-1096, SPEC-2020151
**********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_CopyRxData_TpRxSmStateHandler_RM_RX_ACTIVE(PduR_RmSrcRomIterType rmSrcIdx, PduLengthType pduLength,
                                                                                        SduDataPtrType sduDataPtr, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
  PduR_RmTp_CopyRxData_TpRxSmStateHandler_RM_RX_ABORTED
**********************************************************************************************************************/
/*! \brief     This function is called if data has to be copied to the tx buffer but the routing is
 *             already aborted.
 *  \details   Rx State machine in state "Aborted"
 *  \param[in]  rmSrcIdx           Routing Manager source Id
 *  \param[in] pduLength         length to copy.
 *  \param[in] sduDataPtr        data pointer (containing the data to be copied by PDU Router module in case of gateway
 *                               or upper layer module in case of reception).
 *  \param[out] bufferSizePtr     Available receive buffer after data has been copied.
 *  \return    BufReq_ReturnType
 *             BUFREQ_E_NOT_OK   Copy data fails because routing is already aborted.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       SPEC-1096, SPEC-2020151
**********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_CopyRxData_TpRxSmStateHandler_RM_RX_ABORTED(PduR_RmSrcRomIterType rmSrcIdx, PduLengthType pduLength,
                                                                                         SduDataPtrType sduDataPtr, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
  PduR_RmTp_CopyRxData_TpRxSmStateHandler_UnexpectedCall
**********************************************************************************************************************/
/*! \brief       This function is called by the PduR if data has to be to copied to the tx buffer unexpectedly.
 *  \details     Rx State machine in state "Idle"
 *  \param[in]   rmSrcIdx          Routing Manager source Id
  * \param[in]   pduLength         length to copy.
 *  \param[in]   sduDataPtr        data pointer (containing the data to be copied by PDU Router module in case of gateway
 *                                 or upper layer module in case of reception).
 *  \param[out]  bufferSizePtr     Available receive buffer after data has been copied.
 *  \return      BufReq_ReturnType
 *               BUFREQ_E_NOT_OK   Copy data fails because the RxSM is still idle. A StartOfReception is expected.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       SPEC-1096, SPEC-2020151
**********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_CopyRxData_TpRxSmStateHandler_UnexpectedCall(PduR_RmSrcRomIterType rmSrcIdx, PduLengthType pduLength,
                                                                                          SduDataPtrType sduDataPtr, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TpRxIndication_TpRxSmStateHandler_UnexpectedCall
 *********************************************************************************************************************/
/*! \brief       The function is called by the PduR GwTp to indicate the complete reception of a GwTp SDU
 *               or to finish the reception if an error occurs.
 *  \details     Rx State machine in state "Active or Aborted"
 *  \param[in]   rmSrcIdx             Routing Manager source Id
 *  \param[out]  result                          Result of the TP reception.\n
 *               E_OK                            The TP reception has been completed successfully.\n
 *               E_NOT_OK                        The TP reception was failing.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       SPEC-1096, SPEC-2020151
***********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_TpRxIndication_TpRxSmStateHandler_UnexpectedCall(PduR_RmSrcRomIterType rmSrcIdx, Std_ReturnType result);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TpRxIndication_TpRxSmStateHandler_RM_RX_ACTIVE_OR_RM_RX_ABORTED
 *********************************************************************************************************************/
/*! \brief       The function is called by the PduR GwTp if an indication is called unexpectedly
 *  \details     Rx State machine in state "Idle"
 *  \param[in]   rmSrcIdx              Routing Manager source Id
 *  \param[out]  result                Result of the TP reception.\n
 *               E_OK    successful
 *               E_NO_OK not successful.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       SPEC-1096, SPEC-2020151
***********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_TpRxIndication_TpRxSmStateHandler_RM_RX_ACTIVE_OR_RM_RX_ABORTED(PduR_RmSrcRomIterType rmSrcIdx, Std_ReturnType result);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_CancelReceive_TpRxSmStateHandler_RM_RX_ACTIVE
 *********************************************************************************************************************/
/*! \brief      The function is called to cancel a reception if a routing is disabled.
 *  \details    -
 *  \param[in]   rmSrcIdx    Routing Manager source Id
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
***********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_CancelReceive_TpRxSmStateHandler_RM_RX_ACTIVE(PduR_RmSrcRomIterType rmSrcIdx);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_CancelReceive_TpRxSmStateHandler_FatalError
 *********************************************************************************************************************/
/*! \brief       If this function is called something went totally wrong.
 *  \details     -
 *  \param[in]   rmSrcIdx   Routing Manager source Id
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
***********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_CancelReceive_TpRxSmStateHandler_FatalError(PduR_RmSrcRomIterType rmSrcIdx);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_CancelReceive_TpRxSmStateHandler_RM_RX_ABORTED
 *********************************************************************************************************************/
/*! \brief       The function is called in case the reception is already aborted
 *  \details     -
 *  \param[in]   rmSrcIdx    Routing Manager source Id
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 ***********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_CancelReceive_TpRxSmStateHandler_RM_RX_ABORTED(PduR_RmSrcRomIterType rmSrcIdx);
# endif

# define PDUR_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */
#endif /* PDUR_RMTP_H */
/**********************************************************************************************************************
 *  END OF FILE: PduR_RmTp.h
 *********************************************************************************************************************/
