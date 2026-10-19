/*
 * File: hpa_state_common.h
 *
 * Code generated for Simulink model 'hpa_state_common'.
 *
 * Model version                  : 3.2810
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Thu Nov 28 16:10:25 2024
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

#ifndef RTW_HEADER_hpa_state_common_h_
#define RTW_HEADER_hpa_state_common_h_
#include <string.h>
#include "common_condition_type.h"
#include "hmi_data_rx_type.h"
#include "lsad_fsm_core_type.h"
#include "master_lsad_fsm_type.h"
#include "slave_lsad_fsm_type.h"
#ifndef hpa_state_common_COMMON_INCLUDES_
#define hpa_state_common_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* hpa_state_common_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Includes for objects with custom storage classes. */
#include "project_const_common.h"
#include "calib_lsad_fsm.h"

/* Block signals and states (default storage) for model 'hpa_state_common' */
#ifndef hpa_state_common_MDLREF_HIDE_CHILD_

typedef struct
{
  real32_T UnitDelay1_DSTATE;          /* '<S30>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_f;        /* '<S20>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_n;        /* '<S27>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_e;        /* '<S23>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_i;        /* '<S14>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_l;        /* '<S17>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_p;        /* '<S33>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_b;        /* '<S36>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_i3;       /* '<S39>/Unit Delay1' */
  tQuitEvnt UnitDelay8_DSTATE;         /* '<S2>/Unit Delay8' */
  tTrmntEvnt UnitDelay7_DSTATE;        /* '<S2>/Unit Delay7' */
  tIntrptType UnitDelay9_DSTATE;       /* '<S2>/Unit Delay9' */
}
DW_hpa_state_common_f_T;

#endif                                 /*hpa_state_common_MDLREF_HIDE_CHILD_*/

extern void hpa_state_common(const tVehCommon *rtu_sVehCommon, const tHPAHmiRx
  *rtu_sHPAHmiRx, const tVehDataRx *rtu_sVehDataRx, const tRelatedModuleInfo
  *rtu_sRelatedModuleInfo, const tDiagInfo *rtu_sDiagInfo, const tMasterLsadFsm *
  rtu_sLastMasterLsadFsm, const tSlaveLsadFsm *rtu_sLastSlaveLsadFsm,
  tHpaStateCommon *rty_sHpaStateCommon);

/* Model reference registration function */
extern void hpa_state_common_initialize(void);

#ifndef hpa_state_common_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern DW_hpa_state_common_f_T hpa_state_common_DW;

#endif                                 /*hpa_state_common_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'hpa_state_common'
 * '<S1>'   : 'hpa_state_common/CondiOverFlag'
 * '<S2>'   : 'hpa_state_common/PAEvntDet'
 * '<S3>'   : 'hpa_state_common/CondiOverFlag/bCmpltDurattime'
 * '<S4>'   : 'hpa_state_common/CondiOverFlag/bCmpltOvertime'
 * '<S5>'   : 'hpa_state_common/CondiOverFlag/bHandshakOvertime'
 * '<S6>'   : 'hpa_state_common/CondiOverFlag/bIntrptOvertime'
 * '<S7>'   : 'hpa_state_common/CondiOverFlag/bManeuveOvertime'
 * '<S8>'   : 'hpa_state_common/CondiOverFlag/bPPOvertime'
 * '<S9>'   : 'hpa_state_common/CondiOverFlag/bQuitDurattime'
 * '<S10>'  : 'hpa_state_common/CondiOverFlag/bTrmntDurattime'
 * '<S11>'  : 'hpa_state_common/CondiOverFlag/bTrmntOvertime'
 * '<S12>'  : 'hpa_state_common/CondiOverFlag/bCmpltDurattime/Enumerated Constant12'
 * '<S13>'  : 'hpa_state_common/CondiOverFlag/bCmpltDurattime/Enumerated Constant2'
 * '<S14>'  : 'hpa_state_common/CondiOverFlag/bCmpltDurattime/Timer4'
 * '<S15>'  : 'hpa_state_common/CondiOverFlag/bCmpltOvertime/Enumerated Constant12'
 * '<S16>'  : 'hpa_state_common/CondiOverFlag/bCmpltOvertime/Enumerated Constant2'
 * '<S17>'  : 'hpa_state_common/CondiOverFlag/bCmpltOvertime/Timer4'
 * '<S18>'  : 'hpa_state_common/CondiOverFlag/bHandshakOvertime/Enumerated Constant1'
 * '<S19>'  : 'hpa_state_common/CondiOverFlag/bHandshakOvertime/Enumerated Constant2'
 * '<S20>'  : 'hpa_state_common/CondiOverFlag/bHandshakOvertime/Timer2'
 * '<S21>'  : 'hpa_state_common/CondiOverFlag/bIntrptOvertime/Enumerated Constant12'
 * '<S22>'  : 'hpa_state_common/CondiOverFlag/bIntrptOvertime/Enumerated Constant2'
 * '<S23>'  : 'hpa_state_common/CondiOverFlag/bIntrptOvertime/Timer3'
 * '<S24>'  : 'hpa_state_common/CondiOverFlag/bManeuveOvertime/Enumerated Constant1'
 * '<S25>'  : 'hpa_state_common/CondiOverFlag/bManeuveOvertime/Enumerated Constant2'
 * '<S26>'  : 'hpa_state_common/CondiOverFlag/bManeuveOvertime/Enumerated Constant3'
 * '<S27>'  : 'hpa_state_common/CondiOverFlag/bManeuveOvertime/Timer7'
 * '<S28>'  : 'hpa_state_common/CondiOverFlag/bPPOvertime/Enumerated Constant1'
 * '<S29>'  : 'hpa_state_common/CondiOverFlag/bPPOvertime/Enumerated Constant2'
 * '<S30>'  : 'hpa_state_common/CondiOverFlag/bPPOvertime/Timer1'
 * '<S31>'  : 'hpa_state_common/CondiOverFlag/bQuitDurattime/Enumerated Constant12'
 * '<S32>'  : 'hpa_state_common/CondiOverFlag/bQuitDurattime/Enumerated Constant2'
 * '<S33>'  : 'hpa_state_common/CondiOverFlag/bQuitDurattime/Timer5'
 * '<S34>'  : 'hpa_state_common/CondiOverFlag/bTrmntDurattime/Enumerated Constant12'
 * '<S35>'  : 'hpa_state_common/CondiOverFlag/bTrmntDurattime/Enumerated Constant2'
 * '<S36>'  : 'hpa_state_common/CondiOverFlag/bTrmntDurattime/Timer6'
 * '<S37>'  : 'hpa_state_common/CondiOverFlag/bTrmntOvertime/Enumerated Constant12'
 * '<S38>'  : 'hpa_state_common/CondiOverFlag/bTrmntOvertime/Enumerated Constant2'
 * '<S39>'  : 'hpa_state_common/CondiOverFlag/bTrmntOvertime/Timer6'
 * '<S40>'  : 'hpa_state_common/PAEvntDet/HPAFailureEvntDet'
 * '<S41>'  : 'hpa_state_common/PAEvntDet/HPAInhibitEvntDet'
 * '<S42>'  : 'hpa_state_common/PAEvntDet/HPAQuitEvntDet'
 * '<S43>'  : 'hpa_state_common/PAEvntDet/PAIntrptEvntDet'
 * '<S44>'  : 'hpa_state_common/PAEvntDet/PATrmntEvntDet'
 */
#endif                                 /* RTW_HEADER_hpa_state_common_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
