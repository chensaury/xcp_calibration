/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  TSC_BswM.h
 *        Config:  Bsw_Project.dpa
 *   ECU-Project:  MDA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - explicit read services */
Std_ReturnType TSC_BswM_Rte_Read_Request_ESH_PostRunRequest_0_requestedMode(BswM_ESH_RunRequest *data);
Std_ReturnType TSC_BswM_Rte_Read_Request_ESH_PostRunRequest_1_requestedMode(BswM_ESH_RunRequest *data);
Std_ReturnType TSC_BswM_Rte_Read_Request_ESH_RunRequest_0_requestedMode(BswM_ESH_RunRequest *data);
Std_ReturnType TSC_BswM_Rte_Read_Request_ESH_RunRequest_1_requestedMode(BswM_ESH_RunRequest *data);

/** Mode switches */
BswM_ESH_Mode TSC_BswM_Rte_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode(void);
Std_ReturnType TSC_BswM_Rte_Switch_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode(BswM_ESH_Mode mode);




