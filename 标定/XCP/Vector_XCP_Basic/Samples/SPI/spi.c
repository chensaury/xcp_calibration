/*----------------------------------------------------------------------------
| File:
|   SPI.C
|
| Project:
|   XCP on SPI Sample
|
| Description:
|   SPI Driver
|
 ----------------------------------------------------------------------------*/

#include "reg_m63200.h"
#include "main.h"
#include "spi.h"
#include "xcpBasic.h"


// Correct the SPI byte order here
// Unfortunatly the Atmel SPI does not use the same byte order as the SxLCase
// This will let us loose some performance
// This can be done by CANape or the SxLCase in future versions 

#define DMA_SWAP  


#define SPI_MAX_RX kXcpMaxDTO+4
#define SPI_MAX_TX kXcpMaxDTO+4

uint8   tx_buffer[SPI_MAX_TX]; 
uint8   rx_buffer[SPI_MAX_RX]; 
uint8   rx_buffer_DMA[SPI_MAX_RX]; 
uint8   rx_xcp_buffer[SPI_MAX_RX]; 
uint16  uiSpiTxCounter;
uint16  uiTxLength;
Bool    bEventSPIxcpCmd, bEventSPIpacketLost;



//------------------------------------------------------------------------------------------
// XCP Driver Callbacks

// Convert an XCP address to a pointer
MTABYTEPTR ApplXcpGetPointer( vuint8 addr_ext, vuint32 addr ) {

  return (MTABYTEPTR)addr;
}


// Called if XcpSendEvent can not transmit, because ApplXcpSend is busy
// In this case just cancel the request
vuint8 ApplXcpSendStall( void ) {

  // Cancel the transmission request for a dummy event message
  xcp.SendStatus &= ~XCP_EVT_REQUEST;
  return 0;
}


// Called by the XCP driver to transmit a XCP message
void ApplXcpSend( vuint8 ucLength, const BYTEPTR ucData ) {

  #ifdef DMA_SWAP
    register int i;
  #endif
    
  PIOA_BASE->PIO_SODR = PA5; // runtime measurement

  // Dummy message
  if (ucLength==2&&ucData[0]==0xFD&&ucData[1]==0xFF) {
    uiTxLength = kXcpMaxCTO+4; // This allows a kXcpMaxCto lenght XCP message to be received
                               // during the transmit of the dummy message
    #ifndef DMA_SWAP
      ucData[1]=0xFD;
      ucData[0]=0xFF;
    #endif
  }

  // Normal message
  else {
    if (ucLength<8) {
      ucLength=8;
    }
    if ((ucLength&0x01)!=0) {
      uiTxLength=ucLength+1;
    } else {
      uiTxLength = ucLength;
    }
    uiTxLength = uiTxLength + 4;

    // Restart the dummy event timer
    ulTimerCounter0 = 0;
  }

  // Set up rx buffer
  *(uint16*)&rx_buffer[0] = 0;
  SPI_BASE->SP_RPR = (uint32)rx_buffer_DMA; // set receive pointer register to receive data buffer 
  SPI_BASE->SP_RCR = SPI_MAX_RX;            // receive counter 
  
  // Set up tx buffer
  tx_buffer[0] = 0;
  tx_buffer[1] = ucLength;
  tx_buffer[2] = (uint8)(uiSpiTxCounter>>8);
  tx_buffer[3] = (uint8)uiSpiTxCounter;
  
  #ifdef DMA_SWAP
    
    for (i=4;i<uiTxLength;i+=2) {
      tx_buffer[i+1] = *ucData++;
      tx_buffer[i] = *ucData++;
    }
    
    // swab(ucData,&tx_buffer[4],uiTxLength-4);
  #else
    memcpy(&tx_buffer[4],ucData,uiTxLength-4);
  #endif
  uiSpiTxCounter++;
  SPI_BASE->SP_TPR = (uint32)tx_buffer;
  SPI_BASE->SP_TCR = uiTxLength/2;    

  PIOA_BASE->PIO_CODR = PA5; // runtime measurement

}



//------------------------------------------------------------------------------------------
// SPI Driver

// Transmit a XCP dummy message to keep the communication alive
Bool spiTransmitDummy(void) {

  // Transmit a dummy event
  uiSpiTxCounter--;
  XcpSendEvent( 0xFF, 0, 0);
  return kTrue;
}


// Transmit buffer empty interrupt
__interrupt void spi_isr(void) {

  #ifdef DMA_SWAP
    uint16  i;
  #endif

  PIOA_BASE->PIO_SODR = PA4; // runtime measurement

  // Check if there is something in the receive buffer
  // which was received during the last transmit
  if ((rx_buffer_DMA[0]!=0) || (rx_buffer_DMA[1]!=0)) {

    // Copy this to rx buffer for XCP commands
    #ifdef DMA_SWAP
      for (i=0;i<SPI_MAX_RX;i=i+2) {
        rx_buffer[i] = rx_buffer_DMA[i+1];
        rx_buffer[i+1] = rx_buffer_DMA[i];
      }
      memcpy(rx_xcp_buffer, (uint8*)((uint32)rx_buffer+(uint32)4), SPI_MAX_RX-4);
    #else
      memcpy(rx_xcp_buffer, (uint8*)((uint32)rx_buffer_DMA+(uint32)4), SPI_MAX_RX-4);
    #endif
      
    bEventSPIxcpCmd = kTrue; // This flag indicates that there has been something received
    uiSpiTxCounter--;
  }
  
  // Notify the XCP driver, that the next message can be transmitted
  XcpSendCallBack();

  PIOA_BASE->PIO_CODR = PA4; // runtime measurement

  AIC_EOICR = SPI_BASE->SP_SR; // Interrupt done
}


// Initialize the SPI interface
Bool spiInit(void) {
  
  PMC_PCER = PMC_SPI_CLK_EN;    // activate clock for SPI 

  PIOA_BASE->PIO_PDR = PA23 | PA24 | PA25 | PA26 | PA27 | PA28 | PA29; // disable PIO control of pins 

  SPI_BASE->SP_MR = SP_MSTR;  // master mode select 
  SPI_BASE->SP_IDR = 0x1F;    // disable interrupts 
  SPI_BASE->SP_IER = 0x20;    // enable interrupts 
  SPI_BASE->SP_RCR = SPI_MAX_RX;    // receive counter 
  SPI_BASE->SP_TCR = 0x00;    // transmit counter 
  SPI_BASE->SP_CSR[0] = SP_BITS_16   // chip select register: 16 bits per transfer,
    | (2 << 8)                       // 6,25 MBaud 
    | (15 << 16)                     // delay before clock 15x MasterClock = 2.5x SPIClock
    | (1 << 24)                      // delay between consecutive frames set to 1 -> 8 bit
    ;

  uiSpiTxCounter = 0;
  SPI_BASE->SP_CR = SP_SPIEN;  // enable SPI 

  AIC_SMR5 = 0x24;              // 5 = SPI, prio 4
  AIC_SVR5 = (uint32)spi_isr;
  AIC_ICCR = 0x0020;            // clear spi irq
  AIC_IECR = 0x0020;            // enable spi irq

  return kTrue;
}

