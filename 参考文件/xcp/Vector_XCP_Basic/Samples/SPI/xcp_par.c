/*----------------------------------------------------------------------------
| File:
|   XCP_PAR.C
|
| Project:
|   XCP on SPI Sample
|
| Description:
|   XCP custom definitions
|
 ----------------------------------------------------------------------------*/

#include "xcpBasic.h"


// Slave device id
// CANape uses this to determine the name of the A2L file
#if defined ( kXcpStationIdLength )
  V_MEMROM0 MEMORY_ROM vuint8 kXcpStationId[kXcpStationIdLength] = kXcpStationIdString;
#endif


