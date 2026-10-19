#ifndef VS_PARA_DEFINATION_H_
#define VS_PARA_DEFINATION_H_

#include "vehsrv_enum.h"
#include "vehsrv_struct.h"

extern tVehsrvInputInfo          g_stVehsrvInput;
extern tMsgMnger_ApaState        g_stVehsrvRecApaShellInfo;	
// extern tCtrl2Vehsrv              g_stCtrl2VehsrvData;	

extern tVehsrvProsessInfo        g_stVehsrvProsess;

extern tVehsrvOutputInfo         g_stVehsrvOutput;	
extern tVehsrv2Ctrl              g_stVehsrv2CtrlData;
extern tVehi_VehicleDataTx       g_stVehsrv2VehiData;

uint8_t VehsrvAllGlobalParaInit(void);

#endif /*VS_PARA_DEFINATION_H_*/
