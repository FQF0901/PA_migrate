#include "lsad_fsm_adapter_api.h"

// input
inline tMsgMnger_PathSegment Get_sPathSegment(void)
{
    return g_sPathSegment;
}
inline void Set_sPathSegment(tMsgMnger_PathSegment LocalIntfacVarInMdl)
{
    g_sPathSegment = LocalIntfacVarInMdl;
    return;
}

inline void Set_sMsgMnger_Hmi(tMsgMnger_Hmi LocalIntfacVarInMdl)
{
    g_sMsgMnger_Hmi = LocalIntfacVarInMdl;
    return;
}
inline tMsgMnger_Hmi Get_sMsgMnger_Hmi(void)
{
    return g_sMsgMnger_Hmi;
}

inline void Set_sPecpPLDInfo(tPecpPLDInfo LocalIntfacVarInMdl)
{
    g_sPecpPLDInfo = LocalIntfacVarInMdl;
    return;
}
inline tPecpPLDInfo Get_sPecpPLDInfo(void)
{
    return g_sPecpPLDInfo;
}

// hmi_data_rx output
inline void Set_sPAHmiRx(tPAHmiRx LocalIntfacVarInMdl)
{
    g_sPAHmiRx = LocalIntfacVarInMdl;
    return;
}
inline tPAHmiRx Get_sPAHmiRx(void)
{
    return g_sPAHmiRx;
}

inline void Set_sRAHmiRx(tRAHmiRx LocalIntfacVarInMdl)
{
    g_sRAHmiRx = LocalIntfacVarInMdl;
    return;
}
inline tRAHmiRx Get_sRAHmiRx(void)
{
    return g_sRAHmiRx;
}

inline void Set_sHPAHmiRx(tHPAHmiRx LocalIntfacVarInMdl)
{
    g_sHPAHmiRx = LocalIntfacVarInMdl;
    return;
}
inline tHPAHmiRx Get_sHPAHmiRx(void)
{
    return g_sHPAHmiRx;
}

// common_condition adapter output
inline void Set_sPaStateAdptr(tPaStateAdptr LocalIntfacVarInMdl)
{
    g_sPaStateAdptr = LocalIntfacVarInMdl;
    return;
}
inline tPaStateAdptr Get_sPaStateAdptr(void)
{
    return g_sPaStateAdptr;
}

// slave_lsad_fsm output
inline void Set_sSlaveLsadFsm(tSlaveLsadFsm LocalIntfacVarInMdl)
{
    g_sSlaveLsadFsm = LocalIntfacVarInMdl;
    return;
}

inline tSlaveLsadFsm Get_sSlaveLsadFsm(void)
{
    return g_sSlaveLsadFsm;
}

// hmi_interactive output
inline void Set_sHMIComDisp(tHMIComDisp LocalIntfacVarInMdl)
{
    g_sHMIComDisp = LocalIntfacVarInMdl;
    return;
}

inline tHMIComDisp Get_sHMIComDisp(void)
{
    return g_sHMIComDisp;
}

inline void Set_sMsgMnger_TextDisp(tMsgMnger_TextDisp LocalIntfacVarInMdl)
{
    g_sMsgMnger_TextDisp = LocalIntfacVarInMdl;
    return;
}

inline tMsgMnger_TextDisp Get_sMsgMnger_TextDisp(void)
{
    return g_sMsgMnger_TextDisp;
}

inline void Set_sFusionDisp(tFusionDisp LocalIntfacVarInMdl)
{
    g_sFusionDisp = LocalIntfacVarInMdl;
    return;
}

inline tFusionDisp Get_sFusionDisp(void)
{
     return g_sFusionDisp;
}

inline void Set_sDragParkingLot(DragParkingLot LocalIntfacVarInMdl)
{
    g_sDragParkingLot = LocalIntfacVarInMdl;
    return;
}

inline DragParkingLot Get_sDragParkingLot(void)
{
     return g_sDragParkingLot;
}

// hmi output
inline void Set_sPADispTx(tPADispTx LocalIntfacVarInMdl)
{
    g_sPADispTx = LocalIntfacVarInMdl;
    return;
}

inline tPADispTx Get_sPADispTx(void){
    return g_sPADispTx;
}

inline void Set_sPrkInSlotTx(tPrkInSlotTx LocalIntfacVarInMdl)
{
    g_sPrkInSlotTx = LocalIntfacVarInMdl;
    return;
}

inline tPrkInSlotTx Get_sPrkInSlotTx(void)
{
    return g_sPrkInSlotTx;
}
