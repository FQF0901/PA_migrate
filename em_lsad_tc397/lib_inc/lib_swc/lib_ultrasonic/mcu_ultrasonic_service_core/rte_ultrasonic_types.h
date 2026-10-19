/**
 * @file	rte_ultrasonic_types.h
 * @brief	This is a brief description of file rte_ultrasonic_types.h.
 * @details	This is the detail description.
 * 
 * @date	2022年8月26日 (created)
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

#ifndef ULTRASONIC_RTE_ULTRASONIC_TYPES_H_
#define ULTRASONIC_RTE_ULTRASONIC_TYPES_H_

/*	===========================================================================
 *								header files
 *	=========================================================================*/
#include "proj_global.h"
#include "ultrasonic_service_definition.h"
#if US_ON_SOC
#pragma pack(push, 4)
#else
#include "us_driver_elmos.h"
#endif

/*	===========================================================================
 *							macros & constants
 *	=========================================================================*/
#define USH_US_SW_VER_LENGTH				(100U)	//超声软件版本号字符串长度
#ifndef VEHI_TYPE_PC
#define VEHI_TYPE_PC                        (99U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_tPDC_AudioWarnLv
#define DEFINED_TYPEDEF_FOR_tPDC_AudioWarnLv
/** ***********************************
 * @brief    PDC audio warning level.
 *************************************/
typedef enum
{
	PDC_AUD_WARN_LV_NONE		= 0,	///< Warning tone level 0
	PDC_AUD_WARN_LV_LONG_BEEP	= 1,	///< Warning tone level 1
	PDC_AUD_WARN_LV_2			= 2,	///< Warning tone level 2
	PDC_AUD_WARN_LV_3			= 3,	///< Warning tone level 3
	PDC_AUD_WARN_LV_4			= 4,	///< Warning tone level 4
	PDC_AUD_WARN_LV_5			= 5,	///< Warning tone level 5
	PDC_AUD_WARN_LV_6			= 6,	///< Warning tone level 6
	PDC_AUD_WARN_LV_7			= 7,	///< Warning tone level 7
	PDC_AUD_WARN_LV_8			= 8,	///< Warning tone level 8
	PDC_AUD_WARN_LV_9			= 9,	///< Warning tone level 9
	PDC_AUD_WARN_LV_10			= 10,	///< Warning tone level 10
} tPDC_AudioWarnLv;
#endif

/** ***********************************
 * @brief	Ultrasonic System Software Version Information.
 *************************************/
typedef struct USH_UsSysVersion
{
	uint8 VersionInfo[USH_US_SW_VER_LENGTH];	/** software version string */
} tUSH_UsSysVersion;

/** ***********************************
 * @brief	Ultrasonic System Support Scenes
 *************************************/
typedef struct USH_UsSupportScenes
{
	tSupportSts UsSupportPdc;					/** Support PDC */
	tSupportSts UsSupportApaSearching;			/** Support LSAD_APA_STS_SEARCHING */
	tSupportSts UsSupportApaActive;				/** Support LSAD_APA_STS_ACTIVE */
} tUSH_UsSupportScenes;

/** ***********************************
 * @brief	超声服务负载偏移控制.
 *************************************/
typedef struct USH_ServLoadShifting
{
	uint8 u8LoadShiftRollingCnt;				/** 服务负载偏移激活计数 */
	uint8 u8LoadShiftTime_ms;					/** 服务负载偏移时间(ms) */
	uint8 reserved[2];
} tUSH_ServLoadShifting;

/** ***********************************
 * @brief	超声系统状态信息.
 *************************************/
typedef struct USH_UsSysInfo
{
	TimestampType u64Timestamp_us;
	tAPA_UltrasonicSts eUsSystemSts;			/** 超声系统工作状态反馈 */
	uint16 u16SensorFailureBitMask;				/** ultrasonic sensors failure bit mask, 0: not failure, 1: failure*/
	tUSH_UsSupportScenes UsSupportScenes;		/** 超声系统当前支持工况 */
	tUSH_UsSysVersion sUsSysVersion;			/** 超声软件版本号信息 */
	tVehi_VehiType eVehiType;					/** 超声适配车辆型号 */
	tUSH_ServLoadShifting sServLoadShifting;	/** 超声服务负载偏移控制 */
	uint8 reserved[1020];
} tUSH_UsSysInfo;

/*	===========================================================================
 *						global variable declarations
 *	=========================================================================*/

/*	===========================================================================
 *						global function declarations
 *	=========================================================================*/

#if US_ON_SOC
#pragma pack(pop)
#endif
#endif /* ULTRASONIC_RTE_ULTRASONIC_TYPES_H_ */
/******************************************************************************
 *									EOF
 *****************************************************************************/
