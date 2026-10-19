#include "ctrl_global_variables.h"
#include "math.h"
#include "vehicle_service/calib/vehsrv_calib.h"
#include "lib_adas_adapter/vehicle_service/ctrl_adapter/ctrl_adapter.h"
#include "ctrl_cruising.h"

static uint8_t Ctrl_CalAverageSpeed(tCtrlLongiInfo*      	stCtrlLongiInfo_ptr,
                                    tVehDataRx*   stVehDataRx_ptr);
static uint8_t Condition_Judge(tCtrlLongiInfo*  stCtrlLongiInfo_ptr);
static uint8_t Trapezoid_Accelerate(tCtrlLongiInfo*     stCtrlLongiInfo_ptr);	
static uint8_t Trapezoid_Decelerate(tCtrlLongiInfo*   stCtrlLongiInfo_ptr);
static float Ctrl_Get_SteeringPercentage (tVehDataRx*   stVehDataRx_ptr,
                                   		  tCtrlLatResult*            stCtrlLatResult_ptr);
static uint8_t Speed_Remain(tCtrlLongiInfo*    stCtrlLongiInfo_ptr);
static uint8_t CurveAcceCompensation(tCtrlLongiInfo*   stCtrlLongiInfo_ptr,
					          		 tCtrlLatResult*        stCtrlLatResult_ptr);


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_SpeedProfile

  * EXPLANATION
APA speed profiles based on parking type and ref path
*************************************************************************
*/

uint8_t Ctrl_SpeedProfile(tCtrlCommonInfo*            stCtrlCommonInfo_ptr,
                          tCtrlLongiInfo*             stCtrlLongiInfo_ptr,
                          tPathPlannerInfo*           stPathPlannerInfo_ptr)
{
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
    float f32PathLength = stPathPlannerInfo_ptr->f32PathLength;
    uint8_t u8PPGearReq = stPathPlannerInfo_ptr->u8Shift;

    // --- General concept: total distance based.
    if (f32PathLength >= stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32PathLengthThreshold3)
    {
        stCtrlLongiInfo_ptr->stSpeedProfile.f32DecelDis  = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32PathLengthLevel4DecelDis;
        stCtrlLongiInfo_ptr->stSpeedProfile.f32StopDis   = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32PathLengthLevel4StopDis;
        stCtrlLongiInfo_ptr->stSpeedProfile.f32MaxSpeed  = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32PathLengthLevel4MaxSpeed;
        stCtrlLongiInfo_ptr->stSpeedProfile.f32InitSpeed = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32PathLengthLevel4InitSpeed;
        if (D_GEAR == u8PPGearReq)
        {
            stCtrlLongiInfo_ptr->stSpeedProfile.f32DecelDis  = 1.2;
            stCtrlLongiInfo_ptr->stSpeedProfile.f32MaxSpeed  = 2.1;
        }
    }
    else if (f32PathLength <  stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32PathLengthThreshold3 && 
             f32PathLength >= stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32PathLengthThreshold2)
    {
        stCtrlLongiInfo_ptr->stSpeedProfile.f32DecelDis  = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32PathLengthLevel3DecelDis;
        stCtrlLongiInfo_ptr->stSpeedProfile.f32StopDis   = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32PathLengthLevel3StopDis;
        stCtrlLongiInfo_ptr->stSpeedProfile.f32MaxSpeed  = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32PathLengthLevel3MaxSpeed;
        stCtrlLongiInfo_ptr->stSpeedProfile.f32InitSpeed = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32PathLengthLevel3InitSpeed;
    }
    else if (f32PathLength <  stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32PathLengthThreshold2 && 
             f32PathLength >= stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32PathLengthThreshold1)
    {
        stCtrlLongiInfo_ptr->stSpeedProfile.f32DecelDis  = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32PathLengthLevel2DecelDis;
        stCtrlLongiInfo_ptr->stSpeedProfile.f32StopDis   = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32PathLengthLevel2StopDis;
        stCtrlLongiInfo_ptr->stSpeedProfile.f32MaxSpeed  = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32PathLengthLevel2MaxSpeed;
        stCtrlLongiInfo_ptr->stSpeedProfile.f32InitSpeed = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32PathLengthLevel2InitSpeed;
        if (DF_PL_TYPE_Vertical == stPathPlannerInfo_ptr->eCtrlPldType)
        {
            stCtrlLongiInfo_ptr->stSpeedProfile.f32MaxSpeed  = 1.0;
        }
    }
    else if (f32PathLength < stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32PathLengthThreshold1)
    {
        stCtrlLongiInfo_ptr->stSpeedProfile.f32DecelDis  = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32PathLengthLevel1DecelDis;
        stCtrlLongiInfo_ptr->stSpeedProfile.f32StopDis   = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32PathLengthLevel1StopDis;
        stCtrlLongiInfo_ptr->stSpeedProfile.f32MaxSpeed  = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32PathLengthLevel1MaxSpeed;
        stCtrlLongiInfo_ptr->stSpeedProfile.f32InitSpeed = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32PathLengthLevel1InitSpeed;
    }

    if (DF_PL_TYPE_Vertical == stPathPlannerInfo_ptr->eCtrlPldType && 1 == stPathPlannerInfo_ptr->u8LastPathFlag)
    {
        stCtrlLongiInfo_ptr->stSpeedProfile.f32DecelDis  = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32VerticalLastPathDecelDis;
    }   

    if (DF_PL_TYPE_ThreeDimensional == stPathPlannerInfo_ptr->eCtrlPldType && 1 == stPathPlannerInfo_ptr->u8LastPathFlag)
    {
        if (stCtrlLongiInfo_ptr->stSpeedProfile.f32MaxSpeed > stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32MechaLastPathMaxSpeed)
        {
            stCtrlLongiInfo_ptr->stSpeedProfile.f32MaxSpeed = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32MechaLastPathMaxSpeed;
        }
    }

    return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_SpeedTrapozoidPhase.

  * EXPLANATION
ladder-shaped vehicle speed control, check which phase is it now.
 - stop steering.
 - speed init.
 - maintain speed.
 - deceleration.
 - stop.
 - emergency stop.

*************************************************************************
*/

uint8_t Ctrl_SpeedTrapozoidPhase(tCtrlLatInfo*              stCtrlLatInfo_ptr,
                                 tVehDataRx*   stVehDataRx_ptr,
                                 tCtrlCommonInfo*           stCtrlCommonInfo_ptr,
                                 tPathPlannerInfo*          stPathPlannerInfo_ptr,
                                 tCtrlLongiInfo*      	    stCtrlLongiInfo_ptr)
{
  static uint16_t u16_fake_road_count = 0;

  tCtrlSpeedTrapezoidPhase ePhase = stCtrlLongiInfo_ptr->eSpeedPhase; 
  float f32SteerAngleChassis = stVehDataRx_ptr->sVehEPSInfo.f32StrWhlAngDeg;   // Steer wheel angle here is "steer angle", not "wheel angle".
  float f32SteerAngleReq     = stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetSteerAngleLimited;  //f32CtrlReqSteer
  tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
  float f32AngleGap_Temp     = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32StopSteerToleranceAngle;
  float f32RegardAsStopSpd = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32RegardAsStopSpeed;
  float f32DistLeft         = stCtrlCommonInfo_ptr->f32DistanceLeft;
  float f32DecelDis          = stCtrlLongiInfo_ptr->stSpeedProfile.f32DecelDis;
  float f32VehSpeed          = stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph;
  float f32TargetInitSpeed   = stCtrlLongiInfo_ptr->stSpeedProfile.f32InitSpeed;
  float f32StopDis           = stCtrlLongiInfo_ptr->stSpeedProfile.f32StopDis;
  uint8_t u8NewPathFlag      = stPathPlannerInfo_ptr->u8NewPathFlag;
  uint8_t u8StopSteerWaitFlag = stCtrlLongiInfo_ptr->u8StopSteeringFinishWaitFlag;
  uint8_t u8PpGearAchieved = stCtrlCommonInfo_ptr->u8PpGearAchieved;

  if ((stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebHappened == 1 || 
       stCtrlCommonInfo_ptr->eCtrlChockedTypeFlag == CONTROL_CHOCKED_ROLL_BACK)&&
       ePhase != PHASE_STOP) {
    ePhase = PHASE_EMERGENCY_STOP;
  }

  switch (ePhase){
    case PHASE_STOP_STEERING:   
      if (fabs(f32SteerAngleChassis - f32SteerAngleReq) < f32AngleGap_Temp &&
          1 == u8StopSteerWaitFlag){
        ePhase = PHASE_SPEED_INIT;
      }
      if (CTRL_ACTION_STOP == stPathPlannerInfo_ptr->u8VehicleActionRequest ||
          stCtrlCommonInfo_ptr->eCtrlChockedTypeFlag == CONTROL_CHOCKED_VERTICAL ||
          stCtrlCommonInfo_ptr->eCtrlChockedTypeFlag == CONTROL_CHOCKED_HORIZONTAL){
        ePhase = PHASE_STOP;
      }
      break;
    case PHASE_SPEED_INIT:
      if (f32VehSpeed > f32TargetInitSpeed || f32DistLeft <= f32DecelDis){
        ePhase = PHASE_SPEED_MAINTAIN;
      }
      if (CTRL_ACTION_STOP == stPathPlannerInfo_ptr->u8VehicleActionRequest||
          stCtrlCommonInfo_ptr->eCtrlChockedTypeFlag == CONTROL_CHOCKED_VERTICAL ||
          stCtrlCommonInfo_ptr->eCtrlChockedTypeFlag == CONTROL_CHOCKED_HORIZONTAL){
        ePhase = PHASE_STOP;
      }
      break;
    case PHASE_SPEED_MAINTAIN:
      if (f32DistLeft <= f32DecelDis){
        ePhase = PHASE_DECELERATION; 
      }
      if (CTRL_ACTION_STOP == stPathPlannerInfo_ptr->u8VehicleActionRequest||
          stCtrlCommonInfo_ptr->eCtrlChockedTypeFlag == CONTROL_CHOCKED_VERTICAL ||
          stCtrlCommonInfo_ptr->eCtrlChockedTypeFlag == CONTROL_CHOCKED_HORIZONTAL){
        ePhase = PHASE_STOP;
      }
      break;
    case PHASE_DECELERATION:
      if ((f32DistLeft <= f32StopDis) || 
         ((f32DistLeft <= f32StopDis + 0.05) && (f32VehSpeed <0.01))){
        ePhase = PHASE_STOP;
      }
      break;
    case PHASE_STOP: 
      // add condition 1==u8PpGearAchieved, in case of peb during the chassis gear changing period. 
      if ((1 == stCtrlLongiInfo_ptr->u8CurrentPathFinishedFlag) && 
           1 == u8NewPathFlag && 1 == u8PpGearAchieved){
        ePhase = PHASE_STOP_STEERING;
      }
    break;
    case PHASE_EMERGENCY_STOP:  
      // u8PebSignal will be 0 until: 1. new replan path comes; 2. send opposite gear request; 3. gear signal from chassis changes.
      // Even if we delete u8PebSignal != 1, phase will shift back to EmergStop after switch case. 
      if (1 == u8NewPathFlag && 1 == u8PpGearAchieved) {
        ePhase = PHASE_STOP_STEERING;
      }
      break;
    default:
      ;
      break;
  }
  stCtrlLongiInfo_ptr->eSpeedPhase = ePhase;
  return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_TrapozoidSpeedCtrl.

  * EXPLANATION
Trapozoid vehicle speed control

*************************************************************************
*/

uint8_t Ctrl_TrapozoidSpeedCtrl(tCtrlLongiInfo*      stCtrlLongiInfo_ptr,
                               tCtrlCommonInfo*      stCtrlCommonInfo_ptr,
                               tVehDataRx*   stVehDataRx_ptr,
                               tPathPlannerInfo*   	 stPathPlannerInfo_ptr)
{
    tCtrlSpeedTrapezoidPhase ePhase = stCtrlLongiInfo_ptr->eSpeedPhase; 
    float f32TargetSpeed        = 0;
    float f32TargetInitSpeed    = stCtrlLongiInfo_ptr->stSpeedProfile.f32InitSpeed;
    float f32MaxSpd             = stCtrlLongiInfo_ptr->stSpeedProfile.f32MaxSpeed;
    float f32DistLeft           = stCtrlCommonInfo_ptr->f32DistanceLeft;
    float f32DecelDis           = stCtrlLongiInfo_ptr->stSpeedProfile.f32DecelDis;
    float f32StopDis            = stCtrlLongiInfo_ptr->stSpeedProfile.f32StopDis;
    float f32VehSpd             = stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph;
    float f32DecelPhaseMinSpd   = 0.5;
    
    if(LSAD_PARK_OUT == g_stCtrlFuncFsmInfo.eLsadFuncType)
    {
       ; 
    }
    else
    {
        if (DF_PL_TYPE_Vertical == stPathPlannerInfo_ptr->eCtrlPldType)
        {
            if (1 == stPathPlannerInfo_ptr->u8LastPathFlag)
            {
                if (f32DistLeft > f32StopDis + 0.15)
                {
                    f32DecelPhaseMinSpd = 0.8;
                }
            }
            else
            {
                f32DecelPhaseMinSpd = 0.8;
            }
        }
    }


   switch (ePhase)
    {
        case PHASE_STOP_STEERING: 
            f32TargetSpeed = 0;
            break;

        case PHASE_SPEED_INIT:
            f32TargetSpeed = (f32TargetInitSpeed + f32MaxSpd) / 2;
            break;

        case PHASE_SPEED_MAINTAIN:
            f32TargetSpeed = f32MaxSpd;
            break;

        case PHASE_DECELERATION:
            f32TargetSpeed = f32MaxSpd * (f32DistLeft / f32DecelDis);   // Speed profile, linear deceleration.
            if (f32TargetSpeed < f32DecelPhaseMinSpd)   // Speed profile, minimum speed of linear deceleration.
            {
                f32TargetSpeed = f32DecelPhaseMinSpd;
            }
            
            if (f32TargetSpeed > f32VehSpd)         // Acceleration should not happen in PHASE_DECELERATION.
            {
                f32TargetSpeed = f32VehSpd;
            }
            if (f32TargetSpeed < 0.5)               // Bottom minumum speed. Avoid overshoot during deceleration. 
            {
                f32TargetSpeed = 0.5;
            }
            break;

        case PHASE_STOP: 
            f32TargetSpeed = 0;
            break;

        case PHASE_EMERGENCY_STOP: 
            f32TargetSpeed = 0;
            break;

        default:
            ;
            break;
    }

    stCtrlLongiInfo_ptr->f32TargetVehSpeed = f32TargetSpeed;

    return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_SpeedPhaseTransitCondition.

  * EXPLANATION
Trapozoid vehicle speed control

*************************************************************************
*/

uint8_t Ctrl_SpeedPhaseTransitCondition(tCtrlLongiInfo*       stCtrlLongiInfo_ptr,
                                        tVehDataRx*   stVehDataRx_ptr)
{
    tCtrlSpeedTrapezoidPhase ePhase = stCtrlLongiInfo_ptr->eSpeedPhase; 
    float f32VehSpeed               = stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph;
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
    float f32RegardAsStopSpd = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32RegardAsStopSpeed;

    static uint8_t u8FinishWaitCount = 0;

    if (PHASE_STOP == ePhase)
    {
        if (f32VehSpeed < f32RegardAsStopSpd)
        {   
            // stCtrlLongiInfo_ptr->u8FinishWaitDelay = stCtrlLongiInfo_ptr->u8FinishWaitDelay + 1;
            // if(stCtrlLongiInfo_ptr->u8FinishWaitDelay >= 100)
            // {
                stCtrlLongiInfo_ptr->u8CurrentPathFinishedFlag = 1;
                // stCtrlLongiInfo_ptr->u8FinishWaitDelay = 100;
            // }
        }
    }
    else 
    {
        stCtrlLongiInfo_ptr->u8CurrentPathFinishedFlag = 0;
        // stCtrlLongiInfo_ptr->u8FinishWaitDelay = 0;
    }
    
    if (PHASE_EMERGENCY_STOP == ePhase)
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

    if (PHASE_STOP_STEERING == ePhase)
    {
        stCtrlLongiInfo_ptr->u16StopSteeringCnt++;
        if (stCtrlLongiInfo_ptr->u16StopSteeringCnt > 500)
        {
            stCtrlLongiInfo_ptr->u16StopSteeringCnt = 500;      // Upper limit, prevent over flow.
        }

        if (stCtrlLongiInfo_ptr->u16StopSteeringCnt > 25)       // Due to the gradient change of target wheel angle.
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

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_StraightTargetSpeed.

  * EXPLANATION
"Straight in straight out", constant speed control.  

*************************************************************************
*/

uint8_t Ctrl_ApaStraightSpeedCtrl(tCtrlFuncFsmInfo*	   stCtrlApaShellInfo_ptr,                                  
                                  tCtrlLongiInfo*          stCtrlLongiInfo_ptr)
{
    float f32TargetSpeed = 0;

    if (DRIVER_CTRL_STRAIGHT_FORWARD == stCtrlApaShellInfo_ptr->eLsadDriverCtrlCommand || 
        DRIVER_CTRL_STRAIGHT_BACKWARD == stCtrlApaShellInfo_ptr->eLsadDriverCtrlCommand)
    {
        f32TargetSpeed = 1.5;
    }
    else
    {
        f32TargetSpeed = 0;
    }

    stCtrlLongiInfo_ptr->f32TargetVehSpeed = f32TargetSpeed;

    return E_OK;
}                           

uint8_t Ctrl_ApaStraighStopDistanceCtrl(tCtrlFuncFsmInfo*	   stCtrlApaShellInfo_ptr,
                                        tCtrlCommonInfo*       stCtrlCommonInfo_ptr,
                                        tCtrlLongiInfo*        stCtrlLongiInfo_ptr)
{
    uint8_t u8PebSignal        = stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebHappened;
    float f32TarStopDist = 0;
    tRequest eStopReq = NO_REQUEST;
    tRequest eAEBReq  = NO_REQUEST;
    if (DRIVER_CTRL_STRAIGHT_FORWARD == stCtrlApaShellInfo_ptr->eLsadDriverCtrlCommand || 
        DRIVER_CTRL_STRAIGHT_BACKWARD == stCtrlApaShellInfo_ptr->eLsadDriverCtrlCommand)
    {
        f32TarStopDist = 0.8;
    }
    else
    {
        f32TarStopDist = 0.0;
    }

    if(1==u8PebSignal)
	{
        eAEBReq = REQUEST;
        eStopReq = REQUEST;
        f32TarStopDist = 0.0;
	}
	else
	{
	    ;
	}
    stCtrlLongiInfo_ptr->f32TargetStopDistance = f32TarStopDist;
    stCtrlLongiInfo_ptr->eStandStillReq = eStopReq;
    stCtrlLongiInfo_ptr->eAEBFlag       = eAEBReq;
    return E_OK;

}         

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_CalTargetAcce.

  * EXPLANATION
Calculate the target acceleration, based on target speed and the current status.

*************************************************************************
*/

uint8_t Ctrl_CalTargetAcce(tCtrlLongiInfo*          stCtrlLongiInfo_ptr,
                           tCtrlCommonInfo*         stCtrlCommonInfo_ptr,
                           tVehDataRx*              stVehDataRx_ptr,
                           tCtrlToChassisInfo*      stCtrlToChassisInfo_ptr,
                           tCtrlUssInfo*            stCtrlUssInfo_ptr)
{
    
  tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
  tCtrlSpeedTrapezoidPhase ePhase = stCtrlLongiInfo_ptr->eSpeedPhase; 
  float f32RegardAsStopSpd = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32RegardAsStopSpeed;
  float f32VehSpdKph = stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph;
  static float f32PreviousVehSpdKph;
  float dt = 0.02f;
  float error = stCtrlToChassisInfo_ptr->f32CtrlReqSpeed - f32VehSpdKph;
  float errorAbs = fabs(error);
  static float PreAcceError;
  float k_P_error[8] = {0.0};
  float k_P_Acce[8] =  {0.0};

  float kp = 0.0;
  float ki = 0.01;
  float kd = ki/2;
  float f32fraction_kp = 1.0;
  float f32TargetDiffAcce = 0.0;
  static uint8 bAcceSpdPrt = 0;
  const uint8 num_points = 8;

  //camulate kp by lookup 
  if(error >0){
    float temp_error[] = {0.0,0.1,0.5,1.0,1.5,2.0,2.5,3.0};
    float temp_Acce[] =  {0.0,0.72,0.56,0.58,0.22,0.2,0.2,0.2};
    memcpy(k_P_error, temp_error, sizeof(temp_error));
    memcpy(k_P_Acce, temp_Acce, sizeof(temp_Acce));
    if((f32VehSpdKph < 0.3 && stCtrlLongiInfo_ptr->f32TargetStopDistance<0.6) ||
       (stCtrlUssInfo_ptr->f32UssMinDistance<0.8)){
      for(int i = 0; i < num_points; i++ ){
        k_P_Acce[i] = 0.5*k_P_Acce[i];//短距离P值减半
      }
    }
  }else{
    float temp_error[] = {0.0,0.1,0.5,1.0, 1.5,2.0,2.5,3.0};
    float temp_Acce[] =  {0.0,0.5,0.6,0.52,0.36,0.4,0.4,0.4};
    memcpy(k_P_error, temp_error, sizeof(temp_error));
    memcpy(k_P_Acce, temp_Acce, sizeof(temp_Acce));
  }
    
  uint8 index = 0;
  float fraction = 0.0;
  for(uint8 i =0;i<num_points;i++){
    if(errorAbs<=k_P_error[0]){
      index = 0;
      break;
    }else if (errorAbs>=k_P_error[num_points-1]){
      index = num_points-1;
      break;
    }else if(errorAbs> k_P_error[i] && errorAbs < k_P_error[i+1]){
      index = i;
      break;
    }   
  }
  if(0 == index){
    kp = k_P_Acce[0];
  }else if(num_points-1 == index){
    kp = k_P_Acce[num_points-1];
  }else{
    fraction = (errorAbs-k_P_error[index])/(k_P_error[index+1]-k_P_error[index]);
    kp = k_P_Acce[index]+fraction*(k_P_Acce[index+1]-k_P_Acce[index]);
  }
  // 根据不同的ePhase 状态设置刹车时的强度
  if (error<0.1) {
    if(ePhase == PHASE_EMERGENCY_STOP){
      f32fraction_kp = 1.8*f32fraction_kp;
    }else if( ePhase == PHASE_STOP){
      f32fraction_kp = 1.4*f32fraction_kp;
    }
    else if(ePhase == PHASE_DECELERATION){
    f32fraction_kp = 1*f32fraction_kp;//
    }
  } 
  kp =kp * f32fraction_kp;//
  //calculate Ki
  if (ePhase == PHASE_STOP_STEERING || ePhase == PHASE_STOP || ePhase == PHASE_EMERGENCY_STOP) {
    stCtrlLongiInfo_ptr->f32KiIntegralSum = 0;
  } else {
    stCtrlLongiInfo_ptr->f32KiIntegralSum += error * dt * ki;
    if (stCtrlLongiInfo_ptr->f32KiIntegralSum > stCtrlLongiInfo_ptr->f32LongKiAntiWindup){
            stCtrlLongiInfo_ptr->f32KiIntegralSum = stCtrlLongiInfo_ptr->f32LongKiAntiWindup;
    }else if (stCtrlLongiInfo_ptr->f32KiIntegralSum < -1 * stCtrlLongiInfo_ptr->f32LongKiAntiWindup){
            stCtrlLongiInfo_ptr->f32KiIntegralSum = -1 * stCtrlLongiInfo_ptr->f32LongKiAntiWindup;
    }
  }
  //calculate kd
  if (ePhase == PHASE_STOP_STEERING || ePhase == PHASE_STOP || ePhase == PHASE_EMERGENCY_STOP ||
    f32VehSpdKph<0.65) {
      stCtrlLongiInfo_ptr->f32TargetDiffAcce = 0;//f32VehSpdKph车速很小时，速度不准确不用微分项
  } else {
    stCtrlLongiInfo_ptr->f32TargetDiffAcce = -(f32VehSpdKph - f32PreviousVehSpdKph) / dt*kd;//测速反馈
    }
  PreAcceError = error;
  stCtrlLongiInfo_ptr->f32TargetPAcce = kp*error;
  stCtrlLongiInfo_ptr->f32TargetAcce = stCtrlLongiInfo_ptr->f32TargetPAcce+stCtrlLongiInfo_ptr->f32KiIntegralSum+stCtrlLongiInfo_ptr->f32TargetDiffAcce;

  if(error<-1.5 && f32VehSpdKph>2.8){
    bAcceSpdPrt = 1;
    }
  else if(error>-0.2){
    bAcceSpdPrt = 0;
    }
  if(bAcceSpdPrt == 1){
    stCtrlLongiInfo_ptr->f32TargetAcce = -1.5;
    }
  f32PreviousVehSpdKph = f32VehSpdKph;  
	return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_FuelOilCalTargetAcce.

  * EXPLANATION
Calculate the fuel oil car’s target acceleration, based on target speed and the current status.

*************************************************************************
*/
uint8_t Ctrl_FuelOilCalTargetAcce(tCtrlLongiInfo*          stCtrlLongiInfo_ptr,
                                  tVehDataRx*   stVehDataRx_ptr)
{
    tCtrlSpeedTrapezoidPhase ePhase = stCtrlLongiInfo_ptr->eSpeedPhase; 
    float f32TargetAcce = 0;
    float Kp = 0.1;      // Specified value to move to vehSrv Calib.
    float f32SpeedError = stCtrlLongiInfo_ptr->f32TargetVehSpeed - stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph;
    float f32TargetAcceUpLimited = 0.05;
    float f32TargetAcceLowLimited = -0.05;

    //uint16_t u16MinUSSDis = Ctrl_CalcuPebDisMin(stChassisToCtrlInfo_ptr);

    if(PHASE_SPEED_INIT == ePhase)
    {
        stCtrlLongiInfo_ptr->u8FuelOilDecelLevel = 0;
        stCtrlLongiInfo_ptr->u8FuelOilSpeedReachFlag = 0;
        f32TargetAcce = 0.1;      
        if(VEHI_GEAR_R == g_stCtrlToChassisInfo.eGearReq)
        {
            f32TargetAcce = 0.1;
        }
    }
    else if(PHASE_SPEED_MAINTAIN == ePhase)
    {
        stCtrlLongiInfo_ptr->u8FuelOilDecelLevel = 0;
        f32TargetAcce = Kp * f32SpeedError;

        // if(1 == stCtrlLongiInfo_ptr->u8ActualGreaterPEBSpeedFlag) //PEB change limited
        // {
        //     f32TargetAcceLowLimited = -0.2;
        // }
        // else
        // {
        //     f32TargetAcceLowLimited = -0.05;
        // }

        if(f32TargetAcce < f32TargetAcceLowLimited)             //Limited acceleration
        {
            f32TargetAcce = f32TargetAcceLowLimited;
        } 
        else if(f32TargetAcce > f32TargetAcceUpLimited)
        {
            f32TargetAcce = f32TargetAcceUpLimited;
        } 
        else
        {
            ;
        }

        if(VEHI_GEAR_R == g_stCtrlToChassisInfo.eGearReq)
        {
            if(stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph < 0.9 * stCtrlLongiInfo_ptr->f32TargetVehSpeed && 0 == stCtrlLongiInfo_ptr->u8FuelOilSpeedReachFlag)
            {
                if(f32TargetAcce > 0 && f32TargetAcce <= 0.05)
                {
                    f32TargetAcce = 0.1;
                } 
            }
            else
            {
                stCtrlLongiInfo_ptr->u8FuelOilSpeedReachFlag = 1;
            }
        }

    }
    else if(PHASE_DECELERATION == ePhase)
    {
        f32TargetAcce = Kp*1.5 * f32SpeedError;
        f32TargetAcceLowLimited = -0.1;
        stCtrlLongiInfo_ptr->u8FuelOilDecelLevel = 0;

        if(f32TargetAcce < f32TargetAcceLowLimited)
        {
            f32TargetAcce = f32TargetAcceLowLimited;
        } 
        else if(f32TargetAcce > f32TargetAcceUpLimited)
        {
            f32TargetAcce = f32TargetAcceUpLimited;
        } 
        else
        {
            ;
        }

        if(f32TargetAcce >0 && f32TargetAcce < 0.05)
        {
            f32TargetAcce = 0.05;
        }
    }
    else if(PHASE_STOP == ePhase)
    {
        stCtrlLongiInfo_ptr->u8FuelOilSpeedReachFlag = 0;
        if(stVehDataRx_ptr->sVehESCInfo.f32VehSpdImp > 0.5 || 3 == stCtrlLongiInfo_ptr->u8FuelOilDecelLevel)
        {
            f32TargetAcce = -0.40;
            stCtrlLongiInfo_ptr->u8FuelOilDecelLevel = 3;
        }
        else if(stVehDataRx_ptr->sVehESCInfo.f32VehSpdImp > 0.25 || 2 == stCtrlLongiInfo_ptr->u8FuelOilDecelLevel)
        {
            f32TargetAcce = -0.35;
            stCtrlLongiInfo_ptr->u8FuelOilDecelLevel = 2;
        }
        else
        {
            f32TargetAcce = -0.2;
            stCtrlLongiInfo_ptr->u8FuelOilDecelLevel = 1;
        }
 
    }
    else if(PHASE_EMERGENCY_STOP == ePhase)
    {
        stCtrlLongiInfo_ptr->u8FuelOilDecelLevel = 0;
        stCtrlLongiInfo_ptr->u8FuelOilSpeedReachFlag = 0;
        f32TargetAcce = -0.5;

        // if(u16MinUSSDis < 25)
        // {
        //     f32TargetAcce = -2;
        // }
        // else if(u16MinUSSDis <15 )
        // {
        //     f32TargetAcce = -3;
        // }
        
    }
    else
    {
        stCtrlLongiInfo_ptr->u8FuelOilDecelLevel = 0;
        f32TargetAcce = 0;
    }

    stCtrlLongiInfo_ptr->f32TargetAcce = f32TargetAcce;

	return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_CalTargetAcceDetailed.

  * EXPLANATION
Calculate the target acceleration, based on target speed and the current status.

*************************************************************************
*/

uint8_t Ctrl_CalTargetAcceDetailed(tCtrlLongiInfo*      	    stCtrlLongiInfo_ptr,
                                   tCtrlLatInfo*                stCtrlLatInfo_ptr,
                                   tVehDataRx*   stVehDataRx_ptr)
{
    // --- Based on target speed and controller.
    Ctrl_CalAverageSpeed(stCtrlLongiInfo_ptr, stVehDataRx_ptr);

	if (stCtrlLongiInfo_ptr->f32AverageSpeed >= 0.1f)
	{
		Condition_Judge(stCtrlLongiInfo_ptr);

		if (1 == stCtrlLongiInfo_ptr->u8LongiCtrlStatus )
		{
		    Trapezoid_Accelerate(stCtrlLongiInfo_ptr);
		}
		else if (2 == stCtrlLongiInfo_ptr->u8LongiCtrlStatus )
		{
			Trapezoid_Decelerate(stCtrlLongiInfo_ptr);
		}
		else if (0 == stCtrlLongiInfo_ptr->u8LongiCtrlStatus )
		{
		    stCtrlLongiInfo_ptr->f32TargetAcce = 0.0f;
		}
		else
		{
		    Speed_Remain(stCtrlLongiInfo_ptr);
		}
	}
	else
	{
		stCtrlLongiInfo_ptr->f32TargetAcce = 0.05f;
	}
	CurveAcceCompensation(stCtrlLongiInfo_ptr, &stCtrlLatInfo_ptr->stCtrlLatResult);

    // --- Based on speed phase.
    if (PHASE_STOP == stCtrlLongiInfo_ptr->eSpeedPhase && PHASE_EMERGENCY_STOP == stCtrlLongiInfo_ptr->eSpeedPhase)
	{
        stCtrlLongiInfo_ptr->f32TargetAcce = -0.20;  
	}
    else
    {
        ;
    }

    return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_CalStopDistance.

  * EXPLANATION
Calculate the target stop distance. This interface is relative rarely used.

*************************************************************************
*/

uint8_t Ctrl_CalStopDistance(tCtrlLongiInfo*      	 stCtrlLongiInfo_ptr,
                             tCtrlCommonInfo*            stCtrlCommonInfo_ptr,
                             tVehDataRx*   stVehDataRx_ptr)
{
  tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
  float f32RegardAsStopSpd = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32RegardAsStopSpeed;
  tCtrlSpeedTrapezoidPhase ePhase = stCtrlLongiInfo_ptr->eSpeedPhase;
  float f32VehSpd = stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph;

  if(PHASE_STOP_STEERING == ePhase || 1 == stCtrlLongiInfo_ptr->u8CurrentPathFinishedFlag ||
    ((PHASE_STOP == ePhase || PHASE_EMERGENCY_STOP == ePhase) && f32VehSpd <= f32RegardAsStopSpd)){
    stCtrlLongiInfo_ptr->f32TargetStopDistance = 0.0f;
	}else{
	  stCtrlLongiInfo_ptr->f32TargetStopDistance = stCtrlCommonInfo_ptr->f32DistanceLeft;
	}
  if (PHASE_STOP == ePhase || PHASE_EMERGENCY_STOP == ePhase){
    stCtrlLongiInfo_ptr->eStandStillReq = REQUEST;
	}else{
	  stCtrlLongiInfo_ptr->eStandStillReq = NO_REQUEST;
	}
  if(PHASE_EMERGENCY_STOP == ePhase) {
	  stCtrlLongiInfo_ptr->eAEBFlag  = REQUEST;
	}else{
    stCtrlLongiInfo_ptr->eAEBFlag  = NO_REQUEST;
  }
    return E_OK;
    return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_FinishActionLongi

  * EXPLANATION
Finish action while the finish flag is true.

*************************************************************************
*/

uint8_t Ctrl_FinishActionLongi(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                               tVehDataRx*   stVehDataRx_ptr,
                               tCtrlLongiInfo*      	 stCtrlLongiInfo_ptr)
{
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
    float f32RegardAsStopSpd = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32RegardAsStopSpeed;

    if (1 == stCtrlCommonInfo_ptr->u8FinishActionFlag)
    {
        if (stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph < f32RegardAsStopSpd)
        {
            stCtrlLongiInfo_ptr->f32TargetVehSpeed = 0;
            stCtrlLongiInfo_ptr->f32TargetAcce = 0;
            stCtrlLongiInfo_ptr->f32TargetStopDistance  =  0;
        }
        else
        {
            stCtrlLongiInfo_ptr->f32TargetVehSpeed = 0;
            stCtrlLongiInfo_ptr->f32TargetAcce = -0.2;
            stCtrlLongiInfo_ptr->f32TargetStopDistance  =  0;
        }
    }

    return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_ConflictGearAction

  * EXPLANATION
Event action while the conflict gear flag is true.

*************************************************************************
*/

uint8_t Ctrl_ConflictGearAction(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                tVehDataRx*   stVehDataRx_ptr,
                                tCtrlLongiInfo*      	  stCtrlLongiInfo_ptr)
{
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
    float f32RegardAsStopSpd = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32RegardAsStopSpeed;

    if (1 == stCtrlCommonInfo_ptr->u8ConflictGearFlag)
    {
        if (stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph < f32RegardAsStopSpd)
        {
            stCtrlLongiInfo_ptr->f32TargetVehSpeed = 0;
            stCtrlLongiInfo_ptr->f32TargetAcce = 0;
            stCtrlLongiInfo_ptr->f32TargetStopDistance  =  0;
        }
        else
        {
            stCtrlLongiInfo_ptr->f32TargetVehSpeed = 0;
            stCtrlLongiInfo_ptr->f32TargetAcce = -0.2;
            stCtrlLongiInfo_ptr->f32TargetStopDistance  =  0;
        }
    }

    return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_LimitationLongi

  * EXPLANATION
Limitation of the longitudinal outputs.

*************************************************************************
*/

uint8_t Ctrl_LimitationLongi(tVehDataRx*            stVehDataRx_ptr,
                             tCtrlLongiInfo*        stCtrlLongiInfo_ptr,
                             tCtrlToChassisInfo*    stCtrl2ChassisInfo_ptr,
                             tCtrlCommonInfo*       stCtrlCommonInfo_ptr)
{
  // To set calibration values instead of constants.
  tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
  float f32VehSpd = stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph;
  tCtrlSpeedTrapezoidPhase ePhase = stCtrlLongiInfo_ptr->eSpeedPhase;
  static float f32CtrlReqAccelLimitedPrev = 0.0;
  float k_PebHappenedAcc = 0;
  float b_PebHappenedAcc = 0;
  float f32lowFilterAccFactor = 0.02/0.2;//0.3滤波时间
  float Calib_f32AccMax = 0.5;
  float Calib_f32AccMin = -0.5;
/*===========================
*	Speed limitation
*==========================*/
  // --- PEB speed limitation. 
  stCtrl2ChassisInfo_ptr->f32CtrlReqSpeedLimited = stCtrl2ChassisInfo_ptr->f32CtrlReqSpeedUnlimited;

  if(stCtrl2ChassisInfo_ptr->f32CtrlReqSpeedLimited > stCtrlCommonInfo_ptr->stCtrlPebInfo.f32PebSpeed){
    stCtrl2ChassisInfo_ptr->f32CtrlReqSpeedLimited = stCtrlCommonInfo_ptr->stCtrlPebInfo.f32PebSpeed;
  }
  // --- Upper/Lower speed limitation. 
  if (stCtrl2ChassisInfo_ptr->f32CtrlReqSpeedLimited <= stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32SpeedMin){
    stCtrl2ChassisInfo_ptr->f32CtrlReqSpeedLimited = 0;
  }else if (stCtrl2ChassisInfo_ptr->f32CtrlReqSpeedLimited > stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32SpeedMax){
    stCtrl2ChassisInfo_ptr->f32CtrlReqSpeedLimited = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32SpeedMax;
  }

    // --- speed change rate limitation. (not in use.)
  float f32SpeedGap = 0;
  if(1 == stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebHappened) {
    f32SpeedGap = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32SpeedIncreRatioMax;
  }else{
    f32SpeedGap = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32SpeedIncreRatioMed;
  }

  stCtrl2ChassisInfo_ptr->f32CtrlReqSpeedPrev = stCtrl2ChassisInfo_ptr->f32CtrlReqSpeed;
  if (stCtrl2ChassisInfo_ptr->f32CtrlReqSpeedLimited > stCtrl2ChassisInfo_ptr->f32CtrlReqSpeedPrev + f32SpeedGap){
    stCtrl2ChassisInfo_ptr->f32CtrlReqSpeedRateLimited = stCtrl2ChassisInfo_ptr->f32CtrlReqSpeedPrev + f32SpeedGap;
  }
  else if (stCtrl2ChassisInfo_ptr->f32CtrlReqSpeedLimited < stCtrl2ChassisInfo_ptr->f32CtrlReqSpeedPrev - f32SpeedGap){
    stCtrl2ChassisInfo_ptr->f32CtrlReqSpeedRateLimited = stCtrl2ChassisInfo_ptr->f32CtrlReqSpeedPrev - f32SpeedGap;
  }
  else{
    stCtrl2ChassisInfo_ptr->f32CtrlReqSpeedRateLimited = stCtrl2ChassisInfo_ptr->f32CtrlReqSpeedLimited;
  }
  

/*===========================
*	Acceleration limitation
*==========================*/
  // --- Upper/Lower acceleration limitation.
  if (ePhase == PHASE_EMERGENCY_STOP){
    Calib_f32AccMax = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32EmergStopAccMax;
    Calib_f32AccMin = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32EmergStopAccMin;
    f32lowFilterAccFactor = 0.02/0.1;//0.1filter time
  }else if(ePhase == PHASE_STOP || ePhase == PHASE_STOP_STEERING){
    Calib_f32AccMax = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32AccMax;
    Calib_f32AccMin = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32AccMin;
    f32lowFilterAccFactor = 0.02/0.6;//0.6filter time
  }else{
    Calib_f32AccMax = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32AccMax;
    Calib_f32AccMin = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32AccMin;
    f32lowFilterAccFactor = 0.02/0.2;//0.3滤波时间
  }
  if (stCtrl2ChassisInfo_ptr->f32CtrlReqAccelUnlimited > Calib_f32AccMax){
    stCtrl2ChassisInfo_ptr->f32CtrlReqAccelLimited = Calib_f32AccMax;
  }else if (stCtrl2ChassisInfo_ptr->f32CtrlReqAccelUnlimited < Calib_f32AccMin) {
    stCtrl2ChassisInfo_ptr->f32CtrlReqAccelLimited = Calib_f32AccMin;
  }else{
    stCtrl2ChassisInfo_ptr->f32CtrlReqAccelLimited = stCtrl2ChassisInfo_ptr->f32CtrlReqAccelUnlimited;
  }

  //---一阶滤波  放在u8PebHappened之前
  stCtrl2ChassisInfo_ptr->f32CtrlReqAccelLimited = f32CtrlReqAccelLimitedPrev+
                                                   f32lowFilterAccFactor*(stCtrl2ChassisInfo_ptr->f32CtrlReqAccelLimited-f32CtrlReqAccelLimitedPrev);
  

  // --- Acceleration change rate limitation.
  float f32AccGap = 0;
  if(1 == stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebHappened) {
    f32AccGap = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32AccIncreRatioMax;
  }
  else{
    f32AccGap = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32AccIncreRatioMed;
  }

  stCtrl2ChassisInfo_ptr->f32CtrlReqAccelPrev = stCtrl2ChassisInfo_ptr->f32CtrlReqAccel;
  if (stCtrl2ChassisInfo_ptr->f32CtrlReqAccelLimited > stCtrl2ChassisInfo_ptr->f32CtrlReqAccelPrev + f32AccGap){
    stCtrl2ChassisInfo_ptr->f32CtrlReqAccelRateLimited = stCtrl2ChassisInfo_ptr->f32CtrlReqAccelPrev + f32AccGap;
  }
  else if (stCtrl2ChassisInfo_ptr->f32CtrlReqAccelLimited < stCtrl2ChassisInfo_ptr->f32CtrlReqAccelPrev - f32AccGap){
    stCtrl2ChassisInfo_ptr->f32CtrlReqAccelRateLimited = stCtrl2ChassisInfo_ptr->f32CtrlReqAccelPrev - f32AccGap;
  }
  else{
    stCtrl2ChassisInfo_ptr->f32CtrlReqAccelRateLimited = stCtrl2ChassisInfo_ptr->f32CtrlReqAccelLimited;
  }
  f32CtrlReqAccelLimitedPrev = stCtrl2ChassisInfo_ptr->f32CtrlReqAccelRateLimited;//记住之前的值
/*===========================
*	Stop distance limitation
*==========================*/
  // --- Stop distance limitation.
  if (stCtrl2ChassisInfo_ptr->f32CtrlReqStopDistanceUnlimited > 51){
    stCtrl2ChassisInfo_ptr->f32CtrlReqStopDistanceLimited = 51;
  }
  else if (stCtrl2ChassisInfo_ptr->f32CtrlReqStopDistanceUnlimited < 0){
    stCtrl2ChassisInfo_ptr->f32CtrlReqStopDistanceLimited = 0;
  }
  else{
    stCtrl2ChassisInfo_ptr->f32CtrlReqStopDistanceLimited = stCtrl2ChassisInfo_ptr->f32CtrlReqStopDistanceUnlimited;
  }

/*===========================
*	Final result after limitation.
*==========================*/
  stCtrl2ChassisInfo_ptr->f32CtrlReqSpeed = stCtrl2ChassisInfo_ptr->f32CtrlReqSpeedRateLimited;
  stCtrl2ChassisInfo_ptr->f32CtrlReqAccel = stCtrl2ChassisInfo_ptr->f32CtrlReqAccelRateLimited;
  stCtrl2ChassisInfo_ptr->f32CtrlReqStopDistance = stCtrl2ChassisInfo_ptr->f32CtrlReqStopDistanceLimited;    // stCtrl2ChassisInfo_ptr->f32CtrlReqStopDistance = 19.0;


  return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_SpeedCompensation

  * EXPLANATION
This function will return a gain factor to control speed when the curvature of road change rapidly

*************************************************************************
*/
uint8_t Ctrl_SpeedCompensation(tPathPlannerInfo*   stPathPlannerData,
                               tCtrlCommonInfo*    stCtrlCommonInfo_ptr,
                               tCtrlLongiInfo*     stCtrlLongiInfo_ptr)
{
    uint8_t u8WayPointGap = 5;
    uint8_t u8CurrentBehindIndex = stCtrlCommonInfo_ptr->u8BehindPointIndex;
    uint8_t u8TargetIndex = u8CurrentBehindIndex + u8WayPointGap;

    float f32KappaGapMin = 0.10;
    float f32KappaGapMax = 0.15;

    float f32SpeedGain = 1;

    if (stPathPlannerData->u8PointNum > 0)
    {
        if(u8TargetIndex >= stPathPlannerData->u8PointNum)
        {
            u8TargetIndex = stPathPlannerData->u8PointNum - 1;
        }
    }
    else 
    {
        u8TargetIndex = 0;
    }

    float f32CurrentKappa = stPathPlannerData ->stPathData[u8CurrentBehindIndex].f32WayPointCurvature;
    float f32TargetKappa = stPathPlannerData ->stPathData[u8TargetIndex].f32WayPointCurvature;

    float GainSlope = 1;
    float f32GainMax = 1.0;
    float f32GainMin = 0.75;
    if( fabs(f32TargetKappa - f32CurrentKappa) <f32KappaGapMin )
    {
        f32SpeedGain =  f32GainMax;
    }
    else if(fabs(f32TargetKappa - f32CurrentKappa) > f32KappaGapMax)
    {
        f32SpeedGain = f32GainMin;
    }
    else
    {
        GainSlope = (f32GainMin - f32GainMax) / (f32KappaGapMax -f32KappaGapMin );
        f32SpeedGain = f32GainMax + GainSlope * (fabs(f32TargetKappa - f32CurrentKappa) - f32KappaGapMin);
    }

    if(stCtrlLongiInfo_ptr->f32TargetVehSpeed > 1)
    {
        stCtrlLongiInfo_ptr->f32TargetVehSpeed = f32SpeedGain * stCtrlLongiInfo_ptr->f32TargetVehSpeed;
    }

    stCtrlLongiInfo_ptr->f32SpeedGainFactor = f32SpeedGain;

    return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_TrajSpeedCtrl

  * EXPLANATION
In the condition of trajectory follow, speed planner will provide the target 
speed.  

*************************************************************************
*/

uint8_t Ctrl_TrajSpeedCtrl(tPathPlannerInfo*   stPathPlannerData,
                           tCtrlCommonInfo*    stCtrlCommonInfo_ptr,
                           tCtrlLongiInfo*     stCtrlLongiInfo_ptr)
{
    if (true == stPathPlannerData->u8IsTraj)
    {
        uint8_t index = stCtrlCommonInfo_ptr->u8NearestPointIndexSelectedPose;
        tCtrlSpeedTrapezoidPhase ePhase = stCtrlLongiInfo_ptr->eSpeedPhase;
        if (PHASE_SPEED_INIT == ePhase || PHASE_SPEED_MAINTAIN == ePhase || PHASE_DECELERATION == ePhase)
        {
            stCtrlLongiInfo_ptr->f32TargetVehSpeed = stPathPlannerData->stPathData[index].f32WayPointV * 3.6f;
            g_stVehicleParms.flag_index8 = stPathPlannerData->stPathData[index].f32WayPointA;   // to modify.
        }
    }

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
Ctrl_CalAverageSpeed

  * EXPLANATION
This function will return average speed based on previous recorded wheel speed
*************************************************************************
*/

static uint8_t Ctrl_CalAverageSpeed(tCtrlLongiInfo*      	stCtrlLongiInfo_ptr,
                                    tVehDataRx*   stVehDataRx_ptr)
{
    float f32SpeedSum = 0;

    for (uint8_t i = 9; i > 0; i--)
    {
        stCtrlLongiInfo_ptr->arrVehSpeedHistory[i] = stCtrlLongiInfo_ptr->arrVehSpeedHistory[i-1];
    }
    stCtrlLongiInfo_ptr->arrVehSpeedHistory[0] = stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph;
    
    for (uint8_t i = 0; i < 10; i++)
    {
        f32SpeedSum += stCtrlLongiInfo_ptr->arrVehSpeedHistory[i];
    }

    stCtrlLongiInfo_ptr->f32AverageSpeed = f32SpeedSum / 10.0f;
    
	return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Condition_Judge

  * EXPLANATION
TBD
*************************************************************************
*/

static uint8_t Condition_Judge(tCtrlLongiInfo*  stCtrlLongiInfo_ptr)
{
    float f32TarSpd = stCtrlLongiInfo_ptr->f32TargetVehSpeed;
    float f32AverageSpd = stCtrlLongiInfo_ptr->f32AverageSpeed;

    if ( (f32AverageSpd < f32TarSpd && f32TarSpd - f32AverageSpd > 0.8f) || stCtrlLongiInfo_ptr->u16AcceCount != 0 )
    {
        stCtrlLongiInfo_ptr->u8LongiCtrlStatus = Acceleration;
        stCtrlLongiInfo_ptr->u16DeceCount      = 0;
        stCtrlLongiInfo_ptr->u16RemainCount1   = 0;
        stCtrlLongiInfo_ptr->u16RemainCount2   = 0;
    }
    else if ( (f32AverageSpd > f32TarSpd && f32AverageSpd - f32TarSpd > 0.8f) || stCtrlLongiInfo_ptr->u16DeceCount != 0 )
    {
        stCtrlLongiInfo_ptr->u8LongiCtrlStatus = Deceleration;
        stCtrlLongiInfo_ptr->u16AcceCount      = 0;
        stCtrlLongiInfo_ptr->u16RemainCount1   = 0;
        stCtrlLongiInfo_ptr->u16RemainCount2   = 0;
    }
    else
    {
        stCtrlLongiInfo_ptr->u8LongiCtrlStatus = ConstantSpeed;
        stCtrlLongiInfo_ptr->u16AcceCount      = 0;
        stCtrlLongiInfo_ptr->u16DeceCount      = 0;
    }

	return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME
Trapezoid_Accelerate

  * EXPLANATION
TBD
*************************************************************************
*/

static uint8_t Trapezoid_Accelerate(tCtrlLongiInfo*     stCtrlLongiInfo_ptr)
{
    float f32TargetSpd = stCtrlLongiInfo_ptr->f32TargetVehSpeed;
    float f32AverageSpd = stCtrlLongiInfo_ptr->f32AverageSpeed;
    float f32StartingAcceMax = f32TargetSpd * 0.8 / (50.0f * 3.0f * 3.6f);
    float f32TargetAcce = 0;
    uint16_t u16AcceCnt = stCtrlLongiInfo_ptr->u16AcceCount;


    if (f32AverageSpd < f32TargetSpd * 0.9f)
    {
        if(u16AcceCnt <= 49)
        {
            f32TargetAcce = f32StartingAcceMax * (float)u16AcceCnt;
            u16AcceCnt++;
        }
        else if (u16AcceCnt <= 99)
        {
            f32TargetAcce = f32StartingAcceMax * 50.0f;
            u16AcceCnt++;
        }
        else if (u16AcceCnt <= 149)
        {
            f32TargetAcce = f32StartingAcceMax * (float)(149 - u16AcceCnt);
            u16AcceCnt++;
        }
        else
        {
            u16AcceCnt = 0;
            stCtrlLongiInfo_ptr->u8LongiCtrlStatus = 3;
        }
    }
    else
    {
        u16AcceCnt = 0;
        stCtrlLongiInfo_ptr->u8LongiCtrlStatus = 3;
    }

    stCtrlLongiInfo_ptr->f32TargetAcce = f32TargetAcce;
    stCtrlLongiInfo_ptr->u16AcceCount = u16AcceCnt;

	return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Trapezoid_Decelerate

  * EXPLANATION
TBD
*************************************************************************
*/

static uint8_t Trapezoid_Decelerate(tCtrlLongiInfo*   stCtrlLongiInfo_ptr)
{

    float f32TargetSpd = stCtrlLongiInfo_ptr->f32TargetVehSpeed;
    float f32AverageSpd = stCtrlLongiInfo_ptr->f32AverageSpeed;
    float f32DecelMax = -1.0f * 0.9f * (3.0f - f32TargetSpd) / (50.0f * 1.0f * 3.6f);
    uint16_t u16DecelCnt = stCtrlLongiInfo_ptr->u16DeceCount;
    float f32TargetAcce = 0;

    if (f32AverageSpd > f32TargetSpd * 0.75f)
    {
        if(u16DecelCnt <= 49)
        {
            f32TargetAcce = f32DecelMax * (float)u16DecelCnt;
            u16DecelCnt++;
        }
        else if (u16DecelCnt <= 99)
        {
            f32TargetAcce = f32DecelMax * 50.0f;
            u16DecelCnt++;
        }
        else if (u16DecelCnt <= 149)
        {
            f32TargetAcce = f32DecelMax * (float)(149 - u16DecelCnt);
            u16DecelCnt++;
        }
        else
        {
            u16DecelCnt = 0;
            stCtrlLongiInfo_ptr->u8LongiCtrlStatus = 3;
        }
    }
    else
    {
        u16DecelCnt = 0;
        stCtrlLongiInfo_ptr->u8LongiCtrlStatus = 3;
    }

    stCtrlLongiInfo_ptr->f32TargetAcce = f32TargetAcce;
    stCtrlLongiInfo_ptr->u16DeceCount = u16DecelCnt;

	return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_Get_SteeringPercentage

  * EXPLANATION
TBD
*************************************************************************
*/

static float Ctrl_Get_SteeringPercentage (tVehDataRx*   stVehDataRx_ptr,
                                   		  tCtrlLatResult*            stCtrlLatResult_ptr)
{
    float f32SteeringSpeedGap = 0;
    float f32SteeringSpeedPercentage = 0;

	float CTRL_STEER_GAP_MAX = 10;
	float CTRL_STEER_SPEED_RATIO = 0.25;

    f32SteeringSpeedGap = stCtrlLatResult_ptr->f32TargetSteerAngleFiltered - stVehDataRx_ptr->sVehEPSInfo.f32StrWhlAngDeg;

    if (fabs(f32SteeringSpeedGap) >= CTRL_STEER_GAP_MAX)
    {
        f32SteeringSpeedGap = CTRL_STEER_GAP_MAX;
    }

    if (fabs(f32SteeringSpeedGap) < 5)
    {
        f32SteeringSpeedGap = 0;
    }

    f32SteeringSpeedPercentage = 1.0 - CTRL_STEER_SPEED_RATIO*fabs(f32SteeringSpeedGap / CTRL_STEER_GAP_MAX);

    return f32SteeringSpeedPercentage;
}



/**
*************************************************************************
  * FUNCTION_NAME
Speed_Remain

  * EXPLANATION
TBD
*************************************************************************
*/

static uint8_t Speed_Remain(tCtrlLongiInfo*    stCtrlLongiInfo_ptr)
{
    float f32TargetSpd = stCtrlLongiInfo_ptr->f32TargetVehSpeed;
    float f32AverageSpd = stCtrlLongiInfo_ptr->f32AverageSpeed;
    uint16_t u16RemainCnt1 = stCtrlLongiInfo_ptr->u16RemainCount1;
    uint16_t u16RemainCnt2 = stCtrlLongiInfo_ptr->u16RemainCount2;
    float f32TargetAcce = 0;

    if(f32TargetSpd <= 2.0f)
    {
        if ( f32AverageSpd < 1.1*f32TargetSpd && f32AverageSpd > 0.8*f32TargetSpd )
        {
            f32TargetAcce = 0.0f;
        }
        else
        {
            if (f32AverageSpd > f32TargetSpd && u16RemainCnt2 <= 99)
            {
                f32TargetAcce = -0.02f;
                u16RemainCnt2++;

                if (f32AverageSpd > 1.5f * f32TargetSpd)
                {
                    f32TargetAcce = -0.04f;
                    u16RemainCnt2++;
                }
            }
            else if (f32AverageSpd < f32TargetSpd && u16RemainCnt1 <= 99)
            {
                f32TargetAcce = 0.02f;
                u16RemainCnt1++;
                if (f32AverageSpd < 0.6f * f32TargetSpd)
                {
                    f32TargetAcce = 0.04f;
                    if (f32AverageSpd < 0.4f * f32TargetSpd)
                    {
                        f32TargetAcce = 0.06f;
                    }
                }
            }
            else
            {
                u16RemainCnt1 = 0;
                u16RemainCnt2 = 0;
            }
        }
    }
    else
    {
        if (f32AverageSpd < 1.1f * f32TargetSpd && f32AverageSpd > 0.9f * f32TargetSpd)
        {
            f32TargetAcce = 0.0f;
        }
        else
        {
            if (f32AverageSpd > f32TargetSpd && u16RemainCnt2 <= 99)
            {
               f32TargetAcce = -0.05f;
               u16RemainCnt2++;
            }
            else if (f32AverageSpd < f32TargetSpd && u16RemainCnt1 <= 99)
            {
               f32TargetAcce = 0.05f;
               u16RemainCnt1++;
            }
            else
            {
                u16RemainCnt1 = 0;
                u16RemainCnt2 = 0;
            }
        }
    }
    stCtrlLongiInfo_ptr->u16RemainCount1 = u16RemainCnt1;
    stCtrlLongiInfo_ptr->u16RemainCount2 = u16RemainCnt2;
    stCtrlLongiInfo_ptr->f32TargetAcce = f32TargetAcce;

	return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME
CurveAcceCompensation

  * EXPLANATION
TBD
*************************************************************************
*/

static uint8_t CurveAcceCompensation(tCtrlLongiInfo*   stCtrlLongiInfo_ptr,
					          		 tCtrlLatResult*        stCtrlLatResult_ptr)
{
    float f32TargetAcce = stCtrlLongiInfo_ptr->f32TargetAcce;
    uint16_t u16RemainCnt2 = stCtrlLongiInfo_ptr->u16RemainCount2;
    float f32TarSteerAngle = stCtrlLatResult_ptr->f32TargetSteerAngleFiltered;

	if(stCtrlLongiInfo_ptr->u8LongiCtrlStatus == 3)
    {
        if (f32TarSteerAngle > 0.0f && f32TarSteerAngle <= 180.0f)
        {
            f32TargetAcce = 1.0f * f32TargetAcce;
        }
        else if (f32TarSteerAngle > 180.0f && f32TarSteerAngle <= 360.0f && u16RemainCnt2 == 0)
        {
            f32TargetAcce = 1.1f * f32TargetAcce;
        }
        else if (f32TarSteerAngle > 360.0f && f32TarSteerAngle <= 450.0f && u16RemainCnt2 == 0)
        {
            f32TargetAcce = 1.2f * f32TargetAcce;
        }
        else if (f32TarSteerAngle < 0.0f && f32TarSteerAngle >= -180.0f)
        {
            f32TargetAcce = 1.0f * f32TargetAcce;
        }
        else if (f32TarSteerAngle < -180.0f && f32TarSteerAngle >= -360.0f && u16RemainCnt2 == 0)
        {
            f32TargetAcce = 1.1f * f32TargetAcce;
        }
        else if (f32TarSteerAngle < -360.0f && f32TarSteerAngle >= -450.0f && u16RemainCnt2 == 0)
        {
            f32TargetAcce = 1.2f * f32TargetAcce;
        }
        else
        {
            f32TargetAcce = 1.0f * f32TargetAcce;
        }
    }
	else
	{
		f32TargetAcce = 1.0f * f32TargetAcce;
	}

    stCtrlLongiInfo_ptr->f32TargetAcce = f32TargetAcce;

	return E_OK;
}


void Ctrl_GetLongiError(tTrajectoryFrame* stTrajFrame_ptr,
                         tTrajLongiController* stTrajLongiController_ptr)
{
    float refStation = stTrajLongiController_ptr->f32PosTrajReq;
    float refSpeed   = stTrajLongiController_ptr->f32VelTrajReq;
    stTrajLongiController_ptr->f32StationErr = refStation - stTrajFrame_ptr->f32s;
    stTrajLongiController_ptr->f32SpeedErr   = refSpeed - stTrajFrame_ptr->f32s_dot;
}



void Ctrl_LongiVel(tCtrlCommonInfo*        stCtrlCommonInfo_ptr,
                   tPathPlannerInfo*       stPathPlannerData_ptr,
                   tTrajLongiController*   stTrajLongiController_ptr,
                   tCtrlLongiInfo*         stCtrlLongiInfo_ptr)
{
    static int count = 0;
    int MAXINTGRALTIME = 40; //max cycle
    if(stCtrlCommonInfo_ptr->u8NearestPointIndexCurPose != stCtrlCommonInfo_ptr->u8NearestPointIndexCurPosePre)
    {
        stCtrlCommonInfo_ptr->u8NearestPointIndexCurPosePre = stCtrlCommonInfo_ptr->u8NearestPointIndexCurPose;
        count = 0;
    }

  if (true == stPathPlannerData_ptr->u8IsTraj && stPathPlannerData_ptr->u8PointNum >0 )
  {
      int indexffw = GetTrajIndexByTime(stCtrlCommonInfo_ptr, stPathPlannerData_ptr,  0,     true);
      int indexfb  = GetTrajIndexByTime(stCtrlCommonInfo_ptr, stPathPlannerData_ptr,  count, false);
      GetTrajDesired((uint8_t)indexffw,(uint8_t)indexfb,      stPathPlannerData_ptr,  stTrajLongiController_ptr);

      count++;
      if(count > MAXINTGRALTIME)
      {
        count = MAXINTGRALTIME;
      }

      uint8_t index = stCtrlCommonInfo_ptr->u8NearestPointIndexCurPose;
      float stationCurr = stPathPlannerData_ptr->stPathData[index].f32WayPointS;
      tCtrlSpeedTrapezoidPhase ePhase = stCtrlLongiInfo_ptr->eSpeedPhase;
      if (PHASE_SPEED_INIT == ePhase || PHASE_SPEED_MAINTAIN == ePhase || PHASE_DECELERATION == ePhase)
      {
          // float poserr = g_stTrjLongiCtroller.f32PosTrajReq - stationCurr;
          // float targetVel = 0.5 * poserr + g_stTrjLongiCtroller.f32VelTrajReq;
          // float targetVel = g_stTrjLongiCtroller.f32VelTrajReq;

          uint8_t indexmax = MIN(index+20, stPathPlannerData_ptr->u8PointNum-1);
          float targetVel = stPathPlannerData_ptr->stPathData[indexmax].f32WayPointV;
          stCtrlLongiInfo_ptr->f32TargetVehSpeed = targetVel * 3.6;
          stCtrlLongiInfo_ptr->f32PPTargetVehSpeed = targetVel * 3.6;  
      }

  }

    
    g_stVehicleParms.flag_index7 = g_stPathPlannerData.stPathData[g_stCtrlCommonInfo.u8NearestPointIndexCurPose].f32WayPointV;
    g_stVehicleParms.flag_index8 = g_stPathPlannerData.stPathData[g_stCtrlCommonInfo.u8NearestPointIndexCurPose].f32WayPointA;
}
