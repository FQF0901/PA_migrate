/*
 * File: ra_state_common.c
 *
 * Code generated for Simulink model 'ra_state_common'.
 *
 * Model version                  : 1.239
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Dec  2 15:53:29 2024
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
#define CtrlPara_START_SEC_VAR
#include "proj_MemMap.h"
#include "ra_state_common.h"
#define CtrlPara_STOP_SEC_VAR
#include "proj_MemMap.h"
/* Block states (default storage) */
DW_ra_state_common_f_T ra_state_common_DW;

/* Output and update for referenced model: 'ra_state_common' */
void ra_state_common(const tVehDataRx *rtu_sVehDataRx, const tVehCommon
                     *rtu_sVehCommon, const tRAHmiRx *rtu_sRAHmiRx, const
                     tRelatedModuleInfo *rtu_sRelatedModuleInfo, const
                     tMasterLsadFsm *rtu_sLastMasterLsadFsm, const tDiagInfo
                     *rtu_sDiagInfo, const tSlaveLsadFsm *rtu_sLastSlaveLsadFsm,
                     tRaStateCommon *rty_sRaStateCommon)
{
  boolean_T LocalVar_bQuitDurattime;
  tRAIntrptEvnt LocalVar_eRAIntrptEvnt;

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
           (((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_RA) ? ((int32_T)1) :
             ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
  {
    ra_state_common_DW.UnitDelay1_DSTATE = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S30>/Unit Delay1' incorporates:
     *  Constant: '<S8>/Constant3'
     *  Sum: '<S30>/Subtraction'
     */
    ra_state_common_DW.UnitDelay1_DSTATE += s_APPManLoopSec;
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
          ((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_RA) ?
                      ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) :
         ((int32_T)0)))))
  {
    ra_state_common_DW.UnitDelay1_DSTATE_a = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S20>/Unit Delay1' incorporates:
     *  Constant: '<S5>/Constant5'
     *  Sum: '<S20>/Subtraction'
     */
    ra_state_common_DW.UnitDelay1_DSTATE_a += s_APPManLoopSec;
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
              LSAD_RA) ? ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) :
         ((int32_T)0)))))
  {
    ra_state_common_DW.UnitDelay1_DSTATE_n = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S27>/Unit Delay1' incorporates:
     *  Constant: '<S7>/Constant15'
     *  Sum: '<S27>/Subtraction'
     */
    ra_state_common_DW.UnitDelay1_DSTATE_n += s_APPManLoopSec;
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
          ((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_RA) ?
                      ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) :
         ((int32_T)0)))))
  {
    ra_state_common_DW.UnitDelay1_DSTATE_j = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S23>/Unit Delay1' incorporates:
     *  Constant: '<S6>/Constant8'
     *  Sum: '<S23>/Subtraction'
     */
    ra_state_common_DW.UnitDelay1_DSTATE_j += s_APPManLoopSec;
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
          ((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_RA) ?
                      ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) :
         ((int32_T)0)))))
  {
    ra_state_common_DW.UnitDelay1_DSTATE_k = 0.0F;
    ra_state_common_DW.UnitDelay1_DSTATE_b = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S14>/Unit Delay1' incorporates:
     *  Constant: '<S3>/Constant10'
     *  Sum: '<S14>/Subtraction'
     */
    ra_state_common_DW.UnitDelay1_DSTATE_k += s_APPManLoopSec;

    /* UnitDelay: '<S17>/Unit Delay1' incorporates:
     *  Constant: '<S4>/Constant10'
     *  Sum: '<S17>/Subtraction'
     */
    ra_state_common_DW.UnitDelay1_DSTATE_b += s_APPManLoopSec;
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
           (((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_RA) ? ((int32_T)1) :
             ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
  {
    ra_state_common_DW.UnitDelay1_DSTATE_d = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S33>/Unit Delay1' incorporates:
     *  Constant: '<S9>/Constant11'
     *  Sum: '<S33>/Subtraction'
     */
    ra_state_common_DW.UnitDelay1_DSTATE_d += s_APPManLoopSec;
  }

  /* End of Switch: '<S33>/Switch1' */

  /* RelationalOperator: '<S9>/Equal12' incorporates:
   *  Constant: '<S9>/Constant12'
   *  UnitDelay: '<S33>/Unit Delay1'
   */
  LocalVar_bQuitDurattime = (ra_state_common_DW.UnitDelay1_DSTATE_d >=
    k_QuitDuratTime);

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
          ((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_RA) ?
                      ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) :
         ((int32_T)0)))))
  {
    ra_state_common_DW.UnitDelay1_DSTATE_aq = 0.0F;
    ra_state_common_DW.UnitDelay1_DSTATE_jw = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S36>/Unit Delay1' incorporates:
     *  Constant: '<S10>/Constant13'
     *  Sum: '<S36>/Subtraction'
     */
    ra_state_common_DW.UnitDelay1_DSTATE_aq += s_APPManLoopSec;

    /* UnitDelay: '<S39>/Unit Delay1' incorporates:
     *  Constant: '<S11>/Constant13'
     *  Sum: '<S39>/Subtraction'
     */
    ra_state_common_DW.UnitDelay1_DSTATE_jw += s_APPManLoopSec;
  }

  /* End of Switch: '<S36>/Switch1' */

  /* BusAssignment: '<S1>/Bus Assignment' incorporates:
   *  Constant: '<S10>/Constant14'
   *  Constant: '<S11>/Constant14'
   *  Constant: '<S3>/Constant9'
   *  Constant: '<S4>/Constant9'
   *  Constant: '<S5>/Constant4'
   *  RelationalOperator: '<S10>/Equal14'
   *  RelationalOperator: '<S11>/Equal14'
   *  RelationalOperator: '<S3>/Equal9'
   *  RelationalOperator: '<S4>/Equal9'
   *  RelationalOperator: '<S5>/Equal5'
   *  RelationalOperator: '<S6>/Equal7'
   *  RelationalOperator: '<S7>/Equal16'
   *  RelationalOperator: '<S8>/Equal2'
   *  UnitDelay: '<S14>/Unit Delay1'
   *  UnitDelay: '<S17>/Unit Delay1'
   *  UnitDelay: '<S20>/Unit Delay1'
   *  UnitDelay: '<S23>/Unit Delay1'
   *  UnitDelay: '<S27>/Unit Delay1'
   *  UnitDelay: '<S30>/Unit Delay1'
   *  UnitDelay: '<S36>/Unit Delay1'
   *  UnitDelay: '<S39>/Unit Delay1'
   */
  (void)memset(&rty_sRaStateCommon->sRACondiOverFlag, 0, sizeof(tRACondiOverFlag));
  rty_sRaStateCommon->sRACondiOverFlag.bRAPPOvertime =
    (ra_state_common_DW.UnitDelay1_DSTATE >= 10.0F);
  rty_sRaStateCommon->sRACondiOverFlag.bRAHandshakeOvertime =
    (ra_state_common_DW.UnitDelay1_DSTATE_a >= k_HandDuratTime);
  rty_sRaStateCommon->sRACondiOverFlag.bRAActiveOvertime =
    (ra_state_common_DW.UnitDelay1_DSTATE_n >= 1800.0F);
  rty_sRaStateCommon->sRACondiOverFlag.bRAIntrptOvertime =
    (ra_state_common_DW.UnitDelay1_DSTATE_j >= 600.0F);
  rty_sRaStateCommon->sRACondiOverFlag.bRACmpltDurattime =
    (ra_state_common_DW.UnitDelay1_DSTATE_k >= k_CmpltDuratTime);
  rty_sRaStateCommon->sRACondiOverFlag.bRACmpltOvertime =
    (ra_state_common_DW.UnitDelay1_DSTATE_b >= 4.0F);
  rty_sRaStateCommon->sRACondiOverFlag.bRAQuitDurattime =
    LocalVar_bQuitDurattime;
  rty_sRaStateCommon->sRACondiOverFlag.bRAQuitOvertime = LocalVar_bQuitDurattime;
  rty_sRaStateCommon->sRACondiOverFlag.bRATrmntDurattime =
    (ra_state_common_DW.UnitDelay1_DSTATE_aq >= k_TmntDuratTime);
  rty_sRaStateCommon->sRACondiOverFlag.bRATrmntOvertime =
    (ra_state_common_DW.UnitDelay1_DSTATE_jw >= 4.0F);

  /* MATLAB Function: '<S2>/RAIntrptEvntDet' incorporates:
   *  Constant: '<S5>/Constant4'
   *  MATLAB Function: '<S2>/RAQuitEvntDet'
   *  MATLAB Function: '<S2>/RATrmntEvntDet'
   *  RelationalOperator: '<S5>/Equal5'
   *  RelationalOperator: '<S6>/Equal7'
   *  RelationalOperator: '<S7>/Equal16'
   *  RelationalOperator: '<S8>/Equal2'
   *  RelationalOperator: '<S8>/Equal3'
   *  UnitDelay: '<S20>/Unit Delay1'
   *  UnitDelay: '<S23>/Unit Delay1'
   *  UnitDelay: '<S27>/Unit Delay1'
   *  UnitDelay: '<S2>/Unit Delay'
   *  UnitDelay: '<S2>/Unit Delay7'
   *  UnitDelay: '<S2>/Unit Delay9'
   *  UnitDelay: '<S30>/Unit Delay1'
   */
  if (LSAD_RA == rtu_sLastSlaveLsadFsm->eLsadFuncType)
  {
    if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
            LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0)) |
          ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE_SUSPEND) ?
           ((int32_T)1) : ((int32_T)0)))))
    {
      if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
                   ((((boolean_T)((int32_T)
          ((rtu_sVehCommon->sCondiDoorSblt.bFLDrClose ? ((int32_T)1) : ((int32_T)
          0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
          ((rtu_sVehCommon->sCondiDoorSblt.bFRDrClose ? ((int32_T)1) : ((int32_T)
          0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                 ((int32_T)0)) | (((boolean_T)((int32_T)
                   ((rtu_sVehCommon->sCondiDoorSblt.bRLDrClose ? ((int32_T)1) :
                     ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ?
             ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
               ((rtu_sVehCommon->sCondiDoorSblt.bRRDrClose ? ((int32_T)1) :
                 ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
      {
        LocalVar_eRAIntrptEvnt = RA_INTERRUPT_DOOR_OPEN;
        ra_state_common_DW.UnitDelay9_DSTATE = RA_INTERRUPTION_NEED_CONFIRM;
      }
      else if ((boolean_T)((int32_T)
                           ((rtu_sVehCommon->sCondiDoorSblt.bHoodDrClose ?
                             ((int32_T)1) : ((int32_T)0)) ^ 1)))
      {
        LocalVar_eRAIntrptEvnt = RA_INTERRUPT_HOOD_OPEN;
        ra_state_common_DW.UnitDelay9_DSTATE = RA_INTERRUPTION_NEED_CONFIRM;
      }
      else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                    ((rtu_sVehCommon->sCondiDoorSblt.bSeatbltAct ? ((int32_T)1) :
                      ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)) &
                 (k_bIntrptEvntSeatblt ? ((int32_T)1) : ((int32_T)0)))))
      {
        LocalVar_eRAIntrptEvnt = RA_INTERRUPT_SEATBELT_UNBUCKLED;
        ra_state_common_DW.UnitDelay9_DSTATE = RA_INTERRUPTION_NEED_CONFIRM;
      }
      else if ((boolean_T)((int32_T)
                           ((rtu_sVehCommon->sCondiDoorSblt.bTailGateClose ?
                             ((int32_T)1) : ((int32_T)0)) ^ 1)))
      {
        LocalVar_eRAIntrptEvnt = RA_INTERRUPT_TRUNK_OPEN;
        ra_state_common_DW.UnitDelay9_DSTATE = RA_INTERRUPTION_NEED_CONFIRM;
      }
      else if (rtu_sVehCommon->sCondiPlatform.bObstAppear)
      {
        LocalVar_eRAIntrptEvnt = RA_INTERRUPT_OBSTACLE;
        ra_state_common_DW.UnitDelay9_DSTATE = RA_INTERRUPTION_NEED_CONFIRM;
      }
      else if (rtu_sRAHmiRx->eRAPrkWorkMd == PRK_WORK_PAUSE)
      {
        LocalVar_eRAIntrptEvnt = RA_INTERRUPT_MANUAL_PAUSE;
        ra_state_common_DW.UnitDelay9_DSTATE = RA_INTERRUPTION_NEED_CONFIRM;
      }
      else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
          ((int32_T)((rtu_sVehCommon->sCondiPlatform.bActvStsNeedRlsBrk ?
                      ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) :
          ((int32_T)0)) & (rtu_sVehDataRx->sVehVCUInfo.bBrkPedal ? ((int32_T)1) :
                           ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
                 (k_bIntrptEvntBrkPdl ? ((int32_T)1) : ((int32_T)0)))))
      {
        LocalVar_eRAIntrptEvnt = RA_INTERRUPT_MANUAL_BRAKE;
        ra_state_common_DW.UnitDelay9_DSTATE = RA_INTERRUPTION_NO_CONFIRM;
      }
      else
      {
        LocalVar_eRAIntrptEvnt = RA_INTERRUPT_NONE;
      }
    }
    else
    {
      LocalVar_eRAIntrptEvnt = RA_INTERRUPT_NONE;
    }

    if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
             (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
               ((int32_T)1) : ((int32_T)0)) |
              ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ?
           ((int32_T)1) : ((int32_T)0)) &
          (rtu_sVehDataRx->sVehVCUInfo.bShftInterf ? ((int32_T)1) : ((int32_T)0)))))
    {
      ra_state_common_DW.UnitDelay7_DSTATE = RA_TERMINATE_STEER_INTERFERE;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                  (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                     LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) &
               (rtu_sVehDataRx->sVehVCUInfo.bAccPedal ? ((int32_T)1) : ((int32_T)
                 0)))))
    {
      ra_state_common_DW.UnitDelay7_DSTATE = RA_TERMINATE_ACCEL_INTERFERE;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                  (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                     LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) &
               (rtu_sVehDataRx->sVehEPSInfo.bEpsInterf ? ((int32_T)1) :
                ((int32_T)0)))))
    {
      ra_state_common_DW.UnitDelay7_DSTATE = RA_TERMINATE_GEAR_INTERFERE;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                  (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                     LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) &
               (rtu_sVehDataRx->sVehESCInfo.bDAActive ? ((int32_T)1) : ((int32_T)
                 0)))))
    {
      ra_state_common_DW.UnitDelay7_DSTATE = RA_TERMINATE_UXEXP_ADAS;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                     LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0)) & (rtu_sVehCommon->sCondiVeh.bEPBUnexp ?
        ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
               ((rtu_sRelatedModuleInfo->eHandshakeSts == HANDSHAKE_CONTROLLED) ?
                ((int32_T)1) : ((int32_T)0)))))
    {
      ra_state_common_DW.UnitDelay7_DSTATE = RA_TERMINATE_UNEXP_EPB;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                  (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                     LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
                  ((rtu_sVehCommon->sCondiVeh.bTirePressNorm ? ((int32_T)1) :
                    ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
    {
      ra_state_common_DW.UnitDelay7_DSTATE = RA_TERMINATE_TIRE_PRESSURE_ABNORMAL;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                  (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                     LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) &
               (rtu_sVehCommon->sCondiVeh.bPrkOverSlope ? ((int32_T)1) :
                ((int32_T)0)))))
    {
      ra_state_common_DW.UnitDelay7_DSTATE = RA_TERMINATE_SLOPE_OVERLIMIT;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                  (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                     LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) &
               (rtu_sVehDataRx->sVehESCInfo.bASActive ? ((int32_T)1) : ((int32_T)
                 0)))))
    {
      ra_state_common_DW.UnitDelay7_DSTATE = RA_TERMINATE_UNEXP_AS;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                  (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                     LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) &
               (rtu_sVehDataRx->sVehBCMInfo.bMirrFld ? ((int32_T)1) : ((int32_T)
                 0)))))
    {
      ra_state_common_DW.UnitDelay7_DSTATE = RA_TERMINATE_MIRROR_FOLD;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                  (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                     LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) &
               (rtu_sVehDataRx->sVehVCUInfo.bHVOff ? ((int32_T)1) : ((int32_T)0)))))
    {
      ra_state_common_DW.UnitDelay7_DSTATE = RA_TERMINATE_HV_NOT_READY;
    }
    else if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                 LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0)) &
               ((ra_state_common_DW.UnitDelay1_DSTATE_n >= 1800.0F) ? ((int32_T)
                 1) : ((int32_T)0)))))
    {
      ra_state_common_DW.UnitDelay7_DSTATE = RA_TERMINATE_MANVR_OVERTIME;

      /*      elseif(eLsadSystemSts == tLSAD_SystemSts.LSAD_STS_ACTIVE && bManeuverOverSpd) */
      /*          eRATrmntEvnt = tRATrmntEvnt.RA_TERMINATE_MANVR_OVERSPEED; */
    }
    else if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                 LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0)) &
               (rtu_sVehCommon->sCondiVeh.bDrvBlock ? ((int32_T)1) : ((int32_T)0)))))
    {
      ra_state_common_DW.UnitDelay7_DSTATE = RA_TERMINATE_VEH_BLOCK;
    }
    else if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                 LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0)) &
               (rtu_sVehCommon->sCondiVeh.bVehSlip ? ((int32_T)1) : ((int32_T)0)))))
    {
      ra_state_common_DW.UnitDelay7_DSTATE = RA_TERMINATE_VEH_SLIP;
    }
    else if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                 LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0)) &
               ((ra_state_common_DW.UnitDelay1_DSTATE_j >= 600.0F) ? ((int32_T)1)
                : ((int32_T)0)))))
    {
      ra_state_common_DW.UnitDelay7_DSTATE = RA_TERMINATE_INTERRUPT_OVERTIME;
    }
    else if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                 LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0)) &
               (rty_sRaStateCommon->sRACondiOverFlag.bRAIntrptOverflow ?
                ((int32_T)1) : ((int32_T)0)))))
    {
      ra_state_common_DW.UnitDelay7_DSTATE = RA_TERMINATE_INTERRUPT_OVERFLOW;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                  (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                     LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) & ((PRK_WORK_EXIT ==
                 rtu_sRAHmiRx->eRAPrkWorkMd) ? ((int32_T)1) : ((int32_T)0)))))
    {
      ra_state_common_DW.UnitDelay7_DSTATE = RA_TERMINATE_MANUAL_DEACT;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                  (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                     LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) &
               ((rtu_sRelatedModuleInfo->eHandshakeSts == HANDSHAKE_FAIL) ?
                ((int32_T)1) : ((int32_T)0)))))
    {
      ra_state_common_DW.UnitDelay7_DSTATE = RA_TERMINATE_EXTERNAL_FAIL;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)((((boolean_T)((int32_T)
        (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
          ((int32_T)1) : ((int32_T)0)) |
         ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE_SUSPEND) ?
          ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
                   (rtu_sDiagInfo->bPASysFail ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0)) & (rtu_sDiagInfo->sComFail.bComFail ?
        ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
               (((boolean_T)((int32_T)((rtu_sDiagInfo->sComFail.bEthFail ?
        ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
    {
      ra_state_common_DW.UnitDelay7_DSTATE = RA_TERMINATE_INVALID_SIGNAL;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                     LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
      LSAD_STS_PP) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)
                 0)) & (((boolean_T)((int32_T)((((boolean_T)((int32_T)
        ((((boolean_T)((int32_T)((((boolean_T)((int32_T)
        ((rtu_sDiagInfo->bPASysFail ? ((int32_T)1) : ((int32_T)0)) |
         ((rtu_sRelatedModuleInfo->eCtrlSts == APA_CTRL_FAULT) ? ((int32_T)1) :
        ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) | ((APA_PATH_PLAN_FAILED
      == rtu_sRelatedModuleInfo->ePathPlanSts) ? ((int32_T)1) : ((int32_T)0)))))
          ? ((int32_T)1) : ((int32_T)0)) | ((APA_PATH_PLAN_PRE_FAILED ==
        rtu_sRelatedModuleInfo->ePathPlanSts) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0)) | ((ra_state_common_DW.UnitDelay1_DSTATE >=
        10.0F) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)))))
    {
      ra_state_common_DW.UnitDelay7_DSTATE = RA_TERMINATE_INTERNAL_FAIL;
    }
    else if (rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_STANDBY)
    {
      ra_state_common_DW.UnitDelay7_DSTATE = RA_TERMINATE_NONE;
    }
    else
    {
      /* no actions */
    }

    if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
                 (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PREPARE) ?
                   ((int32_T)1) : ((int32_T)0)) |
                  ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                    LSAD_STS_PREPARE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ?
               ((int32_T)1) : ((int32_T)0)) |
              ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_HANDSHAKE) ?
               ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
          (((boolean_T)((int32_T)((rtu_sVehCommon->sCondiVeh.bVehStill ?
               ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
    {
      ra_state_common_DW.UnitDelay_DSTATE = RA_QUIT_VEH_MOVE;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PREPARE)
                    ? ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                     LSAD_STS_PREPARE_SUSPEND) ? ((int32_T)1) : ((int32_T)0)))))
      ? ((int32_T)1) : ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
      LSAD_STS_HANDSHAKE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                ((int32_T)0)) & ((PRK_WORK_EXIT == rtu_sRAHmiRx->eRAPrkWorkMd) ?
                ((int32_T)1) : ((int32_T)0)))))
    {
      ra_state_common_DW.UnitDelay_DSTATE = RA_QUIT_MANUAL_DEACTIVATE;
    }
    else if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                 LSAD_STS_HANDSHAKE) ? ((int32_T)1) : ((int32_T)0)) &
               (((boolean_T)((int32_T)(((HANDSHAKE_FAIL ==
        rtu_sRelatedModuleInfo->eHandshakeSts) ? ((int32_T)1) : ((int32_T)0)) |
        ((ra_state_common_DW.UnitDelay1_DSTATE_a >= k_HandDuratTime) ? ((int32_T)
        1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)))))
    {
      ra_state_common_DW.UnitDelay_DSTATE = RA_QUIT_HANDSHAKE_FAIL;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PREPARE)
                    ? ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
                     LSAD_STS_PREPARE_SUSPEND) ? ((int32_T)1) : ((int32_T)0)))))
      ? ((int32_T)1) : ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
      LSAD_STS_HANDSHAKE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                ((int32_T)0)) & (rtu_sDiagInfo->bPASysFail ? ((int32_T)1) :
                ((int32_T)0)))))
    {
      ra_state_common_DW.UnitDelay_DSTATE = RA_QUIT_INTERNAL_FAIL;
    }
    else if (rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_STANDBY)
    {
      ra_state_common_DW.UnitDelay_DSTATE = RA_QUIT_NONE;
    }
    else
    {
      /* no actions */
    }
  }
  else
  {
    LocalVar_eRAIntrptEvnt = RA_INTERRUPT_NONE;
    ra_state_common_DW.UnitDelay9_DSTATE = RA_INTERRUTPION_NONE;
    ra_state_common_DW.UnitDelay7_DSTATE = RA_TERMINATE_NONE;
    ra_state_common_DW.UnitDelay_DSTATE = RA_QUIT_NONE;
  }

  /* End of MATLAB Function: '<S2>/RAIntrptEvntDet' */

  /* BusAssignment: '<S2>/Bus Assignment' incorporates:
   *  UnitDelay: '<S2>/Unit Delay'
   *  UnitDelay: '<S2>/Unit Delay7'
   *  UnitDelay: '<S2>/Unit Delay9'
   */
  (void)memset(&rty_sRaStateCommon->sRAEvnt, 0, sizeof(tRAEvnt));
  rty_sRaStateCommon->sRAEvnt.eRAIntrptEvnt = LocalVar_eRAIntrptEvnt;
  rty_sRaStateCommon->sRAEvnt.eRATrmntEvnt =
    ra_state_common_DW.UnitDelay7_DSTATE;
  rty_sRaStateCommon->sRAEvnt.eRAFailureEvnt = RA_FAILURE_NONE;
  rty_sRaStateCommon->sRAEvnt.eRAQuitEvnt = ra_state_common_DW.UnitDelay_DSTATE;
  rty_sRaStateCommon->sRAEvnt.eRAIntrptType =
    ra_state_common_DW.UnitDelay9_DSTATE;
}

/* Model initialize function */
void ra_state_common_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)&ra_state_common_DW, 0,
                sizeof(DW_ra_state_common_f_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
