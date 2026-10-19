/*
 * File: common_condition_type.h
 *
 * Code generated for Simulink model 'lsad_fsm_core'.
 *
 * Model version                  : 1.131
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Dec  2 16:05:03 2024
 */

#ifndef RTW_HEADER_common_condition_type_h_
#define RTW_HEADER_common_condition_type_h_
#include "common_condition_adapter_type.h"
#include "rtwtypes.h"

typedef enum
{
  PP_FAIL_DEFAULT = 0,                 /* Default value */
  PO_FAIL_NO_DIRECTION,
  PO_FAIL_NO_OBSTACLES,
  PO_FAIL_USS_PEB,
  PO_FAIL_SPACE_LIMITED,
  PI_FAIL_SHIFT_OVERFLOW,
  PI_FAIL_END_PATH_PEB,
  PI_FAIL_SIDE_USS_PEB,
  PI_FAIL_PATH_ID_REQ_UNREAS,
  PI_FAIL_UNEXP_P_SHIFT
}

tPlatPPFailReason;

typedef enum
{
  INTERRUPT_NONE = 0,                  /* Default value */
  INTERRUPT_DOOR_OPEN,
  INTERRUPT_SEATBELT_UNBUCKLED,
  INTERRUPT_TRUNK_OPEN,
  INTERRUPT_OBSTACLE,
  INTERRUPT_UNEXPECTED_STEER_CONTROL,
  INTERRUPT_MANUAL_BRAKE,
  INTERRUPT_RPA_ANSWER_PHONE,
  INTERRUPT_RPA_BUTTON_RELEASE,
  INTERRUPT_RPA_APP_EXIT,
  INTERRUPT_PR_DOOR_OPEN,
  INTERRUPT_RL_DOOR_OPEN,
  INTERRUPT_RR_DOOR_OPEN,
  INTERRUPT_HOOD_OPEN,
  INTERRUPT_RPA_CONN_UNSAFE,
  INTERRUPT_RPA_CONN_LOSS,
  INTERRUPT_DR_DOOR_OPEN,
  INTERRUPT_MANUAL_ACCEL,
  INTERRUPT_MANUAL_PAUSE,
  INTERRUPT_PP_REQ_PAUSE
}

tIntrptEvnt;

typedef enum
{
  TERMINATE_NONE = 0,                  /* Default value */
  TERMINATE_EXTERNAL_FAIL,
  TERMINATE_INTERNAL_FAIL,
  TERMINATE_MANVR_OVERTIME,
  TERMINATE_MANVR_OVERSPEED,
  TERMINATE_MANVR_OVERFLOW,
  TERMINATE_INTERRUPT_OVERFLOW,
  TERMINATE_INVALID_SIGNAL,
  TERMINATE_STEER_INTERFERE,
  TERMINATE_ACCEL_INTERFERE,
  TERMINATE_UNEXP_GEAR,
  TERMINATE_UNEXP_EPB,
  TERMINATE_UXEXP_ADAS,
  TERMINATE_UNEXP_AS,
  TERMINATE_VEH_BLOCK,
  TERMINATE_NO_PATH,
  TERMINATE_GEAR_INTERFERE,
  TERMINATE_MANUAL_DEACT,
  TERMINATE_INTERRUPT_OVERTIME,
  TERMINATE_TIRE_PRESSURE_ABNORMAL,
  TERMINATE_SLOPE_OVERLIMIT,
  TERMINATE_RPA_LOW_BAT,
  TERMINATE_RPA_CONN_LOSS,
  TERMINATE_RPA_CONN_UNSAFE,
  TERMINATE_RPA_APP_EXIT,
  TERMINATE_RPA_BACK,
  TERMINATE_DRIVER_DOOR_OPEN,
  TERMINATE_SEATBELT_UNBUCKLED,
  TERMINATE_DISTANCE_ARRIVED,
  TERMINATE_READY_OVERTIME,
  TERMINATE_RELEASING_FAIL,
  TERMINATE_PO_DIR_NOT_SUPPORTED,
  TERMINATE_PO_FRONT_NO_OBS,
  TERMINATE_USS_FAIL,
  TERMINATE_VISION_FAIL,
  TERMINATE_PATH_PLAN_FAIL,
  TERMINATE_OBSTACLE,
  TERMINATE_VEH_SLIP,
  TERMINATE_VEH_MOVE,
  TERMINATE_MIRROR_FOLD,
  TERMINATE_HV_NOT_READY,
  TERMINATE_RPA_SEARCH_OVERTIME,
  TERMINATE_RPA_CONFIRM_OVERTIME,
  TERMINATE_MONO_ERROR,
  TERMINATE_CTRLSTOP_OVERTIME,
  TERMINATE_CTRL_FAIL_REASON
}

tTrmntEvnt;

typedef enum
{
  INHIBIT_NONE = 0,                    /* Default value */
  INHIBIT_EXTERNAL_FAIL,
  INHIBIT_ACTIVE_DA,
  INHIBIT_TIRE_PRESSURE_ABNORMAL,
  INHIBIT_SEARCH_OVERSPEED,
  INHIBIT_HV_NOT_READY
}

tInhibitEvnt;

typedef enum
{
  FAILURE_NONE = 0,                    /* Default value */
  FAILURE_INTERNAL_FAIL,
  FAILURE_USS_FAIL,
  FAILURE_VISION_FAIL
}

tFailureEvnt;

typedef enum
{
  INTERRUTPION_NONE = 0,               /* Default value */
  INTERRUPTION_NEED_CONFIRM,
  INTERRUPTION_NO_CONFIRM
}

tIntrptType;

typedef enum
{
  RA_INTERRUPT_NONE = 0,               /* Default value */
  RA_INTERRUPT_DOOR_OPEN,
  RA_INTERRUPT_SEATBELT_UNBUCKLED,
  RA_INTERRUPT_TRUNK_OPEN,
  RA_INTERRUPT_OBSTACLE,
  RA_INTERRUPT_UNEXPECTED_STEER_CONTROL,
  RA_INTERRUPT_MANUAL_BRAKE,
  RA_INTERRUPT_RPA_ANSWER_PHONE,
  RA_INTERRUPT_RPA_BUTTON_RELEASE,
  RA_INTERRUPT_RPA_APP_EXIT,
  RA_INTERRUPT_PR_DOOR_OPEN,
  RA_INTERRUPT_RL_DOOR_OPEN,
  RA_INTERRUPT_RR_DOOR_OPEN,
  RA_INTERRUPT_HOOD_OPEN,
  RA_INTERRUPT_RPA_CONN_UNSAFE,
  RA_INTERRUPT_RPA_CONN_LOSS,
  RA_INTERRUPT_DR_DOOR_OPEN,
  RA_INTERRUPT_MANUAL_PAUSE
}

tRAIntrptEvnt;

typedef enum
{
  RA_TERMINATE_NONE = 0,               /* Default value */
  RA_TERMINATE_EXTERNAL_FAIL,
  RA_TERMINATE_INTERNAL_FAIL,
  RA_TERMINATE_MANVR_OVERTIME,
  RA_TERMINATE_MANVR_OVERSPEED,
  RA_TERMINATE_MANVR_OVERFLOW,
  RA_TERMINATE_INTERRUPT_OVERFLOW,
  RA_TERMINATE_INVALID_SIGNAL,
  RA_TERMINATE_STEER_INTERFERE,
  RA_TERMINATE_ACCEL_INTERFERE,
  RA_TERMINATE_UNEXP_GEAR,
  RA_TERMINATE_UNEXP_EPB,
  RA_TERMINATE_UXEXP_ADAS,
  RA_TERMINATE_UNEXP_AS,
  RA_TERMINATE_VEH_BLOCK,
  RA_TERMINATE_NO_PATH,
  RA_TERMINATE_GEAR_INTERFERE,
  RA_TERMINATE_MANUAL_DEACT,
  RA_TERMINATE_INTERRUPT_OVERTIME,
  RA_TERMINATE_TIRE_PRESSURE_ABNORMAL,
  RA_TERMINATE_SLOPE_OVERLIMIT,
  RA_TERMINATE_RPA_LOW_BAT,
  RA_TERMINATE_RPA_CONN_LOSS,
  RA_TERMINATE_RPA_CONN_UNSAFE,
  RA_TERMINATE_RPA_APP_EXIT,
  RA_TERMINATE_RPA_BACK,
  RA_TERMINATE_DRIVER_DOOR_OPEN,
  RA_TERMINATE_SEATBELT_UNBUCKLED,
  RA_TERMINATE_DISTANCE_ARRIVED,
  RA_TERMINATE_READY_OVERTIME,
  RA_TERMINATE_RELEASING_FAIL,
  RA_TERMINATE_PO_DIR_NOT_SUPPORTED,
  RA_TERMINATE_PO_FRONT_NO_OBS,
  RA_TERMINATE_USS_FAIL,
  RA_TERMINATE_VISION_FAIL,
  RA_TERMINATE_PATH_PLAN_FAIL,
  RA_TERMINATE_OBSTACLE,
  RA_TERMINATE_VEH_SLIP,
  RA_TERMINATE_MIRROR_FOLD,
  RA_TERMINATE_HV_NOT_READY
}

tRATrmntEvnt;

typedef enum
{
  RA_FAILURE_NONE = 0,                 /* Default value */
  RA_FAILURE_INTERNAL_FAIL,
  RA_FAILURE_USS_FAIL,
  RA_FAILURE_VISION_FAIL
}

tRAFailureEvnt;

typedef enum
{
  RA_QUIT_NONE = 0,                    /* Default value */
  RA_QUIT_INTERNAL_FAIL,
  RA_QUIT_EXTERNAL_FAIL,
  RA_QUIT_SEARCH_OVERSPEED,
  RA_QUIT_SEARCH_OVERSLOPE,
  RA_QUIT_ACTIVE_DA,
  RA_QUIT_MANUAL_DEACTIVATE,
  RA_QUIT_SEARCH_OVERTIME,
  RA_QUIT_SEARCH_GEAR_R,
  RA_QUIT_CONFIRM_OVERTIME,
  RA_QUIT_NO_PARK_OUT_DIR,
  RA_QUIT_PATH_PLAN_FAIL,
  RA_QUIT_HANDSHAKE_FAIL,
  RA_QUIT_VEH_MOVE,
  RA_QUIT_RPA_GEAR_NOT_P,
  RA_QUIT_RPA_CONNECT_OVERTIME,
  RA_QUIT_RPA_LEAVE_WO_P,
  RA_QUIT_INVALID_SIGNAL,
  RA_QUIT_TIRE_PRESSURE_ABNORMAL,
  RA_QUIT_RPA_LOW_BAT,
  RA_QUIT_RPA_CONN_LOSS,
  RA_QUIT_RPA_CONN_UNSAFE,
  RA_QUIT_RPA_APP_EXIT,
  RA_QUIT_DR_DOOR_OPEN,
  RA_QUIT_PR_DOOR_OPEN,
  RA_QUIT_RL_DOOR_OPEN,
  RA_QUIT_RR_DOOR_OPEN,
  RA_QUIT_HOOD_OPEN,
  RA_QUIT_TRUNK_OPEN,
  RA_QUIT_WAIT_OVERTIME,
  RA_QUIT_SEATBELT_UNBUCKLED,
  RA_QUIT_LOCATION_UNAVL,
  RA_QUIT_RELEASING_FAIL,
  RA_QUIT_ACTIVE_MOD,
  RA_QUIT_USS_FAIL,
  RA_QUIT_VISION_FAIL,
  RA_QUIT_MIRROR_FOLD,
  RA_QUIT_HV_NOT_READY
}

tRAQuitEvnt;

typedef enum
{
  RA_INTERRUTPION_NONE = 0,            /* Default value */
  RA_INTERRUPTION_NEED_CONFIRM,
  RA_INTERRUPTION_NO_CONFIRM
}

tRAIntrptType;

typedef struct
{
  boolean_T bVehStill;
  boolean_T bPrkOverSlope;
  boolean_T bDrvBlock;
  boolean_T bVehSlip;
  boolean_T bTirePressNorm;
  boolean_T bDrvAssistNoActv;
  boolean_T bEPBClosed;
  boolean_T bEPBUnexp;
  boolean_T bGearPosConflict;
  boolean_T bExterActualNorm;
  boolean_T bGearNorm;
  boolean_T bGearP;
  boolean_T bGearR;
  boolean_T bSysPwrMdOff;
  boolean_T bMoveConflict;
  boolean_T bMoveSame;
  boolean_T bESCPulFail;
  uint8_T u8Res3[3];
}

tCondiVeh;

typedef struct
{
  boolean_T bFLDrClose;
  boolean_T bFRDrClose;
  boolean_T bRLDrClose;
  boolean_T bRRDrClose;
  boolean_T bHoodDrClose;
  boolean_T bTailGateClose;
  boolean_T bSeatbltAct;
  uint8_T u8Res;
}

tCondiDoorSblt;

typedef struct
{
  tPlatPPFailReason ePlatPPFailReason;
  boolean_T bRecomdSlot;
  boolean_T bObstAppear;
  boolean_T bPrkCtrlFail;
  boolean_T bActvStsNeedRlsBrk;
}

tCondiPlatform;

typedef struct
{
  boolean_T bHpaPPOvertime;
  boolean_T bHpaHandshakOvertime;
  boolean_T bHpaActiveRdyOvertime;
  boolean_T bHpaActiveOvertime;
  boolean_T bHpaIntrptOverflow;
  boolean_T bHpaIntrptOvertime;
  boolean_T bHpaCmpltDurattime;
  boolean_T bHpaCmpltOvertime;
  boolean_T bHpaQuitDurattime;
  boolean_T bHpaTrmntDurattime;
  boolean_T bHpaTrmntOvertime;
  boolean_T bHpaPwrOnSelfChkDurattime;
}

tHPACondiOverFlag;

typedef struct
{
  tQuitEvnt eHPAQuitEvnt;
  tIntrptEvnt eHPAIntrptEvnt;
  tTrmntEvnt eHPATrmntEvnt;
  tInhibitEvnt eHPAInhibitEvnt;
  tFailureEvnt eHPAFailureEvnt;
  tIntrptType eHPAIntrptType;
}

tHPAEvnt;

typedef struct
{
  boolean_T bPPOvertime;
  boolean_T bHandshakOvertime;
  boolean_T bActiveRdyOvertime;
  boolean_T bActiveOvertime;
  boolean_T bIntrptOverflow;
  boolean_T bStepOverflow;
  boolean_T bIntrptOvertime;
  boolean_T bCmpltDurattime;
  boolean_T bCmpltOvertime;
  boolean_T bQuitDurattime;
  boolean_T bTrmntDurattime;
  boolean_T bTrmntOvertime;
  boolean_T bPwrOnSelfChkDurattime;
  boolean_T bCtrlStopOvertime;
  uint8_T u8Res2[2];
}

tCondiOverFlag;

typedef struct
{
  tIntrptEvnt ePAIntrptEvnt;
  tTrmntEvnt ePATrmntEvnt;
  tInhibitEvnt ePAInhibitEvnt;
  tFailureEvnt ePAFailureEvnt;
  tIntrptType ePAIntrptType;
}

tPAEvnt;

typedef struct
{
  boolean_T bRAPPOvertime;
  boolean_T bRAHandshakeOvertime;
  boolean_T bRAQuitDurattime;
  boolean_T bRAQuitOvertime;
  boolean_T bRAActiveReadyOvertime;
  boolean_T bRAActiveOvertime;
  boolean_T bRAIntrptOvertime;
  boolean_T bRAIntrptOverflow;
  boolean_T bRACmpltDurattime;
  boolean_T bRACmpltOvertime;
  boolean_T bRATrmntDurattime;
  boolean_T bRATrmntOvertime;
  boolean_T bRASelfCheckOvertime;
  real_T u8Res[3];
}

tRACondiOverFlag;

typedef struct
{
  tRAIntrptEvnt eRAIntrptEvnt;
  tRATrmntEvnt eRATrmntEvnt;
  tRAFailureEvnt eRAFailureEvnt;
  tRAQuitEvnt eRAQuitEvnt;
  tRAIntrptType eRAIntrptType;
}

tRAEvnt;

typedef struct
{
  tCondiVeh sCondiVeh;
  tCondiDoorSblt sCondiDoorSblt;
  tCondiPlatform sCondiPlatform;
}

tVehCommon;

typedef struct
{
  tHPACondiOverFlag sHPACondiOverFlag;
  tHPAEvnt sHPAEvnt;
}

tHpaStateCommon;

typedef struct
{
  tCondiOverFlag sCondiOverFlag;
  tPAEvnt sPAEvnt;
}

tPaStateCommon;

typedef struct
{
  tRACondiOverFlag sRACondiOverFlag;
  tRAEvnt sRAEvnt;
}

tRaStateCommon;

#endif                                 /* RTW_HEADER_common_condition_type_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
