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

#ifndef IDSM_INT_H
#define IDSM_INT_H

/*==================[inclusions]============================================*/

#include <IdsM_Cfg.h>             /* IdsM pre-compile-time configuration */
#include <IdsM_CfgTypes.h>        /* IdsM pre-compile-time dependent configuration types */
#include <IdsM_Lcfg.h>            /* IdsM link time configuration */
#include <IdsM_ProtocolAccess.h>  /* IDS protocol access */
#include <IdsM_Types.h>           /* IdsM general types */
#include <IdsM_Trace.h>           /* IdsM trace */
#include <SchM_IdsM.h>            /* AUTOSAR BSW scheduler */

#ifdef IDSM_PRECOMPILE_TIME_PBCFG_ACCESS
#include <IdsM_PBcfg.h>
#endif /* IDSM_PRECOMPILE_TIME_PBCFG_ACCESS */

#if (defined TS_RELOCATABLE_CFG_ENABLE)
#error TS_RELOCATABLE_CFG_ENABLE is already defined
#endif
#define TS_RELOCATABLE_CFG_ENABLE IDSM_RELOCATABLE_CFG_ENABLE
#include <TSPBConfig.h>       /* post-build config access macros */

#if(IDSM_DEV_ERROR_DETECT == STD_ON)
/* !LINKSTO IdsM.ASR20-11.SWS_IdsM_00101,1 */
#include <Det.h>                    /* AUTOSAR development error tracer */
#endif /* IDSM_DEV_ERROR_DETECT == STD_ON */

/*==================[macros]================================================*/

/* --- IdsM DET ERROR ----------------------------------------------------- */

/** \brief IdsM DET Report Error Wrapper */
/* !LINKSTO eb.custom.IdsM.Server.Acess.OfBSW,1 */
#if (defined IDSM_DET_REPORT_ERROR)
#error IDSM_DET_REPORT_ERROR already defined!
#endif /* #if( defined IDSM_DET_REPORT_ERROR)*/
#define IDSM_DET_REPORT_ERROR(ApiId, ErrorId) \
    ((void)Det_ReportError(IDSM_MODULE_ID, IDSM_INSTANCE_ID, (ApiId), (ErrorId)))



/* --- IdsM APIs SID ------------------------------------------------------ */

/** \brief IdsM_Init Service Id */
#if (defined IDSM_SID_INIT)
#error IDSM_SID_INIT already defined!
#endif /* #if( defined IDSM_SID_INIT)*/
#define IDSM_SID_INIT                                                    0x00U

#if( IDSM_VERSION_INFO_API == STD_ON )
/** \brief IdsM_GetVersionInfo Service Id */
#if (defined IDSM_SID_GETVERSIONINFO)
#error IDSM_SID_GETVERSIONINFO already defined!
#endif /* #if( defined IDSM_SID_GETVERSIONINFO)*/
#define IDSM_SID_GETVERSIONINFO                                          0x01U
#endif /* #if( IDSM_VERSION_INFO_API == STD_ON ) */

/** \brief IdsM_MainFunction Service Id */
#if (defined IDSM_SID_MAINFUNCTION)
#error IDSM_SID_MAINFUNCTION already defined!
#endif /* #if( defined IDSM_SID_MAINFUNCTION)*/
#define IDSM_SID_MAINFUNCTION                                            0x02U

/** \brief IdsM_SetSecurityEvent Service Id */
#if (defined IDSM_SID_SETSECURITYEVENT)
#error IDSM_SID_SETSECURITYEVENT already defined!
#endif /* #if( defined IDSM_SID_SETSECURITYEVENT)*/
#define IDSM_SID_SETSECURITYEVENT                                        0x03U

/** \brief IdsM_SetSecurityEventWithContextData Service Id */
#if (defined IDSM_SID_SETSECURITYEVENTWITHCONTEXTDATA)
#error IDSM_SID_SETSECURITYEVENTWITHCONTEXTDATA already defined!
#endif /* #if( defined IDSM_SID_SETSECURITYEVENTWITHCONTEXTDATA)*/
#define IDSM_SID_SETSECURITYEVENTWITHCONTEXTDATA                         0x04U

/** \brief IdsM_SetSecurityEventWithCount Service Id */
#if (defined IDSM_SID_SETSECURITYEVENTWITHCOUNT)
#error IDSM_SID_SETSECURITYEVENTWITHCOUNT already defined!
#endif /* #if( defined IDSM_SID_SETSECURITYEVENTWITHCOUNT)*/
#define IDSM_SID_SETSECURITYEVENTWITHCOUNT                               0x05U

/** \brief IdsM_SetSecurityEventWithCountContextData Service Id */
#if (defined IDSM_SID_SETSECURITYEVENTWITHCOUNTCONTEXTDATA)
#error IDSM_SID_SETSECURITYEVENTWITHCOUNTCONTEXTDATA already defined!
#endif /* #if( defined IDSM_SID_SETSECURITYEVENTWITHCOUNTCONTEXTDATA)*/
#define IDSM_SID_SETSECURITYEVENTWITHCOUNTCONTEXTDATA                    0x06U

/** \brief IdsM_SetSecurityEventWithTimestampCount Service Id */
#if (defined IDSM_SID_SETSECURITYEVENTWITHTIMESTAMPCOUNT)
#error IDSM_SID_SETSECURITYEVENTWITHTIMESTAMPCOUNT already defined!
#endif /* #if( defined IDSM_SID_SETSECURITYEVENTWITHTIMESTAMPCOUNT)*/
#define IDSM_SID_SETSECURITYEVENTWITHTIMESTAMPCOUNT                      0x07U

/** \brief IdsM_SetSecurityEventWithTimestampCountContextData Service Id */
#if (defined IDSM_SID_SETSECURITYEVENTWITHTIMESTAMPCOUNTCONTEXTDATA)
#error IDSM_SID_SETSECURITYEVENTWITHTIMESTAMPCOUNTCONTEXTDATA already defined!
#endif /* #if( defined IDSM_SID_SETSECURITYEVENTWITHTIMESTAMPCOUNTCONTEXTDATA)*/
#define IDSM_SID_SETSECURITYEVENTWITHTIMESTAMPCOUNTCONTEXTDATA           0x08U

/** \brief IdsM_SetExtSecurityEventWithTimestampCount Service Id */
#if (defined IDSM_SID_SETEXTSECURITYEVENTWITHTIMESTAMPCOUNT)
#error IDSM_SID_SETEXTSECURITYEVENTWITHTIMESTAMPCOUNT already defined!
#endif /* #if( defined IDSM_SID_SETEXTSECURITYEVENTWITHTIMESTAMPCOUNT)*/
#define IDSM_SID_SETEXTSECURITYEVENTWITHTIMESTAMPCOUNT                   0x61U

/** \brief IdsM_SetExtSecurityEventWithTimestampCountContextData Service Id */
#if (defined IDSM_SID_SETEXTSECURITYEVENTWITHTIMESTAMPCOUNTCONTEXTDATA)
#error IDSM_SID_SETEXTSECURITYEVENTWITHTIMESTAMPCOUNTCONTEXTDATA already defined!
#endif /* #if( defined IDSM_SID_SETEXTSECURITYEVENTWITHTIMESTAMPCOUNTCONTEXTDATA)*/
#define IDSM_SID_SETEXTSECURITYEVENTWITHTIMESTAMPCOUNTCONTEXTDATA        0x62U

/** \brief IdsM_TxConfirmation Service Id */
#if (defined IDSM_SID_TXCONFIRMATION)
#error IDSM_SID_TXCONFIRMATION already defined!
#endif /* #if (defined IDSM_SID_TXCONFIRMATION)*/
#define IDSM_SID_TXCONFIRMATION                                          0x40U

/** \brief IdsM_PduRIfRxIndication Service Id */
#if (defined IDSM_SID_PDURIFRXINDICATION)
#error IDSM_SID_PDURIFRXINDICATION already defined!
#endif /* #if (defined IDSM_SID_PDURIFRXINDICATION)*/
#define IDSM_SID_PDURIFRXINDICATION                                      0x41U

/* --- Error Macros ------------------------------------------------------- */

/** \brief Invalid Buffer Id */
/* !LINKSTO IdsM.ASR20-11.SWS_IdsM_00604,1 */
#if (defined IDSM_INVALID_INDEX)
#error IDSM_INVALID_INDEX already defined!
#endif /* #if( defined IDSM_INVALID_INDEX)*/
#define IDSM_INVALID_INDEX                                             0xFFFFU

/** \brief Empty state list */
#if (defined IDSM_EMPTY_STATE_LIST)
#error IDSM_EMPTY_STATE_LIST already defined!
#endif /* #if( defined IDSM_EMPTY_STATE_LIST)*/
#define IDSM_EMPTY_STATE_LIST                                          0xFFFFU

/* API function called with an invalid event identifier. */
/* !LINKSTO IdsM.ASR20-11.SWS_IdsM_02003,1 */
#if (defined IDSM_E_PARAM_INVALID)
#error IDSM_E_PARAM_INVALID already defined!
#endif /* #if( defined IDSM_E_PARAM_INVALID)*/
#define IDSM_E_PARAM_INVALID                                             0x0AU

/* API function called with a NULL pointer parameter. */
#if (defined IDSM_E_PARAM_POINTER)
#error IDSM_E_PARAM_POINTER already defined!
#endif /* #if( defined IDSM_E_PARAM_POINTER)*/
#define IDSM_E_PARAM_POINTER                                             0x0BU

/* API function called with an invalid data size parameter. */
#if (defined IDSM_E_PARAM_LENGTH)
#error IDSM_E_PARAM_LENGTH already defined!
#endif /* #if( defined IDSM_E_PARAM_LENGTH)*/
#define IDSM_E_PARAM_LENGTH                                              0x0CU

/* API function called before IdsM has been fully initialized. */
#if (defined IDSM_E_UNINIT)
#error IDSM_E_UNINIT already defined!
#endif /* #if( defined IDSM_E_UNINIT)*/
#define IDSM_E_UNINIT                                                    0x0DU

/* The service IdsM_Init is called while the module is already initialized. */
#if (defined IDSM_E_ALREADY_INITIALIZED)
#error IDSM_E_ALREADY_INITIALIZED already defined!
#endif /* #if( defined IDSM_E_ALREADY_INITIALIZED)*/
#define IDSM_E_ALREADY_INITIALIZED                                       0x0EU

/* DET error dummy API was called */
#if (defined IDSM_E_INVALID_CALL)
#error IDSM_E_INVALID_CALL already defined!
#endif /* #if (defined IDSM_E_INVALID_CALL)*/
#define IDSM_E_INVALID_CALL                                              0x13U



/* --- IdsM Internal Events ----------------------------------------------- */

/* Number of IdsM internal events */
#if (defined IDSM_NUMBER_OF_INTERNAL_EVENTS)
#error IDSM_NUMBER_OF_INTERNAL_EVENTS already defined!
#endif /* #if( defined IDSM_NUMBER_OF_INTERNAL_EVENTS)*/
#define IDSM_NUMBER_OF_INTERNAL_EVENTS                                      3U

/* Internal event empty status */
#if (defined IDSM_INTERNAL_EVENT_NOT_READY_TO_TRANSMIT)
#error IDSM_INTERNAL_EVENT_NOT_READY_TO_TRANSMIT already defined!
#endif /* #if( defined IDSM_INTERNAL_EVENT_NOT_READY_TO_TRANSMIT)*/
#define IDSM_INTERNAL_EVENT_NOT_READY_TO_TRANSMIT                           0U

/* Internal event ready to transmit status */
#if (defined IDSM_INTERNAL_EVENT_READY_TO_TRANSMIT)
#error IDSM_INTERNAL_EVENT_READY_TO_TRANSMIT already defined!
#endif /* #if( defined IDSM_INTERNAL_EVENT_READY_TO_TRANSMIT)*/
#define IDSM_INTERNAL_EVENT_READY_TO_TRANSMIT                               1U

/* IdsM internal event no event buffer available index in structure */
#if (defined IDSM_NO_EVENT_BUFFER_AVAILABLE_INDEX)
#error IDSM_NO_EVENT_BUFFER_AVAILABLE_INDEX already defined!
#endif /* #if( defined IDSM_NO_EVENT_BUFFER_AVAILABLE_INDEX)*/
#define IDSM_NO_EVENT_BUFFER_AVAILABLE_INDEX                                0U

/* IdsM internal event no context data buffer available index in structure */
#if (defined IDSM_NO_CONTEXT_DATA_BUFFER_AVAILABLE_INDEX)
#error IDSM_NO_CONTEXT_DATA_BUFFER_AVAILABLE_INDEX already defined!
#endif /* #if( defined IDSM_NO_CONTEXT_DATA_BUFFER_AVAILABLE_INDEX)*/
#define IDSM_NO_CONTEXT_DATA_BUFFER_AVAILABLE_INDEX                         1U

/* IdsM internal event traffic limitation exceeded index in structure */
#if (defined IDSM_TRAFFIC_LIMITATION_EXCEEDED_INDEX)
#error IDSM_TRAFFIC_LIMITATION_EXCEEDED_INDEX already defined!
#endif /* #if( defined IDSM_TRAFFIC_LIMITATION_EXCEEDED_INDEX)*/
#define IDSM_TRAFFIC_LIMITATION_EXCEEDED_INDEX                              2U

/* IdsM internal event start event definition id number */
#if (defined IDSM_INTERNAL_EVENTS_START_DEFINITION_ID)
#error IDSM_INTERNAL_EVENTS_START_DEFINITION_ID already defined!
#endif /* #if( defined IDSM_INTERNAL_EVENTS_START_DEFINITION_ID)*/
#define IDSM_INTERNAL_EVENTS_START_DEFINITION_ID                           46U

/* IdsM internal event no event buffer available event definition id */
/* !LINKSTO IdsM.ASR20-11.SWS_IdsM_00801,1 */
/* !LINKSTO IdsM.ASR20-11.SWS_IdsM_91015,1 */
#if (defined IDSM_NO_EVENT_BUFFER_AVAILABLE_EVENT_DEFINITION_ID)
#error IDSM_NO_EVENT_BUFFER_AVAILABLE_EVENT_DEFINITION_ID already defined!
#endif /* #if( defined IDSM_NO_EVENT_BUFFER_AVAILABLE_EVENT_DEFINITION_ID)*/
#define IDSM_NO_EVENT_BUFFER_AVAILABLE_EVENT_DEFINITION_ID                 46U

/* IdsM internal event no context data buffer available event definition id */
#if (defined IDSM_NO_CONTEXT_DATA_BUFFER_AVAILABLE_EVENT_DEFINITION_ID)
#error IDSM_NO_CONTEXT_DATA_BUFFER_AVAILABLE_EVENT_DEFINITION_ID already defined!
#endif /* #if( defined IDSM_NO_CONTEXT_DATA_BUFFER_AVAILABLE_EVENT_DEFINITION_ID)*/
#define IDSM_NO_CONTEXT_DATA_BUFFER_AVAILABLE_EVENT_DEFINITION_ID          47U

/* IdsM internal event traffic limitation exceeded event definition id */
#if (defined IDSM_TRAFFIC_LIMITATION_EXCEEDED_EVENT_DEFINITION_ID)
#error IDSM_TRAFFIC_LIMITATION_EXCEEDED_EVENT_DEFINITION_ID already defined!
#endif /* #if( defined IDSM_TRAFFIC_LIMITATION_EXCEEDED_EVENT_DEFINITION_ID)*/
#define IDSM_TRAFFIC_LIMITATION_EXCEEDED_EVENT_DEFINITION_ID               48U



/* --- Post build config and RAM access ----------------------------------- */

#if (defined IDSM_PBCFG_ACCESS)
#error IDSM_PB_CFG_ACCESS already defined!
#endif /* #if( defined IDSM_PB_CFG_ACCESS)*/
#define IDSM_PB_CFG_ACCESS(type, element) \
    (TS_UNCHECKEDGETCFG(IdsM_ConfigPtr, type, IDSM, IdsM_ConfigPtr->element))

#if (defined IDSM_PBRAM_REF_ID)
#error IDSM_PBRAM_REF_ID already defined!
#endif /* #if( defined IDSM_PBRAM_REF_ID)*/
#define IDSM_PBRAM_REF_ID(type, offset) \
    (TS_UNCHECKEDGETVAR(IdsM_GMemPtr, type, IDSM, offset))

#if (defined IDSM_PB_VAR_ACCESS)
#error IDSM_PB_VAR_ACCESS already defined!
#endif /* #if( defined IDSM_PB_VAR_ACCESS)*/
#define IDSM_PB_VAR_ACCESS(type, offset) \
    (IDSM_PBRAM_REF_ID(type, (IdsM_ConfigPtr->offset)))

#if (defined IDSM_GET_EVENT_CFG)
#error IDSM_GET_EVENT_CFG already defined!
#endif /* #if( defined IDSM_GET_EVENT_CFG)*/
#define IDSM_GET_EVENT_CFG(Index)   \
    (IDSM_PB_CFG_ACCESS(IdsM_EventCfgType, eventCfgPtr)[(Index)])

#if (defined IDSM_GET_REPORTING_MODE_CFG)
#error IDSM_GET_REPORTING_MODE_CFG already defined!
#endif /* #if( defined IDSM_GET_REPORTING_MODE_CFG)*/
#define IDSM_GET_REPORTING_MODE_CFG(Index)   \
    (IDSM_PB_CFG_ACCESS(uint8, reportingModePtr)[(Index)])

#if (defined IDSM_GET_BUFFER_BASE_CFG)
#error IDSM_GET_BUFFER_BASE_CFG already defined!
#endif /* #if( defined IDSM_GET_BUFFER_BASE_CFG)*/
#define IDSM_GET_BUFFER_BASE_CFG(Index)   \
    (IDSM_PB_CFG_ACCESS(uint16, bufferBasePtr)[(Index)])

#if (defined IDSM_GET_BUFFER_SEGMENT_CFG)
#error IDSM_GET_BUFFER_SEGMENT_CFG already defined!
#endif /* #if( defined IDSM_GET_BUFFER_SEGMENT_CFG)*/
#define IDSM_GET_BUFFER_SEGMENT_CFG(Index)   \
    (IDSM_PB_CFG_ACCESS(IdsM_BufferSegmentsType, bufferSegmentsPtr)[(Index)])

#if (defined IDSM_GET_FILTERCHAIN_CFG)
#error IDSM_GET_FILTERCHAIN_CFG already defined!
#endif /* #if( defined IDSM_GET_FILTERCHAIN_CFG)*/
#define IDSM_GET_FILTERCHAIN_CFG(Index)   \
    (IDSM_PB_CFG_ACCESS(IdsM_FilterChainCfgType, filterChainCfgPtr)[(Index)])

#if (defined IDSM_GET_BUFFER_META)
#error IDSM_GET_BUFFER_META already defined!
#endif /* #if( defined IDSM_GET_BUFFER_META)*/
#define IDSM_GET_BUFFER_META(Index)   \
    (IDSM_PB_VAR_ACCESS(IdsM_BufferMetaType, bufferMetaBase)[(Index)])

#if (defined IDSM_GET_EMPTY_LIST)
#error IDSM_GET_EMPTY_LIST already defined!
#endif /* #if( defined IDSM_GET_EMPTY_LIST)*/
#define IDSM_GET_EMPTY_LIST(Index)   \
    (IDSM_PB_VAR_ACCESS(IdsM_StateListType, emptyListBase)[(Index)])

#if (defined IDSM_GET_SAMPLING_COUNT)
#error IDSM_GET_SAMPLING_COUNT already defined!
#endif /* #if( defined IDSM_GET_SAMPLING_COUNT)*/
#define IDSM_GET_SAMPLING_COUNT(Index)   \
    (IDSM_PB_VAR_ACCESS(uint8, samplingCountBase)[(Index)])

#if (defined IDSM_GET_AGG_BUFFER_ID)
#error IDSM_GET_AGG_BUFFER_ID already defined!
#endif /* #if( defined IDSM_GET_AGG_BUFFER_ID)*/
#define IDSM_GET_AGG_BUFFER_ID(Index)   \
    (IDSM_PB_VAR_ACCESS(uint8, aggBufferIdBase)[(Index)])

#if (defined IDSM_GET_THRESHOLD_COUNT)
#error IDSM_GET_THRESHOLD_COUNT already defined!
#endif /* #if( defined IDSM_GET_THRESHOLD_COUNT)*/
#define IDSM_GET_THRESHOLD_COUNT(Index)   \
    (IDSM_PB_VAR_ACCESS(uint8, thresholdCountBase)[(Index)])

#if (defined IDSM_GET_BUFFER)
#error IDSM_GET_BUFFER already defined!
#endif /* #if( defined IDSM_GET_BUFFER)*/
#define IDSM_GET_BUFFER(Index)   \
    (IDSM_PBRAM_REF_ID(uint8, IDSM_GET_BUFFER_BASE_CFG(Index)))

/* ------- IdsM Instance Filter Macros ------- */
#if (defined IDSM_CHECK_EVENT_RATE_LIMITATION_ENABLED)
#error IDSM_CHECK_EVENT_RATE_LIMITATION_ENABLED already defined!
#endif /* #if( defined IDSM_CHECK_EVENT_RATE_LIMITATION_ENABLED)*/
#define IDSM_CHECK_EVENT_RATE_LIMITATION_ENABLED(maxEventsRate)   \
    ((maxEventsRate) > 0)

#if (defined IDSM_CHECK_TRAFFIC_RATE_LIMITATION_ENABLED)
#error IDSM_CHECK_TRAFFIC_RATE_LIMITATION_ENABLED already defined!
#endif /* #if( defined IDSM_CHECK_TRAFFIC_RATE_LIMITATION_ENABLED)*/
#define IDSM_CHECK_TRAFFIC_RATE_LIMITATION_ENABLED(maxTrafficBytes)   \
    ((maxTrafficBytes) > 0)

/*==================[type definitions]======================================*/

/** \brief IdsM Internal Event structure */
typedef struct
{
    VAR(uint16, TYPEDEF) Counter;   /* Internal event counter */
    #if (defined IDSM_HOST_ECU)
    VAR(uint8, TYPEDEF) Status;     /* Buffer ready or not ready for propagation */
    TS_DefMaxAlignedByteArray(BufferMaxAligned, IDSM, VAR_CLEARED, IDSM_MIN_MESSAGE_LENGTH);    /* Internal event buffer aligned for buffer access */
    P2VAR(uint8, AUTOMATIC, IDSM_APPL_DATA) Buffer;     /* Internal event buffer pointer */
    #endif /* IDSM_HOST_ECU */
} IdsM_InternalEventType;

/*==================[external function declarations]========================*/

#define IDSM_START_SEC_CODE
#include <IdsM_MemMap.h>

#if (defined IDSM_HOST_ECU)
extern FUNC(void, IDSM_CODE) IdsM_PrepareInternalEvent
(
    VAR(uint16, TYPEDEF) internalEventIdx
);
#endif /* IDSM_HOST_ECU */

/** \brief Push buffer index at the end of selected state list
 *
 * Add buffer index at the end of StateList in FIFO way
 *
 * \param[in] StateListPtr Pointer to state list to push the buffer into it.
 * \param[in] BufferIdx Buffer index to be added to the list.
 */
extern FUNC(void, IDSM_CODE) IdsM_PushToStateList
(
    P2VAR(IdsM_StateListType, AUTOMATIC, IDSM_APPL_DATA) StateListPtr,
    uint16 BufferIdx
);

/** \brief Pop buffer index at the start of selected state list
 *
 * Remove buffer index from the start of StateList in FIFO way,
 * and return the index.
 *
 * \param[in] StateListPtr Pointer to state list to pop the buffer from it.
 *
 * \return Buffer index, or IDSM_INVALID_INDEX if list is empty
 */
extern FUNC(uint16, IDSM_CODE) IdsM_PopFromStateList
(
    P2VAR(IdsM_StateListType, AUTOMATIC, IDSM_APPL_DATA) StateListPtr
);

/** \brief Remove Buffer index at any location of selected state list
 *
 * Remove buffer index from any location of StateList and make make pervious element point to the next element
 *
 * \param[in] StateListPtr Pointer to state list.
 * \param[in] BufferIdx Buffer index to be removed from the list.
 */
extern FUNC(void, IDSM_CODE) IdsM_RemoveFromStateList
(
    P2VAR(IdsM_StateListType, AUTOMATIC, IDSM_APPL_DATA) StateListPtr,
    uint16 BufferIdx
);

/** \brief Free buffer and return it to empty state
 *
 * Search for an empty buffer with suitable size and return its Id.
 * Suitable size is the same or nearest segment to the requested size,
 * If all buffers in the nearest segment are busy, search for empty buffer in bigger segments.
 *
 * \param[in] BufferIdx Buffer index to be freed.
 */
extern FUNC(void, IDSM_CODE) IdsM_FreeBuffer
(
    uint16 BufferIdx
);

/** \brief Add Buffer Idx at the end of NewSEv state list
 *
 * \param[in] BufferIdx Buffer index to be pushed.
 */
extern FUNC(void, IDSM_CODE) IdsM_PushToState_New
(
    uint16 BufferIdx
);

/** \brief Add Buffer Idx at the end of QSEv state list
 *
 * \param[in] BufferIdx Buffer index to be pushed.
 */
extern FUNC(void, IDSM_CODE) IdsM_PushToState_Qualified
(
    uint16 BufferIdx
);

/** \brief Get Buffer Idx from the start of NewSEv state list and remove it from the list
 *
 * \return Buffer index, or IDSM_INVALID_INDEX if list is empty
 */
extern FUNC(uint16, IDSM_CODE) IdsM_PopFromState_New
(
    void
);

/** \brief Get Buffer Idx from the start of QSEv state list and remove it from the list
 *
 * \return Buffer index, or IDSM_INVALID_INDEX if list is empty
 */
extern FUNC(uint16, IDSM_CODE) IdsM_PopFromState_Qualified
(
    void
);

#if (defined IDSM_HOST_ECU)
/** \brief Propagate the qualified security events to IdsR */
extern FUNC(void, IDSM_CODE) IdsM_PropagateQSEvs(void);
#endif /* IDSM_HOST_ECU */

#define IDSM_STOP_SEC_CODE
#include <IdsM_MemMap.h>

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[internal data]=========================================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

/* start data section declaration */
#define IDSM_START_SEC_VAR_INIT_8
#include <IdsM_MemMap.h>

/** \brief IdsM init state */
extern VAR( boolean, IDSM_APPL_DATA ) IdsM_IsInitialized;

/* stop data section declaration */
#define IDSM_STOP_SEC_VAR_INIT_8
#include <IdsM_MemMap.h>


/* start data section declaration */
#define IDSM_START_SEC_VAR_CLEARED_32
#include <IdsM_MemMap.h>

/** \brief IdsM MainFunction counter */
extern VAR( uint32, IDSM_APPL_DATA ) IdsM_MainFunctionCounter;

/* stop data section declaration */
#define IDSM_STOP_SEC_VAR_CLEARED_32
#include <IdsM_MemMap.h>


/* start data section declaration */
#define IDSM_START_SEC_VAR_CLEARED_16
#include <IdsM_MemMap.h>

/** \brief maximum allowed context data length
 **
 ** Maximum allowed context data length in IDS buffer.
 ** No event could be reported with bigger length.
 */
extern VAR( uint16, IDSM_APPL_DATA ) IdsM_MaxContextDataLength;

#if (defined IDSM_HOST_ECU)
/** \brief Total Number of Processed Events during the Filter Interval */
extern VAR(uint16, TYPEDEF) IdsM_ProcessedEvents;

/** \brief Total Number of Transmitted Bytes during the Filter Interval */
extern VAR(uint16, TYPEDEF) IdsM_TransmittedBytes;

#if(IDSM_UNRELIABLE_TX_CONF_TIMEOUT_ENABLED == STD_ON)
/** \brief Unreliable tx confirmation timeout counter */
extern VAR(uint16, TYPEDEF) IdsM_TxConfTimeoutCounter;
#endif /* IDSM_UNRELIABLE_TX_CONF_TIMEOUT_ENABLED == STD_ON */

#endif /* IDSM_HOST_ECU */

/* stop data section declaration */
#define IDSM_STOP_SEC_VAR_CLEARED_16
#include <IdsM_MemMap.h>

/* start data section declaration */
#define IDSM_START_SEC_VAR_CLEARED_8
#include <IdsM_MemMap.h>

#if (defined IDSM_HOST_ECU)
/** \brief Tx confirmation status flag */
extern VAR(boolean, TYPEDEF) IdsM_TxConfFlag;
#endif /* IDSM_HOST_ECU */

/* stop data section declaration */
#define IDSM_STOP_SEC_VAR_CLEARED_8
#include <IdsM_MemMap.h>

/* start data section declaration */
#define IDSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <IdsM_MemMap.h>

/** \brief IdsM configurations */
extern P2CONST( IdsM_ConfigType, AUTOMATIC, IDSM_APPL_CONST ) IdsM_ConfigPtr;

/** \brief IdsM events configurations */
extern P2CONST( IdsM_EventCfgType, AUTOMATIC, IDSM_APPL_CONST ) IdsM_EventsCfg;

/** \brief IdsM events reporting mode */
extern P2CONST( uint8, AUTOMATIC, IDSM_APPL_CONST ) IdsM_ReportingModesCfg;

/** \brief IdsM internal buffers Base */
extern P2CONST( uint16, AUTOMATIC, IDSM_APPL_CONST ) IdsM_BuffersBaseCfg;

/** \brief IdsM buffer segments
 **
 ** ContextData size virtually divides buffer array to segments where each
 ** segment will have buffers with same context data length.
 */
extern P2CONST( IdsM_BufferSegmentsType, AUTOMATIC, IDSM_APPL_CONST ) IdsM_BufferSegmentsCfg;

/** \brief IdsM filter chain configurations */
extern P2CONST( IdsM_FilterChainCfgType, AUTOMATIC, IDSM_APPL_CONST ) IdsM_FilterChainsCfg;

/** \brief IdsM buffers Meta Data */
extern P2VAR( IdsM_BufferMetaType, AUTOMATIC, IDSM_APPL_DATA ) IdsM_BuffersMeta;

/** \brief Array of empty state list */
extern P2VAR( IdsM_StateListType, AUTOMATIC, IDSM_APPL_DATA ) IdsM_EmptyLists;

/** \brief Array of sampling count
 **
 ** Array that contains count parameter for events with Sampling filter.
 */
extern P2VAR( uint16, AUTOMATIC, IDSM_APPL_DATA ) IdsM_SamplingCounters;

/** \brief Array of aggregation buffer Ids
 **
 ** Array that contains buffer id of last event reported with aggregation
 ** filter configured.
 */
extern P2VAR( uint16, AUTOMATIC, IDSM_APPL_DATA ) IdsM_AggBufferIds;

/** \brief Array of threshold count
 **
 ** Array that contains count parameter for events with Threshold filter.
 */
extern P2VAR( uint16, AUTOMATIC, IDSM_APPL_DATA ) IdsM_ThresholdCounters;

/** \brief New security event state list
 **
 ** List that contains buffer ids for buffers in New state.
 */
extern VAR( IdsM_StateListType, IDSM_APPL_DATA ) IdsM_NewSEvList;

/** \brief Aggregation state list
 **
 ** List that contains buffer ids for buffers in Aggergation state.
 */
extern VAR( IdsM_StateListType, IDSM_APPL_DATA ) IdsM_AggList;

/** \brief Qualified security event state list
 **
 ** List that contains buffer ids for buffers in Qualified state.
 */
extern VAR( IdsM_StateListType, IDSM_APPL_DATA ) IdsM_QSEvList;

/** \brief Internal events stuctures */
/* !LINKSTO IdsM.ASR20-11.SWS_IdsM_00802,1 */
extern VAR( IdsM_InternalEventType, IDSM_APPL_DATA ) IdsM_InternalEvents[IDSM_NUMBER_OF_INTERNAL_EVENTS];

/* stop data section declaration */
#define IDSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <IdsM_MemMap.h>


/* start data section declaration */
#define IDSM_START_SEC_CONST_UNSPECIFIED
#include <IdsM_MemMap.h>

#if (IDSM_TIMESTAMP_SUPPORT == STD_ON)
/** Pointer to statically allocated RAM */
extern CONSTP2VAR(uint8, IDSM_CONST, IDSM_VAR_CLEARED) IdsM_LocalTimestampPtr;
#endif /* IDSM_TIMESTAMP_SUPPORT == STD_ON */

/* stop data section declaration */
#define IDSM_STOP_SEC_CONST_UNSPECIFIED
#include <IdsM_MemMap.h>

/*==================[internal function declarations]========================*/
/*==================[internal function definitions]=========================*/

#undef TS_RELOCATABLE_CFG_ENABLE

#endif /* ifndef IDSM_INT_H */
/*==================[end of file]===========================================*/
