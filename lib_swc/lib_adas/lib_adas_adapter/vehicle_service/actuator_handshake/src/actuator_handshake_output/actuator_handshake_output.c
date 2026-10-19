#include "actuator_handshake_output.h"
#include "adas_project_input.h"
#include "adas_struct.h"
#include "adas_calibration_data.h"
#include "vehicle_service_global_variables.h"
#include "vehicle_service/calib/vehsrv_calib.h"


static uint8_t VCU_gear_map(tVehiGear eGearReq);
static uint8_t brake_mode_map(tRequest eAEBFlag);
static uint8_t handshake_output_RestTx(tMsgMnger_VehicleInfo    s_MsgMnger_VehicleInfo,
                                       tVehi_VehicleDataTx      s_MsgMnger_Ctrl2Chassis,
                                       tMsgMnger_ApaState       s_MsgMnger_ApaState,
                                       tHandshakeManager*       stHandshakeManager_ptr,
                                       tActuaSrvTx*             stActuaSrvTx_ptr);
static uint8_t handshake_output_VCU(tMsgMnger_VehicleInfo    s_MsgMnger_VehicleInfo,
                                    ST_VEHICLE_HANDSHAKE_INFO s_MsgMnger_VehicleHandshakeInfo,
                                    tVehi_VehicleDataTx      s_MsgMnger_Ctrl2Chassis,
                                    tHandshakeManager*       stHandshakeManager_ptr,
                                    tActuaSrvTx*             stActuaSrvTx_ptr);
static uint8_t handshake_output_ESC(tMsgMnger_VehicleInfo    s_MsgMnger_VehicleInfo,
                                    ST_VEHICLE_HANDSHAKE_INFO s_MsgMnger_VehicleHandshakeInfo,
                                    tVehi_VehicleDataTx      s_MsgMnger_Ctrl2Chassis,
                                    tMsgMnger_ApaState       s_MsgMnger_ApaState,
                                    tHandshakeManager*       stHandshakeManager_ptr,
                                    tActuaSrvTx*             stActuaSrvTx_ptr);
static uint8_t handshake_output_EPS(tMsgMnger_VehicleInfo    s_MsgMnger_VehicleInfo,
                                    ST_VEHICLE_HANDSHAKE_INFO s_MsgMnger_VehicleHandshakeInfo,
                                    tVehi_VehicleDataTx      s_MsgMnger_Ctrl2Chassis,
                                    tHandshakeManager*       stHandshakeManager_ptr,
                                    tActuaSrvTx*             stActuaSrvTx_ptr);  
/*	=====================================================================
 *
 *
 *	===================================================================*/                                         

uint8_t actuator_handshake_output(tMsgMnger_VehicleInfo     s_MsgMnger_VehicleInfo,
                                  ST_VEHICLE_HANDSHAKE_INFO s_MsgMnger_VehicleHandshakeInfo,
                                  tMsgMnger_ApaState        s_MsgMnger_ApaState,
                                  tVehi_VehicleDataTx       s_MsgMnger_Ctrl2Chassis)
{
  handshake_output_RestTx(s_MsgMnger_VehicleInfo,s_MsgMnger_Ctrl2Chassis,
                          s_MsgMnger_ApaState,&g_sHandshakeManager,&g_sActuaSrvTx);
  handshake_output_VCU(s_MsgMnger_VehicleInfo,s_MsgMnger_VehicleHandshakeInfo,s_MsgMnger_Ctrl2Chassis,
                      &g_sHandshakeManager,&g_sActuaSrvTx);
  handshake_output_ESC(s_MsgMnger_VehicleInfo,s_MsgMnger_VehicleHandshakeInfo,s_MsgMnger_Ctrl2Chassis,
                      s_MsgMnger_ApaState,&g_sHandshakeManager,&g_sActuaSrvTx);
  handshake_output_EPS(s_MsgMnger_VehicleInfo,s_MsgMnger_VehicleHandshakeInfo,s_MsgMnger_Ctrl2Chassis,
                      &g_sHandshakeManager,&g_sActuaSrvTx);   
  return E_OK;                                     
}

static uint8_t handshake_output_RestTx(tMsgMnger_VehicleInfo    s_MsgMnger_VehicleInfo,
                                       tVehi_VehicleDataTx      s_MsgMnger_Ctrl2Chassis,
                                       tMsgMnger_ApaState       s_MsgMnger_ApaState,
                                       tHandshakeManager*       stHandshakeManager_ptr,
                                       tActuaSrvTx*             stActuaSrvTx_ptr)
{
  float f32VehSpeed       = s_MsgMnger_VehicleInfo.sVehicleDataRx.stVehESCInfo.f32VehicleSpeed;
  tLSAD_SystemSts eLsadSystemSts = s_MsgMnger_ApaState.eLsadSystemSts;
  tActuaSrvRestTx sActuaSrvRestTx = stActuaSrvTx_ptr->sActuaSrvRestTx;
  tHandshakeSts   eHandshakeSts = stHandshakeManager_ptr-> eHandshakeSts;
  tHandshakeTypeRq eHandshakeReq =s_MsgMnger_Ctrl2Chassis.eHandshakeReq;
  tHandshakeType eHandshakeType = stHandshakeManager_ptr-> eHandshakeType;
  switch(eHandshakeSts)
  {
    case HANDSHAKE_UNCONTROLLED: 
      if(LSAD_STS_PREPARE==eLsadSystemSts || LSAD_STS_PREPARE_SUSPEND==eLsadSystemSts || 
        LSAD_STS_HANDSHAKE==eLsadSystemSts || LSAD_STS_ACTIVE==eLsadSystemSts ||
        LSAD_STS_ACTIVE_SUSPEND==eLsadSystemSts)
      {
        sActuaSrvRestTx.APA_MainStas = 0x7;
      }
      else
      {
        sActuaSrvRestTx.APA_MainStas = 0x1;
      }
      
      break; 
    case HANDSHAKE_START: 
    case HANDSHAKE_SUCCESS: 
    case HANDSHAKE_CONTROLLED:
      sActuaSrvRestTx.APA_MainStas = 0x2;
      break;
    case HANDSHAKE_RELEASING: 
    case HANDSHAKE_ABORT: 
    case HANDSHAKE_FAIL: 
      sActuaSrvRestTx.APA_MainStas = 0x7;
      break;
    default:
      sActuaSrvRestTx.APA_MainStas = sActuaSrvRestTx.APA_MainStas;
      break;
  }
  switch(eHandshakeSts)
  {
    case HANDSHAKE_UNCONTROLLED:
      sActuaSrvRestTx.APA_APA_Mode = 0x0;
      sActuaSrvRestTx.MPC_32E_ACCMode = 0x2;
      break;
    case HANDSHAKE_START: 
    case HANDSHAKE_SUCCESS:
      if(HANDSHAKE_RQ_LOW_SPEED== eHandshakeReq)
      {
        sActuaSrvRestTx.APA_APA_Mode = 0x1;
        sActuaSrvRestTx.MPC_32E_ACCMode = 0x2;
      }
      else if(HANDSHAKE_RQ_HIGH_SPEED== eHandshakeReq)
      {
        sActuaSrvRestTx.APA_APA_Mode = 0x0;
        sActuaSrvRestTx.MPC_32E_ACCMode = 0x6;
      }
      else
      {
        sActuaSrvRestTx.APA_APA_Mode = 0x0;
        sActuaSrvRestTx.MPC_32E_ACCMode = 0x2;
      }   
      break;
    case HANDSHAKE_CONTROLLED:
      if(HANDSHAKE_LOW_SPEED== eHandshakeType)
      {
        sActuaSrvRestTx.APA_APA_Mode = 0x1;
        sActuaSrvRestTx.MPC_32E_ACCMode = 0x2;
      }
      else if(HANDSHAKE_HIGH_SPEED== eHandshakeType)
      {
        sActuaSrvRestTx.APA_APA_Mode = 0x0;
        sActuaSrvRestTx.MPC_32E_ACCMode = 
        (s_MsgMnger_Ctrl2Chassis.f32CtrlReqAccel<0.02 && f32VehSpeed<0.02)? 6 : 3;
      }
      else
      {
        sActuaSrvRestTx.APA_APA_Mode = 0x0;
        sActuaSrvRestTx.MPC_32E_ACCMode = 0x2;
      }
      break;  
    case HANDSHAKE_RELEASING : 
    case HANDSHAKE_ABORT : 
    case HANDSHAKE_FAIL:
      if(HANDSHAKE_HIGH_SPEED== eHandshakeType){
        sActuaSrvRestTx.APA_APA_Mode = 0x0;
        sActuaSrvRestTx.MPC_32E_ACCMode = 0x3;
      }
      else{
        sActuaSrvRestTx.APA_APA_Mode = 0x0;
        sActuaSrvRestTx.MPC_32E_ACCMode = 0x2;
      }
      break; 
  } 
  stActuaSrvTx_ptr->sActuaSrvRestTx = sActuaSrvRestTx;
  return E_OK;
}

static uint8_t handshake_output_VCU(tMsgMnger_VehicleInfo    s_MsgMnger_VehicleInfo,
                                    ST_VEHICLE_HANDSHAKE_INFO s_MsgMnger_VehicleHandshakeInfo,
                                    tVehi_VehicleDataTx    s_MsgMnger_Ctrl2Chassis,
                                    tHandshakeManager*  stHandshakeManager_ptr,
                                    tActuaSrvTx*        stActuaSrvTx_ptr)
{
  uint8_t g_SCU_SCUAPASts = s_MsgMnger_VehicleHandshakeInfo.SCU_APA_Sts;
  float f32VehSpeed       = s_MsgMnger_VehicleInfo.sVehicleDataRx.stVehESCInfo.f32VehicleSpeed;
  tVehiGear eVehicleGear = s_MsgMnger_VehicleInfo.sVehicleDataRx.stVehVCUInfo.eVehicleGear;
  tHandshakeSts   eHandshakeSts = stHandshakeManager_ptr-> eHandshakeSts;
  tActuaSrvVCUCtrl sActuaSrvVCUCtrl = stActuaSrvTx_ptr->sActuaSrvVCUCtrl;
  // sActuaSrvVCUCtrl.APS_SCU_TargetGearRequest = VCU_gear_map(s_MsgMnger_Ctrl2Chassis.eGearReq);
  if(HANDSHAKE_RELEASING==eHandshakeSts || HANDSHAKE_ABORT==eHandshakeSts || HANDSHAKE_FAIL==eHandshakeSts)
  {
    sActuaSrvVCUCtrl.APS_SCU_TargetGearRequest = (f32VehSpeed<1)? 1 : VCU_gear_map(s_MsgMnger_Ctrl2Chassis.eGearReq);
  }
  else
  {
    sActuaSrvVCUCtrl.APS_SCU_TargetGearRequest =  VCU_gear_map(s_MsgMnger_Ctrl2Chassis.eGearReq);
  }
  
  // switch(eHandshakeSts)
  // {
  //   case HANDSHAKE_START:
  //     sActuaSrvVCUCtrl.APS_SCU_TargetGearRequest = 
  //     (g_SCU_SCUAPASts == 1)? VCU_gear_map(eVehicleGear) : 0;
  //     break;
  //   case HANDSHAKE_SUCCESS:
  //     break;
  //   case HANDSHAKE_CONTROLLED:
  //     sActuaSrvVCUCtrl.APS_SCU_TargetGearRequest = VCU_gear_map(s_MsgMnger_Ctrl2Chassis.eGearReq);
  //     break;
  //   case HANDSHAKE_RELEASING: case HANDSHAKE_ABORT:
  //     sActuaSrvVCUCtrl.APS_SCU_TargetGearRequest = 
  //     (f32VehSpeed<1 && VEHI_GEAR_P!=eVehicleGear)? 1 : 0;
  //     break;
  //   case HANDSHAKE_FAIL:
  //     sActuaSrvVCUCtrl.APS_SCU_TargetGearRequest = 1;
  //     break;
  //   default:    
  //     sActuaSrvVCUCtrl.APS_SCU_TargetGearRequest = 0;
  //     break;
  // }
  stActuaSrvTx_ptr->sActuaSrvVCUCtrl = sActuaSrvVCUCtrl;
  return E_OK;
}

static uint8_t handshake_output_ESC(tMsgMnger_VehicleInfo    s_MsgMnger_VehicleInfo,
                                    ST_VEHICLE_HANDSHAKE_INFO s_MsgMnger_VehicleHandshakeInfo,
                                    tVehi_VehicleDataTx    s_MsgMnger_Ctrl2Chassis,
                                    tMsgMnger_ApaState       s_MsgMnger_ApaState,
                                    tHandshakeManager*  stHandshakeManager_ptr,
                                    tActuaSrvTx*        stActuaSrvTx_ptr)
{
  float f32VehSpeed       = s_MsgMnger_VehicleInfo.sVehicleDataRx.stVehESCInfo.f32VehicleSpeed;
  tHandshakeSts   eHandshakeSts = stHandshakeManager_ptr-> eHandshakeSts;
  tLSAD_FuncType eLsadFuncType = (tLSAD_FuncType)s_MsgMnger_ApaState.u8LsadFuncType;  
  tActuaSrvESCCtrl sActuaSrvESCCtrl = stActuaSrvTx_ptr->sActuaSrvESCCtrl;
  sActuaSrvESCCtrl.MPC_32E_axvCvUpperValue = 0.1;
  sActuaSrvESCCtrl.MPC_32E_axvCvLowerValue = 0.1;
  sActuaSrvESCCtrl.MPC_32E_aDtUpperLimitAxvCv = 16;
  sActuaSrvESCCtrl.MPC_32E_aDtLowerLimitAxvCv = -16;
  sActuaSrvESCCtrl.MPC_32E_ACC_Minimum_Braking = 0;
  sActuaSrvESCCtrl.MPC_32E_ESC_VLC_ShutDownMode = 0;
  sActuaSrvESCCtrl.MPC_32E_BrakePreferred = 0;
  sActuaSrvESCCtrl.MPC_32E_PADDING_BIT4 = 15;
  sActuaSrvESCCtrl.MPC_32E_PADDING_BIT1_1 = 1;
  sActuaSrvESCCtrl.APA_to_ESP_request_valid = 1;
  sActuaSrvESCCtrl.EPB_EmergencyBrake = 1;
  sActuaSrvESCCtrl.EPB_EmergencyBrakeValid = 1;
  sActuaSrvESCCtrl.APA_FailureBrakeMode = brake_mode_map(s_MsgMnger_Ctrl2Chassis.eAEBFlag);
  if((HANDSHAKE_ABORT==eHandshakeSts ||HANDSHAKE_FAIL==eHandshakeSts)&&
     (0==sActuaSrvESCCtrl.APA_FailureBrakeMode)){
      sActuaSrvESCCtrl.APA_FailureBrakeMode = 1;
  }

  switch(eHandshakeSts)
  {
    case HANDSHAKE_START: 
    case HANDSHAKE_SUCCESS:
      sActuaSrvESCCtrl.APA_SpeedLimit = 0;  
      sActuaSrvESCCtrl.APA_StopDistance = 0;
      sActuaSrvESCCtrl.MPC_32E_axvCvAim = 0;      
      break;
    case HANDSHAKE_CONTROLLED:
      sActuaSrvESCCtrl.APA_SpeedLimit = s_MsgMnger_Ctrl2Chassis.f32CtrlReqSpeed;
      sActuaSrvESCCtrl.APA_StopDistance = s_MsgMnger_Ctrl2Chassis.f32CtrlReqStopDistance*100;
      sActuaSrvESCCtrl.MPC_32E_axvCvAim = s_MsgMnger_Ctrl2Chassis.f32CtrlReqAccel;
      break;
    case HANDSHAKE_RELEASING: 
      sActuaSrvESCCtrl.APA_SpeedLimit = 0;  
      sActuaSrvESCCtrl.APA_StopDistance = 0;
      sActuaSrvESCCtrl.MPC_32E_axvCvAim = s_MsgMnger_Ctrl2Chassis.f32CtrlReqAccel;    
      break;
    case HANDSHAKE_ABORT: 
    case HANDSHAKE_FAIL:
      sActuaSrvESCCtrl.APA_SpeedLimit = 0;  
      sActuaSrvESCCtrl.APA_StopDistance = 0;
      sActuaSrvESCCtrl.MPC_32E_axvCvAim = -1.0;    
      break;  
    default: 
      sActuaSrvESCCtrl.APA_SpeedLimit = 0;  
      sActuaSrvESCCtrl.APA_StopDistance = 0;
      sActuaSrvESCCtrl.MPC_32E_axvCvAim = 0; 
      break;
  } 
  if((LSAD_CRUISE==eLsadFuncType)&&
    (HANDSHAKE_CONTROLLED==eHandshakeSts|| HANDSHAKE_RELEASING==eHandshakeSts ||
     HANDSHAKE_ABORT==eHandshakeSts|| HANDSHAKE_FAIL==eHandshakeSts))
  {
    if(s_MsgMnger_Ctrl2Chassis.f32CtrlReqAccel>0)    
    {
      sActuaSrvESCCtrl.MPC_32E_ACCDecToStopReq = 0;
      sActuaSrvESCCtrl.MPC_32E_ACCDriveOffReq = 1;
    }
    else if(s_MsgMnger_Ctrl2Chassis.f32CtrlReqAccel<0.0)
    {
      sActuaSrvESCCtrl.MPC_32E_ACCDecToStopReq = (f32VehSpeed<0.02)? 1 : 0;       
      sActuaSrvESCCtrl.MPC_32E_ACCDriveOffReq = 0;
    }
  }  
  else
  {
    sActuaSrvESCCtrl.MPC_32E_ACCDecToStopReq = 0;
    sActuaSrvESCCtrl.MPC_32E_ACCDriveOffReq = 0; 
  } 
  // HANDSHAKE_ABORT HANDSHAKE_FAIL 能刹车
  sActuaSrvESCCtrl.APA_StopDistance =  (sActuaSrvESCCtrl.APA_StopDistance>2000)? 2000 : sActuaSrvESCCtrl.APA_StopDistance;
  stActuaSrvTx_ptr->sActuaSrvESCCtrl = sActuaSrvESCCtrl;
  return E_OK;  
}

static uint8_t handshake_output_EPS(tMsgMnger_VehicleInfo    s_MsgMnger_VehicleInfo,
                                    ST_VEHICLE_HANDSHAKE_INFO s_MsgMnger_VehicleHandshakeInfo,
                                    tVehi_VehicleDataTx    s_MsgMnger_Ctrl2Chassis,
                                    tHandshakeManager*  stHandshakeManager_ptr,
                                    tActuaSrvTx*        stActuaSrvTx_ptr)
{
  uint8_t g_EPS_APA_Status = s_MsgMnger_VehicleHandshakeInfo.EPS_APA_Sts;
  float32_t f32SteeringWheelAngle = s_MsgMnger_VehicleInfo.sVehicleDataRx.stVehEPSInfo.f32SteeringWheelAngle;
  tHandshakeSts   eHandshakeSts = stHandshakeManager_ptr-> eHandshakeSts;
  tActuaSrvEPSCtrl sActuaSrvEPSCtrl = stActuaSrvTx_ptr->sActuaSrvEPSCtrl;
  tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
  sActuaSrvEPSCtrl.APA_SteeringCtrlReqForEPSVD = 1;
  static uint8 EPSEnblCnt                      = 0;
  float f32SteeringGap = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32SteerAngleIncreRatioMax;
  static float APA_PreTar_StrAgl = 0;
  APA_PreTar_StrAgl = sActuaSrvEPSCtrl.APA_Tar_StrAgl;//记录上一个周期的方向盘的值
  switch(eHandshakeSts)
  {
    case HANDSHAKE_START: 
      sActuaSrvEPSCtrl.APA_Tar_StrAgl = f32SteeringWheelAngle;     
      if(EPSEnblCnt == 5)     //只有HAN车需要
      {
        sActuaSrvEPSCtrl.APA_SteeringCtrlReqForEPS = 1;
      }
      else
      {
        sActuaSrvEPSCtrl.APA_SteeringCtrlReqForEPS = 0;
        EPSEnblCnt++;
      }   
      break;
    case HANDSHAKE_SUCCESS:
      sActuaSrvEPSCtrl.APA_Tar_StrAgl = f32SteeringWheelAngle;    
      sActuaSrvEPSCtrl.APA_SteeringCtrlReqForEPS = 1;  
      break;  
    case HANDSHAKE_CONTROLLED:
      sActuaSrvEPSCtrl.APA_Tar_StrAgl = s_MsgMnger_Ctrl2Chassis.f32CtrlReqSteer;
      break;
    case HANDSHAKE_RELEASING: 
    case HANDSHAKE_ABORT: 
    case HANDSHAKE_FAIL:
      sActuaSrvEPSCtrl.APA_Tar_StrAgl = f32SteeringWheelAngle;
      EPSEnblCnt = 0;
      break;
    default: 
      sActuaSrvEPSCtrl.APA_Tar_StrAgl = 0;
      sActuaSrvEPSCtrl.APA_SteeringCtrlReqForEPS = 0; 
      EPSEnblCnt = 0; 
      break;
  }
//方向盘保护逻辑
	if (sActuaSrvEPSCtrl.APA_Tar_StrAgl > APA_PreTar_StrAgl + f32SteeringGap)
	{
		sActuaSrvEPSCtrl.APA_Tar_StrAgl = APA_PreTar_StrAgl + f32SteeringGap;
	}
	else if (sActuaSrvEPSCtrl.APA_Tar_StrAgl < APA_PreTar_StrAgl - f32SteeringGap)
	{
		sActuaSrvEPSCtrl.APA_Tar_StrAgl = APA_PreTar_StrAgl - f32SteeringGap;
	}


	if (sActuaSrvEPSCtrl.APA_Tar_StrAgl > stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32SteerAngleMax)
	{
		sActuaSrvEPSCtrl.APA_Tar_StrAgl = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32SteerAngleMax;
	}
	else if (sActuaSrvEPSCtrl.APA_Tar_StrAgl < -stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32SteerAngleMax)
	{
		sActuaSrvEPSCtrl.APA_Tar_StrAgl = -stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32SteerAngleMax;
	}
	else
	{
		//保持
	}
  stActuaSrvTx_ptr->sActuaSrvEPSCtrl = sActuaSrvEPSCtrl;
  return E_OK;
}


static uint8_t  VCU_gear_map(tVehiGear eGearReq)
  {
    uint8_t APS_SCU_TargetGearRequest = 0;
    switch(eGearReq)
    {
      case VEHI_GEAR_D:
        APS_SCU_TargetGearRequest = 4;
        break;
      case VEHI_GEAR_R:
        APS_SCU_TargetGearRequest = 2;
        break;
      case VEHI_GEAR_N:
        APS_SCU_TargetGearRequest = 3;
        break;
      case VEHI_GEAR_P:
        APS_SCU_TargetGearRequest = 1;
        break;
      default:
        APS_SCU_TargetGearRequest = 0;
        break;
    }
    return APS_SCU_TargetGearRequest;
  }

static uint8_t  brake_mode_map(tRequest eAEBFlag)
  {
    uint8_t APA_FailureBrakeMode;
    if(1 == eAEBFlag)
    {
        APA_FailureBrakeMode        = 0x1;
    }
    else if(2 == eAEBFlag)
    {
        APA_FailureBrakeMode        = 0x2;
    }
    else
    {
        APA_FailureBrakeMode        = 0x0;
    }
    return  APA_FailureBrakeMode;   
  }
