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
#ifndef SOAD_CFG_H
#define SOAD_CFG_H

/*==================[includes]==============================================*/

#include <TSAutosar.h>              /* Global configuration */
#include <ComStack_Types.h>
#include <SoAd_DefProg_Cfg.h>

/*==================[macros]================================================*/

#if (defined SOAD_PBCFGM_SUPPORT_ENABLED) /* To prevent double definition */
#error SOAD_PBCFGM_SUPPORT_ENABLED already defined!
#endif /* (defined SOAD_PBCFGM_SUPPORT_ENABLED) */

/** \brief switch reports that PbcfgM uses SoAd */
#define SOAD_PBCFGM_SUPPORT_ENABLED STD_OFF


#if (defined SOAD_ISVALIDCONFIG_MMAP_ENABLED) /* To prevent double definition */
#error SOAD_ISVALIDCONFIG_MMAP_ENABLED already defined!
#endif /* (defined SOAD_ISVALIDCONFIG_MMAP_ENABLED) */

/** \brief switch reports that SoAd_IsValidConfig function shall be mapped to memory section SOAD_CODE_CC_BLOCK */
#define SOAD_ISVALIDCONFIG_MMAP_ENABLED STD_OFF


#if (defined SOAD_DEV_ERROR_DETECT) /* To prevent double definition */
#error SOAD_DEV_ERROR_DETECT already defined!
#endif /* (defined SOAD_DEV_ERROR_DETECT) */

/** \brief Pre-processor switch for enabling development error detection. */
#define SOAD_DEV_ERROR_DETECT STD_ON


#if (defined SOAD_VERSION_INFO_API) /* To prevent double definition */
#error SOAD_VERSION_INFO_API already defined!
#endif /* (defined SOAD_VERSION_INFO_API) */

/** \brief Pre-processor switch for enabling version info API support. */
#define SOAD_VERSION_INFO_API STD_ON


#if (defined SOAD_REPORT_SOAD_E_INV_PDUHEADER_ID) /* To prevent double definition */
#error SOAD_REPORT_SOAD_E_INV_PDUHEADER_ID already defined!
#endif /* (defined SOAD_REPORT_SOAD_E_INV_PDUHEADER_ID) */

/** \brief Pre-processor switch for enabling version info API support. */
#define SOAD_REPORT_SOAD_E_INV_PDUHEADER_ID STD_ON


#if (defined SOAD_IPV6_SUPPORT) /* To prevent double definition */
#error SOAD_IPV6_SUPPORT already defined!
#endif /* (defined SOAD_IPV6_SUPPORT) */

/** \brief Pre-processor switch for enabling version info API support. */
#define SOAD_IPV6_SUPPORT STD_OFF


/** \brief Maximum value of SoAd_TimerType. */
#define SOAD_TIMERTYPE_MAX 255U


#if (defined SOAD_META_DATA_HANDLING) /* To prevent double definition */
#error SOAD_META_DATA_HANDLING already defined!
#endif /* (defined SOAD_META_DATA_HANDLING) */

/** \brief Pre-prcoessor switch for enabling MetaDataHandling */
#define SOAD_META_DATA_HANDLING STD_OFF


#if (defined SOAD_ENABLE_MAIN_FUNCTION_TX) /* To prevent double definition */
#error SOAD_ENABLE_MAIN_FUNCTION_TX already defined!
#endif /* (defined SOAD_ENABLE_MAIN_FUNCTION_TX) */

/** \brief Pre-Processor switch for enabling SoAdEnableMainFunctionTx */
#define SOAD_ENABLE_MAIN_FUNCTION_TX STD_OFF


#if (defined SOAD_GETANDRESETMEASUREMENTDATA_API) /* To prevent double definition */
#error SOAD_GETANDRESETMEASUREMENTDATA_API already defined!
#endif /* (defined SOAD_GETANDRESETMEASUREMENTDATA_API) */

/** \brief Pre-Processor switch for enabling SoAdGetAndResetMeasurementDataApi  */
#define SOAD_GETANDRESETMEASUREMENTDATA_API STD_OFF


#if (defined SOAD_TLS_ENABLED) /* To prevent double definition */
#error SOAD_TLS_ENABLED already defined!
#endif /* (defined SOAD_TLS_ENABLED) */

/** \brief Pre-Processor switch for enabling SoAdTlsEnabled */
#define SOAD_TLS_ENABLED STD_OFF


/** \brief Maximum value of SetUniqueRemoteCnt. */
#define SOAD_SETUNIQUEREMOTEADDRCNT_MAX 65535U

/*------------------[Invalid values for index types]------------------------*/

#if (defined SOAD_INVALID_ROUTE_ID) /* To prevent double definition */
#error SOAD_INVALID_ROUTE_ID already defined!
#endif /* (defined SOAD_INVALID_ROUTE_ID) */

/** \brief Max SoAd_RoutingGroupIdType value */
#define SOAD_INVALID_ROUTE_ID 0xFFFFU

        
#if (defined SOAD_INVALID_SOCKET_ROUTE_DEST_ID) /* To prevent double definition */
#error SOAD_INVALID_SOCKET_ROUTE_DEST_ID already defined!
#endif /* (defined SOAD_INVALID_SOCKET_ROUTE_DEST_ID) */

/** \brief Max SoAd_SocketRouteDestIdType value */
#define SOAD_INVALID_SOCKET_ROUTE_DEST_ID 0xFFFFU


#if (defined SOAD_INVALID_DEST_VIRTUAL_ID) /* To prevent double definition */
#error SOAD_INVALID_DEST_VIRTUAL_ID already defined!
#endif /* (defined SOAD_INVALID_DEST_VIRTUAL_ID) */

/** \brief Max SoAd_PduRouteDestVirtualIdType value */
#define SOAD_INVALID_DEST_VIRTUAL_ID 0xFFFFU

        
#if (defined SOAD_INVALID_PDUTXDATA_ID) /* To prevent double definition */
#error SOAD_INVALID_PDUTXDATA_ID already defined!
#endif /* (defined SOAD_INVALID_PDUTXDATA_ID) */

/** \brief Invalid value for SoAd_PduTxDataIdType */
#define SOAD_INVALID_PDUTXDATA_ID 0xFFFFU

        
#if (defined SOAD_INVALID_PDUTXTCPDATA_ID) /* To prevent double definition */
#error SOAD_INVALID_PDUTXTCPDATA_ID already defined!
#endif /* (defined SOAD_INVALID_PDUTXTCPDATA_ID) */

/** \brief Invalid value for SoAd_PduTxTcpDataIdType */
#define SOAD_INVALID_PDUTXTCPDATA_ID 0xFFFFU


#if (defined SOAD_INVALID_PDUTXUDPDATA_ID) /* To prevent double definition */
#error SOAD_INVALID_PDUTXUDPDATA_ID already defined!
#endif /* (defined SOAD_INVALID_PDUTXUDPDATA_ID) */

/** \brief Invalid value for SoAd_PduTxUdpDataIdType */
#define SOAD_INVALID_PDUTXUDPDATA_ID 0xFFFFU


#if (defined SOAD_INVALID_SOCON_ID) /* To prevent double definition */
#error SOAD_INVALID_SOCON_ID already defined!
#endif /* (defined SOAD_INVALID_SOCON_ID) */

/** \brief Max SoAd_SoConIdType value */
#define SOAD_INVALID_SOCON_ID 0xFFFFU


#if (defined SOAD_INVALID_ROUTINGGROUP_ID) /* To prevent double definition */
#error SOAD_INVALID_ROUTINGGROUP_ID already defined!
#endif /* (defined SOAD_INVALID_ROUTINGGROUP_ID) */

/** \brief Max SoAd_RoutingGroupIdType value */
#define SOAD_INVALID_ROUTINGGROUP_ID 0xFFFFU


#if (defined SOAD_INVALID_FRAME_PRIO) /* To prevent double definition */
#error SOAD_INVALID_FRAME_PRIO already defined!
#endif /* (defined SOAD_INVALID_FRAME_PRIO) */

/** \brief Max FramePriority value */
#define SOAD_INVALID_FRAME_PRIO 255U


#if (defined SOAD_INVALID_TIMERVAL) /* To prevent double definition */
#error SOAD_INVALID_TIMERVAL already defined!
#endif /* (defined SOAD_INVALID_TIMERVAL) */

/** \brief Invalid value for timers */
#define SOAD_INVALID_TIMERVAL 0xFFU


#if (defined SOAD_TLS_INVALID_CONNECTION_ID) /* To prevent double definition */
#error SOAD_TLS_INVALID_CONNECTION_ID already defined!
#endif /* (defined SOAD_TLS_INVALID_CONNECTION_ID) */

/** \brief Invalid value for tlsConnectionIds */
#define SOAD_TLS_INVALID_CONNECTION_ID 0xFFFFU


/*------------------[Flag type values]--------------------------------------*/


#if (defined SOAD_SOCONSTATE_FLAG_REMOTE_SET_SHIFT) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_REMOTE_SET_SHIFT already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_REMOTE_SET_SHIFT) */

/** \brief The bit shift for socket connection upper flag SOAD_SOCONSTATE_FLAG_REMOTE_SET */
#define SOAD_SOCONSTATE_FLAG_REMOTE_SET_SHIFT 0U


#if (defined SOAD_SOCONSTATE_FLAG_REMOTE_SET_MASK) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_REMOTE_SET_MASK already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_REMOTE_SET_MASK) */

/** \brief The bit mask for socket connection state upper flag SOAD_SOCONSTATE_FLAG_REMOTE_SET */
#define SOAD_SOCONSTATE_FLAG_REMOTE_SET_MASK ((uint16)(1UL << SOAD_SOCONSTATE_FLAG_REMOTE_SET_SHIFT))


#if (defined SOAD_SOCONSTATE_FLAG_TX_TP_PENDING_SHIFT) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_TX_TP_PENDING_SHIFT already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_TX_TP_PENDING_SHIFT) */

/** \brief The bit shift for socket connection upper flag SOAD_SOCONSTATE_FLAG_TX_TP_PENDING */
#define SOAD_SOCONSTATE_FLAG_TX_TP_PENDING_SHIFT 1U


#if (defined SOAD_SOCONSTATE_FLAG_TX_TP_PENDING_MASK) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_TX_TP_PENDING_MASK already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_TX_TP_PENDING_MASK) */

/** \brief The bit mask for socket connection state upper flag SOAD_SOCONSTATE_FLAG_TX_TP_PENDING */
#define SOAD_SOCONSTATE_FLAG_TX_TP_PENDING_MASK ((uint16)(1UL << SOAD_SOCONSTATE_FLAG_TX_TP_PENDING_SHIFT))


#if (defined SOAD_SOCONSTATE_FLAG_RX_TP_CANCELED_SHIFT) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_RX_TP_CANCELED_SHIFT already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_RX_TP_CANCELED_SHIFT) */

/** \brief The bit shift for socket connection upper flag SOAD_SOCONSTATE_FLAG_RX_TP_CANCELED */
#define SOAD_SOCONSTATE_FLAG_RX_TP_CANCELED_SHIFT 2U


#if (defined SOAD_SOCONSTATE_FLAG_RX_TP_CANCELED_MASK) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_RX_TP_CANCELED_MASK already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_RX_TP_CANCELED_MASK) */

/** \brief The bit mask for socket connection state upper flag SOAD_SOCONSTATE_FLAG_RX_TP_CANCELED */
#define SOAD_SOCONSTATE_FLAG_RX_TP_CANCELED_MASK ((uint16)(1UL << SOAD_SOCONSTATE_FLAG_RX_TP_CANCELED_SHIFT))


#if (defined SOAD_SOCONSTATE_FLAG_TX_TP_CANCELED_SHIFT) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_TX_TP_CANCELED_SHIFT already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_TX_TP_CANCELED_SHIFT) */

/** \brief The bit shift for socket connection upper flag SOAD_SOCONSTATE_FLAG_TX_TP_CANCELED */
#define SOAD_SOCONSTATE_FLAG_TX_TP_CANCELED_SHIFT 3U


#if (defined SOAD_SOCONSTATE_FLAG_TX_TP_CANCELED_MASK) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_TX_TP_CANCELED_MASK already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_TX_TP_CANCELED_MASK) */

/** \brief The bit mask for socket connection state upper flag SOAD_SOCONSTATE_FLAG_TX_TP_CANCELED */
#define SOAD_SOCONSTATE_FLAG_TX_TP_CANCELED_MASK ((uint16)(1UL << SOAD_SOCONSTATE_FLAG_TX_TP_CANCELED_SHIFT))


#if (defined SOAD_SOCONSTATE_FLAG_CLOSE_SOCON_SHIFT) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_CLOSE_SOCON_SHIFT already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_CLOSE_SOCON_SHIFT) */

/** \brief The bit shift for socket connection upper flag SOAD_SOCONSTATE_FLAG_CLOSE_SOCON */
#define SOAD_SOCONSTATE_FLAG_CLOSE_SOCON_SHIFT 4U


#if (defined SOAD_SOCONSTATE_FLAG_CLOSE_SOCON_MASK) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_CLOSE_SOCON_MASK already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_CLOSE_SOCON_MASK) */

/** \brief The bit mask for socket connection state upper flag SOAD_SOCONSTATE_FLAG_CLOSE_SOCON */
#define SOAD_SOCONSTATE_FLAG_CLOSE_SOCON_MASK ((uint16)(1UL << SOAD_SOCONSTATE_FLAG_CLOSE_SOCON_SHIFT))


#if (defined SOAD_SOCONSTATE_FLAG_CLOSE_SOCON_ABORT_SHIFT) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_CLOSE_SOCON_ABORT_SHIFT already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_CLOSE_SOCON_ABORT_SHIFT) */

/** \brief The bit shift for socket connection upper flag SOAD_SOCONSTATE_FLAG_CLOSE_SOCON_ABORT */
#define SOAD_SOCONSTATE_FLAG_CLOSE_SOCON_ABORT_SHIFT 5U


#if (defined SOAD_SOCONSTATE_FLAG_CLOSE_SOCON_ABORT_MASK) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_CLOSE_SOCON_ABORT_MASK already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_CLOSE_SOCON_ABORT_MASK) */

/** \brief The bit mask for socket connection state upper flag SOAD_SOCONSTATE_FLAG_CLOSE_SOCON_ABORT */
#define SOAD_SOCONSTATE_FLAG_CLOSE_SOCON_ABORT_MASK ((uint16)(1UL << SOAD_SOCONSTATE_FLAG_CLOSE_SOCON_ABORT_SHIFT))


#if (defined SOAD_SOCONSTATE_FLAG_TX_BUFFER_LOCK_SHIFT) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_TX_BUFFER_LOCK_SHIFT already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_TX_BUFFER_LOCK_SHIFT) */

/** \brief The bit shift for socket connection upper flag SOAD_SOCONSTATE_FLAG_TX_BUFFER_LOCK */
#define SOAD_SOCONSTATE_FLAG_TX_BUFFER_LOCK_SHIFT 6U


#if (defined SOAD_SOCONSTATE_FLAG_TX_BUFFER_LOCK_MASK) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_TX_BUFFER_LOCK_MASK already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_TX_BUFFER_LOCK_MASK) */

/** \brief The bit mask for socket connection state upper flag SOAD_SOCONSTATE_FLAG_TX_BUFFER_LOCK */
#define SOAD_SOCONSTATE_FLAG_TX_BUFFER_LOCK_MASK ((uint16)(1UL << SOAD_SOCONSTATE_FLAG_TX_BUFFER_LOCK_SHIFT))


#if (defined SOAD_SOCONSTATE_FLAG_TX_COPYTXDATA_SHIFT) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_TX_COPYTXDATA_SHIFT already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_TX_COPYTXDATA_SHIFT) */

/** \brief The bit shift for socket connection upper flag SOAD_SOCONSTATE_FLAG_TX_COPYTXDATA */
#define SOAD_SOCONSTATE_FLAG_TX_COPYTXDATA_SHIFT 7U


#if (defined SOAD_SOCONSTATE_FLAG_TX_COPYTXDATA_MASK) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_TX_COPYTXDATA_MASK already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_TX_COPYTXDATA_MASK) */

/** \brief The bit mask for socket connection state upper flag SOAD_SOCONSTATE_FLAG_TX_COPYTXDATA */
#define SOAD_SOCONSTATE_FLAG_TX_COPYTXDATA_MASK ((uint16)(1UL << SOAD_SOCONSTATE_FLAG_TX_COPYTXDATA_SHIFT))


#if (defined SOAD_SOCONSTATE_FLAG_TX_LOCK_SHIFT) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_TX_LOCK_SHIFT already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_TX_LOCK_SHIFT) */

/** \brief The bit shift for socket connection upper flag SOAD_SOCONSTATE_FLAG_TX_LOCK */
#define SOAD_SOCONSTATE_FLAG_TX_LOCK_SHIFT 8U


#if (defined SOAD_SOCONSTATE_FLAG_TX_LOCK_MASK) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_TX_LOCK_MASK already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_TX_LOCK_MASK) */

/** \brief The bit mask for socket connection state upper flag SOAD_SOCONSTATE_FLAG_TX_LOCK */
#define SOAD_SOCONSTATE_FLAG_TX_LOCK_MASK ((uint16)(1UL << SOAD_SOCONSTATE_FLAG_TX_LOCK_SHIFT))


#if (defined SOAD_SOCONSTATE_FLAG_USED_SETREMOTEADDR_SHIFT) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_USED_SETREMOTEADDR_SHIFT already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_USED_SETREMOTEADDR_SHIFT) */

/** \brief The bit shift for socket connection upper flag SOAD_SOCONSTATE_FLAG_USED_SETREMOTEADDR */
#define SOAD_SOCONSTATE_FLAG_USED_SETREMOTEADDR_SHIFT 9U


#if (defined SOAD_SOCONSTATE_FLAG_USED_SETREMOTEADDR_MASK) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_USED_SETREMOTEADDR_MASK already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_USED_SETREMOTEADDR_MASK) */

/** \brief The bit mask for socket connection state upper flag SOAD_SOCONSTATE_FLAG_USED_SETREMOTEADDR */
#define SOAD_SOCONSTATE_FLAG_USED_SETREMOTEADDR_MASK ((uint16)(1UL << SOAD_SOCONSTATE_FLAG_USED_SETREMOTEADDR_SHIFT))


#if (defined SOAD_SOCONSTATE_TXING_OK_SHIFT) /* To prevent double definition */
#error SOAD_SOCONSTATE_TXING_OK_SHIFT already defined!
#endif /* (defined SOAD_SOCONSTATE_TXING_OK_SHIFT) */

/** \brief The bit shift for socket connection upper flag SOAD_SOCONSTATE_TXING_OK */
#define SOAD_SOCONSTATE_TXING_OK_SHIFT 10U


#if (defined SOAD_SOCONSTATE_TXING_OK_MASK) /* To prevent double definition */
#error SOAD_SOCONSTATE_TXING_OK_MASK already defined!
#endif /* (defined SOAD_SOCONSTATE_TXING_OK_MASK) */

/** \brief The bit mask for socket connection state upper flag SOAD_SOCONSTATE_TXING_OK */
#define SOAD_SOCONSTATE_TXING_OK_MASK ((uint16)(1UL << SOAD_SOCONSTATE_TXING_OK_SHIFT))


#if (defined SOAD_SOCONSTATE_FLAG_TX_TP_NO_DATA_COPIED_SHIFT) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_TX_TP_NO_DATA_COPIED_SHIFT already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_TX_TP_NO_DATA_COPIED_SHIFT) */

/** \brief The bit shift for socket connection upper flag SOAD_SOCONSTATE_FLAG_TX_TP_NO_DATA_COPIED */
#define SOAD_SOCONSTATE_FLAG_TX_TP_NO_DATA_COPIED_SHIFT 11U


#if (defined SOAD_SOCONSTATE_FLAG_TX_TP_NO_DATA_COPIED_MASK) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_TX_TP_NO_DATA_COPIED_MASK already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_TX_TP_NO_DATA_COPIED_MASK) */

/** \brief The bit mask for socket connection state upper flag SOAD_SOCONSTATE_FLAG_TX_TP_NO_DATA_COPIED */
#define SOAD_SOCONSTATE_FLAG_TX_TP_NO_DATA_COPIED_MASK ((uint16)(1UL << SOAD_SOCONSTATE_FLAG_TX_TP_NO_DATA_COPIED_SHIFT))



#if (defined SOAD_SOCONGROUP_FLAG_UDP_SOCKET_IN_USE_SHIFT) /* To prevent double definition */
#error SOAD_SOCONGROUP_FLAG_UDP_SOCKET_IN_USE_SHIFT already defined!
#endif /* (defined SOAD_SOCONGROUP_FLAG_UDP_SOCKET_IN_USE_SHIFT) */

/** \brief The bit shift for socket connection group flag SOAD_SOCONGROUP_FLAG_UDP_SOCKET_IN_USE */
#define SOAD_SOCONGROUP_FLAG_UDP_SOCKET_IN_USE_SHIFT 0U


#if (defined SOAD_SOCONGROUP_FLAG_UDP_SOCKET_IN_USE_MASK) /* To prevent double definition */
#error SOAD_SOCONGROUP_FLAG_UDP_SOCKET_IN_USE_MASK already defined!
#endif /* (defined SOAD_SOCONGROUP_FLAG_UDP_SOCKET_IN_USE_MASK) */

/** \brief The bit mask for socket connection group flag SOAD_SOCONGROUP_FLAG_UDP_SOCKET_IN_USE */
#define SOAD_SOCONGROUP_FLAG_UDP_SOCKET_IN_USE_MASK ((uint8)(1UL << SOAD_SOCONGROUP_FLAG_UDP_SOCKET_IN_USE_SHIFT))



#if (defined SOAD_SOCONSTATE_FLAG_RX_DATA_BUFFERED_SHIFT) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_RX_DATA_BUFFERED_SHIFT already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_RX_DATA_BUFFERED_SHIFT) */

/** \brief The bit shift for socket connection state lower flag SOAD_SOCONSTATE_FLAG_RX_DATA_BUFFERED */
#define SOAD_SOCONSTATE_FLAG_RX_DATA_BUFFERED_SHIFT 0U


#if (defined SOAD_SOCONSTATE_FLAG_RX_DATA_BUFFERED_MASK) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_RX_DATA_BUFFERED_MASK already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_RX_DATA_BUFFERED_MASK) */

/** \brief The bit mask for socket connection state lower flag SOAD_SOCONSTATE_FLAG_RX_DATA_BUFFERED */
#define SOAD_SOCONSTATE_FLAG_RX_DATA_BUFFERED_MASK ((uint8)(1UL << SOAD_SOCONSTATE_FLAG_RX_DATA_BUFFERED_SHIFT))


#if (defined SOAD_SOCONSTATE_FLAG_RX_TCP_SEGMENTED_SHIFT) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_RX_TCP_SEGMENTED_SHIFT already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_RX_TCP_SEGMENTED_SHIFT) */

/** \brief The bit shift for socket connection state lower flag SOAD_SOCONSTATE_FLAG_RX_TCP_SEGMENTED */
#define SOAD_SOCONSTATE_FLAG_RX_TCP_SEGMENTED_SHIFT 1U


#if (defined SOAD_SOCONSTATE_FLAG_RX_TCP_SEGMENTED_MASK) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_RX_TCP_SEGMENTED_MASK already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_RX_TCP_SEGMENTED_MASK) */

/** \brief The bit mask for socket connection state lower flag SOAD_SOCONSTATE_FLAG_RX_TCP_SEGMENTED */
#define SOAD_SOCONSTATE_FLAG_RX_TCP_SEGMENTED_MASK ((uint8)(1UL << SOAD_SOCONSTATE_FLAG_RX_TCP_SEGMENTED_SHIFT))


#if (defined SOAD_SOCONSTATE_FLAG_TX_UDP_RETRY_SHIFT) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_TX_UDP_RETRY_SHIFT already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_TX_UDP_RETRY_SHIFT) */

/** \brief The bit shift for socket connection state lower flag SOAD_SOCONSTATE_FLAG_TX_UDP_RETRY */
#define SOAD_SOCONSTATE_FLAG_TX_UDP_RETRY_SHIFT 2U


#if (defined SOAD_SOCONSTATE_FLAG_TX_UDP_RETRY_MASK) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_TX_UDP_RETRY_MASK already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_TX_UDP_RETRY_MASK) */

/** \brief The bit mask for socket connection state lower flag SOAD_SOCONSTATE_FLAG_TX_UDP_RETRY */
#define SOAD_SOCONSTATE_FLAG_TX_UDP_RETRY_MASK ((uint8)(1UL << SOAD_SOCONSTATE_FLAG_TX_UDP_RETRY_SHIFT))


#if (defined SOAD_SOCONSTATE_FLAG_TCPIP_SOCKET_CLOSED_SHIFT) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_TCPIP_SOCKET_CLOSED_SHIFT already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_TCPIP_SOCKET_CLOSED_SHIFT) */

/** \brief The bit shift for socket connection state lower flag SOAD_SOCONSTATE_FLAG_TCPIP_SOCKET_CLOSED */
#define SOAD_SOCONSTATE_FLAG_TCPIP_SOCKET_CLOSED_SHIFT 3U


#if (defined SOAD_SOCONSTATE_FLAG_TCPIP_SOCKET_CLOSED_MASK) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_TCPIP_SOCKET_CLOSED_MASK already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_TCPIP_SOCKET_CLOSED_MASK) */

/** \brief The bit mask for socket connection state lower flag SOAD_SOCONSTATE_FLAG_TCPIP_SOCKET_CLOSED */
#define SOAD_SOCONSTATE_FLAG_TCPIP_SOCKET_CLOSED_MASK ((uint8)(1UL << SOAD_SOCONSTATE_FLAG_TCPIP_SOCKET_CLOSED_SHIFT))


#if (defined SOAD_SOCONSTATE_FLAG_TXCONF_PENDING_SHIFT) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_TXCONF_PENDING_SHIFT already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_TXCONF_PENDING_SHIFT) */

/** \brief The bit shift for socket connection state lower flag SOAD_SOCONSTATE_FLAG_TXCONF_PENDING */
#define SOAD_SOCONSTATE_FLAG_TXCONF_PENDING_SHIFT 4U


#if (defined SOAD_SOCONSTATE_FLAG_TXCONF_PENDING_MASK) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_TXCONF_PENDING_MASK already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_TXCONF_PENDING_MASK) */

/** \brief The bit mask for socket connection state lower flag SOAD_SOCONSTATE_FLAG_TXCONF_PENDING */
#define SOAD_SOCONSTATE_FLAG_TXCONF_PENDING_MASK ((uint8)(1UL << SOAD_SOCONSTATE_FLAG_TXCONF_PENDING_SHIFT))


#if (defined SOAD_SOCONSTATE_FLAG_RXTX_PROGRESS_SHIFT) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_RXTX_PROGRESS_SHIFT already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_RXTX_PROGRESS_SHIFT) */

/** \brief The bit shift for socket connection state lower flag SOAD_SOCONSTATE_FLAG_RXTX_PROGRESS */
#define SOAD_SOCONSTATE_FLAG_RXTX_PROGRESS_SHIFT 5U


#if (defined SOAD_SOCONSTATE_FLAG_RXTX_PROGRESS_MASK) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_RXTX_PROGRESS_MASK already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_RXTX_PROGRESS_MASK) */

/** \brief The bit mask for socket connection state lower flag SOAD_SOCONSTATE_FLAG_RXTX_PROGRESS */
#define SOAD_SOCONSTATE_FLAG_RXTX_PROGRESS_MASK ((uint8)(1UL << SOAD_SOCONSTATE_FLAG_RXTX_PROGRESS_SHIFT))


#if (defined SOAD_SOCONSTATE_FLAG_RECONNECT_SOCKET_SHIFT) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_RECONNECT_SOCKET_SHIFT already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_RECONNECT_SOCKET_SHIFT) */

/** \brief The bit shift for socket connection state lower flag SOAD_SOCONSTATE_FLAG_RECONNECT_SOCKET */
#define SOAD_SOCONSTATE_FLAG_RECONNECT_SOCKET_SHIFT 6U


#if (defined SOAD_SOCONSTATE_FLAG_RECONNECT_SOCKET_MASK) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_RECONNECT_SOCKET_MASK already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_RECONNECT_SOCKET_MASK) */

/** \brief The bit mask for socket connection state lower flag SOAD_SOCONSTATE_FLAG_RECONNECT_SOCKET */
#define SOAD_SOCONSTATE_FLAG_RECONNECT_SOCKET_MASK ((uint8)(1UL << SOAD_SOCONSTATE_FLAG_RECONNECT_SOCKET_SHIFT))


#if (defined SOAD_SOCONSTATE_FLAG_TCP_FIN_RECEIVED_SHIFT) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_TCP_FIN_RECEIVED_SHIFT already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_TCP_FIN_RECEIVED_SHIFT) */

/** \brief The bit shift for socket connection state lower flag SOAD_SOCONSTATE_FLAG_TCP_FIN_RECEIVED */
#define SOAD_SOCONSTATE_FLAG_TCP_FIN_RECEIVED_SHIFT 7U


#if (defined SOAD_SOCONSTATE_FLAG_TCP_FIN_RECEIVED_MASK) /* To prevent double definition */
#error SOAD_SOCONSTATE_FLAG_TCP_FIN_RECEIVED_MASK already defined!
#endif /* (defined SOAD_SOCONSTATE_FLAG_TCP_FIN_RECEIVED_MASK) */

/** \brief The bit mask for socket connection state lower flag SOAD_SOCONSTATE_FLAG_TCP_FIN_RECEIVED */
#define SOAD_SOCONSTATE_FLAG_TCP_FIN_RECEIVED_MASK ((uint8)(1UL << SOAD_SOCONSTATE_FLAG_TCP_FIN_RECEIVED_SHIFT))



#if (defined SOAD_SOCON_FLAG_AUTO_SETUP_SHIFT) /* To prevent double definition */
#error SOAD_SOCON_FLAG_AUTO_SETUP_SHIFT already defined!
#endif /* (defined SOAD_SOCON_FLAG_AUTO_SETUP_SHIFT) */

/** \brief The bit shift for socket connection flag SOAD_SOCON_FLAG_AUTO_SETUP */
#define SOAD_SOCON_FLAG_AUTO_SETUP_SHIFT 0U


#if (defined SOAD_SOCON_FLAG_AUTO_SETUP_MASK) /* To prevent double definition */
#error SOAD_SOCON_FLAG_AUTO_SETUP_MASK already defined!
#endif /* (defined SOAD_SOCON_FLAG_AUTO_SETUP_MASK) */

/** \brief The bit mask for socket connection flag SOAD_SOCON_FLAG_AUTO_SETUP */
#define SOAD_SOCON_FLAG_AUTO_SETUP_MASK ((uint16)(1UL << SOAD_SOCON_FLAG_AUTO_SETUP_SHIFT))


#if (defined SOAD_SOCON_FLAG_SOCKET_TCP_KEEP_ALIVE_SHIFT) /* To prevent double definition */
#error SOAD_SOCON_FLAG_SOCKET_TCP_KEEP_ALIVE_SHIFT already defined!
#endif /* (defined SOAD_SOCON_FLAG_SOCKET_TCP_KEEP_ALIVE_SHIFT) */

/** \brief The bit shift for socket connection flag SOAD_SOCON_FLAG_SOCKET_TCP_KEEP_ALIVE */
#define SOAD_SOCON_FLAG_SOCKET_TCP_KEEP_ALIVE_SHIFT 1U


#if (defined SOAD_SOCON_FLAG_SOCKET_TCP_KEEP_ALIVE_MASK) /* To prevent double definition */
#error SOAD_SOCON_FLAG_SOCKET_TCP_KEEP_ALIVE_MASK already defined!
#endif /* (defined SOAD_SOCON_FLAG_SOCKET_TCP_KEEP_ALIVE_MASK) */

/** \brief The bit mask for socket connection flag SOAD_SOCON_FLAG_SOCKET_TCP_KEEP_ALIVE */
#define SOAD_SOCON_FLAG_SOCKET_TCP_KEEP_ALIVE_MASK ((uint16)(1UL << SOAD_SOCON_FLAG_SOCKET_TCP_KEEP_ALIVE_SHIFT))


#if (defined SOAD_SOCON_FLAG_UDP_STRICT_HEADER_LEN_CHECK_SHIFT) /* To prevent double definition */
#error SOAD_SOCON_FLAG_UDP_STRICT_HEADER_LEN_CHECK_SHIFT already defined!
#endif /* (defined SOAD_SOCON_FLAG_UDP_STRICT_HEADER_LEN_CHECK_SHIFT) */

/** \brief The bit shift for socket connection flag SOAD_SOCON_FLAG_UDP_STRICT_HEADER_LEN_CHECK */
#define SOAD_SOCON_FLAG_UDP_STRICT_HEADER_LEN_CHECK_SHIFT 2U


#if (defined SOAD_SOCON_FLAG_UDP_STRICT_HEADER_LEN_CHECK_MASK) /* To prevent double definition */
#error SOAD_SOCON_FLAG_UDP_STRICT_HEADER_LEN_CHECK_MASK already defined!
#endif /* (defined SOAD_SOCON_FLAG_UDP_STRICT_HEADER_LEN_CHECK_MASK) */

/** \brief The bit mask for socket connection flag SOAD_SOCON_FLAG_UDP_STRICT_HEADER_LEN_CHECK */
#define SOAD_SOCON_FLAG_UDP_STRICT_HEADER_LEN_CHECK_MASK ((uint16)(1UL << SOAD_SOCON_FLAG_UDP_STRICT_HEADER_LEN_CHECK_SHIFT))


#if (defined SOAD_SOCON_FLAG_IS_PDU_HEADER_MODE_SHIFT) /* To prevent double definition */
#error SOAD_SOCON_FLAG_IS_PDU_HEADER_MODE_SHIFT already defined!
#endif /* (defined SOAD_SOCON_FLAG_IS_PDU_HEADER_MODE_SHIFT) */

/** \brief The bit shift for socket connection flag SOAD_SOCON_FLAG_IS_PDU_HEADER_MODE */
#define SOAD_SOCON_FLAG_IS_PDU_HEADER_MODE_SHIFT 3U


#if (defined SOAD_SOCON_FLAG_IS_PDU_HEADER_MODE_MASK) /* To prevent double definition */
#error SOAD_SOCON_FLAG_IS_PDU_HEADER_MODE_MASK already defined!
#endif /* (defined SOAD_SOCON_FLAG_IS_PDU_HEADER_MODE_MASK) */

/** \brief The bit mask for socket connection flag SOAD_SOCON_FLAG_IS_PDU_HEADER_MODE */
#define SOAD_SOCON_FLAG_IS_PDU_HEADER_MODE_MASK ((uint16)(1UL << SOAD_SOCON_FLAG_IS_PDU_HEADER_MODE_SHIFT))


#if (defined SOAD_SOCON_FLAG_IS_TCP_SHIFT) /* To prevent double definition */
#error SOAD_SOCON_FLAG_IS_TCP_SHIFT already defined!
#endif /* (defined SOAD_SOCON_FLAG_IS_TCP_SHIFT) */

/** \brief The bit shift for socket connection flag SOAD_SOCON_FLAG_IS_TCP */
#define SOAD_SOCON_FLAG_IS_TCP_SHIFT 4U


#if (defined SOAD_SOCON_FLAG_IS_TCP_MASK) /* To prevent double definition */
#error SOAD_SOCON_FLAG_IS_TCP_MASK already defined!
#endif /* (defined SOAD_SOCON_FLAG_IS_TCP_MASK) */

/** \brief The bit mask for socket connection flag SOAD_SOCON_FLAG_IS_TCP */
#define SOAD_SOCON_FLAG_IS_TCP_MASK ((uint16)(1UL << SOAD_SOCON_FLAG_IS_TCP_SHIFT))


#if (defined SOAD_SOCON_FLAG_IS_TCP_INITIATE_SHIFT) /* To prevent double definition */
#error SOAD_SOCON_FLAG_IS_TCP_INITIATE_SHIFT already defined!
#endif /* (defined SOAD_SOCON_FLAG_IS_TCP_INITIATE_SHIFT) */

/** \brief The bit shift for socket connection flag SOAD_SOCON_FLAG_IS_TCP_INITIATE */
#define SOAD_SOCON_FLAG_IS_TCP_INITIATE_SHIFT 5U


#if (defined SOAD_SOCON_FLAG_IS_TCP_INITIATE_MASK) /* To prevent double definition */
#error SOAD_SOCON_FLAG_IS_TCP_INITIATE_MASK already defined!
#endif /* (defined SOAD_SOCON_FLAG_IS_TCP_INITIATE_MASK) */

/** \brief The bit mask for socket connection flag SOAD_SOCON_FLAG_IS_TCP_INITIATE */
#define SOAD_SOCON_FLAG_IS_TCP_INITIATE_MASK ((uint16)(1UL << SOAD_SOCON_FLAG_IS_TCP_INITIATE_SHIFT))


#if (defined SOAD_SOCON_FLAG_IS_TCP_NO_DELAY_SHIFT) /* To prevent double definition */
#error SOAD_SOCON_FLAG_IS_TCP_NO_DELAY_SHIFT already defined!
#endif /* (defined SOAD_SOCON_FLAG_IS_TCP_NO_DELAY_SHIFT) */

/** \brief The bit shift for socket connection flag SOAD_SOCON_FLAG_IS_TCP_NO_DELAY */
#define SOAD_SOCON_FLAG_IS_TCP_NO_DELAY_SHIFT 6U


#if (defined SOAD_SOCON_FLAG_IS_TCP_NO_DELAY_MASK) /* To prevent double definition */
#error SOAD_SOCON_FLAG_IS_TCP_NO_DELAY_MASK already defined!
#endif /* (defined SOAD_SOCON_FLAG_IS_TCP_NO_DELAY_MASK) */

/** \brief The bit mask for socket connection flag SOAD_SOCON_FLAG_IS_TCP_NO_DELAY */
#define SOAD_SOCON_FLAG_IS_TCP_NO_DELAY_MASK ((uint16)(1UL << SOAD_SOCON_FLAG_IS_TCP_NO_DELAY_SHIFT))


#if (defined SOAD_SOCON_FLAG_IS_UDP_LISTEN_ONLY_SHIFT) /* To prevent double definition */
#error SOAD_SOCON_FLAG_IS_UDP_LISTEN_ONLY_SHIFT already defined!
#endif /* (defined SOAD_SOCON_FLAG_IS_UDP_LISTEN_ONLY_SHIFT) */

/** \brief The bit shift for socket connection flag SOAD_SOCON_FLAG_IS_UDP_LISTEN_ONLY */
#define SOAD_SOCON_FLAG_IS_UDP_LISTEN_ONLY_SHIFT 7U


#if (defined SOAD_SOCON_FLAG_IS_UDP_LISTEN_ONLY_MASK) /* To prevent double definition */
#error SOAD_SOCON_FLAG_IS_UDP_LISTEN_ONLY_MASK already defined!
#endif /* (defined SOAD_SOCON_FLAG_IS_UDP_LISTEN_ONLY_MASK) */

/** \brief The bit mask for socket connection flag SOAD_SOCON_FLAG_IS_UDP_LISTEN_ONLY */
#define SOAD_SOCON_FLAG_IS_UDP_LISTEN_ONLY_MASK ((uint16)(1UL << SOAD_SOCON_FLAG_IS_UDP_LISTEN_ONLY_SHIFT))


#if (defined SOAD_SOCON_FLAG_IS_UDP_RETRY_SHIFT) /* To prevent double definition */
#error SOAD_SOCON_FLAG_IS_UDP_RETRY_SHIFT already defined!
#endif /* (defined SOAD_SOCON_FLAG_IS_UDP_RETRY_SHIFT) */

/** \brief The bit shift for socket connection flag SOAD_SOCON_FLAG_IS_UDP_RETRY */
#define SOAD_SOCON_FLAG_IS_UDP_RETRY_SHIFT 8U


#if (defined SOAD_SOCON_FLAG_IS_UDP_RETRY_MASK) /* To prevent double definition */
#error SOAD_SOCON_FLAG_IS_UDP_RETRY_MASK already defined!
#endif /* (defined SOAD_SOCON_FLAG_IS_UDP_RETRY_MASK) */

/** \brief The bit mask for socket connection flag SOAD_SOCON_FLAG_IS_UDP_RETRY */
#define SOAD_SOCON_FLAG_IS_UDP_RETRY_MASK ((uint16)(1UL << SOAD_SOCON_FLAG_IS_UDP_RETRY_SHIFT))


#if (defined SOAD_SOCON_FLAG_NOTIFY_LOCALIPADDRCHG_SHIFT) /* To prevent double definition */
#error SOAD_SOCON_FLAG_NOTIFY_LOCALIPADDRCHG_SHIFT already defined!
#endif /* (defined SOAD_SOCON_FLAG_NOTIFY_LOCALIPADDRCHG_SHIFT) */

/** \brief The bit shift for socket connection flag SOAD_SOCON_FLAG_NOTIFY_LOCALIPADDRCHG */
#define SOAD_SOCON_FLAG_NOTIFY_LOCALIPADDRCHG_SHIFT 9U


#if (defined SOAD_SOCON_FLAG_NOTIFY_LOCALIPADDRCHG_MASK) /* To prevent double definition */
#error SOAD_SOCON_FLAG_NOTIFY_LOCALIPADDRCHG_MASK already defined!
#endif /* (defined SOAD_SOCON_FLAG_NOTIFY_LOCALIPADDRCHG_MASK) */

/** \brief The bit mask for socket connection flag SOAD_SOCON_FLAG_NOTIFY_LOCALIPADDRCHG */
#define SOAD_SOCON_FLAG_NOTIFY_LOCALIPADDRCHG_MASK ((uint16)(1UL << SOAD_SOCON_FLAG_NOTIFY_LOCALIPADDRCHG_SHIFT))


#if (defined SOAD_SOCON_FLAG_NOTIFY_SOCONMODECHG_SHIFT) /* To prevent double definition */
#error SOAD_SOCON_FLAG_NOTIFY_SOCONMODECHG_SHIFT already defined!
#endif /* (defined SOAD_SOCON_FLAG_NOTIFY_SOCONMODECHG_SHIFT) */

/** \brief The bit shift for socket connection flag SOAD_SOCON_FLAG_NOTIFY_SOCONMODECHG */
#define SOAD_SOCON_FLAG_NOTIFY_SOCONMODECHG_SHIFT 10U


#if (defined SOAD_SOCON_FLAG_NOTIFY_SOCONMODECHG_MASK) /* To prevent double definition */
#error SOAD_SOCON_FLAG_NOTIFY_SOCONMODECHG_MASK already defined!
#endif /* (defined SOAD_SOCON_FLAG_NOTIFY_SOCONMODECHG_MASK) */

/** \brief The bit mask for socket connection flag SOAD_SOCON_FLAG_NOTIFY_SOCONMODECHG */
#define SOAD_SOCON_FLAG_NOTIFY_SOCONMODECHG_MASK ((uint16)(1UL << SOAD_SOCON_FLAG_NOTIFY_SOCONMODECHG_SHIFT))


#if (defined SOAD_SOCON_FLAG_REMOTE_SET_SHIFT) /* To prevent double definition */
#error SOAD_SOCON_FLAG_REMOTE_SET_SHIFT already defined!
#endif /* (defined SOAD_SOCON_FLAG_REMOTE_SET_SHIFT) */

/** \brief The bit shift for socket connection flag SOAD_SOCON_FLAG_REMOTE_SET */
#define SOAD_SOCON_FLAG_REMOTE_SET_SHIFT 11U


#if (defined SOAD_SOCON_FLAG_REMOTE_SET_MASK) /* To prevent double definition */
#error SOAD_SOCON_FLAG_REMOTE_SET_MASK already defined!
#endif /* (defined SOAD_SOCON_FLAG_REMOTE_SET_MASK) */

/** \brief The bit mask for socket connection flag SOAD_SOCON_FLAG_REMOTE_SET */
#define SOAD_SOCON_FLAG_REMOTE_SET_MASK ((uint16)(1UL << SOAD_SOCON_FLAG_REMOTE_SET_SHIFT))


#if (defined SOAD_SOCON_FLAG_NO_MSG_FILTER_SHIFT) /* To prevent double definition */
#error SOAD_SOCON_FLAG_NO_MSG_FILTER_SHIFT already defined!
#endif /* (defined SOAD_SOCON_FLAG_NO_MSG_FILTER_SHIFT) */

/** \brief The bit shift for socket connection flag SOAD_SOCON_FLAG_NO_MSG_FILTER */
#define SOAD_SOCON_FLAG_NO_MSG_FILTER_SHIFT 12U


#if (defined SOAD_SOCON_FLAG_NO_MSG_FILTER_MASK) /* To prevent double definition */
#error SOAD_SOCON_FLAG_NO_MSG_FILTER_MASK already defined!
#endif /* (defined SOAD_SOCON_FLAG_NO_MSG_FILTER_MASK) */

/** \brief The bit mask for socket connection flag SOAD_SOCON_FLAG_NO_MSG_FILTER */
#define SOAD_SOCON_FLAG_NO_MSG_FILTER_MASK ((uint16)(1UL << SOAD_SOCON_FLAG_NO_MSG_FILTER_SHIFT))


#if (defined SOAD_SOCON_FLAG_IS_TCP_IMMEDIATE_TP_TXCONF_SHIFT) /* To prevent double definition */
#error SOAD_SOCON_FLAG_IS_TCP_IMMEDIATE_TP_TXCONF_SHIFT already defined!
#endif /* (defined SOAD_SOCON_FLAG_IS_TCP_IMMEDIATE_TP_TXCONF_SHIFT) */

/** \brief The bit shift for socket connection flag SOAD_SOCON_FLAG_IS_TCP_IMMEDIATE_TP_TXCONF */
#define SOAD_SOCON_FLAG_IS_TCP_IMMEDIATE_TP_TXCONF_SHIFT 13U


#if (defined SOAD_SOCON_FLAG_IS_TCP_IMMEDIATE_TP_TXCONF_MASK) /* To prevent double definition */
#error SOAD_SOCON_FLAG_IS_TCP_IMMEDIATE_TP_TXCONF_MASK already defined!
#endif /* (defined SOAD_SOCON_FLAG_IS_TCP_IMMEDIATE_TP_TXCONF_MASK) */

/** \brief The bit mask for socket connection flag SOAD_SOCON_FLAG_IS_TCP_IMMEDIATE_TP_TXCONF */
#define SOAD_SOCON_FLAG_IS_TCP_IMMEDIATE_TP_TXCONF_MASK ((uint16)(1UL << SOAD_SOCON_FLAG_IS_TCP_IMMEDIATE_TP_TXCONF_SHIFT))


#if (defined SOAD_SOCON_FLAG_NPDUUDPTXBUFFER_SHIFT) /* To prevent double definition */
#error SOAD_SOCON_FLAG_NPDUUDPTXBUFFER_SHIFT already defined!
#endif /* (defined SOAD_SOCON_FLAG_NPDUUDPTXBUFFER_SHIFT) */

/** \brief The bit shift for socket connection flag SOAD_SOCON_FLAG_NPDUUDPTXBUFFER */
#define SOAD_SOCON_FLAG_NPDUUDPTXBUFFER_SHIFT 14U


#if (defined SOAD_SOCON_FLAG_NPDUUDPTXBUFFER_MASK) /* To prevent double definition */
#error SOAD_SOCON_FLAG_NPDUUDPTXBUFFER_MASK already defined!
#endif /* (defined SOAD_SOCON_FLAG_NPDUUDPTXBUFFER_MASK) */

/** \brief The bit mask for socket connection flag SOAD_SOCON_FLAG_NPDUUDPTXBUFFER */
#define SOAD_SOCON_FLAG_NPDUUDPTXBUFFER_MASK ((uint16)(1UL << SOAD_SOCON_FLAG_NPDUUDPTXBUFFER_SHIFT))


#if (defined SOAD_SOCON_FLAG_IS_IPV6_SHIFT) /* To prevent double definition */
#error SOAD_SOCON_FLAG_IS_IPV6_SHIFT already defined!
#endif /* (defined SOAD_SOCON_FLAG_IS_IPV6_SHIFT) */

/** \brief The bit shift for socket connection flag SOAD_SOCON_FLAG_IS_IPV6 */
#define SOAD_SOCON_FLAG_IS_IPV6_SHIFT 15U


#if (defined SOAD_SOCON_FLAG_IS_IPV6_MASK) /* To prevent double definition */
#error SOAD_SOCON_FLAG_IS_IPV6_MASK already defined!
#endif /* (defined SOAD_SOCON_FLAG_IS_IPV6_MASK) */

/** \brief The bit mask for socket connection flag SOAD_SOCON_FLAG_IS_IPV6 */
#define SOAD_SOCON_FLAG_IS_IPV6_MASK ((uint16)(1UL << SOAD_SOCON_FLAG_IS_IPV6_SHIFT))



#if (defined SOAD_PDUROUTE_FLAG_IS_UL_TP_SHIFT) /* To prevent double definition */
#error SOAD_PDUROUTE_FLAG_IS_UL_TP_SHIFT already defined!
#endif /* (defined SOAD_PDUROUTE_FLAG_IS_UL_TP_SHIFT) */

/** \brief The bit shift for route flag SOAD_PDUROUTE_FLAG_IS_UL_TP */
#define SOAD_PDUROUTE_FLAG_IS_UL_TP_SHIFT 0U


#if (defined SOAD_PDUROUTE_FLAG_IS_UL_TP_MASK) /* To prevent double definition */
#error SOAD_PDUROUTE_FLAG_IS_UL_TP_MASK already defined!
#endif /* (defined SOAD_PDUROUTE_FLAG_IS_UL_TP_MASK) */

/** \brief The bit mask for route flag SOAD_PDUROUTE_FLAG_IS_UL_TP */
#define SOAD_PDUROUTE_FLAG_IS_UL_TP_MASK ((uint8)(1UL << SOAD_PDUROUTE_FLAG_IS_UL_TP_SHIFT))


#if (defined SOAD_PDUROUTE_FLAG_LAST_IS_BEST_SHIFT) /* To prevent double definition */
#error SOAD_PDUROUTE_FLAG_LAST_IS_BEST_SHIFT already defined!
#endif /* (defined SOAD_PDUROUTE_FLAG_LAST_IS_BEST_SHIFT) */

/** \brief The bit shift for route flag SOAD_PDUROUTE_FLAG_LAST_IS_BEST */
#define SOAD_PDUROUTE_FLAG_LAST_IS_BEST_SHIFT 1U


#if (defined SOAD_PDUROUTE_FLAG_LAST_IS_BEST_MASK) /* To prevent double definition */
#error SOAD_PDUROUTE_FLAG_LAST_IS_BEST_MASK already defined!
#endif /* (defined SOAD_PDUROUTE_FLAG_LAST_IS_BEST_MASK) */

/** \brief The bit mask for route flag SOAD_PDUROUTE_FLAG_LAST_IS_BEST */
#define SOAD_PDUROUTE_FLAG_LAST_IS_BEST_MASK ((uint8)(1UL << SOAD_PDUROUTE_FLAG_LAST_IS_BEST_SHIFT))


#if (defined SOAD_PDUROUTE_FLAG_METADATA_SOCON_ID_SHIFT) /* To prevent double definition */
#error SOAD_PDUROUTE_FLAG_METADATA_SOCON_ID_SHIFT already defined!
#endif /* (defined SOAD_PDUROUTE_FLAG_METADATA_SOCON_ID_SHIFT) */

/** \brief The bit shift for route flag SOAD_PDUROUTE_FLAG_METADATA_SOCON_ID */
#define SOAD_PDUROUTE_FLAG_METADATA_SOCON_ID_SHIFT 2U


#if (defined SOAD_PDUROUTE_FLAG_METADATA_SOCON_ID_MASK) /* To prevent double definition */
#error SOAD_PDUROUTE_FLAG_METADATA_SOCON_ID_MASK already defined!
#endif /* (defined SOAD_PDUROUTE_FLAG_METADATA_SOCON_ID_MASK) */

/** \brief The bit mask for route flag SOAD_PDUROUTE_FLAG_METADATA_SOCON_ID */
#define SOAD_PDUROUTE_FLAG_METADATA_SOCON_ID_MASK ((uint8)(1UL << SOAD_PDUROUTE_FLAG_METADATA_SOCON_ID_SHIFT))


#if (defined SOAD_PDUROUTE_FLAG_SKIP_IF_TXCONF_SHIFT) /* To prevent double definition */
#error SOAD_PDUROUTE_FLAG_SKIP_IF_TXCONF_SHIFT already defined!
#endif /* (defined SOAD_PDUROUTE_FLAG_SKIP_IF_TXCONF_SHIFT) */

/** \brief The bit shift for route flag SOAD_PDUROUTE_FLAG_SKIP_IF_TXCONF */
#define SOAD_PDUROUTE_FLAG_SKIP_IF_TXCONF_SHIFT 3U


#if (defined SOAD_PDUROUTE_FLAG_SKIP_IF_TXCONF_MASK) /* To prevent double definition */
#error SOAD_PDUROUTE_FLAG_SKIP_IF_TXCONF_MASK already defined!
#endif /* (defined SOAD_PDUROUTE_FLAG_SKIP_IF_TXCONF_MASK) */

/** \brief The bit mask for route flag SOAD_PDUROUTE_FLAG_SKIP_IF_TXCONF */
#define SOAD_PDUROUTE_FLAG_SKIP_IF_TXCONF_MASK ((uint8)(1UL << SOAD_PDUROUTE_FLAG_SKIP_IF_TXCONF_SHIFT))


#if (defined SOAD_SOCKETROUTE_FLAG_IS_UL_TP_SHIFT) /* To prevent double definition */
#error SOAD_SOCKETROUTE_FLAG_IS_UL_TP_SHIFT already defined!
#endif /* (defined SOAD_SOCKETROUTE_FLAG_IS_UL_TP_SHIFT) */

/** \brief The bit shift for route flag SOAD_SOCKETROUTE_FLAG_IS_UL_TP */
#define SOAD_SOCKETROUTE_FLAG_IS_UL_TP_SHIFT 0U


#if (defined SOAD_SOCKETROUTE_FLAG_IS_UL_TP_MASK) /* To prevent double definition */
#error SOAD_SOCKETROUTE_FLAG_IS_UL_TP_MASK already defined!
#endif /* (defined SOAD_SOCKETROUTE_FLAG_IS_UL_TP_MASK) */

/** \brief The bit mask for route flag SOAD_SOCKETROUTE_FLAG_IS_UL_TP */
#define SOAD_SOCKETROUTE_FLAG_IS_UL_TP_MASK ((uint8)(1UL << SOAD_SOCKETROUTE_FLAG_IS_UL_TP_SHIFT))


#if (defined SOAD_SOCKETROUTE_FLAG_IS_GROUPROUTE_SHIFT) /* To prevent double definition */
#error SOAD_SOCKETROUTE_FLAG_IS_GROUPROUTE_SHIFT already defined!
#endif /* (defined SOAD_SOCKETROUTE_FLAG_IS_GROUPROUTE_SHIFT) */

/** \brief The bit shift for route flag SOAD_SOCKETROUTE_FLAG_IS_GROUPROUTE */
#define SOAD_SOCKETROUTE_FLAG_IS_GROUPROUTE_SHIFT 1U


#if (defined SOAD_SOCKETROUTE_FLAG_IS_GROUPROUTE_MASK) /* To prevent double definition */
#error SOAD_SOCKETROUTE_FLAG_IS_GROUPROUTE_MASK already defined!
#endif /* (defined SOAD_SOCKETROUTE_FLAG_IS_GROUPROUTE_MASK) */

/** \brief The bit mask for route flag SOAD_SOCKETROUTE_FLAG_IS_GROUPROUTE */
#define SOAD_SOCKETROUTE_FLAG_IS_GROUPROUTE_MASK ((uint8)(1UL << SOAD_SOCKETROUTE_FLAG_IS_GROUPROUTE_SHIFT))


#if (defined SOAD_SOCKETROUTE_FLAG_METADATA_SOCON_ID_SHIFT) /* To prevent double definition */
#error SOAD_SOCKETROUTE_FLAG_METADATA_SOCON_ID_SHIFT already defined!
#endif /* (defined SOAD_SOCKETROUTE_FLAG_METADATA_SOCON_ID_SHIFT) */

/** \brief The bit shift for route flag SOAD_SOCKETROUTE_FLAG_METADATA_SOCON_ID */
#define SOAD_SOCKETROUTE_FLAG_METADATA_SOCON_ID_SHIFT 2U


#if (defined SOAD_SOCKETROUTE_FLAG_METADATA_SOCON_ID_MASK) /* To prevent double definition */
#error SOAD_SOCKETROUTE_FLAG_METADATA_SOCON_ID_MASK already defined!
#endif /* (defined SOAD_SOCKETROUTE_FLAG_METADATA_SOCON_ID_MASK) */

/** \brief The bit mask for route flag SOAD_SOCKETROUTE_FLAG_METADATA_SOCON_ID */
#define SOAD_SOCKETROUTE_FLAG_METADATA_SOCON_ID_MASK ((uint8)(1UL << SOAD_SOCKETROUTE_FLAG_METADATA_SOCON_ID_SHIFT))



#if (defined SOAD_SOCKETSTATE_CLOSED) /* To prevent double definition */
#error SOAD_SOCKETSTATE_CLOSED already defined!
#endif /* (defined SOAD_SOCKETSTATE_CLOSED) */

/** \brief Value of SoAd_SocketStateType SOAD_SOCKETSTATE_CLOSED */
#define SOAD_SOCKETSTATE_CLOSED 0U


#if (defined SOAD_SOCKETSTATE_CONNECTING) /* To prevent double definition */
#error SOAD_SOCKETSTATE_CONNECTING already defined!
#endif /* (defined SOAD_SOCKETSTATE_CONNECTING) */

/** \brief Value of SoAd_SocketStateType SOAD_SOCKETSTATE_CONNECTING */
#define SOAD_SOCKETSTATE_CONNECTING 1U


#if (defined SOAD_SOCKETSTATE_CONNECTED) /* To prevent double definition */
#error SOAD_SOCKETSTATE_CONNECTED already defined!
#endif /* (defined SOAD_SOCKETSTATE_CONNECTED) */

/** \brief Value of SoAd_SocketStateType SOAD_SOCKETSTATE_CONNECTED */
#define SOAD_SOCKETSTATE_CONNECTED 2U


#if (defined SOAD_SOCKETSTATE_CLOSING) /* To prevent double definition */
#error SOAD_SOCKETSTATE_CLOSING already defined!
#endif /* (defined SOAD_SOCKETSTATE_CLOSING) */

/** \brief Value of SoAd_SocketStateType SOAD_SOCKETSTATE_CLOSING */
#define SOAD_SOCKETSTATE_CLOSING 3U


#if (defined SOAD_SOCKETSTATE_ONLINE) /* To prevent double definition */
#error SOAD_SOCKETSTATE_ONLINE already defined!
#endif /* (defined SOAD_SOCKETSTATE_ONLINE) */

/** \brief Value of SoAd_SocketStateType SOAD_SOCKETSTATE_ONLINE */
#define SOAD_SOCKETSTATE_ONLINE 4U


#if (defined SOAD_SOCKETSTATE_RESTART) /* To prevent double definition */
#error SOAD_SOCKETSTATE_RESTART already defined!
#endif /* (defined SOAD_SOCKETSTATE_RESTART) */

/** \brief Value of SoAd_SocketStateType SOAD_SOCKETSTATE_RESTART */
#define SOAD_SOCKETSTATE_RESTART 5U


#if (defined SOAD_SOCKETSTATE_SHUTDOWN) /* To prevent double definition */
#error SOAD_SOCKETSTATE_SHUTDOWN already defined!
#endif /* (defined SOAD_SOCKETSTATE_SHUTDOWN) */

/** \brief Value of SoAd_SocketStateType SOAD_SOCKETSTATE_SHUTDOWN */
#define SOAD_SOCKETSTATE_SHUTDOWN 6U



#if (defined SOAD_PDUROUTEDESTVIRTUALSTATE_IDLE) /* To prevent double definition */
#error SOAD_PDUROUTEDESTVIRTUALSTATE_IDLE already defined!
#endif /* (defined SOAD_PDUROUTEDESTVIRTUALSTATE_IDLE) */

/** \brief Value of SoAd_PduRouteDestVirtualStateType SOAD_PDUROUTEDESTVIRTUALSTATE_IDLE */
#define SOAD_PDUROUTEDESTVIRTUALSTATE_IDLE 0U


#if (defined SOAD_PDUROUTEDESTVIRTUALSTATE_TXING) /* To prevent double definition */
#error SOAD_PDUROUTEDESTVIRTUALSTATE_TXING already defined!
#endif /* (defined SOAD_PDUROUTEDESTVIRTUALSTATE_TXING) */

/** \brief Value of SoAd_PduRouteDestVirtualStateType SOAD_PDUROUTEDESTVIRTUALSTATE_TXING */
#define SOAD_PDUROUTEDESTVIRTUALSTATE_TXING 1U


#if (defined SOAD_PDUROUTEDESTVIRTUALSTATE_WAITCONF) /* To prevent double definition */
#error SOAD_PDUROUTEDESTVIRTUALSTATE_WAITCONF already defined!
#endif /* (defined SOAD_PDUROUTEDESTVIRTUALSTATE_WAITCONF) */

/** \brief Value of SoAd_PduRouteDestVirtualStateType SOAD_PDUROUTEDESTVIRTUALSTATE_WAITCONF */
#define SOAD_PDUROUTEDESTVIRTUALSTATE_WAITCONF 2U


#if (defined SOAD_PDUROUTEDESTVIRTUALSTATE_SKIPCONF) /* To prevent double definition */
#error SOAD_PDUROUTEDESTVIRTUALSTATE_SKIPCONF already defined!
#endif /* (defined SOAD_PDUROUTEDESTVIRTUALSTATE_SKIPCONF) */

/** \brief Value of SoAd_PduRouteDestVirtualStateType SOAD_PDUROUTEDESTVIRTUALSTATE_SKIPCONF */
#define SOAD_PDUROUTEDESTVIRTUALSTATE_SKIPCONF 3U


#if (defined SOAD_PDUROUTEDESTVIRTUALSTATE_BUFFERED) /* To prevent double definition */
#error SOAD_PDUROUTEDESTVIRTUALSTATE_BUFFERED already defined!
#endif /* (defined SOAD_PDUROUTEDESTVIRTUALSTATE_BUFFERED) */

/** \brief Value of SoAd_PduRouteDestVirtualStateType SOAD_PDUROUTEDESTVIRTUALSTATE_BUFFERED */
#define SOAD_PDUROUTEDESTVIRTUALSTATE_BUFFERED 4U


#if (defined SOAD_PDUROUTEDESTVIRTUALSTATE_SHADOW_BUFFERED) /* To prevent double definition */
#error SOAD_PDUROUTEDESTVIRTUALSTATE_SHADOW_BUFFERED already defined!
#endif /* (defined SOAD_PDUROUTEDESTVIRTUALSTATE_SHADOW_BUFFERED) */

/** \brief Value of SoAd_PduRouteDestVirtualStateType SOAD_PDUROUTEDESTVIRTUALSTATE_SHADOW_BUFFERED */
#define SOAD_PDUROUTEDESTVIRTUALSTATE_SHADOW_BUFFERED 5U


#if (defined SOAD_PDUROUTEDESTVIRTUALSTATE_CONF_OK) /* To prevent double definition */
#error SOAD_PDUROUTEDESTVIRTUALSTATE_CONF_OK already defined!
#endif /* (defined SOAD_PDUROUTEDESTVIRTUALSTATE_CONF_OK) */

/** \brief Value of SoAd_PduRouteDestVirtualStateType SOAD_PDUROUTEDESTVIRTUALSTATE_CONF_OK */
#define SOAD_PDUROUTEDESTVIRTUALSTATE_CONF_OK 6U


#if (defined SOAD_PDUROUTEDESTVIRTUALSTATE_CONF_NOT_OK) /* To prevent double definition */
#error SOAD_PDUROUTEDESTVIRTUALSTATE_CONF_NOT_OK already defined!
#endif /* (defined SOAD_PDUROUTEDESTVIRTUALSTATE_CONF_NOT_OK) */

/** \brief Value of SoAd_PduRouteDestVirtualStateType SOAD_PDUROUTEDESTVIRTUALSTATE_CONF_NOT_OK */
#define SOAD_PDUROUTEDESTVIRTUALSTATE_CONF_NOT_OK 7U



#if (defined SOAD_SOCKETRXSTATE_IDLE) /* To prevent double definition */
#error SOAD_SOCKETRXSTATE_IDLE already defined!
#endif /* (defined SOAD_SOCKETRXSTATE_IDLE) */

/** \brief Value of SoAd_SocketRxStateType SOAD_SOCKETRXSTATE_IDLE */
#define SOAD_SOCKETRXSTATE_IDLE 0U


#if (defined SOAD_SOCKETRXSTATE_TXING) /* To prevent double definition */
#error SOAD_SOCKETRXSTATE_TXING already defined!
#endif /* (defined SOAD_SOCKETRXSTATE_TXING) */

/** \brief Value of SoAd_SocketRxStateType SOAD_SOCKETRXSTATE_TXING */
#define SOAD_SOCKETRXSTATE_TXING 1U


#if (defined SOAD_SOCKETRXSTATE_WAITCONF) /* To prevent double definition */
#error SOAD_SOCKETRXSTATE_WAITCONF already defined!
#endif /* (defined SOAD_SOCKETRXSTATE_WAITCONF) */

/** \brief Value of SoAd_SocketRxStateType SOAD_SOCKETRXSTATE_WAITCONF */
#define SOAD_SOCKETRXSTATE_WAITCONF 2U


#if (defined SOAD_SOCKETRXSTATE_SKIPCONF) /* To prevent double definition */
#error SOAD_SOCKETRXSTATE_SKIPCONF already defined!
#endif /* (defined SOAD_SOCKETRXSTATE_SKIPCONF) */

/** \brief Value of SoAd_SocketRxStateType SOAD_SOCKETRXSTATE_SKIPCONF */
#define SOAD_SOCKETRXSTATE_SKIPCONF 3U


#if (defined SOAD_SOCKETRXSTATE_BUFFERED) /* To prevent double definition */
#error SOAD_SOCKETRXSTATE_BUFFERED already defined!
#endif /* (defined SOAD_SOCKETRXSTATE_BUFFERED) */

/** \brief Value of SoAd_SocketRxStateType SOAD_SOCKETRXSTATE_BUFFERED */
#define SOAD_SOCKETRXSTATE_BUFFERED 4U



#if (defined SOAD_PDUROUTEDEST_FLAG_TRIGGER_ALWAYS_SHIFT) /* To prevent double definition */
#error SOAD_PDUROUTEDEST_FLAG_TRIGGER_ALWAYS_SHIFT already defined!
#endif /* (defined SOAD_PDUROUTEDEST_FLAG_TRIGGER_ALWAYS_SHIFT) */

/** \brief The bit shift for PDU route destination flag SOAD_PDUROUTEDEST_FLAG_TRIGGER_ALWAYS */
#define SOAD_PDUROUTEDEST_FLAG_TRIGGER_ALWAYS_SHIFT 0U


#if (defined SOAD_PDUROUTEDEST_FLAG_TRIGGER_ALWAYS_MASK) /* To prevent double definition */
#error SOAD_PDUROUTEDEST_FLAG_TRIGGER_ALWAYS_MASK already defined!
#endif /* (defined SOAD_PDUROUTEDEST_FLAG_TRIGGER_ALWAYS_MASK) */

/** \brief The bit mask for PDU route destination flag SOAD_PDUROUTEDEST_FLAG_TRIGGER_ALWAYS */
#define SOAD_PDUROUTEDEST_FLAG_TRIGGER_ALWAYS_MASK ((uint8)(1UL << SOAD_PDUROUTEDEST_FLAG_TRIGGER_ALWAYS_SHIFT))


#if (defined SOAD_PDUROUTEDEST_FLAG_IS_GROUPROUTE_SHIFT) /* To prevent double definition */
#error SOAD_PDUROUTEDEST_FLAG_IS_GROUPROUTE_SHIFT already defined!
#endif /* (defined SOAD_PDUROUTEDEST_FLAG_IS_GROUPROUTE_SHIFT) */

/** \brief The bit shift for PDU route destination flag SOAD_PDUROUTEDEST_FLAG_IS_GROUPROUTE */
#define SOAD_PDUROUTEDEST_FLAG_IS_GROUPROUTE_SHIFT 1U


#if (defined SOAD_PDUROUTEDEST_FLAG_IS_GROUPROUTE_MASK) /* To prevent double definition */
#error SOAD_PDUROUTEDEST_FLAG_IS_GROUPROUTE_MASK already defined!
#endif /* (defined SOAD_PDUROUTEDEST_FLAG_IS_GROUPROUTE_MASK) */

/** \brief The bit mask for PDU route destination flag SOAD_PDUROUTEDEST_FLAG_IS_GROUPROUTE */
#define SOAD_PDUROUTEDEST_FLAG_IS_GROUPROUTE_MASK ((uint8)(1UL << SOAD_PDUROUTEDEST_FLAG_IS_GROUPROUTE_SHIFT))

/*------[Pre-processor switch to enable/diable relocatable postbuild config]------*/


#if (defined SOAD_RELOCATABLE_CFG_ENABLE) /* To prevent double definition */
#error SOAD_RELOCATABLE_CFG_ENABLE already defined!
#endif /* (defined SOAD_RELOCATABLE_CFG_ENABLE) */

/** \brief Derived from SoAdRelocatableCfgEnable */
#define SOAD_RELOCATABLE_CFG_ENABLE STD_ON


#if (defined SOAD_CFG_SIGNATURE) /* To prevent double definition */
#error SOAD_CFG_SIGNATURE already defined!
#endif /* (defined SOAD_CFG_SIGNATURE) */

/** \brief Compile time verification value */
#define SOAD_CFG_SIGNATURE 507991585U


#if (defined SOAD_PUBLIC_INFO_SIGNATURE) /* To prevent double definition */
#error SOAD_PUBLIC_INFO_SIGNATURE already defined!
#endif /* (defined SOAD_PUBLIC_INFO_SIGNATURE) */

/** \brief Compile time Published information verfication value */
#define SOAD_PUBLIC_INFO_SIGNATURE 3411738731U

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
#endif /* ifndef SOAD_CFG_H  */
/*==================[end of file]===========================================*/
