#include "ctrl_global_variables.h"
#include "adas_calibration_data.h"
#include "math.h"
#include "vehicle_service/calib/vehsrv_calib.h"


static uint8_t Ctrl_AdapterInit(void);
static uint8_t Ctrl_UssMemInfoInit(void);
static uint8_t Ctrl_ParkOutSideInit(void);
static uint8_t Ctrl_MemReservation(void);
static uint8_t Ctrl_LatVarInit(void);
static uint8_t Ctrl_CommonPathInfoInit(void);
static uint8_t Ctrl_ApaShellInfoInit(void);
static uint8_t Ctrl_PathPlannerInfoInit(void);
static uint8_t Ctrl_CtrlToFsmInit(void);
static uint8_t Ctrl_VehicleParmsInit(void);
static uint8_t Ctrl_VehPoseInit(void);
static uint8_t Ctrl_TrjLongiCtrollerInit(void);

#define CtrlPara_START_SEC_VAR		// Memory allocation
#include "proj_MemMap.h"

/*===========================
*	External Input
*==========================*/
tVehDataRx            		        g_stCtrlVehDataRx;
tPathPlannerInfo 				    g_stPathPlannerData = {0};	
tCtrlVehSpeed                       g_stCtrlVehSpeed;
tCtrlVehPose                        g_stCtrlVehPose;
tCtrlUssInfo              			g_stCtrlUssInfo;				
tCtrlFuncFsmInfo					g_stCtrlFuncFsmInfo;

/*===========================
*	Ctrl Module Variable
*==========================*/
tCtrlCommonInfo						g_stCtrlCommonInfo;   
tCtrlLongiInfo         		        g_stCtrlLongiInfo;	
tCtrlLatInfo						g_stCtrlLatInfo;

//cruising
tStateMachine                       g_stStateMachine;
tLowPassPars                        g_stLpfPars={0,0,0,0};
tTrajectoryFrame                    trajFramPos;


/*===========================
*	External Output
*==========================*/
tCtrlToChassisInfo            		g_stCtrlToChassisInfo;
tCtrl_StateInfo         		    g_stCtrlToPathPlannerInfo;
tCtrlToFuncStateMachine             g_stCtrlToFuncStateMachine;

/*===========================
*   Log, Diagnose
*==========================*/
tCtrl_LogInfo                	    g_stCtrlLogInfo;
tMsgMnger_CtrlErrCode               g_stCtrlDiagErrCode;

/*===========================
*   Others
*==========================*/
tCtrlParkOutSide                    g_stCtrlParkoutSide;

// Cruising
tVehicleModelAndCtrlPara 			g_stVehicleParms;
tCtrlPurePursuit            		g_stCtrlPurePursuit;
float								g_lqrGain[4] = {0};
tTrajLongiController                g_stTrjLongiCtroller;
// Cruising End

// -- Memory reservation. 
static tReservationUnit s_stResUnit1, s_stResUnit2;		
//static tReservationUnit s_stResUnit3, s_stResUnit4, s_stResUnit5;
//static tReservationUnit s_stResUnit6, s_stResUnit7, s_stResUnit8;


#define CtrlPara_STOP_SEC_VAR	// Memory allocation end.
#include "proj_MemMap.h"



uint8_t Ctrl_VariablesInit(void)		// To classify. Part of them need only one initialization, part of them need many times of initialization.
{
	uint8_t rtn = E_OK;

	rtn |= Ctrl_AdapterInit();
	rtn |= Ctrl_LongStateInit();
	rtn |= Ctrl_UssMemInfoInit();
    rtn |= Ctrl_ParkOutSideInit();
	rtn |= Ctrl_MemReservation();
	rtn |= Ctrl_CommonPathInfoInit();
	rtn |= Ctrl_ApaShellInfoInit();
	rtn |= Ctrl_LatVarInit();
    rtn |= Ctrl_PathPlannerInfoInit();
    rtn |= Ctrl_CtrlToFsmInit();
    rtn |= Ctrl_VehicleParmsInit();
    rtn |= Ctrl_VehPoseInit();
    rtn |= Ctrl_PebDirInit();
    rtn |= Ctrl_TrjLongiCtrollerInit();

    g_stCtrlDiagErrCode.u16ModuleParkErrCode = 0;

	return rtn;
}


uint8_t Ctrl_LogClean()
{

	for (uint8_t i = 0; i < LOG_ADAS_DEBUG_NUM; i++)
	{
		g_stCtrlLogInfo.f32AdasDebugVal[i] = 0.0f;
	}

    return E_OK;
}


uint8_t Ctrl_LongStateInit()
{
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
    g_stCtrlLongiInfo.eSpeedPhase            = PHASE_STOP_STEERING;
    g_stCtrlLongiInfo.f32TargetVehSpeed      = 0;
    g_stCtrlLongiInfo.f32LongKp   	         = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32CtrlAccKp;
	g_stCtrlLongiInfo.f32LongKi 	         = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32CtrlAccKi;
    g_stCtrlLongiInfo.f32LongKiAntiWindup    = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32CtrlAccKiAntiWindup;
	g_stCtrlLongiInfo.f32LongKd 		     = 0.0;
    g_stCtrlLongiInfo.f32KiIntegralSum       = 0;
    g_stCtrlLongiInfo.f32TargetAcce          = 0;
    g_stCtrlLongiInfo.f32TargetStopDistance  = 0;
    g_stCtrlLongiInfo.eStandStillReq         = NO_REQUEST;
    g_stCtrlLongiInfo.eAEBFlag               = NO_REQUEST;
    g_stCtrlLongiInfo.f32AverageSpeed        = 0;
    g_stCtrlLongiInfo.u8LongiCtrlStatus      = 0;
    g_stCtrlLongiInfo.u16AcceCount           = 0;
    g_stCtrlLongiInfo.u16DeceCount           = 0;
    g_stCtrlLongiInfo.u16RemainCount1        = 0;
    g_stCtrlLongiInfo.u16RemainCount2        = 0;
    g_stCtrlLongiInfo.u8CurrentPathFinishedFlag = 0;
    g_stCtrlLongiInfo.u8CurrentPathFinishedFlagPrev = 0;
    g_stCtrlLongiInfo.u16EmergStopStableCnt = 0;
    g_stCtrlLongiInfo.u8EmergStoppedFlag = 0;
    g_stCtrlLongiInfo.u16StopSteeringCnt = 0;
    g_stCtrlLongiInfo.u8StopSteeringFinishWaitFlag = 0;
    g_stCtrlLongiInfo.f32TrajTargetAcce     = 0;
    g_stCtrlLongiInfo.u8VehSpeedHumpTime     = 0;


    for (int8_t i = 0; i < 10; i++)
	{
        g_stCtrlLongiInfo.arrVehSpeedHistory[i] = 0;
	}

    g_stCtrlLongiInfo.stSpeedProfile.f32DecelDis  = 1.0;
    g_stCtrlLongiInfo.stSpeedProfile.f32StopDis   = 0.15;
    g_stCtrlLongiInfo.stSpeedProfile.f32MaxSpeed  = 2.0;
    g_stCtrlLongiInfo.stSpeedProfile.f32InitSpeed = 0.5;

    g_stCtrlLongiInfo.f32SpeedGainFactor          = 1.0;
    g_stCtrlLongiInfo.eRecordPebVehGear           = N_GEAR;
    g_stCtrlLongiInfo.u8PEBGearRecordFlag         = 0;
    g_stCtrlLongiInfo.u8FuelOilSpeedReachFlag     = 0;
    g_stCtrlLongiInfo.u8FuelOilDecelLevel         = 0;
    g_stCtrlLongiInfo.u8FinishWaitDelay           = 0;

	return E_OK;
}



/*	=====================================================================
 *
 *						static function definitions
 *
 *	===================================================================*/


static uint8_t Ctrl_AdapterInit()
{
    g_stCtrlToPathPlannerInfo.u16CurPathid    = 0;
    g_stCtrlToPathPlannerInfo.u8PathPEBDir    = 0;
    g_stCtrlToPathPlannerInfo.u8CtrlState     = 0;
    g_stCtrlToPathPlannerInfo.u8CtrlSubstate  = 0;

    (void) memset((void *) &g_stCtrlVehDataRx, 0,
                sizeof(tVehDataRx));
    g_stCtrlVehDataRx.sVehESCInfo.stVehSpdImpLPF.f32LPF_den_2 = -0.7;
    g_stCtrlVehDataRx.sVehESCInfo.stVehSpdImpLPF.f32LPF_num_1 = 0.15;
    g_stCtrlVehDataRx.sVehESCInfo.stVehSpdImpLPF.f32LPF_num_2 = 0.15;
    g_stCtrlVehDataRx.sVehVCUInfo.eVehActualGear = P_GEAR;

	g_stCtrlToChassisInfo.f32CtrlReqSpeedUnlimited 	       = 0;
    g_stCtrlToChassisInfo.f32CtrlReqSpeedLimited 	       = 0;
    g_stCtrlToChassisInfo.f32CtrlReqSpeedRateLimited       = 0;
    g_stCtrlToChassisInfo.f32CtrlReqSpeed                  = 0;
    g_stCtrlToChassisInfo.f32CtrlReqSpeedPrev              = 0;
	g_stCtrlToChassisInfo.f32CtrlReqAccelUnlimited         = 0;
    g_stCtrlToChassisInfo.f32CtrlReqAccelLimited  	       = 0;
    g_stCtrlToChassisInfo.f32CtrlReqAccelRateLimited       = 0;
    g_stCtrlToChassisInfo.f32CtrlReqAccel                  = 0;
    g_stCtrlToChassisInfo.f32CtrlReqAccelPrev              = 0;
	g_stCtrlToChassisInfo.f32CtrlReqStopDistanceUnlimited  = 0;
    g_stCtrlToChassisInfo.f32CtrlReqStopDistanceLimited    = 0;
    g_stCtrlToChassisInfo.f32CtrlReqStopDistance           = 0;
	g_stCtrlToChassisInfo.eStandStillReq                   = 0;
	g_stCtrlToChassisInfo.eAEBFlag                         = 0;
    
	g_stCtrlToChassisInfo.f32CtrlReqSteerUnlimited     = 0;
    g_stCtrlToChassisInfo.f32CtrlReqSteerMinmaxLimited = 0;
	g_stCtrlToChassisInfo.f32CtrlReqSteerRateLimited   = 0;
    g_stCtrlToChassisInfo.f32CtrlReqSteer              = 0;
 //   g_stCtrlToChassisInfo.f32CtrlReqSteerPrev          = 0; // Cancel initialization. This value will only be initialize during standy or off status;

	g_stCtrlToChassisInfo.eGearReq 				 = NONE_GEAR;
	g_stCtrlToChassisInfo.eHandshakeReq 		 = 0;

// 	g_stChassisToCtrlInfo.f32SteerWheelAngle 	 = 0;
// 	g_stChassisToCtrlInfo.f32SteerRotationSpd 	 = 0;
// 	g_stChassisToCtrlInfo.f32VehicleSpeed 		 = 0;

// 	g_stChassisToCtrlInfo.u16RLWheelImpulse 	 = 5000;
// 	g_stChassisToCtrlInfo.u16RRWheelImpulse 	 = 5000;
// 	g_stChassisToCtrlInfo.u16FRWheelImpulse 	 = 5000;
// 	g_stChassisToCtrlInfo.u16FLWheelImpulse 	 = 5000;

// 	g_stChassisToCtrlInfo.u16FL_Sector_Dist 	 = 0;
// 	g_stChassisToCtrlInfo.u16FML_Sector_Dist 	 = 0;
// 	g_stChassisToCtrlInfo.u16FMR_Sector_Dist 	 = 0;
// 	g_stChassisToCtrlInfo.u16FR_Sector_Dist 	 = 0;
// 	g_stChassisToCtrlInfo.u16RL_Sector_Dist 	 = 0;
// 	g_stChassisToCtrlInfo.u16RML_Sector_Dist 	 = 0;
// 	g_stChassisToCtrlInfo.u16RMR_Sector_Dist 	 = 0;
// 	g_stChassisToCtrlInfo.u16RR_Sector_Dist 	 = 0;
// 	g_stChassisToCtrlInfo.u16FSL_Sector_Dist 	 = 0;
// 	g_stChassisToCtrlInfo.u16FSR_Sector_Dist     = 0;
// 	g_stChassisToCtrlInfo.u16RSL_Sector_Dist 	 = 0;
// 	g_stChassisToCtrlInfo.u16RSR_Sector_Dist 	 = 0;

// 	for (int i = 0; i < US_IDX_NUM_MAX; i++)
//     {
//         g_stChassisToCtrlInfo.u16PebDistanceOriginal[i] = 0;
//     }

// 	for (int i = 0; i < PDC_ZONE_NUM; i++)
//     {
//         g_stChassisToCtrlInfo.u16PebDistanceConverted[i] = 0;
// 		g_stChassisToCtrlInfo.bBlindAreaObstacle[i] = FALSE;
//     }

// 	g_stChassisToCtrlInfo.u2WheelDirRL  = 0;
// 	g_stChassisToCtrlInfo.u2WheelDirRR  = 0;
// 	g_stChassisToCtrlInfo.u2WheelDirFR  = 0;
// 	g_stChassisToCtrlInfo.u2WheelDirFL  = 0;

// 	g_stChassisToCtrlInfo.u8esc_status 	   = 0;
// 	g_stChassisToCtrlInfo.u8eps_status 	   = 0;
// 	g_stChassisToCtrlInfo.u8vcu_status     = 0;
// 	g_stChassisToCtrlInfo.u8gearbox_status = 0;
// 	g_stChassisToCtrlInfo.u8DifficlutRoad  = 0;
//  g_stChassisToCtrlInfo.u8VehStandStill  = 0;





	return E_OK;
}


static uint8_t Ctrl_VehPoseInit()
{
    g_stCtrlVehPose.stCurrentPos.f32X_Coor = 0;
    g_stCtrlVehPose.stCurrentPos.f32Y_Coor = 0;
    g_stCtrlVehPose.stCurrentPos.f32Theta  = 0;
    g_stCtrlVehPose.stCurrentPos.f32Track  = 0;

    g_stCtrlVehPose.stPreviousPos.f32X_Coor = 0;
    g_stCtrlVehPose.stPreviousPos.f32Y_Coor = 0;
    g_stCtrlVehPose.stPreviousPos.f32Theta  = 0;
    g_stCtrlVehPose.stPreviousPos.f32Track  = 0;

    g_stCtrlVehPose.stPredictPos.f32FutureDRPoseX = 0;
    g_stCtrlVehPose.stPredictPos.f32FutureDRPoseY = 0;
    g_stCtrlVehPose.stPredictPos.f32FutureDRTheta = 0;
    g_stCtrlVehPose.stPredictPos.f32TimeGap       = (0.12 + 0.12)*1.0 + 0.22;   // stCalibPF_ptr->stPFAPAFuncConfig.Config_f32CtrtlTimeDT;

    g_stCtrlVehPose.stSelectedPos.f32X_Coor   = 0;
    g_stCtrlVehPose.stSelectedPos.f32Y_Coor   = 0;
    g_stCtrlVehPose.stSelectedPos.f32Theta   = 0;
    g_stCtrlVehPose.stSelectedPos.f32Track   = 0;

    return E_OK;
}

static uint8_t Ctrl_CommonPathInfoInit()
{
	g_stCtrlCommonInfo.eCtrlFuncStatus              = CTRL_MODULE_STANDBY;
  g_stCtrlCommonInfo.eCtrlFuncStatusPrev          = CTRL_MODULE_STANDBY;
  g_stCtrlCommonInfo.eCtrlFuncType                = Ctrl_Internal_Default;
    
  g_stCtrlCommonInfo.u16CurrentPathID             = 0;
  g_stCtrlCommonInfo.u16ReqPathID                 = 0;
  g_stCtrlCommonInfo.u16WaitNewPathCnt            = 0;
  g_stCtrlCommonInfo.u8WaitNewPathTimeoutFlag     = 0;
  g_stCtrlCommonInfo.u8ReplanReq                  = 0;
  g_stCtrlCommonInfo.eReplanReqType               = REPLAN_TYPE_NONE;
  g_stCtrlCommonInfo.u16WaitReplanResultCnt       = 0;
  g_stCtrlCommonInfo.eCtrlReplanResult            = CTRL_REPLAN_NONE;
  g_stCtrlCommonInfo.u8ExpectReplanGear           = P_GEAR;
  g_stCtrlCommonInfo.u8WaitReplanTimeoutFlag      = 0;
  g_stCtrlCommonInfo.u16RecPathID                 = 0;

  g_stCtrlCommonInfo.u8NearestPointIndexCurPose      = 0;
  g_stCtrlCommonInfo.u8NearestPointIndexCurPosePre   = 0;
  g_stCtrlCommonInfo.u8NearestPointIndexSelectedPose = 0;
	g_stCtrlCommonInfo.u8NearestPointIndexTime      = 0;
  g_stCtrlCommonInfo.i8PathStartPosIndicator      = 0;
  g_stCtrlCommonInfo.f32DistanceLeftRaw           = 0;
  g_stCtrlCommonInfo.f32DistanceLeft			    = 0;
  g_stCtrlCommonInfo.u8FrontPointIndex            = 0;
  g_stCtrlCommonInfo.u8BehindPointIndex           = 0;
  g_stCtrlCommonInfo.f32FrontPointDistance        = 0;
  g_stCtrlCommonInfo.f32BehindPointDistance       = 0;

  g_stCtrlCommonInfo.u8ConflictGearFlag           = 0;
  g_stCtrlCommonInfo.u8PpGearAchieved             = 0;
  g_stCtrlCommonInfo.u8PebParkCompleteFlag        = 0;
  g_stCtrlCommonInfo.u8PauseFlag                  = 0;
  g_stCtrlCommonInfo.u16TrappedTime1              = 0;
  g_stCtrlCommonInfo.u16TrappedTime2              = 0;
  g_stCtrlCommonInfo.u16TrappedTime3              = 0;
  g_stCtrlCommonInfo.u16RaTerminate              = 0;
  g_stCtrlCommonInfo.eGearRecord                  = NONE_GEAR;
	g_stCtrlCommonInfo.u8CtrlTrapFlag               = 0;
	g_stCtrlCommonInfo.u16CtrlChockCount            = 0;
  g_stCtrlCommonInfo.u8CtrlVerticalChockedFlag    = 0;
  g_stCtrlCommonInfo.u8CtrlHorizontalChockedFlag  = 0;
  g_stCtrlCommonInfo.eCtrlChockedTypeFlag = 0 ;

	g_stCtrlCommonInfo.u8CtrlChockCompleteFlag      = 0;
  g_stCtrlCommonInfo.u16CtrlUnknownStopCount      = 0;
  g_stCtrlCommonInfo.u8CtrlUnknownStopFlag        = 0;
  g_stCtrlCommonInfo.u8FinishActionFlag           = 0;
  g_stCtrlCommonInfo.u8FixPGearFlag               = 0;
	g_stCtrlCommonInfo.eCtrlFinishType              = CTRL_FINISH_TYPE_NONE;
  g_stCtrlCommonInfo.u8StandStillFlag             = 0;

  g_stCtrlCommonInfo.stTrapDectect.u16Counter          = 0;
  g_stCtrlCommonInfo.stTrapDectect.u16PathIDRecord     = 0;
  g_stCtrlCommonInfo.stTrapDectect.u8AEBTypeRecord     = 0;
  g_stCtrlCommonInfo.stTrapDectect.u8RecordFlag        = 0;
  g_stCtrlCommonInfo.stTrapDectect.u8PathGearRecord    = 0;
  g_stCtrlCommonInfo.stTrapDectect.u8GearShiftFlag     = 0;
  g_stCtrlCommonInfo.stTrapDectect.u8VehGearRecord     = 0;

	g_stCtrlCommonInfo.stCtrlPebInfo.f32speed       = 5;
	g_stCtrlCommonInfo.stCtrlPebInfo.f32ThetaErr    = 0;
	g_stCtrlCommonInfo.stCtrlPebInfo.f32LatDisErr   = 0;
	g_stCtrlCommonInfo.stCtrlPebInfo.u16distance    = 3;
	g_stCtrlCommonInfo.stCtrlPebInfo.u8USS_dis      = 0;
	g_stCtrlCommonInfo.stCtrlPebInfo.u8USS_Count    = 0;
	g_stCtrlCommonInfo.stCtrlPebInfo.u8PebHappened  = 0;
  g_stCtrlCommonInfo.stCtrlPebInfo.f32PebSpeed    = 15;
  g_stCtrlCommonInfo.stCtrlPebInfo.f32PebAcce     = 0;

	g_stCtrlCommonInfo.stCtrlPebInfo.u16USSRearLeft   = 0;
	g_stCtrlCommonInfo.stCtrlPebInfo.u16USSRearRight  = 0;
  g_stCtrlCommonInfo.stCtrlPebInfo.u8USS_flag_Front = 0;
  g_stCtrlCommonInfo.stCtrlPebInfo.u8USS_flag_Rear  = 0;
  g_stCtrlCommonInfo.stCtrlPebInfo.u8USS_flag_Left_Front_Side = 0;
  g_stCtrlCommonInfo.stCtrlPebInfo.u8USS_flag_Left_Rear_Side  = 0;
  g_stCtrlCommonInfo.stCtrlPebInfo.u8USS_flag_Right_Front_Side = 0;
  g_stCtrlCommonInfo.stCtrlPebInfo.u8USS_flag_Right_Rear_Side = 0;
    
  g_stCtrlCommonInfo.stCtrlPebInfo.u8PebDir         = 0;
  g_stCtrlCommonInfo.u8CtrlState                    = 0;
  g_stCtrlCommonInfo.u8CtrlSubstate                 = 0;
  g_stCtrlCommonInfo.u8DecisionRecord               = 0;
  g_stCtrlCommonInfo.f32RecordedDistanceTravel      = 0;
  g_stCtrlCommonInfo.u8VehStopByTravelDisFlag       = 0;

  g_stCtrlCommonInfo.u8FakeRoadPathId               = 1;

  g_stCtrlCommonInfo.u16RecordedPathID              = 0;
  g_stCtrlCommonInfo.u8RecordedTargetBehindID       = 0;
  g_stCtrlCommonInfo.u8RecordedTargetFrontID        = 0;

  g_stCtrlCommonInfo.u8TargetBehindID               = 0;
  g_stCtrlCommonInfo.u8TargetFrontID                = 0;

  g_stCtrlCommonInfo.f32RecordedTime                = 0;
  g_stCtrlCommonInfo.f32TargetTime                  = 0;

	return E_OK;
}

static uint8_t Ctrl_LatVarInit()
{
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib(); 

    g_stCtrlLatInfo.stCtrlLatErr.f32ErrDistRaw           = 0;
    g_stCtrlLatInfo.stCtrlLatErr.f32ErrDistFiltered      = 0;
    g_stCtrlLatInfo.stCtrlLatErr.f32ErrDistFilteredPrev  = 0;
    g_stCtrlLatInfo.stCtrlLatErr.f32ErrThetaRaw          = 0;
    g_stCtrlLatInfo.stCtrlLatErr.f32ErrThetaFiltered     = 0;
    g_stCtrlLatInfo.stCtrlLatErr.f32ErrThetaFilteredPrev = 0;
    g_stCtrlLatInfo.stCtrlLatErr.f32ErrDotDistRaw 		 = 0.0;
	g_stCtrlLatInfo.stCtrlLatErr.f32ErrDotThetaRaw 		 = 0.0;

    g_stCtrlLatInfo.stCtrlLatErr.f32SinglePointTargetCurvatureRaw       = 0.0f;
    g_stCtrlLatInfo.stCtrlLatErr.f32SinglePointTargetCurvatureFiltered  = 0.0f;
	g_stCtrlLatInfo.stCtrlLatErr.f32MultiPointTargetCurvatureRaw        = 0.0f;
    g_stCtrlLatInfo.stCtrlLatErr.f32MultiPointTargetCurvatureFiltered   = 0.0f;

	g_stCtrlLatInfo.stCtrlPurePursuit.m_alpha 		= 0;
	g_stCtrlLatInfo.stCtrlPurePursuit.m_deltaS 		= 2;
	g_stCtrlLatInfo.stCtrlPurePursuit.m_distMP 		= 0;
	g_stCtrlLatInfo.stCtrlPurePursuit.m_Ld 			= 0;
	g_stCtrlLatInfo.stCtrlPurePursuit.m_x_end 		= 0;
	g_stCtrlLatInfo.stCtrlPurePursuit.m_y_end 		= 0;
	g_stCtrlLatInfo.stCtrlPurePursuit.m_fai_end     = 0;
	g_stCtrlLatInfo.stCtrlPurePursuit.m_kcur_end 	= 0;
	g_stCtrlLatInfo.stCtrlPurePursuit.m_index 		= 0;
	g_stCtrlLatInfo.stCtrlPurePursuit.u16PreviewPathPointId 	= 0;
	g_stCtrlLatInfo.stCtrlPurePursuit.f32LatErrorOutput 		= 0;
	g_stCtrlLatInfo.stCtrlPurePursuit.f32LatSteerUpLimit 		= 0;
	g_stCtrlLatInfo.stCtrlPurePursuit.f32LatSteerLowLimit 	    = 0;
	g_stCtrlLatInfo.stCtrlPurePursuit.f32PurePursuitReqSteer 	= 0;

	g_stCtrlLatInfo.stCtrlStanley.f32ReqSteer 		= 0;

	g_stCtrlLatInfo.stCtrlPid.f32LatKp 				= 0.1;
	g_stCtrlLatInfo.stCtrlPid.f32LatKi 				= 0.5;
	g_stCtrlLatInfo.stCtrlPid.f32LatKd 				= 0.001;
	g_stCtrlLatInfo.stCtrlPid.f32LatTs 				= stCalibPF_ptr->stPFAPAFuncConfig.Config_f32CtrtlTimeDT;
	g_stCtrlLatInfo.stCtrlPid.f32LatIntegral      	= 0;
	g_stCtrlLatInfo.stCtrlPid.f32LatCompenSteer		= 0;
	g_stCtrlLatInfo.stCtrlPid.u8CompsationIndex    	= 0;
	for (int i = 0; i < 10; i++) 
	{
		g_stCtrlLatInfo.stCtrlPid.farr32LatIntegral[i] = 0;
	}

	g_stCtrlLatInfo.stCtrlLqr.f32Ts 							= stCalibPF_ptr->stPFAPAFuncConfig.Config_f32CtrtlTimeDT;
	g_stCtrlLatInfo.stCtrlLqr.f32K1 							= 0;
	g_stCtrlLatInfo.stCtrlLqr.f32K2 							= 0;
	g_stCtrlLatInfo.stCtrlLqr.f32K3 							= 0;
	g_stCtrlLatInfo.stCtrlLqr.f32K4 							= 0;
	g_stCtrlLatInfo.stCtrlLqr.f32LateralErrorCoefficient 		= 1;
	g_stCtrlLatInfo.stCtrlLqr.f32ThetaErrorCoefficient   		= 1;
	g_stCtrlLatInfo.stCtrlLqr.f32SinglePointFeedforwardAngle 	= 0;
	g_stCtrlLatInfo.stCtrlLqr.f32MultiPointFeedforwardAngle 	= 0;
	g_stCtrlLatInfo.stCtrlLqr.f32FeedbackAngleRaw 			    = 0;

	g_stCtrlLatInfo.stCtrlMpc.f32ReqSteer						= 0;

    g_stCtrlLatInfo.stCtrlLpfDistErr.f32LPF_den_2                = -0.7;
    g_stCtrlLatInfo.stCtrlLpfDistErr.f32LPF_num_1                = 0.15;
    g_stCtrlLatInfo.stCtrlLpfDistErr.f32LPF_num_2                = 0.15;
    g_stCtrlLatInfo.stCtrlLpfDistErr.f32LPF_filter_yk_1          = 0;
    g_stCtrlLatInfo.stCtrlLpfDistErr.f32LPF_filter_yk            = 0;
    g_stCtrlLatInfo.stCtrlLpfDistErr.f32LPF_yk                   = 0;
    g_stCtrlLatInfo.stCtrlLpfDistErr.f32LPF_yk_1                 = 0;

    g_stCtrlLatInfo.stCtrlLpfThetaErr.f32LPF_den_2               = -0.7;
    g_stCtrlLatInfo.stCtrlLpfThetaErr.f32LPF_num_1               = 0.15;
    g_stCtrlLatInfo.stCtrlLpfThetaErr.f32LPF_num_2               = 0.15;
    g_stCtrlLatInfo.stCtrlLpfThetaErr.f32LPF_filter_yk_1         = 0;
    g_stCtrlLatInfo.stCtrlLpfThetaErr.f32LPF_filter_yk           = 0;
    g_stCtrlLatInfo.stCtrlLpfThetaErr.f32LPF_yk                  = 0;
    g_stCtrlLatInfo.stCtrlLpfThetaErr.f32LPF_yk_1                = 0;

    g_stCtrlLatInfo.stCtrlLpfCurvatureSinglePoint.f32LPF_den_2                  = -0.7;
    g_stCtrlLatInfo.stCtrlLpfCurvatureSinglePoint.f32LPF_num_1                  = 0.15;
    g_stCtrlLatInfo.stCtrlLpfCurvatureSinglePoint.f32LPF_num_2                  = 0.15;
    g_stCtrlLatInfo.stCtrlLpfCurvatureSinglePoint.f32LPF_filter_yk_1            = 0;
    g_stCtrlLatInfo.stCtrlLpfCurvatureSinglePoint.f32LPF_filter_yk              = 0;
    g_stCtrlLatInfo.stCtrlLpfCurvatureSinglePoint.f32LPF_yk                     = 0;
    g_stCtrlLatInfo.stCtrlLpfCurvatureSinglePoint.f32LPF_yk_1                   = 0;

    g_stCtrlLatInfo.stCtrlLpfCurvatureMultiPoint.f32LPF_den_2                  = -0.7;
    g_stCtrlLatInfo.stCtrlLpfCurvatureMultiPoint.f32LPF_num_1                  = 0.15;
    g_stCtrlLatInfo.stCtrlLpfCurvatureMultiPoint.f32LPF_num_2                  = 0.15;
    g_stCtrlLatInfo.stCtrlLpfCurvatureMultiPoint.f32LPF_filter_yk_1            = 0;
    g_stCtrlLatInfo.stCtrlLpfCurvatureMultiPoint.f32LPF_filter_yk              = 0;
    g_stCtrlLatInfo.stCtrlLpfCurvatureMultiPoint.f32LPF_yk                     = 0;
    g_stCtrlLatInfo.stCtrlLpfCurvatureMultiPoint.f32LPF_yk_1                   = 0;

    g_stCtrlLatInfo.stCtrlLpfLat.f32LPF_den_2                    = -0.7;
    g_stCtrlLatInfo.stCtrlLpfLat.f32LPF_num_1                    = 0.15;
    g_stCtrlLatInfo.stCtrlLpfLat.f32LPF_num_2                    = 0.15;
    g_stCtrlLatInfo.stCtrlLpfLat.f32LPF_filter_yk_1              = 0;
    g_stCtrlLatInfo.stCtrlLpfLat.f32LPF_filter_yk                = 0;
    g_stCtrlLatInfo.stCtrlLpfLat.f32LPF_yk                       = 0;
    g_stCtrlLatInfo.stCtrlLpfLat.f32LPF_yk_1                     = 0;

    g_stCtrlLatInfo.stCtrlLpfTargetLatSteer.f32LPF_den_2         = -0.7;
    g_stCtrlLatInfo.stCtrlLpfTargetLatSteer.f32LPF_num_1         = 0.15;
    g_stCtrlLatInfo.stCtrlLpfTargetLatSteer.f32LPF_num_2         = 0.15;
    g_stCtrlLatInfo.stCtrlLpfTargetLatSteer.f32LPF_filter_yk_1   = 0;
    g_stCtrlLatInfo.stCtrlLpfTargetLatSteer.f32LPF_filter_yk     = 0;
    g_stCtrlLatInfo.stCtrlLpfTargetLatSteer.f32LPF_yk            = 0;
    g_stCtrlLatInfo.stCtrlLpfTargetLatSteer.f32LPF_yk_1          = 0;

	g_stCtrlLatInfo.stCtrlLatResult.u16PreviewPathPointId       = 0;
	g_stCtrlLatInfo.stCtrlLatResult.f32LookAheadCurvature 	    = 0;
	g_stCtrlLatInfo.stCtrlLatResult.f32FeedforwardAngle 		= 0;
	g_stCtrlLatInfo.stCtrlLatResult.f32FeedbackAngleRaw 		= 0;
	g_stCtrlLatInfo.stCtrlLatResult.f32FeedbackAngleFiltered 	= 0;
	g_stCtrlLatInfo.stCtrlLatResult.f32TargetWheelAngle 		= 0;
    g_stCtrlLatInfo.stCtrlLatResult.f32WheelToSteerRatio        = 15;
	g_stCtrlLatInfo.stCtrlLatResult.f32TargetSteerAngleRaw 		= 0;
	g_stCtrlLatInfo.stCtrlLatResult.f32TargetSteerAngleFiltered = 0;
    g_stCtrlLatInfo.stCtrlLatResult.f32TargetSteerAngleLimited  = 0;
	g_stCtrlLatInfo.stCtrlLatResult.f32LatSteerGap 			    = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32SteerAngleIncreRatioMax;
	g_stCtrlLatInfo.stCtrlLatResult.f32WheelToSteerRatioFactor  = 1;
    g_stCtrlLatInfo.stCtrlLatResult.f32PauseMemorySteer         = 0;
    g_stCtrlLatInfo.stCtrlLatResult.u8PauseMemorySteerLockFlag  = 0;

    g_stCtrlLatInfo.u8ReleaseTirePressurePhase       = 0;

	return E_OK;
}

static uint8_t Ctrl_UssMemInfoInit()
{
	for (int8_t i = 0; i < 12; i ++)
	{
		for (int8_t ii = 0; ii < 3; ii ++)
		{
			g_stCtrlUssInfo.u16_USS_mem_info[i][ii] = 0;
		}
	}

	for (int8_t iii = 0; iii < 9; iii ++)
	{
		g_stCtrlUssInfo.u8_Subarea_AEB_Sig[iii] = 0;
		g_stCtrlUssInfo.u8_Subarea_AEB_Counter[iii] = 0;
	}

	g_stCtrlUssInfo.u8_Subarea_AEB_Stage = 0;

	g_stCtrlUssInfo.u8_Subarea_gear_mem       = 0;
	g_stCtrlUssInfo.u16_Subarea_AEB_two_count = 0;

	g_stCtrlUssInfo.u8_Subarea_AEB_STOP_flag = 0;
	g_stCtrlUssInfo.u8_USAP_AEB_front_flag   = 0;
	g_stCtrlUssInfo.u8_USAP_AEB_rear_flag    = 0;
	g_stCtrlUssInfo.i8_USAP_gear_now         = 0;
	g_stCtrlUssInfo.f32_USAP_guide_speed     = 0.0f;
	g_stCtrlUssInfo.f32_USAP_guide_acce      = 0.0f;
	g_stCtrlUssInfo.u8_USAP_force_quit_flag  = 0;

    return E_OK;
}

static uint8_t Ctrl_ParkOutSideInit()
{
    
    g_stCtrlParkoutSide.eParkOutFinishCode          = 0;
    g_stCtrlParkoutSide.eParkOutType                = 0;
    g_stCtrlParkoutSide.eParkOutPhase               = 0;
    g_stCtrlParkoutSide.f32FrontEmptyFinishDis      = 0;
    g_stCtrlParkoutSide.f32NarrowFinishDis          = 0;
    g_stCtrlParkoutSide.f32SideNarrowFinishDis      = 0;
    g_stCtrlParkoutSide.f32DriveBackMinDis          = 0;
    g_stCtrlParkoutSide.f32InitTheta                = 0;
    g_stCtrlParkoutSide.f32RecordTrack              = 0;
    g_stCtrlParkoutSide.f32DistanceTravel           = 0;
    g_stCtrlParkoutSide.f32stopDis                  = 0;
    g_stCtrlParkoutSide.f32targetSpeed              = 0;
    g_stCtrlParkoutSide.f32minSpeed                 = 0;
    g_stCtrlParkoutSide.f32maxSteer                 = 0;
    g_stCtrlParkoutSide.f32steerGap                 = 0;
    g_stCtrlParkoutSide.f32steerFinishGap           = 0;
    g_stCtrlParkoutSide.bParkOutInitFlag            = 0;
    g_stCtrlParkoutSide.iParkOutInitCheckWaitTime   = 0;
    g_stCtrlParkoutSide.bParkOutInitCheckFlag       = 0;
    g_stCtrlParkoutSide.bParkOutFinishFlag          = 0;
	
	return E_OK;
}

static uint8_t Ctrl_MemReservation(void)
{
	//s_stResUnit1.u32Reservation[0] = 0;
	//s_stResUnit2.u32Reservation[0] = 0;
	//s_stResUnit3.u32Reservation[0] = 0;
	//s_stResUnit4.u32Reservation[0] = 0;
	//s_stResUnit5.u32Reservation[0] = 0;
	//s_stResUnit6.u32Reservation[0] = 0;
	//s_stResUnit7.u32Reservation[0] = 0;
	//s_stResUnit8.u32Reservation[0] = 0;
	return E_OK;
}



static uint8_t Ctrl_ApaShellInfoInit(void)
{
	g_stCtrlFuncFsmInfo.eLsadSystemSts = LSAD_STS_STANDBY;
	g_stCtrlFuncFsmInfo.eLsadSystemStsPrev = LSAD_STS_STANDBY;
    g_stCtrlFuncFsmInfo.eLsadSystemSubSts = LSAD_SUBSTS_NONE;
	g_stCtrlFuncFsmInfo.eLsadFuncType = LSAD_FUNC_TYPE_NONE;
    g_stCtrlFuncFsmInfo.eLsadDriverCtrlCommand = DRIVER_CTRL_NONE;
    g_stCtrlFuncFsmInfo.eCtrlParkOutType = CTRL_PARKOUT_NONE;

	return E_OK;
}

static uint8_t Ctrl_PathPlannerInfoInit(void)
{
    g_stPathPlannerData.ePathPlanSts              = APA_PATH_PLAN_STANDBY;
    g_stPathPlannerData.u16TotallyPathNum         = 0;
    g_stPathPlannerData.u16PathId                 = 0;
    g_stPathPlannerData.u8PointNum                = 0;
    g_stPathPlannerData.u8Shift                   = 5;
    g_stPathPlannerData.u8IsTraj                  = 0;
    g_stPathPlannerData.ePldType                  = DF_PL_TYPE_DEFAULT;
    g_stPathPlannerData.u8PlanResult              = 0;
    g_stPathPlannerData.u8PebLevel                = 0;
	g_stPathPlannerData.f32PathLength		      = 0;
    g_stPathPlannerData.stFinalLocation.f32X_Coor = 0;
    g_stPathPlannerData.stFinalLocation.f32Y_Coor = 0;
    g_stPathPlannerData.stFinalLocation.f32Theta  = 0;
    g_stPathPlannerData.u64StartTime              = 0;

	for (uint8_t i = 0; i < MAX_POINT_NUM; i++)
	{
		g_stPathPlannerData.stPathData[i].f32WayPointX         = 0;
        g_stPathPlannerData.stPathData[i].f32WayPointY         = 0;
        g_stPathPlannerData.stPathData[i].f32WayPointTheta     = 0;
        g_stPathPlannerData.stPathData[i].f32WayPointCurvature = 0;
        g_stPathPlannerData.stPathData[i].f32WayPointS         = 0;
        g_stPathPlannerData.stPathData[i].f32WayPointV         = 0;
        g_stPathPlannerData.stPathData[i].f32WayPointA         = 0;
        g_stPathPlannerData.stPathData[i].u32WayPointT         = 0;
	}

    g_stPathPlannerData.eCtrlPldType              = DF_PL_TYPE_DEFAULT;
    g_stPathPlannerData.u8NewPathFlag             = 0;
    g_stPathPlannerData.i8CtrlGearFactor          = 0;
    g_stPathPlannerData.u8LastPathFlag 			  = 0;
    g_stPathPlannerData.u8NoNewPathFlag           = 0;
    g_stPathPlannerData.u8PathInvalidFlag         = 0;
    g_stPathPlannerData.u8KappaSuddenChangeFlag   = 0;
    g_stPathPlannerData.u8KappaSuddenChangePointId = 0;

    return E_OK;
}

static uint8_t Ctrl_CtrlToFsmInit()
{
    g_stCtrlToFuncStateMachine.eCtrlStatus              = APA_CTRL_OFF;
    g_stCtrlToFuncStateMachine.stCtrlReqSts.u8ReqPause  = 0;
    g_stCtrlToFuncStateMachine.u8PausePressDurationCnt  = 0;

    return E_OK;
}

static uint8_t Ctrl_VehicleParmsInit()
{
	g_stVehicleParms.breakStatus = 0;
	g_stVehicleParms.accDesired = 0.0;
	g_stVehicleParms.mIntegration = 0.0;

	g_stVehicleParms.disCurPos2MatchPoint = 0.0;
	g_stVehicleParms.disMatchPoint2FinalPoint = 0.0;

	//for log print
	g_stVehicleParms.carPos[0] = 0;
	g_stVehicleParms.carPos[1] = 0;
	g_stVehicleParms.carPos[2] = 0;

	g_stVehicleParms.errState[0] = 0;
	g_stVehicleParms.errState[1] = 0;
	g_stVehicleParms.errState[2] = 0;
	g_stVehicleParms.errState[3] = 0;

	g_stVehicleParms.steeringOut = 0.0;
	
	g_stVehicleParms.index = 0;
	g_stVehicleParms.pointNum = 0;
	g_stVehicleParms.pathId = 0;

	g_stVehicleParms.x_path = 0;
	g_stVehicleParms.y_path = 0;
	g_stVehicleParms.theta_path = 0;

	g_stVehicleParms.flag_index1 = 0;
	g_stVehicleParms.flag_index2 = 0;
	g_stVehicleParms.flag_index3 = 0;
	g_stVehicleParms.flag_index4 = 0;
	g_stVehicleParms.flag_index5 = 0;
	g_stVehicleParms.flag_index6 = 0;
	g_stVehicleParms.flag_index7 = 0;
	g_stVehicleParms.flag_index8 = 0;
	g_stVehicleParms.flag_index9 = 0;
	g_stVehicleParms.flag_index10 = 0;
	g_stVehicleParms.flag_index11 = 0;
	g_stVehicleParms.flag_index12 = 0;
	g_stVehicleParms.flag_index13 = 0;
	g_stVehicleParms.flag_index14 = 0;
	g_stVehicleParms.flag_index15 = 0;
	g_stVehicleParms.flag_index16 = 0;

	g_stVehicleParms.f32Steering_ = 0.0;
	g_stVehicleParms.f32Vel_ = 0.0; 
	
	g_stVehicleParms.x_dr = -0.1;
	g_stVehicleParms.y_dr = -0.1;
	g_stVehicleParms.theta_dr = 0.0;
	
	return E_OK;
}

uint8_t Ctrl_PurePursuitParInit()
{
	g_stCtrlPurePursuit.m_alpha = 0.0;
	g_stCtrlPurePursuit.m_deltaS = 2; 
	g_stCtrlPurePursuit.m_distMP = 0.0;
	g_stCtrlPurePursuit.m_Ld = 0.0;
	g_stCtrlPurePursuit.m_x_end = 0.0;
	g_stCtrlPurePursuit.m_y_end = 0.0;
	g_stCtrlPurePursuit.m_fai_end = 0.0;
	g_stCtrlPurePursuit.m_kcur_end = 0.0;
	g_stCtrlPurePursuit.m_index = 0;

	return E_OK;
}

uint8_t Ctrl_PebDirInit()
{

    g_stCtrlCommonInfo.stCtrlPebInfo.u8PebHappened = 0;
    g_stCtrlCommonInfo.stCtrlPebInfo.u8PebDir = 0;
    g_stCtrlUssInfo.u8PebUssNumber = 20;
    g_stCtrlUssInfo.f32TTCMinTime = 20.0;
    return E_OK;
}

uint8_t Ctrl_TrjLongiCtrollerInit()
{
    g_stTrjLongiCtroller.f32accFfwRatio = 1;
    g_stTrjLongiCtroller.f32ACCMAX = 2.0;
    g_stTrjLongiCtroller.f32DECMAX = -2.0;
    g_stTrjLongiCtroller.f32AccResul = 0;
    g_stTrjLongiCtroller.f32AccTrajReq = 0;
    g_stTrjLongiCtroller.f32dt = 0.02;
    g_stTrjLongiCtroller.f32Integration = 0;
    g_stTrjLongiCtroller.f32kpp = 0;
    g_stTrjLongiCtroller.f32KvAntiSat = 0;
    g_stTrjLongiCtroller.f32kvi = 0;
    g_stTrjLongiCtroller.f32kvp = 0;
    g_stTrjLongiCtroller.f32PosControlOffset = 0;
    g_stTrjLongiCtroller.i8saturationFlag = 1;

    return E_OK;
}
