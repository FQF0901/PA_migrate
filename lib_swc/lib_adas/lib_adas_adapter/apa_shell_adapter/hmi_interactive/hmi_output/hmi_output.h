/*
 * File: hmi_output.h
 *
 * Code generated for Simulink model 'hmi_output'.
 *
 * Model version                  : 1.1549
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Thu Nov 28 16:36:14 2024
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

#ifndef RTW_HEADER_hmi_output_h_
#define RTW_HEADER_hmi_output_h_
#include <math.h>
#include <string.h>
#include "hmi_interactive_type.h"
#include "common_condition_type.h"
#include "hmi_data_rx_type.h"
#include "lsad_fsm_core_type.h"
#include "master_lsad_fsm_type.h"
#include "slave_lsad_fsm_type.h"
#ifndef hmi_output_COMMON_INCLUDES_
#define hmi_output_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* hmi_output_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Block signals and states (default storage) for model 'hmi_output' */
#ifndef hmi_output_MDLREF_HIDE_CHILD_

typedef struct
{
  uint16_T EMUnitDelay_DSTATE;         /* '<Root>/EMUnitDelay' */
}
DW_hmi_output_f_T;

#endif                                 /*hmi_output_MDLREF_HIDE_CHILD_*/

extern void hmi_output(const tHMIComDisp *rtu_sHMIComDisp, const tPaStateCommon *
  rtu_sPaStateCommon, const tRaStateCommon *rtu_sRaStateCommon, const
  tHpaStateCommon *rtu_eHpaStateCommon, const tVehDataRx *rtu_sVehDataRx, const
  tRelatedModuleInfo *rtu_sRelatedModuleInfo, const tVehCommon *rtu_sVehCommon,
  const tMasterLsadFsm *rtu_sMasterLsadFsm, const tSlaveLsadFsm
  *rtu_sSlaveLsadFsm, const tPaStateAdptr *rtu_sPaStateAdptr, tMsgMnger_TextDisp
  *rty_sMsgMnger_TextDisp);

/* Model reference registration function */
extern void hmi_output_initialize(void);

#ifndef hmi_output_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern DW_hmi_output_f_T hmi_output_DW;

#endif                                 /*hmi_output_MDLREF_HIDE_CHILD_*/

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Data Type Conversion1' : Unused code path elimination
 */

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
 * '<Root>' : 'hmi_output'
 * '<S1>'   : 'hmi_output/FuncRemainDistDet'
 * '<S2>'   : 'hmi_output/FuncTextDisplayDet'
 * '<S3>'   : 'hmi_output/LocTextDisplayDet'
 * '<S4>'   : 'hmi_output/MapTextDisplayDet'
 * '<S5>'   : 'hmi_output/Subsystem'
 * '<S6>'   : 'hmi_output/VehiGearMapping'
 * '<S7>'   : 'hmi_output/Subsystem/Enumerated Constant1'
 * '<S8>'   : 'hmi_output/Subsystem/Enumerated Constant2'
 * '<S9>'   : 'hmi_output/Subsystem/Enumerated Constant3'
 * '<S10>'  : 'hmi_output/Subsystem/FcnRes'
 */
#endif                                 /* RTW_HEADER_hmi_output_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
