
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
/* \file    CanSM_Int.h
 * \brief   Internal header of the CAN State Manager AUTOSAR Release 4
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module header file.
 *  -------------------------------------------------------------------------------------------------------------------
 *********************************************************************************************************************/


#if !defined  CANSM_INT_H
# define CANSM_INT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

# include "ComStack_Types.h"
/* \trace SPEC-636 */
# include "ComM_Types.h"        /* needed cause of ComM_ModeType */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : Ccl_Asr4SmCan CQComponent : Implementation */
/* Version - BCD coded version number - Main- and Sub-Version - Release-Version */
# define CCL_ASR4SMCAN_INT_HEADER_VERSION                                        0x0300u   /* BCD coded version number */
# define CCL_ASR4SMCAN_INT_HEADER_RELEASE_VERSION                                0x01u   /* BCD coded release version number  */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct CanSM_ChannelVarRecordTypeTag
{
  uint16          CanSM_UniversalTimer;
  uint16          CanSM_LastValidBaudRate;  /*!< Memorizes LatestCheckedBaudRate, CurrentBaudRate */
  ComM_ModeType   CanSM_RequestedComMode;  /*!< Memorizes the communication requested mode */
  ComM_ModeType   CanSM_IndicatedComMode;  /*!< Memorizes the last indicated communication mode */
  ComM_ModeType   CanSM_NewComMode; /*!< Memorizes the actual ComM mode */  
  uint8           CanSM_EnfroceComModeIndication;  /*!< Used values are boolean */
  Std_ReturnType  CanSM_RamCheckState;  /*!< Memorizes the return value of the RamCheckEnd function */
  uint8           CanSM_CurrentState;  /*!< Memorizes the current state of the state machine. Valid values are CANSM_S_* */
  uint8           CanSM_ModeRequestRepetitionCounter;  /*!< Counts the mode request repetitions */
  uint8           CanSM_ModeIndicationResponsible; /*!< Memorizes the responsible for indicate BswM state */
  uint8           CanSM_BswMIndicatedState; /*!< Memorizes the last indicated BswM state */
  uint8           CanSM_BswMNewState; /*!< Memorizes the actual BswM state */  
  uint8           CanSM_BusOffCounter; /*!< Counts the bus-offs */
  uint8           CanSM_BusOffFlag;  /*!< Memorizes a bus-off  */
  uint8           CanSM_TxOnlineDelayTime;   /*!< Value of the additional J1939Nm delay */
  uint8           CanSM_TxTimeoutEndIndicationFlag;  /*!< Used values are boolean */
} CanSM_ChannelVarRecordType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/





#endif /* end if not defined ( CANSM_INT_H ) */
/**********************************************************************************************************************
  END OF FILE: CanSM_Int.h
 *********************************************************************************************************************/

