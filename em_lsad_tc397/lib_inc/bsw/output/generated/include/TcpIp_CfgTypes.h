


/**
 * \file
 *
 * \brief AUTOSAR TcpIp
 *
 * This file contains the implementation of the AUTOSAR
 * module TcpIp.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef TCPIP_CFGTYPES_H
#define TCPIP_CFGTYPES_H



/*==================[inclusions]=============================================*/

#include <Platform_Types.h>
#include <TSAutosar.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS TCPIP_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/

typedef VAR( uint8, TYPEDEF ) TcpIp_LocalAddrIdType;

typedef VAR( uint16, TYPEDEF ) TcpIp_DomainType;

typedef struct /* TcpIp_AddrInetType */ {
    VAR( uint32, TYPEDEF ) addr[1]; /* IPv4 address in network byte order. */
} TcpIp_AddrInetType;

typedef struct /* TcpIp_AddrInet6Type */ {
    VAR( uint32, TYPEDEF ) addr[4]; /* IPv6 address in network byte order . */
} TcpIp_AddrInet6Type;

typedef struct /* TcpIp_MACAddrType */ {
    VAR( uint8, TYPEDEF ) physAddr[6]; /* MAC address. */
} TcpIp_MACAddrType;

typedef struct /* TcpIp_IpFragConfigType */ {
    VAR( uint32, TYPEDEF ) reassTimeout; /* Reassembly timeout for IP datagram reassembly. */
    VAR( uint32, TYPEDEF ) reassBufferSize; /* Size of each reassembly buffer. */
    VAR( uint16, TYPEDEF ) reassBufferCount; /* Number of concurrent reassembly reception buffers. */
    VAR( uint16, TYPEDEF ) txFragmentBufferSize; /* maximum size of a datagram to be transmitted fragmented. */
    VAR( uint16, TYPEDEF ) txFragmentBufferCount; /* Number of concurrent transmit fragmentation buffers for in-order Datagram (UDP/ICMP) splitting.. */
    VAR( uint16, TYPEDEF ) txFragmentSegmentCount; /* Maximum number of Ethernet buffers (=fragments per datagram) for in-order Datagram (UDP/ICMP) splitting. */
} TcpIp_IpFragConfigType;

typedef struct /* TcpIp_UdpConfigType */ {
    VAR( uint8, TYPEDEF ) ttl; /* Time to live used for Udp transmission. */
    VAR( uint8, TYPEDEF ) mayFragment; /* Outgoing Datagrams may be (re-)fragmented along the path. */
} TcpIp_UdpConfigType;

typedef struct /* TcpIp_memoryConfigType */ {
    VAR( uint32, TYPEDEF ) memoryPoolOffset; /* Position of the first memory block in the memory array. */
    VAR( uint16, TYPEDEF ) memoryBlockSize; /* Size of one block in the memory pool. */
    VAR( uint16, TYPEDEF ) numOfBlocks; /* Number of memory blocks in this memory pool. */
    VAR( uint16, TYPEDEF ) memoryBlockDescriptorOffset; /* Position of the first memory block in the descriptor array. */
} TcpIp_memoryConfigType;

typedef struct /* TcpIp_TcpConfigType */ {
    VAR( uint32, TYPEDEF ) msl; /* Maximum segment lifetime */
    VAR( uint32, TYPEDEF ) finWait2Timeout; /* Timeout to receive a FIN from the remote node */
    VAR( uint32, TYPEDEF ) reTxTimeout; /* Timeout before an unacknowledged TCP segment is sent again. */
    VAR( uint32, TYPEDEF ) issPeriod; /* ISN is incremented by this value every mainfunction. */
    VAR( uint32, TYPEDEF ) dupAckTxTimeoutSeqNum; /* Timeout rate-limiting the duplicate Acknowledgement for out-of-window sequence number. */
    VAR( uint32, TYPEDEF ) dupAckTxTimeoutAckNum; /* Timeout rate-limiting the duplicate Acknowledgement for out-of-window acknowledgement number. */
    VAR( uint32, TYPEDEF ) synReceivedTimeout; /* Maximum time waiting in SYN_RECEIVED for a confirming connection request acknowledgment after having both received and sent a connection request */
    VAR( uint16, TYPEDEF ) delayedAckTimeout; /* Maximal time an acknowledgment is delayed for transmission */
    VAR( uint16, TYPEDEF ) maxRxWindow; /* Default value of maximum receive window in bytes. */
    VAR( uint8, TYPEDEF ) maxReTx; /* Maximum number of times that a TCP segment is retransmitted. */
    VAR( uint8, TYPEDEF ) maxSynReTx; /* Maximum number of times that a SYN is retransmitted. */
    VAR( uint8, TYPEDEF ) ttl; /* Time to live used for Tcp transmission. */
    VAR( uint8, TYPEDEF ) nagleDefault; /* Enables or disables support of Nagle's algorithm. */
} TcpIp_TcpConfigType;

typedef struct /* TcpIp_DhcpV4ConfigType */ {
    VAR( uint8, TYPEDEF ) initDelay; /* Delay of the DHCPDISCOVER message transmission */
    VAR( uint8, TYPEDEF ) addrDefendMechanism; /* >Indicates the DhcpV4 Address Defend Mechanism. */
    VAR( uint8, TYPEDEF ) optionNum; /* Number of configured Dhcp options. */
} TcpIp_DhcpV4ConfigType;

typedef struct /* TcpIp_IpV4LinkLocalConfigType */ {
    VAR( uint16, TYPEDEF ) autoIpInitTimeout; /* AutoIp inital timeout. */
    VAR( uint8, TYPEDEF ) addrDefendMechanism; /* >Indicates the AutoIp Address Defend Mechanism. */
} TcpIp_IpV4LinkLocalConfigType;

typedef struct /* TcpIp_assignmConfigType */ {
    VAR( uint16, TYPEDEF ) dadIpV4Idx; /* The index in the ARP DAD cache. */
    VAR( uint8, TYPEDEF ) assignIdx; /* Assignment type variable array index. */
    VAR( uint8, TYPEDEF ) priority_autoAssign; /* Priority of assignment (bits 1-3) and autoAssignment (bit 0) information. */
} TcpIp_assignmConfigType;

typedef struct /* TcpIp_localAddrIpV6StaticConfigType */ {
    VAR( uint32, TYPEDEF ) srcIpStatic[4]; /* Static source IP address for this local address configuration. */
    VAR( uint32, TYPEDEF ) routerIpStatic[4]; /* Static router IP address for this local address configuration. */
    VAR( uint32, TYPEDEF ) netMaskStatic[4]; /* Static network mask including subnet. */
} TcpIp_localAddrIpV6StaticConfigType;

typedef struct /* TcpIp_IpV4ConfigType */ {
    VAR( uint32, TYPEDEF ) arpRequestTimeout; /* Arp Request timeout in units of mainfunction ticks. */
    VAR( uint32, TYPEDEF ) arpTimeout; /* Arp entry timeout in units of seconds. */
    VAR( uint8, TYPEDEF ) numGratuitousARP; /* Number of gratuitous ARP messages sent after IP address assignment. */
    VAR( uint8, TYPEDEF ) icmpTtl; /* Ttl used for ICMP transmission. */
    VAR( uint8, TYPEDEF ) icmpEchoReplyEnable; /* Enable/Disable echo reply transmission. */
    VAR( uint8, TYPEDEF ) addrDefendMechanism; /* >Indicates the IpV4 Static Address Defend Mechanism. */
} TcpIp_IpV4ConfigType;

typedef struct /* TcpIp_IpV6ConfigType */ {
    VAR( uint8, TYPEDEF ) icmpV6HopLimit; /* Default Hop-Limit value of outgoing ICMPv6 packets. */
    VAR( uint8, TYPEDEF ) icmpV6EchoReplyEnable; /* Enable/Disable echo reply transmission. */
    VAR( uint8, TYPEDEF ) icmpV6EchoReplyToMulticastEnabled; /* Enable/Disable echo reply to multicast messages. */
    VAR( uint8, TYPEDEF ) icmpV6MsgDestinationUnreachableEnabled; /* Dis/Enables transmission of Destination Unreachable Messages. */
    VAR( uint8, TYPEDEF ) icmpV6MsgParameterProblemEnabled; /* Parameter problem message will be sent if a received packet has been dropped. */
} TcpIp_IpV6ConfigType;

typedef struct /* TcpIp_DhcpV6ConfigType */ {
    VAR( uint8, TYPEDEF ) optionNum; /* Number of configured DhcpV6 options. */
} TcpIp_DhcpV6ConfigType;

typedef struct /* TcpIp_NdpConfigType */ {
    VAR( uint16, TYPEDEF ) ndpDefaultReachableTime; /* Configuration of the ReachableTime (s). */
    VAR( uint16, TYPEDEF ) ndpDefaultRetransTimer; /* Configures the default value (s) for the RetransTimer */
    VAR( uint16, TYPEDEF ) ndpDelayFirstProbeTime; /* Delay before sending the first NUD probe in (s). */
    VAR( uint8, TYPEDEF ) ndpNumMulticastSolicitations; /* Maximum number of multicast solicitations that will be sent when performing address resolution. */
    VAR( uint8, TYPEDEF ) ndpNumUnicastSolicitations; /* Maximum number of unicast solicitations that will be sent when performing Neighbor Unreachability Detection. */
} TcpIp_NdpConfigType;

typedef struct /* TcpIp_DhcpOptionConfigType */ {
    VAR( uint16, TYPEDEF ) optionCode; /* option code according to RFC 3315 */
    VAR( uint16, TYPEDEF ) optionMaxLength; /* maximum length in bytes for this option. */
    VAR( uint32, TYPEDEF ) optionDataOffset; /* DHCP option offset */
    VAR( boolean, TYPEDEF ) optionTransmit; /* Defines if options is transmitted or just saved */
} TcpIp_DhcpOptionConfigType;

/** 
This type contains IpSec configuration related to a specific cryptographic key used by the Csm module.
 */
typedef struct /* TcpIp_IpSec_KeyGenerationConfigType */ {
    VAR( uint32, TYPEDEF ) keyId; /* Csm ID of they key */
    VAR( uint32, TYPEDEF ) elementId; /* Element ID of this key */
    VAR( uint8, TYPEDEF ) keyLength; /* Length of the key */
} TcpIp_IpSec_KeyGenerationConfigType;

/** 
This type contains configuration related to a specific transform used by IkeV2.
 */
typedef struct /* TcpIp_IpSec_TransformType */ {
    VAR( uint16, TYPEDEF ) attributeType; /* Additional attribute type for this algorithm */
    VAR( uint16, TYPEDEF ) attributeValue; /* Additional attribute value for this algorithm */
    VAR( uint16, TYPEDEF ) transformId; /* Indicates the transform id of the algorithm */
    VAR( uint8, TYPEDEF ) transformType; /* Indicates the type of algorithm */
} TcpIp_IpSec_TransformType;

/** 
This type contains configuration related to a specific rule of an IpSec policy.
 */
typedef struct /* TcpIp_IpSecRuleConfigType */ {
    VAR( uint16, TYPEDEF ) startPort; /* start of the port range for which the policy is valid */
    VAR( uint16, TYPEDEF ) endPort; /* end of the port range for which the policy is valid */
    VAR( uint8, TYPEDEF ) upperLayerProtocol; /* Indicates the upper layer protocol ICMP/UDP/TCP/ANY */
} TcpIp_IpSecRuleConfigType;

typedef struct /* TcpIp_SockAddrInetType */ {
    VAR( TcpIp_DomainType, TYPEDEF ) domain; /* This is the code for the address format of this address. */
    VAR( uint16, TYPEDEF ) port; /* port number. */
    VAR( uint32, TYPEDEF ) addr[1]; /* IPv4 address in network byte order. */
} TcpIp_SockAddrInetType;

typedef struct /* TcpIp_SockAddrInet6Type */ {
    VAR( TcpIp_DomainType, TYPEDEF ) domain; /* This is the code for the address format of this address. */
    VAR( uint16, TYPEDEF ) port; /* port number. */
    VAR( uint32, TYPEDEF ) addr[4]; /* IPv6 address in network byte order . */
} TcpIp_SockAddrInet6Type;

typedef struct /* TcpIp_localAddrConfigType */ {
    VAR( TcpIp_LocalAddrIdType, TYPEDEF ) intLocalAddrId; /* Reference to array of local address configurations. */
    VAR( TcpIp_assignmConfigType, TYPEDEF ) assignmByMethod[8]; /* Assignment configuration for this localAddr. */
    VAR( uint8, TYPEDEF ) assignmByPriority[4]; /* Assignment types sorted by assignment priority. */
    VAR( uint8, TYPEDEF ) numAssignm; /* Number of assignments configured for this localAddr. */
    VAR( uint8, TYPEDEF ) ctrlIdx; /* Reference to controller config structure this local address belongs to. */
    VAR( uint8, TYPEDEF ) addrType; /* type of address (unicast, multicast). */
} TcpIp_localAddrConfigType;

typedef struct /* TcpIp_localAddrIpV6ConfigType */ {
    VAR( uint8, TYPEDEF ) staticAddrId; /* Index pointing to static configured ip address and netmask */
    VAR( TcpIp_LocalAddrIdType, TYPEDEF ) solMultilocalAddrId; /* Solcit Multicast Local address identifier (TcpIpAddrId). */
} TcpIp_localAddrIpV6ConfigType;

typedef struct /* TcpIp_DhcpAddrIpV6ConfigType */ {
    VAR( TcpIp_LocalAddrIdType, TYPEDEF ) solMultilocalAddrId; /* Solcit Multicast Local address identifier (TcpIpAddrId). */
} TcpIp_DhcpAddrIpV6ConfigType;

typedef struct /* TcpIp_NdpRpdAddrIpV6ConfigType */ {
    VAR( TcpIp_LocalAddrIdType, TYPEDEF ) solMultilocalAddrId; /* Solcit Multicast Local address identifier (TcpIpAddrId). */
} TcpIp_NdpRpdAddrIpV6ConfigType;

typedef struct /* TcpIp_ctrlIpV4ConfigType */ {
    VAR( uint32, TYPEDEF ) defaultGWIpStatic; /* Static default Gateway IP address. */
    VAR( uint32, TYPEDEF ) netMaskStatic; /* Static network mask including subnet. */
    VAR( TcpIp_LocalAddrIdType, TYPEDEF ) intLocalAddrIdFirst; /* Index of first local address (internal table) which shall be searched for this controller. */
    VAR( TcpIp_LocalAddrIdType, TYPEDEF ) intLocalAddrNum; /* Number of local addresses (internal table) which shall be searched for this controller. */
    VAR( TcpIp_LocalAddrIdType, TYPEDEF ) localAddrIdTx; /* Unicast localAddrId of this controller to use for transmission. */
    VAR( TcpIp_LocalAddrIdType, TYPEDEF ) localAddrLimdBroad; /* Limited Broadcast localAddrId of this controller used for binding. */
} TcpIp_ctrlIpV4ConfigType;

typedef struct /* TcpIp_ctrlIpV6ConfigType */ {
    VAR( TcpIp_LocalAddrIdType, TYPEDEF ) intLocalAddrIdFirst; /* Index of first local address (internal table) which shall be searched for this controller. */
    VAR( TcpIp_LocalAddrIdType, TYPEDEF ) intLocalAddrNum; /* Number of local addresses (internal table) which shall be searched for this controller. */
    VAR( TcpIp_LocalAddrIdType, TYPEDEF ) localAddrLinkLocal; /* Link Local localAddrId of this controller */
} TcpIp_ctrlIpV6ConfigType;

/** 
This type contains the specification of an IpSec proposal.
 */
typedef struct /* TcpIp_IpSec_TransformProposalType */ {
    TS_REF2CFG( TcpIp_IpSec_TransformType )  transformPtr; /* Reference to the transform */
    VAR( uint8, TYPEDEF ) transformSize; /* Size of all transforms */
    VAR( uint8, TYPEDEF ) numOfTransforms; /* Defines the number of transforms */
} TcpIp_IpSec_TransformProposalType;

typedef struct /* TcpIp_ctrlConfigType */ {
    VAR( TcpIp_ctrlIpV4ConfigType, TYPEDEF ) ctrlIpV4; /* IpV4 controller information */
    VAR( uint16, TYPEDEF ) mtu; /* Maximum transmission unit of this ethernet controller */
    VAR( uint8, TYPEDEF ) defaultVlanPrio; /* default vlan priority to use for this controller */
    VAR( TcpIp_LocalAddrIdType, TYPEDEF ) localAddrIdAny; /* Any-IP localAddrId of this controller used for binding. */
    VAR( TcpIp_LocalAddrIdType, TYPEDEF ) intLocalAddrIdFirst; /* Index of first local address (internal table) which shall be searched for this controller. */
    VAR( TcpIp_LocalAddrIdType, TYPEDEF ) intLocalAddrNum; /* Number of local addresses (internal table) which shall be searched for this controller. */
    VAR( uint8, TYPEDEF ) ethIfCtrlIdx; /* internal to external controller index mapping */
    VAR( uint8, TYPEDEF ) enableOffloadChecksum; /* Hardware calculation of the protocol checksums. */
} TcpIp_ctrlConfigType;

/** 
This type contains the specification of an IpSec SA.
 */
typedef struct /* TcpIp_IpSec_ProposalsConfigType */ {
    TS_REF2CFG( TcpIp_IpSec_TransformProposalType )  transformProposalListRef; /* Reference to the proposal */
    VAR( uint8, TYPEDEF ) numOfPropsals; /* Size of the SPI */
    VAR( uint8, TYPEDEF ) totalProposalSize; /* Size of all proposals */
    VAR( uint8, TYPEDEF ) spiSize; /* Size of the SPI */
    VAR( uint8, TYPEDEF ) protocolId; /* Defines the used security protocol */
} TcpIp_IpSec_ProposalsConfigType;

typedef struct /* TcpIp_ConfigType */ {
    VAR( uint32, TYPEDEF ) PlatformSignature; /* Used to validate the platform. */
    VAR( uint32, TYPEDEF ) LcfgSignature; /* Used to validate the post build configuration against the link time configuration. */
    VAR( uint32, TYPEDEF ) CfgSignature; /* Used to validate the post build configuration against the precompile time configuration. */
    VAR( uint32, TYPEDEF ) PublicInfoSignature; /* Used to validate Public information. */
    TS_REF2CFG( TcpIp_localAddrConfigType )  localAddrRef; /* Reference to list of local address configurations. */
    TS_REF2CFG( uint8 )  intIpLocalAddrRef; /* Reference to internal list of local address configurations. */
    TS_REF2CFG( uint32 )  intIpV4LocalAddrRef; /* Reference to static IpV4 addresses. */
    TS_REF2CFG( TcpIp_localAddrIpV6ConfigType )  intIpV6LocalAddrRef; /* Reference to internal IpV6 list of local address configurations. */
    TS_REF2CFG( TcpIp_localAddrIpV6StaticConfigType )  intIPv6StaticAddrRef; /* Reference to internal IpV6 list of local address configurations. */
    TS_REF2CFG( TcpIp_DhcpAddrIpV6ConfigType )  intIpV6DhcpAddrRef; /* Reference to internal list of multicast and LinkLocal address index */
    TS_REF2CFG( TcpIp_NdpRpdAddrIpV6ConfigType )  intIpV6NdpRpdAddrRef; /* Reference to internal list of multicast address index */
    TS_REF2CFG( TcpIp_ctrlConfigType )  ctrlRef; /* Reference to list of controller configurations. */
    TS_REF2CFG( uint8 )  ctrlMappingRef; /* Used to map internal index to external index. */
    TS_REF2CFG( uint8 )  arpDadCtrlMappingRef; /* Used to map Arp Dad index to internal ctrl index. */
    TS_REF2CFG( TcpIp_DhcpOptionConfigType )  dhcpOptionRef; /* Reference to internal list of Dhcp options */
    TS_REF2CFG( TcpIp_DhcpOptionConfigType )  dhcpV6OptionRef; /* Reference to internal list of DhcpV6 options */
    TS_REF2CFG( TcpIp_LocalAddrIdType )  assignmToLocalAddrIdMapRef[8]; /* Reference to list for assignment/type to local addrId mapping. */
    TS_REF2CFG( TcpIp_memoryConfigType )  memoryRef; /* Reference to list of buffers */
    VAR( TcpIp_IpV4ConfigType, TYPEDEF ) ipV4Config; /* IpV4 configuration parameters. */
    VAR( TcpIp_IpFragConfigType, TYPEDEF ) ipFragConfig; /* Ip fragmentation configuration parameters. */
    VAR( TcpIp_UdpConfigType, TYPEDEF ) udpConfig; /* Udp configuration parameters. */
    VAR( TcpIp_TcpConfigType, TYPEDEF ) tcpConfig; /* Tcp configuration parameters. */
    VAR( TcpIp_DhcpV4ConfigType, TYPEDEF ) dhcpv4Config; /* Dhcp configuration parameters. */
    VAR( TcpIp_IpV4LinkLocalConfigType, TYPEDEF ) ipV4linkLocalConfig; /* IpV4 link local configuration parameters. */
    VAR( uint16, TYPEDEF ) IpV4ArpDadNum; /* Number of ARP DAD entries. */
    VAR( TcpIp_LocalAddrIdType, TYPEDEF ) totalLocalAddrNum; /* Number of LocalAddrIds configured and generated. */
    VAR( TcpIp_LocalAddrIdType, TYPEDEF ) configLocalAddrNum; /* Number of LocalAddrIds configured. */
    VAR( uint8, TYPEDEF ) ctrlNum; /* Number of TcpIp controllers configured. */
    VAR( uint8, TYPEDEF ) maxCtrlIdx; /* highest EthIf controller index referenced by the TcpIp. */
    VAR( uint8, TYPEDEF ) dhcpv4Num; /* Number of Dhcp clients configured. */
    VAR( uint8, TYPEDEF ) IpV4LinkLocalNum; /* Number of link local Ip address assignments configured. */
    VAR( uint8, TYPEDEF ) transRetryNum; /* Number of transmission retries. */
    VAR( uint8, TYPEDEF ) numOfMemoryPools; /* Number of configured memory pools. */
} TcpIp_ConfigType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* TCPIP_CFGTYPES_H */

/*==================[end of file]============================================*/

