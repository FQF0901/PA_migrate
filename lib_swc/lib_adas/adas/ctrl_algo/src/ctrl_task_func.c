#include <math.h>
#include "adas_interface.h"
#include "adas_project_input.h"
#include "ctrl_task_func.h"
#include "ctrl_global_variables.h"
#include "lib_adas_adapter/vehicle_service/ctrl_adapter/ctrl_adapter.h"
#include "parking/ctrl_apa_parking.h"
#include "parking/ctrl_apa_straight.h"
#include "parking/ctrl_apa_sideout.h"
#include "cruising/ctrl_cruising.h"
#include "vehicle_service/calib/vehsrv_calib.h"
#include "ctrl_diag.h"
//#include "global_var_api.h"


static uint8_t Ctrl_RunModuleStateMachine(tCtrlFuncFsmInfo*        stCtrlApaShellInfo_ptr,
                                          tCtrlCommonInfo*          stCtrlCommonInfo_ptr);
static uint8_t Ctrl_ModuleStateMachineResult(tCtrlFuncFsmInfo*        stCtrlApaShellInfo_ptr,
                                             tCtrlCommonInfo*          stCtrlCommonInfo_ptr);
static uint8_t Ctrl_StateMachineFuncStatusActions_20ms(void);
static uint8_t Ctrl_StateMachineFuncTypeActions_20ms(void);


// --- Temp solution for USS unlock.
// static uint16_t u16UnlockUssSignal = 0;
// static uint8_t u8UnlockUssCounter = 0;
// static uint8_t u8UnlockUssSwitchFlag = 0;
// --- Temp solution for USS unlock. END

/**
*************************************************************************
  * FUNCTION_NAME 
Ctrl_TaskInit. 

  * EXPLANATION   
Current solution: Ctrl initializes at the beginning of its 20ms task, including 
DR initialization.
Better solution: MCU platform is responsible for all initialization.


*************************************************************************
*/

EM_ADAS_ReturnType Ctrl_TaskInit()
{
    VehSrv_CalibInit();
    Ctrl_LogClean();
    Dr_Init_20ms_Task();
    Ctrl_VariablesInit();
    Ctrl_VehDiagReset_20ms();

    return (EM_ADAS_ReturnType)E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME 
Ctrl_InputAdapter_20ms. 

  * EXPLANATION   
It is the input interface adapter of ctrl module. 
 - From CAN.
 - From perception.
 - From path planner.
 - From apa shell fsm.

*************************************************************************
*/

uint8_t Ctrl_InputAdapter_20ms()
{
    Ctrl_ReceiveFromVehInterface(&g_stCtrlVehDataRx);
    Ctrl_ReceiveFromApaShell(&g_stCtrlFuncFsmInfo);
    Ctrl_ReceiveFromUSS(&g_stCtrlUssInfo);
    Ctrl_ReceiveFromPathPlanner(&g_stPathPlannerData, &g_stCtrlCommonInfo, &g_stCtrlFuncFsmInfo);
    Ctrl_ReceiveFromLocalization(&g_stCtrlVehPose);

    return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME 
Ctrl_FunctionStateMachine_20ms. 

  * EXPLANATION   
State machine of ctrl module. It receive the status of APA shell state machine,
and adjust the corresponding state in Ctrl.  

*************************************************************************
*/

uint8_t Ctrl_FunctionStateMachine_20ms()
{
    Ctrl_RunModuleStateMachine(&g_stCtrlFuncFsmInfo, &g_stCtrlCommonInfo);
    Ctrl_ModuleStateMachineResult(&g_stCtrlFuncFsmInfo, &g_stCtrlCommonInfo);

	return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME 
Ctrl_StateMachineActions_20ms. 

  * EXPLANATION   
In each state of the SM, actions will be made based on function status and 
function types. 

*************************************************************************
*/


uint8_t Ctrl_StateMachineActions_20ms()
{
    Ctrl_StateMachineFuncStatusActions_20ms();
    Ctrl_StateMachineFuncTypeActions_20ms();

    return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME 
Ctrl_OutputAdapter_20ms. 

  * EXPLANATION   
It is the output interface adapter of ctrl module. It's the confluence of outputs, 
including the data to be send to CAN (e.g. target vehicle speed), and the 
data to be send to path planner in SOC (e.g. ctrl algorithm status).  

*************************************************************************
*/

uint8_t Ctrl_OutputAdapter_20ms()
{
    Ctrl_SendToCAN(&g_sVehDataRx,&g_stCtrlToChassisInfo,&g_stCtrlFuncFsmInfo);
    Ctrl_SendToApaShell(&g_stCtrlToFuncStateMachine);
    Ctrl_SendToSOC(&g_stCtrlToPathPlannerInfo, &g_stCtrlLogInfo, &g_stCtrlToFuncStateMachine);

    return E_OK;
}





/*	=====================================================================
 *
 *						static function definitions
 *
 *	===================================================================*/

/**
*************************************************************************
  * FUNCTION_NAME 
Ctrl_RunModuleStateMachine. 

  * EXPLANATION   
Ctrl module state machine. 

*************************************************************************
*/

static uint8_t Ctrl_RunModuleStateMachine(tCtrlFuncFsmInfo*        stCtrlApaShellInfo_ptr,
                                          tCtrlCommonInfo*          stCtrlCommonInfo_ptr)
{
    tLSAD_SystemSts eApaStatus = stCtrlApaShellInfo_ptr->eLsadSystemSts;
    tLSAD_SystemSts eApaStatusPrev = stCtrlApaShellInfo_ptr->eLsadSystemStsPrev;
    tCtrlFinishType eCtrlFinishType = stCtrlCommonInfo_ptr->eCtrlFinishType;
    uint8_t u8PauseFlag       = stCtrlCommonInfo_ptr->u8PauseFlag;
    tCtrl_Module_Status eCtrlFuncStatus   = stCtrlCommonInfo_ptr->eCtrlFuncStatus;
    stCtrlCommonInfo_ptr->eCtrlFuncStatusPrev   =   eCtrlFuncStatus;

    switch (eCtrlFuncStatus)
    {
        case CTRL_MODULE_OFF: 
            if (eApaStatus != LSAD_STS_OFF)
            {
                eCtrlFuncStatus = CTRL_MODULE_STANDBY;
            }
            break;

        case CTRL_MODULE_STANDBY:
            if (LSAD_STS_ACTIVE == eApaStatus)
            {
                eCtrlFuncStatus = CTRL_MODULE_ACTIVE;
            }
            break;

        case CTRL_MODULE_ACTIVE:
            // During Active, there are 3 possible transitions. 
            if (CTRL_FINISH_TYPE_APA == eCtrlFinishType || CTRL_FINISH_TYPE_HPP == eCtrlFinishType)  // Complete. Ctrl finishes the last path and also the "finish actions". 
            {
                eCtrlFuncStatus = CTRL_MODULE_FINISH;
            }
            else if (LSAD_STS_ACTIVE_SUSPEND == eApaStatus || 1 == u8PauseFlag)    // Pause. Either triggered by driver, or triggered by PEB.
            {
                eCtrlFuncStatus = CTRL_MODULE_PAUSE;
            }
            break;

        case CTRL_MODULE_PAUSE:
            if (LSAD_STS_ACTIVE_SUSPEND == eApaStatusPrev && LSAD_STS_ACTIVE == eApaStatus)
            {
                eCtrlFuncStatus = CTRL_MODULE_ACTIVE;
            }
            break;

        case CTRL_MODULE_FINISH:
            if (LSAD_STS_STANDBY == eApaStatus ||LSAD_STS_PREPARE == eApaStatus ||LSAD_STS_PREPARE_SUSPEND == eApaStatus)  // LSAD_HPP_STS_WaveHand: After cruise finished, ctrl init. 
            {
                eCtrlFuncStatus = CTRL_MODULE_STANDBY;
            }
            break;

        default:
            ;
            break;
    }

    if (LSAD_STS_TERMINATED == eApaStatus || LSAD_STS_FAILURE == eApaStatus)
    {
        eCtrlFuncStatus = CTRL_MODULE_FINISH;
    }
    else if(LSAD_STS_STANDBY== eApaStatus)
    {
        eCtrlFuncStatus = CTRL_MODULE_STANDBY;
    }
    stCtrlCommonInfo_ptr->eCtrlFuncStatus = eCtrlFuncStatus;
    return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME 
Ctrl_ModuleStateMachineResult. 

  * EXPLANATION   
Ctrl module state machine. 

*************************************************************************
*/

static uint8_t Ctrl_ModuleStateMachineResult(tCtrlFuncFsmInfo*        stCtrlApaShellInfo_ptr,
                                             tCtrlCommonInfo*          stCtrlCommonInfo_ptr)
{
    tLSAD_FuncType eApaType    = stCtrlApaShellInfo_ptr->eLsadFuncType;
    tCtrlParkOutType eParkOutType = stCtrlApaShellInfo_ptr->eCtrlParkOutType;
    tCtrl_Module_Status eCtrlFuncStatus   = stCtrlCommonInfo_ptr->eCtrlFuncStatus;
    tCtrl_Internal_FuncType eCtrlFuncType = stCtrlCommonInfo_ptr->eCtrlFuncType;

    switch (eCtrlFuncStatus)
    {
        case CTRL_MODULE_OFF: 
            eCtrlFuncStatus = CTRL_MODULE_OFF;
            eCtrlFuncType = Ctrl_Internal_Default;
            break;

        case CTRL_MODULE_STANDBY:
            eCtrlFuncStatus = CTRL_MODULE_STANDBY;
            eCtrlFuncType = Ctrl_Internal_Default;
            break;

        case CTRL_MODULE_ACTIVE:
            eCtrlFuncStatus = CTRL_MODULE_ACTIVE;
            if (LSAD_PARK_IN == eApaType || LSAD_PARK_OUT == eApaType || 
                LSAD_RA == eApaType|| LSAD_DRAG_PARK_IN == eApaType)
            {
                eCtrlFuncType = Ctrl_Internal_ParkingWithPlan;
            }
            else if (LSAD_PARK_OUT == eApaType && CTRL_PARKOUT_WITHOUTPP == eParkOutType)
            {
                eCtrlFuncType = Ctrl_Internal_ParkingOutNoPlan;
            }
            else if (LSAD_PARK_STRAIGHT == eApaType)
            {
                eCtrlFuncType = Ctrl_Internal_Straight;
            }
            else if (LSAD_CRUISE == eApaType)
            {
                eCtrlFuncType = Ctrl_Internal_Crusing;
            }
            else if (LSAD_EOL == eApaType)
            {
                eCtrlFuncType = Ctrl_Internal_Default;
            }
            else
            {
                eCtrlFuncType = Ctrl_Internal_Default;      // Should not happen. To add diag info.
            }
            break;

        case CTRL_MODULE_PAUSE:
            eCtrlFuncStatus = CTRL_MODULE_PAUSE;
            eCtrlFuncType = Ctrl_Internal_Default;
            break;

        case CTRL_MODULE_FINISH:
            eCtrlFuncStatus = CTRL_MODULE_FINISH;
            eCtrlFuncType = Ctrl_Internal_Default;
            break;

        default:
            ;
            break;
    }

    stCtrlCommonInfo_ptr->eCtrlFuncStatus = eCtrlFuncStatus;
    stCtrlCommonInfo_ptr->eCtrlFuncType = eCtrlFuncType;

    return E_OK;
}

/**
*************************************************************************
  * FUNCTION_NAME 
Ctrl_StateMachineFuncStatusActions_20ms. 

  * EXPLANATION   
In each state of the SM, actions will be made based on function status. 
E.g. Off, Standby, Init, etc. 

*************************************************************************
*/

static uint8_t Ctrl_StateMachineFuncStatusActions_20ms()
{
  tPFCalibData* stCalibPF_ptr = VehSrv_GetCalib();
  float f32RegardAsStopSpd = stCalibPF_ptr->stPFCtrlLongCalib.Calib_f32RegardAsStopSpeed;
  tVehActualGear ePPGearReq = (tVehActualGear)g_stPathPlannerData.u8Shift;
  tLSAD_SystemSts eLsadSystemSts = g_stCtrlFuncFsmInfo.eLsadSystemSts;  
  tLSAD_FuncType eLsadFuncType = g_stCtrlFuncFsmInfo.eLsadFuncType;    


  if(LSAD_PARK_IN == eLsadFuncType || LSAD_PARK_OUT == eLsadFuncType || LSAD_DRAG_PARK_IN == eLsadFuncType ||
      LSAD_RA == eLsadFuncType ||LSAD_PARK_STRAIGHT == eLsadFuncType){
    g_stCtrlToChassisInfo.eHandshakeReq = HANDSHAKE_RQ_LOW_SPEED;
  }else if(LSAD_CRUISE == eLsadFuncType){
    if(R_GEAR == ePPGearReq){
      g_stCtrlToChassisInfo.eHandshakeReq = HANDSHAKE_RQ_LOW_SPEED;
    }else{
      g_stCtrlToChassisInfo.eHandshakeReq = HANDSHAKE_RQ_HIGH_SPEED;
    }
  }else{
    g_stCtrlToChassisInfo.eHandshakeReq = HANDSHAKE_RQ_TYPE_NONE;
  }

  switch(g_stCtrlCommonInfo.eCtrlFuncStatus){
    case CTRL_MODULE_OFF:
      g_stCtrlToChassisInfo.eGearReq        = g_stCtrlVehDataRx.sVehVCUInfo.eVehActualGear;
      g_stCtrlToChassisInfo.f32CtrlReqSteer = g_stCtrlVehDataRx.sVehEPSInfo.f32StrWhlAngDeg;
      g_stCtrlToChassisInfo.f32CtrlReqAccel = -0.3;
      g_stCtrlToChassisInfo.f32CtrlReqSpeed = 0;
      g_stCtrlToChassisInfo.f32CtrlReqStopDistance = 0;
      g_stCtrlToChassisInfo.eAEBFlag        = 0;
      g_stCtrlToChassisInfo.f32CtrlReqSteerPrev = g_stCtrlVehDataRx.sVehEPSInfo.f32StrWhlAngDeg;

      g_stCtrlToFuncStateMachine.eCtrlStatus = APA_CTRL_OFF;
      break;
    case CTRL_MODULE_STANDBY :
      // --- Ctrl Init.
      if (g_stCtrlCommonInfo.eCtrlFuncStatusPrev != g_stCtrlCommonInfo.eCtrlFuncStatus) {
        Ctrl_VariablesInit();
        Ctrl_VehDiagReset_20ms();
      }
      // --- Dr Init.
      if (g_stCtrlVehDataRx.sVehESCInfo.f32VehSpdKph > 25){
        (void)Dr_Init_20ms_Task();
      }
      g_stCtrlToChassisInfo.eGearReq        = g_stCtrlVehDataRx.sVehVCUInfo.eVehActualGear;
      g_stCtrlToChassisInfo.f32CtrlReqSteer = g_stCtrlVehDataRx.sVehEPSInfo.f32StrWhlAngDeg;
      g_stCtrlToChassisInfo.f32CtrlReqAccel = 0;
      g_stCtrlToChassisInfo.f32CtrlReqSpeed = 0;
      g_stCtrlToChassisInfo.f32CtrlReqStopDistance = 0;
      g_stCtrlToChassisInfo.eAEBFlag        = 0;
      g_stCtrlToChassisInfo.f32CtrlReqSteerPrev = g_stCtrlVehDataRx.sVehEPSInfo.f32StrWhlAngDeg;

      g_stCtrlToFuncStateMachine.eCtrlStatus = APA_CTRL_STANDBY;
      break;
    case CTRL_MODULE_ACTIVE :
      // During CTRL_MODULE_ACTIVE, the actions depends on the function type, refer to Ctrl_StateMachineFuncTypeActions_20ms().
      g_stCtrlToFuncStateMachine.eCtrlStatus = APA_CTRL_ACTIVE;
        // --- Reset after pause. This will either reset in ACTIVE, or in STANDBY's main reset.   
       g_stCtrlLatInfo.stCtrlLatResult.u8PauseMemorySteerLockFlag = 0;
      break;
    case CTRL_MODULE_PAUSE :
      // --- Pause actions: stop and hold the vehicle
      g_stCtrlToChassisInfo.f32CtrlReqSpeed = 0;
      g_stCtrlToChassisInfo.f32CtrlReqStopDistance = 0; 
      g_stCtrlToChassisInfo.eStandStillReq  = REQUEST;
      g_stCtrlToChassisInfo.eAEBFlag        = REQUEST;
      // g_stCtrlCommonInfo.stCtrlPebInfo.u8PebHappened = 0;Keep u8PebHappened state ,when it is  back to  CTRL_MODULE_ACTIVE can send eb replan to pp
      // g_stCtrlCommonInfo.stCtrlPebInfo.u8PebDir = 0;Keep,when it is  back to  CTRL_MODULE_ACTIVE can send eb replan to pp
      // g_stCtrlCommonInfo.u8CtrlSubstate     = CTRL_CTRL_SUBSTATE_STOP_NONE;Keep,when it is  back to  CTRL_MODULE_ACTIVE can send eb replan to pp
      if (0 == g_stCtrlLatInfo.stCtrlLatResult.u8PauseMemorySteerLockFlag){
        g_stCtrlLatInfo.stCtrlLatResult.u8PauseMemorySteerLockFlag = 1;
        g_stCtrlLatInfo.stCtrlLatResult.f32PauseMemorySteer = g_stCtrlVehDataRx.sVehEPSInfo.f32StrWhlAngDeg;
      }
      g_stCtrlToChassisInfo.f32CtrlReqSteer = g_stCtrlLatInfo.stCtrlLatResult.f32PauseMemorySteer;
      if (g_stCtrlVehDataRx.sVehESCInfo.f32VehSpdKph < f32RegardAsStopSpd){
        g_stCtrlToChassisInfo.eGearReq = g_stCtrlVehDataRx.sVehVCUInfo.eVehActualGear;
        g_stCtrlToChassisInfo.f32CtrlReqAccel = 0;
      }else{
        g_stCtrlToChassisInfo.eGearReq = g_stCtrlVehDataRx.sVehVCUInfo.eVehActualGear;
        g_stCtrlToChassisInfo.f32CtrlReqAccel = -0.3;
      }
      g_stCtrlToFuncStateMachine.eCtrlStatus = APA_CTRL_PAUSE;
      g_stCtrlToFuncStateMachine.stCtrlReqSts.u8ReqPause = (CTRL_ACTION_PAUSE == g_stPathPlannerData.u8VehicleActionRequest)? 1: 0;
      g_stCtrlToChassisInfo.f32CtrlReqSteerPrev = g_stCtrlVehDataRx.sVehEPSInfo.f32StrWhlAngDeg;  
      // --- Clean the values for replan failed. 
      if(g_stCtrlFuncFsmInfo.u8LsadStSResetPEB == 1 ){   
        g_stCtrlLongiInfo.eSpeedPhase = PHASE_STOP_STEERING;            // Second way (replan failed way) to transfer from EMERG_STOP to STOP_STEERING: EMERG_STOP -> (Pause) -> STOP_STEERING.
        g_stCtrlLongiInfo.u8EmergStoppedFlag = 0;            // In the first step after resume, avoid send replan request.  
      }
      break;
    case CTRL_MODULE_FINISH :
      g_stCtrlToChassisInfo.eGearReq        = g_stCtrlVehDataRx.sVehVCUInfo.eVehActualGear;
      g_stCtrlToChassisInfo.f32CtrlReqSteer = g_stCtrlVehDataRx.sVehEPSInfo.f32StrWhlAngDeg;
      g_stCtrlToChassisInfo.f32CtrlReqAccel = -0.3;
      g_stCtrlToChassisInfo.f32CtrlReqSpeed = 0;
      g_stCtrlToChassisInfo.f32CtrlReqStopDistance = 0;
      g_stCtrlToChassisInfo.eAEBFlag        = 0;
      g_stCtrlToChassisInfo.f32CtrlReqSteerPrev = g_stCtrlVehDataRx.sVehEPSInfo.f32StrWhlAngDeg;

      if (g_stCtrlCommonInfo.eCtrlChockedTypeFlag == CONTROL_CHOCKED_ROLL_BACK||
          g_stCtrlCommonInfo.u8CtrlUnknownStopFlag == 1 ||
          g_stPathPlannerData.u8VehicleActionReason == CTRL_ACTION_REASON_FINISH_TRAP||
          g_stPathPlannerData.u8VehicleActionReason == CTRL_ACTION_REASON_FINISH_CTRL_ERROR) {
        g_stCtrlToFuncStateMachine.eCtrlStatus = APA_CTRL_FAULT;
      } else if (CTRL_FINISH_TYPE_HPP == g_stCtrlCommonInfo.eCtrlFinishType)  {
        g_stCtrlToFuncStateMachine.eCtrlStatus = APA_CTRL_COMPLETE_HPP;
      }else if (CTRL_FINISH_TYPE_APA == g_stCtrlCommonInfo.eCtrlFinishType){
        g_stCtrlToFuncStateMachine.eCtrlStatus = APA_CTRL_COMPLETE_APA;
      }   // No else here, since the eCtrlFinishType will be clean afterwards. 
      g_stCtrlCommonInfo.eCtrlFinishType = CTRL_FINISH_TYPE_NONE;    // Reset the value, help to clean this value after cruise finish. Cruise can't clean by itself because the cruise_20ms task will be no longer called
      if (g_stCtrlCommonInfo.eCtrlChockedTypeFlag == CONTROL_CHOCKED_ROLL_BACK) {
        g_stCtrlToFuncStateMachine.stCtrlReqSts.eCtrlFailReason = CTRL_FAIL_ROLL_BACK;
      } else if (g_stCtrlCommonInfo.eCtrlChockedTypeFlag == CONTROL_CHOCKED_VERTICAL)  {
        g_stCtrlToFuncStateMachine.stCtrlReqSts.eCtrlFailReason = CTRL_FINISH_CHOCK;
      }else if (g_stCtrlCommonInfo.eCtrlChockedTypeFlag == CONTROL_CHOCKED_HORIZONTAL){
        g_stCtrlToFuncStateMachine.stCtrlReqSts.eCtrlFailReason = CTRL_FINISH_CHOCK;
      }else if (g_stPathPlannerData.u8VehicleActionReason == CTRL_ACTION_REASON_FINISH_CTRL_ERROR){
        g_stCtrlToFuncStateMachine.stCtrlReqSts.eCtrlFailReason = CTRL_FAIL_LONG_STOP;
      }else if (g_stPathPlannerData.u8VehicleActionReason == CTRL_ACTION_REASON_FINISH_TRAP){
        g_stCtrlToFuncStateMachine.stCtrlReqSts.eCtrlFailReason = CTRL_PLAN_FAIL_TRAP;
      }else if (g_stCtrlCommonInfo.u8CtrlUnknownStopFlag == 1){
        g_stCtrlToFuncStateMachine.stCtrlReqSts.eCtrlFailReason = CTRL_FAIL_LONG_STOP;
      }
      break;
    default :
      break;
    }

    return E_OK;
}


/**
*************************************************************************
  * FUNCTION_NAME 
Ctrl_StateMachineFuncTypeActions_20ms. 

  * EXPLANATION   
In each state of the SM, actions will be made based on function types. 
E.g. ParkIn, ParkOut, Cruising, etc.  

*************************************************************************
*/

static uint8_t Ctrl_StateMachineFuncTypeActions_20ms()
{
    uint8_t rtn = 0;

    if (Ctrl_Internal_Crusing == g_stCtrlCommonInfo.eCtrlFuncType )
    {
        rtn |= Ctrl_CruisingTask_20ms();
    }
    else if (Ctrl_Internal_ParkingWithPlan == g_stCtrlCommonInfo.eCtrlFuncType )
    {
        rtn |= Ctrl_Parking_Task_20ms();
    }
    else if (Ctrl_Internal_Straight == g_stCtrlCommonInfo.eCtrlFuncType)
    {
        rtn |= Ctrl_Straight_Task_20ms();
    }
    else if (Ctrl_Internal_Back == g_stCtrlCommonInfo.eCtrlFuncType)
    {
    //    rtn |= Ctrl_Straight_Backward_Task_20ms();
    }
    else if (Ctrl_Internal_ParkingOutNoPlan == g_stCtrlCommonInfo.eCtrlFuncType)
    {
        rtn |= Ctrl_SideParkOut_20ms();
        // rtn |= Ctrl_UssParkOut_20ms();
    }
    else if (Ctrl_Internal_Default == g_stCtrlCommonInfo.eCtrlFuncType)
    {
        rtn |= E_OK;
    }
    else
    {
         rtn |= Ctrl_WaveHandWithChassis(&g_stCtrlVehDataRx,&g_stCtrlToChassisInfo,&g_stCtrlLatInfo);
    }

    return rtn;
}

