/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2021)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Fee_Cfg.h                                                     **
**                                                                            **
**  VERSION   : 13.0.0                                                        **
**                                                                            **
**  DATE, TIME: 2024-02-29, 10:19:29    !!!IGNORE-LINE!!!                 **
**                                                                            **
**  GENERATOR : Build b211016-0103                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : Fee.bmd                                           **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Fee configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of Fee Driver,                           **
**                     AUTOSAR Release 4.2.2 and 4.4.0                        **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

#ifndef  FEE_CFG_H
#define  FEE_CFG_H



/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Typedefs Imported from Memory Abstract Interface */ 
#include "MemIf.h"

/* Callback functions imported from NvM Module */
#include "NvM_Cbk.h"


/* Functions imported from Fls Module */
#include "Fls_17_Dmu.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* FEE AS version information */
#define FEE_AS_VERSION (422)



#define FEE_AR_RELEASE_MAJOR_VERSION  (4U)
#define FEE_AR_RELEASE_MINOR_VERSION  (2U)
#define FEE_AR_RELEASE_REVISION_VERSION  (2U)
/* Vendor specific implementation version information */



#define FEE_SW_MAJOR_VERSION  (20U)
#define FEE_SW_MINOR_VERSION  (0U)
#define FEE_SW_PATCH_VERSION  (2U)

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                    Static configuration parameters                         **
*******************************************************************************/

/* Development error detection enabled/disabled */
#define FEE_DEV_ERROR_DETECT       (STD_ON)


/* Enable/Disable Safety error detection and reporting*/
#define FEE_SAFETY_ENABLE         (STD_ON)

/* Enable/Disable FEE Init Check API*/
#define FEE_INITCHECK_API         (STD_OFF)
/* Fee_GetVersionInfo API enabled/disabled */
#define FEE_VERSION_INFO_API       (STD_OFF)

/* Fee_GetCycleCount API enabled/disabled */
#define FEE_GET_CYCLE_COUNT_API    (STD_OFF)

/* Fee_GetEccErrorInfo API enabled/disabled */

#define FEE_GET_ECC_ERROR_INFO_API         (STD_OFF)
/* Runtime Error*/

#define FEE_RUNTIME_ERROR_DETECT (STD_OFF)
/* Fee_SetMode API enabled/disabled */

#define FEE_SET_MODE_SUPPORTED     (STD_ON)



/* Block type configured */

#define FEE_DATA_BLOCK_SUPPORTED FEE_DOUBLE_SECTOR_DATA_ONLY


/* Fee_17_GetPrevData API enabled/disabled */
#define FEE_GET_PREV_DATA_API      (STD_OFF)

#define FEE_CANCELL_ALL_API      (STD_OFF)


#define FEE_MAX_BYTES_PER_CYCLE      (512U)
/* FEE programs state pages upon detection of virgin flash */
#define FEE_VIRGIN_FLASH_ILLEGAL_STATE      (STD_OFF)

/* Enable/Disable Debug support  */
#define FEE_DEBUG_SUPPORT     (STD_OFF)


/*FeeMainFunctionPeriod value in micro seconds(us)*/
#define FEE_MAIN_FUNCTION_PERIOD       10000


/* Erase suspend/resume feature supported in FLS */
#define FEE_FLS_SUPPORTS_ERASE_SUSPEND  (STD_OFF)

/* DFlash WordLine size */
#define FEE_DFLASH_WORDLINE_SIZE     (512U)

#define FEE_CONTINUE          (0U)
#define FEE_STOP_AT_GC        (1U)


#define FEE_UNCFG_BLK_OVERFLOW_HANDLE    (FEE_CONTINUE)

/* Virtual page size, i.e., DF_EEPROM page size */
#define FEE_VIRTUAL_PAGE_SIZE      (8U)


/* Logical block's overhead in bytes */
#define FEE_BLOCK_OVERHEAD         (17U)


/* Logical block's data page overhead in bytes */
#define FEE_PAGE_OVERHEAD          (1U)

/* Maximum number of configured blocks to be handled */

#define FEE_MAX_BLOCK_COUNT        (3U)

/* Number of pages to be scanned and analyzed in one Fee_Main() cycle. */

#define FEE_PAGES_PER_FEEMAIN      (65535U)

/* Symbolic names of logical blocks */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_FeeBlock_Cfm 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_FeeBlock_Cfm already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_FeeBlock_Cfm ((uint16)32)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FeeBlock_Cfm */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NvMBlock_ConfigID 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NvMBlock_ConfigID already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NvMBlock_ConfigID ((uint16)16)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NvMBlock_ConfigID */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NvMBlock_ConfigID_Red 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NvMBlock_ConfigID_Red already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NvMBlock_ConfigID_Red ((uint16)17)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NvMBlock_ConfigID_Red */


#define FEE_DISABLE_DEM_REPORT   (0U)
#define FEE_ENABLE_DEM_REPORT    (1U)

/* DEM Configurations */

#define FEE_GC_INIT_DEM_REPORT       (FEE_ENABLE_DEM_REPORT)

#define FEE_E_GC_INIT                (DemConf_DemEventParameter_FEE_E_GC_INIT)

#define FEE_WRITE_DEM_REPORT         (FEE_ENABLE_DEM_REPORT)

#define FEE_E_WRITE                  (DemConf_DemEventParameter_FEE_E_WRITE)

#define FEE_READ_DEM_REPORT          (FEE_ENABLE_DEM_REPORT)

#define FEE_E_READ                   (DemConf_DemEventParameter_FEE_E_READ)

#define FEE_GC_WRITE_DEM_REPORT      (FEE_ENABLE_DEM_REPORT)

#define FEE_E_GC_WRITE               (DemConf_DemEventParameter_FEE_E_GC_WRITE)

#define FEE_GC_READ_DEM_REPORT       (FEE_ENABLE_DEM_REPORT)

#define FEE_E_GC_READ                (DemConf_DemEventParameter_FEE_E_GC_READ)

#define FEE_GC_ERASE_DEM_REPORT      (FEE_ENABLE_DEM_REPORT)

#define FEE_E_GC_ERASE               (DemConf_DemEventParameter_FEE_E_GC_ERASE)

#define FEE_INVALIDATE_DEM_REPORT    (FEE_ENABLE_DEM_REPORT)

#define FEE_E_INVALIDATE             (DemConf_DemEventParameter_FEE_E_INVALIDATE)

#define FEE_WRITE_CYCLES_DEM_REPORT  (FEE_ENABLE_DEM_REPORT)

#define FEE_E_WRITE_CYCLES_EXHAUSTED (DemConf_DemEventParameter_FEE_E_WRITE_CYCLES_EXHAUSTED)

#define FEE_GC_TRIG_DEM_REPORT       (FEE_ENABLE_DEM_REPORT)

#define FEE_E_GC_TRIG                (DemConf_DemEventParameter_FEE_E_GC_TRIG)
#define FEE_UNCFG_BLK_DEM_REPORT     (FEE_ENABLE_DEM_REPORT)

#define FEE_E_UNCONFIG_BLK_EXCEEDED  (DemConf_DemEventParameter_FEE_E_UNCONFIG_BLK_EXCEEDED)


#define FEE_DEM_ENABLED              (STD_ON)
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#endif /* #ifndef FEE_CFG_H */
