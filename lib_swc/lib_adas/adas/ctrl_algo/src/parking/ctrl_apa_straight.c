#include <math.h>
#include "parking/ctrl_apa_straight.h"
#include "ctrl_global_variables.h"
#include "ctrl_peb_algo_new.h"
#include "lib_adas_adapter/vehicle_service/ctrl_adapter/ctrl_adapter.h"
#include "common/ctrl_comm_func.h"
#include "controller/ctrl_long_algo.h"
#include "controller/ctrl_lat_algo.h"

static uint8_t Ctrl_CommonProcessing(void);
static uint8_t Ctrl_LongiOutputProcessing(void);
static uint8_t Ctrl_LatOutputProcessing(void);

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_Straight_Task_20ms

  * EXPLANATION
APA straight main task.

*************************************************************************
*/

uint8_t Ctrl_Straight_Task_20ms(void)
{
    // Common processing.
    Ctrl_CommonProcessing();

    // Longitudinal control.
    Ctrl_LongiOutputProcessing();

    // Lateral control.
    Ctrl_LatOutputProcessing();

    return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_CommonProcessing

  * EXPLANATION
Common processing includes:
 - PEB, detection.
 - Gear shift.
 - interaction with CtrlSM.

*************************************************************************
*/

static uint8_t Ctrl_CommonProcessing(void)
{
/*===========================
*	PEB
*==========================*/ 
    control_PEB_detection(&g_stCtrlCommonInfo, &g_stCtrlVehDataRx, &g_stCtrlUssInfo,
                          &g_stStateMachine, &g_stPathPlannerData,&g_stCtrlFuncFsmInfo, &g_stCtrlLongiInfo);

/*===========================
*	Finish detection  
*==========================*/   
    Ctrl_ApaStraightFinishDetermination(&g_stCtrlFuncFsmInfo, &g_stCtrlCommonInfo);

/*===========================
*	Post-Processing   
*==========================*/                         
    // --- Gear request
    Ctrl_ApaStraightGearReq(&g_stCtrlFuncFsmInfo, &g_stCtrlVehDataRx, &g_stCtrlToChassisInfo, &g_stCtrlCommonInfo);

    // --- Event Actions
    Ctrl_FinishActionCommon(&g_stCtrlCommonInfo, &g_stCtrlToChassisInfo, &g_stCtrlVehDataRx);

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
    Ctrl_ApaStraightSpeedCtrl(&g_stCtrlFuncFsmInfo, &g_stCtrlLongiInfo);

/*===========================
*	Acceleration calculation 
*==========================*/
    Ctrl_CalTargetAcce(&g_stCtrlLongiInfo, &g_stCtrlCommonInfo, &g_stCtrlVehDataRx,  &g_stCtrlToChassisInfo,&g_stCtrlUssInfo);

/*===========================
*	Stop distance calculation 
*==========================*/
    Ctrl_ApaStraighStopDistanceCtrl(&g_stCtrlFuncFsmInfo, &g_stCtrlCommonInfo, &g_stCtrlLongiInfo);

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
    Ctrl_LimitationLongi(&g_stCtrlVehDataRx,&g_stCtrlLongiInfo,&g_stCtrlToChassisInfo, &g_stCtrlCommonInfo);

    return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_LatOutputProcessing

  * EXPLANATION
APA Straight, steer is always zero. 

*************************************************************************
*/

static uint8_t Ctrl_LatOutputProcessing(void)
{
/*===========================
*	Post-Processing  
*==========================*/
    // --- Deliver result & limitation
    g_stCtrlToChassisInfo.f32CtrlReqSteerUnlimited = 0;
    Ctrl_LimitationLat(&g_stCtrlLongiInfo, &g_stCtrlCommonInfo, &g_stCtrlToChassisInfo);

    return E_OK;
}
