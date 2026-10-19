/**
 * \file
 *
 * \brief AUTOSAR SoAd
 *
 * This file contains the implementation of the AUTOSAR
 * module SoAd.
 *
 * \version 1.8.19
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef SOAD_PBRAMCFG_H
#define SOAD_PBRAMCFG_H

/*==================[includes]==============================================*/

/*==================[macros]================================================*/

#if (defined SOAD_DATA_MEM_SIZE) /* To prevent double definition */
#error SOAD_DATA_MEM_SIZE already defined!
#endif /* (defined SOAD_DATA_MEM_SIZE) */

/**
 * Size of internal SoAd data in units of bytes (static memory
 * allocation) - Memory required by post-build config must at most equal
 * to this constant
 */
#define SOAD_DATA_MEM_SIZE 2574U


/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
#endif /* ifndef SOAD_PBRAMCFG_H  */
/*==================[end of file]===========================================*/
