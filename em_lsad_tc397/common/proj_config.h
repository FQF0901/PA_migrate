#ifndef PROJ_CONFIG_H__
#define PROJ_CONFIG_H__

#ifndef ON
#define ON                              0x01U
#endif
#ifndef OFF
#define OFF                             0x00U
#endif

#define USS_CALIB_SWITCH                OFF
#define JENKINS_BUILD_NUM_DEFAULT       0x00U
/***************************** Vehicle Type **********************************/
#define VEHI_TYPE_UNKNOWN               0
#define VEHI_TYPE_MCE                   1   /* Marvel R (MCE) */
#define VEHI_TYPE_NL5                   2   /* Geely (NL-5) */
#define VEHI_TYPE_DESKTOP               3   /* DESKTOP (DEFAULT) */
#define VEHI_TYPE_HAN                   4   /* BYD-han */
#define VEHI_TYPE_MIFA                  5   /* MIFA */
#define VEHI_TYPE_EP31                  6   /* Hozon EP31 */
#define VEHI_TYPE_EP40                  7   /* Hozon EP40 */
#define VEHI_TYPE_EP36                  8   /* Hozon EP36 */
#define VEHI_TYPE_EP32                  9   /* Hozon EP32 */
#define VEHI_TYPE_EP37                  10  /* Hozon EP37 */
#define VEHI_TYPE_EV52                  11  /* Hozon EV52 */
#define VEHI_TYPE_JX65                  12  /* JX65 */
#define VEHI_TYPE_HAOMO                 13  /* haomo V61 */
#define VEHI_TYPE_BICV                  14  /* */
#define VEHI_TYPE_EP41                  15  /* Hozon EP41 */
#define VEHI_TYPE_PC                    99  /* */
#define VEHI_TYPE_ERR                   -1  /* err */

/* Project ID */
#define EM_61000017_APA                 0x01U
#define EM_61000075_HPA                 0x02U
#define EM_61000051_EP40                0x03U
#define EM_61000050_EP36                0x04U
#define EM_61000062_EP32                0x05U
#define EM_PROJECT_ID                   EM_61000017_APA
#define EM_VEHI_TYPE                   VEHI_TYPE_HAN
#define EM_JENKINS_BUILD_NUM            764

/* OS Class */
#define PLT_FREERTOS                    0x01U
#define PLT_AUTOSAR_EB                     0x02U
#define PLT_AUTOSAR_VECTOR                     0x03U

/* chip Class */
#define MICRO_CONTROLLER_TC397          0x01U
#define MICRO_CONTROLLER_S32G           0x02U

#if (defined (EM_61000017_APA) && (EM_PROJECT_ID == EM_61000017_APA))
#define EM_SW_PLATFORM                  PLT_AUTOSAR_EB
#define EM_MICRO_CONTROLLER             MICRO_CONTROLLER_TC397
#define FUNCTION_HPP                    OFF
#define FUNCTION_APA                    ON
#elif (defined (EM_61000075_HPA) && (EM_PROJECT_ID == EM_61000075_HPA))
#define EM_SW_PLATFORM                  PLT_AUTOSAR_EB
#define EM_MICRO_CONTROLLER             MICRO_CONTROLLER_TC397
#define FUNCTION_HPP                    ON
#define FUNCTION_APA                    ON
#elif (defined (EM_61000051_EP40) && (EM_PROJECT_ID == EM_61000051_EP40))
#define EM_SW_PLATFORM                  PLT_AUTOSAR_EB
#define EM_MICRO_CONTROLLER             MICRO_CONTROLLER_TC397
#define FUNCTION_HPP                    OFF
#define FUNCTION_APA                    ON
#elif (defined (EM_61000062_EP32) && (EM_PROJECT_ID == EM_61000062_EP32))
#define EM_SW_PLATFORM                  PLT_AUTOSAR_EB
#define EM_MICRO_CONTROLLER             MICRO_CONTROLLER_TC397
#define FUNCTION_HPP                    OFF
#define FUNCTION_APA                    ON
#elif (defined (EM_61000050_EP36) && (EM_PROJECT_ID == EM_61000050_EP36))
#define EM_SW_PLATFORM                  PLT_AUTOSAR_EB
#define EM_MICRO_CONTROLLER             MICRO_CONTROLLER_TC397
#define FUNCTION_HPP                    OFF
#define FUNCTION_APA                    ON
#else
#error Please choose Project ID first.
#endif

/* macro to disable / restore interrupt, please adapt for AutoSAR CP accordingly */
#if (EM_SW_PLATFORM == PLT_FREERTOS)
#define EM_RTE_ENTER_CRITICAL()    do{extern void vTaskSuspendAll(void); vTaskSuspendAll();     }while(0)
#define EM_RTE_EXIT_CRITICAL()     do{extern long xTaskResumeAll(void); (void)xTaskResumeAll(); }while(0)
#elif(EM_SW_PLATFORM == PLT_AUTOSAR_EB)
#define EM_RTE_ENTER_CRITICAL()    do{extern void EM_SuspendOSInterrupts(void); EM_SuspendOSInterrupts();}while(0)        /* >>>>>> TO ADAAPT TO AUTOSAR CP >>>>>> */
#define EM_RTE_EXIT_CRITICAL()     do{extern void EM_ResumeOSInterrupts(void);  EM_ResumeOSInterrupts(); }while(0)        /* >>>>>> TO ADAAPT TO AUTOSAR CP >>>>>> */
#endif
#endif
