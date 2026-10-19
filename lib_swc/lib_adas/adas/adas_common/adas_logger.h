#ifndef ADAS_LOGGER_H_
#define ADAS_LOGGER_H_

#include "adas_project_input.h"

//#define __DEBUG    //日志模块总开关，注释掉将关闭日志输出

//定义日志级别
enum LOG_LEVEL {
    LOG_LEVEL_OFF=0,
    LOG_LEVEL_FATAL,
    LOG_LEVEL_ERR,
    LOG_LEVEL_WARN,
    LOG_LEVEL_INFO,
    LOG_LEVEL_ALL
};


#ifdef __DEBUG
#define ADAS_LOG(level, ...) \
    do { \
        if(level>=LOG_LEVEL_ALL)\
            {Ifx_Console_print("[D]");Ifx_Console_print(__VA_ARGS__);(void)Ifx_Console_print("\r\n");}\
        else if(level>=LOG_LEVEL_INFO)\
            {Ifx_Console_print("[I]");Ifx_Console_print(__VA_ARGS__);(void)Ifx_Console_print("\r\n");}\
        else if(level>=LOG_LEVEL_WARN)\
            {Ifx_Console_print("[W]");Ifx_Console_print(__VA_ARGS__);(void)Ifx_Console_print("\r\n");}\
        else if(level>=LOG_LEVEL_ERR)\
            {Ifx_Console_print("[E]");Ifx_Console_print(__VA_ARGS__);(void)Ifx_Console_print("\r\n");}\
        else if(level>=LOG_LEVEL_FATAL)\
            {Ifx_Console_print("[FATAL]");Ifx_Console_print(__VA_ARGS__);(void)Ifx_Console_print("\r\n");}\
        else \
            {;}\
    } while (0)
#else
    #define ADAS_LOG(level, ...)
#endif


#endif /* ADAS_LOGGER_H_ */


