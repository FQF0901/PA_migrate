#ifndef RTW_HEADER_fsm_adapter_global_var_h_
#define RTW_HEADER_fsm_adapter_global_var_h_
#include "hmi_data_rx_type.h"
#include "common_condition_type.h"
#include "hmi_interactive_type.h"
#include "hmi_output_type.h"
#include "lsad_fsm_core_type.h"
#include "emos_rte.h"
#include "adas_struct.h"
#include "master_lsad_fsm_type.h"
#include "common_condition_adapter_type.h"
#include "slave_lsad_fsm_type.h"
#include "vehicle_service_global_variables.h"
#include "rte.h"
#include "em_interchip_msg.h"

// input
extern tMsgMnger_PathSegment g_sPathSegment;
extern tMsgMnger_Hmi g_sMsgMnger_Hmi;
extern tPecpPLDInfo g_sPecpPLDInfo;

// hmi_data_rx output
extern tPAHmiRx g_sPAHmiRx;
extern tRAHmiRx g_sRAHmiRx;
extern tHPAHmiRx g_sHPAHmiRx;

// common_condition adapter output
extern tPaStateAdptr g_sPaStateAdptr;

// slave_lsad_fsm output
extern tSlaveLsadFsm g_sSlaveLsadFsm;

// hmi_interactive output
extern tHMIComDisp g_sHMIComDisp;
extern tMsgMnger_TextDisp g_sMsgMnger_TextDisp;
extern tFusionDisp g_sFusionDisp;
extern DragParkingLot g_sDragParkingLot;

// hmi output
extern tPADispTx g_sPADispTx;
extern tPrkInSlotTx g_sPrkInSlotTx;

#endif



