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
 * \ingroup    Os_Kernel
 * \defgroup   Os_Common Common
 * \brief      Common functionality/concepts which are used nearly everywhere in the kernel.
 * \details    --no details--
 *
 * \{
 * \file
 * \brief      Common data types and small helper functions.
 * \details    --no details--
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/


#ifndef OS_COMMONINT_H
# define OS_COMMONINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module dependencies */
# include "Os_Common_Types.h"
# include "OsInt.h"
# include "Os_Hook_Types.h"

# ifdef CDK_CHECK_MISRA                                                                                                 /* COV_OS_CDKMISRA */
#  ifndef OS_STATIC_CODE_ANALYSIS                                                                                       /* COV_OS_STATICCODEANALYSIS */
#    define OS_STATIC_CODE_ANALYSIS
#  endif
# endif


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! \brief  Union of all OS API parameter types in arbitrary order.
 *  \details
 *  As the OS interface does not use the AUTOSAR compiler abstraction (P2CONST etc.),
 *  these macros may not be used here.
 *
 *  Used for OSEK API OSError_x1_x2().
 *  The the API provides the ability to get the faulty parameters which caused the error.
 */
union Os_ParamType_Tag
{                                                                                                                       /* PRQA S 0750 */ /* MD_MSR_Union */
  AlarmBaseRefType                          ParamAlarmBaseRefType;
  AlarmType                                 ParamAlarmType;
  AppModeType                               ParamAppModeType;
  ApplicationStateRefType                   ParamApplicationStateRefType;
  ApplicationStateType                      ParamApplicationStateType;
  ApplicationType                           ParamApplicationType;
  boolean                                   Paramboolean;
  boolean*                                  ParambooleanRefType;
  CoreIdType                                ParamCoreIdType;
  CounterType                               ParamCounterType;
  EventMaskType                             ParamEventMaskType;
  EventMaskType*                            ParamEventMaskRefType;
  ISRType                                   ParamISRType;
  IdleModeType                              ParamIdleModeType;
  MemorySizeType                            ParamMemorySizeType;
  MemoryStartAddressType                    ParamMemoryStartAddressType;
  ResourceType                              ParamResourceType;
  RestartType                               ParamRestartType;
  ScheduleTableStatusRefType                ParamScheduleTableStatusRefType;
  ScheduleTableStatusType                   ParamScheduleTableStatusType;
  ScheduleTableType                         ParamScheduleTableType;
  SpinlockIdType                            ParamSpinlockIdType;
  StatusType                                ParamStatusType;
  Std_VersionInfoType *                     ParamStd_VersionInfoRefType;
  TaskRefType                               ParamTaskRefType;
  TaskStateRefType                          ParamTaskStateRefType;
  TaskStateType                             ParamTaskStateType;
  TaskType                                  ParamTaskType;
  TickRefType                               ParamTickRefType;
  TickType                                  ParamTickType;
  TrustedFunctionIndexType                  ParamTrustedFunctionIndexType;
  TrustedFunctionParameterRefType           ParamTrustedFunctionParameterRefType;
  TryToGetSpinlockType *                    ParamTryToGetSpinlockRefType;
  TryToGetSpinlockType const*               ParamTryToGetSpinlockConstRefType;
  uint32                                    Paramuint32;
  void const*                               ParamVoidRefType;
  ObjectTypeType                            ParamObjectTypeType;
  Os_NonTrustedFunctionIndexType            ParamOs_NonTrustedFunctionIndexType;
  Os_NonTrustedFunctionParameterRefType     ParamOs_NonTrustedFunctionParameterRefType;
  Os_FastTrustedFunctionIndexType           ParamOs_FastTrustedFunctionIndexType;
  Os_FastTrustedFunctionParameterRefType    ParamOs_FastTrustedFunctionParameterRefType;
  Os_ExceptionSourceIdType                  ParamExceptionSourceIdType;
  Os_InterruptSourceIdType                  ParamInterruptSourceIdType;
  Os_ExceptionSourceIdRefType               ParamExceptionSourceIdRefType;
  Os_InterruptSourceIdRefType               ParamInterruptSourceIdRefType;
  Os_ObjectIdType                           ParamObjectIdType;
  Os_PeripheralIdType                       ParamPeripheralIdType;
  Os_ErrorInformationRefType                ParamErrorInformationRefType;
  Os_HookIdType                             ParamHookIdType;
  Os_BarrierIdType                          ParamBarrierIdType;
  Os_ExceptionContextRefType                ParamExceptionContextRefType;
};


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */



# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_COMMONINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_CommonInt.h
 **********************************************************************************************************************/
