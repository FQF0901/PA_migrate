


/**
 * \file
 *
 * \brief AUTOSAR EthIf
 *
 * This file contains the implementation of the AUTOSAR
 * module EthIf.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef ETHIF_PBCFG_H
#define ETHIF_PBCFG_H



/*==================[inclusions]=============================================*/

#include <EthIf_SymbolicNames_PBcfg.h>
#include <TSAutosar.h>
#include <EthIf_Types_ExtGen.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS ETHIF_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/

#if (defined EthIf_Config) /* To prevent double definition */
#error EthIf_Config already defined
#endif /* (defined EthIf_Config) */

#define EthIf_Config (EthIf_ConfigLayout.RootCfg)


#if (defined EthIfConfigSet) /* To prevent double definition */
#error EthIfConfigSet already defined
#endif /* (defined EthIfConfigSet) */

#define EthIfConfigSet (EthIf_ConfigLayout.RootCfg)



/*==================[type definitions]=======================================*/

typedef struct /* EthIf_ConfigLayoutType */ {
    VAR( EthIf_ConfigType, TYPEDEF ) RootCfg;
    VAR( EthIf_CtrlType, TYPEDEF ) EthIf_EthIfCtrl[1];
    VAR( EthIf_PhysCtrlType, TYPEDEF ) EthIf_PhysCtrl[1];
} EthIf_ConfigLayoutType;

typedef CONST( EthIf_ConfigLayoutType, ETHIF_APPL_CONST ) EthIf_ConstConfigLayoutType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define ETHIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <EthIf_MemMap.h>

/** 

          Module post build configuration. - Static code accesses this configuration
          solely via the pointer of type Module_ConfigType passed to
          Module_Init() as parameter.
        
 */
extern EthIf_ConstConfigLayoutType EthIf_ConfigLayout;

#define ETHIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <EthIf_MemMap.h>


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* ETHIF_PBCFG_H */

/*==================[end of file]============================================*/

