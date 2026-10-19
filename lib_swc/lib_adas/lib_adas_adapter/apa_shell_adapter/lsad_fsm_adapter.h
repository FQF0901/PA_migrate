/*
 * File: lsad_fsm_adapter.h
 *
 * Code generated for Simulink model 'lsad_fsm_adapter'.
 *
 * Model version                  : 1.135
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Wed Dec  4 15:22:59 2024
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

#ifndef RTW_HEADER_lsad_fsm_adapter_h_
#define RTW_HEADER_lsad_fsm_adapter_h_
#include <string.h>
#include "rte.h"
#include "lsad_fsm_core_type.h"
#include "Platform_Types.h"
#include "vehicle_service_type.h"
#include "common_condition_type.h"
#include "master_lsad_fsm_type.h"
#include "hmi_interactive_type.h"
#include "hmi_data_rx_type.h"
#include "slave_lsad_fsm_type.h"
#ifndef lsad_fsm_adapter_COMMON_INCLUDES_
#define lsad_fsm_adapter_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* lsad_fsm_adapter_COMMON_INCLUDES_ */

/* Shared type includes */
#include "multiword_types.h"

/* Child system includes */
#define hmi_data_rx_MDLREF_HIDE_CHILD_
#include "hmi_data_rx.h"
#define common_condition_adapter_MDLREF_HIDE_CHILD_
#include "common_condition_adapter.h"
#define slave_lsad_fsm_MDLREF_HIDE_CHILD_
#include "slave_lsad_fsm.h"
#define hmi_interactive_MDLREF_HIDE_CHILD_
#include "hmi_interactive.h"

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
  tPecpPLDInfo sPecpPLDInfo;           /* '<Root>/Signal Copy18' */
  tPAHmiRx sPAHmiRx;                   /* '<Root>/hmi_data_rx' */
  tPaStateAdptr sPaStateAdptr;         /* '<Root>/common_condition_adapter' */
  tRelatedModuleInfo sRelatedModuleInfo;/* '<Root>/Signal Copy3' */
  tSlaveLsadFsm sSlaveLsadFsm;         /* '<Root>/slave_lsad_fsm' */
  tSlaveLsadFsm UnitDelay7_DSTATE;     /* '<Root>/Unit Delay7' */
  tSlaveLsadFsm UnitDelay_DSTATE;      /* '<Root>/Unit Delay' */
  tMasterLsadFsm sLsadFsmCore;         /* '<Root>/Signal Copy10' */
}
DW_lsad_fsm_adapter_T;

/* Block signals and states (default storage) */
extern DW_lsad_fsm_adapter_T lsad_fsm_adapter_DW;

/* External data declarations for dependent source files */
extern const tRelatedModuleInfo lsad_fsm_adapter_rtZtRelatedModuleInfo;/* tRelatedModuleInfo ground */
extern const tPecpPLDInfo lsad_fsm_adapter_rtZtPecpPLDInfo;/* tPecpPLDInfo ground */

/* Model entry point functions */
extern void lsad_fsm_adapter_initialize(void);
extern void lsad_fsm_adapter_step(void);
extern void lsad_fsm_adapter_terminate(void);

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
 * '<Root>' : 'lsad_fsm_adapter'
 */
#endif                                 /* RTW_HEADER_lsad_fsm_adapter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
