/* CAN.H */

#define ulong unsigned long
#define uword unsigned int
#define ubyte unsigned char

//****************************************************************************
//  Definition of a structure for the CAN data
//****************************************************************************

// The following data type serves as a software message object. Each access to
// a hardware message object has to be made by forward a pointer to a software
// message object (TCAN_Obj). The data type has the following fields:
//
// ubMsgCfg:
// this byte has the same structure as the message configuration register of a
// hardware message object. It contains the "Data Lenght Code" (DLC), the "Extended
// Identifier" (XTD) and the "Message Direction" (DIR, read only access).
//
//         7     6     5      4    3     2     1     0
//      |-----------------------------------------------|
//      |        DLC            | DIR | XTD |  0  |  0  |
//      |-----------------------------------------------|
//
// ulId: 
// this field is four bytes long and contains either the 11-bit identifier 
// or the 29-bit identifier (as a HEX-Value)
//
// ubData[8]:
// 8 bytes containing the data of a frame
//

typedef struct
{
     ulong ulId;       // Standard (11-bit) or Extended (29-bit) identifier
     ubyte ubData[8];  // 8-bit Data Bytes (Must be WORD aligned)
     ubyte ubMsgCfg;   // 8-bit Message Configuration Register
} TCAN_Obj;


//****************************************************************************
//  Prototypes of global functions
//****************************************************************************

void CAN_vInit(void);
void CAN_vSetMsgDlc(ubyte ObjNr, ubyte dlc);
void CAN_vGetMsgObj(ubyte ObjNr, TCAN_Obj *pstObj);
bit CAN_bRequestMsgObj(ubyte ObjNr);
bit CAN_bNewData(ubyte ObjNr);
void CAN_vTransmit(ubyte ObjNr);
void CAN_vLoadData(ubyte ObjNr, ubyte *pubBuffer);
bit CAN_bDelMsgObj(ubyte ObjNr);
bit CAN_bMsgLost(ubyte ObjNr);
void CAN_vReleaseObj(ubyte ObjNr);



//****************************************************************************
//  Defines
//****************************************************************************

// Control/Status Register
#define C1CSR   (*((uword volatile *) 0xEF00))

// Interrupt Register
#define C1IR    (*((uword volatile *) 0xEF02))

// Bit Timing Register
#define C1BTR   (*((uword volatile *) 0xEF04))

// Global Mask Short
#define C1GMS   (*((uword volatile *) 0xEF06))

// Upper Global Mask Long
#define C1UGML  (*((uword volatile *) 0xEF08))

// Lower Global Mask Long
#define C1LGML  (*((uword volatile *) 0xEF0A))

// Upper Mask of Last Message
#define C1UMLM  (*((uword volatile *) 0xEF0C))

// Lower Mask of Last Message
#define C1LMLM  (*((uword volatile *) 0xEF0E))


// Structure for a single CAN object
// A total of 15 such object structures exists (starting at EF10H)

struct can_obj 
{
  uword  MCR;       // Message Control Register
  uword  UAR;       // Upper Arbitration Register
  uword  LAR;       // Lower Arbitration Register
  ubyte  MCFG;      // Message Configuration Register
  ubyte  Data[8];   // Message Data 0 .. 7
  ubyte  Res;       // Reserved for application specific data
};

#define CAN_OBJ_PTR  struct can_obj volatile *
#define CAN_OBJP(i)  (((struct can_obj volatile *)0xEF10)+i)
#define CAN_OBJ      ((struct can_obj volatile *)0xEF10)


