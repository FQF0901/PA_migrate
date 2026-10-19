#ifndef RTW_HEADER_handshake_common_h_
#define RTW_HEADER_handshake_common_h_
#include "adas_project_input.h"
#include "adas_struct.h"

uint8_t handshake_common(tMsgMnger_ApaState       s_MsgMnger_ApaState,
                         tVehi_VehicleDataTx       s_MsgMnger_Ctrl2Chassis,
                         tHandshakeManager*       stHandshakeManager_ptr);
#endif //RTW_HEADER_handshake_common_h_


