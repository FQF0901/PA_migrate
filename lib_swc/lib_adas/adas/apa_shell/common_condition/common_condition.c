/*
 * File: common_condition.c
 *
 * Code generated for Simulink model 'common_condition'.
 *
 * Model version                  : 3.2188
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Thu Nov 28 16:12:27 2024
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

#include "common_condition.h"

/* System initialize for referenced model: 'common_condition' */
void common_condition_Init(void)
{
  /* SystemInitialize for ModelReference: '<Root>/pa_state_common' */
  pa_state_common_Init();
}

/* Output and update for referenced model: 'common_condition' */
void common_condition(const tVehDataRx *rtu_sVehDataRx, const tPAHmiRx
                      *rtu_sPAHmiRx, const tRAHmiRx *rtu_sRAHmiRx, const
                      tRelatedModuleInfo *rtu_sRelatedModuleInfo, const
                      tHPAHmiRx *rtu_sHPAHmiRx, const tDiagInfo *rtu_sDiagInfo,
                      const tMasterLsadFsm *rtu_sLastMasterLsadFsm, const
                      tSlaveLsadFsm *rtu_sLastSlaveLsadFsm, const tPaStateAdptr *
                      rtu_sPaStateAdptr, tVehCommon *rty_sVehCommon,
                      tPaStateCommon *rty_sPaStateCommon, tRaStateCommon
                      *rty_sRaStateCommon, tHpaStateCommon *rty_sHpaStateCommon)
{
  /* ModelReference: '<Root>/veh_common' */
  veh_common(rtu_sVehDataRx, rtu_sRelatedModuleInfo, rtu_sLastMasterLsadFsm,
             rty_sVehCommon);

  /* ModelReference: '<Root>/hpa_state_common' */
  hpa_state_common(rty_sVehCommon, rtu_sHPAHmiRx, rtu_sVehDataRx,
                   rtu_sRelatedModuleInfo, rtu_sDiagInfo, rtu_sLastMasterLsadFsm,
                   rtu_sLastSlaveLsadFsm, rty_sHpaStateCommon);

  /* ModelReference: '<Root>/pa_state_common' */
  pa_state_common(rty_sVehCommon, rtu_sPAHmiRx, rtu_sVehDataRx,
                  rtu_sRelatedModuleInfo, rtu_sDiagInfo, rtu_sPaStateAdptr,
                  rtu_sLastMasterLsadFsm, rtu_sLastSlaveLsadFsm,
                  rty_sPaStateCommon);

  /* ModelReference: '<Root>/ra_state_common' */
  ra_state_common(rtu_sVehDataRx, rty_sVehCommon, rtu_sRAHmiRx,
                  rtu_sRelatedModuleInfo, rtu_sLastMasterLsadFsm, rtu_sDiagInfo,
                  rtu_sLastSlaveLsadFsm, rty_sRaStateCommon);
}

/* Model initialize function */
void common_condition_initialize(void)
{
  /* Model Initialize function for ModelReference Block: '<Root>/hpa_state_common' */
  hpa_state_common_initialize();

  /* Model Initialize function for ModelReference Block: '<Root>/pa_state_common' */
  pa_state_common_initialize();

  /* Model Initialize function for ModelReference Block: '<Root>/ra_state_common' */
  ra_state_common_initialize();

  /* Model Initialize function for ModelReference Block: '<Root>/veh_common' */
  veh_common_initialize();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
