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

#ifndef OS_USER_H
#define OS_USER_H
#ifdef __cplusplus
extern "C" {
#endif

#define OS_GENERATION_ID_OS_H    0xbe1fc30cUL

#define OS_AUTOSAROS_VER         6

#define OS_AUTOSAROS_REV         1

#define OS_AUTOSAROS_CORE_BUILD  20220425

#define OS_AUTOSAROS_ARCH_BUILD  20220425

#ifndef OS_INTERRUPT_KEYWORD
#define OS_INTERRUPT_KEYWORD
#endif

#include <Os_api.h>

/*===================================================================
 * Alarms
 *==================================================================*/
#define AlarmIncrementRteCounter_C0  0
#define AlarmIncrementRteCounter_C1  1
#define AlarmIncrementRteCounter_C2  2
#define AlarmIncrementRteCounter_C3  3
#define AlarmIncrementRteCounter_C4  4
#define AlarmIncrementRteCounter_C5  5

/*===================================================================
 * Application modes
 *==================================================================*/
#define OSDEFAULTAPPMODE  0

/*===================================================================
 * Applications
 *==================================================================*/
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsApplication_C0  0
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsApplication_C1  1
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsApplication_C2  2
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsApplication_C3  3
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsApplication_C4  4
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsApplication_C5  5
#endif
/* Application Hooks */
/* Trusted Functions */

/*===================================================================
 * CPU Core configuration
 *==================================================================*/
#define OS_CORE_ID_0  0
#define OS_CORE_ID_1  1
#define OS_CORE_ID_2  2
#define OS_CORE_ID_3  3
#define OS_CORE_ID_4  4
#define OS_CORE_ID_5  5

/*===================================================================
 * Core Mapping
 *==================================================================*/
#define RES_SCHEDULER  OS_GetResScheduler()

/*===================================================================
 * Counters
 *==================================================================*/
/* Macros for the configured counter values and time conversions */
#define OSMAXALLOWEDVALUE_HwCounter_C0  OS_U(4294967295)
#define OSTICKSPERBASE_HwCounter_C0  OS_U(1000)
#define OSMINCYCLE_HwCounter_C0  OS_U(100)
#ifndef OS_ASM
extern void OS_CounterIsr_HwCounter_C0(void);
#endif  /* OS_ASM */
#define OS_NsToTicks_HwCounter_C0(x)  OS_NsToTicks_STM0_T0((x))
#define OS_TicksToNs_HwCounter_C0(x)  OS_TicksToNs_STM0_T0((x))
#define OS_TICKS2NS_HwCounter_C0(x)   (OS_TicksToNs_STM0_T0((x)))
#define OS_TICKS2US_HwCounter_C0(x)   (OS_TicksToNs_STM0_T0((x))/1000u)
#define OS_TICKS2MS_HwCounter_C0(x)   (OS_TicksToNs_STM0_T0((x))/1000000u)
#define OS_TICKS2SEC_HwCounter_C0(x)  (OS_TicksToNs_STM0_T0((x))/1000000000u)
#define OSMAXALLOWEDVALUE_Rte_Counter_C0  OS_U(4294967295)
#define OSTICKSPERBASE_Rte_Counter_C0  OS_U(1)
#define OSMINCYCLE_Rte_Counter_C0  OS_U(1)
#define OS_NsToTicks_Rte_Counter_C0(x)  ((x)/1000000)
#define OS_TicksToNs_Rte_Counter_C0(x)  ((x)*1000000)
#define OS_TICKS2NS_Rte_Counter_C0(x)   (OS_TicksToNs_Rte_Counter_C0((x)))
#define OS_TICKS2US_Rte_Counter_C0(x)   (OS_TicksToNs_Rte_Counter_C0((x)))/1000u
#define OS_TICKS2MS_Rte_Counter_C0(x)   (OS_TicksToNs_Rte_Counter_C0((x)))/1000000u
#define OS_TICKS2SEC_Rte_Counter_C0(x)  (OS_TicksToNs_Rte_Counter_C0((x)))/1000000000u
#define OSMAXALLOWEDVALUE_HwCounter_C1  OS_U(4294967295)
#define OSTICKSPERBASE_HwCounter_C1  OS_U(1000)
#define OSMINCYCLE_HwCounter_C1  OS_U(100)
#ifndef OS_ASM
extern void OS_CounterIsr_HwCounter_C1(void);
#endif  /* OS_ASM */
#define OS_NsToTicks_HwCounter_C1(x)  OS_NsToTicks_STM1_T0((x))
#define OS_TicksToNs_HwCounter_C1(x)  OS_TicksToNs_STM1_T0((x))
#define OS_TICKS2NS_HwCounter_C1(x)   (OS_TicksToNs_STM1_T0((x)))
#define OS_TICKS2US_HwCounter_C1(x)   (OS_TicksToNs_STM1_T0((x))/1000u)
#define OS_TICKS2MS_HwCounter_C1(x)   (OS_TicksToNs_STM1_T0((x))/1000000u)
#define OS_TICKS2SEC_HwCounter_C1(x)  (OS_TicksToNs_STM1_T0((x))/1000000000u)
#define OSMAXALLOWEDVALUE_Rte_Counter_C1  OS_U(4294967295)
#define OSTICKSPERBASE_Rte_Counter_C1  OS_U(1)
#define OSMINCYCLE_Rte_Counter_C1  OS_U(1)
#define OS_NsToTicks_Rte_Counter_C1(x)  ((x)/1000000)
#define OS_TicksToNs_Rte_Counter_C1(x)  ((x)*1000000)
#define OS_TICKS2NS_Rte_Counter_C1(x)   (OS_TicksToNs_Rte_Counter_C1((x)))
#define OS_TICKS2US_Rte_Counter_C1(x)   (OS_TicksToNs_Rte_Counter_C1((x)))/1000u
#define OS_TICKS2MS_Rte_Counter_C1(x)   (OS_TicksToNs_Rte_Counter_C1((x)))/1000000u
#define OS_TICKS2SEC_Rte_Counter_C1(x)  (OS_TicksToNs_Rte_Counter_C1((x)))/1000000000u
#define OSMAXALLOWEDVALUE_HwCounter_C2  OS_U(4294967295)
#define OSTICKSPERBASE_HwCounter_C2  OS_U(1000)
#define OSMINCYCLE_HwCounter_C2  OS_U(100)
#ifndef OS_ASM
extern void OS_CounterIsr_HwCounter_C2(void);
#endif  /* OS_ASM */
#define OS_NsToTicks_HwCounter_C2(x)  OS_NsToTicks_STM2_T0((x))
#define OS_TicksToNs_HwCounter_C2(x)  OS_TicksToNs_STM2_T0((x))
#define OS_TICKS2NS_HwCounter_C2(x)   (OS_TicksToNs_STM2_T0((x)))
#define OS_TICKS2US_HwCounter_C2(x)   (OS_TicksToNs_STM2_T0((x))/1000u)
#define OS_TICKS2MS_HwCounter_C2(x)   (OS_TicksToNs_STM2_T0((x))/1000000u)
#define OS_TICKS2SEC_HwCounter_C2(x)  (OS_TicksToNs_STM2_T0((x))/1000000000u)
#define OSMAXALLOWEDVALUE_Rte_Counter_C2  OS_U(4294967295)
#define OSTICKSPERBASE_Rte_Counter_C2  OS_U(1)
#define OSMINCYCLE_Rte_Counter_C2  OS_U(1)
#define OS_NsToTicks_Rte_Counter_C2(x)  ((x)/1000000)
#define OS_TicksToNs_Rte_Counter_C2(x)  ((x)*1000000)
#define OS_TICKS2NS_Rte_Counter_C2(x)   (OS_TicksToNs_Rte_Counter_C2((x)))
#define OS_TICKS2US_Rte_Counter_C2(x)   (OS_TicksToNs_Rte_Counter_C2((x)))/1000u
#define OS_TICKS2MS_Rte_Counter_C2(x)   (OS_TicksToNs_Rte_Counter_C2((x)))/1000000u
#define OS_TICKS2SEC_Rte_Counter_C2(x)  (OS_TicksToNs_Rte_Counter_C2((x)))/1000000000u
#define OSMAXALLOWEDVALUE_HwCounter_C3  OS_U(4294967295)
#define OSTICKSPERBASE_HwCounter_C3  OS_U(1000)
#define OSMINCYCLE_HwCounter_C3  OS_U(100)
#ifndef OS_ASM
extern void OS_CounterIsr_HwCounter_C3(void);
#endif  /* OS_ASM */
#define OS_NsToTicks_HwCounter_C3(x)  OS_NsToTicks_STM3_T0((x))
#define OS_TicksToNs_HwCounter_C3(x)  OS_TicksToNs_STM3_T0((x))
#define OS_TICKS2NS_HwCounter_C3(x)   (OS_TicksToNs_STM3_T0((x)))
#define OS_TICKS2US_HwCounter_C3(x)   (OS_TicksToNs_STM3_T0((x))/1000u)
#define OS_TICKS2MS_HwCounter_C3(x)   (OS_TicksToNs_STM3_T0((x))/1000000u)
#define OS_TICKS2SEC_HwCounter_C3(x)  (OS_TicksToNs_STM3_T0((x))/1000000000u)
#define OSMAXALLOWEDVALUE_Rte_Counter_C3  OS_U(4294967295)
#define OSTICKSPERBASE_Rte_Counter_C3  OS_U(1)
#define OSMINCYCLE_Rte_Counter_C3  OS_U(1)
#define OS_NsToTicks_Rte_Counter_C3(x)  ((x)/1000000)
#define OS_TicksToNs_Rte_Counter_C3(x)  ((x)*1000000)
#define OS_TICKS2NS_Rte_Counter_C3(x)   (OS_TicksToNs_Rte_Counter_C3((x)))
#define OS_TICKS2US_Rte_Counter_C3(x)   (OS_TicksToNs_Rte_Counter_C3((x)))/1000u
#define OS_TICKS2MS_Rte_Counter_C3(x)   (OS_TicksToNs_Rte_Counter_C3((x)))/1000000u
#define OS_TICKS2SEC_Rte_Counter_C3(x)  (OS_TicksToNs_Rte_Counter_C3((x)))/1000000000u
#define OSMAXALLOWEDVALUE_HwCounter_C4  OS_U(4294967295)
#define OSTICKSPERBASE_HwCounter_C4  OS_U(1000)
#define OSMINCYCLE_HwCounter_C4  OS_U(100)
#ifndef OS_ASM
extern void OS_CounterIsr_HwCounter_C4(void);
#endif  /* OS_ASM */
#define OS_NsToTicks_HwCounter_C4(x)  OS_NsToTicks_STM4_T0((x))
#define OS_TicksToNs_HwCounter_C4(x)  OS_TicksToNs_STM4_T0((x))
#define OS_TICKS2NS_HwCounter_C4(x)   (OS_TicksToNs_STM4_T0((x)))
#define OS_TICKS2US_HwCounter_C4(x)   (OS_TicksToNs_STM4_T0((x))/1000u)
#define OS_TICKS2MS_HwCounter_C4(x)   (OS_TicksToNs_STM4_T0((x))/1000000u)
#define OS_TICKS2SEC_HwCounter_C4(x)  (OS_TicksToNs_STM4_T0((x))/1000000000u)
#define OSMAXALLOWEDVALUE_Rte_Counter_C4  OS_U(4294967295)
#define OSTICKSPERBASE_Rte_Counter_C4  OS_U(1)
#define OSMINCYCLE_Rte_Counter_C4  OS_U(1)
#define OS_NsToTicks_Rte_Counter_C4(x)  ((x)/1000000)
#define OS_TicksToNs_Rte_Counter_C4(x)  ((x)*1000000)
#define OS_TICKS2NS_Rte_Counter_C4(x)   (OS_TicksToNs_Rte_Counter_C4((x)))
#define OS_TICKS2US_Rte_Counter_C4(x)   (OS_TicksToNs_Rte_Counter_C4((x)))/1000u
#define OS_TICKS2MS_Rte_Counter_C4(x)   (OS_TicksToNs_Rte_Counter_C4((x)))/1000000u
#define OS_TICKS2SEC_Rte_Counter_C4(x)  (OS_TicksToNs_Rte_Counter_C4((x)))/1000000000u
#define OSMAXALLOWEDVALUE_HwCounter_C5  OS_U(4294967295)
#define OSTICKSPERBASE_HwCounter_C5  OS_U(1000)
#define OSMINCYCLE_HwCounter_C5  OS_U(100)
#ifndef OS_ASM
extern void OS_CounterIsr_HwCounter_C5(void);
#endif  /* OS_ASM */
#define OS_NsToTicks_HwCounter_C5(x)  OS_NsToTicks_STM5_T0((x))
#define OS_TicksToNs_HwCounter_C5(x)  OS_TicksToNs_STM5_T0((x))
#define OS_TICKS2NS_HwCounter_C5(x)   (OS_TicksToNs_STM5_T0((x)))
#define OS_TICKS2US_HwCounter_C5(x)   (OS_TicksToNs_STM5_T0((x))/1000u)
#define OS_TICKS2MS_HwCounter_C5(x)   (OS_TicksToNs_STM5_T0((x))/1000000u)
#define OS_TICKS2SEC_HwCounter_C5(x)  (OS_TicksToNs_STM5_T0((x))/1000000000u)
#define OSMAXALLOWEDVALUE_Rte_Counter_C5  OS_U(4294967295)
#define OSTICKSPERBASE_Rte_Counter_C5  OS_U(1)
#define OSMINCYCLE_Rte_Counter_C5  OS_U(1)
#define OS_NsToTicks_Rte_Counter_C5(x)  ((x)/1000000)
#define OS_TicksToNs_Rte_Counter_C5(x)  ((x)*1000000)
#define OS_TICKS2NS_Rte_Counter_C5(x)   (OS_TicksToNs_Rte_Counter_C5((x)))
#define OS_TICKS2US_Rte_Counter_C5(x)   (OS_TicksToNs_Rte_Counter_C5((x)))/1000u
#define OS_TICKS2MS_Rte_Counter_C5(x)   (OS_TicksToNs_Rte_Counter_C5((x)))/1000000u
#define OS_TICKS2SEC_Rte_Counter_C5(x)  (OS_TicksToNs_Rte_Counter_C5((x)))/1000000000u

/* Non-Internal Counter Ids */
#define HwCounter_C0  0
#define Rte_Counter_C0  1
#define HwCounter_C1  2
#define Rte_Counter_C1  3
#define HwCounter_C2  4
#define Rte_Counter_C2  5
#define HwCounter_C3  6
#define Rte_Counter_C3  7
#define HwCounter_C4  8
#define Rte_Counter_C4  9
#define HwCounter_C5  10
#define Rte_Counter_C5  11


/* System Counter Macros */
#define OSMAXALLOWEDVALUE  OSMAXALLOWEDVALUE_HwCounter_C0
#define OSTICKSPERBASE     OSTICKSPERBASE_HwCounter_C0
#define OSMINCYCLE         OSMINCYCLE_HwCounter_C0
#define OSTICKDURATION     OS_TicksToNs_HwCounter_C0(1u)

/*===================================================================
 * Events
 *==================================================================*/
#define SchM_OSShutdownEvent  0x0001u
#define Rte_OSTimingEvent_EM_Bsw_20ms_C1_TE_2CDA2542ABD9EE922E79D5DEA31CABFA  0x0002u
#define Rte_OSTimingEvent_EM_Bsw_20ms_C1_TE_236D4CDC7E97447E9763E89F52F1E395  0x0004u
#define Rte_OSTimingEvent_EM_Bsw_Task_C0_TE_72326CF0F55FFC788B52DB7F835D5952  0x0002u
#define Rte_OSTimingEvent_EM_Bsw_Task_C0_TE_DA2A233F5D58325C1CAED292AA64F465  0x0004u
#define Rte_OSTimingEvent_EM_Bsw_10ms_C0_TE_012AF07576AE01C05AAE3DE95EFFDD4C  0x0002u
#define Rte_OSTimingEvent_EM_Bsw_10ms_C0_TE_1D65699D19EB37B5C8A54E55582BC006  0x0004u
#define Rte_OSTimingEvent_EM_Bsw_10ms_C0_TE_1E6CCE5F1652297767E90CCFF6814CA1  0x0008u
#define Rte_OSTimingEvent_EM_Bsw_20ms_C2_TE_49AEC53B73B5F5193AB8079E8EE7934E  0x0002u
#define Rte_OSTimingEvent_EM_Bsw_20ms_C2_TE_480E602D3320AA916F8C973A4F0703A3  0x0004u
#define Rte_OSTimingEvent_OsTask_20ms_C3_TE_1BF45AF11CA52C53FB5A043C90F94DEE  0x0002u
#define Rte_OSTimingEvent_OsTask_20ms_C3_TE_B77D98AB2C8CC6F0727B727EFFCA2188  0x0004u
#define Rte_OSTimingEvent_EM_Bsw_10ms_C0_TE_FB1E1E46F286102A5E018DDD34ABF710  0x0010u

/*===================================================================
 * Interrupts
 *==================================================================*/
#ifndef OS_ASM
extern void OS_ISR_ETHSR0_ISR(void);
#endif  /* OS_ASM */
#define ETHSR0_ISR_ISR_CATEGORY  2
#define ETHSR0_ISR_ISR_VECTOR    6
#define ETHSR0_ISR_ISR_LEVEL     7
#ifndef OS_ASM
extern void OS_ISR_ETHSR2_ISR(void);
#endif  /* OS_ASM */
#define ETHSR2_ISR_ISR_CATEGORY  2
#define ETHSR2_ISR_ISR_VECTOR    7
#define ETHSR2_ISR_ISR_LEVEL     8
#ifndef OS_ASM
extern void OS_ISR_ETHSR6_ISR(void);
#endif  /* OS_ASM */
#define ETHSR6_ISR_ISR_CATEGORY  2
#define ETHSR6_ISR_ISR_VECTOR    8
#define ETHSR6_ISR_ISR_LEVEL     9
#ifndef OS_ASM
extern void OS_ISR_DMACH0SR_ISR(void);
#endif  /* OS_ASM */
#define DMACH0SR_ISR_ISR_CATEGORY  2
#define DMACH0SR_ISR_ISR_VECTOR    9
#define DMACH0SR_ISR_ISR_LEVEL     10
#ifndef OS_ASM
extern void OS_ISR_DMACH1SR_ISR(void);
#endif  /* OS_ASM */
#define DMACH1SR_ISR_ISR_CATEGORY  2
#define DMACH1SR_ISR_ISR_VECTOR    10
#define DMACH1SR_ISR_ISR_LEVEL     11
#ifndef OS_ASM
extern void OS_ISR_QSPI0PT_ISR(void);
#endif  /* OS_ASM */
#define QSPI0PT_ISR_ISR_CATEGORY  2
#define QSPI0PT_ISR_ISR_VECTOR    11
#define QSPI0PT_ISR_ISR_LEVEL     12
#ifndef OS_ASM
extern void OS_ISR_QSPI0ERR_ISR(void);
#endif  /* OS_ASM */
#define QSPI0ERR_ISR_ISR_CATEGORY  2
#define QSPI0ERR_ISR_ISR_VECTOR    12
#define QSPI0ERR_ISR_ISR_LEVEL     13
#ifndef OS_ASM
extern void OS_ISR_DMACH5SR_ISR(void);
#endif  /* OS_ASM */
#define DMACH5SR_ISR_ISR_CATEGORY  2
#define DMACH5SR_ISR_ISR_VECTOR    13
#define DMACH5SR_ISR_ISR_LEVEL     14
#ifndef OS_ASM
extern void OS_ISR_DMACH6SR_ISR(void);
#endif  /* OS_ASM */
#define DMACH6SR_ISR_ISR_CATEGORY  2
#define DMACH6SR_ISR_ISR_VECTOR    14
#define DMACH6SR_ISR_ISR_LEVEL     15
#ifndef OS_ASM
extern void OS_ISR_CAN0SR12_ISR(void);
#endif  /* OS_ASM */
#define CAN0SR12_ISR_ISR_CATEGORY  2
#define CAN0SR12_ISR_ISR_VECTOR    15
#define CAN0SR12_ISR_ISR_LEVEL     16
#ifndef OS_ASM
extern void OS_ISR_CAN0SR13_ISR(void);
#endif  /* OS_ASM */
#define CAN0SR13_ISR_ISR_CATEGORY  2
#define CAN0SR13_ISR_ISR_VECTOR    16
#define CAN0SR13_ISR_ISR_LEVEL     17
#ifndef OS_ASM
extern void OS_ISR_CAN0SR14_ISR(void);
#endif  /* OS_ASM */
#define CAN0SR14_ISR_ISR_CATEGORY  2
#define CAN0SR14_ISR_ISR_VECTOR    17
#define CAN0SR14_ISR_ISR_LEVEL     18
#ifndef OS_ASM
extern void OS_ISR_CAN0SR15_ISR(void);
#endif  /* OS_ASM */
#define CAN0SR15_ISR_ISR_CATEGORY  2
#define CAN0SR15_ISR_ISR_VECTOR    18
#define CAN0SR15_ISR_ISR_LEVEL     19
#ifndef OS_ASM
extern void OS_ISR_CAN1SR0_ISR(void);
#endif  /* OS_ASM */
#define CAN1SR0_ISR_ISR_CATEGORY  2
#define CAN1SR0_ISR_ISR_VECTOR    19
#define CAN1SR0_ISR_ISR_LEVEL     20
#ifndef OS_ASM
extern void OS_ISR_CAN1SR1_ISR(void);
#endif  /* OS_ASM */
#define CAN1SR1_ISR_ISR_CATEGORY  2
#define CAN1SR1_ISR_ISR_VECTOR    20
#define CAN1SR1_ISR_ISR_LEVEL     21
#ifndef OS_ASM
extern void OS_ISR_CAN1SR2_ISR(void);
#endif  /* OS_ASM */
#define CAN1SR2_ISR_ISR_CATEGORY  2
#define CAN1SR2_ISR_ISR_VECTOR    21
#define CAN1SR2_ISR_ISR_LEVEL     22
#ifndef OS_ASM
extern void OS_ISR_CAN1SR3_ISR(void);
#endif  /* OS_ASM */
#define CAN1SR3_ISR_ISR_CATEGORY  2
#define CAN1SR3_ISR_ISR_VECTOR    22
#define CAN1SR3_ISR_ISR_LEVEL     23
#ifndef OS_ASM
extern void OS_ISR_GPT12_T2_ISR(void);
#endif  /* OS_ASM */
#define GPT12_T2_ISR_ISR_CATEGORY  2
#define GPT12_T2_ISR_ISR_VECTOR    23
#define GPT12_T2_ISR_ISR_LEVEL     24
#ifndef OS_ASM
extern void OS_ISR_GPT12_T3_ISR(void);
#endif  /* OS_ASM */
#define GPT12_T3_ISR_ISR_CATEGORY  2
#define GPT12_T3_ISR_ISR_VECTOR    24
#define GPT12_T3_ISR_ISR_LEVEL     25
#ifndef OS_ASM
extern void OS_ISR_GPT12_T6_ISR(void);
#endif  /* OS_ASM */
#define GPT12_T6_ISR_ISR_CATEGORY  2
#define GPT12_T6_ISR_ISR_VECTOR    25
#define GPT12_T6_ISR_ISR_LEVEL     26
#ifndef OS_ASM
extern void OS_ISR_EmUSS01_ISR(void);
#endif  /* OS_ASM */
#define EmUSS01_ISR_ISR_CATEGORY  1
#define EmUSS01_ISR_ISR_VECTOR    43
#define EmUSS01_ISR_ISR_LEVEL     44
#ifndef OS_ASM
extern void OS_ISR_EmUSS02_ISR(void);
#endif  /* OS_ASM */
#define EmUSS02_ISR_ISR_CATEGORY  1
#define EmUSS02_ISR_ISR_VECTOR    43
#define EmUSS02_ISR_ISR_LEVEL     44
#ifndef OS_ASM
extern void OS_ISR_EmUSS03_ISR(void);
#endif  /* OS_ASM */
#define EmUSS03_ISR_ISR_CATEGORY  1
#define EmUSS03_ISR_ISR_VECTOR    43
#define EmUSS03_ISR_ISR_LEVEL     44
#ifndef OS_ASM
extern void OS_ISR_EmUSS04_ISR(void);
#endif  /* OS_ASM */
#define EmUSS04_ISR_ISR_CATEGORY  1
#define EmUSS04_ISR_ISR_VECTOR    43
#define EmUSS04_ISR_ISR_LEVEL     44
#ifndef OS_ASM
extern void OS_ISR_EmUSS05_ISR(void);
#endif  /* OS_ASM */
#define EmUSS05_ISR_ISR_CATEGORY  1
#define EmUSS05_ISR_ISR_VECTOR    43
#define EmUSS05_ISR_ISR_LEVEL     44
#ifndef OS_ASM
extern void OS_ISR_EmUSS06_ISR(void);
#endif  /* OS_ASM */
#define EmUSS06_ISR_ISR_CATEGORY  1
#define EmUSS06_ISR_ISR_VECTOR    43
#define EmUSS06_ISR_ISR_LEVEL     44
#ifndef OS_ASM
extern void OS_ISR_EmUSS07_ISR(void);
#endif  /* OS_ASM */
#define EmUSS07_ISR_ISR_CATEGORY  1
#define EmUSS07_ISR_ISR_VECTOR    43
#define EmUSS07_ISR_ISR_LEVEL     44
#ifndef OS_ASM
extern void OS_ISR_EmUSS08_ISR(void);
#endif  /* OS_ASM */
#define EmUSS08_ISR_ISR_CATEGORY  1
#define EmUSS08_ISR_ISR_VECTOR    43
#define EmUSS08_ISR_ISR_LEVEL     44
#ifndef OS_ASM
extern void OS_ISR_EmUSS09_ISR(void);
#endif  /* OS_ASM */
#define EmUSS09_ISR_ISR_CATEGORY  1
#define EmUSS09_ISR_ISR_VECTOR    43
#define EmUSS09_ISR_ISR_LEVEL     44
#ifndef OS_ASM
extern void OS_ISR_EmUSS10_ISR(void);
#endif  /* OS_ASM */
#define EmUSS10_ISR_ISR_CATEGORY  1
#define EmUSS10_ISR_ISR_VECTOR    43
#define EmUSS10_ISR_ISR_LEVEL     44
#ifndef OS_ASM
extern void OS_ISR_EmUSS11_ISR(void);
#endif  /* OS_ASM */
#define EmUSS11_ISR_ISR_CATEGORY  1
#define EmUSS11_ISR_ISR_VECTOR    43
#define EmUSS11_ISR_ISR_LEVEL     44
#ifndef OS_ASM
extern void OS_ISR_EmUSS12_ISR(void);
#endif  /* OS_ASM */
#define EmUSS12_ISR_ISR_CATEGORY  1
#define EmUSS12_ISR_ISR_VECTOR    43
#define EmUSS12_ISR_ISR_LEVEL     44
#define CrossCoreNotify0_ISR_CATEGORY  CC
#define CrossCoreNotify0_ISR_VECTOR    31
#define CrossCoreNotify0_ISR_LEVEL     32
#define CrossCoreNotify1_ISR_CATEGORY  CC
#define CrossCoreNotify1_ISR_VECTOR    31
#define CrossCoreNotify1_ISR_LEVEL     32
#define CrossCoreNotify2_ISR_CATEGORY  CC
#define CrossCoreNotify2_ISR_VECTOR    31
#define CrossCoreNotify2_ISR_LEVEL     32
#define CrossCoreNotify3_ISR_CATEGORY  CC
#define CrossCoreNotify3_ISR_VECTOR    31
#define CrossCoreNotify3_ISR_LEVEL     32
#define CrossCoreNotify4_ISR_CATEGORY  CC
#define CrossCoreNotify4_ISR_VECTOR    31
#define CrossCoreNotify4_ISR_LEVEL     32
#define CrossCoreNotify5_ISR_CATEGORY  CC
#define CrossCoreNotify5_ISR_VECTOR    31
#define CrossCoreNotify5_ISR_LEVEL     32
#define Os_Counter_STM0_T0_ISR_CATEGORY  2
#define Os_Counter_STM0_T0_ISR_VECTOR    5
#define Os_Counter_STM0_T0_ISR_LEVEL     6
#define Os_Counter_STM1_T0_ISR_CATEGORY  2
#define Os_Counter_STM1_T0_ISR_VECTOR    5
#define Os_Counter_STM1_T0_ISR_LEVEL     6
#define Os_Counter_STM2_T0_ISR_CATEGORY  2
#define Os_Counter_STM2_T0_ISR_VECTOR    5
#define Os_Counter_STM2_T0_ISR_LEVEL     6
#define Os_Counter_STM3_T0_ISR_CATEGORY  2
#define Os_Counter_STM3_T0_ISR_VECTOR    5
#define Os_Counter_STM3_T0_ISR_LEVEL     6
#define Os_Counter_STM4_T0_ISR_CATEGORY  2
#define Os_Counter_STM4_T0_ISR_VECTOR    5
#define Os_Counter_STM4_T0_ISR_LEVEL     6
#define Os_Counter_STM5_T0_ISR_CATEGORY  2
#define Os_Counter_STM5_T0_ISR_VECTOR    5
#define Os_Counter_STM5_T0_ISR_LEVEL     6
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define ETHSR0_ISR  0
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define ETHSR2_ISR  1
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define ETHSR6_ISR  2
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define DMACH0SR_ISR  3
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define DMACH1SR_ISR  4
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define QSPI0PT_ISR  5
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define QSPI0ERR_ISR  6
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define DMACH5SR_ISR  7
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define DMACH6SR_ISR  8
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN0SR12_ISR  9
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN0SR13_ISR  10
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN0SR14_ISR  11
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN0SR15_ISR  12
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN1SR0_ISR  13
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN1SR1_ISR  14
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN1SR2_ISR  15
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN1SR3_ISR  16
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define GPT12_T2_ISR  17
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define GPT12_T3_ISR  18
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define GPT12_T6_ISR  19
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EmUSS01_ISR  20
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EmUSS02_ISR  21
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EmUSS03_ISR  22
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EmUSS04_ISR  23
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EmUSS05_ISR  24
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EmUSS06_ISR  25
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EmUSS07_ISR  26
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EmUSS08_ISR  27
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EmUSS09_ISR  28
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EmUSS10_ISR  29
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EmUSS11_ISR  30
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EmUSS12_ISR  31
#endif

/*===================================================================
 * Resources
 *==================================================================*/
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define RES_SCHEDULER_0  0
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define RES_SCHEDULER_1  1
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define RES_SCHEDULER_2  2
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define RES_SCHEDULER_3  3
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define RES_SCHEDULER_4  4
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define RES_SCHEDULER_5  5
#endif

/*===================================================================
 * Schedule Tables
 *==================================================================*/
#define SchM_DefaultScheduleTable_OsApplication_C0  0
#define Rte_DefaultScheduleTable_OsApplication_C0  1
#define SchM_DefaultScheduleTable_OsApplication_C1  2
#define Rte_DefaultScheduleTable_OsApplication_C1  3
#define SchM_DefaultScheduleTable_OsApplication_C2  4
#define SchM_DefaultScheduleTable_OsApplication_C3  5
#define SchM_DefaultScheduleTable_OsApplication_C4  6
#define SchM_DefaultScheduleTable_OsApplication_C5  7
#define Rte_DefaultScheduleTable_OsApplication_C2  8
#define Rte_DefaultScheduleTable_OsApplication_C3  9

/*===================================================================
 * Spinlocks
 *==================================================================*/
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsSpinlock_0  0
#endif

/*===================================================================
 * Tasks
 *==================================================================*/
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EM_Bsw_10ms_C0  0
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EM_Bsw_Task_C0  1
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EM_Bsw_20ms_C1  2
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EM_Bsw_20ms_C2  3
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsTask_20ms_C3  4
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EM_Bsw_Start_Init_C0  5
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EM_Bsw_Init_C0  6
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EM_App_5ms_C0  7
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EM_App_10ms_C0  8
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EM_App_25ms_C0  9
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EM_Bsw_Init_C1  10
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EM_Uss_Init_C1  11
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EM_Uss_5ms_C1  12
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EM_Uss_10ms_C1  13
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EM_Uss_20ms_C1  14
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EM_Uss_50ms_C1  15
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EM_Bsw_Init_C2  16
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EM_App_Init_C2  17
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EM_App_5ms_C2  18
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EM_App_10ms_C2  19
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EM_App_20ms_C2  20
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define EM_App_50ms_C2  21
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Init_Task_C3  22
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsTask_10ms_C3  23
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsTask_5ms_C3  24
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsTask_20ms_C4  25
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Init_Task_C4  26
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsTask_20ms_C5  27
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Init_Task_C5  28
#endif

/*===================================================================
 * Time-stamp timer
 *==================================================================*/
#define OS_TimestampNsToTicks(ns)     OS_NsToTicks_TbTimer(ns)
#define OS_TimestampTicksToNs(ticks)  OS_TicksToNs_TbTimer(ticks)
#ifdef __cplusplus
}
#endif
#endif  /* OS_USER_H */
