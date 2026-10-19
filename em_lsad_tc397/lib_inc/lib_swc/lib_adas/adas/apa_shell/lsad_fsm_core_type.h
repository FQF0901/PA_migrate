/*
 * File: lsad_fsm_core_type.h
 *
 * Code generated for Simulink model 'lsad_fsm_core'.
 *
 * Model version                  : 1.131
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Dec  2 16:05:03 2024
 */

#ifndef RTW_HEADER_lsad_fsm_core_type_h_
#define RTW_HEADER_lsad_fsm_core_type_h_
#include "emos_rte.h"
#include "adas_struct.h"
#include "rtwtypes.h"

typedef struct
{
  tAPA_PathPlanSts ePathPlanSts;
  tAPA_CtrlSts eCtrlSts;
  tAPA_UltrasonicSts eUltrasonicSts;
  tHandshakeSts eHandshakeSts;
  ELocStatus eLocSts;
  tAPA_DataFusionSts eDataFusionSts;
  tSupportSts eUssSupportActive;
  EMapCreatorState eMappingSts;
  tHandshakeFailReason eHandshakeFailReason;
  tHandshakeType eHandshakeType;
  tHandshakeTypeRq eHandshakeTypeReq;
  tVehiGear eHandshakeGearReq;
  real32_T f32RARecordedDist;
  real32_T f32CtrlReqStopDistance;
  real32_T f32X_Coor;
  real32_T f32Y_Coor;
  real32_T f32Theta;
  uint8_T u8CtrlReqPause;
  uint8_T u8ParkoutDir;
  uint8_T u8Res[2];
}
tRelatedModuleInfo;

#endif                                 /* RTW_HEADER_lsad_fsm_core_type_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
