/***********************************************************************
* Filename: ad.h
* Date:     11.04.2007 (creation)
* Revision: S1V1-F
*
* Copyright 2004 Steinbeis GmbH & Co. KG für Technologietransfer
* TransferZentrum Mikroelektronik
*
* Changes:
* SG  20070411  - initial version
*
************************************************************************
*
* Description:
*
* This header file provides definitions and prototypes for the 
* QADC-module of the MPC5567
*
***********************************************************************/

#ifndef _AD_H_
#define _AD_H_

/*- SYSTEM INCLUDES- - - - - - - - - - - - - - - - - - - - - - - - - -*/

/*- MODULE INCLUDES- - - - - - - - - - - - - - - - - - - - - - - - - -*/
#include "typedefs.h"
/*- DEFINES- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

/*- RETURN VALUES  - - - - - - - - - - - - - - - - - - - - - - - - - -*/
#define NO_RESULT_AVAILABLE	0x0
#define RESULT_AVAILABLE	0x1

/**************************************************************************/
/* ADC Control Register                                                   */
/**************************************************************************/

#define ADC0 0x0 						// ADC0
#define ADC1 0x1 						// ADC1

/**************************************************************************/
/* CFIFO Operation Mode 					                              */
/**************************************************************************/

#define ST_SINGLE_SCAN 			0x1 	// Software trigger, single scan
#define LLGET_SINGLE_SCAN 		0x2		// Low level gated external trigger, single scan 
#define HLGET_SINGLE_SCAN		0x3		// High level gated external trigger, single scan
#define FEET_SINGLE_SCAN		0x4		// Falling edge external trigger, single scan
#define REET_SINGLE_SCAN    	0x5		// Rising edge external trigger, single scan
#define FOREET_SINGLE_SCAN		0x6		// Falling or rising edge external trigger, single scan

#define ST_CONTINUOUS_SCAN 		0x9		// Software trigger, continuous scan
#define LLGET_CONTINUOUS_SCAN	0xA		// Low level gated external trigger, continuous scan  
#define HLGET_CONTINUOUS_SCAN   0xB		// High level gated external trigger, continuous scan
#define FEET_CONTINUOUS_SCAN	0xC		// Falling edge external trigger, continuous scan
#define REET_CONTINUOUS_SCAN	0xD		// Rising edge external trigger, continuous scan
#define FOREET_CONTINUOUS_SCAN	0xE		// Falling or rising edge external trigger, continuous scan

/**************************************************************************/
/* System Clock Divide Factors		                                      */
/**************************************************************************/

#define SCDF_2					0x0
#define SCDF_4					0x1
#define SCDF_6					0x2
#define SCDF_8					0x3
#define SCDF_10					0x4
#define SCDF_12					0x5
#define SCDF_14					0x6
#define SCDF_16					0x7
#define SCDF_18					0x8
#define SCDF_20					0x9
#define SCDF_22					0xA
#define SCDF_24					0xB


/**************************************************************************/
/* Conversion Command Messages		                                      */
/**************************************************************************/

#define RESULT_FIFO_0			0x0
#define	RESULT_FIFO_1			0x1
#define RESULT_FIFO_2			0x2
#define RESULT_FIFO_3			0x3
#define RESULT_FIFO_4			0x4
#define RESULT_FIFO_5			0x5

#define SAMPLING_TIME_2			0x0
#define SAMPLING_TIME_8			0x1
#define SAMPLING_TIME_64		0x2
#define SAMPLING_TIME_128		0x3

/**************************************************************************/
/* Interrupt and eDMA control Register	                                  */
/**************************************************************************/

#define INTERRUPT				0x1
#define POLL					0x0

/*- TYPEDEFS- - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


/*- GLOBAL VARIABLES- - - - - - - - - - - - - - - - - - - - - - - - - */

extern vuint32_t g_result0;
extern vuint32_t g_result1;
extern vuint32_t g_result2;
extern vuint32_t g_result3;
extern vuint32_t g_result4;
extern vuint32_t g_result5;


/*- GLOBAL FUNCTIONS- - - - - - - - - - - - - - - - - - - - - - - - - */

void Init_AD(int8_t adc, int8_t adc_clk_ps, int8_t adc_emux, uint16_t adc_mode, int8_t interrupt);
void Start_Conversion(int8_t adc, int8_t cal, int8_t result_fifo, int8_t sampling_time, 
					  int8_t time_stamp, int8_t fmt, int8_t channel_number);
int8_t Read_poll_Result(int8_t result_fifo, uint32_t *result);
void Stop_Conversion(int8_t adc);

void INTERRUPT_QADC_FISR0(void);
void INTERRUPT_QADC_FISR1(void);
void INTERRUPT_QADC_FISR2(void);
void INTERRUPT_QADC_FISR3(void);
void INTERRUPT_QADC_FISR4(void);
void INTERRUPT_QADC_FISR5(void);


#endif /* _AD_H_ */
