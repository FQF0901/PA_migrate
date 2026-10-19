/******************************************************************************
 * @file    log_print.h
 * @brief   print level entrance
 * @details This is the detail description.
 * 
 * @date    2022.9.2 (created)
 * @version 0.0.1
 * @par Copyright (C):
 *          Shanghai Enjoy Move Technology CO.,LTD. All Rights Reserved.
 * @par Encoding:
 *          UTF-8
 * @remarks
 *

 *****************************************************************************/

#ifndef __LOG_PRINTF_H__
#define __LOG_PRINTF_H__
/*  ===========================================================================
 *                              header files
 *  =========================================================================*/

#include "proj_global.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OPEN_LOG_PRINT
#ifdef OPEN_LOG_PRINT
#define MAX_LOG_PRINT_SIZE 256


typedef union
{
    struct Log_Module
    {
        uint32 reserve_32		:15;
        uint8 UsRecord          :1;
        uint8 Shell             :1;
        uint8 DIAG_SERVICE      :1;
        uint8 LOG               :1;
        uint8 XCP			    :1;
        uint8 DEBUG			    :1;
        uint8 UsDiag		    :1;
        uint8 DTC			    :1;
        uint8 USD			    :1;
        uint8 UPLD			    :1;
        uint8 WJ			    :1;
        uint8 HDSK			    :1;
        uint8 ETH			    :1;
        uint8 P_ADAS			:1;
        uint8 PF			    :1;
        uint8 USH			    :1;
        uint8 SYS			    :1;
    } s_Log_Module;
    uint32 log_module;

} Log_Module_T;
extern Log_Module_T log_module_t;

extern void log_print(uint32 local_module, const char* file, uint32 line, const char* format, ...);

#ifdef __cplusplus
}
#endif

#endif /* __LOG_PRINTF_H__ */

#endif
/***************************************************************************
 *  END OF FILE: log_print.h
 **************************************************************************/
