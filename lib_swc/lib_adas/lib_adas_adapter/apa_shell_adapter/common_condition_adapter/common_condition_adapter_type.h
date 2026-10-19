/*
 * File: common_condition_adapter_type.h
 *
 * Code generated for Simulink model 'lsad_fsm_adapter'.
 *
 * Model version                  : 1.132
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Thu Nov 28 16:38:14 2024
 */

#ifndef RTW_HEADER_common_condition_adapter_type_h_
#define RTW_HEADER_common_condition_adapter_type_h_
#include "rtwtypes.h"

typedef enum
{
  PO_SLOT_TYPE_NONE = 0,               /* Default value */
  PO_SLOT_TYPE_PARALLEL,
  PO_SLOT_TYPE_PERPENDI,
  PO_SLOT_TYPE_OBLIQUE
}

tPOSlotType;

typedef enum
{
  PO_DIR_NO_REQ = 0,                   /* Default value */
  PO_HEAD_DIR_LEFT,
  PO_HEAD_DIR_STRAIGHT,
  PO_HEAD_DIR_RIGHT,
  PO_TAIL_DIR_LEFT,
  PO_TAIL_DIR_STRAIGHT,
  PO_TAIL_DIR_RIGHT
}

tPODir;

typedef enum
{
  APA_MODE_NONE = 0,                   /* Default value */
  APA_MODE_PARK_IN,
  APA_MODE_PARK_OUT,
  APA_MODE_SELF_SELECT,
  APA_MODE_STRAIGHT,
  APA_MODE_NP
}

tAPAMod;

typedef enum
{
  PARK_FUNC_NONE = 0,                  /* Default value */
  PARK_FUNC_APA,
  PARK_FUNC_RPA
}

tPrkFnct;

typedef enum
{
  DRAG_SLOT_TYPE_NONE = 0,             /* Default value */
  DRAG_SLOT_TYPE_PARALLEL,
  DRAG_SLOT_TYPE_PERPENDI,
  DRAG_SLOT_TYPE_OBLIQUE
}

tDragSlotType;

typedef enum
{
  BG_SEARCH_NONE = 0,                  /* Default value */
  BG_SEARCH_INTERNAL_FAIL,
  BG_SEARCH_EXTERNAL_FAIL,
  BG_SEARCH_OVERSPEED,
  BG_SEARCH_ACTIVE_DA,
  BG_SEARCH_ACTIVE_MOD,
  BG_SEARCH_INVALID_SIGNAL,
  BG_SEARCH_TIRE_PRESSURE_ABNORMAL,
  BG_SEARCH_LOCATION_UNAVL,
  BG_SEARCH_USS_FAIL,
  BG_SEARCH_VISION_FAIL
}

tBgSrchEvnt;

typedef enum
{
  SUSPEND_NONE = 0,                    /* Default value */
  SUSPEND_SPEED_HIGH,
  SUSPEND_DR_DOOR_OPEN,
  SUSPEND_PR_DOOR_OPEN,
  SUSPEND_RL_DOOR_OPEN,
  SUSPEND_RR_DOOR_OPEN,
  SUSPEND_HOOD_OPEN,
  SUSPEND_TRUNK_OPEN,
  SUSPEND_WAIT_OVERTIME,
  SUSPEND_NOT_STANDSTILLED,
  SUSPEND_DOOR_OPEN,
  SUSPEND_SEATBELT_UNBUCKLED,
  SUSPEND_MIRROR_FOLD,
  SUSPEND_RPA_OBSTACLE
}

tSuspendEvnt;

typedef enum
{
  QUIT_NONE = 0,                       /* Default value */
  QUIT_INTERNAL_FAIL,
  QUIT_EXTERNAL_FAIL,
  QUIT_SEARCH_OVERSPEED,
  QUIT_SEARCH_OVERSLOPE,
  QUIT_ACTIVE_DA,
  QUIT_MANUAL_DEACTIVATE,
  QUIT_SEARCH_OVERTIME,
  QUIT_SEARCH_GEAR_R,
  QUIT_CONFIRM_OVERTIME,
  QUIT_NO_PARK_OUT_DIR,
  QUIT_PATH_PLAN_FAIL,
  QUIT_HANDSHAKE_FAIL,
  QUIT_VEH_MOVE,
  QUIT_RPA_GEAR_NOT_P,
  QUIT_RPA_CONNECT_OVERTIME,
  QUIT_RPA_LEAVE_WO_P,
  QUIT_INVALID_SIGNAL,
  QUIT_TIRE_PRESSURE_ABNORMAL,
  QUIT_RPA_LOW_BAT,
  QUIT_RPA_CONN_LOSS,
  QUIT_RPA_CONN_UNSAFE,
  QUIT_RPA_APP_EXIT,
  QUIT_DR_DOOR_OPEN,
  QUIT_PR_DOOR_OPEN,
  QUIT_RL_DOOR_OPEN,
  QUIT_RR_DOOR_OPEN,
  QUIT_HOOD_OPEN,
  QUIT_TRUNK_OPEN,
  QUIT_WAIT_OVERTIME,
  QUIT_SEATBELT_UNBUCKLED,
  QUIT_LOCATION_UNAVL,
  QUIT_RELEASING_FAIL,
  QUIT_ACTIVE_MOD,
  QUIT_USS_FAIL,
  QUIT_VISION_FAIL,
  QUIT_MIRROR_FOLD,
  QUIT_HV_NOT_READY,
  QUIT_MONO_ERROR,
  QUIT_CTRLSTOP_OVERTIME
}

tQuitEvnt;

typedef struct
{
  boolean_T bPISrchOvertime;
  boolean_T bSupressOvertime;
  boolean_T bPICnfmOvertime;
  boolean_T bPOCnfmOvertime;
  boolean_T bRmtCnnctDuratime;
  boolean_T bRmtCnnctOvertime;
  boolean_T bBackgroundOvertime;
  uint8_T u8Res1;
}

tCondiOverFlagAdptr;

typedef struct
{
  tPOSlotType ePOSlotType;
  tPODir ePODir;
  real32_T POSlotLength;
  tAPAMod eAPAMod;
  tPrkFnct ePrkFnct;
  tDragSlotType eDragSlotType;
  boolean_T bAppInitRPA;
  boolean_T bBLEConnect;
  boolean_T bBLEScrt;
  boolean_T bPhoneHangUp;
  boolean_T bBgSrchDisable;
  boolean_T bHmiSelfSelTypeSelected;
  uint8_T u8Res2[2];
}

tCondiHMI;

typedef struct
{
  real32_T f32PrkSlotX0;
  real32_T f32PrkSlotY0;
  real32_T f32PrkSlotX1;
  real32_T f32PrkSlotY1;
  real32_T f32PrkSlotX2;
  real32_T f32PrkSlotY2;
  real32_T f32PrkSlotX3;
  real32_T f32PrkSlotY3;
}

tPrkSlot;

typedef struct
{
  tBgSrchEvnt ePABgSrchEvnt;
  tSuspendEvnt ePASuspendEvnt;
  tQuitEvnt ePAQuitEvnt;
}

tPAEvntAdptr;

typedef struct
{
  boolean_T bRPADrClose;
  boolean_T bRPAVehStdstil;
  boolean_T bRPAGearAval;
  boolean_T bRPAEPBAval;
  boolean_T bRPASlopAval;
  boolean_T bRPASurrAval;
  boolean_T bRPASysNorm;
  boolean_T bRPATirePresNorm;
  boolean_T bRPASlotFind;
  boolean_T bBLEConnect;
  boolean_T bBLEScrt;
  boolean_T bTrunkClose;
  boolean_T bHoodClose;
  uint8_T u8Res3[3];
}

tRPAChkList;

typedef struct
{
  tCondiOverFlagAdptr sCondiOverFlagAdptr;
  tCondiHMI sCondiHMI;
  tPrkSlot sDragPrkSlot;
  tPAEvntAdptr sPAEvntAdptr;
  tRPAChkList sRPAChkList;
}

tPaStateAdptr;

#endif                         /* RTW_HEADER_common_condition_adapter_type_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
