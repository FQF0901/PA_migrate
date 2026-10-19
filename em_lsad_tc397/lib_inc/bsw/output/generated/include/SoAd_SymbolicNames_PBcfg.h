/**
 * \file
 *
 * \brief AUTOSAR SoAd
 *
 * This file contains the implementation of the AUTOSAR
 * module SoAd.
 *
 * \version 1.8.19
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */


#ifndef SOAD_SYMBOLICNAMES_PBCFG_H
#define SOAD_SYMBOLICNAMES_PBCFG_H

/*==================[includes]==============================================*/

/*==================[macros]================================================*/

/* -----------------[SoAdSocketId]----------------------------------------- */

#if (defined SoAdConf_CGSocketConnectionBundleUDP_SocketConnection_Udp)
#error SoAdConf_CGSocketConnectionBundleUDP_SocketConnection_Udp is already defined
#endif
/** \brief Export symbolic name value for CGSocketConnectionBundleUDP_SocketConnection_Udp */
#define SoAdConf_CGSocketConnectionBundleUDP_SocketConnection_Udp 0U

#if (defined SoAdConf_CGSocketConnectionBundleUDP_SocketConnectionTestToDebugNode)
#error SoAdConf_CGSocketConnectionBundleUDP_SocketConnectionTestToDebugNode is already defined
#endif
/** \brief Export symbolic name value for CGSocketConnectionBundleUDP_SocketConnectionTestToDebugNode */
#define SoAdConf_CGSocketConnectionBundleUDP_SocketConnectionTestToDebugNode 1U

#if (defined SoAdConf_CGSocketConnectionBundleUDP_SocketConnectionTestToUssToolNode)
#error SoAdConf_CGSocketConnectionBundleUDP_SocketConnectionTestToUssToolNode is already defined
#endif
/** \brief Export symbolic name value for CGSocketConnectionBundleUDP_SocketConnectionTestToUssToolNode */
#define SoAdConf_CGSocketConnectionBundleUDP_SocketConnectionTestToUssToolNode 2U

#if (defined SoAdConf_CGSocketConnectionBundleUDP_SocketConnectionTestToCfmNode)
#error SoAdConf_CGSocketConnectionBundleUDP_SocketConnectionTestToCfmNode is already defined
#endif
/** \brief Export symbolic name value for CGSocketConnectionBundleUDP_SocketConnectionTestToCfmNode */
#define SoAdConf_CGSocketConnectionBundleUDP_SocketConnectionTestToCfmNode 3U

#if (defined SoAdConf_CGSocketConnectionBundleTCP_SocketConnectionDebugToTestNode)
#error SoAdConf_CGSocketConnectionBundleTCP_SocketConnectionDebugToTestNode is already defined
#endif
/** \brief Export symbolic name value for CGSocketConnectionBundleTCP_SocketConnectionDebugToTestNode */
#define SoAdConf_CGSocketConnectionBundleTCP_SocketConnectionDebugToTestNode 4U

#if (defined SoAdConf_SocketConnectionBundleUDP_Test_SoAdSocketConnection_UDPTest)
#error SoAdConf_SocketConnectionBundleUDP_Test_SoAdSocketConnection_UDPTest is already defined
#endif
/** \brief Export symbolic name value for SocketConnectionBundleUDP_Test_SoAdSocketConnection_UDPTest */
#define SoAdConf_SocketConnectionBundleUDP_Test_SoAdSocketConnection_UDPTest 5U

#if (defined SoAdConf_SocketConnectionBundleDoIp_UDP_SoAdSocketConnection_UDP_Discover)
#error SoAdConf_SocketConnectionBundleDoIp_UDP_SoAdSocketConnection_UDP_Discover is already defined
#endif
/** \brief Export symbolic name value for SocketConnectionBundleDoIp_UDP_SoAdSocketConnection_UDP_Discover */
#define SoAdConf_SocketConnectionBundleDoIp_UDP_SoAdSocketConnection_UDP_Discover 6U

#if (defined SoAdConf_SocketConnectionBundleDoIp_UDP2_SoAdSocketConnection_UDP_TEST_EQUIPMENT)
#error SoAdConf_SocketConnectionBundleDoIp_UDP2_SoAdSocketConnection_UDP_TEST_EQUIPMENT is already defined
#endif
/** \brief Export symbolic name value for SocketConnectionBundleDoIp_UDP2_SoAdSocketConnection_UDP_TEST_EQUIPMENT */
#define SoAdConf_SocketConnectionBundleDoIp_UDP2_SoAdSocketConnection_UDP_TEST_EQUIPMENT 7U

#if (defined SoAdConf_SocketConnectionBundleDoIp_Tcp_SocketConnectionBundleDoIp_Tcp)
#error SoAdConf_SocketConnectionBundleDoIp_Tcp_SocketConnectionBundleDoIp_Tcp is already defined
#endif
/** \brief Export symbolic name value for SocketConnectionBundleDoIp_Tcp_SocketConnectionBundleDoIp_Tcp */
#define SoAdConf_SocketConnectionBundleDoIp_Tcp_SocketConnectionBundleDoIp_Tcp 8U

#if (defined SoAdConf_SocketConnectionBundleDoIp_Tcp2_SocketConnectionBundleDoIp_Tcp2)
#error SoAdConf_SocketConnectionBundleDoIp_Tcp2_SocketConnectionBundleDoIp_Tcp2 is already defined
#endif
/** \brief Export symbolic name value for SocketConnectionBundleDoIp_Tcp2_SocketConnectionBundleDoIp_Tcp2 */
#define SoAdConf_SocketConnectionBundleDoIp_Tcp2_SocketConnectionBundleDoIp_Tcp2 9U

/* -----------------[SoAdTxPduId]------------------------------------------ */

#if (defined SoAdConf_PRPdu_CounterOut_T)
#error SoAdConf_PRPdu_CounterOut_T is already defined
#endif
/** \brief Export symbolic name value for PRPdu_CounterOut_T */
#define SoAdConf_PRPdu_CounterOut_T 0U

#if (defined SoAdConf_PRPdu_DummyIn_T)
#error SoAdConf_PRPdu_DummyIn_T is already defined
#endif
/** \brief Export symbolic name value for PRPdu_DummyIn_T */
#define SoAdConf_PRPdu_DummyIn_T 1U

#if (defined SoAdConf_PRPdu_UssTool_T)
#error SoAdConf_PRPdu_UssTool_T is already defined
#endif
/** \brief Export symbolic name value for PRPdu_UssTool_T */
#define SoAdConf_PRPdu_UssTool_T 2U

#if (defined SoAdConf_PRPdu_Cfm_T)
#error SoAdConf_PRPdu_Cfm_T is already defined
#endif
/** \brief Export symbolic name value for PRPdu_Cfm_T */
#define SoAdConf_PRPdu_Cfm_T 3U

#if (defined SoAdConf_PRPdu_UdpOut_31T)
#error SoAdConf_PRPdu_UdpOut_31T is already defined
#endif
/** \brief Export symbolic name value for PRPdu_UdpOut_31T */
#define SoAdConf_PRPdu_UdpOut_31T 4U

#if (defined SoAdConf_PRPdu_UdpOut_DoIp_Discover)
#error SoAdConf_PRPdu_UdpOut_DoIp_Discover is already defined
#endif
/** \brief Export symbolic name value for PRPdu_UdpOut_DoIp_Discover */
#define SoAdConf_PRPdu_UdpOut_DoIp_Discover 5U

#if (defined SoAdConf_PRPdu_UdpOut_DoIp_TEST_EQUIPMENT)
#error SoAdConf_PRPdu_UdpOut_DoIp_TEST_EQUIPMENT is already defined
#endif
/** \brief Export symbolic name value for PRPdu_UdpOut_DoIp_TEST_EQUIPMENT */
#define SoAdConf_PRPdu_UdpOut_DoIp_TEST_EQUIPMENT 6U

#if (defined SoAdConf_PRPdu_TcpOut_DoIp)
#error SoAdConf_PRPdu_TcpOut_DoIp is already defined
#endif
/** \brief Export symbolic name value for PRPdu_TcpOut_DoIp */
#define SoAdConf_PRPdu_TcpOut_DoIp 7U

#if (defined SoAdConf_PRPdu_TcpOut_DoIp2)
#error SoAdConf_PRPdu_TcpOut_DoIp2 is already defined
#endif
/** \brief Export symbolic name value for PRPdu_TcpOut_DoIp2 */
#define SoAdConf_PRPdu_TcpOut_DoIp2 8U

/* -----------------[SoAdRxPduId]------------------------------------------ */

#if (defined SoAdConf_SRSocketConnectionDoIP_Tcp_SoAdSocketRouteDest_0)
#error SoAdConf_SRSocketConnectionDoIP_Tcp_SoAdSocketRouteDest_0 is already defined
#endif
/** \brief Export symbolic name value for SRSocketConnectionDoIP_Tcp_SoAdSocketRouteDest_0 */
#define SoAdConf_SRSocketConnectionDoIP_Tcp_SoAdSocketRouteDest_0 0U

#if (defined SoAdConf_SRSocketConnectionDoIP_Tcp2_SoAdSocketRouteDest_0)
#error SoAdConf_SRSocketConnectionDoIP_Tcp2_SoAdSocketRouteDest_0 is already defined
#endif
/** \brief Export symbolic name value for SRSocketConnectionDoIP_Tcp2_SoAdSocketRouteDest_0 */
#define SoAdConf_SRSocketConnectionDoIP_Tcp2_SoAdSocketRouteDest_0 1U

/* -----------------[SoAdRoutingGroupId]----------------------------------- */

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/


#endif /* ifndef SOAD_SYMBOLICNAMES_PBCFG_H */
/*==================[end of file]===========================================*/
