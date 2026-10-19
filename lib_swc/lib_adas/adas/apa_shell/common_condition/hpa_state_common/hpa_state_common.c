/*
 * File: hpa_state_common.c
 *
 * Code generated for Simulink model 'hpa_state_common'.
 *
 * Model version                  : 3.2821
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Dec  2 15:52:46 2024
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

#include "hpa_state_common.h"

/* Block states (default storage) */
#define CtrlPara_START_SEC_VAR
#include "proj_MemMap.h"
DW_hpa_state_common_f_T hpa_state_common_DW;
#define CtrlPara_STOP_SEC_VAR
#include "proj_MemMap.h"
/* Output and update for referenced model: 'hpa_state_common' */
void hpa_state_common(const tVehCommon *rtu_sVehCommon, const tHPAHmiRx
                      *rtu_sHPAHmiRx, const tVehDataRx *rtu_sVehDataRx, const
                      tRelatedModuleInfo *rtu_sRelatedModuleInfo, const
                      tDiagInfo *rtu_sDiagInfo, const tMasterLsadFsm
                      *rtu_sLastMasterLsadFsm, const tSlaveLsadFsm
                      *rtu_sLastSlaveLsadFsm, tHpaStateCommon
                      *rty_sHpaStateCommon)
{
  tHPACondiOverFlag LocalVar_sHPACondiOverFlag;
  tInhibitEvnt LocalVar_eHPAInhibitEvnt;
  tIntrptEvnt LocalVar_eHPAIntrptEvnt;

  /* Switch: '<S30>/Switch1' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S29>/Constant'
   *  Constant: '<S30>/Constant Value2'
   *  Logic: '<S8>/Logical Operator2'
   *  Logic: '<S8>/OR1'
   *  RelationalOperator: '<S8>/Equal1'
   *  RelationalOperator: '<S8>/Equal3'
   *  Switch: '<S30>/Switch'
   *  UnitDelay: '<S30>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts !=
          LSAD_STS_PP) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
           (((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_CRUISE) ? ((int32_T)1)
             : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
  {
    hpa_state_common_DW.UnitDelay1_DSTATE = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S30>/Unit Delay1' incorporates:
     *  Constant: '<S8>/Constant3'
     *  Sum: '<S30>/Subtraction'
     */
    hpa_state_common_DW.UnitDelay1_DSTATE += s_APPManLoopSec;
  }

  /* End of Switch: '<S30>/Switch1' */

  /* Switch: '<S20>/Switch1' incorporates:
   *  Constant: '<S18>/Constant'
   *  Constant: '<S19>/Constant'
   *  Constant: '<S20>/Constant Value2'
   *  Logic: '<S5>/Logical Operator3'
   *  Logic: '<S5>/OR1'
   *  RelationalOperator: '<S5>/Equal1'
   *  RelationalOperator: '<S5>/Equal6'
   *  RelationalOperator: '<S8>/Equal3'
   *  Switch: '<S20>/Switch'
   *  UnitDelay: '<S20>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts !=
          LSAD_STS_HANDSHAKE) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)
          ((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_CRUISE) ?
                      ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) :
         ((int32_T)0)))))
  {
    hpa_state_common_DW.UnitDelay1_DSTATE_f = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S20>/Unit Delay1' incorporates:
     *  Constant: '<S5>/Constant5'
     *  Sum: '<S20>/Subtraction'
     */
    hpa_state_common_DW.UnitDelay1_DSTATE_f += s_APPManLoopSec;
  }

  /* End of Switch: '<S20>/Switch1' */

  /* Switch: '<S27>/Switch1' incorporates:
   *  Constant: '<S24>/Constant'
   *  Constant: '<S25>/Constant'
   *  Constant: '<S26>/Constant'
   *  Constant: '<S27>/Constant Value2'
   *  Logic: '<S7>/Logical Operator'
   *  Logic: '<S7>/Logical Operator8'
   *  Logic: '<S7>/OR1'
   *  RelationalOperator: '<S7>/Equal'
   *  RelationalOperator: '<S7>/Equal1'
   *  RelationalOperator: '<S7>/Equal2'
   *  RelationalOperator: '<S8>/Equal3'
   *  Switch: '<S27>/Switch'
   *  UnitDelay: '<S27>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
           (((rtu_sLastMasterLsadFsm->eLsadSystemSts != LSAD_STS_ACTIVE_SUSPEND)
             ? ((int32_T)1) : ((int32_T)0)) &
            ((rtu_sLastMasterLsadFsm->eLsadSystemSts != LSAD_STS_ACTIVE) ?
             ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
        (((boolean_T)((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncType ==
              LSAD_CRUISE) ? ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) :
         ((int32_T)0)))))
  {
    hpa_state_common_DW.UnitDelay1_DSTATE_n = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S27>/Unit Delay1' incorporates:
     *  Constant: '<S7>/Constant15'
     *  Sum: '<S27>/Subtraction'
     */
    hpa_state_common_DW.UnitDelay1_DSTATE_n += s_APPManLoopSec;
  }

  /* End of Switch: '<S27>/Switch1' */

  /* Switch: '<S23>/Switch1' incorporates:
   *  Constant: '<S21>/Constant'
   *  Constant: '<S22>/Constant'
   *  Constant: '<S23>/Constant Value2'
   *  Logic: '<S6>/Logical Operator4'
   *  Logic: '<S6>/OR1'
   *  RelationalOperator: '<S6>/Equal1'
   *  RelationalOperator: '<S6>/Equal20'
   *  RelationalOperator: '<S8>/Equal3'
   *  Switch: '<S23>/Switch'
   *  UnitDelay: '<S23>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts !=
          LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)
          ((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_CRUISE) ?
                      ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) :
         ((int32_T)0)))))
  {
    hpa_state_common_DW.UnitDelay1_DSTATE_e = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S23>/Unit Delay1' incorporates:
     *  Constant: '<S6>/Constant8'
     *  Sum: '<S23>/Subtraction'
     */
    hpa_state_common_DW.UnitDelay1_DSTATE_e += s_APPManLoopSec;
  }

  /* End of Switch: '<S23>/Switch1' */

  /* Switch: '<S14>/Switch1' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S13>/Constant'
   *  Constant: '<S14>/Constant Value2'
   *  Constant: '<S17>/Constant Value2'
   *  Logic: '<S3>/Logical Operator5'
   *  Logic: '<S3>/OR1'
   *  RelationalOperator: '<S3>/Equal1'
   *  RelationalOperator: '<S3>/Equal20'
   *  RelationalOperator: '<S8>/Equal3'
   *  Switch: '<S14>/Switch'
   *  Switch: '<S17>/Switch'
   *  Switch: '<S17>/Switch1'
   *  UnitDelay: '<S14>/Unit Delay1'
   *  UnitDelay: '<S17>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts !=
          LSAD_STS_COMPLETE) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)
          ((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_CRUISE) ?
                      ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) :
         ((int32_T)0)))))
  {
    hpa_state_common_DW.UnitDelay1_DSTATE_i = 0.0F;
    hpa_state_common_DW.UnitDelay1_DSTATE_l = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S14>/Unit Delay1' incorporates:
     *  Constant: '<S3>/Constant10'
     *  Sum: '<S14>/Subtraction'
     */
    hpa_state_common_DW.UnitDelay1_DSTATE_i += s_APPManLoopSec;

    /* UnitDelay: '<S17>/Unit Delay1' incorporates:
     *  Constant: '<S4>/Constant10'
     *  Sum: '<S17>/Subtraction'
     */
    hpa_state_common_DW.UnitDelay1_DSTATE_l += s_APPManLoopSec;
  }

  /* End of Switch: '<S14>/Switch1' */

  /* Switch: '<S33>/Switch1' incorporates:
   *  Constant: '<S31>/Constant'
   *  Constant: '<S32>/Constant'
   *  Constant: '<S33>/Constant Value2'
   *  Logic: '<S9>/Logical Operator6'
   *  Logic: '<S9>/OR1'
   *  RelationalOperator: '<S8>/Equal3'
   *  RelationalOperator: '<S9>/Equal1'
   *  RelationalOperator: '<S9>/Equal20'
   *  Switch: '<S33>/Switch'
   *  UnitDelay: '<S33>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts !=
          LSAD_STS_QUIT) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
           (((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_CRUISE) ? ((int32_T)1)
             : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
  {
    hpa_state_common_DW.UnitDelay1_DSTATE_p = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S33>/Unit Delay1' incorporates:
     *  Constant: '<S9>/Constant11'
     *  Sum: '<S33>/Subtraction'
     */
    hpa_state_common_DW.UnitDelay1_DSTATE_p += s_APPManLoopSec;
  }

  /* End of Switch: '<S33>/Switch1' */

  /* Switch: '<S36>/Switch1' incorporates:
   *  Constant: '<S34>/Constant'
   *  Constant: '<S35>/Constant'
   *  Constant: '<S36>/Constant Value2'
   *  Constant: '<S39>/Constant Value2'
   *  Logic: '<S10>/Logical Operator7'
   *  Logic: '<S10>/OR1'
   *  RelationalOperator: '<S10>/Equal1'
   *  RelationalOperator: '<S10>/Equal20'
   *  RelationalOperator: '<S8>/Equal3'
   *  Switch: '<S36>/Switch'
   *  Switch: '<S39>/Switch'
   *  Switch: '<S39>/Switch1'
   *  UnitDelay: '<S36>/Unit Delay1'
   *  UnitDelay: '<S39>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts !=
          LSAD_STS_TERMINATED) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)
          ((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_CRUISE) ?
                      ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) :
         ((int32_T)0)))))
  {
    hpa_state_common_DW.UnitDelay1_DSTATE_b = 0.0F;
    hpa_state_common_DW.UnitDelay1_DSTATE_i3 = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S36>/Unit Delay1' incorporates:
     *  Constant: '<S10>/Constant13'
     *  Sum: '<S36>/Subtraction'
     */
    hpa_state_common_DW.UnitDelay1_DSTATE_b += s_APPManLoopSec;

    /* UnitDelay: '<S39>/Unit Delay1' incorporates:
     *  Constant: '<S11>/Constant13'
     *  Sum: '<S39>/Subtraction'
     */
    hpa_state_common_DW.UnitDelay1_DSTATE_i3 += s_APPManLoopSec;
  }

  /* End of Switch: '<S36>/Switch1' */

  /* BusAssignment: '<S1>/Bus Assignment' incorporates:
   *  Constant: '<S10>/Constant14'
   *  Constant: '<S11>/Constant14'
   *  Constant: '<S3>/Constant9'
   *  Constant: '<S4>/Constant9'
   *  Constant: '<S5>/Constant4'
   *  Constant: '<S9>/Constant12'
   *  RelationalOperator: '<S10>/Equal14'
   *  RelationalOperator: '<S11>/Equal14'
   *  RelationalOperator: '<S3>/Equal9'
   *  RelationalOperator: '<S4>/Equal9'
   *  RelationalOperator: '<S5>/Equal5'
   *  RelationalOperator: '<S6>/Equal7'
   *  RelationalOperator: '<S7>/Equal16'
   *  RelationalOperator: '<S8>/Equal2'
   *  RelationalOperator: '<S9>/Equal12'
   *  UnitDelay: '<S14>/Unit Delay1'
   *  UnitDelay: '<S17>/Unit Delay1'
   *  UnitDelay: '<S20>/Unit Delay1'
   *  UnitDelay: '<S23>/Unit Delay1'
   *  UnitDelay: '<S27>/Unit Delay1'
   *  UnitDelay: '<S30>/Unit Delay1'
   *  UnitDelay: '<S33>/Unit Delay1'
   *  UnitDelay: '<S36>/Unit Delay1'
   *  UnitDelay: '<S39>/Unit Delay1'
   */
  (void)memset(&LocalVar_sHPACondiOverFlag, 0, sizeof(tHPACondiOverFlag));
  LocalVar_sHPACondiOverFlag.bHpaPPOvertime =
    (hpa_state_common_DW.UnitDelay1_DSTATE >= 10.0F);
  LocalVar_sHPACondiOverFlag.bHpaHandshakOvertime =
    (hpa_state_common_DW.UnitDelay1_DSTATE_f >= k_HandDuratTime);
  LocalVar_sHPACondiOverFlag.bHpaActiveOvertime =
    (hpa_state_common_DW.UnitDelay1_DSTATE_n >= 1800.0F);
  LocalVar_sHPACondiOverFlag.bHpaIntrptOvertime =
    (hpa_state_common_DW.UnitDelay1_DSTATE_e >= 600.0F);
  LocalVar_sHPACondiOverFlag.bHpaCmpltDurattime =
    (hpa_state_common_DW.UnitDelay1_DSTATE_i >= k_CmpltDuratTime);
  LocalVar_sHPACondiOverFlag.bHpaCmpltOvertime =
    (hpa_state_common_DW.UnitDelay1_DSTATE_l >= 4.0F);
  LocalVar_sHPACondiOverFlag.bHpaQuitDurattime =
    (hpa_state_common_DW.UnitDelay1_DSTATE_p >= k_QuitDuratTime);
  LocalVar_sHPACondiOverFlag.bHpaTrmntDurattime =
    (hpa_state_common_DW.UnitDelay1_DSTATE_b >= k_TmntDuratTime);
  LocalVar_sHPACondiOverFlag.bHpaTrmntOvertime =
    (hpa_state_common_DW.UnitDelay1_DSTATE_i3 >= 4.0F);

  /* MATLAB Function: '<S2>/HPAQuitEvntDet' incorporates:
   *  Constant: '<S5>/Constant4'
   *  RelationalOperator: '<S5>/Equal5'
   *  RelationalOperator: '<S8>/Equal3'
   *  UnitDelay: '<S20>/Unit Delay1'
   *  UnitDelay: '<S2>/Unit Delay8'
   */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
               ((((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts
    == LSAD_STS_PREPARE) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PREPARE_SUSPEND) ?
       ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
                ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_HANDSHAKE) ?
                 ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
            & ((rtu_sHPAHmiRx->eHPAPrkWorkMd == PRK_WORK_EXIT) ? ((int32_T)1) :
               ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
        ((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_CRUISE) ? ((int32_T)1) :
         ((int32_T)0)))))
  {
    hpa_state_common_DW.UnitDelay8_DSTATE = QUIT_MANUAL_DEACTIVATE;
  }
  else if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
               LSAD_STS_HANDSHAKE) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)
               ((int32_T)((((boolean_T)((int32_T)
      (((rtu_sRelatedModuleInfo->eHandshakeSts == HANDSHAKE_FAIL) ? ((int32_T)1)
        : ((int32_T)0)) & ((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_CRUISE)
    ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
                          ((hpa_state_common_DW.UnitDelay1_DSTATE_f >=
      k_HandDuratTime) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
              ((int32_T)0)))))
  {
    /*   //ÕâÀïÏÈÖ»ÄÃÁËhppÍË³öÊ§°ÜµÄ */
    hpa_state_common_DW.UnitDelay8_DSTATE = QUIT_HANDSHAKE_FAIL;

    /* %%%%% */
  }
  else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
      LSAD_STS_PREPARE) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PREPARE_SUSPEND) ?
       ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
       ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_HANDSHAKE) ?
        ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
      ((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_CRUISE) ? ((int32_T)1) :
       ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
             (rtu_sDiagInfo->bPASysFail ? ((int32_T)1) : ((int32_T)0)))))
  {
    if ((boolean_T)((int32_T)((rtu_sDiagInfo->sComFail.bComFail ? ((int32_T)1) :
           ((int32_T)0)) & (((boolean_T)((int32_T)
             ((rtu_sDiagInfo->sComFail.bEthFail ? ((int32_T)1) : ((int32_T)0)) ^
              1))) ? ((int32_T)1) : ((int32_T)0)))))
    {
      hpa_state_common_DW.UnitDelay8_DSTATE = QUIT_INVALID_SIGNAL;
    }
    else if (rtu_sDiagInfo->sUssFail.bUssFail)
    {
      hpa_state_common_DW.UnitDelay8_DSTATE = QUIT_USS_FAIL;
    }
    else if (rtu_sDiagInfo->sVisionFail.bVisionFail)
    {
      hpa_state_common_DW.UnitDelay8_DSTATE = QUIT_VISION_FAIL;
    }
    else
    {
      hpa_state_common_DW.UnitDelay8_DSTATE = QUIT_INTERNAL_FAIL;
    }
  }
  else if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
               LSAD_STS_STANDBY) ? ((int32_T)1) : ((int32_T)0)) |
             ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_OFF) ?
              ((int32_T)1) : ((int32_T)0)))))
  {
    hpa_state_common_DW.UnitDelay8_DSTATE = QUIT_NONE;
  }
  else
  {
    /* no actions */
  }

  /* End of MATLAB Function: '<S2>/HPAQuitEvntDet' */

  /* MATLAB Function: '<S2>/HPAIntrptEvntDet' incorporates:
   *  RelationalOperator: '<S8>/Equal3'
   *  UnitDelay: '<S2>/Unit Delay9'
   */
  if (rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_CRUISE)
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
        LocalVar_eHPAIntrptEvnt = INTERRUPT_DOOR_OPEN;
        hpa_state_common_DW.UnitDelay9_DSTATE = INTERRUPTION_NEED_CONFIRM;
      }
      else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                    ((rtu_sVehCommon->sCondiDoorSblt.bSeatbltAct ? ((int32_T)1) :
                      ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)) &
                 (k_bIntrptEvntSeatblt ? ((int32_T)1) : ((int32_T)0)))))
      {
        LocalVar_eHPAIntrptEvnt = INTERRUPT_SEATBELT_UNBUCKLED;
        hpa_state_common_DW.UnitDelay9_DSTATE = INTERRUPTION_NEED_CONFIRM;
      }
      else if ((boolean_T)((int32_T)
                           ((rtu_sVehCommon->sCondiDoorSblt.bTailGateClose ?
                             ((int32_T)1) : ((int32_T)0)) ^ 1)))
      {
        LocalVar_eHPAIntrptEvnt = INTERRUPT_TRUNK_OPEN;
        hpa_state_common_DW.UnitDelay9_DSTATE = INTERRUPTION_NEED_CONFIRM;
      }
      else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
          ((int32_T)((rtu_sVehCommon->sCondiPlatform.bActvStsNeedRlsBrk ?
                      ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) :
          ((int32_T)0)) & (rtu_sVehDataRx->sVehVCUInfo.bBrkPedal ? ((int32_T)1) :
                           ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
                 (k_bIntrptEvntBrkPdl ? ((int32_T)1) : ((int32_T)0)))))
      {
        LocalVar_eHPAIntrptEvnt = INTERRUPT_MANUAL_BRAKE;
        hpa_state_common_DW.UnitDelay9_DSTATE = INTERRUPTION_NO_CONFIRM;
      }
      else if (rtu_sHPAHmiRx->eHPAPrkWorkMd == PRK_WORK_PAUSE)
      {
        LocalVar_eHPAIntrptEvnt = INTERRUPT_MANUAL_PAUSE;
        hpa_state_common_DW.UnitDelay9_DSTATE = INTERRUPTION_NEED_CONFIRM;
      }
      else if (rtu_sVehCommon->sCondiPlatform.bObstAppear)
      {
        LocalVar_eHPAIntrptEvnt = INTERRUPT_OBSTACLE;
        hpa_state_common_DW.UnitDelay9_DSTATE = INTERRUPTION_NEED_CONFIRM;
      }
      else
      {
        LocalVar_eHPAIntrptEvnt = INTERRUPT_NONE;
      }
    }
    else
    {
      LocalVar_eHPAIntrptEvnt = INTERRUPT_NONE;
    }
  }
  else
  {
    LocalVar_eHPAIntrptEvnt = INTERRUPT_NONE;
    hpa_state_common_DW.UnitDelay9_DSTATE = INTERRUTPION_NONE;
  }

  /* End of MATLAB Function: '<S2>/HPAIntrptEvntDet' */

  /* MATLAB Function: '<S2>/PATrmntEvntDet' incorporates:
   *  RelationalOperator: '<S6>/Equal7'
   *  RelationalOperator: '<S7>/Equal16'
   *  RelationalOperator: '<S8>/Equal2'
   *  RelationalOperator: '<S8>/Equal3'
   *  UnitDelay: '<S23>/Unit Delay1'
   *  UnitDelay: '<S27>/Unit Delay1'
   *  UnitDelay: '<S2>/Unit Delay7'
   *  UnitDelay: '<S30>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
          LSAD_STS_STANDBY) ? ((int32_T)1) : ((int32_T)0)) |
        ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_OFF) ? ((int32_T)1)
         : ((int32_T)0)))))
  {
    hpa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_NONE;
  }
  else if (rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_CRUISE)
  {
    if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
                 (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ?
                   ((int32_T)1) : ((int32_T)0)) |
                  ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                   ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
              | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                  LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ?
           ((int32_T)1) : ((int32_T)0)) &
          (rtu_sVehDataRx->sVehEPSInfo.bEpsInterf ? ((int32_T)1) : ((int32_T)0)))))
    {
      hpa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_STEER_INTERFERE;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
      | ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE_SUSPEND) ?
         ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
               ((rtu_sRelatedModuleInfo->eCtrlSts == APA_CTRL_FAULT) ? ((int32_T)
                 1) : ((int32_T)0)))))
    {
      hpa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_NO_PATH;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
      | ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE_SUSPEND) ?
         ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
               (rtu_sVehDataRx->sVehVCUInfo.bAccPedal ? ((int32_T)1) : ((int32_T)
                 0)))))
    {
      hpa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_ACCEL_INTERFERE;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
      | ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE_SUSPEND) ?
         ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
               (rtu_sVehDataRx->sVehVCUInfo.bShftInterf ? ((int32_T)1) :
                ((int32_T)0)))))
    {
      hpa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_GEAR_INTERFERE;
    }
    else if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                 LSAD_STS_PP) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)
                 ((int32_T)((((boolean_T)((int32_T)
        (((hpa_state_common_DW.UnitDelay1_DSTATE >= 10.0F) ? ((int32_T)1) :
          ((int32_T)0)) | ((APA_PATH_PLAN_FAILED ==
                            rtu_sRelatedModuleInfo->ePathPlanSts) ? ((int32_T)1)
      : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
                            ((APA_PATH_PLAN_PRE_FAILED ==
        rtu_sRelatedModuleInfo->ePathPlanSts) ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)))))
    {
      hpa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_PATH_PLAN_FAIL;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                  (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                     LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) &
               ((hpa_state_common_DW.UnitDelay1_DSTATE_n >= 1800.0F) ? ((int32_T)
                 1) : ((int32_T)0)))))
    {
      hpa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_MANVR_OVERTIME;

      /*  elseif(eLsadSystemSts == tLSAD_SystemSts.LSAD_STS_ACTIVE)&&... */
      /*        (bManeuverOverSpd) */
      /*  	eHPATrmntEvnt = tTrmntEvnt.TERMINATE_MANVR_OVERSPEED; */
    }
    else if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                 LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0)) &
               ((hpa_state_common_DW.UnitDelay1_DSTATE_e >= 600.0F) ? ((int32_T)
                 1) : ((int32_T)0)))))
    {
      hpa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_INTERRUPT_OVERTIME;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                  (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                     LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) &
               (LocalVar_sHPACondiOverFlag.bHpaIntrptOverflow ? ((int32_T)1) :
                ((int32_T)0)))))
    {
      hpa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_INTERRUPT_OVERFLOW;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
      | ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE_SUSPEND) ?
         ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
               ((rtu_sHPAHmiRx->eHPAPrkWorkMd == PRK_WORK_EXIT) ? ((int32_T)1) :
                ((int32_T)0)))))
    {
      hpa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_MANUAL_DEACT;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
      | ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE_SUSPEND) ?
         ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
               ((rtu_sRelatedModuleInfo->eHandshakeSts == HANDSHAKE_FAIL) ?
                ((int32_T)1) : ((int32_T)0)))))
    {
      hpa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_EXTERNAL_FAIL;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
      | ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE_SUSPEND) ?
         ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
               (rtu_sDiagInfo->bPASysFail ? ((int32_T)1) : ((int32_T)0)))))
    {
      if ((boolean_T)((int32_T)((rtu_sDiagInfo->sComFail.bComFail ? ((int32_T)1)
             : ((int32_T)0)) & (((boolean_T)((int32_T)
               ((rtu_sDiagInfo->sComFail.bEthFail ? ((int32_T)1) : ((int32_T)0))
                ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
      {
        hpa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_INVALID_SIGNAL;
      }
      else if (rtu_sDiagInfo->sUssFail.bUssFail)
      {
        hpa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_USS_FAIL;
      }
      else if (rtu_sDiagInfo->sVisionFail.bVisionFail)
      {
        hpa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_VISION_FAIL;
      }
      else
      {
        hpa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_INTERNAL_FAIL;
      }
    }
    else
    {
      /* no actions */
    }
  }
  else
  {
    hpa_state_common_DW.UnitDelay7_DSTATE = TERMINATE_NONE;
  }

  /* End of MATLAB Function: '<S2>/PATrmntEvntDet' */

  /* MATLAB Function: '<S2>/HPAInhibitEvntDet' incorporates:
   *  RelationalOperator: '<S8>/Equal3'
   */
  if (rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_INHIBIT)
  {
    if ((boolean_T)((int32_T)((rtu_sVehCommon->sCondiVeh.bExterActualNorm ?
           ((int32_T)1) : ((int32_T)0)) ^ 1)))
    {
      LocalVar_eHPAInhibitEvnt = INHIBIT_EXTERNAL_FAIL;

      /*  	elseif(bPISrchOverSpd) */
      /*          eHPAInhibitEvnt = tInhibitEvnt.INHIBIT_SEARCH_OVERSPEED;     */
    }
    else if ((boolean_T)((int32_T)((rtu_sVehCommon->sCondiVeh.bTirePressNorm ?
                ((int32_T)1) : ((int32_T)0)) ^ 1)))
    {
      LocalVar_eHPAInhibitEvnt = INHIBIT_TIRE_PRESSURE_ABNORMAL;
    }
    else if (rtu_sVehDataRx->sVehESCInfo.bDAActive)
    {
      LocalVar_eHPAInhibitEvnt = INHIBIT_ACTIVE_DA;
    }
    else if (rtu_sVehDataRx->sVehVCUInfo.bHVOff)
    {
      LocalVar_eHPAInhibitEvnt = INHIBIT_HV_NOT_READY;
    }
    else
    {
      LocalVar_eHPAInhibitEvnt = INHIBIT_NONE;
    }
  }
  else
  {
    LocalVar_eHPAInhibitEvnt = INHIBIT_NONE;
  }

  /* End of MATLAB Function: '<S2>/HPAInhibitEvntDet' */
  (void)memset(rty_sHpaStateCommon, 0, sizeof(tHpaStateCommon));

  /* BusAssignment: '<Root>/Bus Assignment2' incorporates:
   *  BusAssignment: '<S2>/Bus Assignment'
   *  UnitDelay: '<S2>/Unit Delay7'
   *  UnitDelay: '<S2>/Unit Delay8'
   */
  rty_sHpaStateCommon->sHPACondiOverFlag = LocalVar_sHPACondiOverFlag;
  rty_sHpaStateCommon->sHPAEvnt.eHPAQuitEvnt =
    hpa_state_common_DW.UnitDelay8_DSTATE;
  rty_sHpaStateCommon->sHPAEvnt.eHPAIntrptEvnt = LocalVar_eHPAIntrptEvnt;
  rty_sHpaStateCommon->sHPAEvnt.eHPATrmntEvnt =
    hpa_state_common_DW.UnitDelay7_DSTATE;
  rty_sHpaStateCommon->sHPAEvnt.eHPAInhibitEvnt = LocalVar_eHPAInhibitEvnt;

  /* MATLAB Function: '<S2>/HPAFailureEvntDet' incorporates:
   *  RelationalOperator: '<S8>/Equal3'
   */
  if (rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_FAILURE)
  {
    if (rtu_sDiagInfo->sUssFail.bUssFail)
    {
      /* BusAssignment: '<Root>/Bus Assignment2' */
      rty_sHpaStateCommon->sHPAEvnt.eHPAFailureEvnt = FAILURE_USS_FAIL;
    }
    else if (rtu_sDiagInfo->sVisionFail.bVisionFail)
    {
      /* BusAssignment: '<Root>/Bus Assignment2' */
      rty_sHpaStateCommon->sHPAEvnt.eHPAFailureEvnt = FAILURE_VISION_FAIL;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                  ((rtu_sDiagInfo->sVisionFail.bVisionFail ? ((int32_T)1) :
                    ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)) &
               (((boolean_T)((int32_T)((rtu_sDiagInfo->sUssFail.bUssFail ?
        ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
    {
      /* BusAssignment: '<Root>/Bus Assignment2' */
      rty_sHpaStateCommon->sHPAEvnt.eHPAFailureEvnt = FAILURE_INTERNAL_FAIL;
    }
    else
    {
      /* BusAssignment: '<Root>/Bus Assignment2' */
      rty_sHpaStateCommon->sHPAEvnt.eHPAFailureEvnt = FAILURE_NONE;
    }
  }
  else
  {
    /* BusAssignment: '<Root>/Bus Assignment2' */
    rty_sHpaStateCommon->sHPAEvnt.eHPAFailureEvnt = FAILURE_NONE;
  }

  /* End of MATLAB Function: '<S2>/HPAFailureEvntDet' */

  /* BusAssignment: '<Root>/Bus Assignment2' incorporates:
   *  BusAssignment: '<S2>/Bus Assignment'
   *  UnitDelay: '<S2>/Unit Delay9'
   */
  rty_sHpaStateCommon->sHPAEvnt.eHPAIntrptType =
    hpa_state_common_DW.UnitDelay9_DSTATE;
}

/* Model initialize function */
void hpa_state_common_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)&hpa_state_common_DW, 0,
                sizeof(DW_hpa_state_common_f_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
