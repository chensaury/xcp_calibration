/*
 * TC397_Autosar.c
 *
 *  Created on: 2022年12月11日
 *      Author: 李德刚
 */

#include "Os.h"
#include "EcuM.h"
#include "Rte_Main.h"


# include "ComM_Cfg.h"
# include "ComM.h"
# include "ComM_EcuMBswM.h"
# include "Can.h"
#include "Port.h"
#include "Mcu.h"
#include "IfxSrc_reg.h"


/***********************************************************************************************************************
 *  main
 **********************************************************************************************************************/
int main(void)
{
	Os_InitMemory();
	Os_Init();
//	SRC_CAN0INT0.B.SRE = 1;
	EcuM_Init(); /* never returns */

	return 0;
}

/***********************************************************************************************************************
 *  InitTask_OsCore0
 **********************************************************************************************************************/
TASK(Init_Core0)
{
	EcuM_StartupTwo();
//	Rte_Start();
//	CanSM_StartWakeupSources(0);
//	ComM_CommunicationAllowed(0, TRUE);



	(void)TerminateTask();
}
/***********************************************************************************************************************
 *  InitTask_OsCore1
 **********************************************************************************************************************/
TASK(Init_Core1)
{
//	EcuM_StartupTwo();
//	Rte_Start();

	(void)TerminateTask();
}

/***********************************************************************************************************************
 *  InitTask_OsCore2
 **********************************************************************************************************************/
TASK(Init_Core2)
{
//	EcuM_StartupTwo();
////	Rte_Start();

	(void)TerminateTask();
}

/***********************************************************************************************************************
 *  InitTask_OsCore3
 **********************************************************************************************************************/
TASK(Init_Core3)
{
//	EcuM_StartupTwo();
////	Rte_Start();

	(void)TerminateTask();
}

/***********************************************************************************************************************
 *  InitTask_OsCore4
 **********************************************************************************************************************/
TASK(Init_Core4)
{
//	EcuM_StartupTwo();
//	Rte_Start();

	(void)TerminateTask();
}

/***********************************************************************************************************************
 *  InitTask_OsCore5
 **********************************************************************************************************************/
TASK(Init_Core5)
{
//	EcuM_StartupTwo();
//	Rte_Start();

	(void)TerminateTask();
}

/**********************************************************************************************************************
 *  END OF FILE: CBD1800382_D00.c
 *********************************************************************************************************************/
/***********************************************************************************************************************
 * UserDefined ExclusiveArea handling for CAN channels, according to AN-ISC-8-1149_ErrorHook_E_OS_DISABLED_INT.pdf
 **********************************************************************************************************************/
static uint8 BrsAsrApplCanInterruptLockCtr;
void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0(void)
{
//	  SuspendAllInterrupts();
//  if (++BrsAsrApplCanInterruptLockCtr == 1u)
//  {
   Can_DisableControllerInterrupts(0u);

///
}

void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0(void)
{
//	  ResumeAllInterrupts();
//  if (--BrsAsrApplCanInterruptLockCtr == 0u)
//  {
    Can_EnableControllerInterrupts(0u);

//  }
}

void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_6(void)
{
//    SuspendAllInterrupts();
//  if (++BrsAsrApplCanInterruptLockCtr == 1u)
//  {
   Can_DisableControllerInterrupts(0u);

//  }
}

void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_6(void)
{
//	  ResumeAllInterrupts();
//  if (--BrsAsrApplCanInterruptLockCtr == 0u)
//  {
    Can_EnableControllerInterrupts(0u);

//  }
}

void SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_0(void)
{
//	  SRC_CAN0INT0.B.SRE = 0;
//	  SuspendAllInterrupts();
//  if (++BrsAsrApplCanInterruptLockCtr == 1u)
//  {

    Can_DisableControllerInterrupts(0u);
////
//  }
}

void SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_0(void)
{
//	  SRC_CAN0INT0.B.SRE = 1;
//	  ResumeAllInterrupts();
//  if (--BrsAsrApplCanInterruptLockCtr == 0u)
//  {

    Can_EnableControllerInterrupts(0u);
//
//  }
}

void SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_4(void)
{
//	  SuspendAllInterrupts();
//  if (++BrsAsrApplCanInterruptLockCtr == 1u)
//  {
//    Can_DisableControllerInterrupts(0u);

//  }
}

void SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_4(void)
{
//	  ResumeAllInterrupts();
//  if (--BrsAsrApplCanInterruptLockCtr == 0u)
//  {
//    Can_EnableControllerInterrupts(0u);

//  }
}

void SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_1(void)
{
  /* Protects against task interruptions -> no locking needed, because all main functions are on same task */
}

void SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_1(void)
{
  /* Protects against task interruptions -> no locking needed, because all main functions are on same task */
}

void SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_1(void)
{
  /* Protects against task interruptions -> no locking needed, because all main functions are on same task */
}

void SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_1(void)
{
  /* Protects against task interruptions -> no locking needed, because all main functions are on same task */
}
