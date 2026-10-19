#ifndef RTW_HEADER_handshake_fail_reason_h_
#define RTW_HEADER_handshake_fail_reason_h_
#include "adas_project_input.h"
#include "adas_struct.h"

uint8_t handshake_fail_reason(tMsgMnger_VehicleInfo    s_MsgMnger_VehicleInfo,
                              ST_VEHICLE_HANDSHAKE_INFO s_MsgMnger_VehicleHandshakeInfo,
                              tMsgMnger_ApaState       s_MsgMnger_ApaState);
#endif //RTW_HEADER_handshake_fail_reason_h_


