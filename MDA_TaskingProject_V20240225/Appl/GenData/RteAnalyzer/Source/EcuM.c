/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  EcuM.c
 *        Config:  Bsw_Project.dpa
 *     SW-C Type:  EcuM
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  C-Code implementation template for SW-C <EcuM>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3197 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3198 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3199 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3201 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3453 EOF */ /* MD_Rte_TestCode */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * EcuM_BootTargetType
 *   
 *
 * EcuM_ModeType
 *   
 *
 * EcuM_ShutdownCauseType
 *   
 *
 * EcuM_StateType
 *   
 *
 * EcuM_TimeType
 *   
 *
 * EcuM_UserType
 *   
 *
 *
 * Operation Prototypes:
 * =====================
 * GetBootTarget of Port Interface EcuM_BootTarget
 *   
 *
 * SelectBootTarget of Port Interface EcuM_BootTarget
 *   
 *
 * GetLastShutdownTarget of Port Interface EcuM_ShutdownTarget
 *   
 *
 * GetShutdownCause of Port Interface EcuM_ShutdownTarget
 *   
 *
 * GetShutdownTarget of Port Interface EcuM_ShutdownTarget
 *   
 *
 * SelectShutdownCause of Port Interface EcuM_ShutdownTarget
 *   
 *
 * SelectShutdownTarget of Port Interface EcuM_ShutdownTarget
 *   
 *
 *********************************************************************************************************************/

#include "Rte_EcuM.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_EcuM.h"
#include "SchM_EcuM.h"
#include "TSC_SchM_EcuM.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void EcuM_TestDefines(void);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * EcuM_TimeType: Integer in interval [0...4294967295]
 * EcuM_UserType: Integer in interval [0...255]
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * EcuM_BootTargetType: Enumeration of integer in interval [0...2] with enumerators
 *   ECUM_BOOT_TARGET_APP (0U)
 *   ECUM_BOOT_TARGET_OEM_BOOTLOADER (1U)
 *   ECUM_BOOT_TARGET_SYS_BOOTLOADER (2U)
 * EcuM_ModeType: Enumeration of integer in interval [0...3] with enumerators
 *   EcuMConf_EcuMResetMode_ECUM_RESET_IO (2U)
 *   EcuMConf_EcuMResetMode_ECUM_RESET_MCU (0U)
 *   EcuMConf_EcuMResetMode_ECUM_RESET_WAKEUP (3U)
 *   EcuMConf_EcuMResetMode_ECUM_RESET_WDG (1U)
 * EcuM_ShutdownCauseType: Enumeration of integer in interval [0...3] with enumerators
 *   EcuMConf_EcuMShutdownCause_ECUM_CAUSE_UNKNOWN (0U)
 *   EcuMConf_EcuMShutdownCause_ECUM_CAUSE_DCM (3U)
 *   EcuMConf_EcuMShutdownCause_ECUM_CAUSE_ECU_STATE (1U)
 *   EcuMConf_EcuMShutdownCause_ECUM_CAUSE_WDGM (2U)
 * EcuM_StateType: Enumeration of integer in interval [0...144] with enumerators
 *   ECUM_STATE_SLEEP (80U)
 *   ECUM_STATE_OFF (128U)
 *   ECUM_STATE_RESET (144U)
 *
 *********************************************************************************************************************/


#define EcuM_START_SEC_CODE
#include "EcuM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EcuM_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EcuM_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, EcuM_CODE) EcuM_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EcuM_MainFunction
 *********************************************************************************************************************/

  TSC_EcuM_SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_0();
  TSC_EcuM_SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_0();
  TSC_EcuM_SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_1();
  TSC_EcuM_SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_1();
  TSC_EcuM_SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_2();
  TSC_EcuM_SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_2();

  EcuM_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetBootTarget
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetBootTarget> of PortPrototype <EcuM_BootTarget>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType EcuM_GetBootTarget(EcuM_BootTargetType *BootTarget)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_EcuM_BootTarget_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetBootTarget_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, EcuM_CODE) EcuM_GetBootTarget(P2VAR(EcuM_BootTargetType, AUTOMATIC, RTE_ECUM_APPL_VAR) BootTarget) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EcuM_GetBootTarget (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetLastShutdownTarget
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetLastShutdownTarget> of PortPrototype <EcuM_ShutdownTarget>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType EcuM_GetLastShutdownTarget(EcuM_StateType *target, EcuM_ModeType *resetSleepMode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_EcuM_ShutdownTarget_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetLastShutdownTarget_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, EcuM_CODE) EcuM_GetLastShutdownTarget(P2VAR(EcuM_StateType, AUTOMATIC, RTE_ECUM_APPL_VAR) target, P2VAR(EcuM_ModeType, AUTOMATIC, RTE_ECUM_APPL_VAR) resetSleepMode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EcuM_GetLastShutdownTarget (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetShutdownCause
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetShutdownCause> of PortPrototype <EcuM_ShutdownTarget>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType EcuM_GetShutdownCause(EcuM_ShutdownCauseType *shutdownCause)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_EcuM_ShutdownTarget_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetShutdownCause_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, EcuM_CODE) EcuM_GetShutdownCause(P2VAR(EcuM_ShutdownCauseType, AUTOMATIC, RTE_ECUM_APPL_VAR) shutdownCause) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EcuM_GetShutdownCause (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetShutdownTarget
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetShutdownTarget> of PortPrototype <EcuM_ShutdownTarget>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType EcuM_GetShutdownTarget(EcuM_StateType *target, EcuM_ModeType *resetSleepMode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_EcuM_ShutdownTarget_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetShutdownTarget_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, EcuM_CODE) EcuM_GetShutdownTarget(P2VAR(EcuM_StateType, AUTOMATIC, RTE_ECUM_APPL_VAR) target, P2VAR(EcuM_ModeType, AUTOMATIC, RTE_ECUM_APPL_VAR) resetSleepMode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EcuM_GetShutdownTarget (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SelectBootTarget
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SelectBootTarget> of PortPrototype <EcuM_BootTarget>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType EcuM_SelectBootTarget(EcuM_BootTargetType BootTarget)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_EcuM_BootTarget_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SelectBootTarget_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, EcuM_CODE) EcuM_SelectBootTarget(EcuM_BootTargetType BootTarget) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EcuM_SelectBootTarget (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SelectShutdownCause
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SelectShutdownCause> of PortPrototype <EcuM_ShutdownTarget>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType EcuM_SelectShutdownCause(EcuM_ShutdownCauseType shutdownCause)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_EcuM_ShutdownTarget_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SelectShutdownCause_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, EcuM_CODE) EcuM_SelectShutdownCause(EcuM_ShutdownCauseType shutdownCause) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EcuM_SelectShutdownCause (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SelectShutdownTarget
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SelectShutdownTarget> of PortPrototype <EcuM_ShutdownTarget>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType EcuM_SelectShutdownTarget(EcuM_StateType targetState, EcuM_ModeType resetSleepMode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_EcuM_ShutdownTarget_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SelectShutdownTarget_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, EcuM_CODE) EcuM_SelectShutdownTarget(EcuM_StateType targetState, EcuM_ModeType resetSleepMode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EcuM_SelectShutdownTarget (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define EcuM_STOP_SEC_CODE
#include "EcuM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void EcuM_TestDefines(void)
{
  /* Enumeration Data Types */

  EcuM_BootTargetType Test_EcuM_BootTargetType_V_1 = ECUM_BOOT_TARGET_APP;
  EcuM_BootTargetType Test_EcuM_BootTargetType_V_2 = ECUM_BOOT_TARGET_OEM_BOOTLOADER;
  EcuM_BootTargetType Test_EcuM_BootTargetType_V_3 = ECUM_BOOT_TARGET_SYS_BOOTLOADER;

  EcuM_ModeType Test_EcuM_ModeType_V_1 = EcuMConf_EcuMResetMode_ECUM_RESET_IO;
  EcuM_ModeType Test_EcuM_ModeType_V_2 = EcuMConf_EcuMResetMode_ECUM_RESET_MCU;
  EcuM_ModeType Test_EcuM_ModeType_V_3 = EcuMConf_EcuMResetMode_ECUM_RESET_WAKEUP;
  EcuM_ModeType Test_EcuM_ModeType_V_4 = EcuMConf_EcuMResetMode_ECUM_RESET_WDG;

  EcuM_ShutdownCauseType Test_EcuM_ShutdownCauseType_V_1 = EcuMConf_EcuMShutdownCause_ECUM_CAUSE_UNKNOWN;
  EcuM_ShutdownCauseType Test_EcuM_ShutdownCauseType_V_2 = EcuMConf_EcuMShutdownCause_ECUM_CAUSE_DCM;
  EcuM_ShutdownCauseType Test_EcuM_ShutdownCauseType_V_3 = EcuMConf_EcuMShutdownCause_ECUM_CAUSE_ECU_STATE;
  EcuM_ShutdownCauseType Test_EcuM_ShutdownCauseType_V_4 = EcuMConf_EcuMShutdownCause_ECUM_CAUSE_WDGM;

  EcuM_StateType Test_EcuM_StateType_V_1 = ECUM_STATE_SLEEP;
  EcuM_StateType Test_EcuM_StateType_V_2 = ECUM_STATE_OFF;
  EcuM_StateType Test_EcuM_StateType_V_3 = ECUM_STATE_RESET;
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_TestCode:
     Reason:     This justification is used within the generated test code by the Rte Analyzer.
     Risk:       No functional risk.
     Prevention: Not required.

*/
