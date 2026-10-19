#include "online_calib_algo.h"

/*  =====================================================================
*                            Global Val Define
*   ===================================================================*/


#define TRANSFER_MODE_CONFIG  TRANSFER_MODE_GROUP  


#define CALIB_ONLINE_GROUP_NUM             10   //最多10组(暂未使用)
#define CALIB_ONLINE_NUM_PER_GROUP         25   //每组25个

#define GROUP_START_ID      'A'
#define GROUP_END_ID        'G'
#define PROJECT_VERSION     "61000017"

//**********************************

static uint8_t CalibMcuRecvSocData(const tMsgMnger_CalibData*  stCalibSoc2McuData, tPFOnlineCalibData* pstOnlineCalib);
static uint8_t CalibMcuSendSocData( tPFOnlineCalibData* pstCalibOnlineData, tMsgMnger_CalibData*  pstCalibMcu2SocData);
static uint8_t CalibPackData(tPFOnlineCalibData* pstCalibOnlineData, tMsgMnger_CalibData* stCalibMcu2SocData);
static uint8_t CalibUnPackData(const tMsgMnger_CalibData*  pstData, tPFOnlineCalibData* pstOnlineData);

/*	=====================================================================
*						   External Func Define
*	===================================================================*/



/*	=====================================================================
*						    Static Func Define
*	===================================================================*/
#define CtrlPara_START_SEC_VAR		// Memory allocation
#include "proj_MemMap.h"

stCalibDataIndex s_stCalibDataIndex = {'B', 4}; //{0};
eCalibDataTransferMode s_eSocGetCalibdataMode = TRANSFER_MODE_NONE;
tPFOnlineCalibData   g_stOnlineCalibData = {0};
OnlineCalibDataIndex g_stOnlineCalibDataIndex;

static int g_CalibDataSendCounter = 0;

#define CtrlPara_STOP_SEC_VAR	// Memory allocation end.
#include "proj_MemMap.h"

void InitCalibGroupIndex()
{
    g_stOnlineCalibDataIndex.a_index = &g_stOnlineCalibData.stPFOnlineCalibData_CarPara_A;
    g_stOnlineCalibDataIndex.b_index = &g_stOnlineCalibData.stPFOnlineCalibData_LatCtrl_B;
    g_stOnlineCalibDataIndex.c_index = &g_stOnlineCalibData.stPFOnlineCalibData_LongiCtr_C;
    g_stOnlineCalibDataIndex.d_index = &g_stOnlineCalibData.stPFOnlineCalibData_SpeedPara_D;
    g_stOnlineCalibDataIndex.e_index = &g_stOnlineCalibData.stPFOnlineCalibData_PebPara_E;
    g_stOnlineCalibDataIndex.f_index = &g_stOnlineCalibData.stPFOnlineCalibData_Headout_F;
    g_stOnlineCalibDataIndex.g_index = &g_stOnlineCalibData.stPFOnlineCalibData_Cruise_G;
}

void setCalibValue(float *valueNeedCalib, const float *value)
{
    *valueNeedCalib = *value;
}

void getCalibValue(const float *valueCalibred, float *value)
{
    *value = *valueCalibred;
}

void handleCalibValue(eCalibDataDirection direct, float *calibValue, float *value)
{
    if(DIRECTION_SOC_TO_MCU == direct)
    {
        setCalibValue(calibValue, value);
    }
    else if(DIRECTION_MCU_TO_SOC == direct)
    {
        getCalibValue(calibValue, value);
    }
}

void Calib_PfOnlieCalibData_Init(const tPFCalibData *pstPfCalibData, tPFOnlineCalibData *pstOnlineCalibData)
{
    InitCalibGroupIndex();

    //A
    pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_f32WhlBase          = pstPfCalibData->stPFVehCalib.Calib_f32WhlBase ;
    pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_f32VehWidthDefault  = pstPfCalibData->stPFVehCalib.Calib_f32VehWidthDefault  ;
    pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_f32ImpuseGap        = pstPfCalibData->stPFVehCalib.Calib_f32ImpuseGap  ;
    pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_f32ImpulseMax       = pstPfCalibData->stPFVehCalib.Calib_f32ImpulseMax  ;
    pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_f32FP0             = pstPfCalibData->stPFCtrlLatCalib.Calib_f32FP0  ;
    pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_f32FP1             = pstPfCalibData->stPFCtrlLatCalib.Calib_f32FP1  ;
    pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_f32FP2             = pstPfCalibData->stPFCtrlLatCalib.Calib_f32FP2  ;
    pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_f32FP3             = pstPfCalibData->stPFCtrlLatCalib.Calib_f32FP3  ;
    pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_f32RP0             = pstPfCalibData->stPFCtrlLatCalib.Calib_f32RP0  ;
    pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_f32RP1             = pstPfCalibData->stPFCtrlLatCalib.Calib_f32RP1  ;
    pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_f32RP2             = pstPfCalibData->stPFCtrlLatCalib.Calib_f32RP2  ;
    pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_f32RP3             = pstPfCalibData->stPFCtrlLatCalib.Calib_f32RP3  ;
    pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Config_f32VerticalParkForceFinish       = pstPfCalibData->stPFAPAFuncConfig.Config_f32VerticalParkForceFinish       ;
    pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Config_f32HorizontalParkForceFinish     = pstPfCalibData->stPFAPAFuncConfig.Config_f32HorizontalParkForceFinish     ;
    pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Config_f32VerticalChockDetectDistance   = pstPfCalibData->stPFAPAFuncConfig.Config_f32VerticalChockDetectDistance   ;
    pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Config_f32HorizontalChockDetectDistance = pstPfCalibData->stPFAPAFuncConfig.Config_f32HorizontalChockDetectDistance ;
    pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Config_i16VerticalChockWaitTime         = pstPfCalibData->stPFAPAFuncConfig.Config_i16VerticalChockWaitTime         ;
    pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Config_i16HorizontalChockWaitTime       = pstPfCalibData->stPFAPAFuncConfig.Config_i16HorizontalChockWaitTime       ;
    pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Config_i16GeneralChockWaitTime          = pstPfCalibData->stPFAPAFuncConfig.Config_i16GeneralChockWaitTime          ;
    pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Config_u16UnknowStopWaitTime            = pstPfCalibData->stPFAPAFuncConfig.Config_u16UnknowStopWaitTime           ;
    pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_f32DrDelayTime      = pstPfCalibData->stPFVehCalib.Calib_f32DrDelayTime  ;
    pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_param_res2          = 0 ;
    pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_param_res3          = 0 ;
    pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_param_res4          = 0 ;
    pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_param_res5          = 0 ;

    //B
    pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32SteerRatioDefault              = pstPfCalibData->stPFCtrlLatCalib.Calib_f32SteerRatioDefault            ;
    pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32SteerLatDistErrGain            = pstPfCalibData->stPFCtrlLatCalib.Calib_f32SteerLatDistErrGain            ;
    pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32SteerLatThetaErrGain           = pstPfCalibData->stPFCtrlLatCalib.Calib_f32SteerLatThetaErrGain           ;
    pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32SteerEndPosDisRate             = pstPfCalibData->stPFCtrlLatCalib.Calib_f32SteerEndPosDisRate             ;
    pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32SteerAngleMax                  = pstPfCalibData->stPFCtrlLatCalib.Calib_f32SteerAngleMax                  ;
    pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32SteerAngleIncreRatioMax        = pstPfCalibData->stPFCtrlLatCalib.Calib_f32SteerAngleIncreRatioMax        ;
    pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32SteerAngleIncreRatioMed        = pstPfCalibData->stPFCtrlLatCalib.Calib_f32SteerAngleIncreRatioMed        ;
    pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_i16LookAheadForwardOffset         = pstPfCalibData->stPFCtrlLatCalib.Calib_i16LookAheadForwardOffset         ;
    pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32SinglePointPreviewKappaLpfDen2 = pstPfCalibData->stPFCtrlLatCalib.Calib_f32SinglePointPreviewKappaLpfDen2 ;
    pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32SinglePointPreviewKappaLpfNum1 = pstPfCalibData->stPFCtrlLatCalib.Calib_f32SinglePointPreviewKappaLpfNum1 ;
    pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32SinglePointPreviewKappaLpfNum2 = pstPfCalibData->stPFCtrlLatCalib.Calib_f32SinglePointPreviewKappaLpfNum2 ;
    pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32MultiPointPreviewKappaLpfDen2  = pstPfCalibData->stPFCtrlLatCalib.Calib_f32MultiPointPreviewKappaLpfDen2  ;
    pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32MultiPointPreviewKappaLpfNum1  = pstPfCalibData->stPFCtrlLatCalib.Calib_f32MultiPointPreviewKappaLpfNum1  ;
    pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32MultiPointPreviewKappaLpfNum2  = pstPfCalibData->stPFCtrlLatCalib.Calib_f32MultiPointPreviewKappaLpfNum2  ;
    pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32DistErrorLpfDen2               = pstPfCalibData->stPFCtrlLatCalib.Calib_f32DistErrorLpfDen2               ;
    pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32DistErrorLpfNum1               = pstPfCalibData->stPFCtrlLatCalib.Calib_f32DistErrorLpfNum1               ;
    pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32DistErrorLpfNum2               = pstPfCalibData->stPFCtrlLatCalib.Calib_f32DistErrorLpfNum2               ;
    pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32ThetaErrorLpfDen2              = pstPfCalibData->stPFCtrlLatCalib.Calib_f32ThetaErrorLpfDen2              ;
    pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32ThetaErrorLpfNum1              = pstPfCalibData->stPFCtrlLatCalib.Calib_f32ThetaErrorLpfNum1              ;
    pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32ThetaErrorLpfNum2              = pstPfCalibData->stPFCtrlLatCalib.Calib_f32ThetaErrorLpfNum2              ;
    pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32TargetSteerLpfDen2             = pstPfCalibData->stPFCtrlLatCalib.Calib_f32TargetSteerLpfDen2             ;
    pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32TargetSteerLpfNum1             = pstPfCalibData->stPFCtrlLatCalib.Calib_f32TargetSteerLpfNum1             ;
    pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32TargetSteerLpfNum2             = pstPfCalibData->stPFCtrlLatCalib.Calib_f32TargetSteerLpfNum2             ;
    pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_lat_res1                          = 0                          ;
    pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_lat_res2                          = 0                          ;
    
    //C
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32CtrlAccKp                      = pstPfCalibData->stPFCtrlLongCalib.Calib_f32CtrlAccKp                      ;
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32CtrlAccKi                      = pstPfCalibData->stPFCtrlLongCalib.Calib_f32CtrlAccKi                      ;
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32CtrlAccKiAntiWindup            = pstPfCalibData->stPFCtrlLongCalib.Calib_f32CtrlAccKiAntiWindup            ;
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32StopSteerToleranceAngle        = pstPfCalibData->stPFCtrlLongCalib.Calib_f32StopSteerToleranceAngle        ;
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32DistanceLeftMin                = pstPfCalibData->stPFCtrlLongCalib.Calib_f32DistanceLeftMin        ;
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32SpeedIncreRatioMax             = pstPfCalibData->stPFCtrlLongCalib.Calib_f32SpeedIncreRatioMax        ;
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32SpeedIncreRatioMed             = pstPfCalibData->stPFCtrlLongCalib.Calib_f32SpeedIncreRatioMed        ;
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32AccIncreRatioMax               = pstPfCalibData->stPFCtrlLongCalib.Calib_f32AccIncreRatioMax        ;
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32AccIncreRatioMed               = pstPfCalibData->stPFCtrlLongCalib.Calib_f32AccIncreRatioMed        ;
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32RegardAsStopSpeed              = pstPfCalibData->stPFCtrlLongCalib.Calib_f32RegardAsStopSpeed        ;
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32SpeedMax                       = pstPfCalibData->stPFCtrlLongCalib.Calib_f32SpeedMax        ;
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32SpeedMin                       = pstPfCalibData->stPFCtrlLongCalib.Calib_f32SpeedMin        ;
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32AccMax                         = pstPfCalibData->stPFCtrlLongCalib.Calib_f32AccMax        ;
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32AccMin                         = pstPfCalibData->stPFCtrlLongCalib.Calib_f32AccMin        ;
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32EmergStopAccMax                = pstPfCalibData->stPFCtrlLongCalib.Calib_f32EmergStopAccMax        ;
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32EmergStopAccMin                = pstPfCalibData->stPFCtrlLongCalib.Calib_f32EmergStopAccMin        ;
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32AccSlopeUpLimit                = pstPfCalibData->stPFCtrlLongCalib.Calib_f32AccSlopeUpLimit        ;
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32AccSlopeLowLimit               = pstPfCalibData->stPFCtrlLongCalib.Calib_f32AccSlopeLowLimit        ;
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32DeAccelSlopeUpLimit            = pstPfCalibData->stPFCtrlLongCalib.Calib_f32DeAccelSlopeUpLimit        ;
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32DeAccelSlopeLowLimit           = pstPfCalibData->stPFCtrlLongCalib.Calib_f32DeAccelSlopeLowLimit        ;

    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32StopAccRq                      = pstPfCalibData->stPFCtrlLongCalib.Calib_f32StopAccRq ;
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32EmergStopAccRq                 = pstPfCalibData->stPFCtrlLongCalib.Calib_f32EmergStopAccRq ;
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_longi_res3                        = 0 ;
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_longi_res4                        = 0 ;
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_longi_res5                        = 0 ;
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_longi_res6                        = 0 ;
    pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_longi_res7                        = 0 ;

    //D
    pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthThreshold1       = pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthThreshold1;
    pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthThreshold2       = pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthThreshold2      ;
    pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthThreshold3       = pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthThreshold3      ;
    pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel1DecelDis   = pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel1DecelDis  ;
    pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel1StopDis    = pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel1StopDis   ;
    pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel1MaxSpeed   = pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel1MaxSpeed  ;
    pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel1InitSpeed  = pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel1InitSpeed ;
    pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel2DecelDis   = pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel2DecelDis  ;
    pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel2StopDis    = pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel2StopDis   ;
    pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel2MaxSpeed   = pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel2MaxSpeed  ;
    pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel2InitSpeed  = pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel2InitSpeed ;
    pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel3DecelDis   = pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel3DecelDis  ;
    pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel3StopDis    = pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel3StopDis   ;
    pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel3MaxSpeed   = pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel3MaxSpeed  ;
    pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel3InitSpeed  = pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel3InitSpeed ;
    pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel4DecelDis   = pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel4DecelDis  ;
    pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel4StopDis    = pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel4StopDis   ;
    pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel4MaxSpeed   = pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel4MaxSpeed  ;
    pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel4InitSpeed  = pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel4InitSpeed ;
    pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32VerticalLastPathDecelDis   = pstPfCalibData->stPFCtrlLongCalib.Calib_f32VerticalLastPathDecelDis  ;
    pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32MechaLastPathMaxSpeed      = pstPfCalibData->stPFCtrlLongCalib.Calib_f32MechaLastPathMaxSpeed     ;
    pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_speed_res1                    = 0 ;
    pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_speed_res2                    = 0 ;
    pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_speed_res3                    = 0 ;
    pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_speed_res4                    = 0 ;

    //E
    pstOnlineCalibData->stPFOnlineCalibData_PebPara_E.Calib_f32PebActive         = pstPfCalibData->stPFPEBCalib.Calib_f32PebActive ;
    pstOnlineCalibData->stPFOnlineCalibData_PebPara_E.Calib_f32PebActiveSide     = pstPfCalibData->stPFPEBCalib.Calib_f32PebActiveSide;
    pstOnlineCalibData->stPFOnlineCalibData_PebPara_E.Calib_f32StopRelativeA     = pstPfCalibData->stPFPEBCalib.Calib_f32StopRelativeA ;
    pstOnlineCalibData->stPFOnlineCalibData_PebPara_E.Calib_f32ReduceRelativeA   = pstPfCalibData->stPFPEBCalib.Calib_f32ReduceRelativeA ;
    pstOnlineCalibData->stPFOnlineCalibData_PebPara_E.Calib_f32ActuatReactTime   = pstPfCalibData->stPFPEBCalib.Calib_f32ActuatReactTime ;
    pstOnlineCalibData->stPFOnlineCalibData_PebPara_E.Calib_f32PebLevel0SafeDit  = pstPfCalibData->stPFPEBCalib.Calib_f32PebLevel0SafeDit ;
    pstOnlineCalibData->stPFOnlineCalibData_PebPara_E.Calib_f32PebLevel1SafeDit  = pstPfCalibData->stPFPEBCalib.Calib_f32PebLevel1SafeDit ;
    pstOnlineCalibData->stPFOnlineCalibData_PebPara_E.Calib_f32PebLevel2SafeDit  = pstPfCalibData->stPFPEBCalib.Calib_f32PebLevel2SafeDit ;

    //F
    pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_f32ThetaLimit           = pstPfCalibData->stPFPkoutCalib.Calib_f32ThetaLimit;
    pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_f32PkoutFrontDisLimit   = pstPfCalibData->stPFPkoutCalib.Calib_f32PkoutFrontDisLimit   ;
    pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_i16SpaceLimit           = pstPfCalibData->stPFPkoutCalib.Calib_i16SpaceLimit           ;
    pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_i16PkoutSideDisLimit    = pstPfCalibData->stPFPkoutCalib.Calib_i16PkoutSideDisLimit    ;
    pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_i16PkoutStraightFrontDisLimit         = pstPfCalibData->stPFPkoutCalib.Calib_i16PkoutStraightFrontDisLimit           ;
    pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_f32ParkoutSpeed         = pstPfCalibData->stPFPkoutCalib.Calib_f32ParkoutSpeed           ;
    pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_headout_res1            = 0 ;
    pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_headout_res2            = 0 ;
    pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_headout_res3            = 0 ;
    pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_headout_res4            = 0 ;
    pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_headout_res5            = 0 ;
    pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_headout_res6            = 0 ;
    pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_headout_res7            = 0 ;
    pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_headout_res8            = 0 ;
    pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_headout_res9            = 0 ;
    pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_PF_freevalue1           = pstPfCalibData->stPFPkoutCalib.Calib_PF_freevalue1 ;
    pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_PF_freevalue2           = pstPfCalibData->stPFPkoutCalib.Calib_PF_freevalue2 ;
    pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_PF_freevalue3           = pstPfCalibData->stPFPkoutCalib.Calib_PF_freevalue3 ;
    pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_PF_freevalue4           = pstPfCalibData->stPFPkoutCalib.Calib_PF_freevalue4 ;
    pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_PF_freevalue5           = pstPfCalibData->stPFPkoutCalib.Calib_PF_freevalue5 ;
    pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_PF_freevalue6           = pstPfCalibData->stPFPkoutCalib.Calib_PF_freevalue6 ;
    pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_PF_freevalue7           = pstPfCalibData->stPFPkoutCalib.Calib_PF_freevalue7 ;
    pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_PF_freevalue8           = pstPfCalibData->stPFPkoutCalib.Calib_PF_freevalue8 ;
    pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_PF_freevalue9           = pstPfCalibData->stPFPkoutCalib.Calib_PF_freevalue9 ;
    pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_PF_freevalue10          = pstPfCalibData->stPFPkoutCalib.Calib_PF_freevalue10 ;

    //G
    pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_f32STOPSPEEDCRUISING                   = pstPfCalibData->stPFCruiseFuncConfig.Calib_f32STOPSPEEDCRUISING        ;
    pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_f32STOPSTEERGAPCRUISING                = pstPfCalibData->stPFCruiseFuncConfig.Calib_f32STOPSTEERGAPCRUISING     ;
    pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_f32STOPACCCRUISING                     = pstPfCalibData->stPFCruiseFuncConfig.Calib_f32STOPACCCRUISING          ;
    pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_f32MAX_LATERRDISCRUISING               = pstPfCalibData->stPFCruiseFuncConfig.Calib_f32MAX_LATERRDISCRUISING    ;
    pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_f32MAX_LATERRHEADINGCRUISING           = pstPfCalibData->stPFCruiseFuncConfig.Calib_f32MAX_LATERRHEADINGCRUISING;
    pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_f32MAX_LONERRCRUISING                  = pstPfCalibData->stPFCruiseFuncConfig.Calib_f32MAX_LONERRCRUISING       ;
    pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_f32LPBANDWIDTHCRUISING                 = pstPfCalibData->stPFCruiseFuncConfig.Calib_f32LPBANDWIDTHCRUISING      ;
    pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_f32K1DISCRUISING                       = pstPfCalibData->stPFCruiseFuncConfig.Calib_f32K1DISCRUISING            ;
    pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_f32K2DOTDISCRUISING                    = pstPfCalibData->stPFCruiseFuncConfig.Calib_f32K2DOTDISCRUISING         ;
    pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_f32K3THETACRUISING                     = pstPfCalibData->stPFCruiseFuncConfig.Calib_f32K3THETACRUISING          ;
    pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_f32K4DOTTHETACRUISING                  = pstPfCalibData->stPFCruiseFuncConfig.Calib_f32K4DOTTHETACRUISING       ;
    pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_cuise_res1              = 0;
    pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_cuise_res2              = 0;
    pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_cuise_res3              = 0;
    pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_cuise_res4              = 0;
    pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_cuise_res5              = 0;
    pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_cuise_res6              = 0;
    pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_cuise_res7              = 0;
    pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_cuise_res8              = 0;
    pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_cuise_res9              = 0;
    pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_cuise_res10             = 0;
    pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_cuise_res11             = 0;
    pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_cuise_res12             = 0;
    pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_cuise_res13             = 0;
    pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_cuise_res14             = 0;

}

void Calib_SyncCalibData(const tPFOnlineCalibData *pstOnlineCalibData, tPFCalibData *pstPfCalibData)
{
    pstPfCalibData->stPFVehCalib.Calib_f32WhlBase          = pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_f32WhlBase         ;
    pstPfCalibData->stPFVehCalib.Calib_f32VehWidthDefault  = pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_f32VehWidthDefault ;
    pstPfCalibData->stPFVehCalib.Calib_f32ImpuseGap        = pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_f32ImpuseGap       ;
    pstPfCalibData->stPFVehCalib.Calib_f32ImpulseMax       = pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_f32ImpulseMax      ;
    pstPfCalibData->stPFDRCalib.Calib_f32FP0              = pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_f32FP0            ;
    pstPfCalibData->stPFDRCalib.Calib_f32FP1              = pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_f32FP1            ;
    pstPfCalibData->stPFDRCalib.Calib_f32FP2              = pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_f32FP2            ;
    pstPfCalibData->stPFDRCalib.Calib_f32RP0              = pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_f32RP0            ;
    pstPfCalibData->stPFDRCalib.Calib_f32RP1              = pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_f32RP1            ;
    pstPfCalibData->stPFDRCalib.Calib_f32RP2              = pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_f32RP2            ;
    pstPfCalibData->stPFDRCalib.Calib_f32RP3              = pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_f32RP3            ;
    pstPfCalibData->stPFAPAFuncConfig.Config_f32VerticalParkForceFinish       = pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Config_f32VerticalParkForceFinish       ;
    pstPfCalibData->stPFAPAFuncConfig.Config_f32HorizontalParkForceFinish     = pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Config_f32HorizontalParkForceFinish     ;
    pstPfCalibData->stPFAPAFuncConfig.Config_f32VerticalChockDetectDistance   = pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Config_f32VerticalChockDetectDistance   ;
    pstPfCalibData->stPFAPAFuncConfig.Config_f32HorizontalChockDetectDistance = pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Config_f32HorizontalChockDetectDistance ;
    pstPfCalibData->stPFAPAFuncConfig.Config_i16VerticalChockWaitTime         = pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Config_i16VerticalChockWaitTime         ;
    pstPfCalibData->stPFAPAFuncConfig.Config_i16HorizontalChockWaitTime       = pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Config_i16HorizontalChockWaitTime       ;
    pstPfCalibData->stPFAPAFuncConfig.Config_i16GeneralChockWaitTime          = pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Config_i16GeneralChockWaitTime          ;
    pstPfCalibData->stPFAPAFuncConfig.Config_u16UnknowStopWaitTime            = pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Config_u16UnknowStopWaitTime            ;
    pstPfCalibData->stPFVehCalib.Calib_f32DrDelayTime                         = pstOnlineCalibData->stPFOnlineCalibData_CarPara_A.Calib_f32DrDelayTime                    ;

    pstPfCalibData->stPFCtrlLatCalib.Calib_f32SteerRatioDefault              = pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32SteerRatioDefault              ;
    pstPfCalibData->stPFCtrlLatCalib.Calib_f32SteerLatThetaErrGain           = pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32SteerLatThetaErrGain           ;
    pstPfCalibData->stPFCtrlLatCalib.Calib_f32SteerEndPosDisRate             = pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32SteerEndPosDisRate             ;
    pstPfCalibData->stPFCtrlLatCalib.Calib_f32SteerAngleMax                  = pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32SteerAngleMax                  ;
    pstPfCalibData->stPFCtrlLatCalib.Calib_f32SteerAngleIncreRatioMax        = pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32SteerAngleIncreRatioMax        ;
    pstPfCalibData->stPFCtrlLatCalib.Calib_f32SteerAngleIncreRatioMed        = pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32SteerAngleIncreRatioMed        ;
    pstPfCalibData->stPFCtrlLatCalib.Calib_i16LookAheadForwardOffset         = pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_i16LookAheadForwardOffset         ;
    pstPfCalibData->stPFCtrlLatCalib.Calib_f32SinglePointPreviewKappaLpfDen2 = pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32SinglePointPreviewKappaLpfDen2 ;
    pstPfCalibData->stPFCtrlLatCalib.Calib_f32SinglePointPreviewKappaLpfNum1 = pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32SinglePointPreviewKappaLpfNum1 ;
    pstPfCalibData->stPFCtrlLatCalib.Calib_f32SinglePointPreviewKappaLpfNum2 = pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32SinglePointPreviewKappaLpfNum2 ;
    pstPfCalibData->stPFCtrlLatCalib.Calib_f32MultiPointPreviewKappaLpfDen2  = pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32MultiPointPreviewKappaLpfDen2  ;
    pstPfCalibData->stPFCtrlLatCalib.Calib_f32MultiPointPreviewKappaLpfNum1  = pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32MultiPointPreviewKappaLpfNum1  ;
    pstPfCalibData->stPFCtrlLatCalib.Calib_f32MultiPointPreviewKappaLpfNum2  = pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32MultiPointPreviewKappaLpfNum2  ;
    pstPfCalibData->stPFCtrlLatCalib.Calib_f32DistErrorLpfDen2               = pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32DistErrorLpfDen2               ;
    pstPfCalibData->stPFCtrlLatCalib.Calib_f32DistErrorLpfNum1               = pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32DistErrorLpfNum1               ;
    pstPfCalibData->stPFCtrlLatCalib.Calib_f32DistErrorLpfNum2               = pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32DistErrorLpfNum2               ;
    pstPfCalibData->stPFCtrlLatCalib.Calib_f32ThetaErrorLpfDen2              = pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32ThetaErrorLpfDen2              ;
    pstPfCalibData->stPFCtrlLatCalib.Calib_f32ThetaErrorLpfNum1              = pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32ThetaErrorLpfNum1              ;
    pstPfCalibData->stPFCtrlLatCalib.Calib_f32ThetaErrorLpfNum2              = pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32ThetaErrorLpfNum2              ;
    pstPfCalibData->stPFCtrlLatCalib.Calib_f32TargetSteerLpfDen2             = pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32TargetSteerLpfDen2             ;
    pstPfCalibData->stPFCtrlLatCalib.Calib_f32TargetSteerLpfNum1             = pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32TargetSteerLpfNum1             ;
    pstPfCalibData->stPFCtrlLatCalib.Calib_f32TargetSteerLpfNum2             = pstOnlineCalibData->stPFOnlineCalibData_LatCtrl_B.Calib_f32TargetSteerLpfNum2             ;


    pstPfCalibData->stPFCtrlLongCalib.Calib_f32CtrlAccKp                      = pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32CtrlAccKp                      ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32CtrlAccKi                      = pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32CtrlAccKi                      ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32CtrlAccKiAntiWindup            = pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32CtrlAccKiAntiWindup            ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32StopSteerToleranceAngle        = pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32StopSteerToleranceAngle        ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32DistanceLeftMin                = pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32DistanceLeftMin             ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32SpeedIncreRatioMax             = pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32SpeedIncreRatioMax          ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32SpeedIncreRatioMed             = pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32SpeedIncreRatioMed          ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32AccIncreRatioMax               = pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32AccIncreRatioMax            ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32AccIncreRatioMed               = pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32AccIncreRatioMed            ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32RegardAsStopSpeed              = pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32RegardAsStopSpeed           ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32SpeedMax                       = pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32SpeedMax                    ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32SpeedMin                       = pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32SpeedMin                    ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32AccMax                         = pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32AccMax                      ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32AccMin                         = pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32AccMin                      ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32EmergStopAccMax                = pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32EmergStopAccMax                      ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32EmergStopAccMin                = pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32EmergStopAccMin                      ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32AccSlopeUpLimit                = pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32AccSlopeUpLimit             ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32AccSlopeLowLimit               = pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32AccSlopeLowLimit            ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32DeAccelSlopeUpLimit            = pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32DeAccelSlopeUpLimit         ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32DeAccelSlopeLowLimit           = pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32DeAccelSlopeLowLimit        ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32StopAccRq                      = pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32StopAccRq        ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32EmergStopAccRq                 = pstOnlineCalibData->stPFOnlineCalibData_LongiCtr_C.Calib_f32EmergStopAccRq        ;

    pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthThreshold1      = pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthThreshold1      ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthThreshold2      = pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthThreshold2      ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthThreshold3      = pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthThreshold3      ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel1DecelDis  = pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel1DecelDis  ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel1StopDis   = pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel1StopDis   ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel1MaxSpeed  = pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel1MaxSpeed  ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel1InitSpeed = pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel1InitSpeed ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel2DecelDis  = pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel2DecelDis  ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel2StopDis   = pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel2StopDis   ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel2MaxSpeed  = pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel2MaxSpeed  ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel2InitSpeed = pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel2InitSpeed ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel3DecelDis  = pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel3DecelDis  ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel3StopDis   = pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel3StopDis   ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel3MaxSpeed  = pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel3MaxSpeed  ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel3InitSpeed = pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel3InitSpeed ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel4DecelDis  = pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel4DecelDis  ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel4StopDis   = pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel4StopDis   ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel4MaxSpeed  = pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel4MaxSpeed  ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32PathLengthLevel4InitSpeed = pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32PathLengthLevel4InitSpeed ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32VerticalLastPathDecelDis  = pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32VerticalLastPathDecelDis  ;
    pstPfCalibData->stPFCtrlLongCalib.Calib_f32MechaLastPathMaxSpeed     = pstOnlineCalibData->stPFOnlineCalibData_SpeedPara_D.Calib_f32MechaLastPathMaxSpeed     ;

    pstPfCalibData->stPFPEBCalib.Calib_f32PebActive            = pstOnlineCalibData->stPFOnlineCalibData_PebPara_E.Calib_f32PebActive;
    pstPfCalibData->stPFPEBCalib.Calib_f32PebActiveSide        = pstOnlineCalibData->stPFOnlineCalibData_PebPara_E.Calib_f32PebActiveSide;
    pstPfCalibData->stPFPEBCalib.Calib_f32StopRelativeA        = pstOnlineCalibData->stPFOnlineCalibData_PebPara_E.Calib_f32StopRelativeA;
    pstPfCalibData->stPFPEBCalib.Calib_f32ReduceRelativeA      = pstOnlineCalibData->stPFOnlineCalibData_PebPara_E.Calib_f32ReduceRelativeA;
    pstPfCalibData->stPFPEBCalib.Calib_f32ActuatReactTime      = pstOnlineCalibData->stPFOnlineCalibData_PebPara_E.Calib_f32ActuatReactTime;
    pstPfCalibData->stPFPEBCalib.Calib_f32PebLevel0SafeDit     = pstOnlineCalibData->stPFOnlineCalibData_PebPara_E.Calib_f32PebLevel0SafeDit;
    pstPfCalibData->stPFPEBCalib.Calib_f32PebLevel1SafeDit     = pstOnlineCalibData->stPFOnlineCalibData_PebPara_E.Calib_f32PebLevel1SafeDit;
    pstPfCalibData->stPFPEBCalib.Calib_f32PebLevel2SafeDit     = pstOnlineCalibData->stPFOnlineCalibData_PebPara_E.Calib_f32PebLevel2SafeDit;

    //headout
    pstPfCalibData->stPFPkoutCalib.Calib_f32ThetaLimit                  = pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_f32ThetaLimit                    ;
    pstPfCalibData->stPFPkoutCalib.Calib_f32PkoutFrontDisLimit          = pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_f32PkoutFrontDisLimit            ;
    pstPfCalibData->stPFPkoutCalib.Calib_i16SpaceLimit                  = pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_i16SpaceLimit                    ;
    pstPfCalibData->stPFPkoutCalib.Calib_i16PkoutSideDisLimit           = pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_i16PkoutSideDisLimit             ;
    pstPfCalibData->stPFPkoutCalib.Calib_i16PkoutStraightFrontDisLimit  = pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_i16PkoutStraightFrontDisLimit    ;
    pstPfCalibData->stPFPkoutCalib.Calib_f32ParkoutSpeed                = pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_f32ParkoutSpeed                  ;
    
    pstPfCalibData->stPFPkoutCalib.Calib_PF_freevalue1                = pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_PF_freevalue1                      ;
    pstPfCalibData->stPFPkoutCalib.Calib_PF_freevalue2                = pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_PF_freevalue2                      ;
    pstPfCalibData->stPFPkoutCalib.Calib_PF_freevalue3                = pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_PF_freevalue3                      ;
    pstPfCalibData->stPFPkoutCalib.Calib_PF_freevalue4                = pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_PF_freevalue4                      ;
    pstPfCalibData->stPFPkoutCalib.Calib_PF_freevalue5                = pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_PF_freevalue5                      ;
    pstPfCalibData->stPFPkoutCalib.Calib_PF_freevalue6                = pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_PF_freevalue6                      ;
    pstPfCalibData->stPFPkoutCalib.Calib_PF_freevalue7                = pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_PF_freevalue7                      ;
    pstPfCalibData->stPFPkoutCalib.Calib_PF_freevalue8                = pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_PF_freevalue8                      ;
    pstPfCalibData->stPFPkoutCalib.Calib_PF_freevalue9                = pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_PF_freevalue9                      ;
    pstPfCalibData->stPFPkoutCalib.Calib_PF_freevalue10               = pstOnlineCalibData->stPFOnlineCalibData_Headout_F.Calib_PF_freevalue10                      ;

    //cruise
    pstPfCalibData->stPFCruiseFuncConfig.Calib_f32STOPSPEEDCRUISING             = pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_f32STOPSPEEDCRUISING               ;
    pstPfCalibData->stPFCruiseFuncConfig.Calib_f32STOPSTEERGAPCRUISING          = pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_f32STOPSTEERGAPCRUISING            ;
    pstPfCalibData->stPFCruiseFuncConfig.Calib_f32STOPACCCRUISING               = pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_f32STOPACCCRUISING                 ;
    pstPfCalibData->stPFCruiseFuncConfig.Calib_f32MAX_LATERRDISCRUISING         = pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_f32MAX_LATERRDISCRUISING           ;
    pstPfCalibData->stPFCruiseFuncConfig.Calib_f32MAX_LATERRHEADINGCRUISING     = pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_f32MAX_LATERRHEADINGCRUISING       ;
    pstPfCalibData->stPFCruiseFuncConfig.Calib_f32MAX_LONERRCRUISING            = pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_f32MAX_LONERRCRUISING              ;
    pstPfCalibData->stPFCruiseFuncConfig.Calib_f32LPBANDWIDTHCRUISING           = pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_f32LPBANDWIDTHCRUISING             ;
    pstPfCalibData->stPFCruiseFuncConfig.Calib_f32K1DISCRUISING                 = pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_f32K1DISCRUISING                   ;
    pstPfCalibData->stPFCruiseFuncConfig.Calib_f32K2DOTDISCRUISING              = pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_f32K2DOTDISCRUISING                ;
    pstPfCalibData->stPFCruiseFuncConfig.Calib_f32K3THETACRUISING               = pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_f32K3THETACRUISING                 ;
    pstPfCalibData->stPFCruiseFuncConfig.Calib_f32K4DOTTHETACRUISING            = pstOnlineCalibData->stPFOnlineCalibData_Cruise_G.Calib_f32K4DOTTHETACRUISING              ;

}

float Calib_IdToData(char groupId, int id, float value, eCalibDataDirection direct)
{
    float value_calibrated  = 0.0f;

    if(DIRECTION_SOC_TO_MCU == direct)
    {
        switch(groupId)
        {
            case 'A':
                g_stOnlineCalibDataIndex.a_index[id] = value;
                break;
            case 'B':
                g_stOnlineCalibDataIndex.b_index[id] = value;
                break;
            case 'C':
                g_stOnlineCalibDataIndex.c_index[id] = value;
                break;
            case 'D':
                g_stOnlineCalibDataIndex.d_index[id] = value;
                break;
            case 'E':
                g_stOnlineCalibDataIndex.e_index[id] = value;
                break;
            case 'F':
                g_stOnlineCalibDataIndex.f_index[id] = value;
                break;
            case 'G':
                g_stOnlineCalibDataIndex.g_index[id] = value;
                break;

            default:
                break;
        }
    }
    else if(DIRECTION_MCU_TO_SOC == direct)
    {
        switch(groupId)
        {
            case 'A':
                value_calibrated = g_stOnlineCalibDataIndex.a_index[id];
                break;
            case 'B':
                value_calibrated = g_stOnlineCalibDataIndex.b_index[id];
                break;
            case 'C':
                value_calibrated = g_stOnlineCalibDataIndex.c_index[id];
                break;
            case 'D':
                value_calibrated = g_stOnlineCalibDataIndex.d_index[id];
                break;
            case 'E':
                value_calibrated = g_stOnlineCalibDataIndex.e_index[id];
                break;
            case 'F':
                value_calibrated = g_stOnlineCalibDataIndex.f_index[id];
                break;
            case 'G':
                value_calibrated = g_stOnlineCalibDataIndex.g_index[id];
                break;
            default:
                break;
        }
    }

    return value_calibrated;

}


static uint8_t CalibUnPackData(const tMsgMnger_CalibData*  pstData, tPFOnlineCalibData* pstOnlineData)
{
    float value     = 0; 

    if(pstData->u8Direction != DIRECTION_SOC_TO_MCU)
    {
        return E_NOT_OK;
    }
    
    if(pstData->u8Mode == TRANSFER_MODE_SINGLE)
    {
        value = pstData->f32Value[0];
        Calib_IdToData(pstData->u8GroupId, pstData->u8Id - 1, value, DIRECTION_SOC_TO_MCU);
        Calib_SyncCalibData(pstOnlineData, &g_stCalibData);
    }
    else if(pstData->u8Mode == TRANSFER_MODE_GROUP)
    {
        for(int i = 0; i<25; i++)
        {
            value = pstData->f32Value[i];
            Calib_IdToData(pstData->u8GroupId, i, value, DIRECTION_SOC_TO_MCU);
        }
        Calib_SyncCalibData(pstOnlineData, &g_stCalibData);
    }
    else if( pstData->u8Mode == TRANSFER_MODE_GET_GROUP )
    {
         //send to soc
        s_eSocGetCalibdataMode     = TRANSFER_MODE_GET_GROUP;
        s_stCalibDataIndex.groupId = pstData->u8GroupId;
        s_stCalibDataIndex.id      = 0;
        g_CalibDataSendCounter     = 2;
    }
    else if( pstData->u8Mode == TRANSFER_MODE_GET_ALL_GROUP )
    {
        s_eSocGetCalibdataMode = TRANSFER_MODE_GET_ALL_GROUP;
        g_CalibDataSendCounter = 2*(GROUP_END_ID - GROUP_START_ID);
    }

    return E_OK;
}

static uint8_t CalibPackData(tPFOnlineCalibData* pstCalibOnlineData, tMsgMnger_CalibData* pstCalibMcu2SocData)
{
    #define CtrlPara_START_SEC_VAR		// Memory allocation
    #include "proj_MemMap.h"

    // --- to put into the global variable. 
    static char sendGroup = GROUP_START_ID;

    #define CtrlPara_STOP_SEC_VAR	// Memory allocation end.
    #include "proj_MemMap.h"
    
    float value;
    
    pstCalibMcu2SocData->u8Direction = DIRECTION_MCU_TO_SOC;

    if(TRANSFER_MODE_GET_GROUP == s_eSocGetCalibdataMode)
    {
        if(TRANSFER_MODE_GROUP == TRANSFER_MODE_CONFIG)
        {
            pstCalibMcu2SocData->u8Mode    = TRANSFER_MODE_GROUP;
            pstCalibMcu2SocData->u8GroupId = s_stCalibDataIndex.groupId;
            pstCalibMcu2SocData->u8Id      = 0;

            for (uint8_t i = 0; i < CALIB_ONLINE_NUM_PER_GROUP; i++)
            {
                value = Calib_IdToData(pstCalibMcu2SocData->u8GroupId, i, 0, DIRECTION_MCU_TO_SOC);
                pstCalibMcu2SocData->f32Value[i] = value;
            }
        }
    }
    else if(TRANSFER_MODE_GET_ALL_GROUP == s_eSocGetCalibdataMode)
    {
        if(TRANSFER_MODE_GROUP == TRANSFER_MODE_CONFIG)
        {
            pstCalibMcu2SocData->u8Mode    = TRANSFER_MODE_GROUP;
            pstCalibMcu2SocData->u8GroupId = sendGroup;
            pstCalibMcu2SocData->u8Id      = 0;

            for (uint8_t i = 0; i < CALIB_ONLINE_NUM_PER_GROUP; i++)
            {
                value = Calib_IdToData(sendGroup, i, 0, DIRECTION_MCU_TO_SOC);
                pstCalibMcu2SocData->f32Value[i] = value;
            }

            sendGroup++;
            if(GROUP_END_ID < sendGroup)
            {
                sendGroup = GROUP_START_ID;
            }
        }
        else if(TRANSFER_MODE_SINGLE == TRANSFER_MODE_CONFIG)
        {
            if(s_stCalibDataIndex.groupId == 0) return E_OK;

            pstCalibMcu2SocData->u8Mode    = TRANSFER_MODE_SINGLE;
            pstCalibMcu2SocData->u8GroupId = s_stCalibDataIndex.groupId;
            pstCalibMcu2SocData->u8Id      = s_stCalibDataIndex.id - 1;
            value = Calib_IdToData(pstCalibMcu2SocData->u8GroupId, pstCalibMcu2SocData->u8Id, 0, DIRECTION_MCU_TO_SOC);
            pstCalibMcu2SocData->f32Value[0] = value;
        }
        else
        {
        }
    }

    return E_OK;
}


uint8_t  CalibOnlineProcess(void)
{
    #define CtrlPara_START_SEC_VAR		// Memory allocation
    #include "proj_MemMap.h"

    // --- to put into the global variable. 
    static uint64 preReceiveTimestamp = 0;
    static uint64 calibCount = 5;

    #define CtrlPara_STOP_SEC_VAR	// Memory allocation end.
    #include "proj_MemMap.h"

    calibCount--;
    if(calibCount > 0)
    {
        return E_OK;
    }
    calibCount = 5;

    Rte_Read_MsgManager_ModifyCalib(&g_stCalibSoc2McuData);
    
    if(preReceiveTimestamp != g_stCalibSoc2McuData.u64Timestamp_us && 0 != preReceiveTimestamp)
    {
        CalibMcuRecvSocData(&g_stCalibSoc2McuData, &g_stOnlineCalibData);
    }
    else
    {

    }
    preReceiveTimestamp = g_stCalibSoc2McuData.u64Timestamp_us;


    if(TRANSFER_MODE_NONE == s_eSocGetCalibdataMode || g_CalibDataSendCounter == 0)
    {
        return E_OK;
    }

    g_CalibDataSendCounter--;
    memset(&g_stCalibMcu2SocData, 0x0, sizeof(g_stCalibMcu2SocData));
    CalibMcuSendSocData(&g_stOnlineCalibData, &g_stCalibMcu2SocData);

    g_stCalibMcu2SocData.u64Timestamp_us = SysTm_GetUnixTimestamp_us();
    Rte_Write_MsgManager_McuCalib(&g_stCalibMcu2SocData);
 
    return E_OK;
}


static uint8_t CalibMcuSendSocData( tPFOnlineCalibData*         pstCalibOnlineData,
                                     tMsgMnger_CalibData*  pstCalibMcu2SocData)
{
    CalibPackData(pstCalibOnlineData, pstCalibMcu2SocData);

    return E_OK;
}


static uint8_t CalibMcuRecvSocData(const tMsgMnger_CalibData*  stCalibSoc2McuData,
                                   tPFOnlineCalibData*                pstOnlineCalib)
{
    CalibUnPackData(stCalibSoc2McuData, pstOnlineCalib);

    return E_OK;
}

