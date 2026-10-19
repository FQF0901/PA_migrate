#include "adas_struct.h"
#include "vehicle_service_global_variables.h"
#include "actuator_handshake_task_func.h"


#define CtrlPara_START_SEC_VAR		// Memory allocation  需要重新定义
#include "proj_MemMap.h"

static int VEH_HANDSHAKE_POWERON_INITFLAG = 0;

#define CtrlPara_STOP_SEC_VAR	// Memory allocation end.
#include "proj_MemMap.h"


/**
*************************************************************************
  * FUNCTION_NAME 
vehicle_interface_Task_20ms. 

  * EXPLANATION   
Ctrl's main function. Including:
 - Initialization.
 - Vehicle diagnosis.
 - Input adapter. 
 - State Machine.
 - Switch case based on corresponding states.
 - Output diagnosis.
 - Output adapter.

******
*******************************************************************
*/

EM_ADAS_ReturnType actuator_handshake_Task_20ms()
{
  uint8_t rtn = 0;
  if (0 == VEH_HANDSHAKE_POWERON_INITFLAG)
  {
    rtn |= (uint8_t)actuator_handshake_initialize();
    VEH_HANDSHAKE_POWERON_INITFLAG = 1;
    if (rtn != E_OK)
    {
      PRINTF_PF("actuator_handshake_Init_Err");
      return ADAS_HANDSHAKE_ERR;
    }
    else
    {
        //        Ifx_Console_print("CF_Init_Pass" );
    }
  }    
  else
  {

  }
  rtn |= (uint8_t)actuator_handshake_step();
  if (rtn != E_OK)
  {
    PRINTF_PF("CF_actuator_handshake_Err");
    return ADAS_HANDSHAKE_ERR;
  }
  else
  {
 //       PRINTF_PF("CF_Output_Apater_Pass" );
  }
  return E_OK;
}

