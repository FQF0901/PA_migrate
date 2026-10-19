#include "diag_info.h"

#define DIAG_ITEM_START 0
#define DIAG_ITEM_END 243

void SendDiagInfo2APP(void)
{
	tDiagInfo Local_sDiagInfo;
	memset(&Local_sDiagInfo, 0, sizeof(tDiagInfo));
	uint8 Local_ReturnValue = 0;
	uint8 Local_EventStatus = 0;
	boolean local_DiagData[DIAG_ITEM_END] = {false};
	memset(&local_DiagData, false, sizeof(local_DiagData[DIAG_ITEM_END]));
	for(uint16 i = DIAG_ITEM_START; i <= DIAG_ITEM_END; i++)
    {
        uint8 Local_ReturnValue = 0;
		uint8 Local_EventStatus = 0;
		Local_ReturnValue = DM_Dem_SlaveGetEventStatus(i, &Local_EventStatus);
		if ((2 == Local_ReturnValue) && (1 == Local_EventStatus))
		{
			local_DiagData[i] = true;
		}
        else
		{
			local_DiagData[i] = false;
		}
	}
	// bCameraSrvFail
	for(uint16 m = 1; m <= 12; m++)
	{
		if (local_DiagData[m])
		{
			Local_sDiagInfo.bCameraSrvFail = true;
			Local_sDiagInfo.bPASysFail = true;
			break;
		}
	}
	// bPlfmFail v4.0.7not support,v4.0.9support
	// for(uint16 m = 13; m <= 45; m++)
	// {
	// 	if (local_DiagData[m])
	// 	{
	// 		Local_sDiagInfo.bPlfmFail = true;
	// 		Local_sDiagInfo.bPASysFail = true;
	// 		break;
	// 	}
	// }
	// if (local_DiagData[243])
	// {
	// 	Local_sDiagInfo.bPlfmFail = true;
	// 	Local_sDiagInfo.bPASysFail = true;
	// }
	// bTsSrvFail
	for(uint16 m = 64; m <= 66; m++)
	{
		if (local_DiagData[m])
		{
			Local_sDiagInfo.bTsSrvFail = true;
			Local_sDiagInfo.bPASysFail = true;
			break;
		}
	}
	// bMcuBswFail
	for(uint16 m = 107; m <= 137; m++)
	{
		if (local_DiagData[m])
		{
			Local_sDiagInfo.bMcuBswFail = true;
			Local_sDiagInfo.bPASysFail = true;
			break;
		}
	}
	// bMcuLogFail
	for(uint16 m = 138; m <= 153; m++)
	{
		if (local_DiagData[m])
		{
			Local_sDiagInfo.bMcuLogFail = true;
			Local_sDiagInfo.bPASysFail = true;
			break;
		}
	}
	// bUssFail
	for(uint16 m = 154; m <= 240; m++)
	{
		if (local_DiagData[m])
		{
			Local_sDiagInfo.bUssFail = true;
			Local_sDiagInfo.bPASysFail = true;
			break;
		}
	}
	// bVisionFail
	for(uint16 m = 241; m <= 242; m++)
	{
		if (local_DiagData[m])
		{
			Local_sDiagInfo.bVisionFail = true;
			Local_sDiagInfo.bPASysFail = true;
			break;
		}
	}

	Set_sDiagInfo(Local_sDiagInfo);
}
