#ifndef ONLINE_CALIB_ALGO_H
#define ONLINE_CALIB_ALGO_H

#include "online_calib_data.h"

extern uint8_t  CalibOnlineProcess(void);
void Calib_PfOnlieCalibData_Init(const tPFCalibData *pstPfCalibData, tPFOnlineCalibData *pstOnlineCalibData);

#endif // ONLINE_CALIB_ALGO_H
