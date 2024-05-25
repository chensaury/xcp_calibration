/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**         \file  ComM_Dcm.h
 *         \brief  Communication Manager ASR4
 *
 *       \details  Callback API of the communication manager for the DCM
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

#ifndef COMM_DCM_H
# define COMM_DCM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "ComM_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# define COMM_DCM_MAJOR_VERSION    (9u)
# define COMM_DCM_MINOR_VERSION    (0u)
# define COMM_DCM_PATCH_VERSION    (1u)

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
 *  CALLBACK FUNCTIONS PROTOTYPES (called by Dcm)
 *********************************************************************************************************************/

# define COMM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"

#  if (COMM_DCM_INDICATION == STD_ON)
/**********************************************************************************************************************
 * ComM_DCM_ActiveDiagnostic()
 *********************************************************************************************************************/
/*! \brief       Indication of active diagnostic by the DCM.
 *  \details     -
 *  \param[in]   Channel                Valid channel identifier (network handle)
 *  \pre         Nm Variant of the channel must not be PASSIVE
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous FALSE
 *  \trace       CREQ-102677
*********************************************************************************************************************/
extern FUNC(void, COMM_CODE) ComM_DCM_ActiveDiagnostic(NetworkHandleType Channel);

/**********************************************************************************************************************
 * ComM_DCM_InactiveDiagnostic()
 *********************************************************************************************************************/
/*! \brief       Indication of inactive diagnostic by the DCM.
 *  \details     -
 *  \param[in]   Channel                Valid channel identifier (network handle)
 *  \pre         Nm Variant of the channel must not be PASSIVE
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous FALSE
 *  \trace       CREQ-102677
*********************************************************************************************************************/
extern FUNC(void, COMM_CODE) ComM_DCM_InactiveDiagnostic(NetworkHandleType Channel);
#  endif

# define COMM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"

#endif  /* COMM_DCM_H */

/**********************************************************************************************************************
  END OF FILE: ComM_Dcm.h
**********************************************************************************************************************/
