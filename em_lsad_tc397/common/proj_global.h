/** ***************************************************************************
 * @file    proj_global.h
 * @brief    This is a brief description of file proj_global.h.
 * @details    This is the detail description.
 * 
 * @date    2020-9-9 (created)
 * @version    0.0.1
 * @par Copyright (C):
 *            Shanghai Enjoy Move Technology CO.,LTD. All Rights Reserved.
 * @par Encoding:
 *            UTF-8
 * @par Description:
 *    1. Hardware Descriptions:
 *        None.
 *    2. Program Architecture:
 *        None.
 *    3. File Usage:
 *        None.
 *    4. Limitations:
 *        None.
 *    5. Else:
 *        None.
 * @par Modification:
 *    -# Date     : 2020.--.--;
 *       Revision : 0.0.1;
 *       
 *       Contents : Co.
 *****************************************************************************/

#ifndef H_PROJ_GLOBAL_H_
#define H_PROJ_GLOBAL_H_

#include <stdio.h>
#include <string.h>
#include <math.h>

#include "proj_config.h"
#if ((EM_PROJECT_ID == EM_61000017_APA) || (EM_PROJECT_ID == EM_61000075_HPA))
#include "Std_Types.h"
#include "common.h"
// #include "ecual_sys_tm.h"
#endif /* ((EM_PROJECT_ID == EM_61000017_APA) || (EM_PROJECT_ID == EM_61000075_HPA)) */

/********************************* DEBUG *************************************/
#define RUNNABLE_TIME_SMOOTH            0           /* useless function delay */
#define SHOW_ETH_INFO                   0           /* 0-disable, !0-show eth info period in ms */
#define TIMING_FUNC_ENABLE              1           /* 0-disable, 1-enable Timing Trace function */
#define SYS_UART_SHELL                  1           /* shell */
#define ETH_LWIP_USED                   1           /* enable lwip */
#define US_ON_SOC                       0
#define FOTA_UPDATE                     1           /* fota */
#define DEBUG_ASSERT                    1           /* */

#define USE_READ_TEMP                   0
#define USE_READ_TEMP_DIAG              1
#define READ_TEMP_SWITCH                USE_READ_TEMP_DIAG

#define XCP_ON_CAN                      1           /* xcp on can */
#define XCP_ON_ETH                      2           /* xcp on tcp */
#define XCP_TYPE                        XCP_ON_ETH

/******************************** SWITCH FOR PRINT ************************************/
#define SWITCH_PRINTF_SYS               1
#define SWITCH_PRINTF_USH               0
#define SWITCH_PRINTF_PF                0
#define SWITCH_PRINTF_ADAS              0
#define SWITCH_PRINTF_ETH               0
#define SWITCH_PRINTF_HDSK              0
#define SWITCH_PRINTF_WJ                1
#define SWITCH_PRINTF_UPLD              0
#define SWITCH_PRINTF_USD               0
#define SWITCH_PRINTF_DTC               0
#define SWITCH_PRINTF_UsDiag            1
#define SWITCH_PRINTF_DEBUG             0
#define SWITCH_PRINTF_XCP               0
#define SWITCH_PRINTF_LOG               1
#define SWITCH_PRINTF_DIAG_SERVICE      0
#define SWITCH_PRINTF_Shell             0
#define SWITCH_PRINTF_UsRecord          1

#define BUILD_YEAR     ((((__DATE__ [7] - '0') * 10 + (__DATE__ [8] - '0')) * 10 \
                                    + (__DATE__ [9] - '0')) * 10 + (__DATE__ [10] - '0'))

extern TimestampType SysTm_GetPowOnTimestamp_us(void);
extern TimestampType SysTm_GetUnixTimestamp_us(void);
#endif /* H_PROJ_GLOBAL_H_ */
/******************************************************************************
 *                                    EOF
 *****************************************************************************/
