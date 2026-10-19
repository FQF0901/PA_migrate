#include "ctrl_diag.h"
#include "ctrl_global_variables.h"
#include "ctrl_errcode.h"
#include "vehicle_service/calib/vehsrv_calib.h"
#include "adas_project_input.h"
#include "lib_adas_adapter/vehicle_service/ctrl_adapter/ctrl_adapter.h"
#include "lib_adas_adapter/vehicle_service/vehicle_service_global_variables.h"
//#include "wrapper_api.h"
//#include "global_var_api.h"
#include "emos_rte.h"

#define STEER_EXECUTION_CACHE_COUNT  10


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_VehDiagReset_20ms

  * EXPLANATION
This function reset error code struct
*************************************************************************
*/
void Ctrl_VehDiagReset_20ms()
{
    g_stCtrlDiagErrCode.u16ModuleInitErrCode      = 0;
    g_stCtrlDiagErrCode.u16ModuleInputErrCode     = 0;
    g_stCtrlDiagErrCode.u16ModuleOutputErrCode    = 0;
    g_stCtrlDiagErrCode.u16ModuleHandshakeErrCode = 0;
    g_stCtrlDiagErrCode.u16ModuleUserErrCode      = 0;

    g_stCtrlDiagErrCode.u16ModulePebErrCode       = 0;
    g_stCtrlDiagErrCode.u16ModuleDrErrCode        = 0;
    g_stCtrlDiagErrCode.u16ModuleParkErrCode      = 0;
    g_stCtrlDiagErrCode.u16ModuleHeadoutErrCode   = 0;
    g_stCtrlDiagErrCode.u16ModuleCruiseErrCode    = 0;
}

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_VehDiagPrint_20ms

  * EXPLANATION
This function prints ctrl error code
*************************************************************************
*/
void Ctrl_VehDiagPrint_20ms(void)
{
//    if( g_stCtrlDiagErrCode.u16ModuleInitErrCode || g_stCtrlDiagErrCode.u16ModuleInputErrCode ||
//        g_stCtrlDiagErrCode.u16ModuleOutputErrCode || g_stCtrlDiagErrCode.u16ModuleHandshakeErrCode ||
//        g_stCtrlDiagErrCode.u16ModuleUserErrCode || g_stCtrlDiagErrCode.u16ModulePebErrCode ||
//        g_stCtrlDiagErrCode.u16ModuleDrErrCode || g_stCtrlDiagErrCode.u16ModuleParkErrCode ||
//        g_stCtrlDiagErrCode.u16ModuleHeadoutErrCode || g_stCtrlDiagErrCode.u16ModuleCruiseErrCode)
    {
        PRINTF_PF("CtrlErrCode:0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X ",
                g_stCtrlDiagErrCode.u16ModuleInitErrCode, g_stCtrlDiagErrCode.u16ModuleInputErrCode,
                g_stCtrlDiagErrCode.u16ModuleOutputErrCode, g_stCtrlDiagErrCode.u16ModuleHandshakeErrCode,
                g_stCtrlDiagErrCode.u16ModuleUserErrCode, g_stCtrlDiagErrCode.u16ModulePebErrCode,
                g_stCtrlDiagErrCode.u16ModuleDrErrCode, g_stCtrlDiagErrCode.u16ModuleParkErrCode,
                g_stCtrlDiagErrCode.u16ModuleHeadoutErrCode, g_stCtrlDiagErrCode.u16ModuleCruiseErrCode);
        Rte_Write_MsgManager_CTRLERRCODE(&g_stCtrlDiagErrCode);
    }
}

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_VehDiag_20ms

  * EXPLANATION
This function sends log info to soc
*************************************************************************
*/
uint8_t Ctrl_VehDiag_20ms()
{
    tMsgMnger_VehicleInfo     s_MsgMnger_VehicleInfo;
    Rte_Read_MsgManager_VehicleInfo(&s_MsgMnger_VehicleInfo);
    tVehi_VehicleDataTx     msgMnger_ctrl_data;      // To delete, replace with global varibles.
    Rte_Read_CTRL2CHASSIS(&msgMnger_ctrl_data);
    
    tMsgMnger_HPPShakeHands         stMsgMngerHppShakeHands;
    (void)Rte_Read_MsgManager_HPPShake(&stMsgMngerHppShakeHands);   // Han vehicle.


    ST_VEHICLE_HANDSHAKE_INFO s_MsgMnger_VehicleHandshakeInfo;
    Rte_Read_HandShakeInfo(&s_MsgMnger_VehicleHandshakeInfo); 

    tMsgMnger_Tactical 			stMsgMnger_Tactical;    
    (void)Rte_Read_MsgManager_Tactical(&stMsgMnger_Tactical);
    
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();

    /*	=====================================================================
    *						      Public Log
    *	===================================================================*/

    // Public log - Input - From APA Shell & From CAN (occupy 0 ~ 9)
    g_stCtrlLogInfo.f32AdasDebugVal[0] = (float)g_stCtrlFuncFsmInfo.eLsadSystemSts;
    g_stCtrlLogInfo.f32AdasDebugVal[1] = (float)Get_sSlaveLsadFsm().eLsadFuncSts;
    g_stCtrlLogInfo.f32AdasDebugVal[2] = (float)g_stCtrlFuncFsmInfo.eLsadFuncType;
    g_stCtrlLogInfo.f32AdasDebugVal[3] = (float)g_stCtrlFuncFsmInfo.eLsadDriverCtrlCommand;
    g_stCtrlLogInfo.f32AdasDebugVal[4] = (float)g_stCtrlVehDataRx.sVehEPSInfo.f32StrWhlAngDeg;
    g_stCtrlLogInfo.f32AdasDebugVal[5] = (float)g_stCtrlVehDataRx.sVehESCInfo.f32VehSpdKph;
    g_stCtrlLogInfo.f32AdasDebugVal[6] = (float)g_stCtrlVehDataRx.sVehVCUInfo.bBrkPedal;
    g_stCtrlLogInfo.f32AdasDebugVal[7] = (float)g_stCtrlVehDataRx.sVehESCInfo.u16WhlPulRR;
    g_stCtrlLogInfo.f32AdasDebugVal[8] = (float)g_stCtrlVehDataRx.sVehESCInfo.eWhlDirRR;
    g_stCtrlLogInfo.f32AdasDebugVal[9] = (float)g_stCtrlVehDataRx.sVehVCUInfo.eVehActualGear;

    // Public log - Input - From Path Planner Info (occupy 10 ~ 29)
    g_stCtrlLogInfo.f32AdasDebugVal[10] = (float)g_stPathPlannerData.u16TotallyPathNum;
    g_stCtrlLogInfo.f32AdasDebugVal[11] = (float)g_stPathPlannerData.u16PathId;
    g_stCtrlLogInfo.f32AdasDebugVal[12] = (float)g_stPathPlannerData.u8PointNum;
    g_stCtrlLogInfo.f32AdasDebugVal[13] = (float)g_stPathPlannerData.u8Shift;
    g_stCtrlLogInfo.f32AdasDebugVal[14] = (float)g_stPathPlannerData.f32PathLength;     
    g_stCtrlLogInfo.f32AdasDebugVal[15] = (float)g_stPathPlannerData.ePldType;
    g_stCtrlLogInfo.f32AdasDebugVal[16] = (float)g_stPathPlannerData.ePathPlanSts;  // for fsm
    g_stCtrlLogInfo.f32AdasDebugVal[17] = (float)g_stPathPlannerData.u8PlanResult;  // for ctrl, no use, only as reference.
    g_stCtrlLogInfo.f32AdasDebugVal[18] = (float)g_stPathPlannerData.u8PebLevel; 
    g_stCtrlLogInfo.f32AdasDebugVal[19] = (float)g_stPathPlannerData.u8IsTraj; 

    // Public log - Input - From Path Planner Points & From DR (occupy 20 ~ 29)
    g_stCtrlLogInfo.f32AdasDebugVal[20] = (float)g_stPathPlannerData.u8VehicleActionRequest;
    g_stCtrlLogInfo.f32AdasDebugVal[21] = (float)g_stPathPlannerData.u8NewPathFlag;
    //g_stCtrlLogInfo.f32AdasDebugVal[22] = (float)g_stPathPlannerData.u8KappaSuddenChangeFlag;
    g_stCtrlLogInfo.f32AdasDebugVal[22] = (float)stCalibPF_ptr->stAdasSystemConfig.Calib_ADAS_DR_SWITCH;

    // --- Temp, handshake status.
    g_stCtrlLogInfo.f32AdasDebugVal[23] = (float)g_stCtrlVehDataRx.sVehESCInfo.bVehStandStill;
    // --- Temp, handshake status. END
    // --- Identify the vehicle and function.
    g_stCtrlLogInfo.f32AdasDebugVal[24] = (float)EM_VEHI_TYPE;
    g_stCtrlLogInfo.f32AdasDebugVal[25] = (float)g_stCtrlUssInfo.f32TTCPebDistance;
    g_stCtrlLogInfo.f32AdasDebugVal[26] = (float)g_stCalibData.stPFVehCalib.Calib_f32WhlBase;   // MarvelR 2.800 vs. BYDHan 2.920
    // --- Identify the vehicle and function. END

    g_stCtrlLogInfo.f32AdasDebugVal[27] = (float)g_stCtrlVehPose.stCurrentPos.f32X_Coor;
    g_stCtrlLogInfo.f32AdasDebugVal[28] = (float)g_stCtrlVehPose.stCurrentPos.f32Y_Coor;
    g_stCtrlLogInfo.f32AdasDebugVal[29] = (float)g_stCtrlVehPose.stCurrentPos.f32Theta;

    // Public log - Intermediate status - Ctrl SM & Common (occupy 30 ~ 39).  
    g_stCtrlLogInfo.f32AdasDebugVal[30] = (float)g_stCtrlCommonInfo.eCtrlFuncStatus;
    g_stCtrlLogInfo.f32AdasDebugVal[31] = (float)g_stCtrlCommonInfo.eCtrlFuncType;
    g_stCtrlLogInfo.f32AdasDebugVal[32] = (float)g_stCtrlCommonInfo.u8NearestPointIndexCurPose;
    g_stCtrlLogInfo.f32AdasDebugVal[33] = (float)g_stCtrlCommonInfo.f32DistanceLeft; 
    g_stCtrlLogInfo.f32AdasDebugVal[34] = (float)g_stCtrlCommonInfo.stCtrlPebInfo.u8PebHappened;
    g_stCtrlLogInfo.f32AdasDebugVal[35] = (float)g_stCtrlCommonInfo.stCtrlPebInfo.u8PebDir;
    g_stCtrlLogInfo.f32AdasDebugVal[36] = (float)g_stCtrlCommonInfo.eCtrlChockedTypeFlag;
    g_stCtrlLogInfo.f32AdasDebugVal[37] = (float)g_stCtrlCommonInfo.u16CurrentPathID;
    g_stCtrlLogInfo.f32AdasDebugVal[38] = (float)g_stCtrlCommonInfo.eCtrlFinishType;     
    g_stCtrlLogInfo.f32AdasDebugVal[39] = (float)s_MsgMnger_VehicleHandshakeInfo.SCU_APA_Sts; 

    // Public log - Intermediate status - Longitudinal (occupy 40 ~ 49).  
    g_stCtrlLogInfo.f32AdasDebugVal[40] = (float)g_stCtrlLongiInfo.eSpeedPhase;
    g_stCtrlLogInfo.f32AdasDebugVal[41] = (float)g_stCtrlLongiInfo.f32TargetVehSpeed;
    g_stCtrlLogInfo.f32AdasDebugVal[42] = (float)g_stCtrlCommonInfo.stCtrlPebInfo.f32PebSpeed;
    g_stCtrlLogInfo.f32AdasDebugVal[43] = (float)g_stCtrlLongiInfo.f32TargetAcce;
    g_stCtrlLogInfo.f32AdasDebugVal[44] = (float)g_stCtrlLongiInfo.f32TrajTargetAcce;  
    g_stCtrlLogInfo.f32AdasDebugVal[45] = (float)g_stCtrlLongiInfo.f32TargetStopDistance;
    g_stCtrlLogInfo.f32AdasDebugVal[46] = (float)g_stCtrlLongiInfo.u8CurrentPathFinishedFlag;
 	  g_stCtrlLogInfo.f32AdasDebugVal[47] = (float)g_stStateMachine.m_state;            // HPP debug 4.04
    g_stCtrlLogInfo.f32AdasDebugVal[48] = (float)g_stStateMachine.m_ReminDis;   // HPP debug 4.04
    g_stCtrlLogInfo.f32AdasDebugVal[49] = (float)g_stStateMachine.m_SpeedToESC*3.6;  // HPP debug 4.04
    // Public log - Intermediate status - Lateral (occupy 50 ~ 59).  
    g_stCtrlLogInfo.f32AdasDebugVal[50] = (float)g_stCtrlLatInfo.stCtrlLatErr.f32ErrDistRaw;    
    g_stCtrlLogInfo.f32AdasDebugVal[51] = (float)g_stCtrlLatInfo.stCtrlLatErr.f32ErrDistFiltered;
    g_stCtrlLogInfo.f32AdasDebugVal[52] = (float)g_stCtrlLatInfo.stCtrlLatErr.f32ErrThetaRaw;
    g_stCtrlLogInfo.f32AdasDebugVal[53] = (float)g_stCtrlLatInfo.stCtrlLatErr.f32ErrThetaFiltered;
    g_stCtrlLogInfo.f32AdasDebugVal[54] = (float)g_stCtrlLatInfo.stCtrlLatErr.f32SinglePointTargetCurvatureRaw;
    g_stCtrlLogInfo.f32AdasDebugVal[55] = (float)g_stCtrlLatInfo.stCtrlLatErr.f32SinglePointTargetCurvatureFiltered;
    g_stCtrlLogInfo.f32AdasDebugVal[56] = (float)g_stCtrlLatInfo.stCtrlLatResult.f32FeedbackAngleRaw;
    g_stCtrlLogInfo.f32AdasDebugVal[57] = (float)g_stCtrlLatInfo.stCtrlLatResult.f32FeedforwardAngle;
    g_stCtrlLogInfo.f32AdasDebugVal[58] = (float)g_stCtrlLatInfo.stCtrlLatResult.f32TargetSteerAngleRaw;
    g_stCtrlLogInfo.f32AdasDebugVal[59] = (float)g_stCtrlLatInfo.stCtrlLatResult.f32TargetSteerAngleFiltered;

    // Public log - Output to CAN & PP & APA Shell (occupy 60 ~ 69)
    g_stCtrlLogInfo.f32AdasDebugVal[60] = (float)msgMnger_ctrl_data.eGearReq; 
    g_stCtrlLogInfo.f32AdasDebugVal[61] = (float)msgMnger_ctrl_data.f32CtrlReqSpeed;    
    g_stCtrlLogInfo.f32AdasDebugVal[62] = (float)msgMnger_ctrl_data.f32CtrlReqAccel;
    g_stCtrlLogInfo.f32AdasDebugVal[63] = (float)msgMnger_ctrl_data.f32CtrlReqSteer;
    g_stCtrlLogInfo.f32AdasDebugVal[64] = (float)msgMnger_ctrl_data.f32CtrlReqStopDistance;
    g_stCtrlLogInfo.f32AdasDebugVal[65] = (float)g_stCtrlToPathPlannerInfo.u8CtrlState; 
    g_stCtrlLogInfo.f32AdasDebugVal[66] = (float)g_stCtrlToPathPlannerInfo.u8CtrlSubstate; 
    g_stCtrlLogInfo.f32AdasDebugVal[67] = (float)g_stCtrlToPathPlannerInfo.u8PathPEBDir;  
    g_stCtrlLogInfo.f32AdasDebugVal[68] = (float)g_stCtrlToFuncStateMachine.eCtrlStatus;
    g_stCtrlLogInfo.f32AdasDebugVal[69] = (float)g_stCtrlLongiInfo.f32PPTargetVehSpeed;

    // Public log - Output to CAN & PP & APA Shell (occupy 70 ~ 99)


//  PEB Handshake intern stCtrlLatInfo_ptr->stCtrlLatErr.f32SinglePointTargetCurvatureRaw
    g_stCtrlLogInfo.f32AdasDebugVal[70] = (float)g_sHandshakeManager.eHandshakeFailReason;
    g_stCtrlLogInfo.f32AdasDebugVal[71] = (float)g_sHandshakeManager.eHandshakeSts;
    g_stCtrlLogInfo.f32AdasDebugVal[72] = (float)g_stCtrlUssInfo.u8PebUssNumber;
    g_stCtrlLogInfo.f32AdasDebugVal[73] = (float)g_stCtrlUssInfo.f32TTCMinTime;
    g_stCtrlLogInfo.f32AdasDebugVal[74] = (float)g_stCtrlUssInfo.f32UssMinDistance;
    g_stCtrlLogInfo.f32AdasDebugVal[75] = (float)g_stCtrlUssInfo.f32VehCurvature;
    g_stCtrlLogInfo.f32AdasDebugVal[76] = (float)g_stCtrlUssInfo.f32TTCSafetyTime;
    g_stCtrlLogInfo.f32AdasDebugVal[77] = (float)g_stStateMachine.m_AccelToESC;
    g_stCtrlLogInfo.f32AdasDebugVal[78] = (float)g_stCtrlLatInfo.stCtrlLatResult.f32WheelToSteerRatio;
    g_stCtrlLogInfo.f32AdasDebugVal[79] = (float)g_stCtrlCommonInfo.u8RecordedTargetFrontID;

    //Handshake Output    
    g_stCtrlLogInfo.f32AdasDebugVal[80] = (float)g_sActuaSrvTx.sActuaSrvEPSCtrl.APA_Tar_StrAgl;
    g_stCtrlLogInfo.f32AdasDebugVal[81] = (float)g_sActuaSrvTx.sActuaSrvRestTx.APA_MainStas;
    g_stCtrlLogInfo.f32AdasDebugVal[82] = (float)g_sActuaSrvTx.sActuaSrvRestTx.APA_APA_Mode;
    g_stCtrlLogInfo.f32AdasDebugVal[83] = (float)g_sActuaSrvTx.sActuaSrvRestTx.MPC_32E_ACCMode;
    g_stCtrlLogInfo.f32AdasDebugVal[84] = (float)g_sActuaSrvTx.sActuaSrvESCCtrl.APA_StopDistance;
    g_stCtrlLogInfo.f32AdasDebugVal[85] = (float)g_sActuaSrvTx.sActuaSrvESCCtrl.APA_SpeedLimit;
    g_stCtrlLogInfo.f32AdasDebugVal[86] = (float)g_sActuaSrvTx.sActuaSrvESCCtrl.MPC_32E_axvCvAim;
    g_stCtrlLogInfo.f32AdasDebugVal[87] = (float)g_sActuaSrvTx.sActuaSrvESCCtrl.APA_FailureBrakeMode;
    g_stCtrlLogInfo.f32AdasDebugVal[88] = (float)g_sActuaSrvTx.sActuaSrvVCUCtrl.APS_SCU_TargetGearRequest;
    g_stCtrlLogInfo.f32AdasDebugVal[89] = (float)msgMnger_ctrl_data.eAEBFlag;

     //Extern  
    g_stCtrlLogInfo.f32AdasDebugVal[90] = (float)g_sHandshakeManager.eHandshakeType;
    g_stCtrlLogInfo.f32AdasDebugVal[91] = (float)g_stCtrlToChassisInfo.eHandshakeReq;
    g_stCtrlLogInfo.f32AdasDebugVal[92] = (float)s_MsgMnger_VehicleHandshakeInfo.ESC_APA_Sts;
    g_stCtrlLogInfo.f32AdasDebugVal[93] = (float)s_MsgMnger_VehicleHandshakeInfo.EPS_APA_Sts;
    g_stCtrlLogInfo.f32AdasDebugVal[94] = (float)g_stCtrlFuncFsmInfo.u8LsadStSResetPEB;
    g_stCtrlLogInfo.f32AdasDebugVal[95] = (float)g_sActuaSrvTx.sActuaSrvESCCtrl.MPC_32E_ACCDecToStopReq; 
    g_stCtrlLogInfo.f32AdasDebugVal[96] = (float)g_sActuaSrvTx.sActuaSrvESCCtrl.MPC_32E_ACCDriveOffReq; 
    g_stCtrlLogInfo.f32AdasDebugVal[97] = (float)g_stCtrlToFuncStateMachine.stCtrlReqSts.u8ReqPause;
    g_stCtrlLogInfo.f32AdasDebugVal[98] = (float)0.0;
    g_stCtrlLogInfo.f32AdasDebugVal[99] = (float)0.0;   
    g_stCtrlLogInfo.f32AdasDebugVal[100] = (float)0.0;
    
    
    g_stCtrlLogInfo.f32AdasDebugVal[100] = (float)Get_sMasterLsadFsm().eLsadSystemSts;
    g_stCtrlLogInfo.f32AdasDebugVal[101] = (float)Get_sRelatedModuleInfo().eCtrlSts;
    g_stCtrlLogInfo.f32AdasDebugVal[102] = (float)Get_sRelatedModuleInfo().ePathPlanSts;
    g_stCtrlLogInfo.f32AdasDebugVal[103] = (float)Get_sRelatedModuleInfo().eUltrasonicSts;
    g_stCtrlLogInfo.f32AdasDebugVal[104] = (float)Get_sRelatedModuleInfo().eLocSts;
    g_stCtrlLogInfo.f32AdasDebugVal[105] = (float)Get_sRelatedModuleInfo().eDataFusionSts;
    g_stCtrlLogInfo.f32AdasDebugVal[106] = (float)Get_sRelatedModuleInfo().eUssSupportActive;
    g_stCtrlLogInfo.f32AdasDebugVal[107] = (float)Get_sRelatedModuleInfo().eMappingSts;
    g_stCtrlLogInfo.f32AdasDebugVal[108] = (float)Get_sRelatedModuleInfo().eHandshakeSts;
    g_stCtrlLogInfo.f32AdasDebugVal[109] = (float)Get_sRelatedModuleInfo().eHandshakeFailReason;

    g_stCtrlLogInfo.f32AdasDebugVal[110] = (float)Get_sRelatedModuleInfo().eHandshakeType;
    g_stCtrlLogInfo.f32AdasDebugVal[111] = (float)Get_sRelatedModuleInfo().eHandshakeTypeReq;
    g_stCtrlLogInfo.f32AdasDebugVal[112] = (float)Get_sRelatedModuleInfo().eHandshakeGearReq;
    g_stCtrlLogInfo.f32AdasDebugVal[113] = (float)Get_sRelatedModuleInfo().f32RARecordedDist;
    g_stCtrlLogInfo.f32AdasDebugVal[114] = (float)Get_sRelatedModuleInfo().f32CtrlReqStopDistance;
    g_stCtrlLogInfo.f32AdasDebugVal[115] = (float)Get_sRelatedModuleInfo().u8VehicleActionRequest;
    g_stCtrlLogInfo.f32AdasDebugVal[116] = (float)Get_sRelatedModuleInfo().u8ParkoutDir;
    g_stCtrlLogInfo.f32AdasDebugVal[117] = (float)Get_sMsgMnger_Hmi().HmiStsReq;
    g_stCtrlLogInfo.f32AdasDebugVal[118] = (float)Get_sMsgMnger_Hmi().HmiTypeReq;
    g_stCtrlLogInfo.f32AdasDebugVal[119] = (float)Get_sVehDataRx().sVehVCUInfo.eSysPwrMd;

    g_stCtrlLogInfo.f32AdasDebugVal[120] = (float)Get_sVehCommon().sCondiPlatform.bObstAppear;
    g_stCtrlLogInfo.f32AdasDebugVal[121] = (float)Get_sVehCommon().sCondiPlatform.bActvStsNeedRlsBrk;
    g_stCtrlLogInfo.f32AdasDebugVal[122] = (float)Get_sPaStateCommon().sPAEvnt.ePAIntrptEvnt;
    g_stCtrlLogInfo.f32AdasDebugVal[123] = (float)Get_sPaStateCommon().sPAEvnt.ePATrmntEvnt;
    g_stCtrlLogInfo.f32AdasDebugVal[124] = (float)Get_sPaStateCommon().sPAEvnt.ePAFailureEvnt;
    g_stCtrlLogInfo.f32AdasDebugVal[125] = (float)Get_sPaStateCommon().sPAEvnt.ePAInhibitEvnt;
    g_stCtrlLogInfo.f32AdasDebugVal[126] = (float)Get_sPaStateCommon().sPAEvnt.ePAIntrptType;
    g_stCtrlLogInfo.f32AdasDebugVal[127] = (float)Get_sRaStateCommon().sRAEvnt.eRAIntrptEvnt;
    g_stCtrlLogInfo.f32AdasDebugVal[128] = (float)Get_sRaStateCommon().sRAEvnt.eRATrmntEvnt;
    g_stCtrlLogInfo.f32AdasDebugVal[129] = (float)Get_sRaStateCommon().sRAEvnt.eRAFailureEvnt;

    g_stCtrlLogInfo.f32AdasDebugVal[130] = (float)Get_sRaStateCommon().sRAEvnt.eRAQuitEvnt;
    g_stCtrlLogInfo.f32AdasDebugVal[131] = (float)Get_sRaStateCommon().sRAEvnt.eRAIntrptType;
    g_stCtrlLogInfo.f32AdasDebugVal[132] = (float)Get_sHpaStateCommon().sHPAEvnt.eHPAQuitEvnt;
    g_stCtrlLogInfo.f32AdasDebugVal[133] = (float)Get_sHpaStateCommon().sHPAEvnt.eHPAIntrptEvnt;
    g_stCtrlLogInfo.f32AdasDebugVal[134] = (float)Get_sHpaStateCommon().sHPAEvnt.eHPATrmntEvnt;
    g_stCtrlLogInfo.f32AdasDebugVal[135] = (float)Get_sHpaStateCommon().sHPAEvnt.eHPAInhibitEvnt;
    g_stCtrlLogInfo.f32AdasDebugVal[136] = (float)Get_sHpaStateCommon().sHPAEvnt.eHPAFailureEvnt;
    g_stCtrlLogInfo.f32AdasDebugVal[137] = (float)Get_sHpaStateCommon().sHPAEvnt.eHPAIntrptType;
    g_stCtrlLogInfo.f32AdasDebugVal[138] = (float)Get_sSlaveLsadFsm().eLsadFuncSts;
    g_stCtrlLogInfo.f32AdasDebugVal[139] = (float)Get_sSlaveLsadFsm().eLsadFuncType;

    g_stCtrlLogInfo.f32AdasDebugVal[140] = (float)Get_sSlaveLsadFsm().eDriverCtrlCommand;
    g_stCtrlLogInfo.f32AdasDebugVal[141] = (float)Get_sSlaveLsadFsm().eBckgrndSearchSts;
    g_stCtrlLogInfo.f32AdasDebugVal[142] = (float)Get_sSlaveLsadFsm().eBckgrndRecordSts;
    g_stCtrlLogInfo.f32AdasDebugVal[143] = (float)Get_sSlaveLsadFsm().eBckgrndCruiseReadySts;
    g_stCtrlLogInfo.f32AdasDebugVal[144] = (float)Get_sSlaveLsadFsm().u8LsadStSResetPEB;
    g_stCtrlLogInfo.f32AdasDebugVal[145] = (float)Get_sPaStateAdptr().sCondiHMI.eAPAMod;
    g_stCtrlLogInfo.f32AdasDebugVal[146] = (float)Get_sPaStateAdptr().sCondiHMI.ePrkFnct;
    g_stCtrlLogInfo.f32AdasDebugVal[147] = (float)Get_sPaStateAdptr().sPAEvntAdptr.ePASuspendEvnt;
    g_stCtrlLogInfo.f32AdasDebugVal[148] = (float)Get_sPaStateAdptr().sPAEvntAdptr.ePAQuitEvnt;
    g_stCtrlLogInfo.f32AdasDebugVal[149] = (float)Get_sMsgMnger_TextDisp().u16FuncTextDisplay;

    g_stCtrlLogInfo.f32AdasDebugVal[150] = (float)Get_sMsgMnger_TextDisp().u8MapTextDisplay;
    g_stCtrlLogInfo.f32AdasDebugVal[151] = (float)Get_sMsgMnger_TextDisp().u8LocTextDisplay;
    g_stCtrlLogInfo.f32AdasDebugVal[152] = (float)Get_sDiagInfo().bPASysFail;
    g_stCtrlLogInfo.f32AdasDebugVal[153] = (float)Get_sDiagInfo().bCameraSrvFail;
    g_stCtrlLogInfo.f32AdasDebugVal[154] = (float)Get_sDiagInfo().bVisionFail;
    g_stCtrlLogInfo.f32AdasDebugVal[155] = (float)Get_sDiagInfo().bPlfmFail;
    g_stCtrlLogInfo.f32AdasDebugVal[156] = (float)Get_sDiagInfo().bTsSrvFail;
    g_stCtrlLogInfo.f32AdasDebugVal[157] = (float)Get_sDiagInfo().bMcuBswFail;
    g_stCtrlLogInfo.f32AdasDebugVal[158] = (float)Get_sDiagInfo().bMcuLogFail;
    g_stCtrlLogInfo.f32AdasDebugVal[159] = (float)Get_sDiagInfo().bUssFail;

    g_stCtrlLogInfo.f32AdasDebugVal[160] = (float)Get_sPADispTx().ADCS11_Parking_WorkSts;
    g_stCtrlLogInfo.f32AdasDebugVal[161] = (float)Get_sPADispTx().ADCS4_PA_failinfo;
    g_stCtrlLogInfo.f32AdasDebugVal[162] = (float)Get_sPADispTx().ADCS4_APA_FunctionMode;
    g_stCtrlLogInfo.f32AdasDebugVal[163] = (float)Get_sPADispTx().ADCS4_TractionswithReq;
    g_stCtrlLogInfo.f32AdasDebugVal[164] = (float)Get_sPADispTx().ADCS8_TBA_text;
    g_stCtrlLogInfo.f32AdasDebugVal[165] = (float)Get_sPADispTx().ADCS4_TBA_Distance;
    g_stCtrlLogInfo.f32AdasDebugVal[166] = (float)stMsgMnger_Tactical.u8StatusParkin;
    g_stCtrlLogInfo.f32AdasDebugVal[167] = (float)Get_sRelatedModuleInfo().u8VehicleActionReason;
    g_stCtrlLogInfo.f32AdasDebugVal[168] = (float)Get_sRelatedModuleInfo().eCtrlFailReason;

    Ctrl_DiagHandShake();

    return E_OK;
}


uint16_t Ctrl_DiagHandShake()
{
    tMsgMnger_ApaState stMsgMnger_ApaState;
    uint8 u8HandShakeSts = 0;
    Rte_Read_MsgManager_ApaState(&stMsgMnger_ApaState);

    (void)Rte_Read_HanshakeStatus(&u8HandShakeSts);

    if(stMsgMnger_ApaState.eLsadSystemSts == LSAD_STS_ACTIVE)
    {
        if(u8HandShakeSts == 0)
        {
            g_stCtrlDiagErrCode.u16ModuleHandshakeErrCode = CTRL_ERR_HANDSHAKE_EXECUTE_FAIL;
        }
    }

    return g_stCtrlDiagErrCode.u16ModuleHandshakeErrCode;
}


uint16_t Ctrl_DiagInputChassis(tMsgMnger_VehicleInfo   *pstVehicleInfo)
{
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
    if(pstVehicleInfo->sVehicleDataRx.stVehESCInfo.f32VehicleSpeed > stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32SpeedMax)
    {
        g_stCtrlDiagErrCode.u16ModuleInputErrCode = CTRL_ERR_INPUT_CHASSIS_OVERSPEED;
    }

    if(pstVehicleInfo->sVehicleDataRx.stVehEPSInfo.f32SteeringWheelAngle > stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32SteerAngleMax
       || pstVehicleInfo->sVehicleDataRx.stVehEPSInfo.f32SteeringWheelAngle < -stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32SteerAngleMax)
    {
        g_stCtrlDiagErrCode.u16ModuleInputErrCode = CTRL_ERR_INPUT_CHASSIS_STEER_INVALID;
    }

    if(pstVehicleInfo->sVehicleDataRx.stVehESCInfo.f32WheelSpeedFL > stCalibPF_ptr->stPFVehCalib.Calib_f32ImpulseMax
         || pstVehicleInfo->sVehicleDataRx.stVehESCInfo.f32WheelSpeedFR > stCalibPF_ptr->stPFVehCalib.Calib_f32ImpulseMax)
    {
        g_stCtrlDiagErrCode.u16ModuleInputErrCode = CTRL_ERR_INPUT_CHASSIS_PULSE_INVALID;
    }

    return g_stCtrlDiagErrCode.u16ModuleInputErrCode;
}


uint16_t Ctrl_DiagInputUss(tMsgMnger_PDC *pstPdcData)
{
    int i = 0;

    if(APA_US_STS_FAILED == pstPdcData->eApaPdcSts)
    {
        g_stCtrlDiagErrCode.u16ModuleInputErrCode = CTRL_ERR_INPUT_USS_SYSTEM_ERROR;

        return g_stCtrlDiagErrCode.u16ModuleInputErrCode;
    }

    for(i=0; i<US_IDX_NUM_MAX; i++)
    {
        if(pstPdcData->u16Distance[i] > CTRL_USS_APA_PDC_VALUE_MAX)
        {
            g_stCtrlDiagErrCode.u16ModuleInputErrCode = CTRL_ERR_INPUT_USS_INVALID_VALUE;
            break;
        }
        else if(pstPdcData->u16Distance[i] < CTRL_USS_PDC_DANGER_DISTANCE)
        {
            g_stCtrlDiagErrCode.u16ModuleInputErrCode = CTRL_ERR_INPUT_USS_DANGER_DIS;
            break;
        }
    }

    for(i=0; i<PDC_ZONE_NUM; i++)
    {
        if(pstPdcData->u16PdcDistance[i] > CTRL_USS_APA_PDC_VALUE_MAX)
        {
            g_stCtrlDiagErrCode.u16ModuleInputErrCode = CTRL_ERR_INPUT_USS_INVALID_VALUE;
            break;
        }
        else if(pstPdcData->u16PdcDistance[i] < CTRL_USS_PDC_DANGER_DISTANCE)
        {
            g_stCtrlDiagErrCode.u16ModuleInputErrCode = CTRL_ERR_INPUT_USS_DANGER_DIS;
            break;
        }
    }

    return g_stCtrlDiagErrCode.u16ModuleInputErrCode;
}


// uint16_t Ctrl_DiagAPAShell(ExtY_apa_shell_ctrl_T *pstApaState)
// {

//     if(pstApaState->eLsadSystemSts >= LSAD_STS_INVALID)
//         g_stCtrlDiagErrCode.u16ModuleInputErrCode = CTRL_ERR_INPUT_SM_STS_INVALID;
//     else if(pstApaState->eLsadSystemSts == LSAD_STS_CANCEL)
//         g_stCtrlDiagErrCode.u16ModuleInputErrCode = CTRL_ERR_INPUT_SM_STS_CANCEL;
//     else if(pstApaState->eLsadSystemSts == LSAD_STS_TERMINATED)
//         g_stCtrlDiagErrCode.u16ModuleInputErrCode = CTRL_ERR_INPUT_SM_STS_TERMINATED;
//     else if(pstApaState->eLsadSystemSts == LSAD_STS_FAILURE)
//         g_stCtrlDiagErrCode.u16ModuleInputErrCode = CTRL_ERR_INPUT_SM_STS_FAILURE;
//     else if(pstApaState->eLsadFuncType > LSAD_EOL)
//         g_stCtrlDiagErrCode.u16ModuleInputErrCode = CTRL_ERR_INPUT_SM_TYPE_INVALID;

//     return g_stCtrlDiagErrCode.u16ModuleInputErrCode;
// }


uint16_t Ctrl_DiagInputPpInfo(tMsgMnger_PathPlanner  *pstPpInfo)
{
    
    if (APA_PATH_PLAN_FAILED == pstPpInfo->eApaPathPlanSts)
    {
        g_stCtrlDiagErrCode.u16ModuleInputErrCode = CTRL_ERR_INPUT_PP_FAILURE;
    }
    else if (pstPpInfo->stPathPlanData.u8PlanResult >= 10)	// ==2 change to >= 10
    {
        g_stCtrlDiagErrCode.u16ModuleInputErrCode = CTRL_ERR_INPUT_PP_REPLAN_FAIL;
    }

    return g_stCtrlDiagErrCode.u16ModuleInputErrCode;
}


uint16_t Ctrl_DiagOutputChassis(tVehi_VehicleDataTx  *pstVehicleData)
{ 
    return 0;
}

uint16_t Ctrl_DiaUserAction(void)
{
    return g_stCtrlDiagErrCode.u16ModuleUserErrCode;
}

void Ctrl_DiagSetPebErrCode(uint16_t errCode)
{
    g_stCtrlDiagErrCode.u16ModulePebErrCode = errCode;
}

void Ctrl_DiagSetDrErrCode(uint16_t errCode)
{
    g_stCtrlDiagErrCode.u16ModuleDrErrCode = errCode;
}

void Ctrl_DiagSetParkErrCode(uint16_t errCode)
{
    g_stCtrlDiagErrCode.u16ModuleParkErrCode = errCode;
}

void Ctrl_DiagSetParkoutErrCode(uint16_t errCode)
{
    g_stCtrlDiagErrCode.u16ModuleHeadoutErrCode = errCode;
}

void Ctrl_DiagSetCruiseErrCode(uint16_t errCode)
{
    g_stCtrlDiagErrCode.u16ModuleCruiseErrCode = errCode;
}

