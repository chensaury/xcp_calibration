/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 * \addtogroup Os_Alarm
 * \{
 *
 * \file
 * \brief       OS services for alarm management.
 * \details     --no details--
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_ALARM_H
# define OS_ALARM_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module dependencies */
# include "Os_AlarmInt.h"

/* Os kernel module dependencies */
# include "OsInt.h"
# include "Os_Lcfg.h"
# include "Os_Core.h"
# include "Os_Job.h"
# include "Os_Counter.h"
# include "Os_Application.h"
# include "Os_Task.h"
# include "Os_Common.h"

/* Os Hal dependencies */
# include "Os_Hal_Compiler.h"




/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_AlarmGetCore()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
P2CONST(Os_CoreAsrConfigType, TYPEDEF, OS_CONST),  OS_CODE, OS_ALWAYS_INLINE, Os_AlarmGetCore,
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  return Os_JobGetCore(&(Alarm->Job));                                                                                  /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_AlarmCheckId()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_AlarmCheckId,
(
  AlarmType AlarmId
))
{
  return Os_ErrExtendedCheck(Os_ErrIsValueLo((uint32)AlarmId, (uint32)OS_ALARMID_COUNT));
}


/***********************************************************************************************************************
 *  Os_AlarmId2Alarm()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_AlarmId2Alarm,
(
  AlarmType AlarmId
))
{
  Os_Assert(Os_ErrIsValueLo((uint32)AlarmId, (uint32)OS_ALARMID_COUNT));
  return OsCfg_AlarmRefs[AlarmId];
}


/***********************************************************************************************************************
 *  Os_AlarmGetApplication()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_AlarmGetApplication,
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm
))
{
  return Alarm->OwnerApplication;
}


/***********************************************************************************************************************
 *  Os_AlarmGetAccessingApplications()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_AppAccessMaskType, OS_CODE,                                             /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_AlarmGetAccessingApplications,
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm
))
{
  return Alarm->AccessingApplications;
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_ALARM_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Alarm.h
 **********************************************************************************************************************/
