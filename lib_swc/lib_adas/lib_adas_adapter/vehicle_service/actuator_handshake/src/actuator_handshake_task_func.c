#include "adas_struct.h"
#include "vehicle_service_global_variables.h"
#include "vehicle_service/calib/vehsrv_calib.h"
#include "vehicle_service/actuator_handshake/src/handshake_common/handshake_common.h"
#include "vehicle_service/actuator_handshake/src/handshake_state/handshake_state.h"
#include "vehicle_service/actuator_handshake/src/handshake_fail_reason/handshake_fail_reason.h"
#include "vehicle_service/actuator_handshake/src/actuator_handshake_output/actuator_handshake_output.h"
#include "actuator_handshake_task_func.h"

/*	=====================================================================
 *
 *
 *	===================================================================*/

uint8 actuator_handshake_initialize()
{
      
      /* states (dwork) */
  (void) memset((void *) &g_sHandshakeManager, 0,sizeof(tHandshakeManager));
  (void) memset((void *) &g_sHandshakeManagerTrans, 0,sizeof(tHandshakeManagerTrans));
  (void) memset((void *) &g_sActuaSrvTx, 0,sizeof(tActuaSrvTx));  
  (void) memset((void *) &g_sVehiclServiceCommon, 0,sizeof(tVehiclServiceCommon)); 
  return E_OK;
}

uint8 actuator_handshake_step()
{
  tMsgMnger_VehicleInfo     s_MsgMnger_VehicleInfo;
  ST_VEHICLE_HANDSHAKE_INFO s_MsgMnger_VehicleHandshakeInfo;
  tVehi_VehicleDataTx       s_MsgMnger_Ctrl2Chassis;
  tMsgMnger_ApaState        s_MsgMnger_ApaState;
  Rte_Read_MsgManager_VehicleInfo(&s_MsgMnger_VehicleInfo);
  Rte_Read_HandShakeInfo(&s_MsgMnger_VehicleHandshakeInfo); 
  Rte_Read_MsgManager_ApaState(&s_MsgMnger_ApaState);
  Rte_Read_CTRL2CHASSIS(&s_MsgMnger_Ctrl2Chassis);
  handshake_common(s_MsgMnger_ApaState,s_MsgMnger_Ctrl2Chassis,&g_sHandshakeManager);
  handshake_fail_reason(s_MsgMnger_VehicleInfo,s_MsgMnger_VehicleHandshakeInfo,s_MsgMnger_ApaState);
  handshake_state(s_MsgMnger_ApaState,s_MsgMnger_VehicleInfo,s_MsgMnger_VehicleHandshakeInfo,s_MsgMnger_Ctrl2Chassis);
  actuator_handshake_output(s_MsgMnger_VehicleInfo,s_MsgMnger_VehicleHandshakeInfo,s_MsgMnger_ApaState,
                              s_MsgMnger_Ctrl2Chassis);
  Rte_Write_ActuaSrvTx(&g_sActuaSrvTx);                            
  return E_OK;
}
