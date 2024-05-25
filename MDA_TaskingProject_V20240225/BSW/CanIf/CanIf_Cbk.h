/* \trace SPEC-1878 */

/********************************************************************************************************************
|    File Name: CanIf_Cbk.h
|
|  Description: Type definitions of the AUTOSAR CAN Interface
|--------------------------------------------------------------------------------------------------------------------
|               C O P Y R I G H T
|--------------------------------------------------------------------------------------------------------------------
| Copyright (c) 1996-2017 by Vector Informatik GmbH.       All rights reserved.
|
| This software is copyright protected and proprietary
| to Vector Informatik GmbH. Vector Informatik GmbH
| grants to you only those rights as set out in the
| license conditions. All other rights remain with
| Vector Informatik GmbH.
|
|--------------------------------------------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|--------------------------------------------------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
| Rna          Ruediger Naas             Vector Informatik GmbH
| Seu          Eugen Stripling           Vector Informatik GmbH
|--------------------------------------------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|--------------------------------------------------------------------------------------------------------------------
| Date        Version   Author  Description
| ----------  --------  ------  -------------------------------------------------------------------------------------
| 2012-07-02  05.00.00  Rna     ESCAN00060132:Support ASR 4.0 Rev 3
| 2015-03-26  05.01.00  Seu     ESCAN00080296: FEAT-427: SafeBSW Step I
| 2015-11-30  05.02.00  Rna     ESCAN00086059: FEAT-1429: Gateway Optimization
| 2016-10-10  05.02.01  Rna     ESCAN00092243: Rework of  Doxygen comments
| 2017-08-04  05.03.00  Seu     ESCAN00096180: FEAT-2946 - Supporting 3rd party communication MCAL CAN driver according to AR 4.2
|*******************************************************************************************************************/

#ifndef CANIF_CBK_H
#define CANIF_CBK_H

/* PRQA S 0850 EOF */ /* MD_MSR_19.8 */
/* PRQA S 3453 EOF */ /* MD_MSR_19.7 */

#include "CanIf_Cfg.h"
/* CanIf_Types.h  is included by CanIf_Cfg.h */

#define CANIF_CBK_MAJOR_VERSION   0x05u
#define CANIF_CBK_MINOR_VERSION   0x03u
#define CANIF_CBK_PATCH_VERSION   0x00u

#define CANIF_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* \trace SPEC-3696 */

/***********************************************************************************************************************
| NAME:  CanIf_TxConfirmation
 **********************************************************************************************************************/
/*! \brief       Confirmation for successful transmission.
 *  \details     -
 *  \param[in]   CanTxPduId: Internal ID of successful transmitted PDU.
 *  \pre         -
 *  \context     TASK/ISR
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      -
 *  \note        This function has the service id 0x13.
 **********************************************************************************************************************/
FUNC(void, CANIF_CODE) CanIf_TxConfirmation(PduIdType CanTxPduId);

/***********************************************************************************************************************
| NAME:  CanIf_RxIndicationAsr403
 **********************************************************************************************************************/
/*! \brief       Indication about a received CAN message [ASR4.0.3].
 *  \details     This functions looks for if received CAN message matches one of the configured ones. If yes then the configured upper layer is notified.
 *  \param[in]   Hrh: Handle of hardware object
 *  \param[in]   CanId: CAN identifier of received message
 *  \param[in]   CanDlc: DLC of received message
 *  \param[in]   CanSduPtr: Pointer to data of received message
 *  \pre         -
 *  \context     TASK/ISR
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      -
 *  \note        This function has the service id 0x14.
 **********************************************************************************************************************/
FUNC(void, CANIF_CODE) CanIf_RxIndicationAsr403(CanIf_HwHandleType Hrh, Can_IdType CanId, uint8 CanDlc, P2CONST(uint8, AUTOMATIC, CANIF_CBK_DRV_VAR)CanSduPtr);

/* void CanIf_CancelTxConfirmation(const Can_PduType *PduInfoPtr); */
#if (CANIF_TRANSMIT_BUFFER_PRIO_BY_CANID == STD_ON)
# if  (CANIF_TRANSMIT_BUFFER_FIFO == STD_OFF)
#  if (CANIF_TRANSMIT_CANCELLATION == STD_ON)
#   if (CANIF_MULTIPLE_TX_BASICCANS == STD_OFF) /* COV_CANIF_GENDATA_FAILURE */
/***********************************************************************************************************************
| NAME:  CanIf_CancelTxConfirmation
 **********************************************************************************************************************/
/*! \brief       The call of this API indicates about a canceled Tx message by the CAN driver.
 *  \details     -
 *  \param[in]   CanTxPduId: Handle of hardware object
 *  \param[in]   PduInfoPtr: Pointer to parameters of canceled Tx message
 *  \pre         -
 *  \context     TASK/ISR
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      CANIF_TRANSMIT_BUFFER == STD_ON and CANIF_TRANSMIT_CANCELLATION == STD_ON
 *  \note        This function has the service id 0x15.
 **********************************************************************************************************************/
FUNC(void, CANIF_CODE) CanIf_CancelTxConfirmation(PduIdType CanTxPduId, P2CONST(Can_PduType, AUTOMATIC, CANIF_CBK_DRV_VAR) PduInfoPtr);
#   endif
#  endif
# endif
#endif

/***********************************************************************************************************************
| NAME:  CanIf_ControllerBusOff
 **********************************************************************************************************************/
/*! \brief       Indication about an occurred BusOff-event
 *  \details     -
 *  \param[in]   ControllerId: ID of CAN channel for which the BusOff-event occurred
 *  \pre         -
 *  \context     TASK/ISR
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      -
 *  \note        This function has the service id 0x16.
 **********************************************************************************************************************/
FUNC(void, CANIF_CODE) CanIf_ControllerBusOff(uint8 ControllerId);

/* NON AUTOSAR callback functions */

#if (CANIF_CANCEL_SUPPORT_API == STD_ON)
/***********************************************************************************************************************
| NAME:  CanIf_CancelTxNotification
 **********************************************************************************************************************/
/*! \brief       CAN Interface is notified about a canceled PDU.
 *  \details     The confirmation is NOT passed to upper layers. Next message from Tx-queue is transmitted.
 *               Used for trigger-purpose to fill the free HW-object, after calling of CanIf_CancelTransmit().
 *  \param[in]   PduId: ID of canceled Tx-message
 *  \param[in]   IsCancelled: TRUE: Tx-message (PduId) was canceled, FALSE: Tx-message (PduId) was NOT canceled (it was transmitted)
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      -
 *  \note        This function has the service id 0x16.
 **********************************************************************************************************************/
FUNC(void, CANIF_CODE) CanIf_CancelTxNotification(PduIdType PduId, CanIf_CancelResultType IsCancelled);
#endif


#define CANIF_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif

