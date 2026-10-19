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
#ifndef TCPIP_IPSEC_API_H
#define TCPIP_IPSEC_API_H

/*==================[inclusions]============================================*/

#include <ComStack_Types.h>       /* AUTOSAR comstack types */
#include <TcpIp_Api.h>            /* general TcpIp type definitions */


#include <TcpIp_IpSec_Api.guards>
/*==================[macros]================================================*/

/** \brief IPsec is activated for this connection */
#define TCPIP_IPSEC_ACTIVE                                             0U
/** \brief IPsec is deactivated for this connection */
#define TCPIP_IPSEC_INACTIVE                                           1U
/** \brief IPsec is activated, IKE remains inactive for this connection */
#define TCPIP_IPSEC_SECURE                                             2U

#define TCPIP_IPSEC_INVALID_ICV                                        2U
/*==================[type definitions]======================================*/
/** \brief Specifies the IPsec state for a specific IPsec connection. */
typedef uint8 TcpIp_IPsecStateType;


typedef struct
{
  /** \brief Packets in - last 32 bits of the incoming packet counter. */
  uint32 numOfPacketsReceived;
  /** \brief Packets out - last 32 bits of the incoming packet counter. */
  uint32 numOfPacketsTransmitted;
  /** \brief Last packet in (s) - seconds since last packet received on SA. If value > 0xffff, set to 0xffff.*/
  uint16 lastPacketReceivedTime;
  /** \brief Last packet out (s) - seconds since last packet sent on SA. If value > 0xffff, set to 0xffff. */
  uint16 lastPacketTransmittedTime;
  /** \brief Child SA Inbound SPI last two bytes */
  uint8 inboundSpi[2U];
  /** \brief Child SA Outbound SPI last two bytes */
  uint8 outboundSpi[2U];
  /** \brief Protocol of encryption (2: AH, 3: ESP) */ /* get from the config */
  uint8 protocol;
}TcpIp_IpSecChildSaStatusType;

typedef struct
{
  /** \brief Pointer to memory where the list of Child SAs shall be stored. Memory should be at least of size
   *    numberOfChildSaElements. */
  P2VAR(TcpIp_IpSecChildSaStatusType, AUTOMATIC, TCPIP_APPL_DATA) childSaStatusPtr;
  /** \brief In: Maximum number of entries that can be stored in output childSaStatusPtr.
   *    Out: Number of entries written to output childSaStatusPtr (Number of all entries in the cache if input value is 0). */
  P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) numberOfChildSaElements; /* similar to ARP entries API */
  /** \brief IKEv2 Initiator SPI last two bytes */
  uint8 initiatorSpi[2U];
  /** \brief IKEv2 Responder SPI last two bytes */
  uint8 responderSpi[2U];
  /** \brief status of the ike security association */
  uint8 ikeState; /* get from the cache */
  /** \brief Flag determining if the local peer is the IKE initiator (TRUE) or the responder (FALSE) of the IKE SA*/
  boolean isIkeInitiator;
}TcpIp_IpSecIkeSaStatusType;


/*==================[external data]=========================================*/

/*==================[external function declarations]========================*/

#define TCPIP_START_SEC_CODE
#include <TcpIp_MemMap.h>

/** \brief Request to change state of communication security
 *
 * By this API service the TCP/IP stack is requested to change the IpSec state of
 * the communication network identified by IpSec connection index.
 *
 * \param[in] conId     IpSec connection index to identify the communication where the TcpIp state
 *                      is requested.
 * \param[in] reqState  Requested TcpIp state.
 *
 * \return Result of operation
 * \retval E_OK      Service accepted
 * \retval E_NOT_OK  Service denied
 *
 * \ServiceID{0xF2}
 * \Reentrancy{Non-Reentrant}
 * \Synchronicity{Asynchronous}
 */
extern FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_RequestIpSecMode
(
  uint8 conId,
  TcpIp_IPsecStateType reqState
);

/** \brief Retrieve current IPsec status
 *
 * This service returns the currently installed IKE SAs and Child SAs. If numberOfIkeSaElementsPtr
 * points to zero value on entry, the function returns only the total number of IKE SAs for
 * the given controller in *numberOfIkeSaElementsPtr on exit.
 * If on exit ikeSaStatusPtr->ikeState == TCPIP_IKEV2_SA_INIT_STATE the value of
 * ikeSaStatusPtr->responderSpi is not yet available and should not be used. If on exit
 * ikeSaStatusPtr->ikeState == TCPIP_IKEV2_AUTH_STATE the value of
 * ikeSaStatusPtr->childSaStatusPtr and ikeSaStatusPtr->numberOfChildSaElements
 * is not yet available and should not be used.
 *
 * \param[in]      ctrlIdx                   EthIf controller index to identify the related SAs.
 * \param[out]     sockAddPtr                Pointer to memory where the remote IP addresses shall be
 *                                           stored, can be either a ist of IPv4 or IPv6 addresses.
 *                                           Memory should be at least of size *numberOfIkeSaElementsPtr.
 * \param[out]     ikeSaStatusPtr            Pointer to memory where the list of IKE SAs and Child SAs
 *                                           shall be stored. Memory should be at least of size
 *                                           *numberOfIkeSaElementsPtr.
 * \param[in,out]  numberOfIkeSaElementsPtr  Entry: Maximum number of SA statuses and IP addresses that
 *                                           can be stored in the output.
 *                                           Exit: Number of SA statuses and IP addresses that were
 *                                           stored.
 *                                           Special Case: If *numberOfIkeSaElementsPtr is zero on
 *                                           input the total number of installed IKE SAs is returned
 *                                           as output in *numberOfIkeSaElementsPtr
 *
 * \return Result of operation
 * \retval E_OK      IPsec status could be read.
 * \retval E_NOT_OK  IPsec status could not be read (e.g. invalid controller, controller is offline)
 */
extern FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_IpSecGetStatus
(
  uint8 ctrlIdx,
  P2VAR(TcpIp_SockAddrPtrType, AUTOMATIC, TCPIP_APPL_DATA) sockAddPtr,
  P2VAR(TcpIp_IpSecIkeSaStatusType, AUTOMATIC, TCPIP_APPL_DATA) ikeSaStatusPtr,
  P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) numberOfIkeSaElementsPtr
);

#define TCPIP_STOP_SEC_CODE
#include <TcpIp_MemMap.h>

#endif /* ifndef TCPIP_IPSEC_API_H */
/*==================[end of file]===========================================*/
