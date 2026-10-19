/*
 * File: common_condition.h
 *
 * Code generated for Simulink model 'common_condition'.
 *
 * Model version                  : 3.2188
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Dec  2 16:04:51 2024
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

#ifndef RTW_HEADER_common_condition_h_
#define RTW_HEADER_common_condition_h_
#include "hmi_data_rx_type.h"
#include "lsad_fsm_core_type.h"
#include "master_lsad_fsm_type.h"
#include "slave_lsad_fsm_type.h"
#include "common_condition_type.h"
#ifndef common_condition_COMMON_INCLUDES_
#define common_condition_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* common_condition_COMMON_INCLUDES_ */

/* Child system includes */
#ifndef common_condition_MDLREF_HIDE_CHILD_
#define veh_common_MDLREF_HIDE_CHILD_
#include "veh_common.h"
#endif                                 /*common_condition_MDLREF_HIDE_CHILD_*/

#ifndef common_condition_MDLREF_HIDE_CHILD_
#define hpa_state_common_MDLREF_HIDE_CHILD_
#include "hpa_state_common.h"
#endif                                 /*common_condition_MDLREF_HIDE_CHILD_*/

#ifndef common_condition_MDLREF_HIDE_CHILD_
#define pa_state_common_MDLREF_HIDE_CHILD_
#include "pa_state_common.h"
#endif                                 /*common_condition_MDLREF_HIDE_CHILD_*/

#ifndef common_condition_MDLREF_HIDE_CHILD_
#define ra_state_common_MDLREF_HIDE_CHILD_
#include "ra_state_common.h"
#endif                                 /*common_condition_MDLREF_HIDE_CHILD_*/

/* Model Code Variants */

/* Includes for objects with custom storage classes. */
#include "project_const_common.h"
#include "calib_lsad_fsm.h"

extern void common_condition_Init(void);
extern void common_condition(const tVehDataRx *rtu_sVehDataRx, const tPAHmiRx
  *rtu_sPAHmiRx, const tRAHmiRx *rtu_sRAHmiRx, const tRelatedModuleInfo
  *rtu_sRelatedModuleInfo, const tHPAHmiRx *rtu_sHPAHmiRx, const tDiagInfo
  *rtu_sDiagInfo, const tMasterLsadFsm *rtu_sLastMasterLsadFsm, const
  tSlaveLsadFsm *rtu_sLastSlaveLsadFsm, const tPaStateAdptr *rtu_sPaStateAdptr,
  tVehCommon *rty_sVehCommon, tPaStateCommon *rty_sPaStateCommon, tRaStateCommon
  *rty_sRaStateCommon, tHpaStateCommon *rty_sHpaStateCommon);

/* Model reference registration function */
extern void common_condition_initialize(void);

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
 * '<Root>' : 'common_condition'
 */
#endif                                 /* RTW_HEADER_common_condition_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
