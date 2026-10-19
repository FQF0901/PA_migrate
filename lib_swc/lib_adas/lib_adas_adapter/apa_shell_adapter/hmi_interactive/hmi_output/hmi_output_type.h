/*
 * File: hmi_output_type.h
 *
 * Code generated for Simulink model 'lsad_fsm_adapter'.
 *
 * Model version                  : 1.132
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Thu Nov 28 16:38:14 2024
 */

#ifndef RTW_HEADER_hmi_output_type_h_
#define RTW_HEADER_hmi_output_type_h_
#include "rtwtypes.h"

typedef struct
{
  real32_T ADCS4_PA_GuideLineE_a;
  real32_T ADCS4_PA_GuideLineE_b;
  real32_T ADCS4_PA_GuideLineE_c;
  real32_T ADCS4_PA_GuideLineE_d;
  real32_T ADCS4_PA_GuideLineE_Xmin;
  real32_T ADCS4_PA_GuideLineE_Xmax;
  uint16_T ADCS4_ParkingTime;
  uint16_T ADCS11_NNS_distance;
  real32_T ADCS11_PA_StopDistance;
  uint8_T ADCS11_Parking_WorkSts;
  uint8_T ADCS11_Currentgear;
  uint8_T ADCS4_PA_failinfo;
  uint8_T ADCS4_PA_ParkBarPercent;
  uint8_T ADCS4_APA_FunctionMode;
  uint8_T ADCS4_Text;
  uint8_T ADCS4_ParkingswithReq;
  uint8_T ADCS4_Slotavaliable;
  uint8_T ADCS4_AVM_vedioReq;
  uint8_T ADCS4_RPA_FunctionMode;
  uint8_T ADCS8_PA_warninginfo;
  uint8_T ADCS4_TractionswithReq;
  uint8_T ADCS8_TBA_text;
  uint8_T ADCS4_TBA_Distance;
  uint8_T ADCS8_RPA_CheckListDispReq8;
  uint8_T ADCS8_RPA_CheckListDispReq7;
  uint8_T ADCS8_RPA_CheckListDispReq6;
  uint8_T ADCS8_RPA_CheckListDispReq5;
  uint8_T ADCS8_RPA_CheckListDispReq4;
  uint8_T ADCS8_RPA_CheckListDispReq3;
  uint8_T ADCS8_RPA_CheckListDispReq2;
  uint8_T ADCS8_RPA_CheckListDispReq1;
  uint8_T ADCS11_APA_requestMirrorFoldSt;
  boolean_T u8Res;
}

tPADispTx;

typedef struct
{
  real32_T ADCS5_RPA_slot_ID_1_P0_X;
  real32_T ADCS5_RPA_slot_ID_1_P0_Y;
  real32_T ADCS5_RPA_slot_ID_1_P1_X;
  real32_T ADCS5_RPA_slot_ID_1_P1_Y;
  real32_T ADCS5_RPA_slot_ID_1_P2_X;
  real32_T ADCS5_RPA_slot_ID_1_P2_Y;
  real32_T ADCS5_RPA_slot_ID_1_P3_X;
  real32_T ADCS5_RPA_slot_ID_1_P3_Y;
  real32_T ADCS5_RPA_slot_Angle1;
  real32_T ADCS5_RPA_ParkingSlotDepth1;
  real32_T ADCS5_RPA_ParkingSlotWidth1;
  uint8_T ADCS5_RPA_slot_ID_1_Status;
  uint8_T ADCS5_RPA_ParkingSlotType1;
  uint8_T ADCS5_RPA_ParkingSlotDirection1;
  real32_T ADCS5_RPA_slot_ID_2_P0_X;
  real32_T ADCS5_RPA_slot_ID_2_P0_Y;
  real32_T ADCS5_RPA_slot_ID_2_P1_X;
  real32_T ADCS5_RPA_slot_ID_2_P1_Y;
  real32_T ADCS5_RPA_slot_ID_2_P2_X;
  real32_T ADCS5_RPA_slot_ID_2_P2_Y;
  real32_T ADCS5_RPA_slot_ID_2_P3_X;
  real32_T ADCS5_RPA_slot_ID_2_P3_Y;
  real32_T ADCS5_RPA_slot_Angle2;
  real32_T ADCS5_RPA_ParkingSlotDepth2;
  real32_T ADCS5_RPA_ParkingSlotWidth2;
  uint8_T ADCS5_RPA_slot_ID_2_Status;
  uint8_T ADCS5_RPA_ParkingSlotType2;
  uint8_T ADCS5_RPA_ParkingSlotDirection2;
  real32_T ADCS5_RPA_slot_ID_3_P0_X;
  real32_T ADCS5_RPA_slot_ID_3_P0_Y;
  real32_T ADCS5_RPA_slot_ID_3_P1_X;
  real32_T ADCS5_RPA_slot_ID_3_P1_Y;
  real32_T ADCS5_RPA_slot_ID_3_P2_X;
  real32_T ADCS5_RPA_slot_ID_3_P2_Y;
  real32_T ADCS5_RPA_slot_ID_3_P3_X;
  real32_T ADCS5_RPA_slot_ID_3_P3_Y;
  real32_T ADCS5_RPA_slot_Angle3;
  real32_T ADCS5_RPA_ParkingSlotDepth3;
  real32_T ADCS5_RPA_ParkingSlotWidth3;
  uint8_T ADCS5_RPA_slot_ID_3_Status;
  uint8_T ADCS5_RPA_ParkingSlotType3;
  uint8_T ADCS5_RPA_ParkingSlotDirection3;
  real32_T ADCS6_RPA_slot_ID_4_P0_X;
  real32_T ADCS6_RPA_slot_ID_4_P0_Y;
  real32_T ADCS6_RPA_slot_ID_4_P1_X;
  real32_T ADCS6_RPA_slot_ID_4_P1_Y;
  real32_T ADCS6_RPA_slot_ID_4_P2_X;
  real32_T ADCS6_RPA_slot_ID_4_P2_Y;
  real32_T ADCS6_RPA_slot_ID_4_P3_X;
  real32_T ADCS6_RPA_slot_ID_4_P3_Y;
  real32_T ADCS6_RPA_slot_Angle4;
  real32_T ADCS6_RPA_ParkingSlotDepth4;
  real32_T ADCS6_RPA_ParkingSlotWidth4;
  uint8_T ADCS6_RPA_slot_ID_4_Status;
  uint8_T ADCS6_RPA_ParkingSlotType4;
  uint8_T ADCS6_RPA_ParkingSlotDirection4;
  real32_T ADCS6_RPA_slot_ID_5_P0_X;
  real32_T ADCS6_RPA_slot_ID_5_P0_Y;
  real32_T ADCS6_RPA_slot_ID_5_P1_X;
  real32_T ADCS6_RPA_slot_ID_5_P1_Y;
  real32_T ADCS6_RPA_slot_ID_5_P2_X;
  real32_T ADCS6_RPA_slot_ID_5_P2_Y;
  real32_T ADCS6_RPA_slot_ID_5_P3_X;
  real32_T ADCS6_RPA_slot_ID_5_P3_Y;
  real32_T ADCS6_RPA_slot_Angle5;
  real32_T ADCS6_RPA_ParkingSlotDepth5;
  real32_T ADCS6_RPA_ParkingSlotWidth5;
  uint8_T ADCS6_RPA_slot_ID_5_Status;
  uint8_T ADCS6_RPA_ParkingSlotType5;
  uint8_T ADCS6_RPA_ParkingSlotDirection5;
  real32_T ADCS6_RPA_slot_ID_6_P0_X;
  real32_T ADCS6_RPA_slot_ID_6_P0_Y;
  real32_T ADCS6_RPA_slot_ID_6_P1_X;
  real32_T ADCS6_RPA_slot_ID_6_P1_Y;
  real32_T ADCS6_RPA_slot_ID_6_P2_X;
  real32_T ADCS6_RPA_slot_ID_6_P2_Y;
  real32_T ADCS6_RPA_slot_ID_6_P3_X;
  real32_T ADCS6_RPA_slot_ID_6_P3_Y;
  real32_T ADCS6_RPA_slot_Angle6;
  real32_T ADCS6_RPA_ParkingSlotDepth6;
  real32_T ADCS6_RPA_ParkingSlotWidth6;
  uint8_T ADCS6_RPA_slot_ID_6_Status;
  uint8_T ADCS6_RPA_ParkingSlotType6;
  uint8_T ADCS6_RPA_ParkingSlotDirection6;
  real32_T ADCS7_RPA_slot_ID_7_P0_X;
  real32_T ADCS7_RPA_slot_ID_7_P0_Y;
  real32_T ADCS7_RPA_slot_ID_7_P1_X;
  real32_T ADCS7_RPA_slot_ID_7_P1_Y;
  real32_T ADCS7_RPA_slot_ID_7_P2_X;
  real32_T ADCS7_RPA_slot_ID_7_P2_Y;
  real32_T ADCS7_RPA_slot_ID_7_P3_X;
  real32_T ADCS7_RPA_slot_ID_7_P3_Y;
  real32_T ADCS7_RPA_slot_Angle7;
  real32_T ADCS7_RPA_ParkingSlotDepth7;
  real32_T ADCS7_RPA_ParkingSlotWidth7;
  uint8_T ADCS7_RPA_slot_ID_7_Status;
  uint8_T ADCS7_RPA_ParkingSlotType7;
  uint8_T ADCS7_RPA_ParkingSlotDirection7;
  real32_T ADCS7_RPA_slot_ID_8_P0_X;
  real32_T ADCS7_RPA_slot_ID_8_P0_Y;
  real32_T ADCS7_RPA_slot_ID_8_P1_X;
  real32_T ADCS7_RPA_slot_ID_8_P1_Y;
  real32_T ADCS7_RPA_slot_ID_8_P2_X;
  real32_T ADCS7_RPA_slot_ID_8_P2_Y;
  real32_T ADCS7_RPA_slot_ID_8_P3_X;
  real32_T ADCS7_RPA_slot_ID_8_P3_Y;
  real32_T ADCS7_RPA_slot_Angle8;
  real32_T ADCS7_RPA_ParkingSlotDepth8;
  real32_T ADCS7_RPA_ParkingSlotWidth8;
  uint8_T ADCS7_RPA_slot_ID_8_Status;
  uint8_T ADCS7_RPA_ParkingSlotType8;
  uint8_T ADCS7_RPA_ParkingSlotDirection8;
  real32_T ADCS5_RPA_slot_ID_9_P0_X;
  real32_T ADCS5_RPA_slot_ID_9_P0_Y;
  real32_T ADCS5_RPA_slot_ID_9_P1_X;
  real32_T ADCS5_RPA_slot_ID_9_P1_Y;
  real32_T ADCS5_RPA_slot_ID_9_P2_X;
  real32_T ADCS5_RPA_slot_ID_9_P2_Y;
  real32_T ADCS5_RPA_slot_ID_9_P3_X;
  real32_T ADCS5_RPA_slot_ID_9_P3_Y;
  real32_T ADCS5_RPA_slot_Angle9;
  real32_T ADCS5_RPA_ParkingSlotDepth9;
  real32_T ADCS5_RPA_ParkingSlotWidth9;
  uint8_T ADCS5_RPA_slot_ID_9_Status;
  uint8_T ADCS5_RPA_ParkingSlotType9;
  uint8_T ADCS5_RPA_ParkingSlotDirection9;
  real32_T ADCS5_RPA_slot_ID_10_P0_X;
  real32_T ADCS5_RPA_slot_ID_10_P0_Y;
  real32_T ADCS5_RPA_slot_ID_10_P1_X;
  real32_T ADCS5_RPA_slot_ID_10_P1_Y;
  real32_T ADCS5_RPA_slot_ID_10_P2_X;
  real32_T ADCS5_RPA_slot_ID_10_P2_Y;
  real32_T ADCS5_RPA_slot_ID_10_P3_X;
  real32_T ADCS5_RPA_slot_ID_10_P3_Y;
  real32_T ADCS5_RPA_slot_Angle10;
  real32_T ADCS5_RPA_ParkingSlotDepth10;
  real32_T ADCS5_RPA_ParkingSlotWidth10;
  uint8_T ADCS5_RPA_slot_ID_10_Status;
  uint8_T ADCS5_RPA_ParkingSlotType10;
  uint8_T ADCS5_RPA_ParkingSlotDirection10;
  real32_T ADCS5_RPA_slot_ID_11_P0_X;
  real32_T ADCS5_RPA_slot_ID_11_P0_Y;
  real32_T ADCS5_RPA_slot_ID_11_P1_X;
  real32_T ADCS5_RPA_slot_ID_11_P1_Y;
  real32_T ADCS5_RPA_slot_ID_11_P2_X;
  real32_T ADCS5_RPA_slot_ID_11_P2_Y;
  real32_T ADCS5_RPA_slot_ID_11_P3_X;
  real32_T ADCS5_RPA_slot_ID_11_P3_Y;
  real32_T ADCS5_RPA_slot_Angle11;
  real32_T ADCS5_RPA_ParkingSlotDepth11;
  real32_T ADCS5_RPA_ParkingSlotWidth11;
  uint8_T ADCS5_RPA_slot_ID_11_Status;
  uint8_T ADCS5_RPA_ParkingSlotType11;
  uint8_T ADCS5_RPA_ParkingSlotDirection11;
  real32_T ADCS5_RPA_slot_ID_12_P0_X;
  real32_T ADCS5_RPA_slot_ID_12_P0_Y;
  real32_T ADCS5_RPA_slot_ID_12_P1_X;
  real32_T ADCS5_RPA_slot_ID_12_P1_Y;
  real32_T ADCS5_RPA_slot_ID_12_P2_X;
  real32_T ADCS5_RPA_slot_ID_12_P2_Y;
  real32_T ADCS5_RPA_slot_ID_12_P3_X;
  real32_T ADCS5_RPA_slot_ID_12_P3_Y;
  real32_T ADCS5_RPA_slot_Angle12;
  real32_T ADCS5_RPA_ParkingSlotDepth12;
  real32_T ADCS5_RPA_ParkingSlotWidth12;
  uint8_T ADCS5_RPA_slot_ID_12_Status;
  uint8_T ADCS5_RPA_ParkingSlotType12;
  uint8_T ADCS5_RPA_ParkingSlotDirection12;
}

tPrkInSlotTx;

#endif                                 /* RTW_HEADER_hmi_output_type_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
