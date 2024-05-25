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
/**        \file  BswM_NvM.h
 *        \brief  MICROSAR Basic Software Mode Manager
 *
 *      \details  Callback header for NvM.
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
#if !defined BSWM_NVM_H
# define BSWM_NVM_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "NvM.h"
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
 *  BswM_NvM_CurrentBlockMode()
 *********************************************************************************************************************/
/*! \brief      Function called by NvM to indicate the current block mode of a NvM block.
 * \details     Passed mode is stored and depending rules are arbitrated.
 * \param[in]   Block               The Block that the new NvM Mode corresponds to.
 * \param[in]   CurrentBlockMode    The current block mode of the NvM block.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for different blocks
 * \synchronous TRUE
 * \config      BSWM_ENABLE_NVM
 * \trace       SPEC-16738, SPEC-7795, SPEC-7945
 */
extern FUNC(void, BSWM_CODE) BswM_NvM_CurrentBlockMode(NvM_BlockIdType Block, NvM_RequestResultType CurrentBlockMode);

/**********************************************************************************************************************
 *  BswM_NvM_CurrentJobMode()
 *********************************************************************************************************************/
/*! \brief      Function called by NvM to inform the BswM about the current state of a multi block job.
 * \details     Passed mode is stored and depending rules are arbitrated.
 * \param[in]   ServiceId       Indicates whether the callback refers to service NvM_ReadAll or NvM_WriteAll.
 * \param[in]   CurrentJobMode  Current state of the job indicated by parameter ServiceId.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for different services
 * \synchronous TRUE
 * \config      BSWM_ENABLE_NVM
 * \trace       SPEC-16732, SPEC-16676, SPEC-16673, SPEC-16749
 */
extern FUNC(void, BSWM_CODE) BswM_NvM_CurrentJobMode(uint8 ServiceId, NvM_RequestResultType CurrentJobMode);

# define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h" 

#endif

/**********************************************************************************************************************
  EOF
**********************************************************************************************************************/
