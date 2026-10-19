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

#ifndef IDSM_PROXY_H
#define IDSM_PROXY_H

/*==================[inclusions]============================================*/

#include <TSAutosar.h>        /* EB specific global AUTOSAR macros */
#include <IdsM_Types.h>       /* IdsM general types */

/*==================[macros]================================================*/

/** \brief External event id */
#if (defined IDSM_EXTERNAL_INDEX)
#error IDSM_EXTERNAL_INDEX already defined!
#endif
#define IDSM_EXTERNAL_INDEX                 0xFFFFU

/** \brief Macro for new event type */
#if (defined IDSM_NEW_EVENT)
#error IDSM_NEW_EVENT already defined!
#endif
#define IDSM_NEW_EVENT                      0x00U

/** \brief Macro for external qualified event type */
#if (defined IDSM_EXTERNAL_QUALIFIED_EVENT)
#error IDSM_EXTERNAL_QUALIFIED_EVENT already defined!
#endif
#define IDSM_EXTERNAL_QUALIFIED_EVENT       0x01U

/** \brief Invalid timestamp */
#if (defined IDSM_INVALID_TIMESTAMP)
#error IDSM_INVALID_TIMESTAMP already defined!
#endif
#define IDSM_INVALID_TIMESTAMP              0x00U

/** \brief Invalid sensor instance id */
#if (defined IDSM_INVALID_SENSOR_ID)
#error IDSM_INVALID_SENSOR_ID already defined!
#endif
#define IDSM_INVALID_SENSOR_ID              0xFFU


/* --- IdsM filter chain bits --------------------------------------------- */

/** \brief Block state filter flag bit in filter flags */
#if (defined IDSM_BLOCK_STATE_FLAG_BIT)
#error IDSM_BLOCK_STATE_FLAG_BIT already defined!
#endif
#define IDSM_BLOCK_STATE_FLAG_BIT           0U

/** \brief Sampling filter flag bit in filter flags */
#if (defined IDSM_SAMPLING_FLAG_BIT)
#error IDSM_SAMPLING_FLAG_BIT already defined!
#endif
#define IDSM_SAMPLING_FLAG_BIT              1U

/** \brief Aggregation filter flag bit in filter flags */
#if (defined IDSM_AGGREGATION_FLAG_BIT)
#error IDSM_AGGREGATION_FLAG_BIT already defined!
#endif
#define IDSM_AGGREGATION_FLAG_BIT           2U

/** \brief Threshold filter flag bit in filter flags */
#if (defined IDSM_THRESHOLD_FLAG_BIT)
#error IDSM_THRESHOLD_FLAG_BIT already defined!
#endif
#define IDSM_THRESHOLD_FLAG_BIT             3U

/** \brief Aggregation filter selector flag bit in filter flags for using first or last context data */
#if (defined IDSM_AGGREGATION_SELECTOR_FLAG_BIT)
#error IDSM_AGGREGATION_SELECTOR_FLAG_BIT already defined!
#endif
#define IDSM_AGGREGATION_SELECTOR_FLAG_BIT  7U

/** \brief Aggregation filter selector use first value */
#if (defined IDSM_AGGREGATION_SELECTOR_USE_FIRST)
#error IDSM_AGGREGATION_SELECTOR_USE_FIRST already defined!
#endif
#define IDSM_AGGREGATION_SELECTOR_USE_FIRST 0U

/** \brief Aggregation filter selector use last value */
#if (defined IDSM_AGGREGATION_SELECTOR_USE_LAST)
#error IDSM_AGGREGATION_SELECTOR_USE_LAST already defined!
#endif
#define IDSM_AGGREGATION_SELECTOR_USE_LAST  1U

/** \brief Check if filter is enabled in filter chain */
#if (defined IDSM_IS_FILTER_ENABLED)
#error IDSM_IS_FILTER_ENABLED already defined!
#endif
#define IDSM_IS_FILTER_ENABLED(filterIdx, flagBit) \
    (IDSM_CHECK_BIT(IdsM_FilterChainsCfg[filterIdx].filterFlags, flagBit))

/** \brief Return aggregation selector flag */
#if (defined IDSM_FILTER_AGGREGATION_SELECTOR)
#error IDSM_FILTER_AGGREGATION_SELECTOR already defined!
#endif
#define IDSM_FILTER_AGGREGATION_SELECTOR(filterIdx) \
    (IDSM_CHECK_BIT(IdsM_FilterChainsCfg[filterIdx].filterFlags, IDSM_AGGREGATION_SELECTOR_FLAG_BIT))



/* --- IdsM filter chain status ------------------------------------------- */

/** \brief Filter state pass */
#if (defined IDSM_FILTER_STATE_PASS)
#error IDSM_FILTER_STATE_PASS already defined!
#endif
#define IDSM_FILTER_STATE_PASS              0U

/** \brief Filter state drop */
#if (defined IDSM_FILTER_STATE_DROP)
#error IDSM_FILTER_STATE_DROP already defined!
#endif
#define IDSM_FILTER_STATE_DROP              1U

/** \brief Filter state in aggregation filter */
#if (defined IDSM_FILTER_STATE_AGGREGATION)
#error IDSM_FILTER_STATE_AGGREGATION already defined!
#endif
#define IDSM_FILTER_STATE_AGGREGATION       2U



/* --- IdsM Sink bits ----------------------------------------------------- */

/** \brief IdsM sink IdsR bit number */
#if (defined IDSM_SINK_IDSR_BIT)
#error IDSM_SINK_IDSR_BIT already defined!
#endif
#define IDSM_SINK_IDSR_BIT                  0U

/** \brief IdsM sink IdsR bit number */
#if (defined IDSM_SINK_DEM_BIT)
#error IDSM_SINK_DEM_BIT already defined!
#endif
#define IDSM_SINK_DEM_BIT                   1U


/** \brief Action taken for events after passing filter chain
 *
 * When target is ECU, Remaining buffer data is saved in buffer and buffer is transitioned to state qualified.
 * When target is External Device, buffer is transmitted to ECU.
 */
#if (defined IDSM_CALL_POST_FILTRATION)
#error IDSM_CALL_POST_FILTRATION already defined!
#endif
#if (defined IDSM_HOST_ECU)
#define IDSM_CALL_POST_FILTRATION(BufferIdx) \
    (IdsM_TransitionToQualified(BufferIdx))
#else /* IDSM_HOST_EXTERNAL_DEVICE */
#define IDSM_CALL_POST_FILTRATION(BufferIdx) \
    (IdsM_SendToECU(BufferIdx))
#endif /* IDSM_HOST */


/*==================[type definitions]======================================*/

/** \brief IdsM Internal data for reported events */
typedef struct
{
    #if (IDSM_TIMESTAMP_SUPPORT == STD_ON)
    VAR(IdsM_TimestampType, TYPEDEF) Timestamp; /* Timestamp used for time reference of the security event */
    #endif /* IDSM_TIMESTAMP_SUPPORT == STD_ON */
    P2CONST(uint8, AUTOMATIC, IDSM_APPL_CONST) ContextDataPtr; /* Pointer to optional context data. Use NULL_PTR if no context data is available */
    VAR(uint16, TYPEDEF) BufferIdx; /* Buffer Id after finding an empty buffer */
    VAR(IdsM_SecurityEventIdType, TYPEDEF) SecurityEventId; /* Security Event ID or IDSM_EXTERNAL_QUALIFIED_EVENT for external events */
    VAR(uint16, TYPEDEF) Count; /* Count value which is used as the start value for the security event */
    VAR(uint16, TYPEDEF) ContextDataSize; /* Size of context data or 0 if no context data reported */
    #if (IDSM_SUPPORT_EXTERNAL_PROXY == STD_ON)
    VAR(uint16, TYPEDEF) EventDefinitionId; /* Event definition id for external events */
    VAR(uint8, TYPEDEF) SensorInstanceId; /* Sensor Instance ID for external events */
    #endif /* (IDSM_SUPPORT_EXTERNAL_PROXY == STD_ON) */
    VAR(uint8, TYPEDEF) EventType; /* Event Type either IDSM_NEW_EVENT or IDSM_EXTERNAL_QUALIFIED_EVENT */
    VAR(uint8, TYPEDEF) ApiSid; /* Sid for IdsM_SetSecurityEventXXX APIs */
} IdsM_ReportedEventType;

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[internal data]=========================================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef IDSM_PROXY_H */
/*==================[end of file]===========================================*/
