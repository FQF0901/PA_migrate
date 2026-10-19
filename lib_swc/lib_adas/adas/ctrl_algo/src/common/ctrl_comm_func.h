/*
 * ctrl_comm_func.h
 *
 *  Created on: Jul 20, 2021
 *      
 */

#ifndef SRC_APL_APP_CTRL_ALGO_INCLUDE_CTRL_COMM_FUNC_H_
#define SRC_APL_APP_CTRL_ALGO_INCLUDE_CTRL_COMM_FUNC_H_

#include "ctrl_struct.h"

float Ctrl_InstanceRadiusCal(tVehDataRx*   stVehDataRx_ptr);
uint8_t control_WheelSpeedDirection_Opposite_gear(tVehDataRx*            stVehDataRx_ptr,
                                                  tCtrlCommonInfo*       stCtrlCommonInfo_ptr);
uint8_t Ctrl_GearReq(tPathPlannerInfo*      stPathPlannerInfo_ptr,
                     tVehDataRx*            stVehDataRx_ptr,
                     tCtrlToChassisInfo*    stCtrl2ChassisInfo_ptr,
                     tCtrlCommonInfo*       stCtrlCommonInfo_ptr);

uint8_t Ctrl_ApaStraightGearReq(tCtrlFuncFsmInfo*	   stCtrlApaShellInfo_ptr,
                                tVehDataRx*            stVehDataRx_ptr,
                                tCtrlToChassisInfo*    stCtrl2ChassisInfo_ptr,
                                tCtrlCommonInfo*       stCtrlCommonInfo_ptr);

uint8_t Ctrl_UpdateCurPathId(tVehDataRx*                stVehDataRx_ptr,
                             tCtrlLongiInfo*            stCtrlLongiInfo_ptr,
                             tCtrl_StateInfo*           stCtrl2PP_State_Info_ptr,
                             tCtrlCommonInfo*           stCtrlCommonInfo_ptr,
                             tPathPlannerInfo*          stPathPlannerInfo_ptr);

uint8_t Ctrl_UpdateCtrlState(tVehDataRx*           stVehDataRx_ptr,
                             tCtrlLongiInfo*       stCtrlLongiInfo_ptr,
                             tCtrl_StateInfo*      stCtrl2PP_State_Info_ptr,
                             tCtrlCommonInfo*      stCtrlCommonInfo_ptr,
                             tPathPlannerInfo*     stPathPlannerInfo_ptr);

uint8_t Ctrl_SelectPoseForLateralCalcu(tCtrlVehPose*      stCtrlVehPose_ptr);

uint8_t Ctrl_RecordPrevPose(tCtrlVehPose*      stCtrlVehPose_ptr);

uint8_t Ctrl_PathDistanceLeft(tCtrlVehiclePosition*     stCurrentPos_ptr,
                              tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
						      tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
						      tPathPlannerInfo*         stPathPlannerInfo_ptr);

uint8_t Ctrl_TrajDistanceLeft(tCtrlVehiclePosition*     stCurrentPos_ptr,
                              tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
						      tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
						      tPathPlannerInfo*         stPathPlannerInfo_ptr);

uint8_t Ctrl_DistanceLeft(tPathPlannerInfo*   stPathPlannerInfo_ptr);

uint8_t Ctrl_VehTrappedDetection(tPathPlannerInfo*          stPathPlannerInfo_ptr,
                                 tCtrlCommonInfo*           stCtrlCommonInfo_ptr,
                                 tVehDataRx*   stVehDataRx_ptr);

uint8_t Ctrl_ReqPause(tCtrlCommonInfo*           stCtrlCommonInfo_ptr,
                      tPathPlannerInfo*          stPathPlannerInfo_ptr);

uint8_t Ctrl_WheelChock_Detection(tCtrlCommonInfo*           stCtrlCommonInfo_ptr,
                                  tVehDataRx*                stVehDataRx_ptr,
                                  tPathPlannerInfo*          stPathPlannerInfo_ptr,
                                  tCtrlToChassisInfo*        stCtrl2ChassisInfo_ptr);

uint8_t Ctrl_UnknownLongStopDetection(tVehDataRx*               stVehDataRx_ptr,
                                      tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                      tCtrlToChassisInfo*       stCtrl2ChassisInfo_ptr);

// uint8_t Ctrl_WheelStopByDistanceChange(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
//                                        tCtrlVehiclePosition*     stCurrentPos_ptr);

uint8_t Ctrl_FinishDetermination(tPathPlannerInfo*         stPathPlannerInfo_ptr,
                                 tCtrlCommonInfo*          stCtrlCommonInfo_ptr);

uint8_t Ctrl_FindNearestPathPoint(tPathPlannerInfo*     stPathPlannerInfo_ptr,
                                  tCtrlCommonInfo*      stCtrlCommonInfo_ptr,
                                  tCtrlVehPose*         stCtrlVehPose_ptr);

uint8_t Ctrl_FindNearestBehindPathPoint(tPathPlannerInfo*     stPathPlannerInfo_ptr,
                                        tCtrlCommonInfo*      stCtrlCommonInfo_ptr,
                                        tCtrlVehPose*         stCtrlVehPose_ptr);

uint8_t Ctrl_FinishActionCommon(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                tCtrlToChassisInfo*       stCtrl2ChassisInfo_ptr,
                                tVehDataRx*               stVehDataRx_ptr);

uint8_t Ctrl_ApaStraightFinishDetermination(tCtrlFuncFsmInfo*	   stCtrlApaShellInfo_ptr,
                                            tCtrlCommonInfo*       stCtrlCommonInfo_ptr);

uint8_t Ctrl_FuturePositionPrediction(tCtrlVehPose*             stCtrlVehPose_ptr,
                                      tVehDataRx*               stVehDataRx_ptr,
                                      tPathPlannerInfo*         stPathPlannerInfo_ptr,
                                      tCtrlCommonInfo*          stCtrlCommonInfo_ptr);

uint8_t Ctrl_LpfCalculation(tCtrlLowPassFilterPara*   stCtrlLpfLat_ptr);



#endif /* SRC_APL_APP_CTRL_ALGO_INCLUDE_CTRL_COMM_FUNC_H_ */
