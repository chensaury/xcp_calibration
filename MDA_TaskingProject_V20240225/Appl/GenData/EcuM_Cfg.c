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
 *              File: EcuM_Cfg.c
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




/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* PRQA S 0310 EOF */ /* MD_CSL_0310 */
#include "EcuM_Cbk.h"

#define ECUM_PRIVATE_CFG_PARTLY_INCLUDE
#include "EcuM_PrivateCfg.h"
#undef ECUM_PRIVATE_CFG_PARTLY_INCLUDE /* PRQA S 0841 */ /* MD_EcuM_0841 */

#if((ECUM_CHANNELOFWAKEUPSOURCELIST == STD_ON) ||(ECUM_PNCOFCOMMPNCS == STD_ON) || (ECUM_SUPPORT_COMM == STD_ON))
#include "ComM.h"
#endif

#if defined(STATIC)
#else
# define STATIC static
#endif


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
#define ECUM_START_SEC_VAR_PARTITION_SYSTEMAPPLICATION_OSCORE0_NOCACHE_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
ECUM_LOCAL VAR(EcuM_CoreStatusType, ECUM_VAR_NOINIT) EcuM_CoreStatus_SystemApplication_OsCore0;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_VAR_PARTITION_SYSTEMAPPLICATION_OSCORE0_NOCACHE_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
#define ECUM_START_SEC_VAR_PARTITION_SYSTEMAPPLICATION_OSCORE1_NOCACHE_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
ECUM_LOCAL VAR(EcuM_CoreStatusType, ECUM_VAR_NOINIT) EcuM_CoreStatus_SystemApplication_OsCore1;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_VAR_PARTITION_SYSTEMAPPLICATION_OSCORE1_NOCACHE_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
#define ECUM_START_SEC_VAR_PARTITION_SYSTEMAPPLICATION_OSCORE2_NOCACHE_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
ECUM_LOCAL VAR(EcuM_CoreStatusType, ECUM_VAR_NOINIT) EcuM_CoreStatus_SystemApplication_OsCore2;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_VAR_PARTITION_SYSTEMAPPLICATION_OSCORE2_NOCACHE_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
#define ECUM_START_SEC_VAR_PARTITION_SYSTEMAPPLICATION_OSCORE3_NOCACHE_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
ECUM_LOCAL VAR(EcuM_CoreStatusType, ECUM_VAR_NOINIT) EcuM_CoreStatus_SystemApplication_OsCore3;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_VAR_PARTITION_SYSTEMAPPLICATION_OSCORE3_NOCACHE_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
#define ECUM_START_SEC_VAR_PARTITION_SYSTEMAPPLICATION_OSCORE4_NOCACHE_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
ECUM_LOCAL VAR(EcuM_CoreStatusType, ECUM_VAR_NOINIT) EcuM_CoreStatus_SystemApplication_OsCore4;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_VAR_PARTITION_SYSTEMAPPLICATION_OSCORE4_NOCACHE_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
#define ECUM_START_SEC_VAR_PARTITION_SYSTEMAPPLICATION_OSCORE5_NOCACHE_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
ECUM_LOCAL VAR(EcuM_CoreStatusType, ECUM_VAR_NOINIT) EcuM_CoreStatus_SystemApplication_OsCore5;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_VAR_PARTITION_SYSTEMAPPLICATION_OSCORE5_NOCACHE_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

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
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  EcuM_CoreStatus
**********************************************************************************************************************/
/** 
  \var    EcuM_CoreStatus
  \brief  Stores status of each core.
*/ 
#define ECUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_CoreStatusArrayType, ECUM_CONST) EcuM_CoreStatus[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CoreStatus                                  */
  /*     0 */ &EcuM_CoreStatus_SystemApplication_OsCore0 ,
  /*     1 */ &EcuM_CoreStatus_SystemApplication_OsCore1 ,
  /*     2 */ &EcuM_CoreStatus_SystemApplication_OsCore2 ,
  /*     3 */ &EcuM_CoreStatus_SystemApplication_OsCore3 ,
  /*     4 */ &EcuM_CoreStatus_SystemApplication_OsCore4 ,
  /*     5 */ &EcuM_CoreStatus_SystemApplication_OsCore5 
};
#define ECUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_DriverInitOne
**********************************************************************************************************************/
/** 
  \var    EcuM_DriverInitOne
  \details
  Element     Description
  Function
*/ 
#define ECUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_DriverInitOneType, ECUM_CONST) EcuM_DriverInitOne[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Function              */
  { /*     0 */ EcuM_AL_DriverInitOne }
};
#define ECUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_PartitionInit
**********************************************************************************************************************/
/** 
  \var    EcuM_PartitionInit
  \brief  Contains all parameters configured for initialization of partitions.
  \details
  Element        Description
  Application    
*/ 
#define ECUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_PartitionInitType, ECUM_CONST) EcuM_PartitionInit[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Application               */
  { /*     0 */ SystemApplication_OsCore0 },
  { /*     1 */ SystemApplication_OsCore1 },
  { /*     2 */ SystemApplication_OsCore2 },
  { /*     3 */ SystemApplication_OsCore3 },
  { /*     4 */ SystemApplication_OsCore4 },
  { /*     5 */ SystemApplication_OsCore5 }
};
#define ECUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_WakeupSourceList
**********************************************************************************************************************/
/** 
  \var    EcuM_WakeupSourceList
  \brief  Contains all parameters configured for Wakeup Sources
  \details
  Element    Description
  Channel    Mapped ComM channel number - 255 if no ComM channel is assigned.
*/ 
#define ECUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_WakeupSourceListType, ECUM_CONST) EcuM_WakeupSourceList[11] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Channel                                                          Comment                                            Referable Keys */
  { /*     0 */ 255                                                       },  /* [ECUM_WKSOURCE_POWER]                  */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_POWER, ECUM_WKSOURCE_POWER] */
  { /*     1 */ 255                                                       },  /* [ECUM_WKSOURCE_RESET]                  */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_RESET, ECUM_WKSOURCE_RESET] */
  { /*     2 */ 255                                                       },  /* [ECUM_WKSOURCE_INTERNAL_RESET]         */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_INTERNAL_RESET, ECUM_WKSOURCE_INTERNAL_RESET] */
  { /*     3 */ 255                                                       },  /* [ECUM_WKSOURCE_INTERNAL_WDG]           */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_INTERNAL_WDG, ECUM_WKSOURCE_INTERNAL_WDG] */
  { /*     4 */ 255                                                       },  /* [ECUM_WKSOURCE_EXTERNAL_WDG]           */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_EXTERNAL_WDG, ECUM_WKSOURCE_EXTERNAL_WDG] */
  { /*     5 */ ComMConf_ComMChannel_CN_CAN00_8c3ac689                    },  /* [CN_CAN00_8c3ac689]                    */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/CN_CAN00_8c3ac689, CN_CAN00_8c3ac689] */
  { /*     6 */ ComMConf_ComMChannel_CN_Schaeffler_MDA_CANFD_c149c45e     },  /* [CN_Schaeffler_MDA_CANFD_c149c45e]     */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/CN_Schaeffler_MDA_CANFD_c149c45e, CN_Schaeffler_MDA_CANFD_c149c45e] */
  { /*     7 */ ComMConf_ComMChannel_CN_Schaeffler_MotorFL_CANFD_b5523491 },  /* [CN_Schaeffler_MotorFL_CANFD_b5523491] */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/CN_Schaeffler_MotorFL_CANFD_b5523491, CN_Schaeffler_MotorFL_CANFD_b5523491] */
  { /*     8 */ ComMConf_ComMChannel_CN_Schaeffler_MotorFR_CANFD_82b3d302 },  /* [CN_Schaeffler_MotorFR_CANFD_82b3d302] */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/CN_Schaeffler_MotorFR_CANFD_82b3d302, CN_Schaeffler_MotorFR_CANFD_82b3d302] */
  { /*     9 */ ComMConf_ComMChannel_CN_Schaeffler_MotorRL_CANFD_4da30b40 },  /* [CN_Schaeffler_MotorRL_CANFD_4da30b40] */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/CN_Schaeffler_MotorRL_CANFD_4da30b40, CN_Schaeffler_MotorRL_CANFD_4da30b40] */
  { /*    10 */ ComMConf_ComMChannel_CN_Schaeffler_MotorRR_CANFD_7a42ecd3 }   /* [CN_Schaeffler_MotorRR_CANFD_7a42ecd3] */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/CN_Schaeffler_MotorRR_CANFD_7a42ecd3, CN_Schaeffler_MotorRR_CANFD_7a42ecd3] */
};
#define ECUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_ModuleState
**********************************************************************************************************************/
#define ECUM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EcuM_StateType, ECUM_VAR_NOINIT) EcuM_ModuleState;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/




