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

#ifndef TCPIP_IPSECIKEV2_EXT_H
#define TCPIP_IPSECIKEV2_EXT_H

/*==================[inclusions]============================================*/
#include <TcpIp_Api.h>            /* general TcpIp type definitions */
/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

#define TCPIP_START_SEC_CODE
#include <TcpIp_MemMap.h>

#if (TCPIP_SECURITY_MODE == TCPIP_IKEV2)


/** \brief React to controller state changes
 *
 * This function opens or closes the UPD-socket (port 500) used for IKE communication. If
 * \p State is TCPIP_IPADDR_STATE_ASSIGNED a socket is opened. If \p State is
 * TCPIP_IPADDR_STATE_UNASSIGNED the socket is closed. If \p State is TCPIP_IPADDR_STATE_ONHOLD
 * nothing happens.
 *
 * \param[in] localAddrId   IP address Identifier, representing an IP address specified
 *                          in the TcpIp module configuration.
 * \param[in] State         State of IP address assignment.
 */
extern FUNC(void, TCPIP_CODE) TcpIp_IkeV2_LocalIpAddrAssignmentChg
(
  TcpIp_LocalAddrIdType localAddrId,
  TcpIp_IpAddrStateType State
);


/** \brief Reception of an IkeV2 message
 *
 * By this API service the IkeV2 SW-Unit gets an indication of a received IkeV2 message. It is
 * checked if a valid connection exists to the remote peer and the message is stored in the
 * IKE rxBuffer. If no more element is free in the rxBuffer the message is dropped.
 *
 * \param[in] SocketId      Index of the socket
 * \param[in] RemoteAddrPtr Points to the remote address information
 * \param[in] BufPtr        Points to the received data. The data contains the IkeV2 message
 * \param[in] Length        Length of received data.
 */
extern FUNC(void, TCPIP_CODE) TcpIp_IkeV2_rxIndication
(
  TcpIp_SocketIdType SocketId,
  P2CONST(TcpIp_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) RemoteAddrPtr,
  P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) BufPtr,
  uint16 Length
);

#endif /* (#if (TCPIP_SECURITY_MODE == TCPIP_IKEV2)) */

#define TCPIP_STOP_SEC_CODE
#include <TcpIp_MemMap.h>

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/


#endif /* TCPIP_IPSECIKEV2_EXT_H */
