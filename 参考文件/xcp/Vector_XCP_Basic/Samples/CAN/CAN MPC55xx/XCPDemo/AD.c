
/***********************************************************************
* Filename: ad.c
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
* This module provides functions for using the QADC of the MPC5567.
*
***********************************************************************/
/*- SYSTEM INCLUDES- - - - - - - - - - - - - - - - - - - - - - - - - -*/

/*- MODULE INCLUDES- - - - - - - - - - - - - - - - - - - - - - - - - -*/
#include "MPC5567.h" 
#include "AD.h"

/*- EXTERNAL FUNCTIONS- - - - - - - - - - - - - - - - - - - - - - - - */

/*- EXTERNAL VARIABLES- - - - - - - - - - - - - - - - - - - - - - - - */

/*- DEFINES- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

/*- TYPEDEFS- - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*- GLOBAL FUNCTIONS- - - - - - - - - - - - - - - - - - - - - - - - - */

/*- GLOBAL VARIABLES- - - - - - - - - - - - - - - - - - - - - - - - - */

uint16_t g_adc_mode;

vuint32_t g_result0;
vuint32_t g_result1;
vuint32_t g_result2;
vuint32_t g_result3;
vuint32_t g_result4;
vuint32_t g_result5;

/*- STATIC FUNCTIONS- - - - - - - - - - - - - - - - - - - - - - - - - */

/*- STATIC VARIABLES- - - - - - - - - - - - - - - - - - - - - - - - - */

/**********************************************************************/
/*- FUNCTION IMPLEMENTATIONS- - - - - - - - - - - - - - - - - - - - - */
/**********************************************************************/


/***********************************************************************
* Name: Init_AD()
* Date: 11.04.2007
*
* Copyright 2004 Steinbeis GmbH & Co. KG für Technologietransfer
* TransferZentrum Mikroelektronik
*
* Changes:
* SG  20070411  - initial version
*
************************************************************************
* Description:
*
* This function initialize the ADC interface.
*
************************************************************************
* Parameters:
*
* int8_t adc
* -> specifies the ADC to initialize 
* 
* 		ADC0 					= ADC 0
* 		ADC1					= ADC 1
* 
* int8_t adc_clk_ps
* -> specifies the System Clock Prescaler for the selected ADC
*
* 		SCDF_2  ,SCDF_4  ,SCDF_6  ,SCDF_8  ,SCDF_10 ,SCDF_12 ,
* 		SCDF_14 ,SCDF_16 ,SCDF_18 ,SCDF_20 ,SCDF_22 ,SCDF_24
* 
* 					Sysclk (120 Mhz)
* 		12 Mhz => -------------------
* 					SCDF
* 
* int8_t adc_emux
* -> specifies if an external multiplexer is used or not
*  
*    	1 						= enable external multiplexer
* 	 	0 						= disable external multiplexer (recommended)
*  
* int8_t adc_mode 
* -> specifies the mode of the ADC
* 
* 		ST_SINGLE_SCAN 			= Software trigger, single scan (recommended)
* 		LLGET_SINGLE_SCAN 		= Low level gated external trigger, single scan 
* 		HLGET_SINGLE_SCAN		= High level gated external trigger, single scan
* 		FEET_SINGLE_SCAN		= Falling edge external trigger, single scan
* 		REET_SINGLE_SCAN    	= Rising edge external trigger, single scan
* 		FOREET_SINGLE_SCAN		= Falling or rising edge external trigger, single scan
* 
* 		ST_CONTINUOUS_SCAN 		= Software trigger, continuous scan 
* 		LLGET_CONTINUOUS_SCAN	= Low level gated external trigger, continuous scan  
* 		HLGET_CONTINUOUS_SCAN   = High level gated external trigger, continuous scan
* 		FEET_CONTINUOUS_SCAN	= Falling edge external trigger, continuous scan
* 		REET_CONTINUOUS_SCAN	= Rising edge external trigger, continuous scan
* 		FOREET_CONTINUOUS_SCAN	= Falling or rising edge external trigger, continuous scan
* 
* int8_t interrupt
* -> specifies whether the result of an AD-conversion generates an interrupt or not. If not,
* 	 the user needs to call the function "Read_poll_Result" periodically until a result is available 
* 
* 		INTERRUPT				= system generates an interrupt
*		POLL					= system generates no interrupt 
* 
************************************************************************
* Return Value:
*
* void
*
***********************************************************************/
void Init_AD(int8_t adc, int8_t adc_clk_ps, int8_t adc_emux, uint16_t adc_mode, int8_t interrupt)
{
	
	uint16_t ADC_control_reg_value 	= 0x0;
	uint16_t CFCR_reg_value 		= 0x0;
	uint32_t CFPR_reg_value 		= 0x0;
		
	g_adc_mode		= 0;						// init global vars
	g_result0		= 0;						// init global vars
	g_result1		= 0;						// init global vars
	g_result2		= 0;						// init global vars
	g_result3		= 0;						// init global vars
	g_result4		= 0;						// init global vars
	g_result5		= 0;						// init global vars
						 	
	g_adc_mode = adc_mode;
				
	ADC_control_reg_value =  1<<15; 			// enable ADC
	ADC_control_reg_value |= adc_emux<<11;		// set external Multiplexer 
	ADC_control_reg_value |= adc_clk_ps ; 		// set Prescaler
	
	CFPR_reg_value =  1<<31; 					// set End of Queue
	CFPR_reg_value |= adc<<25; 					// select ADC (ADC0 or ADC1)
	CFPR_reg_value |= ADC_control_reg_value<<8; // insert ADC_control_reg_value
	CFPR_reg_value |= 1;						// insert ADC_control_reg_address (0x1)
	
	EQADC.CFPR[0].R =CFPR_reg_value; 			// set CFIFO 0 push register  
									
									
	CFCR_reg_value =  (uint16_t)g_adc_mode<<4;	// set mode
	
	if(	g_adc_mode == 0x1 || g_adc_mode == 0x2 || g_adc_mode == 0x3 ||
		g_adc_mode == 0x4 || g_adc_mode == 0x5 || g_adc_mode == 0x6 )
	{
		CFCR_reg_value |= 1<<10;				// if Single Scan Mode -> set SSE Bit
	}

	EQADC.CFCR[0].R = CFCR_reg_value;		 	// set CFIFO 0 control register (mode)
	
	
	if(interrupt)
	{																		
		EQADC.IDCR[0].B.RFDE = 1;				// set interrupt
		INTC.PSR[105].R =1;			  			// set priority Result FIFO 0
		INTC.PSR[110].R =1;			  			// set priority Result FIFO 0
		INTC.PSR[115].R =1;			  			// set priority Result FIFO 0
		INTC.PSR[120].R =1;			  			// set priority Result FIFO 0
		INTC.PSR[125].R =1;			  			// set priority Result FIFO 0
		INTC.PSR[130].R =1;			  			// set priority Result FIFO 0 
	}
		
	while (EQADC.FISR[0].B.EOQF !=1) {} 		// Wait for End Of Queue flag 
	EQADC.FISR[0].B.EOQF = 1; 					// Clear End Of Queue flag 
}

/***********************************************************************
* Name: Start_Conversion()
* Date: 11.04.2007
*
* Copyright 2004 Steinbeis GmbH & Co. KG für Technologietransfer
* TransferZentrum Mikroelektronik
*
* Changes:
* SG  20070412  - inital version 
*
************************************************************************
* Description:
*
* This function starts an single AD conversion. 
* !!! Continuous scan mode is not possible !!!
*
************************************************************************
* Parameters:
*
* int8_t adc
* -> specifies the ADC  
* 
* 		ADC0 					= ADC 0
* 		ADC1					= ADC 1
* 
* int8_t cal
* -> specifies if the result should be calibrated or not
* 
* 		0						= don't calibrate result
*		1 						= calibrate result (at the moment not supported)
*
* int8_t result_fifo
* -> specifies the RESULT_FIFO to insert the result of the AD-conversion  
* 
*		RESULT_FIFO_0			= Result FIFO 0	
*		RESULT_FIFO_1			= Result FIFO 1			
*		RESULT_FIFO_2			= Result FIFO 2
*		RESULT_FIFO_3			= Result FIFO 3
*		RESULT_FIFO_4			= Result FIFO 4
*		RESULT_FIFO_5			= Result FIFO 5
* 
* int8_t sampling_time
* -> specifies the duration of the sampling time in ADC clock cycles
* 
*		SAMPLING_TIME_2			= 2   ADC Clock Cycles
*		SAMPLING_TIME_8			= 8   ADC Clock Cycles
*		SAMPLING_TIME_64		= 64  ADC Clock Cycles
*		SAMPLING_TIME_128       = 128 ADC Clock Cycles
* 
* int8_t time_stamp
* -> specifies whether the Time Stamp feature is enabled or not
* 
* 		0						= return conversion result only
* 		1						= return conversion time stamp after the conversion result(at the moment not supported)
* 
* int8_t fmt
* -> specifies whether the result of the conversion is signed or unsigned
* 
* 		0						= Right justified unsigned
* 		1						= Right justified signed
* 
* int8_t channel_number
* -> Selects the analog input channel
* 
* 		0-39					= channel 0 -channel 39 (FlexDevel only 0-7)
************************************************************************
* Return Value:
*
* void
* 
***********************************************************************/
void Start_Conversion(	int8_t adc, int8_t cal, int8_t result_fifo, int8_t sampling_time, 
						int8_t time_stamp, int8_t fmt, int8_t channel_number)
{
	uint32_t CFPR_reg_value = 0x0;
	uint32_t CFCR_reg_value = 0x0;
	
	CFPR_reg_value = 	1<<31;					// Set EOQ 
	CFPR_reg_value |=   adc<<25;				// Set ADC
	CFPR_reg_value |=   cal<<24;				// Set calibration on or off
	CFPR_reg_value |=   result_fifo<<20;		// Set result FIFO number
	CFPR_reg_value |= 	sampling_time<<18;		// Set sampling time
	CFPR_reg_value |=   time_stamp<<17;			// Set timestamp feature on or off
	CFPR_reg_value |=   fmt<<16;				// Set result signed or unsigned
	CFPR_reg_value |=   channel_number<<8;		// Set channel number
		
	EQADC.CFPR[0].R = CFPR_reg_value; 			// Set CFIFO 0 push register 

	
	CFCR_reg_value =  g_adc_mode<<4;		 	// set mode
	
	if(	g_adc_mode == 0x1 || g_adc_mode == 0x2 || g_adc_mode == 0x3 ||
		g_adc_mode == 0x4 || g_adc_mode == 0x5 || g_adc_mode == 0x6 )
	{
		CFCR_reg_value |= 1<<10;				// if Single Scan Mode -> set SSE Bit
	}

	EQADC.CFCR[0].R = CFCR_reg_value;		 	// set CFIFO 0 control register 

}


/***********************************************************************
* Name: Read_poll_Result()
* Date: 11.04.2007
*
* Copyright 2004 Steinbeis GmbH & Co. KG für Technologietransfer
* TransferZentrum Mikroelektronik
*
* Changes:
* SG  20070412  - inital version
*
************************************************************************
* Description:
*
* This function verifies if an AD conversion has finished and
* reads the result.(poll mode)
* 
************************************************************************
* Parameters:
*
*int8_t result_fifo
* -> specifies the RESULT_FIFO to fetch the result of the AD-conversion  
* 
*		RESULT_FIFO_0			= Result FIFO 0	
*		RESULT_FIFO_1			= Result FIFO 1			
*		RESULT_FIFO_2			= Result FIFO 2
*		RESULT_FIFO_3			= Result FIFO 3
*		RESULT_FIFO_4			= Result FIFO 4
*		RESULT_FIFO_5			= Result FIFO 5
* 
* uint32 *result
* -> Pointer to store the result 
* 
************************************************************************
* Return Value:
*
* int8_t
* -> error code 
* 
* 	 NO_RESULT_AVAILABLE		= no result available
* 	 RESULT_AVAILABLE			= result available
* 
***********************************************************************/
int8_t Read_poll_Result(int8_t result_fifo, uint32_t *result)
{	
	if(EQADC.FISR[result_fifo].B.RFDF == 1)					// Check if RFIFO x's Drain Flag is set
	{ 	
		*result = (uint32_t)EQADC.RFPR[result_fifo].R; 		// Save result 
		EQADC.FISR[result_fifo].B.RFDF = 1;					// Clear result FIFO drain flag
		return RESULT_AVAILABLE;
	}
	else
	{
		return NO_RESULT_AVAILABLE;	
	}
}


/***********************************************************************
* Name: Stop_AD()
* Date: 11.04.2007
*
* Copyright 2004 Steinbeis GmbH & Co. KG für Technologietransfer
* TransferZentrum Mikroelektronik
*
* Changes:
* SG  20070412  - inital version
*
************************************************************************
* Description:
*
* This function stops/disables the AD converter 
*
************************************************************************
* Parameters:
*
* int8_t adc
* -> specifies the ADC  
* 
* 		ADC0 					= ADC 0
* 		ADC1					= ADC 1
*
************************************************************************
* Return Value:
*
* void
*
***********************************************************************/
void Stop_Conversion(int8_t adc)
{
	uint32_t CFPR_reg_value 		= 0x0;
	
	CFPR_reg_value =  1<<31; 					// set End of Queue
	CFPR_reg_value |= adc<<25; 					// select ADC (ADC0 or ADC1)
	CFPR_reg_value |= 1;						// insert ADC_control_reg_address (0x1)
	
	EQADC.CFPR[0].R =CFPR_reg_value; 			// Set CFIFO 0 push register  
}


/***********************************************************************
* Name: _INTERRUPT_QADC_FISR0()
* Date: 11.04.2007
*
* Copyright 2004 Steinbeis GmbH & Co. KG für Technologietransfer
* TransferZentrum Mikroelektronik
*
* Changes:
* SG  20070412  - inital version
*
************************************************************************
* Description:
*
* Interrupt service routine for result fifo 0
*
************************************************************************
* Parameters:
*
* none
*
************************************************************************
* Return Value:
*
* none
*
***********************************************************************/

void INTERRUPT_QADC_FISR0(void)
{
 	g_result0 = EQADC.RFPR[0].R; 				// Save result in lower 16 bits 
 	EQADC.FISR[0].B.RFDF = 1;					// Clear result FIFO drain flag
}

/***********************************************************************
* Name: _INTERRUPT_QADC_FISR1()
* Date: 11.04.2007
*
* Copyright 2004 Steinbeis GmbH & Co. KG für Technologietransfer
* TransferZentrum Mikroelektronik
*
* Changes:
* SG  20070412  - inital version
*
************************************************************************
* Description:
*
* Interrupt service routine for result fifo 1
*
************************************************************************
* Parameters:
*
* none
*
************************************************************************
* Return Value:
*
* none
*
***********************************************************************/

void INTERRUPT_QADC_FISR1(void)
{
 	g_result1 = EQADC.RFPR[1].R; 				// Save result in lower 16 bits 
 	EQADC.FISR[1].B.RFDF = 1;					// Clear result FIFO drain flag 
}

/***********************************************************************
* Name: _INTERRUPT_QADC_FISR2()
* Date: 11.04.2007
*
* Copyright 2004 Steinbeis GmbH & Co. KG für Technologietransfer
* TransferZentrum Mikroelektronik
*
* Changes:
* SG  20070412  - inital version
*
************************************************************************
* Description:
*
* Interrupt service routine for result fifo 2
*
************************************************************************
* Parameters:
*
* none
*
************************************************************************
* Return Value:
*
* none
*
***********************************************************************/

void INTERRUPT_QADC_FISR2(void)
{
 	g_result2 = EQADC.RFPR[2].R; 				// Save result in lower 16 bits 
 	EQADC.FISR[2].B.RFDF = 1;					// Clear result FIFO drain flag 
}

/***********************************************************************
* Name: _INTERRUPT_QADC_FISR3()
* Date: 11.04.2007
*
* Copyright 2004 Steinbeis GmbH & Co. KG für Technologietransfer
* TransferZentrum Mikroelektronik
*
* Changes:
* SG  20070412  - inital version
*
************************************************************************
* Description:
*
* Interrupt service routine for result fifo 3
*
************************************************************************
* Parameters:
*
* none
*
************************************************************************
* Return Value:
*
* none
*
***********************************************************************/

void INTERRUPT_QADC_FISR3(void)
{
  	g_result3 = EQADC.RFPR[3].R; 				// Save result in lower 16 bits
  	EQADC.FISR[3].B.RFDF = 1;					// Clear result FIFO drain flag 
}

/***********************************************************************
* Name: _INTERRUPT_QADC_FISR4()
* Date: 11.04.2007
*
* Copyright 2004 Steinbeis GmbH & Co. KG für Technologietransfer
* TransferZentrum Mikroelektronik
*
* Changes:
* SG  20070412  - inital version
*
************************************************************************
* Description:
*
* Interrupt service routine for result fifo 4
*
************************************************************************
* Parameters:
*
* none
*
************************************************************************
* Return Value:
*
* none
*
***********************************************************************/

void INTERRUPT_QADC_FISR4(void)
{
  	g_result4 = EQADC.RFPR[4].R; 				// Save result in lower 16 bits 
  	EQADC.FISR[4].B.RFDF = 1;					// Clear result FIFO drain flag
}

/***********************************************************************
* Name: _INTERRUPT_QADC_FISR5()
* Date: 11.04.2007
*
* Copyright 2004 Steinbeis GmbH & Co. KG für Technologietransfer
* TransferZentrum Mikroelektronik
*
* Changes:
* SG  20070412  - inital version
*
************************************************************************
* Description:
*
* Interrupt service routine for result fifo 5
*
************************************************************************
* Parameters:
*
* none
*
************************************************************************
* Return Value:
*
* none
*
***********************************************************************/

void INTERRUPT_QADC_FISR5(void)
{
  	g_result5 = EQADC.RFPR[5].R; 				// Save result in lower 16 bits 
  	EQADC.FISR[5].B.RFDF = 1;					// Clear result FIFO drain flag
}

