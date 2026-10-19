/*
 * File: hmi_common.c
 *
 * Code generated for Simulink model 'hmi_common'.
 *
 * Model version                  : 1.1008
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Dec  2 15:47:08 2024
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

#include "hmi_common.h"
#include "circshift_Oao1VbEW.h"
#include "polyfit_ZTjQ9uNU.h"
#include "sort_sNVDfYYM.h"

/* Block states (default storage) */
#define CtrlPara_START_SEC_VAR
#include "proj_MemMap.h"
DW_hmi_common_f_T hmi_common_DW;
#define CtrlPara_STOP_SEC_VAR
#include "proj_MemMap.h"
/* Forward declaration for local functions */
static void hmi_common_UpdatePrkOutDispPLD(tLSAD_SystemSts eLsadSystemSts,
  tSlotDisp sSlotGroup[12], real32_T m_fX_Coor, real32_T m_fY_Coor, real32_T
  m_fTheta, tPOSlotType ePOSlotType, tPODir ePODir);

/* Function for MATLAB Function: '<Root>/SlotGroupDet' */
static void hmi_common_UpdatePrkOutDispPLD(tLSAD_SystemSts eLsadSystemSts,
  tSlotDisp sSlotGroup[12], real32_T m_fX_Coor, real32_T m_fY_Coor, real32_T
  m_fTheta, tPOSlotType ePOSlotType, tPODir ePODir)
{
  int32_T i;
  real32_T ChaX1;
  real32_T ChaX2;
  real32_T ChaX3;
  real32_T ChaY0;
  real32_T ChaY0_tmp;
  real32_T ChaY1;
  real32_T ChaY2;
  real32_T ChaY3;
  real32_T p_IN_tmp;
  if (eLsadSystemSts == LSAD_STS_PP)
  {
    hmi_common_DW.m_fX_Coor_PP = m_fX_Coor;
    hmi_common_DW.m_fY_Coor_PP = m_fY_Coor;
    hmi_common_DW.m_fTheta_PP = m_fTheta;
  }

  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)(((eLsadSystemSts ==
              LSAD_STS_PP) ? ((int32_T)1) : ((int32_T)0)) | ((eLsadSystemSts ==
              LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
         ((int32_T)0)) | ((eLsadSystemSts == LSAD_STS_ACTIVE_SUSPEND) ?
                          ((int32_T)1) : ((int32_T)0)))))
  {
    p_IN_tmp = sinf(hmi_common_DW.m_fTheta_PP);
    ChaY0 = cosf(hmi_common_DW.m_fTheta_PP);
    ChaX1 = m_fX_Coor - hmi_common_DW.m_fX_Coor_PP;
    ChaY1 = m_fY_Coor - hmi_common_DW.m_fY_Coor_PP;
    ChaY3 = (ChaY0 * ChaX1) + (p_IN_tmp * ChaY1);
    p_IN_tmp = ((-p_IN_tmp) * ChaX1) + (ChaY0 * ChaY1);

    /* trans cha coor */
    m_fTheta -= hmi_common_DW.m_fTheta_PP;
    switch (ePOSlotType)
    {
     case PO_SLOT_TYPE_PERPENDI:
      ChaY0 = sinf(m_fTheta);
      ChaX1 = cosf(m_fTheta);
      sSlotGroup[0].SlotX0 = ((4.6F - ChaY3) * ChaX1) + ((-1.25F - p_IN_tmp) *
        ChaY0);
      sSlotGroup[0].SlotY0 = ((4.6F - ChaY3) * (-ChaY0)) + ((-1.25F - p_IN_tmp) *
        ChaX1);
      sSlotGroup[0].SlotX1 = ((4.6F - ChaY3) * cosf(m_fTheta)) + ((1.25F -
        p_IN_tmp) * sinf(m_fTheta));
      ChaY0 = (1.25F - p_IN_tmp) * cosf(m_fTheta);
      sSlotGroup[0].SlotY1 = ((4.6F - ChaY3) * (-sinf(m_fTheta))) + ChaY0;
      ChaX3 = (-1.2F - ChaY3) * ChaX1;
      sSlotGroup[0].SlotX2 = ChaX3 + ((1.25F - p_IN_tmp) * sinf(m_fTheta));
      ChaY3 = (-1.2F - ChaY3) * (-sinf(m_fTheta));
      sSlotGroup[0].SlotY2 = ChaY3 + ChaY0;
      sSlotGroup[0].SlotX3 = ChaX3 + ((-1.25F - p_IN_tmp) * sinf(m_fTheta));
      sSlotGroup[0].SlotY3 = ChaY3 + ((-1.25F - p_IN_tmp) * ChaX1);
      sSlotGroup[0].u8SlotID = 1U;
      sSlotGroup[0].eDispSlotType = DISP_SLOT_TYP_PERPENDICULAR;
      sSlotGroup[0].eDispSlotStatus = SLOT_DISP_SELECTED;
      break;

     case PO_SLOT_TYPE_PARALLEL:
      if ((boolean_T)((int32_T)(((ePODir == PO_HEAD_DIR_LEFT) ? ((int32_T)1) :
             ((int32_T)0)) | ((ePODir == PO_TAIL_DIR_LEFT) ? ((int32_T)1) :
                              ((int32_T)0)))))
      {
        /* 车位的不一定对，先这样 */
        ChaX1 = (1.25F - p_IN_tmp) * sinf(m_fTheta);
        ChaY0 = cosf(m_fTheta);
        ChaX3 = (4.6F - ChaY3) * ChaY0;
        sSlotGroup[0].SlotX0 = ChaX3 + ChaX1;
        ChaY1 = (1.25F - p_IN_tmp) * ChaY0;
        ChaY0_tmp = (4.6F - ChaY3) * (-sinf(m_fTheta));
        ChaY0 = ChaY0_tmp + ChaY1;
        ChaX1 += (-1.2F - ChaY3) * cosf(m_fTheta);
        ChaY1 += (-1.2F - ChaY3) * (-sinf(m_fTheta));
        ChaX2 = ((-1.2F - ChaY3) * cosf(m_fTheta)) + ((-1.25F - p_IN_tmp) * sinf
          (m_fTheta));
        ChaY2 = ((-1.2F - ChaY3) * (-sinf(m_fTheta))) + ((-1.25F - p_IN_tmp) *
          cosf(m_fTheta));
        ChaX3 += (-1.25F - p_IN_tmp) * sinf(m_fTheta);
        ChaY3 = ChaY0_tmp + ((-1.25F - p_IN_tmp) * cosf(m_fTheta));
      }
      else
      {
        ChaX1 = sinf(m_fTheta);
        ChaX2 = cosf(m_fTheta);
        ChaY2 = (-1.25F - p_IN_tmp) * ChaX1;
        sSlotGroup[0].SlotX0 = ((4.6F - ChaY3) * ChaX2) + ChaY2;
        ChaY1 = (-1.25F - p_IN_tmp) * ChaX2;
        ChaY0 = ((4.6F - ChaY3) * (-ChaX1)) + ChaY1;
        ChaX1 = ((-1.2F - ChaY3) * ChaX2) + ChaY2;
        ChaY1 += (-1.2F - ChaY3) * (-sinf(m_fTheta));
        ChaX2 = ((-1.2F - ChaY3) * cosf(m_fTheta)) + ((1.25F - p_IN_tmp) * sinf
          (m_fTheta));
        ChaY2 = ((-1.2F - ChaY3) * (-sinf(m_fTheta))) + ((1.25F - p_IN_tmp) *
          cosf(m_fTheta));
        ChaX3 = ((4.6F - ChaY3) * cosf(m_fTheta)) + ((1.25F - p_IN_tmp) * sinf
          (m_fTheta));
        ChaY3 = ((4.6F - ChaY3) * (-sinf(m_fTheta))) + ((1.25F - p_IN_tmp) *
          cosf(m_fTheta));
      }

      sSlotGroup[0].SlotY0 = ChaY0;
      sSlotGroup[0].SlotX1 = ChaX1;
      sSlotGroup[0].SlotY1 = ChaY1;
      sSlotGroup[0].SlotX2 = ChaX2;
      sSlotGroup[0].SlotY2 = ChaY2;
      sSlotGroup[0].SlotX3 = ChaX3;
      sSlotGroup[0].SlotY3 = ChaY3;
      sSlotGroup[0].u8SlotID = 1U;
      sSlotGroup[0].eDispSlotType = DISP_SLOT_TYP_PARALLEL;
      sSlotGroup[0].eDispSlotStatus = SLOT_DISP_SELECTED;
      break;

     default:
      sSlotGroup[0].SlotX0 = 0.0F;
      sSlotGroup[0].SlotY0 = 0.0F;
      sSlotGroup[0].SlotX1 = 0.0F;
      sSlotGroup[0].SlotY1 = 0.0F;
      sSlotGroup[0].SlotX2 = 0.0F;
      sSlotGroup[0].SlotY2 = 0.0F;
      sSlotGroup[0].SlotX3 = 0.0F;
      sSlotGroup[0].SlotY3 = 0.0F;
      sSlotGroup[0].u8SlotID = 0U;
      sSlotGroup[0].eDispSlotType = DISP_SLOT_TYP_NO_REQ;
      sSlotGroup[0].eDispSlotStatus = SLOT_DISP_NO_REQ;
      break;
    }
  }
  else
  {
    for (i = 0; i < 12; i++)
    {
      sSlotGroup[i].SlotX0 = 0.0F;
      sSlotGroup[i].SlotY0 = 0.0F;
      sSlotGroup[i].SlotX1 = 0.0F;
      sSlotGroup[i].SlotY1 = 0.0F;
      sSlotGroup[i].SlotX2 = 0.0F;
      sSlotGroup[i].SlotY2 = 0.0F;
      sSlotGroup[i].SlotX3 = 0.0F;
      sSlotGroup[i].SlotY3 = 0.0F;
      sSlotGroup[i].u8SlotID = 0U;
      sSlotGroup[i].eDispSlotType = DISP_SLOT_TYP_NO_REQ;
      sSlotGroup[i].eDispSlotStatus = SLOT_DISP_NO_REQ;
    }
  }
}

/* System initialize for referenced model: 'hmi_common' */
void hmi_common_Init(void)
{
  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay1' */
  hmi_common_DW.UnitDelay1_DSTATE_i = SLOT_NOT_AVALIABLE;

  /* SystemInitialize for MATLAB Function: '<Root>/ADCS9PlotFitCalc' */
  hmi_common_DW.u16CurPathCnt = 0U;
  hmi_common_DW.IntVPAGuideLineA = 0.0F;
  hmi_common_DW.IntVPAGuideLineB = 0.0F;
  hmi_common_DW.IntVPAGuideLineC = 0.0F;
  hmi_common_DW.IntVPAGuideLineD = 0.0F;
  hmi_common_DW.IntVPAGuideLineXMin = 0.0F;
  hmi_common_DW.IntVPAGuideLineXMax = 0.0F;

  /* SystemInitialize for MATLAB Function: '<Root>/SlotGroupDet' */
  hmi_common_DW.m_fX_Coor_PP = 0.0F;
  hmi_common_DW.m_fY_Coor_PP = 0.0F;
  hmi_common_DW.m_fTheta_PP = 0.0F;

  /* SystemInitialize for MATLAB Function: '<Root>/PITypeDirDet' */
  hmi_common_DW.bitsForTID0.bIsDeterm = false;
  hmi_common_DW.PISlotLengthDelay = 0.0F;
}

/* Output and update for referenced model: 'hmi_common' */
void hmi_common(const tPaStateCommon *rtu_sPaStateCommon, const
                tRelatedModuleInfo *rtu_sRelatedModuleInfo, const tPAHmiRx
                *rtu_sPAHmiRx, const tPecpPLDInfo *rtu_tPecpPLDInfo, const
                tVehCommon *rtu_sVehCommon, const tMsgMnger_PathSegment
                *rtu_sPathSegment, const tPaStateAdptr *rtu_sPaStateAdptr, const
                tMasterLsadFsm *rtu_sMasterLsadFsm, const tSlaveLsadFsm
                *rtu_sSlaveLsadFsm, tHMIComDisp *rty_sHMIComDisp, DragParkingLot
                *rty_sDragParkingLot, tFusionDisp *rty_sFusionDisp)
{
  tParkLotInfo sPecpPLDInfo_stPLDs[20];
  real_T b_Index_data[40];
  real_T Index[20];
  real_T d[20];
  real_T cnt;
  real_T d_0;
  real_T dzero;
  int32_T iidx[20];
  int32_T e_i;
  int32_T i;
  int32_T k0;
  int32_T temp2_size_idx_1;
  real32_T P[4];
  real32_T P_X[4];
  real32_T P_Y[4];
  real32_T LocalVar_Switch1;
  real32_T LocalVar_Switch1_k;
  real32_T X0RgeThrsdLeftPER_tmp;
  real32_T X1RgeThrsdLeftOBL;
  real32_T X1RgeThrsdLeftOBL_tmp;
  real32_T X1RgeThrsdLeftPER_tmp;
  real32_T X1RgeThrsdLeftPLL_tmp;
  real32_T Y0RgeThrsdLeftPER_tmp;
  real32_T Y0RgeThrsdLeftPLL_tmp;
  real32_T Y2RgeThrsdLeftOBL;
  real32_T Y2RgeThrsdLeftPER;
  real32_T Y2RgeThrsdLeftPLL;
  real32_T Y2RgeThrsdRightOBL;
  real32_T Y2RgeThrsdRightPER;
  real32_T Y2RgeThrsdRightPLL;
  uint32_T tmp;
  int8_T mark[20];
  boolean_T b_b_data[20];
  boolean_T LocalVar_Equal2;
  boolean_T LocalVar_Equal4_c;
  boolean_T LocalVar_LogicalOperator3;
  boolean_T LocalVar_LogicalOperator3_c;
  boolean_T LocalVar_RelationalOperator_a;
  boolean_T LocalVar_RelationalOperator_g;
  boolean_T LocalVar_RelationalOperator_jj;
  boolean_T LocalVar_RelationalOperator_o;
  boolean_T LocalVar_Switch;
  boolean_T LocalVar_Switch_l;
  boolean_T exitg1;
  tDriverRequest LocalVar_eDriverRequest;

  /* MATLAB Function: '<Root>/ADCS9PlotFitCalc' */
  /*  初始化 */
  /*  /$ shift definition $/ */
  /*  enum EShiftType */
  /*  { */
  /*      SHIFT_NONE = 0, */
  /*      SHIFT_R    = 1, */
  /*      SHIFT_N    = 2, */
  /*      SHIFT_D    = 3, */
  /*      SHIFT_P    = 5 */
  /*  }; */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
               (((rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_PARK_IN) ?
                 ((int32_T)1) : ((int32_T)0)) |
                ((rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_PARK_OUT) ?
                 ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
            ((rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_SELF_SELECT) ?
             ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
        (((boolean_T)((int32_T)(((rtu_sMasterLsadFsm->eLsadSystemSts ==
              LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0)) |
            ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE_SUSPEND) ?
             ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)))))
  {
    if (((int32_T)hmi_common_DW.u16CurPathCnt) > 25)
    {
      hmi_common_DW.u16CurPathCnt = 0U;

      /* 500ms更新一次 */
    }
    else
    {
      tmp = ((uint32_T)hmi_common_DW.u16CurPathCnt) + 1U;
      if ((((uint32_T)hmi_common_DW.u16CurPathCnt) + 1U) > 65535U)
      {
        tmp = 65535U;
      }

      hmi_common_DW.u16CurPathCnt = (uint16_T)tmp;
    }

    if (((int32_T)rtu_sPathSegment->u8PathNum) >= 4)
    {
      if (((int32_T)hmi_common_DW.u16CurPathCnt) == 0)
      {
        P_X[0] = rtu_sPathSegment->stPathPoint[0].point.x;
        P_Y[0] = rtu_sPathSegment->stPathPoint[0].point.y;
        P_X[1] = rtu_sPathSegment->stPathPoint[1].point.x;
        P_Y[1] = rtu_sPathSegment->stPathPoint[1].point.y;
        P_X[2] = rtu_sPathSegment->stPathPoint[2].point.x;
        P_Y[2] = rtu_sPathSegment->stPathPoint[2].point.y;
        P_X[3] = rtu_sPathSegment->stPathPoint[3].point.x;
        P_Y[3] = rtu_sPathSegment->stPathPoint[3].point.y;
        polyfit_ZTjQ9uNU(P_X, P_Y, P);
        hmi_common_DW.IntVPAGuideLineA = P[0];
        hmi_common_DW.IntVPAGuideLineB = P[1];
        hmi_common_DW.IntVPAGuideLineC = P[2];
        hmi_common_DW.IntVPAGuideLineD = P[3];
        hmi_common_DW.IntVPAGuideLineXMin = 0.0F;
        switch (rtu_sPathSegment->u8Shift)
        {
         case 3:
          /* D */
          hmi_common_DW.IntVPAGuideLineXMax = 5.0F;
          break;

         case 1:
          /* R */
          hmi_common_DW.IntVPAGuideLineXMax = -3.0F;
          break;

         default:
          hmi_common_DW.IntVPAGuideLineXMax = 0.0F;
          break;
        }
      }
    }
    else
    {
      hmi_common_DW.IntVPAGuideLineA = 0.0F;
      hmi_common_DW.IntVPAGuideLineB = 0.0F;
      hmi_common_DW.IntVPAGuideLineC = 0.0F;
      hmi_common_DW.IntVPAGuideLineD = 0.0F;
      hmi_common_DW.IntVPAGuideLineXMin = 0.0F;
      hmi_common_DW.IntVPAGuideLineXMax = 0.0F;
    }
  }
  else
  {
    hmi_common_DW.IntVPAGuideLineA = 0.0F;
    hmi_common_DW.IntVPAGuideLineB = 0.0F;
    hmi_common_DW.IntVPAGuideLineC = 0.0F;
    hmi_common_DW.IntVPAGuideLineD = 0.0F;
    hmi_common_DW.IntVPAGuideLineXMin = 0.0F;
    hmi_common_DW.IntVPAGuideLineXMax = 0.0F;
  }

  /* MATLAB Function: '<Root>/SlotGroupDet' incorporates:
   *  MATLAB Function: '<Root>/ADCS9PlotFitCalc'
   *  UnitDelay: '<Root>/Unit Delay2'
   */
  /*  20 pick out 12 parking spaces ID list   */
  (void)memcpy(&rty_sFusionDisp->sSlotGroup[0],
               &hmi_common_DW.UnitDelay2_DSTATE[0], 12U * (sizeof(tSlotDisp)));
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
               ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
      ((int32_T)(((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_SEARCH) ?
      ((int32_T)1) : ((int32_T)0)) | ((rtu_sSlaveLsadFsm->eLsadFuncSts ==
      FUNC_STS_RPA_PI_SEARCH) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_CONFIRM)
    ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_PI_CONFIRM) ? ((int32_T)
      1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
                ((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_REMOTE_CONNECT)
                 ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
            | ((rtu_sSlaveLsadFsm->eLsadFuncSts ==
                FUNC_STS_APA_BACKGROUND_SEARCH) ? ((int32_T)1) : ((int32_T)0)))))
         ? ((int32_T)1) : ((int32_T)0)) & ((rtu_sPaStateAdptr->sCondiHMI.eAPAMod
          == APA_MODE_PARK_IN) ? ((int32_T)1) : ((int32_T)0)))))
  {
    dzero = 0.0;
    cnt = 0.0;

    /* 计算所有库位的距离 */
    for (i = 0; i < 20; i++)
    {
      mark[i] = 0;
      d[i] = (real_T)sqrtf((real32_T)(((real32_T)((float32)
        (rtu_tPecpPLDInfo->stPLDs[i].stPLDPoint[0].x * rtu_tPecpPLDInfo->
         stPLDs[i].stPLDPoint[0].x))) + ((real32_T)((float32)
        (rtu_tPecpPLDInfo->stPLDs[i].stPLDPoint[0].y * rtu_tPecpPLDInfo->
         stPLDs[i].stPLDPoint[0].y)))));
    }

    sort_sNVDfYYM(d, iidx);
    for (i = 0; i < 20; i++)
    {
      d_0 = d[i];
      e_i = iidx[i];

      /* 查找排序好的距离中前几个为0的距离，放到数组的最后面 */
      if ((d_0 == 0.0) && (cnt == 0.0))
      {
        dzero++;

        /* 如果距离没有0了开始处理把not avilible放后面 */
      }
      else if (d_0 <= ((real_T)k_ParkInSlotMemoDist))
      {
        if (rtu_tPecpPLDInfo->stPLDs[e_i - 1].stState ==
            PECP_PLD_STATE_Available)
        {
          cnt++;
          mark[((int32_T)cnt) - 1] = (int8_T)(i + 1);
        }
      }
      else
      {
        /* no actions */
      }

      Index[i] = (real_T)e_i;
    }

    circshift_Oao1VbEW(Index, -dzero);
    if (1.0 > cnt)
    {
      k0 = -1;
    }
    else
    {
      k0 = ((int32_T)cnt) - 1;
    }

    for (i = 0; i <= k0; i++)
    {
      iidx[i] = (int32_T)((real_T)(((real_T)mark[i]) - dzero));
    }

    for (i = 0; i < 20; i++)
    {
      d[i] = Index[i];
      b_b_data[i] = false;
    }

    for (i = 0; i <= k0; i++)
    {
      b_b_data[iidx[i] - 1] = true;
    }

    e_i = 0;
    k0 = -1;
    for (i = 0; i < 20; i++)
    {
      LocalVar_RelationalOperator_a = b_b_data[i];
      e_i += LocalVar_RelationalOperator_a ? ((int32_T)1) : ((int32_T)0);
      if ((boolean_T)((int32_T)((LocalVar_RelationalOperator_a ? ((int32_T)1) :
             ((int32_T)0)) ^ 1)))
      {
        k0++;
        d[k0] = d[i];
      }
    }

    if (1 > (20 - e_i))
    {
      temp2_size_idx_1 = 0;
    }
    else
    {
      temp2_size_idx_1 = 20 - e_i;
    }

    if (1.0 > cnt)
    {
      i = -1;
      e_i = -1;
    }
    else
    {
      i = ((int32_T)cnt) - 1;
      e_i = ((int32_T)cnt) - 1;
    }

    k0 = e_i + 1;
    for (e_i = 0; e_i < k0; e_i++)
    {
      b_Index_data[e_i] = Index[((int32_T)((real_T)(((real_T)mark[e_i]) - dzero)))
        - 1];
    }

    for (e_i = 0; e_i < temp2_size_idx_1; e_i++)
    {
      b_Index_data[(e_i + i) + 1] = d[e_i];
    }

    for (i = 0; i < 20; i++)
    {
      sPecpPLDInfo_stPLDs[i] = rtu_tPecpPLDInfo->stPLDs[((int32_T)b_Index_data[i])
        - 1];
    }

    for (e_i = 1; (e_i - 1) < ((int32_T)k_SelectSlotNum); e_i++)
    {
      /* 对有效车位赋值 */
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].SlotX0 =
        (real32_T)sPecpPLDInfo_stPLDs[((int32_T)((uint8_T)e_i)) - 1].stPLDPoint
        [0].x;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].SlotY0 =
        (real32_T)sPecpPLDInfo_stPLDs[((int32_T)((uint8_T)e_i)) - 1].stPLDPoint
        [0].y;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].SlotX1 =
        (real32_T)sPecpPLDInfo_stPLDs[((int32_T)((uint8_T)e_i)) - 1].stPLDPoint
        [1].x;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].SlotY1 =
        (real32_T)sPecpPLDInfo_stPLDs[((int32_T)((uint8_T)e_i)) - 1].stPLDPoint
        [1].y;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].SlotX2 =
        (real32_T)sPecpPLDInfo_stPLDs[((int32_T)((uint8_T)e_i)) - 1].stPLDPoint
        [2].x;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].SlotY2 =
        (real32_T)sPecpPLDInfo_stPLDs[((int32_T)((uint8_T)e_i)) - 1].stPLDPoint
        [2].y;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].SlotX3 =
        (real32_T)sPecpPLDInfo_stPLDs[((int32_T)((uint8_T)e_i)) - 1].stPLDPoint
        [3].x;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].SlotY3 =
        (real32_T)sPecpPLDInfo_stPLDs[((int32_T)((uint8_T)e_i)) - 1].stPLDPoint
        [3].y;
      if (sPecpPLDInfo_stPLDs[((int32_T)((uint8_T)e_i)) - 1].s32ParkLotID == 0)
      {
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].
          eDispSlotStatus = SLOT_DISP_NO_REQ;
      }
      else if ((sPecpPLDInfo_stPLDs[((int32_T)((uint8_T)e_i)) - 1].stState ==
                PECP_PLD_STATE_Available) && (sPecpPLDInfo_stPLDs[((int32_T)
                 ((uint8_T)e_i)) - 1].s32ParkLotID ==
                rtu_tPecpPLDInfo->s32SuggestParkID))
      {
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].
          eDispSlotStatus = SLOT_DISP_SELECTED;
      }
      else if ((sPecpPLDInfo_stPLDs[((int32_T)((uint8_T)e_i)) - 1].stState ==
                PECP_PLD_STATE_Available) && (sPecpPLDInfo_stPLDs[((int32_T)
                 ((uint8_T)e_i)) - 1].s32ParkLotID !=
                rtu_tPecpPLDInfo->s32SuggestParkID))
      {
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].
          eDispSlotStatus = SLOT_DISP_AVAILABLE;
      }
      else if (sPecpPLDInfo_stPLDs[((int32_T)((uint8_T)e_i)) - 1].stState ==
               PECP_PLD_STATE_UnAvailable)
      {
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].
          eDispSlotStatus = SLOT_DISP_UNAVAILABLE;
      }
      else
      {
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].
          eDispSlotStatus = SLOT_DISP_UNKNOWN;
      }

      switch (sPecpPLDInfo_stPLDs[((int32_T)((uint8_T)e_i)) - 1].stType)
      {
       case PECP_PLD_TYPE_Horizontal:
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].eDispSlotType
          = DISP_SLOT_TYP_PARALLEL;
        break;

       case PECP_PLD_TYPE_SPACE_Horizontal:
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].eDispSlotType
          = DISP_SLOT_TYP_PARALLEL;
        break;

       case PECP_PLD_TYPE_Vertical:
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].eDispSlotType
          = DISP_SLOT_TYP_PERPENDICULAR;
        break;

       case PECP_PLD_TYPE_SPACE_Vertical:
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].eDispSlotType
          = DISP_SLOT_TYP_PERPENDICULAR;
        break;

       case PECP_PLD_TYPE_ThreeDimensional:
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].eDispSlotType
          = DISP_SLOT_TYP_PERPENDICULAR;
        break;

       case PECP_PLD_TYPE_Oblique_30:
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].eDispSlotType
          = DISP_SLOT_TYP_OBLIQUE;
        break;

       case PECP_PLD_TYPE_Oblique_45:
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].eDispSlotType
          = DISP_SLOT_TYP_OBLIQUE;
        break;

       case PECP_PLD_TYPE_Oblique_60:
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].eDispSlotType
          = DISP_SLOT_TYP_OBLIQUE;
        break;

       case PECP_PLD_TYPE_SPACE_Oblique:
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].eDispSlotType
          = DISP_SLOT_TYP_OBLIQUE;
        break;

       default:
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].eDispSlotType
          = DISP_SLOT_TYP_NO_REQ;
        break;
      }

      /*      if sPecpPLDInfoUpInp.stPLDs(i).stType == PECP_PLD_TYPE.PECP_PLD_TYPE_Horizontal || sPecpPLDInfoUpInp.stPLDs(i).stType == PECP_PLD_TYPE.PECP_PLD_TYPE_Vertical || ... */
      /*              sPecpPLDInfoUpInp.stPLDs(i).stType == PECP_PLD_TYPE.PECP_PLD_TYPE_Oblique_30 || sPecpPLDInfoUpInp.stPLDs(i).stType == PECP_PLD_TYPE.PECP_PLD_TYPE_Oblique_45 || ... */
      /*              sPecpPLDInfoUpInp.stPLDs(i).stType == PECP_PLD_TYPE.PECP_PLD_TYPE_Oblique_60 */
      /*          sSlotGroup(i).eDispSlotSubType = tDispSlotSubType.DISP_SLOT_SUB_TYP_MARKED; */
      /*      elseif  sPecpPLDInfoUpInp.stPLDs(i).stType == PECP_PLD_TYPE.PECP_PLD_TYPE_SPACE_Horizontal || sPecpPLDInfoUpInp.stPLDs(i).stType == PECP_PLD_TYPE.PECP_PLD_TYPE_SPACE_Vertical || ... */
      /*              sPecpPLDInfoUpInp.stPLDs(i).stType == PECP_PLD_TYPE.PECP_PLD_TYPE_SPACE_Oblique */
      /*          sSlotGroup(i).eDispSlotSubType = tDispSlotSubType.DISP_SLOT_SUB_TYP_SPATIAL; */
      /*      elseif sPecpPLDInfoUpInp.stPLDs(i).stType == PECP_PLD_TYPE.PECP_PLD_TYPE_ThreeDimensional */
      /*          sSlotGroup(i).eDispSlotSubType = tDispSlotSubType.DISP_SLOT_SUB_TYP_MECHANICAL; */
      /*      else */
      /*          sSlotGroup(i).eDispSlotSubType = tDispSlotSubType.DISP_SLOT_SUB_TYP_MARKED; */
      /*      end    */
      i = sPecpPLDInfo_stPLDs[((int32_T)((uint8_T)e_i)) - 1].s32ParkLotID;
      if (i < 0)
      {
        i = 0;
      }
      else if (i > 255)
      {
        i = 255;
      }
      else
      {
        /* no actions */
      }

      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].u8SlotID =
        (uint8_T)i;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].
        u8SlotConfidence = sPecpPLDInfo_stPLDs[((int32_T)((uint8_T)e_i)) - 1].
        u8confidence;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].u8ParkFrontRear
        = 1U;

      /* 0: rear park in   1: head park in */
    }
  }
  else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)(((rtu_sMasterLsadFsm->eLsadSystemSts ==
      LSAD_STS_HANDSHAKE) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ? ((int32_T)1) :
      ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ? ((int32_T)1) :
      ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE_SUSPEND) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_TERMINATED) ? ((int32_T)1)
       : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
       ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_COMPLETE) ? ((int32_T)1)
        : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
      ((rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_PARK_IN) ? ((int32_T)1)
       : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
             ((rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_SELF_SELECT) ?
              ((int32_T)1) : ((int32_T)0)))))
  {
    /* 泊车过程中透传平台库位 */
    for (e_i = 1; (e_i - 1) < ((int32_T)k_SelectSlotNum); e_i++)
    {
      /* 对有效车位赋值 */
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].SlotX0 =
        (real32_T)rtu_tPecpPLDInfo->stPLDs[((int32_T)((uint8_T)e_i)) - 1].
        stPLDPoint[0].x;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].SlotY0 =
        (real32_T)rtu_tPecpPLDInfo->stPLDs[((int32_T)((uint8_T)e_i)) - 1].
        stPLDPoint[0].y;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].SlotX1 =
        (real32_T)rtu_tPecpPLDInfo->stPLDs[((int32_T)((uint8_T)e_i)) - 1].
        stPLDPoint[1].x;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].SlotY1 =
        (real32_T)rtu_tPecpPLDInfo->stPLDs[((int32_T)((uint8_T)e_i)) - 1].
        stPLDPoint[1].y;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].SlotX2 =
        (real32_T)rtu_tPecpPLDInfo->stPLDs[((int32_T)((uint8_T)e_i)) - 1].
        stPLDPoint[2].x;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].SlotY2 =
        (real32_T)rtu_tPecpPLDInfo->stPLDs[((int32_T)((uint8_T)e_i)) - 1].
        stPLDPoint[2].y;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].SlotX3 =
        (real32_T)rtu_tPecpPLDInfo->stPLDs[((int32_T)((uint8_T)e_i)) - 1].
        stPLDPoint[3].x;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].SlotY3 =
        (real32_T)rtu_tPecpPLDInfo->stPLDs[((int32_T)((uint8_T)e_i)) - 1].
        stPLDPoint[3].y;
      if (((rtu_tPecpPLDInfo->stPLDs[((int32_T)((uint8_T)e_i)) - 1].stState ==
            PECP_PLD_STATE_Available) && (rtu_tPecpPLDInfo->stPLDs[((int32_T)
             ((uint8_T)e_i)) - 1].s32ParkLotID ==
            rtu_tPecpPLDInfo->s32SuggestParkID)) &&
          (rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_PARK_IN))
      {
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].
          eDispSlotStatus = SLOT_DISP_SELECTED;
        switch (rtu_tPecpPLDInfo->stPLDs[((int32_T)((uint8_T)e_i)) - 1].stType)
        {
         case PECP_PLD_TYPE_Horizontal:
          rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].
            eDispSlotType = DISP_SLOT_TYP_PARALLEL;
          break;

         case PECP_PLD_TYPE_SPACE_Horizontal:
          rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].
            eDispSlotType = DISP_SLOT_TYP_PARALLEL;
          break;

         case PECP_PLD_TYPE_Vertical:
          rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].
            eDispSlotType = DISP_SLOT_TYP_PERPENDICULAR;
          break;

         case PECP_PLD_TYPE_SPACE_Vertical:
          rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].
            eDispSlotType = DISP_SLOT_TYP_PERPENDICULAR;
          break;

         case PECP_PLD_TYPE_ThreeDimensional:
          rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].
            eDispSlotType = DISP_SLOT_TYP_PERPENDICULAR;
          break;

         case PECP_PLD_TYPE_Oblique_30:
          rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].
            eDispSlotType = DISP_SLOT_TYP_OBLIQUE;
          break;

         case PECP_PLD_TYPE_Oblique_45:
          rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].
            eDispSlotType = DISP_SLOT_TYP_OBLIQUE;
          break;

         case PECP_PLD_TYPE_Oblique_60:
          rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].
            eDispSlotType = DISP_SLOT_TYP_OBLIQUE;
          break;

         case PECP_PLD_TYPE_SPACE_Oblique:
          rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].
            eDispSlotType = DISP_SLOT_TYP_OBLIQUE;
          break;

         default:
          rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].
            eDispSlotType = DISP_SLOT_TYP_NO_REQ;
          break;
        }

        i = rtu_tPecpPLDInfo->stPLDs[((int32_T)((uint8_T)e_i)) - 1].s32ParkLotID;
        if (i < 0)
        {
          i = 0;
        }
        else if (i > 255)
        {
          i = 255;
        }
        else
        {
          /* no actions */
        }

        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].u8SlotID =
          (uint8_T)i;
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].
          u8SlotConfidence = rtu_tPecpPLDInfo->stPLDs[((int32_T)((uint8_T)e_i))
          - 1].u8confidence;
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].
          u8ParkFrontRear = 1U;
      }
      else
      {
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].SlotX0 = 0.0F;
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].SlotY0 = 0.0F;
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].SlotX1 = 0.0F;
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].SlotY1 = 0.0F;
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].SlotX2 = 0.0F;
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].SlotY2 = 0.0F;
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].SlotX3 = 0.0F;
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].SlotY3 = 0.0F;
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].u8SlotID = 0U;
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].eDispSlotType
          = DISP_SLOT_TYP_NO_REQ;
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].
          eDispSlotStatus = SLOT_DISP_NO_REQ;
        rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)e_i)) - 1].
          eDispSlotSubType = DISP_SLOT_SUB_TYP_MARKED;
      }
    }
  }
  else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      (((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_HANDSHAKE) ? ((int32_T)1)
    : ((int32_T)0)) | ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_PP) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ? ((int32_T)1) :
      ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE_SUSPEND) ?
       ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
       ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_TERMINATED) ? ((int32_T)
      1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
      ((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_COMPLETE) ? ((int32_T)1) :
       ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
             ((rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_PARK_OUT) ?
              ((int32_T)1) : ((int32_T)0)))))
  {
    hmi_common_UpdatePrkOutDispPLD(rtu_sMasterLsadFsm->eLsadSystemSts,
      rty_sFusionDisp->sSlotGroup, rtu_sRelatedModuleInfo->f32X_Coor,
      rtu_sRelatedModuleInfo->f32Y_Coor, rtu_sRelatedModuleInfo->f32Theta,
      rtu_sPaStateAdptr->sCondiHMI.ePOSlotType,
      rtu_sPaStateAdptr->sCondiHMI.ePODir);
  }
  else
  {
    for (i = 1; (i - 1) < ((int32_T)k_SelectSlotNum); i++)
    {
      /* initialized value */
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)i)) - 1].SlotX0 = 0.0F;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)i)) - 1].SlotY0 = 0.0F;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)i)) - 1].SlotX1 = 0.0F;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)i)) - 1].SlotY1 = 0.0F;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)i)) - 1].SlotX2 = 0.0F;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)i)) - 1].SlotY2 = 0.0F;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)i)) - 1].SlotX3 = 0.0F;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)i)) - 1].SlotY3 = 0.0F;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)i)) - 1].u8SlotID = 0U;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)i)) - 1].eDispSlotType =
        DISP_SLOT_TYP_NO_REQ;
      rty_sFusionDisp->sSlotGroup[((int32_T)((uint8_T)i)) - 1].eDispSlotStatus =
        SLOT_DISP_NO_REQ;
    }
  }

  /* End of MATLAB Function: '<Root>/SlotGroupDet' */

  /* MATLAB Function: '<Root>/PITypeDirDet' incorporates:
   *  MATLAB Function: '<Root>/ADCS9PlotFitCalc'
   *  UnitDelay: '<Root>/Unit Delay4'
   *  UnitDelay: '<Root>/Unit Delay5'
   */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
           (((rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ? ((int32_T)
              1) : ((int32_T)0)) & (((boolean_T)((int32_T)
               ((hmi_common_DW.bitsForTID0.bIsDeterm ? ((int32_T)1) : ((int32_T)
      0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
        & (((boolean_T)((int32_T)(((rtu_sPaStateAdptr->sCondiHMI.eAPAMod ==
              APA_MODE_PARK_IN) ? ((int32_T)1) : ((int32_T)0)) |
            ((rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_SELF_SELECT) ?
             ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)))))
  {
    /* 泊车过程中透传平台库位 */
    hmi_common_DW.UnitDelay4_DSTATE_d = PI_SLOT_TYPE_NONE;
    hmi_common_DW.UnitDelay5_DSTATE = PI_DIR_NO_REQ;
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 8))
    {
      if (rty_sFusionDisp->sSlotGroup[i].eDispSlotStatus == SLOT_DISP_SELECTED)
      {
        /*  %% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
        switch (rty_sFusionDisp->sSlotGroup[i].eDispSlotType)
        {
         case DISP_SLOT_TYP_PARALLEL:
          hmi_common_DW.UnitDelay4_DSTATE_d = PI_SLOT_TYPE_PARALLEL;
          break;

         case DISP_SLOT_TYP_OBLIQUE:
          hmi_common_DW.UnitDelay4_DSTATE_d = PI_SLOT_TYPE_OBLIQUE;
          break;

         case DISP_SLOT_TYP_PERPENDICULAR:
          hmi_common_DW.UnitDelay4_DSTATE_d = PI_SLOT_TYPE_PERPENDI;
          break;

         default:
          hmi_common_DW.UnitDelay4_DSTATE_d = PI_SLOT_TYPE_NONE;
          break;
        }

        if (rty_sFusionDisp->sSlotGroup[i].SlotY0 < 0.0F)
        {
          if (rty_sFusionDisp->sSlotGroup[i].SlotY1 < 0.0F)
          {
            if (rty_sFusionDisp->sSlotGroup[i].SlotY2 < 0.0F)
            {
              if (rty_sFusionDisp->sSlotGroup[i].SlotY3 < 0.0F)
              {
                hmi_common_DW.UnitDelay5_DSTATE = PI_DIR_RIGHT;
              }
              else
              {
                hmi_common_DW.UnitDelay5_DSTATE = PI_DIR_LEFT;
              }
            }
            else
            {
              hmi_common_DW.UnitDelay5_DSTATE = PI_DIR_LEFT;
            }
          }
          else
          {
            hmi_common_DW.UnitDelay5_DSTATE = PI_DIR_LEFT;
          }
        }
        else
        {
          hmi_common_DW.UnitDelay5_DSTATE = PI_DIR_LEFT;
        }

        hmi_common_DW.PISlotLengthDelay = fabsf(rty_sFusionDisp->sSlotGroup[i].
          SlotX1 - rty_sFusionDisp->sSlotGroup[i].SlotX0);
        hmi_common_DW.bitsForTID0.bIsDeterm = true;
        exitg1 = true;
      }
      else
      {
        i++;
      }
    }
  }
  else if (rtu_sMasterLsadFsm->eLsadSystemSts == LSAD_STS_STANDBY)
  {
    hmi_common_DW.UnitDelay4_DSTATE_d = PI_SLOT_TYPE_NONE;
    hmi_common_DW.UnitDelay5_DSTATE = PI_DIR_NO_REQ;
    hmi_common_DW.PISlotLengthDelay = 0.0F;
    hmi_common_DW.bitsForTID0.bIsDeterm = false;
  }
  else
  {
    hmi_common_DW.PISlotLengthDelay = 0.0F;
  }

  /* MATLAB Function: '<Root>/eSlotAvaliabDet' incorporates:
   *  UnitDelay: '<Root>/Unit Delay1'
   */
  /* 斜列左侧可泊车区域 */
  X1RgeThrsdLeftOBL = s_VehLength - s_VehRearToRAxis;
  LocalVar_Switch1 = X1RgeThrsdLeftOBL + s_PlatSlotRgeLAddOBL;
  LocalVar_Switch1_k = (s_VehWidth / 2.0F) + s_PlatSlotRgeWAddOBL;
  X1RgeThrsdLeftOBL_tmp = LocalVar_Switch1 - s_PlatSlotRgeLenOBL;
  Y2RgeThrsdLeftOBL = LocalVar_Switch1_k + s_PlatSlotRgeWidOBL;

  /* 斜列右侧可泊车区域 */
  Y2RgeThrsdRightOBL = (-LocalVar_Switch1_k) - s_PlatSlotRgeWidOBL;

  /* 垂直左侧可泊车区域 */
  X0RgeThrsdLeftPER_tmp = X1RgeThrsdLeftOBL + s_PlatSlotRgeLAddPER;
  Y0RgeThrsdLeftPER_tmp = (s_VehWidth / 2.0F) + s_PlatSlotRgeWAddPER;
  X1RgeThrsdLeftPER_tmp = X0RgeThrsdLeftPER_tmp - s_PlatSlotRgeLenPER;
  Y2RgeThrsdLeftPER = Y0RgeThrsdLeftPER_tmp + s_PlatSlotRgeWidPER;

  /* 垂直右侧可泊车区域 */
  Y2RgeThrsdRightPER = (-Y0RgeThrsdLeftPER_tmp) - s_PlatSlotRgeWidPER;

  /* 水平左侧可泊车区域 */
  X1RgeThrsdLeftOBL += s_PlatSlotRgeLAddPLL;
  Y0RgeThrsdLeftPLL_tmp = (s_VehWidth / 2.0F) + s_PlatSlotRgeWAddPLL;
  X1RgeThrsdLeftPLL_tmp = X1RgeThrsdLeftOBL - s_PlatSlotRgeLenPLL;
  Y2RgeThrsdLeftPLL = Y0RgeThrsdLeftPLL_tmp + s_PlatSlotRgeWidPLL;

  /* 水平右侧可泊车区域 */
  Y2RgeThrsdRightPLL = (-Y0RgeThrsdLeftPLL_tmp) - s_PlatSlotRgeWidPLL;
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
               (((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_CONFIRM) ?
                 ((int32_T)1) : ((int32_T)0)) &
                ((rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_SELF_SELECT) ?
                 ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
            & ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX0 > -15.0F) ?
               ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
        ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX0 < 15.0F) ? ((int32_T)1) :
         ((int32_T)0)))))
  {
    switch (rtu_sPaStateAdptr->sCondiHMI.eDragSlotType)
    {
     case DRAG_SLOT_TYPE_PERPENDI:
      if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
                   ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
          ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
          (((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY0 >
          Y0RgeThrsdLeftPER_tmp) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX0 < X0RgeThrsdLeftPER_tmp)
        ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY1 > Y0RgeThrsdLeftPER_tmp)
        ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX1 > X1RgeThrsdLeftPER_tmp)
        ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY2 < Y2RgeThrsdLeftPER) ?
          ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX2 > X1RgeThrsdLeftPER_tmp)
           ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
                    ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY3 <
                      Y2RgeThrsdLeftPER) ? ((int32_T)1) : ((int32_T)0))))) ?
                 ((int32_T)1) : ((int32_T)0)) &
                ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX3 <
                  X0RgeThrsdLeftPER_tmp) ? ((int32_T)1) : ((int32_T)0))))) ?
             ((int32_T)1) : ((int32_T)0)) &
            ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY3 > 0.1F) ? ((int32_T)1)
             : ((int32_T)0)))))
      {
        /* Slot on the Lest side of the car */
        hmi_common_DW.UnitDelay1_DSTATE_i = SLOT_AVALIABLE;
      }
      else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
          ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
          ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
          ((int32_T)(((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY0 <
          (-Y0RgeThrsdLeftPER_tmp)) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX0 < X0RgeThrsdLeftPER_tmp)
        ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY1 <
          (-Y0RgeThrsdLeftPER_tmp)) ? ((int32_T)1) : ((int32_T)0))))) ?
          ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX1 > X1RgeThrsdLeftPER_tmp)
        ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
           ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY2 > Y2RgeThrsdRightPER) ?
        ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX2 > X1RgeThrsdLeftPER_tmp)
           ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
                     ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY3 >
                       Y2RgeThrsdRightPER) ? ((int32_T)1) : ((int32_T)0))))) ?
          ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX3 < X0RgeThrsdLeftPER_tmp)
           ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
                 ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY3 < -0.1F) ?
                  ((int32_T)1) : ((int32_T)0)))))
      {
        /* Slot on the Right side of the car */
        hmi_common_DW.UnitDelay1_DSTATE_i = SLOT_AVALIABLE;
      }
      else
      {
        hmi_common_DW.UnitDelay1_DSTATE_i = SLOT_NOT_AVALIABLE;
      }
      break;

     case DRAG_SLOT_TYPE_OBLIQUE:
      if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
                   ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
          ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
          (((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY0 > LocalVar_Switch1_k) ?
        ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX0 < LocalVar_Switch1) ?
          ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY1 > LocalVar_Switch1_k) ?
        ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX1 > X1RgeThrsdLeftOBL_tmp)
        ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY2 < Y2RgeThrsdLeftOBL) ?
          ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX2 > X1RgeThrsdLeftOBL_tmp)
           ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
                    ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY3 <
                      Y2RgeThrsdLeftOBL) ? ((int32_T)1) : ((int32_T)0))))) ?
                 ((int32_T)1) : ((int32_T)0)) &
                ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX3 <
                  LocalVar_Switch1) ? ((int32_T)1) : ((int32_T)0))))) ?
             ((int32_T)1) : ((int32_T)0)) &
            ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY3 > 0.1F) ? ((int32_T)1)
             : ((int32_T)0)))))
      {
        /* Slot on the Lest side of the car() */
        hmi_common_DW.UnitDelay1_DSTATE_i = SLOT_AVALIABLE;
      }
      else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
          ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
          ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
          ((int32_T)(((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY0 <
          (-LocalVar_Switch1_k)) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX0 < LocalVar_Switch1) ?
          ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY1 < (-LocalVar_Switch1_k))
        ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX1 > X1RgeThrsdLeftOBL_tmp)
        ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
           ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY2 > Y2RgeThrsdRightOBL) ?
        ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX2 > X1RgeThrsdLeftOBL_tmp)
           ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
                     ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY3 >
                       Y2RgeThrsdRightOBL) ? ((int32_T)1) : ((int32_T)0))))) ?
          ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX3 < LocalVar_Switch1) ?
           ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
                 ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY3 < -0.1F) ?
                  ((int32_T)1) : ((int32_T)0)))))
      {
        /* Slot on the Right side of the car */
        hmi_common_DW.UnitDelay1_DSTATE_i = SLOT_AVALIABLE;
      }
      else
      {
        hmi_common_DW.UnitDelay1_DSTATE_i = SLOT_NOT_AVALIABLE;
      }
      break;

     case DRAG_SLOT_TYPE_PARALLEL:
      if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
                   ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
          ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
          (((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY0 >
          Y0RgeThrsdLeftPLL_tmp) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX0 < X1RgeThrsdLeftOBL) ?
          ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY1 > Y0RgeThrsdLeftPLL_tmp)
        ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX1 > X1RgeThrsdLeftPLL_tmp)
        ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY2 < Y2RgeThrsdLeftPLL) ?
          ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX2 > X1RgeThrsdLeftPLL_tmp)
           ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
                    ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY3 <
                      Y2RgeThrsdLeftPLL) ? ((int32_T)1) : ((int32_T)0))))) ?
                 ((int32_T)1) : ((int32_T)0)) &
                ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX3 <
                  X1RgeThrsdLeftOBL) ? ((int32_T)1) : ((int32_T)0))))) ?
             ((int32_T)1) : ((int32_T)0)) &
            ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY3 > 0.1F) ? ((int32_T)1)
             : ((int32_T)0)))))
      {
        hmi_common_DW.UnitDelay1_DSTATE_i = SLOT_AVALIABLE;
      }
      else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
          ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
          ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
          ((int32_T)(((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY0 <
          (-Y0RgeThrsdLeftPLL_tmp)) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX0 < X1RgeThrsdLeftOBL) ?
          ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY1 <
          (-Y0RgeThrsdLeftPLL_tmp)) ? ((int32_T)1) : ((int32_T)0))))) ?
          ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX1 > X1RgeThrsdLeftPLL_tmp)
        ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
           ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY2 > Y2RgeThrsdRightPLL) ?
        ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX2 > X1RgeThrsdLeftPLL_tmp)
           ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
                     ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY3 >
                       Y2RgeThrsdRightPLL) ? ((int32_T)1) : ((int32_T)0))))) ?
          ((int32_T)1) : ((int32_T)0)) &
          ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX3 < X1RgeThrsdLeftOBL) ?
           ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
                 ((rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY3 < -0.1F) ?
                  ((int32_T)1) : ((int32_T)0)))))
      {
        hmi_common_DW.UnitDelay1_DSTATE_i = SLOT_AVALIABLE;
      }
      else
      {
        hmi_common_DW.UnitDelay1_DSTATE_i = SLOT_NOT_AVALIABLE;
      }
      break;

     default:
      hmi_common_DW.UnitDelay1_DSTATE_i = SLOT_NOT_AVALIABLE;
      break;
    }
  }
  else if (rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_STANDBY)
  {
    hmi_common_DW.UnitDelay1_DSTATE_i = SLOT_NOT_AVALIABLE;
  }
  else
  {
    /* no actions */
  }

  /* End of MATLAB Function: '<Root>/eSlotAvaliabDet' */

  /* MATLAB Function: '<Root>/DriverRequestDet' incorporates:
   *  MATLAB Function: '<Root>/ADCS9PlotFitCalc'
   *  UnitDelay: '<Root>/Unit Delay'
   *  UnitDelay: '<Root>/Unit Delay1'
   */
  switch (rtu_sMasterLsadFsm->eLsadSystemSts)
  {
   case LSAD_STS_PREPARE:
    switch (rtu_sSlaveLsadFsm->eLsadFuncSts)
    {
     case FUNC_STS_APA_PI_SEARCH:
      if (rtu_sRelatedModuleInfo->eDataFusionSts == APA_DF_BERTH)
      {
        LocalVar_eDriverRequest = DRIVER_STOP_TO_SELECT_PS;
      }
      else
      {
        LocalVar_eDriverRequest = DRIVER_SEARCH_PS;
      }
      break;

     case FUNC_STS_APA_PI_CONFIRM:
      if ((boolean_T)((int32_T)(((rtu_sPaStateAdptr->sCondiHMI.ePrkFnct ==
              PARK_FUNC_APA) ? ((int32_T)1) : ((int32_T)0)) &
            ((rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_PARK_IN) ?
             ((int32_T)1) : ((int32_T)0)))))
      {
        LocalVar_eDriverRequest = DRIVER_SELECT_PS_AND_CONFIRM;
      }
      else if (rtu_sPaStateAdptr->sCondiHMI.ePrkFnct == PARK_FUNC_RPA)
      {
        LocalVar_eDriverRequest = DRIVER_PRESS_DMS_TO_START;
      }
      else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                    (((rtu_sPaStateAdptr->sCondiHMI.ePrkFnct == PARK_FUNC_APA) ?
                      ((int32_T)1) : ((int32_T)0)) &
                     ((rtu_sPaStateAdptr->sCondiHMI.eAPAMod ==
                       APA_MODE_SELF_SELECT) ? ((int32_T)1) : ((int32_T)0))))) ?
                  ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
                    ((rtu_sPaStateAdptr->sCondiHMI.bHmiSelfSelTypeSelected ?
                      ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) :
                  ((int32_T)0)))))
      {
        LocalVar_eDriverRequest = DRIVER_SELECT_VIR_PS_TYPE;
      }
      else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
          ((int32_T)(((rtu_sPaStateAdptr->sCondiHMI.ePrkFnct == PARK_FUNC_APA) ?
                      ((int32_T)1) : ((int32_T)0)) &
                     ((rtu_sPaStateAdptr->sCondiHMI.eAPAMod ==
                       APA_MODE_SELF_SELECT) ? ((int32_T)1) : ((int32_T)0))))) ?
        ((int32_T)1) : ((int32_T)0)) &
          (rtu_sPaStateAdptr->sCondiHMI.bHmiSelfSelTypeSelected ? ((int32_T)1) :
           ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
                 ((hmi_common_DW.UnitDelay1_DSTATE_i != SLOT_AVALIABLE) ?
                  ((int32_T)1) : ((int32_T)0)))))
      {
        LocalVar_eDriverRequest = DRIVER_ADJUST_VIR_PS;
      }
      else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
          ((int32_T)(((rtu_sPaStateAdptr->sCondiHMI.ePrkFnct == PARK_FUNC_APA) ?
                      ((int32_T)1) : ((int32_T)0)) &
                     ((rtu_sPaStateAdptr->sCondiHMI.eAPAMod ==
                       APA_MODE_SELF_SELECT) ? ((int32_T)1) : ((int32_T)0))))) ?
        ((int32_T)1) : ((int32_T)0)) &
          (rtu_sPaStateAdptr->sCondiHMI.bHmiSelfSelTypeSelected ? ((int32_T)1) :
           ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
                 ((hmi_common_DW.UnitDelay1_DSTATE_i == SLOT_AVALIABLE) ?
                  ((int32_T)1) : ((int32_T)0)))))
      {
        LocalVar_eDriverRequest = DRIVER_CONFIRM_VIR_PS;
      }
      else
      {
        LocalVar_eDriverRequest = DRIVER_NO_REQ;
      }
      break;

     case FUNC_STS_APA_PO_CONFIRM:
      if ((boolean_T)((int32_T)(((rtu_sPaStateAdptr->sCondiHMI.ePOSlotType ==
              PO_SLOT_TYPE_NONE) ? ((int32_T)1) : ((int32_T)0)) |
            ((rtu_sPaStateAdptr->sCondiHMI.ePODir == PO_DIR_NO_REQ) ? ((int32_T)
              1) : ((int32_T)0)))))
      {
        LocalVar_eDriverRequest = DRIVER_SELECT_DIR_W_PS_TYPE;
      }
      else
      {
        LocalVar_eDriverRequest = DRIVER_CONFIRM_DIR;
      }
      break;

     case FUNC_STS_RPA_REMOTE_CONNECT:
      LocalVar_eDriverRequest = DRIVER_PREPARE_RPA;
      break;

     default:
      LocalVar_eDriverRequest = DRIVER_NO_REQ;
      break;
    }
    break;

   case LSAD_STS_PREPARE_SUSPEND:
    if (rtu_sPaStateAdptr->sPAEvntAdptr.ePASuspendEvnt == SUSPEND_SPEED_HIGH)
    {
      LocalVar_eDriverRequest = DRIVER_SLOW_DOWN;
    }
    else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
                  (((rtu_sPaStateAdptr->sPAEvntAdptr.ePASuspendEvnt ==
                     SUSPEND_DR_DOOR_OPEN) ? ((int32_T)1) : ((int32_T)0)) |
                   ((rtu_sPaStateAdptr->sPAEvntAdptr.ePASuspendEvnt ==
                     SUSPEND_TRUNK_OPEN) ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) |
               ((rtu_sPaStateAdptr->sPAEvntAdptr.ePASuspendEvnt ==
                 SUSPEND_HOOD_OPEN) ? ((int32_T)1) : ((int32_T)0)))))
    {
      LocalVar_eDriverRequest = DRIVER_CLOSE_DOOR;
    }
    else
    {
      LocalVar_eDriverRequest = DRIVER_NO_REQ;
    }
    break;

   case LSAD_STS_HANDSHAKE:
    LocalVar_eDriverRequest = DRIVER_WAIT_HANDSHAKE;
    break;

   default:
    if ((boolean_T)((int32_T)(((rtu_sMasterLsadFsm->eLsadSystemSts ==
            LSAD_STS_PP) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
             (((hmi_common_DW.UnitDelay_DSTATE_pa == LSAD_STS_PP) ? ((int32_T)1)
               : ((int32_T)0)) & ((rtu_sMasterLsadFsm->eLsadSystemSts ==
                LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
           : ((int32_T)0)))))
    {
      LocalVar_eDriverRequest = DRIVER_WAIT_PATH_PLAN;
    }
    else if ((boolean_T)((int32_T)(((rtu_sMasterLsadFsm->eLsadSystemSts ==
                 LSAD_STS_ACTIVE) ? ((int32_T)1) : ((int32_T)0)) &
               (rtu_sVehCommon->sCondiPlatform.bActvStsNeedRlsBrk ? ((int32_T)1)
                : ((int32_T)0)))))
    {
      /* bActvStsNeedRlsBrk */
      LocalVar_eDriverRequest = DRIVER_RELEASE_CONTROL;

      /* 汉车用户没踩刹车也会有这个提示词，调试的时候留意 */
    }
    else
    {
      switch (rtu_sMasterLsadFsm->eLsadSystemSts)
      {
       case LSAD_STS_ACTIVE:
        switch (rtu_sPaStateAdptr->sCondiHMI.ePrkFnct)
        {
         case PARK_FUNC_APA:
          LocalVar_eDriverRequest = DRIVER_MONITOR_APA_PARKING;
          break;

         case PARK_FUNC_RPA:
          LocalVar_eDriverRequest = DRIVER_MONITOR_RPA_PARKING;
          break;

         default:
          LocalVar_eDriverRequest = DRIVER_NO_REQ;
          break;
        }
        break;

       case LSAD_STS_ACTIVE_SUSPEND:
        if (rtu_sPaStateCommon->sPAEvnt.ePAIntrptEvnt != INTERRUPT_NONE)
        {
          if (rtu_sPaStateAdptr->sCondiHMI.eAPAMod != APA_MODE_STRAIGHT)
          {
            LocalVar_eDriverRequest = DRIVER_RESOLVE_SUSPENSION;
          }
          else
          {
            LocalVar_eDriverRequest = DRIVER_NO_REQ;
          }
        }
        else
        {
          LocalVar_eDriverRequest = DRIVER_CONFIRM_RECOVERY;
        }
        break;

       case LSAD_STS_TERMINATED:
        if (rtu_sPaStateCommon->sPAEvnt.ePATrmntEvnt ==
            TERMINATE_PO_FRONT_NO_OBS)
        {
          LocalVar_eDriverRequest = DRIVER_MANUAL_PARK_OUT;
        }
        else if (rtu_sRelatedModuleInfo->eHandshakeSts != HANDSHAKE_UNCONTROLLED)
        {
          LocalVar_eDriverRequest = DRIVER_WAIT_CTROL_HANDOVER;
        }
        else
        {
          LocalVar_eDriverRequest = DRIVER_TAKEOVER;
        }
        break;

       case LSAD_STS_COMPLETE:
        if (rtu_sRelatedModuleInfo->eHandshakeSts != HANDSHAKE_UNCONTROLLED)
        {
          LocalVar_eDriverRequest = DRIVER_WAIT_CTROL_HANDOVER;
        }
        else
        {
          LocalVar_eDriverRequest = DRIVER_TAKEOVER;
        }
        break;

       default:
        LocalVar_eDriverRequest = DRIVER_NO_REQ;
        break;
      }
    }
    break;
  }

  /* End of MATLAB Function: '<Root>/DriverRequestDet' */

  /* Logic: '<S11>/Logical Operator3' incorporates:
   *  Constant: '<S25>/Constant'
   *  Constant: '<S26>/Constant'
   *  RelationalOperator: '<S11>/Equal3'
   *  RelationalOperator: '<S11>/Equal4'
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  LocalVar_LogicalOperator3 = (rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkSlotIDReq !=
    PRK_SLOT_NO_REQ) & (hmi_common_DW.UnitDelay2_DSTATE_b == PRK_SLOT_NO_REQ);

  /* RelationalOperator: '<S11>/Equal6' incorporates:
   *  Constant: '<S27>/Constant'
   */
  LocalVar_RelationalOperator_a = (rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkSlotIDReq ==
    PRK_SLOT_NO_REQ);

  /* Switch: '<S24>/Switch1' incorporates:
   *  Constant: '<S11>/Constant13'
   *  Constant: '<S24>/Constant3'
   *  Sum: '<S24>/Add'
   *  UnitDelay: '<S24>/Unit Delay'
   */
  if (LocalVar_RelationalOperator_a)
  {
    LocalVar_Switch1 = hmi_common_DW.UnitDelay_DSTATE_p + s_APPManLoopSec;
  }
  else
  {
    LocalVar_Switch1 = 0.0F;
  }

  /* End of Switch: '<S24>/Switch1' */

  /* RelationalOperator: '<S24>/Relational Operator' incorporates:
   *  Constant: '<S11>/Constant10'
   */
  LocalVar_RelationalOperator_o = (LocalVar_Switch1 > k_SwtResetDuraTime);

  /* UnitDelay: '<S11>/Unit Delay1' incorporates:
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  hmi_common_DW.UnitDelay2_DSTATE_b = hmi_common_DW.UnitDelay1_DSTATE;

  /* Logic: '<S28>/OR1' incorporates:
   *  Logic: '<S11>/Logical Operator5'
   *  Logic: '<S11>/Logical Operator6'
   *  Logic: '<S28>/NOT'
   *  Logic: '<S28>/OR'
   *  RelationalOperator: '<S11>/Equal5'
   *  Switch: '<S24>/Switch'
   *  UnitDelay: '<S11>/Unit Delay2'
   *  UnitDelay: '<S11>/Unit Delay3'
   *  UnitDelay: '<S28>/Unit Delay2'
   */
  LocalVar_LogicalOperator3 = LocalVar_LogicalOperator3 | ((boolean_T)((int32_T)
    ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
    ((LocalVar_RelationalOperator_a ? ((int32_T)1) : ((int32_T)0)) ^ 1))) ?
    ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
    ((LocalVar_RelationalOperator_o ? ((int32_T)1) : ((int32_T)0)) ^ 1))) ?
    ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
    (((boolean_T)((int32_T)((((boolean_T)((int32_T)
    (((rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkSlotIDReq !=
       hmi_common_DW.UnitDelay2_DSTATE_b) ? ((int32_T)1) : ((int32_T)0)) ^ 1))) ?
    ((int32_T)1) : ((int32_T)0)) | (hmi_common_DW.bitsForTID0.UnitDelay3_DSTATE ?
    ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0)) &
     (hmi_common_DW.bitsForTID0.UnitDelay2_DSTATE_d ? ((int32_T)1) : ((int32_T)0)))));

  /* Switch: '<S23>/Switch1' incorporates:
   *  Constant: '<S11>/Constant2'
   *  Constant: '<S23>/Constant3'
   *  Sum: '<S23>/Add'
   *  UnitDelay: '<S23>/Unit Delay'
   */
  if (LocalVar_LogicalOperator3)
  {
    LocalVar_Switch1_k = hmi_common_DW.UnitDelay_DSTATE + s_APPManLoopSec;
  }
  else
  {
    LocalVar_Switch1_k = 0.0F;
  }

  /* End of Switch: '<S23>/Switch1' */

  /* RelationalOperator: '<S23>/Relational Operator' incorporates:
   *  Constant: '<S11>/Constant1'
   */
  LocalVar_RelationalOperator_g = (LocalVar_Switch1_k > k_VldSwtDuratTime);

  /* Switch: '<S23>/Switch' */
  LocalVar_Switch = LocalVar_LogicalOperator3 & LocalVar_RelationalOperator_g;

  /* UnitDelay: '<S22>/Unit Delay2' incorporates:
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  hmi_common_DW.UnitDelay2_DSTATE_b = hmi_common_DW.UnitDelay2_DSTATE_m;

  /* Logic: '<S22>/Logical Operator3' incorporates:
   *  Constant: '<S31>/Constant'
   *  Constant: '<S32>/Constant'
   *  RelationalOperator: '<S22>/Equal3'
   *  RelationalOperator: '<S22>/Equal4'
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  LocalVar_LogicalOperator3_c = (rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkSlotIDReq !=
    PRK_SLOT_NO_REQ) & (hmi_common_DW.UnitDelay2_DSTATE_b == PRK_SLOT_NO_REQ);

  /* RelationalOperator: '<S22>/Equal6' incorporates:
   *  Constant: '<S33>/Constant'
   */
  LocalVar_Equal4_c = (rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkSlotIDReq ==
                       PRK_SLOT_NO_REQ);

  /* Switch: '<S30>/Switch1' incorporates:
   *  Constant: '<S22>/Constant13'
   *  Constant: '<S30>/Constant3'
   *  Sum: '<S30>/Add'
   *  UnitDelay: '<S30>/Unit Delay'
   */
  if (LocalVar_Equal4_c)
  {
    X1RgeThrsdLeftOBL = hmi_common_DW.UnitDelay_DSTATE_bm + s_APPManLoopSec;
  }
  else
  {
    X1RgeThrsdLeftOBL = 0.0F;
  }

  /* End of Switch: '<S30>/Switch1' */

  /* RelationalOperator: '<S30>/Relational Operator' incorporates:
   *  Constant: '<S22>/Constant10'
   */
  LocalVar_RelationalOperator_a = (X1RgeThrsdLeftOBL > k_SwtResetDuraTime);

  /* UnitDelay: '<S22>/Unit Delay1' incorporates:
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  hmi_common_DW.UnitDelay2_DSTATE_b = hmi_common_DW.UnitDelay1_DSTATE_h;

  /* Logic: '<S34>/OR1' incorporates:
   *  Logic: '<S22>/Logical Operator5'
   *  Logic: '<S22>/Logical Operator6'
   *  Logic: '<S34>/NOT'
   *  Logic: '<S34>/OR'
   *  RelationalOperator: '<S22>/Equal5'
   *  Switch: '<S30>/Switch'
   *  UnitDelay: '<S11>/Unit Delay2'
   *  UnitDelay: '<S22>/Unit Delay3'
   *  UnitDelay: '<S34>/Unit Delay2'
   */
  LocalVar_Equal4_c = LocalVar_LogicalOperator3_c | ((boolean_T)((int32_T)
    ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
    ((LocalVar_Equal4_c ? ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) :
    ((int32_T)0)) | (((boolean_T)((int32_T)((LocalVar_RelationalOperator_a ?
    ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ?
    ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)((((boolean_T)
    ((int32_T)(((rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkSlotIDReq !=
                 hmi_common_DW.UnitDelay2_DSTATE_b) ? ((int32_T)1) : ((int32_T)0))
               ^ 1))) ? ((int32_T)1) : ((int32_T)0)) |
    (hmi_common_DW.bitsForTID0.UnitDelay3_DSTATE_l ? ((int32_T)1) : ((int32_T)0)))))
    ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
     (hmi_common_DW.bitsForTID0.UnitDelay2_DSTATE_f ? ((int32_T)1) : ((int32_T)0)))));

  /* Switch: '<S29>/Switch1' incorporates:
   *  Constant: '<S22>/Constant2'
   *  Constant: '<S29>/Constant3'
   *  Sum: '<S29>/Add'
   *  UnitDelay: '<S29>/Unit Delay'
   */
  if (LocalVar_Equal4_c)
  {
    Y2RgeThrsdLeftOBL = hmi_common_DW.UnitDelay_DSTATE_b + s_APPManLoopSec;
  }
  else
  {
    Y2RgeThrsdLeftOBL = 0.0F;
  }

  /* End of Switch: '<S29>/Switch1' */

  /* RelationalOperator: '<S29>/Relational Operator' incorporates:
   *  Constant: '<S22>/Constant1'
   */
  LocalVar_RelationalOperator_jj = (Y2RgeThrsdLeftOBL > k_VldSwtDuratTime);

  /* Switch: '<S29>/Switch' */
  LocalVar_Switch_l = LocalVar_Equal4_c & LocalVar_RelationalOperator_jj;

  /* RelationalOperator: '<S8>/Equal3' incorporates:
   *  Constant: '<S15>/Constant'
   */
  LocalVar_LogicalOperator3_c = (rtu_sPaStateAdptr->sCondiHMI.eAPAMod ==
    APA_MODE_PARK_IN);

  /* MATLAB Function: '<S8>/DrvrSelSlotIDDet' incorporates:
   *  Delay: '<S12>/Delay'
   *  RelationalOperator: '<S12>/Relational Operator'
   *  UnitDelay: '<S8>/Unit Delay1'
   */
  if (((int32_T)(LocalVar_LogicalOperator3_c ? 1 : 0)) > ((int32_T)
       (hmi_common_DW.bitsForTID0.Delay_DSTATE ? 1 : 0)))
  {
    hmi_common_DW.UnitDelay1_DSTATE_hu = 0U;
  }
  else if (LocalVar_Switch)
  {
    switch (rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkSlotIDReq)
    {
     case PRK_SLOT_ID0:
      hmi_common_DW.UnitDelay1_DSTATE_hu = rty_sFusionDisp->sSlotGroup[0].
        u8SlotID;
      break;

     case PRK_SLOT_ID1:
      hmi_common_DW.UnitDelay1_DSTATE_hu = rty_sFusionDisp->sSlotGroup[1].
        u8SlotID;
      break;

     case PRK_SLOT_ID2:
      hmi_common_DW.UnitDelay1_DSTATE_hu = rty_sFusionDisp->sSlotGroup[2].
        u8SlotID;
      break;

     case PRK_SLOT_ID3:
      hmi_common_DW.UnitDelay1_DSTATE_hu = rty_sFusionDisp->sSlotGroup[3].
        u8SlotID;
      break;

     case PRK_SLOT_ID4:
      hmi_common_DW.UnitDelay1_DSTATE_hu = rty_sFusionDisp->sSlotGroup[4].
        u8SlotID;
      break;

     case PRK_SLOT_ID5:
      hmi_common_DW.UnitDelay1_DSTATE_hu = rty_sFusionDisp->sSlotGroup[5].
        u8SlotID;
      break;

     case PRK_SLOT_ID6:
      hmi_common_DW.UnitDelay1_DSTATE_hu = rty_sFusionDisp->sSlotGroup[6].
        u8SlotID;
      break;

     case PRK_SLOT_ID7:
      hmi_common_DW.UnitDelay1_DSTATE_hu = rty_sFusionDisp->sSlotGroup[7].
        u8SlotID;
      break;

     default:
      /* no actions */
      break;
    }
  }
  else if (LocalVar_Switch_l)
  {
    switch (rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkSlotIDReq)
    {
     case PRK_SLOT_ID0:
      hmi_common_DW.UnitDelay1_DSTATE_hu = rty_sFusionDisp->sSlotGroup[0].
        u8SlotID;
      break;

     case PRK_SLOT_ID1:
      hmi_common_DW.UnitDelay1_DSTATE_hu = rty_sFusionDisp->sSlotGroup[1].
        u8SlotID;
      break;

     case PRK_SLOT_ID2:
      hmi_common_DW.UnitDelay1_DSTATE_hu = rty_sFusionDisp->sSlotGroup[2].
        u8SlotID;
      break;

     case PRK_SLOT_ID3:
      hmi_common_DW.UnitDelay1_DSTATE_hu = rty_sFusionDisp->sSlotGroup[3].
        u8SlotID;
      break;

     case PRK_SLOT_ID4:
      hmi_common_DW.UnitDelay1_DSTATE_hu = rty_sFusionDisp->sSlotGroup[4].
        u8SlotID;
      break;

     case PRK_SLOT_ID5:
      hmi_common_DW.UnitDelay1_DSTATE_hu = rty_sFusionDisp->sSlotGroup[5].
        u8SlotID;
      break;

     case PRK_SLOT_ID6:
      hmi_common_DW.UnitDelay1_DSTATE_hu = rty_sFusionDisp->sSlotGroup[6].
        u8SlotID;
      break;

     case PRK_SLOT_ID7:
      hmi_common_DW.UnitDelay1_DSTATE_hu = rty_sFusionDisp->sSlotGroup[7].
        u8SlotID;
      break;

     default:
      /* no actions */
      break;
    }
  }
  else
  {
    /* no actions */
  }

  /* End of MATLAB Function: '<S8>/DrvrSelSlotIDDet' */

  /* RelationalOperator: '<S8>/Equal2' incorporates:
   *  Constant: '<S14>/Constant'
   */
  LocalVar_Equal2 = (rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_PARK_IN);

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S16>/Constant'
   *  Constant: '<S17>/Constant'
   *  Constant: '<S18>/Constant'
   *  Constant: '<S19>/Constant'
   *  Constant: '<S20>/Constant'
   *  Constant: '<S21>/Constant'
   *  Logic: '<S8>/Logical Operator1'
   *  Logic: '<S8>/Logical Operator2'
   *  Logic: '<S8>/Logical Operator3'
   *  Logic: '<S8>/Logical Operator4'
   *  MATLAB Function: '<Root>/ADCS9PlotFitCalc'
   *  RelationalOperator: '<S8>/Equal1'
   *  RelationalOperator: '<S8>/Equal4'
   *  RelationalOperator: '<S8>/Equal5'
   *  RelationalOperator: '<S8>/Equal6'
   *  RelationalOperator: '<S8>/Equal7'
   *  RelationalOperator: '<S8>/Equal8'
   *  RelationalOperator: '<S8>/Equal9'
   *  Switch: '<S8>/Switch1'
   *  UnitDelay: '<S8>/Unit Delay1'
   *  UnitDelay: '<S8>/Unit Delay4'
   */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)
           (((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_CONFIRM) ?
             ((int32_T)1) : ((int32_T)0)) | ((rtu_sSlaveLsadFsm->eLsadFuncSts ==
              FUNC_STS_RPA_PI_CONFIRM) ? ((int32_T)1) : ((int32_T)0))))) ?
         ((int32_T)1) : ((int32_T)0)) & (LocalVar_Equal2 ? ((int32_T)1) :
         ((int32_T)0)))))
  {
    hmi_common_DW.UnitDelay4_DSTATE_l = hmi_common_DW.UnitDelay1_DSTATE_hu;
  }
  else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((LocalVar_Equal2 ?
      ((int32_T)1) : ((int32_T)0)) & ((rtu_sSlaveLsadFsm->eLsadFuncSts !=
      FUNC_STS_APA_PI_CONFIRM) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) & ((rtu_sSlaveLsadFsm->eLsadFuncSts != FUNC_STS_RPA_PI_CONFIRM)
                     ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
        ((int32_T)0)) & ((rtu_sSlaveLsadFsm->eLsadFuncSts !=
                          FUNC_STS_RPA_REMOTE_CONNECT) ? ((int32_T)1) :
                         ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
      ((rtu_sMasterLsadFsm->eLsadSystemSts != LSAD_STS_HANDSHAKE) ? ((int32_T)1)
       : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
             ((rtu_sPaStateAdptr->sCondiHMI.eAPAMod != APA_MODE_PARK_IN) ?
              ((int32_T)1) : ((int32_T)0)))))
  {
    /* Switch: '<S8>/Switch1' incorporates:
     *  Constant: '<S8>/Constant'
     *  UnitDelay: '<S8>/Unit Delay4'
     */
    hmi_common_DW.UnitDelay4_DSTATE_l = 0U;
  }
  else
  {
    /* no actions */
  }

  /* End of Switch: '<S8>/Switch' */
  (void)memset(rty_sHMIComDisp, 0, sizeof(tHMIComDisp));

  /* BusAssignment: '<Root>/Bus Assignment' incorporates:
   *  MATLAB Function: '<Root>/ADCS9PlotFitCalc'
   *  MATLAB Function: '<Root>/PITypeDirDet'
   *  UnitDelay: '<Root>/Unit Delay1'
   *  UnitDelay: '<Root>/Unit Delay4'
   *  UnitDelay: '<Root>/Unit Delay5'
   *  UnitDelay: '<S8>/Unit Delay4'
   */
  rty_sHMIComDisp->PAGuideLineA = hmi_common_DW.IntVPAGuideLineA;
  rty_sHMIComDisp->PAGuideLineB = hmi_common_DW.IntVPAGuideLineB;
  rty_sHMIComDisp->PAGuideLineC = hmi_common_DW.IntVPAGuideLineC;
  rty_sHMIComDisp->PAGuideLineD = hmi_common_DW.IntVPAGuideLineD;
  rty_sHMIComDisp->PAGuideLineXMin = hmi_common_DW.IntVPAGuideLineXMin;
  rty_sHMIComDisp->PAGuideLineXMax = hmi_common_DW.IntVPAGuideLineXMax;
  rty_sHMIComDisp->PISlotLength = hmi_common_DW.PISlotLengthDelay;
  rty_sHMIComDisp->eDriverRequest = LocalVar_eDriverRequest;
  rty_sHMIComDisp->eSlotAvaliab = hmi_common_DW.UnitDelay1_DSTATE_i;
  rty_sHMIComDisp->ePISlotType = hmi_common_DW.UnitDelay4_DSTATE_d;
  rty_sHMIComDisp->ePIDir = hmi_common_DW.UnitDelay5_DSTATE;
  rty_sHMIComDisp->u8aParkBarPercent = 55U;
  rty_sHMIComDisp->u8DrvrSelSlotID = hmi_common_DW.UnitDelay4_DSTATE_l;

  /* BusCreator: '<Root>/Bus Creator1' incorporates:
   *  Delay: '<Root>/Delay1'
   */
  (void)memcpy(&rty_sFusionDisp->sObsGroup[0], &hmi_common_DW.Delay1_DSTATE[0],
               12U * (sizeof(tObsDisp)));
  (void)memset(rty_sDragParkingLot, 0, sizeof(DragParkingLot));

  /* MATLAB Function: '<S7>/SelfParkSlotDet' incorporates:
   *  MATLAB Function: '<Root>/ADCS9PlotFitCalc'
   *  UnitDelay: '<S7>/Unit Delay4'
   */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
               (((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_CONFIRM) ?
                 ((int32_T)1) : ((int32_T)0)) |
                ((rtu_sSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RPA_PI_CONFIRM) ?
                 ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
            & ((rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_SELF_SELECT) ?
               ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
        ((rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkWorkMd == PRK_WORK_START) ? ((int32_T)1)
         : ((int32_T)0)))))
  {
    rty_sDragParkingLot->u8PoseOrPoints = 1U;

    /*  0:pose 1:points */
    switch (rtu_sPaStateAdptr->sCondiHMI.eDragSlotType)
    {
     case DRAG_SLOT_TYPE_PARALLEL:
      rty_sDragParkingLot->type = 1U;

      /* DragParkingLotType: DRAG_PL_TYPE_Horizontal */
      break;

     case DRAG_SLOT_TYPE_PERPENDI:
      rty_sDragParkingLot->type = 2U;

      /* DragParkingLotType: DRAG_PL_TYPE_Vertical */
      break;

     case DRAG_SLOT_TYPE_OBLIQUE:
      rty_sDragParkingLot->type = 4U;

      /* DragParkingLotType: DRAG_PL_TYPE_Oblique_45 */
      break;

     default:
      rty_sDragParkingLot->type = 0U;

      /* DragParkingLotType: DRAG_PL_TYPE_None */
      break;
    }

    rty_sDragParkingLot->stPoints[0].x =
      rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX0;
    rty_sDragParkingLot->stPoints[0].y =
      rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY0;
    rty_sDragParkingLot->stPoints[1].x =
      rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX1;
    rty_sDragParkingLot->stPoints[1].y =
      rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY1;
    rty_sDragParkingLot->stPoints[2].x =
      rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX2;
    rty_sDragParkingLot->stPoints[2].y =
      rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY2;
    rty_sDragParkingLot->stPoints[3].x =
      rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotX3;
    rty_sDragParkingLot->stPoints[3].y =
      rtu_sPaStateAdptr->sDragPrkSlot.f32PrkSlotY3;
    rty_sDragParkingLot->res[0] = 1U;

    /* 当STS_AVAILABLE使用 */
  }
  else if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
      (((rtu_sSlaveLsadFsm->eLsadFuncSts != FUNC_STS_APA_PI_CONFIRM) ? ((int32_T)
      1) : ((int32_T)0)) & ((rtu_sSlaveLsadFsm->eLsadFuncSts !=
      FUNC_STS_RPA_PI_CONFIRM) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) & ((rtu_sMasterLsadFsm->eLsadSystemSts != LSAD_STS_HANDSHAKE) ?
                     ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)
               0)) & ((rtu_sPaStateAdptr->sCondiHMI.eAPAMod ==
                       APA_MODE_SELF_SELECT) ? ((int32_T)1) : ((int32_T)0)))))
  {
    rty_sDragParkingLot->u8PoseOrPoints = 1U;

    /*  0:pose 1:points */
    rty_sDragParkingLot->type = 0U;
    rty_sDragParkingLot->stPoints[0].x = 0.0F;
    rty_sDragParkingLot->stPoints[0].y = 0.0F;
    rty_sDragParkingLot->stPoints[1].x = 0.0F;
    rty_sDragParkingLot->stPoints[1].y = 0.0F;
    rty_sDragParkingLot->stPoints[2].x = 0.0F;
    rty_sDragParkingLot->stPoints[2].y = 0.0F;
    rty_sDragParkingLot->stPoints[3].x = 0.0F;
    rty_sDragParkingLot->stPoints[3].y = 0.0F;
    rty_sDragParkingLot->res[0] = 0U;

    /* 当STS_NOT_AVAILABLE使用 */
  }
  else
  {
    *rty_sDragParkingLot = hmi_common_DW.UnitDelay4_DSTATE;
  }

  /* End of MATLAB Function: '<S7>/SelfParkSlotDet' */

  /* Switch: '<S23>/Switch2' incorporates:
   *  UnitDelay: '<S23>/Unit Delay'
   */
  if ((boolean_T)((int32_T)((LocalVar_RelationalOperator_g ? ((int32_T)1) :
         ((int32_T)0)) ^ 1)))
  {
    hmi_common_DW.UnitDelay_DSTATE = LocalVar_Switch1_k;
  }

  /* End of Switch: '<S23>/Switch2' */

  /* Switch: '<S24>/Switch2' incorporates:
   *  UnitDelay: '<S24>/Unit Delay'
   */
  if ((boolean_T)((int32_T)((LocalVar_RelationalOperator_o ? ((int32_T)1) :
         ((int32_T)0)) ^ 1)))
  {
    hmi_common_DW.UnitDelay_DSTATE_p = LocalVar_Switch1;
  }

  /* End of Switch: '<S24>/Switch2' */

  /* Switch: '<S29>/Switch2' incorporates:
   *  UnitDelay: '<S29>/Unit Delay'
   */
  if ((boolean_T)((int32_T)((LocalVar_RelationalOperator_jj ? ((int32_T)1) :
         ((int32_T)0)) ^ 1)))
  {
    hmi_common_DW.UnitDelay_DSTATE_b = Y2RgeThrsdLeftOBL;
  }

  /* End of Switch: '<S29>/Switch2' */

  /* Switch: '<S30>/Switch2' incorporates:
   *  UnitDelay: '<S30>/Unit Delay'
   */
  if ((boolean_T)((int32_T)((LocalVar_RelationalOperator_a ? ((int32_T)1) :
         ((int32_T)0)) ^ 1)))
  {
    hmi_common_DW.UnitDelay_DSTATE_bm = X1RgeThrsdLeftOBL;
  }

  /* End of Switch: '<S30>/Switch2' */

  /* Update for UnitDelay: '<Root>/Unit Delay2' */
  (void)memcpy(&hmi_common_DW.UnitDelay2_DSTATE[0], &rty_sFusionDisp->
               sSlotGroup[0], 12U * (sizeof(tSlotDisp)));

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  hmi_common_DW.UnitDelay_DSTATE_pa = rtu_sMasterLsadFsm->eLsadSystemSts;

  /* Update for UnitDelay: '<S11>/Unit Delay2' */
  hmi_common_DW.UnitDelay2_DSTATE_b = rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkSlotIDReq;

  /* Update for UnitDelay: '<S11>/Unit Delay1' */
  hmi_common_DW.UnitDelay1_DSTATE = rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkSlotIDReq;

  /* Update for UnitDelay: '<S11>/Unit Delay3' */
  hmi_common_DW.bitsForTID0.UnitDelay3_DSTATE = LocalVar_Switch;

  /* Update for UnitDelay: '<S28>/Unit Delay2' */
  hmi_common_DW.bitsForTID0.UnitDelay2_DSTATE_d = LocalVar_LogicalOperator3;

  /* Update for UnitDelay: '<S22>/Unit Delay2' */
  hmi_common_DW.UnitDelay2_DSTATE_m = rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkSlotIDReq;

  /* Update for UnitDelay: '<S22>/Unit Delay1' */
  hmi_common_DW.UnitDelay1_DSTATE_h = rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkSlotIDReq;

  /* Update for UnitDelay: '<S22>/Unit Delay3' */
  hmi_common_DW.bitsForTID0.UnitDelay3_DSTATE_l = LocalVar_Switch_l;

  /* Update for UnitDelay: '<S34>/Unit Delay2' */
  hmi_common_DW.bitsForTID0.UnitDelay2_DSTATE_f = LocalVar_Equal4_c;

  /* Update for Delay: '<S12>/Delay' */
  hmi_common_DW.bitsForTID0.Delay_DSTATE = LocalVar_LogicalOperator3_c;

  /* Update for UnitDelay: '<S7>/Unit Delay4' */
  hmi_common_DW.UnitDelay4_DSTATE = *rty_sDragParkingLot;
}

/* Model initialize function */
void hmi_common_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)&hmi_common_DW, 0,
                sizeof(DW_hmi_common_f_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
