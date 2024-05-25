/*
 *         CAN VERSION 
 */
#ifndef CANCBUSOFF_H_
#define CANCBUSOFF_H_

//#include "Typedefs.h"
#include <sys/_stdint.h>
#include <stdbool.h>
/*
 * =========================== return results =============================
 */

#define OK              0U
#define CANID_ERR       0xFFu
#define VALUE_ERR       0xFEu
#define DISABLED_ERR    0xFDu
#define LENGTH_ERR      0xFCu
/*
 * ===========================  CONSTANTS (NOT TO BE CHANGED!!) =================================
 * */

/*
 * == Tx/Rx Method ===
 */
#define ByEvent         0x00u
#define ByPeriodic      0x01u
#define ByComplex       0x02u
/*
 * === Event and ComplexEvent type =====
 */
#define Event_OnWrite   0x1u
#define Event_OnChange  0x02u
/*
 * ==== default number of CAN =====
 */
#define ONE_CAN         0x00u
#define TWO_CANS        0x01u
/*
 * ==== Rx frame type
 */
#define Normal_Frame    0x00u //normal or request frame
#define Diag_Frame      0x01u
#define Active_Frame    0x02u
/*
 * ===== byte order ======
 */
#define LITTLE_ENDIAN   0u //Intel
#define BIG_ENDIAN      1u //Moto

/* CAN RX function disable or enable setting */
#define CAN_RX_APP_MSG_ENABLE     					(0X00U)
#define CAN_RX_APP_MSG_DISABLE	 					(0X01U)

/* BUS OFF RELATED PARAMEMTERS- CHANGE ONLY NECESSARY */
/* ==================================================================================== */
#define BUS_OFF_TMR_SHORT_def       (45U)   /* Bus Off timer(short) */
#define BUS_OFF_TMR_LONG_def        (1000U)  /* Bus off timer(long) */
#define NUM_TO_BUSOFF_LONG_def      (10U)   /* bus off how many times before bus off timer changes to [BUS_OFF_TMR_LONG_def] */
#define BUS_OFF_PROBATION_def       (10U)   /* BUS_OFF_PROBATION x 100 ms == the time it needs to wait until no_BusOff_cntr is re-initialized */

typedef enum
{
	 BusOff_Sts_PowerOn = 0u,
	 BusOff_Sts_InitWait,
	 BusOff_Sts_FastRest,
	 BusOff_Sts_FastRestDelay,
	 BusOff_Sts_SlowRest,
	 BusOff_Sts_SlowRestDelay
}BusOff_Sts_en;

//=============================== FOR USER =============================================
#define POWER_OFF       (0x0u)
#define POWER_ON        (0x1u)

/****************************************************************************
name :GetBusOffStatus
input: CAN_Num: 0: CAN0; 1: CAN1;
output:  0: No BusOff; 1: BusOff; 0xFF: CAN1 isn't activated
function:
   Check the current BusOff status for either CAN0 or CAN1
Remark:
Limitation:
   none.
Author: hong
*****************************************************************************/
uint8_t GetBusOffStatus(void);

/****************************************************************************
name: void OnCAN_BusOffTimer_100ms()
input: void
output: void
function: count to 1000ms before re-initialize Bus off counter.
Remark:
   busOffCntr is to count how many bus off occurs within pre-definite probationary period.
   if bus off occurs more than 10 times within probationary period, then switch to longer bus
   off timer, which is typical 1000ms.
Author: hong
*****************************************************************************/
void OnCAN_BusOffTimer_100ms(void);

/****************************************************************************
name: void HSCAN0_RxFull()
input: none
output: void
function: this function is called by CAN 0 INT's call back function. it copies msg from
             CAN0 hardware received buffer to received Q, sRxD, before next CAN INT.
Remark:
        make sure CAN0's INT function in Events. c calls this function.
Author: hong
*****************************************************************************/
//void HSCAN0_RxFull(Message_Info_ST CanMsg);


/****************************************************************************
name: void HSCAN0_OnBusOff()
input: none
output: void
function: Bus off related timer
Remark:
   make sure Bus off INT call back function calls this function.
Author: hong
*****************************************************************************/
void HSCAN0_OnBusOff();

uint8_t CAN_CheckBusOffState(void);


/* ============================================================================= */
#endif
