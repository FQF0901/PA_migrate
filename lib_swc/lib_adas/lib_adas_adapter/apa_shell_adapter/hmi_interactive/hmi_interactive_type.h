/*
 * File: hmi_interactive_type.h
 *
 * Code generated for Simulink model 'lsad_fsm_adapter'.
 *
 * Model version                  : 1.132
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Thu Nov 28 16:38:14 2024
 */

#ifndef RTW_HEADER_hmi_interactive_type_h_
#define RTW_HEADER_hmi_interactive_type_h_
#include "rtwtypes.h"

typedef enum
{
  SLOT_DISP_NO_REQ = 0,                /* Default value */
  SLOT_DISP_UNAVAILABLE,
  SLOT_DISP_AVAILABLE,
  SLOT_DISP_SELECTED,
  SLOT_DISP_UNKNOWN
}

tDispSlotStatus;

typedef enum
{
  DISP_SLOT_TYP_NO_REQ = 0,            /* Default value */
  DISP_SLOT_TYP_PARALLEL,
  DISP_SLOT_TYP_PERPENDICULAR,
  DISP_SLOT_TYP_OBLIQUE
}

tDispSlotType;

typedef enum
{
  DISP_SLOT_SUB_TYP_MARKED = 0,        /* Default value */
  DISP_SLOT_SUB_TYP_SPATIAL,
  DISP_SLOT_SUB_TYP_MECHANICAL,
  DISP_SLOT_SUB_TYP_HANDICAP
}

tDispSlotSubType;

typedef enum
{
  DISP_OBS_TYP_NO = 0,                 /* Default value */
  DISP_OBS_TYP_PEDESTRIAN,
  DISP_OBS_TYP_BICYCLE,
  DISP_OBS_TYP_MOTOBIKE,
  DISP_OBS_TYP_TRICYCLE,
  DISP_OBS_TYP_CAR,
  DISP_OBS_TYP_TRUCK,
  DISP_OBS_TYP_BUS,
  DISP_OBS_TYP_SPECIAL,
  DISP_OBS_TYP_SUV,
  DISP_OBS_TYP_MINIBUS,
  DISP_OBS_TYP_AMBULANCE,
  DISP_OBS_TYP_FIRETRUCK,
  DISP_OBS_TYP_ENGINEERVEHICLE,
  DISP_OBS_TYP_ANIMAL,
  DISP_OBS_TYP_CONICAL_BARREL,
  DISP_OBS_TYP_WATERHORSE,
  DISP_OBS_TYP_TRIANGLE,
  DISP_OBS_TYP_SUSPENSION,
  DISP_OBS_TYP_PARKINGLEVER,
  DISP_OBS_TYP_DECELERAZONE,
  DISP_OBS_TYP_COLUMN,
  DISP_OBS_TYP_REFLECT_COLUMN,
  DISP_OBS_TYP_FLOOR_LOCK_OPEN,
  DISP_OBS_TYP_FLOOR_LOCK_OFF,
  DISP_OBS_TYP_WHEEL_CHOCK
}

tDispObsType;

typedef struct
{
  real32_T SlotX0;
  real32_T SlotY0;
  real32_T SlotX1;
  real32_T SlotY1;
  real32_T SlotX2;
  real32_T SlotY2;
  real32_T SlotX3;
  real32_T SlotY3;
  tDispSlotStatus eDispSlotStatus;
  tDispSlotType eDispSlotType;
  tDispSlotSubType eDispSlotSubType;
  uint8_T u8SlotID;
  uint8_T u8SlotConfidence;
  uint8_T u8ParkFrontRear;
  uint8_T u8Res1;
}

tSlotDisp;

typedef struct
{
  real32_T ObsX;
  real32_T ObsY;
  real32_T ObsDis;
  tDispObsType eDispObsType;
  uint8_T u8ObsID;
  uint8_T u8Res3[3];
}

tObsDisp;

typedef enum
{
  DRIVER_NO_REQ = 0,                   /* Default value */
  DRIVER_SLOW_DOWN,
  DRIVER_SEARCH_PS,
  DRIVER_STOP_TO_SELECT_PS,
  DRIVER_PRESS_DMS_TO_START,
  DRIVER_SELECT_PS_AND_CONFIRM,
  DRIVER_SELECT_VIR_PS_TYPE,
  DRIVER_ADJUST_VIR_PS,
  DRIVER_CONFIRM_VIR_PS,
  DRIVER_SELECT_DIR_W_PS_TYPE,
  DRIVER_CONFIRM_DIR,
  DRIVER_WAIT_PATH_PLAN,
  DRIVER_WAIT_HANDSHAKE,
  DRIVER_RELEASE_CONTROL,
  DRIVER_MONITOR_APA_PARKING,
  DRIVER_RESOLVE_SUSPENSION,
  DRIVER_CONFIRM_RECOVERY,
  DRIVER_WAIT_CTROL_HANDOVER,
  DRIVER_TAKEOVER,
  DRIVER_PREPARE_RPA,
  DRIVER_MONITOR_RPA_PARKING,
  DRIVER_CLOSE_DOOR,
  DRIVER_MANUAL_PARK_OUT
}

tDriverRequest;

typedef enum
{
  SLOT_UNDECID = 0,                    /* Default value */
  SLOT_AVALIABLE,
  SLOT_NOT_AVALIABLE
}

tSlotAvaliab;

typedef enum
{
  PI_SLOT_TYPE_NONE = 0,               /* Default value */
  PI_SLOT_TYPE_PARALLEL,
  PI_SLOT_TYPE_PERPENDI,
  PI_SLOT_TYPE_OBLIQUE
}

tPISlotType;

typedef enum
{
  PI_DIR_NO_REQ = 0,                   /* Default value */
  PI_DIR_LEFT,
  PI_DIR_STRAIGHT,
  PI_DIR_RIGHT
}

tPIDir;

typedef struct
{
  tSlotDisp sSlotGroup[12];
  tObsDisp sObsGroup[12];
}

tFusionDisp;

typedef struct
{
  real32_T PAGuideLineA;
  real32_T PAGuideLineB;
  real32_T PAGuideLineC;
  real32_T PAGuideLineD;
  real32_T PAGuideLineXMin;
  real32_T PAGuideLineXMax;
  real32_T PISlotLength;
  tDriverRequest eDriverRequest;
  tSlotAvaliab eSlotAvaliab;
  tPISlotType ePISlotType;
  tPIDir ePIDir;
  boolean_T bHeadParkIn;
  uint8_T u8aParkBarPercent;
  uint8_T u8DrvrSelSlotID;
  uint8_T u8Res;
}

tHMIComDisp;

#endif                                 /* RTW_HEADER_hmi_interactive_type_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
