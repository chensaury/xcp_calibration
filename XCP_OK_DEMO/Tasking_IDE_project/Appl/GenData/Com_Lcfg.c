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
 *            Module: Com
 *           Program: MSR_Vector_SLP4
 *          Customer: Aptiv (China) Technology Company Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Aurix 2G/TC397 B-Step
 *    License Scope : The usage is restricted to CBD1900078_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Com_Lcfg.c
 *   Generation Time: 2023-03-21 20:44:23
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


/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/
/* PRQA  S 1881 EOF */ /* MD_MSR_AutosarBoolean */
/* PRQA  S 1882 EOF */ /* MD_MSR_AutosarBoolean */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#define V_IL_ASRCOMCFG5_LCFG_SOURCE

#include "Com.h"

#include "Com_Lcfg.h"


#include "SchM_Com.h"

/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  Com_ConstValueUInt16
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt16
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT16)
*/ 
#define COM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_ConstValueUInt16Type, COM_CONST) Com_ConstValueUInt16[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ConstValueUInt16      Referable Keys */
  /*     0 */           0x0000u,  /* [/ActiveEcuC/Com/ComConfig/Comp_speed_of_compressor_oACP_32E_oCAN00_c033917a_RxInitValue, /ActiveEcuC/Com/ComConfig/Ecomp_CompIpt_V_oACP_327_oCAN00_c7006e5a_RxInitValue, /ActiveEcuC/Com/ComConfig/Ecomp_Complpt_A_oACP_327_oCAN00_ea282991_RxInitValue, /ActiveEcuC/Com/ComConfig/Ecomp_InvSoftwareVer_oACP_327_oCAN00_4030e33b_RxInitValue] */
  /*     1 */           0x018Cu   /* [/ActiveEcuC/Com/ComConfig/B_RLS_DewPoint_oB_RLS_oCAN00_421173c7_RxInitValue] */
};
#define COM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt8
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt8
  \brief  Optimized array of commonly used values like initial or invalid values. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_ConstValueUInt8Type, COM_CONST) Com_ConstValueUInt8[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ConstValueUInt8      Referable Keys */
  /*     0 */            0x01u,  /* [/ActiveEcuC/Com/ComConfig/B_RLS_relativeHumidity_oB_RLS_oCAN00_e615f445_RxInitValue] */
  /*     1 */            0x50u,  /* [/ActiveEcuC/Com/ComConfig/B_RLS_WindshieldTemp_oB_RLS_oCAN00_6dbe9061_RxInitValue] */
  /*     2 */            0x00u   /* [/ActiveEcuC/Com/ComConfig/B_RLS_Offline_Calibration_Result_oB_RLS_oCAN00_f4cfd300_RxInitValue, /ActiveEcuC/Com/ComConfig/B_RLS_SolarLeft_oB_RLS_oCAN00_3b2a55ba_RxInitValue, /ActiveEcuC/Com/ComConfig/B_RLS_SolarRight_oB_RLS_oCAN00_6bd7c4e8_RxInitValue, /ActiveEcuC/Com/ComConfig/Comp_error_code1_oACP_32E_oCAN00_b5915ac1_RxInitValue, /ActiveEcuC/Com/ComConfig/Comp_work_status_oACP_32E_oCAN00_1667710c_RxInitValue] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_PduGrpVector
**********************************************************************************************************************/
/** 
  \var    Com_PduGrpVector
  \brief  Contains an I-PDU-Group vector for each I-PDU, mapping the I-PDU to the corresponding I-PDU-Groups.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_PduGrpVectorType, COM_CONST) Com_PduGrpVector[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     PduGrpVector      Referable Keys */
  /*     0 */         0x02u,  /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx] */
  /*     1 */         0x01u   /* [/ActiveEcuC/Com/ComConfig/ACP_327_oCAN00_ffa62305_Rx, /ActiveEcuC/Com/ComConfig/ACP_32E_oCAN00_11d3b5e8_Rx, /ActiveEcuC/Com/ComConfig/B_RLS_oCAN00_6419d093_Rx] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfo
  \brief  Contains all signal layout information necessary for signal access within an I-PDU.
  \details
  Element                   Description
  InitValueUsed             TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64,Com_ConstValueFloat32,Com_ConstValueFloat64
  ApplType                  Application data type.
  BitLength                 Bit length of the signal or group signal.
  BitPosition               Little endian bit position of the signal or group signal within the I-PDU.
  BufferIdx                 the index of the 0:1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64,Com_RxSigBufferFloat32,Com_RxSigBufferFloat64
  BusAcc                    BUS access algorithm for signal or group signal packing / un-packing.
  ByteLength                Byte length of the signal or group signal.
  BytePosition              Little endian byte position of the signal or group signal within the I-PDU.
  InitValueIdx              the index of the 0:1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64,Com_ConstValueFloat32,Com_ConstValueFloat64
  RxPduInfoIdx              the index of the 1:1 relation pointing to Com_RxPduInfo
  StartByteInPduPosition    Start Byte position of the signal or group signal within the I-PDU.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxAccessInfoType, COM_CONST) Com_RxAccessInfo[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    InitValueUsed  ApplType                           BitLength  BitPosition  BufferIdx  BusAcc                                 ByteLength  BytePosition  InitValueIdx  RxPduInfoIdx  StartByteInPduPosition        Referable Keys */
  { /*     0 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       10u,         40u,        0u, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1u,           5u,           1u,           2u,                     4u },  /* [/ActiveEcuC/Com/ComConfig/B_RLS_DewPoint_oB_RLS_oCAN00_421173c7_Rx, /ActiveEcuC/Com/ComConfig/B_RLS_oCAN00_6419d093_Rx] */
  { /*     1 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        2u,         48u,        0u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           6u,           2u,           2u,                     6u },  /* [/ActiveEcuC/Com/ComConfig/B_RLS_Offline_Calibration_Result_oB_RLS_oCAN00_f4cfd300_Rx, /ActiveEcuC/Com/ComConfig/B_RLS_oCAN00_6419d093_Rx] */
  { /*     2 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,        1u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           2u,           2u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/B_RLS_SolarLeft_oB_RLS_oCAN00_3b2a55ba_Rx, /ActiveEcuC/Com/ComConfig/B_RLS_oCAN00_6419d093_Rx] */
  { /*     3 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          8u,        2u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           1u,           2u,           2u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/B_RLS_SolarRight_oB_RLS_oCAN00_6bd7c4e8_Rx, /ActiveEcuC/Com/ComConfig/B_RLS_oCAN00_6419d093_Rx] */
  { /*     4 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,         24u,        3u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           3u,           1u,           2u,                     3u },  /* [/ActiveEcuC/Com/ComConfig/B_RLS_WindshieldTemp_oB_RLS_oCAN00_6dbe9061_Rx, /ActiveEcuC/Com/ComConfig/B_RLS_oCAN00_6419d093_Rx] */
  { /*     5 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,         16u,        4u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           2u,           0u,           2u,                     2u },  /* [/ActiveEcuC/Com/ComConfig/B_RLS_relativeHumidity_oB_RLS_oCAN00_e615f445_Rx, /ActiveEcuC/Com/ComConfig/B_RLS_oCAN00_6419d093_Rx] */
  { /*     6 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,         32u,        5u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           4u,           2u,           0u,                     4u },  /* [/ActiveEcuC/Com/ComConfig/Comp_error_code1_oACP_32E_oCAN00_b5915ac1_Rx, /ActiveEcuC/Com/ComConfig/ACP_32E_oCAN00_11d3b5e8_Rx] */
  { /*     7 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,          8u,        1u,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2u,           1u,           0u,           0u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Comp_speed_of_compressor_oACP_32E_oCAN00_c033917a_Rx, /ActiveEcuC/Com/ComConfig/ACP_32E_oCAN00_11d3b5e8_Rx] */
  { /*     8 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,         24u,        6u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           3u,           2u,           0u,                     3u },  /* [/ActiveEcuC/Com/ComConfig/Comp_work_status_oACP_32E_oCAN00_1667710c_Rx, /ActiveEcuC/Com/ComConfig/ACP_32E_oCAN00_11d3b5e8_Rx] */
  { /*     9 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         24u,        2u,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2u,           3u,           0u,           1u,                     2u },  /* [/ActiveEcuC/Com/ComConfig/Ecomp_CompIpt_V_oACP_327_oCAN00_c7006e5a_Rx, /ActiveEcuC/Com/ComConfig/ACP_327_oCAN00_ffa62305_Rx] */
  { /*    10 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,        3u,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,           1u,                     4u },  /* [/ActiveEcuC/Com/ComConfig/Ecomp_Complpt_A_oACP_327_oCAN00_ea282991_Rx, /ActiveEcuC/Com/ComConfig/ACP_327_oCAN00_ffa62305_Rx] */
  { /*    11 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,          8u,        4u,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2u,           1u,           0u,           1u,                     0u }   /* [/ActiveEcuC/Com/ComConfig/Ecomp_InvSoftwareVer_oACP_327_oCAN00_4030e33b_Rx, /ActiveEcuC/Com/ComConfig/ACP_327_oCAN00_ffa62305_Rx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_RxAccessInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxAccessInfoIndType, COM_CONST) Com_RxAccessInfoInd[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxAccessInfoInd      Referable Keys */
  /*     0 */               6u,  /* [/ActiveEcuC/Com/ComConfig/ACP_32E_oCAN00_11d3b5e8_Rx] */
  /*     1 */               7u,  /* [/ActiveEcuC/Com/ComConfig/ACP_32E_oCAN00_11d3b5e8_Rx] */
  /*     2 */               8u,  /* [/ActiveEcuC/Com/ComConfig/ACP_32E_oCAN00_11d3b5e8_Rx] */
  /*     3 */               9u,  /* [/ActiveEcuC/Com/ComConfig/ACP_327_oCAN00_ffa62305_Rx] */
  /*     4 */              10u,  /* [/ActiveEcuC/Com/ComConfig/ACP_327_oCAN00_ffa62305_Rx] */
  /*     5 */              11u,  /* [/ActiveEcuC/Com/ComConfig/ACP_327_oCAN00_ffa62305_Rx] */
  /*     6 */               0u,  /* [/ActiveEcuC/Com/ComConfig/B_RLS_oCAN00_6419d093_Rx] */
  /*     7 */               1u,  /* [/ActiveEcuC/Com/ComConfig/B_RLS_oCAN00_6419d093_Rx] */
  /*     8 */               2u,  /* [/ActiveEcuC/Com/ComConfig/B_RLS_oCAN00_6419d093_Rx] */
  /*     9 */               3u,  /* [/ActiveEcuC/Com/ComConfig/B_RLS_oCAN00_6419d093_Rx] */
  /*    10 */               4u,  /* [/ActiveEcuC/Com/ComConfig/B_RLS_oCAN00_6419d093_Rx] */
  /*    11 */               5u   /* [/ActiveEcuC/Com/ComConfig/B_RLS_oCAN00_6419d093_Rx] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxPduGrpInfo
  \brief  Contains all I-PDU-Group relevant information for Rx I-PDUs.
  \details
  Element                 Description
  PduGrpVectorStartIdx    the start index of the 0:n relation pointing to Com_PduGrpVector
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxPduGrpInfoType, COM_CONST) Com_RxPduGrpInfo[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PduGrpVectorStartIdx */
  { /*     0 */                   1u },
  { /*     1 */                   1u },
  { /*     2 */                   1u }
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxPduInfo
  \brief  Contains all relevant common information for Rx I-PDUs.
  \details
  Element                   Description
  RxAccessInfoIndUsed       TRUE, if the 0:n relation has 1 relation pointing to Com_RxAccessInfoInd
  RxDefPduBufferStartIdx    the start index of the 0:n relation pointing to Com_RxDefPduBuffer
  RxSigInfoEndIdx           the end index of the 0:n relation pointing to Com_RxSigInfo
  RxSigInfoStartIdx         the start index of the 0:n relation pointing to Com_RxSigInfo
  Type                      Defines whether rx Pdu is a NORMAL or TP IPdu.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxPduInfoType, COM_CONST) Com_RxPduInfo[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxAccessInfoIndUsed  RxDefPduBufferStartIdx  RxSigInfoEndIdx  RxSigInfoStartIdx  Type                              Referable Keys */
  { /*     0 */                TRUE,                     0u,              3u,                0u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/ACP_32E_oCAN00_11d3b5e8_Rx, /ActiveEcuC/Com/ComConfig/ITMS_oCAN00_Rx_06702e0c] */
  { /*     1 */                TRUE,                     8u,              6u,                3u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/ACP_327_oCAN00_ffa62305_Rx, /ActiveEcuC/Com/ComConfig/ITMS_oCAN00_Rx_06702e0c] */
  { /*     2 */                TRUE,                    16u,             12u,                6u, COM_NORMAL_TYPEOFRXPDUINFO }   /* [/ActiveEcuC/Com/ComConfig/B_RLS_oCAN00_6419d093_Rx, /ActiveEcuC/Com/ComConfig/ITMS_oCAN00_Rx_06702e0c] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxSigInfo
  \brief  Contains all relevant information for Rx signals.
  \details
  Element             Description
  RxAccessInfoIdx     the index of the 1:1 relation pointing to Com_RxAccessInfo
  SignalProcessing
  ValidDlc            Minimum length of PDU required to completely receive the signal or signal group.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxSigInfoType, COM_CONST) Com_RxSigInfo[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxAccessInfoIdx  SignalProcessing                          ValidDlc        Referable Keys */
  { /*     0 */              6u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/ACP_32E_oCAN00_11d3b5e8_Rx] */
  { /*     1 */              7u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/ACP_32E_oCAN00_11d3b5e8_Rx] */
  { /*     2 */              8u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4u },  /* [/ActiveEcuC/Com/ComConfig/ACP_32E_oCAN00_11d3b5e8_Rx] */
  { /*     3 */              9u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4u },  /* [/ActiveEcuC/Com/ComConfig/ACP_327_oCAN00_ffa62305_Rx] */
  { /*     4 */             10u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6u },  /* [/ActiveEcuC/Com/ComConfig/ACP_327_oCAN00_ffa62305_Rx] */
  { /*     5 */             11u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/ACP_327_oCAN00_ffa62305_Rx] */
  { /*     6 */              0u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6u },  /* [/ActiveEcuC/Com/ComConfig/B_RLS_oCAN00_6419d093_Rx] */
  { /*     7 */              1u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/B_RLS_oCAN00_6419d093_Rx] */
  { /*     8 */              2u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/B_RLS_oCAN00_6419d093_Rx] */
  { /*     9 */              3u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/B_RLS_oCAN00_6419d093_Rx] */
  { /*    10 */              4u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4u },  /* [/ActiveEcuC/Com/ComConfig/B_RLS_oCAN00_6419d093_Rx] */
  { /*    11 */              5u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u }   /* [/ActiveEcuC/Com/ComConfig/B_RLS_oCAN00_6419d093_Rx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeFalse
**********************************************************************************************************************/
/** 
  \var    Com_TxModeFalse
  \brief  Contains all relevant information for transmission mode false.
  \details
  Element     Description
  Periodic    TRUE if transmission mode contains a cyclic part.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxModeFalseType, COM_CONST) Com_TxModeFalse[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Periodic        Referable Keys */
  { /*     0 */     TRUE }   /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxModeInfo
  \brief  Contains all relevant information for transmission mode handling.
  \details
  Element     Description
  InitMode    Initial transmission mode selector of the Tx I-PDU.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxModeInfoType, COM_CONST) Com_TxModeInfo[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    InitMode        Referable Keys */
  { /*     0 */     TRUE }   /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeTrue
**********************************************************************************************************************/
/** 
  \var    Com_TxModeTrue
  \brief  Contains all relevant information for transmission mode true.
  \details
  Element     Description
  Periodic    TRUE if transmission mode contains a cyclic part.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxModeTrueType, COM_CONST) Com_TxModeTrue[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Periodic        Referable Keys */
  { /*     0 */     TRUE }   /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInfo
  \brief  Contains all relevant information for Tx I-PDUs.
  \details
  Element               Description
  TxPduInitValueUsed    TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInitValue
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxPduInfoType, COM_CONST) Com_TxPduInfo[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxPduInitValueUsed        Referable Keys */
  { /*     0 */               TRUE }   /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx, /ActiveEcuC/Com/ComConfig/ITMS_oCAN00_Tx_502a898a] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInitValue
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInitValue
  \brief  Initial values used for Tx I-PDU buffer initialization.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxPduInitValueType, COM_CONST) Com_TxPduInitValue[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxPduInitValue      Referable Keys */
  /*     0 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx] */
  /*     1 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx] */
  /*     2 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx] */
  /*     3 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx] */
  /*     4 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx] */
  /*     5 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx] */
  /*     6 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx] */
  /*     7 */           0x00u   /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxSigInfo
  \brief  Contains all relevant information for Tx signals and group signals.
  \details
  Element             Description
  ApplType            Application data type.
  BitLength           Bit length of the signal or group signal.
  BitPosition         Little endian bit position of the signal or group signal within the I-PDU.
  BusAcc              BUS access algorithm for signal or group signal packing / un-packing.
  ByteLength          Byte length of the signal or group signal.
  TxBufferEndIdx      the end index of the 0:n relation pointing to Com_TxBuffer
  TxBufferStartIdx    the start index of the 0:n relation pointing to Com_TxBuffer
  TxPduInfoIdx        the index of the 1:1 relation pointing to Com_TxPduInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxSigInfoType, COM_CONST) Com_TxSigInfo[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ApplType                        BitLength  BitPosition  BusAcc                          ByteLength  TxBufferEndIdx  TxBufferStartIdx  TxPduInfoIdx        Referable Keys */
  { /*     0 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,          0u,     COM_BYTE_BUSACCOFTXSIGINFO,         1u,             1u,               0u,           0u },  /* [/ActiveEcuC/Com/ComConfig/AC_max_perm_compressor_power_oITMS_350_oCAN00_ef8bdcbc_Tx, /ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx] */
  { /*     1 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1u,         24u,     COM_NBIT_BUSACCOFTXSIGINFO,         0u,             4u,               3u,           0u },  /* [/ActiveEcuC/Com/ComConfig/AllowOperation_Flag_oITMS_350_oCAN00_009f228c_Tx, /ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx] */
  { /*     2 */ COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,         56u, COM_NBYTE_SW_BUSACCOFTXSIGINFO,         2u,             8u,               6u,           0u }   /* [/ActiveEcuC/Com/ComConfig/TgtSpd_rpm_oITMS_350_oCAN00_b9dd7dcf_Tx, /ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CurrentTxMode
**********************************************************************************************************************/
/** 
  \var    Com_CurrentTxMode
  \brief  Current transmission mode state of all Tx I-PDUs.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_CurrentTxModeType, COM_VAR_NOINIT) Com_CurrentTxMode[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx, /ActiveEcuC/Com/ComConfig/ITMS_oCAN00_Tx_502a898a] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CycleTimeCnt
**********************************************************************************************************************/
/** 
  \var    Com_CycleTimeCnt
  \brief  Current counter value of cyclic transmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_CycleTimeCntType, COM_VAR_NOINIT) Com_CycleTimeCnt[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx, /ActiveEcuC/Com/ComConfig/ITMS_oCAN00_Tx_502a898a] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CyclicSendRequest
**********************************************************************************************************************/
/** 
  \var    Com_CyclicSendRequest
  \brief  Cyclic send request flag used to indicate cyclic transmission mode for all Tx I-PDU.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_CyclicSendRequestType, COM_VAR_NOINIT) Com_CyclicSendRequest[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx, /ActiveEcuC/Com/ComConfig/ITMS_oCAN00_Tx_502a898a] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_DelayTimeCnt
**********************************************************************************************************************/
/** 
  \var    Com_DelayTimeCnt
  \brief  Current counter value of minimum delay counter.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_DelayTimeCntType, COM_VAR_NOINIT) Com_DelayTimeCnt[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx, /ActiveEcuC/Com/ComConfig/ITMS_oCAN00_Tx_502a898a] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_GatewayProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_GatewayProcessingISRLockCounterType, COM_VAR_NOINIT) Com_GatewayProcessingISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_HandleRxPduDeferred
**********************************************************************************************************************/
/** 
  \var    Com_HandleRxPduDeferred
  \brief  Array indicating received Rx I-PDUs to be processed deferred within the next call of Com_MainfunctionRx().
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_HandleRxPduDeferredUType, COM_VAR_NOINIT) Com_HandleRxPduDeferred;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ACP_32E_oCAN00_11d3b5e8_Rx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/ACP_327_oCAN00_ffa62305_Rx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/B_RLS_oCAN00_6419d093_Rx] */

#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_Initialized
**********************************************************************************************************************/
/** 
  \var    Com_Initialized
  \brief  Initialization state of Com. TRUE, if Com_Init() has been called, else FALSE.
*/ 
#define COM_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_InitializedType, COM_VAR_ZERO_INIT) Com_Initialized = FALSE;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RepCnt
**********************************************************************************************************************/
/** 
  \var    Com_RepCnt
  \brief  Current repetition counter value for replication of transmission requests plus one initial transmit.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RepCntType, COM_VAR_NOINIT) Com_RepCnt[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx, /ActiveEcuC/Com/ComConfig/ITMS_oCAN00_Tx_502a898a] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RepCycleCnt
**********************************************************************************************************************/
/** 
  \var    Com_RepCycleCnt
  \brief  Current counter value of repetition period for replication of transmission requests.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RepCycleCntType, COM_VAR_NOINIT) Com_RepCycleCnt[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx, /ActiveEcuC/Com/ComConfig/ITMS_oCAN00_Tx_502a898a] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeadlineMonitoringISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxDeadlineMonitoringISRLockCounterType, COM_VAR_NOINIT) Com_RxDeadlineMonitoringISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDefPduBuffer
**********************************************************************************************************************/
/** 
  \var    Com_RxDefPduBuffer
  \brief  Rx I-PDU buffer for deferred signal processing.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxDefPduBufferUType, COM_VAR_NOINIT) Com_RxDefPduBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ACP_32E_oCAN00_11d3b5e8_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/ACP_32E_oCAN00_11d3b5e8_Rx] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/ACP_32E_oCAN00_11d3b5e8_Rx] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/ACP_327_oCAN00_ffa62305_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/ACP_327_oCAN00_ffa62305_Rx] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/ACP_327_oCAN00_ffa62305_Rx] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/B_RLS_oCAN00_6419d093_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/B_RLS_oCAN00_6419d093_Rx] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/B_RLS_oCAN00_6419d093_Rx] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeferredProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxDeferredProcessingISRLockCounterType, COM_VAR_NOINIT) Com_RxDeferredProcessingISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_RxIPduGroupISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_RxPduGrpActive
  \brief  Rx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxPduGrpActiveType, COM_VAR_NOINIT) Com_RxPduGrpActive[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ACP_32E_oCAN00_11d3b5e8_Rx, /ActiveEcuC/Com/ComConfig/ITMS_oCAN00_Rx_06702e0c] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/ACP_327_oCAN00_ffa62305_Rx, /ActiveEcuC/Com/ComConfig/ITMS_oCAN00_Rx_06702e0c] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/B_RLS_oCAN00_6419d093_Rx, /ActiveEcuC/Com/ComConfig/ITMS_oCAN00_Rx_06702e0c] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt16
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt16
  \brief  Rx Signal and Group Signal Buffer. (UINT16)
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxSigBufferUInt16Type, COM_VAR_NOINIT) Com_RxSigBufferUInt16[5];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/B_RLS_DewPoint_oB_RLS_oCAN00_421173c7_Rx, /ActiveEcuC/Com/ComConfig/B_RLS_DewPoint_oB_RLS_oCAN00_421173c7_Rx_RxSignalBufferRouting] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/Comp_speed_of_compressor_oACP_32E_oCAN00_c033917a_Rx, /ActiveEcuC/Com/ComConfig/Comp_speed_of_compressor_oACP_32E_oCAN00_c033917a_Rx_RxSignalBufferRouting] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/Ecomp_CompIpt_V_oACP_327_oCAN00_c7006e5a_Rx, /ActiveEcuC/Com/ComConfig/Ecomp_CompIpt_V_oACP_327_oCAN00_c7006e5a_Rx_RxSignalBufferRouting] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/Ecomp_Complpt_A_oACP_327_oCAN00_ea282991_Rx, /ActiveEcuC/Com/ComConfig/Ecomp_Complpt_A_oACP_327_oCAN00_ea282991_Rx_RxSignalBufferRouting] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/Ecomp_InvSoftwareVer_oACP_327_oCAN00_4030e33b_Rx, /ActiveEcuC/Com/ComConfig/Ecomp_InvSoftwareVer_oACP_327_oCAN00_4030e33b_Rx_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt8
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt8
  \brief  Rx Signal and Group Signal Buffer. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxSigBufferUInt8Type, COM_VAR_NOINIT) Com_RxSigBufferUInt8[7];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/B_RLS_Offline_Calibration_Result_oB_RLS_oCAN00_f4cfd300_Rx, /ActiveEcuC/Com/ComConfig/B_RLS_Offline_Calibration_Result_oB_RLS_oCAN00_f4cfd300_Rx_RxSignalBufferRouting] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/B_RLS_SolarLeft_oB_RLS_oCAN00_3b2a55ba_Rx, /ActiveEcuC/Com/ComConfig/B_RLS_SolarLeft_oB_RLS_oCAN00_3b2a55ba_Rx_RxSignalBufferRouting] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/B_RLS_SolarRight_oB_RLS_oCAN00_6bd7c4e8_Rx, /ActiveEcuC/Com/ComConfig/B_RLS_SolarRight_oB_RLS_oCAN00_6bd7c4e8_Rx_RxSignalBufferRouting] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/B_RLS_WindshieldTemp_oB_RLS_oCAN00_6dbe9061_Rx, /ActiveEcuC/Com/ComConfig/B_RLS_WindshieldTemp_oB_RLS_oCAN00_6dbe9061_Rx_RxSignalBufferRouting] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/B_RLS_relativeHumidity_oB_RLS_oCAN00_e615f445_Rx, /ActiveEcuC/Com/ComConfig/B_RLS_relativeHumidity_oB_RLS_oCAN00_e615f445_Rx_RxSignalBufferRouting] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/Comp_error_code1_oACP_32E_oCAN00_b5915ac1_Rx, /ActiveEcuC/Com/ComConfig/Comp_error_code1_oACP_32E_oCAN00_b5915ac1_Rx_RxSignalBufferRouting] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/Comp_work_status_oACP_32E_oCAN00_1667710c_Rx, /ActiveEcuC/Com/ComConfig/Comp_work_status_oACP_32E_oCAN00_1667710c_Rx_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TransmitRequest
**********************************************************************************************************************/
/** 
  \var    Com_TransmitRequest
  \brief  Transmit request flag used for decoupled Tx I-PDU tranmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TransmitRequestType, COM_VAR_NOINIT) Com_TransmitRequest[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx, /ActiveEcuC/Com/ComConfig/ITMS_oCAN00_Tx_502a898a] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxBuffer
**********************************************************************************************************************/
/** 
  \var    Com_TxBuffer
  \brief  Shared uint8 buffer for Tx I-PDUs and ComSignalGroup shadow buffer.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxBufferType, COM_VAR_NOINIT) Com_TxBuffer[8];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx, /ActiveEcuC/Com/ComConfig/AC_max_perm_compressor_power_oITMS_350_oCAN00_ef8bdcbc_Tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx, /ActiveEcuC/Com/ComConfig/AllowOperation_Flag_oITMS_350_oCAN00_009f228c_Tx] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx, /ActiveEcuC/Com/ComConfig/TgtSpd_rpm_oITMS_350_oCAN00_b9dd7dcf_Tx] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx, /ActiveEcuC/Com/ComConfig/TgtSpd_rpm_oITMS_350_oCAN00_b9dd7dcf_Tx] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxCyclicProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxCyclicProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxCyclicProcessingISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxDeadlineMonitoringISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxDeadlineMonitoringISRLockCounterType, COM_VAR_NOINIT) Com_TxDeadlineMonitoringISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_TxIPduGroupISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_TxPduGrpActive
  \brief  Tx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxPduGrpActiveType, COM_VAR_NOINIT) Com_TxPduGrpActive[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx, /ActiveEcuC/Com/ComConfig/ITMS_oCAN00_Tx_502a898a] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxProcessingISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSduLength
**********************************************************************************************************************/
/** 
  \var    Com_TxSduLength
  \brief  This var Array contains the Com Ipdu Length.
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxSduLengthType, COM_VAR_NOINIT) Com_TxSduLength[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ITMS_350_oCAN00_8869cfa0_Tx, /ActiveEcuC/Com/ComConfig/ITMS_oCAN00_Tx_502a898a] */

#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/



/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/






/**********************************************************************************************************************
  END OF FILE: Com_Lcfg.c
**********************************************************************************************************************/

