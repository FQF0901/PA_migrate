/**
 * \file
 *
 * \brief AUTOSAR TcpIp
 *
 * This file contains the implementation of the AUTOSAR
 * module TcpIp.
 *
 * \version 3.5.15
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */



  
#ifndef TCPIP_SYMBOLICNAMES_PBCFG_H
#define TCPIP_SYMBOLICNAMES_PBCFG_H





/*==================[macros]=================================================*/

/*------------------[symbolic name definitions]------------------------------*/
#ifdef TcpIpConf_TcpIpLocalAddr_SocketAddress_TestNode_NEP
  #error already defined: TcpIpConf_TcpIpLocalAddr_SocketAddress_TestNode_NEP
#endif
/** \brief SymbolicName value for SocketAddress_TestNode_NEP */
#define TcpIpConf_TcpIpLocalAddr_SocketAddress_TestNode_NEP 0U

#if (defined TCPIP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

  #ifdef TcpIp_SocketAddress_TestNode_NEP
    #error already defined: TcpIp_SocketAddress_TestNode_NEP
  #endif
  /** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) for SocketAddress_TestNode_NEP */
  #define TcpIp_SocketAddress_TestNode_NEP 0U

#endif /* defined TCPIP_PROVIDE_LEGACY_SYMBOLIC_NAMES */




#endif /* ifndef TCPIP_SYMBOLICNAMES_PBCFG_H */

