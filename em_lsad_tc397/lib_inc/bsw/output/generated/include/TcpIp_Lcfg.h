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
#ifndef TCPIP_LCFG_H
#define TCPIP_LCFG_H

/*==================[inclusions]============================================*/

#include <TSAutosar.h>              /* global configuration */
#include <ComStack_Types.h>         /* Com Stack Types */
#include <TcpIp_Socket_Api.h>       /* Type definitions of Socket SW-unit */
#include <TcpIp_IpAddrM_Api.h>      /* Type definitions of IpAddrM SW-unit*/
#include <TcpIp_Ip_Api.h>           /* Type definitions of Ip SW-unit*/

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/** \brief Function pointer type for <Up>_RxIndication */
typedef P2FUNC(void, TCPIP_APPL_CODE, TcpIp_RxIndicationFpType)
(
  TcpIp_SocketIdType SocketId,
  P2CONST(TcpIp_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) RemoteAddrPtr,
  P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) BufPtr,
  uint16 Length
);

/** \brief Function pointer type for <Up>_LocalIpAddrAssignmentChg */
typedef P2FUNC(void, TCPIP_APPL_CODE, TcpIp_LocalIpAddrAssignChgFpType)
(
  TcpIp_LocalAddrIdType IpAddrId,
  TcpIp_IpAddrStateType State
);

/** \brief Function pointer type for <Up>_CopyTxData */
typedef P2FUNC(BufReq_ReturnType, TCPIP_APPL_CODE, TcpIp_CopyTxDataFpType)
(
  TcpIp_SocketIdType SocketId,
  P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) BufPtr,
  uint16 BufLength
);

/** \brief Function pointer type for <Up>_TcpIpEvent */
typedef P2FUNC(void, TCPIP_APPL_CODE, TcpIp_TcpIpEventFpType)
(
  TcpIp_SocketIdType SocketId,
  TcpIp_EventType Event
);

/** \brief Function pointer type for <Up>_TcpAccepted */
typedef P2FUNC(Std_ReturnType, TCPIP_APPL_CODE, TcpIp_TcpAcceptedFpType)
(
  TcpIp_SocketIdType SocketId,
  TcpIp_SocketIdType SocketIdConnected,
  P2CONST(TcpIp_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) RemoteAddrPtr
);

/** \brief Function pointer type for <Up>_TcpConnected */
typedef P2FUNC(void, TCPIP_APPL_CODE, TcpIp_TcpConnectedFpType)
(
  TcpIp_SocketIdType SocketId
);

/** \brief Function pointer type for <Up>_TxConfirmation */
typedef P2FUNC(void, TCPIP_APPL_CODE, TcpIp_TxConfirmationFpType)
(
  TcpIp_SocketIdType SocketId,
  uint16 Length
);












/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

#define TCPIP_START_SEC_CONST_8
#include <TcpIp_MemMap.h>

/** \brief Number of total socket owners */
extern CONST(uint8, TCPIP_APPL_CONST) TcpIp_NumSockOwner;

/** \brief Number of socket owner configured through TcpIpSocketOwnerConfig (without DHCP) */
extern CONST(uint8, TCPIP_APPL_CONST) TcpIp_NumConfSockOwner;

/** \brief Number of socket owners configured to behave as a side upper layer (Tls) */
extern CONST(uint8, TCPIP_APPL_CONST) TcpIp_NumUlSockOwner;

#define TCPIP_STOP_SEC_CONST_8
#include <TcpIp_MemMap.h>

/* start data section declaration */
#define TCPIP_START_SEC_CONST_32
#include <TcpIp_MemMap.h>

/* value used to validate post build configuration against link time configuration */
extern CONST(uint32, TCPIP_CONST) TcpIp_LcfgSignature;

/* stop data section declaration */
#define TCPIP_STOP_SEC_CONST_32
#include <TcpIp_MemMap.h>

#define TCPIP_START_SEC_CONST_UNSPECIFIED
#include <TcpIp_MemMap.h>

/** \brief Function pointer array for <Up>_RxIndication */
extern CONST(TcpIp_RxIndicationFpType, TCPIP_APPL_CONST) TcpIp_RxIndicationAPI[];

/** \brief Function pointer array for <Up>_LocalIpAddrAssignmentChg */
extern CONST(TcpIp_LocalIpAddrAssignChgFpType, TCPIP_APPL_CONST) TcpIp_LocalIpAddrAssignChgAPI[];

/** \brief Function pointer array for <Up>_CopyTxData */
extern CONST(TcpIp_CopyTxDataFpType, TCPIP_APPL_CONST) TcpIp_CopyTxDataAPI[];

/** \brief Function pointer array for <Up>_TcpIpEvent */
extern CONST(TcpIp_TcpIpEventFpType, TCPIP_APPL_CONST) TcpIp_TcpIpEventAPI[];

/** \brief Function pointer array for <Up>_TcpAccepted */
extern CONST(TcpIp_TcpAcceptedFpType, TCPIP_APPL_CONST) TcpIp_TcpAcceptedAPI[];

/** \brief Function pointer array for <Up>_TcpConnected */
extern CONST(TcpIp_TcpConnectedFpType, TCPIP_APPL_CONST) TcpIp_TcpConnectedAPI[];

/** \brief Function pointer array for <Up>_TxConfirmation */
extern CONST(TcpIp_TxConfirmationFpType, TCPIP_APPL_CONST) TcpIp_TxConfirmationAPI[];













#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
#include <TcpIp_MemMap.h>

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef TCPIP_LCFG_H */
/*==================[end of file]===========================================*/
