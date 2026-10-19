#include <math.h>
#include "parking/ctrl_apa_sideout.h"
#include "ctrl_global_variables.h"
#include "ctrl_peb_algo_new.h"
#include "lib_adas_adapter/vehicle_service/ctrl_adapter/ctrl_adapter.h"
#include "common/ctrl_comm_func.h"
#include "controller/ctrl_long_algo.h"
#include "controller/ctrl_lat_algo.h"

static uint8_t Ctrl_SideParkOutMain(void);
static uint8_t ParkOutInit(void);
static uint8_t ParkOutInitCheck(tCtrlUssInfo* stCtrlUssInfo_ptr);
static uint8_t ParkOutPhaseInit(tCtrlUssInfo* stCtrlUssInfo_ptr);
static uint8_t Ctrl_ParkOutLeftSide(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                    tVehDataRx*   stVehDataRx_ptr,
                                    tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                    tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                    tCtrlParkOutSide*         stCtrlParkoutSide_ptr,
                                    tCtrlVehiclePosition*       stCurrentPos_ptr);

static uint8_t Ctrl_ParkOutRightSide(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                     tVehDataRx*   stVehDataRx_ptr,
                                     tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                     tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                     tCtrlParkOutSide*         stCtrlParkoutSide_ptr,
                                     tCtrlVehiclePosition*       stCurrentPos_ptr);

static uint8_t Ctrl_ParkOutDriveBack(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                    tVehDataRx*   stVehDataRx_ptr,
                                    tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                    tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                    tCtrlParkOutSide*         stCtrlParkoutSide_ptr,
                                    tCtrlVehiclePosition*       stCurrentPos_ptr);

static uint8_t Ctrl_ParkOutDriveFront(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                      tVehDataRx*   stVehDataRx_ptr,
                                      tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                      tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                      tCtrlParkOutSide*         stCtrlParkoutSide_ptr,
                                      tCtrlVehiclePosition*       stCurrentPos_ptr);

static uint8_t Ctrl_ParkOutStraightFarward(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                           tVehDataRx*   stVehDataRx_ptr,
                                           tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                           tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                           tCtrlParkOutSide*         stCtrlParkoutSide_ptr,
                                           tCtrlVehiclePosition*       stCurrentPos_ptr);

static uint8_t Ctrl_ParkOutLeftForward(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                       tVehDataRx*   stVehDataRx_ptr,
                                       tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                       tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                       tCtrlParkOutSide*         stCtrlParkoutSide_ptr,
                                       tCtrlVehiclePosition*       stCurrentPos_ptr);

static uint8_t Ctrl_ParkOutRightForward(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                        tVehDataRx*   stVehDataRx_ptr,
                                        tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                        tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                        tCtrlParkOutSide*         stCtrlParkoutSide_ptr,
                                        tCtrlVehiclePosition*       stCurrentPos_ptr);

static uint8_t Ctrl_ParkOutRightBackward(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                         tVehDataRx*   stVehDataRx_ptr,
                                         tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                         tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                         tCtrlParkOutSide*         stCtrlParkoutSide_ptr,
                                         tCtrlVehiclePosition*       stCurrentPos_ptr);

static uint8_t Ctrl_ParkOutLeftBackward(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                        tVehDataRx*   stVehDataRx_ptr,
                                        tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                        tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                        tCtrlParkOutSide*         stCtrlParkoutSide_ptr,
                                        tCtrlVehiclePosition*       stCurrentPos_ptr);

static uint8_t Ctrl_ParkOutComplete(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                    tVehDataRx*   stVehDataRx_ptr,
                                    tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                    tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                    tCtrlParkOutSide*         stCtrlParkoutSide_ptr,
                                    tCtrlVehiclePosition*       stCurrentPos_ptr);

static uint8_t Ctrl_ParkOutDownComplete(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                        tVehDataRx*   stVehDataRx_ptr,
                                        tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                        tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                        tCtrlParkOutSide*         stCtrlParkoutSide_ptr,
                                        tCtrlVehiclePosition*       stCurrentPos_ptr);

static uint8_t Ctrl_ParkOutFinish(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                  tCtrlParkOutSide*         stCtrlParkoutSide_ptr,
                                  tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                  tCtrlVehiclePosition*       stCurrentPos_ptr);

static uint8_t Ctrl_ParkOutOutput(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                  tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                  tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                  tCtrlToChassisInfo*       stCtrlToChassisInfo_ptr);

/**
*************************************************************************
  * FUNCTION_NAME
Ctrl_Straight_Task_20ms

  * EXPLANATION
APA straight main task.

*************************************************************************
*/

uint8_t Ctrl_SideParkOut_20ms(void)
{
    Ctrl_SideParkOutMain();

    Ctrl_ParkOutOutput(&g_stCtrlCommonInfo,
                       &g_stCtrlLongiInfo,
                       &g_stCtrlLatInfo,
                       &g_stCtrlToChassisInfo);

    return E_OK;
}

static uint8_t Ctrl_SideParkOutMain()
{
    if (0 == g_stCtrlParkoutSide.bParkOutInitFlag)
    {
        g_stCtrlParkoutSide.bParkOutInitFlag = 1;
        ParkOutInit();
    }
    else
    {
        ;
    }

    if ((DRIVER_CTRL_PARKOUT_NOPP_LEFT == g_stCtrlFuncFsmInfo.eLsadDriverCtrlCommand) || 
        (DRIVER_CTRL_PARKOUT_NOPP_RIGHT == g_stCtrlFuncFsmInfo.eLsadDriverCtrlCommand) || 
        (DRIVER_CTRL_PARKOUT_NOPP_MIDDLE == g_stCtrlFuncFsmInfo.eLsadDriverCtrlCommand))
    {
        g_stCtrlParkoutSide.iParkOutInitCheckWaitTime = g_stCtrlParkoutSide.iParkOutInitCheckWaitTime + 1;
        if (g_stCtrlParkoutSide.iParkOutInitCheckWaitTime > 1000)
        {
            g_stCtrlParkoutSide.iParkOutInitCheckWaitTime = 1000;
        }
    }
    else
    {
        g_stCtrlParkoutSide.iParkOutInitCheckWaitTime = 0;
    }
    
    if (g_stCtrlParkoutSide.iParkOutInitCheckWaitTime < 120)
    {
        // g_stCtrlToChassisInfo.eGearReq = VEHI_GEAR_R;
        return E_OK;
    }
    else
    {
        ;
    }

    if (DRIVER_CTRL_PARKOUT_NOPP_MIDDLE == g_stCtrlFuncFsmInfo.eLsadDriverCtrlCommand)
    {
        g_stCtrlUssInfo.u16PebDistanceConverted[0]    = 250;
        g_stCtrlUssInfo.u16PebDistanceConverted[1]    = 250;
        g_stCtrlUssInfo.u16PebDistanceConverted[6]    = 250;
        g_stCtrlUssInfo.u16PebDistanceConverted[7]    = 250;
        g_stCtrlUssInfo.u16PebDistanceConverted[16]   = 500;
        g_stCtrlUssInfo.u16PebDistanceConverted[18]   = 500;
    }
    else
    {
        ;
    }

    if ((0 == g_stCtrlParkoutSide.bParkOutInitCheckFlag) &&
        ((DRIVER_CTRL_PARKOUT_NOPP_LEFT == g_stCtrlFuncFsmInfo.eLsadDriverCtrlCommand) || 
         (DRIVER_CTRL_PARKOUT_NOPP_RIGHT == g_stCtrlFuncFsmInfo.eLsadDriverCtrlCommand) || 
         (DRIVER_CTRL_PARKOUT_NOPP_MIDDLE == g_stCtrlFuncFsmInfo.eLsadDriverCtrlCommand)))
    {
        if (DRIVER_CTRL_PARKOUT_NOPP_LEFT == g_stCtrlFuncFsmInfo.eLsadDriverCtrlCommand)
        {
            g_stCtrlParkoutSide.eParkOutType = LeftParkOut;
        }
        else if (DRIVER_CTRL_PARKOUT_NOPP_RIGHT == g_stCtrlFuncFsmInfo.eLsadDriverCtrlCommand)
        {
            g_stCtrlParkoutSide.eParkOutType = RightParkOut;
        }
        else if (DRIVER_CTRL_PARKOUT_NOPP_MIDDLE == g_stCtrlFuncFsmInfo.eLsadDriverCtrlCommand)
        {
            g_stCtrlParkoutSide.eParkOutType = StraightForwardParkOut;
        }
        else
        {
            ;
        }
        g_stCtrlParkoutSide.bParkOutInitCheckFlag = 1;
        ParkOutInitCheck(&g_stCtrlUssInfo);
    }
    else
    {
        ;
    }

    if (1 == g_stCtrlParkoutSide.bParkOutPreFinishFlag)
    {
        Ctrl_ParkOutComplete(&g_stCtrlCommonInfo,
                            &g_stCtrlVehDataRx,
                            &g_stCtrlLongiInfo,
                            &g_stCtrlLatInfo,
                            &g_stCtrlParkoutSide,
                            &g_stCtrlVehPose.stCurrentPos);
                              
    }
    else
    {
        ;
    }

    if (1 == g_stCtrlParkoutSide.bParkOutFinishFlag)
    {
        g_stCtrlCommonInfo.eCtrlFinishType = CTRL_FINISH_TYPE_APA;
        return E_OK;
    }
    else
    {
        ;
    }

    if (1 == g_stCtrlParkoutSide.bParkOutPreFinishFlag)
    {
        return E_OK;
    }
    else
    {
        ;
    }

    ParkOutPhaseInit(&g_stCtrlUssInfo);

    control_PEB_detection(&g_stCtrlCommonInfo, &g_stCtrlVehDataRx, &g_stCtrlUssInfo,
                          &g_stStateMachine, &g_stPathPlannerData,&g_stCtrlFuncFsmInfo,&g_stCtrlLongiInfo);

    if(LeftParkOut == g_stCtrlParkoutSide.eParkOutType)
    {
        Ctrl_ParkOutLeftSide(&g_stCtrlCommonInfo,
                             &g_stCtrlVehDataRx,
                             &g_stCtrlLongiInfo,
                             &g_stCtrlLatInfo,
                             &g_stCtrlParkoutSide,
                             &g_stCtrlVehPose.stCurrentPos);
    }
    else if(RightParkOut == g_stCtrlParkoutSide.eParkOutType)
    {
        Ctrl_ParkOutRightSide(&g_stCtrlCommonInfo,
                              &g_stCtrlVehDataRx,
                              &g_stCtrlLongiInfo,
                              &g_stCtrlLatInfo,
                              &g_stCtrlParkoutSide,
                              &g_stCtrlVehPose.stCurrentPos);
    }                              
    else if(StraightForwardParkOut == g_stCtrlParkoutSide.eParkOutType)
    {
        Ctrl_ParkOutStraightFarward(&g_stCtrlCommonInfo,
                                    &g_stCtrlVehDataRx,
                                    &g_stCtrlLongiInfo,
                                    &g_stCtrlLatInfo,
                                    &g_stCtrlParkoutSide,
                                    &g_stCtrlVehPose.stCurrentPos);
    }
    else
    {
        ;
    }

    return E_OK;

}


static uint8_t ParkOutInit()
{
    tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
    
    g_stCtrlParkoutSide.eParkOutFinishCode          = NoReason;
    g_stCtrlLongiInfo.f32TotalStopDistance          = 2.5;
    g_stCtrlParkoutSide.f32TargetTheta              = DegToRad(stCalibPF_ptr->stPFPkoutCalib.Calib_f32ThetaLimit);
    g_stCtrlParkoutSide.f32stopDis                  = 0.1;
    g_stCtrlParkoutSide.f32targetSpeed              = stCalibPF_ptr->stPFPkoutCalib.Calib_f32ParkoutSpeed;
    g_stCtrlParkoutSide.f32minSpeed                 = 0.1;
    g_stCtrlParkoutSide.f32maxSteer                 = 450;
    g_stCtrlParkoutSide.f32steerGap                 = 70;
    g_stCtrlParkoutSide.f32steerFinishGap           = 20;
    g_stCtrlParkoutSide.f32NarrowFinishDis          = stCalibPF_ptr->stPFPkoutCalib.Calib_i16SpaceLimit;
    g_stCtrlParkoutSide.f32FrontEmptyFinishDis      = stCalibPF_ptr->stPFPkoutCalib.Calib_f32PkoutFrontDisLimit;
    g_stCtrlParkoutSide.f32SideNarrowFinishDis      = stCalibPF_ptr->stPFPkoutCalib.Calib_i16PkoutSideDisLimit;
    g_stCtrlParkoutSide.f32DriveBackMinDis          = 60;
    g_stCtrlParkoutSide.f32FrontNarrowFinishDis     = stCalibPF_ptr->stPFPkoutCalib.Calib_i16PkoutStraightFrontDisLimit;
    g_stCtrlParkoutSide.bParkOutPreFinishFlag       = 0;
    g_stCtrlParkoutSide.bParkOutFinishFlag          = 0;
    g_stCtrlParkoutSide.iParkOutInitCheckWaitTime   = 0;

    if ((DRIVER_CTRL_PARKOUT_NOPP_LEFT == g_stCtrlFuncFsmInfo.eLsadDriverCtrlCommand) || 
        (DRIVER_CTRL_PARKOUT_NOPP_RIGHT == g_stCtrlFuncFsmInfo.eLsadDriverCtrlCommand))
    {
        g_stCtrlLongiInfo.eGearReq = R_GEAR;
    }
    else if (DRIVER_CTRL_PARKOUT_NOPP_MIDDLE == g_stCtrlFuncFsmInfo.eLsadDriverCtrlCommand)
    {
        g_stCtrlLongiInfo.eGearReq = D_GEAR;
    }
    else
    {
        ;
    }

    return E_OK;
}


static uint8_t ParkOutInitCheck(tCtrlUssInfo* stCtrlUssInfo_ptr)
{

    float f32USSFrontDis                        = 0;
    float f32USSBackDis                         = 0;
    g_stCtrlParkoutSide.eParkOutFinishCode      = NoReason;
    g_stCtrlParkoutSide.f32InitTheta            = g_stCtrlVehPose.stCurrentPos.f32Theta;
    g_stCtrlParkoutSide.f32RecordTrack          = g_stCtrlVehPose.stCurrentPos.f32Track;

    //Left to Right 1, 2, 3, 4

    if(stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_FRONT_LEFT_2_DIS] < stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_FRONT_LEFT_3_DIS])
    {
        f32USSFrontDis = stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_FRONT_LEFT_2_DIS];
    }
    else
    {
        f32USSFrontDis = stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_FRONT_LEFT_3_DIS];
    }

    if(stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_REAR_LEFT_2_DIS] < stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_REAR_LEFT_3_DIS])
    {
        f32USSBackDis = stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_REAR_LEFT_2_DIS];
    }
    else
    {
        f32USSBackDis = stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_REAR_LEFT_3_DIS];
    }

    if ((LeftParkOut == g_stCtrlParkoutSide.eParkOutType) || (RightParkOut == g_stCtrlParkoutSide.eParkOutType))
    {
        
        if(f32USSFrontDis > g_stCtrlParkoutSide.f32FrontEmptyFinishDis)
        {
            g_stCtrlParkoutSide.eParkOutFinishCode = ParkSlotWideParkOutComplete;  //No Obstacle in front, ParkOut Complete
            g_stCtrlParkoutSide.bParkOutPreFinishFlag = 1;
            return E_OK;
        }
        else
        {
            ;
        }

        if(f32USSFrontDis + f32USSBackDis < g_stCtrlParkoutSide.f32NarrowFinishDis)
        {
            g_stCtrlParkoutSide.eParkOutFinishCode = ParkSlotNarrowParkOutFail;  //No Obstacle in front, ParkOut Complete
            g_stCtrlParkoutSide.bParkOutPreFinishFlag = 1;
            return E_OK;
        }

        if (DRIVER_CTRL_PARKOUT_NOPP_LEFT == g_stCtrlFuncFsmInfo.eLsadFuncType)
        {
            if((stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_SIDE_FRONT_LEFT_DIS] < g_stCtrlParkoutSide.f32SideNarrowFinishDis)|| 
               (stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_SIDE_REAR_LEFT_DIS]  < g_stCtrlParkoutSide.f32SideNarrowFinishDis))
            {
                g_stCtrlParkoutSide.eParkOutFinishCode = ParkOutLeftBlock;
                g_stCtrlParkoutSide.bParkOutPreFinishFlag = 1;
            }
        }
        else if (DRIVER_CTRL_PARKOUT_NOPP_RIGHT == g_stCtrlFuncFsmInfo.eLsadFuncType)
        {
            if((stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_SIDE_FRONT_RIGHT_DIS] < g_stCtrlParkoutSide.f32SideNarrowFinishDis)|| 
               (stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_SIDE_REAR_RIGHT_DIS]  < g_stCtrlParkoutSide.f32SideNarrowFinishDis))
            {
                g_stCtrlParkoutSide.eParkOutFinishCode = ParkOutRightBlock;
                g_stCtrlParkoutSide.bParkOutPreFinishFlag = 1;
            }
        }
    }
    else if (StraightForwardParkOut == g_stCtrlParkoutSide.eParkOutType)
    {
        if (f32USSFrontDis < g_stCtrlParkoutSide.f32FrontNarrowFinishDis)
        {
            g_stCtrlParkoutSide.eParkOutFinishCode = ParkOutStraightObsFront;  //Obstacle in front, ParkOut Complete
            g_stCtrlParkoutSide.bParkOutPreFinishFlag = 1;
            return E_OK;
        }
        else
        {
            ;
        }
    }
    else
    {
        ;
    }

    return E_OK;
}


static uint8_t ParkOutPhaseInit(tCtrlUssInfo* stCtrlUssInfo_ptr)
{

    // if ((ParkOutPhaseDefault == g_stCtrlParkoutSide.eParkOutPhase) &&
    //     ((LeftParkOut == g_stCtrlParkoutSide.eParkOutType) ||
    //      (RightParkOut == g_stCtrlParkoutSide.eParkOutType)))
    // {
    //     g_stCtrlLongiInfo.eGearReq = VEHI_GEAR_R;
    // }
    // else if ((ParkOutPhaseDefault == g_stCtrlParkoutSide.eParkOutPhase) &&
    //          (StraightForwardParkOut == g_stCtrlParkoutSide.eParkOutType))
    // {
    //     g_stCtrlLongiInfo.eGearReq = VEHI_GEAR_D;
    // }
    // else
    // {
    //     ;
    // }


    float f32USSBackDis = 0;
    if(stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_REAR_LEFT_2_DIS] < stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_REAR_LEFT_3_DIS])
    {
        f32USSBackDis = stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_REAR_LEFT_2_DIS];
    }
    else
    {
        f32USSBackDis = stCtrlUssInfo_ptr->u16PebDistanceOriginal[PEB_REAR_LEFT_3_DIS];
    }

    if ((ParkOutPhaseDefault == g_stCtrlParkoutSide.eParkOutPhase) &&
        (R_GEAR == g_stCtrlVehDataRx.sVehVCUInfo.eVehActualGear) &&
        ((LeftParkOut == g_stCtrlParkoutSide.eParkOutType) || 
         (RightParkOut == g_stCtrlParkoutSide.eParkOutType)))
    {
        if(f32USSBackDis > g_stCtrlParkoutSide.f32DriveBackMinDis)
        {
            g_stCtrlParkoutSide.eParkOutPhase = DriveBack;
        }
        else
        {
            if (LeftParkOut == g_stCtrlParkoutSide.eParkOutType)
            {
                g_stCtrlParkoutSide.eParkOutPhase = RightBackward;
            }
            else
            {
                g_stCtrlParkoutSide.eParkOutPhase = LeftBackward;
            }
        }
    }
    else
    {
        ;
    }

    if ((ParkOutPhaseDefault == g_stCtrlParkoutSide.eParkOutPhase) &&
        (D_GEAR == g_stCtrlVehDataRx.sVehVCUInfo.eVehActualGear) &&
        (StraightForwardParkOut == g_stCtrlParkoutSide.eParkOutType))
    {
        g_stCtrlParkoutSide.eParkOutPhase = DriveFront;
    }

    return E_OK;

}


static uint8_t Ctrl_ParkOutFinish(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                  tCtrlParkOutSide*         stCtrlParkoutSide_ptr,
                                  tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                  tCtrlVehiclePosition*       stCurrentPos_ptr)
{
    
    if (((fabs(g_stCtrlParkoutSide.f32InitTheta - g_stCtrlVehPose.stCurrentPos.f32Theta) > stCtrlParkoutSide_ptr->f32TargetTheta) &&
         ((LeftParkOut == g_stCtrlParkoutSide.eParkOutType) || (RightParkOut == g_stCtrlParkoutSide.eParkOutType))) || 
        (((stCtrlParkoutSide_ptr->f32DistanceTravel > stCtrlLongiInfo_ptr->f32TotalStopDistance) || (1 == stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebHappened)) &&
         (StraightForwardParkOut == g_stCtrlParkoutSide.eParkOutType)))
    {
        stCtrlParkoutSide_ptr->eParkOutPhase = ParkOutComplete;
    }
    else
    {
        ;
    }

    return E_OK;
}


static uint8_t Ctrl_ParkOutLeftSide(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                    tVehDataRx*   stVehDataRx_ptr,
                                    tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                    tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                    tCtrlParkOutSide*         stCtrlParkoutSide_ptr,
                                    tCtrlVehiclePosition*       stCurrentPos_ptr)
{

    stCtrlParkoutSide_ptr->f32ParkingPercentage = fabs(g_stCtrlParkoutSide.f32InitTheta - g_stCtrlVehPose.stCurrentPos.f32Theta) / stCtrlParkoutSide_ptr->f32TargetTheta;

    stCtrlParkoutSide_ptr->f32DistanceTravel = stCurrentPos_ptr->f32Track - stCtrlParkoutSide_ptr->f32RecordTrack;
    Ctrl_ParkOutFinish(stCtrlCommonInfo_ptr, stCtrlParkoutSide_ptr, stCtrlLongiInfo_ptr, stCurrentPos_ptr);

    switch (stCtrlParkoutSide_ptr->eParkOutPhase)
    {
        case DriveBack:

            Ctrl_ParkOutDriveBack(stCtrlCommonInfo_ptr,
                                  stVehDataRx_ptr,
                                  stCtrlLongiInfo_ptr,
                                  stCtrlLatInfo_ptr,
                                  stCtrlParkoutSide_ptr,
                                  stCurrentPos_ptr);

            break;

        case LeftForward:

            Ctrl_ParkOutLeftForward(stCtrlCommonInfo_ptr,
                                    stVehDataRx_ptr,
                                    stCtrlLongiInfo_ptr,
                                    stCtrlLatInfo_ptr,
                                    stCtrlParkoutSide_ptr,
                                    stCurrentPos_ptr);
        
            break;

        case RightBackward:

            Ctrl_ParkOutRightBackward(stCtrlCommonInfo_ptr,
                                      stVehDataRx_ptr,
                                      stCtrlLongiInfo_ptr,
                                      stCtrlLatInfo_ptr,
                                      stCtrlParkoutSide_ptr,
                                      stCurrentPos_ptr);
            

            break;

        case ParkOutComplete:

            Ctrl_ParkOutDownComplete(stCtrlCommonInfo_ptr,
                                        stVehDataRx_ptr,
                                        stCtrlLongiInfo_ptr,
                                        stCtrlLatInfo_ptr,
                                        stCtrlParkoutSide_ptr,
                                        stCurrentPos_ptr);
            

            break;

        default:
            
            ;

            break;

    }

    return E_OK;
}


static uint8_t Ctrl_ParkOutRightSide(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                     tVehDataRx*   stVehDataRx_ptr,
                                     tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                     tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                     tCtrlParkOutSide*         stCtrlParkoutSide_ptr,
                                     tCtrlVehiclePosition*       stCurrentPos_ptr)
{

    stCtrlParkoutSide_ptr->f32ParkingPercentage = fabs(g_stCtrlParkoutSide.f32InitTheta - g_stCtrlVehPose.stCurrentPos.f32Theta) / stCtrlParkoutSide_ptr->f32TargetTheta;

    stCtrlParkoutSide_ptr->f32DistanceTravel = stCurrentPos_ptr->f32Track - stCtrlParkoutSide_ptr->f32RecordTrack;
    Ctrl_ParkOutFinish(stCtrlCommonInfo_ptr, stCtrlParkoutSide_ptr, stCtrlLongiInfo_ptr, stCurrentPos_ptr);

    switch (stCtrlParkoutSide_ptr->eParkOutPhase)
    {
        case DriveBack:

            Ctrl_ParkOutDriveBack(stCtrlCommonInfo_ptr,
                                  stVehDataRx_ptr,
                                  stCtrlLongiInfo_ptr,
                                  stCtrlLatInfo_ptr,
                                  stCtrlParkoutSide_ptr,
                                  stCurrentPos_ptr);

            break;

        case RightForward:

            Ctrl_ParkOutRightForward(stCtrlCommonInfo_ptr,
                                     stVehDataRx_ptr,
                                     stCtrlLongiInfo_ptr,
                                     stCtrlLatInfo_ptr,
                                     stCtrlParkoutSide_ptr,
                                     stCurrentPos_ptr);

            break;

        case LeftBackward:

            Ctrl_ParkOutLeftBackward(stCtrlCommonInfo_ptr,
                                     stVehDataRx_ptr,
                                     stCtrlLongiInfo_ptr,
                                     stCtrlLatInfo_ptr,
                                     stCtrlParkoutSide_ptr,
                                     stCurrentPos_ptr);

            break;

        case ParkOutComplete:

            Ctrl_ParkOutDownComplete(stCtrlCommonInfo_ptr,
                                        stVehDataRx_ptr,
                                        stCtrlLongiInfo_ptr,
                                        stCtrlLatInfo_ptr,
                                        stCtrlParkoutSide_ptr,
                                        stCurrentPos_ptr);

            break;

        default:
            
            ;

            break;
    }

    return E_OK;
}


static uint8_t Ctrl_ParkOutStraightFarward(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                           tVehDataRx*   stVehDataRx_ptr,
                                           tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                           tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                           tCtrlParkOutSide*         stCtrlParkoutSide_ptr,
                                           tCtrlVehiclePosition*       stCurrentPos_ptr)
{
    stCtrlParkoutSide_ptr->f32DistanceTravel = stCurrentPos_ptr->f32Track - stCtrlParkoutSide_ptr->f32RecordTrack;
    stCtrlLongiInfo_ptr->f32TargetStopDistance = stCtrlLongiInfo_ptr->f32TotalStopDistance - stCtrlParkoutSide_ptr->f32DistanceTravel;
    stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetWheelAngle = 0;
    stCtrlParkoutSide_ptr->f32ParkingPercentage = stCtrlParkoutSide_ptr->f32DistanceTravel / stCtrlLongiInfo_ptr->f32TotalStopDistance;
    Ctrl_ParkOutFinish(stCtrlCommonInfo_ptr, stCtrlParkoutSide_ptr, stCtrlLongiInfo_ptr, stCurrentPos_ptr);

    switch (stCtrlParkoutSide_ptr->eParkOutPhase)
    {
        case DriveFront:

            Ctrl_ParkOutDriveFront(stCtrlCommonInfo_ptr,
                                   stVehDataRx_ptr,
                                   stCtrlLongiInfo_ptr,
                                   stCtrlLatInfo_ptr,
                                   stCtrlParkoutSide_ptr,
                                   stCurrentPos_ptr);

            break;

        case ParkOutComplete:

            Ctrl_ParkOutDownComplete(stCtrlCommonInfo_ptr,
                                        stVehDataRx_ptr,
                                        stCtrlLongiInfo_ptr,
                                        stCtrlLatInfo_ptr,
                                        stCtrlParkoutSide_ptr,
                                        stCurrentPos_ptr);

            break;

        default:
            
            ;

            break;
    }

    return E_OK;
}


static uint8_t Ctrl_ParkOutDriveBack(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                     tVehDataRx*   stVehDataRx_ptr,
                                     tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                     tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                     tCtrlParkOutSide*         stCtrlParkoutSide_ptr,
                                     tCtrlVehiclePosition*       stCurrentPos_ptr)
{
    
    stCtrlLongiInfo_ptr->f32TargetStopDistance = stCtrlLongiInfo_ptr->f32TotalStopDistance - stCtrlParkoutSide_ptr->f32DistanceTravel;
    stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetWheelAngle = 0;

    if (R_GEAR == stVehDataRx_ptr->sVehVCUInfo.eVehActualGear)
    {
        if(fabs(stVehDataRx_ptr->sVehEPSInfo.f32StrWhlAngDeg- stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetWheelAngle) < stCtrlParkoutSide_ptr->f32steerGap)
        {
            stCtrlLongiInfo_ptr->f32TargetVehSpeed = stCtrlParkoutSide_ptr->f32targetSpeed;
        }
        else
        {
            stCtrlLongiInfo_ptr->f32TargetVehSpeed = 0;
        }

        if ((1 == stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebHappened) || 
            (stCtrlLongiInfo_ptr->f32TargetStopDistance < stCtrlParkoutSide_ptr->f32stopDis))
        {
            stCtrlLongiInfo_ptr->f32TargetVehSpeed = 0;
            if(stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph < stCtrlParkoutSide_ptr->f32minSpeed)
            {
                stCtrlLongiInfo_ptr->eGearReq = D_GEAR;
                stCtrlParkoutSide_ptr->f32RecordTrack = stCurrentPos_ptr->f32Track;
                stCtrlLongiInfo_ptr->f32TargetStopDistance = 0;
            }
        }
    }
    else if (D_GEAR == stVehDataRx_ptr->sVehVCUInfo.eVehActualGear)
    {
        if (LeftParkOut == g_stCtrlParkoutSide.eParkOutType)
        {
            stCtrlParkoutSide_ptr->eParkOutPhase = LeftForward;
        }
        else
        {
            stCtrlParkoutSide_ptr->eParkOutPhase = RightForward;
        }
    }
    else
    {
        ;
    }

    return E_OK;
}


static uint8_t Ctrl_ParkOutDriveFront(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                      tVehDataRx*   stVehDataRx_ptr,
                                      tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                      tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                      tCtrlParkOutSide*         stCtrlParkoutSide_ptr,
                                      tCtrlVehiclePosition*       stCurrentPos_ptr)
{
    stCtrlLongiInfo_ptr->f32TargetStopDistance = stCtrlLongiInfo_ptr->f32TotalStopDistance - stCtrlParkoutSide_ptr->f32DistanceTravel;
    stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetWheelAngle = 0;

    if (D_GEAR == stVehDataRx_ptr->sVehVCUInfo.eVehActualGear)
    {
        if(fabs(stVehDataRx_ptr->sVehEPSInfo.f32StrWhlAngDeg - stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetWheelAngle) < stCtrlParkoutSide_ptr->f32steerGap)
        {
            stCtrlLongiInfo_ptr->f32TargetVehSpeed = stCtrlParkoutSide_ptr->f32targetSpeed;
        }
        else
        {
            stCtrlLongiInfo_ptr->f32TargetVehSpeed = 0;
        }
    }
    else
    {
        ;
    }

    return E_OK;
}


static uint8_t Ctrl_ParkOutLeftForward(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                       tVehDataRx*   stVehDataRx_ptr,
                                       tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                       tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                       tCtrlParkOutSide*         stCtrlParkoutSide_ptr,
                                       tCtrlVehiclePosition*       stCurrentPos_ptr)
{
    stCtrlLongiInfo_ptr->f32TargetStopDistance = stCtrlLongiInfo_ptr->f32TotalStopDistance - stCtrlParkoutSide_ptr->f32DistanceTravel;
    stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetWheelAngle = stCtrlParkoutSide_ptr->f32maxSteer;

    if (D_GEAR == stVehDataRx_ptr->sVehVCUInfo.eVehActualGear)
    {
        if(fabs(stVehDataRx_ptr->sVehEPSInfo.f32StrWhlAngDeg - stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetWheelAngle) < stCtrlParkoutSide_ptr->f32steerGap)
        {
            stCtrlLongiInfo_ptr->f32TargetVehSpeed = stCtrlParkoutSide_ptr->f32targetSpeed;
        }
        else
        {
            stCtrlLongiInfo_ptr->f32TargetVehSpeed = 0;
        }

        if ((1 == stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebHappened) || 
            (stCtrlLongiInfo_ptr->f32TargetStopDistance < stCtrlParkoutSide_ptr->f32stopDis))
        {
            stCtrlLongiInfo_ptr->f32TargetVehSpeed = 0;
            if(stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph < stCtrlParkoutSide_ptr->f32minSpeed)
            {
                stCtrlLongiInfo_ptr->eGearReq = R_GEAR;
                stCtrlParkoutSide_ptr->f32RecordTrack = stCurrentPos_ptr->f32Track;
                stCtrlLongiInfo_ptr->f32TargetStopDistance = 0;
            }
        }
    }
    else if (R_GEAR == stVehDataRx_ptr->sVehVCUInfo.eVehActualGear)
    {
        stCtrlParkoutSide_ptr->eParkOutPhase = RightBackward;
    }
    else
    {
        ;
    }

    return E_OK;
}


static uint8_t Ctrl_ParkOutRightForward(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                        tVehDataRx*   stVehDataRx_ptr,
                                        tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                        tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                        tCtrlParkOutSide*         stCtrlParkoutSide_ptr,
                                        tCtrlVehiclePosition*       stCurrentPos_ptr)
{
    stCtrlLongiInfo_ptr->f32TargetStopDistance = stCtrlLongiInfo_ptr->f32TotalStopDistance - stCtrlParkoutSide_ptr->f32DistanceTravel;
    stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetWheelAngle = -1 * stCtrlParkoutSide_ptr->f32maxSteer;

    if (D_GEAR == stVehDataRx_ptr->sVehVCUInfo.eVehActualGear)
    {
        if(fabs(stVehDataRx_ptr->sVehEPSInfo.f32StrWhlAngDeg - stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetWheelAngle) < stCtrlParkoutSide_ptr->f32steerGap)
        {
            stCtrlLongiInfo_ptr->f32TargetVehSpeed = stCtrlParkoutSide_ptr->f32targetSpeed;
        }
        else
        {
            stCtrlLongiInfo_ptr->f32TargetVehSpeed = 0;
        }

        if ((1 == stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebHappened) || 
            (stCtrlLongiInfo_ptr->f32TargetStopDistance < stCtrlParkoutSide_ptr->f32stopDis))
        {
            stCtrlLongiInfo_ptr->f32TargetVehSpeed = 0;
            if(stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph < stCtrlParkoutSide_ptr->f32minSpeed)
            {
                stCtrlLongiInfo_ptr->eGearReq = R_GEAR;
                stCtrlParkoutSide_ptr->f32RecordTrack = stCurrentPos_ptr->f32Track;
                stCtrlLongiInfo_ptr->f32TargetStopDistance = 0;
            }
        }
    }
    else if (R_GEAR == stVehDataRx_ptr->sVehVCUInfo.eVehActualGear)
    {
        stCtrlParkoutSide_ptr->eParkOutPhase = LeftBackward;
    }
    else
    {
        ;
    }

    return E_OK;
}


static uint8_t Ctrl_ParkOutRightBackward(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                         tVehDataRx*   stVehDataRx_ptr,
                                         tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                         tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                         tCtrlParkOutSide*         stCtrlParkoutSide_ptr,
                                         tCtrlVehiclePosition*       stCurrentPos_ptr)
{
    stCtrlLongiInfo_ptr->f32TargetStopDistance = stCtrlLongiInfo_ptr->f32TotalStopDistance - stCtrlParkoutSide_ptr->f32DistanceTravel;
    stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetWheelAngle = -1 * stCtrlParkoutSide_ptr->f32maxSteer;

    if (R_GEAR == stVehDataRx_ptr->sVehVCUInfo.eVehActualGear)
    {
        if(fabs(stVehDataRx_ptr->sVehEPSInfo.f32StrWhlAngDeg - stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetWheelAngle) < stCtrlParkoutSide_ptr->f32steerGap)
        {
            stCtrlLongiInfo_ptr->f32TargetVehSpeed = stCtrlParkoutSide_ptr->f32targetSpeed;
        }
        else
        {
            stCtrlLongiInfo_ptr->f32TargetVehSpeed = 0;
        }

        if ((1 == stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebHappened) || 
            (stCtrlLongiInfo_ptr->f32TargetStopDistance < stCtrlParkoutSide_ptr->f32stopDis))
        {
            stCtrlLongiInfo_ptr->f32TargetVehSpeed = 0;
            if(stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph < stCtrlParkoutSide_ptr->f32minSpeed)
            {
                stCtrlLongiInfo_ptr->eGearReq = D_GEAR;
                stCtrlParkoutSide_ptr->f32RecordTrack = stCurrentPos_ptr->f32Track;
                stCtrlLongiInfo_ptr->f32TargetStopDistance = 0;
            }
        }
    }
    else if (D_GEAR == stVehDataRx_ptr->sVehVCUInfo.eVehActualGear)
    {
        stCtrlParkoutSide_ptr->eParkOutPhase = LeftForward;
    }
    else
    {
        ;
    }

    return E_OK;
}



static uint8_t Ctrl_ParkOutLeftBackward(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                        tVehDataRx*   stVehDataRx_ptr,
                                        tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                        tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                        tCtrlParkOutSide*         stCtrlParkoutSide_ptr,
                                        tCtrlVehiclePosition*       stCurrentPos_ptr)
{
    stCtrlLongiInfo_ptr->f32TargetStopDistance = stCtrlLongiInfo_ptr->f32TotalStopDistance - stCtrlParkoutSide_ptr->f32DistanceTravel;
    stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetWheelAngle = stCtrlParkoutSide_ptr->f32maxSteer;

    if (R_GEAR == stVehDataRx_ptr->sVehVCUInfo.eVehActualGear)
    {
        if(fabs(stVehDataRx_ptr->sVehEPSInfo.f32StrWhlAngDeg - stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetWheelAngle) < stCtrlParkoutSide_ptr->f32steerGap)
        {
            stCtrlLongiInfo_ptr->f32TargetVehSpeed = stCtrlParkoutSide_ptr->f32targetSpeed;
        }
        else
        {
            stCtrlLongiInfo_ptr->f32TargetVehSpeed = 0;
        }

        if ((1 == stCtrlCommonInfo_ptr->stCtrlPebInfo.u8PebHappened) || 
            (stCtrlLongiInfo_ptr->f32TargetStopDistance < stCtrlParkoutSide_ptr->f32stopDis))
        {
            stCtrlLongiInfo_ptr->f32TargetVehSpeed = 0;
            if(stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph < stCtrlParkoutSide_ptr->f32minSpeed)
            {
                stCtrlLongiInfo_ptr->eGearReq = D_GEAR;
                stCtrlParkoutSide_ptr->f32RecordTrack = stCurrentPos_ptr->f32Track;
                stCtrlLongiInfo_ptr->f32TargetStopDistance = 0;
            }
        }
    }
    else if (D_GEAR == stVehDataRx_ptr->sVehVCUInfo.eVehActualGear)
    {
        stCtrlParkoutSide_ptr->eParkOutPhase = RightForward;
    }
    else
    {
        ;
    }

    return E_OK;
}



static uint8_t Ctrl_ParkOutComplete(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                    tVehDataRx*   stVehDataRx_ptr,
                                    tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                    tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                    tCtrlParkOutSide*         stCtrlParkoutSide_ptr,
                                    tCtrlVehiclePosition*       stCurrentPos_ptr)
{
    stCtrlLongiInfo_ptr->eGearReq = stVehDataRx_ptr->sVehVCUInfo.eVehActualGear;
    stCtrlLongiInfo_ptr->f32TargetVehSpeed = 0;
    stCtrlLongiInfo_ptr->f32TargetAcce = -0.5;
    stCtrlLongiInfo_ptr->f32TargetStopDistance = 0;
    stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetWheelAngle = stVehDataRx_ptr->sVehEPSInfo.f32StrWhlAngDeg;
    if(stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph < 0.05)
    {
        stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetWheelAngle = 0;
        stCtrlLongiInfo_ptr->eGearReq = P_GEAR;

        if((P_GEAR == stVehDataRx_ptr->sVehVCUInfo.eVehActualGear) && 
            (fabs(stVehDataRx_ptr->sVehEPSInfo.f32StrWhlAngDeg - stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetWheelAngle) < g_stCtrlParkoutSide.f32steerFinishGap))
        {
            stCtrlParkoutSide_ptr->bParkOutFinishFlag = 1;
        }

    }
    else
    {
        ;
    }

    return E_OK;
}



static uint8_t Ctrl_ParkOutDownComplete(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                        tVehDataRx*   stVehDataRx_ptr,
                                        tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                        tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                        tCtrlParkOutSide*         stCtrlParkoutSide_ptr,
                                        tCtrlVehiclePosition*       stCurrentPos_ptr)
{
    stCtrlLongiInfo_ptr->eGearReq = stVehDataRx_ptr->sVehVCUInfo.eVehActualGear;
    stCtrlLongiInfo_ptr->f32TargetVehSpeed = 0;
    stCtrlLongiInfo_ptr->f32TargetAcce = -0.5;
    stCtrlLongiInfo_ptr->f32TargetStopDistance = 0;
    stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetWheelAngle = stVehDataRx_ptr->sVehEPSInfo.f32StrWhlAngDeg;
    if(stVehDataRx_ptr->sVehESCInfo.f32VehSpdKph < 0.05)
    {
        stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetWheelAngle = 0;
        stCtrlLongiInfo_ptr->eGearReq = P_GEAR;

        if((P_GEAR == stVehDataRx_ptr->sVehVCUInfo.eVehActualGear) && 
            (fabs(stVehDataRx_ptr->sVehEPSInfo.f32StrWhlAngDeg - stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetWheelAngle) < g_stCtrlParkoutSide.f32steerFinishGap))
        {
            g_stCtrlParkoutSide.eParkOutFinishCode = ParkOutFinish;
            stCtrlParkoutSide_ptr->bParkOutFinishFlag = 1;
        }

    }
    else
    {
        ;
    }

    return E_OK;
}



static uint8_t Ctrl_ParkOutOutput(tCtrlCommonInfo*          stCtrlCommonInfo_ptr,
                                  tCtrlLongiInfo*           stCtrlLongiInfo_ptr,
                                  tCtrlLatInfo*             stCtrlLatInfo_ptr,
                                  tCtrlToChassisInfo*       stCtrlToChassisInfo_ptr)
{
    stCtrlToChassisInfo_ptr->eGearReq = stCtrlLongiInfo_ptr->eGearReq;
    if (stCtrlLongiInfo_ptr->f32TargetVehSpeed < stCtrlCommonInfo_ptr->stCtrlPebInfo.f32PebSpeed)
    {
        stCtrlToChassisInfo_ptr->f32CtrlReqSpeed = stCtrlLongiInfo_ptr->f32TargetVehSpeed;
    }
    else
    {
        stCtrlToChassisInfo_ptr->f32CtrlReqSpeed = stCtrlCommonInfo_ptr->stCtrlPebInfo.f32PebSpeed;
    }
    stCtrlToChassisInfo_ptr->f32CtrlReqAccel = stCtrlLongiInfo_ptr->f32TargetAcce;
    stCtrlToChassisInfo_ptr->f32CtrlReqStopDistance = stCtrlLongiInfo_ptr->f32TargetStopDistance;
    stCtrlToChassisInfo_ptr->f32CtrlReqSteerUnlimited = stCtrlLatInfo_ptr->stCtrlLatResult.f32TargetWheelAngle;
    Ctrl_LimitationLat(&g_stCtrlLongiInfo, &g_stCtrlCommonInfo, &g_stCtrlToChassisInfo);

    return E_OK;
}

