/*
 * File: veh_common.h
 *
 * Code generated for Simulink model 'veh_common'.
 *
 * Model version                  : 3.2220
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Dec  2 16:04:28 2024
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

#ifndef RTW_HEADER_veh_common_h_
#define RTW_HEADER_veh_common_h_
#include <string.h>
#include "lsad_fsm_core_type.h"
#include "master_lsad_fsm_type.h"
#include "slave_lsad_fsm_type.h"
#include "common_condition_type.h"
#ifndef veh_common_COMMON_INCLUDES_
#define veh_common_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* veh_common_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Includes for objects with custom storage classes. */
#include "project_const_common.h"
#include "calib_lsad_fsm.h"

/* Block signals and states (default storage) for model 'veh_common' */
#ifndef veh_common_MDLREF_HIDE_CHILD_

typedef struct
{
  real32_T UnitDelay1_DSTATE;          /* '<S19>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_h;        /* '<S69>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_a;        /* '<S41>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_l;        /* '<S48>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_k;        /* '<S60>/Unit Delay1' */
  real32_T UnitDelay_DSTATE;           /* '<S50>/Unit Delay' */
  tVehActualGear UnitDelay1_DSTATE_c;  /* '<S30>/Unit Delay1' */
  tAjarDrSts UnitDelay2_DSTATE;        /* '<S30>/Unit Delay2' */
  struct
  {
    uint_T UnitDelay_DSTATE_d:1;       /* '<S6>/Unit Delay' */
    uint_T UnitDelay1_DSTATE_b:1;      /* '<S6>/Unit Delay1' */
    uint_T UnitDelay2_DSTATE_f:1;      /* '<S17>/Unit Delay2' */
    uint_T UnitDelay2_DSTATE_o:1;      /* '<S18>/Unit Delay2' */
    uint_T UnitDelay2_DSTATE_fo:1;     /* '<S12>/Unit Delay2' */
    uint_T UnitDelay_DSTATE_c:1;       /* '<S30>/Unit Delay' */
    uint_T UnitDelay2_DSTATE_ok:1;     /* '<S66>/Unit Delay2' */
  }
  bitsForTID0;

  tLSAD_SystemSts UnitDelay_DSTATE_g;  /* '<S5>/Unit Delay' */
  uint16_T A;                          /* '<S65>/Data Store Memory' */
  uint8_T A_o;                         /* '<S16>/Data Store Memory' */
}
DW_veh_common_f_T;

#endif                                 /*veh_common_MDLREF_HIDE_CHILD_*/

extern void veh_common(const tVehDataRx *rtu_sVehDataRx, const
  tRelatedModuleInfo *rtu_sRelatedModuleInfo, const tMasterLsadFsm
  *rtu_sLastMasterLsadFsm, tVehCommon *rty_sVehCommon);

/* Model reference registration function */
extern void veh_common_initialize(void);

#ifndef veh_common_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern DW_veh_common_f_T veh_common_DW;

#endif                                 /*veh_common_MDLREF_HIDE_CHILD_*/

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S30>/AND4' : Unused code path elimination
 * Block '<S30>/Constant4' : Unused code path elimination
 * Block '<S30>/Constant5' : Unused code path elimination
 * Block '<S61>/Constant' : Unused code path elimination
 * Block '<S64>/Constant' : Unused code path elimination
 * Block '<S30>/Equal1' : Unused code path elimination
 * Block '<S30>/Equal2' : Unused code path elimination
 * Block '<S30>/Equal7' : Unused code path elimination
 * Block '<S30>/Equal8' : Unused code path elimination
 * Block '<S30>/Logical Operator3' : Unused code path elimination
 * Block '<S30>/Logical Operator5' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S32>/Data Type Conversion' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'veh_common'
 * '<S1>'   : 'veh_common/CondiDoorSblt'
 * '<S2>'   : 'veh_common/CondiPlatform'
 * '<S3>'   : 'veh_common/CondiVeh'
 * '<S4>'   : 'veh_common/CondiDoorSblt/Enumerated Constant'
 * '<S5>'   : 'veh_common/CondiPlatform/ActvStsNeedRlsBrk'
 * '<S6>'   : 'veh_common/CondiPlatform/ObstAppear'
 * '<S7>'   : 'veh_common/CondiPlatform/PrkCtrlFail'
 * '<S8>'   : 'veh_common/CondiPlatform/Subsystem'
 * '<S9>'   : 'veh_common/CondiPlatform/ActvStsNeedRlsBrk/Enumerated Constant1'
 * '<S10>'  : 'veh_common/CondiPlatform/ActvStsNeedRlsBrk/Enumerated Constant3'
 * '<S11>'  : 'veh_common/CondiPlatform/ActvStsNeedRlsBrk/Enumerated Constant9'
 * '<S12>'  : 'veh_common/CondiPlatform/ActvStsNeedRlsBrk/Latch_Reset'
 * '<S13>'  : 'veh_common/CondiPlatform/ObstAppear/Enumerated Constant1'
 * '<S14>'  : 'veh_common/CondiPlatform/ObstAppear/Enumerated Constant3'
 * '<S15>'  : 'veh_common/CondiPlatform/ObstAppear/Enumerated Constant9'
 * '<S16>'  : 'veh_common/CondiPlatform/ObstAppear/Increment_Counter'
 * '<S17>'  : 'veh_common/CondiPlatform/ObstAppear/Latch_Reset'
 * '<S18>'  : 'veh_common/CondiPlatform/ObstAppear/Latch_Reset10'
 * '<S19>'  : 'veh_common/CondiPlatform/ObstAppear/Timer1'
 * '<S20>'  : 'veh_common/CondiPlatform/ObstAppear/Increment_Counter/Subsystem'
 * '<S21>'  : 'veh_common/CondiPlatform/PrkCtrlFail/Enumerated Constant3'
 * '<S22>'  : 'veh_common/CondiVeh/ExterActualNorm'
 * '<S23>'  : 'veh_common/CondiVeh/MoveConflict'
 * '<S24>'  : 'veh_common/CondiVeh/MoveSame'
 * '<S25>'  : 'veh_common/CondiVeh/Subsystem'
 * '<S26>'  : 'veh_common/CondiVeh/Subsystem1'
 * '<S27>'  : 'veh_common/CondiVeh/Subsystem2'
 * '<S28>'  : 'veh_common/CondiVeh/Subsystem3'
 * '<S29>'  : 'veh_common/CondiVeh/VehSlip'
 * '<S30>'  : 'veh_common/CondiVeh/bEPB'
 * '<S31>'  : 'veh_common/CondiVeh/bPrkInOverSlope'
 * '<S32>'  : 'veh_common/CondiVeh/bVehStill'
 * '<S33>'  : 'veh_common/CondiVeh/MoveConflict/Enumerated Constant'
 * '<S34>'  : 'veh_common/CondiVeh/MoveConflict/Enumerated Constant10'
 * '<S35>'  : 'veh_common/CondiVeh/MoveConflict/Enumerated Constant11'
 * '<S36>'  : 'veh_common/CondiVeh/MoveConflict/Enumerated Constant12'
 * '<S37>'  : 'veh_common/CondiVeh/MoveConflict/Enumerated Constant2'
 * '<S38>'  : 'veh_common/CondiVeh/MoveConflict/Enumerated Constant3'
 * '<S39>'  : 'veh_common/CondiVeh/MoveConflict/Enumerated Constant6'
 * '<S40>'  : 'veh_common/CondiVeh/MoveConflict/Enumerated Constant9'
 * '<S41>'  : 'veh_common/CondiVeh/MoveConflict/Timer'
 * '<S42>'  : 'veh_common/CondiVeh/MoveSame/Enumerated Constant1'
 * '<S43>'  : 'veh_common/CondiVeh/MoveSame/Enumerated Constant4'
 * '<S44>'  : 'veh_common/CondiVeh/MoveSame/Enumerated Constant5'
 * '<S45>'  : 'veh_common/CondiVeh/MoveSame/Enumerated Constant6'
 * '<S46>'  : 'veh_common/CondiVeh/MoveSame/Enumerated Constant7'
 * '<S47>'  : 'veh_common/CondiVeh/MoveSame/Enumerated Constant8'
 * '<S48>'  : 'veh_common/CondiVeh/MoveSame/Timer'
 * '<S49>'  : 'veh_common/CondiVeh/Subsystem/GearConflict'
 * '<S50>'  : 'veh_common/CondiVeh/Subsystem1/DebounceTime'
 * '<S51>'  : 'veh_common/CondiVeh/Subsystem1/Enumerated Constant1'
 * '<S52>'  : 'veh_common/CondiVeh/Subsystem2/Enumerated Constant6'
 * '<S53>'  : 'veh_common/CondiVeh/Subsystem3/Enumerated Constant18'
 * '<S54>'  : 'veh_common/CondiVeh/VehSlip/Enumerated Constant10'
 * '<S55>'  : 'veh_common/CondiVeh/VehSlip/Enumerated Constant11'
 * '<S56>'  : 'veh_common/CondiVeh/VehSlip/Enumerated Constant12'
 * '<S57>'  : 'veh_common/CondiVeh/VehSlip/Enumerated Constant2'
 * '<S58>'  : 'veh_common/CondiVeh/VehSlip/Enumerated Constant3'
 * '<S59>'  : 'veh_common/CondiVeh/VehSlip/Enumerated Constant9'
 * '<S60>'  : 'veh_common/CondiVeh/VehSlip/Timer'
 * '<S61>'  : 'veh_common/CondiVeh/bEPB/Enumerated Constant1'
 * '<S62>'  : 'veh_common/CondiVeh/bEPB/Enumerated Constant2'
 * '<S63>'  : 'veh_common/CondiVeh/bEPB/Enumerated Constant3'
 * '<S64>'  : 'veh_common/CondiVeh/bEPB/Enumerated Constant7'
 * '<S65>'  : 'veh_common/CondiVeh/bEPB/Increment_Counter'
 * '<S66>'  : 'veh_common/CondiVeh/bEPB/Latch_Reset10'
 * '<S67>'  : 'veh_common/CondiVeh/bEPB/Increment_Counter/Subsystem'
 * '<S68>'  : 'veh_common/CondiVeh/bPrkInOverSlope/Enumerated Constant3'
 * '<S69>'  : 'veh_common/CondiVeh/bPrkInOverSlope/Timer1'
 */
#endif                                 /* RTW_HEADER_veh_common_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
