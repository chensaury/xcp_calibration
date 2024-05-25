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
 *              File: Com_Cbk.h
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


#if !defined (COM_CBK_H)
# define COM_CBK_H

/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "Com_Cot.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/



/**
 * \defgroup ComHandleIdsComRxPdu Handle IDs of handle space ComRxPdu.
 * \brief Rx Pdus
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComIPdu_BecmPropFr01_oCAN00_e2f0fff8_Rx               0u
#define ComConf_ComIPdu_EcmPropFr00_oCAN00_2afbaddb_Rx                1u
#define ComConf_ComIPdu_EcmPropFr07_oCAN00_203ea4c2_Rx                2u
#define ComConf_ComIPdu_EcmPropFr24_oCAN00_80478ba7_Rx                3u
#define ComConf_ComIPdu_IemEduPropFr01_oCAN00_97fdab75_Rx             4u
#define ComConf_ComIPdu_MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_985efe2d_Rx 5u
#define ComConf_ComIPdu_MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_8b12c95b_Rx 6u
#define ComConf_ComIPdu_MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_49f811f9_Rx 7u
#define ComConf_ComIPdu_MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_5ab4268f_Rx 8u
#define ComConf_ComIPdu_MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx 9u
#define ComConf_ComIPdu_MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx 10u
#define ComConf_ComIPdu_MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx 11u
#define ComConf_ComIPdu_MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx 12u
#define ComConf_ComIPdu_MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx 13u
#define ComConf_ComIPdu_MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx 14u
#define ComConf_ComIPdu_MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx 15u
#define ComConf_ComIPdu_MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx 16u
#define ComConf_ComIPdu_MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx 17u
#define ComConf_ComIPdu_MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx 18u
#define ComConf_ComIPdu_MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx 19u
#define ComConf_ComIPdu_MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx 20u
#define ComConf_ComIPdu_MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx 21u
#define ComConf_ComIPdu_MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx 22u
#define ComConf_ComIPdu_MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx 23u
#define ComConf_ComIPdu_MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx 24u
#define ComConf_ComIPdu_MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx 25u
#define ComConf_ComIPdu_MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx 26u
#define ComConf_ComIPdu_MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx 27u
#define ComConf_ComIPdu_MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx 28u
#define ComConf_ComIPdu_TcmPropFr04_oCAN00_6f4049d8_Rx                29u
#define ComConf_ComIPdu_VddmPropFr05_oCAN00_53500d40_Rx               30u
#define ComConf_ComIPdu_VddmPropFr08_oCAN00_c8551891_Rx               31u
#define ComConf_ComIPdu_VddmPropFr09_oCAN00_04ff180f_Rx               32u
#define ComConf_ComIPdu_VddmPropFr10_oCAN00_0ccb1767_Rx               33u
#define ComConf_ComIPdu_VddmPropFr12_oCAN00_4eee101a_Rx               34u
#define ComConf_ComIPdu_VddmPropFr29_oCAN00_2a093089_Rx               35u
/**\} */

/**
 * \defgroup ComHandleIdsComTxPdu Handle IDs of handle space ComTxPdu.
 * \brief Tx Pdus
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComIPdu_MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx 0u
#define ComConf_ComIPdu_MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx 1u
#define ComConf_ComIPdu_MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx 2u
#define ComConf_ComIPdu_MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx 3u
#define ComConf_ComIPdu_MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx 4u
#define ComConf_ComIPdu_MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx 5u
#define ComConf_ComIPdu_MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx 6u
#define ComConf_ComIPdu_MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx 7u
#define ComConf_ComIPdu_MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx 8u
#define ComConf_ComIPdu_MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx  9u
#define ComConf_ComIPdu_MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx 10u
#define ComConf_ComIPdu_MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx 11u
#define ComConf_ComIPdu_MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx 12u
#define ComConf_ComIPdu_MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx 13u
#define ComConf_ComIPdu_MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx 14u
#define ComConf_ComIPdu_MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx 15u
#define ComConf_ComIPdu_MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx 16u
#define ComConf_ComIPdu_MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx 17u
#define ComConf_ComIPdu_MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx   18u
/**\} */

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define COM_START_SEC_CODE
#include "MemMap.h"    /* PRQA S 5087 1 */ /*MD_MSR_MemMap */
/**********************************************************************************************************************
  Com_RxIndication
**********************************************************************************************************************/
/** \brief    This function is called by the lower layer after an I-PDU has been received.
    \param    RxPduId      ID of AUTOSAR COM I-PDU that has been received. Identifies the data that has been received.
                              Range: 0..(maximum number of I-PDU IDs received by AUTOSAR COM) - 1
    \param    PduInfoPtr      Payload information of the received I-PDU (pointer to data and data length).
    \return   none
    \context  The function can be called on interrupt and task level. It is not allowed to use CAT1 interrupts with Rte (BSW00326]). Due to this, the interrupt context shall be configured to a CAT2 interrupt if an Rte is used. 
    \synchronous TRUE
    \reentrant   TRUE, for different Handles
    \trace    SPEC-2737026
    \note     The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_RxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/**********************************************************************************************************************
  Com_TxConfirmation
**********************************************************************************************************************/
/** \brief    This function is called by the lower layer after the PDU has been transmitted on the network.
              A confirmation that is received for an I-PDU that does not require a confirmation is silently discarded.
    \param    TxPduId    ID of AUTOSAR COM I-PDU that has been transmitted.
                            Range: 0..(maximum number of I-PDU IDs transmitted by AUTOSAR COM) - 1
    \return   none
    \context  The function can be called on interrupt and task level. It is not allowed to use CAT1 interrupts with Rte (BSW00326]). Due to this, the interrupt context shall be configured to a CAT2 interrupt if an Rte is used. 
    \synchronous TRUE
    \reentrant   TRUE, for different Handles
    \trace    SPEC-2737028
    \note     The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_TxConfirmation(PduIdType TxPduId);



#define COM_STOP_SEC_CODE
#include "MemMap.h"    /* PRQA S 5087 1 */ /* MD_MSR_MemMap */

#endif  /* COM_CBK_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cbk.h
**********************************************************************************************************************/

