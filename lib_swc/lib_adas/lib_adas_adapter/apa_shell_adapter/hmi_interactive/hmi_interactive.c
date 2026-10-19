/*
 * File: hmi_interactive.c
 *
 * Code generated for Simulink model 'hmi_interactive'.
 *
 * Model version                  : 3.1280
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Wed Dec  4 15:22:43 2024
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

#include "hmi_interactive.h"

/* Block states (default storage) */
#define CtrlPara_START_SEC_VAR
#include "proj_MemMap.h"
DW_hmi_interactive_f_T hmi_interactive_DW;
#define CtrlPara_STOP_SEC_VAR
#include "proj_MemMap.h"
/* System initialize for referenced model: 'hmi_interactive' */
void hmi_interactive_Init(void)
{
  /* SystemInitialize for ModelReference: '<Root>/hmi_common' */
  hmi_common_Init();
}

/* Output and update for referenced model: 'hmi_interactive' */
void hmi_interactive(const tHpaStateCommon *rtu_sHpaStateCommon, const
                     tRaStateCommon *rtu_sRaStateCommon, const tPaStateCommon
                     *rtu_sPaStateCommon, const tRelatedModuleInfo
                     *rtu_sRelatedModuleInfo, const tVehDataRx *rtu_sVehDataRx,
                     const tVehCommon *rtu_sVehCommon, const tPAHmiRx
                     *rtu_sPAHmiRx, const tPecpPLDInfo *rtu_sPecpPLDInfo, const
                     tMsgMnger_PathSegment *rtu_sPathSegment, const
                     tPaStateAdptr *rtu_sPaStateAdptr, const tMasterLsadFsm
                     *rtu_sMasterLsadFsm, const tSlaveLsadFsm *rtu_sSlaveLsadFsm,
                     tHMIComDisp *rty_sHMIComDisp, tMsgMnger_TextDisp
                     *rty_sMsgMnger_TextDisp, DragParkingLot
                     *rty_sDragParkingLot)
{
  /* ModelReference: '<Root>/hmi_common' */
  hmi_common(rtu_sPaStateCommon, rtu_sRelatedModuleInfo, rtu_sPAHmiRx,
             rtu_sPecpPLDInfo, rtu_sVehCommon, rtu_sPathSegment,
             rtu_sPaStateAdptr, rtu_sMasterLsadFsm, rtu_sSlaveLsadFsm,
             rty_sHMIComDisp, rty_sDragParkingLot,
             &hmi_interactive_DW.sFusionDisp);

  /* ModelReference: '<Root>/hmi_output' */
  hmi_output(rty_sHMIComDisp, rtu_sPaStateCommon, rtu_sRaStateCommon,
             rtu_sHpaStateCommon, rtu_sVehDataRx, rtu_sRelatedModuleInfo,
             rtu_sVehCommon, rtu_sMasterLsadFsm, rtu_sSlaveLsadFsm,
             rtu_sPaStateAdptr, rty_sMsgMnger_TextDisp);
}

/* Model initialize function */
void hmi_interactive_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) memset((void *) &hmi_interactive_DW, 0,
                sizeof(DW_hmi_interactive_f_T));

  /* Model Initialize function for ModelReference Block: '<Root>/hmi_common' */
  hmi_common_initialize();

  /* Model Initialize function for ModelReference Block: '<Root>/hmi_output' */
  hmi_output_initialize();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
