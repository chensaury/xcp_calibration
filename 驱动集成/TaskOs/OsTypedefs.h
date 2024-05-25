/*
 * Osif_define.h
 *
 *  Created on: 06.12.2023
 *
 */

#ifndef __OSIF_DEFINE_H__
#define __OSIF_DEFINE_H__

#include "Cpu.h"
#include "OsCfg_Isr.h"

#ifndef TRUE
#define TRUE  (1)
#endif

#ifndef FALSE
#define FALSE (0)
#endif

#ifndef NULL_PTR
#define NULL_PTR    (void*)(0)
#endif

#define boolean  uint8_t
#define uint8 uint8_t
#define uint16 uint16_t
#define uint32 uint32_t
#define sint8 int8_t
#define sint16 int16_t
#define sint32 int32_t

typedef  float float32;


#include <OsTimerTick.h>
#include "OsTaskFu.h"
#include "OsScheduler.h"

#include "OsCfg_Scheduler.h"
#include "OsCfg_Isr.h"

extern void OsMainInit(void);
extern void OsMain(void);





#endif /* __OSIF_DEFINE_H__ */
