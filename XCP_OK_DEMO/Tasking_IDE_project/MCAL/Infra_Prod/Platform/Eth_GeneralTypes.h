/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2018)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : Eth_GeneralTypes.h                                         **
**                                                                            **
**  VERSION      : 5.0.0                                                      **
**                                                                            **
**  DATE         : 2018-08-03                                                 **
**                                                                            **
**  VARIANT      : Variant PB                                                 **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : Type Definition for ETH module                             **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_EthernetDriver.pdf, AUTOSAR Release 4.2.2  **
**                                                                            **
**  MAY BE CHANGED BY USER : Yes                                              **
**                                                                            **
*******************************************************************************/
/* [cover parentID={02E963B3-0809-4549-A097-7621EFA30E8E}]
[/cover] */
#ifndef ETH_GENERALTYPES_H
#define ETH_GENERALTYPES_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Include Communication Stack Types */
#include "ComStack_Types.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

typedef uint16 Eth_FrameType;

typedef uint8 Eth_DataType;

typedef enum 
{
  ETH_MODE_DOWN   = 0x0U,
  ETH_MODE_ACTIVE = 0x1U
}Eth_ModeType;

/* [cover parentID={06E8EA99-99C0-447c-BAB8-CEA3043FB649}] */
typedef enum 
{
  ETH_STATE_UNINIT   = 0x0U,
  ETH_STATE_INIT     = 0x1U
}Eth_StateType;
/*[/cover] */


/* Added for compatibility with AS4.1 */
typedef enum
{
  ETH_RECEIVED = 0x0U,
  ETH_NOT_RECEIVED,
  ETH_RECEIVED_MORE_DATA_AVAILABLE
} Eth_RxStatusType;

typedef enum
{
  ETH_ADD_TO_FILTER = 0x0U,
  ETH_REMOVE_FROM_FILTER
} Eth_FilterActionType;

/* [cover parentID={31610027-C922-48ba-A512-90E0F5996F6F}] */
typedef enum
{
  ETH_OK=0x0U,
  ETH_E_NOT_OK,
  ETH_E_NO_ACCESS
}Eth_ReturnType;
/*[/cover] */

typedef enum
{
  ETH_VALID = 0x0U,
  ETH_INVALID,
  ETH_UNCERTAIN
}Eth_TimeStampQualType;

typedef struct
{
  uint32 nanoseconds;
  uint32 seconds;
  uint16 secondsHi;
}Eth_TimeStampType;

typedef struct
{
  Eth_TimeStampType diff;
  boolean sign;
}Eth_TimeIntDiffType;

typedef struct
{
  Eth_TimeIntDiffType IngressTimeStampDelta ;
  Eth_TimeIntDiffType OriginTimeStampDelta ;
}Eth_RateRatioType;

typedef uint32 Eth_BufIdxType;

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

/*******************************************************************************
**                            LOW Level Driver Definitions                    **
*******************************************************************************/

/*******************************************************************************
**                            LOW Level Driver Definitions                    **
*******************************************************************************/


#endif /* ETH_GENERALTYPES_H */

