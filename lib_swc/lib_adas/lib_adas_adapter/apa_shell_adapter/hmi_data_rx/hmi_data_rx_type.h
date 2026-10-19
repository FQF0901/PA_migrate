/*
 * File: hmi_data_rx_type.h
 *
 * Code generated for Simulink model 'lsad_fsm_adapter'.
 *
 * Model version                  : 1.132
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Fri Nov 29 10:41:26 2024
 */

#ifndef RTW_HEADER_hmi_data_rx_type_h_
#define RTW_HEADER_hmi_data_rx_type_h_
#include "rtwtypes.h"

typedef enum
{
  SWT_NO_REQ = 0,                      /* Default value */
  SWT_ON,
  SWT_OFF
}

tTriStateSwt;

typedef enum
{
  PRK_TYP_NO_REQ = 0,                  /* Default value */
  PRK_IN,
  PRK_OUT,
  PRK_DRAG,
  PRK_STRAIGHT
}

tPrkTypReq;

typedef enum
{
  SLOT_TYP_NO_REQ = 0,                 /* Default value */
  SLOT_TYP_PARALLEL,
  SLOT_TYP_PERPENDI,
  SLOT_TYP_OBLIQUE
}

tSlotTyp;

typedef enum
{
  PRK_OUT_DIR_NO_REQ = 0,              /* Default value */
  PRK_HEAD_OUT_DIR_LEFT,
  PRK_HEAD_OUT_DIR_STRAIGHT,
  PRK_HEAD_OUT_DIR_RIGHT,
  PRK_TAIL_OUT_DIR_LEFT,
  PRK_TAIL_OUT_DIR_STRAIGHT,
  PRK_TAIL_OUT_DIR_RIGHT
}

tPrkoutDir;

typedef enum
{
  PRK_OUT_HEAD_TAIL_NO_REQ = 0,        /* Default value */
  PRK_HEAD_OUT_REQ,
  PRK_TAIL_OUT_REQ
}

tPOHeadTailReq;

typedef enum
{
  PRK_SLOT_NO_REQ = 0,                 /* Default value */
  PRK_SLOT_ID0,
  PRK_SLOT_ID1,
  PRK_SLOT_ID2,
  PRK_SLOT_ID3,
  PRK_SLOT_ID4,
  PRK_SLOT_ID5,
  PRK_SLOT_ID6,
  PRK_SLOT_ID7,
  PRK_SLOT_ID8,
  PRK_SLOT_ID9,
  PRK_SLOT_ID10,
  PRK_SLOT_ID11,
  PRK_SLOT_ID12
}

tPrkSlotIDReq;

typedef enum
{
  PRK_WORK_NO_REQ = 0,                 /* Default value */
  PRK_WORK_START,
  PRK_WORK_PAUSE,
  PRK_WORK_CONTINUE,
  PRK_WORK_EXIT
}

tPrkWorkMd;

typedef enum
{
  BLE_CONNECT_INITIAL_VALUE = 0,       /* Default value */
  BLE_CONNECT_NOT,
  BLE_CONNECT
}

tBLEConnectSts;

typedef enum
{
  BLE_SECURITY_INITIAL_VALUE = 0,      /* Default value */
  BLE_SECURITY_NOT,
  BLE_SECURITY
}

tBLEScrtSts;

typedef enum
{
  REMOTR_NOT_SELECT = 0,               /* Default value */
  RemoteInt_60s_HangUp_Phone,
  RemoteInt_60s_Return
}

tRemoteIntModSel;

typedef enum
{
  RCA_PRK_DEAFAULT = 0,                /* Default value */
  RCA_PRK_AHEAD,
  RCA_PRK_BACK,
  RCA_PRK_LEFT,
  RCA_PRK_RIGHT,
  RCA_PRK_NO_REQ
}

tRCAPrkDircMd;

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

tDragPrkSlot;

typedef struct
{
  tTriStateSwt eAPAPrkWakeup;
  tPrkTypReq eAPAPrkTypReq;
  tSlotTyp eAPAPrkSlotType;
  tPrkoutDir eAPAPrkOutDir;
  tPOHeadTailReq ePOHeadTailReq;
  tPrkSlotIDReq eAPAPrkSlotIDReq;
  tSlotTyp eAPASelfPrkType;
  tPrkWorkMd eAPAPrkWorkMd;
  tTriStateSwt eIgoPA;
  boolean_T bLocaPrkArea;
  boolean_T bEolReq;
  uint8_T u8Res[2];
}

tAPAHmiRx;

typedef struct
{
  tTriStateSwt eRPAPrkWakeup;
  tTriStateSwt eRPAIHUReq;
  tPrkTypReq eRPAPrkTypReq;
  tSlotTyp eRPAPrkSlotType;
  tPrkoutDir eRPAPrkOutDir;
  tPrkSlotIDReq eRPAPrkSlotIDReq;
  tSlotTyp eRPASelfPrkTyp;
  tPrkWorkMd eRPAPrkWorkMd;
  tBLEConnectSts eBLEConnectSts;
  tBLEScrtSts eBLEScrtSts;
  tRemoteIntModSel eRemoteIntModSel;
  boolean_T bRPAFixSlot;
  boolean_T bPhoneBatLow;
  uint8_T u8Res[2];
}

tRPAHmiRx;

typedef struct
{
  tRCAPrkDircMd eRCAPrkDircMd;
  tPrkWorkMd eRCAPrkWorkMd;
  boolean_T bSecureSK2RCA;
  uint8_T u8Res[3];
}

tRCAHmiRx;

typedef struct
{
  tDragPrkSlot sAPADragPrkSlot;
  tDragPrkSlot sRPADragPrkSlot;
  tAPAHmiRx sAPAHmiRx;
  tRPAHmiRx sRPAHmiRx;
  tRCAHmiRx sRCAHmiRx;
}

tPAHmiRx;

typedef struct
{
  tPrkWorkMd eRAPrkWorkMd;
}

tRAHmiRx;

typedef struct
{
  tPrkWorkMd eHPAPrkWorkMd;
}

tHPAHmiRx;

#endif                                 /* RTW_HEADER_hmi_data_rx_type_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
