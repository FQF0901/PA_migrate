#include <math.h>
#include "ctrl_apa_parking.h"
#include "ctrl_global_variables.h"
#include "peb/ctrl_peb_algo_new.h"
#include "lib_adas_adapter/vehicle_service/ctrl_adapter/ctrl_adapter.h"
#include "common/ctrl_comm_func.h"
#include "controller/ctrl_long_algo.h"
#include "controller/ctrl_lat_algo.h"
#include "controller/ctrl_lat_algo.h"
#include "vehicle_service/calib/vehsrv_calib.h"
#include "testroad/testroad.h"
#include "cruising/ctrl_cruising.h"

static uint8_t Ctrl_CommonProcessing(void);
static uint8_t Ctrl_LongiOutputProcessing(void);
static uint8_t Ctrl_LatOutputProcessing(void);
static uint8_t Ctrl_CommonPostProcessing(void);


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_Parking_Task_20ms

  * EXPLANATION
APA main task during APA parking.

*************************************************************************
*/

uint8_t Ctrl_Parking_Task_20ms()
{
    // vehicle on path, PEB, finish detect, etc.
    Ctrl_CommonProcessing();

    // Longitudinal control.
    Ctrl_LongiOutputProcessing();

    // Lateral control.
    Ctrl_LatOutputProcessing();

    // vehicle on path, PEB, finish detect, etc.
    Ctrl_CommonPostProcessing();

    return E_OK;
}



/*	=====================================================================
 *
 *						    static functions 
 *
 *	===================================================================*/


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_CommonProcessing

  * EXPLANATION
Common processing includes:
 - vehicle on path. 
 - PEB, and the replan & pause afterwards.
 - Gear shift.
 - new path request, finish detection.
 - interaction with CtrlSM and APAShell.

*************************************************************************
*/
static uint8_t Ctrl_CommonProcessing(void)
{
/*===========================
*	Vehicle detection 
*==========================*/
  control_WheelSpeedDirection_Opposite_gear(&g_stCtrlVehDataRx, &g_stCtrlCommonInfo);

/*===========================
*	Vehicle on Path 
*==========================*/
    // --- Update current path ID
    Ctrl_UpdateCurPathId(&g_stCtrlVehDataRx, &g_stCtrlLongiInfo, &g_stCtrlToPathPlannerInfo, &g_stCtrlCommonInfo, &g_stPathPlannerData);//modify to keep
    
    // --- Update vehicle position (DR) 
    Ctrl_FuturePositionPrediction(&g_stCtrlVehPose, &g_stCtrlVehDataRx, &g_stPathPlannerData, &g_stCtrlCommonInfo);
    Ctrl_SelectPoseForLateralCalcu(&g_stCtrlVehPose);

    // --- Vehicle refer to path
    Ctrl_FindNearestPathPoint(&g_stPathPlannerData, &g_stCtrlCommonInfo, &g_stCtrlVehPose);
    Ctrl_FindNearestBehindPathPoint(&g_stPathPlannerData, &g_stCtrlCommonInfo, &g_stCtrlVehPose);
    Ctrl_DistanceLeft(&g_stPathPlannerData);

/*===========================
*	Scenarios Detection  
*==========================*/     
    // --- PEB detection
    control_PEB_detection(&g_stCtrlCommonInfo, &g_stCtrlVehDataRx, &g_stCtrlUssInfo,
                          &g_stStateMachine, &g_stPathPlannerData,&g_stCtrlFuncFsmInfo,&g_stCtrlLongiInfo);
    Ctrl_ReqPause(&g_stCtrlCommonInfo, &g_stPathPlannerData);
    
    // --- Trapped detection
    // Ctrl_VehTrappedDetection(&g_stPathPlannerData, &g_stCtrlCommonInfo, &g_stCtrlVehDataRx);
    
    // --- Chocked detection
    Ctrl_WheelChock_Detection(&g_stCtrlCommonInfo, &g_stCtrlVehDataRx, &g_stPathPlannerData, &g_stCtrlToChassisInfo);
    Ctrl_UnknownLongStopDetection(&g_stCtrlVehDataRx, &g_stCtrlCommonInfo, &g_stCtrlToChassisInfo);
    
    // --- Finish detection
    Ctrl_FinishDetermination(&g_stPathPlannerData, &g_stCtrlCommonInfo);//modify to PP, PF send finish path to PP

/*===========================
*	Post-Processing   
*==========================*/                         
    // --- Gear request
    Ctrl_GearReq(&g_stPathPlannerData, &g_stCtrlVehDataRx, &g_stCtrlToChassisInfo, &g_stCtrlCommonInfo);

    // --- Event actions
    Ctrl_FinishActionCommon(&g_stCtrlCommonInfo, &g_stCtrlToChassisInfo, &g_stCtrlVehDataRx);//modify parking finish from PP

    return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_CommonPostProcessing

  * EXPLANATION
Common post processing includes:
 - PebInit.
 - CtrlState.

*************************************************************************
*/
static uint8_t Ctrl_CommonPostProcessing()
{

    Ctrl_UpdateCtrlState(&g_stCtrlVehDataRx, &g_stCtrlLongiInfo, &g_stCtrlToPathPlannerInfo, &g_stCtrlCommonInfo, &g_stPathPlannerData);

    return E_OK;
}



/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_LongiOutputProcessing

  * EXPLANATION
Longitudinal data processing. 
 - Target acceleration calculation, and send request to chassis.
 - Rest distance calculation, and send to chassis.
 - Target vehicle speed calculation, and send request to chassis.  

*************************************************************************
*/

static uint8_t Ctrl_LongiOutputProcessing(void)
{
/*===========================
*	Speed calculation 
*==========================*/
  // --- Trapozoid speed plan & control
  Ctrl_SpeedProfile(&g_stCtrlCommonInfo, &g_stCtrlLongiInfo, &g_stPathPlannerData);
  Ctrl_SpeedTrapozoidPhase(&g_stCtrlLatInfo, &g_stCtrlVehDataRx, &g_stCtrlCommonInfo, &g_stPathPlannerData, 
                           &g_stCtrlLongiInfo);
  Ctrl_TrapozoidSpeedCtrl(&g_stCtrlLongiInfo, &g_stCtrlCommonInfo, &g_stCtrlVehDataRx, &g_stPathPlannerData);
  Ctrl_SpeedPhaseTransitCondition(&g_stCtrlLongiInfo, &g_stCtrlVehDataRx);
  Ctrl_SpeedCompensation(&g_stPathPlannerData, &g_stCtrlCommonInfo, &g_stCtrlLongiInfo);

  // --- Trajectory speed control (Once enabled, trapozoid speed ctrl will be overridden.)
  //Ctrl_TrajSpeedCtrl(&g_stPathPlannerData, &g_stCtrlCommonInfo, &g_stCtrlLongiInfo);
  Ctrl_LongiVel(&g_stCtrlCommonInfo,&g_stPathPlannerData, &g_stTrjLongiCtroller,&g_stCtrlLongiInfo);
    

/*===========================
*	Acceleration calculation 
*==========================*/
  
  Ctrl_CalTargetAcce(&g_stCtrlLongiInfo, &g_stCtrlCommonInfo, &g_stCtrlVehDataRx, &g_stCtrlToChassisInfo,&g_stCtrlUssInfo);

/*===========================
*	Stop distance calculation 
*==========================*/
  Ctrl_CalStopDistance(&g_stCtrlLongiInfo, &g_stCtrlCommonInfo, &g_stCtrlVehDataRx);

/*===========================
*	Post-Processing 
*==========================*/
    // --- Event Actions
  Ctrl_ConflictGearAction(&g_stCtrlCommonInfo, &g_stCtrlVehDataRx, &g_stCtrlLongiInfo);
  Ctrl_FinishActionLongi(&g_stCtrlCommonInfo, &g_stCtrlVehDataRx, &g_stCtrlLongiInfo);

    // --- Deliver result & Limitation
	g_stCtrlToChassisInfo.f32CtrlReqSpeedUnlimited        = g_stCtrlLongiInfo.f32TargetVehSpeed;
  g_stCtrlToChassisInfo.f32CtrlReqAccelUnlimited        = g_stCtrlLongiInfo.f32TargetAcce;
  g_stCtrlToChassisInfo.f32CtrlReqStopDistanceUnlimited = g_stCtrlLongiInfo.f32TargetStopDistance;
  g_stCtrlToChassisInfo.eStandStillReq                  = g_stCtrlLongiInfo.eStandStillReq;
  g_stCtrlToChassisInfo.eAEBFlag                        = g_stCtrlLongiInfo.eAEBFlag;
  Ctrl_LimitationLongi(&g_stCtrlVehDataRx,&g_stCtrlLongiInfo,&g_stCtrlToChassisInfo, &g_stCtrlCommonInfo);

  return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_LatOutputProcessing

  * EXPLANATION
Lateral data processing.
 - Target steering wheel angle calculation, and send request to chassis.  

*************************************************************************
*/

static uint8_t Ctrl_LatOutputProcessing(void)
{
/*===========================
*	Lateral error calculation 
*==========================*/
    // --- Feedforward
    Ctrl_LqrPreviewSinglePoint(&g_stPathPlannerData, &g_stCtrlLongiInfo, &g_stCtrlLatInfo, &g_stCtrlCommonInfo, &g_stCtrlVehDataRx);
    Ctrl_LqrPreviewMultiPoints(&g_stPathPlannerData, &g_stCtrlCommonInfo, &g_stCtrlLatInfo);
    Ctrl_CurvatureSinglePointFilter(&g_stCtrlLatInfo);
    Ctrl_CurvatureMultiPointFilter(&g_stCtrlLatInfo);

    // --- Feedback
    Ctrl_GetLatErrTrajectoryFrame(&g_stPathPlannerData, &g_stCtrlVehPose.stSelectedPos, g_stCtrlCommonInfo.u8BehindPointIndex,
                                  g_stCtrlVehDataRx.sVehESCInfo.f32VehSpdKph, &g_stCtrlLatInfo, &g_stCtrlCommonInfo);
    Ctrl_DistErrorFilter(&g_stCtrlLatInfo);
    Ctrl_ThetaErrorFilter(&g_stCtrlLatInfo);

/*===========================
*	Feedback & feedforward controllers  
*==========================*/
    // --- Feedforward 
    Ctrl_CalFeedForwardAngle(&g_stCtrlLatInfo);

    // --- Feedback, LQR.
    Ctrl_CalLqrFeedbackAngle(&g_stCtrlLatInfo, &g_stPathPlannerData, &g_stCtrlLongiInfo, &g_stCtrlCommonInfo);

/*===========================
*	Post-Processing  
*==========================*/
    // --- Select Lqr feedback & feedforward result
    g_stCtrlLatInfo.stCtrlLatResult.f32FeedforwardAngle = g_stCtrlLatInfo.stCtrlLqr.f32SinglePointFeedforwardAngle;      // f32MultiPointFeedforwardAngle,f32SinglePointFeedforwardAngle
    g_stCtrlLatInfo.stCtrlLatResult.f32FeedbackAngleRaw = g_stCtrlLatInfo.stCtrlLqr.f32FeedbackAngleRaw;
    g_stCtrlLatInfo.stCtrlLatResult.f32FeedbackAngleFiltered = g_stCtrlLatInfo.stCtrlLatResult.f32FeedbackAngleRaw;     // No filter at feedback result side, it is done at lateral error side instead.
    g_stCtrlLatInfo.stCtrlLatResult.f32TargetWheelAngle = g_stCtrlLatInfo.stCtrlLatResult.f32FeedforwardAngle + g_stCtrlLatInfo.stCtrlLatResult.f32FeedbackAngleFiltered;

    // --- Wheel/steer, rad/degree conversion
    Ctrl_CalTargetSteerAngleRaw(&g_stPathPlannerData, &g_stCtrlCommonInfo, &g_stCtrlLatInfo,&g_stCtrlVehDataRx);
    
    // --- Event Actions
    Ctrl_StopSteerBackToZero(&g_stCtrlLongiInfo, &g_stCtrlCommonInfo, &g_stCtrlLatInfo);//delete 
    Ctrl_FinishActionLat(&g_stCtrlCommonInfo, &g_stCtrlLatInfo, &g_stCtrlVehDataRx, &g_stCtrlToChassisInfo);

    // --- Final filter
    Ctrl_TargetSteerOutputFilter(&g_stCtrlLatInfo);

    // --- Deliver result & limitation
    g_stCtrlToChassisInfo.f32CtrlReqSteerUnlimited = g_stCtrlLatInfo.stCtrlLatResult.f32TargetSteerAngleFiltered;
    Ctrl_LimitationLat(&g_stCtrlLongiInfo, &g_stCtrlCommonInfo, &g_stCtrlToChassisInfo);

    return E_OK;
}

