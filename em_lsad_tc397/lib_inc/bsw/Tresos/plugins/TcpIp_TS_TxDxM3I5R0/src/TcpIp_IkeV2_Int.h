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
#ifndef TCPIP_IPSECIKEV2_H
#define TCPIP_IPSECIKEV2_H

/*==================[inclusions]============================================*/

#include <TcpIp_Int.h>            /* module internal headerfile */
#include <TcpIp_Cbk.h>            /* TcpIp_RxIndication() function declaration */
#include <TcpIp_IpSec_Api.h>
#include <TcpIp_IpV4_Int.h>       /* used SW-unit interface file */
#include <TcpIp_IpV6_Int.h>       /* used SW-unit interface file */

/*==================[macros]================================================*/

#if (TCPIP_SECURITY_MODE == TCPIP_IKEV2)

/** \brief ISAKMP Header size for the IKEv2 Message */
#define TCPIP_IKEV2_ISAKMP_HEADER_SIZE                              28U
/** \brief Length of an IKE SA with one proposal */
#define TCPIP_IKEV2_IKE_SA_SIZE                                     48U
/** \brief Length of the Key exchange payload without key exchange data */
#define TCPIP_IKEV2_IKE_MIN_NONCE_SIZE                              16U
/** \brief Size of an ike spi */
#define TCPIP_IKEV2_IKE_SPI_SIZE                                     8U
/** \brief Size of the generic payload header */
#define TCPIP_IKEV2_GENERIC_PAYLOAD_HDR_SIZE                         4U
/** \brief Size of the certificate payload header */
#define TCPIP_IKEV2_CERTIFICATE_HDR_SIZE                             5U
/** \brief Size of the certificate request payload header */
#define TCPIP_IKEV2_CERTIFICATE_REQUEST_HDR_SIZE                     5U
/** \brief Size of the generic payload header */
#define TCPIP_IKEV2_PAYLOAD_ID_HDR_SIZE                              8U
/** \brief Size of the authentication header */
#define TCPIP_IKEV2_PAYLOAD_AUTH_FIXED_SIZE                          8U
/** \brief Size of the digital signature authentication header */
#define TCPIP_IKEV2_PAYLOAD_AUTH_DIG_SIG_FIXED_SIZE                  9U
/** \brief Size of the proposal header  */
#define TCPIP_IKEV2_PROPOSAL_HDR_GENERIC_SIZE                        8U
/** \brief Size of the transform substructure header */
#define TCPIP_IKEV2_TRANSFORM_HDR_SIZE                               8U
/** \brief Size of the attribute */
#define TCPIP_IKEV2_ATTRIBUTE_SIZE                                   4U
/** \brief Size of the traffic selector payload header */
#define TCPIP_IKEV2_PAYLOAD_TRAFFIC_SEL_HDR_SIZE                     8U
/** \brief Minimum traffic selector substructure size */
#define TCPIP_IKEV2_TRAFFIC_SEL_MIN_HDR_SIZE                        12U
/** \brief Size of a notify without data field */
#define TCPIP_IKEV2_EMPTY_NOTIFY_SIZE                                8U
/** \brief Size of the expected invalid key payload message */
#define TCPIP_IKEV2_INVALID_KE_PAYLOAD_SIZE                         10U
/** \brief Size of the expected IKE SA delete message */
#define TCPIP_IKEV2_IKE_SA_DELETE_SIZE                               8U
/** \brief Size of the expected IKE child SA delete message */
#define TCPIP_IKEV2_SINGLE_IPSEC_SA_DELETE_SIZE                     12U
/** \brief Size of a rekey notification */
#define TCPIP_IKEV2_REKEY_NOTIFY_SIZE                               12U
/** \brief Size of a rekey notification */
#define TCPIP_IKEV2_CHILD_SA_NOT_FOUND_NOTIFY_SIZE                  12U
/** \brief Size of ipv4 traffic selector */
#define TCPIP_IKEV2_IPV4_TRAFFIC_SEL_SIZE                           16U
/** \brief Size of ipv6 traffic selector */
#define TCPIP_IKEV2_IPV6_TRAFFIC_SEL_SIZE                           40U
/** \brief Size of the key exchange header */
#define TCPIP_IKEV2_KEYEXC_HDR_SIZE                                  8U
/** \brief Size of the fixed part of the SKF header */
#define TCPIP_IKEV2_SKF_FIXED_HDR_SIZE                               8U
/** \brief Size of the "Pad Length" field in an SKF message */
#define TCPIP_IKEV2_SKF_PAD_LENGTH_SIZE                              1U

/** \brief  IKE version 1 */
#define TCPIP_IKEV2_VERSION_IKEV1              1U
/** \brief  IKE version 2 */
#define TCPIP_IKEV2_VERSION_IKEV2              2U

/** \brief Invalid IKE connection index */
#define TCPIP_IKEV2_INVALID_IKE_CONNECTION_IDX                      255U

/*---------------[Exchange Types]---------------*/
/** \brief Exchange Type IKE_SA_INIT*/
#define TCPIP_IKEV2_EXCHANGE_SA_INIT           34U
/** \brief Exchange Type IKE_AUTH*/
#define TCPIP_IKEV2_EXCHANGE_AUTH              35U
/** \brief Exchange Type CREATE_CHILD_SA*/
#define TCPIP_IKEV2_EXCHANGE_CREATE_CHILD_SA   36U
/** \brief Exchange Type INFORMATIONAL*/
#define TCPIP_IKEV2_EXCHANGE_INFORMATIONAL     37U

/*----------------[Payload Types]---------------*/
/** \brief No Next Payload */
#define TCPIP_IKEV2_NO_NEXT_PAYLOAD             0U
/** \brief Proposal Payload Type*/
#define TCPIP_IKEV2_PAYLOAD_TYPE_PROPOSAL       2U
/** \brief Transform Payload Type*/
#define TCPIP_IKEV2_PAYLOAD_TYPE_TRANSFORM      3U
/** \brief Security Association (SA) Payload Type*/
#define TCPIP_IKEV2_PAYLOAD_TYPE_SA            33U
/** \brief Key Exchange (KE) Payload Type*/
#define TCPIP_IKEV2_PAYLOAD_TYPE_KE            34U
/** \brief Identification Initiator (IDi) Payload Type*/
#define TCPIP_IKEV2_PAYLOAD_TYPE_IDI           35U
/** \brief Identification Responder (IDr) Payload Type*/
#define TCPIP_IKEV2_PAYLOAD_TYPE_IDR           36U
/** \brief Certificate (CERT) Payload Type*/
#define TCPIP_IKEV2_PAYLOAD_TYPE_CERT          37U
/** \brief Certificate Request (CERTREQ) Payload Type*/
#define TCPIP_IKEV2_PAYLOAD_TYPE_CERTREQ       38U
/** \brief Authentication (AUTH) Payload Type*/
#define TCPIP_IKEV2_PAYLOAD_TYPE_AUTH          39U
/** \brief Nonce (Ni,Nr) Payload Type*/
#define TCPIP_IKEV2_PAYLOAD_TYPE_NONCE         40U
/** \brief Notify Payload Type*/
#define TCPIP_IKEV2_PAYLOAD_TYPE_N             41U
/** \brief Delete (D) Payload Type*/
#define TCPIP_IKEV2_PAYLOAD_TYPE_D             42U
/** \brief Vendor ID (V) Payload Type*/
#define TCPIP_IKEV2_PAYLOAD_TYPE_V             43U
/** \brief Traffic Selector - Initiator (TSi) Payload Type*/
#define TCPIP_IKEV2_PAYLOAD_TYPE_TSI           44U
/** \brief Traffic Selector - Responder (TSr) Payload Type*/
#define TCPIP_IKEV2_PAYLOAD_TYPE_TSR           45U
/** \brief Encrypted and Authenticated (SK) Payload Type*/
#define TCPIP_IKEV2_PAYLOAD_TYPE_SK            46U
/** \brief Configuration (CP) Payload Type*/
#define TCPIP_IKEV2_PAYLOAD_TYPE_CP            47U
/** \brief Extensible Authentication (EAP) Payload Type*/
#define TCPIP_IKEV2_PAYLOAD_TYPE_EAP           48U
/** \brief Encrypted and Authenticated Fragment (SKF) Payload Type*/
#define TCPIP_IKEV2_PAYLOAD_TYPE_SKF           53U

/*-------------[Proposal IDs Types]-------------*/
/** \brief IKE protocol proposal type */
#define TCPIP_IKEV2_PROTOCOL_IKE_ID             1U
/** \brief AH protocol proposal type */
#define TCPIP_IKEV2_PROTOCOL_AH_ID              2U
/** \brief ESP protocol proposal type */
#define TCPIP_IKEV2_PROTOCOL_ESP_ID             3U

/*---------------------[Notify Message Types]---------------------*/
/** \brief UNSUPPORTED_CRITICAL_PAYLOAD error type */
#define TCPIP_IKEV2_NOTIFY_UNSUPPORTED_CRITICAL_PAYLOAD           1U
/** \brief INVALID_IKE_SPI error type */
#define TCPIP_IKEV2_NOTIFY_INVALID_IKE_SPI                        4U
/** \brief INVALID_MAJOR_VERSION error type */
#define TCPIP_IKEV2_NOTIFY_INVALID_MAJOR_VERSION                  5U
/** \brief INVALID_SYNTAX error type */
#define TCPIP_IKEV2_NOTIFY_INVALID_SYNTAX                         7U
/** \brief INVALID_MESSAGE_ID error type */
#define TCPIP_IKEV2_NOTIFY_INVALID_MESSAGE_ID                     9U
/** \brief INVALID_SPI error type */
#define TCPIP_IKEV2_NOTIFY_INVALID_SPI                           11U
/** \brief NO_PROPOSAL_CHOSEN error type */
#define TCPIP_IKEV2_NOTIFY_NO_PROPOSAL_CHOSEN                    14U
/** \brief INVALID_KE_PAYLOAD error type */
#define TCPIP_IKEV2_NOTIFY_INVALID_KE_PAYLOAD                    17U
/** \brief AUTHENTICATION_FAILED error type */
#define TCPIP_IKEV2_NOTIFY_AUTHENTICATION_FAILED                 24U
/** \brief SINGLE_PAIR_REQUIRED error type */
#define TCPIP_IKEV2_NOTIFY_SINGLE_PAIR_REQUIRED                  34U
/** \brief NO_ADDITIONAL_SAS error type */
#define TCPIP_IKEV2_NOTIFY_NO_ADDITIONAL_SAS                     35U
/** \brief INTERNAL_ADDRESS_FAILURE error type */
#define TCPIP_IKEV2_NOTIFY_INTERNAL_ADDRESS_FAILURE              36U
/** \brief FAILED_CP_REQUIRED error type */
#define TCPIP_IKEV2_NOTIFY_FAILED_CP_REQUIRED                    37U
/** \brief TS_UNACCEPTABLE error type */
#define TCPIP_IKEV2_NOTIFY_TS_UNACCEPTABLE                       38U
/** \brief INVALID_SELECTORS error type */
#define TCPIP_IKEV2_NOTIFY_INVALID_SELECTORS                     39U
/** \brief UNACCEPTABLE_ADDRESSES error type */
#define TCPIP_IKEV2_NOTIFY_UNACCEPTABLE_ADDRESSES                40U
/** \brief UNEXPECTED_NAT_DETECTED error type */
#define TCPIP_IKEV2_NOTIFY_UNEXPECTED_NAT_DETECTED               41U
/** \brief USE_ASSIGNED_HoA error type */
#define TCPIP_IKEV2_NOTIFY_USE_ASSIGNED_HOA                      42U
/** \brief TEMPORARY_FAILURE error type */
#define TCPIP_IKEV2_NOTIFY_TEMPORARY_FAILURE                     43U
/** \brief CHILD_SA_NOT_FOUND error type */
#define TCPIP_IKEV2_NOTIFY_CHILD_SA_NOT_FOUND                    44U
/** \brief INVALID_GROUP_ID error type */
#define TCPIP_IKEV2_NOTIFY_INVALID_GROUP_ID                      45U
/** \brief AUTHORIZATION_FAILED error type */
#define TCPIP_IKEV2_NOTIFY_AUTHORIZATION_FAILED                  46U

/** \brief maximal error type defined by IANA */
#define TCPIP_IKEV2_NOTIFY_MAX_KNOWN_TYPE                        46U
/** \brief maximal status type supported */
#define TCPIP_IKEV2_NOTIFY_MAX_ERROR_TYPE                     16383U

/** \brief INITIAL_CONTACT status type */
#define TCPIP_IKEV2_NOTIFY_INITIAL_CONTACT                    16384U
/** \brief USE_TRANSPORT_MODE status type */
#define TCPIP_IKEV2_NOTIFY_USE_TRANSPORT_MODE_TYPE            16391U
/** \brief REKEY_SA status type */
#define TCPIP_IKEV2_NOTIFY_REKEY_SA                           16393U
/** \brief FRAGMENTATION_SUPPORTED status type */
#define TCPIP_IKEV2_NOTIFY_FRAGMENTATION_SUPPORTED            16430U
/** \brief SIGNATURE_HASH_ALGORITHMS status type */
#define TCPIP_IKEV2_NOTIFY_SIGNATUREHASHALGORITHM_TYPE        16431U

/*-----------[Traffic Selector Types]------------*/
/** \brief IpV4 traffic selector type */
#define TCPIP_IKEV2_TRAFFIC_SEL_IPV4_TYPE        7U
/** \brief IpV6 traffic selector type */
#define TCPIP_IKEV2_TRAFFIC_SEL_IPV6_TYPE        8U

/** \brief IkeV2 Nonce minimum size in octets */
#define TCPIP_IKEV2_NONCE_SIZE_MIN              16U
/** \brief IkeV2 Nonce maximum size in octets */
#define TCPIP_IKEV2_NONCE_SIZE_MAX             256U

/*-------[Identification Selector Types]--------*/
/** \brief A single four (4) octet IPv4 address */
#define TCPIP_IKEV2_ID_IPV4_TYPE                1U
/** \brief A single sixteen (16) octet IPv6 address */
#define TCPIP_IKEV2_ID_IPV6_TYPE                5U
/** \brief The binary Distinguished Encoding Rules (DER) encoding of an
      ASN.1 X.500 Distinguished Name */
#define TCPIP_IKEV2_ID_DER_ASN1_DN_TYPE         9U

/*==================[type definitions]======================================*/
/*------------------[IKE State Types]------------------*/
/** \brief uninitialized state */
#define TCPIP_IKEV2_INACTIVE_STATE                  0x00U
/** \brief State for the IKE_SA_INIT */
#define TCPIP_IKEV2_SA_INIT_STATE                   0x04U
/** \brief State for the IKE_AUTH */
#define TCPIP_IKEV2_AUTH_STATE                      0x08U
/** \brief State for the IKE_ESTABLISHED */
#define TCPIP_IKEV2_ESTABLISHED_STATE               0x10U
/** \brief State for the deletion of the IKE SA, e.g. if
 * IKE SA life time expires or TcpIp is shut down */
#define TCPIP_IKEV2_IKE_DELETION_STATE              0x20U
/** \brief State for the re-authentication of the IKE SA */
#define TCPIP_IKEV2_REAUTHENTICATION_STATE          0x40U

/** \brief Type which specifies the current state of a IKE connection */
typedef uint8 TcpIp_IkeV2_stateType;

/*==================[external function declarations]========================*/



/*==================[internal function declarations]========================*/
#define TCPIP_START_SEC_CODE
#include <TcpIp_MemMap.h>

#if (TCPIP_SECURITY_MODE == TCPIP_IKEV2)

/** \brief Mainfunction of the IkeV2 Unit
 *
 *  This service maintains the IkeV2 unit and performs periodic tasks.
 *  It is triggered from the TcpIp_SecurityMainFunction.
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_mainFunction(void);

#if (TCPIP_IPSEC_GET_STATUS_API_ENABLED == STD_ON)
/** \brief Returns IKE SAs status for specified TcpIp controller
 *
 * This function returns status for all IKE SAs on a given controller.
 * If numberOfIkeSaElementsPtr points to zero value, the function returns only total number of
 * IKE SAs for the given controller.
 *
 * \param[in]     TcpIp_ctrlIdx             Relevant TcpIp controller index
 * \param[out]    sockAddPtr                Pointer to a list of local addresses to fill
 * \param[out]    ikeSaStatusPtr            IKE status data for the selected controller
 * \param[in,out] numberOfIkeSaElementsPtr  Entry: If pointing to zero then sockAddPtr/ikeSaStatusPtr not filled
 *                                          Exit: Number of found SA entries
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_getIkeSaEntries
(
  uint8 TcpIp_ctrlIdx,
  P2VAR(TcpIp_SockAddrPtrType, AUTOMATIC, TCPIP_APPL_DATA) sockAddPtr,
  P2VAR(TcpIp_IpSecIkeSaStatusType, AUTOMATIC, TCPIP_APPL_DATA) ikeSaStatusPtr,
  P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) numberOfIkeSaElementsPtr
);

#endif /* (TCPIP_IPSEC_GET_STATUS_API_ENABLED == STD_ON) */

/** \brief Initialization of the IkeV2
 *
 *  This function initializes the module to a default mode
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_init
(
  void
);

/** \brief Start a given IKE Connection
 *
 *  This function changes the state variable of an IKE connection to indicate the Ike negotiation
 *  shall start. If extraction of identifier from the certificate is not succesful this function
 *  does nothing. The actual tranmission of an IkeV2 request is triggered from TcpIp_IkeV2_mainFunction.
 *
 * \param[in] ikeConIdx   index of the IKE connection to be started
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_start
(
  uint8 ikeConIdx
);

/** \brief Stop a given IKE Connection
 *
 *  This function stops the IKE connection selected by ikeConIdx and deletes all IKE SAs for this
 *  connection.
 *
 * \param[in] ikeConIdx   index of the IKE connection to be closed
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_stop
(
  uint8 ikeConIdx
);

/** \brief Decrement the running timers for each IKE SA
 *
 *  This function decrements the following three timers: ikeSaTimer, dpdTimer, retransTimer
 *  If one of the timers expires the corresponding bit-flag is
 *  set (ikeSaTimeoutFlag, dpdTimeoutFlag, retransTimeoutFlag).
 *  The timeout is handeled in TcpIp_IkeV2_handleTimeouts. Once the timeout is
 *  handeled in TcpIp_IkeV2_handleTimeouts the corresponding bit-flag is cleared.
 *
 * \param[in] timerTick        timer tick of the TcpIp_MainFunction
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_decrementTimers
(
  uint16 timerTick
);

/** \brief Stop IKE SAs that is invalid
 *
 * This service deletes the IKE SA with index ikeSaIndex because it is no longer valid
 * (e.g. the associated Child SA has detected a replay attack or the sequence number overflowed).
 *
 * \param[in]  ikeSaIndex          IKE SA index
 * \param[in]  ikeConnectionIdx    IKE connection index
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_deleteInvalidIkeSa
(
  uint8 ikeSaIndex,
  uint8 ikeConnectionIdx
);

#endif /* (TCPIP_SECURITY_MODE == TCPIP_IKEV2) */


#define TCPIP_STOP_SEC_CODE
#include <TcpIp_MemMap.h>
#endif /* (TCPIP_SECURITY_MODE == TCPIP_IKEV2)*/

#endif /* if !defined( TCPIP_IPSECIKEV2_H ) */
/*==================[end of file]===========================================*/
