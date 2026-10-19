#ifndef wrapper_api_H_
#define wrapper_api_H_
#include "vehicle_service_global_variables.h"
#include "diag_info.h"

//Diag interface
extern void Set_sDiagInfo(tDiagInfo LocalVarInWrapper);
extern tDiagInfo Get_sDiagInfo(void);

// extern tHandshakeManager Get_sHandshakeManager(void);

#endif