#include "vehicle_service/calib/vehsrv_calib_data.h"
#include "vehicle_service/calib/online/online_calib_algo.h"
#include "adas_project_input.h"

/*	=====================================================================
*						        Staic var
*	===================================================================*/
#define CtrlPara_START_SEC_VAR		// Memory allocation
#include "proj_MemMap.h"

tPFCalibData g_stCalibData;

#define CtrlPara_STOP_SEC_VAR	// Memory allocation end.
#include "proj_MemMap.h"

uint8_t VehSrv_CalibInitData()
{
    
    #include "calib.cfg"

    #if (SIMULATION_PRESCAN_MCU == 1)
    g_stCalibData.stPFVehCalib.Calib_f32WhlBase                     = 2.610f;
    g_stCalibData.stPFVehCalib.Calib_f32VehWidthDefault             = 1.615f;
    #endif

    Calib_PfOnlieCalibData_Init(&g_stCalibData, &g_stOnlineCalibData);

	return E_OK;
}



tPFCalibData* VehSrv_GetCalibData(void) 
{
    return &g_stCalibData;
}

uint8_t VehSrv_CalibInitDataFromCfm()
{
    int valueInt;
    float valueFloat;

    //CarPara
    if(0 == cfm_get_float("PF_A01", &valueFloat))
    {
        g_stCalibData.stPFVehCalib.Calib_f32WhlBase = valueFloat;
    }
    if(0 == cfm_get_float("PF_A02", &valueFloat))
    {
        g_stCalibData.stPFVehCalib.Calib_f32VehWidthDefault = valueFloat;
    }
    if(0 == cfm_get_float("PF_A03", &valueFloat))
    {
        g_stCalibData.stPFVehCalib.Calib_f32ImpuseGap = valueFloat;
    }
    if(0 == cfm_get_float("PF_A04", &valueFloat))
    {
        g_stCalibData.stPFVehCalib.Calib_f32ImpulseMax = valueFloat;
    }   
    if(0 == cfm_get_float("PF_A05", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32FP0 = valueFloat;
    }
    if(0 == cfm_get_float("PF_A06", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32FP1 = valueFloat;
    }    
    if(0 == cfm_get_float("PF_A07", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32FP2 = valueFloat;
    }
    if(0 == cfm_get_float("PF_A08", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32FP3 = valueFloat;
    }
    if(0 == cfm_get_float("PF_A09", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32RP0 = valueFloat;
    }
    if(0 == cfm_get_float("PF_A10", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32RP1 = valueFloat;
    }
    if(0 == cfm_get_float("PF_A11", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32RP2 = valueFloat;
    }
    if(0 == cfm_get_float("PF_A12", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32RP3 = valueFloat;
    } 
    if(0 == cfm_get_float("PF_A13", &valueFloat))
    {
        g_stCalibData.stPFAPAFuncConfig.Config_f32VerticalParkForceFinish = valueFloat;
    }
    if(0 == cfm_get_float("PF_A14", &valueFloat))
    {
        g_stCalibData.stPFAPAFuncConfig.Config_f32HorizontalParkForceFinish = valueFloat;
    }
    if(0 == cfm_get_float("PF_A15", &valueFloat))
    {
        g_stCalibData.stPFAPAFuncConfig.Config_f32VerticalChockDetectDistance = valueFloat;
    }
    if(0 == cfm_get_float("PF_A16", &valueFloat))
    {
        g_stCalibData.stPFAPAFuncConfig.Config_f32HorizontalChockDetectDistance = valueFloat;
    }
    if(0 == cfm_get_int("PF_A17", &valueInt))
    {
        g_stCalibData.stPFAPAFuncConfig.Config_i16VerticalChockWaitTime = (int16_t)valueInt;
    }
    if(0 == cfm_get_int("PF_A18", &valueInt))
    {
        g_stCalibData.stPFAPAFuncConfig.Config_i16HorizontalChockWaitTime = (int16_t)valueInt;
    }
    if(0 == cfm_get_int("PF_A19", &valueInt))
    {
        g_stCalibData.stPFAPAFuncConfig.Config_i16GeneralChockWaitTime = (int16_t)valueInt;
    }
    if(0 == cfm_get_int("PF_A20", &valueInt))
    {
        g_stCalibData.stPFAPAFuncConfig.Config_u16UnknowStopWaitTime = (uint16_t)valueInt;
    }
    if(0 == cfm_get_float("PF_A21", &valueFloat))
    {
        g_stCalibData.stPFVehCalib.Calib_f32DrDelayTime = valueFloat;
    }
    // reserve
    // if(0 == cfm_get_float("PF_A22", &valueFloat))
    // {
        
    // }
    // if(0 == cfm_get_float("PF_A23", &valueFloat))
    // {
        
    // }
    // if(0 == cfm_get_float("PF_A24", &valueFloat))
    // {
        
    // }
    // if(0 == cfm_get_float("PF_A25", &valueFloat))
    // {
        
    // }


    //LatCtrl
    if(0 == cfm_get_float("PF_B01", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32SteerRatioDefault = valueFloat;
    }
    if(0 == cfm_get_float("PF_B02", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32SteerLatDistErrGain = valueFloat;
    }
    if(0 == cfm_get_float("PF_B03", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32SteerLatThetaErrGain = valueFloat;
    }
    if(0 == cfm_get_float("PF_B04", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32SteerEndPosDisRate = valueFloat;
    }
    if(0 == cfm_get_float("PF_B05", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32SteerAngleMax = valueFloat;
    }
    if(0 == cfm_get_float("PF_B06", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32SteerAngleIncreRatioMax = valueFloat;
    } 
    if(0 == cfm_get_float("PF_B07", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32SteerAngleIncreRatioMed = valueFloat;
    }  
    if(0 == cfm_get_int("PF_B08", &valueInt))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_i16LookAheadForwardOffset = (int16_t)valueInt;
    }  
    if(0 == cfm_get_float("PF_B09", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32SinglePointPreviewKappaLpfDen2 = valueFloat;
    } 
    if(0 == cfm_get_float("PF_B10", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32SinglePointPreviewKappaLpfNum1 = valueFloat;
    }
    if(0 == cfm_get_float("PF_B11", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32SinglePointPreviewKappaLpfNum2 = valueFloat;
    } 
    if(0 == cfm_get_float("PF_B12", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32MultiPointPreviewKappaLpfDen2 = valueFloat;
    }
    if(0 == cfm_get_float("PF_B13", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32MultiPointPreviewKappaLpfNum1 = valueFloat;
    }
    if(0 == cfm_get_float("PF_B14", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32MultiPointPreviewKappaLpfNum2 = valueFloat;
    }
    if(0 == cfm_get_float("PF_B15", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32DistErrorLpfDen2 = valueFloat;
    }
    if(0 == cfm_get_float("PF_B16", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32DistErrorLpfNum1 = valueFloat;
    }
    if(0 == cfm_get_float("PF_B17", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32DistErrorLpfNum2 = valueFloat;
    }
    if(0 == cfm_get_float("PF_B18", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32ThetaErrorLpfDen2 = valueFloat;
    }
    if(0 == cfm_get_float("PF_B19", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32ThetaErrorLpfNum1 = valueFloat;
    }
    if(0 == cfm_get_float("PF_B20", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32ThetaErrorLpfNum2 = valueFloat;
    } 
    if(0 == cfm_get_float("PF_B21", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32TargetSteerLpfDen2 = valueFloat;
    } 
    if(0 == cfm_get_float("PF_B22", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32TargetSteerLpfNum1 = valueFloat;
    }
    if(0 == cfm_get_float("PF_B23", &valueFloat))
    {
        g_stCalibData.stPFCtrlLatCalib.Calib_f32TargetSteerLpfNum2 = valueFloat;
    }
    // reserve
    // if(0 == cfm_get_float("PF_B24", &valueFloat))
    // {
        
    // }  
    // if(0 == cfm_get_float("PF_B25", &valueFloat))
    // {
        
    // }


    //LongiCtrl
    if(0 == cfm_get_float("PF_C01", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32CtrlAccKp = valueFloat;
    }
    if(0 == cfm_get_float("PF_C02", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32CtrlAccKi = valueFloat;
    }
    if(0 == cfm_get_float("PF_C03", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32CtrlAccKiAntiWindup = valueFloat;
    }
    if(0 == cfm_get_float("PF_C04", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32StopSteerToleranceAngle = valueFloat;
    }
    if(0 == cfm_get_float("PF_C05", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32DistanceLeftMin = valueFloat;
    }
    if(0 == cfm_get_float("PF_C06", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32SpeedIncreRatioMax = valueFloat;
    }
    if(0 == cfm_get_float("PF_C07", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32SpeedIncreRatioMed = valueFloat;
    } 
    if(0 == cfm_get_float("PF_C08", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32AccIncreRatioMax = valueFloat;
    } 
    if(0 == cfm_get_float("PF_C09", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32AccIncreRatioMed = valueFloat;
    } 
    if(0 == cfm_get_float("PF_C10", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32RegardAsStopSpeed = valueFloat;
    } 
    if(0 == cfm_get_float("PF_C11", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32SpeedMax = valueFloat;
    } 
    if(0 == cfm_get_float("PF_C12", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32SpeedMin = valueFloat;
    }
    if(0 == cfm_get_float("PF_C13", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32AccMax = valueFloat;
    } 
    if(0 == cfm_get_float("PF_C14", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32AccMin = valueFloat;
    }
    if(0 == cfm_get_float("PF_C13", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32EmergStopAccMax = valueFloat;
    } 
    if(0 == cfm_get_float("PF_C14", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32EmergStopAccMin = valueFloat;
    }
    if(0 == cfm_get_float("PF_C15", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32AccSlopeUpLimit = valueFloat;
    }
    if(0 == cfm_get_float("PF_C16", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32AccSlopeLowLimit = valueFloat;
    }
    if(0 == cfm_get_float("PF_C17", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32DeAccelSlopeUpLimit = valueFloat;
    } 
    if(0 == cfm_get_float("PF_C18", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32DeAccelSlopeLowLimit = valueFloat;
    }
    if(0 == cfm_get_float("PF_C19", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32StopAccRq = valueFloat;
    }
    if(0 == cfm_get_float("PF_C20", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32EmergStopAccRq = valueFloat;
    }
    // reserve    
    // if(0 == cfm_get_float("PF_C21", &valueFloat))
    // {

    // }
    // if(0 == cfm_get_float("PF_C22", &valueFloat))
    // {

    // }
    // if(0 == cfm_get_float("PF_C23", &valueFloat))
    // {

    // }
    // if(0 == cfm_get_float("PF_C24", &valueFloat))
    // {

    // }
    // if(0 == cfm_get_float("PF_C25", &valueFloat))
    // {

    // }


    //SpeedPara
    if(0 == cfm_get_float("PF_D01", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32PathLengthThreshold1 = valueFloat;
    }
    if(0 == cfm_get_float("PF_D02", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32PathLengthThreshold2 = valueFloat;
    }  
    if(0 == cfm_get_float("PF_D03", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32PathLengthThreshold3 = valueFloat;
    } 
    if(0 == cfm_get_float("PF_D04", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32PathLengthLevel1DecelDis = valueFloat;
    } 
    if(0 == cfm_get_float("PF_D05", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32PathLengthLevel1StopDis = valueFloat;
    }
    if(0 == cfm_get_float("PF_D06", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32PathLengthLevel1MaxSpeed = valueFloat;
    } 
    if(0 == cfm_get_float("PF_D07", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32PathLengthLevel1InitSpeed = valueFloat;
    }
    if(0 == cfm_get_float("PF_D08", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32PathLengthLevel2DecelDis = valueFloat;
    }
    if(0 == cfm_get_float("PF_D09", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32PathLengthLevel2StopDis = valueFloat;
    }
    if(0 == cfm_get_float("PF_D10", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32PathLengthLevel2MaxSpeed = valueFloat;
    }
    if(0 == cfm_get_float("PF_D11", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32PathLengthLevel2InitSpeed = valueFloat;
    } 
    if(0 == cfm_get_float("PF_D12", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32PathLengthLevel3DecelDis = valueFloat;
    }
    if(0 == cfm_get_float("PF_D13", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32PathLengthLevel3StopDis = valueFloat;
    } 
    if(0 == cfm_get_float("PF_D14", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32PathLengthLevel3MaxSpeed = valueFloat;
    } 
    if(0 == cfm_get_float("PF_D15", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32PathLengthLevel3InitSpeed = valueFloat;
    } 
    if(0 == cfm_get_float("PF_D16", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32PathLengthLevel4DecelDis = valueFloat;
    }
    if(0 == cfm_get_float("PF_D17", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32PathLengthLevel4StopDis = valueFloat;
    }
    if(0 == cfm_get_float("PF_D18", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32PathLengthLevel4MaxSpeed = valueFloat;
    }
    if(0 == cfm_get_float("PF_D19", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32PathLengthLevel4InitSpeed = valueFloat;
    }
    if(0 == cfm_get_float("PF_D20", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32VerticalLastPathDecelDis = valueFloat;
    }
    if(0 == cfm_get_float("PF_D21", &valueFloat))
    {
        g_stCalibData.stPFCtrlLongCalib.Calib_f32MechaLastPathMaxSpeed = valueFloat;
    } 
    // reserve
    // if(0 == cfm_get_float("PF_D22", &valueFloat))
    // {
  
    // } 
    // if(0 == cfm_get_float("PF_D23", &valueFloat))
    // {
  
    // } 
    // if(0 == cfm_get_float("PF_D24", &valueFloat))
    // {
  
    // } 
    // if(0 == cfm_get_float("PF_D25", &valueFloat))
    // {
  
    // } 


    //PebPara
    if(0 == cfm_get_float("PF_E01", &valueFloat))
    {
        g_stCalibData.stPFPEBCalib.Calib_f32PebActive = valueFloat;  
    }
    if(0 == cfm_get_float("PF_E02", &valueFloat))
    {
        g_stCalibData.stPFPEBCalib.Calib_f32PebActiveSide = valueFloat;
    } 
    if(0 == cfm_get_float("PF_E03", &valueFloat))
    {
        g_stCalibData.stPFPEBCalib.Calib_f32StopRelativeA = valueFloat;
    }
    if(0 == cfm_get_float("PF_E04", &valueFloat))
    {
        g_stCalibData.stPFPEBCalib.Calib_f32ReduceRelativeA = valueFloat;
    }
    if(0 == cfm_get_float("PF_E05", &valueFloat))
    {
        g_stCalibData.stPFPEBCalib.Calib_f32ActuatReactTime = valueFloat;
    }
    if(0 == cfm_get_float("PF_E06", &valueFloat))
    {
        g_stCalibData.stPFPEBCalib.Calib_f32PebLevel0SafeDit = valueFloat;
    }
    if(0 == cfm_get_float("PF_E07", &valueFloat))
    {
        g_stCalibData.stPFPEBCalib.Calib_f32PebLevel1SafeDit = valueFloat;
    } 
    if(0 == cfm_get_float("PF_E07", &valueFloat))
    {
        g_stCalibData.stPFPEBCalib.Calib_f32PebLevel2SafeDit = valueFloat;
    } 


    //HeadoutPara
    if(0 == cfm_get_float("PF_F01", &valueFloat))
    {
        g_stCalibData.stPFPkoutCalib.Calib_f32ThetaLimit = valueFloat;
    } 
    if(0 == cfm_get_float("PF_F02", &valueFloat))
    {
        g_stCalibData.stPFPkoutCalib.Calib_f32PkoutFrontDisLimit = valueFloat;
    } 
    if(0 == cfm_get_int("PF_F03", &valueInt))
    {
        g_stCalibData.stPFPkoutCalib.Calib_i16SpaceLimit = (int16_t)valueInt;
    }  
    if(0 == cfm_get_int("PF_F04", &valueInt))
    {
        g_stCalibData.stPFPkoutCalib.Calib_i16PkoutSideDisLimit = (int16_t)valueInt;
    }
    if(0 == cfm_get_int("PF_F05", &valueInt))
    {
        g_stCalibData.stPFPkoutCalib.Calib_i16PkoutStraightFrontDisLimit = (int16_t)valueInt;
    }
    if(0 == cfm_get_float("PF_F06", &valueFloat))
    {
        g_stCalibData.stPFPkoutCalib.Calib_f32ParkoutSpeed = valueFloat;
    } 
    // reserve
    // if(0 == cfm_get_float("PF_F07", &valueFloat))
    // {
        
    // } 
    // if(0 == cfm_get_float("PF_F08", &valueFloat))
    // {
       
    // } 
    // if(0 == cfm_get_float("PF_F09", &valueFloat))
    // {
        
    // } 
    // if(0 == cfm_get_float("PF_F10", &valueFloat))
    // {
       
    // } 


    //CruisePara
    if(0 == cfm_get_float("PF_G01", &valueFloat))
    {
        g_stCalibData.stPFCruiseFuncConfig.Calib_f32STOPSPEEDCRUISING = valueFloat;
    } 
    if(0 == cfm_get_float("PF_G02", &valueFloat))
    {
        g_stCalibData.stPFCruiseFuncConfig.Calib_f32STOPSTEERGAPCRUISING = valueFloat;
    } 
    if(0 == cfm_get_float("PF_G03", &valueFloat))
    {
        g_stCalibData.stPFCruiseFuncConfig.Calib_f32STOPACCCRUISING = valueFloat;
    } 
    if(0 == cfm_get_float("PF_G04", &valueFloat))
    {
        g_stCalibData.stPFCruiseFuncConfig.Calib_f32MAX_LATERRDISCRUISING = valueFloat;
    } 
    if(0 == cfm_get_float("PF_G05", &valueFloat))
    {
        g_stCalibData.stPFCruiseFuncConfig.Calib_f32MAX_LATERRHEADINGCRUISING = valueFloat;
    }
    if(0 == cfm_get_float("PF_G06", &valueFloat))
    {
        g_stCalibData.stPFCruiseFuncConfig.Calib_f32MAX_LONERRCRUISING = valueFloat;
    } 
    if(0 == cfm_get_float("PF_G07", &valueFloat))
    {
        g_stCalibData.stPFCruiseFuncConfig.Calib_f32LPBANDWIDTHCRUISING = valueFloat;
    } 
    if(0 == cfm_get_float("PF_G08", &valueFloat))
    {
        g_stCalibData.stPFCruiseFuncConfig.Calib_f32K1DISCRUISING = valueFloat;
    } 
    if(0 == cfm_get_float("PF_G09", &valueFloat))
    {
        g_stCalibData.stPFCruiseFuncConfig.Calib_f32K2DOTDISCRUISING = valueFloat;
    } 
    if(0 == cfm_get_float("PF_G10", &valueFloat))
    {
        g_stCalibData.stPFCruiseFuncConfig.Calib_f32K3THETACRUISING = valueFloat;
    } 
    if(0 == cfm_get_float("PF_G11", &valueFloat))
    {
        g_stCalibData.stPFCruiseFuncConfig.Calib_f32K4DOTTHETACRUISING = valueFloat;
    } 
    // reserve
    // if(0 == cfm_get_float("PF_G12", &valueFloat))
    // {
        
    // } 
    // if(0 == cfm_get_float("PF_G13", &valueFloat))
    // {
        
    // } 
    // if(0 == cfm_get_float("PF_G14", &valueFloat))
    // {
        
    // } 
    // if(0 == cfm_get_float("PF_G15", &valueFloat))
    // {
        
    // } 

    return E_OK;
}

