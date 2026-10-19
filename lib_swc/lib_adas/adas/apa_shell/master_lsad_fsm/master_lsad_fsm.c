/*
 * File: master_lsad_fsm.c
 *
 * Code generated for Simulink model 'master_lsad_fsm'.
 *
 * Model version                  : 3.2685
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Dec  2 15:54:08 2024
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

#include "master_lsad_fsm.h"

/* Named constants for Chart: '<Root>/master_lsad_fsm_stateflow' */
#define master_lsad_fsm_IN_Active      ((uint8_T)1U)
#define master_lsad_fsm_IN_Active_Main ((uint8_T)1U)
#define master_lsad_fsm_IN_Active_Suspend ((uint8_T)2U)
#define master_lsad_fsm_IN_Complete    ((uint8_T)1U)
#define master_lsad_fsm_IN_Disable     ((uint8_T)1U)
#define master_lsad_fsm_IN_Enable      ((uint8_T)2U)
#define master_lsad_fsm_IN_Failure     ((uint8_T)1U)
#define master_lsad_fsm_IN_Finish      ((uint8_T)2U)
#define master_lsad_fsm_IN_HandShake   ((uint8_T)3U)
#define master_lsad_fsm_IN_Inhibit     ((uint8_T)2U)
#define master_lsad_fsm_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define master_lsad_fsm_IN_Off         ((uint8_T)3U)
#define master_lsad_fsm_IN_PathPlan    ((uint8_T)4U)
#define master_lsad_fsm_IN_Prepare     ((uint8_T)1U)
#define master_lsad_fsm_IN_Prepare_Main ((uint8_T)5U)
#define master_lsad_fsm_IN_Prepare_Suspend ((uint8_T)2U)
#define master_lsad_fsm_IN_Quit        ((uint8_T)2U)
#define master_lsad_fsm_IN_Standby     ((uint8_T)6U)
#define master_lsad_fsm_IN_Terminate   ((uint8_T)3U)

/* Block states (default storage) */
#define CtrlPara_START_SEC_VAR
#include "proj_MemMap.h"
DW_master_lsad_fsm_f_T master_lsad_fsm_DW;
#define CtrlPara_STOP_SEC_VAR
#include "proj_MemMap.h"
/* Forward declaration for local functions */
static void master_lsad_fsm_Enable(tLSAD_SystemSts *eLsadSystemSts, const
  boolean_T *bActive2Complete, const boolean_T *bActive2Prepare, const boolean_T
  *bActive2Suspend, const boolean_T *bActive2Terminate, const real_T *bEnble2Off);

/* Function for Chart: '<Root>/master_lsad_fsm_stateflow' */
static void master_lsad_fsm_Enable(tLSAD_SystemSts *eLsadSystemSts, const
  boolean_T *bActive2Complete, const boolean_T *bActive2Prepare, const boolean_T
  *bActive2Suspend, const boolean_T *bActive2Terminate, const real_T *bEnble2Off)
{
  if ((*bEnble2Off) != 0.0)
  {
    master_lsad_fsm_DW.bitsForTID0.is_Active_Main =
      master_lsad_fsm_IN_NO_ACTIVE_CHILD;
    master_lsad_fsm_DW.bitsForTID0.is_Finish =
      master_lsad_fsm_IN_NO_ACTIVE_CHILD;
    master_lsad_fsm_DW.bitsForTID0.is_Prepare_Main =
      master_lsad_fsm_IN_NO_ACTIVE_CHILD;
    master_lsad_fsm_DW.bitsForTID0.is_Enable =
      master_lsad_fsm_IN_NO_ACTIVE_CHILD;
    master_lsad_fsm_DW.bitsForTID0.is_c3_master_lsad_fsm =
      master_lsad_fsm_IN_Disable;
    master_lsad_fsm_DW.bitsForTID0.is_Disable = master_lsad_fsm_IN_Off;
    *eLsadSystemSts = LSAD_STS_OFF;
  }
  else
  {
    switch (master_lsad_fsm_DW.bitsForTID0.is_Enable)
    {
     case master_lsad_fsm_IN_Active_Main:
      if (*bActive2Complete)
      {
        master_lsad_fsm_DW.bitsForTID0.is_Active_Main =
          master_lsad_fsm_IN_NO_ACTIVE_CHILD;
        master_lsad_fsm_DW.bitsForTID0.is_Enable = master_lsad_fsm_IN_Finish;
        master_lsad_fsm_DW.bitsForTID0.is_Finish = master_lsad_fsm_IN_Complete;
        *eLsadSystemSts = LSAD_STS_COMPLETE;
      }
      else if (*bActive2Terminate)
      {
        master_lsad_fsm_DW.bitsForTID0.is_Active_Main =
          master_lsad_fsm_IN_NO_ACTIVE_CHILD;
        master_lsad_fsm_DW.bitsForTID0.is_Enable = master_lsad_fsm_IN_Finish;
        master_lsad_fsm_DW.bitsForTID0.is_Finish = master_lsad_fsm_IN_Terminate;
        *eLsadSystemSts = LSAD_STS_TERMINATED;
      }
      else if (*bActive2Prepare)
      {
        master_lsad_fsm_DW.bitsForTID0.is_Active_Main =
          master_lsad_fsm_IN_NO_ACTIVE_CHILD;
        master_lsad_fsm_DW.bitsForTID0.is_Enable =
          master_lsad_fsm_IN_Prepare_Main;
        master_lsad_fsm_DW.bitsForTID0.is_Prepare_Main =
          master_lsad_fsm_IN_Prepare;
        *eLsadSystemSts = LSAD_STS_PREPARE;
      }
      else if (((uint32_T)master_lsad_fsm_DW.bitsForTID0.is_Active_Main) ==
               master_lsad_fsm_IN_Active)
      {
        if (*bActive2Suspend)
        {
          master_lsad_fsm_DW.bitsForTID0.is_Active_Main =
            master_lsad_fsm_IN_Active_Suspend;
          *eLsadSystemSts = LSAD_STS_ACTIVE_SUSPEND;
        }
        else
        {
          *eLsadSystemSts = LSAD_STS_ACTIVE;
        }

        /* case IN_Active_Suspend: */
      }
      else if (master_lsad_fsm_DW.bitsForTID0.bSuspend2Active)
      {
        master_lsad_fsm_DW.bitsForTID0.is_Active_Main =
          master_lsad_fsm_IN_Active;
        *eLsadSystemSts = LSAD_STS_ACTIVE;
      }
      else
      {
        *eLsadSystemSts = LSAD_STS_ACTIVE_SUSPEND;
      }
      break;

     case master_lsad_fsm_IN_Finish:
      switch (master_lsad_fsm_DW.bitsForTID0.is_Finish)
      {
       case master_lsad_fsm_IN_Complete:
        if (master_lsad_fsm_DW.bitsForTID0.bComplete2Standby)
        {
          master_lsad_fsm_DW.bitsForTID0.is_Finish =
            master_lsad_fsm_IN_NO_ACTIVE_CHILD;
          master_lsad_fsm_DW.bitsForTID0.is_Enable = master_lsad_fsm_IN_Standby;
          *eLsadSystemSts = LSAD_STS_STANDBY;
        }
        else
        {
          *eLsadSystemSts = LSAD_STS_COMPLETE;
        }
        break;

       case master_lsad_fsm_IN_Quit:
        if (master_lsad_fsm_DW.bitsForTID0.bQuit2Standby)
        {
          master_lsad_fsm_DW.bitsForTID0.is_Finish =
            master_lsad_fsm_IN_NO_ACTIVE_CHILD;
          master_lsad_fsm_DW.bitsForTID0.is_Enable = master_lsad_fsm_IN_Standby;
          *eLsadSystemSts = LSAD_STS_STANDBY;
        }
        else
        {
          *eLsadSystemSts = LSAD_STS_QUIT;
        }
        break;

       default:
        /* case IN_Terminate: */
        if (master_lsad_fsm_DW.bitsForTID0.bTerminate2Standby)
        {
          master_lsad_fsm_DW.bitsForTID0.is_Finish =
            master_lsad_fsm_IN_NO_ACTIVE_CHILD;
          master_lsad_fsm_DW.bitsForTID0.is_Enable = master_lsad_fsm_IN_Standby;
          *eLsadSystemSts = LSAD_STS_STANDBY;
        }
        else
        {
          *eLsadSystemSts = LSAD_STS_TERMINATED;
        }
        break;
      }
      break;

     case master_lsad_fsm_IN_HandShake:
      if (master_lsad_fsm_DW.bitsForTID0.bHandshake2Quit)
      {
        master_lsad_fsm_DW.bitsForTID0.is_Enable = master_lsad_fsm_IN_Finish;
        master_lsad_fsm_DW.bitsForTID0.is_Finish = master_lsad_fsm_IN_Quit;
        *eLsadSystemSts = LSAD_STS_QUIT;
      }
      else if (master_lsad_fsm_DW.bitsForTID0.bHandshake2PP)
      {
        master_lsad_fsm_DW.bitsForTID0.is_Enable = master_lsad_fsm_IN_PathPlan;
        *eLsadSystemSts = LSAD_STS_PP;
      }
      else if (master_lsad_fsm_DW.bitsForTID0.bHandshake2Terminate)
      {
        master_lsad_fsm_DW.bitsForTID0.is_Enable = master_lsad_fsm_IN_Finish;
        master_lsad_fsm_DW.bitsForTID0.is_Finish = master_lsad_fsm_IN_Terminate;
        *eLsadSystemSts = LSAD_STS_TERMINATED;
      }
      else
      {
        *eLsadSystemSts = LSAD_STS_HANDSHAKE;
      }
      break;

     case master_lsad_fsm_IN_PathPlan:
      if (master_lsad_fsm_DW.bitsForTID0.bPP2Active)
      {
        master_lsad_fsm_DW.bitsForTID0.is_Enable =
          master_lsad_fsm_IN_Active_Main;
        master_lsad_fsm_DW.bitsForTID0.is_Active_Main =
          master_lsad_fsm_IN_Active;
        *eLsadSystemSts = LSAD_STS_ACTIVE;
      }
      else if (master_lsad_fsm_DW.bitsForTID0.bPP2Terminate)
      {
        master_lsad_fsm_DW.bitsForTID0.is_Enable = master_lsad_fsm_IN_Finish;
        master_lsad_fsm_DW.bitsForTID0.is_Finish = master_lsad_fsm_IN_Terminate;
        *eLsadSystemSts = LSAD_STS_TERMINATED;
      }
      else
      {
        *eLsadSystemSts = LSAD_STS_PP;
      }
      break;

     case master_lsad_fsm_IN_Prepare_Main:
      if (master_lsad_fsm_DW.bitsForTID0.bPrepare2Quit)
      {
        master_lsad_fsm_DW.bitsForTID0.is_Prepare_Main =
          master_lsad_fsm_IN_NO_ACTIVE_CHILD;
        master_lsad_fsm_DW.bitsForTID0.is_Enable = master_lsad_fsm_IN_Finish;
        master_lsad_fsm_DW.bitsForTID0.is_Finish = master_lsad_fsm_IN_Quit;
        *eLsadSystemSts = LSAD_STS_QUIT;
      }
      else if (master_lsad_fsm_DW.bitsForTID0.bPrepare2Handshake)
      {
        master_lsad_fsm_DW.bitsForTID0.is_Prepare_Main =
          master_lsad_fsm_IN_NO_ACTIVE_CHILD;
        master_lsad_fsm_DW.bitsForTID0.is_Enable = master_lsad_fsm_IN_HandShake;
        *eLsadSystemSts = LSAD_STS_HANDSHAKE;
      }
      else if (((uint32_T)master_lsad_fsm_DW.bitsForTID0.is_Prepare_Main) ==
               master_lsad_fsm_IN_Prepare)
      {
        if (master_lsad_fsm_DW.bitsForTID0.bPrepare2Suspend)
        {
          master_lsad_fsm_DW.bitsForTID0.is_Prepare_Main =
            master_lsad_fsm_IN_Prepare_Suspend;
          *eLsadSystemSts = LSAD_STS_PREPARE_SUSPEND;
        }
        else
        {
          *eLsadSystemSts = LSAD_STS_PREPARE;
        }

        /* case IN_Prepare_Suspend: */
      }
      else if (master_lsad_fsm_DW.bitsForTID0.bSuspend2Prepare)
      {
        master_lsad_fsm_DW.bitsForTID0.is_Prepare_Main =
          master_lsad_fsm_IN_Prepare;
        *eLsadSystemSts = LSAD_STS_PREPARE;
      }
      else
      {
        *eLsadSystemSts = LSAD_STS_PREPARE_SUSPEND;
      }
      break;

     default:
      /* case IN_Standby: */
      if (master_lsad_fsm_DW.bStandby2Fail != 0.0)
      {
        master_lsad_fsm_DW.bitsForTID0.is_Enable =
          master_lsad_fsm_IN_NO_ACTIVE_CHILD;
        master_lsad_fsm_DW.bitsForTID0.is_c3_master_lsad_fsm =
          master_lsad_fsm_IN_Disable;
        master_lsad_fsm_DW.bitsForTID0.is_Disable = master_lsad_fsm_IN_Failure;
        *eLsadSystemSts = LSAD_STS_FAILURE;
      }
      else if (master_lsad_fsm_DW.bitsForTID0.bStandby2Inhibit)
      {
        master_lsad_fsm_DW.bitsForTID0.is_Enable =
          master_lsad_fsm_IN_NO_ACTIVE_CHILD;
        master_lsad_fsm_DW.bitsForTID0.is_c3_master_lsad_fsm =
          master_lsad_fsm_IN_Disable;
        master_lsad_fsm_DW.bitsForTID0.is_Disable = master_lsad_fsm_IN_Inhibit;
        *eLsadSystemSts = LSAD_STS_INHIBIT;
      }
      else if (master_lsad_fsm_DW.bitsForTID0.bStandby2Prepare)
      {
        master_lsad_fsm_DW.bitsForTID0.is_Enable =
          master_lsad_fsm_IN_Prepare_Main;
        master_lsad_fsm_DW.bitsForTID0.is_Prepare_Main =
          master_lsad_fsm_IN_Prepare;
        *eLsadSystemSts = LSAD_STS_PREPARE;
      }
      else
      {
        *eLsadSystemSts = LSAD_STS_STANDBY;
      }
      break;
    }
  }
}

/* System initialize for referenced model: 'master_lsad_fsm' */
void master_lsad_fsm_Init(void)
{
  /* SystemInitialize for Chart: '<Root>/master_lsad_fsm_stateflow' */
  master_lsad_fsm_DW.bitsForTID0.is_Disable = master_lsad_fsm_IN_NO_ACTIVE_CHILD;
  master_lsad_fsm_DW.bitsForTID0.is_Enable = master_lsad_fsm_IN_NO_ACTIVE_CHILD;
  master_lsad_fsm_DW.bitsForTID0.is_Active_Main =
    master_lsad_fsm_IN_NO_ACTIVE_CHILD;
  master_lsad_fsm_DW.bitsForTID0.is_Finish = master_lsad_fsm_IN_NO_ACTIVE_CHILD;
  master_lsad_fsm_DW.bitsForTID0.is_Prepare_Main =
    master_lsad_fsm_IN_NO_ACTIVE_CHILD;
  master_lsad_fsm_DW.bitsForTID0.is_active_c3_master_lsad_fsm = 0U;
  master_lsad_fsm_DW.bitsForTID0.is_c3_master_lsad_fsm =
    master_lsad_fsm_IN_NO_ACTIVE_CHILD;
}

/* Output and update for referenced model: 'master_lsad_fsm' */
void master_lsad_fsm(const tPAHmiRx *rtu_sPAHmiRx, const tPaStateCommon
                     *rtu_sPaStateCommon, const tVehCommon *rtu_sVehCommon,
                     const tVehDataRx *rtu_sVehDataRx, const tRelatedModuleInfo *
                     rtu_sRelatedModuleInfo, const tHpaStateCommon
                     *rtu_sHpaStateCommon, const tSlaveLsadFsm
                     *rtu_sSlaveLsadFsm, const tHPAHmiRx *rtu_sHPAHmiRx, const
                     tRAHmiRx *rtu_sRAHmiRx, const boolean_T
                     *rtu_sRaStateCommon_sRACondiOverFlag_bRAIntrptOvertime,
                     const boolean_T
                     *rtu_sRaStateCommon_sRACondiOverFlag_bRACmpltDurattime,
                     const boolean_T
                     *rtu_sRaStateCommon_sRACondiOverFlag_bRACmpltOvertime,
                     const boolean_T
                     *rtu_sRaStateCommon_sRACondiOverFlag_bRATrmntDurattime,
                     const boolean_T
                     *rtu_sRaStateCommon_sRACondiOverFlag_bRATrmntOvertime,
                     const tRAIntrptEvnt
                     *rtu_sRaStateCommon_sRAEvnt_eRAIntrptEvnt, const
                     tRATrmntEvnt *rtu_sRaStateCommon_sRAEvnt_eRATrmntEvnt,
                     const tRAIntrptType
                     *rtu_sRaStateCommon_sRAEvnt_eRAIntrptType, const tDiagInfo *
                     rtu_sDiagInfo, const tMasterLsadFsm *rtu_sLastMasterLsadFsm,
                     const tPaStateAdptr *rtu_sPaStateAdptr, tMasterLsadFsm
                     *rty_sMasterLsadFsm)
{
  real_T bEnble2Off;
  tLSAD_SystemSts eLsadSystemSts;
  boolean_T LocalVar_AND10;
  boolean_T LocalVar_OR1;
  boolean_T LocalVar_OR1_f;
  boolean_T LocalVar_OR1_g;
  boolean_T LocalVar_OR1_j;
  boolean_T LocalVar_RelationalOperator;
  boolean_T LocalVar_bBlindUnLockNeedContinue;
  boolean_T LocalVar_bBlindUnLockNeedContinue_a;
  boolean_T LocalVar_bBlindUnLockNeedContinue_n;
  boolean_T LocalVar_bBlindUnLockNeedContinue_p;
  boolean_T LocalVar_bNeedContinue;
  boolean_T LocalVar_bNeedContinue_c;
  boolean_T LocalVar_bNeedContinue_o;
  boolean_T bActive2Complete;
  boolean_T bActive2Prepare;
  boolean_T bActive2Suspend;
  boolean_T bActive2Terminate;
  boolean_T bStandby2Inhibit_tmp;

  /* Outputs for Atomic SubSystem: '<Root>/Quit2IdleDet' */
  /* Outputs for Atomic SubSystem: '<Root>/PP2ActiveDet' */
  /* Outputs for Atomic SubSystem: '<Root>/Handshake2Quit' */
  /* Outputs for Atomic SubSystem: '<Root>/Hand2PrkCtrlDet' */
  /* Outputs for Atomic SubSystem: '<Root>/Prepare2QuitDet' */
  /* Outputs for Atomic SubSystem: '<Root>/Active2PrepareDet' */
  /* Outputs for Atomic SubSystem: '<Root>/Active2CompleteDet' */
  /* RelationalOperator: '<S1>/Equal1' incorporates:
   *  RelationalOperator: '<S10>/Equal4'
   *  RelationalOperator: '<S11>/Equal1'
   *  RelationalOperator: '<S1>/Equal8'
   *  RelationalOperator: '<S20>/Equal4'
   *  RelationalOperator: '<S23>/Equal1'
   *  RelationalOperator: '<S23>/Equal3'
   *  RelationalOperator: '<S25>/Equal1'
   *  RelationalOperator: '<S2>/Equal1'
   *  RelationalOperator: '<S2>/Equal3'
   */
  eLsadSystemSts = rtu_sLastMasterLsadFsm->eLsadSystemSts;

  /* End of Outputs for SubSystem: '<Root>/Active2PrepareDet' */
  /* End of Outputs for SubSystem: '<Root>/Prepare2QuitDet' */
  /* End of Outputs for SubSystem: '<Root>/Hand2PrkCtrlDet' */
  /* End of Outputs for SubSystem: '<Root>/Handshake2Quit' */
  /* End of Outputs for SubSystem: '<Root>/PP2ActiveDet' */
  /* End of Outputs for SubSystem: '<Root>/Quit2IdleDet' */

  /* Logic: '<S1>/Logical Operator1' incorporates:
   *  Constant: '<S32>/Constant'
   *  Constant: '<S33>/Constant'
   *  Constant: '<S34>/Constant'
   *  Constant: '<S35>/Constant'
   *  Constant: '<S36>/Constant'
   *  Constant: '<S37>/Constant'
   *  Constant: '<S39>/Constant'
   *  Constant: '<S40>/Constant'
   *  Logic: '<S1>/EMAND'
   *  Logic: '<S1>/EMAND1'
   *  Logic: '<S1>/EMAND2'
   *  Logic: '<S1>/EMNOT'
   *  Logic: '<S1>/EMOR'
   *  Logic: '<S1>/OR'
   *  Logic: '<S1>/OR1'
   *  RelationalOperator: '<S1>/Equal1'
   *  RelationalOperator: '<S1>/Equal10'
   *  RelationalOperator: '<S1>/Equal2'
   *  RelationalOperator: '<S1>/Equal3'
   *  RelationalOperator: '<S1>/Equal6'
   *  RelationalOperator: '<S1>/Equal7'
   *  RelationalOperator: '<S1>/Equal8'
   *  RelationalOperator: '<S1>/Equal9'
   */
  bActive2Complete = ((boolean_T)((int32_T)(((eLsadSystemSts == LSAD_STS_ACTIVE)
    ? ((int32_T)1) : ((int32_T)0)) | ((eLsadSystemSts == LSAD_STS_ACTIVE_SUSPEND)
    ? ((int32_T)1) : ((int32_T)0))))) & ((boolean_T)((int32_T)
    (((rtu_sRelatedModuleInfo->eCtrlSts == APA_CTRL_COMPLETE_APA) ? ((int32_T)1)
      : ((int32_T)0)) | (((boolean_T)((int32_T)
    (((rtu_sRelatedModuleInfo->eCtrlSts == APA_CTRL_COMPLETE_HPP) ? ((int32_T)1)
      : ((int32_T)0)) & (((boolean_T)((int32_T)
    ((rtu_sVehCommon->sCondiPlatform.bRecomdSlot ? ((int32_T)1) : ((int32_T)0)) ^
     1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)))));

  /* End of Outputs for SubSystem: '<Root>/Active2CompleteDet' */

  /* Outputs for Atomic SubSystem: '<Root>/Active2PrepareDet' */
  /* Logic: '<S2>/AND1' incorporates:
   *  Constant: '<S42>/Constant'
   *  Constant: '<S43>/Constant'
   *  Constant: '<S44>/Constant'
   *  Constant: '<S45>/Constant'
   *  Logic: '<S2>/AND'
   *  RelationalOperator: '<S2>/Equal1'
   *  RelationalOperator: '<S2>/Equal2'
   *  RelationalOperator: '<S2>/Equal3'
   *  RelationalOperator: '<S2>/Equal4'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  bActive2Prepare = ((boolean_T)((int32_T)((((boolean_T)((int32_T)
    (((eLsadSystemSts == LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0)) |
     ((eLsadSystemSts == LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0)))))
    ? ((int32_T)1) : ((int32_T)0)) & ((rtu_sSlaveLsadFsm->eLsadFuncType ==
    LSAD_PARK_IN) ? ((int32_T)1) : ((int32_T)0))))) &
    (master_lsad_fsm_DW.UnitDelay_DSTATE == LSAD_CRUISE);

  /* Update for UnitDelay: '<S2>/Unit Delay' */
  master_lsad_fsm_DW.UnitDelay_DSTATE = rtu_sSlaveLsadFsm->eLsadFuncType;

  /* End of Outputs for SubSystem: '<Root>/Active2PrepareDet' */

  /* Outputs for Atomic SubSystem: '<Root>/Active2SuspendDet' */
  /* Logic: '<S3>/OR' incorporates:
   *  Constant: '<S46>/Constant'
   *  Constant: '<S47>/Constant'
   *  Constant: '<S48>/Constant'
   *  RelationalOperator: '<S3>/Equal'
   *  RelationalOperator: '<S3>/Equal1'
   *  RelationalOperator: '<S3>/Equal2'
   */
  bActive2Suspend = ((boolean_T)((int32_T)
    (((rtu_sPaStateCommon->sPAEvnt.ePAIntrptEvnt != INTERRUPT_NONE) ? ((int32_T)
    1) : ((int32_T)0)) | ((rtu_sHpaStateCommon->sHPAEvnt.eHPAIntrptEvnt !=
    INTERRUPT_NONE) ? ((int32_T)1) : ((int32_T)0))))) |
    ((*rtu_sRaStateCommon_sRAEvnt_eRAIntrptEvnt) != RA_INTERRUPT_NONE);

  /* End of Outputs for SubSystem: '<Root>/Active2SuspendDet' */

  /* Outputs for Atomic SubSystem: '<Root>/Active2TerminateDet' */
  /* Logic: '<S4>/OR' incorporates:
   *  Constant: '<S49>/Constant'
   *  Constant: '<S50>/Constant'
   *  Constant: '<S51>/Constant'
   *  RelationalOperator: '<S4>/Equal'
   *  RelationalOperator: '<S4>/Equal1'
   *  RelationalOperator: '<S4>/Equal2'
   */
  bActive2Terminate = ((boolean_T)((int32_T)
    (((rtu_sPaStateCommon->sPAEvnt.ePATrmntEvnt != TERMINATE_NONE) ? ((int32_T)1)
      : ((int32_T)0)) | ((rtu_sHpaStateCommon->sHPAEvnt.eHPATrmntEvnt !=
    TERMINATE_NONE) ? ((int32_T)1) : ((int32_T)0))))) |
    ((*rtu_sRaStateCommon_sRAEvnt_eRATrmntEvnt) != RA_TERMINATE_NONE);

  /* End of Outputs for SubSystem: '<Root>/Active2TerminateDet' */

  /* Outputs for Atomic SubSystem: '<Root>/Enble2OffDet' */
  /* DataTypeConversion: '<S6>/Data Type Conversion' */
  bEnble2Off = rtu_sVehCommon->sCondiVeh.bSysPwrMdOff ? 1.0 : 0.0;

  /* End of Outputs for SubSystem: '<Root>/Enble2OffDet' */

  /* Outputs for Atomic SubSystem: '<Root>/Idle2FailDet' */
  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  master_lsad_fsm_DW.bStandby2Fail = rtu_sDiagInfo->bPASysFail ? 1.0 : 0.0;

  /* End of Outputs for SubSystem: '<Root>/Idle2FailDet' */

  /* Outputs for Atomic SubSystem: '<Root>/Fail2InhibitDet' */
  /* Outputs for Atomic SubSystem: '<Root>/Standby2InhibitDet' */
  /* Logic: '<S26>/Logical Operator1' incorporates:
   *  Logic: '<S8>/Logical Operator2'
   */
  bStandby2Inhibit_tmp = rtu_sVehCommon->sCondiVeh.bExterActualNorm ^ 1;

  /* End of Outputs for SubSystem: '<Root>/Fail2InhibitDet' */

  /* Logic: '<S26>/Logical Operator' incorporates:
   *  Constant: '<S26>/Constant23'
   *  Logic: '<S26>/Logical Operator1'
   *  RelationalOperator: '<S26>/Relational Operator8'
   */
  master_lsad_fsm_DW.bitsForTID0.bStandby2Inhibit = (boolean_T)((int32_T)
    ((((boolean_T)((int32_T)((((boolean_T)((int32_T)
    (((rtu_sVehDataRx->sVehESCInfo.f32VehSpdKph > k_PrkInSrchMaxSpd) ? ((int32_T)
    1) : ((int32_T)0)) | (bStandby2Inhibit_tmp ? ((int32_T)1) : ((int32_T)0)))))
    ? ((int32_T)1) : ((int32_T)0)) | (rtu_sVehDataRx->sVehVCUInfo.bHVOff ?
    ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
     (rtu_sVehDataRx->sVehESCInfo.bDAActive ? ((int32_T)1) : ((int32_T)0))));

  /* End of Outputs for SubSystem: '<Root>/Standby2InhibitDet' */

  /* Outputs for Atomic SubSystem: '<Root>/bStandby2PrepareDet' */
  /* Logic: '<S30>/AND' incorporates:
   *  Constant: '<S136>/Constant'
   *  Constant: '<S137>/Constant'
   *  Constant: '<S138>/Constant'
   *  Constant: '<S139>/Constant'
   *  RelationalOperator: '<S30>/Equal'
   *  RelationalOperator: '<S30>/Equal1'
   *  RelationalOperator: '<S30>/Equal2'
   *  RelationalOperator: '<S30>/Equal3'
   */
  master_lsad_fsm_DW.bitsForTID0.bStandby2Prepare = (boolean_T)((int32_T)
    ((((boolean_T)((int32_T)((((boolean_T)((int32_T)
    (((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_REMOTE_CONNECT) ?
      ((int32_T)1) : ((int32_T)0)) | ((rtu_sSlaveLsadFsm->eLsadFuncSts ==
    FUNC_STS_APA_MODE_SELECT) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_CRUISE_READY) ?
                     ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)
    0)) | ((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RA_READY) ? ((int32_T)1)
           : ((int32_T)0))));

  /* End of Outputs for SubSystem: '<Root>/bStandby2PrepareDet' */

  /* Outputs for Atomic SubSystem: '<Root>/Suspend2PrepareDet' */
  /* Logic: '<S28>/AND' incorporates:
   *  Constant: '<S125>/Constant'
   *  Constant: '<S126>/Constant'
   *  Constant: '<S127>/Constant'
   *  Constant: '<S128>/Constant'
   *  Constant: '<S129>/Constant'
   *  Constant: '<S130>/Constant'
   *  Constant: '<S131>/Constant'
   *  Constant: '<S132>/Constant'
   *  Constant: '<S133>/Constant'
   *  RelationalOperator: '<S28>/Equal'
   *  RelationalOperator: '<S28>/Equal1'
   *  RelationalOperator: '<S28>/Equal2'
   *  RelationalOperator: '<S28>/Equal3'
   *  RelationalOperator: '<S28>/Equal4'
   *  RelationalOperator: '<S28>/Equal5'
   *  RelationalOperator: '<S28>/Equal6'
   *  RelationalOperator: '<S28>/Equal7'
   *  RelationalOperator: '<S28>/Equal8'
   */
  master_lsad_fsm_DW.bitsForTID0.bSuspend2Prepare = (boolean_T)((int32_T)
    ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
    ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
    ((((boolean_T)((int32_T)(((rtu_sSlaveLsadFsm->eLsadFuncSts ==
    FUNC_STS_APA_PI_SEARCH) ? ((int32_T)1) : ((int32_T)0)) |
    ((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_CONFIRM) ? ((int32_T)1)
    : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
    ((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PO_CONFIRM) ? ((int32_T)1)
    : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
    ((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_PARK_STRAIGHT) ? ((int32_T)
    1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
    ((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_PO_CONFIRM) ? ((int32_T)1)
     : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
     ((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_PI_SEARCH) ? ((int32_T)1)
      : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
    ((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_PI_CONFIRM) ? ((int32_T)1)
     : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
    ((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_REMOTE_OK) ? ((int32_T)1) :
     ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
     ((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_REMOTE_CONNECT) ?
      ((int32_T)1) : ((int32_T)0))));

  /* End of Outputs for SubSystem: '<Root>/Suspend2PrepareDet' */

  /* Outputs for Atomic SubSystem: '<Root>/Prepare2SuspendDet' */
  /* Logic: '<S24>/AND' incorporates:
   *  Constant: '<S77>/Constant'
   *  Constant: '<S78>/Constant'
   *  Constant: '<S79>/Constant'
   *  RelationalOperator: '<S24>/Equal'
   *  RelationalOperator: '<S24>/Equal1'
   *  RelationalOperator: '<S24>/Equal2'
   */
  master_lsad_fsm_DW.bitsForTID0.bPrepare2Suspend = (boolean_T)((int32_T)
    ((((boolean_T)((int32_T)(((rtu_sSlaveLsadFsm->eLsadFuncSts ==
    FUNC_STS_APA_PI_SUPPRESSION) ? ((int32_T)1) : ((int32_T)0)) |
    ((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PO_SUPPRESSION) ?
     ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
     ((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_PI_SUPPRESSION) ?
      ((int32_T)1) : ((int32_T)0))));

  /* End of Outputs for SubSystem: '<Root>/Prepare2SuspendDet' */

  /* Outputs for Atomic SubSystem: '<Root>/Prepare2QuitDet' */
  /* Logic: '<S23>/AND' incorporates:
   *  Constant: '<S71>/Constant'
   *  Constant: '<S72>/Constant'
   *  Constant: '<S73>/Constant'
   *  Logic: '<S23>/AND1'
   *  RelationalOperator: '<S23>/Equal1'
   *  RelationalOperator: '<S23>/Equal2'
   *  RelationalOperator: '<S23>/Equal3'
   */
  master_lsad_fsm_DW.bitsForTID0.bPrepare2Quit = (boolean_T)((int32_T)
    ((((boolean_T)((int32_T)(((eLsadSystemSts == LSAD_STS_PREPARE) ? ((int32_T)1)
    : ((int32_T)0)) | ((eLsadSystemSts == LSAD_STS_PREPARE_SUSPEND) ? ((int32_T)
    1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
     ((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_QUIT) ? ((int32_T)1) :
      ((int32_T)0))));

  /* End of Outputs for SubSystem: '<Root>/Prepare2QuitDet' */

  /* Outputs for Atomic SubSystem: '<Root>/Prepare2HandshakeDet' */
  /* Logic: '<S22>/AND' incorporates:
   *  Constant: '<S69>/Constant'
   *  Constant: '<S70>/Constant'
   *  RelationalOperator: '<S22>/Equal'
   *  RelationalOperator: '<S22>/Equal1'
   */
  master_lsad_fsm_DW.bitsForTID0.bPrepare2Handshake = (boolean_T)((int32_T)
    (((rtu_sSlaveLsadFsm->eLsadFuncType != LSAD_FUNC_TYPE_NONE) ? ((int32_T)1) :
      ((int32_T)0)) & ((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_AFTER_SELECT)
                       ? ((int32_T)1) : ((int32_T)0))));

  /* End of Outputs for SubSystem: '<Root>/Prepare2HandshakeDet' */

  /* Outputs for Atomic SubSystem: '<Root>/Hand2PrkCtrlDet' */
  /* Logic: '<S10>/Logical Operator5' incorporates:
   *  Constant: '<S50>/Constant'
   *  Constant: '<S51>/Constant'
   *  Logic: '<S10>/Logical Operator'
   *  RelationalOperator: '<S10>/Equal3'
   *  RelationalOperator: '<S10>/Equal4'
   */
  master_lsad_fsm_DW.bitsForTID0.bHandshake2PP = (boolean_T)((int32_T)
    ((((boolean_T)((int32_T)(((eLsadSystemSts == LSAD_STS_HANDSHAKE) ? ((int32_T)
    1) : ((int32_T)0)) & (rtu_sVehCommon->sCondiVeh.bVehStill ? ((int32_T)1) :
    ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
     ((rtu_sRelatedModuleInfo->eHandshakeSts == HANDSHAKE_SUCCESS) ? ((int32_T)1)
      : ((int32_T)0))));

  /* End of Outputs for SubSystem: '<Root>/Hand2PrkCtrlDet' */

  /* Outputs for Atomic SubSystem: '<Root>/Handshake2Quit' */
  /* Logic: '<S11>/AND' incorporates:
   *  Constant: '<S52>/Constant'
   *  Constant: '<S53>/Constant'
   *  RelationalOperator: '<S11>/Equal1'
   *  RelationalOperator: '<S11>/Equal2'
   */
  master_lsad_fsm_DW.bitsForTID0.bHandshake2Quit = (boolean_T)((int32_T)
    (((eLsadSystemSts == LSAD_STS_HANDSHAKE) ? ((int32_T)1) : ((int32_T)0)) &
     ((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_QUIT) ? ((int32_T)1) :
      ((int32_T)0))));

  /* End of Outputs for SubSystem: '<Root>/Handshake2Quit' */

  /* Outputs for Atomic SubSystem: '<Root>/Handshake2TerminateDet' */
  /* Logic: '<S12>/OR' incorporates:
   *  Constant: '<S54>/Constant'
   *  Constant: '<S55>/Constant'
   *  Constant: '<S56>/Constant'
   *  RelationalOperator: '<S12>/Equal'
   *  RelationalOperator: '<S12>/Equal1'
   *  RelationalOperator: '<S12>/Equal2'
   */
  master_lsad_fsm_DW.bitsForTID0.bHandshake2Terminate = (boolean_T)((int32_T)
    ((((boolean_T)((int32_T)(((rtu_sPaStateCommon->sPAEvnt.ePATrmntEvnt !=
    TERMINATE_NONE) ? ((int32_T)1) : ((int32_T)0)) |
    ((rtu_sHpaStateCommon->sHPAEvnt.eHPATrmntEvnt != TERMINATE_NONE) ? ((int32_T)
    1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
     (((*rtu_sRaStateCommon_sRAEvnt_eRATrmntEvnt) != RA_TERMINATE_NONE) ?
      ((int32_T)1) : ((int32_T)0))));

  /* End of Outputs for SubSystem: '<Root>/Handshake2TerminateDet' */

  /* Outputs for Atomic SubSystem: '<Root>/PP2ActiveDet' */
  /* Logic: '<S20>/Logical Operator' incorporates:
   *  Constant: '<S63>/Constant'
   *  Constant: '<S64>/Constant'
   *  Constant: '<S65>/Constant'
   *  Logic: '<S20>/EMOR'
   *  RelationalOperator: '<S20>/Equal1'
   *  RelationalOperator: '<S20>/Equal2'
   *  RelationalOperator: '<S20>/Equal4'
   */
  master_lsad_fsm_DW.bitsForTID0.bPP2Active = (boolean_T)((int32_T)
    (((eLsadSystemSts == LSAD_STS_PP) ? ((int32_T)1) : ((int32_T)0)) &
     (((boolean_T)((int32_T)(((rtu_sRelatedModuleInfo->ePathPlanSts ==
    APA_PATH_PLAN_SUCCESS) ? ((int32_T)1) : ((int32_T)0)) |
    ((rtu_sSlaveLsadFsm->eLsadFuncType == LSAD_PARK_STRAIGHT) ? ((int32_T)1) :
     ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))));

  /* End of Outputs for SubSystem: '<Root>/PP2ActiveDet' */

  /* Outputs for Atomic SubSystem: '<Root>/PP2TerminateDet' */
  /* Logic: '<S21>/OR' incorporates:
   *  Constant: '<S66>/Constant'
   *  Constant: '<S67>/Constant'
   *  Constant: '<S68>/Constant'
   *  RelationalOperator: '<S21>/Equal'
   *  RelationalOperator: '<S21>/Equal1'
   *  RelationalOperator: '<S21>/Equal2'
   */
  master_lsad_fsm_DW.bitsForTID0.bPP2Terminate = (boolean_T)((int32_T)
    ((((boolean_T)((int32_T)(((rtu_sPaStateCommon->sPAEvnt.ePATrmntEvnt !=
    TERMINATE_NONE) ? ((int32_T)1) : ((int32_T)0)) |
    ((rtu_sHpaStateCommon->sHPAEvnt.eHPATrmntEvnt != TERMINATE_NONE) ? ((int32_T)
    1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
     (((*rtu_sRaStateCommon_sRAEvnt_eRATrmntEvnt) != RA_TERMINATE_NONE) ?
      ((int32_T)1) : ((int32_T)0))));

  /* End of Outputs for SubSystem: '<Root>/PP2TerminateDet' */

  /* Outputs for Atomic SubSystem: '<Root>/Suspend2ActiveDet' */
  /* Logic: '<S27>/AND10' incorporates:
   *  Constant: '<S105>/Constant'
   *  Constant: '<S106>/Constant'
   *  Constant: '<S107>/Constant'
   *  RelationalOperator: '<S27>/Equal6'
   *  RelationalOperator: '<S27>/Equal7'
   *  RelationalOperator: '<S27>/Equal8'
   */
  LocalVar_AND10 = ((boolean_T)((int32_T)
    (((rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkWorkMd == PRK_WORK_START) ? ((int32_T)1) :
      ((int32_T)0)) | ((rtu_sPAHmiRx->sRCAHmiRx.eRCAPrkDircMd == RCA_PRK_AHEAD) ?
                       ((int32_T)1) : ((int32_T)0))))) |
    (rtu_sPAHmiRx->sRCAHmiRx.eRCAPrkDircMd == RCA_PRK_BACK);

  /* Logic: '<S27>/Logical Operator10' incorporates:
   *  Constant: '<S102>/Constant'
   *  Constant: '<S95>/Constant'
   *  RelationalOperator: '<S27>/Equal2'
   *  RelationalOperator: '<S27>/Equal3'
   */
  LocalVar_bNeedContinue = (rtu_sPaStateCommon->sPAEvnt.ePAIntrptType ==
    INTERRUPTION_NEED_CONFIRM) & (rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkWorkMd ==
    PRK_WORK_CONTINUE);

  /* Logic: '<S114>/OR1' incorporates:
   *  Logic: '<S114>/NOT'
   *  Logic: '<S114>/OR'
   *  UnitDelay: '<S114>/Unit Delay2'
   *  UnitDelay: '<S79>/Unit Delay1'
   */
  LocalVar_OR1 = LocalVar_bNeedContinue | ((boolean_T)((int32_T)((((boolean_T)
    ((int32_T)((master_lsad_fsm_DW.bitsForTID0.UnitDelay1_DSTATE_k ? ((int32_T)1)
                : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)) &
    (master_lsad_fsm_DW.bitsForTID0.UnitDelay2_DSTATE ? ((int32_T)1) : ((int32_T)
    0)))));

  /* Switch: '<S115>/Switch1' incorporates:
   *  Constant: '<S115>/Constant Value2'
   *  Logic: '<S79>/Logical Operator1'
   *  Switch: '<S115>/Switch'
   *  UnitDelay: '<S115>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)((LocalVar_OR1 ? ((int32_T)1) : ((int32_T)0)) ^ 1)))
  {
    master_lsad_fsm_DW.UnitDelay1_DSTATE = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S115>/Unit Delay1' incorporates:
     *  Constant: '<S79>/Constant9'
     *  Sum: '<S115>/Subtraction'
     */
    master_lsad_fsm_DW.UnitDelay1_DSTATE += 0.02F;
  }

  /* End of Switch: '<S115>/Switch1' */

  /* RelationalOperator: '<S79>/Relational Operator5' incorporates:
   *  Constant: '<S79>/Constant8'
   *  UnitDelay: '<S115>/Unit Delay1'
   */
  LocalVar_bBlindUnLockNeedContinue = (master_lsad_fsm_DW.UnitDelay1_DSTATE >
    0.5F);

  /* Logic: '<S27>/Logical Operator12' incorporates:
   *  Constant: '<S101>/Constant'
   *  Constant: '<S99>/Constant'
   *  RelationalOperator: '<S27>/Equal25'
   *  RelationalOperator: '<S27>/Equal26'
   */
  LocalVar_bNeedContinue_c = ((*rtu_sRaStateCommon_sRAEvnt_eRAIntrptType) ==
    RA_INTERRUPTION_NEED_CONFIRM) & (rtu_sRAHmiRx->eRAPrkWorkMd ==
    PRK_WORK_CONTINUE);

  /* Logic: '<S116>/OR1' incorporates:
   *  Logic: '<S116>/NOT'
   *  Logic: '<S116>/OR'
   *  UnitDelay: '<S116>/Unit Delay2'
   *  UnitDelay: '<S80>/Unit Delay1'
   */
  LocalVar_OR1_j = LocalVar_bNeedContinue_c | ((boolean_T)((int32_T)
    ((((boolean_T)((int32_T)
                   ((master_lsad_fsm_DW.bitsForTID0.UnitDelay1_DSTATE_ks ?
                     ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) :
      ((int32_T)0)) & (master_lsad_fsm_DW.bitsForTID0.UnitDelay2_DSTATE_f ?
                       ((int32_T)1) : ((int32_T)0)))));

  /* Switch: '<S117>/Switch1' incorporates:
   *  Constant: '<S117>/Constant Value2'
   *  Logic: '<S80>/Logical Operator1'
   *  Switch: '<S117>/Switch'
   *  UnitDelay: '<S117>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)((LocalVar_OR1_j ? ((int32_T)1) : ((int32_T)0)) ^ 1)))
  {
    master_lsad_fsm_DW.UnitDelay1_DSTATE_i = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S117>/Unit Delay1' incorporates:
     *  Constant: '<S80>/Constant9'
     *  Sum: '<S117>/Subtraction'
     */
    master_lsad_fsm_DW.UnitDelay1_DSTATE_i += 0.02F;
  }

  /* End of Switch: '<S117>/Switch1' */

  /* RelationalOperator: '<S80>/Relational Operator5' incorporates:
   *  Constant: '<S80>/Constant8'
   *  UnitDelay: '<S117>/Unit Delay1'
   */
  LocalVar_bBlindUnLockNeedContinue_a = (master_lsad_fsm_DW.UnitDelay1_DSTATE_i >
    0.5F);

  /* Logic: '<S27>/Logical Operator11' incorporates:
   *  Constant: '<S91>/Constant'
   *  Constant: '<S92>/Constant'
   *  RelationalOperator: '<S27>/Equal21'
   *  RelationalOperator: '<S27>/Equal22'
   */
  LocalVar_bNeedContinue_o = (rtu_sHpaStateCommon->sHPAEvnt.eHPAIntrptType ==
    INTERRUPTION_NEED_CONFIRM) & (rtu_sHPAHmiRx->eHPAPrkWorkMd ==
    PRK_WORK_CONTINUE);

  /* Logic: '<S118>/OR1' incorporates:
   *  Logic: '<S118>/NOT'
   *  Logic: '<S118>/OR'
   *  UnitDelay: '<S118>/Unit Delay2'
   *  UnitDelay: '<S81>/Unit Delay1'
   */
  LocalVar_OR1_g = LocalVar_bNeedContinue_o | ((boolean_T)((int32_T)
    ((((boolean_T)((int32_T)((master_lsad_fsm_DW.bitsForTID0.UnitDelay1_DSTATE_e
    ? ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)) &
     (master_lsad_fsm_DW.bitsForTID0.UnitDelay2_DSTATE_a ? ((int32_T)1) :
      ((int32_T)0)))));

  /* Switch: '<S119>/Switch1' incorporates:
   *  Constant: '<S119>/Constant Value2'
   *  Logic: '<S81>/Logical Operator1'
   *  Switch: '<S119>/Switch'
   *  UnitDelay: '<S119>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)((LocalVar_OR1_g ? ((int32_T)1) : ((int32_T)0)) ^ 1)))
  {
    master_lsad_fsm_DW.UnitDelay1_DSTATE_a = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S119>/Unit Delay1' incorporates:
     *  Constant: '<S81>/Constant9'
     *  Sum: '<S119>/Subtraction'
     */
    master_lsad_fsm_DW.UnitDelay1_DSTATE_a += 0.02F;
  }

  /* End of Switch: '<S119>/Switch1' */

  /* RelationalOperator: '<S81>/Relational Operator5' incorporates:
   *  Constant: '<S81>/Constant8'
   *  UnitDelay: '<S119>/Unit Delay1'
   */
  LocalVar_bBlindUnLockNeedContinue_p = (master_lsad_fsm_DW.UnitDelay1_DSTATE_a >
    0.5F);

  /* RelationalOperator: '<S82>/Relational Operator' incorporates:
   *  Delay: '<S82>/Delay'
   */
  LocalVar_RelationalOperator = (((int32_T)(LocalVar_AND10 ? 1 : 0)) > ((int32_T)
    (master_lsad_fsm_DW.bitsForTID0.Delay_DSTATE ? 1 : 0)));

  /* Logic: '<S120>/OR1' incorporates:
   *  Logic: '<S120>/NOT'
   *  Logic: '<S120>/OR'
   *  UnitDelay: '<S109>/Unit Delay1'
   *  UnitDelay: '<S120>/Unit Delay2'
   */
  LocalVar_OR1_f = LocalVar_RelationalOperator | ((boolean_T)((int32_T)
    ((((boolean_T)((int32_T)((master_lsad_fsm_DW.bitsForTID0.UnitDelay1_DSTATE_o
    ? ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)) &
     (master_lsad_fsm_DW.bitsForTID0.UnitDelay2_DSTATE_l ? ((int32_T)1) :
      ((int32_T)0)))));

  /* Switch: '<S121>/Switch1' incorporates:
   *  Constant: '<S121>/Constant Value2'
   *  Logic: '<S109>/Logical Operator1'
   *  Switch: '<S121>/Switch'
   *  UnitDelay: '<S121>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)((LocalVar_OR1_f ? ((int32_T)1) : ((int32_T)0)) ^ 1)))
  {
    master_lsad_fsm_DW.UnitDelay1_DSTATE_g = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S121>/Unit Delay1' incorporates:
     *  Constant: '<S109>/Constant9'
     *  Sum: '<S121>/Subtraction'
     */
    master_lsad_fsm_DW.UnitDelay1_DSTATE_g += 0.02F;
  }

  /* End of Switch: '<S121>/Switch1' */

  /* RelationalOperator: '<S109>/Relational Operator5' incorporates:
   *  Constant: '<S109>/Constant8'
   *  UnitDelay: '<S121>/Unit Delay1'
   */
  LocalVar_bBlindUnLockNeedContinue_n = (master_lsad_fsm_DW.UnitDelay1_DSTATE_g >
    0.5F);

  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<S83>/Constant'
   *  Constant: '<S87>/Constant'
   *  Constant: '<S88>/Constant'
   *  Constant: '<S89>/Constant'
   *  Constant: '<S94>/Constant'
   *  Logic: '<S27>/OR'
   *  RelationalOperator: '<S27>/Equal'
   *  RelationalOperator: '<S27>/Equal12'
   *  RelationalOperator: '<S27>/Equal13'
   *  RelationalOperator: '<S27>/Equal14'
   *  RelationalOperator: '<S27>/Equal19'
   *  Switch: '<S27>/Switch1'
   *  Switch: '<S27>/Switch2'
   */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
           (((rtu_sSlaveLsadFsm->eLsadFuncType == LSAD_PARK_IN) ? ((int32_T)1) :
             ((int32_T)0)) | ((rtu_sSlaveLsadFsm->eLsadFuncType == LSAD_PARK_OUT)
             ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
        ((rtu_sSlaveLsadFsm->eLsadFuncType == LSAD_PARK_STRAIGHT) ? ((int32_T)1)
         : ((int32_T)0)))))
  {
    /* Switch: '<S110>/Switch' incorporates:
     *  Constant: '<S85>/Constant'
     *  RelationalOperator: '<S27>/Equal10'
     *  Switch: '<S111>/Switch'
     */
    if (rtu_sPaStateCommon->sPAEvnt.ePAIntrptEvnt == INTERRUPT_OBSTACLE)
    {
      LocalVar_bNeedContinue = LocalVar_bBlindUnLockNeedContinue;
      LocalVar_RelationalOperator = LocalVar_bBlindUnLockNeedContinue_n;
    }

    /* End of Switch: '<S110>/Switch' */

    /* Switch: '<S27>/Switch' incorporates:
     *  Constant: '<S103>/Constant'
     *  Constant: '<S104>/Constant'
     *  Constant: '<S108>/Constant'
     *  Constant: '<S84>/Constant'
     *  Logic: '<S27>/Logical Operator1'
     *  Logic: '<S27>/Logical Operator3'
     *  Logic: '<S27>/Logical Operator4'
     *  Logic: '<S27>/Logical Operator5'
     *  Logic: '<S27>/Logical Operator6'
     *  Logic: '<S27>/Logical Operator7'
     *  RelationalOperator: '<S27>/Equal1'
     *  RelationalOperator: '<S27>/Equal4'
     *  RelationalOperator: '<S27>/Equal5'
     *  RelationalOperator: '<S27>/Equal9'
     */
    master_lsad_fsm_DW.bitsForTID0.bSuspend2Active = (boolean_T)((int32_T)
      ((((boolean_T)((int32_T)(((rtu_sPaStateCommon->sPAEvnt.ePAIntrptEvnt ==
      INTERRUPT_NONE) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)(((rtu_sPaStateAdptr->sCondiHMI.ePrkFnct ==
      PARK_FUNC_APA) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
      (((rtu_sPaStateCommon->sPAEvnt.ePAIntrptType == INTERRUPTION_NO_CONFIRM) ?
        ((int32_T)1) : ((int32_T)0)) | (LocalVar_bNeedContinue ? ((int32_T)1) :
      ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
        ((int32_T)0)) | (((boolean_T)((int32_T)
      (((rtu_sPaStateAdptr->sCondiHMI.ePrkFnct == PARK_FUNC_RPA) ? ((int32_T)1) :
        ((int32_T)0)) & (LocalVar_RelationalOperator ? ((int32_T)1) : ((int32_T)
      0))))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)))))
        ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
      ((rtu_sPaStateCommon->sCondiOverFlag.bIntrptOvertime ? ((int32_T)1) :
        ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))));
  }
  else if (rtu_sSlaveLsadFsm->eLsadFuncType == LSAD_CRUISE)
  {
    /* Switch: '<S113>/Switch' incorporates:
     *  Constant: '<S96>/Constant'
     *  RelationalOperator: '<S27>/Equal20'
     *  Switch: '<S27>/Switch1'
     */
    if (rtu_sHpaStateCommon->sHPAEvnt.eHPAIntrptEvnt == INTERRUPT_OBSTACLE)
    {
      LocalVar_bNeedContinue_o = LocalVar_bBlindUnLockNeedContinue_p;
    }

    /* End of Switch: '<S113>/Switch' */

    /* Switch: '<S27>/Switch' incorporates:
     *  Constant: '<S90>/Constant'
     *  Constant: '<S93>/Constant'
     *  Logic: '<S27>/Logical Operator14'
     *  Logic: '<S27>/Logical Operator2'
     *  Logic: '<S27>/OR1'
     *  RelationalOperator: '<S27>/Equal18'
     *  RelationalOperator: '<S27>/Equal27'
     *  Switch: '<S27>/Switch1'
     */
    master_lsad_fsm_DW.bitsForTID0.bSuspend2Active = (boolean_T)((int32_T)
      ((((boolean_T)((int32_T)(((rtu_sHpaStateCommon->sHPAEvnt.eHPAIntrptEvnt ==
      INTERRUPT_NONE) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
      (((rtu_sHpaStateCommon->sHPAEvnt.eHPAIntrptType == INTERRUPTION_NO_CONFIRM)
        ? ((int32_T)1) : ((int32_T)0)) | (LocalVar_bNeedContinue_o ? ((int32_T)1)
      : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
        ((int32_T)0)) & (((boolean_T)((int32_T)
      ((rtu_sHpaStateCommon->sHPACondiOverFlag.bHpaIntrptOvertime ? ((int32_T)1)
        : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))));
  }
  else if (rtu_sSlaveLsadFsm->eLsadFuncType == LSAD_RA)
  {
    /* Logic: '<S27>/Logical Operator9' incorporates:
     *  Switch: '<S27>/Switch1'
     *  Switch: '<S27>/Switch2'
     */
    LocalVar_bNeedContinue =
      (*rtu_sRaStateCommon_sRACondiOverFlag_bRAIntrptOvertime) ^ 1;

    /* Switch: '<S112>/Switch' incorporates:
     *  Constant: '<S98>/Constant'
     *  RelationalOperator: '<S27>/Equal24'
     *  Switch: '<S27>/Switch1'
     *  Switch: '<S27>/Switch2'
     */
    if ((*rtu_sRaStateCommon_sRAEvnt_eRAIntrptEvnt) == RA_INTERRUPT_OBSTACLE)
    {
      LocalVar_bNeedContinue_c = LocalVar_bBlindUnLockNeedContinue_a;
    }

    /* End of Switch: '<S112>/Switch' */

    /* Switch: '<S27>/Switch' incorporates:
     *  Constant: '<S100>/Constant'
     *  Constant: '<S97>/Constant'
     *  Logic: '<S27>/Logical Operator13'
     *  Logic: '<S27>/OR2'
     *  RelationalOperator: '<S27>/Equal23'
     *  RelationalOperator: '<S27>/Equal28'
     *  Switch: '<S27>/Switch1'
     *  Switch: '<S27>/Switch2'
     */
    master_lsad_fsm_DW.bitsForTID0.bSuspend2Active = (boolean_T)((int32_T)
      ((((boolean_T)((int32_T)((((*rtu_sRaStateCommon_sRAEvnt_eRAIntrptEvnt) ==
      RA_INTERRUPT_NONE) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
      ((((*rtu_sRaStateCommon_sRAEvnt_eRAIntrptType) ==
         RA_INTERRUPTION_NO_CONFIRM) ? ((int32_T)1) : ((int32_T)0)) |
       (LocalVar_bNeedContinue_c ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
      : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
       (LocalVar_bNeedContinue ? ((int32_T)1) : ((int32_T)0))));
  }
  else
  {
    /* Switch: '<S27>/Switch' incorporates:
     *  Constant: '<S27>/Constant'
     *  Switch: '<S27>/Switch1'
     *  Switch: '<S27>/Switch2'
     */
    master_lsad_fsm_DW.bitsForTID0.bSuspend2Active = false;
  }

  /* End of Switch: '<S27>/Switch' */

  /* Update for UnitDelay: '<S79>/Unit Delay1' */
  master_lsad_fsm_DW.bitsForTID0.UnitDelay1_DSTATE_k =
    LocalVar_bBlindUnLockNeedContinue;

  /* Update for UnitDelay: '<S114>/Unit Delay2' */
  master_lsad_fsm_DW.bitsForTID0.UnitDelay2_DSTATE = LocalVar_OR1;

  /* Update for UnitDelay: '<S80>/Unit Delay1' */
  master_lsad_fsm_DW.bitsForTID0.UnitDelay1_DSTATE_ks =
    LocalVar_bBlindUnLockNeedContinue_a;

  /* Update for UnitDelay: '<S116>/Unit Delay2' */
  master_lsad_fsm_DW.bitsForTID0.UnitDelay2_DSTATE_f = LocalVar_OR1_j;

  /* Update for UnitDelay: '<S81>/Unit Delay1' */
  master_lsad_fsm_DW.bitsForTID0.UnitDelay1_DSTATE_e =
    LocalVar_bBlindUnLockNeedContinue_p;

  /* Update for UnitDelay: '<S118>/Unit Delay2' */
  master_lsad_fsm_DW.bitsForTID0.UnitDelay2_DSTATE_a = LocalVar_OR1_g;

  /* Update for Delay: '<S82>/Delay' */
  master_lsad_fsm_DW.bitsForTID0.Delay_DSTATE = LocalVar_AND10;

  /* Update for UnitDelay: '<S109>/Unit Delay1' */
  master_lsad_fsm_DW.bitsForTID0.UnitDelay1_DSTATE_o =
    LocalVar_bBlindUnLockNeedContinue_n;

  /* Update for UnitDelay: '<S120>/Unit Delay2' */
  master_lsad_fsm_DW.bitsForTID0.UnitDelay2_DSTATE_l = LocalVar_OR1_f;

  /* End of Outputs for SubSystem: '<Root>/Suspend2ActiveDet' */

  /* Outputs for Atomic SubSystem: '<Root>/Complete2StandbyDet' */
  /* Logic: '<S5>/Logical Operator3' */
  LocalVar_AND10 = ((boolean_T)((int32_T)
    (((*rtu_sRaStateCommon_sRACondiOverFlag_bRACmpltDurattime) ? ((int32_T)1) :
      ((int32_T)0)) | (rtu_sPaStateCommon->sCondiOverFlag.bCmpltDurattime ?
                       ((int32_T)1) : ((int32_T)0))))) |
    rtu_sHpaStateCommon->sHPACondiOverFlag.bHpaCmpltDurattime;

  /* Logic: '<S5>/Logical Operator1' incorporates:
   *  Constant: '<S49>/Constant'
   *  Logic: '<S5>/Logical Operator2'
   *  RelationalOperator: '<S5>/Equal2'
   */
  master_lsad_fsm_DW.bitsForTID0.bComplete2Standby = (boolean_T)((int32_T)
    ((((boolean_T)((int32_T)((((boolean_T)((int32_T)
    (((*rtu_sRaStateCommon_sRACondiOverFlag_bRACmpltOvertime) ? ((int32_T)1) :
      ((int32_T)0)) | (rtu_sHpaStateCommon->sHPACondiOverFlag.bHpaCmpltOvertime ?
                       ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | (rtu_sPaStateCommon->sCondiOverFlag.bCmpltOvertime ?
                     ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)
    0)) | (((boolean_T)((int32_T)((LocalVar_AND10 ? ((int32_T)1) : ((int32_T)0))
    & ((rtu_sRelatedModuleInfo->eHandshakeSts == HANDSHAKE_UNCONTROLLED) ?
       ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))));

  /* End of Outputs for SubSystem: '<Root>/Complete2StandbyDet' */

  /* Outputs for Atomic SubSystem: '<Root>/Terminate2StandbyDet' */
  /* Logic: '<S29>/Logical Operator2' */
  LocalVar_AND10 = ((boolean_T)((int32_T)
    (((*rtu_sRaStateCommon_sRACondiOverFlag_bRATrmntDurattime) ? ((int32_T)1) :
      ((int32_T)0)) | (rtu_sHpaStateCommon->sHPACondiOverFlag.bHpaTrmntDurattime
                       ? ((int32_T)1) : ((int32_T)0))))) |
    rtu_sPaStateCommon->sCondiOverFlag.bTrmntDurattime;

  /* Logic: '<S29>/Logical Operator' incorporates:
   *  Constant: '<S134>/Constant'
   *  Constant: '<S135>/Constant'
   *  Logic: '<S29>/Logical Operator1'
   *  RelationalOperator: '<S29>/Equal1'
   *  RelationalOperator: '<S29>/Equal2'
   */
  master_lsad_fsm_DW.bitsForTID0.bTerminate2Standby = (boolean_T)((int32_T)
    ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
    (((*rtu_sRaStateCommon_sRACondiOverFlag_bRATrmntOvertime) ? ((int32_T)1) :
      ((int32_T)0)) | (rtu_sHpaStateCommon->sHPACondiOverFlag.bHpaTrmntOvertime ?
                       ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sPaStateCommon->sPAEvnt.ePATrmntEvnt ==
                      TERMINATE_RPA_BACK) ? ((int32_T)1) : ((int32_T)0))))) ?
    ((int32_T)1) : ((int32_T)0)) |
    (rtu_sPaStateCommon->sCondiOverFlag.bTrmntOvertime ? ((int32_T)1) :
     ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
    ((LocalVar_AND10 ? ((int32_T)1) : ((int32_T)0)) &
     ((rtu_sRelatedModuleInfo->eHandshakeSts == HANDSHAKE_UNCONTROLLED) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))));

  /* End of Outputs for SubSystem: '<Root>/Terminate2StandbyDet' */

  /* Outputs for Atomic SubSystem: '<Root>/Quit2IdleDet' */
  /* Logic: '<S25>/AND' incorporates:
   *  Constant: '<S80>/Constant'
   *  Constant: '<S81>/Constant'
   *  RelationalOperator: '<S25>/Equal1'
   *  RelationalOperator: '<S25>/Equal2'
   */
  master_lsad_fsm_DW.bitsForTID0.bQuit2Standby = (boolean_T)((int32_T)
    (((eLsadSystemSts == LSAD_STS_QUIT) ? ((int32_T)1) : ((int32_T)0)) &
     ((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_STANDBY) ? ((int32_T)1) :
      ((int32_T)0))));

  /* End of Outputs for SubSystem: '<Root>/Quit2IdleDet' */

  /* Chart: '<Root>/master_lsad_fsm_stateflow' incorporates:
   *  Constant: '<S14>/Constant1'
   *  Constant: '<S64>/Constant'
   *  Constant: '<S65>/Constant'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S8>/Constant'
   *  DataTypeConversion: '<S15>/Data Type Conversion'
   *  DataTypeConversion: '<S9>/Data Type Conversion'
   *  Logic: '<S14>/Logical Operator'
   *  Logic: '<S14>/Logical Operator1'
   *  Logic: '<S14>/Logical Operator2'
   *  Logic: '<S16>/Logical Operator2'
   *  Logic: '<S18>/Logical Operator'
   *  Logic: '<S18>/Logical Operator5'
   *  Logic: '<S19>/Logical Operator'
   *  Logic: '<S19>/Logical Operator1'
   *  Logic: '<S7>/Logical Operator'
   *  Logic: '<S7>/Logical Operator2'
   *  Logic: '<S7>/Logical Operator3'
   *  Logic: '<S7>/Logical Operator4'
   *  Logic: '<S7>/Logical Operator5'
   *  Logic: '<S8>/Logical Operator'
   *  Logic: '<S8>/Logical Operator2'
   *  Logic: '<S8>/Logical Operator3'
   *  Logic: '<S8>/Logical Operator5'
   *  RelationalOperator: '<S14>/EMSmallEqual'
   *  RelationalOperator: '<S18>/Equal'
   *  RelationalOperator: '<S19>/Equal'
   *  RelationalOperator: '<S7>/EMSmall'
   *  RelationalOperator: '<S8>/EMGreat'
   */
  if (((uint32_T)master_lsad_fsm_DW.bitsForTID0.is_active_c3_master_lsad_fsm) ==
      0U)
  {
    master_lsad_fsm_DW.bitsForTID0.is_active_c3_master_lsad_fsm = 1U;
    master_lsad_fsm_DW.bitsForTID0.is_c3_master_lsad_fsm =
      master_lsad_fsm_IN_Disable;
    master_lsad_fsm_DW.bitsForTID0.is_Disable = master_lsad_fsm_IN_Off;
    eLsadSystemSts = LSAD_STS_OFF;
  }
  else if (((uint32_T)master_lsad_fsm_DW.bitsForTID0.is_c3_master_lsad_fsm) ==
           master_lsad_fsm_IN_Disable)
  {
    switch (master_lsad_fsm_DW.bitsForTID0.is_Disable)
    {
     case master_lsad_fsm_IN_Failure:
      /* Outputs for Atomic SubSystem: '<Root>/Fail2InhibitDet' */
      /* Outputs for Atomic SubSystem: '<Root>/Fail2EnbleDet' */
      /* Logic: '<S7>/Logical Operator5' incorporates:
       *  Logic: '<S8>/Logical Operator5'
       */
      bActive2Complete = rtu_sDiagInfo->bPASysFail ^ 1;

      /* End of Outputs for SubSystem: '<Root>/Fail2InhibitDet' */
      if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
                   ((((boolean_T)((int32_T)((((boolean_T)((int32_T)
          ((bActive2Complete ? ((int32_T)1) : ((int32_T)0)) &
           ((rtu_sVehDataRx->sVehESCInfo.f32VehSpdKph <= k_PrkInSrchMaxSpd) ?
          ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
          (rtu_sVehCommon->sCondiVeh.bExterActualNorm ? ((int32_T)1) : ((int32_T)
          0))))) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
          ((rtu_sVehDataRx->sVehVCUInfo.bHVOff ? ((int32_T)1) : ((int32_T)0)) ^
           1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
                & (((boolean_T)((int32_T)((rtu_sVehDataRx->sVehESCInfo.bDAActive
        ? ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ?
             ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
               ((rtu_sVehDataRx->sVehBCMInfo.bMirrFld ? ((int32_T)1) : ((int32_T)
                  0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
      {
        master_lsad_fsm_DW.bitsForTID0.is_Disable =
          master_lsad_fsm_IN_NO_ACTIVE_CHILD;
        master_lsad_fsm_DW.bitsForTID0.is_c3_master_lsad_fsm =
          master_lsad_fsm_IN_Enable;
        master_lsad_fsm_DW.bitsForTID0.is_Enable = master_lsad_fsm_IN_Standby;
        eLsadSystemSts = LSAD_STS_STANDBY;
      }
      else
      {
        /* Outputs for Atomic SubSystem: '<Root>/Fail2InhibitDet' */
        if ((boolean_T)((int32_T)((bActive2Complete ? ((int32_T)1) : ((int32_T)0))
              & (((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
            ((int32_T)(((rtu_sVehDataRx->sVehESCInfo.f32VehSpdKph >
                         k_PrkInSrchMaxSpd) ? ((int32_T)1) : ((int32_T)0)) |
                       (bStandby2Inhibit_tmp ? ((int32_T)1) : ((int32_T)0))))) ?
          ((int32_T)1) : ((int32_T)0)) | (rtu_sVehDataRx->sVehVCUInfo.bHVOff ?
            ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
                  (rtu_sVehDataRx->sVehESCInfo.bDAActive ? ((int32_T)1) :
                   ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)))))
        {
          master_lsad_fsm_DW.bitsForTID0.is_Disable = master_lsad_fsm_IN_Inhibit;
          eLsadSystemSts = LSAD_STS_INHIBIT;
        }
        else
        {
          /* Outputs for Atomic SubSystem: '<Root>/Fail2OffDet' */
          if (rtu_sVehCommon->sCondiVeh.bSysPwrMdOff)
          {
            master_lsad_fsm_DW.bitsForTID0.is_Disable = master_lsad_fsm_IN_Off;
            eLsadSystemSts = LSAD_STS_OFF;
          }
          else
          {
            eLsadSystemSts = LSAD_STS_FAILURE;
          }

          /* End of Outputs for SubSystem: '<Root>/Fail2OffDet' */
        }

        /* End of Outputs for SubSystem: '<Root>/Fail2InhibitDet' */
      }

      /* End of Outputs for SubSystem: '<Root>/Fail2EnbleDet' */
      break;

     case master_lsad_fsm_IN_Inhibit:
      /* Outputs for Atomic SubSystem: '<Root>/Inhibit2FailDet' */
      if (rtu_sDiagInfo->bPASysFail)
      {
        master_lsad_fsm_DW.bitsForTID0.is_Disable = master_lsad_fsm_IN_Failure;
        eLsadSystemSts = LSAD_STS_FAILURE;
      }
      else
      {
        /* Outputs for Atomic SubSystem: '<Root>/Inhibit2OffDet' */
        if (rtu_sVehCommon->sCondiVeh.bSysPwrMdOff)
        {
          master_lsad_fsm_DW.bitsForTID0.is_Disable = master_lsad_fsm_IN_Off;
          eLsadSystemSts = LSAD_STS_OFF;
        }
        else
        {
          /* Outputs for Atomic SubSystem: '<Root>/Inhibit2EnbleDet' */
          if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
                      ((int32_T)(((rtu_sVehDataRx->sVehESCInfo.f32VehSpdKph <=
              k_PrkInSrchMaxSpd) ? ((int32_T)1) : ((int32_T)0)) &
                                 (rtu_sVehCommon->sCondiVeh.bExterActualNorm ?
                                  ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
                     : ((int32_T)0)) & (((boolean_T)((int32_T)
                       ((rtu_sVehDataRx->sVehVCUInfo.bHVOff ? ((int32_T)1) :
                         ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ?
                 ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
                   ((rtu_sVehDataRx->sVehESCInfo.bDAActive ? ((int32_T)1) :
                     ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
          {
            master_lsad_fsm_DW.bitsForTID0.is_Disable =
              master_lsad_fsm_IN_NO_ACTIVE_CHILD;
            master_lsad_fsm_DW.bitsForTID0.is_c3_master_lsad_fsm =
              master_lsad_fsm_IN_Enable;
            master_lsad_fsm_DW.bitsForTID0.is_Enable =
              master_lsad_fsm_IN_Standby;
            eLsadSystemSts = LSAD_STS_STANDBY;
          }
          else
          {
            eLsadSystemSts = LSAD_STS_INHIBIT;
          }

          /* End of Outputs for SubSystem: '<Root>/Inhibit2EnbleDet' */
        }

        /* End of Outputs for SubSystem: '<Root>/Inhibit2OffDet' */
      }

      /* End of Outputs for SubSystem: '<Root>/Inhibit2FailDet' */
      break;

     default:
      /* Outputs for Atomic SubSystem: '<Root>/Off2EnbleDet' */
      /* case IN_Off: */
      if ((boolean_T)((int32_T)(((rtu_sVehDataRx->sVehVCUInfo.eSysPwrMd ==
              SYS_PWR_MD_RUN) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)
              ((int32_T)((rtu_sDiagInfo->bPASysFail ? ((int32_T)1) : ((int32_T)0))
                         ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
      {
        master_lsad_fsm_DW.bitsForTID0.is_Disable =
          master_lsad_fsm_IN_NO_ACTIVE_CHILD;
        master_lsad_fsm_DW.bitsForTID0.is_c3_master_lsad_fsm =
          master_lsad_fsm_IN_Enable;
        master_lsad_fsm_DW.bitsForTID0.is_Enable = master_lsad_fsm_IN_Standby;
        eLsadSystemSts = LSAD_STS_STANDBY;
      }
      else
      {
        /* Outputs for Atomic SubSystem: '<Root>/Off2FailDet' */
        if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                 ((rtu_sDiagInfo->bPASysFail ? ((int32_T)1) : ((int32_T)0)) &
                  ((rtu_sVehDataRx->sVehVCUInfo.eSysPwrMd == SYS_PWR_MD_RUN) ?
                   ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
              & (rtu_sPaStateCommon->sCondiOverFlag.bPwrOnSelfChkDurattime ?
                 ((int32_T)1) : ((int32_T)0)))))
        {
          master_lsad_fsm_DW.bitsForTID0.is_Disable = master_lsad_fsm_IN_Failure;
          eLsadSystemSts = LSAD_STS_FAILURE;
        }
        else
        {
          eLsadSystemSts = LSAD_STS_OFF;
        }

        /* End of Outputs for SubSystem: '<Root>/Off2FailDet' */
      }

      /* End of Outputs for SubSystem: '<Root>/Off2EnbleDet' */
      break;
    }
  }
  else
  {
    /* case IN_Enable: */
    master_lsad_fsm_Enable(&eLsadSystemSts, &bActive2Complete, &bActive2Prepare,
      &bActive2Suspend, &bActive2Terminate, &bEnble2Off);
  }

  /* End of Chart: '<Root>/master_lsad_fsm_stateflow' */
  (void)memset(rty_sMasterLsadFsm, 0, sizeof(tMasterLsadFsm));

  /* BusAssignment: '<Root>/Bus Assignment' */
  rty_sMasterLsadFsm->eLsadSystemSts = eLsadSystemSts;
}

/* Model initialize function */
void master_lsad_fsm_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)&master_lsad_fsm_DW, 0,
                sizeof(DW_master_lsad_fsm_f_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
