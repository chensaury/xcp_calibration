/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  EthSwt_GeneralTypes.h
 *        \brief  General Type Header of MICROSAR Ethernet Switch Driver
 *
 *      \details  The General Type Header contains the data types used.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Mark Harsch                   vismha        Vector Informatik GmbH
 *  David Fessler                 visfer        Vector Informatik GmbH
 *  Ingo Schroeck                 visink        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2016-06-20  vismha  -             Initial creation
 *  02.00.00  2016-11-28  vismha  -             Extended management info type
 *  02.01.00  2016-12-20  vismha  -             Introduced action for EthSwt_UpdateMCastPortAssignment() API
 *  02.02.00  2017-02-01  visfer  ESCAN00093815 Add ETHSWT_INVALID_PORT_IDX to EthSwitchGeneralTypes
 *  02.02.01  2017-11-23  visink  STORYC-3270   STORY-3208 Add define for invalid switch index to EthSwt_GeneralTypes.h
 *  02.02.02  2019-03-01  visink  ESCAN00102221 Missing type definitions and wrong compiler abstraction macro usage lead to compilation errors
 *********************************************************************************************************************/

#ifndef ETHSWT_GENERALTYPES_H
#define ETHSWT_GENERALTYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "ComStack_Types.h"
#include "Eth_GeneralTypes.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! \brief EthSwt_StateType values */
#define ETHSWT_STATE_UNINIT                      (0x00U)
#define ETHSWT_STATE_INIT                        (0x01U)
#define ETHSWT_STATE_ACTIVE                      (0x02U)

/*! \brief EthSwt_MacLearningType values */
#define ETHSWT_MACLEARNING_HWDISABLED            (0x00U)
#define ETHSWT_MACLEARNING_HWENABLED             (0x01U)
#define ETHSWT_MACLEARNING_SWENABLED             (0x02U)

/*! \brief EthSwt_PortModeType values */
#define ETHSWT_MODE_DOWN_SWITCHPORT              (0x00U)
#define ETHSWT_MODE_ACTIVE_SWITCHPORT            (0x01U)

/*! \brief Enumeration values for the different possible physical types of a switch port. */
#define ETHSWT_PORT_PHYS_TYPE_BROAD_R_REACH      (0U)
#define ETHSWT_PORT_PHYS_TYPE_BASE_T             (1U)
#define ETHSWT_PORT_PHYS_TYPE_RTPGE              (2U)
#define ETHSWT_PORT_PHYS_TYPE_X_MII              (3U)
#define ETHSWT_PORT_PHYS_TYPE_INTERNAL           (4U)

/*! \brief Enumeration values for the different possible speed configurations of a switch port. */
#define ETHSWT_PORT_SPEED_10_MBIT                (1U)
#define ETHSWT_PORT_SPEED_100_MBIT               (2U)
#define ETHSWT_PORT_SPEED_200_MBIT               (3U)
#define ETHSWT_PORT_SPEED_1000_MBIT              (4U)
#define ETHSWT_PORT_SPEED_DONT_CARE              (0xFFU)

/*! \brief Enumeration values for type EthSwt_MCastPortAssignActionType */
#define ETHSWT_MCAST_PORT_ASSIGN_ACTION_ADD      (0u)
#define ETHSWT_MCAST_PORT_ASSIGN_ACTION_REMOVE   (1u)

#define ETHSWT_INVALID_SWITCH_IDX                (0xFF)
#define ETHSWT_INVALID_PORT_IDX                  (0xFF)

/*! Enumeration values for type EthSwt_PortMirrorStateType */
# define ETHSWT_PORT_MIRROR_DISABLED             (0x00u)
# define ETHSWT_PORT_MIRROR_ENABLED              (0x01u)
# define ETHSWT_PORT_MIRROR_INVALID              (0x02u)

/*! Enumeration values for MirroringMode */
# define ETHSWT_MIRROR_MODE_NO_VLAN_RETAGGING     (0x00u)
# define ETHSWT_MIRROR_MODE_VLAN_RETAGGING        (0x01u)
# define ETHSWT_MIRROR_MODE_DOUBLE_VLAN_RETAGGING (0x02u)
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/* PRQA S 0342,0881 ETHSWT_GENERAL_GLUE_OPERATOR */ /* MD_MSR_19.13_0342 */

/*! \brief Macro for better readability of compiler abstraction CONSTP2CONST */
#define ETHSWT_CONSTP2CONST(DataType, Derivative) \
          CONSTP2CONST(DataType, ETHSWT_30_##Derivative##_APPL_CONST, ETHSWT_30_##Derivative##_APPL_CONST)

/*! \brief Macro for better readability of compiler abstraction CONSTP2VAR */
#define ETHSWT_CONSTP2VAR(DataType, Derivative) \
          CONSTP2VAR(DataType, ETHSWT_30_##Derivative##_APPL_CONST, ETHSWT_30_##Derivative##_APPL_VAR)

/*! \brief Macro for better readability of compiler abstraction CONSTP2VAR */
#define ETHSWT_CONSTP2VAR_WITH_MEM(DataType, MemType, Derivative) \
          CONSTP2VAR(DataType, ETHSWT_30_##Derivative##_APPL_CONST, ETHSWT_30_##Derivative##_##MemType)

/*! \brief Macro for better readability of compiler abstraction P2CONST */
#define ETHSWT_P2CONST(DataType, Derivative) \
          P2CONST(DataType, AUTOMATIC, ETHSWT_30_##Derivative##_CONST)

/*! \brief Macro for better readability of compiler abstraction P2VAR */
#define ETHSWT_P2VAR(DataType, Derivative) \
          P2VAR(DataType, AUTOMATIC, ETHSWT_30_##Derivative##_APPL_VAR)

/*! \brief Macro for better readability of compiler abstraction P2VAR */
#define ETHSWT_P2VAR_WITH_MEM(DataType, MemType, Derivative) \
          P2VAR(DataType, AUTOMATIC, ETHSWT_30_##Derivative##_##MemType)

/*! \brief Macro for better readability of compiler abstraction CONST */
#define ETHSWT_CONST(DataType, Derivative) \
          CONST(DataType, ETHSWT_30_##Derivative##_CONST)

/*! \brief Macro for better readability of compiler abstraction VAR */
#define ETHSWT_VAR(DataType, Derivative) \
          VAR(DataType, ETHSWT_30_##Derivative##_APPL_VAR)

/*! \brief Macro for better readability of compiler abstraction VAR */
#define ETHSWT_VAR_WITH_MEM(DataType, MemType, Derivative) \
          VAR(DataType, ETHSWT_30_##Derivative##_##MemType)

/*! \brief Macro for better readability of compiler abstraction FUNC */
#define ETHSWT_FUNC(RetType, Derivative) \
          FUNC(RetType, ETHSWT_30_##Derivative##_CODE)


/*! \brief Macro for better readability of start of exclusive area */
#define EthSwt_EnterExclusiveArea(Derivative, Area) \
          SchM_Enter_EthSwt_30_##Derivative##_EXCLUSIVE_AREA_##Area()

/*! \brief Macro for better readability of end of exclusive area */
#define EthSwt_ExitExclusiveArea(Derivative, Area) \
          SchM_Exit_EthSwt_30_##Derivative##_EXCLUSIVE_AREA_##Area()

/* PRQA L:ETHSWT_GENERAL_GLUE_OPERATOR */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/*! \brief Dummy type for multiple configuration. (Isn't supported by AUTOSAR at the moment) */
typedef struct
{
  uint8 DummyData; /**< dummy data because multiple configuration isn't supported */
} EthSwt_ConfigType;

/*! \brief AUTOSAR type for holding MAC address, VLAN ID and port mapping information. */
typedef struct
{
  uint8  MacAddr[6]; /**< MAC address */
  uint16 VlanId;     /**< VLAN ID */
  uint8  SwitchPort; /**< Index of the Switch Port */
} EthSwt_MacVlanType;

/*! \brief AUTOSAR type for module state. */
typedef uint8  EthSwt_StateType;

/*! \brief AUTOSAR type for switch index. */
typedef uint8  EthSwt_SwitchIdxType;

/*! \brief AUTOSAR type for port index. */
typedef uint8 EthSwt_PortIdxType;

/*! \brief AUTOSAR type for buffer level. */
typedef uint32 EthSwt_BufferLevelType;

/*! \brief AUTOSAR type for MAC learning type. */
typedef uint8 EthSwt_MacLearningType;

/*! \brief AUTOSAR type for port mode. */
typedef uint8 EthSwt_PortModeType;

/*! \brief Type for holding the management information for Ethernet frames received/transmitted on switch ports. */
typedef struct
{
  EthSwt_SwitchIdxType  SwitchIdx; /**< EthSwt switch index */
  uint8                 PortIdx;   /**< EthSwt port index */
  Eth_FrameIdType       FrameId;   /**< Eth Frame identifier */
} EthSwt_MgmtInfoType;

/*! \brief Type for defining the action that is applied during EthSwt_UpdateMCastPortAssignment() */
typedef uint8 EthSwt_MCastPortAssignActionType;

/*! Port mirroring configuration type */
typedef struct
{
  uint8    CapturePortIdx;                            /*!< Switch port which captures mirrored traffic
                                                           - symbolic name value from configuration must be used */
  uint8    srcMacAddrFilter[ETH_PHYS_ADDR_LEN_BYTE];  /*!< Source MAC address of packets which shall be mirrored */
  uint8    dstMacAddrFilter[ETH_PHYS_ADDR_LEN_BYTE];  /*!< Destination MAC address of packets which shall be mirrored */
  uint16   VlanIdFilter;                              /*!< VLAN ID of frames which shall be mirrored */
  uint8    MirroringPacketDivider;                    /*!< Limits mirrored frames: 1 -> all frames, 2 -> every second frame, ... */
  uint8    MirroringMode;                             /*!< Retagging of mirrored frames: 0x00 == no VLAN retagging,
                                                       *   0x01 == VLAN retagging, 0x02 == VLAN double retagging */
  uint16   VlanOuterTag;                              /*!< VLAN ID used for VLAN retagging or as outer tag for VLAN double retagging */
  uint16   VlanInnerTag;                              /*!< VLAN ID used as inner tag for VLAN double retagging */
  uint32   MirroredSwitchEgressPortIdxBitMask;        /*!< Bit mask defining ports where egress frames shall be mirrored
                                                           - symbolic name values from configuration must be used */
  uint32   MirroredSwitchIngressPortIdxBitMask;       /*!< Bit mask defining ports where ingress frames shall be mirrored
                                                           - symbolic name values from configuration must be used */
} EthSwt_PortMirrorCfgType;

/*! Switch port mirroring state type */
typedef uint8 EthSwt_PortMirrorStateType;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/



#endif  /* ETHSWT_GENERALTYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: EthSwt_GeneralTypes.h
 *********************************************************************************************************************/
 
