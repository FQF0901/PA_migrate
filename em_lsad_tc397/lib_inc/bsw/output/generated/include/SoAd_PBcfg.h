


/**
 * \file
 *
 * \brief AUTOSAR SoAd
 *
 * This file contains the implementation of the AUTOSAR
 * module SoAd.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef SOAD_PBCFG_H
#define SOAD_PBCFG_H



/*==================[inclusions]=============================================*/

#include <SoAd_SymbolicNames_PBcfg.h>
#include <TSAutosar.h>
#include <SoAd_CfgTypes.h>
#include <Platform_Types.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS SOAD_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/

#if (defined SoAdConfig) /* To prevent double definition */
#error SoAdConfig already defined
#endif /* (defined SoAdConfig) */

#define SoAdConfig (SoAd_ConfigLayout.RootCfg)



/*==================[type definitions]=======================================*/

typedef struct /* SoAd_ConfigLayoutType */ {
    VAR( SoAd_ConfigType, TYPEDEF ) RootCfg;
    VAR( SoAd_SoConType, TYPEDEF ) SoAd_SoCon[10];
    VAR( SoAd_SoConGroupType, TYPEDEF ) SoAd_SoConGroup[7];
    VAR( uint32, TYPEDEF ) SoAd_PduRouteDestVirtualTxEnableBitMapInit[1];
    VAR( uint32, TYPEDEF ) SoAd_SocketRouteDestVirtualEnableBitMapInit[1];
    VAR( SoAd_PduRouteDestCommonType, TYPEDEF ) SoAd_PduRouteDestCommon[9];
    VAR( SoAd_SocketRouteType, TYPEDEF ) SoAd_SocketRoute[8];
    VAR( SoAd_PduRouteType, TYPEDEF ) SoAd_PduRoute[9];
    VAR( SoAd_PduRouteDestVirtualType, TYPEDEF ) SoAd_PduRouteDestVirtual[9];
    VAR( SoAd_SocketRouteDestType, TYPEDEF ) SoAd_SocketRouteDest[8];
    VAR( SoAd_PduRouteDestVirtualIdType, TYPEDEF ) SoAd_PduTxData_PduRouteDestVirtual_Map[9];
    VAR( SoAd_SoConRxBufferCfgType, TYPEDEF ) SoAd_SoConRxBufferCfg[3];
    VAR( SoAd_CancelReceiveSoConMapType, TYPEDEF ) SoAd_CancelReceiveSoConMap[2];
    VAR( SoAd_RoutingGroupSocketRouteDestMapMapType, TYPEDEF ) SoAd_RoutingGroupSocketRouteDestMapMap[1];
    VAR( uint8, TYPEDEF ) SoAd_RoutingGroupStateBitMapInit[8];
} SoAd_ConfigLayoutType;

typedef CONST( SoAd_ConfigLayoutType, TYPEDEF ) SoAd_ConstConfigLayoutType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define SOAD_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <SoAd_MemMap.h>

extern SoAd_ConstConfigLayoutType SoAd_ConfigLayout;

#define SOAD_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <SoAd_MemMap.h>


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* SOAD_PBCFG_H */

/*==================[end of file]============================================*/

