/*
 * ctrl_lat_algo.c
 *
 *  Created on: Jul 21, 2021
 *      
 */
#include "ctrl_lat_algo.h"
#include "math.h"
#include "common/ctrl_comm_func.h"
#include "vehicle_service/calib/vehsrv_calib.h"
#include "adas_project_input.h"



/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_FinishActionLat

  * EXPLANATION
Finish action lateral.
*************************************************************************
*/

uint8_t Ctrl_FinishActionLat(tCtrlCommonInfo*       stCtrlCommonInfo_ptr,
                             tCtrlLatInfo*          stCtrlLatInfo_ptr,
                             tVehDataRx*            stVehDataRx_pt,
                             tCtrlToChassisInfo*    stCtrl2ChassisInfo_ptr)
{
  if (1 == stCtrlCommonInfo_ptr->u8FinishActionFlag){
    switch (stCtrlLatInfo_ptr->u8ReleaseTirePressurePhase){
      case 0:
        stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetSteerAngleRaw = 25;
        if (fabs(stVehDataRx_pt->sVehEPSInfo.f32StrWhlAngDeg - 25) < 5){
          stCtrlLatInfo_ptr->u8ReleaseTirePressurePhase = 1;
        }
        break;
      case 1:
        stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetSteerAngleRaw = -25;
        if (fabs(stVehDataRx_pt->sVehEPSInfo.f32StrWhlAngDeg + 25) < 5){
          stCtrlLatInfo_ptr->u8ReleaseTirePressurePhase = 2;
        }
        break;
      case 2:
        stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetSteerAngleRaw = 15;
        if (fabs(stVehDataRx_pt->sVehEPSInfo.f32StrWhlAngDeg-15) < 5){
          stCtrlLatInfo_ptr->u8ReleaseTirePressurePhase = 3;
        }
        break;
      case 3:
        stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetSteerAngleRaw = -15;
        if (fabs(stVehDataRx_pt->sVehEPSInfo.f32StrWhlAngDeg + 15) < 5){
          stCtrlLatInfo_ptr->u8ReleaseTirePressurePhase = 4;
        }
        break;
      case 4:
        stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetSteerAngleRaw = 0;
        if (fabs(stVehDataRx_pt->sVehEPSInfo.f32StrWhlAngDeg) < 5){
          stCtrlLatInfo_ptr->u8ReleaseTirePressurePhase = 5;
        }
        break;  
      default:
        ;
        break;
    }
  }

  return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_StopSteerBackToZero

  * EXPLANATION
Steer back to zero when finish current path. 
During waiting the next path, steer back to zero can save some time. 

*************************************************************************
*/

uint8_t Ctrl_StopSteerBackToZero(tCtrlLongiInfo*        stCtrlLongiInfo_ptr,
                                 tCtrlCommonInfo*       stCtrlCommonInfo_ptr,
                                 tCtrlLatInfo*          stCtrlLatInfo_ptr)
{
    if (PHASE_STOP == stCtrlLongiInfo_ptr->eSpeedPhase ||
        (PHASE_EMERGENCY_STOP == stCtrlLongiInfo_ptr->eSpeedPhase && stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebHappened == 0))  // In case of the vehicle slip over the path, and it will give bad effect to next path follow.     
    // VehSpd < 0.5 as an additional condition, so that the lateral path follow performance will be less influenced.
    {
        stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetSteerAngleRaw = 0;
    }

    return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_LimitationLat

  * EXPLANATION
Limitation of the lateral outputs.

*************************************************************************
*/

uint8_t Ctrl_LimitationLat(tCtrlLongiInfo*        stCtrlLongiInfo_ptr,
                           tCtrlCommonInfo*       stCtrlCommonInfo_ptr,
                           tCtrlToChassisInfo*    stCtrl2ChassisInfo_ptr)
{
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
    float f32SteerGap = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32SteerAngleIncreRatioMed;

    // --- Limit max and min
    if(stCtrl2ChassisInfo_ptr->f32CtrlReqSteerUnlimited >= stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32SteerAngleMax)
    {
        stCtrl2ChassisInfo_ptr->f32CtrlReqSteerMinmaxLimited = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32SteerAngleMax;
    }
    else if (stCtrl2ChassisInfo_ptr->f32CtrlReqSteerUnlimited <= -stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32SteerAngleMax)
    {
        stCtrl2ChassisInfo_ptr->f32CtrlReqSteerMinmaxLimited = -stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32SteerAngleMax;
    }
    else 
    {
        stCtrl2ChassisInfo_ptr->f32CtrlReqSteerMinmaxLimited = stCtrl2ChassisInfo_ptr->f32CtrlReqSteerUnlimited;
    }

    // --- Limit the steer change rate
    if(PHASE_STOP == stCtrlLongiInfo_ptr->eSpeedPhase || PHASE_EMERGENCY_STOP == stCtrlLongiInfo_ptr->eSpeedPhase ||
       PHASE_STOP_STEERING == stCtrlLongiInfo_ptr->eSpeedPhase) 
    {
        f32SteerGap = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32SteerAngleIncreRatioMed;
    }
    else
    {
        f32SteerGap = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32SteerAngleIncreRatioMax;
    }

    stCtrl2ChassisInfo_ptr->f32CtrlReqSteerPrev = stCtrl2ChassisInfo_ptr->f32CtrlReqSteer;
    if (stCtrl2ChassisInfo_ptr->f32CtrlReqSteerMinmaxLimited > stCtrl2ChassisInfo_ptr->f32CtrlReqSteerPrev + f32SteerGap)
    {
        stCtrl2ChassisInfo_ptr->f32CtrlReqSteerRateLimited = stCtrl2ChassisInfo_ptr->f32CtrlReqSteerPrev + f32SteerGap;
    }
    else if (stCtrl2ChassisInfo_ptr->f32CtrlReqSteerMinmaxLimited < stCtrl2ChassisInfo_ptr->f32CtrlReqSteerPrev - f32SteerGap)
    {
        stCtrl2ChassisInfo_ptr->f32CtrlReqSteerRateLimited = stCtrl2ChassisInfo_ptr->f32CtrlReqSteerPrev - f32SteerGap;
    }
    else
    {
        stCtrl2ChassisInfo_ptr->f32CtrlReqSteerRateLimited = stCtrl2ChassisInfo_ptr->f32CtrlReqSteerMinmaxLimited;
    }

    // --- Final result after limitation.
    stCtrl2ChassisInfo_ptr->f32CtrlReqSteer = stCtrl2ChassisInfo_ptr->f32CtrlReqSteerRateLimited;

    return E_OK;
}

 /**
 *************************************************************************
   * FUNCTION_NAME
 Ctrl_CalLqrFeedbackAngle

   * EXPLANATION
 This function calculates lateral feedback based on LQR algorithm.
 *************************************************************************
 */

uint8_t Ctrl_CalLqrFeedbackAngle(tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                tPathPlannerInfo*         stPathPlannerInfo_ptr,
                                tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                tCtrlCommonInfo*          stCtrlCommonInfo_ptr)
{
    tDF_PL_TYPE eCtrlPldType = stPathPlannerInfo_ptr->eCtrlPldType;
    uint8_t u8LastPathFlag = stPathPlannerInfo_ptr->u8LastPathFlag;
    float f32DistanceLeft = stCtrlCommonInfo_ptr->f32DistanceLeft;
	stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrDistFiltered  = ((float)stPathPlannerInfo_ptr->i8CtrlGearFactor) * stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrDistFiltered;
	stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrThetaFiltered = ((float)stPathPlannerInfo_ptr->i8CtrlGearFactor) * stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrThetaFiltered;

/*=========================== 
*	choose K value  
* ==========================*/
    float f32KbArr[4] = {4.0, 0.03, 3.0, 0.03};

    if (DF_PL_TYPE_Vertical == eCtrlPldType || DF_PL_TYPE_ThreeDimensional == eCtrlPldType)
    {
        if (1 == u8LastPathFlag)
        {
            if (f32DistanceLeft < 1.5)
            {
                f32KbArr[0] = 2;
                f32KbArr[1] = 0.02;
                f32KbArr[2] = 5;
                f32KbArr[3] = 0.02;
            }
            else if (f32DistanceLeft < 2.5)
            {
                f32KbArr[0] = 3;
                f32KbArr[1] = 0.02;
                f32KbArr[2] = 5;
                f32KbArr[3] = 0.02;
            }
            else if (f32DistanceLeft < 5)
            {
                f32KbArr[0] = 3.5;
                f32KbArr[1] = 0.02;
                f32KbArr[2] = 5;
                f32KbArr[3] = 0.02;
            }
        }
    }
    else if (DF_PL_TYPE_Horizontal == eCtrlPldType)
    {
        if (1 == u8LastPathFlag)    // Quite short distance.
        {
            f32KbArr[0] = 1;
            f32KbArr[1] = 0.02;
            f32KbArr[2] = 5;
            f32KbArr[3] = 0.02;
        }
    }

    stCtrlLatInfo_ptr->stCtrlLqr.f32K1 = f32KbArr[0];
    stCtrlLatInfo_ptr->stCtrlLqr.f32K2 = f32KbArr[1];
    stCtrlLatInfo_ptr->stCtrlLqr.f32K3 = f32KbArr[2];
    stCtrlLatInfo_ptr->stCtrlLqr.f32K4 = f32KbArr[3];

/*=========================== 
*	LQR feedback calculation
* ==========================*/
    stCtrlLatInfo_ptr->stCtrlLqr.f32FeedbackAngleRaw = -( f32KbArr[0] *  stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrDistFiltered
                                                        + f32KbArr[1] * (stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrDistFiltered - stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrDistFilteredPrev) / stCtrlLatInfo_ptr->stCtrlLqr.f32Ts
                                                        + f32KbArr[2] *  stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrThetaFiltered
                                                        + f32KbArr[3] * (stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrThetaFiltered - stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrThetaFilteredPrev) / stCtrlLatInfo_ptr->stCtrlLqr.f32Ts );	 

/*=========================== 
*	LQR feedback limitation
* ==========================*/
	if(stCtrlLatInfo_ptr->stCtrlLqr.f32FeedbackAngleRaw > 0.4)   // .15
	{
		stCtrlLatInfo_ptr->stCtrlLqr.f32FeedbackAngleRaw = 0.4;  // 0.15
	}
	else if(stCtrlLatInfo_ptr->stCtrlLqr.f32FeedbackAngleRaw < -0.4) // -0.15
	{
		stCtrlLatInfo_ptr->stCtrlLqr.f32FeedbackAngleRaw = -0.4; // -0.15
	}

	return E_OK;
}



 /**
 *************************************************************************
   * FUNCTION_NAME
 Ctrl_LqrCompensationLowPassFilter

   * EXPLANATION
 Specific usage of low pass filter in lateral LQR. 
  - Input: raw value.
  - Parameters: specific parameters.
  - Output: filtered value.

To put in common.

 *************************************************************************
 */

float Ctrl_LqrCompensationLowPassFilter(tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                        tPathPlannerInfo*         stPathPlannerInfo_ptr,
                                        tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                        tCtrlCommonInfo*          stCtrlCommonInfo_ptr)
{
    if(DF_PL_TYPE_ThreeDimensional == stPathPlannerInfo_ptr->eCtrlPldType)
    {
        if(stCtrlCommonInfo_ptr->f32DistanceLeft < 5 && 1 == stPathPlannerInfo_ptr->u8LastPathFlag)
        {
            stCtrlLatInfo_ptr->stCtrlLpfLat.f32LPF_den_2 = -0.7;
            stCtrlLatInfo_ptr->stCtrlLpfLat.f32LPF_num_1 = 0.15;
            stCtrlLatInfo_ptr->stCtrlLpfLat.f32LPF_num_2 = 0.15;
        }
        else
        {
            stCtrlLatInfo_ptr->stCtrlLpfLat.f32LPF_den_2 = -0.8;
            stCtrlLatInfo_ptr->stCtrlLpfLat.f32LPF_num_1 = 0.10;
            stCtrlLatInfo_ptr->stCtrlLpfLat.f32LPF_num_2 = 0.10;
        }
    }
    else if(DF_PL_TYPE_Vertical == stPathPlannerInfo_ptr->eCtrlPldType || DF_PL_TYPE_Horizontal == stPathPlannerInfo_ptr->eCtrlPldType)
    {
        if(stCtrlCommonInfo_ptr->f32DistanceLeft < 4 && 1 == stPathPlannerInfo_ptr->u8LastPathFlag)
        {
            stCtrlLatInfo_ptr->stCtrlLpfLat.f32LPF_den_2 = -0.90;  //MCE
            stCtrlLatInfo_ptr->stCtrlLpfLat.f32LPF_num_1 = 0.05;
            stCtrlLatInfo_ptr->stCtrlLpfLat.f32LPF_num_2 = 0.05;
        }
        else
        {
            stCtrlLatInfo_ptr->stCtrlLpfLat.f32LPF_den_2 = -0.70;
            stCtrlLatInfo_ptr->stCtrlLpfLat.f32LPF_num_1 = 0.15;
            stCtrlLatInfo_ptr->stCtrlLpfLat.f32LPF_num_2 = 0.15;
        }
    }
    else
    {
        ;
    }

    stCtrlLatInfo_ptr->stCtrlLpfLat.f32LPF_yk = stCtrlLatInfo_ptr->stCtrlLatResult.f32FeedbackAngleRaw;
    Ctrl_LpfCalculation(&stCtrlLatInfo_ptr->stCtrlLpfLat);
    stCtrlLatInfo_ptr->stCtrlLatResult.f32FeedbackAngleFiltered = stCtrlLatInfo_ptr->stCtrlLpfLat.f32LPF_filter_yk;

    return E_OK;

}



/**
 *************************************************************************
   * FUNCTION_NAME
 Ctrl_CalTargetSteerAngleRaw

   * EXPLANATION
 This function aims to adjust wheel2steer ratio based on target curvature,
 It should be removed or re-write in the future
 *************************************************************************
 */

uint8_t Ctrl_CalTargetSteerAngleRaw(tPathPlannerInfo*      stPathPlannerInfo_ptr,
                                    tCtrlCommonInfo*       stCtrlCommonInfo_ptr,
                                    tCtrlLatInfo*          stCtrlLatInfo_ptr,
                                    tVehDataRx*   stVehDataRx_pt)
{

/*===========================
*   Choose look ahead point (To re-use.)
*==========================*/
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
	int16_t i16LookForwardOffset = stCalibPF_ptr->stPFCtrlLatCalib.Calib_i16LookAheadForwardOffset;

    float Wheel2SteerRatio  = Ctrl_CalWheelCurve(stCtrlLatInfo_ptr,stVehDataRx_pt);
    //Wheel2SteerRatio = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32SteerRatioDefault;      // Use constant value.
    stCtrlLatInfo_ptr->stCtrlLatResult.f32WheelToSteerRatio = Wheel2SteerRatio;

/*

	if (1 == stPathPlannerInfo_ptr->u8LastPathFlag && DF_PL_TYPE_ThreeDimensional == stPathPlannerInfo_ptr->eCtrlPldType)
	{
	    i16LookForwardOffset = 3;
	}
    else if (1 == stPathPlannerInfo_ptr->u8LastPathFlag
             && DF_PL_TYPE_Horizontal == stPathPlannerInfo_ptr->eCtrlPldType
             && 2 == stPathPlannerInfo_ptr->u16TotallyPathNum)
    {
         i16LookForwardOffset = 3;
    }
	else if (1 == stPathPlannerInfo_ptr->u8LastPathFlag)
	{
	    i16LookForwardOffset = 2;
	}


	*/

/*===========================
*   Target curvature.
*==========================*/

    /*

    float f32TargetCurvature = 0.0f;

	if (stCtrlCommonInfo_ptr->u8BehindNearestPointIndexCurPose + i16LookForwardOffset < stPathPlannerInfo_ptr->u8PointNum)     
	{
		f32TargetCurvature = stPathPlannerInfo_ptr->stPathData[stCtrlCommonInfo_ptr->u8BehindNearestPointIndexCurPose + i16LookForwardOffset].f32WayPointCurvature;
	}
	else
	{
		f32TargetCurvature = stPathPlannerInfo_ptr->stPathData[stPathPlannerInfo_ptr->u8LastPointId].f32WayPointCurvature;
	}
	
	*/

/*===========================
*   Ratio calculation.
*==========================*/

    /*
    float StopDistCompFactor = stCtrlLatInfo_ptr->stCtrlLatResult.f32WheelToSteerRatioFactor;

    */



/*===========================
*   TargetSteerAngleRaw calculation.
*==========================*/

    stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetSteerAngleRaw = RadToDeg(g_stCtrlLatInfo.stCtrlLatResult.f32TargetWheelAngle * Wheel2SteerRatio);

    return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_Point2Point_DisCalcu

  * EXPLANATION
Output the result of Point2Point dis.

*************************************************************************
*/

float Ctrl_Point2Point_DisCalcu(float dr_x, float dr_y, float p_x, float p_y)
{
    float f32Point2PointDis = sqrtf((dr_x - p_x)*(dr_x - p_x) + (dr_y - p_y)*(dr_y - p_y));
    
    return f32Point2PointDis;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_Point2Line_DisCalcu

  * EXPLANATION
Output the result of Point2Line dis.

*************************************************************************
*/

float Ctrl_Point2Line_DisCalcu(float x1, float y1, float x2, float y2, float x3, float y3)
{
    float A = y2 - y1;
    float B = x1 - x2;
    float C = x1 * (y1 - y2) + y1 * (x2 - x1);
    float temp = sqrtf(A*A + B*B);

    temp = Ctrl_Anti_Devide_Zero(temp);

    float f32Point2LineDis = fabs(A*x3 + B*y3 + C) / temp;

    return f32Point2LineDis;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_PointLocateLine_Dir_Calcu

  * EXPLANATION
Determine the position relationship between a point and a directed line,
 positive->left and negative->left.

*************************************************************************
*/

int8_t Ctrl_PointLocateLine_Dir_Calcu(float x1, float y1, float x2, float y2, float x3, float y3)
{
    float   temp1 = y2-y3;
    float   temp2 = x2-x3;
    float   temp  = 0.0f;
    int8_t  i8Dir = 0;

    temp = (x1-x3)*temp1-(y1-y3)*temp2;

    if (temp > 0.0)
    {
        i8Dir = 1;
    }
    else
    {
        i8Dir = -1;
    }

    return i8Dir;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_TripletDisErr_Calcu

  * EXPLANATION
Determine the position relationship between a point and a directed line
 segment, positive left and negative left.

*************************************************************************
*/

float Ctrl_TripletDisErr_Calcu(float dr_x, float dr_y, float p1x, float p1y, float p2x, float p2y,
                                      float p3x, float p3y, float p4x, float p4y, float wc1, float wc2, float wc3)
{
    float s1 = Ctrl_Point2Line_DisCalcu(p1x, p1y, p2x, p2y, dr_x, dr_y);
    float s2 = Ctrl_Point2Line_DisCalcu(p2x, p2y, p3x, p3y, dr_x, dr_y);
    float s3 = Ctrl_Point2Line_DisCalcu(p3x, p3y, p4x, p4y, dr_x, dr_y);

    int8_t dir1 = Ctrl_PointLocateLine_Dir_Calcu(p1x, p1y, p2x, p2y, dr_x, dr_y);
    int8_t dir2 = Ctrl_PointLocateLine_Dir_Calcu(p2x, p2y, p3x, p3y, dr_x, dr_y);
    int8_t dir3 = Ctrl_PointLocateLine_Dir_Calcu(p3x, p3y, p4x, p4y, dr_x, dr_y);

    float f32DisErr = wc1/(wc1 + wc2 + wc3) * s1 * (float)dir1 + 
                    wc2/(wc1 + wc2 + wc3) * s2 * (float)dir2 + 
                    wc3/(wc1 + wc2 + wc3) * s3 * (float)dir3;

    // PRINTF_WJ("s1 %3.3f,s2 %3.3f,s3 %3.3f,d1 %2d,d2 %2d,d3 %2d,f32DisErr %3.3f\r\n",
    //             s1,
    //             s2,
    //             s3,
    //             dir1,
    //             dir2,
    //             dir3,
    //             f32DisErr);

    return f32DisErr;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_Anti_Devide_Zero

  * EXPLANATION
Prevents the divisible item from being zero.

*************************************************************************
*/

float Ctrl_Anti_Devide_Zero(float temp)
{
    float f32OutPut = 0.0f;

    if (fabs(temp) < 0.0001)
    {
        if (temp > 0.0f)
        {
            f32OutPut = 0.0001;
        }
        else
        {
            f32OutPut = -0.0001;
        }
    }
    else
    {
        f32OutPut = temp;
    }    

    return f32OutPut;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_CalcuRotatePointCoordsX

  * EXPLANATION
Calculate the x-coordinate of a point rotated 90 degrees against its axis

*************************************************************************
*/

float Ctrl_CalcuRotatePointCoordsX(float Point1_y, float Point2_y, float Point2_x)
{
    float f32OutPut = 0.0f;
    f32OutPut = -Point1_y + Point2_y + Point2_x;
  
    return f32OutPut;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_CalcuRotatePointCoordsY

  * EXPLANATION
Calculate the y-coordinate of a point rotated 90 degrees against its axis

*************************************************************************
*/

float Ctrl_CalcuRotatePointCoordsY(float Point1_x, float Point2_x, float Point2_y)
{
    float f32OutPut = 0.0f;
    f32OutPut = -Point1_x + Point2_x + Point2_y;

    return f32OutPut;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_Calcu_DistErr

  * EXPLANATION
DisErr main algo.

*************************************************************************
*/

uint8_t Ctrl_Calcu_DistErr(tPathPlannerInfo*      stPathPlannerInfo_ptr,
                          tCtrlLatInfo*          stCtrlLatInfo_ptr,
                          tCtrlCommonInfo*       stCtrlCommonInfo_ptr,
                          tCtrlVehPose*          stCtrlVehPose_ptr)
{
    uint8_t u8TotalNum  = stPathPlannerInfo_ptr->u8PointNum;
    uint8_t u8MpIndex   = stCtrlCommonInfo_ptr->u8BehindPointIndex;
    float   dr_x        = stCtrlVehPose_ptr->stSelectedPos.f32X_Coor;
    float   dr_y        = stCtrlVehPose_ptr->stSelectedPos.f32Y_Coor;

    uint8_t u8PointLeft = u8TotalNum - u8MpIndex - 1;
    float   f32ErrDist   = 0;

    float p1x = 0.0f;
    float p1y = 0.0f;
    float p2x = 0.0f;
    float p2y = 0.0f;
    float p3x = 0.0f;
    float p3y = 0.0f;
    float p4x = 0.0f;
    float p4y = 0.0f;
    float wc1 = 0.0f;
    float wc2 = 0.0f;
    float wc3 = 0.0f;

    switch (u8PointLeft)
    {
    case 0:
        p1x = stPathPlannerInfo_ptr->stPathData[u8TotalNum - 2].f32WayPointX;
        p1y = stPathPlannerInfo_ptr->stPathData[u8TotalNum - 2].f32WayPointY;
        p2x = stPathPlannerInfo_ptr->stPathData[u8TotalNum - 1].f32WayPointX;
        p2y = stPathPlannerInfo_ptr->stPathData[u8TotalNum - 1].f32WayPointY;
        p3x = 0.0f;
        p3y = 0.0f;
        p4x = 0.0f;
        p4y = 0.0f;
        wc1 = 1;
        wc2 = 0;
        wc3 = 0;

        break;
    case 1:
        p1x = stPathPlannerInfo_ptr->stPathData[u8TotalNum - 2].f32WayPointX;
        p1y = stPathPlannerInfo_ptr->stPathData[u8TotalNum - 2].f32WayPointY;
        p2x = stPathPlannerInfo_ptr->stPathData[u8TotalNum - 1].f32WayPointX;
        p2y = stPathPlannerInfo_ptr->stPathData[u8TotalNum - 1].f32WayPointY;
        p3x = 0.0f;
        p3y = 0.0f;
        p4x = 0.0f;
        p4y = 0.0f;
        wc1 = 1;
        wc2 = 0;
        wc3 = 0;

        break;
    case 2:
        p1x = stPathPlannerInfo_ptr->stPathData[u8TotalNum - 3].f32WayPointX;
        p1y = stPathPlannerInfo_ptr->stPathData[u8TotalNum - 3].f32WayPointY;
        p2x = stPathPlannerInfo_ptr->stPathData[u8TotalNum - 2].f32WayPointX;
        p2y = stPathPlannerInfo_ptr->stPathData[u8TotalNum - 2].f32WayPointY;
        p3x = stPathPlannerInfo_ptr->stPathData[u8TotalNum - 1].f32WayPointX;
        p3y = stPathPlannerInfo_ptr->stPathData[u8TotalNum - 1].f32WayPointY;
        p4x = 0.0f;
        p4y = 0.0f;
        wc1 = 1;
        wc2 = 1;
        wc3 = 0;   

        break;
    default:
        p1x = stPathPlannerInfo_ptr->stPathData[u8MpIndex].f32WayPointX;
        p1y = stPathPlannerInfo_ptr->stPathData[u8MpIndex].f32WayPointY;
        p2x = stPathPlannerInfo_ptr->stPathData[u8MpIndex + 1].f32WayPointX;
        p2y = stPathPlannerInfo_ptr->stPathData[u8MpIndex + 1].f32WayPointY;
        p3x = stPathPlannerInfo_ptr->stPathData[u8MpIndex + 2].f32WayPointX;
        p3y = stPathPlannerInfo_ptr->stPathData[u8MpIndex + 2].f32WayPointY;
        p4x = stPathPlannerInfo_ptr->stPathData[u8MpIndex + 3].f32WayPointX;
        p4y = stPathPlannerInfo_ptr->stPathData[u8MpIndex + 3].f32WayPointY;
        wc1 = CTRL_DIS_ERR_CALCU_WEIGHT_COEFFICIENT_ONE;
        wc2 = CTRL_DIS_ERR_CALCU_WEIGHT_COEFFICIENT_TWO;
        wc3 = CTRL_DIS_ERR_CALCU_WEIGHT_COEFFICIENT_THREE;

        break;
    }

    f32ErrDist = Ctrl_TripletDisErr_Calcu(dr_x, dr_y, p1x, p1y, p2x, p2y,
                            p3x, p3y, p4x, p4y, wc1, wc2, wc3);

   stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrDistRaw = f32ErrDist;

    // --- Invalid path and reference point. Park finished.
   if (stPathPlannerInfo_ptr->u16PathId > stPathPlannerInfo_ptr->u16TotallyPathNum)
   {
       stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrDistRaw = 0;
   }

    return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_Calcu_ThetaErr

  * EXPLANATION
ThetaErr main algo.

*************************************************************************
*/

uint8_t Ctrl_Calcu_ThetaErr(tPathPlannerInfo*     stPathPlannerInfo_ptr,
                            tCtrlLatInfo*         stCtrlLatInfo_ptr,
                            tCtrlCommonInfo*      stCtrlCommonInfo_ptr,
                            tCtrlVehPose*         stCtrlVehPose_ptr)
{
    uint8_t u8TotalNum      = stPathPlannerInfo_ptr->u8PointNum;
    uint8_t u8EndPointIndex = u8TotalNum - 1;
    uint8_t u8MpIndex       = stCtrlCommonInfo_ptr->u8BehindPointIndex;
    float   dr_x            = stCtrlVehPose_ptr->stSelectedPos.f32X_Coor;
    float   dr_y            = stCtrlVehPose_ptr->stSelectedPos.f32Y_Coor;
    float   dr_t            = stCtrlVehPose_ptr->stCurrentPos.f32Theta;

    float   f32ErrTheta     = 0.0f;
    float   f32TargetCur    = 0.0f;
    float   f32ThetaRef     = 0.0f;

    float   mpx     = 0.0f;
    float   mpy     = 0.0f;
    float   mppx    = 0.0f;
    float   mppy    = 0.0f;
    float   mdpx    = 0.0f;
    float   mdpy    = 0.0f;
    float   theta   = 0.0f;
    float   theta_p = 0.0f;
    float   cur     = 0.0f;
    float   cur_p   = 0.0f;
    uint8_t dir     = 0;

    if (0 == u8MpIndex)
    {
        mpx     = stPathPlannerInfo_ptr->stPathData[0].f32WayPointX;
        mpy     = stPathPlannerInfo_ptr->stPathData[0].f32WayPointY;
        mppx    = stPathPlannerInfo_ptr->stPathData[1].f32WayPointX;
        mppy    = stPathPlannerInfo_ptr->stPathData[1].f32WayPointY;
        theta   = stPathPlannerInfo_ptr->stPathData[0].f32WayPointTheta;
        theta_p = stPathPlannerInfo_ptr->stPathData[1].f32WayPointTheta;
        cur     = stPathPlannerInfo_ptr->stPathData[0].f32WayPointCurvature;
        cur_p   = stPathPlannerInfo_ptr->stPathData[1].f32WayPointCurvature;

        float resx = Ctrl_CalcuRotatePointCoordsX(mppy, mpy, mpx);
        float resy = Ctrl_CalcuRotatePointCoordsY(mppx, mpx, mpy);
        float s0   = 0.0f;

        dir = Ctrl_PointLocateLine_Dir_Calcu(mpx, mpy, resx, resy, dr_x, dr_y);

        if (1 == dir)
        {
            f32ThetaRef  = theta;
            f32ErrTheta  = NormalizeAngle(dr_t - f32ThetaRef);
            f32TargetCur = cur;
        }
        else
        {
            s0   = Ctrl_Point2Line_DisCalcu(mpx, mpy, resx, resy, dr_x, dr_y);
            float temp = sqrt((mpx - mppx)*(mpx - mppx) + (mpy - mppy)*(mpy - mppy)) / 2;
            temp = Ctrl_Anti_Devide_Zero(temp);

            f32ThetaRef  = theta + s0/temp * (NormalizeAngle(theta_p - theta));
            f32ErrTheta  = NormalizeAngle(dr_t - f32ThetaRef);
            f32TargetCur = cur + s0/temp * (cur_p - cur);
        }
    }
    else if (u8EndPointIndex == u8MpIndex)
    {
        theta   = stPathPlannerInfo_ptr->stPathData[u8TotalNum - 1].f32WayPointTheta;
        cur     = stPathPlannerInfo_ptr->stPathData[u8TotalNum - 1].f32WayPointCurvature;

        f32ThetaRef  = theta;
        f32ErrTheta  = NormalizeAngle(dr_t - f32ThetaRef);
        f32TargetCur = cur;
    }
    else
    {
        mpx     = stPathPlannerInfo_ptr->stPathData[u8MpIndex].f32WayPointX;
        mpy     = stPathPlannerInfo_ptr->stPathData[u8MpIndex].f32WayPointY;
        mppx    = stPathPlannerInfo_ptr->stPathData[u8MpIndex + 1].f32WayPointX;
        mppy    = stPathPlannerInfo_ptr->stPathData[u8MpIndex + 1].f32WayPointY;
        mdpx    = stPathPlannerInfo_ptr->stPathData[u8MpIndex - 1].f32WayPointX;
        mdpy    = stPathPlannerInfo_ptr->stPathData[u8MpIndex - 1].f32WayPointY;
        theta   = stPathPlannerInfo_ptr->stPathData[u8MpIndex].f32WayPointTheta;
        theta_p = stPathPlannerInfo_ptr->stPathData[u8MpIndex + 1].f32WayPointTheta;
        cur     = stPathPlannerInfo_ptr->stPathData[u8MpIndex].f32WayPointCurvature;
        cur_p   = stPathPlannerInfo_ptr->stPathData[u8MpIndex + 1].f32WayPointCurvature;

        float resx2 = Ctrl_CalcuRotatePointCoordsX(mpy, (mdpy + mpy) / 2, (mdpx + mpx) / 2);
        float resy2 = Ctrl_CalcuRotatePointCoordsY(mpx, (mdpx + mpx) / 2, (mdpy + mpy) / 2);
        float s2    = Ctrl_Point2Line_DisCalcu((mpx + mppx) / 2, (mpy + mppy) / 2, resx2, resy2, dr_x, dr_y);

        f32ThetaRef  = theta_p + s2/(CTRL_P2P_DIS) * (NormalizeAngle(theta - theta_p));
        f32ErrTheta  = NormalizeAngle(dr_t - f32ThetaRef);
        f32TargetCur = cur_p + s2/(CTRL_P2P_DIS) * (cur - cur_p);
    }
    NormalizeAngle(f32ErrTheta);
    NormalizeAngle(f32ErrTheta);

    stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrThetaRaw  = f32ErrTheta;

    // --- Invalid path and reference point. Park finished.
    if (stPathPlannerInfo_ptr->u16PathId > stPathPlannerInfo_ptr->u16TotallyPathNum)
    {
        stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrThetaRaw = 0;
    }

    return E_OK;
}


/**
 *************************************************************************
   * FUNCTION_NAME
 Ctrl_GetLatErrTrajectoryFrame

   * EXPLANATION

 *************************************************************************
 */
tTrajectoryFrame Ctrl_GetLatErrTrajectoryFrame( tPathPlannerInfo*        stPathPlannerInfo_ptr,
                                                tCtrlVehiclePosition*      stPos_ptr,
                                                uint8_t                  index,
                                                float32_t                vehicleSped,
                                                tCtrlLatInfo*            stCtrlLatInfo_ptr,
                                                tCtrlCommonInfo*         stCtrlCommonInfo_ptr)
{
    tTrajectoryFrame trajFrame;
    float x = stPos_ptr->f32X_Coor;
    float y = stPos_ptr->f32Y_Coor;
    float theta = stPos_ptr->f32Theta;
    float refX = stPathPlannerInfo_ptr->stPathData[index].f32WayPointX;
    float refY = stPathPlannerInfo_ptr->stPathData[index].f32WayPointY;
    float refTheta = stPathPlannerInfo_ptr->stPathData[index].f32WayPointTheta;
    float refKappa = stPathPlannerInfo_ptr->stPathData[index].f32WayPointCurvature;
    float refS = stPathPlannerInfo_ptr->stPathData[index].f32WayPointS;
    float dX = x - refX;
    float dY = y - refY;
    float tr[2] = {cosf(refTheta),sinf(refTheta)};
    float nr[2] = {-sinf(refTheta),cosf(refTheta)};
    float BehindNearstPoint = stCtrlCommonInfo_ptr->f32FrontPointDistance;      // Seems mismatched, currently not in use.
    float ForwarNearestPoint = stCtrlCommonInfo_ptr->f32BehindPointDistance;
    

    float d  = nr[0] * dX + nr[1] * dY;
    float es = tr[0] * dX + tr[1] * dY;
    float s  = refS + es;

   float deltaTheta = theta - (refTheta + refKappa * es);

    // float refTheta_Interp = refTheta;
    // float DeltaThetaGap  = 0;
    // if(  index + 1  <  stPathPlannerInfo_ptr->u8PointNum)
    // {
    //     DeltaThetaGap = stPathPlannerInfo_ptr->stPathData[index + 1].f32WayPointTheta - stPathPlannerInfo_ptr->stPathData[index].f32WayPointTheta;

    //     if(BehindNearstPoint +ForwarNearestPoint < 0.01)
    //     {
    //         refTheta_Interp = refTheta;
    //     }
    //     else
    //     {
    //         refTheta_Interp = refTheta + DeltaThetaGap *((BehindNearstPoint)/(BehindNearstPoint + ForwarNearestPoint)) ;
    //     }

    // }
    // else
    // {
    //     DeltaThetaGap = 0;
    //     refTheta_Interp = refTheta;
    // }

    // float deltaTheta = theta - refTheta_Interp;






    float d_dot = vehicleSped * sinf(deltaTheta);

    float one_minus_kappa_r_d = 1 - refKappa * d;
    if(one_minus_kappa_r_d <= 0.0)
    {
        one_minus_kappa_r_d = 0.01;
    }
    float s_dot = vehicleSped * cosf(deltaTheta) / one_minus_kappa_r_d;

    trajFrame.f32s = s;
    trajFrame.f32d = d * ((float)stPathPlannerInfo_ptr->i8CtrlGearFactor) ;
    trajFrame.f32s_dot = s_dot;
    trajFrame.f32d_dot = d_dot * ((float)stPathPlannerInfo_ptr->i8CtrlGearFactor) ;
    trajFrame.f32es = es;
    trajFrame.f32efai = sinf(deltaTheta);
    trajFrame.f32KappaDots = refKappa * s_dot;
    

    float wz = 0.0;
    stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrDistRaw = trajFrame.f32d;
    stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrDotDistRaw = trajFrame.f32d_dot;
    stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrThetaRaw = trajFrame.f32efai;
    stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrDotThetaRaw = wz - trajFrame.f32KappaDots;


    // --- Invalid path and reference point, park finished, stop calculation.
    if (stPathPlannerInfo_ptr->u16PathId > stPathPlannerInfo_ptr->u16TotallyPathNum)
    {
        stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrDistRaw = 0;
        stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrDotDistRaw = 0;
        stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrThetaRaw = 0;
        stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrDotThetaRaw = 0;
    }

    return trajFrame;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_Err_LowPassFilter

  * EXPLANATION
Low Pass Filter for diserr and thetaerr.

*************************************************************************
*/

uint8_t Ctrl_Err_LowPassFilter(tCtrlLatErr*          stCtrlLatErr_ptr)
{
    float ts  = 0.02f;
    float fc1 = CTRL_DIS_ERR_LPF_PARA;
    float fc2 = CTRL_THETA_ERR_LPF_PARA;

    float alph1 = ts / (ts + 1 / 2 * CTRL_PI * fc1);
    float alph2 = ts / (ts + 1 / 2 * CTRL_PI * fc2);

    float xn1  = stCtrlLatErr_ptr->f32ErrDistRaw;
    float ynd1 = stCtrlLatErr_ptr->f32ErrDistFilteredPrev;
    float yn1  = alph1 * xn1 + (1 - alph1) * ynd1;
    stCtrlLatErr_ptr->f32ErrDistFiltered     = yn1;
    stCtrlLatErr_ptr->f32ErrDistFilteredPrev = yn1;

    float xn2  = stCtrlLatErr_ptr->f32ErrThetaRaw;
    float ynd2 = stCtrlLatErr_ptr->f32ErrThetaFilteredPrev;
    float yn2  = alph2 * xn2 + (1 - alph2) * ynd2;
    stCtrlLatErr_ptr->f32ErrThetaFiltered     = yn2;
    stCtrlLatErr_ptr->f32ErrThetaFilteredPrev = yn2;

    return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_CurvatureSinglePointFilter

  * EXPLANATION
Low Pass Filter for single point preview curvature.

*************************************************************************
*/

uint8_t Ctrl_CurvatureSinglePointFilter(tCtrlLatInfo*   stCtrlLatInfo_ptr)
{
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
    stCtrlLatInfo_ptr->stCtrlLpfCurvatureSinglePoint.f32LPF_yk = stCtrlLatInfo_ptr->stCtrlLatErr.f32SinglePointTargetCurvatureRaw;
    stCtrlLatInfo_ptr->stCtrlLpfCurvatureSinglePoint.f32LPF_den_2 = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32SinglePointPreviewKappaLpfDen2;
    stCtrlLatInfo_ptr->stCtrlLpfCurvatureSinglePoint.f32LPF_num_1 = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32SinglePointPreviewKappaLpfNum1;
    stCtrlLatInfo_ptr->stCtrlLpfCurvatureSinglePoint.f32LPF_num_2 = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32SinglePointPreviewKappaLpfNum2;

    Ctrl_LpfCalculation(&stCtrlLatInfo_ptr->stCtrlLpfCurvatureSinglePoint);

    stCtrlLatInfo_ptr->stCtrlLatErr.f32SinglePointTargetCurvatureFiltered = stCtrlLatInfo_ptr->stCtrlLpfCurvatureSinglePoint.f32LPF_filter_yk;
    
    return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_CurvatureMultiPointFilter

  * EXPLANATION
Low Pass Filter for single point preview curvature.

*************************************************************************
*/

uint8_t Ctrl_CurvatureMultiPointFilter(tCtrlLatInfo*   stCtrlLatInfo_ptr)
{
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
    stCtrlLatInfo_ptr->stCtrlLpfCurvatureMultiPoint.f32LPF_yk = stCtrlLatInfo_ptr->stCtrlLatErr.f32MultiPointTargetCurvatureRaw;
    stCtrlLatInfo_ptr->stCtrlLpfCurvatureMultiPoint.f32LPF_den_2 = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32MultiPointPreviewKappaLpfDen2;
    stCtrlLatInfo_ptr->stCtrlLpfCurvatureMultiPoint.f32LPF_num_1 = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32MultiPointPreviewKappaLpfNum1;
    stCtrlLatInfo_ptr->stCtrlLpfCurvatureMultiPoint.f32LPF_num_2 = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32MultiPointPreviewKappaLpfNum2;

    Ctrl_LpfCalculation(&stCtrlLatInfo_ptr->stCtrlLpfCurvatureMultiPoint);

    stCtrlLatInfo_ptr->stCtrlLatErr.f32MultiPointTargetCurvatureFiltered = stCtrlLatInfo_ptr->stCtrlLpfCurvatureMultiPoint.f32LPF_filter_yk;
    
    return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_DistErrorFilter

  * EXPLANATION
Low Pass Filter for distance error.

*************************************************************************
*/

uint8_t Ctrl_DistErrorFilter(tCtrlLatInfo*   stCtrlLatInfo_ptr)
{
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
    stCtrlLatInfo_ptr->stCtrlLpfDistErr.f32LPF_yk = stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrDistRaw;
    stCtrlLatInfo_ptr->stCtrlLpfDistErr.f32LPF_den_2 = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32DistErrorLpfDen2;
    stCtrlLatInfo_ptr->stCtrlLpfDistErr.f32LPF_num_1 = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32DistErrorLpfNum1;
    stCtrlLatInfo_ptr->stCtrlLpfDistErr.f32LPF_num_2 = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32DistErrorLpfNum2;

    Ctrl_LpfCalculation(&stCtrlLatInfo_ptr->stCtrlLpfDistErr);

    stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrDistFilteredPrev = stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrDistFiltered;
    stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrDistFiltered = stCtrlLatInfo_ptr->stCtrlLpfDistErr.f32LPF_filter_yk;
    
    return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_ThetaErrorFilter

  * EXPLANATION
Low Pass Filter for theta error.

*************************************************************************
*/

uint8_t Ctrl_ThetaErrorFilter(tCtrlLatInfo*   stCtrlLatInfo_ptr)
{
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
    stCtrlLatInfo_ptr->stCtrlLpfThetaErr.f32LPF_yk = stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrThetaRaw;
    stCtrlLatInfo_ptr->stCtrlLpfThetaErr.f32LPF_den_2 = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32ThetaErrorLpfDen2;
    stCtrlLatInfo_ptr->stCtrlLpfThetaErr.f32LPF_num_1 = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32ThetaErrorLpfNum1;
    stCtrlLatInfo_ptr->stCtrlLpfThetaErr.f32LPF_num_2 = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32ThetaErrorLpfNum2;

    Ctrl_LpfCalculation(&stCtrlLatInfo_ptr->stCtrlLpfThetaErr);
    
    stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrThetaFilteredPrev = stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrThetaFiltered;
    stCtrlLatInfo_ptr->stCtrlLatErr.f32ErrThetaFiltered = stCtrlLatInfo_ptr->stCtrlLpfThetaErr.f32LPF_filter_yk;
    
    return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_LqrPreviewSinglePointCompensation

  * EXPLANATION
Calculation of speed compensation.

*************************************************************************
*/

float Ctrl_LqrPreviewSinglePointCompensation(tVehDataRx*              stVehDataRx_ptr,
                                               tCtrlCommonInfo*         stCtrlCommonInfo_ptr,
                                               tPathPlannerInfo*        stPathPlannerInfo_ptr)
{

    float f32CompTime = floor(stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph/4);
    if(f32CompTime > 0.7)
    {
      f32CompTime = 0.7;
    }

    return f32CompTime;
}

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_LqrPreviewSinglePoint

  * EXPLANATION
Calculation of curvature output with velocity.

*************************************************************************
*/

uint8_t Ctrl_LqrPreviewSinglePoint(tPathPlannerInfo*        stPathPlannerInfo_ptr,
                                   tCtrlLongiInfo*      	  stCtrlLongiInfo_ptr,
                                   tCtrlLatInfo*            stCtrlLatInfo_ptr,
                                   tCtrlCommonInfo*         stCtrlCommonInfo_ptr,
                                   tVehDataRx*              stVehDataRx_ptr)
{
    uint8_t u8FrontPointId = stCtrlCommonInfo_ptr->u8FrontPointIndex;
    uint8_t u8BehindPointId = stCtrlCommonInfo_ptr->u8BehindPointIndex;
    float f32FrontPointDist = stCtrlCommonInfo_ptr->f32FrontPointDistance;
    float f32BehindPointDist = stCtrlCommonInfo_ptr->f32BehindPointDistance;
    float f32FrontBehindTotalDist = f32FrontPointDist + f32BehindPointDist;
    uint8_t u8CurrentIndex = g_stCtrlCommonInfo.u8NearestPointIndexCurPose;
    tCtrlSpeedTrapezoidPhase ePhase = stCtrlLongiInfo_ptr->eSpeedPhase;
    float   f32CurrentTime = ((float)stPathPlannerInfo_ptr->stPathData[u8CurrentIndex].u32WayPointT)/1e6;
    float f32DelayTime = 0.5;
    uint8_t u8PointNum = stPathPlannerInfo_ptr->u8PointNum;
    float f32LastTime = ((float)stPathPlannerInfo_ptr->stPathData[u8PointNum-1].u32WayPointT)/1e6;
    uint8_t u8TargetPoint = 0;
    float f32CompTime = 0;
    float f32PPTrajTimeInterval = 0.04;//PP轨迹间隔时间

    if (ePhase == PHASE_STOP_STEERING||ePhase == PHASE_SPEED_INIT){
      f32DelayTime = 0;
    } else{
      f32DelayTime = 0.5;
    }
    u8TargetPoint = u8CurrentIndex+(uint8_t)(f32DelayTime/f32PPTrajTimeInterval);
    u8TargetPoint = (u8TargetPoint>=u8PointNum)? (u8PointNum-1) :u8TargetPoint;
    stCtrlCommonInfo_ptr->u8RecordedTargetFrontID  = u8TargetPoint;
    float f32FrontPointKappa = stPathPlannerInfo_ptr->stPathData[u8TargetPoint].f32WayPointCurvature;
    // float f32BehindPointKappa = stPathPlannerInfo_ptr->stPathData[u8BehindPoint].f32WayPointCurvature;
    float f32RefKappa = 0;
    stCtrlLatInfo_ptr->stCtrlLatErr.f32SinglePointTargetCurvatureRaw = f32FrontPointKappa;
    // stCtrlLatInfo_ptr->stCtrlLatErr.f32SinglePointTargetCurvatureRaw = f32RefKappa;

    return E_OK;
}

// uint8_t Ctrl_LqrPreviewSinglePoint(tPathPlannerInfo*        stPathPlannerInfo_ptr,
//                                    tCtrlLatInfo*            stCtrlLatInfo_ptr,
//                                    tCtrlCommonInfo*         stCtrlCommonInfo_ptr,
//                                    tChassisToCtrlInfo*      stChassisToCtrlInfo_ptr)
// {
//     uint8_t u8TotalNum   = stPathPlannerInfo_ptr->u8PointNum;
//     uint8_t u8MpIndex    = stCtrlCommonInfo_ptr->u8NearestPointIndexSelectedPose;         //stCtrlCommonInfo_ptr->u8BehindNearestPointIndexCurPose;
//     uint8_t u8PointLeft  = u8TotalNum - u8MpIndex - 1;
//     float   f32Speed     = stChassisToCtrlInfo_ptr->f32VehicleSpeed;
//     float   f32TargetCur = 0.0f;

//     switch (u8PointLeft)
//     {
//         case 0:
//             f32TargetCur = stPathPlannerInfo_ptr->stPathData[u8MpIndex].f32WayPointCurvature;
//             break;
//         case 1:
//             f32TargetCur = stPathPlannerInfo_ptr->stPathData[u8MpIndex].f32WayPointCurvature;
//             break;
//         case 2:
//             if (f32Speed > 1.5f)
//             {
//                 f32TargetCur = stPathPlannerInfo_ptr->stPathData[u8MpIndex + 1].f32WayPointCurvature;
//             }
//             else
//             {
//                 f32TargetCur = stPathPlannerInfo_ptr->stPathData[u8MpIndex].f32WayPointCurvature;
//             }
//             break;
//         default:
//             if( stPathPlannerInfo_ptr->u16PathId ==stPathPlannerInfo_ptr->u16TotallyPathNum  && DF_PL_TYPE_ThreeDimensional == stPathPlannerInfo_ptr->eCtrlPldType)
//             {
//                 f32TargetCur = stPathPlannerInfo_ptr->stPathData[u8MpIndex + 3].f32WayPointCurvature;
//             }
//             else if (f32Speed >= 2.0f)
//             {
//                 f32TargetCur = stPathPlannerInfo_ptr->stPathData[u8MpIndex + 2].f32WayPointCurvature;
//             }
//             else if(f32Speed >= 1.0f && f32Speed < 2.0f)
//             {
//                 f32TargetCur = stPathPlannerInfo_ptr->stPathData[u8MpIndex + 1].f32WayPointCurvature;
//             }
//             else
//             {
//                 f32TargetCur = stPathPlannerInfo_ptr->stPathData[u8MpIndex].f32WayPointCurvature;
//             }
//             break;
//     }

//     stCtrlLatInfo_ptr->stCtrlLatErr.f32SinglePointTargetCurvatureRaw = f32TargetCur;

//     return E_OK;
// }

/**
 *************************************************************************
   * FUNCTION_NAME
 Ctrl_LqrPreviewMultiPoints

   * EXPLANATION
 preview LQR select several path points ahead of ego vehicle as preview points.
 In this way, the path follow performance will be better in the situation of 
 quite curvy path.   

 5 points preview:
 - Hybrid A* planner: [0.4, 0.2, 0.2, 0.1, 0.1]
 - CLC planner: [0.9, 0.1, 0, 0, 0]

 *************************************************************************
 */

uint8_t Ctrl_LqrPreviewMultiPoints(tPathPlannerInfo*        stPathPlannerInfo_ptr,
                                   tCtrlCommonInfo*         stCtrlCommonInfo_ptr,
                                   tCtrlLatInfo*            stCtrlLatInfo_ptr)
{
    // --- inputs and initialization.
    uint8_t u8NearestPathPointId = stCtrlCommonInfo_ptr->u8NearestPointIndexSelectedPose;         //stCtrlCommonInfo_ptr->u8BehindNearestPointIndexCurPose;
    uint8_t u8TotalPointAmount = stPathPlannerInfo_ptr->u8PointNum;
    float   f32FeedforwardCurvature = 0.0;

    // --- Multi point preview & Kf calibration
    uint8_t u8PreviewPointAmount = 5;
    float f32KfArr[5] = {0.6, 0.3, 0.1, 0.0, 0.0}; 

    if (DF_PL_TYPE_ThreeDimensional == stPathPlannerInfo_ptr->eCtrlPldType)
    {   // for mechanical pld, we need quite precise path follow, and in this condition pp kappa change rate should be low. 
        f32KfArr[0] = 0.9;
        f32KfArr[1] = 0.1;
        f32KfArr[2] = 0;
        f32KfArr[3] = 0;
        f32KfArr[4] = 0;
    }

    if (u8NearestPathPointId >= u8TotalPointAmount - u8PreviewPointAmount)
    {
        f32FeedforwardCurvature = stPathPlannerInfo_ptr->stPathData[u8NearestPathPointId].f32WayPointCurvature;
    }
    else 
    {
        for (int i = 0; i < u8PreviewPointAmount; i++)
        {
            f32FeedforwardCurvature += stPathPlannerInfo_ptr->stPathData[u8NearestPathPointId + i + 1].f32WayPointCurvature * f32KfArr[i];
        }
    }

    stCtrlLatInfo_ptr->stCtrlLatErr.f32MultiPointTargetCurvatureRaw = f32FeedforwardCurvature;

    return E_OK;
}


/**
 *************************************************************************
   * FUNCTION_NAME
 Ctrl_CalFeedForwardAngle

   * EXPLANATION
 Calculate the feedforward angle based on the reference kappa.  

 *************************************************************************
 */

uint8_t Ctrl_CalFeedForwardAngle(tCtrlLatInfo*     stCtrlLatInfo_ptr)
{
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
    float f32WheelBase = stCalibPF_ptr->stPFVehCalib.Calib_f32WhlBase;
    float f32SinglePointCurv = stCtrlLatInfo_ptr->stCtrlLatErr.f32SinglePointTargetCurvatureFiltered;
    float f32MultiPointCurv = stCtrlLatInfo_ptr->stCtrlLatErr.f32MultiPointTargetCurvatureFiltered;
    
    stCtrlLatInfo_ptr->stCtrlLqr.f32SinglePointFeedforwardAngle = atanf(f32WheelBase * f32SinglePointCurv);
    stCtrlLatInfo_ptr->stCtrlLqr.f32MultiPointFeedforwardAngle = atanf(f32WheelBase * f32MultiPointCurv);

    return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_TargetSteerOutputFilter

  * EXPLANATION
Specific usage of low pass filter for final steering output.
 - Input: raw value.
 - Parameters: specific parameters.
 - Output: filtered value.

To put in common.

*************************************************************************
*/

uint8_t Ctrl_TargetSteerOutputFilter(tCtrlLatInfo* stCtrlLatInfo_ptr)
{
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();

    // --- Save the effective final target value of controller.
    if(stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetSteerAngleRaw >= stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32SteerAngleMax)
    {
        stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetSteerAngleLimited = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32SteerAngleMax;
    }
    else if (stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetSteerAngleRaw <= -stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32SteerAngleMax)
    {
        stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetSteerAngleLimited = -stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32SteerAngleMax;
    }
    else 
    {
        stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetSteerAngleLimited = stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetSteerAngleRaw;
    }

    // --- Low pass filter for controller's output raw value. 
    stCtrlLatInfo_ptr->stCtrlLpfTargetLatSteer.f32LPF_yk = stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetSteerAngleRaw;
    stCtrlLatInfo_ptr->stCtrlLpfTargetLatSteer.f32LPF_den_2 = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32TargetSteerLpfDen2;
    stCtrlLatInfo_ptr->stCtrlLpfTargetLatSteer.f32LPF_num_1 = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32TargetSteerLpfNum1;
    stCtrlLatInfo_ptr->stCtrlLpfTargetLatSteer.f32LPF_num_2 = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32TargetSteerLpfNum2;

    Ctrl_LpfCalculation(&stCtrlLatInfo_ptr->stCtrlLpfTargetLatSteer);
    stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetSteerAngleFiltered = stCtrlLatInfo_ptr->stCtrlLpfTargetLatSteer.f32LPF_filter_yk;
    
    return E_OK;
}


/*	=====================================================================
 *
 *						static function definitions
 *
 *	===================================================================*/

























/*	=====================================================================
 *
 *						function not in use
 *
 *	===================================================================*/


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_SteerEndSmoother. 

  * EXPLANATION   
Smooth Steer Output based on Raw Final Output 
(Used in EP40)

*************************************************************************
*/

float Ctrl_SteerEndSmoother()
{

    float f32SteerGapRaw = 2;

    if(fabs(g_stCtrlVehDataRx.sVehEPSInfo.f32StrWhlAngDeg - g_stCtrlLatInfo.stCtrlLatResult.f32FeedbackAngleRaw)>270)
    {
        f32SteerGapRaw = 8;
    }
    else if (fabs(g_stCtrlVehDataRx.sVehEPSInfo.f32StrWhlAngDeg - g_stCtrlLatInfo.stCtrlLatResult.f32FeedbackAngleRaw)>225)
    {
        f32SteerGapRaw = 7;
    }
    else if(fabs(g_stCtrlVehDataRx.sVehEPSInfo.f32StrWhlAngDeg - g_stCtrlLatInfo.stCtrlLatResult.f32FeedbackAngleRaw)>180)
    {
        f32SteerGapRaw = 6;
    }
    else if(fabs(g_stCtrlVehDataRx.sVehEPSInfo.f32StrWhlAngDeg - g_stCtrlLatInfo.stCtrlLatResult.f32FeedbackAngleRaw)>135)
    {
        f32SteerGapRaw = 5;
    }
    else if(fabs(g_stCtrlVehDataRx.sVehEPSInfo.f32StrWhlAngDeg - g_stCtrlLatInfo.stCtrlLatResult.f32FeedbackAngleRaw)>90)
    {
        f32SteerGapRaw = 4;
    }
    else if(fabs(g_stCtrlVehDataRx.sVehEPSInfo.f32StrWhlAngDeg - g_stCtrlLatInfo.stCtrlLatResult.f32FeedbackAngleRaw)>45)
    {
        f32SteerGapRaw = 3;
    }
    else if(fabs(g_stCtrlVehDataRx.sVehEPSInfo.f32StrWhlAngDeg - g_stCtrlLatInfo.stCtrlLatResult.f32FeedbackAngleRaw)>30)
    {
        f32SteerGapRaw = 2;
    }
    else
    {
        f32SteerGapRaw = 2;
    }

    return f32SteerGapRaw;
}


/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_SteerSmoother. 

  * EXPLANATION   
Smooth Steer Output based on SteerRatiom, Need To Calib
(Used in EP40)

*************************************************************************
*/

float Ctrl_SteerSmoother()
{

    float f32SteerGap = 3;
    if (fabs(g_stCtrlVehDataRx.sVehEPSInfo.f32StrWhlAngSpdRad)>5)
    {
        f32SteerGap = 8;
    }
    else if (fabs(g_stCtrlVehDataRx.sVehEPSInfo.f32StrWhlAngSpdRad)>4)
    {
        f32SteerGap = 6;
    }
    else if (fabs(g_stCtrlVehDataRx.sVehEPSInfo.f32StrWhlAngSpdRad)>3)
    {
        f32SteerGap = 5;
    }
    else if (fabs(g_stCtrlVehDataRx.sVehEPSInfo.f32StrWhlAngSpdRad)>2)
    {
        f32SteerGap = 4;
    }
    else if (fabs(g_stCtrlVehDataRx.sVehEPSInfo.f32StrWhlAngSpdRad)>1)
    {
        f32SteerGap = 3;
    }

    return f32SteerGap;
}



 /**
 *************************************************************************
   * FUNCTION_NAME
   Ctrl_Err_LowPassFilterOptimize
   (Used in EP40)

 *************************************************************************
 */

uint8_t Ctrl_Err_LowPassFilterOptimize(tCtrlLatErr* stCtrlLatErr_ptr,
                                       tCtrlLowPassFilterPara* stCtrlLpfDisErr_ptr,
                                       tCtrlLowPassFilterPara* stCtrlLpfThetaErr_ptr,
                                       tCtrlCommonInfo* stCtrlCommonInfo_ptr,
                                       tVehDataRx*   stVehDataRx_pt)
{

    // if(stCtrlCommonInfo_ptr->f32DistanceLeft <0.4) //stChassis2CtrlInfoptr->f32VehicleSpeed < 0.5 && stCtrlCommonInfo_ptr->f32DistanceLeft <0.6
    if(stVehDataRx_pt->sVehESCInfo.f32VehSpdKph < 0.4)
    {
      stCtrlLpfDisErr_ptr->f32LPF_yk = stCtrlLatErr_ptr->f32ErrDistRaw;
      stCtrlLpfDisErr_ptr->f32LPF_den_2 = -0.8;
      stCtrlLpfDisErr_ptr->f32LPF_num_1 = 0.1;
      stCtrlLpfDisErr_ptr->f32LPF_num_2 = 0.1;


      stCtrlLpfThetaErr_ptr->f32LPF_yk = stCtrlLatErr_ptr->f32ErrThetaRaw;
      stCtrlLpfThetaErr_ptr->f32LPF_den_2 = -0.96;
      stCtrlLpfThetaErr_ptr->f32LPF_num_1 = 0.02;
      stCtrlLpfThetaErr_ptr->f32LPF_num_2 = 0.02;
    }
    // else if(stCtrlCommonInfo_ptr->f32DistanceLeft <0.6) //stChassis2CtrlInfoptr->f32VehicleSpeed < 0.5 && stCtrlCommonInfo_ptr->f32DistanceLeft <0.6
    else if(stVehDataRx_pt->sVehESCInfo.f32VehSpdKph < 0.7)
    {
      stCtrlLpfDisErr_ptr->f32LPF_yk = stCtrlLatErr_ptr->f32ErrDistRaw;
      stCtrlLpfDisErr_ptr->f32LPF_den_2 = -0.8;
      stCtrlLpfDisErr_ptr->f32LPF_num_1 = 0.1;
      stCtrlLpfDisErr_ptr->f32LPF_num_2 = 0.1;


      stCtrlLpfThetaErr_ptr->f32LPF_yk = stCtrlLatErr_ptr->f32ErrThetaRaw;
      stCtrlLpfThetaErr_ptr->f32LPF_den_2 = -0.95;
      stCtrlLpfThetaErr_ptr->f32LPF_num_1 = 0.025;
      stCtrlLpfThetaErr_ptr->f32LPF_num_2 = 0.025;
    }
    else if(stVehDataRx_pt->sVehESCInfo.f32VehSpdKph < 1.0)
    {
      stCtrlLpfDisErr_ptr->f32LPF_yk = stCtrlLatErr_ptr->f32ErrDistRaw;
      stCtrlLpfDisErr_ptr->f32LPF_den_2 = -0.8;
      stCtrlLpfDisErr_ptr->f32LPF_num_1 = 0.1;
      stCtrlLpfDisErr_ptr->f32LPF_num_2 = 0.1;


      stCtrlLpfThetaErr_ptr->f32LPF_yk = stCtrlLatErr_ptr->f32ErrThetaRaw;
      stCtrlLpfThetaErr_ptr->f32LPF_den_2 = -0.934;
      stCtrlLpfThetaErr_ptr->f32LPF_num_1 = 0.033;
      stCtrlLpfThetaErr_ptr->f32LPF_num_2 = 0.033;
    }
    else
    {
      stCtrlLpfDisErr_ptr->f32LPF_yk = stCtrlLatErr_ptr->f32ErrDistRaw;
      stCtrlLpfDisErr_ptr->f32LPF_den_2 = -0.8;
      stCtrlLpfDisErr_ptr->f32LPF_num_1 = 0.1;
      stCtrlLpfDisErr_ptr->f32LPF_num_2 = 0.1;


      stCtrlLpfThetaErr_ptr->f32LPF_yk = stCtrlLatErr_ptr->f32ErrThetaRaw;
      stCtrlLpfThetaErr_ptr->f32LPF_den_2 = -0.9;
      stCtrlLpfThetaErr_ptr->f32LPF_num_1 = 0.05;
      stCtrlLpfThetaErr_ptr->f32LPF_num_2 = 0.05;
    }

    Ctrl_LpfCalculation(stCtrlLpfDisErr_ptr);
    Ctrl_LpfCalculation(stCtrlLpfThetaErr_ptr);

    stCtrlLatErr_ptr->f32ErrDistFiltered = stCtrlLpfDisErr_ptr->f32LPF_filter_yk;
    stCtrlLatErr_ptr->f32ErrThetaFiltered = stCtrlLpfThetaErr_ptr->f32LPF_filter_yk;


  return E_OK;
}


/**
 *************************************************************************
   * FUNCTION_NAME
 Ctrl_CalWheelCurve

   * EXPLANATION
 This function aims to calculate curve in SteerRatio
 *************************************************************************
 */

float Ctrl_CalWheelCurve(tCtrlLatInfo*             stCtrlLatInfo_ptr,
                         tVehDataRx*   stVehDataRx_pt)
{
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
    float f32WheelBase = stCalibPF_ptr->stPFVehCalib.Calib_f32WhlBase;
    float f32Steer2WheelRatio = 15;
    float f32WheelAngle = 0;
    float f32InstantRadius = 0;

    float f32TargetCurv = fabs(stCtrlLatInfo_ptr->stCtrlLatErr.f32SinglePointTargetCurvatureFiltered);

    float f32CurvCub   = f32TargetCurv*f32TargetCurv*f32TargetCurv;
    float f32CurvSqr   = f32TargetCurv*f32TargetCurv;
    float f32Curv      = f32TargetCurv;

    if (D_GEAR == stVehDataRx_pt ->sVehVCUInfo.eVehActualGear)  //Change to wheel dir
    {
        f32Steer2WheelRatio = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32FP3 * f32CurvCub + stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32FP2*f32CurvSqr + stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32FP1*f32Curv + stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32FP0;
    } 
    else if (R_GEAR == stVehDataRx_pt ->sVehVCUInfo.eVehActualGear) //Change to wheel dir
    {
        f32Steer2WheelRatio = stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32FP3 * f32CurvCub + stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32RP2*f32CurvSqr + stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32RP1*f32Curv + stCalibPF_ptr->stPFCtrlLatCalib.Calib_f32RP0;
    }
    else
    {
        ;
    }


  return f32Steer2WheelRatio;
}


/**
 *************************************************************************
   * FUNCTION_NAME
 Ctrl_CalWheelCurveFromAngleRatioBase

   * EXPLANATION
 This function aims to calculate curve from angle ratio base
 *************************************************************************
 */

float Ctrl_CalWheelCurveFromAngleRatioBase(float f32SteerAngle, 
                                           float f32SteerRatio, 
                                           float f32WheelBase)
{

  return tanf((f32SteerAngle * CTRL_PI) / (CTRL_180DEG * f32SteerRatio)) /f32WheelBase;
}


/**
 *************************************************************************
   * FUNCTION_NAME
 Ctrl_GetLatError

   * EXPLANATION

 *************************************************************************
 */

void Ctrl_GetLatError(tTrajectoryFrame *stTrajFrame_ptr,
                      tCtrlLatInfo* stCtrlLatInfo_ptr)
{


}
