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

#ifndef IDSM_TYPES_H
#define IDSM_TYPES_H

/*==================[inclusions]============================================*/

#include <Std_Types.h>        /* AUTOSAR standard types */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/** \brief Type definition of local IdsM Security Event IDs */
/* !LINKSTO IdsM.ASR20-11.SWS_IdsM_91031,1 */
typedef uint16 IdsM_SecurityEventIdType;

/** \brief Type definition of IdsM timestamps */
/* !LINKSTO IdsM.ASR20-11.SWS_IdsM_91014,1 */
typedef uint64 IdsM_TimestampType;

/* !LINKSTO IdsM.ASR20-11.SWS_IdsM_01013,1 */
/* !LINKSTO IdsM.ASR20-11.SWS_IdsM_91013,1 */
/** \brief Notification status type
 **
 ** This type defines the values that the "read Rx/Tx notification status"
 ** API functions return if they are activated via configuration.
 */
typedef enum
{
  IDSM_REPORTING_MODE_OFF = 0U,       /* Event is not reported */
  IDSM_REPORTING_MODE_BRIEF,          /* Event is reported withoutcontext data */
  IDSM_REPORTING_MODE_DETAILED,       /* Event is reportedincluding context data */
  IDSM_REPORTING_MODE_BRIEF_BYPASSING_FILTERS,     /* Event is reported unfiltered without context data */
  IDSM_REPORTING_MODE_DETAILED_BYPASSING_FILTERS,  /* Event is reported unfiltered including context data */
  IDSM_REPORTING_MODE_INVALID = 0xFF  /* Invalid reporting mode */
} IdsM_Filters_ReportingModeType;

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[internal data]=========================================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef IDSM_TYPES_H */
/*==================[end of file]===========================================*/
