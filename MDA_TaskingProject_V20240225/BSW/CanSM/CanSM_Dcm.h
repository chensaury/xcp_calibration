
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
/* \file    CanSM_Dcm.h
 * \brief   Dcm header of the CAN State Manager AUTOSAR Release 4
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module header file.
 *  -------------------------------------------------------------------------------------------------------------------
 *********************************************************************************************************************/


#ifndef CANSM_DCM_H
# define CANSM_DCM_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/* # include "Std_Types.h" */ /* Std_ReturnType uint16 */
/* # include "Compiler.h" */ /* compiler abstraction */
/* # include "ComStack_Types.h"  */ /* NetworkHandleType; includes ComStack_Types.h, which includes Std_Types.h which include "Platform_Types.h" and include "Compiler.h" */
# include "CanSM_Cfg.h" /* includes ComStack_Types.h  */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : Ccl_Asr4SmCan CQComponent : Implementation */
/* Version - BCD coded version number - Main- and Sub-Version - Release-Version */
# define CCL_ASR4SMCAN_DCM_HEADER_VERSION                                        0x0300u   /* BCD coded version number */
# define CCL_ASR4SMCAN_DCM_HEADER_RELEASE_VERSION                                0x01u   /* BCD coded release version number  */

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


# if ( STD_ON == CANSM_SET_BAUDRATE_API )

/***********************************************************************************************************************
 *  CanSM_SetBaudrate
 **********************************************************************************************************************/
/*! \brief       Change the baud rate
 *  \details     Starts an asynchronous process to change the baud rate
 *  \param[in]   Network           network
 *  \param[in]   BaudRateConfigID  Baud rate configuration ID
 *  \return      E_OK      Request was accepted
 *  \return      E_NOT_OK  Request was not accepted
 *  \context     ANY
 *  \reentrant   TRUE for different handles
 *  \synchronous FALSE
 *  \config      CANSM_SET_BAUDRATE_API
 *  \pre         CanSM mode online / full communication / NO_BUS_OFF / FULLCOM_ENSURED
 *  \trace SPEC-11320, SPEC-47142
 **********************************************************************************************************************/
FUNC( Std_ReturnType, CANSM_CODE ) CanSM_SetBaudrate( NetworkHandleType  Network, uint16  BaudRateConfigID );

# endif  /* if ( STD_ON == CANSM_SET_BAUDRATE_API ) */

# if ( CANSM_CHANGE_BAUDRATE_API == STD_ON )
/***********************************************************************************************************************
 *  CanSM_CheckBaudrate
 **********************************************************************************************************************/
/*! \brief       Check if  baud rate is supported
 *  \details     Check if baud rate is supported via CanIf_CheckBaudrate.
 *  \param[in]   CanSM_NetworkHandle   network handle
 *  \param[in]   CanSM_Baudrate        baud rate
 *  \return      E_OK      Request was accepted
 *  \return      E_NOT_OK  Request was not accepted
 *  \context     ANY
 *  \reentrant   TRUE for different handles
 *  \synchronous FALSE
 *  \config      CANSM_CHANGE_BAUDRATE_API
 *  \pre         CanSM mode online / full communication / NO_BUS_OFF / FULLCOM_ENSURED
 *  \trace SPEC-11320
 **********************************************************************************************************************/
FUNC( Std_ReturnType, CANSM_CODE ) CanSM_CheckBaudrate( NetworkHandleType CanSM_NetworkHandle, CONST(uint16, AUTOMATIC) CanSM_Baudrate );

/***********************************************************************************************************************
 *  CanSM_ChangeBaudrate
 **********************************************************************************************************************/
/*! \brief       Changes the baud rate
 *  \details     Starts an asynchronous process to change the baud rate if the prior checked baud rate is valid
 *  \param[in]   CanSM_NetworkHandle   network handle
 *  \param[in]   CanSM_Baudrate        baud rate
 *  \return      E_OK      Request was accepted
 *  \return      E_NOT_OK  Request was not accepted
 *  \context     ANY
 *  \reentrant   TRUE for different handles
 *  \synchronous FALSE
 *  \config      CANSM_CHANGE_BAUDRATE_API
 *  \pre         CanSM_CheckBaudrate, CanSM mode online / full communication / NO_BUS_OFF / FULLCOM_ENSURED
 *  \trace SPEC-11320
 **********************************************************************************************************************/
FUNC( Std_ReturnType, CANSM_CODE ) CanSM_ChangeBaudrate( NetworkHandleType CanSM_NetworkHandle, CONST(uint16, AUTOMATIC) CanSM_Baudrate );

# endif /* if ( CANSM_CHANGE_BAUDRATE_API == STD_ON ) */

# define CANSM_STOP_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */



#endif /* end if not defined ( CANSM_DCM_H ) */

/**********************************************************************************************************************
 *  END OF FILE: CanSM_Dcm.h
 *********************************************************************************************************************/

