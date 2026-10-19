#ifndef VEHSRV_CALIB_STRUCT_H_
#define VEHSRV_CALIB_STRUCT_H_

#include <stdint.h>

typedef struct _PF_CTRL_LONG_CALIBRATION_TAG_
{
    float Calib_f32CtrlAccKp;
    float Calib_f32CtrlAccKi;
    float Calib_f32StopAccRq;
    float Calib_f32EmergStopAccRq;
    float Calib_f32CtrlAccKiAntiWindup;
    float Calib_f32StopSteerToleranceAngle;

    float Calib_f32SpeedMax;
    float Calib_f32SpeedMin;
    float Calib_f32AccMax;
    float Calib_f32AccMin;
    float Calib_f32EmergStopAccMax;
    float Calib_f32EmergStopAccMin;
    float Calib_f32AccSlopeUpLimit;
    float Calib_f32AccSlopeLowLimit;
    float Calib_f32DeAccelSlopeUpLimit;
    float Calib_f32DeAccelSlopeLowLimit;
    float Calib_f32DistanceLeftMin;
    
    float Calib_f32PathLengthThreshold1;
    float Calib_f32PathLengthThreshold2;
    float Calib_f32PathLengthThreshold3;
    float Calib_f32PathLengthLevel1DecelDis;
    float Calib_f32PathLengthLevel1StopDis;
    float Calib_f32PathLengthLevel1MaxSpeed;
    float Calib_f32PathLengthLevel1InitSpeed;
    float Calib_f32PathLengthLevel2DecelDis;
    float Calib_f32PathLengthLevel2StopDis;
    float Calib_f32PathLengthLevel2MaxSpeed;
    float Calib_f32PathLengthLevel2InitSpeed;
    float Calib_f32PathLengthLevel3DecelDis;
    float Calib_f32PathLengthLevel3StopDis;
    float Calib_f32PathLengthLevel3MaxSpeed;
    float Calib_f32PathLengthLevel3InitSpeed;
    float Calib_f32PathLengthLevel4DecelDis;
    float Calib_f32PathLengthLevel4StopDis;
    float Calib_f32PathLengthLevel4MaxSpeed;
    float Calib_f32PathLengthLevel4InitSpeed;
    float Calib_f32VerticalLastPathDecelDis;
    float Calib_f32MechaLastPathMaxSpeed;

    float Calib_f32RegardAsStopSpeed;
    float Calib_f32SpeedIncreRatioMax;
    float Calib_f32SpeedIncreRatioMed;
    float Calib_f32AccIncreRatioMax;
    float Calib_f32AccIncreRatioMed;

}tPFCtrlLongCalib;


typedef struct _PF_CTRL_LAT_CALIBRATION_TAG
{
    float Calib_f32SteerRatioDefault;
    float Calib_f32SteerLatDistErrGain;
    float Calib_f32SteerLatThetaErrGain;
    float Calib_f32SteerEndPosDisRate;
    float Calib_f32SteerAngleMax;
    float Calib_f32SteerAngleIncreRatioMax;
    float Calib_f32SteerAngleIncreRatioMed;

    float Calib_f32SinglePointPreviewKappaLpfDen2;
    float Calib_f32SinglePointPreviewKappaLpfNum1;
    float Calib_f32SinglePointPreviewKappaLpfNum2;
    float Calib_f32MultiPointPreviewKappaLpfDen2;
    float Calib_f32MultiPointPreviewKappaLpfNum1;
    float Calib_f32MultiPointPreviewKappaLpfNum2;
    float Calib_f32DistErrorLpfDen2;
    float Calib_f32DistErrorLpfNum1;
    float Calib_f32DistErrorLpfNum2;
    float Calib_f32ThetaErrorLpfDen2;
    float Calib_f32ThetaErrorLpfNum1;
    float Calib_f32ThetaErrorLpfNum2;
    float Calib_f32TargetSteerLpfDen2;
    float Calib_f32TargetSteerLpfNum1;
    float Calib_f32TargetSteerLpfNum2;

    float Calib_f32SteerTorqueIncreRatioMax;
    float Calib_f32SteerTorqueIncreRatioMed;
    float Calib_f32SteerTorqueMax;

    float Calib_f32FP3;
    float Calib_f32FP2;
    float Calib_f32FP1;
    float Calib_f32FP0;

    float Calib_f32RP3;
    float Calib_f32RP2;
    float Calib_f32RP1;
    float Calib_f32RP0;

    int16_t Calib_i16LookAheadForwardOffset;
    int16_t i16Res;


}tPFCtrlLatCalib;


typedef struct _PF_DR_Calib_TAG_
{
    float Calib_f32VehWidth90Left_forward;
    float Calib_f32VehWidth180Left_forward;
    float Calib_f32VehWidth270Left_forward;
    float Calib_f32VehWidth360Left_forward;
    float Calib_f32VehWidth450Left_forward;
    float Calib_f32VehWidthMaxLeft_forward;
    float Calib_f32VehWidth90Right_forward;
    float Calib_f32VehWidth180Right_forward;
    float Calib_f32VehWidth270Right_forward;
    float Calib_f32VehWidth360Right_forward;
    float Calib_f32VehWidth450Right_forward;
    float Calib_f32VehWidthMaxRight_forward;

    float Calib_f32VehWidth90Left_backward;
    float Calib_f32VehWidth180Left_backward;
    float Calib_f32VehWidth270Left_backward;
    float Calib_f32VehWidth360Left_backward;
    float Calib_f32VehWidth450Left_backward;
    float Calib_f32VehWidthMaxLeft_backward;
    float Calib_f32VehWidth90Right_backward;
    float Calib_f32VehWidth180Right_backward;
    float Calib_f32VehWidth270Right_backward;
    float Calib_f32VehWidth360Right_backward;
    float Calib_f32VehWidth450Right_backward;
    float Calib_f32VehWidthMaxRight_backward;

    float Calib_f32FP3;
    float Calib_f32FP2;
    float Calib_f32FP1;
    float Calib_f32FP0;

    float Calib_f32RP3;
    float Calib_f32RP2;
    float Calib_f32RP1;
    float Calib_f32RP0;



}tPFDRCalib;

typedef struct _PF_PEB_CALIBRATION_TAG_
{
    float Calib_f32PebActive;
    float Calib_f32PebActiveSide;
    float Calib_f32StopRelativeA;
    float Calib_f32ReduceRelativeA;
    float Calib_f32ActuatReactTime;
    float Calib_f32PebLevel0SafeDit;
    float Calib_f32PebLevel1SafeDit;
    float Calib_f32PebLevel2SafeDit;
}tPFPEBCalib;

typedef struct _PF_PKOUT_CALIBRATION_TAG_
{

    float   Calib_f32ThetaLimit;
    float   Calib_f32PkoutFrontDisLimit;
    int16_t Calib_i16SpaceLimit;
    int16_t Calib_i16PkoutSideDisLimit;
    int16_t Calib_i16PkoutStraightFrontDisLimit;
    float   Calib_f32ParkoutSpeed;

    float   Calib_PF_freevalue1;
    float   Calib_PF_freevalue2;
    float   Calib_PF_freevalue3;
    float   Calib_PF_freevalue4;
    float   Calib_PF_freevalue5;
    float   Calib_PF_freevalue6;
    float   Calib_PF_freevalue7;
    float   Calib_PF_freevalue8;
    float   Calib_PF_freevalue9;
    float   Calib_PF_freevalue10;
}tPFPkoutCalib;

typedef struct _PF_VEH_TAG_
{
    float Calib_f32WhlBase;
    float Calib_f32VehWidthDefault;
    float Calib_f32ImpuseGap;
    float Calib_f32ImpulseMax;
    float Calib_f32ImpulsePerLoop;
    float Calib_f32DrDelayTime;
}tPFVehCalib;

typedef struct _PF_ADAS_FUN_CONFIG_TAG_
{
    float Config_f32VerticalParkForceFinish;
    float Config_f32HorizontalParkForceFinish;
    float Config_f32CtrtlTimeDT;
    float Config_f32VerticalChockDetectDistance;
    float Config_f32HorizontalChockDetectDistance;

    int16_t Config_i16VerticalChockWaitTime;
    int16_t Config_i16HorizontalChockWaitTime;
    int16_t Config_i16GeneralChockWaitTime;
    uint16_t Config_u16UnknowStopWaitTime;

}tPFAPAFuncConfig;

typedef struct _PF_ADAS_FUN_CRUISE_CONFIG_TAG_
{
    float Calib_f32STOPSPEEDCRUISING;
    float Calib_f32STOPSTEERGAPCRUISING;
    float Calib_f32STOPACCCRUISING;
    float Calib_f32MAX_LATERRDISCRUISING;
    float Calib_f32MAX_LATERRHEADINGCRUISING;
    float Calib_f32MAX_LONERRCRUISING;

    float Calib_f32LPBANDWIDTHCRUISING;
    float Calib_f32K1DISCRUISING;
    float Calib_f32K2DOTDISCRUISING;
    float Calib_f32K3THETACRUISING;
    float Calib_f32K4DOTTHETACRUISING;

}tPFCruiseFuncConfig;

typedef struct _ADAS_SYSTEM_CONFIG_TAG_
{
    uint8_t Calib_ADAS_APASHELL_SWITCH;
    uint8_t Calib_ADAS_DR_SWITCH;
    uint8_t Calib_res[30];

}tAdasSystemConfig;

typedef struct _PF_CALIBRATION_DATA_TAG_
{
    tPFVehCalib       stPFVehCalib;
    tPFCtrlLongCalib  stPFCtrlLongCalib;
    tPFCtrlLatCalib   stPFCtrlLatCalib;
    tPFDRCalib        stPFDRCalib;
    tPFPEBCalib       stPFPEBCalib;
    tPFPkoutCalib     stPFPkoutCalib;
    tPFAPAFuncConfig  stPFAPAFuncConfig;
    tPFCruiseFuncConfig  stPFCruiseFuncConfig;
    tAdasSystemConfig  stAdasSystemConfig;
}tPFCalibData;


#endif /* VEHSRV_CALIB_STRUCT_H_ */
