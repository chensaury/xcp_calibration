/*----------------------------------------------------------------------------
| File:
|   CCPSIM.C
|
| Project:
|   CCP Driver Example
|   CCPSIM - PC Emulation of a ECU using CCP
|
 ----------------------------------------------------------------------------*/

#define  STRICT
#include <windows.h>

#include "stdio.h"
#include "conio.h"

// CAN driver
#include "VCanD.h"

// CCP driver
#include "CCP.h"

// ECU simulation
#include "ecu.h"

///////////////////////////////////////////////////////////////////////
// Defines

#define CCP_CANAPE

#define APP_NAME "CCPsim"

#define ABSOLUT_ADRESS_CALC
#ifdef ABSOLUT_ADRESS_CALC
#include <Tlhelp32.h>
#endif


///////////////////////////////////////////////////////////////////////
// Statics

static void canMain( void );

// Datensegment-Pointer
#ifdef __BORLANDC__
  #define isDllAddr 0x58
  extern CCP_BYTE __isDLL;
  static CCP_DWORD dataSeg = (CCP_DWORD)(&__isDLL-isDllAddr);
#else
  extern CCP_BYTE __xc_a;
  static CCP_DWORD dataSeg = (CCP_DWORD)&__xc_a;
#endif

///////////////////////////////////////////////////////////////////////
// Globals

int hwType                   = HWTYPE_VIRTUAL;
int hwChannel                = 0;
int hwIndex                  = 0;

VportHandle gPortHandle      = INVALID_PORTHANDLE;
Vaccess gChannelMask         = 0;
Vaccess gPermissionMask      = 0;
VDriverConfig *gDriverConfig = 0;
unsigned int gBitRate        = 0;
BYTE gDebugLevel             = 1;

static HANDLE threadHandle   = 0;
static CCP_DWORD threadId    = 0;
static int threadRunning     = 0;

unsigned long gDtoId         = 0x000007e1;
unsigned long gCroId         = 0x00000667;
unsigned short gStationAddr  = 57;

#ifdef CCP_CANAPE
  int hwType0 = -1, hwIndex0 = -1, hwChannel0 = -1;
  int hwType1 = -1, hwIndex1 = -1, hwChannel1 = -1;

  Vstatus _EXPORT_DECL ncdSetApplConfig(char *appId, int appChannel, int hwType, int hwIndex, int hwChannel);
  Vstatus _EXPORT_DECL ncdGetApplConfig(char *appId, int appChannel, int *hwType, int *hwIndex, int *hwChannel);
#endif

#ifdef CCP_LATENCY_TEST
  unsigned int ccpLatencyTime    = 0;
#endif

int gRam = 0;



///////////////////////////////////////////////////////////////////////
// GetStartAdress(char *Name)
//---------------------------------------------------------------------
// determine programm start adress
// HMODULE hModule: Modulehandle in case of a DLL - in case of an EXE this parameter should be NULL
// char *Name: Module Name. Only used in case of determine the start adress of other Modules
//             in all other cases the Parameter should be NULL
///////////////////////////////////////////////////////////////////////
#ifndef __BORLANDC__
#ifdef ABSOLUT_ADRESS_CALC

CCP_DWORD  GetStartAdress(HMODULE hModule, char *Name){

 MODULEENTRY32  Modul       = {0}; 
 HANDLE hModuleSnap;
 DWORD StartAdrr=0;
 char Buffer[255];
 char *pBuf=Buffer;
 int len;

 if(!Name){
   GetModuleFileName(hModule,Buffer,sizeof(Buffer));
   len=strlen(Buffer);
   while((Buffer[len--]!='\\')&&(len>=0));
   pBuf+=len+2;
 }
 else{
   pBuf=Name;
 }

 Modul.dwSize=sizeof(MODULEENTRY32);

  hModuleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, GetCurrentProcessId()); 
  if (hModuleSnap == INVALID_HANDLE_VALUE) 
   return (FALSE); 

  if(Module32First(hModuleSnap,&Modul)){
    do{
      if(stricmp((pBuf),(Modul.szModule))==0){
        StartAdrr= (DWORD)Modul.modBaseAddr;
        break;
      }
    }while(Module32Next(hModuleSnap, &Modul));
  }
  CloseHandle(hModuleSnap);
  return StartAdrr;
}

#endif
#endif



///////////////////////////////////////////////////////////////////////
// InitDriver ()
//---------------------------------------------------------------------
// initializes the CAN driver

static Vstatus InitDriver( int hwType, int hwIndex, int hwChannel )
{
  Vstatus vErr;
  VsetAcceptance acc;
  char name[16];

  // Open the driver
  vErr = ncdOpenDriver ();
  if (vErr) goto error;

  // Select a channel
  gChannelMask = ncdGetChannelMask(hwType,hwIndex,hwChannel);
  if (gChannelMask==0) return VERR_HW_NOT_PRESENT;

  // If a virtual channel is used,
  // make sure CANape channel 0 is configured to virtual channels
  #ifdef CCP_CANAPE
    if (hwType==HWTYPE_VIRTUAL) {
      ncdGetApplConfig("CANape",0,&hwType0,&hwIndex0,&hwChannel0);
      ncdGetApplConfig("CANape",1,&hwType1,&hwIndex1,&hwChannel1);
      if (hwType0!=HWTYPE_VIRTUAL) {
        ncdSetApplConfig("CANape",0,HWTYPE_VIRTUAL,0,0);
        ncdSetApplConfig("CANape",1,HWTYPE_VIRTUAL,0,1);
        printf("CANape has been reconfigured to use virtual channels !\n");
      }
    }
  #endif

  // Open a port
  gPermissionMask = (gBitRate>0) ? gChannelMask : 0; // If no bitrate specified, don't init
  sprintf(name,"CCPsim-%u",CCP_STATION_ADDR);
  vErr = ncdOpenPort(&gPortHandle,name,gChannelMask, gPermissionMask, &gPermissionMask, 1024);
  if (vErr) goto error;

  // If permission to initialize
  if (gPermissionMask) {

    // Initialize the channels
    vErr = ncdSetChannelBitrate(gPortHandle,gPermissionMask,gBitRate);
    if (vErr) goto error;

    // Reset the clock
    vErr = ncdResetClock(gPortHandle);
    if (vErr) goto error;
  }

  // Enable TX and TXRQ notifications
  vErr = ncdSetChannelMode(gPortHandle,gChannelMask,1,1);
  if (vErr) goto error;

  // Set the acceptance filter
  acc.code = CCP_CRO_ID;
  acc.mask = (acc.code&0x80000000UL) ? 0x9FFFFFFFUL : 0x7FF; // relevant=1
  vErr = ncdSetChannelAcceptance(gPortHandle,gChannelMask,&acc);
  if (vErr) goto error;

  return VSUCCESS;

error:
  printf("ERROR: %s",ncdGetErrorString(vErr));

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

  #ifdef CCP_CANAPE
    if (hwType0!=-1&&hwType0!=HWTYPE_VIRTUAL) {
      ncdSetApplConfig("CANape",0,hwType0,hwIndex0,hwChannel0);
      ncdSetApplConfig("CANape",1,hwType1,hwIndex1,hwChannel1);
    }
  #endif

  ncdCloseDriver();
  return VSUCCESS; // No error handling
}                                                    // ..end CleanUp()


///////////////////////////////////////////////////////////////////////
// ccpSend()
//---------------------------------------------------------------------
// Callback for ccp.c to send the CRM message


CCP_BYTE canSendId( CCP_DWORD id, CCP_BYTE len, CCP_BYTEPTR msg ) {

  Vstatus vErr;
  Vevent event;

  event.tag                 = V_TRANSMIT_MSG;
  event.tagData.msg.id      = id;
  event.tagData.msg.flags   = 0;
  event.tagData.msg.dlc     = len;
  memcpy(&event.tagData.msg.data[0],msg,8);
  vErr =  ncdTransmit(gPortHandle, gChannelMask, &event);
  if (vErr) {
    printf("ERROR: %s\n",ncdGetErrorString(vErr));
    return 0;
  }

  return 1;
}


CCP_BYTE ccpSendId( CCP_DWORD id, CCP_BYTE len, CCP_BYTEPTR msg ) {

  canSendId( id, len, msg );

  if (gDebugLevel>=3 || (gDebugLevel==2 && msg[0]==0xff)) {
    int i;
    printf("TX: ");
    for (i=0;i<len;i++) printf(" %02X",msg[i]);
    printf("\n");
  }

  return 1;
}


void ccpSend(CCP_BYTEPTR msg ) {

  ccpSendId(gDtoId,8,msg);
}



/**************************************************************************/
// CCPsim generic RAM/FLASH Emulation
/**************************************************************************/

unsigned char *ram[0x10000];
unsigned int ramSectorCount;

void ramInit(void) {

  #ifdef CCP_TESTMODE
    if (gDebugLevel) {
      printf("Ram initialized\n");
    }
  #endif

  memset(ram,0,sizeof(ram));
  ramSectorCount = 0;
}

unsigned char *ramGetPointer( unsigned long a ) {

  unsigned int h = a >> 16;
  unsigned int l = a & 0xFFFF;

  if (ram[h]==0) {
    ram[h] = malloc(0x10000+16);
    if (ram[h]==0) {
        printf("Out of memory\n");
        return 0;
    }
    memset(ram[h],0,0x10000);
    ramSectorCount++;
    #ifdef CCP_TESTMODE
      if (gDebugLevel) {
        printf("Ram Sector %u at %08X created\n",ramSectorCount,a&0xFFFF0000);
      }
    #endif
  }
  return ram[h]+l;
}

unsigned long ramGetAddress( unsigned char *p ) {

  unsigned int i;
  for (i=0;i<0x10000;i++) {
    if (ram[i] && ram[i]<=p && p<=ram[i]+0xFFFF) return (i<<16) + (p-ram[i]);
  }
  return 0xFFFFFFFF;
}


unsigned char *flash[0x10000];

void flashInit(void) {

  #ifdef CCP_TESTMODE
    if (gDebugLevel) {
      printf("Flash initialized\n");
    }
  #endif

  memset(flash,0,sizeof(flash));
}

unsigned char *flashGetPointer( unsigned long a ) {

  unsigned int h = a >> 16;
  unsigned int l = a & 0xFFFF;

  if (flash[h]==0) {
    flash[h] = malloc(0x10000);
    memset(flash[h],0xFF,0x10000);
    #ifdef CCP_TESTMODE
      if (gDebugLevel) {
        printf("Flash Sector at %08X created\n",a&0xFFFF0000);
      }
    #endif
  }
  return flash[h]+l;
}

unsigned long flashGetAddress( unsigned char *p ) {

  unsigned int i;
  for (i=0;i<0x10000;i++) {
    if (flash[i] && flash[i]<=p && p<=flash[i]+0xFFFF) return (i<<16) + (p-flash[i]);
  }
  return 0xFFFFFFFF;
}

void flashClear( unsigned char *p, unsigned int size ) {

  unsigned long a = flashGetAddress(p);

  #ifdef CCP_TESTMODE
    if (gDebugLevel) {
      printf("Erasing sector at %08X,%u\n",a,size);
    }
  #endif

  memset(flashGetPointer(a&0xFFFF0000),0xFF,0x10000);
}

void flashProgramm( unsigned char * data, unsigned char *a, unsigned int size ) {

  while (size--) {
    *(a++) = *(data++);
  }

}

void flashRead(void) {

  FILE *f = fopen("FLASH.DAT","rb");
  unsigned int i;

  if (f) {

    #ifdef CCP_TESTMODE
      if (gDebugLevel) {
        printf("Loading Flash from FLASH.DAT\n");
      }
    #endif

    for (i=0;i<0x10000;i++) {
      unsigned char * tmp;
      fread(&tmp,sizeof(unsigned char*),1,f);
      if (tmp) {
        fread(flashGetPointer(i<<16),0x10000,1,f);
      }
    }
    fclose(f);
  }
}

void flashWrite( void ) {

  FILE *f = fopen("FLASH.DAT","wb");
  unsigned int i;
  if (f) {

    #ifdef CCP_TESTMODE
      if (gDebugLevel) {
        printf("Saving Flash to FLASH.DAT\n");
      }
    #endif

    for (i=0;i<0x10000;i++) {
      fwrite(&flash[i],sizeof(unsigned char*),1,f);
      if (flash[i]) fwrite(flash[i],0x10000,1,f);
    }
    fclose(f);
  }
}

void flashCopy( void ) {

  unsigned int i;

  #ifdef CCP_TESTMODE
    if (gDebugLevel) {
      printf("Copy Flash to Ram\n");
    }
  #endif

  for (i=0;i<0x10000;i++) {
    if (ram[i]) {
      free(ram[i]);
      ram[i] = 0;
    }
  }
  for (i=0;i<0x10000;i++) {
    if (flash[i]) {
      memcpy(ramGetPointer(i<<16),flash[i],0x10000);
    }
  }
}






/**************************************************************************/
// CCPsim FLASH Emulation
/**************************************************************************/

#if defined(CCP_PROGRAM)

#define FLASH        ccpFlash
#define FLASH_SIZE   1024*256
#define FLASH_START  &ccpFlash[0]
#define FLASH_LAST   &ccpFlash[FLASH_SIZE-1]

CCP_BYTE ccpFlash[FLASH_SIZE] = {0};



/**************************************************************************/
// CCPsim Set/GetCalPage
/**************************************************************************/

// ==0 - Ram
// !=0 - Flash
CCP_DWORD ccpCalPage = 0;

CCP_DWORD ccpGetCalPage( void ) {

  return ccpCalPage;
}

void ccpSetCalPage( CCP_DWORD a ) {

  if (gRam) {
    if (ccpCalPage) { // Trick: Backtransform MTA
      ccpCalPage = flashGetAddress((unsigned char*)a);
    } else {
      ccpCalPage = ramGetAddress((unsigned char*)a);
    }
  } else {
    ccpCalPage = a;
  }

  #ifdef CCP_TESTMODE
    if (gDebugLevel) {
      printf("Set Calibration Page to %s\n",(ccpCalPage)?"FLASH":"RAM");
    }
  #endif
}



void ccpWriteFlash( void ) {
  FILE *f = fopen("CCPSIM.DAT","wb");
  if (f) {
    fwrite(ccpFlash,FLASH_SIZE,1,f);
    fclose(f);
  }
}

int ccpReadFlash( void ) {
  FILE *f = fopen("CCPSIM.DAT","rb");
  int n;
  if (f) {
    n = fread(ccpFlash,FLASH_SIZE,1,f);
    fclose(f);
    return n;
  }
  return 0;
}

static void ccpInitFlash( void ) {
  int i;
  if (ccpReadFlash() && *(CCP_DWORD*)&ccpFlash[CALRAM_SIZE-4]==0x0055AAFF) {
    for (i=0;i<CALRAM_SIZE;i++) CALRAM[i] = ccpFlash[i];
    #ifdef CCP_TESTMODE
      if (gDebugLevel) {
        printf("\nInitialized calibration RAM from FLASH\n\n");
      }
    #endif
  } else {
    for (i=0;i<CALRAM_SIZE;i++) ccpFlash[i] = CALRAM[i];
    ccpWriteFlash();
  }
}



/**************************************************************************/
// ccpFlashClear() -------------------------------------------------------------
//

void ccpFlashClear( CCP_BYTEPTR a, CCP_DWORD size ) {

  if (gRam) {

    flashClear(a,size);

  } else {

    int i;
    for (i=0;i<CALRAM_SIZE;i++) ccpFlash[i] = 0xff;

  }
}



/**************************************************************************/
// ccpFlashProgramm() ----------------------------------------------------------

CCP_BYTE ccpFlashProgramm( CCP_BYTEPTR data, CCP_BYTEPTR a, CCP_BYTE size ) {

  if (gRam) {
  
    if (size==0) {
      // Simulate Reset
      flashCopy();
      flashWrite();
      ccp.SessionStatus &= ~SS_CONNECTED; /* DISCONNECT */
    } else {
      flashProgramm(data, a, size);
    }  
    return CCP_WRITE_OK;

  } else {

    int i;

    if (size==0) {                                
      for (i=0;i<CALRAM_SIZE;i++) CALRAM[i] = ccpFlash[i];
      ccpWriteFlash();
      ccp.SessionStatus &= ~SS_CONNECTED; /* DISCONNECT */
    } else {
      for (i=0;i<size;i++) {
        CCP_BYTEPTR f = (ccpCalPage==0) ? ccpFlash + (a-CALRAM) : a;
        if (f>=ccpFlash&&f<ccpFlash+FLASH_SIZE) {
          f[i] = data[i];
        } else {
          printf("WARNING: illegal memory access, address=0x%08X\n",f);
        }
      }
    }
    return CCP_WRITE_OK;
  }
}

#endif





/**************************************************************************/
// ccpCheckWriteAccess()
//
// goal in that exmple:
// -> protect FLASH addresses
// -> protect struct ccp
//
// Call:
// - ccpCommand(), CC_DNLOAD, CC_DNLOAD6
// - check protection state
// - ccpWriteMTA()

#if defined(CCP_WRITE_PROTECTION)
CCP_BYTE ccpCheckWriteAccess( CCP_BYTEPTR a, CCP_BYTE size ) {

  if (gRam) return CCP_WRITE_OK;

  // Protect FLASH
  #ifdef CCP_PROGRAM
    if (a>=FLASH_START && a<=FLASH_LAST) {
      printf("WARNING: illegal FLASH write access, address=0x%08X, size=%u\n",a,size);
      return CCP_WRITE_DENIED;
    }
  #endif

  // Protect CCP
  if ((a>(CCP_BYTEPTR)&ccp) && (a<((CCP_BYTEPTR)&ccp)+sizeof(struct ccp))) {
    printf("WARNING: illegal write access to CCP area, address=0x%08X, size=%u\n",a,size);
    return CCP_WRITE_DENIED;
  }

  return CCP_WRITE_OK;
}
#endif



/**************************************************************************/
// ccpGetPointer() -------------------------------------------------------------
//
// Convert a CCP CCP_BYTE,CCP_DWORD address to a C pointer

CCP_BYTEPTR ccpGetPointer( CCP_BYTE addr_ext, CCP_DWORD addr ) {

  if (gRam) {

    if (ccpCalPage) {
      return flashGetPointer( addr );
    } else {
      return ramGetPointer( addr );
    }

  } else {

    CCP_BYTEPTR a = (CCP_BYTEPTR)(addr+dataSeg);
    if (addr<2) return (CCP_BYTEPTR)addr;

    #if defined(CCP_CALPAGE)
    if (a>=(CCP_BYTE*)&CALRAM_START && a<=(CCP_BYTE*)&CALRAM_LAST) { // Address within Calibration RAM
      if (ccpCalPage==0) { // RAM
        return (CCP_BYTEPTR)a;
      } else {             // FLASH
        return (CCP_BYTEPTR)(ccpFlash+(a-(CCP_BYTE*)&CALRAM_START));
      }
    } else
    #endif
    {
      return (CCP_BYTEPTR)a;
    }

  }
}

#ifdef CCP_STANDARD
void ccpGetMTA0( CCP_BYTE *addr_ext, CCP_DWORD *addr ) {

  if (gRam) {
    *addr_ext = 0;
    *addr = 0;
  } else {
    *addr_ext = 0;
    *addr = (CCP_DWORD)(ccp.MTA[0]-dataSeg);
  }
}
#endif



/**************************************************************************/
void ccpUserBackground( void ) {
}



/**************************************************************************/
CCP_BYTE ccpDisableNormalOperation( CCP_MTABYTEPTR a, CCP_WORD s )
{
  return 1;
}



/**************************************************************************/
#if defined(CCP_SEED_KEY)

// ccpGetSeed() ----------------------------------------------------------------
//
// Parameter:      PL_CAL, PL_PGM, PL_DAQ
// Return:         32 bit value with seed
//

// ccpUnlock() -----------------------------------------------------------------
//
// Parameter:      Key mit 0-6 Byte
// Return:         PL_CAL, PL_PGM, PL_DAQ or 0
//

#ifndef random 
static CCP_DWORD RndCnt = 0x4fe9d61;
static CCP_DWORD random(CCP_DWORD max) {
  RndCnt += max + RndCnt/3;
  return RndCnt % (max+1);
}
#endif


CCP_BYTE ccpResourceMask = 0;
CCP_DWORD ccpLastSeed = 0;

CCP_DWORD ccpGetSeed( CCP_BYTE resourceMask )
{
  ccpResourceMask = resourceMask;

  /* Generate a seed */
  /* Example: */
  /* Optimum is a number which never appears twice */
  ccpLastSeed = random(0xFFFF);
  return ccpLastSeed;
}

CCP_BYTE ccpUnlock( CCP_BYTE *key )
{
  CCP_BYTE res;

  /* Check the key */
  /* Example: */
  ccpLastSeed = (ccpLastSeed>>5) | (ccpLastSeed<<23);
  ccpLastSeed *= 7;
  ccpLastSeed ^= 0x26031961;
  if ( *(CCP_DWORD*)key != ccpLastSeed ) {
    return 0;
  }

  /* Reset resource protection bit */
  res = ccpResourceMask;
  ccpResourceMask = 0;
  return res;
}

#endif



/**************************************************************************/
// main()
/**************************************************************************/
//

// help
static void usage( void ) {

  printf(
    "\n"
    "Usage:\n"
    "  " APP_NAME " [options]\n"
    "\n"
    "  Options:\n"
    "    -tx    Set screen output verbosity to x (Default 1)\n"
    "    -bx    Set CAN bitrate to x (Default not initialized)\n"
    "    -v     Use a virtual channel (Default CANcardX)\n"
    "           CANape will be automatically configured to virtual channels\n"
    "    -ac2   Use a CANac2 channel\n"
    "    -pci   Use a CANac2-PCI channel\n"
    "    -pari  Use a CANpari channel\n"
    "    -cardx Use a CANcardX channel\n"
    "    -1     Use channel 1 (Default)\n"
    "    -2     Use channel 2\n"
    "    -crox  Set CRO identifier to x (Default 1639)\n"
    "    -dtox  Set DTO identifier to x (Default 2017)\n"
    "    -x     Use extended ids (Default standard)\n"
    "    -addr  Set slave address to x (Default 57)\n"
    "    -ram   Enable generic RAM emulation\n"
    "    -init  Init flash to default\n"
    "\n"
    "  Keyboard commands:\n"
    "    1-4    Set screen output verbosity 1..4\n"
    "    T      Trigger event channel 1\n"
    "    ESC    Exit\n"
    "\n"
    );

    exit(0);
}

int handleKey( int key ) {

  switch (key) {

    // Help
    case 'h':
    case 'H':
      usage();
      break;

    // Trigger a DAQ event
    #ifdef CCP_DAQ
    case 't':
    case 'T': ccpDaq(1);
      break;
    #endif

    // Debuglevel
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
      gDebugLevel = key-'0';
      break;

    // ESC
    case 27:
      return 1;
      //break;

    default:
      break;
  }

  return 0;
}

// thread running ccpDaq()
//#pragma argsused
CCP_DWORD WINAPI thread( PVOID par ) {

  int i;

  i = 0;
  threadRunning = 1;
  while (threadRunning) {

    /* CCP driver background processing */
    ccpBackground();

    /* ECU Simulation */
    ecuCyclic();

    #ifdef CCP_DAQ

    /* Event Channel 10 is cyclic 10 ms */
    ccpDaq(10);

    /* Event Channel 11 is cyclic 100 ms */
    if (++i>=10) {
      i=0;
      ccpDaq(11);
    }

    #endif

    /* Delay */
    Sleep(10);
  }

  return 0;
}


int main( int argc, char *argv[])
{
  int i;
  unsigned int u;

  printf(
    APP_NAME " ECU simulator with CCP\n"
    "Vector Informatik GmbH, 1997-2002\n\n"
    "Build " __DATE__ " " __TIME__ "\n"
    "Driver version 137\n"
    #ifndef __BORLANDC__
    "Microsoft Version\n"
    #endif
  );

 
  #ifndef __BORLANDC__
  {
    #ifdef ABSOLUT_ADRESS_CALC 
    {
      dataSeg = GetStartAdress(NULL,NULL);
      printf("Module start adress = 0x%08x\nCANape mapfilereader Microsoft extended necessary\n",dataSeg);
    }
    #else
    {
      printf("__xc_a_ start adress = 0x%08x\nCANape mapfilereader Microsoft standard necessary\n",dataSeg);
    }
    #endif
  }
  #endif
  
  
  // Get default hardware configuration from VCANCONF
  {
    int type, index, channel;
    if (VSUCCESS==ncdGetApplConfig("CCPsim",0,&type,&index,&channel)) {
      hwType = type;
      hwChannel = channel;
      hwIndex = index;
    }
  }

  // Parse commandline
  for (i=1; i<argc; i++) {
      char c;
      if (strcmp(argv[i], "-h") == 0) {
          usage();
      } else if (strcmp(argv[i], "-v") == 0) {
          hwType = HWTYPE_VIRTUAL;
          printf("Use a virtual channel\n");
      } else if (strcmp(argv[i], "-cardx") == 0) {
          hwType = HWTYPE_CANCARDX;
          printf("Use a CANcardX channel\n");
      } else if (strcmp(argv[i], "-ac2") == 0) {
          hwType = HWTYPE_CANAC2;
          printf("Use a CANac2 channel\n");
      } else if (strcmp(argv[i], "-pci") == 0) {
          hwType = HWTYPE_CANAC2PCI;
          printf("Use a CANac2-PCI channel\n");
      } else if (strcmp(argv[i], "-pari") == 0) {
          hwType = HWTYPE_CANPARI;
          printf("Use a CANpari channel\n");
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
      } else if (strcmp(argv[i], "-ram") == 0) {
          printf("RAM emulation enabled\n");
          gRam = 1;
      } else if (strcmp(argv[i], "-flash") == 0) {
          printf("RAM + FLASH emulation enabled\n");
          gRam = 2;
      } else if (strcmp(argv[i], "-init") == 0) {
          remove("FLASH.DAT");
          remove("CCPSIM.DAT");
          printf("Init flash\n");
      } else if (sscanf(argv[i], "-b%u", &u) == 1) {
        if (u>5000&&u<=1000000) gBitRate = u;
        printf("Initialize CAN hardware to %u BPS\n",gBitRate);
      } else if (sscanf(argv[i], "-cro%u", &u) == 1) {
        CCP_CRO_ID = u;
        printf("CCP_CRO_ID = %u\n",CCP_CRO_ID);
      } else if (sscanf(argv[i], "-dto%u", &u) == 1) {
        CCP_DTO_ID = u;
        printf("CCP_DTO_ID = %u\n",CCP_DTO_ID);
      } else if (sscanf(argv[i], "-addr%u", &u) == 1) {
        CCP_STATION_ADDR = u;
        printf("CCP_STATION_ADDR = %u\n",CCP_STATION_ADDR);
      } else if (sscanf(argv[i], "-t%c", &c) == 1) {
          gDebugLevel = c-'0';
          printf("Set screen output verbosity to %u\n",gDebugLevel);
      } else {
          usage();
      }
  }

  printf("\n");

  // Set default hardware configuration in VCANCONF
  ncdSetApplConfig("CCPsim",0,hwType,hwIndex,hwChannel);

  // Initialize Address -> Pointer
  if (!gRam) {
    extern CCP_BYTE flashSignatur;
    if (gDebugLevel) {
      printf("\nCANape Calibration RAM Settings:\n");
      printf(" CALRAM_SECTOR_COUNT = 1\n");
      printf(" CALRAM_SECTOR_ADDR_1 = 0x%08X\n",(CCP_BYTE*)&CALRAM_START-dataSeg);
      printf(" CALRAM_SECTOR_SIZE_1 = 0x%08X\n",(CCP_BYTE*)&CALRAM_LAST-(CCP_BYTE*)&CALRAM_START+1);
      printf("\nRequired CANape FLASH Settings:\n");
      printf(" FLASH_SECTOR_COUNT = 1\n");
      printf(" FLASH_SECTOR_ADDR_1 = 0x%08X\n",(CCP_BYTE*)&CALRAM_START-dataSeg);
      printf(" FLASH_SECTOR_SIZE_1 = 0x%08X\n",(CCP_BYTE*)&CALRAM_LAST-(CCP_BYTE*)&CALRAM_START+1);
      printf(" FLASH_SIGN   = 0x%08X\n",(CCP_BYTE*)&flashSignatur-dataSeg);
      printf(" FLASH_SIZE   = 32\n\n");

      #if 0
      {
        extern float ampl;
        printf(" dataSeg = 0x%08X\n",dataSeg);
        printf(" &ampl = 0x%08X\n",(CCP_BYTE*)&ampl-dataSeg);
      }
      #endif


    }
  }

  // Initialize the generic ram/flash emulation feature
  if (gRam) {

    ramInit();
    #ifdef CCP_PROGRAM
      flashInit();
      if (gRam==2) {
        flashRead();
        flashCopy();
      }
    #endif

  } else {

    // Initialize the ECU.C flash emulation feature
    #ifdef CCP_PROGRAM
      ccpInitFlash();
    #endif

  }

  // Initialize CCP driver
  ccpInit();

  // Initialize ECU simulation
  ecuInit();

  // Create the DAQ thread
  threadHandle = CreateThread(0,0x1000,thread,0,0,&threadId);
  SetThreadPriority(threadHandle,THREAD_PRIORITY_TIME_CRITICAL);

  // Mainloop
  canMain();

  // Stop DAQ thread
  if (threadHandle) {
    threadRunning = 0;
    WaitForSingleObject(threadHandle,5000);
  }

  // Write Flash to disk
  #ifdef CCP_PROGRAM
    if (gRam) {
      flashWrite();
    } else {
      ccpWriteFlash();
    }
  #endif

  return 0;
}

void canMain( void ) {

  int end,i;
  Vstatus vErr;
  Vevent *pEvent;
  HANDLE h;
  HANDLE mainThreadHandle;

  #ifdef CCP_LATENCY_TEST
    unsigned int txRqTime;
  #endif

  // Initialize the CAN driver
  vErr = InitDriver(hwType,hwIndex,hwChannel);
  if (vErr) goto error;

  // Create a synchronisation object
  h = CreateEvent(NULL, FALSE, FALSE, NULL);
  vErr = ncdSetNotification(gPortHandle, (void*)&h, 1);
  if (vErr) goto ncdError;

  // channel on bus
  vErr = ncdActivateChannel(gPortHandle,gChannelMask);
  if (vErr) goto ncdError;


  mainThreadHandle = GetCurrentThread();
  SetThreadPriority(mainThreadHandle, THREAD_PRIORITY_ABOVE_NORMAL);
  // Mainloop
  end = 0;
  while (!end) {

    // Wait for receive event
    WaitForSingleObject(h,500);

    // Receive
    for (;;) { // read all events

      vErr = ncdReceive1(gPortHandle,&pEvent);
      if (vErr&&vErr!=VERR_QUEUE_IS_EMPTY) goto ncdError;
      if (vErr==VERR_QUEUE_IS_EMPTY) break;

      // check for the ccp cro message
      if (pEvent->tag==V_RECEIVE_MSG) {
        if (pEvent->tagData.msg.flags & MSGFLAG_ERROR_FRAME) {
          printf("Error Frame!\n");
        }
        else if (pEvent->tagData.msg.id==CCP_DTO_ID) {

          #ifdef CCP_LATENCY_TEST
            if (pEvent->tagData.msg.flags&MSGFLAG_TXRQ) {
              txRqTime = pEvent->timeStamp;
            }
          #endif

          if (pEvent->tagData.msg.flags&MSGFLAG_TX) {

            #ifdef CCP_LATENCY_TEST
              ccpLatencyTime = pEvent->timeStamp-txRqTime;
            #endif

            /* Notify the CCP driver */
            if (!ccpSendCallBack()) {
            }
          }
        }
        if (pEvent->tagData.msg.id==CCP_CRO_ID) {

          // Screen output
          if (gDebugLevel>=2) {
            printf("RX: ");
            for (i=0;i<pEvent->tagData.msg.dlc;i++) printf(" %02X",pEvent->tagData.msg.data[i]);
            printf("\n");
          }

          ccpCommand(&pEvent->tagData.msg.data[0]);

        }
      }

    } // for


    // Check keyboard
    if (kbhit()) {
      int c = getch();
      if (handleKey(c)) {
        end = 1;
      }
    }

  } // while(!end);


error:

  ncdDeactivateChannel(gPortHandle, gChannelMask);
  CleanUp();
  return;

ncdError:
  printf("ERROR: %s\n",ncdGetErrorString(vErr));
  goto error;
}
