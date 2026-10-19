
#ifndef CAN_DBC_PARSER_HPP_H
#define CAN_DBC_PARSER_HPP_H

#include "proj_global.h"


#if(EM_VEHI_TYPE == VEHI_TYPE_HAN)

typedef enum
{
    COM_PDUID_0X422_RX          = 0,
    COM_PDUID_0X318_RX,
    COM_PDUID_0X133_RX,
    COM_PDUID_0X294_RX,
    COM_PDUID_0X2B6_RX,
    COM_PDUID_0X212_RX,
    COM_PDUID_0X220_RX,
    COM_PDUID_0X218_RX,
    COM_PDUID_0X222_RX,
    COM_PDUID_0X11F_RX,
    COM_PDUID_0X123_RX,
    COM_PDUID_0X1F0_RX,
    COM_PDUID_0X121_RX,
    COM_PDUID_0X2F1_RX,
    COM_PDUID_0X342_RX,
    COM_PDUID_0X135_RX,
    COM_PDUID_0X35C_RX,
    COM_PDUID_NUM_RX,
};

/* TX MSG*/
typedef struct
{
        uint8   APA_MainStas                    :3;
        uint8   APA_SpeedLimit_L                :5;
        uint8   APA_SpeedLimit_H                :3;
        uint8   APA_SteeringCtrlReqForEPS       :1;
        uint8   APA_SteeringCtrlReqForEPSVD     :1;
        uint8   APA_FailureBrakeMode            :2;
        uint8   APA_to_ESP_request_valid        :1;
        uint8   APA_Tar_StrAgl_L                :8;
        uint8   APA_Tar_StrAgl_H                :8;
        uint8   APA_StopDistance_L              :8;
        uint8   APA_StopDistance_H              :4;
        uint8   EPB_EmergencyBrake              :1;
        uint8   EPB_EmergencyBrakeValid         :1;
        uint8   APS_SCU_TargetGearRequest_L     :2;
        uint8   APS_SCU_TargetGearRequest_H     :2;
        uint8   APA_APA_Mode                    :2;
        uint8   APA_APA_Alive_Counter           :4;
        uint8   APA_APA_Checksum                :8;
}CAN_Frame_134_Type;

typedef struct
{
        uint8                                   :8;
        uint8                                   :8;
        uint8                                   :8;
        uint8                                   :8;
        uint8                                   :4;
        uint8   EPS_InterDect                   :1;
        uint8   EPS_InterDectVD                 :1;
        uint8   EPS_APA_CtrlSts_L               :2;
        uint8   EPS_APA_CtrlSts_H               :1;
        uint8                                   :7;
        uint8                                   :4;
        uint8   EPS_Alive_Counter               :4;
        uint8   EPS_Checksum                    :8;
}CAN_Frame_135_Type;

typedef struct
{
        uint8   AVM_APA_SuspendedReason         :4;
        uint8   ParkingProcessOtherInfoPrompt   :4;
        uint8   AVM_APA_AutoSearchSts           :3;
        uint8   AVM_APA_AbortReason             :5;
        uint8   OptimalParkingSpace             :3;
        uint8   APA_Status_Reserved_1           :5;
        uint8   AVM_APA_Active                  :2;
        uint8   ParkingType                     :4;
        uint8   AutomaticParkingSwitchState     :2;
        uint8   AVM_APA_CurrentPathNum          :4;
        uint8   AVM_APA_TotalPathNum            :4;
        uint8   AVM_APA_CurrentStepNum          :4;
        uint8   APA_Electricity_request         :2;
        uint8   APA_Electricity_request_valid   :1;
        uint8   APA_Status_Reserved_3_L         :1;
        uint8   APA_Status_Reserved_3_H         :4;
        uint8   APA_Status_Alive_Counter        :4;
        uint8   APA_Status_Checksum             :8;
}CAN_Frame_1D1_Type;

typedef struct
{
        uint8   MPC_316_HMAStatus               :3;
        uint8   MPC_316_HMAHighBeamRequest      :1;
        uint8   MPC_316_LeftLineTrackingStatus  :2;
        uint8   MPC_316_LaneAssistModeSta       :2;
        uint8   MPC_316_LDWSensitivity          :2;
        uint8   MPC_316_TakeOverRequestToDriver :1;
        uint8   MPC_316_LKS_LDWCameraBlocked    :1;
        uint8   MPC_316_LKSFault                :1;
        uint8   MPC_316_LDWFault                :1;
        uint8   MPC_316_ACC_AEBCameraBlocked    :1;
        uint8   MPC_316_PADDING_BIT1            :1;
        uint8   MPC_316_OutputLKSTorqueRequest_L        :8;
        uint8   MPC_316_OutputLKSTorqueRequest_H        :3;
        uint8   MPC_316_LKSTorqueRequestStaus   :2;
        uint8   MPC_316_RSFFunctionStatus       :3;
        uint8   MPC_316_RSFOutputSpeedLimitUnit :2;
        uint8   MPC_316_RightLlineTrackingStatus        :2;
        uint8   MPC_316_TJA_ICAFunctionStatus   :3;
        uint8   MPC_316_FuncCameraBlocked       :1;
        uint8   MPC_316_RSFOutputSpeedLimit     :8;
        uint8   MPC_316_LaneDepartureAlarmMode  :2;
        uint8   MPC_316_PADDING_BIT2_2          :2;
        uint8   MPC_316_AliveCounter            :4;
        uint8   MPC_316_Checksum                :8;
}CAN_Frame_316_Type;

typedef struct
{
        uint8   MPC_432_EquipmentACC            :1;
        uint8   MPC_432_EquipmentAEB            :1;
        uint8   MPC_432_EquipmentFCW            :1;
        uint8   MPC_432_EquipmentHMA            :1;
        uint8   MPC_432_EquipmentLDW            :1;
        uint8   MPC_432_EquipmentLKS            :1;
        uint8   MPC_432_EquipmentSLA            :1;
        uint8   MPC_432_EquipmentTJA_ICA        :1;
        uint8   MPC_432_ModuleManufacturer      :4;
        uint8   MPC_432_IsEquipmentWarningMode  :1;
        uint8   MPC_432_PADDING_BIT3            :3;
        uint8   MPC_432_PADDING_BIT16_1_L       :8;
        uint8   MPC_432_PADDING_BIT16_1_H       :8;
        uint8   MPC_432_PADDING_BIT16_2_L       :8;
        uint8   MPC_432_PADDING_BIT16_2_H       :8;
        uint8   MPC_432_PADDING_BIT16_3_L       :8;
        uint8   MPC_432_PADDING_BIT16_3_H       :8;
}CAN_Frame_432_Type;

typedef struct
{
        uint8   MPC_32D_vSetDis_L               :8;
        uint8   MPC_32D_vSetDis_H               :1;
        uint8   MPC_32D_ObjValid                :1;
        uint8   MPC_32D_TauGapSet               :3;
        uint8   MPC_32D_DxTarObj                :3;
        uint8   MPC_32D_PCWPreWarning           :1;
        uint8   MPC_32D_PCWLatentWarning        :1;
        uint8   MPC_32D_PCW_state               :1;
        uint8   MPC_32D_ACCModeDisplay          :3;
        uint8   MPC_32D_ACCState                :1;
        uint8   MPC_32D_TakeOverReq             :1;
        uint8   MPC_32D_SpeedUnit               :2;
        uint8   MPC_32D_CCR_AEBError            :1;
        uint8   MPC_32D_ACCTextInfoForDriver    :5;
        uint8   MPC_32D_CCR_FCWError            :1;
        uint8   MPC_32D_VRU_FCWError            :1;
        uint8   MPC_32D_PADDING_BIT1            :1;
        uint8   MPC_32D_AcuteWarning            :1;
        uint8   MPC_32D_AEBState                :1;
        uint8   MPC_32D_PADDING_BIT3            :3;
        uint8   MPC_32D_PADDING_BIT8            :8;
        uint8   MPC_32D_AliveCounter            :4;
        uint8   MPC_32D_PADDING_BIT4            :4;
        uint8   MPC_32D_CheckSum                :8;
}CAN_Frame_32D_Type;

typedef struct
{
        uint8   MPC_32E_axvCvAim                :8;
        uint8   MPC_32E_axvCvUpperValue         :8;
        uint8   MPC_32E_axvCvLowerValue         :8;
        uint8   MPC_32E_aDtUpperLimitAxvCv      :7;
        uint8   MPC_32E_PADDING_BIT1_1          :1;
        uint8   MPC_32E_aDtLowerLimitAxvCv      :7;
        uint8   MPC_32E_ACCDriveOffReq          :1;
        uint8   MPC_32E_ACCDecToStopReq         :1;
        uint8   MPC_32E_ACC_Minimum_Braking     :1;
        uint8   MPC_32E_BrakePreferred          :1;
        uint8   MPC_32E_ACCMode                 :3;
        uint8   MPC_32E_ESC_VLC_ShutDownMode    :2;
        uint8   MPC_32E_AliveCounter            :4;
        uint8   MPC_32E_PADDING_BIT4            :4;
        uint8   MPC_32E_CheckSum                :8;
}CAN_Frame_32E_Type;

typedef struct
{
        uint16  MPC_32F_AEBaxTarAEB_L           :8;
        uint16  MPC_32F_AEBaxTarAEB_H           :8;
        uint8   MPC_32F_EBADecelerationControl  :1;
        uint8   MPC_32F_PADDING_BIT1            :1;
        uint8   MPC_32F_Prefill                 :1;
        uint8   MPC_32F_AWBRequest              :1;
        uint8   MPC_32F_ABARequest              :1;
        uint8   MPC_32F_ABALevel                :2;
        uint8   MPC_32F_AEBDecCtrlRequest       :1;
        uint8   MPC_32F_PADDING_BIT4_1          :4;
        uint8   MPC_32F_AWBLevel                :4;
        uint8   MPC_32F_RequestESCHoldVehicle   :1;
        uint8   MPC_32F_PADDING_BIT7            :7;
        uint8   MPC_32F_PADDING_BIT8            :8;
        uint8   MPC_32F_AliveCounter            :4;
        uint8   MPC_32F_PADDING_BIT4_2          :4;
        uint8   MPC_32F_CheckSum                :8;
}CAN_Frame_32F_Type;

/* RX MSG */

typedef struct
{
        uint8   ESC_422_FLWheelPulseCounter_L   :8;
        uint8   ESC_422_FLWheelPulseCounter_H   :2;
        uint8                                   :2;
        uint8   ESC_422_RRWheelPulseCounterValid        :1;
        uint8   ESC_422_RLWheelPulseCounterValid        :1;
        uint8   ESC_422_FRWheelPulseCounterValid        :1;
        uint8   ESC_422_FLWheelPulseCounterValid        :1;
        uint8   ESC_422_FRWheelPulseCounter_L   :8;
        uint8   ESC_422_FRWheelPulseCounter_H   :2;
        uint8                                   :2;
        uint8   ESC_422_RLWheelPulseCounter_L   :4;
        uint8   ESC_422_RLWheelPulseCounter_H   :6;
        uint8                                   :2;
        uint8   ESC_422_RRWheelPulseCounter_L   :8;
        uint8   ESC_422_RRWheelPulseCounter_H   :2;
        uint8                                   :2;
        uint8   ESC_422_AliveCounter            :4;
        uint8   ESC_422_CheckSum                :8;
}CAN_Frame_422_Type;

typedef struct
{
        uint8   EPS_318_EPSLKACtrlSt            :3;
        uint8                                   :5;
        uint8   EPS_318_LKACtrlDlvdValue_L      :8;
        uint8   EPS_318_LKACtrlDlvdValue_H      :4;
        uint8   EPS_318_LKACtrlDlvdValueVD      :1;
        uint8   EPS_318_HandsOffDetSt           :1;
        uint8   EPS_318_HandsOffDetStVD         :1;
        uint8   EPS_318_StrngWhlTorqVD          :1;
        uint8   EPS_318_StrngWhlTorq_L          :8;
        uint8   EPS_318_StrngWhlTorq_H          :4;
        uint8                                   :4;
        uint8                                   :8;
        uint8                                   :4;
        uint8   EPS_318_AliveCounter            :4;
        uint8   EPS_318_Checksum                :8;
}CAN_Frame_318_Type;

typedef struct
{
        uint8   SWITCH_133_AllWeatherLights     :1;
        uint8                                   :1;
        uint8   SWITCH_133_LowBeamLights        :1;
        uint8   SWITCH_133_HighBeamLights       :1;
        uint8   SWITCH_133_LeftTurnLights       :1;
        uint8   SWITCH_133_RightTurnLights      :1;
        uint8   SWITCH_133_FrontFogLamp         :1;
        uint8   SWITCH_133_RearFogLamp          :1;
        uint8   SWITCH_133_FrontWiperPosition   :4;
        uint8                                   :4;
        uint8                                   :8;
        uint8                                   :8;
        uint8                                   :8;
        uint8   SWITCH_133_LightAutoSwitch      :2;
        uint8                                   :6;
        uint8                                   :8;
        uint8                                   :4;
        uint8   SWITCH_133_AliveCounter         :4;
}CAN_Frame_133_Type;

typedef struct
{
        uint8   BCM_294_LeftFrontDoorState      :2;
        uint8   BCM_294_RightFrontDoorState     :2;
        uint8   BCM_294_LeftBackDoorState       :2;
        uint8   BCM_294_RightBackDoorState      :2;
        uint8   BCM_294_LeftFrontDoorValid      :1;
        uint8   BCM_294_RightFrontDoorValid     :1;
        uint8   BCM_294_LeftBackDoorValid       :1;
        uint8   BCM_294_RightBackDoorValid      :1;
        uint8   BCM_294_SeatBeltStatusValid     :1;
        uint8   BCM_294_BackDoorStatusValid     :1;
        uint8   BCM_294_FrontHatchStatusValid   :1;
        uint8   BCM_294_EmergencyAlarmValid     :1;
        uint8   BCM_294_DriverSeatBeltStatus    :2;
        uint8   BCM_294_BackDoorState           :2;
        uint8   BCM_294_FrontHatchState         :2;
        uint8   BCM_294_EmergencyAlarmStatus    :2;
        uint8                                   :8;
        uint8                                   :8;
        uint8                                   :8;
        uint8   BCM_294_AliveCounter            :4;
        uint8                                   :4;
        uint8   BCM_294_CheckSum                :8;
}CAN_Frame_294_Type;

typedef struct
{
        uint8   IPK_2B6_Year                    :8;
        uint8   IPK_2B6_Month                   :8;
        uint8   IPK_2B6_Day                     :8;
        uint8   IPK_2B6_Hour                    :8;
        uint8   IPK_2B6_Minute                  :8;
        uint8   IPK_2B6_Second                  :8;
        uint8                                   :8;
        uint8                                   :8;
}CAN_Frame_2B6_Type;

typedef struct
{
        uint8                                   :4;
        uint8   TCU_212_ShiftProgressState      :1;
        uint8   TCU_212_ShiftProgressStatus     :1;
        uint8                                   :2;
        uint8                                   :8;
        uint8                                   :8;
        uint8                                   :8;
        uint8                                   :8;
        uint8                                   :8;
        uint8   TCU_212_ActualShiftMode         :4;
        uint8   TCU_212_ActualGear              :4;
        uint8   TCU_212_CheckSum                :8;
}CAN_Frame_212_Type;

typedef struct
{
        uint8   ESC_220_RRWheelDriveDirection   :2;
        uint8   ESC_220_RLWheelDriveDirection   :2;
        uint8   ESC_220_FRWheelDriveDirection   :2;
        uint8   ESC_220_FLWheelDriveDirection   :2;
        uint8   ESC_220_ActiveVehicleHold       :1;
        uint8   ESC_220_VLCAvailable            :1;
        uint8   ESC_220_VLCActive               :1;
        uint8   ESC_220_VLCFail                 :1;
        uint8   ESC_220_NoBrakeForce            :1;
        uint8                                   :2;
        uint8   ESC_220_QDCACC                  :1;
        uint8   ESC_220_ECDTempOff              :1;
        uint8                                   :1;
        uint8   ESC_220_VehicleStandstill       :2;
        uint8   ESC_220_FLWheelDriveDirectionStau        :1;
        uint8   ESC_220_FRWheelDriveDirectionStau        :1;
        uint8   ESC_220_RLWheelDriveDirectionStau        :1;
        uint8   ESC_220_RRWheelDriveDirectionStau        :1;
        uint8   ESC_220_VLCInternalTargetAccelerat       :8;
        uint8                                   :8;
        uint8                                   :8;
        uint8   ESC_220_AliveCounter            :4;
        uint8                                   :1;
        uint8   ESC_220_CDD_Available           :1;
        uint8   ESC_220_CDDActive               :1;
        uint8   ESC_220_CDD_Fail                :1;
        uint8   ESC_220_CheckSum                :8;
}CAN_Frame_220_Type;

typedef struct
{
        uint8                                   :8;
        uint8                                   :1;
        uint8   EPB_218_EPBStatus               :3;
        uint8                                   :4;
        uint8                                   :8;
        uint8                                   :8;
        uint8                                   :8;
        uint8                                   :8;
        uint8   EPB_218_RollingCounter          :4;
        uint8                                   :4;
        uint8   EPB_218_Checksum                :8;
}CAN_Frame_218_Type;

typedef struct
{
        uint8   ESC_222_YawRate_L               :8;
        uint8   ESC_222_YawRate_H               :4;
        uint8   ESC_222_YawRateOffset_L         :4;
        uint8   ESC_222_YawRateOffset_H         :8;
        uint8   ESC_222_EBDActive               :1;
        uint8   ESC_222_ABSActive               :1;
        uint8   ESC_222_EBDFault                :1;
        uint8   ESC_222_ABS_Fault               :1;
        uint8   ESC_222_TCSActive               :1;
        uint8                                   :1;
        uint8   ESC_222_VDCActive               :1;
        uint8   ESC_222_YawRateStatus           :1;
        uint8   ESC_APA_Status                  :3;
        uint8                                   :5;
        uint8                                   :8;
        uint8   ESC_222_AliveCounter            :4;
        uint8                                   :4;
        uint8   ESC_222_CheckSum                :8;
}CAN_Frame_222_Type;

typedef struct
{
        uint16  SAS_11F_SteeringWheelAngle_L    :8;
        uint16  SAS_11F_SteeringWheelAngle_H    :8;
        uint8   SAS_11F_SWRotationSpeed         :8;
        uint8   SAS_11F_FailureStatus           :1;
        uint8   SAS_11F_CalibrationStatus       :1;
        uint8                                   :6;
        uint8   SAS_11F_AliveCounter            :4;
        uint8   SAS_11F_CheckSum                :4;
}CAN_Frame_11F_Type;

typedef struct
{
        uint8                                   :8;
        uint8                                   :8;
        uint8                                   :8;
        uint8                                   :8;
        uint8                                   :8;
        uint8                                   :1;
        uint8   ESC_123_HDCCtrlStatus           :2;
        uint8   ESC_123_BrakePedalStatus        :2;
        uint8                                   :3;
        uint8   ESC_123_AliveCounter            :4;
        uint8   ESC_123_ESPOff                  :1;
        uint8   ESC_123_ESPActive               :1;
        uint8   ESC_123_TCSFault                :1;
        uint8   ESC_123_VDCFault                :1;
        uint8   ESC_123_Checksum                :8;
}CAN_Frame_123_Type;

typedef struct
{
        uint8   ESC_1F0_WheelSpeedFL_L          :8;
        uint8   ESC_1F0_WheelSpeedFL_H          :4;
        uint8   ESC_1F0_WheelSpeedFRStatus      :1;
        uint8   ESC_1F0_WheelSpeedFLStatus      :1;
        uint8   ESC_1F0_WheelSpeedRRStatus      :1;
        uint8   ESC_1F0_WheelSpeedRLStatus      :1;
        uint8   ESC_1F0_WheelSpeedFR_L          :8;
        uint8   ESC_1F0_WheelSpeedFR_H          :4;
        uint8   ESC_1F0_WheelSpeedRL_L          :4;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
        uint8   ESC_1F0_WheelSpeedRL_H          :8;
        uint8   ESC_1F0_WheelSpeedRR_L          :8;
        uint8   ESC_1F0_WheelSpeedRR_H          :4;
        uint8   ESC_1F0_MessageCounter          :4;
        uint8   ESC_1F0_Checksum                :8;
}CAN_Frame_1F0_Type;

typedef struct
{
        uint8   ESC_121_VehicleSpeed_L          :8;
        uint8   ESC_121_VehicleSpeed_H          :4;
        uint8                                   :3;
        uint8   ESC_121_VehicleSpeedStatus      :1;
        uint8                                   :8;
        uint8                                   :4;
        uint8   ESC_121_AWBavailable            :1;
        uint8   ESC_121_AWBactive               :1;
        uint8   ESC_121_AEBdecActive            :1;
        uint8   ESC_121_AEBnotAvailable         :1;
        uint8   ESC_121_PrefillAvailable        :1;
        uint8   ESC_121_PrefillActive           :1;
        uint8   ESC_121_ABAavailable            :1;
        uint8   ESC_121_ABAactive               :1;
        uint8                                   :4;
        uint8                                   :8;
        uint8   ESC_121_AliveCounter            :4;
        uint8                                   :4;
        uint8   ESC_121_Checksum                :8;
}CAN_Frame_121_Type;

typedef struct
{	
    uint8	                              	:1;
	uint8	AC_AmbientTemperatureInvalid  	:1;
	uint8	                              	:6;
	uint8	AC_AmbientTemperature         	:8;
	uint8	                              	:8;
	uint8	                              	:8;
	uint8	                              	:8;
	uint8	                              	:8;
	uint8	                              	:8;
	uint8	                              	:8;
}CAN_Frame_2F1_Type;

typedef struct
{
	uint8	VCU_342_ThrottleDepth                   	:8;
	uint8	VCU_342_DethOfBreaking                  	:8;
	uint8	VCU_342_ThrottleDepthValid              	:1;
	uint8	VCU_342_DethOfBreakingValid             	:1;
	uint8	                                        	:2;
	uint8	VCU_342_VehicleRunMode                  	:2;
	uint8	                                        	:2;
	uint8	VCU_342_TargetGear                      	:4;
	uint8	                                        	:4;
	uint8	                                        	:8;
	uint8	                                        	:8;
	uint8	                                        	:8;
	uint8	VCU_342_CheckSum                        	:8;
}CAN_Frame_342_Type;

typedef struct
{
	uint8	GearshiftSystem                                	:1;
	uint8	                                         	:5;
	uint8	SCU_SCUAPAInh                           	:1;
	uint8	                                        	:3;
	uint8	SCU_SCUAPASts                           	:3;
	uint8	                                        	:2;
	uint8	                                        	:8;
	uint8	                                        	:8;
	uint8	                                        	:8;
        uint8	                                        	:8;
        uint8	                                        	:4;
        uint8   SCU_APA_Status_Alive_Counter                    :4;
	uint8	SCU_APA_Status_Checksum                        	:8;
}CAN_Frame_35C_Type;

/*======================================== interface declaration ====================================================*/
/* TX MSG */
extern CAN_Frame_1D1_Type CAN_Msg_1D1_VAR;
extern CAN_Frame_134_Type CAN_Msg_134_VAR;
extern CAN_Frame_316_Type CAN_Msg_316_VAR;
extern CAN_Frame_432_Type CAN_Msg_432_VAR;

extern CAN_Frame_32D_Type CAN_Msg_32D_VAR;
extern CAN_Frame_32E_Type CAN_Msg_32E_VAR;
extern CAN_Frame_32F_Type CAN_Msg_32F_VAR;

/* RX MSG */
extern CAN_Frame_422_Type CAN_Msg_422_VAR;
extern CAN_Frame_318_Type CAN_Msg_318_VAR;
extern CAN_Frame_133_Type CAN_Msg_133_VAR;
extern CAN_Frame_294_Type CAN_Msg_294_VAR;

extern CAN_Frame_2B6_Type CAN_Msg_2B6_VAR;
extern CAN_Frame_212_Type CAN_Msg_212_VAR;
extern CAN_Frame_220_Type CAN_Msg_220_VAR;
extern CAN_Frame_218_Type CAN_Msg_218_VAR;

extern CAN_Frame_222_Type CAN_Msg_222_VAR;
extern CAN_Frame_11F_Type CAN_Msg_11F_VAR;
extern CAN_Frame_123_Type CAN_Msg_123_VAR;
extern CAN_Frame_1F0_Type CAN_Msg_1F0_VAR;

extern CAN_Frame_121_Type CAN_Msg_121_VAR;
extern CAN_Frame_2F1_Type CAN_Msg_2F1_VAR;
extern CAN_Frame_342_Type CAN_Msg_342_VAR;
extern CAN_Frame_135_Type CAN_Msg_135_VAR;
extern CAN_Frame_35C_Type CAN_Msg_35C_VAR;

extern void Tx_CheckSum_main();
extern void doAliveCounter_main();

extern uint8 Com_CAN_SignalParse_TX_1D1_APA_Electricity_request_valid(uint8 u8APA_Electricity_request_valid);
extern uint8 Com_CAN_SignalParse_TX_1D1_APA_Electricity_request(uint8 u8APA_Electricity_request);
extern uint8 Com_CAN_SignalParse_TX_1D1_AVM_APA_CurrentStepNum(uint8 u8AVM_APA_CurrentStepNum);
extern uint8 Com_CAN_SignalParse_TX_1D1_AVM_APA_TotalPathNum(uint8 u8AVM_APA_TotalPathNum);

extern uint8 Com_CAN_SignalParse_TX_1D1_AVM_APA_CurrentPathNum(uint8 u8AVM_APA_CurrentPathNum);
extern uint8 Com_CAN_SignalParse_TX_1D1_AutomaticParkingSwitchState(uint8 u8AutomaticParkingSwitchState);
extern uint8 Com_CAN_SignalParse_TX_1D1_ParkingType(uint8 u8ParkingType);
extern uint8 Com_CAN_SignalParse_TX_1D1_AVM_APA_Active(uint8 u8AVM_APA_Active);

extern uint8 Com_CAN_SignalParse_TX_1D1_OptimalParkingSpace(uint8 u8OptimalParkingSpace);
extern uint8 Com_CAN_SignalParse_TX_1D1_AVM_APA_AbortReason(uint8 u8AVM_APA_AbortReason);
extern uint8 Com_CAN_SignalParse_TX_1D1_AVM_APA_AutoSearchSts(uint8 u8AVM_APA_AutoSearchSts);
extern uint8 Com_CAN_SignalParse_TX_1D1_ParkingProcessOtherInfoPrompt(uint8 u8ParkingProcessOtherInfoPrompt);

extern uint8 Com_CAN_SignalParse_TX_1D1_AVM_APA_SuspendedReason(uint8 u8AVM_APA_SuspendedReason);
extern uint8 Com_CAN_SignalParse_TX_1D1_APA_Status_Alive_Counter(uint8 u8APA_Status_Alive_Counter);
extern uint8 Com_CAN_SignalParse_TX_1D1_APA_Status_Checksum(uint8 u8APA_Status_Checksum);
extern uint8 Com_CAN_SignalParse_TX_134_APA_APA_Mode(uint8 u8APA_APA_Mode);
extern uint8 Com_CAN_SignalParse_TX_134_APS_SCU_TargetGearRequest(uint8 u8APS_SCU_TargetGearRequest);
extern uint8 Com_CAN_SignalParse_TX_134_EPB_EmergencyBrakeValid(uint8 u8EPB_EmergencyBrakeValid);

extern uint8 Com_CAN_SignalParse_TX_134_EPB_EmergencyBrake(uint8 u8EPB_EmergencyBrake);
extern uint8 Com_CAN_SignalParse_TX_134_APA_StopDistance(uint16 u16APA_StopDistance);
extern uint8 Com_CAN_SignalParse_TX_134_APA_Tar_StrAgl(float32 f32APA_Tar_StrAgl);
extern uint8 Com_CAN_SignalParse_TX_134_APA_to_ESP_request_valid(uint8 u8APA_to_ESP_request_valid);

extern uint8 Com_CAN_SignalParse_TX_134_APA_FailureBrakeMode(uint8 u8APA_FailureBrakeMode);
extern uint8 Com_CAN_SignalParse_TX_134_APA_SteeringCtrlReqForEPSVD(uint8 u8APA_SteeringCtrlReqForEPSVD);
extern uint8 Com_CAN_SignalParse_TX_134_APA_SteeringCtrlReqForEPS(uint8 u8APA_SteeringCtrlReqForEPS);
extern uint8 Com_CAN_SignalParse_TX_134_APA_SpeedLimit(float32 f32APA_SpeedLimit);

extern uint8 Com_CAN_SignalParse_TX_134_APA_MainStas(uint8 u8APA_MainStas);
extern uint8 Com_CAN_SignalParse_TX_134_APA_APA_Alive_Counter(uint8 u8APA_APA_Alive_Counter);
extern uint8 Com_CAN_SignalParse_TX_134_APA_APA_Checksum(uint8 u8APA_APA_Checksum);

extern uint8 Com_CAN_SignalParse_TX_316_MPC_316_HMAStatus(uint8 u8MPC_316_HMAStatus);
extern uint8 Com_CAN_SignalParse_TX_316_MPC_316_HMAHighBeamRequest(uint8 u8MPC_316_HMAHighBeamRequest);
extern uint8 Com_CAN_SignalParse_TX_316_MPC_316_LeftLineTrackingStatus(uint8 u8MPC_316_LeftLineTrackingStatus);

extern uint8 Com_CAN_SignalParse_TX_316_MPC_316_RightLlineTrackingStatus(uint8 u8MPC_316_RightLlineTrackingStatus);
extern uint8 Com_CAN_SignalParse_TX_316_MPC_316_MPC_316_LaneAssistModeSta(uint8 u8MPC_316_LaneAssistModeSta);
extern uint8 Com_CAN_SignalParse_TX_316_MPC_316_LDWSensitivity(uint8 u8MPC_316_LDWSensitivity);
extern uint8 Com_CAN_SignalParse_TX_316_MPC_316_TakeOverRequestToDriver(uint8 u8MPC_316_TakeOverRequestToDriver);

extern uint8 Com_CAN_SignalParse_TX_316_MPC_316_LKS_LDWCameraBlocked(uint8 u8MPC_316_LKS_LDWCameraBlocked);
extern uint8 Com_CAN_SignalParse_TX_316_MPC_316_MPC_316_LKSFault(uint8 u8MPC_316_LKSFault);
extern uint8 Com_CAN_SignalParse_TX_316_MPC_316_LDWFault(uint8 u8MPC_316_LDWFault);
extern uint8 Com_CAN_SignalParse_TX_316_MPC_316_OutputLKSTorqueRequest(float32 f32MPC_316_OutputLKSTorqueRequest);

extern uint8 Com_CAN_SignalParse_TX_316_MPC_316_LKSTorqueRequestStaus(uint8 u8MPC_316_LKSTorqueRequestStaus);
extern uint8 Com_CAN_SignalParse_TX_316_MPC_316_RSFFunctionStatus(uint8 u8MPC_316_RSFFunctionStatus);
extern uint8 Com_CAN_SignalParse_TX_316_MPC_316_RSFOutputSpeedLimitUnit(uint8 u8MPC_316_RSFOutputSpeedLimitUnit);
extern uint8 Com_CAN_SignalParse_TX_316_MPC_316_TJA_ICAFunctionStatus(uint8 u8MPC_316_TJA_ICAFunctionStatus);

extern uint8 Com_CAN_SignalParse_TX_316_MPC_316_RSFOutputSpeedLimit(uint8 u8MPC_316_RSFOutputSpeedLimit);
extern uint8 Com_CAN_SignalParse_TX_316_MPC_316_LaneDepartureAlarmMode(uint8 u8MPC_316_LaneDepartureAlarmMode);
extern uint8 Com_CAN_SignalParse_TX_316_MPC_316_PADDING_BIT1(uint8 u8MPC_316_PADDING_BIT1);
extern uint8 Com_CAN_SignalParse_TX_316_MPC_316_PADDING_BIT2_2(uint8 u8MPC_316_PADDING_BIT2_2);

extern uint8 Com_CAN_SignalParse_TX_316_MPC_316_ACC_AEBCameraBlocked(uint8 u8MPC_316_ACC_AEBCameraBlocked);
extern uint8 Com_CAN_SignalParse_TX_316_MPC_316_FuncCameraBlocked(uint8 u8MPC_316_FuncCameraBlocked);
extern uint8 Com_CAN_SignalParse_TX_316_MPC_316_AliveCounter(uint8 u8MPC_316_AliveCounter);
extern uint8 Com_CAN_SignalParse_TX_316_MPC_316_Checksum(uint8 u8MPC_316_Checksum);
extern uint8 Com_CAN_SignalParse_TX_432_MPC_432_EquipmentACC(uint8 u8MPC_432_EquipmentACC);
extern uint8 Com_CAN_SignalParse_TX_432_MPC_432_EquipmentAEB(uint8 u8MPC_432_EquipmentAEB);

extern uint8 Com_CAN_SignalParse_TX_432_MPC_432_EquipmentFCW(uint8 u8MPC_432_EquipmentFCW);
extern uint8 Com_CAN_SignalParse_TX_432_MPC_432_EquipmentHMA(uint8 u8MPC_432_EquipmentHMA);
extern uint8 Com_CAN_SignalParse_TX_432_MPC_432_EquipmentLDW(uint8 u8MPC_432_EquipmentLDW);
extern uint8 Com_CAN_SignalParse_TX_432_MPC_432_EquipmentLKS(uint8 u8MPC_432_EquipmentLKS);

extern uint8 Com_CAN_SignalParse_TX_432_MPC_432_EquipmentSLA(uint8 u8MPC_432_EquipmentSLA);
extern uint8 Com_CAN_SignalParse_TX_432_MPC_432_EquipmentTJA_ICA(uint8 u8MPC_432_EquipmentTJA_ICA);
extern uint8 Com_CAN_SignalParse_TX_432_MPC_432_IsEquipmentWarningMode(uint8 u8MPC_432_IsEquipmentWarningMode);
extern uint8 Com_CAN_SignalParse_TX_432_MPC_432_ModuleManufacturer(uint8 u8MPC_432_ModuleManufacturer);

extern uint8 Com_CAN_SignalParse_TX_432_MPC_432_PADDING_BIT3(uint8 u8MPC_432_PADDING_BIT3);
extern uint8 Com_CAN_SignalParse_TX_432_MPC_432_PADDING_BIT16_1(uint16 u16MPC_432_PADDING_BIT16_1);
extern uint8 Com_CAN_SignalParse_TX_432_MPC_432_PADDING_BIT16_2(uint16 u16MPC_432_PADDING_BIT16_2);
extern uint8 Com_CAN_SignalParse_TX_432_MPC_432_PADDING_BIT16_3(uint16 u16MPC_432_PADDING_BIT16_3);

extern uint8 Com_CAN_SignalParse_TX_32D_MPC_32D_vSetDis(float32 f32MPC_32D_vSetDis);
extern uint8 Com_CAN_SignalParse_TX_32D_MPC_32D_ObjValid(uint8 u8MPC_32D_ObjValid);
extern uint8 Com_CAN_SignalParse_TX_32D_MPC_32D_TauGapSet(uint8 u8MPC_32D_TauGapSet);
extern uint8 Com_CAN_SignalParse_TX_32D_MPC_32D_DxTarObj(uint8 u8MPC_32D_DxTarObj);

extern uint8 Com_CAN_SignalParse_TX_32D_MPC_32D_PCWPreWarning(uint8 u8MPC_32D_PCWPreWarning);
extern uint8 Com_CAN_SignalParse_TX_32D_MPC_32D_PCWLatentWarning(uint8 u8MPC_32D_PCWLatentWarning);
extern uint8 Com_CAN_SignalParse_TX_32D_MPC_32D_PCW_state(uint8 u8MPC_32D_PCW_state);
extern uint8 Com_CAN_SignalParse_TX_32D_MPC_32D_ACCModeDisplay(uint8 u8MPC_32D_ACCModeDisplay);

extern uint8 Com_CAN_SignalParse_TX_32D_MPC_32D_ACCState(uint8 u8MPC_32D_ACCState);
extern uint8 Com_CAN_SignalParse_TX_32D_MPC_32D_TakeOverReq(uint8 u8MPC_32D_TakeOverReq);
extern uint8 Com_CAN_SignalParse_TX_32D_MPC_32D_ACCTextInfoForDriver(uint8 u8MPC_32D_ACCTextInfoForDriver);
extern uint8 Com_CAN_SignalParse_TX_32D_MPC_32D_AEBState(uint8 u8MPC_32D_AEBState);

extern uint8 Com_CAN_SignalParse_TX_32D_MPC_32D_AcuteWarning(uint8 u8MPC_32D_AcuteWarning);
extern uint8 Com_CAN_SignalParse_TX_32D_MPC_32D_SpeedUnit(uint8 u8MPC_32D_SpeedUnit);
extern uint8 Com_CAN_SignalParse_TX_32D_MPC_32D_CCR_AEBError(uint8 u8MPC_32D_CCR_AEBError);
extern uint8 Com_CAN_SignalParse_TX_32D_MPC_32D_CCR_FCWError(uint8 u8MPC_32D_CCR_FCWError);

extern uint8 Com_CAN_SignalParse_TX_32D_MPC_32D_VRU_FCWError(uint8 u8MPC_32D_VRU_FCWError);
extern uint8 Com_CAN_SignalParse_TX_32D_MPC_32D_PADDING_BIT1(uint8 u8MPC_32D_PADDING_BIT1);
extern uint8 Com_CAN_SignalParse_TX_32D_MPC_32D_PADDING_BIT3(uint8 u8MPC_32D_PADDING_BIT3);
extern uint8 Com_CAN_SignalParse_TX_32D_MPC_32D_PADDING_BIT8(uint8 u8MPC_32D_PADDING_BIT8);

extern uint8 Com_CAN_SignalParse_TX_32D_MPC_32D_PADDING_BIT4(uint8 u8MPC_32D_PADDING_BIT4);
extern uint8 Com_CAN_SignalParse_TX_32D_MPC_32E_AliveCounter(uint8 u8MPC_32E_AliveCounter);
extern uint8 Com_CAN_SignalParse_TX_32D_MPC_32D_CheckSum(uint8 u8MPC_32D_CheckSum);
extern uint8 Com_CAN_SignalParse_TX_32E_MPC_32E_axvCvAim(float32 f32MPC_32E_axvCvAim);
extern uint8 Com_CAN_SignalParse_TX_32E_MPC_32E_axvCvUpperValue(float32 f32MPC_32E_axvCvUpperValue);
extern uint8 Com_CAN_SignalParse_TX_32E_MPC_32E_axvCvLowerValue(float32 f32MPC_32E_axvCvLowerValue);

extern uint8 Com_CAN_SignalParse_TX_32E_MPC_32E_aDtUpperLimitAxvCv(float32 f32MPC_32E_aDtUpperLimitAxvCv);
extern uint8 Com_CAN_SignalParse_TX_32E_MPC_32E_aDtLowerLimitAxvCv(float32 f32MPC_32E_aDtLowerLimitAxvCv);
extern uint8 Com_CAN_SignalParse_TX_32E_MPC_32E_ACC_Minimum_Braking(uint8 u8MPC_32E_ACC_Minimum_Braking);
extern uint8 Com_CAN_SignalParse_TX_32E_MPC_32E_ESC_VLC_ShutDownMode(uint8 u8MPC_32E_ESC_VLC_ShutDownMode);

extern uint8 Com_CAN_SignalParse_TX_32E_MPC_32E_ACCDriveOffReq(uint8 u8MPC_32E_ACCDriveOffReq);
extern uint8 Com_CAN_SignalParse_TX_32E_MPC_32E_ACCDecToStopReq(uint8 u8MPC_32E_ACCDecToStopReq);
extern uint8 Com_CAN_SignalParse_TX_32E_MPC_32E_ACCMode(uint8 u8MPC_32E_ACCMode);
extern uint8 Com_CAN_SignalParse_TX_32E_MPC_32E_BrakePreferred(uint8 u8MPC_32E_BrakePreferred);

extern uint8 Com_CAN_SignalParse_TX_32E_MPC_32E_PADDING_BIT4(uint8 u8MPC_32E_PADDING_BIT1_4);
extern uint8 Com_CAN_SignalParse_TX_32E_MPC_32E_PADDING_BIT1_1(uint8 u8MPC_32E_PADDING_BIT1_1);

extern uint8 Com_CAN_SignalParse_TX_32E_MPC_32E_CheckSum(uint8 u8MPC_32E_CheckSum);
extern uint8 Com_CAN_SignalParse_TX_32E_MPC_32E_AliveCounter(uint8 u8MPC_32E_AliveCounter);
extern uint8 Com_CAN_SignalParse_TX_32F_MPC_32F_AEBaxTarAEB(float32 f32MPC_32F_AEBaxTarAEB);
extern uint8 Com_CAN_SignalParse_TX_32F_MPC_32F_Prefill(uint8 u8MPC_32F_Prefill);

extern uint8 Com_CAN_SignalParse_TX_32F_MPC_32F_AWBRequest(uint8 u8MPC_32F_AWBRequest);
extern uint8 Com_CAN_SignalParse_TX_32F_MPC_32F_ABARequest(uint8 u8MPC_32F_ABARequest);
extern uint8 Com_CAN_SignalParse_TX_32F_MPC_32F_ABALevel(uint8 u8MPC_32F_ABALevel);
extern uint8 Com_CAN_SignalParse_TX_32F_MPC_32F_AEBDecCtrlRequest(uint8 u8MPC_32F_AEBDecCtrlRequest);

extern uint8 Com_CAN_SignalParse_TX_32F_MPC_32F_AWBLevel(uint8 u8MPC_32F_AWBLevel);
extern uint8 Com_CAN_SignalParse_TX_32F_MPC_32F_EBADecelerationControl(uint8 u8MPC_32F_EBADecelerationControl);
extern uint8 Com_CAN_SignalParse_TX_32F_MPC_32F_RequestESCHoldVehicle(uint8 u8MPC_32F_RequestESCHoldVehicle);
extern uint8 Com_CAN_SignalParse_TX_32F_MPC_32F_PADDING_BIT1(uint8 u8MPC_32F_PADDING_BIT1);

extern uint8 Com_CAN_SignalParse_TX_32F_MPC_32F_PADDING_BIT4_1(uint8 u8MPC_32F_PADDING_BIT4_1);
extern uint8 Com_CAN_SignalParse_TX_32F_MPC_32F_PADDING_BIT7(uint8 u8MPC_32F_PADDING_BIT7);
extern uint8 Com_CAN_SignalParse_TX_32F_MPC_32F_PADDING_BIT8(uint8 u8MPC_32F_PADDING_BIT8);
extern uint8 Com_CAN_SignalParse_TX_32F_MPC_32F_PADDING_BIT4_2(uint8 u8MPC_32F_PADDING_BIT4_2);

extern uint8 Com_CAN_SignalParse_TX_32F_MPC_32F_AliveCounter(uint8 u8MPC_32F_AliveCounter);
extern uint8 Com_CAN_SignalParse_TX_32F_MPC_32F_CheckSum(uint8 u8MPC_32F_CheckSum);

extern uint8 Com_CAN_SignalParse_RX_11F_SAS_11F_FailureStatus(void);
extern uint8 Com_CAN_SignalParse_RX_11F_SAS_11F_CalibrationStatus(void);
extern uint16 Com_CAN_SignalParse_RX_11F_SAS_11F_SWRotationSpeed(void);
extern float32 Com_CAN_SignalParse_RX_11F_SAS_11F_SteeringWheelAngle(void);

extern uint8 Com_CAN_SignalParse_RX_121_ESC_121_VehicleSpeedStatus(void);
extern float32 Com_CAN_SignalParse_RX_121_ESC_121_VehicleSpeed(void);
extern uint8 Com_CAN_SignalParse_RX_121_ESC_121_AWBavailable(void);
extern uint8 Com_CAN_SignalParse_RX_121_ESC_121_AWBactive(void);

extern uint8 Com_CAN_SignalParse_RX_121_ESC_121_AEBdecActive(void);
extern uint8 Com_CAN_SignalParse_RX_121_ESC_121_AEBnotAvailable(void);
extern uint8 Com_CAN_SignalParse_RX_121_ESC_121_PrefillAvailable(void);
extern uint8 Com_CAN_SignalParse_RX_121_ESC_121_PrefillActive(void);

extern uint8 Com_CAN_SignalParse_RX_121_ESC_121_ABAavailable(void);
extern uint8 Com_CAN_SignalParse_RX_121_ESC_121_ABAactive(void);
extern uint16 Com_CAN_SignalParse_RX_422_ESC_422_FLWheelPulseCounter(void);
extern uint8 Com_CAN_SignalParse_RX_422_ESC_422_FLWheelPulseCounterValid(void);

extern uint16 Com_CAN_SignalParse_RX_422_ESC_422_FRWheelPulseCounter(void);
extern uint8 Com_CAN_SignalParse_RX_422_ESC_422_FRWheelPulseCounterValid(void);
extern uint16 Com_CAN_SignalParse_RX_422_ESC_422_RLWheelPulseCounter(void);
extern uint8 Com_CAN_SignalParse_RX_422_ESC_422_RLWheelPulseCounterValid(void);

extern uint16 Com_CAN_SignalParse_RX_422_ESC_422_RRWheelPulseCounter(void);
extern uint8 Com_CAN_SignalParse_RX_422_ESC_422_RRWheelPulseCounterValid(void);
extern uint8 Com_CAN_SignalParse_RX_220_ESC_220_RRWheelDriveDirection(void);
extern uint8 Com_CAN_SignalParse_RX_220_ESC_220_RLWheelDriveDirection(void);

extern uint8 Com_CAN_SignalParse_RX_220_ESC_220_FRWheelDriveDirection(void);
extern uint8 Com_CAN_SignalParse_RX_220_ESC_220_FLWheelDriveDirection(void);
extern float32 Com_CAN_SignalParse_RX_220_ESC_220_VLCInternalTargetAccelerat(void);
extern uint8 Com_CAN_SignalParse_RX_220_ESC_220_CDD_Available(void);

extern uint8 Com_CAN_SignalParse_RX_220_ESC_220_CDDActive(void);
extern uint8 Com_CAN_SignalParse_RX_220_ESC_220_CDD_Fail(void);
extern uint8 Com_CAN_SignalParse_RX_220_ESC_220_NoBrakeForce(void);
extern uint8 Com_CAN_SignalParse_RX_220_ESC_220_ECDTempOff(void);

extern uint8 Com_CAN_SignalParse_RX_220_ESC_220_FLWheelDriveDirectionStau(void);
extern uint8 Com_CAN_SignalParse_RX_220_ESC_220_FRWheelDriveDirectionStau(void);
extern uint8 Com_CAN_SignalParse_RX_220_ESC_220_RLWheelDriveDirectionStau(void);
extern uint8 Com_CAN_SignalParse_RX_220_ESC_220_RRWheelDriveDirectionStau(void);

extern uint8 Com_CAN_SignalParse_RX_220_ESC_220_ActiveVehicleHold(void);
extern uint8 Com_CAN_SignalParse_RX_220_ESC_220_VLCAvailable(void);
extern uint8 Com_CAN_SignalParse_RX_220_ESC_220_VLCActive(void);
extern uint8 Com_CAN_SignalParse_RX_220_ESC_220_VLCFail(void);

extern uint8 Com_CAN_SignalParse_RX_220_ESC_220_QDCACC(void);
extern uint8 Com_CAN_SignalParse_RX_220_ESC_220_VehicleStandstill(void);
extern uint8 Com_CAN_SignalParse_RX_212_TCU_212_ActualShiftMode(void);
extern uint8 Com_CAN_SignalParse_RX_212_TCU_212_ActualGear(void);

extern uint8 Com_CAN_SignalParse_RX_212_TCU_212_ShiftProgressState(void);
extern uint8 Com_CAN_SignalParse_RX_212_TCU_212_ShiftProgressStatus(void);
extern float32 Com_CAN_SignalParse_RX_1F0_ESC_1F0_WheelSpeedFL(void);
extern float32 Com_CAN_SignalParse_RX_1F0_ESC_1F0_WheelSpeedFR(void);

extern float32 Com_CAN_SignalParse_RX_1F0_ESC_1F0_WheelSpeedRL(void);
extern float32 Com_CAN_SignalParse_RX_1F0_ESC_1F0_WheelSpeedRR(void);
extern float32 Com_CAN_SignalParse_RX_2F1_AC_2F1_AmbientTemperature(void);
extern uint8 Com_CAN_SignalParse_RX_2F1_AC_2F1_AmbientTemperatureInvalid(void);

extern uint8 Com_CAN_SignalParse_RX_342_VCU_342_TargetGear(void);

extern uint8 Com_CAN_SignalParse_RX_318_EPS_318_EPSLKACtrlSt(void);

extern uint8 Com_CAN_SignalParse_RX_135_EPS_135_EPS_APA_CtrlSts(void);
extern uint8 Com_CAN_SignalParse_RX_135_EPS_135_EPS_InterDect(void);
extern uint8 Com_CAN_SignalParse_RX_135_EPS_135_EPS_InterDectVD(void);

extern uint8 Com_CAN_SignalParse_RX_35C_SCU_35C_SCU_SCUAPASts(void);

extern uint8 Com_CAN_SignalParse_RX_222_ESC_222_ESC_APA_Status(void);
#endif

#endif
