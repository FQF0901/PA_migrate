/*
 * File: hozon_hmi_output.h
 *
 * Code generated for Simulink model 'hozon_hmi_output'.
 *
 * Model version                  : 1.1636
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Thu Nov 28 16:36:54 2024
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

#ifndef RTW_HEADER_hozon_hmi_output_h_
#define RTW_HEADER_hozon_hmi_output_h_
#include <math.h>
#include <string.h>
#include "slave_lsad_fsm_type.h"
#include "hmi_interactive_type.h"
#include "hmi_data_rx_type.h"
#include "common_condition_type.h"
#include "lsad_fsm_core_type.h"
#include "vehicle_service_type.h"
#include "rte.h"
#include "master_lsad_fsm_type.h"
#include "hmi_output_type.h"
#ifndef hozon_hmi_output_COMMON_INCLUDES_
#define hozon_hmi_output_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* hozon_hmi_output_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Includes for objects with custom storage classes. */
#include "project_const_common.h"
#include "calib_lsad_fsm.h"

/* Block signals and states (default storage) for model 'hozon_hmi_output' */
#ifndef hozon_hmi_output_MDLREF_HIDE_CHILD_

typedef struct
{
  real_T UnitDelay1_DSTATE;            /* '<S23>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_n;        /* '<S55>/Unit Delay1' */
  real32_T UnitDelay_DSTATE;           /* '<S6>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_l;        /* '<S59>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_d;        /* '<S102>/Unit Delay1' */
  struct
  {
    uint_T UnitDelay3_DSTATE:1;        /* '<S4>/Unit Delay3' */
    uint_T UnitDelay2_DSTATE_p:1;      /* '<S54>/Unit Delay2' */
  }
  bitsForTID0;

  tLSAD_SystemSts UnitDelay2_DSTATE;   /* '<S4>/Unit Delay2' */
  uint16_T A;                          /* '<S89>/Data Store Memory' */
  uint8_T UnitDelay1_DSTATE_nu;        /* '<S4>/Unit Delay1' */
  uint8_T UnitDelay_DSTATE_k;          /* '<S9>/Unit Delay' */
  uint8_T UnitDelay_DSTATE_b;          /* '<S23>/Unit Delay' */
  uint8_T UnitDelay_DSTATE_g;          /* '<S21>/Unit Delay' */
}
DW_hozon_hmi_output_f_T;

#endif                                 /*hozon_hmi_output_MDLREF_HIDE_CHILD_*/

extern void hozon_hmi_output_Init(void);
extern void hozon_hmi_output(const tHMIComDisp *rtu_sHMIComDisp, const
  tFusionDisp *rtu_sFusionDisp, const tPAHmiRx *rtu_sPAHmiRx, const
  tPaStateCommon *rtu_sPaStateCommon, const tDiagInfo *rtu_sDiagInfo, const
  tVehCommon *rtu_sVehCommon, const tRaStateCommon *rtu_sRaStateCommon, const
  tVehDataRx *rtu_sVehDataRx, const tRAHmiRx *rtu_sRAHmiRx, const
  tRelatedModuleInfo *rtu_sRelatedModuleInfo, const tMsgMnger_PathSegment
  *rtu_sPathSegment, const tMasterLsadFsm *rtu_sMasterLsadFsm, const
  tSlaveLsadFsm *rtu_sSlaveLsadFsm, const tPaStateAdptr *rtu_sPaStateAdptr,
  tPADispTx *rty_sPADispTx, tPrkInSlotTx *rty_sPrkInSlotTx);

/* Model reference registration function */
extern void hozon_hmi_output_initialize(void);

#ifndef hozon_hmi_output_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern DW_hozon_hmi_output_f_T hozon_hmi_output_DW;

#endif                                 /*hozon_hmi_output_MDLREF_HIDE_CHILD_*/

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion11' : Eliminate redundant data type conversion
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
 * '<Root>' : 'hozon_hmi_output'
 * '<S1>'   : 'hozon_hmi_output/ADCS11_Currentgear'
 * '<S2>'   : 'hozon_hmi_output/ADCS11_NNS_distance'
 * '<S3>'   : 'hozon_hmi_output/ADCS4 _TractionswithReq'
 * '<S4>'   : 'hozon_hmi_output/ADCS4_AVM_vedioReq'
 * '<S5>'   : 'hozon_hmi_output/ADCS4_PA_ParkBarPercent'
 * '<S6>'   : 'hozon_hmi_output/ADCS4_ParkingTimeDet'
 * '<S7>'   : 'hozon_hmi_output/ADCS4_ParkingswithReq'
 * '<S8>'   : 'hozon_hmi_output/ADCS4_Slotavaliable'
 * '<S9>'   : 'hozon_hmi_output/ADCS4_Text'
 * '<S10>'  : 'hozon_hmi_output/ADCS6PAwarninginfoDet'
 * '<S11>'  : 'hozon_hmi_output/ADCS8_TBA_text'
 * '<S12>'  : 'hozon_hmi_output/APAFunctionModeDet'
 * '<S13>'  : 'hozon_hmi_output/Enumerated Constant'
 * '<S14>'  : 'hozon_hmi_output/Enumerated Constant1'
 * '<S15>'  : 'hozon_hmi_output/Enumerated Constant2'
 * '<S16>'  : 'hozon_hmi_output/Enumerated Constant3'
 * '<S17>'  : 'hozon_hmi_output/Enumerated Constant4'
 * '<S18>'  : 'hozon_hmi_output/Enumerated Constant5'
 * '<S19>'  : 'hozon_hmi_output/Enumerated Constant6'
 * '<S20>'  : 'hozon_hmi_output/Enumerated Constant7'
 * '<S21>'  : 'hozon_hmi_output/PA_WorkSts'
 * '<S22>'  : 'hozon_hmi_output/POObstAppear'
 * '<S23>'  : 'hozon_hmi_output/ParkWorkSts'
 * '<S24>'  : 'hozon_hmi_output/RPAFunctionModeDet'
 * '<S25>'  : 'hozon_hmi_output/Subsystem'
 * '<S26>'  : 'hozon_hmi_output/TBA_Distance'
 * '<S27>'  : 'hozon_hmi_output/bParkBarPercentaDelay'
 * '<S28>'  : 'hozon_hmi_output/sHozonPrkInSlotTxDet'
 * '<S29>'  : 'hozon_hmi_output/ADCS11_Currentgear/Enumerated Constant'
 * '<S30>'  : 'hozon_hmi_output/ADCS11_Currentgear/Enumerated Constant1'
 * '<S31>'  : 'hozon_hmi_output/ADCS11_Currentgear/ifthen_elseif'
 * '<S32>'  : 'hozon_hmi_output/ADCS4 _TractionswithReq/Enumerated Constant'
 * '<S33>'  : 'hozon_hmi_output/ADCS4 _TractionswithReq/Enumerated Constant1'
 * '<S34>'  : 'hozon_hmi_output/ADCS4 _TractionswithReq/Enumerated Constant10'
 * '<S35>'  : 'hozon_hmi_output/ADCS4 _TractionswithReq/Enumerated Constant11'
 * '<S36>'  : 'hozon_hmi_output/ADCS4 _TractionswithReq/Enumerated Constant12'
 * '<S37>'  : 'hozon_hmi_output/ADCS4 _TractionswithReq/Enumerated Constant13'
 * '<S38>'  : 'hozon_hmi_output/ADCS4 _TractionswithReq/Enumerated Constant14'
 * '<S39>'  : 'hozon_hmi_output/ADCS4 _TractionswithReq/Enumerated Constant15'
 * '<S40>'  : 'hozon_hmi_output/ADCS4 _TractionswithReq/Enumerated Constant16'
 * '<S41>'  : 'hozon_hmi_output/ADCS4 _TractionswithReq/Enumerated Constant17'
 * '<S42>'  : 'hozon_hmi_output/ADCS4 _TractionswithReq/Enumerated Constant7'
 * '<S43>'  : 'hozon_hmi_output/ADCS4 _TractionswithReq/Enumerated Constant8'
 * '<S44>'  : 'hozon_hmi_output/ADCS4 _TractionswithReq/Enumerated Constant9'
 * '<S45>'  : 'hozon_hmi_output/ADCS4_AVM_vedioReq/Enumerated Constant1'
 * '<S46>'  : 'hozon_hmi_output/ADCS4_AVM_vedioReq/Enumerated Constant2'
 * '<S47>'  : 'hozon_hmi_output/ADCS4_AVM_vedioReq/Enumerated Constant3'
 * '<S48>'  : 'hozon_hmi_output/ADCS4_AVM_vedioReq/Enumerated Constant4'
 * '<S49>'  : 'hozon_hmi_output/ADCS4_AVM_vedioReq/Enumerated Constant5'
 * '<S50>'  : 'hozon_hmi_output/ADCS4_AVM_vedioReq/Enumerated Constant6'
 * '<S51>'  : 'hozon_hmi_output/ADCS4_AVM_vedioReq/Enumerated Constant7'
 * '<S52>'  : 'hozon_hmi_output/ADCS4_AVM_vedioReq/Enumerated Constant8'
 * '<S53>'  : 'hozon_hmi_output/ADCS4_AVM_vedioReq/Enumerated Constant9'
 * '<S54>'  : 'hozon_hmi_output/ADCS4_AVM_vedioReq/Latch_Reset7'
 * '<S55>'  : 'hozon_hmi_output/ADCS4_AVM_vedioReq/Timer8'
 * '<S56>'  : 'hozon_hmi_output/ADCS4_ParkingTimeDet/Enumerated Constant1'
 * '<S57>'  : 'hozon_hmi_output/ADCS4_ParkingTimeDet/Enumerated Constant2'
 * '<S58>'  : 'hozon_hmi_output/ADCS4_ParkingTimeDet/Enumerated Constant3'
 * '<S59>'  : 'hozon_hmi_output/ADCS4_ParkingTimeDet/Timer7'
 * '<S60>'  : 'hozon_hmi_output/ADCS4_ParkingswithReq/Enumerated Constant1'
 * '<S61>'  : 'hozon_hmi_output/ADCS4_ParkingswithReq/Enumerated Constant10'
 * '<S62>'  : 'hozon_hmi_output/ADCS4_ParkingswithReq/Enumerated Constant11'
 * '<S63>'  : 'hozon_hmi_output/ADCS4_ParkingswithReq/Enumerated Constant12'
 * '<S64>'  : 'hozon_hmi_output/ADCS4_ParkingswithReq/Enumerated Constant13'
 * '<S65>'  : 'hozon_hmi_output/ADCS4_ParkingswithReq/Enumerated Constant2'
 * '<S66>'  : 'hozon_hmi_output/ADCS4_ParkingswithReq/Enumerated Constant3'
 * '<S67>'  : 'hozon_hmi_output/ADCS4_ParkingswithReq/Enumerated Constant4'
 * '<S68>'  : 'hozon_hmi_output/ADCS4_ParkingswithReq/Enumerated Constant5'
 * '<S69>'  : 'hozon_hmi_output/ADCS4_ParkingswithReq/Enumerated Constant6'
 * '<S70>'  : 'hozon_hmi_output/ADCS4_ParkingswithReq/Enumerated Constant7'
 * '<S71>'  : 'hozon_hmi_output/ADCS4_ParkingswithReq/Enumerated Constant8'
 * '<S72>'  : 'hozon_hmi_output/ADCS4_ParkingswithReq/Enumerated Constant9'
 * '<S73>'  : 'hozon_hmi_output/ADCS4_Slotavaliable/Enumerated Constant1'
 * '<S74>'  : 'hozon_hmi_output/ADCS4_Slotavaliable/Enumerated Constant2'
 * '<S75>'  : 'hozon_hmi_output/ADCS4_Text/ADCS4TextDet'
 * '<S76>'  : 'hozon_hmi_output/ADCS4_Text/ifthenelse'
 * '<S77>'  : 'hozon_hmi_output/APAFunctionModeDet/Enumerated Constant'
 * '<S78>'  : 'hozon_hmi_output/APAFunctionModeDet/Enumerated Constant1'
 * '<S79>'  : 'hozon_hmi_output/APAFunctionModeDet/Enumerated Constant3'
 * '<S80>'  : 'hozon_hmi_output/APAFunctionModeDet/Enumerated Constant4'
 * '<S81>'  : 'hozon_hmi_output/PA_WorkSts/Enumerated Constant'
 * '<S82>'  : 'hozon_hmi_output/PA_WorkSts/Enumerated Constant1'
 * '<S83>'  : 'hozon_hmi_output/PA_WorkSts/IfPA_WorkSts_APA'
 * '<S84>'  : 'hozon_hmi_output/PA_WorkSts/IfRA_WorkSts_RA'
 * '<S85>'  : 'hozon_hmi_output/PA_WorkSts/IfPA_WorkSts_APA/PAADCS11ParkWorkSts'
 * '<S86>'  : 'hozon_hmi_output/PA_WorkSts/IfRA_WorkSts_RA/RAADCS11ParkingWorkSts'
 * '<S87>'  : 'hozon_hmi_output/POObstAppear/Enumerated Constant1'
 * '<S88>'  : 'hozon_hmi_output/POObstAppear/Enumerated Constant5'
 * '<S89>'  : 'hozon_hmi_output/POObstAppear/Increment_Counter'
 * '<S90>'  : 'hozon_hmi_output/POObstAppear/Increment_Counter/Subsystem'
 * '<S91>'  : 'hozon_hmi_output/ParkWorkSts/ParkingWorkStsLatch'
 * '<S92>'  : 'hozon_hmi_output/RPAFunctionModeDet/Enumerated Constant1'
 * '<S93>'  : 'hozon_hmi_output/RPAFunctionModeDet/Enumerated Constant2'
 * '<S94>'  : 'hozon_hmi_output/RPAFunctionModeDet/Enumerated Constant3'
 * '<S95>'  : 'hozon_hmi_output/RPAFunctionModeDet/Enumerated Constant4'
 * '<S96>'  : 'hozon_hmi_output/RPAFunctionModeDet/Enumerated Constant5'
 * '<S97>'  : 'hozon_hmi_output/Subsystem/ADCS4PAfailinfoDet'
 * '<S98>'  : 'hozon_hmi_output/Subsystem/ifthenelse1'
 * '<S99>'  : 'hozon_hmi_output/TBA_Distance/Enumerated Constant'
 * '<S100>' : 'hozon_hmi_output/TBA_Distance/ifthenelse1'
 * '<S101>' : 'hozon_hmi_output/bParkBarPercentaDelay/Enumerated Constant2'
 * '<S102>' : 'hozon_hmi_output/bParkBarPercentaDelay/Timer2'
 * '<S103>' : 'hozon_hmi_output/sHozonPrkInSlotTxDet/PrkInSlotDet'
 */
#endif                                 /* RTW_HEADER_hozon_hmi_output_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
