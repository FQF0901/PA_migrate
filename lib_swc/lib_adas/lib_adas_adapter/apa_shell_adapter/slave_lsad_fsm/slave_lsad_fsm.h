/*
 * File: slave_lsad_fsm.h
 *
 * Code generated for Simulink model 'slave_lsad_fsm'.
 *
 * Model version                  : 3.2732
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Tue Feb 25 10:15:32 2025
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

#ifndef RTW_HEADER_slave_lsad_fsm_h_
#define RTW_HEADER_slave_lsad_fsm_h_
#include <math.h>
#include <string.h>
#include "hmi_data_rx_type.h"
#include "common_condition_type.h"
#include "slave_lsad_fsm_type.h"
#include "lsad_fsm_core_type.h"
#include "master_lsad_fsm_type.h"
#ifndef slave_lsad_fsm_COMMON_INCLUDES_
#define slave_lsad_fsm_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* slave_lsad_fsm_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Includes for objects with custom storage classes. */
#include "project_const_common.h"
#include "calib_lsad_fsm.h"

/* Block signals and states (default storage) for model 'slave_lsad_fsm' */
#ifndef slave_lsad_fsm_MDLREF_HIDE_CHILD_

typedef struct
{
  real32_T UnitDelay1_DSTATE;          /* '<S125>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_p;        /* '<S95>/Unit Delay1' */
  tLSAD_FuncSts Delay1_DSTATE[3];      /* '<Root>/Delay1' */
  tLSAD_FuncSts eLsadFuncSts;          /* '<Root>/slave_lsad_fsm_stateflow' */
  tAPAMod UnitDelay1_DSTATE_e;         /* '<S8>/Unit Delay1' */
  tAPAMod UnitDelay2_DSTATE;           /* '<S8>/Unit Delay2' */
  tAPAMod UnitDelay3_DSTATE;           /* '<S8>/Unit Delay3' */
  tBckgrndModuleSts eBckgrndRecordSts; /* '<Root>/slave_lsad_fsm_stateflow' */
  tBckgrndModuleSts eBckgrndCruiseReadySts;/* '<Root>/slave_lsad_fsm_stateflow' */
  tBckgrndModuleSts eBckgrndSearchSts; /* '<Root>/slave_lsad_fsm_stateflow' */
  tLSAD_FuncType Delay_DSTATE[3];      /* '<Root>/Delay' */
  tLSAD_FuncType eLsadFuncType;        /* '<Root>/slave_lsad_fsm_stateflow' */
  tIntrptEvnt UnitDelay_DSTATE;        /* '<S29>/Unit Delay' */
  tIntrptEvnt UnitDelay3_DSTATE_p;     /* '<S29>/Unit Delay3' */
  tRAIntrptEvnt UnitDelay4_DSTATE;     /* '<S29>/Unit Delay4' */
  struct
  {
    uint_T is_c6_slave_lsad_fsm:3;     /* '<Root>/slave_lsad_fsm_stateflow' */
    uint_T is_FuncSelect:3;            /* '<Root>/slave_lsad_fsm_stateflow' */
    uint_T is_BackgroundRecord:2;      /* '<Root>/slave_lsad_fsm_stateflow' */
    uint_T is_BackgroundCruiseReady:2; /* '<Root>/slave_lsad_fsm_stateflow' */
    uint_T is_BackgroundSearch:2;      /* '<Root>/slave_lsad_fsm_stateflow' */
    uint_T is_APAPrkCnfm:2;            /* '<Root>/slave_lsad_fsm_stateflow' */
    uint_T is_APAPrkIn:2;              /* '<Root>/slave_lsad_fsm_stateflow' */
    uint_T is_APAPrkOut:2;             /* '<Root>/slave_lsad_fsm_stateflow' */
    uint_T is_RPAPrkCnfm:2;            /* '<Root>/slave_lsad_fsm_stateflow' */
    uint_T is_RPAPrkIn:2;              /* '<Root>/slave_lsad_fsm_stateflow' */
    uint_T is_active_c6_slave_lsad_fsm:1;/* '<Root>/slave_lsad_fsm_stateflow' */
    uint_T bAPAPrkModChng:1;           /* '<S8>/Logical Operator3' */
    uint_T bAPAPrkOut:1;               /* '<S9>/Logical Operator' */
    uint_T bAPASuppres:1;              /* '<S10>/Equal' */
    uint_T bRPAStraight2Hand:1;        /* '<S24>/Logical Operator1' */
    uint_T bRAReady2Hand:1;            /* '<S23>/Logical Operator' */
    uint_T bFuncSelect2Quit:1;         /* '<S21>/AND' */
    uint_T bCruisingReady2Hand:1;      /* '<S17>/Logical Operator' */
    uint_T bAPAPISrch:1;               /* '<S7>/APAPrkInSrchDet ' */
    uint_T UnitDelay2_DSTATE_j:1;      /* '<S48>/Unit Delay2' */
    uint_T UnitDelay2_DSTATE_f:1;      /* '<S29>/Unit Delay2' */
  }
  bitsForTID0;

  uint8_T UnitDelay1_DSTATE_g;         /* '<S29>/Unit Delay1' */
  boolean_T Delay_DSTATE_g[3];         /* '<S23>/Delay' */
  boolean_T Delay_DSTATE_j[3];         /* '<S17>/Delay' */
  boolean_T Delay_DSTATE_f[3];         /* '<S13>/Delay' */
}
DW_slave_lsad_fsm_f_T;

#endif                                 /*slave_lsad_fsm_MDLREF_HIDE_CHILD_*/

extern void slave_lsad_fsm_Init(void);
extern void slave_lsad_fsm(const tPAHmiRx *rtu_sPAHmiRx, const tPaStateCommon
  *rtu_sPaStateCommon, const tVehCommon *rtu_sVehCommon, const tVehDataRx
  *rtu_sVehDataRx, const tRelatedModuleInfo *rtu_sRelatedModuleInfo, const
  boolean_T *rtu_sHpaStateCommon_sHPACondiOverFlag_bHpaQuitDurattime, const
  tQuitEvnt *rtu_sHpaStateCommon_sHPAEvnt_eHPAQuitEvnt, const tIntrptEvnt
  *rtu_sHpaStateCommon_sHPAEvnt_eHPAIntrptEvnt, const tHPAHmiRx *rtu_sHPAHmiRx,
  const tRAHmiRx *rtu_sRAHmiRx, const boolean_T
  *rtu_sRaStateCommon_sRACondiOverFlag_bRAQuitDurattime, const tRAIntrptEvnt
  *rtu_sRaStateCommon_sRAEvnt_eRAIntrptEvnt, const tRAQuitEvnt
  *rtu_sRaStateCommon_sRAEvnt_eRAQuitEvnt, const tDiagInfo *rtu_sDiagInfo, const
  tMasterLsadFsm *rtu_sLastMasterLsadFsm, const tSlaveLsadFsm
  *rtu_sLastSlaveLsadFsm, const tPaStateAdptr *rtu_sPaStateAdptr, tSlaveLsadFsm *
  rty_sSlaveLsadFsm);

/* Model reference registration function */
extern void slave_lsad_fsm_initialize(void);

#ifndef slave_lsad_fsm_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern DW_slave_lsad_fsm_f_T slave_lsad_fsm_DW;

#endif                                 /*slave_lsad_fsm_MDLREF_HIDE_CHILD_*/

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Constant' : Unused code path elimination
 * Block '<S1>/Constant1' : Unused code path elimination
 * Block '<S32>/Constant' : Unused code path elimination
 * Block '<S1>/Equal' : Unused code path elimination
 * Block '<S1>/Equal2' : Unused code path elimination
 * Block '<S20>/Constant' : Unused code path elimination
 * Block '<S104>/Constant' : Unused code path elimination
 * Block '<S20>/Equal2' : Unused code path elimination
 * Block '<S20>/Equal4' : Unused code path elimination
 * Block '<S19>/Signal Copy' : Eliminate redundant signal conversion block
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
 * '<Root>' : 'slave_lsad_fsm'
 * '<S1>'   : 'slave_lsad_fsm/APA2RPADet'
 * '<S2>'   : 'slave_lsad_fsm/APAModeSelectDet'
 * '<S3>'   : 'slave_lsad_fsm/APAPICnfm2HandDet'
 * '<S4>'   : 'slave_lsad_fsm/APAPOCnfm2HandDet'
 * '<S5>'   : 'slave_lsad_fsm/APAPrkInCnfmDet'
 * '<S6>'   : 'slave_lsad_fsm/APAPrkInDet'
 * '<S7>'   : 'slave_lsad_fsm/APAPrkInSrchDet'
 * '<S8>'   : 'slave_lsad_fsm/APAPrkModChngDet'
 * '<S9>'   : 'slave_lsad_fsm/APAPrkOutDet'
 * '<S10>'  : 'slave_lsad_fsm/APASuppressDet'
 * '<S11>'  : 'slave_lsad_fsm/AfterSelect2Quit'
 * '<S12>'  : 'slave_lsad_fsm/AfterSelect2Standby'
 * '<S13>'  : 'slave_lsad_fsm/BckgrndCruiseReadyDisable2EnableDet'
 * '<S14>'  : 'slave_lsad_fsm/BckgrndCruiseReadyEnable2DisableDet'
 * '<S15>'  : 'slave_lsad_fsm/BckgrndRecordDisable2EnableDet'
 * '<S16>'  : 'slave_lsad_fsm/Cruising2APAPIConfirmDet'
 * '<S17>'  : 'slave_lsad_fsm/CruisingReady2HandDet'
 * '<S18>'  : 'slave_lsad_fsm/DriverCtrlCommandFcn'
 * '<S19>'  : 'slave_lsad_fsm/EolDet'
 * '<S20>'  : 'slave_lsad_fsm/Idle2APADet'
 * '<S21>'  : 'slave_lsad_fsm/Prepare2QuitDet'
 * '<S22>'  : 'slave_lsad_fsm/Quit2StandbyDet'
 * '<S23>'  : 'slave_lsad_fsm/RAReady2HandDet'
 * '<S24>'  : 'slave_lsad_fsm/RPAStraight2HandDet'
 * '<S25>'  : 'slave_lsad_fsm/SeatbltDebugHandshakeFcn'
 * '<S26>'  : 'slave_lsad_fsm/Standby2CruisingReadyDet'
 * '<S27>'  : 'slave_lsad_fsm/Standby2RAReadyDet'
 * '<S28>'  : 'slave_lsad_fsm/Standby2RPADet'
 * '<S29>'  : 'slave_lsad_fsm/Subsystem1'
 * '<S30>'  : 'slave_lsad_fsm/slave_lsad_fsm_stateflow'
 * '<S31>'  : 'slave_lsad_fsm/APA2RPADet/Enumerated Constant1'
 * '<S32>'  : 'slave_lsad_fsm/APA2RPADet/Enumerated Constant14'
 * '<S33>'  : 'slave_lsad_fsm/APA2RPADet/Enumerated Constant2'
 * '<S34>'  : 'slave_lsad_fsm/APA2RPADet/Enumerated Constant3'
 * '<S35>'  : 'slave_lsad_fsm/APA2RPADet/Enumerated Constant4'
 * '<S36>'  : 'slave_lsad_fsm/APA2RPADet/Enumerated Constant5'
 * '<S37>'  : 'slave_lsad_fsm/APA2RPADet/Enumerated Constant6'
 * '<S38>'  : 'slave_lsad_fsm/APAModeSelectDet/Enumerated Constant5'
 * '<S39>'  : 'slave_lsad_fsm/APAModeSelectDet/Enumerated Constant6'
 * '<S40>'  : 'slave_lsad_fsm/APAModeSelectDet/Enumerated Constant7'
 * '<S41>'  : 'slave_lsad_fsm/APAPICnfm2HandDet/Enumerated Constant1'
 * '<S42>'  : 'slave_lsad_fsm/APAPICnfm2HandDet/Enumerated Constant2'
 * '<S43>'  : 'slave_lsad_fsm/APAPICnfm2HandDet/Enumerated Constant3'
 * '<S44>'  : 'slave_lsad_fsm/APAPICnfm2HandDet/Enumerated Constant5'
 * '<S45>'  : 'slave_lsad_fsm/APAPICnfm2HandDet/Enumerated Constant6'
 * '<S46>'  : 'slave_lsad_fsm/APAPICnfm2HandDet/Enumerated Constant7'
 * '<S47>'  : 'slave_lsad_fsm/APAPICnfm2HandDet/Enumerated Constant9'
 * '<S48>'  : 'slave_lsad_fsm/APAPICnfm2HandDet/Latch_Reset'
 * '<S49>'  : 'slave_lsad_fsm/APAPOCnfm2HandDet/Enumerated Constant1'
 * '<S50>'  : 'slave_lsad_fsm/APAPOCnfm2HandDet/Enumerated Constant2'
 * '<S51>'  : 'slave_lsad_fsm/APAPOCnfm2HandDet/Enumerated Constant3'
 * '<S52>'  : 'slave_lsad_fsm/APAPOCnfm2HandDet/Enumerated Constant4'
 * '<S53>'  : 'slave_lsad_fsm/APAPrkInCnfmDet/Enumerated Constant1'
 * '<S54>'  : 'slave_lsad_fsm/APAPrkInCnfmDet/Enumerated Constant2'
 * '<S55>'  : 'slave_lsad_fsm/APAPrkInCnfmDet/Enumerated Constant3'
 * '<S56>'  : 'slave_lsad_fsm/APAPrkInCnfmDet/Enumerated Constant4'
 * '<S57>'  : 'slave_lsad_fsm/APAPrkInDet/Enumerated Constant1'
 * '<S58>'  : 'slave_lsad_fsm/APAPrkInDet/Enumerated Constant2'
 * '<S59>'  : 'slave_lsad_fsm/APAPrkInSrchDet/APAPrkInSrchDet '
 * '<S60>'  : 'slave_lsad_fsm/APAPrkModChngDet/Enumerated Constant1'
 * '<S61>'  : 'slave_lsad_fsm/APAPrkModChngDet/Enumerated Constant2'
 * '<S62>'  : 'slave_lsad_fsm/APAPrkModChngDet/Enumerated Constant4'
 * '<S63>'  : 'slave_lsad_fsm/APAPrkModChngDet/Enumerated Constant5'
 * '<S64>'  : 'slave_lsad_fsm/APAPrkModChngDet/Enumerated Constant6'
 * '<S65>'  : 'slave_lsad_fsm/APAPrkModChngDet/Enumerated Constant7'
 * '<S66>'  : 'slave_lsad_fsm/APAPrkOutDet/Enumerated Constant1'
 * '<S67>'  : 'slave_lsad_fsm/APAPrkOutDet/Enumerated Constant2'
 * '<S68>'  : 'slave_lsad_fsm/APAPrkOutDet/Enumerated Constant3'
 * '<S69>'  : 'slave_lsad_fsm/APAPrkOutDet/Enumerated Constant4'
 * '<S70>'  : 'slave_lsad_fsm/APAPrkOutDet/Enumerated Constant5'
 * '<S71>'  : 'slave_lsad_fsm/APASuppressDet/Enumerated Constant1'
 * '<S72>'  : 'slave_lsad_fsm/AfterSelect2Quit/Enumerated Constant1'
 * '<S73>'  : 'slave_lsad_fsm/AfterSelect2Quit/Enumerated Constant2'
 * '<S74>'  : 'slave_lsad_fsm/AfterSelect2Quit/Enumerated Constant3'
 * '<S75>'  : 'slave_lsad_fsm/AfterSelect2Quit/Enumerated Constant4'
 * '<S76>'  : 'slave_lsad_fsm/AfterSelect2Standby/Enumerated Constant2'
 * '<S77>'  : 'slave_lsad_fsm/AfterSelect2Standby/Enumerated Constant4'
 * '<S78>'  : 'slave_lsad_fsm/BckgrndCruiseReadyDisable2EnableDet/Enumerated Constant1'
 * '<S79>'  : 'slave_lsad_fsm/BckgrndCruiseReadyDisable2EnableDet/Enumerated Constant3'
 * '<S80>'  : 'slave_lsad_fsm/BckgrndCruiseReadyDisable2EnableDet/Enumerated Constant4'
 * '<S81>'  : 'slave_lsad_fsm/BckgrndCruiseReadyEnable2DisableDet/Enumerated Constant1'
 * '<S82>'  : 'slave_lsad_fsm/BckgrndCruiseReadyEnable2DisableDet/Enumerated Constant3'
 * '<S83>'  : 'slave_lsad_fsm/BckgrndRecordDisable2EnableDet/Enumerated Constant1'
 * '<S84>'  : 'slave_lsad_fsm/BckgrndRecordDisable2EnableDet/Enumerated Constant2'
 * '<S85>'  : 'slave_lsad_fsm/BckgrndRecordDisable2EnableDet/Enumerated Constant3'
 * '<S86>'  : 'slave_lsad_fsm/BckgrndRecordDisable2EnableDet/Enumerated Constant4'
 * '<S87>'  : 'slave_lsad_fsm/BckgrndRecordDisable2EnableDet/Enumerated Constant5'
 * '<S88>'  : 'slave_lsad_fsm/BckgrndRecordDisable2EnableDet/RAMoveConflict'
 * '<S89>'  : 'slave_lsad_fsm/BckgrndRecordDisable2EnableDet/RAMoveConflict/Enumerated Constant10'
 * '<S90>'  : 'slave_lsad_fsm/BckgrndRecordDisable2EnableDet/RAMoveConflict/Enumerated Constant11'
 * '<S91>'  : 'slave_lsad_fsm/BckgrndRecordDisable2EnableDet/RAMoveConflict/Enumerated Constant12'
 * '<S92>'  : 'slave_lsad_fsm/BckgrndRecordDisable2EnableDet/RAMoveConflict/Enumerated Constant2'
 * '<S93>'  : 'slave_lsad_fsm/BckgrndRecordDisable2EnableDet/RAMoveConflict/Enumerated Constant3'
 * '<S94>'  : 'slave_lsad_fsm/BckgrndRecordDisable2EnableDet/RAMoveConflict/Enumerated Constant9'
 * '<S95>'  : 'slave_lsad_fsm/BckgrndRecordDisable2EnableDet/RAMoveConflict/Timer'
 * '<S96>'  : 'slave_lsad_fsm/Cruising2APAPIConfirmDet/Enumerated Constant1'
 * '<S97>'  : 'slave_lsad_fsm/Cruising2APAPIConfirmDet/Enumerated Constant2'
 * '<S98>'  : 'slave_lsad_fsm/Cruising2APAPIConfirmDet/Enumerated Constant3'
 * '<S99>'  : 'slave_lsad_fsm/Cruising2APAPIConfirmDet/Enumerated Constant4'
 * '<S100>' : 'slave_lsad_fsm/Cruising2APAPIConfirmDet/Enumerated Constant5'
 * '<S101>' : 'slave_lsad_fsm/CruisingReady2HandDet/Enumerated Constant3'
 * '<S102>' : 'slave_lsad_fsm/Idle2APADet/Enumerated Constant'
 * '<S103>' : 'slave_lsad_fsm/Idle2APADet/Enumerated Constant1'
 * '<S104>' : 'slave_lsad_fsm/Idle2APADet/Enumerated Constant2'
 * '<S105>' : 'slave_lsad_fsm/Idle2APADet/Enumerated Constant3'
 * '<S106>' : 'slave_lsad_fsm/Prepare2QuitDet/Enumerated Constant1'
 * '<S107>' : 'slave_lsad_fsm/Prepare2QuitDet/Enumerated Constant2'
 * '<S108>' : 'slave_lsad_fsm/Prepare2QuitDet/Enumerated Constant3'
 * '<S109>' : 'slave_lsad_fsm/Prepare2QuitDet/Enumerated Constant4'
 * '<S110>' : 'slave_lsad_fsm/Prepare2QuitDet/Enumerated Constant5'
 * '<S111>' : 'slave_lsad_fsm/Quit2StandbyDet/Enumerated Constant1'
 * '<S112>' : 'slave_lsad_fsm/Quit2StandbyDet/Enumerated Constant2'
 * '<S113>' : 'slave_lsad_fsm/Quit2StandbyDet/Enumerated Constant3'
 * '<S114>' : 'slave_lsad_fsm/Quit2StandbyDet/Enumerated Constant4'
 * '<S115>' : 'slave_lsad_fsm/RAReady2HandDet/Enumerated Constant3'
 * '<S116>' : 'slave_lsad_fsm/RPAStraight2HandDet/Enumerated Constant3'
 * '<S117>' : 'slave_lsad_fsm/Standby2CruisingReadyDet/Enumerated Constant2'
 * '<S118>' : 'slave_lsad_fsm/Standby2CruisingReadyDet/Enumerated Constant3'
 * '<S119>' : 'slave_lsad_fsm/Standby2CruisingReadyDet/Enumerated Constant4'
 * '<S120>' : 'slave_lsad_fsm/Standby2RAReadyDet/Enumerated Constant2'
 * '<S121>' : 'slave_lsad_fsm/Standby2RAReadyDet/Enumerated Constant3'
 * '<S122>' : 'slave_lsad_fsm/Standby2RAReadyDet/Enumerated Constant4'
 * '<S123>' : 'slave_lsad_fsm/Standby2RPADet/Enumerated Constant3'
 * '<S124>' : 'slave_lsad_fsm/Standby2RPADet/Enumerated Constant4'
 * '<S125>' : 'slave_lsad_fsm/Standby2RPADet/Timer2'
 * '<S126>' : 'slave_lsad_fsm/Subsystem1/u8LsadStSResetPEBDet'
 */
#endif                                 /* RTW_HEADER_slave_lsad_fsm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
