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
 *            Module: EcuM
 *           Program: MSR_Vector_SLP4
 *          Customer: Aptiv (China) Technology Company Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Aurix 2G/TC397 B-Step
 *    License Scope : The usage is restricted to CBD1900078_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EcuM_Generated_Types.h
 *   Generation Time: 2023-03-21 20:44:22
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

#if !defined(ECUM_GENERATEDTYPES_H)
#define ECUM_GENERATEDTYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

# include "Rte_EcuM_Type.h"
# include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*! This type is a 32bit bitmask where each bit represents a wakeup source. */
 typedef uint32 EcuM_WakeupSourceType;
 
 

/* ------------------------------------- Symblic Name Defines for EcuM_WakeupSourceType ---------------------------- */
#define EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_POWER          (0uL) 
#define EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_RESET          (1uL) 
#define EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_INTERNAL_RESET (2uL) 
#define EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_INTERNAL_WDG   (3uL) 
#define EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_EXTERNAL_WDG   (4uL) 
#define EcuMConf_EcuMWakeupSource_CN_CAN00_a2de9a4f            (5uL) 

 
/* ------------------------------------- Range of EcuM_WakeupSourceType -------------------------------------------- */
#define ECUM_WKSOURCE_NONE              (EcuM_WakeupSourceType)(0x00000000uL) 
#define ECUM_WKSOURCE_ALL_SOURCES       (EcuM_WakeupSourceType)(~((EcuM_WakeupSourceType)0x00UL)) 
#define ECUM_WKSOURCE_POWER             (EcuM_WakeupSourceType)(1uL) 
#define ECUM_WKSOURCE_RESET             (EcuM_WakeupSourceType)(2uL) 
#define ECUM_WKSOURCE_INTERNAL_RESET    (EcuM_WakeupSourceType)(4uL) 
#define ECUM_WKSOURCE_INTERNAL_WDG      (EcuM_WakeupSourceType)(8uL) 
#define ECUM_WKSOURCE_EXTERNAL_WDG      (EcuM_WakeupSourceType)(16uL) 
#define ECUM_WKSOURCE_CN_CAN00_a2de9a4f (EcuM_WakeupSourceType)(32uL) 



  /* ------------------------------------- Range of EcuM_StateType ------------------------------------------------- */
#define ECUM_SUBSTATE_MASK                                  (0x0Fu)
#define ECUM_STATE_STARTUP                                  (0x10u)
#define ECUM_STATE_STARTUP_ONE                              (0x11u)
#define ECUM_STATE_STARTUP_TWO                              (0x12u)
#define ECUM_STATE_WAKEUP                                   (0x20u)
#define ECUM_STATE_WAKEUP_ONE                               (0x21u)
#define ECUM_STATE_WAKEUP_VALIDATION                        (0x22u)
#define ECUM_STATE_WAKEUP_REACTION                          (0x23u)
#define ECUM_STATE_WAKEUP_TWO                               (0x24u)
#define ECUM_STATE_WAKEUP_WAKESLEEP                         (0x25u)
#define ECUM_STATE_WAKEUP_TTII                              (0x26u)
#define ECUM_STATE_RUN                                      (0x30u)
#define ECUM_STATE_APP_RUN                                  (0x32u)
#define ECUM_STATE_APP_POST_RUN                             (0x33u)
#define ECUM_STATE_SHUTDOWN                                 (0x40u)
#define ECUM_STATE_PREP_SHUTDOWN                            (0x44u)
#define ECUM_STATE_GO_SLEEP                                 (0x49u)
#define ECUM_STATE_GO_OFF_ONE                               (0x4Du)
#define ECUM_STATE_GO_OFF_TWO                               (0x4Eu)
/* State OFF, RESET AND SLEEP are defined by the RTE */
#define ECUM_STATE_ERROR                                    (0xFFu)


typedef uint8 EcuM_WakeupStateType;
/* ------------------------------------- Range of EcuM_WakeupStatusType -------------------------------------------- */
#define ECUM_WKSTATUS_NONE                                  (0u)
#define ECUM_WKSTATUS_PENDING                               (1u)
#define ECUM_WKSTATUS_VALIDATED                             (2u)
#define ECUM_WKSTATUS_EXPIRED                               (3u)

/* The following state was introduced by Vector to support asynchronous transceiver handling */
#define ECUM_WKSTATUS_CHECKWAKEUP                           (5u)
#define ECUM_WKSTATUS_ENABLED                               (6u)

/* ------------------------------------- Range of Alarm Clocks ----------------------------------------------------- */

/* ------------------------------------- Range of EcuM RunStatus Types --------------------------------------------- */
#define ECUM_RUNSTATUS_UNKNOWN                              (0u)
#define ECUM_RUNSTATUS_REQUESTED                            (1u)
#define ECUM_RUNSTATUS_RELEASED                             (2u)


typedef uint8 EcuM_RunStatusType;

typedef EcuM_ModeType EcuM_ResetType;

#endif /* ECUM_GENERATEDTYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: ECUM_GENERATEDTYPES.H
 *********************************************************************************************************************/


