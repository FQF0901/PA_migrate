


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

#ifndef ETHSM_PBCFG_H
#define ETHSM_PBCFG_H



/*==================[inclusions]=============================================*/

#include <EthSM_SymbolicNames_PBcfg.h>
#include <TSAutosar.h>
#include <EthSM_Types_ExtGen.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS ETHSM_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/

#if (defined EthSMConfig) /* To prevent double definition */
#error EthSMConfig already defined
#endif /* (defined EthSMConfig) */

#define EthSMConfig (EthSM_ConfigLayout.RootCfg)



/*==================[type definitions]=======================================*/

typedef struct /* EthSM_ConfigLayoutType */ {
    VAR( EthSM_ConfigType, TYPEDEF ) RootCfg;
    VAR( EthSM_NetworkType, TYPEDEF ) Network[1];
} EthSM_ConfigLayoutType;

typedef CONST( EthSM_ConfigLayoutType, ETHSM_APPL_CONST ) EthSM_ConstConfigLayoutType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define ETHSM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <EthSM_MemMap.h>

/** 

          Module post build configuration. - Static code accesses this configuration
          solely via the pointer of type Module_ConfigType passed to
          Module_Init() as parameter.
        
 */
extern EthSM_ConstConfigLayoutType EthSM_ConfigLayout;

#define ETHSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <EthSM_MemMap.h>


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* ETHSM_PBCFG_H */

/*==================[end of file]============================================*/

