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
 *          File:  TSC_CtMDA_Control_Logic.h
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
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpBodyAccZ_BodyAcc(BodyAcc *data);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpIMU_IMUAcc(IMUAcc *data);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpIMU_IMUAngle(IMUAngle *data);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpIMU_IMURate(IMURate *data);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpIMU_IMUVel(IMUVel *data);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpMotFLAct_MotFLAct(MotActFL *data);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpMotFRAct_MotFRAct(MotActFR *data);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpMotRLAct_MotRLAct(MotActRL *data);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpMotRRAct_MotRRAct(MotActRR *data);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpPedlPos_PedlPos(PedlPos *data);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpPressure_Pressure(Pressure *data);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpSteerWhl_SteerWhl(SteerWhl *data);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpSuspHeight_SuspHeight(SuspHeight *data);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpVelFbAll_VlvFL(VlvActFL *data);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpVelFbAll_VlvFR(VlvActFR *data);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpVelFbAll_VlvRL(VlvActRL *data);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpVelFbAll_VlvRR(VlvActRR *data);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Read_PpWhlAccZ_WhlAcc(WhlAcc *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Write_PpMotTgtOutFL_MotTgtOutFL(const MotTgtOutFL *data);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Write_PpMotTgtOutFR_MotTgtOutFR(const MotTgtOutFR *data);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Write_PpMotTgtOutRL_MotTgtOutRL(const MotTgtOutRL *data);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Write_PpMotTgtOutRR_MotTgtOutRR(const MotTgtOutRR *data);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Write_PpVlvTgtCCFF_VlvTgtChannel(uint8 data);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Write_PpVlvTgtCCFF_VlvTgtCurrent(const VlvTgtCurrent *data);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Write_PpVlvTgtCCFF_VlvTgtFlutter(const VlvTgtFlutter *data);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Write_PpVlvTgtCCFF_VlvTgtFrequency(const VlvTgtFrequency *data);

/** Client server interfaces */
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Call_PoPT2000_Ctrl_PT2000_Enable_mode(uint8 Ch_number, uint8 Mode);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Call_PoPT2000_Ctrl_PT2000_Init(uint8 init);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Call_PoPT2000_Ctrl_PT2000_Mode_Change(uint8 Ch_number, uint8 Mode_Change);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Call_PoPT2000_Ctrl_Set_ConstantCurrent(uint8 ChannelID, uint16 Current, uint16 Frequency, uint16 Flutter);
Std_ReturnType TSC_CtMDA_Control_Logic_Rte_Call_PoPT2000_Ctrl_Set_Peak_Hold(uint8 ChannelID, uint16 IboostB, uint16 tbias_tot, uint16 tbias_off, uint16 ibias, uint16 iboostP, uint16 tpeak_tot, uint16 tpeak_off, uint16 ipeak, uint16 tbypass, uint16 thold_tot, uint16 thold_off, uint16 ihold, uint16 fwtimeOFF);




