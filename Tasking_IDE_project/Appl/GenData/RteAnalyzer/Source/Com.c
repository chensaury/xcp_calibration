/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Com.c
 *        Config:  Bsw_Project.dpa
 *    BSW Module:  Com
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  C-Code implementation template for BSW Module <Com>
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

#include "SchM_Com.h"
#include "TSC_SchM_Com.h"


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


#define COM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Schedulable Entity Name: Com_MainFunctionRx
 *
 *********************************************************************************************************************/

FUNC(void, COM_CODE) Com_MainFunctionRx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Com_MainFunctionRx
 *********************************************************************************************************************/

  TSC_Com_SchM_Enter_Com_COM_EXCLUSIVE_AREA_BOTH();
  TSC_Com_SchM_Exit_Com_COM_EXCLUSIVE_AREA_BOTH();
  TSC_Com_SchM_Enter_Com_COM_EXCLUSIVE_AREA_RX();
  TSC_Com_SchM_Exit_Com_COM_EXCLUSIVE_AREA_RX();
  TSC_Com_SchM_Enter_Com_COM_EXCLUSIVE_AREA_TX();
  TSC_Com_SchM_Exit_Com_COM_EXCLUSIVE_AREA_TX();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Schedulable Entity Name: Com_MainFunctionTx
 *
 *********************************************************************************************************************/

FUNC(void, COM_CODE) Com_MainFunctionTx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Com_MainFunctionTx
 *********************************************************************************************************************/

  TSC_Com_SchM_Enter_Com_COM_EXCLUSIVE_AREA_BOTH();
  TSC_Com_SchM_Exit_Com_COM_EXCLUSIVE_AREA_BOTH();
  TSC_Com_SchM_Enter_Com_COM_EXCLUSIVE_AREA_RX();
  TSC_Com_SchM_Exit_Com_COM_EXCLUSIVE_AREA_RX();
  TSC_Com_SchM_Enter_Com_COM_EXCLUSIVE_AREA_TX();
  TSC_Com_SchM_Exit_Com_COM_EXCLUSIVE_AREA_TX();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define COM_STOP_SEC_CODE
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
