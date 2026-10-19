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

#define MEMMAP_ERROR_APA_TESTCOUNER_C2

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Apa_TestCouner_C2 */

#if (defined Apa_TestCouner_C2_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_APA_TESTCOUNER_C2
    #error Tried to open section Apa_TestCouner_C2_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef Apa_TestCouner_C2_START_SEC_CODE
    #undef MEMMAP_ERROR_APA_TESTCOUNER_C2
  #endif
#elif (defined Apa_TestCouner_C2_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef Apa_TestCouner_C2_STOP_SEC_CODE
    #undef MEMMAP_ERROR_APA_TESTCOUNER_C2
  #else
    #undef MEMMAP_ERROR_APA_TESTCOUNER_C2
    #error Tried to close section Apa_TestCouner_C2_STOP_SEC_CODE without prior opening Apa_TestCouner_C2_START_SEC_CODE.
  #endif

#endif

#ifdef MEMMAP_ERROR_APA_TESTCOUNER_C2
  #undef MEMMAP_ERROR_APA_TESTCOUNER_C2
  #error MEMMAP_ERROR_APA_TESTCOUNER_C2 the included memory section was not defined within the SWC-IMPLEMENTATION of Apa_TestCouner_C2.
#endif
