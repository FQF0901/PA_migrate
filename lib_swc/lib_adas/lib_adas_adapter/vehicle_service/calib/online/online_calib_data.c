#include "online_calib_data.h"

///*	=====================================================================
//*						     Global Val Define
//*	===================================================================*/
#define CtrlPara_START_SEC_VAR		// Memory allocation
#include "proj_MemMap.h"

tMsgMnger_CalibData        g_stCalibSoc2McuData = {0};
tMsgMnger_CalibData        g_stCalibMcu2SocData = {0};

#define CtrlPara_STOP_SEC_VAR	// Memory allocation end.
#include "proj_MemMap.h"