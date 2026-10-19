
#ifndef CAN_DBC_PARSER_MCE_H
#define CAN_DBC_PARSER_MCE_H

#include "proj_global.h"


#if(EM_VEHI_TYPE == VEHI_TYPE_MCE)

/**********************************RX******************************************************************/
/********************************0x9d******************************************************************/
extern uint8 Com_CAN_SignalParse_RX_9D_SCUShifterLvrPosHSC2(void);

/********************************0xc1******************************************************************/
extern uint16 Com_CAN_SignalParse_RX_C1_LDrvnWhlRotlDistPlsCtrHSC2(void);
extern uint16 Com_CAN_SignalParse_RX_C1_RDrvnWhlRotlDistPlsCtrHSC2(void);

/********************************0xc5******************************************************************/
extern uint16 Com_CAN_SignalParse_RX_C5_LNonDrvnWhlRotlDistPCHSC2(void);
extern uint16 Com_CAN_SignalParse_RX_C5_RNonDrvnWhlRotlDistPCHSC2(void);

/********************************0x1b1******************************************************************/
extern uint8 Com_CAN_SignalParse_RX_1B1_EPSAPAStsHSC2(void);

/********************************0x1b6******************************************************************/
extern uint8 Com_CAN_SignalParse_RX_1B6_BrkPdlAppdHSC2(void);

/********************************0x1c7******************************************************************/
extern uint8 Com_CAN_SignalParse_RX_1C7_LNonDrvnWhlRotlDircnHSC2(void);
extern uint8 Com_CAN_SignalParse_RX_1C7_RNonDrvnWhlRotlDircnHSC2(void);

/********************************0x1e5******************************************************************/
extern float32 Com_CAN_SignalParse_RX_1E5_StrgWhlAngHSC2(void);

/********************************0x348******************************************************************/
extern float32 Com_CAN_SignalParse_RX_348_WhlGndVelLDrvnHSC2(void);
extern float32 Com_CAN_SignalParse_RX_348_WhlGndVelRDrvnHSC2(void);

/********************************0x34A******************************************************************/
extern float32 Com_CAN_SignalParse_RX_34A_WhlGndVelLNonDrvnHSC2(void);
extern float32 Com_CAN_SignalParse_RX_34A_WhlGndVelRNonDrvnHSC2(void);

/********************************0x353******************************************************************/
extern uint8 Com_CAN_SignalParse_RX_353_VehSpdAvgDrvnVHSC2(void);
extern float32 Com_CAN_SignalParse_RX_353_VehSpdAvgDrvnHSC2(void);

/********************************0x3F1******************************************************************/
extern uint8 Com_CAN_SignalParse_RX_3F1_OtsdAirTemCrValV(void);
extern uint8 Com_CAN_SignalParse_RX_3F1_OtsdAirTemCrVal(void);

/********************************0x541******************************************************************/
extern uint8 Com_CAN_SignalParse_RX_541_CalendarYearHSC2(void);
extern uint8 Com_CAN_SignalParse_RX_541_CalendarMonthHSC2(void);
extern uint8 Com_CAN_SignalParse_RX_541_CalendarDayHSC2(void);
extern uint8 Com_CAN_SignalParse_RX_541_HourOfDayHSC2(void);
extern uint8 Com_CAN_SignalParse_RX_541_MinuteOfHourHSC2(void);
extern uint8 Com_CAN_SignalParse_RX_541_SecsOfMinuteHSC2(void);

/**********************************TX******************************************************************/
/**********************************0x1A8******************************************************************/
extern uint8 Com_CAN_SignalParse_TX_1A8_APAChksmHSC2(uint8 u8APAChksmHSC2);
extern uint8 Com_CAN_SignalParse_TX_1A8_APAAlvRCHSC2(uint8 u8APAAlvRCHSC2);
extern uint8 Com_CAN_SignalParse_TX_1A8_APACmdEPSStsHSC2(uint8 u8APACmdEPSStsHSC2);
extern uint8 Com_CAN_SignalParse_TX_1A8_APAFHSC2(uint8 u8APAFHSC2);
extern uint8 Com_CAN_SignalParse_TX_1A8_APAToqReqStsHSC2(uint8 u8APAToqReqStsHSC2);
extern uint8 Com_CAN_SignalParse_TX_1A8_APAToqReqValHSC2(float32 f32APAToqReqStsHSC2);
extern uint8 Com_CAN_SignalParse_TX_1A8_APATrgtEPSStrgWhlAngHSC2(float32 f32APATrgtEPSStrgWhlAngHSC2);

/**********************************0x1B5******************************************************************/
extern uint8 Com_CAN_SignalParse_TX_1B5_APACrpSpdReqStsHSC2(uint8 u8APACrpSpdReqStsHSC2);
extern uint8 Com_CAN_SignalParse_TX_1B5_APACrpSpdReqValHSC2(float32 f32APACrpSpdReqValHSC2);
extern uint8 Com_CAN_SignalParse_TX_1B5_APAEPBOPReqHSC2(uint8 u8APAEPBOPReqHSC2);
extern uint8 Com_CAN_SignalParse_TX_1B5_APAEPBOpReqValPVHSC2(uint8 u8APAEPBOpReqValPVHSC2);
extern uint8 Com_CAN_SignalParse_TX_1B5_APAEPBReqAlvRCHSC2(uint8 u8APAEPBReqAlvRCHSC2);
extern uint8 Com_CAN_SignalParse_TX_1B5_APAInfoDispReqHSC2(uint8 u8APAInfoDispReqHSC2);
extern uint8 Com_CAN_SignalParse_TX_1B5_APAMdHSC2(uint8 u8APAMdHSC2);
extern uint8 Com_CAN_SignalParse_TX_1B5_APANRCDAvlblHSC2(uint8 u8APANRCDAvlblHSC2);
extern uint8 Com_CAN_SignalParse_TX_1B5_APAReqHSC2(uint8 u8APAReqHSC2);
extern uint8 Com_CAN_SignalParse_TX_1B5_APASCSAcclReqStsHSC2(uint8 u8APASCSAcclReqStsHSC2);
extern uint8 Com_CAN_SignalParse_TX_1B5_APASCSAcclReqValHSC2(float32 f32APASCSAcclReqValHSC2);
extern uint8 Com_CAN_SignalParse_TX_1B5_APASCSAcclReqValPVHSC2(uint16 u16APASCSAcclReqValPVHSC2);
extern uint8 Com_CAN_SignalParse_TX_1B5_APASCSAlvRCHSC2(uint8 u8APASCSAlvRCHSC2);
extern uint8 Com_CAN_SignalParse_TX_1B5_APAShifterPosReqdHSC2(uint8 u8APAShifterPosReqdHSC2);
extern uint8 Com_CAN_SignalParse_TX_1B5_APAStsHSC2(uint8 u8APAStsHSC2);

/**********************************0x23D******************************************************************/
extern uint8 Com_CAN_SignalParse_TX_23D_PDCCofignStsHSC2(uint8 u8PDCCofignStsHSC2);
extern uint8 Com_CAN_SignalParse_TX_23D_FLObsRngHSC2(uint8 u8FLObsRngHSC2);
extern uint8 Com_CAN_SignalParse_TX_23D_FRObsRngHSC2(uint8 u8FRObsRngHSC2);
extern uint8 Com_CAN_SignalParse_TX_23D_FrtMidLObsRngHSC2(uint8 u8FrtMidLObsRngHSC2);
extern uint8 Com_CAN_SignalParse_TX_23D_FrtMidRObsRngHSC2(uint8 u8FrtMidRObsRngHSC2);
extern uint8 Com_CAN_SignalParse_TX_23D_FrtObsDistHSC2(uint8 u8FrtObsDistHSC2);
extern uint8 Com_CAN_SignalParse_TX_23D_FrtPDCAudWrnngHSC2(uint8 u8FrtPDCAudWrnngHSC2);
extern uint8 Com_CAN_SignalParse_TX_23D_PDCSysStsHSC2(uint8 u8PDCSysStsHSC2);
extern uint8 Com_CAN_SignalParse_TX_23D_RLObsRngHSC2(uint8 u8RLObsRngHSC2);
extern uint8 Com_CAN_SignalParse_TX_23D_RRObsRngHSC2(uint8 u8RRObsRngHSC2);
extern uint8 Com_CAN_SignalParse_TX_23D_RrMidLObsRngHSC2(uint8 u8RrMidLObsRngHSC2);
extern uint8 Com_CAN_SignalParse_TX_23D_RrMidRObsRngHSC2(uint8 u8RrMidRObsRngHSC2);
extern uint8 Com_CAN_SignalParse_TX_23D_RrObsDistHSC2(uint8 u8RrObsDistHSC2);
extern uint8 Com_CAN_SignalParse_TX_23D_RrPDCAudWrnngHSC2(uint8 u8RrPDCAudWrnngHSC2);

/**********************************0x237******************************************************************/
extern uint8 Com_CAN_SignalParse_TX_237_FRSideObsDistHSC2(uint16 u16FRSideObsDistHSC2);
extern uint8 Com_CAN_SignalParse_TX_237_RRSideObsDistHSC2(uint16 u16RRSideObsDistHSC2);
extern uint8 Com_CAN_SignalParse_TX_237_FLSideObsDistHSC2(uint16 u16FLSideObsDistHSC2);
extern uint8 Com_CAN_SignalParse_TX_237_RLSideObsDistHSC2(uint16 u16RLSideObsDistHSC2);

/**********************************0x28B******************************************************************/
extern uint8 Com_CAN_SignalParse_TX_28B_FRObsDist_sech2(uint16 u16FRObsDist_sech2);
extern uint8 Com_CAN_SignalParse_TX_28B_FLObsDist_sech2(uint16 u16FLObsDist_sech2);
extern uint8 Com_CAN_SignalParse_TX_28B_RRObsDist_sech2(uint16 u16RRObsDist_sech2);
extern uint8 Com_CAN_SignalParse_TX_28B_RLObsDist_sech2(uint16 u16RLObsDist_sech2);

/**********************************0x2FC******************************************************************/
extern uint8 Com_CAN_SignalParse_TX_2FC_HD_AVMsysrdyHSC4(uint8 u8HD_AVMsysrdyHSC4);
extern uint8 Com_CAN_SignalParse_TX_2FC_HD_AVMCurViewHSC4(uint8 u8HD_AVMCurViewHSC4);
extern uint8 Com_CAN_SignalParse_TX_2FC_HD_AVMVideoFmtStaHSC4(uint8 u8HD_AVMVideoFmtStaHSC4);

/**********************************0x390******************************************************************/
extern uint8 Com_CAN_SignalParse_TX_390_AutoDrvngSysStsHSC4(uint8 u8AutoDrvngSysStsHSC4);

#endif

#endif
