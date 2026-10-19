
#ifndef TIMING_ANALYSE_H__
#define TIMING_ANALYSE_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "Std_Types.h"

//#include "timing_cfg.h"
#include "timing_record.h"

#define TASK_INIT_TIMING	0

typedef struct TimingValue
{
	uint32 maxinum;
	uint32 mininum;
	float  average; 	// = (avg * n + last)/(n+1) = avg + (last - avg)/(n+1)
	uint32 n;
	
}TimingValue;

typedef struct TimingAnalysis
{
//	TimingData  TaskTiming;			// the Task Id information, and save the new TimingData
	TimingData  LastTiming;			// the Task Id information, and save the last TimingData

#if (defined(TASK_INIT_TIMING) && (TASK_INIT_TIMING == 1))
	uint64	LastInitTime;		// the last Task Initial begin time, init
	uint64  LastStopTime;       // the last Task Stop time, out
#endif
	uint64	LastStartTime;		// the last Task Start time, in

//#if (defined(TASK_INIT_TIMING) && (TASK_INIT_TIMING == 1))
//	uint32	MissInitCounter;	// the miss's counter of Initial Timing
//#endif
	uint32	MissStartCounter;	// the miss's counter of Start Timing
	uint32	MissStopCounter;	// the miss's counter of Stop Timing

	TimingValue GrossExecutionTime;	// in-out
	TimingValue DeltaTime; 			// in-in
#if (defined(TASK_INIT_TIMING) && (TASK_INIT_TIMING == 1))
	TimingValue Period;				// init-init
	TimingValue InitialPendingTime; // init-in
	TimingValue ResponseTime;		// init-out
#endif

	struct TimingAnalysis *next;	// next task id analysis
	
}TimingAnalysis;

extern void TimingAnalyse_Init(void);
extern void TimingAnalyse_Process(uint8 *pBuf, uint32 bufLen);
extern void TimingAnalyse_ShowInformation(void);

#ifdef __cplusplus
}
#endif

#endif /* TIMING_ANALYSE_H__ */

