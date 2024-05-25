/*====================================================================================
   CAN VERSION 
=======================================================================================*/

#include <string.h>
#include "BatteryApp.h"
#include "SBC_Handler.h"
#include "can_pal.h"
#include "CAN0can_pal1.h"
#include "CANBusoff.h"



//===============================Bus off variables==============================
typedef struct BUSOFFSTATTAG
{
   uint16_t busOff_f: 1; 			/* bus off status for CAN 0. 0:  no bus off; 1: bus off */
   uint16_t physicalBusOff_f: 1;    /* bus off set by ECU */
   uint16_t no_BusOff_time: 7;      /* how long it has been with no bus off */
   uint16_t busOffCntr: 8;   		/* counts how many bus off has been occurred */
   uint16_t busOffTmr;   			/* this for using with BUS_OFF_TMR_SHORT or BUS_OFF_TMR_LONG in Events.c */
} BusOffStat_T;

typedef struct BusOff_CAN
{
   BusOffStat_T CAN_0;

}BusOff_CAN_T;

BusOff_CAN_T BusOff_Status;

uint8_t CanBusOff_Fast_Reset_Timer_1ms = 0u;
uint16_t CanBusOff_Slow_Reset_Timer_1ms = 0u;
BusOff_Sts_en BusOff_Sts = BusOff_Sts_PowerOn;
static void Can_BusOff_Process(void);


/****************************************************************************
name: void HSCAN0_OnBusOff()
input: BusOffStat_T: busOff
       whichCAN: CAN_Num: 0: CAN 0; 1; CAN 1
output: void
function: Bus off related timer
Remark:
     make sure Bus off INT call back function calls this function.
Author: hong
*****************************************************************************/
#if 1
static void HSCAN_BusOff(BusOffStat_T *busOff)
{
   busOff->no_BusOff_time = 0;
   busOff->physicalBusOff_f = 1;  // start BusOff... stop Tx Msg.
	/* Set MCAN OFF */
   sbc_switch_vcc3(VCC3_OFF);
	/* CAN Bus off  */
	BusOff_Status.CAN_0.busOff_f = 0x1;
	/* CAN module stop */
	while(CAN_Deinit(&CAN0can_pal1_instance) != STATUS_SUCCESS);
}
#else
static void HSCAN_BusOff(BusOffStat_T *busOff)
{
   busOff->no_BusOff_time = 0;
   busOff->busOffCntr++; // how many time bus off occurrs
   busOff->physicalBusOff_f = 1;  // start BusOff... stop Tx Msg.

   if(busOff->busOffCntr > NUM_TO_BUSOFF_LONG_def){
      busOff->busOffTmr = BUS_OFF_TMR_LONG_def;
      busOff->busOffCntr--; // max busOffCntr4CAN0 can go is 11 in order to prevent memory over flow
   }
   else{
      busOff->busOffTmr = BUS_OFF_TMR_SHORT_def;
   }
}
#endif

/************************************************************************
 * Function		:	HSCAN0_OnBusOff
 * Description	:
 * Input		:	None
 * Return		:	None
 * Time			:
 * Called		:
 * Others		:
*************************************************************************/
void HSCAN0_OnBusOff()
{
	CAN0->ESR1 |= CAN_ESR1_BOFFINT_MASK;  /* clear BusOff interrupt flag */
	HSCAN_BusOff(&BusOff_Status.CAN_0);

	/*  battery mode is normal */
	if(GetPDSBatteryModeApi() == BATTERY_MODE_NORMAL)
	{
		//CAN0BusOff_Start();
	}
}

/************************************************************************
 * Function		:	CAN_CheckBusOffState
 * Description	:
 * Input		:	None
 * Return		:	None
 * Time			:
 * Called		:
 * Others		:
*************************************************************************/
uint8_t CAN_CheckBusOffState(void)
{
	if(BusOff_Status.CAN_0.busOff_f == 1)
	{
		return true;
	}
	return false;
}

/**********************************************************************
  name :     GetBusOffStatus
  input:     CAN_Num: 0: CAN0; 1: CAN1;
  output:    0: No BusOff; 1: BusOff; 0xFF: CAN1 isn't activated
  function:
             Check the current BusOff status for either CAN0 or CAN1
***********************************************************************/
uint8_t GetBusOffStatus(void)
{
    return (uint8_t)BusOff_Status.CAN_0.busOff_f;
}

/****************************************************************************
name: void OnCAN_BusOffTimer_100ms()
input: void
output: void
function: count to 1000ms before re-initialize Bus off counter.
Remark:
   busOffCntr is to count how many bus off occures within pre-definite probationary period.
   if bus off occures more than 10 times within probationary period, then switch to longer bus
   off timer, which is typical 1000ms.
Author: hong
*****************************************************************************/

void OnCAN_BusOffTimer_100ms()
{
   if(BusOff_Status.CAN_0.busOff_f == 0u){
	//	   && BusOff_Status.CAN0.busOffCntr){
      BusOff_Status.CAN_0.no_BusOff_time++;

      if(BusOff_Status.CAN_0.no_BusOff_time >= BUS_OFF_PROBATION_def){
         BusOff_Status.CAN_0.busOffCntr = 0u;
         BusOff_Status.CAN_0.no_BusOff_time = 0u;

      }
   }
}

/*************************CAN BusOff Process**********************************************************/
static void Can_BusOff_Process(void)
{
	switch(BusOff_Sts)
	{
	case BusOff_Sts_PowerOn:
		BusOff_Status.CAN_0.physicalBusOff_f = 0u;
		BusOff_Status.CAN_0.busOffCntr = 0u;   		
		BusOff_Status.CAN_0.busOffTmr = 0u;    		
		BusOff_Status.CAN_0.busOff_f = 0u;
		BusOff_Status.CAN_0.no_BusOff_time = 0u;
		CanBusOff_Fast_Reset_Timer_1ms = 0u;
		CanBusOff_Slow_Reset_Timer_1ms = 0u;
		BusOff_Sts = BusOff_Sts_InitWait;
		break;
	case BusOff_Sts_InitWait:
		if(BusOff_Status.CAN_0.physicalBusOff_f)
		{
			BusOff_Status.CAN_0.physicalBusOff_f = 0u;
			BusOff_Status.CAN_0.busOff_f = 1u;
			BusOff_Status.CAN_0.no_BusOff_time = 0u;
			CanBusOff_Fast_Reset_Timer_1ms = 0u;
			CanBusOff_Slow_Reset_Timer_1ms = 0u;
			/* Set MCAN OFF */
			sbc_switch_vcc3(VCC3_OFF);
			/* CAN TX stop  */

			/* CAN module stop */
			while(CAN_Deinit(&CAN0can_pal1_instance) != STATUS_SUCCESS);
			/* check fast reset or Slow reset */
			if(BusOff_Status.CAN_0.busOffCntr >= NUM_TO_BUSOFF_LONG_def)
			{
				BusOff_Status.CAN_0.busOffTmr = BUS_OFF_TMR_LONG_def;
				BusOff_Sts = BusOff_Sts_SlowRest;
			}
			else
			{
				BusOff_Status.CAN_0.busOffCntr++;
				BusOff_Status.CAN_0.busOffTmr = BUS_OFF_TMR_SHORT_def;
				BusOff_Sts = BusOff_Sts_FastRest;
			}
		}
		break;
	case BusOff_Sts_FastRest:
		CanBusOff_Fast_Reset_Timer_1ms = 0u;
		BusOff_Status.CAN_0.no_BusOff_time = 0u;
		/* Set MCAN OFF */
		sbc_switch_vcc3(VCC3_OFF);
		/* CAN TX stop  */

		/* CAN module stop */
		while(CAN_Deinit(&CAN0can_pal1_instance) != STATUS_SUCCESS);
		BusOff_Sts = BusOff_Sts_FastRestDelay;
		break;
	case BusOff_Sts_FastRestDelay:
		CanBusOff_Fast_Reset_Timer_1ms++;
		if(CanBusOff_Fast_Reset_Timer_1ms >= BusOff_Status.CAN_0.busOffTmr)
		{
			CanBusOff_Fast_Reset_Timer_1ms = BusOff_Status.CAN_0.busOffTmr;
			BusOff_Status.CAN_0.busOff_f = 0u;
			BusOff_Status.CAN_0.no_BusOff_time = 0u;
			/* Set MCAN Normal */
			sbc_switch_vcc3(VCC3_ENABLED);
			//CAN_Init_Config_Func();
			//MyCAN_Init();
			BusOff_Sts = BusOff_Sts_InitWait;
		}
		break;
	case BusOff_Sts_SlowRest:
		CanBusOff_Slow_Reset_Timer_1ms = 0u;
		BusOff_Status.CAN_0.no_BusOff_time = 0u;
		/* Set MCAN OFF */
		sbc_switch_vcc3(VCC3_OFF);
		/* CAN TX stop  */
		//StopAllTxMsgs();
		/* CAN module stop */
		while(CAN_Deinit(&CAN0can_pal1_instance) != STATUS_SUCCESS);
		BusOff_Sts = BusOff_Sts_SlowRestDelay;
		break;
	case BusOff_Sts_SlowRestDelay:
		CanBusOff_Slow_Reset_Timer_1ms++;
		if(CanBusOff_Slow_Reset_Timer_1ms >= BusOff_Status.CAN_0.busOffTmr)
		{
			CanBusOff_Slow_Reset_Timer_1ms = BusOff_Status.CAN_0.busOffTmr;
			BusOff_Status.CAN_0.busOff_f = 0u;
			BusOff_Status.CAN_0.no_BusOff_time = 0u;
			/* Set MCAN Normal */
			sbc_switch_vcc3(VCC3_ENABLED);
			//CAN_Init_Config_Func();
			//MyCAN_Init();
			BusOff_Sts = BusOff_Sts_InitWait;
		}
		break;
	default:
		BusOff_Sts = BusOff_Sts_PowerOn;
		break;
	}
}

