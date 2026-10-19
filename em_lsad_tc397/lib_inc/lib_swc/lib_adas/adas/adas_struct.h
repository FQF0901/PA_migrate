#ifndef LIB_SWC_ADAS_STRUCT_H_
#define LIB_SWC_ADAS_STRUCT_H_

#include <stdint.h>
#include "Platform_Types.h"
#include "rtwtypes.h"
// #include "vehicle_service_type.h"
//#include "vehicle.h"

typedef uint16 EM_ADAS_ReturnType;

typedef struct _LPF_ADAS_
{
    float f32LPF_den_2;
    float f32LPF_num_1;
    float f32LPF_num_2;
    float f32LPF_filter_yk_1;
    float f32LPF_filter_yk;
    float f32LPF_yk;
    float f32LPF_yk_1;
}tLowPassFilterPara;

typedef enum _ADAS_RETURN_CODE
{
    ADAS_RETURN_OK = 0,
    ADAS_RETURN_ERROR = 1
}EAdasReturnCode;

typedef enum{
    NONE_GEAR  =   0,
    R_GEAR     =   1,
    N_GEAR     =   2,
    D_GEAR     =   3,
    P_GEAR     =   5
}tVehActualGear;
typedef enum _ttCtrlFailReason
{
  CTRL_FAIL_NO =0,
  CTRL_FAIL_ROLL_BACK =1,
  CTRL_FAIL_LONG_STOP =2,
  CTRL_PLAN_FAIL_TRAP =5,
  CTRL_FINISH_CHOCK =10,
  CTRL_PLAN_FINISH_STOP_NEAR_END =30

}tCtrlFailReason;
typedef struct _tAPA_CtrlReqStatus
{
    tCtrlFailReason eCtrlFailReason; 
    uint8   u8ReqPause;
    uint8   u8Res[3];
} tAPA_CtrlReqStatus;

// typedef struct _CTRL2VEHSRV_STATE_INFO
// {
//     tVehi_VehicleDataTx g_stCtrlOutputPara;

//     uint8         res_sts[16];   //for vs receive ctrl sts
//     float         res_val[5];    //for vs receive other para
// }tCtrl2Vehsrv;

typedef struct _VEHSRV2CTRL_STATE_INFO
{
    uint8         res_sts[12];    //for ctrl receive vs sts
    float         res_val[10];    //for ctrl receive calib data
}tVehsrv2Ctrl;



typedef enum
{
  SYS_PWR_MD_OFF = 0,                  /* Default value */
  SYS_PWR_MD_ACC,
  SYS_PWR_MD_RUN,
  SYS_PWR_MD_CRANK
}
tSysPwrMd;
typedef enum
{
  WHLSPD_INVALID = 0,                  /* Default value */
  WHLSPD_FORWARD,
  WHLSPD_BACKWARD,
  WHLSPD_STANDSTILL
}
tWhlSpdDir;
typedef enum
{
  PA_CTRL_STS_OFF = 0,                     /* Default value */
  PA_CTRL_STS_READY,
  PA_CTRL_STS_SPEED_CTRL,
  PA_CTRL_STS_STOP_CTRL,
  PA_CTRL_STS_STANDSTILL,
  PA_CTRL_STS_IDB_FAIL,
  PA_CTRL_STS_IDB_EMERGENCY_STOP
}
tPACtrlSts;
typedef enum
{
  EPB_UNKNOWN = 0,                     /* Default value */
  EPB_RELEASED,
  EPB_CLAMPED,
  EPB_CLAMPING,
  EPB_RELEASING,
  EPB_INVALID
}
tEPBStatus;
typedef enum
{
  ESC_STS_OFF = 0,                 /* Default value */
  ESC_STS_READY,
  ESC_SPEED_CTRL,
  ESC_STS_STOP_CTRL,
  ESC_STS_STANDSTILL,
  ESC_STS_FAIL,
  ESC_STS_EMERGENCY_STOP
}
tESCStatus;
typedef enum
{
  AVH_INACTIVE = 0,                    /* Default value */
  AVH_ACTIVE,
  AVH_RELEASED
}
tAVHStatus;
typedef enum
{
  DOOR_INVALID = 0,                    /* Default value */
  DOOR_AJAR,
  DOOR_INAJAR
}
tAjarDrSts;
typedef enum
{
  SEATBLT_INVALID = 0,                 /* Default value */
  SEATBLT_ACTIVE,
  SEATBLT_INACTIVE
}
tSeatbltSts;
typedef enum
{
  TYRE_SYSTEM_NORMAL = 0,              /* Default value */
  TYRE_SYSTEM_ERROR,
  TYRE_SYSTEM_WAIT_LEARN
}
tTyreWrnSts;
typedef enum
{
  TURN_OFF = 0,                        /* Default value */
  TURN_LEFT,
  TURN_RIGHT
}
tTurnLight;
typedef enum
{
  TURN_LIGHT_INACTIVE = 0,             /* Default value */
  TURN_LIGHT_ACTIVE,
  TURN_LIGHT_FAILED
}
tTurnLightSts;
typedef struct
{
  float f32MotorTq;
  float f32MotorSpeed;
  tSysPwrMd eSysPwrMd;
  tVehActualGear eVehActualGear;
  uint8   u8AccPedalPos;
  boolean bAccPedal;
  boolean bBrkPedal;
  boolean bShftInterf;
  boolean bHVOff;
  boolean bUnExpGear;
  boolean bVehBlock;
  uint8   u8Res;
}
tVehVCUInfo;
typedef struct
{
  float f32VehSpdKph;
  float f32VehSpdMps;
  float f32WhlSpdFLKph;
  float f32WhlSpdFRKph;
  float f32WhlSpdRLKph;
  float f32WhlSpdRRKph;
  float f32MasterCylPres;
  float f32VehSpdImp;
  float f32VehSpdImpFiltered;
  tLowPassFilterPara stVehSpdImpLPF;
  tWhlSpdDir eWhlDirFL;
  tWhlSpdDir eWhlDirFR;
  tWhlSpdDir eWhlDirRL;
  tWhlSpdDir eWhlDirRR;
  tPACtrlSts ePACtrlSts;
  tEPBStatus eEPBStatus;
  tESCStatus eESCStatus;
  tAVHStatus eAVHStatus;
  uint16   u16WhlPulFL;
  uint16   u16WhlPulFR;
  uint16   u16WhlPulRL;
  uint16   u16WhlPulRR;
  boolean bVehStandStill;
  boolean bEPBInterf;
  boolean bAVHEnabled;
  boolean bDAActive;    //
  boolean bASActive;    //
}
tVehESCInfo;
typedef struct
{
  float f32StrWhlAngDeg;
  float f32StrWhlAngRad;
  float f32StrWhlAngSpdDeg;
  float f32StrWhlAngSpdRad;
  float f32EPSMotTq;
  boolean bEpsInterf;
  boolean bEPSCalib;
  uint8   u8Res2[2];
}
tVehEPSInfo;
typedef struct
{
  float f32VehYawRateRad;
  float f32VehYawRateDeg;
  float f32LongAcc;
}
tVehACUInfo;
typedef struct
{
  tAjarDrSts eAjarDrFLSts;
  tAjarDrSts eAjarDrFRSts;
  tAjarDrSts eAjarDrRLSts;
  tAjarDrSts eAjarDrRRSts;
  tAjarDrSts eAjarHoodSts;
  tAjarDrSts eAjarTailGateSts;
  tSeatbltSts eDrvSeatbltSts;
  tSeatbltSts ePsrSeatbltSts;
  tTyreWrnSts eTyreWrnSts;
  tTurnLight eTurnLight;
  tTurnLightSts eLeftTurnLightSts;
  tTurnLightSts eRightTurnLightSts;
  boolean bTrlerAttchStsOn;
  boolean bMirrFld;
  uint8   u8Res2[2];
}
tVehBCMInfo;
typedef struct
{
  boolean bBrakingFail;
  boolean bTractionFail;
  boolean bSteeringFail;
  boolean bSignalInvalid;
  boolean bSigValErr;
  uint8   u8Res3[3];
}
tExtCdtnMiss;
typedef struct
{
  tVehVCUInfo sVehVCUInfo;
  tVehESCInfo sVehESCInfo;
  tVehEPSInfo sVehEPSInfo;
  tVehACUInfo sVehACUInfo;
  tVehBCMInfo sVehBCMInfo;
  tExtCdtnMiss sExtCdtnMiss;
}
tVehDataRx;
typedef enum
{
  HANDSHAKE_TYPE_NONE = 0,   
  HANDSHAKE_LOW_SPEED = 1,
  HANDSHAKE_HIGH_SPEED = 2,
}
tHandshakeType;
typedef enum
{
  NO_FAILCODE = 0,                     /* Default value */
  EPS_RESPONSE_OVERTIME,
  ESC_RESPONSE_OVERTIME,
  IDB_RESPONSE_OVERTIME,
  VCU_RESPONSE_OVERTIME,
  EPS_FAIL,
  ESC_FAIL,
  IDB_FAIL,
  VCU_FAIL,
  EPS_COMM_FAIL,
  ESC_COMM_FAIL,
  IDB_COMM_FAIL,
  VCU_COMM_FAIL,
  EPS_OFF,
  ESC_OFF,
  IDB_OFF,
  VCU_OFF,
  EPS_STEER_INTERFACE,
  EPS_ANGEL_DEVATION,
  ESC_GEAR_INTERFACE,
  ESC_GEAR_UNEXPECTED,
  ESC_EPB_UNEXPECTED,
  EPB_RELEASE_OVERTIME,
  EPB_CLAMP_OVERTIME,
  ESC_VEH_BLOCKED,
  EPS_OVERSPEED,
  EPS_ABNORM_CAN_INPUT,
  PA_FAIL,
  PLSBLTY_CHCK_FAIL,
  EXT_SYS_FAULT
}
tHandshakeFailReason;
typedef enum
{
  HANDSHAKE_UNCONTROLLED = 0,          /* Default value */
  HANDSHAKE_START,
  HANDSHAKE_SUCCESS,
  HANDSHAKE_CONTROLLED,
  HANDSHAKE_RELEASING,
  HANDSHAKE_ABORT,
  HANDSHAKE_FAIL
}
tHandshakeSts;
typedef struct
{
  tHandshakeType eHandshakeType;
  tHandshakeFailReason eHandshakeFailReason;
  tHandshakeSts eHandshakeSts;
}
tHandshakeManager;

typedef struct
{
  boolean_T bSysVoltFail;
  boolean_T bSocFail;
  boolean_T bMcuFail;
  boolean_T bSysTempFail;
  boolean_T bSysCommFail;
  boolean_T bHwFail;
  uint8_T u8Res2[2];
}

tHwFail;

typedef struct
{
  boolean_T bUsSrvcFail;
  boolean_T bUsAlgoFail;
  boolean_T bUsDriverFail;
  boolean_T bUsPwrFail;
  boolean_T bUssFail;
  uint8_T u8Res3[3];
}

tUssFail;

typedef struct
{
  boolean_T bCamFail;
  boolean_T bCamSysFail;
  boolean_T bCvAlgoFail;
  boolean_T bEolFail;
  boolean_T bVisionFail;
  uint8_T u8Res3[3];
}

tVisionFail;

typedef struct
{
  boolean_T bAppFail;
  uint8_T u8Res3[3];
}

tAPPFail;

typedef struct
{
  boolean_T bCanFail;
  boolean_T bADUComFail;
  boolean_T bESCComFail;
  boolean_T bSCUComFail;
  boolean_T bEPSComFail;
  boolean_T bFICMComFail;
  boolean_T bECMComFail;
  boolean_T bBCMComFail;
  boolean_T bICGMComFail;
  boolean_T bACComFail;
  boolean_T bEthFail;
  boolean_T bComFail;
}

tComFail;

typedef struct
{
  tHwFail sHwFail;
  tUssFail sUssFail;
  tVisionFail sVisionFail;
  tAPPFail sAPPFail;
  tComFail sComFail;
  boolean_T bPASysFail;
  boolean_T bCameraSrvFail;
  boolean_T bPlfmFail;
  boolean_T bTsSrvFail;
  boolean_T bMcuBswFail;
  boolean_T bMcuLogFail;
  boolean_T bUssFail;
  boolean_T bVisionFail;
}

tDiagInfo;

/***** em_interchip_msg end *****/

#endif //LIB_SWC_ADAS_STRUCT_H_
