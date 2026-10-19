/*
 * File: pa_state_common.h
 *
 * Code generated for Simulink model 'pa_state_common'.
 *
 * Model version                  : 3.2829
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Thu Nov 28 16:10:53 2024
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

#ifndef RTW_HEADER_pa_state_common_h_
#define RTW_HEADER_pa_state_common_h_
#include <string.h>
#include "common_condition_type.h"
#include "hmi_data_rx_type.h"
#include "lsad_fsm_core_type.h"
#include "master_lsad_fsm_type.h"
#include "slave_lsad_fsm_type.h"
#ifndef pa_state_common_COMMON_INCLUDES_
#define pa_state_common_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* pa_state_common_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Includes for objects with custom storage classes. */
#include "project_const_common.h"
#include "calib_lsad_fsm.h"

/* Block signals and states (default storage) for model 'pa_state_common' */
#ifndef pa_state_common_MDLREF_HIDE_CHILD_

typedef struct
{
  real32_T UnitDelay1_DSTATE;          /* '<S61>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_l;        /* '<S40>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_a;        /* '<S21>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_j;        /* '<S55>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_g;        /* '<S29>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_k;        /* '<S35>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_p;        /* '<S67>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_b;        /* '<S86>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_bb;       /* '<S92>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_gx;       /* '<S23>/Unit Delay1' */
  tVehActualGear UnitDelay1_DSTATE_gl; /* '<S12>/Unit Delay1' */
  tVehActualGear UnitDelay3_DSTATE;    /* '<S12>/Unit Delay3' */
  tTrmntEvnt UnitDelay7_DSTATE;        /* '<S2>/Unit Delay7' */
  tIntrptType UnitDelay9_DSTATE;       /* '<S2>/Unit Delay9' */
  tLSAD_SystemSts UnitDelay_DSTATE;    /* '<S8>/Unit Delay' */
  uint16_T UnitDelay1_DSTATE_f;        /* '<S41>/Unit Delay1' */
  uint16_T UnitDelay1_DSTATE_gk;       /* '<S68>/Unit Delay1' */
}
DW_pa_state_common_f_T;

#endif                                 /*pa_state_common_MDLREF_HIDE_CHILD_*/

extern void pa_state_common_Init(void);
extern void pa_state_common(const tVehCommon *rtu_sVehCommon, const tPAHmiRx
  *rtu_sPAHmiRx, const tVehDataRx *rtu_sVehDataRx, const tRelatedModuleInfo
  *rtu_sRelatedModuleInfo, const tDiagInfo *rtu_sDiagInfo, const tPaStateAdptr
  *rtu_sPaStateAdptr, const tMasterLsadFsm *rtu_sLastMasterLsadFsm, const
  tSlaveLsadFsm *rtu_sLastSlaveLsadFsm, tPaStateCommon *rty_sPaStateCommon);

/* Model reference registration function */
extern void pa_state_common_initialize(void);

#ifndef pa_state_common_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern DW_pa_state_common_f_T pa_state_common_DW;

#endif                                 /*pa_state_common_MDLREF_HIDE_CHILD_*/

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/EMUint16Conversion' : Unused code path elimination
 * Block '<Root>/EMUint16Conversion1' : Unused code path elimination
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
 * '<Root>' : 'pa_state_common'
 * '<S1>'   : 'pa_state_common/CondiOverFlag'
 * '<S2>'   : 'pa_state_common/PAEvntDet'
 * '<S3>'   : 'pa_state_common/CondiOverFlag/ActiveOvertime'
 * '<S4>'   : 'pa_state_common/CondiOverFlag/SelfCheckOvertimeDet'
 * '<S5>'   : 'pa_state_common/CondiOverFlag/bCmpltDurattime'
 * '<S6>'   : 'pa_state_common/CondiOverFlag/bCmpltOvertime'
 * '<S7>'   : 'pa_state_common/CondiOverFlag/bHandshakOvertime'
 * '<S8>'   : 'pa_state_common/CondiOverFlag/bIntrptOverflow'
 * '<S9>'   : 'pa_state_common/CondiOverFlag/bIntrptOvertime'
 * '<S10>'  : 'pa_state_common/CondiOverFlag/bPPOvertime'
 * '<S11>'  : 'pa_state_common/CondiOverFlag/bQuitDurattime'
 * '<S12>'  : 'pa_state_common/CondiOverFlag/bStepOverflow'
 * '<S13>'  : 'pa_state_common/CondiOverFlag/bTrmntDurattime'
 * '<S14>'  : 'pa_state_common/CondiOverFlag/bTrmntOvertime'
 * '<S15>'  : 'pa_state_common/CondiOverFlag/ActiveOvertime/Enumerated Constant1'
 * '<S16>'  : 'pa_state_common/CondiOverFlag/ActiveOvertime/Enumerated Constant2'
 * '<S17>'  : 'pa_state_common/CondiOverFlag/ActiveOvertime/Enumerated Constant3'
 * '<S18>'  : 'pa_state_common/CondiOverFlag/ActiveOvertime/Enumerated Constant4'
 * '<S19>'  : 'pa_state_common/CondiOverFlag/ActiveOvertime/Enumerated Constant5'
 * '<S20>'  : 'pa_state_common/CondiOverFlag/ActiveOvertime/Enumerated Constant6'
 * '<S21>'  : 'pa_state_common/CondiOverFlag/ActiveOvertime/Timer7'
 * '<S22>'  : 'pa_state_common/CondiOverFlag/SelfCheckOvertimeDet/Enumerated Constant12'
 * '<S23>'  : 'pa_state_common/CondiOverFlag/SelfCheckOvertimeDet/Timer6'
 * '<S24>'  : 'pa_state_common/CondiOverFlag/bCmpltDurattime/Enumerated Constant1'
 * '<S25>'  : 'pa_state_common/CondiOverFlag/bCmpltDurattime/Enumerated Constant12'
 * '<S26>'  : 'pa_state_common/CondiOverFlag/bCmpltDurattime/Enumerated Constant2'
 * '<S27>'  : 'pa_state_common/CondiOverFlag/bCmpltDurattime/Enumerated Constant3'
 * '<S28>'  : 'pa_state_common/CondiOverFlag/bCmpltDurattime/Enumerated Constant4'
 * '<S29>'  : 'pa_state_common/CondiOverFlag/bCmpltDurattime/Timer4'
 * '<S30>'  : 'pa_state_common/CondiOverFlag/bCmpltOvertime/Enumerated Constant1'
 * '<S31>'  : 'pa_state_common/CondiOverFlag/bCmpltOvertime/Enumerated Constant12'
 * '<S32>'  : 'pa_state_common/CondiOverFlag/bCmpltOvertime/Enumerated Constant2'
 * '<S33>'  : 'pa_state_common/CondiOverFlag/bCmpltOvertime/Enumerated Constant3'
 * '<S34>'  : 'pa_state_common/CondiOverFlag/bCmpltOvertime/Enumerated Constant4'
 * '<S35>'  : 'pa_state_common/CondiOverFlag/bCmpltOvertime/Timer4'
 * '<S36>'  : 'pa_state_common/CondiOverFlag/bHandshakOvertime/Enumerated Constant1'
 * '<S37>'  : 'pa_state_common/CondiOverFlag/bHandshakOvertime/Enumerated Constant2'
 * '<S38>'  : 'pa_state_common/CondiOverFlag/bHandshakOvertime/Enumerated Constant3'
 * '<S39>'  : 'pa_state_common/CondiOverFlag/bHandshakOvertime/Enumerated Constant4'
 * '<S40>'  : 'pa_state_common/CondiOverFlag/bHandshakOvertime/Timer2'
 * '<S41>'  : 'pa_state_common/CondiOverFlag/bIntrptOverflow/Counter1'
 * '<S42>'  : 'pa_state_common/CondiOverFlag/bIntrptOverflow/Enumerated Constant1'
 * '<S43>'  : 'pa_state_common/CondiOverFlag/bIntrptOverflow/Enumerated Constant2'
 * '<S44>'  : 'pa_state_common/CondiOverFlag/bIntrptOverflow/Enumerated Constant3'
 * '<S45>'  : 'pa_state_common/CondiOverFlag/bIntrptOverflow/Enumerated Constant4'
 * '<S46>'  : 'pa_state_common/CondiOverFlag/bIntrptOverflow/Enumerated Constant5'
 * '<S47>'  : 'pa_state_common/CondiOverFlag/bIntrptOverflow/Enumerated Constant6'
 * '<S48>'  : 'pa_state_common/CondiOverFlag/bIntrptOverflow/Enumerated Constant7'
 * '<S49>'  : 'pa_state_common/CondiOverFlag/bIntrptOverflow/Enumerated Constant8'
 * '<S50>'  : 'pa_state_common/CondiOverFlag/bIntrptOvertime/Enumerated Constant11'
 * '<S51>'  : 'pa_state_common/CondiOverFlag/bIntrptOvertime/Enumerated Constant12'
 * '<S52>'  : 'pa_state_common/CondiOverFlag/bIntrptOvertime/Enumerated Constant2'
 * '<S53>'  : 'pa_state_common/CondiOverFlag/bIntrptOvertime/Enumerated Constant3'
 * '<S54>'  : 'pa_state_common/CondiOverFlag/bIntrptOvertime/Enumerated Constant4'
 * '<S55>'  : 'pa_state_common/CondiOverFlag/bIntrptOvertime/Timer3'
 * '<S56>'  : 'pa_state_common/CondiOverFlag/bPPOvertime/Enumerated Constant1'
 * '<S57>'  : 'pa_state_common/CondiOverFlag/bPPOvertime/Enumerated Constant2'
 * '<S58>'  : 'pa_state_common/CondiOverFlag/bPPOvertime/Enumerated Constant3'
 * '<S59>'  : 'pa_state_common/CondiOverFlag/bPPOvertime/Enumerated Constant4'
 * '<S60>'  : 'pa_state_common/CondiOverFlag/bPPOvertime/Enumerated Constant5'
 * '<S61>'  : 'pa_state_common/CondiOverFlag/bPPOvertime/Timer1'
 * '<S62>'  : 'pa_state_common/CondiOverFlag/bQuitDurattime/Enumerated Constant1'
 * '<S63>'  : 'pa_state_common/CondiOverFlag/bQuitDurattime/Enumerated Constant11'
 * '<S64>'  : 'pa_state_common/CondiOverFlag/bQuitDurattime/Enumerated Constant12'
 * '<S65>'  : 'pa_state_common/CondiOverFlag/bQuitDurattime/Enumerated Constant2'
 * '<S66>'  : 'pa_state_common/CondiOverFlag/bQuitDurattime/Enumerated Constant3'
 * '<S67>'  : 'pa_state_common/CondiOverFlag/bQuitDurattime/Timer5'
 * '<S68>'  : 'pa_state_common/CondiOverFlag/bStepOverflow/Counter'
 * '<S69>'  : 'pa_state_common/CondiOverFlag/bStepOverflow/Enumerated Constant1'
 * '<S70>'  : 'pa_state_common/CondiOverFlag/bStepOverflow/Enumerated Constant10'
 * '<S71>'  : 'pa_state_common/CondiOverFlag/bStepOverflow/Enumerated Constant11'
 * '<S72>'  : 'pa_state_common/CondiOverFlag/bStepOverflow/Enumerated Constant12'
 * '<S73>'  : 'pa_state_common/CondiOverFlag/bStepOverflow/Enumerated Constant2'
 * '<S74>'  : 'pa_state_common/CondiOverFlag/bStepOverflow/Enumerated Constant3'
 * '<S75>'  : 'pa_state_common/CondiOverFlag/bStepOverflow/Enumerated Constant4'
 * '<S76>'  : 'pa_state_common/CondiOverFlag/bStepOverflow/Enumerated Constant5'
 * '<S77>'  : 'pa_state_common/CondiOverFlag/bStepOverflow/Enumerated Constant6'
 * '<S78>'  : 'pa_state_common/CondiOverFlag/bStepOverflow/Enumerated Constant7'
 * '<S79>'  : 'pa_state_common/CondiOverFlag/bStepOverflow/Enumerated Constant8'
 * '<S80>'  : 'pa_state_common/CondiOverFlag/bStepOverflow/Enumerated Constant9'
 * '<S81>'  : 'pa_state_common/CondiOverFlag/bTrmntDurattime/Enumerated Constant11'
 * '<S82>'  : 'pa_state_common/CondiOverFlag/bTrmntDurattime/Enumerated Constant12'
 * '<S83>'  : 'pa_state_common/CondiOverFlag/bTrmntDurattime/Enumerated Constant2'
 * '<S84>'  : 'pa_state_common/CondiOverFlag/bTrmntDurattime/Enumerated Constant3'
 * '<S85>'  : 'pa_state_common/CondiOverFlag/bTrmntDurattime/Enumerated Constant4'
 * '<S86>'  : 'pa_state_common/CondiOverFlag/bTrmntDurattime/Timer6'
 * '<S87>'  : 'pa_state_common/CondiOverFlag/bTrmntOvertime/Enumerated Constant11'
 * '<S88>'  : 'pa_state_common/CondiOverFlag/bTrmntOvertime/Enumerated Constant12'
 * '<S89>'  : 'pa_state_common/CondiOverFlag/bTrmntOvertime/Enumerated Constant2'
 * '<S90>'  : 'pa_state_common/CondiOverFlag/bTrmntOvertime/Enumerated Constant3'
 * '<S91>'  : 'pa_state_common/CondiOverFlag/bTrmntOvertime/Enumerated Constant4'
 * '<S92>'  : 'pa_state_common/CondiOverFlag/bTrmntOvertime/Timer6'
 * '<S93>'  : 'pa_state_common/PAEvntDet/PAFailureEvntDet'
 * '<S94>'  : 'pa_state_common/PAEvntDet/PAInhibitEvntDet'
 * '<S95>'  : 'pa_state_common/PAEvntDet/PAIntrptEvntDet'
 * '<S96>'  : 'pa_state_common/PAEvntDet/PATrmntEvntDet'
 */
#endif                                 /* RTW_HEADER_pa_state_common_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
