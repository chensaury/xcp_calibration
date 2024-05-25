/*
 * OsScheduler.h
 *
 *  Created on:  06.12.2023
 *
 */

#ifndef APPSCHEDULER_H_
#define APPSCHEDULER_H_


typedef void (*schedulerCallback)(void);

typedef struct
{
	uint32 taskoffset;
	uint32 taskreload;
	boolean countinous;
	schedulerCallback  callback;   /**< \brief Specifies callback routine */
}osScheduler_cfg_tasks;

typedef struct
{
	uint32 taskcounter;
	uint32 taskreload;
	boolean countinous;
	uint32 overflow;
	boolean run;
	schedulerCallback  callback;   /**< \brief Specifies callback routine */
}osScheduler_task;


void OsScheduler_initTask(osScheduler_task *handle,osScheduler_cfg_tasks *config);

void OsScheduler_tick(osScheduler_task *handle);

void OsScheduler_process(osScheduler_task *handle);

void OsScheduler_init(void);

#endif /* APPSCHEDULER_H_ */
