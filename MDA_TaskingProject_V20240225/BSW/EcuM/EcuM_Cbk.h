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
/**        \file  EcuM_Cbk.h
 *        \brief  MICROSAR ECU State Manager
 *
 *      \details  This header provides some EcuM Callback Functions.
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

#ifndef ECUM_CBK_H
# define ECUM_CBK_H

# include "EcuM_Generated_Types.h"
# include "EcuM_Cfg.h"

#if(ECUM_INCLUDE_NVRAM_MGR == STD_ON && ECUM_FIXED_BEHAVIOR == STD_ON)
# include "NvM.h"
#endif

# if(ECUM_CONFIGURATION_VARIANT == ECUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE)
# include "EcuM_Error.h"
# endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* Component Version Information */
# define ECUM_CBK_SW_MAJOR_VERSION                                         (0x10u)
# define ECUM_CBK_SW_MINOR_VERSION                                         (0x00u)
# define ECUM_CBK_SW_PATCH_VERSION                                         (0x00u)

/* AUTOSAR Software Specification Version Information */
# define ECUM_CBK_AR_RELEASE_MAJOR_VERSION                                    (4u)
# define ECUM_CBK_AR_RELEASE_MINOR_VERSION                                    (0u)
# define ECUM_CBK_AR_RELEASE_REVISION_VERSION                                 (3u)

#if defined(ECUM_LOCAL)
#else
# define ECUM_LOCAL static
#endif


/**********************************************************************************************************************
 *  CALLBACK FUNCTIONS
 *********************************************************************************************************************/
# define ECUM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  EcuM_ValidateWakeupEvent
 **********************************************************************************************************************/
/*! \brief       Validate a wake-up event.
 *  \details     After wake-up, the ECU State Manager will stop the process during the WAKEUP VALIDATION state to wait
                 for validation of the wake-up event. The validation is carried out with a call to this API service.
 *  \param[in]   WakeupSource     the wake-up source which should be validated
 *  \pre         -
 *  \context     TASK | ISR
 *  \reentrant   TRUE for different wakeup sources.
 *  \synchronous TRUE
 *  \trace       CREQ-537
 *  \note        This API can only handle one wakeup source, so only one bit is allowed to be set in the mask.
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_ValidateWakeupEvent(EcuM_WakeupSourceType WakeupSource);

/***********************************************************************************************************************
 *  EcuM_SetWakeupEvent
 **********************************************************************************************************************/
/*! \brief       Set a wake-up event.
 *  \details     Marks a wake-up event as pending if validation is required.
 *               If no validation is required then EcuM_ValidateSetWakeupEvent will be called within this function to
 *               mark this source as validated.
 *  \param[in]   WakeupSource     the source of the wake-up event.
 *  \pre         -
 *  \context     TASK | ISR
 *  \reentrant   TRUE for different wakeup sources.
 *  \synchronous TRUE
 *  \trace       CREQ-465
 *  \note        This API can only handle one wakeup source, so only one bit is allowed to be set in the mask.
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_SetWakeupEvent(EcuM_WakeupSourceType WakeupSource);

/***********************************************************************************************************************
 *  EcuM_CheckWakeup
 **********************************************************************************************************************/
/*! \brief       Check a wake-up event.
 *  \details     Polls a wake-up source for occurred wake-up event. It sets up the PLL and check other wakeup sources
 *               that may be connected to the same interrupt.
 *  \param[in]   WakeupSource     the source of the wake-up event.
 *  \pre         -
 *  \context     TASK | ISR
 *  \reentrant   TRUE for different wakeup sources.
 *  \synchronous TRUE
 *  \trace       CREQ-499
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_CheckWakeup(EcuM_WakeupSourceType wakeupSource);

#if (STD_ON == ECUM_FIXED_BEHAVIOR)
# if (STD_ON == ECUM_INCLUDE_NVRAM_MGR)
/***********************************************************************************************************************
 *  EcuM_CB_NfyNvMJobEnd
 **********************************************************************************************************************/
/*! \brief       NvM job end notification.
 *  \details     Callback-function which is used to indicate the end of a Job (in this case NvM_WriteAll() is relevant).
 *  \param[in]   ServiceID_u8            Service Id: NVM_READ_ALL/NVM_WRITE_ALL
 *  \param[in]   JobResult_t             result of the job: failed or OK
 *  \pre         -
 *  \context     TASK | ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_FIXED_BEHAVIOR && ECUM_INCLUDE_NVRAM_MGR
 *  \trace       CREQ-668
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_CB_NfyNvMJobEnd(uint8 ServiceID, NvM_RequestResultType JobResult);
# endif
#endif

#  if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
/***********************************************************************************************************************
 *  EcuM_AlarmCheckWakeup
 **********************************************************************************************************************/
/*! \brief       Checks if alarm has expired.
 *  \details     This function can be used to check the if an Alarm has expired and to increment the EcuM Clock. Function
 *               can be called by services like EcuM_CheckWakeup.
 *  \pre         -
 *  \context     TASK | ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_ALARM_CLOCK_PRESENT
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AlarmCheckWakeup(void);
#  endif

# define ECUM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* ECUM_CBK_H */
/**********************************************************************************************************************
 *  END OF FILE: ECUM_CBK.H
 *********************************************************************************************************************/
