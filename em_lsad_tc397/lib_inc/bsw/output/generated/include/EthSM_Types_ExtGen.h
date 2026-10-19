


/**
 * \file
 *
 * \brief AUTOSAR EthSM
 *
 * This file contains the implementation of the AUTOSAR
 * module EthSM.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef ETHSM_TYPES_EXTGEN_H
#define ETHSM_TYPES_EXTGEN_H



/*==================[inclusions]=============================================*/

#include <Platform_Types.h>
#include <TSAutosar.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS ETHSM_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/

#if (defined ETHSM_INVALID_DEM_EVENTID) /* To prevent double definition */
#error ETHSM_INVALID_DEM_EVENTID already defined
#endif /* (defined ETHSM_INVALID_DEM_EVENTID) */

#define ETHSM_INVALID_DEM_EVENTID 0



/*==================[type definitions]=======================================*/

/** 
 Type of network configuration structure.
 */
typedef struct /* EthSM_NetworkType */ {
    VAR( uint8, TYPEDEF ) CtrlIdx;
    VAR( uint8, TYPEDEF ) NetworkHandleIdx;
} EthSM_NetworkType;

/** 
 Type definition of the root structure.
 */
typedef struct /* EthSM_ConfigType */ {
    VAR( uint32, TYPEDEF ) PlatformSignature; /* Used to validate the platform. */
    VAR( uint32, TYPEDEF ) LcfgSignature; /* Used to validate the post build configuration against the link time configuration. */
    VAR( uint32, TYPEDEF ) CfgSignature; /* Used to validate the post build configuration against the precompile time configuration. */
    VAR( uint32, TYPEDEF ) PublicInfoSignature; /* Used to validate Public information. */
    TS_REF2CFG( EthSM_NetworkType )  NetworkRef;
    VAR( uint8, TYPEDEF ) NumNetworks;
} EthSM_ConfigType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* ETHSM_TYPES_EXTGEN_H */

/*==================[end of file]============================================*/

