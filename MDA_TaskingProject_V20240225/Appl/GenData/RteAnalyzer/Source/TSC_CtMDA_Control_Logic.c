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
 *          File:  TSC_CtMDA_Control_Logic.c
 *        Config:  Bsw_Project.dpa
 *   ECU-Project:  MDA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CtMDA_Control_Logic.h"
#include "TSC_CtMDA_Control_Logic.h"








Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpBodyAccZ_BodyAcc(BodyAcc *data)
{
  return Rte_Read_PpBodyAccZ_BodyAcc(data);
}

Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpIMU_IMUAcc(IMUAcc *data)
{
  return Rte_Read_PpIMU_IMUAcc(data);
}

Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpIMU_IMUAngle(IMUAngle *data)
{
  return Rte_Read_PpIMU_IMUAngle(data);
}

Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpIMU_IMURate(IMURate *data)
{
  return Rte_Read_PpIMU_IMURate(data);
}

Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpIMU_IMUVel(IMUVel *data)
{
  return Rte_Read_PpIMU_IMUVel(data);
}

Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpMotFLAct_MotFLAct(MotActFL *data)
{
  return Rte_Read_PpMotFLAct_MotFLAct(data);
}

Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpMotFRAct_MotFRAct(MotActFR *data)
{
  return Rte_Read_PpMotFRAct_MotFRAct(data);
}

Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpMotRLAct_MotRLAct(MotActRL *data)
{
  return Rte_Read_PpMotRLAct_MotRLAct(data);
}

Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpMotRRAct_MotRRAct(MotActRR *data)
{
  return Rte_Read_PpMotRRAct_MotRRAct(data);
}

Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpPedlPos_PedlPos(PedlPos *data)
{
  return Rte_Read_PpPedlPos_PedlPos(data);
}

Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpPressure_Pressure(Pressure *data)
{
  return Rte_Read_PpPressure_Pressure(data);
}

Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpSteerWhl_SteerWhl(SteerWhl *data)
{
  return Rte_Read_PpSteerWhl_SteerWhl(data);
}

Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpSuspHeight_SuspHeight(SuspHeight *data)
{
  return Rte_Read_PpSuspHeight_SuspHeight(data);
}

Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpVelFbAll_VlvFL(VlvActFL *data)
{
  return Rte_Read_PpVelFbAll_VlvFL(data);
}

Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpVelFbAll_VlvFR(VlvActFR *data)
{
  return Rte_Read_PpVelFbAll_VlvFR(data);
}

Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpVelFbAll_VlvRL(VlvActRL *data)
{
  return Rte_Read_PpVelFbAll_VlvRL(data);
}

Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpVelFbAll_VlvRR(VlvActRR *data)
{
  return Rte_Read_PpVelFbAll_VlvRR(data);
}

Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpWhlAccZ_WhlAcc(WhlAcc *data)
{
  return Rte_Read_PpWhlAccZ_WhlAcc(data);
}




Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Write_PpMotTgtOutFL_MotTgtOutFL(const MotTgtOutFL *data)
{
  return Rte_Write_PpMotTgtOutFL_MotTgtOutFL(data);
}

Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Write_PpMotTgtOutFR_MotTgtOutFR(const MotTgtOutFR *data)
{
  return Rte_Write_PpMotTgtOutFR_MotTgtOutFR(data);
}

Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Write_PpMotTgtOutRL_MotTgtOutRL(const MotTgtOutRL *data)
{
  return Rte_Write_PpMotTgtOutRL_MotTgtOutRL(data);
}

Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Write_PpMotTgtOutRR_MotTgtOutRR(const MotTgtOutRR *data)
{
  return Rte_Write_PpMotTgtOutRR_MotTgtOutRR(data);
}

Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Write_PpVlvTgtCCFF_VlvTgtChannel(uint8 data)
{
  return Rte_Write_PpVlvTgtCCFF_VlvTgtChannel(data);
}

Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Write_PpVlvTgtCCFF_VlvTgtCurrent(const VlvTgtCurrent *data)
{
  return Rte_Write_PpVlvTgtCCFF_VlvTgtCurrent(data);
}

Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Write_PpVlvTgtCCFF_VlvTgtFlutter(const VlvTgtFlutter *data)
{
  return Rte_Write_PpVlvTgtCCFF_VlvTgtFlutter(data);
}

Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Write_PpVlvTgtCCFF_VlvTgtFrequency(const VlvTgtFrequency *data)
{
  return Rte_Write_PpVlvTgtCCFF_VlvTgtFrequency(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Call_PoPT2000_Ctrl_PT2000_Enable_mode(uint8 Ch_number, uint8 Mode)
{
  return Rte_Call_PoPT2000_Ctrl_PT2000_Enable_mode(Ch_number, Mode);
}
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Call_PoPT2000_Ctrl_PT2000_Init(uint8 init)
{
  return Rte_Call_PoPT2000_Ctrl_PT2000_Init(init);
}
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Call_PoPT2000_Ctrl_PT2000_Mode_Change(uint8 Ch_number, uint8 Mode_Change)
{
  return Rte_Call_PoPT2000_Ctrl_PT2000_Mode_Change(Ch_number, Mode_Change);
}
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Call_PoPT2000_Ctrl_Set_ConstantCurrent(uint8 ChannelID, uint16 Current, uint16 Frequency, uint16 Flutter)
{
  return Rte_Call_PoPT2000_Ctrl_Set_ConstantCurrent(ChannelID, Current, Frequency, Flutter);
}
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Call_PoPT2000_Ctrl_Set_Peak_Hold(uint8 ChannelID, uint16 IboostB, uint16 tbias_tot, uint16 tbias_off, uint16 ibias, uint16 iboostP, uint16 tpeak_tot, uint16 tpeak_off, uint16 ipeak, uint16 tbypass, uint16 thold_tot, uint16 thold_off, uint16 ihold, uint16 fwtimeOFF)
{
  return Rte_Call_PoPT2000_Ctrl_Set_Peak_Hold(ChannelID, IboostB, tbias_tot, tbias_off, ibias, iboostP, tpeak_tot, tpeak_off, ipeak, tbypass, thold_tot, thold_off, ihold, fwtimeOFF);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */







     /* CtMDA_Control_Logic */
      /* CtMDA_Control_Logic */



