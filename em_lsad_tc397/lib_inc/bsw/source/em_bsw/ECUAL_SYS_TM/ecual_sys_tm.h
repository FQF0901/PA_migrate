/**
 * @file	ecual_sys_tm.h
 * @brief	This is a brief description of file ecual_sys_tm.h.
 * @details	This is the detail description.
 * 
 * @date	2020年11月26日 (created)
 * @version	0.0.1
 * @par Copyright (C):
 *			
 * @par Encoding:
 *			UTF-8
 * @par Description:
 *	1. Hardware Descriptions:
 *		None.
 *	2. Program Architecture:
 *		None.
 *	3. File Usage:
 *		None.
 *	4. Limitations:
 *		None.
 *	5. Else:
 *		None.
 * @par Modification:
 *	-# Date     : 2020.--.--;
 *	   Revision : 0.0.1;
 *	   
 *	   Contents : Co.
 */

#ifndef EM_ECUAL_ECUAL_SYS_TM_ECUAL_SYS_TM_H_
#define EM_ECUAL_ECUAL_SYS_TM_ECUAL_SYS_TM_H_

/*	===========================================================================
 *								header files
 *	=========================================================================*/
#include "Platform_Types.h"
#include "common.h"
/*	===========================================================================
 *							macros & constants
 *	=========================================================================*/

/*	===========================================================================
 *						data structure declarations
 *	=========================================================================*/
typedef sint64             Ifx_TickTime;    /**< \brief Time in ticks */


#define u16Year         year
#define u8Month         month
#define u8Day           day
#define u8Hour          hour
#define u8Minute        minute
#define u8Second        second
#define u16MilliSecond  msec
#define u16MicroSecond  usec

#define TIMER_COUNT       (11)                                      /**< \internal \brief number of timer values defined */
#define TIMER_INDEX_10NS  (0)                                       /**< \internal \brief Index of the time value 10ns*/
#define TIMER_INDEX_100NS (1)                                       /**< \internal \brief Index of the time value 100ns*/
#define TIMER_INDEX_1US   (2)                                       /**< \internal \brief Index of the time value 1us*/
#define TIMER_INDEX_10US  (3)                                       /**< \internal \brief Index of the time value 10us*/
#define TIMER_INDEX_100US (4)                                       /**< \internal \brief Index of the time value 100us*/
#define TIMER_INDEX_1MS   (5)                                       /**< \internal \brief Index of the time value 1ms*/
#define TIMER_INDEX_10MS  (6)                                       /**< \internal \brief Index of the time value 10ms*/
#define TIMER_INDEX_100MS (7)                                       /**< \internal \brief Index of the time value 100ms*/
#define TIMER_INDEX_1S    (8)                                       /**< \internal \brief Index of the time value 1s*/
#define TIMER_INDEX_10S   (9)                                       /**< \internal \brief Index of the time value 10s*/
#define TIMER_INDEX_100S  (10)                                      /**< \internal \brief Index of the time value 100s*/

extern sint64 TimeConst[TIMER_COUNT];

#define TimeConst_0s    ((Ifx_TickTime)0)                           /**< \brief time constant equal to 1s */
#define TimeConst_10ns  (TimeConst[TIMER_INDEX_10NS])               /**< \brief time constant equal to 10ns */
#define TimeConst_100ns (TimeConst[TIMER_INDEX_100NS])              /**< \brief time constant equal to 100ns */
#define TimeConst_1us   (TimeConst[TIMER_INDEX_1US])                /**< \brief time constant equal to 1us */
#define TimeConst_10us  (TimeConst[TIMER_INDEX_10US])               /**< \brief time constant equal to 10us */
#define TimeConst_100us (TimeConst[TIMER_INDEX_100US])              /**< \brief time constant equal to 100us */
#define TimeConst_1ms   (TimeConst[TIMER_INDEX_1MS])                /**< \brief time constant equal to 1ms */
#define TimeConst_10ms  (TimeConst[TIMER_INDEX_10MS])               /**< \brief time constant equal to 10ms */
#define TimeConst_100ms (TimeConst[TIMER_INDEX_100MS])              /**< \brief time constant equal to 100ms */
#define TimeConst_1s    (TimeConst[TIMER_INDEX_1S])                 /**< \brief time constant equal to 1s */
#define TimeConst_10s   (TimeConst[TIMER_INDEX_10S])                /**< \brief time constant equal to 10s */
#define TimeConst_100s  (TimeConst[TIMER_INDEX_100S])               /**< \brief time constant equal to 100s */

#define TIME_INFINITE ((Ifx_TickTime)0x7FFFFFFFFFFFFFFFLL)
//#pragma pack(push, 1)
#ifndef _SYSTEMCALENDAR_
#define _SYSTEMCALENDAR_
typedef struct
{
    uint16  year;       ///year
    uint16  month;      ///month,1-12
    uint16  day;        ///day,1-31
    uint16  hour;       ///hour,0-24
    uint16  minute;     ///min,0-59
    uint16  second;     ///sec,0-59
    uint16  msec;       ///msec,0-999
    uint16  usec;       ///usec,0-999

    uint64  u64UnixTimes;       ///seconds since UTC_BASE_YEAR
    uint64  u64UnixTimes_us;    ///usec since UTC_BASE_YEAR
    uint64  u64PowOnTimes_us;   ///usec since last power on

}st_SystemCalendar, *pst_SystemCalendar;
#endif
//#pragma pack(pop)
/*	===========================================================================
 *						global variable declarations
 *	=========================================================================*/

/*	===========================================================================
 *						global function declarations
 *	=========================================================================*/
extern void initTime(void);
extern void SysTm_SetDefaultCalendar(void);

/** ***************************************************************************
 * @brief		设置系统日历（YMDHMS）.
 * @details		This is a detail description of foo.
 *****************************************************************************/
extern void SysTm_SetSystemCalendar(st_SystemCalendar SystemCalendar, boolean isSave);

/** ***************************************************************************
 * @brief		获取系统日历（YMDHMS）.
 * @details		This is a detail description of foo.
 * @return		系统日历（YMDHMS）: 		-.
 *****************************************************************************/
extern st_SystemCalendar SysTm_GetSystemCalendar(void);

/** ***************************************************************************
 * @brief		获取上电后开始计时的时间戳.
 * @details		This is a detail description of foo.
 * @return		Timestamp (usec): 		-.
 *****************************************************************************/
extern TimestampType SysTm_GetPowOnTimestamp_us(void);
extern TimestampType SysTm_GetPowOnTimestamp_ns(void);

/** ***************************************************************************
 * @brief		获取Unix时间戳.
 * @details		UNIX时间戳的0按照ISO 8601规范为 ：1970-01-01T00:00:00Z.
 * @return		Unix Timestamp (usec).
 *****************************************************************************/
extern TimestampType SysTm_GetUnixTimestamp_us(void);
extern TimestampType SysTm_GetUnixTimestamp_ns(void);

/** ***************************************************************************
 * @brief       设置Unix时间戳.
 * @parameter   unixTime (second)
 * @details     This is a detail description of foo.
 *****************************************************************************/
extern void SysTm_SetUnixTimestamp(TimestampType unixTime);


#endif /* EM_ECUAL_ECUAL_SYS_TM_ECUAL_SYS_TM_H_ */
/******************************************************************************
 *									EOF
 *****************************************************************************/
