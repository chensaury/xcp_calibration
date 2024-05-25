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
 *          File:  TSC_BswM.c
 *        Config:  Bsw_Project.dpa
 *   ECU-Project:  ITMS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BswM.h"
#include "TSC_BswM.h"








Std_ReturnType TSC_BswM_Rte_Read_Request_ESH_PostRunRequest_0_requestedMode(BswM_ESH_RunRequest *data)
{
  return Rte_Read_Request_ESH_PostRunRequest_0_requestedMode(data);
}

Std_ReturnType TSC_BswM_Rte_Read_Request_ESH_PostRunRequest_1_requestedMode(BswM_ESH_RunRequest *data)
{
  return Rte_Read_Request_ESH_PostRunRequest_1_requestedMode(data);
}

Std_ReturnType TSC_BswM_Rte_Read_Request_ESH_RunRequest_0_requestedMode(BswM_ESH_RunRequest *data)
{
  return Rte_Read_Request_ESH_RunRequest_0_requestedMode(data);
}

Std_ReturnType TSC_BswM_Rte_Read_Request_ESH_RunRequest_1_requestedMode(BswM_ESH_RunRequest *data)
{
  return Rte_Read_Request_ESH_RunRequest_1_requestedMode(data);
}








     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */
BswM_ESH_Mode TSC_BswM_Rte_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode(void)
{
  return Rte_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode();
}

Std_ReturnType TSC_BswM_Rte_Switch_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode(BswM_ESH_Mode mode)
{
  return Rte_Switch_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode( mode);
}



     /* Trigger Interfaces */

     /* Inter-Runnable variables */







     /* BswM */
      /* BswM */



