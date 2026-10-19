/*
 * File: pa_state_adapter.c
 *
 * Code generated for Simulink model 'pa_state_adapter'.
 *
 * Model version                  : 3.2834
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Dec  2 15:46:04 2024
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

#include "pa_state_adapter.h"

/* Block states (default storage) */
#define CtrlPara_START_SEC_VAR
#include "proj_MemMap.h"
DW_pa_state_adapter_f_T pa_state_adapter_DW;
#define CtrlPara_STOP_SEC_VAR
#include "proj_MemMap.h"
/* Invariant block signals (default storage) */
const ConstB_pa_state_adapter_h_T pa_state_adapter_ConstB =
{
  {
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F
  },                                   /* '<Root>/Bus Assignment' */

  {
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,

    {
      0U, 0U, 0U
    }
  }                                    /* '<Root>/Bus Assignment1' */
};

/* Output and update for referenced model: 'pa_state_adapter' */
void pa_state_adapter(const tVehCommon *rtu_sVehCommon, const tPAHmiRx
                      *rtu_sPAHmiRx, const tVehDataRx *rtu_sVehDataRx, const
                      tMasterLsadFsm *rtu_sLastMasterLsadFsm, const tDiagInfo
                      *rtu_sDiagInfo, const tPaStateCommon *rtu_sPaStateCommon,
                      const tSlaveLsadFsm *rtu_sLastSlaveLsadFsm, const
                      tRelatedModuleInfo *rtu_sRelatedModuleInfo, tPaStateAdptr *
                      rty_sPaStateAdptr)
{
  boolean_T LocalVar_Equal1;
  boolean_T LocalVar_Equal1_k;
  boolean_T LocalVar_bPOCnfmInitReset;
  boolean_T k_RPAScreenSearch;
  tAPAMod LocalVar_UnitDelay1_h;

  /* Switch: '<S40>/Switch1' incorporates:
   *  Constant: '<S38>/Constant'
   *  Constant: '<S39>/Constant'
   *  Constant: '<S40>/Constant Value2'
   *  Logic: '<S28>/Logical Operator1'
   *  Logic: '<S28>/Logical Operator13'
   *  RelationalOperator: '<S28>/Equal1'
   *  RelationalOperator: '<S28>/Equal2'
   *  Switch: '<S40>/Switch'
   *  UnitDelay: '<S40>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
           (((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_SEARCH) ?
             ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))
        & (((boolean_T)((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
              FUNC_STS_APA_PI_SUPPRESSION) ? ((int32_T)1) : ((int32_T)0)) ^ 1)))
           ? ((int32_T)1) : ((int32_T)0)))))
  {
    pa_state_adapter_DW.UnitDelay1_DSTATE = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S40>/Unit Delay1' incorporates:
     *  Constant: '<S28>/Constant19'
     *  Sum: '<S40>/Subtraction'
     */
    pa_state_adapter_DW.UnitDelay1_DSTATE += s_APPManLoopSec;
  }

  /* End of Switch: '<S40>/Switch1' */

  /* UnitDelay: '<S2>/Unit Delay1' */
  LocalVar_UnitDelay1_h = pa_state_adapter_DW.UnitDelay1_DSTATE_c;

  /* RelationalOperator: '<S27>/Equal1' incorporates:
   *  Constant: '<S31>/Constant'
   *  UnitDelay: '<S27>/Unit Delay1'
   */
  LocalVar_Equal1 = (pa_state_adapter_DW.UnitDelay1_DSTATE_e ==
                     APA_MODE_SELF_SELECT);

  /* UnitDelay: '<S27>/Unit Delay2' incorporates:
   *  UnitDelay: '<S27>/Unit Delay1'
   */
  pa_state_adapter_DW.UnitDelay1_DSTATE_e =
    pa_state_adapter_DW.UnitDelay2_DSTATE_c;

  /* Switch: '<S37>/Switch' incorporates:
   *  Constant: '<S32>/Constant'
   *  Constant: '<S33>/Constant'
   *  Constant: '<S34>/Constant'
   *  Constant: '<S35>/Constant'
   *  Constant: '<S36>/Constant'
   *  Constant: '<S37>/Constant Value2'
   *  Logic: '<S27>/Logical Operator'
   *  Logic: '<S27>/Logical Operator1'
   *  Logic: '<S27>/Logical Operator13'
   *  Logic: '<S27>/Logical Operator2'
   *  Logic: '<S27>/Logical Operator3'
   *  Logic: '<S27>/Logical Operator5'
   *  RelationalOperator: '<S27>/Equal2'
   *  RelationalOperator: '<S27>/Equal3'
   *  RelationalOperator: '<S27>/Equal32'
   *  RelationalOperator: '<S27>/Equal4'
   *  RelationalOperator: '<S27>/Equal5'
   *  UnitDelay: '<S27>/Unit Delay1'
   *  UnitDelay: '<S2>/Unit Delay1'
   *  UnitDelay: '<S37>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
               (((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_CONFIRM)
                 ? ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) :
             ((int32_T)0)) & (((boolean_T)((int32_T)
               (((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_PI_CONFIRM)
                 ? ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) :
             ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)
          ((int32_T)((((boolean_T)((int32_T)
               (((pa_state_adapter_DW.UnitDelay1_DSTATE_c == APA_MODE_PARK_IN) ?
                 ((int32_T)1) : ((int32_T)0)) & (LocalVar_Equal1 ? ((int32_T)1) :
    ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
               (((pa_state_adapter_DW.UnitDelay1_DSTATE_c ==
                  APA_MODE_SELF_SELECT) ? ((int32_T)1) : ((int32_T)0)) &
                ((pa_state_adapter_DW.UnitDelay1_DSTATE_e == APA_MODE_PARK_IN) ?
                 ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)))))
         ? ((int32_T)1) : ((int32_T)0)))))
  {
    pa_state_adapter_DW.UnitDelay1_DSTATE_n = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S37>/Unit Delay1' incorporates:
     *  Constant: '<S27>/Constant21'
     *  Sum: '<S37>/Subtraction'
     *  Switch: '<S37>/Switch1'
     */
    pa_state_adapter_DW.UnitDelay1_DSTATE_n += s_APPManLoopSec;
  }

  /* End of Switch: '<S37>/Switch' */

  /* Switch: '<S43>/Switch1' incorporates:
   *  Constant: '<S41>/Constant'
   *  Constant: '<S42>/Constant'
   *  Constant: '<S43>/Constant Value2'
   *  Logic: '<S29>/Logical Operator'
   *  Logic: '<S29>/Logical Operator17'
   *  RelationalOperator: '<S29>/Equal1'
   *  RelationalOperator: '<S29>/Equal35'
   *  Switch: '<S43>/Switch'
   *  UnitDelay: '<S43>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
           (((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PO_CONFIRM) ?
             ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))
        & (((boolean_T)((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
              FUNC_STS_RPA_PO_CONFIRM) ? ((int32_T)1) : ((int32_T)0)) ^ 1))) ?
           ((int32_T)1) : ((int32_T)0)))))
  {
    pa_state_adapter_DW.UnitDelay1_DSTATE_a = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S43>/Unit Delay1' incorporates:
     *  Constant: '<S29>/Constant24'
     *  Sum: '<S43>/Subtraction'
     */
    pa_state_adapter_DW.UnitDelay1_DSTATE_a += s_APPManLoopSec;
  }

  /* End of Switch: '<S43>/Switch1' */

  /* BusAssignment: '<S2>/Bus Assignment' incorporates:
   *  Constant: '<S27>/Constant22'
   *  Constant: '<S28>/Constant20'
   *  Constant: '<S29>/Constant23'
   *  Constant: '<S2>/Constant2'
   *  RelationalOperator: '<S27>/Equal27'
   *  RelationalOperator: '<S28>/Equal28'
   *  RelationalOperator: '<S29>/Equal34'
   *  UnitDelay: '<S37>/Unit Delay1'
   *  UnitDelay: '<S40>/Unit Delay1'
   *  UnitDelay: '<S43>/Unit Delay1'
   */
  (void)memset(&rty_sPaStateAdptr->sCondiOverFlagAdptr, 0, sizeof
               (tCondiOverFlagAdptr));
  rty_sPaStateAdptr->sCondiOverFlagAdptr.bPISrchOvertime =
    (pa_state_adapter_DW.UnitDelay1_DSTATE >= k_PrkInSrchDuratTime);
  rty_sPaStateAdptr->sCondiOverFlagAdptr.bSupressOvertime = false;
  rty_sPaStateAdptr->sCondiOverFlagAdptr.bPICnfmOvertime =
    (pa_state_adapter_DW.UnitDelay1_DSTATE_n >= k_PrkInCofmDuratTime);
  rty_sPaStateAdptr->sCondiOverFlagAdptr.bPOCnfmOvertime =
    (pa_state_adapter_DW.UnitDelay1_DSTATE_a >= k_PrkOutCofmDuratTime);
  rty_sPaStateAdptr->sCondiOverFlagAdptr.bRmtCnnctDuratime = false;
  rty_sPaStateAdptr->sCondiOverFlagAdptr.bRmtCnnctOvertime = false;
  rty_sPaStateAdptr->sCondiOverFlagAdptr.bBackgroundOvertime = false;

  /* RelationalOperator: '<S12>/Equal4' incorporates:
   *  Constant: '<S24>/Constant'
   */
  LocalVar_Equal1 = (rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
                     FUNC_STS_APA_PO_CONFIRM);

  /* RelationalOperator: '<S12>/Equal1' incorporates:
   *  Constant: '<S23>/Constant'
   */
  LocalVar_Equal1_k = (rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
                       FUNC_STS_RPA_PO_CONFIRM);

  /* Logic: '<S12>/Logical Operator1' incorporates:
   *  Delay: '<S21>/Delay'
   *  Delay: '<S22>/Delay'
   *  RelationalOperator: '<S21>/Relational Operator'
   *  RelationalOperator: '<S22>/Relational Operator'
   */
  LocalVar_bPOCnfmInitReset = (((int32_T)(LocalVar_Equal1 ? 1 : 0)) > ((int32_T)
    (pa_state_adapter_DW.bitsForTID0.Delay_DSTATE ? 1 : 0))) | (((int32_T)
    (LocalVar_Equal1_k ? 1 : 0)) > ((int32_T)
    (pa_state_adapter_DW.bitsForTID0.Delay_DSTATE_f ? 1 : 0)));

  /* MATLAB Function: '<S12>/POSlotType' incorporates:
   *  UnitDelay: '<S12>/Unit Delay5'
   *  UnitDelay: '<S1>/Unit Delay3'
   */
  if (LocalVar_bPOCnfmInitReset)
  {
    pa_state_adapter_DW.UnitDelay5_DSTATE_c = PO_SLOT_TYPE_NONE;
  }
  else if ((boolean_T)((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
               FUNC_STS_APA_PO_CONFIRM) ? ((int32_T)1) : ((int32_T)0)) &
             ((pa_state_adapter_DW.UnitDelay3_DSTATE == PARK_FUNC_APA) ?
              ((int32_T)1) : ((int32_T)0)))))
  {
    switch (rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkSlotType)
    {
     case SLOT_TYP_PERPENDI:
      pa_state_adapter_DW.UnitDelay5_DSTATE_c = PO_SLOT_TYPE_PERPENDI;
      break;

     case SLOT_TYP_PARALLEL:
      pa_state_adapter_DW.UnitDelay5_DSTATE_c = PO_SLOT_TYPE_PARALLEL;
      break;

     case SLOT_TYP_OBLIQUE:
      pa_state_adapter_DW.UnitDelay5_DSTATE_c = PO_SLOT_TYPE_OBLIQUE;
      break;

     default:
      /* no actions */
      break;
    }
  }
  else if ((boolean_T)((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
               FUNC_STS_RPA_PO_CONFIRM) ? ((int32_T)1) : ((int32_T)0)) &
             ((pa_state_adapter_DW.UnitDelay3_DSTATE == PARK_FUNC_RPA) ?
              ((int32_T)1) : ((int32_T)0)))))
  {
    switch (rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkSlotType)
    {
     case SLOT_TYP_PERPENDI:
      pa_state_adapter_DW.UnitDelay5_DSTATE_c = PO_SLOT_TYPE_PERPENDI;
      break;

     case SLOT_TYP_PARALLEL:
      pa_state_adapter_DW.UnitDelay5_DSTATE_c = PO_SLOT_TYPE_PARALLEL;
      break;

     case SLOT_TYP_OBLIQUE:
      pa_state_adapter_DW.UnitDelay5_DSTATE_c = PO_SLOT_TYPE_OBLIQUE;
      break;

     default:
      /* no actions */
      break;
    }
  }
  else if (rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_STANDBY)
  {
    pa_state_adapter_DW.UnitDelay5_DSTATE_c = PO_SLOT_TYPE_NONE;
  }
  else
  {
    /* no actions */
  }

  /* End of MATLAB Function: '<S12>/POSlotType' */

  /* MATLAB Function: '<S12>/PODirDet' incorporates:
   *  RelationalOperator: '<S12>/Equal2'
   *  UnitDelay: '<S12>/Unit Delay1'
   *  UnitDelay: '<S12>/Unit Delay5'
   *  UnitDelay: '<S12>/Unit Delay7'
   */
  if ((boolean_T)((int32_T)((LocalVar_bPOCnfmInitReset ? ((int32_T)1) :
         ((int32_T)0)) | ((pa_state_adapter_DW.UnitDelay5_DSTATE_c !=
          pa_state_adapter_DW.UnitDelay1_DSTATE_ad) ? ((int32_T)1) : ((int32_T)0)))))
  {
    pa_state_adapter_DW.UnitDelay7_DSTATE = PO_DIR_NO_REQ;
  }
  else if ((boolean_T)((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
               FUNC_STS_APA_PO_CONFIRM) ? ((int32_T)1) : ((int32_T)0)) |
             ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_PO_CONFIRM) ?
              ((int32_T)1) : ((int32_T)0)))))
  {
    if ((boolean_T)((int32_T)(((rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkOutDir ==
            PRK_HEAD_OUT_DIR_LEFT) ? ((int32_T)1) : ((int32_T)0)) |
          ((rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkOutDir == PRK_HEAD_OUT_DIR_LEFT) ?
           ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_adapter_DW.UnitDelay7_DSTATE = PO_HEAD_DIR_LEFT;
    }
    else if ((boolean_T)((int32_T)(((rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkOutDir ==
                 PRK_HEAD_OUT_DIR_STRAIGHT) ? ((int32_T)1) : ((int32_T)0)) |
               ((rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkOutDir ==
                 PRK_HEAD_OUT_DIR_STRAIGHT) ? ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_adapter_DW.UnitDelay7_DSTATE = PO_HEAD_DIR_STRAIGHT;
    }
    else if ((boolean_T)((int32_T)(((rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkOutDir ==
                 PRK_HEAD_OUT_DIR_RIGHT) ? ((int32_T)1) : ((int32_T)0)) |
               ((rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkOutDir == PRK_HEAD_OUT_DIR_RIGHT)
                ? ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_adapter_DW.UnitDelay7_DSTATE = PO_HEAD_DIR_RIGHT;
    }
    else if ((boolean_T)((int32_T)(((rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkOutDir ==
                 PRK_TAIL_OUT_DIR_LEFT) ? ((int32_T)1) : ((int32_T)0)) |
               ((rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkOutDir == PRK_TAIL_OUT_DIR_LEFT)
                ? ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_adapter_DW.UnitDelay7_DSTATE = PO_TAIL_DIR_LEFT;
    }
    else if ((boolean_T)((int32_T)(((rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkOutDir ==
                 PRK_TAIL_OUT_DIR_STRAIGHT) ? ((int32_T)1) : ((int32_T)0)) |
               ((rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkOutDir ==
                 PRK_TAIL_OUT_DIR_STRAIGHT) ? ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_adapter_DW.UnitDelay7_DSTATE = PO_TAIL_DIR_STRAIGHT;
    }
    else if ((boolean_T)((int32_T)(((rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkOutDir ==
                 PRK_TAIL_OUT_DIR_RIGHT) ? ((int32_T)1) : ((int32_T)0)) |
               ((rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkOutDir == PRK_TAIL_OUT_DIR_RIGHT)
                ? ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_adapter_DW.UnitDelay7_DSTATE = PO_TAIL_DIR_RIGHT;
    }
    else
    {
      /* no actions */
    }
  }
  else if (rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_STANDBY)
  {
    pa_state_adapter_DW.UnitDelay7_DSTATE = PO_DIR_NO_REQ;
  }
  else
  {
    /* no actions */
  }

  /* End of MATLAB Function: '<S12>/PODirDet' */

  /* MATLAB Function: '<S1>/APAMod ' incorporates:
   *  UnitDelay: '<S1>/Unit Delay2'
   *  UnitDelay: '<S1>/Unit Delay4'
   */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
           (((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_MODE_SELECT) ?
             ((int32_T)1) : ((int32_T)0)) |
            ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_SUPPRESSION)
             ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
        ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_SEARCH) ?
         ((int32_T)1) : ((int32_T)0)))))
  {
    /*      if(eAPAInternalStsDelay == tLSAD_SystemSts.FUNC_STS_INTERNAL_PARK_IDLE)||... */
    /*        (eAPAInternalStsDelay == tLSAD_SystemSts.FUNC_STS_INTERNAL_BACKGROUND_SEARCH)%´ÓIDLE||BACKGROUND_SEARCH To PARKIN_SEARCH */
    /*          eAPAMod = tAPAMod.APA_MODE_PARK_IN; */
    if ((boolean_T)((int32_T)(((rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkTypReq == PRK_IN)
           ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sVehDataRx->sVehESCInfo.f32VehSpdKph <= k_PrkInSrchMaxSpd) ?
           ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_adapter_DW.UnitDelay4_DSTATE = APA_MODE_PARK_IN;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                  (((rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkTypReq == PRK_DRAG) ?
                    ((int32_T)1) : ((int32_T)0)) | ((APA_DF_DRAG ==
        rtu_sRelatedModuleInfo->eDataFusionSts) ? ((int32_T)1) : ((int32_T)0)))))
                ? ((int32_T)1) : ((int32_T)0)) &
               (rtu_sVehCommon->sCondiVeh.bVehStill ? ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_adapter_DW.UnitDelay4_DSTATE = APA_MODE_SELF_SELECT;
    }
    else if ((boolean_T)((int32_T)(((rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkTypReq ==
                 PRK_OUT) ? ((int32_T)1) : ((int32_T)0)) &
               (rtu_sVehCommon->sCondiVeh.bVehStill ? ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_adapter_DW.UnitDelay4_DSTATE = APA_MODE_PARK_OUT;
    }
    else
    {
      /* no actions */
    }
  }
  else
  {
    switch (rtu_sLastSlaveLsadFsm->eLsadFuncSts)
    {
     case FUNC_STS_APA_PI_SUPPRESSION:
      if (pa_state_adapter_DW.UnitDelay2_DSTATE == FUNC_STS_STANDBY)
      {
        pa_state_adapter_DW.UnitDelay4_DSTATE = APA_MODE_PARK_IN;
      }
      break;

     case FUNC_STS_APA_PI_CONFIRM:
      if (rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkTypReq == PRK_IN)
      {
        pa_state_adapter_DW.UnitDelay4_DSTATE = APA_MODE_PARK_IN;
      }
      else if ((boolean_T)((int32_T)(((rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkTypReq ==
                   PRK_DRAG) ? ((int32_T)1) : ((int32_T)0)) | ((APA_DF_DRAG ==
                   rtu_sRelatedModuleInfo->eDataFusionSts) ? ((int32_T)1) :
                  ((int32_T)0)))))
      {
        pa_state_adapter_DW.UnitDelay4_DSTATE = APA_MODE_SELF_SELECT;
      }
      else if (rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkTypReq == PRK_OUT)
      {
        pa_state_adapter_DW.UnitDelay4_DSTATE = APA_MODE_PARK_OUT;
      }
      else
      {
        /* no actions */
      }
      break;

     case FUNC_STS_APA_PO_CONFIRM:
      if ((boolean_T)((int32_T)(((rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkTypReq ==
              PRK_DRAG) ? ((int32_T)1) : ((int32_T)0)) | ((APA_DF_DRAG ==
              rtu_sRelatedModuleInfo->eDataFusionSts) ? ((int32_T)1) : ((int32_T)
              0)))))
      {
        pa_state_adapter_DW.UnitDelay4_DSTATE = APA_MODE_SELF_SELECT;
      }
      else if (rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkTypReq == PRK_IN)
      {
        pa_state_adapter_DW.UnitDelay4_DSTATE = APA_MODE_PARK_IN;
      }
      else
      {
        /* no actions */
      }

      /*  elseif(eAPAInternalSts == tLSAD_SystemSts.FUNC_STS_RPA_REMOTE_CONNECT) */
      /*      if(eAPAInternalStsDelay == tLSAD_SystemSts.FUNC_STS_INTERNAL_PARK_IDLE) */
      /*          eAPAMod = tAPAMod.APA_MODE_PARK_IN;     */
      /*      else */
      /*          eAPAMod = eAPAModDelay;  */
      /*      end     */
      break;

     case FUNC_STS_RPA_REMOTE_OK:
      if (rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkTypReq == PRK_IN)
      {
        pa_state_adapter_DW.UnitDelay4_DSTATE = APA_MODE_PARK_IN;
      }
      else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                    (((rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkTypReq == PRK_DRAG) ?
                      ((int32_T)1) : ((int32_T)0)) | ((APA_DF_DRAG ==
          rtu_sRelatedModuleInfo->eDataFusionSts) ? ((int32_T)1) : ((int32_T)0)))))
                  ? ((int32_T)1) : ((int32_T)0)) &
                 (rtu_sVehCommon->sCondiVeh.bVehStill ? ((int32_T)1) : ((int32_T)
                   0)))))
      {
        pa_state_adapter_DW.UnitDelay4_DSTATE = APA_MODE_SELF_SELECT;
      }
      else
      {
        switch (rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkTypReq)
        {
         case PRK_OUT:
          pa_state_adapter_DW.UnitDelay4_DSTATE = APA_MODE_PARK_OUT;
          break;

         case PRK_STRAIGHT:
          pa_state_adapter_DW.UnitDelay4_DSTATE = APA_MODE_STRAIGHT;
          break;

         default:
          /* no actions */
          break;
        }
      }
      break;

     case FUNC_STS_RPA_PO_CONFIRM:
      switch (rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkTypReq)
      {
       case PRK_STRAIGHT:
        pa_state_adapter_DW.UnitDelay4_DSTATE = APA_MODE_STRAIGHT;
        break;

       case PRK_IN:
        pa_state_adapter_DW.UnitDelay4_DSTATE = APA_MODE_PARK_IN;
        break;

       default:
        if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                 (((rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkTypReq == PRK_DRAG) ?
                   ((int32_T)1) : ((int32_T)0)) | ((APA_DF_DRAG ==
                    rtu_sRelatedModuleInfo->eDataFusionSts) ? ((int32_T)1) :
                   ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
              (rtu_sVehCommon->sCondiVeh.bVehStill ? ((int32_T)1) : ((int32_T)0)))))
        {
          pa_state_adapter_DW.UnitDelay4_DSTATE = APA_MODE_SELF_SELECT;
        }
        break;
      }
      break;

     case FUNC_STS_STANDBY:
      pa_state_adapter_DW.UnitDelay4_DSTATE = APA_MODE_NONE;
      break;

     default:
      /* no actions */
      break;
    }
  }

  /* End of MATLAB Function: '<S1>/APAMod ' */

  /* MATLAB Function: '<S1>/PrkFnctDet ' incorporates:
   *  UnitDelay: '<S1>/Unit Delay1'
   *  UnitDelay: '<S1>/Unit Delay3'
   */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
               ((((boolean_T)((int32_T)(((LSAD_FUNC_TYPE_NONE ==
      rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0)) |
      ((LSAD_PARK_IN == rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) :
       ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) | ((LSAD_PARK_OUT ==
      rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0))))) ?
             ((int32_T)1) : ((int32_T)0)) | ((LSAD_PARK_STRAIGHT ==
              rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0)))))
         ? ((int32_T)1) : ((int32_T)0)) | ((LSAD_DRAG_PARK_IN ==
          rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0)))))
  {
    if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
                 ((((boolean_T)((int32_T)((((boolean_T)((int32_T)
        (((FUNC_STS_APA_MODE_SELECT == rtu_sLastSlaveLsadFsm->eLsadFuncSts) ?
        ((int32_T)1) : ((int32_T)0)) | ((FUNC_STS_APA_PI_SUPPRESSION ==
        rtu_sLastSlaveLsadFsm->eLsadFuncSts) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0)) | ((FUNC_STS_APA_PI_SEARCH ==
        rtu_sLastSlaveLsadFsm->eLsadFuncSts) ? ((int32_T)1) : ((int32_T)0))))) ?
                   ((int32_T)1) : ((int32_T)0)) | ((FUNC_STS_APA_PI_CONFIRM ==
        rtu_sLastSlaveLsadFsm->eLsadFuncSts) ? ((int32_T)1) : ((int32_T)0))))) ?
               ((int32_T)1) : ((int32_T)0)) | ((FUNC_STS_APA_PO_SUPPRESSION ==
                rtu_sLastSlaveLsadFsm->eLsadFuncSts) ? ((int32_T)1) : ((int32_T)
                0))))) ? ((int32_T)1) : ((int32_T)0)) |
          ((FUNC_STS_APA_PO_CONFIRM == rtu_sLastSlaveLsadFsm->eLsadFuncSts) ?
           ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_adapter_DW.UnitDelay3_DSTATE = PARK_FUNC_APA;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)(((FUNC_STS_RPA_REMOTE_CONNECT ==
        rtu_sLastSlaveLsadFsm->eLsadFuncSts) ? ((int32_T)1) : ((int32_T)0)) |
        ((FUNC_STS_RPA_REMOTE_OK == rtu_sLastSlaveLsadFsm->eLsadFuncSts) ?
        ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
        ((FUNC_STS_RPA_PARK_STRAIGHT == rtu_sLastSlaveLsadFsm->eLsadFuncSts) ?
        ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
        ((FUNC_STS_RPA_PO_CONFIRM == rtu_sLastSlaveLsadFsm->eLsadFuncSts) ?
         ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
                   ((FUNC_STS_RPA_PI_SUPPRESSION ==
                     rtu_sLastSlaveLsadFsm->eLsadFuncSts) ? ((int32_T)1) :
                    ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
        ((FUNC_STS_RPA_PI_SEARCH == rtu_sLastSlaveLsadFsm->eLsadFuncSts) ?
         ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
               ((FUNC_STS_RPA_PI_CONFIRM == rtu_sLastSlaveLsadFsm->eLsadFuncSts)
                ? ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_adapter_DW.UnitDelay3_DSTATE = PARK_FUNC_RPA;
    }
    else if (rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_STANDBY)
    {
      pa_state_adapter_DW.UnitDelay3_DSTATE = PARK_FUNC_NONE;
    }
    else
    {
      pa_state_adapter_DW.UnitDelay3_DSTATE =
        pa_state_adapter_DW.UnitDelay1_DSTATE_d;
    }
  }
  else
  {
    pa_state_adapter_DW.UnitDelay3_DSTATE = PARK_FUNC_NONE;
  }

  /* End of MATLAB Function: '<S1>/PrkFnctDet ' */

  /* MATLAB Function: '<S1>/eDragSlotTypeDet' incorporates:
   *  UnitDelay: '<S1>/Unit Delay4'
   *  UnitDelay: '<S1>/Unit Delay5'
   */
  if ((boolean_T)((int32_T)(((rtu_sPAHmiRx->sAPAHmiRx.eAPASelfPrkType ==
          SLOT_TYP_PARALLEL) ? ((int32_T)1) : ((int32_T)0)) |
        ((rtu_sPAHmiRx->sRPAHmiRx.eRPASelfPrkTyp == SLOT_TYP_PARALLEL) ?
         ((int32_T)1) : ((int32_T)0)))))
  {
    pa_state_adapter_DW.UnitDelay5_DSTATE = DRAG_SLOT_TYPE_PARALLEL;
  }
  else if ((boolean_T)((int32_T)(((rtu_sPAHmiRx->sAPAHmiRx.eAPASelfPrkType ==
               SLOT_TYP_PERPENDI) ? ((int32_T)1) : ((int32_T)0)) |
             ((rtu_sPAHmiRx->sRPAHmiRx.eRPASelfPrkTyp == SLOT_TYP_PERPENDI) ?
              ((int32_T)1) : ((int32_T)0)))))
  {
    pa_state_adapter_DW.UnitDelay5_DSTATE = DRAG_SLOT_TYPE_PERPENDI;
  }
  else if ((boolean_T)((int32_T)(((rtu_sPAHmiRx->sAPAHmiRx.eAPASelfPrkType ==
               SLOT_TYP_OBLIQUE) ? ((int32_T)1) : ((int32_T)0)) |
             ((rtu_sPAHmiRx->sRPAHmiRx.eRPASelfPrkTyp == SLOT_TYP_OBLIQUE) ?
              ((int32_T)1) : ((int32_T)0)))))
  {
    pa_state_adapter_DW.UnitDelay5_DSTATE = DRAG_SLOT_TYPE_OBLIQUE;
  }
  else if ((boolean_T)((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
               FUNC_STS_STANDBY) ? ((int32_T)1) : ((int32_T)0)) |
             ((pa_state_adapter_DW.UnitDelay4_DSTATE != APA_MODE_SELF_SELECT) ?
              ((int32_T)1) : ((int32_T)0)))))
  {
    pa_state_adapter_DW.UnitDelay5_DSTATE = DRAG_SLOT_TYPE_NONE;
  }
  else
  {
    /* no actions */
  }

  /* End of MATLAB Function: '<S1>/eDragSlotTypeDet' */

  /* Switch: '<S6>/Switch3' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S15>/Constant'
   *  Constant: '<S16>/Constant'
   *  Constant: '<S6>/Constant5'
   *  Logic: '<S6>/Logical Operator15'
   *  RelationalOperator: '<S6>/Equal'
   *  RelationalOperator: '<S6>/Equal29'
   *  RelationalOperator: '<S6>/Equal30'
   *  UnitDelay: '<S6>/Unit Delay1'
   *  UnitDelay: '<S6>/Unit Delay3'
   */
  if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
          LSAD_STS_STANDBY) ? ((int32_T)1) : ((int32_T)0)) &
        ((pa_state_adapter_DW.UnitDelay3_DSTATE_m == LSAD_STS_OFF) ? ((int32_T)1)
         : ((int32_T)0)))))
  {
    LocalVar_bPOCnfmInitReset = false;
  }
  else
  {
    LocalVar_bPOCnfmInitReset = (rtu_sPAHmiRx->sAPAHmiRx.eIgoPA == SWT_ON) |
      pa_state_adapter_DW.bitsForTID0.UnitDelay1_DSTATE_co;
  }

  /* End of Switch: '<S6>/Switch3' */

  /* BusAssignment: '<S1>/Bus Assignment' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S8>/Constant'
   *  Constant: '<S9>/Constant'
   *  RelationalOperator: '<S1>/Equal1'
   *  RelationalOperator: '<S1>/Equal2'
   *  RelationalOperator: '<S1>/Equal3'
   *  UnitDelay: '<S12>/Unit Delay5'
   *  UnitDelay: '<S12>/Unit Delay7'
   *  UnitDelay: '<S1>/Unit Delay3'
   *  UnitDelay: '<S1>/Unit Delay4'
   *  UnitDelay: '<S1>/Unit Delay5'
   */
  (void)memset(&rty_sPaStateAdptr->sCondiHMI, 0, sizeof(tCondiHMI));
  rty_sPaStateAdptr->sCondiHMI.ePOSlotType =
    pa_state_adapter_DW.UnitDelay5_DSTATE_c;
  rty_sPaStateAdptr->sCondiHMI.ePODir = pa_state_adapter_DW.UnitDelay7_DSTATE;
  rty_sPaStateAdptr->sCondiHMI.POSlotLength = 0.0F;
  rty_sPaStateAdptr->sCondiHMI.eAPAMod = pa_state_adapter_DW.UnitDelay4_DSTATE;
  rty_sPaStateAdptr->sCondiHMI.ePrkFnct = pa_state_adapter_DW.UnitDelay3_DSTATE;
  rty_sPaStateAdptr->sCondiHMI.eDragSlotType =
    pa_state_adapter_DW.UnitDelay5_DSTATE;
  rty_sPaStateAdptr->sCondiHMI.bAppInitRPA = false;
  rty_sPaStateAdptr->sCondiHMI.bBLEConnect =
    (rtu_sPAHmiRx->sRPAHmiRx.eBLEConnectSts == BLE_CONNECT);
  rty_sPaStateAdptr->sCondiHMI.bBLEScrt = (rtu_sPAHmiRx->sRPAHmiRx.eBLEScrtSts ==
    BLE_SECURITY);
  rty_sPaStateAdptr->sCondiHMI.bPhoneHangUp =
    (rtu_sPAHmiRx->sRPAHmiRx.eRemoteIntModSel == RemoteInt_60s_HangUp_Phone);
  rty_sPaStateAdptr->sCondiHMI.bBgSrchDisable = LocalVar_bPOCnfmInitReset;

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S17>/Constant'
   *  Constant: '<S18>/Constant'
   *  Constant: '<S19>/Constant'
   *  Logic: '<S10>/Logical Operator1'
   *  Logic: '<S10>/Logical Operator2'
   *  RelationalOperator: '<S10>/Equal1'
   *  RelationalOperator: '<S10>/Equal2'
   *  RelationalOperator: '<S10>/Equal5'
   *  UnitDelay: '<S1>/Unit Delay4'
   */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
           (((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_CONFIRM) ?
             ((int32_T)1) : ((int32_T)0)) |
            ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_PI_CONFIRM) ?
             ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
        ((pa_state_adapter_DW.UnitDelay4_DSTATE == APA_MODE_SELF_SELECT) ?
         ((int32_T)1) : ((int32_T)0)))))
  {
    /* BusAssignment: '<S1>/Bus Assignment' incorporates:
     *  Constant: '<S20>/Constant'
     *  RelationalOperator: '<S10>/Equal3'
     *  UnitDelay: '<S1>/Unit Delay5'
     */
    rty_sPaStateAdptr->sCondiHMI.bHmiSelfSelTypeSelected =
      (pa_state_adapter_DW.UnitDelay5_DSTATE != DRAG_SLOT_TYPE_NONE);
  }
  else
  {
    /* BusAssignment: '<S1>/Bus Assignment' incorporates:
     *  Constant: '<S10>/Constant'
     */
    rty_sPaStateAdptr->sCondiHMI.bHmiSelfSelTypeSelected = false;
  }

  /* End of Switch: '<S10>/Switch' */

  /* MATLAB Function: '<S3>/PASuspendEvntDet' */
  if ((boolean_T)((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
          FUNC_STS_APA_PI_SEARCH) ? ((int32_T)1) : ((int32_T)0)) |
        ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_SUPPRESSION) ?
         ((int32_T)1) : ((int32_T)0)))))
  {
    if (rtu_sVehDataRx->sVehESCInfo.f32VehSpdKph > k_SuppressEnterSpd)
    {
      rty_sPaStateAdptr->sPAEvntAdptr.ePASuspendEvnt = SUSPEND_SPEED_HIGH;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)((((boolean_T)((int32_T)
        ((rtu_sVehCommon->sCondiDoorSblt.bFLDrClose ? ((int32_T)1) : ((int32_T)0))
         ^ 1))) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
        ((rtu_sVehCommon->sCondiDoorSblt.bFRDrClose ? ((int32_T)1) : ((int32_T)0))
         ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
      | (((boolean_T)((int32_T)((rtu_sVehCommon->sCondiDoorSblt.bRLDrClose ?
        ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
                  ((rtu_sVehCommon->sCondiDoorSblt.bRRDrClose ? ((int32_T)1) :
                    ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
    {
      rty_sPaStateAdptr->sPAEvntAdptr.ePASuspendEvnt = SUSPEND_DR_DOOR_OPEN;
    }
    else if ((boolean_T)((int32_T)
                         ((rtu_sVehCommon->sCondiDoorSblt.bTailGateClose ?
                           ((int32_T)1) : ((int32_T)0)) ^ 1)))
    {
      rty_sPaStateAdptr->sPAEvntAdptr.ePASuspendEvnt = SUSPEND_TRUNK_OPEN;
    }
    else if ((boolean_T)((int32_T)((rtu_sVehCommon->sCondiDoorSblt.bHoodDrClose ?
                ((int32_T)1) : ((int32_T)0)) ^ 1)))
    {
      rty_sPaStateAdptr->sPAEvntAdptr.ePASuspendEvnt = SUSPEND_HOOD_OPEN;
    }
    else if (rtu_sVehDataRx->sVehBCMInfo.bMirrFld)
    {
      rty_sPaStateAdptr->sPAEvntAdptr.ePASuspendEvnt = SUSPEND_MIRROR_FOLD;
    }
    else
    {
      rty_sPaStateAdptr->sPAEvntAdptr.ePASuspendEvnt = SUSPEND_NONE;
    }

    /* RPA²´Èë */
  }
  else if ((boolean_T)((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
               FUNC_STS_RPA_PI_SEARCH) ? ((int32_T)1) : ((int32_T)0)) |
             ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
               FUNC_STS_RPA_PI_SUPPRESSION) ? ((int32_T)1) : ((int32_T)0)))))
  {
    if (rtu_sVehDataRx->sVehESCInfo.f32VehSpdKph > k_SuppressEnterSpd)
    {
      rty_sPaStateAdptr->sPAEvntAdptr.ePASuspendEvnt = SUSPEND_SPEED_HIGH;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)((((boolean_T)((int32_T)
        ((rtu_sVehCommon->sCondiDoorSblt.bFLDrClose ? ((int32_T)1) : ((int32_T)0))
         ^ 1))) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
        ((rtu_sVehCommon->sCondiDoorSblt.bFRDrClose ? ((int32_T)1) : ((int32_T)0))
         ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
      | (((boolean_T)((int32_T)((rtu_sVehCommon->sCondiDoorSblt.bRLDrClose ?
        ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
                  ((rtu_sVehCommon->sCondiDoorSblt.bRRDrClose ? ((int32_T)1) :
                    ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
    {
      rty_sPaStateAdptr->sPAEvntAdptr.ePASuspendEvnt = SUSPEND_DR_DOOR_OPEN;
    }
    else if ((boolean_T)((int32_T)
                         ((rtu_sVehCommon->sCondiDoorSblt.bTailGateClose ?
                           ((int32_T)1) : ((int32_T)0)) ^ 1)))
    {
      rty_sPaStateAdptr->sPAEvntAdptr.ePASuspendEvnt = SUSPEND_TRUNK_OPEN;
    }
    else if ((boolean_T)((int32_T)((rtu_sVehCommon->sCondiDoorSblt.bHoodDrClose ?
                ((int32_T)1) : ((int32_T)0)) ^ 1)))
    {
      rty_sPaStateAdptr->sPAEvntAdptr.ePASuspendEvnt = SUSPEND_HOOD_OPEN;
    }
    else if (rtu_sVehCommon->sCondiPlatform.bObstAppear)
    {
      rty_sPaStateAdptr->sPAEvntAdptr.ePASuspendEvnt = SUSPEND_RPA_OBSTACLE;
    }
    else
    {
      rty_sPaStateAdptr->sPAEvntAdptr.ePASuspendEvnt = SUSPEND_NONE;
    }
  }
  else
  {
    rty_sPaStateAdptr->sPAEvntAdptr.ePASuspendEvnt = SUSPEND_NONE;
  }

  /* End of MATLAB Function: '<S3>/PASuspendEvntDet' */

  /* MATLAB Function: '<S3>/PAQuitEvntDet' incorporates:
   *  BusAssignment: '<S1>/Bus Assignment'
   *  RelationalOperator: '<S6>/Equal29'
   *  UnitDelay: '<S1>/Unit Delay3'
   *  UnitDelay: '<S1>/Unit Delay4'
   *  UnitDelay: '<S3>/Unit Delay8'
   */
  k_RPAScreenSearch = k_RPAPhoneSearch ^ 1;

  /* ´óÆÁËÑ¿âÓëÊÖ»úËÑ¿â»¥³â */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
               ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
      ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
      ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
      ((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_APA_MODE_SELECT) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_SEARCH) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_SUPPRESSION) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PO_SUPPRESSION) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_CONFIRM) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PO_CONFIRM) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_PO_CONFIRM) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_PARK_STRAIGHT) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
      (((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
      LSAD_STS_HANDSHAKE) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)
      ((int32_T)((((boolean_T)((int32_T)(((LSAD_PARK_IN ==
      rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0)) |
      ((LSAD_PARK_OUT == rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) :
      ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) | ((LSAD_PARK_STRAIGHT ==
      rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_REMOTE_CONNECT) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
      1) : ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_REMOTE_OK) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
             ((int32_T)0)) | (((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_PI_SUPPRESSION) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_PI_SEARCH) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
       ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_PI_CONFIRM) ?
        ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
                (k_RPAScreenSearch ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
              1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
        (rtu_sVehDataRx->sVehBCMInfo.bMirrFld ? ((int32_T)1) : ((int32_T)0)))))
  {
    pa_state_adapter_DW.UnitDelay8_DSTATE = QUIT_MIRROR_FOLD;
  }
  else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      (((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_MODE_SELECT) ?
      ((int32_T)1) : ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_APA_PI_SEARCH) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_APA_PI_SUPPRESSION) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
      1) : ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_APA_PO_SUPPRESSION) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
      1) : ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_APA_PI_CONFIRM) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_APA_PO_CONFIRM) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_PO_CONFIRM) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_PARK_STRAIGHT) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
      1) : ((int32_T)0)) | (((boolean_T)((int32_T)
      (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_HANDSHAKE) ?
      ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)((((boolean_T)
      ((int32_T)(((LSAD_PARK_IN == rtu_sLastSlaveLsadFsm->eLsadFuncType) ?
      ((int32_T)1) : ((int32_T)0)) | ((LSAD_PARK_OUT ==
      rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0)) | ((LSAD_PARK_STRAIGHT ==
      rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_REMOTE_CONNECT) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
      1) : ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_REMOTE_OK) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | (((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
      ((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_PI_SUPPRESSION) ? ((int32_T)1) : ((int32_T)0)) |
                 ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_PI_SEARCH)
    ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_PI_CONFIRM) ?
       ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
      (k_RPAScreenSearch ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                     ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
             (((boolean_T)((int32_T)((rtu_sVehCommon->sCondiVeh.bTirePressNorm ?
    ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
  {
    pa_state_adapter_DW.UnitDelay8_DSTATE = QUIT_TIRE_PRESSURE_ABNORMAL;
  }
  else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      (((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_MODE_SELECT) ?
      ((int32_T)1) : ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_APA_PI_SEARCH) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_APA_PI_SUPPRESSION) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
      1) : ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_APA_PO_SUPPRESSION) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
      1) : ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_APA_PI_CONFIRM) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_APA_PO_CONFIRM) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_PO_CONFIRM) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_PARK_STRAIGHT) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
      1) : ((int32_T)0)) | (((boolean_T)((int32_T)
      (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_HANDSHAKE) ?
      ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)((((boolean_T)
      ((int32_T)(((LSAD_PARK_IN == rtu_sLastSlaveLsadFsm->eLsadFuncType) ?
      ((int32_T)1) : ((int32_T)0)) | ((LSAD_PARK_OUT ==
      rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0)) | ((LSAD_PARK_STRAIGHT ==
      rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_REMOTE_CONNECT) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
      1) : ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_REMOTE_OK) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | (((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
      ((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_PI_SUPPRESSION) ? ((int32_T)1) : ((int32_T)0)) |
                 ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_PI_SEARCH)
    ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_PI_CONFIRM) ?
       ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
      (k_RPAScreenSearch ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                     ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
             (rtu_sVehDataRx->sVehESCInfo.bDAActive ? ((int32_T)1) : ((int32_T)0)))))
  {
    pa_state_adapter_DW.UnitDelay8_DSTATE = QUIT_ACTIVE_DA;
  }
  else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      (((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_MODE_SELECT) ?
      ((int32_T)1) : ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_APA_PI_SEARCH) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_APA_PI_SUPPRESSION) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
      1) : ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_APA_PO_SUPPRESSION) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
      1) : ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_APA_PI_CONFIRM) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_APA_PO_CONFIRM) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_PO_CONFIRM) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_PARK_STRAIGHT) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
      1) : ((int32_T)0)) | (((boolean_T)((int32_T)
      (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_HANDSHAKE) ?
      ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)((((boolean_T)
      ((int32_T)(((LSAD_PARK_IN == rtu_sLastSlaveLsadFsm->eLsadFuncType) ?
      ((int32_T)1) : ((int32_T)0)) | ((LSAD_PARK_OUT ==
      rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0)) | ((LSAD_PARK_STRAIGHT ==
      rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_REMOTE_CONNECT) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
      1) : ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_REMOTE_OK) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | (((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
      ((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_PI_SUPPRESSION) ? ((int32_T)1) : ((int32_T)0)) |
                 ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_PI_SEARCH)
    ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_PI_CONFIRM) ?
       ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
      (k_RPAScreenSearch ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                     ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
             (rtu_sVehDataRx->sVehVCUInfo.bHVOff ? ((int32_T)1) : ((int32_T)0)))))
  {
    pa_state_adapter_DW.UnitDelay8_DSTATE = QUIT_HV_NOT_READY;
  }
  else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_APA_MODE_SELECT) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_SEARCH) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_SUPPRESSION) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PO_SUPPRESSION) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_CONFIRM) ?
       ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
       ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PO_CONFIRM) ?
        ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
      (((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
      LSAD_STS_HANDSHAKE) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)
      ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)(((LSAD_PARK_IN ==
    rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0)) |
      ((LSAD_DRAG_PARK_IN == rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1)
    : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) | ((LSAD_PARK_OUT ==
      rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0))))) ?
                  ((int32_T)1) : ((int32_T)0)) | ((LSAD_PARK_STRAIGHT ==
      rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) ?
              ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
                (((rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkWorkMd == PRK_WORK_EXIT) ?
                  ((int32_T)1) : ((int32_T)0)) &
                 ((pa_state_adapter_DW.UnitDelay3_DSTATE == PARK_FUNC_APA) ?
                  ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)))))
  {
    pa_state_adapter_DW.UnitDelay8_DSTATE = QUIT_MANUAL_DEACTIVATE;
  }
  else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                (((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_SEARCH)
                  ? ((int32_T)1) : ((int32_T)0)) |
                 ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
                   FUNC_STS_APA_PI_SUPPRESSION) ? ((int32_T)1) : ((int32_T)0)))))
              ? ((int32_T)1) : ((int32_T)0)) &
             (rty_sPaStateAdptr->sCondiOverFlagAdptr.bPISrchOvertime ? ((int32_T)
               1) : ((int32_T)0)))))
  {
    pa_state_adapter_DW.UnitDelay8_DSTATE = QUIT_SEARCH_OVERTIME;
  }
  else if ((boolean_T)((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
               FUNC_STS_APA_PI_SUPPRESSION) ? ((int32_T)1) : ((int32_T)0)) &
             ((rtu_sVehDataRx->sVehESCInfo.f32VehSpdKph > k_PrkInSrchMaxSpd) ?
              ((int32_T)1) : ((int32_T)0)))))
  {
    pa_state_adapter_DW.UnitDelay8_DSTATE = QUIT_SEARCH_OVERSPEED;
  }
  else if ((boolean_T)((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
               FUNC_STS_APA_PI_SEARCH) ? ((int32_T)1) : ((int32_T)0)) &
             (rty_sPaStateAdptr->sCondiOverFlagAdptr.bPISrchOvertime ? ((int32_T)
               1) : ((int32_T)0)))))
  {
    pa_state_adapter_DW.UnitDelay8_DSTATE = QUIT_SEARCH_OVERTIME;
  }
  else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                (((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
                   FUNC_STS_APA_PI_CONFIRM) ? ((int32_T)1) : ((int32_T)0)) |
                 (((boolean_T)((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
    FUNC_STS_RPA_PI_CONFIRM) ? ((int32_T)1) : ((int32_T)0)) & (k_RPAScreenSearch
    ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) ?
              ((int32_T)1) : ((int32_T)0)) &
             (rty_sPaStateAdptr->sCondiOverFlagAdptr.bPICnfmOvertime ? ((int32_T)
               1) : ((int32_T)0)))))
  {
    pa_state_adapter_DW.UnitDelay8_DSTATE = QUIT_CONFIRM_OVERTIME;
  }
  else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      (((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_CONFIRM) ?
      ((int32_T)1) : ((int32_T)0)) & ((pa_state_adapter_DW.UnitDelay4_DSTATE ==
      APA_MODE_SELF_SELECT) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
      ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_APA_PO_CONFIRM) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
                      FUNC_STS_RPA_PO_CONFIRM) ? ((int32_T)1) : ((int32_T)0)))))
        ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
      (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_HANDSHAKE) ?
        ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)((((boolean_T)
      ((int32_T)(((LSAD_PARK_IN == rtu_sLastSlaveLsadFsm->eLsadFuncType) ?
      ((int32_T)1) : ((int32_T)0)) | ((LSAD_PARK_OUT ==
      rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0)) | ((LSAD_PARK_STRAIGHT ==
      rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
      (((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_PI_CONFIRM) ?
        ((int32_T)1) : ((int32_T)0)) & (k_RPAScreenSearch ? ((int32_T)1) :
      ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
              ((int32_T)0)) & (((boolean_T)((int32_T)
                ((rtu_sVehCommon->sCondiVeh.bVehStill ? ((int32_T)1) : ((int32_T)
      0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
  {
    pa_state_adapter_DW.UnitDelay8_DSTATE = QUIT_VEH_MOVE;
  }
  else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                (((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
                   FUNC_STS_APA_PO_CONFIRM) ? ((int32_T)1) : ((int32_T)0)) |
                 ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
                   FUNC_STS_RPA_PO_CONFIRM) ? ((int32_T)1) : ((int32_T)0))))) ?
              ((int32_T)1) : ((int32_T)0)) &
             (rty_sPaStateAdptr->sCondiOverFlagAdptr.bPOCnfmOvertime ? ((int32_T)
               1) : ((int32_T)0)))))
  {
    pa_state_adapter_DW.UnitDelay8_DSTATE = QUIT_CONFIRM_OVERTIME;
  }
  else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_HANDSHAKE)
                  ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)(((LSAD_PARK_IN ==
      rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0)) |
      ((LSAD_PARK_OUT == rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) :
       ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) | ((LSAD_PARK_STRAIGHT ==
    rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
             (((boolean_T)((int32_T)(((rtu_sRelatedModuleInfo->eHandshakeSts ==
      HANDSHAKE_FAIL) ? ((int32_T)1) : ((int32_T)0)) |
      (rtu_sPaStateCommon->sCondiOverFlag.bHandshakOvertime ? ((int32_T)1) :
       ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)))))
  {
    /*   //ÕâÀïÏÈÖ»ÄÃÁËAPAÍË³öÊ§°ÜµÄ */
    pa_state_adapter_DW.UnitDelay8_DSTATE = QUIT_HANDSHAKE_FAIL;

    /* %%%%% */
    /*  elseif(eLsadFuncSts == tLSAD_FuncSts.FUNC_STS_RPA_REMOTE_CONNECT ||... */
    /*         eLsadFuncSts == tLSAD_FuncSts.FUNC_STS_RPA_REMOTE_OK ||...  */
    /*         eLsadFuncSts == tLSAD_FuncSts.FUNC_STS_RPA_PO_CONFIRM ||... */
    /*         eLsadFuncSts == tLSAD_FuncSts.FUNC_STS_RPA_PARK_STRAIGHT ||... */
    /*        ((eLsadSystemSts == tLSAD_SystemSts.LSAD_STS_HANDSHAKE &&(tLSAD_FuncType.LSAD_PARK_IN == eLsadFuncType || tLSAD_FuncType.LSAD_PARK_OUT == eLsadFuncType || tLSAD_FuncType.LSAD_PARK_STRAIGHT == eLsadFuncType )) && ePrkFnct == tPrkFnct.PARK_FUNC_RPA)||... */
    /*       ((eLsadFuncSts == tLSAD_FuncSts.FUNC_STS_RPA_PI_SUPPRESSION ||... */
    /*         eLsadFuncSts == tLSAD_FuncSts.FUNC_STS_RPA_PI_SEARCH ||... */
    /*         eLsadFuncSts == tLSAD_FuncSts.FUNC_STS_RPA_PI_CONFIRM)&& k_RPAScreenSearch))&&... */
    /*        (bPhoneBatLow) */
    /*  	ePAQuitEvnt = tQuitEvnt.QUIT_RPA_LOW_BAT; */
  }
  else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      (((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_REMOTE_CONNECT) ?
      ((int32_T)1) : ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_REMOTE_OK) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_PO_CONFIRM) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
                      FUNC_STS_RPA_PARK_STRAIGHT) ? ((int32_T)1) : ((int32_T)0)))))
        ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)((((boolean_T)
      ((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_HANDSHAKE)
    ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)((((boolean_T)
      ((int32_T)(((LSAD_PARK_IN == rtu_sLastSlaveLsadFsm->eLsadFuncType) ?
      ((int32_T)1) : ((int32_T)0)) | ((LSAD_PARK_OUT ==
      rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0)) | ((LSAD_PARK_STRAIGHT ==
      rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
      ((pa_state_adapter_DW.UnitDelay3_DSTATE == PARK_FUNC_RPA) ? ((int32_T)1) :
       ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
      ((int32_T)0)) | (((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_PI_SUPPRESSION) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_PI_SEARCH) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
       ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_PI_CONFIRM) ?
        ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
      (k_RPAScreenSearch ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                       ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
             (((boolean_T)((int32_T)(((rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkWorkMd ==
      PRK_WORK_EXIT) ? ((int32_T)1) : ((int32_T)0)) &
      ((pa_state_adapter_DW.UnitDelay3_DSTATE == PARK_FUNC_RPA) ? ((int32_T)1) :
       ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)))))
  {
    pa_state_adapter_DW.UnitDelay8_DSTATE = QUIT_RPA_APP_EXIT;

    /*  elseif(eLsadFuncSts == tLSAD_FuncSts.FUNC_STS_RPA_REMOTE_CONNECT)&&... */
    /*        (sCondiOverFlag.bRPACnfmOvertime)   */
    /*  	ePAQuitEvnt = tQuitEvnt.QUIT_RPA_CONNECT_OVERTIME;  %ÔÝÊ±²»ÐèÒªÔ¶³ÌÁ¬½Ó³¬Ê±È·ÈÏ */
    /*  elseif(eLsadFuncSts == tLSAD_FuncSts.FUNC_STS_RPA_REMOTE_CONNECT)&&... */
    /*        (~bGearP)&&... */
    /*        (~bFLDrClose) */
    /*  	ePAQuitEvnt = tQuitEvnt.QUIT_RPA_LEAVE_WO_P;    */
    /*  elseif(eLsadFuncSts == tLSAD_FuncSts.FUNC_STS_RPA_PO_CONFIRM ||... */
    /*         eLsadFuncSts == tLSAD_FuncSts.FUNC_STS_RPA_PARK_STRAIGHT ||... */
    /*        (eLsadSystemSts == tLSAD_SystemSts.LSAD_STS_HANDSHAKE && ePrkFnct == tPrkFnct.PARK_FUNC_RPA && (tLSAD_FuncType.LSAD_PARK_IN == eLsadFuncType || tLSAD_FuncType.LSAD_PARK_OUT == eLsadFuncType || tLSAD_FuncType.LSAD_PARK_STRAIGHT == eLsadFuncType ))||... */
    /*       ((eLsadFuncSts == tLSAD_FuncSts.FUNC_STS_RPA_PI_SUPPRESSION ||... */
    /*         eLsadFuncSts == tLSAD_FuncSts.FUNC_STS_RPA_PI_SEARCH ||... */
    /*         eLsadFuncSts == tLSAD_FuncSts.FUNC_STS_RPA_PI_CONFIRM)&& k_RPAScreenSearch))&&...  */
    /*        (eRPAPrkWakeup ~= tTriStateSwt.SWT_ON) */
    /*  	ePAQuitEvnt = tQuitEvnt.QUIT_RPA_CONN_LOSS; */
    /*  elseif(eLsadFuncSts == tLSAD_FuncSts.FUNC_STS_RPA_PI_CONFIRM ||... */
    /*         eLsadFuncSts == tLSAD_FuncSts.FUNC_STS_RPA_PO_CONFIRM ||... */
    /*         (eLsadSystemSts == tLSAD_SystemSts.LSAD_STS_HANDSHAKE && ePrkFnct == tPrkFnct.PARK_FUNC_RPA)&&...     */
    /*        (sCondiHMI.ePrkFnct == tPrkFnct.PARK_FUNC_RPA)&&... */
    /*        (~sCondiHMI.bBLEScrt) */
    /*  	ePAQuitEvnt = tQuitEvnt.QUIT_RPA_CONN_UNSAFE; */
    /*  elseif(eLsadFuncSts == tLSAD_FuncSts.FUNC_STS_RPA_PI_CONFIRM ||... */
    /*         eLsadFuncSts == tLSAD_FuncSts.FUNC_STS_RPA_PO_CONFIRM)&&... */
    /*        (~sVehCommon.sCondiVCU.bGearP) */
    /*      ePAQuitEvnt = tQuitEvnt.QUIT_RPA_GEAR_NOT_P; */
  }
  else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      (((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_MODE_SELECT) ?
      ((int32_T)1) : ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_APA_PI_SEARCH) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_APA_PI_SUPPRESSION) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
      1) : ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_APA_PO_SUPPRESSION) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
      1) : ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_APA_PI_CONFIRM) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_APA_PO_CONFIRM) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_PO_CONFIRM) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_PARK_STRAIGHT) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
      1) : ((int32_T)0)) | (((boolean_T)((int32_T)
      (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_HANDSHAKE) ?
      ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)((((boolean_T)
      ((int32_T)(((LSAD_PARK_IN == rtu_sLastSlaveLsadFsm->eLsadFuncType) ?
      ((int32_T)1) : ((int32_T)0)) | ((LSAD_PARK_OUT ==
      rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0)) | ((LSAD_PARK_STRAIGHT ==
      rtu_sLastSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_REMOTE_CONNECT) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
      1) : ((int32_T)0)) | ((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_REMOTE_OK) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | (((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
      ((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_PI_SUPPRESSION) ? ((int32_T)1) : ((int32_T)0)) |
                 ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_PI_SEARCH)
    ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_PI_CONFIRM) ?
       ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
      (k_RPAScreenSearch ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                     ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
             (rtu_sDiagInfo->bPASysFail ? ((int32_T)1) : ((int32_T)0)))))
  {
    if ((boolean_T)((int32_T)((rtu_sDiagInfo->sComFail.bComFail ? ((int32_T)1) :
           ((int32_T)0)) & (((boolean_T)((int32_T)
             ((rtu_sDiagInfo->sComFail.bEthFail ? ((int32_T)1) : ((int32_T)0)) ^
              1))) ? ((int32_T)1) : ((int32_T)0)))))
    {
      pa_state_adapter_DW.UnitDelay8_DSTATE = QUIT_INVALID_SIGNAL;
    }
    else if (rtu_sDiagInfo->sUssFail.bUssFail)
    {
      pa_state_adapter_DW.UnitDelay8_DSTATE = QUIT_USS_FAIL;
    }
    else if (rtu_sDiagInfo->sVisionFail.bVisionFail)
    {
      pa_state_adapter_DW.UnitDelay8_DSTATE = QUIT_VISION_FAIL;
    }
    else
    {
      pa_state_adapter_DW.UnitDelay8_DSTATE = QUIT_INTERNAL_FAIL;
    }
  }
  else if (rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_STANDBY)
  {
    pa_state_adapter_DW.UnitDelay8_DSTATE = QUIT_NONE;
  }
  else
  {
    /* no actions */
  }

  /* End of MATLAB Function: '<S3>/PAQuitEvntDet' */

  /* BusCreator: '<S3>/Bus Creator' incorporates:
   *  Constant: '<S44>/Constant'
   *  UnitDelay: '<S3>/Unit Delay8'
   */
  rty_sPaStateAdptr->sPAEvntAdptr.ePABgSrchEvnt = BG_SEARCH_NONE;
  rty_sPaStateAdptr->sPAEvntAdptr.ePAQuitEvnt =
    pa_state_adapter_DW.UnitDelay8_DSTATE;

  /* BusCreator: '<Root>/Bus Creator' incorporates:
   *  BusAssignment: '<Root>/Bus Assignment'
   *  BusAssignment: '<Root>/Bus Assignment1'
   */
  rty_sPaStateAdptr->sDragPrkSlot = pa_state_adapter_ConstB.sDragPrkSlot;
  rty_sPaStateAdptr->sRPAChkList = pa_state_adapter_ConstB.sRPAChkList;

  /* Update for UnitDelay: '<S2>/Unit Delay1' incorporates:
   *  BusAssignment: '<S1>/Bus Assignment'
   *  UnitDelay: '<S1>/Unit Delay4'
   */
  pa_state_adapter_DW.UnitDelay1_DSTATE_c =
    pa_state_adapter_DW.UnitDelay4_DSTATE;

  /* Update for UnitDelay: '<S27>/Unit Delay1' */
  pa_state_adapter_DW.UnitDelay1_DSTATE_e = LocalVar_UnitDelay1_h;

  /* Update for UnitDelay: '<S27>/Unit Delay2' */
  pa_state_adapter_DW.UnitDelay2_DSTATE_c = LocalVar_UnitDelay1_h;

  /* Update for Delay: '<S21>/Delay' */
  pa_state_adapter_DW.bitsForTID0.Delay_DSTATE = LocalVar_Equal1;

  /* Update for Delay: '<S22>/Delay' */
  pa_state_adapter_DW.bitsForTID0.Delay_DSTATE_f = LocalVar_Equal1_k;

  /* Update for UnitDelay: '<S12>/Unit Delay1' incorporates:
   *  UnitDelay: '<S12>/Unit Delay5'
   */
  pa_state_adapter_DW.UnitDelay1_DSTATE_ad =
    pa_state_adapter_DW.UnitDelay5_DSTATE_c;

  /* Update for UnitDelay: '<S1>/Unit Delay2' */
  pa_state_adapter_DW.UnitDelay2_DSTATE = rtu_sLastSlaveLsadFsm->eLsadFuncSts;

  /* Update for UnitDelay: '<S1>/Unit Delay1' incorporates:
   *  UnitDelay: '<S1>/Unit Delay3'
   */
  pa_state_adapter_DW.UnitDelay1_DSTATE_d =
    pa_state_adapter_DW.UnitDelay3_DSTATE;

  /* Update for UnitDelay: '<S6>/Unit Delay3' */
  pa_state_adapter_DW.UnitDelay3_DSTATE_m =
    rtu_sLastMasterLsadFsm->eLsadSystemSts;

  /* Update for UnitDelay: '<S6>/Unit Delay1' */
  pa_state_adapter_DW.bitsForTID0.UnitDelay1_DSTATE_co =
    LocalVar_bPOCnfmInitReset;
}

/* Model initialize function */
void pa_state_adapter_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)&pa_state_adapter_DW, 0,
                sizeof(DW_pa_state_adapter_f_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
