/**
 * \file
 *
 * \brief AUTOSAR EthIf
 *
 * This file contains the implementation of the AUTOSAR
 * module EthIf.
 *
 * \version 1.9.20
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef ETHIF_SYMBOLICNAMES_PBCFG_H
#define ETHIF_SYMBOLICNAMES_PBCFG_H

/*==================[includes]==============================================*/

/*==================[macros]================================================*/

/* EthIfController */
#if (defined EthIfConf_EcuTestNode_EthChannel)
#error EthIfConf_EcuTestNode_EthChannel is already defined
#endif
#define EthIfConf_EcuTestNode_EthChannel 0U

#if (defined ETHIF_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined EthIf_EcuTestNode_EthChannel)
#error EthIf_EcuTestNode_EthChannel is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define EthIf_EcuTestNode_EthChannel 0U
#endif /* ETHIF_PROVIDE_LEGACY_SYMBOLIC_NAMES */


/* EthIfSwitch */

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef ETHIF_SYMBOLICNAMES_PBCFG_H */
/*==================[end of file]===========================================*/
