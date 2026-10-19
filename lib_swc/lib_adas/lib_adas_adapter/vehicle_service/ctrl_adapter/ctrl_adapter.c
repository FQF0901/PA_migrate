#include "adas_project_input.h"
#include "ctrl_global_variables.h"
#include "ctrl_adapter.h"
#include "ctrl_enum.h"
#include "math.h"
#include "vehicle_service/calib/vehsrv_calib.h"
#include "common/ctrl_comm_func.h"
#include "testroad/testroad.h"
#include "ctrl_diag.h"
// --- Temp-RA.
// --- Temp-RA. END.

// --- Temp-APP-PO.
// --- Temp-APP-PO.. END.

#define CtrlPara_START_SEC_VAR		// Memory allocation
#include "proj_MemMap.h"

/******************vs test*****************/
// static tCtrl2Vehsrv            msgMnger_ctrl2vehsrv_data;
/******************vs test*****************/

#define CtrlPara_STOP_SEC_VAR	// Memory allocation end.
#include "proj_MemMap.h"


static uint8_t Ctrl_NewPathCheck(tPathPlannerInfo*   stPathPlannerInfo_ptr,
                                 tCtrlCommonInfo*    stCtrlCommonInfo_ptr);
static uint8_t Ctrl_GetGearMode(tPathPlannerInfo*   stPathPlannerInfo_ptr);
static uint8_t Ctrl_CheckPldType(tPathPlannerInfo*          stPathPlannerInfo_ptr);
static uint8_t Ctrl_CheckLastPoint(tPathPlannerInfo*       stPathPlannerInfo_ptr);
static uint8_t Ctrl_CheckLastPath(tPathPlannerInfo*       stPathPlannerInfo_ptr);
static uint8_t Ctrl_CheckNoNewPath(tPathPlannerInfo*       stPathPlannerInfo_ptr);
static uint8_t Ctrl_CheckPathValid(tPathPlannerInfo*  stPathPlannerInfo_ptr,
                                   tCtrlCommonInfo*   stCtrlCommonInfo_ptr);
static uint8_t Ctrl_CheckPathKappaChangeRate(tPathPlannerInfo*   stPathPlannerInfo_ptr);
static uint16_t Ctrl_CalcuPebDisMin(tVehDataRx*   stVehDataRx_ptr,tCtrlUssInfo* stCtrlUssInfo_ptr);
static uint8_t PdcZoneMinDistance(uint8 start , uint8 end,uint8 serialNmb,
                           tMsgMnger_PDC* stMsgMnger_PDC_ptr ,
                           tCtrlUssInfo* stCtrlUssInfo_ptr);





/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_ReceiveFromUSS.

  * EXPLANATION
Get USS or DataFusion (Future) data from RTE (e.g. OD distance or MOD distance, etc.), and save the OD date in designative data structure/variable.

*************************************************************************
*/
uint8_t Ctrl_ReceiveFromVehInterface(tVehDataRx*   stVehDataRx_ptr)
{
  tVehDataRx msgMnger_VehDataRx;
  Rte_Read_MsgManager_APPVehData(&msgMnger_VehDataRx);  // 

  stVehDataRx_ptr->sVehVCUInfo  = msgMnger_VehDataRx.sVehVCUInfo;
  stVehDataRx_ptr->sVehESCInfo  = msgMnger_VehDataRx.sVehESCInfo;
  stVehDataRx_ptr->sVehEPSInfo  = msgMnger_VehDataRx.sVehEPSInfo;
  stVehDataRx_ptr->sVehACUInfo  = msgMnger_VehDataRx.sVehACUInfo;
  stVehDataRx_ptr->sVehBCMInfo  = msgMnger_VehDataRx.sVehBCMInfo;
  stVehDataRx_ptr->sExtCdtnMiss = msgMnger_VehDataRx.sExtCdtnMiss;

  return E_OK;
}

uint8_t Ctrl_ReceiveFromUSS(tCtrlUssInfo* stCtrlUssInfo_ptr)
{
  tMsgMnger_PDC stMsgMnger_PDC;

  Rte_Read_MsgManager_PDC(&stMsgMnger_PDC);
    
  Ctrl_DiagInputUss(&stMsgMnger_PDC);

	stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_FRONT_LEFT_1_DIS] = stMsgMnger_PDC.u16Distance[US_IDX_PDC_FLC];
  stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_FRONT_LEFT_2_DIS] = stMsgMnger_PDC.u16Distance[US_IDX_PDC_FLM];
  stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_FRONT_LEFT_3_DIS] = stMsgMnger_PDC.u16Distance[US_IDX_PDC_FRM];
  stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_FRONT_LEFT_4_DIS] = stMsgMnger_PDC.u16Distance[US_IDX_PDC_FRC];
  stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_REAR_LEFT_1_DIS] = stMsgMnger_PDC.u16Distance[US_IDX_PDC_RLC];
  stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_REAR_LEFT_2_DIS] = stMsgMnger_PDC.u16Distance[US_IDX_PDC_RLM];
  stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_REAR_LEFT_3_DIS] = stMsgMnger_PDC.u16Distance[US_IDX_PDC_RRM];
  stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_REAR_LEFT_4_DIS] = stMsgMnger_PDC.u16Distance[US_IDX_PDC_RRC];
  stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_SIDE_FRONT_LEFT_DIS] = stMsgMnger_PDC.u16Distance[US_IDX_APA_FLS];
  stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_SIDE_FRONT_RIGHT_DIS] = stMsgMnger_PDC.u16Distance[US_IDX_APA_FRS];
  stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_SIDE_REAR_LEFT_DIS] = stMsgMnger_PDC.u16Distance[US_IDX_APA_RLS];
  stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_SIDE_REAR_RIGHT_DIS] = stMsgMnger_PDC.u16Distance[US_IDX_APA_RRS];
  stCtrlUssInfo_ptr->u16FL_Sector_Dist  = stMsgMnger_PDC.u16Distance[US_IDX_PDC_FLC];
  stCtrlUssInfo_ptr->u16FML_Sector_Dist = stMsgMnger_PDC.u16Distance[US_IDX_PDC_FLM];
  stCtrlUssInfo_ptr->u16FMR_Sector_Dist = stMsgMnger_PDC.u16Distance[US_IDX_PDC_FRM];
  stCtrlUssInfo_ptr->u16FR_Sector_Dist  = stMsgMnger_PDC.u16Distance[US_IDX_PDC_FRC];
  stCtrlUssInfo_ptr->u16RL_Sector_Dist  = stMsgMnger_PDC.u16Distance[US_IDX_PDC_RLC];
  stCtrlUssInfo_ptr->u16RML_Sector_Dist = stMsgMnger_PDC.u16Distance[US_IDX_PDC_RLM];
  stCtrlUssInfo_ptr->u16RMR_Sector_Dist = stMsgMnger_PDC.u16Distance[US_IDX_PDC_RRM];
  stCtrlUssInfo_ptr->u16RR_Sector_Dist  = stMsgMnger_PDC.u16Distance[US_IDX_PDC_RRC];
  stCtrlUssInfo_ptr->u16FSL_Sector_Dist = stMsgMnger_PDC.u16Distance[US_IDX_APA_FLS];
  stCtrlUssInfo_ptr->u16FSR_Sector_Dist = stMsgMnger_PDC.u16Distance[US_IDX_APA_FRS];
  stCtrlUssInfo_ptr->u16RSL_Sector_Dist = stMsgMnger_PDC.u16Distance[US_IDX_APA_RLS];
  stCtrlUssInfo_ptr->u16RSR_Sector_Dist = stMsgMnger_PDC.u16Distance[US_IDX_APA_RRS];

	for (int i = 0; i < PDC_ZONE_NUM; i++){
    stCtrlUssInfo_ptr->bBlindAreaObstacle[i] = FALSE;                          
  }
  PdcZoneMinDistance(4,7,0,&stMsgMnger_PDC,stCtrlUssInfo_ptr);
  PdcZoneMinDistance(8,10,1,&stMsgMnger_PDC,stCtrlUssInfo_ptr);
  PdcZoneMinDistance(11,14,2,&stMsgMnger_PDC,stCtrlUssInfo_ptr); 
  PdcZoneMinDistance(15,17,3,&stMsgMnger_PDC,stCtrlUssInfo_ptr);
  PdcZoneMinDistance(18,20,4,&stMsgMnger_PDC,stCtrlUssInfo_ptr);   
  PdcZoneMinDistance(21,24,5,&stMsgMnger_PDC,stCtrlUssInfo_ptr);
  PdcZoneMinDistance(25,27,6,&stMsgMnger_PDC,stCtrlUssInfo_ptr);
  PdcZoneMinDistance(28,31,7,&stMsgMnger_PDC,stCtrlUssInfo_ptr); 
  PdcZoneMinDistance(40,43,8,&stMsgMnger_PDC,stCtrlUssInfo_ptr);
  PdcZoneMinDistance(44,46,9,&stMsgMnger_PDC,stCtrlUssInfo_ptr);  
  PdcZoneMinDistance(47,49,10,&stMsgMnger_PDC,stCtrlUssInfo_ptr);
  PdcZoneMinDistance(50,53,11,&stMsgMnger_PDC,stCtrlUssInfo_ptr);
  PdcZoneMinDistance(54,57,12,&stMsgMnger_PDC,stCtrlUssInfo_ptr); 
  PdcZoneMinDistance(58,60,13,&stMsgMnger_PDC,stCtrlUssInfo_ptr);
  PdcZoneMinDistance(61,63,14,&stMsgMnger_PDC,stCtrlUssInfo_ptr);   
  PdcZoneMinDistance(64,67,15,&stMsgMnger_PDC,stCtrlUssInfo_ptr);
  PdcZoneMinDistance(33,35,16,&stMsgMnger_PDC,stCtrlUssInfo_ptr);
  PdcZoneMinDistance(77,81,17,&stMsgMnger_PDC,stCtrlUssInfo_ptr); 
  PdcZoneMinDistance(0,2,18,&stMsgMnger_PDC,stCtrlUssInfo_ptr);
  PdcZoneMinDistance(87,91,19,&stMsgMnger_PDC,stCtrlUssInfo_ptr);

  return E_OK;
}

static uint16_t Ctrl_CalcuPebDisMin(tVehDataRx*   stVehDataRx_ptr,tCtrlUssInfo* stCtrlUssInfo_ptr)
{
  uint16_t pebDisMin = 1000;

  if (D_GEAR == stVehDataRx_ptr->sVehVCUInfo.eVehActualGear){
    for (int i = 0; i < 8; ++i){
      if (stCtrlUssInfo_ptr->u16PebDistanceConverted[i] < pebDisMin){
        pebDisMin = stCtrlUssInfo_ptr->u16PebDistanceConverted[i];
      }
    }
  }else if (R_GEAR == stVehDataRx_ptr->sVehVCUInfo.eVehActualGear){
    for (int i = 8; i < 16; ++i){
      if (stCtrlUssInfo_ptr->u16PebDistanceConverted[i] < pebDisMin){
        pebDisMin = stCtrlUssInfo_ptr->u16PebDistanceConverted[i];
      }
    }
  }else{
    ;
  }

  return pebDisMin;
}

/**
*************************************************************************
  * FUNCTION_NAME 
Ctrl_ReceiveFromPathPlanner. 

  * EXPLANATION   
Get the result of path planning module. It is the info about the target
path to follow, including：
 - array of target vehicle pose.
 - control info, e.g. pathID, pose point total number, etc.

*************************************************************************
*/
uint8_t Ctrl_ReceiveFromPathPlanner(tPathPlannerInfo*   stPathPlannerInfo_ptr,
						   	        tCtrlCommonInfo*    stCtrlCommonInfo_ptr,
                                    tCtrlFuncFsmInfo*   stCtrlApaShellInfo_ptr)
{
    // --- Receive path info.
  tMsgMnger_PathPlanner   msgMnger_PathPlanner;
  Rte_Read_MsgManager_PathPlanner(&msgMnger_PathPlanner);

  #if ADAS_TEST_ROAD_SWITCH  //for test road
        msgMnger_PathPlanner =  Ctrl_Recv_Fake_Road(stCtrlCommonInfo_ptr);
  #endif

    // --- Received path info diagnose.
  Ctrl_DiagInputPpInfo(&msgMnger_PathPlanner);

    // --- Record path info.   
  memset(stPathPlannerInfo_ptr, 0, sizeof(tPathPlannerInfo));
  stPathPlannerInfo_ptr->u16PathId                 = msgMnger_PathPlanner.stPathPlanData.u16PathId;
  stPathPlannerInfo_ptr->u16TotallyPathNum         = msgMnger_PathPlanner.stPathPlanData.u16TotallyPathNum;           
  stPathPlannerInfo_ptr->ePathPlanSts              = msgMnger_PathPlanner.eApaPathPlanSts;
  stPathPlannerInfo_ptr->u8PointNum                = msgMnger_PathPlanner.stPathPlanData.u8Size;
  stPathPlannerInfo_ptr->u8Shift                   = msgMnger_PathPlanner.stPathPlanData.u8Shift;
  stPathPlannerInfo_ptr->u8IsTraj                  = msgMnger_PathPlanner.stPathPlanData.u8IsTraj;
  stPathPlannerInfo_ptr->ePldType                  = msgMnger_PathPlanner.stPathPlanData.u8PldType;
  stPathPlannerInfo_ptr->u8PlanResult              = msgMnger_PathPlanner.stPathPlanData.u8PlanResult;
  stPathPlannerInfo_ptr->u8PebLevel                = msgMnger_PathPlanner.stPathPlanData.u8PebLevel;
  stPathPlannerInfo_ptr->f32PathLength             = msgMnger_PathPlanner.stPathPlanData.f32PathLength;
  stPathPlannerInfo_ptr->stFinalLocation.f32X_Coor = msgMnger_PathPlanner.stPathPlanData.stEndPose.point.x;
  stPathPlannerInfo_ptr->stFinalLocation.f32Y_Coor = msgMnger_PathPlanner.stPathPlanData.stEndPose.point.y;
  stPathPlannerInfo_ptr->stFinalLocation.f32Theta  = msgMnger_PathPlanner.stPathPlanData.stEndPose.theta;
  stPathPlannerInfo_ptr->u64StartTime              = msgMnger_PathPlanner.stPathPlanData.u64StartTime;
  stPathPlannerInfo_ptr->u8VehicleActionRequest    = msgMnger_PathPlanner.stPathPlanData.u8VehicleActionRequest;
  stPathPlannerInfo_ptr->u8VehicleActionReason    = msgMnger_PathPlanner.stPathPlanData.u8VehicleActionReason;

  if (true == msgMnger_PathPlanner.stPathPlanData.u8IsTraj){
    tMsgMnger_PPTrajPoint_Rst* stTrajPoint_ptr = (tMsgMnger_PPTrajPoint_Rst*)&msgMnger_PathPlanner.stPathPlanData;
    for (uint8_t i = 0; i < stPathPlannerInfo_ptr->u8PointNum; i++){
      stPathPlannerInfo_ptr->stPathData[i].f32WayPointX           = stTrajPoint_ptr->stPathPosition[i].f32WayPointX;
      stPathPlannerInfo_ptr->stPathData[i].f32WayPointY           = stTrajPoint_ptr->stPathPosition[i].f32WayPointY;
      stPathPlannerInfo_ptr->stPathData[i].f32WayPointTheta       = stTrajPoint_ptr->stPathPosition[i].f32WayPointTheta;
      stPathPlannerInfo_ptr->stPathData[i].f32WayPointCurvature   = stTrajPoint_ptr->stPathPosition[i].f32WayPointCurvature;
      stPathPlannerInfo_ptr->stPathData[i].f32WayPointS           = stTrajPoint_ptr->stPathPosition[i].f32WayPointS;
      stPathPlannerInfo_ptr->stPathData[i].f32WayPointV           = stTrajPoint_ptr->stPathPosition[i].f32WayPointV;
      stPathPlannerInfo_ptr->stPathData[i].f32WayPointA           = stTrajPoint_ptr->stPathPosition[i].f32WayPointA;
      stPathPlannerInfo_ptr->stPathData[i].u32WayPointT           = stTrajPoint_ptr->stPathPosition[i].u32WayPointT;
    }
  }else{
    tMsgMnger_PPWayPoint_Rst* stWayPoint_ptr = &msgMnger_PathPlanner.stPathPlanData;
    for (uint8_t i = 0; i < stPathPlannerInfo_ptr->u8PointNum; i++){
      stPathPlannerInfo_ptr->stPathData[i].f32WayPointX           = stWayPoint_ptr->stPathPosition[i].f32WayPointX;
      stPathPlannerInfo_ptr->stPathData[i].f32WayPointY           = stWayPoint_ptr->stPathPosition[i].f32WayPointY;
      stPathPlannerInfo_ptr->stPathData[i].f32WayPointTheta       = stWayPoint_ptr->stPathPosition[i].f32WayPointTheta;
      stPathPlannerInfo_ptr->stPathData[i].f32WayPointCurvature   = stWayPoint_ptr->stPathPosition[i].f32WayPointCurvature;
    }
  }

    // --- Recorded path data preprocessing. 
  Ctrl_CheckPathValid(stPathPlannerInfo_ptr, stCtrlCommonInfo_ptr);
  Ctrl_CheckPldType(stPathPlannerInfo_ptr);
  Ctrl_CheckLastPoint(stPathPlannerInfo_ptr);
  Ctrl_CheckLastPath(stPathPlannerInfo_ptr);
  Ctrl_CheckNoNewPath(stPathPlannerInfo_ptr);
  Ctrl_NewPathCheck(stPathPlannerInfo_ptr, stCtrlCommonInfo_ptr);
  Ctrl_GetGearMode(stPathPlannerInfo_ptr);
  if (0 == stPathPlannerInfo_ptr->u8IsTraj) {
    Ctrl_CheckPathKappaChangeRate(stPathPlannerInfo_ptr);// && 1 == stPathPlannerInfo_ptr->u8NewPathFlag)    // To save workload, but meet strange bugs.
  }
	return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME 
Ctrl_ReceiveFromApaShell. 

  * EXPLANATION   
Get current function status & function type from APA shell. And mapping.

*************************************************************************
*/
uint8_t Ctrl_ReceiveFromApaShell(tCtrlFuncFsmInfo*     stCtrlApaShellInfo_ptr)
{
    // --- Receive function status, type, command.  
  tMsgMnger_ApaState   stMsgMngerApaState;
  Rte_Read_MsgManager_ApaState(&stMsgMngerApaState);
  stCtrlApaShellInfo_ptr->eLsadSystemStsPrev = stCtrlApaShellInfo_ptr->eLsadSystemSts;
  stCtrlApaShellInfo_ptr->eLsadSystemSts = stMsgMngerApaState.eLsadSystemSts;
  stCtrlApaShellInfo_ptr->eLsadSystemSubSts = stMsgMngerApaState.eLsadSystemSubSts;
  stCtrlApaShellInfo_ptr->eLsadFuncType = (tLSAD_FuncType)stMsgMngerApaState.u8LsadFuncType;
  stCtrlApaShellInfo_ptr->eLsadDriverCtrlCommand = (tLSAD_DriverCtrlCommand)stMsgMngerApaState.u8DriverCtrlCommand;
  stCtrlApaShellInfo_ptr->u8LsadStSResetPEB = stMsgMngerApaState.u8LsadStSResetPEB;

    // --- Parkout type summarize.
  tLSAD_DriverCtrlCommand eDetailedCommand = stCtrlApaShellInfo_ptr->eLsadDriverCtrlCommand;
  if (DRIVER_CTRL_PARKOUT_PP_LEFT == eDetailedCommand || DRIVER_CTRL_PARKOUT_PP_MIDDLE == eDetailedCommand ||
      DRIVER_CTRL_PARKOUT_PP_RIGHT == eDetailedCommand){
    stCtrlApaShellInfo_ptr->eCtrlParkOutType = CTRL_PARKOUT_WITHPP;
  }else if (DRIVER_CTRL_PARKOUT_NOPP_LEFT == eDetailedCommand || DRIVER_CTRL_PARKOUT_NOPP_MIDDLE == eDetailedCommand ||
           DRIVER_CTRL_PARKOUT_NOPP_RIGHT == eDetailedCommand){
    stCtrlApaShellInfo_ptr->eCtrlParkOutType = CTRL_PARKOUT_WITHOUTPP;
  }else{
    stCtrlApaShellInfo_ptr->eCtrlParkOutType = CTRL_PARKOUT_NONE;
  }

  return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME 
Ctrl_ReceiveFromLocalization. 

  * EXPLANATION   
Get the current vehicle position.

*************************************************************************
*/
uint8_t Ctrl_ReceiveFromLocalization(tCtrlVehPose*   stCtrlVehPose_ptr)
{
    // --- Record the previous position.
  Ctrl_RecordPrevPose(stCtrlVehPose_ptr);   

    // --- Get the current position.
    //    Dr_GetPoseNow(&stCtrlVehPose_ptr->stCurrentPos);

    // Get DR POSE FROM RTE

  tMsgMnger_Localisition msgMnger_Localisition;
  Rte_Read_MsgManager_Localisition(&msgMnger_Localisition);

  stCtrlVehPose_ptr->stCurrentPos.u64Timestamp = msgMnger_Localisition.u64Timestamp_us;
  stCtrlVehPose_ptr->stCurrentPos.f32X_Coor    = msgMnger_Localisition.f32x;
  stCtrlVehPose_ptr->stCurrentPos.f32Y_Coor    = msgMnger_Localisition.f32y;
  stCtrlVehPose_ptr->stCurrentPos.f32Theta     = msgMnger_Localisition.f32yaw;
  stCtrlVehPose_ptr->stCurrentPos.f32Track     = msgMnger_Localisition.f32roll;   //msgMnger_Localisition.f32Depth;

  return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_SendToCAN. 

  * EXPLANATION   
Prepare the data to be send out to CAN. Mainly control related data, e.g. 
target speed, target steer angle, etc.  

*************************************************************************
*/
uint8_t Ctrl_SendToCAN(tVehDataRx*           stVehDataRx_ptr,
                       tCtrlToChassisInfo*   stCtrlToChassisInfo_ptr,
                       tCtrlFuncFsmInfo*     stCtrlApaShellInfo_ptr)
{
  tVehi_VehicleDataTx   msgCtrl2Chassis;
  float  f32PebLevel1Dis = 0.1;
  float  f32PebLevel0Dis = -0.1;
  float f32PebMinDist = g_stCtrlUssInfo.f32PebMinSpdDistance;
  float u8PebLevel = g_stPathPlannerData.u8PebLevel;
  static float f32Ctrl2ChassisPreCtrlReqSpeed = 0.0;


  if(stCtrlToChassisInfo_ptr->f32CtrlReqStopDistance< 0.1){
    msgCtrl2Chassis.f32CtrlReqSpeed = 0;
  } else if(stCtrlToChassisInfo_ptr->f32CtrlReqSpeed<0.5 && stCtrlToChassisInfo_ptr->f32CtrlReqSpeed>0.1){
    msgCtrl2Chassis.f32CtrlReqSpeed = 0.5;
  } else{
    msgCtrl2Chassis.f32CtrlReqSpeed = stCtrlToChassisInfo_ptr->f32CtrlReqSpeed;
  }
  msgCtrl2Chassis.f32CtrlReqSpeed = f32Ctrl2ChassisPreCtrlReqSpeed+
                                    (0.02/0.3)*(msgCtrl2Chassis.f32CtrlReqSpeed-f32Ctrl2ChassisPreCtrlReqSpeed);//一节滤波保证执行器速度响应更平稳
  msgCtrl2Chassis.f32CtrlReqAccel = stCtrlToChassisInfo_ptr->f32CtrlReqAccel;
  msgCtrl2Chassis.f32CtrlReqStopDistance = stCtrlToChassisInfo_ptr->f32CtrlReqStopDistance;
  if (1 == stCtrlToChassisInfo_ptr->eAEBFlag){
    //u8PebLevel1级别刹停与u8PebLevel1级别刹停距离
   if (((1==u8PebLevel && f32PebMinDist <= f32PebLevel1Dis)||
        (0==u8PebLevel && f32PebMinDist <= f32PebLevel0Dis)||
        (LSAD_CRUISE == g_stCtrlFuncFsmInfo.eLsadFuncType))&&
       ((uint8_t)g_stCtrlVehDataRx.sVehVCUInfo.eVehActualGear == g_stPathPlannerData.u8Shift)){
     msgCtrl2Chassis.eAEBFlag = 2;   // 1: ComfortBrake | 2: EmergBrake
     msgCtrl2Chassis.f32CtrlReqStopDistance = 0;
     msgCtrl2Chassis.f32CtrlReqSpeed = 0;
   } else{
     msgCtrl2Chassis.eAEBFlag = stCtrlToChassisInfo_ptr->eAEBFlag;
   }
 }else{
   msgCtrl2Chassis.eAEBFlag = stCtrlToChassisInfo_ptr->eAEBFlag;
 }
  
  msgCtrl2Chassis.f32CtrlReqSteer = stCtrlToChassisInfo_ptr->f32CtrlReqSteer;
  if(P_GEAR == stCtrlToChassisInfo_ptr->eGearReq){
    msgCtrl2Chassis.eGearReq = VEHI_GEAR_P;
  } else if(R_GEAR == stCtrlToChassisInfo_ptr->eGearReq){
    msgCtrl2Chassis.eGearReq = VEHI_GEAR_R;
  } else if(N_GEAR == stCtrlToChassisInfo_ptr->eGearReq){
    msgCtrl2Chassis.eGearReq = VEHI_GEAR_N;
  } else if(D_GEAR == stCtrlToChassisInfo_ptr->eGearReq){
    msgCtrl2Chassis.eGearReq = VEHI_GEAR_D;
  }
  msgCtrl2Chassis.eStandStillReq = stCtrlToChassisInfo_ptr->eStandStillReq;
  msgCtrl2Chassis.eHandshakeReq = stCtrlToChassisInfo_ptr->eHandshakeReq;
  (void)Ctrl_DiagOutputChassis(&msgCtrl2Chassis);
  Rte_Write_CTRL2CHASSIS(&msgCtrl2Chassis);  

    /*********************vs test**********************/
    // msgMnger_ctrl2vehsrv_data.g_stCtrlOutputPara = msgCtrl2Chassis;
    // Rte_Write_CTRL2VEHSRV(&msgMnger_ctrl2vehsrv_data);
    /*********************vs test**********************/
  f32Ctrl2ChassisPreCtrlReqSpeed = msgCtrl2Chassis.f32CtrlReqSpeed;
  return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME 
Ctrl_SendToApaShell. 

  * EXPLANATION   
The main interface function from Ctrl to Apa Shell.

*************************************************************************
*/

uint8_t Ctrl_SendToApaShell(tCtrlToFuncStateMachine*  stCtrlToFuncStateMachine_ptr)
{
  Rte_Write_CTRL2SM(&stCtrlToFuncStateMachine_ptr->eCtrlStatus);      
  Rte_Write_CTRL2SM_ReqStatus(&stCtrlToFuncStateMachine_ptr->stCtrlReqSts);       // Not working now, ctrl trigger the pause via ctrl_status.

  return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME 
Ctrl_SendToPathPlanner. 

  * EXPLANATION   
The main interface function from Ctrl to SOC. 

*************************************************************************
*/

uint8_t Ctrl_SendToSOC(const tCtrl_StateInfo*       stCtrl2PPStateInfo_ptr, 
                       const tCtrl_LogInfo*            stCtrlLogInfo_ptr,
                       const tCtrlToFuncStateMachine*     stCtrlToFuncStateMachine_ptr)
{
  tMsgMnger_PF    msgMnger_PF;
    
  msgMnger_PF.u64Timestamp_us               = SysTm_GetUnixTimestamp_us();
  msgMnger_PF.eApaControlAlgoSts            = stCtrlToFuncStateMachine_ptr->eCtrlStatus;
  msgMnger_PF.stCtrl2PpStateInfo            = *stCtrl2PPStateInfo_ptr;
 
  msgMnger_PF.stCtrl2PpStateInfo.u8res[0]   = g_stCtrlCommonInfo.u8PauseFlag;          //临时方案：源头,控制暂停的信号,fsm使用
    // msgMnger_PF.stCtrl2PpStateInfo.u8res[1]   = (uint8)g_sPAManagerInfo.eAPAInternalSts; //临时方案：源头,APA状态,fsm使用
    // msgMnger_PF.stCtrl2PpStateInfo.u8res[2]   = (uint8)g_sRAManagerInfo.eRAStatus;       //临时方案：源头,RA状态,fsm使用

  msgMnger_PF.stCtrlLogInfo                 = *stCtrlLogInfo_ptr;

  Rte_Write_MsgManager_PF(&msgMnger_PF);

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
Ctrl_NewPathCheck

  * EXPLANATION
If a new ref path is received, this function will return "true" flag
*************************************************************************
*/

static uint8_t Ctrl_NewPathCheck(tPathPlannerInfo*   stPathPlannerInfo_ptr, 
                                 tCtrlCommonInfo*    stCtrlCommonInfo_ptr)
{
    
  if (stPathPlannerInfo_ptr->u16PathId > stCtrlCommonInfo_ptr->u16CurrentPathID){
    stPathPlannerInfo_ptr->u8NewPathFlag = 1;
    stCtrlCommonInfo_ptr->u8CtrlSubstate = CTRL_CTRL_SUBSTATE_STOP_NONE;    // --- once ctrl receives a new path, reset the ctrl sub-state, as decision requires. 
  }
  else {
    stPathPlannerInfo_ptr->u8NewPathFlag = 0;
  }

  return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_GetGearMode

  * EXPLANATION
This function will return 1 for D-gear and -1 for R gear
*************************************************************************
*/
static uint8_t Ctrl_GetGearMode(tPathPlannerInfo*   stPathPlannerInfo_ptr)
{
  if (R_GEAR == stPathPlannerInfo_ptr->u8Shift){
      stPathPlannerInfo_ptr->i8CtrlGearFactor = -1;
  }
  else if(D_GEAR == stPathPlannerInfo_ptr->u8Shift){
    stPathPlannerInfo_ptr->i8CtrlGearFactor = 1;
  }
  else{
    stPathPlannerInfo_ptr->i8CtrlGearFactor = 0;
  }

  return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_CheckPathKappaChangeRate

  * EXPLANATION
Check if the path's kappa change rate is abnormally high.  

*************************************************************************
*/
static uint8_t Ctrl_CheckPathKappaChangeRate(tPathPlannerInfo*   stPathPlannerInfo_ptr)
{
  uint8_t u8KappaSuddenChangeFlag = 0;
  uint8_t u8KappaSuddenChangePointId = 0;

  for (uint8_t i = 1; i < stPathPlannerInfo_ptr->u8PointNum; i++){
    float f32CurKappa = stPathPlannerInfo_ptr->stPathData[i].f32WayPointCurvature;
    float f32PrevKappa = stPathPlannerInfo_ptr->stPathData[i-1].f32WayPointCurvature;
    float f32DeltaKappa = fabs(f32CurKappa - f32PrevKappa);
     // [0.05 ~ 0.4]
    if (f32DeltaKappa > 0.08){
      u8KappaSuddenChangeFlag = 1;
      u8KappaSuddenChangePointId = i;
    }
  }

  stPathPlannerInfo_ptr->u8KappaSuddenChangeFlag = u8KappaSuddenChangeFlag;
  stPathPlannerInfo_ptr->u8KappaSuddenChangePointId = u8KappaSuddenChangePointId;

  return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_CheckPathValid

  * EXPLANATION
Check if the path is valid. 

*************************************************************************
*/

static uint8_t Ctrl_CheckPathValid(tPathPlannerInfo*  stPathPlannerInfo_ptr,
                                   tCtrlCommonInfo*   stCtrlCommonInfo_ptr)
{
  if (CTRL_MODULE_ACTIVE == stCtrlCommonInfo_ptr->eCtrlFuncStatus){
    if (0 == stPathPlannerInfo_ptr->u16PathId || 0 == stPathPlannerInfo_ptr->u8PointNum){
      stPathPlannerInfo_ptr->u8PathInvalidFlag = 1;
    }
  }

  return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_CheckPldType

  * EXPLANATION
Part slot type mapping. 

*************************************************************************
*/

static uint8_t Ctrl_CheckPldType(tPathPlannerInfo*          stPathPlannerInfo_ptr)
{
  tDF_PL_TYPE ePldType = stPathPlannerInfo_ptr->ePldType;

  if(DF_PL_TYPE_Horizontal == ePldType || DF_PL_TYPE_SPACE_Horizontal == ePldType){
    stPathPlannerInfo_ptr->eCtrlPldType = DF_PL_TYPE_Horizontal;
  }
  else if (DF_PL_TYPE_Vertical == ePldType || DF_PL_TYPE_SPACE_Vertical ==  ePldType){
    stPathPlannerInfo_ptr->eCtrlPldType = DF_PL_TYPE_Vertical;
  }
  else if(DF_PL_TYPE_Oblique_30 == ePldType || DF_PL_TYPE_Oblique_45 == ePldType || 
          DF_PL_TYPE_Oblique_60 == ePldType || DF_PL_TYPE_SPACE_Inclined == ePldType){
    stPathPlannerInfo_ptr->eCtrlPldType = DF_PL_TYPE_Vertical;
  }
  else if(DF_PL_TYPE_ThreeDimensional == ePldType){
    stPathPlannerInfo_ptr->eCtrlPldType = DF_PL_TYPE_ThreeDimensional;       
  }
  else{
    stPathPlannerInfo_ptr->eCtrlPldType = DF_PL_TYPE_DEFAULT;
  }

  return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_CheckLastPoint

  * EXPLANATION
Record the last point ID. 

*************************************************************************
*/

static uint8_t Ctrl_CheckLastPoint(tPathPlannerInfo*       stPathPlannerInfo_ptr)
{

  if (stPathPlannerInfo_ptr->u8PointNum > 0){
    stPathPlannerInfo_ptr->u8LastPointId = stPathPlannerInfo_ptr->u8PointNum - 1;
  }
  else{
    stPathPlannerInfo_ptr->u8LastPointId = 0;        // In this case, ctrl doesn't have received the right path from pp.
  }

  return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_CheckLastPath

  * EXPLANATION
Record the last path flag, and record the final point pose. 

*************************************************************************
*/

static uint8_t Ctrl_CheckLastPath(tPathPlannerInfo*       stPathPlannerInfo_ptr)
{
  uint8_t u8LastPointID = stPathPlannerInfo_ptr->u8LastPointId;

  if(stPathPlannerInfo_ptr->u16PathId == stPathPlannerInfo_ptr->u16TotallyPathNum){
    stPathPlannerInfo_ptr->u8LastPathFlag = 1; 

    stPathPlannerInfo_ptr->stFinalLocation.f32X_Coor = stPathPlannerInfo_ptr->stPathData[u8LastPointID].f32WayPointX;
    stPathPlannerInfo_ptr->stFinalLocation.f32Y_Coor = stPathPlannerInfo_ptr->stPathData[u8LastPointID].f32WayPointY;
    stPathPlannerInfo_ptr->stFinalLocation.f32Theta  = stPathPlannerInfo_ptr->stPathData[u8LastPointID].f32WayPointTheta;
  }
  else{
    stPathPlannerInfo_ptr->u8LastPathFlag = 0;
  }

  return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_CheckNoNewPath

  * EXPLANATION
Record the last path flag, and record the final point pose. 

*************************************************************************
*/

static uint8_t Ctrl_CheckNoNewPath(tPathPlannerInfo*       stPathPlannerInfo_ptr)
{
  if(stPathPlannerInfo_ptr->u16PathId > stPathPlannerInfo_ptr->u16TotallyPathNum){
    stPathPlannerInfo_ptr->u8NoNewPathFlag = 1; 
  }
  else {
    stPathPlannerInfo_ptr->u8NoNewPathFlag = 0;
  }

  return E_OK;
}




/*	=====================================================================
 *
 *					  functions not in use
 *
 *	===================================================================*/


/**
*************************************************************************
  * FUNCTION_NAME 
Ctrl_ShakeHandWithChassis. 

  * EXPLANATION   
Send the start hand shake request to chassis actuators(VCU, ESC, EPS). 

*************************************************************************
*/

uint8_t Ctrl_ShakeHandWithChassis(tCtrlToChassisInfo*  stCtrlToChassisInfo_ptr)
{
  stCtrlToChassisInfo_ptr->eHandshakeReq = 1;
  return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME 
Ctrl_WaveHandWithChassis. 

  * EXPLANATION   
Send the stop hand shake request to chassis actuators(VCU, ESC, EPS). 

*************************************************************************
*/

uint8_t Ctrl_WaveHandWithChassis(tVehDataRx*            stVehDataRx_pt,
                                 tCtrlToChassisInfo*    stCtrlToChassisInfo_ptr,
                                 tCtrlLatInfo*          stCtrlLatInfo_ptr)
{
    stCtrlToChassisInfo_ptr->eHandshakeReq = 0;
    stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetWheelAngle = stVehDataRx_pt->sVehEPSInfo.f32StrWhlAngDeg/
    stCtrlLatInfo_ptr->stCtrlLatResult.f32WheelToSteerRatio;
    return E_OK;
}


static uint8_t PdcZoneMinDistance(uint8 start , uint8 end,uint8 serialNmb,
                                  tMsgMnger_PDC* stMsgMnger_PDC_ptr ,
                                  tCtrlUssInfo* stCtrlUssInfo_ptr)
{
  uint16 u16PdcZoneMinDistance = 1000;           
  for(uint8 i=start;i< end+1;i++){
    if(u16PdcZoneMinDistance>stMsgMnger_PDC_ptr->sPeb92Distance[i].sDistanceCell[0].u16Distance_cm &&
       0 != stMsgMnger_PDC_ptr->sPeb92Distance[i].sDistanceCell[1].u16Distance_cm){
      u16PdcZoneMinDistance = stMsgMnger_PDC_ptr->sPeb92Distance[i].sDistanceCell[0].u16Distance_cm;
    }        
  }
  stCtrlUssInfo_ptr->u16PebDistanceConverted[serialNmb] = u16PdcZoneMinDistance;
  return E_OK;
}

