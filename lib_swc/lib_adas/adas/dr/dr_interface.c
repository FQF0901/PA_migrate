#include "adas_math.h"
#include "adas_data_list.h"
#include "adas_project_input.h"
#include "adas_calibration_data.h"
#include "adas_interface.h"
#include "dr_interface.h"
#include "dr_structs.h"
#include "vehicle_service/calib/vehsrv_calib.h"

static EM_ADAS_ReturnType Dr_UpdateCanData(PST_DR_INFO stDrInfo_ptr);
/**
*************************************************************************
  * FUNCTION_NAME 
Dr_Init_20ms_Task. 
Better change the name to Dr_TaskInit. But we also need to change it in BSW.

  * EXPLANATION   
Dr(dead reckoning) initialization. 
 - One dr calculation for ctrl, which will reset by adas parking start. 
 - One dr calculation for global coordination, which start from when vehicle power on, 
 and will not reset.    

*************************************************************************
*/

EM_ADAS_ReturnType Dr_Init_20ms_Task(void)
{
    (void)Dr_Start(&g_stDrInfoGlobalCoordinate);
	
    return ADAS_RETURN_OK;
}



/**
*************************************************************************
  * FUNCTION_NAME 
Dr_Process_20ms_Task. 

  * EXPLANATION   
Dr processing. 
  

*************************************************************************
*/

EM_ADAS_ReturnType Dr_Process_20ms_Task(void)
{
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
    if (0 == stCalibPF_ptr->stAdasSystemConfig.Calib_ADAS_DR_SWITCH)
    {
        return E_OK;
    }

    Dr_UpdateCanData(&g_stDrInfoGlobalCoordinate);
    (void)Dr_Process(&g_stDrInfoGlobalCoordinate);
    (void)Get_VehiPosAllTimeInfo3D();

    return ADAS_RETURN_OK;
}




/**
*************************************************************************
  * FUNCTION_NAME
Get_VehiPosAllTimeInfo3D.

  * EXPLANATION
Dr's output interface, provide the [X, Y, theta] to invoker, who call this
function. Here the [X, Y, theta] result goes to Rte_Write_AllTime_DR_Data().

*************************************************************************
*/

EM_ADAS_ReturnType Get_VehiPosAllTimeInfo3D(void)
{
    // tObjProperty3D stCtrlVehPoseAllTime = { 0 };

    // tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
    // float f32DrDelayTime = stCalibPF_ptr->stPFVehCalib.Calib_f32DrDelayTime;
    // TimestampType poseDelayTimeNs = f32DrDelayTime;
    

    // stCtrlVehPoseAllTime.u64Timestamp_us = g_stDrInfoGlobalCoordinate.stNowPose.u64Timestamp - poseDelayTimeNs;   // SysTm_GetUnixTimestamp_us() - poseDelayTimeNs;
    // stCtrlVehPoseAllTime.f32X            = g_stDrInfoGlobalCoordinate.stNowPose.f32X_Coor;
    // stCtrlVehPoseAllTime.f32Y            = g_stDrInfoGlobalCoordinate.stNowPose.f32Y_Coor;
    // stCtrlVehPoseAllTime.f32Z            = 0;
    // stCtrlVehPoseAllTime.f32Yaw          = g_stDrInfoGlobalCoordinate.stNowPose.f32Theta;
    // stCtrlVehPoseAllTime.f32Pitch        = 0;
    // stCtrlVehPoseAllTime.f32Roll         = 0;
    // // --- Temp solution, send the ctrl calculated vehicle speed, to USS.
    // stCtrlVehPoseAllTime.f32Roll         = g_stChassisToCtrlInfo.f32VehSpdImpFiltered;
    // // --- Temp solution. END
    // stCtrlVehPoseAllTime.f32Depth        = g_stDrInfoGlobalCoordinate.stNowPose.f32Track;
    // stCtrlVehPoseAllTime.f32Height       = g_stCtrlVehSpeed.f32VehSpeed;
    // stCtrlVehPoseAllTime.u8Confidence    = 1;

    // return Rte_Write_AllTime_DR_Data(&stCtrlVehPoseAllTime);

    tMsgMnger_Localisition msgMnger_Localisition;
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
    float f32DrDelayTime = stCalibPF_ptr->stPFVehCalib.Calib_f32DrDelayTime;
    TimestampType poseDelayTimeNs = f32DrDelayTime;

    msgMnger_Localisition.eApaLocalisationSts            = APA_FUNC_SUCCESS;
    if (g_stDrInfoGlobalCoordinate.stNowPose.u64Timestamp < poseDelayTimeNs)
    {
        msgMnger_Localisition.u64Timestamp_us = 0;
    }
    else
    {
        msgMnger_Localisition.u64Timestamp_us = g_stDrInfoGlobalCoordinate.stNowPose.u64Timestamp - poseDelayTimeNs;   // SysTm_GetUnixTimestamp_us() - poseDelayTimeNs;
    }
    //msgMnger_Localisition.sVehiPosInfo3D.eType           = OBJ_TYPE_DEFAULT;    // better add a new enum type = EgoVehicle. 
    msgMnger_Localisition.f32x            = g_stDrInfoGlobalCoordinate.stNowPose.f32X_Coor;
    msgMnger_Localisition.f32y            = g_stDrInfoGlobalCoordinate.stNowPose.f32Y_Coor;
    msgMnger_Localisition.f32z            = 0;
    msgMnger_Localisition.f32yaw          = g_stDrInfoGlobalCoordinate.stNowPose.f32Theta;
    msgMnger_Localisition.f32pitch        = 0;
    // msgMnger_Localisition.f32roll         = 0;
    // msgMnger_Localisition.sVehiPosInfo3D.f32Roll         = g_stChassisToCtrlInfo.f32VehSpdImpFiltered;  // --- Temp solution, send the ctrl calculated vehicle speed, to USS.
    msgMnger_Localisition.f32roll        = g_stDrInfoGlobalCoordinate.stNowPose.f32Track;
    // msgMnger_Localisition.sVehiPosInfo3D.f32Height       = g_stCtrlVehSpeed.f32VehSpeed;                // --- Temp solution
    // msgMnger_Localisition.sVehiPosInfo3D.u8Confidence    = 1;


    // Rte_Write_MsgManager_Localisition(&msgMnger_Localisition); //2024.05.14 HAPA, Read DR from SOC

    return ADAS_RETURN_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME 
Dr_SetPoseNow. 

  * EXPLANATION   
Localization information from external resource, e.g. SOC PO, simulation. 

*************************************************************************
*/

EM_ADAS_ReturnType Dr_SetPoseNow(tDrVehiclePosition* pose_ptr)
{
    float dis = GetDistance(g_stDrInfoGlobalCoordinate.stNowPose.f32X_Coor, g_stDrInfoGlobalCoordinate.stNowPose.f32Y_Coor,
                            pose_ptr->f32X_Coor, pose_ptr->f32Y_Coor );

    g_stDrInfoGlobalCoordinate.stVehPos =  *pose_ptr;
    g_stDrInfoGlobalCoordinate.stVehPos.f32Track += dis;

    // --- stNowPose is for final use.
    g_stDrInfoGlobalCoordinate.stNowPose = g_stDrInfoGlobalCoordinate.stVehPos;

    return ADAS_RETURN_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME 
Dr_GetPoseNow. 

  * EXPLANATION   
Interface function for external modules. When the external module calls this 
function, it will receive localization information from g_stDrInfoGlobalCoordinate.

*************************************************************************
*/

EM_ADAS_ReturnType Dr_GetPoseNow(tDrVehiclePosition *stPoseData_ptr)
{
    *stPoseData_ptr = g_stDrInfoGlobalCoordinate.stNowPose;
    
    return ADAS_RETURN_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME 
Dr_UpdateCanData. 

  * EXPLANATION   
Update the CAN data which is received CAN network

*************************************************************************
*/
static EM_ADAS_ReturnType Dr_UpdateCanData(PST_DR_INFO stDrInfo_ptr)
{
    tMsgMnger_VehicleInfo   stVehicleInfo;
    (void)Rte_Read_MsgManager_VehicleInfo(&stVehicleInfo);
    // In BYD, we must use the first level timestamp, but in MarvelR we used to use the second level timestamp.
    Dr_CoreSetCanData(stDrInfo_ptr, stVehicleInfo.u64Timestamp_us, &(stVehicleInfo.sVehicleDataRx.stVehESCInfo), &(stVehicleInfo.sVehicleDataRx.stVehEPSInfo));

    return ADAS_RETURN_OK;
}

