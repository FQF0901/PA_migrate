


/**
 * \file
 *
 * \brief AUTOSAR DoIP
 *
 * This file contains the implementation of the AUTOSAR
 * module DoIP.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef DOIP_PBCFG_H
#define DOIP_PBCFG_H



/*==================[inclusions]=============================================*/

#include <DoIP_SymbolicNames_PBcfg.h>
#include <TSAutosar.h>
#include <DoIP_Types_Int.h>
#include <Platform_Types.h>
#include <ComStack_Cfg.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS DOIP_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/

#if (defined DoIP_Config) /* To prevent double definition */
#error DoIP_Config already defined
#endif /* (defined DoIP_Config) */

#define DoIP_Config (DoIP_ConfigLayout.RootCfg)


#if (defined DoIPConfigSet) /* To prevent double definition */
#error DoIPConfigSet already defined
#endif /* (defined DoIPConfigSet) */

#define DoIPConfigSet (DoIP_ConfigLayout.RootCfg)



/*==================[type definitions]=======================================*/

typedef struct /* DoIP_ConfigLayoutType */ {
    VAR( DoIP_ConfigType, TYPEDEF ) RootCfg;
    VAR( DoIP_TcpConnType, TYPEDEF ) DoIP_TcpCon[2];
    VAR( DoIP_UdpConnType, TYPEDEF ) DoIP_UdpAnnCon[1];
    VAR( DoIP_UdpConnType, TYPEDEF ) DoIP_UdpCon[1];
    VAR( DoIP_TesterType, TYPEDEF ) DoIP_Tester[1];
    VAR( DoIP_RouteType, TYPEDEF ) DoIP_Route[1];
    VAR( DoIP_RoutingActType, TYPEDEF ) DoIP_RoutingActivation[1];
    VAR( uint16, TYPEDEF ) DoIP_LOT_Target[1];
    VAR( PduIdType, TYPEDEF ) DoIP_LOT_PduRTxPduId[1];
    VAR( PduIdType, TYPEDEF ) DoIP_LOT_PduRRxPduId[1];
} DoIP_ConfigLayoutType;

typedef CONST( DoIP_ConfigLayoutType, DOIP_APPL_CONST ) DoIP_ConstConfigLayoutType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define DOIP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <DoIP_MemMap.h>

/** 

          Module post build configuration. - Static code accesses this configuration
          solely via the pointer of type Module_ConfigType passed to
          Module_Init() as parameter.
        
 */
extern DoIP_ConstConfigLayoutType DoIP_ConfigLayout;

#define DOIP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <DoIP_MemMap.h>


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* DOIP_PBCFG_H */

/*==================[end of file]============================================*/

