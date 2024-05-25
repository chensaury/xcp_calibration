/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Os_OsCore0_swc.c
 *        Config:  Bsw_Project.dpa
 *     SW-C Type:  Os_OsCore0_swc
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  C-Code implementation template for SW-C <Os_OsCore0_swc>
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
 * TimeInMicrosecondsType
 *   
 *
 *
 * Operation Prototypes:
 * =====================
 * GetCounterValue of Port Interface Os_Service
 *   
 *
 * GetElapsedValue of Port Interface Os_Service
 *   
 *
 *********************************************************************************************************************/

#include "Rte_Os_OsCore0_swc.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_Os_OsCore0_swc.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"


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
 * CounterType: Integer in interval [0...255]
 * TimeInMicrosecondsType: Integer in interval [0...4294967295]
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 *********************************************************************************************************************/


#define Os_OsCore0_swc_START_SEC_CODE
#include "Os_OsCore0_swc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetCounterValue
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetCounterValue> of PortPrototype <OsService_SystemTimer0>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType GetCounterValue(TimeInMicrosecondsType *Value)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Os_Service_E_OK
 *   RTE_E_Os_Service_E_OS_ID
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetCounterValue_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Os_OsCore0_swc_CODE) TSC_Inline_Os_OsCore1_swc_GetCounterValue(CounterType parg0, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_OS_OSCORE0_SWC_APPL_VAR) Value);
FUNC(Std_ReturnType, Os_OsCore0_swc_CODE) TSC_Inline_Os_OsCore2_swc_GetCounterValue(CounterType parg0, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_OS_OSCORE0_SWC_APPL_VAR) Value);
FUNC(Std_ReturnType, Os_OsCore0_swc_CODE) TSC_Inline_Os_OsCore3_swc_GetCounterValue(CounterType parg0, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_OS_OSCORE0_SWC_APPL_VAR) Value);
FUNC(Std_ReturnType, Os_OsCore0_swc_CODE) TSC_Inline_Os_OsCore4_swc_GetCounterValue(CounterType parg0, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_OS_OSCORE0_SWC_APPL_VAR) Value);
FUNC(Std_ReturnType, Os_OsCore0_swc_CODE) TSC_Inline_Os_OsCore5_swc_GetCounterValue(CounterType parg0, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_OS_OSCORE0_SWC_APPL_VAR) Value);
FUNC(Std_ReturnType, Os_OsCore0_swc_CODE) GetCounterValue(CounterType parg0, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_OS_OSCORE0_SWC_APPL_VAR) Value) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: GetCounterValue (returns application error)
 *********************************************************************************************************************/

  TSC_Inline_Os_OsCore1_swc_GetCounterValue(
    parg0,
    Value
  );
  TSC_Inline_Os_OsCore2_swc_GetCounterValue(
    parg0,
    Value
  );
  TSC_Inline_Os_OsCore3_swc_GetCounterValue(
    parg0,
    Value
  );
  TSC_Inline_Os_OsCore4_swc_GetCounterValue(
    parg0,
    Value
  );
  TSC_Inline_Os_OsCore5_swc_GetCounterValue(
    parg0,
    Value
  );
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetElapsedValue
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetElapsedValue> of PortPrototype <OsService_SystemTimer0>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType GetElapsedValue(TimeInMicrosecondsType *Value, TimeInMicrosecondsType *ElapsedValue)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Os_Service_E_OK
 *   RTE_E_Os_Service_E_OS_ID
 *   RTE_E_Os_Service_E_OS_VALUE
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetElapsedValue_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Os_OsCore0_swc_CODE) TSC_Inline_Os_OsCore1_swc_GetElapsedValue(CounterType parg0, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_OS_OSCORE0_SWC_APPL_VAR) Value, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_OS_OSCORE0_SWC_APPL_VAR) ElapsedValue);
FUNC(Std_ReturnType, Os_OsCore0_swc_CODE) TSC_Inline_Os_OsCore2_swc_GetElapsedValue(CounterType parg0, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_OS_OSCORE0_SWC_APPL_VAR) Value, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_OS_OSCORE0_SWC_APPL_VAR) ElapsedValue);
FUNC(Std_ReturnType, Os_OsCore0_swc_CODE) TSC_Inline_Os_OsCore3_swc_GetElapsedValue(CounterType parg0, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_OS_OSCORE0_SWC_APPL_VAR) Value, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_OS_OSCORE0_SWC_APPL_VAR) ElapsedValue);
FUNC(Std_ReturnType, Os_OsCore0_swc_CODE) TSC_Inline_Os_OsCore4_swc_GetElapsedValue(CounterType parg0, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_OS_OSCORE0_SWC_APPL_VAR) Value, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_OS_OSCORE0_SWC_APPL_VAR) ElapsedValue);
FUNC(Std_ReturnType, Os_OsCore0_swc_CODE) TSC_Inline_Os_OsCore5_swc_GetElapsedValue(CounterType parg0, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_OS_OSCORE0_SWC_APPL_VAR) Value, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_OS_OSCORE0_SWC_APPL_VAR) ElapsedValue);
FUNC(Std_ReturnType, Os_OsCore0_swc_CODE) GetElapsedValue(CounterType parg0, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_OS_OSCORE0_SWC_APPL_VAR) Value, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_OS_OSCORE0_SWC_APPL_VAR) ElapsedValue) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: GetElapsedValue (returns application error)
 *********************************************************************************************************************/

  TSC_Inline_Os_OsCore1_swc_GetElapsedValue(
    parg0,
    Value,
    ElapsedValue
  );
  TSC_Inline_Os_OsCore2_swc_GetElapsedValue(
    parg0,
    Value,
    ElapsedValue
  );
  TSC_Inline_Os_OsCore3_swc_GetElapsedValue(
    parg0,
    Value,
    ElapsedValue
  );
  TSC_Inline_Os_OsCore4_swc_GetElapsedValue(
    parg0,
    Value,
    ElapsedValue
  );
  TSC_Inline_Os_OsCore5_swc_GetElapsedValue(
    parg0,
    Value,
    ElapsedValue
  );
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Os_OsCore0_swc_STOP_SEC_CODE
#include "Os_OsCore0_swc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


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
