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
 *            Module: BswM
 *           Program: MSR_Vector_SLP4
 *          Customer: Aptiv (China) Technology Company Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Aurix 2G/TC397 B-Step
 *    License Scope : The usage is restricted to CBD1900078_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: BswM_Lcfg.c
 *   Generation Time: 2024-01-08 16:27:34
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

#define BSWM_LCFG_SOURCE

/* -----------------------------------------------------------------------------
    &&&~ INCLUDE
 ----------------------------------------------------------------------------- */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
#include "BswM.h"
#include "BswM_Private_Cfg.h"
#include "SchM_BswM.h"

#if !defined (BSWM_LOCAL)
# define BSWM_LOCAL static
#endif

#if !defined (BSWM_LOCAL_INLINE) /* COV_BSWM_LOCAL_INLINE */
# define BSWM_LOCAL_INLINE LOCAL_INLINE
#endif

/* -----------------------------------------------------------------------------
    &&&~ MACROS
 ----------------------------------------------------------------------------- */
/* PRQA S 3453 1 */ /* MD_BswM_3453 */
#define BswM_SetIpduGroup(pduId, bitVal) Com_SetIpduGroup(BswM_ComIPduGroupState, (pduId), (bitVal))
#define BswM_SetIpduReinitGroup(pduId, bitVal)
/* PRQA S 3453 1 */ /* MD_BswM_3453 */
#define BswM_SetIpduDMGroup(pduId, bitVal) Com_SetIpduGroup(BswM_ComRxIPduGroupDMState, (pduId), (bitVal))

/* PRQA S 3453 1 */ /* MD_BswM_3453 */
#define BswM_MarkPduGroupControlInvocation(control) BswM_PduGroupControlInvocation |= (control)
#define BswM_MarkDmControlInvocation() BswM_PduGroupControlInvocation |= BSWM_GROUPCONTROL_DM



#define BSWM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ LOCAL FUNCTION DECLARATIONS
 ----------------------------------------------------------------------------- */
/**********************************************************************************************************************
 *  BswM_Action_RuleHandler()
 **********************************************************************************************************************/
/*!
 * \brief       Executes a rule.
 * \details     Arbitrates a rule and executes corresponding action list.
 * \param[in]   handleId  Id of the rule to execute.
 * \return      E_OK      No action list was executed or corresponding action list was completely executed.
 * \return      E_NOT_OK  Action list was aborted because an action failed.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_RuleHandler(BswM_HandleType handleId);

/**********************************************************************************************************************
 *  BswM_UpdateRuleStates()
 **********************************************************************************************************************/
/*!
 * \brief       Updates the state of a rule.
 * \details     Set rule state of passed ruleId to passed state.
 * \param[in]   ruleId    Id of the rule to update.
 * \param[in]   state     New state of the rule.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateRuleStates(BswM_SizeOfRuleStatesType ruleId, BswM_RuleStatesType state);

/**********************************************************************************************************************
 *  BswM_UpdateTimer()
 **********************************************************************************************************************/
/*!
 * \brief       Updates a timer.
 * \details     Set timer value of passed timerId to passed value and calculates the new state.
 * \param[in]   timerId   Id of the timer to update.
 * \param[in]   value     New value of the timer.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateTimer(BswM_SizeOfTimerValueType timerId, BswM_TimerValueType value);

/*! \addtogroup    BswMGeneratedFunctions BswM Generated Functions
 * \{
 */
/* PRQA S 0779 FUNCTIONDECLARATIONS */ /* MD_BswM_0779 */

/**********************************************************************************************************************
 *  BswMActionListFunctions
 *********************************************************************************************************************/
/*! \defgroup    BswMActionListFunctions
 * \{
 */

/*!
 * \{
 * \brief       Execute actions of action list.
 * \details     Generated function which depends on the configuration. Executes the actions of the action list in the
 *              configured order.
 * \return      E_OK      Action list was completely executed.
 * \return      E_NOT_OK  Action list was aborted because an action failed.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_ExitRun(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_RunToPostRun(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_WaitForNvMToShutdown(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_WakeupToPrep(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_WaitForNvMWakeup(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_WakeupToRun(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_ESH_PostRunToPrepCheck(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_ExitPostRun(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_PrepShutdownToWaitForNvM(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_INIT_AL_Initialize(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_RX_Disable(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_TX_Disable(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_TX_EnableNoinit(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_Disable_DM(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_Enable_DM(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_CAN00_8c3ac689_RX_Disable(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_CAN00_8c3ac689_Disable_DM(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_CAN00_8c3ac689_Enable_DM(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_Disable(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_EnableNoinit(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_Disable_DM(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_Enable_DM(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_TX_Disable(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_TX_EnableNoinit(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX_Disable(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX_EnableNoinit(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_Disable_DM(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_Enable_DM(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_Disable(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_EnableNoinit(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_Disable_DM(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_Enable_DM(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_Disable_DM(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_Enable_DM(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX_Disable(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX_EnableNoinit(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_Disable(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_EnableNoinit(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_Disable(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_EnableNoinit(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX_Disable(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX_EnableNoinit(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_RX_EnableNoinit(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_CAN00_8c3ac689_RX_EnableNoinit(void);
/*! \} */ /* End of sharing description for BswMActionListFunctions */
#define BswM_ActionList_ESH_AL_PostRunToPrepShutdown BswM_ActionList_ESH_AL_WakeupToPrep
#define BswM_ActionList_ESH_AL_InitToWakeup BswM_ActionList_ESH_AL_WaitForNvMWakeup
#define BswM_ActionList_ESH_AL_PostRunToRun BswM_ActionList_ESH_AL_WakeupToRun
/*! \} */ /* End of group BswMActionListFunctions */

/**********************************************************************************************************************
 *  BswMRuleFunctions
 *********************************************************************************************************************/
/*! \defgroup    BswMRuleFunctions
 * \{
 */

/*!
 * \{
 * \brief       Arbitrates the configured rule.
 * \details     Generated function which depends on the configuration. Arbitrates the rule and returns the action list
 *              which shall be executed.
 * \return      ID of action list to execute (BSWM_NO_ACTIONLIST if no ActionList shall be executed)
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_RunToPostRun(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_RunToPostRunNested(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_WaitToShutdown(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_WakeupToPrep(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_WaitToWakeup(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_WakeupToRun(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_InitToWakeup(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_PostRunToPrepNested(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_PostRunNested(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_PostRun(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_PrepToWait(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MDA_CANFD_c149c45e_RX(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MDA_CANFD_c149c45e_RX_DM(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_CAN00_8c3ac689_RX(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_CAN00_8c3ac689_RX_DM(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_RX(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_DM(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_TX(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_DM(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_DM(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_DM(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MDA_CANFD_c149c45e_TX(void);
/*! \} */ /* End of sharing description for BswMRuleFunctions */
/*! \} */ /* End of group BswMRuleFunctions */
/* PRQA L:FUNCTIONDECLARATIONS */
/*! \} */ /* End of group BswMGeneratedFunctions */

#define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


/* -----------------------------------------------------------------------------
    &&&~ LOCAL VARIABLE DECLARATIONS
 ----------------------------------------------------------------------------- */

/* PRQA S 0779 VARIABLEDECLARATIONS */ /* MD_BswM_0779 */ 

#define BSWM_START_SEC_VAR_NOINIT_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

BSWM_LOCAL VAR(uint8, BSWM_VAR_NOINIT) BswM_PduGroupControlInvocation;

#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

#define BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


BSWM_LOCAL VAR(Rte_ModeType_ESH_Mode, BSWM_VAR_NOINIT) BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode;

BSWM_LOCAL VAR(BswM_ESH_RunRequest, BSWM_VAR_NOINIT) Request_ESH_RunRequest_0_requestedMode;
BSWM_LOCAL VAR(BswM_ESH_RunRequest, BSWM_VAR_NOINIT) Request_ESH_RunRequest_1_requestedMode;
BSWM_LOCAL VAR(BswM_ESH_RunRequest, BSWM_VAR_NOINIT) Request_ESH_PostRunRequest_0_requestedMode;
BSWM_LOCAL VAR(BswM_ESH_RunRequest, BSWM_VAR_NOINIT) Request_ESH_PostRunRequest_1_requestedMode;
BSWM_LOCAL VAR(Rte_ModeType_ESH_Mode, BSWM_VAR_NOINIT) BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode;


/* PRQA S 3218 3 */ /* MD_BswM_3218 */
BSWM_LOCAL VAR(Com_IpduGroupVector, BSWM_VAR_NOINIT) BswM_ComIPduGroupState;
BSWM_LOCAL VAR(Com_IpduGroupVector, BSWM_VAR_NOINIT) BswM_ComRxIPduGroupDMState;

#define BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* PRQA L:VARIABLEDECLARATIONS */

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/



/**********************************************************************************************************************
 *  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
**********************************************************************************************************************/
/* PRQA S 0310 GLOBALDATADECLARATIONS */ /* MD_BswM_0310 */ 
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  BswM_ActionLists
**********************************************************************************************************************/
/** 
  \var    BswM_ActionLists
  \details
  Element    Description
  FctPtr     Pointer to the array list function.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(BswM_ActionListsType, BSWM_CONST) BswM_ActionLists[47] = {
    /* Index    FctPtr                                                                            Comment                   Referable Keys */
  { /*     0 */ BswM_ActionList_ESH_AL_ExitRun                                             },  /* [Priority: 0] */  /* [AL_ESH_AL_ExitRun] */
  { /*     1 */ BswM_ActionList_ESH_AL_RunToPostRun                                        },  /* [Priority: 0] */  /* [AL_ESH_AL_RunToPostRun] */
  { /*     2 */ BswM_ActionList_ESH_AL_WaitForNvMToShutdown                                },  /* [Priority: 0] */  /* [AL_ESH_AL_WaitForNvMToShutdown] */
  { /*     3 */ BswM_ActionList_ESH_AL_WakeupToPrep                                        },  /* [Priority: 0] */  /* [AL_ESH_AL_WakeupToPrep] */
  { /*     4 */ BswM_ActionList_ESH_AL_WaitForNvMWakeup                                    },  /* [Priority: 0] */  /* [AL_ESH_AL_WaitForNvMWakeup] */
  { /*     5 */ BswM_ActionList_ESH_AL_WakeupToRun                                         },  /* [Priority: 0] */  /* [AL_ESH_AL_WakeupToRun] */
  { /*     6 */ BswM_ActionList_ESH_AL_InitToWakeup                                        },  /* [Priority: 0] */  /* [AL_ESH_AL_InitToWakeup] */
  { /*     7 */ BswM_ActionList_ESH_AL_PostRunToPrepShutdown                               },  /* [Priority: 0] */  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  { /*     8 */ BswM_ActionList_ESH_AL_ESH_PostRunToPrepCheck                              },  /* [Priority: 0] */  /* [AL_ESH_AL_ESH_PostRunToPrepCheck] */
  { /*     9 */ BswM_ActionList_ESH_AL_PostRunToRun                                        },  /* [Priority: 0] */  /* [AL_ESH_AL_PostRunToRun] */
  { /*    10 */ BswM_ActionList_ESH_AL_ExitPostRun                                         },  /* [Priority: 0] */  /* [AL_ESH_AL_ExitPostRun] */
  { /*    11 */ BswM_ActionList_ESH_AL_PrepShutdownToWaitForNvM                            },  /* [Priority: 0] */  /* [AL_ESH_AL_PrepShutdownToWaitForNvM] */
  { /*    12 */ BswM_ActionList_INIT_AL_Initialize                                         },  /* [Priority: 0] */  /* [AL_INIT_AL_Initialize] */
  { /*    13 */ BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_RX_Disable          },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_RX_Disable] */
  { /*    14 */ BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_TX_Disable          },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_TX_Disable] */
  { /*    15 */ BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_TX_EnableNoinit     },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_TX_EnableNoinit] */
  { /*    16 */ BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_Disable_DM          },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_Disable_DM] */
  { /*    17 */ BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_Enable_DM           },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_Enable_DM] */
  { /*    18 */ BswM_ActionList_CC_AL_CN_CAN00_8c3ac689_RX_Disable                         },  /* [Priority: 0] */  /* [AL_CC_AL_CN_CAN00_8c3ac689_RX_Disable] */
  { /*    19 */ BswM_ActionList_CC_AL_CN_CAN00_8c3ac689_Disable_DM                         },  /* [Priority: 0] */  /* [AL_CC_AL_CN_CAN00_8c3ac689_Disable_DM] */
  { /*    20 */ BswM_ActionList_CC_AL_CN_CAN00_8c3ac689_Enable_DM                          },  /* [Priority: 0] */  /* [AL_CC_AL_CN_CAN00_8c3ac689_Enable_DM] */
  { /*    21 */ BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_Disable      },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_Disable] */
  { /*    22 */ BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_EnableNoinit },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_EnableNoinit] */
  { /*    23 */ BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_Disable_DM      },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_Disable_DM] */
  { /*    24 */ BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_Enable_DM       },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_Enable_DM] */
  { /*    25 */ BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_TX_Disable      },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_TX_Disable] */
  { /*    26 */ BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_TX_EnableNoinit },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_TX_EnableNoinit] */
  { /*    27 */ BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX_Disable      },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX_Disable] */
  { /*    28 */ BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX_EnableNoinit },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX_EnableNoinit] */
  { /*    29 */ BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_Disable_DM      },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_Disable_DM] */
  { /*    30 */ BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_Enable_DM       },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_Enable_DM] */
  { /*    31 */ BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_Disable      },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_Disable] */
  { /*    32 */ BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_EnableNoinit },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_EnableNoinit] */
  { /*    33 */ BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_Disable_DM      },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_Disable_DM] */
  { /*    34 */ BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_Enable_DM       },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_Enable_DM] */
  { /*    35 */ BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_Disable_DM      },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_Disable_DM] */
  { /*    36 */ BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_Enable_DM       },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_Enable_DM] */
  { /*    37 */ BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX_Disable      },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX_Disable] */
  { /*    38 */ BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX_EnableNoinit },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX_EnableNoinit] */
  { /*    39 */ BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_Disable      },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_Disable] */
  { /*    40 */ BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_EnableNoinit },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_EnableNoinit] */
  { /*    41 */ BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_Disable      },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_Disable] */
  { /*    42 */ BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_EnableNoinit },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_EnableNoinit] */
  { /*    43 */ BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX_Disable      },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX_Disable] */
  { /*    44 */ BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX_EnableNoinit },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX_EnableNoinit] */
  { /*    45 */ BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_RX_EnableNoinit     },  /* [Priority: 0] */  /* [AL_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_RX_EnableNoinit] */
  { /*    46 */ BswM_ActionList_CC_AL_CN_CAN00_8c3ac689_RX_EnableNoinit                    }   /* [Priority: 0] */  /* [AL_CC_AL_CN_CAN00_8c3ac689_RX_EnableNoinit] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_CanSMChannelMapping
**********************************************************************************************************************/
/** 
  \var    BswM_CanSMChannelMapping
  \brief  Maps the external id of BswMCanSMIndication to an internal id and references immediate request ports.
  \details
  Element                  Description
  ExternalId               External id of BswMCanSMIndication.
  ImmediateUserEndIdx      the end index of the 0:n relation pointing to BswM_ImmediateUser
  ImmediateUserStartIdx    the start index of the 0:n relation pointing to BswM_ImmediateUser
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(BswM_CanSMChannelMappingType, BSWM_CONST) BswM_CanSMChannelMapping[6] = {
    /* Index    ExternalId                                                 ImmediateUserEndIdx  ImmediateUserStartIdx        Referable Keys */
  { /*     0 */ ComMConf_ComMChannel_CN_CAN00_8c3ac689                   ,                  1u,                    0u },  /* [CANSM_CHANNEL_0, MRP_CC_CanSMIndication_CN_CAN00_8c3ac689] */
  { /*     1 */ ComMConf_ComMChannel_CN_Schaeffler_MDA_CANFD_c149c45e    ,                  2u,                    1u },  /* [CANSM_CHANNEL_1, MRP_CC_CanSMIndication_CN_Schaeffler_MDA_CANFD_c149c45e] */
  { /*     2 */ ComMConf_ComMChannel_CN_Schaeffler_MotorFL_CANFD_b5523491,                  3u,                    2u },  /* [CANSM_CHANNEL_2, MRP_CC_CanSMIndication_CN_Schaeffler_MotorFL_CANFD_b5523491] */
  { /*     3 */ ComMConf_ComMChannel_CN_Schaeffler_MotorFR_CANFD_82b3d302,                  4u,                    3u },  /* [CANSM_CHANNEL_3, MRP_CC_CanSMIndication_CN_Schaeffler_MotorFR_CANFD_82b3d302] */
  { /*     4 */ ComMConf_ComMChannel_CN_Schaeffler_MotorRL_CANFD_4da30b40,                  5u,                    4u },  /* [CANSM_CHANNEL_4, MRP_CC_CanSMIndication_CN_Schaeffler_MotorRL_CANFD_4da30b40] */
  { /*     5 */ ComMConf_ComMChannel_CN_Schaeffler_MotorRR_CANFD_7a42ecd3,                  6u,                    5u }   /* [CANSM_CHANNEL_5, MRP_CC_CanSMIndication_CN_Schaeffler_MotorRR_CANFD_7a42ecd3] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComMChannelMapping
**********************************************************************************************************************/
/** 
  \var    BswM_ComMChannelMapping
  \brief  Maps the external id of BswMComMIndication to an internal id and references immediate request ports.
  \details
  Element       Description
  ExternalId    External id of BswMComMIndication.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(BswM_ComMChannelMappingType, BSWM_CONST) BswM_ComMChannelMapping[6] = {
    /* Index    ExternalId                                                       Referable Keys */
  { /*     0 */ ComMConf_ComMChannel_CN_CAN00_8c3ac689                    },  /* [COMM_CHANNEL_0, MRP_ESH_ComMIndication_CN_CAN00_8c3ac689] */
  { /*     1 */ ComMConf_ComMChannel_CN_Schaeffler_MDA_CANFD_c149c45e     },  /* [COMM_CHANNEL_1, MRP_ESH_ComMIndication_CN_Schaeffler_MDA_CANFD_c149c45e] */
  { /*     2 */ ComMConf_ComMChannel_CN_Schaeffler_MotorFL_CANFD_b5523491 },  /* [COMM_CHANNEL_2, MRP_ESH_ComMIndication_CN_Schaeffler_MotorFL_CANFD_b5523491] */
  { /*     3 */ ComMConf_ComMChannel_CN_Schaeffler_MotorFR_CANFD_82b3d302 },  /* [COMM_CHANNEL_3, MRP_ESH_ComMIndication_CN_Schaeffler_MotorFR_CANFD_82b3d302] */
  { /*     4 */ ComMConf_ComMChannel_CN_Schaeffler_MotorRL_CANFD_4da30b40 },  /* [COMM_CHANNEL_4, MRP_ESH_ComMIndication_CN_Schaeffler_MotorRL_CANFD_4da30b40] */
  { /*     5 */ ComMConf_ComMChannel_CN_Schaeffler_MotorRR_CANFD_7a42ecd3 }   /* [COMM_CHANNEL_5, MRP_ESH_ComMIndication_CN_Schaeffler_MotorRR_CANFD_7a42ecd3] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_DeferredRules
**********************************************************************************************************************/
/** 
  \var    BswM_DeferredRules
  \details
  Element     Description
  RulesIdx    the index of the 1:1 relation pointing to BswM_Rules
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(BswM_DeferredRulesType, BSWM_CONST) BswM_DeferredRules[7] = {
    /* Index    RulesIdx        Referable Keys */
  { /*     0 */       0u },  /* [NoPartitions, R_ESH_RunToPostRun] */
  { /*     1 */       2u },  /* [NoPartitions, R_ESH_WaitToShutdown] */
  { /*     2 */       3u },  /* [NoPartitions, R_ESH_WakeupToPrep] */
  { /*     3 */       4u },  /* [NoPartitions, R_ESH_WaitToWakeup] */
  { /*     4 */       5u },  /* [NoPartitions, R_ESH_WakeupToRun] */
  { /*     5 */       9u },  /* [NoPartitions, R_ESH_PostRun] */
  { /*     6 */      10u }   /* [NoPartitions, R_ESH_PrepToWait] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_GenericMapping
**********************************************************************************************************************/
/** 
  \var    BswM_GenericMapping
  \brief  Maps the external id of BswMGenericRequest to an internal id and references immediate request ports.
  \details
  Element                  Description
  ExternalId               External id of BswMGenericRequest.
  ImmediateUserEndIdx      the end index of the 0:n relation pointing to BswM_ImmediateUser
  ImmediateUserStartIdx    the start index of the 0:n relation pointing to BswM_ImmediateUser
  InitValue                Initialization value of port.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(BswM_GenericMappingType, BSWM_CONST) BswM_GenericMapping[2] = {
    /* Index    ExternalId  ImmediateUserEndIdx                          ImmediateUserStartIdx                          InitValue                                                            Referable Keys */
  { /*     0 */ 230       ,                                          7u,                                            6u, BSWM_GENERICVALUE_ESH_State_ESH_INIT                          },  /* [GENERIC_0, MRP_ESH_State] */
  { /*     1 */ 232       , BSWM_NO_IMMEDIATEUSERENDIDXOFGENERICMAPPING, BSWM_NO_IMMEDIATEUSERSTARTIDXOFGENERICMAPPING, BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_NO_REQUEST }   /* [GENERIC_1, MRP_ESH_ComMPendingRequests] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ImmediateUser
**********************************************************************************************************************/
/** 
  \var    BswM_ImmediateUser
  \brief  Contains all immediate request ports.
  \details
  Element             Description
  MaskedBits          contains bitcoded the boolean data of BswM_OnInitOfImmediateUser, BswM_RulesIndUsedOfImmediateUser
  RulesIndEndIdx      the end index of the 0:n relation pointing to BswM_RulesInd
  RulesIndStartIdx    the start index of the 0:n relation pointing to BswM_RulesInd
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(BswM_ImmediateUserType, BSWM_CONST) BswM_ImmediateUser[7] = {
    /* Index    MaskedBits  RulesIndEndIdx  RulesIndStartIdx        Comment                                                                     Referable Keys */
  { /*     0 */      0x01u,             2u,               0u },  /* [Name: CC_CanSMIndication_CN_CAN00_8c3ac689]                    */  /* [MRP_CC_CanSMIndication_CN_CAN00_8c3ac689, CANSM_CHANNEL_0] */
  { /*     1 */      0x01u,             5u,               2u },  /* [Name: CC_CanSMIndication_CN_Schaeffler_MDA_CANFD_c149c45e]     */  /* [MRP_CC_CanSMIndication_CN_Schaeffler_MDA_CANFD_c149c45e, CANSM_CHANNEL_1] */
  { /*     2 */      0x01u,             8u,               5u },  /* [Name: CC_CanSMIndication_CN_Schaeffler_MotorFL_CANFD_b5523491] */  /* [MRP_CC_CanSMIndication_CN_Schaeffler_MotorFL_CANFD_b5523491, CANSM_CHANNEL_2] */
  { /*     3 */      0x01u,            11u,               8u },  /* [Name: CC_CanSMIndication_CN_Schaeffler_MotorFR_CANFD_82b3d302] */  /* [MRP_CC_CanSMIndication_CN_Schaeffler_MotorFR_CANFD_82b3d302, CANSM_CHANNEL_3] */
  { /*     4 */      0x01u,            14u,              11u },  /* [Name: CC_CanSMIndication_CN_Schaeffler_MotorRL_CANFD_4da30b40] */  /* [MRP_CC_CanSMIndication_CN_Schaeffler_MotorRL_CANFD_4da30b40, CANSM_CHANNEL_4] */
  { /*     5 */      0x01u,            17u,              14u },  /* [Name: CC_CanSMIndication_CN_Schaeffler_MotorRR_CANFD_7a42ecd3] */  /* [MRP_CC_CanSMIndication_CN_Schaeffler_MotorRR_CANFD_7a42ecd3, CANSM_CHANNEL_5] */
  { /*     6 */      0x03u,            25u,              17u }   /* [Name: ESH_State]                                               */  /* [MRP_ESH_State, GENERIC_0] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_Rules
**********************************************************************************************************************/
/** 
  \var    BswM_Rules
  \details
  Element    Description
  Id         External id of rule.
  FctPtr     Pointer to the rule function which does the arbitration.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(BswM_RulesType, BSWM_CONST) BswM_Rules[28] = {
    /* Index    Id   FctPtr                                                         Referable Keys */
  { /*     0 */ 22u, BswM_Rule_ESH_RunToPostRun                              },  /* [R_ESH_RunToPostRun, MRP_ESH_State, MRP_ESH_ModeNotification, MRP_ESH_ComMIndication_CN_CAN00_8c3ac689, MRP_ESH_ComMIndication_CN_Schaeffler_MDA_CANFD_c149c45e, MRP_ESH_ComMIndication_CN_Schaeffler_MotorFL_CANFD_b5523491, MRP_ESH_ComMIndication_CN_Schaeffler_MotorRR_CANFD_7a42ecd3, MRP_ESH_ComMIndication_CN_Schaeffler_MotorRL_CANFD_4da30b40, MRP_ESH_ComMIndication_CN_Schaeffler_MotorFR_CANFD_82b3d302, MRP_ESH_RunRequest_0, MRP_ESH_RunRequest_1, MRP_ESH_SelfRunRequestTimer, NoPartitions] */
  { /*     1 */ 23u, BswM_Rule_ESH_RunToPostRunNested                        },  /* [R_ESH_RunToPostRunNested, NoPartitions] */
  { /*     2 */ 24u, BswM_Rule_ESH_WaitToShutdown                            },  /* [R_ESH_WaitToShutdown, MRP_ESH_State, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_ComMPendingRequests, NoPartitions] */
  { /*     3 */ 26u, BswM_Rule_ESH_WakeupToPrep                              },  /* [R_ESH_WakeupToPrep, MRP_ESH_State, MRP_ESH_EcuM_GetPendingWakeupEvents, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_ComMPendingRequests, MRP_ESH_ModeNotification, NoPartitions] */
  { /*     4 */ 25u, BswM_Rule_ESH_WaitToWakeup                              },  /* [R_ESH_WaitToWakeup, MRP_ESH_State, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_ComMPendingRequests, NoPartitions] */
  { /*     5 */ 27u, BswM_Rule_ESH_WakeupToRun                               },  /* [R_ESH_WakeupToRun, MRP_ESH_State, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_ComMPendingRequests, MRP_ESH_ModeNotification, NoPartitions] */
  { /*     6 */ 17u, BswM_Rule_ESH_InitToWakeup                              },  /* [R_ESH_InitToWakeup, MRP_ESH_State, NoPartitions] */
  { /*     7 */ 20u, BswM_Rule_ESH_PostRunToPrepNested                       },  /* [R_ESH_PostRunToPrepNested, NoPartitions] */
  { /*     8 */ 19u, BswM_Rule_ESH_PostRunNested                             },  /* [R_ESH_PostRunNested, NoPartitions] */
  { /*     9 */ 18u, BswM_Rule_ESH_PostRun                                   },  /* [R_ESH_PostRun, MRP_ESH_State, MRP_ESH_ModeNotification, NoPartitions] */
  { /*    10 */ 21u, BswM_Rule_ESH_PrepToWait                                },  /* [R_ESH_PrepToWait, MRP_ESH_State, MRP_ESH_ModeNotification, NoPartitions] */
  { /*    11 */  2u, BswM_Rule_CC_CN_Schaeffler_MDA_CANFD_c149c45e_RX        },  /* [R_CC_CN_Schaeffler_MDA_CANFD_c149c45e_RX, MRP_CC_CanSMIndication_CN_Schaeffler_MDA_CANFD_c149c45e, NoPartitions] */
  { /*    12 */  3u, BswM_Rule_CC_CN_Schaeffler_MDA_CANFD_c149c45e_RX_DM     },  /* [R_CC_CN_Schaeffler_MDA_CANFD_c149c45e_RX_DM, MRP_CC_CanSMIndication_CN_Schaeffler_MDA_CANFD_c149c45e, NoPartitions] */
  { /*    13 */  0u, BswM_Rule_CC_CN_CAN00_8c3ac689_RX                       },  /* [R_CC_CN_CAN00_8c3ac689_RX, MRP_CC_CanSMIndication_CN_CAN00_8c3ac689, NoPartitions] */
  { /*    14 */  1u, BswM_Rule_CC_CN_CAN00_8c3ac689_RX_DM                    },  /* [R_CC_CN_CAN00_8c3ac689_RX_DM, MRP_CC_CanSMIndication_CN_CAN00_8c3ac689, NoPartitions] */
  { /*    15 */  5u, BswM_Rule_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_RX    },  /* [R_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_RX, MRP_CC_CanSMIndication_CN_Schaeffler_MotorFL_CANFD_b5523491, NoPartitions] */
  { /*    16 */  6u, BswM_Rule_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_DM },  /* [R_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_DM, MRP_CC_CanSMIndication_CN_Schaeffler_MotorFL_CANFD_b5523491, NoPartitions] */
  { /*    17 */  7u, BswM_Rule_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_TX    },  /* [R_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_TX, MRP_CC_CanSMIndication_CN_Schaeffler_MotorFL_CANFD_b5523491, NoPartitions] */
  { /*    18 */ 10u, BswM_Rule_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX    },  /* [R_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX, MRP_CC_CanSMIndication_CN_Schaeffler_MotorFR_CANFD_82b3d302, NoPartitions] */
  { /*    19 */  9u, BswM_Rule_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_DM },  /* [R_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_DM, MRP_CC_CanSMIndication_CN_Schaeffler_MotorFR_CANFD_82b3d302, NoPartitions] */
  { /*    20 */  8u, BswM_Rule_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX    },  /* [R_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX, MRP_CC_CanSMIndication_CN_Schaeffler_MotorFR_CANFD_82b3d302, NoPartitions] */
  { /*    21 */ 12u, BswM_Rule_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_DM },  /* [R_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_DM, MRP_CC_CanSMIndication_CN_Schaeffler_MotorRL_CANFD_4da30b40, NoPartitions] */
  { /*    22 */ 15u, BswM_Rule_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_DM },  /* [R_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_DM, MRP_CC_CanSMIndication_CN_Schaeffler_MotorRR_CANFD_7a42ecd3, NoPartitions] */
  { /*    23 */ 16u, BswM_Rule_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX    },  /* [R_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX, MRP_CC_CanSMIndication_CN_Schaeffler_MotorRR_CANFD_7a42ecd3, NoPartitions] */
  { /*    24 */ 14u, BswM_Rule_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX    },  /* [R_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX, MRP_CC_CanSMIndication_CN_Schaeffler_MotorRR_CANFD_7a42ecd3, NoPartitions] */
  { /*    25 */ 11u, BswM_Rule_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX    },  /* [R_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX, MRP_CC_CanSMIndication_CN_Schaeffler_MotorRL_CANFD_4da30b40, NoPartitions] */
  { /*    26 */ 13u, BswM_Rule_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX    },  /* [R_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX, MRP_CC_CanSMIndication_CN_Schaeffler_MotorRL_CANFD_4da30b40, NoPartitions] */
  { /*    27 */  4u, BswM_Rule_CC_CN_Schaeffler_MDA_CANFD_c149c45e_TX        }   /* [R_CC_CN_Schaeffler_MDA_CANFD_c149c45e_TX, MRP_CC_CanSMIndication_CN_Schaeffler_MDA_CANFD_c149c45e, NoPartitions] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_RulesInd
**********************************************************************************************************************/
/** 
  \var    BswM_RulesInd
  \brief  the indexes of the 1:1 sorted relation pointing to BswM_Rules
*/ 
#define BSWM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(BswM_RulesIndType, BSWM_CONST) BswM_RulesInd[25] = {
  /* Index    RulesInd      Referable Keys */
  /*     0 */      13u,  /* [MRP_CC_CanSMIndication_CN_CAN00_8c3ac689] */
  /*     1 */      14u,  /* [MRP_CC_CanSMIndication_CN_CAN00_8c3ac689] */
  /*     2 */      11u,  /* [MRP_CC_CanSMIndication_CN_Schaeffler_MDA_CANFD_c149c45e] */
  /*     3 */      12u,  /* [MRP_CC_CanSMIndication_CN_Schaeffler_MDA_CANFD_c149c45e] */
  /*     4 */      27u,  /* [MRP_CC_CanSMIndication_CN_Schaeffler_MDA_CANFD_c149c45e] */
  /*     5 */      15u,  /* [MRP_CC_CanSMIndication_CN_Schaeffler_MotorFL_CANFD_b5523491] */
  /*     6 */      16u,  /* [MRP_CC_CanSMIndication_CN_Schaeffler_MotorFL_CANFD_b5523491] */
  /*     7 */      17u,  /* [MRP_CC_CanSMIndication_CN_Schaeffler_MotorFL_CANFD_b5523491] */
  /*     8 */      18u,  /* [MRP_CC_CanSMIndication_CN_Schaeffler_MotorFR_CANFD_82b3d302] */
  /*     9 */      19u,  /* [MRP_CC_CanSMIndication_CN_Schaeffler_MotorFR_CANFD_82b3d302] */
  /*    10 */      20u,  /* [MRP_CC_CanSMIndication_CN_Schaeffler_MotorFR_CANFD_82b3d302] */
  /*    11 */      21u,  /* [MRP_CC_CanSMIndication_CN_Schaeffler_MotorRL_CANFD_4da30b40] */
  /*    12 */      25u,  /* [MRP_CC_CanSMIndication_CN_Schaeffler_MotorRL_CANFD_4da30b40] */
  /*    13 */      26u,  /* [MRP_CC_CanSMIndication_CN_Schaeffler_MotorRL_CANFD_4da30b40] */
  /*    14 */      22u,  /* [MRP_CC_CanSMIndication_CN_Schaeffler_MotorRR_CANFD_7a42ecd3] */
  /*    15 */      23u,  /* [MRP_CC_CanSMIndication_CN_Schaeffler_MotorRR_CANFD_7a42ecd3] */
  /*    16 */      24u,  /* [MRP_CC_CanSMIndication_CN_Schaeffler_MotorRR_CANFD_7a42ecd3] */
  /*    17 */       0u,  /* [MRP_ESH_State] */
  /*    18 */       2u,  /* [MRP_ESH_State] */
  /*    19 */       3u,  /* [MRP_ESH_State] */
  /*    20 */       4u,  /* [MRP_ESH_State] */
  /*    21 */       5u,  /* [MRP_ESH_State] */
  /*    22 */       6u,  /* [MRP_ESH_State] */
  /*    23 */       9u,  /* [MRP_ESH_State] */
  /*    24 */      10u   /* [MRP_ESH_State] */
};
#define BSWM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_RulesOfConfig
**********************************************************************************************************************/
/** 
  \var    BswM_RulesOfConfig
  \details
  Element        Description
  InitActions
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(BswM_RulesOfConfigType, BSWM_CONST) BswM_RulesOfConfig[1] = {
    /* Index    InitActions                       Comment                    Referable Keys */
  { /*     0 */ BswM_Init_Gen_NoPartitions }   /* [NoPartitions] */  /* [NoPartitions] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionListQueue
**********************************************************************************************************************/
/** 
  \var    BswM_ActionListQueue
  \brief  Variable to store action lists which shall be executed.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(uBswM_ActionListQueueType, BSWM_VAR_NOINIT) BswM_ActionListQueue;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [AL_ESH_AL_ExitRun] */
  /*     1 */  /* [AL_ESH_AL_RunToPostRun] */
  /*     2 */  /* [AL_ESH_AL_WaitForNvMToShutdown] */
  /*     3 */  /* [AL_ESH_AL_WakeupToPrep] */
  /*     4 */  /* [AL_ESH_AL_WaitForNvMWakeup] */
  /*     5 */  /* [AL_ESH_AL_WakeupToRun] */
  /*     6 */  /* [AL_ESH_AL_InitToWakeup] */
  /*     7 */  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  /*     8 */  /* [AL_ESH_AL_ESH_PostRunToPrepCheck] */
  /*     9 */  /* [AL_ESH_AL_PostRunToRun] */
  /*    10 */  /* [AL_ESH_AL_ExitPostRun] */
  /*    11 */  /* [AL_ESH_AL_PrepShutdownToWaitForNvM] */
  /*    12 */  /* [AL_INIT_AL_Initialize] */
  /*    13 */  /* [AL_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_RX_Disable] */
  /*    14 */  /* [AL_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_TX_Disable] */
  /*    15 */  /* [AL_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_TX_EnableNoinit] */
  /*    16 */  /* [AL_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_Disable_DM] */
  /*    17 */  /* [AL_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_Enable_DM] */
  /*    18 */  /* [AL_CC_AL_CN_CAN00_8c3ac689_RX_Disable] */
  /*    19 */  /* [AL_CC_AL_CN_CAN00_8c3ac689_Disable_DM] */
  /*    20 */  /* [AL_CC_AL_CN_CAN00_8c3ac689_Enable_DM] */
  /*    21 */  /* [AL_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_Disable] */
  /*    22 */  /* [AL_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_EnableNoinit] */
  /*    23 */  /* [AL_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_Disable_DM] */
  /*    24 */  /* [AL_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_Enable_DM] */
  /*    25 */  /* [AL_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_TX_Disable] */
  /*    26 */  /* [AL_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_TX_EnableNoinit] */
  /*    27 */  /* [AL_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX_Disable] */
  /*    28 */  /* [AL_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX_EnableNoinit] */
  /*    29 */  /* [AL_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_Disable_DM] */
  /*    30 */  /* [AL_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_Enable_DM] */
  /*    31 */  /* [AL_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_Disable] */
  /*    32 */  /* [AL_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_EnableNoinit] */
  /*    33 */  /* [AL_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_Disable_DM] */
  /*    34 */  /* [AL_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_Enable_DM] */
  /*    35 */  /* [AL_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_Disable_DM] */
  /*    36 */  /* [AL_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_Enable_DM] */
  /*    37 */  /* [AL_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX_Disable] */
  /*    38 */  /* [AL_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX_EnableNoinit] */
  /*    39 */  /* [AL_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_Disable] */
  /*    40 */  /* [AL_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_EnableNoinit] */
  /*    41 */  /* [AL_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_Disable] */
  /*    42 */  /* [AL_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_EnableNoinit] */
  /*    43 */  /* [AL_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX_Disable] */
  /*    44 */  /* [AL_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX_EnableNoinit] */
  /*    45 */  /* [AL_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_RX_EnableNoinit] */
  /*    46 */  /* [AL_CC_AL_CN_CAN00_8c3ac689_RX_EnableNoinit] */

#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_CanSMChannelState
**********************************************************************************************************************/
/** 
  \var    BswM_CanSMChannelState
  \brief  Variable to store current mode of BswMCanSMIndication mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(CanSM_BswMCurrentStateType, BSWM_VAR_NOINIT) BswM_CanSMChannelState[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [CANSM_CHANNEL_0, MRP_CC_CanSMIndication_CN_CAN00_8c3ac689] */
  /*     1 */  /* [CANSM_CHANNEL_1, MRP_CC_CanSMIndication_CN_Schaeffler_MDA_CANFD_c149c45e] */
  /*     2 */  /* [CANSM_CHANNEL_2, MRP_CC_CanSMIndication_CN_Schaeffler_MotorFL_CANFD_b5523491] */
  /*     3 */  /* [CANSM_CHANNEL_3, MRP_CC_CanSMIndication_CN_Schaeffler_MotorFR_CANFD_82b3d302] */
  /*     4 */  /* [CANSM_CHANNEL_4, MRP_CC_CanSMIndication_CN_Schaeffler_MotorRL_CANFD_4da30b40] */
  /*     5 */  /* [CANSM_CHANNEL_5, MRP_CC_CanSMIndication_CN_Schaeffler_MotorRR_CANFD_7a42ecd3] */

#define BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComMChannelState
**********************************************************************************************************************/
/** 
  \var    BswM_ComMChannelState
  \brief  Variable to store current mode of BswMComMIndication mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(ComM_ModeType, BSWM_VAR_NOINIT) BswM_ComMChannelState[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [COMM_CHANNEL_0, MRP_ESH_ComMIndication_CN_CAN00_8c3ac689] */
  /*     1 */  /* [COMM_CHANNEL_1, MRP_ESH_ComMIndication_CN_Schaeffler_MDA_CANFD_c149c45e] */
  /*     2 */  /* [COMM_CHANNEL_2, MRP_ESH_ComMIndication_CN_Schaeffler_MotorFL_CANFD_b5523491] */
  /*     3 */  /* [COMM_CHANNEL_3, MRP_ESH_ComMIndication_CN_Schaeffler_MotorFR_CANFD_82b3d302] */
  /*     4 */  /* [COMM_CHANNEL_4, MRP_ESH_ComMIndication_CN_Schaeffler_MotorRL_CANFD_4da30b40] */
  /*     5 */  /* [COMM_CHANNEL_5, MRP_ESH_ComMIndication_CN_Schaeffler_MotorRR_CANFD_7a42ecd3] */

#define BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ForcedActionListPriority
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(BswM_ForcedActionListPriorityType, BSWM_VAR_NOINIT) BswM_ForcedActionListPriority[1];
#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_GenericState
**********************************************************************************************************************/
/** 
  \var    BswM_GenericState
  \brief  Variable to store current mode of BswMGenericRequest mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(BswM_ModeType, BSWM_VAR_NOINIT) BswM_GenericState[2];
  /* Index        Referable Keys  */
  /*     0 */  /* [GENERIC_0, MRP_ESH_State] */
  /*     1 */  /* [GENERIC_1, MRP_ESH_ComMPendingRequests] */

#define BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_Initialized
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(BswM_InitializedType, BSWM_VAR_NOINIT) BswM_Initialized[1];
#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ModeRequestQueue
**********************************************************************************************************************/
/** 
  \var    BswM_ModeRequestQueue
  \brief  Variable to store an immediate mode request which must be queued because of a current active arbitration.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(BswM_ModeRequestQueueType, BSWM_VAR_NOINIT) BswM_ModeRequestQueue[7];
  /* Index        Referable Keys  */
  /*     0 */  /* [MRP_CC_CanSMIndication_CN_CAN00_8c3ac689, CANSM_CHANNEL_0] */
  /*     1 */  /* [MRP_CC_CanSMIndication_CN_Schaeffler_MDA_CANFD_c149c45e, CANSM_CHANNEL_1] */
  /*     2 */  /* [MRP_CC_CanSMIndication_CN_Schaeffler_MotorFL_CANFD_b5523491, CANSM_CHANNEL_2] */
  /*     3 */  /* [MRP_CC_CanSMIndication_CN_Schaeffler_MotorFR_CANFD_82b3d302, CANSM_CHANNEL_3] */
  /*     4 */  /* [MRP_CC_CanSMIndication_CN_Schaeffler_MotorRL_CANFD_4da30b40, CANSM_CHANNEL_4] */
  /*     5 */  /* [MRP_CC_CanSMIndication_CN_Schaeffler_MotorRR_CANFD_7a42ecd3, CANSM_CHANNEL_5] */
  /*     6 */  /* [MRP_ESH_State, GENERIC_0] */

#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_QueueSemaphore
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(BswM_QueueSemaphoreType, BSWM_VAR_NOINIT) BswM_QueueSemaphore[1];
#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_QueueWritten
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(BswM_QueueWrittenType, BSWM_VAR_NOINIT) BswM_QueueWritten[1];
#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_RuleStates
**********************************************************************************************************************/
/** 
  \var    BswM_RuleStates
  \brief  Stores the last execution state of the rule.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(BswM_RuleStatesType, BSWM_VAR_NOINIT) BswM_RuleStates[28];
  /* Index        Referable Keys  */
  /*     0 */  /* [R_ESH_RunToPostRun, MRP_ESH_State, MRP_ESH_ModeNotification, MRP_ESH_ComMIndication_CN_CAN00_8c3ac689, MRP_ESH_ComMIndication_CN_Schaeffler_MDA_CANFD_c149c45e, MRP_ESH_ComMIndication_CN_Schaeffler_MotorFL_CANFD_b5523491, MRP_ESH_ComMIndication_CN_Schaeffler_MotorRR_CANFD_7a42ecd3, MRP_ESH_ComMIndication_CN_Schaeffler_MotorRL_CANFD_4da30b40, MRP_ESH_ComMIndication_CN_Schaeffler_MotorFR_CANFD_82b3d302, MRP_ESH_RunRequest_0, MRP_ESH_RunRequest_1, MRP_ESH_SelfRunRequestTimer, NoPartitions] */
  /*     1 */  /* [R_ESH_RunToPostRunNested, NoPartitions] */
  /*     2 */  /* [R_ESH_WaitToShutdown, MRP_ESH_State, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_ComMPendingRequests, NoPartitions] */
  /*     3 */  /* [R_ESH_WakeupToPrep, MRP_ESH_State, MRP_ESH_EcuM_GetPendingWakeupEvents, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_ComMPendingRequests, MRP_ESH_ModeNotification, NoPartitions] */
  /*     4 */  /* [R_ESH_WaitToWakeup, MRP_ESH_State, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_ComMPendingRequests, NoPartitions] */
  /*     5 */  /* [R_ESH_WakeupToRun, MRP_ESH_State, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_ComMPendingRequests, MRP_ESH_ModeNotification, NoPartitions] */
  /*     6 */  /* [R_ESH_InitToWakeup, MRP_ESH_State, NoPartitions] */
  /*     7 */  /* [R_ESH_PostRunToPrepNested, NoPartitions] */
  /*     8 */  /* [R_ESH_PostRunNested, NoPartitions] */
  /*     9 */  /* [R_ESH_PostRun, MRP_ESH_State, MRP_ESH_ModeNotification, NoPartitions] */
  /*    10 */  /* [R_ESH_PrepToWait, MRP_ESH_State, MRP_ESH_ModeNotification, NoPartitions] */
  /*    11 */  /* [R_CC_CN_Schaeffler_MDA_CANFD_c149c45e_RX, MRP_CC_CanSMIndication_CN_Schaeffler_MDA_CANFD_c149c45e, NoPartitions] */
  /*    12 */  /* [R_CC_CN_Schaeffler_MDA_CANFD_c149c45e_RX_DM, MRP_CC_CanSMIndication_CN_Schaeffler_MDA_CANFD_c149c45e, NoPartitions] */
  /*    13 */  /* [R_CC_CN_CAN00_8c3ac689_RX, MRP_CC_CanSMIndication_CN_CAN00_8c3ac689, NoPartitions] */
  /*    14 */  /* [R_CC_CN_CAN00_8c3ac689_RX_DM, MRP_CC_CanSMIndication_CN_CAN00_8c3ac689, NoPartitions] */
  /*    15 */  /* [R_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_RX, MRP_CC_CanSMIndication_CN_Schaeffler_MotorFL_CANFD_b5523491, NoPartitions] */
  /*    16 */  /* [R_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_DM, MRP_CC_CanSMIndication_CN_Schaeffler_MotorFL_CANFD_b5523491, NoPartitions] */
  /*    17 */  /* [R_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_TX, MRP_CC_CanSMIndication_CN_Schaeffler_MotorFL_CANFD_b5523491, NoPartitions] */
  /*    18 */  /* [R_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX, MRP_CC_CanSMIndication_CN_Schaeffler_MotorFR_CANFD_82b3d302, NoPartitions] */
  /*    19 */  /* [R_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_DM, MRP_CC_CanSMIndication_CN_Schaeffler_MotorFR_CANFD_82b3d302, NoPartitions] */
  /*    20 */  /* [R_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX, MRP_CC_CanSMIndication_CN_Schaeffler_MotorFR_CANFD_82b3d302, NoPartitions] */
  /*    21 */  /* [R_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_DM, MRP_CC_CanSMIndication_CN_Schaeffler_MotorRL_CANFD_4da30b40, NoPartitions] */
  /*    22 */  /* [R_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_DM, MRP_CC_CanSMIndication_CN_Schaeffler_MotorRR_CANFD_7a42ecd3, NoPartitions] */
  /*    23 */  /* [R_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX, MRP_CC_CanSMIndication_CN_Schaeffler_MotorRR_CANFD_7a42ecd3, NoPartitions] */
  /*    24 */  /* [R_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX, MRP_CC_CanSMIndication_CN_Schaeffler_MotorRR_CANFD_7a42ecd3, NoPartitions] */
  /*    25 */  /* [R_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX, MRP_CC_CanSMIndication_CN_Schaeffler_MotorRL_CANFD_4da30b40, NoPartitions] */
  /*    26 */  /* [R_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX, MRP_CC_CanSMIndication_CN_Schaeffler_MotorRL_CANFD_4da30b40, NoPartitions] */
  /*    27 */  /* [R_CC_CN_Schaeffler_MDA_CANFD_c149c45e_TX, MRP_CC_CanSMIndication_CN_Schaeffler_MDA_CANFD_c149c45e, NoPartitions] */

#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerState
**********************************************************************************************************************/
/** 
  \var    BswM_TimerState
  \brief  Variable to store current state of BswMTimer (STARTED, STOPPER OR EXPIRED).
*/ 
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(uBswM_TimerStateType, BSWM_VAR_NOINIT) BswM_TimerState;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [MRP_ESH_SelfRunRequestTimer] */

#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerValue
**********************************************************************************************************************/
/** 
  \var    BswM_TimerValue
  \brief  Variable to store current timer values.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(uBswM_TimerValueType, BSWM_VAR_NOINIT) BswM_TimerValue;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [MRP_ESH_SelfRunRequestTimer] */

#define BSWM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/* PRQA L:GLOBALDATADECLARATIONS */


#define BSWM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


/* -----------------------------------------------------------------------------
    &&&~ FUNCTIONS
 ----------------------------------------------------------------------------- */
/**********************************************************************************************************************
 *  BswM_ExecuteIpduGroupControl()
 **********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_ExecuteIpduGroupControl(void)
{
  Com_IpduGroupVector ipduGroupState;
  Com_IpduGroupVector dmState;
  uint16 iCnt;
  uint8 controlInvocation = BSWM_GROUPCONTROL_IDLE;

  SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  if(BswM_PduGroupControlInvocation != BSWM_GROUPCONTROL_IDLE)
  {
    if((BswM_PduGroupControlInvocation & BSWM_GROUPCONTROL_NORMAL) != 0u)
    {
      iCnt = BSWM_IPDUGROUPVECTORSIZE;
      while(iCnt-- > (uint16)0x0000) /* PRQA S 3440 */ /* MD_BswM_3440 */
      {
        ipduGroupState[iCnt] = BswM_ComIPduGroupState[iCnt]; /* SBSW_BSWM_SETIPDUGROUPVECTOR */
      }
    }
    if((BswM_PduGroupControlInvocation & BSWM_GROUPCONTROL_DM) != 0u)
    {
      iCnt = BSWM_IPDUGROUPVECTORSIZE;
      while(iCnt-- > (uint16)0x0000) /* PRQA S 3440 */ /* MD_BswM_3440 */
      {
        dmState[iCnt] = BswM_ComRxIPduGroupDMState[iCnt]; /* SBSW_BSWM_SETIPDUGROUPVECTOR */
      }
    }
    controlInvocation = BswM_PduGroupControlInvocation;
    BswM_PduGroupControlInvocation = BSWM_GROUPCONTROL_IDLE;
  }
  SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if(controlInvocation != BSWM_GROUPCONTROL_IDLE)
  {
    if((controlInvocation & BSWM_GROUPCONTROL_NORMAL) != 0u)
    {
      Com_IpduGroupControl(ipduGroupState, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
    }
    if((controlInvocation & BSWM_GROUPCONTROL_DM) != 0u)
    {
      Com_ReceptionDMControl(dmState); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
    }
  }
} /* PRQA S 6010, 6030 */ /* MD_MSR_STPTH, MD_MSR_STCYC */

/**********************************************************************************************************************
 *  BswM_Action_RuleHandler()
 **********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_RuleHandler(BswM_HandleType handleId)
{
  BswM_HandleType actionListIndex;
  Std_ReturnType retVal = E_NOT_OK;
  
  if (handleId < BswM_GetSizeOfRules())
  {
    SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    actionListIndex = BswM_GetFctPtrOfRules(handleId)(); /* SBSW_BSWM_RULEFCTPTR */
    SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if(actionListIndex < BswM_GetSizeOfActionLists())
    {
      retVal = BswM_GetFctPtrOfActionLists(actionListIndex)(); /* SBSW_BSWM_ACTIONLISTFCTPTR */
    }
    else
    {
      retVal = E_OK;
    }
  }
  return retVal;
} 

/**********************************************************************************************************************
 *  BswM_UpdateRuleStates()
 **********************************************************************************************************************/
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateRuleStates(BswM_SizeOfRuleStatesType ruleId, BswM_RuleStatesType state)
{
  if (ruleId < BswM_GetSizeOfRuleStates())
  {
    BswM_SetRuleStates(ruleId, state); /* SBSW_BSWM_SETRULESTATE */
  }
}

/**********************************************************************************************************************
 *  BswM_UpdateTimer()
 **********************************************************************************************************************/
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateTimer(BswM_SizeOfTimerValueType timerId, BswM_TimerValueType value)
{
  if (timerId < BswM_GetSizeOfTimerValue())
  {
      SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      BswM_SetTimerValue(timerId, value); /* SBSW_BSWM_SETTIMER */
      BswM_SetTimerState(timerId, (BswM_TimerStateType)((value != 0u) ? BSWM_TIMER_STARTED : BSWM_TIMER_STOPPED)); /* SBSW_BSWM_SETTIMER */
      SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
}

/**********************************************************************************************************************
 *  BswM_Init_Gen_NoPartitions
 *********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_Init_Gen_NoPartitions(void)
{

  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = 0xFF;
  Request_ESH_RunRequest_0_requestedMode = RELEASED;
  Request_ESH_RunRequest_1_requestedMode = RELEASED;
  Request_ESH_PostRunRequest_0_requestedMode = RELEASED;
  Request_ESH_PostRunRequest_1_requestedMode = RELEASED;
  BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_STARTUP;
  BswM_PduGroupControlInvocation = BSWM_GROUPCONTROL_IDLE;

  /* PRQA S 3109 COMCLEARIPDU */ /* MD_BswM_3109 */
  Com_ClearIpduGroupVector(BswM_ComIPduGroupState); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  Com_ClearIpduGroupVector(BswM_ComRxIPduGroupDMState); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMCLEARIPDU */

  (void)BswM_ActionList_INIT_AL_Initialize();
}

/**********************************************************************************************************************
 *  BswM_ModeNotificationFct
 *********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_ModeNotificationFct(void)
{
  if(BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode != 0xFF)
  {
    if(Rte_Switch_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode(BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode) == RTE_E_OK)
    {
      BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = 0xFF;
    }
  }
}

/**********************************************************************************************************************
 *  BswM_SwcModeRequestUpdateFct
 *********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_SwcModeRequestUpdateFct(void)
{
  uint32 mode;
  mode = Rte_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode();
  if (mode != RTE_TRANSITION_ESH_Mode)
  {
    BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode = (Rte_ModeType_ESH_Mode)mode;
  }
  (void)Rte_Read_Request_ESH_RunRequest_0_requestedMode(&Request_ESH_RunRequest_0_requestedMode); /* SBSW_BSWM_RTE_READ */
  (void)Rte_Read_Request_ESH_RunRequest_1_requestedMode(&Request_ESH_RunRequest_1_requestedMode); /* SBSW_BSWM_RTE_READ */
  (void)Rte_Read_Request_ESH_PostRunRequest_0_requestedMode(&Request_ESH_PostRunRequest_0_requestedMode); /* SBSW_BSWM_RTE_READ */
  (void)Rte_Read_Request_ESH_PostRunRequest_1_requestedMode(&Request_ESH_PostRunRequest_1_requestedMode); /* SBSW_BSWM_RTE_READ */
}

/**********************************************************************************************************************
 *  BswMActionListFunctions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_ExitRun
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_ExitRun(void)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0();
  /*lint -restore */
  ESH_ComM_CheckPendingRequests();
  (void)BswM_Action_RuleHandler(BSWM_ID_RULE_ESH_RunToPostRunNested);
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0();
  /*lint -restore */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_RunToPostRun
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_RunToPostRun(void)
{
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_CAN00_8c3ac689, FALSE);
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_Schaeffler_MDA_CANFD_c149c45e, FALSE);
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_Schaeffler_MotorFL_CANFD_b5523491, FALSE);
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_Schaeffler_MotorRR_CANFD_7a42ecd3, FALSE);
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_Schaeffler_MotorRL_CANFD_4da30b40, FALSE);
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_Schaeffler_MotorFR_CANFD_82b3d302, FALSE);
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  EcuM_ClearValidatedWakeupEvent(ECUM_WKSOURCE_ALL_SOURCES);
  /*lint -restore */
  BswM_ESH_OnEnterPostRun();
  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_POSTRUN;
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_POST_RUN);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_WaitForNvMToShutdown
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_WaitForNvMToShutdown(void)
{
  BswM_ESH_OnEnterShutdown();
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  (void)EcuM_GoToSelectedShutdownTarget();
  /*lint -restore */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_WakeupToPrep
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_WakeupToPrep(void)
{
  BswM_ESH_OnEnterPrepShutdown();
  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_SHUTDOWN;
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_PREP_SHUTDOWN);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_WaitForNvMWakeup
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_WaitForNvMWakeup(void)
{
  BswM_ESH_OnEnterWakeup();
  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_WAKEUP;
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_WakeupToRun
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_WakeupToRun(void)
{
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_CAN00_8c3ac689, TRUE);
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_Schaeffler_MDA_CANFD_c149c45e, TRUE);
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_Schaeffler_MotorFL_CANFD_b5523491, TRUE);
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_Schaeffler_MotorRR_CANFD_7a42ecd3, TRUE);
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_Schaeffler_MotorRL_CANFD_4da30b40, TRUE);
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_Schaeffler_MotorFR_CANFD_82b3d302, TRUE);
  BswM_UpdateTimer(BSWM_TMR_ESH_SelfRunRequestTimer, 10uL);
  BswM_ESH_OnEnterRun();
  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_RUN;
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_RUN);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_ESH_PostRunToPrepCheck
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_ESH_PostRunToPrepCheck(void)
{
  (void)BswM_Action_RuleHandler(BSWM_ID_RULE_ESH_PostRunToPrepNested);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_ExitPostRun
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_ExitPostRun(void)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0();
  /*lint -restore */
  ESH_ComM_CheckPendingRequests();
  (void)BswM_Action_RuleHandler(BSWM_ID_RULE_ESH_PostRunNested);
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0();
  /*lint -restore */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_PrepShutdownToWaitForNvM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_PrepShutdownToWaitForNvM(void)
{
  ESH_ComM_CheckPendingRequests();
  BswM_ESH_OnEnterWaitForNvm();
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_INIT_AL_Initialize
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_INIT_AL_Initialize(void)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  Can_Init(Can_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  CanIf_Init(CanIf_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  Com_Init(Com_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  PduR_Init(PduR_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  CanSM_Init(CanSM_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  CanXcp_Init(NULL_PTR);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  Xcp_Init();
  /*lint -restore */
  BswM_AL_SetProgrammableInterrupts();
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  ComM_Init();
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  (void)Rte_Start();
  /*lint -restore */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_RX_Disable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_RX_Disable(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MDA_CANFD_Rx_370d2033, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MDA_CANFD_Rx_370d2033, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_TX_Disable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_TX_Disable(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MDA_CANFD_Tx_615787b5, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MDA_CANFD_Tx_615787b5, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_TX_EnableNoinit
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_TX_EnableNoinit(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MDA_CANFD_Tx_615787b5, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MDA_CANFD_Tx_615787b5, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_Disable_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_Disable_DM(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MDA_CANFD_Rx_370d2033, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkDmControlInvocation();
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_Enable_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_Enable_DM(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MDA_CANFD_Rx_370d2033, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkDmControlInvocation();
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_CAN00_8c3ac689_RX_Disable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_CAN00_8c3ac689_RX_Disable(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_MDA_oCAN00_Rx_982be727, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oCAN00_Rx_982be727, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_CAN00_8c3ac689_Disable_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_CAN00_8c3ac689_Disable_DM(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oCAN00_Rx_982be727, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkDmControlInvocation();
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_CAN00_8c3ac689_Enable_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_CAN00_8c3ac689_Enable_DM(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oCAN00_Rx_982be727, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkDmControlInvocation();
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_Disable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_Disable(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorFL_CANFD_Rx_d87c4b2a, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorFL_CANFD_Rx_d87c4b2a, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_EnableNoinit
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_EnableNoinit(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorFL_CANFD_Rx_d87c4b2a, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorFL_CANFD_Rx_d87c4b2a, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_Disable_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_Disable_DM(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorFL_CANFD_Rx_d87c4b2a, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkDmControlInvocation();
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_Enable_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_Enable_DM(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorFL_CANFD_Rx_d87c4b2a, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkDmControlInvocation();
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_TX_Disable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_TX_Disable(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorFL_CANFD_Tx_8e26ecac, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorFL_CANFD_Tx_8e26ecac, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_TX_EnableNoinit
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_TX_EnableNoinit(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorFL_CANFD_Tx_8e26ecac, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorFL_CANFD_Tx_8e26ecac, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX_Disable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX_Disable(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorFR_CANFD_Tx_b7415df7, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorFR_CANFD_Tx_b7415df7, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX_EnableNoinit
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX_EnableNoinit(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorFR_CANFD_Tx_b7415df7, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorFR_CANFD_Tx_b7415df7, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_Disable_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_Disable_DM(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorFR_CANFD_Rx_e11bfa71, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkDmControlInvocation();
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_Enable_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_Enable_DM(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorFR_CANFD_Rx_e11bfa71, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkDmControlInvocation();
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_Disable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_Disable(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorFR_CANFD_Rx_e11bfa71, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorFR_CANFD_Rx_e11bfa71, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_EnableNoinit
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_EnableNoinit(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorFR_CANFD_Rx_e11bfa71, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorFR_CANFD_Rx_e11bfa71, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_Disable_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_Disable_DM(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorRL_CANFD_Rx_c653fc63, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkDmControlInvocation();
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_Enable_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_Enable_DM(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorRL_CANFD_Rx_c653fc63, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkDmControlInvocation();
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_Disable_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_Disable_DM(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorRR_CANFD_Rx_ff344d38, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkDmControlInvocation();
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_Enable_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_Enable_DM(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorRR_CANFD_Rx_ff344d38, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkDmControlInvocation();
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX_Disable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX_Disable(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorRR_CANFD_Tx_a96eeabe, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorRR_CANFD_Tx_a96eeabe, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX_EnableNoinit
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX_EnableNoinit(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorRR_CANFD_Tx_a96eeabe, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorRR_CANFD_Tx_a96eeabe, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_Disable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_Disable(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorRR_CANFD_Rx_ff344d38, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorRR_CANFD_Rx_ff344d38, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_EnableNoinit
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_EnableNoinit(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorRR_CANFD_Rx_ff344d38, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorRR_CANFD_Rx_ff344d38, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_Disable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_Disable(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorRL_CANFD_Rx_c653fc63, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorRL_CANFD_Rx_c653fc63, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_EnableNoinit
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_EnableNoinit(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorRL_CANFD_Rx_c653fc63, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorRL_CANFD_Rx_c653fc63, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX_Disable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX_Disable(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorRL_CANFD_Tx_90095be5, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorRL_CANFD_Tx_90095be5, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX_EnableNoinit
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX_EnableNoinit(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorRL_CANFD_Tx_90095be5, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MotorRL_CANFD_Tx_90095be5, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_RX_EnableNoinit
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_RX_EnableNoinit(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MDA_CANFD_Rx_370d2033, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oSchaeffler_MDA_CANFD_Rx_370d2033, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_CAN00_8c3ac689_RX_EnableNoinit
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_CAN00_8c3ac689_RX_EnableNoinit(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_MDA_oCAN00_Rx_982be727, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_MDA_oCAN00_Rx_982be727, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswMRuleFunctions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  BswM_Rule_ESH_RunToPostRun
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_RunToPostRun(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression ESH_LE_RunToPostRunTransition. */ /* PRQA S 3415 1 */ /* MD_MSR_12.4 */
  if(((BswM_GetGenericState(0) == BSWM_GENERICVALUE_ESH_State_ESH_RUN) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_RUN)) && (((BswM_GetComMChannelState(0) == COMM_NO_COMMUNICATION) && (BswM_GetComMChannelState(1) == COMM_NO_COMMUNICATION) && (BswM_GetComMChannelState(2) == COMM_NO_COMMUNICATION) && (BswM_GetComMChannelState(5) == COMM_NO_COMMUNICATION) && (BswM_GetComMChannelState(4) == COMM_NO_COMMUNICATION) && (BswM_GetComMChannelState(3) == COMM_NO_COMMUNICATION)) && ((Request_ESH_RunRequest_0_requestedMode == RELEASED) && (Request_ESH_RunRequest_1_requestedMode == RELEASED)) && (BswM_GetTimerState(0) == BSWM_TIMER_EXPIRED)))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_ExitRun. */
    retVal = BSWM_ID_AL_ESH_AL_ExitRun;
  }
  /* No false action list configured. */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_RunToPostRunNested
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_RunToPostRunNested(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression ESH_LE_ComMNoPendingRequests. */
  if(BswM_GetGenericState(1) == BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_NO_REQUEST)
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_RunToPostRun. */
    retVal = BSWM_ID_AL_ESH_AL_RunToPostRun;
  }
  /* No false action list configured. */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_WaitToShutdown
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_WaitToShutdown(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression ESH_LE_WaitForNvMToShutdown. */ /* PRQA S 3415 1 */ /* MD_MSR_12.4 */
  if((BswM_GetGenericState(0) == BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM) && ((EcuM_GetValidatedWakeupEvents() == 0u) && (BswM_GetGenericState(1) == BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_NO_REQUEST)))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_WaitForNvMToShutdown. */
    retVal = BSWM_ID_AL_ESH_AL_WaitForNvMToShutdown;
  }
  /* No false action list configured. */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_WakeupToPrep
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_WakeupToPrep(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression ESH_LE_WakeupToPrepShutdown. */ /* PRQA S 3415 1 */ /* MD_MSR_12.4 */
  if((BswM_GetGenericState(0) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && (EcuM_GetPendingWakeupEvents() == 0u) && ((EcuM_GetValidatedWakeupEvents() == 0u) && (BswM_GetGenericState(1) == BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_NO_REQUEST)) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_WAKEUP))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_WakeupToPrep. */
    retVal = BSWM_ID_AL_ESH_AL_WakeupToPrep;
  }
  /* No false action list configured. */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_WaitToWakeup
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_WaitToWakeup(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression ESH_LE_WaitForNvMToWakeup. */ /* PRQA S 3415 1 */ /* MD_MSR_12.4 */
  if((BswM_GetGenericState(0) == BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM) && ((EcuM_GetValidatedWakeupEvents() != 0u) || (BswM_GetGenericState(1) == BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_PENDING_REQUEST)))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_WaitForNvMWakeup. */
    retVal = BSWM_ID_AL_ESH_AL_WaitForNvMWakeup;
  }
  /* No false action list configured. */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_WakeupToRun
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_WakeupToRun(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression ESH_LE_WakeupToRun. */ /* PRQA S 3415 1 */ /* MD_MSR_12.4 */
  if((BswM_GetGenericState(0) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && ((EcuM_GetValidatedWakeupEvents() != 0u) || (BswM_GetGenericState(1) == BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_PENDING_REQUEST)) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_WAKEUP))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_WakeupToRun. */
    retVal = BSWM_ID_AL_ESH_AL_WakeupToRun;
  }
  /* No false action list configured. */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_InitToWakeup
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_InitToWakeup(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression ESH_LE_InitToWakeup. */
  if(BswM_GetGenericState(0) == BSWM_GENERICVALUE_ESH_State_ESH_INIT)
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_InitToWakeup. */
    retVal = BSWM_ID_AL_ESH_AL_InitToWakeup;
  }
  /* No false action list configured. */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_PostRunToPrepNested
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_PostRunToPrepNested(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression ESH_LE_PostRunToPrep. */
  if((Request_ESH_PostRunRequest_0_requestedMode == RELEASED) && (Request_ESH_PostRunRequest_1_requestedMode == RELEASED))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_PostRunToPrepShutdown. */
    retVal = BSWM_ID_AL_ESH_AL_PostRunToPrepShutdown;
  }
  /* No false action list configured. */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_PostRunNested
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_PostRunNested(void)
{
  BswM_HandleType retVal;
  /* Evaluate logical expression ESH_LE_PostRunToRun. */
  if(((Request_ESH_RunRequest_0_requestedMode == REQUESTED) || (Request_ESH_RunRequest_1_requestedMode == REQUESTED)) || ((EcuM_GetValidatedWakeupEvents() != 0u) || (BswM_GetGenericState(1) == BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_PENDING_REQUEST)))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_PostRunToRun. */
    retVal = BSWM_ID_AL_ESH_AL_PostRunToRun;
  }
  else
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_ESH_PostRunToPrepCheck. */
    retVal = BSWM_ID_AL_ESH_AL_ESH_PostRunToPrepCheck;
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_PostRun
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_PostRun(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression ESH_LE_PostRun. */
  if((BswM_GetGenericState(0) == BSWM_GENERICVALUE_ESH_State_ESH_POST_RUN) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_POSTRUN))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_ExitPostRun. */
    retVal = BSWM_ID_AL_ESH_AL_ExitPostRun;
  }
  /* No false action list configured. */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_PrepToWait
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_PrepToWait(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression ESH_LE_PrepShutdownToWaitForNvM. */
  if((BswM_GetGenericState(0) == BSWM_GENERICVALUE_ESH_State_ESH_PREP_SHUTDOWN) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_SHUTDOWN))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_PrepShutdownToWaitForNvM. */
    retVal = BSWM_ID_AL_ESH_AL_PrepShutdownToWaitForNvM;
  }
  /* No false action list configured. */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_Schaeffler_MDA_CANFD_c149c45e_RX
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MDA_CANFD_c149c45e_RX(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CN_Schaeffler_MDA_CANFD_c149c45e_RX. */
  if(BswM_GetCanSMChannelState(1) != CANSM_BSWM_NO_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MDA_CANFD_c149c45e_RX) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MDA_CANFD_c149c45e_RX, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_RX_EnableNoinit. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_RX_EnableNoinit;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MDA_CANFD_c149c45e_RX) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MDA_CANFD_c149c45e_RX, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_RX_Disable. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_RX_Disable;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_Schaeffler_MDA_CANFD_c149c45e_RX_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MDA_CANFD_c149c45e_RX_DM(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CN_Schaeffler_MDA_CANFD_c149c45e_RX_DM. */
  if(BswM_GetCanSMChannelState(1) == CANSM_BSWM_FULL_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MDA_CANFD_c149c45e_RX_DM) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MDA_CANFD_c149c45e_RX_DM, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_Enable_DM. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_Enable_DM;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MDA_CANFD_c149c45e_RX_DM) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MDA_CANFD_c149c45e_RX_DM, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_Disable_DM. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_Disable_DM;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_CAN00_8c3ac689_RX
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_CAN00_8c3ac689_RX(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CN_CAN00_8c3ac689_RX. */
  if(BswM_GetCanSMChannelState(0) != CANSM_BSWM_NO_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_CAN00_8c3ac689_RX) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_CAN00_8c3ac689_RX, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_CAN00_8c3ac689_RX_EnableNoinit. */
      retVal = BSWM_ID_AL_CC_AL_CN_CAN00_8c3ac689_RX_EnableNoinit;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_CAN00_8c3ac689_RX) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_CAN00_8c3ac689_RX, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_CAN00_8c3ac689_RX_Disable. */
      retVal = BSWM_ID_AL_CC_AL_CN_CAN00_8c3ac689_RX_Disable;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_CAN00_8c3ac689_RX_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_CAN00_8c3ac689_RX_DM(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CN_CAN00_8c3ac689_RX_DM. */
  if(BswM_GetCanSMChannelState(0) == CANSM_BSWM_FULL_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_CAN00_8c3ac689_RX_DM) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_CAN00_8c3ac689_RX_DM, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_CAN00_8c3ac689_Enable_DM. */
      retVal = BSWM_ID_AL_CC_AL_CN_CAN00_8c3ac689_Enable_DM;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_CAN00_8c3ac689_RX_DM) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_CAN00_8c3ac689_RX_DM, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_CAN00_8c3ac689_Disable_DM. */
      retVal = BSWM_ID_AL_CC_AL_CN_CAN00_8c3ac689_Disable_DM;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_RX
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_RX(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CN_Schaeffler_MotorFL_CANFD_b5523491_RX. */
  if(BswM_GetCanSMChannelState(2) != CANSM_BSWM_NO_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_RX) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_RX, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_EnableNoinit. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_EnableNoinit;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_RX) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_RX, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_Disable. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_Disable;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_DM(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_DM. */
  if(BswM_GetCanSMChannelState(2) == CANSM_BSWM_FULL_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_DM) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_DM, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_Enable_DM. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_Enable_DM;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_DM) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_RX_DM, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_Disable_DM. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_Disable_DM;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_TX
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_TX(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CN_Schaeffler_MotorFL_CANFD_b5523491_TX. */
  if(BswM_GetCanSMChannelState(2) == CANSM_BSWM_FULL_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_TX) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_TX, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_TX_EnableNoinit. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_TX_EnableNoinit;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_TX) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorFL_CANFD_b5523491_TX, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_TX_Disable. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MotorFL_CANFD_b5523491_TX_Disable;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX. */
  if(BswM_GetCanSMChannelState(3) == CANSM_BSWM_FULL_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX_EnableNoinit. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX_EnableNoinit;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX_Disable. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_TX_Disable;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_DM(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_DM. */
  if(BswM_GetCanSMChannelState(3) == CANSM_BSWM_FULL_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_DM) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_DM, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_Enable_DM. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_Enable_DM;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_DM) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_DM, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_Disable_DM. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_Disable_DM;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX. */
  if(BswM_GetCanSMChannelState(3) != CANSM_BSWM_NO_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_EnableNoinit. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_EnableNoinit;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_Disable. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MotorFR_CANFD_82b3d302_RX_Disable;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_DM(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_DM. */
  if(BswM_GetCanSMChannelState(4) == CANSM_BSWM_FULL_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_DM) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_DM, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_Enable_DM. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_Enable_DM;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_DM) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_DM, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_Disable_DM. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_Disable_DM;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_DM(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_DM. */
  if(BswM_GetCanSMChannelState(5) == CANSM_BSWM_FULL_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_DM) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_DM, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_Enable_DM. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_Enable_DM;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_DM) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_DM, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_Disable_DM. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_Disable_DM;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX. */
  if(BswM_GetCanSMChannelState(5) == CANSM_BSWM_FULL_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX_EnableNoinit. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX_EnableNoinit;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX_Disable. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_TX_Disable;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX. */
  if(BswM_GetCanSMChannelState(5) != CANSM_BSWM_NO_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_EnableNoinit. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_EnableNoinit;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_Disable. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MotorRR_CANFD_7a42ecd3_RX_Disable;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX. */
  if(BswM_GetCanSMChannelState(4) != CANSM_BSWM_NO_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_EnableNoinit. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_EnableNoinit;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_Disable. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_RX_Disable;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX. */
  if(BswM_GetCanSMChannelState(4) == CANSM_BSWM_FULL_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX_EnableNoinit. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX_EnableNoinit;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX_Disable. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MotorRL_CANFD_4da30b40_TX_Disable;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_Schaeffler_MDA_CANFD_c149c45e_TX
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_Schaeffler_MDA_CANFD_c149c45e_TX(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CN_Schaeffler_MDA_CANFD_c149c45e_TX. */
  if(BswM_GetCanSMChannelState(1) == CANSM_BSWM_FULL_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MDA_CANFD_c149c45e_TX) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MDA_CANFD_c149c45e_TX, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_TX_EnableNoinit. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_TX_EnableNoinit;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MDA_CANFD_c149c45e_TX) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_Schaeffler_MDA_CANFD_c149c45e_TX, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_TX_Disable. */
      retVal = BSWM_ID_AL_CC_AL_CN_Schaeffler_MDA_CANFD_c149c45e_TX_Disable;
    }
  }
  return retVal;
}



#define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

