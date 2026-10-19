#ifndef RTW_HEADER_vehicle_service_global_h_
#define RTW_HEADER_vehicle_service_global_h_
#include "adas_project_input.h"
#include "adas_struct.h"
#include "vehicle_service_type.h"

#define ADAS_ADAPTOR_SUCCESS   0
#define ADAS_ADAPTOR_ERR       1
#define ADAS_HANDSHAKE_ERR 1

extern tVehDataRx            		     g_sVehDataRx;
extern tHandshakeManager                 g_sHandshakeManager;
extern tHandshakeManagerTrans            g_sHandshakeManagerTrans;
extern tActuaSrvTx                       g_sActuaSrvTx;
extern tVehiclServiceCommon              g_sVehiclServiceCommon;
extern tDiagInfo                         g_sDiagInfo;

#endif //RTW_HEADER_vehicle_service_global_h_
