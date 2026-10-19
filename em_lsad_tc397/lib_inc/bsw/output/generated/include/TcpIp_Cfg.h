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

#ifndef TCPIP_CFG_H
#define TCPIP_CFG_H

/* It is required by AUTOSAR include the headerfile that contains the post-build/link-time symbolic IDs here */
/* This mixture of config classes can be omitted for module internal purposes */
#ifndef TCPIP_NO_CFGCLASSMIX_REQUIRED
#include <TcpIp_SymbolicNames_PBcfg.h>
#endif /* TCPIP_NO_CFGCLASSMIX_REQUIRED */

#undef TCPIP_NO_CFGCLASSMIX_REQUIRED

#ifdef TCPIP_DEV_ERROR_DETECT
  #error already defined: TCPIP_DEV_ERROR_DETECT
#endif
/** \brief Development error detection support */
#define TCPIP_DEV_ERROR_DETECT STD_ON

#ifdef TCPIP_VERSION_INFO_API
  #error already defined: TCPIP_VERSION_INFO_API
#endif
/** \brief VersionInfo API support */
#define TCPIP_VERSION_INFO_API STD_OFF

#ifdef TCPIP_IPV4_ENABLED
  #error already defined: TCPIP_IPV4_ENABLED
#endif
/** \brief IPv4 support */
#define TCPIP_IPV4_ENABLED STD_ON

#ifdef TCPIP_IPV6_ENABLED
  #error already defined: TCPIP_IPV6_ENABLED
#endif
/** \brief IPv6 support */
#define TCPIP_IPV6_ENABLED STD_OFF

#ifdef TCPIP_UDP_ENABLED
  #error already defined: TCPIP_UDP_ENABLED
#endif
/** \brief UDP support */
#define TCPIP_UDP_ENABLED STD_ON

#ifdef TCPIP_UDP_BROADCAST_RECEPTION_ENABLED
  #error already defined: TCPIP_UDP_BROADCAST_RECEPTION_ENABLED
#endif
/** \brief UDP limited broadcast and all nodes multicast reception */
#define TCPIP_UDP_BROADCAST_RECEPTION_ENABLED STD_OFF

#ifdef TCPIP_TCP_ENABLED
  #error already defined: TCPIP_TCP_ENABLED
#endif
/** \brief TCP support */
#define TCPIP_TCP_ENABLED STD_ON

#ifdef TCPIP_GETANDRESETMEASUREMENTDATA_API
  #error already defined: TCPIP_GETANDRESETMEASUREMENTDATA_API
#endif
/** \brief Get and Reset Measurement Data API support */
#define TCPIP_GETANDRESETMEASUREMENTDATA_API STD_OFF

#ifdef TCPIP_DHCPGETSTATUS_API
  #error already defined: TCPIP_DHCPGETSTATUS_API
#endif
/** \brief TcpIpDhcpGetStatusApi API support */
#define TCPIP_DHCPGETSTATUS_API STD_OFF

#ifdef TCPIP_ICMPTRANSMITERROR_API
  #error already defined: TCPIP_ICMPTRANSMITERROR_API
#endif
/** \brief TcpIpIcmpTransmitError API support */
#define TCPIP_ICMPTRANSMITERROR_API STD_OFF

#ifdef TCPIP_TCP_KEEP_ALIVE_ENABLED
  #error already defined: TCPIP_TCP_KEEP_ALIVE_ENABLED
#endif
/** \brief TCP keep alive support */
#define TCPIP_TCP_KEEP_ALIVE_ENABLED STD_OFF

#ifdef TCPIP_TCP_OUTOFORDER_RECEPTION_ENABLED
  #error already defined: TCPIP_TCP_OUTOFORDER_RECEPTION_ENABLED
#endif
/** \brief TCP segment reception out-of-order support */
#define TCPIP_TCP_OUTOFORDER_RECEPTION_ENABLED STD_OFF


#ifdef TCPIP_TCP_UNPREDICTABLE_INIT_SEQ_NUM_ENABLED
  #error already defined: TCPIP_TCP_UNPREDICTABLE_INIT_SEQ_NUM_ENABLED
#endif
/** \brief TCP unpredictable initial sequence number support */
#define TCPIP_TCP_UNPREDICTABLE_INIT_SEQ_NUM_ENABLED STD_OFF

#ifdef TCPIP_TCP_SYN_COOKIES_ENABLED
  #error already defined: TCPIP_TCP_SYN_COOKIES_ENABLED
#endif
/** \brief TCP segment reception out-of-order support */
#define TCPIP_TCP_SYN_COOKIES_ENABLED STD_OFF



#ifdef TCPIP_TCP_COPY_WINDOW_CHECK_ENABLED
  #error already defined: TCPIP_TCP_COPY_WINDOW_CHECK_ENABLED
#endif
/** \brief TCP copy window check */
#define TCPIP_TCP_COPY_WINDOW_CHECK_ENABLED STD_ON

#ifdef TCPIP_TCP_TIME_WAIT_RX_RST_IGNORE_ENABLED
  #error already defined: TCPIP_TCP_TIME_WAIT_RX_RST_IGNORE_ENABLED
#endif
/** \brief TCP RST segment ignored reception in state TIME-WAIT */
#define TCPIP_TCP_TIME_WAIT_RX_RST_IGNORE_ENABLED STD_OFF

#ifdef TCPIP_ICMPV4_ENABLED
  #error already defined: TCPIP_ICMPV4_ENABLED
#endif
/** \brief IcmpV4 support */
#define TCPIP_ICMPV4_ENABLED STD_ON

#ifdef TCPIP_ICMPV6_ENABLED
  #error already defined: TCPIP_ICMPV6_ENABLED
#endif
/** \brief IcmpV6 support is mandatory in IPV6 */
#define TCPIP_ICMPV6_ENABLED TCPIP_IPV6_ENABLED

#ifdef TCPIP_IPV4_LINK_LOCAL_ENABLED
  #error already defined: TCPIP_IPV4_LINK_LOCAL_ENABLED
#endif
/** \brief IpV4 link local address assignment support */
#define TCPIP_IPV4_LINK_LOCAL_ENABLED STD_ON

#ifdef TCPIP_IPV6_LINK_LOCAL_ENABLED
  #error already defined: TCPIP_IPV6_LINK_LOCAL_ENABLED
#endif
/** \brief IpV6 link local address assignment support */
#define TCPIP_IPV6_LINK_LOCAL_ENABLED STD_OFF

#ifdef TCPIP_DHCPV4_CLIENT_ENABLED
  #error already defined: TCPIP_DHCPV4_CLIENT_ENABLED
#endif
/** \brief DHCP Client support */
#define TCPIP_DHCPV4_CLIENT_ENABLED STD_ON

#ifdef TCPIP_DHCPV4_SIMPLE_CLIENT_ENABLED
  #error already defined: TCPIP_DHCPV4_SIMPLE_CLIENT_ENABLED
#endif
/** \brief DHCP Simple Client support */
#define TCPIP_DHCPV4_SIMPLE_CLIENT_ENABLED STD_OFF

#ifdef TCPIP_DHCPV6_CLIENT_ENABLED
  #error already defined: TCPIP_DHCPV6_CLIENT_ENABLED
#endif
/** \brief DHCPv6 Client support */
#define TCPIP_DHCPV6_CLIENT_ENABLED STD_OFF

 
/**\brief Duplicate address detection macros */
#ifdef TCPIP_NDP_DAD_CONFIG_ENABLED
  #error already defined: TCPIP_NDP_DAD_CONFIG_ENABLED
#endif
/** \brief Duplicate address detection support */
#define TCPIP_NDP_DAD_CONFIG_ENABLED STD_OFF

#ifdef TCPIP_NDP_DAD_CONFIG_DELAY_ENABLED
  #error already defined: TCPIP_NDP_DAD_CONFIG_DELAY_ENABLED
#endif
/** \brief Stateless auto assignment configuation support */
#define TCPIP_NDP_DAD_CONFIG_DELAY_ENABLED  STD_OFF

#ifdef TCPIP_NDP_DAD_CONFIG_OPTIMISTIC_DAD_ENABLED
  #error already defined: TCPIP_NDP_DAD_CONFIG_OPTIMISTIC_DAD_ENABLED
#endif
/** \brief Optimistic duplicate address detection support */
#define TCPIP_NDP_DAD_CONFIG_OPTIMISTIC_DAD_ENABLED  STD_OFF

#ifdef TCPIP_DHCPV6_DAD_CONFIG_DAD_ENABLED
  #error already defined: TCPIP_DHCPV6_DAD_CONFIG_DAD_ENABLED
#endif
/** \brief DhcpV6 duplicate address detection support */
#define TCPIP_DHCPV6_DAD_CONFIG_DAD_ENABLED  STD_OFF



#ifdef TCPIP_DAD_FCT_ENABLE
  #error already defined: TCPIP_DAD_FCT_ENABLE
#endif
/** \brief Duplicate Address Detection Callout */
#define TCPIP_DAD_FCT_ENABLE STD_OFF

#ifdef TCPIP_NDP_RPD_ENABLED
  #error already defined: TCPIP_NDP_RPD_ENABLED
#endif
/** \brief Router and Prefix Discovery support */
#define TCPIP_NDP_RPD_ENABLED STD_OFF

#ifdef TCPIP_NDP_RND_RTR_SOLICIT_DELAY_ENABLED
  #error already defined: TCPIP_NDP_RND_RTR_SOLICIT_DELAY_ENABLED
#endif
/** \brief Retransmission Solicitation Delay support */
#define TCPIP_NDP_RND_RTR_SOLICIT_DELAY_ENABLED STD_OFF

 
 
#ifdef TCPIP_NDP_DESTINATION_CACHE_ENABLED
  #error already defined: TCPIP_NDP_DESTINATION_CACHE_ENABLED
#endif
/** \brief Destination cache support */
#define TCPIP_NDP_DESTINATION_CACHE_ENABLED STD_OFF

 
#ifdef TCPIP_IP_FRAGMENT_RX_ENABLED
  #error already defined: TCPIP_IP_FRAGMENT_RX_ENABLED
#endif
/** \brief IP RX fragmentation support */
#define TCPIP_IP_FRAGMENT_RX_ENABLED STD_ON

#ifdef TCPIP_IP_FRAGMENT_TX_ENABLED
  #error already defined: TCPIP_IP_FRAGMENT_TX_ENABLED
#endif
/** \brief IP TX fragmentation support */
#define TCPIP_IP_FRAGMENT_TX_ENABLED TCPIP_IP_FRAGMENT_TX_INORDER

#ifdef TCPIP_IP_FRAGMENT_MEMRESERVED
  #error already defined: TCPIP_IP_FRAGMENT_MEMRESERVED
#endif
/** \brief  */
#define TCPIP_IP_FRAGMENT_MEMRESERVED 6000U

#ifdef TCPIP_MAINFUNCTION_PRESCALER_1S
  #error already defined: TCPIP_MAINFUNCTION_PRESCALER_1S
#endif
/** \brief mainfunction prescaler for 1s interval */
#define TCPIP_MAINFUNCTION_PRESCALER_1S 50U

#ifdef TCPIP_MAINFUNCTION_PRESCALER_100MS
  #error already defined: TCPIP_MAINFUNCTION_PRESCALER_100MS
#endif
/** \brief mainfunction prescaler for 100ms interval */
#define TCPIP_MAINFUNCTION_PRESCALER_100MS 5U

#ifdef TCPIP_DHCPV4_FQDN_ENABLED
  #error already defined: TCPIP_DHCPV4_FQDN_ENABLED
#endif
/** \brief DHCP Fully Qualified Domain Name support */
#define TCPIP_DHCPV4_FQDN_ENABLED STD_OFF

#ifdef TCPIP_DHCPV4_OPTIONS_ENABLED
  #error already defined: TCPIP_DHCPV4_OPTIONS_ENABLED
#endif
/** \brief Dhcp options support */
#define TCPIP_DHCPV4_OPTIONS_ENABLED STD_OFF

#ifdef TCPIP_DHCPV6_FQDN_ENABLED
  #error already defined: TCPIP_DHCPV6_FQDN_ENABLED
#endif
/** \brief DHCP Fully Qualified Domain Name support */
#define TCPIP_DHCPV6_FQDN_ENABLED STD_OFF

#ifdef TCPIP_DHCPV6_OPTIONS_ENABLED
  #error already defined: TCPIP_DHCPV6_OPTIONS_ENABLED
#endif
/** \brief DhcpV6 options support */
#define TCPIP_DHCPV6_OPTIONS_ENABLED STD_OFF

#ifdef TCPIP_ICMPV4_RX_FCT_ENABLED
  #error already defined: TCPIP_ICMPV4_RX_FCT_ENABLED
#endif
/** \brief ICMP message handler configuration */
#define TCPIP_ICMPV4_RX_FCT_ENABLED STD_OFF

#ifdef TCPIP_IPV4_ARP_PACKET_FILTER_ENABLE
  #error already defined: TCPIP_IPV4_ARP_PACKET_FILTER_ENABLE
#endif
/** \brief IPV4 ARP packet filter */
#define TCPIP_IPV4_ARP_PACKET_FILTER_ENABLE STD_OFF

#ifdef TCPIP_TCP_OPTION_FILTER_ENABLE
  #error already defined: TCPIP_TCP_OPTION_FILTER_ENABLE
#endif
/** \brief TCP option filtering */
#define TCPIP_TCP_OPTION_FILTER_ENABLE STD_OFF

#ifdef TCPIP_IPV6_EXTENSIONHDR_FILTER_ENABLE
  #error already defined: TCPIP_IPV6_EXTENSIONHDR_FILTER_ENABLE
#endif
/** \brief IPV6 extension header filtering */
#define TCPIP_IPV6_EXTENSIONHDR_FILTER_ENABLE STD_OFF

#ifdef TCPIP_PHYSADDR_CHANGE_FCT_ENABLE
  #error already defined: TCPIP_PHYSADDR_CHANGE_FCT_ENABLE
#endif
/** \brief Physical address change handler configuration */
#define TCPIP_PHYSADDR_CHANGE_FCT_ENABLE STD_OFF

#ifdef TCPIP_UDP_MAXIMUM_SOCKET_INSTANCES
  #error already defined: TCPIP_UDP_MAXIMUM_SOCKET_INSTANCES
#endif
/** \brief maximum number overlapping socket instances possible during demultiplexing */
#define TCPIP_UDP_MAXIMUM_SOCKET_INSTANCES 2U

#ifdef TCPIP_NVM_STORING_ENABLED
  #error already defined: TCPIP_NVM_STORING_ENABLED
#endif
/** \brief enable/disable NvM support for storing IP addresses */
#define TCPIP_NVM_STORING_ENABLED STD_OFF




#ifdef TCPIP_SOCKET_NUM_UDP_IPV4
  #error already defined: TCPIP_SOCKET_NUM_UDP_IPV4
#endif
/** \brief maximum number of IpV4 Udp sockets */
#define TCPIP_SOCKET_NUM_UDP_IPV4 7U

#ifdef TCPIP_SOCKET_NUM_TCP_IPV4
  #error already defined: TCPIP_SOCKET_NUM_TCP_IPV4
#endif
/** \brief maximum number of IpV4 Tcp sockets */
#define TCPIP_SOCKET_NUM_TCP_IPV4 6U

#ifdef TCPIP_SOCKET_NUM_UDP_IPV6
  #error already defined: TCPIP_SOCKET_NUM_UDP_IPV6
#endif
/** \brief maximum number of IpV6 Udp sockets */
#define TCPIP_SOCKET_NUM_UDP_IPV6 0U

#ifdef TCPIP_SOCKET_NUM_TCP_IPV6
  #error already defined: TCPIP_SOCKET_NUM_TCP_IPV6
#endif
/** \brief maximum number of IpV6 Tcp sockets */
#define TCPIP_SOCKET_NUM_TCP_IPV6 0U

#ifdef TCPIP_ICMPV6_RX_FCT_ENABLED
  #error already defined: TCPIP_ICMPV6_RX_FCT_ENABLED
#endif
/** \brief ICMPV6 message handler configuration */
#define TCPIP_ICMPV6_RX_FCT_ENABLED STD_OFF

#ifdef TCPIP_SOCKETPAGE_MASK
  #error already defined: TCPIP_SOCKETPAGE_MASK
#endif
/** \brief socket page mask adjusted to the enabled configurations */
#define TCPIP_SOCKETPAGE_MASK 5U

#ifdef TCPIP_SOCKETPAGE_NUM_VALID_CONFIGS
  #error already defined: TCPIP_SOCKETPAGE_NUM_VALID_CONFIGS
#endif
/** \brief number of configured socket pages */
#define TCPIP_SOCKETPAGE_NUM_VALID_CONFIGS 2U

#ifdef TCPIP_SOCKETPAGE_CONFIG_INDEX
  #error already defined: TCPIP_SOCKETPAGE_CONFIG_INDEX
#endif
/** \brief socket page index adjusted to the enabled configurations */
#define TCPIP_SOCKETPAGE_CONFIG_INDEX 148U

/* ----- RX policy check ingress handler ----- */
#ifdef TCPIP_RX_POLICY_CHECK_INGRESS_FCT_ENABLED
  #error already defined: TCPIP_RX_POLICY_CHECK_INGRESS_FCT_ENABLED
#endif
/** \brief RX policy check ingress handler */
#define TCPIP_RX_POLICY_CHECK_INGRESS_FCT_ENABLED STD_OFF

/* ----- RX policy check routing handler ----- */
#ifdef TCPIP_RX_POLICY_CHECK_ROUTING_FCT_ENABLED
  #error already defined: TCPIP_RX_POLICY_CHECK_ROUTING_FCT_ENABLED
#endif
/** \brief RX policy check routing handler */
#define TCPIP_RX_POLICY_CHECK_ROUTING_FCT_ENABLED STD_OFF

/* ----- RX packet post process handler ----- */
#ifdef TCPIP_RX_PACKET_POSTPROCESS_FCT_ENABLED
  #error already defined: TCPIP_RX_PACKET_POSTPROCESS_FCT_ENABLED
#endif
/** \brief RX packet post process handler */
#define TCPIP_RX_PACKET_POSTPROCESS_FCT_ENABLED STD_OFF

/* ----- RX packet drop handler ----- */
#ifdef TCPIP_RX_PACKET_DROP_FCT_ENABLED
  #error already defined: TCPIP_RX_PACKET_DROP_FCT_ENABLED
#endif
/** \brief RX packet drop handler */
#define TCPIP_RX_PACKET_DROP_FCT_ENABLED STD_OFF

/* ----- Memory management ----- */

#ifdef TCPIP_MEMORY_NUM_TOTAL_BLOCKS
  #error already defined: TCPIP_MEMORY_NUM_TOTAL_BLOCKS
#endif
/** \brief Total Number of configured memory blocks */
#define TCPIP_MEMORY_NUM_TOTAL_BLOCKS 1U

#ifdef TCPIP_MEMORY_TOTAL_SIZE
  #error already defined: TCPIP_MEMORY_TOTAL_SIZE
#endif
/** \brief Total size of reserved memory */
#define TCPIP_MEMORY_TOTAL_SIZE 32U





#ifdef TCPIP_ARP_DAD_ENABLED
  #error already defined: TCPIP_ARP_DAD_ENABLED
#endif
/** \brief ARP DAD enabled */
#define TCPIP_ARP_DAD_ENABLED STD_ON

#ifdef TCPIP_DHCPV4_CONFIG_DAD_ENABLED
  #error already defined: TCPIP_DHCPV4_CONFIG_DAD_ENABLED
#endif
/** \brief DhcpV4 DAD enabled */
#define TCPIP_DHCPV4_CONFIG_DAD_ENABLED STD_OFF


#ifdef TCPIP_ARP_TABLESIZE_MAX
  #error already defined: TCPIP_ARP_TABLESIZE_MAX
#endif
/** \brief Size of ARP table per ethernet controller */
#define TCPIP_ARP_TABLESIZE_MAX 5U


#ifdef TCPIP_NUM_ARP_DAD_ENTRIES
  #error already defined: TCPIP_NUM_ARP_DAD_ENTRIES
#endif
/** \brief Maximum number of ARP DAD entries */
#define TCPIP_NUM_ARP_DAD_ENTRIES 5U





#ifdef TCPIP_NUM_LOCALADDRENTRIES
  #error already defined: TCPIP_NUM_LOCALADDRENTRIES
#endif
/** \brief Maximum number of local addrIds supported */
#define TCPIP_NUM_LOCALADDRENTRIES \
  (TCPIP_NUM_IPV4_LOCALADDRENTRIES + TCPIP_NUM_IPV6_LOCALADDRENTRIES)

#ifdef TCPIP_NUM_IPV4_LOCALADDRENTRIES
  #error already defined: TCPIP_NUM_IPV4_LOCALADDRENTRIES
#endif
/** \brief Maximum number of IPv4 local addrIds supported */
#define TCPIP_NUM_IPV4_LOCALADDRENTRIES 10U

#ifdef TCPIP_NUM_IPV6_LOCALADDRENTRIES
  #error already defined: TCPIP_NUM_IPV6_LOCALADDRENTRIES
#endif
/** \brief Maximum number of IPv6 local addrIds supported */
#define TCPIP_NUM_IPV6_LOCALADDRENTRIES 0U

#ifdef TCPIP_NUM_ETHIFCTRL
  #error already defined: TCPIP_NUM_ETHIFCTRL
#endif
/** \brief Maximum number of EthIfCtrl supported */
#define TCPIP_NUM_ETHIFCTRL 4U

#ifdef TCPIP_NUM_DHCPV4_CLIENTS
  #error already defined: TCPIP_NUM_DHCPV4_CLIENTS
#endif
/** \brief Maximum number of DHCP clients supported */
#define TCPIP_NUM_DHCPV4_CLIENTS 5U

#ifdef TCPIP_DHCPV4_DOMAINNAME_SIZE
  #error already defined: TCPIP_DHCPV4_DOMAINNAME_SIZE
#endif
/** \brief Maximum size of the domain Name */
#define TCPIP_DHCPV4_DOMAINNAME_SIZE 5U


#ifdef TCPIP_NUM_IPV4_LINK_LOCAL_ASSIGN
  #error already defined: TCPIP_NUM_IPV4_LINK_LOCAL_ASSIGN
#endif
/** \brief Maximum number of link local address assignments supported */
#define TCPIP_NUM_IPV4_LINK_LOCAL_ASSIGN 5U

#ifdef TCPIP_IPV4_LINK_LOCAL_NETMASK
  #error already defined: TCPIP_IPV4_LINK_LOCAL_NETMASK
#endif
/** \brief netmask of link local address space */
#define TCPIP_IPV4_LINK_LOCAL_NETMASK 65535U



#ifdef TCPIP_CFG_SIGNATURE
  #error already defined: TCPIP_CFG_SIGNATURE
#endif
/** \brief Compile time verification value */
#define TCPIP_CFG_SIGNATURE 2689342550U

#ifdef TCPIP_PUBLIC_INFO_SIGNATURE
  #error already defined: TCPIP_PUBLIC_INFO_SIGNATURE
#endif
/** \brief PublicInfoSignature */
#define TCPIP_PUBLIC_INFO_SIGNATURE 3422504959U

#ifdef TCPIP_PBCFGM_SUPPORT_ENABLED
  #error already defined: TCPIP_PBCFGM_SUPPORT_ENABLED
#endif
/** \brief enable/disable relocateable postbuild config */
#define TCPIP_PBCFGM_SUPPORT_ENABLED STD_OFF

#ifdef TCPIP_RELOCATABLE_CFG_ENABLE
  #error already defined: TCPIP_RELOCATABLE_CFG_ENABLE
#endif
/** \brief enable/disable relocateable config */
#define TCPIP_RELOCATABLE_CFG_ENABLE STD_ON

#ifdef TCPIP_MAINFUNCTIONTX_ENABLED
  #error already defined: TCPIP_MAINFUNCTIONTX_ENABLED
#endif
/** \brief enable/disable TcpIp_MainFunctionTx */
#define TCPIP_MAINFUNCTIONTX_ENABLED STD_OFF

/* ----- IpSec ----- */
#ifdef TCPIP_FIREWALL
  #error already defined: TCPIP_FIREWALL
#endif
/** \brief Enables the availability to define bypass/discard policies */
#define TCPIP_FIREWALL   (STD_ON + 1U)

#ifdef TCPIP_STATIC_IPSEC
  #error already defined: TCPIP_STATIC_IPSEC
#endif
/** \brief Enables the availability to define bypass/secured/discard policies and manual security associations */
#define TCPIP_STATIC_IPSEC   ((TCPIP_FIREWALL) + 1U)

#ifdef TCPIP_IKEV2
  #error already defined: TCPIP_IKEV2
#endif
/** \brief Enables the availability to define bypass/secured/discard policies and manual/dynamic security associations */
#define TCPIP_IKEV2   ((TCPIP_STATIC_IPSEC) + 1U)

#ifdef TCPIP_SECURITY_MODE
  #error already defined: TCPIP_SECURITY_MODE
#endif
/** \brief TcpIp security mode */
#define TCPIP_SECURITY_MODE STD_OFF


#ifdef TCPIP_IPSEC_GET_STATUS_API_ENABLED
  #error already defined: TCPIP_IPSEC_GET_STATUS_API_ENABLED
#endif
/** \brief enable/disable IpSec */
#define TCPIP_IPSEC_GET_STATUS_API_ENABLED STD_OFF



#ifdef TCPIP_REMOTE_MAC_FILTERING_ENABLED
  #error already defined: TCPIP_REMOTE_MAC_FILTERING_ENABLED
#endif
/** \brief enable/disable MAC filtering */
#define TCPIP_REMOTE_MAC_FILTERING_ENABLED STD_OFF





#ifdef TCPIP_IPSEC_GMAC_ENABLED
  #error already defined: TCPIP_IPSEC_GMAC_ENABLED
#endif
/** \brief Indicates if GMAC is used for authentication in one or more configuration */
#define TCPIP_IPSEC_GMAC_ENABLED STD_OFF

#ifdef TCPIP_IPSEC_ERROR_REPORT_FCT_ENABLED
  #error already defined: TCPIP_IPSEC_ERROR_REPORT_FCT_ENABLED
#endif
/** \brief IpSec error handler configuration */
#define TCPIP_IPSEC_ERROR_REPORT_FCT_ENABLED STD_OFF

#ifdef TCPIP_IPV6_TRAFFIC_CLASS_FILTER_ENABLED
  #error already defined: TCPIP_IPV6_TRAFFIC_CLASS_FILTER_ENABLED
#endif
/** \brief Traffic class value filtering */
#define TCPIP_IPV6_TRAFFIC_CLASS_FILTER_ENABLED STD_OFF

#ifdef TCPIP_TCP_CRYPTO_ENABLED
  #error already defined: TCPIP_TCP_CRYPTO_ENABLED
#endif
/** \brief enable/disable Crypto for TCP syn cookies or unpredictable sequence numbers */
#define TCPIP_TCP_CRYPTO_ENABLED STD_OFF


#ifdef TCPIP_IPV6_FLOW_LABEL_FILTER_ENABLED
  #error already defined: TCPIP_IPV6_FLOW_LABEL_FILTER_ENABLED
#endif
/** \brief Flow label value filtering */
#define TCPIP_IPV6_FLOW_LABEL_FILTER_ENABLED STD_OFF

#ifdef TCPIP_IPSECDB_GETANDRESETMEASUREMENTDATA_ENABLE
  #error already defined: TCPIP_IPSECDB_GETANDRESETMEASUREMENTDATA_ENABLE
#endif
/** \brief Indicates if counters for security policies are used */
#define TCPIP_IPSECDB_GETANDRESETMEASUREMENTDATA_ENABLE STD_OFF



#ifdef TCPIP_IKEV2_FRAGMENTATION_ENABLED
  #error already defined: TCPIP_IKEV2_FRAGMENTATION_ENABLED
#endif
/** \brief Indicates whether IKEv2 message fragmentation support is activated */
#define TCPIP_IKEV2_FRAGMENTATION_ENABLED STD_OFF





#ifdef TCPIP_SECURITYEVENT_REPORTING_ENABLED
  #error already defined: TCPIP_SECURITYEVENT_REPORTING_ENABLED
#endif
/** \brief Indicates whether Security event reporting is activated */
#define TCPIP_SECURITYEVENT_REPORTING_ENABLED STD_OFF

/* ----- Tls ----- */
#ifdef TCPIP_TLS_ENABLED
  #error already defined: TCPIP_TLS_ENABLED
#endif
/** \brief enable/disable Tls interface */
#define TCPIP_TLS_ENABLED STD_OFF

/* ----- defensive programming macros ----- */



/*------------------[Defensive programming]---------------------------------*/

#if (defined TCPIP_DEFENSIVE_PROGRAMMING_ENABLED)
#error TCPIP_DEFENSIVE_PROGRAMMING_ENABLED is already defined
#endif
/** \brief Defensive programming usage
 **
 ** En- or disables the usage of the defensive programming */
#define TCPIP_DEFENSIVE_PROGRAMMING_ENABLED   STD_OFF

#if (defined TCPIP_PRECONDITION_ASSERT_ENABLED)
#error TCPIP_PRECONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Precondition assertion usage
 **
 ** En- or disables the usage of precondition assertion checks */
#define TCPIP_PRECONDITION_ASSERT_ENABLED     STD_OFF

#if (defined TCPIP_POSTCONDITION_ASSERT_ENABLED)
#error TCPIP_POSTCONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Postcondition assertion usage
 **
 ** En- or disables the usage of postcondition assertion checks */
#define TCPIP_POSTCONDITION_ASSERT_ENABLED    STD_OFF

#if (defined TCPIP_UNREACHABLE_CODE_ASSERT_ENABLED)
#error TCPIP_UNREACHABLE_CODE_ASSERT_ENABLED is already defined
#endif
/** \brief Unreachable code assertion usage
 **
 ** En- or disables the usage of unreachable code assertion checks */
#define TCPIP_UNREACHABLE_CODE_ASSERT_ENABLED STD_OFF

#if (defined TCPIP_INVARIANT_ASSERT_ENABLED)
#error TCPIP_INVARIANT_ASSERT_ENABLED is already defined
#endif
/** \brief Invariant assertion usage
 **
 ** En- or disables the usage of invariant assertion checks */
#define TCPIP_INVARIANT_ASSERT_ENABLED        STD_OFF

#if (defined TCPIP_STATIC_ASSERT_ENABLED)
#error TCPIP_STATIC_ASSERT_ENABLED is already defined
#endif
/** \brief Static assertion usage
 **
 ** En- or disables the usage of static assertion checks */
#define TCPIP_STATIC_ASSERT_ENABLED           STD_OFF


/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
#endif   /* TCPIP_CFG_H */

