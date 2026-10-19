#ifndef RTW_HEADER_vehicle_intface_task_func_h_
#define RTW_HEADER_vehicle_intface_task_func_h_
#include "vehicle_service_global_variables.h"

uint8_t vehicle_interface_initialize(void);
uint8_t vehicle_interface_step(tVehDataRx* stVehDataRx_ptr);
uint8_t VehInter_CalVehicleSpeedImpulse(tVehDataRx*  stVehDataRx_ptr);

#endif //RTW_HEADER_vehicle_intface_task_func_h_


