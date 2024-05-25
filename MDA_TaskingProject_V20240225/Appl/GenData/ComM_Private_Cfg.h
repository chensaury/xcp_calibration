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
 *            Module: ComM
 *           Program: MSR_Vector_SLP4
 *          Customer: Aptiv (China) Technology Company Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Aurix 2G/TC397 B-Step
 *    License Scope : The usage is restricted to CBD1900078_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: ComM_Private_Cfg.h
 *   Generation Time: 2024-01-08 16:27:30
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


#if !defined(COMM_PRIVATE_CFG_H)
#define COMM_PRIVATE_CFG_H
/* -----------------------------------------------------------------------------
    &&&~ INCLUDE
 ----------------------------------------------------------------------------- */
#include "ComM.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 MACROS_3453 */  /* MD_CSL_3453 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  ComMPCGetConstantDuplicatedRootDataMacros  ComM Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define ComM_GetChannelOfPCConfig()                                   ComM_Channel  /**< the pointer to ComM_Channel */
#define ComM_GetChannelPbOfPCConfig()                                 ComM_ChannelPb  /**< the pointer to ComM_ChannelPb */
#define ComM_GetSizeOfChannelOfPCConfig()                             6u  /**< the number of accomplishable value elements in ComM_Channel */
#define ComM_GetSizeOfChannelPbOfPCConfig()                           6u  /**< the number of accomplishable value elements in ComM_ChannelPb */
#define ComM_GetSizeOfUserByteMaskOfPCConfig()                        6u  /**< the number of accomplishable value elements in ComM_UserByteMask */
#define ComM_GetSizeOfUserOfPCConfig()                                6u  /**< the number of accomplishable value elements in ComM_User */
#define ComM_GetSizeOfUserReqFullComOfPCConfig()                      6u  /**< the number of accomplishable value elements in ComM_UserReqFullCom */
#define ComM_GetUserByteMaskOfPCConfig()                              ComM_UserByteMask  /**< the pointer to ComM_UserByteMask */
#define ComM_GetUserOfPCConfig()                                      ComM_User  /**< the pointer to ComM_User */
#define ComM_GetUserReqFullComOfPCConfig()                            ComM_UserReqFullCom  /**< the pointer to ComM_UserReqFullCom */
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCGetDataMacros  ComM Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define ComM_GetUserReqFullComEndIdxOfChannelPb(Index)                (ComM_GetChannelPbOfPCConfig()[(Index)].UserReqFullComEndIdxOfChannelPb)
#define ComM_GetUserReqFullComStartIdxOfChannelPb(Index)              (ComM_GetChannelPbOfPCConfig()[(Index)].UserReqFullComStartIdxOfChannelPb)
#define ComM_IsPncUserOfUser(Index)                                   ((ComM_GetUserOfPCConfig()[(Index)].PncUserOfUser) != FALSE)
#define ComM_GetUserByteMaskEndIdxOfUser(Index)                       (ComM_GetUserOfPCConfig()[(Index)].UserByteMaskEndIdxOfUser)
#define ComM_GetUserByteMaskStartIdxOfUser(Index)                     (ComM_GetUserOfPCConfig()[(Index)].UserByteMaskStartIdxOfUser)
#define ComM_GetChannelOfUserByteMask(Index)                          ((NetworkHandleType)ComM_GetUserByteMaskOfPCConfig()[(Index)].ChannelOfUserByteMask)
#define ComM_GetUserReqFullComIdxOfUserByteMask(Index)                (ComM_GetUserByteMaskOfPCConfig()[(Index)].UserReqFullComIdxOfUserByteMask)
#define ComM_GetUserReqFullCom(Index)                                 (ComM_GetUserReqFullComOfPCConfig()[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCGetDeduplicatedDataMacros  ComM Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define ComM_GetBusTypeOfChannel(Index)                               COMM_BUS_TYPE_CAN  /**< The channel bus type */
#define ComM_GetGwTypeOfChannel(Index)                                COMM_GATEWAY_TYPE_NONE  /**< The partial network gateway type, relevant for channels attached to coordinated partial networks */
#define ComM_GetInhibitionInitValueOfChannel(Index)                   0x00u  /**< Initial value of the inhibition status of the channel */
#define ComM_GetNmTypeOfChannel(Index)                                COMM_NONE_NMTYPEOFCHANNEL  /**< The Network Management type fo the channel */
#define ComM_GetWakeupStateOfChannel(Index)                           COMM_FULL_COM_NETWORK_REQUESTED  /**< Target channel state after a Passive Wake-up */
#define ComM_IsUserReqFullComUsedOfChannelPb(Index)                   (((TRUE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to ComM_UserReqFullCom */
#define ComM_GetSizeOfChannel()                                       ComM_GetSizeOfChannelOfPCConfig()
#define ComM_GetSizeOfChannelPb()                                     ComM_GetSizeOfChannelPbOfPCConfig()
#define ComM_GetSizeOfUser()                                          ComM_GetSizeOfUserOfPCConfig()
#define ComM_GetSizeOfUserByteMask()                                  ComM_GetSizeOfUserByteMaskOfPCConfig()
#define ComM_GetSizeOfUserReqFullCom()                                ComM_GetSizeOfUserReqFullComOfPCConfig()
#define ComM_IsUserByteMaskUsedOfUser(Index)                          (((TRUE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to ComM_UserByteMask */
#define ComM_GetClearMaskOfUserByteMask(Index)                        0xFEu  /**< Clear-mask for clearing the bit which corresponds to this user */
#define ComM_GetSetMaskOfUserByteMask(Index)                          0x01u  /**< Set-mask for setting the bit which corresponds to this user */
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCSetDataMacros  ComM Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define ComM_SetUserReqFullCom(Index, Value)                          ComM_GetUserReqFullComOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCHasMacros  ComM Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define ComM_HasChannel()                                             (TRUE != FALSE)
#define ComM_HasBusTypeOfChannel()                                    (TRUE != FALSE)
#define ComM_HasGwTypeOfChannel()                                     (TRUE != FALSE)
#define ComM_HasInhibitionInitValueOfChannel()                        (TRUE != FALSE)
#define ComM_HasNmTypeOfChannel()                                     (TRUE != FALSE)
#define ComM_HasWakeupStateOfChannel()                                (TRUE != FALSE)
#define ComM_HasChannelPb()                                           (TRUE != FALSE)
#define ComM_HasUserReqFullComEndIdxOfChannelPb()                     (TRUE != FALSE)
#define ComM_HasUserReqFullComStartIdxOfChannelPb()                   (TRUE != FALSE)
#define ComM_HasUserReqFullComUsedOfChannelPb()                       (TRUE != FALSE)
#define ComM_HasSizeOfChannel()                                       (TRUE != FALSE)
#define ComM_HasSizeOfChannelPb()                                     (TRUE != FALSE)
#define ComM_HasSizeOfUser()                                          (TRUE != FALSE)
#define ComM_HasSizeOfUserByteMask()                                  (TRUE != FALSE)
#define ComM_HasSizeOfUserReqFullCom()                                (TRUE != FALSE)
#define ComM_HasUser()                                                (TRUE != FALSE)
#define ComM_HasPncUserOfUser()                                       (TRUE != FALSE)
#define ComM_HasUserByteMaskEndIdxOfUser()                            (TRUE != FALSE)
#define ComM_HasUserByteMaskStartIdxOfUser()                          (TRUE != FALSE)
#define ComM_HasUserByteMaskUsedOfUser()                              (TRUE != FALSE)
#define ComM_HasUserByteMask()                                        (TRUE != FALSE)
#define ComM_HasChannelOfUserByteMask()                               (TRUE != FALSE)
#define ComM_HasClearMaskOfUserByteMask()                             (TRUE != FALSE)
#define ComM_HasSetMaskOfUserByteMask()                               (TRUE != FALSE)
#define ComM_HasUserReqFullComIdxOfUserByteMask()                     (TRUE != FALSE)
#define ComM_HasUserReqFullCom()                                      (TRUE != FALSE)
#define ComM_HasPCConfig()                                            (TRUE != FALSE)
#define ComM_HasChannelOfPCConfig()                                   (TRUE != FALSE)
#define ComM_HasChannelPbOfPCConfig()                                 (TRUE != FALSE)
#define ComM_HasSizeOfChannelOfPCConfig()                             (TRUE != FALSE)
#define ComM_HasSizeOfChannelPbOfPCConfig()                           (TRUE != FALSE)
#define ComM_HasSizeOfUserByteMaskOfPCConfig()                        (TRUE != FALSE)
#define ComM_HasSizeOfUserOfPCConfig()                                (TRUE != FALSE)
#define ComM_HasSizeOfUserReqFullComOfPCConfig()                      (TRUE != FALSE)
#define ComM_HasUserByteMaskOfPCConfig()                              (TRUE != FALSE)
#define ComM_HasUserOfPCConfig()                                      (TRUE != FALSE)
#define ComM_HasUserReqFullComOfPCConfig()                            (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCIncrementDataMacros  ComM Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define ComM_IncUserReqFullCom(Index)                                 ComM_GetUserReqFullCom(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCDecrementDataMacros  ComM Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define ComM_DecUserReqFullCom(Index)                                 ComM_GetUserReqFullCom(Index)--
/** 
  \}
*/ 

  /* PRQA L:MACROS_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/* Postbuild */
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 MACROS_3453 */  /* MD_CSL_3453 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:MACROS_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/* Macros for stored PNC signal data manipulation:*/

/* Evaluate if the bit for InternalPncId is set in the stored data for signal specified by InternalSignalId */
#define ComM_IsSignalStoredPncBitSet(InternalSignalId, InternalPncId) ((ComM_GetPncSignalValues(ComM_GetPncSignalValuesStartIdxOfPncSignal(InternalSignalId) + ComM_GetSignalByteIndexOfPncPb(InternalPncId)) & ComM_GetSetMaskOfPnc(InternalPncId)) > 0u)


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/* PRQA S 3451 EXTERNDECLARATIONS */ /* MD_ComM_3451 */ 
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  ComM_ChannelPb
**********************************************************************************************************************/
/** 
  \var    ComM_ChannelPb
  \brief  Contains PostBuild configuration parameters of channels
  \details
  Element                   Description
  UserReqFullComEndIdx      the end index of the 0:n relation pointing to ComM_UserReqFullCom
  UserReqFullComStartIdx    the start index of the 0:n relation pointing to ComM_UserReqFullCom
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(ComM_ChannelPbType, COMM_CONST) ComM_ChannelPb[6];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  ComM_User
**********************************************************************************************************************/
/** 
  \var    ComM_User
  \brief  Information about ComM users
  \details
  Element                 Description
  PncUser                 decides if a user is a partial network user or a direct channel user
  UserByteMaskEndIdx      the end index of the 0:n relation pointing to ComM_UserByteMask
  UserByteMaskStartIdx    the start index of the 0:n relation pointing to ComM_UserByteMask
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(ComM_UserType, COMM_CONST) ComM_User[6];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserByteMask
**********************************************************************************************************************/
/** 
  \var    ComM_UserByteMask
  \brief  Each user has N entries in this array (N = # channels attached to this user, directly or through PNC). Each entry describes a Byte Position and a Mask for storing/clearing the user request in UserReqFullCom
  \details
  Element              Description
  Channel              ID of the channel which is requested by this entry.
  UserReqFullComIdx    the index of the 1:1 relation pointing to ComM_UserReqFullCom
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(ComM_UserByteMaskType, COMM_CONST) ComM_UserByteMask[6];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserReqFullCom
**********************************************************************************************************************/
/** 
  \var    ComM_UserReqFullCom
  \brief  RAM array used to store user requests for channels as bitmasks. Each channel 'owns' 1..n bytes in this array, depending on the number of users assigned to it.
*/ 
#define COMM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(ComM_UserReqFullComType, COMM_VAR_NOINIT) ComM_UserReqFullCom[6];
#define COMM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/* PRQA L:EXTERNDECLARATIONS */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  INTERNAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIG POINTER
**********************************************************************************************************************/
#if (COMM_USE_INIT_POINTER == STD_ON)
# define COMM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"

extern P2CONST(ComM_ConfigType, AUTOMATIC, COMM_INIT_DATA) ComM_ConfigPtr;

# define COMM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"
#endif

#endif /* COMM_PRIVATE_CFG_H */

