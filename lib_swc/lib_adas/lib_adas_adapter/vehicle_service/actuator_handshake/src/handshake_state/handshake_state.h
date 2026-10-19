#ifndef RTW_HEADER_handshake_state_h_
#define RTW_HEADER_handshake_state_h_
#include "adas_project_input.h"
#include "adas_struct.h"
#include "vehicle_service_type.h"

uint8_t handshake_state(tMsgMnger_ApaState        s_stMsgMngerVehMsgApaState,
                        tMsgMnger_VehicleInfo     s_msnger_VehicleInfo,
                        ST_VEHICLE_HANDSHAKE_INFO s_MsgMnger_VehicleHandshakeInfo,
                        tVehi_VehicleDataTx       s_MsgMnger_Ctrl2Chassis);

#endif //RTW_HEADER_handshake_state_h_


