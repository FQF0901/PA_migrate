#include "ctrl_peb_algo_new.h"
#include "ctrl_comm_func.h"

static uint8_t control_PEB_algo(tVehDataRx*          stVehDataRx_ptr,  
                                tCtrlUssInfo*        stCtrlUssInfo_ptr, 
                                tStateMachine*       stStateMachine_ptr,
                                tCtrlCommonInfo*     stCtrlCommonInfo_ptr,
                                tPathPlannerInfo*    stPathPlannerInfo_ptr,
                                tCtrlFuncFsmInfo*     stCtrlApaShellInfo_ptr,
                                tCtrlLongiInfo*      stCtrlLongiInfo_ptr);
static uint8_t control_PEB_init(tVehDataRx*          stVehDataRx_ptr, 
                                tPathPlannerInfo*    stPathPlannerInfo_ptr,
                                tCtrlUssInfo* 	     stCtrlUssInfo_ptr, 
                                tCtrlFuncFsmInfo*     stCtrlApaShellInfo_ptr,
                                tCtrlCommonInfo*     stCtrlCommonInfo_ptr);                                   
static uint8_t control_PEB_input_filter(tCtrlUssInfo*         stCtrlUssInfo_ptr);
static uint8 control_PEB_distance_factor(tVehDataRx*   stVehDataRx_ptr, 
                                         tCtrlFuncFsmInfo*     stCtrlApaShellInfo_ptr,
                                         tCtrlUssInfo* 	stCtrlUssInfo_ptr);
static uint8 control_PEB_TTC(tVehDataRx*   stVehDataRx_ptr,
                             tCtrlLongiInfo*   stCtrlLongiInfo_ptr,
                                    tCtrlUssInfo* 	stCtrlUssInfo_ptr);                               
static uint8 control_PEB_level(tCtrlUssInfo* 	  stCtrlUssInfo_ptr,
                               tCtrlCommonInfo*  stCtrlCommonInfo_ptr);
static uint8_t control_PEB_output(tCtrlUssInfo*          stCtrlUssInfo_ptr, 
                                  tVehDataRx*            stVehDataRx_ptr, 
                                  tStateMachine*         stStateMachine_ptr,
                                  tCtrlCommonInfo*       stCtrlCommonInfo_ptr,
                                  tPathPlannerInfo*      stPathPlannerInfo_ptr,
                                  tCtrlLongiInfo*        stCtrlLongiInfo_ptr);
// static uint8_t control_PEB_speed_plan(tVehDataRx*    stVehDataRx_ptr,
//                                       tCtrlUssInfo* 	     stCtrlUssInfo_ptr,
//                                       tCtrlFuncFsmInfo*     stCtrlApaShellInfo_ptr,
//                                       tCtrlCommonInfo*    stCtrlCommonInfo_ptr);

#define CtrlPara_START_SEC_VAR		// Memory allocation
#include "proj_MemMap.h"
#define CtrlPara_STOP_SEC_VAR	// Memory allocation end.
#include "proj_MemMap.h"

#define NUM_FRONT       8
#define NUM_REAR        16
#define NUM_RIGHT_FRONT 16
#define NUM_RIGHT_REAR  17
#define NUM_LEFT_FRONT  18
#define NUM_LEFT_REAR   19


/**
*************************************************************************
  * FUNCTION_NAME
control_PEB_detection

  * EXPLANATION
PEB interface. Detect if PEB is triggered.

*************************************************************************
*/


uint8_t control_PEB_detection(tCtrlCommonInfo*       stCtrlCommonInfo_ptr,
                              tVehDataRx*            stVehDataRx_ptr,
                              tCtrlUssInfo*          stCtrlUssInfo_ptr,
                              tStateMachine*         stStateMachine_ptr,
                              tPathPlannerInfo*      stPathPlannerInfo_ptr,
                              tCtrlFuncFsmInfo*     stCtrlApaShellInfo_ptr,
                              tCtrlLongiInfo*        stCtrlLongiInfo_ptr)
{
  tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
  if (stCalibPF_ptr->stPFPEBCalib.Calib_f32PebActive > 0.5){
    stCtrlUssInfo_ptr->u16UssOn = 1;
  }
  else{
    stCtrlUssInfo_ptr->u16UssOn = 0;
  }

  if (stCalibPF_ptr->stPFPEBCalib.Calib_f32PebActiveSide > 0.5){
    stCtrlUssInfo_ptr->u16UssSideOn = 1;
  }
  else{
    stCtrlUssInfo_ptr->u16UssSideOn = 0;
  }
  PRINTF_ADAS("[control_PEB_detection] %d %d", stCtrlCommonInfo_ptr->eCtrlFuncStatus, stCtrlUssInfo_ptr->u16UssOn);
  if((CTRL_MODULE_ACTIVE == stCtrlCommonInfo_ptr->eCtrlFuncStatus) && (1 == stCtrlUssInfo_ptr->u16UssOn)){
    control_PEB_algo(stVehDataRx_ptr,stCtrlUssInfo_ptr,stStateMachine_ptr, stCtrlCommonInfo_ptr,
                     stPathPlannerInfo_ptr, stCtrlApaShellInfo_ptr,stCtrlLongiInfo_ptr);
  }
  else{
    ;   // Set ePebHappened to zero?
  }
  return E_OK;
}




/**
*************************************************************************
  * FUNCTION_NAME 
control_PEB_algo. 

  * EXPLANATION   
PEB main algo New.

*************************************************************************
*/

static uint8_t control_PEB_algo(tVehDataRx*          stVehDataRx_ptr,
                                tCtrlUssInfo*        stCtrlUssInfo_ptr,
                                tStateMachine*       stStateMachine_ptr,
                                tCtrlCommonInfo*     stCtrlCommonInfo_ptr,
                                tPathPlannerInfo*    stPathPlannerInfo_ptr,
                                tCtrlFuncFsmInfo*     stCtrlApaShellInfo_ptr,
                                tCtrlLongiInfo*      stCtrlLongiInfo_ptr)
{
  stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebLevel = stPathPlannerInfo_ptr->u8PebLevel;
// PEB initialization
  control_PEB_init(stVehDataRx_ptr, stPathPlannerInfo_ptr,stCtrlUssInfo_ptr, stCtrlApaShellInfo_ptr,stCtrlCommonInfo_ptr);
// Data filtering
  control_PEB_input_filter(stCtrlUssInfo_ptr);
// peb Distance factor
  control_PEB_distance_factor(stVehDataRx_ptr,stCtrlApaShellInfo_ptr,stCtrlUssInfo_ptr);    
// TTC calculation
    control_PEB_TTC(stVehDataRx_ptr, stCtrlLongiInfo_ptr,stCtrlUssInfo_ptr);
// PEB Level
    control_PEB_level(stCtrlUssInfo_ptr,stCtrlCommonInfo_ptr);    
// Output assignment
  control_PEB_output(stCtrlUssInfo_ptr, stVehDataRx_ptr,stStateMachine_ptr,stCtrlCommonInfo_ptr,
                     stPathPlannerInfo_ptr, stCtrlLongiInfo_ptr);
// Speed planning
//   control_PEB_speed_plan(stVehDataRx_ptr,stCtrlUssInfo_ptr,stCtrlApaShellInfo_ptr,stCtrlCommonInfo_ptr);
  return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME 
control_PEB_init. 

  * EXPLANATION   
This function indicates whether there are obstacles that cannot be detected.

*************************************************************************
*/

static uint8_t control_PEB_init(tVehDataRx*          stVehDataRx_ptr, 
                                tPathPlannerInfo*    stPathPlannerInfo_ptr,
                                tCtrlUssInfo* 	     stCtrlUssInfo_ptr, 
                                tCtrlFuncFsmInfo*     stCtrlApaShellInfo_ptr,
                                tCtrlCommonInfo*     stCtrlCommonInfo_ptr)
{
  tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
  float32 f32VehSpdKph = stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph;
  float f32VehRadius = 1000.0;
  f32VehRadius = Ctrl_InstanceRadiusCal(stVehDataRx_ptr);
  if(f32VehRadius>1000.0){
    f32VehRadius = 1000.0;
  } else if(f32VehRadius<-1000.0){
    f32VehRadius = -1000.0;
  }else if(f32VehRadius<4.0 && f32VehRadius>0){
    f32VehRadius = 4.0;
  }else if(f32VehRadius>-4.0 && f32VehRadius<0){
    f32VehRadius = -4;
  }

  stCtrlUssInfo_ptr->f32VehCurvature = 1/f32VehRadius;
    
  if(LSAD_CRUISE == stCtrlApaShellInfo_ptr->eLsadFuncType){
    stCtrlUssInfo_ptr->f32ReduceRelativeA = -1.2; //巡航过程中减速最大减加速度
    stCtrlUssInfo_ptr->f32StopRelativeA = -1.8; //巡航过程中的最大减加速度
    stCtrlUssInfo_ptr->f32ActuatReactTime = stCalibPF_ptr->stPFPEBCalib.Calib_f32ActuatReactTime; //车辆响应时间
  }else{
    stCtrlUssInfo_ptr->f32ReduceRelativeA = stCalibPF_ptr->stPFPEBCalib.Calib_f32ReduceRelativeA; //泊车和巡航过程中减速最大减加速度
    stCtrlUssInfo_ptr->f32StopRelativeA = stCalibPF_ptr->stPFPEBCalib.Calib_f32StopRelativeA; //泊车和巡航过程中的最大减加速度
    stCtrlUssInfo_ptr->f32ActuatReactTime = stCalibPF_ptr->stPFPEBCalib.Calib_f32ActuatReactTime; //车辆响应时间
  }
    
  stCtrlUssInfo_ptr->f32TTCSafetyTime = fabs((f32VehSpdKph/3.6)/ stCtrlUssInfo_ptr->f32StopRelativeA);
  stCtrlUssInfo_ptr->f32UssMinDistance = 7.5;
  if(2 == stPathPlannerInfo_ptr->u8PebLevel){
    stCtrlUssInfo_ptr->f32SafeDit = stCalibPF_ptr->stPFPEBCalib.Calib_f32PebLevel2SafeDit; //泊车和巡航过程刹停后的安全距离
  }
  else if(1 == stPathPlannerInfo_ptr->u8PebLevel){
    stCtrlUssInfo_ptr->f32SafeDit = stCalibPF_ptr->stPFPEBCalib.Calib_f32PebLevel1SafeDit; //泊车和巡航过程刹停后的安全距离
  }else{
    stCtrlUssInfo_ptr->f32SafeDit = stCalibPF_ptr->stPFPEBCalib.Calib_f32PebLevel0SafeDit; //泊车和巡航过程刹停后的安全距离
  }
  stCtrlUssInfo_ptr->f32SideSafeDit = 0.22;//侧边的PEB安全距离单独计算   
    

  stCtrlUssInfo_ptr->bPebStopFlagFinal = FALSE;
  for (int i = 0; i < PDC_ZONE_NUM; i++){
    stCtrlUssInfo_ptr->f32PebDistance[i] = 7.5;
  }
  return E_OK;
}


static uint8_t control_PEB_input_filter(tCtrlUssInfo*   stCtrlUssInfo_ptr)
{
  for (int i = 0; i < PDC_ZONE_NUM; ++i){
    stCtrlUssInfo_ptr->f32PEBInputDistance[i] = (float)stCtrlUssInfo_ptr->u16PebDistanceConverted[i]/(float)100.0;
  }

  return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME 
control_PEB_distance_factor. 

  * EXPLANATION   
根据

*************************************************************************
*/

static uint8 control_PEB_distance_factor(tVehDataRx*    stVehDataRx_ptr, 
                                         tCtrlFuncFsmInfo*     stCtrlApaShellInfo_ptr,
                                         tCtrlUssInfo* 	stCtrlUssInfo_ptr)
{
  tVehActualGear eVehActualGear = stVehDataRx_ptr->sVehVCUInfo.eVehActualGear;
  float32 f32SafeDit = stCtrlUssInfo_ptr->f32SafeDit; //泊车和巡航过程刹停后的安全距离
  float32 f32VehSpdMps = stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph/3.6;
  float32 f32PebDisFactor[PDC_ZONE_NUM] = {0.0}; 
  uint8 bPEBUssNumberEnbl[PDC_ZONE_NUM] = {0};
  float f32VehCurvature = stCtrlUssInfo_ptr->f32VehCurvature;
  float f32VehMaxCurvature = 1.0/4.2;//角雷达更不容易触发EB

  for (int i = 0; i < PDC_ZONE_NUM; ++i){      
    f32PebDisFactor[i] = 1;//默认不考虑距离有系数
    bPEBUssNumberEnbl[i] = 1;//默认不考虑距离有系数
    if(D_GEAR==eVehActualGear){        
      if(i==16 ||i==18){
        f32PebDisFactor[i] = 0;//TTC计算不看侧边雷达
        bPEBUssNumberEnbl[i] = 1;//
      }else if(i==6 || i==7){
        f32PebDisFactor[i] = -f32VehCurvature/f32VehMaxCurvature;  
      } else if(i==0 || i==1){
        f32PebDisFactor[i] = f32VehCurvature/f32VehMaxCurvature;
        f32PebDisFactor[i] = fmax(f32PebDisFactor[i],0.5);//保证TTC可以降速
      } else if((i>=8 && i<=15)||(i == 17)||(i == 19)){
        f32PebDisFactor[i] = 0;//往前不看后边的雷达
        bPEBUssNumberEnbl[i] = 0;//往前不看后边的雷达
      } else{
        ;
      }
    }else if(R_GEAR==eVehActualGear){
      if(i==17|| i==18){
        f32PebDisFactor[i] = 0;//TTC计算不看侧边雷达
        bPEBUssNumberEnbl[i] = 1;//
      }else if(i==19 || i==16){
        f32PebDisFactor[i] = 0;//TTC计算不看侧边雷达
        bPEBUssNumberEnbl[i] = 1;//
      }else if(i==15 || i==8){
        f32PebDisFactor[i] = 0.8*fabs(f32VehCurvature/f32VehMaxCurvature);//8和15更不考虑碰撞
      }else if(i==14 || i==9){
        f32PebDisFactor[i] = fabs(f32VehCurvature/f32VehMaxCurvature);  
      }else if(i>=0 && i<=7){
        f32PebDisFactor[i] = 0;//往后不看正前边的雷达
        bPEBUssNumberEnbl[i] = 0;//往后不看正前边的雷达
      }else{
        ;
      }
    }else{
      f32PebDisFactor[i] = 0;//非DR档不开PEB
      bPEBUssNumberEnbl[i] = 0;//非DR档不开PEB
    }
    f32PebDisFactor[i] = fmax(f32PebDisFactor[i],0.05);
    stCtrlUssInfo_ptr->f32PebDistance[i] = stCtrlUssInfo_ptr->f32PEBInputDistance[i]/f32PebDisFactor[i]
                                          -f32SafeDit-stCtrlUssInfo_ptr->f32ActuatReactTime*f32VehSpdMps;
  }
  memcpy(stCtrlUssInfo_ptr->f32PebDisFactor,f32PebDisFactor,sizeof(f32PebDisFactor));
  memcpy(stCtrlUssInfo_ptr->bPEBUssNumberEnbl,bPEBUssNumberEnbl,sizeof(bPEBUssNumberEnbl));
  return E_OK;
}

static uint8 control_PEB_TTC(tVehDataRx*   stVehDataRx_ptr,
                             tCtrlLongiInfo*   stCtrlLongiInfo_ptr,
                             tCtrlUssInfo* 	stCtrlUssInfo_ptr)
{
  float32 f32StopRelativeA = stCtrlUssInfo_ptr->f32StopRelativeA; //泊车和巡航过程中的最大减加速度
  float32 f32SafeDit = stCtrlUssInfo_ptr->f32SafeDit; //泊车和巡航过程刹停后的安全距离
  float32 f32TempFactor = 0;//temp < 0 %相当于车停后匀加速运动了
  float32 f32PebMinSpdDistance = 0;//
  float32 f32VehSpdMps = stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph/3.6;
  tVehActualGear eVehActualGear = stVehDataRx_ptr->sVehVCUInfo.eVehActualGear;
  for (int i = 0; i < PDC_ZONE_NUM; ++i)
  {                            
    if(stCtrlUssInfo_ptr->f32PebDistance[i]<0.01){
      stCtrlUssInfo_ptr->f32PebTTCTime[i] = 0.0;//剩余距离为负数，肯定碰撞
      stCtrlUssInfo_ptr->f32PebDistance[i] = 0.0;
    }else if(f32VehSpdMps<0.05){
      stCtrlUssInfo_ptr->f32PebTTCTime[i] = 20.0;//车速很小时默认
    }else if(fabs(f32StopRelativeA)<0.001){
      stCtrlUssInfo_ptr->f32PebTTCTime[i] = stCtrlUssInfo_ptr->f32PebDistance[i]/f32VehSpdMps;//匀速运动
    }else{
      f32TempFactor = f32VehSpdMps*f32VehSpdMps+2*f32StopRelativeA*stCtrlUssInfo_ptr->f32PebDistance[i];
      if(f32TempFactor<0){
        stCtrlUssInfo_ptr->f32PebTTCTime[i] = 20.0;//相当于车停后匀加速运动了
      }else{
        stCtrlUssInfo_ptr->f32PebTTCTime[i] = (-f32VehSpdMps+sqrt(f32TempFactor))/f32StopRelativeA;
      }
    }
    stCtrlUssInfo_ptr->f32PebTTCSpd[i] = sqrt(fabs(2*(stCtrlUssInfo_ptr->f32ReduceRelativeA)*stCtrlUssInfo_ptr->f32PebDistance[i]))*3.6;//f32StopRelativeA+0.1安全考虑，计算车速更小  
    if(stCtrlUssInfo_ptr->f32PebDistance[i]<0.7 && stCtrlLongiInfo_ptr->f32TargetStopDistance<0.6){
      stCtrlUssInfo_ptr->f32PebTTCSpd[i] = fmin(stCtrlUssInfo_ptr->f32PebTTCSpd[i],0.8);//短路径限速
    }
  }
  return E_OK;
      } 

static uint8 control_PEB_level(tCtrlUssInfo* 	  stCtrlUssInfo_ptr,
                               tCtrlCommonInfo*  stCtrlCommonInfo_ptr)
{ 
  float32 f32SafeDit = stCtrlUssInfo_ptr->f32SafeDit; //泊车和巡航过程刹停后的安全距离
  stCtrlCommonInfo_ptr->stCtrlPebInfo.f32PebSpeed = 15.0;
  for (int i = 0; i < PDC_ZONE_NUM; ++i){
    if(stCtrlUssInfo_ptr->f32PEBInputDistance[i]<stCtrlUssInfo_ptr->f32UssMinDistance){
      stCtrlUssInfo_ptr->f32UssMinDistance = stCtrlUssInfo_ptr->f32PEBInputDistance[i];
    }
    if(stCtrlUssInfo_ptr->f32PebTTCTime[i]<stCtrlUssInfo_ptr->f32TTCMinTime){
      stCtrlUssInfo_ptr->f32TTCMinTime = stCtrlUssInfo_ptr->f32PebTTCTime[i];//保证不发生PEB时，也能输出时间
    }
    if(stCtrlUssInfo_ptr->f32PebDistance[i]<stCtrlUssInfo_ptr->f32TTCPebDistance){
      stCtrlUssInfo_ptr->f32TTCPebDistance = stCtrlUssInfo_ptr->f32PebDistance[i];//保证不发生PEB时，也能输出时间
    }
    //单独针对角雷达针对原始的输入信号限速
    if((i==0 || i==7|| i==8 || i==15)&&(stCtrlUssInfo_ptr->bPEBUssNumberEnbl[i] == 1)){
      if(stCtrlUssInfo_ptr->f32PEBInputDistance[i]<0.8){
        stCtrlUssInfo_ptr->f32PebTTCSpd[i] = fmin(stCtrlUssInfo_ptr->f32PebTTCSpd[i],1.2);
        }
      else if(stCtrlUssInfo_ptr->f32PEBInputDistance[i]<0.5){
        stCtrlUssInfo_ptr->f32PebTTCSpd[i] = fmin(stCtrlUssInfo_ptr->f32PebTTCSpd[i],0.8);
        }
      } 
    if(stCtrlUssInfo_ptr->f32PebTTCSpd[i]<stCtrlCommonInfo_ptr->stCtrlPebInfo.f32PebSpeed){
      stCtrlCommonInfo_ptr->stCtrlPebInfo.f32PebSpeed = stCtrlUssInfo_ptr->f32PebTTCSpd[i];
      stCtrlUssInfo_ptr->u8PebUssTTCSpdNumber = i;
      stCtrlUssInfo_ptr->f32TTCPebDistance = stCtrlUssInfo_ptr->f32PebDistance[i];
      }

    //前后侧边的雷达安全距离单独计算
    if(i==17 || i==19){
      f32SafeDit = stCtrlUssInfo_ptr->f32SideSafeDit;
    }else if(i==16 || i==18){
      f32SafeDit = 0.26;
    }else if(i==0 || i==7|| i==8 || i==15){
      f32SafeDit = 0.35;
    }
    if((stCtrlUssInfo_ptr->f32PebTTCTime[i]<stCtrlUssInfo_ptr->f32TTCSafetyTime  ||
       stCtrlUssInfo_ptr->f32PEBInputDistance[i]<(f32SafeDit))&&(stCtrlUssInfo_ptr->bPEBUssNumberEnbl[i] == 1)){
      stCtrlUssInfo_ptr->bPebStopFlagDirection[i] = TRUE;
      stCtrlUssInfo_ptr->bPebStopFlagFinal = TRUE;
      stCtrlUssInfo_ptr->f32TTCMinTime = stCtrlUssInfo_ptr->f32PebTTCTime[i];
      stCtrlUssInfo_ptr->f32TTCPebDistance = stCtrlUssInfo_ptr->f32PebDistance[i];
    }else{
      stCtrlUssInfo_ptr->bPebStopFlagDirection[i] = FALSE;
    }
  }  
  return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME 
control_PEB_output. 

  * EXPLANATION   
This function is used for output.

*************************************************************************
*/

static uint8_t control_PEB_output(tCtrlUssInfo*          stCtrlUssInfo_ptr, 
                                  tVehDataRx*            stVehDataRx_ptr, 
                                  tStateMachine*         stStateMachine_ptr,
                                  tCtrlCommonInfo*       stCtrlCommonInfo_ptr,
                                  tPathPlannerInfo*      stPathPlannerInfo_ptr,
                                  tCtrlLongiInfo*        stCtrlLongiInfo_ptr)
{
  if(Ctrl_Internal_ParkingWithPlan == stCtrlCommonInfo_ptr->eCtrlFuncType){
    if (stCtrlUssInfo_ptr->bPebStopFlagFinal){
      stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebHappened = 1;//所存u8PebHappened和u8PebDir
      for (uint8_t i = 0; i < PDC_ZONE_NUM; ++i){   
        if (0 == stCtrlUssInfo_ptr->bPebStopFlagDirection[i]){
          continue;
        }
        if (i < NUM_FRONT){
          stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebDir = stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebDir | 1;  //FRONT
          stCtrlUssInfo_ptr->u8PebUssNumber = i;
        }else if (i < NUM_REAR){   
          stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebDir = stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebDir | 2; //REAR
          stCtrlUssInfo_ptr->u8PebUssNumber = i; 
        }else if (NUM_LEFT_FRONT == i){
          stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebDir = stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebDir | 4;  //LEFT_FRONT
          stCtrlUssInfo_ptr->u8PebUssNumber = i;
        }else if (NUM_LEFT_REAR == i){
          stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebDir = stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebDir | 8;  //LEFT_REAR
          stCtrlUssInfo_ptr->u8PebUssNumber = i;
        }else if (NUM_RIGHT_FRONT == i){
          stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebDir = stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebDir | 16;  //RIGHT_FRONT
          stCtrlUssInfo_ptr->u8PebUssNumber = i;
        }else if (NUM_RIGHT_REAR == i){
          stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebDir = stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebDir | 32;  //RIGHT_REAR
          stCtrlUssInfo_ptr->u8PebUssNumber = i;
        }else{
          ;
        }
      }
    }
    
    if (((R_GEAR == stVehDataRx_ptr->sVehVCUInfo.eVehActualGear) && (D_GEAR == stPathPlannerInfo_ptr->u8Shift))|| 
        ((D_GEAR == stVehDataRx_ptr->sVehVCUInfo.eVehActualGear) && (R_GEAR == stPathPlannerInfo_ptr->u8Shift))||
         (PHASE_STOP_STEERING == stCtrlLongiInfo_ptr->eSpeedPhase)){
      Ctrl_PebDirInit();
    }
  }else if (Ctrl_Internal_Crusing == stCtrlCommonInfo_ptr->eCtrlFuncType){
    if (stCtrlUssInfo_ptr->bPebStopFlagFinal){
      stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebHappened = 1;//所存u8PebHappened和u8PebDir
      for (uint8_t i = 0; i < PDC_ZONE_NUM; ++i){
        if (0 == stCtrlUssInfo_ptr->bPebStopFlagDirection[i]){
          continue;
        }
        if (i < NUM_FRONT){
          stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebDir = stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebDir | 1;  //FRONT
          stCtrlUssInfo_ptr->u8PebUssNumber = i;
        }else if (i < NUM_REAR){   
          stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebDir = stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebDir | 2; //REAR
          stCtrlUssInfo_ptr->u8PebUssNumber = i; 
        }else if (NUM_LEFT_FRONT == i){
          stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebDir = stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebDir | 4;  //LEFT_FRONT
          stCtrlUssInfo_ptr->u8PebUssNumber = i;
        }else if (NUM_LEFT_REAR == i){
          stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebDir = stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebDir | 8;  //LEFT_REAR
          stCtrlUssInfo_ptr->u8PebUssNumber = i;
        }else if (NUM_RIGHT_FRONT == i){
          stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebDir = stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebDir | 16;  //RIGHT_FRONT
          stCtrlUssInfo_ptr->u8PebUssNumber = i;
        }else if (NUM_RIGHT_REAR == i){
          stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebDir = stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebDir | 32;  //RIGHT_REAR
          stCtrlUssInfo_ptr->u8PebUssNumber = i;
        }else{
          ;
        }
      }
    }else{
      ;
    }
    if ((CRUISE_STOP_STEERING == stStateMachine_ptr->m_state)){
      Ctrl_PebDirInit();
    }
  }else{
    ;
  }    
  return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME 
control_PEB_speed_plan. 

  * EXPLANATION   
This function is used for speed planning.

*************************************************************************
*/

  // stCtrlUssInfo_ptr->f32PebMinSpdDistance = (stCtrlUssInfo_ptr->f32PebMinSpdDistance<0) ? 0 : stCtrlUssInfo_ptr->f32PebMinSpdDistance;                              




