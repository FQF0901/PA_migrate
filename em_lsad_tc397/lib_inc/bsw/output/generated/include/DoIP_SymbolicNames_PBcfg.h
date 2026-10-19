/**
 * \file
 *
 * \brief AUTOSAR DoIP
 *
 * This file contains the implementation of the AUTOSAR
 * module DoIP.
 *
 * \version 1.1.24
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef DOIP_SYMBOLICNAMES_PBCFG_H
#define DOIP_SYMBOLICNAMES_PBCFG_H

/*==================[includes]==============================================*/

/*==================[macros]================================================*/




/** \brief Symbolic name value for UDP connections */

/* === UDP Rx ID === */
#if (defined DoIPConf_DoIPUdpConnection_0_DoIPSoAdRxPdu)
#error DoIPConf_DoIPUdpConnection_0_DoIPSoAdRxPdu is already defined
#endif
#define DoIPConf_DoIPUdpConnection_0_DoIPSoAdRxPdu 0U

#if(defined DOIP_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined DoIP_DoIPUdpConnection_0_DoIPSoAdRxPdu)
#error DoIP_DoIPUdpConnection_0_DoIPSoAdRxPdu is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define DoIP_DoIPUdpConnection_0_DoIPSoAdRxPdu 0U
#endif /* DOIP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


/* === UDP Tx ID === */
#if (defined DoIPConf_DoIPUdpConnection_0_DoIPSoAdTxPdu)
#error DoIPConf_DoIPUdpConnection_0_DoIPSoAdTxPdu is already defined
#endif
#define DoIPConf_DoIPUdpConnection_0_DoIPSoAdTxPdu 0U

#if(defined DOIP_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined DoIP_DoIPUdpConnection_0_DoIPSoAdTxPdu)
#error DoIP_DoIPUdpConnection_0_DoIPSoAdTxPdu is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define DoIP_DoIPUdpConnection_0_DoIPSoAdTxPdu 0U
#endif /* DOIP_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/** \brief Symbolic name value for UDP vehicle announcement connections */

/* === UDP Tx ID === */
#if (defined DoIPConf_DoIPUdpVehicleAnnouncement_0_DoIPSoAdTxPdu)
#error DoIPConf_DoIPUdpVehicleAnnouncement_0_DoIPSoAdTxPdu is already defined
#endif
#define DoIPConf_DoIPUdpVehicleAnnouncement_0_DoIPSoAdTxPdu 1U

#if(defined DOIP_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined DoIP_DoIPUdpVehicleAnnouncement_0_DoIPSoAdTxPdu)
#error DoIP_DoIPUdpVehicleAnnouncement_0_DoIPSoAdTxPdu is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define DoIP_DoIPUdpVehicleAnnouncement_0_DoIPSoAdTxPdu 1U
#endif /* DOIP_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* ============================================================================================== */

/** \brief Symbolic name value for TCP connections */

/* === TCP Rx ID === */
#if (defined DoIPConf_DoIPTcpConnection_0_DoIPSoAdRxPdu)
#error DoIPConf_DoIPTcpConnection_0_DoIPSoAdRxPdu is already defined
#endif
#define DoIPConf_DoIPTcpConnection_0_DoIPSoAdRxPdu 0U

#if(defined DOIP_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined DoIP_DoIPTcpConnection_0_DoIPSoAdRxPdu)
#error DoIP_DoIPTcpConnection_0_DoIPSoAdRxPdu is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define DoIP_DoIPTcpConnection_0_DoIPSoAdRxPdu 0U
#endif /* DOIP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


/* === TCP Tx ID === */
#if (defined DoIPConf_DoIPTcpConnection_0_DoIPSoAdTxPdu)
#error DoIPConf_DoIPTcpConnection_0_DoIPSoAdTxPdu is already defined
#endif
#define DoIPConf_DoIPTcpConnection_0_DoIPSoAdTxPdu 0U

#if(defined DOIP_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined DoIP_DoIPTcpConnection_0_DoIPSoAdTxPdu)
#error DoIP_DoIPTcpConnection_0_DoIPSoAdTxPdu is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define DoIP_DoIPTcpConnection_0_DoIPSoAdTxPdu 0U
#endif /* DOIP_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* === TCP Rx ID === */
#if (defined DoIPConf_DoIPTcpConnection_1_DoIPSoAdRxPdu)
#error DoIPConf_DoIPTcpConnection_1_DoIPSoAdRxPdu is already defined
#endif
#define DoIPConf_DoIPTcpConnection_1_DoIPSoAdRxPdu 1U

#if(defined DOIP_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined DoIP_DoIPTcpConnection_1_DoIPSoAdRxPdu)
#error DoIP_DoIPTcpConnection_1_DoIPSoAdRxPdu is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define DoIP_DoIPTcpConnection_1_DoIPSoAdRxPdu 1U
#endif /* DOIP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


/* === TCP Tx ID === */
#if (defined DoIPConf_DoIPTcpConnection_1_DoIPSoAdTxPdu)
#error DoIPConf_DoIPTcpConnection_1_DoIPSoAdTxPdu is already defined
#endif
#define DoIPConf_DoIPTcpConnection_1_DoIPSoAdTxPdu 1U

#if(defined DOIP_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined DoIP_DoIPTcpConnection_1_DoIPSoAdTxPdu)
#error DoIP_DoIPTcpConnection_1_DoIPSoAdTxPdu is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define DoIP_DoIPTcpConnection_1_DoIPSoAdTxPdu 1U
#endif /* DOIP_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* ============================================================================================== */

/** \brief Symbolic name value for channel handle ID for PduR */

/* === Rx ID for PduR === */
#if (defined DoIPConf_DoIPChannel_0_DoIPPduRRxPdu)
#error DoIPConf_DoIPChannel_0_DoIPPduRRxPdu is already defined
#endif
#define DoIPConf_DoIPChannel_0_DoIPPduRRxPdu 0U

#if(defined DOIP_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined DoIP_DoIPChannel_0_DoIPPduRRxPdu)
#error DoIP_DoIPChannel_0_DoIPPduRRxPdu is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define DoIP_DoIPChannel_0_DoIPPduRRxPdu 0U
#endif /* DOIP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


/* === Tx ID for PduR === */
#if (defined DoIPConf_DoIPChannel_0_DoIPPduRTxPdu)
#error DoIPConf_DoIPChannel_0_DoIPPduRTxPdu is already defined
#endif
#define DoIPConf_DoIPChannel_0_DoIPPduRTxPdu 0U

#if(defined DOIP_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined DoIP_DoIPChannel_0_DoIPPduRTxPdu)
#error DoIP_DoIPChannel_0_DoIPPduRTxPdu is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define DoIP_DoIPChannel_0_DoIPPduRTxPdu 0U
#endif /* DOIP_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef DOIP_SYMBOLICNAMES_PBCFG_H */

/*==================[end of file]===========================================*/
