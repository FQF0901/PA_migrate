/*
 * File: lsad_fsm_core.c
 *
 * Code generated for Simulink model 'lsad_fsm_core'.
 *
 * Model version                  : 1.131
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Fri Nov 29 16:33:09 2024
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

#include "lsad_fsm_core.h"
#include "lsad_fsm_adapter_api.h"
#include "lsad_fsm_api.h"
#include "wrapper_api.h"

/* Block signals and states (default storage) */
#define CtrlPara_START_SEC_VAR
#include "proj_MemMap.h"
DW_lsad_fsm_core_T lsad_fsm_core_DW;
#define CtrlPara_STOP_SEC_VAR
#include "proj_MemMap.h"
/* Model step function */
void lsad_fsm_core_step(void)
{
  /* local block i/o variables */
  tRaStateCommon LocalVar_sRaStateCommon;
  tVehCommon LocalVar_sVehCommon;
  tPaStateCommon LocalVar_sPaStateCommon;
  tHpaStateCommon LocalVar_sHpaStateCommon;
  tDiagInfo LocalVar_sDiagInfo;
  tHPAHmiRx LocalVar_sHPAHmiRx;
  tPAHmiRx LocalVar_sPAHmiRx;
  tPaStateAdptr LocalVar_sPaStateAdptr;
  tRAHmiRx LocalVar_sRAHmiRx;
  tRelatedModuleInfo LocalVar_sRelatedModuleInfo;
  tSlaveLsadFsm LocalVar_sSlaveLsadFsm;
  tVehDataRx LocalVar_sVehDataRx;

  /* SignalConversion: '<Root>/Signal Copy23' incorporates:
   *  Inport: '<Root>/sPAHmiRx'
   */
  LocalVar_sPAHmiRx = Get_sPAHmiRx();

  /* SignalConversion: '<Root>/Signal Copy' incorporates:
   *  Inport: '<Root>/sVehDataRx'
   */
  LocalVar_sVehDataRx = Get_sVehDataRx();

  /* SignalConversion: '<Root>/Signal Copy25' incorporates:
   *  Inport: '<Root>/sRAHmiRx'
   */
  LocalVar_sRAHmiRx = Get_sRAHmiRx();

  /* SignalConversion: '<Root>/Signal Copy3' incorporates:
   *  Inport: '<Root>/sRelatedModuleInfo'
   */
  LocalVar_sRelatedModuleInfo = Get_sRelatedModuleInfo();

  /* SignalConversion: '<Root>/Signal Copy26' incorporates:
   *  Inport: '<Root>/sHPAHmiRx'
   */
  LocalVar_sHPAHmiRx = Get_sHPAHmiRx();

  /* SignalConversion: '<Root>/Signal Copy5' incorporates:
   *  Inport: '<Root>/sDiagInfo'
   */
  LocalVar_sDiagInfo = Get_sDiagInfo();

  /* SignalConversion: '<Root>/Signal Copy22' incorporates:
   *  Inport: '<Root>/sSlaveLsadFsm'
   */
  LocalVar_sSlaveLsadFsm = Get_sSlaveLsadFsm();

  /* SignalConversion: '<Root>/Signal Copy24' incorporates:
   *  Inport: '<Root>/sPaStateAdptr'
   */
  LocalVar_sPaStateAdptr = Get_sPaStateAdptr();

  /* ModelReference: '<Root>/common_condition' incorporates:
   *  UnitDelay: '<Root>/Unit Delay5'
   */
  common_condition(&LocalVar_sVehDataRx, &LocalVar_sPAHmiRx, &LocalVar_sRAHmiRx,
                   &LocalVar_sRelatedModuleInfo, &LocalVar_sHPAHmiRx,
                   &LocalVar_sDiagInfo, &lsad_fsm_core_DW.UnitDelay5_DSTATE,
                   &LocalVar_sSlaveLsadFsm, &LocalVar_sPaStateAdptr,
                   &LocalVar_sVehCommon, &LocalVar_sPaStateCommon,
                   &LocalVar_sRaStateCommon, &LocalVar_sHpaStateCommon);

  /* ModelReference generated from: '<Root>/master_lsad_fsm' incorporates:
   *  UnitDelay: '<Root>/Unit Delay1'
   *  UnitDelay: '<Root>/Unit Delay5'
   */
  master_lsad_fsm(&LocalVar_sPAHmiRx, &LocalVar_sPaStateCommon,
                  &LocalVar_sVehCommon, &LocalVar_sVehDataRx,
                  &LocalVar_sRelatedModuleInfo, &LocalVar_sHpaStateCommon,
                  &LocalVar_sSlaveLsadFsm, &LocalVar_sHPAHmiRx,
                  &LocalVar_sRAHmiRx,
                  &LocalVar_sRaStateCommon.sRACondiOverFlag.bRAIntrptOvertime,
                  &LocalVar_sRaStateCommon.sRACondiOverFlag.bRACmpltDurattime,
                  &LocalVar_sRaStateCommon.sRACondiOverFlag.bRACmpltOvertime,
                  &LocalVar_sRaStateCommon.sRACondiOverFlag.bRATrmntDurattime,
                  &LocalVar_sRaStateCommon.sRACondiOverFlag.bRATrmntOvertime,
                  &LocalVar_sRaStateCommon.sRAEvnt.eRAIntrptEvnt,
                  &LocalVar_sRaStateCommon.sRAEvnt.eRATrmntEvnt,
                  &LocalVar_sRaStateCommon.sRAEvnt.eRAIntrptType,
                  &LocalVar_sDiagInfo, &lsad_fsm_core_DW.UnitDelay1_DSTATE,
                  &LocalVar_sPaStateAdptr, &lsad_fsm_core_DW.UnitDelay5_DSTATE);

  /* SignalConversion: '<Root>/Signal Copy10' incorporates:
   *  ModelReference generated from: '<Root>/master_lsad_fsm'
   *  UnitDelay: '<Root>/Unit Delay5'
   */
  Set_sMasterLsadFsm(lsad_fsm_core_DW.UnitDelay5_DSTATE);

  /* SignalConversion: '<Root>/Signal Copy6' incorporates:
   *  ModelReference: '<Root>/common_condition'
   */
  Set_sVehCommon(LocalVar_sVehCommon);

  /* SignalConversion: '<Root>/Signal Copy7' incorporates:
   *  ModelReference: '<Root>/common_condition'
   */
  Set_sPaStateCommon(LocalVar_sPaStateCommon);

  /* SignalConversion: '<Root>/Signal Copy8' */
  Set_sRaStateCommon(LocalVar_sRaStateCommon);

  /* SignalConversion: '<Root>/Signal Copy9' */
  Set_sHpaStateCommon(LocalVar_sHpaStateCommon);

  /* Update for UnitDelay: '<Root>/Unit Delay1' incorporates:
   *  ModelReference generated from: '<Root>/master_lsad_fsm'
   *  UnitDelay: '<Root>/Unit Delay5'
   */
  lsad_fsm_core_DW.UnitDelay1_DSTATE = lsad_fsm_core_DW.UnitDelay5_DSTATE;
}

/* Model initialize function */
void lsad_fsm_core_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)&lsad_fsm_core_DW, 0,
                sizeof(DW_lsad_fsm_core_T));

  /* Model Initialize function for ModelReference Block: '<Root>/common_condition' */
  common_condition_initialize();

  /* Model Initialize function for ModelReference Block: '<Root>/master_lsad_fsm' */
  master_lsad_fsm_initialize();

  /* SystemInitialize for ModelReference: '<Root>/common_condition' */
  common_condition_Init();

  /* SystemInitialize for ModelReference generated from: '<Root>/master_lsad_fsm' */
  master_lsad_fsm_Init();
}

/* Model terminate function */
void lsad_fsm_core_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
