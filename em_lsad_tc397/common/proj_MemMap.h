/*
 * proj_MemMap.h
 *
 *  Created on: 2022-1-27
 *      
 */
#if ((EM_PROJECT_ID == EM_61000017_APA) || (EM_PROJECT_ID == EM_61000075_HPA))
#ifndef MEMMAP_WRAPPER
  #define MEMMAP_ERROR
#endif

/*------------------------------------------------------------------------------Section cut line */
#ifdef EM_BSW_START_SEC_VAR
  #pragma section farbss  "EM_Bsw"
  #pragma section fardata "EM_Bsw"
  #pragma section_name_with_symbol
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_VAR_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_VAR_SECTION_OPEN */
  #define PROJ_VAR_SECTION_OPEN
  #undef EM_BSW_START_SEC_VAR
#endif /* ifdef EM_BSW_START_SEC_VAR */

#ifdef EM_BSW_STOP_SEC_VAR
  #pragma section fardata restore
  #pragma section farbss restore
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifndef PROJ_VAR_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_VAR_SECTION_OPEN */
  #undef PROJ_VAR_SECTION_OPEN
  #undef EM_BSW_STOP_SEC_VAR
#endif /* ifdef EM_BSW_STOP_SEC_VAR */
/*------------------------------------------------------------------------------Section cut line */
#ifdef FOTA_START_SEC_VAR
  #pragma section farbss  "lmubss_cpu0.fota"
  #pragma section fardata "lmudata_cpu0.fota"
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_VAR_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_VAR_SECTION_OPEN */
  #define PROJ_VAR_SECTION_OPEN
  #undef FOTA_START_SEC_VAR
#endif /* ifdef FOTA_START_SEC_VAR */

#ifdef FOTA_STOP_SEC_VAR
  #pragma section fardata restore
  #pragma section farbss restore
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifndef PROJ_VAR_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_VAR_SECTION_OPEN */
  #undef PROJ_VAR_SECTION_OPEN
  #undef FOTA_STOP_SEC_VAR
#endif /* ifdef FOTA_STOP_SEC_VAR */
/*------------------------------------------------------------------------------Section cut line */
#ifdef CtrlPara_START_SEC_VAR
  #pragma section farbss  "EM_Adas"
  #pragma section fardata "EM_Adas"
  #pragma section_name_with_symbol
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_VAR_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_VAR_SECTION_OPEN */
  #define PROJ_VAR_SECTION_OPEN
  #undef CtrlPara_START_SEC_VAR
#endif /* ifdef CtrlPara_START_SEC_VAR */

#ifdef CtrlPara_STOP_SEC_VAR
  #pragma section fardata restore
  #pragma section farbss restore
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifndef PROJ_VAR_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_VAR_SECTION_OPEN */
  #undef PROJ_VAR_SECTION_OPEN
  #undef CtrlPara_STOP_SEC_VAR
#endif /* ifdef CtrlPara_STOP_SEC_VAR */

/*------------------------------------------------------------------------------Section cut line */
#ifdef TcpPrint_START_SEC_VAR
  #pragma section farbss  "lmubss_cpu0.tcp_print"  // lmubss_cpu0.*  bss_cpu0.* lmubss.
  #pragma section fardata "lmudata_cpu0.tcp_print" // lmudata_cpu0.* data_cpu0.* lmudata.
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_VAR_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_VAR_SECTION_OPEN */
  #define PROJ_VAR_SECTION_OPEN
  #undef TcpPrint_START_SEC_VAR
#endif /* ifdef TcpPrint_START_SEC_VAR */

#ifdef TcpPrint_STOP_SEC_VAR
  #pragma section fardata restore
  #pragma section farbss restore
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifndef PROJ_VAR_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_VAR_SECTION_OPEN */
  #undef PROJ_VAR_SECTION_OPEN
  #undef TcpPrint_STOP_SEC_VAR
#endif /* ifdef TcpPrint_STOP_SEC_VAR */
/*------------------------------------------------------------------------------Section cut line */
#ifdef UdpPrint_START_SEC_VAR
  #pragma section farbss  "lmubss_cpu0.udp_print"   // lmubss_cpu0.*  bss_cpu0.* lmubss.
  #pragma section fardata "lmudata_cpu0.udp_print"  // lmudata_cpu0.* data_cpu0.* lmudata.
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_VAR_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_VAR_SECTION_OPEN */
  #define PROJ_VAR_SECTION_OPEN
  #undef UdpPrint_START_SEC_VAR
#endif /* ifdef UdpPrint_START_SEC_VAR */

#ifdef UdpPrint_STOP_SEC_VAR
  #pragma section fardata restore
  #pragma section farbss restore
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifndef PROJ_VAR_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_VAR_SECTION_OPEN */
  #undef PROJ_VAR_SECTION_OPEN
  #undef UdpPrint_STOP_SEC_VAR
#endif /* ifdef UdpPrint_STOP_SEC_VAR */
/*------------------------------------------------------------------------------Section cut line */
#ifdef SysInfo_START_SEC_VAR
  #pragma section farbss  "lmubss.sys_info"   // bss_cpu0. or lmubss_cpu0. or lmubss.
  #pragma section fardata "lmudata.sys_info"  // data_cpu0. or lmudata_cpu0. or lmudata.
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_VAR_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_VAR_SECTION_OPEN */
  #define PROJ_VAR_SECTION_OPEN
  #undef SysInfo_START_SEC_VAR
#endif /* ifdef SysInfo_START_SEC_VAR */

#ifdef SysInfo_STOP_SEC_VAR
  #pragma section fardata restore
  #pragma section farbss restore
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifndef PROJ_VAR_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_VAR_SECTION_OPEN */
  #undef PROJ_VAR_SECTION_OPEN
  #undef SysInfo_STOP_SEC_VAR
#endif /* ifdef SysInfo_STOP_SEC_VAR */
/*------------------------------------------------------------------------------Section cut line */
#ifdef Ultrasonic_Service_START_SEC_VAR
  #pragma section farbss  "EM_UssSrv"   // bss_cpu1. or lmubss_cpu1. or lmubss.
  #pragma section fardata "EM_UssSrv"  // data_cpu1. or lmudata_cpu1. or lmudata.
  #pragma section_name_with_symbol
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_VAR_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_VAR_SECTION_OPEN */
  #define PROJ_VAR_SECTION_OPEN
  #undef Ultrasonic_Service_START_SEC_VAR
#endif /* ifdef Ultrasonic_Service_START_SEC_VAR */

#ifdef Ultrasonic_Service_STOP_SEC_VAR
  #pragma section fardata restore
  #pragma section farbss restore
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifndef PROJ_VAR_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_VAR_SECTION_OPEN */
  #undef PROJ_VAR_SECTION_OPEN
  #undef Ultrasonic_Service_STOP_SEC_VAR
#endif /* ifdef Ultrasonic_Service_STOP_SEC_VAR */
/*------------------------------------------------------------------------------Section cut line */
#ifdef Ultrasonic_Cdd_START_SEC_VAR
  #pragma section farbss  "EM_UssSrv"   // bss_cpu1. or lmubss_cpu1. or lmubss.
  #pragma section fardata "EM_UssSrv"  // data_cpu1. or lmudata_cpu1. or lmudata.
  #pragma section_name_with_symbol
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_VAR_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_VAR_SECTION_OPEN */
  #define PROJ_VAR_SECTION_OPEN
  #undef Ultrasonic_Cdd_START_SEC_VAR
#endif /* ifdef Ultrasonic_Cdd_START_SEC_VAR */

#ifdef Ultrasonic_Cdd_STOP_SEC_VAR
  #pragma section fardata restore
  #pragma section farbss restore
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifndef PROJ_VAR_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_VAR_SECTION_OPEN */
  #undef PROJ_VAR_SECTION_OPEN
  #undef Ultrasonic_Cdd_STOP_SEC_VAR
#endif /* ifdef Ultrasonic_Cdd_STOP_SEC_VAR */
/*------------------------------------------------------------------------------Section cut line */
#ifdef Ultrasonic_Algo_START_SEC_VAR
  #pragma section farbss  "EM_UssAlgo"     // bss_cpu1. or lmubss_cpu1. or lmubss.
  #pragma section fardata "EM_UssAlgo"    // data_cpu1. or lmudata_cpu1. or lmudata.
  #pragma section_name_with_symbol
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_VAR_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_VAR_SECTION_OPEN */
  #define PROJ_VAR_SECTION_OPEN
  #undef Ultrasonic_Algo_START_SEC_VAR
#endif /* ifdef Ultrasonic_Algo_START_SEC_VAR */

#ifdef Ultrasonic_Algo_STOP_SEC_VAR
  #pragma section fardata restore
  #pragma section farbss restore
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifndef PROJ_VAR_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_VAR_SECTION_OPEN */
  #undef PROJ_VAR_SECTION_OPEN
  #undef Ultrasonic_Algo_STOP_SEC_VAR
#endif /* ifdef Ultrasonic_Algo_STOP_SEC_VAR */
/*------------------------------------------------------------------------------Section cut line */
#ifdef MsgManager_START_SEC_VAR
  #pragma section farbss  "EM_Veh"
  #pragma section fardata "EM_Veh"
  #pragma section_name_with_symbol
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_VAR_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_VAR_SECTION_OPEN */
  #define PROJ_VAR_SECTION_OPEN
  #undef MsgManager_START_SEC_VAR
#endif /* ifdef MsgManager_START_SEC_VAR */

#ifdef MsgManager_STOP_SEC_VAR
  #pragma section fardata restore
  #pragma section farbss restore
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifndef PROJ_VAR_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_VAR_SECTION_OPEN */
  #undef PROJ_VAR_SECTION_OPEN
  #undef MsgManager_STOP_SEC_VAR
#endif /* ifdef MsgManager_STOP_SEC_VAR */
/*------------------------------------------------------------------------------Section cut line */
#ifdef Rte_START_SEC_VAR
  #pragma section farbss  "EM_Rte"    // bss_cpu1. or lmubss_cpu1. or lmubss.
  #pragma section fardata "EM_Rte"   // data_cpu1. or lmudata_cpu1. or lmudata.
  #pragma section_name_with_symbol
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_VAR_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_VAR_SECTION_OPEN */
  #define PROJ_VAR_SECTION_OPEN
  #undef Rte_START_SEC_VAR
#endif /* ifdef Rte_START_SEC_VAR */

#ifdef Rte_STOP_SEC_VAR
  #pragma section fardata restore
  #pragma section farbss restore
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifndef PROJ_VAR_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_VAR_SECTION_OPEN */
  #undef PROJ_VAR_SECTION_OPEN
  #undef Rte_STOP_SEC_VAR
#endif /* ifdef Rte_STOP_SEC_VAR */
/*------------------------------------------------------------------------------Section cut line */
#ifdef FreeRTosHeap_START_SEC_VAR
  #pragma section farbss  "bss_cpu0.freertos_heap"
  #pragma section fardata "data_cpu0.freertos_heap"
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_VAR_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_VAR_SECTION_OPEN */
  #define PROJ_VAR_SECTION_OPEN
  #undef FreeRTosHeap_START_SEC_VAR
#endif /* ifdef FreeRTosHeap_START_SEC_VAR */
/*------------------------------------------------------------------------------CoreX cut line */
#ifdef FreeRTosHeapCore0_START_SEC_VAR
  #pragma section farbss  "bss_cpu0.freertos_heap0"
  #pragma section fardata "data_cpu0.freertos_heap0"
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_VAR_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_VAR_SECTION_OPEN */
  #define PROJ_VAR_SECTION_OPEN
  #undef FreeRTosHeapCore0_START_SEC_VAR
#endif /* ifdef FreeRTosHeapCore0_START_SEC_VAR */
/*------------------------------------------------------------------------------CoreX cut line */
#ifdef FreeRTosHeapCore1_START_SEC_VAR
  #pragma section farbss  "bss_cpu1.freertos_heap1"
  #pragma section fardata "data_cpu1.freertos_heap1"
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_VAR_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_VAR_SECTION_OPEN */
  #define PROJ_VAR_SECTION_OPEN
  #undef FreeRTosHeapCore1_START_SEC_VAR
#endif /* ifdef FreeRTosHeapCore1_START_SEC_VAR */
/*------------------------------------------------------------------------------CoreX cut line */
#ifdef FreeRTosHeapCore2_START_SEC_VAR
  #pragma section farbss  "bss_cpu2.freertos_heap2"
  #pragma section fardata "data_cpu2.freertos_heap2"
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_VAR_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_VAR_SECTION_OPEN */
  #define PROJ_VAR_SECTION_OPEN
  #undef FreeRTosHeapCore2_START_SEC_VAR
#endif /* ifdef FreeRTosHeapCore2_START_SEC_VAR */
/*------------------------------------------------------------------------------CoreX cut line */
#ifdef FreeRTosHeapCore3_START_SEC_VAR
  #pragma section farbss  "bss_cpu3.freertos_heap3"
  #pragma section fardata "data_cpu3.freertos_heap3"
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_VAR_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_VAR_SECTION_OPEN */
  #define PROJ_VAR_SECTION_OPEN
  #undef FreeRTosHeapCore3_START_SEC_VAR
#endif /* ifdef FreeRTosHeapCore3_START_SEC_VAR */
/*------------------------------------------------------------------------------CoreX cut line */
#ifdef FreeRTosHeapCore4_START_SEC_VAR
  #pragma section farbss  "bss_cpu4.freertos_heap4"
  #pragma section fardata "data_cpu4.freertos_heap4"
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_VAR_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_VAR_SECTION_OPEN */
  #define PROJ_VAR_SECTION_OPEN
  #undef FreeRTosHeapCore4_START_SEC_VAR
#endif /* ifdef FreeRTosHeapCore4_START_SEC_VAR */
/*------------------------------------------------------------------------------CoreX cut line */
#ifdef FreeRTosHeapCore5_START_SEC_VAR
  #pragma section farbss  "bss_cpu5.freertos_heap5"
  #pragma section fardata "data_cpu5.freertos_heap5"
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_VAR_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_VAR_SECTION_OPEN */
  #define PROJ_VAR_SECTION_OPEN
  #undef FreeRTosHeapCore5_START_SEC_VAR
#endif /* ifdef FreeRTosHeapCore5_START_SEC_VAR */
/*------------------------------------------------------------------------------CoreX cut line */
#ifdef FreeRTosHeap_STOP_SEC_VAR
  #pragma section fardata restore
  #pragma section farbss restore
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifndef PROJ_VAR_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_VAR_SECTION_OPEN */
  #undef PROJ_VAR_SECTION_OPEN
  #undef FreeRTosHeap_STOP_SEC_VAR
#endif /* ifdef FreeRTosHeap_STOP_SEC_VAR */
/*------------------------------------------------------------------------------Section cut line */
#ifdef LwipDemo_START_SEC_VAR
  #pragma section farbss  "lmubss_cpu0.lwip_demo"  // lmubss_cpu0, bss_cpu0, lmubss
  #pragma section fardata "lmudata_cpu0.lwip_demo" // lmudata_cpu0, data_cpu0, lmudata
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_VAR_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_VAR_SECTION_OPEN */
  #define PROJ_VAR_SECTION_OPEN
  #undef LwipDemo_START_SEC_VAR
#endif /* ifdef LwipDemo_START_SEC_VAR */

#ifdef LwipDemo_STOP_SEC_VAR
  #pragma section fardata restore
  #pragma section farbss restore
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifndef PROJ_VAR_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_VAR_SECTION_OPEN */
  #undef PROJ_VAR_SECTION_OPEN
  #undef LwipDemo_STOP_SEC_VAR
#endif /* ifdef LwipDemo_STOP_SEC_VAR */
/*------------------------------------------------------------------------------Section cut line */
#ifdef TIMING_START_SEC_VAR
  #pragma section farbss  "lmubss_cpu0.timing"     // bss_cpu5. or lmubss_cpu5. or lmubss.
  #pragma section fardata "lmudata_cpu0.timing"    // data_cpu5. or lmudata_cpu5. or lmudata.

  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR

  #ifdef PROJ_ALL_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_ALL_SECTION_OPEN */
  #define PROJ_ALL_SECTION_OPEN

  #undef TIMING_START_SEC_VAR
#endif /* ifdef TIMING_START_SEC_VAR */

#ifdef TIMING_STOP_SEC_VAR
  #pragma section fardata restore
  #pragma section farbss restore

  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR

  #ifndef PROJ_ALL_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_ALL_SECTION_OPEN */
  #undef PROJ_ALL_SECTION_OPEN

  #undef TIMING_STOP_SEC_VAR
#endif /* ifdef TIMING_STOP_SEC_VAR */
/*-------------------------------------------------------------------------------------------ALL */
#ifdef BSW_START_SEC_VAR
  //#pragma section code    "text_cpu0.lwip_dma"
  #pragma section farbss  "EM_Bsw"   // lmubss_cpu0, bss_cpu0, lmubss
  #pragma section fardata "EM_Bsw"  // lmudata_cpu0, data_cpu0, lmudata
  #pragma section_name_with_symbol
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_ALL_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_ALL_SECTION_OPEN */
  #define PROJ_ALL_SECTION_OPEN
  #undef BSW_START_SEC_VAR
#endif /* ifdef BSW_START_SEC_VAR */

#ifdef BSW_STOP_SEC_VAR
  //#pragma section code restore
  #pragma section fardata restore
  #pragma section farbss restore
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifndef PROJ_ALL_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_ALL_SECTION_OPEN */
  #undef PROJ_ALL_SECTION_OPEN
  #undef BSW_STOP_SEC_VAR
#endif /* ifdef BSW_STOP_SEC_VAR */
/*-------------------------------------------------------------------------------------------ALL */
#ifdef C5_BSW_START_SEC_VAR
  //#pragma section code    "text_cpu0.lwip_dma"
  #pragma section farbss  "EM_Bsw_C5"   // lmubss_cpu0, bss_cpu0, lmubss
  #pragma section fardata "EM_Bsw_C5"  // lmudata_cpu0, data_cpu0, lmudata
  #pragma section_name_with_symbol
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_ALL_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_ALL_SECTION_OPEN */
  #define PROJ_ALL_SECTION_OPEN
  #undef C5_BSW_START_SEC_VAR
#endif /* ifdef C5_BSW_START_SEC_VAR */

#ifdef C5_BSW_STOP_SEC_VAR
  //#pragma section code restore
  #pragma section fardata restore
  #pragma section farbss restore
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifndef PROJ_ALL_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_ALL_SECTION_OPEN */
  #undef PROJ_ALL_SECTION_OPEN
  #undef C5_BSW_STOP_SEC_VAR
#endif /* ifdef C5_BSW_STOP_SEC_VAR */
/*------------------------------------------------------------------------------Section cut line */
#ifdef EMOS_START_SEC_VAR
  //#pragma section code    "text_cpu0.lwip_dma"
  #pragma section farbss  "EM_emos"   // lmubss_cpu0, bss_cpu0, lmubss
  #pragma section fardata "EM_emos"  // lmudata_cpu0, data_cpu0, lmudata
  #pragma section_name_with_symbol
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_ALL_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_ALL_SECTION_OPEN */
  #define PROJ_ALL_SECTION_OPEN
  #undef EMOS_START_SEC_VAR
#endif /* ifdef EMOS_START_SEC_VAR */

#ifdef EMOS_STOP_SEC_VAR
  //#pragma section code restore
  #pragma section fardata restore
  #pragma section farbss restore
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifndef PROJ_ALL_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_ALL_SECTION_OPEN */
  #undef PROJ_ALL_SECTION_OPEN
  #undef EMOS_STOP_SEC_VAR
#endif /* ifdef EMOS_STOP_SEC_VAR */
/*------------------------------------------------------------------------------Section cut line */
#ifdef EMDC_START_SEC_VAR
  //#pragma section code    "text_cpu0.lwip_dma"
  #pragma section farbss  "EM_emdc"   // lmubss_cpu0, bss_cpu0, lmubss
  #pragma section fardata "EM_emdc"  // lmudata_cpu0, data_cpu0, lmudata
  #pragma section_name_with_symbol
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_ALL_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_ALL_SECTION_OPEN */
  #define PROJ_ALL_SECTION_OPEN
  #undef EMDC_START_SEC_VAR
#endif /* ifdef EMDC_START_SEC_VAR */

#ifdef EMDC_STOP_SEC_VAR
  //#pragma section code restore
  #pragma section fardata restore
  #pragma section farbss restore
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifndef PROJ_ALL_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_ALL_SECTION_OPEN */
  #undef PROJ_ALL_SECTION_OPEN
  #undef EMDC_STOP_SEC_VAR
#endif /* ifdef EMDC_STOP_SEC_VAR */
/*------------------------------------------------------------------------------Section cut line */
#ifdef START_SEC_LWIP_MEM_ALL
  //#pragma section code    "text_cpu0.lwip_mem"
  #pragma section farbss  "lmubss_cpu0.lwip_mem"   // lmubss_cpu0, bss_cpu0, lmubss
  #pragma section fardata "lmudata_cpu0.lwip_mem"  // lmudata_cpu0, data_cpu0, lmudata
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_ALL_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_ALL_SECTION_OPEN */
  #define PROJ_ALL_SECTION_OPEN
  #undef START_SEC_LWIP_MEM_ALL
#endif /* ifdef START_SEC_LWIP_MEM_ALL */

#ifdef STOP_SEC_LWIP_MEM_ALL
  //#pragma section code restore
  #pragma section fardata restore
  #pragma section farbss restore
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifndef PROJ_ALL_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_ALL_SECTION_OPEN */
  #undef PROJ_ALL_SECTION_OPEN
  #undef STOP_SEC_LWIP_MEM_ALL
#endif /* ifdef STOP_SEC_LWIP_MEM_ALL */
/*-------------------------------------------------------------------------------------------ALL */
#ifdef RAM5_RESERVE_START_SEC_VAR
  //#pragma section code    "text_cpu0.lwip_dma"
  #pragma section farbss  "EM_Ram5Rsv"   // lmubss_cpu0, bss_cpu0, lmubss
  #pragma section fardata "EM_Ram5Rsv"  // lmudata_cpu0, data_cpu0, lmudata
  #pragma section_name_with_symbol
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_ALL_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_ALL_SECTION_OPEN */
  #define PROJ_ALL_SECTION_OPEN
  #undef RAM5_RESERVE_START_SEC_VAR
#endif /* ifdef RAM5_RESERVE_START_SEC_VAR */

#ifdef RAM5_RESERVE_STOP_SEC_VAR
  //#pragma section code restore
  #pragma section fardata restore
  #pragma section farbss restore
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifndef PROJ_ALL_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_ALL_SECTION_OPEN */
  #undef PROJ_ALL_SECTION_OPEN
  #undef RAM5_RESERVE_STOP_SEC_VAR
#endif /* ifdef RAM5_RESERVE_STOP_SEC_VAR */
/*-------------------------------------------------------------------------------------------ALL */
#ifdef RAM4_RESERVE_START_SEC_VAR
  //#pragma section code    "text_cpu0.lwip_dma"
  #pragma section farbss  "EM_Ram4Rsv"   // lmubss_cpu0, bss_cpu0, lmubss
  #pragma section fardata "EM_Ram4Rsv"  // lmudata_cpu0, data_cpu0, lmudata
  #pragma section_name_with_symbol
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_ALL_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_ALL_SECTION_OPEN */
  #define PROJ_ALL_SECTION_OPEN
  #undef RAM4_RESERVE_START_SEC_VAR
#endif /* ifdef RAM4_RESERVE_START_SEC_VAR */

#ifdef RAM4_RESERVE_STOP_SEC_VAR
  //#pragma section code restore
  #pragma section fardata restore
  #pragma section farbss restore
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifndef PROJ_ALL_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_ALL_SECTION_OPEN */
  #undef PROJ_ALL_SECTION_OPEN
  #undef RAM4_RESERVE_STOP_SEC_VAR
#endif /* ifdef RAM4_RESERVE_STOP_SEC_VAR */
/*-------------------------------------------------------------------------------------------ALL */
#ifdef RAM2_RESERVE_START_SEC_VAR
  //#pragma section code    "text_cpu0.lwip_dma"
  #pragma section farbss  "EM_Ram2Rsv"   // lmubss_cpu0, bss_cpu0, lmubss
  #pragma section fardata "EM_Ram2Rsv"  // lmudata_cpu0, data_cpu0, lmudata
  #pragma section_name_with_symbol
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_ALL_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_ALL_SECTION_OPEN */
  #define PROJ_ALL_SECTION_OPEN
  #undef RAM2_RESERVE_START_SEC_VAR
#endif /* ifdef RAM2_RESERVE_START_SEC_VAR */

#ifdef RAM2_RESERVE_STOP_SEC_VAR
  //#pragma section code restore
  #pragma section fardata restore
  #pragma section farbss restore
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifndef PROJ_ALL_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_ALL_SECTION_OPEN */
  #undef PROJ_ALL_SECTION_OPEN
  #undef RAM2_RESERVE_STOP_SEC_VAR
#endif /* ifdef RAM2_RESERVE_STOP_SEC_VAR */
/*-------------------------------------------------------------------------------------------ALL */
#ifdef RAM3_RESERVE_START_SEC_VAR
  //#pragma section code    "text_cpu0.lwip_dma"
  #pragma section farbss  "EM_Ram3Rsv"   // lmubss_cpu0, bss_cpu0, lmubss
  #pragma section fardata "EM_Ram3Rsv"  // lmudata_cpu0, data_cpu0, lmudata
  #pragma section_name_with_symbol
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_ALL_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_ALL_SECTION_OPEN */
  #define PROJ_ALL_SECTION_OPEN
  #undef RAM3_RESERVE_START_SEC_VAR
#endif /* ifdef RAM3_RESERVE_START_SEC_VAR */

#ifdef RAM3_RESERVE_STOP_SEC_VAR
  //#pragma section code restore
  #pragma section fardata restore
  #pragma section farbss restore
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifndef PROJ_ALL_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_ALL_SECTION_OPEN */
  #undef PROJ_ALL_SECTION_OPEN
  #undef RAM3_RESERVE_STOP_SEC_VAR
#endif /* ifdef RAM3_RESERVE_STOP_SEC_VAR */

/*-------------------------------------------------------------------------------------------ALL */
#ifdef RAM1_RESERVE_START_SEC_VAR
  //#pragma section code    "text_cpu0.lwip_dma"
  #pragma section farbss  "EM_Ram1Rsv"   // lmubss_cpu0, bss_cpu0, lmubss
  #pragma section fardata "EM_Ram1Rsv"  // lmudata_cpu0, data_cpu0, lmudata
  #pragma section_name_with_symbol
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_ALL_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_ALL_SECTION_OPEN */
  #define PROJ_ALL_SECTION_OPEN
  #undef RAM1_RESERVE_START_SEC_VAR
#endif /* ifdef RAM1_RESERVE_START_SEC_VAR */

#ifdef RAM1_RESERVE_STOP_SEC_VAR
  //#pragma section code restore
  #pragma section fardata restore
  #pragma section farbss restore
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifndef PROJ_ALL_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_ALL_SECTION_OPEN */
  #undef PROJ_ALL_SECTION_OPEN
  #undef RAM1_RESERVE_STOP_SEC_VAR
#endif /* ifdef RAM1_RESERVE_STOP_SEC_VAR */

/*-------------------------------------------------------------------------------------------ALL */
#ifdef RAM0_RESERVE_START_SEC_VAR
  //#pragma section code    "text_cpu0.lwip_dma"
  #pragma section farbss  "EM_Ram0Rsv"   // lmubss_cpu0, bss_cpu0, lmubss
  #pragma section fardata "EM_Ram0Rsv"  // lmudata_cpu0, data_cpu0, lmudata
  #pragma section_name_with_symbol
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_ALL_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_ALL_SECTION_OPEN */
  #define PROJ_ALL_SECTION_OPEN
  #undef RAM0_RESERVE_START_SEC_VAR
#endif /* ifdef RAM0_RESERVE_START_SEC_VAR */

#ifdef RAM0_RESERVE_STOP_SEC_VAR
  //#pragma section code restore
  #pragma section fardata restore
  #pragma section farbss restore
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifndef PROJ_ALL_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_ALL_SECTION_OPEN */
  #undef PROJ_ALL_SECTION_OPEN
  #undef RAM0_RESERVE_STOP_SEC_VAR
#endif /* ifdef RAM0_RESERVE_STOP_SEC_VAR */

#ifdef APPVAR_START_SEC_VAR
  #pragma section farbss  "bss_cpu2.app_var"
  #pragma section fardata "data_cpu2.app_var"
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifdef PROJ_VAR_SECTION_OPEN
    #error "MEMMAP sections may not be nested: close former section before opening a new one"
  #endif /* ifdef PROJ_VAR_SECTION_OPEN */
  #define PROJ_VAR_SECTION_OPEN
  #undef APPVAR_START_SEC_VAR
#endif /* ifdef APPVAR_START_SEC_VAR */

#ifdef APPVAR_STOP_SEC_VAR
  #pragma section fardata restore
  #pragma section farbss restore
  #ifndef MEMMAP_ERROR
    #error "multiple MEMMAP sections are defined: the proj_MemMap.h file must be included after each section definition"
  #endif
  #undef MEMMAP_ERROR
  #ifndef PROJ_VAR_SECTION_OPEN
    #error "trying to close MEMMAP section which was not opened"
  #endif /* ifndef PROJ_VAR_SECTION_OPEN */
  #undef PROJ_VAR_SECTION_OPEN
  #undef APPVAR_STOP_SEC_VAR
#endif /* ifdef APPVAR_STOP_SEC_VAR */

#endif //((EM_PROJECT_ID == EM_61000017_APA) || (EM_PROJECT_ID == EM_61000075_HPA))
/*--------------------------------------------------------------------------------------END FILE */
