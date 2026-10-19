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
#ifndef TCPIP_IPSECDB_INT_H
#define TCPIP_IPSECDB_INT_H

/*==================[inclusions]=============================================*/

#include <TcpIp_guards.h>         /* after foreign/API/Cfg; before internal/private */

#include <TcpIp_Int.h>            /* module internal headerfile */
#include <TcpIp_IpSec_Int.h>      /* module internal headerfile */
#include <TcpIp_Crypto.h>         /* used SW-unit interface file */

/*==================[macros]=================================================*/

/* Internal values of IpSec mechanism */
/** \brief Internal IpSec mechanism discarded */
#define TCPIP_IPSECDB_MECHANISM_DISCARDED                                   1U
/** \brief Internal IpSec mechanism bypassed */
#define TCPIP_IPSECDB_MECHANISM_BYPASSED                                    2U
/** \brief Internal IpSec mechanism secured */
#define TCPIP_IPSECDB_MECHANISM_SECURED                                     3U

/** \brief Invalid SA index */
#define TCPIP_IPSECDB_INVALID_SA_INDEX                                    255U
/** \brief Invalid ipSec connection index */
#define TCPIP_IPSECDB_INVALID_CONNECTION_INDEX                            255U
/** \brief Invalid data index */
#define TCPIP_IPSECDB_INVALID_DATAIDX                                     255U

/** \brief Inbound SA */
#define TCPIP_IPSECDB_DIRECTION_INBOUND                                     0U
/** \brief Outbound SA */
#define TCPIP_IPSECDB_DIRECTION_OUTBOUND                                    1U

#if (TCPIP_SECURITY_MODE >= TCPIP_STATIC_IPSEC)
/** \brief Number of configured IpSec Connections */
#define TCPIP_IPSEC_NUM_CONNECTIONS              TcpIp_PBcfgPtr->numOfIpSecCon
#endif /* (TCPIP_SECURITY_MODE >= TCPIP_STATIC_IPSEC) */

/*==================[type definitions]======================================*/

/** \brief Structure containing the data describing IKE traffic selector. */
typedef struct
{
  /** \brief Pointer to the configured traffic selector. */
  P2CONST(TcpIp_IpSecRuleConfigType, AUTOMATIC, TCPIP_APPL_DATA) traffSelPtr;
  /** \brief Pointer to the configured traffic selector address. */
  P2CONST(uint32, AUTOMATIC, TCPIP_APPL_DATA) addrPtr;
  /** \brief Number of selectors. */
  uint8 numOfSelectors;
  /** \brief Type of selector. */
  uint8 ipType;
} TcpIp_IpSec_TrafficSelType;

/** \brief The data pointer used for all const 32 bit TcpIp data items */
typedef P2CONST(TcpIp_IpSec_KeyGenerationConfigType, AUTOMATIC, TCPIP_APPL_DATA)
  TcpIp_IpSec_ConstKeyGenerationConfigPtrType;

/*==================[internal function declarations]========================*/

#if (TCPIP_SECURITY_MODE >= TCPIP_FIREWALL)

#define TCPIP_START_SEC_CODE
#include <TcpIp_MemMap.h>


#if (TCPIP_SECURITY_MODE >= TCPIP_STATIC_IPSEC)
/** \brief Initialize the IpSecDb unit
 *
 * This service initialize the IpSecDb relevant runtime data.
 *
 * \Reentrancy{Non-Reentrant}
 * \Synchronicity{Synchronous}
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IpSecDb_init
(
  void
);

#endif /* (TCPIP_SECURITY_MODE >= TCPIP_STATIC_IPSEC) */
/** \brief Check the presence of a security policy for inbound packets
  *
  * This service checks if there is an IpSec security policy of an incoming packet based on the
  * local and remote IP address pair.
  *
  * \param[in] localAddr       Identifier of the local IP address
  * \param[in] remoteAddrPtr   Reference to the remote address
 * \param[in] physAddrPtr      Points to MAC address of remote host (source MAC)
  *
  * \return Result of operation
  * \retval E_OK remote   Address match
  * \retval E_NOT_OK      No address match
  *
  * \Reentrancy{Non-Reentrant}
  * \Synchronicity{Synchronous}
  */
TS_MOD_PRIV_DECL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_IpSecDb_checkSecurityPolicyAddr
(
  TcpIp_LocalAddrIdType localAddr,
  P2CONST(uint32, AUTOMATIC, TCPIP_APPL_DATA) remoteAddrPtr,
  P2CONST(uint8, AUTOMATIC, TCPIP_APPL_DATA) physAddrPtr
);

#if (TCPIP_SECURITY_MODE >= TCPIP_STATIC_IPSEC)

/** \brief Get the security association for an incoming packet
  *
  * This service checks if an incoming packet matches a SA in the database, and if so, returns it.
  *
  * \param[in] spi              SPI to identify the SA on the receiver side
  * \param[in] localAddr        Identifier of the local (i.e. receiver's) IP address
  * \param[in] remoteAddrPtr    Reference to the remote (i.e. the transmitter's) IP address
  * \param[out] ipSecSaIdxPtr   Index of the database element describing the SA of the match
  * \param[out] tempIpSecSaDataPtr       Reference to the data where the SA information is written to
  *
  * \return Indicates whether a match was found and whether the sequence number is correct or not
  * \retval E_OK      match found and sequence number has not been received yet
  * \retval E_NOT_OK  either no match found or sequence number has has already been received
  */
TS_MOD_PRIV_DECL FUNC(Std_ReturnType, TCPIP_CODE ) TcpIp_IpSecDb_getSecurityRxAssociation
(
  uint32 spi,
  TcpIp_LocalAddrIdType localAddr,
  P2CONST(uint32, AUTOMATIC, TCPIP_APPL_DATA) remoteAddrPtr,
  P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) ipSecSaIdxPtr,
  P2VAR(TcpIp_IpSec_TempDataType, AUTOMATIC, TCPIP_APPL_DATA) tempIpSecSaDataPtr
);
#endif /* (TCPIP_SECURITY_MODE >= TCPIP_STATIC_IPSEC) */

/** \brief Check if an inbound packet should be processed according to the security polices.
  *
  * This service checks wether an inbound packet should be processed i.e. passed to the upper layer
  * (BYPASSED, SECURED with valid SA and IPsec connection, or IPsec disabled) or not (DISCARDED or
  * invalid SA/connection). This is done by checking the security policies in the database.
  *
  * \param[in] localAddrId    Identifier of the local (i.e. the receiver's) IP address
  * \param[in] remoteAddrPtr  Reference to the remote (i.e. the sender's) IP address
  * \param[in] dataPtr        Reference to the start of TCP/UDP/ICMP payload
  * \param[in] dataLength     Length of the payload
  * \param[in] nextHeader     upper layer protocol
  * \param[in] ipSecSaIdx     Index of the respective SA
  *  \param[in] physAddrPtr    Points to MAC address of remote host (source MAC)
  *
  * \return Result of operation
  * \retval TCPIP_IPSECDB_MECHANISM_DISCARDED   Packet is discarded
  * \retval TCPIP_IPSECDB_MECHANISM_BYPASSED    Packet is bypassed
  * \retval TCPIP_IPSECDB_MECHANISM_SECURED     Packet is secured
  *
  * \Reentrancy{Non-Reentrant}
  * \Synchronicity{Synchronous}
  */
TS_MOD_PRIV_DECL FUNC(uint8, TCPIP_CODE) TcpIp_IpSecDb_checkSecurityRxPolicy
(
  TcpIp_LocalAddrIdType localAddrId,
  P2CONST(uint32, AUTOMATIC, TCPIP_APPL_DATA) remoteAddrPtr,
  P2CONST(uint8, AUTOMATIC, TCPIP_APPL_DATA) dataPtr,
  uint16 dataLength,
  uint8 nextHeader,
  uint8 ipSecSaIdx,
  P2CONST(uint8, AUTOMATIC, TCPIP_APPL_DATA) physAddrPtr
);

#if (TCPIP_SECURITY_MODE >= TCPIP_STATIC_IPSEC)
/** \brief Start an IpSec connection
 *
 * This service sets the state of an IpSec connection to active and initializes its SA database
 * entry in case of manual configuration (i.e. IKE not being used).
 *
 * \param[in] ipSecConnectionIdx   IpSec connection identifier
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IpSecDb_start
(
  uint8 ipSecConnectionIdx
);

/** \brief Stop an IpSec connection
 *
 * This service sets the state of an IpSec connection to inactive and frees the SA database entry
 * in case of manual configuration (i.e. IKE not being used).
 *
 * \param[in] ipSecConnectionIdx   IpSec connection identifier
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IpSecDb_stop
(
  uint8 ipSecConnectionIdx
);

/** \brief Get the security association for an outgoing packet
  *
  * This service checks if an outgoing packet matches a SA in the database, and if so, returns it.
  *
  * \param[in] ipSecConnectionIdx          Index of the connection
  * \param[out] tempIpSecSaDataPtr         Reference to the SA description where the attributes of the
  *                                        matching SA are saved
  * \param[in] getSeqNum                   TRUE: increases the sequence number and returns it
  *                                        FALSE: ignore sequence number
  *
  * \return Result of operation
  * \retval E_OK      Matching SA was found
  * \retval E_NOT_OK  No match was found
  */
TS_MOD_PRIV_DECL FUNC(Std_ReturnType, TCPIP_CODE ) TcpIp_IpSecDb_getSecurityTxAssociation
(
  uint8 ipSecConnectionIdx,
  P2VAR(TcpIp_IpSec_TempDataType, AUTOMATIC, TCPIP_APPL_DATA) tempIpSecSaDataPtr,
  boolean getSeqNum
);

#endif /* (TCPIP_SECURITY_MODE >= TCPIP_STATIC_IPSEC) */

/** \brief Check the security policy of an outbound packet.
  *
  * This service checks the security policy of an SA to determine wether an outbound packet should
  * be secured, not secured, or discarded.
  *
  * \param[in] localAddrId             Identifier of the local (i.e. the sender's) IP address
  * \param[in] remoteAddrPtr           Reference to the remote (i.e. the receiver's) IP address and port
  * \param[in] nextHeader              Number of the protocol following the AH (e.g. UDP, TCP, ICMP)
  * \param[in] localPort               Port from which the packet will be transmitted
  * \param[in] ipSecConnectionIdxPtr   Index of the connection
  *
  * \return Result of operation
  * \retval TCPIP_IPSECDB_MECHANISM_DISCARDED   Packet is discarded
  * \retval TCPIP_IPSECDB_MECHANISM_BYPASSED    Packet is bypassed
  * \retval TCPIP_IPSECDB_MECHANISM_SECURED     Packet is secured
  *
  * \Reentrancy{Non-Reentrant}
  * \Synchronicity{Synchronous}
  */
TS_MOD_PRIV_DECL FUNC(uint8, TCPIP_CODE) TcpIp_IpSecDb_checkSecurityTxPolicy
(
  TcpIp_LocalAddrIdType localAddrId,
  P2CONST(TcpIp_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) remoteAddrPtr,
  uint8 nextHeader,
  uint16 localPort,
  P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) ipSecConnectionIdxPtr
);

#if ((TCPIP_GETANDRESETMEASUREMENTDATA_API == STD_ON))
/** \brief Read and reset dropped/passed datagrams by security policies
 *
 * This function reads and resets dropped/passed datagrams by security policies.
 *
 * \param[in]  MeasurementIdx          Index to select specific measurement data
 * \param[in]  MeasurementResetNeeded  Flag to trigger a reset of the measurement
 * \param[out] MeasurementDataPtr      Reference to data buffer
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IpSecDb_GetAndResetPolicyCount
(
  TcpIp_MeasurementIdxType MeasurementIdx,
  boolean MeasurementResetNeeded,
  P2VAR(uint32, AUTOMATIC, TCPIP_APPL_DATA) MeasurementDataPtr
);
#endif /* TCPIP_GETANDRESETMEASUREMENTDATA_API == STD_ON)*/


#if (TCPIP_IPSECDB_GETANDRESETMEASUREMENTDATA_ENABLE == STD_ON)

/** \brief Log IpSec, IpSecDb and IkeV2 errors
 *
 * This services handles logging of errors originating form IpSec, IpSecDb and IkeV2 using a callout
 * function.
 *
 * \param[in] localAddrId   Identification of the local IP address/Security Association
 * \param[in] remoteIpPtr   Reference to the remote address
 * \param[in] errorType     Error type
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IpSecDb_LogError
(
  uint8 localAddrId,
  P2CONST(uint32, AUTOMATIC, TCPIP_APPL_DATA) remoteIpPtr,
  uint8 errorType
);

#endif /* #if (TCPIP_IPSECDB_GETANDRESETMEASUREMENTDATA_ENABLE == STD_ON) */

#if (TCPIP_SECURITY_MODE == TCPIP_IKEV2)

/** \brief Mainfunction of the IpSecDb Unit
 *
 *  This service maintains the IpSecDb unit and performs periodic tasks.
 *
 * \param[in] timerTick Main MainFunction call counter within the current second.
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IpSecDb_mainFunction
(
  uint16 timerTick
);

/** \brief Get a free security association
 *
 * This service allocates a free run-time data structure for Security Association (SA) management and sets its elements.
 *
 * \param[in] ipSecConnectionIdx    Index of the IpSec connection the SA should be allocated for
 * \param[in] ikeSaIdx              Index of the respective IKE SA
 * \param[in] identifier            Identifier of the SA
 * \param[in] initiator             Boolean flag that indicates wether this SA is an initiator (TRUE) or not (FALSE)
 * \param[in] spi Inbound/Outbound  Security Parameter Index (SPI)
 *
 * \return Index of the SA array element that has been allocated
 * \retval TCPIP_IPSECDB_INVALID_SA_INDEX indicates that no free SA is available.
 *
 */
TS_MOD_PRIV_DECL FUNC(uint8, TCPIP_CODE) TcpIp_IpSecDb_getFreeSecurityAssociation
(
  uint8 ipSecConnectionIdx,
  uint8 ikeSaIdx,
  uint32 identifier,
  boolean initiator,
  uint32 spi
);


/** \brief Check if there is a free security association
 *
 * This service checks if there is a free run-time data structure for Security Association (SA) management.
 *
 * \param[in] ipSecConnectionIdx    Index of the IpSec connection the SA should be allocated for
 *
 * \return TRUE    free SA found
 * \return FALSE   no free SA is available.
 *
 */
TS_MOD_PRIV_DECL FUNC(boolean, TCPIP_CODE) TcpIp_IpSecDb_findFreeSecurityAssociation
(
  uint8 ipSecConnectionIdx
);

/** \brief Get an SA from the database by the identifier
 *
 * This service retrieves the SA with a specific identifier from the database.
 *
 * \param[in] ipSecConnectionIdx  Index of the IpSec connection the SA belongs to
 * \param[in] identifier          Identifier of the SA that is being searched
 * \param[in] ikeSaIdx              Index of the respective IKE SA
 * \param[in] initiator           Boolean flag that indicates wether this SA is an initiator (TRUE) or not (FALSE)
 *
 * \return The index of the match within the database
 * \retval TCPIP_IPSECDB_INVALID_SA_INDEX indicates that no match has been found.
 *
 */
TS_MOD_PRIV_DECL FUNC(uint8, TCPIP_CODE) TcpIp_IpSecDb_getSecurityAssociation_byIdentifier
(
  uint8 ipSecConnectionIdx,
  uint32 identifier,
  uint8 ikeSaIdx,
  boolean initiator
);

/** \brief Get security security information from the configuration
 *
 * This service retrieves common SA configuration and local/remote security policy configuration from the post-build configuration for a specific IpSec connection.
 *
 * \param[in] ipSecConnectionIdx      Index of the IpSec connection the information should be retrieved for
 * \param[in] direction               Direction of the security policies the information should be retrieved for
 * \param[out] proposalsConfigPtr     Reference to the configured proposals
 * \param[out] remotePolicyConfigPtr  Reference to the configuration of remote traffic selectors
 * \param[out] localPolicyConfigPtr   Reference to the configuration of local traffic selectors
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IpSecDb_getSecurityInformation
(
  uint8 ipSecConnectionIdx,
  uint8 direction,
  P2VAR(TcpIp_IpSec_ProposalsConfigType, AUTOMATIC, TCPIP_APPL_DATA) proposalsConfigPtr,
  P2VAR(TcpIp_IpSec_TrafficSelType, AUTOMATIC, TCPIP_APPL_DATA) remotePolicyConfigPtr,
  P2VAR(TcpIp_IpSec_TrafficSelType, AUTOMATIC, TCPIP_APPL_DATA) localPolicyConfigPtr
);

/** \brief Set an SA to active
 *
 * This service sets an SA to the active state and sets related attributes.
 *
 * \param[in] ipSecSaIdx  The index of the SA that should be set to the active state
 * \param[in] spi         SPI of the SA
 * \param[in] direction   Direction of the SA
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IpSecDb_setSecurityAssociationActive
(
  uint8 ipSecSaIdx,
  uint32 spi,
  uint8 direction
);

/** \brief Set the proposal index of a security association
 *
 * This service sets the SA proposal index of a SA database entry
 *
 * \param[in] ipSecSaIdx    Index of the runtime element represting the SA in the database
 * \param[in] proposalIdx   Index of the SA proposal that should be set
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IpSecDb_setSecurityAssociationProposal
(
  uint8 ipSecSaIdx,
  uint8 proposalIdx
);

/** \brief Get the key configuration of a security association
 *
 * This service retrieves the key generation configuration of a specific SA from the post-build configuration.
 *
 * \param[in]  ipSecSaIdx         Index of the runtime element represting the SA in the database
 * \param[out] keyConfigPtr       Reference to the key generation configuration
 * \param[out] keyOrderConfigPtr  Reference to the order of the keys
 * \param[out] numOfKeysPtr       Reference to the number of keys
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IpSecDb_getSecurityAssociationKeyConfig
(
  uint8 ipSecSaIdx,
  P2VAR(TcpIp_IpSec_ConstKeyGenerationConfigPtrType, AUTOMATIC, TCPIP_APPL_DATA) keyConfigPtr,
  P2VAR(TcpIp_ConstUint8PtrType, AUTOMATIC, TCPIP_APPL_DATA) keyOrderConfigPtr,
  P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) numOfKeysPtr
);

/** \brief Get the security association
 *
 * This service retrieves the inbound and outbound SPI, as well as the protocol identifier for a specific SA from the post-build configuration.
 *
 * \param[in]  ipSecSaIdx     Index of the runtime element represting the SA in the database
 * \param[out] inboundSpi     Reference to where the inbound SPI is saved
 * \param[out] outboundSpi    Reference to where the outbound SPI is saved
 * \param[out] protocol       Reference to where the protocol identifier is saved
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IpSecDb_getSecurityAssociationSpi
(
  uint8 ipSecSaIdx,
  P2VAR(uint32, AUTOMATIC, TCPIP_APPL_DATA) inboundSpi,
  P2VAR(uint32, AUTOMATIC, TCPIP_APPL_DATA) outboundSpi,
  P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) protocol
);

/** \brief Stops a security association
 *
 * This service stops all IpSec SAs allocated for the specific IKE SA belonging to an IpSec connection.
 *
 * \param[in] ipSecConnectionIdx  Index of the IpSec connection
 * \param[in] ikeSaIdx            Index of the IKE SA
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IpSecDb_stopSecurityAssociation
(
  uint8 ipSecConnectionIdx,
  uint8 ikeSaIdx
);

/** \brief Searches if there is an invalid IpSec SA associated with an IpSec connection
 *
 * This service deletes all IpSec SAs that are invalid. It is triggered from the TcpIp_SecurityMainFunction.
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IpSecDb_deleteInvalidIpSecSa(void);

/** \brief Get an outbound security association by its SPI
 *
 * This service retrieves the index of an SPI specified by its SPI from the database.
 *
 * \param[in] ipSecConnectionIdx  Index of the IpSec connection
 * \param[in] protocolId          Protocol identifier of SA
 * \param[in] spiSize             Size of the SPI in bytes
 * \param[in] spi                 SPI of the SA
 *
 * \return Index of the SA index
 * \retval TCPIP_IPSECDB_INVALID_SA_INDEX is returned if no match was found
 *
 */
TS_MOD_PRIV_DECL FUNC(uint8, TCPIP_CODE) TcpIp_IpSecDb_getOutSecurityAssociation_bySpi
(
  uint8 ipSecConnectionIdx,
  uint8 protocolId,
  uint16 spiSize,
  uint32 spi
);

/** \brief Update the received message counter
 *
 * This service is called to indicate that an incoming message was successfully validated.
 * The function will reset the "last received message" counter for the specified SA
 * and increment the number of received packets counter.
 *
 * \param[in] ipSecSaIdx  Index of the security association
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE ) TcpIp_IpSecDb_updateReceivedCounter
(
  uint8 ipSecSaIdx
);

#if (TCPIP_IKEV2_DPD_ENABLED == STD_ON )

/** \brief Get "last received message" counter
 *
 * This service loops over all established SAs for the specified connection and returns
 * the smallest "last received message" counter.
 *
 * \return passed time when the last message has been received on the specified connection
 *
 */
TS_MOD_PRIV_DECL FUNC(uint16, TCPIP_CODE) TcpIp_IpSecDb_getRecentConnActivity
(
  uint8 ipSecConnectionIdx
);

#endif /* (TCPIP_IKEV2_DPD_ENABLED == STD_ON ) */

#if (TCPIP_IPSECANTIREPLAY_ENABLED == STD_ON)

/** \brief Update sequence number
 *
 * This service updates the sequence number of an IpSec SA.
 *
 * \param[in] ipSecSaIdx    Index of the SA
 * \param[in] tempIpSecSaDataPtr     Reference to the data where the SA information is written to
 *
  * \retval E_OK          Sequence number updated
  * \retval E_NOT_OK      Connection closed
 */
TS_MOD_PRIV_DECL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_IpSecDb_updateSeqNum
(
  uint8 ipSecSaIdx,
  P2VAR(TcpIp_IpSec_TempDataType, AUTOMATIC, TCPIP_APPL_DATA) tempIpSecSaDataPtr
);

#endif /* (TCPIP_IPSECANTIREPLAY_ENABLED == STD_ON) */
#endif /* (TCPIP_SECURITY_MODE == TCPIP_IKEV2) */

#if (TCPIP_IPSEC_GET_STATUS_API_ENABLED == STD_ON)

/** \brief Get the status for all child SAs
 *
 * This service returns the statuses for all child SAs for a given IKE SA.
 * If numberOfChildSaElements points to zero value, the function returns only the total number of
 * child SAs for the given IKE SA.
 *
 * \param[in] ipSecConIdx                   Relevant IpSec connection index
 * \param[in] ikeSaIndex                    Relevant IKE SA index
 * \param[out] saStsPtr                     Reference to the status cache to fill
 * \param[in,out] numberOfChildSaElements   Input: Reference to the number of child SA entries that can be saved in the cache
 *                                          Output: Reference to the number of child SA entries that have been saved in the cache
 *
 */
TS_MOD_PRIV_DECL FUNC(void, TCPIP_CODE) TcpIp_IpSecDb_getChildSas
(
  uint8 ipSecConIdx,
  uint8 ikeSaIndex,
  P2VAR(TcpIp_IpSecChildSaStatusType, AUTOMATIC, TCPIP_APPL_DATA) saStsPtr,
  P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) numberOfChildSaElements
);

#endif /* (TCPIP_IPSEC_GET_STATUS_API_ENABLED == STD_ON) */

#define TCPIP_STOP_SEC_CODE
#include <TcpIp_MemMap.h>


/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

#endif /* (TCPIP_SECURITY_MODE >= TCPIP_FIREWALL) */

#endif /* ifndef TCPIP_IPSECDB_INT_H */
/*==================[end of file]===========================================*/
