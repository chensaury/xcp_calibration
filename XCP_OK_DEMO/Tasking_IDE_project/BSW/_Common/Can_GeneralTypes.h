/********************************************************************************************************************
|    File Name: Can_GeneralTypes.H
|
|  Description: Type definitions of the AUTOSAR CAN components Can, CanIf, CanTrcv
|--------------------------------------------------------------------------------------------------------------------
|               C O P Y R I G H T
|--------------------------------------------------------------------------------------------------------------------
| Copyright (c) 1996-2012 by Vector Informatik GmbH.       All rights reserved.
|
| This software is copyright protected and proprietary
| to Vector Informatik GmbH. Vector Informatik GmbH
| grants to you only those rights as set out in the
| license conditions. All other rights remain with
| Vector Informatik GmbH.
|
|--------------------------------------------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|--------------------------------------------------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
| visbir       Holger Birke              Vector Informatik GmbH
|--------------------------------------------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|--------------------------------------------------------------------------------------------------------------------
| Date        Version   Author  Description
| ----------  --------  ------  -------------------------------------------------------------------------------------
| 2012-05-31  1.00.00   visbir  - Add Can types
| 2012-07-27  1.00.01   visbir  - Add Trcv switch for include
| 2013-02-20  1.01.00   visbir  - ESCAN00061193: Use static Trcv types
|*******************************************************************************************************************/
#ifndef CAN_GENERAL_TYPES
#define CAN_GENERAL_TYPES

/* Version of Can_GeneralTypes header */
#define CAN_GENERAL_TYPES_MAJOR_VERSION     0x01
#define CAN_GENERAL_TYPES_MINOR_VERSION     0x01
#define CAN_GENERAL_TYPES_PATCH_VERSION     0x00

#include "ComStack_Types.h"

/*  CAN Transceiver Driver    also available as generated file "CanTrcv_GeneralTypes.h"  */
/*  !!!  please remove this types when you use no Vector CAN Transceiver Driver  */
typedef enum CanTrcv_TrcvModeTypeTag 
{
  CANTRCV_TRCVMODE_NORMAL = 0u,
  CANTRCV_TRCVMODE_SLEEP,
  CANTRCV_TRCVMODE_STANDBY
} CanTrcv_TrcvModeType;

typedef enum CanTrcv_TrcvWakeupModeTypeTag
{
  CANTRCV_WUMODE_ENABLE = 0u,
  CANTRCV_WUMODE_CLEAR,
  CANTRCV_WUMODE_DISABLE
} CanTrcv_TrcvWakeupModeType;

typedef enum CanTrcv_TrcvWakeupReasonTypeTag
{
  CANTRCV_WU_ERROR = 0u,
  CANTRCV_WU_BY_BUS,
  CANTRCV_WU_BY_PIN,
  CANTRCV_WU_INTERNALLY,
  CANTRCV_WU_NOT_SUPPORTED,
  CANTRCV_WU_POWER_ON,
  CANTRCV_WU_RESET,
  CANTRCV_WU_BY_SYSERR
} CanTrcv_TrcvWakeupReasonType;
/*  CAN Transceiver Driver   end  */


/*  CAN Driver generated File  */
#include "Can_DrvGeneralTypes.h"


/*  CAN Interface generated File  */
#include "CanIf_GeneralTypes.h"



#endif /* CAN_GENERAL_TYPES */
