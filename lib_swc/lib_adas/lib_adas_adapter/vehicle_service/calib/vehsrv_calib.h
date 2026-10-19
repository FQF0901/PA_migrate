#ifndef VEHSRV_CALIB_H_
#define VEHSRV_CALIB_H_

#include <stdint.h>
#include <stdio.h>
#include "Std_Types.h"
#include "vehicle_service/calib/vehsrv_calib_data.h"


uint8_t VehSrv_CalibInitFromCfm(void);
uint8_t        VehSrv_CalibInit(void);
tPFCalibData*  VehSrv_GetCalib(void);


#endif /* VEHSRV_CALIB_H_ */
