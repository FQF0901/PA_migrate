/*
 * File: Perception_Interface.h
 *
 * Code generated for Simulink model 'hozon_pdc'.
 *
 * Model version                  : 3.936
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Wed Jun 29 19:24:21 2022
 */

#ifndef RTW_HEADER_Perception_Interface_h_
#define RTW_HEADER_Perception_Interface_h_
//#include "interface_common_enums.h"
#include "rtwtypes.h"

#define INFO_OBSTACLE             (1)
#define INFO_PDC                  (2)
//#define PDC_USING_INFO_TYPE       INFO_PDC

// extern void Prcp_Intf_SendFreespaceInfo(void);
// extern void Prcp_Intf_SendFreespaceInfo_DF(void);
// extern void Prcp_Intf_SendFreespaceInfo_DF153(void);//ep40 1.11.1 add
// extern void Prcp_Intf_SendUssData2APP(void);
// extern void Prcp_Intf_SendDispObj2APP(void);
// extern void PecpIntf_SendPLDInfo2APP(void);
// extern void Prcp_Intf_SendAPPStatus2USS(void);

// interface wrapper sty transfer repo
extern void SendUSSData2APP(void);
// extern void SendAPPData2USS(void);

// extern void SendUssData2ActuaSrv(void);

#endif                                 /* RTW_HEADER_Perception_Interface_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
