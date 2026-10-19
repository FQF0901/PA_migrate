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

#ifndef IDSM_TRACE_H
#define IDSM_TRACE_H
/*==================[inclusions]============================================*/

#include <Std_Types.h>

/* Check if BASE_DBG_ENABLE is defined and set to STD_ON.
 * If so, include Base_Dbg.h which includes a custom header file */
#if (defined BASE_DBG_ENABLE)
#if (BASE_DBG_ENABLE == STD_ON)

#include <Base_Dbg.h>

#endif
#endif
#include <IdsM_Trace_Internal.h>

/*==================[macros]================================================*/

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_GETVERSIONINFO_ENTRY
/** \brief Entry point of function IdsM_GetVersionInfo()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_GETVERSIONINFO_ENTRY(versioninfo)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_GETVERSIONINFO_EXIT
/** \brief Exit point of function IdsM_GetVersionInfo()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_GETVERSIONINFO_EXIT(versioninfo)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_INIT_ENTRY
/** \brief Entry point of function IdsM_Init()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_INIT_ENTRY(ConfigPtr)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_INIT_EXIT
/** \brief Exit point of function IdsM_Init()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_INIT_EXIT(ConfigPtr)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_ISVALIDCONFIG_ENTRY
/** \brief Entry point of function IdsM_IsValidConfig()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_ISVALIDCONFIG_ENTRY(CfgPtr)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_ISVALIDCONFIG_EXIT
/** \brief Exit point of function IdsM_IsValidConfig()
 **
 ** The first parameter of the macro is the return
 ** value of the function, followed by the arguments
 ** of the function.
 */
#define DBG_IDSM_ISVALIDCONFIG_EXIT(Retval,CfgPtr)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_MAINFUNCTION_ENTRY
/** \brief Entry point of function IdsM_MainFunction()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_MAINFUNCTION_ENTRY()
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_MAINFUNCTION_EXIT
/** \brief Exit point of function IdsM_MainFunction()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_MAINFUNCTION_EXIT()
#endif
/** \brief Exclude section from doxygen
 ** @endcond */


/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_SETSECURITYEVENT_ENTRY
/** \brief Entry point of function IdsM_SetSecurityEvent()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_SETSECURITYEVENT_ENTRY(securityEventId)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_SETSECURITYEVENT_EXIT
/** \brief Exit point of function IdsM_SetSecurityEvent()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_SETSECURITYEVENT_EXIT(securityEventId)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_SETSECURITYEVENTWITHCONTEXTDATA_ENTRY
/** \brief Entry point of function IdsM_SetSecurityEventWithContextData()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_SETSECURITYEVENTWITHCONTEXTDATA_ENTRY(securityEventId,contextData,contextDataSize)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_SETSECURITYEVENTWITHCONTEXTDATA_EXIT
/** \brief Exit point of function IdsM_SetSecurityEventWithContextData()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_SETSECURITYEVENTWITHCONTEXTDATA_EXIT(securityEventId,contextData,contextDataSize)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_SETSECURITYEVENTWITHCOUNT_ENTRY
/** \brief Entry point of function IdsM_SetSecurityEventWithCount()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_SETSECURITYEVENTWITHCOUNT_ENTRY(securityEventId,count)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_SETSECURITYEVENTWITHCOUNT_EXIT
/** \brief Exit point of function IdsM_SetSecurityEventWithCount()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_SETSECURITYEVENTWITHCOUNT_EXIT(securityEventId,count)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_SETSECURITYEVENTWITHCOUNTCONTEXTDATA_ENTRY
/** \brief Entry point of function IdsM_SetSecurityEventWithCountContextData()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_SETSECURITYEVENTWITHCOUNTCONTEXTDATA_ENTRY(securityEventId,count,contextData,contextDataSize)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_SETSECURITYEVENTWITHCOUNTCONTEXTDATA_EXIT
/** \brief Exit point of function IdsM_SetSecurityEventWithCountContextData()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_SETSECURITYEVENTWITHCOUNTCONTEXTDATA_EXIT(securityEventId,count,contextData,contextDataSize)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_SETSECURITYEVENTWITHTIMESTAMPCOUNT_ENTRY
/** \brief Entry point of function IdsM_SetSecurityEventWithTimestampCount()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_SETSECURITYEVENTWITHTIMESTAMPCOUNT_ENTRY(securityEventId,timestamp,count)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_SETSECURITYEVENTWITHTIMESTAMPCOUNT_EXIT
/** \brief Exit point of function IdsM_SetSecurityEventWithTimestampCount()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_SETSECURITYEVENTWITHTIMESTAMPCOUNT_EXIT(securityEventId,timestamp,count)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_SETSECURITYEVENTWITHTIMESTAMPCOUNTCONTEXTDATA_ENTRY
/** \brief Entry point of function IdsM_SetSecurityEventWithTimestampCountContextData()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_SETSECURITYEVENTWITHTIMESTAMPCOUNTCONTEXTDATA_ENTRY(securityEventId,timestamp,count,contextData,contextDataSize)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_SETSECURITYEVENTWITHTIMESTAMPCOUNTCONTEXTDATA_EXIT
/** \brief Exit point of function IdsM_SetSecurityEventWithTimestampCountContextData()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_SETSECURITYEVENTWITHTIMESTAMPCOUNTCONTEXTDATA_EXIT(securityEventId,timestamp,count,contextData,contextDataSize)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_SETEXTSECURITYEVENTWITHTIMESTAMPCOUNT_ENTRY
/** \brief Entry point of function IdsM_SetExtSecurityEventWithTimestampCount()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_SETEXTSECURITYEVENTWITHTIMESTAMPCOUNT_ENTRY(sensorInstanceId,eventDefinitionId,timestamp,count)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_SETEXTSECURITYEVENTWITHTIMESTAMPCOUNT_EXIT
/** \brief Exit point of function IdsM_SetExtSecurityEventWithTimestampCount()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_SETEXTSECURITYEVENTWITHTIMESTAMPCOUNT_EXIT(sensorInstanceId,eventDefinitionId,timestamp,count)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_SETEXTSECURITYEVENTWITHTIMESTAMPCOUNTCONTEXTDATA_ENTRY
/** \brief Entry point of function IdsM_SetExtSecurityEventWithTimestampCountContextData()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_SETEXTSECURITYEVENTWITHTIMESTAMPCOUNTCONTEXTDATA_ENTRY(sensorInstanceId,eventDefinitionId,timestamp,count,contextDataSize,contextData)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_SETEXTSECURITYEVENTWITHTIMESTAMPCOUNTCONTEXTDATA_EXIT
/** \brief Exit point of function IdsM_SetExtSecurityEventWithTimestampCountContextData()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_SETEXTSECURITYEVENTWITHTIMESTAMPCOUNTCONTEXTDATA_EXIT(sensorInstanceId,eventDefinitionId,timestamp,count,contextDataSize,contextData)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */


/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_TXCONFIRMATION_ENTRY
/** \brief Entry point of function IdsM_TxConfirmation()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_TXCONFIRMATION_ENTRY(txPduId,result)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_TXCONFIRMATION_EXIT
/** \brief Exit point of function IdsM_TxConfirmation()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_TXCONFIRMATION_EXIT(txPduId,result)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_PDURIFRXINDICATION_ENTRY
/** \brief Entry point of function IdsM_PduRIfRxIndication()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_PDURIFRXINDICATION_ENTRY(rxPduId,pduInfoPtr)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_IDSM_PDURIFRXINDICATION_EXIT
/** \brief Exit point of function IdsM_PduRIfRxIndication()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_IDSM_PDURIFRXINDICATION_EXIT(rxPduId,pduInfoPtr)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */


/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef IDSM_TRACE_H */
/*==================[end of file]===========================================*/
