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
 * \addtogroup Os_ScheduleTable
 * \{
 *
 * \file
 * \brief       OS services for schedule table management.
 * \details     --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_SCHEDULETABLE_H
# define OS_SCHEDULETABLE_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
# include "Os_ScheduleTableInt.h"

/* Os kernel module dependencies */
# include "OsInt.h"
# include "Os_Lcfg.h"
# include "Os_Counter.h"
# include "Os_Job.h"
# include "Os_Core.h"
# include "Os_Common.h"
# include "Os_Task.h"

/* Os hal dependencies */
# include "Os_Hal_Compiler.h"



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
 *  Os_SchTCheckId()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_SchTCheckId,
(
 ScheduleTableType ScheduleTableId
))
{
  return Os_ErrExtendedCheck(Os_ErrIsValueLo((uint32)ScheduleTableId, (uint32)OS_SCHTID_COUNT));
}


/***********************************************************************************************************************
 *  Os_SchTId2SchT()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_SchTId2SchT,
(
  ScheduleTableType SchTId
))
{
  Os_Assert(Os_ErrIsValueLo((uint32)SchTId, (uint32)OS_SCHTID_COUNT));
  return OsCfg_SchTRefs[SchTId];
}


/***********************************************************************************************************************
 *  Os_SchTGetCore()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_LOCAL_INLINE P2CONST(Os_CoreAsrConfigType, TYPEDEF, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_SchTGetCore,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) SchT
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  return Os_JobGetCore(&(SchT->Job));                                                                                   /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SchTGetApplication()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_SchTGetApplication,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) SchT
))
{
  return SchT->OwnerApplication;
}


/***********************************************************************************************************************
 *  Os_SchTGetAccessingApplications()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_AppAccessMaskType, OS_CODE,                                             /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_SchTGetAccessingApplications,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) SchT
))
{
  return SchT->AccessingApplications;
}

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_SCHEDULETABLE_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_ScheduleTable.h
 **********************************************************************************************************************/
