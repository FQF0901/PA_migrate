/*
 * File: pa_state_common.c
 *
 * Code generated for Simulink model 'pa_state_common'.
 *
 * Model version                  : 3.2842
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Dec  2 15:53:07 2024
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

#include "pa_state_common.h"

/* Block states (default storage) */
#define CtrlPara_START_SEC_VAR
#include "proj_MemMap.h"
DW_pa_state_common_f_T pa_state_common_DW;
#define CtrlPara_STOP_SEC_VAR
#include "proj_MemMap.h"
/* System initialize for referenced model: 'pa_state_common' */
void pa_state_common_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S12>/Unit Delay1' */
  pa_state_common_DW.UnitDelay1_DSTATE_gl = P_GEAR;

  /* InitializeConditions for UnitDelay: '<S12>/Unit Delay3' */
  pa_state_common_DW.UnitDelay3_DSTATE = P_GEAR;
}

/* Output and update for referenced model: 'pa_state_common' */
void pa_state_common(const tVehCommon *rtu_sVehCommon, const tPAHmiRx
                     *rtu_sPAHmiRx, const tVehDataRx *rtu_sVehDataRx, const
                     tRelatedModuleInfo *rtu_sRelatedModuleInfo, const tDiagInfo
                     *rtu_sDiagInfo, const tPaStateAdptr *rtu_sPaStateAdptr,
                     const tMasterLsadFsm *rtu_sLastMasterLsadFsm, const
                     tSlaveLsadFsm *rtu_sLastSlaveLsadFsm, tPaStateCommon
                     *rty_sPaStateCommon)
{
  boolean_T bRPAPrepareAndCtrled;

  /* Switch: '<S61>/Switch1' incorporates:
   *  Constant: '<S56>/Constant'
   *  Constant: '<S57>/Constant'
   *  Constant: '<S58>/Constant'
   *  Constant: '<S59>/Constant'
   *  Constant: '<S60>/Constant'
   *  Constant: '<S61>/Constant Value2'
   *  Logic: '<S10>/Logical Operator2'
   *  Logic: '<S10>/OR'
   *  Logic: '<S10>/OR1'
   *  RelationalOperator: '<S10>/Equal1'
   *  RelationalOperator: '<S10>/Equal3'
   *  RelationalOperator: '<S10>/Equal4'
   *  RelationalOperator: '<S10>/Equal5'
   *  RelationalOperator: '<S10>/Equal6'
   *  Switch: '<S61>/Switch'
   *  UnitDelay: '<S61>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts !=
          LSAD_STS_PP) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
           ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
      ((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_PARK_IN) ?
      ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)) &
      (((boolean_T)((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncType ==
      LSAD_PARK_OUT) ? ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) :
       ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
      (((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_PARK_STRAIGHT) ? ((int32_T)
      1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
             : ((int32_T)0)) & (((boolean_T)((int32_T)
               (((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_DRAG_PARK_IN) ?
                 ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)
              0))))) ? ((int32_T)1) : ((int32_T)0)))))
  {
    pa_state_common_DW.UnitDelay1_DSTATE = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S61>/Unit Delay1' incorporates:
     *  Constant: '<S10>/Constant3'
     *  Sum: '<S61>/Subtraction'
     */
    pa_state_common_DW.UnitDelay1_DSTATE += s_APPManLoopSec;
  }

  /* End of Switch: '<S61>/Switch1' */

  /* Switch: '<S40>/Switch1' incorporates:
   *  Constant: '<S36>/Constant'
   *  Constant: '<S37>/Constant'
   *  Constant: '<S38>/Constant'
   *  Constant: '<S39>/Constant'
   *  Constant: '<S40>/Constant Value2'
   *  Logic: '<S7>/Logical Operator3'
   *  Logic: '<S7>/OR'
   *  Logic: '<S7>/OR1'
   *  RelationalOperator: '<S10>/Equal3'
   *  RelationalOperator: '<S7>/Equal1'
   *  RelationalOperator: '<S7>/Equal2'
   *  RelationalOperator: '<S7>/Equal4'
   *  RelationalOperator: '<S7>/Equal6'
   *  Switch: '<S40>/Switch'
   *  UnitDelay: '<S40>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts !=
          LSAD_STS_HANDSHAKE) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)
          ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      (((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_PARK_IN) ? ((int32_T)1) :
        ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)
      ((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_PARK_OUT) ?
                  ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)
      0))))) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
               (((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_PARK_STRAIGHT) ?
                 ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)
              0))))) ? ((int32_T)1) : ((int32_T)0)))))
  {
    pa_state_common_DW.UnitDelay1_DSTATE_l = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S40>/Unit Delay1' incorporates:
     *  Constant: '<S7>/Constant5'
     *  Sum: '<S40>/Subtraction'
     */
    pa_state_common_DW.UnitDelay1_DSTATE_l += s_APPManLoopSec;
  }

  /* End of Switch: '<S40>/Switch1' */

  /* Switch: '<S21>/Switch1' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S16>/Constant'
   *  Constant: '<S17>/Constant'
   *  Constant: '<S18>/Constant'
   *  Constant: '<S19>/Constant'
   *  Constant: '<S20>/Constant'
   *  Constant: '<S21>/Constant Value2'
   *  Logic: '<S3>/Logical Operator'
   *  Logic: '<S3>/Logical Operator8'
   *  Logic: '<S3>/OR'
   *  Logic: '<S3>/OR1'
   *  RelationalOperator: '<S10>/Equal3'
   *  RelationalOperator: '<S3>/Equal'
   *  RelationalOperator: '<S3>/Equal1'
   *  RelationalOperator: '<S3>/Equal2'
   *  RelationalOperator: '<S3>/Equal4'
   *  RelationalOperator: '<S3>/Equal5'
   *  RelationalOperator: '<S3>/Equal6'
   *  Switch: '<S21>/Switch'
   *  UnitDelay: '<S21>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
           (((rtu_sLastMasterLsadFsm->eLsadSystemSts != LSAD_STS_ACTIVE_SUSPEND)
             ? ((int32_T)1) : ((int32_T)0)) &
            ((rtu_sLastMasterLsadFsm->eLsadSystemSts != LSAD_STS_ACTIVE) ?
             ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
        (((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncType ==
      LSAD_PARK_IN) ? ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) :
        ((int32_T)0)) & (((boolean_T)((int32_T)
      (((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_PARK_OUT) ? ((int32_T)1) :
    ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
      ((int32_T)0)) & (((boolean_T)((int32_T)
      (((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_PARK_STRAIGHT) ? ((int32_T)
      1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
             : ((int32_T)0)) & (((boolean_T)((int32_T)
               (((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_DRAG_PARK_IN) ?
                 ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)
              0))))) ? ((int32_T)1) : ((int32_T)0)))))
  {
    pa_state_common_DW.UnitDelay1_DSTATE_a = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S21>/Unit Delay1' incorporates:
     *  Constant: '<S3>/Constant15'
     *  Sum: '<S21>/Subtraction'
     */
    pa_state_common_DW.UnitDelay1_DSTATE_a += s_APPManLoopSec;
  }

  /* End of Switch: '<S21>/Switch1' */

  /* Switch: '<S41>/Switch1' incorporates:
   *  Constant: '<S41>/Constant1'
   *  Constant: '<S42>/Constant'
   *  Constant: '<S43>/Constant'
   *  Constant: '<S44>/Constant'
   *  Constant: '<S45>/Constant'
   *  Constant: '<S46>/Constant'
   *  Constant: '<S47>/Constant'
   *  Constant: '<S48>/Constant'
   *  Constant: '<S49>/Constant'
   *  Constant: '<S68>/Constant1'
   *  Logic: '<S8>/Logical Operator'
   *  Logic: '<S8>/Logical Operator1'
   *  Logic: '<S8>/Logical Operator2'
   *  Logic: '<S8>/OR'
   *  Logic: '<S8>/OR1'
   *  RelationalOperator: '<S10>/Equal3'
   *  RelationalOperator: '<S8>/Equal'
   *  RelationalOperator: '<S8>/Equal1'
   *  RelationalOperator: '<S8>/Equal2'
   *  RelationalOperator: '<S8>/Equal3'
   *  RelationalOperator: '<S8>/Equal4'
   *  RelationalOperator: '<S8>/Equal5'
   *  RelationalOperator: '<S8>/Equal6'
   *  RelationalOperator: '<S8>/Equal7'
   *  Switch: '<S41>/Switch'
   *  Switch: '<S68>/Switch1'
   *  UnitDelay: '<S41>/Unit Delay1'
   *  UnitDelay: '<S68>/Unit Delay1'
   *  UnitDelay: '<S8>/Unit Delay'
   */
  if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts !=
          LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0)) &
        ((rtu_sLastMasterLsadFsm->eLsadSystemSts != LSAD_STS_ACTIVE) ? ((int32_T)
          1) : ((int32_T)0)))))
  {
    pa_state_common_DW.UnitDelay1_DSTATE_f = 0U;
    pa_state_common_DW.UnitDelay1_DSTATE_gk = 0U;
  }
  else
  {
    if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
                 ((((boolean_T)((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncType
      == LSAD_PARK_IN) ? ((int32_T)1) : ((int32_T)0)) |
        ((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_PARK_OUT) ? ((int32_T)1) :
         ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
                  ((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_PARK_STRAIGHT) ?
                   ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
              | ((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_DRAG_PARK_IN) ?
                 ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
          & (((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0)) &
              ((pa_state_common_DW.UnitDelay_DSTATE == LSAD_STS_ACTIVE) ?
               ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)))))
    {
      /* UnitDelay: '<S41>/Unit Delay1' incorporates:
       *  Constant: '<S41>/Constant'
       *  Sum: '<S41>/Add'
       *  Switch: '<S41>/Switch'
       */
      pa_state_common_DW.UnitDelay1_DSTATE_f = (uint16_T)(((uint32_T)
        pa_state_common_DW.UnitDelay1_DSTATE_f) + 1U);
    }

    /* Switch: '<S68>/Switch' incorporates:
     *  Constant: '<S69>/Constant'
     *  Constant: '<S70>/Constant'
     *  Constant: '<S71>/Constant'
     *  Constant: '<S72>/Constant'
     *  Constant: '<S73>/Constant'
     *  Constant: '<S76>/Constant'
     *  Constant: '<S77>/Constant'
     *  Constant: '<S78>/Constant'
     *  Constant: '<S79>/Constant'
     *  Constant: '<S80>/Constant'
     *  Logic: '<S12>/Logical Operator1'
     *  Logic: '<S12>/Logical Operator10'
     *  Logic: '<S12>/Logical Operator11'
     *  Logic: '<S12>/Logical Operator2'
     *  Logic: '<S12>/OR'
     *  Logic: '<S12>/OR1'
     *  RelationalOperator: '<S12>/Equal1'
     *  RelationalOperator: '<S12>/Equal10'
     *  RelationalOperator: '<S12>/Equal2'
     *  RelationalOperator: '<S12>/Equal20'
     *  RelationalOperator: '<S12>/Equal21'
     *  RelationalOperator: '<S12>/Equal22'
     *  RelationalOperator: '<S12>/Equal5'
     *  RelationalOperator: '<S12>/Equal7'
     *  RelationalOperator: '<S12>/Equal8'
     *  RelationalOperator: '<S12>/Equal9'
     *  UnitDelay: '<S12>/Unit Delay1'
     *  UnitDelay: '<S12>/Unit Delay3'
     */
    if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
                 ((((boolean_T)((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncType
      == LSAD_PARK_IN) ? ((int32_T)1) : ((int32_T)0)) |
        ((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_PARK_OUT) ? ((int32_T)1) :
         ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
                  ((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_PARK_STRAIGHT) ?
                   ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
              | ((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_DRAG_PARK_IN) ?
                 ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
          & (((boolean_T)((int32_T)((((boolean_T)((int32_T)
                 (((rtu_sPaStateAdptr->sCondiHMI.eAPAMod != APA_MODE_STRAIGHT) ?
                   ((int32_T)1) : ((int32_T)0)) &
                  ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                   ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
              & (((boolean_T)((int32_T)((((boolean_T)((int32_T)
        (((rtu_sVehDataRx->sVehVCUInfo.eVehActualGear == R_GEAR) ? ((int32_T)1) :
          ((int32_T)0)) & ((pa_state_common_DW.UnitDelay1_DSTATE_gl != R_GEAR) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
                  (((boolean_T)((int32_T)
        (((rtu_sVehDataRx->sVehVCUInfo.eVehActualGear == D_GEAR) ? ((int32_T)1) :
          ((int32_T)0)) & ((pa_state_common_DW.UnitDelay3_DSTATE != D_GEAR) ?
                           ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                   ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) ?
             ((int32_T)1) : ((int32_T)0)))))
    {
      /* UnitDelay: '<S68>/Unit Delay1' incorporates:
       *  Constant: '<S68>/Constant'
       *  Sum: '<S68>/Add'
       */
      pa_state_common_DW.UnitDelay1_DSTATE_gk = (uint16_T)(((uint32_T)
        pa_state_common_DW.UnitDelay1_DSTATE_gk) + 1U);
    }

    /* End of Switch: '<S68>/Switch' */
  }

  /* End of Switch: '<S41>/Switch1' */

  /* Switch: '<S55>/Switch1' incorporates:
   *  Constant: '<S50>/Constant'
   *  Constant: '<S51>/Constant'
   *  Constant: '<S52>/Constant'
   *  Constant: '<S53>/Constant'
   *  Constant: '<S54>/Constant'
   *  Constant: '<S55>/Constant Value2'
   *  Logic: '<S9>/Logical Operator4'
   *  Logic: '<S9>/OR'
   *  Logic: '<S9>/OR1'
   *  RelationalOperator: '<S10>/Equal3'
   *  RelationalOperator: '<S9>/Equal1'
   *  RelationalOperator: '<S9>/Equal10'
   *  RelationalOperator: '<S9>/Equal20'
   *  RelationalOperator: '<S9>/Equal4'
   *  RelationalOperator: '<S9>/Equal5'
   *  Switch: '<S55>/Switch'
   *  UnitDelay: '<S55>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts !=
          LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)
          ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncType ==
      LSAD_PARK_IN) ? ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) :
        ((int32_T)0)) & (((boolean_T)((int32_T)
      (((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_PARK_OUT) ? ((int32_T)1) :
    ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
      ((int32_T)0)) & (((boolean_T)((int32_T)
      (((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_PARK_STRAIGHT) ? ((int32_T)
      1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
                      : ((int32_T)0)) & (((boolean_T)((int32_T)
               (((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_DRAG_PARK_IN) ?
                 ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)
              0))))) ? ((int32_T)1) : ((int32_T)0)))))
  {
    pa_state_common_DW.UnitDelay1_DSTATE_j = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S55>/Unit Delay1' incorporates:
     *  Constant: '<S9>/Constant8'
     *  Sum: '<S55>/Subtraction'
     */
    pa_state_common_DW.UnitDelay1_DSTATE_j += s_APPManLoopSec;
  }

  /* End of Switch: '<S55>/Switch1' */

  /* Switch: '<S29>/Switch1' incorporates:
   *  Constant: '<S24>/Constant'
   *  Constant: '<S25>/Constant'
   *  Constant: '<S26>/Constant'
   *  Constant: '<S27>/Constant'
   *  Constant: '<S28>/Constant'
   *  Constant: '<S29>/Constant Value2'
   *  Constant: '<S35>/Constant Value2'
   *  Logic: '<S5>/Logical Operator5'
   *  Logic: '<S5>/OR'
   *  Logic: '<S5>/OR1'
   *  RelationalOperator: '<S10>/Equal3'
   *  RelationalOperator: '<S5>/Equal1'
   *  RelationalOperator: '<S5>/Equal2'
   *  RelationalOperator: '<S5>/Equal20'
   *  RelationalOperator: '<S5>/Equal4'
   *  RelationalOperator: '<S5>/Equal5'
   *  Switch: '<S29>/Switch'
   *  Switch: '<S35>/Switch'
   *  Switch: '<S35>/Switch1'
   *  UnitDelay: '<S29>/Unit Delay1'
   *  UnitDelay: '<S35>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts !=
          LSAD_STS_COMPLETE) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)
          ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncType ==
      LSAD_PARK_IN) ? ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) :
        ((int32_T)0)) & (((boolean_T)((int32_T)
      (((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_PARK_OUT) ? ((int32_T)1) :
    ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
      ((int32_T)0)) & (((boolean_T)((int32_T)
      (((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_PARK_STRAIGHT) ? ((int32_T)
      1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
                      : ((int32_T)0)) & (((boolean_T)((int32_T)
               (((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_DRAG_PARK_IN) ?
                 ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)
              0))))) ? ((int32_T)1) : ((int32_T)0)))))
  {
    pa_state_common_DW.UnitDelay1_DSTATE_g = 0.0F;
    pa_state_common_DW.UnitDelay1_DSTATE_k = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S29>/Unit Delay1' incorporates:
     *  Constant: '<S5>/Constant10'
     *  Sum: '<S29>/Subtraction'
     */
    pa_state_common_DW.UnitDelay1_DSTATE_g += s_APPManLoopSec;

    /* UnitDelay: '<S35>/Unit Delay1' incorporates:
     *  Constant: '<S6>/Constant10'
     *  Sum: '<S35>/Subtraction'
     */
    pa_state_common_DW.UnitDelay1_DSTATE_k += s_APPManLoopSec;
  }

  /* End of Switch: '<S29>/Switch1' */

  /* Switch: '<S67>/Switch1' incorporates:
   *  Constant: '<S62>/Constant'
   *  Constant: '<S63>/Constant'
   *  Constant: '<S64>/Constant'
   *  Constant: '<S65>/Constant'
   *  Constant: '<S66>/Constant'
   *  Constant: '<S67>/Constant Value2'
   *  Logic: '<S11>/Logical Operator6'
   *  Logic: '<S11>/OR'
   *  Logic: '<S11>/OR1'
   *  RelationalOperator: '<S10>/Equal3'
   *  RelationalOperator: '<S11>/Equal1'
   *  RelationalOperator: '<S11>/Equal10'
   *  RelationalOperator: '<S11>/Equal2'
   *  RelationalOperator: '<S11>/Equal20'
   *  RelationalOperator: '<S11>/Equal4'
   *  Switch: '<S67>/Switch'
   *  UnitDelay: '<S67>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts !=
          LSAD_STS_QUIT) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
           ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
      ((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_PARK_IN) ?
      ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)) &
      (((boolean_T)((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncType ==
      LSAD_PARK_OUT) ? ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) :
       ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
      (((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_PARK_STRAIGHT) ? ((int32_T)
      1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
             : ((int32_T)0)) & (((boolean_T)((int32_T)
               (((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_DRAG_PARK_IN) ?
                 ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)
              0))))) ? ((int32_T)1) : ((int32_T)0)))))
  {
    pa_state_common_DW.UnitDelay1_DSTATE_p = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S67>/Unit Delay1' incorporates:
     *  Constant: '<S11>/Constant11'
     *  Sum: '<S67>/Subtraction'
     */
    pa_state_common_DW.UnitDelay1_DSTATE_p += s_APPManLoopSec;
  }

  /* End of Switch: '<S67>/Switch1' */

  /* Switch: '<S86>/Switch1' incorporates:
   *  Constant: '<S81>/Constant'
   *  Constant: '<S82>/Constant'
   *  Constant: '<S83>/Constant'
   *  Constant: '<S84>/Constant'
   *  Constant: '<S85>/Constant'
   *  Constant: '<S86>/Constant Value2'
   *  Constant: '<S92>/Constant Value2'
   *  Logic: '<S13>/Logical Operator7'
   *  Logic: '<S13>/OR'
   *  Logic: '<S13>/OR1'
   *  RelationalOperator: '<S10>/Equal3'
   *  RelationalOperator: '<S13>/Equal1'
   *  RelationalOperator: '<S13>/Equal10'
   *  RelationalOperator: '<S13>/Equal20'
   *  RelationalOperator: '<S13>/Equal4'
   *  RelationalOperator: '<S13>/Equal5'
   *  Switch: '<S86>/Switch'
   *  Switch: '<S92>/Switch'
   *  Switch: '<S92>/Switch1'
   *  UnitDelay: '<S86>/Unit Delay1'
   *  UnitDelay: '<S92>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts !=
          LSAD_STS_TERMINATED) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)
          ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncType ==
      LSAD_PARK_IN) ? ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) :
        ((int32_T)0)) & (((boolean_T)((int32_T)
      (((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_PARK_OUT) ? ((int32_T)1) :
    ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
      ((int32_T)0)) & (((boolean_T)((int32_T)
      (((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_PARK_STRAIGHT) ? ((int32_T)
      1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
                      : ((int32_T)0)) & (((boolean_T)((int32_T)
               (((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_DRAG_PARK_IN) ?
                 ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)
              0))))) ? ((int32_T)1) : ((int32_T)0)))))
  {
    pa_state_common_DW.UnitDelay1_DSTATE_b = 0.0F;
    pa_state_common_DW.UnitDelay1_DSTATE_bb = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S86>/Unit Delay1' incorporates:
     *  Constant: '<S13>/Constant13'
     *  Sum: '<S86>/Subtraction'
     */
    pa_state_common_DW.UnitDelay1_DSTATE_b += s_APPManLoopSec;

    /* UnitDelay: '<S92>/Unit Delay1' incorporates:
     *  Constant: '<S14>/Constant13'
     *  Sum: '<S92>/Subtraction'
     */
    pa_state_common_DW.UnitDelay1_DSTATE_bb += s_APPManLoopSec;
  }

  /* End of Switch: '<S86>/Switch1' */

  /* Switch: '<S23>/Switch1' incorporates:
   *  Constant: '<S22>/Constant'
   *  Constant: '<S23>/Constant Value2'
   *  Logic: '<S4>/Logical Operator7'
   *  RelationalOperator: '<S10>/Equal3'
   *  RelationalOperator: '<S4>/Equal20'
   *  Switch: '<S23>/Switch'
   *  UnitDelay: '<S23>/Unit Delay1'
   */
  if (rtu_sLastMasterLsadFsm->eLsadSystemSts != LSAD_STS_OFF)
  {
    pa_state_common_DW.UnitDelay1_DSTATE_gx = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S23>/Unit Delay1' incorporates:
     *  Constant: '<S4>/Constant13'
     *  Sum: '<S23>/Subtraction'
     */
    pa_state_common_DW.UnitDelay1_DSTATE_gx += s_APPManLoopSec;
  }

  /* End of Switch: '<S23>/Switch1' */

  /* BusAssignment: '<S1>/Bus Assignment' incorporates:
   *  Constant: '<S10>/Constant2'
   *  Constant: '<S11>/Constant12'
   *  Constant: '<S12>/Constant4'
   *  Constant: '<S13>/Constant14'
   *  Constant: '<S14>/Constant14'
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S3>/Constant16'
   *  Constant: '<S4>/Constant14'
   *  Constant: '<S5>/Constant9'
   *  Constant: '<S6>/Constant9'
   *  Constant: '<S7>/Constant4'
   *  Constant: '<S8>/Constant18'
   *  Constant: '<S9>/Constant7'
   *  RelationalOperator: '<S10>/Equal2'
   *  RelationalOperator: '<S11>/Equal12'
   *  RelationalOperator: '<S12>/Equal6'
   *  RelationalOperator: '<S13>/Equal14'
   *  RelationalOperator: '<S14>/Equal14'
   *  RelationalOperator: '<S3>/Equal16'
   *  RelationalOperator: '<S4>/Equal14'
   *  RelationalOperator: '<S5>/Equal9'
   *  RelationalOperator: '<S6>/Equal9'
   *  RelationalOperator: '<S7>/Equal5'
   *  RelationalOperator: '<S8>/Equal31'
   *  RelationalOperator: '<S9>/Equal7'
   *  UnitDelay: '<S21>/Unit Delay1'
   *  UnitDelay: '<S23>/Unit Delay1'
   *  UnitDelay: '<S29>/Unit Delay1'
   *  UnitDelay: '<S35>/Unit Delay1'
   *  UnitDelay: '<S40>/Unit Delay1'
   *  UnitDelay: '<S41>/Unit Delay1'
   *  UnitDelay: '<S55>/Unit Delay1'
   *  UnitDelay: '<S61>/Unit Delay1'
   *  UnitDelay: '<S67>/Unit Delay1'
   *  UnitDelay: '<S68>/Unit Delay1'
   *  UnitDelay: '<S86>/Unit Delay1'
   *  UnitDelay: '<S92>/Unit Delay1'
   */
  (void)memset(&rty_sPaStateCommon->sCondiOverFlag, 0, sizeof(tCondiOverFlag));
  rty_sPaStateCommon->sCondiOverFlag.bPPOvertime =
    (pa_state_common_DW.UnitDelay1_DSTATE >= k_PPDuratTime);
  rty_sPaStateCommon->sCondiOverFlag.bHandshakOvertime =
    (pa_state_common_DW.UnitDelay1_DSTATE_l >= k_HandDuratTime);
  rty_sPaStateCommon->sCondiOverFlag.bActiveRdyOvertime = false;
  rty_sPaStateCommon->sCondiOverFlag.bActiveOvertime =
    (pa_state_common_DW.UnitDelay1_DSTATE_a >= k_ManeuverDuratTime);
  rty_sPaStateCommon->sCondiOverFlag.bIntrptOverflow =
    (pa_state_common_DW.UnitDelay1_DSTATE_f >= ((uint16_T)k_RcvItrpt_MaxTime));
  rty_sPaStateCommon->sCondiOverFlag.bStepOverflow =
    (pa_state_common_DW.UnitDelay1_DSTATE_gk > ((uint16_T)k_ManeuverMaxMoveStep));
  rty_sPaStateCommon->sCondiOverFlag.bIntrptOvertime =
    (pa_state_common_DW.UnitDelay1_DSTATE_j >= k_RcvItrptDuratTime);
  rty_sPaStateCommon->sCondiOverFlag.bCmpltDurattime =
    (pa_state_common_DW.UnitDelay1_DSTATE_g >= k_CmpltDuratTime);
  rty_sPaStateCommon->sCondiOverFlag.bCmpltOvertime =
    (pa_state_common_DW.UnitDelay1_DSTATE_k >= 4.0F);
  rty_sPaStateCommon->sCondiOverFlag.bQuitDurattime =
    (pa_state_common_DW.UnitDelay1_DSTATE_p >= k_QuitDuratTime);
  rty_sPaStateCommon->sCondiOverFlag.bTrmntDurattime =
    (pa_state_common_DW.UnitDelay1_DSTATE_b >= k_TmntDuratTime);
  rty_sPaStateCommon->sCondiOverFlag.bTrmntOvertime =
    (pa_state_common_DW.UnitDelay1_DSTATE_bb >= 4.0F);
  rty_sPaStateCommon->sCondiOverFlag.bPwrOnSelfChkDurattime =
    (pa_state_common_DW.UnitDelay1_DSTATE_gx >= 25.0F);

  /* MATLAB Function: '<S2>/PAIntrptEvntDet' incorporates:
   *  RelationalOperator: '<S10>/Equal3'
   *  UnitDelay: '<S2>/Unit Delay9'
   */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)(((LSAD_PARK_IN ==
              rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0))
            | ((LSAD_PARK_OUT == rtu_sLastSlaveLsadFsm->eLsadFuncType) ?
               ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
        ((LSAD_PARK_STRAIGHT == rtu_sLastSlaveLsadFsm->eLsadFuncType) ?
         ((int32_T)1) : ((int32_T)0)))))
  {
    if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
            LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0)) |
          ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE_SUSPEND) ?
           ((int32_T)1) : ((int32_T)0)))))
    {
      if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
                   ((((boolean_T)((int32_T)((((boolean_T)((int32_T)
          ((rtu_sVehCommon->sCondiDoorSblt.bFLDrClose ? ((int32_T)1) : ((int32_T)
          0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
          ((rtu_sVehCommon->sCondiDoorSblt.bFRDrClose ? ((int32_T)1) : ((int32_T)
          0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                     ((int32_T)0)) | (((boolean_T)((int32_T)
          ((rtu_sVehCommon->sCondiDoorSblt.bRLDrClose ? ((int32_T)1) : ((int32_T)
          0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                 ((int32_T)0)) | (((boolean_T)((int32_T)
                   ((rtu_sVehCommon->sCondiDoorSblt.bRRDrClose ? ((int32_T)1) :
                     ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ?
             ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
               ((rtu_sVehCommon->sCondiDoorSblt.bHoodDrClose ? ((int32_T)1) :
                 ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
      {
        rty_sPaStateCommon->sPAEvnt.ePAIntrptEvnt = INTERRUPT_DOOR_OPEN;
        pa_state_common_DW.UnitDelay9_DSTATE = INTERRUPTION_NEED_CONFIRM;
      }
      else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
          ((int32_T)((rtu_sVehCommon->sCondiDoorSblt.bSeatbltAct ? ((int32_T)1) :
                      ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sCondiHMI.ePrkFnct == PARK_FUNC_APA) ? ((int32_T)
          1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
                 (k_bIntrptEvntSeatblt ? ((int32_T)1) : ((int32_T)0)))))
      {
        rty_sPaStateCommon->sPAEvnt.ePAIntrptEvnt = INTERRUPT_SEATBELT_UNBUCKLED;
        pa_state_common_DW.UnitDelay9_DSTATE = INTERRUPTION_NEED_CONFIRM;
      }
      else if ((boolean_T)((int32_T)
                           ((rtu_sVehCommon->sCondiDoorSblt.bTailGateClose ?
                             ((int32_T)1) : ((int32_T)0)) ^ 1)))
      {
        rty_sPaStateCommon->sPAEvnt.ePAIntrptEvnt = INTERRUPT_TRUNK_OPEN;
        pa_state_common_DW.UnitDelay9_DSTATE = INTERRUPTION_NEED_CONFIRM;
      }
      else if (rtu_sVehCommon->sCondiPlatform.bObstAppear)
      {
        rty_sPaStateCommon->sPAEvnt.ePAIntrptEvnt = INTERRUPT_OBSTACLE;
        pa_state_common_DW.UnitDelay9_DSTATE = INTERRUPTION_NEED_CONFIRM;

        /*          elseif (eVehicleActionRequest == ECtrlAction.CTRL_ACTION_PAUSE &&... */
        /*                  (eVehicleActionReason == ECtrlActionReason.CTRL_ACTION_REASON_PAUSE_TRAP || ... */
        /*                   eVehicleActionReason == ECtrlActionReason.CTRL_ACTION_REASON_PAUSE_PRECHECK_ERROR ||... */
        /*                   eVehicleActionReason == ECtrlActionReason.CTRL_ACTION_REASON_PAUSE_PARKIN_SLOT_OCCUPY)) */
        /*              ePAIntrptEvnt = tIntrptEvnt.INTERRUPT_PP_REQ_PAUSE; */
        /*              ePAIntrptType = tIntrptType.INTERRUPTION_NEED_CONFIRM; */
      }
      else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
          ((int32_T)((rtu_sVehCommon->sCondiPlatform.bActvStsNeedRlsBrk ?
                      ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) :
          ((int32_T)0)) & (rtu_sVehDataRx->sVehVCUInfo.bBrkPedal ? ((int32_T)1) :
                           ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
                 (k_bIntrptEvntBrkPdl ? ((int32_T)1) : ((int32_T)0)))))
      {
        rty_sPaStateCommon->sPAEvnt.ePAIntrptEvnt = INTERRUPT_MANUAL_BRAKE;
        pa_state_common_DW.UnitDelay9_DSTATE = INTERRUPTION_NO_CONFIRM;
      }
      else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                    (((rtu_sPaStateAdptr->sCondiHMI.ePrkFnct == PARK_FUNC_RPA) ?
                      ((int32_T)1) : ((int32_T)0)) &
                     ((rtu_sPaStateAdptr->sCondiHMI.eAPAMod != APA_MODE_STRAIGHT)
                      ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                  ((int32_T)0)) & ((rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkWorkMd ==
                   PRK_WORK_PAUSE) ? ((int32_T)1) : ((int32_T)0)))))
      {
        rty_sPaStateCommon->sPAEvnt.ePAIntrptEvnt = INTERRUPT_RPA_BUTTON_RELEASE;
        pa_state_common_DW.UnitDelay9_DSTATE = INTERRUPTION_NEED_CONFIRM;
      }
      else if ((boolean_T)((int32_T)(((rtu_sPaStateAdptr->sCondiHMI.ePrkFnct ==
                   PARK_FUNC_RPA) ? ((int32_T)1) : ((int32_T)0)) &
                 (rtu_sPaStateAdptr->sCondiHMI.bPhoneHangUp ? ((int32_T)1) :
                  ((int32_T)0)))))
      {
        rty_sPaStateCommon->sPAEvnt.ePAIntrptEvnt = INTERRUPT_RPA_ANSWER_PHONE;
        pa_state_common_DW.UnitDelay9_DSTATE = INTERRUPTION_NEED_CONFIRM;

        /*              	elseif (sCondiHMI.ePrkFnct == tPrkFnct.PARK_FUNC_RPA)&&... */
        /*                        (sHMIDataRx.sRPAInfoRx.eRPAPrkWorkMd == tPrkWorkMd.PRK_WORK_EXIT) */
        /*                      ePAIntrptEvnt = tIntrptEvnt.INTERRUPT_RPA_APP_EXIT; */
        /*                      ePAIntrptType = tIntrptType.INTERRUPTION_NEED_CONFIRM; */
      }
      else if ((boolean_T)((int32_T)(((rtu_sPaStateAdptr->sCondiHMI.ePrkFnct ==
                   PARK_FUNC_APA) ? ((int32_T)1) : ((int32_T)0)) &
                 ((rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkWorkMd == PRK_WORK_PAUSE) ?
                  ((int32_T)1) : ((int32_T)0)))))
      {
        rty_sPaStateCommon->sPAEvnt.ePAIntrptEvnt = INTERRUPT_MANUAL_PAUSE;
        pa_state_common_DW.UnitDelay9_DSTATE = INTERRUPTION_NEED_CONFIRM;
      }
      else
      {
        rty_sPaStateCommon->sPAEvnt.ePAIntrptEvnt = INTERRUPT_NONE;
      }
    }
    else
    {
      rty_sPaStateCommon->sPAEvnt.ePAIntrptEvnt = INTERRUPT_NONE;
    }
  }
  else
  {
    rty_sPaStateCommon->sPAEvnt.ePAIntrptEvnt = INTERRUPT_NONE;
    pa_state_common_DW.UnitDelay9_DSTATE = INTERRUTPION_NONE;
  }

  /* End of MATLAB Function: '<S2>/PAIntrptEvntDet' */

  /* MATLAB Function: '<S2>/PATrmntEvntDet' incorporates:
   *  Constant: '<S10>/Constant2'
   *  Constant: '<S12>/Constant4'
   *  Constant: '<S3>/Constant16'
   *  Constant: '<S8>/Constant18'
   *  Constant: '<S9>/Constant7'
   *  RelationalOperator: '<S10>/Equal2'
   *  RelationalOperator: '<S10>/Equal3'
   *  RelationalOperator: '<S12>/Equal6'
   *  RelationalOperator: '<S3>/Equal16'
   *  RelationalOperator: '<S8>/Equal31'
   *  RelationalOperator: '<S9>/Equal7'
   *  UnitDelay: '<S21>/Unit Delay1'
   *  UnitDelay: '<S2>/Unit Delay7'
   *  UnitDelay: '<S41>/Unit Delay1'
   *  UnitDelay: '<S55>/Unit Delay1'
   *  UnitDelay: '<S61>/Unit Delay1'
   *  UnitDelay: '<S68>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
               ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
      ((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts != LSAD_STS_PREPARE) ?
    ((int32_T)1) : ((int32_T)0)) & ((rtu_sLastMasterLsadFsm->eLsadSystemSts !=
      LSAD_STS_PREPARE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
    : ((int32_T)0)) & ((rtu_sLastMasterLsadFsm->eLsadSystemSts !=
      LSAD_STS_HANDSHAKE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
      ((int32_T)0)) & ((rtu_sLastMasterLsadFsm->eLsadSystemSts != LSAD_STS_PP) ?
                       ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                 ((int32_T)0)) & ((rtu_sLastMasterLsadFsm->eLsadSystemSts !=
      LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
             ((int32_T)0)) & ((rtu_sLastMasterLsadFsm->eLsadSystemSts !=
              LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ?
         ((int32_T)1) : ((int32_T)0)) & ((rtu_sLastMasterLsadFsm->eLsadSystemSts
          != LSAD_STS_TERMINATED) ? ((int32_T)1) : ((int32_T)0)))))
  {
    pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_NONE;
  }
  else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      (((LSAD_PARK_IN == rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) :
        ((int32_T)0)) | ((LSAD_PARK_OUT == rtu_sLastSlaveLsadFsm->eLsadFuncType)
    ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
      ((LSAD_PARK_STRAIGHT == rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)
      1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) | ((LSAD_DRAG_PARK_IN
    == rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0)))))
  {
    bRPAPrepareAndCtrled = ((boolean_T)((int32_T)((((boolean_T)((int32_T)
      (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PREPARE) ? ((int32_T)
      1) : ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
      LSAD_STS_PREPARE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
      : ((int32_T)0)) & (k_RPAPhoneSearch ? ((int32_T)1) : ((int32_T)0))))) &
      (rtu_sPaStateAdptr->sCondiHMI.ePrkFnct == PARK_FUNC_RPA);
    if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
                 ((((boolean_T)((int32_T)
        (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ? ((int32_T)1)
          : ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                   ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
               : ((int32_T)0)) | (bRPAPrepareAndCtrled ? ((int32_T)1) :
               ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
          (rtu_sVehDataRx->sVehEPSInfo.bEpsInterf ? ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_STEER_INTERFERE;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)((((boolean_T)((int32_T)
        (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ? ((int32_T)1)
          : ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                    ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
      : ((int32_T)0)) & ((APA_CTRL_FAULT == rtu_sRelatedModuleInfo->eCtrlSts) ?
                         ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                ((int32_T)0)) & (((boolean_T)((int32_T)((((boolean_T)((int32_T)
        ((((boolean_T)((int32_T)((((boolean_T)((int32_T)
        (((rtu_sRelatedModuleInfo->eCtrlFailReason == CTRL_FAIL_LONG_STOP) ?
        ((int32_T)1) : ((int32_T)0)) | ((rtu_sRelatedModuleInfo->eCtrlFailReason
      == CTRL_FAIL_ROLL_BACK) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
      ((int32_T)0)) | ((rtu_sRelatedModuleInfo->eCtrlFailReason ==
                        CTRL_PLAN_FAIL_TRAP) ? ((int32_T)1) : ((int32_T)0))))) ?
          ((int32_T)1) : ((int32_T)0)) |
         ((rtu_sRelatedModuleInfo->eCtrlFailReason == CTRL_FINISH_CHOCK) ?
          ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
        ((rtu_sRelatedModuleInfo->eCtrlFailReason ==
          CTRL_PLAN_FINISH_STOP_NEAR_END) ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_CTRL_FAIL_REASON;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)((((boolean_T)((int32_T)
        (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ? ((int32_T)1)
          : ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                    ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
      : ((int32_T)0)) | (bRPAPrepareAndCtrled ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) &
               (rtu_sVehDataRx->sVehVCUInfo.bAccPedal ? ((int32_T)1) : ((int32_T)
                 0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_ACCEL_INTERFERE;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)((((boolean_T)((int32_T)
        (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ? ((int32_T)1)
          : ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                    ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
      : ((int32_T)0)) | (bRPAPrepareAndCtrled ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) &
               (rtu_sVehDataRx->sVehESCInfo.bDAActive ? ((int32_T)1) : ((int32_T)
                 0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_UXEXP_ADAS;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)((((boolean_T)((int32_T)
        (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ? ((int32_T)1)
          : ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                    ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
      : ((int32_T)0)) | (bRPAPrepareAndCtrled ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
                  ((rtu_sVehCommon->sCondiVeh.bTirePressNorm ? ((int32_T)1) :
                    ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_TIRE_PRESSURE_ABNORMAL;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
        (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ? ((int32_T)1)
      : ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
        ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                          LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0)))))
                    ? ((int32_T)1) : ((int32_T)0)) | (bRPAPrepareAndCtrled ?
        ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
        (rtu_sVehCommon->sCondiVeh.bEPBUnexp ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) &
               ((rtu_sRelatedModuleInfo->eHandshakeSts == HANDSHAKE_CONTROLLED) ?
                ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_UNEXP_EPB;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)((((boolean_T)((int32_T)
        (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ? ((int32_T)1)
          : ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                    ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
      : ((int32_T)0)) | (bRPAPrepareAndCtrled ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) &
               (rtu_sVehDataRx->sVehVCUInfo.bShftInterf ? ((int32_T)1) :
                ((int32_T)0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_GEAR_INTERFERE;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)((((boolean_T)((int32_T)
        (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ? ((int32_T)1)
          : ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                    ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
      : ((int32_T)0)) | (bRPAPrepareAndCtrled ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) &
               (rtu_sVehDataRx->sVehVCUInfo.bHVOff ? ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_HV_NOT_READY;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
        (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ? ((int32_T)1)
      : ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
        ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                          LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0)))))
                    ? ((int32_T)1) : ((int32_T)0)) | (bRPAPrepareAndCtrled ?
        ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
        ((rtu_sPaStateAdptr->sCondiHMI.ePrkFnct == PARK_FUNC_RPA) ? ((int32_T)1)
         : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
               (rtu_sPAHmiRx->sRPAHmiRx.bPhoneBatLow ? ((int32_T)1) : ((int32_T)
                 0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_RPA_LOW_BAT;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
        (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ? ((int32_T)1)
      : ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
        ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                          LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0)))))
                    ? ((int32_T)1) : ((int32_T)0)) | (bRPAPrepareAndCtrled ?
        ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
        ((rtu_sPaStateAdptr->sCondiHMI.ePrkFnct == PARK_FUNC_RPA) ? ((int32_T)1)
         : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
               ((rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkWakeup != SWT_ON) ? ((int32_T)1)
                : ((int32_T)0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_RPA_CONN_LOSS;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
        (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ? ((int32_T)1)
      : ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
        ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                          LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0)))))
                    ? ((int32_T)1) : ((int32_T)0)) | (bRPAPrepareAndCtrled ?
        ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
        ((rtu_sPaStateAdptr->sCondiHMI.ePrkFnct == PARK_FUNC_RPA) ? ((int32_T)1)
         : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)
                 ((int32_T)((rtu_sPaStateAdptr->sCondiHMI.bBLEScrt ? ((int32_T)1)
      : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_RPA_CONN_UNSAFE;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
        (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ? ((int32_T)1)
      : ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
        ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                          LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0)))))
                    ? ((int32_T)1) : ((int32_T)0)) | (bRPAPrepareAndCtrled ?
        ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
        ((rtu_sPaStateAdptr->sCondiHMI.ePrkFnct == PARK_FUNC_RPA) ? ((int32_T)1)
         : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
               ((rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkWorkMd == PRK_WORK_EXIT) ?
                ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_RPA_BACK;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)((((boolean_T)((int32_T)
        (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ? ((int32_T)1)
          : ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                    ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
      : ((int32_T)0)) | (bRPAPrepareAndCtrled ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) &
               (rtu_sVehCommon->sCondiVeh.bPrkOverSlope ? ((int32_T)1) :
                ((int32_T)0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_SLOPE_OVERLIMIT;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)((((boolean_T)((int32_T)
        (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ? ((int32_T)1)
          : ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                    ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
      : ((int32_T)0)) | (bRPAPrepareAndCtrled ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) &
               (rtu_sVehDataRx->sVehESCInfo.bASActive ? ((int32_T)1) : ((int32_T)
                 0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_UNEXP_AS;
    }
    else if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                 LSAD_STS_PP) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)
                 ((int32_T)((((boolean_T)((int32_T)
        (((pa_state_common_DW.UnitDelay1_DSTATE >= k_PPDuratTime) ? ((int32_T)1)
          : ((int32_T)0)) | ((APA_PATH_PLAN_FAILED ==
        rtu_sRelatedModuleInfo->ePathPlanSts) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0)) | ((APA_PATH_PLAN_PRE_FAILED ==
        rtu_sRelatedModuleInfo->ePathPlanSts) ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_PATH_PLAN_FAIL;
    }
    else if ((boolean_T)((int32_T)((bRPAPrepareAndCtrled ? ((int32_T)1) :
                ((int32_T)0)) &
               (rtu_sPaStateAdptr->sCondiOverFlagAdptr.bPISrchOvertime ?
                ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_RPA_SEARCH_OVERTIME;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                     LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0)) | (bRPAPrepareAndCtrled ? ((int32_T)1) :
        ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
               (rtu_sVehDataRx->sVehVCUInfo.bUnExpGear ? ((int32_T)1) :
                ((int32_T)0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_UNEXP_GEAR;

      /*          elseif(eAPAInternalSts == tLSAD_FuncSts.FUNC_STS_RPA_PI_CONFIRM && k_RPAPhoneSearch)&&... */
      /*                 ~bVehStill */
      /*              ePATrmntEvnt = tTrmntEvnt.TERMINATE_VEH_MOVE; */
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                  (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                     LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) &
               ((pa_state_common_DW.UnitDelay1_DSTATE_a >= k_ManeuverDuratTime) ?
                ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_MANVR_OVERTIME;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                  (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0)) | (bRPAPrepareAndCtrled ?
        ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
               ((rtu_sVehDataRx->sVehESCInfo.f32VehSpdKph > k_ManeuveringMaxSpd)
                ? ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_MANVR_OVERSPEED;
    }
    else if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                 LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0)) &
               ((pa_state_common_DW.UnitDelay1_DSTATE_gk > ((uint16_T)
                  k_ManeuverMaxMoveStep)) ? ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_MANVR_OVERFLOW;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                  (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0)) | (bRPAPrepareAndCtrled ?
        ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
               (rtu_sVehCommon->sCondiVeh.bDrvBlock ? ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_VEH_BLOCK;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                  (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0)) | (bRPAPrepareAndCtrled ?
        ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
               (rtu_sVehCommon->sCondiVeh.bVehSlip ? ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_VEH_SLIP;
    }
    else if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                 LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0)) &
               ((pa_state_common_DW.UnitDelay1_DSTATE_j >= k_RcvItrptDuratTime) ?
                ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_INTERRUPT_OVERTIME;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                  (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                     LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) &
               ((pa_state_common_DW.UnitDelay1_DSTATE_f >= ((uint16_T)
                  k_RcvItrpt_MaxTime)) ? ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_INTERRUPT_OVERFLOW;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
      | ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE_SUSPEND) ?
         ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
               (((boolean_T)((int32_T)((((boolean_T)((int32_T)
        (((rtu_sPaStateAdptr->sCondiHMI.ePrkFnct == PARK_FUNC_APA) ? ((int32_T)1)
          : ((int32_T)0)) & ((rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkWorkMd ==
        PRK_WORK_EXIT) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
        ((int32_T)0)) | (((boolean_T)((int32_T)
        (((rtu_sPaStateAdptr->sCondiHMI.ePrkFnct == PARK_FUNC_RPA) ? ((int32_T)1)
          : ((int32_T)0)) & ((rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkWorkMd ==
        PRK_WORK_EXIT) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                         ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_MANUAL_DEACT;

      /*  elseif(eLsadSystemSts == tLSAD_SystemSts.LSAD_STS_ACTIVE &&... */
      /*         bMirrFld)   %%É¾µôÒ»¸öRPAµÄÌõ¼þ */
      /*  	ePATrmntEvnt = tTrmntEvnt.TERMINATE_MIRROR_FOLD;  %%»áÓë»úÐµ¿âÎ»³åÍ» */
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)((((boolean_T)((int32_T)
        (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ? ((int32_T)1)
          : ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                    ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
      : ((int32_T)0)) | (bRPAPrepareAndCtrled ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
                  ((((boolean_T)((int32_T)((((boolean_T)((int32_T)
        (((rtu_sRelatedModuleInfo->eHandshakeSts == HANDSHAKE_FAIL) ? ((int32_T)
        1) : ((int32_T)0)) & ((rtu_sRelatedModuleInfo->eHandshakeFailReason !=
        NO_FAILCODE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
        ((int32_T)0)) & ((rtu_sRelatedModuleInfo->eHandshakeFailReason !=
                          PA_FAIL) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
        1) : ((int32_T)0)) | (rtu_sVehCommon->sCondiVeh.bESCPulFail ? ((int32_T)
        1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_EXTERNAL_FAIL;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)((((boolean_T)((int32_T)
        (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ? ((int32_T)1)
          : ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                    ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
        LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
      : ((int32_T)0)) | (bRPAPrepareAndCtrled ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) & (rtu_sDiagInfo->bPASysFail ?
                ((int32_T)1) : ((int32_T)0)))))
    {
      if ((boolean_T)((int32_T)((rtu_sDiagInfo->sComFail.bComFail ? ((int32_T)1)
             : ((int32_T)0)) & (((boolean_T)((int32_T)
               ((rtu_sDiagInfo->sComFail.bEthFail ? ((int32_T)1) : ((int32_T)0))
                ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
      {
        pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_INVALID_SIGNAL;
      }
      else if (rtu_sDiagInfo->sUssFail.bUssFail)
      {
        pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_USS_FAIL;
      }
      else if (rtu_sDiagInfo->sVisionFail.bVisionFail)
      {
        pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_VISION_FAIL;
      }
      else
      {
        pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_INTERNAL_FAIL;
      }
    }
    else
    {
      /* no actions */
    }
  }
  else
  {
    pa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_NONE;

    /* ·ÇPI PO PStraight×´Ì¬ÏÂ */
  }

  /* End of MATLAB Function: '<S2>/PATrmntEvntDet' */

  /* MATLAB Function: '<S2>/PAInhibitEvntDet' incorporates:
   *  RelationalOperator: '<S10>/Equal3'
   */
  if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
          LSAD_STS_INHIBIT) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)
          ((int32_T)(((rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkWakeup == SWT_ON) ?
                      ((int32_T)1) : ((int32_T)0)) |
                     ((rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkWakeup == SWT_ON) ?
                      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)
          0)))))
  {
    if ((boolean_T)((int32_T)((rtu_sVehCommon->sCondiVeh.bExterActualNorm ?
           ((int32_T)1) : ((int32_T)0)) ^ 1)))
    {
      rty_sPaStateCommon->sPAEvnt.ePAInhibitEvnt = INHIBIT_EXTERNAL_FAIL;
    }
    else if (rtu_sVehDataRx->sVehESCInfo.f32VehSpdKph > k_PrkInSrchMaxSpd)
    {
      rty_sPaStateCommon->sPAEvnt.ePAInhibitEvnt = INHIBIT_SEARCH_OVERSPEED;
    }
    else if ((boolean_T)((int32_T)((rtu_sVehCommon->sCondiVeh.bTirePressNorm ?
                ((int32_T)1) : ((int32_T)0)) ^ 1)))
    {
      rty_sPaStateCommon->sPAEvnt.ePAInhibitEvnt =
        INHIBIT_TIRE_PRESSURE_ABNORMAL;
    }
    else if (rtu_sVehDataRx->sVehESCInfo.bDAActive)
    {
      rty_sPaStateCommon->sPAEvnt.ePAInhibitEvnt = INHIBIT_ACTIVE_DA;
    }
    else if (rtu_sVehDataRx->sVehVCUInfo.bHVOff)
    {
      rty_sPaStateCommon->sPAEvnt.ePAInhibitEvnt = INHIBIT_HV_NOT_READY;
    }
    else
    {
      rty_sPaStateCommon->sPAEvnt.ePAInhibitEvnt = INHIBIT_NONE;
    }
  }
  else
  {
    rty_sPaStateCommon->sPAEvnt.ePAInhibitEvnt = INHIBIT_NONE;
  }

  /* End of MATLAB Function: '<S2>/PAInhibitEvntDet' */

  /* MATLAB Function: '<S2>/PAFailureEvntDet' incorporates:
   *  RelationalOperator: '<S10>/Equal3'
   */
  if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
          LSAD_STS_FAILURE) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)
          ((int32_T)(((rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkWakeup == SWT_ON) ?
                      ((int32_T)1) : ((int32_T)0)) |
                     ((rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkWakeup == SWT_ON) ?
                      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)
          0)))))
  {
    if (rtu_sDiagInfo->sUssFail.bUssFail)
    {
      rty_sPaStateCommon->sPAEvnt.ePAFailureEvnt = FAILURE_USS_FAIL;
    }
    else if (rtu_sDiagInfo->sVisionFail.bVisionFail)
    {
      rty_sPaStateCommon->sPAEvnt.ePAFailureEvnt = FAILURE_VISION_FAIL;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                  ((rtu_sDiagInfo->sVisionFail.bVisionFail ? ((int32_T)1) :
                    ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)) &
               (((boolean_T)((int32_T)((rtu_sDiagInfo->sUssFail.bUssFail ?
        ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
    {
      rty_sPaStateCommon->sPAEvnt.ePAFailureEvnt = FAILURE_INTERNAL_FAIL;
    }
    else
    {
      rty_sPaStateCommon->sPAEvnt.ePAFailureEvnt = FAILURE_NONE;
    }
  }
  else
  {
    rty_sPaStateCommon->sPAEvnt.ePAFailureEvnt = FAILURE_NONE;
  }

  /* End of MATLAB Function: '<S2>/PAFailureEvntDet' */

  /* BusCreator: '<S2>/Bus Creator' incorporates:
   *  UnitDelay: '<S2>/Unit Delay7'
   *  UnitDelay: '<S2>/Unit Delay9'
   */
  rty_sPaStateCommon->sPAEvnt.ePATrmntEvnt =
    pa_state_common_DW.UnitDelay7_DSTATE;
  rty_sPaStateCommon->sPAEvnt.ePAIntrptType =
    pa_state_common_DW.UnitDelay9_DSTATE;

  /* Update for UnitDelay: '<S8>/Unit Delay' */
  pa_state_common_DW.UnitDelay_DSTATE = rtu_sLastMasterLsadFsm->eLsadSystemSts;

  /* Update for UnitDelay: '<S12>/Unit Delay1' */
  pa_state_common_DW.UnitDelay1_DSTATE_gl =
    rtu_sVehDataRx->sVehVCUInfo.eVehActualGear;

  /* Update for UnitDelay: '<S12>/Unit Delay3' */
  pa_state_common_DW.UnitDelay3_DSTATE =
    rtu_sVehDataRx->sVehVCUInfo.eVehActualGear;
}

/* Model initialize function */
void pa_state_common_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)&pa_state_common_DW, 0,
                sizeof(DW_pa_state_common_f_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
