/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BswM.c
 *        Config:  Bsw_Project.dpa
 *     SW-C Type:  BswM
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  C-Code implementation template for SW-C <BswM>
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
 * BswM_ESH_Mode
 *   
 *
 * BswM_ESH_RunRequest
 *   
 *
 *********************************************************************************************************************/

#include "Rte_BswM.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_BswM.h"
#include "SchM_BswM.h"
#include "TSC_SchM_BswM.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void BswM_TestDefines(void);

typedef P2FUNC(Std_ReturnType, RTE_CODE, FncPtrType)(void); /* PRQA S 3448 */ /* MD_Rte_TestCode */


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
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * BswM_ESH_Mode: Enumeration of integer in interval [0...255] with enumerators
 *   STARTUP (0U)
 *   RUN (1U)
 *   POSTRUN (2U)
 *   WAKEUP (3U)
 *   SHUTDOWN (4U)
 * BswM_ESH_RunRequest: Enumeration of integer in interval [0...255] with enumerators
 *   RELEASED (0U)
 *   REQUESTED (1U)
 *
 *********************************************************************************************************************/


#define BswM_START_SEC_CODE
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BswM_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Request_ESH_PostRunRequest_0_requestedMode(BswM_ESH_RunRequest *data)
 *   Std_ReturnType Rte_Read_Request_ESH_PostRunRequest_1_requestedMode(BswM_ESH_RunRequest *data)
 *   Std_ReturnType Rte_Read_Request_ESH_RunRequest_0_requestedMode(BswM_ESH_RunRequest *data)
 *   Std_ReturnType Rte_Read_Request_ESH_RunRequest_1_requestedMode(BswM_ESH_RunRequest *data)
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode(BswM_ESH_Mode mode)
 *   Modes of Rte_ModeType_ESH_Mode:
 *   - RTE_MODE_ESH_Mode_POSTRUN
 *   - RTE_MODE_ESH_Mode_RUN
 *   - RTE_MODE_ESH_Mode_SHUTDOWN
 *   - RTE_MODE_ESH_Mode_STARTUP
 *   - RTE_MODE_ESH_Mode_WAKEUP
 *   - RTE_TRANSITION_ESH_Mode
 *   BswM_ESH_Mode Rte_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode(void)
 *   Modes of Rte_ModeType_ESH_Mode:
 *   - RTE_MODE_ESH_Mode_POSTRUN
 *   - RTE_MODE_ESH_Mode_RUN
 *   - RTE_MODE_ESH_Mode_SHUTDOWN
 *   - RTE_MODE_ESH_Mode_STARTUP
 *   - RTE_MODE_ESH_Mode_WAKEUP
 *   - RTE_TRANSITION_ESH_Mode
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BswM_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BswM_CODE) BswM_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BswM_MainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  BswM_ESH_RunRequest Read_Request_ESH_PostRunRequest_0_requestedMode;
  BswM_ESH_RunRequest Read_Request_ESH_PostRunRequest_1_requestedMode;
  BswM_ESH_RunRequest Read_Request_ESH_RunRequest_0_requestedMode;
  BswM_ESH_RunRequest Read_Request_ESH_RunRequest_1_requestedMode;

  Rte_ModeType_ESH_Mode Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode;

  /**********************************************************
  * Direct Function Accesses and Take Addresses of Functions
  **********************************************************/

  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Read_Request_ESH_PostRunRequest_0_requestedMode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_BswM_Rte_Read_Request_ESH_PostRunRequest_0_requestedMode(&Read_Request_ESH_PostRunRequest_0_requestedMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Read_Request_ESH_PostRunRequest_1_requestedMode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_BswM_Rte_Read_Request_ESH_PostRunRequest_1_requestedMode(&Read_Request_ESH_PostRunRequest_1_requestedMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Read_Request_ESH_RunRequest_0_requestedMode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_BswM_Rte_Read_Request_ESH_RunRequest_0_requestedMode(&Read_Request_ESH_RunRequest_0_requestedMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Read_Request_ESH_RunRequest_1_requestedMode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_BswM_Rte_Read_Request_ESH_RunRequest_1_requestedMode(&Read_Request_ESH_RunRequest_1_requestedMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Switch_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_BswM_Rte_Switch_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode(RTE_MODE_ESH_Mode_STARTUP);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode = TSC_BswM_Rte_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode();

  TSC_BswM_SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0();
  TSC_BswM_SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0();

  BswM_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BswM_STOP_SEC_CODE
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void BswM_TestDefines(void)
{
  /* Enumeration Data Types */

  BswM_ESH_Mode Test_BswM_ESH_Mode_V_1 = STARTUP;
  BswM_ESH_Mode Test_BswM_ESH_Mode_V_2 = RUN;
  BswM_ESH_Mode Test_BswM_ESH_Mode_V_3 = POSTRUN;
  BswM_ESH_Mode Test_BswM_ESH_Mode_V_4 = WAKEUP;
  BswM_ESH_Mode Test_BswM_ESH_Mode_V_5 = SHUTDOWN;

  BswM_ESH_RunRequest Test_BswM_ESH_RunRequest_V_1 = RELEASED;
  BswM_ESH_RunRequest Test_BswM_ESH_RunRequest_V_2 = REQUESTED;

  /* Modes */

  BswM_ESH_Mode Test_ESH_Mode_MV_1 = RTE_MODE_ESH_Mode_POSTRUN;
  BswM_ESH_Mode Test_ESH_Mode_MV_2 = RTE_MODE_ESH_Mode_RUN;
  BswM_ESH_Mode Test_ESH_Mode_MV_3 = RTE_MODE_ESH_Mode_SHUTDOWN;
  BswM_ESH_Mode Test_ESH_Mode_MV_4 = RTE_MODE_ESH_Mode_STARTUP;
  BswM_ESH_Mode Test_ESH_Mode_MV_5 = RTE_MODE_ESH_Mode_WAKEUP;
  BswM_ESH_Mode Test_ESH_Mode_TV = RTE_TRANSITION_ESH_Mode;

  BswM_ESH_RunRequest Test_ESH_RunRequest_MV_1 = RTE_MODE_ESH_RunRequest_RELEASED;
  BswM_ESH_RunRequest Test_ESH_RunRequest_MV_2 = RTE_MODE_ESH_RunRequest_REQUESTED;
  BswM_ESH_RunRequest Test_ESH_RunRequest_TV = RTE_TRANSITION_ESH_RunRequest;
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
