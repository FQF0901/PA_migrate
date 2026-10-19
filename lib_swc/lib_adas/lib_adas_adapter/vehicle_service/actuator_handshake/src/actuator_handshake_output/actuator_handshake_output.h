#ifndef RTW_HEADER_actuator_handshake_output_h_
#define RTW_HEADER_actuator_handshake_output_h_
#include "adas_project_input.h"
#include "adas_struct.h"

uint8_t actuator_handshake_output(tMsgMnger_VehicleInfo     s_MsgMnger_VehicleInfo,
                                  ST_VEHICLE_HANDSHAKE_INFO s_MsgMnger_VehicleHandshakeInfo,
                                  tMsgMnger_ApaState        s_stMsgMngerVehMsgApaState,
                                  tVehi_VehicleDataTx        s_MsgMnger_Ctrl2Chassis);
                                                         


#endif //RTW_HEADER_actuator_handshake_output_h_


