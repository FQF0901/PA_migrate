#ifndef IDSM_VERSION_H
#define IDSM_VERSION_H
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

/*==================[inclusions]=============================================*/

/*==================[macros]=================================================*/

/*------------------[AUTOSAR vendor identification]-------------------------*/

#if (defined IDSM_VENDOR_ID)
#error IDSM_VENDOR_ID is already defined
#endif
/** \brief AUTOSAR vendor identification: Elektrobit Automotive GmbH */
#define IDSM_VENDOR_ID         1U

/*------------------[AUTOSAR module identification]-------------------------*/

#if (defined IDSM_MODULE_ID)
#error IDSM_MODULE_ID already defined
#endif
/** \brief AUTOSAR module identification */
#define IDSM_MODULE_ID         108U

/*------------------[AUTOSAR release version identification]----------------*/

#if (defined IDSM_AR_RELEASE_MAJOR_VERSION)
#error IDSM_AR_RELEASE_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR release major version */
#define IDSM_AR_RELEASE_MAJOR_VERSION     4U

#if (defined IDSM_AR_RELEASE_MINOR_VERSION)
#error IDSM_AR_RELEASE_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR release minor version */
#define IDSM_AR_RELEASE_MINOR_VERSION     6U

#if (defined IDSM_AR_RELEASE_REVISION_VERSION)
#error IDSM_AR_RELEASE_REVISION_VERSION already defined
#endif
/** \brief AUTOSAR release revision version */
#define IDSM_AR_RELEASE_REVISION_VERSION  0U

/*------------------[AUTOSAR module version identification]------------------*/

#if (defined IDSM_SW_MAJOR_VERSION)
#error IDSM_SW_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR module major version */
#define IDSM_SW_MAJOR_VERSION             1U

#if (defined IDSM_SW_MINOR_VERSION)
#error IDSM_SW_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR module minor version */
#define IDSM_SW_MINOR_VERSION             0U

#if (defined IDSM_SW_PATCH_VERSION)
#error IDSM_SW_PATCH_VERSION already defined
#endif
/** \brief AUTOSAR module patch version */
#define IDSM_SW_PATCH_VERSION             0U

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* ifndef IDSM_VERSION_H */
/*==================[end of file]============================================*/
