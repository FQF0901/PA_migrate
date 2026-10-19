


/**
 * \file
 *
 * \brief AUTOSAR DoIP
 *
 * This file contains the implementation of the AUTOSAR
 * module DoIP.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef DOIP_TYPES_INT_H
#define DOIP_TYPES_INT_H



/*==================[inclusions]=============================================*/

#include <Platform_Types.h>
#include <ComStack_Cfg.h>
#include <TSAutosar.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS DOIP_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/

typedef VAR( uint8, TYPEDEF ) DoIP_TcpConIdxType;

typedef struct /* DoIP_TesterType */ {
    VAR( uint16, TYPEDEF ) Source;
    VAR( uint16, TYPEDEF ) RouteIdx;
    VAR( uint16, TYPEDEF ) NumBytesDiagNAck;
    VAR( uint16, TYPEDEF ) NumberOfRoutesPerSource;
} DoIP_TesterType;

typedef struct /* DoIP_RoutingActType */ {
    VAR( uint8, TYPEDEF ) ActivationNumber;
    VAR( uint8, TYPEDEF ) AuthReqLength;
    VAR( uint8, TYPEDEF ) AuthResLength;
    VAR( uint8, TYPEDEF ) ConfReqLength;
    VAR( uint8, TYPEDEF ) ConfResLength;
    VAR( boolean, TYPEDEF ) RoutingActivationSecurityRequired;
} DoIP_RoutingActType;

typedef struct /* DoIP_TcpConnType */ {
    VAR( PduIdType, TYPEDEF ) SoAdTxPduId;
    VAR( PduIdType, TYPEDEF ) SoAdRxPduId;
    VAR( boolean, TYPEDEF ) IpAddrAssignReq;
    VAR( boolean, TYPEDEF ) UpdateHostName;
    VAR( boolean, TYPEDEF ) TcpConnectionSecurityRequired;
} DoIP_TcpConnType;

typedef struct /* DoIP_UdpConnType */ {
    VAR( PduIdType, TYPEDEF ) SoAdTxPduId;
    VAR( boolean, TYPEDEF ) IpAddrAssignReq;
    VAR( boolean, TYPEDEF ) UpdateHostName;
} DoIP_UdpConnType;

typedef struct /* DoIP_RouteType */ {
    VAR( PduIdType, TYPEDEF ) DoIPPduRPduId;
    VAR( uint16, TYPEDEF ) RoutingActivationIdx;
} DoIP_RouteType;

typedef struct /* DoIP_CustChannelType */ {
    VAR( PduIdType, TYPEDEF ) DoIPPduRRxPduId;
    VAR( PduIdType, TYPEDEF ) ECUC_RxPduId;
    VAR( PduIdType, TYPEDEF ) DoIPPduRTxPduId;
    VAR( PduIdType, TYPEDEF ) ECUC_TxPduId;
    VAR( uint8, TYPEDEF ) DoIPSoAdPduId;
} DoIP_CustChannelType;

typedef struct /* DoIP_ConfigType */ {
    VAR( uint32, TYPEDEF ) PlatformSignature; /* Used to validate the platform. */
    VAR( uint32, TYPEDEF ) LcfgSignature; /* Used to validate the post build configuration against the link time configuration. */
    VAR( uint32, TYPEDEF ) CfgSignature; /* Used to validate the post build configuration against the precompile time configuration. */
    VAR( uint32, TYPEDEF ) PublicInfoSignature; /* Used to validate Public information. */
    TS_REF2CFG( DoIP_TcpConnType )  TcpConRef;
    TS_REF2CFG( DoIP_UdpConnType )  UdpAnnConRef;
    TS_REF2CFG( DoIP_UdpConnType )  UdpConRef;
    TS_REF2CFG( DoIP_TesterType )  TesterRef;
    TS_REF2CFG( DoIP_RouteType )  RouteRef;
    TS_REF2CFG( DoIP_RoutingActType )  RoutingActivationRef;
    TS_REF2CFG( uint16 )  LOT_TargetRef;
    TS_REF2CFG( PduIdType )  LOT_PduRTxPduIdRef;
    TS_REF2CFG( PduIdType )  LOT_PduRRxPduIdRef;
    VAR( uint16, TYPEDEF ) RouteMax;
    VAR( uint16, TYPEDEF ) PduRRxPduMax;
    VAR( uint16, TYPEDEF ) PduRTxPduMax;
    VAR( uint8, TYPEDEF ) RoutingActivationMax;
    VAR( uint8, TYPEDEF ) TcpConMax;
    VAR( uint8, TYPEDEF ) UdpAnnConMax;
    VAR( uint8, TYPEDEF ) UdpConMax;
    VAR( PduIdType, TYPEDEF ) UdpMaxIdx;
    VAR( uint8, TYPEDEF ) TesterMax;
    VAR( uint8, TYPEDEF ) PduRTxPduStd;
    VAR( uint8, TYPEDEF ) EntityId[6];
    VAR( uint8, TYPEDEF ) GroupId[6];
    VAR( uint8, TYPEDEF ) LogicalAddr[2];
    VAR( uint8, TYPEDEF ) FurtherActionReq;
} DoIP_ConfigType;


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

#endif /* DOIP_TYPES_INT_H */

/*==================[end of file]============================================*/

