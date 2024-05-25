/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: MSR_Vector_SLP4
 *          Customer: Aptiv (China) Technology Company Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Aurix 2G/TC397 B-Step
 *    License Scope : The usage is restricted to CBD1900078_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Alarm_Lcfg.c
 *   Generation Time: 2024-01-08 16:27:30
 *           Project: Bsw_Project - Version 1.0
 *          Delivery: CBD1900078_D01
 *      Tool Version: DaVinci Configurator (beta) 5.18.42 SP2
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Pro and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_ALARM_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Alarm_Lcfg.h"
#include "Os_Alarm.h"

/* Os kernel module dependencies */
#include "Os_Application_Lcfg.h"
#include "Os_Cfg.h"
#include "Os_Common.h"
#include "Os_Counter_Lcfg.h"
#include "Os_Counter.h"
#include "Os_Task_Lcfg.h"
#include "Os_Timer.h"

/* Os hal dependencies */


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic alarm data: Rte_Al_TE2_SchM_Core0_0_10ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE2_SchM_Core0_0_10ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE2_SchM_Core0_0_1ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE2_SchM_Core0_0_1ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE2_SchM_Core0_0_20ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE2_SchM_Core0_0_20ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE2_SchM_Core0_0_5ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE2_SchM_Core0_0_5ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_CtCDD_CtCDD */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_CtCDD_CtCDD_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_CtIoHardWare_Adc_Write */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_CtIoHardWare_Adc_Write_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_CtMDA_Control_Logic_MDA_Control_Logic */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_CtMDA_Control_Logic_MDA_Control_Logic_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_CtPSI5_Handler_PSI5MAIN_HD */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_CtPSI5_Handler_PSI5MAIN_HD_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_CtPT2000_Handler_PT2000_Diag_HD */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_CtPT2000_Handler_PT2000_Diag_HD_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_CtPT2000_Handler_PT2000_Main_HD */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_CtPT2000_Handler_PT2000_Main_HD_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_CtPWM_Handler_PWM_SET */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_CtPWM_Handler_PWM_SET_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic alarm data: Rte_Al_TE1_EcuM_EcuM_MainFunction */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE1_EcuM_EcuM_MainFunction_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_CtMotor_FL_CpApMotor_FL */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_CtMotor_FL_CpApMotor_FL_Dyn;

#define OS_STOP_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic alarm data: Rte_Al_TE2_EcuM_EcuM_MainFunction */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE2_EcuM_EcuM_MainFunction_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_CtMotor_FR_CpApMotor_FR */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_CtMotor_FR_CpApMotor_FR_Dyn;

#define OS_STOP_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE3_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic alarm data: Rte_Al_TE3_EcuM_EcuM_MainFunction */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE3_EcuM_EcuM_MainFunction_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_CtMotor_RL_CpApMotor_RL */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_CtMotor_RL_CpApMotor_RL_Dyn;

#define OS_STOP_SEC_CORE3_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE4_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic alarm data: Rte_Al_TE4_EcuM_EcuM_MainFunction */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE4_EcuM_EcuM_MainFunction_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_CtMotor_RR_CpApMotor_RR */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_CtMotor_RR_CpApMotor_RR_Dyn;

#define OS_STOP_SEC_CORE4_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE5_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic alarm data: Rte_Al_TE6_EcuM_EcuM_MainFunction */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE6_EcuM_EcuM_MainFunction_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Core5swc_Runnable */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Core5swc_Runnable_Dyn;

#define OS_STOP_SEC_CORE5_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Alarm configuration data: Rte_Al_TE2_SchM_Core0_0_10ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_SchM_Core0_0_10ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE2_SchM_Core0_0_10ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer0),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0uL, /* 0.0 sec */
      /* .Cycle            = */ 0uL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore1) | OS_APPID2MASK(SystemApplication_OsCore2) | OS_APPID2MASK(SystemApplication_OsCore3) | OS_APPID2MASK(SystemApplication_OsCore4) | OS_APPID2MASK(SystemApplication_OsCore5)),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0
  },
  /* .Task  = */ &OsCfg_Task_SchM_Core0,
  /* .Mask  = */ Rte_Ev_Cyclic2_SchM_Core0_0_10ms
};

/*! Alarm configuration data: Rte_Al_TE2_SchM_Core0_0_1ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_SchM_Core0_0_1ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE2_SchM_Core0_0_1ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer0),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0uL, /* 0.0 sec */
      /* .Cycle            = */ 0uL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore1) | OS_APPID2MASK(SystemApplication_OsCore2) | OS_APPID2MASK(SystemApplication_OsCore3) | OS_APPID2MASK(SystemApplication_OsCore4) | OS_APPID2MASK(SystemApplication_OsCore5)),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0
  },
  /* .Task  = */ &OsCfg_Task_SchM_Core0,
  /* .Mask  = */ Rte_Ev_Cyclic2_SchM_Core0_0_1ms
};

/*! Alarm configuration data: Rte_Al_TE2_SchM_Core0_0_20ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_SchM_Core0_0_20ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE2_SchM_Core0_0_20ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer0),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0uL, /* 0.0 sec */
      /* .Cycle            = */ 0uL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore1) | OS_APPID2MASK(SystemApplication_OsCore2) | OS_APPID2MASK(SystemApplication_OsCore3) | OS_APPID2MASK(SystemApplication_OsCore4) | OS_APPID2MASK(SystemApplication_OsCore5)),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0
  },
  /* .Task  = */ &OsCfg_Task_SchM_Core0,
  /* .Mask  = */ Rte_Ev_Cyclic2_SchM_Core0_0_20ms
};

/*! Alarm configuration data: Rte_Al_TE2_SchM_Core0_0_5ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_SchM_Core0_0_5ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE2_SchM_Core0_0_5ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer0),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0uL, /* 0.0 sec */
      /* .Cycle            = */ 0uL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore1) | OS_APPID2MASK(SystemApplication_OsCore2) | OS_APPID2MASK(SystemApplication_OsCore3) | OS_APPID2MASK(SystemApplication_OsCore4) | OS_APPID2MASK(SystemApplication_OsCore5)),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0
  },
  /* .Task  = */ &OsCfg_Task_SchM_Core0,
  /* .Mask  = */ Rte_Ev_Cyclic2_SchM_Core0_0_5ms
};

/*! Alarm configuration data: Rte_Al_TE_CtCDD_CtCDD */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_CtCDD_CtCDD =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_CtCDD_CtCDD_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer0),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0uL, /* 0.0 sec */
      /* .Cycle            = */ 0uL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore1) | OS_APPID2MASK(SystemApplication_OsCore2) | OS_APPID2MASK(SystemApplication_OsCore3) | OS_APPID2MASK(SystemApplication_OsCore4) | OS_APPID2MASK(SystemApplication_OsCore5)),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0
  },
  /* .Task  = */ &OsCfg_Task_Core_OsTask_CDD
};

/*! Alarm configuration data: Rte_Al_TE_CtIoHardWare_Adc_Write */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_CtIoHardWare_Adc_Write =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_CtIoHardWare_Adc_Write_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer0),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0uL, /* 0.0 sec */
      /* .Cycle            = */ 0uL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore1) | OS_APPID2MASK(SystemApplication_OsCore2) | OS_APPID2MASK(SystemApplication_OsCore3) | OS_APPID2MASK(SystemApplication_OsCore4) | OS_APPID2MASK(SystemApplication_OsCore5)),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0
  },
  /* .Task  = */ &OsCfg_Task_Core_OsTask_IOHW,
  /* .Mask  = */ Rte_Ev_Run_CtIoHardWare_Adc_Write
};

/*! Alarm configuration data: Rte_Al_TE_CtMDA_Control_Logic_MDA_Control_Logic */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_CtMDA_Control_Logic_MDA_Control_Logic =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_CtMDA_Control_Logic_MDA_Control_Logic_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer0),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0uL, /* 0.0 sec */
      /* .Cycle            = */ 0uL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore1) | OS_APPID2MASK(SystemApplication_OsCore2) | OS_APPID2MASK(SystemApplication_OsCore3) | OS_APPID2MASK(SystemApplication_OsCore4) | OS_APPID2MASK(SystemApplication_OsCore5)),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0
  },
  /* .Task  = */ &OsCfg_Task_APP_Task_Core0
};

/*! Alarm configuration data: Rte_Al_TE_CtPSI5_Handler_PSI5MAIN_HD */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_CtPSI5_Handler_PSI5MAIN_HD =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_CtPSI5_Handler_PSI5MAIN_HD_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer0),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0uL, /* 0.0 sec */
      /* .Cycle            = */ 0uL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore1) | OS_APPID2MASK(SystemApplication_OsCore2) | OS_APPID2MASK(SystemApplication_OsCore3) | OS_APPID2MASK(SystemApplication_OsCore4) | OS_APPID2MASK(SystemApplication_OsCore5)),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0
  },
  /* .Task  = */ &OsCfg_Task_Core_OsTask_PSI5
};

/*! Alarm configuration data: Rte_Al_TE_CtPT2000_Handler_PT2000_Diag_HD */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_CtPT2000_Handler_PT2000_Diag_HD =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_CtPT2000_Handler_PT2000_Diag_HD_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer0),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0uL, /* 0.0 sec */
      /* .Cycle            = */ 0uL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore1) | OS_APPID2MASK(SystemApplication_OsCore2) | OS_APPID2MASK(SystemApplication_OsCore3) | OS_APPID2MASK(SystemApplication_OsCore4) | OS_APPID2MASK(SystemApplication_OsCore5)),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0
  },
  /* .Task  = */ &OsCfg_Task_Core_OsTask_PT2000,
  /* .Mask  = */ Rte_Ev_Run_CtPT2000_Handler_PT2000_Diag_HD
};

/*! Alarm configuration data: Rte_Al_TE_CtPT2000_Handler_PT2000_Main_HD */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_CtPT2000_Handler_PT2000_Main_HD =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_CtPT2000_Handler_PT2000_Main_HD_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer0),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0uL, /* 0.0 sec */
      /* .Cycle            = */ 0uL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore1) | OS_APPID2MASK(SystemApplication_OsCore2) | OS_APPID2MASK(SystemApplication_OsCore3) | OS_APPID2MASK(SystemApplication_OsCore4) | OS_APPID2MASK(SystemApplication_OsCore5)),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0
  },
  /* .Task  = */ &OsCfg_Task_Core_OsTask_PT2000,
  /* .Mask  = */ Rte_Ev_Run_CtPT2000_Handler_PT2000_Main_HD
};

/*! Alarm configuration data: Rte_Al_TE_CtPWM_Handler_PWM_SET */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_CtPWM_Handler_PWM_SET =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_CtPWM_Handler_PWM_SET_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer0),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0uL, /* 0.0 sec */
      /* .Cycle            = */ 0uL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore1) | OS_APPID2MASK(SystemApplication_OsCore2) | OS_APPID2MASK(SystemApplication_OsCore3) | OS_APPID2MASK(SystemApplication_OsCore4) | OS_APPID2MASK(SystemApplication_OsCore5)),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0
  },
  /* .Task  = */ &OsCfg_Task_Core_OsTask_IOHW,
  /* .Mask  = */ Rte_Ev_Run_CtPWM_Handler_PWM_SET
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Alarm configuration data: Rte_Al_TE1_EcuM_EcuM_MainFunction */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE1_EcuM_EcuM_MainFunction =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE1_EcuM_EcuM_MainFunction_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer1),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0uL, /* 0.0 sec */
      /* .Cycle            = */ 0uL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore1) | OS_APPID2MASK(SystemApplication_OsCore2) | OS_APPID2MASK(SystemApplication_OsCore3) | OS_APPID2MASK(SystemApplication_OsCore4) | OS_APPID2MASK(SystemApplication_OsCore5)),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore1
  },
  /* .Task  = */ &OsCfg_Task_SchM_Core1
};

/*! Alarm configuration data: Rte_Al_TE_CtMotor_FL_CpApMotor_FL */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_CtMotor_FL_CpApMotor_FL =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_CtMotor_FL_CpApMotor_FL_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer1),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0uL, /* 0.0 sec */
      /* .Cycle            = */ 0uL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore1) | OS_APPID2MASK(SystemApplication_OsCore2) | OS_APPID2MASK(SystemApplication_OsCore3) | OS_APPID2MASK(SystemApplication_OsCore4) | OS_APPID2MASK(SystemApplication_OsCore5)),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore1
  },
  /* .Task  = */ &OsCfg_Task_APP_Task_Core1
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Alarm configuration data: Rte_Al_TE2_EcuM_EcuM_MainFunction */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_EcuM_EcuM_MainFunction =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE2_EcuM_EcuM_MainFunction_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer2),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0uL, /* 0.0 sec */
      /* .Cycle            = */ 0uL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore1) | OS_APPID2MASK(SystemApplication_OsCore2) | OS_APPID2MASK(SystemApplication_OsCore3) | OS_APPID2MASK(SystemApplication_OsCore4) | OS_APPID2MASK(SystemApplication_OsCore5)),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore2
  },
  /* .Task  = */ &OsCfg_Task_SchM_Core2
};

/*! Alarm configuration data: Rte_Al_TE_CtMotor_FR_CpApMotor_FR */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_CtMotor_FR_CpApMotor_FR =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_CtMotor_FR_CpApMotor_FR_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer2),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0uL, /* 0.0 sec */
      /* .Cycle            = */ 0uL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore1) | OS_APPID2MASK(SystemApplication_OsCore2) | OS_APPID2MASK(SystemApplication_OsCore3) | OS_APPID2MASK(SystemApplication_OsCore4) | OS_APPID2MASK(SystemApplication_OsCore5)),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore2
  },
  /* .Task  = */ &OsCfg_Task_APP_Task_Core2
};

#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE3_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Alarm configuration data: Rte_Al_TE3_EcuM_EcuM_MainFunction */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE3_EcuM_EcuM_MainFunction =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE3_EcuM_EcuM_MainFunction_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer3),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0uL, /* 0.0 sec */
      /* .Cycle            = */ 0uL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore1) | OS_APPID2MASK(SystemApplication_OsCore2) | OS_APPID2MASK(SystemApplication_OsCore3) | OS_APPID2MASK(SystemApplication_OsCore4) | OS_APPID2MASK(SystemApplication_OsCore5)),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore3
  },
  /* .Task  = */ &OsCfg_Task_SchM_Core3
};

/*! Alarm configuration data: Rte_Al_TE_CtMotor_RL_CpApMotor_RL */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_CtMotor_RL_CpApMotor_RL =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_CtMotor_RL_CpApMotor_RL_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer3),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0uL, /* 0.0 sec */
      /* .Cycle            = */ 0uL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore1) | OS_APPID2MASK(SystemApplication_OsCore2) | OS_APPID2MASK(SystemApplication_OsCore3) | OS_APPID2MASK(SystemApplication_OsCore4) | OS_APPID2MASK(SystemApplication_OsCore5)),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore3
  },
  /* .Task  = */ &OsCfg_Task_APP_Task_Core3
};

#define OS_STOP_SEC_CORE3_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE4_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Alarm configuration data: Rte_Al_TE4_EcuM_EcuM_MainFunction */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE4_EcuM_EcuM_MainFunction =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE4_EcuM_EcuM_MainFunction_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer4),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0uL, /* 0.0 sec */
      /* .Cycle            = */ 0uL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore1) | OS_APPID2MASK(SystemApplication_OsCore2) | OS_APPID2MASK(SystemApplication_OsCore3) | OS_APPID2MASK(SystemApplication_OsCore4) | OS_APPID2MASK(SystemApplication_OsCore5)),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore4
  },
  /* .Task  = */ &OsCfg_Task_SchM_Core4
};

/*! Alarm configuration data: Rte_Al_TE_CtMotor_RR_CpApMotor_RR */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_CtMotor_RR_CpApMotor_RR =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_CtMotor_RR_CpApMotor_RR_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer4),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0uL, /* 0.0 sec */
      /* .Cycle            = */ 0uL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore1) | OS_APPID2MASK(SystemApplication_OsCore2) | OS_APPID2MASK(SystemApplication_OsCore3) | OS_APPID2MASK(SystemApplication_OsCore4) | OS_APPID2MASK(SystemApplication_OsCore5)),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore4
  },
  /* .Task  = */ &OsCfg_Task_APP_Task_Core4
};

#define OS_STOP_SEC_CORE4_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE5_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Alarm configuration data: Rte_Al_TE6_EcuM_EcuM_MainFunction */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE6_EcuM_EcuM_MainFunction =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE6_EcuM_EcuM_MainFunction_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer5),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0uL, /* 0.0 sec */
      /* .Cycle            = */ 0uL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore1) | OS_APPID2MASK(SystemApplication_OsCore2) | OS_APPID2MASK(SystemApplication_OsCore3) | OS_APPID2MASK(SystemApplication_OsCore4) | OS_APPID2MASK(SystemApplication_OsCore5)),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore5
  },
  /* .Task  = */ &OsCfg_Task_SchM_Core5
};

/*! Alarm configuration data: Rte_Al_TE_Core5swc_Runnable */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Core5swc_Runnable =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Core5swc_Runnable_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer5),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0uL, /* 0.0 sec */
      /* .Cycle            = */ 0uL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore1) | OS_APPID2MASK(SystemApplication_OsCore2) | OS_APPID2MASK(SystemApplication_OsCore3) | OS_APPID2MASK(SystemApplication_OsCore4) | OS_APPID2MASK(SystemApplication_OsCore5)),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore5
  },
  /* .Task  = */ &OsCfg_Task_APP_Task_Core5
};

#define OS_STOP_SEC_CORE5_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for alarms. */
CONSTP2CONST(Os_AlarmConfigType, OS_CONST, OS_CONST) OsCfg_AlarmRefs[OS_ALARMID_COUNT + 1] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE1_EcuM_EcuM_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_EcuM_EcuM_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_SchM_Core0_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_SchM_Core0_0_1ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_SchM_Core0_0_20ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_SchM_Core0_0_5ms),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE3_EcuM_EcuM_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE4_EcuM_EcuM_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE6_EcuM_EcuM_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Core5swc_Runnable),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CtCDD_CtCDD),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CtIoHardWare_Adc_Write),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CtMDA_Control_Logic_MDA_Control_Logic),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CtMotor_FL_CpApMotor_FL),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CtMotor_FR_CpApMotor_FR),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CtMotor_RL_CpApMotor_RL),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CtMotor_RR_CpApMotor_RR),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CtPSI5_Handler_PSI5MAIN_HD),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CtPT2000_Handler_PT2000_Diag_HD),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CtPT2000_Handler_PT2000_Main_HD),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CtPWM_Handler_PWM_SET),
  NULL_PTR
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Alarm_Lcfg.c
 *********************************************************************************************************************/
