/*
 * ctrl_global_variables.h
 *
 *  Created on: Jul 14, 2021
 *      
 */

#ifndef SRC_APL_APP_CTRL_ALGO_INCLUDE_CTRL_PARA_DEFINATION_H_
#define SRC_APL_APP_CTRL_ALGO_INCLUDE_CTRL_PARA_DEFINATION_H_

#include "adas_project_input.h"
#include "ctrl_struct.h"
#include "ctrl_errcode.h"


/*===========================
*	External Input
*==========================*/
extern tVehDataRx                  g_stCtrlVehDataRx;
extern tPathPlannerInfo            g_stPathPlannerData;
extern tCtrlVehSpeed               g_stCtrlVehSpeed;
extern tCtrlVehPose                g_stCtrlVehPose;
extern tCtrlUssInfo                g_stCtrlUssInfo;	
extern tCtrlFuncFsmInfo		       g_stCtrlFuncFsmInfo;

/*===========================
*	Ctrl Module Variable
*==========================*/
extern tCtrlCommonInfo             g_stCtrlCommonInfo;
extern tCtrlLongiInfo               g_stCtrlLongiInfo;
extern tCtrlLatInfo                 g_stCtrlLatInfo;

/*===========================
*	External Output
*==========================*/
extern tCtrlToChassisInfo          g_stCtrlToChassisInfo;
extern tCtrl_StateInfo             g_stCtrlToPathPlannerInfo;
extern tCtrlToFuncStateMachine     g_stCtrlToFuncStateMachine;

/*===========================
*   Log, Diagnose
*==========================*/
extern tCtrl_LogInfo               g_stCtrlLogInfo;
extern tMsgMnger_CtrlErrCode       g_stCtrlDiagErrCode;

/*===========================
*   Others
*==========================*/
extern tCtrlParkOutSide                 g_stCtrlParkoutSide;

/*===========================
*   Cruising
*==========================*/
extern tVehicleModelAndCtrlPara    g_stVehicleParms;
extern tCtrlPurePursuit            g_stCtrlPurePursuit;
extern float                       g_lqrGain[4];
extern tTrajLongiController        g_stTrjLongiCtroller;
extern tStateMachine               g_stStateMachine;
extern tLowPassPars                g_stLpfPars;
extern tTrajectoryFrame            trajFramPos;

uint8_t Ctrl_VariablesInit(void);
uint8_t Ctrl_LongStateInit(void);
uint8_t Ctrl_PebDirInit(void);
uint8_t Ctrl_LogClean(void);

#endif /* SRC_APL_APP_CTRL_ALGO_INCLUDE_CTRL_PARA_DEFINATION_H_ */
