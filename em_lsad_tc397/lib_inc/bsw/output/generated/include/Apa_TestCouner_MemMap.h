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

#define MEMMAP_ERROR_APA_TESTCOUNER

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Apa_TestCouner */

#if (defined Apa_TestCouner_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_APA_TESTCOUNER
    #error Tried to open section Apa_TestCouner_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef Apa_TestCouner_START_SEC_CODE
    #undef MEMMAP_ERROR_APA_TESTCOUNER
  #endif
#elif (defined Apa_TestCouner_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef Apa_TestCouner_STOP_SEC_CODE
    #undef MEMMAP_ERROR_APA_TESTCOUNER
  #else
    #undef MEMMAP_ERROR_APA_TESTCOUNER
    #error Tried to close section Apa_TestCouner_STOP_SEC_CODE without prior opening Apa_TestCouner_START_SEC_CODE.
  #endif

#endif

#ifdef MEMMAP_ERROR_APA_TESTCOUNER
  #undef MEMMAP_ERROR_APA_TESTCOUNER
  #error MEMMAP_ERROR_APA_TESTCOUNER the included memory section was not defined within the SWC-IMPLEMENTATION of Apa_TestCouner.
#endif
