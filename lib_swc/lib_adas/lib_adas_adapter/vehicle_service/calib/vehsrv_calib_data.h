#ifndef VEHSRV_CALIB_DATA_H_
#define VEHSRV_CALIB_DATA_H_

#include <stdint.h>
#include "Std_Types.h"
#include "vehicle_service/calib/vehsrv_calib_struct.h"
#include "vehicle_service/calib/online/online_calib_data.h"



extern tPFCalibData g_stCalibData;


uint8_t VehSrv_CalibInitData(void);
tPFCalibData* VehSrv_GetCalibData(void);
uint8_t VehSrv_CalibInitDataFromCfm(void);

#endif /* VEHSRV_CALIB_DATA_H_ */
