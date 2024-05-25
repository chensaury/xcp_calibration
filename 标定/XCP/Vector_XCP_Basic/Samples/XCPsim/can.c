/*----------------------------------------------------------------------------
| File:
|   CAN.C
|
| Project:
|   CAN Transport Layer for XCPsim
|
 ----------------------------------------------------------------------------*/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <io.h>
#include <conio.h>
#include <dos.h>

// CAN driver
#include "VCanD.h"

// XCP driver
#include "xcpbasic.h"

// XCPsim
#include "xcpsim.h"




int hwType                   = HWTYPE_VIRTUAL;
int hwChannel                = 0; 
int hwIndex                  = 0;
unsigned int gBitRate        = 0;

DWORD gDtoId                 = 2;
DWORD gCroId                 = 1;

VportHandle gPortHandle      = INVALID_PORTHANDLE;
Vaccess gChannelMask         = 0;
Vaccess gPermissionMask      = 0;
VDriverConfig *gDriverConfig = 0;




///////////////////////////////////////////////////////////////////////
// canGetDefaults()
//---------------------------------------------------------------------

void canGetDefaults( void )  {
    int type, index, channel;
    if (VSUCCESS==ncdGetApplConfig("XCPsim",0,&type,&index,&channel)) {
      hwType = type;
      hwChannel = channel;
      hwIndex = index;
    }
}

///////////////////////////////////////////////////////////////////////
// InitDriver ()
//---------------------------------------------------------------------
// initializes the CAN driver

static Vstatus InitDriver( int hwType, int hwIndex, int hwChannel, int open )
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


  // Open a port
  gPermissionMask = (gBitRate>0) ? gChannelMask : 0; // If no bitrate specified, don't init
  sprintf(name,"XCPsim-%u",gCroId);
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
  if (open) {
    acc.code = 0;
    acc.mask = 0; // relevant=1
  } else {
    acc.code = gCroId;
    acc.mask = (acc.code&0x80000000UL) ? 0x9FFFFFFFUL : 0x7FF; // relevant=1
  }  
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


  ncdCloseDriver();
  return VSUCCESS; // No error handling
}                                                    // ..end CleanUp()


///////////////////////////////////////////////////////////////////////
// canSend()
//---------------------------------------------------------------------
// CAN transmit

int canSend( BYTE len, const BYTEPTR msg ) {
    
  Vstatus vErr;
  Vevent event;

  if (len>8) {
    printf("ERROR: Illegal packetsize %u for CAN",len);
    return 0;
  }
	
  event.tag                 = V_TRANSMIT_MSG;
  event.tagData.msg.id      = gDtoId;
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


///////////////////////////////////////////////////////////////////////
// canMain()
//---------------------------------------------------------------------
// CAN mainloop

void canMain( void ) {

  int i;
  Vstatus vErr;
  Vevent *pEvent;
  unsigned int txRqTime;
  HANDLE h;

  // Initialize the CAN driver
  vErr = InitDriver(hwType,hwIndex,hwChannel,TRUE);
  if (vErr) goto error;

  // Create a synchronisation object
  h = CreateEvent(NULL, FALSE, FALSE, NULL);
  vErr = ncdSetNotification(gPortHandle, (void*)&h, 1);
  if (vErr) goto ncdError;

  // channel on bus
  vErr = ncdActivateChannel(gPortHandle,gChannelMask);
  if (vErr) goto ncdError;

  // Mainloop
  mainRunning = 1;
  while (mainRunning) {

    // Wait for receive event
    WaitForSingleObject(h,500);

    // Receive
    for (;;) { // read all events

      vErr = ncdReceive1(gPortHandle,&pEvent);
      if (vErr&&vErr!=VERR_QUEUE_IS_EMPTY) goto ncdError;
      if (vErr==VERR_QUEUE_IS_EMPTY) break;

      // Print all incoming events
      if (gDebugLevel>=4) {
        static unsigned int lastTime = 0;
        unsigned int time = pEvent->timeStamp;
        printf("%gs: %s\n",(double)(time-lastTime)/100000.0,ncdGetEventString(pEvent));
        lastTime = time;
      }

      // check for the xcp cro message
      if (pEvent->tag==V_RECEIVE_MSG) {

        if (pEvent->tagData.msg.flags & MSGFLAG_ERROR_FRAME) {
          printf("Error Frame!\n");
        }
        else if (pEvent->tagData.msg.id==gDtoId) {
          if (pEvent->tagData.msg.flags&MSGFLAG_TXRQ) {
            txRqTime = pEvent->timeStamp;
          }
          if (pEvent->tagData.msg.flags&MSGFLAG_TX) {
            
            /* Notify the xcp driver */
            XcpSendCallBack();
          }
        }
        if (pEvent->tagData.msg.id==gCroId) {

          // Print raw CRO message data
          if (gDebugLevel>=2&&gDebugLevel<4) {
            printf("CRO: ");
            for (i=0;i<pEvent->tagData.msg.dlc;i++) printf(" %02X",pEvent->tagData.msg.data[i]);
            printf("\n");
          }

          XcpCommand((void*)&pEvent->tagData.msg.data[0]);

        }
      }

    } // for


    // Check keyboard
    if (_kbhit()) {
      int c = _getch();
      if (handleKey(c)) {
        mainRunning = 0;
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
