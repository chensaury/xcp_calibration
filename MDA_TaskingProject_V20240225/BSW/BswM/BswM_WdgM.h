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
/**        \file  BswM_WdgM.h
 *        \brief  MICROSAR Basic Software Mode Manager
 *
 *      \details  Callback header for WdgM.
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
#if !defined BSWM_WDGM_H
# define BSWM_WDGM_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "Os.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT VERSIONS
 *********************************************************************************************************************/

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
# define BSWM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h" 

/**********************************************************************************************************************
 *  BswM_WdgM_RequestPartitionReset()
 *********************************************************************************************************************/
/*! \brief      Function called by WdgM to inform the BswM about a partition reset.
 * \details     Passed application is stored and depending rules are arbitrated.
 * \param[in]   Application   Application which shall be reseted.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \config      BSWM_ENABLE_WDGM
 * \trace       SPEC-16714, SPEC-16735
 */
extern FUNC(void, BSWM_CODE) BswM_WdgM_RequestPartitionReset(ApplicationType Application);

# define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h" 

#endif /* BSWM_WDGM_H */

/**********************************************************************************************************************
 *  END OF FILE: BswM_WdgM.h
 *********************************************************************************************************************/
