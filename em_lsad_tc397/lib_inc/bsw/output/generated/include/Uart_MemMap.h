/**
 * \file
 *
 * \brief AUTOSAR MemMap
 *
 * This file contains the implementation of the AUTOSAR
 * module MemMap.
 *
 * \version 1.3.11
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]=============================================*/

#define MEMMAP_ERROR_UART

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Uart */

#if (defined UART_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_UART
    #error Tried to open section UART_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef UART_START_SEC_CODE
    #undef MEMMAP_ERROR_UART
  #endif
#elif (defined UART_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef UART_STOP_SEC_CODE
    #undef MEMMAP_ERROR_UART
  #else
    #undef MEMMAP_ERROR_UART
    #error Tried to close section UART_STOP_SEC_CODE without prior opening UART_START_SEC_CODE.
  #endif

#elif (defined UART_START_SEC_CODE_ASIL_B_LOCAL)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_UART
    #error Tried to open section UART_START_SEC_CODE_ASIL_B_LOCAL within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_B_LOCAL
    #undef UART_START_SEC_CODE_ASIL_B_LOCAL
    #undef MEMMAP_ERROR_UART
  #endif
#elif (defined UART_STOP_SEC_CODE_ASIL_B_LOCAL)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_B_LOCAL)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_B_LOCAL
    #undef UART_STOP_SEC_CODE_ASIL_B_LOCAL
    #undef MEMMAP_ERROR_UART
  #else
    #undef MEMMAP_ERROR_UART
    #error Tried to close section UART_STOP_SEC_CODE_ASIL_B_LOCAL without prior opening UART_START_SEC_CODE_ASIL_B_LOCAL.
  #endif

#elif (defined UART_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_UART
    #error Tried to open section UART_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
    #undef UART_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
    #undef MEMMAP_ERROR_UART
  #endif
#elif (defined UART_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
    #undef UART_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
    #undef MEMMAP_ERROR_UART
  #else
    #undef MEMMAP_ERROR_UART
    #error Tried to close section UART_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED without prior opening UART_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED.
  #endif

#elif (defined UART_START_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_UART
    #error Tried to open section UART_START_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
    #undef UART_START_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
    #undef MEMMAP_ERROR_UART
  #endif
#elif (defined UART_STOP_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
    #undef UART_STOP_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
    #undef MEMMAP_ERROR_UART
  #else
    #undef MEMMAP_ERROR_UART
    #error Tried to close section UART_STOP_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED without prior opening UART_START_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED.
  #endif

#elif (defined UART_START_SEC_CONST_ASIL_B_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_UART
    #error Tried to open section UART_START_SEC_CONST_ASIL_B_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_B_16
    #undef UART_START_SEC_CONST_ASIL_B_16
    #undef MEMMAP_ERROR_UART
  #endif
#elif (defined UART_STOP_SEC_CONST_ASIL_B_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_B_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_B_16
    #undef UART_STOP_SEC_CONST_ASIL_B_16
    #undef MEMMAP_ERROR_UART
  #else
    #undef MEMMAP_ERROR_UART
    #error Tried to close section UART_STOP_SEC_CONST_ASIL_B_16 without prior opening UART_START_SEC_CONST_ASIL_B_16.
  #endif

#elif (defined UART_START_SEC_CONST_ASIL_B_LOCAL_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_UART
    #error Tried to open section UART_START_SEC_CONST_ASIL_B_LOCAL_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_B_LOCAL_32
    #undef UART_START_SEC_CONST_ASIL_B_LOCAL_32
    #undef MEMMAP_ERROR_UART
  #endif
#elif (defined UART_STOP_SEC_CONST_ASIL_B_LOCAL_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_B_LOCAL_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_B_LOCAL_32
    #undef UART_STOP_SEC_CONST_ASIL_B_LOCAL_32
    #undef MEMMAP_ERROR_UART
  #else
    #undef MEMMAP_ERROR_UART
    #error Tried to close section UART_STOP_SEC_CONST_ASIL_B_LOCAL_32 without prior opening UART_START_SEC_CONST_ASIL_B_LOCAL_32.
  #endif

#elif (defined UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_UART
    #error Tried to open section UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_LOCAL_32
    #undef UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
    #undef MEMMAP_ERROR_UART
  #endif
#elif (defined UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_LOCAL_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_LOCAL_32
    #undef UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
    #undef MEMMAP_ERROR_UART
  #else
    #undef MEMMAP_ERROR_UART
    #error Tried to close section UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32 without prior opening UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32.
  #endif

#elif (defined UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_UART
    #error Tried to open section UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_LOCAL_8
    #undef UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
    #undef MEMMAP_ERROR_UART
  #endif
#elif (defined UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_LOCAL_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_LOCAL_8
    #undef UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
    #undef MEMMAP_ERROR_UART
  #else
    #undef MEMMAP_ERROR_UART
    #error Tried to close section UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8 without prior opening UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8.
  #endif

#elif (defined UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_UART
    #error Tried to open section UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
    #undef UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
    #undef MEMMAP_ERROR_UART
  #endif
#elif (defined UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
    #undef UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
    #undef MEMMAP_ERROR_UART
  #else
    #undef MEMMAP_ERROR_UART
    #error Tried to close section UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED without prior opening UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_UART) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_UART) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_UART
  #error MEMMAP_ERROR_UART the included memory section was not defined within the BSW-IMPLEMENTATION of Uart.
#endif
