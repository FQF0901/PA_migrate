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

#ifndef TCPIP_IPSECIKEV2_PRIV_H
#define TCPIP_IPSECIKEV2_PRIV_H

/*==================[inclusions]============================================*/
#include <TcpIp_IkeV2_Int.h>       /* external IpSec Api declarations */
#include <TcpIp_IpSecDb_Int.h>    /* used SW-unit interface file */
#include <TcpIp_Crypto.h>         /* module internal headerfile */
#include <TcpIp_Memory_Int.h>     /* used SW-unit interface file */

#if (TCPIP_SECURITY_MODE == TCPIP_IKEV2)
#include <TSMemS.h>

/*==================[macros]================================================*/

/** \brief UDP port used for IKE communication */
#define TCPIP_IKEV2_UDPPORT_500                                          500U
/** \brief size of the SPI used for IPsec communication */
#define TCPIP_IKEV2_IPSEC_SPI_SIZE                                         4U

/** \brief IKE connection state stopped */
#define TCPIP_IKEV2_CONNECTION_STATE_STOPPED                               0U
/** \brief IKE connection state socket open */
#define TCPIP_IKEV2_CONNECTION_STATE_SOCKETOPEN                            1U
/** \brief IKE connection state started */
#define TCPIP_IKEV2_CONNECTION_STATE_STARTED                               2U
/** \brief IKE connection state active */
#define TCPIP_IKEV2_CONNECTION_STATE_ACTIVE                                3U

/** \brief invalid index of the IKE SA */
#define TCPIP_IKEV2_SA_INVALID_INDEX                                     255U
/** \brief invalid proposal */
#define TCPIP_IKEV2_INVALID_PROPOSAL                                     255U
/** \brief default proposal */
#define TCPIP_IKEV2_DEFAULT_PROPOSAL                                       0U
/** \brief timer is stopped */
#define TCPIP_IKEV2_TIMER_NOT_RUNNING                             0xFFFFFFFFU
/** \brief invalid message type in IKE */
#define TCPIP_IKEV2_INVALID_MSG_TYPE                                     255U

/** \brief IkeV2 Encrypted Fragment payload (SKF) macros */
/** \brief Byte index of the "Fragment Number" field in an SKF */
#define TCPIP_IKEV2_SKF_FRAGMENT_NUMBER_IDX                                4U
/** \brief Byte index of the "Total fragments" field in an SKF */
#define TCPIP_IKEV2_SKF_TOTAL_FRAGMENTS_IDX                                6U

/* Length of the hash digest of the received message */
#if (TCPIP_IKEV2_SHA1_ENABLED == STD_ON)
#define TCPIP_IKEV2_MSG_HASH_LENGTH                                       20U
#else
#define TCPIP_IKEV2_MSG_HASH_LENGTH                                       32U
#endif

/* authentication payload types */
/** \brief preshared key used for authentication */
#define TCPIP_IKEV2_AUTH_METHOD_SHARED_KEY                               0x02U
/** \brief digital signature used for authentication */
#define TCPIP_IKEV2_AUTH_METHOD_DIGITAL_SIG                              0x0eU

/* The error codes of the TcpIp_IkeV2_ReturnType correspond to the
 * error notify message types as defined by IANA
 * (www.iana.org/assignments/ikev2-parameters) */

#define TCPIP_IKEV2_E_RX_NOTIFY_INVALID_KE_PAYLOAD           TCPIP_IKEV2_NOTIFY_INVALID_KE_PAYLOAD
#define TCPIP_IKEV2_E_RX_NOTIFY_AUTHENTICATION_FAILED        TCPIP_IKEV2_NOTIFY_AUTHENTICATION_FAILED
#define TCPIP_IKEV2_E_RX_NOTIFY_INVALID_SYNTAX               TCPIP_IKEV2_NOTIFY_INVALID_SYNTAX

#define TCPIP_IKEV2_E_RX_NOTIFY_UNKNOWN                      199U

/* Range 200-255 is for internal error conditions */
#define TCPIP_IKEV2_E_OK                                  0U
#define TCPIP_IKEV2_E_NOT_OK                              201U
#define TCPIP_IKEV2_E_NO_PROPOSAL_CHOSEN                  203U
#define TCPIP_IKEV2_E_INVALID_SYNTAX                      204U
#define TCPIP_IKEV2_E_AUTHENTICATION_FAILED               205U
#define TCPIP_IKEV2_E_TS_UNACCEPTABLE                     206U
#define TCPIP_IKEV2_E_INVALID_KE_PAYLOAD                  207U
#define TCPIP_IKEV2_E_PAYLOAD_MISSING                     210U
#define TCPIP_IKEV2_E_SIG_HASH_NOT_SUPPORTED              211U
#define TCPIP_IKEV2_E_UNSUPPORTED_CRITICAL_PAYLOAD        213U
#define TCPIP_IKEV2_E_INVALID_MESSAGE_ID                  214U
#define TCPIP_IKEV2_E_RX_BUFFER_FULL                      215U
#define TCPIP_IKEV2_E_RX_BUFFER_MSG_TOOLARGE              216U

/* ASN.1 */
#define TCPIP_IKEV2_ASN1_SEQUENCE                                        0x30U
#define TCPIP_IKEV2_ASN1_INT                                             0x02U
#define TCPIP_IKEV2_ASN1_HDR_MINLEN                                         2U
#define TCPIP_IKEV2_ASN1_EXTRA_BYTE                                         1U

/* certificate */
#define TCPIP_IKEV2_CERT_ENCODING_IDX                                       4U
#define TCPIP_IKEV2_CERTAUTH_HASH_LENGTH                                   20U
#define TCPIP_IKEV2_CERT_INVALID_IDX                                      255U

/** \brief Size of the Dispatch Array for encrypt and decrypt */
#define TCPIP_IKEV2_NUM_CRYPT                                               2U

#define TCPIP_IKEV2_INITIATOR_FLAG                                       0x08U
#define TCPIP_IKEV2_RESPONSE_FLAG                                        0x20U

#define TCPIP_IKEV2_TRAFFIC_SEL_HDR_IPADDR_IDX                              8U

#define TCPIP_IKEV2_IS_RESPONSE_MSG(flags) \
  ((flags & TCPIP_IKEV2_RESPONSE_FLAG) == TCPIP_IKEV2_RESPONSE_FLAG)

/** \brief Set the SPI to zero */
#define TCPIP_IKEV2_IS_ZERO_IKE_SPI(spiPtr)                                      \
  ((((spiPtr)[0U]) == 0U) && (((spiPtr)[1U]) == 0U) &&                           \
  (((spiPtr)[2U]) == 0U) && (((spiPtr)[3U]) == 0U) &&                            \
  (((spiPtr)[4U]) == 0U) && (((spiPtr)[5U]) == 0U) &&                            \
  (((spiPtr)[6U]) == 0U) && (((spiPtr)[7U]) == 0U))

/* Certificate encodings */
#define TCPIP_IKEV2_CERT_ENCODING_X509_SIGNATURE                         0x04U

#define TCPIP_IKEV2_CERT_HDR_GET_ENCODING(dataPtr)                               \
  (dataPtr[TCPIP_IKEV2_CERT_ENCODING_IDX])


/** \brief Set the message nextpayload */
#define TCPIP_IKEV2_PAYLOAD_SET_NEXTPAYLOAD(ikeHdrPtr, nextPayloadType)             \
   ((ikeHdrPtr)[TCPIP_IKEV2_PAYLOAD_HDR_NEXT_PAYLOAD_IDX] = (nextPayloadType))

/** \brief Set critical payload bit in the message */
#define TCPIP_IKEV2_PAYLOAD_SET_CRITICALBIT(ikeHdrPtr, value)                       \
   ((ikeHdrPtr)[TCPIP_IKEV2_PAYLOAD_HDR_FLAG_C_IDX] = (value))

/** \brief Set the payload length*/
#define TCPIP_IKEV2_PAYLOAD_SET_PAYLOADLENGTH(ikeHdrPtr, value)                     \
  TCPIP_SET16 (ikeHdrPtr, TCPIP_IKEV2_PAYLOAD_HDR_PAYLOAD_LEN_IDX, value)

/** \brief Set the fields of generic payload header */
#define TCPIP_IKEV2_SET_PAYLOADHEADER(pylHdrPtr, prevPylTypePtr, pylType, pylLen)   \
  do                                                                                \
  {                                                                                 \
    if((prevPylTypePtr) != NULL_PTR)                                                \
    {                                                                               \
      TCPIP_IKEV2_PAYLOAD_SET_NEXTPAYLOAD((prevPylTypePtr), (pylType));             \
    }                                                                               \
    TCPIP_IKEV2_PAYLOAD_SET_CRITICALBIT((pylHdrPtr), 0U);                           \
    TCPIP_IKEV2_PAYLOAD_SET_PAYLOADLENGTH((pylHdrPtr), (pylLen));                   \
  } while (0U)

/** \brief Set the fields of generic payload header */
#define TCPIP_IKEV2_SET_PAYLOADHEADER_NO_CHECK(pylHdrPtr, prevPylTypePtr, pylType, pylLen) \
  do                                                                                              \
  {                                                                                               \
    TCPIP_IKEV2_PAYLOAD_SET_NEXTPAYLOAD((prevPylTypePtr), (pylType));                             \
    TCPIP_IKEV2_PAYLOAD_SET_CRITICALBIT((pylHdrPtr), 0U);                                         \
    TCPIP_IKEV2_PAYLOAD_SET_PAYLOADLENGTH((pylHdrPtr), (pylLen));                                 \
  } while (0U)

/** \brief Set the fields of generic payload header */
#define TCPIP_IKEV2_SET_PAYLOADHEADER_NO_NEXT_PAYLOAD(pylHdrPtr, prevPylTypePtr, pylLen)          \
  do                                                                                              \
  {                                                                                               \
    TCPIP_IKEV2_PAYLOAD_SET_CRITICALBIT((pylHdrPtr), 0U);                                         \
    TCPIP_IKEV2_PAYLOAD_SET_PAYLOADLENGTH((pylHdrPtr), (pylLen));                                 \
  } while (0U)

#if (TCPIP_IKEV2_ENCRYPT_ENABLED == STD_ON) && (TCPIP_IKEV2_AEAD_ENABLED == STD_ON)
#  define TCPIP_IKEV2_IF_ENCRYPT_AEAD_BOTH(encrypt, aead, both) (both)
#elif (TCPIP_IKEV2_ENCRYPT_ENABLED == STD_ON)
#  define TCPIP_IKEV2_IF_ENCRYPT_AEAD_BOTH(encrypt, aead, both) (encrypt)
#elif (TCPIP_IKEV2_AEAD_ENABLED == STD_ON)
#  define TCPIP_IKEV2_IF_ENCRYPT_AEAD_BOTH(encrypt, aead, both) (aead)
#endif

#define TCPIP_IKEV2_TRAFFIC_SEL_HDR_GET_IPADDR_PTR(dataPtr)         \
  (&(dataPtr)[TCPIP_IKEV2_TRAFFIC_SEL_HDR_IPADDR_IDX])

#define TCPIP_IKEV2_HDR_RESPONDERSPI_IDX                                    8U

/** \brief Get the message responder SPI type (IKE_SA_INIT) */
#define TCPIP_IKEV2_GET_RESPONDERINITSPI(ikeHdrPtr)                        \
  (&(ikeHdrPtr)[TCPIP_IKEV2_HDR_RESPONDERSPI_IDX])

/** \brief IkeV2 base header next payload value index  */
#define TCPIP_IKEV2_PAYLOAD_HDR_NEXT_PAYLOAD_IDX                       0U
/** \brief IkeV2 base header critical flag  index  */
#define TCPIP_IKEV2_PAYLOAD_HDR_FLAG_C_IDX                             1U
/** \brief IkeV2 base header payload length value index  */
#define TCPIP_IKEV2_PAYLOAD_HDR_PAYLOAD_LEN_IDX                        2U

#define TCPIP_IKEV2_PAYLOAD_HDR_GET_FLAG_C(dataPtr)                     \
  ((dataPtr)[TCPIP_IKEV2_PAYLOAD_HDR_FLAG_C_IDX] & 0x80U)

#define TCPIP_IKEV2_PAYLOAD_HDR_GET_NEXT_PAYLOAD(dataPtr)               \
  ((dataPtr)[TCPIP_IKEV2_PAYLOAD_HDR_NEXT_PAYLOAD_IDX])

#define TCPIP_IKEV2_PAYLOAD_HDR_GET_PAYLOAD_LENGTH(dataPtr)             \
  TCPIP_GET16(dataPtr, TCPIP_IKEV2_PAYLOAD_HDR_PAYLOAD_LEN_IDX)

/** \brief removes IKE sa with index contained in nextEntryPtr from the linked list */
#define TcpIp_IkeV2_removeNextSa(nextEntryPtr)                                   \
{                                                                                \
  P2VAR(uint8,AUTOMATIC,TCPIP_APPL_DATA) nextEntry_Ptr = (nextEntryPtr);         \
  P2VAR(TcpIp_IkeV2_SaRuntimeDataType,AUTOMATIC,TCPIP_APPL_DATA) sa_Ptr =        \
    &TcpIp_IkeV2_SaRuntimeData[*nextEntry_Ptr];                                  \
  TS_AtomicAssign8(*nextEntry_Ptr, sa_Ptr->nextIkeSaIdx);                        \
}

/** \brief default initialization value for variables of type TcpIp_IkeV2_MemoryType */
#define TCPIP_IKEV2_MEM_INITIALIZER_ARRAY                               \
  {0U, TCPIP_MEMORY_IDPTR_INVALID, NULL_PTR, NULL_PTR, 0U, 0U, 0U}

/** \brief default initialization value for variables of type TcpIp_IkeV2_DataType */
#define TCPIP_IKEV2_IKEDATA_INITIALIZER_ARRAY                           \
  {                                                                     \
    NULL_PTR, /*ikeSaCommonConfigPtr*/                                  \
    NULL_PTR, /*ikeSaConfigPtr*/                                        \
    NULL_PTR, /*ikeSaRtDataPtr*/                                        \
    NULL_PTR, /*ikeConnectionConfigPtr*/                                \
    NULL_PTR, /*ikeConnectionRtDataPtr*/                                \
    0U, /*spiPlaceHolder*/                                              \
    0U, /*dhKeyRemoteMemIndex*/                                         \
    TCPIP_IKEV2_SA_INVALID_INDEX, /*currentIkeSaIdx*/                   \
    TCPIP_IKEV2_INVALID_MSG_TYPE, /*currentMsgType*/                    \
    TCPIP_IKEV2_CERT_INVALID_IDX, /*matchingCACertificateIdx*/          \
    TCPIP_IKEV2_INVALID_PROPOSAL, /*remoteProposalChosen*/              \
    TCPIP_IKEV2_INVALID_PROPOSAL  /*remoteChildProposalChosen*/         \
  }

/** \brief maximal supported asn.1 header length  */
#define TCPIP_IKEV2_ASN1_MAXSUPP_DHR_LEN                                    5U

/*==================[type definitions]======================================*/

/** \brief TcpIp specific return type. */
typedef uint8 TcpIp_IkeV2_ReturnType;

/** \brief Structure describing an identification as defined in RFC 7296 section 3.5. */
typedef struct
{
  /** \brief Length of the identification. */
  uint16 identificationLength;
  /** \brief Pointer to the memory location where the identification data is stored. Contains the value
      of the "Identification Data" field from the Identification Payload. */
  P2CONST(uint8, AUTOMATIC, TCPIP_APPL_DATA) idPtr;
  /** \brief Type of the identification being used. Contains the value of the "ID Type" field from the
      Identification Payload. */
  uint8 identificationType;
} TcpIp_IkeV2_IdentificationType;


/** \brief Structure describing a traffic selector information */
typedef struct
{
  /** \brief Length of the traffic selector in bytes. */
  uint16 trafficSelectorLength;
  /** \brief Size in bytes of the associated IP address. Can be either TCPIP_IPV4_ADDR_BYTE_SIZE or
      TCPIP_IPV6_ADDR_BYTE_SIZE for an IPv4 or IPv6 address, respectively. */
  uint8 ipAddrSize;
  /** \brief Type of the traffic selector, as defined in RFC 7296 section 3.13.1. */
  uint8 trafficSelectorType;
} TcpIp_IkeV2_TrafficSelInfoType;

/** \brief Structure describing a process configuration. */
typedef struct
{
  /** \brief Pointer to the memory location where the proposals is stored. */
  P2CONST(TcpIp_IpSec_ProposalsConfigType, AUTOMATIC, TCPIP_APPL_DATA) proposalsConfigPtr;
  /** \brief Pointer to the memory location where the remote identification is stored. */
  P2VAR(TcpIp_IkeV2_IdentificationType, AUTOMATIC, TCPIP_APPL_DATA) remoteIdPtr;
  /** \brief Pointer to the memory location where the remote authentication configuration is stored. */
  P2CONST(TcpIp_IkeV2AuthConfigType, AUTOMATIC, TCPIP_APPL_DATA) remoteAuthConfigPtr;
  /** \brief Pointer to the memory location where the traffic selector of the initiator is stored. */
  P2CONST(TcpIp_IpSec_TrafficSelType, AUTOMATIC, TCPIP_APPL_DATA) initiatorPolicyConfigPtr;
  /** \brief Pointer to the memory location where the traffic selector of the responder is stored. */
  P2CONST(TcpIp_IpSec_TrafficSelType, AUTOMATIC, TCPIP_APPL_DATA) responderPolicyConfigPtr;
} TcpIp_IkeV2_ProcessPayloadsTempDataType;

/** \brief Structure describing a memory block used to store IKEv2 messages */
typedef struct
{
  /** \brief Length of the allocated memory in bytes. */
  uint32 memoryBlockLength;
  /** \brief Identifier of the memory block */
  P2VAR(void, AUTOMATIC, TCPIP_APPL_DATA) memoryId;
  /** \brief Pointer to the memory location where the message starts. */
  P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) memoryDataPtr;
  /** \brief Pointer to the memory location where the encrypted part of the message starts. */
  P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) memoryCryptDataPtr;
  /** \brief Total length of the message in bytes. */
  uint16 dataLength;
  /** \brief Length of the encrypted part of the message in bytes. */
  uint16 encryptedDataLength;
  /** \brief Length of the decrypted message without padding and pad length in bytes. */
  uint16 decryptedDataLength;
} TcpIp_IkeV2_MemoryType;

#if (TCPIP_IKEV2_FRAGMENTATION_ENABLED == STD_ON)

/** \brief Structure describing a receive message fragment */
typedef struct
{
  /** \brief Pointer to the memory location where the message fragment is stored */
  P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) dataPtr;
  /** \brief Length of the message fragment in bytes */
  uint16 dataLen;
  /** \brief Flag determining if this fragment has been received (TRUE) or not (FALSE). */
  boolean received;
} TcpIp_IkeV2_FragmentInfoType;

/** \brief Structure describing a memory block used to for fragmented reception */
typedef struct
{
  /** \brief Size of the memory block in bytes */
  uint32 size;
  /** \brief Pointer to the memory location of the buffer */
  P2VAR(void, AUTOMATIC, TCPIP_APPL_DATA) idPtr;
} TcpIp_IkeV2_FragmentedRxMemoryInfoType;

/** \brief Structure describing a fragmented reception */
typedef struct
{
  /** \brief Structure describing the memory block used to buffer the message fragments */
  TcpIp_IkeV2_MemoryType reassembledFragments;
  /** \brief List of instanciated structures describing the message fragments with
      TCPIP_IKEV2_SKF_MAX_FRAGMENTS_RX elements */
  TcpIp_IkeV2_FragmentInfoType fragmentInfos[TCPIP_IKEV2_SKF_MAX_FRAGMENTS_RX];
  /** \brief Number of total fragments used in the fragmented reception */
  uint16 totalFragments;
  /** \brief Maximum supported length of the payload of a decrypted fragment in bytes */
  uint16 decryptedContentMaxLen;
  /** \brief Next payload identifier of the original (re)assembled message */
  uint8 nextPayload;
} TcpIp_IkeV2_FragmentedRxInfoType;

#endif /* (TCPIP_IKEV2_FRAGMENTATION_ENABLED == STD_ON) */

/** \brief Structure describing an IKEv2 Security Association (SA). */
typedef struct
{
  /** \brief Timer to detect retransmission timeouts. */
  uint32 retransTimer;
#if (TCPIP_IKEV2_DPD_ENABLED == STD_ON)
  /** \brief Timer to detect dead peer (dead-peer-detection) timeouts. */
  uint32 dpdTimer;
#endif /*  (TCPIP_IKEV2_DPD_ENABLED == STD_ON) */
  /** \brief Timer to detect IKEv2 SA timeouts. */
  uint32 ikeSaTimer;
  /** \brief ID of the request message that is going to be transmitted next. */
  uint32 NextTxMessageId;
  /** \brief ID of the request message that is expected to be received next. */
  uint32 NextRxMessageId;
  /** \brief Memory block containing the init message transmitted by the local peer. */
  TcpIp_IkeV2_MemoryType localInitMessage;
  /** \brief Memory block containing the received init message from the remote peer. */
  TcpIp_IkeV2_MemoryType remoteInitMessage;
  /** \brief Size of the nonce sent by the remote peer in bytes. */
  uint16 nonceRemoteSize;

#if (TCPIP_IKEV2_FRAGMENTATION_ENABLED == STD_ON)
  /** \brief If fragmentation is disabled the memory block contains the last transmitted message. If
      fragmentation is enabled it contains a list of all the message fragments corresponding to the
      last transmission. */
  TcpIp_IkeV2_MemoryType lastTransmitMsgs[TCPIP_IKEV2_SKF_MAX_FRAGMENTS_TX];
  /** \brief If fragmentation is enabled the structure contains data related to the currently ongoing
      fragmented reception */
  TcpIp_IkeV2_FragmentedRxInfoType fragmentedRxInfo;
#else
  TcpIp_IkeV2_MemoryType lastTransmitMsgs[1U];
#endif /* (TCPIP_IKEV2_FRAGMENTATION_ENABLED == STD_ON) */
  /** \brief State the SA is currently in. */
  TcpIp_IkeV2_stateType state;
  /** \brief SPI of the initiator peer. */
  uint8 initiatorIkeSpi[TCPIP_IKEV2_IKE_SPI_SIZE];
  /** \brief SPI of the responder peer. */
  uint8 responderIkeSpi[TCPIP_IKEV2_IKE_SPI_SIZE];
  /** \brief Concatenation of initiator and responder nonces. */
  uint8 nonceCombined[TCPIP_IKEV2_MAX_COMBINED_NONCE_SIZE];
  /** \brief SHA-1 hash of the message received last. */
  uint8 lastReceiveMsgHash[TCPIP_IKEV2_MSG_HASH_LENGTH];
  /** \brief Number of retransmit of the last transmit message. */
  uint8 numOfRetransmits;
  /** \brief Index of the beginning of the remote nonce inside nonceCombined. */
  uint8 remoteNonceOffset;
  /** \brief Index of the beginning of the local nonce inside nonceCombined. */
  uint8 localNonceOffset;
  /** \brief Index of the next SA in the linked list of SAs. */
  uint8 nextIkeSaIdx;
  /** \brief Index of the chosen proposal for Ike */
  uint8 IkeProposalChosen;
  /** \brief Flag determining if the local peer is the IKE initiator (TRUE) or the responder (FALSE).
   * re keying currently not supported this value is the same for IKE and IPsec SA*/
  boolean isIkeInitiator;
#if (TCPIP_IKEV2_FRAGMENTATION_ENABLED == STD_ON)
  /** \brief Flag determining whether this communication can use fragmentation (TRUE) or not (FALSE). */
  boolean isFragmentationEnabled;
#endif /* (TCPIP_IKEV2_FRAGMENTATION_ENABLED == STD_ON) */
} TcpIp_IkeV2_SaRuntimeDataType;

/** \brief Structure describing a IKE connection */
typedef struct
{
  /** \brief Identification of the UDP socket used by the IKE connection */
  TcpIp_SocketIdType socketId;
  /** \brief Index of the first SA in the linked list for this IKE connection. */
  uint8 headIkeSaIdx;
  /** \brief State this IKE connection is in. */
  uint8 state;
  /** \brief IKE SA deletion necessary because the socket for IKE communication closed */
  boolean socketClosedDelPending;
} TcpIp_IkeV2_ConnectionRuntimeDataType;

/** \brief Structure referencing data needed for IKEv2 communication. */
typedef struct
{
  /** \brief Pointer to the memory location where the IKEv2 configuration is saved. */
  P2CONST(TcpIp_IkeV2SecurityAssociationCommonConfigType, AUTOMATIC, TCPIP_APPL_DATA) ikeSaCommonConfigPtr;
  /** \brief Pointer to the memory location where the IKEv2 SA configuration is saved. */
  P2CONST(TcpIp_IkeV2SecurityAssociationConfigType, AUTOMATIC, TCPIP_APPL_DATA) ikeSaConfigPtr;
  /** \brief Pointer to the memory location where the IKEv2 SA runtime data is saved. */
  P2VAR(TcpIp_IkeV2_SaRuntimeDataType, AUTOMATIC, TCPIP_APPL_DATA) ikeSaRtDataPtr;
  /** \brief Pointer to the memory location where the IKEv2 connection configuration is saved. */
  P2CONST(TcpIp_IkeV2ConnectionConfigType, AUTOMATIC, TCPIP_APPL_DATA) ikeConnectionConfigPtr;
  /** \brief Pointer to the memory location where the IKEv2 connection runtime data is saved. */
  P2VAR(TcpIp_IkeV2_ConnectionRuntimeDataType, AUTOMATIC, TCPIP_APPL_DATA) ikeConnectionRtDataPtr;
  /** \brief Security Parameter Index (SPI) helper */
  uint32 spiPlaceHolder;
  /** \brief Index where the Diffie-Hellman public key of the remote peer is stored inside the remote INIT
      message referenced saved by remoteInitMessage. */
  uint16 dhKeyRemoteMemIndex;
  /** \brief index of the current IKE SA */
  uint8 currentIkeSaIdx;
  /** \brief message type of the current received message */
  uint8 currentMsgType;
  /** \brief Index of the local Certificate Authority (CA) certificate that matches the one from the
      certificate request sent by the remote. */
  uint8 matchingCACertificateIdx;
  /** \brief Index of the chosen remote SA proposal */
  uint8 remoteProposalChosen;
  /** \brief Index of the chosen proposal for IPsec */
  uint8 remoteChildProposalChosen;
} TcpIp_IkeV2_DataType;

/** \brief Function pointer type of functions that handle encryption and decryption of data.
 *
 * \param[in] ikeSaConfigPtr Pointer to the IKE SA configuration.
 * \param[in] ikeSaCommonConfigPtr Pointer to the IKE configuration.
 * \param[in] initializationVectorPtr Pointer to the initialization vector.
 * \param[in] initializationVectorSize Size of the initialization vector in bytes.
 * \param[in,out] memoryBlockPtr Pointer to the memory block for the encrypted/decrypted message.
 *
 * \return Result of operation.
 * \retval E_OK Operation successful.
 * \retval E_NOT_OK Operation not successful.
 */
typedef P2FUNC(Std_ReturnType, TCPIP_CODE, TcpIp_IkeV2_Crypt_FctPtrType)
(
  P2VAR(TcpIp_IkeV2_DataType, AUTOMATIC, TCPIP_APPL_DATA) ikeDataPtr,
  P2CONST(uint8, AUTOMATIC, TCPIP_APPL_DATA) initializationVectorPtr,
  uint16 initializationVectorSize,
  P2VAR(TcpIp_IkeV2_MemoryType, AUTOMATIC, TCPIP_APPL_DATA) memoryBlockPtr
);

/** \brief Function pointer type of functions that handle generation of the initialization vector.
 *
 * \param[in] jobId JobId for csm random generator.
 * \param[out] resultPtr Pointer to the initialization vector.
 * \param[in,out] resultLengthPtr Size of the initialization vector in bytes.
 *
 * \return Result of operation.
 * \retval E_OK Operation successful.
 * \retval E_NOT_OK Operation not successful.
 */
typedef P2FUNC(Std_ReturnType, TCPIP_CODE, TcpIp_IkeV2_GenerateIv_FctPtrType)
(
  uint32 jobId,
  P2VAR(uint8,  AUTOMATIC, CSM_APPL_DATA) resultPtr,
  P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) resultLengthPtr
);

/** \brief Structure to reference the functions that handle encryption and decryption of data. */
typedef struct
{
  /** \brief Pointer to the encryption function. */
  TcpIp_IkeV2_Crypt_FctPtrType encryptPtr;
  /** \brief Pointer to the decryption function. */
  TcpIp_IkeV2_Crypt_FctPtrType decryptPtr;
  /** \brief Pointer to the generate initialization vector function. */
  TcpIp_IkeV2_GenerateIv_FctPtrType generateIvPtr;
} TcpIp_IkeV2_DispatchType;

/*==================[external function declarations]========================*/
#define TCPIP_START_SEC_CODE
#include <TcpIp_MemMap.h>

/** \brief Function processes the messages in the rx Buffer
 *
 * The messages in the rx buffer will be processed until no unprocessed message is left
 * or a complete circle is completed
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_rxData_processMsgFromRxBuffer
(
  void
);

/** \brief Function to reset buffer data
 *
 * The buffer is reset by setting all isPending members to FALSE and resetting the
 * TcpIp_IkeV2_rxBufferIdxIn/TcpIp_IkeV2_rxBufferIdxOut buffer pointers
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_rxData_resetRxBuffer
(
  void
);

/** \brief Function will get length of the init message
 *
 * This function will get length of the init message
 *
 * \param[in] ikeDataPtr     Pointer to the data needed for IKEv2 communication
 * \param[in] isRequestMsg   States if message is a request
 *
 * \return length of the init message
 */
TS_MOD_PRIV_DECL FUNC(uint16, TCPIP_CODE) TcpIp_IkeV2_txData_getInitMsgSize
(
  P2VAR(TcpIp_IkeV2_DataType, AUTOMATIC, TCPIP_APPL_DATA) ikeDataPtr,
  boolean isRequestMsg
);

/** \brief Function will allocate memory for auth message
 *
 * This function will get length of the auth message and allocate the memorys
 *
 * \param[in] ikeDataPtr         Pointer to the data needed for IKEv2 communication
 * \param[in] memoryBlockPtr     Pointer to structure describing a memory
 *                               block used to store IKEv2 messages
 * \param[in] isRequestMsg       States if message is a request
 *
 * \return Result of operation
 * \return TCPIP_OK           Memory allocation successful
 * \return TCPIP_E_NOT_OK     Memory allocation failed
 */
TS_MOD_PRIV_DECL FUNC(TcpIp_ReturnType, TCPIP_CODE) TcpIp_IkeV2_txData_getAuthMsgMemoryBlock
(
  P2VAR(TcpIp_IkeV2_DataType, AUTOMATIC, TCPIP_APPL_DATA) ikeDataPtr,
  P2VAR(TcpIp_IkeV2_MemoryType, AUTOMATIC, TCPIP_APPL_DATA) memoryBlockPtr,
  boolean isRequestMsg
);

/** \brief Function will transmit the init message
 *
 * This function will build and transmit the init message
 *
 * \param[in] ikeDataPtr                          Pointer to the data needed for IKEv2 communication
 * \param[in] memoryBlockPtr                      Pointer to structure describing a memory
 *                                                block used to store IKEv2 messages
 * \param[in] isRequestMsg                        States if message is a request
 *
 * \return Result of operation
 * \return TCPIP_OK           Transmission successful
 * \return TCPIP_E_NOT_OK     Transmission failed
 */
TS_MOD_PRIV_DECL FUNC(TcpIp_ReturnType, TCPIP_CODE) TcpIp_IkeV2_txData_transmitInitMsg
(
  P2VAR(TcpIp_IkeV2_DataType, AUTOMATIC, TCPIP_APPL_DATA) ikeDataPtr,
  P2VAR(TcpIp_IkeV2_MemoryType, AUTOMATIC, TCPIP_APPL_DATA) memoryBlockPtr,
  boolean isRequestMsg
);

/** \brief Function will transmit the auth message
 *
 * This function will build and transmit the auth message
 *
 * \param[in] ikeDataPtr                          Pointer to the data needed for IKEv2 communication
 * \param[in] memoryBlockPtr                      Pointer to structure describing a memory
 *                                                block used to store IKEv2 messages
 * \param[in] isRequestMsg                        States if message is a request
 *
 * \return Result of operation
 * \return TCPIP_OK           Transmission successful
 * \return TCPIP_E_NOT_OK     Transmission failed
 */
TS_MOD_PRIV_DECL FUNC(TcpIp_ReturnType, TCPIP_CODE) TcpIp_IkeV2_txData_transmitAuthMsg
(
  P2VAR(TcpIp_IkeV2_DataType, AUTOMATIC, TCPIP_APPL_DATA) ikeDataPtr,
  P2VAR(TcpIp_IkeV2_MemoryType, AUTOMATIC, TCPIP_APPL_DATA) memoryBlockPtr,
  boolean isRequestMsg
);

/** \brief Function will transmit the notify message
 *
 * This function will build and transmit a notify message
 *
 * \param[in] ikeDataPtr           Pointer to the data needed for IKEv2 communication
 * \param[in] msgType              Notify message type
 * \param[in] notifyType           Type of the notify payload
 * \param[in] isRequestMsg         States if message is a request
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_txData_transmitNotifyMsg
(
  P2VAR(TcpIp_IkeV2_DataType, AUTOMATIC, TCPIP_APPL_DATA) ikeDataPtr,
  uint8 msgType,
  uint16 notifyType,
  boolean isRequestMsg
);

/** \brief Function will transmit an empty informational message
 *
 * This function will build and transmit  an empty informational message
 *
 * \param[in] ikeDataPtr           Pointer to the data needed for IKEv2 communication
 * \param[in] isRequestMsg         States if message is a request
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_txData_transmitEmptyInfoMsg
(
  P2VAR(TcpIp_IkeV2_DataType, AUTOMATIC, TCPIP_APPL_DATA) ikeDataPtr,
  boolean isRequestMsg
);

/** \brief Function will transmit the Informational delete message
 *
 * This function will build and transmit an Informational delete message
 *
 * \param[in] ikeDataPtr           Pointer to the data needed for IKEv2 communication
 * \param[in] spi                  SPI of the SA to be deleted
 * \param[in] protocolId           IPsec protocol of the SA to be deleted
 * \param[in] isRequestMsg         States if message is a request
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_txData_transmitDeleteMsg
(
  P2VAR(TcpIp_IkeV2_DataType, AUTOMATIC, TCPIP_APPL_DATA) ikeDataPtr,
  uint32 spi,
  uint8 protocolId,
  boolean isRequestMsg
);

/** \brief Function will retransmit the last transmitted message
 *
 * This function will retransmit the last transmitted message
 *
 * \param[in] ikeDataPtr           Pointer to the data needed for IKEv2 communication
 *
 * \return Result of operation
 * \return TCPIP_OK           Transmission successful
 * \return TCPIP_E_NOT_OK     Transmission failed
 */
TS_MOD_PRIV_DECL FUNC(TcpIp_ReturnType, TCPIP_CODE) TcpIp_IkeV2_txData_retransmit
(
  P2VAR(TcpIp_IkeV2_DataType, AUTOMATIC, TCPIP_APPL_DATA) ikeDataPtr
);

#if (TCPIP_IKEV2_LOCAL_SIGNATURE_ENABLED == STD_ON)
/** \brief Function builds the certificate payload
 *
 * This function builds the certificate payload, or multiple certificate payoads(certificate chain)
 * depending on the received CA in the certificate request payload
 *
 * \param[in] ikeConnectionConfigPtr    Pointer to the IKEv2 connection configuration
 * \param[in] matchingCACertificateIdx  Certificate that matches the one from the
                                        certificate request sent by the remote
 * \param[in,out] prevPayloadPtr        pointer to set next and current payload type
 *                                      in: pointer to the previous palyoad
 *                                      out: pointer to the current payload
 * \param[in] payloadPtr                pointer to the buffer location where
 *                                      certificate data is copied to
 *
 * \return E_OK       certificate payload assembled successfully
 * \return E_NOT_OK   certificate payload assembly failed
 */
TS_MOD_PRIV_DECL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_IkeV2_Cert_buildCert
(
  P2CONST(TcpIp_IkeV2ConnectionConfigType, AUTOMATIC, TCPIP_APPL_DATA) ikeConnectionConfigPtr,
  uint8 matchingCACertificateIdx,
  P2VAR(TcpIp_Uint8PtrType, AUTOMATIC, TCPIP_APPL_DATA) prevPayloadPtr,
  P2VAR(TcpIp_Uint8PtrType, AUTOMATIC, TCPIP_APPL_DATA) payloadPtr
);

/** \brief Function returns length of certificate payloads
 *
 * This function returns the length of all certificate payloads needed for transmission.
 * Length depends on size and number of Certificates (one certificate or chain of certificates)
 * that need to be transmitted.
 *
 * \param[in] ikeConnectionConfigPtr    Pointer to the IKEv2 connection configuration
 * \param[in] matchingCACertificateIdx  Certificate that matches the one from the
                                        certificate request sent by the remote
 *
 * \return Length of Certificate payload/s
 */
TS_MOD_PRIV_DECL FUNC(uint16, TCPIP_CODE) TcpIp_IkeV2_Cert_getMaxCertificateSize
(
  P2CONST(TcpIp_IkeV2ConnectionConfigType, AUTOMATIC, TCPIP_APPL_DATA) ikeConnectionConfigPtr,
  uint8 matchingCACertificateIdx
);

/** \brief Function builds the ID payload when certificates are used
 *
 * This function extracts the subject field from the certificate and builds the
 * ID payload for the IKE exchange.
 *
 * \param[in] ikeConnectionConfigPtr    Pointer to the IKEv2 connection configuration
 * \param[in] initiatorIdConfigPtr      Pointer to the structure describing an identification
 * \param[out] idPtr                    Pointer to the memory location where the ID shall be copied to
 *
 * \return Result of operation
 * \retval E_OK                 ID assembled successfully
 * \retval E_NOT_OK             ID assembly failed
 */
TS_MOD_PRIV_DECL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_IkeV2_Cert_buildCertId
(
  P2CONST(TcpIp_IkeV2ConnectionConfigType, AUTOMATIC, TCPIP_APPL_DATA) ikeConnectionConfigPtr,
  P2VAR(TcpIp_IkeV2_IdentificationType, AUTOMATIC, TCPIP_APPL_DATA) initiatorIdConfigPtr,
  P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) idPtr
);

/** \brief Function finds the if any requested certificate are the same as local CA
 *
 * This function checks all CA received in the certificate request payload and searches for a
 * matching CA that is configured locally.
 *
 * \param[in] ikeDataPtr                pointer to the data needed for IKEv2 communication
 * \param[in] currentPayloadHdrPtr      pointer to the certificate request payload
 * \param[in] currentPayloadLength      length of the passed payload
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_Cert_processCertificateRequest
(
  P2VAR(TcpIp_IkeV2_DataType, AUTOMATIC, TCPIP_APPL_DATA) ikeDataPtr,
  P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) currentPayloadHdrPtr,
  uint16 currentPayloadLength
);
#endif /* (TCPIP_IKEV2_LOCAL_SIGNATURE_ENABLED == STD_ON) */

#if (TCPIP_IKEV2_REMOTE_SIGNATURE_ENABLED == STD_ON)

#if (TCPIP_IKEV2_MAX_REMOTE_ID_SIZE > 0U)
/** \brief Function initialize extracted ID
 *
 * This function sets the array holding the extracted certificate IDs to 0
 *
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_Cert_initExtractedCertificateId(void);

/** \brief Function extracts the identification from the certificate
 *
 * This functions extracts the required ID fields from the local certificate
 *
 * \param[in] ikeConnectionConfigPtr    Pointer to the IKEv2 connection configuration
 *
 * \return E_OK           extraction successful
 * \retval E_NOT_OK       extraction failed
 */
TS_MOD_PRIV_DECL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_IkeV2_Cert_extractCertID
(
  P2CONST(TcpIp_IkeV2ConnectionConfigType, AUTOMATIC, TCPIP_APPL_DATA) ikeConnectionConfigPtr
);
#endif /* (TCPIP_IKEV2_MAX_REMOTE_ID_SIZE > 0U) */

/** \brief Function returns the size of certificate request payload
 *
 * This function calculates the size needed for certificate request payload
 *
 * \param[in] ikeConnectionConfigPtr    Pointer to the IKEv2 connection configuration
 *
 * \return size of the certificate request payload
 */
TS_MOD_PRIV_DECL FUNC(uint16, TCPIP_CODE) TcpIp_IkeV2_Cert_getCertificateRequestSize
(
  P2CONST(TcpIp_IkeV2ConnectionConfigType, AUTOMATIC, TCPIP_APPL_DATA) ikeConnectionConfigPtr
);

/** \brief Function builds certificate request payload
 *
 * This function builds certificate request payload with locally configured CAs
 *
 * \param[in,out] prevPayloadPtr        pointer to set next and current payload type
 *                                      in: pointer to the previous palyoad
 *                                      out: pointer to the current payload
 * \param[in] payloadPtr                pointer to the buffer location where
 *                                      certificate request is copied to
 *
 * \return E_OK       certificate request assembled successfully
 * \return E_NOT_OK   certificate request assembly failed
 */
TS_MOD_PRIV_DECL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_IkeV2_Cert_buildCertReq
(
  P2VAR(TcpIp_Uint8PtrType, AUTOMATIC, TCPIP_APPL_DATA) prevPayloadPtr,
  P2VAR(TcpIp_Uint8PtrType, AUTOMATIC, TCPIP_APPL_DATA) payloadPtr
);

/** \brief Function will process the certificates and verify the authentication payload
 *
 * This function will extract all received certificates, verify the entire certificate chain
 * and use the received certificate to verify the authentication payload (digital signature)
 *
 * \param[in] remoteIdPtr                   pointer to the remote identification data
 * \param[in] ikeDataPtr                    pointer to the data needed for IKEv2 communication
 * \param[in] authenticationPayloadHdrPtr   pointer to the authentication payload
 * \param[in] authenticationPayloadLength   length of the authentication payload
 * \param[in] dataPtr                       pointer to the certificate payload
 * \param[in] dataLength                    length of the certificate payload
 * \param[in] nextPayloadIdIn               next payload type
 *
 *
 * \return Result of operation
 * \retval TCPIP_IKEV2_E_OK                        certificate and authentication data are valid
 * \retval TCPIP_IKEV2_E_AUTHENTICATION_FAILED     Authentication failed
 * \retval TCPIP_IKEV2_E_INVALID_SYNTAX            Invalid payload syntax
 */
TS_MOD_PRIV_DECL FUNC(TcpIp_IkeV2_ReturnType, TCPIP_CODE) TcpIp_IkeV2_Cert_processCertificateAuthData
(
  P2CONST(TcpIp_IkeV2_IdentificationType, AUTOMATIC, TCPIP_APPL_DATA) remoteIdPtr,
  P2VAR(TcpIp_IkeV2_DataType, AUTOMATIC, TCPIP_APPL_DATA) ikeDataPtr,
  P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) authenticationPayloadHdrPtr,
  uint16 authenticationPayloadLength,
  P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) dataPtr,
  uint16 dataLength,
  uint8 nextPayloadIdIn
);

/** \brief Function verifies identification payload
 *
 * This function verifies the identification payload with the configured certificate data
 *
 * \param[in] remoteAuthConfigPtr    Pointer to the configuration containing the authentication data
 * \param[in] idPtr                  Pointer to the start of the identification data
 * \param[in] idLength               Identification length
 *
 *
 * \return Result of operation
 * \retval TCPIP_IKEV2_E_OK                        Identification valid
 * \retval TCPIP_IKEV2_E_AUTHENTICATION_FAILED     Authentication failed
 * \retval TCPIP_IKEV2_E_INVALID_SYNTAX            Invalid payload syntax
 */
TS_MOD_PRIV_DECL FUNC(TcpIp_IkeV2_ReturnType, TCPIP_CODE) TcpIp_IkeV2_Cert_verifyIdentification
(
  P2CONST(TcpIp_IkeV2AuthConfigType, AUTOMATIC, TCPIP_APPL_DATA) remoteAuthConfigPtr,
  P2CONST(uint8, AUTOMATIC, TCPIP_APPL_DATA) idPtr,
  uint16 idLength
);
#endif /* (TCPIP_IKEV2_REMOTE_SIGNATURE_ENABLED == STD_ON) */

TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_SM_startIkeSA
(
  P2CONST(TcpIp_IkeV2ConnectionConfigType, AUTOMATIC, TCPIP_APPL_DATA) ikeConnectionConfigPtr,
  P2VAR(TcpIp_IkeV2_ConnectionRuntimeDataType, AUTOMATIC, TCPIP_APPL_DATA) ikeConnectionRtDataPtr,
  uint8 selDhPropodalIdx
);

TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_SM_stopIkeSA
(
  P2VAR(TcpIp_IkeV2_DataType, AUTOMATIC, TCPIP_APPL_DATA) ikeDataPtr
);

TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_SM_stopAllIkeSAs
(
  P2VAR(TcpIp_IkeV2_ConnectionRuntimeDataType, AUTOMATIC, TCPIP_APPL_DATA) ikeConnectionRtDataPtr,
  P2CONST(TcpIp_IkeV2ConnectionConfigType, AUTOMATIC, TCPIP_APPL_DATA) ikeConnectionConfigPtr,
  boolean transmitDelete,
  uint8 keepIkeSa
);

#if (TCPIP_IKEV2_DPD_ENABLED == STD_ON)
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_SM_dpdTimeout
(
  P2VAR(TcpIp_IkeV2_DataType, AUTOMATIC, TCPIP_APPL_DATA) ikeDataPtr
);
#endif /*  (TCPIP_IKEV2_DPD_ENABLED == STD_ON) */

TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_SM_retranTimeout
(
  P2VAR(TcpIp_IkeV2_DataType, AUTOMATIC, TCPIP_APPL_DATA) ikeDataPtr
);

TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_SM_ikeSaTimeout
(
  P2VAR(TcpIp_IkeV2_DataType, AUTOMATIC, TCPIP_APPL_DATA) ikeDataPtr
);

TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_SM_rcvResponse
(
  P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) ikeMsgHdrPtr,
  P2VAR(TcpIp_IkeV2_DataType, AUTOMATIC, TCPIP_APPL_DATA) ikeDataPtr,
  uint16 ikeMsgLength
);

TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_SM_rcvRequest
(
  P2VAR(TcpIp_IkeV2_DataType, AUTOMATIC, TCPIP_APPL_DATA) ikeDataPtr,
  P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) ikeMsgHdrPtr,
  uint16 ikeMsgLength
);

TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_SM_requestDeletionOfIkeSA
(
  P2VAR(TcpIp_IkeV2_DataType, AUTOMATIC, TCPIP_APPL_DATA) ikeDataPtr
);

TS_MOD_PRIV_DECL FUNC(TcpIp_ReturnType, TCPIP_CODE) TcpIp_IkeV2_SM_retransmitFailed
(
  P2VAR(TcpIp_IkeV2_DataType, AUTOMATIC, TCPIP_APPL_DATA) ikeDataPtr
);

TS_MOD_PRIV_DECL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_IkeV2_generateKeys
(
  P2CONST(TcpIp_IkeV2ProposalSpecificConfigType, AUTOMATIC, TCPIP_APPL_DATA) ikeProposalSpecificConfigPtr,
  P2CONST(TcpIp_IpSec_KeyGenerationConfigType, AUTOMATIC, TCPIP_APPL_DATA) keyGenerationPtr,
  P2CONST(uint8, AUTOMATIC, TCPIP_APPL_DATA) customKeyGenerationOderPtr,
  uint8 numOfKeys,
  P2VAR(TcpIp_Crypto_FragmentType, AUTOMATIC, TCPIP_APPL_DATA) dataFragsPtr,
  uint8 numOfDataFragments
);

TS_MOD_PRIV_DECL FUNC_P2CONST(TcpIp_IkeV2SecurityAssociationConfigType, TCPIP_APPL_DATA, TCPIP_CODE)
  TcpIp_IkeV2_getSecurityAssociationCfg
(
  uint8 ikeSaIndex,
  uint8 selectedProposalIdx,
  P2CONST(TcpIp_IkeV2SecurityAssociationCommonConfigType, AUTOMATIC, TCPIP_APPL_DATA) ikeSaCommonConfigPtr
);

TS_MOD_PRIV_DECL FUNC_P2CONST(TcpIp_IkeV2ProposalSpecificConfigType, TCPIP_APPL_DATA, TCPIP_CODE)
  TcpIp_IkeV2_getProposalSpecificCfg
(
  uint8 selectedProposalIdx,
  P2CONST(TcpIp_IkeV2SecurityAssociationCommonConfigType, AUTOMATIC, TCPIP_APPL_DATA) ikeSaCommonConfigPtr
);

#if (TCPIP_IKEV2_LOCAL_SIGNATURE_ENABLED == STD_ON) || (TCPIP_IKEV2_REMOTE_SIGNATURE_ENABLED == STD_ON)
/** \brief Function builds the ASN.1 header
 *
 * This function builds the asn.1 header for the passed payload.
 *
 * \param[in] memoryDataPtr     Pointer to the data
 * \param[in] idLength          length of passed data
 *
 * \return lenth of ASN.1 header which is inserted
 */
TS_MOD_PRIV_DECL FUNC(uint16, TCPIP_CODE) TcpIp_IkeV2_generateAsnHdr
(
  P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) memoryDataPtr,
  uint32 idLength
);
#endif /* (TCPIP_IKEV2_LOCAL_SIGNATURE_ENABLED == STD_ON) || (TCPIP_IKEV2_REMOTE_SIGNATURE_ENABLED == STD_ON) */

/** \brief Function initializes newly allocated SA
 *
 * This function initializes newly allocated SA
 *
 * \param[in] ikeSaRtDataPtr      Pointer to the runtime data related to IKE Security associations
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_initializeSA
(
  P2VAR(TcpIp_IkeV2_SaRuntimeDataType, AUTOMATIC, TCPIP_APPL_DATA) ikeSaRtDataPtr
);

/** \brief Function generates child SA keys
 *
 * This function builds the needed keys for the child SA
 *
 * \param[in] ipSecSaIdx     Index of the IPsec SA
 * \param[in] ikeDataPtr     Pointer to the data needed for IKEv2 communication
 *
 * \return E_OK           key generated successfully
 * \retval E_NOT_OK       key generation failed
 */
TS_MOD_PRIV_DECL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_IkeV2_generateChildSAKeys
(
  uint8 ipSecSaIdx,
  P2VAR(TcpIp_IkeV2_DataType, AUTOMATIC, TCPIP_APPL_DATA) ikeDataPtr
);

/** \brief Function will allocate memory
 *
 * This function will get allocate memory for IKE communication
 *
 * \param[in,out] memoryBlockPtr    in: Pointer to structure describing a memory
 *                                      block used to store IKEv2 messages
 *                                  out: pointer to the allocated memory
 *
 * \return Result of operation
 * \return TCPIP_OK           Memory allocation successful
 * \return TCPIP_E_NOT_OK     Memory allocation failed
 */
TS_MOD_PRIV_DECL FUNC(TcpIp_ReturnType, TCPIP_CODE) TcpIp_IkeV2_getMemoryBlock
(
  P2VAR(TcpIp_IkeV2_MemoryType, AUTOMATIC, TCPIP_APPL_DATA) memoryBlockPtr
);

/** \brief Function will free allocated memory
 *
 * This function will check if memory ID is valid and free the allocated memory
 *
 * \param[in] memoryBlockPtr    Pointer to structure describing a memory
 *                              block used to store IKEv2 messages
 * \param[in] clearCryptData    If memoryCryptDataPtr is set to 0U
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_freeMemoryBlock
(
  P2VAR(TcpIp_IkeV2_MemoryType, AUTOMATIC, TCPIP_APPL_DATA) memoryBlockPtr,
  boolean clearCryptData
);

/** \brief Function will set member variables to cleared values
 *
 * This function will clear the member variables of the memoryBlockPtr
 *
 * \param[in] memoryBlockPtr    Pointer to memoryBlock to be nullified
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_nullifyMemoryBlock
(
  P2VAR(TcpIp_IkeV2_MemoryType, AUTOMATIC, TCPIP_APPL_DATA) memoryBlockPtr
);

/** \brief Function will transfer a memoryBlock between two locations
 *
 * This function copies the memoryBlockSrcPtr to memoryBlockDestPtr and
 * invalidates the memoryBlockSrcPtr such that it can be no longer used
 *
 * \param[in, out] memoryBlockDestPtr  in: Pointer to the destination memory block
 *                                     out:  Pointer to the source memory block
 * \param[in, out] memoryBlockSrcPtr   in: Pointer to the source memory block
 *                                     out:  Pointer to invalid memory block
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_transferMemoryBlock
(
  P2VAR(TcpIp_IkeV2_MemoryType, AUTOMATIC, TCPIP_APPL_DATA) memoryBlockDestPtr,
  P2VAR(TcpIp_IkeV2_MemoryType, AUTOMATIC, TCPIP_APPL_DATA) memoryBlockSrcPtr
);

/** \brief Function will free memory of the last transmitted message
 *
 * This function frees the memory used to store last transmitted message
 *
 * \param[in] ikeSaRtDataPtr      Pointer to the runtime data related to IKE Security associations
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_freeTransmitMsgsMemory
(
  P2VAR(TcpIp_IkeV2_SaRuntimeDataType, AUTOMATIC, TCPIP_APPL_DATA) ikeSaRtDataPtr
);

#if (TCPIP_IKEV2_FRAGMENTATION_ENABLED == STD_ON)

/** \brief Function will free memory used for reassembly
 *
 * This function will free memory used for reassembly
 *
 * \param[in] fragmentedRxInfoPtr     pointer to the structure describing the fragmented reception
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_resetFragmentedRxData
(
  P2VAR(TcpIp_IkeV2_FragmentedRxInfoType, AUTOMATIC, TCPIP_APPL_DATA) fragmentedRxInfoPtr
);

#endif /* (TCPIP_IKEV2_FRAGMENTATION_ENABLED == STD_ON) */

/** \brief get a random SPI
 *
 * This function will get a new random SPI
 *
 * \param[out] spiPtr      point to the memory location where the SPI will be stored
 * \param[in]  spiSizeIn   requested SPI length
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_getNewRandomSpi
(
  P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) spiPtr,
  uint8 spiSizeIn
);

#if (TCPIP_IKEV2_ENCRYPT_ENABLED == STD_ON)

/** \brief This function will encrypt a given payload
 *
 * This function will  encrypt the given payload and generate the integrity checksum.
 *
 * \param[in] ikeDataPtr                 Pointer to the data needed for IKEv2 communication
 * \param[in] initializationVectorPtr    Pointer to the IV used for encryption
 * \param[in] initializationVectorSize   Size of the passed IV
 * \param[in,out] memoryBlockPtr         Pointer to the memory block for the encrypted/decrypted message.
 *
 * \return Result of operation
 * \return TCPIP_OK           encryption successful
 * \return TCPIP_E_NOT_OK     encryption failed
 */
TS_MOD_PRIV_DECL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_IkeV2_encrypt
(
  P2VAR(TcpIp_IkeV2_DataType, AUTOMATIC, TCPIP_APPL_DATA) ikeDataPtr,
  P2CONST(uint8, AUTOMATIC, TCPIP_APPL_DATA) initializationVectorPtr,
  uint16 initializationVectorSize,
  P2VAR(TcpIp_IkeV2_MemoryType, AUTOMATIC, TCPIP_APPL_DATA) memoryBlockPtr
);

/** \brief This function will decrypt a given payload
 *
 * This function will  decrypt the given payload.
 *
 * \param[in] ikeDataPtr                 Pointer to the data needed for IKEv2 communication
 * \param[in] initializationVectorPtr    Pointer to the IV used for decryption
 * \param[in] initializationVectorSize   Size of the passed IV
 * \param[in,out] memoryBlockPtr         Pointer to the memory block for the encrypted/decrypted message.
 *
 * \return Result of operation
 * \return TCPIP_OK           decryption successful
 * \return TCPIP_E_NOT_OK     decryption failed
 */
TS_MOD_PRIV_DECL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_IkeV2_decrypt
(
  P2VAR(TcpIp_IkeV2_DataType, AUTOMATIC, TCPIP_APPL_DATA) ikeDataPtr,
  P2CONST(uint8, AUTOMATIC, TCPIP_APPL_DATA) initializationVectorPtr,
  uint16 initializationVectorSize,
  P2VAR(TcpIp_IkeV2_MemoryType, AUTOMATIC, TCPIP_APPL_DATA) memoryBlockPtr
);

#endif /* (TCPIP_IKEV2_ENCRYPT_ENABLED == STD_ON) */

#if (TCPIP_IKEV2_AEAD_ENABLED == STD_ON)

/** \brief This function will encrypt a given payload
 *
 * This function will perform AEAD encryption of a given payload.
 *
 * \param[in] ikeDataPtr                 Pointer to the data needed for IKEv2 communication
 * \param[in] initializationVectorPtr    Pointer to the IV used for encryption
 * \param[in] initializationVectorSize   Size of the passed IV
 * \param[in,out] memoryBlockPtr         Pointer to the memory block for the encrypted/decrypted message.
 *
 * \return Result of operation
 * \return TCPIP_OK           encryption successful
 * \return TCPIP_E_NOT_OK     encryption failed
 */
TS_MOD_PRIV_DECL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_IkeV2_aeadEncrypt
(
  P2VAR(TcpIp_IkeV2_DataType, AUTOMATIC, TCPIP_APPL_DATA) ikeDataPtr,
  P2CONST(uint8, AUTOMATIC, TCPIP_APPL_DATA) initializationVectorPtr,
  uint16 initializationVectorSize,
  P2VAR(TcpIp_IkeV2_MemoryType, AUTOMATIC, TCPIP_APPL_DATA) memoryBlockPtr
);

/** \brief This function will decrypt a given payload
 *
 * This function will perform AEAD decryption of a given payload.
 *
 * \param[in] ikeDataPtr                 Pointer to the data needed for IKEv2 communication
 * \param[in] initializationVectorPtr    Pointer to the IV used for decryption
 * \param[in] initializationVectorSize   Size of the passed IV
 * \param[in,out] memoryBlockPtr         Pointer to the memory block for the encrypted/decrypted message.
 *
 * \return Result of operation
 * \return TCPIP_OK           decryption successful
 * \return TCPIP_E_NOT_OK     decryption failed
 */
TS_MOD_PRIV_DECL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_IkeV2_aeadDecrypt
(
  P2VAR(TcpIp_IkeV2_DataType, AUTOMATIC, TCPIP_APPL_DATA) ikeDataPtr,
  P2CONST(uint8, AUTOMATIC, TCPIP_APPL_DATA) initializationVectorPtr,
  uint16 initializationVectorSize,
  P2VAR(TcpIp_IkeV2_MemoryType, AUTOMATIC, TCPIP_APPL_DATA) memoryBlockPtr
);
/** \brief Generation of the initialization vector.
 *
 * This function generates initialization vector by using pseudo number generator.
 *
 * \param[in] jobId JobId for csm random generator.
 * \param[out] resultPtr Pointer to the initialization vector.
 * \param[in] resultLengthPtr Size of the initialization vector in bytes.
 *
 * \return Result of operation.
 * \retval E_OK Operation successful.
 */
TS_MOD_PRIV_DECL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_IkeV2_getNewRandomIv
(
  uint32 jobId,
  P2VAR(uint8,  AUTOMATIC, CSM_APPL_DATA) resultPtr,
  P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) resultLengthPtr
);

#endif /* (TCPIP_IKEV2_AEAD_ENABLED == STD_ON) */


/** \brief Get traffic selector information
 *
 * This function returns traffic selector information for the selected type
 *
 * \param[in] ipType        Address type
 *
 * \return traffic selector information
 */
TS_MOD_PRIV_DECL FUNC(TcpIp_IkeV2_TrafficSelInfoType, TCPIP_CODE) TcpIp_IkeV2_getSelInfo
(
  uint8 ipType
);


/** \brief This function will generate maced key pad
 *
 * This function will generate maced key pad used for authentication
 *
 * \param[in] ikeProposalSpecificConfigPtr      Pointer to the proposal specific configurations
 * \param[in] preSharedKeyId                    ID of the preshared key
 * \param[out] generatedKeyPtr                  memory location where the key pad will be saved
 * \param[in,out] generatedKeyLengthPtr         in: size of the memory were the key pad will be stored
 *                                              out: size of the generated key pad
 *
 * \return Result of operation
 * \return TCPIP_OK           operation successful
 * \return TCPIP_E_NOT_OK     operation failed
 */
TS_MOD_PRIV_DECL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_IkeV2_generateMacedKeyPad
(
  P2CONST(TcpIp_IkeV2ProposalSpecificConfigType, AUTOMATIC, TCPIP_APPL_DATA) ikeProposalSpecificConfigPtr,
  uint32 preSharedKeyId,
  P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) generatedKeyPtr,
  P2VAR(uint32, AUTOMATIC, TCPIP_APPL_DATA) generatedKeyLengthPtr
);

/** \brief This function will generate maced ID
 *
 * This function will generate maced ID used for authentication
 *
 * \param[in] ikeProposalSpecificConfigPtr      Pointer to the proposal specific configurations
 * \param[in] ikeProposalSpecificConfigPtr      Pointer to the structure describing an identification
 * \param[out] generatedKeyPtr                  memory location where the ID will be saved
 * \param[in,out] generatedKeyLengthPtr         in: size of the memory were the key pad will be stored
 *                                              out: size of the generated ID
 *
 * \return Result of operation
 * \return TCPIP_OK           operation successful
 * \return TCPIP_E_NOT_OK     operation failed
 */
TS_MOD_PRIV_DECL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_IkeV2_generateMacedId
(
  uint32 skAuthKeyId,
  P2CONST(TcpIp_IkeV2ProposalSpecificConfigType, AUTOMATIC, TCPIP_APPL_DATA) ikeProposalSpecificConfigPtr,
  P2CONST(TcpIp_IkeV2_IdentificationType, AUTOMATIC, TCPIP_APPL_DATA) identifierConfigPtr,
  P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) generatedKeyPtr,
  P2VAR(uint32, AUTOMATIC, TCPIP_APPL_DATA) generatedKeyLengthPtr
);

/** \brief Get remote address
 *
 * This function will return the remote address for the specified IPsec connection
 *
 * \param[in] ipSecConnectionConfigPtr       Reference to ipSec connection configuration
 *
 * \return Pointer to the remote address
 */
TS_MOD_PRIV_DECL FUNC_P2CONST(uint32, TCPIP_APPL_DATA, TCPIP_CODE) TcpIp_IkeV2_getRemoteAddr
(
  P2CONST(TcpIp_IpSecConnectionConfigType, AUTOMATIC, TCPIP_APPL_DATA) ipSecConnectionConfigPtr
);

/** \brief This function checks if the current SA is the only active SA
 *
 * This function will check is the current SA is the only active SA on the selectec IPsec connection
 *
 * \param[in] ikeDataPtr                 Pointer to the data needed for IKEv2 communication
 *
 * \return Result of operation
 * \return true         only active SA
 * \return false        there are other active SA on this connection
 */
TS_MOD_PRIV_DECL FUNC(boolean, TCPIP_CODE) TcpIp_IkeV2_saIsOnlyActiveOne
(
  P2VAR(TcpIp_IkeV2_DataType, AUTOMATIC, TCPIP_APPL_DATA) ikeDataPtr
);

/** \brief Get a free IKE SA
 *
 * This function will return the index of a available free IKE SA if there are any
 *
 * \param[in] ikeSaCommonIdx            Pointer to the IKEv2 configuration
 * \param[in] ikeConnectionRtDataPtr    Pointer to the IKEv2 connection configuration
 * \param[in] isIkeInitiator            Determines if local host is IKE initiator of this IKE SA
 *
 * \return index of the free IKE SA
 */
TS_MOD_PRIV_DECL FUNC(uint8, TCPIP_CODE) TcpIp_IkeV2_getFreeIkeSA
(
  uint8 ikeSaCommonIdx,
  P2VAR(TcpIp_IkeV2_ConnectionRuntimeDataType, AUTOMATIC, TCPIP_APPL_DATA) ikeConnectionRtDataPtr,
  boolean isIkeInitiator
);

/** \brief Insert IKE SA
 *
 * This insert a new IKE SA into the linked list with nextEntryPtr pointing to the element
 * of the linked list to be shifted
 *
 * \param[in, out] nextEntryPtr     pointer to the nextEntry member of the previous element
 *                                  of the linked list where the new element shall be added
 * \param[in] ipSecIdx              ike SA index of the SA to be added to the linked list
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_insertIkeSa
(
  P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) nextEntryPtr,
  uint8 ikeSaIdx
);

#if (TCPIP_IKEV2_REMOTE_SIGNATURE_ENABLED == STD_ON)
/** \brief GET ASN.1 sequence length
 *
 * This function check the ASN.1 header and get the length of the sequence
 *
 * \param[in] dataPtr            Pointer to the data memory where the data is located
 * \param[in] dataLen            Length of the passed data
 * \param[out] sequenceLength    Length of the ASN.1 sequence
 * \param[out] payloadOffset     Offset of the sequence data
 *
 * \return Result of operation
 * \return TCPIP_OK           operation successful
 * \return TCPIP_E_NOT_OK     operation failed
 */
TS_MOD_PRIV_DECL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_IkeV2_getSequenceLength
(
  P2CONST(uint8, AUTOMATIC, TCPIP_APPL_DATA) dataPtr,
  uint16 dataLen,
  P2VAR(uint16, AUTOMATIC, TCPIP_APPL_DATA) sequenceLength,
  P2VAR(uint16, AUTOMATIC, TCPIP_APPL_DATA) payloadOffset
);
#endif /* (TCPIP_IKEV2_REMOTE_SIGNATURE_ENABLED == STD_ON) */

#if (TCPIP_IPSEC_ERROR_REPORT_FCT_ENABLED == STD_ON)
/** \brief Log IKE error
 *
 * This function will log the IKE error
 *
 * \param[in] ipSecConnectionIdx     IPsec connection index
 * \param[in] errorCode              Error code
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IkeV2_LogError
(
  uint8 ipSecConnectionIdx,
  uint8 errorCode
);
#endif /* (TCPIP_IPSEC_ERROR_REPORT_FCT_ENABLED == STD_ON) */

/** \brief Function returns the connection status
 *
 * This function returns true if the connection has open socket, no deletion
 * is requested because of the controler restarting and state of connection
 * is TCPIP_IKEV2_CONNECTION_STATE_ACTIVE
 *
 * \param[in]  ikeConnectionRtDataPtr    Local address id
 *
 * \return Result of operation
 * \return TRUE      connection is ready
 * \return FALSE     connection is not ready
 */
TS_MOD_PRIV_DECL FUNC(boolean, TCPIP_CODE) TcpIp_IkeV2_connectionIsReady
(
  P2VAR(TcpIp_IkeV2_ConnectionRuntimeDataType, AUTOMATIC, TCPIP_APPL_DATA) ikeConnectionRtDataPtr
);

#define TCPIP_STOP_SEC_CODE
#include <TcpIp_MemMap.h>
/*==================[external constants]====================================*/

#if (TCPIP_IKEV2_ENCRYPT_ENABLED == STD_ON) && (TCPIP_IKEV2_AEAD_ENABLED == STD_ON)

#define TCPIP_START_SEC_CONST_UNSPECIFIED
#include <TcpIp_MemMap.h>

/** \brief Contains pointers to the functions used to generate initialization vector,
    encrypt and decrypt data for both conventional encryption and authentication
    as well as authenticated encryption with associated data (AEAD).
    */
extern CONST(TcpIp_IkeV2_DispatchType,TCPIP_CONST)
  TcpIp_IkeV2_DispatchArray[TCPIP_IKEV2_NUM_CRYPT];

#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
#include <TcpIp_MemMap.h>

#endif /* (TCPIP_IKEV2_ENCRYPT_ENABLED == STD_ON) && (TCPIP_IKEV2_AEAD_ENABLED == STD_ON) */

/*==================[external data]=========================================*/
#define TCPIP_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <TcpIp_MemMap.h>

/** \brief Runtime data related to IKE Security associations. */
extern VAR(TcpIp_IkeV2_SaRuntimeDataType, TCPIP_VAR_NOINIT)
  TcpIp_IkeV2_SaRuntimeData[TCPIP_IPSEC_NUM_IKE_SECURITY_ASSOCIATIONS];

/** \brief Runtime data related to IKE connections. */
extern VAR(TcpIp_IkeV2_ConnectionRuntimeDataType, TCPIP_VAR_NOINIT)
  TcpIp_IkeV2_ConnectionRuntimeData[TCPIP_IKEV2_NUM_CONNECTIONS];

/** \brief List of indices to the first free (i.e. unused) IKE SA element inside TcpIp_IkeV2_SaRuntimeData for a
    specific IKE configuration. */
extern VAR(uint8, TCPIP_VAR_NOINIT) TcpIp_IkeV2_firstFreeIkeSa[TCPIP_IKEV2_NUM_CONFIGS];

#define TCPIP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <TcpIp_MemMap.h>

/*==================[internal function declarations]========================*/

#endif /* (TCPIP_SECURITY_MODE == TCPIP_IKEV2) */

#endif /* if !defined( TCPIP_IPSECIKEV2_PRIV_H ) */
/*==================[end of file]===========================================*/
