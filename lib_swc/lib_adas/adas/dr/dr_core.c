#include "adas_math.h"
#include "dr_core.h"
#include "adas_project_input.h"
#include "dr_structs.h"
#include "adas_calibration_data.h"
#include "adas_data_list.h"
#include "vehicle_service/calib/vehsrv_calib.h"

#define CtrlPara_START_SEC_VAR		// Memory allocation
#include "proj_MemMap.h"

static ST_DR_CAN_DATA     s_stNewCan;
ST_DR_INFO g_stDrInfoGlobalCoordinate;

#define CtrlPara_STOP_SEC_VAR	// Memory allocation end.
#include "proj_MemMap.h"


static EM_ADAS_ReturnType Dr_CalPose_New(PST_DR_INFO stDrInfo_ptr);
static EM_ADAS_ReturnType MoveInfo_Clear(ST_DR_MOVE_INFO* stMoveInfo_ptr);
static EM_ADAS_ReturnType MoveInfo_Set(PST_DR_INFO  stDrInfo_ptr);
static EM_ADAS_ReturnType Dr_SetPoseTo(PST_DR_INFO  stDrInfo_ptr);


/**
*************************************************************************
  * FUNCTION_NAME 
Dr_Start. 

  * EXPLANATION   
Initialization while power on, set the values to zero.  

*************************************************************************
*/

EM_ADAS_ReturnType Dr_Start(PST_DR_INFO stDrInfo_ptr)
{
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();

    s_stNewCan.u64Timestamp = 0;

    stDrInfo_ptr->stVehParam.f32WhlBase           = stCalibPF_ptr->stPFVehCalib.Calib_f32WhlBase;
    stDrInfo_ptr->stVehParam.f32VehWidth          = stCalibPF_ptr->stPFVehCalib.Calib_f32VehWidthDefault;
    stDrInfo_ptr->stVehParam.f32PlsOffset         = stCalibPF_ptr->stPFVehCalib.Calib_f32ImpuseGap;
    stDrInfo_ptr->stVehParam.u32MaxPls            = stCalibPF_ptr->stPFVehCalib.Calib_f32ImpulseMax;

    stDrInfo_ptr->stVehParam.f32VehWidth90Left_forward  = stCalibPF_ptr->stPFDRCalib.Calib_f32VehWidth90Left_forward;
    stDrInfo_ptr->stVehParam.f32VehWidth180Left_forward = stCalibPF_ptr->stPFDRCalib.Calib_f32VehWidth180Left_forward;
    stDrInfo_ptr->stVehParam.f32VehWidth270Left_forward = stCalibPF_ptr->stPFDRCalib.Calib_f32VehWidth270Left_forward;
    stDrInfo_ptr->stVehParam.f32VehWidth360Left_forward = stCalibPF_ptr->stPFDRCalib.Calib_f32VehWidth360Left_forward;
    stDrInfo_ptr->stVehParam.f32VehWidth450Left_forward = stCalibPF_ptr->stPFDRCalib.Calib_f32VehWidth450Left_forward;
    stDrInfo_ptr->stVehParam.f32VehWidthMaxLeft_forward = stCalibPF_ptr->stPFDRCalib.Calib_f32VehWidthMaxLeft_forward;
    stDrInfo_ptr->stVehParam.f32VehWidth90Right_forward = stCalibPF_ptr->stPFDRCalib.Calib_f32VehWidth90Right_forward;
    stDrInfo_ptr->stVehParam.f32VehWidth180Right_forward = stCalibPF_ptr->stPFDRCalib.Calib_f32VehWidth180Right_forward;
    stDrInfo_ptr->stVehParam.f32VehWidth270Right_forward = stCalibPF_ptr->stPFDRCalib.Calib_f32VehWidth270Right_forward;
    stDrInfo_ptr->stVehParam.f32VehWidth360Right_forward = stCalibPF_ptr->stPFDRCalib.Calib_f32VehWidth360Right_forward;
    stDrInfo_ptr->stVehParam.f32VehWidth450Right_forward = stCalibPF_ptr->stPFDRCalib.Calib_f32VehWidth450Right_forward;
    stDrInfo_ptr->stVehParam.f32VehWidthMaxRight_forward = stCalibPF_ptr->stPFDRCalib.Calib_f32VehWidthMaxRight_forward;

    stDrInfo_ptr->stVehParam.f32VehWidth90Left_backward    = stCalibPF_ptr->stPFDRCalib.Calib_f32VehWidth90Left_backward;
    stDrInfo_ptr->stVehParam.f32VehWidth180Left_backward   = stCalibPF_ptr->stPFDRCalib.Calib_f32VehWidth180Left_backward;
    stDrInfo_ptr->stVehParam.f32VehWidth270Left_backward   = stCalibPF_ptr->stPFDRCalib.Calib_f32VehWidth270Left_backward;
    stDrInfo_ptr->stVehParam.f32VehWidth360Left_backward   = stCalibPF_ptr->stPFDRCalib.Calib_f32VehWidth360Left_backward;
    stDrInfo_ptr->stVehParam.f32VehWidth450Left_backward   = stCalibPF_ptr->stPFDRCalib.Calib_f32VehWidth450Left_backward;
    stDrInfo_ptr->stVehParam.f32VehWidthMaxLeft_backward   = stCalibPF_ptr->stPFDRCalib.Calib_f32VehWidthMaxLeft_backward;
    stDrInfo_ptr->stVehParam.f32VehWidth90Right_backward   = stCalibPF_ptr->stPFDRCalib.Calib_f32VehWidth90Right_backward;
    stDrInfo_ptr->stVehParam.f32VehWidth180Right_backward  = stCalibPF_ptr->stPFDRCalib.Calib_f32VehWidth180Right_backward;
    stDrInfo_ptr->stVehParam.f32VehWidth270Right_backward  = stCalibPF_ptr->stPFDRCalib.Calib_f32VehWidth270Right_backward;
    stDrInfo_ptr->stVehParam.f32VehWidth360Right_backward  = stCalibPF_ptr->stPFDRCalib.Calib_f32VehWidth360Right_backward;
    stDrInfo_ptr->stVehParam.f32VehWidth450Right_backward  = stCalibPF_ptr->stPFDRCalib.Calib_f32VehWidth450Right_backward;
    stDrInfo_ptr->stVehParam.f32VehWidthMaxRight_backward  = stCalibPF_ptr->stPFDRCalib.Calib_f32VehWidthMaxRight_backward;

    stDrInfo_ptr->stVehParam.f32FP3 = stCalibPF_ptr->stPFDRCalib.Calib_f32FP3;
    stDrInfo_ptr->stVehParam.f32FP2 = stCalibPF_ptr->stPFDRCalib.Calib_f32FP2;
    stDrInfo_ptr->stVehParam.f32FP1 = stCalibPF_ptr->stPFDRCalib.Calib_f32FP1;
    stDrInfo_ptr->stVehParam.f32FP0 = stCalibPF_ptr->stPFDRCalib.Calib_f32FP0;

    stDrInfo_ptr->stVehParam.f32RP3 = stCalibPF_ptr->stPFDRCalib.Calib_f32RP3;
    stDrInfo_ptr->stVehParam.f32RP2 = stCalibPF_ptr->stPFDRCalib.Calib_f32RP2;
    stDrInfo_ptr->stVehParam.f32RP1 = stCalibPF_ptr->stPFDRCalib.Calib_f32RP1;
    stDrInfo_ptr->stVehParam.f32RP0 = stCalibPF_ptr->stPFDRCalib.Calib_f32RP0;

    stDrInfo_ptr->stVehPos.u64Timestamp           = 0;
    stDrInfo_ptr->stVehPos.f32Track               = 0.0f;
    stDrInfo_ptr->stVehPos.f32Theta               = 0.0f;
    stDrInfo_ptr->stVehPos.f32X_Coor              = 0.0f;
    stDrInfo_ptr->stVehPos.f32Y_Coor              = 0.0f;
    stDrInfo_ptr->stVehPos.f32X_CoorFront         = 0.0f;
    stDrInfo_ptr->stVehPos.f32Y_CoorFront         = 0.0f;
    stDrInfo_ptr->stVehPos.f32ThetaFront          = 0.0f;
    stDrInfo_ptr->stVehPos.f32TrackFront          = 0.0f;
    stDrInfo_ptr->stVehPos.f32X_CoorRear          = 0.0f;
    stDrInfo_ptr->stVehPos.f32Y_CoorRear          = 0.0f;
    stDrInfo_ptr->stVehPos.f32ThetaRear           = 0.0f;
    stDrInfo_ptr->stVehPos.f32TrackRear           = 0.0f;
    stDrInfo_ptr->stLastCAN.u64Timestamp          = 0;

    stDrInfo_ptr->stNowPose.u64Timestamp          = 0;
    stDrInfo_ptr->stNowPose.f32X_Coor             = 0.0f;
    stDrInfo_ptr->stNowPose.f32Y_Coor             = 0.0f;
    stDrInfo_ptr->stNowPose.f32Theta              = 0.0f;
    stDrInfo_ptr->stNowPose.f32Track              = 0.0f;
    stDrInfo_ptr->stNowPose.f32X_CoorFront        = 0.0f;
    stDrInfo_ptr->stNowPose.f32Y_CoorFront        = 0.0f;
    stDrInfo_ptr->stNowPose.f32ThetaFront         = 0.0f;
    stDrInfo_ptr->stNowPose.f32TrackFront         = 0.0f;
    stDrInfo_ptr->stNowPose.f32X_CoorRear         = 0.0f;
    stDrInfo_ptr->stNowPose.f32Y_CoorRear         = 0.0f;
    stDrInfo_ptr->stNowPose.f32ThetaRear          = 0.0f;
    stDrInfo_ptr->stNowPose.f32TrackRear          = 0.0f;

    stDrInfo_ptr->stVehPosPre.u64Timestamp           = 0;
    stDrInfo_ptr->stVehPosPre.f32Track               = 0.0f;
    stDrInfo_ptr->stVehPosPre.f32Theta               = 0.0f;
    stDrInfo_ptr->stVehPosPre.f32X_Coor              = 0.0f;
    stDrInfo_ptr->stVehPosPre.f32Y_Coor              = 0.0f;
    stDrInfo_ptr->stVehPosPre.f32X_CoorFront         = 0.0f;
    stDrInfo_ptr->stVehPosPre.f32Y_CoorFront         = 0.0f;
    stDrInfo_ptr->stVehPosPre.f32ThetaFront          = 0.0f;
    stDrInfo_ptr->stVehPosPre.f32TrackFront          = 0.0f;
    stDrInfo_ptr->stVehPosPre.f32X_CoorRear          = 0.0f;
    stDrInfo_ptr->stVehPosPre.f32Y_CoorRear          = 0.0f;
    stDrInfo_ptr->stVehPosPre.f32ThetaRear           = 0.0f;
    stDrInfo_ptr->stVehPosPre.f32TrackRear           = 0.0f;

    DataList_Init( &(stDrInfo_ptr->stThetaList),            8);
    DataList_Init( &(stDrInfo_ptr->stWhlPlsFrontLeftList),  16);
    DataList_Init( &(stDrInfo_ptr->stWhlPlsFrontRightList), 16);
    DataList_Init( &(stDrInfo_ptr->stWhlPlsRearLeftList),   16);
    DataList_Init( &(stDrInfo_ptr->stWhlPlsRearRightList),  16);

    MoveInfo_Clear(&(stDrInfo_ptr->stMoveInfo));
    stDrInfo_ptr->s32Flag = 0;

    return ADAS_RETURN_OK;
}



/**
*************************************************************************
  * FUNCTION_NAME 
Dr_Process. 

  * EXPLANATION   
Dr calculation includes following steps:
 - MoveInfo_Set. Calculate the [track offset, theta offset] based on pulse.
 - Dr_CalPose_New. Convert [track offset, theta offset] to [X, Y, theta].
 - Dr_SetPoseTo. Filter the theta. 
 - MoveInfo_Reset. Set the pulse value to zero, for the next round calculation. 

*************************************************************************
*/

EM_ADAS_ReturnType Dr_Process(PST_DR_INFO stDrInfo_ptr)
{
    if (stDrInfo_ptr->s32Flag == 0)
    {
        stDrInfo_ptr->s32Flag = 1;
        stDrInfo_ptr->stLastCAN.f32SteeringAngle = s_stNewCan.f32SteeringAngle;
        stDrInfo_ptr->stLastCAN.u16WheelPulseFL  = s_stNewCan.u16WheelPulseFL;
        stDrInfo_ptr->stLastCAN.u16WheelPulseFR  = s_stNewCan.u16WheelPulseFR;
        stDrInfo_ptr->stLastCAN.u16WheelPulseRL  = s_stNewCan.u16WheelPulseRL;
        stDrInfo_ptr->stLastCAN.u16WheelPulseRR  = s_stNewCan.u16WheelPulseRR;
        stDrInfo_ptr->stLastCAN.u64Timestamp     = s_stNewCan.u64Timestamp;
        stDrInfo_ptr->stLastCAN.u8ShiftPos       = s_stNewCan.u8ShiftPos;
    }
    else
    {
        MoveInfo_Set(stDrInfo_ptr);
        Dr_CalPose_New(stDrInfo_ptr);
        Dr_SetPoseTo(stDrInfo_ptr);
    }

    return E_OK;
}




/**
*************************************************************************
  * FUNCTION_NAME 
Dr_CoreSetCanData. 

  * EXPLANATION   
Update the CAN data which is received CAN network
Can data is the source of DR module
*************************************************************************
*/
EM_ADAS_ReturnType Dr_CoreSetCanData(PST_DR_INFO stDrInfo_ptr, uint64_t timeStamp, PST_VEHICLE_ESC_INFO stEscInfo_ptr, PST_VEHICLE_EPS_INFO stEpsInfo_ptr)
{
    // --- Record the previous CAN data.
    stDrInfo_ptr->stLastCAN.f32SteeringAngle = s_stNewCan.f32SteeringAngle;
    stDrInfo_ptr->stLastCAN.u64Timestamp     = s_stNewCan.u64Timestamp;
    stDrInfo_ptr->stLastCAN.u16WheelPulseFL  = s_stNewCan.u16WheelPulseFL;
    stDrInfo_ptr->stLastCAN.u16WheelPulseFR  = s_stNewCan.u16WheelPulseFR;
    stDrInfo_ptr->stLastCAN.u16WheelPulseRL  = s_stNewCan.u16WheelPulseRL;
    stDrInfo_ptr->stLastCAN.u16WheelPulseRR  = s_stNewCan.u16WheelPulseRR;
    stDrInfo_ptr->stLastCAN.u8ShiftPos       = s_stNewCan.u8ShiftPos;
    
    s_stNewCan.u64Timestamp    = timeStamp;

    if(WHEEL_DIR_FORWARD == stEscInfo_ptr->eWheelDirRL || WHEEL_DIR_FORWARD == stEscInfo_ptr->eWheelDirRR)
    {
        s_stNewCan.u8ShiftPos = WHEEL_DIR_FORWARD;
    }
    else if (WHEEL_DIR_BACKWARD == stEscInfo_ptr->eWheelDirRL || WHEEL_DIR_BACKWARD == stEscInfo_ptr->eWheelDirRR)
    {
        s_stNewCan.u8ShiftPos = WHEEL_DIR_BACKWARD;
    }
    else
    {
        s_stNewCan.u8ShiftPos = WHEEL_DIR_STANDSTILL;
    }

    if( s_stNewCan.u8ShiftPos != WHEEL_DIR_STANDSTILL )
    {
        // --- Update the new CAN data.
        s_stNewCan.u16WheelPulseFL = stEscInfo_ptr->u16WheSpePulFL;
        s_stNewCan.u16WheelPulseFR = stEscInfo_ptr->u16WheSpePulFR;
        s_stNewCan.u16WheelPulseRL = stEscInfo_ptr->u16WheSpePulRL;
        s_stNewCan.u16WheelPulseRR = stEscInfo_ptr->u16WheSpePulRR;
        s_stNewCan.f32SteeringAngle = stEpsInfo_ptr->f32SteeringWheelAngle;
    }


    return ADAS_RETURN_OK;
}


/*	=====================================================================
 *
 *						        static function definitions
 *
 *	===================================================================*/


/**
*************************************************************************
  * FUNCTION_NAME 
Dr_CalPose_New. 

  * EXPLANATION   
Convert [track offset, theta offset] to [X, Y, theta].  

*************************************************************************
*/

static EM_ADAS_ReturnType Dr_CalPose_New(PST_DR_INFO stDrInfo_ptr)
{
    stDrInfo_ptr->stVehPos.f32X_CoorFront       += stDrInfo_ptr->stMoveInfo.f32TrackOffsetFront * cosf(stDrInfo_ptr->stVehPos.f32ThetaFront + 0.5*stDrInfo_ptr->stMoveInfo.f32ThetaOfffsetFront);
    stDrInfo_ptr->stVehPos.f32Y_CoorFront       += stDrInfo_ptr->stMoveInfo.f32TrackOffsetFront * sinf(stDrInfo_ptr->stVehPos.f32ThetaFront + 0.5*stDrInfo_ptr->stMoveInfo.f32ThetaOfffsetFront);
    stDrInfo_ptr->stVehPos.f32ThetaFront        += stDrInfo_ptr->stMoveInfo.f32ThetaOfffsetFront;
    stDrInfo_ptr->stVehPos.f32ThetaFront        = NormalizeAngle(stDrInfo_ptr->stVehPos.f32ThetaFront);

    stDrInfo_ptr->stVehPos.f32X_CoorRear        += stDrInfo_ptr->stMoveInfo.f32TrackOffsetRear * cosf(stDrInfo_ptr->stVehPos.f32ThetaRear + 0.5*stDrInfo_ptr->stMoveInfo.f32ThetaOfffsetRear);
    stDrInfo_ptr->stVehPos.f32Y_CoorRear        += stDrInfo_ptr->stMoveInfo.f32TrackOffsetRear * sinf(stDrInfo_ptr->stVehPos.f32ThetaRear + 0.5*stDrInfo_ptr->stMoveInfo.f32ThetaOfffsetRear);
    stDrInfo_ptr->stVehPos.f32ThetaRear         += stDrInfo_ptr->stMoveInfo.f32ThetaOfffsetRear;
    stDrInfo_ptr->stVehPos.f32ThetaRear         = NormalizeAngle(stDrInfo_ptr->stVehPos.f32ThetaRear);

    stDrInfo_ptr->stVehPosPre.f32X_Coor         = stDrInfo_ptr->stVehPos.f32X_Coor;
    stDrInfo_ptr->stVehPosPre.f32Y_Coor         = stDrInfo_ptr->stVehPos.f32Y_Coor;
    stDrInfo_ptr->stVehPosPre.f32Theta          = stDrInfo_ptr->stVehPos.f32Theta;

    // stDrInfo_ptr->stVehPos.f32X_Coor            = (stDrInfo_ptr->stVehPos.f32X_CoorRear + stDrInfo_ptr->stVehParam.f32WhlBase + (stDrInfo_ptr->stVehPos.f32X_CoorFront - stDrInfo_ptr->stVehParam.f32WhlBase * cosf(stDrInfo_ptr->stVehPos.f32Theta))) / 2;
    // stDrInfo_ptr->stVehPos.f32Y_Coor            = (stDrInfo_ptr->stVehPos.f32Y_CoorRear + (stDrInfo_ptr->stVehPos.f32Y_CoorFront - stDrInfo_ptr->stVehParam.f32WhlBase * sinf(stDrInfo_ptr->stVehPos.f32Theta))) / 2;
    // stDrInfo_ptr->stVehPos.f32Theta             = stDrInfo_ptr->stVehPos.f32ThetaRear;

    // stDrInfo_ptr->stVehPos.f32Track             += sqrtf(powf(stDrInfo_ptr->stVehPos.f32X_Coor - stDrInfo_ptr->stVehPosPre.f32X_Coor, 2) + powf(stDrInfo_ptr->stVehPos.f32Y_Coor - stDrInfo_ptr->stVehPosPre.f32Y_Coor, 2));
    // stDrInfo_ptr->stVehPos.u64Timestamp         = s_stNewCan.u64Timestamp;
    // stDrInfo_ptr->stVehPos.f32Theta             = NormalizeAngle(stDrInfo_ptr->stVehPos.f32Theta);

    // stDrInfo_ptr->stVehPos.f32X_Coor            = stDrInfo_ptr->stVehPos.f32X_CoorFront;
    // stDrInfo_ptr->stVehPos.f32Y_Coor            = stDrInfo_ptr->stVehPos.f32Y_CoorFront;
    // stDrInfo_ptr->stVehPos.f32Theta             = stDrInfo_ptr->stVehPos.f32ThetaFront;

    // stDrInfo_ptr->stVehPos.f32Track             += stDrInfo_ptr->stMoveInfo.f32ThetaOfffsetFront;
    // stDrInfo_ptr->stVehPos.u64Timestamp         = s_stNewCan.u64Timestamp;
    // stDrInfo_ptr->stVehPos.f32Theta             = NormalizeAngle(stDrInfo_ptr->stVehPos.f32Theta);

    stDrInfo_ptr->stVehPos.f32X_Coor            = stDrInfo_ptr->stVehPos.f32X_CoorRear;
    stDrInfo_ptr->stVehPos.f32Y_Coor            = stDrInfo_ptr->stVehPos.f32Y_CoorRear;
    stDrInfo_ptr->stVehPos.f32Theta             = stDrInfo_ptr->stVehPos.f32ThetaRear;

    stDrInfo_ptr->stVehPos.f32Track             += fabs(stDrInfo_ptr->stMoveInfo.f32TrackOffsetRear);
    stDrInfo_ptr->stVehPos.u64Timestamp         = s_stNewCan.u64Timestamp;
    stDrInfo_ptr->stVehPos.f32Theta             = NormalizeAngle(stDrInfo_ptr->stVehPos.f32Theta);

    g_stCtrlVehSpeed.f32TimeGap = 0.02;
    g_stCtrlVehSpeed.f32VehSpeed = stDrInfo_ptr->stMoveInfo.f32TrackOffsetRear / g_stCtrlVehSpeed.f32TimeGap;

    return ADAS_RETURN_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME 
MoveInfo_Reset. 

  * EXPLANATION   
Set the pulse value to zero, for the next round calculation.  

*************************************************************************
*/

static EM_ADAS_ReturnType MoveInfo_Clear(ST_DR_MOVE_INFO* stMoveInfo_ptr)
{
    stMoveInfo_ptr->f32FlPlusNums           = 0.0;
    stMoveInfo_ptr->f32FrPlusNums           = 0.0;
    stMoveInfo_ptr->f32RlPlusNums           = 0.0;
    stMoveInfo_ptr->f32RrPlusNums           = 0.0;
    stMoveInfo_ptr->f32DataTime             = 0.0;
    stMoveInfo_ptr->f32ThetaOfffset         = 0.0;
    stMoveInfo_ptr->f32TrackOffset          = 0.0;
    stMoveInfo_ptr->f32ThetaOfffsetFront    = 0.0;
    stMoveInfo_ptr->f32TrackOffsetFront     = 0.0;
    stMoveInfo_ptr->f32ThetaOfffsetRear     = 0.0;
    stMoveInfo_ptr->f32TrackOffsetRear      = 0.0;

    return ADAS_RETURN_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME 
MoveInfo_Set. 

  * EXPLANATION   
Calculate the [track offset, theta offset] based on pulse.  

*************************************************************************
*/

static EM_ADAS_ReturnType MoveInfo_Set(PST_DR_INFO stDrInfo_ptr)
{
    MoveInfo_Clear(&(stDrInfo_ptr->stMoveInfo));

    int16_t detaWhlPlsRl = 0;
    int16_t detaWhlPlsRr = 0;
    int16_t detaWhlPlsFl = 0;
    int16_t detaWhlPlsFr = 0;

    float f32VehWidth = stDrInfo_ptr->stVehParam.f32VehWidth;

    detaWhlPlsFl = (int)s_stNewCan.u16WheelPulseFL - (int)stDrInfo_ptr->stLastCAN.u16WheelPulseFL;
    detaWhlPlsFr = (int)s_stNewCan.u16WheelPulseFR - (int)stDrInfo_ptr->stLastCAN.u16WheelPulseFR;
    detaWhlPlsRl = (int)s_stNewCan.u16WheelPulseRL - (int)stDrInfo_ptr->stLastCAN.u16WheelPulseRL;
    detaWhlPlsRr = (int)s_stNewCan.u16WheelPulseRR - (int)stDrInfo_ptr->stLastCAN.u16WheelPulseRR;
    
    if (detaWhlPlsFl < 0)
    {
        detaWhlPlsFl += stDrInfo_ptr->stVehParam.u32MaxPls;
    }
    if (detaWhlPlsFr < 0)
    {
        detaWhlPlsFr += stDrInfo_ptr->stVehParam.u32MaxPls;
    }
    if (detaWhlPlsRl < 0)
    {
        detaWhlPlsRl += stDrInfo_ptr->stVehParam.u32MaxPls;
    }
    if (detaWhlPlsRr < 0)
    {
        detaWhlPlsRr += stDrInfo_ptr->stVehParam.u32MaxPls;
    }
    
    if (detaWhlPlsFl > 30)
    {
        detaWhlPlsFl = 0;
    }
    if (detaWhlPlsFr > 30)
    {
        detaWhlPlsFr = 0;
    }
    if (detaWhlPlsRl > 30)
    {
        detaWhlPlsRl = 0;
    }
    if (detaWhlPlsRr > 30)
    {
        detaWhlPlsRr = 0;
    }
    
    DataList_Add(&(stDrInfo_ptr->stWhlPlsFrontLeftList), detaWhlPlsFl);
    DataList_Add(&(stDrInfo_ptr->stWhlPlsFrontRightList), detaWhlPlsFr);
    DataList_Add(&(stDrInfo_ptr->stWhlPlsRearLeftList), detaWhlPlsRl);
    DataList_Add(&(stDrInfo_ptr->stWhlPlsRearRightList), detaWhlPlsRr);

    stDrInfo_ptr->stMoveInfo.f32FlPlusNums = DataList_Average(&(stDrInfo_ptr->stWhlPlsFrontLeftList));
    stDrInfo_ptr->stMoveInfo.f32FrPlusNums = DataList_Average(&(stDrInfo_ptr->stWhlPlsFrontRightList));
    stDrInfo_ptr->stMoveInfo.f32RlPlusNums = DataList_Average(&(stDrInfo_ptr->stWhlPlsRearLeftList));
    stDrInfo_ptr->stMoveInfo.f32RrPlusNums = DataList_Average(&(stDrInfo_ptr->stWhlPlsRearRightList));

    float pls_num_front  = (stDrInfo_ptr->stMoveInfo.f32FlPlusNums + stDrInfo_ptr->stMoveInfo.f32FrPlusNums) / 2.0f;
    float pls_num_rear  = (stDrInfo_ptr->stMoveInfo.f32RlPlusNums + stDrInfo_ptr->stMoveInfo.f32RrPlusNums) / 2.0f;
    float pls_diff_front = (stDrInfo_ptr->stMoveInfo.f32FrPlusNums - stDrInfo_ptr->stMoveInfo.f32FlPlusNums);
    float pls_diff_rear = (stDrInfo_ptr->stMoveInfo.f32RrPlusNums - stDrInfo_ptr->stMoveInfo.f32RlPlusNums);

    stDrInfo_ptr->stMoveInfo.f32DataTime = s_stNewCan.u64Timestamp - stDrInfo_ptr->stLastCAN.u64Timestamp;


#if CTRL_DR_STEER_AND_VS
    float f32ThetaGap = 0;
    float f32WheelAngle = 0;
    float f32Steer2WheelRatio  = 0;
    float f32InstantRadius = 0;

    float f32SteerCub = s_stNewCan.f32SteeringAngle * s_stNewCan.f32SteeringAngle *s_stNewCan.f32SteeringAngle;
    float f32SteerSqr = s_stNewCan.f32SteeringAngle * s_stNewCan.f32SteeringAngle;
    float f32Steer    = s_stNewCan.f32SteeringAngle;

    if (WHEEL_DIR_FORWARD == s_stNewCan.u8ShiftPos)  //Change to wheel dir
    {
        if(s_stNewCan.f32SteeringAngle > 0)
        {
            f32Steer2WheelRatio = stDrInfo_ptr->stVehParam.f32FLP3 *f32SteerCub + stDrInfo_ptr->stVehParam.f32FLP2*f32SteerSqr + stDrInfo_ptr->stVehParam.f32FLP1*f32Steer + stDrInfo_ptr->stVehParam.f32FLP0;
            f32WheelAngle = s_stNewCan.f32SteeringAngle/f32Steer2WheelRatio;
            f32InstantRadius = stDrInfo_ptr->stVehParam.f32WhlBase / tanf(f32WheelAngle/180*3.14);
        }
        else
        {
            f32Steer2WheelRatio = stDrInfo_ptr->stVehParam.f32FRP3 *f32SteerCub + stDrInfo_ptr->stVehParam.f32FRP2*f32SteerSqr + stDrInfo_ptr->stVehParam.f32FRP1*f32Steer + stDrInfo_ptr->stVehParam.f32FRP0;
            f32WheelAngle = s_stNewCan.f32SteeringAngle/f32Steer2WheelRatio;
            f32InstantRadius = stDrInfo_ptr->stVehParam.f32WhlBase / tanf(f32WheelAngle/180*3.14);
        }
    }
    else if (WHEEL_DIR_BACKWARD == s_stNewCan.u8ShiftPos) //Change to wheel dir
    {
        if(s_stNewCan.f32SteeringAngle > 0)
        {
            f32Steer2WheelRatio = stDrInfo_ptr->stVehParam.f32RLP3 *f32SteerCub + stDrInfo_ptr->stVehParam.f32RLP2*f32SteerSqr + stDrInfo_ptr->stVehParam.f32RLP1*f32Steer + stDrInfo_ptr->stVehParam.f32RLP0;
            f32WheelAngle = s_stNewCan.f32SteeringAngle/f32Steer2WheelRatio;
            f32InstantRadius = stDrInfo_ptr->stVehParam.f32WhlBase / tanf(f32WheelAngle/180*3.14);
        }
        else
        {
            f32Steer2WheelRatio = stDrInfo_ptr->stVehParam.f32RRP3 *f32SteerCub + stDrInfo_ptr->stVehParam.f32RRP2*f32SteerSqr + stDrInfo_ptr->stVehParam.f32RRP1*f32Steer + stDrInfo_ptr->stVehParam.f32RRP0;
            f32WheelAngle = s_stNewCan.f32SteeringAngle/f32Steer2WheelRatio;
            f32InstantRadius = stDrInfo_ptr->stVehParam.f32WhlBase / tanf(f32WheelAngle/180*3.14);
        }
    }
    else
    {
        ;
    }
#endif

    if (WHEEL_DIR_FORWARD == s_stNewCan.u8ShiftPos)  //Change to wheel dir
    {
        stDrInfo_ptr->stMoveInfo.f32TrackOffsetFront    = pls_num_front * stDrInfo_ptr->stVehParam.f32PlsOffset;
        stDrInfo_ptr->stMoveInfo.f32ThetaOfffsetFront   = pls_diff_front * stDrInfo_ptr->stVehParam.f32PlsOffset / f32VehWidth; //Calibration Here
        stDrInfo_ptr->stMoveInfo.f32TrackOffsetRear     = pls_num_rear * stDrInfo_ptr->stVehParam.f32PlsOffset;
        stDrInfo_ptr->stMoveInfo.f32ThetaOfffsetRear    = pls_diff_rear * stDrInfo_ptr->stVehParam.f32PlsOffset / f32VehWidth; //Calibration Here
#if CTRL_DR_STEER_AND_VS
        stDrInfo_ptr->stMoveInfo.f32ThetaOfffsetRear    = stDrInfo_ptr->stMoveInfo.f32TrackOffsetRear/f32InstantRadius;
#endif
    }
    else if (WHEEL_DIR_BACKWARD == s_stNewCan.u8ShiftPos) //Change to wheel dir
    {
        stDrInfo_ptr->stMoveInfo.f32TrackOffsetFront    = -pls_num_front * stDrInfo_ptr->stVehParam.f32PlsOffset;
        stDrInfo_ptr->stMoveInfo.f32ThetaOfffsetFront   = -pls_diff_front * stDrInfo_ptr->stVehParam.f32PlsOffset / f32VehWidth; //Calibration Here
        stDrInfo_ptr->stMoveInfo.f32TrackOffsetRear     = -pls_num_rear * stDrInfo_ptr->stVehParam.f32PlsOffset;
        stDrInfo_ptr->stMoveInfo.f32ThetaOfffsetRear    = -pls_diff_rear * stDrInfo_ptr->stVehParam.f32PlsOffset / f32VehWidth; //Calibration Here
#if CTRL_DR_STEER_AND_VS
        stDrInfo_ptr->stMoveInfo.f32ThetaOfffsetRear    = stDrInfo_ptr->stMoveInfo.f32TrackOffsetRear/f32InstantRadius;
#endif
    }
    else
    {
        stDrInfo_ptr->stMoveInfo.f32TrackOffsetFront    = 0;
        stDrInfo_ptr->stMoveInfo.f32ThetaOfffsetFront   = 0;
        stDrInfo_ptr->stMoveInfo.f32TrackOffsetRear     = 0;
        stDrInfo_ptr->stMoveInfo.f32ThetaOfffsetRear    = 0;
    }

    return ADAS_RETURN_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME 
Dr_SetPoseTo. 

  * EXPLANATION   
Filter the theta.  

*************************************************************************
*/

static EM_ADAS_ReturnType Dr_SetPoseTo(PST_DR_INFO stDrInfo_ptr)
{
    
    stDrInfo_ptr->stNowPose = stDrInfo_ptr->stVehPos;

    return ADAS_RETURN_OK;
}

