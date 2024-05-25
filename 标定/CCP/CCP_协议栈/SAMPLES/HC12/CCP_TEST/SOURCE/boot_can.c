/*******************************************************************************

  File Name   : boot_can.c
  Date        : 14.08.2001
  Version     : 1.0
  Desciption  : free CAN driver for CCP without using interrupts

*******************************************************************************/


// -----------------------------------------------------------------------------
// INCLUDE FILES
// -----------------------------------------------------------------------------
#include <iod60.h>               // standard HC12 IO
#include "ccppar.h"              // CPP config file
#include "boot_can.h"            // CAN driver
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// DEFINES
// -----------------------------------------------------------------------------

#define CAN_BTR0         0x0043         // CAN-Bus-Timing
#define CAN_BTR1         0x0014         // 500 KBaud

#define SYNCH            0x0010         // SYNCH-Bit
#define RXF              0x0001         // receive buffer
#define TXE0             0x0001         // transmit buffer 0

#define REG_BLOCK_ADR    0x0000         // address of register block
#define REG_BLOCK_OFFSET 0x0100         // offset to CAN register

#define msCAN12 (*((t_msCAN12*)(REG_BLOCK_ADR + REG_BLOCK_OFFSET)))
// -----------------------------------------------------------------------------




// -----------------------------------------------------------------------------
// VARIABLES and Structs
// -----------------------------------------------------------------------------
unsigned int g_ccp_dto_id;              // global DTO-ID
unsigned int g_ccp_cro_id;              // global CRO-ID

typedef volatile struct
{
   WORD  Id;              // ID
   BYTE  IdEx1;           // Extended ID bytes; not used
   BYTE  IdEx2;
   BYTE  DataFld[8];      // Data 0 .. 7
   BYTE  DLC;             // Data length reg.:  X X X X DLC3 DLC2 DLC1 DLC0
   BYTE  PRIO;            // TxBuf priority reg.
   BYTE  unused[2];
} t_MsgObject;


typedef volatile struct
{
  BYTE      CMCR0;        // 0 0 CSWAI SYNCH TLNKEN SLPAK SLPRQ SFTRES
  BYTE      CMCR1;        // 0 0 0 0 0 LOOPB WUPM CLKSRC
  BYTE      CBTR0;        // SJW1 SJW0 BRP5 ... BRP0
  BYTE      CBTR1;        // SAMP TSEG22 TSEG21 TSEG20 TSEG13 ... TSEG10
  BYTE      CRFLG;        // WUPIF RWRNIF TWRNIF RERRIF TERRIF BOFFIF OVRIF RXF
  BYTE      CRIER;        // WUPIE RWRNIE TWRNIE RERRIE TERRIE BOFFIE OVRIE RXE
  BYTE      CTFLG;        // 0 ABTAK2 ABTAK1 ABTAK0 0 TXE2 TXE1 TXE0
  BYTE      CTCR;         // 0 ABTRQ2 ABTRQ1 ABTRQ0 0 TXEIE2 TXEIE1 TXEIE0
  BYTE      CIDAC;        // 0 0 IDAM1 IDAM0 0 0 IDHIT1 IDHIT0
  BYTE      reserved1[5];
  BYTE      CRXERR;       // RXERR7 ... RXERR0
  BYTE      CTXERR;       // TXERR7 ... TXERR0
  BYTE      CIDAR0;       // Filter Masks 0..3
  BYTE      CIDAR1;
  BYTE      CIDAR2;
  BYTE      CIDAR3;
  BYTE      CIDMR0;
  BYTE      CIDMR1;
  BYTE      CIDMR2;
  BYTE      CIDMR3;
  BYTE      CIDAR4;       // Filter Masks 4..7
  BYTE      CIDAR5;
  BYTE      CIDAR6;
  BYTE      CIDAR7;
  BYTE      CIDMR4;
  BYTE      CIDMR5;
  BYTE      CIDMR6;
  BYTE      CIDMR7;
  BYTE      reserved2[29];
  BYTE      PCTLCAN;      // 0 0 0 0 0 0 PUECAN
  BYTE      PORTCAN;      // PCAN7 ... PCAN0
  BYTE      DDRCAN;       // DDRCAN7 ... DDRCAN0
  t_MsgObject   RxBuf;    // Rx-Msg Object
  t_MsgObject   TxBuf[3]; // Tx-Msg Objects
} t_msCAN12;
/* STOPSINGLE_OF_MULTIPLE */

// -----------------------------------------------------------------------------



// -----------------------------------------------------------------------------
// CAN INITIALISATION
// -----------------------------------------------------------------------------
void ccpBootInit (int cro_id, int dto_id)
{
  g_ccp_dto_id = dto_id;       // handover IDs (CRO, DTO)
  g_ccp_cro_id = cro_id;

  msCAN12.CMCR0  |= 0x01;      // enter soft reset state
  msCAN12.CMCR1  |= 0x01;      // set timing reg.
  msCAN12.CBTR0  = CAN_BTR0;   // baud rate
  msCAN12.CBTR1  = CAN_BTR1;
  msCAN12.CRIER  = 0x00;       // disable receive interrupt
  msCAN12.CIDAC  = 0x00;       // set filter, twice 32-bit
  msCAN12.CIDAR0 = 0x00;       // set ID acceptance register 0..3
  msCAN12.CIDAR1 = 0x00;
  msCAN12.CIDAR2 = 0x00;
  msCAN12.CIDAR3 = 0x00;
  msCAN12.CIDMR0 = 0xFF;       // filter full open
  msCAN12.CIDMR1 = 0xFF;
  msCAN12.CIDMR2 = 0xFF;
  msCAN12.CIDMR3 = 0xFF;
  msCAN12.CIDAR4 = 0x00;       // set ID acceptance register 4..7
  msCAN12.CIDAR5 = 0x00;
  msCAN12.CIDAR6 = 0x00;
  msCAN12.CIDAR7 = 0x00;
  msCAN12.CIDMR4 = 0xFF;       // filter full open
  msCAN12.CIDMR5 = 0xFF;
  msCAN12.CIDMR6 = 0xFF;;
  msCAN12.CIDMR7 = 0xFF;
  msCAN12.CTCR  &= 0x00;       // and disable appropriate TX-interrupt
  msCAN12.CMCR0 &= 0xFE;       // quit soft reset mode, clear bit 0
// -----------------------------------------------------------------------------
} /* ccpBootInit */




// -----------------------------------------------------------------------------
// CAN TRANSMIT (Data Frame)
// -----------------------------------------------------------------------------
int ccpBootTransmitCrmPossible( void ) {

  return ((msCAN12.CTFLG & TXE0) == 1);        // return 1 if so
}
// -----------------------------------------------------------------------------
void ccpBootTransmitCrm (unsigned char *msg)
{
   if ((msCAN12.CMCR0 & SYNCH) == 0)return;    // check if bus is snychronized
   if ((msCAN12.CTFLG & TXE0) == 0) return;    // check if buffer is empty

   msCAN12.TxBuf[0].Id = (g_ccp_dto_id<<5);    // convert id for id register

   msCAN12.TxBuf[0].PRIO = 0;                  // priority high!
   msCAN12.TxBuf[0].DLC  = 8;                  // data length 8 byte
   msCAN12.TxBuf[0].DataFld[0] = *msg++;       // store message
   msCAN12.TxBuf[0].DataFld[1] = *msg++;
   msCAN12.TxBuf[0].DataFld[2] = *msg++;
   msCAN12.TxBuf[0].DataFld[3] = *msg++;
   msCAN12.TxBuf[0].DataFld[4] = *msg++;
   msCAN12.TxBuf[0].DataFld[5] = *msg++;
   msCAN12.TxBuf[0].DataFld[6] = *msg++;
   msCAN12.TxBuf[0].DataFld[7] = *msg++;

   msCAN12.CTFLG = TXE0;                       // signal for hc12 to send buffer_0

} /* ccpBootTransmitCrm */
// -----------------------------------------------------------------------------



// -----------------------------------------------------------------------------
// CAN RECEIVE (Data Frame)
// -----------------------------------------------------------------------------
int ccpBootReceiveCro (unsigned char *msg)
{
  WORD id;

  if ((msCAN12.CRFLG & RXF) == 0) return 0;    // check if receive buffer is full

  id = msCAN12.RxBuf.Id >> 5;

  *msg++ = msCAN12.RxBuf.DataFld[0];           // store received message in buffer
  *msg++ = msCAN12.RxBuf.DataFld[1];
  *msg++ = msCAN12.RxBuf.DataFld[2];
  *msg++ = msCAN12.RxBuf.DataFld[3];
  *msg++ = msCAN12.RxBuf.DataFld[4];
  *msg++ = msCAN12.RxBuf.DataFld[5];
  *msg++ = msCAN12.RxBuf.DataFld[6];
  *msg++ = msCAN12.RxBuf.DataFld[7];

  msCAN12.CRFLG = RXF;                         // signal for hc12 to release buffer

  if (id == g_ccp_cro_id) return 1;            // if correctly received, return 1
  return 0;

} /* ccpBootReceiveCro */
// -----------------------------------------------------------------------------
