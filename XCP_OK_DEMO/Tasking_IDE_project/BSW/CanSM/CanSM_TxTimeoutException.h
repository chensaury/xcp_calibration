
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
/* \file    CanSM_TxTimeoutException.h
 * \brief   Tx timeout exception header of the CAN State Manager AUTOSAR Release 4
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module header file.
 *  -------------------------------------------------------------------------------------------------------------------
 *********************************************************************************************************************/


#ifndef CANSM_TXTIMEOUTEXCEPTION_H
# define CANSM_TXTIMEOUTEXCEPTION_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/* # include "Std_Types.h" */  /* uint8 */
/* # include "Compiler.h" */  /* compiler abstraction */
/* # include "ComStack_Types.h" */ /* NetworkHandleType; includes ComStack_Types.h, which includes Std_Types.h which include "Platform_Types.h" and include "Compiler.h" */
# include "CanSM_Cfg.h" /* CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG; includes ComStack_Types.h  */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : Ccl_Asr4SmCan CQComponent : Implementation */
/* Version - BCD coded version number - Main- and Sub-Version - Release-Version */
# define CCL_ASR4SMCAN_TXTIMEOUTEXCEPTION_HEADER_VERSION                                        0x0300u   /* BCD coded version number */
# define CCL_ASR4SMCAN_TXTIMEOUTEXCEPTION_HEADER_RELEASE_VERSION                                0x01u   /* BCD coded release version number  */


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
 *  CanSM_TxTimeoutException
 **********************************************************************************************************************/
/*! \brief       Re-starts the CAN controller
 *  \details     The CanNm has detected a TxTimeout exception for the affected partial CAN network. Re-starts the CAN controller. The function call is ignored in case of a running bus-off recovery. 
 *               It is also possible to restart the CAN Ctrl beside the partial network usecase by usage of the API.
 *  \param[in]   CanSM_NetworkHandle     network handle
 *  \context     ANY
 *  \reentrant   TRUE for different handles
 *  \synchronous FALSE
 *  \config      -
 *  \pre         CanSM mode online / full communication / NO_BUS_OFF / FULLCOM_ENSURED
 *  \trace       CREQ-360
 *  \trace SPEC-11333
 **********************************************************************************************************************/
FUNC( void, CANSM_CODE ) CanSM_TxTimeoutException( NetworkHandleType CanSM_NetworkHandle );


# define CANSM_STOP_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */



#endif /* end if not defined ( CANSM_TXTIMEOUTEXCEPTION_H ) */

/**********************************************************************************************************************
 *  END OF FILE: CanSM_TxTimeoutException.h
 *********************************************************************************************************************/

