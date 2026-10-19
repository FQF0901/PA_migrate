// #include "IfxCpu.h"
#include "apa_shell.h"
#include "apa_shell_adapter.h"
#include "lsad_fsm_core.h"
#include "lsad_fsm_adapter.h"
#include "ctrl_global_variables.h"
#include "msg_manager.h"
#include "adas_project_input.h"
#include "adas_calibration_data.h"
#include "vehicle_service/calib/vehsrv_calib.h"
#include "vehicle_service/vehicle_service_global_variables.h"
#include "ctrl_algo/src/ctrl_global_variables.h"
#include "diag_info.h"

void SetAPAShellAdapterInput(void)
{
/*	=====================================================================
    *			Prepare the input signals for APA shell state machine 
    *	===================================================================*/
  	#define CtrlPara_START_SEC_VAR		// Memory allocation
	#include "proj_MemMap.h"

	tGPIO_Info        			tGIPO_Button;
	// input info
	tMsgMnger_Hmi 				stMsgMnger_Hmi;
	tVehi_VehicleDataTx 		stVehi_VehicleDataTx;
	tPecpPLDInfo 				stMsgMnger_PeceptionPld;
	tMsgMnger_PathSegment 		stPathSegment;

	#define CtrlPara_STOP_SEC_VAR	// Memory allocation end.
	#include "proj_MemMap.h"

	(void)Rte_Read_GPIO_INFO(&tGIPO_Button);
	/*=========================== hmi input  ==========================*/
	memset(&stMsgMnger_Hmi, 0, sizeof(tMsgMnger_Hmi));
	(void)Rte_Read_MsgManager_HMI(&stMsgMnger_Hmi); 
	if (1 == tGIPO_Button.u8key_continue_info) 
	{
		stMsgMnger_Hmi.HmiStsReq = (uint8)HMI_STS_EOL_START;
	} // eol button
	Set_sMsgMnger_Hmi(stMsgMnger_Hmi);
	/*=========================== pld input  ==========================*/
	memset(&stMsgMnger_PeceptionPld, 0, sizeof(tPecpPLDInfo));
	Rte_Read_MsgManager_PeceptionPld(&stMsgMnger_PeceptionPld);  
	Set_sPecpPLDInfo(stMsgMnger_PeceptionPld);
	/*=========================== pp info  ==========================*/
	memset(&stPathSegment , 0, sizeof(tMsgMnger_PathSegment));
	Rte_Read_MsgManager_PathSegment(&stPathSegment);  
	Set_sPathSegment(stPathSegment);

	/*=========================== diag info  ==========================*/
	SendDiagInfo2APP();
}

void SetMsgManager_ApaState(void)
{
  	#define CtrlPara_START_SEC_VAR		// Memory allocation
	#include "proj_MemMap.h"
	tMsgMnger_ApaState 			msgMnger_ApaState;
	tMasterLsadFsm 				stMasterLsadFsm; 
	tSlaveLsadFsm 				stSlaveLsadFsm; 
    uint8 						u8SelectedBrethID;
	#define CtrlPara_STOP_SEC_VAR	// Memory allocation end.
	#include "proj_MemMap.h"

	memset(&msgMnger_ApaState, 0, sizeof(tMsgMnger_ApaState));
    Rte_Read_SelectedBerthId(&u8SelectedBrethID);   //ʹ��EMsim�Ŀ�λ
	//u8SelectedBrethID = Get_sHMIComDisp().u8DrvrSelSlotID; //ʹ�ô���ѡ��Ŀ�λ
    stMasterLsadFsm = Get_sMasterLsadFsm();
	stSlaveLsadFsm = Get_sSlaveLsadFsm();
    msgMnger_ApaState.u64Timestamp_us = SysTm_GetUnixTimestamp_us();
    msgMnger_ApaState.eLsadSystemSts = stMasterLsadFsm.eLsadSystemSts;
    msgMnger_ApaState.eLsadSystemSubSts = LSAD_SUBSTS_NONE;
	msgMnger_ApaState.u8LsadFuncSts = (uint8)stSlaveLsadFsm.eLsadFuncSts;
	msgMnger_ApaState.u8BckgrndSearchSts = (uint8)stSlaveLsadFsm.eBckgrndSearchSts;
	msgMnger_ApaState.u8BckgrndCruiseReadySts = (uint8)stSlaveLsadFsm.eBckgrndCruiseReadySts;
	msgMnger_ApaState.u8BckgrndRecordSts = (uint8)stSlaveLsadFsm.eBckgrndRecordSts;
    msgMnger_ApaState.u8SelectedBerthId = u8SelectedBrethID;
    msgMnger_ApaState.u8LsadFuncType = (uint8)stSlaveLsadFsm.eLsadFuncType;
    msgMnger_ApaState.u8DriverCtrlCommand = (uint8)stSlaveLsadFsm.eDriverCtrlCommand;
	msgMnger_ApaState.u8LsadStSResetPEB = (uint8)stSlaveLsadFsm.u8LsadStSResetPEB;
    Rte_Write_MsgManager_ApaState(&msgMnger_ApaState);
}