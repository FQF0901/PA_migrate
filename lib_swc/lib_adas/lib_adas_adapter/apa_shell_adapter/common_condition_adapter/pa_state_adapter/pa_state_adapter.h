/*
 * File: pa_state_adapter.h
 *
 * Code generated for Simulink model 'pa_state_adapter'.
 *
 * Model version                  : 3.2829
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Thu Nov 28 16:34:59 2024
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

#ifndef RTW_HEADER_pa_state_adapter_h_
#define RTW_HEADER_pa_state_adapter_h_
#include <string.h>
#include "hmi_data_rx_type.h"
#include "common_condition_adapter_type.h"
#include "common_condition_type.h"
#include "master_lsad_fsm_type.h"
#include "lsad_fsm_core_type.h"
#include "slave_lsad_fsm_type.h"
#ifndef pa_state_adapter_COMMON_INCLUDES_
#define pa_state_adapter_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* pa_state_adapter_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Includes for objects with custom storage classes. */
#include "project_const_common.h"
#include "calib_lsad_fsm.h"

/* Block signals and states (default storage) for model 'pa_state_adapter' */
#ifndef pa_state_adapter_MDLREF_HIDE_CHILD_

typedef struct
{
  real32_T UnitDelay1_DSTATE;          /* '<S40>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_n;        /* '<S37>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_a;        /* '<S43>/Unit Delay1' */
  tLSAD_FuncSts UnitDelay2_DSTATE;     /* '<S1>/Unit Delay2' */
  tAPAMod UnitDelay1_DSTATE_c;         /* '<S2>/Unit Delay1' */
  tAPAMod UnitDelay1_DSTATE_e;         /* '<S27>/Unit Delay1' */
  tAPAMod UnitDelay2_DSTATE_c;         /* '<S27>/Unit Delay2' */
  tAPAMod UnitDelay4_DSTATE;           /* '<S1>/Unit Delay4' */
  tDragSlotType UnitDelay5_DSTATE;     /* '<S1>/Unit Delay5' */
  tPOSlotType UnitDelay5_DSTATE_c;     /* '<S12>/Unit Delay5' */
  tPOSlotType UnitDelay1_DSTATE_ad;    /* '<S12>/Unit Delay1' */
  tPODir UnitDelay7_DSTATE;            /* '<S12>/Unit Delay7' */
  tPrkFnct UnitDelay3_DSTATE;          /* '<S1>/Unit Delay3' */
  tPrkFnct UnitDelay1_DSTATE_d;        /* '<S1>/Unit Delay1' */
  tQuitEvnt UnitDelay8_DSTATE;         /* '<S3>/Unit Delay8' */
  struct
  {
    uint_T Delay_DSTATE:1;             /* '<S21>/Delay' */
    uint_T Delay_DSTATE_f:1;           /* '<S22>/Delay' */
    uint_T UnitDelay1_DSTATE_co:1;     /* '<S6>/Unit Delay1' */
  }
  bitsForTID0;

  tLSAD_SystemSts UnitDelay3_DSTATE_m; /* '<S6>/Unit Delay3' */
}
DW_pa_state_adapter_f_T;

#endif                                 /*pa_state_adapter_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for model 'pa_state_adapter' */
#ifndef pa_state_adapter_MDLREF_HIDE_CHILD_

typedef struct
{
  const tPrkSlot sDragPrkSlot;         /* '<Root>/Bus Assignment' */
  const tRPAChkList sRPAChkList;       /* '<Root>/Bus Assignment1' */
}
ConstB_pa_state_adapter_h_T;

#endif                                 /*pa_state_adapter_MDLREF_HIDE_CHILD_*/

#ifndef pa_state_adapter_MDLREF_HIDE_CHILD_

/* Invariant block signals (default storage) */
extern const ConstB_pa_state_adapter_h_T pa_state_adapter_ConstB;

#endif                                 /*pa_state_adapter_MDLREF_HIDE_CHILD_*/

extern void pa_state_adapter(const tVehCommon *rtu_sVehCommon, const tPAHmiRx
  *rtu_sPAHmiRx, const tVehDataRx *rtu_sVehDataRx, const tMasterLsadFsm
  *rtu_sLastMasterLsadFsm, const tDiagInfo *rtu_sDiagInfo, const tPaStateCommon *
  rtu_sPaStateCommon, const tSlaveLsadFsm *rtu_sLastSlaveLsadFsm, const
  tRelatedModuleInfo *rtu_sRelatedModuleInfo, tPaStateAdptr *rty_sPaStateAdptr);

/* Model reference registration function */
extern void pa_state_adapter_initialize(void);

#ifndef pa_state_adapter_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern DW_pa_state_adapter_f_T pa_state_adapter_DW;

#endif                                 /*pa_state_adapter_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'pa_state_adapter'
 * '<S1>'   : 'pa_state_adapter/CondiHMI'
 * '<S2>'   : 'pa_state_adapter/CondiOverFlagAdptr'
 * '<S3>'   : 'pa_state_adapter/PAEvntDet'
 * '<S4>'   : 'pa_state_adapter/CondiHMI/APAMod '
 * '<S5>'   : 'pa_state_adapter/CondiHMI/AppInitRPA'
 * '<S6>'   : 'pa_state_adapter/CondiHMI/BackgroundSrchDet'
 * '<S7>'   : 'pa_state_adapter/CondiHMI/Enumerated Constant1'
 * '<S8>'   : 'pa_state_adapter/CondiHMI/Enumerated Constant2'
 * '<S9>'   : 'pa_state_adapter/CondiHMI/Enumerated Constant3'
 * '<S10>'  : 'pa_state_adapter/CondiHMI/HmiSelfSelTypeSelectedDet'
 * '<S11>'  : 'pa_state_adapter/CondiHMI/PrkFnctDet '
 * '<S12>'  : 'pa_state_adapter/CondiHMI/PrkOutDirIndcr'
 * '<S13>'  : 'pa_state_adapter/CondiHMI/eDragSlotTypeDet'
 * '<S14>'  : 'pa_state_adapter/CondiHMI/BackgroundSrchDet/Enumerated Constant'
 * '<S15>'  : 'pa_state_adapter/CondiHMI/BackgroundSrchDet/Enumerated Constant1'
 * '<S16>'  : 'pa_state_adapter/CondiHMI/BackgroundSrchDet/Enumerated Constant20'
 * '<S17>'  : 'pa_state_adapter/CondiHMI/HmiSelfSelTypeSelectedDet/Enumerated Constant1'
 * '<S18>'  : 'pa_state_adapter/CondiHMI/HmiSelfSelTypeSelectedDet/Enumerated Constant2'
 * '<S19>'  : 'pa_state_adapter/CondiHMI/HmiSelfSelTypeSelectedDet/Enumerated Constant22'
 * '<S20>'  : 'pa_state_adapter/CondiHMI/HmiSelfSelTypeSelectedDet/Enumerated Constant3'
 * '<S21>'  : 'pa_state_adapter/CondiHMI/PrkOutDirIndcr/EdgeRising2'
 * '<S22>'  : 'pa_state_adapter/CondiHMI/PrkOutDirIndcr/EdgeRising3'
 * '<S23>'  : 'pa_state_adapter/CondiHMI/PrkOutDirIndcr/Enumerated Constant2'
 * '<S24>'  : 'pa_state_adapter/CondiHMI/PrkOutDirIndcr/Enumerated Constant3'
 * '<S25>'  : 'pa_state_adapter/CondiHMI/PrkOutDirIndcr/PODirDet'
 * '<S26>'  : 'pa_state_adapter/CondiHMI/PrkOutDirIndcr/POSlotType'
 * '<S27>'  : 'pa_state_adapter/CondiOverFlagAdptr/bPICnfmOvertime'
 * '<S28>'  : 'pa_state_adapter/CondiOverFlagAdptr/bPISrchOvertime'
 * '<S29>'  : 'pa_state_adapter/CondiOverFlagAdptr/bPOCnfmOvertime'
 * '<S30>'  : 'pa_state_adapter/CondiOverFlagAdptr/bRPACnfmOvertime'
 * '<S31>'  : 'pa_state_adapter/CondiOverFlagAdptr/bPICnfmOvertime/Enumerated Constant1'
 * '<S32>'  : 'pa_state_adapter/CondiOverFlagAdptr/bPICnfmOvertime/Enumerated Constant18'
 * '<S33>'  : 'pa_state_adapter/CondiOverFlagAdptr/bPICnfmOvertime/Enumerated Constant2'
 * '<S34>'  : 'pa_state_adapter/CondiOverFlagAdptr/bPICnfmOvertime/Enumerated Constant3'
 * '<S35>'  : 'pa_state_adapter/CondiOverFlagAdptr/bPICnfmOvertime/Enumerated Constant5'
 * '<S36>'  : 'pa_state_adapter/CondiOverFlagAdptr/bPICnfmOvertime/Enumerated Constant7'
 * '<S37>'  : 'pa_state_adapter/CondiOverFlagAdptr/bPICnfmOvertime/Timer9'
 * '<S38>'  : 'pa_state_adapter/CondiOverFlagAdptr/bPISrchOvertime/Enumerated Constant2'
 * '<S39>'  : 'pa_state_adapter/CondiOverFlagAdptr/bPISrchOvertime/Enumerated Constant3'
 * '<S40>'  : 'pa_state_adapter/CondiOverFlagAdptr/bPISrchOvertime/Timer8'
 * '<S41>'  : 'pa_state_adapter/CondiOverFlagAdptr/bPOCnfmOvertime/Enumerated Constant1'
 * '<S42>'  : 'pa_state_adapter/CondiOverFlagAdptr/bPOCnfmOvertime/Enumerated Constant22'
 * '<S43>'  : 'pa_state_adapter/CondiOverFlagAdptr/bPOCnfmOvertime/Timer10'
 * '<S44>'  : 'pa_state_adapter/PAEvntDet/Enumerated Constant'
 * '<S45>'  : 'pa_state_adapter/PAEvntDet/PAQuitEvntDet'
 * '<S46>'  : 'pa_state_adapter/PAEvntDet/PASuspendEvntDet'
 */
#endif                                 /* RTW_HEADER_pa_state_adapter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
