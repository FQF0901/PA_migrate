/**
 * @file    common.h
 * @brief   This is a brief description of file common.h.
 * @details This is the detail description.
 * 
 * @date    2021-10-13 (created)
 * @version 0.0.1
 * @par Copyright (C):
 *          
 * @par Encoding:
 *          UTF-8
 * @par Description:
 *  1. Hardware Descriptions:
 *      None.
 *  2. Program Architecture:
 *      None.
 *  3. File Usage:
 *      None.
 *  4. Limitations:
 *      None.
 *  5. Else:
 *      None.
 * @par Modification:
 *  -# Date     : 2020.--.--;
 *     Revision : 0.0.1;
 *     
 *     Contents : Co.
 */

#ifndef __COMMON_H__
#define __COMMON_H__

/*  ===========================================================================
 *                              header files
 *  =========================================================================*/
#if (EM_SW_PLATFORM == PLT_FREERTOS)
//#include "os_common.h"
#endif /* (EM_SW_PLATFORM == PLT_FREERTOS) */
#if ((EM_PROJECT_ID == EM_61000017_APA) || (EM_PROJECT_ID == EM_61000075_HPA))
// #include "log_print.h"
//#include "uart_printf.h"
#endif /* ((EM_PROJECT_ID == EM_61000017_APA) || (EM_PROJECT_ID == EM_61000075_HPA)) */
/*  ===========================================================================
 *                          macros & constants
 *  =========================================================================*/
#define MIN(x,y)                ( (x) < (y) ? (x) : (y) )
#define MAX(x,y)                ( (x) > (y) ? (x) : (y) )
#define ABS(x)                  ( (x) > (0) ? (x) :-(x) )
#define DIF_ABS(x,y)            ((x) > (y) ? ((x)-(y)) :((y) - (x)))
#define SIZE_ALIGN(size, algin) ( ((size)+(algin)-1) & ~((algin)-1) )
#define SIZE_ROUND(size, round) ( (size)-((round)?((size)%(round)):(0)) )
#define BITS(v,b)               ((uint32)(v) << (b))
#define BIT(b)                  BITS(1u,b)
#define NAME2STR(name)          #name
#define VAL2STR(val)            NAME2STR(val)
#define PRINTFORMAT(len,spec)   __PRNFORMAT3(len,spec)
#define __PRNFORMAT3(mod,spec)  __PRNFORMAT4(mod##spec)
#define __PRNFORMAT4(format)    #format
#define STR_NULL                ((const char *)"")
#define STR_UNDEFINED           ((const char *)"UN-DEFINED")
#define COMM_TIMEOUT_INFINIT    (0xFFFFFFFFUL)
#define COMM_IS_TIMEOUT(c)      ((c.timeOut!=COMM_TIMEOUT_INFINIT) && (c.intervalTime > c.timeOut))
#define NOPNOP()                __nop()
#define SYNC_SYNC()             __dsync()   /* __isync() */

#if DEBUG_ASSERT == 1
#define ASSERT(x)               IFX_ASSERT(IFX_VERBOSE_LEVEL_WARNING, x)
#define ASSERT_PARM(expr, ...)  (expr) ? ((void)0) : (void)uart_printf("<ASSERTION> = %d,'%s',%s:%u,func:%s().\r\n", (int)__VA_ARGS__, #expr, __FILE__, __LINE__, __func__)
#else
#define ASSERT(x)               ((void)0)
#define ASSERT_PARM(expr, ...)  ((void)0)
#endif

#define PI                      (3.14159265358979323846f)
#define MATH_DEG2RAD(x)         ((x) * (PI / 180.0f)) /* Angle to Radian */
#define MATH_RAD2DEG(x)         ((x) * (180.0f / PI)) /* Radian to Angle */

#if ((EM_PROJECT_ID == EM_61000017_APA) || (EM_PROJECT_ID == EM_61000075_HPA))
#define TASK_RUN_INFO()         //uart_printf("PowerON %6llu us: {Cpu%d.Task} %s()\r\n", SysTm_GetPowOnTimestamp_us(), CPU_ID, __func__);
#define FUNC_RUN_INFO()         uart_printf("FILE %s LINE %d of %s() on {Cpu%d}\r\n", __FILE__, __LINE__, __func__, CPU_ID);
#define FUNC_RUN_HEART(x)       if(((x)%1000) == 0) { uart_printf("%6llu >> %s(): heart =%lu\r\n", SysTm_GetPowOnTimestamp_us(), __func__, (x)); }
#define LOG_TIME_STR            "[%02d %02d:%02d:%02d.%03d] %s"
#define LOG_TIME_VAR            tm.day, tm.hour, tm.minute, tm.second, tm.msec, __func__

extern void log_print(uint32 local_module, const char* file, uint32 line, const char* format, ...);
#define PRINTF_SYS(...)             (void)log_print(0x80000000, __func__, __LINE__, __VA_ARGS__)
#define PRINTF_USH(...)             (void)log_print(0x40000000, __func__, __LINE__, __VA_ARGS__)
#define PRINTF_PF(...)              (void)log_print(0x20000000, __func__, __LINE__, __VA_ARGS__)
#define PRINTF_ADAS(...)            (void)log_print(0x10000000, __func__, __LINE__, __VA_ARGS__)
#define PRINTF_ETH(...)             (void)log_print(0x08000000, __func__, __LINE__, __VA_ARGS__)
#define PRINTF_HDSK(...)            (void)log_print(0x04000000, __func__, __LINE__, __VA_ARGS__)
#define PRINTF_WJ(...)              (void)log_print(0x02000000, __func__, __LINE__, __VA_ARGS__)
#define PRINTF_UPLD(...)            (void)log_print(0x01000000, __func__, __LINE__, __VA_ARGS__)
#define PRINTF_USD(...)             (void)log_print(0x00800000, __func__, __LINE__, __VA_ARGS__)
#define PRINTF_DTC(...)             (void)log_print(0x00400000, __func__, __LINE__, __VA_ARGS__)
#define PRINTF_UsDiag(...)          (void)log_print(0x00200000, __func__, __LINE__, __VA_ARGS__)
#define PRINTF_DEBUG(...)           (void)log_print(0x00100000, __func__, __LINE__, __VA_ARGS__)
#define PRINTF_XCP(...)             (void)log_print(0x00080000, __func__, __LINE__, __VA_ARGS__)
#define PRINTF_LOG(...)             (void)log_print(0x00040000, __func__, __LINE__, __VA_ARGS__)
#define PRINTF_DIAG_SERVICE(...)    (void)log_print(0x00020000, __func__, __LINE__, __VA_ARGS__)
#define PRINTF_Shell(...)           (void)log_print(0x00010000, __func__, __LINE__, __VA_ARGS__)
#define PRINTF_UsRecord(...)        (void)log_print(0x00008000, __func__, __LINE__, __VA_ARGS__)


#define E_TIMEOUT                   (0x02u)     /** Timeout error */
#define E_ALIGN                     (0x04u)     /** Alignment error */
#define E_INVAL                     (0x08u)     /** parameter error */
#define E_BUSY                      (0x10u)     /** Busy */
#define E_NO_DATA                   (0x20u)     /** No data available */
#define E_NOT_SUPPORT               (0x40u)     /** not supported   */
#define E_CRC_FAILURE               (0x80u)     /** CRC check fails */
#define E_HARDWARE_FAILURE          (0x80u)     /** Hardware error */
#define E_NOT_FOUND                 (0x80u)     /** Not found */
#define E_LIMIT                     (0x80u)     /** times/other conditions */

typedef uint64 TimestampType;

#endif /* ((EM_PROJECT_ID == EM_61000017_APA) || (EM_PROJECT_ID == EM_61000075_HPA)) */
#endif /* __COMMON_H__ */
/******************************************************************************
 *                                  EOF
 *****************************************************************************/
