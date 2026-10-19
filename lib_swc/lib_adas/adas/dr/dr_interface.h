#ifndef CTRL_DR_INTERFACE_
#define CTRL_DR_INTERFACE_


#include "adas_struct.h"
#include "adas_project_input.h"
#include "dr_core.h"


// --- Part of interface functions are declared in adas_interface.h
// EM_ADAS_ReturnType Dr_Init_20ms_Task(void);
// EM_ADAS_ReturnType Dr_Process_20ms_Task(void);
// EM_ADAS_ReturnType Get_VehiPosAllTimeInfo3D(void);
// --- Part of interface functions are declared in adas_interface.h. END

EM_ADAS_ReturnType Dr_SetPoseNow(tDrVehiclePosition* pose_ptr);     // Localization from external resource, e.g. SOC PO, simulation.
EM_ADAS_ReturnType Dr_GetPoseNow(tDrVehiclePosition* stPoseData_ptr);

#endif //CTRL_DR_INTERFACE_
