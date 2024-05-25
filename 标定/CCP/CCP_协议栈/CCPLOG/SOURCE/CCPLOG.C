/*----------------------------------------------------------------------------
| File:
|   CCPLOG.C
| Project:
|   Simple CCP Logging Utility
|
 ----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------

 Version History:

   V1.10, 11.11.2002
    - gp	Added acceptance filter for extended IDs (InitDriver( ))
   V1.11, 18.11.2002
    - Ds Added option -e for extended id's
 ---------------------------------------------------------------------------*/

#define  STRICT
#include <windows.h>

#include "stdio.h"
#include "conio.h"

// CAN driver
#include "VCanD.h"

// CCP handler
#define CCP_TESTMODE

#define CCP_LOGVERSION 111

#include "ccp.h"


///////////////////////////////////////////////////////////////////////
// Parameters
unsigned long gBitRate       = 0;
unsigned int gHwType         = HWTYPE_CANCARDX;
unsigned int gHwIndex        = 0;
unsigned int gHwChannel      = 0;
unsigned char gDebugLevel    = 1;
DWORD gDtoId                 = 0,
      gCroId                 = 0;
int gMotorola                = 0;
int gCCPVersion              = 200;
int gLogging                 = 0;
int gOffline                 = 0;
int gExtendedid              = 0;
int gCCPLogversion           = CCP_LOGVERSION;

///////////////////////////////////////////////////////////////////////
// Global

VportHandle gPortHandle      = INVALID_PORTHANDLE;
Vaccess gChannelMask         = 0;
Vaccess gPermissionMask      = 0;
unsigned char gLastCmd       = 0;
unsigned int gLastTime       = 0;

unsigned int gMsgCount       = 0;
unsigned int gDtoCount       = 0;
unsigned int gCroCount       = 0;
FILE * gLogFile              = 0;

///////////////////////////////////////////////////////////////////////
// Code
// if motorola, swap the bytes

#define SWAP_MOTOROLA(p,n) if (gMotorola) toMotorola(p,n);

static void toMotorola( void *p0, unsigned int n ) {

  unsigned char b;
  unsigned char *p = p0;
  switch (n) {
    case 4:
      b = p[3]; p[3] = p[0]; p[0] = b;
      b = p[2]; p[2] = p[1]; p[1] = b;
      break;
    case 2:
      b = p[0]; p[0] = p[1]; p[1] = b;
      break;
  }
}

// CRC commands

#define CRC_OK                 0x00
#define CRC_DAQ_OVERLOAD       0x01
#define CRC_CMD_BUSY           0x10
#define CRC_DAQ_BUSY           0x11
#define CRC_TIMEOUT            0x12
#define CRC_KEY_REQUEST        0x18
#define CRC_SS_REQUEST         0x19
#define CRC_COLD_START_REQUEST 0x20
#define CRC_CMD_UNKNOWN        0x30
#define CRC_CMD_SYNTAX         0x31
#define CRC_CMD_RANGE          0x32
#define CRC_NO_ACCESS          0x33
#define CRC_OVERLOAD           0x34
#define CRC_LOCKED             0x35
#define CRC_RESOURCE_NAV       0x36


static char *ccpErrorStr( int err ) {

  switch (err) {
    case CRC_CMD_BUSY:           return "CMD Busy";
    case CRC_DAQ_BUSY:           return "DAQ Busy";
    case CRC_DAQ_OVERLOAD:       return "DAQ Overload";
    case CRC_KEY_REQUEST:        return "Key Request";
    case CRC_COLD_START_REQUEST: return "Cold Start Request";
    case CRC_TIMEOUT:            return "Internal Timeout";
    case CRC_CMD_UNKNOWN:        return "Unknown Command";
    case CRC_CMD_SYNTAX:         return "Command Syntax";
    case CRC_CMD_RANGE:          return "Parameter out of Range";
    case CRC_NO_ACCESS:          return "No Access";
    case CRC_RESOURCE_NAV:       return "Resource not available";
  }
  return "Unknown CCP Errorcode";
}

static char *ccpCommandStr( int cmd ) {

  switch (cmd) {
    case CC_CONNECT           : return "CONNECT";
    case CC_TEST              : return "TEST";
    case CC_DISCONNECT        : return "DISCONNECT";
    case CC_EXCHANGE_ID       : return "EXCHANGE_ID";
    case CC_SET_MTA           : return "SET_MTA";
    case CC_DNLOAD            : return "DNLOAD";
    case CC_DNLOAD6           : return "DNLOAD6";
    case CC_UPLOAD            : return "UPLOAD";
    case CC_SHORT_UPLOAD      : return "SHORT_UPLOAD";
    case CC_GET_DAQ_SIZE      : return "GET_DAQ_SIZE";
    case CC_SET_DAQ_PTR       : return "SET_DAQ_PTR";
    case CC_WRITE_DAQ         : return "WRITE_DAQ";
    case CC_START_STOP        : return "START_STOP";
    case CC_START_STOP_ALL    : return "START_STOP_ALL";
    case CC_SET_CAL_PAGE      : return "SELECT_CAL_PAGE";
    case CC_GET_SEED          : return "GET_SEED";
    case CC_UNLOCK            : return "UNLOCK";
    case CC_SET_S_STATUS      : return "SET_S_STATUS";
    case CC_GET_S_STATUS      : return "GET_S_STATUS";
    case CC_BUILD_CHKSUM      : return "BUILD_CHECKSUM";
    case CC_CLEAR_MEMORY      : return "CLEAR_MEMEORY";
    case CC_MOVE_MEMORY       : return "MOVE_MEMORY";
    case CC_PROGRAM           : return "PROGRAM";
    case CC_PROGRAM6          : return "PROGRAM6";
    case CC_GET_CCP_VERSION   : return "GET_CCP_VERSION";
    case CC_GET_CAL_PAGE      : return "GET_ACTIVE_CAL_PAGE";
    case CC_ACTION_SERVICE	   : return "ACTION_SERVICE";
	 case CC_DIAG_SERVICE	   : return "DIAG_SERVICE";
	 case CC_PROGRAM_PREPARE   : return	"PROGRAM_PREPARE";
	 case CC_PROGRAM_START	   : return "PROGRAM_START";
  }
  return "Unknown CCP Command";
}

//------------------------------------------------------------------------------

struct stat {
  unsigned int count;
  unsigned int tRespMin;
  unsigned int tRespMax;
  unsigned int tRespAvr;
};

struct stat gStat[0x30];

void initStat( void ) {
  int i;
  for (i=0;i<0x30;i++) {
    gStat[i].count = 0;
    gStat[i].tRespMin = 0;
    gStat[i].tRespMax = 0;
    gStat[i].tRespAvr = 0;
  }
}

void setStat( int i, unsigned int t ) {
  gStat[i].count++;
  gStat[i].tRespAvr += t;
  if (gStat[i].count==1) {
    gStat[i].tRespMin = t;
    gStat[i].tRespMax = t;
  } else {
    if (gStat[i].tRespMin > t) gStat[i].tRespMin = t;
    if (gStat[i].tRespMax < t) gStat[i].tRespMax = t;
  }
}

static void printStat1( int i ) {
  if (gStat[i].count) {
    printf(" %-20s: %-8u [%u0us,%u0us,%u0us]\n",
      ccpCommandStr(i),
      gStat[i].count,
      gStat[i].tRespMin,
      gStat[i].tRespAvr/gStat[i].count,
      gStat[i].tRespMax);
  }
}

void printStat( void ) {
  printf("\nStatistics:\n");
  printf(" Total Messages=%u, DTOs=%u, CROs=%u\n",gMsgCount,gDtoCount,gCroCount);
  printf("\nResponce Timing Statistic:\n");
  printStat1(CC_CONNECT);
  printStat1(CC_TEST);
  printStat1(CC_EXCHANGE_ID);
  printStat1(CC_BUILD_CHKSUM);
  printStat1(CC_DNLOAD);
  printStat1(CC_DNLOAD6);
  printStat1(CC_UPLOAD);
  printStat1(CC_SHORT_UPLOAD);
  printStat1(CC_START_STOP);
  printStat1(CC_START_STOP_ALL);
  printStat1(CC_PROGRAM);
  printStat1(CC_PROGRAM6);
  printStat1(CC_SET_CAL_PAGE);
  printStat1(CC_GET_CAL_PAGE);
  printf("\n");
}


/*--------------------------------------------------------------------------*/
/* Command processor */
/*--------------------------------------------------------------------------*/

void ccpPrintCommand( unsigned int time, BYTE *com ) {

  #define cmd com[0]
  #define ctr com[1]

  printf("%8gs: ",(double)time/100000.0);

  switch (cmd) {

      case CC_TEST:
        {
          #define stationId *(WORD*)&com[2]
          printf("TEST station-id = %04Xh (%u)\n",stationId,stationId);
          if (gCCPVersion<201) {
            printf("Autodetect: CCP version = 201\n");
            gCCPVersion = 201;
          }
        }
        break;

      case CC_ACTION_SERVICE:
        {
          #define Actionservicenumber  *(WORD*)&com[2]

         printf("ACTION_SERVICE: %02X %02X %02X %02X %02X %02X %02X %02X\n",com[0],com[1],com[2],com[3],com[4],com[5],com[6],com[7]);
        }
        break;
 	   case CC_DIAG_SERVICE:
        {
         #define Diagservicenumber  *(WORD*)&com[2]

         printf("DIAG_SERVICE: %02X %02X %02X %02X %02X %02X %02X %02X\n",com[0],com[1],com[2],com[3],com[4],com[5],com[6],com[7]);
        }
        break;
	   case CC_PROGRAM_PREPARE:
        {
          printf("PROGRAM_PREPARE: %02X %02X %02X %02X %02X %02X %02X %02X\n",com[0],com[1],com[2],com[3],com[4],com[5],com[6],com[7]);
        }
        break;
	   case CC_PROGRAM_START:
        {
          printf("PROGRAM_START: %02X %02X %02X %02X %02X %02X %02X %02X\n",com[0],com[1],com[2],com[3],com[4],com[5],com[6],com[7]);
        }
        break;
      case CC_CONNECT:
        {
          #define stationId *(WORD*)&com[2]
          printf("CONNECT station-id = %04Xh (%u)\n",stationId,stationId);
        }
        break;

      case CC_DISCONNECT:
        {
          #define dcCmd com[2]
          printf("DISCONNECT cmd=%u\n",dcCmd);
        }
        break;

      case CC_EXCHANGE_ID:
        {
          #define masterId com[2]
          printf("EXCANGE_ID master_id=%u\n",masterId);
        }
        break;

      case CC_GET_CCP_VERSION:
        {
          #define mainVersion com[2]
          #define subVersion  com[3]
          printf("GET_CCP_VERSION version=V%u.%u\n",mainVersion,subVersion);
        }
        break;

      case CC_GET_SEED: /* Get Seed for Key */
        {
          printf("GET_SEED resource=%02X\n",com[2]);
        }
        break;

      case CC_UNLOCK: /* Unlock Protection */
        {
          printf("UNLOCK key=%02X%02X%02X%02X%02X%02X\n",com[2],com[3],com[4],com[5],com[6],com[7]);
        }
        break;

      case CC_SET_MTA: /* Set transfer address */
        {
          #define mta     com[2]
          #define addrExt com[3]
          #define addr    (*(DWORD*)&com[4])
          SWAP_MOTOROLA(&addr,4);
          printf("SET_MTA %u to %u:%08lXh\n",mta,addrExt,addr);
        }
        break;

      case CC_DNLOAD: /* Download */
        {
          #define size com[2]
          printf("DNLOAD n=%u\n",size);
        }
        break;

      case CC_DNLOAD6: /* Download */
        {
          printf("DNLOAD6\n");
        }
        break;

      case CC_UPLOAD: /* Upload */
        {
          #define size com[2]
          printf("UPLOAD n=%u\n",size);
        }
        break;

      case CC_SHORT_UPLOAD: /* Upload (Shortcut) */
        {
          #define size    com[2]
          #define addrExt com[3]
          SWAP_MOTOROLA(&addr,4);
          printf("SHORT_UPLOAD p=%08lX,%u,n=%u\n",addr,addrExt,size);
        }
        break;

      case CC_GET_DAQ_SIZE: /* Return the size of a DAQ list and clear */
        {
          #define daqList com[2]
          #define daqId   (*(DWORD*)&com[4])
          SWAP_MOTOROLA(&daqId,4);
          printf("GET_DAQ_SIZE daq=%u, id=%04Xh\n",daqList,daqId);
        }
        break;

      case CC_SET_DAQ_PTR: /* Set DAQ pointer */
        {
          #define daq  com[2]
          #define odt  com[3]
          #define idx  com[4]
          printf("SET_DAQ_PTR daq=%u,odt=%u,idx=%u\n",daq,odt,idx);
        }
        break;

      case CC_WRITE_DAQ: /* Write DAQ entry */
        {
          #define size    com[2]
          #define addrExt com[3]
          #define addr    (*(DWORD*)&com[4])
          SWAP_MOTOROLA(&addr,4);
          printf("WRITE_DAQ size=%u,addr=%u:%08Xh\n",size,addrExt,addr);
        }
        break;

      case CC_START_STOP: /* Cyclic aquisition start/stop */
        {
          #define ssCmd       com[2]    /* Start or Stop */
          #define ssDaq       com[3]    /* DAQ list */
          #define ssLast      com[4]    /* Last ODT to send */
          #define ssRate      com[5]    /* Rate in ms, 0xFF=EVENT */
          #define ssEvent     com[5]    /* Event channel */
          #define ssPrescaler (*(WORD*)&com[6]) /* Prescaler */
          if (gCCPVersion>200 || ssCmd>1) {
            SWAP_MOTOROLA(&ssPrescaler,2);
            printf("START_STOP cmd=%u,daq=%u,last=%u,event=%u,prescaler=%u\n",ssCmd,ssDaq,ssLast,ssEvent,ssPrescaler);
          } else {
            printf("START_STOP cmd=%u,daq=%u,last=%u,rate=%u\n",ssCmd,ssDaq,ssLast,ssRate);
          }
        }
        break;

      case CC_START_STOP_ALL: /* Cyclic aquisition start/stop */
        {
          printf("START_STOP_ALL cmd=%u\n",ssCmd);
          if (gCCPVersion<201) {
            printf("Autodetect: CCP version = 201\n");
            gCCPVersion = 201;
          }
        }
        break;

      case CC_CLEAR_MEMORY: /* Clear Memory */
        {
          #define memSize (*(DWORD*)&com[2])
          SWAP_MOTOROLA(&memSize,4);
          printf("CLEAR_MEMORY size=%u\n",memSize);
        }
        break;

      case CC_PROGRAM: /* Program */
        {
          #define size com[2]
          printf("PROGRAM: ");
          if (size==0) {
            printf("EOS\n");
          } else {
            int i;
            for (i=0;i<size;i++) printf("%02X ",com[3+i]);
            printf("\n");
          }
        }
        break;

      case CC_PROGRAM6: /* Program */
        {
              int i;
              printf("PROGRAM6: ");
              for (i=0;i<6;i++) printf("%02X ",com[2+i]);
              printf("\n");
        }
        break;

      case CC_SET_CAL_PAGE: /* Select Calibration Page */
        {
          printf("SEL_CAL_PAGE\n");
        }
        break;

      case CC_GET_CAL_PAGE: /* Get Calibration Page */
        {
          printf("GET_ACTIVE_CAL_PAGE\n");
        }
        break;

      case CC_SET_S_STATUS: /* Set Session Status */
        {
          printf("SET_S_STATUS %02X\n",com[2]);
        }
        break;

      case CC_GET_S_STATUS: /* Get Session Status */
        {
          printf("GET_S_STATUS\n");
        }
        break;

      case CC_BUILD_CHKSUM: /* Build Checksum */
        {
          #define memSize (*(DWORD*)&com[2])
          //#define checkSum (*(DWORD*)&ccp.Crm[4])
          SWAP_MOTOROLA(&memSize,4);
          printf("BUILD_CHKSUM size = %04Xh (%u)\n",memSize,memSize);
        }
        break;

      case CC_MOVE_MEMORY: /* Move Memory */
        {
          SWAP_MOTOROLA(&memSize,4);
          printf("MOVE_MEMORY size = %04Xh (%u)\n",memSize);
        }
        break;

      default: /* unknown */
        {
          printf("*** UNKNOWN COMMAND ***\n");
          break;
        }
    }



}

void ccpPrintEvent( BYTE *com ) {

  int i;

  if (com[0]!=0xFE) return;

  for (i=1;i<8;i++) {
    if (com[i]==0) {
      printf("\n");
      return;
    } else {
      printf("%c, ",com[i]);
    }
  }
}

void ccpPrintResponce( unsigned int time, BYTE *com ) {


  if (com[0]!=0xFF) return;

  printf("+%7gms: ",time/100.0);

  if (com[1]) {
    printf("ERROR: '%s' !!! ",ccpErrorStr(com[1]));
  }

  switch (gLastCmd) {

    case CC_BUILD_CHKSUM:
      {
        #define csum *(DWORD*)&com[4]
        SWAP_MOTOROLA(&csum,4)        ;
        printf("size = %02Xh, sum = %08Xh\n",com[3],csum);
      }
      break;

    case CC_EXCHANGE_ID:
      {
        printf("len = %u, resource availability mask=%02Xh, resource protection mask=%02Xh\n",com[3],com[5],com[6]);
      }
      break;

    case  CC_GET_CCP_VERSION:
      {
        printf("version = V%u.%u\n",com[3],com[4]);
        gCCPVersion = com[3]*100+com[4];
      }
      break;

    case CC_SHORT_UPLOAD:
    case CC_UPLOAD:
      {
        printf("data = {%02Xh,%02Xh,%02Xh,%02Xh,%02Xh}\n",com[3],com[4],com[5],com[6],com[7]);
      }
      break;

    case CC_GET_DAQ_SIZE:
      {
        if (com[3]) {
          printf("size = %u, firstPid = %u\n",com[3],com[4]);
        } else {
          printf("size = 0\n");
        }
      }
      break;

    case CC_GET_CAL_PAGE:
      {
        #define calpage *(DWORD*)&com[4]
        SWAP_MOTOROLA(&calpage,4);
        printf("addr = %u:%08Xh\n",com[3],calpage);
      }
      break;

    case CC_GET_S_STATUS:
      {
        printf("status = %02Xh, %02Xh, %02Xh\n",com[3],com[4],com[5]);
      }
      break;

    case CC_GET_SEED:
      {
        printf("protection status=%u, seed = %02X%02X%02X%02X\n",com[3],com[4],com[5],com[6],com[7]);
      }
      break;

    case CC_UNLOCK:
      {
        printf("current resource protection mask=%02X\n",com[3]);
      }
      break;

    default:
      {
        printf("%02X %02X %02X %02X %02X %02X %02X %02X \n",com[0],com[1],com[2],com[3],com[4],com[5],com[6],com[7]);
      }
      break;


   }
}

///////////////////////////////////////////////////////////////////////
// InitDriver ()
//---------------------------------------------------------------------
// Initializes the CAN driver interface

static Vstatus InitDriver(void)
{
  Vstatus vErr;
  VsetAcceptance acc;

  // Open the driver
  vErr = ncdOpenDriver ();
  if (vErr) goto error;

  // Get channel configuration of CCPlog
  vErr = ncdGetApplConfig("CCPlog",0,&gHwType,&gHwIndex,&gHwChannel);
  if (vErr) {
    vErr=ncdSetApplConfig("CCPlog",0,gHwType,gHwIndex,gHwChannel);
    if (vErr) {
      printf("ERROR: Registration failed\n");
      goto error;
    }
  }

  // Select the channel
  gChannelMask = ncdGetChannelMask(gHwType,gHwIndex,gHwChannel);
  if (gChannelMask==0) {
    printf("ERROR: No hardware channel assigned to CCPlog\n");
    goto error;
  }

  // Open a port
  vErr = ncdOpenPort(&gPortHandle,"CCPlog",gChannelMask,gBitRate>0?gChannelMask:0,&gPermissionMask,1024);
  if (vErr) goto error;

  // If permission to initialize
  if (gPermissionMask) {

    // Set the bus timing
    vErr = ncdSetChannelBitrate(gPortHandle,gPermissionMask,gBitRate);
    if (vErr) goto error;

    // Reset the clock
    vErr = ncdResetClock(gPortHandle);
    if (vErr) goto error;
  }

  // Open the acceptance filter for all standard ids
  acc.mask = 0; // relevant=1
  acc.code = 0;
  vErr = ncdSetChannelAcceptance(gPortHandle,gChannelMask,&acc);

  if(gExtendedid == 1)  {
    // Open the acceptance filter for all extended ids (Gurvir Parmar 11/11/2002)
    acc.mask = 0x80000000;
    acc.code = 0x80000000;
    vErr = ncdSetChannelAcceptance(gPortHandle, gChannelMask, &acc);
  }

  if (vErr) goto error;

  return VSUCCESS;


error:

  printf("ERROR: %s\n",ncdGetErrorString(vErr));

  if (gPortHandle!=INVALID_PORTHANDLE) {
    ncdClosePort(gPortHandle);
    gPortHandle = INVALID_PORTHANDLE;
  }

  return vErr;
}                                                  // end InitDriver ()



///////////////////////////////////////////////////////////////////////
// CleanUp()
//---------------------------------------------------------------------
// close the port and the CAN driver

static Vstatus CleanUp(void)
{
  ncdClosePort(gPortHandle);
  gPortHandle = INVALID_PORTHANDLE;
  ncdCloseDriver();
  return VSUCCESS; // No error handling
}                                                    // ..end CleanUp()


///////////////////////////////////////////////////////////////////////
// main()
//---------------------------------------------------------------------
//

// help
static void usage( void ) {

  printf(
    "\nUsage:\n"
    "  CCPlog [options]\n"
    "\n"
    "  Options:\n"
    "    -tx    Set output verbosity to x\n"
    "            1 - Print commands\n"
    "            2 - Print commands and responses\n"
    "            3 - Print commands, responses and all other can messages\n\n"
    "    -bx    Set bitrate to x (Default is not initialized)\n"
    "    -crox  Set CRO id to x (decimal)\n"
    "    -dtox  Set DTO id to x (decimal)\n"
    "    -verx  Set version number to x (default is 200)\n"
    "    -m     Set byte order to Motorola\n\n"
    "    -e     Set the acceptance filter for extended id's\n"
    "  Keys:\n"
    "    0-3    Set output verbosity to x\n"
    "    m      Set byte order to Motorola\n"
    "    s      Print Statistics\n"
    );


}

int main( int argc, char *argv[])
{
  Vstatus       vErr;
  Vevent        *pEvent =0, event;
  int           end = 0, i;
  HANDLE        h = 0;
  unsigned long b;

  printf(
    "CCPlog - The CCP Logging Utility\n"
    "Vector Informatik GmbH, 1997-2002\n\n"
    "Build " __DATE__ " " __TIME__ "  Ver: %2.2f\n"  ,(float)CCP_LOGVERSION/100
  );

  // commandline
  for (i=1; i<argc; i++) {
      char c;
      if (strcmp(argv[i], "-h") == 0) {
          usage();
		  return 0;
      } else if (strcmp(argv[i], "-m") == 0) {
          gMotorola = 1;
      } else if (strcmp(argv[i], "-l") == 0) {
          gLogging = 1;
      } else if (strcmp(argv[i], "-o") == 0) {
          gOffline = 1;
      } else if (strcmp(argv[i], "-e") == 0) {
          gExtendedid = 1;
      } else if (sscanf(argv[i], "-b%u", &b) == 1) {
          gBitRate = b;
      } else if (sscanf(argv[i], "-cro%u", &b) == 1) {
          gCroId = b;
      } else if (sscanf(argv[i], "-dto%u", &b) == 1) {
          gDtoId = b;
      } else if (sscanf(argv[i], "-ver%u", &b) == 1) {
          gCCPVersion = b;
      } else if (sscanf(argv[i], "-t%c", &c) == 1) {
          gDebugLevel = c-'0';
          printf("Output verbosity level = %u\n",gDebugLevel);
      } else {
          usage();
		  return 0;
      }
  }

  printf("\n");
  if (gBitRate) printf("Bitrate = %u bps\n",gBitRate);
  if (gCroId) printf("CRO Id  = %u (%04Xh)\n",gCroId,gCroId);
  if (gDtoId) printf("DTO Id  = %u (%04Xh)\n",gDtoId,gDtoId);
  if (gLogging) printf("LOG file = CCPLOG.LOG\n");
  if (gOffline) printf("Offline Mode\n");
  if (gExtendedid) printf("Extended ID Mode\n");

  // Create the log file
  if (gLogging || gOffline) {
    if (gLogging) gLogFile = fopen("CCPLOG.LOG","wb");
    if (gOffline) gLogFile = fopen("CCPLOG.LOG","rb");
    if (gLogFile==0) {
      printf("ERROR: Could not open file CCPLOG.LOG!\n");
      goto error;
    }
  }

  if (!gOffline) {

    // initialize the CAN driver
    vErr = InitDriver();
    if (vErr) goto error;

    // create a synchronisation object
    h = CreateEvent(NULL, FALSE, FALSE, NULL);
    vErr = ncdSetNotification(gPortHandle, &h, 1);
    if (vErr) goto ncdError;

    // channel on bus
    vErr = ncdActivateChannel(gPortHandle,gChannelMask);
    if (vErr) goto ncdError;
  }

  // main loop
  initStat();
  while (!end) {

    // wait for receive event
    if (h) WaitForSingleObject(h,100);

    // receive
    for (;;) { // read all events

      if (gOffline) {
        if (0==fread(&event,1,sizeof(Vevent),gLogFile)) {
          end = 1;
          break;
        }
        pEvent = &event;
      }

      else {
        vErr = ncdReceive1(gPortHandle,&pEvent);
        if (vErr&&vErr!=VERR_QUEUE_IS_EMPTY) goto ncdError;
        if (vErr==VERR_QUEUE_IS_EMPTY) break;
      }

      // screen output
      if (gDebugLevel>=3 && pEvent->tag != V_TIMER) {
        printf("%s\n",ncdGetEventString(pEvent));
      }

      // check for the ccp cro or dto message
      if (pEvent->tag==V_RECEIVE_MSG) {

        gMsgCount++;

        // Logging
        if (gLogging) fwrite(pEvent,1,sizeof(Vevent),gLogFile);

        // Autodetect CRO and DTO identifiers
        if (gCroId==0) {
          if (pEvent->tagData.msg.data[0]==CC_CONNECT) {
            gCroId = pEvent->tagData.msg.id;
            printf("Autodetect CRO Id  = %u (%04Xh)\n",gCroId,gCroId);
          }
        }
        if (gDtoId==0 && gCroId!=0) {
          if (pEvent->tagData.msg.data[0]==0xFF) {
            gDtoId = pEvent->tagData.msg.id;
            printf("Autodetect DTO Id  = %u (%04Xh)\n",gDtoId,gDtoId);
          }
        }

        // Check for queue overruns
        if (pEvent->tagData.msg.flags&MSGFLAG_OVERRUN) {
          ncdFlushReceiveQueue(gPortHandle);
          gLastCmd = 0;
          gLastTime = 0;
          printf("Queue overflow, messages lost\n");
        }

        // CCP command
        if (pEvent->tagData.msg.id==gCroId) {
          gCroCount++;
          gLastCmd = pEvent->tagData.msg.data[0];
          gLastTime = pEvent->timeStamp;
          if (gDebugLevel>=1) ccpPrintCommand(pEvent->timeStamp,&pEvent->tagData.msg.data[0]);
        }

        // CCP responce
        else if (pEvent->tagData.msg.id==gDtoId) {
          gDtoCount++;
          if (pEvent->tagData.msg.data[0]==0xFF) {
            if (gLastCmd&&gLastTime) setStat(gLastCmd,pEvent->timeStamp-gLastTime);
            if (gDebugLevel>=2) ccpPrintResponce(pEvent->timeStamp-gLastTime,&pEvent->tagData.msg.data[0]);
            gLastCmd = 0;
            gLastTime = 0;
          }
          else if (pEvent->tagData.msg.data[0]==0xFE) {
            ccpPrintEvent(&pEvent->tagData.msg.data[0]);
          }
        }

        // Other
        else if (gDebugLevel>=3 && gLastCmd) {
          printf("%s\n",ncdGetEventString(pEvent));
        }

      } // V_RECEIVE_MSG

    } // for

    // Keyboard
    if (kbhit()) {
      int key;
      key = getch();
      switch (key) {
        case '0':
        case '1':
        case '2':
        case '3':
          gDebugLevel = key-'0';
          printf("Set output verbosity level to = %u\n",gDebugLevel);
          break;
        case 's':
        case 'S':
          printStat();
          break;
        case 'm':
        case 'M':
          gMotorola = 1;
          printf("Set byte order to Motorola\n");
          break;
        case 'h':
        case 'H':
          usage();
          break;
       case 27:
          end = 1;
          break;
        default:
          break;
      }
    }

  } // while (!end)


error:

  if (!gOffline) {
    ncdDeactivateChannel(gPortHandle, gChannelMask);
    CleanUp();
  }
  if (gLogging || gOffline) fclose(gLogFile);
  printf("Press any Key...\n");
  getch();
  return 0;

ncdError:
  printf("ERROR: %s\n",ncdGetErrorString(vErr));
  goto error;

}



