/*
 * File: lsad_fsm_adapter.c
 *
 * Code generated for Simulink model 'lsad_fsm_adapter'.
 *
 * Model version                  : 1.135
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Tue Feb 25 10:16:24 2025
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

#include "lsad_fsm_adapter.h"
#include "lsad_fsm_adapter_api.h"
#include "lsad_fsm_api.h"
#include "wrapper_api.h"
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
#define CtrlPara_START_SEC_VAR
#include "proj_MemMap.h"
const tRelatedModuleInfo lsad_fsm_adapter_rtZtRelatedModuleInfo =
{
  APA_PATH_PLAN_STANDBY,               /* ePathPlanSts */
  APA_CTRL_OFF,                        /* eCtrlSts */
  APA_US_STS_OFF,                      /* eUltrasonicSts */
  HANDSHAKE_UNCONTROLLED,              /* eHandshakeSts */
  LOC_STATUS_NONE,                     /* eLocSts */
  APA_DF_OFF,                          /* eDataFusionSts */
  NOT_SUPPORT,                         /* eUssSupportActive */
  MAPCREATOR_STATE_READY,              /* eMappingSts */
  NO_FAILCODE,                         /* eHandshakeFailReason */
  HANDSHAKE_TYPE_NONE,                 /* eHandshakeType */
  HANDSHAKE_RQ_TYPE_NONE,              /* eHandshakeTypeReq */
  VEHI_GEAR_P,                         /* eHandshakeGearReq */
  CTRL_FAIL_NO,                        /* eCtrlFailReason */
  0.0F,                                /* f32RARecordedDist */
  0.0F,                                /* f32CtrlReqStopDistance */
  0.0F,                                /* f32X_Coor */
  0.0F,                                /* f32Y_Coor */
  0.0F,                                /* f32Theta */
  0U,                                  /* u8VehicleActionRequest */
  0U,                                  /* u8ParkoutDir */
  0U,                                  /* u8StatusParkin */
  0U,                                  /* u8VehicleActionReason */
  0U,                                  /* u8SceneType */
  0U,                                  /* u8ReqPause */

  {
    0U, 0U
  }
  /* u8Res2 */
} ;                                    /* tRelatedModuleInfo ground */

const tPecpPLDInfo lsad_fsm_adapter_rtZtPecpPLDInfo =
{
  {
    {
      {
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        }
      }
      ,                                /* stPLDPoint */
      PECP_PLD_TYPE_INVALID,           /* stType */
      PECP_PLD_STATE_UnAvailable,      /* stState */
      0,                               /* s32ParkLotID */
      0U                               /* u8confidence */
    },
    {
      {
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        }
      }
      ,                                /* stPLDPoint */
      PECP_PLD_TYPE_INVALID,           /* stType */
      PECP_PLD_STATE_UnAvailable,      /* stState */
      0,                               /* s32ParkLotID */
      0U                               /* u8confidence */
    },
    {
      {
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        }
      }
      ,                                /* stPLDPoint */
      PECP_PLD_TYPE_INVALID,           /* stType */
      PECP_PLD_STATE_UnAvailable,      /* stState */
      0,                               /* s32ParkLotID */
      0U                               /* u8confidence */
    },
    {
      {
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        }
      }
      ,                                /* stPLDPoint */
      PECP_PLD_TYPE_INVALID,           /* stType */
      PECP_PLD_STATE_UnAvailable,      /* stState */
      0,                               /* s32ParkLotID */
      0U                               /* u8confidence */
    },
    {
      {
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        }
      }
      ,                                /* stPLDPoint */
      PECP_PLD_TYPE_INVALID,           /* stType */
      PECP_PLD_STATE_UnAvailable,      /* stState */
      0,                               /* s32ParkLotID */
      0U                               /* u8confidence */
    },
    {
      {
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        }
      }
      ,                                /* stPLDPoint */
      PECP_PLD_TYPE_INVALID,           /* stType */
      PECP_PLD_STATE_UnAvailable,      /* stState */
      0,                               /* s32ParkLotID */
      0U                               /* u8confidence */
    },
    {
      {
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        }
      }
      ,                                /* stPLDPoint */
      PECP_PLD_TYPE_INVALID,           /* stType */
      PECP_PLD_STATE_UnAvailable,      /* stState */
      0,                               /* s32ParkLotID */
      0U                               /* u8confidence */
    },
    {
      {
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        }
      }
      ,                                /* stPLDPoint */
      PECP_PLD_TYPE_INVALID,           /* stType */
      PECP_PLD_STATE_UnAvailable,      /* stState */
      0,                               /* s32ParkLotID */
      0U                               /* u8confidence */
    },
    {
      {
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        }
      }
      ,                                /* stPLDPoint */
      PECP_PLD_TYPE_INVALID,           /* stType */
      PECP_PLD_STATE_UnAvailable,      /* stState */
      0,                               /* s32ParkLotID */
      0U                               /* u8confidence */
    },
    {
      {
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        }
      }
      ,                                /* stPLDPoint */
      PECP_PLD_TYPE_INVALID,           /* stType */
      PECP_PLD_STATE_UnAvailable,      /* stState */
      0,                               /* s32ParkLotID */
      0U                               /* u8confidence */
    },
    {
      {
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        }
      }
      ,                                /* stPLDPoint */
      PECP_PLD_TYPE_INVALID,           /* stType */
      PECP_PLD_STATE_UnAvailable,      /* stState */
      0,                               /* s32ParkLotID */
      0U                               /* u8confidence */
    },
    {
      {
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        }
      }
      ,                                /* stPLDPoint */
      PECP_PLD_TYPE_INVALID,           /* stType */
      PECP_PLD_STATE_UnAvailable,      /* stState */
      0,                               /* s32ParkLotID */
      0U                               /* u8confidence */
    },
    {
      {
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        }
      }
      ,                                /* stPLDPoint */
      PECP_PLD_TYPE_INVALID,           /* stType */
      PECP_PLD_STATE_UnAvailable,      /* stState */
      0,                               /* s32ParkLotID */
      0U                               /* u8confidence */
    },
    {
      {
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        }
      }
      ,                                /* stPLDPoint */
      PECP_PLD_TYPE_INVALID,           /* stType */
      PECP_PLD_STATE_UnAvailable,      /* stState */
      0,                               /* s32ParkLotID */
      0U                               /* u8confidence */
    },
    {
      {
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        }
      }
      ,                                /* stPLDPoint */
      PECP_PLD_TYPE_INVALID,           /* stType */
      PECP_PLD_STATE_UnAvailable,      /* stState */
      0,                               /* s32ParkLotID */
      0U                               /* u8confidence */
    },
    {
      {
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        }
      }
      ,                                /* stPLDPoint */
      PECP_PLD_TYPE_INVALID,           /* stType */
      PECP_PLD_STATE_UnAvailable,      /* stState */
      0,                               /* s32ParkLotID */
      0U                               /* u8confidence */
    },
    {
      {
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        }
      }
      ,                                /* stPLDPoint */
      PECP_PLD_TYPE_INVALID,           /* stType */
      PECP_PLD_STATE_UnAvailable,      /* stState */
      0,                               /* s32ParkLotID */
      0U                               /* u8confidence */
    },
    {
      {
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        }
      }
      ,                                /* stPLDPoint */
      PECP_PLD_TYPE_INVALID,           /* stType */
      PECP_PLD_STATE_UnAvailable,      /* stState */
      0,                               /* s32ParkLotID */
      0U                               /* u8confidence */
    },
    {
      {
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        }
      }
      ,                                /* stPLDPoint */
      PECP_PLD_TYPE_INVALID,           /* stType */
      PECP_PLD_STATE_UnAvailable,      /* stState */
      0,                               /* s32ParkLotID */
      0U                               /* u8confidence */
    },
    {
      {
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        },
        {
          0.0F,                        /* x */
          0.0F                         /* y */
        }
      }
      ,                                /* stPLDPoint */
      PECP_PLD_TYPE_INVALID,           /* stType */
      PECP_PLD_STATE_UnAvailable,      /* stState */
      0,                               /* s32ParkLotID */
      0U                               /* u8confidence */
    }
  }
  ,                                    /* stPLDs */
  0,                                   /* s32SuggestParkID */
  0                                    /* s32ParkNum */
} ;                                    /* tPecpPLDInfo ground */

/* Block signals and states (default storage) */
DW_lsad_fsm_adapter_T lsad_fsm_adapter_DW;
#define CtrlPara_STOP_SEC_VAR
#include "proj_MemMap.h"
/* Model step function */
void lsad_fsm_adapter_step(void)
{
  /* local block i/o variables */
  DragParkingLot LocalVar_sDragParkingLot;
  tHMIComDisp LocalVar_sHMIComDisp;
  tMsgMnger_TextDisp LocalVar_sMsgMnger_TextDisp;
  tRAHmiRx LocalVar_sRAHmiRx;
  tHPAHmiRx LocalVar_sHPAHmiRx;
  tDiagInfo LocalVar_sDiagInfo;
  tHpaStateCommon LocalVar_SignalCopy9;
  tMsgMnger_Hmi LocalVar_sMsgMnger_Hmi;
  tMsgMnger_PathSegment LocalVar_sPathSegment;
  tPaStateCommon LocalVar_sPaStateCommon;
  tRaStateCommon LocalVar_SignalCopy8;
  tVehCommon LocalVar_sVehCommon;
  tVehDataRx LocalVar_sVehDataRx;

  /* SignalConversion: '<Root>/Signal Copy2' incorporates:
   *  Inport: '<Root>/sMsgMnger_Hmi'
   */
  LocalVar_sMsgMnger_Hmi = Get_sMsgMnger_Hmi();

  /* ModelReference: '<Root>/hmi_data_rx' */
  hmi_data_rx(&LocalVar_sMsgMnger_Hmi, &LocalVar_sRAHmiRx,
              &lsad_fsm_adapter_DW.sPAHmiRx, &LocalVar_sHPAHmiRx);

  /* SignalConversion: '<Root>/Signal Copy12' */
  Set_sRAHmiRx(LocalVar_sRAHmiRx);

  /* SignalConversion: '<Root>/Signal Copy13' */
  Set_sPAHmiRx(lsad_fsm_adapter_DW.sPAHmiRx);

  /* SignalConversion: '<Root>/Signal Copy11' */
  Set_sHPAHmiRx(LocalVar_sHPAHmiRx);

  /* SignalConversion: '<Root>/Signal Copy9' incorporates:
   *  Inport: '<Root>/sHpaStateCommon'
   */
  LocalVar_SignalCopy9 = Get_sHpaStateCommon();

  /* SignalConversion: '<Root>/Signal Copy8' incorporates:
   *  Inport: '<Root>/sRaStateCommon'
   */
  LocalVar_SignalCopy8 = Get_sRaStateCommon();

  /* SignalConversion: '<Root>/Signal Copy7' incorporates:
   *  Inport: '<Root>/sPaStateCommon'
   */
  LocalVar_sPaStateCommon = Get_sPaStateCommon();

  /* SignalConversion: '<Root>/Signal Copy3' incorporates:
   *  Inport: '<Root>/sRelatedModuleInfo'
   */
  lsad_fsm_adapter_DW.sRelatedModuleInfo = Get_sRelatedModuleInfo();

  /* SignalConversion: '<Root>/Signal Copy' incorporates:
   *  Inport: '<Root>/sVehDataRx'
   */
  LocalVar_sVehDataRx = Get_sVehDataRx();

  /* SignalConversion: '<Root>/Signal Copy6' incorporates:
   *  Inport: '<Root>/sVehCommon'
   */
  LocalVar_sVehCommon = Get_sVehCommon();

  /* SignalConversion: '<Root>/Signal Copy18' incorporates:
   *  Inport: '<Root>/sPecpPLDInfo'
   */
  lsad_fsm_adapter_DW.sPecpPLDInfo = Get_sPecpPLDInfo();

  /* SignalConversion: '<Root>/Signal Copy4' incorporates:
   *  Inport: '<Root>/sPathSegment'
   */
  LocalVar_sPathSegment = Get_sPathSegment();

  /* SignalConversion: '<Root>/Signal Copy10' incorporates:
   *  Inport: '<Root>/sMasterLsadFsm'
   */
  lsad_fsm_adapter_DW.sLsadFsmCore = Get_sMasterLsadFsm();

  /* SignalConversion: '<Root>/Signal Copy5' incorporates:
   *  Inport: '<Root>/sDiagInfo'
   */
  LocalVar_sDiagInfo = Get_sDiagInfo();

  /* ModelReference: '<Root>/common_condition_adapter' */
  common_condition_adapter(&LocalVar_sVehCommon, &lsad_fsm_adapter_DW.sPAHmiRx,
    &LocalVar_sVehDataRx, &lsad_fsm_adapter_DW.sLsadFsmCore, &LocalVar_sDiagInfo,
    &LocalVar_sPaStateCommon, &lsad_fsm_adapter_DW.UnitDelay7_DSTATE,
    &lsad_fsm_adapter_DW.sRelatedModuleInfo, &lsad_fsm_adapter_DW.sPaStateAdptr);

  /* ModelReference generated from: '<Root>/slave_lsad_fsm' incorporates:
   *  UnitDelay: '<Root>/Unit Delay'
   */
  slave_lsad_fsm(&lsad_fsm_adapter_DW.sPAHmiRx, &LocalVar_sPaStateCommon,
                 &LocalVar_sVehCommon, &LocalVar_sVehDataRx,
                 &lsad_fsm_adapter_DW.sRelatedModuleInfo,
                 &LocalVar_SignalCopy9.sHPACondiOverFlag.bHpaQuitDurattime,
                 &LocalVar_SignalCopy9.sHPAEvnt.eHPAQuitEvnt,
                 &LocalVar_SignalCopy9.sHPAEvnt.eHPAIntrptEvnt,
                 &LocalVar_sHPAHmiRx, &LocalVar_sRAHmiRx,
                 &LocalVar_SignalCopy8.sRACondiOverFlag.bRAQuitDurattime,
                 &LocalVar_SignalCopy8.sRAEvnt.eRAIntrptEvnt,
                 &LocalVar_SignalCopy8.sRAEvnt.eRAQuitEvnt, &LocalVar_sDiagInfo,
                 &lsad_fsm_adapter_DW.sLsadFsmCore,
                 &lsad_fsm_adapter_DW.UnitDelay_DSTATE,
                 &lsad_fsm_adapter_DW.sPaStateAdptr,
                 &lsad_fsm_adapter_DW.sSlaveLsadFsm);

  /* ModelReference: '<Root>/hmi_interactive' */
  hmi_interactive(&LocalVar_SignalCopy9, &LocalVar_SignalCopy8,
                  &LocalVar_sPaStateCommon,
                  &lsad_fsm_adapter_DW.sRelatedModuleInfo, &LocalVar_sVehDataRx,
                  &LocalVar_sVehCommon, &lsad_fsm_adapter_DW.sPAHmiRx,
                  &lsad_fsm_adapter_DW.sPecpPLDInfo, &LocalVar_sPathSegment,
                  &lsad_fsm_adapter_DW.sPaStateAdptr,
                  &lsad_fsm_adapter_DW.sLsadFsmCore,
                  &lsad_fsm_adapter_DW.sSlaveLsadFsm, &LocalVar_sHMIComDisp,
                  &LocalVar_sMsgMnger_TextDisp, &LocalVar_sDragParkingLot);

  /* SignalConversion: '<Root>/Signal Copy1' incorporates:
   *  ModelReference: '<Root>/hmi_interactive'
   */
  Set_sHMIComDisp(LocalVar_sHMIComDisp);

  /* SignalConversion: '<Root>/Signal Copy14' */
  Set_sMsgMnger_TextDisp(LocalVar_sMsgMnger_TextDisp);

  /* SignalConversion: '<Root>/Signal Copy20' */
  Set_sDragParkingLot(LocalVar_sDragParkingLot);

  /* SignalConversion: '<Root>/Signal Copy22' */
  Set_sSlaveLsadFsm(lsad_fsm_adapter_DW.sSlaveLsadFsm);

  /* SignalConversion: '<Root>/Signal Copy23' incorporates:
   *  ModelReference: '<Root>/common_condition_adapter'
   */
  Set_sPaStateAdptr(lsad_fsm_adapter_DW.sPaStateAdptr);

  /* Update for UnitDelay: '<Root>/Unit Delay7' */
  lsad_fsm_adapter_DW.UnitDelay7_DSTATE = lsad_fsm_adapter_DW.sSlaveLsadFsm;

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  lsad_fsm_adapter_DW.UnitDelay_DSTATE = lsad_fsm_adapter_DW.sSlaveLsadFsm;
}

/* Model initialize function */
void lsad_fsm_adapter_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)&lsad_fsm_adapter_DW, 0,
                sizeof(DW_lsad_fsm_adapter_T));

  {
    lsad_fsm_adapter_DW.sPecpPLDInfo = lsad_fsm_adapter_rtZtPecpPLDInfo;
    lsad_fsm_adapter_DW.sRelatedModuleInfo =
      lsad_fsm_adapter_rtZtRelatedModuleInfo;
  }

  /* Model Initialize function for ModelReference Block: '<Root>/common_condition_adapter' */
  common_condition_adapter_initialize();

  /* Model Initialize function for ModelReference Block: '<Root>/hmi_interactive' */
  hmi_interactive_initialize();

  /* Model Initialize function for ModelReference Block: '<Root>/slave_lsad_fsm' */
  slave_lsad_fsm_initialize();

  /* SystemInitialize for ModelReference generated from: '<Root>/slave_lsad_fsm' */
  slave_lsad_fsm_Init();

  /* SystemInitialize for ModelReference: '<Root>/hmi_interactive' */
  hmi_interactive_Init();
}

/* Model terminate function */
void lsad_fsm_adapter_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
