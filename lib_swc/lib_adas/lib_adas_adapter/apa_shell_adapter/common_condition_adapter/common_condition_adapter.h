/*
 * File: common_condition_adapter.h
 *
 * Code generated for Simulink model 'common_condition_adapter'.
 *
 * Model version                  : 3.2189
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Thu Nov 28 16:37:47 2024
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

#ifndef RTW_HEADER_common_condition_adapter_h_
#define RTW_HEADER_common_condition_adapter_h_
#include "common_condition_type.h"
#include "hmi_data_rx_type.h"
#include "master_lsad_fsm_type.h"
#include "lsad_fsm_core_type.h"
#include "slave_lsad_fsm_type.h"
#ifndef common_condition_adapter_COMMON_INCLUDES_
#define common_condition_adapter_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                           /* common_condition_adapter_COMMON_INCLUDES_ */

/* Child system includes */
#ifndef common_condition_adapter_MDLREF_HIDE_CHILD_
#define pa_state_adapter_MDLREF_HIDE_CHILD_
#include "pa_state_adapter.h"
#endif                           /*common_condition_adapter_MDLREF_HIDE_CHILD_*/

/* Model Code Variants */

/* Includes for objects with custom storage classes. */
#include "project_const_common.h"
#include "calib_lsad_fsm.h"

extern void common_condition_adapter(const tVehCommon *rtu_sVehCommon, const
  tPAHmiRx *rtu_sPAHmiRx, const tVehDataRx *rtu_sVehDataRx, const tMasterLsadFsm
  *rtu_sLastMasterLsadFsm, const tDiagInfo *rtu_sDiagInfo, const tPaStateCommon *
  rtu_sPaStateCommon, const tSlaveLsadFsm *rtu_sLastSlaveLsadFsm, const
  tRelatedModuleInfo *rtu_sRelatedModuleInfo, tPaStateAdptr *rty_sPaStateAdptr);

/* Model reference registration function */
extern void common_condition_adapter_initialize(void);

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
 * '<Root>' : 'common_condition_adapter'
 */
#endif                              /* RTW_HEADER_common_condition_adapter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
