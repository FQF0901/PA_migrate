/*
 * version.c
 *
 *  Created on: 2022-3-4
 *      
 */

#include "version.h"
//#include "version_timing.h"
#include "proj_global.h"
#include "emos_rte.h"
#include "ecual_sys_tm.h"

#define BSW_START_SEC_VAR
#include "proj_MemMap.h"

// extern const stVersionInfo cVerLib_bsw;
//extern const stVersionInfo cVerLib_bsw_base;
//extern const stVersionInfo cVerLib_bsw_emsync;
//extern const stVersionInfo cVerLib_bsw_service;
//extern const stVersionInfo cVerLib_bsw_task;
//extern const stVersionInfo cVerLib_bsw_usdriver;
// extern const stVersionInfo cVerLib_rte;
// extern const stVersionInfo cVerLib_vehmsg;
// extern const stVersionInfo cVerLib_swc_adas;
// extern const stVersionInfo cVerLib_swc_ultrasonic;

extern int MsgMnger_MCU2SOC_EcuInfo(void *pData);

//#define COLOR_MODULE    "\033[1m\033[5m\033[7m" // 楂樹寒搴︺�侀棯鐑併�佸弽鏄�
#define COLOR_MODULE    "\033[1m\033[7m"    // 楂樹寒搴︺�佸弽鏄�
#define COLOR_VERSION   //"\033[43m\033[5m"   // 闂儊
#define COLOR_RESTORE   "\033[0m"           // 鍏抽棴

const uint8_t g_u8HardwareMajorVersion = 4;
const uint8_t g_u8HardwareMinorVersion = 0;
const uint8_t g_u8HardwarePatchVersion = 5;

int MsgMnger_MCU2SOC_EcuInfo(void *pData)
{
    tMsgMnger_EcuInfo *pStData = (tMsgMnger_EcuInfo *)pData;
    pStData->u64PowOnTimestamp_us       = SysTm_GetPowOnTimestamp_us();
    pStData->u64UnixTimestamp_us        = SysTm_GetUnixTimestamp_us();
    pStData->eHardwareType              = ECU_TYPE_TC397;
    pStData->u8HardwareMajorVersion     = 0;
    pStData->u8HardwareMinorVersion     = 0;
    pStData->u8HardwarePatchVersion     = 0;
    pStData->u8SoftwareMajorVersion     = g_u8HardwareMajorVersion;
    pStData->u8SoftwareMinorVersion     = g_u8HardwareMinorVersion;
    pStData->u8SoftwarePatchVersion     = g_u8HardwarePatchVersion;
    pStData->u16JenkinsBuildNum         = EM_JENKINS_BUILD_NUM;
    pStData->eSelfcheckSts              = SELFCHECK_FINISHED;
    return 0;
}

// const stVersionInfo cVerElf =
// {
//     .index   = VER_ELF,
//     .name    = "elf tc397",
//     .version = "03.01.09",
//     .rebuild = ""__DATE__", "__TIME__,
// };

//const stVersionInfo cVerLib_bsw =
//{
//    .index   = VER_LIB_bsw,
//    .name    = "lib bsw",
//    .version = "?.?.?",
//    .rebuild = ""__DATE__", "__TIME__,
//};

// const stVersionInfo cVerLib_rte =
// {
//     .index   = VER_LIB_rte,
//     .name    = "lib rte",
//     .version = "??.??.??",
//     .rebuild = ""__DATE__", "__TIME__,
// };

// const stVersionInfo cVerLib_vehmsg =
// {
//     .index   = VER_LIB_vehmsg,
//     .name    = "lib wehmsg",
//     .version = "??.??.??",
//     .rebuild = ""__DATE__", "__TIME__,
// };

// const stVersionInfo cVerLib_swc_adas =
// {
//     .index   = VER_LIB_swc_adas,
//     .name    = "lib adas",
//     .version = "??.??.??",
//     .rebuild = ""__DATE__", "__TIME__,
// };

// const stVersionInfo cVerLib_swc_ultrasonic =
// {
//     .index   = VER_LIB_swc_ultrasonic,
//     .name    = "lib ultrasonic",
//     .version = "??.??.??",
//     .rebuild = ""__DATE__", "__TIME__,
// };

// const stVersionInfo cVerLib_timing =
// {
//     .index   = VER_LIB_timing,
//     .name    = "lib timing",
//     .version = VER_TIMING,
//     .rebuild = VER_TIMING_REBUILD,
// };

extern const stVersionInfo cVerLib_swc_ultrasonic;
extern const stVersionInfo cVerLib_timing;

//const stVersionInfo *sAllVersion[VER_INFO_NUMBER] =
//{
//     [VER_ELF]               = &cVerElf,
//     [VER_LIB_bsw]           = &cVerLib_bsw,
//     [VER_LIB_timing]        = &cVerLib_timing,
// //    [VER_LIB_bsw_base]      = &cVerLib_bsw_base,
// //    [VER_LIB_bsw_emsync]    = &cVerLib_bsw_emsync,
// //    [VER_LIB_bsw_service]   = &cVerLib_bsw_service,
// //    [VER_LIB_bsw_task]      = &cVerLib_bsw_task,
// //    [VER_LIB_bsw_usdriver]  = &cVerLib_bsw_usdriver,
//     [VER_LIB_rte]           = &cVerLib_rte,
//     [VER_LIB_vehmsg]        = &cVerLib_vehmsg,
//     [VER_LIB_swc_adas]      = &cVerLib_swc_adas,
//     [VER_LIB_swc_ultrasonic]= &cVerLib_swc_ultrasonic,

//};

void show_version_info(char *prefix, char *suffix)
{
    // uint32 i;
    // char *preInfo = "";
    // char *sufInfo = "";

    // if(prefix != NULL)
    // {
    //     preInfo = prefix;
    // }
    // if(suffix != NULL)
    // {
    //     sufInfo = suffix;
    // }

    // for(i=0; i<VER_INFO_NUMBER; i++)
    // {
    //     if(sAllVersion[i] != NULL)
    //     {
    //         uart_printf("%s Module(%d):" COLOR_MODULE " %-15s " COLOR_VERSION "V%-9s" COLOR_RESTORE " build %s %s\r\n",
    //                 preInfo,
    //                 sAllVersion[i]->index, sAllVersion[i]->name, sAllVersion[i]->version, sAllVersion[i]->rebuild,
    //                 sufInfo);
    //     }
    // }
}

#define  BSW_STOP_SEC_VAR
#include "proj_MemMap.h"
