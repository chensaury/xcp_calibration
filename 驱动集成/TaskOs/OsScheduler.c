/*
 * OsScheduler.c
 *
 *  Created on: 06.12.2023
 *
 */

#include "OsTypedefs.h"

osScheduler_task g_tasks_core0[OsScheduler_Task_count];

void OsScheduler_init(void)
{
    // Initialize AppScheduler Tasks
        osScheduler_cfg_tasks config = osScheduler_task_config[OsScheduler_Task_10ms];
        config.callback = (schedulerCallback) &OsTaskfu_10ms;
        OsScheduler_initTask(&g_tasks_core0[OsScheduler_Task_10ms],&config);

        config = osScheduler_task_config[OsScheduler_Task_100ms];
        config.callback = (schedulerCallback) &OsTaskfu_100ms;
        OsScheduler_initTask(&g_tasks_core0[OsScheduler_Task_100ms],&config);

        config = osScheduler_task_config[OsScheduler_Task_200ms];
        config.callback = (schedulerCallback) &OsTaskfu_200ms;
        OsScheduler_initTask(&g_tasks_core0[OsScheduler_Task_200ms],&config);

        config = osScheduler_task_config[OsScheduler_Task_1ms];
        config.callback = (schedulerCallback) &OsTaskfu_1ms;
        OsScheduler_initTask(&g_tasks_core0[OsScheduler_Task_1ms],&config);
}


void OsScheduler_initTask(osScheduler_task *handle,osScheduler_cfg_tasks *config)
{
	handle->taskcounter = config->taskoffset + config->taskreload;
	handle->taskreload = config->taskreload;
	handle->countinous = config->countinous;
	handle->callback = config->callback;
}



 void OsScheduler_tick(osScheduler_task *handle)
{
	uint32 i;
	for(i=0;i<OsScheduler_Task_count;i++)
	{
		if(handle->taskcounter)
		{

			handle->taskcounter--;
			if(handle->taskcounter == 0)
			{
				if(handle->countinous)
				{
					handle->taskcounter = handle->taskreload;
				}
				if(handle->run != FALSE)
				{
					handle->overflow++;
				}
				handle->run = TRUE;
			}
		}
		handle++;
	}
}



void OsScheduler_process(osScheduler_task *handle)
{

	if(handle->run != FALSE)
	{
		handle->run = FALSE;
		handle->callback();
	}

}

