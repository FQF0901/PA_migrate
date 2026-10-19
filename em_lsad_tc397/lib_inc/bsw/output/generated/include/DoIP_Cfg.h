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

#ifndef DOIP_CFG_H
#define DOIP_CFG_H


/*==================[includes]==============================================*/

#include <Std_Types.h> /* AUTOSAR standard types */


/*==================[macros]================================================*/

/* When timer is set to 0, the closest we can get is the next MainFunction tick. */



#if (defined DOIP_DEV_ERROR_DETECT)
#error DOIP_DEV_ERROR_DETECT is already defined
#endif
/** \brief Pre-processor switch for enabling development error detection. */
#define DOIP_DEV_ERROR_DETECT STD_ON

#if (defined DOIP_ENABLE_MAIN_FUNCTION_TX)
#error DOIP_ENABLE_MAIN_FUNCTION_TX is already defined
#endif

/** \brief Pre-processor switch for enabling calling the tx part of the main function separately. */
#define DOIP_ENABLE_MAIN_FUNCTION_TX STD_OFF

#if (defined DOIP_VERSION_INFO_API)
#error DOIP_VERSION_INFO_API is already defined
#endif
/** \brief Pre-processor switch for enabling version info API support. */
#define DOIP_VERSION_INFO_API STD_ON

#if (defined DOIP_MAX_PAYLOADSIZE)
#error DOIP_MAX_PAYLOADSIZE is already defined
#endif
/** \brief Maximum allowed diagnostic payload size. */
#define DOIP_MAX_PAYLOADSIZE ((uint32)10U)

#if (defined DOIP_MAX_NUMBYTE_DIAGACKNACK)
#error DOIP_MAX_NUMBYTE_DIAGACKNACK is already defined
#endif
/** \brief Maximum number of bytes of the original Diagnostic message that will be copied into the ACK/NACK response message. */
#define DOIP_MAX_NUMBYTE_DIAGACKNACK 128U

#if (defined DOIP_VIN_INVALIDITY_PATTERN)
#error DOIP_VIN_INVALIDITY_PATTERN is already defined
#endif
/** \brief Vehicle identification number invalidity pattern. */
#define DOIP_VIN_INVALIDITY_PATTERN 0U

#if (defined DOIP_VIN_STATUS_ENABLE)
#error DOIP_VIN_STATUS_ENABLE is already defined
#endif
/** \brief Pre-processor switch for enabling vehicle identification number status. */
#define DOIP_VIN_STATUS_ENABLE STD_ON

#if (defined DOIP_DHCP_VIN_USE_ENABLE)
#error DOIP_DHCP_VIN_USE_ENABLE is already defined
#endif
/** \brief Pre-processor switch for enabling the use of VIN for DHCP host naming. */
#define DOIP_DHCP_VIN_USE_ENABLE STD_OFF

#if (defined DOIP_USER_GET_VIN)
#error DOIP_USER_GET_VIN is already defined
#endif
/** \brief Pre-processor switch for enabling user defined callback function to retrieve VIN. */
#define DOIP_USER_GET_VIN STD_OFF

#if (defined DOIP_USER_VID_REQ_RECEIVED_CALLBACK)
#error DOIP_USER_VID_REQ_RECEIVED_CALLBACK is already defined
#endif
/** \brief Pre-processor switch for enabling user defined callback function to indicate a received VID request. */
#define DOIP_USER_VID_REQ_RECEIVED_CALLBACK STD_OFF

#if (defined DOIP_POWER_MODE)
#error DOIP_POWER_MODE is already defined
#endif
/** \brief Pre-processor switch for enabling service port/user callback function to retrieve Power Mode. */
#define DOIP_POWER_MODE STD_OFF

#if (defined DOIP_RTE_USED)
#error DOIP_RTE_USED is already defined.
#endif
/** \brief Pre-processor switch for enabling access to Rte. */
#define DOIP_RTE_USED STD_OFF

#if (defined DOIP_VEHICLE_ANN_REPETITION)
#error DOIP_VEHICLE_ANN_REPETITION is already defined
#endif
/** \brief Number of repetitons of the vehicle announcements. */
#define DOIP_VEHICLE_ANN_REPETITION 3U

#if (defined DOIP_VEHICLE_ANN_TIMEOUT)
#error DOIP_VEHICLE_ANN_TIMEOUT is already defined
#endif
/** \brief Timeout until next vehicle announcements shall be sent. */
#define DOIP_VEHICLE_ANN_TIMEOUT 50U

#if (defined DOIP_VEHICLE_ANN_RESP_MAX_INIT_TIMEOUT)
#error DOIP_VEHICLE_ANN_RESP_MAX_INIT_TIMEOUT is already defined
#endif
/** \brief Maximum timeout for initial vehicle announcement and vehicle identification response. */
#define DOIP_VEHICLE_ANN_RESP_MAX_INIT_TIMEOUT 500U

#if (defined DOIP_MAX_PARALLEL_TESTER)
#error DOIP_MAX_PARALLEL_TESTER is already defined
#endif
/** \brief Maximum number of parallel active tester (TCP connections). */
#define DOIP_MAX_PARALLEL_TESTER 1U

/** \brief Maximum number of UDP socket connections. */
#define DOIP_MAX_UDP_SOCKET_CONNECTIONS 2U

#if (defined DOIP_MAX_CHANNELS)
#error DOIP_MAX_CHANNELS is already defined
#endif
/** \brief Maximum number configured channels. */
#define DOIP_MAX_CHANNELS 1U

#if (defined DOIP_TCP_INITIAL_INACTIVITY_TIMEOUT)
#error DOIP_TCP_INITIAL_INACTIVITY_TIMEOUT is already defined
#endif
/** \brief Initial timeout of a TCP connection waiting for a routing activation request. */
#define DOIP_TCP_INITIAL_INACTIVITY_TIMEOUT 100000U

#if (defined DOIP_TCP_GENERAL_INACTIVITY_TIMEOUT)
#error DOIP_TCP_GENERAL_INACTIVITY_TIMEOUT is already defined
#endif
/** \brief General timeout of a TCP connection waiting for a routing activation request. */
#define DOIP_TCP_GENERAL_INACTIVITY_TIMEOUT 500000U

#if (defined DOIP_DIAG_ENT_STATUS_MAXBYTE_USE)
#error DOIP_DIAG_ENT_STATUS_MAXBYTE_USE is already defined
#endif
/** \brief Pre-processor switch for using the Max data size element of a diagnostic entity status response. */
#define DOIP_DIAG_ENT_STATUS_MAXBYTE_USE STD_OFF

#if (defined DOIP_NODE_TYPE)
#error DOIP_NODE_TYPE is already defined
#endif
/** \brief Switch for DoIPNodeType DOIP_GATEWAY or DOIP_NODE */
#define DOIP_NODE_TYPE   DOIP_NODE

#if (defined DOIP_RESPONSE_BEFORE_ROUTACT)
#error DOIP_RESPONSE_BEFORE_ROUTACT is already defined
#endif
/** \brief Switch for DoIPResponseBeforeRoutingActivation DOIP_DISABLE_DIAG_NACK_0x06 or DOIP_ENABLE_ALL_DIAG_NACK */
#define DOIP_RESPONSE_BEFORE_ROUTACT   DOIP_ENABLE_ALL_DIAG_NACK

#if (defined DOIP_PL_LENGTH_ENTITY_STATUS_RESP)
#error DOIP_PL_LENGTH_ENTITY_STATUS_RESP is already defined
#endif
/** \brief  Pre-processor switch to determine the size of Diagnostic entity status response message */
#define DOIP_PL_LENGTH_ENTITY_STATUS_RESP   3U

#if (defined DOIP_CUSTOM_PAYLOAD_TYPE_ENABLED)
#error DOIP_CUSTOM_PAYLOAD_TYPE_ENABLED is already defined
#endif
/** \brief Pre-processor switch for enabling custom payload type diagnostic messages. */
#define DOIP_CUSTOM_PAYLOAD_TYPE_ENABLED STD_OFF

#if (defined DOIP_GETANDRESETMEASUREMENTDATA_API)
#error DOIP_GETANDRESETMEASUREMENTDATA_API is already defined
#endif
/** \brief Pre-processor switch for enabling Get and Reset measurement data API. */
#define DOIP_GETANDRESETMEASUREMENTDATA_API STD_OFF

#if (defined DOIP_USER_TCP_SOCON_MODECHG_CALLBACK)
#error DOIP_USER_TCP_SOCON_MODECHG_CALLBACK is already defined
#endif
/** \brief Pre-processor switch for enabling user defined callback function to provide information about the TCP connection status. */
#define DOIP_USER_TCP_SOCON_MODECHG_CALLBACK STD_OFF

#if (defined DOIP_TCP_CONN_BUFF_SIZE)
#error DOIP_TCP_CONN_BUFF_SIZE is already defined
#endif
/** \brief Tcp connection buffer size used for segmented header reception and storing a part of diagnostic message payload used for NACK. */
#define DOIP_TCP_CONN_BUFF_SIZE (128U)

#define DOIP_MAX_STANDARD_CHANNELS (DOIP_MAX_CHANNELS - DOIP_MAX_CUSTOM_CHANNELS)

#if (defined DOIP_MAX_VEHICLE_ANNOUNCEMENT_CON)
#error DOIP_MAX_VEHICLE_ANNOUNCEMENT_CON is already defined
#endif
/** \brief Maximum number of Udp announcement connections. */
#define DOIP_MAX_VEHICLE_ANNOUNCEMENT_CON 1U

#if (defined DOIP_PDULENGTHTYPE_MAX)
#error DOIP_PDULENGTHTYPE_MAX is already defined
#endif
/** \brief Maximum DoIP message payload size */
#define DOIP_PDULENGTHTYPE_MAX 0xFFFFU

#if (defined DOIP_ALIVE_CHECK_RESPONSE_TIMEOUT)
#error DOIP_ALIVE_CHECK_RESPONSE_TIMEOUT is already defined
#endif
/** \brief Timeout for waiting for a response to an Alive check request. */
#define DOIP_ALIVE_CHECK_RESPONSE_TIMEOUT 50U

#if (defined DOIP_USE_MAC_ADDR_ENABLE)
#error DOIP_USE_MAC_ADDR_ENABLE is already defined
#endif
/** \brief Pre-processor switch for enabling the use of MAC Address instead of EID for Vehicle Identification/Announcement. */
#define DOIP_USE_MAC_ADDR_ENABLE STD_ON

#if (defined DOIP_USE_EID_AS_GID_ENABLED)
#error DOIP_USE_EID_AS_GID_ENABLED is already defined
#endif

/** \brief Pre-processor switch for enabling setting GID to EID. */
#define DOIP_USE_EID_AS_GID_ENABLED STD_OFF

#if (defined DOIP_DYN_GID_SYNC_ENABLED)
#error DOIP_DYN_GID_SYNC_ENABLED is already defined
#endif
/** \brief Pre-processor switch for enabling Dynamic GID synchronization. */
#define DOIP_DYN_GID_SYNC_ENABLED STD_OFF

/** \brief Compile time verification value */
#if (defined DOIP_CFG_SIGNATURE)
#error DOIP_CFG_SIGNATURE already defined!
#endif
#define DOIP_CFG_SIGNATURE  3951308641U

/** \brief Compile time Published information verification value */
#if (defined DOIP_PUBLIC_INFO_SIGNATURE)
#error DOIP_PUBLIC_INFO_SIGNATURE already defined!
#endif
#define DOIP_PUBLIC_INFO_SIGNATURE  778901256U

/** \brief Pre-processor switch indicates if PbcfgM uses DoIP */
#if (defined DOIP_PBCFGM_SUPPORT_ENABLED)
#error DOIP_PBCFGM_SUPPORT_ENABLED already defined!
#endif
#define DOIP_PBCFGM_SUPPORT_ENABLED  STD_OFF

/** \brief Pre-processor switch to enable/disable relocatable postbuild config
 */
#if (defined DOIP_RELOCATABLE_CFG_ENABLE)
#error DOIP_RELOCATABLE_CFG_ENABLE is already defined
#endif
#define DOIP_RELOCATABLE_CFG_ENABLE STD_ON

/** \brief Pre-processor switch indicating that DoIP_IsValidConfig function shall be mapped to memory section DOIP_CODE_CC_BLOCK
*/
#if (defined DOIP_ISVALIDCONFIG_MMAP_ENABLED)
#error DOIP_ISVALIDCONFIG_MMAP_ENABLED already defined!
#endif
#define DOIP_ISVALIDCONFIG_MMAP_ENABLED STD_OFF

#if (defined DOIP_HOSTNAME_SIZE_MAX)
#error DOIP_HOSTNAME_SIZE_MAX is already defined
#endif
/** \brief Maximum size of DHCP HostName. */
#define DOIP_HOSTNAME_SIZE_MAX 50U

#if (defined DOIP_DHCP_HOSTNAME_PREFIX)
#error DOIP_DHCP_HOSTNAME_PREFIX is already defined
#endif
/** \brief DHCP HostName string. */
#define DOIP_DHCP_HOSTNAME_PREFIX ""
#if (defined DOIP_DHCP_HOSTNAME_PREFIX_SIZE)
#error DOIP_DHCP_HOSTNAME_PREFIX_SIZE is already defined
#endif
/** \brief Length of DHCP HostName string. */
#define DOIP_DHCP_HOSTNAME_PREFIX_SIZE 0U

/** \brief Number of configured routing activation user callback functions. */
#if (defined DOIP_ROUTING_ACTIVATION_CALLBACK_NUM)
#error DOIP_ROUTING_ACTIVATION_CALLBACK_NUM is already defined
#endif
#define DOIP_ROUTING_ACTIVATION_CALLBACK_NUM 0U

#if (defined DOIP_ENABLE_TCP_CLOSURE_FIN)
#error DOIP_ENABLE_TCP_CLOSURE_FIN is already defined
#endif
/** \brief Pre-processor switch for enabling Tcp connection closure with FIN when NACK is transmitted along with connection closure. */
#define DOIP_ENABLE_TCP_CLOSURE_FIN STD_OFF


#if (defined DOIP_LOCAL_IP_ADDRESS_RELEASE_DELAY)
#error DOIP_LOCAL_IP_ADDRESS_RELEASE_DELAY is already defined
#endif
/** \brief Time to wait in [s] after DoIP_ActivationLineSwitchInactive() is called before the local IP address assignment is released. */

#define DOIP_LOCAL_IP_ADDRESS_RELEASE_DELAY 1U

#if (defined DOIP_ENABLE_TCP_CLOSE_API)
#error DOIP_ENABLE_TCP_CLOSE_API is already defined.
#endif
/** \brief Pre-processor switch for enabling APIs for closing Tcp connection. */
#define DOIP_ENABLE_TCP_CLOSE_API STD_ON

/*------------------[Defensive programming]---------------------------------*/

#if (defined DOIP_DEFENSIVE_PROGRAMMING_ENABLED)
#error DOIP_DEFENSIVE_PROGRAMMING_ENABLED is already defined
#endif
/** \brief Defensive programming usage
 **
 ** En- or disables the usage of the defensive programming */
#define DOIP_DEFENSIVE_PROGRAMMING_ENABLED   STD_OFF

#if (defined DOIP_PRECONDITION_ASSERT_ENABLED)
#error DOIP_PRECONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Precondition assertion usage
 **
 ** En- or disables the usage of precondition assertion checks */
#define DOIP_PRECONDITION_ASSERT_ENABLED     STD_OFF

#if (defined DOIP_POSTCONDITION_ASSERT_ENABLED)
#error DOIP_POSTCONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Postcondition assertion usage
 **
 ** En- or disables the usage of postcondition assertion checks */
#define DOIP_POSTCONDITION_ASSERT_ENABLED    STD_OFF

#if (defined DOIP_UNREACHABLE_CODE_ASSERT_ENABLED)
#error DOIP_UNREACHABLE_CODE_ASSERT_ENABLED is already defined
#endif
/** \brief Unreachable code assertion usage
 **
 ** En- or disables the usage of unreachable code assertion checks */
#define DOIP_UNREACHABLE_CODE_ASSERT_ENABLED STD_OFF

#if (defined DOIP_INVARIANT_ASSERT_ENABLED)
#error DOIP_INVARIANT_ASSERT_ENABLED is already defined
#endif
/** \brief Invariant assertion usage
 **
 ** En- or disables the usage of invariant assertion checks */
#define DOIP_INVARIANT_ASSERT_ENABLED        STD_OFF

#if (defined DOIP_STATIC_ASSERT_ENABLED)
#error DOIP_STATIC_ASSERT_ENABLED is already defined
#endif
/** \brief Static assertion usage
 **
 ** En- or disables the usage of static assertion checks */
#define DOIP_STATIC_ASSERT_ENABLED           STD_OFF


/*------------------------[Defensive programming]----------------------------*/

#if (defined DOIP_PRECONDITION_ASSERT)
#error DOIP_PRECONDITION_ASSERT is already defined
#endif

#if (defined DOIP_PRECONDITION_ASSERT_NO_EVAL)
#error DOIP_PRECONDITION_ASSERT_NO_EVAL is already defined
#endif

#if (DOIP_PRECONDITION_ASSERT_ENABLED == STD_ON)
/** \brief Report an assertion violation to Det
 **
 ** \param[in] Condition Condition which is violated
 ** \param[in] ApiId Service ID of the API function */
#define DOIP_PRECONDITION_ASSERT(Condition, ApiId) \
  DET_PRECONDITION_ASSERT((Condition), DOIP_MODULE_ID, DOIP_INSTANCE_ID, (ApiId))

/** \brief Report an assertion violation to Det
 **
 ** \param[in] Condition Condition which is violated
 ** \param[in] ApiId Service ID of the API function */
#define DOIP_PRECONDITION_ASSERT_NO_EVAL(Condition, ApiId) \
  DET_PRECONDITION_ASSERT_NO_EVAL((Condition), DOIP_MODULE_ID, DOIP_INSTANCE_ID, (ApiId))
#else
#define DOIP_PRECONDITION_ASSERT(Condition, ApiId)
#define DOIP_PRECONDITION_ASSERT_NO_EVAL(Condition, ApiId)
#endif

#if (defined DOIP_POSTCONDITION_ASSERT)
#error DOIP_POSTCONDITION_ASSERT is already defined
#endif

#if (defined DOIP_POSTCONDITION_ASSERT_NO_EVAL)
#error DOIP_POSTCONDITION_ASSERT_NO_EVAL is already defined
#endif

#if (DOIP_POSTCONDITION_ASSERT_ENABLED == STD_ON)
/** \brief Report an assertion violation to Det
 **
 ** \param[in] Condition Condition which is violated
 ** \param[in] ApiId Service ID of the API function */
#define DOIP_POSTCONDITION_ASSERT(Condition, ApiId) \
  DET_POSTCONDITION_ASSERT((Condition), DOIP_MODULE_ID, DOIP_INSTANCE_ID, (ApiId))

/** \brief Report an assertion violation to Det
 **
 ** \param[in] Condition Condition which is violated
 ** \param[in] ApiId Service ID of the API function */
#define DOIP_POSTCONDITION_ASSERT_NO_EVAL(Condition, ApiId) \
  DET_POSTCONDITION_ASSERT_NO_EVAL((Condition), DOIP_MODULE_ID, DOIP_INSTANCE_ID, (ApiId))
#else
#define DOIP_POSTCONDITION_ASSERT(Condition, ApiId)
#define DOIP_POSTCONDITION_ASSERT_NO_EVAL(Condition, ApiId)
#endif

#if (defined DOIP_INVARIANT_ASSERT)
#error DOIP_INVARIANT_ASSERT is already defined
#endif

#if (defined DOIP_INVARIANT_ASSERT_NO_EVAL)
#error DOIP_INVARIANT_ASSERT_NO_EVAL is already defined
#endif

#if (DOIP_INVARIANT_ASSERT_ENABLED == STD_ON)
/** \brief Report an assertion violation to Det
 **
 ** \param[in] Condition Condition which is violated
 ** \param[in] ApiId Service ID of the API function */
#define DOIP_INVARIANT_ASSERT(Condition, ApiId) \
  DET_INVARIANT_ASSERT((Condition), DOIP_MODULE_ID, DOIP_INSTANCE_ID, (ApiId))

/** \brief Report an assertion violation to Det
 **
 ** \param[in] Condition Condition which is violated
 ** \param[in] ApiId Service ID of the API function */
#define DOIP_INVARIANT_ASSERT_NO_EVAL(Condition, ApiId) \
  DET_INVARIANT_ASSERT_NO_EVAL((Condition), DOIP_MODULE_ID, DOIP_INSTANCE_ID, (ApiId))
#else
#define DOIP_INVARIANT_ASSERT(Condition, ApiId)
#define DOIP_INVARIANT_ASSERT_NO_EVAL(Condition, ApiId)
#endif

#if (defined DOIP_STATIC_ASSERT)
# error DOIP_STATIC_ASSERT is already defined
#endif
#if (DOIP_STATIC_ASSERT_ENABLED == STD_ON)
/** \brief Report an static assertion violation to Det
 **
 ** \param[in] Condition Condition which is violated */
# define DOIP_STATIC_ASSERT(expr) DET_STATIC_ASSERT(expr)
#else
# define DOIP_STATIC_ASSERT(expr)
#endif

#if (defined DOIP_UNREACHABLE_CODE_ASSERT)
#error DOIP_UNREACHABLE_CODE_ASSERT is already defined
#endif
#if (DOIP_UNREACHABLE_CODE_ASSERT_ENABLED == STD_ON)
/** \brief Report an unreachable code assertion violation to Det
 **
 ** \param[in] ApiId Service ID of the API function */
#define DOIP_UNREACHABLE_CODE_ASSERT(ApiId) \
  DET_UNREACHABLE_CODE_ASSERT(DOIP_MODULE_ID, DOIP_INSTANCE_ID, (ApiId))
#else
#define DOIP_UNREACHABLE_CODE_ASSERT(ApiId)
#endif

#if (defined DOIP_INTERNAL_API_ID)
#error DOIP_INTERNAL_API_ID is already defined
#endif
/** \brief API ID of module internal functions to be used in assertions */
#define DOIP_INTERNAL_API_ID DET_INTERNAL_API_ID

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* DOIP_CFG_H */
/*==================[end of file]===========================================*/
