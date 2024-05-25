/*
 * OsTimerOS.h
 *
 *  Created on: 06.12.2023
 *
 */

#ifndef __OS_TIMEROS_H_
#define __OS_TIMEROS_H_
#define K_TIMER_1MS_COUNT    (0)
#define K_TIMER_5MS_COUNT    (4)
#define K_TIMER_10MS_COUNT   (9)
#define K_TIMER_100MS_COUNT  (99)
#define K_TIMER_200MS_COUNT  (199)
#define K_TIMER_300MS_COUNT   (301)

extern uint32_t timer1ms_counter;
extern uint32_t timer5ms_counter;
extern uint32_t timer10ms_counter;
extern uint32_t timer100ms_counter;
extern uint32_t timer200ms_counter;
extern uint32_t timer300ms_counter;
void OsTimerTick_Init(void);

extern void OsTimerTick_1msIsr(void);
#endif /* __OS_TIMEROS_H_ */
