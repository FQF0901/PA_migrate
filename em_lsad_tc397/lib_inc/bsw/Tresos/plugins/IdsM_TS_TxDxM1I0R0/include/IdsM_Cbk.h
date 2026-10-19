/**
 * \file
 *
 * \brief AUTOSAR IdsM
 *
 * This file contains the implementation of the AUTOSAR
 * module IdsM.
 *
 * \version 1.0.0
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef IDSM_CBK_H
#define IDSM_CBK_H

/*==================[inclusions]============================================*/

#include <IdsM_Cfg.h>               /* IdsM pre-compile-time configuration */
#include <Std_Types.h>              /* AUTOSAR standard types */
/* !LINKSTO IdsM.ASR20-11.SWS_IdsM_91022,1 */
#include <ComStack_Types.h>         /* AUTOSAR Communication Stack types */

#if (defined IDSM_HOST_ECU)
#if (defined IDSM_SINK_IDSR_SUPPORT)
/* !LINKSTO IdsM.ASR20-11.SWS_IdsM_00105,1 */
#include <PduR_IdsM.h>              /* IdsM PduR Header File */
#endif /* IDSM_SINK_IDSR_SUPPORT */
#endif /* IDSM_HOST_ECU */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

#define IDSM_START_SEC_CODE
#include <IdsM_MemMap.h>

/** \brief IdsM transmission confirmation interface
 *
 * The lower layer communication interface module confirms the transmission
 * of a PDU, or the failure to transmit a PDU.
 *
 * \param[in] txPduId ID of the PDU that has been transmitted.
 * \param[in] result E_OK: The PDU was transmitted. E_NOT_OK: Transmission of the PDU failed.
 *
 * \ServiceID{0x40}
 * \Reentrancy{Non-Reentrant}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, IDSM_CODE) IdsM_TxConfirmation
(
    VAR(PduIdType, TYPEDEF) txPduId,
    VAR(Std_ReturnType, TYPEDEF) result
);

/**
 * \brief IdsM module Reception indication callback function.
 *
 * This callback function is called by the lower interface module to confirm the reception
 * of a PDU.
 * Note: This is a dummy function that should never be called. If it is called, a DET error is reported.
 *
 * \param[in] rxPduId - ID of the PDU that has been received.
 * \param[in] pduInfoPtr - Pointer to the data which has been received.
 *
 * \ServiceID{0x41}
 * \Reentrancy{  Reentrant for different PduIds
 *               Non Reentrant for the same PduId  }
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, IDSM_CODE) IdsM_PduRIfRxIndication
(
    VAR(PduIdType, TYPEDEF) rxPduId,
    P2VAR(PduInfoType, AUTOMATIC, IDSM_APPL_DATA) pduInfoPtr
);

#define IDSM_STOP_SEC_CODE
#include <IdsM_MemMap.h>

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef IDSM_CBK_H */
/*==================[end of file]===========================================*/
