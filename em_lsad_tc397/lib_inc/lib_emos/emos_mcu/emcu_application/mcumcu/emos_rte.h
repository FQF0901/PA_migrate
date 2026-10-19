#ifndef _EMOS_RTE_HEADER_
#define _EMOS_RTE_HEADER_

#include <stdbool.h>
#include "Platform_Types.h"

#include <stdint.h>
#include "s2s_com.h"
#include "emos_mcu_mcuinfo.h"
#include "Std_Types.h"
#include "common.h"

#define EMOS_MCU_TIMER_SYNC_RESERVEDPORT 254  
typedef struct _tEmosTimerSync
{
    tUInt64 Timestamp;
	tUInt64 seq;
	tUInt64 sigDelay;//1--248
	tUInt32 sigDrop;//1--248
	tUInt32 dropCnt;
	tUInt32 delayCnt;
	tUInt32 portID;
}EmosTimerSync;

#ifndef DEFINED_TYPEDEF_FOR_TimestampType_
#define DEFINED_TYPEDEF_FOR_TimestampType_
/* Unit(us),200k years + */
#endif

/* test enum should be set as 4-byte length, use --integration-enumeration please */
typedef enum tTest_Enum
{
    TEST_ENUM_0 = 0,
}Test_Enum;

#define TEST_CHECK_ENUM_SIZE    ((sizeof(Test_Enum)) != (sizeof(int)) ? -1 : 1)
#define TEST_CHECK_SHORT_SIZE    ((sizeof(short)) != 2 ? -1 : 1)
#define TEST_CHECK_INT_SIZE    ((sizeof(int)) != 4 ? -1 : 1)
#define TEST_CHECK_LLONG_SIZE    ((sizeof(long long)) != 8 ? -1 : 1)
typedef struct _tTestStruct
{
    unsigned char data_a:TEST_CHECK_ENUM_SIZE;
    unsigned char data_b:TEST_CHECK_SHORT_SIZE;
    unsigned char data_c:TEST_CHECK_INT_SIZE;
    unsigned char data_d:TEST_CHECK_LLONG_SIZE;
}TestStruct;

typedef int (*MsgPreOperation)(void *pData);

#define VEHI_TYPE_ERR -1
#define VEHI_TYPE_UNKNOWN 0
#define VEHI_TYPE_MCE 1  // Marvel R (MCE)
#define VEHI_TYPE_NL5 2  // Geely (NL-5)
#define VEHI_TYPE_DESKTOP 3
#define VEHI_TYPE_HAN 4  // BYD汉
#define VEHI_TYPE_MIFA 5  // MIFA
#define VEHI_TYPE_EP31 6  // Hozon EP31
#define VEHI_TYPE_EP40 7  // Hozon EP40
#define VEHI_TYPE_EP36 8  // Hozon EP36
#define VEHI_TYPE_EP32 9  // Hozon EP32
#define VEHI_TYPE_EP37 10  // Hozon EP37
#define VEHI_TYPE_EV52 11  // Hozon EV52
#define VEHI_TYPE_JX65 12  // 星宇 JX65
#define VEHI_TYPE_HAOMO 13  // 毫末
#define VEHI_TYPE_BICV 14  // 北斗
#define VEHI_TYPE_EP41 15  // Hozon EP41
#define VEHI_TYPE_EP36_M01 16  // Hozon EP36 M01
#define VEHI_TYPE_PC 99
#define PLD_NUM_MAX_VPLD 20U  // max number of vision PLD index
#define PLD_NUM_MAX_UPLD 10U  // max number of ultrasonic PLD index
#define PLD_NUM_MAX_DF_DRAW 20U  // max number of data fusion draw index
#define OD_NUM_MAX 50U  // max number of object detection index
#define FS_BOUND_NUM_MAX 160U  // max number of free space boundary index
#define USH_ONE_SND_MULT_RCV_MAX 3U  // one send multiple receive max
#define USH_ECHO_NUM_MAX 5U  // 5 echoes
#define PDC_ZONE_NUM 20U  // number of PDC warnning zone, side(1*4)+R/F(8*2)
#define PEB_ZONE_NUM 92U  // number of PEB warnning zone, side(5*4)+R/F(36*2)
#define MEB_ZONE_NUM 100U  // number of MEB warnning zone, side(5*4)+R/F(40*2)
#define SOC_US_PLD_NUM_MAX_UPLD 10U  // max number of ultrasonic PLD index
#define SOC_US_OD_NUM_MAX 50U  // max number of object detection index
#define SOC_US_FS_BOUND_NUM_MAX 512U  // max number of free space boundary index
#define SOC_US_PDC_ZONE_NUM 20U  // number of PDC warnning zone


typedef float float32_t;
typedef double float64_t;
typedef int32_t tVehi_VehiType;
typedef float32_t tUSH_Temperature_degC;
typedef enum _ttAdasLogNumber
{
	LOG_APA_SHELL_STATUS = 0,
	LOG_APA_SHELL_PARK_TYPE,
	LOG_ACTUAL_WHEEL_ANGLE,
	LOG_ACTUAL_VEH_SPD,
	LOG_RR_WHEEL_IMPULSE,
	LOG_RL_WHEEL_IMPULSE = 5,
	LOG_RR_WHEEL_DIR,
	LOG_RL_WHEEL_DIR,
	LOG_ACTUAL_VEH_GEAR,
	LOG_CHASSIS_STATUS,
	LOG_TOTAL_PATH_NUM = 10,
	LOG_PATH_ID,
	LOG_TOTAL_POINT_NUM,
	LOG_SHIFT_GEAR_REQUEST,
	LOG_WAY_POINT_DISTANCE,
	LOG_PLD_TYPE = 15,
	LOG_PATH_VALID_FLAG,
	LOG_PATH_LENGTH_TYPE,
	LOG_REPLAN_FLAG,
	LOG_USS_SLOT_FLAG,
	LOG_CUR_PATH_TOTAL_DISTANCE = 20,
	LOG_WAY_POINT_X_FIRST,
	LOG_WAY_POINT_Y_FIRST,
	LOG_WAY_POINT_THETA_FIRST,
	LOG_WAY_POINT_X_LAST,
	LOG_WAY_POINT_Y_LAST = 25,
	LOG_WAY_POINT_THETA_LAST,
	LOG_DR_CURRENT_X,
	LOG_DR_CURRENT_Y,
	LOG_DR_CURRENT_THETA,
	LOG_CTRL_FUNC_STATUS = 30,
	LOG_CTRL_FUNC_TYPE,
	LOG_NEAREST_PATH_POINT_ID,
	LOG_DISTANCE_LEFT,
	LOG_PEB_FLAG,
	LOG_CTRL_ERR_CODE = 35,
	LOG_SPEED_PHASE = 40,
	LOG_TARGET_SPEED,
	LOG_PEB_SPEED_LIMIT,
	LOG_TARGET_ACCE,
	LOG_LQR_DIST_ERR = 50,
	LOG_LQR_THETA_ERR,
	LOG_FEEDBACK_ANGLE_RAW,
	LOG_FEEDBACK_ANGLE_FILTERED,
	LOG_SINGLE_POINT_TARGET_KAPPA,
	LOG_SINGLE_POINT_FEEDFORWARD_ANGLE = 55,
	LOG_MULTI_POINT_TARGET_KAPPA,
	LOG_MULTI_POINT_FEEDFORWARD_ANGLE,
	LOG_TARGET_STEER_ANGLE_RAW,
	LOG_TARGET_STEER_ANGLE_FILTERED,
	LOG_REQ_GEAR = 60,
	LOG_REQ_SPEED,
	LOG_REQ_ACCEL,
	LOG_REQ_STEER,
	LOG_REQ_STOP_DISTANCE,
	LOG_REQ_PATH_ID = 65,
	LOG_REQ_REPLAN,
	LOG_REQ_REPLAN_TYPE,
	LOG_CTRL_STATUS,
	LOG_REQ_PAUSE,
	LOG_ADAS_DEBUG_NUM = 200
	
}tAdasLogNumber;
typedef enum _ttSelfcheckSts
{
	SELFCHECK_UNFINISHED = 0,
	SELFCHECK_FINISHED,
	SELFCHECK_FAILURE
	
}tSelfcheckSts;
typedef enum _ttNormalSts
{
	NORMAL = 0,
	ABNORMAL
	
}tNormalSts;
typedef enum _ttEnableSts
{
	DISABLE = 0,
	ENABLE
	
}tEnableSts;
typedef enum _ttDoorSts
{
	DOOR_CLOSED = 0,
	DOOR_OPENED
	
}tDoorSts;
typedef enum _ttKeyPosition
{
	KEY_POS_OFF = 0,
	KEY_POS_ACC,
	KEY_POS_ON,
	KEY_POS_START
	
}tKeyPosition;
typedef enum _ttFaultSts
{
	NO_FAULT,
	FAULT
	
}tFaultSts;
typedef enum _ttValidity
{
	VALID,
	INVALID
	
}tValidity;
typedef enum _ttConnectSts
{
	DISCONNECTED,
	CONNECTED
	
}tConnectSts;
typedef enum _ttWorkSts
{
	NOT_WORK,
	WORK
	
}tWorkSts;
typedef enum _ttRequest
{
	NO_REQUEST,
	REQUEST
	
}tRequest;
typedef enum _ttAllowSts
{
	NOT_ALLOWED,
	ALLOWED
	
}tAllowSts;
typedef enum _ttSatisfiedSts
{
	UNSATISFIED,
	SATISFIED
	
}tSatisfiedSts;
typedef enum _ttSupportSts
{
	NOT_SUPPORT,
	SUPPORT
	
}tSupportSts;
typedef enum _ttActiveSts
{
	NOT_ACTIVED,
	ACTIVED
	
}tActiveSts;
typedef enum _ttParkSts
{
	NOT_PARKED,
	PARKED
	
}tParkSts;
typedef enum _ttLockSts
{
	UNLOCKED,
	LOCKED
	
}tLockSts;
typedef enum _ttFinishSts
{
	NOT_FINISHED,
	FINISHED
	
}tFinishSts;
typedef enum _ttExecutionSts
{
	EXECUTION_NONE,
	EXECUTION_FAILURE,
	EXECUTING,
	EXECUTION_DONE
	
}tExecutionSts;
typedef enum _ttAvailable
{
	NOT_AVAILABLE,
	AVAILABLE
	
}tAvailable;
typedef enum _ttWheelDirection
{
	WHEEL_DIR_STANDSTILL = 0,
	WHEEL_DIR_FORWARD,
	WHEEL_DIR_BACKWARD,
	WHEEL_DIR_INVALID
	
}tWheelDirection;
typedef enum _ttVehiGear
{
	VEHI_GEAR_P,
	VEHI_GEAR_R,
	VEHI_GEAR_N,
	VEHI_GEAR_D,
	VEHI_GEAR_INVALID
	
}tVehiGear;
typedef enum _ttDriveMode
{
	DRIVE_MODE_STANDARD = 0,
	DRIVE_MODE_COMFORT = 1,
	DRIVE_MODE_SPORT = 2,
	DRIVE_MODE_ECONOMIC = 3,
	DRIVE_MODE_OFF_ROAD = 4
	
}tDriveMode;
typedef enum _ttSeatBeltSts
{
	SEAT_BELT_BUCKLE = 0,
	SEAT_BELT_FAULT = 1,
	SEAT_BELT_UNBUCKLE = 2,
	SEAT_BELT_NOT_USED = 3
	
}tSeatBeltSts;
typedef enum _ttAEBMode
{
	AEB_MODE_OFF = 0,
	AEB_MODE_ON = 1,
	AEB_MODE_STANDBY = 2,
	AEB_MODE_ACTIVE = 3
	
}tAEBMode;
typedef enum _ttAPA_UssMode
{
	USS_MODE_STANDBY = 0,
	USS_MODE_FAILURE,
	USS_MODE_APA,
	USS_MODE_RPA,
	USS_MODE_HPA
	
}tAPA_UssMode;
typedef enum _ttLSAD_SystemSts
{
	LSAD_STS_OFF = 0,
	LSAD_STS_STANDBY,
	LSAD_STS_PREPARE,
	LSAD_STS_PREPARE_SUSPEND,
	LSAD_STS_HANDSHAKE,
	LSAD_STS_PP,
	LSAD_STS_ACTIVE,
	LSAD_STS_ACTIVE_SUSPEND,
	LSAD_STS_QUIT,
	LSAD_STS_COMPLETE,
	LSAD_STS_TERMINATED,
	LSAD_STS_FAILURE = 20,
	LSAD_STS_INHIBIT
	
}tLSAD_SystemSts;
typedef enum _ttLSAD_SystemSubSts
{
	LSAD_SUBSTS_NONE = 0,
	LSAD_SUBSTS_STANDBY = 10,
	LSAD_SUBSTS_PARKREADY = 11,
	LSAD_SUBSTS_CRUISEREADY = 12,
	LSAD_SUBSTS_CRUISEREADY_PARKREADY = 13
	
}tLSAD_SystemSubSts;
typedef enum _ttLSAD_FuncType
{
	LSAD_FUNC_TYPE_NONE = 0,
	LSAD_PARK_IN,
	LSAD_PARK_OUT,
	LSAD_PARK_STRAIGHT,
	LSAD_CRUISE,
	LSAD_RA,
	LSAD_DRAG_PARK_IN,
	LSAD_EOL = 10
	
}tLSAD_FuncType;
typedef enum _ttLSAD_DriverCtrlCommand
{
	DRIVER_CTRL_NONE = 0,
	DRIVER_CTRL_PARKIN_TAILIN = 10,
	DRIVER_CTRL_PARKIN_HEADIN,
	DRIVER_CTRL_PARKOUT_PP_LEFT = 20,
	DRIVER_CTRL_PARKOUT_PP_MIDDLE,
	DRIVER_CTRL_PARKOUT_PP_RIGHT,
	DRIVER_CTRL_PARKOUT_NOPP_LEFT,
	DRIVER_CTRL_PARKOUT_NOPP_MIDDLE,
	DRIVER_CTRL_PARKOUT_NOPP_RIGHT,
	DRIVER_CTRL_STRAIGHT_STOP = 30,
	DRIVER_CTRL_STRAIGHT_FORWARD,
	DRIVER_CTRL_STRAIGHT_BACKWARD,
	DRIVER_CTRL_STRAIGHT_FINISH,
	DRIVER_CTRL_MAP_CREATE_START = 40,
	DRIVER_CTRL_MAP_CREATE_END,
	DRIVER_CTRL_MAP_CREATE_SAVE,
	DRIVER_CTRL_MAP_CREATE_DISCARD,
	DRIVER_CTRL_PKOUT_FRONT_LEFT = 50,
	DRIVER_CTRL_PKOUT_FRONT_MIDDLE,
	DRIVER_CTRL_PKOUT_FRONT_RIGHT,
	DRIVER_CTRL_PKOUT_REAR_LEFT,
	DRIVER_CTRL_PKOUT_REAR_MIDDLE,
	DRIVER_CTRL_PKOUT_REAR_RIGHT,
	DRIVER_CTRL_PKOUT_SIDE_LEFT,
	DRIVER_CTRL_PKOUT_SIDE_RIGHT
	
}tLSAD_DriverCtrlCommand;
typedef enum _ttHmiStsReq
{
	HMI_STS_NONE = 0,
	HMI_STS_CANCEL,
	HMI_STS_GO_STRAIGHT,
	HMI_STS_SCENARIO_SELECT,
	HMI_STS_PARKIN_SEARCH = 10,
	HMI_STS_PARKIN_START,
	HMI_STS_PARKIN_SUSPEND,
	HMI_STS_PARKIN_CONTINUE,
	HMI_STS_PARKOUT_START = 20,
	HMI_STS_PARKOUT_SUSPEND,
	HMI_STS_PARKOUT_CONTINUE,
	HMI_STS_CRUISING_START = 30,
	HMI_STS_CRUISING_SUSPEND,
	HMI_STS_CRUISING_CONTINUE,
	HMI_STS_RA_START = 40,
	HMI_STS_RA_SUSPEND,
	HMI_STS_RA_CONTINUE,
	HMI_STS_MEB_DISABLE = 50,
	HMI_STS_MEB_ENABLE,
	HMI_STS_MAP_START = 100,
	HMI_STS_MAP_SAVE,
	HMI_STS_MAP_DISCARD,
	HMI_STS_EOL_START = 110,
	HMI_STS_PARKIN_DRAG_SEARCH = 150
	
}tHmiStsReq;
typedef enum _ttHmiTypeReq
{
	HMI_TYPE_NONE = 0,
	HMI_TYPE_PKOUT_WAIT,
	HMI_TYPE_PKOUT_PP_LEFT,
	HMI_TYPE_PKOUT_PP_RIGHT,
	HMI_TYPE_PKOUT_PP_MIDDLE,
	HMI_TYPE_GO_STRAIGHT_FORWARD,
	HMI_TYPE_GO_STRAIGHT_BACKWARD,
	HMI_TYPE_PKOUT_NOPP_LEFT,
	HMI_TYPE_PKOUT_NOPP_RIGHT,
	HMI_TYPE_PKOUT_NOPP_MIDDLE,
	HMI_TYPE_PKIN_AUTO_SEARCH = 30,
	HMI_TYPE_PKOUT_FRONT_LEFT = 50,
	HMI_TYPE_PKOUT_FRONT_MIDDLE,
	HMI_TYPE_PKOUT_FRONT_RIGHT,
	HMI_TYPE_PKOUT_REAR_LEFT,
	HMI_TYPE_PKOUT_REAR_MIDDLE,
	HMI_TYPE_PKOUT_REAR_RIGHT,
	HMI_TYPE_PKOUT_SIDE_LEFT,
	HMI_TYPE_PKOUT_SIDE_RIGHT,
	HMI_TYPE_SCENARIO_PARKIN = 100,
	HMI_TYPE_SCENARIO_PARKOUT,
	HMI_TYPE_SCENARIO_CRUISE,
	HMI_TYPE_SCENARIO_RA
	
}tHmiTypeReq;
typedef enum _ttAPA_VisionPldSts
{
	APA_VIS_PLD_OFF = 0,
	APA_VIS_PLD_STANDBY = 1,
	APA_VIS_PLD_NO_BERTH = 2,
	APA_VIS_PLD_BERTH = 3
	
}tAPA_VisionPldSts;
typedef enum _ttAPA_UlrasonicPldSts
{
	APA_UPLD_OFF = 0,
	APA_UPLD_STANDBY = 1,
	APA_UPLD_NO_BERTH = 2,
	APA_UPLD_BERTH = 3
	
}tAPA_UlrasonicPldSts;
typedef enum _ttAPA_DataFusionSts
{
	APA_DF_OFF = 0,
	APA_DF_STANDBY = 1,
	APA_DF_NO_BERTH = 2,
	APA_DF_BERTH = 3,
	APA_DF_DRAG = 4
	
}tAPA_DataFusionSts;
typedef enum _ttAPA_PathPlanSts
{
	APA_PATH_PLAN_STANDBY = 0,
	APA_PATH_PLAN_SUCCESS = 1,
	APA_PATH_PLAN_FAILED = 2,
	APA_PATH_PLAN_PRE_SUCCESS = 3,
	APA_PATH_PLAN_PRE_FAILED = 4,
	APA_PATH_PLAN_PRE_USER = 5,
	APA_PATH_PLAN_FINISH = 10
	
}tAPA_PathPlanSts;
typedef enum _ttAPA_TacticalSts
{
	APA_TACTICAL_STANDBY = 0,
	APA_TACTICAL_ACTIVE = 1,
	APA_TACTICAL_SUCCESS = 2,
	APA_TACTICAL_FAILURE = 3,
	APA_TACTICAL_PREPLAN = 10,
	APA_TACTICAL_PREPLAN_SUCCESS = 11,
	APA_TACTICAL_PREPLAN_FAILURE = 12
	
}tAPA_TacticalSts;
typedef enum _ttAPA_CtrlSts
{
	APA_CTRL_OFF = 0,
	APA_CTRL_STANDBY = 1,
	APA_CTRL_ACTIVE = 2,
	APA_CTRL_COMPLETE_APA = 3,
	APA_CTRL_PAUSE = 4,
	APA_CTRL_FAULT = 5,
	APA_CTRL_COMPLETE_HPP = 6
	
}tAPA_CtrlSts;
typedef enum _ttAPA_UltrasonicSwtCtrl
{
	APA_US_SWT_OFF = 0,
	APA_US_SWT_STANDBY = 1,
	APA_US_SWT_ON = 2
	
}tAPA_UltrasonicSwtCtrl;
typedef enum _ttAPA_UltrasonicSts
{
	APA_US_STS_OFF = 0,
	APA_US_STS_INIT = 1,
	APA_US_STS_STANDBY = 2,
	APA_US_STS_SUCCESS = 3,
	APA_US_STS_LIMITED = 4,
	APA_US_STS_FAILED = 5
	
}tAPA_UltrasonicSts;
typedef enum _ttPDC_AudioWarnLv
{
	PDC_AUD_WARN_LV_NONE = 0,
	PDC_AUD_WARN_LV_LONG_BEEP = 1,
	PDC_AUD_WARN_LV_2 = 2,
	PDC_AUD_WARN_LV_3 = 3,
	PDC_AUD_WARN_LV_4 = 4,
	PDC_AUD_WARN_LV_5 = 5,
	PDC_AUD_WARN_LV_6 = 6,
	PDC_AUD_WARN_LV_7 = 7,
	PDC_AUD_WARN_LV_8 = 8,
	PDC_AUD_WARN_LV_9 = 9,
	PDC_AUD_WARN_LV_10 = 10
	
}tPDC_AudioWarnLv;
typedef enum _ttAPA_FunctionSts
{
	APA_FUNC_OFF = 0,
	APA_FUNC_STANDBY = 1,
	APA_FUNC_SUCCESS = 2,
	APA_FUNC_FAILED = 3
	
}tAPA_FunctionSts;
typedef enum _ttAPA_HandshakeSts
{
	APA_HANDSHAKE_NONE = 0,
	APA_HANDSHAKE_EXECUTING,
	APA_HANDSHAKE_EXECUTE_SUCCESS,
	APA_HANDSHAKE_EXECUTE_FAILURE,
	APA_HANDSHAKE_EXITING,
	APA_HANDSHAKE_EXIT_SUCCESS,
	APA_HANDSHAKE_EXIT_FAILURE
	
}tAPA_HandshakeSts;
typedef enum _ttVehi_SignalType
{
	HPP_HANDSHAKE_NONE = 0,
	HPP_HANDSHAKE_REQUIRING,
	HPP_HANDSHAKE_EXECUTING,
	HPP_HANDSHAKE_EXECUTE_SUCCESS,
	HPP_HANDSHAKE_EXECUTE_FAILURE,
	HPP_HANDSHAKE_EXITING,
	HPP_HANDSHAKE_EXIT_SUCCESS
	
}tVehi_SignalType;
typedef enum _ttAPA_EcuType
{
	ECU_TYPE_UNKNOWN = 0,
	ECU_TYPE_EP12_TC277,
	ECU_TYPE_USS_TC277,
	ECU_TYPE_USS_S32K3,
	ECU_TYPE_TC297,
	ECU_TYPE_TC387,
	ECU_TYPE_TC397,
	ECU_TYPE_TC399,
	ECU_TYPE_S32G2_M7,
	ECU_TYPE_S32G3_M7,
	ECU_TYPE_SOC_START = 200,
	ECU_TYPE_EP12_TDA2 = 200,
	ECU_TYPE_EAPA_TDA4,
	ECU_TYPE_EAPA_J3,
	ECU_TYPE_EAPA_J5,
	ECU_TYPE_S32G2,
	ECU_TYPE_S32G3,
	ECU_TYPE_SA8155P,
	ECU_TYPE_SA8295,
	ECU_TYPE_MAX
	
}tAPA_EcuType;
typedef enum _ttAPA_SubmoduleEnableCfg
{
	SUBMODULE_DISABLE_BOTH = 0,
	SUBMODULE_ENABLE_ON_MCU,
	SUBMODULE_ENABLE_ON_SOC,
	SUBMODULE_ENABLE_BOTH
	
}tAPA_SubmoduleEnableCfg;
typedef enum _ttAPA_ObjType
{
	OBJ_TYPE_INVALID = 0,
	OBJ_TYPE_DEFAULT = 1,
	OBJ_TYPE_BERTH_PERPENDICULAR,
	OBJ_TYPE_BERTH_PARALLEL,
	OBJ_TYPE_BERTH_SLANTED_30_DEG,
	OBJ_TYPE_BERTH_SLANTED_45_DEG,
	OBJ_TYPE_BERTH_SLANTED_60_DEG,
	OBJ_TYPE_BERTH_MECHANISM,
	OBJ_TYPE_OBSTACALE_US,
	OBJ_TYPE_OBSTACALE_VIS,
	OBJ_TYPE_OBSTACALE_US_LOW,
	OBJ_TYPE_OBSTACALE_US_HIGH
	
}tAPA_ObjType;
typedef enum _ttAPA_PldBerthAvailable
{
	PLD_BERTH_NONE = 0,
	PLD_BERTH_NOT_AVAILABLE,
	PLD_BERTH_AVAILABLE,
	PLD_BERTH_SELECTED
	
}tAPA_PldBerthAvailable;
typedef enum _ttRPA_CtrlReq
{
	RPA_REQ_NONE = 0,
	RPA_REQ_SEARCHING,
	RPA_REQ_PARK_ACTIVE,
	RPA_REQ_PARK_SUSPEND,
	RPA_REQ_PARK_RESUME,
	RPA_REQ_TERMINATE
	
}tRPA_CtrlReq;
typedef enum _ttMsg_DTCtype
{
	AI_CAMERA_COVER_ERR = 1,
	AI_IMG_DIRT_ERR = 2,
	VISION_CALIBRATION_FILE_ERROR = 3,
	DR_TIME_STAMP_INVALID_ERR = 11,
	DR_TIME_INTERVAL_INVALID_ERR = 12,
	DR_WHEEL_IMPULSE_INVALID_ERR = 13,
	PP_STATUS_ERR = 21,
	PP_CALC_FAIL_PLD_NARROW_ERR = 22,
	PP_PATHID_ABNORMAL_ERR = 23,
	PP_CALC_FAIL_ID_INVALID_ERR = 24,
	EM_MCU_TIMESTAMP_ERR = 31,
	EM_MCU_DATA_OFF_ERR = 32
	
}tMsg_DTCtype;
typedef enum _ttHandshakeTypeRq
{
	HANDSHAKE_RQ_TYPE_NONE,
	HANDSHAKE_RQ_LOW_SPEED,
	HANDSHAKE_RQ_HIGH_SPEED
	
}tHandshakeTypeRq;
typedef enum _ttLSAD_HandShakeSts
{
	LSAD_HPP_HANDSHAKE_NONE = 0,
	LSAD_HPP_HANDSHAKE_REQUIRING,
	LSAD_HPP_HANDSHAKE_EXECUTING,
	LSAD_HPP_HANDSHAKE_EXECUTE_SUCCESS,
	LSAD_HPP_HANDSHAKE_EXECUTE_FAILURE,
	LSAD_HPP_HANDSHAKE_EXITING,
	LSAD_HPP_HANDSHAKE_EXIT_SUCCESS,
	LSAD_APA_HANDSHAKE_NONE,
	LSAD_APA_HANDSHAKE_REQUIRING,
	LSAD_APA_HANDSHAKE_EXECUTING,
	LSAD_APA_HANDSHAKE_EXECUTE_SUCCESS,
	LSAD_APA_HANDSHAKE_EXECUTE_FAILURE,
	LSAD_APA_HANDSHAKE_EXITING,
	LSAD_APA_HANDSHAKE_EXIT_SUCCESS
	
}tLSAD_HandShakeSts;
typedef enum _teCalibDataTransferMode
{
	TRANSFER_MODE_NONE = 0,
	TRANSFER_MODE_SINGLE = 1,
	TRANSFER_MODE_GROUP = 2,
	TRANSFER_MODE_GET_GROUP = 3,
	TRANSFER_MODE_GET_ALL_GROUP = 4
	
}eCalibDataTransferMode;
typedef enum _teCalibDataDirection
{
	DIRECTION_MCU_TO_SOC = 1,
	DIRECTION_SOC_TO_MCU = 2
	
}eCalibDataDirection;
typedef enum _tECtrlState
{
	CTRL_CTRL_STATE_NONE = 0,
	CTRL_CTRL_STATE_FOLLOW = 1,
	CTRL_CTRL_STATE_STOP = 2,
	CTRL_CTRL_STATE_STOP_REDUCT = 3
	
}ECtrlState;
typedef enum _tECtrlSubstate
{
	CTRL_CTRL_SUBSTATE_STOP_NONE = 0,
	CTRL_CTRL_SUBSTATE_STOP_REACH = 1,
	CTRL_CTRL_SUBSTATE_STOP_PEB = 2,
	CTRL_CTRL_SUBSTATE_STOP_PP = 3,
	CTRL_CTRL_SUBSTATE_STOP_TRAP = 10,
	CTRL_CTRL_SUBSTATE_STOP_CHOCK = 11,
	CTRL_CTRL_SUBSTATE_STOP_INVALID = 12,
	CTRL_CTRL_SUBSTATE_STOP_LONG = 13,
	CTRL_CTRL_SUBSTATE_STOP_OTHERS = 20,
	CTRL_CTRL_SUBSTATE_FOLLOW_NONE = 100
	
}ECtrlSubstate;
typedef enum _tECtrlAction
{
	CTRL_ACTION_NONE = 0,
	CTRL_ACTION_STOP = 1,
	CTRL_ACTION_PAUSE = 2,
	CTRL_ACTION_FINISH = 10
	
}ECtrlAction;
typedef enum _tPixelLabel
{
	eLABEL_UNKNOW = 0,
	eLABEL_VEHICLE = 1,
	eLABEL_ROAD = 2,
	eLABEL_PERSON = 3,
	eLABEL_ZEBRA = 4,
	eLABEL_PARKINGLINE = 5,
	eLABEL_ROADARROW = 6,
	eLABEL_CURBSTONE = 7,
	eLABEL_WALLCOLUMN = 8,
	eLABEL_SPEEDBUMP = 9,
	eLABEL_LANELINE = 10,
	eLABEL_PARKLOCK = 11,
	eLABEL_VEHSTOPER = 12,
	eLABEL_TRAFFCONE = 13,
	eLABEL_OBSTACLE = 14,
	eLABEL_PARKAREA = 15,
	eLABEL_TOTALNUM//classnum
	
}PixelLabel;
typedef enum _ttUSH_UsIdx
{
	US_IDX_APA_FRS = 0,
	US_IDX_APA_RRS = 1,
	US_IDX_APA_FLS = 2,
	US_IDX_APA_RLS = 3,
	US_IDX_PDC_RRC = 4,
	US_IDX_PDC_RRM = 5,
	US_IDX_PDC_RLM = 6,
	US_IDX_PDC_RLC = 7,
	US_IDX_PDC_FLC = 8,
	US_IDX_PDC_FLM = 9,
	US_IDX_PDC_FRM = 10,
	US_IDX_PDC_FRC = 11,
	US_IDX_NUM_MAX = 12,
	US_IDX_APA_PDC_BOUND = US_IDX_PDC_RRC,
	US_IDX_ALL_IDX = 0xFE,
	US_IDX_INVALID = 0xFF
	
}tUSH_UsIdx;
typedef enum _ttUSH_UsExtendSts
{
	USH_EXTEND_STS_NONE = 0x0000,
	USH_EXTEND_STS_BLIND_DETECT = 0x0001,
	USH_EXTEND_STS_DIRECT_WAVE = 0x0002,
	USH_EXTEND_STS_MULTI_ECHO = 0x0004,
	USH_EXTEND_STS_CHAN_INTERFERE = 0x0008,
	USH_EXTEND_STS_NOISE = 0x0010,
	USH_EXTEND_STS_EXTEND_RECEIVE = 0x0020,
	USH_EXTEND_STS_RINGINGTIME_BOOST = 0x0040,
	USH_EXTEND_STS_HIGH_OBJ = 0x0080,
	USH_EXTEND_STS_STRONG_ECHO_SIGNAL = 0x0100,
	USH_EXTEND_STS_UNSCHEDULED_RECEIVE = 0x0200,
	USH_EXTEND_STS_ALL_MASK = 0x07FF
	
}tUSH_UsExtendSts;
typedef enum _ttUSH_MeasurementProfile
{
	USH_MEASUREMENT_PROFILE_A,
	USH_MEASUREMENT_PROFILE_B,
	USH_MEASUREMENT_PROFILE_C,
	USH_MEASUREMENT_PROFILE_ENVELOPE,
	USH_MEASUREMENT_PROFILE_NONE,
	USH_MEASUREMENT_PROFILE_NUM
	
}tUSH_MeasurementProfile;
typedef enum _ttUSH_UsSensorDiag
{
	USH_DIAG_NORMAL = 0x00000000U,
	USH_DIAG_NOISE = 0x00000001U,
	USH_DIAG_FREQ_DEV_RING = 0x00000004U,
	USH_DIAG_FREQ_DEV_TRANS_RESP = 0x00000008U,
	USH_DIAG_TEMPORARY_FAILURE_MASK = 0x0000000DU,
	USH_DIAG_DRIVER_IO_CHECK_ERR = 0x00000010U,
	USH_DIAG_SENSOR_IO_CHECK_ERR = 0x00000020U,
	USH_DIAG_READBACK_CHECK_ERR = 0x00000040U,
	USH_DIAG_VOLT_ERR = 0x00000080U,
	USH_DIAG_THRES_N_ACTIVE = 0x00000100U,
	USH_DIAG_MEAS_N_ACTIVE = 0x00000200U,
	USH_DIAG_OUTER_PARM_ERR_MASK = 0x00000380U,
	USH_DIAG_OV = 0x00000400U,
	USH_DIAG_UV = 0x00000800U,
	USH_DIAG_VAL_ERR_MASK = 0x00000C00U,
	USH_DIAG_SC = 0x00001000U,
	USH_DIAG_OC = 0x00002000U,
	USH_DIAG_OT = 0x00004000U,
	USH_DIAG_G_DIG_DEV = 0x00008000U,
	USH_DIAG_G_ANA_DEV = 0x00010000U,
	USH_DIAG_I_DRV_DEV = 0x00020000U,
	USH_DIAG_F_DRV_DEV = 0x00040000U,
	USH_DIAG_CHIP_ID_INV = 0x00080000U,
	USH_DIAG_EOL_FAILURE = 0x00100000U,
	USH_DIAG_EE_CHECK_ERR = 0x00200000U,
	USH_DIAG_FREQ_DEV = 0x00400000U,
	USH_DIAG_PWR_FAILURE = 0x00800000U,
	USH_DIAG_DRIVER_FAILURE = 0x01000000U,
	USH_DIAG_ALGO_SIG_ABNORMAL = 0x02000000U,
	USH_DIAG_RINGING_TIME_DEV = 0x04000000U,
	USH_DIAG_PWR_RESET = 0x08000000U,
	USH_DIAG_INNER_PARM_ERR_MASK = 0x003F8000U,
	USH_DIAG_SCOC = 0x00003000U,
	USH_DIAG_ECHO_DEV = 0x04400000U,
	USH_DIAG_CLOSE_DETECT_MASK = 0x003FFF80U,
	USH_DIAG_DRIVER_COMM_ERR_MASK = 0x00400070U,
	USH_DIAG_SERIOUS_FAILURE_MASK = 0x07FFFFF0U,
	USH_DIAG_ALL_FAILURES_MASK = (USH_DIAG_TEMPORARY_FAILURE_MASK | USH_DIAG_SERIOUS_FAILURE_MASK)
	
}tUSH_UsSensorDiag;
typedef enum _tDragParkingLotType
{
	DRAG_PL_TYPE_None = 0,
	DRAG_PL_TYPE_Horizontal = 1,
	DRAG_PL_TYPE_Vertical = 2,
	DRAG_PL_TYPE_Oblique_30 = 3,
	DRAG_PL_TYPE_Oblique_45 = 4,
	DRAG_PL_TYPE_Oblique_60 = 5
	
}DragParkingLotType;
typedef enum _tPECP_PLD_TYPE
{
	PECP_PLD_TYPE_INVALID = -1,
	PECP_PLD_TYPE_Horizontal = 0,
	PECP_PLD_TYPE_Vertical = 1,
	PECP_PLD_TYPE_Oblique_30 = 2,
	PECP_PLD_TYPE_Oblique_45 = 3,
	PECP_PLD_TYPE_Oblique_60 = 4,
	PECP_PLD_TYPE_ThreeDimensional = 5,
	PECP_PLD_TYPE_SPACE_Horizontal = 6,
	PECP_PLD_TYPE_SPACE_Vertical = 7,
	PECP_PLD_TYPE_SPACE_Oblique = 8
	
}PECP_PLD_TYPE;
typedef enum _tPECP_PLD_STATE
{
	PECP_PLD_STATE_UnAvailable = 0,
	PECP_PLD_STATE_Available = 1,
	PECP_PLD_STATE_Unknow = 2
	
}PECP_PLD_STATE;
typedef enum _tPECP_OBJECT_TYPES
{
	PECP_OBJECT_CAR4 = 0,
	PECP_OBJECT_PIL3,
	PECP_OBJECT_RIDE2,
	PECP_OBJECT_LOCK,
	PECP_OBJECT_COLUMN,
	PECP_OBJECT_CONE,
	PECP_OBJECT_PERSON//pedestrian
	
}PECP_OBJECT_TYPES;
typedef enum _ttSwitchSts
{
	USS_OFF = 0,
	USS_ON
	
}tSwitchSts;
typedef enum _teLSAD_HandShakeDiag
{
	LSAD_HANDSHAKE_TCU_NOT_AVAILABLE = 0,
	LSAD_HANDSHAKE_EPS_NOT_AVAILABLE = 1,
	LSAD_HANDSHAKE_ESC_NOT_AVAILABLE = 2,
	LSAD_HANDSHAKE_TCU_NOT_IN_ACTIVE = 3,
	LSAD_HANDSHAKE_EPS_NOT_IN_ACTIVE = 4,
	LSAD_HANDSHAKE_ESC_NOT_IN_ACTIVE = 5,
	LSAD_HANDSHAKE_STEERWHEEL_ANG_REQUIRE_ERROR = 6,
	LSAD_HANDSHAKE_STEERWHEEL_ANG_INTERRUPTED = 7,
	LSAD_HANDSHAKE_BRAKE_NOT_FORCED = 8,
	LSAD_HANDSHAKE_DIAG_NUM_MAX = 9
	
}eLSAD_HandShakeDiag;
typedef enum _tEVehDirection
{
	VEH_DIRECTION_STOP = 0,
	VEH_DIRECTION_FORWARD = 1,
	VEH_DIRECTION_BACKWARD = 2,
	VEH_DIRECTION_INVALID = 3
	
}EVehDirection;
typedef enum _tELocStatus
{
	LOC_STATUS_NONE = 0,
	LOC_STATUS_TRYING = 1,
	LOC_STATUS_SUCCESS = 2
	
}ELocStatus;
typedef enum _tEMapCreatorState
{
	MAPCREATOR_STATE_NOT_READY = 0,
	MAPCREATOR_STATE_READY = 1,
	MAPCREATOR_STATE_IN_PROGRESS = 2,
	MAPCREATOR_STATE_ABORTED = 4,
	MAPCREATOR_STATE_FINALIZING = 5,
	MAPCREATOR_STATE_SUCCESSED = 6,
	MAPCREATOR_STATE_FAILED = 7,
	MAPCREATOR_STATE_CLOSED = 8
	
}EMapCreatorState;
typedef enum _ttLSAD_FuncSts
{
	FUNC_STS_STANDBY = 0,
	FUNC_STS_APA_BACKGROUND_SEARCH = 1,
	FUNC_STS_APA_MODE_SELECT = 2,
	FUNC_STS_APA_PI_SUPPRESSION = 3,
	FUNC_STS_APA_PI_SEARCH = 4,
	FUNC_STS_APA_PI_CONFIRM = 5,
	FUNC_STS_APA_PO_SUPPRESSION = 6,
	FUNC_STS_APA_PO_CONFIRM = 7,
	FUNC_STS_RPA_REMOTE_CONNECT = 8,
	FUNC_STS_RPA_REMOTE_OK = 9,
	FUNC_STS_RPA_PO_CONFIRM = 10,
	FUNC_STS_RPA_PARK_STRAIGHT = 11,
	FUNC_STS_RPA_PI_SUPPRESSION = 12,
	FUNC_STS_RPA_PI_SEARCH = 13,
	FUNC_STS_RPA_PI_CONFIRM = 14,
	FUNC_STS_CRUISE_READY = 15,
	FUNC_STS_CRUISE_SUSPEND = 16,
	FUNC_STS_RA_READY = 17,
	FUNC_STS_EOL_ACTIVE = 18,
	FUNC_STS_AFTER_SELECT = 19,
	FUNC_STS_QUIT = 20
	
}tLSAD_FuncSts;
typedef enum _tEParkOutDirection
{
	PARKOUT_DIR_NONE = 0,
	PARKOUT_DIR_FRONT_LEFT = 1,
	PARKOUT_DIR_FRONT_MID = 2,
	PARKOUT_DIR_FRONT_RIGHT = 4,
	PARKOUT_DIR_REAR_LEFT = 8,
	PARKOUT_DIR_REAR_MID = 16,
	PARKOUT_DIR_REAR_RIGHT = 32,
	PARKOUT_DIR_SIDE_LEFT = 64,
	PARKOUT_DIR_SIDE_RIGHT = 128,
	PARKOUT_DIR_ALL = 255
	
}EParkOutDirection;
typedef enum _tECtrlActionReason
{
	CTRL_ACTION_REASON_NONE = 0,
	CTRL_ACTION_REASON_STOP_SPEED = 1,
	CTRL_ACTION_REASON_PAUSE_TRAP = 50,
	CTRL_ACTION_REASON_PAUSE_AEB_REPLAN_ERROR = 51,
	CTRL_ACTION_REASON_PAUSE_PRECHECK_ERROR = 52,
	CTRL_ACTION_REASON_PAUSE_PARKIN_SLOT_OCCUPY = 70,
	CTRL_ACTION_REASON_FINISH_COMPELTE = 100,
	CTRL_ACTION_REASON_FINISH_CTRL_ERROR = 101,
	CTRL_ACTION_REASON_FINISH_TRAP = 102
	
}ECtrlActionReason;
typedef struct _TPoint
{
	float32_t x;
    float32_t y;
    
}TPoint;
typedef struct _TPoint2I
{
	int32_t x;
    int32_t y;
    
}TPoint2I;
typedef struct _TPose
{
	TPoint point;
    float32_t theta;
    
}TPose;
typedef struct _TLine
{
	float32_t a;
    float32_t b;
    float32_t c;
    
}TLine;
typedef struct _tMsgMnger_Hmi
{
	TimestampType u64Timestamp_us;
    uint8_t HmiStsReq;  // tHmiStsReq
    uint8_t HmiTypeReq;
    uint8_t Res[2];
    
}tMsgMnger_Hmi;
typedef struct _ST_VEHICLE_VCU_INFO
{
	float32_t f32MotorSpeed;
    tVehiGear eVehicleGear;  // vehicle gear
    tActiveSts eBrakeActiveSts;  // brake active status
    
}ST_VEHICLE_VCU_INFO, *PST_VEHICLE_VCU_INFO;
typedef struct _ST_VEHICLE_EPS_INFO
{
	float32_t f32SteeringWheelAngle;  // (deg)
    float32_t f32SteeringWheelAngleSpd;  // (deg/s)
    
}ST_VEHICLE_EPS_INFO, *PST_VEHICLE_EPS_INFO;
typedef struct _ST_VEHICLE_ESC_INFO
{
	tValidity eVehicleSpeedValidity;  // vehicle speed validity
    float32_t f32VehicleSpeed;  // vehicle speed, (kph)
    float32_t f32WheelSpeedFL;  // left front wheel speed (kph)
    float32_t f32WheelSpeedFR;  // right front wheel speed (kph)
    float32_t f32WheelSpeedRL;  // left rear wheel speed (kph)
    float32_t f32WheelSpeedRR;  // right rear wheel speed (kph)
    uint16_t u16WheSpePulFL;  // left front wheel pulse
    uint16_t u16WheSpePulFR;  // right front wheel pulse
    uint16_t u16WheSpePulRL;  // left rear wheel pulse
    uint16_t u16WheSpePulRR;  // right rear wheel pulse
    tWheelDirection eWheelDirFL;  // left front wheel direction
    tWheelDirection eWheelDirFR;  // right front wheel direction
    tWheelDirection eWheelDirRL;  // left rear wheel direction
    tWheelDirection eWheelDirRR;  // right rear wheel direction
    uint8_t u8VehStantStill;
    uint8_t u8Res[7];
    
}ST_VEHICLE_ESC_INFO, *PST_VEHICLE_ESC_INFO;
typedef struct _ST_VEHICLE_BCM_INFO
{
	uint8_t u8FLDoorOpenSts;  // 1:Open     0:Close
    uint8_t u8FRDoorOpenSts;  // 1:Open     0:Close
    uint8_t u8RLDoorOpenSts;  // 1:Open     0:Close
    uint8_t u8RRDoorOpenSts;  // 1:Open     0:Close
    uint8_t u8HoodOpenSts;  // 1:Open     0:Close
    uint8_t u8TailgateOpenSts;  // 1:Open     0:Close
    uint8_t u8Res2[2];
    
}ST_VEHICLE_BCM_INFO, *PST_VEHICLE_BCM_INFO;
typedef struct _tVehi_VehicleDataRx
{
	uint64_t u64Timestamp_us;
    ST_VEHICLE_VCU_INFO stVehVCUInfo;  // vehilce VCU info
    ST_VEHICLE_EPS_INFO stVehEPSInfo;  // vehilce EPS info
    ST_VEHICLE_ESC_INFO stVehESCInfo;  // vehilce ESC info
    ST_VEHICLE_BCM_INFO stVehBCMInfo;  // vehilce BCM info
    float32_t ambientAirTemp_degC;  // ambient air temperature, (degC)
    tValidity ambientAirTempValidity;  // ambient air validity
    uint8_t u8Res[8];
    
}tVehi_VehicleDataRx, *pst_tVehicleDataRx_T;
typedef struct _ST_VEHICLE_HANDSHAKE_INFO
{
	uint8_t Veh_CDD_Available;
    uint8_t Veh_CDD_Fail;
    uint8_t Veh_CDD_Active;
    uint8_t Veh_VLCActive;
    uint8_t Veh_VLCAvailable;
    uint8_t Veh_VLCFail;
    uint8_t SCU_APA_Sts;
    uint8_t ESC_APA_Sts;
    uint8_t EPS_APA_Sts;
    
}ST_VEHICLE_HANDSHAKE_INFO;
typedef struct _tVehi_VehicleDataTx
{
	uint64_t u64Timestamp_us;
    float32_t f32CtrlReqAccel;  // unit: m/2^2
    float32_t f32CtrlReqSpeed;  // unit: m/s
    float32_t f32CtrlReqStopDistance;  // unit: m
    float32_t f32CtrlReqTorq;  // unit: Nm
    float32_t f32CtrlReqDelAccel;  // unit: m/s
    float32_t f32CtrlReqAccelSlopUpper;  // unit: m/2^2
    float32_t f32CtrlReqAccelSlopLower;  // unit: m/2^2
    float32_t f32CtrlReqSteer;  // unit: degree
    float32_t f32CtrlReqSteerSpeed;  // unit: degree/s
    float32_t f32MEBDecCtrlVal;  // unit: m/2^2
    tVehiGear eGearReq;  // 0123 PRND
    tRequest eStandStillReq;  // 0：N/A 1:Stand still Require
    tHandshakeTypeRq eHandshakeReq;  // 0: N/A 1: HandShakeReq
    tRequest eEpbPullReq;  // 0: N/A 1: pull EPB request
    tRequest eAEBFlag;
    tRequest eMEBDecCtrlReq;  // 0: N/A 1: MEB decelerate ctrl request
    
}tVehi_VehicleDataTx, *pst_tVehicleDataTx_T;
typedef struct _tUSH_ObstacleInfo
{
	TimestampType u64Timestamp_us;
    tUSH_UsIdx eSendUsIdx;  // @see tUSH_UsIdx. sensor which transmits ultrasonic signal
    tUSH_UsIdx eRecvUsIdx;  // @see tUSH_UsIdx. sensor which receive ultrasonic signal
    uint16 u16Length[USH_ECHO_NUM_MAX];  // total length of ultrasonic path, unit: (mm).
    uint16 u16Width[USH_ECHO_NUM_MAX];  // unit: (us).
    uint8 u8EchoHeight[USH_ECHO_NUM_MAX];  // the echo height of the echo (0~0x3F
    uint8 u8EchoNum;  // number of echoes (0~5)
    uint8 u8RollingCount;  // obstacle information updated rolling counter (0~255)
    uint8 u8res;
    tUSH_MeasurementProfile eMeasProf;  // @see tUSH_MeasurementProfile. sensor measurement profile
    tUSH_UsExtendSts eUsExtendSts;  // @see tUSH_UsExtendSts. ultrasonic service extend status mask
    tUSH_UsSensorDiag eUsDiagSts;  // @see tUSH_UsSensorDiag. sensor diagnostic result
    
}tUSH_ObstacleInfo;
typedef struct _tMsgMnger_UsObstacle
{
	TimestampType u64Timestamp_us;
    tAPA_UltrasonicSts eUsObstacleFuncSts;  // @see tAPA_UltrasonicSts.
    uint16 u16SensorFailureBitMask;  // ultrasonic sensors(bit0~11) failure bit mask, 0: not failure, 1: failure
    uint16 u16BlindZoneUnlockTriggerBitMask;  // 超声盲区解锁触发(bit0~5: Front/Rear/FRS/RRS/FLS/RLS)
    tUSH_ObstacleInfo sObstacleInfo[US_IDX_NUM_MAX * USH_ONE_SND_MULT_RCV_MAX];
    uint8 u8RollingCountApa;  // all APA information updated rolling counter (0~255)
    uint8 u8RollingCountPdc;  // all PDC information updated rolling counter (0~255)
    uint16 u16SendSensorUpdateBitMask;  // 0~11 bit correspond to 12 sensor; 0=no update, 1=updated; (cycle=50ms)
    tUSH_Temperature_degC fEnvironmentTemperature;
    tUSH_Temperature_degC fUsSensorTemperature;
    
}tMsgMnger_UsObstacle;
typedef struct _tVisionFreespaceBdRst_draw
{
	uint8_t au8FsBdMap[384*384];  // freespace bindary map
    uint64_t u64Timestamp_img;  // the time of image that pld dnn result
    
}tVisionFreespaceBdRst_draw;
typedef struct _tCtrl_StateInfo
{
	uint16_t u16CurPathid;
    uint8_t u8CtrlState;
    uint8_t u8CtrlSubstate;
    uint32_t u8PathPEBDir;
    uint8_t u8res[24];
    
}tCtrl_StateInfo;
typedef struct _tCtrl_LogInfo
{
	float32_t f32AdasDebugVal[LOG_ADAS_DEBUG_NUM];
    
}tCtrl_LogInfo;
typedef struct _tMsgMnger_CtrlErrCode
{
	uint16_t u16ModuleInitErrCode;
    uint16_t u16ModuleInputErrCode;
    uint16_t u16ModuleOutputErrCode;
    uint16_t u16ModuleHandshakeErrCode;
    uint16_t u16ModuleUserErrCode;
    uint16_t u16ModulePebErrCode;
    uint16_t u16ModuleDrErrCode;
    uint16_t u16ModuleParkErrCode;
    uint16_t u16ModuleHeadoutErrCode;
    uint16_t u16ModuleCruiseErrCode;
    uint16_t u16Res[6];
    
}tMsgMnger_CtrlErrCode;
typedef struct _tObjProperty2D
{
	TimestampType u64Timestamp_us;
    tAPA_ObjType eType;  // object type
    float32_t f32X;  // unit: m
    float32_t f32Y;  // unit: m
    float32_t f32Theta;  // unit: rad (-pi, pi]
    float32_t f32Width;  // unit: m
    float32_t f32Depth;  // unit: m
    uint16_t u16Id;  // object identifier (0=invalid ID)
    uint8_t u8Confidence;  // object confidence
    uint8_t u8res;
    
}tObjProperty2D;
typedef struct _tObjProperty3D
{
	TimestampType u64Timestamp_us;
    tAPA_ObjType eType;  // object type
    float32_t f32X;  // unit: m
    float32_t f32Y;  // unit: m
    float32_t f32Z;  // unit: m
    float32_t f32Yaw;  // unit: rad (-pi, pi]
    float32_t f32Pitch;  // unit: rad (-pi, pi]
    float32_t f32Roll;  // unit: rad (-pi, pi]
    float32_t f32Width;  // unit: m
    float32_t f32Depth;  // unit: m
    float32_t f32Height;  // unit: m
    uint16_t u16Id;  // object identifier (0=invalid ID)
    uint8_t u8Confidence;  // object confidence
    uint8_t u8res;
    
}tObjProperty3D;
typedef struct _tMsgMnger_EcuInfo
{
	TimestampType u64PowOnTimestamp_us;  // MCU power on timestamp, unit: us
    TimestampType u64UnixTimestamp_us;  // unix timestamp(ISO 8601: 1970-01-01T00:00:00Z.)
    tAPA_EcuType eHardwareType;  // hardware type identifier
    uint8_t u8HardwareMajorVersion;  // hardware major version
    uint8_t u8HardwareMinorVersion;  // hardware minor version
    uint8_t u8HardwarePatchVersion;  // hardware patch version
    uint8_t u8SoftwareMajorVersion;  // software major version
    uint8_t u8SoftwareMinorVersion;  // software minor version
    uint8_t u8SoftwarePatchVersion;  // software patch version
    uint16_t u16JenkinsBuildNum;  // jenkins build num
    tSelfcheckSts eSelfcheckSts;  // ECU self check status
    
}tMsgMnger_EcuInfo;
typedef struct _tMsgMnger_VehicleInfo
{
	TimestampType u64Timestamp_us;
    int32_t eVehiType;  // vehicle type, NL5/MCE/etc...
    tVehi_VehicleDataRx sVehicleDataRx;  // received vehicle CAN data
    
}tMsgMnger_VehicleInfo;
typedef struct _tAPA_SubmoduleCfg
{
	tAPA_SubmoduleEnableCfg eApaCfg_EcuInfo;
    tAPA_SubmoduleEnableCfg eApaCfg_VehicleData;
    tAPA_SubmoduleEnableCfg eApaCfg_ApaRpaHpa;
    tAPA_SubmoduleEnableCfg eApaCfg_UsObstacle;
    tAPA_SubmoduleEnableCfg eApaCfg_ObjDetection;
    tAPA_SubmoduleEnableCfg eApaCfg_VisionPld;
    tAPA_SubmoduleEnableCfg eApaCfg_UltrasonicPld;
    tAPA_SubmoduleEnableCfg eApaCfg_Freespace;
    tAPA_SubmoduleEnableCfg eApaCfg_DataFusion;
    tAPA_SubmoduleEnableCfg eApaCfg_Localisation;
    tAPA_SubmoduleEnableCfg eApaCfg_PathPlanner;
    tAPA_SubmoduleEnableCfg eApaCfg_PfPeb;
    tAPA_SubmoduleEnableCfg eApaCfg_Pdc;
    
}tAPA_SubmoduleCfg;
typedef struct _tMsgMnger_ApaState
{
	TimestampType u64Timestamp_us;
    tLSAD_SystemSts eLsadSystemSts;  // APA system status
    tLSAD_SystemSubSts eLsadSystemSubSts;
    uint8 u8LsadFuncSts;  // Functions status(enum:tLSAD_FuncSts)
    uint8 u8BckgrndSearchSts;  // 后台巡库状态，0不支持，1支持，
    uint8 u8BckgrndCruiseReadySts;  // 后台支持Cruise，0不支持，1支持
    uint8 u8BckgrndRecordSts;  // 后台支持记录车辆位置，0不支持，1支持
    uint8 u8SelectedBerthId;  // selected berth ID on HMI (0=invalid ID)
    uint8 u8LsadFuncType;
    uint8 u8DriverCtrlCommand;
    uint8 u8TrgrAutoDetectFunc;  // 0不触发自识别功能的任何判断 1触发泊入/泊出自识别功能的判断 
    uint8 u8LsadStSResetPEB;  // 用于PEB重置
    uint8 u8Res3[3];
    
}tMsgMnger_ApaState;
typedef struct _tMsgMnger_RpaApp
{
	TimestampType u64Timestamp_us;
    tRequest eRpaModeReq;  // USS RPA mode request
    tRPA_CtrlReq eRpaCtrlReq;  // RPA control request
    uint8_t u8SelectedBerthId;  // selected berth ID on APP (0=invalid ID)
    uint8_t reserved[3];
    
}tMsgMnger_RpaApp;
typedef struct _tMsgMnger_ObjDetection
{
	TimestampType u64Timestamp_us;
    tAPA_FunctionSts eObjectDetectionSts;
    tObjProperty2D sObjProperty2D[OD_NUM_MAX];
    uint8 reserved[64U];
    
}tMsgMnger_ObjDetection;
typedef struct _tMsgMnger_FsBoundary
{
	float32_t f32XY[2];
    PixelLabel eLabel;
    
}tMsgMnger_FsBoundary;
typedef struct _tMsgMnger_Freespace
{
	TimestampType u64Timestamp_us;
    tAPA_FunctionSts eApaFreespaceSts;
    tMsgMnger_FsBoundary sFsBoundary[FS_BOUND_NUM_MAX];
    
}tMsgMnger_Freespace;
typedef struct _tMsgMnger_PldInfo
{
	tObjProperty2D sObjProperty2D;
    tAPA_PldBerthAvailable ePldBerthAvailable;  // berth available status
    
}tMsgMnger_PldInfo;
typedef struct _tMsgMnger_VisionPLD
{
	TimestampType u64Timestamp_us;
    tAPA_VisionPldSts eApaVisionPldSts;
    tMsgMnger_PldInfo sVpldInfo[PLD_NUM_MAX_VPLD];  // vision PLD information
    
}tMsgMnger_VisionPLD;
typedef struct _tMsgMnger_UltrasonicPLD
{
	TimestampType u64Timestamp_us;
    tAPA_UlrasonicPldSts eApaUltrasonicPldSts;
    tMsgMnger_PldInfo sUpldInfo[PLD_NUM_MAX_UPLD];  // ultrasonic PLD information
    
}tMsgMnger_UltrasonicPLD;
typedef struct _tVehLocalisation
{
	float32_t f32X;
    float32_t f32Y;
    float32_t f32Z;
    float32_t f32Yaw;
    float32_t f32Pitch;
    float32_t f32Roll;
    float32_t f32ThetaErr;
    float32_t f32DistanceErr;
    tRequest eDataFusionErrActReq;
    
}tVehLocalisation;
typedef struct _tSlotLocation
{
	float32_t f32Confidence;
    float32_t f32Point1X;
    float32_t f32Point1Y;
    float32_t f32Point2X;
    float32_t f32Point2Y;
    float32_t f32Point3X;
    float32_t f32Point3Y;
    float32_t f32Point4X;
    float32_t f32Point4Y;
    
}tSlotLocation;
typedef struct _tEndPosition
{
	float32_t f32Confidence;
    float32_t f32EndPointX;
    float32_t f32EndPointY;
    float32_t f32EndPointTheta;
    
}tEndPosition;
typedef struct _tSectorInfo
{
	float32_t f32Distance;
    float32_t f32Confident;
    
}tSectorInfo;
typedef struct _tObjLocation
{
	float32_t f32Confidence;
    tSectorInfo sSect1;
    tSectorInfo sSect2;
    tSectorInfo sSect3;
    tSectorInfo sSect4;
    tSectorInfo sSect5;
    tSectorInfo sSect6;
    tSectorInfo sSect7;
    tSectorInfo sSect8;
    tSectorInfo sSect9;
    tSectorInfo sSect10;
    tSectorInfo sSect11;
    tSectorInfo sSect12;
    
}tObjLocation;
typedef struct _tMsgFusionRst
{
	TimestampType u64Timestamp;
    tVehLocalisation sVehLocalFused;
    tSlotLocation sSlotLocation;
    tEndPosition sTargetEndPostion;
    tObjLocation sVehPEBInfo;
    
}tMsgFusionRst;
typedef struct _DragParkingLot
{
	uint64_t u64Timestamp;  // us
    uint8_t u8PoseOrPoints;  // 0:pose 1:points
    uint8_t type;  // defined as enum DragParkingLotType
    uint8_t res[6];
    TPose stPose;
    float32_t width;
    float32_t depth;
    TPoint stPoints[4];
    
}DragParkingLot;
typedef struct _tMsgMnger_Localisition
{
	uint64_t u64Timestamp_us;  // unit: us
    tAPA_FunctionSts eApaLocalisationSts;  // see enum tAPA_FunctionSts 
    float32 f32x;  // unit: m
    float32 f32y;  // unit: m
    float32 f32z;  // unit: m
    float32 f32yaw;  // unit: rad
    float32 f32pitch;  // unit: rad
    float32 f32roll;  // unit: rad
    float32 speed;  // unit:  m/s
    float32 f32curvature;  // unit:  rad/m
    float32 f32track;  // uint: m
    uint8_t direction;  // see enum EVehDirection
    uint8_t res[3];
    
}tMsgMnger_Localisition;
typedef struct _ST_PATH_PLANNER_WAY_POINT
{
	float32 f32WayPointX;
    float32 f32WayPointY;
    float32 f32WayPointTheta;
    float32 f32WayPointCurvature;
    
}ST_PATH_PLANNER_WAY_POINT;
typedef struct _ST_PATH_PLANNER_TRAJ_POINT
{
	float32 f32WayPointX;
    float32 f32WayPointY;
    float32 f32WayPointTheta;
    float32 f32WayPointCurvature;
    float32 f32WayPointS;
    float32 f32WayPointV;
    float32 f32WayPointA;
    uint32 u32WayPointT;
    
}ST_PATH_PLANNER_TRAJ_POINT;
typedef struct _tMsgMnger_PPWayPoint_Rst
{
	uint64_t u64StartTime;
    uint16_t u16TotallyPathNum;
    uint16_t u16PathId;
    uint8_t u8Size;
    uint8_t u8Shift;
    uint8_t u8IsTraj;  // 1: traj,  0:waypoint
    uint8_t u8PldType;  // see DF_PLD_TYPE
    uint16_t u16res;  // no use!
    uint8_t u8PlanResult;  // EPlan Result
    uint8_t u8PebLevel;  // PEB level
    float32 f32PathLength;  // the length for current path segment.
    uint8_t u8VehicleActionRequest;  // see ECtrlAction
    uint8_t u8ParkHeadinFlag;  // 0 tailin || 1 headin !!!
    uint8_t u8VehicleActionReason;  // see ECtrlActionReason
    uint8_t u8SceneType;  // see tLSAD_FuncType
    uint8_t reserved[12];
    TPose stEndPose;
    ST_PATH_PLANNER_WAY_POINT stPathPosition[128];
    
}tMsgMnger_PPWayPoint_Rst;
typedef struct _tMsgMnger_PPTrajPoint_Rst
{
	uint64_t u64StartTime;
    uint16_t u16TotallyPathNum;
    uint16_t u16PathId;
    uint8_t u8Size;
    uint8_t u8Shift;
    uint8_t u8IsTraj;  // 1: traj,  0:waypoint
    uint8_t u8PldType;  // see DF_PLD_TYPE
    uint16_t u16res;  // no use!
    uint8_t u8PlanResult;  // EPlan Result
    uint8_t u8PebLevel;  // PEB level
    float32 f32PathLength;  // the length for current path segment.
    uint8_t u8VehicleActionRequest;  // see ECtrlAction
    uint8_t u8ParkHeadinFlag;  // 0 tailin || 1 headin !!!
    uint8_t u8VehicleActionReason;  // see ECtrlActionReason
    uint8_t u8SceneType;  // see tLSAD_FuncType
    uint8_t reserved[12];
    TPose stEndPose;
    ST_PATH_PLANNER_TRAJ_POINT stPathPosition[64];
    
}tMsgMnger_PPTrajPoint_Rst;
typedef struct _tMsgMnger_PathPlanner
{
	TimestampType u64Timestamp_us;
    tAPA_PathPlanSts eApaPathPlanSts;
    tMsgMnger_PPWayPoint_Rst stPathPlanData;
    
}tMsgMnger_PathPlanner;
typedef struct _tMsgMnger_PF
{
	TimestampType u64Timestamp_us;
    tAPA_CtrlSts eApaControlAlgoSts;  // Control algorithm status
    tCtrl_StateInfo stCtrl2PpStateInfo;
    tCtrl_LogInfo stCtrlLogInfo;
    
}tMsgMnger_PF;
typedef struct _tUSH_DistanceCell
{
	uint16 u16Distance_cm;  // ultrasonic distance，unit: (cm).
    uint8 u8Confidence;  // confidence of distance.
    uint8 u8Reserved;
    
}tUSH_DistanceCell;
typedef struct _tUSH_Peb92Distance
{
	tUSH_DistanceCell sDistanceCell[2U];  // PEB92 distance cell collection.
    
}tUSH_Peb92Distance;
typedef struct _tMsgMnger_PDC
{
	TimestampType u64Timestamp_us;
    tAPA_UltrasonicSts eApaPdcSts;  // Ultrasonic PDC/PEB status.
    uint16 u16Distance[US_IDX_NUM_MAX];  // PDC12 distance of front zone (8~11); rear zone (4~7); side zone (0~3), unit: (cm).
    uint16 u16PdcDistance[PDC_ZONE_NUM];  // PEB20 distance of front zone (0~7); rear zone (8~15); side zone (16~19); unit: (cm).
    uint16 u16SensorFailureBitMask;  // 12 ultrasonic sensors(bit0~11) failure bit mask, 0: not failure, 1: failure
    uint16 u16BlindZoneLockStsBitMask;  // PEB06 blind zone(Front/Rear/FRS/RRS/FLS/RLS) lock status bit mask , 0: unlocked, 1: locked.
    tPDC_AudioWarnLv ePdcAudioWarnLv[6U];  // PDC06 audio warning level. (Front/Rear/FRS/RRS/FLS/RLS)
    tUSH_Peb92Distance sPeb92Distance[PEB_ZONE_NUM];  // PEB92 distance of front zone (0~35); rear zone (36~71); side zone (RS=72~81,LS=82~91); unit: (cm).
    sint16 s16Meb100Distance_cm[MEB_ZONE_NUM];  // MEB100 distance of front zone (0~39); rear zone (40~79); side zone (RS=80~89,LS=90~99); unit: (cm).
    uint16 u16Peb04DistanceFrlr_cm[4U];  // PEB04 distance 4 zone. (Front/Rear/Left/Right)
    uint16 u16Pdc04DistanceFrlr_cm[4U];  // PDC04 distance 4 zone. (Front/Rear/Left/Right)
    uint16 u16Pdc20RectangleDistance_cm[50U];  // PDC20 rectangle zone distance.
    uint8 u8Reserved[372U];
    
}tMsgMnger_PDC;
typedef struct _ST_MCU2SOC_DATA
{
	tMsgMnger_EcuInfo sMsg_EcuInfo;  // size = 32 Byte
    tMsgMnger_VehicleInfo sMsg_VehicleInfo;  // size = 92 Byte
    tMsgMnger_ApaState sMsg_ApaState;  // size = 72 Byte
    tMsgMnger_RpaApp sMsg_RpaApp;  // size = 20 Byte
    tMsgMnger_UsObstacle sMsg_UsObstacle;  // size = 2044 Byte
    tMsgMnger_ObjDetection sMsg_ObjDetection;  // size = 2012 Byte
    tMsgMnger_Freespace sMsg_Freespace;  // size = 1932 Byte
    tMsgMnger_VisionPLD sMsg_VisionPLD;  // size = 812 Byte
    tMsgMnger_UltrasonicPLD sMsg_UltrasonicPLD;  // size = 412 Byte
    tMsgMnger_Localisition sMsg_Localisition;  // size = 64 Byte
    tMsgMnger_PathPlanner sMsg_PathPlanner;  // size = 2076 Byte
    tMsgMnger_PF sMsg_PF;  // size = 300 Byte
    tMsgMnger_PDC sMsg_PDC;  // size = 1528 Byte
    
}ST_MCU2SOC_DATA, *PST_MCU2SOC_DATA, ST_SOC2MCU_DATA, *PST_SOC2MCU_DATA;
typedef struct _PecpIntf_FsBoundary
{
	int16_t int16XY[2];
    
}PecpIntf_FsBoundary;
typedef struct _tMsgMnger_PecpIntf_Freespace
{
	uint64_t u64Timestamp_us;
    tAPA_FunctionSts eApaFreespaceSts;
    PecpIntf_FsBoundary sFsBoundary[172];
    uint8_t u8Labels[172];
    
}tMsgMnger_PecpIntf_Freespace;
typedef struct _tMsgMnger_CalibData
{
	TimestampType u64Timestamp_us;
    uint8_t u8Direction;
    uint8_t u8Mode;
    uint8_t u8GroupId;
    uint8_t u8Id;
    float32 f32Value[25];
    uint8_t res[16];
    
}tMsgMnger_CalibData;
typedef struct _tMsgMnger_HPPShakeHands
{
	TimestampType u64Timestamp_us;
    tLSAD_HandShakeSts eShakeHandsType;  // ShakeHandsSignal
    
}tMsgMnger_HPPShakeHands;
typedef struct _tSocUs_ObjDetection
{
	TimestampType u64Timestamp_us;
    tAPA_FunctionSts eObjectDetectionSts;
    tObjProperty2D sObjProperty2D[SOC_US_OD_NUM_MAX];
    uint8 reserved[1024];
    
}tSocUs_ObjDetection;
typedef struct _tSocUs_Freespace
{
	TimestampType u64Timestamp_us;
    tAPA_FunctionSts eApaFreespaceSts;
    tMsgMnger_FsBoundary sFsBoundary[SOC_US_FS_BOUND_NUM_MAX];
    uint8 reserved[4096];
    
}tSocUs_Freespace;
typedef struct _tSocUs_PDC
{
	TimestampType u64Timestamp_us;
    tAPA_UltrasonicSts eApaPdcSts;  // 超声PDC状态反馈
    uint16 u16Distance[US_IDX_NUM_MAX];  // distance of sensor detected first obstacle, unit: (cm).
    uint16 u16PdcDistance[SOC_US_PDC_ZONE_NUM];  // distance of front zone * 8; rear zone * 8; side zone * 4; unit: (cm).
    uint16 u16SensorFailureBitMask;  // ultrasonic sensors failure bit mask, 0: not failure, 1: failure
    uint8 reserved[2];
    uint8 reserved1[512];
    
}tSocUs_PDC;
typedef struct _tSocUs_UltrasonicPLD
{
	TimestampType u64Timestamp_us;
    tAPA_UlrasonicPldSts eApaUltrasonicPldSts;
    tMsgMnger_PldInfo sUpldInfo[SOC_US_PLD_NUM_MAX_UPLD];  // ultrasonic PLD information
    uint8 reserved[256];
    
}tSocUs_UltrasonicPLD;
typedef struct _tSocUsData
{
	tSocUs_ObjDetection sSocUs_ObjDetection;  // size = 2836 Byte
    tSocUs_Freespace sSocUs_Freespace;  // size = 10252 Byte
    tSocUs_PDC sSocUs_PDC;  // size = 592 Byte
    tSocUs_UltrasonicPLD sSocUs_UltrasonicPLD;  // size = 668 Byte
    
}tSocUsData;
typedef struct _PECP_TPoint
{
	float32_t x;
    float32_t y;
    
}PECP_TPoint;
typedef struct _tParkLotInfo
{
	PECP_TPoint stPLDPoint[4];  // center location in x, y relate to ego-car rear-axle center
    PECP_PLD_TYPE stType;  // plot type
    PECP_PLD_STATE stState;  // plot aviailability
    int32_t s32ParkLotID;  // plot id
    uint8_t u8confidence;  // [0, 100], 70 is good.
    
}tParkLotInfo;
typedef struct _tPecpPLDInfo
{
	tParkLotInfo stPLDs[20];  // plot information
    uint64_t u64Timestamp_us;  // time stamp in us
    int32_t s32SuggestParkID;  // recommend plot num
    tAPA_DataFusionSts eApaDataFusionSts;
    int32_t s32ParkNum;  // plot counts
    
}tPecpPLDInfo;
typedef struct _tPecpObjInfo
{
	PECP_TPoint stObjPoint;  // center location in x, y relate to ego-car rear-axle center
    float f32ObjTheta;  // object speed direction
    float f32ObjVx;  // object speed in m/s, current is not available
    float f32ObjVy;  // object speed in m/s, current is not available
    float f32ObjHeading;  // angle between object head and ego-car up direction(x -> up, y -> left)
    float f32ObjLength;  // object physical length
    float f32ObjWidth;  // object physical width
    float f32Conf;  // object confindence
    PECP_OBJECT_TYPES stObjType;
    uint32_t u32ObjId;  // object id
    
}tPecpObjInfo;
typedef struct _tPecpObstcalInfo
{
	tPecpObjInfo atObjList[20];  // object list
    uint64_t u64Timestamp_us;  // timestamp in us
    int32_t s32OdNum;  // avaliable object number, maxium is 20
    uint32_t u32CamID;  // camera id which detect object 0:front 1:rear 2:left 3:right
    uint32_t u32FrameID;  // frame id
    
}tPecpObstcalInfo;
typedef struct _Eol_Result_EP31_T
{
	uint64_t timeStamp;
    uint8_t u8calib_state;
    uint8_t au8data[3];
    
}Eol_Result_EP31_T;
typedef struct _stCFMMessageType_SOCMCU
{
	uint8_t cmd_type;
    uint8_t send_cnt;
    uint8_t result;
    uint8_t crc8;
    uint32_t total_cnt;
    uint32_t current_cnt;
    uint32_t package_length;
    uint8_t data[1024];
    
}stCFMMessageType_SOCMCU;
typedef struct _tMsgMnger_TextDisp
{
	TimestampType u64Timestamp_us;
    float f32TTCMinValue;  // （碰撞时间显示）周期型，单位s
    uint16_t u16FuncTextDisplay;  // 泊入/泊出/巡航/RA的提示词
    uint8_t u8SystemSts;  // 主状态机状态，参考tLSAD_SystemSts
    uint8_t u8MapSts;  // 建图状态，参考EMapCreatorState
    uint8_t u8LocSts;  // 定位状态，参考ELocStatus
    uint8_t u8FuncType;  // 功能类型，参考tLSAD_FuncSts
    uint8_t u8MEBStatus;  // 0：MEB_OFF；1：MEB_INIT；2：MEB_STANDBY；3：MEB_ACTIVE；4：MEB_FAIL
    uint8_t u8MapTextDisplay;  // 建图的提示词
    uint8_t u8LocTextDisplay;  // 定位的提示词
    uint8_t u8FuncBarPercent;  // 功能进度条%
    uint8_t u8FuncRemainDist;  // 剩余距离m
    uint8_t u8SupportParkDirect;  // 可泊出方向
    uint8_t u8VehDirect;  // 车辆档位，参考tVehiGear
    uint8_t Res[7];  // 预留位
    
}tMsgMnger_TextDisp;
typedef struct _tMsgMnger_Diag
{
	TimestampType u64Timestamp_us;
    uint8_t diag_info[1392];
    
}tMsgMnger_Diag;
typedef struct _tMsgMnger_LocSts
{
	uint64_t time_stamp;
    uint8_t loc_status;  // see ELocStatus
    uint8_t confidence;  // [0-100]
    uint8_t res[2];
    
}tMsgMnger_LocSts;
typedef struct _tMsgMnger_MapCreatorSts
{
	uint64_t time_stamp;
    int32_t session_id;
    float path_length;
    uint8_t mapping_state;  // see EMapCreatorState
    uint8_t res[3];
    
}tMsgMnger_MapCreatorSts;
typedef struct _tMsgMnger_PosSts
{
	uint64_t time_stamp;
    float record_distance;
    uint8_t pos_status;
    uint8_t res[3];
    
}tMsgMnger_PosSts;
typedef struct _TaskPeriodTestType
{
	uint32_t task_count;  // 任务计数
    uint64_t entry_time;  // 任务进入时间
    uint64_t exit_time;  // 任务退出时间
    uint32_t run_time;  // 任务运行时间
    uint32_t max_run_time;  // 最大运行时间
    uint32_t max_run_time_limit;  // 最大允许运行时间
    uint32_t execute_time;  // 执行任务时间
    uint32_t max_execute_time;  // 最大执行时间
    uint32_t max_execute_time_limit;  // 最大允许运行时间
    
}TaskPeriodTestType;
typedef struct _tMsgMnger_McuDebugInfo
{
	TimestampType u64Timestamp_us;
    TaskPeriodTestType task_info[15];
    
}tMsgMnger_McuDebugInfo;
typedef struct _tMsgMnger_PathSegment
{
	uint64_t u64TimeStamp;
    uint16_t u16PathId;
    uint8_t u8Shift;
    uint8_t u8PathNum;
    float f32PathDistance;
    TPose stPathPoint[64];
    
}tMsgMnger_PathSegment;
typedef struct _tMsgMnger_Tactical
{
	uint64_t u64TimeStamp;  // 时间戳
    uint16_t u16ParkoutDirecAvailable;  // 有效泊出方向
    uint16_t u16ParkoutDirecDefault;  // 推荐泊出方向
    uint8_t u8StatusParkin;  // Tactical状态
    uint8_t u8StatusParkout;  // Tactical状态
    uint8_t u8StatusCruise;  // Tactical状态
    uint8_t u8StatusRa;  // Tactical状态
    uint8_t res[4];  // 预留位
    
}tMsgMnger_Tactical;
typedef struct _tMsg_PdcDebug
{
	uint8_t Res[800];
    
}tMsg_PdcDebug;
extern tUInt32 g_Emos_delayCnt;
extern tUInt32 g_Emos_dropCnt;

extern Std_ReturnType Rte_Emos_Init();
extern tUInt64 Rte_Emos_GetSysTime();
extern tResult EMOS_timer_sync();

typedef struct _tRte_Null
{
    tUInt64 timeStamp;
	tUInt32 sequence;
	tUInt32 dirtyFlag;
	
}tRte_Header;

typedef struct _tRtemcuMcuInfo
{
    tRte_Header header;
	tMsgMnger_EcuInfo data;
}tRtemcuMcuInfo;
extern Std_ReturnType Rte_Write_MsgManager_McuInfo(const tMsgMnger_EcuInfo *msgMnger_McuInfo);
extern Std_ReturnType Rte_Read_MsgManager_McuInfo(tMsgMnger_EcuInfo *msgMnger_McuInfo);
typedef struct _tRtemcuMcuFreespace
{
    tRte_Header header;
	tMsgMnger_Freespace data;
}tRtemcuMcuFreespace;
extern Std_ReturnType Rte_Write_MsgManager_McuFreespace(const tMsgMnger_Freespace *msgMnger_McuFreespace);
extern Std_ReturnType Rte_Read_MsgManager_McuFreespace(tMsgMnger_Freespace *msgMnger_McuFreespace);
typedef struct _tRtemcuVehicleInfo
{
    tRte_Header header;
	tMsgMnger_VehicleInfo data;
}tRtemcuVehicleInfo;
extern Std_ReturnType Rte_Write_MsgManager_VehicleInfo(const tMsgMnger_VehicleInfo *msgMnger_VehicleInfo);
extern Std_ReturnType Rte_Read_MsgManager_VehicleInfo(tMsgMnger_VehicleInfo *msgMnger_VehicleInfo);
typedef struct _tRtemcuUsObstacle
{
    tRte_Header header;
	tMsgMnger_UsObstacle data;
}tRtemcuUsObstacle;
extern Std_ReturnType Rte_Write_MsgManager_UsObstacle(const tMsgMnger_UsObstacle *msgMnger_UsObstacle);
extern Std_ReturnType Rte_Read_MsgManager_UsObstacle(tMsgMnger_UsObstacle *msgMnger_UsObstacle);
typedef struct _tRtemcuObjDetection
{
    tRte_Header header;
	tMsgMnger_ObjDetection data;
}tRtemcuObjDetection;
extern Std_ReturnType Rte_Write_MsgManager_ObjDetection(const tMsgMnger_ObjDetection *msgMnger_ObjDetection);
extern Std_ReturnType Rte_Read_MsgManager_ObjDetection(tMsgMnger_ObjDetection *msgMnger_ObjDetection);
typedef struct _tRtemcuUltrasonicPLD
{
    tRte_Header header;
	tMsgMnger_UltrasonicPLD data;
}tRtemcuUltrasonicPLD;
extern Std_ReturnType Rte_Write_MsgManager_UltrasonicPLD(const tMsgMnger_UltrasonicPLD *msgMnger_UltrasonicPLD);
extern Std_ReturnType Rte_Read_MsgManager_UltrasonicPLD(tMsgMnger_UltrasonicPLD *msgMnger_UltrasonicPLD);
typedef struct _tRtemcuLocalisition
{
    tRte_Header header;
	tMsgMnger_Localisition data;
}tRtemcuLocalisition;
extern Std_ReturnType Rte_Read_MsgManager_Localisition(tMsgMnger_Localisition *msgMnger_Localisition);
typedef struct _tRtemcuPF
{
    tRte_Header header;
	tMsgMnger_PF data;
}tRtemcuPF;
extern Std_ReturnType Rte_Write_MsgManager_PF(const tMsgMnger_PF *msgMnger_PF);
extern Std_ReturnType Rte_Read_MsgManager_PF(tMsgMnger_PF *msgMnger_PF);
typedef struct _tRtemcuPDC
{
    tRte_Header header;
	tMsgMnger_PDC data;
}tRtemcuPDC;
extern Std_ReturnType Rte_Write_MsgManager_PDC(const tMsgMnger_PDC *msgMnger_PDC);
extern Std_ReturnType Rte_Read_MsgManager_PDC(tMsgMnger_PDC *msgMnger_PDC);
typedef struct _tRtemcuCTRLERRCODE
{
    tRte_Header header;
	tMsgMnger_CtrlErrCode data;
}tRtemcuCTRLERRCODE;
extern Std_ReturnType Rte_Write_MsgManager_CTRLERRCODE(const tMsgMnger_CtrlErrCode *msgMnger_CTRLERRCODE);
extern Std_ReturnType Rte_Read_MsgManager_CTRLERRCODE(tMsgMnger_CtrlErrCode *msgMnger_CTRLERRCODE);
typedef struct _tRtemcuSocInfo
{
    tRte_Header header;
	tMsgMnger_EcuInfo data;
}tRtemcuSocInfo;
extern Std_ReturnType Rte_Read_MsgManager_SocInfo(tMsgMnger_EcuInfo *msgMnger_SocInfo);
typedef struct _tRtemcuSocFreespace
{
    tRte_Header header;
	tMsgMnger_Freespace data;
}tRtemcuSocFreespace;
extern Std_ReturnType Rte_Read_MsgManager_SocFreespace(tMsgMnger_Freespace *msgMnger_SocFreespace);
typedef struct _tRtemcuPathPlanner
{
    tRte_Header header;
	tMsgMnger_PathPlanner data;
}tRtemcuPathPlanner;
extern Std_ReturnType Rte_Read_MsgManager_PathPlanner(tMsgMnger_PathPlanner *msgMnger_PathPlanner);
typedef struct _tRtemcuHMI
{
    tRte_Header header;
	tMsgMnger_Hmi data;
}tRtemcuHMI;
extern Std_ReturnType Rte_Read_MsgManager_HMI(tMsgMnger_Hmi *msgMnger_HMI);
typedef struct _tRtemcuRpaApp
{
    tRte_Header header;
	tMsgMnger_RpaApp data;
}tRtemcuRpaApp;
extern Std_ReturnType Rte_Read_MsgManager_RpaApp(tMsgMnger_RpaApp *msgMnger_RpaApp);
typedef struct _tRtemcuEOL_EP31
{
    tRte_Header header;
	Eol_Result_EP31_T data;
}tRtemcuEOL_EP31;
extern Std_ReturnType Rte_Read_MsgManager_EOL_EP31(Eol_Result_EP31_T *msgMnger_EOL_EP31);
typedef struct _tRtemcuPecetionObjects
{
    tRte_Header header;
	tPecpObstcalInfo data;
}tRtemcuPecetionObjects;
extern Std_ReturnType Rte_Read_MsgManager_PecetionObjects(tPecpObstcalInfo *msgMnger_PecetionObjects);
typedef struct _tRtemcuPeceptionPld
{
    tRte_Header header;
	tPecpPLDInfo data;
}tRtemcuPeceptionPld;
extern Std_ReturnType Rte_Read_MsgManager_PeceptionPld(tPecpPLDInfo *msgMnger_PeceptionPld);
typedef struct _tRtemcuVisionPLD
{
    tRte_Header header;
	tMsgMnger_VisionPLD data;
}tRtemcuVisionPLD;
extern Std_ReturnType Rte_Write_MsgManager_VisionPLD(const tMsgMnger_VisionPLD *msgMnger_VisionPLD);
extern Std_ReturnType Rte_Read_MsgManager_VisionPLD(tMsgMnger_VisionPLD *msgMnger_VisionPLD);
typedef struct _tRtemcuApaState
{
    tRte_Header header;
	tMsgMnger_ApaState data;
}tRtemcuApaState;
extern Std_ReturnType Rte_Write_MsgManager_ApaState(const tMsgMnger_ApaState *msgMnger_ApaState);
extern Std_ReturnType Rte_Read_MsgManager_ApaState(tMsgMnger_ApaState *msgMnger_ApaState);
typedef struct _tRtemcuModifyCalib
{
    tRte_Header header;
	tMsgMnger_CalibData data;
}tRtemcuModifyCalib;
extern Std_ReturnType Rte_Read_MsgManager_ModifyCalib(tMsgMnger_CalibData *msgMnger_ModifyCalib);
typedef struct _tRtemcuMcuCalib
{
    tRte_Header header;
	tMsgMnger_CalibData data;
}tRtemcuMcuCalib;
extern Std_ReturnType Rte_Write_MsgManager_McuCalib(const tMsgMnger_CalibData *msgMnger_McuCalib);
extern Std_ReturnType Rte_Read_MsgManager_McuCalib(tMsgMnger_CalibData *msgMnger_McuCalib);
typedef struct _tRtemcuHPPShake
{
    tRte_Header header;
	tMsgMnger_HPPShakeHands data;
}tRtemcuHPPShake;
extern Std_ReturnType Rte_Write_MsgManager_HPPShake(const tMsgMnger_HPPShakeHands *msgMnger_HPPShake);
extern Std_ReturnType Rte_Read_MsgManager_HPPShake(tMsgMnger_HPPShakeHands *msgMnger_HPPShake);
typedef struct _tRtemcuMCU2SOC_ConfigSRV
{
    tRte_Header header;
	stCFMMessageType_SOCMCU data;
}tRtemcuMCU2SOC_ConfigSRV;
extern Std_ReturnType Rte_Write_MsgManager_MCU2SOC_ConfigSRV(const stCFMMessageType_SOCMCU *msgMnger_MCU2SOC_ConfigSRV);
extern Std_ReturnType Rte_Read_MsgManager_MCU2SOC_ConfigSRV(stCFMMessageType_SOCMCU *msgMnger_MCU2SOC_ConfigSRV);
typedef struct _tRtemcuSOC2MCU_ConfigSRV
{
    tRte_Header header;
	stCFMMessageType_SOCMCU data;
}tRtemcuSOC2MCU_ConfigSRV;
extern Std_ReturnType Rte_Read_MsgManager_SOC2MCU_ConfigSRV(stCFMMessageType_SOCMCU *msgMnger_SOC2MCU_ConfigSRV);
typedef struct _tRtemcuMCU2SOC_DIAG
{
    tRte_Header header;
	tMsgMnger_Diag data;
}tRtemcuMCU2SOC_DIAG;
extern Std_ReturnType Rte_Write_MsgManager_MCU2SOC_DIAG(const tMsgMnger_Diag *msgMnger_MCU2SOC_DIAG);
extern Std_ReturnType Rte_Read_MsgManager_MCU2SOC_DIAG(tMsgMnger_Diag *msgMnger_MCU2SOC_DIAG);
typedef struct _tRtemcuSOC2MCU_DIAG
{
    tRte_Header header;
	tMsgMnger_Diag data;
}tRtemcuSOC2MCU_DIAG;
extern Std_ReturnType Rte_Read_MsgManager_SOC2MCU_DIAG(tMsgMnger_Diag *msgMnger_SOC2MCU_DIAG);
typedef struct _tRtemcuMCUHMITextDisp
{
    tRte_Header header;
	tMsgMnger_TextDisp data;
}tRtemcuMCUHMITextDisp;
extern Std_ReturnType Rte_Write_MsgManager_MCUHMITextDisp(const tMsgMnger_TextDisp *msgMnger_MCUHMITextDisp);
extern Std_ReturnType Rte_Read_MsgManager_MCUHMITextDisp(tMsgMnger_TextDisp *msgMnger_MCUHMITextDisp);
typedef struct _tRtemcuMsgMnger_PecpIntf_Freespace
{
    tRte_Header header;
	tMsgMnger_PecpIntf_Freespace data;
}tRtemcuMsgMnger_PecpIntf_Freespace;
extern Std_ReturnType Rte_Read_MsgManager_MsgMnger_PecpIntf_Freespace(tMsgMnger_PecpIntf_Freespace *msgMnger_MsgMnger_PecpIntf_Freespace);
typedef struct _tRtemcuSOC2MCU_LocSts
{
    tRte_Header header;
	tMsgMnger_LocSts data;
}tRtemcuSOC2MCU_LocSts;
extern Std_ReturnType Rte_Read_MsgManager_SOC2MCU_LocSts(tMsgMnger_LocSts *msgMnger_SOC2MCU_LocSts);
typedef struct _tRtemcuSOC2MCU_MapCreator
{
    tRte_Header header;
	tMsgMnger_MapCreatorSts data;
}tRtemcuSOC2MCU_MapCreator;
extern Std_ReturnType Rte_Read_MsgManager_SOC2MCU_MapCreator(tMsgMnger_MapCreatorSts *msgMnger_SOC2MCU_MapCreator);
typedef struct _tRtemcuSOC2MCU_PosSts
{
    tRte_Header header;
	tMsgMnger_PosSts data;
}tRtemcuSOC2MCU_PosSts;
extern Std_ReturnType Rte_Read_MsgManager_SOC2MCU_PosSts(tMsgMnger_PosSts *msgMnger_SOC2MCU_PosSts);
typedef struct _tRtemcuMCU2SOC_McuLog
{
    tRte_Header header;
	tMsgMnger_McuDebugInfo data;
}tRtemcuMCU2SOC_McuLog;
extern Std_ReturnType Rte_Write_MsgManager_MCU2SOC_McuLog(const tMsgMnger_McuDebugInfo *msgMnger_MCU2SOC_McuLog);
extern Std_ReturnType Rte_Read_MsgManager_MCU2SOC_McuLog(tMsgMnger_McuDebugInfo *msgMnger_MCU2SOC_McuLog);
typedef struct _tRtemcuDragPL
{
    tRte_Header header;
	DragParkingLot data;
}tRtemcuDragPL;
extern Std_ReturnType Rte_Write_MsgManager_DragPL(const DragParkingLot *msgMnger_DragPL);
extern Std_ReturnType Rte_Read_MsgManager_DragPL(DragParkingLot *msgMnger_DragPL);
typedef struct _tRtemcuPathSegment
{
    tRte_Header header;
	tMsgMnger_PathSegment data;
}tRtemcuPathSegment;
extern Std_ReturnType Rte_Read_MsgManager_PathSegment(tMsgMnger_PathSegment *msgMnger_PathSegment);
typedef struct _tRtemcuTactical
{
    tRte_Header header;
	tMsgMnger_Tactical data;
}tRtemcuTactical;
extern Std_ReturnType Rte_Read_MsgManager_Tactical(tMsgMnger_Tactical *msgMnger_Tactical);
typedef struct _tRtemcuPdcDebug
{
    tRte_Header header;
	tMsg_PdcDebug data;
}tRtemcuPdcDebug;
extern Std_ReturnType Rte_Write_MsgManager_PdcDebug(const tMsg_PdcDebug *msgMnger_PdcDebug);
extern Std_ReturnType Rte_Read_MsgManager_PdcDebug(tMsg_PdcDebug *msgMnger_PdcDebug);
extern tUInt8 Rte_Register_Callback(MsgPreOperation pCb, tUInt8 portID);
#endif // _EMOS_RTE_HEADER_
