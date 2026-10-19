/*
 * 
 * @Descripttion: 
 * 
 * @Date: 2020-05-15 15:58:56
 * @version: 
 * @LastEditTime: 2020-09-28 09:42:07
 */ 

#ifndef DR_STRUCTS
#define DR_STRUCTS

#include "adas_types.h"
#include "adas_data_list.h"


/**
 * @explanation : CAN data structure 
 */
typedef struct _DR_CAN_DATA_TAG_
{
    /* data */
    uint64_t    u64Timestamp;        // ms
	float32_t   f32SteeringAngle;    // Steer Wheel Aange  deg
    uint16_t    u16WheelPulseFL;    // head left wheel pulse
    uint16_t    u16WheelPulseFR;    // head left wheel pulse
    uint16_t    u16WheelPulseRL;    // rear left wheel pulse
    uint16_t    u16WheelPulseRR;    // rear right wheel pulse
	uint8_t     u8ShiftPos;         // VehMovState 0x0:parked; 0x1:Neutral; 0x2:Forward; 0x3:Reward
	uint8_t     u8Gear;             // vehicle gear

	uint8_t     u8Res[2];    
}ST_DR_CAN_DATA;

/**
 * @explanation : Vehicle position structure 
 */
typedef struct _DR_VEHICLE_POSITION_TAG_
{
    uint64_t   u64Timestamp;     // ns
    float32_t  f32X_Coor;        // x coordinate of vehicle position,(m)
    float32_t  f32Y_Coor;        // y coordinate of vehicle position,(m)
    float32_t  f32Theta;         // heading degree of vehicle, [-PI, PI]
    float32_t  f32Track;         // distance from origin to the current position
    float32_t  f32X_CoorFront;   // x coordinate of vehicle position,(m)
    float32_t  f32Y_CoorFront;   // y coordinate of vehicle position,(m)
    float32_t  f32ThetaFront;    // heading degree of vehicle, [-PI, PI]
    float32_t  f32TrackFront;    // distance from origin to the current position
    float32_t  f32X_CoorRear;    // x coordinate of vehicle position,(m)
    float32_t  f32Y_CoorRear;    // y coordinate of vehicle position,(m)
    float32_t  f32ThetaRear;     // heading degree of vehicle, [-PI, PI]
    float32_t  f32TrackRear;     // distance from origin to the current position
}tDrVehiclePosition;

/**
 * @explanation : Vehicle parameter data structure
 */
typedef struct _DR_VEH_PARAM_TAG_
{
	float32_t  f32WhlBase;      // Vehicle wheel base, m
	float32_t  f32VehWidth;     // Vehicle width, m 
//	float32_t  f32Coff[24];     // Ackerman fitting curve coefficient
    float32_t  f32PlsOffset;    // Uint wheel pulse distance

    float32_t f32VehWidth90Left_forward;
    float32_t f32VehWidth180Left_forward;
    float32_t f32VehWidth270Left_forward;
    float32_t f32VehWidth360Left_forward;
    float32_t f32VehWidth450Left_forward;
    float32_t f32VehWidthMaxLeft_forward;
    float32_t f32VehWidth90Right_forward;
    float32_t f32VehWidth180Right_forward;
    float32_t f32VehWidth270Right_forward;
    float32_t f32VehWidth360Right_forward;
    float32_t f32VehWidth450Right_forward;
    float32_t f32VehWidthMaxRight_forward;

    float32_t f32VehWidth90Left_backward;
    float32_t f32VehWidth180Left_backward;
    float32_t f32VehWidth270Left_backward;
    float32_t f32VehWidth360Left_backward;
    float32_t f32VehWidth450Left_backward;
    float32_t f32VehWidthMaxLeft_backward;
    float32_t f32VehWidth90Right_backward;
    float32_t f32VehWidth180Right_backward;
    float32_t f32VehWidth270Right_backward;
    float32_t f32VehWidth360Right_backward;
    float32_t f32VehWidth450Right_backward;
    float32_t f32VehWidthMaxRight_backward;

    float32_t f32FP3;
    float32_t f32FP2;
    float32_t f32FP1;
    float32_t f32FP0;

    float32_t f32RP3;
    float32_t f32RP2;
    float32_t f32RP1;
    float32_t f32RP0;

	uint32_t u32MaxPls;       // Maximum number of wheel pulse (from 1)
}ST_DR_VEH_PARAM;

typedef struct _DR_MOVE_INFO_TAG_
{
    float32_t f32FlPlusNums;
    float32_t f32FrPlusNums;
    float32_t f32RlPlusNums;
    float32_t f32RrPlusNums;
    uint64_t f32DataTime;
    float32_t f32TrackOffset;
    float32_t f32ThetaOfffset;
    float32_t f32TrackOffsetFront;
    float32_t f32ThetaOfffsetFront;
    float32_t f32TrackOffsetRear;
    float32_t f32ThetaOfffsetRear;
}ST_DR_MOVE_INFO;

typedef struct _DR_INFO_TAG_
{
    ST_DR_CAN_DATA     		stLastCAN;     
    tDrVehiclePosition      stVehPos;      // During DR calculation.
    tDrVehiclePosition      stVehPosPre;   
    ST_DR_VEH_PARAM    	 	stVehParam;    
    ST_DR_MOVE_INFO    	 	stMoveInfo;
    tDrVehiclePosition      stNowPose;     // Final result, get from stVehPos.

    DataList    stThetaList;
    DataList    stWhlPlsRearLeftList;
    DataList    stWhlPlsRearRightList;
    DataList    stWhlPlsFrontLeftList;
    DataList    stWhlPlsFrontRightList;
    int32_t 	s32Flag;
} ST_DR_INFO,*PST_DR_INFO;

#endif
