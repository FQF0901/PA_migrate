#ifndef EM_SWC_DR_WORK_INCLUDE_DR_FILTER_H_
#define EM_SWC_DR_WORK_INCLUDE_DR_FILTER_H_



#include "adas_light_matrix.h"
#include "adas_calibration_data.h"
#include "dr_interface.h"

#define DR_EKF_ON 0


typedef struct _VEH_IMU_INFO_TAG_
{
    uint64_t u64TimeStamp;
    tValidity eVehicleIMUValidity;

    float f32X_Acc;
    float f32Y_Acc;
    float f32Z_Acc;

    float f32Pitch_Rate;
    float f32Roll_Rate;
    float f32Yaw_Rate;

} ST_VEHICLE_IMU_INFO, *PST_VEHICLE_IMU_INFO;


EM_ADAS_ReturnType DR_filtering_Init();//EKF滤波初始化，主要初始化相关矩阵，申请相关内存空间

EM_ADAS_ReturnType DR_filtering(PST_DR_INFO    Obs_Position,
                                ST_VEHICLE_IMU_INFO* Input_YawRate,
                                tVehi_VehicleDataRx* Input_Speed);//EKF滤波过程，调用一次为一次循环

EM_ADAS_ReturnType DR_filtering_Clear();//释放EKF滤波资源，释放内存空间

#endif /* EM_SWC_DR_WORK_INCLUDE_DR_FILTER_H_ */

