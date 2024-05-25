/*----------------------------------------------------------------------------
| File:
|   VCAND.H
| Project:
|   CAN driver for Win NT and Win 95
|
| Description:
|   Driver Interface Prototypes
|
|-----------------------------------------------------------------------------
| $Author: visds $    $Locker: $   $Revision: 271 $
| $Header: /CCP/CCPsim/VCanD.h 2     23.11.00 13:17 Martin $
|-----------------------------------------------------------------------------
| Copyright (c) 1996 by Vector Informatik GmbH.  All rights reserved.
 ----------------------------------------------------------------------------*/

#ifndef _V_CAND_H_
#define _V_CAND_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef char * ncdStringType;

#if (__FLAT__) || defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
  #if (_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED) || defined(__BORLANDC__)
    #define _EXPORT_API     __stdcall
  #else
    #define _EXPORT_API
  #endif
#else
  #define _EXPORT_API       _far _pascal
#endif

#define _EXPORT_DECL  __declspec(dllimport) _EXPORT_API
#define _EXPORT_DEF  __declspec(dllimport) _EXPORT_API

#include <pshpack1.h>

#define MAX_APPNAME 32

//------------------------------------------------------------------------------
// define for ReceiveMode

#define VCAN_WAIT   0
#define VCAN_POLL   1
#define VCAN_NOTIFY 2

//------------------------------------------------------------------------------
// driver status

typedef short Vstatus;

#define VSUCCESS                     0
#define VPENDING                     1
#define VERROR                       255
#define VERR_QUEUE_IS_EMPTY          10
#define VERR_QUEUE_IS_FULL           11
#define VERR_TX_NOT_POSSIBLE         12
#define VERR_NO_LICENSE              14
#define VERR_WRONG_PARAMETER         101
#define VERR_TWICE_REGISTER          110
#define VERR_INVALID_CHAN_INDEX      111
#define VERR_INVALID_ACCESS          112
#define VERR_PORT_IS_OFFLINE         113
#define VERR_CHAN_IS_ONLINE          116
#define VERR_INVALID_PORT            118
#define VERR_HW_NOT_READY            120
#define VERR_CMD_TIMEOUT             121
#define VERR_HW_NOT_PRESENT          129
#define VERR_NOTIFY_ALREADY_ACTIVE   131
#define VERR_CANNOT_OPEN_DRIVER      201


//------------------------------------------------------------------------------
// accessmask

typedef unsigned long Vaccess;

// build a channels mask from the channels index
#define CHANNEL_MASK(x) (1<<(x))

//------------------------------------------------------------------------------
// porthandle

#define INVALID_PORTHANDLE (-1)
typedef long VportHandle;

//------------------------------------------------------------------------------
// acceptance filter

typedef struct _Vset_acceptance {
  unsigned long code;
  unsigned long mask;
} VsetAcceptance;

//------------------------------------------------------------------------------
// bit timing

typedef struct {
  unsigned long bitRate;
  unsigned char sjw;
  unsigned char tseg1;
  unsigned char tseg2;
  unsigned char sam;  // 1 or 3
} VchipParams;

//------------------------------------------------------------------------------
// definitions for the events and commands used by the driver

enum _Vevent_type {
  V_RECEIVE_MSG           = 1,
  V_CHIP_STATE            = 4,
  V_CLOCK_OVERFLOW        = 5,
  V_TRIGGER               = 6,
  V_TIMER                 = 8,
  V_TRANSCEIVER           = 9,
  V_TRANSMIT_MSG          = 10
};


typedef unsigned char VeventTag;

//------------------------------------------------------------------------------
// events

//------------------------------------------------------------------------------
// structure for V_RECEIVE_MSG

#define MAX_MSG_LEN 8
#define EXT_MSG 0x80000000 // signs an extended identifier

#define MSGFLAG_ERROR_FRAME         0x01        // Msg is a bus error
#define MSGFLAG_OVERRUN             0x02        // Msgs following this has been lost
#define MSGFLAG_NERR                0x04        // NERR active during this msg
#define MSGFLAG_WAKEUP              0x08        // Msg rcv'd in wakeup mode
#define MSGFLAG_REMOTE_FRAME        0x10        // Msg is a remote frame
#define MSGFLAG_RESERVED_1          0x20        // Reserved for future usage
#define MSGFLAG_TX                  0x40        // TX acknowledge
#define MSGFLAG_TXRQ                0x80        // TX request

// 14 Bytes
struct _Vmsg {
  unsigned long id;
  unsigned char flags;
  unsigned char dlc;
  unsigned char data[MAX_MSG_LEN];
};


// structure for V_CHIP_STATE

#define CHIPSTAT_BUSOFF              0x01
#define CHIPSTAT_ERROR_PASSIVE       0x02
#define CHIPSTAT_ERROR_WARNING       0x04
#define CHIPSTAT_ERROR_ACTIVE        0x08

struct _VchipState {
  unsigned char busStatus;
  unsigned char txErrorCounter;
  unsigned char rxErrorCounter;
};


// structure for V_TRANSCEIVER

#define TRANSCEIVER_EVENT_ERROR   1
#define TRANSCEIVER_EVENT_CHANGED 2

#define TRANSCEIVER_TYPE_NONE     0
#define TRANSCEIVER_TYPE_251      1
#define TRANSCEIVER_TYPE_252      2
#define TRANSCEIVER_TYPE_DNOPTO   3
#define TRANSCEIVER_TYPE_W210     4
#define TRANSCEIVER_TYPE_SWC_PROTO       5  // Prototype. Driver may latch-up.
#define TRANSCEIVER_TYPE_SWC             6

#define TRANSCEIVER_LINEMODE_NA       0
#define TRANSCEIVER_LINEMODE_TWO_LINE 1
#define TRANSCEIVER_LINEMODE_CAN_H    2
#define TRANSCEIVER_LINEMODE_CAN_L    3
#define TRANSCEIVER_LINEMODE_SWC_SLEEP   4  // SWC Sleep Mode.
#define TRANSCEIVER_LINEMODE_SWC_NORMAL  5  // SWC Normal Mode.
#define TRANSCEIVER_LINEMODE_SWC_FAST    6  // SWC High-Speed Mode.
#define TRANSCEIVER_LINEMODE_SWC_WAKEUP  7  // SWC Wakeup Mode.


#define TRANSCEIVER_RESNET_NA          0
#define TRANSCEIVER_RESNET_MASTER      1
#define TRANSCEIVER_RESNET_MASTER_STBY 2
#define TRANSCEIVER_RESNET_SLAVE       3

struct _Vtransceiver {
  unsigned char event;       // TRANSCEIVER_EVENT_xxx
};


typedef struct _Vevent {
  VeventTag           tag;             // 1
  unsigned char       chanIndex;       // 1
  unsigned char       _transId;        // 1 not implemented yet !!!!
  unsigned char       portHandle;      // 1 internal use only !!!!
  unsigned long       timeStamp;       // 4
  union {
    struct _Vmsg                  msg;
    struct _VchipState            chipState;
    struct _Vtransceiver          transceiver;
  } tagData;                           // 14 Bytes (_VMessage)
} Vevent;
                                       // --------
                                       // 22 Bytes

//------------------------------------------------------------------------------
// structure for SET_OUTPUT_MODE

#define OUTPUT_MODE_SILENT 0
#define OUTPUT_MODE_NORMAL 1


//------------------------------------------------------------------------------
// configuration

// defines for the supported hardware
#define HWTYPE_NONE         0
#define HWTYPE_VIRTUAL      1
#define HWTYPE_CANCARDX     2
#define HWTYPE_CANPARI      3
#define HWTYPE_CANDONGLE    4
#define HWTYPE_CANAC2       5
#define HWTYPE_CANAC2PCI    6
#define HWTYPE_CANCARD      7
#define MAX_HWTYPE          7

// defines for the tranceiver type
#define TRANSCEIVER_TYPE_NONE     0
#define TRANSCEIVER_TYPE_251      1
#define TRANSCEIVER_TYPE_252      2
#define TRANSCEIVER_TYPE_DNOPTO   3
#define TRANSCEIVER_TYPE_W210     4
#define MAX_TRANSCEIVER_TYPE      4

#define MAX_CHAN_NAME   31
#define MAX_DRIVER_NAME 31

typedef struct _VChannelConfig {

  char              name[MAX_CHAN_NAME+1];
  unsigned char     hwType;         // HWTYPE_xxxx (see above)
  unsigned char     hwIndex;        // Index of the hardware (same type) (0,1,...)
  unsigned char     hwChannel;      // Index of the channel (same hardware) (0,1,...)
  unsigned char     tranceiverType; // TRANCEIVER_TYPE_xxxx (see above)
  unsigned char     channelIndex;   // Global channel index (0,1,...)
  unsigned long     channelMask;    // Global channel mask (=1<<channelIndex)

  // Channel
  unsigned char     isOnBus;        // The channel is on bus
  VchipParams       chipParams;     // Actual bittiming
  unsigned char     outputMode;     // Actual output mode
  unsigned char     flags;          // Actual options MSGFLAG_TX,MSGFLAG_TXRQ

} VChannelConfig;

typedef struct _VDriverConfig {
  char              driverName[MAX_DRIVER_NAME+1];
  unsigned short    driverVersion;
  void*             dispatcher;
  unsigned char     channelCount;  // total number of channels
  VChannelConfig    channel[1];    // [channelCount]
} VDriverConfig;

#define SIZEOF_VDRIVERCONFIG(n) (sizeof(VDriverConfig)+(n-1)*sizeof(VChannelConfig))

#include <poppack.h>


/*******************************************************************
ncdOpenDriver():

The Application calls this function to get access to the driver.
*/
Vstatus _EXPORT_DECL ncdOpenDriver(void);


/********************************************************************
ncdGetDriverConfig():

The application gets the information, which
CAN channels are available in the system. The user
must provide the memory, pChanCount is pointing to
and the size of pDriverConfig. Passing NULL
for pDriverConfig only the ChanCount is given back.
*/
Vstatus _EXPORT_DECL ncdGetDriverConfig(
  int           *pChanCount,
  VDriverConfig *pDriverConfig
);


/********************************************************************
ncdGetChannelIndex():
ncdGetChannelMask():

Get the channel index for a channel of a certain hardware.
Parameter -1 means "don't care"
Result -1 (ncdGetChannelIndex) or 0 (ncdGetChannelMask) means "not found"
*/
int _EXPORT_DECL ncdGetChannelIndex(
  int hwType,     // [-1,HWTYPE_CANCARDX,HWTYPE_VIRTUAL,...]
  int hwIndex,    // [-1,0,1]
  int hwChannel   // [-1,0,1]
);

Vaccess _EXPORT_DECL ncdGetChannelMask(
  int hwType,     // [-1,HWTYPE_CANCARDX,HWTYPE_VIRTUAL,...]
  int hwIndex,    // [-1,0,1]
  int hwChannel   // [-1,0,1]
);



/********************************************************************
ncdOpenPort():

The application tells the driver to which channels
it wants to get access to and which of these channels
it wants to get the permission to initialize the channel.
Only one port can get the permission to initialize a channel.
The permitted init access is returned.
*/
Vstatus _EXPORT_DECL ncdOpenPort(
  VportHandle   *portHandle,
  char          *userName,
  Vaccess        accessMask,
  Vaccess        initMask,
  Vaccess       *permissionMask,
  int            rxQueueSize
  );


/********************************************************************
ncdSetChannelMode():

For the CAN channels defined by AccessMask is set
whether the caller will get a TX and/or a TXRQ
receipt for transmitted messages.
The port must have init access to the channels.
*/
Vstatus _EXPORT_DECL ncdSetChannelMode(VportHandle    portHandle,
                                      Vaccess       accessMask,
                                      int           tx,
                                      int           txrq
);


/********************************************************************
ncdSetChannelOutput():

The output mode for the CAN chips of the channels defined by accessMask, is set
to OUTPUT_MODE_NORMAL or OUTPUT_MODE_SILENT.
The port must have init access to the channels.
*/
Vstatus _EXPORT_DECL ncdSetChannelOutput(VportHandle portHandle,
                                        Vaccess    accessMask,
                                        int        mode
);



/********************************************************************
ncdSetChannelParams():
ncdSetChannelParamsC200():
ncdSetChannelBitrate():

The channels defined by accessMask will be initialized with the
given parameters.
The port must have init access to the channels.
*/
Vstatus _EXPORT_DECL ncdSetChannelParams(VportHandle   portHandle,
                                        Vaccess       accessMask,
                                        VchipParams*  pChipParams
);

Vstatus _EXPORT_DECL ncdSetChannelParamsC200(VportHandle   portHandle,
                                            Vaccess       accessMask,
                                            unsigned char btr0,
                                            unsigned char btr1
);


Vstatus _EXPORT_DECL ncdSetChannelBitrate(VportHandle   portHandle,
                                         Vaccess       accessMask,
                                         unsigned long bitrate
);


/********************************************************************
ncdSetAcceptance():

Set the acceptance filter
Filters for std and ext ids are handled independant in the driver.
Use mask=0xFFFF,code=0xFFFF or mask=0xFFFFFFFF,code=0xFFFFFFFF to fully close
the filter.
*/
Vstatus _EXPORT_DECL ncdSetChannelAcceptance(VportHandle     portHandle,
                                             Vaccess         accessMask,
                                             VsetAcceptance *filter
);


/********************************************************************
ncdSetTimerRate():

The timer of the port will be activated/deacticated and the
rate for cyclic timer events is set (10us resolution).
*/
Vstatus _EXPORT_DECL ncdSetTimerRate(
  VportHandle portHandle,
  unsigned long timerRate
);


/********************************************************************
ncdResetClock():

The clock generating timestamps for the port will be reset

*/
Vstatus _EXPORT_DECL ncdResetClock(
  VportHandle portHandle
);


/********************************************************************
ncdSetNotification():

Setup a event to notify the application if there are messages in the
ports receive queue.
queueLevel specifies the number of messages that triggeres the event.
Note that the event is triggered only once, when the queueLevel is
reached. An application should read all available messages by ncdReceive
to be sure to reenable the event.

*/
Vstatus _EXPORT_DECL ncdSetNotification(
  VportHandle portHandle,
  unsigned long *handle,
  int queueLevel
);

/********************************************************************
ncdTransmit():

A CAN message will be put to the designated channels to be transmitted.

*/
Vstatus _EXPORT_DECL ncdTransmit(VportHandle    portHandle,
                                 Vaccess       accessMask,
                                 Vevent*       pEvent
);


/********************************************************************
ncdReceive1():

The driver is asked to retrieve a single Events from the
application's receive queue. This function is optimized
for speed. It returns a pointer to the received event.
Lifetime of the data is until the next call of ncdReceive1.
It returns VERR_QUEUE_IS_EMPTY and *ppEvent=NULL if no event
is available.

*/
Vstatus _EXPORT_DECL ncdReceive1(VportHandle portHandle,
                                Vevent    **ppEvent
);


/********************************************************************
ncdReceive():

The driver is asked to retrieve Events from the
application's receive queue. You can choose wether
it will be polled or waited for an incoming event.
Its possible to read multiple events at a time, but the
caller must provide the memory. In pEventCount the actual
number of received events will be returned.
*/
Vstatus _EXPORT_DECL ncdReceive(VportHandle     portHandle,
                                int             receiveMode,
                                unsigned int    waitHandle,
                                int            *pEventCount,
                                Vevent         *pEventList
);


/********************************************************************
ncdRequestChipState():

The state of the selected channels is requested.
The answer will be received as an event (V_CHIP_STATE).
*/
Vstatus _EXPORT_DECL ncdRequestChipState (VportHandle portHandle,
                                          Vaccess    accessMask
);


/********************************************************************
ncdFlushTransmitQueue():

The transmit queue of the selected channel will be flushed.
*/
Vstatus _EXPORT_DECL ncdFlushTransmitQueue (VportHandle portHandle,
                                            Vaccess    accessMask
);


/********************************************************************
ncdFlushReceiveQueue():

The receive queue of the port will be flushed.
*/
Vstatus _EXPORT_DECL ncdFlushReceiveQueue(VportHandle portHandle);


/********************************************************************
ncdGetReceiveQueueLevel():

The count of event´s in the receive queue of the port will be returned.
*/
Vstatus _EXPORT_DECL ncdGetReceiveQueueLevel(VportHandle portHandle,
                                             int       *level
);


/********************************************************************
ncdGetState():

The state of the port is returned.
*/
Vstatus _EXPORT_DECL ncdGetState(VportHandle portHandle);


/********************************************************************
ncdActivateChannel():

The selected channels go 'on the bus'.
*/
Vstatus _EXPORT_DECL ncdActivateChannel(VportHandle portHandle,
                                        Vaccess    accessMask
);


/********************************************************************
DeactivateChannel():

The selected channels go 'off the bus'.
Its now possible to initialize

*/
Vstatus _EXPORT_DECL ncdDeactivateChannel(VportHandle portHandle,
                                          Vaccess    accessMask
);


/********************************************************************
ncdClosePort():

The port is closed, channels are deactivated.

*/
Vstatus _EXPORT_DECL ncdClosePort(VportHandle portHandle);


/********************************************************************
ncdCloseDriver ():

The driver is closed.
This is used to unload the driver, if no more application is useing it.
Does not close the open ports !!!
*/
Vstatus _EXPORT_DECL ncdCloseDriver(void);


/********************************************************************

ncdGetErrorString()
ncdGetEventString()

Utility Functions
*/

ncdStringType _EXPORT_DECL ncdGetErrorString( Vstatus err );
ncdStringType _EXPORT_DECL ncdGetEventString( Vevent *ev );

/********************************************************************
ncdSetApplConfig():
ncdGetApplConfig():

Handle the application configuration for VCANCONF.EXE
*/

Vstatus _EXPORT_DEF ncdSetApplConfig(
    char   *appId,          // Name
    int     appChannel,     // 0,1
    int     hwType,         // HWTYPE_xxxx
    int     hwIndex,        // Index of the hardware (slot) (0,1,...)
    int     hwChannel       // Index of the channel (connector) (0,1,...)
);

Vstatus _EXPORT_DEF ncdGetApplConfig(
    char   *appId,          // Name
    int     appChannel,     // 0,1
    int    *hwType,         // HWTYPE_xxxx
    int    *hwIndex,        // Index of the hardware (slot) (0,1,...)
    int    *hwChannel       // Index of the channel (connector) (0,1,...)
);


#ifdef __cplusplus
}
#endif   // _cplusplus

#endif


