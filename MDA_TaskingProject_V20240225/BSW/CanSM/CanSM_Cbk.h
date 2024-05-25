
/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/* \file    CanSM_Cbk.h
 * \brief   Call back header of the CAN State Manager AUTOSAR Release 4
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module header file.
 *  -------------------------------------------------------------------------------------------------------------------
 *********************************************************************************************************************/


#ifndef CANSM_CBK_H
# define CANSM_CBK_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/* # include "Std_Types.h" */ /*  uint16 */
/* # include "Compiler.h" */ /* compiler abstraction */
# include "ComStack_Types.h" /* NetworkHandleType; includes ComStack_Types.h, which includes Std_Types.h which include "Platform_Types.h" and include "Compiler.h" */
/* \trace SPEC-636 */
# include "CanIf.h"           /* needed cause of CanIf_ControllerModeType, */
/* # include "Can_GeneralTypes.h"  CanTrcv_TrcvModeType */ /* included by CanIf_Types.h; included by CanIf.h  */
# include "CanSM_Cfg.h" /* pre          Processor switches */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : Ccl_Asr4SmCan CQComponent : Implementation */
/* Version - BCD coded version number - Main- and Sub-Version - Release-Version */
# define CCL_ASR4SMCAN_CALLBACK_HEADER_VERSION                                        0x0300u   /* BCD coded version number */
# define CCL_ASR4SMCAN_CALLBACK_HEADER_RELEASE_VERSION                                0x01u   /* BCD coded release version number  */

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

# define CANSM_START_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  CanSM_ControllerBusOff
 **********************************************************************************************************************/
/*! \brief       Starts the bus-off recovery
 *  \details     Starts the bus-off recovery, indicates the bus-off recovery to Dem, BswM, ComM and bus-off begin call out
 *  \param[in]   CanSM_ControllerId      CAN controller index
 *  \context     ANY
 *  \reentrant   TRUE for different ID
 *  \synchronous FALSE
 *  \config      -
 *  \pre         -
 *  \trace       SPEC-646
 **********************************************************************************************************************/
FUNC( void, CANSM_CODE ) CanSM_ControllerBusOff( uint8 CanSM_ControllerId );


#if( CANSM_EXTENDED_RAM_CHECK == STD_ON )
/***********************************************************************************************************************
 *  CanSM_RamCheckCorruptMailbox
 **********************************************************************************************************************/
/*! \brief       Handles the indication of a RAM check mail box error
 *  \details     Gets informations about RAM check mail box errors. Forwards the information to the application and evaluates HW register failures
 *  \param[in]   CanSM_ControllerId      CAN controller index
 *  \param[in]   CanSM_MailBoxHandle     Mail box identifier
 *  \context     TASK
 *  \reentrant   TRUE for different ID
 *  \synchronous FALSE
 *  \config      CANSM_EXTENDED_RAM_CHECK
 *  \pre         -
 *  \trace       SPEC-646
 **********************************************************************************************************************/
FUNC(void, CANSM_CODE) CanSM_RamCheckCorruptMailbox( uint8 CanSM_ControllerId, Can_HwHandleType CanSM_MailBoxHandle );

/***********************************************************************************************************************
 *  CanSM_RamCheckCorruptController
 **********************************************************************************************************************/
/*! \brief       Handles the indication of a RAM check controller error
 *  \details     Gets informations about RAM check controller errors. Forwards the information to the application and evaluates HW register failures
 *  \param[in]   CanSM_ControllerId      CAN controller index
 *  \context     TASK
 *  \reentrant   TRUE for different ID
 *  \synchronous FALSE
 *  \config      CANSM_EXTENDED_RAM_CHECK
 *  \pre         -
 *  \trace       SPEC-646
 **********************************************************************************************************************/
FUNC(void, CANSM_CODE) CanSM_RamCheckCorruptController( uint8 CanSM_ControllerId );
#endif /* CANSM_EXTENDED_RAM_CHECK  */

/***********************************************************************************************************************
 *  CanSM_ControllerModeIndication
 **********************************************************************************************************************/
/*! \brief       Handles the indication of a controller mode change
 *  \details     Gets informations about successful mode changes. Triggers the next sub state of the machine  machine. (Unexpected indications are ignored)
 *  \param[in]   CanSM_ControllerId      CAN controller index
 *  \param[in]   CanSM_ControllerMode    CAN controller mode
 *  \context     ANY
 *  \reentrant   TRUE for different ID
 *  \synchronous FALSE
 *  \config      -
 *  \pre         -
 *  \trace       SPEC-646
 **********************************************************************************************************************/
FUNC( void, CANSM_CODE ) CanSM_ControllerModeIndication( uint8 CanSM_ControllerId, CanIf_ControllerModeType CanSM_ControllerMode );

#if ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_ON )
/***********************************************************************************************************************
 *  CanSM_TransceiverModeIndication
 **********************************************************************************************************************/
/*! \brief       Handles the indication of a transceiver mode change
 *  \details     Gets informations about successful mode changes. Triggers the next sub state of the machine  machine. (Unexpected indications are ignored)
 *  \param[in]   CanSM_TransceiverId     CAN transceiver index
 *  \param[in]   CanSM_TransceiverMode   CAN transceiver mode
 *  \context     ANY
 *  \reentrant   TRUE for different ID
 *  \synchronous FALSE
 *  \config      CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG
 *  \pre         -
 *  \trace       SPEC-646
 **********************************************************************************************************************/
FUNC(void, CANSM_CODE) CanSM_TransceiverModeIndication( uint8 CanSM_TransceiverId, CanTrcv_TrcvModeType CanSM_TransceiverMode );

#endif /* CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG  */



#if ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON )

/***********************************************************************************************************************
 *  CanSM_ClearTrcvWufFlagIndication
 **********************************************************************************************************************/
/*! \brief       Handles the indication of a cleared transceiver wake up flag
 *  \details     Triggers the next sub state of the machine machine. (Unexpected indications are ignored)
 *  \param[in]   CanSM_TransceiverId     CAN transceiver index
 *  \context     ANY
 *  \reentrant   TRUE for different ID
 *  \synchronous FALSE
 *  \config      CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG
 *  \pre         -
 *  \trace       SPEC-646
 **********************************************************************************************************************/
FUNC(void, CANSM_CODE) CanSM_ClearTrcvWufFlagIndication( uint8  CanSM_TransceiverId );

/***********************************************************************************************************************
 *  CanSM_CheckTransceiverWakeFlagIndication
 **********************************************************************************************************************/
/*! \brief       Handles the indication of a checked transceiver wake up flag
 *  \details     Triggers the next sub state of the machine  machine. The actual handling of a positive wake up flag has to be done by the transceiver. (Unexpected indications are ignored)
 *  \param[in]   CanSM_TransceiverId     CAN transceiver index
 *  \context     ANY
 *  \reentrant   TRUE for different ID
 *  \synchronous FALSE
 *  \config      CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG
 *  \pre         -
 *  \trace       SPEC-646
 **********************************************************************************************************************/
FUNC(void, CANSM_CODE) CanSM_CheckTransceiverWakeFlagIndication ( uint8  CanSM_TransceiverId );

/***********************************************************************************************************************
 *  CanSM_ConfirmPnAvailability
 **********************************************************************************************************************/
/*! \brief       Gets information about active partial network transceiver
 *  \details     Inform the CanNm that the transceiver is running in partial network mode.
 *  \param[in]   CanSM_TransceiverId     CAN transceiver index
 *  \context     ANY
 *  \reentrant   TRUE for different ID
 *  \synchronous FALSE
 *  \config      CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG
 *  \pre         -
 *  \trace       SPEC-646
 **********************************************************************************************************************/
FUNC( void, CANSM_CODE ) CanSM_ConfirmPnAvailability( uint8 CanSM_TransceiverId );

#endif /* end   else if ( CANSM_PARTIAL_NETWORK == STD_ON ) */

# define CANSM_STOP_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */



#endif /* end if not defined ( CANSM_CBK_H ) */

/**********************************************************************************************************************
 *  END OF FILE: CanSM_Cbk.h
 *********************************************************************************************************************/

