/*
 * ctrl_adapter.h
 *
 *  Created on: Jul 27, 2021
 *      
 */

#ifndef SRC_APL_APP_CTRL_ALGO_INCLUDE_CTRL_ADAPTER_H_
#define SRC_APL_APP_CTRL_ALGO_INCLUDE_CTRL_ADAPTER_H_

#include "ctrl_struct.h"

uint8_t Ctrl_ReceiveFromVehInterface(tVehDataRx*   stVehDataRx_ptr);
uint8_t Ctrl_ReceiveFromUSS(tCtrlUssInfo* stCtrlUssInfo_ptr);
uint8_t Ctrl_ReceiveFromPathPlanner(tPathPlannerInfo*   stPathPlannerInfo_ptr,
						   	                    tCtrlCommonInfo*    stCtrlCommonInfo_ptr,
                                    tCtrlFuncFsmInfo*   stCtrlApaShellInfo_ptr);
uint8_t Ctrl_ReceiveFromApaShell(tCtrlFuncFsmInfo*     stCtrlApaShellInfo_ptr);
uint8_t Ctrl_ReceiveFromLocalization(tCtrlVehPose*   stCtrlVehPose_ptr);
uint8_t Ctrl_SendToCAN(tVehDataRx*           stVehDataRx_ptr,
                       tCtrlToChassisInfo*   stCtrlToChassisInfo_ptr,
                       tCtrlFuncFsmInfo*     stCtrlApaShellInfo_ptr);
uint8_t Ctrl_SendToApaShell(tCtrlToFuncStateMachine*  stCtrlToFuncStateMachine_ptr);
uint8_t Ctrl_SendToSOC(const tCtrl_StateInfo*             stCtrl2PPStateInfo_ptr, 
                       const tCtrl_LogInfo*               stCtrlLogInfo_ptr,
                       const tCtrlToFuncStateMachine*     stCtrlToFuncStateMachine_ptr);
                       
uint8_t Ctrl_ShakeHandWithChassis(tCtrlToChassisInfo*  stCtrlToChassisInfo_ptr);
uint8_t Ctrl_WaveHandWithChassis(tVehDataRx*            stVehDataRx_pt,
                                 tCtrlToChassisInfo*    stCtrlToChassisInfo_ptr,
                                 tCtrlLatInfo*          stCtrlLatInfo_ptr);


#endif /* SRC_APL_APP_CTRL_ALGO_INCLUDE_CTRL_ADAPTER_H_ */
