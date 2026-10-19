/*
 * File: hozon_hmi_output.c
 *
 * Code generated for Simulink model 'hozon_hmi_output'.
 *
 * Model version                  : 1.1636
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Dec  2 15:48:07 2024
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

#include "hozon_hmi_output.h"

/* Block states (default storage) */
#define CtrlPara_START_SEC_VAR
#include "proj_MemMap.h"
DW_hozon_hmi_output_f_T hozon_hmi_output_DW;
#define CtrlPara_STOP_SEC_VAR
#include "proj_MemMap.h"
/* System initialize for referenced model: 'hozon_hmi_output' */
void hozon_hmi_output_Init(void)
{
  /* InitializeConditions for RelationalOperator: '<S4>/Equal2' incorporates:
   *  UnitDelay: '<S4>/Unit Delay2'
   */
  hozon_hmi_output_DW.UnitDelay2_DSTATE = LSAD_STS_STANDBY;
}

/* Output and update for referenced model: 'hozon_hmi_output' */
void hozon_hmi_output(const tHMIComDisp *rtu_sHMIComDisp, const tFusionDisp
                      *rtu_sFusionDisp, const tPAHmiRx *rtu_sPAHmiRx, const
                      tPaStateCommon *rtu_sPaStateCommon, const tDiagInfo
                      *rtu_sDiagInfo, const tVehCommon *rtu_sVehCommon, const
                      tRaStateCommon *rtu_sRaStateCommon, const tVehDataRx
                      *rtu_sVehDataRx, const tRAHmiRx *rtu_sRAHmiRx, const
                      tRelatedModuleInfo *rtu_sRelatedModuleInfo, const
                      tMsgMnger_PathSegment *rtu_sPathSegment, const
                      tMasterLsadFsm *rtu_sMasterLsadFsm, const tSlaveLsadFsm
                      *rtu_sSlaveLsadFsm, const tPaStateAdptr *rtu_sPaStateAdptr,
                      tPADispTx *rty_sPADispTx, tPrkInSlotTx *rty_sPrkInSlotTx)
{
  int32_T tmp;
  real32_T LocalVar_Saturation1;
  real32_T tmp_0;
  uint32_T tmp_1;
  uint8_T LocalVar_ADCS11_Parking_WorkSts;
  uint8_T LocalVar_ADCS4_PA_failinfo;
  uint8_T LocalVar_ADCS8_PA_warninginfo;
  uint8_T LocalVar_ADCS8_TBA_text;
  uint8_T u8aParkBarPercent;
  boolean_T LocalVar_OR1;
  boolean_T LocalVar_bParkBarPercentaDelay;

  /* Switch: '<S90>/Switch1' incorporates:
   *  Constant: '<S87>/Constant'
   *  Constant: '<S88>/Constant'
   *  Constant: '<S90>/Constant'
   *  DataStoreWrite: '<S89>/Data Store Write'
   *  Logic: '<S22>/Logical Operator1'
   *  Logic: '<S22>/Logical Operator2'
   *  RelationalOperator: '<S22>/EMEqual'
   *  RelationalOperator: '<S22>/Equal5'
   *  Switch: '<S90>/Switch'
   */
  if ((boolean_T)((int32_T)(((rtu_sMasterLsadFsm->eLsadSystemSts !=
          LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)
          ((int32_T)(((rtu_sPaStateCommon->sPAEvnt.ePAIntrptEvnt ==
                       INTERRUPT_OBSTACLE) ? ((int32_T)1) : ((int32_T)0)) ^ 1)))
         ? ((int32_T)1) : ((int32_T)0)))))
  {
    hozon_hmi_output_DW.A = 0U;
  }
  else
  {
    /* Sum: '<S90>/Add' incorporates:
     *  Constant: '<S90>/Constant1'
     *  DataStoreRead: '<S89>/Data Store Read'
     */
    tmp_1 = ((uint32_T)hozon_hmi_output_DW.A) + 1U;
    if ((((uint32_T)hozon_hmi_output_DW.A) + 1U) > 65535U)
    {
      tmp_1 = 65535U;
    }

    /* DataStoreWrite: '<S89>/Data Store Write' incorporates:
     *  Sum: '<S90>/Add'
     */
    hozon_hmi_output_DW.A = (uint16_T)tmp_1;
  }

  /* End of Switch: '<S90>/Switch1' */

  /* Saturate: '<S2>/Saturation1' */
  if (rtu_sRelatedModuleInfo->f32CtrlReqStopDistance > 10.0F)
  {
    LocalVar_Saturation1 = 10.0F;
  }
  else if (rtu_sRelatedModuleInfo->f32CtrlReqStopDistance < 0.0F)
  {
    LocalVar_Saturation1 = 0.0F;
  }
  else
  {
    LocalVar_Saturation1 = rtu_sRelatedModuleInfo->f32CtrlReqStopDistance;
  }

  /* End of Saturate: '<S2>/Saturation1' */

  /* Switch: '<S55>/Switch1' incorporates:
   *  Constant: '<S55>/Constant Value2'
   *  Logic: '<S4>/Logical Operator13'
   *  Switch: '<S55>/Switch'
   *  UnitDelay: '<S4>/Unit Delay3'
   *  UnitDelay: '<S55>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)((hozon_hmi_output_DW.bitsForTID0.UnitDelay3_DSTATE ?
         ((int32_T)1) : ((int32_T)0)) ^ 1)))
  {
    hozon_hmi_output_DW.UnitDelay1_DSTATE_n = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S55>/Unit Delay1' incorporates:
     *  Constant: '<S4>/Constant19'
     *  Sum: '<S55>/Subtraction'
     */
    hozon_hmi_output_DW.UnitDelay1_DSTATE_n += s_APPManLoopSec;
  }

  /* End of Switch: '<S55>/Switch1' */

  /* Logic: '<S54>/OR1' incorporates:
   *  Constant: '<S47>/Constant'
   *  Constant: '<S48>/Constant'
   *  Constant: '<S49>/Constant'
   *  Constant: '<S4>/Constant2'
   *  Constant: '<S50>/Constant'
   *  Logic: '<S4>/Logical Operator1'
   *  Logic: '<S4>/Logical Operator2'
   *  Logic: '<S54>/NOT'
   *  Logic: '<S54>/OR'
   *  RelationalOperator: '<S22>/EMEqual'
   *  RelationalOperator: '<S4>/Equal2'
   *  RelationalOperator: '<S4>/Equal28'
   *  RelationalOperator: '<S4>/Equal3'
   *  RelationalOperator: '<S4>/Equal4'
   *  RelationalOperator: '<S4>/Equal5'
   *  UnitDelay: '<S54>/Unit Delay2'
   *  UnitDelay: '<S55>/Unit Delay1'
   */
  LocalVar_OR1 = ((boolean_T)((int32_T)(((rtu_sMasterLsadFsm->eLsadSystemSts ==
    LSAD_STS_STANDBY) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
    ((((boolean_T)((int32_T)(((hozon_hmi_output_DW.UnitDelay2_DSTATE ==
    LSAD_STS_TERMINATED) ? ((int32_T)1) : ((int32_T)0)) |
    ((hozon_hmi_output_DW.UnitDelay2_DSTATE == LSAD_STS_COMPLETE) ? ((int32_T)1)
     : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
     ((hozon_hmi_output_DW.UnitDelay2_DSTATE == LSAD_STS_QUIT) ? ((int32_T)1) :
      ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) | ((boolean_T)((int32_T)
    (((hozon_hmi_output_DW.UnitDelay1_DSTATE_n < 0.06F) ? ((int32_T)1) :
      ((int32_T)0)) & (hozon_hmi_output_DW.bitsForTID0.UnitDelay2_DSTATE_p ?
                       ((int32_T)1) : ((int32_T)0)))));

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S45>/Constant'
   *  Constant: '<S46>/Constant'
   *  Constant: '<S4>/Constant'
   *  Constant: '<S51>/Constant'
   *  Constant: '<S52>/Constant'
   *  Constant: '<S53>/Constant'
   *  Logic: '<S4>/Logical Operator'
   *  Logic: '<S4>/Logical Operator5'
   *  RelationalOperator: '<S22>/EMEqual'
   *  RelationalOperator: '<S4>/Equal1'
   *  RelationalOperator: '<S4>/Equal6'
   *  RelationalOperator: '<S4>/Equal7'
   *  RelationalOperator: '<S4>/Equal8'
   *  RelationalOperator: '<S4>/Equal9'
   *  Switch: '<S4>/Switch1'
   *  Switch: '<S4>/Switch2'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)(((rtu_sMasterLsadFsm->eLsadSystemSts ==
          LSAD_STS_PREPARE) ? ((int32_T)1) : ((int32_T)0)) |
        ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_PREPARE_SUSPEND) ?
         ((int32_T)1) : ((int32_T)0)))))
  {
    hozon_hmi_output_DW.UnitDelay1_DSTATE_nu = 3U;
  }
  else if (LocalVar_OR1)
  {
    /* UnitDelay: '<S4>/Unit Delay1' incorporates:
     *  Constant: '<S4>/Constant1'
     *  Switch: '<S4>/Switch1'
     */
    hozon_hmi_output_DW.UnitDelay1_DSTATE_nu = 1U;
  }
  else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                (((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_STANDBY) ?
                  ((int32_T)1) : ((int32_T)0)) |
                 ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_FAILURE) ?
                  ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
             | ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_INHIBIT) ?
                ((int32_T)1) : ((int32_T)0)))))
  {
    /* Switch: '<S4>/Switch2' incorporates:
     *  Constant: '<S4>/Constant3'
     *  Switch: '<S4>/Switch1'
     *  UnitDelay: '<S4>/Unit Delay1'
     */
    hozon_hmi_output_DW.UnitDelay1_DSTATE_nu = 0U;
  }
  else
  {
    /* no actions */
  }

  /* End of Switch: '<S4>/Switch' */

  /* MATLAB Function: '<Root>/ADCS4_PA_ParkBarPercent' incorporates:
   *  RelationalOperator: '<S22>/EMEqual'
   */
  if (((real_T)rtu_sPathSegment->f32PathDistance) >= 0.001)
  {
    /* 转成0~10之间 */
    tmp_0 = floorf(((rtu_sRelatedModuleInfo->f32CtrlReqStopDistance -
                     rtu_sPathSegment->f32PathDistance) /
                    rtu_sPathSegment->f32PathDistance) * 10.0F);
    if (tmp_0 < 256.0F)
    {
      if (tmp_0 >= 0.0F)
      {
        u8aParkBarPercent = (uint8_T)tmp_0;
      }
      else
      {
        u8aParkBarPercent = 0U;
      }
    }
    else
    {
      u8aParkBarPercent = MAX_uint8_T;
    }
  }
  else
  {
    u8aParkBarPercent = 0U;
  }

  /*  输出 */
  if (rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_COMPLETE)
  {
    u8aParkBarPercent = 11U;

    /* 0xB：100% */
  }
  else if ((boolean_T)((int32_T)(((rtu_sMasterLsadFsm->eLsadSystemSts ==
               LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0)) |
             ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE_SUSPEND) ?
              ((int32_T)1) : ((int32_T)0)))))
  {
    /* 这里是要加1的 */
    tmp = (int32_T)((uint32_T)(((uint32_T)u8aParkBarPercent) + 1U));
    if ((((uint32_T)u8aParkBarPercent) + 1U) > 255U)
    {
      tmp = 255;
    }

    if (11 < ((int32_T)((uint8_T)tmp)))
    {
      u8aParkBarPercent = 11U;
    }
    else
    {
      u8aParkBarPercent = (uint8_T)tmp;
    }
  }
  else
  {
    u8aParkBarPercent = 0U;

    /* 0x0：No request */
  }

  /* End of MATLAB Function: '<Root>/ADCS4_PA_ParkBarPercent' */

  /* Switch: '<S59>/Switch1' incorporates:
   *  Constant: '<S56>/Constant'
   *  Constant: '<S58>/Constant'
   *  Constant: '<S59>/Constant Value2'
   *  Logic: '<S6>/Logical Operator'
   *  Logic: '<S6>/Logical Operator8'
   *  RelationalOperator: '<S22>/EMEqual'
   *  RelationalOperator: '<S6>/Equal1'
   *  RelationalOperator: '<S6>/Equal2'
   *  Switch: '<S59>/Switch'
   *  UnitDelay: '<S59>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)(((rtu_sMasterLsadFsm->eLsadSystemSts !=
          LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0)) &
        ((rtu_sMasterLsadFsm->eLsadSystemSts != LSAD_STS_ACTIVE_SUSPEND) ?
         ((int32_T)1) : ((int32_T)0)))))
  {
    hozon_hmi_output_DW.UnitDelay1_DSTATE_l = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S59>/Unit Delay1' incorporates:
     *  Constant: '<S6>/Constant15'
     *  Sum: '<S59>/Subtraction'
     */
    hozon_hmi_output_DW.UnitDelay1_DSTATE_l += s_APPManLoopSec;
  }

  /* End of Switch: '<S59>/Switch1' */

  /* Switch: '<S6>/Switch1' incorporates:
   *  Constant: '<S57>/Constant'
   *  RelationalOperator: '<S22>/EMEqual'
   *  RelationalOperator: '<S6>/Equal3'
   *  UnitDelay: '<S59>/Unit Delay1'
   *  UnitDelay: '<S6>/Unit Delay'
   */
  if (rtu_sMasterLsadFsm->eLsadSystemSts != LSAD_STS_COMPLETE)
  {
    hozon_hmi_output_DW.UnitDelay_DSTATE =
      hozon_hmi_output_DW.UnitDelay1_DSTATE_l;
  }

  /* End of Switch: '<S6>/Switch1' */

  /* Switch: '<S102>/Switch1' incorporates:
   *  Constant: '<S101>/Constant'
   *  Constant: '<S102>/Constant Value2'
   *  Logic: '<S27>/Logical Operator1'
   *  RelationalOperator: '<S22>/EMEqual'
   *  RelationalOperator: '<S27>/EMEqual'
   *  Switch: '<S102>/Switch'
   *  UnitDelay: '<S102>/Unit Delay1'
   */
  if (rtu_sMasterLsadFsm->eLsadSystemSts != LSAD_STS_COMPLETE)
  {
    hozon_hmi_output_DW.UnitDelay1_DSTATE_d = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S102>/Unit Delay1' incorporates:
     *  Constant: '<S27>/Constant9'
     *  Sum: '<S102>/Subtraction'
     */
    hozon_hmi_output_DW.UnitDelay1_DSTATE_d += 0.02F;
  }

  /* End of Switch: '<S102>/Switch1' */

  /* RelationalOperator: '<S27>/Relational Operator5' incorporates:
   *  Constant: '<S27>/Constant8'
   *  UnitDelay: '<S102>/Unit Delay1'
   */
  LocalVar_bParkBarPercentaDelay = (hozon_hmi_output_DW.UnitDelay1_DSTATE_d >
    1.0F);

  /* MATLAB Function: '<S9>/ADCS4TextDet' incorporates:
   *  RelationalOperator: '<S22>/EMEqual'
   *  UnitDelay: '<S9>/Unit Delay'
   */
  switch (rtu_sHMIComDisp->eDriverRequest)
  {
   case DRIVER_SLOW_DOWN:
    hozon_hmi_output_DW.UnitDelay_DSTATE_k = 6U;

    /* 0x6：车速过快，请将车速降低至25km/H以下 */
    break;

   case DRIVER_SEARCH_PS:
    hozon_hmi_output_DW.UnitDelay_DSTATE_k = 1U;

    /* 0x1：搜索车位中，请保持低速行驶 */
    break;

   default:
    if ((boolean_T)((int32_T)(((rtu_sMasterLsadFsm->eLsadSystemSts ==
            LSAD_STS_PREPARE_SUSPEND) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sPAEvntAdptr.ePASuspendEvnt == SUSPEND_SPEED_HIGH)
           ? ((int32_T)1) : ((int32_T)0)))))
    {
      hozon_hmi_output_DW.UnitDelay_DSTATE_k = 6U;

      /* 0x6 车速过快，请将车速降低至25km/H以下 */
    }
    else
    {
      switch (rtu_sHMIComDisp->eDriverRequest)
      {
       case DRIVER_STOP_TO_SELECT_PS:
        hozon_hmi_output_DW.UnitDelay_DSTATE_k = 2U;

        /* 0x2：已找到车位，请踩住刹车，点击开始泊入     */
        break;

       case DRIVER_PRESS_DMS_TO_START:
        hozon_hmi_output_DW.UnitDelay_DSTATE_k = 0U;

        /* 0x0：Noindication */
        break;

       case DRIVER_SELECT_PS_AND_CONFIRM:
        hozon_hmi_output_DW.UnitDelay_DSTATE_k = 14U;

        /* 0xE：请保持车辆静止并点击开始泊车 */
        break;

       case DRIVER_SELECT_VIR_PS_TYPE:
        hozon_hmi_output_DW.UnitDelay_DSTATE_k = 11U;

        /* 0xB：请保持车辆静止并选择车位类型 */
        break;

       case DRIVER_ADJUST_VIR_PS:
        hozon_hmi_output_DW.UnitDelay_DSTATE_k = 12U;

        /*  0xC：请调整好目标车位后点击确认     */
        break;

       case DRIVER_CONFIRM_VIR_PS:
        hozon_hmi_output_DW.UnitDelay_DSTATE_k = 14U;

        /* 0xE：请保持车辆静止并点击开始泊车 */
        break;

       case DRIVER_SELECT_DIR_W_PS_TYPE:
        hozon_hmi_output_DW.UnitDelay_DSTATE_k = 9U;

        /* 0x9：请保持车辆静止并选择泊出类型及方向 */
        break;

       default:
        if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                 (((rtu_sHMIComDisp->eDriverRequest == DRIVER_CONFIRM_DIR) ?
                   ((int32_T)1) : ((int32_T)0)) |
                  ((rtu_sHMIComDisp->eDriverRequest == DRIVER_WAIT_HANDSHAKE) ?
                   ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
              | ((rtu_sHMIComDisp->eDriverRequest == DRIVER_WAIT_PATH_PLAN) ?
                 ((int32_T)1) : ((int32_T)0)))))
        {
          hozon_hmi_output_DW.UnitDelay_DSTATE_k = 14U;

          /* 0xE：请保持车辆静止并点击开始泊车 */
          /*  elseif(eDriverRequest == tDriverRequest.DRIVER_WAIT_PATH_PLAN) */
          /*      ADCS4_Text = uint8(32);% 0x20：路径规划中 */
          /*  elseif(eDriverRequest == tDriverRequest.DRIVER_WAIT_HANDSHAKE) */
          /*      ADCS4_Text = uint8(32);% 0x20：路径规划中 */
        }
        else
        {
          switch (rtu_sHMIComDisp->eDriverRequest)
          {
           case DRIVER_RELEASE_CONTROL:
            hozon_hmi_output_DW.UnitDelay_DSTATE_k = 3U;

            /*  0x3： 请松开刹车及方向盘，自动泊车开始 */
            break;

           case DRIVER_MONITOR_APA_PARKING:
            /* ||... */
            /*        (eDriverRequest == tDriverRequest.DRIVER_WAIT_PATH_PLAN) */
            hozon_hmi_output_DW.UnitDelay_DSTATE_k = 4U;

            /* 0x4：请注意周边环境 */
            break;

           case DRIVER_RESOLVE_SUSPENSION:
            hozon_hmi_output_DW.UnitDelay_DSTATE_k = 34U;

            /*  0x22：suspend（见暂停提示） */
            /*     if(ePrkIntrptEvnt == tPrkIntrptEvnt.INTERRUPT_RPA_BUTTON_RELEASE) */
            /*          ADCS4_Text = uint8(9);%0x9：请继续泊车  */
            /*     else */
            /*          ADCS4_Text = uint8(0);%0x0：Noindication */
            /*     end */
            break;

           case DRIVER_CONFIRM_RECOVERY:
            hozon_hmi_output_DW.UnitDelay_DSTATE_k = 0U;

            /* ADCS4_text = 0x0：No indication */
            break;

           case DRIVER_PREPARE_RPA:
            hozon_hmi_output_DW.UnitDelay_DSTATE_k = 16U;

            /*  0x10： 你好，使用远程泊车功能需停好车辆后，挂P档，下车，关好车门，打开手机蓝牙，通过手机App来进行操作。（弹窗 */
            break;

           case DRIVER_MONITOR_RPA_PARKING:
            hozon_hmi_output_DW.UnitDelay_DSTATE_k = 4U;

            /* 0x4：请注意周边环境 */
            break;

           case DRIVER_CLOSE_DOOR:
            hozon_hmi_output_DW.UnitDelay_DSTATE_k = 0U;

            /* 0x0：Noindication */
            break;

           default:
            if ((boolean_T)((int32_T)(((rtu_sMasterLsadFsm->eLsadSystemSts ==
                    LSAD_STS_QUIT) ? ((int32_T)1) : ((int32_T)0)) &
                  ((rtu_sPaStateAdptr->sPAEvntAdptr.ePAQuitEvnt ==
                    QUIT_SEARCH_OVERSPEED) ? ((int32_T)1) : ((int32_T)0)))))
            {
              hozon_hmi_output_DW.UnitDelay_DSTATE_k = 7U;

              /* 0x7：车速过快，自动泊车已退出    */
            }
            else if ((boolean_T)((int32_T)(((rtu_sMasterLsadFsm->eLsadSystemSts ==
              LSAD_STS_TERMINATED) ? ((int32_T)1) : ((int32_T)0)) &
                       ((rtu_sPaStateCommon->sPAEvnt.ePATrmntEvnt ==
                         TERMINATE_VEH_MOVE) ? ((int32_T)1) : ((int32_T)0)))))
            {
              hozon_hmi_output_DW.UnitDelay_DSTATE_k = 15U;

              /* 0xF：请在车辆静止下使用此功能     */
            }
            else if ((boolean_T)((int32_T)(((rtu_sMasterLsadFsm->eLsadSystemSts ==
              LSAD_STS_TERMINATED) ? ((int32_T)1) : ((int32_T)0)) &
                       ((rtu_sPaStateCommon->sPAEvnt.ePATrmntEvnt ==
                         TERMINATE_PO_FRONT_NO_OBS) ? ((int32_T)1) : ((int32_T)0)))))
            {
              hozon_hmi_output_DW.UnitDelay_DSTATE_k = 50U;

              /* 0x32：周围空旷，可自主泊出 */
            }
            else if ((boolean_T)((int32_T)(((rtu_sSlaveLsadFsm->eLsadFuncSts ==
                         FUNC_STS_RPA_REMOTE_CONNECT) ? ((int32_T)1) : ((int32_T)
                         0)) & (((boolean_T)((int32_T)((((boolean_T)((int32_T)
                ((rtu_sPaStateAdptr->sRPAChkList.bRPAGearAval ? ((int32_T)1) :
                  ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)) |
                (((boolean_T)((int32_T)
                              ((rtu_sPaStateAdptr->sRPAChkList.bRPAEPBAval ?
                                ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)
                1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)))))
            {
              hozon_hmi_output_DW.UnitDelay_DSTATE_k = 16U;

              /* 0x10： 你好，使用远程泊车功能需停好车辆后，挂P档，下车，关好车门，打开手机蓝牙，通过手机App来进行操作。（弹窗） */
            }
            else if (rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_COMPLETE)
            {
              if (LocalVar_bParkBarPercentaDelay)
              {
                hozon_hmi_output_DW.UnitDelay_DSTATE_k = 5U;

                /* 0x5：泊车已完成，3S后退出（车端）请前往处理（手机） */
              }
            }
            else
            {
              hozon_hmi_output_DW.UnitDelay_DSTATE_k = 0U;

              /* 0x0：Noindication */
            }
            break;
          }
        }
        break;
      }
    }
    break;
  }

  /* End of MATLAB Function: '<S9>/ADCS4TextDet' */

  /* MATLAB Function: '<Root>/ADCS6PAwarninginfoDet' incorporates:
   *  DataStoreWrite: '<S89>/Data Store Write'
   *  RelationalOperator: '<S22>/EMEqual'
   *  RelationalOperator: '<S22>/Equal2'
   */
  LocalVar_ADCS8_PA_warninginfo = 0U;
  switch (rtu_sMasterLsadFsm->eLsadSystemSts)
  {
   case LSAD_STS_QUIT:
    switch (rtu_sPaStateAdptr->sPAEvntAdptr.ePAQuitEvnt)
    {
     case QUIT_INTERNAL_FAIL:
      LocalVar_ADCS8_PA_warninginfo = 14U;

      /* 0xE：泊车系统故障，功能终止，3S后退出（车端）/请前往处理（手机） */
      break;

     case QUIT_EXTERNAL_FAIL:
      LocalVar_ADCS8_PA_warninginfo = 13U;

      /*  0xD：关联系统故障，功能终止，3S后退出（车端）/请前往处理（手机） */
      break;

     case QUIT_SEARCH_OVERSLOPE:
      LocalVar_ADCS8_PA_warninginfo = 20U;

      /* 0x14：坡度过大，功能终止，3S后退出（车端）/请前往处理（手机） */
      break;

     case QUIT_ACTIVE_DA:
      LocalVar_ADCS8_PA_warninginfo = 19U;

      /* 0x13：ADAS车控功能已开启，功能终止，3S后退出（车端）/请前往处理（手机） */
      break;

     case QUIT_SEARCH_OVERTIME:
      LocalVar_ADCS8_PA_warninginfo = 55U;

      /* 0x37：车位搜索超时，功能中止，3s后退出 */
      break;

     case QUIT_CONFIRM_OVERTIME:
      LocalVar_ADCS8_PA_warninginfo = 16U;

      /* 泊车超时，功能终止，3S后退出（车端）/请前往处理（手机） */
      break;

     case QUIT_PATH_PLAN_FAIL:
      LocalVar_ADCS8_PA_warninginfo = 23U;

      /* 0x17：泊车空间不足，功能终止，3S后退出（车端）/请前往处理（手机  */
      break;

     case QUIT_HANDSHAKE_FAIL:
      LocalVar_ADCS8_PA_warninginfo = 13U;

      /* 0xD：关联系统故障，功能终止，3S后退出（车端）/请前往处理（手机 */
      break;

     case QUIT_MANUAL_DEACTIVATE:
      LocalVar_ADCS8_PA_warninginfo = 27U;

      /* 0x1B：功能终止，系统3S后退出（车端）/请前往处理（手机）    */
      break;

     case QUIT_RPA_CONNECT_OVERTIME:
      /* 0x1E"操作超时，请接管车辆"    */
      break;

     case QUIT_INVALID_SIGNAL:
      LocalVar_ADCS8_PA_warninginfo = 13U;

      /* 0xD：关联系统故障，功能终止，3S后退出（车端）/请前往处理（手机）   */
      break;

     case QUIT_TIRE_PRESSURE_ABNORMAL:
      LocalVar_ADCS8_PA_warninginfo = 28U;

      /* 0x1C：胎压报警，功能终止，3S后退出（车端）/请前往处理（手机）  */
      break;

     case QUIT_RPA_LOW_BAT:
      LocalVar_ADCS8_PA_warninginfo = 22U;

      /* 0x16：电量不足，功能终止，3S后退出（车端）/请前往处理   */
      break;

     case QUIT_RELEASING_FAIL:
      LocalVar_ADCS8_PA_warninginfo = 27U;

      /* 0x1B：功能终止，系统3S后退出（车端）/请前往处理（手机）  */
      break;

     case QUIT_USS_FAIL:
      LocalVar_ADCS8_PA_warninginfo = 14U;

      /*  0xE：泊车系统故障，功能终止，3S后退出（车端）/请前往处理（手机） */
      break;

     case QUIT_VISION_FAIL:
      LocalVar_ADCS8_PA_warninginfo = 14U;

      /*  0xE：泊车系统故障，功能终止，3S后退出（车端）/请前往处理（手机）  */
      break;

     case QUIT_RPA_CONN_LOSS:
      LocalVar_ADCS8_PA_warninginfo = 25U;

      /*  0x19：蓝牙连接故障，请连接蓝牙后重试  */
      break;

     case QUIT_MIRROR_FOLD:
      LocalVar_ADCS8_PA_warninginfo = 24U;

      /* 0x18：后视镜被折叠，功能终止，3S后退出（车端）/请前往处理（手机） */
      break;

     case QUIT_VEH_MOVE:
      LocalVar_ADCS8_PA_warninginfo = 45U;

      /* 0x2D：刹车已松开，请接管车辆 */
      break;

     default:
      /* no actions */
      break;
    }
    break;

   case LSAD_STS_PREPARE:
    if ((boolean_T)((int32_T)(((rtu_sSlaveLsadFsm->eLsadFuncSts ==
            FUNC_STS_APA_PO_CONFIRM) ? ((int32_T)1) : ((int32_T)0)) |
          ((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_SEARCH) ?
           ((int32_T)1) : ((int32_T)0)))))
    {
      if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
                   ((((boolean_T)((int32_T)
          ((rtu_sVehCommon->sCondiDoorSblt.bFLDrClose ? ((int32_T)1) : ((int32_T)
          0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
          ((rtu_sVehCommon->sCondiDoorSblt.bFRDrClose ? ((int32_T)1) : ((int32_T)
          0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                 ((int32_T)0)) | (((boolean_T)((int32_T)
                   ((rtu_sVehCommon->sCondiDoorSblt.bRLDrClose ? ((int32_T)1) :
                     ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ?
             ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
               ((rtu_sVehCommon->sCondiDoorSblt.bRRDrClose ? ((int32_T)1) :
                 ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
      {
        LocalVar_ADCS8_PA_warninginfo = 1U;

        /* 0x1"请关闭车门"      */
      }
      else if ((boolean_T)((int32_T)
                           ((rtu_sVehCommon->sCondiDoorSblt.bTailGateClose ?
                             ((int32_T)1) : ((int32_T)0)) ^ 1)))
      {
        LocalVar_ADCS8_PA_warninginfo = 2U;

        /* 0x2"请关闭行李箱门"      */
      }
      else if ((boolean_T)((int32_T)
                           ((rtu_sVehCommon->sCondiDoorSblt.bHoodDrClose ?
                             ((int32_T)1) : ((int32_T)0)) ^ 1)))
      {
        LocalVar_ADCS8_PA_warninginfo = 3U;

        /* 0x3：请关闭机舱盖开启        */
      }
      else
      {
        /* no actions */
      }
    }
    else if (rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_REMOTE_CONNECT)
    {
      if ((boolean_T)((int32_T)((rtu_sPaStateAdptr->sRPAChkList.bRPADrClose ?
             ((int32_T)1) : ((int32_T)0)) ^ 1)))
      {
        LocalVar_ADCS8_PA_warninginfo = 5U;

        /* 0x5：车门被打开，请关闭后重试 */
      }
      else if ((boolean_T)((int32_T)((rtu_sPaStateAdptr->sRPAChkList.bTrunkClose
                  ? ((int32_T)1) : ((int32_T)0)) ^ 1)))
      {
        LocalVar_ADCS8_PA_warninginfo = 6U;

        /*  0x6：行李箱门开启，请关闭后重试   */
      }
      else if ((boolean_T)((int32_T)((rtu_sPaStateAdptr->sRPAChkList.bHoodClose ?
                  ((int32_T)1) : ((int32_T)0)) ^ 1)))
      {
        LocalVar_ADCS8_PA_warninginfo = 7U;

        /*  0x7：机舱盖开启，请关闭后重试 */
      }
      else if ((boolean_T)((int32_T)
                           ((rtu_sPaStateAdptr->sRPAChkList.bRPAVehStdstil ?
                             ((int32_T)1) : ((int32_T)0)) ^ 1)))
      {
        LocalVar_ADCS8_PA_warninginfo = 15U;

        /* 0xF：泊车超速，功能终止，3S后退出（车端）/请前往处理（手机）      */
      }
      else if ((boolean_T)((int32_T)
                           ((rtu_sPaStateAdptr->sRPAChkList.bRPATirePresNorm ?
                             ((int32_T)1) : ((int32_T)0)) ^ 1)))
      {
        LocalVar_ADCS8_PA_warninginfo = 28U;

        /* 0x1C：胎压报警，功能终止，3S后退出（车端）/请前往处理（手机）       */
      }
      else if ((boolean_T)((int32_T)
                           ((rtu_sPaStateAdptr->sRPAChkList.bRPASlopAval ?
                             ((int32_T)1) : ((int32_T)0)) ^ 1)))
      {
        LocalVar_ADCS8_PA_warninginfo = 20U;

        /* 0x14：坡度过大，功能终止，3S后退出（车端）/请前往处理（手机） */
      }
      else if ((boolean_T)((int32_T)((rtu_sPaStateAdptr->sRPAChkList.bRPASysNorm
                  ? ((int32_T)1) : ((int32_T)0)) ^ 1)))
      {
        LocalVar_ADCS8_PA_warninginfo = 14U;

        /* 0xE：泊车系统故障，功能终止，3S后退出（车端）/请前往处理（手机）  */
      }
      else if ((boolean_T)((int32_T)
                           ((rtu_sPaStateAdptr->sRPAChkList.bRPASurrAval ?
                             ((int32_T)1) : ((int32_T)0)) ^ 1)))
      {
        LocalVar_ADCS8_PA_warninginfo = 13U;

        /* 0xD：关联系统故障，功能终止，3S后退出（车端）/请前往处理（手机）      */
      }
      else
      {
        /* no actions */
      }
    }
    else
    {
      /* no actions */
    }
    break;

   case LSAD_STS_PREPARE_SUSPEND:
    switch (rtu_sPaStateAdptr->sPAEvntAdptr.ePASuspendEvnt)
    {
     case SUSPEND_DR_DOOR_OPEN:
      LocalVar_ADCS8_PA_warninginfo = 1U;

      /* 0x1"请关闭车门"  */
      break;

     case SUSPEND_TRUNK_OPEN:
      LocalVar_ADCS8_PA_warninginfo = 2U;

      /* 0x2"请关闭行李箱门"  */
      break;

     case SUSPEND_HOOD_OPEN:
      LocalVar_ADCS8_PA_warninginfo = 3U;

      /* 0x3：请关闭机舱盖开启  */
      /*      elseif(sPaStateCommonAdptr.sPAEvntAdptr.ePASuspendEvnt == */
      /*      tSuspendEvnt.SUSPEND_RPA_OBSTACLE) //RPA的先屏蔽掉 */
      /*          ADCS8_PA_warninginfo = uint8(10);%0xA：轨迹内有障碍物，请处理后重试 */
      /*      elseif(sPaStateCommonAdptr.sPAEvntAdptr.ePASuspendEvnt == tSuspendEvnt.SUSPEND_RPA_MANUAL_BRAKE) */
      /*          ADCS8_PA_warninginfo = uint8(9);%0x9：系统检测到刹车，功能中断，松开刹车后，泊车继续 */
      break;

     default:
      /* no actions */
      break;
    }
    break;

   case LSAD_STS_ACTIVE:
    /* 0x0"Normal"   */
    break;

   default:
    if (((int32_T)hozon_hmi_output_DW.A) < 150)
    {
      switch (rtu_sMasterLsadFsm->eLsadSystemSts)
      {
       case LSAD_STS_ACTIVE_SUSPEND:
        if ((boolean_T)((int32_T)(((rtu_sPaStateCommon->sPAEvnt.ePAIntrptEvnt ==
                INTERRUPT_DOOR_OPEN) ? ((int32_T)1) : ((int32_T)0)) &
              (rtu_sVehCommon->sCondiDoorSblt.bHoodDrClose ? ((int32_T)1) :
               ((int32_T)0)))))
        {
          LocalVar_ADCS8_PA_warninginfo = 5U;

          /* 0x5：车门被打开，请关闭后重试 */
        }
        else if ((boolean_T)((int32_T)
                             (((rtu_sPaStateCommon->sPAEvnt.ePAIntrptEvnt ==
                                INTERRUPT_DOOR_OPEN) ? ((int32_T)1) : ((int32_T)
                     0)) & (((boolean_T)((int32_T)
                      ((rtu_sVehCommon->sCondiDoorSblt.bHoodDrClose ? ((int32_T)
            1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
        {
          LocalVar_ADCS8_PA_warninginfo = 7U;

          /*  0x7：机舱盖开启，请关闭后重试    */
        }
        else
        {
          switch (rtu_sPaStateCommon->sPAEvnt.ePAIntrptEvnt)
          {
           case INTERRUPT_SEATBELT_UNBUCKLED:
            LocalVar_ADCS8_PA_warninginfo = 8U;

            /* 0x8：安全带未系，请系上安全带后重试 */
            break;

           case INTERRUPT_TRUNK_OPEN:
            LocalVar_ADCS8_PA_warninginfo = 6U;

            /*  0x6：行李箱门开启，请关闭后重试 */
            break;

           case INTERRUPT_OBSTACLE:
            LocalVar_ADCS8_PA_warninginfo = 10U;

            /* 0xA：轨迹内有障碍物，请处理后重试  */
            break;

           case INTERRUPT_MANUAL_BRAKE:
            LocalVar_ADCS8_PA_warninginfo = 9U;

            /* 0x9：系统检测到刹车，功能中断，松开刹车后，泊车继续     */
            break;

           case INTERRUPT_RPA_BUTTON_RELEASE:
            LocalVar_ADCS8_PA_warninginfo = 26U;

            /* 0x1A：遥控泊车按键松开，泊车暂停     */
            break;

           default:
            /* no actions */
            break;
          }
        }
        break;

       case LSAD_STS_TERMINATED:
        switch (rtu_sPaStateCommon->sPAEvnt.ePATrmntEvnt)
        {
         case TERMINATE_INTERNAL_FAIL:
          LocalVar_ADCS8_PA_warninginfo = 14U;

          /* 0xE：泊车系统故障，功能终止，3S后退出（车端）/请前往处理 */
          break;

         case TERMINATE_EXTERNAL_FAIL:
          LocalVar_ADCS8_PA_warninginfo = 13U;

          /* 0xD：关联系统故障，功能终止，3S后退出（车端）/请前往处理（手机） */
          break;

         case TERMINATE_MANVR_OVERTIME:
          LocalVar_ADCS8_PA_warninginfo = 16U;

          /* 0x10：泊车超时，功能终止，3S后退出（车端）/请前往处理       */
          break;

         case TERMINATE_MANVR_OVERSPEED:
          LocalVar_ADCS8_PA_warninginfo = 15U;

          /* 0xF：泊车超速，功能终止，3S后退出（车端）/请前往处理 */
          break;

         case TERMINATE_MANVR_OVERFLOW:
          LocalVar_ADCS8_PA_warninginfo = 17U;

          /* 0x11：泊车超步，功能终止，3S后退出（车端）/请前往处理       */
          break;

         case TERMINATE_INTERRUPT_OVERFLOW:
          LocalVar_ADCS8_PA_warninginfo = 11U;

          /* 0xB：中断次数超限，功能终止，3S后退出（车端）/请前往处理 */
          break;

         case TERMINATE_INVALID_SIGNAL:
          LocalVar_ADCS8_PA_warninginfo = 14U;

          /* 0xE：泊车系统故障，功能终止，3S后退出（车端）/请前往处理       */
          break;

         case TERMINATE_STEER_INTERFERE:
          LocalVar_ADCS8_PA_warninginfo = 18U;

          /* 0x12：驾驶员干预，功能终止，3S后退出（车端）/请前往处理 */
          break;

         case TERMINATE_ACCEL_INTERFERE:
          LocalVar_ADCS8_PA_warninginfo = 18U;

          /* 0x12：驾驶员干预，功能终止，3S后退出（车端）/请前往处理 */
          break;

         case TERMINATE_DRIVER_DOOR_OPEN:
          LocalVar_ADCS8_PA_warninginfo = 18U;

          /* 0x12：驾驶员干预，功能终止，3S后退出（车端）/请前往处理 */
          break;

         case TERMINATE_UNEXP_GEAR:
          LocalVar_ADCS8_PA_warninginfo = 13U;

          /* 0xD：关联系统故障，功能终止，3S后退出（车端）/请前往处理（手机） */
          break;

         case TERMINATE_UNEXP_EPB:
          LocalVar_ADCS8_PA_warninginfo = 13U;

          /* 0xD：关联系统故障，功能终止，3S后退出（车端）/请前往处理（手机）       */
          break;

         case TERMINATE_UXEXP_ADAS:
          LocalVar_ADCS8_PA_warninginfo = 19U;

          /* 0x13：ADAS车控功能已开启，功能终止，3S后退出（车端）/请前往处理（手机） */
          break;

         case TERMINATE_UNEXP_AS:
          LocalVar_ADCS8_PA_warninginfo = 13U;

          /* 0xD：关联系统故障，功能终止，3S后退出（车端）/请前往处理（手机）      */
          break;

         case TERMINATE_VEH_BLOCK:
          LocalVar_ADCS8_PA_warninginfo = 44U;

          /* 0x2C：车辆受阻，功能终止，3S后退出（车端）/请前往处理 */
          break;

         case TERMINATE_VEH_SLIP:
          LocalVar_ADCS8_PA_warninginfo = 20U;

          /*  0x14：坡度过大，功能终止，3S后退出（车端）/请前往处理（手机）    */
          break;

         case TERMINATE_NO_PATH:
          LocalVar_ADCS8_PA_warninginfo = 23U;

          /* 0x17：泊车空间不足，功能终止，3S后退出（车端）/请前往处理（手机）  */
          break;

         case TERMINATE_PATH_PLAN_FAIL:
          LocalVar_ADCS8_PA_warninginfo = 23U;

          /* 0x17：泊车空间不足，功能终止，3S后退出（车端）/请前往处理（手机）  */
          break;

         case TERMINATE_GEAR_INTERFERE:
          LocalVar_ADCS8_PA_warninginfo = 18U;

          /* 0x12：驾驶员干预，功能终止，3S后退出（车端）/请前往处理 */
          break;

         case TERMINATE_INTERRUPT_OVERTIME:
          LocalVar_ADCS8_PA_warninginfo = 12U;

          /* 0xC：中断时间超时，功能终止，3S后退出（车端）/请前往处理 */
          break;

         case TERMINATE_TIRE_PRESSURE_ABNORMAL:
          LocalVar_ADCS8_PA_warninginfo = 28U;

          /* 0x1C：胎压报警，功能终止，3S后退出（车端）/请前往处理 */
          break;

         case TERMINATE_SLOPE_OVERLIMIT:
          LocalVar_ADCS8_PA_warninginfo = 20U;

          /* 0x14：坡度过大，功能终止，3S后退出（车端）/请前往处理 */
          break;

         case TERMINATE_RPA_LOW_BAT:
          LocalVar_ADCS8_PA_warninginfo = 33U;

          /* 0x21"遥控设备电量低"  */
          break;

         case TERMINATE_RPA_CONN_LOSS:
          LocalVar_ADCS8_PA_warninginfo = 25U;

          /* 0x19"蓝牙连接故障，请连接蓝牙后重试"       */
          break;

         case TERMINATE_READY_OVERTIME:
          LocalVar_ADCS8_PA_warninginfo = 59U;

          /* 0x3B：操作超时，请接管车辆 */
          break;

         case TERMINATE_RELEASING_FAIL:
          LocalVar_ADCS8_PA_warninginfo = 27U;

          /* 0x1B"泊车已退出(非预期原因导致泊车退出)"  */
          break;

         default:
          if (rtu_sPaStateCommon->sCondiOverFlag.bTrmntDurattime)
          {
            LocalVar_ADCS8_PA_warninginfo = 59U;

            /* 0x3B"操作超时，请接管车辆"    */
          }
          else
          {
            switch (rtu_sPaStateCommon->sPAEvnt.ePATrmntEvnt)
            {
             case TERMINATE_VISION_FAIL:
              LocalVar_ADCS8_PA_warninginfo = 14U;

              /* 0xE：泊车系统故障，功能终止，3S后退出（车端）/请前往处理 */
              break;

             case TERMINATE_USS_FAIL:
              LocalVar_ADCS8_PA_warninginfo = 14U;

              /* 0xE：泊车系统故障，功能终止，3S后退出（车端）/请前往处理    */
              break;

             case TERMINATE_MANUAL_DEACT:
              LocalVar_ADCS8_PA_warninginfo = 27U;

              /* 0x1B：功能终止，系统3S后退出（车端）/请前往处理（手机）  */
              break;

             case TERMINATE_MIRROR_FOLD:
              LocalVar_ADCS8_PA_warninginfo = 24U;

              /* 0x18：后视镜被折叠，功能终止，3S后退出（车端）/请前往处理（手机） */
              break;

             case TERMINATE_CTRLSTOP_OVERTIME:
              LocalVar_ADCS8_PA_warninginfo = 16U;

              /* 0x10：泊车超时，功能终止，3S后退出（车端）/请前往处理（手机） */
              break;

             default:
              /* no actions */
              break;
            }
          }
          break;
        }
        break;

       default:
        if ((boolean_T)((int32_T)(((rtu_sMasterLsadFsm->eLsadSystemSts ==
                LSAD_STS_COMPLETE) ? ((int32_T)1) : ((int32_T)0)) &
              (rtu_sPaStateCommon->sCondiOverFlag.bCmpltDurattime ? ((int32_T)1)
               : ((int32_T)0)))))
        {
          LocalVar_ADCS8_PA_warninginfo = 59U;

          /* 0x3B"操作超时，请接管车辆"      */
        }
        else if ((boolean_T)((int32_T)(((rtu_sMasterLsadFsm->eLsadSystemSts ==
                     LSAD_STS_FAILURE) ? ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_INHIBIT) ?
                    ((int32_T)1) : ((int32_T)0)))))
        {
          switch (rtu_sPaStateAdptr->sPAEvntAdptr.ePAQuitEvnt)
          {
           case QUIT_INTERNAL_FAIL:
            LocalVar_ADCS8_PA_warninginfo = 8U;

            /* 0x8：影像系统故障，泊车退出    */
            break;

           case QUIT_EXTERNAL_FAIL:
            LocalVar_ADCS8_PA_warninginfo = 7U;

            /*  0x7：关联系统故障，泊车退出 */
            break;

           case QUIT_SEARCH_OVERSPEED:
            LocalVar_ADCS8_PA_warninginfo = 11U;

            /* 0xB：泊车超速，泊车退出 */
            break;

           case QUIT_ACTIVE_DA:
            LocalVar_ADCS8_PA_warninginfo = 18U;

            /* 0x12：其他整车功能激活，泊车退出    */
            break;

           case QUIT_TIRE_PRESSURE_ABNORMAL:
            LocalVar_ADCS8_PA_warninginfo = 25U;

            /* 0x19"胎压报警，泊车退出"  */
            break;

           case QUIT_USS_FAIL:
            LocalVar_ADCS8_PA_warninginfo = 9U;

            /* 0x9：超声波系统故障，泊车退出 */
            break;

           case QUIT_VISION_FAIL:
            LocalVar_ADCS8_PA_warninginfo = 8U;

            /* 0x8：影像系统故障，泊车退出   */
            break;

           default:
            /* no actions */
            break;
          }
        }
        else if (rtu_sHMIComDisp->eDriverRequest == DRIVER_CLOSE_DOOR)
        {
          LocalVar_ADCS8_PA_warninginfo = 1U;

          /* 0x1：请关闭车门 */
        }
        else
        {
          /* no actions */
        }
        break;
      }
    }
    else
    {
      /* 0x0"Normal"  超声解锁后能正常显示      */
    }
    break;
  }

  /* End of MATLAB Function: '<Root>/ADCS6PAwarninginfoDet' */

  /* MATLAB Function: '<Root>/ADCS8_TBA_text' incorporates:
   *  RelationalOperator: '<S22>/EMEqual'
   */
  if (rtu_sSlaveLsadFsm->eLsadFuncType == LSAD_RA)
  {
    if (rtu_sVehCommon->sCondiPlatform.bActvStsNeedRlsBrk)
    {
      LocalVar_ADCS8_TBA_text = 19U;

      /* 0x13：松开刹车及方向盘，循迹倒车开始    */
    }
    else
    {
      switch (rtu_sMasterLsadFsm->eLsadSystemSts)
      {
       case LSAD_STS_ACTIVE:
        LocalVar_ADCS8_TBA_text = 11U;

        /* 0xB：循迹倒车中，请注意周边环境；   */
        break;

       case LSAD_STS_COMPLETE:
        LocalVar_ADCS8_TBA_text = 18U;

        /* 0x12：循迹倒车已完成 */
        break;

       default:
        if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                 (((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_STANDBY) ?
                   ((int32_T)1) : ((int32_T)0)) &
                  ((rtu_sSlaveLsadFsm->eBckgrndRecordSts ==
                    BACKGROUND_MODULE_STS_ENABLE) ? ((int32_T)1) : ((int32_T)0)))))
               ? ((int32_T)1) : ((int32_T)0)) & ((rtu_sRAHmiRx->eRAPrkWorkMd ==
                PRK_WORK_START) ? ((int32_T)1) : ((int32_T)0)))))
        {
          LocalVar_ADCS8_TBA_text = 20U;

          /* 0x14：车辆无记忆路径，循迹倒车不可用 */
        }
        else
        {
          switch (rtu_sMasterLsadFsm->eLsadSystemSts)
          {
           case LSAD_STS_ACTIVE_SUSPEND:
            switch (rtu_sRaStateCommon->sRAEvnt.eRAIntrptEvnt)
            {
             case RA_INTERRUPT_DOOR_OPEN:
              LocalVar_ADCS8_TBA_text = 13U;

              /* 0xD：关闭车门后，点击继续恢复循迹倒车 */
              break;

             case RA_INTERRUPT_SEATBELT_UNBUCKLED:
              LocalVar_ADCS8_TBA_text = 12U;

              /* 0xC：系好安全带后，点击继续恢复循迹倒车 */
              break;

             case RA_INTERRUPT_TRUNK_OPEN:
              LocalVar_ADCS8_TBA_text = 14U;

              /* 0xE：关闭后备箱后，点击继续恢复循迹倒车 */
              break;

             case RA_INTERRUPT_HOOD_OPEN:
              LocalVar_ADCS8_TBA_text = 15U;

              /* 0xF：关闭前舱盖后，点击继续恢复循迹倒车   */
              break;

             case RA_INTERRUPT_OBSTACLE:
              LocalVar_ADCS8_TBA_text = 16U;

              /* 0x10：检测到障碍物，移除障碍物后，点击继续恢复循迹倒车 */
              break;

             case RA_INTERRUPT_MANUAL_BRAKE:
              LocalVar_ADCS8_TBA_text = 17U;

              /* 0x11：检测到刹&#x2ECB;，松开刹车后可&#x2F83;动恢复循迹倒车   */
              break;

             default:
              LocalVar_ADCS8_TBA_text = 0U;
              break;
            }
            break;

           case LSAD_STS_QUIT:
            switch (rtu_sRaStateCommon->sRAEvnt.eRAQuitEvnt)
            {
             case RA_QUIT_EXTERNAL_FAIL:
              LocalVar_ADCS8_TBA_text = 3U;

              /* 0x3：关联系统故障，循迹倒车即将退出 */
              break;

             case RA_QUIT_MANUAL_DEACTIVATE:
              LocalVar_ADCS8_TBA_text = 21U;

              /* 0x15：功能中止，循迹倒车即将退出 */
              break;

             case RA_QUIT_VEH_MOVE:
              LocalVar_ADCS8_TBA_text = 21U;

              /* 0x15：功能中止，循迹倒车即将退出 */
              break;

             case RA_QUIT_HANDSHAKE_FAIL:
              LocalVar_ADCS8_TBA_text = 3U;

              /* 0x3:关联系统故障 */
              break;

             default:
              LocalVar_ADCS8_TBA_text = 0U;
              break;
            }
            break;

           case LSAD_STS_TERMINATED:
            switch (rtu_sRaStateCommon->sRAEvnt.eRATrmntEvnt)
            {
             case RA_TERMINATE_EXTERNAL_FAIL:
              LocalVar_ADCS8_TBA_text = 3U;

              /* 0x3：关联系统故障，循迹倒车即将退出   */
              break;

             case RA_TERMINATE_INTERNAL_FAIL:
              LocalVar_ADCS8_TBA_text = 8U;

              /* 0x8：泊车系统故障，循迹倒车即将退出     */
              break;

             case RA_TERMINATE_VEH_BLOCK:
              LocalVar_ADCS8_TBA_text = 1U;

              /* 0x1：车辆受阻，循迹倒车即将退出    */
              break;

             case RA_TERMINATE_VEH_SLIP:
              LocalVar_ADCS8_TBA_text = 5U;

              /* 0x5：车辆发生溜坡，循迹倒车即将退出    */
              break;

             case RA_TERMINATE_SLOPE_OVERLIMIT:
              LocalVar_ADCS8_TBA_text = 7U;

              /* 0x7：坡度过大，循迹倒车即将退出     */
              break;

             case RA_TERMINATE_MANVR_OVERSPEED:
              LocalVar_ADCS8_TBA_text = 2U;

              /* 0x2：泊车超速，循迹倒车即将退出      */
              break;

             case RA_TERMINATE_INTERRUPT_OVERFLOW:
              LocalVar_ADCS8_TBA_text = 6U;

              /* 0x6：中断次数超限，循迹倒车即将退出 */
              break;

             case RA_TERMINATE_INTERRUPT_OVERTIME:
              LocalVar_ADCS8_TBA_text = 10U;

              /* 0xA：中断超时，循迹倒车即将退出    */
              break;

             case RA_TERMINATE_INVALID_SIGNAL:
              LocalVar_ADCS8_TBA_text = 3U;

              /* 0x3：关联系统故障，循迹倒车即将退出       */
              break;

             case RA_TERMINATE_STEER_INTERFERE:
              LocalVar_ADCS8_TBA_text = 9U;

              /* 0x9：驾驶员干预，循迹倒车即将退出 */
              break;

             case RA_TERMINATE_ACCEL_INTERFERE:
              LocalVar_ADCS8_TBA_text = 9U;

              /* 0x9：驾驶员干预，循迹倒车即将退出  */
              break;

             case RA_TERMINATE_GEAR_INTERFERE:
              LocalVar_ADCS8_TBA_text = 9U;

              /* 0x9：驾驶员干预，循迹倒车即将退出 */
              break;

             case RA_TERMINATE_UNEXP_GEAR:
              LocalVar_ADCS8_TBA_text = 9U;

              /* 0x9：驾驶员干预，循迹倒车即将退出 */
              break;

             case RA_TERMINATE_UNEXP_EPB:
              LocalVar_ADCS8_TBA_text = 9U;

              /* 0x9：驾驶员干预，循迹倒车即将退出       */
              break;

             case RA_TERMINATE_UXEXP_ADAS:
              LocalVar_ADCS8_TBA_text = 4U;

              /* 0x4：行车辅助功能激活，循迹倒车即将退出 */
              break;

             case RA_TERMINATE_UNEXP_AS:
              LocalVar_ADCS8_TBA_text = 9U;

              /* 0x9：驾驶员干预，循迹倒车即将退出    */
              break;

             case RA_TERMINATE_MIRROR_FOLD:
              LocalVar_ADCS8_TBA_text = 21U;

              /* 0x15：功能终止，循迹倒车即将退出 */
              break;

             default:
              LocalVar_ADCS8_TBA_text = 0U;
              break;
            }
            break;

           default:
            LocalVar_ADCS8_TBA_text = 0U;

            /* 0x0：Noindication */
            break;
          }
        }
        break;
      }
    }
  }
  else
  {
    LocalVar_ADCS8_TBA_text = 0U;

    /* 0x0：Noindication */
  }

  /* End of MATLAB Function: '<Root>/ADCS8_TBA_text' */

  /* MATLAB Function: '<S25>/ADCS4PAfailinfoDet' incorporates:
   *  RelationalOperator: '<S22>/EMEqual'
   */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
           (((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_STANDBY) ?
             ((int32_T)1) : ((int32_T)0)) | ((rtu_sMasterLsadFsm->eLsadSystemSts
              == LSAD_STS_FAILURE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
          1) : ((int32_T)0)) | ((rtu_sMasterLsadFsm->eLsadSystemSts ==
          LSAD_STS_INHIBIT) ? ((int32_T)1) : ((int32_T)0)))))
  {
    if (rtu_sVehDataRx->sVehVCUInfo.bHVOff)
    {
      LocalVar_ADCS4_PA_failinfo = 4U;

      /*   0x4：请在车辆启动下，使用此功能    */
    }
    else if (rtu_sDiagInfo->sVisionFail.bVisionFail)
    {
      LocalVar_ADCS4_PA_failinfo = 1U;

      /* 0x1摄像头故障，功能无法开启 */
    }
    else if (rtu_sDiagInfo->sUssFail.bUssFail)
    {
      LocalVar_ADCS4_PA_failinfo = 3U;

      /* 0x3雷达故障，功能无法开启 */
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                  ((rtu_sDiagInfo->bPASysFail ? ((int32_T)1) : ((int32_T)0)) &
                   (((boolean_T)((int32_T)
        ((rtu_sDiagInfo->sVisionFail.bVisionFail ? ((int32_T)1) : ((int32_T)0)) ^
         1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
               (((boolean_T)((int32_T)((rtu_sDiagInfo->sUssFail.bUssFail ?
        ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
    {
      LocalVar_ADCS4_PA_failinfo = 2U;

      /*    0x2系统故障，功能无法开启 */
    }
    else if ((boolean_T)((int32_T)((rtu_sVehCommon->sCondiVeh.bExterActualNorm ?
                ((int32_T)1) : ((int32_T)0)) ^ 1)))
    {
      LocalVar_ADCS4_PA_failinfo = 5U;

      /*  0x5关联件系统故障，功能无法开启 */
    }
    else if (rtu_sVehDataRx->sVehESCInfo.f32VehSpdKph > k_SuppressEnterSpd)
    {
      LocalVar_ADCS4_PA_failinfo = 7U;

      /*  0x7请保持速度＜25km/h下，使用此功能 */
    }
    else if (rtu_sVehDataRx->sVehESCInfo.bDAActive)
    {
      LocalVar_ADCS4_PA_failinfo = 8U;

      /*   0x8：ADAS已开启，无法使用此功能 */
      /*      elseif(~sVehCommon.sCondiVeh.bTirePressNorm) */
      /*          ADCS4_PA_failinfo = uint8(5); % 0x5：关联件系统故障，功能无法开启 */
    }
    else if (rtu_sVehDataRx->sVehBCMInfo.bMirrFld)
    {
      LocalVar_ADCS4_PA_failinfo = 6U;

      /*   0x6：后视镜折叠，功能无法开启 */
    }
    else
    {
      LocalVar_ADCS4_PA_failinfo = 0U;

      /*   0x0”Normal” */
    }
  }
  else
  {
    LocalVar_ADCS4_PA_failinfo = 0U;

    /*   0x0”Normal” */
  }

  /* End of MATLAB Function: '<S25>/ADCS4PAfailinfoDet' */

  /* Outputs for Atomic SubSystem: '<Root>/PA_WorkSts' */
  /* If: '<S21>/If' incorporates:
   *  Constant: '<S81>/Constant'
   *  Constant: '<S82>/Constant'
   *  Logic: '<S21>/EMAND'
   *  RelationalOperator: '<S21>/Equal'
   *  RelationalOperator: '<S21>/Equal1'
   */
  if ((boolean_T)((int32_T)(((rtu_sSlaveLsadFsm->eLsadFuncType != LSAD_RA) ?
         ((int32_T)1) : ((int32_T)0)) & ((rtu_sSlaveLsadFsm->eLsadFuncType !=
          LSAD_EOL) ? ((int32_T)1) : ((int32_T)0)))))
  {
    /* Outputs for IfAction SubSystem: '<S21>/IfPA_WorkSts_APA' incorporates:
     *  ActionPort: '<S83>/Action Port'
     */
    /* MATLAB Function: '<S83>/PAADCS11ParkWorkSts' incorporates:
     *  RelationalOperator: '<S22>/EMEqual'
     */
    /*  if(sCommonCondi.sCondiHMI.eAPADeActReq == tAPADeActReq.APA_ACTIVATE) */
    /*      ADCU1_APA_Step = uint8(1); %Initial */
    if (rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_STANDBY)
    {
      /* SignalConversion generated from: '<S83>/PA_ADCS11_Parking_WorkSts' incorporates:
       *  UnitDelay: '<S21>/Unit Delay'
       */
      hozon_hmi_output_DW.UnitDelay_DSTATE_g = 2U;

      /* 0x2TBAstatndby（之前是0x1statndby）还没选功能的时候，发2 */
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                  (((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_SEARCH) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_CONFIRM)
                    ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)
                 0)) & ((rtu_sPaStateAdptr->sCondiHMI.ePrkFnct == PARK_FUNC_RPA)
                        ? ((int32_T)1) : ((int32_T)0)))))
    {
      /* SignalConversion generated from: '<S83>/PA_ADCS11_Parking_WorkSts' incorporates:
       *  UnitDelay: '<S21>/Unit Delay'
       */
      hozon_hmi_output_DW.UnitDelay_DSTATE_g = 3U;

      /* 0x3"Parking"  */
    }
    else if ((boolean_T)((int32_T)(((rtu_sPaStateAdptr->sCondiHMI.ePrkFnct ==
                 PARK_FUNC_RPA) ? ((int32_T)1) : ((int32_T)0)) &
               ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_PREPARE_SUSPEND)
                ? ((int32_T)1) : ((int32_T)0)))))
    {
      /* SignalConversion generated from: '<S83>/PA_ADCS11_Parking_WorkSts' incorporates:
       *  UnitDelay: '<S21>/Unit Delay'
       */
      hozon_hmi_output_DW.UnitDelay_DSTATE_g = 8U;

      /* 0x8"Suspend" */
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
        ((int32_T)(((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_SEARCH) ?
                    ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sSlaveLsadFsm->eLsadFuncSts ==
                     FUNC_STS_APA_BACKGROUND_SEARCH) ? ((int32_T)1) : ((int32_T)
        0))))) ? ((int32_T)1) : ((int32_T)0)) |
        ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_PREPARE_SUSPEND) ?
         ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
               ((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_CONFIRM) ?
                ((int32_T)1) : ((int32_T)0)))))
    {
      /* SignalConversion generated from: '<S83>/PA_ADCS11_Parking_WorkSts' incorporates:
       *  UnitDelay: '<S21>/Unit Delay'
       */
      hozon_hmi_output_DW.UnitDelay_DSTATE_g = 1U;

      /* 0x1”Standby(通过开关进入PA)" */
    }
    else
    {
      switch (rtu_sSlaveLsadFsm->eLsadFuncSts)
      {
       case FUNC_STS_APA_PO_CONFIRM:
        /* SignalConversion generated from: '<S83>/PA_ADCS11_Parking_WorkSts' incorporates:
         *  UnitDelay: '<S21>/Unit Delay'
         */
        hozon_hmi_output_DW.UnitDelay_DSTATE_g = 1U;

        /* 0x1”Standby(通过开关进入PA)"       */
        break;

       case FUNC_STS_RPA_REMOTE_CONNECT:
        if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
                     ((((boolean_T)((int32_T)((((boolean_T)((int32_T)
            ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
            ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
            ((((boolean_T)((int32_T)((((boolean_T)((int32_T)
            ((rtu_sPaStateAdptr->sRPAChkList.bRPADrClose ? ((int32_T)1) :
            ((int32_T)0)) & (rtu_sPaStateAdptr->sRPAChkList.bRPAVehStdstil ?
            ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
            (rtu_sPaStateAdptr->sRPAChkList.bRPAGearAval ? ((int32_T)1) :
            ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
            (rtu_sPaStateAdptr->sRPAChkList.bRPAEPBAval ? ((int32_T)1) :
            ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
            (rtu_sPaStateAdptr->sRPAChkList.bRPASlopAval ? ((int32_T)1) :
            ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
            (rtu_sPaStateAdptr->sRPAChkList.bRPASurrAval ? ((int32_T)1) :
            ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
            (rtu_sPaStateAdptr->sRPAChkList.bRPASysNorm ? ((int32_T)1) :
            ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
            (rtu_sPaStateAdptr->sRPAChkList.bRPATirePresNorm ? ((int32_T)1) :
            ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
             (rtu_sPaStateAdptr->sRPAChkList.bRPASlotFind ? ((int32_T)1) :
            ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
            (rtu_sPaStateAdptr->sRPAChkList.bBLEConnect ? ((int32_T)1) :
             ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
                      (rtu_sPaStateAdptr->sRPAChkList.bBLEScrt ? ((int32_T)1) :
                       ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
                  (rtu_sPaStateAdptr->sRPAChkList.bTrunkClose ? ((int32_T)1) :
                   ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
              (rtu_sPaStateAdptr->sRPAChkList.bHoodClose ? ((int32_T)1) :
               ((int32_T)0)))))
        {
          /* SignalConversion generated from: '<S83>/PA_ADCS11_Parking_WorkSts' incorporates:
           *  UnitDelay: '<S21>/Unit Delay'
           */
          hozon_hmi_output_DW.UnitDelay_DSTATE_g = 1U;

          /* 0x1”Standby”  */
        }
        break;

       default:
        if ((boolean_T)((int32_T)(((rtu_sMasterLsadFsm->eLsadSystemSts ==
                LSAD_STS_PP) ? ((int32_T)1) : ((int32_T)0)) |
              ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_HANDSHAKE) ?
               ((int32_T)1) : ((int32_T)0)))))
        {
          /* SignalConversion generated from: '<S83>/PA_ADCS11_Parking_WorkSts' incorporates:
           *  UnitDelay: '<S21>/Unit Delay'
           */
          hozon_hmi_output_DW.UnitDelay_DSTATE_g = 3U;

          /* 0x3"Parking" */
        }
        else if (rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE)
        {
          /* SignalConversion generated from: '<S83>/PA_ADCS11_Parking_WorkSts' incorporates:
           *  UnitDelay: '<S21>/Unit Delay'
           */
          hozon_hmi_output_DW.UnitDelay_DSTATE_g = 3U;

          /* 0x3"Parking" */
        }
        else if ((boolean_T)((int32_T)(((rtu_sMasterLsadFsm->eLsadSystemSts ==
                     LSAD_STS_STANDBY) ? ((int32_T)1) : ((int32_T)0)) |
                   (((boolean_T)((int32_T)(((rtu_sMasterLsadFsm->eLsadSystemSts ==
          LSAD_STS_QUIT) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
            (((rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkWorkMd == PRK_WORK_EXIT) ?
              ((int32_T)1) : ((int32_T)0)) |
             ((rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkWorkMd == PRK_WORK_EXIT) ?
              ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) ?
                    ((int32_T)1) : ((int32_T)0)))))
        {
          /* SignalConversion generated from: '<S83>/PA_ADCS11_Parking_WorkSts' incorporates:
           *  UnitDelay: '<S21>/Unit Delay'
           */
          /* %该条件有互斥 */
          hozon_hmi_output_DW.UnitDelay_DSTATE_g = 0U;

          /* 0x0"OFF" */
        }
        else if ((boolean_T)((int32_T)(((rtu_sMasterLsadFsm->eLsadSystemSts ==
                     LSAD_STS_INHIBIT) ? ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_FAILURE) ?
                    ((int32_T)1) : ((int32_T)0)))))
        {
          /* SignalConversion generated from: '<S83>/PA_ADCS11_Parking_WorkSts' incorporates:
           *  UnitDelay: '<S21>/Unit Delay'
           */
          hozon_hmi_output_DW.UnitDelay_DSTATE_g = 10U;

          /* 0xA"Failure"。 */
        }
        else
        {
          switch (rtu_sMasterLsadFsm->eLsadSystemSts)
          {
           case LSAD_STS_COMPLETE:
            if (LocalVar_bParkBarPercentaDelay)
            {
              /* SignalConversion generated from: '<S83>/PA_ADCS11_Parking_WorkSts' incorporates:
               *  UnitDelay: '<S21>/Unit Delay'
               */
              hozon_hmi_output_DW.UnitDelay_DSTATE_g = 7U;

              /* 0x7“Complete” */
            }
            break;

           case LSAD_STS_ACTIVE_SUSPEND:
            /* SignalConversion generated from: '<S83>/PA_ADCS11_Parking_WorkSts' incorporates:
             *  UnitDelay: '<S21>/Unit Delay'
             */
            hozon_hmi_output_DW.UnitDelay_DSTATE_g = 8U;

            /* 0x8"Suspend" */
            break;

           default:
            if ((boolean_T)((int32_T)(((rtu_sMasterLsadFsm->eLsadSystemSts ==
                    LSAD_STS_QUIT) ? ((int32_T)1) : ((int32_T)0)) |
                  ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_TERMINATED) ?
                   ((int32_T)1) : ((int32_T)0)))))
            {
              /* SignalConversion generated from: '<S83>/PA_ADCS11_Parking_WorkSts' incorporates:
               *  UnitDelay: '<S21>/Unit Delay'
               */
              hozon_hmi_output_DW.UnitDelay_DSTATE_g = 9U;

              /* 0x9"Abort" */
            }
            else
            {
              /* SignalConversion generated from: '<S83>/PA_ADCS11_Parking_WorkSts' incorporates:
               *  UnitDelay: '<S21>/Unit Delay'
               */
              hozon_hmi_output_DW.UnitDelay_DSTATE_g = 0U;

              /* 0x0"OFF" */
            }
            break;
          }
        }
        break;
      }
    }

    /* End of MATLAB Function: '<S83>/PAADCS11ParkWorkSts' */
    /* End of Outputs for SubSystem: '<S21>/IfPA_WorkSts_APA' */
  }
  else
  {
    /* Outputs for IfAction SubSystem: '<S21>/IfRA_WorkSts_RA' incorporates:
     *  ActionPort: '<S84>/Action Port'
     */
    /* MATLAB Function: '<S84>/RAADCS11ParkingWorkSts' incorporates:
     *  RelationalOperator: '<S22>/EMEqual'
     */
    /*  if(sCommonCondi.sCondiHMI.eAPADeActReq == tAPADeActReq.APA_ACTIVATE) */
    /*      ADCU1_APA_Step = uint8(1); %Initial    */
    if (rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_STANDBY)
    {
      /* SignalConversion generated from: '<S84>/RA_ADCS11_Parking_WorkSts' incorporates:
       *  UnitDelay: '<S21>/Unit Delay'
       */
      hozon_hmi_output_DW.UnitDelay_DSTATE_g = 2U;

      /* 0x2TBAstatndby（之前是0x1statndby） */
    }
    else if ((boolean_T)((int32_T)(((rtu_sMasterLsadFsm->eLsadSystemSts ==
                 LSAD_STS_PREPARE) ? ((int32_T)1) : ((int32_T)0)) |
               ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_PREPARE_SUSPEND)
                ? ((int32_T)1) : ((int32_T)0)))))
    {
      /* SignalConversion generated from: '<S84>/RA_ADCS11_Parking_WorkSts' incorporates:
       *  UnitDelay: '<S21>/Unit Delay'
       */
      hozon_hmi_output_DW.UnitDelay_DSTATE_g = 2U;

      /* 0x2TBAstatndby（之前是0x1statndby） */
    }
    else
    {
      switch (rtu_sMasterLsadFsm->eLsadSystemSts)
      {
       case LSAD_STS_HANDSHAKE:
        /* SignalConversion generated from: '<S84>/RA_ADCS11_Parking_WorkSts' incorporates:
         *  UnitDelay: '<S21>/Unit Delay'
         */
        hozon_hmi_output_DW.UnitDelay_DSTATE_g = 3U;

        /* 0x3"Parking"       */
        break;

       case LSAD_STS_ACTIVE:
        /* SignalConversion generated from: '<S84>/RA_ADCS11_Parking_WorkSts' incorporates:
         *  UnitDelay: '<S21>/Unit Delay'
         */
        hozon_hmi_output_DW.UnitDelay_DSTATE_g = 3U;

        /* 0x3"Parking" */
        break;

       case LSAD_STS_FAILURE:
        /* SignalConversion generated from: '<S84>/RA_ADCS11_Parking_WorkSts' incorporates:
         *  UnitDelay: '<S21>/Unit Delay'
         */
        hozon_hmi_output_DW.UnitDelay_DSTATE_g = 10U;

        /* 0xA"Failure"。 */
        break;

       case LSAD_STS_COMPLETE:
        /* SignalConversion generated from: '<S84>/RA_ADCS11_Parking_WorkSts' incorporates:
         *  UnitDelay: '<S21>/Unit Delay'
         */
        hozon_hmi_output_DW.UnitDelay_DSTATE_g = 7U;

        /* 0x7“Complete” */
        break;

       case LSAD_STS_ACTIVE_SUSPEND:
        /* SignalConversion generated from: '<S84>/RA_ADCS11_Parking_WorkSts' incorporates:
         *  UnitDelay: '<S21>/Unit Delay'
         */
        hozon_hmi_output_DW.UnitDelay_DSTATE_g = 8U;

        /* 0x8"Suspend" */
        break;

       case LSAD_STS_TERMINATED:
        /* SignalConversion generated from: '<S84>/RA_ADCS11_Parking_WorkSts' incorporates:
         *  UnitDelay: '<S21>/Unit Delay'
         */
        hozon_hmi_output_DW.UnitDelay_DSTATE_g = 9U;

        /* 0x9"Abort" */
        break;

       default:
        /* SignalConversion generated from: '<S84>/RA_ADCS11_Parking_WorkSts' incorporates:
         *  UnitDelay: '<S21>/Unit Delay'
         */
        hozon_hmi_output_DW.UnitDelay_DSTATE_g = 0U;
        break;
      }
    }

    /* End of MATLAB Function: '<S84>/RAADCS11ParkingWorkSts' */
    /* End of Outputs for SubSystem: '<S21>/IfRA_WorkSts_RA' */
  }

  /* End of If: '<S21>/If' */
  /* End of Outputs for SubSystem: '<Root>/PA_WorkSts' */

  /* MATLAB Function: '<S23>/ParkingWorkStsLatch' incorporates:
   *  UnitDelay: '<S21>/Unit Delay'
   *  UnitDelay: '<S23>/Unit Delay'
   *  UnitDelay: '<S23>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)(((((int32_T)hozon_hmi_output_DW.UnitDelay_DSTATE_b) ==
          8) ? ((int32_T)1) : ((int32_T)0)) & ((((int32_T)
           hozon_hmi_output_DW.UnitDelay_DSTATE_g) == 3) ? ((int32_T)1) :
         ((int32_T)0)))))
  {
    LocalVar_ADCS11_Parking_WorkSts = 3U;
    hozon_hmi_output_DW.UnitDelay1_DSTATE++;
  }
  else if ((boolean_T)((int32_T)(((hozon_hmi_output_DW.UnitDelay1_DSTATE > 0.0) ?
              ((int32_T)1) : ((int32_T)0)) &
             ((hozon_hmi_output_DW.UnitDelay1_DSTATE <= 25.0) ? ((int32_T)1) :
              ((int32_T)0)))))
  {
    LocalVar_ADCS11_Parking_WorkSts = 3U;
    hozon_hmi_output_DW.UnitDelay1_DSTATE++;
  }
  else
  {
    LocalVar_ADCS11_Parking_WorkSts = hozon_hmi_output_DW.UnitDelay_DSTATE_g;
    hozon_hmi_output_DW.UnitDelay1_DSTATE = 0.0;
  }

  /* End of MATLAB Function: '<S23>/ParkingWorkStsLatch' */

  /* Logic: '<Root>/Logical Operator19' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S20>/Constant'
   *  RelationalOperator: '<Root>/Equal7'
   *  RelationalOperator: '<Root>/Equal8'
   *  RelationalOperator: '<S22>/EMEqual'
   */
  LocalVar_bParkBarPercentaDelay = (rtu_sMasterLsadFsm->eLsadSystemSts ==
    LSAD_STS_QUIT) | (rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_FAILURE);
  (void)memset(rty_sPADispTx, 0, sizeof(tPADispTx));

  /* Switch: '<S98>/Switch' incorporates:
   *  Constant: '<S25>/Constant1'
   *  RelationalOperator: '<S25>/Equal1'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  if (((int32_T)hozon_hmi_output_DW.UnitDelay1_DSTATE_nu) == 0)
  {
    /* BusAssignment: '<Root>/Bus Assignment2' */
    rty_sPADispTx->ADCS4_PA_failinfo = LocalVar_ADCS4_PA_failinfo;
  }
  else
  {
    /* BusAssignment: '<Root>/Bus Assignment2' incorporates:
     *  Constant: '<S25>/Constant3'
     */
    rty_sPADispTx->ADCS4_PA_failinfo = 0U;
  }

  /* End of Switch: '<S98>/Switch' */

  /* BusAssignment: '<Root>/Bus Assignment2' */
  rty_sPADispTx->ADCS8_PA_warninginfo = LocalVar_ADCS8_PA_warninginfo;
  rty_sPADispTx->ADCS11_Parking_WorkSts = LocalVar_ADCS11_Parking_WorkSts;

  /* Switch: '<S12>/Switch1' incorporates:
   *  Constant: '<S77>/Constant'
   *  Constant: '<S78>/Constant'
   *  Constant: '<S79>/Constant'
   *  Constant: '<S80>/Constant'
   *  RelationalOperator: '<S12>/Equal'
   *  RelationalOperator: '<S12>/Equal1'
   *  RelationalOperator: '<S12>/Equal2'
   *  RelationalOperator: '<S12>/Equal3'
   *  Switch: '<S12>/Switch2'
   *  Switch: '<S12>/Switch4'
   *  Switch: '<S12>/Switch5'
   */
  if (rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_PARK_IN)
  {
    /* BusAssignment: '<Root>/Bus Assignment2' incorporates:
     *  Constant: '<S12>/Constant1'
     */
    rty_sPADispTx->ADCS4_APA_FunctionMode = 1U;
  }
  else if (rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_PARK_OUT)
  {
    /* Switch: '<S12>/Switch2' incorporates:
     *  BusAssignment: '<Root>/Bus Assignment2'
     *  Constant: '<S12>/Constant2'
     */
    rty_sPADispTx->ADCS4_APA_FunctionMode = 2U;
  }
  else if (rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_SELF_SELECT)
  {
    /* Switch: '<S12>/Switch4' incorporates:
     *  BusAssignment: '<Root>/Bus Assignment2'
     *  Constant: '<S12>/Constant3'
     *  Switch: '<S12>/Switch2'
     */
    rty_sPADispTx->ADCS4_APA_FunctionMode = 3U;
  }
  else if (rtu_sSlaveLsadFsm->eLsadFuncType == LSAD_RA)
  {
    /* Switch: '<S12>/Switch5' incorporates:
     *  BusAssignment: '<Root>/Bus Assignment2'
     *  Constant: '<S12>/Constant5'
     *  Switch: '<S12>/Switch2'
     *  Switch: '<S12>/Switch4'
     */
    rty_sPADispTx->ADCS4_APA_FunctionMode = 4U;
  }
  else
  {
    /* BusAssignment: '<Root>/Bus Assignment2' incorporates:
     *  Constant: '<S12>/Constant4'
     *  Switch: '<S12>/Switch2'
     *  Switch: '<S12>/Switch4'
     *  Switch: '<S12>/Switch5'
     */
    rty_sPADispTx->ADCS4_APA_FunctionMode = 0U;
  }

  /* End of Switch: '<S12>/Switch1' */

  /* Switch: '<S24>/Switch3' incorporates:
   *  Constant: '<S92>/Constant'
   *  Constant: '<S93>/Constant'
   *  Constant: '<S94>/Constant'
   *  Constant: '<S95>/Constant'
   *  Constant: '<S96>/Constant'
   *  RelationalOperator: '<S24>/Equal1'
   *  RelationalOperator: '<S24>/Equal2'
   *  RelationalOperator: '<S24>/Equal3'
   *  RelationalOperator: '<S24>/Equal4'
   *  RelationalOperator: '<S24>/Equal6'
   *  Switch: '<S24>/Switch1'
   *  Switch: '<S24>/Switch2'
   *  Switch: '<S24>/Switch4'
   *  Switch: '<S24>/Switch5'
   */
  if (rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_NONE)
  {
    /* BusAssignment: '<Root>/Bus Assignment2' incorporates:
     *  Constant: '<S24>/Constant'
     */
    rty_sPADispTx->ADCS4_RPA_FunctionMode = 0U;
  }
  else if (rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_PARK_IN)
  {
    /* Switch: '<S24>/Switch1' incorporates:
     *  BusAssignment: '<Root>/Bus Assignment2'
     *  Constant: '<S24>/Constant1'
     */
    rty_sPADispTx->ADCS4_RPA_FunctionMode = 1U;
  }
  else if (rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_PARK_OUT)
  {
    /* Switch: '<S24>/Switch2' incorporates:
     *  BusAssignment: '<Root>/Bus Assignment2'
     *  Constant: '<S24>/Constant2'
     *  Switch: '<S24>/Switch1'
     */
    rty_sPADispTx->ADCS4_RPA_FunctionMode = 2U;
  }
  else if (rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_SELF_SELECT)
  {
    /* Switch: '<S24>/Switch4' incorporates:
     *  BusAssignment: '<Root>/Bus Assignment2'
     *  Constant: '<S24>/Constant3'
     *  Switch: '<S24>/Switch1'
     *  Switch: '<S24>/Switch2'
     */
    rty_sPADispTx->ADCS4_RPA_FunctionMode = 3U;
  }
  else if (rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_STRAIGHT)
  {
    /* Switch: '<S24>/Switch5' incorporates:
     *  BusAssignment: '<Root>/Bus Assignment2'
     *  Constant: '<S24>/Constant5'
     *  Switch: '<S24>/Switch1'
     *  Switch: '<S24>/Switch2'
     *  Switch: '<S24>/Switch4'
     */
    rty_sPADispTx->ADCS4_RPA_FunctionMode = 4U;
  }
  else
  {
    /* BusAssignment: '<Root>/Bus Assignment2' incorporates:
     *  Constant: '<S24>/Constant4'
     *  Switch: '<S24>/Switch1'
     *  Switch: '<S24>/Switch2'
     *  Switch: '<S24>/Switch4'
     *  Switch: '<S24>/Switch5'
     */
    rty_sPADispTx->ADCS4_RPA_FunctionMode = 0U;
  }

  /* End of Switch: '<S24>/Switch3' */

  /* Switch: '<S8>/Switch3' incorporates:
   *  Constant: '<S73>/Constant'
   *  Constant: '<S74>/Constant'
   *  RelationalOperator: '<S8>/Equal1'
   *  RelationalOperator: '<S8>/Equal6'
   *  Switch: '<S8>/Switch1'
   */
  if (rtu_sHMIComDisp->eSlotAvaliab == SLOT_AVALIABLE)
  {
    /* BusAssignment: '<Root>/Bus Assignment2' incorporates:
     *  Constant: '<S8>/Constant'
     */
    rty_sPADispTx->ADCS4_Slotavaliable = 1U;
  }
  else if (rtu_sHMIComDisp->eSlotAvaliab == SLOT_NOT_AVALIABLE)
  {
    /* Switch: '<S8>/Switch1' incorporates:
     *  BusAssignment: '<Root>/Bus Assignment2'
     *  Constant: '<S8>/Constant1'
     */
    rty_sPADispTx->ADCS4_Slotavaliable = 2U;
  }
  else
  {
    /* BusAssignment: '<Root>/Bus Assignment2' incorporates:
     *  Constant: '<S8>/Constant2'
     *  Switch: '<S8>/Switch1'
     */
    rty_sPADispTx->ADCS4_Slotavaliable = 0U;
  }

  /* End of Switch: '<S8>/Switch3' */

  /* BusAssignment: '<Root>/Bus Assignment2' incorporates:
   *  Constant: '<S60>/Constant'
   *  Constant: '<S61>/Constant'
   *  Constant: '<S62>/Constant'
   *  Constant: '<S63>/Constant'
   *  Constant: '<S64>/Constant'
   *  Constant: '<S65>/Constant'
   *  Constant: '<S66>/Constant'
   *  Constant: '<S67>/Constant'
   *  Constant: '<S68>/Constant'
   *  Constant: '<S69>/Constant'
   *  Constant: '<S70>/Constant'
   *  Constant: '<S71>/Constant'
   *  Constant: '<S72>/Constant'
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   *  Logic: '<S7>/Logical Operator'
   *  Logic: '<S7>/Logical Operator1'
   *  Logic: '<S7>/Logical Operator2'
   *  Logic: '<S7>/Logical Operator3'
   *  Logic: '<S7>/Logical Operator4'
   *  Logic: '<S7>/Logical Operator5'
   *  Logic: '<S7>/Logical Operator6'
   *  Logic: '<S7>/Logical Operator7'
   *  Logic: '<S7>/Logical Operator8'
   *  RelationalOperator: '<S22>/EMEqual'
   *  RelationalOperator: '<S7>/Equal1'
   *  RelationalOperator: '<S7>/Equal10'
   *  RelationalOperator: '<S7>/Equal11'
   *  RelationalOperator: '<S7>/Equal12'
   *  RelationalOperator: '<S7>/Equal13'
   *  RelationalOperator: '<S7>/Equal2'
   *  RelationalOperator: '<S7>/Equal3'
   *  RelationalOperator: '<S7>/Equal4'
   *  RelationalOperator: '<S7>/Equal5'
   *  RelationalOperator: '<S7>/Equal6'
   *  RelationalOperator: '<S7>/Equal7'
   *  RelationalOperator: '<S7>/Equal8'
   *  RelationalOperator: '<S7>/Equal9'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  rty_sPADispTx->ADCS4_ParkingswithReq = ((boolean_T)((int32_T)((((boolean_T)
    ((int32_T)((((boolean_T)((int32_T)(((rtu_sSlaveLsadFsm->eLsadFuncSts ==
    FUNC_STS_APA_PI_CONFIRM) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)
    ((int32_T)((((boolean_T)((int32_T)(((rtu_sPaStateAdptr->sCondiHMI.eAPAMod ==
    APA_MODE_PARK_IN) ? ((int32_T)1) : ((int32_T)0)) &
    ((rtu_sPaStateAdptr->sCondiHMI.ePrkFnct == PARK_FUNC_APA) ? ((int32_T)1) :
    ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
    (((rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_SELF_SELECT) ? ((int32_T)
    1) : ((int32_T)0)) & ((rtu_sHMIComDisp->eSlotAvaliab == SLOT_AVALIABLE) ?
    ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) ?
    ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
               (((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
    ((int32_T)((((boolean_T)((int32_T)(((rtu_sSlaveLsadFsm->eLsadFuncSts ==
    FUNC_STS_RPA_PI_CONFIRM) ? ((int32_T)1) : ((int32_T)0)) |
    ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ? ((int32_T)1) :
    ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
               ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_HANDSHAKE) ?
    ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
    ((rtu_sPaStateAdptr->sCondiHMI.ePrkFnct == PARK_FUNC_RPA) ? ((int32_T)1) :
     ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
    (rtu_sPAHmiRx->sRPAHmiRx.bRPAFixSlot ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
    (((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
    (((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PO_CONFIRM) ? ((int32_T)1)
      : ((int32_T)0)) | ((rtu_sSlaveLsadFsm->eLsadFuncSts ==
    FUNC_STS_RPA_PO_CONFIRM) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) & ((rtu_sPaStateAdptr->sCondiHMI.ePOSlotType !=
                      PO_SLOT_TYPE_NONE) ? ((int32_T)1) : ((int32_T)0))))) ?
    ((int32_T)1) : ((int32_T)0)) & ((rtu_sPaStateAdptr->sCondiHMI.ePODir !=
    PO_DIR_NO_REQ) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)
    0))))) ? ((uint8_T)1) : ((uint8_T)0);
  rty_sPADispTx->ADCS4_AVM_vedioReq = hozon_hmi_output_DW.UnitDelay1_DSTATE_nu;

  /* Switch: '<S76>/Switch' incorporates:
   *  Constant: '<S9>/Constant'
   *  RelationalOperator: '<S9>/Equal'
   */
  if (0 != ((int32_T)LocalVar_ADCS8_PA_warninginfo))
  {
    /* BusAssignment: '<Root>/Bus Assignment2' incorporates:
     *  Constant: '<S9>/Constant1'
     */
    rty_sPADispTx->ADCS4_Text = 0U;
  }
  else
  {
    /* BusAssignment: '<Root>/Bus Assignment2' incorporates:
     *  UnitDelay: '<S9>/Unit Delay'
     */
    rty_sPADispTx->ADCS4_Text = hozon_hmi_output_DW.UnitDelay_DSTATE_k;
  }

  /* End of Switch: '<S76>/Switch' */

  /* Switch: '<S100>/Switch' incorporates:
   *  Constant: '<S99>/Constant'
   *  RelationalOperator: '<S26>/EMEqual'
   */
  if (rtu_sSlaveLsadFsm->eLsadFuncType == LSAD_RA)
  {
    /* BusAssignment: '<Root>/Bus Assignment2' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion9'
     */
    rty_sPADispTx->ADCS4_TBA_Distance = (uint8_T)
      rtu_sRelatedModuleInfo->f32CtrlReqStopDistance;
  }
  else
  {
    /* BusAssignment: '<Root>/Bus Assignment2' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion9'
     */
    rty_sPADispTx->ADCS4_TBA_Distance = 0U;
  }

  /* End of Switch: '<S100>/Switch' */

  /* Saturate: '<S6>/EMSaturation' incorporates:
   *  UnitDelay: '<S6>/Unit Delay'
   */
  if (hozon_hmi_output_DW.UnitDelay_DSTATE > k_ManeuverDuratTime)
  {
    tmp_0 = k_ManeuverDuratTime;
  }
  else if (hozon_hmi_output_DW.UnitDelay_DSTATE < 0.0F)
  {
    tmp_0 = 0.0F;
  }
  else
  {
    tmp_0 = hozon_hmi_output_DW.UnitDelay_DSTATE;
  }

  /* End of Saturate: '<S6>/EMSaturation' */

  /* BusAssignment: '<Root>/Bus Assignment2' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S15>/Constant'
   *  Constant: '<S16>/Constant'
   *  Constant: '<S17>/Constant'
   *  Constant: '<S18>/Constant'
   *  Constant: '<S19>/Constant'
   *  Constant: '<S32>/Constant'
   *  Constant: '<S33>/Constant'
   *  Constant: '<S34>/Constant'
   *  Constant: '<S35>/Constant'
   *  Constant: '<S36>/Constant'
   *  Constant: '<S37>/Constant'
   *  Constant: '<S38>/Constant'
   *  Constant: '<S39>/Constant'
   *  Constant: '<S40>/Constant'
   *  Constant: '<S41>/Constant'
   *  Constant: '<S42>/Constant'
   *  Constant: '<S43>/Constant'
   *  Constant: '<S44>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  DataTypeConversion: '<Root>/Data Type Conversion3'
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   *  DataTypeConversion: '<Root>/Data Type Conversion5'
   *  DataTypeConversion: '<Root>/Data Type Conversion6'
   *  DataTypeConversion: '<Root>/Data Type Conversion7'
   *  DataTypeConversion: '<Root>/Data Type Conversion8'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   *  Logic: '<Root>/Logical Operator'
   *  Logic: '<Root>/Logical Operator1'
   *  Logic: '<Root>/Logical Operator10'
   *  Logic: '<Root>/Logical Operator11'
   *  Logic: '<Root>/Logical Operator12'
   *  Logic: '<Root>/Logical Operator13'
   *  Logic: '<Root>/Logical Operator14'
   *  Logic: '<Root>/Logical Operator15'
   *  Logic: '<Root>/Logical Operator16'
   *  Logic: '<Root>/Logical Operator17'
   *  Logic: '<Root>/Logical Operator18'
   *  Logic: '<Root>/Logical Operator2'
   *  Logic: '<Root>/Logical Operator20'
   *  Logic: '<Root>/Logical Operator21'
   *  Logic: '<Root>/Logical Operator3'
   *  Logic: '<Root>/Logical Operator4'
   *  Logic: '<Root>/Logical Operator5'
   *  Logic: '<Root>/Logical Operator6'
   *  Logic: '<Root>/Logical Operator7'
   *  Logic: '<Root>/Logical Operator8'
   *  Logic: '<Root>/Logical Operator9'
   *  Logic: '<S3>/Logical Operator'
   *  Logic: '<S3>/Logical Operator1'
   *  Logic: '<S3>/Logical Operator2'
   *  Logic: '<S3>/Logical Operator3'
   *  RelationalOperator: '<Root>/Equal1'
   *  RelationalOperator: '<Root>/Equal2'
   *  RelationalOperator: '<Root>/Equal3'
   *  RelationalOperator: '<Root>/Equal4'
   *  RelationalOperator: '<Root>/Equal5'
   *  RelationalOperator: '<Root>/Equal6'
   *  RelationalOperator: '<S22>/EMEqual'
   *  RelationalOperator: '<S3>/Equal'
   *  RelationalOperator: '<S3>/Equal1'
   *  RelationalOperator: '<S3>/Equal10'
   *  RelationalOperator: '<S3>/Equal11'
   *  RelationalOperator: '<S3>/Equal12'
   *  RelationalOperator: '<S3>/Equal13'
   *  RelationalOperator: '<S3>/Equal2'
   *  RelationalOperator: '<S3>/Equal3'
   *  RelationalOperator: '<S3>/Equal4'
   *  RelationalOperator: '<S3>/Equal5'
   *  RelationalOperator: '<S3>/Equal6'
   *  RelationalOperator: '<S3>/Equal7'
   *  RelationalOperator: '<S3>/Equal8'
   *  RelationalOperator: '<S3>/Equal9'
   */
  rty_sPADispTx->ADCS4_ParkingTime = (uint16_T)roundf(tmp_0);
  rty_sPADispTx->ADCS4_PA_ParkBarPercent = u8aParkBarPercent;
  rty_sPADispTx->ADCS4_TractionswithReq = ((boolean_T)((int32_T)((((boolean_T)
    ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
    ((int32_T)(((rtu_sSlaveLsadFsm->eLsadFuncType == LSAD_FUNC_TYPE_NONE) ?
    ((int32_T)1) : ((int32_T)0)) & ((rtu_sSlaveLsadFsm->eBckgrndRecordSts ==
    BACKGROUND_MODULE_STS_ENABLE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)
    1) : ((int32_T)0)) & ((rtu_sRelatedModuleInfo->f32RARecordedDist >= 5.0F) ?
    ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
    (rtu_sVehCommon->sCondiVeh.bVehStill ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) &
               ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_STANDBY) ?
                ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
    (((boolean_T)((int32_T)(((rtu_sSlaveLsadFsm->eLsadFuncType == LSAD_RA) ?
    ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)((((boolean_T)
    ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
    ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
    ((int32_T)(((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_PREPARE) ?
    ((int32_T)1) : ((int32_T)0)) | ((rtu_sMasterLsadFsm->eLsadSystemSts ==
    LSAD_STS_PREPARE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_HANDSHAKE) ?
    ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
    ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ? ((int32_T)1) :
    ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
    ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ? ((int32_T)1) :
    ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
    ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE_SUSPEND) ? ((int32_T)
    1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
    ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_QUIT) ? ((int32_T)1) :
    ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
               ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_COMPLETE) ?
                ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
    ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_TERMINATED) ? ((int32_T)1) :
     ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
     ((int32_T)0))))) ? ((uint8_T)1) : ((uint8_T)0);
  rty_sPADispTx->ADCS8_TBA_text = LocalVar_ADCS8_TBA_text;
  rty_sPADispTx->ADCS8_RPA_CheckListDispReq8 = ((boolean_T)((int32_T)
    ((((boolean_T)((int32_T)((((boolean_T)((int32_T)
    ((rtu_sPaStateAdptr->sRPAChkList.bRPASurrAval ? ((int32_T)1) : ((int32_T)0))
     ^ 1))) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
    ((((boolean_T)((int32_T)(((rtu_sMasterLsadFsm->eLsadSystemSts ==
    LSAD_STS_INHIBIT) ? ((int32_T)1) : ((int32_T)0)) &
    ((rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkWakeup == SWT_ON) ? ((int32_T)1) :
     ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
    ((rtu_sVehCommon->sCondiVeh.bExterActualNorm ? ((int32_T)1) : ((int32_T)0)) ^
     1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0)) & (LocalVar_bParkBarPercentaDelay ? ((int32_T)
    1) : ((int32_T)0))))) ? ((uint8_T)1) : ((uint8_T)0);
  rty_sPADispTx->ADCS8_RPA_CheckListDispReq7 = ((boolean_T)((int32_T)
    ((LocalVar_bParkBarPercentaDelay ? ((int32_T)1) : ((int32_T)0)) &
     (((boolean_T)((int32_T)((((boolean_T)((int32_T)
    ((rtu_sPaStateAdptr->sRPAChkList.bRPASysNorm ? ((int32_T)1) : ((int32_T)0)) ^
     1))) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
    (((rtu_sMasterLsadFsm->eLsadSystemSts != LSAD_STS_FAILURE) ? ((int32_T)1) :
      ((int32_T)0)) | (((boolean_T)((int32_T)
    (((rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkWakeup == SWT_ON) ? ((int32_T)1) :
      ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) ? ((uint8_T)1) :
    ((uint8_T)0);
  rty_sPADispTx->ADCS8_RPA_CheckListDispReq6 = ((boolean_T)((int32_T)
    ((rtu_sPaStateAdptr->sRPAChkList.bRPASlopAval ? ((int32_T)1) : ((int32_T)0))
     ^ 1))) ? ((uint8_T)1) : ((uint8_T)0);
  rty_sPADispTx->ADCS8_RPA_CheckListDispReq5 = ((boolean_T)((int32_T)
    ((((boolean_T)((int32_T)((rtu_sPaStateAdptr->sRPAChkList.bRPATirePresNorm ?
    ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)) |
     (((boolean_T)((int32_T)((((boolean_T)((int32_T)
    (((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_INHIBIT) ? ((int32_T)1) :
      ((int32_T)0)) & ((rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkWakeup == SWT_ON) ?
                       ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) & (((boolean_T)((int32_T)
    ((rtu_sVehCommon->sCondiVeh.bTirePressNorm ? ((int32_T)1) : ((int32_T)0)) ^
     1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) ?
    ((uint8_T)1) : ((uint8_T)0);
  rty_sPADispTx->ADCS8_RPA_CheckListDispReq4 = ((boolean_T)((int32_T)
    ((rtu_sPaStateAdptr->sRPAChkList.bRPAEPBAval ? ((int32_T)1) : ((int32_T)0)) ^
     1))) ? ((uint8_T)1) : ((uint8_T)0);
  rty_sPADispTx->ADCS8_RPA_CheckListDispReq3 = ((boolean_T)((int32_T)
    ((rtu_sPaStateAdptr->sRPAChkList.bRPAGearAval ? ((int32_T)1) : ((int32_T)0))
     ^ 1))) ? ((uint8_T)1) : ((uint8_T)0);
  rty_sPADispTx->ADCS8_RPA_CheckListDispReq2 = ((boolean_T)((int32_T)
    ((rtu_sPaStateAdptr->sRPAChkList.bRPAVehStdstil ? ((int32_T)1) : ((int32_T)0))
     ^ 1))) ? ((uint8_T)1) : ((uint8_T)0);
  rty_sPADispTx->ADCS8_RPA_CheckListDispReq1 = ((boolean_T)((int32_T)
    ((((boolean_T)((int32_T)((((boolean_T)((int32_T)
    ((rtu_sPaStateAdptr->sRPAChkList.bRPADrClose ? ((int32_T)1) : ((int32_T)0)) ^
     1))) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
    ((rtu_sPaStateAdptr->sRPAChkList.bTrunkClose ? ((int32_T)1) : ((int32_T)0)) ^
     1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
     (((boolean_T)((int32_T)((rtu_sPaStateAdptr->sRPAChkList.bHoodClose ?
    ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ?
    ((uint8_T)1) : ((uint8_T)0);

  /* Switch: '<S31>/Switch1' incorporates:
   *  Constant: '<S29>/Constant'
   *  Constant: '<S30>/Constant'
   *  RelationalOperator: '<S1>/Equal'
   *  RelationalOperator: '<S1>/Equal1'
   *  Switch: '<S31>/Switch2'
   */
  if (rtu_sVehDataRx->sVehVCUInfo.eVehActualGear == D_GEAR)
  {
    /* BusAssignment: '<Root>/Bus Assignment2' */
    rty_sPADispTx->ADCS11_Currentgear = 1U;
  }
  else if (rtu_sVehDataRx->sVehVCUInfo.eVehActualGear == R_GEAR)
  {
    /* Switch: '<S31>/Switch2' incorporates:
     *  BusAssignment: '<Root>/Bus Assignment2'
     */
    rty_sPADispTx->ADCS11_Currentgear = 2U;
  }
  else
  {
    /* BusAssignment: '<Root>/Bus Assignment2' incorporates:
     *  Switch: '<S31>/Switch2'
     */
    rty_sPADispTx->ADCS11_Currentgear = 0U;
  }

  /* End of Switch: '<S31>/Switch1' */

  /* BusAssignment: '<Root>/Bus Assignment2' incorporates:
   *  Constant: '<S2>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion10'
   *  Product: '<S2>/Product'
   */
  rty_sPADispTx->ADCS4_PA_GuideLineE_a = rtu_sHMIComDisp->PAGuideLineA;
  rty_sPADispTx->ADCS4_PA_GuideLineE_b = rtu_sHMIComDisp->PAGuideLineB;
  rty_sPADispTx->ADCS4_PA_GuideLineE_c = rtu_sHMIComDisp->PAGuideLineC;
  rty_sPADispTx->ADCS4_PA_GuideLineE_d = rtu_sHMIComDisp->PAGuideLineD;
  rty_sPADispTx->ADCS4_PA_GuideLineE_Xmin = rtu_sHMIComDisp->PAGuideLineXMin;
  rty_sPADispTx->ADCS4_PA_GuideLineE_Xmax = rtu_sHMIComDisp->PAGuideLineXMax;
  rty_sPADispTx->ADCS11_NNS_distance = (uint16_T)((real_T)(((real_T)
    LocalVar_Saturation1) * 100.0));
  rty_sPADispTx->ADCS11_PA_StopDistance = LocalVar_Saturation1;
  rty_sPADispTx->ADCS11_APA_requestMirrorFoldSt = 0U;

  /* MATLAB Function: '<S28>/PrkInSlotDet' */
  /*  slot1 */
  if (((((rtu_sFusionDisp->sSlotGroup[0].SlotY0 < 0.0F) &&
         (rtu_sFusionDisp->sSlotGroup[0].SlotY1 < 0.0F)) &&
        (rtu_sFusionDisp->sSlotGroup[0].SlotY2 < 0.0F)) &&
       (rtu_sFusionDisp->sSlotGroup[0].SlotY3 < 0.0F)) || ((boolean_T)((int32_T)
        ((((boolean_T)((int32_T)(((rtu_sPaStateAdptr->sCondiHMI.ePODir ==
               PO_HEAD_DIR_LEFT) ? ((int32_T)1) : ((int32_T)0)) &
             ((rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_PARK_OUT) ?
              ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
         ((rtu_sPaStateAdptr->sCondiHMI.ePOSlotType == PO_SLOT_TYPE_PARALLEL) ?
          ((int32_T)1) : ((int32_T)0))))))
  {
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_1_P0_X = rtu_sFusionDisp->sSlotGroup[0].
      SlotX1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_1_P0_Y = rtu_sFusionDisp->sSlotGroup[0].
      SlotY1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_1_P1_X = rtu_sFusionDisp->sSlotGroup[0].
      SlotX0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_1_P1_Y = rtu_sFusionDisp->sSlotGroup[0].
      SlotY0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_1_P2_X = rtu_sFusionDisp->sSlotGroup[0].
      SlotX2;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_1_P2_Y = rtu_sFusionDisp->sSlotGroup[0].
      SlotY2;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_1_P3_X = rtu_sFusionDisp->sSlotGroup[0].
      SlotX3;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_1_P3_Y = rtu_sFusionDisp->sSlotGroup[0].
      SlotY3;
  }
  else
  {
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_1_P0_X = rtu_sFusionDisp->sSlotGroup[0].
      SlotX0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_1_P0_Y = rtu_sFusionDisp->sSlotGroup[0].
      SlotY0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_1_P1_X = rtu_sFusionDisp->sSlotGroup[0].
      SlotX1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_1_P1_Y = rtu_sFusionDisp->sSlotGroup[0].
      SlotY1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_1_P2_X = rtu_sFusionDisp->sSlotGroup[0].
      SlotX3;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_1_P2_Y = rtu_sFusionDisp->sSlotGroup[0].
      SlotY3;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_1_P3_X = rtu_sFusionDisp->sSlotGroup[0].
      SlotX2;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_1_P3_Y = rtu_sFusionDisp->sSlotGroup[0].
      SlotY2;
  }

  rty_sPrkInSlotTx->ADCS5_RPA_slot_Angle1 = 0.0F;
  rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDepth1 = fminf(fabsf
    (rtu_sFusionDisp->sSlotGroup[0].SlotY0 - rtu_sFusionDisp->sSlotGroup[0].
     SlotY3), fabsf(rtu_sFusionDisp->sSlotGroup[0].SlotY1 -
                    rtu_sFusionDisp->sSlotGroup[0].SlotY2));
  rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotWidth1 = fminf(fabsf
    (rtu_sFusionDisp->sSlotGroup[0].SlotX0 - rtu_sFusionDisp->sSlotGroup[0].
     SlotX1), fabsf(rtu_sFusionDisp->sSlotGroup[0].SlotX3 -
                    rtu_sFusionDisp->sSlotGroup[0].SlotX2));
  switch (rtu_sFusionDisp->sSlotGroup[0].eDispSlotStatus)
  {
   case SLOT_DISP_AVAILABLE:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_1_Status = 1U;

    /* 0x1：Available */
    break;

   case SLOT_DISP_UNAVAILABLE:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_1_Status = 2U;

    /* 0x2：unavailable */
    break;

   case SLOT_DISP_UNKNOWN:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_1_Status = 4U;

    /* 0x4：unknow     */
    break;

   case SLOT_DISP_SELECTED:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_1_Status = 3U;

    /* 0x3：Selected */
    break;

   default:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_1_Status = 0U;
    break;
  }

  switch (rtu_sFusionDisp->sSlotGroup[0].eDispSlotType)
  {
   case DISP_SLOT_TYP_PERPENDICULAR:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType1 = 1U;

    /*  0x1：Vertical */
    break;

   case DISP_SLOT_TYP_PARALLEL:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType1 = 2U;

    /* 0x2：Parallel */
    break;

   case DISP_SLOT_TYP_OBLIQUE:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType1 = 3U;

    /* 0x3：Oblique */
    break;

   default:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType1 = 0U;
    break;
  }

  if ((((rtu_sFusionDisp->sSlotGroup[0].SlotY0 < 0.0F) &&
        (rtu_sFusionDisp->sSlotGroup[0].SlotY1 < 0.0F)) &&
       (rtu_sFusionDisp->sSlotGroup[0].SlotY2 < 0.0F)) &&
      (rtu_sFusionDisp->sSlotGroup[0].SlotY3 < 0.0F))
  {
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection1 = 1U;

    /* 0x1：Left */
  }
  else if (rtu_sFusionDisp->sSlotGroup[0].SlotY0 > 0.0F)
  {
    if (rtu_sFusionDisp->sSlotGroup[0].SlotY1 > 0.0F)
    {
      if (rtu_sFusionDisp->sSlotGroup[0].SlotY2 > 0.0F)
      {
        if (rtu_sFusionDisp->sSlotGroup[0].SlotY3 > 0.0F)
        {
          rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection1 = 2U;

          /* 0x2：Right */
        }
        else
        {
          rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection1 = 0U;

          /*  */
        }
      }
      else
      {
        rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection1 = 0U;

        /*  */
      }
    }
    else
    {
      rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection1 = 0U;

      /*  */
    }
  }
  else
  {
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection1 = 0U;

    /*  */
  }

  /*  slot2 */
  if ((((rtu_sFusionDisp->sSlotGroup[1].SlotY0 < 0.0F) &&
        (rtu_sFusionDisp->sSlotGroup[1].SlotY1 < 0.0F)) &&
       (rtu_sFusionDisp->sSlotGroup[1].SlotY2 < 0.0F)) &&
      (rtu_sFusionDisp->sSlotGroup[1].SlotY3 < 0.0F))
  {
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_2_P0_X = rtu_sFusionDisp->sSlotGroup[1].
      SlotX1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_2_P0_Y = rtu_sFusionDisp->sSlotGroup[1].
      SlotY1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_2_P1_X = rtu_sFusionDisp->sSlotGroup[1].
      SlotX0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_2_P1_Y = rtu_sFusionDisp->sSlotGroup[1].
      SlotY0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_2_P2_X = rtu_sFusionDisp->sSlotGroup[1].
      SlotX2;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_2_P2_Y = rtu_sFusionDisp->sSlotGroup[1].
      SlotY2;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_2_P3_X = rtu_sFusionDisp->sSlotGroup[1].
      SlotX3;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_2_P3_Y = rtu_sFusionDisp->sSlotGroup[1].
      SlotY3;
  }
  else
  {
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_2_P0_X = rtu_sFusionDisp->sSlotGroup[1].
      SlotX0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_2_P0_Y = rtu_sFusionDisp->sSlotGroup[1].
      SlotY0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_2_P1_X = rtu_sFusionDisp->sSlotGroup[1].
      SlotX1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_2_P1_Y = rtu_sFusionDisp->sSlotGroup[1].
      SlotY1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_2_P2_X = rtu_sFusionDisp->sSlotGroup[1].
      SlotX3;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_2_P2_Y = rtu_sFusionDisp->sSlotGroup[1].
      SlotY3;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_2_P3_X = rtu_sFusionDisp->sSlotGroup[1].
      SlotX2;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_2_P3_Y = rtu_sFusionDisp->sSlotGroup[1].
      SlotY2;
  }

  rty_sPrkInSlotTx->ADCS5_RPA_slot_Angle2 = 0.0F;
  rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDepth2 = 0.0F;
  rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotWidth2 = fminf(fabsf
    (rtu_sFusionDisp->sSlotGroup[1].SlotX0 - rtu_sFusionDisp->sSlotGroup[1].
     SlotX1), fabsf(rtu_sFusionDisp->sSlotGroup[1].SlotX3 -
                    rtu_sFusionDisp->sSlotGroup[1].SlotX2));
  switch (rtu_sFusionDisp->sSlotGroup[1].eDispSlotStatus)
  {
   case SLOT_DISP_AVAILABLE:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_2_Status = 1U;

    /* 0x1：Available */
    break;

   case SLOT_DISP_UNAVAILABLE:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_2_Status = 2U;

    /* 0x2：unavailable */
    break;

   case SLOT_DISP_UNKNOWN:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_2_Status = 4U;

    /* 0x4：unknow     */
    break;

   case SLOT_DISP_SELECTED:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_2_Status = 3U;

    /* 0x3：Selected */
    break;

   default:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_2_Status = 0U;
    break;
  }

  switch (rtu_sFusionDisp->sSlotGroup[1].eDispSlotType)
  {
   case DISP_SLOT_TYP_PERPENDICULAR:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType2 = 1U;

    /*  0x1：Vertical */
    break;

   case DISP_SLOT_TYP_PARALLEL:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType2 = 2U;

    /* 0x2：Parallel */
    break;

   case DISP_SLOT_TYP_OBLIQUE:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType2 = 3U;

    /* 0x3：Oblique */
    break;

   default:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType2 = 0U;
    break;
  }

  if ((((rtu_sFusionDisp->sSlotGroup[1].SlotY0 < 0.0F) &&
        (rtu_sFusionDisp->sSlotGroup[1].SlotY1 < 0.0F)) &&
       (rtu_sFusionDisp->sSlotGroup[1].SlotY2 < 0.0F)) &&
      (rtu_sFusionDisp->sSlotGroup[1].SlotY3 < 0.0F))
  {
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection2 = 1U;

    /* 0x1：Left */
  }
  else if (rtu_sFusionDisp->sSlotGroup[1].SlotY0 > 0.0F)
  {
    if (rtu_sFusionDisp->sSlotGroup[1].SlotY2 > 0.0F)
    {
      if (rtu_sFusionDisp->sSlotGroup[1].SlotY3 > 0.0F)
      {
        rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection2 = 2U;

        /* 0x2：Right */
      }
      else
      {
        rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection2 = 0U;

        /*  */
      }
    }
    else
    {
      rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection2 = 0U;

      /*  */
    }
  }
  else
  {
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection2 = 0U;

    /*  */
  }

  /*  slot3 */
  if ((((rtu_sFusionDisp->sSlotGroup[2].SlotY0 < 0.0F) &&
        (rtu_sFusionDisp->sSlotGroup[2].SlotY1 < 0.0F)) &&
       (rtu_sFusionDisp->sSlotGroup[2].SlotY2 < 0.0F)) &&
      (rtu_sFusionDisp->sSlotGroup[2].SlotY3 < 0.0F))
  {
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_3_P0_X = rtu_sFusionDisp->sSlotGroup[2].
      SlotX1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_3_P0_Y = rtu_sFusionDisp->sSlotGroup[2].
      SlotY1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_3_P1_X = rtu_sFusionDisp->sSlotGroup[2].
      SlotX0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_3_P1_Y = rtu_sFusionDisp->sSlotGroup[2].
      SlotY0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_3_P2_X = rtu_sFusionDisp->sSlotGroup[2].
      SlotX2;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_3_P2_Y = rtu_sFusionDisp->sSlotGroup[2].
      SlotY2;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_3_P3_X = rtu_sFusionDisp->sSlotGroup[2].
      SlotX3;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_3_P3_Y = rtu_sFusionDisp->sSlotGroup[2].
      SlotY3;
  }
  else
  {
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_3_P0_X = rtu_sFusionDisp->sSlotGroup[2].
      SlotX0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_3_P0_Y = rtu_sFusionDisp->sSlotGroup[2].
      SlotY0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_3_P1_X = rtu_sFusionDisp->sSlotGroup[2].
      SlotX1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_3_P1_Y = rtu_sFusionDisp->sSlotGroup[2].
      SlotY1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_3_P2_X = rtu_sFusionDisp->sSlotGroup[2].
      SlotX3;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_3_P2_Y = rtu_sFusionDisp->sSlotGroup[2].
      SlotY3;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_3_P3_X = rtu_sFusionDisp->sSlotGroup[2].
      SlotX2;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_3_P3_Y = rtu_sFusionDisp->sSlotGroup[2].
      SlotY2;
  }

  rty_sPrkInSlotTx->ADCS5_RPA_slot_Angle3 = 0.0F;
  rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDepth3 = fminf(fabsf
    (rtu_sFusionDisp->sSlotGroup[2].SlotY0 - rtu_sFusionDisp->sSlotGroup[2].
     SlotY3), fabsf(rtu_sFusionDisp->sSlotGroup[2].SlotY1 -
                    rtu_sFusionDisp->sSlotGroup[2].SlotY2));
  rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotWidth3 = fminf(fabsf
    (rtu_sFusionDisp->sSlotGroup[2].SlotX0 - rtu_sFusionDisp->sSlotGroup[2].
     SlotX1), fabsf(rtu_sFusionDisp->sSlotGroup[2].SlotX3 -
                    rtu_sFusionDisp->sSlotGroup[2].SlotX2));
  switch (rtu_sFusionDisp->sSlotGroup[2].eDispSlotStatus)
  {
   case SLOT_DISP_AVAILABLE:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_3_Status = 1U;

    /* 0x1：Available */
    break;

   case SLOT_DISP_UNAVAILABLE:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_3_Status = 2U;

    /* 0x2：unavailable */
    break;

   case SLOT_DISP_UNKNOWN:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_3_Status = 4U;

    /* 0x4：unknow     */
    break;

   case SLOT_DISP_SELECTED:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_3_Status = 3U;

    /* 0x3：Selected */
    break;

   default:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_3_Status = 0U;
    break;
  }

  switch (rtu_sFusionDisp->sSlotGroup[2].eDispSlotType)
  {
   case DISP_SLOT_TYP_PERPENDICULAR:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType3 = 1U;

    /*  0x1：Vertical */
    break;

   case DISP_SLOT_TYP_PARALLEL:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType3 = 2U;

    /* 0x2：Parallel */
    break;

   case DISP_SLOT_TYP_OBLIQUE:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType3 = 3U;

    /* 0x3：Oblique */
    break;

   default:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType3 = 0U;
    break;
  }

  if ((((rtu_sFusionDisp->sSlotGroup[2].SlotY0 < 0.0F) &&
        (rtu_sFusionDisp->sSlotGroup[2].SlotY1 < 0.0F)) &&
       (rtu_sFusionDisp->sSlotGroup[2].SlotY2 < 0.0F)) &&
      (rtu_sFusionDisp->sSlotGroup[2].SlotY3 < 0.0F))
  {
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection3 = 1U;

    /* 0x1：Left */
  }
  else if (rtu_sFusionDisp->sSlotGroup[2].SlotY0 > 0.0F)
  {
    if (rtu_sFusionDisp->sSlotGroup[2].SlotY1 > 0.0F)
    {
      if (rtu_sFusionDisp->sSlotGroup[2].SlotY2 > 0.0F)
      {
        if (rtu_sFusionDisp->sSlotGroup[2].SlotY3 > 0.0F)
        {
          rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection3 = 2U;

          /* 0x2：Right */
        }
        else
        {
          rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection3 = 0U;

          /*  */
        }
      }
      else
      {
        rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection3 = 0U;

        /*  */
      }
    }
    else
    {
      rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection3 = 0U;

      /*  */
    }
  }
  else
  {
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection3 = 0U;

    /*  */
  }

  /*  slot4 */
  if ((((rtu_sFusionDisp->sSlotGroup[3].SlotY0 < 0.0F) &&
        (rtu_sFusionDisp->sSlotGroup[3].SlotY1 < 0.0F)) &&
       (rtu_sFusionDisp->sSlotGroup[3].SlotY2 < 0.0F)) &&
      (rtu_sFusionDisp->sSlotGroup[3].SlotY3 < 0.0F))
  {
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_4_P0_X = rtu_sFusionDisp->sSlotGroup[3].
      SlotX1;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_4_P0_Y = rtu_sFusionDisp->sSlotGroup[3].
      SlotY1;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_4_P1_X = rtu_sFusionDisp->sSlotGroup[3].
      SlotX0;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_4_P1_Y = rtu_sFusionDisp->sSlotGroup[3].
      SlotY0;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_4_P2_X = rtu_sFusionDisp->sSlotGroup[3].
      SlotX2;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_4_P2_Y = rtu_sFusionDisp->sSlotGroup[3].
      SlotY2;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_4_P3_X = rtu_sFusionDisp->sSlotGroup[3].
      SlotX3;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_4_P3_Y = rtu_sFusionDisp->sSlotGroup[3].
      SlotY3;
  }
  else
  {
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_4_P0_X = rtu_sFusionDisp->sSlotGroup[3].
      SlotX0;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_4_P0_Y = rtu_sFusionDisp->sSlotGroup[3].
      SlotY0;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_4_P1_X = rtu_sFusionDisp->sSlotGroup[3].
      SlotX1;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_4_P1_Y = rtu_sFusionDisp->sSlotGroup[3].
      SlotY1;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_4_P2_X = rtu_sFusionDisp->sSlotGroup[3].
      SlotX3;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_4_P2_Y = rtu_sFusionDisp->sSlotGroup[3].
      SlotY3;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_4_P3_X = rtu_sFusionDisp->sSlotGroup[3].
      SlotX2;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_4_P3_Y = rtu_sFusionDisp->sSlotGroup[3].
      SlotY2;
  }

  rty_sPrkInSlotTx->ADCS6_RPA_slot_Angle4 = 0.0F;
  rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotDepth4 = fminf(fabsf
    (rtu_sFusionDisp->sSlotGroup[3].SlotY0 - rtu_sFusionDisp->sSlotGroup[3].
     SlotY3), fabsf(rtu_sFusionDisp->sSlotGroup[3].SlotY1 -
                    rtu_sFusionDisp->sSlotGroup[3].SlotY2));
  rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotWidth4 = fminf(fabsf
    (rtu_sFusionDisp->sSlotGroup[3].SlotX0 - rtu_sFusionDisp->sSlotGroup[3].
     SlotX1), fabsf(rtu_sFusionDisp->sSlotGroup[3].SlotX3 -
                    rtu_sFusionDisp->sSlotGroup[3].SlotX2));
  switch (rtu_sFusionDisp->sSlotGroup[3].eDispSlotStatus)
  {
   case SLOT_DISP_AVAILABLE:
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_4_Status = 1U;

    /* 0x1：Available */
    break;

   case SLOT_DISP_UNAVAILABLE:
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_4_Status = 2U;

    /* 0x2：unavailable */
    break;

   case SLOT_DISP_UNKNOWN:
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_4_Status = 4U;

    /* 0x4：unknow     */
    break;

   case SLOT_DISP_SELECTED:
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_4_Status = 3U;

    /* 0x3：Selected */
    break;

   default:
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_4_Status = 0U;
    break;
  }

  switch (rtu_sFusionDisp->sSlotGroup[3].eDispSlotType)
  {
   case DISP_SLOT_TYP_PERPENDICULAR:
    rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotType4 = 1U;

    /*  0x1：Vertical */
    break;

   case DISP_SLOT_TYP_PARALLEL:
    rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotType4 = 2U;

    /* 0x2：Parallel */
    break;

   case DISP_SLOT_TYP_OBLIQUE:
    rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotType4 = 3U;

    /* 0x3：Oblique */
    break;

   default:
    rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotType4 = 0U;
    break;
  }

  if ((((rtu_sFusionDisp->sSlotGroup[3].SlotY0 < 0.0F) &&
        (rtu_sFusionDisp->sSlotGroup[3].SlotY1 < 0.0F)) &&
       (rtu_sFusionDisp->sSlotGroup[3].SlotY2 < 0.0F)) &&
      (rtu_sFusionDisp->sSlotGroup[3].SlotY3 < 0.0F))
  {
    rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotDirection4 = 1U;

    /* 0x1：Left */
  }
  else if (rtu_sFusionDisp->sSlotGroup[3].SlotY0 > 0.0F)
  {
    if (rtu_sFusionDisp->sSlotGroup[3].SlotY1 > 0.0F)
    {
      if (rtu_sFusionDisp->sSlotGroup[3].SlotY2 > 0.0F)
      {
        if (rtu_sFusionDisp->sSlotGroup[3].SlotY3 > 0.0F)
        {
          rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotDirection4 = 2U;

          /* 0x2：Right */
        }
        else
        {
          rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotDirection4 = 0U;

          /*  */
        }
      }
      else
      {
        rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotDirection4 = 0U;

        /*  */
      }
    }
    else
    {
      rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotDirection4 = 0U;

      /*  */
    }
  }
  else
  {
    rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotDirection4 = 0U;

    /*  */
  }

  /*  slot5 */
  if ((((rtu_sFusionDisp->sSlotGroup[4].SlotY0 < 0.0F) &&
        (rtu_sFusionDisp->sSlotGroup[4].SlotY1 < 0.0F)) &&
       (rtu_sFusionDisp->sSlotGroup[4].SlotY2 < 0.0F)) &&
      (rtu_sFusionDisp->sSlotGroup[4].SlotY3 < 0.0F))
  {
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_5_P0_X = rtu_sFusionDisp->sSlotGroup[4].
      SlotX1;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_5_P0_Y = rtu_sFusionDisp->sSlotGroup[4].
      SlotY1;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_5_P1_X = rtu_sFusionDisp->sSlotGroup[4].
      SlotX0;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_5_P1_Y = rtu_sFusionDisp->sSlotGroup[4].
      SlotY0;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_5_P2_X = rtu_sFusionDisp->sSlotGroup[4].
      SlotX2;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_5_P2_Y = rtu_sFusionDisp->sSlotGroup[4].
      SlotY2;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_5_P3_X = rtu_sFusionDisp->sSlotGroup[4].
      SlotX3;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_5_P3_Y = rtu_sFusionDisp->sSlotGroup[4].
      SlotY3;
  }
  else
  {
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_5_P0_X = rtu_sFusionDisp->sSlotGroup[4].
      SlotX0;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_5_P0_Y = rtu_sFusionDisp->sSlotGroup[4].
      SlotY0;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_5_P1_X = rtu_sFusionDisp->sSlotGroup[4].
      SlotX1;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_5_P1_Y = rtu_sFusionDisp->sSlotGroup[4].
      SlotY1;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_5_P2_X = rtu_sFusionDisp->sSlotGroup[4].
      SlotX3;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_5_P2_Y = rtu_sFusionDisp->sSlotGroup[4].
      SlotY3;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_5_P3_X = rtu_sFusionDisp->sSlotGroup[4].
      SlotX2;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_5_P3_Y = rtu_sFusionDisp->sSlotGroup[4].
      SlotY2;
  }

  rty_sPrkInSlotTx->ADCS6_RPA_slot_Angle5 = 0.0F;
  rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotDepth5 = fminf(fabsf
    (rtu_sFusionDisp->sSlotGroup[4].SlotY0 - rtu_sFusionDisp->sSlotGroup[4].
     SlotY3), fabsf(rtu_sFusionDisp->sSlotGroup[4].SlotY1 -
                    rtu_sFusionDisp->sSlotGroup[4].SlotY2));
  rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotWidth5 = fminf(fabsf
    (rtu_sFusionDisp->sSlotGroup[4].SlotX0 - rtu_sFusionDisp->sSlotGroup[4].
     SlotX1), fabsf(rtu_sFusionDisp->sSlotGroup[4].SlotX3 -
                    rtu_sFusionDisp->sSlotGroup[4].SlotX2));
  switch (rtu_sFusionDisp->sSlotGroup[4].eDispSlotStatus)
  {
   case SLOT_DISP_AVAILABLE:
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_5_Status = 1U;

    /* 0x1：Available */
    break;

   case SLOT_DISP_UNAVAILABLE:
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_5_Status = 2U;

    /* 0x2：unavailable */
    break;

   case SLOT_DISP_UNKNOWN:
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_5_Status = 4U;

    /* 0x4：unknow     */
    break;

   case SLOT_DISP_SELECTED:
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_5_Status = 3U;

    /* 0x3：Selected */
    break;

   default:
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_5_Status = 0U;
    break;
  }

  switch (rtu_sFusionDisp->sSlotGroup[4].eDispSlotType)
  {
   case DISP_SLOT_TYP_PERPENDICULAR:
    rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotType5 = 1U;

    /*  0x1：Vertical */
    break;

   case DISP_SLOT_TYP_PARALLEL:
    rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotType5 = 2U;

    /* 0x2：Parallel */
    break;

   case DISP_SLOT_TYP_OBLIQUE:
    rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotType5 = 3U;

    /* 0x3：Oblique */
    break;

   default:
    rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotType5 = 0U;
    break;
  }

  if ((((rtu_sFusionDisp->sSlotGroup[4].SlotY0 < 0.0F) &&
        (rtu_sFusionDisp->sSlotGroup[4].SlotY1 < 0.0F)) &&
       (rtu_sFusionDisp->sSlotGroup[4].SlotY2 < 0.0F)) &&
      (rtu_sFusionDisp->sSlotGroup[4].SlotY3 < 0.0F))
  {
    rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotDirection5 = 1U;

    /* 0x1：Left */
  }
  else if (rtu_sFusionDisp->sSlotGroup[4].SlotY0 > 0.0F)
  {
    if (rtu_sFusionDisp->sSlotGroup[4].SlotY1 > 0.0F)
    {
      if (rtu_sFusionDisp->sSlotGroup[4].SlotY2 > 0.0F)
      {
        if (rtu_sFusionDisp->sSlotGroup[4].SlotY3 > 0.0F)
        {
          rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotDirection5 = 2U;

          /* 0x2：Right */
        }
        else
        {
          rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotDirection5 = 0U;

          /*  */
        }
      }
      else
      {
        rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotDirection5 = 0U;

        /*  */
      }
    }
    else
    {
      rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotDirection5 = 0U;

      /*  */
    }
  }
  else
  {
    rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotDirection5 = 0U;

    /*  */
  }

  /*  slot6 */
  if ((((rtu_sFusionDisp->sSlotGroup[5].SlotY0 < 0.0F) &&
        (rtu_sFusionDisp->sSlotGroup[5].SlotY1 < 0.0F)) &&
       (rtu_sFusionDisp->sSlotGroup[5].SlotY2 < 0.0F)) &&
      (rtu_sFusionDisp->sSlotGroup[5].SlotY3 < 0.0F))
  {
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_6_P0_X = rtu_sFusionDisp->sSlotGroup[5].
      SlotX1;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_6_P0_Y = rtu_sFusionDisp->sSlotGroup[5].
      SlotY1;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_6_P1_X = rtu_sFusionDisp->sSlotGroup[5].
      SlotX0;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_6_P1_Y = rtu_sFusionDisp->sSlotGroup[5].
      SlotY0;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_6_P2_X = rtu_sFusionDisp->sSlotGroup[5].
      SlotX2;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_6_P2_Y = rtu_sFusionDisp->sSlotGroup[5].
      SlotY2;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_6_P3_X = rtu_sFusionDisp->sSlotGroup[5].
      SlotX3;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_6_P3_Y = rtu_sFusionDisp->sSlotGroup[5].
      SlotY3;
  }
  else
  {
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_6_P0_X = rtu_sFusionDisp->sSlotGroup[5].
      SlotX0;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_6_P0_Y = rtu_sFusionDisp->sSlotGroup[5].
      SlotY0;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_6_P1_X = rtu_sFusionDisp->sSlotGroup[5].
      SlotX1;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_6_P1_Y = rtu_sFusionDisp->sSlotGroup[5].
      SlotY1;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_6_P2_X = rtu_sFusionDisp->sSlotGroup[5].
      SlotX3;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_6_P2_Y = rtu_sFusionDisp->sSlotGroup[5].
      SlotY3;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_6_P3_X = rtu_sFusionDisp->sSlotGroup[5].
      SlotX2;
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_6_P3_Y = rtu_sFusionDisp->sSlotGroup[5].
      SlotY2;
  }

  rty_sPrkInSlotTx->ADCS6_RPA_slot_Angle6 = 0.0F;
  rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotDepth6 = fminf(fabsf
    (rtu_sFusionDisp->sSlotGroup[5].SlotY0 - rtu_sFusionDisp->sSlotGroup[5].
     SlotY3), fabsf(rtu_sFusionDisp->sSlotGroup[5].SlotY1 -
                    rtu_sFusionDisp->sSlotGroup[5].SlotY2));
  rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotWidth6 = fminf(fabsf
    (rtu_sFusionDisp->sSlotGroup[5].SlotX0 - rtu_sFusionDisp->sSlotGroup[5].
     SlotX1), fabsf(rtu_sFusionDisp->sSlotGroup[5].SlotX3 -
                    rtu_sFusionDisp->sSlotGroup[5].SlotX2));
  switch (rtu_sFusionDisp->sSlotGroup[5].eDispSlotStatus)
  {
   case SLOT_DISP_AVAILABLE:
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_6_Status = 1U;

    /* 0x1：Available */
    break;

   case SLOT_DISP_UNAVAILABLE:
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_6_Status = 2U;

    /* 0x2：unavailable */
    break;

   case SLOT_DISP_UNKNOWN:
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_6_Status = 4U;

    /* 0x4：unknow     */
    break;

   case SLOT_DISP_SELECTED:
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_6_Status = 3U;

    /* 0x3：Selected */
    break;

   default:
    rty_sPrkInSlotTx->ADCS6_RPA_slot_ID_6_Status = 0U;
    break;
  }

  switch (rtu_sFusionDisp->sSlotGroup[5].eDispSlotType)
  {
   case DISP_SLOT_TYP_PERPENDICULAR:
    rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotType6 = 1U;

    /*  0x1：Vertical */
    break;

   case DISP_SLOT_TYP_PARALLEL:
    rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotType6 = 2U;

    /* 0x2：Parallel */
    break;

   case DISP_SLOT_TYP_OBLIQUE:
    rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotType6 = 3U;

    /* 0x3：Oblique */
    break;

   default:
    rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotType6 = 0U;
    break;
  }

  if ((((rtu_sFusionDisp->sSlotGroup[5].SlotY0 < 0.0F) &&
        (rtu_sFusionDisp->sSlotGroup[5].SlotY1 < 0.0F)) &&
       (rtu_sFusionDisp->sSlotGroup[5].SlotY2 < 0.0F)) &&
      (rtu_sFusionDisp->sSlotGroup[5].SlotY3 < 0.0F))
  {
    rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotDirection6 = 1U;

    /* 0x1：Left */
  }
  else if (rtu_sFusionDisp->sSlotGroup[5].SlotY0 > 0.0F)
  {
    if (rtu_sFusionDisp->sSlotGroup[5].SlotY1 > 0.0F)
    {
      if (rtu_sFusionDisp->sSlotGroup[5].SlotY2 > 0.0F)
      {
        if (rtu_sFusionDisp->sSlotGroup[5].SlotY3 > 0.0F)
        {
          rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotDirection6 = 2U;

          /* 0x2：Right */
        }
        else
        {
          rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotDirection6 = 0U;

          /*  */
        }
      }
      else
      {
        rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotDirection6 = 0U;

        /*  */
      }
    }
    else
    {
      rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotDirection6 = 0U;

      /*  */
    }
  }
  else
  {
    rty_sPrkInSlotTx->ADCS6_RPA_ParkingSlotDirection6 = 0U;

    /*  */
  }

  /*  slot7 */
  if ((((rtu_sFusionDisp->sSlotGroup[6].SlotY0 < 0.0F) &&
        (rtu_sFusionDisp->sSlotGroup[6].SlotY1 < 0.0F)) &&
       (rtu_sFusionDisp->sSlotGroup[6].SlotY2 < 0.0F)) &&
      (rtu_sFusionDisp->sSlotGroup[6].SlotY3 < 0.0F))
  {
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_7_P0_X = rtu_sFusionDisp->sSlotGroup[6].
      SlotX1;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_7_P0_Y = rtu_sFusionDisp->sSlotGroup[6].
      SlotY1;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_7_P1_X = rtu_sFusionDisp->sSlotGroup[6].
      SlotX0;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_7_P1_Y = rtu_sFusionDisp->sSlotGroup[6].
      SlotY0;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_7_P2_X = rtu_sFusionDisp->sSlotGroup[6].
      SlotX2;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_7_P2_Y = rtu_sFusionDisp->sSlotGroup[6].
      SlotY2;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_7_P3_X = rtu_sFusionDisp->sSlotGroup[6].
      SlotX3;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_7_P3_Y = rtu_sFusionDisp->sSlotGroup[6].
      SlotY3;
  }
  else
  {
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_7_P0_X = rtu_sFusionDisp->sSlotGroup[6].
      SlotX0;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_7_P0_Y = rtu_sFusionDisp->sSlotGroup[6].
      SlotY0;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_7_P1_X = rtu_sFusionDisp->sSlotGroup[6].
      SlotX1;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_7_P1_Y = rtu_sFusionDisp->sSlotGroup[6].
      SlotY1;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_7_P2_X = rtu_sFusionDisp->sSlotGroup[6].
      SlotX3;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_7_P2_Y = rtu_sFusionDisp->sSlotGroup[6].
      SlotY3;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_7_P3_X = rtu_sFusionDisp->sSlotGroup[6].
      SlotX2;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_7_P3_Y = rtu_sFusionDisp->sSlotGroup[6].
      SlotY2;
  }

  rty_sPrkInSlotTx->ADCS7_RPA_slot_Angle7 = 0.0F;
  rty_sPrkInSlotTx->ADCS7_RPA_ParkingSlotDepth7 = fminf(fabsf
    (rtu_sFusionDisp->sSlotGroup[6].SlotY0 - rtu_sFusionDisp->sSlotGroup[6].
     SlotY3), fabsf(rtu_sFusionDisp->sSlotGroup[6].SlotY1 -
                    rtu_sFusionDisp->sSlotGroup[6].SlotY2));
  rty_sPrkInSlotTx->ADCS7_RPA_ParkingSlotWidth7 = fminf(fabsf
    (rtu_sFusionDisp->sSlotGroup[6].SlotX0 - rtu_sFusionDisp->sSlotGroup[6].
     SlotX1), fabsf(rtu_sFusionDisp->sSlotGroup[6].SlotX3 -
                    rtu_sFusionDisp->sSlotGroup[6].SlotX2));
  switch (rtu_sFusionDisp->sSlotGroup[6].eDispSlotStatus)
  {
   case SLOT_DISP_AVAILABLE:
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_7_Status = 1U;

    /* 0x1：Available */
    break;

   case SLOT_DISP_UNAVAILABLE:
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_7_Status = 2U;

    /* 0x2：unavailable */
    break;

   case SLOT_DISP_UNKNOWN:
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_7_Status = 4U;

    /* 0x4：unknow     */
    break;

   case SLOT_DISP_SELECTED:
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_7_Status = 3U;

    /* 0x3：Selected */
    break;

   default:
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_7_Status = 0U;
    break;
  }

  switch (rtu_sFusionDisp->sSlotGroup[6].eDispSlotType)
  {
   case DISP_SLOT_TYP_PERPENDICULAR:
    rty_sPrkInSlotTx->ADCS7_RPA_ParkingSlotType7 = 1U;

    /*  0x1：Vertical */
    break;

   case DISP_SLOT_TYP_PARALLEL:
    rty_sPrkInSlotTx->ADCS7_RPA_ParkingSlotType7 = 2U;

    /* 0x2：Parallel */
    break;

   case DISP_SLOT_TYP_OBLIQUE:
    rty_sPrkInSlotTx->ADCS7_RPA_ParkingSlotType7 = 3U;

    /* 0x3：Oblique */
    break;

   default:
    rty_sPrkInSlotTx->ADCS7_RPA_ParkingSlotType7 = 0U;
    break;
  }

  if ((((rtu_sFusionDisp->sSlotGroup[6].SlotY0 < 0.0F) &&
        (rtu_sFusionDisp->sSlotGroup[6].SlotY1 < 0.0F)) &&
       (rtu_sFusionDisp->sSlotGroup[6].SlotY2 < 0.0F)) &&
      (rtu_sFusionDisp->sSlotGroup[6].SlotY3 < 0.0F))
  {
    rty_sPrkInSlotTx->ADCS7_RPA_ParkingSlotDirection7 = 1U;

    /* 0x1：Left */
  }
  else if (rtu_sFusionDisp->sSlotGroup[6].SlotY0 > 0.0F)
  {
    if (rtu_sFusionDisp->sSlotGroup[6].SlotY1 > 0.0F)
    {
      if (rtu_sFusionDisp->sSlotGroup[6].SlotY2 > 0.0F)
      {
        if (rtu_sFusionDisp->sSlotGroup[6].SlotY3 > 0.0F)
        {
          rty_sPrkInSlotTx->ADCS7_RPA_ParkingSlotDirection7 = 2U;

          /* 0x2：Right */
        }
        else
        {
          rty_sPrkInSlotTx->ADCS7_RPA_ParkingSlotDirection7 = 0U;

          /*  */
        }
      }
      else
      {
        rty_sPrkInSlotTx->ADCS7_RPA_ParkingSlotDirection7 = 0U;

        /*  */
      }
    }
    else
    {
      rty_sPrkInSlotTx->ADCS7_RPA_ParkingSlotDirection7 = 0U;

      /*  */
    }
  }
  else
  {
    rty_sPrkInSlotTx->ADCS7_RPA_ParkingSlotDirection7 = 0U;

    /*  */
  }

  /*  slot8 */
  if ((((rtu_sFusionDisp->sSlotGroup[7].SlotY0 < 0.0F) &&
        (rtu_sFusionDisp->sSlotGroup[7].SlotY1 < 0.0F)) &&
       (rtu_sFusionDisp->sSlotGroup[7].SlotY2 < 0.0F)) &&
      (rtu_sFusionDisp->sSlotGroup[7].SlotY3 < 0.0F))
  {
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_8_P0_X = rtu_sFusionDisp->sSlotGroup[7].
      SlotX1;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_8_P0_Y = rtu_sFusionDisp->sSlotGroup[7].
      SlotY1;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_8_P1_X = rtu_sFusionDisp->sSlotGroup[7].
      SlotX0;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_8_P1_Y = rtu_sFusionDisp->sSlotGroup[7].
      SlotY0;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_8_P2_X = rtu_sFusionDisp->sSlotGroup[7].
      SlotX2;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_8_P2_Y = rtu_sFusionDisp->sSlotGroup[7].
      SlotY2;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_8_P3_X = rtu_sFusionDisp->sSlotGroup[7].
      SlotX3;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_8_P3_Y = rtu_sFusionDisp->sSlotGroup[7].
      SlotY3;
  }
  else
  {
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_8_P0_X = rtu_sFusionDisp->sSlotGroup[7].
      SlotX0;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_8_P0_Y = rtu_sFusionDisp->sSlotGroup[7].
      SlotY0;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_8_P1_X = rtu_sFusionDisp->sSlotGroup[7].
      SlotX1;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_8_P1_Y = rtu_sFusionDisp->sSlotGroup[7].
      SlotY1;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_8_P2_X = rtu_sFusionDisp->sSlotGroup[7].
      SlotX3;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_8_P2_Y = rtu_sFusionDisp->sSlotGroup[7].
      SlotY3;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_8_P3_X = rtu_sFusionDisp->sSlotGroup[7].
      SlotX2;
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_8_P3_Y = rtu_sFusionDisp->sSlotGroup[7].
      SlotY2;
  }

  rty_sPrkInSlotTx->ADCS7_RPA_slot_Angle8 = 0.0F;
  rty_sPrkInSlotTx->ADCS7_RPA_ParkingSlotDepth8 = fminf(fabsf
    (rtu_sFusionDisp->sSlotGroup[7].SlotY0 - rtu_sFusionDisp->sSlotGroup[7].
     SlotY3), fabsf(rtu_sFusionDisp->sSlotGroup[7].SlotY1 -
                    rtu_sFusionDisp->sSlotGroup[7].SlotY2));
  rty_sPrkInSlotTx->ADCS7_RPA_ParkingSlotWidth8 = fminf(fabsf
    (rtu_sFusionDisp->sSlotGroup[7].SlotX0 - rtu_sFusionDisp->sSlotGroup[7].
     SlotX1), fabsf(rtu_sFusionDisp->sSlotGroup[7].SlotX3 -
                    rtu_sFusionDisp->sSlotGroup[7].SlotX2));
  switch (rtu_sFusionDisp->sSlotGroup[7].eDispSlotStatus)
  {
   case SLOT_DISP_AVAILABLE:
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_8_Status = 1U;

    /* 0x1：Available */
    break;

   case SLOT_DISP_UNAVAILABLE:
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_8_Status = 2U;

    /* 0x2：unavailable */
    break;

   case SLOT_DISP_UNKNOWN:
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_8_Status = 4U;

    /* 0x4：unknow     */
    break;

   case SLOT_DISP_SELECTED:
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_8_Status = 3U;

    /* 0x3：Selected */
    break;

   default:
    rty_sPrkInSlotTx->ADCS7_RPA_slot_ID_8_Status = 0U;
    break;
  }

  switch (rtu_sFusionDisp->sSlotGroup[7].eDispSlotType)
  {
   case DISP_SLOT_TYP_PERPENDICULAR:
    rty_sPrkInSlotTx->ADCS7_RPA_ParkingSlotType8 = 1U;

    /*  0x1：Vertical */
    break;

   case DISP_SLOT_TYP_PARALLEL:
    rty_sPrkInSlotTx->ADCS7_RPA_ParkingSlotType8 = 2U;

    /* 0x2：Parallel */
    break;

   case DISP_SLOT_TYP_OBLIQUE:
    rty_sPrkInSlotTx->ADCS7_RPA_ParkingSlotType8 = 3U;

    /* 0x3：Oblique */
    break;

   default:
    rty_sPrkInSlotTx->ADCS7_RPA_ParkingSlotType8 = 0U;
    break;
  }

  if ((((rtu_sFusionDisp->sSlotGroup[7].SlotY0 < 0.0F) &&
        (rtu_sFusionDisp->sSlotGroup[7].SlotY1 < 0.0F)) &&
       (rtu_sFusionDisp->sSlotGroup[7].SlotY2 < 0.0F)) &&
      (rtu_sFusionDisp->sSlotGroup[7].SlotY3 < 0.0F))
  {
    rty_sPrkInSlotTx->ADCS7_RPA_ParkingSlotDirection8 = 1U;

    /* 0x1：Left */
  }
  else if (rtu_sFusionDisp->sSlotGroup[7].SlotY0 > 0.0F)
  {
    if (rtu_sFusionDisp->sSlotGroup[7].SlotY1 > 0.0F)
    {
      if (rtu_sFusionDisp->sSlotGroup[7].SlotY2 > 0.0F)
      {
        if (rtu_sFusionDisp->sSlotGroup[7].SlotY3 > 0.0F)
        {
          rty_sPrkInSlotTx->ADCS7_RPA_ParkingSlotDirection8 = 2U;

          /* 0x2：Right */
        }
        else
        {
          rty_sPrkInSlotTx->ADCS7_RPA_ParkingSlotDirection8 = 0U;

          /*  */
        }
      }
      else
      {
        rty_sPrkInSlotTx->ADCS7_RPA_ParkingSlotDirection8 = 0U;

        /*  */
      }
    }
    else
    {
      rty_sPrkInSlotTx->ADCS7_RPA_ParkingSlotDirection8 = 0U;

      /*  */
    }
  }
  else
  {
    rty_sPrkInSlotTx->ADCS7_RPA_ParkingSlotDirection8 = 0U;

    /*  */
  }

  /*  slot9 */
  if ((((rtu_sFusionDisp->sSlotGroup[8].SlotY0 < 0.0F) &&
        (rtu_sFusionDisp->sSlotGroup[8].SlotY1 < 0.0F)) &&
       (rtu_sFusionDisp->sSlotGroup[8].SlotY2 < 0.0F)) &&
      (rtu_sFusionDisp->sSlotGroup[8].SlotY3 < 0.0F))
  {
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_9_P0_X = rtu_sFusionDisp->sSlotGroup[8].
      SlotX1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_9_P0_Y = rtu_sFusionDisp->sSlotGroup[8].
      SlotY1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_9_P1_X = rtu_sFusionDisp->sSlotGroup[8].
      SlotX0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_9_P1_Y = rtu_sFusionDisp->sSlotGroup[8].
      SlotY0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_9_P2_X = rtu_sFusionDisp->sSlotGroup[8].
      SlotX2;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_9_P2_Y = rtu_sFusionDisp->sSlotGroup[8].
      SlotY2;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_9_P3_X = rtu_sFusionDisp->sSlotGroup[8].
      SlotX3;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_9_P3_Y = rtu_sFusionDisp->sSlotGroup[8].
      SlotY3;
  }
  else
  {
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_9_P0_X = rtu_sFusionDisp->sSlotGroup[8].
      SlotX0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_9_P0_Y = rtu_sFusionDisp->sSlotGroup[8].
      SlotY0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_9_P1_X = rtu_sFusionDisp->sSlotGroup[8].
      SlotX1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_9_P1_Y = rtu_sFusionDisp->sSlotGroup[8].
      SlotY1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_9_P2_X = rtu_sFusionDisp->sSlotGroup[8].
      SlotX3;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_9_P2_Y = rtu_sFusionDisp->sSlotGroup[8].
      SlotY3;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_9_P3_X = rtu_sFusionDisp->sSlotGroup[8].
      SlotX2;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_9_P3_Y = rtu_sFusionDisp->sSlotGroup[8].
      SlotY2;
  }

  rty_sPrkInSlotTx->ADCS5_RPA_slot_Angle9 = 0.0F;
  rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDepth9 = fminf(fabsf
    (rtu_sFusionDisp->sSlotGroup[8].SlotY0 - rtu_sFusionDisp->sSlotGroup[8].
     SlotY3), fabsf(rtu_sFusionDisp->sSlotGroup[8].SlotY1 -
                    rtu_sFusionDisp->sSlotGroup[8].SlotY2));
  rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotWidth9 = fminf(fabsf
    (rtu_sFusionDisp->sSlotGroup[8].SlotX0 - rtu_sFusionDisp->sSlotGroup[8].
     SlotX1), fabsf(rtu_sFusionDisp->sSlotGroup[8].SlotX3 -
                    rtu_sFusionDisp->sSlotGroup[8].SlotX2));
  switch (rtu_sFusionDisp->sSlotGroup[8].eDispSlotStatus)
  {
   case SLOT_DISP_AVAILABLE:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_9_Status = 1U;

    /* 0x1：Available */
    break;

   case SLOT_DISP_UNAVAILABLE:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_9_Status = 2U;

    /* 0x2：unavailable */
    break;

   case SLOT_DISP_UNKNOWN:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_9_Status = 4U;

    /* 0x4：unknow     */
    break;

   case SLOT_DISP_SELECTED:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_9_Status = 3U;

    /* 0x3：Selected */
    break;

   default:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_9_Status = 0U;
    break;
  }

  switch (rtu_sFusionDisp->sSlotGroup[8].eDispSlotType)
  {
   case DISP_SLOT_TYP_PERPENDICULAR:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType9 = 1U;

    /*  0x1：Vertical */
    break;

   case DISP_SLOT_TYP_PARALLEL:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType9 = 2U;

    /* 0x2：Parallel */
    break;

   case DISP_SLOT_TYP_OBLIQUE:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType9 = 3U;

    /* 0x3：Oblique */
    break;

   default:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType9 = 0U;
    break;
  }

  if ((((rtu_sFusionDisp->sSlotGroup[8].SlotY0 < 0.0F) &&
        (rtu_sFusionDisp->sSlotGroup[8].SlotY1 < 0.0F)) &&
       (rtu_sFusionDisp->sSlotGroup[8].SlotY2 < 0.0F)) &&
      (rtu_sFusionDisp->sSlotGroup[8].SlotY3 < 0.0F))
  {
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection9 = 1U;

    /* 0x1：Left */
  }
  else if (rtu_sFusionDisp->sSlotGroup[8].SlotY0 > 0.0F)
  {
    if (rtu_sFusionDisp->sSlotGroup[8].SlotY1 > 0.0F)
    {
      if (rtu_sFusionDisp->sSlotGroup[8].SlotY2 > 0.0F)
      {
        if (rtu_sFusionDisp->sSlotGroup[8].SlotY3 > 0.0F)
        {
          rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection9 = 2U;

          /* 0x2：Right */
        }
        else
        {
          rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection9 = 0U;

          /*  */
        }
      }
      else
      {
        rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection9 = 0U;

        /*  */
      }
    }
    else
    {
      rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection9 = 0U;

      /*  */
    }
  }
  else
  {
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection9 = 0U;

    /*  */
  }

  /*  slot10 */
  if ((((rtu_sFusionDisp->sSlotGroup[9].SlotY0 < 0.0F) &&
        (rtu_sFusionDisp->sSlotGroup[9].SlotY1 < 0.0F)) &&
       (rtu_sFusionDisp->sSlotGroup[9].SlotY2 < 0.0F)) &&
      (rtu_sFusionDisp->sSlotGroup[9].SlotY3 < 0.0F))
  {
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_10_P0_X = rtu_sFusionDisp->sSlotGroup[9]
      .SlotX1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_10_P0_Y = rtu_sFusionDisp->sSlotGroup[9]
      .SlotY1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_10_P1_X = rtu_sFusionDisp->sSlotGroup[9]
      .SlotX0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_10_P1_Y = rtu_sFusionDisp->sSlotGroup[9]
      .SlotY0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_10_P2_X = rtu_sFusionDisp->sSlotGroup[9]
      .SlotX2;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_10_P2_Y = rtu_sFusionDisp->sSlotGroup[9]
      .SlotY2;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_10_P3_X = rtu_sFusionDisp->sSlotGroup[9]
      .SlotX3;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_10_P3_Y = rtu_sFusionDisp->sSlotGroup[9]
      .SlotY3;
  }
  else
  {
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_10_P0_X = rtu_sFusionDisp->sSlotGroup[9]
      .SlotX0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_10_P0_Y = rtu_sFusionDisp->sSlotGroup[9]
      .SlotY0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_10_P1_X = rtu_sFusionDisp->sSlotGroup[9]
      .SlotX1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_10_P1_Y = rtu_sFusionDisp->sSlotGroup[9]
      .SlotY1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_10_P2_X = rtu_sFusionDisp->sSlotGroup[9]
      .SlotX3;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_10_P2_Y = rtu_sFusionDisp->sSlotGroup[9]
      .SlotY3;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_10_P3_X = rtu_sFusionDisp->sSlotGroup[9]
      .SlotX2;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_10_P3_Y = rtu_sFusionDisp->sSlotGroup[9]
      .SlotY2;
  }

  rty_sPrkInSlotTx->ADCS5_RPA_slot_Angle10 = 0.0F;
  rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDepth10 = fminf(fabsf
    (rtu_sFusionDisp->sSlotGroup[9].SlotY0 - rtu_sFusionDisp->sSlotGroup[9].
     SlotY3), fabsf(rtu_sFusionDisp->sSlotGroup[9].SlotY1 -
                    rtu_sFusionDisp->sSlotGroup[9].SlotY2));
  rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotWidth10 = fminf(fabsf
    (rtu_sFusionDisp->sSlotGroup[9].SlotX0 - rtu_sFusionDisp->sSlotGroup[9].
     SlotX1), fabsf(rtu_sFusionDisp->sSlotGroup[9].SlotX3 -
                    rtu_sFusionDisp->sSlotGroup[9].SlotX2));
  switch (rtu_sFusionDisp->sSlotGroup[9].eDispSlotStatus)
  {
   case SLOT_DISP_AVAILABLE:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_10_Status = 1U;

    /* 0x1：Available */
    break;

   case SLOT_DISP_UNAVAILABLE:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_10_Status = 2U;

    /* 0x2：unavailable */
    break;

   case SLOT_DISP_UNKNOWN:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_10_Status = 4U;

    /* 0x4：unknow     */
    break;

   case SLOT_DISP_SELECTED:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_10_Status = 3U;

    /* 0x3：Selected */
    break;

   default:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_10_Status = 0U;
    break;
  }

  switch (rtu_sFusionDisp->sSlotGroup[9].eDispSlotType)
  {
   case DISP_SLOT_TYP_PERPENDICULAR:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType10 = 1U;

    /*  0x1：Vertical */
    break;

   case DISP_SLOT_TYP_PARALLEL:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType10 = 2U;

    /* 0x2：Parallel */
    break;

   case DISP_SLOT_TYP_OBLIQUE:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType10 = 3U;

    /* 0x3：Oblique */
    break;

   default:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType10 = 0U;
    break;
  }

  if ((((rtu_sFusionDisp->sSlotGroup[9].SlotY0 < 0.0F) &&
        (rtu_sFusionDisp->sSlotGroup[9].SlotY1 < 0.0F)) &&
       (rtu_sFusionDisp->sSlotGroup[9].SlotY2 < 0.0F)) &&
      (rtu_sFusionDisp->sSlotGroup[9].SlotY3 < 0.0F))
  {
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection10 = 1U;

    /* 0x1：Left */
  }
  else if (rtu_sFusionDisp->sSlotGroup[9].SlotY0 > 0.0F)
  {
    if (rtu_sFusionDisp->sSlotGroup[9].SlotY1 > 0.0F)
    {
      if (rtu_sFusionDisp->sSlotGroup[9].SlotY2 > 0.0F)
      {
        if (rtu_sFusionDisp->sSlotGroup[9].SlotY3 > 0.0F)
        {
          rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection10 = 2U;

          /* 0x2：Right */
        }
        else
        {
          rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection10 = 0U;

          /*  */
        }
      }
      else
      {
        rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection10 = 0U;

        /*  */
      }
    }
    else
    {
      rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection10 = 0U;

      /*  */
    }
  }
  else
  {
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection10 = 0U;

    /*  */
  }

  /*  slot11 */
  if ((((rtu_sFusionDisp->sSlotGroup[10].SlotY0 < 0.0F) &&
        (rtu_sFusionDisp->sSlotGroup[10].SlotY1 < 0.0F)) &&
       (rtu_sFusionDisp->sSlotGroup[10].SlotY2 < 0.0F)) &&
      (rtu_sFusionDisp->sSlotGroup[10].SlotY3 < 0.0F))
  {
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_11_P0_X = rtu_sFusionDisp->sSlotGroup[10]
      .SlotX1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_11_P0_Y = rtu_sFusionDisp->sSlotGroup[10]
      .SlotY1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_11_P1_X = rtu_sFusionDisp->sSlotGroup[10]
      .SlotX0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_11_P1_Y = rtu_sFusionDisp->sSlotGroup[10]
      .SlotY0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_11_P2_X = rtu_sFusionDisp->sSlotGroup[10]
      .SlotX2;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_11_P2_Y = rtu_sFusionDisp->sSlotGroup[10]
      .SlotY2;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_11_P3_X = rtu_sFusionDisp->sSlotGroup[10]
      .SlotX3;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_11_P3_Y = rtu_sFusionDisp->sSlotGroup[10]
      .SlotY3;
  }
  else
  {
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_11_P0_X = rtu_sFusionDisp->sSlotGroup[10]
      .SlotX0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_11_P0_Y = rtu_sFusionDisp->sSlotGroup[10]
      .SlotY0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_11_P1_X = rtu_sFusionDisp->sSlotGroup[10]
      .SlotX1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_11_P1_Y = rtu_sFusionDisp->sSlotGroup[10]
      .SlotY1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_11_P2_X = rtu_sFusionDisp->sSlotGroup[10]
      .SlotX3;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_11_P2_Y = rtu_sFusionDisp->sSlotGroup[10]
      .SlotY3;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_11_P3_X = rtu_sFusionDisp->sSlotGroup[10]
      .SlotX2;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_11_P3_Y = rtu_sFusionDisp->sSlotGroup[10]
      .SlotY2;
  }

  rty_sPrkInSlotTx->ADCS5_RPA_slot_Angle11 = 0.0F;
  rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDepth11 = fminf(fabsf
    (rtu_sFusionDisp->sSlotGroup[10].SlotY0 - rtu_sFusionDisp->sSlotGroup[10].
     SlotY3), fabsf(rtu_sFusionDisp->sSlotGroup[10].SlotY1 -
                    rtu_sFusionDisp->sSlotGroup[10].SlotY2));
  rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotWidth11 = fminf(fabsf
    (rtu_sFusionDisp->sSlotGroup[10].SlotX0 - rtu_sFusionDisp->sSlotGroup[10].
     SlotX1), fabsf(rtu_sFusionDisp->sSlotGroup[10].SlotX3 -
                    rtu_sFusionDisp->sSlotGroup[10].SlotX2));
  switch (rtu_sFusionDisp->sSlotGroup[10].eDispSlotStatus)
  {
   case SLOT_DISP_AVAILABLE:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_11_Status = 1U;

    /* 0x1：Available */
    break;

   case SLOT_DISP_UNAVAILABLE:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_11_Status = 2U;

    /* 0x2：unavailable */
    break;

   case SLOT_DISP_UNKNOWN:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_11_Status = 4U;

    /* 0x4：unknow     */
    break;

   case SLOT_DISP_SELECTED:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_11_Status = 3U;

    /* 0x3：Selected */
    break;

   default:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_11_Status = 0U;
    break;
  }

  switch (rtu_sFusionDisp->sSlotGroup[10].eDispSlotType)
  {
   case DISP_SLOT_TYP_PERPENDICULAR:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType11 = 1U;

    /*  0x1：Vertical */
    break;

   case DISP_SLOT_TYP_PARALLEL:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType11 = 2U;

    /* 0x2：Parallel */
    break;

   case DISP_SLOT_TYP_OBLIQUE:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType11 = 3U;

    /* 0x3：Oblique */
    break;

   default:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType11 = 0U;
    break;
  }

  if ((((rtu_sFusionDisp->sSlotGroup[10].SlotY0 < 0.0F) &&
        (rtu_sFusionDisp->sSlotGroup[10].SlotY1 < 0.0F)) &&
       (rtu_sFusionDisp->sSlotGroup[10].SlotY2 < 0.0F)) &&
      (rtu_sFusionDisp->sSlotGroup[10].SlotY3 < 0.0F))
  {
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection11 = 1U;

    /* 0x1：Left */
  }
  else if (rtu_sFusionDisp->sSlotGroup[10].SlotY0 > 0.0F)
  {
    if (rtu_sFusionDisp->sSlotGroup[10].SlotY1 > 0.0F)
    {
      if (rtu_sFusionDisp->sSlotGroup[10].SlotY2 > 0.0F)
      {
        if (rtu_sFusionDisp->sSlotGroup[10].SlotY3 > 0.0F)
        {
          rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection11 = 2U;

          /* 0x2：Right */
        }
        else
        {
          rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection11 = 0U;

          /*  */
        }
      }
      else
      {
        rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection11 = 0U;

        /*  */
      }
    }
    else
    {
      rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection11 = 0U;

      /*  */
    }
  }
  else
  {
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection11 = 0U;

    /*  */
  }

  /*  slot12 */
  if ((((rtu_sFusionDisp->sSlotGroup[11].SlotY0 < 0.0F) &&
        (rtu_sFusionDisp->sSlotGroup[11].SlotY1 < 0.0F)) &&
       (rtu_sFusionDisp->sSlotGroup[11].SlotY2 < 0.0F)) &&
      (rtu_sFusionDisp->sSlotGroup[11].SlotY3 < 0.0F))
  {
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_12_P0_X = rtu_sFusionDisp->sSlotGroup[11]
      .SlotX1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_12_P0_Y = rtu_sFusionDisp->sSlotGroup[11]
      .SlotY1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_12_P1_X = rtu_sFusionDisp->sSlotGroup[11]
      .SlotX0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_12_P1_Y = rtu_sFusionDisp->sSlotGroup[11]
      .SlotY0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_12_P2_X = rtu_sFusionDisp->sSlotGroup[11]
      .SlotX2;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_12_P2_Y = rtu_sFusionDisp->sSlotGroup[11]
      .SlotY2;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_12_P3_X = rtu_sFusionDisp->sSlotGroup[11]
      .SlotX3;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_12_P3_Y = rtu_sFusionDisp->sSlotGroup[11]
      .SlotY3;
  }
  else
  {
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_12_P0_X = rtu_sFusionDisp->sSlotGroup[11]
      .SlotX0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_12_P0_Y = rtu_sFusionDisp->sSlotGroup[11]
      .SlotY0;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_12_P1_X = rtu_sFusionDisp->sSlotGroup[11]
      .SlotX1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_12_P1_Y = rtu_sFusionDisp->sSlotGroup[11]
      .SlotY1;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_12_P2_X = rtu_sFusionDisp->sSlotGroup[11]
      .SlotX3;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_12_P2_Y = rtu_sFusionDisp->sSlotGroup[11]
      .SlotY3;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_12_P3_X = rtu_sFusionDisp->sSlotGroup[11]
      .SlotX2;
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_12_P3_Y = rtu_sFusionDisp->sSlotGroup[11]
      .SlotY2;
  }

  rty_sPrkInSlotTx->ADCS5_RPA_slot_Angle12 = 0.0F;
  rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDepth12 = fminf(fabsf
    (rtu_sFusionDisp->sSlotGroup[11].SlotY0 - rtu_sFusionDisp->sSlotGroup[11].
     SlotY3), fabsf(rtu_sFusionDisp->sSlotGroup[11].SlotY1 -
                    rtu_sFusionDisp->sSlotGroup[11].SlotY2));
  rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotWidth12 = fminf(fabsf
    (rtu_sFusionDisp->sSlotGroup[11].SlotX0 - rtu_sFusionDisp->sSlotGroup[11].
     SlotX1), fabsf(rtu_sFusionDisp->sSlotGroup[11].SlotX3 -
                    rtu_sFusionDisp->sSlotGroup[11].SlotX2));
  switch (rtu_sFusionDisp->sSlotGroup[11].eDispSlotStatus)
  {
   case SLOT_DISP_AVAILABLE:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_12_Status = 1U;

    /* 0x1：Available */
    break;

   case SLOT_DISP_UNAVAILABLE:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_12_Status = 2U;

    /* 0x2：unavailable */
    break;

   case SLOT_DISP_UNKNOWN:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_12_Status = 4U;

    /* 0x4：unknow     */
    break;

   case SLOT_DISP_SELECTED:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_12_Status = 3U;

    /* 0x3：Selected */
    break;

   default:
    rty_sPrkInSlotTx->ADCS5_RPA_slot_ID_12_Status = 0U;
    break;
  }

  switch (rtu_sFusionDisp->sSlotGroup[11].eDispSlotType)
  {
   case DISP_SLOT_TYP_PERPENDICULAR:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType12 = 1U;

    /*  0x1：Vertical */
    break;

   case DISP_SLOT_TYP_PARALLEL:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType12 = 2U;

    /* 0x2：Parallel */
    break;

   case DISP_SLOT_TYP_OBLIQUE:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType12 = 3U;

    /* 0x3：Oblique */
    break;

   default:
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotType12 = 0U;
    break;
  }

  if ((((rtu_sFusionDisp->sSlotGroup[11].SlotY0 < 0.0F) &&
        (rtu_sFusionDisp->sSlotGroup[11].SlotY1 < 0.0F)) &&
       (rtu_sFusionDisp->sSlotGroup[11].SlotY2 < 0.0F)) &&
      (rtu_sFusionDisp->sSlotGroup[11].SlotY3 < 0.0F))
  {
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection12 = 1U;

    /* 0x1：Left */
  }
  else if (rtu_sFusionDisp->sSlotGroup[11].SlotY0 > 0.0F)
  {
    if (rtu_sFusionDisp->sSlotGroup[11].SlotY1 > 0.0F)
    {
      if (rtu_sFusionDisp->sSlotGroup[11].SlotY2 > 0.0F)
      {
        if (rtu_sFusionDisp->sSlotGroup[11].SlotY3 > 0.0F)
        {
          rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection12 = 2U;

          /* 0x2：Right */
        }
        else
        {
          rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection12 = 0U;

          /*  */
        }
      }
      else
      {
        rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection12 = 0U;

        /*  */
      }
    }
    else
    {
      rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection12 = 0U;

      /*  */
    }
  }
  else
  {
    rty_sPrkInSlotTx->ADCS5_RPA_ParkingSlotDirection12 = 0U;

    /*  */
  }

  /* End of MATLAB Function: '<S28>/PrkInSlotDet' */

  /* Update for RelationalOperator: '<S4>/Equal2' incorporates:
   *  UnitDelay: '<S4>/Unit Delay2'
   */
  hozon_hmi_output_DW.UnitDelay2_DSTATE = rtu_sMasterLsadFsm->eLsadSystemSts;

  /* Update for UnitDelay: '<S4>/Unit Delay3' */
  hozon_hmi_output_DW.bitsForTID0.UnitDelay3_DSTATE = LocalVar_OR1;

  /* Update for UnitDelay: '<S54>/Unit Delay2' */
  hozon_hmi_output_DW.bitsForTID0.UnitDelay2_DSTATE_p = LocalVar_OR1;

  /* Update for UnitDelay: '<S23>/Unit Delay' incorporates:
   *  UnitDelay: '<S21>/Unit Delay'
   */
  hozon_hmi_output_DW.UnitDelay_DSTATE_b =
    hozon_hmi_output_DW.UnitDelay_DSTATE_g;
}

/* Model initialize function */
void hozon_hmi_output_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)&hozon_hmi_output_DW, 0,
                sizeof(DW_hozon_hmi_output_f_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
