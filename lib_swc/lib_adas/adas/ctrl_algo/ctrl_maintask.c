#include "adas_struct.h"
#include "adas_interface.h"
#include "ctrl_task_func.h"
#include "ctrl_global_variables.h"
#include "ctrl_struct.h"
#include "cruising/ctrl_cruising.h"
#include "parking/ctrl_apa_parking.h"
#include "ctrl_diag.h"
#include "ctrl_enum.h"
#include "lib_adas_adapter/vehicle_service/ctrl_adapter/ctrl_adapter.h"
#include "peb/ctrl_peb_algo_new.h"
#include "adas_project_input.h"

#define CtrlPara_START_SEC_VAR		// Memory allocation
#include "proj_MemMap.h"

static int CTRL_POWERON_INITFLAG = 0;

#define CtrlPara_STOP_SEC_VAR	// Memory allocation end.
#include "proj_MemMap.h"

/**
*************************************************************************
  * FUNCTION_NAME 
Ctrl_Task_20ms. 

  * EXPLANATION   
Ctrl's main function. Including:
 - Initialization.
 - Vehicle diagnosis.
 - Input adapter. 
 - State Machine.
 - Switch case based on corresponding states.
 - Output diagnosis.
 - Output adapter.

*************************************************************************
*/

EM_ADAS_ReturnType Ctrl_Task_20ms()
{
    uint8_t rtn = 0;


    if (0 == CTRL_POWERON_INITFLAG)
    {
        rtn |= (uint8_t)Ctrl_TaskInit();    // Execute only once. To put it into MCU main_thread.c, where the initializations of all tasks are done together.

        CTRL_POWERON_INITFLAG = 1;
        if (rtn != E_OK)
        {
            PRINTF_PF("CF_Init_Err");
            return E_ERR;
        }
        else
        {
    //        Ifx_Console_print("CF_Init_Pass" );
        }
    }
    else
    {

    }

    rtn |= Ctrl_InputAdapter_20ms();

    if (rtn != E_OK)
    {
        PRINTF_PF("CF_Input_Err");
       return E_ERR;
    }
    else
    {
//       Ifx_Console_print("CF_Input_Pass" );
    }

    rtn |= Ctrl_FunctionStateMachine_20ms();
    if (rtn != E_OK)
    {
        PRINTF_PF("CF_SM_Err");
        return E_ERR;
    }
    else
    {
 //       Ifx_Console_print("CF_SM_Pass" );
    }

    rtn |= Ctrl_StateMachineActions_20ms();
    if (rtn != E_OK)
    {
        PRINTF_PF("CF_SM_Actions_Err");
        return E_ERR;
    }
    else
    {
 //       PRINTF_PF("CF_SM_Pass" );
    }

    rtn |= Ctrl_VehDiag_20ms();
    if (rtn != E_OK)
    {
        PRINTF_PF("CF_VehDiag_Err");
        return E_ERR;
    }
    else
    {
//        PRINTF_PF("CF_VehDiag_Pass" );
    }

    rtn |= Ctrl_OutputAdapter_20ms();
    if (rtn != E_OK)
    {
        PRINTF_PF("CF_Output_Apater_Err");
        return E_ERR;
    }
    else
    {
 //       PRINTF_PF("CF_Output_Apater_Pass" );
    }
    
    Ctrl_VehDiagPrint_20ms();

    return E_OK;
}


