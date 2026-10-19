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

#ifndef IDSM_H
#define IDSM_H

/*  MISRA-C:2012 Deviation List
 *
 *  MISRA-1) Deviated Rule: 20.5 (advisory)
 *   #undef shall not be used.
 *
 *   Reason:
 *   Macro IDSM_NO_PBCFG_REQUIRED and IDSM_NO_CFG_REQUIRED may be defined in
 *   more than one instance which will cause compile
 *   warning.
 */

/*==================[inclusions]============================================*/

#include <IdsM_Cfg.h>         /* IdsM pre-compile-time configuration */
#include <IdsM_CfgTypes.h>    /* IdsM pre-compile-time dependent configuration types */
#include <IdsM_Types.h>       /* IdsM general types */
#include <IdsM_Version.h>     /* IdsM version declaration */

/* Exclude post-build-time config include file if requested to do so */
#if (!defined IDSM_NO_PBCFG_REQUIRED) && (!defined IDSM_NO_CFG_REQUIRED)
#if (IDSM_PBCFGM_SUPPORT_ENABLED == STD_OFF)
#include <IdsM_PBcfg.h>
#endif /* IDSM_PBCFGM_SUPPORT_ENABLED == STD_OFF */
#endif /* IDSM_NO_PBCFG_REQUIRED */
/* Deviation MISRA-1 */
#undef IDSM_NO_PBCFG_REQUIRED
/* Deviation MISRA-1 */
#undef IDSM_NO_CFG_REQUIRED

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/** \brief Initializes the IdsM module
 *
 * This service initializes the IdsM module.
 * It initializes all variables and sets the module state to initialized.
 *
 * \param[in] ConfigPtr Address of the post-build time configuration data of the IdsM module.
 *
 * \ServiceID{0x00}
 * \Reentrancy{Non-Reentrant}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, IDSM_CODE) IdsM_Init
(
  P2CONST(IdsM_ConfigType, AUTOMATIC, IDSM_APPL_CONST) ConfigPtr
);

 /** \brief Checks the compatibility of the post-build configuration.
  **
  ** This service checks the compatibility of the post-build configuration
  ** against the source code.
  **
  ** \param[in] CfgPtr Pointer to the configuration data of the IdsM module.
  **
  ** \Reentrancy{Reentrant}
  ** \Synchronicity{Synchronous}
  */
extern FUNC(Std_ReturnType, IDSM_CODE) IdsM_IsValidConfig
(
    P2CONST(void, AUTOMATIC, IDSM_APPL_CONST) CfgPtr
);

#if (IDSM_VERSION_INFO_API == STD_ON)
/** \brief Get version information of the IdsM module.
 *
 * This service returns the version information of this module. The version
 * information includes:
 *  - Module ID
 *  - Vendor ID
 *  - Vendor-specific version numbers
 *
 * \param[out] versioninfo Pointer to where to store the version
 * information of this module.
 *
 * \ServiceID{0x01}
 * \Reentrancy{Reentrant}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, IDSM_CODE) IdsM_GetVersionInfo
(
  P2VAR(Std_VersionInfoType, AUTOMATIC, IDSM_APPL_DATA) versioninfo
);
#endif /* IDSM_VERSION_INFO_API == STD_ON */

#ifndef RTE_SCHM_SWCBSW_IDSM_MAINFUNCTION
#define RTE_SCHM_SWCBSW_IDSM_MAINFUNCTION
/** \brief IdsM module main function.
 *
 * This function is called periodically.
 * It processes security events asynchronously which are queued during API function calls.
 *
 * \ServiceID{0x02}
 * \Reentrancy{Non-Reentrant}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, IDSM_CODE) IdsM_MainFunction(void);
#endif /* RTE_SCHM_SWCBSW_IDSM_MAINFUNCTION */

/** \brief IdsM set security event.
 *
 * This API is the application interface to report security events to the IdsM.
 *
 * \param[in] securityEventId Security Event ID
 *
 * \ServiceID{0x03}
 * \Reentrancy{Reentrant}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, IDSM_CODE) IdsM_SetSecurityEvent
(
  VAR(IdsM_SecurityEventIdType, TYPEDEF) securityEventId
);

/** \brief IdsM set security event with context data.
 *
 * This API is the application interface to report security events with
 * context data to the IdsM.
 *
 * \param[in] securityEventId Security Event ID
 * \param[in] contextData Pointer to optional context data. Use NULL_PTR if no context data is available.
 * \param[in] contextDataSize Size of context data
 *
 * \ServiceID{0x04}
 * \Reentrancy{Reentrant}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, IDSM_CODE) IdsM_SetSecurityEventWithContextData
(
  VAR(IdsM_SecurityEventIdType, TYPEDEF) securityEventId,
  P2CONST(uint8, AUTOMATIC, IDSM_APPL_CONST) contextData,
  VAR(uint16, TYPEDEF) contextDataSize
);

/** \brief IdsM set security event with count.
 *
 * This API is the application interface for Smart Sensors to report
 * security events with a count value to the IdsM.
 *
 * \param[in] securityEventId Security Event ID
 * \param[in] count Count value which is used as the start value for the security event
 *
 * \ServiceID{0x05}
 * \Reentrancy{Reentrant}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, IDSM_CODE) IdsM_SetSecurityEventWithCount
(
  VAR(IdsM_SecurityEventIdType, TYPEDEF) securityEventId,
  VAR(uint16, TYPEDEF) count
);

/** \brief IdsM set security event with count and context data.
 *
 * This API is the application interface for Smart Sensors to report
 * security events with a count value and context data to the IdsM.
 *
 * \param[in] securityEventId Security Event ID
 * \param[in] count Count value which is used as the start value for the security event
 * \param[in] contextData Pointer to optional context data. Use NULL_PTR if no context data is available.
 * \param[in] contextDataSize Size of context data
 *
 * \ServiceID{0x06}
 * \Reentrancy{Reentrant}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, IDSM_CODE) IdsM_SetSecurityEventWithCountContextData
(
  VAR(IdsM_SecurityEventIdType, TYPEDEF) securityEventId,
  VAR(uint16, TYPEDEF) count,
  P2CONST(uint8, AUTOMATIC, IDSM_APPL_CONST) contextData,
  VAR(uint16, TYPEDEF) contextDataSize
);

/** \brief IdsM set security event with timestamp and count.
 *
 * This API is the application interface for Smart Sensors to report
 * security events with a timestamp and a count value to the IdsM.
 *
 * \param[in] securityEventId Security Event ID
 * \param[in] timestamp Timestamp used for time reference of the security event.
 * \param[in] count Count value which is used as the start value for the security event
 *
 * \ServiceID{0x07}
 * \Reentrancy{Reentrant}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, IDSM_CODE) IdsM_SetSecurityEventWithTimestampCount
(
  VAR(IdsM_SecurityEventIdType, TYPEDEF) securityEventId,
  VAR(IdsM_TimestampType, TYPEDEF) timestamp,
  VAR(uint16, TYPEDEF) count
);

/** \brief IdsM set security event with timestamp, count, and context data.
 *
 * This API is the application interface for Smart Sensors to report
 * security events with a timestamp, a count value and context data to the IdsM.
 *
 * \param[in] securityEventId Security Event ID
 * \param[in] timestamp Timestamp used for time reference of the security event.
 * \param[in] count Count value which is used as the start value for the security event
 * \param[in] contextData Pointer to optional context data. Use NULL_PTR if no context data is available.
 * \param[in] contextDataSize Size of context data
 *
 * \ServiceID{0x08}
 * \Reentrancy{Reentrant}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, IDSM_CODE) IdsM_SetSecurityEventWithTimestampCountContextData
(
  VAR(IdsM_SecurityEventIdType, TYPEDEF) securityEventId,
  VAR(IdsM_TimestampType, TYPEDEF) timestamp,
  VAR(uint16, TYPEDEF) count,
  P2CONST(uint8, AUTOMATIC, IDSM_APPL_CONST) contextData,
  VAR(uint16, TYPEDEF) contextDataSize
);

#if (IDSM_SUPPORT_EXTERNAL_PROXY == STD_ON)

/** \brief IdsM set external security event with timestamp and count.
 *
 * This API is the application interface for external devices to report
 * qualified security events with a timestamp and a count value to the IdsM.
 *
 * \param[in] sensorInstanceId Sensor Instance ID
 * \param[in] eventDefinitionId Event Definition ID
 * \param[in] timestamp Timestamp used for time reference of the security event.
 * \param[in] count Count value which is used as the start value for the security event
 *
 * \ServiceID{0x61}
 * \Reentrancy{Reentrant}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, IDSM_CODE) IdsM_SetExtSecurityEventWithTimestampCount
(
  VAR(uint8, TYPEDEF) sensorInstanceId,
  VAR(uint16, TYPEDEF) eventDefinitionId,
  VAR(IdsM_TimestampType, TYPEDEF) timestamp,
  VAR(uint16, TYPEDEF) count
);

/** \brief IdsM set external security event with timestamp, count, and context data.
 *
 * This API is the application interface for external device to report
 * qualified security events with a timestamp, count, and context data to the IdsM.
 *
 * \param[in] sensorInstanceId Sensor Instance ID
 * \param[in] eventDefinitionId Event Definition ID
 * \param[in] timestamp Timestamp used for time reference of the security event.
 * \param[in] count Count value which is used as the start value for the security event
 * \param[in] contextDataSize Size of context data
 * \param[in] contextData Pointer to optional context data. Use NULL_PTR if no context data is available.
 *
 * \ServiceID{0x62}
 * \Reentrancy{Reentrant}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, IDSM_CODE) IdsM_SetExtSecurityEventWithTimestampCountContextData
(
  VAR(uint8, TYPEDEF) sensorInstanceId,
  VAR(uint16, TYPEDEF) eventDefinitionId,
  VAR(IdsM_TimestampType, TYPEDEF) timestamp,
  VAR(uint16, TYPEDEF) count,
  VAR(uint16, TYPEDEF) contextDataSize,
  P2CONST(uint8, AUTOMATIC, IDSM_APPL_CONST) contextData
);

#endif /* (IDSM_SUPPORT_EXTERNAL_PROXY == STD_ON) */

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[internal data]=========================================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef IDSM_H */
/*==================[end of file]===========================================*/
