#ifndef CTRL_STRUCT_H_
#define CTRL_STRUCT_H_

#include "adas_project_input.h"
#include "ctrl_enum.h"
#include "math.h"
#include "adas_calibration_data.h"
#include "ctrl_controllers.h"
#include "adas_struct.h"

//#define E_OK 0
#define E_ERR 1

//#define Ultrasonic Direction
#define PEB_FRONT_LEFT_1_DIS								 0
#define PEB_FRONT_LEFT_2_DIS								 1
#define PEB_FRONT_LEFT_3_DIS								 2
#define PEB_FRONT_LEFT_4_DIS								 3
#define PEB_REAR_LEFT_1_DIS								   4
#define PEB_REAR_LEFT_2_DIS								   5
#define PEB_REAR_LEFT_3_DIS								   6
#define PEB_REAR_LEFT_4_DIS								   7
#define PEB_SIDE_FRONT_LEFT_DIS							 8
#define PEB_SIDE_FRONT_RIGHT_DIS						 9
#define PEB_SIDE_REAR_LEFT_DIS							 10
#define PEB_SIDE_REAR_RIGHT_DIS							 11

//#define New Ultrasonic Direction
#define PEB_FRONT_LEFT_START								 0
#define PEB_FRONT_LEFT_END								   7
#define PEB_REAR_RIGHT_START								 8
#define PEB_REAR_RIGHT_END								   15
#define PEB_SIDE_FRONT_LEFT							     18
#define PEB_SIDE_FRONT_RIGHT						     16
#define PEB_SIDE_REAR_LEFT						       19
#define PEB_SIDE_REAR_RIGHT							     17



    /*  =====================================================================
    *                            Common
    *   ===================================================================*/


typedef struct _CTRL_LPF_PARA_
{
    float f32LPF_den_2;
    float f32LPF_num_1;
    float f32LPF_num_2;

    float f32LPF_filter_yk_1;
    float f32LPF_filter_yk;

    float f32LPF_yk;
    float f32LPF_yk_1;
}tCtrlLowPassFilterPara;



    /*	=====================================================================
    *						   External Input
    *	===================================================================*/

// typedef struct _CHASSIS2CTRL_INFO
// {
// 	float   f32SteerWheelAngle;
// 	float   f32SteerRotationSpd;
// 	float   f32VehicleSpeed;            // vehicle speed from ESC.
//     float   f32VehicleSpeedImpulse;     // vehicle speed calculated by impulse, which is also from ESC.

// 	uint16_t u16RLWheelImpulse;
// 	uint16_t u16RRWheelImpulse;
// 	uint16_t u16FRWheelImpulse;
// 	uint16_t u16FLWheelImpulse;

//     uint16_t u16RLWheelImpulseRecord;
// 	uint16_t u16RRWheelImpulseRecord;
// 	uint16_t u16FRWheelImpulseRecord;
// 	uint16_t u16FLWheelImpulseRecord;
// 	uint8_t u2WheelDirRL:2;
// 	uint8_t u2WheelDirRR:2;
// 	uint8_t u2WheelDirFR:2;
// 	uint8_t u2WheelDirFL:2;
// 	tCtrlVehGear eCtrlVehGear;//eCtrlVehGear

// 	uint8_t u8esc_status;
// 	uint8_t u8eps_status;
// 	uint8_t u8vcu_status;
// 	uint8_t u8gearbox_status;
// 	uint8_t u8DifficlutRoad;
//     uint8_t u8VehStandStill;
//     tActiveSts eBrakeActiveStatus;

//     float  f32VehSpdImpFiltered;
//     tCtrlLowPassFilterPara  stVehSpdImpLPF;

// 	uint8_t u8res[1];
// }tChassisToCtrlInfo;

typedef struct _PATH_PLANNER_DATA_TAG_
{
    float                 f32WayPointX;     //First x length, theta shift, y (distance from two point)30cm and curvature reserved  (1:P, 2:R, 3:N, 4:D)
    float                 f32WayPointY;              
    float                 f32WayPointTheta;         
    float                 f32WayPointCurvature;
    float                 f32WayPointS;
    float                 f32WayPointV;
    float                 f32WayPointA;
    uint32_t              u32WayPointT;
}tPathPlannerData;


typedef struct _CTRL_VEHICLE_POSITION_TAG_
{
    uint64_t   u64Timestamp;     // ns
    float32_t  f32X_Coor;        // x coordinate of vehicle position,(m)
    float32_t  f32Y_Coor;        // y coordinate of vehicle position,(m)
    float32_t  f32Theta;         // heading degree of vehicle, [-PI, PI]
    float32_t  f32Track;         // distance from origin to the current position
}tCtrlVehiclePosition;

typedef struct _PATH_PLANNER_INFO_
{
    // --- Raw data from path planner 
    uint64_t    u64Timestamp;  
    tAPA_PathPlanSts ePathPlanSts;  
    uint16_t    u16TotallyPathNum;
    uint16_t    u16PathId;
    uint8_t     u8PointNum;
    uint8_t     u8Shift;
    uint8_t     u8IsTraj;
    tDF_PL_TYPE ePldType;
    uint8_t     u8PlanResult;
    uint8_t     u8PebLevel;
    float       f32PathLength;    
    tCtrlVehiclePosition      stFinalLocation;
    uint64_t    u64StartTime;

    tPathPlannerData  stPathData[MAX_POINT_NUM];	

    // --- path date processing
    tDF_PL_TYPE eCtrlPldType;
    uint8_t     u8LastPointId;
    uint8_t     u8NewPathFlag;
    int8_t      i8CtrlGearFactor;
    uint8_t     u8LastPathFlag;
    uint8_t     u8NoNewPathFlag;
    uint8_t     u8PathInvalidFlag;
    uint8_t     u8KappaSuddenChangeFlag;
    uint8_t     u8KappaSuddenChangePointId;

    //pause flag
    uint8_t     u8PauseFlag;
    uint8_t     u8VehicleActionRequest; //see ECtrlAction
    ECtrlActionReason      u8VehicleActionReason;

}tPathPlannerInfo;

typedef struct _CTRL_PREDICT_DR_POSE_
{
    float          f32FutureDRPoseX;          
    float          f32FutureDRPoseY;           
    float          f32FutureDRTheta;
    float          f32TimeGap;
}tCtrlPredictDrPose;       

typedef struct _CTRL_VEH_SPEED_
{
    float          f32TimeGap;
    float          f32VehSpeed;
}tCtrlVehSpeed;

typedef struct _CTRL_VEH_POSE_
{
    tCtrlVehiclePosition 	  stCurrentPos;
    tCtrlVehiclePosition      stPreviousPos;
    tCtrlPredictDrPose        stPredictPos;
    tCtrlVehiclePosition      stSelectedPos;
}tCtrlVehPose;

typedef struct _CTRL_USS_INFO_
{
    uint16_t  u16UssOn;
    uint16_t  u16UssSideOn;
    uint16_t  u16_PEB_Record_data[PDC_ZONE_NUM];
    boolean_T bPebStopFlagDirection[PDC_ZONE_NUM];
    boolean_T bPebStopFlagFinal;
    float32_t f32WhlAngDeg;
    float32_t f32StopRelativeA;
    float32_t f32ReduceRelativeA;
    float32_t f32ActuatReactTime;
    float32_t f32SafeDit;
    float32_t f32SideSafeDit;
    float32_t f32PEBInputDistance[PDC_ZONE_NUM];
    float32_t f32PebDistance[PDC_ZONE_NUM];
    float32_t f32PebDisFactor[PDC_ZONE_NUM];
    float32_t f32PebDisAngle[PDC_ZONE_NUM];
    float32_t f32PebTTCTime[PDC_ZONE_NUM];
    float32_t f32PebTTCSpd[PDC_ZONE_NUM];
    float32_t f32TTCSafetyTime;
    float32_t f32TTCMinTime;
    float32_t f32TTCPebDistance;
    float32_t f32UssMinDistance;
    float32_t f32PebMinSpdDistance;
    float32_t f32VehCurvature;
    uint8_t  u8PebUssNumber;
    uint8_t   u8PebUssTTCSpdNumber;
    float32_t f32PebDistanceFinal;
    uint8_t   bPEBUssNumberEnbl[PDC_ZONE_NUM];

    uint16_t u16_USS_mem_info[12][3];

    uint8_t  u8_Subarea_AEB_Sig[10];
    uint16_t u8_Subarea_AEB_Counter[10];
    uint8_t  u8_Subarea_AEB_Stage;

    uint8_t  u8_Subarea_gear_mem;
    uint16_t u16_Subarea_AEB_two_count;
    uint8_t  u8_Subarea_AEB_STOP_flag;

    uint8_t  u8_USAP_AEB_front_flag;
    uint8_t  u8_USAP_AEB_rear_flag;
    int8_t   i8_USAP_gear_now;

    float    f32_USAP_guide_speed;
    float    f32_USAP_guide_acce;

    uint8_t  u8_USAP_force_quit_flag;
    uint16_t u16PebDistanceOriginal[US_IDX_NUM_MAX];
    uint16_t u16PebDistanceConverted[PDC_ZONE_NUM];
    boolean bBlindAreaObstacle[PDC_ZONE_NUM];
	uint16_t u16FL_Sector_Dist;
	uint16_t u16FML_Sector_Dist;
	uint16_t u16FMR_Sector_Dist;
	uint16_t u16FR_Sector_Dist;
	uint16_t u16RL_Sector_Dist;
	uint16_t u16RML_Sector_Dist;
	uint16_t u16RMR_Sector_Dist;
	uint16_t u16RR_Sector_Dist;
	uint16_t u16FSL_Sector_Dist;
	uint16_t u16FSR_Sector_Dist;
	uint16_t u16RSL_Sector_Dist;
	uint16_t u16RSR_Sector_Dist;

}tCtrlUssInfo;

typedef struct _CTRL_FUNC_FSM_INFO_
{
    tLSAD_SystemSts eLsadSystemSts;
    tLSAD_SystemSts eLsadSystemStsPrev;
    tLSAD_SystemSubSts eLsadSystemSubSts;
    tLSAD_FuncType eLsadFuncType;
    tLSAD_DriverCtrlCommand  eLsadDriverCtrlCommand;
    tCtrlParkOutType eCtrlParkOutType;
    uint8_t u8LsadStSResetPEB;
}tCtrlFuncFsmInfo;





    /*	=====================================================================
    *						  Ctrl Module Variable
    *	===================================================================*/

typedef struct _CTRL_TRAP_DETECT_INFO_
{
   uint16_t    u16PathIDRecord;
   uint16_t    u16Counter;

   uint8_t     u8RecordFlag;
   uint8_t     u8AEBTypeRecord;
   uint8_t     u8PathGearRecord;
   uint8_t     u8GearShiftFlag;

   uint8_t     u8VehGearRecord;
   uint8_t     u8Res[3];

}tCtrlTrapDectectInfo;

typedef struct _Ctrl_PEB_INFO_
{
    float f32PebOriginDisMax;
    float f32PebDisMin[PDC_ZONE_NUM];
    float f32PebDisMax[PDC_ZONE_NUM];
    float f32PebDisFrontMin;
    float f32PebDisRearMin;
    float f32PebDisLeftRightFrontMin;
    float f32PebDisLeftRightRearMin;
    float f32PebDisFrontMax;
    float f32PebDisRearMax;
    float f32PebDisLeftRightFrontMax;
    float f32PebDisLeftRightRearMax;

    float f32speed;
    float f32ThetaErr;
    float f32LatDisErr;

    uint16_t u16USSRearLeft;
    uint16_t u16USSRearRight;

    uint16_t u16distance;
    uint8_t  u8USS_dis;
    uint8_t  u8USS_Count;

    uint8_t  u8PebHappened;
    uint8_t  u8USS_flag_Front;
    uint8_t  u8USS_flag_Rear;
    float32_t f32PebSpeed;
    float32_t f32PebAcce;
    
    uint8_t u8USS_flag_Left_Front_Side;
    uint8_t u8USS_flag_Left_Rear_Side;
    uint8_t u8USS_flag_Right_Front_Side;
    uint8_t u8USS_flag_Right_Rear_Side;

    uint8_t  u8PebLevel;
    uint8_t  u8PebDir;
    uint8_t  u8res[2];
}tCtrlPebInfo;   

typedef enum {
  CONTROL_CHOCKED_NO = 0,
  CONTROL_CHOCKED_VERTICAL = 1,
  CONTROL_CHOCKED_HORIZONTAL = 2,
  CONTROL_CHOCKED_ROLL_BACK = 3,
}tCtrlChockedTypeFlag;

typedef struct _CTRL_COMMON_INFO__
{
    // --- Ctrl Status
    tCtrl_Module_Status eCtrlFuncStatus;
    tCtrl_Module_Status eCtrlFuncStatusPrev;
    tCtrl_Internal_FuncType eCtrlFuncType;
    
    // --- Finish path
    ECtrlState u8CtrlState;
    ECtrlSubstate u8CtrlSubstate;
    ECtrlAction u8DecisionRecord;
    
    // --- Request new path
    uint16_t    u16CurrentPathID;
    uint16_t    u16ReqPathID;
    uint16_t    u16WaitNewPathCnt;
    uint16_t    u16RecPathID;
    uint8_t     u8WaitNewPathTimeoutFlag;
    uint8_t     u8ReplanReq;
    EReplanType eReplanReqType;
    uint16_t    u16WaitReplanResultCnt;
    tCtrlReplanResult   eCtrlReplanResult;
    uint8_t     u8ExpectReplanGear;
    uint8_t     u8WaitReplanTimeoutFlag;    // to delete

    // --- Vehicle on Path Info
    uint8_t     u8NearestPointIndexCurPose;
    uint8_t     u8NearestPointIndexCurPosePre;
    uint8_t     u8NearestPointIndexSelectedPose;
    uint8_t     u8NearestPointIndexTime;
    int8_t      i8PathStartPosIndicator;
    float       f32DistanceLeftRaw;
    float       f32DistanceLeft;
    uint8_t     u8FrontPointIndex;
    uint8_t     u8BehindPointIndex;
    float       f32FrontPointDistance;
    float       f32BehindPointDistance;

    uint8_t     u8FakeRoadPathId;

    float32_t   f32PointDisToEnd[MAX_POINT_NUM];

    // --- Detection of PEB, finish, chock, trap 
    tCtrlTrapDectectInfo  stTrapDectect;
    tCtrlPebInfo          stCtrlPebInfo;
    tVehActualGear          eGearRecord;
    uint8_t     u8ConflictGearFlag;
    uint8_t     u8PpGearAchieved;
    uint8_t     u8PebParkCompleteFlag;
    uint8_t     u8PauseFlag;
    uint16_t    u16TrappedTime1;
    uint16_t    u16TrappedTime2;
    uint16_t    u16TrappedTime3;
    uint16_t    u16RaTerminate;
    uint8_t     u8CtrlTrapFlag;
    uint16_t    u16CtrlChockCount;
    uint8_t     u8CtrlVerticalChockedFlag;
    uint8_t     u8CtrlHorizontalChockedFlag;
    tCtrlChockedTypeFlag  eCtrlChockedTypeFlag;
    uint8_t     u8CtrlChockCompleteFlag;
    uint16_t    u16CtrlUnknownStopCount;
    uint8_t     u8CtrlUnknownStopFlag;
    uint8_t     u8FinishActionFlag;
    uint8_t     u8FixPGearFlag;
    tCtrlFinishType     eCtrlFinishType;        // u8CtrlFinishFlag;
    uint8_t     u8StandStillFlag;
    uint8_t     u8VehStopByTravelDisFlag;
    tVehicleDir  eVehicleDir;
    tAccelerationMode   eAcclerationMode;
    float       f32RecordedDistanceTravel;



    uint16_t u16RecordedPathID;
    uint8_t  u8RecordedTargetBehindID;
    uint8_t  u8RecordedTargetFrontID;

    uint8_t  u8TargetBehindID;
    uint8_t  u8TargetFrontID;

    float f32RecordedTime;
    float f32TargetTime;

    uint8_t  bWhlSpdDirectOppositeGear;
    float f32VehSpdDirectKph;
}tCtrlCommonInfo;




typedef struct _CTRL_SPEED_PROFILE_TAG_
{
   float f32MaxSpeed;
   float f32InitSpeed;
   float f32DecelDis;
   float f32StopDis;
}tCtrlSpeedProfile;

typedef struct _ST_CTRL_LONGI_VAR_
{
    tCtrlSpeedProfile stSpeedProfile;
    tCtrlSpeedTrapezoidPhase eSpeedPhase;

    float f32TargetVehSpeed;
    float f32PPTargetVehSpeed;
    uint8_t u8CurrentPathFinishedFlag;
    uint8_t u8CurrentPathFinishedFlagPrev;
    uint16_t u16EmergStopStableCnt;
    uint8_t u8EmergStoppedFlag;
    uint16_t u16StopSteeringCnt;
    uint8_t u8StopSteeringFinishWaitFlag; 

    float f32TrajTargetAcce;
    float arrVehSpeedHistory[10];
    float f32AverageSpeed;
    uint8_t u8LongiCtrlStatus;
    uint16_t u16AcceCount;
    uint16_t u16DeceCount;
    uint16_t u16RemainCount1;
    uint16_t u16RemainCount2;
    float f32LongKp;
    float f32LongKi;
    float f32LongKiAntiWindup;
    float f32LongKd;
    float f32KiIntegralSum;
    float f32TargetDiffAcce;
    float f32TargetPAcce;
    float f32TargetAcce;
    float f32TargetTq;
    uint8_t u8VehSpeedHumpTime;

    float f32TargetStopDistance;
    float f32TotalStopDistance;
    tRequest eStandStillReq;
    tRequest eAEBFlag;

    tVehActualGear eGearReq;
    float f32SpeedGainFactor;

    tVehActualGear eRecordPebVehGear;
    uint8_t u8PEBGearRecordFlag;
    uint8_t u8FuelOilSpeedReachFlag;
    uint8_t u8FuelOilDecelLevel;
    uint8_t u8FinishWaitDelay;
}tCtrlLongiInfo;  

typedef struct _ST_CTRL_LAT_ERR_
{
    float   f32ErrDistRaw;
    float   f32ErrDistFiltered;
    float   f32ErrDistFilteredPrev;

    float   f32ErrThetaRaw;
    float   f32ErrThetaFiltered;
    float   f32ErrThetaFilteredPrev;

    float   f32SinglePointTargetCurvatureRaw;
    float   f32SinglePointTargetCurvatureFiltered;
    float   f32MultiPointTargetCurvatureRaw;
    float   f32MultiPointTargetCurvatureFiltered;

    float   f32ErrDotDistRaw;
    float   f32ErrDotThetaRaw;
}tCtrlLatErr;


typedef struct _ST_CTRL_LAT_RESULT_
{
    uint16_t       u16PreviewPathPointId;      // Not in use, it equals to NearestPoint + LookAheadPoint
    float          f32LookAheadCurvature;      // Not in use. 
    float          f32FeedforwardAngle;

    float          f32FeedbackAngleRaw;
    float          f32FeedbackAngleFiltered;

    float          f32TargetWheelAngle;
    float          f32WheelToSteerRatio;
    float          f32TargetSteerAngleRaw;
    float          f32TargetSteerAngleFiltered;
    float          f32TargetSteerAngleLimited;

    float          f32LatSteerGap;
    float          f32WheelToSteerRatioFactor;

    float          f32PauseMemorySteer;
    uint8_t        u8PauseMemorySteerLockFlag;

    uint8_t        u8res[2];
}tCtrlLatResult;

typedef struct _ST_CTRL_LAT_CURVE_
{
    float       f32CurveStages[4][5];
    float       f32SteerRatioStage[4][5];
}tCtrlLatCurve;

typedef struct _ST_CTRL_LAT_VAR_
{
    tCtrlLatErr         stCtrlLatErr;
    
    tCtrlPurePursuit    stCtrlPurePursuit;
    tCtrlStanley        stCtrlStanley;
    tCtrlPid            stCtrlPid;
    tCtrlLqr            stCtrlLqr;
    tCtrlMpc            stCtrlMpc;

    tCtrlLowPassFilterPara stCtrlLpfDistErr;
    tCtrlLowPassFilterPara stCtrlLpfThetaErr;
    tCtrlLowPassFilterPara stCtrlLpfCurvatureSinglePoint;
    tCtrlLowPassFilterPara stCtrlLpfCurvatureMultiPoint;
    tCtrlLowPassFilterPara stCtrlLpfLat;
    tCtrlLowPassFilterPara stCtrlLpfTargetLatSteer;

    tCtrlLatResult      stCtrlLatResult;
    tCtrlLatCurve       stCtrlLatCurve;

    uint8 u8ReleaseTirePressurePhase;

}tCtrlLatInfo;  



typedef enum
{
    STANDBY = 0,
    RUNNING = 1,
    STOP    = 2
}CONTROLSTATE;

typedef enum
{
    NON = 0,
    COMPLETE = 1
}CONTROLTASK;

typedef enum 
{
    CRUISE_STOP_STEERING,
    CRUISE_RUNNING,
    CRUISE_STOP,
    CRUISE_EMERGENCY_STOP,
}tCtrlCruiseLonStatus;

typedef struct
{
    tCtrlCruiseLonStatus m_state;
    CONTROLTASK  m_task;

    bool         m_IsValidTraj;
    uint8_t      m_GearTrajReq;
    float32_t    m_SteerTrajReq;
    float32_t    m_SpeedTrajReq;
    float32_t    m_AccTrajReq;
    uint8_t      m_FunctionType;

    float32_t    m_CarSpeed;
    uint8_t      m_CarGear;
    uint8_t      m_CarBreak;
    float32_t    m_CarSteer;
    float32_t    m_CarSteerPre;
    float32_t    m_ReminDis;

    float32_t    m_StopSpeed;
    float32_t    m_StopSteerGap;

    uint8_t      m_GearToVcu; //P R N D
    float32_t    m_SpeedToESC;
    float32_t    m_AccelToESC;
    float32_t    m_SteerToEPS;

    uint8_t      m_EMGFlag;
    uint8_t      m_PathFinishFlag;
    uint8_t      m_u8PhaseLocation;
}tStateMachine;


typedef struct
{
    float f32u1;
    float f32y1;
    float f32Ts;
    float f32Bw;  //unit:hz
}tLowPassPars;







    /*	=====================================================================
    *						    External Output
    *	===================================================================*/

typedef struct _CTRL2CHASSIS_INFO_
{
    // --- Longitudinal
    float f32CtrlReqSpeedUnlimited;
    float f32CtrlReqSpeedLimited;
    float f32CtrlReqSpeedRateLimited;
    float f32CtrlReqSpeed;
    float f32CtrlReqSpeedPrev;
    float f32CtrlReqAccelUnlimited;
    float f32CtrlReqAccelLimited;
    float f32CtrlReqAccelRateLimited;
    float f32CtrlReqAccel;
    float f32CtrlReqAccelPrev;
    float f32CtrlReqTqUnlimited;
    float f32CtrlReqTqLimited;
    float f32CtrlReqTq;
    float f32CtrlReqStopDistanceUnlimited;
    float f32CtrlReqStopDistanceLimited;
    float f32CtrlReqStopDistance;
    tRequest eStandStillReq;
    tRequest eAEBFlag;

    // --- Lateral
    float f32CtrlReqSteerUnlimited;
    float f32CtrlReqSteerMinmaxLimited;
    float f32CtrlReqSteerRateLimited;
    float f32CtrlReqSteer;
    float f32CtrlReqSteerPrev;

    // --- Others
    tVehActualGear eGearReq;
    tHandshakeTypeRq eHandshakeReq;

}tCtrlToChassisInfo;

typedef struct _CTRL_TO_FUNC_STATE_MACHINE_
{
    tAPA_CtrlSts eCtrlStatus;
    tAPA_CtrlReqStatus stCtrlReqSts;
    uint8_t     u8PausePressDurationCnt;

}tCtrlToFuncStateMachine;















    /*	=====================================================================
    *				Others.
    *	===================================================================*/

typedef struct 
{
    float   f32SteerOutput;
    float   f32DrThetaTrackMem;
    float   f32DrThetaTrackTemp;

    uint8_t u8UssPkoutExternalActive;
    uint8_t u8UssPkoutDirGet;

    uint8_t u8PkoutWithoutPpPebSig;
    uint8_t u8PkoutWithoutPpPebActiveCount;
    uint8_t u8PkoutWithoutPpInitOkSig;
    uint8_t u8PkoutDir;
    uint8_t u8PkoutGearInput;
    uint8_t u8FuncActiveSig;

    uint8_t u8UssPkoutQuitFlag;
    uint8_t u8UssInitCount;
    uint8_t u8UssInitOkFlag;
    uint8_t res[1];
}tParkoutWithoutPathPlannerInfo;

typedef struct _CTRL_PARK_OUT_SIDE_
{
    tCtrl_ParkOutFinishReason eParkOutFinishCode;
    tCtrl_ParkOutType         eParkOutType;
    tCtrl_ParkOutPhase        eParkOutPhase;
    float f32FrontEmptyFinishDis;
    float f32FrontNarrowFinishDis;
    float f32NarrowFinishDis;
    float f32SideNarrowFinishDis;
    float f32DriveBackMinDis;
    float f32InitTheta;
    float f32TargetTheta;
    float f32RecordTrack;
    float f32DistanceTravel;
    float f32stopDis;
    float f32targetSpeed;
    float f32minSpeed;
    float f32maxSteer;
    float f32steerGap;
    float f32steerFinishGap;
    float f32ParkingPercentage;
    
    uint8_t bParkOutInitFlag;
    int iParkOutInitCheckWaitTime;
    uint8_t bParkOutInitCheckFlag;
    uint8_t bParkOutPreFinishFlag;
    uint8_t bParkOutFinishFlag;
}tCtrlParkOutSide;

typedef struct
{
    uint32_t u32Reservation[250];      // 1k Byte reservation
}tReservationUnit;

/* Cruising */
typedef struct
{
    uint8_t breakStatus;
    float accDesired;
    float mIntegration;

    float disCurPos2MatchPoint;
    float disMatchPoint2FinalPoint;

    float mAd;
    float mVd;


    // for print log
    float errState[4];
    float steeringOut;
    float carPos[3];
    int index;
    int pointNum;
    int pathId;

    float x_path;
    float y_path;
    float theta_path;

    float flag_index1;
    float flag_index2;
    float flag_index3;
    float flag_index4;
    float flag_index5;
    float flag_index6;
    float flag_index7;
    float flag_index8;
    float flag_index9;
    float flag_index10;
    float flag_index11;
    float flag_index12;
    float flag_index13;
    int flag_index14;
    int flag_index15;
    int flag_index16;
    float f32Steering_;
    float f32Vel_;

    float x_dr;
    float y_dr;
    float theta_dr;
}tVehicleModelAndCtrlPara;

typedef struct 
{
    float f32s;
    float f32d;
    float f32s_dot;
    float f32d_dot;

    float f32es;
    float f32efai;
    float f32KappaDots;
}tTrajectoryFrame;

typedef struct
{
    float f32StationErr;
    float f32SpeedErr;

    float f32kpp;
    float f32kvp;
    float f32kvi;
    float f32dt;
    int   i8saturationFlag;
    float f32KvAntiSat;
    float f32saturationValue;
    float f32Integration;

    float f32accFfwRatio;
    float f32AccTrajReq;
    float f32VelTrajReq;
    float f32PosTrajReq;

    float f32PosControlOffset;
    float f32VelControlOffset;
    
    float f32VelResul;
    float f32AccResul;

    float f32ACCMAX;
    float f32DECMAX;

}tTrajLongiController;

#endif
