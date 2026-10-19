#ifndef RTW_HEADER_lsad_fsm_api_h_
#define RTW_HEADER_lsad_fsm_api_h_
#include "fsm_global_var.h"
#include "vehicle_service_global_variables.h"
#include "wrapper_api.h"
#include "fsm_adapter_global_var.h"
#include "lsad_fsm_adapter_api.h"

// input
extern tVehDataRx Get_sVehDataRx(void);

extern void Set_sRelatedModuleInfo(tRelatedModuleInfo LocalIntfacVarInMdl);
extern tRelatedModuleInfo Get_sRelatedModuleInfo(void);

// common_condition output
extern void Set_sVehCommon(tVehCommon LocalIntfacVarInMdl);
extern tVehCommon Get_sVehCommon(void);

extern void Set_sPaStateCommon(tPaStateCommon LocalIntfacVarInMdl);
extern tPaStateCommon Get_sPaStateCommon(void);

extern void Set_sRaStateCommon(tRaStateCommon LocalIntfacVarInMdl);
extern tRaStateCommon Get_sRaStateCommon(void);

extern void Set_sHpaStateCommon(tHpaStateCommon LocalIntfacVarInMdl);
extern tHpaStateCommon Get_sHpaStateCommon(void);

// lsad_fsm_core output
extern void Set_sMasterLsadFsm(tMasterLsadFsm LocalIntfacVarInMdl);
extern tMasterLsadFsm Get_sMasterLsadFsm(void);

#endif