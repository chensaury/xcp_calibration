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
/**        \file  EcuM_Error.h
 *        \brief  MICROSAR ECU State Manager
 *
 *      \details  This header provides the EcuM_BswErrorHook for MICROSAR Bsw Modules.
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

/* ---- Protection against multiple inclusion ----------------------------- */
#ifndef ECUM_ERROR_H
# define ECUM_ERROR_H

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
# define ECUM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  EcuM_BswErrorHook
 **********************************************************************************************************************/
/*! \brief       Bsw Error Hook.
 *  \details     Function which can be called by each BSW module to indicate post-build configuration / generation
 *               issues.
 *  \param[in]   BswModuleId            ASR Module Id
 *  \param[in]   ErrorId                Detected error
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      At least one module which is POSTBUILD_LOADABLE.
 *  \trace       CREQ-431
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_BswErrorHook(uint16 BswModuleId, uint8 ErrorId);

# define ECUM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define ECUM_BSWERROR_NULLPTR                       (0x00u)
#define ECUM_BSWERROR_COMPATIBILITYVERSION          (0x01u)
#define ECUM_BSWERROR_MAGICNUMBER                   (0x02u)
#define ECUM_NO_BSWERROR                            (0xFFu)

#endif /* ECUM_ERROR_H */

/**********************************************************************************************************************
 *  END OF FILE: ECUM_ERROR.H
 *********************************************************************************************************************/
