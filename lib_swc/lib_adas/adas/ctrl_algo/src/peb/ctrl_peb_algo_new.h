#ifndef EM_SWC_CTRL_ALGO_INC_CTRL_USS_H_NEW_
#define EM_SWC_CTRL_ALGO_INC_CTRL_USS_H_NEW_
#include "ctrl_struct.h"
#include "ctrl_global_variables.h"
#include "vehicle_service/calib/vehsrv_calib.h"


uint8_t control_PEB_detection(tCtrlCommonInfo*        stCtrlCommonInfo_ptr,
                              tVehDataRx*             stVehDataRx_ptr,
                              tCtrlUssInfo*           stCtrlUssInfo_ptr,
                              tStateMachine*         stStateMachine_ptr,
                              tPathPlannerInfo*       stPathPlannerInfo_ptr,
                              tCtrlFuncFsmInfo*     stCtrlApaShellInfo_ptr,
                              tCtrlLongiInfo*         stCtrlLongiInfo_ptr);
						
#endif /* EM_SWC_CTRL_ALGO_INC_CTRL_USS_H_NEW_ */
