/*
 * File: common_condition_adapter.c
 *
 * Code generated for Simulink model 'common_condition_adapter'.
 *
 * Model version                  : 3.2189
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Thu Nov 28 16:37:47 2024
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

#include "common_condition_adapter.h"

/* Output and update for referenced model: 'common_condition_adapter' */
void common_condition_adapter(const tVehCommon *rtu_sVehCommon, const tPAHmiRx
  *rtu_sPAHmiRx, const tVehDataRx *rtu_sVehDataRx, const tMasterLsadFsm
  *rtu_sLastMasterLsadFsm, const tDiagInfo *rtu_sDiagInfo, const tPaStateCommon *
  rtu_sPaStateCommon, const tSlaveLsadFsm *rtu_sLastSlaveLsadFsm, const
  tRelatedModuleInfo *rtu_sRelatedModuleInfo, tPaStateAdptr *rty_sPaStateAdptr)
{
  /* ModelReference: '<Root>/pa_state_adapter' */
  pa_state_adapter(rtu_sVehCommon, rtu_sPAHmiRx, rtu_sVehDataRx,
                   rtu_sLastMasterLsadFsm, rtu_sDiagInfo, rtu_sPaStateCommon,
                   rtu_sLastSlaveLsadFsm, rtu_sRelatedModuleInfo,
                   rty_sPaStateAdptr);
}

/* Model initialize function */
void common_condition_adapter_initialize(void)
{
  /* Model Initialize function for ModelReference Block: '<Root>/pa_state_adapter' */
  pa_state_adapter_initialize();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
