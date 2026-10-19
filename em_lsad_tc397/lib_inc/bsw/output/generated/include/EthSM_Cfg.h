/**
 * \file
 *
 * \brief AUTOSAR EthSM
 *
 * This file contains the implementation of the AUTOSAR
 * module EthSM.
 *
 * \version 1.6.15
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */


#ifndef ETHSM_CFG_H
#define ETHSM_CFG_H

/*==================[includes]==============================================*/

#include <TSAutosar.h>              /* Global configuration */
#include <EthSM_DefProg_Cfg.h>

/*==================[macros]================================================*/

#if (defined ETHSM_SINGLE_NETWORK_OPT_ENABLE)
#error ETHSM_SINGLE_NETWORK_OPT_ENABLE is already defined
#endif
/** \brief Pre-processor switch for enabling single network optimization.
 */
#define ETHSM_SINGLE_NETWORK_OPT_ENABLE     STD_ON

#if (defined ETHSM_DEV_ERROR_DETECT)
#error ETHSM_DEV_ERROR_DETECT is already defined
#endif
/** \brief Pre-processor switch for enabling development error detection.
 */
#define ETHSM_DEV_ERROR_DETECT              STD_ON

#if (defined ETHSM_VERSION_INFO_API)
#error ETHSM_VERSION_INFO_API is already defined
#endif
/** \brief Pre-processor switch for enabling version info API support.
 */
#define ETHSM_VERSION_INFO_API              STD_ON

#if (defined ETHSM_NETWORKS_ARRAYSIZE)
#error ETHSM_NETWORKS_ARRAYSIZE is already defined
#endif
/** \brief Maximum value of handle of destinated communication network for request
 */
#define ETHSM_NETWORKS_ARRAYSIZE            1U

#if (defined ETHSM_DEVAUTH_SUPPORT_ENABLE)
#error ETHSM_DEVAUTH_SUPPORT_ENABLE is already defined
#endif
/** \brief Pre-processor switch for enabling Device Authentication Support.
 */
#define ETHSM_DEVAUTH_SUPPORT_ENABLE     STD_OFF

#if (defined ETHSM_MULTI_CORE)
#error ETHSM_MULTI_CORE is already defined
#endif
/** \brief Pre-processor switch for enabling Multi core support.
 */
#define ETHSM_MULTI_CORE              STD_OFF

#if (defined ETHSM_CALL_COMM_BUSSM_MODEINDICATION)
#error ETHSM_CALL_COMM_BUSSM_MODEINDICATION is already defined
#endif
/** \brief Pre-processor switch for selecting ComM or Rte generated function.
 */
#define ETHSM_CALL_COMM_BUSSM_MODEINDICATION(NetworkIdx, Channel, ComMode)    ComM_BusSM_ModeIndication(Channel, ComMode)

#if (defined ETHSM_PROD_ERR_HANDLING_CTRL_TEST)
#error ETHSM_PROD_ERR_HANDLING_CTRL_TEST is already defined
#endif
/** \brief Switch for DEM to DET reporting for production error ETHSM_E_LINK_DOWN */
#define ETHSM_PROD_ERR_HANDLING_CTRL_TEST   TS_PROD_ERR_DISABLE

#if (defined ETHSM_E_DEMTODET_CTRL_TEST)
#error ETHSM_E_DEMTODET_CTRL_TEST is already defined
#endif

/** \brief Compile time verification value */
#if (defined ETHSM_CFG_SIGNATURE)
#error ETHSM_CFG_SIGNATURE already defined!
#endif
#define ETHSM_CFG_SIGNATURE  376937700U

/** \brief Compile time Published information verification value */
#if (defined ETHSM_PUBLIC_INFO_SIGNATURE)
#error ETHSM_PUBLIC_INFO_SIGNATURE already defined!
#endif
#define ETHSM_PUBLIC_INFO_SIGNATURE  1692380571U

/** \brief Pre-processor switch indicates if PbcfgM uses EthSM */
#if (defined ETHSM_PBCFGM_SUPPORT_ENABLED)
#error ETHSM_PBCFGM_SUPPORT_ENABLED already defined!
#endif
#define ETHSM_PBCFGM_SUPPORT_ENABLED  STD_OFF

/** \brief Pre-processor switch to enable/disable relocatable postbuild config
 */
#if (defined ETHSM_RELOCATABLE_CFG_ENABLE)
#error ETHSM_RELOCATABLE_CFG_ENABLE is already defined
#endif
#define ETHSM_RELOCATABLE_CFG_ENABLE STD_ON

/** \brief Pre-processor switch indicating that EthSM_IsValidConfig function shall be mapped to memory section ETHSM_CODE_CC_BLOCK
*/
#if (defined ETHSM_ISVALIDCONFIG_MMAP_ENABLED)
#error ETHSM_ISVALIDCONFIG_MMAP_ENABLED already defined!
#endif
#define ETHSM_ISVALIDCONFIG_MMAP_ENABLED STD_OFF

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/*==================[includes]==============================================*/

#endif /* ifndef ETHSM_CFG_H */

/*==================[end of file]===========================================*/

