


/**
 * \file
 *
 * \brief AUTOSAR SoAd
 *
 * This file contains the implementation of the AUTOSAR
 * module SoAd.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef SOAD_CFGTYPES_H
#define SOAD_CFGTYPES_H



/*==================[inclusions]=============================================*/

#include <Platform_Types.h>
#include <TSAutosar.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS SOAD_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/

#if (defined SOAD_SOCON_OFFLINE) /* To prevent double definition */
#error SOAD_SOCON_OFFLINE already defined
#endif /* (defined SOAD_SOCON_OFFLINE) */

#define SOAD_SOCON_OFFLINE 0U


#if (defined SOAD_SOCON_RECONNECT) /* To prevent double definition */
#error SOAD_SOCON_RECONNECT already defined
#endif /* (defined SOAD_SOCON_RECONNECT) */

#define SOAD_SOCON_RECONNECT 1U


#if (defined SOAD_SOCON_ONLINE) /* To prevent double definition */
#error SOAD_SOCON_ONLINE already defined
#endif /* (defined SOAD_SOCON_ONLINE) */

#define SOAD_SOCON_ONLINE 2U



/*==================[type definitions]=======================================*/

typedef VAR( uint16, TYPEDEF ) SoAd_TcpIp_SockedIdType;

typedef VAR( uint16, TYPEDEF ) SoAd_SocketRouteDestIdType;

typedef VAR( uint16, TYPEDEF ) SoAd_SoConIdType;

typedef VAR( uint16, TYPEDEF ) SoAd_RoutingGroupIdType;

typedef VAR( uint16, TYPEDEF ) SoAd_PduRouteDestVirtualIdType;

typedef VAR( uint16, TYPEDEF ) SoAd_BufLengthType;

typedef VAR( uint16, TYPEDEF ) SoAd_RefToRAM;

typedef VAR( uint8, TYPEDEF ) SoAd_TimerType;

typedef VAR( uint8, TYPEDEF ) SoAd_TcpIp_LocalAddrIdType;

typedef VAR( uint16, TYPEDEF ) SoAd_PduLengthType;

typedef VAR( uint16, TYPEDEF ) SoAd_TlsConnectionIdType;

typedef VAR( uint16, TYPEDEF ) SoAd_NotificationBitmapType;

typedef VAR( uint16, TYPEDEF ) SoAd_PduTxUdpDataIdType;

typedef VAR( uint16, TYPEDEF ) SoAd_RouteIdType;

typedef VAR( uint16, TYPEDEF ) SoAd_PduTxDataIdType;

typedef VAR( uint16, TYPEDEF ) SoAd_SocketRouteDestVirtualIdType;

typedef VAR( uint16, TYPEDEF ) SoAd_PduIdType;

typedef VAR( uint16, TYPEDEF ) SoAd_RoutingGroupMapIdType;

typedef VAR( uint16, TYPEDEF ) SoAd_PduTxTcpDataIdType;

typedef VAR( uint16, TYPEDEF ) SoAd_PduRouteDestCommonIdType;

typedef VAR( uint8, TYPEDEF ) SoAd_SocketStateType;

typedef struct /* SoAd_SoConGroupStateType */ {
    VAR( uint8, TYPEDEF ) Flags;
} SoAd_SoConGroupStateType;

typedef VAR( uint8, TYPEDEF ) SoAd_PduRouteDestVirtualStateType;

typedef VAR( uint8, TYPEDEF ) SoAd_SoAdBufferType;

/** 
 * \brief Socket connection states
 */
typedef VAR( uint8, TYPEDEF ) SoAd_SoConModeType;

typedef struct /* SoAd_RoutingGroupSocketRouteDestMapMapType */ {
    VAR( SoAd_SocketRouteDestIdType, TYPEDEF ) SocketRouteDestMapCnt;
    VAR( SoAd_TcpIp_SockedIdType, TYPEDEF ) SocketRouteDestMapFirstId;
} SoAd_RoutingGroupSocketRouteDestMapMapType;

typedef struct /* SoAd_RoutingGroupExtToIntIdMapType */ {
    VAR( SoAd_RoutingGroupIdType, TYPEDEF ) RoutingGroupId;
    VAR( SoAd_SoConIdType, TYPEDEF ) SoConGroupId;
} SoAd_RoutingGroupExtToIntIdMapType;

typedef struct /* SoAd_RoutingGroupPduRouteDestMapType */ {
    VAR( SoAd_PduRouteDestVirtualIdType, TYPEDEF ) PduRouteDestVirtualMapCnt;
    VAR( SoAd_PduRouteDestVirtualIdType, TYPEDEF ) PduRouteDestVirtualMapFirstId;
} SoAd_RoutingGroupPduRouteDestMapType;

typedef struct /* SoAd_CancelReceiveSoConMapType */ {
    VAR( SoAd_SoConIdType, TYPEDEF ) SoConId;
    VAR( SoAd_TcpIp_SockedIdType, TYPEDEF ) SocketRouteId;
} SoAd_CancelReceiveSoConMapType;

typedef struct /* SoAd_FixTxBufferIdToSoConIdInitMapCfgType */ {
    VAR( SoAd_SoConIdType, TYPEDEF ) SoConId;
    VAR( SoAd_SoConIdType, TYPEDEF ) BufferId;
} SoAd_FixTxBufferIdToSoConIdInitMapCfgType;

typedef struct /* SoAd_SoConTxBufferCfgType */ {
    VAR( SoAd_RefToRAM, TYPEDEF ) BufId;
    VAR( SoAd_BufLengthType, TYPEDEF ) Capacity;
} SoAd_SoConTxBufferCfgType;

typedef struct /* SoAd_SoConRxBufferCfgType */ {
    VAR( SoAd_RefToRAM, TYPEDEF ) BufId;
    VAR( SoAd_BufLengthType, TYPEDEF ) IfCapacity;
    VAR( SoAd_BufLengthType, TYPEDEF ) TpCapacity;
} SoAd_SoConRxBufferCfgType;

typedef struct /* SoAd_SoConGroupType */ {
    VAR( uint32, TYPEDEF ) SocketTcpKeepAliveInterval;
    VAR( uint32, TYPEDEF ) SocketTcpKeepAliveTime;
    VAR( SoAd_SoConIdType, TYPEDEF ) SoConFirstId;
    VAR( SoAd_SoConIdType, TYPEDEF ) SoConCnt;
    VAR( uint16, TYPEDEF ) LocalPort;
    VAR( SoAd_PduLengthType, TYPEDEF ) TxQuota;
    VAR( SoAd_SoConIdType, TYPEDEF ) BufferFirstId;
    VAR( SoAd_SoConIdType, TYPEDEF ) BufferPoolCount;
    VAR( SoAd_SoConIdType, TYPEDEF ) BufferPoolFirstId;
    VAR( SoAd_SoConIdType, TYPEDEF ) ShadowBufferId;
    VAR( uint8, TYPEDEF ) FramePriority;
    VAR( SoAd_TcpIp_LocalAddrIdType, TYPEDEF ) LocalIpAddrId;
    VAR( uint8, TYPEDEF ) SocketTcpKeepAliveProbesMax;
    VAR( SoAd_TimerType, TYPEDEF ) UdpAliveRefTimeout;
    VAR( SoAd_TimerType, TYPEDEF ) NPduUdpTxRefTimeout;
} SoAd_SoConGroupType;

typedef struct /* SoAd_SoConType */ {
    VAR( uint32, TYPEDEF ) AllowedRemoteIpAddr[1];
    VAR( uint16, TYPEDEF ) AllowedRemotePort;
    VAR( uint16, TYPEDEF ) Flags;
    VAR( SoAd_PduTxDataIdType, TYPEDEF ) PduTxDataCnt;
    VAR( SoAd_PduTxDataIdType, TYPEDEF ) PduTxDataFirstId;
    VAR( SoAd_SoConIdType, TYPEDEF ) RxDataId;
    VAR( SoAd_RouteIdType, TYPEDEF ) SocketRouteCnt;
    VAR( SoAd_RouteIdType, TYPEDEF ) SocketRouteFirstId;
    VAR( SoAd_SoConIdType, TYPEDEF ) SoConGroupId;
    VAR( SoAd_SoConIdType, TYPEDEF ) SoConId;
    VAR( SoAd_SoConIdType, TYPEDEF ) SoConTxTcpDataId;
    VAR( SoAd_PduTxUdpDataIdType, TYPEDEF ) SoConTxUdpDataId;
    VAR( SoAd_SoConIdType, TYPEDEF ) TxDataId;
    VAR( SoAd_NotificationBitmapType, TYPEDEF ) ULNotifBitmap;
    VAR( SoAd_TlsConnectionIdType, TYPEDEF ) TlsConnectionId;
} SoAd_SoConType;

typedef struct /* SoAd_SocketRouteDestType */ {
    VAR( SoAd_PduIdType, TYPEDEF ) DestPduId;
    VAR( SoAd_RoutingGroupMapIdType, TYPEDEF ) RoutingGroupMapCnt;
    VAR( SoAd_RoutingGroupMapIdType, TYPEDEF ) RoutingGroupMapFirstId;
    VAR( SoAd_PduIdType, TYPEDEF ) EcuCPduId;
    VAR( SoAd_SocketRouteDestIdType, TYPEDEF ) SocketRouteDestId;
    VAR( SoAd_RouteIdType, TYPEDEF ) SocketRouteId;
    VAR( SoAd_SocketRouteDestVirtualIdType, TYPEDEF ) VirtualDestinationStartId;
    VAR( SoAd_SocketRouteDestVirtualIdType, TYPEDEF ) VirtualDestinationCount;
    VAR( uint8, TYPEDEF ) Flags;
    VAR( uint8, TYPEDEF ) ULFuncId;
} SoAd_SocketRouteDestType;

typedef struct /* SoAd_SocketRouteType */ {
    VAR( uint32, TYPEDEF ) PduHeaderId;
    VAR( SoAd_SocketRouteDestIdType, TYPEDEF ) SocketRouteDestFirstId;
    VAR( SoAd_SocketRouteDestIdType, TYPEDEF ) SocketRouteDestCnt;
    VAR( SoAd_SocketRouteDestIdType, TYPEDEF ) SoConToSocketRouteDestMapFirstId;
    VAR( uint8, TYPEDEF ) Flags;
} SoAd_SocketRouteType;

typedef struct /* SoAd_PduRouteType */ {
    VAR( SoAd_PduRouteDestVirtualIdType, TYPEDEF ) PduRouteDestVirtualCnt;
    VAR( SoAd_PduRouteDestVirtualIdType, TYPEDEF ) PduRouteDestVirtualFirstId;
    VAR( SoAd_PduIdType, TYPEDEF ) TxConfPduId;
    VAR( SoAd_PduIdType, TYPEDEF ) EcuCPduId;
    VAR( uint8, TYPEDEF ) Flags;
    VAR( uint8, TYPEDEF ) ULFuncId;
} SoAd_PduRouteType;

typedef struct /* SoAd_PduRouteDestVirtualType */ {
    VAR( SoAd_SoConIdType, TYPEDEF ) SoConId;
    VAR( SoAd_PduRouteDestVirtualIdType, TYPEDEF ) PduRouteDestVirtualId;
    VAR( SoAd_PduRouteDestCommonIdType, TYPEDEF ) PduRouteDestCommonId;
    VAR( SoAd_RouteIdType, TYPEDEF ) PduRouteId;
    VAR( SoAd_PduTxDataIdType, TYPEDEF ) PduTxDataId;
    VAR( SoAd_PduTxTcpDataIdType, TYPEDEF ) PduTxTcpDataId;
} SoAd_PduRouteDestVirtualType;

typedef struct /* SoAd_PduRouteDestCommonType */ {
    VAR( uint32, TYPEDEF ) PduHeaderId;
    VAR( SoAd_RoutingGroupMapIdType, TYPEDEF ) RoutingGroupMapCnt;
    VAR( SoAd_RoutingGroupMapIdType, TYPEDEF ) RoutingGroupMapFirstId;
    VAR( SoAd_TimerType, TYPEDEF ) NPduUdpTxPduTimeout;
    VAR( uint8, TYPEDEF ) Flags;
} SoAd_PduRouteDestCommonType;

typedef struct /* SoAd_SoConRxDataType */ {
    VAR( uint32, TYPEDEF ) CurrPduHeaderId;
    VAR( uint32, TYPEDEF ) CurrPduLen;
    VAR( SoAd_PduLengthType, TYPEDEF ) TpOut;
    VAR( SoAd_PduLengthType, TYPEDEF ) TpIn;
    VAR( SoAd_PduLengthType, TYPEDEF ) IfIn;
    VAR( SoAd_PduLengthType, TYPEDEF ) CurrPduForwardedLen;
    VAR( SoAd_PduLengthType, TYPEDEF ) NextPduOutstandingLen;
    VAR( SoAd_RouteIdType, TYPEDEF ) CurrSocketRouteId;
    VAR( uint8, TYPEDEF ) CurrPduHeaderRemainingLen;
} SoAd_SoConRxDataType;

typedef struct /* SoAd_SoConStateType */ {
    VAR( uint32, TYPEDEF ) RemoteAddress[1];
    VAR( uint16, TYPEDEF ) AssignedLocalPort;
    VAR( uint16, TYPEDEF ) UpperFlags;
    VAR( uint16, TYPEDEF ) RemotePort;
    VAR( SoAd_TcpIp_SockedIdType, TYPEDEF ) SocketId;
    VAR( uint16, TYPEDEF ) SetUniqueRemoteAddrCnt;
    VAR( uint8, TYPEDEF ) BusyCnt;
    VAR( SoAd_SocketStateType, TYPEDEF ) SocketState;
    VAR( uint8, TYPEDEF ) LowerFlags;
    VAR( uint8, TYPEDEF ) OpenRefCnt;
    VAR( SoAd_TimerType, TYPEDEF ) UdpAliveTimeout;
} SoAd_SoConStateType;

typedef struct /* SoAd_SoConTxTcpDataType */ {
    VAR( SoAd_PduLengthType, TYPEDEF ) TxConfCtr;
} SoAd_SoConTxTcpDataType;

typedef struct /* SoAd_SoConTxUdpDataType */ {
    VAR( SoAd_SoConIdType, TYPEDEF ) TxBufferId;
} SoAd_SoConTxUdpDataType;

typedef struct /* SoAd_PduRouteDestVirtualDataType */ {
    VAR( SoAd_PduRouteDestVirtualStateType, TYPEDEF ) PduRouteDestVirtualState;
} SoAd_PduRouteDestVirtualDataType;

typedef struct /* SoAd_PduTxTcpDataType */ {
    VAR( SoAd_PduLengthType, TYPEDEF ) PduTxConfCtr;
} SoAd_PduTxTcpDataType;

typedef struct /* SoAd_ListenSocketSoConMapType */ {
    VAR( SoAd_TcpIp_SockedIdType, TYPEDEF ) ListenSocketId;
    VAR( SoAd_SoConIdType, TYPEDEF ) SoConListFirstId;
} SoAd_ListenSocketSoConMapType;

typedef struct /* SoAd_SocketSoConMapType */ {
    VAR( SoAd_TcpIp_SockedIdType, TYPEDEF ) SocketId;
    VAR( SoAd_SoConIdType, TYPEDEF ) SoConId;
} SoAd_SocketSoConMapType;

typedef struct /* SoAd_SoConTxBufferStateType */ {
    VAR( SoAd_BufLengthType, TYPEDEF ) TxLen;
    VAR( SoAd_BufLengthType, TYPEDEF ) BufferIdx;
    VAR( SoAd_TimerType, TYPEDEF ) TxTimer;
} SoAd_SoConTxBufferStateType;

typedef struct /* SoAd_ConfigType */ {
    VAR( uint32, TYPEDEF ) CfgSignature;
    VAR( uint32, TYPEDEF ) LcfgSignature;
    VAR( uint32, TYPEDEF ) PlatformSignature;
    VAR( uint32, TYPEDEF ) PublicInfoSignature;
    VAR( uint32, TYPEDEF ) SoAdPBRAMRequired;
    VAR( SoAd_SoConIdType, TYPEDEF ) ListenSocketCapacity;
    VAR( SoAd_PduRouteDestVirtualIdType, TYPEDEF ) PduRouteCnt;
    VAR( SoAd_RoutingGroupIdType, TYPEDEF ) RoutingGroupCnt;
    VAR( SoAd_RoutingGroupIdType, TYPEDEF ) RoutingGroupExtCnt;
    VAR( SoAd_SoConIdType, TYPEDEF ) SoConCnt;
    VAR( SoAd_BufLengthType, TYPEDEF ) BufferCnt;
    VAR( SoAd_BufLengthType, TYPEDEF ) BufferPoolCnt;
    VAR( SoAd_BufLengthType, TYPEDEF ) FixedBufferCnt;
    VAR( SoAd_SoConIdType, TYPEDEF ) SoConGroupCnt;
    VAR( SoAd_RouteIdType, TYPEDEF ) SocketRouteCnt;
    VAR( SoAd_SocketRouteDestIdType, TYPEDEF ) SocketRouteDestCnt;
    VAR( SoAd_SocketRouteDestVirtualIdType, TYPEDEF ) SocketRouteDestVirtualCnt;
    VAR( SoAd_SocketRouteDestIdType, TYPEDEF ) SoConToSocketRouteDestMapCnt;
    VAR( SoAd_RouteIdType, TYPEDEF ) CancelReceiveSoConMapCnt;
    VAR( SoAd_RoutingGroupIdType, TYPEDEF ) RoutingGroupTriggerableCnt;
    VAR( SoAd_PduRouteDestVirtualIdType, TYPEDEF ) PduRouteDestVirtualCnt;
    VAR( SoAd_BufLengthType, TYPEDEF ) TriggerTransmitBufferCapacity;
    VAR( SoAd_RefToRAM, TYPEDEF ) ListenSocketSoConMapBase;
    VAR( SoAd_RefToRAM, TYPEDEF ) LocalIpAddrStateBitMapBase;
    VAR( SoAd_RefToRAM, TYPEDEF ) PduRouteDestVirtualDataBase;
    VAR( SoAd_RefToRAM, TYPEDEF ) PduTxTcpDataBase;
    VAR( SoAd_RefToRAM, TYPEDEF ) RoutingGroupStateBitMapBase;
    VAR( SoAd_RefToRAM, TYPEDEF ) SoConRxDataBase;
    VAR( SoAd_RefToRAM, TYPEDEF ) SoConStateBase;
    VAR( SoAd_RefToRAM, TYPEDEF ) SoConGroupStateBase;
    VAR( SoAd_RefToRAM, TYPEDEF ) SoConTxDataBase;
    VAR( SoAd_RefToRAM, TYPEDEF ) SoConTxTcpDataBase;
    VAR( SoAd_RefToRAM, TYPEDEF ) SoConTxUdpDataBase;
    VAR( SoAd_RefToRAM, TYPEDEF ) SoConTxBufferStateBase;
    VAR( SoAd_RefToRAM, TYPEDEF ) SocketSoConMapBase;
    VAR( SoAd_RefToRAM, TYPEDEF ) SoConToSocketRouteDestMapBase;
    VAR( SoAd_RefToRAM, TYPEDEF ) SoAdBufferBase;
    VAR( SoAd_RefToRAM, TYPEDEF ) SoAdBufferPoolBitMapBase;
    VAR( SoAd_RefToRAM, TYPEDEF ) RoutingGroupTriggeredBitMapBase;
    VAR( SoAd_RefToRAM, TYPEDEF ) TriggerTransmitBufferBufId;
    VAR( SoAd_RefToRAM, TYPEDEF ) SoConTransCondChangeBitMapBase;
    VAR( SoAd_RefToRAM, TYPEDEF ) SoConRxNotIdleBitMapBase;
    VAR( SoAd_RefToRAM, TYPEDEF ) SoConTxTPNotIdleBitMapBase;
    VAR( SoAd_RefToRAM, TYPEDEF ) SoConTxIFNotIdleBitMapBase;
    VAR( SoAd_RefToRAM, TYPEDEF ) DestVirtualNotIdleBitMapBase;
    VAR( SoAd_RefToRAM, TYPEDEF ) PduTxDataNotIdleBitMapBase;
    VAR( SoAd_RefToRAM, TYPEDEF ) PduRouteDestVirtualTxEnabledBitMapBase;
    VAR( SoAd_RefToRAM, TYPEDEF ) SocketRouteDestVirtualEnabledBitMapBase;
    TS_REF2CFG( uint32 )  SocketRouteDestVirtualEnableBitMapInitRef;
    TS_REF2CFG( SoAd_PduRouteDestCommonType )  PduRouteDestCommonRef;
    TS_REF2CFG( SoAd_PduRouteDestVirtualType )  PduRouteDestVirtualRef;
    TS_REF2CFG( SoAd_PduRouteType )  PduRouteRef;
    TS_REF2CFG( SoAd_PduRouteDestVirtualIdType )  PduTxData_PduRoute_MapRef;
    TS_REF2CFG( uint8 )  RoutingGroupStateBitMapInitRef;
    TS_REF2CFG( uint32 )  PduRouteDestVirtualTxEnableBitMapInitRef;
    TS_REF2CFG( SoAd_SocketRouteType )  SocketRouteRef;
    TS_REF2CFG( SoAd_SocketRouteDestType )  SocketRouteDestRef;
    TS_REF2CFG( SoAd_SoConType )  SoConRef;
    TS_REF2CFG( SoAd_SoConGroupType )  SoConGroupRef;
    TS_REF2CFG( SoAd_SoConRxBufferCfgType )  SoConRxBufferCfgRef;
    TS_REF2CFG( SoAd_SoConTxBufferCfgType )  SoConTxBufferCfgRef;
    TS_REF2CFG( SoAd_FixTxBufferIdToSoConIdInitMapCfgType )  FixTxBufferIdToSoConIdInitMapCfgRef;
    TS_REF2CFG( SoAd_CancelReceiveSoConMapType )  CancelReceiveSoConMapRef;
    TS_REF2CFG( SoAd_RoutingGroupIdType )  PduRouteDestRoutingGroupMapRef;
    TS_REF2CFG( SoAd_PduRouteDestVirtualIdType )  RoutingGroupPduRouteDestVirtualMapRef;
    TS_REF2CFG( SoAd_RoutingGroupIdType )  SocketRouteRoutingGroupMapRef;
    TS_REF2CFG( SoAd_RoutingGroupPduRouteDestMapType )  RoutingGroupPduRouteDestMapRef;
    TS_REF2CFG( SoAd_RoutingGroupExtToIntIdMapType )  RoutingGroupExtToIntIdMapRef;
    TS_REF2CFG( SoAd_SocketRouteDestIdType )  RoutingGroupSocketRouteDestMapRef;
    TS_REF2CFG( SoAd_RoutingGroupSocketRouteDestMapMapType )  RoutingGroupSocketRouteDestMapMapRef;
    VAR( uint8, TYPEDEF ) LocalIpAddrCnt;
} SoAd_ConfigType;


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

#endif /* SOAD_CFGTYPES_H */

/*==================[end of file]============================================*/

