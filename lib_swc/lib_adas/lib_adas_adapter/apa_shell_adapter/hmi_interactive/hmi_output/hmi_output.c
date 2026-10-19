/*
 * File: hmi_output.c
 *
 * Code generated for Simulink model 'hmi_output'.
 *
 * Model version                  : 1.1553
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Wed Dec 25 10:37:26 2024
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

#include "hmi_output.h"

/* Block states (default storage) */
#define CtrlPara_START_SEC_VAR
#include "proj_MemMap.h"
DW_hmi_output_f_T hmi_output_DW;
#define CtrlPara_STOP_SEC_VAR
#include "proj_MemMap.h"
/* Forward declaration for local functions */
static uint16_T hmi_output_FuncTextDisplay_APA(tLSAD_SystemSts eLsadSystemSts,
  boolean_T sPaStateCommon_sCondiOverFlag_bCmpltDurattime, boolean_T
  sPaStateCommon_sCondiOverFlag_bTrmntDurattime, tIntrptEvnt
  sPaStateCommon_sPAEvnt_ePAIntrptEvnt, tTrmntEvnt
  sPaStateCommon_sPAEvnt_ePATrmntEvnt, tSuspendEvnt
  sPaStateAdptr_sPAEvntAdptr_ePASuspendEvnt, tQuitEvnt
  sPaStateAdptr_sPAEvntAdptr_ePAQuitEvnt, boolean_T
  sVehCommon_sCondiDoorSblt_bHoodDrClose, tDriverRequest eDriverRequest,
  boolean_T bPressBrkPedal, uint16_T LastFuncTextDisplay);

/* Function for MATLAB Function: '<Root>/FuncTextDisplayDet' */
static uint16_T hmi_output_FuncTextDisplay_APA(tLSAD_SystemSts eLsadSystemSts,
  boolean_T sPaStateCommon_sCondiOverFlag_bCmpltDurattime, boolean_T
  sPaStateCommon_sCondiOverFlag_bTrmntDurattime, tIntrptEvnt
  sPaStateCommon_sPAEvnt_ePAIntrptEvnt, tTrmntEvnt
  sPaStateCommon_sPAEvnt_ePATrmntEvnt, tSuspendEvnt
  sPaStateAdptr_sPAEvntAdptr_ePASuspendEvnt, tQuitEvnt
  sPaStateAdptr_sPAEvntAdptr_ePAQuitEvnt, boolean_T
  sVehCommon_sCondiDoorSblt_bHoodDrClose, tDriverRequest eDriverRequest,
  boolean_T bPressBrkPedal, uint16_T LastFuncTextDisplay)
{
  uint16_T u16FuncTextDisplay;
  switch (eLsadSystemSts)
  {
   case LSAD_STS_QUIT:
    switch (sPaStateAdptr_sPAEvntAdptr_ePAQuitEvnt)
    {
     case QUIT_INTERNAL_FAIL:
      u16FuncTextDisplay = 303U;

      /* 泊车系统故障，功能终止， */
      break;

     case QUIT_EXTERNAL_FAIL:
      u16FuncTextDisplay = 304U;

      /*  关联系统故障，功能终止， */
      break;

     case QUIT_SEARCH_OVERSLOPE:
      u16FuncTextDisplay = 319U;

      /* 坡度过大，功能终止， */
      break;

     case QUIT_ACTIVE_DA:
      u16FuncTextDisplay = 324U;

      /* ADAS车控功能已开启，功能终止， */
      break;

     case QUIT_SEARCH_OVERTIME:
      u16FuncTextDisplay = 307U;

      /* 车位搜索超时，功能中止，3s后退出 */
      break;

     case QUIT_CONFIRM_OVERTIME:
      u16FuncTextDisplay = 308U;

      /* 泊车超时，功能终止， */
      break;

     case QUIT_PATH_PLAN_FAIL:
      u16FuncTextDisplay = 309U;

      /* 泊车空间不足，功能终止， */
      break;

     case QUIT_HANDSHAKE_FAIL:
      u16FuncTextDisplay = 304U;

      /* 关联系统故障，功能终止 */
      break;

     case QUIT_MANUAL_DEACTIVATE:
      u16FuncTextDisplay = 0U;
      break;

     case QUIT_RPA_CONNECT_OVERTIME:
      u16FuncTextDisplay = 310U;

      /* "操作超时，请接管车辆" */
      break;

     case QUIT_INVALID_SIGNAL:
      u16FuncTextDisplay = 304U;

      /* 关联系统故障，功能终止， */
      break;

     case QUIT_TIRE_PRESSURE_ABNORMAL:
      u16FuncTextDisplay = 311U;

      /* 胎压报警，功能终止， */
      break;

     case QUIT_RPA_LOW_BAT:
      u16FuncTextDisplay = 312U;

      /* 电量不足，功能终止， */
      break;

     case QUIT_RELEASING_FAIL:
      u16FuncTextDisplay = 313U;

      /* 功能终止，系统 */
      break;

     case QUIT_USS_FAIL:
      u16FuncTextDisplay = 303U;

      /*  泊车系统故障，功能终止， */
      break;

     case QUIT_VISION_FAIL:
      u16FuncTextDisplay = 303U;

      /*  泊车系统故障，功能终止， */
      break;

     case QUIT_MIRROR_FOLD:
      u16FuncTextDisplay = 314U;

      /* 后视镜被折叠，功能终止， */
      break;

     case QUIT_SEARCH_OVERSPEED:
      u16FuncTextDisplay = 315U;

      /* 泊车超速，功能终止 */
      break;

     case QUIT_VEH_MOVE:
      u16FuncTextDisplay = 207U;

      /* 请在车辆静止下使用此功能 */
      break;

     default:
      u16FuncTextDisplay = 0U;
      break;
    }
    break;

   case LSAD_STS_PREPARE_SUSPEND:
    switch (sPaStateAdptr_sPAEvntAdptr_ePASuspendEvnt)
    {
     case SUSPEND_DR_DOOR_OPEN:
      u16FuncTextDisplay = 200U;

      /* "请关闭车门" */
      break;

     case SUSPEND_TRUNK_OPEN:
      u16FuncTextDisplay = 203U;

      /* "请关闭行李箱门" */
      break;

     case SUSPEND_HOOD_OPEN:
      u16FuncTextDisplay = 204U;

      /* 请关闭机舱盖 */
      break;

     case SUSPEND_RPA_OBSTACLE:
      u16FuncTextDisplay = 205U;

      /* 轨迹内有障碍物，请处理后重试 */
      break;

     case SUSPEND_SPEED_HIGH:
      u16FuncTextDisplay = 15U;

      /* 车速过快，请将车速降低至25km/H以下 */
      break;

     default:
      u16FuncTextDisplay = 0U;
      break;
    }
    break;

   case LSAD_STS_ACTIVE_SUSPEND:
    if ((boolean_T)((int32_T)(((sPaStateCommon_sPAEvnt_ePAIntrptEvnt ==
            INTERRUPT_DOOR_OPEN) ? ((int32_T)1) : ((int32_T)0)) &
          (sVehCommon_sCondiDoorSblt_bHoodDrClose ? ((int32_T)1) : ((int32_T)0)))))
    {
      u16FuncTextDisplay = 200U;

      /* 车门被打开，请关闭后重试 */
    }
    else if ((boolean_T)((int32_T)(((sPaStateCommon_sPAEvnt_ePAIntrptEvnt ==
                 INTERRUPT_DOOR_OPEN) ? ((int32_T)1) : ((int32_T)0)) &
               (((boolean_T)((int32_T)((sVehCommon_sCondiDoorSblt_bHoodDrClose ?
      ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
    {
      u16FuncTextDisplay = 204U;

      /*  机舱盖开启，请关闭后重试 */
    }
    else
    {
      switch (sPaStateCommon_sPAEvnt_ePAIntrptEvnt)
      {
       case INTERRUPT_SEATBELT_UNBUCKLED:
        u16FuncTextDisplay = 201U;

        /* 安全带未系，请系上安全带后重试 */
        break;

       case INTERRUPT_TRUNK_OPEN:
        u16FuncTextDisplay = 203U;

        /* 行李箱门开启，请关闭后重试 */
        break;

       case INTERRUPT_OBSTACLE:
        u16FuncTextDisplay = 9U;

        /* 泊车恢复，请点击继续泊车 */
        break;

       case INTERRUPT_MANUAL_BRAKE:
        u16FuncTextDisplay = 206U;

        /* 系统检测到刹车，功能中断，松开刹车后，泊车继续 */
        break;

       default:
        u16FuncTextDisplay = 0U;
        break;
      }
    }
    break;

   case LSAD_STS_TERMINATED:
    switch (sPaStateCommon_sPAEvnt_ePATrmntEvnt)
    {
     case TERMINATE_INTERNAL_FAIL:
      u16FuncTextDisplay = 303U;

      /* 泊车系统故障，功能终止， */
      break;

     case TERMINATE_EXTERNAL_FAIL:
      u16FuncTextDisplay = 304U;

      /* 关联系统故障，功能终止， */
      break;

     case TERMINATE_MANVR_OVERTIME:
      u16FuncTextDisplay = 310U;

      /* 泊车超时，功能终止， */
      break;

     case TERMINATE_MANVR_OVERSPEED:
      u16FuncTextDisplay = 315U;

      /* 泊车超速，功能终止， */
      break;

     case TERMINATE_MANVR_OVERFLOW:
      u16FuncTextDisplay = 316U;

      /* 泊车超步，功能终止， */
      break;

     case TERMINATE_INTERRUPT_OVERFLOW:
      u16FuncTextDisplay = 317U;

      /* 0xB：中断次数超限，功能终止， */
      break;

     case TERMINATE_INVALID_SIGNAL:
      u16FuncTextDisplay = 303U;

      /* 泊车系统故障，功能终止， */
      break;

     case TERMINATE_STEER_INTERFERE:
      u16FuncTextDisplay = 300U;

      /* 驾驶员干预，功能终止， */
      break;

     case TERMINATE_ACCEL_INTERFERE:
      u16FuncTextDisplay = 300U;

      /* 驾驶员干预，功能终止， */
      break;

     case TERMINATE_UNEXP_GEAR:
      u16FuncTextDisplay = 304U;

      /* 关联系统故障，功能终止， */
      break;

     case TERMINATE_UNEXP_EPB:
      u16FuncTextDisplay = 304U;

      /* 关联系统故障，功能终止， */
      break;

     case TERMINATE_UNEXP_AS:
      u16FuncTextDisplay = 304U;

      /* 关联系统故障，功能终止， */
      break;

     case TERMINATE_VEH_BLOCK:
      u16FuncTextDisplay = 318U;

      /* 车辆受阻，功能终止， */
      break;

     case TERMINATE_VEH_SLIP:
      u16FuncTextDisplay = 319U;

      /*  坡度过大，功能终止， */
      break;

     case TERMINATE_NO_PATH:
      u16FuncTextDisplay = 309U;

      /* 泊车空间不足，功能终止， */
      break;

     case TERMINATE_PATH_PLAN_FAIL:
      u16FuncTextDisplay = 309U;

      /* 泊车空间不足，功能终止， */
      break;

     case TERMINATE_GEAR_INTERFERE:
      u16FuncTextDisplay = 300U;

      /* 驾驶员干预，功能终止， */
      break;

     case TERMINATE_INTERRUPT_OVERTIME:
      u16FuncTextDisplay = 320U;

      /* 中断时间超时，功能终止， */
      break;

     case TERMINATE_TIRE_PRESSURE_ABNORMAL:
      u16FuncTextDisplay = 311U;

      /* 胎压报警，功能终止， */
      break;

     case TERMINATE_SLOPE_OVERLIMIT:
      u16FuncTextDisplay = 319U;

      /* 坡度过大，功能终止， */
      break;

     case TERMINATE_READY_OVERTIME:
      u16FuncTextDisplay = 310U;

      /* 操作超时，请接管车辆 */
      break;

     case TERMINATE_RELEASING_FAIL:
      u16FuncTextDisplay = 321U;

      /* "泊车已退出(非预期原因导致泊车退出)" */
      break;

     default:
      if (sPaStateCommon_sCondiOverFlag_bTrmntDurattime)
      {
        u16FuncTextDisplay = 310U;

        /* 0"操作超时，请接管车辆" */
      }
      else
      {
        switch (sPaStateCommon_sPAEvnt_ePATrmntEvnt)
        {
         case TERMINATE_VISION_FAIL:
          u16FuncTextDisplay = 303U;

          /* 泊车系统故障，功能终止， */
          break;

         case TERMINATE_USS_FAIL:
          u16FuncTextDisplay = 303U;

          /* 泊车系统故障，功能终止， */
          break;

         case TERMINATE_MANUAL_DEACT:
          u16FuncTextDisplay = 321U;

          /* 功能终止，系统 */
          break;

         case TERMINATE_MIRROR_FOLD:
          u16FuncTextDisplay = 314U;

          /* 后视镜被折叠，功能终止， */
          break;

         case TERMINATE_VEH_MOVE:
          u16FuncTextDisplay = 207U;

          /* 请在车辆静止下使用此功能 */
          break;

         case TERMINATE_PO_FRONT_NO_OBS:
          u16FuncTextDisplay = 322U;

          /* 周围空旷，可自主泊出 */
          break;

         default:
          u16FuncTextDisplay = 0U;
          break;
        }
      }
      break;
    }
    break;

   case LSAD_STS_COMPLETE:
    if (sPaStateCommon_sCondiOverFlag_bCmpltDurattime)
    {
      u16FuncTextDisplay = 310U;

      /* "操作超时，请接管车辆" */
    }
    else
    {
      u16FuncTextDisplay = 100U;

      /* 泊车已完成 */
    }
    break;

   default:
    switch (eDriverRequest)
    {
     case DRIVER_SEARCH_PS:
      u16FuncTextDisplay = 4U;

      /* 搜索车位中，请保持低速行驶 */
      break;

     case DRIVER_STOP_TO_SELECT_PS:
      u16FuncTextDisplay = 2U;

      /* 已找到车位，请踩住刹车，点击开始泊入 */
      break;

     case DRIVER_PRESS_DMS_TO_START:
      u16FuncTextDisplay = 0U;

      /* 0x0：Noindication */
      break;

     case DRIVER_SELECT_PS_AND_CONFIRM:
      u16FuncTextDisplay = 10U;

      /* 请保持车辆静止并点击开始泊车 */
      break;

     case DRIVER_SELECT_VIR_PS_TYPE:
      u16FuncTextDisplay = 15U;

      /* 请保持车辆静止并选择车位类型 */
      break;

     case DRIVER_ADJUST_VIR_PS:
      u16FuncTextDisplay = 14U;

      /* 请调整好目标车位后点击确认 */
      break;

     case DRIVER_CONFIRM_VIR_PS:
      u16FuncTextDisplay = 10U;

      /* 请保持车辆静止并点击开始泊车 */
      break;

     case DRIVER_SELECT_DIR_W_PS_TYPE:
      u16FuncTextDisplay = 6U;

      /* 请保持车辆静止并选择泊出类型及方向 */
      break;

     case DRIVER_CONFIRM_DIR:
      u16FuncTextDisplay = 10U;

      /* 请保持车辆静止并点击开始泊车 */
      break;

     case DRIVER_WAIT_PATH_PLAN:
      u16FuncTextDisplay = LastFuncTextDisplay;

      /* 路径规划中,显示的太快了，这里索性直接保持上一个的输出 */
      break;

     case DRIVER_WAIT_HANDSHAKE:
      u16FuncTextDisplay = LastFuncTextDisplay;

      /* 路径规划中,显示的太快了，这里索性直接保持上一个的输出 */
      break;

     case DRIVER_RELEASE_CONTROL:
      /* 实际无，eDriverRequest的判断端已经屏蔽了 */
      u16FuncTextDisplay = 11U;

      /* 请松开刹车及方向盘，自动泊车开始 */
      break;

     case DRIVER_MONITOR_APA_PARKING:
      u16FuncTextDisplay = 7U;

      /* 请注意周边环境 */
      break;

     case DRIVER_CONFIRM_RECOVERY:
      u16FuncTextDisplay = 0U;

      /* ADCS4_text = 0x0：No indication */
      break;

     case DRIVER_MONITOR_RPA_PARKING:
      u16FuncTextDisplay = 7U;

      /* 请注意周边环境 */
      break;

     default:
      u16FuncTextDisplay = 0U;

      /* 0x0：Noindication */
      break;
    }
    break;
  }

  if (bPressBrkPedal)
  {
    u16FuncTextDisplay = 1U;

    /* 请踩刹车踏板 */
  }

  return u16FuncTextDisplay;
}

/* Output and update for referenced model: 'hmi_output' */
void hmi_output(const tHMIComDisp *rtu_sHMIComDisp, const tPaStateCommon
                *rtu_sPaStateCommon, const tRaStateCommon *rtu_sRaStateCommon,
                const tHpaStateCommon *rtu_eHpaStateCommon, const tVehDataRx
                *rtu_sVehDataRx, const tRelatedModuleInfo
                *rtu_sRelatedModuleInfo, const tVehCommon *rtu_sVehCommon, const
                tMasterLsadFsm *rtu_sMasterLsadFsm, const tSlaveLsadFsm
                *rtu_sSlaveLsadFsm, const tPaStateAdptr *rtu_sPaStateAdptr,
                tMsgMnger_TextDisp *rty_sMsgMnger_TextDisp)
{
  int32_T i;
  real32_T tmp;
  int8_T LocalVar_Res[7];
  uint8_T LocalVar_u8LocTextDisplay;
  uint8_T LocalVar_u8MapTextDisplay;
  uint8_T LocalVar_u8VehiGear;
  boolean_T bPressBrkPedal;

  /* MATLAB Function: '<Root>/FuncTextDisplayDet' incorporates:
   *  UnitDelay: '<Root>/EMUnitDelay'
   */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
               (((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
                 ((int32_T)1) : ((int32_T)0)) |
                ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE_SUSPEND)
                 ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
            & (((boolean_T)((int32_T)((((boolean_T)((int32_T)
      (((HANDSHAKE_RQ_HIGH_SPEED == rtu_sRelatedModuleInfo->eHandshakeTypeReq) ?
        ((int32_T)1) : ((int32_T)0)) & ((HANDSHAKE_HIGH_SPEED !=
      rtu_sRelatedModuleInfo->eHandshakeType) ? ((int32_T)1) : ((int32_T)0))))) ?
    ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
      (((HANDSHAKE_RQ_LOW_SPEED == rtu_sRelatedModuleInfo->eHandshakeTypeReq) ?
        ((int32_T)1) : ((int32_T)0)) & ((HANDSHAKE_LOW_SPEED !=
      rtu_sRelatedModuleInfo->eHandshakeType) ? ((int32_T)1) : ((int32_T)0))))) ?
    ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) ?
         ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)((((boolean_T)
              ((int32_T)(((rtu_sMasterLsadFsm->eLsadSystemSts ==
      LSAD_STS_PREPARE) ? ((int32_T)1) : ((int32_T)0)) &
                         ((HANDSHAKE_RQ_LOW_SPEED ==
      rtu_sRelatedModuleInfo->eHandshakeTypeReq) ? ((int32_T)1) : ((int32_T)0)))))
             ? ((int32_T)1) : ((int32_T)0)) & ((HANDSHAKE_HIGH_SPEED ==
              rtu_sRelatedModuleInfo->eHandshakeType) ? ((int32_T)1) : ((int32_T)
              0))))) ? ((int32_T)1) : ((int32_T)0)))))
  {
    bPressBrkPedal = true;

    /* HPA是在active的时候，HPA切APA的时候是在prepare时，请求低，实际高的时候。 */
  }
  else
  {
    bPressBrkPedal = false;
  }

  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)(((LSAD_PARK_IN ==
              rtu_sSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) : ((int32_T)0)) |
            ((LSAD_PARK_OUT == rtu_sSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1) :
             ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
        ((LSAD_PARK_STRAIGHT == rtu_sSlaveLsadFsm->eLsadFuncType) ? ((int32_T)1)
         : ((int32_T)0)))))
  {
    hmi_output_DW.EMUnitDelay_DSTATE = hmi_output_FuncTextDisplay_APA
      (rtu_sMasterLsadFsm->eLsadSystemSts,
       rtu_sPaStateCommon->sCondiOverFlag.bCmpltDurattime,
       rtu_sPaStateCommon->sCondiOverFlag.bTrmntDurattime,
       rtu_sPaStateCommon->sPAEvnt.ePAIntrptEvnt,
       rtu_sPaStateCommon->sPAEvnt.ePATrmntEvnt,
       rtu_sPaStateAdptr->sPAEvntAdptr.ePASuspendEvnt,
       rtu_sPaStateAdptr->sPAEvntAdptr.ePAQuitEvnt,
       rtu_sVehCommon->sCondiDoorSblt.bHoodDrClose,
       rtu_sHMIComDisp->eDriverRequest, bPressBrkPedal,
       hmi_output_DW.EMUnitDelay_DSTATE);
  }
  else
  {
    switch (rtu_sSlaveLsadFsm->eLsadFuncType)
    {
     case LSAD_CRUISE:
      switch (rtu_sMasterLsadFsm->eLsadSystemSts)
      {
       case LSAD_STS_QUIT:
        switch (rtu_eHpaStateCommon->sHPAEvnt.eHPAQuitEvnt)
        {
         case QUIT_INTERNAL_FAIL:
          hmi_output_DW.EMUnitDelay_DSTATE = 303U;

          /* 泊车系统故障，功能终止， */
          break;

         case QUIT_EXTERNAL_FAIL:
          hmi_output_DW.EMUnitDelay_DSTATE = 304U;

          /*  关联系统故障，功能终止， */
          break;

         case QUIT_SEARCH_OVERSLOPE:
          hmi_output_DW.EMUnitDelay_DSTATE = 319U;

          /* 坡度过大，功能终止， */
          break;

         case QUIT_ACTIVE_DA:
          hmi_output_DW.EMUnitDelay_DSTATE = 324U;

          /* ADAS车控功能已开启，功能终止， */
          break;

         case QUIT_SEARCH_OVERTIME:
          hmi_output_DW.EMUnitDelay_DSTATE = 307U;

          /* 车位搜索超时，功能中止，3s后退出 */
          break;

         case QUIT_CONFIRM_OVERTIME:
          hmi_output_DW.EMUnitDelay_DSTATE = 308U;

          /* 泊车超时，功能终止， */
          break;

         case QUIT_PATH_PLAN_FAIL:
          hmi_output_DW.EMUnitDelay_DSTATE = 325U;

          /* 规划失败，功能终止 */
          break;

         case QUIT_HANDSHAKE_FAIL:
          hmi_output_DW.EMUnitDelay_DSTATE = 304U;

          /* 关联系统故障，功能终止 */
          break;

         case QUIT_MANUAL_DEACTIVATE:
          hmi_output_DW.EMUnitDelay_DSTATE = 0U;
          break;

         case QUIT_RPA_CONNECT_OVERTIME:
          hmi_output_DW.EMUnitDelay_DSTATE = 310U;

          /* "操作超时，请接管车辆" */
          break;

         case QUIT_INVALID_SIGNAL:
          hmi_output_DW.EMUnitDelay_DSTATE = 304U;

          /* 关联系统故障，功能终止， */
          break;

         case QUIT_TIRE_PRESSURE_ABNORMAL:
          hmi_output_DW.EMUnitDelay_DSTATE = 311U;

          /* 胎压报警，功能终止， */
          break;

         case QUIT_RPA_LOW_BAT:
          hmi_output_DW.EMUnitDelay_DSTATE = 312U;

          /* 电量不足，功能终止， */
          break;

         case QUIT_RELEASING_FAIL:
          hmi_output_DW.EMUnitDelay_DSTATE = 313U;

          /* 功能终止，系统 */
          break;

         case QUIT_USS_FAIL:
          hmi_output_DW.EMUnitDelay_DSTATE = 303U;

          /*  泊车系统故障，功能终止， */
          break;

         case QUIT_VISION_FAIL:
          hmi_output_DW.EMUnitDelay_DSTATE = 303U;

          /*  泊车系统故障，功能终止， */
          break;

         case QUIT_MIRROR_FOLD:
          hmi_output_DW.EMUnitDelay_DSTATE = 314U;

          /* 后视镜被折叠，功能终止， */
          break;

         case QUIT_SEARCH_OVERSPEED:
          hmi_output_DW.EMUnitDelay_DSTATE = 315U;

          /* 泊车超速，功能终止 */
          break;

         case QUIT_VEH_MOVE:
          hmi_output_DW.EMUnitDelay_DSTATE = 207U;

          /* 请在车辆静止下使用此功能 */
          break;

         default:
          hmi_output_DW.EMUnitDelay_DSTATE = 0U;
          break;
        }

        /*  elseif(eLsadSystemSts == tLSAD_SystemSts.LSAD_STS_PREPARE_SUSPEND ) */
        /*      if(sHpaStateCommon.sHPAEvnt.eHPASuspendEvnt == tSuspendEvnt.SUSPEND_DR_DOOR_OPEN) */
        /*          u16FuncTextDisplay = uint16(200);%"请关闭车门" */
        /*      elseif(sHpaStateCommon.sHPAEvnt.eHPASuspendEvnt == tSuspendEvnt.SUSPEND_TRUNK_OPEN) */
        /*          u16FuncTextDisplay = uint16(203);%"请关闭行李箱门" */
        /*      elseif(sHpaStateCommon.sHPAEvnt.eHPASuspendEvnt == tSuspendEvnt.SUSPEND_HOOD_OPEN) */
        /*          u16FuncTextDisplay = uint16(204);%请关闭机舱盖 */
        /*      elseif(sHpaStateCommon.sHPAEvnt.eHPASuspendEvnt == tSuspendEvnt.SUSPEND_RPA_OBSTACLE) */
        /*          u16FuncTextDisplay = uint16(205);%轨迹内有障碍物，请处理后重试 */
        /*      else */
        /*          u16FuncTextDisplay = uint16(0); */
        /*      end */
        break;

       case LSAD_STS_ACTIVE_SUSPEND:
        if ((boolean_T)((int32_T)(((rtu_eHpaStateCommon->sHPAEvnt.eHPAIntrptEvnt
                == INTERRUPT_DOOR_OPEN) ? ((int32_T)1) : ((int32_T)0)) &
              (rtu_sVehCommon->sCondiDoorSblt.bHoodDrClose ? ((int32_T)1) :
               ((int32_T)0)))))
        {
          hmi_output_DW.EMUnitDelay_DSTATE = 200U;

          /* 车门被打开，请关闭后重试 */
        }
        else if ((boolean_T)((int32_T)
                             (((rtu_eHpaStateCommon->sHPAEvnt.eHPAIntrptEvnt ==
                                INTERRUPT_DOOR_OPEN) ? ((int32_T)1) : ((int32_T)
                     0)) & (((boolean_T)((int32_T)
                      ((rtu_sVehCommon->sCondiDoorSblt.bHoodDrClose ? ((int32_T)
            1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
        {
          hmi_output_DW.EMUnitDelay_DSTATE = 204U;

          /*  机舱盖开启，请关闭后重试 */
        }
        else
        {
          switch (rtu_eHpaStateCommon->sHPAEvnt.eHPAIntrptEvnt)
          {
           case INTERRUPT_SEATBELT_UNBUCKLED:
            hmi_output_DW.EMUnitDelay_DSTATE = 201U;

            /* 安全带未系，请系上安全带后重试 */
            break;

           case INTERRUPT_TRUNK_OPEN:
            hmi_output_DW.EMUnitDelay_DSTATE = 203U;

            /* 行李箱门开启，请关闭后重试 */
            break;

           case INTERRUPT_OBSTACLE:
            hmi_output_DW.EMUnitDelay_DSTATE = 9U;

            /* 泊车恢复，请点击继续泊车 */
            break;

           case INTERRUPT_MANUAL_BRAKE:
            hmi_output_DW.EMUnitDelay_DSTATE = 206U;

            /* 系统检测到刹车，功能中断，松开刹车后，泊车继续 */
            break;

           default:
            hmi_output_DW.EMUnitDelay_DSTATE = 0U;
            break;
          }
        }
        break;

       case LSAD_STS_TERMINATED:
        switch (rtu_eHpaStateCommon->sHPAEvnt.eHPATrmntEvnt)
        {
         case TERMINATE_INTERNAL_FAIL:
          hmi_output_DW.EMUnitDelay_DSTATE = 303U;

          /* 泊车系统故障，功能终止， */
          break;

         case TERMINATE_EXTERNAL_FAIL:
          hmi_output_DW.EMUnitDelay_DSTATE = 304U;

          /* 关联系统故障，功能终止， */
          break;

         case TERMINATE_MANVR_OVERTIME:
          hmi_output_DW.EMUnitDelay_DSTATE = 310U;

          /* 泊车超时，功能终止， */
          break;

         case TERMINATE_MANVR_OVERSPEED:
          hmi_output_DW.EMUnitDelay_DSTATE = 315U;

          /* 泊车超速，功能终止， */
          break;

         case TERMINATE_MANVR_OVERFLOW:
          hmi_output_DW.EMUnitDelay_DSTATE = 316U;

          /* 泊车超步，功能终止， */
          break;

         case TERMINATE_INTERRUPT_OVERFLOW:
          hmi_output_DW.EMUnitDelay_DSTATE = 317U;

          /* 0xB：中断次数超限，功能终止， */
          break;

         case TERMINATE_INVALID_SIGNAL:
          hmi_output_DW.EMUnitDelay_DSTATE = 303U;

          /* 泊车系统故障，功能终止， */
          break;

         case TERMINATE_STEER_INTERFERE:
          hmi_output_DW.EMUnitDelay_DSTATE = 300U;

          /* 驾驶员干预，功能终止， */
          break;

         case TERMINATE_ACCEL_INTERFERE:
          hmi_output_DW.EMUnitDelay_DSTATE = 300U;

          /* 驾驶员干预，功能终止， */
          break;

         case TERMINATE_UNEXP_GEAR:
          hmi_output_DW.EMUnitDelay_DSTATE = 304U;

          /* 关联系统故障，功能终止， */
          break;

         case TERMINATE_UNEXP_EPB:
          hmi_output_DW.EMUnitDelay_DSTATE = 304U;

          /* 关联系统故障，功能终止， */
          break;

         case TERMINATE_UNEXP_AS:
          hmi_output_DW.EMUnitDelay_DSTATE = 304U;

          /* 关联系统故障，功能终止， */
          break;

         case TERMINATE_VEH_BLOCK:
          hmi_output_DW.EMUnitDelay_DSTATE = 318U;

          /* 车辆受阻，功能终止， */
          break;

         case TERMINATE_VEH_SLIP:
          hmi_output_DW.EMUnitDelay_DSTATE = 319U;

          /*  坡度过大，功能终止， */
          break;

         case TERMINATE_NO_PATH:
          hmi_output_DW.EMUnitDelay_DSTATE = 326U;

          /* 控制失败，功能终止 */
          break;

         case TERMINATE_PATH_PLAN_FAIL:
          hmi_output_DW.EMUnitDelay_DSTATE = 325U;

          /* 规划失败，功能终止 */
          break;

         case TERMINATE_GEAR_INTERFERE:
          hmi_output_DW.EMUnitDelay_DSTATE = 300U;

          /* 驾驶员干预，功能终止， */
          break;

         case TERMINATE_INTERRUPT_OVERTIME:
          hmi_output_DW.EMUnitDelay_DSTATE = 320U;

          /* 中断时间超时，功能终止， */
          break;

         case TERMINATE_TIRE_PRESSURE_ABNORMAL:
          hmi_output_DW.EMUnitDelay_DSTATE = 311U;

          /* 胎压报警，功能终止， */
          break;

         case TERMINATE_SLOPE_OVERLIMIT:
          hmi_output_DW.EMUnitDelay_DSTATE = 319U;

          /* 坡度过大，功能终止， */
          break;

         case TERMINATE_READY_OVERTIME:
          hmi_output_DW.EMUnitDelay_DSTATE = 310U;

          /* 操作超时，请接管车辆 */
          break;

         case TERMINATE_RELEASING_FAIL:
          hmi_output_DW.EMUnitDelay_DSTATE = 321U;

          /* "泊车已退出(非预期原因导致泊车退出)" */
          break;

         default:
          if (rtu_eHpaStateCommon->sHPACondiOverFlag.bHpaTrmntDurattime)
          {
            hmi_output_DW.EMUnitDelay_DSTATE = 310U;

            /* 0"操作超时，请接管车辆" */
          }
          else
          {
            switch (rtu_eHpaStateCommon->sHPAEvnt.eHPATrmntEvnt)
            {
             case TERMINATE_VISION_FAIL:
              hmi_output_DW.EMUnitDelay_DSTATE = 303U;

              /* 泊车系统故障，功能终止， */
              break;

             case TERMINATE_USS_FAIL:
              hmi_output_DW.EMUnitDelay_DSTATE = 303U;

              /* 泊车系统故障，功能终止， */
              break;

             case TERMINATE_MANUAL_DEACT:
              hmi_output_DW.EMUnitDelay_DSTATE = 321U;

              /* 功能终止，系统 */
              break;

             case TERMINATE_MIRROR_FOLD:
              hmi_output_DW.EMUnitDelay_DSTATE = 314U;

              /* 后视镜被折叠，功能终止， */
              break;

             case TERMINATE_VEH_MOVE:
              hmi_output_DW.EMUnitDelay_DSTATE = 207U;

              /* 请在车辆静止下使用此功能 */
              break;

             case TERMINATE_PO_FRONT_NO_OBS:
              hmi_output_DW.EMUnitDelay_DSTATE = 322U;

              /* 周围空旷，可自主泊出 */
              break;

             default:
              hmi_output_DW.EMUnitDelay_DSTATE = 0U;
              break;
            }
          }
          break;
        }
        break;

       case LSAD_STS_COMPLETE:
        if (rtu_eHpaStateCommon->sHPACondiOverFlag.bHpaCmpltDurattime)
        {
          hmi_output_DW.EMUnitDelay_DSTATE = 310U;

          /* "操作超时，请接管车辆" */
        }
        else
        {
          hmi_output_DW.EMUnitDelay_DSTATE = 100U;

          /* 泊车已完成 */
        }
        break;

       case LSAD_STS_HANDSHAKE:
        /* 路径规划中,显示的太快了，这里索性直接保持上一个的输出 */
        break;

       case LSAD_STS_PP:
        /* 路径规划中,显示的太快了，这里索性直接保持上一个的输出 */
        /*  elseif(eLsadSystemSts == tLSAD_SystemSts.LSAD_STS_ACTIVE && bBrkPedal)    %breakpedal */
        /*      u16FuncTextDisplay = uint16(11);%请松开刹车及方向盘，自动泊车开始 */
        break;

       case LSAD_STS_ACTIVE:
        hmi_output_DW.EMUnitDelay_DSTATE = 8U;

        /* 正在驶入您的车位，请注意周围环境 */
        break;

       default:
        hmi_output_DW.EMUnitDelay_DSTATE = 0U;

        /* 0x0：Noindication */
        break;
      }

      if (bPressBrkPedal)
      {
        hmi_output_DW.EMUnitDelay_DSTATE = 1U;

        /* 请踩刹车踏板 */
      }
      break;

     case LSAD_RA:
      /*  if(eLsadSystemSts == tLSAD_SystemSts.LSAD_STS_ACTIVE && bBrkPedal)   */
      /*  	u16FuncTextDisplay = uint16(40);%松开刹车及方向盘，循迹倒车开始    */
      switch (rtu_sMasterLsadFsm->eLsadSystemSts)
      {
       case LSAD_STS_ACTIVE:
        hmi_output_DW.EMUnitDelay_DSTATE = 41U;

        /* 循迹倒车中，请注意周边环境；   */
        break;

       case LSAD_STS_COMPLETE:
        hmi_output_DW.EMUnitDelay_DSTATE = 101U;

        /* 循迹倒车已完成 */
        /*  elseif(eRAStatus == tRAStatus.RA_PATH_RECORD && bRAWakeUpConfrm) */
        /*      u16FuncTextDisplay = uint16(20);%0x14：车辆无记忆路径，循迹倒车不可用 */
        /*  elseif (eRAStatus == tRAStatus.RA_SUSPEND)  */
        /*      if(sRaStateCommon.sRAEvnt.eRAIntrptEvnt == tRAIntrptEvnt.RA_INTERRUPT_DOOR_OPEN) */
        /*          u16FuncTextDisplay = uint16(13);%0xD：关闭车门后，点击继续恢复循迹倒车 */
        /*      elseif(sRaStateCommon.sRAEvnt.eRAIntrptEvnt == tRAIntrptEvnt.RA_INTERRUPT_SEATBELT_UNBUCKLED) */
        /*          u16FuncTextDisplay = uint16(12);%0xC：系好安全带后，点击继续恢复循迹倒车 */
        /*      elseif(sRaStateCommon.sRAEvnt.eRAIntrptEvnt == tRAIntrptEvnt.RA_INTERRUPT_TRUNK_OPEN) */
        /*          u16FuncTextDisplay = uint16(14);%0xE：关闭后备箱后，点击继续恢复循迹倒车 */
        /*      elseif(sRaStateCommon.sRAEvnt.eRAIntrptEvnt == tRAIntrptEvnt.RA_INTERRUPT_HOOD_OPEN) */
        /*          u16FuncTextDisplay = uint16(15);%0xF：关闭前舱盖后，点击继续恢复循迹倒车   */
        /*      elseif(sRaStateCommon.sRAEvnt.eRAIntrptEvnt == tRAIntrptEvnt.RA_INTERRUPT_OBSTACLE) */
        /*          u16FuncTextDisplay = uint16(16);%0x10：检测到障碍物，移除障碍物后，点击继续恢复循迹倒车 */
        /*      elseif(sRaStateCommon.sRAEvnt.eRAIntrptEvnt == tRAIntrptEvnt.RA_INTERRUPT_MANUAL_BRAKE) */
        /*          u16FuncTextDisplay = uint16(17);%0x11：检测到刹车踏板被踩下，松开刹车后可自动恢复循迹倒车   */
        /*      else */
        /*          u16FuncTextDisplay = uint16(0);     */
        /*      end */
        break;

       case LSAD_STS_QUIT:
        switch (rtu_sRaStateCommon->sRAEvnt.eRAQuitEvnt)
        {
         case RA_QUIT_EXTERNAL_FAIL:
          hmi_output_DW.EMUnitDelay_DSTATE = 304U;

          /* 0x3：关联系统故障，循迹倒车即将退出 */
          break;

         case RA_QUIT_MANUAL_DEACTIVATE:
          hmi_output_DW.EMUnitDelay_DSTATE = 0U;

          /*  */
          break;

         case RA_QUIT_VEH_MOVE:
          hmi_output_DW.EMUnitDelay_DSTATE = 207U;

          /* 请在车辆静止下使用此功能 */
          break;

         case RA_QUIT_HANDSHAKE_FAIL:
          hmi_output_DW.EMUnitDelay_DSTATE = 304U;

          /* 0x3:关联系统故障 */
          break;

         case RA_QUIT_INTERNAL_FAIL:
          hmi_output_DW.EMUnitDelay_DSTATE = 303U;

          /* 泊车系统故障，循迹倒车即将退出   */
          break;

         default:
          hmi_output_DW.EMUnitDelay_DSTATE = 0U;
          break;
        }
        break;

       case LSAD_STS_TERMINATED:
        switch (rtu_sRaStateCommon->sRAEvnt.eRATrmntEvnt)
        {
         case RA_TERMINATE_EXTERNAL_FAIL:
          hmi_output_DW.EMUnitDelay_DSTATE = 304U;

          /* 关联系统故障，循迹倒车即将退出   */
          break;

         case RA_TERMINATE_INTERNAL_FAIL:
          hmi_output_DW.EMUnitDelay_DSTATE = 303U;

          /* 泊车系统故障，循迹倒车即将退出     */
          break;

         case RA_TERMINATE_VEH_BLOCK:
          hmi_output_DW.EMUnitDelay_DSTATE = 318U;

          /* ：车辆受阻，循迹倒车即将退出    */
          break;

         case RA_TERMINATE_VEH_SLIP:
          hmi_output_DW.EMUnitDelay_DSTATE = 319U;

          /* 0x5：车辆发生溜坡，循迹倒车即将退出    */
          break;

         case RA_TERMINATE_SLOPE_OVERLIMIT:
          hmi_output_DW.EMUnitDelay_DSTATE = 319U;

          /* 0x7：坡度过大，循迹倒车即将退出     */
          break;

         case RA_TERMINATE_MANVR_OVERSPEED:
          hmi_output_DW.EMUnitDelay_DSTATE = 315U;

          /* 0x2：泊车超速，循迹倒车即将退出      */
          break;

         case RA_TERMINATE_INTERRUPT_OVERFLOW:
          hmi_output_DW.EMUnitDelay_DSTATE = 317U;

          /* 0x6：中断次数超限，循迹倒车即将退出 */
          break;

         case RA_TERMINATE_INTERRUPT_OVERTIME:
          hmi_output_DW.EMUnitDelay_DSTATE = 320U;

          /* 0xA：中断超时，循迹倒车即将退出    */
          break;

         case RA_TERMINATE_INVALID_SIGNAL:
          hmi_output_DW.EMUnitDelay_DSTATE = 303U;

          /* 0x3：关联系统故障，循迹倒车即将退出       */
          break;

         case RA_TERMINATE_STEER_INTERFERE:
          hmi_output_DW.EMUnitDelay_DSTATE = 300U;

          /* 0x9：驾驶员干预，循迹倒车即将退出 */
          break;

         case RA_TERMINATE_ACCEL_INTERFERE:
          hmi_output_DW.EMUnitDelay_DSTATE = 300U;

          /* 0x9：驾驶员干预，循迹倒车即将退出  */
          break;

         case RA_TERMINATE_GEAR_INTERFERE:
          hmi_output_DW.EMUnitDelay_DSTATE = 300U;

          /* 0x9：驾驶员干预，循迹倒车即将退出 */
          break;

         case RA_TERMINATE_UNEXP_GEAR:
          hmi_output_DW.EMUnitDelay_DSTATE = 300U;

          /* 0x9：驾驶员干预，循迹倒车即将退出 */
          break;

         case RA_TERMINATE_UNEXP_EPB:
          hmi_output_DW.EMUnitDelay_DSTATE = 300U;

          /* 0x9：驾驶员干预，循迹倒车即将退出       */
          break;

         case RA_TERMINATE_UXEXP_ADAS:
          hmi_output_DW.EMUnitDelay_DSTATE = 324U;

          /* 0x4：ADAS车控功能已开启，功能终止 */
          break;

         case RA_TERMINATE_UNEXP_AS:
          hmi_output_DW.EMUnitDelay_DSTATE = 300U;

          /* 0x9：驾驶员干预，循迹倒车即将退出    */
          /*      elseif(sRaStateCommon.sRAEvnt.eRATrmntEvnt == tRATrmntEvnt.RA_TERMINATE_MIRROR_FOLD) */
          /*          u16FuncTextDisplay = uint16(21);%0x15： */
          break;

         default:
          hmi_output_DW.EMUnitDelay_DSTATE = 0U;
          break;
        }
        break;

       default:
        hmi_output_DW.EMUnitDelay_DSTATE = 0U;

        /* 0x0：Noindication */
        break;
      }
      break;

     default:
      switch (rtu_sMasterLsadFsm->eLsadSystemSts)
      {
       case LSAD_STS_FAILURE:
        hmi_output_DW.EMUnitDelay_DSTATE = 303U;

        /* 系统故障，系统退出 */
        break;

       case LSAD_STS_INHIBIT:
        hmi_output_DW.EMUnitDelay_DSTATE = 304U;

        /* 关联系统故障，系统退出 */
        break;

       default:
        hmi_output_DW.EMUnitDelay_DSTATE = 0U;

        /*  */
        break;
      }
      break;
    }
  }

  /* MATLAB Function: '<Root>/MapTextDisplayDet' */
  switch (rtu_sRelatedModuleInfo->eMappingSts)
  {
   case MAPCREATOR_STATE_IN_PROGRESS:
    /*      case EMapCreatorState.MAPCREATOR_STATE_NOT_READY */
    /*          u8MapTextDisplay = uint8(1); */
    LocalVar_u8MapTextDisplay = 2U;
    break;

   case MAPCREATOR_STATE_FINALIZING:
    LocalVar_u8MapTextDisplay = 3U;
    break;

   case MAPCREATOR_STATE_SUCCESSED:
    LocalVar_u8MapTextDisplay = 4U;
    break;

   case MAPCREATOR_STATE_FAILED:
    LocalVar_u8MapTextDisplay = 5U;
    break;

   default:
    LocalVar_u8MapTextDisplay = 0U;
    break;
  }

  /* End of MATLAB Function: '<Root>/MapTextDisplayDet' */

  /* MATLAB Function: '<Root>/LocTextDisplayDet' incorporates:
   *  MATLAB Function: '<Root>/FuncTextDisplayDet'
   */
  /*  只在不建图的时候，standy的时候显示提示词 */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
               ((((boolean_T)((int32_T)(((MAPCREATOR_STATE_IN_PROGRESS ==
      rtu_sRelatedModuleInfo->eMappingSts) ? ((int32_T)1) : ((int32_T)0)) |
      ((MAPCREATOR_STATE_FINALIZING == rtu_sRelatedModuleInfo->eMappingSts) ?
       ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
                ((MAPCREATOR_STATE_SUCCESSED ==
                  rtu_sRelatedModuleInfo->eMappingSts) ? ((int32_T)1) :
                 ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
            ((MAPCREATOR_STATE_FAILED == rtu_sRelatedModuleInfo->eMappingSts) ?
             ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
        ((LSAD_STS_STANDBY != rtu_sMasterLsadFsm->eLsadSystemSts) ? ((int32_T)1)
         : ((int32_T)0)))))
  {
    LocalVar_u8LocTextDisplay = 0U;
  }
  else
  {
    switch (rtu_sRelatedModuleInfo->eLocSts)
    {
     case LOC_STATUS_TRYING:
      LocalVar_u8LocTextDisplay = 1U;
      break;

     case LOC_STATUS_SUCCESS:
      LocalVar_u8LocTextDisplay = 2U;
      break;

     default:
      LocalVar_u8LocTextDisplay = 0U;
      break;
    }
  }

  /* End of MATLAB Function: '<Root>/LocTextDisplayDet' */

  /* MATLAB Function: '<Root>/VehiGearMapping' */
  switch (rtu_sVehDataRx->sVehVCUInfo.eVehActualGear)
  {
   case NONE_GEAR:
    LocalVar_u8VehiGear = 4U;
    break;

   case R_GEAR:
    LocalVar_u8VehiGear = 1U;
    break;

   case N_GEAR:
    LocalVar_u8VehiGear = 2U;
    break;

   case D_GEAR:
    LocalVar_u8VehiGear = 3U;
    break;

   case P_GEAR:
    LocalVar_u8VehiGear = 0U;
    break;

   default:
    LocalVar_u8VehiGear = 4U;
    break;
  }

  /* End of MATLAB Function: '<Root>/VehiGearMapping' */

  /* MATLAB Function: '<S5>/FcnRes' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S8>/Constant'
   *  Constant: '<S9>/Constant'
   *  DataTypeConversion: '<S5>/EMUint8Conversion5'
   *  DataTypeConversion: '<S5>/EMUint8Conversion6'
   *  DataTypeConversion: '<S5>/EMUint8Conversion7'
   *  Logic: '<S5>/EMAND'
   *  RelationalOperator: '<S5>/EMGreat'
   *  RelationalOperator: '<S5>/Equal1'
   *  RelationalOperator: '<S5>/Equal2'
   *  RelationalOperator: '<S5>/Equal5'
   */
  for (i = 0; i < 7; i++)
  {
    LocalVar_Res[i] = 0;
  }

  LocalVar_Res[0] = (int8_T)((rtu_sRelatedModuleInfo->f32RARecordedDist > 5.0F) ?
    ((int32_T)1) : ((int32_T)0));
  LocalVar_Res[1] = (int8_T)(((boolean_T)((int32_T)
    (((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_STANDBY) ? ((int32_T)1) :
      ((int32_T)0)) & ((rtu_sRelatedModuleInfo->eLocSts == LOC_STATUS_SUCCESS) ?
                       ((int32_T)1) : ((int32_T)0))))) ? 1 : 0);
  LocalVar_Res[2] = (int8_T)((rtu_sRelatedModuleInfo->eMappingSts ==
    MAPCREATOR_STATE_READY) ? ((int32_T)1) : ((int32_T)0));

  /* End of MATLAB Function: '<S5>/FcnRes' */
  (void)memset(rty_sMsgMnger_TextDisp, 0, sizeof(tMsgMnger_TextDisp));

  /* BusAssignment: '<Root>/Bus Assignment' incorporates:
   *  DataTypeConversion: '<Root>/EMUint8Conversion'
   *  DataTypeConversion: '<Root>/EMUint8Conversion1'
   *  DataTypeConversion: '<Root>/EMUint8Conversion2'
   *  DataTypeConversion: '<Root>/EMUint8Conversion3'
   *  MATLAB Function: '<Root>/FuncTextDisplayDet'
   *  UnitDelay: '<Root>/EMUnitDelay'
   */
  rty_sMsgMnger_TextDisp->f32TTCMinValue = 25.0F;
  rty_sMsgMnger_TextDisp->u16FuncTextDisplay = hmi_output_DW.EMUnitDelay_DSTATE;
  rty_sMsgMnger_TextDisp->u8SystemSts = (uint8_T)
    rtu_sMasterLsadFsm->eLsadSystemSts;
  rty_sMsgMnger_TextDisp->u8MapSts = (uint8_T)
    rtu_sRelatedModuleInfo->eMappingSts;
  rty_sMsgMnger_TextDisp->u8LocSts = (uint8_T)rtu_sRelatedModuleInfo->eLocSts;
  rty_sMsgMnger_TextDisp->u8FuncType = (uint8_T)rtu_sSlaveLsadFsm->eLsadFuncType;
  rty_sMsgMnger_TextDisp->u8MEBStatus = 0U;
  rty_sMsgMnger_TextDisp->u8MapTextDisplay = LocalVar_u8MapTextDisplay;
  rty_sMsgMnger_TextDisp->u8LocTextDisplay = LocalVar_u8LocTextDisplay;
  rty_sMsgMnger_TextDisp->u8FuncBarPercent = 0U;

  /* MATLAB Function: '<Root>/FuncRemainDistDet' incorporates:
   *  MATLAB Function: '<Root>/FuncTextDisplayDet'
   */
  if ((boolean_T)((int32_T)(((LSAD_RA == rtu_sSlaveLsadFsm->eLsadFuncType) ?
         ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
           (((LSAD_STS_ACTIVE == rtu_sMasterLsadFsm->eLsadSystemSts) ? ((int32_T)
              1) : ((int32_T)0)) | ((LSAD_STS_ACTIVE_SUSPEND ==
              rtu_sMasterLsadFsm->eLsadSystemSts) ? ((int32_T)1) : ((int32_T)0)))))
         ? ((int32_T)1) : ((int32_T)0)))))
  {
    tmp = roundf(rtu_sRelatedModuleInfo->f32CtrlReqStopDistance);
    if (tmp < 256.0F)
    {
      if (tmp >= 0.0F)
      {
        /* BusAssignment: '<Root>/Bus Assignment' */
        rty_sMsgMnger_TextDisp->u8FuncRemainDist = (uint8_T)tmp;
      }
      else
      {
        /* BusAssignment: '<Root>/Bus Assignment' */
        rty_sMsgMnger_TextDisp->u8FuncRemainDist = 0U;
      }
    }
    else
    {
      /* BusAssignment: '<Root>/Bus Assignment' */
      rty_sMsgMnger_TextDisp->u8FuncRemainDist = MAX_uint8_T;
    }
  }
  else
  {
    /* BusAssignment: '<Root>/Bus Assignment' */
    rty_sMsgMnger_TextDisp->u8FuncRemainDist = 0U;
  }

  /* End of MATLAB Function: '<Root>/FuncRemainDistDet' */

  /* BusAssignment: '<Root>/Bus Assignment' */
  rty_sMsgMnger_TextDisp->u8SupportParkDirect =
    rtu_sRelatedModuleInfo->u8ParkoutDir;
  rty_sMsgMnger_TextDisp->u8VehDirect = LocalVar_u8VehiGear;
  for (i = 0; i < 7; i++)
  {
    rty_sMsgMnger_TextDisp->Res[i] = (uint8_T)LocalVar_Res[i];
  }
}

/* Model initialize function */
void hmi_output_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)&hmi_output_DW, 0,
                sizeof(DW_hmi_output_f_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
