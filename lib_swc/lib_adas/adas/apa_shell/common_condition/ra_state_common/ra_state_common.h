/*
 * File: ra_state_common.h
 *
 * Code generated for Simulink model 'ra_state_common'.
 *
 * Model version                  : 1.234
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Thu Nov 28 16:11:17 2024
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

#ifndef RTW_HEADER_ra_state_common_h_
#define RTW_HEADER_ra_state_common_h_
#include <string.h>
#include "common_condition_type.h"
#include "hmi_data_rx_type.h"
#include "lsad_fsm_core_type.h"
#include "master_lsad_fsm_type.h"
#include "slave_lsad_fsm_type.h"
#ifndef ra_state_common_COMMON_INCLUDES_
#define ra_state_common_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ra_state_common_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Includes for objects with custom storage classes. */
#include "project_const_common.h"
#include "calib_lsad_fsm.h"

/* Block signals and states (default storage) for model 'ra_state_common' */
#ifndef ra_state_common_MDLREF_HIDE_CHILD_

typedef struct
{
  real32_T UnitDelay1_DSTATE;          /* '<S30>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_a;        /* '<S20>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_n;        /* '<S27>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_j;        /* '<S23>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_k;        /* '<S14>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_b;        /* '<S17>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_d;        /* '<S33>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_aq;       /* '<S36>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_jw;       /* '<S39>/Unit Delay1' */
  tRATrmntEvnt UnitDelay7_DSTATE;      /* '<S2>/Unit Delay7' */
  tRAQuitEvnt UnitDelay_DSTATE;        /* '<S2>/Unit Delay' */
  tRAIntrptType UnitDelay9_DSTATE;     /* '<S2>/Unit Delay9' */
}
DW_ra_state_common_f_T;

#endif                                 /*ra_state_common_MDLREF_HIDE_CHILD_*/

extern void ra_state_common(const tVehDataRx *rtu_sVehDataRx, const tVehCommon
  *rtu_sVehCommon, const tRAHmiRx *rtu_sRAHmiRx, const tRelatedModuleInfo
  *rtu_sRelatedModuleInfo, const tMasterLsadFsm *rtu_sLastMasterLsadFsm, const
  tDiagInfo *rtu_sDiagInfo, const tSlaveLsadFsm *rtu_sLastSlaveLsadFsm,
  tRaStateCommon *rty_sRaStateCommon);

/* Model reference registration function */
extern void ra_state_common_initialize(void);

#ifndef ra_state_common_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern DW_ra_state_common_f_T ra_state_common_DW;

#endif                                 /*ra_state_common_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'ra_state_common'
 * '<S1>'   : 'ra_state_common/CondiOverFlag'
 * '<S2>'   : 'ra_state_common/RAEvntDet'
 * '<S3>'   : 'ra_state_common/CondiOverFlag/bCmpltDurattime'
 * '<S4>'   : 'ra_state_common/CondiOverFlag/bCmpltOvertime'
 * '<S5>'   : 'ra_state_common/CondiOverFlag/bHandshakOvertime'
 * '<S6>'   : 'ra_state_common/CondiOverFlag/bIntrptOvertime'
 * '<S7>'   : 'ra_state_common/CondiOverFlag/bManeuveOvertime'
 * '<S8>'   : 'ra_state_common/CondiOverFlag/bPPOvertime'
 * '<S9>'   : 'ra_state_common/CondiOverFlag/bQuitDurattime'
 * '<S10>'  : 'ra_state_common/CondiOverFlag/bTrmntDurattime'
 * '<S11>'  : 'ra_state_common/CondiOverFlag/bTrmntOvertime'
 * '<S12>'  : 'ra_state_common/CondiOverFlag/bCmpltDurattime/Enumerated Constant12'
 * '<S13>'  : 'ra_state_common/CondiOverFlag/bCmpltDurattime/Enumerated Constant2'
 * '<S14>'  : 'ra_state_common/CondiOverFlag/bCmpltDurattime/Timer4'
 * '<S15>'  : 'ra_state_common/CondiOverFlag/bCmpltOvertime/Enumerated Constant12'
 * '<S16>'  : 'ra_state_common/CondiOverFlag/bCmpltOvertime/Enumerated Constant2'
 * '<S17>'  : 'ra_state_common/CondiOverFlag/bCmpltOvertime/Timer4'
 * '<S18>'  : 'ra_state_common/CondiOverFlag/bHandshakOvertime/Enumerated Constant1'
 * '<S19>'  : 'ra_state_common/CondiOverFlag/bHandshakOvertime/Enumerated Constant2'
 * '<S20>'  : 'ra_state_common/CondiOverFlag/bHandshakOvertime/Timer2'
 * '<S21>'  : 'ra_state_common/CondiOverFlag/bIntrptOvertime/Enumerated Constant12'
 * '<S22>'  : 'ra_state_common/CondiOverFlag/bIntrptOvertime/Enumerated Constant2'
 * '<S23>'  : 'ra_state_common/CondiOverFlag/bIntrptOvertime/Timer3'
 * '<S24>'  : 'ra_state_common/CondiOverFlag/bManeuveOvertime/Enumerated Constant1'
 * '<S25>'  : 'ra_state_common/CondiOverFlag/bManeuveOvertime/Enumerated Constant2'
 * '<S26>'  : 'ra_state_common/CondiOverFlag/bManeuveOvertime/Enumerated Constant3'
 * '<S27>'  : 'ra_state_common/CondiOverFlag/bManeuveOvertime/Timer7'
 * '<S28>'  : 'ra_state_common/CondiOverFlag/bPPOvertime/Enumerated Constant1'
 * '<S29>'  : 'ra_state_common/CondiOverFlag/bPPOvertime/Enumerated Constant2'
 * '<S30>'  : 'ra_state_common/CondiOverFlag/bPPOvertime/Timer1'
 * '<S31>'  : 'ra_state_common/CondiOverFlag/bQuitDurattime/Enumerated Constant12'
 * '<S32>'  : 'ra_state_common/CondiOverFlag/bQuitDurattime/Enumerated Constant2'
 * '<S33>'  : 'ra_state_common/CondiOverFlag/bQuitDurattime/Timer5'
 * '<S34>'  : 'ra_state_common/CondiOverFlag/bTrmntDurattime/Enumerated Constant12'
 * '<S35>'  : 'ra_state_common/CondiOverFlag/bTrmntDurattime/Enumerated Constant2'
 * '<S36>'  : 'ra_state_common/CondiOverFlag/bTrmntDurattime/Timer6'
 * '<S37>'  : 'ra_state_common/CondiOverFlag/bTrmntOvertime/Enumerated Constant12'
 * '<S38>'  : 'ra_state_common/CondiOverFlag/bTrmntOvertime/Enumerated Constant2'
 * '<S39>'  : 'ra_state_common/CondiOverFlag/bTrmntOvertime/Timer6'
 * '<S40>'  : 'ra_state_common/RAEvntDet/RAIntrptEvntDet'
 * '<S41>'  : 'ra_state_common/RAEvntDet/RAQuitEvntDet'
 * '<S42>'  : 'ra_state_common/RAEvntDet/RATrmntEvntDet'
 */
#endif                                 /* RTW_HEADER_ra_state_common_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
