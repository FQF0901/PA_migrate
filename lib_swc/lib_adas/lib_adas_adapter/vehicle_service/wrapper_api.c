#include "wrapper_api.h"

//Diag interface
inline void Set_sDiagInfo(tDiagInfo LocalVarInWrapper){
    g_sDiagInfo = LocalVarInWrapper;
    return;
}

inline tDiagInfo Get_sDiagInfo(void){
    return g_sDiagInfo;
}

inline tHandshakeManager Get_sHandshakeManager(void)
{
    return g_sHandshakeManager;
}
