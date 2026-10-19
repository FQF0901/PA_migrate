#ifndef ONLINE_CALIB_STRUCT_H
#define ONLINE_CALIB_STRUCT_H

#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "adas_project_input.h"
#include "vehicle_service/calib/vehsrv_calib_data.h"

/*	=====================================================================
*						       Struct Define
*	===================================================================*/

typedef struct _tPFOnlineCalibData_CarPara
{
    // CarParam
    float  Calib_f32WhlBase               ;
    float  Calib_f32VehWidthDefault       ;
    float  Calib_f32ImpuseGap             ;
    float  Calib_f32ImpulseMax            ;
    float  Calib_f32FP0                  ;
    float  Calib_f32FP1                  ;
    float  Calib_f32FP2                  ;
    float  Calib_f32FP3                  ;
    float  Calib_f32RP0                  ;
    float  Calib_f32RP1                  ;
    float  Calib_f32RP2                  ;
    float  Calib_f32RP3                  ;
    float Config_f32VerticalParkForceFinish       ;
    float Config_f32HorizontalParkForceFinish     ;
    float Config_f32VerticalChockDetectDistance   ;
    float Config_f32HorizontalChockDetectDistance ;
    float Config_i16VerticalChockWaitTime         ;
    float Config_i16HorizontalChockWaitTime       ;
    float Config_i16GeneralChockWaitTime          ;
    float Config_u16UnknowStopWaitTime            ;
    float  Calib_f32DrDelayTime           ;
    float  Calib_param_res2               ;
    float  Calib_param_res3               ;
    float  Calib_param_res4               ;
    float  Calib_param_res5               ;
}tPFOnlineCalibData_CarPara;


typedef struct _tPFOnlineCalibData_LatCtrl
{
    // LatCtrl
    float Calib_f32SteerRatioDefault              ;
    float Calib_f32SteerLatDistErrGain            ;
    float Calib_f32SteerLatThetaErrGain           ;
    float Calib_f32SteerEndPosDisRate             ;
    float Calib_f32SteerAngleMax                  ;
    float Calib_f32SteerAngleIncreRatioMax        ;
    float Calib_f32SteerAngleIncreRatioMed        ;
    float Calib_i16LookAheadForwardOffset         ;
    float Calib_f32SinglePointPreviewKappaLpfDen2 ;
    float Calib_f32SinglePointPreviewKappaLpfNum1 ;
    float Calib_f32SinglePointPreviewKappaLpfNum2 ;
    float Calib_f32MultiPointPreviewKappaLpfDen2  ;
    float Calib_f32MultiPointPreviewKappaLpfNum1  ;
    float Calib_f32MultiPointPreviewKappaLpfNum2  ;
    float Calib_f32DistErrorLpfDen2               ;
    float Calib_f32DistErrorLpfNum1               ;
    float Calib_f32DistErrorLpfNum2               ;
    float Calib_f32ThetaErrorLpfDen2              ;
    float Calib_f32ThetaErrorLpfNum1              ;
    float Calib_f32ThetaErrorLpfNum2              ;
    float Calib_f32TargetSteerLpfDen2             ;
    float Calib_f32TargetSteerLpfNum1             ;
    float Calib_f32TargetSteerLpfNum2             ;
    float Calib_lat_res1                          ;
    float Calib_lat_res2                          ;
}tPFOnlineCalibData_LatCtrl;


typedef struct _tPFOnlineCalibData_LongiCtr
{
    // LongiCtr
    float Calib_f32CtrlAccKp                      ;
    float Calib_f32CtrlAccKi                      ;
    float Calib_f32CtrlAccKiAntiWindup            ;
    float Calib_f32StopSteerToleranceAngle        ;
    float Calib_f32DistanceLeftMin                ;
    float Calib_f32SpeedIncreRatioMax             ;
    float Calib_f32SpeedIncreRatioMed             ;
    float Calib_f32AccIncreRatioMax               ;
    float Calib_f32AccIncreRatioMed               ;
    float Calib_f32RegardAsStopSpeed              ;
    float Calib_f32SpeedMax                       ;
    float Calib_f32SpeedMin                       ;
    float Calib_f32AccMax                         ;
    float Calib_f32AccMin                         ;
    float Calib_f32EmergStopAccMax                ;
    float Calib_f32EmergStopAccMin                ;
    float Calib_f32AccSlopeUpLimit                ;
    float Calib_f32AccSlopeLowLimit               ;
    float Calib_f32DeAccelSlopeUpLimit            ;
    float Calib_f32DeAccelSlopeLowLimit           ;

    float Calib_f32StopAccRq                      ;
    float Calib_f32EmergStopAccRq                 ;
    float Calib_longi_res3                        ;
    float Calib_longi_res4                        ;
    float Calib_longi_res5                        ;
    float Calib_longi_res6                        ;
    float Calib_longi_res7                        ;
}tPFOnlineCalibData_LongiCtr;


typedef struct _tPFOnlineCalibData_SpeedPara
{
    // SpeedPara
    float Calib_f32PathLengthThreshold1       ;
    float Calib_f32PathLengthThreshold2       ;
    float Calib_f32PathLengthThreshold3       ;
    float Calib_f32PathLengthLevel1DecelDis   ;
    float Calib_f32PathLengthLevel1StopDis    ;
    float Calib_f32PathLengthLevel1MaxSpeed   ;
    float Calib_f32PathLengthLevel1InitSpeed  ;
    float Calib_f32PathLengthLevel2DecelDis   ;
    float Calib_f32PathLengthLevel2StopDis    ;
    float Calib_f32PathLengthLevel2MaxSpeed   ;
    float Calib_f32PathLengthLevel2InitSpeed  ;
    float Calib_f32PathLengthLevel3DecelDis   ;
    float Calib_f32PathLengthLevel3StopDis    ;
    float Calib_f32PathLengthLevel3MaxSpeed   ;
    float Calib_f32PathLengthLevel3InitSpeed  ;
    float Calib_f32PathLengthLevel4DecelDis   ;
    float Calib_f32PathLengthLevel4StopDis    ;
    float Calib_f32PathLengthLevel4MaxSpeed   ;
    float Calib_f32PathLengthLevel4InitSpeed  ;
    float Calib_f32VerticalLastPathDecelDis   ;
    float Calib_f32MechaLastPathMaxSpeed      ;
    float Calib_speed_res1                    ;
    float Calib_speed_res2                    ;
    float Calib_speed_res3                    ;
    float Calib_speed_res4                    ;
}tPFOnlineCalibData_SpeedPara;


typedef struct _tPFOnlineCalibData_PebPara
{
    // PebPara
    float Calib_f32PebActive;
    float Calib_f32PebActiveSide;
    float Calib_f32StopRelativeA;
    float Calib_f32ReduceRelativeA;
    float Calib_f32ActuatReactTime;
    float Calib_f32PebLevel0SafeDit;
    float Calib_f32PebLevel1SafeDit;
    float Calib_f32PebLevel2SafeDit;
}tPFOnlineCalibData_PebPara;


typedef struct _tPFOnlineCalibData_Headout
{
    // Headout
    float Calib_f32ThetaLimit           ;
    float Calib_f32PkoutFrontDisLimit   ;
    float Calib_i16SpaceLimit           ;
    float Calib_i16PkoutSideDisLimit    ;
    float Calib_i16PkoutStraightFrontDisLimit ;
    float Calib_f32ParkoutSpeed         ;
    float Calib_headout_res1            ;
    float Calib_headout_res2            ;
    float Calib_headout_res3            ;
    float Calib_headout_res4            ;
    float Calib_headout_res5            ;
    float Calib_headout_res6            ;
    float Calib_headout_res7            ;
    float Calib_headout_res8            ;
    float Calib_headout_res9            ;
    float Calib_PF_freevalue1           ;
    float Calib_PF_freevalue2           ;
    float Calib_PF_freevalue3           ;
    float Calib_PF_freevalue4           ;
    float Calib_PF_freevalue5           ;
    float Calib_PF_freevalue6           ;
    float Calib_PF_freevalue7           ;
    float Calib_PF_freevalue8           ;
    float Calib_PF_freevalue9           ;
    float Calib_PF_freevalue10          ;
}tPFOnlineCalibData_Headout;


typedef struct _tPFOnlineCalibData_Cruise
{
    float Calib_f32STOPSPEEDCRUISING         ;
    float Calib_f32STOPSTEERGAPCRUISING      ;
    float Calib_f32STOPACCCRUISING           ;
    float Calib_f32MAX_LATERRDISCRUISING     ;
    float Calib_f32MAX_LATERRHEADINGCRUISING ;
    float Calib_f32MAX_LONERRCRUISING        ;
    float Calib_f32LPBANDWIDTHCRUISING       ;
    float Calib_f32K1DISCRUISING             ;
    float Calib_f32K2DOTDISCRUISING          ;
    float Calib_f32K3THETACRUISING           ;
    float Calib_f32K4DOTTHETACRUISING        ;
    float Calib_cuise_res1                   ;
    float Calib_cuise_res2                   ;
    float Calib_cuise_res3                   ;
    float Calib_cuise_res4                   ;
    float Calib_cuise_res5                   ;
    float Calib_cuise_res6                   ;
    float Calib_cuise_res7                   ;
    float Calib_cuise_res8                   ;
    float Calib_cuise_res9                   ;
    float Calib_cuise_res10                  ;
    float Calib_cuise_res11                  ;
    float Calib_cuise_res12                  ;
    float Calib_cuise_res13                  ;
    float Calib_cuise_res14                  ;
}tPFOnlineCalibData_Cruise;

typedef struct _tPFOnlineCalibData
{
    tPFOnlineCalibData_CarPara    stPFOnlineCalibData_CarPara_A;   //A
    tPFOnlineCalibData_LatCtrl    stPFOnlineCalibData_LatCtrl_B;   //B
    tPFOnlineCalibData_LongiCtr   stPFOnlineCalibData_LongiCtr_C;  //C
    tPFOnlineCalibData_SpeedPara  stPFOnlineCalibData_SpeedPara_D; //D
    tPFOnlineCalibData_PebPara    stPFOnlineCalibData_PebPara_E;   //E
    tPFOnlineCalibData_Headout    stPFOnlineCalibData_Headout_F;   //F
    tPFOnlineCalibData_Cruise     stPFOnlineCalibData_Cruise_G;    //G

    //to extend here

}tPFOnlineCalibData;


typedef struct _tOnlineCalibDataIndex
{
    float*   a_index;
    float*   b_index;
    float*   c_index;
    float*   d_index;
    float*   e_index;
    float*   f_index;
    float*   g_index;
}OnlineCalibDataIndex;

typedef struct _stCalibDataIndex{
    char groupId;
    int  id;
}stCalibDataIndex;

#endif // ONLINE_CALIB_STRUCT_H
