
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
/* \file    CanSM_EcuM.h
 * \brief   EcuM header of the CAN State Manager AUTOSAR Release 4
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module header file.
 *  -------------------------------------------------------------------------------------------------------------------
 *********************************************************************************************************************/


#ifndef CANSM_ECUM_H
# define CANSM_ECUM_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/* # include  Std_Types.h Std_VersionInfoType */
/* # include "Compiler.h" */ /* compiler abstraction */
/* # include "ComStack_Types.h" */ /* NetworkHandleType; includes ComStack_Types.h, which includes Std_Types.h which include "Platform_Types.h" and include "Compiler.h" */
/* # include "CanSM_Cfg.h" */ /* includes ComStack_Types.h  */ /* included by CanSM.h */
# include "CanSM.h"             /* needed cause of CANSM_CONFIG_VARIANT and CanSM_ConfigType */
# include "EcuM.h"             /* EcuM_WakeupSourceType  */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : Ccl_Asr4SmCan CQComponent : Implementation */
/* Version - BCD coded version number - Main- and Sub-Version - Release-Version */
# define CCL_ASR4SMCAN_ECUM_HEADER_VERSION                                        0x0300u   /* BCD coded version number */
# define CCL_ASR4SMCAN_ECUM_HEADER_RELEASE_VERSION                                0x01u   /* BCD coded release version number  */

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

/*********************************************************************************************************************
* CanSM_PreInit
**********************************************************************************************************************/
/*! \brief       Initializes the configuration data component
 *  \details     Configuration data and variables are initialized
 *  \param[in]   ConfigPtr          Pointer to configuration structure
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous FALSE
 *  \config      CANSM_EXTENDED_RAM_CHECK
 *  \pre         CanSM_InitMemory has been called if CANSM_PREVENT_BUSSLEEP_AT_STARTUP is activated unless CanSM_EnableSetBusSleep[] is initialized by start up code.
 *  \trace       CREQ-106018
 **********************************************************************************************************************/
FUNC( void, CANSM_CODE ) CanSM_PreInit( CONSTP2CONST( CanSM_ConfigType, AUTOMATIC, CANSM_CONST ) ConfigPtr );


/*********************************************************************************************************************
* CanSM_Init
**********************************************************************************************************************/
/*! \brief       Initializes the component
 *  \details     Variables are initialized and the initial transition to no communication will be performed/started.
 *  \param[in]   configPtr          Pointer to configuration structure
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous FALSE
 *  \config      -
 *  \pre         CanSM_InitMemory has been called if CANSM_PREVENT_BUSSLEEP_AT_STARTUP is activated unless CanSM_EnableSetBusSleep[] is initialized by start up code.
 *  \trace       SPEC-638
 **********************************************************************************************************************/
FUNC( void, CANSM_CODE ) CanSM_Init( CONSTP2CONST( CanSM_ConfigType, AUTOMATIC, CANSM_CONST ) ConfigPtr );


/***********************************************************************************************************************
*  CanSM_InitMemory
**********************************************************************************************************************/
/*! \brief       De-initializes the component
 *  \details     pre-initialize some global variables which has to be set before the Init has been called (e.g. after ECU reset without power up)
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      -
 *  \pre         Module is uninitialized.
  *  \note        Use this function in case CanSM_IsInitialized or CanSM_EnableSetBusSleep[] is not initialized by the startup code.
 **********************************************************************************************************************/
FUNC( void, CANSM_CODE ) CanSM_InitMemory( void );


#if ( STD_ON == CANSM_PREVENT_BUSSLEEP_AT_STARTUP )
/*********************************************************************************************************************
  FUNCTION: CanSM_PreventBusSleepAtStartUp
*********************************************************************************************************************/
/*! \brief       Skips initial transition
 *  \details     Memorize channel which must NOT set to sleep during the initialization
 *  \param[in]   CanSM_NetworkHandle    network handle
 *  \return      E_OK      Request was accepted
 *  \return      E_NOT_OK  Request was not accepted
 *  \context     ANY
 *  \reentrant   TRUE for different handles
 *  \synchronous FALSE
 *  \config      -
 *  \pre         CanSM must NOT be initialized, CANSM_USE_INIT_POINTER == STD_OFF
 **********************************************************************************************************************/
FUNC( Std_ReturnType, CANSM_CODE ) CanSM_PreventBusSleepAtStartUp( NetworkHandleType CanSM_NetworkHandle );
#endif /* ( STD_ON == CANSM_PREVENT_BUSSLEEP_AT_STARTUP ) */

/***********************************************************************************************************************
 *  CanSM_StartWakeupSources
 **********************************************************************************************************************/
/*! \brief       Activates CAN hardware
 *  \details     The CAN controller and CAN transceiver will be activated to be able to receive messages (the messages will not be forwarded to other BSW/SWC).
 *               The function call is ignored if the CanSM has already received a full communication request.
 *               If the hardware (transceiver) is connected via SPI the mode change will be probably to slow and function will fail.
 *  \param[in]   CanSM_NetworkHandle     network handle
 *  \return      E_OK                    The CanTrcv mode and CanDrv modes have been changed successfully or no change was necessary
 *  \return      E_NOT_OK                It was not possible to set the CanTrcv or CanDrv to the required state.
 *  \context     ANY
 *  \reentrant   TRUE for different handles
 *  \synchronous TRUE
 *  \config      -
 *  \pre         No communication is requested. The channel is NOT a partial network channel.
 *  \trace       CREQ-361
 **********************************************************************************************************************/
FUNC( Std_ReturnType, CANSM_CODE ) CanSM_StartWakeupSources( NetworkHandleType CanSM_NetworkHandle );


/***********************************************************************************************************************
 *  CanSM_StopWakeupSources
 **********************************************************************************************************************/
/*! \brief       Deactivates CAN hardware
 *  \details     The CAN controller and CAN transceiver will be deactivated. The function is ignored if the CanSM has already received a full communication request.
 *               If the controller could not be set to SLEEP the function returns E_OK and start a new wake up handling via the EcuM.
 *               If the hardware (transceiver) is connected via SPI the mode change will be probably to slow and function will fail.
 *  \param[in]   CanSM_NetworkHandle     network handle
 *  \param[in]   WakeupSource            wake up source
 *  \return      E_OK                    The CanTrcv and CanDrv has been set successful in the required states or a new wake up has been started
 *  \return      E_NOT_OK                It was not possible to set the CanTrcv or CanDrv to the required state.
 *  \context     ANY
 *  \reentrant   TRUE for different handles
 *  \synchronous TRUE
 *  \config      -
 *  \pre         No communication is requested. The channel is NOT a partial network channel.
 *  \trace       CREQ-361
 **********************************************************************************************************************/
FUNC( Std_ReturnType, CANSM_CODE ) CanSM_StopWakeupSources( NetworkHandleType CanSM_NetworkHandle, EcuM_WakeupSourceType WakeupSource  );


# define CANSM_STOP_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */



#endif /* end if not defined ( CANSM_ECUM_H ) */

/**********************************************************************************************************************
 *  END OF FILE: CanSM_EcuM.h
 *********************************************************************************************************************/

