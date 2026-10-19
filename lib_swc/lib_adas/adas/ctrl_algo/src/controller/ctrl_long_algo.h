/*
 * ctrl_long_algo.h
 *
 *  Created on: Jul 20, 2021
 *      
 */

#ifndef SRC_APL_APP_CTRL_ALGO_INCLUDE_CTRL_LONG_ALGO_H_
#define SRC_APL_APP_CTRL_ALGO_INCLUDE_CTRL_LONG_ALGO_H_

#include "ctrl_struct.h"

uint8_t Ctrl_SpeedProfile(tCtrlCommonInfo*            stCtrlCommonInfo_ptr,
                          tCtrlLongiInfo*              stCtrlLongiInfo_ptr,
                          tPathPlannerInfo*           stPathPlannerInfo_ptr);

uint8_t Ctrl_SpeedTrapozoidPhase(tCtrlLatInfo*              stCtrlLatInfo_ptr,
                                 tVehDataRx*   stVehDataRx_ptr,
                                 tCtrlCommonInfo*           stCtrlCommonInfo_ptr,
                                 tPathPlannerInfo*          stPathPlannerInfo_ptr,
                                 tCtrlLongiInfo*      	    stCtrlLongiInfo_ptr);

uint8_t Ctrl_TrapozoidSpeedCtrl(tCtrlLongiInfo*      stCtrlLongiInfo_ptr,
                               tCtrlCommonInfo*      stCtrlCommonInfo_ptr,
                               tVehDataRx*   stVehDataRx_ptr,
                               tPathPlannerInfo*   	 stPathPlannerInfo_ptr);

uint8_t Ctrl_SpeedPhaseTransitCondition(tCtrlLongiInfo*       stCtrlLongiInfo_ptr,
                                        tVehDataRx*   stVehDataRx_ptr);
                                        
uint8_t Ctrl_ApaStraightSpeedCtrl(tCtrlFuncFsmInfo*	   stCtrlApaShellInfo_ptr,
                                  tCtrlLongiInfo*          stCtrlLongiInfo_ptr);
uint8_t Ctrl_ApaStraighStopDistanceCtrl(tCtrlFuncFsmInfo*	   stCtrlApaShellInfo_ptr,
                                        tCtrlCommonInfo*       stCtrlCommonInfo_ptr,
                                        tCtrlLongiInfo*        stCtrlLongiInfo_ptr);                                  
uint8_t Ctrl_CalTargetAcce(tCtrlLongiInfo*          stCtrlLongiInfo_ptr,
                           tCtrlCommonInfo*         stCtrlCommonInfo_ptr,
                           tVehDataRx*              stVehDataRx_ptr,
                           tCtrlToChassisInfo*      stCtrlToChassisInfo_ptr,
                           tCtrlUssInfo*            stCtrlUssInfo_ptr);
                           
uint8_t Ctrl_FuelOilCalTargetAcce(tCtrlLongiInfo*          stCtrlLongiInfo_ptr,
                                  tVehDataRx*   stVehDataRx_ptr);

uint8_t Ctrl_CalStopDistance(tCtrlLongiInfo*      	 stCtrlLongiInfo_ptr,
                             tCtrlCommonInfo*            stCtrlCommonInfo_ptr,
                             tVehDataRx*   stVehDataRx_ptr);

uint8_t Ctrl_FinishActionLongi(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                               tVehDataRx*   stVehDataRx_ptr,
                               tCtrlLongiInfo*      	 stCtrlLongiInfo_ptr);

uint8_t Ctrl_ConflictGearAction(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                tVehDataRx*   stVehDataRx_ptr,
                                tCtrlLongiInfo*      	  stCtrlLongiInfo_ptr);

uint8_t Ctrl_LimitationLongi(tVehDataRx*            stVehDataRx_ptr,
                             tCtrlLongiInfo*        stCtrlLongiInfo_ptr,
                             tCtrlToChassisInfo*    stCtrl2ChassisInfo_ptr,
                             tCtrlCommonInfo*       stCtrlCommonInfo_ptr);

void Ctrl_GetLongiError(tTrajectoryFrame* stTrajFrame_ptr,
                         tTrajLongiController* stTrajLongiController_ptr);

uint8_t Ctrl_SpeedCompensation(tPathPlannerInfo*   stPathPlannerData,
                               tCtrlCommonInfo*    stCtrlCommonInfo_ptr,
                               tCtrlLongiInfo*     stCtrlLongiInfo_ptr);

uint8_t Ctrl_TrajSpeedCtrl(tPathPlannerInfo*   stPathPlannerData,
                           tCtrlCommonInfo*    stCtrlCommonInfo_ptr,
                           tCtrlLongiInfo*     stCtrlLongiInfo_ptr);


void Ctrl_LongiVel(tCtrlCommonInfo*        stCtrlCommonInfo_ptr,
                   tPathPlannerInfo*       stPathPlannerData_ptr,
                   tTrajLongiController*   stTrajLongiController_ptr,
                   tCtrlLongiInfo*         stCtrlLongiInfo_ptr);

#endif /* SRC_APL_APP_CTRL_ALGO_INCLUDE_CTRL_LONG_ALGO_H_ */
