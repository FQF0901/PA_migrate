#include "handshake_common.h"
#include "vehicle_service_math.h"
#include "adas_struct.h"
#include "adas_project_input.h"
#include "vehicle_service_type.h"
#include "vehicle_service_global_variables.h"
#include "vehicle_service/calib/vehsrv_calib.h"

                                       



/*	=====================================================================
 *					
 *
 *	===================================================================*/
uint8_t handshake_common(tMsgMnger_ApaState       s_MsgMnger_ApaState,
                         tVehi_VehicleDataTx       s_MsgMnger_Ctrl2Chassis,
                         tHandshakeManager*       stHandshakeManager_ptr)
{ 
  tHandshakeTypeRq eHandshakeReq =s_MsgMnger_Ctrl2Chassis.eHandshakeReq;
  tHandshakeSts  eHandshakeSts = stHandshakeManager_ptr-> eHandshakeSts;
  tHandshakeType eHandshakeType = stHandshakeManager_ptr-> eHandshakeType;
  if(HANDSHAKE_UNCONTROLLED == eHandshakeSts)
  {
    eHandshakeType = HANDSHAKE_TYPE_NONE;
  }
  else if(HANDSHAKE_SUCCESS == eHandshakeSts)
  {
    if(HANDSHAKE_RQ_LOW_SPEED==eHandshakeReq)
    {
      eHandshakeType = HANDSHAKE_LOW_SPEED;
    }
    else if(HANDSHAKE_RQ_HIGH_SPEED==eHandshakeReq)
    {
      eHandshakeType = HANDSHAKE_HIGH_SPEED;
    }
    else
    {
      eHandshakeType = HANDSHAKE_TYPE_NONE;
    }
  }
  else 
  {
    ;
  }
  stHandshakeManager_ptr-> eHandshakeType = eHandshakeType; 
  return E_OK;
}



