#ifndef ONLINE_CALIB_DATA_H
#define ONLINE_CALIB_DATA_H

#include "vehicle_service/calib/vehsrv_calib_struct.h"
#include "online_calib_struct.h"
/*	=====================================================================
*						       Val Declar
*	===================================================================*/
extern tMsgMnger_CalibData        g_stCalibSoc2McuData; 
extern tMsgMnger_CalibData        g_stCalibMcu2SocData; 

extern tPFOnlineCalibData g_stOnlineCalibData;

#endif // ONLINE_CALIB_DATA_H
