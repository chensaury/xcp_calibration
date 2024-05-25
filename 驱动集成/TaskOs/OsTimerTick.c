/*
 * OsTimerTick.c
 *
 *  Created on: 06.12.2023
 *
 */
#include "OsTypedefs.h"
#include "ftm_mc_driver.h"
#include "flexTimer_mc1.h"
#include "CanNM.h"
#include "Canif_Signals.h"

extern osScheduler_task g_tasks_core0[OsScheduler_Task_count];
uint32_t timer1ms_counter=0;
uint32_t timer5ms_counter=0;
uint32_t timer10ms_counter=0;
uint32_t timer100ms_counter=0;
uint32_t timer200ms_counter=0;
uint32_t timer300ms_counter = 0;

uint32_t timer_ticks=0;
void ftmTimerISR(void);
inline void OsTimerTick_1msIsr(void)
{
    OsScheduler_tick((osScheduler_task*)&g_tasks_core0);
}

ftm_state_t ftmStateStruct;
void OsTimerTick_Init (void)
{
     timer1ms_counter=0;
     timer5ms_counter=0;
     timer10ms_counter=0;
     timer100ms_counter=0;
     timer200ms_counter=0;
     timer300ms_counter=0;

	 FTM_DRV_Init(INST_FLEXTIMER_MC1, &flexTimer_mc1_InitConfig,&ftmStateStruct);
	 INT_SYS_InstallHandler(FTM0_Ovf_Reload_IRQn,&ftmTimerISR,(isr_t*)0U);
	 INT_SYS_EnableIRQ(FTM0_Ovf_Reload_IRQn);
	 FTM_DRV_InitCounter(INST_FLEXTIMER_MC1, &flexTimer_mc1_TimerConfig);
	 FTM_DRV_CounterStart(INST_FLEXTIMER_MC1);
}

/*1ms timer interrupt handler*/
 void ftmTimerISR(void)
 {
	 CanNm_TimerNotification(1);
//	 CanNm_MainFunction();
	 timer_ticks++;
	 timer1ms_counter++;
	 timer5ms_counter++;
	 timer10ms_counter++;
	 timer100ms_counter++;
	 timer200ms_counter++;
	 if(TIMERSTART)
	 {
		 timer300ms_counter++;

	 }


 	 FTM_DRV_ClearStatusFlags(INST_FLEXTIMER_MC1,(uint32_t)FTM_TIME_OVER_FLOW_FLAG);
 }

