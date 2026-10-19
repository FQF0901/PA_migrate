/*
 * File: master_lsad_fsm.h
 *
 * Code generated for Simulink model 'master_lsad_fsm'.
 *
 * Model version                  : 3.2684
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Thu Nov 28 16:11:58 2024
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

#ifndef RTW_HEADER_master_lsad_fsm_h_
#define RTW_HEADER_master_lsad_fsm_h_
#include <string.h>
#include "common_condition_type.h"
#include "hmi_data_rx_type.h"
#include "lsad_fsm_core_type.h"
#include "slave_lsad_fsm_type.h"
#include "master_lsad_fsm_type.h"
#ifndef master_lsad_fsm_COMMON_INCLUDES_
#define master_lsad_fsm_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* master_lsad_fsm_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Includes for objects with custom storage classes. */
#include "calib_lsad_fsm.h"

/* Block signals and states (default storage) for model 'master_lsad_fsm' */
#ifndef master_lsad_fsm_MDLREF_HIDE_CHILD_

typedef struct
{
  real_T bStandby2Fail;                /* '<S13>/Data Type Conversion' */
  real32_T UnitDelay1_DSTATE;          /* '<S112>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_i;        /* '<S114>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_a;        /* '<S116>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_g;        /* '<S118>/Unit Delay1' */
  tLSAD_FuncType UnitDelay_DSTATE;     /* '<S2>/Unit Delay' */
  struct
  {
    uint_T is_Enable:3;                /* '<Root>/master_lsad_fsm_stateflow' */
    uint_T is_c3_master_lsad_fsm:2;    /* '<Root>/master_lsad_fsm_stateflow' */
    uint_T is_Disable:2;               /* '<Root>/master_lsad_fsm_stateflow' */
    uint_T is_Prepare_Main:2;          /* '<Root>/master_lsad_fsm_stateflow' */
    uint_T is_Finish:2;                /* '<Root>/master_lsad_fsm_stateflow' */
    uint_T is_Active_Main:2;           /* '<Root>/master_lsad_fsm_stateflow' */
    uint_T is_active_c3_master_lsad_fsm:1;/* '<Root>/master_lsad_fsm_stateflow' */
    uint_T bStandby2Prepare:1;         /* '<S30>/AND' */
    uint_T bTerminate2Standby:1;       /* '<S29>/Logical Operator' */
    uint_T bSuspend2Prepare:1;         /* '<S28>/AND' */
    uint_T bSuspend2Active:1;          /* '<S27>/Switch' */
    uint_T bStandby2Inhibit:1;         /* '<S26>/Logical Operator' */
    uint_T bQuit2Standby:1;            /* '<S25>/AND' */
    uint_T bPrepare2Suspend:1;         /* '<S24>/AND' */
    uint_T bPrepare2Quit:1;            /* '<S23>/AND' */
    uint_T bPrepare2Handshake:1;       /* '<S22>/AND' */
    uint_T bPP2Terminate:1;            /* '<S21>/OR' */
    uint_T bPP2Active:1;               /* '<S20>/Logical Operator' */
    uint_T bHandshake2Terminate:1;     /* '<S12>/OR' */
    uint_T bHandshake2Quit:1;          /* '<S11>/AND' */
    uint_T bHandshake2PP:1;            /* '<S10>/Logical Operator5' */
    uint_T bComplete2Standby:1;        /* '<S5>/Logical Operator1' */
    uint_T UnitDelay1_DSTATE_k:1;      /* '<S76>/Unit Delay1' */
    uint_T UnitDelay2_DSTATE:1;        /* '<S111>/Unit Delay2' */
    uint_T UnitDelay1_DSTATE_ks:1;     /* '<S77>/Unit Delay1' */
    uint_T UnitDelay2_DSTATE_f:1;      /* '<S113>/Unit Delay2' */
    uint_T UnitDelay1_DSTATE_e:1;      /* '<S78>/Unit Delay1' */
    uint_T UnitDelay2_DSTATE_a:1;      /* '<S115>/Unit Delay2' */
    uint_T Delay_DSTATE:1;             /* '<S79>/Delay' */
    uint_T UnitDelay1_DSTATE_o:1;      /* '<S106>/Unit Delay1' */
    uint_T UnitDelay2_DSTATE_l:1;      /* '<S117>/Unit Delay2' */
  }
  bitsForTID0;
}
DW_master_lsad_fsm_f_T;

#endif                                 /*master_lsad_fsm_MDLREF_HIDE_CHILD_*/

extern void master_lsad_fsm_Init(void);
extern void master_lsad_fsm(const tPAHmiRx *rtu_sPAHmiRx, const tPaStateCommon
  *rtu_sPaStateCommon, const tVehCommon *rtu_sVehCommon, const tVehDataRx
  *rtu_sVehDataRx, const tRelatedModuleInfo *rtu_sRelatedModuleInfo, const
  tHpaStateCommon *rtu_sHpaStateCommon, const tSlaveLsadFsm *rtu_sSlaveLsadFsm,
  const tHPAHmiRx *rtu_sHPAHmiRx, const tRAHmiRx *rtu_sRAHmiRx, const boolean_T *
  rtu_sRaStateCommon_sRACondiOverFlag_bRAIntrptOvertime, const boolean_T
  *rtu_sRaStateCommon_sRACondiOverFlag_bRACmpltDurattime, const boolean_T
  *rtu_sRaStateCommon_sRACondiOverFlag_bRACmpltOvertime, const boolean_T
  *rtu_sRaStateCommon_sRACondiOverFlag_bRATrmntDurattime, const boolean_T
  *rtu_sRaStateCommon_sRACondiOverFlag_bRATrmntOvertime, const tRAIntrptEvnt
  *rtu_sRaStateCommon_sRAEvnt_eRAIntrptEvnt, const tRATrmntEvnt
  *rtu_sRaStateCommon_sRAEvnt_eRATrmntEvnt, const tRAIntrptType
  *rtu_sRaStateCommon_sRAEvnt_eRAIntrptType, const tDiagInfo *rtu_sDiagInfo,
  const tMasterLsadFsm *rtu_sLastMasterLsadFsm, const tPaStateAdptr
  *rtu_sPaStateAdptr, tMasterLsadFsm *rty_sMasterLsadFsm);

/* Model reference registration function */
extern void master_lsad_fsm_initialize(void);

#ifndef master_lsad_fsm_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern DW_master_lsad_fsm_f_T master_lsad_fsm_DW;

#endif                                 /*master_lsad_fsm_MDLREF_HIDE_CHILD_*/

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/EMSingleConversion' : Unused code path elimination
 * Block '<Root>/EMSingleConversion1' : Unused code path elimination
 * Block '<S16>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S19>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'master_lsad_fsm'
 * '<S1>'   : 'master_lsad_fsm/Active2CompleteDet'
 * '<S2>'   : 'master_lsad_fsm/Active2PrepareDet'
 * '<S3>'   : 'master_lsad_fsm/Active2SuspendDet'
 * '<S4>'   : 'master_lsad_fsm/Active2TerminateDet'
 * '<S5>'   : 'master_lsad_fsm/Complete2StandbyDet'
 * '<S6>'   : 'master_lsad_fsm/Enble2OffDet'
 * '<S7>'   : 'master_lsad_fsm/Fail2EnbleDet'
 * '<S8>'   : 'master_lsad_fsm/Fail2InhibitDet'
 * '<S9>'   : 'master_lsad_fsm/Fail2OffDet'
 * '<S10>'  : 'master_lsad_fsm/Hand2PrkCtrlDet'
 * '<S11>'  : 'master_lsad_fsm/Handshake2Quit'
 * '<S12>'  : 'master_lsad_fsm/Handshake2TerminateDet'
 * '<S13>'  : 'master_lsad_fsm/Idle2FailDet'
 * '<S14>'  : 'master_lsad_fsm/Inhibit2EnbleDet'
 * '<S15>'  : 'master_lsad_fsm/Inhibit2FailDet'
 * '<S16>'  : 'master_lsad_fsm/Inhibit2OffDet'
 * '<S17>'  : 'master_lsad_fsm/MappingStsDet'
 * '<S18>'  : 'master_lsad_fsm/Off2EnbleDet'
 * '<S19>'  : 'master_lsad_fsm/Off2FailDet'
 * '<S20>'  : 'master_lsad_fsm/PP2ActiveDet'
 * '<S21>'  : 'master_lsad_fsm/PP2TerminateDet'
 * '<S22>'  : 'master_lsad_fsm/Prepare2HandshakeDet'
 * '<S23>'  : 'master_lsad_fsm/Prepare2QuitDet'
 * '<S24>'  : 'master_lsad_fsm/Prepare2SuspendDet'
 * '<S25>'  : 'master_lsad_fsm/Quit2IdleDet'
 * '<S26>'  : 'master_lsad_fsm/Standby2InhibitDet'
 * '<S27>'  : 'master_lsad_fsm/Suspend2ActiveDet'
 * '<S28>'  : 'master_lsad_fsm/Suspend2PrepareDet'
 * '<S29>'  : 'master_lsad_fsm/Terminate2StandbyDet'
 * '<S30>'  : 'master_lsad_fsm/bStandby2PrepareDet'
 * '<S31>'  : 'master_lsad_fsm/master_lsad_fsm_stateflow'
 * '<S32>'  : 'master_lsad_fsm/Active2CompleteDet/Enumerated Constant1'
 * '<S33>'  : 'master_lsad_fsm/Active2CompleteDet/Enumerated Constant2'
 * '<S34>'  : 'master_lsad_fsm/Active2CompleteDet/Enumerated Constant3'
 * '<S35>'  : 'master_lsad_fsm/Active2CompleteDet/Enumerated Constant4'
 * '<S36>'  : 'master_lsad_fsm/Active2PrepareDet/Enumerated Constant'
 * '<S37>'  : 'master_lsad_fsm/Active2PrepareDet/Enumerated Constant1'
 * '<S38>'  : 'master_lsad_fsm/Active2PrepareDet/Enumerated Constant2'
 * '<S39>'  : 'master_lsad_fsm/Active2PrepareDet/Enumerated Constant3'
 * '<S40>'  : 'master_lsad_fsm/Active2SuspendDet/Enumerated Constant1'
 * '<S41>'  : 'master_lsad_fsm/Active2SuspendDet/Enumerated Constant2'
 * '<S42>'  : 'master_lsad_fsm/Active2SuspendDet/Enumerated Constant3'
 * '<S43>'  : 'master_lsad_fsm/Active2TerminateDet/Enumerated Constant1'
 * '<S44>'  : 'master_lsad_fsm/Active2TerminateDet/Enumerated Constant2'
 * '<S45>'  : 'master_lsad_fsm/Active2TerminateDet/Enumerated Constant3'
 * '<S46>'  : 'master_lsad_fsm/Complete2StandbyDet/Enumerated Constant1'
 * '<S47>'  : 'master_lsad_fsm/Hand2PrkCtrlDet/Enumerated Constant1'
 * '<S48>'  : 'master_lsad_fsm/Hand2PrkCtrlDet/Enumerated Constant3'
 * '<S49>'  : 'master_lsad_fsm/Handshake2Quit/Enumerated Constant'
 * '<S50>'  : 'master_lsad_fsm/Handshake2Quit/Enumerated Constant2'
 * '<S51>'  : 'master_lsad_fsm/Handshake2TerminateDet/Enumerated Constant1'
 * '<S52>'  : 'master_lsad_fsm/Handshake2TerminateDet/Enumerated Constant2'
 * '<S53>'  : 'master_lsad_fsm/Handshake2TerminateDet/Enumerated Constant3'
 * '<S54>'  : 'master_lsad_fsm/MappingStsDet/Enumerated Constant1'
 * '<S55>'  : 'master_lsad_fsm/MappingStsDet/Enumerated Constant2'
 * '<S56>'  : 'master_lsad_fsm/MappingStsDet/Enumerated Constant3'
 * '<S57>'  : 'master_lsad_fsm/MappingStsDet/Enumerated Constant4'
 * '<S58>'  : 'master_lsad_fsm/Off2EnbleDet/Enumerated Constant1'
 * '<S59>'  : 'master_lsad_fsm/Off2FailDet/Enumerated Constant1'
 * '<S60>'  : 'master_lsad_fsm/PP2ActiveDet/Enumerated Constant2'
 * '<S61>'  : 'master_lsad_fsm/PP2ActiveDet/Enumerated Constant3'
 * '<S62>'  : 'master_lsad_fsm/PP2ActiveDet/Enumerated Constant4'
 * '<S63>'  : 'master_lsad_fsm/PP2TerminateDet/Enumerated Constant1'
 * '<S64>'  : 'master_lsad_fsm/PP2TerminateDet/Enumerated Constant2'
 * '<S65>'  : 'master_lsad_fsm/PP2TerminateDet/Enumerated Constant3'
 * '<S66>'  : 'master_lsad_fsm/Prepare2HandshakeDet/Enumerated Constant'
 * '<S67>'  : 'master_lsad_fsm/Prepare2HandshakeDet/Enumerated Constant1'
 * '<S68>'  : 'master_lsad_fsm/Prepare2QuitDet/Enumerated Constant'
 * '<S69>'  : 'master_lsad_fsm/Prepare2QuitDet/Enumerated Constant1'
 * '<S70>'  : 'master_lsad_fsm/Prepare2QuitDet/Enumerated Constant2'
 * '<S71>'  : 'master_lsad_fsm/Prepare2SuspendDet/Enumerated Constant'
 * '<S72>'  : 'master_lsad_fsm/Prepare2SuspendDet/Enumerated Constant1'
 * '<S73>'  : 'master_lsad_fsm/Prepare2SuspendDet/Enumerated Constant2'
 * '<S74>'  : 'master_lsad_fsm/Quit2IdleDet/Enumerated Constant'
 * '<S75>'  : 'master_lsad_fsm/Quit2IdleDet/Enumerated Constant2'
 * '<S76>'  : 'master_lsad_fsm/Suspend2ActiveDet/APABlindUnLockNeedContinue'
 * '<S77>'  : 'master_lsad_fsm/Suspend2ActiveDet/APABlindUnLockNeedContinue1'
 * '<S78>'  : 'master_lsad_fsm/Suspend2ActiveDet/APABlindUnLockNeedContinue2'
 * '<S79>'  : 'master_lsad_fsm/Suspend2ActiveDet/EdgeRising'
 * '<S80>'  : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant'
 * '<S81>'  : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant1'
 * '<S82>'  : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant10'
 * '<S83>'  : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant11'
 * '<S84>'  : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant12'
 * '<S85>'  : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant13'
 * '<S86>'  : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant14'
 * '<S87>'  : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant15'
 * '<S88>'  : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant16'
 * '<S89>'  : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant17'
 * '<S90>'  : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant18'
 * '<S91>'  : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant19'
 * '<S92>'  : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant2'
 * '<S93>'  : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant20'
 * '<S94>'  : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant23'
 * '<S95>'  : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant24'
 * '<S96>'  : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant25'
 * '<S97>'  : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant26'
 * '<S98>'  : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant27'
 * '<S99>'  : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant3'
 * '<S100>' : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant4'
 * '<S101>' : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant5'
 * '<S102>' : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant6'
 * '<S103>' : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant7'
 * '<S104>' : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant8'
 * '<S105>' : 'master_lsad_fsm/Suspend2ActiveDet/Enumerated Constant9'
 * '<S106>' : 'master_lsad_fsm/Suspend2ActiveDet/RPABlindUnLockNeedContinue'
 * '<S107>' : 'master_lsad_fsm/Suspend2ActiveDet/ifthenelse'
 * '<S108>' : 'master_lsad_fsm/Suspend2ActiveDet/ifthenelse1'
 * '<S109>' : 'master_lsad_fsm/Suspend2ActiveDet/ifthenelse2'
 * '<S110>' : 'master_lsad_fsm/Suspend2ActiveDet/ifthenelse3'
 * '<S111>' : 'master_lsad_fsm/Suspend2ActiveDet/APABlindUnLockNeedContinue/Latch_Reset'
 * '<S112>' : 'master_lsad_fsm/Suspend2ActiveDet/APABlindUnLockNeedContinue/Timer2'
 * '<S113>' : 'master_lsad_fsm/Suspend2ActiveDet/APABlindUnLockNeedContinue1/Latch_Reset'
 * '<S114>' : 'master_lsad_fsm/Suspend2ActiveDet/APABlindUnLockNeedContinue1/Timer2'
 * '<S115>' : 'master_lsad_fsm/Suspend2ActiveDet/APABlindUnLockNeedContinue2/Latch_Reset'
 * '<S116>' : 'master_lsad_fsm/Suspend2ActiveDet/APABlindUnLockNeedContinue2/Timer2'
 * '<S117>' : 'master_lsad_fsm/Suspend2ActiveDet/RPABlindUnLockNeedContinue/Latch_Reset'
 * '<S118>' : 'master_lsad_fsm/Suspend2ActiveDet/RPABlindUnLockNeedContinue/Timer2'
 * '<S119>' : 'master_lsad_fsm/Suspend2PrepareDet/Enumerated Constant'
 * '<S120>' : 'master_lsad_fsm/Suspend2PrepareDet/Enumerated Constant1'
 * '<S121>' : 'master_lsad_fsm/Suspend2PrepareDet/Enumerated Constant2'
 * '<S122>' : 'master_lsad_fsm/Suspend2PrepareDet/Enumerated Constant3'
 * '<S123>' : 'master_lsad_fsm/Suspend2PrepareDet/Enumerated Constant4'
 * '<S124>' : 'master_lsad_fsm/Suspend2PrepareDet/Enumerated Constant5'
 * '<S125>' : 'master_lsad_fsm/Suspend2PrepareDet/Enumerated Constant6'
 * '<S126>' : 'master_lsad_fsm/Suspend2PrepareDet/Enumerated Constant7'
 * '<S127>' : 'master_lsad_fsm/Suspend2PrepareDet/Enumerated Constant8'
 * '<S128>' : 'master_lsad_fsm/Terminate2StandbyDet/Enumerated Constant'
 * '<S129>' : 'master_lsad_fsm/Terminate2StandbyDet/Enumerated Constant1'
 * '<S130>' : 'master_lsad_fsm/bStandby2PrepareDet/Enumerated Constant'
 * '<S131>' : 'master_lsad_fsm/bStandby2PrepareDet/Enumerated Constant1'
 * '<S132>' : 'master_lsad_fsm/bStandby2PrepareDet/Enumerated Constant2'
 * '<S133>' : 'master_lsad_fsm/bStandby2PrepareDet/Enumerated Constant3'
 */
#endif                                 /* RTW_HEADER_master_lsad_fsm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
