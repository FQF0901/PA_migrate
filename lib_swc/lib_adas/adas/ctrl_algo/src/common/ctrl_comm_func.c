/*
 * ctrl_comm_func.c
 *
 *  Created on: Jul 20, 2021
 *      
 */

#include "peb/ctrl_peb_algo_new.h"
#include "ctrl_diag.h"
#include "ctrl_comm_func.h"
#include "math.h"
#include "controller/ctrl_lat_algo.h"
#include "vehicle_service/calib/vehsrv_calib.h"
#include "adas_project_input.h"


static uint8_t Ctrl_Steering_Compensation(tCtrlLatResult*        stCtrlLatResult_ptr,
                                          tPathPlannerInfo*      stPathPlannerInfo_ptr);
static uint8_t Ctrl_Finish_ParkComplete(tPathPlannerInfo*   stPathPlannerInfo_ptr);
static uint8_t Ctrl_Finish_PebComplete(tCtrlCommonInfo*    stCtrlCommonInfo_ptr);
static uint8_t Ctrl_Finish_PathGearP(tPathPlannerInfo*   stPathPlannerInfo_ptr);
static uint8_t Ctrl_Finish_ChockComplete(tCtrlCommonInfo*    stCtrlCommonInfo_ptr);
static uint8_t Ctrl_Finish_WaitNewPathTimeOut(tCtrlCommonInfo*  stCtrlCommonInfo_ptr);
static uint8_t Ctrl_Finish_InvalidPath(tPathPlannerInfo*   stPathPlannerInfo_ptr);
static uint8_t Ctrl_Finish_UnknownLongStop(tCtrlCommonInfo*  stCtrlCommonInfo_ptr);
static uint8_t Ctrl_Finish_Trapped(tCtrlCommonInfo*  stCtrlCommonInfo_ptr);
static uint8_t Ctrl_Finish_ReplanFailed(tPathPlannerInfo*   stPathPlannerInfo_ptr);
static uint8_t Ctrl_GetVehicleStopFlag(tVehDataRx*   stVehDataRx_ptr);



/**
*************************************************************************
  * FUNCTION_NAME
control_WheelSpeed_Opposite_gear
  * EXPLANATION
This function will return required gear based on ref path
*************************************************************************
*/
uint8_t control_WheelSpeedDirection_Opposite_gear(tVehDataRx*            stVehDataRx_ptr,
                                                  tCtrlCommonInfo*       stCtrlCommonInfo_ptr)
{
  static uint8 u8WhlSpdDirectOpposGearCounter = 0;
  if((stVehDataRx_ptr->sVehVCUInfo.eVehActualGear == R_GEAR &&
     (stVehDataRx_ptr->sVehESCInfo.eWhlDirRL == WHLSPD_FORWARD || stVehDataRx_ptr->sVehESCInfo.eWhlDirRR == WHLSPD_FORWARD)) ||
     (stVehDataRx_ptr->sVehVCUInfo.eVehActualGear == D_GEAR && 
     (stVehDataRx_ptr->sVehESCInfo.eWhlDirRL == WHLSPD_BACKWARD || stVehDataRx_ptr->sVehESCInfo.eWhlDirRR == WHLSPD_BACKWARD))){
    u8WhlSpdDirectOpposGearCounter++;
    u8WhlSpdDirectOpposGearCounter = (u8WhlSpdDirectOpposGearCounter>150)?150 : u8WhlSpdDirectOpposGearCounter; 
    
  } else{
    u8WhlSpdDirectOpposGearCounter = 0;
  }
  if(u8WhlSpdDirectOpposGearCounter >5){
    stCtrlCommonInfo_ptr->bWhlSpdDirectOppositeGear = 1;
    stCtrlCommonInfo_ptr->f32VehSpdDirectKph = -stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph;
  }else {
    stCtrlCommonInfo_ptr->bWhlSpdDirectOppositeGear = 0;
    stCtrlCommonInfo_ptr->f32VehSpdDirectKph = stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph;//在坡道上应用
  }
  return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_SetGear

  * EXPLANATION
This function will return required gear based on ref path
*************************************************************************
*/
uint8_t Ctrl_GearReq(tPathPlannerInfo*      stPathPlannerInfo_ptr,
                     tVehDataRx*            stVehDataRx_ptr,
                     tCtrlToChassisInfo*    stCtrl2ChassisInfo_ptr,
                     tCtrlCommonInfo*       stCtrlCommonInfo_ptr)
{
    tVehActualGear eCurGear = stVehDataRx_ptr->sVehVCUInfo.eVehActualGear;
    float f32CurSpd = stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph;
    uint8 bVehStandStill = stVehDataRx_ptr->sVehESCInfo.bVehStandStill;
    tVehActualGear ePPGearReq = (tVehActualGear)stPathPlannerInfo_ptr->u8Shift;
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
    float f32RegardAsStopSpd = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32RegardAsStopSpeed;

    // --- Protection: PP send the conflict gear request while driving.
    if (eCurGear == ePPGearReq ||  1== bVehStandStill || P_GEAR == eCurGear)   // 1.2km/h: can cover the slip on speed bump, the vehicle speed is usually <= 1.0km/h. 
    {
        stCtrl2ChassisInfo_ptr->eGearReq = ePPGearReq;
        stCtrlCommonInfo_ptr->u8ConflictGearFlag = 0;
    }
    else 
    {
        // stCtrl2ChassisInfo_ptr->eGearReq = eCurGear;  //维持原来的需求档位
        stCtrlCommonInfo_ptr->u8ConflictGearFlag = 1;
    }

    // --- Check if the chassis vehicle gear is the same with PPGear
    if (eCurGear == ePPGearReq)
    {
        stCtrlCommonInfo_ptr->u8PpGearAchieved = 1;
    }
    else 
    {
        stCtrlCommonInfo_ptr->u8PpGearAchieved = 0;
    }

    return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_ApaStraightGearReq

  * EXPLANATION
This function can be merged with APA's Ctrl_GearReq(), but the cost is that
 the function input becomes more complicated.

*************************************************************************
*/
uint8_t Ctrl_ApaStraightGearReq(tCtrlFuncFsmInfo*	   stCtrlApaShellInfo_ptr,
                                tVehDataRx*            stVehDataRx_ptr,
                                tCtrlToChassisInfo*    stCtrl2ChassisInfo_ptr,
                                tCtrlCommonInfo*       stCtrlCommonInfo_ptr)
{
    tVehActualGear eCurGear = stVehDataRx_ptr->sVehVCUInfo.eVehActualGear;
    float f32CurSpd = stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph;
    tVehActualGear eDriverGearReq = eCurGear;
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
    float f32RegardAsStopSpd = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32RegardAsStopSpeed;

    // --- Gear shift based on driver's command.
    if (DRIVER_CTRL_STRAIGHT_FORWARD == stCtrlApaShellInfo_ptr->eLsadDriverCtrlCommand)
    {
        eDriverGearReq = D_GEAR;
    }
    else if (DRIVER_CTRL_STRAIGHT_BACKWARD == stCtrlApaShellInfo_ptr->eLsadDriverCtrlCommand)
    {
        eDriverGearReq = R_GEAR;
    }

    // --- Protection: PP send the conflict gear request while driving.
    if (eCurGear == eDriverGearReq || f32CurSpd < f32RegardAsStopSpd)
    {
        stCtrl2ChassisInfo_ptr->eGearReq = eDriverGearReq;
        stCtrlCommonInfo_ptr->u8ConflictGearFlag = 0;
    }
    else 
    {
        stCtrl2ChassisInfo_ptr->eGearReq = eCurGear;
        stCtrlCommonInfo_ptr->u8ConflictGearFlag = 1;
    }

    return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_UpdateCurPathId

  * EXPLANATION
When the vehicle really start to follow the new path, then update the current 
path ID.

*************************************************************************
*/

uint8_t Ctrl_UpdateCurPathId(tVehDataRx*   stVehDataRx_ptr,
                             tCtrlLongiInfo*       stCtrlLongiInfo_ptr,
                             tCtrl_StateInfo*   stCtrl2PP_State_Info_ptr,
                             tCtrlCommonInfo*     stCtrlCommonInfo_ptr,
                             tPathPlannerInfo*    stPathPlannerInfo_ptr)
{
    tCtrlSpeedTrapezoidPhase ePhase = stCtrlLongiInfo_ptr->eSpeedPhase; 

    if (PHASE_STOP != ePhase && PHASE_EMERGENCY_STOP != ePhase)      
    {
        stCtrlCommonInfo_ptr->u16CurrentPathID = stPathPlannerInfo_ptr->u16PathId;
    }

	return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_SelectPoseForLateralCalcu

  * EXPLANATION
Select current vehicle position or future vehicle position, for lateral 
control calculation. 

*************************************************************************
*/

uint8_t Ctrl_SelectPoseForLateralCalcu(tCtrlVehPose*      stCtrlVehPose_ptr)
{
    // --- Select current pose for lateral control calculation.
    // stCtrlVehPose_ptr->stSelectedPos = stCtrlVehPose_ptr->stCurrentPos;

    // --- Select predictive pose for lateral control calculation.
    stCtrlVehPose_ptr->stSelectedPos.f32X_Coor = stCtrlVehPose_ptr->stPredictPos.f32FutureDRPoseX;
    stCtrlVehPose_ptr->stSelectedPos.f32Y_Coor = stCtrlVehPose_ptr->stPredictPos.f32FutureDRPoseY;
    stCtrlVehPose_ptr->stSelectedPos.f32Theta  = stCtrlVehPose_ptr->stPredictPos.f32FutureDRTheta;

	return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_RecordPrevPose

  * EXPLANATION
This function stores previous value of dead reckoning

*************************************************************************
*/

uint8_t Ctrl_RecordPrevPose(tCtrlVehPose*      stCtrlVehPose_ptr)
{
	 stCtrlVehPose_ptr->stPreviousPos.f32Theta     = stCtrlVehPose_ptr->stCurrentPos.f32Theta;
	 stCtrlVehPose_ptr->stPreviousPos.f32Track     = stCtrlVehPose_ptr->stCurrentPos.f32Track;
	 stCtrlVehPose_ptr->stPreviousPos.f32X_Coor    = stCtrlVehPose_ptr->stCurrentPos.f32X_Coor;
	 stCtrlVehPose_ptr->stPreviousPos.f32Y_Coor    = stCtrlVehPose_ptr->stCurrentPos.f32Y_Coor;
	 stCtrlVehPose_ptr->stPreviousPos.u64Timestamp = stCtrlVehPose_ptr->stCurrentPos.u64Timestamp;

	 return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_DistanceLeft

  * EXPLANATION
This function will return the distance left of current refence path.
 - Current solution: distance between point to line.
 - Potential solution: use the nearest point and the last point on line.

*************************************************************************
*/

uint8_t Ctrl_PathDistanceLeft(tCtrlVehiclePosition*       stCurrentPos_ptr,
                          tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
						  tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
						  tPathPlannerInfo*         stPathPlannerInfo_ptr)
{   
    float f32ParaK = 0;
    float f32ParaB = 0;
    uint8_t u8LastPointId = stPathPlannerInfo_ptr->u8LastPointId;
    float f32EgoVehX = stCurrentPos_ptr->f32X_Coor;
    float f32EgoVehY = stCurrentPos_ptr->f32Y_Coor;
    float f32LastPointX = stPathPlannerInfo_ptr->stPathData[u8LastPointId].f32WayPointX;
    float f32LastPointY = stPathPlannerInfo_ptr->stPathData[u8LastPointId].f32WayPointY;
    float f32LastPointThetaVertical = (stPathPlannerInfo_ptr->stPathData[u8LastPointId].f32WayPointTheta) + CTRL_PI / 2;

    // --- Protection
    if (f32LastPointThetaVertical > 100)
    {
        f32LastPointThetaVertical = 100;
    }
    else if (f32LastPointThetaVertical < -100)
    {
        f32LastPointThetaVertical = -100;
    }

    while (f32LastPointThetaVertical > CTRL_PI)
    {
        f32LastPointThetaVertical = f32LastPointThetaVertical - 2 * CTRL_PI;
    }

    while (f32LastPointThetaVertical < -CTRL_PI)
    {
        f32LastPointThetaVertical = f32LastPointThetaVertical + 2 * CTRL_PI;
    }

    // --- Calculate the distance between point to line.
    if (fabs(f32LastPointThetaVertical - CTRL_PI/2) < 0.005 || fabs(f32LastPointThetaVertical + CTRL_PI/2) < 0.005)    //When the vehicle is in the horizontal position, < 0.005 means close to zero, i.e. tan(f32LastPointThetaVertical) = infinity.
    {
        if(stPathPlannerInfo_ptr->u8NewPathFlag)
        {
            if(f32EgoVehX >= f32LastPointX)         //Initial position to the right of the normal : +
            {
                stCtrlCommonInfo_ptr->i8PathStartPosIndicator = 1;
            }
            else                                    //Initial position to the left of the normal : -
            {
                stCtrlCommonInfo_ptr->i8PathStartPosIndicator = -1;
            }
        }
        stCtrlCommonInfo_ptr->f32DistanceLeft = stCtrlCommonInfo_ptr->i8PathStartPosIndicator * (f32EgoVehX - f32LastPointX);
    }
    else 
    {
        f32ParaK = tanf(f32LastPointThetaVertical);
        f32ParaB = f32LastPointY - f32ParaK * f32LastPointX;
        if(stPathPlannerInfo_ptr->u8NewPathFlag)                            //Judge the initial position of new path 
        {
            if(f32EgoVehY >= (f32ParaK * f32EgoVehX + f32ParaB))            //Initial position to the above of the normal : +
            {
                stCtrlCommonInfo_ptr->i8PathStartPosIndicator = 1;
            }
            else                                                            //Initial position to the below of the normal : -
            {
                stCtrlCommonInfo_ptr->i8PathStartPosIndicator = -1;
            }
        }
        stCtrlCommonInfo_ptr->f32DistanceLeft = stCtrlCommonInfo_ptr->i8PathStartPosIndicator * 
                                                (f32EgoVehY - f32ParaK*f32EgoVehX - f32ParaB) / sqrtf(f32ParaK*f32ParaK + 1); 
    }

    // --- Close to zero handling.
    stCtrlCommonInfo_ptr->f32DistanceLeftRaw = stCtrlCommonInfo_ptr->f32DistanceLeft;   // Monitor the raw value, to see if the optimized algorithm works.
	if (stCtrlCommonInfo_ptr->f32DistanceLeft < g_stCalibData.stPFCtrlLongCalib.Calib_f32DistanceLeftMin)
	{
        stCtrlCommonInfo_ptr->f32DistanceLeft = 0;
	}

    // --- Invalid path and reference point, park finished, stop calculation.
    if (stPathPlannerInfo_ptr->u16PathId > stPathPlannerInfo_ptr->u16TotallyPathNum)
    {
        stCtrlCommonInfo_ptr->f32DistanceLeft = 0;
    }

	return E_OK;
}

// /**
// *************************************************************************
//   * FUNCTION_NAME
// Ctrl_DistanceLeft

//   * EXPLANATION
// This function will return the distance left of current refence path.
//  - Current solution: distance between point to line.
//  - Potential solution: use the nearest point and the last point on line.

// *************************************************************************
// */

uint8_t Ctrl_TrajDistanceLeft(tCtrlVehiclePosition*       stCurrentPos_ptr,
                              tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                              tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                              tPathPlannerInfo*         stPathPlannerInfo_ptr)
{   
    uint8_t point_num = stPathPlannerInfo_ptr->u8PointNum;
	uint8_t index = stCtrlCommonInfo_ptr->u8NearestPointIndexCurPose;
	float prj_distance = 0.0;
	float vec_a[2] = {0.0,0.0};
	float vec_b[2] = {0.0,0.0};
    float disCarToMachpoint = 0.0;

	if (index == point_num - 1)
	{
		vec_a[0] = stCurrentPos_ptr->f32X_Coor - stPathPlannerInfo_ptr->stPathData[index].f32WayPointX;
		vec_a[1] = stCurrentPos_ptr->f32Y_Coor - stPathPlannerInfo_ptr->stPathData[index].f32WayPointY;
		vec_b[0] = stPathPlannerInfo_ptr->stPathData[index].f32WayPointX - stPathPlannerInfo_ptr->stPathData[index-1].f32WayPointX;
		vec_b[1] = stPathPlannerInfo_ptr->stPathData[index].f32WayPointY - stPathPlannerInfo_ptr->stPathData[index-1].f32WayPointY;
	}
	else
	{
		vec_a[0] = stCurrentPos_ptr->f32X_Coor - stPathPlannerInfo_ptr->stPathData[index].f32WayPointX;
		vec_a[1] = stCurrentPos_ptr->f32Y_Coor - stPathPlannerInfo_ptr->stPathData[index].f32WayPointY;
		vec_b[0] = stPathPlannerInfo_ptr->stPathData[index+1].f32WayPointX - stPathPlannerInfo_ptr->stPathData[index].f32WayPointX;
		vec_b[1] = stPathPlannerInfo_ptr->stPathData[index+1].f32WayPointY - stPathPlannerInfo_ptr->stPathData[index].f32WayPointY;
	}
    
    if(sqrtf(sq(vec_b[0]) + sq(vec_b[1]))<MATH_EPSILON)
    {
        prj_distance = 0.0f;
    }
    else
    {
        prj_distance = (vec_a[0] * vec_b[0] + vec_a[1] * vec_b[1]) / sqrtf(sq(vec_b[0]) + sq(vec_b[1]));
    }

	if (index == point_num - 1 &&  prj_distance >= 0)
	{	
		disCarToMachpoint = 0;
	}
	else
	{
        disCarToMachpoint = prj_distance;
	}

    stCtrlCommonInfo_ptr->f32DistanceLeft = g_stPathPlannerData.f32PathLength - g_stPathPlannerData.stPathData[index].f32WayPointS - prj_distance;

    // --- Invalid path and reference point, park finished, stop calculation.
    if (stPathPlannerInfo_ptr->u16PathId > stPathPlannerInfo_ptr->u16TotallyPathNum)
    {
        stCtrlCommonInfo_ptr->f32DistanceLeft = 0;
    }

	return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_DistanceLeft

  * EXPLANATION
This function will return the distance left of current refence path.
 - Current solution: distance between point to line.
 - Potential solution: use the nearest point and the last point on line.

*************************************************************************
*/

uint8_t Ctrl_DistanceLeft(tPathPlannerInfo*   stPathPlannerInfo_ptr)
{
    if(true == stPathPlannerInfo_ptr->u8IsTraj)
    {
        Ctrl_TrajDistanceLeft(&g_stCtrlVehPose.stCurrentPos, &g_stCtrlLongiInfo, &g_stCtrlCommonInfo, &g_stPathPlannerData);
    }
    else
    {
        Ctrl_PathDistanceLeft(&g_stCtrlVehPose.stCurrentPos, &g_stCtrlLongiInfo, &g_stCtrlCommonInfo, &g_stPathPlannerData);
    }

    return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_Veh_Trapped_Detection

  * EXPLANATION
This function detects if the vehicle is trap by front and rear aeb
*************************************************************************
*/

// uint8_t Ctrl_VehTrappedDetection(tPathPlannerInfo*          stPathPlannerInfo_ptr,
//                                  tCtrlCommonInfo*           stCtrlCommonInfo_ptr,
//                                  tVehDataRx*   stVehDataRx_ptr)
// {
//   int iTrappedTime = 100;

//   if(((R_GEAR == stCtrlCommonInfo_ptr->eGearRecord) && (D_GEAR == stVehDataRx_ptr->sVehVCUInfo.eVehActualGear)) || 
//      ((D_GEAR == stCtrlCommonInfo_ptr->eGearRecord) && (R_GEAR == stVehDataRx_ptr->sVehVCUInfo.eVehActualGear))){
//     if (0 == stCtrlCommonInfo_ptr->u16TrappedTime1){
//       stCtrlCommonInfo_ptr->u16TrappedTime3 = 0;
//       stCtrlCommonInfo_ptr->u16TrappedTime2 = 0;
//       stCtrlCommonInfo_ptr->u16TrappedTime1 = 1;
//     }else if (0 == stCtrlCommonInfo_ptr->u16TrappedTime2){
//       // Must be written in reverse
//       stCtrlCommonInfo_ptr->u16TrappedTime3 = 0;
//       stCtrlCommonInfo_ptr->u16TrappedTime2 = stCtrlCommonInfo_ptr->u16TrappedTime1 + 1;
//       stCtrlCommonInfo_ptr->u16TrappedTime1 = 1;
//     }else{
//       // Must be written in reverse
//       stCtrlCommonInfo_ptr->u16TrappedTime3 = stCtrlCommonInfo_ptr->u16TrappedTime2 + 1;
//       stCtrlCommonInfo_ptr->u16TrappedTime2 = stCtrlCommonInfo_ptr->u16TrappedTime1 + 1;
//       stCtrlCommonInfo_ptr->u16TrappedTime1 = 1;
//     }
//   }else{
//     if(0 != stCtrlCommonInfo_ptr->u16TrappedTime1){
//       stCtrlCommonInfo_ptr->u16TrappedTime1 = stCtrlCommonInfo_ptr->u16TrappedTime1 + 1;
//     }else{
//       ;
//     }

//     if(0 != stCtrlCommonInfo_ptr->u16TrappedTime2){
//       stCtrlCommonInfo_ptr->u16TrappedTime2 = stCtrlCommonInfo_ptr->u16TrappedTime2 + 1;
//     }else{
//       ;
//     }

//     if(0 != stCtrlCommonInfo_ptr->u16TrappedTime3){
//       stCtrlCommonInfo_ptr->u16TrappedTime3 = stCtrlCommonInfo_ptr->u16TrappedTime3 + 1;
//     }else{
//       ;
//     }
//   }

//   stCtrlCommonInfo_ptr->u16TrappedTime1 = (stCtrlCommonInfo_ptr->u16TrappedTime1 > 500)? 500 : stCtrlCommonInfo_ptr->u16TrappedTime1;
//   stCtrlCommonInfo_ptr->u16TrappedTime2 = (stCtrlCommonInfo_ptr->u16TrappedTime2 > 500)? 500 : stCtrlCommonInfo_ptr->u16TrappedTime2;
//   stCtrlCommonInfo_ptr->u16TrappedTime3 = (stCtrlCommonInfo_ptr->u16TrappedTime2 > 500)? 500 : stCtrlCommonInfo_ptr->u16TrappedTime3;


//   if ((stCtrlCommonInfo_ptr->u16TrappedTime1 > 0) && (stCtrlCommonInfo_ptr->u16TrappedTime1 < iTrappedTime) && 
//       (stCtrlCommonInfo_ptr->u16TrappedTime2 > 0) && (stCtrlCommonInfo_ptr->u16TrappedTime2 < iTrappedTime) && 
//       (stCtrlCommonInfo_ptr->u16TrappedTime3 > 0) && (stCtrlCommonInfo_ptr->u16TrappedTime3 < iTrappedTime)){
//     stCtrlCommonInfo_ptr->u8CtrlTrapFlag = 1;
//     stCtrlCommonInfo_ptr->u8CtrlSubstate = CTRL_CTRL_SUBSTATE_STOP_TRAP;
//   }else{
//     ;
//   }

//   stCtrlCommonInfo_ptr->eGearRecord = stVehDataRx_ptr->sVehVCUInfo.eVehActualGear;   // To confirm if need ctrl_gear or veh_gear, if need veh_gear, use the rte to record.

//     return E_OK;

// }

/**
*************************************************************************
  * FUNCTION_NAME 
Ctrl_ReqPause.

  * EXPLANATION
If peb activate and no available path, decision will require ctrl to pause.

*************************************************************************
*/

uint8_t Ctrl_ReqPause(tCtrlCommonInfo*           stCtrlCommonInfo_ptr,
                      tPathPlannerInfo*          stPathPlannerInfo_ptr)
{
    if (CTRL_ACTION_PAUSE == stPathPlannerInfo_ptr->u8VehicleActionRequest)
    {
        stCtrlCommonInfo_ptr->u8PauseFlag = 1;
    }
    else
    {
        stCtrlCommonInfo_ptr->u8PauseFlag = 0;
    }

    return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_WheelChock_Detection

  * EXPLANATION
When the vehicle had actually already finished the parking, but is blocked by 
the wheel block, which is not recognized precisely by camera, we will regard 
this as park finished. 
Additionally, if the vehicle is blocked by stone, speed bump, slope, etc. we will
do the same execution. 
block means: Ctrl2Chassis.speed > 0, Chassis2Ctrl.speed = 0.

*************************************************************************
*/

uint8_t Ctrl_WheelChock_Detection(tCtrlCommonInfo*           stCtrlCommonInfo_ptr,
                                  tVehDataRx*   stVehDataRx_ptr,
                                  tPathPlannerInfo*          stPathPlannerInfo_ptr,
                                  tCtrlToChassisInfo*        stCtrl2ChassisInfo_ptr)
{
  tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
  float f32DistLeft = stCtrlCommonInfo_ptr->f32DistanceLeft;
  float f32VerticalChockAllowedDistLeft = stCalibPF_ptr->stPFAPAFuncConfig.Config_f32VerticalChockDetectDistance;
  float f32HorizontalChockAllowedDistLeft = stCalibPF_ptr->stPFAPAFuncConfig.Config_f32HorizontalChockDetectDistance;
  float f32VehSpeed = stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph;
  int16_t i16VerticalChockWaitTime = stCalibPF_ptr->stPFAPAFuncConfig.Config_i16VerticalChockWaitTime;
  int16_t i16HorizontalChockWaitTime = stCalibPF_ptr->stPFAPAFuncConfig.Config_i16HorizontalChockWaitTime;
  int16_t i16GeneralChockWaitTime = stCalibPF_ptr->stPFAPAFuncConfig.Config_i16GeneralChockWaitTime;
  float f32RegardAsStopSpd = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32RegardAsStopSpeed;
  tActiveSts eBrakeActiveSts = stVehDataRx_ptr->sVehVCUInfo.bBrkPedal;
  float f32ReqSpeed = stCtrl2ChassisInfo_ptr->f32CtrlReqSpeed;

    // --- Detect trapped.
  #if (SIMULATION_PRESCAN_MCU)   // In prescan, the brake pedal is always pressed.
    if (f32ReqSpeed > 0.2 && 1 == stCtrlCommonInfo_ptr->bWhlSpdDirectOppositeGear && 1 == stPathPlannerInfo_ptr->u8LastPathFlag){
  #else
    if (f32ReqSpeed > 0.2 && 1 == stCtrlCommonInfo_ptr->bWhlSpdDirectOppositeGear  && 
        NOT_ACTIVED == eBrakeActiveSts ) {
  #endif
      if(DF_PL_TYPE_Vertical == g_stPathPlannerData.eCtrlPldType  && f32DistLeft < f32VerticalChockAllowedDistLeft && 
         1 == stPathPlannerInfo_ptr->u8LastPathFlag){
        stCtrlCommonInfo_ptr->eCtrlChockedTypeFlag = CONTROL_CHOCKED_VERTICAL;
        stCtrlCommonInfo_ptr->u8CtrlSubstate = CTRL_CTRL_SUBSTATE_STOP_CHOCK;
      }else if(DF_PL_TYPE_Horizontal == g_stPathPlannerData.eCtrlPldType  && f32DistLeft < f32HorizontalChockAllowedDistLeft && 
               1 == stPathPlannerInfo_ptr->u8LastPathFlag){
        stCtrlCommonInfo_ptr->eCtrlChockedTypeFlag = CONTROL_CHOCKED_HORIZONTAL;
        stCtrlCommonInfo_ptr->u8CtrlSubstate = CTRL_CTRL_SUBSTATE_STOP_CHOCK;
      }else if( stCtrlCommonInfo_ptr->u16CtrlChockCount >250){
        stCtrlCommonInfo_ptr->eCtrlChockedTypeFlag = CONTROL_CHOCKED_ROLL_BACK;//库外判断车辆溜坡5s直接退出
        stCtrlCommonInfo_ptr->u8CtrlSubstate = CTRL_CTRL_SUBSTATE_STOP_CHOCK;
      }else{
        stCtrlCommonInfo_ptr->eCtrlChockedTypeFlag = CONTROL_CHOCKED_NO;
        stCtrlCommonInfo_ptr->u16CtrlChockCount ++;
      }
      
    }else{
      stCtrlCommonInfo_ptr->eCtrlChockedTypeFlag = CONTROL_CHOCKED_NO;
      stCtrlCommonInfo_ptr->u16CtrlChockCount = 0;
    }


  return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_UnknownLongStopDetection

  * EXPLANATION
Ctrl as the final module in ADAS, should set a finish judgement for unknown 
stop. 

*************************************************************************
*/

uint8_t Ctrl_UnknownLongStopDetection(tVehDataRx*               stVehDataRx_ptr,
                                      tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                      tCtrlToChassisInfo*       stCtrl2ChassisInfo_ptr)
{
  tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
  uint16_t u16UnknownStopWaitTime = stCalibPF_ptr->stPFAPAFuncConfig.Config_u16UnknowStopWaitTime;
  float f32RegardAsStopSpd = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32RegardAsStopSpeed;
  float f32VehSpeed = stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph;
  tActiveSts eBrakeActiveSts = stVehDataRx_ptr->sVehVCUInfo.bBrkPedal;

#if (SIMULATION_PRESCAN_MCU)   // In prescan, the brake pedal is always pressed.
  if (f32VehSpeed < f32RegardAsStopSpd){
#else
  if (f32VehSpeed < f32RegardAsStopSpd && 1 == stVehDataRx_ptr->sVehESCInfo.bVehStandStill &&
      NOT_ACTIVED == eBrakeActiveSts && stCtrl2ChassisInfo_ptr->f32CtrlReqSpeed>0.2){ 
#endif
    stCtrlCommonInfo_ptr->u16CtrlUnknownStopCount++;
    stCtrlCommonInfo_ptr->u16CtrlUnknownStopCount = (stCtrlCommonInfo_ptr->u16CtrlUnknownStopCount > 5000)?5000 :stCtrlCommonInfo_ptr->u16CtrlUnknownStopCount; 
  }else {
    stCtrlCommonInfo_ptr->u16CtrlUnknownStopCount = 0;
  }

  if (stCtrlCommonInfo_ptr->u16CtrlUnknownStopCount > u16UnknownStopWaitTime)  {
    stCtrlCommonInfo_ptr->u8CtrlUnknownStopFlag = 1;
    stCtrlCommonInfo_ptr->u8CtrlSubstate = CTRL_CTRL_SUBSTATE_STOP_LONG;
  }else if(stCtrlCommonInfo_ptr->u16CtrlUnknownStopCount > 400){
    stCtrlCommonInfo_ptr->u8CtrlUnknownStopFlag = 0;
    stCtrlCommonInfo_ptr->u8CtrlSubstate = CTRL_CTRL_SUBSTATE_STOP_LONG;//规划判断是否是最后一段路报完成
  }else {
    stCtrlCommonInfo_ptr->u8CtrlUnknownStopFlag = 0;
  }

    return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_WheelStopByDistanceChange

  * EXPLANATION
Sometimes ESC speed signal is not precise, we need to use the wheel impulse 
signals to judge whether the vehicle is really stopped. 

*************************************************************************
*/

// uint8_t Ctrl_WheelStopByDistanceChange(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
//                                        tCtrlVehiclePosition*       stCurrentPos_ptr)
// {

//     uint8_t u8VehStopFlag = 0;

//     if(fabsf(stCtrlCommonInfo_ptr->f32RecordedDistanceTravel - stCurrentPos_ptr->f32Track) < 0.000001)
//     {
//         u8VehStopFlag = 1;
//     }
//     else
//     {
//         u8VehStopFlag = 0;
//     }
//     stCtrlCommonInfo_ptr->f32RecordedDistanceTravel = stCurrentPos_ptr->f32Track;
//     stCtrlCommonInfo_ptr->u8VehStopByTravelDisFlag  = u8VehStopFlag;

//     return E_OK;
// }

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_FinishDetermination

  * EXPLANATION
This function aims to determine whether APA parking status can be finished(fail/complete)
*************************************************************************
*/
uint8_t Ctrl_FinishDetermination(tPathPlannerInfo*         stPathPlannerInfo_ptr,
                                 tCtrlCommonInfo*          stCtrlCommonInfo_ptr)
{
  // --- Finish is determinated in decision module. 
  if (CTRL_ACTION_FINISH == stPathPlannerInfo_ptr->u8VehicleActionRequest || 
      stCtrlCommonInfo_ptr->eCtrlChockedTypeFlag == CONTROL_CHOCKED_ROLL_BACK||
      stCtrlCommonInfo_ptr->eCtrlChockedTypeFlag == CONTROL_CHOCKED_VERTICAL||
      stCtrlCommonInfo_ptr->eCtrlChockedTypeFlag == CONTROL_CHOCKED_HORIZONTAL||
      stCtrlCommonInfo_ptr->u8CtrlUnknownStopFlag == 1){
    stCtrlCommonInfo_ptr->u8FinishActionFlag = 1;   // 控制主动退出的都让控制g_stCtrlCommonInfo.eCtrlFuncStatus= CTRL_MODULE_FINISH . 
  }

/*===========================
*	Error code record, to be simplified with decision.  
*==========================*/     
  // // --- Success
  // if (1 == Ctrl_Finish_ParkComplete(stPathPlannerInfo_ptr)){
  //       // u8TakeFinishActionFlag = 1;
  // }else if (1 == Ctrl_Finish_PebComplete(stCtrlCommonInfo_ptr)){
  //   // u8TakeFinishActionFlag = 1;
  // }else if (1 == Ctrl_Finish_PathGearP(stPathPlannerInfo_ptr)){
  //   // u8TakeFinishActionFlag = 1;
  // }else if (1 == Ctrl_Finish_ChockComplete(stCtrlCommonInfo_ptr)){
  //   // u8TakeFinishActionFlag = 1;
  // }
  // // --- Fail
  // else if (1 == Ctrl_Finish_InvalidPath(stPathPlannerInfo_ptr)){
  //   // u8TakeFinishActionFlag = 1;
  // }else if (1 == Ctrl_Finish_UnknownLongStop(stCtrlCommonInfo_ptr)){
  //   // u8TakeFinishActionFlag = 1;
  // }else if (1 == Ctrl_Finish_Trapped(stCtrlCommonInfo_ptr)){
  //   // u8TakeFinishActionFlag = 1;
  // }else {
  //   // u8TakeFinishActionFlag = 0;
  // }
  return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_FinishActionCommon

  * EXPLANATION
Finish actions.

*************************************************************************
*/

uint8_t Ctrl_FinishActionCommon(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                tCtrlToChassisInfo*       stCtrl2ChassisInfo_ptr,
                                tVehDataRx*                stVehDataRx_ptr)
{
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
    float f32RegardAsStopSpd = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32RegardAsStopSpeed;

    if (1 == stCtrlCommonInfo_ptr->u8FinishActionFlag)
    {
        if (stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph < f32RegardAsStopSpd || 1 == stCtrlCommonInfo_ptr->u8FixPGearFlag)
        {
            stCtrl2ChassisInfo_ptr->eGearReq        = P_GEAR;      // VEHI_GEAR_P;
            stCtrlCommonInfo_ptr->u8FixPGearFlag = 1;
        }
        else
        {
            stCtrl2ChassisInfo_ptr->eGearReq        = stVehDataRx_ptr->sVehVCUInfo.eVehActualGear;
        }

        if (1 == Ctrl_GetVehicleStopFlag(stVehDataRx_ptr))
        {
            stCtrlCommonInfo_ptr->eCtrlFinishType = CTRL_FINISH_TYPE_APA;
        }
        else 
        {
            stCtrlCommonInfo_ptr->eCtrlFinishType = CTRL_FINISH_TYPE_NONE;
        }
    }

    return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_ApaStraightFinishDetermination

  * EXPLANATION
This function aims to determine whether APA parking status can be finished(fail/complete)
*************************************************************************
*/
uint8_t Ctrl_ApaStraightFinishDetermination(tCtrlFuncFsmInfo*	   stCtrlApaShellInfo_ptr,
                                            tCtrlCommonInfo*       stCtrlCommonInfo_ptr)
{
    if (DRIVER_CTRL_STRAIGHT_FINISH == stCtrlApaShellInfo_ptr->eLsadDriverCtrlCommand)
    {
        stCtrlCommonInfo_ptr->u8FinishActionFlag = 1;
    }
    else 
    {
        stCtrlCommonInfo_ptr->u8FinishActionFlag = 0;
    }

    return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_FindNearestPathPoint

  * EXPLANATION
The matching point is determined by calculating the minimum relative 
distance.

*************************************************************************
*/

uint8_t Ctrl_FindNearestPathPoint(tPathPlannerInfo*     stPathPlannerInfo_ptr,
                                  tCtrlCommonInfo*      stCtrlCommonInfo_ptr,
                                  tCtrlVehPose*         stCtrlVehPose_ptr)
{
    uint8_t u8TotalNum    = stPathPlannerInfo_ptr->u8PointNum;
    float   dr_CurX       = stCtrlVehPose_ptr->stCurrentPos.f32X_Coor;
    float   dr_CurY       = stCtrlVehPose_ptr->stCurrentPos.f32Y_Coor;
    float   dr_SelectedX  = stCtrlVehPose_ptr->stSelectedPos.f32X_Coor;
    float   dr_SelectedY  = stCtrlVehPose_ptr->stSelectedPos.f32Y_Coor;
    float   f32MinDisCur     = 0.0f;
    float   f32MinDisCurTemp = 0.0f;
    float   f32MinDisSelect     = 0.0f;
    float   f32MinDisSelectTemp = 0.0f;   
    uint8_t u8NearPointIndexCur     = 0;
    uint8_t u8NearPointIndexSelect  = 0;

    for (int i = 0; i < u8TotalNum; i ++)
    {
        float p_x = stPathPlannerInfo_ptr->stPathData[i].f32WayPointX;
        float p_y = stPathPlannerInfo_ptr->stPathData[i].f32WayPointY;

        f32MinDisCurTemp = Ctrl_Point2Point_DisCalcu(dr_CurX, dr_CurY, p_x, p_y);
        f32MinDisSelectTemp = Ctrl_Point2Point_DisCalcu(dr_SelectedX, dr_SelectedY, p_x, p_y);

        if (0 == i)
        {
            f32MinDisCur = f32MinDisCurTemp;
            u8NearPointIndexCur = 0;
            f32MinDisSelect = f32MinDisSelectTemp;
            u8NearPointIndexSelect = 0;
        }
        else
        {
            // --- Find the nearest point index of current vehicle pose.
            if (f32MinDisCurTemp < f32MinDisCur)
            {
                f32MinDisCur = f32MinDisCurTemp;
                u8NearPointIndexCur = (uint8_t)i;
            }
            
            // --- Find the nearest point index of selected vehicle pose, it could be the predictive vehicle position.
            if (f32MinDisSelectTemp < f32MinDisSelect)
            {
                f32MinDisSelect = f32MinDisSelectTemp;
                u8NearPointIndexSelect = (uint8_t)i;
            }
        }
    }

    stCtrlCommonInfo_ptr->u8NearestPointIndexCurPose = u8NearPointIndexCur;
    stCtrlCommonInfo_ptr->u8NearestPointIndexSelectedPose = u8NearPointIndexSelect;

    return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_FindNearestBehindPathPoint

  * EXPLANATION
Find the front and behind reference path point.

*************************************************************************
*/

uint8_t Ctrl_FindNearestBehindPathPoint(tPathPlannerInfo*     stPathPlannerInfo_ptr,
                                        tCtrlCommonInfo*      stCtrlCommonInfo_ptr,
                                        tCtrlVehPose*         stCtrlVehPose_ptr)
{
    uint8_t u8TotalNum    = stPathPlannerInfo_ptr->u8PointNum;
    uint8_t u8NearPointIndexCur = stCtrlCommonInfo_ptr->u8NearestPointIndexSelectedPose;
    float   f32VehPosX       = stCtrlVehPose_ptr->stSelectedPos.f32X_Coor;
    float   f32VehPosY       = stCtrlVehPose_ptr->stSelectedPos.f32Y_Coor; 
    float   f32BoundaryTheta = 0;
    float   dr_Nearestdx         = stPathPlannerInfo_ptr->stPathData[u8NearPointIndexCur].f32WayPointX;
    float   dr_Nearestdy         = stPathPlannerInfo_ptr->stPathData[u8NearPointIndexCur].f32WayPointY;
    float   dr_FrontNearestdx    = stPathPlannerInfo_ptr->stPathData[u8NearPointIndexCur].f32WayPointX;
    float   dr_FrontNearestdy    = stPathPlannerInfo_ptr->stPathData[u8NearPointIndexCur].f32WayPointY;
    float   dr_BehindNearestdx   = stPathPlannerInfo_ptr->stPathData[u8NearPointIndexCur].f32WayPointX;
    float   dr_BehindNearestdy   = stPathPlannerInfo_ptr->stPathData[u8NearPointIndexCur].f32WayPointY;
    float   f32DistanceFront = 0;
    float   f32DistanceBehind = 0;
    uint8_t dr_FrontNearestIndex = 0;
    uint8_t dr_BehindNearestIndex = 0;
    int8_t  i8Direction = 0;

    if(u8TotalNum < 2)
    {
        dr_BehindNearestIndex = 0;
        dr_FrontNearestIndex = 0;
        if(0 == u8TotalNum)
        {
            f32DistanceFront = 0;
            f32DistanceBehind = 0;
        }
        else
        {
            dr_FrontNearestdx = stPathPlannerInfo_ptr->stPathData[0].f32WayPointX;
            dr_FrontNearestdy = stPathPlannerInfo_ptr->stPathData[0].f32WayPointY;
            f32DistanceFront = sqrtf((f32VehPosX - dr_FrontNearestdx) * (f32VehPosX - dr_FrontNearestdx) + (f32VehPosY - dr_FrontNearestdy) * (f32VehPosY - dr_FrontNearestdy));
            f32DistanceBehind = f32DistanceFront;
        }
    }
    else if(u8NearPointIndexCur == 0)
    {
        f32BoundaryTheta = stPathPlannerInfo_ptr->stPathData[0].f32WayPointTheta;
        i8Direction = (f32VehPosX - stPathPlannerInfo_ptr->stPathData[0].f32WayPointX) * cosf(f32BoundaryTheta) + (f32VehPosY - stPathPlannerInfo_ptr->stPathData[0].f32WayPointY) * sinf(f32BoundaryTheta);
        if(i8Direction <= 0)
        {
            dr_BehindNearestIndex = 0;
            dr_FrontNearestIndex = 0;

            dr_FrontNearestdx = stPathPlannerInfo_ptr->stPathData[0].f32WayPointX;
            dr_FrontNearestdy = stPathPlannerInfo_ptr->stPathData[0].f32WayPointY;
            f32DistanceFront = sqrtf((f32VehPosX - dr_FrontNearestdx) * (f32VehPosX - dr_FrontNearestdx) + (f32VehPosY - dr_FrontNearestdy) * (f32VehPosY - dr_FrontNearestdy));
            f32DistanceBehind = f32DistanceFront;
        }
        else
        {
            dr_BehindNearestIndex = 0;
            dr_FrontNearestIndex = 1;

            dr_FrontNearestdx = stPathPlannerInfo_ptr->stPathData[1].f32WayPointX;
            dr_FrontNearestdy = stPathPlannerInfo_ptr->stPathData[1].f32WayPointY;
            f32DistanceFront = sqrtf((f32VehPosX - dr_FrontNearestdx) * (f32VehPosX - dr_FrontNearestdx) + (f32VehPosY - dr_FrontNearestdy) * (f32VehPosY - dr_FrontNearestdy));

            dr_BehindNearestdx = stPathPlannerInfo_ptr->stPathData[0].f32WayPointX;
            dr_BehindNearestdy = stPathPlannerInfo_ptr->stPathData[0].f32WayPointY;
            f32DistanceBehind = sqrtf((f32VehPosX - dr_BehindNearestdx) * (f32VehPosX - dr_BehindNearestdx) + (f32VehPosY - dr_BehindNearestdy) * (f32VehPosY - dr_BehindNearestdy));
        }
    }
    else if(u8NearPointIndexCur == u8TotalNum - 1)
    {
        f32BoundaryTheta = stPathPlannerInfo_ptr->stPathData[u8TotalNum - 1].f32WayPointTheta;
        i8Direction = (f32VehPosX - dr_FrontNearestdx) * cosf(f32BoundaryTheta) + (f32VehPosY - dr_FrontNearestdy) * sinf(f32BoundaryTheta);
        if(i8Direction >= 0)
        {
            dr_BehindNearestIndex = u8TotalNum - 1;
            dr_FrontNearestIndex = u8TotalNum - 1;

            dr_FrontNearestdx = stPathPlannerInfo_ptr->stPathData[u8TotalNum - 1].f32WayPointX;
            dr_FrontNearestdy = stPathPlannerInfo_ptr->stPathData[u8TotalNum - 1].f32WayPointY;
            f32DistanceFront = sqrtf((f32VehPosX - dr_FrontNearestdx) * (f32VehPosX - dr_FrontNearestdx) + (f32VehPosY - dr_FrontNearestdy) * (f32VehPosY - dr_FrontNearestdy));
            f32DistanceBehind = f32DistanceFront;
        }
        else
        {
            dr_BehindNearestIndex = u8TotalNum - 2;
            dr_FrontNearestIndex = u8TotalNum - 1;

            dr_FrontNearestdx = stPathPlannerInfo_ptr->stPathData[u8TotalNum - 1].f32WayPointX;
            dr_FrontNearestdy = stPathPlannerInfo_ptr->stPathData[u8TotalNum - 1].f32WayPointY;
            f32DistanceFront = sqrtf((f32VehPosX - dr_FrontNearestdx) * (f32VehPosX - dr_FrontNearestdx) + (f32VehPosY - dr_FrontNearestdy) * (f32VehPosY - dr_FrontNearestdy));

            dr_BehindNearestdx = stPathPlannerInfo_ptr->stPathData[u8TotalNum - 2].f32WayPointX;
            dr_BehindNearestdy = stPathPlannerInfo_ptr->stPathData[u8TotalNum - 2].f32WayPointY;
            f32DistanceBehind = sqrtf((f32VehPosX - dr_BehindNearestdx) * (f32VehPosX - dr_BehindNearestdx) + (f32VehPosY - dr_BehindNearestdy) * (f32VehPosY - dr_BehindNearestdy));
        }
    }
    else
    {
        dr_FrontNearestdx = stPathPlannerInfo_ptr->stPathData[u8NearPointIndexCur + 1].f32WayPointX;
        dr_FrontNearestdy = stPathPlannerInfo_ptr->stPathData[u8NearPointIndexCur + 1].f32WayPointY;
        dr_BehindNearestdx = stPathPlannerInfo_ptr->stPathData[u8NearPointIndexCur - 1].f32WayPointX;
        dr_BehindNearestdy = stPathPlannerInfo_ptr->stPathData[u8NearPointIndexCur - 1].f32WayPointY;
        f32DistanceFront = sqrtf((f32VehPosX - dr_FrontNearestdx) * (f32VehPosX - dr_FrontNearestdx) + (f32VehPosY - dr_FrontNearestdy) * (f32VehPosY - dr_FrontNearestdy));
        f32DistanceBehind = sqrtf((f32VehPosX - dr_BehindNearestdx) * (f32VehPosX - dr_BehindNearestdx) + (f32VehPosY - dr_BehindNearestdy) * (f32VehPosY - dr_BehindNearestdy));

        if(f32DistanceFront  <= f32DistanceBehind)
        {
            dr_BehindNearestIndex = u8NearPointIndexCur;
            dr_FrontNearestIndex = u8NearPointIndexCur + 1; 
            f32DistanceBehind = sqrtf((f32VehPosX - dr_Nearestdx) * (f32VehPosX - dr_Nearestdx) + (f32VehPosY - dr_Nearestdy) * (f32VehPosY - dr_Nearestdy));
        } 
        else
        {
            dr_BehindNearestIndex = u8NearPointIndexCur - 1;
            dr_FrontNearestIndex  = u8NearPointIndexCur;
            f32DistanceFront = sqrtf((f32VehPosX - dr_Nearestdx) * (f32VehPosX - dr_Nearestdx) + (f32VehPosY - dr_Nearestdy) * (f32VehPosY - dr_Nearestdy));
        }
    }
    
    stCtrlCommonInfo_ptr->u8FrontPointIndex       = dr_FrontNearestIndex;   // u8FrontNearestPointIndexCurPose
    stCtrlCommonInfo_ptr->u8BehindPointIndex      = dr_BehindNearestIndex;
    stCtrlCommonInfo_ptr->f32FrontPointDistance   = f32DistanceFront;
    stCtrlCommonInfo_ptr->f32BehindPointDistance  = f32DistanceBehind;
    stCtrlCommonInfo_ptr->u16RecPathID            = stPathPlannerInfo_ptr->u16PathId;

    return E_OK;
}

/*	=====================================================================
 *
 *						static function definitions 
 *
 *	===================================================================*/



/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_Steering_Compensation

  * EXPLANATION
Wheel2Steer compensation factor. 

Optional: Use the DistanceLeft to adjust the compensation factor.
But we should try to make the factor as simple as possible, otherwise it 
would be difficult to calibrate. 

*************************************************************************
*/

static uint8_t Ctrl_Steering_Compensation(tCtrlLatResult*        stCtrlLatResult_ptr,
                                          tPathPlannerInfo*      stPathPlannerInfo_ptr)
{

    if (1 == stPathPlannerInfo_ptr->u8LastPathFlag && DF_PL_TYPE_Horizontal != stPathPlannerInfo_ptr->eCtrlPldType)
    {
        stCtrlLatResult_ptr->f32WheelToSteerRatioFactor = 1;
    }
    else
    {
        stCtrlLatResult_ptr->f32WheelToSteerRatioFactor = 1;
    }

    return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_Finish_XXXX

  * EXPLANATION
Different kinds of finish situations.
*************************************************************************
*/

/*===========================
*	      Completed
*==========================*/

static uint8_t Ctrl_Finish_ParkComplete(tPathPlannerInfo*   stPathPlannerInfo_ptr)
{
    if(1 == stPathPlannerInfo_ptr->u8NoNewPathFlag)
    {
        Ctrl_DiagSetParkErrCode(CTRL_ERR_PARK_COMPLETE);
        PRINTF_HDSK("Finish: Ctrl_PathReq_Complete\r\n");
        return 1;
    }

    return 0;
}

static uint8_t Ctrl_Finish_PebComplete(tCtrlCommonInfo*    stCtrlCommonInfo_ptr)
{
    if(1 == stCtrlCommonInfo_ptr->u8PebParkCompleteFlag)
    {
        Ctrl_DiagSetParkErrCode(CTRL_ERR_PARK_NEAR_END_POSE_VERTICAL);      // To delete _VERTICAL. 
        PRINTF_HDSK("Finish: USS detect Complete\r\n");
        return 1;
    }

    return 0;
}

static uint8_t Ctrl_Finish_PathGearP(tPathPlannerInfo*   stPathPlannerInfo_ptr)
{
    if (P_GEAR == stPathPlannerInfo_ptr->u8Shift)
    {
        Ctrl_DiagSetParkErrCode(CTRL_ERR_PARK_PATH_P_GEAR);
        PRINTF_HDSK("Finish: P gear detected \r\n");
        return 1;
    }

    return 0;
}

static uint8_t Ctrl_Finish_ChockComplete(tCtrlCommonInfo*    stCtrlCommonInfo_ptr)
{
    if(1 == stCtrlCommonInfo_ptr->eCtrlChockedTypeFlag == CONTROL_CHOCKED_VERTICAL)
    {
        if (1 == stCtrlCommonInfo_ptr->u8CtrlVerticalChockedFlag)
        {
            Ctrl_DiagSetParkErrCode(CTRL_ERR_PARK_VERTICAL_CHOCK);
        }
        else if (stCtrlCommonInfo_ptr->eCtrlChockedTypeFlag == CONTROL_CHOCKED_HORIZONTAL)
        {
            Ctrl_DiagSetParkErrCode(CTRL_ERR_PARK_HORIZONTAL_CHOCK);
        }
        else if (stCtrlCommonInfo_ptr->eCtrlChockedTypeFlag == CONTROL_CHOCKED_ROLL_BACK)
        {
            Ctrl_DiagSetParkErrCode(CTRL_ERR_PARK_GENERAL_CHOCK);
        }
        
        PRINTF_HDSK("Finish: Chock Detect \r\n");
        return 1;
    }

    return 0;
}

/*===========================
*	        Failed
*==========================*/

static uint8_t Ctrl_Finish_WaitNewPathTimeOut(tCtrlCommonInfo*  stCtrlCommonInfo_ptr)
{
    if (1 == stCtrlCommonInfo_ptr->u8WaitNewPathTimeoutFlag)
    {
        Ctrl_DiagSetParkErrCode(CTRL_ERR_PARK_WAIT_NEW_PATH_TIMEOUT);
        PRINTF_HDSK("Finish: CAN Not Obtain New Path\r\n");
        return 1;
    }

    return 0;
}

static uint8_t Ctrl_Finish_InvalidPath(tPathPlannerInfo*   stPathPlannerInfo_ptr)
{
    if (1 == stPathPlannerInfo_ptr->u8PathInvalidFlag)
    {
        Ctrl_DiagSetParkErrCode(CTRL_ERR_PARK_PP_STS_INVALID);
        PRINTF_HDSK("Finish: No Valid Path\r\n");
        return 1;
    }

    return 0;
}

static uint8_t Ctrl_Finish_UnknownLongStop(tCtrlCommonInfo*  stCtrlCommonInfo_ptr)
{
    if (1 == stCtrlCommonInfo_ptr->u8CtrlUnknownStopFlag)
    {
        Ctrl_DiagSetParkErrCode(CTRL_ERR_PARK_UNKNOWN_LONG_STOP);
        PRINTF_HDSK("Finish: Unknown long stop\r\n");
        return 1;
    }

    return 0;
}

static uint8_t Ctrl_Finish_Trapped(tCtrlCommonInfo*  stCtrlCommonInfo_ptr)
{
    if (1 == stCtrlCommonInfo_ptr->u8CtrlTrapFlag)
    {
        Ctrl_DiagSetParkErrCode(CTRL_ERR_PARK_TRAPPED);
        PRINTF_HDSK("Finish: Trapped\r\n");
        return 1;
    }

    return 0;
}

static uint8_t Ctrl_Finish_ReplanFailed(tPathPlannerInfo*   stPathPlannerInfo_ptr)
{
    if(stPathPlannerInfo_ptr->u8PlanResult >= 10)	// ==2 change to >= 10
    {
        Ctrl_DiagSetParkErrCode(CTRL_ERR_PARK_PP_REPLAN_INVALID);
        PRINTF_HDSK("Finish: Path Plan Hard Fail\r\n");
        return 1;
    }

    return 0;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_GetVehicleStopFlag

  * EXPLANATION
This function aims to get whether vehicle stopped
*************************************************************************
*/
static uint8_t Ctrl_GetVehicleStopFlag(tVehDataRx*   stVehDataRx_ptr)
{
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
    float f32RegardAsStopSpd = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32RegardAsStopSpeed;
    
    if( fabs(stVehDataRx_ptr->sVehEPSInfo.f32StrWhlAngDeg) < 15.0f && P_GEAR == stVehDataRx_ptr->sVehVCUInfo.eVehActualGear &&
            stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph < f32RegardAsStopSpd && 3 == g_stCtrlLatInfo.u8ReleaseTirePressurePhase)
    {
        return 1;
    }

    return 0;
}



/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_InstanceRadiusCal.

  * EXPLANATION
This function uses current steer angle to calculate turning radius

*************************************************************************
*/
float Ctrl_InstanceRadiusCal(tVehDataRx*   stVehDataRx_ptr)
{

    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();

    float f32Steer2WheelRatio  = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32SteerRatioDefault;
    float f32WheelBase = stCalibPF_ptr->stPFVehCalib.Calib_f32WhlBase;
    float f32WheelAngle = DegToRad(stVehDataRx_ptr->sVehEPSInfo.f32StrWhlAngDeg/f32Steer2WheelRatio);
    float f32InstantRadius = 0;

    if (fabs(f32WheelAngle) > 0.001)
    {
        f32InstantRadius = f32WheelBase / tanf(f32WheelAngle);
    }
    else
    {
        f32InstantRadius = f32WheelBase / 0.001;
    }
    

    // float f32SteerCub = stChassis2CtrlInfo_ptr->f32SteerWheelAngle * stChassis2CtrlInfo_ptr->f32SteerWheelAngle * stChassis2CtrlInfo_ptr->f32SteerWheelAngle;
    // float f32SteerSqr = stChassis2CtrlInfo_ptr->f32SteerWheelAngle * stChassis2CtrlInfo_ptr->f32SteerWheelAngle;
    // float f32Steer    = stChassis2CtrlInfo_ptr->f32SteerWheelAngle;

    // if (VEHI_GEAR_D == stChassis2CtrlInfo_ptr->eCtrlVehGear)  //Change to wheel dir
    // {
    //     if(stChassis2CtrlInfo_ptr->f32SteerWheelAngle > 0)
    //     {
    //         f32Steer2WheelRatio = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32FLP3 *f32SteerCub + stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32FLP2*f32SteerSqr + stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32FLP1*f32Steer + stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32FLP0;
    //         f32WheelAngle = stChassis2CtrlInfo_ptr->f32SteerWheelAngle/f32Steer2WheelRatio;
    //         f32InstantRadius = stCalibPF_ptr->stPFVehCalib.Calib_f32WhlBase / tanf(DegToRad(f32WheelAngle));
    //     }
    //     else
    //     {
    //         f32Steer2WheelRatio = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32FRP3 *f32SteerCub + stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32FRP2*f32SteerSqr + stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32FRP1*f32Steer + stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32FRP0;
    //         f32WheelAngle = stChassis2CtrlInfo_ptr->f32SteerWheelAngle/f32Steer2WheelRatio;
    //         f32InstantRadius = stCalibPF_ptr->stPFVehCalib.Calib_f32WhlBase / tanf(DegToRad(f32WheelAngle));
    //     }
    // }
    // else if (VEHI_GEAR_R == stChassis2CtrlInfo_ptr->eCtrlVehGear) //Change to wheel dir
    // {
    //     if(stChassis2CtrlInfo_ptr->f32SteerWheelAngle > 0)
    //     {
    //         f32Steer2WheelRatio = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32RLP3 *f32SteerCub + stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32RLP2*f32SteerSqr + stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32RLP1*f32Steer + stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32RLP0;
    //         f32WheelAngle = stChassis2CtrlInfo_ptr->f32SteerWheelAngle/f32Steer2WheelRatio;
    //         f32InstantRadius = stCalibPF_ptr->stPFVehCalib.Calib_f32WhlBase / tanf(DegToRad(f32WheelAngle));
    //     }
    //     else
    //     {
    //         f32Steer2WheelRatio = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32RRP3 *f32SteerCub + stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32RRP2*f32SteerSqr + stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32RRP1*f32Steer + stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32RRP0;
    //         f32WheelAngle = stChassis2CtrlInfo_ptr->f32SteerWheelAngle/f32Steer2WheelRatio;
    //         f32InstantRadius = stCalibPF_ptr->stPFVehCalib.Calib_f32WhlBase / tanf(DegToRad(f32WheelAngle));
    //     }
    // }
    // else
    // {
    //     ;
    // }

    return f32InstantRadius;
}



/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_FuturePositionPrediction.

  * EXPLANATION
This function uses current vehicle position and chassis info to predict future position

*************************************************************************
*/

uint8_t Ctrl_FuturePositionPrediction(tCtrlVehPose*             stCtrlVehPose_ptr,
                                      tVehDataRx*   stVehDataRx_ptr,
                                      tPathPlannerInfo*         stPathPlannerInfo_ptr,
                                      tCtrlCommonInfo*          stCtrlCommonInfo_ptr)
{
    tCtrlVehiclePosition*  stCurrentPos_ptr = &stCtrlVehPose_ptr->stCurrentPos; 
    tCtrlPredictDrPose*  stPredictPose_ptr = &stCtrlVehPose_ptr->stPredictPos;
    float f32VehSpd = stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph / 3.6;
    float f32DeltaTheta = 0;
    float f32DeltaDis =  f32VehSpd * stPredictPose_ptr->f32TimeGap;
    float f32InstanceTurningRadius = Ctrl_InstanceRadiusCal(stVehDataRx_ptr);


    f32DeltaDis = f32DeltaDis * (stPathPlannerInfo_ptr->i8CtrlGearFactor);
    f32DeltaTheta  = f32DeltaDis/f32InstanceTurningRadius;

    stPredictPose_ptr->f32FutureDRPoseX = stCurrentPos_ptr->f32X_Coor + f32DeltaDis * cosf(stCurrentPos_ptr->f32Theta + 0.5*f32DeltaTheta) ;
    stPredictPose_ptr->f32FutureDRPoseY = stCurrentPos_ptr->f32Y_Coor + f32DeltaDis * sinf(stCurrentPos_ptr->f32Theta + 0.5*f32DeltaTheta) ;
    stPredictPose_ptr->f32FutureDRTheta = stCurrentPos_ptr->f32Theta + f32DeltaTheta;
//    stPredictPose_ptr->f32FutureDRTheta =  stCurrentPos_ptr->f32Theta;

    if (stPredictPose_ptr->f32FutureDRTheta > CTRL_180DEG)
    {
        stPredictPose_ptr->f32FutureDRTheta = stPredictPose_ptr->f32FutureDRTheta - CTRL_360DEG ;
    }

    else if (stPredictPose_ptr->f32FutureDRTheta < -CTRL_180DEG)
    {
        stPredictPose_ptr->f32FutureDRTheta = stPredictPose_ptr->f32FutureDRTheta + CTRL_360DEG ;
    }

    return E_OK;
}


uint8_t Ctrl_UpdateCtrlState(tVehDataRx*   stVehDataRx_ptr,
                             tCtrlLongiInfo*       stCtrlLongiInfo_ptr,
                             tCtrl_StateInfo*   stCtrl2PP_State_Info_ptr,
                             tCtrlCommonInfo*     stCtrlCommonInfo_ptr,
                             tPathPlannerInfo*    stPathPlannerInfo_ptr)
{
  if ((((R_GEAR == stVehDataRx_ptr->sVehVCUInfo.eVehActualGear) && (R_GEAR == stPathPlannerInfo_ptr->u8Shift)) || 
       ((D_GEAR == stVehDataRx_ptr->sVehVCUInfo.eVehActualGear) && (D_GEAR == stPathPlannerInfo_ptr->u8Shift)))){
    if (1 == stCtrlLongiInfo_ptr->u8EmergStoppedFlag && stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebHappened == 1){
      stCtrlCommonInfo_ptr->u8CtrlSubstate = CTRL_CTRL_SUBSTATE_STOP_PEB;
    }else{
      ;
    }
    if (1 == stCtrlLongiInfo_ptr->u8CurrentPathFinishedFlag){
      if (CTRL_ACTION_STOP == stPathPlannerInfo_ptr->u8VehicleActionRequest){
        stCtrlCommonInfo_ptr->u8CtrlSubstate = 3;//CTRL_CTRL_SUBSTATE_STOP_PP
      }else{
        stCtrlCommonInfo_ptr->u8CtrlSubstate = CTRL_CTRL_SUBSTATE_STOP_REACH;
      }
    }
  }

  if (CTRL_CTRL_SUBSTATE_STOP_NONE != stCtrlCommonInfo_ptr->u8CtrlSubstate){
    stCtrlCommonInfo_ptr->u8CtrlState = CTRL_CTRL_STATE_STOP;
  }
  else if(1 == stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebHappened){
        stCtrlCommonInfo_ptr->u8CtrlState = 3 ;//CTRL_CTRL_STATE_STOP_REDUCT=3//EB刹停的过程中，让规划知道EB正在刹车，不要进行重规划;
  }else{   
      stCtrlCommonInfo_ptr->u8CtrlState = CTRL_CTRL_STATE_NONE;
  }

  stCtrl2PP_State_Info_ptr->u16CurPathid   = stCtrlCommonInfo_ptr->u16CurrentPathID;
  stCtrl2PP_State_Info_ptr->u8PathPEBDir   = stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebDir;
  stCtrl2PP_State_Info_ptr->u8CtrlState    = (uint8_t)stCtrlCommonInfo_ptr->u8CtrlState;
  stCtrl2PP_State_Info_ptr->u8CtrlSubstate = (uint8_t)stCtrlCommonInfo_ptr->u8CtrlSubstate;

    return E_OK;
}




/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_LpfCalculation

  * EXPLANATION
Low pass filter

*************************************************************************
*/

uint8_t Ctrl_LpfCalculation(tCtrlLowPassFilterPara*   stCtrlLpfLat_ptr)
{
    stCtrlLpfLat_ptr->f32LPF_filter_yk_1   =  stCtrlLpfLat_ptr->f32LPF_filter_yk;
    stCtrlLpfLat_ptr->f32LPF_filter_yk     =  - stCtrlLpfLat_ptr->f32LPF_den_2 * stCtrlLpfLat_ptr->f32LPF_filter_yk_1
                                             + stCtrlLpfLat_ptr->f32LPF_num_1 * stCtrlLpfLat_ptr->f32LPF_yk
                                             + stCtrlLpfLat_ptr->f32LPF_num_2 * stCtrlLpfLat_ptr->f32LPF_filter_yk_1;
    stCtrlLpfLat_ptr->f32LPF_yk_1          =  stCtrlLpfLat_ptr->f32LPF_yk;   // Raw previous value, not used

    return E_OK;
}
