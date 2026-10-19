/*
 * File: hmi_common.h
 *
 * Code generated for Simulink model 'hmi_common'.
 *
 * Model version                  : 1.1008
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Thu Nov 28 16:35:54 2024
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

#ifndef RTW_HEADER_hmi_common_h_
#define RTW_HEADER_hmi_common_h_
#include <math.h>
#include <string.h>
#include "hmi_data_rx_type.h"
#include "common_condition_adapter_type.h"
#include "common_condition_type.h"
#include "lsad_fsm_core_type.h"
#include "Platform_Types.h"
#include "rte.h"
#include "master_lsad_fsm_type.h"
#include "slave_lsad_fsm_type.h"
#include "hmi_interactive_type.h"
#ifndef hmi_common_COMMON_INCLUDES_
#define hmi_common_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* hmi_common_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Includes for objects with custom storage classes. */
#include "project_const_common.h"
#include "calib_lsad_fsm.h"

/* Block signals and states (default storage) for model 'hmi_common' */
#ifndef hmi_common_MDLREF_HIDE_CHILD_

typedef struct
{
  tSlotDisp UnitDelay2_DSTATE[12];     /* '<Root>/Unit Delay2' */
  tObsDisp Delay1_DSTATE[12];          /* '<Root>/Delay1' */
  DragParkingLot UnitDelay4_DSTATE;    /* '<S7>/Unit Delay4' */
  real32_T UnitDelay_DSTATE;           /* '<S23>/Unit Delay' */
  real32_T UnitDelay_DSTATE_p;         /* '<S24>/Unit Delay' */
  real32_T UnitDelay_DSTATE_b;         /* '<S29>/Unit Delay' */
  real32_T UnitDelay_DSTATE_bm;        /* '<S30>/Unit Delay' */
  real32_T m_fX_Coor_PP;               /* '<Root>/SlotGroupDet' */
  real32_T m_fY_Coor_PP;               /* '<Root>/SlotGroupDet' */
  real32_T m_fTheta_PP;                /* '<Root>/SlotGroupDet' */
  real32_T PISlotLengthDelay;          /* '<Root>/PITypeDirDet' */
  real32_T IntVPAGuideLineA;           /* '<Root>/ADCS9PlotFitCalc' */
  real32_T IntVPAGuideLineB;           /* '<Root>/ADCS9PlotFitCalc' */
  real32_T IntVPAGuideLineC;           /* '<Root>/ADCS9PlotFitCalc' */
  real32_T IntVPAGuideLineD;           /* '<Root>/ADCS9PlotFitCalc' */
  real32_T IntVPAGuideLineXMin;        /* '<Root>/ADCS9PlotFitCalc' */
  real32_T IntVPAGuideLineXMax;        /* '<Root>/ADCS9PlotFitCalc' */
  tPrkSlotIDReq UnitDelay2_DSTATE_b;   /* '<S11>/Unit Delay2' */
  tPrkSlotIDReq UnitDelay1_DSTATE;     /* '<S11>/Unit Delay1' */
  tPrkSlotIDReq UnitDelay2_DSTATE_m;   /* '<S22>/Unit Delay2' */
  tPrkSlotIDReq UnitDelay1_DSTATE_h;   /* '<S22>/Unit Delay1' */
  tSlotAvaliab UnitDelay1_DSTATE_i;    /* '<Root>/Unit Delay1' */
  tPISlotType UnitDelay4_DSTATE_d;     /* '<Root>/Unit Delay4' */
  tPIDir UnitDelay5_DSTATE;            /* '<Root>/Unit Delay5' */
  struct
  {
    uint_T UnitDelay3_DSTATE:1;        /* '<S11>/Unit Delay3' */
    uint_T UnitDelay2_DSTATE_d:1;      /* '<S28>/Unit Delay2' */
    uint_T UnitDelay3_DSTATE_l:1;      /* '<S22>/Unit Delay3' */
    uint_T UnitDelay2_DSTATE_f:1;      /* '<S34>/Unit Delay2' */
    uint_T Delay_DSTATE:1;             /* '<S12>/Delay' */
    uint_T bIsDeterm:1;                /* '<Root>/PITypeDirDet' */
  }
  bitsForTID0;

  tLSAD_SystemSts UnitDelay_DSTATE_pa; /* '<Root>/Unit Delay' */
  uint16_T u16CurPathCnt;              /* '<Root>/ADCS9PlotFitCalc' */
  uint8_T UnitDelay1_DSTATE_hu;        /* '<S8>/Unit Delay1' */
  uint8_T UnitDelay4_DSTATE_l;         /* '<S8>/Unit Delay4' */
}
DW_hmi_common_f_T;

#endif                                 /*hmi_common_MDLREF_HIDE_CHILD_*/

extern void hmi_common_Init(void);
extern void hmi_common(const tPaStateCommon *rtu_sPaStateCommon, const
  tRelatedModuleInfo *rtu_sRelatedModuleInfo, const tPAHmiRx *rtu_sPAHmiRx,
  const tPecpPLDInfo *rtu_tPecpPLDInfo, const tVehCommon *rtu_sVehCommon, const
  tMsgMnger_PathSegment *rtu_sPathSegment, const tPaStateAdptr
  *rtu_sPaStateAdptr, const tMasterLsadFsm *rtu_sMasterLsadFsm, const
  tSlaveLsadFsm *rtu_sSlaveLsadFsm, tHMIComDisp *rty_sHMIComDisp, DragParkingLot
  *rty_sDragParkingLot, tFusionDisp *rty_sFusionDisp);

/* Model reference registration function */
extern void hmi_common_initialize(void);

#ifndef hmi_common_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern DW_hmi_common_f_T hmi_common_DW;

#endif                                 /*hmi_common_MDLREF_HIDE_CHILD_*/

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Data Type Conversion1' : Unused code path elimination
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
 * '<Root>' : 'hmi_common'
 * '<S1>'   : 'hmi_common/ADCS9PlotFitCalc'
 * '<S2>'   : 'hmi_common/DriverRequestDet'
 * '<S3>'   : 'hmi_common/ObsFusionDispDet'
 * '<S4>'   : 'hmi_common/PITypeDirDet'
 * '<S5>'   : 'hmi_common/SlotGroupDet'
 * '<S6>'   : 'hmi_common/eSlotAvaliabDet'
 * '<S7>'   : 'hmi_common/sSelfParkSlotDet'
 * '<S8>'   : 'hmi_common/u8DrvrSelSlotID'
 * '<S9>'   : 'hmi_common/sSelfParkSlotDet/SelfParkSlotDet'
 * '<S10>'  : 'hmi_common/u8DrvrSelSlotID/DrvrSelSlotIDDet'
 * '<S11>'  : 'hmi_common/u8DrvrSelSlotID/DrvrSelSlotIDEnb'
 * '<S12>'  : 'hmi_common/u8DrvrSelSlotID/EdgeRising1'
 * '<S13>'  : 'hmi_common/u8DrvrSelSlotID/Enumerated Constant1'
 * '<S14>'  : 'hmi_common/u8DrvrSelSlotID/Enumerated Constant2'
 * '<S15>'  : 'hmi_common/u8DrvrSelSlotID/Enumerated Constant3'
 * '<S16>'  : 'hmi_common/u8DrvrSelSlotID/Enumerated Constant4'
 * '<S17>'  : 'hmi_common/u8DrvrSelSlotID/Enumerated Constant5'
 * '<S18>'  : 'hmi_common/u8DrvrSelSlotID/Enumerated Constant6'
 * '<S19>'  : 'hmi_common/u8DrvrSelSlotID/Enumerated Constant7'
 * '<S20>'  : 'hmi_common/u8DrvrSelSlotID/Enumerated Constant8'
 * '<S21>'  : 'hmi_common/u8DrvrSelSlotID/Enumerated Constant9'
 * '<S22>'  : 'hmi_common/u8DrvrSelSlotID/RPADrvrSelSlotIDEnb'
 * '<S23>'  : 'hmi_common/u8DrvrSelSlotID/DrvrSelSlotIDEnb/DebounceTime'
 * '<S24>'  : 'hmi_common/u8DrvrSelSlotID/DrvrSelSlotIDEnb/DebounceTime3'
 * '<S25>'  : 'hmi_common/u8DrvrSelSlotID/DrvrSelSlotIDEnb/Enumerated Constant3'
 * '<S26>'  : 'hmi_common/u8DrvrSelSlotID/DrvrSelSlotIDEnb/Enumerated Constant4'
 * '<S27>'  : 'hmi_common/u8DrvrSelSlotID/DrvrSelSlotIDEnb/Enumerated Constant5'
 * '<S28>'  : 'hmi_common/u8DrvrSelSlotID/DrvrSelSlotIDEnb/Latch_Reset7'
 * '<S29>'  : 'hmi_common/u8DrvrSelSlotID/RPADrvrSelSlotIDEnb/DebounceTime'
 * '<S30>'  : 'hmi_common/u8DrvrSelSlotID/RPADrvrSelSlotIDEnb/DebounceTime3'
 * '<S31>'  : 'hmi_common/u8DrvrSelSlotID/RPADrvrSelSlotIDEnb/Enumerated Constant3'
 * '<S32>'  : 'hmi_common/u8DrvrSelSlotID/RPADrvrSelSlotIDEnb/Enumerated Constant4'
 * '<S33>'  : 'hmi_common/u8DrvrSelSlotID/RPADrvrSelSlotIDEnb/Enumerated Constant5'
 * '<S34>'  : 'hmi_common/u8DrvrSelSlotID/RPADrvrSelSlotIDEnb/Latch_Reset7'
 */
#endif                                 /* RTW_HEADER_hmi_common_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
