/*----------------------------------------------------------------------------
| File:
|   XCPSIM.C
|
| Project:
|   PC Emulation of a ECU using XCP on Ethernet or XCP on CAN
|
 ----------------------------------------------------------------------------*/


// CAN driver
#include "VCanD.h"

// XCP driver
#include "xcpbasic.h"

// ECU simulation
#include "ecu.h"

// XCP handler
#include "xcpsim.h"



///////////////////////////////////////////////////////////////////////
// Globals


int tcpMode                  = 0; // Ethernet or CAN, default is CAN
int mainRunning              = 0; // Status
unsigned short gTimer        = 0; // DAQ clock 
vuint8 gDebugLevel           = 1; // Debug output 
  extern BYTE __xc_a;
  static DWORD dataSeg =0/* (DWORD)&__xc_a*/;
V_MEMROM0 vuint8 MEMORY_ROM kXcpStationId[]="XCPSIM";


#if defined ( XCP_ENABLE_VECTOR_MAPNAMES )

#define MAP_FORMAT 29
#define MAP_NAME   "xcpsim"

unsigned char MapTest[500];
unsigned int MapTestSize;

vuint32 ApplXcpGetIdData( vuint8 **pData) {

  MapTestSize = sprintf((char*)MapTest,"%c%c%s.map",MAP_FORMAT,0,MAP_NAME);
  *pData = MapTest;
  return MapTestSize;
}

#endif



/**************************************************************************/
// ApplXcpSend()
// ApplXcpSendFlush()
// ApplXcpGetPointer() 
// ApplXcpGetSeed()
// ApplXcpUnlock()
// Platform and implementation specific functions for the XCP driver
/**************************************************************************/


// Flush the tranmit queue
void ApplXcpSendFlush(void) {

  if (tcpMode) {

    tcpSendFlush();

  } 
}


// Transmit a message
void ApplXcpSend( vuint8 len, MEMORY_ROM BYTEPTR msg  ) {

  if (tcpMode) {

    tcpSend( len, msg );
    XcpSendCallBack();

  } 
  else {

    canSend( len, msg );

  }


}


// Convert a XCP (BYTE,DWORD) address to a C pointer
BYTEPTR ApplXcpGetPointer( BYTE addr_ext, DWORD addr ) 
{
  
  BYTEPTR a = (BYTEPTR)(addr /*+ dataSeg*/);
  return (BYTEPTR) a;
}


// Seed & Key
#if defined(XCP_ENABLE_SEED_KEY) || defined(XCP_ENABLE_SEED_KEY)

BYTE xcpResourceMask = 0;

BYTE ApplXcpGetSeed( BYTE resourceMask, BYTE *seed )
{
  
  xcpResourceMask = resourceMask;

  /* Generate the seed */
  seed[0] = 0;
  seed[1] = 1;
  seed[2] = 2;
  seed[3] = 3;
  seed[4] = 4;
  seed[5] = 5;

  return 0;
}

vuint8 ApplXcpUnlock( MEMORY_CONST vuint8 *key, vuint8 length )
{
  /* Ckeck the key */
  /* key[0],key[1],key[2],key[3],key[4],key[5] */

  xcp.ProtectionStatus &= ~xcpResourceMask; /* Reset the appropriate resource protection mask bit */
  return 1;
}

#endif




///////////////////////////////////////////////////////////////////////
// main()
//---------------------------------------------------------------------
//

// help
static void usage( void ) {

  printf(
    "\n"
    "Usage:\n"
    "  XCPsim [options]\n"
    "\n"
    "  Options:\n"
    "    -tx      Set output verbosity to x (0=Off,1=Cmd,2=+Res,3=+Raw CRO/DTO,4=+Raw CAN)\n"
    "\n"
    "  XCP Options:\n"
    "    -cro<x>  Set CRO identifier to x (Default 1)\n"
    "    -dto<x>  Set DTO identifier to x (Default 2)\n"
    "    -x       Use extended ids (Default standard)\n"
    "    -addr<x> Set slave address to x (Default 1)\n"
    "\n"
    "  Ethernet Options:\n"
    "    -udp     Use UDP\n"
    "    -tcp     Use TCP/IP\n"
    "    -port<x> Use port x (Default 5555)\n"
    "\n"
    "  CAN Options (Defaults from CAN-Hw Applet):\n"
    "    -b<x>    Set CAN bitrate to x (5000-1000000)\n"
    "    -v       Use a virtual channel\n"
    "    -1       Use channel 1\n"
    "    -2       Use channel 2\n"
    "\n"
    "  Keyboard Commands:\n"
    "    ESC      Exit\n"
    "\n"
    );

    
}

// Keyboard handler
int handleKey( int key ) {

  switch (key) {

    // ESC
    case 27:
      return 1;
      break;

    default:
      break;
  }

  return 0;
}


static HANDLE threadHandle   = 0;
static DWORD threadId        = 0;
static int threadRunning     = 0;

// Task Sheduler
static DWORD WINAPI thread( PVOID par ) {

  WORD i = 0;
  WORD j = 0;

  threadRunning = 1;
  while (threadRunning) {

    Sleep(10);

    if (mainRunning) {

     /* 10ms Task ECU Simulation */
      ecuCyclic();

      /* Event Channel 1 is cyclic 1 ms */
      #ifdef XCP_ENABLE_DAQ
      for (j=0;j<10;++j) {
        gTimer += 1;
        XcpEvent(3);

      }
      #endif

      /* Event Channel 1 is cyclic 10 ms */
      #ifdef XCP_ENABLE_DAQ
      #ifdef XCP_DPRAM_SERVER
        dpramServerTriggerTask(1);
      #else
        XcpEvent(1);
      #endif
      #endif

      if (i++%10==0) {

        /* Event Channel 2 is cyclic 100 ms */
        #ifdef XCP_ENABLE_DAQ
            XcpEvent(2);
        #endif
 
        /* Flush every 100ms */
        ApplXcpSendFlush();
    
      }
      /* XCP driver background processing */
      #ifdef XCP_ENABLE_CHECKSUM
        XcpBackground();
      #endif  

    }
  }

  return 0;
}


// Mainloop
int main( int argc, char *argv[])
{
  int i;
  unsigned int u;

  printf(
    "XCPsim ECU simulator for Ethernet or CAN (Basic Version) \n"
    "Vector Informatik GmbH, 2004\n\n"
    "Build " __DATE__ " " __TIME__ "\n"
  );


  // Get the channel assignment from the CAN control panel
  canGetDefaults();


  // Parse commandline
  for (i=1; i<argc; i++) {
      char c;
      if (strcmp(argv[i], "-h") == 0) {
          usage();
          exit(0);
      } else if (strcmp(argv[i], "-v") == 0) {
          hwType = HWTYPE_VIRTUAL;
          printf("Use a virtual channel\n");
      } else if (strcmp(argv[i], "-x") == 0) {
          gDtoId |= 0x80000000UL;
          gCroId |= 0x80000000UL;
          printf("Extended Ids\n");
      } else if (strcmp(argv[i], "-1") == 0) {
          hwChannel = 0;
          printf("Use channel 1\n");
      } else if (strcmp(argv[i], "-2") == 0) {
          hwChannel = 1;
          printf("Use channel 2\n");
      } else if (sscanf(argv[i], "-b%u", &u) == 1) {
        if (u>5000&&u<=1000000) gBitRate = u;
        printf("Initialize CAN hardware to %u BPS\n",gBitRate);
      } else if (sscanf(argv[i], "-cro%u", &u) == 1) {
        gCroId = u;
      } else if (sscanf(argv[i], "-dto%u", &u) == 1) {
        gDtoId = u;
      } else if (strcmp(argv[i], "-tcp") == 0) {
          tcpMode = 1;
          gProto = SOCK_STREAM;
          printf("Using TCP/IP\n");
      } else if (strcmp(argv[i], "-udp") == 0) {
          tcpMode = 1;
          gProto = SOCK_DGRAM;
          printf("Using UDP\n");
      } else if (sscanf(argv[i], "-port%u", &u) == 1) {
        gPort = u;
        printf("Using port %u\n",u);
      } else if (sscanf(argv[i], "-t%c", &c) == 1) {
          gDebugLevel = c-'0';
          printf("Set screen output verbosity to %u\n",gDebugLevel);
      } else {
          usage();
          exit(0);
      }

  }

  // Set default hardware configuration in VCANCONF
  ncdSetApplConfig("XCPsim",0,hwType,hwIndex,hwChannel);


  // Initialize XCP driver
  XcpInit();


  // Initialize ECU simulation
  ecuInit();
 
  printf("\n CALRAM_ADDR  = 0x%08X\n",(BYTE*)&CALRAM_START-dataSeg);
  printf(" CALRAM_SIZE  = 0x%08X\n",(BYTE*)&CALRAM_LAST-(BYTE*)&CALRAM_START+1);
 
                
 
  // Create the DAQ thread
  threadHandle = CreateThread(0,0x1000,thread,0,0,&threadId);
  SetThreadPriority(threadHandle,THREAD_PRIORITY_TIME_CRITICAL);

  // Mainloop
  if (tcpMode) {
    tcpMain();
  } else {
    canMain();
  }

  // Stop DAQ thread
  if (threadHandle) {
    threadRunning = 0;
    WaitForSingleObject(threadHandle,5000);
  }


}

