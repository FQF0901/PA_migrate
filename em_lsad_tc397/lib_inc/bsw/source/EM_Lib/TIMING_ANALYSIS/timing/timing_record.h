/*
 * timing_record.h
 *
 *  Created on: 2022年12月13日
 *      
 */

#ifndef TIMING_RECORD_H__
#define TIMING_RECORD_H__

/*  ===========================================================================
 *                              header files
 *  =========================================================================*/
#include "Std_Types.h"

/*  ===========================================================================
 *                              constants
 *  =========================================================================*/

/*  ===========================================================================
 *                              macros
 *  =========================================================================*/
#define TIMING_PRINT_ENABLE     1

#if (defined(TIMING_PRINT_ENABLE) && (TIMING_PRINT_ENABLE >= 1))
//#define TIMING_REC_PRINT(...)           Timing_Printf(__VA_ARGS__);
// #include "uart_printf.h"
#define TIMING_ANL_PRINT(...)           //(void)uart_printf(__VA_ARGS__);
#define TIMING_ANL_PRINT_HEX(buf,len)   //(void)uart_printf_hexbuffer((char *)buf, (int)(len), 1);
#else
#define TIMING_ANL_PRINT(...)
#define TIMING_ANL_PRINT_HEX(buf,len)
#endif

#if (defined(TIMING_PRINT_ENABLE) && (TIMING_PRINT_ENABLE >= 2))
//#define TIMING_REC_PRINT(...)           Timing_Printf(__VA_ARGS__);
#include "uart_printf.h"
#define TIMING_REC_PRINT(...)           (void)uart_printf(__VA_ARGS__);
#define TIMING_REC_PRINT_HEX(buf,len)   (void)uart_printf_hexbuffer((char *)buf, (int)(len), 1);
#else
#define TIMING_REC_PRINT(...)
#define TIMING_REC_PRINT_HEX(buf,len)
#endif

/*  ===========================================================================
 *                      data structure declarations
 *  =========================================================================*/
typedef struct TimingData_BITS
{
    uint32  flag    :2;     // data flag: 2
    uint32  core_id :4;     // cpu index: 0~15
    uint32  time_id :2;     // timing type: 0-task start, 1-execution start, 2-execution stop
    uint32  timing  :24;    // timing value: low 24bit of timestamp, us
    uint16  task_id;        // task id: 1~65535
}TimingData_BITS;

#define TIMING_DATA_SIZE    6 //(sizeof(TimingData_BITS))

typedef union TimingData
{
    TimingData_BITS B;
    uint8 buf[TIMING_DATA_SIZE];
}TimingData;

/*  ===========================================================================
 *                      global variable declarations
 *  =========================================================================*/

/*  ===========================================================================
 *                      global function declarations
 *  =========================================================================*/
extern uint32 TimingRecord_Number(void);
extern void   TimingRecord_Save(TimingData timing);
extern uint32 TimingRecord_Read(TimingData *timing);
extern uint32 TimingRecord_Check(TimingData *timing);
extern void*  TimingRecord_Malloc(uint32 size);
extern uint32 TimingRecord_ReadToBuffer(uint8 *pBuf, uint32 number, uint32 minNumber);
extern void   TimingRecord_Process(void);
extern void   TimingRecord_Explanation(uint8 *pData, uint32 len);

#endif /* TIMING_RECORD_H__ */
