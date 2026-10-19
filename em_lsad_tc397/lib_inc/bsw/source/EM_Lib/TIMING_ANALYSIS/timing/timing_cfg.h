/*
 * timing_cfg.h
 *
 *  Created on: 2022年12月13日
 *      
 */

#ifndef TIMING_CFG_H__
#define TIMING_CFG_H__

/*  ===========================================================================
 *                              header files
 *  =========================================================================*/
#include "proj_global.h"

/*  ===========================================================================
 *                              constants
 *  =========================================================================*/
#define TIMING_CPU_NUMBER       (6)

#define TIMING_ID_TYPE_INIT     (0)
#define TIMING_ID_TYPE_START    (1)
#define TIMING_ID_TYPE_STOP     (2)

#define TIMING_STEP_VALUE       (0x01000000U)

/*  ===========================================================================
 *                              macros
 *  =========================================================================*/
#if (defined(TIMING_FUNC_ENABLE) && (TIMING_FUNC_ENABLE == 1))

#define TASK_ID_CREAT()                                         \
    static uint16 tTaskID = 0;                                  \
    if(tTaskID == 0)                                            \
    {                                                           \
        tTaskID = GetTaskIdFromName(__func__);                  \
    }

#define TASK_TIMING_START()         TimingCapture(1, (tTaskID))
#define TASK_TIMING_STOP()          TimingCapture(2, (tTaskID))

#define SPEC_TASK_ID_CREAT(func)                                \
    static uint16 tTaskID = 0;                                  \
    if(tTaskID == 0)                                            \
    {                                                           \
        tTaskID = GetTaskIdFromName(#func);                     \
    }

#define SPEC_TASK_TIMING_START(id)  TimingCapture(TIMING_ID_TYPE_START, (id))
#define SPEC_TASK_TIMING_STOP(id)   TimingCapture(TIMING_ID_TYPE_STOP, (id))
#else

#define TASK_ID_CREAT()
#define TASK_TIMING_START()
#define TASK_TIMING_STOP()
#define SPEC_TASK_TIMING_START(id)
#define SPEC_TASK_TIMING_STOP(id)

#endif // #ifndef TASK_ID_CREAT
/*  ===========================================================================
 *                      data structure declarations
 *  =========================================================================*/

/*  ===========================================================================
 *                      global variable declarations
 *  =========================================================================*/

/*  ===========================================================================
 *                      global function declarations
 *  =========================================================================*/
extern uint16 GetTaskIdFromU32(uint32 funcHandle);
extern uint16 GetTaskIdFromName(const char *funcName);
extern void   TimingCapture(uint16 timeid, uint16 taskid);

extern void TimingBuffer_Init(uint8 *fifoBuffer, uint32 fifoBufferSize, uint8* sendBuffer, uint32 sendBufferSize);

extern void TimingRecord_Process(void);
extern void TimingComm_RecvCallback(uint8 *rxBuf, uint32 bufLen);

/*  ===========================================================================
 *                      interface function declarations
 *  =========================================================================*/
// call by TimingRecord_Process() task, transmit the timing data.
extern void TimingComm_Send(uint8 *txBuf, uint32 bufLen);

// call by TimingCapture(), get the current timestamp in us.
extern uint32 Timing_Timestamp_us(void);

// call by TimingCapture(), get the current cpu core index.
extern uint32 Timing_Cpu_Index(void);

// call by Timing_xxx lib function, to show the debug log
extern void Timing_Printf(const char *format, ...);

#endif /* TIMING_CFG_H__ */
