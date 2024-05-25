/*
 * File: CtMDA_Control_Logic.c
 *
 * Code generated for Simulink model 'CtMDA_Control_Logic'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Nov 10 11:54:47 2023
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CtMDA_Control_Logic.h"
#include <math.h>
#include "Rte_Type.h"
//#include "rtwtypes.h"
#include "CtMDA_Control_Logic_private.h"
#include "Dio.h"
#include "Com.h"
#include "AppPT2000.h"
#include "Com_Cfg.h"


//测量量声明
#pragma section all "calibration_parameter_mes_cal"
volatile uint16  mes_0;
uint16  mes_1;
#pragma section all restore

//标定量声明
#pragma section all "calibration_parameter_wp_cal"
volatile uint16  calibration_P0 = 0x4567;
uint16  calibration_P1 = 0x4567;
#pragma section all restore




extern Channel channel_get_value ;



const MotTgtOutFL CtMDA_Control_Logic_rtZA_MotTgtOutFL = {
  0.0F,                                /* float32 */
  0U,                                  /* uint8 */
  0U,                                  /* uint8 */
  0.0F                                 /* float32 */
} ;                                    /* MotTgtOutFL ground */

const MotTgtOutFR CtMDA_Control_Logic_rtZA_MotTgtOutFR = {
  0.0F,                                /* float32 */
  0U,                                  /* uint8 */
  0U,                                  /* uint8 */
  0.0F                                 /* float32 */
} ;                                    /* MotTgtOutFR ground */

const MotTgtOutRL CtMDA_Control_Logic_rtZA_MotTgtOutRL = {
  0U,                                  /* uint8 */
  0U,                                  /* uint8 */
  0U,                                  /* uint8 */
  0.0F                                 /* float32 */
} ;                                    /* MotTgtOutRL ground */

const MotTgtOutRR CtMDA_Control_Logic_rtZA_MotTgtOutRR = {
  0U,                                  /* uint8 */
  0U,                                  /* uint8 */
  0U,                                  /* uint8 */
  0.0F                                 /* float32 */
} ;                                    /* MotTgtOutRR ground */

const VlvTgtCurrent CtMDA_Control_Logic_rtZA_VlvTgtCurrent = {
  0U,                                  /* uint16 */
  0U,                                  /* uint16 */
  0U,                                  /* uint16 */
  0U,                                  /* uint16 */
  0U,                                  /* uint16 */
  0U,                                  /* uint16 */
  0U,                                  /* uint16 */
  0U                                   /* uint16 */
} ;                                    /* VlvTgtCurrent ground */

const VlvTgtFlutter CtMDA_Control_Logic_rtZVlvTgtFlutter = {
  0U,                                  /* VlvTgtFlutterFL1 */
  0U,                                  /* VlvTgtFlutterFL2 */
  0U,                                  /* VlvTgtFlutterFR1 */
  0U,                                  /* VlvTgtFlutterFR2 */
  0U,                                  /* VlvTgtFlutterRL1 */
  0U,                                  /* VlvTgtFlutterRL2 */
  0U,                                  /* VlvTgtFlutterRR1 */
  0U                                   /* VlvTgtFlutterRR2 */
} ;                                    /* VlvTgtFlutter ground */

const VlvTgtFrequency CtMDA_Control_Logic_rtZVlvTgtFrequency = {
  0U,                                  /* VlvTgtFrequencyFL1 */
  0U,                                  /* VlvTgtFrequencyFL2 */
  0U,                                  /* VlvTgtFrequencyFR1 */
  0U,                                  /* VlvTgtFrequencyFR2 */
  0U,                                  /* VlvTgtFrequencyRL1 */
  0U,                                  /* VlvTgtFrequencyRL2 */
  0U,                                  /* VlvTgtFrequencyRR1 */
  0U                                   /* VlvTgtFrequencyRR2 */
} ;                                    /* VlvTgtFrequency ground */

/* Block states (default storage) */
DW_CtMDA_Control_Logic_T CtMDA_Control_Logic_DW;

/* Model step function for TID1 */
void MDA_Control_Logic(void)           /* Explicit Task: MDA_Control_Logic */
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/MDA_Control_Logic' incorporates:
   *  SubSystem: '<Root>/MDA_Control_Logic_sys'
   */
  /* FunctionCaller: '<S2>/PoPT2000_Ctrl_PT2000_Mode_Change' incorporates:
   *  Constant: '<S2>/Constant'
   *
   * Block description for '<S2>/PoPT2000_Ctrl_PT2000_Mode_Change':
   *  电磁阀模式转换
   */


  /* FunctionCaller: '<S2>/PoPT2000_Ctrl_Set_ConstantCurrent' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant3'
   *  Gain: '<S2>/Gain'
   *  Product: '<S2>/Divide'
   *  UnitDelay: '<S3>/Output'
   *
   * Block description for '<S2>/PoPT2000_Ctrl_Set_ConstantCurrent':
   *  // 恒流赋值
   */
  static uint16 i = 0;
  static uint32 j = 0;
//  Rte_Call_PoPT2000_Ctrl_Set_ConstantCurrent(1, 500, 2000, 75);


  /* Switch: '<S12>/FixPt Switch' incorporates:
   *  Constant: '<S11>/FixPt Constant'
   *  Constant: '<S12>/Constant'
   *  Sum: '<S11>/FixPt Sum1'
   *  UnitDelay: '<S3>/Output'
   */

//电磁阀0.1A步进测试
//  j++;
//
//
//  if(j <= 5000)
//  {
//	  if(j%100 == 0)
//	  {
//		  if(i <= 1800)
//		  {
//			  i = i+100;
//		  }
//		  else
//		  {
//			  i = 0;
//		  }
//		  Rte_Call_PoPT2000_Ctrl_Set_ConstantCurrent(1, i, 2000, 75);
//	  }
//  }
//
//  if((j>5000)&&(j <= 10000))
//  {
//	  if(j%100 == 0)
//	  {
//		  if(i <= 1800)
//		  {
//			  i = i+100;
//		  }
//		  else
//		  {
//			  i = 0;
//		  }
//		  Rte_Call_PoPT2000_Ctrl_Set_ConstantCurrent(1, i, 2000, 75);
//	  }
//  }
//   if(j>10000)
//  {
//	  j = 0;
//  }
//
//
//
//  /* End of Switch: '<S12>/FixPt Switch' */
//
//  /* FunctionCaller: '<S2>/PoPT2000_Ctrl_PT2000_Enable_mode'
//   *
//   * Block description for '<S2>/PoPT2000_Ctrl_PT2000_Enable_mode':
//   *  //START 使能 开启电磁阀 1- 16
//   *
//   */
//
//   if(j>3000)
//   {
//// 	  Rte_Call_PoPT2000_Ctrl_PT2000_Enable_mode(3, 1);
////	  Rte_Call_PoPT2000_Ctrl_PT2000_Enable_mode(2, 1);
////	  Rte_Call_PoPT2000_Ctrl_PT2000_Enable_mode(1, 1);
//   }



  /* FunctionCaller: '<S2>/PoPT2000_Ctrl_Set_Peak_Hold' */
//  Rte_Call_PoPT2000_Ctrl_Set_Peak_Hold(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

  /* FunctionCaller: '<S2>/PoPT2000_Ctrl_PT2000_Init'
   *
   * Block description for '<S2>/PoPT2000_Ctrl_PT2000_Init':
   *  //初始化
   */
  Rte_Call_PoPT2000_Ctrl_PT2000_Init(0);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/MDA_Control_Logic' */

//  /* Outport: '<Root>/PpMotTgtOutFL_MotTgtOutFL' */
//  (void)E2EPW_Write_PpMotTgtOutFL_MotTgtOutFL
//    (&CtMDA_Control_Logic_rtZA_MotTgtOutFL);
//
//  /* Outport: '<Root>/PpMotTgtOutFR_MotTgtOutFR' */
//  (void)E2EPW_Write_PpMotTgtOutFR_MotTgtOutFR
//    (&CtMDA_Control_Logic_rtZA_MotTgtOutFR);
//
//  /* Outport: '<Root>/PpMotTgtOutRL_MotTgtOutRL' */
//  (void)E2EPW_Write_PpMotTgtOutRL_MotTgtOutRL
//    (&CtMDA_Control_Logic_rtZA_MotTgtOutRL);
//
//  /* Outport: '<Root>/PpMotTgtOutRR_MotTgtOutRR' */
//  (void)E2EPW_Write_PpMotTgtOutRR_MotTgtOutRR
//    (&CtMDA_Control_Logic_rtZA_MotTgtOutRR);
//
//  /* Outport: '<Root>/PpVlvTgtCCFF_VlvTgtChannel' */
//  (void)E2EPW_Write_PpVlvTgtCCFF_VlvTgtChannel(0U);
//
//  /* Outport: '<Root>/PpVlvTgtCCFF_VlvTgtCurrent' */
//  (void)E2EPW_Write_PpVlvTgtCCFF_VlvTgtCurrent
//    (&CtMDA_Control_Logic_rtZA_VlvTgtCurrent);
//
//  /* Outport: '<Root>/PpVlvTgtCCFF_VlvTgtFlutter' */
//  (void)E2EPW_Write_PpVlvTgtCCFF_VlvTgtFlutter
//    (&CtMDA_Control_Logic_rtZVlvTgtFlutter);
//
//  /* Outport: '<Root>/PpVlvTgtCCFF_VlvTgtFrequency' */
//  (void)E2EPW_Write_PpVlvTgtCCFF_VlvTgtFrequency
//    (&CtMDA_Control_Logic_rtZVlvTgtFrequency);
}

/* Model initialize function */
void CtMDA_Control_Logic_Init(void)
{
//  /* End-to-End (E2E) initialization */
//  E2EPW_WriteInit_PpMotTgtOutFL_MotTgtOutFL();
//  E2EPW_WriteInit_PpMotTgtOutFR_MotTgtOutFR();
//  E2EPW_WriteInit_PpMotTgtOutRL_MotTgtOutRL();
//  E2EPW_WriteInit_PpMotTgtOutRR_MotTgtOutRR();
//  E2EPW_WriteInit_PpVlvTgtCCFF_VlvTgtChannel();
//  E2EPW_WriteInit_PpVlvTgtCCFF_VlvTgtCurrent();
//  E2EPW_WriteInit_PpVlvTgtCCFF_VlvTgtFlutter();
//  E2EPW_WriteInit_PpVlvTgtCCFF_VlvTgtFrequency();

  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
