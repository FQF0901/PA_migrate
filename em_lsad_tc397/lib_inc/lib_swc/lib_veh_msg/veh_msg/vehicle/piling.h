
// #include "proj_global.h"
// #if (EM_VEHI_TYPE == VEHI_TYPE_MCE)
// #define COM_PDUTX_NUM       20U
// #define COM_PDURX_NUM       19U
// #elif (EM_VEHI_TYPE == VEHI_TYPE_HAN)
// #define COM_PDUTX_NUM       7U
// #define COM_PDURX_NUM       15U
// #endif


// #define u16Year         year
// #define u8Month         month
// #define u8Day           day
// #define u8Hour          hour
// #define u8Minute        minute
// #define u8Second        second
// #define u16MilliSecond  msec
// #define u16MicroSecond  usec


// typedef enum
// {
//     COM_PDUID_0X09D_RX          = 0,
//     COM_PDUID_0X0C1_RX,
//     COM_PDUID_0X0C5_RX,
//     COM_PDUID_0X185_RX,
//     COM_PDUID_0X1B1_RX,
//     COM_PDUID_0X1C7_RX,
//     COM_PDUID_0X1E5_RX,
//     COM_PDUID_0X1E9_RX,
//     COM_PDUID_0X22A_RX,
//     COM_PDUID_0X348_RX,
//     COM_PDUID_0X34A_RX,
//     COM_PDUID_0X353_RX,
//     COM_PDUID_0X1B6_RX,
//     COM_PDUID_0X3F1_RX,
//     COM_PDUID_0X0E0_RX,
//     COM_PDUID_0X541_RX,
//     COM_PDUID_0X529_RX,
//     COM_PDUID_0X530_RX,
//     COM_PDUID_0X201_RX,
//     COM_PDUID_NUM_RX,
// };
// /*======================================== type define ==============================================================*/
// /* TX MSG*/
// typedef struct
// {
//         uint8   APAToqReqValHSC2_H    :4;
//         uint8   APAToqReqStsHSC2      :1;
//         uint8   APAFHSC2              :1;
//         uint8   APACmdEPSStsHSC2      :2;
//         uint8   APAToqReqValHSC2_L    :8;
//         uint8  APATrgtEPSStrgWhlAngHSC2_H        :8;
//         uint8  APATrgtEPSStrgWhlAngHSC2_L        :8;
//         uint8   APAAlvRCHSC2          :8;
//         uint8   APAChksmHSC2          :8;
// }CAN_Frame_1A8_Type;

// typedef struct
// {
//         uint8   APASCSAcclReqValPVHSC2_H      :2;
//         uint8   APAMdHSC2             :3;
//         uint8   APAReqHSC2            :3;
//         uint8   APASCSAcclReqValPVHSC2_L      :8;
//         uint8   APASCSAcclReqValHSC2  :8;
//         uint8   APACrpSpdReqValHSC2   :6;
//         uint8   APAEPBOPReqHSC2       :2;
//         uint8   APAInfoDispReqHSC2    :6;
//         uint8   APANRCDAvlblHSC2      :1;
//         uint8   APACrpSpdReqStsHSC2   :1;
//         uint8   APAShifterPosReqdHSC2 :4;
//         uint8   APASCSAlvRCHSC2       :4;
//         uint8   APAEPBReqAlvRCHSC2    :4;
//         uint8   APAStsHSC2            :3;
//         uint8   APASCSAcclReqStsHSC2  :1;
//         uint8   APAEPBOpReqValPVHSC2  :8;
// }CAN_Frame_1B5_Type;

// typedef struct
// {
//         uint8   APASlotLngth_sech2_SecCAN2_H    :3;
//         uint8                                   :5;
//         uint8   APASlotLngth_sech2_SecCAN2_L    :8;
//         uint8   APAParkngSched_sech2_SecCAN2    :7;
//         uint8                                   :1;
//         uint8   APAVehCrdnatAzmth_sech2_SecCAN2_H       :1;
//         uint8   APAParkngSchedV_sech2_SecCAN2   :1;
//         uint8                                   :6;
//         uint8   APAVehCrdnatAzmth_sech2_SecCAN2_L       :8;
//         uint8   APAVehCrdnatPosX_sech2_SecCAN2_H        :6;
//         uint8   APASlotBearng_sech2_SecCAN2     :2;
//         uint8   APAVehCrdnatPosY_sech2_SecCAN2_H        :2;
//         uint8   APAVehCrdnatPosX_sech2_SecCAN2_L        :6;
//         uint8   APAVehCrdnatPosY_sech2_SecCAN2_L        :8;
// }CAN_Frame_3C6_Type;

// typedef struct
// {
//         uint8   RRObsDist_sech2_SecCAN2_H       :8;
//         uint8   RLObsDist_sech2_SecCAN2_H       :7;
//         uint8   RRObsDist_sech2_SecCAN2_L       :1;
//         uint8   FRObsDist_sech2_SecCAN2_H       :6;
//         uint8   RLObsDist_sech2_SecCAN2_L       :2;
//         uint8   FLObsDist_sech2_SecCAN2_H       :1;
//         uint8                                   :4;
//         uint8   FRObsDist_sech2_SecCAN2_L       :3;
//         uint8   FLObsDist_sech2_SecCAN2_L       :8;
// }CAN_Frame_28B_Type;

// typedef struct
// {
//         uint8   RrPDCAudWrnngHSC2     :4;
//         uint8   PDCSysStsHSC2         :4;
//         uint8   RrMidRObsRngHSC2      :4;
//         uint8   FrtPDCAudWrnngHSC2    :4;
//         uint8   FrtMidRObsRngHSC2     :4;
//         uint8   RrMidLObsRngHSC2      :4;
//         uint8   RRObsRngHSC2          :4;
//         uint8   FrtMidLObsRngHSC2     :4;
//         uint8   FRObsRngHSC2          :4;
//         uint8   RLObsRngHSC2          :4;
//         uint8   PDCCofignStsHSC2      :3;
//         uint8                                   :1;
//         uint8   FLObsRngHSC2          :4;
//         uint8   FrtObsDistHSC2        :8;
//         uint8   RrObsDistHSC2         :8;
// }CAN_Frame_23D_Type;

// typedef struct
// {
//         uint8   RRSideObsDistHSC2_H   :1;
//         uint8                                   :7;
//         uint8   RRSideObsDistHSC2_L   :8;
//         uint8   RLSideObsDistHSC2_H   :1;
//         uint8                                   :7;
//         uint8   RLSideObsDistHSC2_L   :8;
//         uint8   FRSideObsDistHSC2_H   :1;
//         uint8                                   :7;
//         uint8   FRSideObsDistHSC2_L   :8;
//         uint8   FLSideObsDistHSC2_H   :1;
//         uint8                                   :7;
//         uint8   FLSideObsDistHSC2_L   :8;
// }CAN_Frame_237_Type;
// typedef struct
// {
//         uint8   P2PACTMdChngTmotHSC4            :8;
//         uint8   P2PDisplayHSC4                  :8;
//         uint8   Route2StateHSC4                 :2;
//         uint8   Route1StateHSC4                 :2;
//         uint8   P2PProgressHSC4                 :4;
//         uint8   Route1SavePercentageHSC4        :7;
//         uint8                                   :1;
//         uint8   Route2SavePercentageHSC4        :7;
//         uint8                                   :1;
//         uint8   reserved1                       :8;
//         uint8                                   :8;
//         uint8                                   :8;
// }CAN_Frame_30D_Type;

// typedef struct
// {
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8   HD_AVMsysrdyHSC4                :1;
//         uint8                                   :7;
//         uint8   HD_AVMCurViewHSC4               :4;
//         uint8   HD_AVMVideoFmtStaHSC4           :4;
//         uint8   HD_AVMErrorDisplay_h4HSC4       :4;
//         uint8   HD_AVMInfoDisplayHSC4           :4;
// }CAN_Frame_2FC_Type;

// typedef struct
// {
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8   AutoDrvngSysStsHSC4             :8;
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8                                   :8;
// }CAN_Frame_390_Type;

// typedef struct
// {
//         uint8  left_1_DspMode_H                 :1;
//         uint8  left_0_id                        :5;
//         uint8  left_0_DspMode                   :2;
//         uint8  left_2_DspMode                   :2;
//         uint8  left_1_id                        :5;
//         uint8  left_1_DspMode_L                 :1;
//         uint8  left_3_id_H                      :1;
//         uint8  left_3_DspMode                   :2;
//         uint8  left_2_id                        :5;
//         uint8  right_0_id_H                     :2;
//         uint8  right_0_DspMode                  :2;
//         uint8  left_3_id_L                      :4;
//         uint8  right_1_id_H                     :3;
//         uint8  right_1_DspMode                  :2;
//         uint8  right_0_id_L                     :3;
//         uint8  right_2_id_H                     :4;
//         uint8  right_2_DspMode                  :2;
//         uint8  right_1_id_L                     :2;
//         uint8  right_3_id                       :5;
//         uint8  right_3_DspMode                  :2;
//         uint8  right_2_id_L                     :1;
//         uint8  rollingCnt                       :8;
// }CAN_Frame_531_Type;

// typedef struct
// {
//         uint8  left_5_DspMode_H                 :1;
//         uint8  left_4_id                        :5;
//         uint8  left_4_DspMode                   :2;
//         uint8  left_6_DspMode                   :2;
//         uint8  left_5_id                        :5;
//         uint8  left_5_DspMode_L                 :1;
//         uint8  left_7_id_H                      :1;
//         uint8  left_7_DspMode                   :2;
//         uint8  left_6_id                        :5;
//         uint8  right_4_id_H                     :2;
//         uint8  right_4_DspMode                  :2;
//         uint8  left_7_id_L                      :4;
//         uint8  right_5_id_H                     :3;
//         uint8  right_5_DspMode                  :2;
//         uint8  right_4_id_L                     :3;
//         uint8  right_6_id_H                     :4;
//         uint8  right_6_DspMode                  :2;
//         uint8  right_5_id_L                     :2;
//         uint8  right_7_id                       :5;
//         uint8  right_7_DspMode                  :2;
//         uint8  right_6_id_L                     :1;
//         uint8  rollingCnt                       :8;
// }CAN_Frame_545_Type;

// typedef struct
// {
//         uint8  LeftDspObjInfo_0_XHSC4_H         :2;
//         uint8  LeftDspObjInfo_0_ThetaHSC4       :6;
//         uint8  LeftDspObjInfo_0_XHSC4_L         :8;
//         uint8  LeftDspObjInfo_0_YHSC4_H         :8;
//         uint8                                   :1;
//         uint8  LeftDspObjInfo_0_TypeHSC4        :3;
//         uint8  LeftDspObjInfo_0_CounterHCS4     :2;
//         uint8  LeftDspObjInfo_0_YHSC4_L         :2;
//         uint8  RightDspObjInfo_0_XHSC4_H        :2;
//         uint8  RightDspObjInfo_0_ThetaHSC4      :6;
//         uint8  RightDspObjInfo_0_XHSC4_L        :8;
//         uint8  RightDspObjInfo_0_YHSC4_H        :8;
//         uint8                                   :1;
//         uint8  RightDspObjInfo_0_TypeHSC4       :3;
//         uint8  RightDspObjInfo_0_CounterHCS4    :2;
//         uint8  RightDspObjInfo_0_YHSC4_L        :2;
// }CAN_Frame_532_Type;

// typedef struct
// {
//         uint8  LeftDspObjInfo_1_XHSC4_H         :2;
//         uint8  LeftDspObjInfo_1_ThetaHSC4       :6;
//         uint8  LeftDspObjInfo_1_XHSC4_L         :8;
//         uint8  LeftDspObjInfo_1_YHSC4_H         :8;
//         uint8                                   :1;
//         uint8  LeftDspObjInfo_1_TypeHSC4        :3;
//         uint8  LeftDspObjInfo_1_CounterHCS4     :2;
//         uint8  LeftDspObjInfo_1_YHSC4_L         :2;
//         uint8  RightDspObjInfo_1_XHSC4_H        :2;
//         uint8  RightDspObjInfo_1_ThetaHSC4      :6;
//         uint8  RightDspObjInfo_1_XHSC4_L        :8;
//         uint8  RightDspObjInfo_1_YHSC4_H        :8;
//         uint8                                   :1;
//         uint8  RightDspObjInfo_1_TypeHSC4       :3;
//         uint8  RightDspObjInfo_1_CounterHCS4    :2;
//         uint8  RightDspObjInfo_1_YHSC4_L        :2;
// }CAN_Frame_539_Type;

// typedef struct
// {
//         uint8  LeftDspObjInfo_2_XHSC4_H         :2;
//         uint8  LeftDspObjInfo_2_ThetaHSC4       :6;
//         uint8  LeftDspObjInfo_2_XHSC4_L         :8;
//         uint8  LeftDspObjInfo_2_YHSC4_H         :8;
//         uint8                                   :1;
//         uint8  LeftDspObjInfo_2_TypeHSC4        :3;
//         uint8  LeftDspObjInfo_2_CounterHCS4     :2;
//         uint8  LeftDspObjInfo_2_YHSC4_L         :2;
//         uint8  RightDspObjInfo_2_XHSC4_H        :2;
//         uint8  RightDspObjInfo_2_ThetaHSC4      :6;
//         uint8  RightDspObjInfo_2_XHSC4_L        :8;
//         uint8  RightDspObjInfo_2_YHSC4_H        :8;
//         uint8                                   :1;
//         uint8  RightDspObjInfo_2_TypeHSC4       :3;
//         uint8  RightDspObjInfo_2_CounterHCS4    :2;
//         uint8  RightDspObjInfo_2_YHSC4_L        :2;
// }CAN_Frame_53B_Type;

// typedef struct
// {
//         uint8  LeftDspObjInfo_3_XHSC4_H         :2;
//         uint8  LeftDspObjInfo_3_ThetaHSC4       :6;
//         uint8  LeftDspObjInfo_3_XHSC4_L         :8;
//         uint8  LeftDspObjInfo_3_YHSC4_H         :8;
//         uint8                                   :1;
//         uint8  LeftDspObjInfo_3_TypeHSC4        :3;
//         uint8  LeftDspObjInfo_3_CounterHCS4     :2;
//         uint8  LeftDspObjInfo_3_YHSC4_L         :2;
//         uint8  RightDspObjInfo_3_XHSC4_H        :2;
//         uint8  RightDspObjInfo_3_ThetaHSC4      :6;
//         uint8  RightDspObjInfo_3_XHSC4_L        :8;
//         uint8  RightDspObjInfo_3_YHSC4_H        :8;
//         uint8                                   :1;
//         uint8  RightDspObjInfo_3_TypeHSC4       :3;
//         uint8  RightDspObjInfo_3_CounterHCS4    :2;
//         uint8  RightDspObjInfo_3_YHSC4_L        :2;
// }CAN_Frame_53C_Type;

// typedef struct
// {
//         uint8  LeftDspObjInfo_4_XHSC4_H         :2;
//         uint8  LeftDspObjInfo_4_ThetaHSC4       :6;
//         uint8  LeftDspObjInfo_4_XHSC4_L         :8;
//         uint8  LeftDspObjInfo_4_YHSC4_H         :8;
//         uint8                                   :1;
//         uint8  LeftDspObjInfo_4_TypeHSC4        :3;
//         uint8  LeftDspObjInfo_4_CounterHCS4     :2;
//         uint8  LeftDspObjInfo_4_YHSC4_L         :2;
//         uint8  RightDspObjInfo_4_XHSC4_H        :2;
//         uint8  RightDspObjInfo_4_ThetaHSC4      :6;
//         uint8  RightDspObjInfo_4_XHSC4_L        :8;
//         uint8  RightDspObjInfo_4_YHSC4_H        :8;
//         uint8                                   :1;
//         uint8  RightDspObjInfo_4_TypeHSC4       :3;
//         uint8  RightDspObjInfo_4_CounterHCS4    :2;
//         uint8  RightDspObjInfo_4_YHSC4_L        :2;
// }CAN_Frame_53D_Type;

// typedef struct
// {
//         uint8  LeftDspObjInfo_5_XHSC4_H         :2;
//         uint8  LeftDspObjInfo_5_ThetaHSC4       :6;
//         uint8  LeftDspObjInfo_5_XHSC4_L         :8;
//         uint8  LeftDspObjInfo_5_YHSC4_H         :8;
//         uint8                                   :1;
//         uint8  LeftDspObjInfo_5_TypeHSC4        :3;
//         uint8  LeftDspObjInfo_5_CounterHCS4     :2;
//         uint8  LeftDspObjInfo_5_YHSC4_L         :2;
//         uint8  RightDspObjInfo_5_XHSC4_H        :2;
//         uint8  RightDspObjInfo_5_ThetaHSC4      :6;
//         uint8  RightDspObjInfo_5_XHSC4_L        :8;
//         uint8  RightDspObjInfo_5_YHSC4_H        :8;
//         uint8                                   :1;
//         uint8  RightDspObjInfo_5_TypeHSC4       :3;
//         uint8  RightDspObjInfo_5_CounterHCS4    :2;
//         uint8  RightDspObjInfo_5_YHSC4_L        :2;
// }CAN_Frame_53E_Type;

// typedef struct
// {
//         uint8  LeftDspObjInfo_6_XHSC4_H         :2;
//         uint8  LeftDspObjInfo_6_ThetaHSC4       :6;
//         uint8  LeftDspObjInfo_6_XHSC4_L         :8;
//         uint8  LeftDspObjInfo_6_YHSC4_H         :8;
//         uint8                                   :1;
//         uint8  LeftDspObjInfo_6_TypeHSC4        :3;
//         uint8  LeftDspObjInfo_6_CounterHCS4     :2;
//         uint8  LeftDspObjInfo_6_YHSC4_L         :2;
//         uint8  RightDspObjInfo_6_XHSC4_H        :2;
//         uint8  RightDspObjInfo_6_ThetaHSC4      :6;
//         uint8  RightDspObjInfo_6_XHSC4_L        :8;
//         uint8  RightDspObjInfo_6_YHSC4_H        :8;
//         uint8                                   :1;
//         uint8  RightDspObjInfo_6_TypeHSC4       :3;
//         uint8  RightDspObjInfo_6_CounterHCS4    :2;
//         uint8  RightDspObjInfo_6_YHSC4_L        :2;
// }CAN_Frame_53F_Type;

// typedef struct
// {
//         uint8  LeftDspObjInfo_7_XHSC4_H         :2;
//         uint8  LeftDspObjInfo_7_ThetaHSC4       :6;
//         uint8  LeftDspObjInfo_7_XHSC4_L         :8;
//         uint8  LeftDspObjInfo_7_YHSC4_H         :8;
//         uint8                                   :1;
//         uint8  LeftDspObjInfo_7_TypeHSC4        :3;
//         uint8  LeftDspObjInfo_7_CounterHCS4     :2;
//         uint8  LeftDspObjInfo_7_YHSC4_L         :2;
//         uint8  RightDspObjInfo_7_XHSC4_H        :2;
//         uint8  RightDspObjInfo_7_ThetaHSC4      :6;
//         uint8  RightDspObjInfo_7_XHSC4_L        :8;
//         uint8  RightDspObjInfo_7_YHSC4_H        :8;
//         uint8                                   :1;
//         uint8  RightDspObjInfo_7_TypeHSC4       :3;
//         uint8  RightDspObjInfo_7_CounterHCS4    :2;
//         uint8  RightDspObjInfo_7_YHSC4_L        :2;
// }CAN_Frame_542_Type;


// /* RX MSG */
// typedef struct
// {
//         uint8   EPBAvlblyStsPV_SecCAN2          :3;
//         uint8   EPBAvlblySts_SecCAN2            :3;
//         uint8                                   :2;
//         uint8                                   :6;
//         uint8   EPBAppcnSts_SecCAN2             :2;
// }CAN_Frame_22A_Type;

// typedef struct
// {
//         uint8                                   :1;
//         uint8   EPSAPAStsHSC2               :4;
//         uint8                                   :3;
//         uint8   EPSAPAInhHSC2               :8;
//         uint8   EPSAPAAlvRCHSC2             :8;
//         uint8   EPSAPAChksmHSC2             :8;
//         uint8   reserved1                   :8;
//         uint8   reserved2                   :8;
//         uint8   reserved3                   :8;
//         uint8   reserved4                   :8;
// }CAN_Frame_1B1_Type;

// typedef struct
// {
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8   OtsdAirTemCrValV_h2HSC2     :1;
//         uint8                                   :2;
//         uint8   OtsdAirTemCrValMsk_h2HSC2   :1;
//         uint8                                   :4;
//         uint8   OtsdAirTemCrVal_h2HSC2      :8;
// }CAN_Frame_3F1_Type;

// typedef struct
// {
//         uint8   CalendarYearHSC2            :8;
//         uint8   CalendarMonthHSC2           :4;
//         uint8                                   :4;
//         uint8   CalendarDayHSC2             :5;
//         uint8                                   :3;
//         uint8   HourOfDayHSC2               :5;
//         uint8                                   :3;
//         uint8   MinuteOfHourHSC2            :6;
//         uint8                                   :2;
//         uint8   SecsOfMinuteHSC2            :6;
//         uint8   TimeDspFmtHSC2              :1;
//         uint8                                   :1;
//         uint8                                   :8;
//         uint8                                   :8;
// }CAN_Frame_541_Type;

// typedef struct
// {
//         uint8                                   :7;
//         uint8   StrgWhlAngVHSC2             :1;
//         uint8   StrgWhlAngHSC2_H            :8;
//         uint8   StrgWhlAngHSC2_L            :8;
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8                                   :8;
// }CAN_Frame_1E5_Type;

// typedef struct
// {
//         uint8   LDrvnWhlRotlDistPlsCtrHSC2_H        :2;
//         uint8   LDrvnWhlRotlDistVHSC2       :1;
//         uint8   LDrvnWhlRotlRstOcdHSC2      :1;
//         uint8   LDrvnWhlRotlSeqNumHSC2      :2;
//         uint8   LDrvnWhlRotlDistTRCHSC2     :2;
//         uint8   LDrvnWhlRotlDistPlsCtrHSC2_L        :8;
//         uint8   LDrvnWhlRotlDistTmspHSC2_H   :8;
//         uint8   LDrvnWhlRotlDistTmspHSC2_L   :8;
//         uint8   RDrvnWhlRotlDistPlsCtrHSC2_H        :2;
//         uint8   RDrvnWhlRotlDistVHSC2       :1;
//         uint8   RDrvnWhlRotlRstOcdHSC2      :1;
//         uint8   RDrvnWhlRotlSeqNumHSC2      :2;
//         uint8   RDrvnWhlRotlDistTRCHSC2     :2;
//         uint8   RDrvnWhlRotlDistPlsCtrHSC2_L        :8;
//         uint8   RDrvnWhlRotlDistTmspHSC2_H    :8;
//         uint8   RDrvnWhlRotlDistTmspHSC2_L    :8;
// }CAN_Frame_C1_Type;

// typedef struct
// {
//         uint8   LNonDrvnWhlRotlDistPCHSC2_H :2;
//         uint8   LNonDrvnWhlRotlDistVHSC2    :1;
//         uint8   LNonDrvnWhlRotlRstOcdHSC2   :1;
//         uint8   LNonDrvnWhlRotlSeqNumHSC2   :2;
//         uint8   LNonDrvnWhlRotlDistTRCHSC2  :2;
//         uint8   LNonDrvnWhlRotlDistPCHSC2_L :8;
//         uint8   LNonDrvnWhlRotlDistTHSC2_H  :8;
//         uint8   LNonDrvnWhlRotlDistTHSC2_L  :8;
//         uint8   RNonDrvnWhlRotlDistPCHSC2_H :2;
//         uint8   RNonDrvnWhlRotlDistVHSC2    :1;
//         uint8   RNonDrvnWhlRotlRstOcdHSC2   :1;
//         uint8   RNonDrvnWhlRotlSeqNumHSC2   :2;
//         uint8   RNonDrvnWhlRotlDistTRCHSC2  :2;
//         uint8   RNonDrvnWhlRotlDistPCHSC2_L :8;
//         uint8   RNonDrvnWhlRotlDistTHSC2_H   :8;
//         uint8   RNonDrvnWhlRotlDistTHSC2_L   :8;
// }CAN_Frame_C5_Type;

// typedef struct
// {
//         uint8   VSELongtAcc_SecCAN2_H           :2;
//         uint8   VSELongtAccV_SecCAN2            :1;
//         uint8   VSELatAccV_SecCAN2              :1;
//         uint8                                   :4;
//         uint8   VSELongtAcc_SecCAN2_L           :8;
//         uint8   VSELatAcc_SecCAN2_H             :4;
//         uint8                                   :4;
//         uint8   VSELatAcc_SecCAN2_L             :8;
// }CAN_Frame_185_Type;

// typedef struct
// {
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8   LNonDrvnWhlRotlDircnHSC2    :2;
//         uint8   RNonDrvnWhlRotlDircnHSC2    :2;
//         uint8   SCSAPAAlvRCHSC2             :4;
//         uint8                                   :5;
//         uint8   SCSNRCDAvlblHSC2            :1;
//         uint8   SCSAPAAcclAHSC2             :1;
//         uint8   SCSAPAAvlblHSC2             :1;
//         uint8                                   :8;
//         uint8                                   :8;
// }CAN_Frame_1C7_Type;

// typedef struct
// {
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8   VSESysA_SecCAN2                 :1;
//         uint8                                   :3;
//         uint8   TCSA_SecCAN2                    :1;
//         uint8                                   :1;
//         uint8   ABSA_SecCAN2                    :1;
//         uint8                                   :1;
//         uint8   VehDynYawRate_SecCAN2_H         :4;
//         uint8   VehDynYawRateV_SecCAN2          :1;
//         uint8                                   :3;
//         uint8   VehDynYawRate_SecCAN2_L         :8;
//         uint8                                   :8;
//         uint8                                   :8;
// }CAN_Frame_1E9_Type;

// typedef struct
// {
//         uint8   WhlGndVelLDrvnHSC2_H        :6;
//         uint8   WhlGndVelLDrvnVHSC2         :1;
//         uint8                                   :1;
//         uint8   WhlGndVelLDrvnHSC2_L        :8;
//         uint8   WhlGndVelRDrvnHSC2_H        :6;
//         uint8   WhlGndVelRDrvnVHSC2         :1;
//         uint8                                   :1;
//         uint8   WhlGndVelRDrvnHSC2_L        :8;
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8                                   :8;
// }CAN_Frame_348_Type;

// typedef struct
// {
//         uint8   WhlGndVelLNonDrvnHSC2_H     :6;
//         uint8   WhlGndVelLNonDrvnVHSC2      :1;
//         uint8                                   :1;
//         uint8   WhlGndVelLNonDrvnHSC2_L     :8;
//         uint8   WhlGndVelRNonDrvnHSC2_H     :6;
//         uint8   WhlGndVelRNonDrvnVHSC2      :1;
//         uint8                                   :1;
//         uint8   WhlGndVelRNonDrvnHSC2_L     :8;
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8                                   :8;
// }CAN_Frame_34A_Type;

// typedef struct
// {
//         uint8   VehSpdAvgDrvnHSC2_H         :7;
//         uint8   VehSpdAvgDrvnVHSC2          :1;
//         uint8   VehSpdAvgDrvnHSC2_L         :8;
//         uint8   DistRCAvgDrvnHSC2_H         :5;
//         uint8   DistRCAvgDrvnRstOcdHSC2     :1;
//         uint8   DistRCAvgDrvnVHSC2          :1;
//         uint8                                   :1;
//         uint8   DistRCAvgDrvnHSC2_L         :8;
//         uint8   VehSpdAvgNonDrvnHSC2_H      :7;
//         uint8   VehSpdAvgNonDrvnVHSC2       :1;
//         uint8   VehSpdAvgNonDrvnHSC2_L      :8;
//         uint8                                   :7;
//         uint8   DistRCAvgDrvnSrcHSC2        :1;
//         uint8                                   :8;
// }CAN_Frame_353_Type;

// typedef struct
// {
//         uint8                                   :2;
//         uint8   SCUDrvrIntrvnA_SecCAN2          :1;
//         uint8   SCUNRCDAvlbl_SecCAN2            :1;
//         uint8                                   :4;
//         uint8   SCUShifterPosRCHSC2             :4;
//         uint8                                   :4;
//         uint8                                   :4;
//         uint8   SCUShifterLvrPosHSC2            :4;
//         uint8                                   :4;
//         uint8   SCUShifterPosInvsnHSC2          :4;
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8                                   :8;
// }CAN_Frame_9D_Type;

// typedef struct
// {
//         uint8                                   :8;
//         uint8                                   :2;
//         uint8   BrkPdlAppdHSC2                  :1;
//         uint8                                   :5;
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8                                   :8;
//         uint8                                   :6;
//         uint8   HydBstrCmpstnReqHSC2            :1;
//         uint8                                   :1;
//         uint8                                   :8;
// }CAN_Frame_1B6_Type;



// #if (EM_VEHI_TYPE == VEHI_TYPE_MCE)

// /* TX MSG */
// CAN_Frame_1A8_Type CAN_Msg_1A8_VAR;
// CAN_Frame_1B5_Type CAN_Msg_1B5_VAR;
// CAN_Frame_3C6_Type CAN_Msg_3C6_VAR;
// CAN_Frame_28B_Type CAN_Msg_28B_VAR;
// CAN_Frame_23D_Type CAN_Msg_23D_VAR;
// CAN_Frame_237_Type CAN_Msg_237_VAR;
// CAN_Frame_30D_Type CAN_Msg_30D_VAR;
// CAN_Frame_2FC_Type CAN_Msg_2FC_VAR;
// CAN_Frame_390_Type CAN_Msg_390_VAR;
// CAN_Frame_531_Type CAN_Msg_531_VAR;
// CAN_Frame_532_Type CAN_Msg_532_VAR;
// CAN_Frame_545_Type CAN_Msg_545_VAR;
// CAN_Frame_539_Type CAN_Msg_539_VAR;
// CAN_Frame_53B_Type CAN_Msg_53B_VAR;
// CAN_Frame_53C_Type CAN_Msg_53C_VAR;
// CAN_Frame_53D_Type CAN_Msg_53D_VAR;
// CAN_Frame_53E_Type CAN_Msg_53E_VAR;
// CAN_Frame_53F_Type CAN_Msg_53F_VAR;
// CAN_Frame_542_Type CAN_Msg_542_VAR;

// uint8 Com_PduTx_0x200_Buf[8U];


// /* RX MSG */
// CAN_Frame_22A_Type CAN_Msg_22A_VAR;
// CAN_Frame_1B1_Type CAN_Msg_1B1_VAR;
// CAN_Frame_3F1_Type CAN_Msg_3F1_VAR;
// CAN_Frame_541_Type CAN_Msg_541_VAR;
// CAN_Frame_1E5_Type CAN_Msg_1E5_VAR;
// CAN_Frame_C1_Type CAN_Msg_C1_VAR;
// CAN_Frame_C5_Type CAN_Msg_C5_VAR;
// CAN_Frame_185_Type CAN_Msg_185_VAR;
// CAN_Frame_1C7_Type CAN_Msg_1C7_VAR;
// CAN_Frame_1E9_Type CAN_Msg_1E9_VAR;
// CAN_Frame_348_Type CAN_Msg_348_VAR;
// CAN_Frame_34A_Type CAN_Msg_34A_VAR;
// CAN_Frame_353_Type CAN_Msg_353_VAR;
// CAN_Frame_9D_Type CAN_Msg_9D_VAR;
// CAN_Frame_1B6_Type CAN_Msg_1B6_VAR;

// uint8 Com_PduRx_0x0E0_Buf[8U];
// uint8 Com_PduRx_0x529_Buf[8U];
// uint8 Com_PduRx_0x530_Buf[8U];
// uint8 Com_PduRx_0x201_Buf[8U];

// typedef enum
// {
//     COM_PDU_NULL = 0U,
//     COM_PDU_UPDATED
// }ComPduStatusType;
// typedef enum
// {
//     COM_TXON_EVENT = 0,
//     COM_TXON_CYCLE
// }ComtxType;

// uint16 Com_PduTx_Period[COM_PDUTX_NUM] = {20U, 20U, 50U, 50U, 50U, 50U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, \
//                                             100U, 100U, 100U, 100U, 100U, 100U, 30U};
// const uint16 Com_PduRx_Period[COM_PDURX_NUM] = {20U, 20U, 20U, 20U, 20U,10U, 10U, 10U, 20U, 50U,50U, 100U, \
//                                             20U, 250U, 200U,200U, 200U, 200U, 200U};
// const uint8 Com_PduTx_Type[COM_PDUTX_NUM] = {COM_TXON_CYCLE,COM_TXON_CYCLE,COM_TXON_CYCLE,COM_TXON_CYCLE,COM_TXON_CYCLE,
//                                         COM_TXON_CYCLE,COM_TXON_CYCLE,COM_TXON_CYCLE,COM_TXON_CYCLE,COM_TXON_CYCLE,
//                                         COM_TXON_CYCLE,COM_TXON_CYCLE,COM_TXON_CYCLE,COM_TXON_CYCLE,COM_TXON_CYCLE,
//                                         COM_TXON_CYCLE,COM_TXON_CYCLE,COM_TXON_CYCLE,COM_TXON_CYCLE,COM_TXON_CYCLE};
// uint8 Com_PduTxEvent_Trig[COM_PDUTX_NUM] = {0,1,0,0,0};
// uint8 Com_PduRx_Status[COM_PDURX_NUM];

// #elif (EM_VEHI_TYPE == VEHI_TYPE_HAN)
// /* TX MSG */
// CAN_Frame_1D1_Type CAN_Msg_1D1_VAR;
// CAN_Frame_134_Type CAN_Msg_134_VAR;
// CAN_Frame_316_Type CAN_Msg_316_VAR;
// CAN_Frame_432_Type CAN_Msg_432_VAR;
// CAN_Frame_32D_Type CAN_Msg_32D_VAR;
// CAN_Frame_32E_Type CAN_Msg_32E_VAR;
// CAN_Frame_32F_Type CAN_Msg_32F_VAR;

// /* RX MSG */
// CAN_Frame_422_Type CAN_Msg_422_VAR;
// CAN_Frame_318_Type CAN_Msg_318_VAR;
// CAN_Frame_133_Type CAN_Msg_133_VAR;
// CAN_Frame_294_Type CAN_Msg_294_VAR;
// CAN_Frame_2B6_Type CAN_Msg_2B6_VAR;
// CAN_Frame_212_Type CAN_Msg_212_VAR;
// CAN_Frame_220_Type CAN_Msg_220_VAR;
// CAN_Frame_218_Type CAN_Msg_218_VAR;
// CAN_Frame_222_Type CAN_Msg_222_VAR;
// CAN_Frame_11F_Type CAN_Msg_11F_VAR;
// CAN_Frame_123_Type CAN_Msg_123_VAR;
// CAN_Frame_1F0_Type CAN_Msg_1F0_VAR;
// CAN_Frame_121_Type CAN_Msg_121_VAR;
// CAN_Frame_2F1_Type CAN_Msg_2F1_VAR;
// CAN_Frame_342_Type CAN_Msg_342_VAR;


// uint16 Com_PduTx_Period[COM_PDUTX_NUM] = {20U, 20U, 20U, 1000U, 20U, 20U, 20U};
// const uint16 Com_PduRx_Period[COM_PDURX_NUM] = {20U, 20U, 100U, 50U, 500U, 20U, 20U, 20U, 20U, 10U, 10U, 20U, 20U, 100U, 20U};
// const uint8 Com_PduTx_Type[COM_PDUTX_NUM] = {COM_TXON_CYCLE, COM_TXON_CYCLE, COM_TXON_CYCLE, COM_TXON_EVENT, COM_TXON_CYCLE, COM_TXON_CYCLE, COM_TXON_CYCLE};
// uint8 Com_PduTxEvent_Trig[COM_PDUTX_NUM] = {0,0};
// uint8 Com_PduRx_Status[COM_PDURX_NUM];

// void doAliveCounter_main()
// {
//     static uint16 timer = 0U;
//     for(uint8 idx = 0U; idx < COM_PDUTX_NUM; idx++)
//     {
//         if(timer % Com_PduTx_Period[idx] == 0 && COM_TXON_CYCLE == Com_PduTx_Type[idx])
//         {
//             switch (idx)
//             {
//             case 0:
//                 CAN_Msg_1D1_VAR.APA_Status_Alive_Counter += 1;
//                 break;
//             case 1:
//                 CAN_Msg_134_VAR.APA_APA_Alive_Counter += 1;
//                 break;
//             case 2:
//                 CAN_Msg_316_VAR.MPC_316_AliveCounter += 1;
//                 break;
//             case 4:
//                 CAN_Msg_32D_VAR.MPC_32D_AliveCounter += 1;
//                 break;
//             case 5:
//                 CAN_Msg_32E_VAR.MPC_32E_AliveCounter += 1;
//                 break;
//             case 6:
//                 CAN_Msg_32F_VAR.MPC_32F_AliveCounter += 1;
//                 break;
//             default:
//                 break;
//             }
//         }
//     }

//     timer += COM_SCHEDULETASK_PERIOD;
//     if(timer >= 5000U)
//     {
//         timer = 0u;
//     }
// }
// #endif

// uint16 Com_CANFrameRx_count[COM_PDURX_NUM];

// typedef struct
// {
//     uint16  year;       ///year
//     uint16  month;      ///month,1-12
//     uint16  day;        ///day,1-31
//     uint16  hour;       ///hour,0-24
//     uint16  minute;     ///min,0-59
//     uint16  second;     ///sec,0-59
//     uint16  msec;       ///msec,0-999
//     uint16  usec;       ///usec,0-999

//     uint64  u64UnixTimes;       ///seconds since UTC_BASE_YEAR
//     uint64  u64UnixTimes_us;    ///usec since UTC_BASE_YEAR
//     uint64  u64PowOnTimes_us;   ///usec since last power on

// }st_SystemCalendar, *pst_SystemCalendar;
