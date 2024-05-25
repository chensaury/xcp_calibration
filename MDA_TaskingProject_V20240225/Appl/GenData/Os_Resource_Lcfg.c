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
 *            Module: Os
 *           Program: MSR_Vector_SLP4
 *          Customer: Aptiv (China) Technology Company Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Aurix 2G/TC397 B-Step
 *    License Scope : The usage is restricted to CBD1900078_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Resource_Lcfg.c
 *   Generation Time: 2024-01-08 16:27:32
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

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_RESOURCE_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Resource_Lcfg.h"
#include "Os_Resource.h"

/* Os kernel module dependencies */
#include "Os_Application_Lcfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"

/* Os hal dependencies */
#include "Os_Hal_Interrupt_Lcfg.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic resource data: RES_SCHEDULER_OsCore0 */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_RES_SCHEDULER_OsCore0_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic resource data: RES_SCHEDULER_OsCore1 */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_RES_SCHEDULER_OsCore1_Dyn;

#define OS_STOP_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic resource data: RES_SCHEDULER_OsCore2 */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_RES_SCHEDULER_OsCore2_Dyn;

#define OS_STOP_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE3_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic resource data: RES_SCHEDULER_OsCore3 */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_RES_SCHEDULER_OsCore3_Dyn;

#define OS_STOP_SEC_CORE3_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE4_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic resource data: RES_SCHEDULER_OsCore4 */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_RES_SCHEDULER_OsCore4_Dyn;

#define OS_STOP_SEC_CORE4_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE5_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic resource data: RES_SCHEDULER_OsCore5 */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_RES_SCHEDULER_OsCore5_Dyn;

#define OS_STOP_SEC_CORE5_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Resource configuration data: RES_SCHEDULER_OsCore0 */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_RES_SCHEDULER_OsCore0 =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_RES_SCHEDULER_OsCore0_Dyn),
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore0,
  /* .ResourceId      = */ RES_SCHEDULER_OsCore0,
  /* .CeilingPriority = */ 0
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Resource configuration data: RES_SCHEDULER_OsCore1 */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_RES_SCHEDULER_OsCore1 =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_RES_SCHEDULER_OsCore1_Dyn),
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore1),
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore1,
  /* .ResourceId      = */ RES_SCHEDULER_OsCore1,
  /* .CeilingPriority = */ 0
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Resource configuration data: RES_SCHEDULER_OsCore2 */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_RES_SCHEDULER_OsCore2 =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_RES_SCHEDULER_OsCore2_Dyn),
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore2),
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore2,
  /* .ResourceId      = */ RES_SCHEDULER_OsCore2,
  /* .CeilingPriority = */ 0
};

#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE3_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Resource configuration data: RES_SCHEDULER_OsCore3 */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_RES_SCHEDULER_OsCore3 =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_RES_SCHEDULER_OsCore3_Dyn),
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore3),
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore3,
  /* .ResourceId      = */ RES_SCHEDULER_OsCore3,
  /* .CeilingPriority = */ 0
};

#define OS_STOP_SEC_CORE3_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE4_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Resource configuration data: RES_SCHEDULER_OsCore4 */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_RES_SCHEDULER_OsCore4 =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_RES_SCHEDULER_OsCore4_Dyn),
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore4),
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore4,
  /* .ResourceId      = */ RES_SCHEDULER_OsCore4,
  /* .CeilingPriority = */ 0
};

#define OS_STOP_SEC_CORE4_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE5_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Resource configuration data: RES_SCHEDULER_OsCore5 */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_RES_SCHEDULER_OsCore5 =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_RES_SCHEDULER_OsCore5_Dyn),
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore5),
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore5,
  /* .ResourceId      = */ RES_SCHEDULER_OsCore5,
  /* .CeilingPriority = */ 0
};

#define OS_STOP_SEC_CORE5_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for resources. */
CONSTP2CONST(Os_ResourceConfigType, OS_CONST, OS_CONST) OsCfg_ResourceRefs[OS_RESOURCEID_COUNT + 1] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_RES_SCHEDULER_OsCore0),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_RES_SCHEDULER_OsCore1),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_RES_SCHEDULER_OsCore2),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_RES_SCHEDULER_OsCore3),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_RES_SCHEDULER_OsCore4),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_RES_SCHEDULER_OsCore5),
  NULL_PTR
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Resource_Lcfg.c
 *********************************************************************************************************************/
