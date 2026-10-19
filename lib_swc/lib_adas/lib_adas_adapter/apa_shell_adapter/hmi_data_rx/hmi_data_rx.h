/*
 * File: hmi_data_rx.h
 *
 * Code generated for Simulink model 'hmi_data_rx'.
 *
 * Model version                  : 3.1622
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Wed Dec  4 15:21:00 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. ROM efficiency
 *    3. MISRA C:2012 guidelines
 *    4. Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_hmi_data_rx_h_
#define RTW_HEADER_hmi_data_rx_h_
#include <string.h>
#include "hmi_data_rx_type.h"
#include "emos_rte.h"
#ifndef hmi_data_rx_COMMON_INCLUDES_
#define hmi_data_rx_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* hmi_data_rx_COMMON_INCLUDES_ */

/* Shared type includes */
#include "multiword_types.h"

/* Model Code Variants */
extern void hmi_data_rx(const tMsgMnger_Hmi *rtu_sMsgMnger_Hmi, tRAHmiRx
  *rty_sRAHmiRx, tPAHmiRx *rty_sPAHmiRx, tHPAHmiRx *rty_sHPAHmiRx);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'hmi_data_rx'
 * '<S1>'   : 'hmi_data_rx/APAHmiRx'
 * '<S2>'   : 'hmi_data_rx/HPPHmiRx'
 * '<S3>'   : 'hmi_data_rx/RAHmiRx'
 * '<S4>'   : 'hmi_data_rx/RCAHmiRx'
 * '<S5>'   : 'hmi_data_rx/RPAHmiRx'
 * '<S6>'   : 'hmi_data_rx/APAHmiRx/APAPrkOutDir'
 * '<S7>'   : 'hmi_data_rx/APAHmiRx/APAPrkSlotType'
 * '<S8>'   : 'hmi_data_rx/APAHmiRx/APAPrkTypReq'
 * '<S9>'   : 'hmi_data_rx/APAHmiRx/APAPrkWakeup'
 * '<S10>'  : 'hmi_data_rx/APAHmiRx/APAPrkWorkMd'
 * '<S11>'  : 'hmi_data_rx/APAHmiRx/EolReq'
 * '<S12>'  : 'hmi_data_rx/APAHmiRx/APAPrkWakeup/Enumerated Constant'
 * '<S13>'  : 'hmi_data_rx/APAHmiRx/APAPrkWakeup/Enumerated Constant1'
 * '<S14>'  : 'hmi_data_rx/APAHmiRx/APAPrkWakeup/Enumerated Constant2'
 * '<S15>'  : 'hmi_data_rx/APAHmiRx/APAPrkWakeup/Enumerated Constant3'
 * '<S16>'  : 'hmi_data_rx/APAHmiRx/APAPrkWakeup/Enumerated Constant4'
 * '<S17>'  : 'hmi_data_rx/APAHmiRx/APAPrkWakeup/Enumerated Constant6'
 * '<S18>'  : 'hmi_data_rx/APAHmiRx/APAPrkWakeup/Enumerated Constant7'
 * '<S19>'  : 'hmi_data_rx/APAHmiRx/APAPrkWakeup/Enumerated Constant8'
 * '<S20>'  : 'hmi_data_rx/APAHmiRx/APAPrkWakeup/ifthenelse'
 * '<S21>'  : 'hmi_data_rx/APAHmiRx/EolReq/Enumerated Constant'
 * '<S22>'  : 'hmi_data_rx/HPPHmiRx/HPAPrkWorkMd'
 * '<S23>'  : 'hmi_data_rx/RAHmiRx/RAPrkWorkMd'
 * '<S24>'  : 'hmi_data_rx/RCAHmiRx/RCAPrkDircMd'
 * '<S25>'  : 'hmi_data_rx/RCAHmiRx/RCAPrkWorkMd'
 * '<S26>'  : 'hmi_data_rx/RPAHmiRx/RCAPrkWorkMd'
 * '<S27>'  : 'hmi_data_rx/RPAHmiRx/RPAPrkTypReq'
 * '<S28>'  : 'hmi_data_rx/RPAHmiRx/RPAPrkWakeup'
 * '<S29>'  : 'hmi_data_rx/RPAHmiRx/RPAPrkWakeup/Enumerated Constant'
 * '<S30>'  : 'hmi_data_rx/RPAHmiRx/RPAPrkWakeup/Enumerated Constant1'
 * '<S31>'  : 'hmi_data_rx/RPAHmiRx/RPAPrkWakeup/Enumerated Constant2'
 * '<S32>'  : 'hmi_data_rx/RPAHmiRx/RPAPrkWakeup/ifthenelse'
 */
#endif                                 /* RTW_HEADER_hmi_data_rx_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
