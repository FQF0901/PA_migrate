#ifndef BSWM_ETHSM_H
#define BSWM_ETHSM_H

/**
 * \file
 *
 * \brief AUTOSAR BswM
 *
 * This file contains the implementation of the AUTOSAR
 * module BswM.
 *
 * \version 1.15.8
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

 /* \addtogroup Mode Management Stack
  * @{ */

/* !description Definition of the BswM_EthSM.h for the EthSM. */

/*==================[includes]===============================================*/

#include <EthSM_Types.h>       /* EthSM API                 */

/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

#define BSWM_START_SEC_CODE
#include <BswM_MemMap.h>

/** \brief Indicates current state (Called by EthSM).
 **
 ** This function is called by EthSM to indicate its current state.
 **
 ** Precondition: None
 **
 ** \param[in]    Network      - The Ethernet channel that the indicated state
 **                              corresponds to.
 **               CurrentState - The current state of the Ethernet channel.
 ** \param[inout] None.
 ** \param[out]   None.
 **
 ** \ServiceID{0x0D}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous} */

extern FUNC(void, BSWM_CODE) BswM_EthSM_CurrentState
(
NetworkHandleType Network,
EthSM_NetworkModeStateType CurrentState
);

#define BSWM_STOP_SEC_CODE
#include <BswM_MemMap.h>

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

/** @} doxygen end group definition */
#endif /* ifndef BSWM_ETHSM_H */
/*==================[end of file]============================================*/

/*==================[end of file]============================================*/
