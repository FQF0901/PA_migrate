#ifndef RTW_HEADER_vehicle_service_type_global_h_
#define RTW_HEADER_vehicle_service_type_global_h_
#include "adas_struct.h"
#include "rtwtypes.h"

typedef struct
{
  boolean_T bESCRespFail;
  boolean_T bVCURespFail;
  boolean_T bEPSRespFail;
  boolean_T bEPBReleaseRespFail;
  boolean_T bEPBClampRespFail;
  boolean_T bIDBFail;
  boolean_T bVCUFail;
  boolean_T bEPSFail;
  boolean_T bIDBOff;
  boolean_T bVCUOff;
  boolean_T bEPSOff;
  boolean_T bPlausChkFail;
  boolean_T bESCComFail;
  boolean_T bVCUComFail;
  boolean_T bEPSComFail;
  boolean_T bPASysFail;
  boolean_T bExtSysFault;
}

tHandshakeFailTrans;

typedef struct
{
  boolean_T bHandUnctrl2Start;
  boolean_T bHandStart2Abort;
  boolean_T bHandSuccess2Abort;
  boolean_T bHandSuccess2Ctrl;
  boolean_T bHandCtrl2Abort;
  boolean_T bHandCtrl2Releas;
  boolean_T bHandCtrl2Success;
  boolean_T bHandStart2Success;
  boolean_T bHandStart2Fail;
  boolean_T bHandSuccess2Fail;
  boolean_T bHandCtrl2Fail;
  boolean_T bHandReleas2Fail;
  boolean_T bHandAbort2Fail;
  boolean_T bHandReleas2Unctrl;
  boolean_T bHandAbort2Unctrl;
  boolean_T bHandFail2Unctrl;
}
tHandshakeTrans;


typedef struct
{
  tHandshakeFailTrans sHandshakeFailTrans;
  tHandshakeTrans sHandshakeTrans;
}

tHandshakeManagerTrans;

typedef struct 
{
  uint16_t u16ESCResponseTime;
  uint16_t u16VCUResponseTime;
  uint16_t u16VCUGearResponseTime;
  uint16_t u16EPSResponseTime;
  uint16_t u16HandshakeFailStateTime;
  uint16_t u16HandshakeAbortStateTime;
} 
tVehiclServiceCommon;

typedef struct
{
  uint8 APS_SCU_TargetGearRequest;
  uint8 u8Res3[3];
}
tActuaSrvVCUCtrl;
typedef struct
{
  float   APA_StopDistance;
  float   APA_SpeedLimit;
  float   MPC_32E_axvCvUpperValue;
  float   MPC_32E_axvCvLowerValue;
  float   MPC_32E_aDtUpperLimitAxvCv;
  float   MPC_32E_aDtLowerLimitAxvCv;
  float   MPC_32E_axvCvAim;
  uint8   APA_FailureBrakeMode;
  uint8   APA_to_ESP_request_valid;
  uint8   EPB_EmergencyBrake;
  uint8   EPB_EmergencyBrakeValid;
  uint8   MPC_32E_ACCDecToStopReq;
  uint8   MPC_32E_ACCDriveOffReq;
  uint8   MPC_32E_ACC_Minimum_Braking;
  uint8   MPC_32E_ESC_VLC_ShutDownMode;
  uint8   MPC_32E_BrakePreferred;
  uint8   MPC_32E_PADDING_BIT4;
  uint8   MPC_32E_PADDING_BIT1_1;
  uint8   epb_req;
  uint8   torq_req_validity;
  uint8   u8Res2[2];
}
tActuaSrvESCCtrl;
typedef struct
{
  float   APA_Tar_StrAgl;
  uint8   APA_SteeringCtrlReqForEPS;
  uint8   APA_SteeringCtrlReqForEPSVD;
  uint8   u8Res2[2];
}
tActuaSrvEPSCtrl;
typedef struct
{
  uint8 u8Res4[4];
}
tActuaSrvEMSCtrl;
typedef struct
{
  uint8 u8Res4[4];
}
tActuaSrvTCUCtrl;
typedef struct
{
  uint8   APA_MainStas;
  uint8   APA_APA_Mode; 
  uint8   MPC_32E_ACCMode;
  uint8 u8Res2[2];
}
tActuaSrvRestTx;
typedef struct
{
  tActuaSrvVCUCtrl sActuaSrvVCUCtrl;
  tActuaSrvESCCtrl sActuaSrvESCCtrl;
  tActuaSrvEPSCtrl sActuaSrvEPSCtrl;
  tActuaSrvEMSCtrl sActuaSrvEMSCtrl;
  tActuaSrvTCUCtrl sActuaSrvTCUCtrl;
  tActuaSrvRestTx sActuaSrvRestTx;
}
tActuaSrvTx;

#endif //RTW_HEADER_vehicle_service_type_global_h_
