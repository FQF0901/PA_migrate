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












#ifndef ETHIF_CFG_H
#define ETHIF_CFG_H

/*==================[includes]==============================================*/

#include <TSAutosar.h>              /* Global configuration */
#include <EthIf_DefProg_Cfg.h>

/*==================[macros]================================================*/

#define ETHIF_ASR403    0U
#define ETHIF_ASR422    1U
#define ETHIF_ASR430    2U

#if (defined ETHIF_DEV_ERROR_DETECT)
#error ETHIF_DEV_ERROR_DETECT is already defined
#endif
/** \brief Pre-processor switch for enabling development error detection.
 */
#define ETHIF_DEV_ERROR_DETECT        STD_ON

/** \brief Switch for DEM to DET reporting for production errors  */
#define ETHIF_ERR_HANDLING_TEST   TS_PROD_ERR_DISABLE


#if (defined ETHIF_GET_VERSION_INFO)
#error ETHIF_GET_VERSION_INFO is already defined
#endif
/** \brief Pre-processor switch for enabling version info API support.
 */
#define ETHIF_GET_VERSION_INFO        STD_OFF

#if (defined ETHIF_VLAN_SUPPORT_ENABLE)
#error ETHIF_VLAN_SUPPORT_ENABLE is already defined
#endif
/** \brief Pre-processor switch for enabling VLAN support.
 */
#define ETHIF_VLAN_SUPPORT_ENABLE     STD_OFF

#if (defined ETHIF_TRCV_SUPPORT_ENABLE)
#error ETHIF_TRCV_SUPPORT_ENABLE is already defined
#endif
/** \brief Pre-processor switch for enabling Trcv support.
 */
#define ETHIF_TRCV_SUPPORT_ENABLE     STD_OFF

#if (defined ETHIF_TRCV_ASYNC_ENABLE)
#error ETHIF_TRCV_ASYNC_ENABLE is already defined
#endif
/** \brief Pre-processor switch for enabling async Trcv mode.
 */
#define ETHIF_TRCV_ASYNC_ENABLE     STD_OFF

#if (defined ETHIF_SWT_SUPPORT_ENABLE)
#error ETHIF_SWT_SUPPORT_ENABLE is already defined
#endif
/** \brief Pre-processor switch for enabling Swt support.
 */
#define ETHIF_SWT_SUPPORT_ENABLE      STD_OFF

#if (defined ETHIF_VIRTUALCTRL_SUPPORT_ENABLE)
#error ETHIF_VIRTUALCTRL_SUPPORT_ENABLE is already defined
#endif
/** \brief Pre-processor switch for enabling virtual EthIfCtrl support.
 */
#define ETHIF_VIRTUALCTRL_SUPPORT_ENABLE STD_OFF

/** \brief Pre-processor switch for Eth API version.
 */
#if (defined ETHIF_ETH_SUPPORT_API_ASR403)
#error ETHIF_ETH_SUPPORT_API_ASR403 is already defined
#endif
#define ETHIF_ETH_SUPPORT_API_ASR403        0U

#if (defined ETHIF_ETH_SUPPORT_API_ASR422)
#error ETHIF_ETH_SUPPORT_API_ASR422 is already defined
#endif
#define ETHIF_ETH_SUPPORT_API_ASR422        1U

#if (defined ETHIF_ETH_SUPPORT_API_ASR430)
#error ETHIF_ETH_SUPPORT_API_ASR430 is already defined
#endif
#define ETHIF_ETH_SUPPORT_API_ASR430        2U

#if (defined ETHIF_ETH_SUPPORT_API_ASR430_EB)
#error ETHIF_ETH_SUPPORT_API_ASR430_EB is already defined
#endif
#define ETHIF_ETH_SUPPORT_API_ASR430_EB     3U

#if (defined ETHIF_ETH_SUPPORT_API)
#error ETHIF_ETH_SUPPORT_API is already defined
#endif
#define ETHIF_ETH_SUPPORT_API           ETHIF_ETH_SUPPORT_API_ASR422

#if (defined ETHIF_ETH_UPDATEPHYSADDRFILTER_API_ENABLE)
#error ETHIF_ETH_UPDATEPHYSADDRFILTER_API_ENABLE is already defined
#endif
/** \brief Pre-processor switch for Eth_UpdatePhysAddrFilter API.
 */
#define ETHIF_ETH_UPDATEPHYSADDRFILTER_API_ENABLE STD_OFF

#if (defined ETHIF_ETH_SETPHYSADDR_API_ENABLE)
#error ETHIF_ETH_SETPHYSADDR_API_ENABLE is already defined
#endif
/** \brief Pre-processor switch for Eth_UpdatePhysAddrFilter API. */
#define ETHIF_ETH_SETPHYSADDR_API_ENABLE STD_OFF

#if (defined ETHIF_MII_API_ENABLE)
#error ETHIF_MII_API_ENABLE is already defined
#endif
/** \brief Pre-processor switch for EthIf_ReadMii and EthIf_WriteMii API. */
#define ETHIF_MII_API_ENABLE STD_OFF

#if (defined ETHIF_ETH_ASYNC_ENABLE)
#error ETHIF_ETH_ASYNC_ENABLE is already defined
#endif
/** \brief Pre-processor switch for enabling async Eth physical controller mode.
 */
#define ETHIF_ETH_ASYNC_ENABLE     STD_OFF

#if (defined ETHIF_GLOBAL_TIME_SYNC_API_ENABLE)
#error ETHIF_GLOBAL_TIME_SYNC_API_ENABLE is already defined
#endif
/** \brief Pre-processor switch for all global time synch API. */
#define ETHIF_GLOBAL_TIME_SYNC_API_ENABLE STD_ON

#if (defined ETHIF_GETPORTMACADDR_API)
#error ETHIF_GETPORTMACADDR_API is already defined
#endif
/** \brief Pre-processor switch for EthIf_GetPortMacAddr API. */
#define ETHIF_GETPORTMACADDR_API STD_OFF

#if (defined ETHIF_GETARLTABLE_API)
#error ETHIF_GETARLTABLE_API is already defined
#endif
/** \brief Pre-processor switch for EthIf_GetArlTable API. */
#define ETHIF_GETARLTABLE_API STD_OFF

#if (defined ETHIF_GETBUFFERLEVEL_API)
#error ETHIF_GETBUFFERLEVEL_API is already defined
#endif
/** \brief Pre-processor switch for EthIf_GetBufferLevel API. */
#define ETHIF_GETBUFFERLEVEL_API STD_OFF

#if (defined ETHIF_STORECONFIGURATION_API)
#error ETHIF_STORECONFIGURATION_API is already defined
#endif
/** \brief Pre-processor switch for EthIf_StoreConfiguration API. */
#define ETHIF_STORECONFIGURATION_API STD_OFF

#if (defined ETHIF_RESETCONFIGURATION_API)
#error ETHIF_RESETCONFIGURATION_API is already defined
#endif
/** \brief Pre-processor switch for EthIf_ResetConfiguration API. */
#define ETHIF_RESETCONFIGURATION_API STD_OFF

#if (defined ETHIF_SWTGETCOUNTERVALUES_API)
#error ETHIF_SWTGETCOUNTERVALUES_API is already defined
#endif
/** \brief Pre-processor switch for EthIf_SwtGetCounterValues API. */
#define ETHIF_SWTGETCOUNTERVALUES_API STD_OFF

#if (defined ETHIF_WAKEUPSUPPORT_API)
#error ETHIF_WAKEUPSUPPORT_API is already defined
#endif
/** \brief Pre-processor switch for EthIf_SetTransceiverWakeupMode and EthIf_CheckWakeup API. */
#define ETHIF_WAKEUPSUPPORT_API STD_OFF

#if (defined ETHIF_GETCTRLIDXLIST_API)
#error ETHIF_GETCTRLIDXLIST_API is already defined
#endif
/** \brief Pre-processor switch for EthIf_GetCtrlIdxList API. */
#define ETHIF_GETCTRLIDXLIST_API STD_OFF

#if (defined ETHIF_GETVLANIDSUPPORT_API)
#error ETHIF_GETVLANIDSUPPORT_API is already defined
#endif
/** \brief Pre-processor switch for EthIf_GetVlanId API. */
#define ETHIF_GETVLANIDSUPPORT_API STD_OFF

#if (defined ETHIF_GETANDRESETMEASUREMENTDATA_API)
#error ETHIF_GETANDRESETMEASUREMENTDATA_API is already defined
#endif
/** \brief Pre-processor switch for EthIf_GetAndResetMeasurementData API. */
#define ETHIF_GETANDRESETMEASUREMENTDATA_API STD_OFF

#if (defined ETHIF_SECURITYEVENT_REPORTING)
#error ETHIF_SECURITYEVENT_REPORTING is already defined
#endif
/** \brief Pre-processor switch for enabling Security event reporting to IdsM. */
#define ETHIF_SECURITYEVENT_REPORTING STD_OFF

#if (defined ETHIF_VERIFYCONFIG_API)
#error ETHIF_VERIFYCONFIG_API is already defined
#endif
/** \brief Pre-processor switch for EthIf_VerifyConfig API. */
#define ETHIF_VERIFYCONFIG_API STD_OFF

#if (defined ETHIF_SETFORWARDINGMODE_API)
#error ETHIF_SETFORWARDINGMODE_API is already defined
#endif
/** \brief Pre-processor switch for EthIf_SetForwardingMode API. */
#define ETHIF_SETFORWARDINGMODE_API STD_OFF

#if (defined ETHIF_GETTRANSCEIVERWAKEUPMODE_API)
#error ETHIF_GETTRANSCEIVERWAKEUPMODE_API is already defined
#endif
/** \brief Pre-processor switch for EthIf_GetTransceiverWakeupMode API. */
#define ETHIF_GETTRANSCEIVERWAKEUPMODE_API STD_OFF
#if (defined ETHIF_DEVICEAUTHENTICATION_API)
#error ETHIF_DEVICEAUTHENTICATION_API is already defined
#endif
/** \brief Pre-processor switch for EthIf_EnableRelatedEthIfCtrls and EthIf_DisableRelatedEthIfCtrls API. */
#define ETHIF_DEVICEAUTHENTICATION_API STD_OFF

#if (defined ETHIF_RETRANSMIT_API)
#error ETHIF_RETRANSMIT_API is already defined
#endif
/** \brief Pre-processor switch for EthIf_Retransmit API. */
#define ETHIF_RETRANSMIT_API STD_OFF

#if (defined ETHIF_SIGNAL_QUALITY_APIS)
#error ETHIF_SIGNAL_QUALITY_APIS is already defined
#endif
/** \brief Pre-processor switch for enabling signal quality APIs.
 */
#define ETHIF_SIGNAL_QUALITY_APIS   STD_ON


#if (defined ETHIF_SWITCHMANAGEMENTSUPPORT)
#error ETHIF_SWITCHMANAGEMENTSUPPORT is already defined
#endif
/** \brief Pre-processor switch for switch management APIs to support a Switch-port specific
           communication attribute access. */
#define ETHIF_SWITCHMANAGEMENTSUPPORT STD_OFF

#if (defined ETHIF_MAINFUNCTIONSTATE_API_ENABLE)
#error ETHIF_MAINFUNCTIONSTATE_API_ENABLE is already defined
#endif
/** \brief Pre-processor switch for EthIf_MainFunctionState API.
 */
#define ETHIF_MAINFUNCTIONSTATE_API_ENABLE    STD_OFF

#if (defined ETHIF_MAINFUNCTIONSTATE_IS_STATIC)
#error ETHIF_MAINFUNCTIONSTATE_IS_STATIC is already defined
#endif
/** \brief macro to determine if  EthIf_MainFunctionState() is external API or not */
#define ETHIF_MAINFUNCTIONSTATE_IS_STATIC    STATIC

#if (defined ETHIF_RX_INDICATION_ITERATIONS)
#error ETHIF_RX_INDICATION_ITERATIONS is already defined
#endif
/** \brief Maximum number of RxINdication per controller per EthIf_MainFunctionRx iteration.
 */
#define ETHIF_RX_INDICATION_ITERATIONS 10U

#if (defined ETHIF_SET_MODE_TIMEOUT)
#error ETHIF_SET_MODE_TIMEOUT is already defined
#endif
/** \brief Time duration after which set mode operation will be repeated
 */
#define ETHIF_SET_MODE_TIMEOUT           0U

#if (defined ETHIF_SWITCH_OFF_PORT_TIMEDELAY)
#error ETHIF_SWITCH_OFF_PORT_TIMEDELAY is already defined
#endif
/** \brief Time delay after the mode "ETHTRCV_MODE_DOWN" of a EthIfSwitchPortGroup will be executed.
 */
#define ETHIF_SWITCH_OFF_PORT_TIMEDELAY           0U

#if (defined ETHIF_PORT_STARTUP_ACTIVE_TIME)
#error ETHIF_PORT_STARTUP_ACTIVE_TIME is already defined
#endif
/** \brief Time delay to switch off ports started with EthIf_StartAllPorts()
 */
#define ETHIF_PORT_STARTUP_ACTIVE_TIME           0U

#if (defined ETHIF_ETH_BSWIMPL)
#error ETHIF_ETH_BSWIMPL is already defined
#endif
/** \brief Number of configured EthIfEthControllerBswmdImplementationRefs.
 */
#define ETHIF_ETH_BSWIMPL 0U
#if (defined ETHIF_ETHTRCV_BSWIMPL)
#error ETHIF_ETHTRCV_BSWIMPL is already defined
#endif
/** \brief Number of configured EthIfEthTrcvBswmdImplementationRefs.
 */
#define ETHIF_ETHTRCV_BSWIMPL 0U
#if (defined ETHIF_ETHSWT_BSWIMPL)
#error ETHIF_ETHSWT_BSWIMPL is already defined
#endif
/** \brief Number of configured EthIfEthSwtBswmdImplementationRefs.
 */
#define ETHIF_ETHSWT_BSWIMPL 0U

#if (defined ETHIF_ETHIFCTRL_ARRAYSIZE)
#error ETHIF_ETHIFCTRL_ARRAYSIZE is already defined
#endif
/** \brief Reserved array space for EthIf controllers.
 */
#define ETHIF_ETHIFCTRL_ARRAYSIZE 1U

#if (defined ETHIF_PHYCTRL_ARRAYSIZE)
#error ETHIF_PHYCTRL_ARRAYSIZE is already defined
#endif
/** \brief Reserved array space for physical controllers.
 */
#define ETHIF_PHYCTRL_ARRAYSIZE 1U

#if (defined ETHIF_TRCV_ARRAYSIZE)
#error ETHIF_TRCV_ARRAYSIZE is already defined
#endif
/** \brief Reserved array space for transceivers.
 */
#define ETHIF_TRCV_ARRAYSIZE 1U

#if (defined ETHIF_PORTGROUPSUPPORT)
#error ETHIF_PORTGROUPSUPPORT is already defined
#endif
/** \brief Pre-processor switch for enabling APIs to support a Switching of port groups
 */
#define ETHIF_PORTGROUPSUPPORT STD_OFF

#if (defined ETHIF_ETHSWT_ARRAYSIZE)
#error ETHIF_ETHSWT_ARRAYSIZE is already defined
#endif
/** \brief Reserved array space for Ethernet switches
 */
#define ETHIF_ETHSWT_ARRAYSIZE 0U

#if (defined ETHIF_PORTGROUPS_ARRAYSIZE)
#error ETHIF_PORTGROUPS_ARRAYSIZE is already defined
#endif
/** \brief Reserved array space for switch port groups supported switch.
 *  When EthIfController references Ethernet Switch (not Switch Port Group), it is considered
 *  as a logical Switch Port Group, thus needs to be counted in this parameter.
 */
#define ETHIF_PORTGROUPS_ARRAYSIZE 0U

#if (defined ETHIF_PORTS_ARRAYSIZE)
#error ETHIF_PORTS_ARRAYSIZE is already defined
#endif
/** \brief Reserved array space for Ethernet switch ports
 */
#define ETHIF_PORTS_ARRAYSIZE 0U

#if (defined ETHIF_INIT_CTRL_TRCV)
#error ETHIF_INIT_CTRL_TRCV is already defined
#endif
/** \brief Pre-processor switch to enable / disable EthIf to initialize configured physical controllers and transceivers.
 */
#define ETHIF_INIT_CTRL_TRCV STD_ON


#if (defined ETHIF_ETHSWT_RX_PREPROCESS)
#error ETHIF_ETHSWT_RX_PREPROCESS is already defined
#endif

/** \brief Pre-processor switch to enable / disable the call to EthSwt_EthIfPreProcessRxFrame().
 */
#if(ETHIF_SWT_SUPPORT_ENABLE == STD_ON)
#define ETHIF_ETHSWT_RX_PREPROCESS STD_OFF
#else
#define ETHIF_ETHSWT_RX_PREPROCESS STD_OFF
#endif

#if (defined ETHIF_ETHSWT_TX_ADAPTFRAME)
#error ETHIF_ETHSWT_TX_ADAPTFRAME is already defined
#endif

/** \brief Pre-processor switch to enable / disable the API calls to .
 */
#if(ETHIF_SWT_SUPPORT_ENABLE == STD_ON)
#define ETHIF_ETHSWT_TX_ADAPTFRAME STD_OFF
#else
#define ETHIF_ETHSWT_TX_ADAPTFRAME STD_OFF
#endif

#if (defined ETHIF_PORT_STATE_MGMT_ENABLED)
#error ETHIF_PORT_STATE_MGMT_ENABLED is already defined
#endif
/** \brief Pre-processor switch for enabling Ethernet switch port made and link state management
 */
 #define ETHIF_PORT_STATE_MGMT_ENABLED STD_OFF

/** \brief Compile time verification value */
#if (defined ETHIF_CFG_SIGNATURE)
#error ETHIF_CFG_SIGNATURE already defined!
#endif
#define ETHIF_CFG_SIGNATURE  1342482760U

/** \brief Compile time Published information verification value */
#if (defined ETHIF_PUBLIC_INFO_SIGNATURE)
#error ETHIF_PUBLIC_INFO_SIGNATURE already defined!
#endif
#define ETHIF_PUBLIC_INFO_SIGNATURE  3357524705U

/** \brief Pre-processor switch indicates if PbcfgM uses EthIf */
#if (defined ETHIF_PBCFGM_SUPPORT_ENABLED)
#error ETHIF_PBCFGM_SUPPORT_ENABLED already defined!
#endif
#define ETHIF_PBCFGM_SUPPORT_ENABLED  STD_OFF

/** \brief Pre-processor switch to enable/disable relocatable postbuild config
 */
#if (defined ETHIF_RELOCATABLE_CFG_ENABLE)
#error ETHIF_RELOCATABLE_CFG_ENABLE is already defined
#endif
#define ETHIF_RELOCATABLE_CFG_ENABLE STD_ON

/** \brief Pre-processor switch indicating that EthIf_IsValidConfig function shall be mapped to memory section ETHIF_CODE_CC_BLOCK
*/
#if (defined ETHIF_ISVALIDCONFIG_MMAP_ENABLED)
#error ETHIF_ISVALIDCONFIG_MMAP_ENABLED already defined!
#endif
#define ETHIF_ISVALIDCONFIG_MMAP_ENABLED STD_OFF


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

#endif /* ifndef ETHIF_CFG_H */

/*==================[end of file]===========================================*/
