#include "handshake_state.h"
#include "adas_project_input.h"
#include "adas_struct.h"
#include "vehicle_service_type.h"
#include "vehicle_service_global_variables.h"
#include "vehicle_service/calib/vehsrv_calib.h"



static uint8_t handshake_state_transition(tMsgMnger_VehicleInfo    s_MsgMnger_VehicleInfo,
                                          ST_VEHICLE_HANDSHAKE_INFO s_MsgMnger_VehicleHandshakeInfo,
                                          tMsgMnger_ApaState       s_MsgMnger_ApaState,
                                          tVehi_VehicleDataTx       s_MsgMnger_Ctrl2Chassis,
                                          tVehiclServiceCommon*    stVehiclServiceCommon_ptr,
                                          tHandshakeManager*       stHandshakeManager_ptr,
                                          tHandshakeManagerTrans*  stHandshakeManagerTrans_ptr);
static uint8_t handshake_state_flow(tHandshakeManager*        stHandshakeManager_ptr,
                                    tHandshakeManagerTrans*   stHandshakeManagerTrans_ptr);
/*	=====================================================================
 *					
 *
 *	===================================================================*/

uint8_t handshake_state(tMsgMnger_ApaState        s_MsgMnger_ApaState,           
                        tMsgMnger_VehicleInfo     s_MsgMnger_VehicleInfo,
                        ST_VEHICLE_HANDSHAKE_INFO s_MsgMnger_VehicleHandshakeInfo,
                        tVehi_VehicleDataTx       s_MsgMnger_Ctrl2Chassis)
{
  handshake_state_transition(s_MsgMnger_VehicleInfo,s_MsgMnger_VehicleHandshakeInfo,s_MsgMnger_ApaState,
                             s_MsgMnger_Ctrl2Chassis,&g_sVehiclServiceCommon,
                             &g_sHandshakeManager,&g_sHandshakeManagerTrans);
  handshake_state_flow(&g_sHandshakeManager,&g_sHandshakeManagerTrans);  
  return E_OK;
}

static uint8_t handshake_state_transition(tMsgMnger_VehicleInfo     s_MsgMnger_VehicleInfo,
                                          ST_VEHICLE_HANDSHAKE_INFO s_MsgMnger_VehicleHandshakeInfo,
                                          tMsgMnger_ApaState        s_MsgMnger_ApaState,
                                          tVehi_VehicleDataTx       s_MsgMnger_Ctrl2Chassis,
                                          tVehiclServiceCommon*     stVehiclServiceCommon_ptr,
                                          tHandshakeManager*        stHandshakeManager_ptr,
                                          tHandshakeManagerTrans*   stHandshakeManagerTrans_ptr)
{
  uint8_t SCU_APA_Sts = s_MsgMnger_VehicleHandshakeInfo.SCU_APA_Sts;
  uint8_t ESC_APA_Sts = s_MsgMnger_VehicleHandshakeInfo.ESC_APA_Sts;
  uint8_t EPS_APA_Sts = s_MsgMnger_VehicleHandshakeInfo.EPS_APA_Sts;
  uint8_t Veh_CDD_Available = s_MsgMnger_VehicleHandshakeInfo.Veh_CDD_Available;
  uint8_t Veh_CDD_Fail = s_MsgMnger_VehicleHandshakeInfo.Veh_CDD_Fail;
  uint8_t Veh_VLCAvailable = s_MsgMnger_VehicleHandshakeInfo.Veh_VLCAvailable;
  uint8_t Veh_VLCFail = s_MsgMnger_VehicleHandshakeInfo.Veh_VLCFail;
  uint8_t bBrakeActiveSts = (uint8_t)s_MsgMnger_VehicleInfo.sVehicleDataRx.stVehVCUInfo.eBrakeActiveSts;
  tLSAD_SystemSts eLsadSystemSts = s_MsgMnger_ApaState.eLsadSystemSts;  
  tLSAD_FuncType eLsadFuncType = (tLSAD_FuncType)s_MsgMnger_ApaState.u8LsadFuncType;
  uint16_t u16HandshakeFailStateTime = stVehiclServiceCommon_ptr->u16HandshakeFailStateTime;
  uint16_t u16HandshakeAbortStateTime = stVehiclServiceCommon_ptr->u16HandshakeAbortStateTime;
  tHandshakeTypeRq eHandshakeReq =s_MsgMnger_Ctrl2Chassis.eHandshakeReq;
  tHandshakeType eHandshakeType = stHandshakeManager_ptr-> eHandshakeType;
  tHandshakeSts   eHandshakeSts = stHandshakeManager_ptr-> eHandshakeSts;
  tHandshakeFailReason eHandshakeFailReason = stHandshakeManager_ptr->eHandshakeFailReason;
  tHandshakeTrans sHandshakeTrans = stHandshakeManagerTrans_ptr->sHandshakeTrans;
  static uint8 HandReleas2UnctrlCnt                      = 0;
  
  sHandshakeTrans.bHandUnctrl2Start =
  ((LSAD_STS_HANDSHAKE == eLsadSystemSts || (LSAD_STS_ACTIVE== eLsadSystemSts && LSAD_CRUISE==eLsadFuncType))
  &&(HANDSHAKE_RQ_TYPE_NONE!= eHandshakeReq)&&(1 == SCU_APA_Sts && 1 == EPS_APA_Sts && 1 == ESC_APA_Sts))? 1:0;
  sHandshakeTrans.bHandStart2Abort = 
  (HANDSHAKE_START == eHandshakeSts && LSAD_STS_QUIT == eLsadSystemSts) ? 1 :0;
  sHandshakeTrans.bHandStart2Fail =
  (HANDSHAKE_START == eHandshakeSts && NO_FAILCODE != eHandshakeFailReason) ? 1 :0;
  sHandshakeTrans.bHandStart2Success =
  ((HANDSHAKE_START == eHandshakeSts)&&
  (2 == SCU_APA_Sts && 2 == EPS_APA_Sts)&&
  ((LSAD_CRUISE==eLsadFuncType && HANDSHAKE_RQ_HIGH_SPEED==eHandshakeReq) ?
  (1==Veh_CDD_Available && 0==Veh_CDD_Fail && 1==Veh_VLCAvailable && 0==Veh_VLCFail): 2 == ESC_APA_Sts))? 1 :0;
  sHandshakeTrans.bHandSuccess2Abort = 
  (HANDSHAKE_SUCCESS == eHandshakeSts && LSAD_STS_TERMINATED == eLsadSystemSts) ? 1 :0;
  sHandshakeTrans.bHandSuccess2Fail =
  (HANDSHAKE_SUCCESS == eHandshakeSts && NO_FAILCODE != eHandshakeFailReason) ? 1 :0;
  sHandshakeTrans.bHandSuccess2Ctrl=
  (HANDSHAKE_SUCCESS == eHandshakeSts && LSAD_STS_ACTIVE == eLsadSystemSts) ? 1 :0;
  sHandshakeTrans.bHandCtrl2Abort = 
  (HANDSHAKE_CONTROLLED == eHandshakeSts && LSAD_STS_TERMINATED == eLsadSystemSts) ? 1 :0;
  sHandshakeTrans.bHandCtrl2Fail =
  (HANDSHAKE_CONTROLLED == eHandshakeSts && NO_FAILCODE != eHandshakeFailReason) ? 1 :0;
  sHandshakeTrans.bHandCtrl2Releas = 
  (HANDSHAKE_CONTROLLED == eHandshakeSts &&
  (LSAD_STS_COMPLETE == eLsadSystemSts || (eHandshakeType!=eHandshakeReq && 1==bBrakeActiveSts))) ? 1 :0;
  sHandshakeTrans.bHandReleas2Fail =
  (HANDSHAKE_RELEASING == eHandshakeSts && NO_FAILCODE != eHandshakeFailReason) ? 1 :0;
  HandReleas2UnctrlCnt = (HANDSHAKE_RELEASING == eHandshakeSts) ? HandReleas2UnctrlCnt+1 : 0; //HANDSHAKE_RELEASING停留2s
  HandReleas2UnctrlCnt = fmin(HandReleas2UnctrlCnt,250);
  sHandshakeTrans.bHandReleas2Unctrl = 
  (HANDSHAKE_RELEASING == eHandshakeSts && HandReleas2UnctrlCnt>160 &&
  2 != ESC_APA_Sts && 2 != SCU_APA_Sts && 2 != EPS_APA_Sts) ? 1 :0;//汉车解除握手需要3s,不然会报错
  u16HandshakeFailStateTime =
  (HANDSHAKE_FAIL == eHandshakeSts) ? u16HandshakeFailStateTime+1 : 0;
  u16HandshakeFailStateTime = fmin(u16HandshakeFailStateTime,500);
  sHandshakeTrans.bHandFail2Unctrl = 
  ((u16HandshakeFailStateTime>160)||(LSAD_STS_STANDBY == eLsadSystemSts))? 1 : 0;
  u16HandshakeAbortStateTime =
  (HANDSHAKE_ABORT == eHandshakeSts) ? u16HandshakeAbortStateTime+1 : 0;
  u16HandshakeAbortStateTime = fmin(u16HandshakeAbortStateTime,500);
  sHandshakeTrans.bHandAbort2Unctrl = 
  ((u16HandshakeAbortStateTime>160)||(LSAD_STS_STANDBY == eLsadSystemSts))? 1 : 0;
  stHandshakeManagerTrans_ptr->sHandshakeTrans = sHandshakeTrans;
  stVehiclServiceCommon_ptr->u16HandshakeFailStateTime = u16HandshakeFailStateTime;
  stVehiclServiceCommon_ptr->u16HandshakeAbortStateTime = u16HandshakeAbortStateTime;
  return E_OK;
}

static uint8_t handshake_state_flow(tHandshakeManager*        stHandshakeManager_ptr,
                             tHandshakeManagerTrans*   stHandshakeManagerTrans_ptr)
{
  tHandshakeSts   eHandshakeSts = stHandshakeManager_ptr-> eHandshakeSts;
  tHandshakeTrans sHandshakeTrans = stHandshakeManagerTrans_ptr->sHandshakeTrans;
  switch(eHandshakeSts)
  {
    case HANDSHAKE_UNCONTROLLED:
      if(sHandshakeTrans.bHandUnctrl2Start)
      {
        eHandshakeSts =  HANDSHAKE_START;
      }
      break;
    case HANDSHAKE_START:
      if(sHandshakeTrans.bHandStart2Abort)
      {
        eHandshakeSts =  HANDSHAKE_ABORT;
      }
      else if(sHandshakeTrans.bHandStart2Fail)
      {
        eHandshakeSts =  HANDSHAKE_FAIL;
      }
      else if(sHandshakeTrans.bHandStart2Success)
      {
        eHandshakeSts =  HANDSHAKE_SUCCESS;
      }
      break;
    case HANDSHAKE_SUCCESS:
      if(sHandshakeTrans.bHandSuccess2Abort)
      {
        eHandshakeSts =  HANDSHAKE_ABORT;
      }
      else if(sHandshakeTrans.bHandSuccess2Fail)
      {
        eHandshakeSts =  HANDSHAKE_FAIL;
      }
      else if(sHandshakeTrans.bHandSuccess2Ctrl)
      {
        eHandshakeSts =  HANDSHAKE_CONTROLLED;
      }
      break;
    case HANDSHAKE_CONTROLLED:
      if(sHandshakeTrans.bHandCtrl2Abort)
      {
        eHandshakeSts =  HANDSHAKE_ABORT;
      }
      else if(sHandshakeTrans.bHandCtrl2Fail)
      {
        eHandshakeSts =  HANDSHAKE_FAIL;
      }
      else if(sHandshakeTrans.bHandCtrl2Releas)
      {
        eHandshakeSts =  HANDSHAKE_RELEASING;
      }
      break;

    case  HANDSHAKE_RELEASING:
      if(sHandshakeTrans.bHandReleas2Fail) 
      {
        eHandshakeSts =  HANDSHAKE_UNCONTROLLED;
      }
      else if(sHandshakeTrans.bHandReleas2Unctrl) 
      {
        eHandshakeSts =  HANDSHAKE_UNCONTROLLED;
      }
      break;
    case  HANDSHAKE_FAIL:
      if(sHandshakeTrans.bHandFail2Unctrl)   
      {
        eHandshakeSts =  HANDSHAKE_UNCONTROLLED;
      }
      break;
    case  HANDSHAKE_ABORT:
      if(sHandshakeTrans.bHandAbort2Unctrl)   
      {
        eHandshakeSts =  HANDSHAKE_UNCONTROLLED;
      }  
      break;
  }
  stHandshakeManager_ptr-> eHandshakeSts = eHandshakeSts;
  return E_OK;
}


