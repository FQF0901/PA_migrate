/*
 * File: hmi_data_rx.c
 *
 * Code generated for Simulink model 'hmi_data_rx'.
 *
 * Model version                  : 3.1625
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Wed Jan 22 15:22:38 2025
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

#include "hmi_data_rx.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Output and update for referenced model: 'hmi_data_rx' */
void hmi_data_rx(const tMsgMnger_Hmi *rtu_sMsgMnger_Hmi, tRAHmiRx *rty_sRAHmiRx,
                 tPAHmiRx *rty_sPAHmiRx, tHPAHmiRx *rty_sHPAHmiRx)
{
  tAPAHmiRx LocalVar_sAPAHmiRx;
  tRCAHmiRx LocalVar_sRCAHmiRx;
  tRPAHmiRx LocalVar_sRPAHmiRx;
  tHmiStsReq LocalVar_DataTypeConversion1;
  tHmiTypeReq LocalVar_DataTypeConversion;
  tPrkWorkMd LocalVar_eRPAPrkWorkMd;
  tPrkoutDir LocalVar_eAPAPrkOutDir;
  tRCAPrkDircMd LocalVar_eRCAPrkDircMd;

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  LocalVar_DataTypeConversion = (tHmiTypeReq)rtu_sMsgMnger_Hmi->HmiTypeReq;

  /* MATLAB Function: '<S1>/APAPrkOutDir' */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
           (((LocalVar_DataTypeConversion == HMI_TYPE_PKOUT_FRONT_LEFT) ?
             ((int32_T)1) : ((int32_T)0)) | ((LocalVar_DataTypeConversion ==
              HMI_TYPE_PKOUT_SIDE_LEFT) ? ((int32_T)1) : ((int32_T)0))))) ?
         ((int32_T)1) : ((int32_T)0)) | ((LocalVar_DataTypeConversion ==
          HMI_TYPE_PKOUT_PP_LEFT) ? ((int32_T)1) : ((int32_T)0)))))
  {
    LocalVar_eAPAPrkOutDir = PRK_HEAD_OUT_DIR_LEFT;
  }
  else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                (((LocalVar_DataTypeConversion == HMI_TYPE_PKOUT_FRONT_RIGHT) ?
                  ((int32_T)1) : ((int32_T)0)) | ((LocalVar_DataTypeConversion ==
    HMI_TYPE_PKOUT_SIDE_RIGHT) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
              ((int32_T)0)) | ((LocalVar_DataTypeConversion ==
               HMI_TYPE_PKOUT_PP_RIGHT) ? ((int32_T)1) : ((int32_T)0)))))
  {
    LocalVar_eAPAPrkOutDir = PRK_HEAD_OUT_DIR_RIGHT;
  }
  else if ((boolean_T)((int32_T)(((LocalVar_DataTypeConversion ==
               HMI_TYPE_PKOUT_FRONT_MIDDLE) ? ((int32_T)1) : ((int32_T)0)) |
             ((LocalVar_DataTypeConversion == HMI_TYPE_PKOUT_PP_MIDDLE) ?
              ((int32_T)1) : ((int32_T)0)))))
  {
    LocalVar_eAPAPrkOutDir = PRK_HEAD_OUT_DIR_STRAIGHT;
  }
  else
  {
    switch (LocalVar_DataTypeConversion)
    {
     case HMI_TYPE_PKOUT_REAR_LEFT:
      LocalVar_eAPAPrkOutDir = PRK_TAIL_OUT_DIR_LEFT;
      break;

     case HMI_TYPE_PKOUT_REAR_RIGHT:
      LocalVar_eAPAPrkOutDir = PRK_TAIL_OUT_DIR_RIGHT;
      break;

     case HMI_TYPE_PKOUT_REAR_MIDDLE:
      LocalVar_eAPAPrkOutDir = PRK_TAIL_OUT_DIR_STRAIGHT;
      break;

     default:
      LocalVar_eAPAPrkOutDir = PRK_OUT_DIR_NO_REQ;
      break;
    }
  }

  /* End of MATLAB Function: '<S1>/APAPrkOutDir' */

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  LocalVar_DataTypeConversion1 = (tHmiStsReq)rtu_sMsgMnger_Hmi->HmiStsReq;

  /* BusAssignment: '<S1>/Bus Assignment' */
  (void)memset(&LocalVar_sAPAHmiRx, 0, sizeof(tAPAHmiRx));

  /* Switch: '<S20>/Switch' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S15>/Constant'
   *  Constant: '<S16>/Constant'
   *  Constant: '<S17>/Constant'
   *  Constant: '<S18>/Constant'
   *  Constant: '<S19>/Constant'
   *  Logic: '<S9>/EMAND'
   *  Logic: '<S9>/EMOR'
   *  Logic: '<S9>/Logical Operator'
   *  RelationalOperator: '<S9>/EMNotEqual1'
   *  RelationalOperator: '<S9>/EMNotEqual2'
   *  RelationalOperator: '<S9>/EMNotEqual3'
   *  RelationalOperator: '<S9>/EMNotEqual5'
   *  RelationalOperator: '<S9>/EMNotEqual6'
   *  RelationalOperator: '<S9>/EMNotEqual7'
   */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
               (((LocalVar_DataTypeConversion1 == HMI_STS_PARKIN_DRAG_SEARCH) ?
                 ((int32_T)1) : ((int32_T)0)) | ((LocalVar_DataTypeConversion1 ==
    HMI_STS_PARKIN_SEARCH) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
             ((int32_T)0)) | ((LocalVar_DataTypeConversion1 ==
              HMI_STS_PARKOUT_START) ? ((int32_T)1) : ((int32_T)0))))) ?
         ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
           (((LocalVar_DataTypeConversion1 == HMI_STS_SCENARIO_SELECT) ?
             ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
               (((LocalVar_DataTypeConversion == HMI_TYPE_SCENARIO_PARKIN) ?
                 ((int32_T)1) : ((int32_T)0)) | ((LocalVar_DataTypeConversion ==
    HMI_TYPE_SCENARIO_PARKOUT) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
             ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)))))
  {
    /* BusAssignment: '<S1>/Bus Assignment' incorporates:
     *  Constant: '<S12>/Constant'
     */
    LocalVar_sAPAHmiRx.eAPAPrkWakeup = SWT_ON;
  }
  else
  {
    /* BusAssignment: '<S1>/Bus Assignment' incorporates:
     *  Constant: '<S14>/Constant'
     */
    LocalVar_sAPAHmiRx.eAPAPrkWakeup = SWT_NO_REQ;
  }

  /* End of Switch: '<S20>/Switch' */

  /* MATLAB Function: '<S1>/APAPrkTypReq' */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
               ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
      ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
      ((int32_T)(((LocalVar_DataTypeConversion == HMI_TYPE_PKOUT_FRONT_LEFT) ?
      ((int32_T)1) : ((int32_T)0)) | ((LocalVar_DataTypeConversion ==
      HMI_TYPE_PKOUT_FRONT_MIDDLE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
      1) : ((int32_T)0)) | ((LocalVar_DataTypeConversion ==
      HMI_TYPE_PKOUT_FRONT_RIGHT) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
      1) : ((int32_T)0)) | ((LocalVar_DataTypeConversion ==
      HMI_TYPE_PKOUT_REAR_LEFT) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
    : ((int32_T)0)) | ((LocalVar_DataTypeConversion ==
      HMI_TYPE_PKOUT_REAR_MIDDLE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
      1) : ((int32_T)0)) | ((LocalVar_DataTypeConversion ==
      HMI_TYPE_PKOUT_REAR_RIGHT) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
    : ((int32_T)0)) | ((LocalVar_DataTypeConversion == HMI_TYPE_PKOUT_SIDE_LEFT)
                       ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                 ((int32_T)0)) | ((LocalVar_DataTypeConversion ==
      HMI_TYPE_PKOUT_SIDE_RIGHT) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
             : ((int32_T)0)) | ((HMI_STS_PARKOUT_START ==
              LocalVar_DataTypeConversion1) ? ((int32_T)1) : ((int32_T)0))))) ?
         ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
           (((HMI_STS_SCENARIO_SELECT == LocalVar_DataTypeConversion1) ?
             ((int32_T)1) : ((int32_T)0)) & ((HMI_TYPE_SCENARIO_PARKOUT ==
              LocalVar_DataTypeConversion) ? ((int32_T)1) : ((int32_T)0))))) ?
         ((int32_T)1) : ((int32_T)0)))))
  {
    /* BusAssignment: '<S1>/Bus Assignment' */
    LocalVar_sAPAHmiRx.eAPAPrkTypReq = PRK_OUT;
  }
  else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                (((HMI_TYPE_PKIN_AUTO_SEARCH == LocalVar_DataTypeConversion) ?
                  ((int32_T)1) : ((int32_T)0)) | ((HMI_STS_PARKIN_SEARCH ==
      LocalVar_DataTypeConversion1) ? ((int32_T)1) : ((int32_T)0))))) ?
              ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
                (((HMI_STS_SCENARIO_SELECT == LocalVar_DataTypeConversion1) ?
                  ((int32_T)1) : ((int32_T)0)) & ((HMI_TYPE_SCENARIO_PARKIN ==
      LocalVar_DataTypeConversion) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
               1) : ((int32_T)0)))))
  {
    /* BusAssignment: '<S1>/Bus Assignment' */
    LocalVar_sAPAHmiRx.eAPAPrkTypReq = PRK_IN;
  }
  else if (LocalVar_DataTypeConversion1 == HMI_STS_PARKIN_DRAG_SEARCH)
  {
    /* BusAssignment: '<S1>/Bus Assignment' */
    LocalVar_sAPAHmiRx.eAPAPrkTypReq = PRK_DRAG;
  }
  else
  {
    /* BusAssignment: '<S1>/Bus Assignment' */
    LocalVar_sAPAHmiRx.eAPAPrkTypReq = PRK_TYP_NO_REQ;
  }

  /* End of MATLAB Function: '<S1>/APAPrkTypReq' */

  /* MATLAB Function: '<S1>/APAPrkSlotType' */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
               ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
      ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      (((LocalVar_DataTypeConversion == HMI_TYPE_PKOUT_FRONT_LEFT) ? ((int32_T)1)
    : ((int32_T)0)) | ((LocalVar_DataTypeConversion ==
      HMI_TYPE_PKOUT_FRONT_MIDDLE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
      1) : ((int32_T)0)) | ((LocalVar_DataTypeConversion ==
      HMI_TYPE_PKOUT_FRONT_RIGHT) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
      1) : ((int32_T)0)) | ((LocalVar_DataTypeConversion ==
      HMI_TYPE_PKOUT_REAR_LEFT) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
    : ((int32_T)0)) | ((LocalVar_DataTypeConversion ==
      HMI_TYPE_PKOUT_REAR_MIDDLE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
      1) : ((int32_T)0)) | ((LocalVar_DataTypeConversion ==
      HMI_TYPE_PKOUT_REAR_RIGHT) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
                 : ((int32_T)0)) | ((LocalVar_DataTypeConversion ==
      HMI_TYPE_PKOUT_PP_LEFT) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
             ((int32_T)0)) | ((LocalVar_DataTypeConversion ==
              HMI_TYPE_PKOUT_PP_RIGHT) ? ((int32_T)1) : ((int32_T)0))))) ?
         ((int32_T)1) : ((int32_T)0)) | ((LocalVar_DataTypeConversion ==
          HMI_TYPE_PKOUT_PP_MIDDLE) ? ((int32_T)1) : ((int32_T)0)))))
  {
    /* BusAssignment: '<S1>/Bus Assignment' */
    LocalVar_sAPAHmiRx.eAPAPrkSlotType = SLOT_TYP_PERPENDI;
  }
  else if ((boolean_T)((int32_T)(((LocalVar_DataTypeConversion ==
               HMI_TYPE_PKOUT_SIDE_LEFT) ? ((int32_T)1) : ((int32_T)0)) |
             ((LocalVar_DataTypeConversion == HMI_TYPE_PKOUT_SIDE_RIGHT) ?
              ((int32_T)1) : ((int32_T)0)))))
  {
    /* BusAssignment: '<S1>/Bus Assignment' */
    LocalVar_sAPAHmiRx.eAPAPrkSlotType = SLOT_TYP_PARALLEL;
  }
  else
  {
    /* BusAssignment: '<S1>/Bus Assignment' */
    LocalVar_sAPAHmiRx.eAPAPrkSlotType = SLOT_TYP_NO_REQ;
  }

  /* End of MATLAB Function: '<S1>/APAPrkSlotType' */

  /* BusAssignment: '<S1>/Bus Assignment' */
  LocalVar_sAPAHmiRx.eAPAPrkOutDir = LocalVar_eAPAPrkOutDir;

  /* MATLAB Function: '<S1>/APAPrkWorkMd' */
  if (HMI_STS_CANCEL == LocalVar_DataTypeConversion1)
  {
    /* BusAssignment: '<S1>/Bus Assignment' */
    LocalVar_sAPAHmiRx.eAPAPrkWorkMd = PRK_WORK_EXIT;
  }
  else if ((boolean_T)((int32_T)(((HMI_STS_PARKIN_START ==
               LocalVar_DataTypeConversion1) ? ((int32_T)1) : ((int32_T)0)) |
             ((HMI_STS_PARKOUT_START == LocalVar_DataTypeConversion1) ?
              ((int32_T)1) : ((int32_T)0)))))
  {
    /* BusAssignment: '<S1>/Bus Assignment' */
    LocalVar_sAPAHmiRx.eAPAPrkWorkMd = PRK_WORK_START;
  }
  else if ((boolean_T)((int32_T)(((HMI_STS_PARKIN_CONTINUE ==
               LocalVar_DataTypeConversion1) ? ((int32_T)1) : ((int32_T)0)) |
             ((HMI_STS_PARKOUT_CONTINUE == LocalVar_DataTypeConversion1) ?
              ((int32_T)1) : ((int32_T)0)))))
  {
    /* BusAssignment: '<S1>/Bus Assignment' */
    LocalVar_sAPAHmiRx.eAPAPrkWorkMd = PRK_WORK_CONTINUE;
  }
  else if ((boolean_T)((int32_T)(((HMI_STS_PARKIN_SUSPEND ==
               LocalVar_DataTypeConversion1) ? ((int32_T)1) : ((int32_T)0)) |
             ((HMI_STS_PARKOUT_SUSPEND == LocalVar_DataTypeConversion1) ?
              ((int32_T)1) : ((int32_T)0)))))
  {
    /* BusAssignment: '<S1>/Bus Assignment' */
    LocalVar_sAPAHmiRx.eAPAPrkWorkMd = PRK_WORK_PAUSE;
  }
  else
  {
    /* BusAssignment: '<S1>/Bus Assignment' */
    LocalVar_sAPAHmiRx.eAPAPrkWorkMd = PRK_WORK_NO_REQ;
  }

  /* End of MATLAB Function: '<S1>/APAPrkWorkMd' */

  /* BusAssignment: '<S1>/Bus Assignment' incorporates:
   *  Constant: '<S21>/Constant'
   *  RelationalOperator: '<S11>/Equal'
   */
  LocalVar_sAPAHmiRx.bEolReq = (LocalVar_DataTypeConversion1 ==
    HMI_STS_EOL_START);

  /* MATLAB Function: '<S5>/RCAPrkWorkMd' */
  if (HMI_STS_GO_STRAIGHT != LocalVar_DataTypeConversion1)
  {
    LocalVar_eRPAPrkWorkMd = PRK_WORK_EXIT;
  }
  else
  {
    LocalVar_eRPAPrkWorkMd = PRK_WORK_START;

    /*  elseif (tHmiStsReq.HMI_STS_PARKIN_CONTINUE == eHmiStsReq || tHmiStsReq.HMI_STS_PARKOUT_CONTINUE == eHmiStsReq) */
    /*      eRPAPrkWorkMd = tPrkWorkMd.PRK_WORK_CONTINUE;  */
    /*  elseif (tHmiTypeReq.HMI_TYPE_GO_STRAIGHT_FORWARD ~= eHmiTypeReq || tHmiTypeReq.HMI_TYPE_GO_STRAIGHT_BACKWARD ~= eHmiTypeReq)  */
    /*      eRPAPrkWorkMd = tPrkWorkMd.PRK_WORK_PAUSE;  */
  }

  /* End of MATLAB Function: '<S5>/RCAPrkWorkMd' */

  /* BusAssignment: '<S5>/Bus Assignment' */
  (void)memset(&LocalVar_sRPAHmiRx, 0, sizeof(tRPAHmiRx));

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S30>/Constant'
   *  MATLAB Function: '<S5>/RPAPrkTypReq'
   *  RelationalOperator: '<S28>/EMNotEqual1'
   */
  if (LocalVar_DataTypeConversion1 == HMI_STS_GO_STRAIGHT)
  {
    /* BusAssignment: '<S5>/Bus Assignment' incorporates:
     *  Constant: '<S29>/Constant'
     */
    LocalVar_sRPAHmiRx.eRPAPrkWakeup = SWT_ON;
    LocalVar_sRPAHmiRx.eRPAPrkTypReq = PRK_STRAIGHT;
  }
  else
  {
    /* BusAssignment: '<S5>/Bus Assignment' incorporates:
     *  Constant: '<S31>/Constant'
     */
    LocalVar_sRPAHmiRx.eRPAPrkWakeup = SWT_NO_REQ;
    LocalVar_sRPAHmiRx.eRPAPrkTypReq = PRK_TYP_NO_REQ;
  }

  /* End of Switch: '<S32>/Switch' */

  /* BusAssignment: '<S5>/Bus Assignment' */
  LocalVar_sRPAHmiRx.eRPAPrkWorkMd = LocalVar_eRPAPrkWorkMd;

  /* MATLAB Function: '<S4>/RCAPrkDircMd' */
  switch (LocalVar_DataTypeConversion)
  {
   case HMI_TYPE_GO_STRAIGHT_FORWARD:
    LocalVar_eRCAPrkDircMd = RCA_PRK_AHEAD;
    break;

   case HMI_TYPE_GO_STRAIGHT_BACKWARD:
    LocalVar_eRCAPrkDircMd = RCA_PRK_BACK;
    break;

   default:
    LocalVar_eRCAPrkDircMd = RCA_PRK_DEAFAULT;
    break;
  }

  /* End of MATLAB Function: '<S4>/RCAPrkDircMd' */

  /* MATLAB Function: '<S4>/RCAPrkWorkMd' */
  if (HMI_STS_GO_STRAIGHT != LocalVar_DataTypeConversion1)
  {
    LocalVar_eRPAPrkWorkMd = PRK_WORK_EXIT;
  }
  else
  {
    LocalVar_eRPAPrkWorkMd = PRK_WORK_START;

    /*  elseif (tHmiStsReq.HMI_STS_PARKIN_CONTINUE == eHmiStsReq || tHmiStsReq.HMI_STS_PARKOUT_CONTINUE == eHmiStsReq) */
    /*      eRPAPrkWorkMd = tPrkWorkMd.PRK_WORK_CONTINUE;  */
    /*  elseif (tHmiTypeReq.HMI_TYPE_GO_STRAIGHT_FORWARD ~= eHmiTypeReq || tHmiTypeReq.HMI_TYPE_GO_STRAIGHT_BACKWARD ~= eHmiTypeReq)  */
    /*      eRPAPrkWorkMd = tPrkWorkMd.PRK_WORK_PAUSE;  */
  }

  /* End of MATLAB Function: '<S4>/RCAPrkWorkMd' */

  /* BusAssignment: '<S4>/Bus Assignment' incorporates:
   *  Constant: '<S4>/Constant1'
   */
  (void)memset(&LocalVar_sRCAHmiRx, 0, sizeof(tRCAHmiRx));
  LocalVar_sRCAHmiRx.eRCAPrkDircMd = LocalVar_eRCAPrkDircMd;
  LocalVar_sRCAHmiRx.eRCAPrkWorkMd = LocalVar_eRPAPrkWorkMd;
  LocalVar_sRCAHmiRx.bSecureSK2RCA = true;
  (void)memset(rty_sPAHmiRx, 0, sizeof(tPAHmiRx));

  /* BusAssignment: '<Root>/Bus Assignment' */
  rty_sPAHmiRx->sAPAHmiRx = LocalVar_sAPAHmiRx;
  rty_sPAHmiRx->sRPAHmiRx = LocalVar_sRPAHmiRx;
  rty_sPAHmiRx->sRCAHmiRx = LocalVar_sRCAHmiRx;

  /* MATLAB Function: '<S2>/HPAPrkWorkMd' */
  switch (LocalVar_DataTypeConversion1)
  {
   case HMI_STS_CANCEL:
    LocalVar_eRPAPrkWorkMd = PRK_WORK_EXIT;
    break;

   case HMI_STS_CRUISING_START:
    LocalVar_eRPAPrkWorkMd = PRK_WORK_START;
    break;

   case HMI_STS_CRUISING_CONTINUE:
    LocalVar_eRPAPrkWorkMd = PRK_WORK_CONTINUE;
    break;

   case HMI_STS_CRUISING_SUSPEND:
    LocalVar_eRPAPrkWorkMd = PRK_WORK_PAUSE;
    break;

   default:
    LocalVar_eRPAPrkWorkMd = PRK_WORK_NO_REQ;
    break;
  }

  /* End of MATLAB Function: '<S2>/HPAPrkWorkMd' */
  (void)memset(rty_sHPAHmiRx, 0, sizeof(tHPAHmiRx));

  /* BusAssignment: '<S2>/Bus Assignment' */
  rty_sHPAHmiRx->eHPAPrkWorkMd = LocalVar_eRPAPrkWorkMd;

  /* MATLAB Function: '<S3>/RAPrkWorkMd' */
  switch (LocalVar_DataTypeConversion1)
  {
   case HMI_STS_CANCEL:
    LocalVar_eRPAPrkWorkMd = PRK_WORK_EXIT;
    break;

   case HMI_STS_RA_START:
    LocalVar_eRPAPrkWorkMd = PRK_WORK_START;
    break;

   case HMI_STS_RA_CONTINUE:
    LocalVar_eRPAPrkWorkMd = PRK_WORK_CONTINUE;
    break;

   case HMI_STS_RA_SUSPEND:
    LocalVar_eRPAPrkWorkMd = PRK_WORK_PAUSE;
    break;

   default:
    LocalVar_eRPAPrkWorkMd = PRK_WORK_NO_REQ;
    break;
  }

  /* End of MATLAB Function: '<S3>/RAPrkWorkMd' */
  (void)memset(rty_sRAHmiRx, 0, sizeof(tRAHmiRx));

  /* BusAssignment: '<S3>/Bus Assignment1' */
  rty_sRAHmiRx->eRAPrkWorkMd = LocalVar_eRPAPrkWorkMd;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
