/*
 * timing_spinlock.h
 *
 *  Created on: 2022年12月13日
 *      
 */

#ifndef TIMING_SPINLOCK_H__
#define TIMING_SPINLOCK_H__

/*  ===========================================================================
 *                              header files
 *  =========================================================================*/
#include "timing_cfg.h"
#include "Std_Types.h"

/*  ===========================================================================
 *                              constants
 *  =========================================================================*/
#define TIMING_MULTICORE_SPINLOCK_USED      1

/*  ===========================================================================
 *                              macros
 *  =========================================================================*/
#define DYSNC()     //__dsync(); __isync()
#define NNOP()      __nop()
#define NOPX(x)     for(int i=0; i<(x); i++) {__nop();}

/*  ===========================================================================
 *                      data structure declarations
 *  =========================================================================*/
#if (defined(TIMING_MULTICORE_SPINLOCK_USED) && (TIMING_MULTICORE_SPINLOCK_USED == 1))
// #include "MultiCoreSpinLock.h"

// typedef EmSpinLockType TimingSpinlock;

#define Timing_DefineSpinLock(lock)     (void)0//EmSpinLockType lock;
#define Timing_CheckSpinLock(lock)      //EmCpuCheckSpinLock( (EmSpinLockType *)(lock) )
#define Timing_CreatSpinLock(lock)      //EmCpuInitSpinLock( (EmSpinLockType *)(lock) )
//#define Timing_SetSpinLock(lock)        EmCpuGetSpinLock( (EmSpinLockType *)(lock), 1 )
//#define Timing_ReleaseSpinLock(lock)    EmCpuReleaseSpinLock( (EmSpinLockType *)(lock) )
// #define Timing_SetSpinLock(lock)        EmCpuGetSpinLockFromISR( (EmSpinLockType *)(lock), 1 )
// #define Timing_ReleaseSpinLock(lock)    EmCpuReleaseSpinLockFromISR( (EmSpinLockType *)(lock) )

#define Timing_SetSpinLock(lock)        GetSpinlock(lock)
#define Timing_ReleaseSpinLock(lock)    ReleaseSpinlock(lock)

#define Timing_IsrSetSpinLock(lock)     //EmCpuGetSpinLockFromISR( (EmSpinLockType *)(lock), 1 )
#define Timing_IsrReleaseSpinLock(lock) //EmCpuReleaseSpinLockFromISR( (EmSpinLockType *)(lock) )

#else

typedef struct _TimingSpinlock
{
    unsigned int spinlock[TIMING_CPU_NUMBER];
    boolean irq_status[TIMING_CPU_NUMBER];
}TimingSpinlock;

#endif // #if (defined(TIMING_MULTICORE_SPINLOCK_USED) && (TIMING_MULTICORE_SPINLOCK_USED == 1))

/*  ===========================================================================
 *                      global variable declarations
 *  =========================================================================*/

/*  ===========================================================================
 *                      global function declarations
 *  =========================================================================*/
#if !(defined(TIMING_MULTICORE_SPINLOCK_USED) && (TIMING_MULTICORE_SPINLOCK_USED == 1))

#define Timing_DefineSpinLock(lock)     TimingSpinlock lock = {0};
#define Timing_CheckSpinLock(lock)      (1)
#define Timing_CreatSpinLock(lock)

#define Timing_IsrSetSpinLock(lock)     Timing_SetSpinLock(lock)
#define Timing_IsrReleaseSpinLock(lock) Timing_ReleaseSpinLock(lock)

extern boolean Timing_SetSpinLock(TimingSpinlock *xlock);
extern void    Timing_ReleaseSpinLock(TimingSpinlock *xlock);

#endif // #if (defined(TIMING_MULTICORE_SPINLOCK_USED) && (TIMING_MULTICORE_SPINLOCK_USED == 1))

#endif /* TIMING_SPINLOCK_H__ */
