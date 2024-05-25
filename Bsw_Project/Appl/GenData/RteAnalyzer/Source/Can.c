/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Can.c
 *        Config:  Bsw_Project.dpa
 *    BSW Module:  Can
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  C-Code implementation template for BSW Module <Can>
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

#include "SchM_Can.h"
#include "TSC_SchM_Can.h"


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
 * ComM_InhibitionStatusType: Integer in interval [0...255]
 * ComM_UserHandleType: Integer in interval [0...255]
 * CounterType: Integer in interval [0...255]
 * EcuM_TimeType: Integer in interval [0...4294967295]
 * EcuM_UserType: Integer in interval [0...255]
 * NetworkHandleType: Integer in interval [0...255]
 * TimeInMicrosecondsType: Integer in interval [0...4294967295]
 * boolean: Boolean (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * BswM_ESH_Mode: Enumeration of integer in interval [0...255] with enumerators
 * BswM_ESH_RunRequest: Enumeration of integer in interval [0...255] with enumerators
 * ComM_ModeType: Enumeration of integer in interval [0...3] with enumerators
 * EcuM_BootTargetType: Enumeration of integer in interval [0...2] with enumerators
 * EcuM_ModeType: Enumeration of integer in interval [0...3] with enumerators
 * EcuM_ShutdownCauseType: Enumeration of integer in interval [0...3] with enumerators
 * EcuM_StateType: Enumeration of integer in interval [0...144] with enumerators
 *
 *********************************************************************************************************************/


#define CAN_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Schedulable Entity Name: Can_MainFunction_BusOff
 *
 *********************************************************************************************************************/

FUNC(void, CAN_CODE) Can_MainFunction_BusOff(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Can_MainFunction_BusOff
 *********************************************************************************************************************/

  TSC_Can_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
  TSC_Can_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
  TSC_Can_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_1();
  TSC_Can_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_1();
  TSC_Can_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_2();
  TSC_Can_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_2();
  TSC_Can_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_3();
  TSC_Can_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_3();
  TSC_Can_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_4();
  TSC_Can_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_4();
  TSC_Can_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_5();
  TSC_Can_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_5();
  TSC_Can_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_6();
  TSC_Can_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_6();
  TSC_Can_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_7();
  TSC_Can_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_7();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Schedulable Entity Name: Can_MainFunction_Mode
 *
 *********************************************************************************************************************/

FUNC(void, CAN_CODE) Can_MainFunction_Mode(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Can_MainFunction_Mode
 *********************************************************************************************************************/

  TSC_Can_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
  TSC_Can_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
  TSC_Can_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_1();
  TSC_Can_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_1();
  TSC_Can_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_2();
  TSC_Can_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_2();
  TSC_Can_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_3();
  TSC_Can_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_3();
  TSC_Can_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_4();
  TSC_Can_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_4();
  TSC_Can_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_5();
  TSC_Can_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_5();
  TSC_Can_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_6();
  TSC_Can_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_6();
  TSC_Can_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_7();
  TSC_Can_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_7();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Schedulable Entity Name: Can_MainFunction_Wakeup
 *
 *********************************************************************************************************************/

FUNC(void, CAN_CODE) Can_MainFunction_Wakeup(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Can_MainFunction_Wakeup
 *********************************************************************************************************************/

  TSC_Can_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
  TSC_Can_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
  TSC_Can_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_1();
  TSC_Can_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_1();
  TSC_Can_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_2();
  TSC_Can_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_2();
  TSC_Can_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_3();
  TSC_Can_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_3();
  TSC_Can_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_4();
  TSC_Can_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_4();
  TSC_Can_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_5();
  TSC_Can_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_5();
  TSC_Can_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_6();
  TSC_Can_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_6();
  TSC_Can_SchM_Enter_Can_CAN_EXCLUSIVE_AREA_7();
  TSC_Can_SchM_Exit_Can_CAN_EXCLUSIVE_AREA_7();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CAN_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
