#ifndef CTRL_ENUM_H_
#define CTRL_ENUM_H_

typedef enum ECTRL_MODULE_TYPE_tag
{
   u8CTRL_FunctionOFF = 0,
   u8CTRL_Crusing,
   u8CTRL_Perpen_Parking,
   u8CTRL_Parra_Parking,
   u8CTRL_USS_Parking,
   u8CTRL_Equip_Parking,
   u8CTRL_Parking_Out,
} ECTRL_MODULE_TYPE;

typedef enum ECTRL_FUNC_STATUS_tag
{
	u8Ctrl_Func_Off = 0,
	u8Ctrl_Func_Init,
	u8Ctrl_Func_On,
	u8Ctrl_Func_Complete,
	u8Ctrl_Func_Fail,
} ECTRL_FUNC_STATUS;

typedef enum EReplanStatus_tag
{
    REPLAN_NONE    = 0, //success and do nothing
    REPLAN_SUCCESS = 1, //success and reset dr.
    REPLAN_FAILED  = 2,
    REPLAN_HARD_FAILED = 3
}EReplanStatus;

typedef enum EReplanType_tag
{
    REPLAN_TYPE_NONE = 0,
    REPLAN_TYPE_ROLL_CAR = 1,
    REPLAN_TYPE_FRONT_AEB = 2,
    REPLAN_TYPE_REAR_AEB = 3,
    REPLAN_TYPE_SUSPENDING = 4,
    REPLAN_TYPE_LAST_ROLL = 12
}EReplanType;

typedef enum tPP_Status_tag
{
    ppStatus_default = 0,
    ppHardFail = 1,
    ppPending = 2,
}tppStatus;

typedef enum {
    ReqOff = 0,
    ReqStandby,
    ReqPause,
    ReqStop,
    ReqResume,
    ReqParking,
    ReqInit,
}tAPA_Shell_ReqStatus;


typedef enum {
    Off = 0,
    Standby,
    Init,
    Cooldown,
    Parking,
    Complete,
    Fail,
    Pause,
    Stop,
}tAPA_Function_Status;

typedef enum {
    Ctrl_Longi_Off = 0,
    Ctrl_Longi_Standby,                  //1
    Ctrl_Longi_Forward_Stop_Steering,
    Ctrl_Longi_Forward_Speed_Init,
    Ctrl_Longi_Forward_Maintain_Speed,
    Ctrl_Longi_Forward_Close_End,        //5
    Ctrl_Longi_USS_Wait_Forward,
    Ctrl_Longi_Forward_End,
    Ctrl_Longi_Forward_WaitForNewPath,
    Ctrl_Longi_Backward_Stop_Steering,
    Ctrl_Longi_Backward_Speed_Init,      //10
    Ctrl_Longi_Backward_Maintain_Speed,  //11
    Ctrl_Longi_Backward_Close_End,       //12
    Ctrl_Longi_USS_Wait_Backward,        //13
    Ctrl_Longi_Backward_End,             //14
    Ctrl_Longi_Backward_WaitForNewPath,  //15
    Ctrl_Longi_Update,
    Ctrl_Longi_Pause,
    Ctrl_Longi_Stop,
    Ctrl_Longi_Init,                     //19
    Ctrl_Longi_USSForward_Stop,
    Ctrl_Longi_USSBackward_Stop,
}tCtrl_Parking_Long_Status;

typedef enum {
        Cruising_Standby=0,
        Forward_Stop_Steering=1,
        Forward_Starting=2,
        Forward_Acceleration=3,
        Forward_Deceleration=4,
        Forward_ConstantSpeed=5,
        Forward_Close_End=6,
        Forward_End=7,
        Cruising_Stop=8,
} tCtrl_Cruising_Status;


typedef enum {
    CTRL_MODULE_OFF = 0,
    CTRL_MODULE_STANDBY,
    CTRL_MODULE_ACTIVE,
    CTRL_MODULE_PAUSE,
    CTRL_MODULE_FINISH,
}tCtrl_Module_Status;

typedef enum {
    Ctrl_Default=0,
    Ctrl_ParkingIn,
    Ctrl_ParkingOut,
    Ctrl_Straight_Forward,
    Ctrl_Straight_Backward,
    Ctrl_Crusing,                       //5
    Ctrl_ReqHeadParraParkingOutLeft,
    Ctrl_ReqHeadParraParkingOutRight,
    Ctrl_ReqHeadPerpenParkingOutStraight,
}tCtrl_Func_Type;


typedef enum
{
    Ctrl_Internal_Default = 0,
    Ctrl_Internal_ParkingWithPlan,
    Ctrl_Internal_Straight,
    Ctrl_Internal_Back,
    Ctrl_Internal_ParkingOutNoPlan,
    Ctrl_Internal_Crusing,
}tCtrl_Internal_FuncType;


typedef enum
{
    DF_PL_TYPE_DEFAULT    = 0,
    DF_PL_TYPE_Horizontal = 1,
    DF_PL_TYPE_Vertical   = 2,
    DF_PL_TYPE_Oblique_30 = 3,
    DF_PL_TYPE_Oblique_45 = 4,
    DF_PL_TYPE_Oblique_60 = 5,
    DF_PL_TYPE_ThreeDimensional = 6,
    DF_PL_TYPE_SPACE_Horizontal = 7,
    DF_PL_TYPE_SPACE_Vertical   = 8,
    DF_PL_TYPE_SPACE_Inclined   = 9,
}tDF_PL_TYPE;


typedef enum
{
   Ctrl_None_AEB     = 0,
   Ctrl_DEFAULT_AEB  = 1,
   Ctrl_Front_AEB    = 2,
   Ctrl_Back_AEB     = 3,
   Ctrl_Mech_AEB     = 11,
}tCtrlAebStatus;


typedef enum
{
   PathPlan_NoneGear   = 0,
   PathPlan_R_Gear     = 1,
   PathPlan_N_Gear     = 2,
   PathPlan_D_Gear     = 3,
   PathPlan_P_Gear     = 5,

}tPathPlanGearInfo;



typedef enum _eUssPdcSolution_tag
{
   USS_PDC_SOLUTION_NONE                  = 0,
   USS_PDC_SOLUTION_ORIGINAL_DISTANCE     = 1,
   USS_PDC_SOLUTION_POLAR_COORDINATE      = 2,

}eUssPdcSolution;

typedef enum 
{
    PHASE_STOP_STEERING = 0,
    PHASE_SPEED_INIT,
    PHASE_SPEED_MAINTAIN,
    PHASE_DECELERATION,
    PHASE_STOP,
    PHASE_EMERGENCY_STOP,
}tCtrlSpeedTrapezoidPhase;

typedef enum  
{
    PLANRESULT_NONE     = 0,        // standby
    PLANRESULT_SUCCESS  = 1,        // success
    PLANRESULT_PLANNING = 2,        // planning

    PLANRESULT_FAILED   = 10,        // failed
    PLANRESULT_TOO_CLOSE_FAILED = 11 // failed
}EPlanResult;

typedef enum
{
    CTRL_REPLAN_NONE,
    CTRL_REPLAN_SUCCESS,
    CTRL_REPLAN_FAILED,
    CTRL_REPLAN_TIMEOUT_FAILED,
    CTRL_REPLAN_GEAR_FAILED
    
}tCtrlReplanResult;

typedef enum 
{
    PEB_LEVEL_NONE = 0,        // no peb
    PEB_LEVEL_1    = 1,        // <= 0.7m
    PEB_LEVEL_2    = 2,        // <= 0.8m
    PEB_LEVEL_3    = 3,        // <= 1.0m
    PEB_LEVEL_4    = 4,        // <= 1.2m
	PEB_LEVEL_5    = 5         // other
}EPebLevel;

typedef enum
{
    CTRL_PARKOUT_NONE,
    CTRL_PARKOUT_WITHPP,
    CTRL_PARKOUT_WITHOUTPP

}tCtrlParkOutType;

typedef enum {
    NoReason                    = 0,
    ParkSlotWideParkOutComplete = 1,
    ParkSlotNarrowParkOutFail   = 2,
    ParkOutTypeError            = 3,
    ParkOutLeftBlock            = 4,
    ParkOutRightBlock           = 5,
    ParkOutStraightObsFront     = 6,
    ParkOutFinish               = 7
}tCtrl_ParkOutFinishReason;

typedef enum {
    ParkOutFefault              = 0,
    LeftParkOut                 = 1,
    RightParkOut                = 2,
    StraightForwardParkOut      = 3,
    StraightBackwardParkOut     = 4
}tCtrl_ParkOutType;


typedef enum {
    ParkOutPhaseDefault         = 0,
    DriveFront                  = 1,
    DriveBack                   = 2,
    LeftForward                 = 3,
    RightForward                = 4,
    LeftBackward                = 5,
    RightBackward               = 6,
    ParkOutComplete             = 7
}tCtrl_ParkOutPhase;

typedef enum {
    VehicleDirForward           = 1,
    VehicleDirStop              = 0,
    VehicleDirBack              = -1
}tVehicleDir;

typedef enum{
    Acceleration                = 1,
    Deceleration                = 2,
    ConstantSpeed               = 3
}tAccelerationMode;

typedef enum{
    CTRL_FINISH_TYPE_NONE  = 0,
    CTRL_FINISH_TYPE_APA   = 1,
    CTRL_FINISH_TYPE_HPP   = 2
}tCtrlFinishType;




#endif //CTRL_ENUM_H_
