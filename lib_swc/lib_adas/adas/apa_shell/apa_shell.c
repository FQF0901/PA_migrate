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
#include "emos_rte.h"

extern tHandshakeManager                 g_sHandshakeManager;
extern tCtrlCommonInfo                   g_stCtrlCommonInfo;
extern tCtrlToChassisInfo          		 g_stCtrlToChassisInfo;

void SetAPAShellCoreInput(void)
{
/*	=====================================================================
    *			Prepare the input signals for APA shell state machine 
    *	===================================================================*/
  	#define CtrlPara_START_SEC_VAR		// Memory allocation
	#include "proj_MemMap.h"

	Std_ReturnType    			rtn = E_NOT_OK;
	tAPA_CtrlSts      			eEM_CtrlStatus;
	static tMsgMnger_PDC     	stMsgMngerPdc;         // static, otherwise it will occupy too many stack space. Uss need to reduce reservation volume. 
    static tUSH_UsSysInfo       stmsgMnger_UsSysInfo;  // static, otherwise it will occupy too many stack space. Uss need to reduce reservation volume.
	// tMsgMnger_DataFusion 		stMsgMnger_DataFusion;
	tPecpPLDInfo 				stMsgMnger_PeceptionPld;
	tMsgMnger_LocSts			stMsgMnger_LocSts;
	tMsgMnger_MapCreatorSts		stMsgMnger_MapCreatorSts;
	tMsgMnger_PosSts			stMsgMnger_PosSts;
	tMsgMnger_PathPlanner 		stMsgMnger_PathPlanner;
	tMsgMnger_Tactical 			stMsgMnger_Tactical;
	tVehi_VehicleDataTx 		stVehi_VehicleDataTx;
	// input info
	tRelatedModuleInfo 			stRelatedModuleInfo;
	tAPA_CtrlReqStatus          stAPA_CtrlReqStatus;

	#define CtrlPara_STOP_SEC_VAR	// Memory allocation end.
	#include "proj_MemMap.h"

	(void)Rte_Read_CTRL2SM(&eEM_CtrlStatus);
	(void)Rte_Read_CTRL2SM_ReqStatus(&stAPA_CtrlReqStatus);
	(void)Rte_Read_MsgManager_PDC(&stMsgMngerPdc);
	(void)Rte_Read_USH_UsSysInfo(&stmsgMnger_UsSysInfo);
	(void)Rte_Read_MsgManager_SOC2MCU_LocSts(&stMsgMnger_LocSts);
	(void)Rte_Read_MsgManager_SOC2MCU_MapCreator(&stMsgMnger_MapCreatorSts);
	(void)Rte_Read_MsgManager_SOC2MCU_PosSts(&stMsgMnger_PosSts);
	(void)Rte_Read_MsgManager_PathPlanner(&stMsgMnger_PathPlanner);
	// (void)Rte_Read_MsgManager_DataFusion(&stMsgMnger_DataFusion);
	(void) Rte_Read_MsgManager_PeceptionPld(&stMsgMnger_PeceptionPld);
	(void)Rte_Read_CTRL2CHASSIS(&stVehi_VehicleDataTx);
	(void)Rte_Read_MsgManager_Tactical(&stMsgMnger_Tactical);


	/*=========================== Module signals   ==========================*/
	memset(&stRelatedModuleInfo, 0, sizeof(tRelatedModuleInfo));
	#if ADAS_TEST_ROAD_SWITCH  //for test road
		stRelatedModuleInfo.ePathPlanSts = APA_PATH_PLAN_SUCCESS; 
		stRelatedModuleInfo.eCtrlSts = eEM_CtrlStatus;
		stRelatedModuleInfo.eUltrasonicSts = APA_US_STS_SUCCESS;
		stRelatedModuleInfo.eHandshakeSts =LSAD_APA_HANDSHAKE_EXECUTE_SUCCESS;
		stRelatedModuleInfo.eLocSts = LOC_STATUS_SUCCESS;
		stRelatedModuleInfo.eDataFusionSts = APA_DF_BERTH;
		stRelatedModuleInfo.eUssSupportActive = SUPPORT;
		stRelatedModuleInfo.eMappingSts = MAPCREATOR_STATE_READY;
		stRelatedModuleInfo.eHandshakeFailReason = NO_FAILCODE;
		stRelatedModuleInfo.eHandshakeType = HANDSHAKE_LOW_SPEED;
		stRelatedModuleInfo.eHandshakeTypeReq = HANDSHAKE_RQ_LOW_SPEED;
		stRelatedModuleInfo.eHandshakeGearReq = VEHI_GEAR_INVALID;
		stRelatedModuleInfo.f32RARecordedDist = stMsgMnger_PosSts.record_distance;
		stRelatedModuleInfo.f32CtrlReqStopDistance = g_stCtrlToChassisInfo.f32CtrlReqStopDistance;
		stRelatedModuleInfo.u8VehicleActionRequest = 
						stMsgMnger_PathPlanner.stPathPlanData.u8VehicleActionRequest;
		
		stRelatedModuleInfo.u8ParkoutDir = 0;
	#else
		stRelatedModuleInfo.ePathPlanSts = stMsgMnger_PathPlanner.eApaPathPlanSts; 
		stRelatedModuleInfo.eCtrlSts = eEM_CtrlStatus;
		stRelatedModuleInfo.eUltrasonicSts = stMsgMngerPdc.eApaPdcSts;
		stRelatedModuleInfo.eHandshakeSts = g_sHandshakeManager.eHandshakeSts;
		stRelatedModuleInfo.eHandshakeType = g_sHandshakeManager.eHandshakeType;
		stRelatedModuleInfo.eHandshakeTypeReq = stVehi_VehicleDataTx.eHandshakeReq;
		stRelatedModuleInfo.eHandshakeFailReason = g_sHandshakeManager.eHandshakeFailReason;
		stRelatedModuleInfo.eLocSts = (ELocStatus)stMsgMnger_LocSts.loc_status;
		stRelatedModuleInfo.eDataFusionSts = stMsgMnger_PeceptionPld.eApaDataFusionSts;
		stRelatedModuleInfo.eUssSupportActive = stmsgMnger_UsSysInfo.UsSupportScenes.UsSupportApaActive;
		stRelatedModuleInfo.eHandshakeGearReq = stVehi_VehicleDataTx.eGearReq;
		stRelatedModuleInfo.eMappingSts = (EMapCreatorState)stMsgMnger_MapCreatorSts.mapping_state;
		stRelatedModuleInfo.eCtrlFailReason = stAPA_CtrlReqStatus.eCtrlFailReason;
		stRelatedModuleInfo.f32RARecordedDist = stMsgMnger_PosSts.record_distance;
		stRelatedModuleInfo.f32CtrlReqStopDistance = g_stCtrlToChassisInfo.f32CtrlReqStopDistance;
		stRelatedModuleInfo.f32X_Coor = g_stCtrlVehPose.stCurrentPos.f32X_Coor;
		stRelatedModuleInfo.f32Y_Coor = g_stCtrlVehPose.stCurrentPos.f32Y_Coor;
		stRelatedModuleInfo.f32Theta = g_stCtrlVehPose.stCurrentPos.f32Theta;
		stRelatedModuleInfo.u8VehicleActionRequest = 
						stMsgMnger_PathPlanner.stPathPlanData.u8VehicleActionRequest;
		stRelatedModuleInfo.u8ParkoutDir = stMsgMnger_Tactical.u16ParkoutDirecAvailable;
		stRelatedModuleInfo.u8StatusParkin = stMsgMnger_Tactical.u8StatusParkin;
		stRelatedModuleInfo.u8VehicleActionReason = 
						stMsgMnger_PathPlanner.stPathPlanData.u8VehicleActionReason;
		stRelatedModuleInfo.u8SceneType = 
						stMsgMnger_PathPlanner.stPathPlanData.u8SceneType;
		stRelatedModuleInfo.u8ReqPause = stAPA_CtrlReqStatus.u8ReqPause;
	#endif
	Set_sRelatedModuleInfo(stRelatedModuleInfo);
}

void SetMsgMnger_TextDisp(void)
{
  	#define CtrlPara_START_SEC_VAR		// Memory allocation
	#include "proj_MemMap.h"
	tMsgMnger_TextDisp 			stMsgMnger_TextDisp;
	#define CtrlPara_STOP_SEC_VAR	// Memory allocation end.
	#include "proj_MemMap.h"

	memset(&stMsgMnger_TextDisp, 0, sizeof(tMsgMnger_TextDisp));
    stMsgMnger_TextDisp = Get_sMsgMnger_TextDisp();
    stMsgMnger_TextDisp.u64Timestamp_us = SysTm_GetUnixTimestamp_us();
    Rte_Write_MsgManager_MCUHMITextDisp(&stMsgMnger_TextDisp);
}

void DragPLTest(void)
{
	DragParkingLot MsgMnger_DragPL;
	memset(&MsgMnger_DragPL, 0, sizeof(DragParkingLot));
	// Horizontal pose
	// MsgMnger_DragPL.u64Timestamp = SysTm_GetUnixTimestamp_us();
	// MsgMnger_DragPL.u8PoseOrPoints = 0U;
	// MsgMnger_DragPL.type = 1U;
	// MsgMnger_DragPL.stPose.point.x = (float32)0.0;
	// MsgMnger_DragPL.stPose.point.y = (float32)3.0;
	// MsgMnger_DragPL.stPose.theta = (float32)0.0;
	// MsgMnger_DragPL.width = (float32)6.0;
	// MsgMnger_DragPL.depth = (float32)2.5;

	// Vertical pose
	// MsgMnger_DragPL.u64Timestamp = SysTm_GetUnixTimestamp_us();
	// MsgMnger_DragPL.u8PoseOrPoints = 0U;
	// MsgMnger_DragPL.type = 1U;
	// MsgMnger_DragPL.stPose.point.x = (float32)0.0;
	// MsgMnger_DragPL.stPose.point.y = (float32)5.0;
	// MsgMnger_DragPL.stPose.theta = (float32)0.0;
	// MsgMnger_DragPL.width = (float32)2.5;
	// MsgMnger_DragPL.depth = (float32)6.0;

	// Horizontal point
	MsgMnger_DragPL.u64Timestamp = SysTm_GetUnixTimestamp_us();
	MsgMnger_DragPL.u8PoseOrPoints = 1U; //point
	MsgMnger_DragPL.type = 1U;
	MsgMnger_DragPL.stPoints[0].x = (float32)6.0;
	MsgMnger_DragPL.stPoints[0].y = (float32)0.0;
	MsgMnger_DragPL.stPoints[1].x = (float32)0.0;
	MsgMnger_DragPL.stPoints[1].y = (float32)0.0;
	MsgMnger_DragPL.stPoints[2].x = (float32)0.0;
	MsgMnger_DragPL.stPoints[2].y = (float32)2.5;
	MsgMnger_DragPL.stPoints[3].x = (float32)6.0;
	MsgMnger_DragPL.stPoints[3].y = (float32)2.5;

	Rte_Write_MsgManager_DragPL(&MsgMnger_DragPL);
}

Std_ReturnType APA_ShellInit(void)
{
	lsad_fsm_adapter_initialize();
	lsad_fsm_core_initialize();
	return E_OK;
}

Std_ReturnType APA_ShellStep(void)
{
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
    if (0 == stCalibPF_ptr->stAdasSystemConfig.Calib_ADAS_APASHELL_SWITCH)
    {
        return E_OK;
    }
	/*	=====================================================================
    *			Prepare the input signals for APA shell state machine 
    *	===================================================================*/
    SetAPAShellAdapterInput();
	SetAPAShellCoreInput();
    /*	=====================================================================
    *				 LSAD(APA) FSM running and send out results.
    *	===================================================================*/
    lsad_fsm_adapter_step();
    lsad_fsm_core_step();
    /*	=====================================================================
    *				 LSAD(APA) FSM send out results.
    *	===================================================================*/
	SetMsgManager_ApaState();
	SetMsgMnger_TextDisp();

	return E_OK;
}