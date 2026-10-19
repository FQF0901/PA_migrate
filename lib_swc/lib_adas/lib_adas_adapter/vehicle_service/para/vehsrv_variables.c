#include "vehsrv_variables.h"

#define CtrlPara_START_SEC_VAR		// Memory allocation
#include "proj_MemMap.h"

/*	=====================================================================
*						        Input
*	===================================================================*/

tVehsrvInputInfo          g_stVehsrvInput;
tMsgMnger_ApaState        g_stVehsrvRecApaShellInfo;
// tCtrl2Vehsrv              g_stCtrl2VehsrvData;

/*	=====================================================================
*						        Common
*	===================================================================*/

tVehsrvProsessInfo        g_stVehsrvProsess;

/*	=====================================================================
*						        Output
*	===================================================================*/

tVehsrvOutputInfo         g_stVehsrvOutput;	

tVehsrv2Ctrl              g_stVehsrv2CtrlData;
tVehi_VehicleDataTx       g_stVehsrv2VehiData;

#define CtrlPara_STOP_SEC_VAR	// Memory allocation end.
#include "proj_MemMap.h"
