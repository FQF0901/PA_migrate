


/**
 * \file
 *
 * \brief AUTOSAR TcpIp
 *
 * This file contains the implementation of the AUTOSAR
 * module TcpIp.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef TCPIP_PBCFG_H
#define TCPIP_PBCFG_H



/*==================[inclusions]=============================================*/

#include <TcpIp_SymbolicNames_PBcfg.h>
#include <TSAutosar.h>
#include <TcpIp_CfgTypes.h>
#include <Platform_Types.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS TCPIP_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/

#if (defined TcpIp_Config) /* To prevent double definition */
#error TcpIp_Config already defined
#endif /* (defined TcpIp_Config) */

#define TcpIp_Config (TcpIp_ConfigLayout.RootCfg)


#if (defined TcpIpConfig) /* To prevent double definition */
#error TcpIpConfig already defined
#endif /* (defined TcpIpConfig) */

#define TcpIpConfig (TcpIp_ConfigLayout.RootCfg)



/*==================[type definitions]=======================================*/

typedef struct /* TcpIp_ConfigLayoutType */ {
    VAR( TcpIp_ConfigType, TYPEDEF ) RootCfg;
    VAR( uint8, TYPEDEF ) intIpLocalAddrCfg[2];
    VAR( uint32, TYPEDEF ) intIpV4LocalAddrCfg[2];
    VAR( TcpIp_localAddrConfigType, TYPEDEF ) localAddrCfg[2];
    VAR( TcpIp_ctrlConfigType, TYPEDEF ) ctrlCfg[1];
    VAR( uint8, TYPEDEF ) ctrlMappingCfg[1];
    VAR( uint8, TYPEDEF ) arpDadCtrlMappingCfg[1];
    VAR( TcpIp_LocalAddrIdType, TYPEDEF ) IpV4StaticIndex2LocalAddrId[2];
    VAR( TcpIp_LocalAddrIdType, TYPEDEF ) IpV4LinkLocalIndex2LocalAddrId[1];
    VAR( TcpIp_LocalAddrIdType, TYPEDEF ) IpV4DhcpIndex2LocalAddrId[1];
    VAR( TcpIp_memoryConfigType, TYPEDEF ) memoryCfg[1];
} TcpIp_ConfigLayoutType;

typedef CONST( TcpIp_ConfigLayoutType, TCPIP_APPL_CONST ) TcpIp_ConstConfigLayoutType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define TCPIP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <TcpIp_MemMap.h>

extern TcpIp_ConstConfigLayoutType TcpIp_ConfigLayout;

#define TCPIP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <TcpIp_MemMap.h>


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* TCPIP_PBCFG_H */

/*==================[end of file]============================================*/

