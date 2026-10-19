/**
 * \file
 *
 * \brief AUTOSAR SoAd
 *
 * This file contains the implementation of the AUTOSAR
 * module SoAd.
 *
 * \version 1.8.19
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef SOAD_LCFG_H
#define SOAD_LCFG_H

/*
 * Misra-C:2012 Deviations:
 *
 * MISRAC2012-1) Deviated Rule: 9.5 (required)
 * Where designated initializers are used to initialize an array object
 * the size of the array shall be specified explicitly.
 *
 * Reason:
 * Link-Time Configuration: Function pointer array with variable size
 * for configurable upper layer support
 */


/*==================[includes]==============================================*/

#include <TSAutosar.h>
#include <ComStack_Types.h>
#include <SoAd_Cfg.h>
#include <SoAd_Types.h>

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

#define SOAD_START_SEC_VAR_CLEARED_32
#include <SoAd_MemMap.h>

/* Deviation MISRAC2012-1 */
extern VAR(uint32, SOAD_VAR_CLEARED) SoAd_Mem[];

#define SOAD_STOP_SEC_VAR_CLEARED_32
#include <SoAd_MemMap.h>


/* start const section declaration */
#define SOAD_START_SEC_CONST_8
#include <SoAd_MemMap.h>

/**
 * API function pointer table size variable for modules with interface archetype
 */
extern CONST(uint8, SOAD_APPL_CONST) SoAd_IfModuleAPISize;

/**
 * API function pointer table size variable for modules with TP archetype
 */
extern CONST(uint8, SOAD_APPL_CONST) SoAd_TpModuleAPISize;

/**
 * API function pointer table size variable for modules that require notifications
 */
extern CONST(uint8, SOAD_APPL_CONST) SoAd_NotificationAPISize;

/* stop const section declaration */
#define SOAD_STOP_SEC_CONST_8
#include <SoAd_MemMap.h>


/* start data section declaration */
#define SOAD_START_SEC_CONST_32
#include <SoAd_MemMap.h>

/* value used to validate post build configuration against link time configuration */
extern CONST(uint32, SOAD_CONST) SoAd_LcfgSignature;

/* stop data section declaration */
#define SOAD_STOP_SEC_CONST_32
#include <SoAd_MemMap.h>


/* start const section declaration */
#define SOAD_START_SEC_CONST_UNSPECIFIED
#include <SoAd_MemMap.h>

/**
 * API function pointer table for modules with interface archetype
 */
/* Deviation MISRAC2012-1 */
extern CONST(SoAd_IfModuleAPIType, SOAD_APPL_CONST) SoAd_IfModuleAPI[];

/**
 * API function pointer table for modules with TP archetype
 */
/* Deviation MISRAC2012-1 */
extern CONST(SoAd_TpModuleAPIType, SOAD_APPL_CONST) SoAd_TpModuleAPI[];

/**
 * API function pointer table for modules that require notifications
 */
/* Deviation MISRAC2012-1 */
extern CONST(SoAd_NotificationAPIType, SOAD_APPL_CONST) SoAd_NotificationAPI[];

/* stop const section declaration */
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
#include <SoAd_MemMap.h>

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
#endif /* ifndef SOAD_LCFG_H  */
/*==================[end of file]===========================================*/
