/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  EthTrcv_GeneralTypes.h
 *        \brief  Ethernet transceiver general types header
 *
 *      \details  General types header for Ethernet Transceiver Driver
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  David Roeder                  visdrr        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2017-02-28  visdrr                Initial creation, based on EthTrcv_GeneralTypes v. 01.03.01 from 
 *                                              DrvTrans__baseEthxAsr v. 6.00.00
 *  01.01.00  2017-03-14  visdrr  FEATC-676     FEAT-2234: Ethernet Link Quality Monitoring
 *  01.01.01  2017-04-07  visdrr  ESCAN00094702 Type defines missing for backwards compatibility 
 *  01.02.00  2017-07-20  visdrr  ESCAN00095946 Split negotiation settings of Master/Slave and Speed mode
 *  01.02.01  2017-07-26  visdrr  ESCAN00096057 Re-add define for ETHTRCV_CONN_NEG_MANUAL
 *********************************************************************************************************************/
#if !defined (ETHTRCV_GENERAL_TYPES_H)
# define ETHTRCV_GENERAL_TYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "ComStack_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* ETHTRCV modes */
# define ETHTRCV_MODE_DOWN                          (0x00U)
# define ETHTRCV_MODE_ACTIVE                        (0x01U)

/* ETHTRCV link states */
# define ETHTRCV_LINK_STATE_DOWN                    (0x00U)
# define ETHTRCV_LINK_STATE_ACTIVE                  (0x01U)

/* ETHTRCV baud rates */
# define ETHTRCV_BAUD_RATE_10MBIT                   (0x00U)
# define ETHTRCV_BAUD_RATE_100MBIT                  (0x01U)
# define ETHTRCV_BAUD_RATE_1000MBIT                 (0x02U)

/* ETHTRCV duplex modes */
# define ETHTRCV_DUPLEX_MODE_HALF                   (0x00U)
# define ETHTRCV_DUPLEX_MODE_FULL                   (0x01U)

/* ETHTRCV state */
# define ETHTRCV_STATE_UNINIT                       (0x00U)
# define ETHTRCV_STATE_INIT                         (0x01U)
# define ETHTRCV_STATE_ACTIVE                       (0x02U)
# define ETHTRCV_STATE_DOWN                         (0x03U)

/* ETHTRCV wakeup types */
# define ETHTRCV_WAKEUP_NOT_SUPPORTED               (0x00U)
# define ETHTRCV_WAKEUP_BY_INTERRUPT                (0x01U)
# define ETHTRCV_WAKEUP_BY_POLLING                  (0x02U)

/* ETHTRCV wakeup modes */
# define ETHTRCV_WUM_DISABLE                        (0x00U)
# define ETHTRCV_WUM_ENABLE                         (0x01U)
# define ETHTRCV_WUM_CLEAR                          (0x02U)

/* ETHTRCV wakeup reasons */
# define ETHTRCV_WUR_NONE                           (0x00U)
# define ETHTRCV_WUR_GENERAL                        (0x01U)
# define ETHTRCV_WUR_BUS                            (0x02U)
# define ETHTRCV_WUR_INTERNAL                       (0x03U)
# define ETHTRCV_WUR_RESET                          (0x04U)
# define ETHTRCV_WUR_POWER_ON                       (0x05U)
# define ETHTRCV_WUR_PIN                            (0x06U)
# define ETHTRCV_WUR_SYSERR                         (0x07U)
/* count of AUTOSAR wakeup reasons defined for the transceiver */
# define ETHTRCV_WUR_NUM                            (0x07U)

/* Masks defining the bitpositions of the AUTOSAR wakeup reasons for type EthTrcv_WakeupReasonFlagsType. */
# define ETHTRCV_WUR_GENERAL_FLAGS_MASK             (0x01U)
# define ETHTRCV_WUR_BUS_FLAGS_MASK                 (0x02U)
# define ETHTRCV_WUR_INTERNAL_FLAGS_MASK            (0x04U)
# define ETHTRCV_WUR_RESET_FLAGS_MASK               (0x08U)
# define ETHTRCV_WUR_POWER_ON_FLAGS_MASK            (0x10U)
# define ETHTRCV_WUR_PIN_FLAGS_MASK                 (0x20U)
# define ETHTRCV_WUR_SYSERR_FLAGS_MASK              (0x40U)
# define ETHTRCV_WUR_CLEAR_MASK                     (0x00U)

/* EthTrcv wakeup inspection types */
# define ETHTRCV_ICU_CHANNEL                        (0x01U)
# define ETHTRCV_TRCV_REGISTERS                     (0x02U)
# define ETHTRCV_USER_CODE                          (0x03U)

/* ETHTRCV MII modes */
# define ETHTRCV_MII_MODE                           (0x00U)
# define ETHTRCV_LIGHT_MII_MODE                     (0x01U)
# define ETHTRCV_RMII_MODE                          (0x02U)
# define ETHTRCV_RMII_XTAL_MODE                     (0x03U)
# define ETHTRCV_GMII_MODE                          (0x04U)
# define ETHTRCV_RGMII_MODE                         (0x05U)
# define ETHTRCV_RGMII_XTAL_MODE                    (0x06U)
# define ETHTRCV_STRAPPING_CONFIG_ONLY              (0x07U)
# define ETHTRCV_DONT_CARE                          (0xFFU)

/* ETHTRCV CONN NEG modes*/
# define ETHTRCV_CONN_NEG_AUTO                      (0x00U)
# define ETHTRCV_CONN_NEG_MASTER                    (0x01U)
# define ETHTRCV_CONN_NEG_SLAVE                     (0x02U)
# define ETHTRCV_CONN_NEG_MANUAL                    (0x03U)

# define ETHTRCV_PHYS_ADDR_LEN_BYTE                 (0x06U)

/* ETHTRCV Phy Test Modes */
# define ETHTRCV_PHYTESTMODE_NONE                   (0x00U) /* Normal operation*/
# define ETHTRCV_PHYTESTMODE_1                      (0x01U) /* Test transmitter drop */
# define ETHTRCV_PHYTESTMODE_2                      (0x02U) /* Test master timing jitter */
# define ETHTRCV_PHYTESTMODE_3                      (0x03U) /* Test slave timing jitter */
# define ETHTRCV_PHYTESTMODE_4                      (0x04U) /* Test transmitter distortion */
# define ETHTRCV_PHYTESTMODE_5                      (0x05U) /* Test power spectral density */

/* ETHTRCV Phy Loopback Modes */
# define ETHTRCV_PHYLOOPBACK_NONE                   (0x00U) /* Normal operation */
# define ETHTRCV_PHYLOOPBACK_INTERNAL               (0x01U) /* Internal Loopback */
# define ETHTRCV_PHYLOOPBACK_EXTERNAL               (0x02U) /* External Loopback */
# define ETHTRCV_PHYLOOPBACK_REMOTE                 (0x03U) /* Remote loopback */

/* ETHTRCV Phy Tx Modes */
# define ETHTRCV_PHYTXMODE_NORMAL                   (0x00U) /* Normal Operation */
# define ETHTRCV_PHYTXMODE_TX_OFF                   (0x01U) /* Transmitter disabled */
# define ETHTRCV_PHYTXMODE_SCRAMBLER_OFF            (0x02U) /* Scrambler disabled */

/* ETHTRCV Cable Diagnostic Status */
# define ETHTRCV_CABLEDIAG_OK                       (0x00U) /* Cable diagnostic ok */
# define ETHTRCV_CABLEDIAG_ERROR                    (0x01U) /* Cable diagnostic failed*/
# define ETHTRCV_CABLEDIAG_SHORT                    (0x02U) /* Short circuit detected */
# define ETHTRCV_CABLEDIAG_OPEN                     (0x03U) /* Open circuit detected */
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8 EthTrcv_ModeType;
typedef uint8 EthTrcv_LinkStateType;
typedef uint8 EthTrcv_BaudRateType;
typedef uint8 EthTrcv_DuplexModeType;
typedef uint8 EthTrcv_StateType;
typedef uint8 EthTrcv_WakeupModeType;
typedef uint8 EthTrcv_WakeupReasonType;
typedef uint8 EthTrcv_WakeupReasonFlagsType;
typedef uint8 EthTrcv_WakeupInspectionType;
typedef uint8 EthTrcv_PhysAddrType[ETHTRCV_PHYS_ADDR_LEN_BYTE];
typedef uint8 EthTrcv_PhyTestModeType;
typedef uint8 EthTrcv_PhyLoopbackModeType;
typedef uint8 EthTrcv_PhyTxModeType;
typedef uint8 EthTrcv_CableDiagResultType;

#endif /* ETHTRCV_GENERAL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_GeneralTypes.h
 *********************************************************************************************************************/
