/*
 * ctrl_lat_algo.h
 *
 *  Created on: Jul 21, 2021
 *      
 */

#ifndef SRC_APL_APP_CTRL_ALGO_INCLUDE_CTRL_LAT_ALGO_H_
#define SRC_APL_APP_CTRL_ALGO_INCLUDE_CTRL_LAT_ALGO_H_

#include "adas_math.h"
#include "ctrl_struct.h"
#include "ctrl_global_variables.h"

#define  ERCL_TEST_ON                                  1  
#define  ERCL_TEST_OFF                                 0  
#define  ERCL_TEST                                     ERCL_TEST_ON

#define  CTRL_DIS_ERR_CALCU_WEIGHT_COEFFICIENT_ONE     5.0f
#define  CTRL_DIS_ERR_CALCU_WEIGHT_COEFFICIENT_TWO     2.0f
#define  CTRL_DIS_ERR_CALCU_WEIGHT_COEFFICIENT_THREE   1.0f

#define  CTRL_AIM_DIS_GEAR_D                           1
// #define CTRL_AIM_DIS_GEAR_R                           0
#define  CTRL_P2P_DIS                                  0.2f

#define  CTRL_DIS_ERR_LPF_PARA                         0.15f
#define  CTRL_THETA_ERR_LPF_PARA                       0.45f


uint8_t Ctrl_CalLqrFeedbackAngle(tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                tPathPlannerInfo*         stPathPlannerInfo_ptr,
                                tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                tCtrlCommonInfo*          stCtrlCommonInfo_ptr);

float Ctrl_LqrCompensationLowPassFilter(tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                        tPathPlannerInfo*         stPathPlannerInfo_ptr,
                                        tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                        tCtrlCommonInfo*          stCtrlCommonInfo_ptr);

uint8_t Ctrl_CalTargetSteerAngleRaw(tPathPlannerInfo*      stPathPlannerInfo_ptr,
                                    tCtrlCommonInfo*       stCtrlCommonInfo_ptr,
                                    tCtrlLatInfo*          stCtrlLatInfo_ptr,
                                    tVehDataRx*            stVehDataRx_ptr);

float Ctrl_CalWheelCurve(tCtrlLatInfo*             stCtrlLatInfo_ptr,
                         tVehDataRx*               stVehDataRx_ptr);

uint8_t Ctrl_FinishActionLat(tCtrlCommonInfo*       stCtrlCommonInfo_ptr,
                             tCtrlLatInfo*          stCtrlLatInfo_ptr,
                             tVehDataRx*            stVehDataRx_ptr,
                             tCtrlToChassisInfo*    stCtrl2ChassisInfo_ptr);

uint8_t Ctrl_StopSteerBackToZero(tCtrlLongiInfo*        stCtrlLongiInfo_ptr,
                                 tCtrlCommonInfo*       stCtrlCommonInfo_ptr,
                                 tCtrlLatInfo*          stCtrlLatInfo_ptr);

uint8_t Ctrl_LimitationLat(tCtrlLongiInfo*         stCtrlLongiInfo_ptr,
                           tCtrlCommonInfo*       stCtrlCommonInfo_ptr,
                           tCtrlToChassisInfo*    stCtrl2ChassisInfo_ptr);

uint8_t Ctrl_Calcu_DistErr(tPathPlannerInfo*      stPathPlannerInfo_ptr,
                          tCtrlLatInfo*          stCtrlLatInfo_ptr,
                          tCtrlCommonInfo*       stCtrlCommonInfo_ptr,
                          tCtrlVehPose*          stCtrlVehPose_ptr);

uint8_t Ctrl_Calcu_ThetaErr(tPathPlannerInfo*     stPathPlannerInfo_ptr,
                            tCtrlLatInfo*         stCtrlLatInfo_ptr,
                            tCtrlCommonInfo*      stCtrlCommonInfo_ptr,
                            tCtrlVehPose*         stCtrlVehPose_ptr);

tTrajectoryFrame Ctrl_GetLatErrTrajectoryFrame( tPathPlannerInfo*        stPathPlannerInfo_ptr,
                                                tCtrlVehiclePosition*      stPos_ptr,
                                                uint8_t                  index,
                                                float32_t                vehicleSped,
                                                tCtrlLatInfo*            stCtrlLatInfo_ptr,
                                                tCtrlCommonInfo*         stCtrlCommonInfo_ptr);

uint8_t Ctrl_DistErrorFilter(tCtrlLatInfo*   stCtrlLatInfo_ptr);

uint8_t Ctrl_ThetaErrorFilter(tCtrlLatInfo*   stCtrlLatInfo_ptr);

uint8_t Ctrl_Err_LowPassFilter(tCtrlLatErr*          stCtrlLatErr_ptr);

uint8_t Ctrl_LqrPreviewSinglePoint(tPathPlannerInfo*        stPathPlannerInfo_ptr,
                                   tCtrlLongiInfo*      	  stCtrlLongiInfo_ptr,
                                   tCtrlLatInfo*            stCtrlLatInfo_ptr,
                                   tCtrlCommonInfo*         stCtrlCommonInfo_ptr,
                                   tVehDataRx*              stVehDataRx_ptr);

uint8_t Ctrl_LqrPreviewMultiPoints(tPathPlannerInfo*        stPathPlannerInfo_ptr,
                                   tCtrlCommonInfo*         stCtrlCommonInfo_ptr,
                                   tCtrlLatInfo*            stCtrlLatInfo_ptr);

uint8_t Ctrl_CurvatureSinglePointFilter(tCtrlLatInfo*   stCtrlLatInfo_ptr);

uint8_t Ctrl_CurvatureMultiPointFilter(tCtrlLatInfo*   stCtrlLatInfo_ptr);

uint8_t Ctrl_CalFeedForwardAngle(tCtrlLatInfo*     stCtrlLatInfo_ptr);

uint8_t Ctrl_TargetSteerOutputFilter(tCtrlLatInfo* stCtrlLatInfo_ptr);

float     Ctrl_Point2Point_DisCalcu(float dr_x, float dr_y, float p_x, float p_y);
float     Ctrl_Point2Line_DisCalcu(float x1, float y1, float x2, float y2, float x3, float y3);
int8_t    Ctrl_PointLocateLine_Dir_Calcu(float x1, float y1, float x2, float y2, float x3, float y3);
float     Ctrl_TripletDisErr_Calcu(float dr_x, float dr_y, float p1x, float p1y, float p2x, float p2y,
                                          float p3x, float p3y, float p4x, float p4y, float wc1, float wc2, float wc3);
float     Ctrl_Anti_Devide_Zero(float temp);
float     Ctrl_CalcuRotatePointCoordsX(float Point1_y, float Point2_y, float Point2_x);
float     Ctrl_CalcuRotatePointCoordsY(float Point1_x, float Point2_x, float Point2_y);

float     Ctrl_CalWheelCurveFromAngleRatioBase(float f32SteerAngle, float f32SteerRatio, float f32WheelBase);

void Ctrl_GetLatError(tTrajectoryFrame *stTrajFrame_ptr,
                      tCtrlLatInfo* stCtrlLatInfo_ptr);
float Ctrl_LqrPreviewSinglePointCompensation(tVehDataRx*              stVehDataRx_ptr,
                                               tCtrlCommonInfo*         stCtrlCommonInfo_ptr,
                                               tPathPlannerInfo*        stPathPlannerInfo_ptr);
#endif /* SRC_APL_APP_CTRL_ALGO_INCLUDE_CTRL_LAT_ALGO_H_ */
