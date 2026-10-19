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
#ifndef IDSM_TRACE_INTERNAL_H
#define IDSM_TRACE_INTERNAL_H
/*==================[inclusions]============================================*/

/*==================[macros]================================================*/
/* Place internal debug instrumentation macros in this file, i.e. all
   macros that are not generated for the public api instrumentation.
*/

#ifndef DBG_IDSM_PEEK_BUFFER
/** \brief Debug Peek IdsM buffer contents */
#define DBG_IDSM_PEEK_BUFFER(BufferPtr)
#endif

#ifndef DBG_IDSM_PEEK_BUFFER_IDX
/** \brief Debug Peek IdsM buffer contents based on buffer index */
#define DBG_IDSM_PEEK_BUFFER_IDX(BufferIdx)
#endif

#ifndef DBG_IDSM_INIT_BUFFERS
/** \brief Debug init pointers to all IdsM buffers */
#define DBG_IDSM_INIT_BUFFERS()
#endif

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef IDSM_TRACE_INTERNAL_H */
/*==================[end of file]===========================================*/
