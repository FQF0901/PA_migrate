#include "vehicle_service/calib/vehsrv_calib.h"


uint8_t VehSrv_CalibInitFromCfm(void)
{
    VehSrv_CalibInitDataFromCfm();

    return 0;
}

uint8_t VehSrv_CalibInit(void)
{
    VehSrv_CalibInitData();                // To add switch case here.

#if CALIB_DATA_FROM_CFM
    VehSrv_CalibInitFromCfm();
#endif  

    return 0;
}

tPFCalibData* VehSrv_GetCalib() 
{
    tPFCalibData* Calib_ptr = NULL;

    Calib_ptr = VehSrv_GetCalibData();     // To add switch case here.
    
    return Calib_ptr;
}


