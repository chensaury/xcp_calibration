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
 *            Module: Can
 *           Program: MSR_Vector_SLP4
 *          Customer: Aptiv (China) Technology Company Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Aurix 2G/TC397 B-Step
 *    License Scope : The usage is restricted to CBD1900078_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Can_DrvGeneralTypes.h
 *   Generation Time: 2024-01-08 16:27:33
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

#if !defined(CAN_DRVGENERALTYPES_H)
#define CAN_DRVGENERALTYPES_H

/* -----------------------------------------------------------------------------
    Types
 ----------------------------------------------------------------------------- */

/* CAN416, CAN065_Conf */
typedef VAR(uint32, TYPEDEF) Can_IdType;

/* CAN429 */
typedef VAR(uint8, TYPEDEF) Can_HwHandleType;
typedef VAR(sint16, TYPEDEF) Can_SignedHwHandleType;

typedef P2VAR(uint8, TYPEDEF, CAN_APPL_VAR) Can_SduPtrType;

/* CAN415 */
typedef struct Can_PduTypeTag
{
  Can_IdType id;
  uint8 length;
  Can_SduPtrType sdu;
  PduIdType swPduHandle;
} Can_PduType;

/* CAN417 */
typedef enum {
  CAN_T_START = 0,
  CAN_T_STOP,
  CAN_T_SLEEP,
  CAN_T_WAKEUP
} Can_StateTransitionType;

typedef enum {
  CAN_CS_UNINIT = 0,
  CAN_CS_STARTED = 1,
  CAN_CS_STOPPED = 2,
  CAN_CS_SLEEP = 3
} Can_ControllerStateType;

typedef enum {
  CAN_ERRORSTATE_ACTIVE = 0,
  CAN_ERRORSTATE_PASSIVE,
  CAN_ERRORSTATE_BUSOFF
} Can_ErrorStateType;

/* CAN039 - for CBD compatibility OK is 1 - REQUESTED */
typedef enum {
  CAN_NOT_OK = 0,
  CAN_OK = 1,
  CAN_BUSY = 2
} Can_ReturnType;

/* CAN496 */
typedef struct Can_HwTypeTag
{
  Can_IdType CanId;
  Can_HwHandleType Hoh;
  uint8 ControllerId;
} Can_HwType;


#endif /* CAN_DRVGENERALTYPES_H */
 

