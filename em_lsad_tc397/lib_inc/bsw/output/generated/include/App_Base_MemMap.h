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

#define MEMMAP_ERROR_APP_BASE

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for App_Base */

#if (defined App_Base_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_APP_BASE
    #error Tried to open section App_Base_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef App_Base_START_SEC_CODE
    #undef MEMMAP_ERROR_APP_BASE
  #endif
#elif (defined App_Base_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef App_Base_STOP_SEC_CODE
    #undef MEMMAP_ERROR_APP_BASE
  #else
    #undef MEMMAP_ERROR_APP_BASE
    #error Tried to close section App_Base_STOP_SEC_CODE without prior opening App_Base_START_SEC_CODE.
  #endif

#endif

#ifdef MEMMAP_ERROR_APP_BASE
  #undef MEMMAP_ERROR_APP_BASE
  #error MEMMAP_ERROR_APP_BASE the included memory section was not defined within the SWC-IMPLEMENTATION of App_Base.
#endif
