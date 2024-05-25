/*
 * OsMain.c
 *
 *  Created on: 06.12.2023
 *
 */
#include "OsTypedefs.h"
#include "OsTaskFu.h"
#include "OsTimerTick.h"
#include "0_AppSW/Config/Roll_Pitch_Parameter.h"
#include "IMU.h"
#include "CanNM.h"
#include "CanIf.h"
#include "Canif_Signals.h"
#include "Battery_App/BatteryApp.h"
#include "Framework.h"
#include "UDS.h"
#include "Application.h"
/** \brief Initialize the position sensor interfaces */ 

extern uint8_t AppTaskScheduleTimer;

void OsMainInit(void)
{
	OsTimerTick_Init();
	OsScheduler_init();
	UdsInit();
}


void OsMain(void)
{
    // Initialize Tasks
    OsTaskfu_init();
	OsMainInit();
	Roll_Pitch_Adjust();


    while (1)
    {

    	//Roll_Pitch_Adjust();

    	if(timer1ms_counter>K_TIMER_1MS_COUNT)
    	{
    		timer1ms_counter = 0;
			AppTaskScheduleTimer++;
    		OsTaskfu_1ms();
    		Framework_TMR_1ms();
    	}

    	if(timer5ms_counter>K_TIMER_5MS_COUNT)
    	{
    		timer5ms_counter=0;

    		OsTaskfu_5ms();

    	}

    	if(timer10ms_counter>K_TIMER_10MS_COUNT)
    	{
    		timer10ms_counter=0;
    		BatteryCheckTimer_10ms();
    		OsTaskfu_10ms();
    	}

    	if(timer100ms_counter>K_TIMER_100MS_COUNT)
    	{
    		timer100ms_counter=0;
    		OsTaskfu_100ms();

    	}

    	if(timer200ms_counter>K_TIMER_200MS_COUNT)
    	{
    		timer200ms_counter=0;
    		OsTaskfu_200ms();
    	}

    	if(timer300ms_counter>K_TIMER_300MS_COUNT)
    	{
    		timer300ms_counter = 0;
    		 TIMERSTART = 0;

    	}

    	OsTaskfu_cyclic();
    	CanNm_MainFunction();
    }
}
