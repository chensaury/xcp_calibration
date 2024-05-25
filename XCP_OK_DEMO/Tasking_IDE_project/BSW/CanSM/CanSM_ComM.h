
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
/* \file    CanSM_ComM.h
 * \brief   ComM header of the CAN State Manager AUTOSAR Release 4
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module header file.
 *  -------------------------------------------------------------------------------------------------------------------
 *********************************************************************************************************************/


#ifndef CANSM_COMM_H
# define CANSM_COMM_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/* # include "Std_Types.h" */ /* Std_ReturnType  */
/* # include "Compiler.h" */ /* compiler abstraction */
# include "ComStack_Types.h" /* NetworkHandleType; includes ComStack_Types.h, which includes Std_Types.h which include "Platform_Types.h" and include "Compiler.h" */
/* \trace SPEC-636 */
# include "ComM_Types.h"        /* needed cause of ComM_ModeType */
# include "CanSM_Cfg.h" /* CANSM_EXTENDED_RAM_CHECK */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : Ccl_Asr4SmCan CQComponent : Implementation */
/* Version - BCD coded version number - Main- and Sub-Version - Release-Version */
# define CCL_ASR4SMCAN_COMM_HEADER_VERSION                                        0x0300u   /* BCD coded version number */
# define CCL_ASR4SMCAN_COMM_HEADER_RELEASE_VERSION                                0x01u   /* BCD coded release version number  */

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
 *  CanSM_RequestComMode
 **********************************************************************************************************************/
/*! \brief       Initiates the sequence to reach the requested communication mode
 *  \details     stores the requested communication mode for the network handle and executes the corresponding network mode state machine direct or in the context      of the CanSM main function.
 *  \param[in]   CanSM_NetworkHandle     network handle
 *  \param[in]   CanSM_RequestedComMMode        Requested communication mode (silent communication request is only accepted if full communication is requested)
 *  \return      E_OK      Request was accepted
 *  \return      E_NOT_OK  Request was not accepted
 *  \context     ANY
 *  \reentrant   TRUE for different handles
 *  \synchronous FALSE
 *  \config      -
 *  \pre         -
 *  \trace       SPEC-639
 **********************************************************************************************************************/
FUNC( Std_ReturnType, CANSM_CODE ) CanSM_RequestComMode( NetworkHandleType CanSM_NetworkHandle, ComM_ModeType CanSM_RequestedComMMode );

/***********************************************************************************************************************
*  CanSM_GetCurrentComMode
**********************************************************************************************************************/
/*! \brief       Reports the communication mode
 *  \details     Reports the last communication mode which has been passed to the ComM
 *  \param[in]   CanSM_NetworkHandle     Network handle
 *  \param[out]  CanSM_ComM_ModePtr      Pointer to communication mode destination
 *  \return      E_OK      Request was accepted
 *  \return      E_NOT_OK  Request was not accepted
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous FALSE
 *  \config      -
 *  \pre         -
 *  \trace       CREQ-1011
 *  \trace       SPEC-639
 **********************************************************************************************************************/
FUNC( Std_ReturnType, CANSM_CODE ) CanSM_GetCurrentComMode( NetworkHandleType CanSM_NetworkHandle, P2VAR( ComM_ModeType, AUTOMATIC, CANSM_APPL_VAR ) CanSM_ComMModePtr);


#if ( CANSM_EXTENDED_RAM_CHECK == STD_ON )
/***********************************************************************************************************************
*  CanSM_RamCheckStatus
**********************************************************************************************************************/
/*! \brief       Reports the RAM check status
 *  \details     Reports the last RAM check status to the ComM.
 *  \param[in]   CanSM_NetworkHandle     Network handle 
 *  \return      CANSM_ENABLE_COMMUNICATION         Every thing is E_OK
 *               CANSM_DISABLE_COMMUNICATION        Communication shall be disabled
*                CANSM_ENABLE_COMMUNICATION_REPEAT  Communication shall be enabled and the RAM check repeated
*                CANSM_DISABLE_COMMUNICATION_REPEAT Communication shall be disabled and the RAM check repeated
 *               E_NOT_OK                           Wrong parameter
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      CANSM_EXTENDED_RAM_CHECK
 *  \pre         -
 *  \trace       CREQ-106018
 **********************************************************************************************************************/
FUNC( Std_ReturnType, CANSM_CODE ) CanSM_RamCheckStatus( NetworkHandleType CanSM_NetworkHandle );
#endif  /* CANSM_EXTENDED_RAM_CHECK */




# define CANSM_STOP_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */



#endif /* end if not defined ( CANSM_COMM_H ) */

/**********************************************************************************************************************
 *  END OF FILE: CanSM_ComM.h
 *********************************************************************************************************************/

