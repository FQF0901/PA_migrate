#include "fsm_adapter_global_var.h"
#define CtrlPara_START_SEC_VAR
#include "proj_MemMap.h"

// input
tMsgMnger_PathSegment g_sPathSegment;
tMsgMnger_Hmi g_sMsgMnger_Hmi;
tPecpPLDInfo g_sPecpPLDInfo;

// hmi_data_rx output
tPAHmiRx g_sPAHmiRx;
tRAHmiRx g_sRAHmiRx;
tHPAHmiRx g_sHPAHmiRx;

// common_condition adapter output
tPaStateAdptr g_sPaStateAdptr;

// slave_lsad_fsm output
tSlaveLsadFsm g_sSlaveLsadFsm;

// hmi_interactive output
tHMIComDisp g_sHMIComDisp;
tMsgMnger_TextDisp g_sMsgMnger_TextDisp;
tFusionDisp g_sFusionDisp;
DragParkingLot g_sDragParkingLot;

// hmi output
tPADispTx g_sPADispTx;
tPrkInSlotTx g_sPrkInSlotTx;

#define CtrlPara_STOP_SEC_VAR
#include "proj_MemMap.h"



