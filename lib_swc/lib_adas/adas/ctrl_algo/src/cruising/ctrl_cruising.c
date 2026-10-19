/*
 * Ctrl_Cursing.c
 *
 *  Created on: Jul 13, 2021
 *      
 */
#include <adas_math.h>
#include "cruising/ctrl_cruising.h"
#include "math.h"
#include "ctrl_struct.h"
#include "ctrl_global_variables.h"
#include "lib_adas_adapter/vehicle_service/ctrl_adapter/ctrl_adapter.h"
#include "lib_adas_adapter/vehicle_service/vehicle_service_global_variables.h"
#include "common/ctrl_comm_func.h"
#include "peb/ctrl_hpeb_algo_new.h"
#include "adas_calibration_data.h"
#include "parking/ctrl_apa_parking.h"
#include "controller/ctrl_lat_algo.h"
#include "controller/ctrl_long_algo.h"
#include "vehicle_service/calib/vehsrv_calib.h"



#define CtrlPara_START_SEC_VAR		// Memory allocation
#include "proj_MemMap.h"

static int CooldownFlag = 0;
static int  LOOKNUM = 40;


#define CtrlPara_STOP_SEC_VAR	// Memory allocation end.
#include "proj_MemMap.h"



static uint8_t GetMatchPointIndex(uint8_t indexStart, tPathPlannerInfo* stPathPlanerData_ptr, tCtrlVehiclePosition* stCurrentPos_ptr);

static uint8_t PrjVectorDistance(float vec_a[2],float vec_b[2],float* prj_dis);

static void Ctrl_LQRGainTable(float Kd[]);

static float Ctrl_LowPassFilter(tLowPassPars* stLowPassPars_ptr,float u);


static uint8_t Ctrl_PathPointToEndDistance(tPathPlannerInfo* stPathPlanerData_ptr,tCtrlCommonInfo*  stCtrlCommonInfo_ptr);

static uint8_t Ctrl_RemainDistance(tCtrlVehiclePosition *stCurrentPos_ptr,tPathPlannerInfo* stPathPlannerInfo_ptr,
							tCtrlCommonInfo*  stCtrlCommonInfo_ptr);

static uint8_t Ctrl_RefreshPlanningPath(tPathPlannerInfo* stPathPlanerData_ptr,tCtrlCommonInfo*  stCtrlCommonInfo_ptr);

static bool WhetherNewPath(tPathPlannerInfo* stPathPlanerData_ptr, tCtrlCommonInfo*  stCtrlCommonInfo_ptr);

static bool WhetherValidPath(tPathPlannerInfo* stPathPlanerData_ptr);

static uint8_t GetYawAngleVelocity(tVehicleModelAndCtrlPara *stVehicleParms_ptr,
					const tCtrlVehiclePosition *stCurrentPos_ptr,
					int drResetFlag);                                             //for later use

static tCtrlVehiclePosition VehicleCTRVModel(const tCtrlVehiclePosition *stCurrentPos_ptr,float velCar,float yawVel);

static tCtrlVehiclePosition VehicleCVModel(const tCtrlVehiclePosition *stCurrentPos_ptr,float velCar);

static uint8_t LongiRminDistance(tCtrlToChassisInfo* stCtrl2Chassis_Info_ptr,
 						 tVehicleModelAndCtrlPara* stVehicleParms_ptr);
static void Ctrl_CrusingOn(void);

static void Ctrl_StateMachineInit(void);
static void Ctrl_LpfInit(void);

static ERROR_ID LatCtrlFeedForward(tVehicleModelAndCtrlPara *stVehicleParms_ptr,
							tPathPlannerInfo* stPathPoint_ptr,
							tCtrlCommonInfo*  stCtrlCommonInfo_ptr);

static uint8_t Ctrl_CalcuSteer(tCtrlVehiclePosition *stCurrentPos_ptr,
						tCtrlCommonInfo*  stCtrlCommonInfo_ptr,
						tStateMachine 		*stStateMachine_ptr,
						tPathPlannerInfo* stPathPlanerData_ptr,
						float lqrGain[4],
						tCtrlLatInfo*     stCtrlLatInfo_ptr,
						tLowPassPars* stLowPassPars_ptr);

/**
*************************************************************************
  * FUNCTION_NAME 
Ctrl_CrusingTask20ms. 

  * EXPLANATION   
Main cruising task,20ms cycletime. 

*************************************************************************
*/

uint8_t Ctrl_CruisingTask_20ms()
{
	if(0 == CooldownFlag)
	{
		CooldownFlag = 1;
		Ctrl_StateMachineInit();
	}

	Ctrl_CrusingOn();

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
FminDis. 

  * EXPLANATION   
Find minimum distance between car and path

*************************************************************************
*/

uint8_t GetMatchPointIndex(uint8_t indexStart, tPathPlannerInfo* stPathPlanerData_ptr, tCtrlVehiclePosition* stCurrentPos_ptr)
{
	float   dmin = 10000;
	uint8_t pointNum = stPathPlanerData_ptr->u8PointNum;
	uint8_t indexMatchPoint = indexStart;
	float curPosX = stCurrentPos_ptr->f32X_Coor;
	float curPosY = stCurrentPos_ptr->f32Y_Coor;

	for(uint8_t i = indexStart; i < pointNum; i++)
	{
		float refPosX = stPathPlanerData_ptr->stPathData[i].f32WayPointX;
		float refPosY = stPathPlanerData_ptr->stPathData[i].f32WayPointY;
		float dist = sqrtf(powf(refPosX - curPosX,2.0) + powf(refPosY - curPosY,2.0));
		if (dist < dmin)
		{
			indexMatchPoint = i;
			dmin = dist;
		}
	}

	return indexMatchPoint;
}

/**
*************************************************************************
  * FUNCTION_NAME 
PrjVectorDistance. 

  * EXPLANATION   
vector a to vector b projector distance

*************************************************************************
*/

uint8_t PrjVectorDistance(float vec_a[2], float vec_b[2], float* prj_dis)
{
	*prj_dis = (vec_a[0] * vec_b[0] + vec_a[1] * vec_b[1]) / sqrtf(sq(vec_b[0]) + sq(vec_b[1]));

	return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME 
Ctrl_LQRGainTable. 

  * EXPLANATION   
lookup LQR Gain talbe by car speed

*************************************************************************
*/

void Ctrl_LQRGainTable(float Kd[])
{
	tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
	Kd[0] = stCalibPF_ptr->stPFCruiseFuncConfig.Calib_f32K1DISCRUISING;                       
	Kd[1] = stCalibPF_ptr->stPFCruiseFuncConfig.Calib_f32K2DOTDISCRUISING;                     
	Kd[2] = stCalibPF_ptr->stPFCruiseFuncConfig.Calib_f32K3THETACRUISING;
	Kd[3] = stCalibPF_ptr->stPFCruiseFuncConfig.Calib_f32K4DOTTHETACRUISING;
}

/**
*************************************************************************
  * FUNCTION_NAME 
Ctrl_LowPassFilter. 

  * EXPLANATION   
first order low-pass filter

*************************************************************************
*/

float Ctrl_LowPassFilter(tLowPassPars* stLowPassPars_ptr,float u)
{
	//tustin
	// float wf = stLowPassPars_ptr->f32Bw;
	float wf = 1.0f;
	float dt = stLowPassPars_ptr->f32Ts;
	float u1 = stLowPassPars_ptr->f32u1;
	float y1 = stLowPassPars_ptr->f32y1;
	float index_y = (1-CTRL_PI*wf*dt)/(1+CTRL_PI*wf*dt);
	float index_u = CTRL_PI*wf*dt/(1+CTRL_PI*wf*dt);

	return (index_u*(u + u1) + index_y * y1);
}

/**
*************************************************************************
  * FUNCTION_NAME 
Ctrl_PathPointToEndDistance. 

  * EXPLANATION 
Calculate points to end point distance.  
*************************************************************************
*/
uint8_t Ctrl_PathPointToEndDistance(tPathPlannerInfo* stPathPlanerData_ptr,tCtrlCommonInfo*  stCtrlCommonInfo_ptr)
{
	float32_t distwopoint_temp[MAX_POINT_NUM]; 
	memset(distwopoint_temp,0,sizeof(float32_t)*MAX_POINT_NUM);
	memset(stCtrlCommonInfo_ptr->f32PointDisToEnd,0,sizeof(float32_t)*MAX_POINT_NUM);
	uint8_t  pointNum = stPathPlanerData_ptr->u8PointNum;
	for (uint8_t i = 0; i < pointNum-1; i++)
	{
		distwopoint_temp[i] = sqrtf(sq(stPathPlanerData_ptr->stPathData[i+1].f32WayPointX - stPathPlanerData_ptr->stPathData[i].f32WayPointX) +
			sq(stPathPlanerData_ptr->stPathData[i+1].f32WayPointY - stPathPlanerData_ptr->stPathData[i].f32WayPointY));
	}

	for (uint8_t i = pointNum -1; i >= 1 ; i--)
	{
		stCtrlCommonInfo_ptr->f32PointDisToEnd[i-1] = stCtrlCommonInfo_ptr->f32PointDisToEnd[i] + distwopoint_temp[i-1];
	}

	return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME 
Ctrl_RemainDistance. 

  * EXPLANATION 
The remainding distance from vehicle's current position to  path end.  
*************************************************************************
*/
uint8_t Ctrl_RemainDistance(tCtrlVehiclePosition *stCurrentPos_ptr,tPathPlannerInfo* stPathPlannerInfo_ptr,
							tCtrlCommonInfo*  stCtrlCommonInfo_ptr)
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

	prj_distance = (vec_a[0] * vec_b[0] + vec_a[1] * vec_b[1]) / sqrtf(sq(vec_b[0]) + sq(vec_b[1]));

	if (index == point_num - 1 &&  prj_distance >= 0)
	{	
		disCarToMachpoint = 0;
	}
	else
	{
        disCarToMachpoint = prj_distance;
	}

    stCtrlCommonInfo_ptr->f32DistanceLeft = g_stPathPlannerData.f32PathLength - g_stPathPlannerData.stPathData[index].f32WayPointS - prj_distance;

	return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME 
Ctrl_RefreshPath. 

  * EXPLANATION 
Refresh planning path.  
*************************************************************************
*/

uint8_t Ctrl_RefreshPlanningPath(tPathPlannerInfo* stPathPlanerData_ptr,
								 tCtrlCommonInfo*  stCtrlCommonInfo_ptr)
{
	if(CRUISE_STOP != g_stStateMachine.m_state && CRUISE_EMERGENCY_STOP != g_stStateMachine.m_state)
	{
		stCtrlCommonInfo_ptr->u8NearestPointIndexCurPose = 0;
		stCtrlCommonInfo_ptr->u16CurrentPathID = stPathPlanerData_ptr->u16PathId;
		Ctrl_PathPointToEndDistance(stPathPlanerData_ptr,stCtrlCommonInfo_ptr);
	}

	return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME 
WhetherNewPath. 

  * EXPLANATION 
New path judge.

*************************************************************************
*/
bool WhetherNewPath(tPathPlannerInfo* stPathPlanerData_ptr, tCtrlCommonInfo*  stCtrlCommonInfo_ptr)
{
	if(stCtrlCommonInfo_ptr->u16CurrentPathID != stPathPlanerData_ptr->u16PathId)
	{
		g_stStateMachine.m_PathFinishFlag = 0;
		return true;
	}
	else
	{
		return false;
	}
}

/**
*************************************************************************
  * FUNCTION_NAME 
WhetherValidPath. 

  * EXPLANATION 
Valid path judge.

*************************************************************************
*/
bool WhetherValidPath(tPathPlannerInfo* stPathPlanerData_ptr)
{
	uint8 point_num = stPathPlanerData_ptr->u8PointNum;
	if(point_num > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
*************************************************************************
  * FUNCTION_NAME 
. VehicleCTRVModel

  * EXPLANATION 
Vehicle constant turn rate and velocity model.

*************************************************************************
*/
tCtrlVehiclePosition VehicleCTRVModel(const tCtrlVehiclePosition *stCurrentPos_ptr,float velCar,float yawVel)
{
	tCtrlVehiclePosition stLookAheadPos;
	float delay_time = STEERING_DELAY_TIME;
	float x = stCurrentPos_ptr->f32X_Coor;
	float y = stCurrentPos_ptr->f32Y_Coor;
	float theta = stCurrentPos_ptr->f32Theta;

	stLookAheadPos.f32X_Coor = x + velCar/yawVel*(sinf(yawVel*delay_time+theta) - sinf(theta));
	stLookAheadPos.f32Y_Coor = y + velCar/yawVel*(-cosf(yawVel*delay_time+theta) + cosf(theta));
	stLookAheadPos.f32Theta = theta + yawVel * delay_time;

	return stLookAheadPos;
}

/**
*************************************************************************
  * FUNCTION_NAME 
. VehicleCVModel

  * EXPLANATION 
Vehicle constant velocity model.

*************************************************************************
*/
tCtrlVehiclePosition VehicleCVModel(const tCtrlVehiclePosition *stCurrentPos_ptr,float velCar)
{
	tCtrlVehiclePosition stLookAheadPos;
	float delay_time = STEERING_DELAY_TIME;
	float x = stCurrentPos_ptr->f32X_Coor;
	float y = stCurrentPos_ptr->f32Y_Coor;
	float theta = stCurrentPos_ptr->f32Theta;

	stLookAheadPos.f32X_Coor = x + velCar * cosf(theta) * delay_time;
	stLookAheadPos.f32Y_Coor = y + velCar * sinf(theta) * delay_time;
	stLookAheadPos.f32Theta = theta;

	return stLookAheadPos;
}

/**
*************************************************************************
  * FUNCTION_NAME 
LongiRminDistance. 

  * EXPLANATION 
Calculate residual distance.

*************************************************************************
*/
uint8_t LongiRminDistance(tCtrlToChassisInfo* stCtrl2Chassis_Info_ptr,
 						 tVehicleModelAndCtrlPara* stVehicleParms_ptr)
{
	//stCtrl2Chassis_Info_ptr->f32CtrlReqStopDistance = stVehicleParms_ptr->disCurPos2MatchPoint + stVehicleParms_ptr->disMatchPoint2FinalPoint;
	stCtrl2Chassis_Info_ptr->f32CtrlReqStopDistance = 10;

	return E_OK;
}

float32_t GetCarSpeed(const tVehDataRx*   stVehDataRx_ptr)
{
	return stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph*1.0f/3.6f; //m/s
}

uint8_t  GetCarGear(const tVehDataRx*   stVehDataRx_ptr)
{
	return (uint8_t)stVehDataRx_ptr->sVehVCUInfo.eVehActualGear;
}

uint8_t GetCarBreak(const tVehDataRx*   stVehDataRx_ptr)
{
	return stVehDataRx_ptr->sVehVCUInfo.bBrkPedal;
} 

float32_t GetCarSteer(const tVehDataRx*   stVehDataRx_ptr)
{
	return stVehDataRx_ptr->sVehEPSInfo.f32StrWhlAngDeg * CTRL_PI/180; //rad
}

void Ctrl_StateMachineInit(void)
{
	g_stStateMachine.m_state = STANDBY;
	g_stStateMachine.m_task = NON;
	g_stStateMachine.m_IsValidTraj = false;
	g_stStateMachine.m_ReminDis = 0.0;

	g_stStateMachine.m_EMGFlag = 0;
	g_stStateMachine.m_PathFinishFlag = 0;;

	Ctrl_LpfInit();
}
	

void Ctrl_LpfInit(void)
{
	tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
	g_stLpfPars.f32Ts = 0.02f;
	g_stLpfPars.f32Bw = stCalibPF_ptr->stPFCruiseFuncConfig.Calib_f32LPBANDWIDTHCRUISING;
	g_stLpfPars.f32u1 = 0.0;
	g_stLpfPars.f32y1 = 0.0;
}

void Ctrl_CalcuMatchPoint(tCtrlCommonInfo*  stCtrlCommonInfo_ptr,tPathPlannerInfo* stPathPlanerData_ptr,tCtrlVehiclePosition *stCurrentPos_ptr)
{
	uint8_t index = GetMatchPointIndex(stCtrlCommonInfo_ptr->u8NearestPointIndexCurPose, stPathPlanerData_ptr, stCurrentPos_ptr);
	stCtrlCommonInfo_ptr->u8NearestPointIndexCurPose = index;
}

tCtrlVehiclePosition Ctrl_CalcuLookAheadPos(tCtrlCommonInfo*  stCtrlCommonInfo_ptr,
										  tPathPlannerInfo* stPathPlanerData_ptr,
										  tCtrlVehiclePosition *stCurrentPos_ptr)
{
	tCtrlVehiclePosition stLookAheadPos;
	float vx = 0.0;
	float wz = 0.0;

	uint8_t index = stCtrlCommonInfo_ptr->u8NearestPointIndexCurPose;
	int8_t  gearFactor = stPathPlanerData_ptr->i8CtrlGearFactor;
	vx = 5.0/3.6 * gearFactor; //TODO traj following
	wz = vx * stPathPlanerData_ptr->stPathData[index].f32WayPointCurvature; 

	if(fabsf(wz) <= 0.001)
	{   
		stLookAheadPos = VehicleCVModel(stCurrentPos_ptr,vx);
	}
	else
	{
		stLookAheadPos = VehicleCTRVModel(stCurrentPos_ptr,vx,wz);
	}
	return stLookAheadPos;
}

uint8_t Ctrl_CalcuSteer(tCtrlVehiclePosition *stCurrentPos_ptr,
						tCtrlCommonInfo*  stCtrlCommonInfo_ptr,
						tStateMachine 		*stStateMachine_ptr,
						tPathPlannerInfo* stPathPlanerData_ptr,
						float lqrGain[4],
						tCtrlLatInfo*     stCtrlLatInfo_ptr,
						tLowPassPars*     stLowPassPars_ptr)
{
	tCtrlVehiclePosition stLookAheadPos = Ctrl_CalcuLookAheadPos(stCtrlCommonInfo_ptr,stPathPlanerData_ptr,stCurrentPos_ptr);
	uint8_t indexLookAhead = GetMatchPointIndex(stCtrlCommonInfo_ptr->u8NearestPointIndexCurPose, stPathPlanerData_ptr, &stLookAheadPos);
	trajFramPos = Ctrl_GetLatErrTrajectoryFrame(stPathPlanerData_ptr,
				                                            	&stLookAheadPos,
				                                            	indexLookAhead,
                                                            	stStateMachine_ptr->m_CarSpeed,
                                                                &g_stCtrlLatInfo,
                                                                &g_stCtrlCommonInfo);
	stCtrlLatInfo_ptr->stCtrlLatResult.f32FeedforwardAngle = atanf(CF_WHLBASE * stPathPlanerData_ptr->stPathData[indexLookAhead].f32WayPointCurvature);
	Ctrl_LQRGainTable(lqrGain);
	stCtrlLatInfo_ptr->stCtrlLatResult.f32FeedbackAngleRaw = -1 * (lqrGain[0] * ((float)stPathPlanerData_ptr->i8CtrlGearFactor)*stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrDistRaw + 
																   lqrGain[2] * ((float)stPathPlanerData_ptr->i8CtrlGearFactor)*stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrThetaRaw);
	g_stVehicleParms.flag_index1 = 100;
    g_stVehicleParms.flag_index2 = stLowPassPars_ptr->f32u1;
    g_stVehicleParms.flag_index3 = stLowPassPars_ptr->f32y1;
	g_stVehicleParms.flag_index4 = stCtrlLatInfo_ptr->stCtrlLatResult.f32FeedbackAngleRaw;

	stCtrlLatInfo_ptr->stCtrlLatResult.f32FeedbackAngleFiltered = Ctrl_LowPassFilter(stLowPassPars_ptr,stCtrlLatInfo_ptr->stCtrlLatResult.f32FeedbackAngleRaw);
	stLowPassPars_ptr->f32u1 = stCtrlLatInfo_ptr->stCtrlLatResult.f32FeedbackAngleRaw;
	stLowPassPars_ptr->f32y1 = stCtrlLatInfo_ptr->stCtrlLatResult.f32FeedbackAngleFiltered;
	g_stVehicleParms.flag_index5 = stCtrlLatInfo_ptr->stCtrlLatResult.f32FeedbackAngleFiltered;
	stStateMachine_ptr->m_SteerTrajReq = (stCtrlLatInfo_ptr->stCtrlLatResult.f32FeedbackAngleFiltered + stCtrlLatInfo_ptr->stCtrlLatResult.f32FeedforwardAngle) * STEER_WHELL_RATIO; 
	g_stVehicleParms.flag_index6 = stStateMachine_ptr->m_SteerTrajReq;

	return E_OK;
}

uint8_t Ctrl_GetTrajSpeedAndAcc(tCtrlCommonInfo*     stCtrlCommonInfo_ptr,
								tPathPlannerInfo*    stPathPlanerData_ptr,
								tCtrlToChassisInfo*  stCtrl2ChassisInfo_ptr,
								tStateMachine*       stStateMachine_ptr)
{
	uint8_t index = stCtrlCommonInfo_ptr->u8NearestPointIndexCurPose;
	uint8_t pointNum = stPathPlanerData_ptr->u8PointNum;
	if( index + LOOKNUM < pointNum)
	{
		stStateMachine_ptr->m_SpeedTrajReq = stPathPlanerData_ptr->stPathData[index + LOOKNUM].f32WayPointV;
		stStateMachine_ptr->m_AccTrajReq   = stPathPlanerData_ptr->stPathData[index + LOOKNUM].f32WayPointA;
	}
	else
	{
		stStateMachine_ptr->m_SpeedTrajReq = stPathPlanerData_ptr->stPathData[pointNum-1].f32WayPointV;
		stStateMachine_ptr->m_AccTrajReq   = stPathPlanerData_ptr->stPathData[pointNum-1].f32WayPointA;
	}

	if(stStateMachine_ptr->m_CarGear !=  stCtrl2ChassisInfo_ptr->eGearReq)  //档位不一致时，保证车辆先静止
	{
		stStateMachine_ptr->m_SpeedTrajReq = 0.0;
		stStateMachine_ptr->m_AccTrajReq   = 0.0;
	}
	stStateMachine_ptr->m_SpeedTrajReq = fmin(stStateMachine_ptr->m_SpeedTrajReq,stCtrlCommonInfo_ptr->stCtrlPebInfo.f32PebSpeed/3.6);
	if(stCtrlCommonInfo_ptr->stCtrlPebInfo.f32PebSpeed<1.3)
	{
		stStateMachine_ptr->m_AccTrajReq   = 0.0;//当PEB的速度很低的时候保证加速度控制的车速也很低
	}
	return E_OK;
}


uint8_t Ctrl_CalcuSpeedAndAcc(tStateMachine* stStateMachine_ptr,
							  tVehicleModelAndCtrlPara* stVehicleParms_ptr)
{
	float accFfwRatio = 1;
    float zeta = 1;
    float wn = 2*CTRL_PI*0.2763*1.0/2.0;
    float dt = 0.02; 
    // float Kp = 2*zeta*wn;
    // float Ki = wn * wn;
	float Kp = 0.6;
	//float Ki = 0.125;
	float Ki = 0.0;

    float proportion = 0.0;
    float Kb = 1.0/Kp; 
    int   saturaionFlag = 1; 
    float saturation = 0.0;
    float ACCMAX = 5.0;
    float DECMAX = -6.0;
	int saturationFlag = 0;
	float AccFFW = accFfwRatio * stStateMachine_ptr->m_AccTrajReq;
	float Vd = stStateMachine_ptr->m_SpeedTrajReq;
	float Vfb = GetCarSpeed(&g_stCtrlVehDataRx);

	float spdErr = Vd - Vfb;
	proportion = Kp * spdErr;
	float intTemp = stVehicleParms_ptr->mIntegration + Ki * spdErr * dt;
	float accTemp = proportion + intTemp + accFfwRatio * AccFFW;
	if(accTemp < DECMAX)
	{
		saturation = Kb * (DECMAX - accTemp);
	}
	else if(accTemp > ACCMAX)
	{
		saturation = Kb * (ACCMAX - accTemp);
	}
	else
	{
		saturation = 0.0;
	}

	 if(GetCarBreak(&g_stCtrlVehDataRx))
	 {
	 	stVehicleParms_ptr->mIntegration += Ki*(spdErr + saturaionFlag * saturation)*dt;
	 	stVehicleParms_ptr->mAd = proportion + stVehicleParms_ptr->mIntegration;
	 }
	 else
	 {
	 	stVehicleParms_ptr->mIntegration = 0.0;
	 	stVehicleParms_ptr->mAd = proportion;
	 	AccFFW = 0.0;
	 }

	stStateMachine_ptr->m_SpeedToESC = Vd;
	float uintemp = 0.0;
	if(stStateMachine_ptr->m_ReminDis <= 0.6f)
	{
		uintemp = -1.0f * fabsf((1.0f - fmaxf(0.0,stStateMachine_ptr->m_ReminDis)/0.6f));
		stStateMachine_ptr->m_AccelToESC = fminf(stVehicleParms_ptr->mAd + AccFFW,uintemp);
	}
	else
	{
		stStateMachine_ptr->m_AccelToESC = stVehicleParms_ptr->mAd + AccFFW;
	}
	g_stVehicleParms.flag_index7 = Vd;
    return E_OK;
}

int GetTrajIndexByTime(tCtrlCommonInfo*  stCtrlCommonInfo_ptr,
						tPathPlannerInfo* stPathPlanerData_ptr,
						int  nCycle,
						_Bool delayFlag)
{
	int idxs = stCtrlCommonInfo_ptr->u8NearestPointIndexCurPose;
	int indexLookAhead = idxs;
	float timeOffset = nCycle * 0.02;
	uint32_t timestart = stPathPlanerData_ptr->stPathData[idxs].u32WayPointT;
	float DELAYLONGI = 0.8; //unit:s
	float timeLookAhead = timestart/1e6 + delayFlag * DELAYLONGI + timeOffset;
	for(int i=idxs;i<stPathPlanerData_ptr->u8PointNum;i++)
	{
		indexLookAhead = i;
		if(timeLookAhead >= stPathPlanerData_ptr->stPathData[i].u32WayPointT/1e6)
		{
			break;
		}
	}
	return indexLookAhead;
}

void GetTrajDesired(uint8_t indexffw,
					uint8_t indexfb,
					tPathPlannerInfo* stPathPlanerData_ptr,
					tTrajLongiController* stTrajLongiController_ptr)
{
	stTrajLongiController_ptr->f32PosTrajReq = stPathPlanerData_ptr->stPathData[indexfb].f32WayPointS;
	stTrajLongiController_ptr->f32VelTrajReq = stPathPlanerData_ptr->stPathData[indexfb].f32WayPointV;
	stTrajLongiController_ptr->f32AccTrajReq = stPathPlanerData_ptr->stPathData[indexffw].f32WayPointA;
}

void Ctrl_LongiController(tTrajLongiController* stTrajLongiController_ptr)
{
	float stationErr = stTrajLongiController_ptr->f32StationErr;
	float speedErr	 = stTrajLongiController_ptr->f32SpeedErr;

	stTrajLongiController_ptr->f32kpp = 1;
	stTrajLongiController_ptr->f32kvp = 0.5;
	stTrajLongiController_ptr->f32kvi = 0;
	stTrajLongiController_ptr->f32dt  = 0.02;
	stTrajLongiController_ptr->f32ACCMAX = 2; //m/s^2
	stTrajLongiController_ptr->f32DECMAX = -2;
	stTrajLongiController_ptr->i8saturationFlag = 1;
	stTrajLongiController_ptr->f32accFfwRatio = 1.0;

	//position loop
	stTrajLongiController_ptr->f32PosControlOffset = stTrajLongiController_ptr->f32kpp * stationErr;
	stTrajLongiController_ptr->f32VelResul = stTrajLongiController_ptr->f32VelTrajReq + stTrajLongiController_ptr->f32PosControlOffset;
	//velocity loop
	float  spdKp = stTrajLongiController_ptr->f32kvp * (stTrajLongiController_ptr->f32PosControlOffset + speedErr);
	float  spdKi = stTrajLongiController_ptr->f32kvi * (stTrajLongiController_ptr->f32PosControlOffset + speedErr)*stTrajLongiController_ptr->f32dt;
	float  spdIntRaw = stTrajLongiController_ptr->f32Integration + spdKi; //f32Integration initial
	//TODO:leadlag controller

	float accRaw = stTrajLongiController_ptr->f32accFfwRatio * stTrajLongiController_ptr->f32AccTrajReq  //Acc ffw
												+ spdKp + stTrajLongiController_ptr->f32Integration;
	stTrajLongiController_ptr->f32KvAntiSat = 1.0/stTrajLongiController_ptr->f32kvp;
	if(accRaw < stTrajLongiController_ptr->f32DECMAX)
	{
		stTrajLongiController_ptr->f32saturationValue = stTrajLongiController_ptr->f32KvAntiSat * (stTrajLongiController_ptr->f32DECMAX - accRaw);
	}
	else if(accRaw > stTrajLongiController_ptr->f32ACCMAX)
	{
		stTrajLongiController_ptr->f32saturationValue = stTrajLongiController_ptr->f32KvAntiSat * (stTrajLongiController_ptr->f32ACCMAX - accRaw);
	}
	else
	{
		stTrajLongiController_ptr->f32saturationValue = 0.0;
	}

	//TODO:break action

	stTrajLongiController_ptr->f32Integration += spdKi + stTrajLongiController_ptr->f32kvi * stTrajLongiController_ptr->i8saturationFlag * 
															stTrajLongiController_ptr->f32saturationValue*stTrajLongiController_ptr->f32dt;

	stTrajLongiController_ptr->f32AccResul = stTrajLongiController_ptr->f32accFfwRatio * stTrajLongiController_ptr->f32AccTrajReq  //Acc ffw
												+ spdKp + stTrajLongiController_ptr->f32Integration;
}

void longi()
{
	static int count = 0;
	int MAXINTGRALTIME = 40; //max cycle 
	if(g_stCtrlCommonInfo.u8NearestPointIndexCurPose!=g_stCtrlCommonInfo.u8NearestPointIndexCurPosePre)
	{
		g_stCtrlCommonInfo.u8NearestPointIndexCurPosePre = g_stCtrlCommonInfo.u8NearestPointIndexCurPose;
		count = 0;
	}
	int indexffw = GetTrajIndexByTime(&g_stCtrlCommonInfo,&g_stPathPlannerData,0,true);
	int indexfb = GetTrajIndexByTime(&g_stCtrlCommonInfo,&g_stPathPlannerData,count,false);
	GetTrajDesired(indexffw,indexfb,&g_stPathPlannerData,&g_stTrjLongiCtroller);
	Ctrl_GetLongiError(&trajFramPos,&g_stTrjLongiCtroller);
	Ctrl_LongiController(&g_stTrjLongiCtroller);

	count++;
	if(count > MAXINTGRALTIME)
	{
		count = MAXINTGRALTIME;
	}
	g_stVehicleParms.flag_index7 = g_stPathPlannerData.stPathData[g_stCtrlCommonInfo.u8NearestPointIndexCurPose].f32WayPointV;
	g_stVehicleParms.flag_index8 = g_stPathPlannerData.stPathData[g_stCtrlCommonInfo.u8NearestPointIndexCurPose].f32WayPointA;
}

uint8_t Ctrl_OutToCanLimit(tCtrlToChassisInfo*    stCtrlToChassisInfo_ptr)
{
    float f32SendOutSteer;
    float f32SteeringGap = 6;

	if(stCtrlToChassisInfo_ptr->f32CtrlReqSpeed > 12.0)
	{
		stCtrlToChassisInfo_ptr->f32CtrlReqSpeed = 12;
	}
	else if (stCtrlToChassisInfo_ptr->f32CtrlReqSpeed <= 0.01)
	{
		stCtrlToChassisInfo_ptr->f32CtrlReqSpeed = 0;
		//stCtrlToChassisInfo_ptr->f32CtrlReqAccel = -1;
	}
	else
	{
		stCtrlToChassisInfo_ptr->f32CtrlReqSpeed = (g_stStateMachine.m_SpeedTrajReq *3.6);
	}

	if(stCtrlToChassisInfo_ptr->f32CtrlReqAccel >2.5)
	{
		stCtrlToChassisInfo_ptr->f32CtrlReqAccel = 2.5;
	}
	else if(stCtrlToChassisInfo_ptr->f32CtrlReqAccel <-2.5)
	{
		stCtrlToChassisInfo_ptr->f32CtrlReqAccel = -2.5;
	}

       
	f32SendOutSteer = stCtrlToChassisInfo_ptr->f32CtrlReqSteer ;

	if (f32SendOutSteer > stCtrlToChassisInfo_ptr->f32CtrlReqSteerPrev + f32SteeringGap)
	{
		f32SendOutSteer = stCtrlToChassisInfo_ptr->f32CtrlReqSteerPrev + f32SteeringGap;
	}
	else if (f32SendOutSteer < stCtrlToChassisInfo_ptr->f32CtrlReqSteerPrev - f32SteeringGap)
	{
		f32SendOutSteer = stCtrlToChassisInfo_ptr->f32CtrlReqSteerPrev - f32SteeringGap;
	}

	stCtrlToChassisInfo_ptr->f32CtrlReqSteerPrev = f32SendOutSteer;

	if (f32SendOutSteer > CTRL_STEER_MAX)
	{
		stCtrlToChassisInfo_ptr->f32CtrlReqSteer = CTRL_STEER_MAX;
	}
	else if (f32SendOutSteer < CTRL_STEER_MIN)
	{
		stCtrlToChassisInfo_ptr->f32CtrlReqSteer = CTRL_STEER_MIN;
	}
	else
	{
		stCtrlToChassisInfo_ptr->f32CtrlReqSteer = f32SendOutSteer;
	}

	stCtrlToChassisInfo_ptr->f32CtrlReqStopDistance = g_stCtrlCommonInfo.f32DistanceLeft;

    //log
    g_stVehicleParms.f32Steering_ = stCtrlToChassisInfo_ptr->f32CtrlReqSteer;
    g_stVehicleParms.f32Vel_      = stCtrlToChassisInfo_ptr->f32CtrlReqAccel;

    return E_OK;
}






uint8_t Ctrl_CrusingPebProcessing(tCtrlCommonInfo*    stCtrlCommonInfo_ptr, 
								  tCtrlToChassisInfo* stCtrlToChassisInfo_ptr,
								  tStateMachine*      stStateMachine_ptr)
{

	static uint8_t u8EMGStopCount = 0;
	float f32RegardAsStopSpd = 0.01;

    if (1 == stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebHappened)
    {
        stCtrlToChassisInfo_ptr->f32CtrlReqSpeed = 0;
        stCtrlToChassisInfo_ptr->f32CtrlReqAccel = -5;
    }


	if (1 == stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebHappened)
    {

        if (stStateMachine_ptr->m_CarSpeed < f32RegardAsStopSpd)
        {
            u8EMGStopCount++;
            if (u8EMGStopCount > 50)
            {
                u8EMGStopCount = 50;   // upper limit, prevent overflow.
            }
        }
        else
        {
            u8EMGStopCount = 0;
        }

        if (u8EMGStopCount > 50)    // for L + 1, prevent vehicle slip after stop.
        {
            stStateMachine_ptr->m_EMGFlag = 1;        
        }   // No else here. So if the vehicle slip again after "stop stable", this u8EmergStoppedFlag will remain 1. The replan request is once send out, can't change.
    }
	else
	{
		u8EMGStopCount = 0;
	}


	return E_OK;
}

uint8_t Ctrl_CruiseLonStateTransCondit(tCtrlLongiInfo*       stCtrlLongiInfo_ptr,
                                        tVehDataRx*   stVehDataRx_ptr)
{
    tCtrlCruiseLonStatus m_state = g_stStateMachine.m_state; 
    float f32VehSpeed               = stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph;
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
    float f32RegardAsStopSpd = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32RegardAsStopSpeed;
    static uint8_t u8FinishWaitCount = 0;

    if (CRUISE_STOP == m_state)
    {
        if (f32VehSpeed < f32RegardAsStopSpd)
        {   
            stCtrlLongiInfo_ptr->u8FinishWaitDelay = stCtrlLongiInfo_ptr->u8FinishWaitDelay + 1;
            if(stCtrlLongiInfo_ptr->u8FinishWaitDelay >= 100)
            {
                stCtrlLongiInfo_ptr->u8CurrentPathFinishedFlag = 1;
                stCtrlLongiInfo_ptr->u8FinishWaitDelay = 100;
            }
        }
    }
    else 
    {
        stCtrlLongiInfo_ptr->u8CurrentPathFinishedFlag = 0;
        stCtrlLongiInfo_ptr->u8FinishWaitDelay = 0;
    }
    
    if (CRUISE_EMERGENCY_STOP == m_state)
    {
        if (0 == stCtrlLongiInfo_ptr->u8PEBGearRecordFlag)
        {
            stCtrlLongiInfo_ptr->eRecordPebVehGear = stVehDataRx_ptr->sVehVCUInfo.eVehActualGear;
            stCtrlLongiInfo_ptr->u8PEBGearRecordFlag = 1;
        }

        if (f32VehSpeed < f32RegardAsStopSpd)
        {
            stCtrlLongiInfo_ptr->u16EmergStopStableCnt++;
            if (stCtrlLongiInfo_ptr->u16EmergStopStableCnt > 500)
            {
                stCtrlLongiInfo_ptr->u16EmergStopStableCnt = 500;   // upper limit, prevent overflow.
            }
        }
        else
        {
            stCtrlLongiInfo_ptr->u16EmergStopStableCnt = 0;
        }

        if (stCtrlLongiInfo_ptr->u16EmergStopStableCnt > 50)    // for L + 1, prevent vehicle slip after stop.
        {
            stCtrlLongiInfo_ptr->u8EmergStoppedFlag = 1;        
        }   // No else here. So if the vehicle slip again after "stop stable", this u8EmergStoppedFlag will remain 1. The replan request is once send out, can't change.
    }
    else
    {
        stCtrlLongiInfo_ptr->u8PEBGearRecordFlag   = 0;     // In very rare case, we need to reset it in Pause. Remain to be seen.
        stCtrlLongiInfo_ptr->u16EmergStopStableCnt = 0;
        stCtrlLongiInfo_ptr->u8EmergStoppedFlag = 0;
    }

    if (CRUISE_STOP_STEERING == m_state)
    {
        stCtrlLongiInfo_ptr->u16StopSteeringCnt++;
        if (stCtrlLongiInfo_ptr->u16StopSteeringCnt > 500)
        {
            stCtrlLongiInfo_ptr->u16StopSteeringCnt = 500;      // Upper limit, prevent over flow.
        }

        if (stCtrlLongiInfo_ptr->u16StopSteeringCnt > 200)       // Due to the gradient change of target wheel angle.
        {
            stCtrlLongiInfo_ptr->u8StopSteeringFinishWaitFlag = 1;      
        }
    }
    else 
    {
        stCtrlLongiInfo_ptr->u16StopSteeringCnt = 0;
        stCtrlLongiInfo_ptr->u8StopSteeringFinishWaitFlag = 0;
    }

    return E_OK;
}

void Ctrl_CrusingOn()
{
	tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();

	g_stStateMachine.m_IsValidTraj = WhetherValidPath(&g_stPathPlannerData);
	g_stStateMachine.m_CarSpeed = GetCarSpeed(&g_stCtrlVehDataRx);
	g_stStateMachine.m_CarBreak = GetCarBreak(&g_stCtrlVehDataRx);
	g_stStateMachine.m_CarGear = GetCarGear(&g_stCtrlVehDataRx);
	g_stStateMachine.m_CarSteer = GetCarSteer(&g_stCtrlVehDataRx);
	g_stStateMachine.m_StopSpeed = stCalibPF_ptr->stPFCruiseFuncConfig.Calib_f32STOPSPEEDCRUISING;
	g_stStateMachine.m_StopSteerGap = stCalibPF_ptr->stPFCruiseFuncConfig.Calib_f32STOPSTEERGAPCRUISING * CTRL_PI/180.0f;
	tCtrlCruiseLonStatus m_statePre = g_stStateMachine.m_state; //记录之前的状态
	tHandshakeTypeRq eHandshakeReq =g_stCtrlToChassisInfo.eHandshakeReq;
	tHandshakeType eHandshakeType = g_sHandshakeManager. eHandshakeType;
	
	uint8_t u8PebSignal        = g_stCtrlCommonInfo.stCtrlPebInfo.u8PebHappened;
	uint8_t u8NewPathFlag      = g_stPathPlannerData.u8NewPathFlag;
	uint8_t u8CurrentPathFinishedFlag = g_stCtrlLongiInfo.u8CurrentPathFinishedFlag;
	uint8_t u8StopSteerWaitFlag = g_stCtrlLongiInfo.u8StopSteeringFinishWaitFlag;

	// float32_t STOPACC = stCalibPF_ptr->stPFCruiseFuncConfig.Calib_f32STOPACCCRUISING * 2.0f;
	float f32StopDis           = 0.2;
	float32_t STOPACC = -1.1f;
	float32_t MAX_LATERRDIS = stCalibPF_ptr->stPFCruiseFuncConfig.Calib_f32MAX_LATERRDISCRUISING;
	float32_t MAX_LATERRHEADING = stCalibPF_ptr->stPFCruiseFuncConfig.Calib_f32MAX_LATERRHEADINGCRUISING * CTRL_PI/180.0f;
	static float32_t u16CruiseStopSteerCounter = 0;

	if(true == g_stStateMachine.m_IsValidTraj)
	{
		Ctrl_RefreshPlanningPath(&g_stPathPlannerData,
								&g_stCtrlCommonInfo);
		Ctrl_CalcuMatchPoint(&g_stCtrlCommonInfo,
							&g_stPathPlannerData,
							&g_stCtrlVehPose.stCurrentPos);
		Ctrl_RemainDistance(&g_stCtrlVehPose.stCurrentPos,&g_stPathPlannerData,&g_stCtrlCommonInfo);
		g_stStateMachine.m_ReminDis = g_stCtrlCommonInfo.f32DistanceLeft;
	}

	Ctrl_CalcuSteer(&g_stCtrlVehPose.stCurrentPos,&g_stCtrlCommonInfo,
					&g_stStateMachine,&g_stPathPlannerData,g_lqrGain,
					&g_stCtrlLatInfo,&g_stLpfPars);
	Ctrl_CruiseLonStateTransCondit(&g_stCtrlLongiInfo, &g_stCtrlVehDataRx);
	Ctrl_GearReq(&g_stPathPlannerData, &g_stCtrlVehDataRx, &g_stCtrlToChassisInfo, &g_stCtrlCommonInfo);
	uint8_t u8PpGearAchieved = g_stCtrlCommonInfo.u8PpGearAchieved;//保证当规划档位过来时，先判断档位不一致

if (1 == u8PebSignal && g_stStateMachine.m_state != CRUISE_STOP) 
    {
        g_stStateMachine.m_state = CRUISE_EMERGENCY_STOP;//u8VehicleActionRequest加上根据规划停车  后续可以加上P档退出机制
    }

switch(g_stStateMachine.m_state)
{
	case CRUISE_STOP_STEERING:
		if((fabsf(g_stStateMachine.m_SteerTrajReq - g_stStateMachine.m_CarSteer) <
			  g_stStateMachine.m_StopSteerGap) && 1 == u8PpGearAchieved)//  add 带车速的时候m_StopSteerGap增大
        {
            g_stStateMachine.m_state = CRUISE_RUNNING;
        }
		break;
	case CRUISE_RUNNING:
		if((g_stStateMachine.m_ReminDis <= f32StopDis) || 
		   ((g_stStateMachine.m_ReminDis <= f32StopDis + 0.3) && (g_stStateMachine.m_CarSpeed <0.001)))
		//(fabsf(g_stCtrlLatInfo.stCtrlLatErr.f32ErrDistRaw) > MAX_LATERRDIS) ||  横向距离或航向角航向角误差过大
		//(fabsf(g_stCtrlLatInfo.stCtrlLatErr.f32ErrThetaRaw) > MAX_LATERRHEADING)
		{
			g_stStateMachine.m_state = CRUISE_STOP;
		}
		break;
	case CRUISE_STOP:
		if((1 == u8CurrentPathFinishedFlag) && 1 == u8NewPathFlag && 1 == u8PpGearAchieved &&
			eHandshakeReq == eHandshakeType) //保证高低速握手模块切换完成
		{
			g_stStateMachine.m_state = CRUISE_STOP_STEERING;
		}
		break;
	case CRUISE_EMERGENCY_STOP:	
		if (1 == u8NewPathFlag && 1 == u8PpGearAchieved) 
            {
                g_stStateMachine.m_state = CRUISE_STOP_STEERING;
            }
         break;
	default :
		break;
}




// if(CRUISE_RUNNING==m_statePre &&     //后续加上方向盘的保护逻辑，记录之前的方向盘角度
//   (CRUISE_EMERGENCY_STOP== g_stStateMachine.m_state || CRUISE_STOP== g_stStateMachine.m_state))
//   {
// 	g_stStateMachine.m_CarSteerPre = g_stStateMachine.m_CarSteer;
//   }
// else if(CRUISE_STOP_STEERING==g_stStateMachine.m_state || CRUISE_RUNNING== g_stStateMachine.m_state)
// {
// 	g_stStateMachine.m_CarSteerPre = g_stStateMachine.m_CarSteer;
// }
// else
// {
// 	g_stStateMachine.m_CarSteerPre = g_stStateMachine.m_CarSteerPre;
// }

switch(g_stStateMachine.m_state)
{
	case CRUISE_STOP_STEERING:
		g_stStateMachine.m_SpeedToESC = 0.0;
		g_stStateMachine.m_AccelToESC = STOPACC;
		g_stStateMachine.m_SteerToEPS = g_stStateMachine.m_SteerTrajReq;
		break;
	case CRUISE_RUNNING:
		Ctrl_GetTrajSpeedAndAcc(&g_stCtrlCommonInfo,&g_stPathPlannerData,&g_stCtrlToChassisInfo,&g_stStateMachine);
		Ctrl_CalcuSpeedAndAcc(&g_stStateMachine,&g_stVehicleParms);
		g_stStateMachine.m_SteerToEPS =g_stStateMachine.m_SteerToEPS = g_stStateMachine.m_SteerTrajReq;
		break;
	case CRUISE_STOP:
		g_stStateMachine.m_SpeedToESC = 0.0;
		g_stStateMachine.m_AccelToESC = (g_stStateMachine.m_CarSpeed < g_stStateMachine.m_StopSpeed)? 0.0: STOPACC;
		g_stStateMachine.m_SteerToEPS = g_stStateMachine.m_CarSteer;//记录方向盘从running跳出的值
		Ctrl_LpfInit();
		break;
	case CRUISE_EMERGENCY_STOP:
		g_stStateMachine.m_SpeedToESC = 0.0;
		g_stStateMachine.m_AccelToESC = (g_stStateMachine.m_CarSpeed < g_stStateMachine.m_StopSpeed)? 0.0: (STOPACC-1.0);
		g_stStateMachine.m_SteerToEPS = g_stStateMachine.m_CarSteer;//记录方向盘从running跳出的值
		Ctrl_LpfInit();
		break;	
	default :
		break;	
}

if(CTRL_ACTION_FINISH == g_stPathPlannerData.u8VehicleActionRequest && P_GEAR==g_stStateMachine.m_CarGear &&
   g_stStateMachine.m_CarSpeed < g_stStateMachine.m_StopSpeed && g_stStateMachine.m_ReminDis <= (1.5+0.5))
{
	g_stCtrlCommonInfo.eCtrlFinishType = CTRL_FINISH_TYPE_HPP;
}
	if(CRUISE_EMERGENCY_STOP==g_stStateMachine.m_state)
	{
		g_stCtrlToChassisInfo.eAEBFlag = 1;
	}

	g_stCtrlToChassisInfo.f32CtrlReqSteerPrev = g_stCtrlToChassisInfo.f32CtrlReqSteer;
	control_HPEB_detection(&g_stCtrlCommonInfo, &g_stCtrlVehDataRx, &g_stCtrlUssInfo,&g_stStateMachine, &g_stPathPlannerData,&g_stCtrlFuncFsmInfo, &g_stCtrlLongiInfo);
	g_stCtrlToChassisInfo.f32CtrlReqSpeed = g_stStateMachine.m_SpeedToESC * 3.6f;
	g_stCtrlToChassisInfo.f32CtrlReqAccel = g_stStateMachine.m_AccelToESC;
	g_stCtrlToChassisInfo.f32CtrlReqSteer = g_stStateMachine.m_SteerToEPS * 180.0f/CTRL_PI;
	Ctrl_CrusingPebProcessing(&g_stCtrlCommonInfo, &g_stCtrlToChassisInfo, &g_stStateMachine);	
	Ctrl_OutToCanLimit(&g_stCtrlToChassisInfo);
	Ctrl_UpdateCtrlState(&g_stCtrlVehDataRx, &g_stCtrlLongiInfo, &g_stCtrlToPathPlannerInfo, &g_stCtrlCommonInfo, &g_stPathPlannerData);
}





