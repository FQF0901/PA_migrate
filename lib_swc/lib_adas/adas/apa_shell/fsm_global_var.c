#include "fsm_global_var.h"
#define CtrlPara_START_SEC_VAR
#include "proj_MemMap.h"

// input
tRelatedModuleInfo g_sRelatedModuleInfo;
// tDiagInfo g_sDiagInfo;

// common_condition output
tVehCommon g_sVehCommon;
tPaStateCommon g_sPaStateCommon;
tRaStateCommon g_sRaStateCommon;
tHpaStateCommon g_sHpaStateCommon;

// master_lsad_fsm output
tMasterLsadFsm g_sMasterLsadFsm;

#define CtrlPara_STOP_SEC_VAR
#include "proj_MemMap.h"

