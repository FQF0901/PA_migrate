/*
 * File: calib_lsad_fsm.c
 *
 * Code generated for Simulink model 'lsad_fsm_core'.
 *
 * Model version                  : 1.130
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Thu Nov 28 16:12:41 2024
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

#include "lsad_fsm_core.h"
#include "lsad_fsm_adapter.h"
/* Exported data definition */

/* Volatile memory section */
/* Definition for custom storage class: Volatile */
#define CtrlPara_START_SEC_VAR
#include "proj_MemMap.h"
volatile real32_T k_ActiveMaxSlopeDeg = 6.8428F;
volatile real32_T k_CmpltDuratTime = 3.0F;
volatile uint16_T k_EPBUnexpFilterTime = 100U;
volatile real32_T k_HandDuratTime = 6.0F;
volatile real32_T k_ManeuverDuratTime = 300.0F;
volatile uint8_T k_ManeuverMaxMoveStep = 20U;
volatile real32_T k_ManeuveringMaxSpd = 5.0F;
volatile real32_T k_MoveConflictOverTime = 0.2F;
volatile real32_T k_PPDuratTime = 8.0F;
volatile real32_T k_PrkInSrchMaxSpd = 30.0F;
volatile real32_T k_SuppressEnterSpd = 25.0F;
volatile real32_T k_SuppressQuitSpd = 24.0F;
volatile real32_T k_QuitDuratTime = 3.0F;
volatile real32_T k_RcvItrptDuratTime = 30.0F;
volatile uint8_T k_RcvItrpt_MaxTime = 8U;
volatile real32_T k_SlopeOverTime = 0.1F;
volatile real32_T k_TmntDuratTime = 4.0F;
volatile real32_T k_PwrMdOffFilterTime = 0.2F;
volatile real32_T k_ParkInSlotMemoDist = 30.0F;
volatile real32_T k_PrkInCofmDuratTime = 80000.0F;
volatile real32_T k_PrkInSrchDuratTime = 80000.0F;
volatile real32_T k_PrkOutCofmDuratTime = 80000.0F;
volatile real32_T k_RALimitedStrWhlAngDeg = 450.0F;
volatile real32_T k_RALimitedVehSpdKph = 25.0F;
volatile uint8_T k_SelectSlotNum = 12U;
volatile real32_T k_SwtResetDuraTime = 0.02F;
volatile real32_T k_VldSwtDuratTime = 0.03F;
volatile boolean_T k_RPAPhoneSearch = 1;
volatile boolean_T k_bIntrptEvntBrkPdl = 0;
volatile boolean_T k_bIntrptEvntSeatblt = 0;
volatile boolean_T k_EnSeatbltDebugHandshake = 0;

#define CtrlPara_STOP_SEC_VAR
#include "proj_MemMap.h"
/*
 * File trailer for generated code.
 *
 * [EOF]
 */
