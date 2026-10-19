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

#define MEMMAP_ERROR_CDD_PRINT

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Cdd_Print */

#if (defined Cdd_Print_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CDD_PRINT
    #error Tried to open section Cdd_Print_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef Cdd_Print_START_SEC_CODE
    #undef MEMMAP_ERROR_CDD_PRINT
  #endif
#elif (defined Cdd_Print_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef Cdd_Print_STOP_SEC_CODE
    #undef MEMMAP_ERROR_CDD_PRINT
  #else
    #undef MEMMAP_ERROR_CDD_PRINT
    #error Tried to close section Cdd_Print_STOP_SEC_CODE without prior opening Cdd_Print_START_SEC_CODE.
  #endif

#endif

#ifdef MEMMAP_ERROR_CDD_PRINT
  #undef MEMMAP_ERROR_CDD_PRINT
  #error MEMMAP_ERROR_CDD_PRINT the included memory section was not defined within the SWC-IMPLEMENTATION of Cdd_Print.
#endif
