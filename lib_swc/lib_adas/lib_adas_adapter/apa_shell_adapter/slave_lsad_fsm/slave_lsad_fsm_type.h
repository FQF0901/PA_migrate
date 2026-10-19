/*
 * File: slave_lsad_fsm_type.h
 *
 * Code generated for Simulink model 'lsad_fsm_adapter'.
 *
 * Model version                  : 1.135
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Tue Feb 25 10:16:24 2025
 */

#ifndef RTW_HEADER_slave_lsad_fsm_type_h_
#define RTW_HEADER_slave_lsad_fsm_type_h_
#include "emos_rte.h"
#include "rtwtypes.h"

typedef enum
{
  BACKGROUND_MODULE_STS_DISABLE = 0,   /* Default value */
  BACKGROUND_MODULE_STS_ENABLE
}

tBckgrndModuleSts;

typedef struct
{
  tLSAD_FuncType eLsadFuncType;
  tLSAD_FuncSts eLsadFuncSts;
  tLSAD_DriverCtrlCommand eDriverCtrlCommand;
  tBckgrndModuleSts eBckgrndSearchSts;
  tBckgrndModuleSts eBckgrndRecordSts;
  tBckgrndModuleSts eBckgrndCruiseReadySts;

  /* PEB????D?o? */
  uint8_T u8LsadStSResetPEB;
  uint8_T u8Res3[3];
}

tSlaveLsadFsm;

#endif                                 /* RTW_HEADER_slave_lsad_fsm_type_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
