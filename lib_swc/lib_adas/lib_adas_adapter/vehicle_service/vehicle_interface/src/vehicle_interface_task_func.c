#include "vehicle_interface_task_func.h"
#include "vehicle_service_math.h"
#include "vehicle_service/calib/vehsrv_calib.h"
#include "vehicle_service/ctrl_adapter/ctrl_adapter.h"
#include "vehicle_service/ctrl_diag/ctrl_diag.h"
#include "vehicle_service/calib/online/online_calib_algo.h"

/*	=====================================================================
 *
 *						vehicle_interface definitions
 *
 *	===================================================================*/

static float Ctrl_CalDistanceDiff(uint16_t u16WheelImpulseNewReceive,
                                  uint16_t u16WhellImpulseLocalRecord,
                                  uint8_t  u8Direction);

uint8_t vehicle_interface_initialize(void)
{
  uint8_t rtn = E_OK;
    /* states (dwork) */
  (void) memset((void *) &g_sVehDataRx, 0, sizeof(tVehDataRx));
  g_sVehDataRx.sVehESCInfo.stVehSpdImpLPF.f32LPF_den_2 = -0.7;
  g_sVehDataRx.sVehESCInfo.stVehSpdImpLPF.f32LPF_num_1 = 0.15;
  g_sVehDataRx.sVehESCInfo.stVehSpdImpLPF.f32LPF_num_2 = 0.15; 
  return rtn;
}


uint8_t vehicle_interface_step(tVehDataRx* stVehDataRx_ptr)
{
  uint8_t u8ErrCode = 0;
  static  uint8_t u8VehStandStill = 0;
  tMsgMnger_VehicleInfo   msnger_VehicleInfo;
  Rte_Read_MsgManager_VehicleInfo(&msnger_VehicleInfo);
  u8ErrCode = Ctrl_DiagInputChassis(&msnger_VehicleInfo);  
  //EPS
  stVehDataRx_ptr->sVehEPSInfo.f32StrWhlAngDeg = msnger_VehicleInfo.sVehicleDataRx.stVehEPSInfo.f32SteeringWheelAngle;
  //VCU
  stVehDataRx_ptr->sVehVCUInfo.bBrkPedal = (boolean)msnger_VehicleInfo.sVehicleDataRx.stVehVCUInfo.eBrakeActiveSts;
  if(VEHI_GEAR_P == msnger_VehicleInfo.sVehicleDataRx.stVehVCUInfo.eVehicleGear){
    stVehDataRx_ptr->sVehVCUInfo.eVehActualGear = P_GEAR;
  }
  else if(VEHI_GEAR_R == msnger_VehicleInfo.sVehicleDataRx.stVehVCUInfo.eVehicleGear){
    stVehDataRx_ptr->sVehVCUInfo.eVehActualGear = R_GEAR;
  }
  else if(VEHI_GEAR_N == msnger_VehicleInfo.sVehicleDataRx.stVehVCUInfo.eVehicleGear){
    stVehDataRx_ptr->sVehVCUInfo.eVehActualGear = N_GEAR;
  }
  else if(VEHI_GEAR_D == msnger_VehicleInfo.sVehicleDataRx.stVehVCUInfo.eVehicleGear){
    stVehDataRx_ptr->sVehVCUInfo.eVehActualGear = D_GEAR;
  }

    //ESC
  stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph = msnger_VehicleInfo.sVehicleDataRx.stVehESCInfo.f32VehicleSpeed;
  stVehDataRx_ptr->sVehESCInfo.u16WhlPulFL  = msnger_VehicleInfo.sVehicleDataRx.stVehESCInfo.u16WheSpePulFL;
  stVehDataRx_ptr->sVehESCInfo.u16WhlPulFR  = msnger_VehicleInfo.sVehicleDataRx.stVehESCInfo.u16WheSpePulFR;
  stVehDataRx_ptr->sVehESCInfo.u16WhlPulRL  = msnger_VehicleInfo.sVehicleDataRx.stVehESCInfo.u16WheSpePulRL;
  stVehDataRx_ptr->sVehESCInfo.u16WhlPulRR  = msnger_VehicleInfo.sVehicleDataRx.stVehESCInfo.u16WheSpePulRR;

  stVehDataRx_ptr->sVehESCInfo.f32WhlSpdFLKph = msnger_VehicleInfo.sVehicleDataRx.stVehESCInfo.f32WheelSpeedFL; //ST_VEHICLE_ESP_INFO
  stVehDataRx_ptr->sVehESCInfo.f32WhlSpdFRKph = msnger_VehicleInfo.sVehicleDataRx.stVehESCInfo.f32WheelSpeedFR;
  stVehDataRx_ptr->sVehESCInfo.f32WhlSpdRLKph = msnger_VehicleInfo.sVehicleDataRx.stVehESCInfo.f32WheelSpeedRL;
  stVehDataRx_ptr->sVehESCInfo.f32WhlSpdRRKph = msnger_VehicleInfo.sVehicleDataRx.stVehESCInfo.f32WheelSpeedRR;

  stVehDataRx_ptr->sVehESCInfo.eWhlDirFL = (tWhlSpdDir)msnger_VehicleInfo.sVehicleDataRx.stVehESCInfo.eWheelDirFL; //ST_VEHICLE_ESP_INFO
  stVehDataRx_ptr->sVehESCInfo.eWhlDirFR = (tWhlSpdDir)msnger_VehicleInfo.sVehicleDataRx.stVehESCInfo.eWheelDirFR;
  stVehDataRx_ptr->sVehESCInfo.eWhlDirRL = (tWhlSpdDir)msnger_VehicleInfo.sVehicleDataRx.stVehESCInfo.eWheelDirRL;
  stVehDataRx_ptr->sVehESCInfo.eWhlDirRR = (tWhlSpdDir)msnger_VehicleInfo.sVehicleDataRx.stVehESCInfo.eWheelDirRR;

  u8VehStandStill = (1==msnger_VehicleInfo.sVehicleDataRx.stVehESCInfo.u8VehStantStill &&msnger_VehicleInfo.sVehicleDataRx.stVehESCInfo.f32VehicleSpeed<0.1) 
                    ? u8VehStandStill+1 : 0;
  u8VehStandStill = fmin(u8VehStandStill,100);                  
  stVehDataRx_ptr->sVehESCInfo.bVehStandStill = (u8VehStandStill>25) ? true : false;//保证换档时，停留时间0.5s
  stVehDataRx_ptr->sVehVCUInfo.eSysPwrMd = SYS_PWR_MD_RUN;
    
    // --- Calculate the vehicle speed by impulse.
  VehInter_CalVehicleSpeedImpulse(stVehDataRx_ptr);
  LpfCalculation(&stVehDataRx_ptr->sVehESCInfo.stVehSpdImpLPF);
  stVehDataRx_ptr->sVehESCInfo.f32VehSpdImp = stVehDataRx_ptr->sVehESCInfo.stVehSpdImpLPF.f32LPF_filter_yk;

  //Wheel speed is opposite to gear direction
  

  Rte_Write_MsgManager_APPVehData(stVehDataRx_ptr); 

  CalibOnlineProcess();

  return u8ErrCode;
}

uint8_t VehInter_CalVehicleSpeedImpulse(tVehDataRx*  stVehDataRx_ptr)
{
  float f32DistanceDiffRL = 0.0l;
  float f32DistanceDiffRR = 0.0l;
  float f32Ts = 0.02;
  float f32VehSpeedImpSum = 0.0l;
  float f32VehSpdImpulseCurrent = 0.0l;
  float f32VehSpdImpulseAverage = 0.0l;

  #define CtrlPara_START_SEC_VAR		// Memory allocation
  #include "proj_MemMap.h"

    // --- to put into the global variable g_stChassisToCtrlInfo.
  static float arrVehSpdImpulse[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  static uint8_t u8Index = 0;
  static float f32VehSpdSum = 0;
  static uint8_t u8ArrayLength = 0;

  #define CtrlPara_STOP_SEC_VAR	// Memory allocation end.
  #include "proj_MemMap.h"

  f32DistanceDiffRL = Ctrl_CalDistanceDiff(stVehDataRx_ptr->sVehESCInfo.u16WhlPulRL, stVehDataRx_ptr->sVehESCInfo.u16WhlPulRL, (uint8_t)stVehDataRx_ptr->sVehESCInfo.eWhlDirRL);
  f32DistanceDiffRR = Ctrl_CalDistanceDiff(stVehDataRx_ptr->sVehESCInfo.f32WhlSpdRRKph, stVehDataRx_ptr->sVehESCInfo.u16WhlPulRR, (uint8_t)stVehDataRx_ptr->sVehESCInfo.eWhlDirRR);
  f32VehSpeedImpSum = (f32DistanceDiffRL + f32DistanceDiffRR) / 2;
  f32VehSpdImpulseCurrent = 3.6 * f32VehSpeedImpSum / f32Ts ;  // unit: km/h

	arrVehSpdImpulse[u8Index] = f32VehSpdImpulseCurrent;
	f32VehSpdSum += f32VehSpdImpulseCurrent;
	u8Index++;
	u8Index = u8Index % 16;
  u8ArrayLength++;

  if (u8ArrayLength >= 16){
    u8ArrayLength = 16;
  }
	f32VehSpdImpulseAverage = fabs(f32VehSpdSum / u8ArrayLength);
	f32VehSpdSum -= arrVehSpdImpulse[u8Index];

  stVehDataRx_ptr->sVehESCInfo.f32VehSpdImp = f32VehSpdImpulseAverage;

	return E_OK;
}

static float Ctrl_CalDistanceDiff(uint16_t u16WheelImpulseNewReceive,
                                  uint16_t u16WhellImpulseLocalRecord,
                                  uint8_t  u8Direction)
{
  #define CtrlPara_START_SEC_VAR		// Memory allocation
  #include "proj_MemMap.h"

    // --- to put into the global variable g_stChassisToCtrlInfo.
  static float f32Distance = 0;

  #define CtrlPara_STOP_SEC_VAR	// Memory allocation end.
  #include "proj_MemMap.h"

  float f32DistanceDiff = 0.0l;
  tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
  float RCstep      = stCalibPF_ptr->stPFVehCalib.Calib_f32ImpuseGap;
  uint16_t u16RCMax = stCalibPF_ptr->stPFVehCalib.Calib_f32ImpulseMax;

	if(5000 == u16WhellImpulseLocalRecord ){
    u16WhellImpulseLocalRecord = u16WheelImpulseNewReceive;
	}

  if (u16WheelImpulseNewReceive >= u16WhellImpulseLocalRecord && 1  == u8Direction){
		f32DistanceDiff = ((float)(u16WheelImpulseNewReceive - u16WhellImpulseLocalRecord)) * RCstep;
    f32Distance += f32DistanceDiff;
  }
  else if (u16WheelImpulseNewReceive >= u16WhellImpulseLocalRecord && 2  == u8Direction){
		f32DistanceDiff = -((float)(u16WheelImpulseNewReceive - u16WhellImpulseLocalRecord)) * RCstep;
    f32Distance -= f32DistanceDiff;
  }
  else if (u16WheelImpulseNewReceive < u16WhellImpulseLocalRecord && 1  == u8Direction){
		f32DistanceDiff = ((float)(u16WheelImpulseNewReceive + u16RCMax - u16WhellImpulseLocalRecord))*RCstep;
    f32Distance += f32DistanceDiff;
  }
  else if (u16WheelImpulseNewReceive < u16WhellImpulseLocalRecord && 2  == u8Direction){
		f32DistanceDiff = -((float)(u16WheelImpulseNewReceive + u16RCMax - u16WhellImpulseLocalRecord))*RCstep;
    f32Distance -= f32DistanceDiff;
  }
  else{
  	f32Distance = 0;
  	f32DistanceDiff = 0;
  }

  return f32DistanceDiff;
}

