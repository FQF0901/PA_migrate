#ifndef RTW_HEADER_fsm_global_var_h_
#define RTW_HEADER_fsm_global_var_h_
#include "hmi_data_rx_type.h"
#include "common_condition_type.h"
#include "hmi_interactive_type.h"
#include "lsad_fsm_core_type.h"
#include "emos_rte.h"
#include "adas_struct.h"
#include "master_lsad_fsm_type.h"
#include "common_condition_adapter_type.h"
#include "slave_lsad_fsm_type.h"
#include "vehicle_service_global_variables.h"
#include "hmi_output_type.h"
#include "rte.h"

// input
extern tRelatedModuleInfo g_sRelatedModuleInfo;
// extern tDiagInfo g_sDiagInfo;

// common_condition output
extern tVehCommon g_sVehCommon;
extern tPaStateCommon g_sPaStateCommon;
extern tRaStateCommon g_sRaStateCommon;
extern tHpaStateCommon g_sHpaStateCommon;

// master_lsad_fsm output
extern tMasterLsadFsm g_sMasterLsadFsm;

#endif 