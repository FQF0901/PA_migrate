/* This file is generated automatically. DO NOT EDIT!!
 * 
 * EB tresos AutoCore OS 6.1.73 TRICORE/TC39XX
 * (Build 20220425)
 * 
 * (c) 1998-2024 Elektrobit Automotive GmbH
 * Am Wolfsmantel 46
 * 91058 Erlangen
 * GERMANY
 * 
 * Date         : 2/1/24 11:25 AM           !!!IGNORE-LINE!!!
 */

#ifndef OS_CONFIG_H
#define OS_CONFIG_H
#ifdef __cplusplus
extern "C" {
#endif

/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 8.6 (required)
 * An identifier with external linkage shall have exactly one external definition.
 *
 * Reason:
 * These symbols are defined in assembly language files and hence,
 * are not visible to the MISRA-C analyzer.
 */
#include <Os.h>
#include <Os_tool.h>
#include <TRICORE/Os_TRICORE_timer_stm.h>

#define OS_GENERATION_ID_OS_CONF_H  0xbe1fc30cUL

#define OS_AUTOSAROS_VER            6

#define OS_AUTOSAROS_REV            1

#define OS_AUTOSAROS_CORE_BUILD     20220425

#define OS_AUTOSAROS_ARCH_BUILD     20220425

#ifndef OS_ASM
extern const os_uint32_t OS_os_GenBuildId;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern const os_uint32_t OS_OsApplication_C0GenBuildId;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern const os_uint32_t OS_OsApplication_C1GenBuildId;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern const os_uint32_t OS_OsApplication_C2GenBuildId;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern const os_uint32_t OS_OsApplication_C3GenBuildId;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern const os_uint32_t OS_OsApplication_C4GenBuildId;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern const os_uint32_t OS_OsApplication_C5GenBuildId;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern const os_uint32_t OS_OS_SYSTEM_0GenBuildId;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern const os_uint32_t OS_OS_SYSTEM_1GenBuildId;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern const os_uint32_t OS_OS_SYSTEM_2GenBuildId;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern const os_uint32_t OS_OS_SYSTEM_3GenBuildId;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern const os_uint32_t OS_OS_SYSTEM_4GenBuildId;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern const os_uint32_t OS_OS_SYSTEM_5GenBuildId;
#endif  /* OS_ASM */

/*===================================================================
 * Advanced Logical Core Interface
 *==================================================================*/
/* Advanced Logical Core Interface preprocessor macros. */
#define OS_ALCI_LOG_TO_PHY_CORE0  0
#define OS_ALCI_LOG_TO_PHY_CORE1  1
#define OS_ALCI_LOG_TO_PHY_CORE2  2
#define OS_ALCI_LOG_TO_PHY_CORE3  3
#define OS_ALCI_LOG_TO_PHY_CORE4  4
#define OS_ALCI_LOG_TO_PHY_CORE5  5

#define OS_ALCI_PHY_TO_LOG_CORE0  0
#define OS_ALCI_PHY_TO_LOG_CORE1  1
#define OS_ALCI_PHY_TO_LOG_CORE2  2
#define OS_ALCI_PHY_TO_LOG_CORE3  3
#define OS_ALCI_PHY_TO_LOG_CORE4  4
#define OS_ALCI_PHY_TO_LOG_CORE5  5

/*===================================================================
 * Alarms
 *==================================================================*/
#define OS_NALARMS  6
#define OS_NALARMCALLBACKS  0

#define OS_SchM_DefaultScheduleTable_OsApplication_C0  6
#define OS_Rte_DefaultScheduleTable_OsApplication_C0  7
#define OS_SchM_DefaultScheduleTable_OsApplication_C1  8
#define OS_Rte_DefaultScheduleTable_OsApplication_C1  9
#define OS_SchM_DefaultScheduleTable_OsApplication_C2  10
#define OS_SchM_DefaultScheduleTable_OsApplication_C3  11
#define OS_SchM_DefaultScheduleTable_OsApplication_C4  12
#define OS_SchM_DefaultScheduleTable_OsApplication_C5  13
#define OS_Rte_DefaultScheduleTable_OsApplication_C2  14
#define OS_Rte_DefaultScheduleTable_OsApplication_C3  15

#define OS_ALARM  OS_ALARM_INIT(    /* AlarmIncrementRteCounter_C0 */  \
  /* Application id */                        OsApplication_C0,  \
  /* Application pointer */                   &OS_appTable[OsApplication_C0],  \
  /* Permissions */                           0x1u,  \
  /* Counter wrapper */                       &OS_WrapIncrementCounter,  \
  /* Not used */                              0,  \
  /* Incremented counter */                   Rte_Counter_C0,  \
  /* Alarm counter */                         HwCounter_C0,  \
  /* dynamic data */                          &OS_alarmDynamic_core0[0]  \
),  \
OS_ALARM_INIT(    /* AlarmIncrementRteCounter_C1 */  \
  /* Application id */                        OsApplication_C1,  \
  /* Application pointer */                   &OS_appTable[OsApplication_C1],  \
  /* Permissions */                           0x2u,  \
  /* Counter wrapper */                       &OS_WrapIncrementCounter,  \
  /* Not used */                              0,  \
  /* Incremented counter */                   Rte_Counter_C1,  \
  /* Alarm counter */                         HwCounter_C1,  \
  /* dynamic data */                          &OS_alarmDynamic_core1[0]  \
),  \
OS_ALARM_INIT(    /* AlarmIncrementRteCounter_C2 */  \
  /* Application id */                        OsApplication_C2,  \
  /* Application pointer */                   &OS_appTable[OsApplication_C2],  \
  /* Permissions */                           0x4u,  \
  /* Counter wrapper */                       &OS_WrapIncrementCounter,  \
  /* Not used */                              0,  \
  /* Incremented counter */                   Rte_Counter_C2,  \
  /* Alarm counter */                         HwCounter_C2,  \
  /* dynamic data */                          &OS_alarmDynamic_core2[0]  \
),  \
OS_ALARM_INIT(    /* AlarmIncrementRteCounter_C3 */  \
  /* Application id */                        OsApplication_C3,  \
  /* Application pointer */                   &OS_appTable[OsApplication_C3],  \
  /* Permissions */                           0x8u,  \
  /* Counter wrapper */                       &OS_WrapIncrementCounter,  \
  /* Not used */                              0,  \
  /* Incremented counter */                   Rte_Counter_C3,  \
  /* Alarm counter */                         HwCounter_C3,  \
  /* dynamic data */                          &OS_alarmDynamic_core3[0]  \
),  \
OS_ALARM_INIT(    /* AlarmIncrementRteCounter_C4 */  \
  /* Application id */                        OsApplication_C4,  \
  /* Application pointer */                   &OS_appTable[OsApplication_C4],  \
  /* Permissions */                           0x10u,  \
  /* Counter wrapper */                       &OS_WrapIncrementCounter,  \
  /* Not used */                              0,  \
  /* Incremented counter */                   Rte_Counter_C4,  \
  /* Alarm counter */                         HwCounter_C4,  \
  /* dynamic data */                          &OS_alarmDynamic_core4[0]  \
),  \
OS_ALARM_INIT(    /* AlarmIncrementRteCounter_C5 */  \
  /* Application id */                        OsApplication_C5,  \
  /* Application pointer */                   &OS_appTable[OsApplication_C5],  \
  /* Permissions */                           0x20u,  \
  /* Counter wrapper */                       &OS_WrapIncrementCounter,  \
  /* Not used */                              0,  \
  /* Incremented counter */                   Rte_Counter_C5,  \
  /* Alarm counter */                         HwCounter_C5,  \
  /* dynamic data */                          &OS_alarmDynamic_core5[0]  \
),  \
OS_ALARM_INIT(    /* OS_SchM_DefaultScheduleTable_OsApplication_C0 */  \
  /* Application id */                        OsApplication_C0,  \
  /* Application pointer */                   &OS_appTable[OsApplication_C0],  \
  /* Permissions */                           0x1u,  \
  /* Schedule table wrapper */                &OS_WrapRunSchedule,  \
  /* Not used */                              0,  \
  /* Schedule table */                        SchM_DefaultScheduleTable_OsApplication_C0,  \
  /* Alarm counter */                         Rte_Counter_C0,  \
  /* dynamic data */                          &OS_alarmDynamic_core0[1]  \
),  \
OS_ALARM_INIT(    /* OS_Rte_DefaultScheduleTable_OsApplication_C0 */  \
  /* Application id */                        OsApplication_C0,  \
  /* Application pointer */                   &OS_appTable[OsApplication_C0],  \
  /* Permissions */                           0x1u,  \
  /* Schedule table wrapper */                &OS_WrapRunSchedule,  \
  /* Not used */                              0,  \
  /* Schedule table */                        Rte_DefaultScheduleTable_OsApplication_C0,  \
  /* Alarm counter */                         Rte_Counter_C0,  \
  /* dynamic data */                          &OS_alarmDynamic_core0[2]  \
),  \
OS_ALARM_INIT(    /* OS_SchM_DefaultScheduleTable_OsApplication_C1 */  \
  /* Application id */                        OsApplication_C1,  \
  /* Application pointer */                   &OS_appTable[OsApplication_C1],  \
  /* Permissions */                           0x2u,  \
  /* Schedule table wrapper */                &OS_WrapRunSchedule,  \
  /* Not used */                              0,  \
  /* Schedule table */                        SchM_DefaultScheduleTable_OsApplication_C1,  \
  /* Alarm counter */                         Rte_Counter_C1,  \
  /* dynamic data */                          &OS_alarmDynamic_core1[1]  \
),  \
OS_ALARM_INIT(    /* OS_Rte_DefaultScheduleTable_OsApplication_C1 */  \
  /* Application id */                        OsApplication_C1,  \
  /* Application pointer */                   &OS_appTable[OsApplication_C1],  \
  /* Permissions */                           0x2u,  \
  /* Schedule table wrapper */                &OS_WrapRunSchedule,  \
  /* Not used */                              0,  \
  /* Schedule table */                        Rte_DefaultScheduleTable_OsApplication_C1,  \
  /* Alarm counter */                         Rte_Counter_C1,  \
  /* dynamic data */                          &OS_alarmDynamic_core1[2]  \
),  \
OS_ALARM_INIT(    /* OS_SchM_DefaultScheduleTable_OsApplication_C2 */  \
  /* Application id */                        OsApplication_C2,  \
  /* Application pointer */                   &OS_appTable[OsApplication_C2],  \
  /* Permissions */                           0x4u,  \
  /* Schedule table wrapper */                &OS_WrapRunSchedule,  \
  /* Not used */                              0,  \
  /* Schedule table */                        SchM_DefaultScheduleTable_OsApplication_C2,  \
  /* Alarm counter */                         Rte_Counter_C2,  \
  /* dynamic data */                          &OS_alarmDynamic_core2[1]  \
),  \
OS_ALARM_INIT(    /* OS_SchM_DefaultScheduleTable_OsApplication_C3 */  \
  /* Application id */                        OsApplication_C3,  \
  /* Application pointer */                   &OS_appTable[OsApplication_C3],  \
  /* Permissions */                           0x8u,  \
  /* Schedule table wrapper */                &OS_WrapRunSchedule,  \
  /* Not used */                              0,  \
  /* Schedule table */                        SchM_DefaultScheduleTable_OsApplication_C3,  \
  /* Alarm counter */                         Rte_Counter_C3,  \
  /* dynamic data */                          &OS_alarmDynamic_core3[1]  \
),  \
OS_ALARM_INIT(    /* OS_SchM_DefaultScheduleTable_OsApplication_C4 */  \
  /* Application id */                        OsApplication_C4,  \
  /* Application pointer */                   &OS_appTable[OsApplication_C4],  \
  /* Permissions */                           0x10u,  \
  /* Schedule table wrapper */                &OS_WrapRunSchedule,  \
  /* Not used */                              0,  \
  /* Schedule table */                        SchM_DefaultScheduleTable_OsApplication_C4,  \
  /* Alarm counter */                         Rte_Counter_C4,  \
  /* dynamic data */                          &OS_alarmDynamic_core4[1]  \
),  \
OS_ALARM_INIT(    /* OS_SchM_DefaultScheduleTable_OsApplication_C5 */  \
  /* Application id */                        OsApplication_C5,  \
  /* Application pointer */                   &OS_appTable[OsApplication_C5],  \
  /* Permissions */                           0x20u,  \
  /* Schedule table wrapper */                &OS_WrapRunSchedule,  \
  /* Not used */                              0,  \
  /* Schedule table */                        SchM_DefaultScheduleTable_OsApplication_C5,  \
  /* Alarm counter */                         Rte_Counter_C5,  \
  /* dynamic data */                          &OS_alarmDynamic_core5[1]  \
),  \
OS_ALARM_INIT(    /* OS_Rte_DefaultScheduleTable_OsApplication_C2 */  \
  /* Application id */                        OsApplication_C2,  \
  /* Application pointer */                   &OS_appTable[OsApplication_C2],  \
  /* Permissions */                           0x4u,  \
  /* Schedule table wrapper */                &OS_WrapRunSchedule,  \
  /* Not used */                              0,  \
  /* Schedule table */                        Rte_DefaultScheduleTable_OsApplication_C2,  \
  /* Alarm counter */                         Rte_Counter_C2,  \
  /* dynamic data */                          &OS_alarmDynamic_core2[2]  \
),  \
OS_ALARM_INIT(    /* OS_Rte_DefaultScheduleTable_OsApplication_C3 */  \
  /* Application id */                        OsApplication_C3,  \
  /* Application pointer */                   &OS_appTable[OsApplication_C3],  \
  /* Permissions */                           0x8u,  \
  /* Schedule table wrapper */                &OS_WrapRunSchedule,  \
  /* Not used */                              0,  \
  /* Schedule table */                        Rte_DefaultScheduleTable_OsApplication_C3,  \
  /* Alarm counter */                         Rte_Counter_C3,  \
  /* dynamic data */                          &OS_alarmDynamic_core3[2]  \
)
#define OS_NALARMS_CORE0  1
#define OS_NALARMS_CORE1  1
#define OS_NALARMS_CORE2  1
#define OS_NALARMS_CORE3  1
#define OS_NALARMS_CORE4  1
#define OS_NALARMS_CORE5  1

/*===================================================================
 * Application modes
 *==================================================================*/
#define OS_NSTARTMODES  1
/* Autostart Tasks */
#define OS_AUTOSTARTTASKS  \
  EM_Bsw_Start_Init_C0,  \
  EM_Bsw_Init_C1,  \
  EM_Bsw_Init_C2,  \
  Init_Task_C3,  \
  Init_Task_C4,  \
  Init_Task_C5,  \
  OS_NULLTASK

#define OS_STARTMODETASKS  \
  0

/* Autostart Alarms */
#define OS_AUTOSTARTALARMS  \
    {  \
      AlarmIncrementRteCounter_C0,  \
      OS_STARTMETHOD_REL,  \
      OS_NsToTicks_HwCounter_C0(1000000),  \
      OS_NsToTicks_HwCounter_C0(1000000)  \
    },  \
    {  \
      AlarmIncrementRteCounter_C1,  \
      OS_STARTMETHOD_REL,  \
      OS_NsToTicks_HwCounter_C1(1000000),  \
      OS_NsToTicks_HwCounter_C1(1000000)  \
    },  \
    {  \
      AlarmIncrementRteCounter_C2,  \
      OS_STARTMETHOD_REL,  \
      OS_NsToTicks_HwCounter_C2(1000000),  \
      OS_NsToTicks_HwCounter_C2(1000000)  \
    },  \
    {  \
      AlarmIncrementRteCounter_C3,  \
      OS_STARTMETHOD_REL,  \
      OS_NsToTicks_HwCounter_C3(1000000),  \
      OS_NsToTicks_HwCounter_C3(1000000)  \
    },  \
    {  \
      AlarmIncrementRteCounter_C4,  \
      OS_STARTMETHOD_REL,  \
      OS_NsToTicks_HwCounter_C4(1000000),  \
      OS_NsToTicks_HwCounter_C4(1000000)  \
    },  \
    {  \
      AlarmIncrementRteCounter_C5,  \
      OS_STARTMETHOD_REL,  \
      OS_NsToTicks_HwCounter_C5(1000000),  \
      OS_NsToTicks_HwCounter_C5(1000000)  \
    },  \
    {  \
      OS_NULLALARM,  \
      OS_STARTMETHOD_REL,  \
      0,  \
      0  \
    }

#define OS_STARTMODEALARMS  \
  0

/* Autostart ScheduleTables */


/*===================================================================
 * Applications
 *==================================================================*/
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsApplication_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsApplication_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsApplication_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsApplication_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsApplication_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsApplication_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsApplication_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsApplication_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsApplication_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsApplication_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsApplication_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsApplication_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsApplication_C3);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsApplication_C3);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsApplication_C3);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsApplication_C3);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsApplication_C4);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsApplication_C4);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsApplication_C4);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsApplication_C4);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsApplication_C5);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsApplication_C5);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsApplication_C5);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsApplication_C5);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_NAPPS        12
#define OS_NAPPSNONPRIV  0
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OS_SYSTEM_0  6
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OS_SYSTEM_1  7
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OS_SYSTEM_2  8
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OS_SYSTEM_3  9
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OS_SYSTEM_4  10
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OS_SYSTEM_5  11
#endif

#define OS_APPCONFIG  OS_APPCONFIG_INIT(    /* OsApplication_C0 */  \
  /* Build ID */                                    &OS_OsApplication_C0GenBuildId,  \
  /* Startup Hook */                                OS_NULL,  \
  /* Shutdown Hook */                               OS_NULL,  \
  /* Error hook */                                  OS_NULL,  \
  /* start of data/bss */                           &OS_TOOL_MR_START(OsApplication_C0),  \
  /* end of data/bss */                             &OS_TOOL_MR_END(OsApplication_C0),  \
  /* start of initial data */                       &OS_TOOL_MR_LMA_START(OsApplication_C0),  \
  /* end of initial data */                         &OS_TOOL_MR_LMA_END(OsApplication_C0),  \
  /* Permission Bit */                              0x1,  \
  /* Accessing applications */                      0x1,  \
  /* Startup hook stack */                          0,  \
  /* Shutdown hook stack */                         0,  \
  /* Error hook stack */                            0,  \
  /* Restart Task */                                OS_NULLTASK,  \
  /* Flags */                                       (OS_APP_TRUSTED),  \
  /* Application ID */                              OsApplication_C0,  \
  /* dynamic data */                                &OS_appDynamic_core0[0],  \
  /* CPU core */                                    0,  \
    OS_ARCHAPP_INIT(  \
      /* Flags */                                   (OS_PSW_PRS_0|OS_PSW_IO_SU|OS_PSW_CDC_DIS)  \
    )  \
),  \
OS_APPCONFIG_INIT(    /* OsApplication_C1 */  \
  /* Build ID */                                    &OS_OsApplication_C1GenBuildId,  \
  /* Startup Hook */                                OS_NULL,  \
  /* Shutdown Hook */                               OS_NULL,  \
  /* Error hook */                                  OS_NULL,  \
  /* start of data/bss */                           &OS_TOOL_MR_START(OsApplication_C1),  \
  /* end of data/bss */                             &OS_TOOL_MR_END(OsApplication_C1),  \
  /* start of initial data */                       &OS_TOOL_MR_LMA_START(OsApplication_C1),  \
  /* end of initial data */                         &OS_TOOL_MR_LMA_END(OsApplication_C1),  \
  /* Permission Bit */                              0x2,  \
  /* Accessing applications */                      0x2,  \
  /* Startup hook stack */                          0,  \
  /* Shutdown hook stack */                         0,  \
  /* Error hook stack */                            0,  \
  /* Restart Task */                                OS_NULLTASK,  \
  /* Flags */                                       (OS_APP_TRUSTED),  \
  /* Application ID */                              OsApplication_C1,  \
  /* dynamic data */                                &OS_appDynamic_core1[0],  \
  /* CPU core */                                    1,  \
    OS_ARCHAPP_INIT(  \
      /* Flags */                                   (OS_PSW_PRS_0|OS_PSW_IO_SU|OS_PSW_CDC_DIS)  \
    )  \
),  \
OS_APPCONFIG_INIT(    /* OsApplication_C2 */  \
  /* Build ID */                                    &OS_OsApplication_C2GenBuildId,  \
  /* Startup Hook */                                OS_NULL,  \
  /* Shutdown Hook */                               OS_NULL,  \
  /* Error hook */                                  OS_NULL,  \
  /* start of data/bss */                           &OS_TOOL_MR_START(OsApplication_C2),  \
  /* end of data/bss */                             &OS_TOOL_MR_END(OsApplication_C2),  \
  /* start of initial data */                       &OS_TOOL_MR_LMA_START(OsApplication_C2),  \
  /* end of initial data */                         &OS_TOOL_MR_LMA_END(OsApplication_C2),  \
  /* Permission Bit */                              0x4,  \
  /* Accessing applications */                      0x4,  \
  /* Startup hook stack */                          0,  \
  /* Shutdown hook stack */                         0,  \
  /* Error hook stack */                            0,  \
  /* Restart Task */                                OS_NULLTASK,  \
  /* Flags */                                       (OS_APP_TRUSTED),  \
  /* Application ID */                              OsApplication_C2,  \
  /* dynamic data */                                &OS_appDynamic_core2[0],  \
  /* CPU core */                                    2,  \
    OS_ARCHAPP_INIT(  \
      /* Flags */                                   (OS_PSW_PRS_0|OS_PSW_IO_SU|OS_PSW_CDC_DIS)  \
    )  \
),  \
OS_APPCONFIG_INIT(    /* OsApplication_C3 */  \
  /* Build ID */                                    &OS_OsApplication_C3GenBuildId,  \
  /* Startup Hook */                                OS_NULL,  \
  /* Shutdown Hook */                               OS_NULL,  \
  /* Error hook */                                  OS_NULL,  \
  /* start of data/bss */                           &OS_TOOL_MR_START(OsApplication_C3),  \
  /* end of data/bss */                             &OS_TOOL_MR_END(OsApplication_C3),  \
  /* start of initial data */                       &OS_TOOL_MR_LMA_START(OsApplication_C3),  \
  /* end of initial data */                         &OS_TOOL_MR_LMA_END(OsApplication_C3),  \
  /* Permission Bit */                              0x8,  \
  /* Accessing applications */                      0x8,  \
  /* Startup hook stack */                          0,  \
  /* Shutdown hook stack */                         0,  \
  /* Error hook stack */                            0,  \
  /* Restart Task */                                OS_NULLTASK,  \
  /* Flags */                                       (OS_APP_TRUSTED),  \
  /* Application ID */                              OsApplication_C3,  \
  /* dynamic data */                                &OS_appDynamic_core3[0],  \
  /* CPU core */                                    3,  \
    OS_ARCHAPP_INIT(  \
      /* Flags */                                   (OS_PSW_PRS_0|OS_PSW_IO_SU|OS_PSW_CDC_DIS)  \
    )  \
),  \
OS_APPCONFIG_INIT(    /* OsApplication_C4 */  \
  /* Build ID */                                    &OS_OsApplication_C4GenBuildId,  \
  /* Startup Hook */                                OS_NULL,  \
  /* Shutdown Hook */                               OS_NULL,  \
  /* Error hook */                                  OS_NULL,  \
  /* start of data/bss */                           &OS_TOOL_MR_START(OsApplication_C4),  \
  /* end of data/bss */                             &OS_TOOL_MR_END(OsApplication_C4),  \
  /* start of initial data */                       &OS_TOOL_MR_LMA_START(OsApplication_C4),  \
  /* end of initial data */                         &OS_TOOL_MR_LMA_END(OsApplication_C4),  \
  /* Permission Bit */                              0x10,  \
  /* Accessing applications */                      0x10,  \
  /* Startup hook stack */                          0,  \
  /* Shutdown hook stack */                         0,  \
  /* Error hook stack */                            0,  \
  /* Restart Task */                                OS_NULLTASK,  \
  /* Flags */                                       (OS_APP_TRUSTED),  \
  /* Application ID */                              OsApplication_C4,  \
  /* dynamic data */                                &OS_appDynamic_core4[0],  \
  /* CPU core */                                    4,  \
    OS_ARCHAPP_INIT(  \
      /* Flags */                                   (OS_PSW_PRS_0|OS_PSW_IO_SU|OS_PSW_CDC_DIS)  \
    )  \
),  \
OS_APPCONFIG_INIT(    /* OsApplication_C5 */  \
  /* Build ID */                                    &OS_OsApplication_C5GenBuildId,  \
  /* Startup Hook */                                OS_NULL,  \
  /* Shutdown Hook */                               OS_NULL,  \
  /* Error hook */                                  OS_NULL,  \
  /* start of data/bss */                           &OS_TOOL_MR_START(OsApplication_C5),  \
  /* end of data/bss */                             &OS_TOOL_MR_END(OsApplication_C5),  \
  /* start of initial data */                       &OS_TOOL_MR_LMA_START(OsApplication_C5),  \
  /* end of initial data */                         &OS_TOOL_MR_LMA_END(OsApplication_C5),  \
  /* Permission Bit */                              0x20,  \
  /* Accessing applications */                      0x20,  \
  /* Startup hook stack */                          0,  \
  /* Shutdown hook stack */                         0,  \
  /* Error hook stack */                            0,  \
  /* Restart Task */                                OS_NULLTASK,  \
  /* Flags */                                       (OS_APP_TRUSTED),  \
  /* Application ID */                              OsApplication_C5,  \
  /* dynamic data */                                &OS_appDynamic_core5[0],  \
  /* CPU core */                                    5,  \
    OS_ARCHAPP_INIT(  \
      /* Flags */                                   (OS_PSW_PRS_0|OS_PSW_IO_SU|OS_PSW_CDC_DIS)  \
    )  \
),  \
OS_APPCONFIG_INIT(    /* OS_SYSTEM_0 */  \
  /* Build ID */                                    &OS_OS_SYSTEM_0GenBuildId,  \
  /* Startup Hook */                                OS_NULL,  \
  /* Shutdown Hook */                               OS_NULL,  \
  /* Error hook */                                  OS_NULL,  \
  /* start of data/bss */                           OS_NULL,  \
  /* end of data/bss */                             OS_NULL,  \
  /* start of initial data */                       OS_NULL,  \
  /* end of initial data */                         OS_NULL,  \
  /* Permission Bit */                              0xfff,  \
  /* Accessing applications */                      0xfff,  \
  /* Startup hook stack */                          0,  \
  /* Shutdown hook stack */                         0,  \
  /* Error hook stack */                            0,  \
  /* Restart Task */                                OS_NULLTASK,  \
  /* Flags */                                       (OS_APP_TRUSTED|OS_APP_SYSTEM),  \
  /* Application ID */                              OS_SYSTEM_0,  \
  /* dynamic data */                                &OS_appDynamic_core0[1],  \
  /* CPU core */                                    0,  \
    OS_ARCHAPP_INIT(  \
      /* Flags */                                   (OS_PSW_PRS_0|OS_PSW_IO_SU|OS_PSW_CDC_DIS)  \
    )  \
),  \
OS_APPCONFIG_INIT(    /* OS_SYSTEM_1 */  \
  /* Build ID */                                    &OS_OS_SYSTEM_1GenBuildId,  \
  /* Startup Hook */                                OS_NULL,  \
  /* Shutdown Hook */                               OS_NULL,  \
  /* Error hook */                                  OS_NULL,  \
  /* start of data/bss */                           OS_NULL,  \
  /* end of data/bss */                             OS_NULL,  \
  /* start of initial data */                       OS_NULL,  \
  /* end of initial data */                         OS_NULL,  \
  /* Permission Bit */                              0xfff,  \
  /* Accessing applications */                      0xfff,  \
  /* Startup hook stack */                          0,  \
  /* Shutdown hook stack */                         0,  \
  /* Error hook stack */                            0,  \
  /* Restart Task */                                OS_NULLTASK,  \
  /* Flags */                                       (OS_APP_TRUSTED|OS_APP_SYSTEM),  \
  /* Application ID */                              OS_SYSTEM_1,  \
  /* dynamic data */                                &OS_appDynamic_core1[1],  \
  /* CPU core */                                    1,  \
    OS_ARCHAPP_INIT(  \
      /* Flags */                                   (OS_PSW_PRS_0|OS_PSW_IO_SU|OS_PSW_CDC_DIS)  \
    )  \
),  \
OS_APPCONFIG_INIT(    /* OS_SYSTEM_2 */  \
  /* Build ID */                                    &OS_OS_SYSTEM_2GenBuildId,  \
  /* Startup Hook */                                OS_NULL,  \
  /* Shutdown Hook */                               OS_NULL,  \
  /* Error hook */                                  OS_NULL,  \
  /* start of data/bss */                           OS_NULL,  \
  /* end of data/bss */                             OS_NULL,  \
  /* start of initial data */                       OS_NULL,  \
  /* end of initial data */                         OS_NULL,  \
  /* Permission Bit */                              0xfff,  \
  /* Accessing applications */                      0xfff,  \
  /* Startup hook stack */                          0,  \
  /* Shutdown hook stack */                         0,  \
  /* Error hook stack */                            0,  \
  /* Restart Task */                                OS_NULLTASK,  \
  /* Flags */                                       (OS_APP_TRUSTED|OS_APP_SYSTEM),  \
  /* Application ID */                              OS_SYSTEM_2,  \
  /* dynamic data */                                &OS_appDynamic_core2[1],  \
  /* CPU core */                                    2,  \
    OS_ARCHAPP_INIT(  \
      /* Flags */                                   (OS_PSW_PRS_0|OS_PSW_IO_SU|OS_PSW_CDC_DIS)  \
    )  \
),  \
OS_APPCONFIG_INIT(    /* OS_SYSTEM_3 */  \
  /* Build ID */                                    &OS_OS_SYSTEM_3GenBuildId,  \
  /* Startup Hook */                                OS_NULL,  \
  /* Shutdown Hook */                               OS_NULL,  \
  /* Error hook */                                  OS_NULL,  \
  /* start of data/bss */                           OS_NULL,  \
  /* end of data/bss */                             OS_NULL,  \
  /* start of initial data */                       OS_NULL,  \
  /* end of initial data */                         OS_NULL,  \
  /* Permission Bit */                              0xfff,  \
  /* Accessing applications */                      0xfff,  \
  /* Startup hook stack */                          0,  \
  /* Shutdown hook stack */                         0,  \
  /* Error hook stack */                            0,  \
  /* Restart Task */                                OS_NULLTASK,  \
  /* Flags */                                       (OS_APP_TRUSTED|OS_APP_SYSTEM),  \
  /* Application ID */                              OS_SYSTEM_3,  \
  /* dynamic data */                                &OS_appDynamic_core3[1],  \
  /* CPU core */                                    3,  \
    OS_ARCHAPP_INIT(  \
      /* Flags */                                   (OS_PSW_PRS_0|OS_PSW_IO_SU|OS_PSW_CDC_DIS)  \
    )  \
),  \
OS_APPCONFIG_INIT(    /* OS_SYSTEM_4 */  \
  /* Build ID */                                    &OS_OS_SYSTEM_4GenBuildId,  \
  /* Startup Hook */                                OS_NULL,  \
  /* Shutdown Hook */                               OS_NULL,  \
  /* Error hook */                                  OS_NULL,  \
  /* start of data/bss */                           OS_NULL,  \
  /* end of data/bss */                             OS_NULL,  \
  /* start of initial data */                       OS_NULL,  \
  /* end of initial data */                         OS_NULL,  \
  /* Permission Bit */                              0xfff,  \
  /* Accessing applications */                      0xfff,  \
  /* Startup hook stack */                          0,  \
  /* Shutdown hook stack */                         0,  \
  /* Error hook stack */                            0,  \
  /* Restart Task */                                OS_NULLTASK,  \
  /* Flags */                                       (OS_APP_TRUSTED|OS_APP_SYSTEM),  \
  /* Application ID */                              OS_SYSTEM_4,  \
  /* dynamic data */                                &OS_appDynamic_core4[1],  \
  /* CPU core */                                    4,  \
    OS_ARCHAPP_INIT(  \
      /* Flags */                                   (OS_PSW_PRS_0|OS_PSW_IO_SU|OS_PSW_CDC_DIS)  \
    )  \
),  \
OS_APPCONFIG_INIT(    /* OS_SYSTEM_5 */  \
  /* Build ID */                                    &OS_OS_SYSTEM_5GenBuildId,  \
  /* Startup Hook */                                OS_NULL,  \
  /* Shutdown Hook */                               OS_NULL,  \
  /* Error hook */                                  OS_NULL,  \
  /* start of data/bss */                           OS_NULL,  \
  /* end of data/bss */                             OS_NULL,  \
  /* start of initial data */                       OS_NULL,  \
  /* end of initial data */                         OS_NULL,  \
  /* Permission Bit */                              0xfff,  \
  /* Accessing applications */                      0xfff,  \
  /* Startup hook stack */                          0,  \
  /* Shutdown hook stack */                         0,  \
  /* Error hook stack */                            0,  \
  /* Restart Task */                                OS_NULLTASK,  \
  /* Flags */                                       (OS_APP_TRUSTED|OS_APP_SYSTEM),  \
  /* Application ID */                              OS_SYSTEM_5,  \
  /* dynamic data */                                &OS_appDynamic_core5[1],  \
  /* CPU core */                                    5,  \
    OS_ARCHAPP_INIT(  \
      /* Flags */                                   (OS_PSW_PRS_0|OS_PSW_IO_SU|OS_PSW_CDC_DIS)  \
    )  \
)

/* Trusted Functions */
#define OS_NFUNCTIONS  0

#define OS_SHOOKSTACKLEN  0
#define OS_EHOOKSTACKLEN  0
#define OS_NAPPS_CORE0    2
#define OS_NAPPS_CORE1    2
#define OS_NAPPS_CORE2    2
#define OS_NAPPS_CORE3    2
#define OS_NAPPS_CORE4    2
#define OS_NAPPS_CORE5    2

/*===================================================================
 * CPU Core configuration
 *==================================================================*/
#define OS_PROPERTIES_CORE0  (OS_U(0)|OS_COREPROP_USED_BIT)
#define OS_PROPERTIES_CORE1  (OS_U(0)|OS_COREPROP_USED_BIT)
#define OS_PROPERTIES_CORE2  (OS_U(0)|OS_COREPROP_USED_BIT)
#define OS_PROPERTIES_CORE3  (OS_U(0)|OS_COREPROP_USED_BIT)
#define OS_PROPERTIES_CORE4  (OS_U(0)|OS_COREPROP_USED_BIT)
#define OS_PROPERTIES_CORE5  (OS_U(0)|OS_COREPROP_USED_BIT)

/*===================================================================
 * Channel Initializers
 *==================================================================*/
#define OS_IOC_ENABLED  0

/*===================================================================
 * Configured Modes
 *==================================================================*/
#define OS_CONFIGMODE        (OS_ECC2|OS_SCHEDMIX|OS_EXTENDED|OS_STACKCHECK|OS_DBGPROT_FULL)
#define OS_IECMODE           (OS_IEC_AUTOSAR)
#define OS_HOOKSELECTION     (OS_ACTION_PROTECTIONHOOK|OS_ACTION_ERRORHOOK)
#define OS_PERMITTEDCONTEXT  (OS_permittedContextAutosar)
#define OS_INCLUDE_RTE       0

/*===================================================================
 * Counters
 *==================================================================*/
#define OS_NSHAREDHWCOUNTERTIMESTAMP         0
#define OS_SHAREDHWCOUNTERTIMESTAMP_ALARMID  -1
#define OS_SHAREDHWCOUNTERTIMESTAMP_COREID   -1
#define OS_NCOUNTERS    12
#define OS_NSWCOUNTERS  6

#define OS_COUNTER  OS_COUNTER_INIT(    /* HwCounter_C0 */  \
  /* Application id */       OsApplication_C0,  \
  /* Application pointer */  &OS_appTable[OsApplication_C0],  \
  /* Update function */      &OS_HwCounterUpdate,  \
  /* Permissions */          0x1u,  \
  /* Hardware timer */       &OS_hwTimer[0],  \
  /* Max allowed value */    (os_tick_t)4294967295u,  \
  /* Ticks per base */       (os_tick_t)1000u,  \
  /* Min cycle */            (os_tick_t)100u,  \
  /* dynamic data */         &OS_counterDynamic_core0[0]  \
),  \
OS_COUNTER_INIT(    /* Rte_Counter_C0 */  \
  /* Application id */       OsApplication_C0,  \
  /* Application pointer */  &OS_appTable[OsApplication_C0],  \
  /* Update function */      OS_NULL,  \
  /* Permissions */          0x1u,  \
  /* Hardware timer */       OS_NULL,  \
  /* Max allowed value */    (os_tick_t)4294967295u,  \
  /* Ticks per base */       (os_tick_t)1u,  \
  /* Min cycle */            (os_tick_t)1u,  \
  /* dynamic data */         &OS_counterDynamic_core0[1]  \
),  \
OS_COUNTER_INIT(    /* HwCounter_C1 */  \
  /* Application id */       OsApplication_C1,  \
  /* Application pointer */  &OS_appTable[OsApplication_C1],  \
  /* Update function */      &OS_HwCounterUpdate,  \
  /* Permissions */          0x2u,  \
  /* Hardware timer */       &OS_hwTimer[1],  \
  /* Max allowed value */    (os_tick_t)4294967295u,  \
  /* Ticks per base */       (os_tick_t)1000u,  \
  /* Min cycle */            (os_tick_t)100u,  \
  /* dynamic data */         &OS_counterDynamic_core1[0]  \
),  \
OS_COUNTER_INIT(    /* Rte_Counter_C1 */  \
  /* Application id */       OsApplication_C1,  \
  /* Application pointer */  &OS_appTable[OsApplication_C1],  \
  /* Update function */      OS_NULL,  \
  /* Permissions */          0x2u,  \
  /* Hardware timer */       OS_NULL,  \
  /* Max allowed value */    (os_tick_t)4294967295u,  \
  /* Ticks per base */       (os_tick_t)1u,  \
  /* Min cycle */            (os_tick_t)1u,  \
  /* dynamic data */         &OS_counterDynamic_core1[1]  \
),  \
OS_COUNTER_INIT(    /* HwCounter_C2 */  \
  /* Application id */       OsApplication_C2,  \
  /* Application pointer */  &OS_appTable[OsApplication_C2],  \
  /* Update function */      &OS_HwCounterUpdate,  \
  /* Permissions */          0x4u,  \
  /* Hardware timer */       &OS_hwTimer[2],  \
  /* Max allowed value */    (os_tick_t)4294967295u,  \
  /* Ticks per base */       (os_tick_t)1000u,  \
  /* Min cycle */            (os_tick_t)100u,  \
  /* dynamic data */         &OS_counterDynamic_core2[0]  \
),  \
OS_COUNTER_INIT(    /* Rte_Counter_C2 */  \
  /* Application id */       OsApplication_C2,  \
  /* Application pointer */  &OS_appTable[OsApplication_C2],  \
  /* Update function */      OS_NULL,  \
  /* Permissions */          0x4u,  \
  /* Hardware timer */       OS_NULL,  \
  /* Max allowed value */    (os_tick_t)4294967295u,  \
  /* Ticks per base */       (os_tick_t)1u,  \
  /* Min cycle */            (os_tick_t)1u,  \
  /* dynamic data */         &OS_counterDynamic_core2[1]  \
),  \
OS_COUNTER_INIT(    /* HwCounter_C3 */  \
  /* Application id */       OsApplication_C3,  \
  /* Application pointer */  &OS_appTable[OsApplication_C3],  \
  /* Update function */      &OS_HwCounterUpdate,  \
  /* Permissions */          0x8u,  \
  /* Hardware timer */       &OS_hwTimer[3],  \
  /* Max allowed value */    (os_tick_t)4294967295u,  \
  /* Ticks per base */       (os_tick_t)1000u,  \
  /* Min cycle */            (os_tick_t)100u,  \
  /* dynamic data */         &OS_counterDynamic_core3[0]  \
),  \
OS_COUNTER_INIT(    /* Rte_Counter_C3 */  \
  /* Application id */       OsApplication_C3,  \
  /* Application pointer */  &OS_appTable[OsApplication_C3],  \
  /* Update function */      OS_NULL,  \
  /* Permissions */          0x8u,  \
  /* Hardware timer */       OS_NULL,  \
  /* Max allowed value */    (os_tick_t)4294967295u,  \
  /* Ticks per base */       (os_tick_t)1u,  \
  /* Min cycle */            (os_tick_t)1u,  \
  /* dynamic data */         &OS_counterDynamic_core3[1]  \
),  \
OS_COUNTER_INIT(    /* HwCounter_C4 */  \
  /* Application id */       OsApplication_C4,  \
  /* Application pointer */  &OS_appTable[OsApplication_C4],  \
  /* Update function */      &OS_HwCounterUpdate,  \
  /* Permissions */          0x10u,  \
  /* Hardware timer */       &OS_hwTimer[4],  \
  /* Max allowed value */    (os_tick_t)4294967295u,  \
  /* Ticks per base */       (os_tick_t)1000u,  \
  /* Min cycle */            (os_tick_t)100u,  \
  /* dynamic data */         &OS_counterDynamic_core4[0]  \
),  \
OS_COUNTER_INIT(    /* Rte_Counter_C4 */  \
  /* Application id */       OsApplication_C4,  \
  /* Application pointer */  &OS_appTable[OsApplication_C4],  \
  /* Update function */      OS_NULL,  \
  /* Permissions */          0x10u,  \
  /* Hardware timer */       OS_NULL,  \
  /* Max allowed value */    (os_tick_t)4294967295u,  \
  /* Ticks per base */       (os_tick_t)1u,  \
  /* Min cycle */            (os_tick_t)1u,  \
  /* dynamic data */         &OS_counterDynamic_core4[1]  \
),  \
OS_COUNTER_INIT(    /* HwCounter_C5 */  \
  /* Application id */       OsApplication_C5,  \
  /* Application pointer */  &OS_appTable[OsApplication_C5],  \
  /* Update function */      &OS_HwCounterUpdate,  \
  /* Permissions */          0x20u,  \
  /* Hardware timer */       &OS_hwTimer[5],  \
  /* Max allowed value */    (os_tick_t)4294967295u,  \
  /* Ticks per base */       (os_tick_t)1000u,  \
  /* Min cycle */            (os_tick_t)100u,  \
  /* dynamic data */         &OS_counterDynamic_core5[0]  \
),  \
OS_COUNTER_INIT(    /* Rte_Counter_C5 */  \
  /* Application id */       OsApplication_C5,  \
  /* Application pointer */  &OS_appTable[OsApplication_C5],  \
  /* Update function */      OS_NULL,  \
  /* Permissions */          0x20u,  \
  /* Hardware timer */       OS_NULL,  \
  /* Max allowed value */    (os_tick_t)4294967295u,  \
  /* Ticks per base */       (os_tick_t)1u,  \
  /* Min cycle */            (os_tick_t)1u,  \
  /* dynamic data */         &OS_counterDynamic_core5[1]  \
)

#define OS_NINTERNALTICKERS  0
/* Number of counters available on cores */
#define OS_NCOUNTERS_CORE0  2
#define OS_NCOUNTERS_CORE1  2
#define OS_NCOUNTERS_CORE2  2
#define OS_NCOUNTERS_CORE3  2
#define OS_NCOUNTERS_CORE4  2
#define OS_NCOUNTERS_CORE5  2

/*===================================================================
 * Events
 *==================================================================*/
#define OS_NEVENTS  13

/*===================================================================
 * Execution timer
 *==================================================================*/
#define OS_EXECUTIONTIMER_INIT     /* Execution timer init */  \
  OS_NULL, \
  OS_NULL, \
  OS_NULL, \
  OS_NULL, \
  OS_NULL, \
  OS_NULL

/*===================================================================
 * Time-stamp timer
 *==================================================================*/

/*===================================================================
 * Hardware Timers
 *==================================================================*/
#define OS_NHWTIMERS        6
#define OS_NHWTIMERS_CORE0  1
#define OS_NHWTIMERS_CORE1  1
#define OS_NHWTIMERS_CORE2  1
#define OS_NHWTIMERS_CORE3  1
#define OS_NHWTIMERS_CORE4  1
#define OS_NHWTIMERS_CORE5  1

#define OS_HWTIMER {    /* STM0_T0 */  \
  /* Driver table */                     &OS_stmDriver,  \
  /* HwTimer Last Value */               &OS_hwtLastValue_core0[0],  \
  /* Max delta */                        3221225472u,  \
  /* Default delta if max exceeded */    2147483648u,  \
  /* Wrap mask */                        4294967295u,  \
  /* Driver number */                    0u,  \
  /* Driver channel */                   0u,  \
  /* core */                             0u,  \
},  \
{    /* STM1_T0 */  \
  /* Driver table */                     &OS_stmDriver,  \
  /* HwTimer Last Value */               &OS_hwtLastValue_core1[0],  \
  /* Max delta */                        3221225472u,  \
  /* Default delta if max exceeded */    2147483648u,  \
  /* Wrap mask */                        4294967295u,  \
  /* Driver number */                    1u,  \
  /* Driver channel */                   0u,  \
  /* core */                             1u,  \
},  \
{    /* STM2_T0 */  \
  /* Driver table */                     &OS_stmDriver,  \
  /* HwTimer Last Value */               &OS_hwtLastValue_core2[0],  \
  /* Max delta */                        3221225472u,  \
  /* Default delta if max exceeded */    2147483648u,  \
  /* Wrap mask */                        4294967295u,  \
  /* Driver number */                    2u,  \
  /* Driver channel */                   0u,  \
  /* core */                             2u,  \
},  \
{    /* STM3_T0 */  \
  /* Driver table */                     &OS_stmDriver,  \
  /* HwTimer Last Value */               &OS_hwtLastValue_core3[0],  \
  /* Max delta */                        3221225472u,  \
  /* Default delta if max exceeded */    2147483648u,  \
  /* Wrap mask */                        4294967295u,  \
  /* Driver number */                    3u,  \
  /* Driver channel */                   0u,  \
  /* core */                             3u,  \
},  \
{    /* STM4_T0 */  \
  /* Driver table */                     &OS_stmDriver,  \
  /* HwTimer Last Value */               &OS_hwtLastValue_core4[0],  \
  /* Max delta */                        3221225472u,  \
  /* Default delta if max exceeded */    2147483648u,  \
  /* Wrap mask */                        4294967295u,  \
  /* Driver number */                    4u,  \
  /* Driver channel */                   0u,  \
  /* core */                             4u,  \
},  \
{    /* STM5_T0 */  \
  /* Driver table */                     &OS_stmDriver,  \
  /* HwTimer Last Value */               &OS_hwtLastValue_core5[0],  \
  /* Max delta */                        3221225472u,  \
  /* Default delta if max exceeded */    2147483648u,  \
  /* Wrap mask */                        4294967295u,  \
  /* Driver number */                    5u,  \
  /* Driver channel */                   0u,  \
  /* core */                             5u,  \
}

/*===================================================================
 * Hook Functions
 *==================================================================*/
#define OS_ERRORHOOK       &ErrorHook
#define OS_SHUTDOWNHOOK    &ShutdownHook
#define OS_PROTECTIONHOOK  &ProtectionHook

/*===================================================================
 * Interrupts
 *==================================================================*/
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(ETHSR0_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(ETHSR0_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(ETHSR0_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(ETHSR0_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(ETHSR2_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(ETHSR2_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(ETHSR2_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(ETHSR2_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(ETHSR6_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(ETHSR6_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(ETHSR6_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(ETHSR6_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(DMACH0SR_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(DMACH0SR_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(DMACH0SR_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(DMACH0SR_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(DMACH1SR_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(DMACH1SR_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(DMACH1SR_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(DMACH1SR_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(QSPI0PT_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(QSPI0PT_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(QSPI0PT_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(QSPI0PT_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(QSPI0ERR_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(QSPI0ERR_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(QSPI0ERR_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(QSPI0ERR_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(DMACH5SR_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(DMACH5SR_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(DMACH5SR_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(DMACH5SR_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(DMACH6SR_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(DMACH6SR_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(DMACH6SR_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(DMACH6SR_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(CAN0SR12_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(CAN0SR12_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(CAN0SR12_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(CAN0SR12_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(CAN0SR13_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(CAN0SR13_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(CAN0SR13_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(CAN0SR13_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(CAN0SR14_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(CAN0SR14_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(CAN0SR14_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(CAN0SR14_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(CAN0SR15_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(CAN0SR15_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(CAN0SR15_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(CAN0SR15_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(CAN1SR0_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(CAN1SR0_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(CAN1SR0_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(CAN1SR0_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(CAN1SR1_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(CAN1SR1_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(CAN1SR1_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(CAN1SR1_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(CAN1SR2_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(CAN1SR2_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(CAN1SR2_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(CAN1SR2_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(CAN1SR3_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(CAN1SR3_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(CAN1SR3_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(CAN1SR3_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(GPT12_T2_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(GPT12_T2_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(GPT12_T2_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(GPT12_T2_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(GPT12_T3_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(GPT12_T3_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(GPT12_T3_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(GPT12_T3_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(GPT12_T6_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(GPT12_T6_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(GPT12_T6_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(GPT12_T6_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EmUSS01_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EmUSS01_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EmUSS01_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EmUSS01_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EmUSS02_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EmUSS02_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EmUSS02_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EmUSS02_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EmUSS03_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EmUSS03_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EmUSS03_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EmUSS03_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EmUSS04_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EmUSS04_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EmUSS04_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EmUSS04_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EmUSS05_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EmUSS05_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EmUSS05_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EmUSS05_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EmUSS06_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EmUSS06_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EmUSS06_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EmUSS06_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EmUSS07_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EmUSS07_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EmUSS07_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EmUSS07_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EmUSS08_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EmUSS08_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EmUSS08_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EmUSS08_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EmUSS09_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EmUSS09_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EmUSS09_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EmUSS09_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EmUSS10_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EmUSS10_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EmUSS10_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EmUSS10_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EmUSS11_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EmUSS11_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EmUSS11_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EmUSS11_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EmUSS12_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EmUSS12_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EmUSS12_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EmUSS12_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */

#define OS_NINTERRUPTS         44
#define OS_NCAT1_INTERRUPTS    12
#define OS_NCAT2_INTERRUPTS    26
#define OS_NCATK_INTERRUPTS    0
#define OS_NCAT2K_INTERRUPTS   0
#define OS_NISRSEXECTIMELIMIT  0
#define OS_NISRSINTLOCKLIMIT   0
#define OS_NISRSRESLOCKLIMIT   0
#define OS_NISRACCOUNTING      0
#define OS_CAT1LOCK            44
#define OS_CAT2LOCK            26
#define OS_KERNLOCK            32
#define OS_XCOREUNLOCK         31
#define OS_ENABLEALLLOCK       1

/* Internal Interrupt Ids */
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CrossCoreNotify0  32
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CrossCoreNotify1  33
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CrossCoreNotify2  34
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CrossCoreNotify3  35
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CrossCoreNotify4  36
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CrossCoreNotify5  37
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Os_Counter_STM0_T0  38
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Os_Counter_STM1_T0  39
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Os_Counter_STM2_T0  40
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Os_Counter_STM3_T0  41
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Os_Counter_STM4_T0  42
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Os_Counter_STM5_T0  43
#endif

/* Isr Config Struct Init Macros. */
#define OS_ISRCONFIG  OS_ISRCONFIG_INIT(    /* ETHSR0_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(ETHSR0_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(ETHSR0_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(ETHSR0_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(ETHSR0_ISR),  \
  /* Interrupt entry */                   &OS_ISR_ETHSR0_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        4096u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            ETHSR0_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core0[0],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_GETH0,  \
      /* Arbitration priority */          7,  \
      /* Run priority */                  7  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* ETHSR2_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(ETHSR2_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(ETHSR2_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(ETHSR2_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(ETHSR2_ISR),  \
  /* Interrupt entry */                   &OS_ISR_ETHSR2_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        4096u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            ETHSR2_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core0[1],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_GETH2,  \
      /* Arbitration priority */          8,  \
      /* Run priority */                  8  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* ETHSR6_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(ETHSR6_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(ETHSR6_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(ETHSR6_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(ETHSR6_ISR),  \
  /* Interrupt entry */                   &OS_ISR_ETHSR6_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        4096u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            ETHSR6_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core0[2],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_GETH6,  \
      /* Arbitration priority */          9,  \
      /* Run priority */                  9  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* DMACH0SR_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(DMACH0SR_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(DMACH0SR_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(DMACH0SR_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(DMACH0SR_ISR),  \
  /* Interrupt entry */                   &OS_ISR_DMACH0SR_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        2048u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            DMACH0SR_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core0[3],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_DMACH0,  \
      /* Arbitration priority */          10,  \
      /* Run priority */                  10  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* DMACH1SR_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(DMACH1SR_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(DMACH1SR_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(DMACH1SR_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(DMACH1SR_ISR),  \
  /* Interrupt entry */                   &OS_ISR_DMACH1SR_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        2048u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            DMACH1SR_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core0[4],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_DMACH1,  \
      /* Arbitration priority */          11,  \
      /* Run priority */                  11  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* QSPI0PT_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(QSPI0PT_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(QSPI0PT_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(QSPI0PT_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(QSPI0PT_ISR),  \
  /* Interrupt entry */                   &OS_ISR_QSPI0PT_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        2048u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            QSPI0PT_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core0[5],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_QSPI0PT,  \
      /* Arbitration priority */          12,  \
      /* Run priority */                  12  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* QSPI0ERR_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(QSPI0ERR_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(QSPI0ERR_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(QSPI0ERR_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(QSPI0ERR_ISR),  \
  /* Interrupt entry */                   &OS_ISR_QSPI0ERR_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        2048u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            QSPI0ERR_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core0[6],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_QSPI0ERR,  \
      /* Arbitration priority */          13,  \
      /* Run priority */                  13  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* DMACH5SR_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(DMACH5SR_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(DMACH5SR_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(DMACH5SR_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(DMACH5SR_ISR),  \
  /* Interrupt entry */                   &OS_ISR_DMACH5SR_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        2048u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            DMACH5SR_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core0[7],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_DMACH5,  \
      /* Arbitration priority */          14,  \
      /* Run priority */                  14  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* DMACH6SR_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(DMACH6SR_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(DMACH6SR_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(DMACH6SR_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(DMACH6SR_ISR),  \
  /* Interrupt entry */                   &OS_ISR_DMACH6SR_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        2048u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            DMACH6SR_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core0[8],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_DMACH6,  \
      /* Arbitration priority */          15,  \
      /* Run priority */                  15  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN0SR12_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(CAN0SR12_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(CAN0SR12_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(CAN0SR12_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(CAN0SR12_ISR),  \
  /* Interrupt entry */                   &OS_ISR_CAN0SR12_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        1024u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            CAN0SR12_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core0[9],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_CAN0INT12,  \
      /* Arbitration priority */          16,  \
      /* Run priority */                  16  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN0SR13_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(CAN0SR13_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(CAN0SR13_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(CAN0SR13_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(CAN0SR13_ISR),  \
  /* Interrupt entry */                   &OS_ISR_CAN0SR13_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        1024u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            CAN0SR13_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core0[10],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_CAN0INT13,  \
      /* Arbitration priority */          17,  \
      /* Run priority */                  17  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN0SR14_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(CAN0SR14_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(CAN0SR14_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(CAN0SR14_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(CAN0SR14_ISR),  \
  /* Interrupt entry */                   &OS_ISR_CAN0SR14_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        1024u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            CAN0SR14_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core0[11],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_CAN0INT14,  \
      /* Arbitration priority */          18,  \
      /* Run priority */                  18  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN0SR15_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(CAN0SR15_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(CAN0SR15_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(CAN0SR15_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(CAN0SR15_ISR),  \
  /* Interrupt entry */                   &OS_ISR_CAN0SR15_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        1024u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            CAN0SR15_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core0[12],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_CAN0INT15,  \
      /* Arbitration priority */          19,  \
      /* Run priority */                  19  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN1SR0_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(CAN1SR0_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(CAN1SR0_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(CAN1SR0_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(CAN1SR0_ISR),  \
  /* Interrupt entry */                   &OS_ISR_CAN1SR0_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        1024u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            CAN1SR0_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core0[13],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_CAN1INT0,  \
      /* Arbitration priority */          20,  \
      /* Run priority */                  20  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN1SR1_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(CAN1SR1_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(CAN1SR1_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(CAN1SR1_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(CAN1SR1_ISR),  \
  /* Interrupt entry */                   &OS_ISR_CAN1SR1_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        1024u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            CAN1SR1_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core0[14],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_CAN1INT1,  \
      /* Arbitration priority */          21,  \
      /* Run priority */                  21  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN1SR2_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(CAN1SR2_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(CAN1SR2_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(CAN1SR2_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(CAN1SR2_ISR),  \
  /* Interrupt entry */                   &OS_ISR_CAN1SR2_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        1024u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            CAN1SR2_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core0[15],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_CAN1INT2,  \
      /* Arbitration priority */          22,  \
      /* Run priority */                  22  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN1SR3_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(CAN1SR3_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(CAN1SR3_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(CAN1SR3_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(CAN1SR3_ISR),  \
  /* Interrupt entry */                   &OS_ISR_CAN1SR3_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        1024u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            CAN1SR3_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core0[16],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_CAN1INT3,  \
      /* Arbitration priority */          23,  \
      /* Run priority */                  23  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* GPT12_T2_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(GPT12_T2_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(GPT12_T2_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(GPT12_T2_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(GPT12_T2_ISR),  \
  /* Interrupt entry */                   &OS_ISR_GPT12_T2_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        512u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            GPT12_T2_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core0[17],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_GPT120T2,  \
      /* Arbitration priority */          24,  \
      /* Run priority */                  24  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* GPT12_T3_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(GPT12_T3_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(GPT12_T3_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(GPT12_T3_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(GPT12_T3_ISR),  \
  /* Interrupt entry */                   &OS_ISR_GPT12_T3_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        512u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            GPT12_T3_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core0[18],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_GPT120T3,  \
      /* Arbitration priority */          25,  \
      /* Run priority */                  25  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* GPT12_T6_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(GPT12_T6_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(GPT12_T6_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(GPT12_T6_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(GPT12_T6_ISR),  \
  /* Interrupt entry */                   &OS_ISR_GPT12_T6_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        512u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            GPT12_T6_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core0[19],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_GPT120T6,  \
      /* Arbitration priority */          26,  \
      /* Run priority */                  26  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* EmUSS01_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C1],  \
  /* Permissions */                       0x2u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(EmUSS01_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(EmUSS01_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(EmUSS01_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(EmUSS01_ISR),  \
  /* Interrupt entry */                   &OS_ISR_EmUSS01_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        256u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            EmUSS01_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core1[0],  \
  /* Flags */                             (OS_ISRF_CAT1|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_DMACH61,  \
      /* Arbitration priority */          33,  \
      /* Run priority */                  44  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* EmUSS02_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C1],  \
  /* Permissions */                       0x2u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(EmUSS02_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(EmUSS02_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(EmUSS02_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(EmUSS02_ISR),  \
  /* Interrupt entry */                   &OS_ISR_EmUSS02_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        256u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            EmUSS02_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core1[1],  \
  /* Flags */                             (OS_ISRF_CAT1|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_DMACH62,  \
      /* Arbitration priority */          34,  \
      /* Run priority */                  44  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* EmUSS03_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C1],  \
  /* Permissions */                       0x2u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(EmUSS03_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(EmUSS03_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(EmUSS03_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(EmUSS03_ISR),  \
  /* Interrupt entry */                   &OS_ISR_EmUSS03_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        256u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            EmUSS03_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core1[2],  \
  /* Flags */                             (OS_ISRF_CAT1|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_DMACH63,  \
      /* Arbitration priority */          35,  \
      /* Run priority */                  44  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* EmUSS04_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C1],  \
  /* Permissions */                       0x2u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(EmUSS04_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(EmUSS04_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(EmUSS04_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(EmUSS04_ISR),  \
  /* Interrupt entry */                   &OS_ISR_EmUSS04_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        256u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            EmUSS04_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core1[3],  \
  /* Flags */                             (OS_ISRF_CAT1|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_DMACH64,  \
      /* Arbitration priority */          36,  \
      /* Run priority */                  44  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* EmUSS05_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C1],  \
  /* Permissions */                       0x2u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(EmUSS05_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(EmUSS05_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(EmUSS05_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(EmUSS05_ISR),  \
  /* Interrupt entry */                   &OS_ISR_EmUSS05_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        256u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            EmUSS05_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core1[4],  \
  /* Flags */                             (OS_ISRF_CAT1|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_DMACH65,  \
      /* Arbitration priority */          37,  \
      /* Run priority */                  44  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* EmUSS06_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C1],  \
  /* Permissions */                       0x2u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(EmUSS06_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(EmUSS06_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(EmUSS06_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(EmUSS06_ISR),  \
  /* Interrupt entry */                   &OS_ISR_EmUSS06_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        256u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            EmUSS06_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core1[5],  \
  /* Flags */                             (OS_ISRF_CAT1|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_DMACH66,  \
      /* Arbitration priority */          38,  \
      /* Run priority */                  44  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* EmUSS07_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C1],  \
  /* Permissions */                       0x2u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(EmUSS07_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(EmUSS07_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(EmUSS07_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(EmUSS07_ISR),  \
  /* Interrupt entry */                   &OS_ISR_EmUSS07_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        256u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            EmUSS07_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core1[6],  \
  /* Flags */                             (OS_ISRF_CAT1|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_DMACH67,  \
      /* Arbitration priority */          39,  \
      /* Run priority */                  44  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* EmUSS08_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C1],  \
  /* Permissions */                       0x2u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(EmUSS08_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(EmUSS08_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(EmUSS08_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(EmUSS08_ISR),  \
  /* Interrupt entry */                   &OS_ISR_EmUSS08_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        256u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            EmUSS08_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core1[7],  \
  /* Flags */                             (OS_ISRF_CAT1|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_DMACH68,  \
      /* Arbitration priority */          40,  \
      /* Run priority */                  44  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* EmUSS09_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C1],  \
  /* Permissions */                       0x2u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(EmUSS09_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(EmUSS09_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(EmUSS09_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(EmUSS09_ISR),  \
  /* Interrupt entry */                   &OS_ISR_EmUSS09_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        256u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            EmUSS09_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core1[8],  \
  /* Flags */                             (OS_ISRF_CAT1|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_DMACH69,  \
      /* Arbitration priority */          41,  \
      /* Run priority */                  44  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* EmUSS10_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C1],  \
  /* Permissions */                       0x2u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(EmUSS10_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(EmUSS10_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(EmUSS10_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(EmUSS10_ISR),  \
  /* Interrupt entry */                   &OS_ISR_EmUSS10_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        256u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            EmUSS10_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core1[9],  \
  /* Flags */                             (OS_ISRF_CAT1|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_DMACH70,  \
      /* Arbitration priority */          42,  \
      /* Run priority */                  44  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* EmUSS11_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C1],  \
  /* Permissions */                       0x2u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(EmUSS11_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(EmUSS11_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(EmUSS11_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(EmUSS11_ISR),  \
  /* Interrupt entry */                   &OS_ISR_EmUSS11_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        256u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            EmUSS11_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core1[10],  \
  /* Flags */                             (OS_ISRF_CAT1|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_DMACH71,  \
      /* Arbitration priority */          43,  \
      /* Run priority */                  44  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* EmUSS12_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_C1],  \
  /* Permissions */                       0x2u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(EmUSS12_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(EmUSS12_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(EmUSS12_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(EmUSS12_ISR),  \
  /* Interrupt entry */                   &OS_ISR_EmUSS12_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        256u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            EmUSS12_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core1[11],  \
  /* Flags */                             (OS_ISRF_CAT1|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_DMACH72,  \
      /* Arbitration priority */          44,  \
      /* Run priority */                  44  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CrossCoreNotify0 */  \
  /* Application */                       &OS_appTable[OS_SYSTEM_0],  \
  /* Permissions */                       0xfffu,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 OS_NULL,  \
  /* end of data/bss */                   OS_NULL,  \
  /* start of initial data */             OS_NULL,  \
  /* end of initial data */               OS_NULL,  \
  /* Interrupt entry */                   &OS_NullFunction,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        200u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            CrossCoreNotify0,  \
  /* dynamic data */                      &OS_isrDynamic_core0[20],  \
  /* Flags */                             (OS_ISRF_CATK|OS_ISRF_CROSSCORE|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_GPSR20,  \
      /* Arbitration priority */          32,  \
      /* Run priority */                  32  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CrossCoreNotify1 */  \
  /* Application */                       &OS_appTable[OS_SYSTEM_1],  \
  /* Permissions */                       0xfffu,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 OS_NULL,  \
  /* end of data/bss */                   OS_NULL,  \
  /* start of initial data */             OS_NULL,  \
  /* end of initial data */               OS_NULL,  \
  /* Interrupt entry */                   &OS_NullFunction,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        200u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            CrossCoreNotify1,  \
  /* dynamic data */                      &OS_isrDynamic_core1[12],  \
  /* Flags */                             (OS_ISRF_CATK|OS_ISRF_CROSSCORE|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_GPSR21,  \
      /* Arbitration priority */          32,  \
      /* Run priority */                  32  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CrossCoreNotify2 */  \
  /* Application */                       &OS_appTable[OS_SYSTEM_2],  \
  /* Permissions */                       0xfffu,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 OS_NULL,  \
  /* end of data/bss */                   OS_NULL,  \
  /* start of initial data */             OS_NULL,  \
  /* end of initial data */               OS_NULL,  \
  /* Interrupt entry */                   &OS_NullFunction,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        200u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            CrossCoreNotify2,  \
  /* dynamic data */                      &OS_isrDynamic_core2[0],  \
  /* Flags */                             (OS_ISRF_CATK|OS_ISRF_CROSSCORE|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_GPSR22,  \
      /* Arbitration priority */          32,  \
      /* Run priority */                  32  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CrossCoreNotify3 */  \
  /* Application */                       &OS_appTable[OS_SYSTEM_3],  \
  /* Permissions */                       0xfffu,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 OS_NULL,  \
  /* end of data/bss */                   OS_NULL,  \
  /* start of initial data */             OS_NULL,  \
  /* end of initial data */               OS_NULL,  \
  /* Interrupt entry */                   &OS_NullFunction,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        200u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            CrossCoreNotify3,  \
  /* dynamic data */                      &OS_isrDynamic_core3[0],  \
  /* Flags */                             (OS_ISRF_CATK|OS_ISRF_CROSSCORE|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_GPSR37,  \
      /* Arbitration priority */          32,  \
      /* Run priority */                  32  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CrossCoreNotify4 */  \
  /* Application */                       &OS_appTable[OS_SYSTEM_4],  \
  /* Permissions */                       0xfffu,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 OS_NULL,  \
  /* end of data/bss */                   OS_NULL,  \
  /* start of initial data */             OS_NULL,  \
  /* end of initial data */               OS_NULL,  \
  /* Interrupt entry */                   &OS_NullFunction,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        200u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            CrossCoreNotify4,  \
  /* dynamic data */                      &OS_isrDynamic_core4[0],  \
  /* Flags */                             (OS_ISRF_CATK|OS_ISRF_CROSSCORE|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_GPSR41,  \
      /* Arbitration priority */          32,  \
      /* Run priority */                  32  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CrossCoreNotify5 */  \
  /* Application */                       &OS_appTable[OS_SYSTEM_5],  \
  /* Permissions */                       0xfffu,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 OS_NULL,  \
  /* end of data/bss */                   OS_NULL,  \
  /* start of initial data */             OS_NULL,  \
  /* end of initial data */               OS_NULL,  \
  /* Interrupt entry */                   &OS_NullFunction,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        200u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            CrossCoreNotify5,  \
  /* dynamic data */                      &OS_isrDynamic_core5[0],  \
  /* Flags */                             (OS_ISRF_CATK|OS_ISRF_CROSSCORE|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_GPSR42,  \
      /* Arbitration priority */          32,  \
      /* Run priority */                  32  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* Os_Counter_STM0_T0 */  \
  /* Application */                       &OS_appTable[OS_SYSTEM_0],  \
  /* Permissions */                       0xfffu,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 OS_NULL,  \
  /* end of data/bss */                   OS_NULL,  \
  /* start of initial data */             OS_NULL,  \
  /* end of initial data */               OS_NULL,  \
  /* Interrupt entry */                   &OS_CounterIsr_HwCounter_C0,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        160u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            Os_Counter_STM0_T0,  \
  /* dynamic data */                      &OS_isrDynamic_core0[21],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_STM0SR0,  \
      /* Arbitration priority */          1,  \
      /* Run priority */                  6  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* Os_Counter_STM1_T0 */  \
  /* Application */                       &OS_appTable[OS_SYSTEM_1],  \
  /* Permissions */                       0xfffu,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 OS_NULL,  \
  /* end of data/bss */                   OS_NULL,  \
  /* start of initial data */             OS_NULL,  \
  /* end of initial data */               OS_NULL,  \
  /* Interrupt entry */                   &OS_CounterIsr_HwCounter_C1,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        160u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            Os_Counter_STM1_T0,  \
  /* dynamic data */                      &OS_isrDynamic_core1[13],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_STM1SR0,  \
      /* Arbitration priority */          2,  \
      /* Run priority */                  6  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* Os_Counter_STM2_T0 */  \
  /* Application */                       &OS_appTable[OS_SYSTEM_2],  \
  /* Permissions */                       0xfffu,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 OS_NULL,  \
  /* end of data/bss */                   OS_NULL,  \
  /* start of initial data */             OS_NULL,  \
  /* end of initial data */               OS_NULL,  \
  /* Interrupt entry */                   &OS_CounterIsr_HwCounter_C2,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        160u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            Os_Counter_STM2_T0,  \
  /* dynamic data */                      &OS_isrDynamic_core2[1],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_STM2SR0,  \
      /* Arbitration priority */          3,  \
      /* Run priority */                  6  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* Os_Counter_STM3_T0 */  \
  /* Application */                       &OS_appTable[OS_SYSTEM_3],  \
  /* Permissions */                       0xfffu,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 OS_NULL,  \
  /* end of data/bss */                   OS_NULL,  \
  /* start of initial data */             OS_NULL,  \
  /* end of initial data */               OS_NULL,  \
  /* Interrupt entry */                   &OS_CounterIsr_HwCounter_C3,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        160u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            Os_Counter_STM3_T0,  \
  /* dynamic data */                      &OS_isrDynamic_core3[1],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_STM3SR0,  \
      /* Arbitration priority */          4,  \
      /* Run priority */                  6  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* Os_Counter_STM4_T0 */  \
  /* Application */                       &OS_appTable[OS_SYSTEM_4],  \
  /* Permissions */                       0xfffu,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 OS_NULL,  \
  /* end of data/bss */                   OS_NULL,  \
  /* start of initial data */             OS_NULL,  \
  /* end of initial data */               OS_NULL,  \
  /* Interrupt entry */                   &OS_CounterIsr_HwCounter_C4,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        160u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            Os_Counter_STM4_T0,  \
  /* dynamic data */                      &OS_isrDynamic_core4[1],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_STM4SR0,  \
      /* Arbitration priority */          5,  \
      /* Run priority */                  6  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* Os_Counter_STM5_T0 */  \
  /* Application */                       &OS_appTable[OS_SYSTEM_5],  \
  /* Permissions */                       0xfffu,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 OS_NULL,  \
  /* end of data/bss */                   OS_NULL,  \
  /* start of initial data */             OS_NULL,  \
  /* end of initial data */               OS_NULL,  \
  /* Interrupt entry */                   &OS_CounterIsr_HwCounter_C5,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        160u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            Os_Counter_STM5_T0,  \
  /* dynamic data */                      &OS_isrDynamic_core5[1],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* Service request node */          &OS_SRC_STM5SR0,  \
      /* Arbitration priority */          6,  \
      /* Run priority */                  6  \
    )  \
)

/* Stack Macros */
#define OS_ISTACKBASE_0          OS_kernStack0
#define OS_ISTACKLEN_0           OS_U( 35968 )
#define OS_ISTACKBASE_1          OS_kernStack1
#define OS_ISTACKLEN_1           OS_U( 1848 )
#define OS_ISTACKBASE_2          OS_kernStack2
#define OS_ISTACKLEN_2           OS_U( 1584 )
#define OS_ISTACKBASE_3          OS_kernStack3
#define OS_ISTACKLEN_3           OS_U( 1584 )
#define OS_ISTACKBASE_4          OS_kernStack4
#define OS_ISTACKLEN_4           OS_U( 1584 )
#define OS_ISTACKBASE_5          OS_kernStack5
#define OS_ISTACKLEN_5           OS_U( 1584 )
#define OS_NINTERRUPTS_CORE0     22
#define OS_NISRACCOUNTING_CORE0  0
#define OS_NINTERRUPTS_CORE1     14
#define OS_NISRACCOUNTING_CORE1  0
#define OS_NINTERRUPTS_CORE2     2
#define OS_NISRACCOUNTING_CORE2  0
#define OS_NINTERRUPTS_CORE3     2
#define OS_NISRACCOUNTING_CORE3  0
#define OS_NINTERRUPTS_CORE4     2
#define OS_NISRACCOUNTING_CORE4  0
#define OS_NINTERRUPTS_CORE5     2
#define OS_NISRACCOUNTING_CORE5  0

/*===================================================================
 * Kernel data
 *==================================================================*/
#define OS_KERNELDATA_INIT_CORE0  /* kernel data core 0 */  \
  /* taskQueueHead */            OS_NULL,  \
  /* taskCurrent */              OS_NULL,  \
  /* iSpInitial */               OS_GetInitialStackPointer( OS_ISTACKBASE_0, OS_ISTACKLEN_0 ),  \
  /* hookApp */                  OS_NULL,  \
  /* inKernel */                 0,  \
  /* idleMode */                 IDLE_NO_HALT,  \
  /* inFunction */               0,  \
  /* tfCalledFrom */             0,  \
  /* iStackBase */               OS_ISTACKBASE_0,  \
  /* iStackLen */                OS_ISTACKLEN_0,  \
  /* isrCurrent */               OS_NULLISR,  \
  /* isrLastLock */              OS_NULLOBJECT,  \
  /* oldSuspendOs */             0,  \
  /* oldSuspendAll */            0,  \
  /* nestSuspendOs */            0,  \
  /* nestSuspendAll */           0,  \
  /* errorStatus */              OS_ERRORSTATUS_INIT,  \
  /* sHookContext */             OS_HOOKCONTEXT_INIT,  \
  /* eHookContext */             OS_HOOKCONTEXT_INIT,  \
  /* errorHookNesting */         0,  \
  /* accounting */               OS_ACCOUNTINGS_INIT,  \
  /* appsStarted */              0,  \
  /* panicCode */                OS_PANIC_NONE
#define OS_KERNELDATA_INIT_CORE1  /* kernel data core 1 */  \
  /* taskQueueHead */            OS_NULL,  \
  /* taskCurrent */              OS_NULL,  \
  /* iSpInitial */               OS_GetInitialStackPointer( OS_ISTACKBASE_1, OS_ISTACKLEN_1 ),  \
  /* hookApp */                  OS_NULL,  \
  /* inKernel */                 0,  \
  /* idleMode */                 IDLE_NO_HALT,  \
  /* inFunction */               0,  \
  /* tfCalledFrom */             0,  \
  /* iStackBase */               OS_ISTACKBASE_1,  \
  /* iStackLen */                OS_ISTACKLEN_1,  \
  /* isrCurrent */               OS_NULLISR,  \
  /* isrLastLock */              OS_NULLOBJECT,  \
  /* oldSuspendOs */             0,  \
  /* oldSuspendAll */            0,  \
  /* nestSuspendOs */            0,  \
  /* nestSuspendAll */           0,  \
  /* errorStatus */              OS_ERRORSTATUS_INIT,  \
  /* sHookContext */             OS_HOOKCONTEXT_INIT,  \
  /* eHookContext */             OS_HOOKCONTEXT_INIT,  \
  /* errorHookNesting */         0,  \
  /* accounting */               OS_ACCOUNTINGS_INIT,  \
  /* appsStarted */              0,  \
  /* panicCode */                OS_PANIC_NONE
#define OS_KERNELDATA_INIT_CORE2  /* kernel data core 2 */  \
  /* taskQueueHead */            OS_NULL,  \
  /* taskCurrent */              OS_NULL,  \
  /* iSpInitial */               OS_GetInitialStackPointer( OS_ISTACKBASE_2, OS_ISTACKLEN_2 ),  \
  /* hookApp */                  OS_NULL,  \
  /* inKernel */                 0,  \
  /* idleMode */                 IDLE_NO_HALT,  \
  /* inFunction */               0,  \
  /* tfCalledFrom */             0,  \
  /* iStackBase */               OS_ISTACKBASE_2,  \
  /* iStackLen */                OS_ISTACKLEN_2,  \
  /* isrCurrent */               OS_NULLISR,  \
  /* isrLastLock */              OS_NULLOBJECT,  \
  /* oldSuspendOs */             0,  \
  /* oldSuspendAll */            0,  \
  /* nestSuspendOs */            0,  \
  /* nestSuspendAll */           0,  \
  /* errorStatus */              OS_ERRORSTATUS_INIT,  \
  /* sHookContext */             OS_HOOKCONTEXT_INIT,  \
  /* eHookContext */             OS_HOOKCONTEXT_INIT,  \
  /* errorHookNesting */         0,  \
  /* accounting */               OS_ACCOUNTINGS_INIT,  \
  /* appsStarted */              0,  \
  /* panicCode */                OS_PANIC_NONE
#define OS_KERNELDATA_INIT_CORE3  /* kernel data core 3 */  \
  /* taskQueueHead */            OS_NULL,  \
  /* taskCurrent */              OS_NULL,  \
  /* iSpInitial */               OS_GetInitialStackPointer( OS_ISTACKBASE_3, OS_ISTACKLEN_3 ),  \
  /* hookApp */                  OS_NULL,  \
  /* inKernel */                 0,  \
  /* idleMode */                 IDLE_NO_HALT,  \
  /* inFunction */               0,  \
  /* tfCalledFrom */             0,  \
  /* iStackBase */               OS_ISTACKBASE_3,  \
  /* iStackLen */                OS_ISTACKLEN_3,  \
  /* isrCurrent */               OS_NULLISR,  \
  /* isrLastLock */              OS_NULLOBJECT,  \
  /* oldSuspendOs */             0,  \
  /* oldSuspendAll */            0,  \
  /* nestSuspendOs */            0,  \
  /* nestSuspendAll */           0,  \
  /* errorStatus */              OS_ERRORSTATUS_INIT,  \
  /* sHookContext */             OS_HOOKCONTEXT_INIT,  \
  /* eHookContext */             OS_HOOKCONTEXT_INIT,  \
  /* errorHookNesting */         0,  \
  /* accounting */               OS_ACCOUNTINGS_INIT,  \
  /* appsStarted */              0,  \
  /* panicCode */                OS_PANIC_NONE
#define OS_KERNELDATA_INIT_CORE4  /* kernel data core 4 */  \
  /* taskQueueHead */            OS_NULL,  \
  /* taskCurrent */              OS_NULL,  \
  /* iSpInitial */               OS_GetInitialStackPointer( OS_ISTACKBASE_4, OS_ISTACKLEN_4 ),  \
  /* hookApp */                  OS_NULL,  \
  /* inKernel */                 0,  \
  /* idleMode */                 IDLE_NO_HALT,  \
  /* inFunction */               0,  \
  /* tfCalledFrom */             0,  \
  /* iStackBase */               OS_ISTACKBASE_4,  \
  /* iStackLen */                OS_ISTACKLEN_4,  \
  /* isrCurrent */               OS_NULLISR,  \
  /* isrLastLock */              OS_NULLOBJECT,  \
  /* oldSuspendOs */             0,  \
  /* oldSuspendAll */            0,  \
  /* nestSuspendOs */            0,  \
  /* nestSuspendAll */           0,  \
  /* errorStatus */              OS_ERRORSTATUS_INIT,  \
  /* sHookContext */             OS_HOOKCONTEXT_INIT,  \
  /* eHookContext */             OS_HOOKCONTEXT_INIT,  \
  /* errorHookNesting */         0,  \
  /* accounting */               OS_ACCOUNTINGS_INIT,  \
  /* appsStarted */              0,  \
  /* panicCode */                OS_PANIC_NONE
#define OS_KERNELDATA_INIT_CORE5  /* kernel data core 5 */  \
  /* taskQueueHead */            OS_NULL,  \
  /* taskCurrent */              OS_NULL,  \
  /* iSpInitial */               OS_GetInitialStackPointer( OS_ISTACKBASE_5, OS_ISTACKLEN_5 ),  \
  /* hookApp */                  OS_NULL,  \
  /* inKernel */                 0,  \
  /* idleMode */                 IDLE_NO_HALT,  \
  /* inFunction */               0,  \
  /* tfCalledFrom */             0,  \
  /* iStackBase */               OS_ISTACKBASE_5,  \
  /* iStackLen */                OS_ISTACKLEN_5,  \
  /* isrCurrent */               OS_NULLISR,  \
  /* isrLastLock */              OS_NULLOBJECT,  \
  /* oldSuspendOs */             0,  \
  /* oldSuspendAll */            0,  \
  /* nestSuspendOs */            0,  \
  /* nestSuspendAll */           0,  \
  /* errorStatus */              OS_ERRORSTATUS_INIT,  \
  /* sHookContext */             OS_HOOKCONTEXT_INIT,  \
  /* eHookContext */             OS_HOOKCONTEXT_INIT,  \
  /* errorHookNesting */         0,  \
  /* accounting */               OS_ACCOUNTINGS_INIT,  \
  /* appsStarted */              0,  \
  /* panicCode */                OS_PANIC_NONE

/*===================================================================
 * Optimization
 *==================================================================*/
#define OS_CAT1_DIRECTCALL  0

/*===================================================================
 * Rate Monitor
 *==================================================================*/
#define OS_NRATEMONS  0
#define OS_NRATEMONS_CORE0  0
#define OS_NRATEMONS_CORE1  0
#define OS_NRATEMONS_CORE2  0
#define OS_NRATEMONS_CORE3  0
#define OS_NRATEMONS_CORE4  0
#define OS_NRATEMONS_CORE5  0


/*===================================================================
 * Resource Lock Timing
 *==================================================================*/
#define OS_NRESLOCKTIMES  0

/*===================================================================
 * Resources
 *==================================================================*/
#define OS_NRESOURCES  6


#define OS_RESOURCES  OS_RESOURCES_INIT(    /* RES_SCHEDULER_0 */  \
  /* Application */          &OS_appTable[OS_SYSTEM_0],  \
  /* Permissions */          0xfffu,  \
  /* Priority */             5,  \
  /* dynamic data */         &OS_resourceDynamic_core0[0]  \
),  \
OS_RESOURCES_INIT(    /* RES_SCHEDULER_1 */  \
  /* Application */          &OS_appTable[OS_SYSTEM_1],  \
  /* Permissions */          0xfffu,  \
  /* Priority */             5,  \
  /* dynamic data */         &OS_resourceDynamic_core1[0]  \
),  \
OS_RESOURCES_INIT(    /* RES_SCHEDULER_2 */  \
  /* Application */          &OS_appTable[OS_SYSTEM_2],  \
  /* Permissions */          0xfffu,  \
  /* Priority */             5,  \
  /* dynamic data */         &OS_resourceDynamic_core2[0]  \
),  \
OS_RESOURCES_INIT(    /* RES_SCHEDULER_3 */  \
  /* Application */          &OS_appTable[OS_SYSTEM_3],  \
  /* Permissions */          0xfffu,  \
  /* Priority */             0,  \
  /* dynamic data */         &OS_resourceDynamic_core3[0]  \
),  \
OS_RESOURCES_INIT(    /* RES_SCHEDULER_4 */  \
  /* Application */          &OS_appTable[OS_SYSTEM_4],  \
  /* Permissions */          0xfffu,  \
  /* Priority */             0,  \
  /* dynamic data */         &OS_resourceDynamic_core4[0]  \
),  \
OS_RESOURCES_INIT(    /* RES_SCHEDULER_5 */  \
  /* Application */          &OS_appTable[OS_SYSTEM_5],  \
  /* Permissions */          0xfffu,  \
  /* Priority */             0,  \
  /* dynamic data */         &OS_resourceDynamic_core5[0]  \
)
/* Number of Non-Internal Used resources on cores */
#define OS_NRESOURCES_CORE0  1
#define OS_NRESOURCES_CORE1  1
#define OS_NRESOURCES_CORE2  1
#define OS_NRESOURCES_CORE3  1
#define OS_NRESOURCES_CORE4  1
#define OS_NRESOURCES_CORE5  1

/*===================================================================
 * Schedule Tables
 *==================================================================*/
#define OS_NSCHEDULES      10
#define OS_NSCHEDULESSYNC  0

#define OS_STCONFIG  OS_STCONFIG_INIT(    /* SchM_DefaultScheduleTable_OsApplication_C0 */  \
  /* Application id */                OsApplication_C0,  \
  /* Application pointer */           &OS_appTable[OsApplication_C0], \
  /* Permissions */                   0x1u,  \
  /* Schedule table entries */        &OS_stEntries[0],  \
  /* Duration */                      20,  \
  /* Cut off */                       0,  \
  /* Precision */                     0,  \
  /* Alarm ID */                      6,  \
  /* Number of expiry points */       5,  \
  /* Flags */                         (OS_ST_REPEATING),  \
  /* dynamic data */                  &OS_scheduleDynamic_core0[0]  \
),  \
OS_STCONFIG_INIT(    /* Rte_DefaultScheduleTable_OsApplication_C0 */  \
  /* Application id */                OsApplication_C0,  \
  /* Application pointer */           &OS_appTable[OsApplication_C0], \
  /* Permissions */                   0x1u,  \
  /* Schedule table entries */        &OS_stEntries[5],  \
  /* Duration */                      100,  \
  /* Cut off */                       0,  \
  /* Precision */                     0,  \
  /* Alarm ID */                      7,  \
  /* Number of expiry points */       49,  \
  /* Flags */                         (OS_ST_REPEATING),  \
  /* dynamic data */                  &OS_scheduleDynamic_core0[1]  \
),  \
OS_STCONFIG_INIT(    /* SchM_DefaultScheduleTable_OsApplication_C1 */  \
  /* Application id */                OsApplication_C1,  \
  /* Application pointer */           &OS_appTable[OsApplication_C1], \
  /* Permissions */                   0x2u,  \
  /* Schedule table entries */        &OS_stEntries[54],  \
  /* Duration */                      20,  \
  /* Cut off */                       0,  \
  /* Precision */                     0,  \
  /* Alarm ID */                      8,  \
  /* Number of expiry points */       1,  \
  /* Flags */                         (OS_ST_REPEATING),  \
  /* dynamic data */                  &OS_scheduleDynamic_core1[0]  \
),  \
OS_STCONFIG_INIT(    /* Rte_DefaultScheduleTable_OsApplication_C1 */  \
  /* Application id */                OsApplication_C1,  \
  /* Application pointer */           &OS_appTable[OsApplication_C1], \
  /* Permissions */                   0x2u,  \
  /* Schedule table entries */        &OS_stEntries[55],  \
  /* Duration */                      100,  \
  /* Cut off */                       0,  \
  /* Precision */                     0,  \
  /* Alarm ID */                      9,  \
  /* Number of expiry points */       122,  \
  /* Flags */                         (OS_ST_REPEATING),  \
  /* dynamic data */                  &OS_scheduleDynamic_core1[1]  \
),  \
OS_STCONFIG_INIT(    /* SchM_DefaultScheduleTable_OsApplication_C2 */  \
  /* Application id */                OsApplication_C2,  \
  /* Application pointer */           &OS_appTable[OsApplication_C2], \
  /* Permissions */                   0x4u,  \
  /* Schedule table entries */        &OS_stEntries[177],  \
  /* Duration */                      20,  \
  /* Cut off */                       0,  \
  /* Precision */                     0,  \
  /* Alarm ID */                      10,  \
  /* Number of expiry points */       1,  \
  /* Flags */                         (OS_ST_REPEATING),  \
  /* dynamic data */                  &OS_scheduleDynamic_core2[0]  \
),  \
OS_STCONFIG_INIT(    /* SchM_DefaultScheduleTable_OsApplication_C3 */  \
  /* Application id */                OsApplication_C3,  \
  /* Application pointer */           &OS_appTable[OsApplication_C3], \
  /* Permissions */                   0x8u,  \
  /* Schedule table entries */        &OS_stEntries[178],  \
  /* Duration */                      20,  \
  /* Cut off */                       0,  \
  /* Precision */                     0,  \
  /* Alarm ID */                      11,  \
  /* Number of expiry points */       1,  \
  /* Flags */                         (OS_ST_REPEATING),  \
  /* dynamic data */                  &OS_scheduleDynamic_core3[0]  \
),  \
OS_STCONFIG_INIT(    /* SchM_DefaultScheduleTable_OsApplication_C4 */  \
  /* Application id */                OsApplication_C4,  \
  /* Application pointer */           &OS_appTable[OsApplication_C4], \
  /* Permissions */                   0x10u,  \
  /* Schedule table entries */        &OS_stEntries[179],  \
  /* Duration */                      20,  \
  /* Cut off */                       0,  \
  /* Precision */                     0,  \
  /* Alarm ID */                      12,  \
  /* Number of expiry points */       1,  \
  /* Flags */                         (OS_ST_REPEATING),  \
  /* dynamic data */                  &OS_scheduleDynamic_core4[0]  \
),  \
OS_STCONFIG_INIT(    /* SchM_DefaultScheduleTable_OsApplication_C5 */  \
  /* Application id */                OsApplication_C5,  \
  /* Application pointer */           &OS_appTable[OsApplication_C5], \
  /* Permissions */                   0x20u,  \
  /* Schedule table entries */        &OS_stEntries[180],  \
  /* Duration */                      20,  \
  /* Cut off */                       0,  \
  /* Precision */                     0,  \
  /* Alarm ID */                      13,  \
  /* Number of expiry points */       1,  \
  /* Flags */                         (OS_ST_REPEATING),  \
  /* dynamic data */                  &OS_scheduleDynamic_core5[0]  \
),  \
OS_STCONFIG_INIT(    /* Rte_DefaultScheduleTable_OsApplication_C2 */  \
  /* Application id */                OsApplication_C2,  \
  /* Application pointer */           &OS_appTable[OsApplication_C2], \
  /* Permissions */                   0x4u,  \
  /* Schedule table entries */        &OS_stEntries[181],  \
  /* Duration */                      100,  \
  /* Cut off */                       0,  \
  /* Precision */                     0,  \
  /* Alarm ID */                      14,  \
  /* Number of expiry points */       42,  \
  /* Flags */                         (OS_ST_REPEATING),  \
  /* dynamic data */                  &OS_scheduleDynamic_core2[1]  \
),  \
OS_STCONFIG_INIT(    /* Rte_DefaultScheduleTable_OsApplication_C3 */  \
  /* Application id */                OsApplication_C3,  \
  /* Application pointer */           &OS_appTable[OsApplication_C3], \
  /* Permissions */                   0x8u,  \
  /* Schedule table entries */        &OS_stEntries[223],  \
  /* Duration */                      20,  \
  /* Cut off */                       0,  \
  /* Precision */                     0,  \
  /* Alarm ID */                      15,  \
  /* Number of expiry points */       7,  \
  /* Flags */                         (OS_ST_REPEATING),  \
  /* dynamic data */                  &OS_scheduleDynamic_core3[1]  \
)

/* ScheduleTables expiry points */
#define OS_NSTENTRIES  230
#define OS_STENTRIES  \
  {  /* EP_0 */  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_Task_C0_TE_72326CF0F55FFC788B52DB7F835D5952,  \
    /* Task */                        EM_Bsw_Task_C0  \
  },  \
  {  /* EP_0 */  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_10ms_C0_TE_012AF07576AE01C05AAE3DE95EFFDD4C | Rte_OSTimingEvent_EM_Bsw_10ms_C0_TE_1D65699D19EB37B5C8A54E55582BC006 | Rte_OSTimingEvent_EM_Bsw_10ms_C0_TE_FB1E1E46F286102A5E018DDD34ABF710,  \
    /* Task */                        EM_Bsw_10ms_C0  \
  },  \
  {  /* EP_5000 */  \
    /* Offset */                      5,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_10ms_C0_TE_1D65699D19EB37B5C8A54E55582BC006,  \
    /* Task */                        EM_Bsw_10ms_C0  \
  },  \
  {  /* EP_10000 */  \
    /* Offset */                      10,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_10ms_C0_TE_012AF07576AE01C05AAE3DE95EFFDD4C | Rte_OSTimingEvent_EM_Bsw_10ms_C0_TE_1D65699D19EB37B5C8A54E55582BC006,  \
    /* Task */                        EM_Bsw_10ms_C0  \
  },  \
  {  /* EP_15000 */  \
    /* Offset */                      15,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_10ms_C0_TE_1D65699D19EB37B5C8A54E55582BC006,  \
    /* Task */                        EM_Bsw_10ms_C0  \
  },  \
  /* EP_0 */  \
  {  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_10ms_C0  \
  },  \
  /* EP_0 */  \
  {  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_25ms_C0  \
  },  \
  /* EP_0 */  \
  {  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C0  \
  },  \
  {  /* EP_0 */  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_Task_C0_TE_DA2A233F5D58325C1CAED292AA64F465,  \
    /* Task */                        EM_Bsw_Task_C0  \
  },  \
  {  /* EP_0 */  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_10ms_C0_TE_1E6CCE5F1652297767E90CCFF6814CA1,  \
    /* Task */                        EM_Bsw_10ms_C0  \
  },  \
  /* EP_5000 */  \
  {  \
    /* Offset */                      5,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C0  \
  },  \
  /* EP_10000 */  \
  {  \
    /* Offset */                      10,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_10ms_C0  \
  },  \
  /* EP_10000 */  \
  {  \
    /* Offset */                      10,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C0  \
  },  \
  {  /* EP_10000 */  \
    /* Offset */                      10,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_10ms_C0_TE_1E6CCE5F1652297767E90CCFF6814CA1,  \
    /* Task */                        EM_Bsw_10ms_C0  \
  },  \
  /* EP_15000 */  \
  {  \
    /* Offset */                      15,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C0  \
  },  \
  /* EP_20000 */  \
  {  \
    /* Offset */                      20,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_10ms_C0  \
  },  \
  /* EP_20000 */  \
  {  \
    /* Offset */                      20,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C0  \
  },  \
  {  /* EP_20000 */  \
    /* Offset */                      20,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_Task_C0_TE_DA2A233F5D58325C1CAED292AA64F465,  \
    /* Task */                        EM_Bsw_Task_C0  \
  },  \
  {  /* EP_20000 */  \
    /* Offset */                      20,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_10ms_C0_TE_1E6CCE5F1652297767E90CCFF6814CA1,  \
    /* Task */                        EM_Bsw_10ms_C0  \
  },  \
  /* EP_25000 */  \
  {  \
    /* Offset */                      25,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_25ms_C0  \
  },  \
  /* EP_25000 */  \
  {  \
    /* Offset */                      25,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C0  \
  },  \
  /* EP_30000 */  \
  {  \
    /* Offset */                      30,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_10ms_C0  \
  },  \
  /* EP_30000 */  \
  {  \
    /* Offset */                      30,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C0  \
  },  \
  {  /* EP_30000 */  \
    /* Offset */                      30,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_10ms_C0_TE_1E6CCE5F1652297767E90CCFF6814CA1,  \
    /* Task */                        EM_Bsw_10ms_C0  \
  },  \
  /* EP_35000 */  \
  {  \
    /* Offset */                      35,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C0  \
  },  \
  /* EP_40000 */  \
  {  \
    /* Offset */                      40,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_10ms_C0  \
  },  \
  /* EP_40000 */  \
  {  \
    /* Offset */                      40,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C0  \
  },  \
  {  /* EP_40000 */  \
    /* Offset */                      40,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_Task_C0_TE_DA2A233F5D58325C1CAED292AA64F465,  \
    /* Task */                        EM_Bsw_Task_C0  \
  },  \
  {  /* EP_40000 */  \
    /* Offset */                      40,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_10ms_C0_TE_1E6CCE5F1652297767E90CCFF6814CA1,  \
    /* Task */                        EM_Bsw_10ms_C0  \
  },  \
  /* EP_45000 */  \
  {  \
    /* Offset */                      45,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C0  \
  },  \
  /* EP_50000 */  \
  {  \
    /* Offset */                      50,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_10ms_C0  \
  },  \
  /* EP_50000 */  \
  {  \
    /* Offset */                      50,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C0  \
  },  \
  /* EP_50000 */  \
  {  \
    /* Offset */                      50,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_25ms_C0  \
  },  \
  {  /* EP_50000 */  \
    /* Offset */                      50,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_10ms_C0_TE_1E6CCE5F1652297767E90CCFF6814CA1,  \
    /* Task */                        EM_Bsw_10ms_C0  \
  },  \
  /* EP_55000 */  \
  {  \
    /* Offset */                      55,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C0  \
  },  \
  /* EP_60000 */  \
  {  \
    /* Offset */                      60,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_10ms_C0  \
  },  \
  /* EP_60000 */  \
  {  \
    /* Offset */                      60,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C0  \
  },  \
  {  /* EP_60000 */  \
    /* Offset */                      60,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_Task_C0_TE_DA2A233F5D58325C1CAED292AA64F465,  \
    /* Task */                        EM_Bsw_Task_C0  \
  },  \
  {  /* EP_60000 */  \
    /* Offset */                      60,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_10ms_C0_TE_1E6CCE5F1652297767E90CCFF6814CA1,  \
    /* Task */                        EM_Bsw_10ms_C0  \
  },  \
  /* EP_65000 */  \
  {  \
    /* Offset */                      65,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C0  \
  },  \
  /* EP_70000 */  \
  {  \
    /* Offset */                      70,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_10ms_C0  \
  },  \
  /* EP_70000 */  \
  {  \
    /* Offset */                      70,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C0  \
  },  \
  {  /* EP_70000 */  \
    /* Offset */                      70,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_10ms_C0_TE_1E6CCE5F1652297767E90CCFF6814CA1,  \
    /* Task */                        EM_Bsw_10ms_C0  \
  },  \
  /* EP_75000 */  \
  {  \
    /* Offset */                      75,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C0  \
  },  \
  /* EP_75000 */  \
  {  \
    /* Offset */                      75,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_25ms_C0  \
  },  \
  /* EP_80000 */  \
  {  \
    /* Offset */                      80,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_10ms_C0  \
  },  \
  /* EP_80000 */  \
  {  \
    /* Offset */                      80,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C0  \
  },  \
  {  /* EP_80000 */  \
    /* Offset */                      80,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_Task_C0_TE_DA2A233F5D58325C1CAED292AA64F465,  \
    /* Task */                        EM_Bsw_Task_C0  \
  },  \
  {  /* EP_80000 */  \
    /* Offset */                      80,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_10ms_C0_TE_1E6CCE5F1652297767E90CCFF6814CA1,  \
    /* Task */                        EM_Bsw_10ms_C0  \
  },  \
  /* EP_85000 */  \
  {  \
    /* Offset */                      85,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C0  \
  },  \
  /* EP_90000 */  \
  {  \
    /* Offset */                      90,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_10ms_C0  \
  },  \
  /* EP_90000 */  \
  {  \
    /* Offset */                      90,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C0  \
  },  \
  {  /* EP_90000 */  \
    /* Offset */                      90,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_10ms_C0_TE_1E6CCE5F1652297767E90CCFF6814CA1,  \
    /* Task */                        EM_Bsw_10ms_C0  \
  },  \
  /* EP_95000 */  \
  {  \
    /* Offset */                      95,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C0  \
  },  \
  {  /* EP_0 */  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_20ms_C1_TE_2CDA2542ABD9EE922E79D5DEA31CABFA,  \
    /* Task */                        EM_Bsw_20ms_C1  \
  },  \
  /* EP_0 */  \
  {  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_10ms_C1  \
  },  \
  /* EP_0 */  \
  {  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_20ms_C1  \
  },  \
  /* EP_0 */  \
  {  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_50ms_C1  \
  },  \
  /* EP_0 */  \
  {  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  {  /* EP_0 */  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_20ms_C1_TE_236D4CDC7E97447E9763E89F52F1E395,  \
    /* Task */                        EM_Bsw_20ms_C1  \
  },  \
  /* EP_1000 */  \
  {  \
    /* Offset */                      1,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_2000 */  \
  {  \
    /* Offset */                      2,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_3000 */  \
  {  \
    /* Offset */                      3,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_4000 */  \
  {  \
    /* Offset */                      4,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_5000 */  \
  {  \
    /* Offset */                      5,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_6000 */  \
  {  \
    /* Offset */                      6,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_7000 */  \
  {  \
    /* Offset */                      7,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_8000 */  \
  {  \
    /* Offset */                      8,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_9000 */  \
  {  \
    /* Offset */                      9,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_10000 */  \
  {  \
    /* Offset */                      10,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_10ms_C1  \
  },  \
  /* EP_10000 */  \
  {  \
    /* Offset */                      10,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_11000 */  \
  {  \
    /* Offset */                      11,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_12000 */  \
  {  \
    /* Offset */                      12,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_13000 */  \
  {  \
    /* Offset */                      13,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_14000 */  \
  {  \
    /* Offset */                      14,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_15000 */  \
  {  \
    /* Offset */                      15,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_16000 */  \
  {  \
    /* Offset */                      16,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_17000 */  \
  {  \
    /* Offset */                      17,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_18000 */  \
  {  \
    /* Offset */                      18,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_19000 */  \
  {  \
    /* Offset */                      19,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_20000 */  \
  {  \
    /* Offset */                      20,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_10ms_C1  \
  },  \
  /* EP_20000 */  \
  {  \
    /* Offset */                      20,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_20ms_C1  \
  },  \
  /* EP_20000 */  \
  {  \
    /* Offset */                      20,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  {  /* EP_20000 */  \
    /* Offset */                      20,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_20ms_C1_TE_236D4CDC7E97447E9763E89F52F1E395,  \
    /* Task */                        EM_Bsw_20ms_C1  \
  },  \
  /* EP_21000 */  \
  {  \
    /* Offset */                      21,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_22000 */  \
  {  \
    /* Offset */                      22,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_23000 */  \
  {  \
    /* Offset */                      23,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_24000 */  \
  {  \
    /* Offset */                      24,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_25000 */  \
  {  \
    /* Offset */                      25,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_26000 */  \
  {  \
    /* Offset */                      26,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_27000 */  \
  {  \
    /* Offset */                      27,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_28000 */  \
  {  \
    /* Offset */                      28,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_29000 */  \
  {  \
    /* Offset */                      29,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_30000 */  \
  {  \
    /* Offset */                      30,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_10ms_C1  \
  },  \
  /* EP_30000 */  \
  {  \
    /* Offset */                      30,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_31000 */  \
  {  \
    /* Offset */                      31,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_32000 */  \
  {  \
    /* Offset */                      32,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_33000 */  \
  {  \
    /* Offset */                      33,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_34000 */  \
  {  \
    /* Offset */                      34,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_35000 */  \
  {  \
    /* Offset */                      35,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_36000 */  \
  {  \
    /* Offset */                      36,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_37000 */  \
  {  \
    /* Offset */                      37,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_38000 */  \
  {  \
    /* Offset */                      38,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_39000 */  \
  {  \
    /* Offset */                      39,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_40000 */  \
  {  \
    /* Offset */                      40,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_10ms_C1  \
  },  \
  /* EP_40000 */  \
  {  \
    /* Offset */                      40,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_20ms_C1  \
  },  \
  /* EP_40000 */  \
  {  \
    /* Offset */                      40,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  {  /* EP_40000 */  \
    /* Offset */                      40,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_20ms_C1_TE_236D4CDC7E97447E9763E89F52F1E395,  \
    /* Task */                        EM_Bsw_20ms_C1  \
  },  \
  /* EP_41000 */  \
  {  \
    /* Offset */                      41,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_42000 */  \
  {  \
    /* Offset */                      42,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_43000 */  \
  {  \
    /* Offset */                      43,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_44000 */  \
  {  \
    /* Offset */                      44,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_45000 */  \
  {  \
    /* Offset */                      45,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_46000 */  \
  {  \
    /* Offset */                      46,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_47000 */  \
  {  \
    /* Offset */                      47,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_48000 */  \
  {  \
    /* Offset */                      48,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_49000 */  \
  {  \
    /* Offset */                      49,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_50000 */  \
  {  \
    /* Offset */                      50,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_10ms_C1  \
  },  \
  /* EP_50000 */  \
  {  \
    /* Offset */                      50,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_50ms_C1  \
  },  \
  /* EP_50000 */  \
  {  \
    /* Offset */                      50,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_51000 */  \
  {  \
    /* Offset */                      51,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_52000 */  \
  {  \
    /* Offset */                      52,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_53000 */  \
  {  \
    /* Offset */                      53,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_54000 */  \
  {  \
    /* Offset */                      54,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_55000 */  \
  {  \
    /* Offset */                      55,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_56000 */  \
  {  \
    /* Offset */                      56,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_57000 */  \
  {  \
    /* Offset */                      57,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_58000 */  \
  {  \
    /* Offset */                      58,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_59000 */  \
  {  \
    /* Offset */                      59,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_60000 */  \
  {  \
    /* Offset */                      60,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_10ms_C1  \
  },  \
  /* EP_60000 */  \
  {  \
    /* Offset */                      60,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_20ms_C1  \
  },  \
  /* EP_60000 */  \
  {  \
    /* Offset */                      60,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  {  /* EP_60000 */  \
    /* Offset */                      60,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_20ms_C1_TE_236D4CDC7E97447E9763E89F52F1E395,  \
    /* Task */                        EM_Bsw_20ms_C1  \
  },  \
  /* EP_61000 */  \
  {  \
    /* Offset */                      61,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_62000 */  \
  {  \
    /* Offset */                      62,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_63000 */  \
  {  \
    /* Offset */                      63,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_64000 */  \
  {  \
    /* Offset */                      64,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_65000 */  \
  {  \
    /* Offset */                      65,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_66000 */  \
  {  \
    /* Offset */                      66,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_67000 */  \
  {  \
    /* Offset */                      67,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_68000 */  \
  {  \
    /* Offset */                      68,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_69000 */  \
  {  \
    /* Offset */                      69,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_70000 */  \
  {  \
    /* Offset */                      70,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_10ms_C1  \
  },  \
  /* EP_70000 */  \
  {  \
    /* Offset */                      70,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_71000 */  \
  {  \
    /* Offset */                      71,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_72000 */  \
  {  \
    /* Offset */                      72,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_73000 */  \
  {  \
    /* Offset */                      73,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_74000 */  \
  {  \
    /* Offset */                      74,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_75000 */  \
  {  \
    /* Offset */                      75,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_76000 */  \
  {  \
    /* Offset */                      76,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_77000 */  \
  {  \
    /* Offset */                      77,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_78000 */  \
  {  \
    /* Offset */                      78,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_79000 */  \
  {  \
    /* Offset */                      79,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_80000 */  \
  {  \
    /* Offset */                      80,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_10ms_C1  \
  },  \
  /* EP_80000 */  \
  {  \
    /* Offset */                      80,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_20ms_C1  \
  },  \
  /* EP_80000 */  \
  {  \
    /* Offset */                      80,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  {  /* EP_80000 */  \
    /* Offset */                      80,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_20ms_C1_TE_236D4CDC7E97447E9763E89F52F1E395,  \
    /* Task */                        EM_Bsw_20ms_C1  \
  },  \
  /* EP_81000 */  \
  {  \
    /* Offset */                      81,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_82000 */  \
  {  \
    /* Offset */                      82,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_83000 */  \
  {  \
    /* Offset */                      83,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_84000 */  \
  {  \
    /* Offset */                      84,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_85000 */  \
  {  \
    /* Offset */                      85,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_86000 */  \
  {  \
    /* Offset */                      86,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_87000 */  \
  {  \
    /* Offset */                      87,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_88000 */  \
  {  \
    /* Offset */                      88,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_89000 */  \
  {  \
    /* Offset */                      89,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_90000 */  \
  {  \
    /* Offset */                      90,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_10ms_C1  \
  },  \
  /* EP_90000 */  \
  {  \
    /* Offset */                      90,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_91000 */  \
  {  \
    /* Offset */                      91,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_92000 */  \
  {  \
    /* Offset */                      92,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_93000 */  \
  {  \
    /* Offset */                      93,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_94000 */  \
  {  \
    /* Offset */                      94,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_95000 */  \
  {  \
    /* Offset */                      95,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_96000 */  \
  {  \
    /* Offset */                      96,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_97000 */  \
  {  \
    /* Offset */                      97,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_98000 */  \
  {  \
    /* Offset */                      98,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  /* EP_99000 */  \
  {  \
    /* Offset */                      99,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_Uss_5ms_C1  \
  },  \
  {  /* EP_0 */  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_20ms_C2_TE_49AEC53B73B5F5193AB8079E8EE7934E,  \
    /* Task */                        EM_Bsw_20ms_C2  \
  },  \
  {  /* EP_0 */  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_OsTask_20ms_C3_TE_1BF45AF11CA52C53FB5A043C90F94DEE,  \
    /* Task */                        OsTask_20ms_C3  \
  },  \
  /* EP_0 */  \
  {  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_20ms_C4  \
  },  \
  /* EP_0 */  \
  {  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_20ms_C5  \
  },  \
  /* EP_0 */  \
  {  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C2  \
  },  \
  /* EP_0 */  \
  {  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_10ms_C2  \
  },  \
  /* EP_0 */  \
  {  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_20ms_C2  \
  },  \
  /* EP_0 */  \
  {  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_50ms_C2  \
  },  \
  {  /* EP_0 */  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_20ms_C2_TE_480E602D3320AA916F8C973A4F0703A3,  \
    /* Task */                        EM_Bsw_20ms_C2  \
  },  \
  /* EP_5000 */  \
  {  \
    /* Offset */                      5,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C2  \
  },  \
  /* EP_10000 */  \
  {  \
    /* Offset */                      10,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C2  \
  },  \
  /* EP_10000 */  \
  {  \
    /* Offset */                      10,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_10ms_C2  \
  },  \
  /* EP_15000 */  \
  {  \
    /* Offset */                      15,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C2  \
  },  \
  /* EP_20000 */  \
  {  \
    /* Offset */                      20,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C2  \
  },  \
  /* EP_20000 */  \
  {  \
    /* Offset */                      20,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_10ms_C2  \
  },  \
  /* EP_20000 */  \
  {  \
    /* Offset */                      20,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_20ms_C2  \
  },  \
  {  /* EP_20000 */  \
    /* Offset */                      20,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_20ms_C2_TE_480E602D3320AA916F8C973A4F0703A3,  \
    /* Task */                        EM_Bsw_20ms_C2  \
  },  \
  /* EP_25000 */  \
  {  \
    /* Offset */                      25,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C2  \
  },  \
  /* EP_30000 */  \
  {  \
    /* Offset */                      30,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C2  \
  },  \
  /* EP_30000 */  \
  {  \
    /* Offset */                      30,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_10ms_C2  \
  },  \
  /* EP_35000 */  \
  {  \
    /* Offset */                      35,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C2  \
  },  \
  /* EP_40000 */  \
  {  \
    /* Offset */                      40,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C2  \
  },  \
  /* EP_40000 */  \
  {  \
    /* Offset */                      40,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_10ms_C2  \
  },  \
  /* EP_40000 */  \
  {  \
    /* Offset */                      40,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_20ms_C2  \
  },  \
  {  /* EP_40000 */  \
    /* Offset */                      40,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_20ms_C2_TE_480E602D3320AA916F8C973A4F0703A3,  \
    /* Task */                        EM_Bsw_20ms_C2  \
  },  \
  /* EP_45000 */  \
  {  \
    /* Offset */                      45,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C2  \
  },  \
  /* EP_50000 */  \
  {  \
    /* Offset */                      50,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C2  \
  },  \
  /* EP_50000 */  \
  {  \
    /* Offset */                      50,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_10ms_C2  \
  },  \
  /* EP_50000 */  \
  {  \
    /* Offset */                      50,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_50ms_C2  \
  },  \
  /* EP_55000 */  \
  {  \
    /* Offset */                      55,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C2  \
  },  \
  /* EP_60000 */  \
  {  \
    /* Offset */                      60,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C2  \
  },  \
  /* EP_60000 */  \
  {  \
    /* Offset */                      60,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_10ms_C2  \
  },  \
  /* EP_60000 */  \
  {  \
    /* Offset */                      60,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_20ms_C2  \
  },  \
  {  /* EP_60000 */  \
    /* Offset */                      60,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_20ms_C2_TE_480E602D3320AA916F8C973A4F0703A3,  \
    /* Task */                        EM_Bsw_20ms_C2  \
  },  \
  /* EP_65000 */  \
  {  \
    /* Offset */                      65,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C2  \
  },  \
  /* EP_70000 */  \
  {  \
    /* Offset */                      70,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C2  \
  },  \
  /* EP_70000 */  \
  {  \
    /* Offset */                      70,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_10ms_C2  \
  },  \
  /* EP_75000 */  \
  {  \
    /* Offset */                      75,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C2  \
  },  \
  /* EP_80000 */  \
  {  \
    /* Offset */                      80,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C2  \
  },  \
  /* EP_80000 */  \
  {  \
    /* Offset */                      80,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_10ms_C2  \
  },  \
  /* EP_80000 */  \
  {  \
    /* Offset */                      80,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_20ms_C2  \
  },  \
  {  /* EP_80000 */  \
    /* Offset */                      80,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_EM_Bsw_20ms_C2_TE_480E602D3320AA916F8C973A4F0703A3,  \
    /* Task */                        EM_Bsw_20ms_C2  \
  },  \
  /* EP_85000 */  \
  {  \
    /* Offset */                      85,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C2  \
  },  \
  /* EP_90000 */  \
  {  \
    /* Offset */                      90,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C2  \
  },  \
  /* EP_90000 */  \
  {  \
    /* Offset */                      90,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_10ms_C2  \
  },  \
  /* EP_95000 */  \
  {  \
    /* Offset */                      95,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        EM_App_5ms_C2  \
  },  \
  /* EP_0 */  \
  {  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_5ms_C3  \
  },  \
  /* EP_0 */  \
  {  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_10ms_C3  \
  },  \
  {  /* EP_0 */  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       Rte_OSTimingEvent_OsTask_20ms_C3_TE_B77D98AB2C8CC6F0727B727EFFCA2188,  \
    /* Task */                        OsTask_20ms_C3  \
  },  \
  /* EP_5000 */  \
  {  \
    /* Offset */                      5,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_5ms_C3  \
  },  \
  /* EP_10000 */  \
  {  \
    /* Offset */                      10,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_5ms_C3  \
  },  \
  /* EP_10000 */  \
  {  \
    /* Offset */                      10,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_10ms_C3  \
  },  \
  /* EP_15000 */  \
  {  \
    /* Offset */                      15,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_5ms_C3  \
  }

#define OS_NSCHEDULES_CORE0  2
#define OS_NSCHEDULES_CORE1  2
#define OS_NSCHEDULES_CORE2  2
#define OS_NSCHEDULES_CORE3  2
#define OS_NSCHEDULES_CORE4  1
#define OS_NSCHEDULES_CORE5  1

/*===================================================================
 * Spinlocks
 *==================================================================*/
#define OS_NAUTOSARSPINLOCKS  1
#define OS_AUTOSARSPINLOCKCONFIG  \
{       /* OsSpinlock_0 */  \
   /* Dynamic spinlock structure */             &OS_autosarSpinlockDynamic[OsSpinlock_0],  \
   /* Successor spinlock */                     OS_NULLSPINLOCK,  \
   /* Accessing Applications */                 0x3f,  \
   /* Spinlock ID */                            OsSpinlock_0,  \
   /* Lock method */                            OS_SPINLOCKLM_LOCK_CAT2_INTERRUPTS  \
}

/*===================================================================
 * Stacks
 *==================================================================*/
#define OS_STACK_REGION_ALIGNMENT  8
/* Task Stacks */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack0_slot0, .bss.core0.os_taskstack0_slot0, 1538, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack0_slot1, .bss.core0.os_taskstack0_slot1, 1026, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack0_slot2, .bss.core0.os_taskstack0_slot2, 1026, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack0_slot3, .bss.core0.os_taskstack0_slot3, 258, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack0_slot4, .bss.core0.os_taskstack0_slot4, 258, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack0_slot5, .bss.core0.os_taskstack0_slot5, 130, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack0_slot6, .bss.core0.os_taskstack0_slot6, 130, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack1_slot0, .bss.core1.os_taskstack1_slot0, 10242, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack1_slot1, .bss.core1.os_taskstack1_slot1, 1026, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack1_slot2, .bss.core1.os_taskstack1_slot2, 386, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack1_slot3, .bss.core1.os_taskstack1_slot3, 258, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack1_slot4, .bss.core1.os_taskstack1_slot4, 130, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack1_slot5, .bss.core1.os_taskstack1_slot5, 130, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack1_slot6, .bss.core1.os_taskstack1_slot6, 130, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack2_slot0, .bss.core2.os_taskstack2_slot0, 1026, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack2_slot1, .bss.core2.os_taskstack2_slot1, 130, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack2_slot2, .bss.core2.os_taskstack2_slot2, 130, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack2_slot3, .bss.core2.os_taskstack2_slot3, 130, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack2_slot4, .bss.core2.os_taskstack2_slot4, 130, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack2_slot5, .bss.core2.os_taskstack2_slot5, 130, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack2_slot6, .bss.core2.os_taskstack2_slot6, 130, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack3_slot0, .bss.core3.os_taskstack3_slot0, 130, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack3_slot1, .bss.core3.os_taskstack3_slot1, 130, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack4, .bss.core4.os_taskstack4, 130, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack5, .bss.core5.os_taskstack5, 130, 8 );
#endif
#endif  /* OS_ASM */
/* Interrupt Stacks */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_kernStack0, .bss.core0.os_kernstack0, 8992, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_kernStack1, .bss.core1.os_kernstack1, 462, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_kernStack2, .bss.core2.os_kernstack2, 396, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_kernStack3, .bss.core3.os_kernstack3, 396, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_kernStack4, .bss.core4.os_kernstack4, 396, 8 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_kernStack5, .bss.core5.os_kernstack5, 396, 8 );
#endif
#endif  /* OS_ASM */

/*===================================================================
 * Tasks
 *==================================================================*/
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EM_Bsw_10ms_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EM_Bsw_10ms_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EM_Bsw_10ms_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EM_Bsw_10ms_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(EM_Bsw_10ms_C0);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EM_Bsw_Task_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EM_Bsw_Task_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EM_Bsw_Task_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EM_Bsw_Task_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(EM_Bsw_Task_C0);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EM_Bsw_20ms_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EM_Bsw_20ms_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EM_Bsw_20ms_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EM_Bsw_20ms_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(EM_Bsw_20ms_C1);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EM_Bsw_20ms_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EM_Bsw_20ms_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EM_Bsw_20ms_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EM_Bsw_20ms_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(EM_Bsw_20ms_C2);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsTask_20ms_C3);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsTask_20ms_C3);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_20ms_C3);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_20ms_C3);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_20ms_C3);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EM_Bsw_Start_Init_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EM_Bsw_Start_Init_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EM_Bsw_Start_Init_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EM_Bsw_Start_Init_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(EM_Bsw_Start_Init_C0);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EM_Bsw_Init_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EM_Bsw_Init_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EM_Bsw_Init_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EM_Bsw_Init_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(EM_Bsw_Init_C0);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EM_App_5ms_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EM_App_5ms_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EM_App_5ms_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EM_App_5ms_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(EM_App_5ms_C0);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EM_App_10ms_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EM_App_10ms_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EM_App_10ms_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EM_App_10ms_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(EM_App_10ms_C0);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EM_App_25ms_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EM_App_25ms_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EM_App_25ms_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EM_App_25ms_C0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(EM_App_25ms_C0);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EM_Bsw_Init_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EM_Bsw_Init_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EM_Bsw_Init_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EM_Bsw_Init_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(EM_Bsw_Init_C1);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EM_Uss_Init_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EM_Uss_Init_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EM_Uss_Init_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EM_Uss_Init_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(EM_Uss_Init_C1);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EM_Uss_5ms_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EM_Uss_5ms_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EM_Uss_5ms_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EM_Uss_5ms_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(EM_Uss_5ms_C1);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EM_Uss_10ms_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EM_Uss_10ms_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EM_Uss_10ms_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EM_Uss_10ms_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(EM_Uss_10ms_C1);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EM_Uss_20ms_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EM_Uss_20ms_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EM_Uss_20ms_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EM_Uss_20ms_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(EM_Uss_20ms_C1);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EM_Uss_50ms_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EM_Uss_50ms_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EM_Uss_50ms_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EM_Uss_50ms_C1);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(EM_Uss_50ms_C1);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EM_Bsw_Init_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EM_Bsw_Init_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EM_Bsw_Init_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EM_Bsw_Init_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(EM_Bsw_Init_C2);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EM_App_Init_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EM_App_Init_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EM_App_Init_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EM_App_Init_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(EM_App_Init_C2);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EM_App_5ms_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EM_App_5ms_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EM_App_5ms_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EM_App_5ms_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(EM_App_5ms_C2);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EM_App_10ms_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EM_App_10ms_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EM_App_10ms_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EM_App_10ms_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(EM_App_10ms_C2);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EM_App_20ms_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EM_App_20ms_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EM_App_20ms_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EM_App_20ms_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(EM_App_20ms_C2);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(EM_App_50ms_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(EM_App_50ms_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(EM_App_50ms_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(EM_App_50ms_C2);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(EM_App_50ms_C2);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Init_Task_C3);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Init_Task_C3);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Init_Task_C3);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Init_Task_C3);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Init_Task_C3);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsTask_10ms_C3);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsTask_10ms_C3);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_10ms_C3);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_10ms_C3);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_10ms_C3);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsTask_5ms_C3);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsTask_5ms_C3);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_5ms_C3);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_5ms_C3);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_5ms_C3);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsTask_20ms_C4);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsTask_20ms_C4);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_20ms_C4);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_20ms_C4);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_20ms_C4);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Init_Task_C4);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Init_Task_C4);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Init_Task_C4);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Init_Task_C4);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Init_Task_C4);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsTask_20ms_C5);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsTask_20ms_C5);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_20ms_C5);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_20ms_C5);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_20ms_C5);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(Init_Task_C5);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(Init_Task_C5);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(Init_Task_C5);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(Init_Task_C5);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Init_Task_C5);
#endif  /* OS_ASM */

#define OS_NTASKS               29
#define OS_NETASKS              5
#define OS_NTASKSEXECTIMELIMIT  0
#define OS_NTASKSINTLOCKLIMIT   0
#define OS_NTASKSRESLOCKLIMIT   0
#define OS_TASKCONFIG  OS_TASKCONFIG_INIT(    /* EM_Bsw_10ms_C0 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core0[0],  \
  /* Run priority */                   1u,  \
  /* Queuing priority */               1u,  \
  /* Activation index */               1,  \
  /* Task entry */                     &OS_TASK_EM_Bsw_10ms_C0,  \
  /* Stack base */                     &OS_taskStack0_slot3[0],  \
  /* Stack size */                     1032u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          (OS_TF_EXTENDED),  \
  /* Task ID */                        EM_Bsw_10ms_C0,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(EM_Bsw_10ms_C0),  \
  /* end of data/bss */                &OS_TOOL_MR_END(EM_Bsw_10ms_C0),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(EM_Bsw_10ms_C0),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(EM_Bsw_10ms_C0),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C0],  \
  /* Permissions */                    0x3fu,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* EM_Bsw_Task_C0 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core0[1],  \
  /* Run priority */                   0u,  \
  /* Queuing priority */               0u,  \
  /* Activation index */               2,  \
  /* Task entry */                     &OS_TASK_EM_Bsw_Task_C0,  \
  /* Stack base */                     &OS_taskStack0_slot4[0],  \
  /* Stack size */                     1032u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          (OS_TF_EXTENDED),  \
  /* Task ID */                        EM_Bsw_Task_C0,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(EM_Bsw_Task_C0),  \
  /* end of data/bss */                &OS_TOOL_MR_END(EM_Bsw_Task_C0),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(EM_Bsw_Task_C0),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(EM_Bsw_Task_C0),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C0],  \
  /* Permissions */                    0x3fu,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* EM_Bsw_20ms_C1 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core1[0],  \
  /* Run priority */                   1u,  \
  /* Queuing priority */               1u,  \
  /* Activation index */               1,  \
  /* Task entry */                     &OS_TASK_EM_Bsw_20ms_C1,  \
  /* Stack base */                     &OS_taskStack1_slot3[0],  \
  /* Stack size */                     1032u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          (OS_TF_EXTENDED),  \
  /* Task ID */                        EM_Bsw_20ms_C1,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(EM_Bsw_20ms_C1),  \
  /* end of data/bss */                &OS_TOOL_MR_END(EM_Bsw_20ms_C1),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(EM_Bsw_20ms_C1),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(EM_Bsw_20ms_C1),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C1],  \
  /* Permissions */                    0x3fu,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* EM_Bsw_20ms_C2 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core2[0],  \
  /* Run priority */                   1u,  \
  /* Queuing priority */               1u,  \
  /* Activation index */               1,  \
  /* Task entry */                     &OS_TASK_EM_Bsw_20ms_C2,  \
  /* Stack base */                     &OS_taskStack2_slot1[0],  \
  /* Stack size */                     520u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          (OS_TF_EXTENDED),  \
  /* Task ID */                        EM_Bsw_20ms_C2,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(EM_Bsw_20ms_C2),  \
  /* end of data/bss */                &OS_TOOL_MR_END(EM_Bsw_20ms_C2),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(EM_Bsw_20ms_C2),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(EM_Bsw_20ms_C2),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C2],  \
  /* Permissions */                    0x3fu,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_20ms_C3 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core3[0],  \
  /* Run priority */                   0u,  \
  /* Queuing priority */               0u,  \
  /* Activation index */               1,  \
  /* Task entry */                     &OS_TASK_OsTask_20ms_C3,  \
  /* Stack base */                     &OS_taskStack3_slot0[0],  \
  /* Stack size */                     520u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          (OS_TF_EXTENDED),  \
  /* Task ID */                        OsTask_20ms_C3,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(OsTask_20ms_C3),  \
  /* end of data/bss */                &OS_TOOL_MR_END(OsTask_20ms_C3),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(OsTask_20ms_C3),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(OsTask_20ms_C3),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C3],  \
  /* Permissions */                    0x3fu,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* EM_Bsw_Start_Init_C0 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core0[2],  \
  /* Run priority */                   5u,  \
  /* Queuing priority */               5u,  \
  /* Activation index */               3,  \
  /* Task entry */                     &OS_TASK_EM_Bsw_Start_Init_C0,  \
  /* Stack base */                     &OS_taskStack0_slot5[0],  \
  /* Stack size */                     520u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          (OS_TF_NONPREEMPT),  \
  /* Task ID */                        EM_Bsw_Start_Init_C0,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(EM_Bsw_Start_Init_C0),  \
  /* end of data/bss */                &OS_TOOL_MR_END(EM_Bsw_Start_Init_C0),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(EM_Bsw_Start_Init_C0),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(EM_Bsw_Start_Init_C0),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C0],  \
  /* Permissions */                    0x1u,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* EM_Bsw_Init_C0 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core0[3],  \
  /* Run priority */                   5u,  \
  /* Queuing priority */               4u,  \
  /* Activation index */               4,  \
  /* Task entry */                     &OS_TASK_EM_Bsw_Init_C0,  \
  /* Stack base */                     &OS_taskStack0_slot6[0],  \
  /* Stack size */                     520u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          (OS_TF_NONPREEMPT),  \
  /* Task ID */                        EM_Bsw_Init_C0,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(EM_Bsw_Init_C0),  \
  /* end of data/bss */                &OS_TOOL_MR_END(EM_Bsw_Init_C0),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(EM_Bsw_Init_C0),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(EM_Bsw_Init_C0),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C0],  \
  /* Permissions */                    0x1u,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* EM_App_5ms_C0 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core0[4],  \
  /* Run priority */                   3u,  \
  /* Queuing priority */               3u,  \
  /* Activation index */               5,  \
  /* Task entry */                     &OS_TASK_EM_App_5ms_C0,  \
  /* Stack base */                     &OS_taskStack0_slot1[0],  \
  /* Stack size */                     4104u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        EM_App_5ms_C0,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(EM_App_5ms_C0),  \
  /* end of data/bss */                &OS_TOOL_MR_END(EM_App_5ms_C0),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(EM_App_5ms_C0),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(EM_App_5ms_C0),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C0],  \
  /* Permissions */                    0x3fu,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* EM_App_10ms_C0 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core0[5],  \
  /* Run priority */                   1u,  \
  /* Queuing priority */               1u,  \
  /* Activation index */               6,  \
  /* Task entry */                     &OS_TASK_EM_App_10ms_C0,  \
  /* Stack base */                     &OS_taskStack0_slot0[0],  \
  /* Stack size */                     6152u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        EM_App_10ms_C0,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(EM_App_10ms_C0),  \
  /* end of data/bss */                &OS_TOOL_MR_END(EM_App_10ms_C0),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(EM_App_10ms_C0),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(EM_App_10ms_C0),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C0],  \
  /* Permissions */                    0x3fu,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* EM_App_25ms_C0 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core0[6],  \
  /* Run priority */                   2u,  \
  /* Queuing priority */               2u,  \
  /* Activation index */               7,  \
  /* Task entry */                     &OS_TASK_EM_App_25ms_C0,  \
  /* Stack base */                     &OS_taskStack0_slot2[0],  \
  /* Stack size */                     4104u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        EM_App_25ms_C0,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(EM_App_25ms_C0),  \
  /* end of data/bss */                &OS_TOOL_MR_END(EM_App_25ms_C0),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(EM_App_25ms_C0),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(EM_App_25ms_C0),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C0],  \
  /* Permissions */                    0x3fu,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* EM_Bsw_Init_C1 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core1[1],  \
  /* Run priority */                   5u,  \
  /* Queuing priority */               5u,  \
  /* Activation index */               2,  \
  /* Task entry */                     &OS_TASK_EM_Bsw_Init_C1,  \
  /* Stack base */                     &OS_taskStack1_slot4[0],  \
  /* Stack size */                     520u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          (OS_TF_NONPREEMPT),  \
  /* Task ID */                        EM_Bsw_Init_C1,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(EM_Bsw_Init_C1),  \
  /* end of data/bss */                &OS_TOOL_MR_END(EM_Bsw_Init_C1),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(EM_Bsw_Init_C1),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(EM_Bsw_Init_C1),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C1],  \
  /* Permissions */                    0x2u,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* EM_Uss_Init_C1 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core1[2],  \
  /* Run priority */                   5u,  \
  /* Queuing priority */               4u,  \
  /* Activation index */               3,  \
  /* Task entry */                     &OS_TASK_EM_Uss_Init_C1,  \
  /* Stack base */                     &OS_taskStack1_slot2[0],  \
  /* Stack size */                     1544u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          (OS_TF_NONPREEMPT),  \
  /* Task ID */                        EM_Uss_Init_C1,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(EM_Uss_Init_C1),  \
  /* end of data/bss */                &OS_TOOL_MR_END(EM_Uss_Init_C1),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(EM_Uss_Init_C1),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(EM_Uss_Init_C1),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C1],  \
  /* Permissions */                    0x2u,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* EM_Uss_5ms_C1 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core1[3],  \
  /* Run priority */                   3u,  \
  /* Queuing priority */               3u,  \
  /* Activation index */               4,  \
  /* Task entry */                     &OS_TASK_EM_Uss_5ms_C1,  \
  /* Stack base */                     &OS_taskStack1_slot1[0],  \
  /* Stack size */                     4104u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        EM_Uss_5ms_C1,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(EM_Uss_5ms_C1),  \
  /* end of data/bss */                &OS_TOOL_MR_END(EM_Uss_5ms_C1),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(EM_Uss_5ms_C1),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(EM_Uss_5ms_C1),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C1],  \
  /* Permissions */                    0x3fu,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* EM_Uss_10ms_C1 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core1[4],  \
  /* Run priority */                   2u,  \
  /* Queuing priority */               2u,  \
  /* Activation index */               5,  \
  /* Task entry */                     &OS_TASK_EM_Uss_10ms_C1,  \
  /* Stack base */                     &OS_taskStack1_slot5[0],  \
  /* Stack size */                     520u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        EM_Uss_10ms_C1,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(EM_Uss_10ms_C1),  \
  /* end of data/bss */                &OS_TOOL_MR_END(EM_Uss_10ms_C1),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(EM_Uss_10ms_C1),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(EM_Uss_10ms_C1),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C1],  \
  /* Permissions */                    0x3fu,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* EM_Uss_20ms_C1 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core1[5],  \
  /* Run priority */                   1u,  \
  /* Queuing priority */               1u,  \
  /* Activation index */               6,  \
  /* Task entry */                     &OS_TASK_EM_Uss_20ms_C1,  \
  /* Stack base */                     &OS_taskStack1_slot6[0],  \
  /* Stack size */                     520u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        EM_Uss_20ms_C1,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(EM_Uss_20ms_C1),  \
  /* end of data/bss */                &OS_TOOL_MR_END(EM_Uss_20ms_C1),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(EM_Uss_20ms_C1),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(EM_Uss_20ms_C1),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C1],  \
  /* Permissions */                    0x3fu,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* EM_Uss_50ms_C1 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core1[6],  \
  /* Run priority */                   0u,  \
  /* Queuing priority */               0u,  \
  /* Activation index */               7,  \
  /* Task entry */                     &OS_TASK_EM_Uss_50ms_C1,  \
  /* Stack base */                     &OS_taskStack1_slot0[0],  \
  /* Stack size */                     40968u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        EM_Uss_50ms_C1,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(EM_Uss_50ms_C1),  \
  /* end of data/bss */                &OS_TOOL_MR_END(EM_Uss_50ms_C1),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(EM_Uss_50ms_C1),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(EM_Uss_50ms_C1),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C1],  \
  /* Permissions */                    0x3fu,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* EM_Bsw_Init_C2 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core2[1],  \
  /* Run priority */                   5u,  \
  /* Queuing priority */               5u,  \
  /* Activation index */               2,  \
  /* Task entry */                     &OS_TASK_EM_Bsw_Init_C2,  \
  /* Stack base */                     &OS_taskStack2_slot2[0],  \
  /* Stack size */                     520u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          (OS_TF_NONPREEMPT),  \
  /* Task ID */                        EM_Bsw_Init_C2,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(EM_Bsw_Init_C2),  \
  /* end of data/bss */                &OS_TOOL_MR_END(EM_Bsw_Init_C2),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(EM_Bsw_Init_C2),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(EM_Bsw_Init_C2),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C2],  \
  /* Permissions */                    0x4u,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* EM_App_Init_C2 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core2[2],  \
  /* Run priority */                   5u,  \
  /* Queuing priority */               4u,  \
  /* Activation index */               3,  \
  /* Task entry */                     &OS_TASK_EM_App_Init_C2,  \
  /* Stack base */                     &OS_taskStack2_slot3[0],  \
  /* Stack size */                     520u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          (OS_TF_NONPREEMPT),  \
  /* Task ID */                        EM_App_Init_C2,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(EM_App_Init_C2),  \
  /* end of data/bss */                &OS_TOOL_MR_END(EM_App_Init_C2),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(EM_App_Init_C2),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(EM_App_Init_C2),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C2],  \
  /* Permissions */                    0x4u,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* EM_App_5ms_C2 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core2[3],  \
  /* Run priority */                   3u,  \
  /* Queuing priority */               3u,  \
  /* Activation index */               4,  \
  /* Task entry */                     &OS_TASK_EM_App_5ms_C2,  \
  /* Stack base */                     &OS_taskStack2_slot4[0],  \
  /* Stack size */                     520u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        EM_App_5ms_C2,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(EM_App_5ms_C2),  \
  /* end of data/bss */                &OS_TOOL_MR_END(EM_App_5ms_C2),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(EM_App_5ms_C2),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(EM_App_5ms_C2),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C2],  \
  /* Permissions */                    0x3fu,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* EM_App_10ms_C2 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core2[4],  \
  /* Run priority */                   2u,  \
  /* Queuing priority */               2u,  \
  /* Activation index */               5,  \
  /* Task entry */                     &OS_TASK_EM_App_10ms_C2,  \
  /* Stack base */                     &OS_taskStack2_slot5[0],  \
  /* Stack size */                     520u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        EM_App_10ms_C2,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(EM_App_10ms_C2),  \
  /* end of data/bss */                &OS_TOOL_MR_END(EM_App_10ms_C2),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(EM_App_10ms_C2),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(EM_App_10ms_C2),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C2],  \
  /* Permissions */                    0x3fu,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* EM_App_20ms_C2 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core2[5],  \
  /* Run priority */                   1u,  \
  /* Queuing priority */               1u,  \
  /* Activation index */               6,  \
  /* Task entry */                     &OS_TASK_EM_App_20ms_C2,  \
  /* Stack base */                     &OS_taskStack2_slot0[0],  \
  /* Stack size */                     4104u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        EM_App_20ms_C2,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(EM_App_20ms_C2),  \
  /* end of data/bss */                &OS_TOOL_MR_END(EM_App_20ms_C2),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(EM_App_20ms_C2),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(EM_App_20ms_C2),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C2],  \
  /* Permissions */                    0x3fu,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* EM_App_50ms_C2 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core2[6],  \
  /* Run priority */                   0u,  \
  /* Queuing priority */               0u,  \
  /* Activation index */               7,  \
  /* Task entry */                     &OS_TASK_EM_App_50ms_C2,  \
  /* Stack base */                     &OS_taskStack2_slot6[0],  \
  /* Stack size */                     520u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        EM_App_50ms_C2,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(EM_App_50ms_C2),  \
  /* end of data/bss */                &OS_TOOL_MR_END(EM_App_50ms_C2),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(EM_App_50ms_C2),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(EM_App_50ms_C2),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C2],  \
  /* Permissions */                    0x3fu,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Init_Task_C3 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core3[1],  \
  /* Run priority */                   0u,  \
  /* Queuing priority */               0u,  \
  /* Activation index */               2,  \
  /* Task entry */                     &OS_TASK_Init_Task_C3,  \
  /* Stack base */                     &OS_taskStack3_slot1[0],  \
  /* Stack size */                     520u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          (OS_TF_NONPREEMPT),  \
  /* Task ID */                        Init_Task_C3,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(Init_Task_C3),  \
  /* end of data/bss */                &OS_TOOL_MR_END(Init_Task_C3),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(Init_Task_C3),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(Init_Task_C3),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C3],  \
  /* Permissions */                    0x8u,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_10ms_C3 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core3[2],  \
  /* Run priority */                   0u,  \
  /* Queuing priority */               0u,  \
  /* Activation index */               3,  \
  /* Task entry */                     &OS_TASK_OsTask_10ms_C3,  \
  /* Stack base */                     &OS_taskStack3_slot1[0],  \
  /* Stack size */                     520u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        OsTask_10ms_C3,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(OsTask_10ms_C3),  \
  /* end of data/bss */                &OS_TOOL_MR_END(OsTask_10ms_C3),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(OsTask_10ms_C3),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(OsTask_10ms_C3),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C3],  \
  /* Permissions */                    0x3fu,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_5ms_C3 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core3[3],  \
  /* Run priority */                   0u,  \
  /* Queuing priority */               0u,  \
  /* Activation index */               4,  \
  /* Task entry */                     &OS_TASK_OsTask_5ms_C3,  \
  /* Stack base */                     &OS_taskStack3_slot1[0],  \
  /* Stack size */                     520u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        OsTask_5ms_C3,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(OsTask_5ms_C3),  \
  /* end of data/bss */                &OS_TOOL_MR_END(OsTask_5ms_C3),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(OsTask_5ms_C3),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(OsTask_5ms_C3),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C3],  \
  /* Permissions */                    0x3fu,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_20ms_C4 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core4[0],  \
  /* Run priority */                   0u,  \
  /* Queuing priority */               0u,  \
  /* Activation index */               1,  \
  /* Task entry */                     &OS_TASK_OsTask_20ms_C4,  \
  /* Stack base */                     &OS_taskStack4[0],  \
  /* Stack size */                     520u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        OsTask_20ms_C4,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(OsTask_20ms_C4),  \
  /* end of data/bss */                &OS_TOOL_MR_END(OsTask_20ms_C4),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(OsTask_20ms_C4),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(OsTask_20ms_C4),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C4],  \
  /* Permissions */                    0x3fu,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Init_Task_C4 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core4[1],  \
  /* Run priority */                   0u,  \
  /* Queuing priority */               0u,  \
  /* Activation index */               2,  \
  /* Task entry */                     &OS_TASK_Init_Task_C4,  \
  /* Stack base */                     &OS_taskStack4[0],  \
  /* Stack size */                     520u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          (OS_TF_NONPREEMPT),  \
  /* Task ID */                        Init_Task_C4,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(Init_Task_C4),  \
  /* end of data/bss */                &OS_TOOL_MR_END(Init_Task_C4),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(Init_Task_C4),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(Init_Task_C4),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C4],  \
  /* Permissions */                    0x10u,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_20ms_C5 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core5[0],  \
  /* Run priority */                   0u,  \
  /* Queuing priority */               0u,  \
  /* Activation index */               1,  \
  /* Task entry */                     &OS_TASK_OsTask_20ms_C5,  \
  /* Stack base */                     &OS_taskStack5[0],  \
  /* Stack size */                     520u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        OsTask_20ms_C5,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(OsTask_20ms_C5),  \
  /* end of data/bss */                &OS_TOOL_MR_END(OsTask_20ms_C5),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(OsTask_20ms_C5),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(OsTask_20ms_C5),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C5],  \
  /* Permissions */                    0x3fu,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Init_Task_C5 */  \
  /* Dynamic task structure */         &OS_taskDynamic_core5[1],  \
  /* Run priority */                   0u,  \
  /* Queuing priority */               0u,  \
  /* Activation index */               2,  \
  /* Task entry */                     &OS_TASK_Init_Task_C5,  \
  /* Stack base */                     &OS_taskStack5[0],  \
  /* Stack size */                     520u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          (OS_TF_NONPREEMPT),  \
  /* Task ID */                        Init_Task_C5,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(Init_Task_C5),  \
  /* end of data/bss */                &OS_TOOL_MR_END(Init_Task_C5),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(Init_Task_C5),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(Init_Task_C5),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_C5],  \
  /* Permissions */                    0x20u,  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
)
#define OS_NTASKS_CORE0  7
#define OS_NTASKS_CORE1  7
#define OS_NTASKS_CORE2  7
#define OS_NTASKS_CORE3  4
#define OS_NTASKS_CORE4  2
#define OS_NTASKS_CORE5  2

/*===================================================================
 * Tasks Common Scheduling
 *==================================================================*/
#define OS_NPRIORITIES_CORE0  6
#define OS_NPRIORITIES_CORE1  6
#define OS_NPRIORITIES_CORE2  6
#define OS_NPRIORITIES_CORE3  1
#define OS_NPRIORITIES_CORE4  1
#define OS_NPRIORITIES_CORE5  1

/*===================================================================
 * Tasks Linked List Scheduling
 *==================================================================*/
#define OS_NTASKACCOUNTING  0
#define OS_NTASKACTIVATIONS  29
#define OS_NTASKACCOUNTING_CORE0   0
#define OS_NTASKACTIVATIONS_CORE0  7
#define OS_TASKACTIVATIONS_CORE0   \
  /* 0 */ &OS_taskTable[EM_Bsw_10ms_C0],    \
  /* 1 */ &OS_taskTable[EM_Bsw_Task_C0],    \
  /* 2 */ &OS_taskTable[EM_Bsw_Start_Init_C0],    \
  /* 3 */ &OS_taskTable[EM_Bsw_Init_C0],    \
  /* 4 */ &OS_taskTable[EM_App_5ms_C0],    \
  /* 5 */ &OS_taskTable[EM_App_10ms_C0],    \
  /* 6 */ &OS_taskTable[EM_App_25ms_C0]
#define OS_NTASKACCOUNTING_CORE1   0
#define OS_NTASKACTIVATIONS_CORE1  7
#define OS_TASKACTIVATIONS_CORE1   \
  /* 0 */ &OS_taskTable[EM_Bsw_20ms_C1],    \
  /* 1 */ &OS_taskTable[EM_Bsw_Init_C1],    \
  /* 2 */ &OS_taskTable[EM_Uss_Init_C1],    \
  /* 3 */ &OS_taskTable[EM_Uss_5ms_C1],    \
  /* 4 */ &OS_taskTable[EM_Uss_10ms_C1],    \
  /* 5 */ &OS_taskTable[EM_Uss_20ms_C1],    \
  /* 6 */ &OS_taskTable[EM_Uss_50ms_C1]
#define OS_NTASKACCOUNTING_CORE2   0
#define OS_NTASKACTIVATIONS_CORE2  7
#define OS_TASKACTIVATIONS_CORE2   \
  /* 0 */ &OS_taskTable[EM_Bsw_20ms_C2],    \
  /* 1 */ &OS_taskTable[EM_Bsw_Init_C2],    \
  /* 2 */ &OS_taskTable[EM_App_Init_C2],    \
  /* 3 */ &OS_taskTable[EM_App_5ms_C2],    \
  /* 4 */ &OS_taskTable[EM_App_10ms_C2],    \
  /* 5 */ &OS_taskTable[EM_App_20ms_C2],    \
  /* 6 */ &OS_taskTable[EM_App_50ms_C2]
#define OS_NTASKACCOUNTING_CORE3   0
#define OS_NTASKACTIVATIONS_CORE3  4
#define OS_TASKACTIVATIONS_CORE3   \
  /* 0 */ &OS_taskTable[OsTask_20ms_C3],    \
  /* 1 */ &OS_taskTable[Init_Task_C3],    \
  /* 2 */ &OS_taskTable[OsTask_10ms_C3],    \
  /* 3 */ &OS_taskTable[OsTask_5ms_C3]
#define OS_NTASKACCOUNTING_CORE4   0
#define OS_NTASKACTIVATIONS_CORE4  2
#define OS_TASKACTIVATIONS_CORE4   \
  /* 0 */ &OS_taskTable[OsTask_20ms_C4],    \
  /* 1 */ &OS_taskTable[Init_Task_C4]
#define OS_NTASKACCOUNTING_CORE5   0
#define OS_NTASKACTIVATIONS_CORE5  2
#define OS_TASKACTIVATIONS_CORE5   \
  /* 0 */ &OS_taskTable[OsTask_20ms_C5],    \
  /* 1 */ &OS_taskTable[Init_Task_C5]

/*===================================================================
 * Tricore Interrupts
 *==================================================================*/
#define OS_IRQ07_NAME      OS_VECTOR_GETH0
#define OS_IRQ07_ISRID     ETHSR0_ISR
#define OS_IRQ07_ENTRY     OS_Cat2Handler
#define OS_IRQ07_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ07_EXIT      OS_Cat2Exit
#define OS_IRQ07_BISRPRIO  32
#define OS_IRQ08_NAME      OS_VECTOR_GETH2
#define OS_IRQ08_ISRID     ETHSR2_ISR
#define OS_IRQ08_ENTRY     OS_Cat2Handler
#define OS_IRQ08_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ08_EXIT      OS_Cat2Exit
#define OS_IRQ08_BISRPRIO  32
#define OS_IRQ09_NAME      OS_VECTOR_GETH6
#define OS_IRQ09_ISRID     ETHSR6_ISR
#define OS_IRQ09_ENTRY     OS_Cat2Handler
#define OS_IRQ09_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ09_EXIT      OS_Cat2Exit
#define OS_IRQ09_BISRPRIO  32
#define OS_IRQ0a_NAME      OS_VECTOR_DMACH0
#define OS_IRQ0a_ISRID     DMACH0SR_ISR
#define OS_IRQ0a_ENTRY     OS_Cat2Handler
#define OS_IRQ0a_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ0a_EXIT      OS_Cat2Exit
#define OS_IRQ0a_BISRPRIO  32
#define OS_IRQ0b_NAME      OS_VECTOR_DMACH1
#define OS_IRQ0b_ISRID     DMACH1SR_ISR
#define OS_IRQ0b_ENTRY     OS_Cat2Handler
#define OS_IRQ0b_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ0b_EXIT      OS_Cat2Exit
#define OS_IRQ0b_BISRPRIO  32
#define OS_IRQ0c_NAME      OS_VECTOR_QSPI0PT
#define OS_IRQ0c_ISRID     QSPI0PT_ISR
#define OS_IRQ0c_ENTRY     OS_Cat2Handler
#define OS_IRQ0c_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ0c_EXIT      OS_Cat2Exit
#define OS_IRQ0c_BISRPRIO  32
#define OS_IRQ0d_NAME      OS_VECTOR_QSPI0ERR
#define OS_IRQ0d_ISRID     QSPI0ERR_ISR
#define OS_IRQ0d_ENTRY     OS_Cat2Handler
#define OS_IRQ0d_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ0d_EXIT      OS_Cat2Exit
#define OS_IRQ0d_BISRPRIO  32
#define OS_IRQ0e_NAME      OS_VECTOR_DMACH5
#define OS_IRQ0e_ISRID     DMACH5SR_ISR
#define OS_IRQ0e_ENTRY     OS_Cat2Handler
#define OS_IRQ0e_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ0e_EXIT      OS_Cat2Exit
#define OS_IRQ0e_BISRPRIO  32
#define OS_IRQ0f_NAME      OS_VECTOR_DMACH6
#define OS_IRQ0f_ISRID     DMACH6SR_ISR
#define OS_IRQ0f_ENTRY     OS_Cat2Handler
#define OS_IRQ0f_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ0f_EXIT      OS_Cat2Exit
#define OS_IRQ0f_BISRPRIO  32
#define OS_IRQ10_NAME      OS_VECTOR_CAN0INT12
#define OS_IRQ10_ISRID     CAN0SR12_ISR
#define OS_IRQ10_ENTRY     OS_Cat2Handler
#define OS_IRQ10_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ10_EXIT      OS_Cat2Exit
#define OS_IRQ10_BISRPRIO  32
#define OS_IRQ11_NAME      OS_VECTOR_CAN0INT13
#define OS_IRQ11_ISRID     CAN0SR13_ISR
#define OS_IRQ11_ENTRY     OS_Cat2Handler
#define OS_IRQ11_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ11_EXIT      OS_Cat2Exit
#define OS_IRQ11_BISRPRIO  32
#define OS_IRQ12_NAME      OS_VECTOR_CAN0INT14
#define OS_IRQ12_ISRID     CAN0SR14_ISR
#define OS_IRQ12_ENTRY     OS_Cat2Handler
#define OS_IRQ12_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ12_EXIT      OS_Cat2Exit
#define OS_IRQ12_BISRPRIO  32
#define OS_IRQ13_NAME      OS_VECTOR_CAN0INT15
#define OS_IRQ13_ISRID     CAN0SR15_ISR
#define OS_IRQ13_ENTRY     OS_Cat2Handler
#define OS_IRQ13_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ13_EXIT      OS_Cat2Exit
#define OS_IRQ13_BISRPRIO  32
#define OS_IRQ14_NAME      OS_VECTOR_CAN1INT0
#define OS_IRQ14_ISRID     CAN1SR0_ISR
#define OS_IRQ14_ENTRY     OS_Cat2Handler
#define OS_IRQ14_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ14_EXIT      OS_Cat2Exit
#define OS_IRQ14_BISRPRIO  32
#define OS_IRQ15_NAME      OS_VECTOR_CAN1INT1
#define OS_IRQ15_ISRID     CAN1SR1_ISR
#define OS_IRQ15_ENTRY     OS_Cat2Handler
#define OS_IRQ15_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ15_EXIT      OS_Cat2Exit
#define OS_IRQ15_BISRPRIO  32
#define OS_IRQ16_NAME      OS_VECTOR_CAN1INT2
#define OS_IRQ16_ISRID     CAN1SR2_ISR
#define OS_IRQ16_ENTRY     OS_Cat2Handler
#define OS_IRQ16_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ16_EXIT      OS_Cat2Exit
#define OS_IRQ16_BISRPRIO  32
#define OS_IRQ17_NAME      OS_VECTOR_CAN1INT3
#define OS_IRQ17_ISRID     CAN1SR3_ISR
#define OS_IRQ17_ENTRY     OS_Cat2Handler
#define OS_IRQ17_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ17_EXIT      OS_Cat2Exit
#define OS_IRQ17_BISRPRIO  32
#define OS_IRQ18_NAME      OS_VECTOR_GPT120T2
#define OS_IRQ18_ISRID     GPT12_T2_ISR
#define OS_IRQ18_ENTRY     OS_Cat2Handler
#define OS_IRQ18_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ18_EXIT      OS_Cat2Exit
#define OS_IRQ18_BISRPRIO  32
#define OS_IRQ19_NAME      OS_VECTOR_GPT120T3
#define OS_IRQ19_ISRID     GPT12_T3_ISR
#define OS_IRQ19_ENTRY     OS_Cat2Handler
#define OS_IRQ19_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ19_EXIT      OS_Cat2Exit
#define OS_IRQ19_BISRPRIO  32
#define OS_IRQ1a_NAME      OS_VECTOR_GPT120T6
#define OS_IRQ1a_ISRID     GPT12_T6_ISR
#define OS_IRQ1a_ENTRY     OS_Cat2Handler
#define OS_IRQ1a_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ1a_EXIT      OS_Cat2Exit
#define OS_IRQ1a_BISRPRIO  32
#define OS_IRQ21_NAME      OS_VECTOR_DMACH61
#define OS_IRQ21_ISRID     EmUSS01_ISR
#define OS_IRQ21_ENTRY     OS_Cat1Handler
#define OS_IRQ21_TYPE      OS_VECTOR_TYPE_CAT1
#define OS_IRQ21_EXIT      OS_Cat1Exit
#define OS_IRQ21_BISRPRIO  44
#define OS_IRQ22_NAME      OS_VECTOR_DMACH62
#define OS_IRQ22_ISRID     EmUSS02_ISR
#define OS_IRQ22_ENTRY     OS_Cat1Handler
#define OS_IRQ22_TYPE      OS_VECTOR_TYPE_CAT1
#define OS_IRQ22_EXIT      OS_Cat1Exit
#define OS_IRQ22_BISRPRIO  44
#define OS_IRQ23_NAME      OS_VECTOR_DMACH63
#define OS_IRQ23_ISRID     EmUSS03_ISR
#define OS_IRQ23_ENTRY     OS_Cat1Handler
#define OS_IRQ23_TYPE      OS_VECTOR_TYPE_CAT1
#define OS_IRQ23_EXIT      OS_Cat1Exit
#define OS_IRQ23_BISRPRIO  44
#define OS_IRQ24_NAME      OS_VECTOR_DMACH64
#define OS_IRQ24_ISRID     EmUSS04_ISR
#define OS_IRQ24_ENTRY     OS_Cat1Handler
#define OS_IRQ24_TYPE      OS_VECTOR_TYPE_CAT1
#define OS_IRQ24_EXIT      OS_Cat1Exit
#define OS_IRQ24_BISRPRIO  44
#define OS_IRQ25_NAME      OS_VECTOR_DMACH65
#define OS_IRQ25_ISRID     EmUSS05_ISR
#define OS_IRQ25_ENTRY     OS_Cat1Handler
#define OS_IRQ25_TYPE      OS_VECTOR_TYPE_CAT1
#define OS_IRQ25_EXIT      OS_Cat1Exit
#define OS_IRQ25_BISRPRIO  44
#define OS_IRQ26_NAME      OS_VECTOR_DMACH66
#define OS_IRQ26_ISRID     EmUSS06_ISR
#define OS_IRQ26_ENTRY     OS_Cat1Handler
#define OS_IRQ26_TYPE      OS_VECTOR_TYPE_CAT1
#define OS_IRQ26_EXIT      OS_Cat1Exit
#define OS_IRQ26_BISRPRIO  44
#define OS_IRQ27_NAME      OS_VECTOR_DMACH67
#define OS_IRQ27_ISRID     EmUSS07_ISR
#define OS_IRQ27_ENTRY     OS_Cat1Handler
#define OS_IRQ27_TYPE      OS_VECTOR_TYPE_CAT1
#define OS_IRQ27_EXIT      OS_Cat1Exit
#define OS_IRQ27_BISRPRIO  44
#define OS_IRQ28_NAME      OS_VECTOR_DMACH68
#define OS_IRQ28_ISRID     EmUSS08_ISR
#define OS_IRQ28_ENTRY     OS_Cat1Handler
#define OS_IRQ28_TYPE      OS_VECTOR_TYPE_CAT1
#define OS_IRQ28_EXIT      OS_Cat1Exit
#define OS_IRQ28_BISRPRIO  44
#define OS_IRQ29_NAME      OS_VECTOR_DMACH69
#define OS_IRQ29_ISRID     EmUSS09_ISR
#define OS_IRQ29_ENTRY     OS_Cat1Handler
#define OS_IRQ29_TYPE      OS_VECTOR_TYPE_CAT1
#define OS_IRQ29_EXIT      OS_Cat1Exit
#define OS_IRQ29_BISRPRIO  44
#define OS_IRQ2a_NAME      OS_VECTOR_DMACH70
#define OS_IRQ2a_ISRID     EmUSS10_ISR
#define OS_IRQ2a_ENTRY     OS_Cat1Handler
#define OS_IRQ2a_TYPE      OS_VECTOR_TYPE_CAT1
#define OS_IRQ2a_EXIT      OS_Cat1Exit
#define OS_IRQ2a_BISRPRIO  44
#define OS_IRQ2b_NAME      OS_VECTOR_DMACH71
#define OS_IRQ2b_ISRID     EmUSS11_ISR
#define OS_IRQ2b_ENTRY     OS_Cat1Handler
#define OS_IRQ2b_TYPE      OS_VECTOR_TYPE_CAT1
#define OS_IRQ2b_EXIT      OS_Cat1Exit
#define OS_IRQ2b_BISRPRIO  44
#define OS_IRQ2c_NAME      OS_VECTOR_DMACH72
#define OS_IRQ2c_ISRID     EmUSS12_ISR
#define OS_IRQ2c_ENTRY     OS_Cat1Handler
#define OS_IRQ2c_TYPE      OS_VECTOR_TYPE_CAT1
#define OS_IRQ2c_EXIT      OS_Cat1Exit
#define OS_IRQ2c_BISRPRIO  44
#define OS_IRQ20_NAME      OS_VECTOR_GPSR20
#define OS_IRQ20_ISRID     CrossCoreNotify0
#define OS_IRQ20_ENTRY     OS_CrossCoreNotifyIsr
#define OS_IRQ20_TYPE      OS_VECTOR_TYPE_CATCC
#define OS_IRQ20_EXIT      OS_CatCCExit
#define OS_IRQ20_BISRPRIO  32
#define OS_IRQ01_NAME      OS_VECTOR_STM0SR0
#define OS_IRQ01_ISRID     Os_Counter_STM0_T0
#define OS_IRQ01_ENTRY     OS_Cat2Handler
#define OS_IRQ01_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ01_EXIT      OS_Cat2Exit
#define OS_IRQ01_BISRPRIO  32
#define OS_IRQ02_NAME      OS_VECTOR_STM1SR0
#define OS_IRQ02_ISRID     Os_Counter_STM1_T0
#define OS_IRQ02_ENTRY     OS_Cat2Handler
#define OS_IRQ02_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ02_EXIT      OS_Cat2Exit
#define OS_IRQ02_BISRPRIO  32
#define OS_IRQ03_NAME      OS_VECTOR_STM2SR0
#define OS_IRQ03_ISRID     Os_Counter_STM2_T0
#define OS_IRQ03_ENTRY     OS_Cat2Handler
#define OS_IRQ03_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ03_EXIT      OS_Cat2Exit
#define OS_IRQ03_BISRPRIO  32
#define OS_IRQ04_NAME      OS_VECTOR_STM3SR0
#define OS_IRQ04_ISRID     Os_Counter_STM3_T0
#define OS_IRQ04_ENTRY     OS_Cat2Handler
#define OS_IRQ04_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ04_EXIT      OS_Cat2Exit
#define OS_IRQ04_BISRPRIO  32
#define OS_IRQ05_NAME      OS_VECTOR_STM4SR0
#define OS_IRQ05_ISRID     Os_Counter_STM4_T0
#define OS_IRQ05_ENTRY     OS_Cat2Handler
#define OS_IRQ05_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ05_EXIT      OS_Cat2Exit
#define OS_IRQ05_BISRPRIO  32
#define OS_IRQ06_NAME      OS_VECTOR_STM5SR0
#define OS_IRQ06_ISRID     Os_Counter_STM5_T0
#define OS_IRQ06_ENTRY     OS_Cat2Handler
#define OS_IRQ06_TYPE      OS_VECTOR_TYPE_CAT2
#define OS_IRQ06_EXIT      OS_Cat2Exit
#define OS_IRQ06_BISRPRIO  32

/*===================================================================
 * TRICORE CSAs
 *==================================================================*/
/* Deviation MISRAC2012-1 <START> */
#ifndef OS_ASM
extern os_cx_t    OS_csaCore0_BEGIN;
extern os_uint8_t OS_csaCore0_NCSA;
#endif  /* OS_ASM */
/* Deviation MISRAC2012-1 <STOP> */
/* Deviation MISRAC2012-1 <START> */
#ifndef OS_ASM
extern os_cx_t    OS_csaCore1_BEGIN;
extern os_uint8_t OS_csaCore1_NCSA;
#endif  /* OS_ASM */
/* Deviation MISRAC2012-1 <STOP> */
/* Deviation MISRAC2012-1 <START> */
#ifndef OS_ASM
extern os_cx_t    OS_csaCore2_BEGIN;
extern os_uint8_t OS_csaCore2_NCSA;
#endif  /* OS_ASM */
/* Deviation MISRAC2012-1 <STOP> */
/* Deviation MISRAC2012-1 <START> */
#ifndef OS_ASM
extern os_cx_t    OS_csaCore3_BEGIN;
extern os_uint8_t OS_csaCore3_NCSA;
#endif  /* OS_ASM */
/* Deviation MISRAC2012-1 <STOP> */
/* Deviation MISRAC2012-1 <START> */
#ifndef OS_ASM
extern os_cx_t    OS_csaCore4_BEGIN;
extern os_uint8_t OS_csaCore4_NCSA;
#endif  /* OS_ASM */
/* Deviation MISRAC2012-1 <STOP> */
/* Deviation MISRAC2012-1 <START> */
#ifndef OS_ASM
extern os_cx_t    OS_csaCore5_BEGIN;
extern os_uint8_t OS_csaCore5_NCSA;
#endif  /* OS_ASM */
/* Deviation MISRAC2012-1 <STOP> */

#define OS_CFG_INITCORECSAS     /* CSA initialization */  \
    {  \
      /* begin */     &OS_csaCore0_BEGIN,  \
      /* size */      (os_uint32_t) &OS_csaCore0_NCSA  \
    },  \
    {  \
      /* begin */     &OS_csaCore1_BEGIN,  \
      /* size */      (os_uint32_t) &OS_csaCore1_NCSA  \
    },  \
    {  \
      /* begin */     &OS_csaCore2_BEGIN,  \
      /* size */      (os_uint32_t) &OS_csaCore2_NCSA  \
    },  \
    {  \
      /* begin */     &OS_csaCore3_BEGIN,  \
      /* size */      (os_uint32_t) &OS_csaCore3_NCSA  \
    },  \
    {  \
      /* begin */     &OS_csaCore4_BEGIN,  \
      /* size */      (os_uint32_t) &OS_csaCore4_NCSA  \
    },  \
    {  \
      /* begin */     &OS_csaCore5_BEGIN,  \
      /* size */      (os_uint32_t) &OS_csaCore5_NCSA  \
    }

/*===================================================================
 * Tricore specific data
 *==================================================================*/
#define OS_TRICORE_TIMESTAMPSTMBASE  OS_STM0_BASE
#define OS_TRICORE_XCORESRCS {  \
  &OS_SRC_GPSR20,  \
  &OS_SRC_GPSR21,  \
  &OS_SRC_GPSR22,  \
  &OS_SRC_GPSR37,  \
  &OS_SRC_GPSR41,  \
  &OS_SRC_GPSR42  \
}
#ifdef __cplusplus
}
#endif
#endif  /* OS_CONFIG_H */
