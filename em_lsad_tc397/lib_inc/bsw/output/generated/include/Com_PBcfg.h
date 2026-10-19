


/**
 * \file
 *
 * \brief AUTOSAR Com
 *
 * This file contains the implementation of the AUTOSAR
 * module Com.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef COM_PBCFG_H
#define COM_PBCFG_H



/*==================[inclusions]=============================================*/

#include <Com_SymbolicNames_PBcfg.h>
#include <TSAutosar.h>
#include <Com_Types.h>
#include <Platform_Types.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS COM_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/

#if (defined ComConfig) /* To prevent double definition */
#error ComConfig already defined
#endif /* (defined ComConfig) */

#define ComConfig (Com_ConfigLayout.Com_RootConfig)



/*==================[type definitions]=======================================*/

typedef struct /* Com_ConfigLayoutType */ {
    VAR( Com_ConfigType, TYPEDEF ) Com_RootConfig;
    VAR( ComRxIPduType, TYPEDEF ) ComRxIPdu[21];
    VAR( ComTxIPduType, TYPEDEF ) ComTxIPdu[25];
    VAR( ComTxModeNTimesType, TYPEDEF ) ComTxModeNTimes[2];
    VAR( ComTxModePeriodicType, TYPEDEF ) ComTxModePeriodic[3];
    VAR( ComSignalRefType, TYPEDEF ) ComRxIPduSignalList[88];
    VAR( ComSignalRefType, TYPEDEF ) ComTxIPduSignalList[178];
    VAR( ComRxSignalType, TYPEDEF ) ComRxSignal[88];
    VAR( ComRxSignalExtType, TYPEDEF ) ComRxSignalExt[88];
    VAR( ComTxSignalType, TYPEDEF ) ComTxSignal[178];
    VAR( ComIPduRefType, TYPEDEF ) ComPeriodicQueueList[19];
    VAR( ComIPduRefType, TYPEDEF ) ComNTimesQueueList[6];
    VAR( ComIPduGroupMaskType, TYPEDEF ) ComIPduGroupMask[16];
    VAR( uint8, TYPEDEF ) ComIPduInit[7786];
} Com_ConfigLayoutType;

typedef CONST( Com_ConfigLayoutType, TYPEDEF ) Com_ConstConfigLayoutType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <Com_MemMap.h>

extern Com_ConstConfigLayoutType Com_ConfigLayout;

#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <Com_MemMap.h>


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* COM_PBCFG_H */

/*==================[end of file]============================================*/

