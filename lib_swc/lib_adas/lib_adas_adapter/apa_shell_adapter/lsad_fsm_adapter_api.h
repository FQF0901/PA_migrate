#ifndef RTW_HEADER_lsad_fsm_adapter_api_h_
#define RTW_HEADER_lsad_fsm_adapter_api_h_
#include "fsm_adapter_global_var.h"
#include "vehicle_service_global_variables.h"
#include "wrapper_api.h"

// input
extern tMsgMnger_PathSegment Get_sPathSegment(void);
extern void Set_sPathSegment(tMsgMnger_PathSegment LocalIntfacVarInMdl);

extern void Set_sMsgMnger_Hmi(tMsgMnger_Hmi LocalIntfacVarInMdl);
extern tMsgMnger_Hmi Get_sMsgMnger_Hmi(void);

extern void Set_sPecpPLDInfo(tPecpPLDInfo LocalIntfacVarInMdl);
extern tPecpPLDInfo Get_sPecpPLDInfo(void);

// hmi_data_rx output
extern void Set_sPAHmiRx(tPAHmiRx LocalIntfacVarInMdl);
extern tPAHmiRx Get_sPAHmiRx(void);

extern void Set_sRAHmiRx(tRAHmiRx LocalIntfacVarInMdl);
extern tRAHmiRx Get_sRAHmiRx(void);

extern void Set_sHPAHmiRx(tHPAHmiRx LocalIntfacVarInMdl);
extern tHPAHmiRx Get_sHPAHmiRx(void);

// common_condition adapter output
extern void Set_sPaStateAdptr(tPaStateAdptr LocalIntfacVarInMdl);
extern tPaStateAdptr Get_sPaStateAdptr(void);

// slave_lsad_fsm output
extern void Set_sSlaveLsadFsm(tSlaveLsadFsm LocalIntfacVarInMdl);
extern tSlaveLsadFsm Get_sSlaveLsadFsm(void);

// hmi_interactive output
extern void Set_sHMIComDisp(tHMIComDisp LocalIntfacVarInMdl);
extern tHMIComDisp Get_sHMIComDisp(void);

extern void Set_sMsgMnger_TextDisp(tMsgMnger_TextDisp LocalIntfacVarInMdl);
extern tMsgMnger_TextDisp Get_sMsgMnger_TextDisp(void);

extern void Set_sFusionDisp(tFusionDisp LocalIntfacVarInMdl);
extern tFusionDisp Get_sFusionDisp(void);

extern void Set_sDragParkingLot(DragParkingLot LocalIntfacVarInMdl);
extern DragParkingLot Get_sDragParkingLot(void);

// hmi output
extern void Set_sPADispTx(tPADispTx LocalIntfacVarInMdl);
extern tPADispTx Get_sPADispTx(void);

extern void Set_sPrkInSlotTx(tPrkInSlotTx LocalIntfacVarInMdl);
extern tPrkInSlotTx Get_sPrkInSlotTx(void);

#endif