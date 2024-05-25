/*******************************************************************************
* Example Code
*
* Copyright(C) 2023 NXP Semiconductors
* NXP Semiconductors Confidential and Proprietary
*
* Software that is described herein is for illustrative purposes only
* which provides customers with programming information regarding the
* NXP products.  This software is supplied "AS IS" without any warranties
* of any kind, and NXP Semiconductors and its licensor disclaim any and
* all warranties, express or implied, including all implied warranties of
* merchantability, fitness for a particular purpose and non-infringement of
* intellectual property rights.  NXP Semiconductors assumes no responsibility
* or liability for the use of the software, conveys no license or rights
* under any patent, copyright, mask work right, or any other intellectual
* property rights in or to any products. NXP Semiconductors reserves the
* right to make changes in the software without notification. NXP
* Semiconductors also makes no representation or warranty that such
* application will be suitable for the specified use without further testing
* or modification.
*
* IN NO EVENT WILL NXP SEMICONDUCTORS BE LIABLE, WHETHER IN CONTRACT, 
* TORT, OR OTHERWISE, FOR ANY INCIDENTAL, SPECIAL, INDIRECT, CONSEQUENTIAL 
* OR PUNITIVE DAMAGES, INCLUDING, BUT NOT LIMITED TO, DAMAGES FOR ANY 
* LOSS OF USE, LOSS OF TIME, INCONVENIENCE, COMMERCIAL LOSS, OR LOST 
* PROFITS, SAVINGS, OR REVENUES, TO THE FULL EXTENT SUCH MAY BE DISCLAIMED  
* BY LAW. NXP SEMICONDUCTOR’S TOTAL LIABILITY FOR ALL COSTS, DAMAGES, 
* CLAIMS, OR LOSSES WHATSOEVER ARISING OUT OF OR IN CONNECTION WITH THE 
* SOFTWARE IS LIMITED TO THE AGGREGATE AMOUNT PAID BY YOU TO NXP SEMICONDUCTORS
* IN CONNECTION WITH THE SOFTWARE TO WHICH LOSSES OR DAMAGES ARE CLAIMED.
*
* Permission to use, copy, modify, and distribute this software and its
* documentation is hereby granted, under NXP Semiconductors' and its
* licensor's relevant copyrights in the software, without fee, provided
* that it is used in conjunction with NXP Semiconductors devices.  This
* copyright, permission, and disclaimer notice must appear in all copies
* of this code.
*******************************************************************************/

/*
 * lpspi.c
 *
 *  SPI Source File
 *
 */

#include "stddef.h"
#include "lpspi.h"
#include "MCAL\Mcal\Tricore\Spi\ssc\inc/Spi.h"


// SPI transfer constants
const unsigned short TIMEOUT = 1000;
const size_t transferByteCount = 2U;

// SPI transmit and receive buffers
unsigned char sendBuf[384] ;
unsigned char sendBufRxBuf[2] ;


/////////////////////////////////////////////////////////////////////////////////////////////////
// Function name   : init_SPI
// Description     : Initializes the SPI interface
// Return type     : void
// Argument        : void
/////////////////////////////////////////////////////////////////////////////////////////////////
void init_SPI(void)
{
    // Add code to initialize the SPI interface
}

FUNC(void, CtPT2000_Handler_CODE) IoHwAb_SPI_Write(uint8 channelId, uint8 sequenceId)
{
    Std_ReturnType stdRet = E_NOT_OK;

    Spi_SetAsyncMode(1);

    stdRet = Spi_SetupEB(channelId, &sendBuf[0], &sendBufRxBuf[0], 2);


	if( E_OK == stdRet )
	{
		stdRet = Spi_SyncTransmit(sequenceId);
	}

//    if( E_OK == stdRet )
//    {
//    	for(uint16 i = 0;i <= 1;i++)
//    	{
//    		if(i == 1000)
//    		{
//    			i = 0;
//    		}
//    	}
//		stdRet = Spi_AsyncTransmit(sequenceId);
//    }
}


FUNC(void, CtPT2000_Handler_CODE) IoHwAb_SPI_Write_32(uint8 channelId, uint8 sequenceId)
{
    Std_ReturnType stdRet = E_NOT_OK;

//    Spi_SetAsyncMode(1);

    stdRet = Spi_SetupEB(channelId, &sendBuf[0], &sendBufRxBuf[0], 384);


	if( E_OK == stdRet )
	{
		stdRet = Spi_SyncTransmit(sequenceId);
	}
}
extern uint8 x;
extern uint8 y;
/////////////////////////////////////////////////////////////////////////////////////////////////
// Function name   : send_16bit_SPI
// Description     : Sends a 16 bit SPI word to the device
// Return type     : uint16_t - Data received from the device
// Argument        : unsigned short data16 - Data to send to the device
/////////////////////////////////////////////////////////////////////////////////////////////////
unsigned short send_16bit_SPI( uint16 data16 )
{
    unsigned short rxData = 0;

    // Send data from master
    sendBuf[1] = data16 & 0xFF;
    sendBuf[0] = (data16 >> 8) & 0xFF;

    // Add code to send a SPI word
    IoHwAb_SPI_Write(x, y);
//    TransferData_QSPI1(&masterDataSend[0], &masterDataReceive[0],2);

    rxData = ((sendBuf[1] << 8) & 0xFF00) | sendBufRxBuf[0];
    return rxData;
}


uint16 send_32bit_SPI( uint16 data16 )
{
    unsigned short rxData = 0;

    // Send data from master
    sendBuf[1] = data16 & 0xFF;
    sendBuf[0] = (data16 >> 8) & 0xFF;

    // Add code to send a SPI word
    IoHwAb_SPI_Write_32(x, y);
//    TransferData_QSPI1(&masterDataSend[0], &masterDataReceive[0],2);

    rxData = ((sendBuf[1] << 8) & 0xFF00) | sendBufRxBuf[0];
    return rxData;
}
