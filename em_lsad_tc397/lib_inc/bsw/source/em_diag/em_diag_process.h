#ifndef EM_DIAG_PROCESS_H__
#define EM_DIAG_PROCESS_H__
#include <stdint.h>
#include "proj_global.h"
#include "em_diag_config.h"

uint8_t DM_Dem_SlaveGetEventStatus(EM_EventIdType EventId, EM_EventStatusType* EventStatus);

uint8_t DM_Dem_SlaveSetEventStatus(EM_EventIdType EventId, EM_EventStatusType EventStatus);

void DM_DiagProcessInit(void);

void DM_SendDataToSOC(void);

void DM_RecvDataFromSOC(void);

#endif // EM_DIAG_WRAPPER_H__