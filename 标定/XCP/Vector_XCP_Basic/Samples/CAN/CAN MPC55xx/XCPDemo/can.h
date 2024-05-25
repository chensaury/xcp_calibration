/*----------------------------------------------------------------------------
| File:
|   
|
| Project:
|   Sample XCP driver for MPC5554
|   CANape Calibration Tool
|
| Description:
|   
|   
|
 ----------------------------------------------------------------------------*/
#ifndef __CAN_H__
#define __CAN_H__


#define MEMORY_ROM const

//#define LOOP_BACK
//#define CAN_TEST
 
 
// TS1 = PROPSEG + PSEG1 + 2  =  2 + 7 + 2 = 11
// TS2 = PSEG2 + 1            =  3 + 1     = 4
// SYNCSEG = 1                             = 1
//                                        -----
//                                           16

//#define CAN_OVERCLOCK
#ifdef CAN_OVERCLOCK
  #if CPU_CLOCK==128
    #define CAN_PRESDIV 7                    // PRESDIV = 7 -> CLOCK = 128/8 = 16
  #else
    #error CPU_CLOCK undefined
  #endif
  #define CAN_CTRL0 ((3<<6)|(0<<3)|(2<<0)) // RJW, PSEG1=7, PSEG2=3
#else
  #if CPU_CLOCK==128
    #define CAN_PRESDIV 7                    // PRESDIV = 7 -> CLOCK = 128/8 = 16
  #elif CPU_CLOCK==80
    #define CAN_PRESDIV 4                    // PRESDIV = 4 -> CLOCK = 80/5 = 16
  #else
    #error CPU_CLOCK undefined
  #endif
  #define CAN_CTRL0 ((3<<6)|(7<<3)|(3<<0)) // RJW, PSEG1=7, PSEG2=3
#endif
#ifdef LOOP_BACK
#define CAN_CTRL1 (0x20|0x10)            // CLKSRC=1 (System), LPB=1 (Loopback)
#else
#define CAN_CTRL1 (0x20|0x00)            // CLKSRC=1 (System), LPB=1 (Loopback)
#endif
#define CAN_CTRL2 (0x10|0x02)            // LBUF, PROP_SEG=2

/* Number of message buffers */
#define CAN_MAX_OBJ (64-1)

/* Use buffers 0-54 for DAQ and BLOCK_UPLOAD */
//#define CAN_DAQ_OBJ_FIRST 0
//#define CAN_DAQ_OBJ_LAST  54
//#define CAN_DAQ_OBJ_COUNT 55

/* Use buffer 62 as XCP TX object */
#define CAN_TX_ID         0x200
#define CAN_TX_OBJ        62
#define CAN_TX_OBJ_MASK   (1u << (CAN_TX_OBJ-32))
#define CAN_TX_OBJ_IFLAG  FlexCAN.iFlag1


/* Use buffer 63 as XCP RX object */
#define CAN_RX_ID          0x201
#define CAN_RX_OBJ         63
#define CAN_RX_OBJ_MASK    (1u << (CAN_RX_OBJ-32))
#define CAN_RX_OBJ_IFLAG   FlexCAN.iFlag1



/* -- Bitmasks of CAN command register CANMCR ------------------------------ */
#define kFlexCANStop       0x8000    /* Stop bit, switch to low power mode   */
#define kFlexCANNotRdy     0x0800    /* Not ready bit                        */
#define kFlexCANSelfWake   0x0000    /* Not available                        */
#define kFlexCANStpAk      0x0010    /* Stop ack                             */
#define kFlexCANFreeze     0x4000    /* Freeze enable                        */
#define kFlexCANFrzAck     0x0100    /* Freeze acknowledge                   */
#define kFlexCANHalt       0x1000    /* Bit for FlexCAN debug mode           */
#define kFlexCANSoftReset  0x0200    /* Bit for FlexCAN soft reset           */

/* -- Bitmasks of CAN error status register ESTAT -------------------------- */
#define kFlexCANBoff       0x0004    /* FlexCAN is in bus off state          */

/* -- Code definitions for receive objects --------------------------------- */
#define kRxCodeNotActive   0x0000    /* Message buffer is not active         */
#define kRxCodeEmpty       0x0400    /* Message buffer is active and empty   */

/* -- Code definitions for transmit objects -------------------------------- */
#define kTxCodeTransmit    0x0C00    /* Start transmit session               */
#define kTxCodeInactive    0x0800    /* Transmit object not ready            */


/* -- Base address of FlexCAN module ----------------------------------------*/
#define FlexCAN (*((volatile tFlexCAN *)(0xFFFC0000)))

/* -- FlexCAN Message buffer structure ------------------------------------- */
typedef struct
{
  vuint16 CtrlStat;           /* Time stamp, code and DLC                    */
  vuint16 timeStamp;          /* Time stamp                                  */
  vuint16 IdHi;               /* ID, RTR                                     */
  vuint16 IdLo;               /* 16-bit time stamp                           */
  vuint8  DataFld[8];         /* Data buffer of CAN message                  */
} tInternalMsgObject;


/* -- FlexCAN register set ------------------------------------------------- */
typedef struct
{
  vuint16   canMCR;       /* 00 Module Configuration Register */
  vuint8    rsv0;         /* 02 Reserved */
  vuint8    canMaxMB;     /* 03 Maximum Message Buffer */
  vuint8    prDiv;        /* 04 Prescal Divider */
  vuint8    canCtrl0;     /* 06 CAN Control 0 */
  vuint8    canCtrl1;     /* 07 CAN Control 1 */
  vuint8    canCtrl2;     /* 05 CAN Control 2 */
  vuint16   rsv1;         /* 08 Reserved */
  vuint16   timer;        /* 0A Timer */
  vuint16   rsv2;         /* 0C Reserved */
  vuint16   rsv3;         /* 0E Reserved */
  vuint16   rxGMskHi;     /* 10 Rx Global Mask Hi */
  vuint16   rxGMskLo;     /* 12 Rx Global Mask Lo */
  vuint16   rx14MskHi;    /* 14 Rx 14 Mask Hi */
  vuint16   rx14MskLo;    /* 16 Rx 14 Mask Lo */
  vuint16   rx15MskHi;    /* 18 Rx 15 Mask Hi */
  vuint16   rx15MskLo;    /* 1A Rx 15 Mask Lo */
  vuint16   rsv4;         /* 1C Reserved */
  vuint8    rxErrCtr;     /* 1E Rx Error Counter */
  vuint8    txErrCtr;     /* 1F Tx Error Counter */
  vuint16   rsv5;         /* 20 Reserved */
  vuint16   ESR;          /* 22 Error / Status */
  vuint32   iMask1;       /* 24 Interrupt Mask 2 (MB 32 - 63) */
  vuint32   iMask0;       /* 28 Interrupt Mask 1 (MB  0 - 31) */
  vuint32   iFlag1;       /* 2C Interrupt Flag 2 (MB 32 - 63) */
  vuint32   iFlag0;       /* 30 Interrupt Flag 1 (MB  0 - 31) */
  vuint8    rsv8[76];     /* 34 - 80 reserve */
  tInternalMsgObject canObject[CAN_MAX_OBJ]; /* Buffer for kCanMaxMB messages */
}tFlexCAN;


/* Function Prototypes *******************************************************/

void    CanInit( void );
vuint8  CanMsgTransmitted( void );
vuint8  CanTransmit( vuint16 id, vuint8 dlc, vuint8 *data );
vuint8  CanGetRxMsg( vuint8 *dlc, vuint16 *id, vuint32 *data );





#endif

/* End of file ***************************************************************/
