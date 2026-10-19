/*
 * File: lsad_fsm_core.h
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

#ifndef RTW_HEADER_lsad_fsm_core_h_
#define RTW_HEADER_lsad_fsm_core_h_
#include <string.h>
#include "lsad_fsm_core_type.h"
#include "slave_lsad_fsm_type.h"
#include "hmi_data_rx_type.h"
#include "master_lsad_fsm_type.h"
#include "common_condition_type.h"
#ifndef lsad_fsm_core_COMMON_INCLUDES_
#define lsad_fsm_core_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* lsad_fsm_core_COMMON_INCLUDES_ */

/* Child system includes */
#define common_condition_MDLREF_HIDE_CHILD_
#include "common_condition.h"
#define master_lsad_fsm_MDLREF_HIDE_CHILD_
#include "master_lsad_fsm.h"

/* Model Code Variants */

/* Includes for objects with custom storage classes. */
#include "project_const_common.h"
#include "wrapper_api.h"
#include "lsad_fsm_adapter_api.h"
#include "lsad_fsm_api.h"
#include "calib_lsad_fsm.h"

/* Macros for accessing real-time model data structure */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct
{
  tMasterLsadFsm UnitDelay5_DSTATE;    /* '<Root>/Unit Delay5' */
  tMasterLsadFsm UnitDelay1_DSTATE;    /* '<Root>/Unit Delay1' */
}
DW_lsad_fsm_core_T;

/* Block signals and states (default storage) */
extern DW_lsad_fsm_core_T lsad_fsm_core_DW;

/* Model entry point functions */
extern void lsad_fsm_core_initialize(void);
extern void lsad_fsm_core_step(void);
extern void lsad_fsm_core_terminate(void);

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
 * '<Root>' : 'lsad_fsm_core'
 */
#endif                                 /* RTW_HEADER_lsad_fsm_core_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
