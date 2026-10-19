#ifndef ETS_TRIGGERANDEVENTS_H
#define ETS_TRIGGERANDEVENTS_H
/**
 * \file
 *
 * \brief AUTOSAR ETS
 *
 * This file contains the implementation of the AUTOSAR
 * module ETS.
 *
 * \version 2.3.0
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[includes]====================================================================*/

#include "Std_Types.h"
#include "ETS_Types.h"
#include "ETS_Macros.h"


/*==================[external constants]==========================================================*/

/*==================[external data]===============================================================*/

/*==================[external function declarations]==============================================*/

FUNC(void, RTE_CODE) ETS_Action_TriggerEventUINT8(void);
FUNC(void, RTE_CODE) ETS_Action_TriggerEventUINT8Reliable(void);
FUNC(void, RTE_CODE) ETS_Action_TriggerEventUINT8Array(void);
FUNC(void, RTE_CODE) ETS_Action_TriggerEventUINT8E2E(void);
FUNC(void, RTE_CODE) ETS_Action_TriggerEventUINT8Multicast(void);
FUNC(void, RTE_CODE) ETS_Action_SuspendInterface(void);
FUNC(void, RTE_CODE) ETS_Action_ResumeInterface(void);
FUNC(void, RTE_CODE) ETS_Action_ClientActivateInterface(void);
FUNC(void, RTE_CODE) ETS_Action_ClientSubscribeEventgroup(void);
FUNC(void, RTE_CODE) ETS_Action_ClientUnsubscribeEventgroup(void);
FUNC(void, RTE_CODE) ETS_Action_ClientDeactivateInterface(void);


#endif /* #ifndef ETS_TRIGGERANDEVENTS_H */
/*==================[end of file]=================================================================*/

