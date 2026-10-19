#include "lsad_fsm_api.h"

// input
inline tVehDataRx Get_sVehDataRx(void)
{
    tVehDataRx temp_g_sVehDataRx;
    Rte_Read_MsgManager_APPVehData(&temp_g_sVehDataRx);
    return temp_g_sVehDataRx;
}

inline void Set_sRelatedModuleInfo(tRelatedModuleInfo LocalIntfacVarInMdl)
{
    g_sRelatedModuleInfo = LocalIntfacVarInMdl;
    return;
}
inline tRelatedModuleInfo Get_sRelatedModuleInfo(void)
{
    return g_sRelatedModuleInfo;
}

// common_condition output
inline void Set_sVehCommon(tVehCommon LocalIntfacVarInMdl)
{
    g_sVehCommon = LocalIntfacVarInMdl;
    return;
}
inline tVehCommon Get_sVehCommon(void)
{
    return g_sVehCommon;
}

inline void Set_sPaStateCommon(tPaStateCommon LocalIntfacVarInMdl)
{
    g_sPaStateCommon = LocalIntfacVarInMdl;
    return;
}
inline tPaStateCommon Get_sPaStateCommon(void)
{
    return g_sPaStateCommon;
}

inline void Set_sRaStateCommon(tRaStateCommon LocalIntfacVarInMdl)
{
    g_sRaStateCommon = LocalIntfacVarInMdl;
    return;
}
inline tRaStateCommon Get_sRaStateCommon(void)
{
    return g_sRaStateCommon;
}

inline void Set_sHpaStateCommon(tHpaStateCommon LocalIntfacVarInMdl)
{
    g_sHpaStateCommon = LocalIntfacVarInMdl;
    return;
}
inline tHpaStateCommon Get_sHpaStateCommon(void)
{
    return g_sHpaStateCommon;
}

// lsad_fsm_core output
inline void Set_sMasterLsadFsm(tMasterLsadFsm LocalIntfacVarInMdl)
{
    g_sMasterLsadFsm = LocalIntfacVarInMdl;
    return;
}

inline tMasterLsadFsm Get_sMasterLsadFsm(void)
{
    return g_sMasterLsadFsm;
}
