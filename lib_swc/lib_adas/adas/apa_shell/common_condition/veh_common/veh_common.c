/*
 * File: veh_common.c
 *
 * Code generated for Simulink model 'veh_common'.
 *
 * Model version                  : 3.2222
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Wed Jan 22 15:02:03 2025
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

#include "veh_common.h"

/* Block states (default storage) */
#define CtrlPara_START_SEC_VAR
#include "proj_MemMap.h"
DW_veh_common_f_T veh_common_DW;
#define CtrlPara_STOP_SEC_VAR
#include "proj_MemMap.h"
/* Output and update for referenced model: 'veh_common' */
void veh_common(const tVehDataRx *rtu_sVehDataRx, const tRelatedModuleInfo
                *rtu_sRelatedModuleInfo, const tMasterLsadFsm
                *rtu_sLastMasterLsadFsm, tVehCommon *rty_sVehCommon)
{
  int32_T tmp_0;
  real32_T LocalVar_Switch1;
  uint32_T tmp;
  boolean_T LocalVar_OR1;
  boolean_T LocalVar_OR1_a;
  boolean_T LocalVar_OR1_b;
  boolean_T LocalVar_OR1_k;
  boolean_T LocalVar_RelationalOperator;
  boolean_T LocalVar_bFRDrClose;
  boolean_T LocalVar_bGearConflict;
  boolean_T LocalVar_bObstAppear;

  /* Switch: '<S20>/Switch1' incorporates:
   *  Constant: '<S20>/Constant'
   *  DataStoreWrite: '<S16>/Data Store Write'
   *  Logic: '<S6>/Logical Operator2'
   *  Switch: '<S20>/Switch'
   *  UnitDelay: '<S6>/Unit Delay'
   */
  if ((boolean_T)((int32_T)((veh_common_DW.bitsForTID0.UnitDelay_DSTATE_d ?
         ((int32_T)1) : ((int32_T)0)) ^ 1)))
  {
    veh_common_DW.A_o = 0U;
  }
  else
  {
    /* Sum: '<S20>/Add' incorporates:
     *  Constant: '<S20>/Constant1'
     *  DataStoreRead: '<S16>/Data Store Read'
     */
    tmp_0 = (int32_T)((uint32_T)(((uint32_T)veh_common_DW.A_o) + 1U));
    if ((((uint32_T)veh_common_DW.A_o) + 1U) > 255U)
    {
      tmp_0 = 255;
    }

    /* DataStoreWrite: '<S16>/Data Store Write' incorporates:
     *  Sum: '<S20>/Add'
     */
    veh_common_DW.A_o = (uint8_T)tmp_0;
  }

  /* End of Switch: '<S20>/Switch1' */

  /* Logic: '<S17>/OR1' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S15>/Constant'
   *  Constant: '<S6>/EMZeroConstant'
   *  DataTypeConversion: '<S6>/EMUint8Conversion'
   *  Logic: '<S17>/NOT'
   *  Logic: '<S17>/OR'
   *  Logic: '<S6>/Logical Operator1'
   *  Logic: '<S6>/Logical Operator7'
   *  RelationalOperator: '<S6>/EMEqual'
   *  RelationalOperator: '<S6>/Equal1'
   *  RelationalOperator: '<S6>/Equal11'
   *  UnitDelay: '<S17>/Unit Delay2'
   *  UnitDelay: '<S6>/Unit Delay1'
   */
  LocalVar_OR1 = ((boolean_T)((int32_T)((((boolean_T)((int32_T)
    (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE_SUSPEND) ?
      ((int32_T)1) : ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
    LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) & ((((int32_T)rtu_sRelatedModuleInfo->u8ReqPause) == 1) ?
                     ((int32_T)1) : ((int32_T)0))))) | ((boolean_T)((int32_T)
    ((((boolean_T)((int32_T)((veh_common_DW.bitsForTID0.UnitDelay1_DSTATE_b ?
    ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)) &
     (veh_common_DW.bitsForTID0.UnitDelay2_DSTATE_f ? ((int32_T)1) : ((int32_T)0)))));

  /* Switch: '<S19>/Switch1' incorporates:
   *  Constant: '<S19>/Constant Value2'
   *  Logic: '<S6>/Logical Operator4'
   *  Switch: '<S19>/Switch'
   *  UnitDelay: '<S19>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)((LocalVar_OR1 ? ((int32_T)1) : ((int32_T)0)) ^ 1)))
  {
    veh_common_DW.UnitDelay1_DSTATE = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S21>/Unit Delay1' incorporates:
     *  Constant: '<S6>/Constant3'
     *  Sum: '<S21>/Subtraction'
     */
    veh_common_DW.UnitDelay1_DSTATE += 0.02F;
  }

  /* End of Switch: '<S21>/Switch1' */

  /* Saturate: '<S6>/Saturation2' incorporates:
   *  UnitDelay: '<S21>/Unit Delay1'
   */
  if (veh_common_DW.UnitDelay1_DSTATE > 5.0F)
  {
    LocalVar_Switch1 = 5.0F;
  }
  else if (veh_common_DW.UnitDelay1_DSTATE < 0.0F)
  {
    LocalVar_Switch1 = 0.0F;
  }
  else
  {
    LocalVar_Switch1 = veh_common_DW.UnitDelay1_DSTATE;
  }

  /* End of Saturate: '<S6>/Saturation2' */

  /* RelationalOperator: '<S6>/Relational Operator2' incorporates:
   *  Constant: '<S6>/Constant2'
   */
  LocalVar_bObstAppear = (LocalVar_Switch1 > 0.05F);

  /* Logic: '<S20>/OR1' incorporates:
   *  Constant: '<S16>/Constant'
   *  Constant: '<S6>/Constant1'
   *  DataStoreWrite: '<S18>/Data Store Write'
   *  Logic: '<S20>/NOT'
   *  Logic: '<S20>/OR'
   *  Logic: '<S6>/Logical Operator3'
   *  RelationalOperator: '<S6>/Equal1'
   *  RelationalOperator: '<S6>/Equal2'
   *  RelationalOperator: '<S6>/Equal7'
   *  UnitDelay: '<S20>/Unit Delay2'
   */
  LocalVar_OR1_b = LocalVar_bObstAppear | ((boolean_T)((int32_T)((((boolean_T)
    ((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts != LSAD_STS_STANDBY) ?
                ((int32_T)1) : ((int32_T)0)) & ((((int32_T)veh_common_DW.A_o) <
    150) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
    (veh_common_DW.bitsForTID0.UnitDelay2_DSTATE_o ? ((int32_T)1) : ((int32_T)0)))));

  /* Logic: '<S12>/OR1' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S11>/Constant'
   *  Constant: '<S9>/Constant'
   *  Logic: '<S12>/NOT'
   *  Logic: '<S12>/OR'
   *  Logic: '<S5>/EMAND'
   *  Logic: '<S5>/EMNOT'
   *  Logic: '<S5>/EMOR'
   *  RelationalOperator: '<S5>/Equal1'
   *  RelationalOperator: '<S5>/Equal11'
   *  RelationalOperator: '<S5>/Equal2'
   *  RelationalOperator: '<S6>/Equal1'
   *  UnitDelay: '<S12>/Unit Delay2'
   *  UnitDelay: '<S5>/Unit Delay'
   */
  LocalVar_OR1_a = ((boolean_T)((int32_T)((((boolean_T)((int32_T)
    (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ? ((int32_T)1)
      : ((int32_T)0)) & ((veh_common_DW.UnitDelay_DSTATE_g == LSAD_STS_PP) ?
    ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
    (rtu_sVehDataRx->sVehVCUInfo.bBrkPedal ? ((int32_T)1) : ((int32_T)0))))) |
    ((boolean_T)((int32_T)((((boolean_T)((int32_T)
          ((rtu_sVehDataRx->sVehVCUInfo.bBrkPedal ? ((int32_T)1) : ((int32_T)0))
           & ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
              ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
       (veh_common_DW.bitsForTID0.UnitDelay2_DSTATE_fo ? ((int32_T)1) :
        ((int32_T)0)))));

  /* BusAssignment: '<S2>/Bus Assignment' incorporates:
   *  Constant: '<S23>/Constant'
   *  Constant: '<S8>/EMZeroConstant'
   *  DataTypeConversion: '<S8>/EMUint8Conversion'
   *  RelationalOperator: '<S7>/Equal2'
   *  RelationalOperator: '<S8>/Equal'
   */
  (void)memset(&rty_sVehCommon->sCondiPlatform, 0, sizeof(tCondiPlatform));
  rty_sVehCommon->sCondiPlatform.ePlatPPFailReason = PP_FAIL_DEFAULT;
  rty_sVehCommon->sCondiPlatform.bRecomdSlot = (((int32_T)
    rtu_sRelatedModuleInfo->u8StatusParkin) == 11);
  rty_sVehCommon->sCondiPlatform.bObstAppear = LocalVar_OR1_b;
  rty_sVehCommon->sCondiPlatform.bPrkCtrlFail =
    (rtu_sRelatedModuleInfo->eCtrlSts == APA_CTRL_FAULT);
  rty_sVehCommon->sCondiPlatform.bActvStsNeedRlsBrk = LocalVar_OR1_a;

  /* Switch: '<S69>/Switch1' incorporates:
   *  Constant: '<S69>/Constant'
   *  DataStoreWrite: '<S67>/Data Store Write'
   *  Logic: '<S32>/Logical Operator2'
   *  Switch: '<S69>/Switch'
   *  UnitDelay: '<S32>/Unit Delay'
   */
  if ((boolean_T)((int32_T)((veh_common_DW.bitsForTID0.UnitDelay_DSTATE_c ?
         ((int32_T)1) : ((int32_T)0)) ^ 1)))
  {
    veh_common_DW.A = 0U;
  }
  else
  {
    /* Sum: '<S69>/Add' incorporates:
     *  Constant: '<S69>/Constant1'
     *  DataStoreRead: '<S67>/Data Store Read'
     */
    tmp = ((uint32_T)veh_common_DW.A) + 1U;
    if ((((uint32_T)veh_common_DW.A) + 1U) > 65535U)
    {
      tmp = 65535U;
    }

    /* DataStoreWrite: '<S65>/Data Store Write' incorporates:
     *  Sum: '<S69>/Add'
     */
    veh_common_DW.A = (uint16_T)tmp;
  }

  /* End of Switch: '<S67>/Switch1' */

  /* Logic: '<S66>/OR1' incorporates:
   *  Constant: '<S30>/Constant1'
   *  Constant: '<S30>/Constant2'
   *  Constant: '<S30>/Constant3'
   *  Constant: '<S30>/Constant7'
   *  Constant: '<S62>/Constant'
   *  Constant: '<S63>/Constant'
   *  DataStoreWrite: '<S65>/Data Store Write'
   *  Logic: '<S30>/Logical Operator'
   *  Logic: '<S30>/Logical Operator1'
   *  Logic: '<S30>/Logical Operator4'
   *  Logic: '<S30>/Logical Operator6'
   *  Logic: '<S66>/NOT'
   *  Logic: '<S66>/OR'
   *  RelationalOperator: '<S30>/Equal10'
   *  RelationalOperator: '<S30>/Equal3'
   *  RelationalOperator: '<S30>/Equal4'
   *  RelationalOperator: '<S30>/Equal5'
   *  RelationalOperator: '<S30>/Equal6'
   *  RelationalOperator: '<S30>/Equal9'
   *  UnitDelay: '<S30>/Unit Delay1'
   *  UnitDelay: '<S30>/Unit Delay2'
   *  UnitDelay: '<S66>/Unit Delay2'
   */
  LocalVar_OR1_k = ((boolean_T)((int32_T)((((boolean_T)((int32_T)
    (((veh_common_DW.UnitDelay1_DSTATE_c == P_GEAR) ? ((int32_T)1) : ((int32_T)0))
     & (((boolean_T)((int32_T)(((rtu_sVehDataRx->sVehVCUInfo.eVehActualGear ==
    D_GEAR) ? ((int32_T)1) : ((int32_T)0)) |
    ((rtu_sVehDataRx->sVehVCUInfo.eVehActualGear == R_GEAR) ? ((int32_T)1) :
     ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | (((boolean_T)((int32_T)
    (((rtu_sVehDataRx->sVehBCMInfo.eAjarDrFLSts == DOOR_INAJAR) ? ((int32_T)1) :
      ((int32_T)0)) & ((veh_common_DW.UnitDelay2_DSTATE == DOOR_AJAR) ?
                       ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                     ((int32_T)0))))) | ((boolean_T)((int32_T)(((veh_common_DW.A
    < k_EPBUnexpFilterTime) ? ((int32_T)1) : ((int32_T)0)) &
    (veh_common_DW.bitsForTID0.UnitDelay2_DSTATE_ok ? ((int32_T)1) : ((int32_T)0)))));

  /* Switch: '<S71>/Switch' incorporates:
   *  Constant: '<S71>/Constant Value2'
   *  UnitDelay: '<S71>/Unit Delay1'
   */
  veh_common_DW.UnitDelay1_DSTATE_h = 0.0F;

  /* Switch: '<S43>/Switch1' incorporates:
   *  Constant: '<S35>/Constant'
   *  Constant: '<S36>/Constant'
   *  Constant: '<S37>/Constant'
   *  Constant: '<S38>/Constant'
   *  Constant: '<S39>/Constant'
   *  Constant: '<S40>/Constant'
   *  Constant: '<S41>/Constant'
   *  Constant: '<S42>/Constant'
   *  Constant: '<S43>/Constant Value2'
   *  Logic: '<S25>/EMNOT'
   *  Logic: '<S25>/EMOR'
   *  Logic: '<S25>/Logical Operator1'
   *  Logic: '<S25>/Logical Operator10'
   *  Logic: '<S25>/Logical Operator11'
   *  Logic: '<S25>/Logical Operator13'
   *  Logic: '<S25>/Logical Operator2'
   *  Logic: '<S25>/Logical Operator9'
   *  Logic: '<S25>/NOT'
   *  RelationalOperator: '<S25>/EMEqual1'
   *  RelationalOperator: '<S25>/EMEqual3'
   *  RelationalOperator: '<S25>/Equal1'
   *  RelationalOperator: '<S25>/Equal10'
   *  RelationalOperator: '<S25>/Equal11'
   *  RelationalOperator: '<S25>/Equal12'
   *  RelationalOperator: '<S25>/Equal8'
   *  RelationalOperator: '<S25>/Equal9'
   *  RelationalOperator: '<S6>/Equal1'
   *  Switch: '<S43>/Switch'
   *  UnitDelay: '<S43>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
           (((rtu_sLastMasterLsadFsm->eLsadSystemSts != LSAD_STS_ACTIVE_SUSPEND)
             ? ((int32_T)1) : ((int32_T)0)) &
            ((rtu_sLastMasterLsadFsm->eLsadSystemSts != LSAD_STS_ACTIVE) ?
             ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
        (((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)((((boolean_T)((int32_T)(((WHLSPD_FORWARD ==
      rtu_sVehDataRx->sVehESCInfo.eWhlDirRL) ? ((int32_T)1) : ((int32_T)0)) ^ 1)))
    ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)(((WHLSPD_FORWARD ==
    rtu_sVehDataRx->sVehESCInfo.eWhlDirRR) ? ((int32_T)1) : ((int32_T)0)) ^ 1)))
    ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
       (((boolean_T)((int32_T)(((rtu_sVehDataRx->sVehVCUInfo.eVehActualGear ==
      R_GEAR) ? ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
    ? ((int32_T)1) : ((int32_T)0)) | (rtu_sVehDataRx->sVehESCInfo.bVehStandStill
    ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
            (((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((rtu_sVehDataRx->sVehESCInfo.bVehStandStill ? ((int32_T)1) : ((int32_T)0))
       | (((boolean_T)((int32_T)((((boolean_T)((int32_T)(((WHLSPD_BACKWARD ==
      rtu_sVehDataRx->sVehESCInfo.eWhlDirRL) ? ((int32_T)1) : ((int32_T)0)) ^ 1)))
    ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)(((WHLSPD_BACKWARD ==
    rtu_sVehDataRx->sVehESCInfo.eWhlDirRR) ? ((int32_T)1) : ((int32_T)0)) ^ 1)))
    ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
      (((rtu_sVehDataRx->sVehVCUInfo.eVehActualGear == D_GEAR) ? ((int32_T)1) :
        ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
             ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)))))
  {
    veh_common_DW.UnitDelay1_DSTATE_a = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S43>/Unit Delay1' incorporates:
     *  Constant: '<S25>/Constant3'
     *  Sum: '<S43>/Subtraction'
     */
    veh_common_DW.UnitDelay1_DSTATE_a += s_APPManLoopSec;
  }

  /* End of Switch: '<S43>/Switch1' */

  /* Switch: '<S50>/Switch1' incorporates:
   *  Constant: '<S26>/Constant8'
   *  Constant: '<S44>/Constant'
   *  Constant: '<S45>/Constant'
   *  Constant: '<S46>/Constant'
   *  Constant: '<S47>/Constant'
   *  Constant: '<S48>/Constant'
   *  Constant: '<S49>/Constant'
   *  Constant: '<S50>/Constant Value2'
   *  Logic: '<S26>/EMNOT'
   *  Logic: '<S26>/Logical Operator1'
   *  Logic: '<S26>/Logical Operator2'
   *  Logic: '<S26>/Logical Operator3'
   *  Logic: '<S26>/Logical Operator4'
   *  Logic: '<S26>/Logical Operator5'
   *  Logic: '<S26>/Logical Operator6'
   *  RelationalOperator: '<S26>/Equal2'
   *  RelationalOperator: '<S26>/Equal3'
   *  RelationalOperator: '<S26>/Equal4'
   *  RelationalOperator: '<S26>/Equal5'
   *  RelationalOperator: '<S26>/Equal6'
   *  RelationalOperator: '<S26>/Equal7'
   *  RelationalOperator: '<S26>/Relational Operator3'
   *  Switch: '<S50>/Switch'
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)(((rtu_sVehDataRx->sVehESCInfo.f32VehSpdKph <= 0.8F) ?
         ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)((((boolean_T)
              ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      (((WHLSPD_FORWARD == rtu_sVehDataRx->sVehESCInfo.eWhlDirRL) ? ((int32_T)1)
    : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)
      ((int32_T)(((WHLSPD_FORWARD == rtu_sVehDataRx->sVehESCInfo.eWhlDirRR) ?
      ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ?
                          ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
      (((rtu_sVehDataRx->sVehVCUInfo.eVehActualGear == D_GEAR) ? ((int32_T)1) :
        ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
             ((int32_T)0)) & (((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)(((WHLSPD_BACKWARD ==
      rtu_sVehDataRx->sVehESCInfo.eWhlDirRL) ? ((int32_T)1) : ((int32_T)0)) ^ 1)))
        ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
      (((WHLSPD_BACKWARD == rtu_sVehDataRx->sVehESCInfo.eWhlDirRR) ? ((int32_T)1)
    : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
      ((int32_T)0)) | (((boolean_T)((int32_T)
      (((rtu_sVehDataRx->sVehVCUInfo.eVehActualGear == R_GEAR) ? ((int32_T)1) :
        ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
             ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)))))
  {
    veh_common_DW.UnitDelay1_DSTATE_l = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S50>/Unit Delay1' incorporates:
     *  Constant: '<S26>/Constant3'
     *  Sum: '<S50>/Subtraction'
     */
    veh_common_DW.UnitDelay1_DSTATE_l += 0.02F;
  }

  /* End of Switch: '<S50>/Switch1' */

  /* Switch: '<S60>/Switch1' incorporates:
   *  Constant: '<S29>/Constant'
   *  Constant: '<S54>/Constant'
   *  Constant: '<S55>/Constant'
   *  Constant: '<S56>/Constant'
   *  Constant: '<S57>/Constant'
   *  Constant: '<S58>/Constant'
   *  Constant: '<S59>/Constant'
   *  Constant: '<S60>/Constant Value2'
   *  Logic: '<S29>/EMNOT'
   *  Logic: '<S29>/Logical Operator1'
   *  Logic: '<S29>/Logical Operator10'
   *  Logic: '<S29>/Logical Operator11'
   *  Logic: '<S29>/Logical Operator12'
   *  Logic: '<S29>/Logical Operator13'
   *  Logic: '<S29>/Logical Operator9'
   *  RelationalOperator: '<S29>/Equal1'
   *  RelationalOperator: '<S29>/Equal10'
   *  RelationalOperator: '<S29>/Equal11'
   *  RelationalOperator: '<S29>/Equal12'
   *  RelationalOperator: '<S29>/Equal2'
   *  RelationalOperator: '<S29>/Equal8'
   *  RelationalOperator: '<S29>/Equal9'
   *  Switch: '<S60>/Switch'
   *  UnitDelay: '<S60>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
               ((((boolean_T)((int32_T)((((boolean_T)((int32_T)(((WHLSPD_FORWARD
    == rtu_sVehDataRx->sVehESCInfo.eWhlDirRL) ? ((int32_T)1) : ((int32_T)0)) ^ 1)))
    ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)(((WHLSPD_FORWARD ==
    rtu_sVehDataRx->sVehESCInfo.eWhlDirRR) ? ((int32_T)1) : ((int32_T)0)) ^ 1)))
    ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
                (((boolean_T)((int32_T)
      (((rtu_sVehDataRx->sVehVCUInfo.eVehActualGear == R_GEAR) ? ((int32_T)1) :
        ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
             ((int32_T)0)) & (((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)(((WHLSPD_BACKWARD ==
      rtu_sVehDataRx->sVehESCInfo.eWhlDirRL) ? ((int32_T)1) : ((int32_T)0)) ^ 1)))
        ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
      (((WHLSPD_BACKWARD == rtu_sVehDataRx->sVehESCInfo.eWhlDirRR) ? ((int32_T)1)
    : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
      ((int32_T)0)) | (((boolean_T)((int32_T)
      (((rtu_sVehDataRx->sVehVCUInfo.eVehActualGear == D_GEAR) ? ((int32_T)1) :
        ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
             ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
        ((rtu_sVehDataRx->sVehESCInfo.f32VehSpdKph <= 0.8F) ? ((int32_T)1) :
         ((int32_T)0)))))
  {
    veh_common_DW.UnitDelay1_DSTATE_k = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S62>/Unit Delay1' incorporates:
     *  Constant: '<S31>/Constant3'
     *  Sum: '<S62>/Subtraction'
     */
    veh_common_DW.UnitDelay1_DSTATE_k += 0.02F;
  }

  /* End of Switch: '<S62>/Switch1' */

  /* MATLAB Function: '<S27>/GearConflict' */
  if (rtu_sRelatedModuleInfo->eHandshakeGearReq != VEHI_GEAR_INVALID)
  {
    if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
                 ((((boolean_T)((int32_T)
        (((rtu_sVehDataRx->sVehVCUInfo.eVehActualGear == D_GEAR) ? ((int32_T)1) :
          ((int32_T)0)) & ((rtu_sRelatedModuleInfo->eHandshakeGearReq ==
                            VEHI_GEAR_D) ? ((int32_T)1) : ((int32_T)0))))) ?
                   ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
        (((rtu_sVehDataRx->sVehVCUInfo.eVehActualGear == N_GEAR) ? ((int32_T)1) :
          ((int32_T)0)) & ((rtu_sRelatedModuleInfo->eHandshakeGearReq ==
                            VEHI_GEAR_N) ? ((int32_T)1) : ((int32_T)0))))) ?
        ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
              (((boolean_T)((int32_T)
                            (((rtu_sVehDataRx->sVehVCUInfo.eVehActualGear ==
        R_GEAR) ? ((int32_T)1) : ((int32_T)0)) &
                  ((rtu_sRelatedModuleInfo->eHandshakeGearReq == VEHI_GEAR_R) ?
                   ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)))))
           ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
             (((rtu_sVehDataRx->sVehVCUInfo.eVehActualGear == P_GEAR) ?
               ((int32_T)1) : ((int32_T)0)) &
              ((rtu_sRelatedModuleInfo->eHandshakeGearReq == VEHI_GEAR_P) ?
               ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)))))
    {
      /* %D */
      /* %N */
      /* %R */
      /* P */
      LocalVar_bGearConflict = false;
    }
    else
    {
      LocalVar_bGearConflict = true;
    }
  }
  else
  {
    LocalVar_bGearConflict = false;
  }

  /* End of MATLAB Function: '<S27>/GearConflict' */

  /* RelationalOperator: '<S28>/Equal4' incorporates:
   *  Constant: '<S53>/Constant'
   */
  LocalVar_bFRDrClose = (rtu_sVehDataRx->sVehVCUInfo.eSysPwrMd == SYS_PWR_MD_OFF);

  /* Switch: '<S52>/Switch1' incorporates:
   *  Constant: '<S28>/Constant13'
   *  Constant: '<S52>/Constant3'
   *  Sum: '<S52>/Add'
   *  UnitDelay: '<S52>/Unit Delay'
   */
  if (LocalVar_bFRDrClose)
  {
    LocalVar_Switch1 = veh_common_DW.UnitDelay_DSTATE + s_APPManLoopSec;
  }
  else
  {
    LocalVar_Switch1 = 0.0F;
  }

  /* End of Switch: '<S52>/Switch1' */

  /* RelationalOperator: '<S52>/Relational Operator' incorporates:
   *  Constant: '<S28>/Constant3'
   */
  LocalVar_RelationalOperator = (LocalVar_Switch1 > k_PwrMdOffFilterTime);

  /* BusAssignment: '<S3>/Bus Assignment' incorporates:
   *  Constant: '<S25>/Constant1'
   *  Constant: '<S26>/Constant1'
   *  Constant: '<S29>/Constant5'
   *  Constant: '<S29>/Constant7'
   *  Constant: '<S31>/Constant1'
   *  Constant: '<S32>/Constant6'
   *  Constant: '<S33>/Constant1'
   *  Constant: '<S3>/Constant9'
   *  Constant: '<S54>/Constant'
   *  Constant: '<S55>/Constant'
   *  Logic: '<S24>/AND3'
   *  Logic: '<S24>/Logical Operator1'
   *  Logic: '<S3>/EMNOT'
   *  RelationalOperator: '<S25>/Relational Operator'
   *  RelationalOperator: '<S26>/Relational Operator'
   *  RelationalOperator: '<S29>/Equal1'
   *  RelationalOperator: '<S29>/Equal3'
   *  RelationalOperator: '<S29>/Equal6'
   *  RelationalOperator: '<S30>/Equal32'
   *  RelationalOperator: '<S31>/Relational Operator'
   *  RelationalOperator: '<S32>/Equal'
   *  RelationalOperator: '<S33>/Equal2'
   *  Switch: '<S52>/Switch'
   *  UnitDelay: '<S43>/Unit Delay1'
   *  UnitDelay: '<S50>/Unit Delay1'
   *  UnitDelay: '<S62>/Unit Delay1'
   *  UnitDelay: '<S71>/Unit Delay1'
   */
  (void)memset(&rty_sVehCommon->sCondiVeh, 0, sizeof(tCondiVeh));
  rty_sVehCommon->sCondiVeh.bVehStill =
    rtu_sVehDataRx->sVehESCInfo.bVehStandStill;
  rty_sVehCommon->sCondiVeh.bPrkOverSlope = (veh_common_DW.UnitDelay1_DSTATE_h >=
    k_SlopeOverTime);
  rty_sVehCommon->sCondiVeh.bMoveConflict = (veh_common_DW.UnitDelay1_DSTATE_a >
    k_MoveConflictOverTime);
  rty_sVehCommon->sCondiVeh.bMoveSame = (veh_common_DW.UnitDelay1_DSTATE_l >
    0.2F);
  rty_sVehCommon->sCondiVeh.bDrvBlock = rtu_sVehDataRx->sVehVCUInfo.bVehBlock;
  rty_sVehCommon->sCondiVeh.bVehSlip = (veh_common_DW.UnitDelay1_DSTATE_k > 0.6F);
  rty_sVehCommon->sCondiVeh.bTirePressNorm =
    (rtu_sVehDataRx->sVehBCMInfo.eTyreWrnSts == TYRE_SYSTEM_NORMAL);
  rty_sVehCommon->sCondiVeh.bDrvAssistNoActv =
    rtu_sVehDataRx->sVehESCInfo.bDAActive ^ 1;
  rty_sVehCommon->sCondiVeh.bEPBClosed = (rtu_sVehDataRx->sVehESCInfo.eEPBStatus
    == EPB_CLAMPED);
  rty_sVehCommon->sCondiVeh.bEPBUnexp = false;
  rty_sVehCommon->sCondiVeh.bGearPosConflict = LocalVar_bGearConflict;
  rty_sVehCommon->sCondiVeh.bExterActualNorm = ((boolean_T)((int32_T)
    ((((boolean_T)((int32_T)((rtu_sVehDataRx->sExtCdtnMiss.bBrakingFail ?
    ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)) &
     (((boolean_T)((int32_T)((rtu_sVehDataRx->sExtCdtnMiss.bTractionFail ?
    ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) &
    ((boolean_T)((int32_T)((rtu_sVehDataRx->sExtCdtnMiss.bSteeringFail ?
        ((int32_T)1) : ((int32_T)0)) ^ 1)));
  rty_sVehCommon->sCondiVeh.bGearNorm =
    (rtu_sVehDataRx->sVehVCUInfo.eVehActualGear != NONE_GEAR);
  rty_sVehCommon->sCondiVeh.bGearP = (rtu_sVehDataRx->sVehVCUInfo.eVehActualGear
    == P_GEAR);
  rty_sVehCommon->sCondiVeh.bGearR = (rtu_sVehDataRx->sVehVCUInfo.eVehActualGear
    == R_GEAR);
  rty_sVehCommon->sCondiVeh.bSysPwrMdOff = LocalVar_bFRDrClose &
    LocalVar_RelationalOperator;
  rty_sVehCommon->sCondiVeh.bESCPulFail = false;

  /* Switch: '<S52>/Switch3' incorporates:
   *  Constant: '<S52>/Constant2'
   *  Logic: '<S28>/Logical Operator2'
   *  Switch: '<S52>/Switch2'
   *  UnitDelay: '<S52>/Unit Delay'
   */
  if ((boolean_T)((int32_T)((LocalVar_bFRDrClose ? ((int32_T)1) : ((int32_T)0)) ^
        1)))
  {
    veh_common_DW.UnitDelay_DSTATE = 0.0F;
  }
  else if ((boolean_T)((int32_T)((LocalVar_RelationalOperator ? ((int32_T)1) :
              ((int32_T)0)) ^ 1)))
  {
    veh_common_DW.UnitDelay_DSTATE = LocalVar_Switch1;
  }
  else
  {
    /* no actions */
  }

  /* End of Switch: '<S52>/Switch3' */

  /* Outputs for Atomic SubSystem: '<Root>/CondiDoorSblt' */
  /* BusCreator: '<S1>/Bus Creator' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant3'
   *  Constant: '<S1>/Constant4'
   *  Constant: '<S1>/Constant5'
   *  Constant: '<S4>/Constant'
   *  RelationalOperator: '<S1>/Equal'
   *  RelationalOperator: '<S1>/Equal1'
   *  RelationalOperator: '<S1>/Equal2'
   *  RelationalOperator: '<S1>/Equal3'
   *  RelationalOperator: '<S1>/Equal4'
   *  RelationalOperator: '<S1>/Equal5'
   *  RelationalOperator: '<S1>/Equal6'
   */
  rty_sVehCommon->sCondiDoorSblt.bFLDrClose =
    (rtu_sVehDataRx->sVehBCMInfo.eAjarDrFLSts != DOOR_AJAR);
  rty_sVehCommon->sCondiDoorSblt.bFRDrClose =
    (rtu_sVehDataRx->sVehBCMInfo.eAjarDrFRSts != DOOR_AJAR);
  rty_sVehCommon->sCondiDoorSblt.bRLDrClose =
    (rtu_sVehDataRx->sVehBCMInfo.eAjarDrRLSts != DOOR_AJAR);
  rty_sVehCommon->sCondiDoorSblt.bRRDrClose =
    (rtu_sVehDataRx->sVehBCMInfo.eAjarDrRRSts != DOOR_AJAR);
  rty_sVehCommon->sCondiDoorSblt.bHoodDrClose =
    (rtu_sVehDataRx->sVehBCMInfo.eAjarHoodSts != DOOR_AJAR);
  rty_sVehCommon->sCondiDoorSblt.bTailGateClose =
    (rtu_sVehDataRx->sVehBCMInfo.eAjarTailGateSts != DOOR_AJAR);
  rty_sVehCommon->sCondiDoorSblt.bSeatbltAct =
    (rtu_sVehDataRx->sVehBCMInfo.eDrvSeatbltSts == SEATBLT_ACTIVE);
  rty_sVehCommon->sCondiDoorSblt.u8Res = 0U;

  /* End of Outputs for SubSystem: '<Root>/CondiDoorSblt' */

  /* Update for UnitDelay: '<S6>/Unit Delay' */
  veh_common_DW.bitsForTID0.UnitDelay_DSTATE_d = LocalVar_OR1_b;

  /* Update for UnitDelay: '<S6>/Unit Delay1' */
  veh_common_DW.bitsForTID0.UnitDelay1_DSTATE_b = LocalVar_bObstAppear;

  /* Update for UnitDelay: '<S19>/Unit Delay2' */
  veh_common_DW.bitsForTID0.UnitDelay2_DSTATE_f = LocalVar_OR1;

  /* Update for UnitDelay: '<S20>/Unit Delay2' */
  veh_common_DW.bitsForTID0.UnitDelay2_DSTATE_o = LocalVar_OR1_b;

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  veh_common_DW.UnitDelay_DSTATE_g = rtu_sLastMasterLsadFsm->eLsadSystemSts;

  /* Update for UnitDelay: '<S12>/Unit Delay2' */
  veh_common_DW.bitsForTID0.UnitDelay2_DSTATE_fo = LocalVar_OR1_a;

  /* Update for UnitDelay: '<S32>/Unit Delay' */
  veh_common_DW.bitsForTID0.UnitDelay_DSTATE_c = LocalVar_OR1_k;

  /* Update for UnitDelay: '<S32>/Unit Delay2' */
  veh_common_DW.UnitDelay2_DSTATE = rtu_sVehDataRx->sVehBCMInfo.eAjarDrFLSts;

  /* Update for UnitDelay: '<S32>/Unit Delay1' */
  veh_common_DW.UnitDelay1_DSTATE_c = rtu_sVehDataRx->sVehVCUInfo.eVehActualGear;

  /* Update for UnitDelay: '<S68>/Unit Delay2' */
  veh_common_DW.bitsForTID0.UnitDelay2_DSTATE_ok = LocalVar_OR1_k;
}

/* Model initialize function */
void veh_common_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)&veh_common_DW, 0,
                sizeof(DW_veh_common_f_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
