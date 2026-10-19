#include "handshake_fail_reason.h"
#include "vehicle_service_math.h"
#include "adas_struct.h"
#include "adas_project_input.h"
#include "vehicle_service_type.h"
#include "vehicle_service_global_variables.h"
#include "vehicle_service/calib/vehsrv_calib.h"


static boolean_T bGearResponse(uint8_t APS_SCU_TargetGearRequest,tVehiGear eVehicleGear);                                         
static uint8_t handshake_fail_reason_transition(tMsgMnger_VehicleInfo    s_MsgMnger_VehicleInfo,
                                                ST_VEHICLE_HANDSHAKE_INFO s_MsgMnger_VehicleHandshakeInfo,
                                                tMsgMnger_ApaState       s_MsgMnger_ApaState,
                                                tHandshakeManager*       stHandshakeManager_ptr,
                                                tVehiclServiceCommon*    stVehiclServiceCommon_ptr,
                                                tActuaSrvTx*             stActuaSrvTx_ptr, 
                                                tHandshakeManagerTrans*  stHandshakeManagerTrans_ptr);
static uint8_t handshake_fail_reason_state(tHandshakeManagerTrans*  stHandshakeManagerTrans_ptr,
                                    tHandshakeManager*       stHandshakeManager_ptr);

/*	=====================================================================
 *					
 *
 *	===================================================================*/
uint8_t handshake_fail_reason(tMsgMnger_VehicleInfo    s_MsgMnger_VehicleInfo,
                              ST_VEHICLE_HANDSHAKE_INFO s_MsgMnger_VehicleHandshakeInfo,
                              tMsgMnger_ApaState       s_MsgMnger_ApaState)
{
  handshake_fail_reason_transition(s_MsgMnger_VehicleInfo,s_MsgMnger_VehicleHandshakeInfo,s_MsgMnger_ApaState,&g_sHandshakeManager,
                                   &g_sVehiclServiceCommon,&g_sActuaSrvTx,&g_sHandshakeManagerTrans);
  handshake_fail_reason_state(&g_sHandshakeManagerTrans,&g_sHandshakeManager);  
  return E_OK;
}

static uint8_t handshake_fail_reason_transition(tMsgMnger_VehicleInfo    s_MsgMnger_VehicleInfo,
                                                ST_VEHICLE_HANDSHAKE_INFO s_MsgMnger_VehicleHandshakeInfo,
                                                tMsgMnger_ApaState       s_MsgMnger_ApaState,
                                                tHandshakeManager*       stHandshakeManager_ptr,
                                                tVehiclServiceCommon*    stVehiclServiceCommon_ptr,
                                                tActuaSrvTx*             stActuaSrvTx_ptr, 
                                                tHandshakeManagerTrans*  stHandshakeManagerTrans_ptr)
{
  uint8_t ESC_APA_Sts = s_MsgMnger_VehicleHandshakeInfo.ESC_APA_Sts;
  uint8_t SCU_APA_Sts = s_MsgMnger_VehicleHandshakeInfo.SCU_APA_Sts;
  uint8_t EPS_APA_Sts = s_MsgMnger_VehicleHandshakeInfo.EPS_APA_Sts;
  uint8_t Veh_CDD_Available = s_MsgMnger_VehicleHandshakeInfo.Veh_CDD_Available;
  uint8_t Veh_CDD_Fail = s_MsgMnger_VehicleHandshakeInfo.Veh_CDD_Fail;
  uint8_t Veh_VLCAvailable = s_MsgMnger_VehicleHandshakeInfo.Veh_VLCAvailable;
  uint8_t Veh_VLCFail = s_MsgMnger_VehicleHandshakeInfo.Veh_VLCFail;  
  tVehiGear eVehicleGear = s_MsgMnger_VehicleInfo.sVehicleDataRx.stVehVCUInfo.eVehicleGear;
  tLSAD_FuncType eLsadFuncType = (tLSAD_FuncType)s_MsgMnger_ApaState.u8LsadFuncType;
  tHandshakeType eHandshakeType = stHandshakeManager_ptr-> eHandshakeType;
  tHandshakeSts  eHandshakeSts = stHandshakeManager_ptr-> eHandshakeSts;
  uint16_t u16ESCResponseTime = stVehiclServiceCommon_ptr->u16ESCResponseTime;
  uint16_t u16VCUResponseTime = stVehiclServiceCommon_ptr->u16VCUResponseTime;
  uint16_t u16VCUGearResponseTime = stVehiclServiceCommon_ptr->u16VCUGearResponseTime;
  uint16_t u16EPSResponseTime = stVehiclServiceCommon_ptr->u16EPSResponseTime;
  tActuaSrvVCUCtrl sActuaSrvVCUCtrl = stActuaSrvTx_ptr->sActuaSrvVCUCtrl;
  tHandshakeFailTrans sHandshakeFailTrans = stHandshakeManagerTrans_ptr->sHandshakeFailTrans;

  u16ESCResponseTime =
  ((HANDSHAKE_START == eHandshakeSts && 1!=ESC_APA_Sts)||     //HANDSHAKE_START 不区分ESC_APA_Sts 和Veh_CDD_Available ...
  ((HANDSHAKE_SUCCESS == eHandshakeSts || HANDSHAKE_CONTROLLED == eHandshakeSts) &&
  ((LSAD_CRUISE==eLsadFuncType && HANDSHAKE_HIGH_SPEED==eHandshakeType) ?
  (0==Veh_CDD_Available || 1==Veh_CDD_Fail || 0==Veh_VLCAvailable || 1==Veh_VLCFail): 2!=ESC_APA_Sts))||
  (HANDSHAKE_RELEASING == eHandshakeSts && 2==ESC_APA_Sts))? u16ESCResponseTime+1 : 0;
  u16ESCResponseTime = fmin(u16ESCResponseTime,300);
  sHandshakeFailTrans.bESCRespFail = (u16ESCResponseTime>250) ? 1:0;
  u16VCUResponseTime = 
  ((HANDSHAKE_START == eHandshakeSts && 1!=SCU_APA_Sts)||
  ((HANDSHAKE_SUCCESS == eHandshakeSts || HANDSHAKE_CONTROLLED == eHandshakeSts) && 2!=SCU_APA_Sts)||
  (HANDSHAKE_RELEASING == eHandshakeSts && 2==SCU_APA_Sts))? u16VCUResponseTime+1 : 0;
  u16VCUResponseTime = fmin(u16VCUResponseTime,300);
  u16VCUGearResponseTime = 
  (HANDSHAKE_CONTROLLED == eHandshakeSts && 
  !bGearResponse(sActuaSrvVCUCtrl.APS_SCU_TargetGearRequest,eVehicleGear))? u16VCUGearResponseTime+1 :0;
  u16VCUGearResponseTime = fmin(u16VCUGearResponseTime,300);
  sHandshakeFailTrans.bVCURespFail =((u16VCUResponseTime>120)||(u16VCUGearResponseTime>150))? 1: 0;
  u16EPSResponseTime =
  ((HANDSHAKE_START == eHandshakeSts && 1!=EPS_APA_Sts)||
  ((HANDSHAKE_SUCCESS == eHandshakeSts || HANDSHAKE_CONTROLLED == eHandshakeSts) && 2!=EPS_APA_Sts)||
  (HANDSHAKE_RELEASING == eHandshakeSts && 2==EPS_APA_Sts))? u16EPSResponseTime+1 :0;
  u16EPSResponseTime = fmin(u16EPSResponseTime,300);
  sHandshakeFailTrans.bEPSRespFail = (u16EPSResponseTime>120)? 1 : 0;
  stHandshakeManagerTrans_ptr->sHandshakeFailTrans = sHandshakeFailTrans;
  stVehiclServiceCommon_ptr->u16ESCResponseTime = u16ESCResponseTime;
  stVehiclServiceCommon_ptr->u16VCUResponseTime = u16VCUResponseTime;
  stVehiclServiceCommon_ptr->u16VCUGearResponseTime = u16VCUGearResponseTime;
  stVehiclServiceCommon_ptr->u16EPSResponseTime = u16EPSResponseTime; 
  return E_OK;
}

static uint8_t handshake_fail_reason_state(tHandshakeManagerTrans*  stHandshakeManagerTrans_ptr,
                                           tHandshakeManager*       stHandshakeManager_ptr)
{
  tHandshakeFailTrans sHandshakeFailTrans = stHandshakeManagerTrans_ptr->sHandshakeFailTrans;
  tHandshakeSts  eHandshakeSts = stHandshakeManager_ptr-> eHandshakeSts;
  tHandshakeFailReason eHandshakeFailReason = stHandshakeManager_ptr->eHandshakeFailReason;

  if(HANDSHAKE_UNCONTROLLED == eHandshakeSts)
  {
    eHandshakeFailReason = NO_FAILCODE;
  }
  else
  {
    if(sHandshakeFailTrans.bESCRespFail)
    {
      eHandshakeFailReason = ESC_RESPONSE_OVERTIME;
    }
    else if(sHandshakeFailTrans.bVCURespFail)
    {
      eHandshakeFailReason = VCU_RESPONSE_OVERTIME;
    }
    else if(sHandshakeFailTrans.bEPSRespFail)
    {
      eHandshakeFailReason = EPS_RESPONSE_OVERTIME;
    }
  }
  stHandshakeManager_ptr->eHandshakeFailReason = eHandshakeFailReason;
  return E_OK;
}

static boolean_T bGearResponse(uint8_t APS_SCU_TargetGearRequest,tVehiGear eVehicleGear)
{
  if((1==APS_SCU_TargetGearRequest && VEHI_GEAR_P==eVehicleGear)||
    (2==APS_SCU_TargetGearRequest && VEHI_GEAR_R==eVehicleGear)||
    (3==APS_SCU_TargetGearRequest && VEHI_GEAR_N==eVehicleGear)||
    (4==APS_SCU_TargetGearRequest && VEHI_GEAR_D==eVehicleGear))
  {
    return true;
  }
  else
  {
    return false;
  }
}


