#ifndef CTRL_DR_CORE_
#define CTRL_DR_CORE_

#include "adas_project_input.h"
#include "adas_struct.h"
#include "ctrl_global_variables.h"
#include "dr/dr_structs.h"
#include "ctrl_struct.h"


extern ST_DR_INFO g_stDrInfoGlobalCoordinate;

EM_ADAS_ReturnType Dr_Start(PST_DR_INFO	stDrInfo_ptr);
EM_ADAS_ReturnType Dr_Process(PST_DR_INFO stDrInfo_ptr);
EM_ADAS_ReturnType Dr_CoreSetCanData(PST_DR_INFO stDrInfo_ptr, uint64_t timeStamp, PST_VEHICLE_ESC_INFO stEscInfo_ptr,PST_VEHICLE_EPS_INFO stEpsInfo_ptr);

#endif //CTRL_DR_CORE_
