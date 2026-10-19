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

#define MEMMAP_ERROR_GPTP

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Gptp */

#if (defined Gptp_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_GPTP
    #error Tried to open section Gptp_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef Gptp_START_SEC_CODE
    #undef MEMMAP_ERROR_GPTP
  #endif
#elif (defined Gptp_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef Gptp_STOP_SEC_CODE
    #undef MEMMAP_ERROR_GPTP
  #else
    #undef MEMMAP_ERROR_GPTP
    #error Tried to close section Gptp_STOP_SEC_CODE without prior opening Gptp_START_SEC_CODE.
  #endif

#endif

#ifdef MEMMAP_ERROR_GPTP
  #undef MEMMAP_ERROR_GPTP
  #error MEMMAP_ERROR_GPTP the included memory section was not defined within the SWC-IMPLEMENTATION of Gptp.
#endif
