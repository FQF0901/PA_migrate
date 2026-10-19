/**
 * \file
 *
 * \brief AUTOSAR PduR
 *
 * This file contains the implementation of the AUTOSAR
 * module PduR.
 *
 * \version 5.3.48
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef PDUR_SYMBOLIC_NAMES_PBCFG_H
#define PDUR_SYMBOLIC_NAMES_PBCFG_H

/*==================[includes]==============================================*/

/*==================[macros]================================================*/
/* -------------------- Routing path: 0 Pdu_CounterOut_T */
#if (defined PduRConf_PduRSrcPdu_Pdu_CounterOut_T_S)
#error PduRConf_PduRSrcPdu_Pdu_CounterOut_T_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Pdu_CounterOut_T_S 0U /* SRC Com-UP-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Pdu_CounterOut_T_S)
#error PduR_Pdu_CounterOut_T_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Pdu_CounterOut_T_S 0U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_Pdu_CounterOut_T_D)
#error PduRConf_PduRDestPdu_Pdu_CounterOut_T_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Pdu_CounterOut_T_D 0U /* DEST SoAd-LO-IF */


/* -------------------- Routing path: 1 Pdu_DummyOut_R */
#if (defined PduRConf_PduRSrcPdu_Pdu_DummyOut_R_S)
#error PduRConf_PduRSrcPdu_Pdu_DummyOut_R_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Pdu_DummyOut_R_S 0U /* SRC SoAd-LO-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Pdu_DummyOut_R_S)
#error PduR_Pdu_DummyOut_R_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Pdu_DummyOut_R_S 0U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* PduRConf_PduRDestPdu_Pdu_DummyOut_R_D not defined since it is not enabled.*/


/* -------------------- Routing path: 2 Pdu_CounterIn_R */
#if (defined PduRConf_PduRSrcPdu_Pdu_CounterIn_R_S)
#error PduRConf_PduRSrcPdu_Pdu_CounterIn_R_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Pdu_CounterIn_R_S 1U /* SRC SoAd-LO-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Pdu_CounterIn_R_S)
#error PduR_Pdu_CounterIn_R_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Pdu_CounterIn_R_S 1U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* PduRConf_PduRDestPdu_Pdu_CounterIn_R_D not defined since it is not enabled.*/


/* -------------------- Routing path: 3 Pdu_DummyIn_T */
#if (defined PduRConf_PduRSrcPdu_Pdu_DummyIn_T_S)
#error PduRConf_PduRSrcPdu_Pdu_DummyIn_T_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Pdu_DummyIn_T_S 1U /* SRC Com-UP-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Pdu_DummyIn_T_S)
#error PduR_Pdu_DummyIn_T_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Pdu_DummyIn_T_S 1U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_Pdu_DummyIn_T_D)
#error PduRConf_PduRDestPdu_Pdu_DummyIn_T_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Pdu_DummyIn_T_D 1U /* DEST SoAd-LO-IF */


/* -------------------- Routing path: 4 Pdu_UssToolIn_R */
#if (defined PduRConf_PduRSrcPdu_Pdu_UssTool_R_S)
#error PduRConf_PduRSrcPdu_Pdu_UssTool_R_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Pdu_UssTool_R_S 2U /* SRC SoAd-LO-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Pdu_UssTool_R_S)
#error PduR_Pdu_UssTool_R_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Pdu_UssTool_R_S 2U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* PduRConf_PduRDestPdu_Pdu_UssTool_R_D not defined since it is not enabled.*/


/* -------------------- Routing path: 5 Pdu_UssToolOut_T */
#if (defined PduRConf_PduRSrcPdu_Pdu_UssTool_T_S)
#error PduRConf_PduRSrcPdu_Pdu_UssTool_T_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Pdu_UssTool_T_S 2U /* SRC Com-UP-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Pdu_UssTool_T_S)
#error PduR_Pdu_UssTool_T_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Pdu_UssTool_T_S 2U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_Pdu_UssTool_T_D)
#error PduRConf_PduRDestPdu_Pdu_UssTool_T_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Pdu_UssTool_T_D 2U /* DEST SoAd-LO-IF */


/* -------------------- Routing path: 6 Pdu_CfmIn_R */
#if (defined PduRConf_PduRSrcPdu_Pdu_Cfm_R_S)
#error PduRConf_PduRSrcPdu_Pdu_Cfm_R_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Pdu_Cfm_R_S 3U /* SRC SoAd-LO-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Pdu_Cfm_R_S)
#error PduR_Pdu_Cfm_R_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Pdu_Cfm_R_S 3U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* PduRConf_PduRDestPdu_Pdu_Cfm_R_D not defined since it is not enabled.*/


/* -------------------- Routing path: 7 Pdu_CfmOut_T */
#if (defined PduRConf_PduRSrcPdu_Pdu_Cfm_T_S)
#error PduRConf_PduRSrcPdu_Pdu_Cfm_T_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Pdu_Cfm_T_S 3U /* SRC Com-UP-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Pdu_Cfm_T_S)
#error PduR_Pdu_Cfm_T_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Pdu_Cfm_T_S 3U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_Pdu_Cfm_T_D)
#error PduRConf_PduRDestPdu_Pdu_Cfm_T_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Pdu_Cfm_T_D 3U /* DEST SoAd-LO-IF */


/* -------------------- Routing path: 8 GW_HSC2_SCU_FrP00_157R */
#if (defined PduRConf_PduRSrcPdu_GW_HSC2_SCU_FrP00_157R_S)
#error PduRConf_PduRSrcPdu_GW_HSC2_SCU_FrP00_157R_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_GW_HSC2_SCU_FrP00_157R_S 0U /* SRC CanIf-LO-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_GW_HSC2_SCU_FrP00_157R_S)
#error PduR_GW_HSC2_SCU_FrP00_157R_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_GW_HSC2_SCU_FrP00_157R_S 0U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* PduRConf_PduRDestPdu_GW_HSC2_SCU_FrP00_157R_D not defined since it is not enabled.*/


/* -------------------- Routing path: 9 SCS_HSC2_FrP00_193R */
#if (defined PduRConf_PduRSrcPdu_SCS_HSC2_FrP00_193R_S)
#error PduRConf_PduRSrcPdu_SCS_HSC2_FrP00_193R_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_SCS_HSC2_FrP00_193R_S 1U /* SRC CanIf-LO-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_SCS_HSC2_FrP00_193R_S)
#error PduR_SCS_HSC2_FrP00_193R_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_SCS_HSC2_FrP00_193R_S 1U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* PduRConf_PduRDestPdu_SCS_HSC2_FrP00_193R_D not defined since it is not enabled.*/


/* -------------------- Routing path: 10 SCS_HSC2_FrP01_197R */
#if (defined PduRConf_PduRSrcPdu_SCS_HSC2_FrP01_197R_S)
#error PduRConf_PduRSrcPdu_SCS_HSC2_FrP01_197R_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_SCS_HSC2_FrP01_197R_S 2U /* SRC CanIf-LO-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_SCS_HSC2_FrP01_197R_S)
#error PduR_SCS_HSC2_FrP01_197R_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_SCS_HSC2_FrP01_197R_S 2U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* PduRConf_PduRDestPdu_SCS_HSC2_FrP01_197R_D not defined since it is not enabled.*/


/* -------------------- Routing path: 11 SCS_HSC2_FrP02_389R */
#if (defined PduRConf_PduRSrcPdu_SCS_HSC2_FrP02_389R_S)
#error PduRConf_PduRSrcPdu_SCS_HSC2_FrP02_389R_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_SCS_HSC2_FrP02_389R_S 3U /* SRC CanIf-LO-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_SCS_HSC2_FrP02_389R_S)
#error PduR_SCS_HSC2_FrP02_389R_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_SCS_HSC2_FrP02_389R_S 3U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* PduRConf_PduRDestPdu_SCS_HSC2_FrP02_389R_D not defined since it is not enabled.*/


/* -------------------- Routing path: 12 P2P_HSC2_FrP00_424T */
#if (defined PduRConf_PduRSrcPdu_P2P_HSC2_FrP00_424T_S)
#error PduRConf_PduRSrcPdu_P2P_HSC2_FrP00_424T_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_P2P_HSC2_FrP00_424T_S 4U /* SRC Com-UP-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_P2P_HSC2_FrP00_424T_S)
#error PduR_P2P_HSC2_FrP00_424T_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_P2P_HSC2_FrP00_424T_S 4U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_P2P_HSC2_FrP00_424T_D)
#error PduRConf_PduRDestPdu_P2P_HSC2_FrP00_424T_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_P2P_HSC2_FrP00_424T_D 0U /* DEST CanIf-LO-IF */


/* -------------------- Routing path: 13 EPS_HSC2_FrP02_433R */
#if (defined PduRConf_PduRSrcPdu_EPS_HSC2_FrP02_433R_S)
#error PduRConf_PduRSrcPdu_EPS_HSC2_FrP02_433R_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_EPS_HSC2_FrP02_433R_S 4U /* SRC CanIf-LO-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_EPS_HSC2_FrP02_433R_S)
#error PduR_EPS_HSC2_FrP02_433R_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_EPS_HSC2_FrP02_433R_S 4U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* PduRConf_PduRDestPdu_EPS_HSC2_FrP02_433R_D not defined since it is not enabled.*/


/* -------------------- Routing path: 14 P2P_HSC2_FrP01_437T */
#if (defined PduRConf_PduRSrcPdu_P2P_HSC2_FrP01_437T_S)
#error PduRConf_PduRSrcPdu_P2P_HSC2_FrP01_437T_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_P2P_HSC2_FrP01_437T_S 5U /* SRC Com-UP-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_P2P_HSC2_FrP01_437T_S)
#error PduR_P2P_HSC2_FrP01_437T_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_P2P_HSC2_FrP01_437T_S 5U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_P2P_HSC2_FrP01_437T_D)
#error PduRConf_PduRDestPdu_P2P_HSC2_FrP01_437T_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_P2P_HSC2_FrP01_437T_D 1U /* DEST CanIf-LO-IF */


/* -------------------- Routing path: 15 EHBS_HSC2_FrP00_438R */
#if (defined PduRConf_PduRSrcPdu_EHBS_HSC2_FrP00_438R_S)
#error PduRConf_PduRSrcPdu_EHBS_HSC2_FrP00_438R_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_EHBS_HSC2_FrP00_438R_S 5U /* SRC CanIf-LO-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_EHBS_HSC2_FrP00_438R_S)
#error PduR_EHBS_HSC2_FrP00_438R_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_EHBS_HSC2_FrP00_438R_S 5U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* PduRConf_PduRDestPdu_EHBS_HSC2_FrP00_438R_D not defined since it is not enabled.*/


/* -------------------- Routing path: 16 SCS_HSC2_FrP03_455R */
#if (defined PduRConf_PduRSrcPdu_SCS_HSC2_FrP03_455R_S)
#error PduRConf_PduRSrcPdu_SCS_HSC2_FrP03_455R_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_SCS_HSC2_FrP03_455R_S 6U /* SRC CanIf-LO-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_SCS_HSC2_FrP03_455R_S)
#error PduR_SCS_HSC2_FrP03_455R_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_SCS_HSC2_FrP03_455R_S 6U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* PduRConf_PduRDestPdu_SCS_HSC2_FrP03_455R_D not defined since it is not enabled.*/


/* -------------------- Routing path: 17 SAS_HSC2_FrP00_485R */
#if (defined PduRConf_PduRSrcPdu_SAS_HSC2_FrP00_485R_S)
#error PduRConf_PduRSrcPdu_SAS_HSC2_FrP00_485R_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_SAS_HSC2_FrP00_485R_S 7U /* SRC CanIf-LO-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_SAS_HSC2_FrP00_485R_S)
#error PduR_SAS_HSC2_FrP00_485R_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_SAS_HSC2_FrP00_485R_S 7U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* PduRConf_PduRDestPdu_SAS_HSC2_FrP00_485R_D not defined since it is not enabled.*/


/* -------------------- Routing path: 18 SCS_HSC2_FrP05_489R */
#if (defined PduRConf_PduRSrcPdu_SCS_HSC2_FrP05_489R_S)
#error PduRConf_PduRSrcPdu_SCS_HSC2_FrP05_489R_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_SCS_HSC2_FrP05_489R_S 8U /* SRC CanIf-LO-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_SCS_HSC2_FrP05_489R_S)
#error PduR_SCS_HSC2_FrP05_489R_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_SCS_HSC2_FrP05_489R_S 8U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* PduRConf_PduRDestPdu_SCS_HSC2_FrP05_489R_D not defined since it is not enabled.*/


/* -------------------- Routing path: 19 EPB_HSC2_FrP01_554R */
#if (defined PduRConf_PduRSrcPdu_EPB_HSC2_FrP01_554R_S)
#error PduRConf_PduRSrcPdu_EPB_HSC2_FrP01_554R_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_EPB_HSC2_FrP01_554R_S 9U /* SRC CanIf-LO-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_EPB_HSC2_FrP01_554R_S)
#error PduR_EPB_HSC2_FrP01_554R_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_EPB_HSC2_FrP01_554R_S 9U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* PduRConf_PduRDestPdu_EPB_HSC2_FrP01_554R_D not defined since it is not enabled.*/


/* -------------------- Routing path: 20 P2P_HSC2_FrP04_567T */
#if (defined PduRConf_PduRSrcPdu_P2P_HSC2_FrP04_567T_S)
#error PduRConf_PduRSrcPdu_P2P_HSC2_FrP04_567T_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_P2P_HSC2_FrP04_567T_S 6U /* SRC Com-UP-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_P2P_HSC2_FrP04_567T_S)
#error PduR_P2P_HSC2_FrP04_567T_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_P2P_HSC2_FrP04_567T_S 6U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_P2P_HSC2_FrP04_567T_D)
#error PduRConf_PduRDestPdu_P2P_HSC2_FrP04_567T_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_P2P_HSC2_FrP04_567T_D 2U /* DEST CanIf-LO-IF */


/* -------------------- Routing path: 21 P2P_HSC2_FrP03_573T */
#if (defined PduRConf_PduRSrcPdu_P2P_HSC2_FrP03_573T_S)
#error PduRConf_PduRSrcPdu_P2P_HSC2_FrP03_573T_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_P2P_HSC2_FrP03_573T_S 7U /* SRC Com-UP-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_P2P_HSC2_FrP03_573T_S)
#error PduR_P2P_HSC2_FrP03_573T_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_P2P_HSC2_FrP03_573T_S 7U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_P2P_HSC2_FrP03_573T_D)
#error PduRConf_PduRDestPdu_P2P_HSC2_FrP03_573T_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_P2P_HSC2_FrP03_573T_D 3U /* DEST CanIf-LO-IF */


/* -------------------- Routing path: 22 APA_SecCH_FrP03_651T */
#if (defined PduRConf_PduRSrcPdu_APA_SecCH_FrP03_651T_S)
#error PduRConf_PduRSrcPdu_APA_SecCH_FrP03_651T_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_APA_SecCH_FrP03_651T_S 8U /* SRC Com-UP-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_APA_SecCH_FrP03_651T_S)
#error PduR_APA_SecCH_FrP03_651T_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_APA_SecCH_FrP03_651T_S 8U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_APA_SecCH_FrP03_651T_D)
#error PduRConf_PduRDestPdu_APA_SecCH_FrP03_651T_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_APA_SecCH_FrP03_651T_D 4U /* DEST CanIf-LO-IF */


/* -------------------- Routing path: 23 SCS_HSC2_FrP11_840R */
#if (defined PduRConf_PduRSrcPdu_SCS_HSC2_FrP11_840R_S)
#error PduRConf_PduRSrcPdu_SCS_HSC2_FrP11_840R_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_SCS_HSC2_FrP11_840R_S 10U /* SRC CanIf-LO-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_SCS_HSC2_FrP11_840R_S)
#error PduR_SCS_HSC2_FrP11_840R_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_SCS_HSC2_FrP11_840R_S 10U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* PduRConf_PduRDestPdu_SCS_HSC2_FrP11_840R_D not defined since it is not enabled.*/


/* -------------------- Routing path: 24 SCS_HSC2_FrP12_842R */
#if (defined PduRConf_PduRSrcPdu_SCS_HSC2_FrP12_842R_S)
#error PduRConf_PduRSrcPdu_SCS_HSC2_FrP12_842R_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_SCS_HSC2_FrP12_842R_S 11U /* SRC CanIf-LO-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_SCS_HSC2_FrP12_842R_S)
#error PduR_SCS_HSC2_FrP12_842R_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_SCS_HSC2_FrP12_842R_S 11U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* PduRConf_PduRDestPdu_SCS_HSC2_FrP12_842R_D not defined since it is not enabled.*/


/* -------------------- Routing path: 25 SCS_HSC2_FrP15_851R */
#if (defined PduRConf_PduRSrcPdu_SCS_HSC2_FrP15_851R_S)
#error PduRConf_PduRSrcPdu_SCS_HSC2_FrP15_851R_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_SCS_HSC2_FrP15_851R_S 12U /* SRC CanIf-LO-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_SCS_HSC2_FrP15_851R_S)
#error PduR_SCS_HSC2_FrP15_851R_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_SCS_HSC2_FrP15_851R_S 12U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* PduRConf_PduRDestPdu_SCS_HSC2_FrP15_851R_D not defined since it is not enabled.*/


/* -------------------- Routing path: 26 P2P_HSC2_FrI02_914T */
#if (defined PduRConf_PduRSrcPdu_P2P_HSC2_FrI02_914T_S)
#error PduRConf_PduRSrcPdu_P2P_HSC2_FrI02_914T_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_P2P_HSC2_FrI02_914T_S 9U /* SRC Com-UP-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_P2P_HSC2_FrI02_914T_S)
#error PduR_P2P_HSC2_FrI02_914T_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_P2P_HSC2_FrI02_914T_S 9U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_P2P_HSC2_FrI02_914T_D)
#error PduRConf_PduRDestPdu_P2P_HSC2_FrI02_914T_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_P2P_HSC2_FrI02_914T_D 5U /* DEST CanIf-LO-IF */


/* -------------------- Routing path: 27 GW_HSC2_FrP10_1009R */
#if (defined PduRConf_PduRSrcPdu_GW_HSC2_FrP10_1009R_S)
#error PduRConf_PduRSrcPdu_GW_HSC2_FrP10_1009R_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_GW_HSC2_FrP10_1009R_S 13U /* SRC CanIf-LO-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_GW_HSC2_FrP10_1009R_S)
#error PduR_GW_HSC2_FrP10_1009R_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_GW_HSC2_FrP10_1009R_S 13U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* PduRConf_PduRDestPdu_GW_HSC2_FrP10_1009R_D not defined since it is not enabled.*/


/* -------------------- Routing path: 28 GW_HSC2_IPK_FrP06_1345R */
#if (defined PduRConf_PduRSrcPdu_GW_HSC2_IPK_FrP06_1345R_S)
#error PduRConf_PduRSrcPdu_GW_HSC2_IPK_FrP06_1345R_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_GW_HSC2_IPK_FrP06_1345R_S 14U /* SRC CanIf-LO-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_GW_HSC2_IPK_FrP06_1345R_S)
#error PduR_GW_HSC2_IPK_FrP06_1345R_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_GW_HSC2_IPK_FrP06_1345R_S 14U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* PduRConf_PduRDestPdu_GW_HSC2_IPK_FrP06_1345R_D not defined since it is not enabled.*/


/* -------------------- Routing path: 29 P2P_IECU_HSC4_FrP01_764T */
#if (defined PduRConf_PduRSrcPdu_P2P_IECU_HSC4_FrP01_764T_S)
#error PduRConf_PduRSrcPdu_P2P_IECU_HSC4_FrP01_764T_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_P2P_IECU_HSC4_FrP01_764T_S 10U /* SRC Com-UP-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_P2P_IECU_HSC4_FrP01_764T_S)
#error PduR_P2P_IECU_HSC4_FrP01_764T_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_P2P_IECU_HSC4_FrP01_764T_S 10U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_P2P_IECU_HSC4_FrP01_764T_D)
#error PduRConf_PduRDestPdu_P2P_IECU_HSC4_FrP01_764T_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_P2P_IECU_HSC4_FrP01_764T_D 6U /* DEST CanIf-LO-IF */


/* -------------------- Routing path: 30 P2P_HSC4_FrP03_781T */
#if (defined PduRConf_PduRSrcPdu_P2P_HSC4_FrP03_781T_S)
#error PduRConf_PduRSrcPdu_P2P_HSC4_FrP03_781T_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_P2P_HSC4_FrP03_781T_S 11U /* SRC Com-UP-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_P2P_HSC4_FrP03_781T_S)
#error PduR_P2P_HSC4_FrP03_781T_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_P2P_HSC4_FrP03_781T_S 11U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_P2P_HSC4_FrP03_781T_D)
#error PduRConf_PduRDestPdu_P2P_HSC4_FrP03_781T_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_P2P_HSC4_FrP03_781T_D 7U /* DEST CanIf-LO-IF */


/* -------------------- Routing path: 31 P2P_IECU_HSC4_FrP02_912T */
#if (defined PduRConf_PduRSrcPdu_P2P_IECU_HSC4_FrP02_912T_S)
#error PduRConf_PduRSrcPdu_P2P_IECU_HSC4_FrP02_912T_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_P2P_IECU_HSC4_FrP02_912T_S 12U /* SRC Com-UP-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_P2P_IECU_HSC4_FrP02_912T_S)
#error PduR_P2P_IECU_HSC4_FrP02_912T_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_P2P_IECU_HSC4_FrP02_912T_S 12U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_P2P_IECU_HSC4_FrP02_912T_D)
#error PduRConf_PduRDestPdu_P2P_IECU_HSC4_FrP02_912T_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_P2P_IECU_HSC4_FrP02_912T_D 8U /* DEST CanIf-LO-IF */


/* -------------------- Routing path: 32 P2P_HSC2_FrP02_966T */
#if (defined PduRConf_PduRSrcPdu_P2P_HSC2_FrP02_966T_S)
#error PduRConf_PduRSrcPdu_P2P_HSC2_FrP02_966T_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_P2P_HSC2_FrP02_966T_S 13U /* SRC Com-UP-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_P2P_HSC2_FrP02_966T_S)
#error PduR_P2P_HSC2_FrP02_966T_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_P2P_HSC2_FrP02_966T_S 13U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_P2P_HSC2_FrP02_966T_D)
#error PduRConf_PduRDestPdu_P2P_HSC2_FrP02_966T_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_P2P_HSC2_FrP02_966T_D 9U /* DEST CanIf-LO-IF */


/* -------------------- Routing path: 33 EM_BerthIdInfo_0x529_1321R */
#if (defined PduRConf_PduRSrcPdu_EM_BerthIdInfo_0x529_1321R_S)
#error PduRConf_PduRSrcPdu_EM_BerthIdInfo_0x529_1321R_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_EM_BerthIdInfo_0x529_1321R_S 15U /* SRC CanIf-LO-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_EM_BerthIdInfo_0x529_1321R_S)
#error PduR_EM_BerthIdInfo_0x529_1321R_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_EM_BerthIdInfo_0x529_1321R_S 15U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* PduRConf_PduRDestPdu_EM_BerthIdInfo_0x529_1321R_D not defined since it is not enabled.*/


/* -------------------- Routing path: 34 EM_APAPLDINF_0x531_1329T */
#if (defined PduRConf_PduRSrcPdu_EM_APAPLDINF_0x531_1329T_S)
#error PduRConf_PduRSrcPdu_EM_APAPLDINF_0x531_1329T_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_EM_APAPLDINF_0x531_1329T_S 14U /* SRC Com-UP-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_EM_APAPLDINF_0x531_1329T_S)
#error PduR_EM_APAPLDINF_0x531_1329T_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_EM_APAPLDINF_0x531_1329T_S 14U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_EM_APAPLDINF_0x531_1329T_D)
#error PduRConf_PduRDestPdu_EM_APAPLDINF_0x531_1329T_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_EM_APAPLDINF_0x531_1329T_D 10U /* DEST CanIf-LO-IF */


/* -------------------- Routing path: 35 LADS_HSC4_OBJ_0_INF_1330T */
#if (defined PduRConf_PduRSrcPdu_LADS_HSC4_OBJ_0_INF_1330T_S)
#error PduRConf_PduRSrcPdu_LADS_HSC4_OBJ_0_INF_1330T_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_LADS_HSC4_OBJ_0_INF_1330T_S 15U /* SRC Com-UP-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_LADS_HSC4_OBJ_0_INF_1330T_S)
#error PduR_LADS_HSC4_OBJ_0_INF_1330T_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_LADS_HSC4_OBJ_0_INF_1330T_S 15U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_LADS_HSC4_OBJ_0_INF_1330T_D)
#error PduRConf_PduRDestPdu_LADS_HSC4_OBJ_0_INF_1330T_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_LADS_HSC4_OBJ_0_INF_1330T_D 11U /* DEST CanIf-LO-IF */


/* -------------------- Routing path: 36 LADS_HSC4_OBJ_1_INF_1337T */
#if (defined PduRConf_PduRSrcPdu_LADS_HSC4_OBJ_1_INF_1337T_S)
#error PduRConf_PduRSrcPdu_LADS_HSC4_OBJ_1_INF_1337T_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_LADS_HSC4_OBJ_1_INF_1337T_S 16U /* SRC Com-UP-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_LADS_HSC4_OBJ_1_INF_1337T_S)
#error PduR_LADS_HSC4_OBJ_1_INF_1337T_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_LADS_HSC4_OBJ_1_INF_1337T_S 16U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_LADS_HSC4_OBJ_1_INF_1337T_D)
#error PduRConf_PduRDestPdu_LADS_HSC4_OBJ_1_INF_1337T_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_LADS_HSC4_OBJ_1_INF_1337T_D 12U /* DEST CanIf-LO-IF */


/* -------------------- Routing path: 37 LADS_HSC4_OBJ_2_INF_1339T */
#if (defined PduRConf_PduRSrcPdu_LADS_HSC4_OBJ_2_INF_1339T_S)
#error PduRConf_PduRSrcPdu_LADS_HSC4_OBJ_2_INF_1339T_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_LADS_HSC4_OBJ_2_INF_1339T_S 17U /* SRC Com-UP-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_LADS_HSC4_OBJ_2_INF_1339T_S)
#error PduR_LADS_HSC4_OBJ_2_INF_1339T_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_LADS_HSC4_OBJ_2_INF_1339T_S 17U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_LADS_HSC4_OBJ_2_INF_1339T_D)
#error PduRConf_PduRDestPdu_LADS_HSC4_OBJ_2_INF_1339T_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_LADS_HSC4_OBJ_2_INF_1339T_D 13U /* DEST CanIf-LO-IF */


/* -------------------- Routing path: 38 LADS_HSC4_OBJ_3_INF_1340T */
#if (defined PduRConf_PduRSrcPdu_LADS_HSC4_OBJ_3_INF_1340T_S)
#error PduRConf_PduRSrcPdu_LADS_HSC4_OBJ_3_INF_1340T_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_LADS_HSC4_OBJ_3_INF_1340T_S 18U /* SRC Com-UP-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_LADS_HSC4_OBJ_3_INF_1340T_S)
#error PduR_LADS_HSC4_OBJ_3_INF_1340T_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_LADS_HSC4_OBJ_3_INF_1340T_S 18U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_LADS_HSC4_OBJ_3_INF_1340T_D)
#error PduRConf_PduRDestPdu_LADS_HSC4_OBJ_3_INF_1340T_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_LADS_HSC4_OBJ_3_INF_1340T_D 14U /* DEST CanIf-LO-IF */


/* -------------------- Routing path: 39 LADS_HSC4_OBJ_4_INF_1341T */
#if (defined PduRConf_PduRSrcPdu_LADS_HSC4_OBJ_4_INF_1341T_S)
#error PduRConf_PduRSrcPdu_LADS_HSC4_OBJ_4_INF_1341T_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_LADS_HSC4_OBJ_4_INF_1341T_S 19U /* SRC Com-UP-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_LADS_HSC4_OBJ_4_INF_1341T_S)
#error PduR_LADS_HSC4_OBJ_4_INF_1341T_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_LADS_HSC4_OBJ_4_INF_1341T_S 19U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_LADS_HSC4_OBJ_4_INF_1341T_D)
#error PduRConf_PduRDestPdu_LADS_HSC4_OBJ_4_INF_1341T_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_LADS_HSC4_OBJ_4_INF_1341T_D 15U /* DEST CanIf-LO-IF */


/* -------------------- Routing path: 40 LADS_HSC4_OBJ_5_INF_1342T */
#if (defined PduRConf_PduRSrcPdu_LADS_HSC4_OBJ_5_INF_1342T_S)
#error PduRConf_PduRSrcPdu_LADS_HSC4_OBJ_5_INF_1342T_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_LADS_HSC4_OBJ_5_INF_1342T_S 20U /* SRC Com-UP-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_LADS_HSC4_OBJ_5_INF_1342T_S)
#error PduR_LADS_HSC4_OBJ_5_INF_1342T_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_LADS_HSC4_OBJ_5_INF_1342T_S 20U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_LADS_HSC4_OBJ_5_INF_1342T_D)
#error PduRConf_PduRDestPdu_LADS_HSC4_OBJ_5_INF_1342T_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_LADS_HSC4_OBJ_5_INF_1342T_D 16U /* DEST CanIf-LO-IF */


/* -------------------- Routing path: 41 LADS_HSC4_OBJ_6_INF_1343T */
#if (defined PduRConf_PduRSrcPdu_LADS_HSC4_OBJ_6_INF_1343T_S)
#error PduRConf_PduRSrcPdu_LADS_HSC4_OBJ_6_INF_1343T_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_LADS_HSC4_OBJ_6_INF_1343T_S 21U /* SRC Com-UP-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_LADS_HSC4_OBJ_6_INF_1343T_S)
#error PduR_LADS_HSC4_OBJ_6_INF_1343T_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_LADS_HSC4_OBJ_6_INF_1343T_S 21U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_LADS_HSC4_OBJ_6_INF_1343T_D)
#error PduRConf_PduRDestPdu_LADS_HSC4_OBJ_6_INF_1343T_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_LADS_HSC4_OBJ_6_INF_1343T_D 17U /* DEST CanIf-LO-IF */


/* -------------------- Routing path: 42 LADS_HSC4_OBJ_7_INF_1346T */
#if (defined PduRConf_PduRSrcPdu_LADS_HSC4_OBJ_7_INF_1346T_S)
#error PduRConf_PduRSrcPdu_LADS_HSC4_OBJ_7_INF_1346T_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_LADS_HSC4_OBJ_7_INF_1346T_S 22U /* SRC Com-UP-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_LADS_HSC4_OBJ_7_INF_1346T_S)
#error PduR_LADS_HSC4_OBJ_7_INF_1346T_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_LADS_HSC4_OBJ_7_INF_1346T_S 22U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_LADS_HSC4_OBJ_7_INF_1346T_D)
#error PduRConf_PduRDestPdu_LADS_HSC4_OBJ_7_INF_1346T_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_LADS_HSC4_OBJ_7_INF_1346T_D 18U /* DEST CanIf-LO-IF */


/* -------------------- Routing path: 43 EM_APAPLDINF_0x545_1349T */
#if (defined PduRConf_PduRSrcPdu_EM_APAPLDINF_0x545_1349T_S)
#error PduRConf_PduRSrcPdu_EM_APAPLDINF_0x545_1349T_S is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_EM_APAPLDINF_0x545_1349T_S 23U /* SRC Com-UP-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_EM_APAPLDINF_0x545_1349T_S)
#error PduR_EM_APAPLDINF_0x545_1349T_S is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_EM_APAPLDINF_0x545_1349T_S 23U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_EM_APAPLDINF_0x545_1349T_D)
#error PduRConf_PduRDestPdu_EM_APAPLDINF_0x545_1349T_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_EM_APAPLDINF_0x545_1349T_D 19U /* DEST CanIf-LO-IF */


/* -------------------- Routing path: 44 RPath_DoIp_Rx */
#if (defined PduRConf_PduRSrcPdu_RPath_DoIp_Rx)
#error PduRConf_PduRSrcPdu_RPath_DoIp_Rx is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_RPath_DoIp_Rx 0U /* SRC DoIP-LO-TP */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_RPath_DoIp_Rx)
#error PduR_RPath_DoIp_Rx is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_RPath_DoIp_Rx 0U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_RPath_DoIp_RxD)
#error PduRConf_PduRDestPdu_RPath_DoIp_RxD is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_RPath_DoIp_RxD 0U /* DEST Dcm-UP-TP */


/* -------------------- Routing path: 45 RPath_DoIp_Tx */
#if (defined PduRConf_PduRSrcPdu_RPath_DoIp_Tx)
#error PduRConf_PduRSrcPdu_RPath_DoIp_Tx is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_RPath_DoIp_Tx 0U /* SRC Dcm-UP-TP */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_RPath_DoIp_Tx)
#error PduR_RPath_DoIp_Tx is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_RPath_DoIp_Tx 0U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_RPath_DoIp_TxD)
#error PduRConf_PduRDestPdu_RPath_DoIp_TxD is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_RPath_DoIp_TxD 0U /* DEST DoIP-LO-TP */


/* -------------------- Routing path: 46 Pdu_UdpTest_T */
#if (defined PduRConf_PduRSrcPdu_Pdu_UdpTest_T)
#error PduRConf_PduRSrcPdu_Pdu_UdpTest_T is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Pdu_UdpTest_T 24U /* SRC Com-UP-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Pdu_UdpTest_T)
#error PduR_Pdu_UdpTest_T is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Pdu_UdpTest_T 24U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_Pdu_UdpTest_TD)
#error PduRConf_PduRDestPdu_Pdu_UdpTest_TD is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Pdu_UdpTest_TD 4U /* DEST SoAd-LO-IF */


/* -------------------- Routing path: 47 Pdu_UdpTest_R */
#if (defined PduRConf_PduRSrcPdu_Pdu_UdpTest_R)
#error PduRConf_PduRSrcPdu_Pdu_UdpTest_R is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Pdu_UdpTest_R 4U /* SRC SoAd-LO-IF */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Pdu_UdpTest_R)
#error PduR_Pdu_UdpTest_R is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Pdu_UdpTest_R 4U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* PduRConf_PduRDestPdu_Pdu_UdpTest_RD not defined since it is not enabled.*/



/* Define vendor specific destination PDU IDs of adjacent modules */
#if (defined PDUR_PROVIDE_ADJACENT_MODULE_VENDOR_SYMBOLIC_NAMES)

/* -------------------- Routing path: 0 Pdu_CounterOut_T */
#define PDURSA_Pdu_CounterOut_T 20U /* SRC Com-UP-IF */
#define PDURDA_Pdu_CounterOut_T 0U /* DEST SoAd-LO-IF DIRECT */

/* -------------------- Routing path: 1 Pdu_DummyOut_R */
/* PDURSA_Pdu_DummyOut_R   SRC SoAd-LO-IF  Not defined since the configuration does not supply this ID */
#define PDURDA_Pdu_DummyOut_R 0U /* DEST Com-UP-IF */

/* -------------------- Routing path: 2 Pdu_CounterIn_R */
/* PDURSA_Pdu_CounterIn_R   SRC SoAd-LO-IF  Not defined since the configuration does not supply this ID */
#define PDURDA_Pdu_CounterIn_R 1U /* DEST Com-UP-IF */

/* -------------------- Routing path: 3 Pdu_DummyIn_T */
#define PDURSA_Pdu_DummyIn_T 21U /* SRC Com-UP-IF */
#define PDURDA_Pdu_DummyIn_T 1U /* DEST SoAd-LO-IF DIRECT */

/* -------------------- Routing path: 4 Pdu_UssToolIn_R */
/* PDURSA_Pdu_UssToolIn_R   SRC SoAd-LO-IF  Not defined since the configuration does not supply this ID */
#define PDURDA_Pdu_UssToolIn_R 2U /* DEST Com-UP-IF */

/* -------------------- Routing path: 5 Pdu_UssToolOut_T */
#define PDURSA_Pdu_UssToolOut_T 22U /* SRC Com-UP-IF */
#define PDURDA_Pdu_UssToolOut_T 2U /* DEST SoAd-LO-IF DIRECT */

/* -------------------- Routing path: 6 Pdu_CfmIn_R */
/* PDURSA_Pdu_CfmIn_R   SRC SoAd-LO-IF  Not defined since the configuration does not supply this ID */
#define PDURDA_Pdu_CfmIn_R 3U /* DEST Com-UP-IF */

/* -------------------- Routing path: 7 Pdu_CfmOut_T */
#define PDURSA_Pdu_CfmOut_T 23U /* SRC Com-UP-IF */
#define PDURDA_Pdu_CfmOut_T 3U /* DEST SoAd-LO-IF DIRECT */

/* -------------------- Routing path: 8 GW_HSC2_SCU_FrP00_157R */
/* PDURSA_GW_HSC2_SCU_FrP00_157R   SRC CanIf-LO-IF  Not defined since the configuration does not supply this ID */
#define PDURDA_GW_HSC2_SCU_FrP00_157R 5U /* DEST Com-UP-IF */

/* -------------------- Routing path: 9 SCS_HSC2_FrP00_193R */
/* PDURSA_SCS_HSC2_FrP00_193R   SRC CanIf-LO-IF  Not defined since the configuration does not supply this ID */
#define PDURDA_SCS_HSC2_FrP00_193R 6U /* DEST Com-UP-IF */

/* -------------------- Routing path: 10 SCS_HSC2_FrP01_197R */
/* PDURSA_SCS_HSC2_FrP01_197R   SRC CanIf-LO-IF  Not defined since the configuration does not supply this ID */
#define PDURDA_SCS_HSC2_FrP01_197R 7U /* DEST Com-UP-IF */

/* -------------------- Routing path: 11 SCS_HSC2_FrP02_389R */
/* PDURSA_SCS_HSC2_FrP02_389R   SRC CanIf-LO-IF  Not defined since the configuration does not supply this ID */
#define PDURDA_SCS_HSC2_FrP02_389R 8U /* DEST Com-UP-IF */

/* -------------------- Routing path: 12 P2P_HSC2_FrP00_424T */
#define PDURSA_P2P_HSC2_FrP00_424T 0U /* SRC Com-UP-IF */
#define PDURDA_P2P_HSC2_FrP00_424T 0U /* DEST CanIf-LO-IF DIRECT */

/* -------------------- Routing path: 13 EPS_HSC2_FrP02_433R */
/* PDURSA_EPS_HSC2_FrP02_433R   SRC CanIf-LO-IF  Not defined since the configuration does not supply this ID */
#define PDURDA_EPS_HSC2_FrP02_433R 9U /* DEST Com-UP-IF */

/* -------------------- Routing path: 14 P2P_HSC2_FrP01_437T */
#define PDURSA_P2P_HSC2_FrP01_437T 1U /* SRC Com-UP-IF */
#define PDURDA_P2P_HSC2_FrP01_437T 1U /* DEST CanIf-LO-IF DIRECT */

/* -------------------- Routing path: 15 EHBS_HSC2_FrP00_438R */
/* PDURSA_EHBS_HSC2_FrP00_438R   SRC CanIf-LO-IF  Not defined since the configuration does not supply this ID */
#define PDURDA_EHBS_HSC2_FrP00_438R 10U /* DEST Com-UP-IF */

/* -------------------- Routing path: 16 SCS_HSC2_FrP03_455R */
/* PDURSA_SCS_HSC2_FrP03_455R   SRC CanIf-LO-IF  Not defined since the configuration does not supply this ID */
#define PDURDA_SCS_HSC2_FrP03_455R 11U /* DEST Com-UP-IF */

/* -------------------- Routing path: 17 SAS_HSC2_FrP00_485R */
/* PDURSA_SAS_HSC2_FrP00_485R   SRC CanIf-LO-IF  Not defined since the configuration does not supply this ID */
#define PDURDA_SAS_HSC2_FrP00_485R 12U /* DEST Com-UP-IF */

/* -------------------- Routing path: 18 SCS_HSC2_FrP05_489R */
/* PDURSA_SCS_HSC2_FrP05_489R   SRC CanIf-LO-IF  Not defined since the configuration does not supply this ID */
#define PDURDA_SCS_HSC2_FrP05_489R 13U /* DEST Com-UP-IF */

/* -------------------- Routing path: 19 EPB_HSC2_FrP01_554R */
/* PDURSA_EPB_HSC2_FrP01_554R   SRC CanIf-LO-IF  Not defined since the configuration does not supply this ID */
#define PDURDA_EPB_HSC2_FrP01_554R 14U /* DEST Com-UP-IF */

/* -------------------- Routing path: 20 P2P_HSC2_FrP04_567T */
#define PDURSA_P2P_HSC2_FrP04_567T 2U /* SRC Com-UP-IF */
#define PDURDA_P2P_HSC2_FrP04_567T 2U /* DEST CanIf-LO-IF DIRECT */

/* -------------------- Routing path: 21 P2P_HSC2_FrP03_573T */
#define PDURSA_P2P_HSC2_FrP03_573T 3U /* SRC Com-UP-IF */
#define PDURDA_P2P_HSC2_FrP03_573T 3U /* DEST CanIf-LO-IF DIRECT */

/* -------------------- Routing path: 22 APA_SecCH_FrP03_651T */
#define PDURSA_APA_SecCH_FrP03_651T 4U /* SRC Com-UP-IF */
#define PDURDA_APA_SecCH_FrP03_651T 4U /* DEST CanIf-LO-IF DIRECT */

/* -------------------- Routing path: 23 SCS_HSC2_FrP11_840R */
/* PDURSA_SCS_HSC2_FrP11_840R   SRC CanIf-LO-IF  Not defined since the configuration does not supply this ID */
#define PDURDA_SCS_HSC2_FrP11_840R 15U /* DEST Com-UP-IF */

/* -------------------- Routing path: 24 SCS_HSC2_FrP12_842R */
/* PDURSA_SCS_HSC2_FrP12_842R   SRC CanIf-LO-IF  Not defined since the configuration does not supply this ID */
#define PDURDA_SCS_HSC2_FrP12_842R 16U /* DEST Com-UP-IF */

/* -------------------- Routing path: 25 SCS_HSC2_FrP15_851R */
/* PDURSA_SCS_HSC2_FrP15_851R   SRC CanIf-LO-IF  Not defined since the configuration does not supply this ID */
#define PDURDA_SCS_HSC2_FrP15_851R 17U /* DEST Com-UP-IF */

/* -------------------- Routing path: 26 P2P_HSC2_FrI02_914T */
#define PDURSA_P2P_HSC2_FrI02_914T 8U /* SRC Com-UP-IF */
#define PDURDA_P2P_HSC2_FrI02_914T 5U /* DEST CanIf-LO-IF DIRECT */

/* -------------------- Routing path: 27 GW_HSC2_FrP10_1009R */
/* PDURSA_GW_HSC2_FrP10_1009R   SRC CanIf-LO-IF  Not defined since the configuration does not supply this ID */
#define PDURDA_GW_HSC2_FrP10_1009R 18U /* DEST Com-UP-IF */

/* -------------------- Routing path: 28 GW_HSC2_IPK_FrP06_1345R */
/* PDURSA_GW_HSC2_IPK_FrP06_1345R   SRC CanIf-LO-IF  Not defined since the configuration does not supply this ID */
#define PDURDA_GW_HSC2_IPK_FrP06_1345R 19U /* DEST Com-UP-IF */

/* -------------------- Routing path: 29 P2P_IECU_HSC4_FrP01_764T */
#define PDURSA_P2P_IECU_HSC4_FrP01_764T 5U /* SRC Com-UP-IF */
#define PDURDA_P2P_IECU_HSC4_FrP01_764T 6U /* DEST CanIf-LO-IF DIRECT */

/* -------------------- Routing path: 30 P2P_HSC4_FrP03_781T */
#define PDURSA_P2P_HSC4_FrP03_781T 6U /* SRC Com-UP-IF */
#define PDURDA_P2P_HSC4_FrP03_781T 7U /* DEST CanIf-LO-IF DIRECT */

/* -------------------- Routing path: 31 P2P_IECU_HSC4_FrP02_912T */
#define PDURSA_P2P_IECU_HSC4_FrP02_912T 7U /* SRC Com-UP-IF */
#define PDURDA_P2P_IECU_HSC4_FrP02_912T 8U /* DEST CanIf-LO-IF DIRECT */

/* -------------------- Routing path: 32 P2P_HSC2_FrP02_966T */
#define PDURSA_P2P_HSC2_FrP02_966T 9U /* SRC Com-UP-IF */
#define PDURDA_P2P_HSC2_FrP02_966T 9U /* DEST CanIf-LO-IF DIRECT */

/* -------------------- Routing path: 33 EM_BerthIdInfo_0x529_1321R */
/* PDURSA_EM_BerthIdInfo_0x529_1321R   SRC CanIf-LO-IF  Not defined since the configuration does not supply this ID */
#define PDURDA_EM_BerthIdInfo_0x529_1321R 20U /* DEST Com-UP-IF */

/* -------------------- Routing path: 34 EM_APAPLDINF_0x531_1329T */
#define PDURSA_EM_APAPLDINF_0x531_1329T 10U /* SRC Com-UP-IF */
#define PDURDA_EM_APAPLDINF_0x531_1329T 10U /* DEST CanIf-LO-IF DIRECT */

/* -------------------- Routing path: 35 LADS_HSC4_OBJ_0_INF_1330T */
#define PDURSA_LADS_HSC4_OBJ_0_INF_1330T 11U /* SRC Com-UP-IF */
#define PDURDA_LADS_HSC4_OBJ_0_INF_1330T 11U /* DEST CanIf-LO-IF DIRECT */

/* -------------------- Routing path: 36 LADS_HSC4_OBJ_1_INF_1337T */
#define PDURSA_LADS_HSC4_OBJ_1_INF_1337T 12U /* SRC Com-UP-IF */
#define PDURDA_LADS_HSC4_OBJ_1_INF_1337T 12U /* DEST CanIf-LO-IF DIRECT */

/* -------------------- Routing path: 37 LADS_HSC4_OBJ_2_INF_1339T */
#define PDURSA_LADS_HSC4_OBJ_2_INF_1339T 13U /* SRC Com-UP-IF */
#define PDURDA_LADS_HSC4_OBJ_2_INF_1339T 13U /* DEST CanIf-LO-IF DIRECT */

/* -------------------- Routing path: 38 LADS_HSC4_OBJ_3_INF_1340T */
#define PDURSA_LADS_HSC4_OBJ_3_INF_1340T 14U /* SRC Com-UP-IF */
#define PDURDA_LADS_HSC4_OBJ_3_INF_1340T 14U /* DEST CanIf-LO-IF DIRECT */

/* -------------------- Routing path: 39 LADS_HSC4_OBJ_4_INF_1341T */
#define PDURSA_LADS_HSC4_OBJ_4_INF_1341T 15U /* SRC Com-UP-IF */
#define PDURDA_LADS_HSC4_OBJ_4_INF_1341T 15U /* DEST CanIf-LO-IF DIRECT */

/* -------------------- Routing path: 40 LADS_HSC4_OBJ_5_INF_1342T */
#define PDURSA_LADS_HSC4_OBJ_5_INF_1342T 16U /* SRC Com-UP-IF */
#define PDURDA_LADS_HSC4_OBJ_5_INF_1342T 16U /* DEST CanIf-LO-IF DIRECT */

/* -------------------- Routing path: 41 LADS_HSC4_OBJ_6_INF_1343T */
#define PDURSA_LADS_HSC4_OBJ_6_INF_1343T 17U /* SRC Com-UP-IF */
#define PDURDA_LADS_HSC4_OBJ_6_INF_1343T 17U /* DEST CanIf-LO-IF DIRECT */

/* -------------------- Routing path: 42 LADS_HSC4_OBJ_7_INF_1346T */
#define PDURSA_LADS_HSC4_OBJ_7_INF_1346T 18U /* SRC Com-UP-IF */
#define PDURDA_LADS_HSC4_OBJ_7_INF_1346T 18U /* DEST CanIf-LO-IF DIRECT */

/* -------------------- Routing path: 43 EM_APAPLDINF_0x545_1349T */
#define PDURSA_EM_APAPLDINF_0x545_1349T 19U /* SRC Com-UP-IF */
#define PDURDA_EM_APAPLDINF_0x545_1349T 19U /* DEST CanIf-LO-IF DIRECT */

/* -------------------- Routing path: 44 RPath_DoIp_Rx */
#define PDURSA_ETHPDU_DOIP_RX 0U /* SRC DoIP-LO-TP */
#define PDURDA_ETHPDU_DOIP_RX 0U /* DEST Dcm-UP-TP */

/* -------------------- Routing path: 45 RPath_DoIp_Tx */
#define PDURSA_ETHPDU_DOIP_TX 0U /* SRC Dcm-UP-TP */
#define PDURDA_ETHPDU_DOIP_TX 0U /* DEST DoIP-LO-TP */

/* -------------------- Routing path: 46 Pdu_UdpTest_T */
#define PDURSA_ETHPDU_TXUDP_Test1 24U /* SRC Com-UP-IF */
#define PDURDA_ETHPDU_TXUDP_Test1 4U /* DEST SoAd-LO-IF DIRECT */

/* -------------------- Routing path: 47 Pdu_UdpTest_R */
/* PDURSA_ETHPDU_RXUDP_Test1   SRC SoAd-LO-IF  Not defined since the configuration does not supply this ID */
#define PDURDA_ETHPDU_RXUDP_Test1 4U /* DEST Com-UP-IF */

#endif /* defined PDUR_PROVIDE_ADJACENT_MODULE_VENDOR_SYMBOLIC_NAMES */

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef PDUR_SYMBOLIC_NAMES_PBCFG_H  */
/*==================[end of file]===========================================*/
