/*
 * File: hmi_interactive.h
 *
 * Code generated for Simulink model 'hmi_interactive'.
 *
 * Model version                  : 3.1280
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Wed Dec  4 15:22:43 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. ROM efficiency
 *    3. MISRA C:2012 guidelines
 *    4. Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_hmi_interactive_h_
#define RTW_HEADER_hmi_interactive_h_
#include <string.h>
#include "common_condition_type.h"
#include "hmi_data_rx_type.h"
#include "lsad_fsm_core_type.h"
#include "Platform_Types.h"
#include "vehicle_service_type.h"
#include "rte.h"
#include "master_lsad_fsm_type.h"
#include "slave_lsad_fsm_type.h"
#include "hmi_interactive_type.h"
#ifndef hmi_interactive_COMMON_INCLUDES_
#define hmi_interactive_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* hmi_interactive_COMMON_INCLUDES_ */

/* Child system includes */
#ifndef hmi_interactive_MDLREF_HIDE_CHILD_
#define hmi_common_MDLREF_HIDE_CHILD_
#include "hmi_common.h"
#endif                                 /*hmi_interactive_MDLREF_HIDE_CHILD_*/

#ifndef hmi_interactive_MDLREF_HIDE_CHILD_
#define hmi_output_MDLREF_HIDE_CHILD_
#include "hmi_output.h"
#endif                                 /*hmi_interactive_MDLREF_HIDE_CHILD_*/

/* Model Code Variants */

/* Includes for objects with custom storage classes. */
#include "project_const_common.h"
#include "calib_lsad_fsm.h"

/* Block signals and states (default storage) for model 'hmi_interactive' */
#ifndef hmi_interactive_MDLREF_HIDE_CHILD_

typedef struct
{
  tFusionDisp sFusionDisp;             /* '<Root>/hmi_common' */
}
DW_hmi_interactive_f_T;

#endif                                 /*hmi_interactive_MDLREF_HIDE_CHILD_*/

extern void hmi_interactive_Init(void);
extern void hmi_interactive(const tHpaStateCommon *rtu_sHpaStateCommon, const
  tRaStateCommon *rtu_sRaStateCommon, const tPaStateCommon *rtu_sPaStateCommon,
  const tRelatedModuleInfo *rtu_sRelatedModuleInfo, const tVehDataRx
  *rtu_sVehDataRx, const tVehCommon *rtu_sVehCommon, const tPAHmiRx
  *rtu_sPAHmiRx, const tPecpPLDInfo *rtu_sPecpPLDInfo, const
  tMsgMnger_PathSegment *rtu_sPathSegment, const tPaStateAdptr
  *rtu_sPaStateAdptr, const tMasterLsadFsm *rtu_sMasterLsadFsm, const
  tSlaveLsadFsm *rtu_sSlaveLsadFsm, tHMIComDisp *rty_sHMIComDisp,
  tMsgMnger_TextDisp *rty_sMsgMnger_TextDisp, DragParkingLot
  *rty_sDragParkingLot);

/* Model reference registration function */
extern void hmi_interactive_initialize(void);

#ifndef hmi_interactive_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern DW_hmi_interactive_f_T hmi_interactive_DW;

#endif                                 /*hmi_interactive_MDLREF_HIDE_CHILD_*/

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'hmi_interactive'
 */
#endif                                 /* RTW_HEADER_hmi_interactive_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
