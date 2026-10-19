/*
 * File: slave_lsad_fsm.c
 *
 * Code generated for Simulink model 'slave_lsad_fsm'.
 *
 * Model version                  : 3.2732
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Tue Feb 25 10:15:32 2025
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

#include "slave_lsad_fsm.h"

/* Named constants for Chart: '<Root>/slave_lsad_fsm_stateflow' */
#define slave_lsad_fsm_IN_APAModeSelect ((uint8_T)1U)
#define slave_lsad_fsm_IN_APAPrkCnfm   ((uint8_T)2U)
#define slave_lsad_fsm_IN_APAPrkIn     ((uint8_T)1U)
#define slave_lsad_fsm_IN_APAPrkInConfirm ((uint8_T)1U)
#define slave_lsad_fsm_IN_APAPrkInSearch ((uint8_T)2U)
#define slave_lsad_fsm_IN_APAPrkOut    ((uint8_T)2U)
#define slave_lsad_fsm_IN_APAPrkOutConfirm ((uint8_T)1U)
#define slave_lsad_fsm_IN_APASuppression ((uint8_T)3U)
#define slave_lsad_fsm_IN_BackgroundCruiseReadyDisable ((uint8_T)1U)
#define slave_lsad_fsm_IN_BackgroundCruiseReadyEnable ((uint8_T)2U)
#define slave_lsad_fsm_IN_BackgroundRecordDisable ((uint8_T)1U)
#define slave_lsad_fsm_IN_BackgroundRecordEnable ((uint8_T)2U)
#define slave_lsad_fsm_IN_BackgroundSearchDisable ((uint8_T)1U)
#define slave_lsad_fsm_IN_CruisingReady ((uint8_T)3U)
#define slave_lsad_fsm_IN_Eol          ((uint8_T)1U)
#define slave_lsad_fsm_IN_FuncAfterSelect ((uint8_T)2U)
#define slave_lsad_fsm_IN_FuncQuit     ((uint8_T)3U)
#define slave_lsad_fsm_IN_FuncSelect   ((uint8_T)4U)
#define slave_lsad_fsm_IN_FuncStandby  ((uint8_T)5U)
#define slave_lsad_fsm_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define slave_lsad_fsm_IN_RA           ((uint8_T)4U)
#define slave_lsad_fsm_IN_RPAPrkCnfm   ((uint8_T)5U)
#define slave_lsad_fsm_IN_RPAPrkIn     ((uint8_T)1U)
#define slave_lsad_fsm_IN_RPAPrkInConfirm ((uint8_T)1U)
#define slave_lsad_fsm_IN_RPAPrkInSearch ((uint8_T)2U)
#define slave_lsad_fsm_IN_RPAPrkOutConfirm ((uint8_T)2U)
#define slave_lsad_fsm_IN_RPAStraight  ((uint8_T)3U)
#define slave_lsad_fsm_IN_Remote       ((uint8_T)6U)
#define slave_lsad_fsm_IN_RemoteOK     ((uint8_T)7U)

/* Block states (default storage) */
#define CtrlPara_START_SEC_VAR
#include "proj_MemMap.h"
DW_slave_lsad_fsm_f_T slave_lsad_fsm_DW;
#define CtrlPara_STOP_SEC_VAR
#include "proj_MemMap.h"
/* Forward declaration for local functions */
static void slave_lsad_fsm_APAPrkCnfm(const boolean_T *bAPA2RPA, const boolean_T
  *bAPAPICnfm2Hand, const boolean_T *bAPAPOCnfm2Hand, const boolean_T
  *bAPAPICnfm, const boolean_T *bAPAPrkIn);
static void slave_lsad_fsm_RPAPrkCnfm(void);
static void slave_lsad_fsm_FuncSelect(const boolean_T *bAPA2RPA, const boolean_T
  *bAPAModeSelect, const boolean_T *bAPAPICnfm2Hand, const boolean_T
  *bAPAPOCnfm2Hand, const boolean_T *bAPAPICnfm, const boolean_T *bAPAPrkIn);

/* Function for Chart: '<Root>/slave_lsad_fsm_stateflow' */
static void slave_lsad_fsm_APAPrkCnfm(const boolean_T *bAPA2RPA, const boolean_T
  *bAPAPICnfm2Hand, const boolean_T *bAPAPOCnfm2Hand, const boolean_T
  *bAPAPICnfm, const boolean_T *bAPAPrkIn)
{
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  if (*bAPA2RPA)
  {
    slave_lsad_fsm_DW.bitsForTID0.is_APAPrkIn =
      slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
    slave_lsad_fsm_DW.bitsForTID0.is_APAPrkOut =
      slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
    slave_lsad_fsm_DW.bitsForTID0.is_APAPrkCnfm =
      slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
    slave_lsad_fsm_DW.bitsForTID0.is_FuncSelect = slave_lsad_fsm_IN_Remote;
    slave_lsad_fsm_DW.eLsadFuncType = LSAD_FUNC_TYPE_NONE;
    slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_RPA_REMOTE_CONNECT;
  }
  else
  {
    guard1 = false;
    guard2 = false;
    if (slave_lsad_fsm_DW.bitsForTID0.bAPAPrkModChng)
    {
      if (*bAPAPrkIn)
      {
        if (slave_lsad_fsm_DW.bitsForTID0.bAPASuppres)
        {
          slave_lsad_fsm_DW.bitsForTID0.is_APAPrkOut =
            slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
          slave_lsad_fsm_DW.bitsForTID0.is_APAPrkCnfm =
            slave_lsad_fsm_IN_APAPrkIn;
          slave_lsad_fsm_DW.eLsadFuncType = LSAD_PARK_IN;
          slave_lsad_fsm_DW.bitsForTID0.is_APAPrkIn =
            slave_lsad_fsm_IN_APASuppression;
          slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_APA_PI_SUPPRESSION;
        }
        else if (slave_lsad_fsm_DW.bitsForTID0.bAPAPISrch)
        {
          slave_lsad_fsm_DW.bitsForTID0.is_APAPrkOut =
            slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
          slave_lsad_fsm_DW.bitsForTID0.is_APAPrkCnfm =
            slave_lsad_fsm_IN_APAPrkIn;
          slave_lsad_fsm_DW.eLsadFuncType = LSAD_PARK_IN;
          slave_lsad_fsm_DW.bitsForTID0.is_APAPrkIn =
            slave_lsad_fsm_IN_APAPrkInSearch;
          slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_APA_PI_SEARCH;
        }
        else if (*bAPAPICnfm)
        {
          slave_lsad_fsm_DW.bitsForTID0.is_APAPrkOut =
            slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
          slave_lsad_fsm_DW.bitsForTID0.is_APAPrkCnfm =
            slave_lsad_fsm_IN_APAPrkIn;
          slave_lsad_fsm_DW.eLsadFuncType = LSAD_PARK_IN;
          slave_lsad_fsm_DW.bitsForTID0.is_APAPrkIn =
            slave_lsad_fsm_IN_APAPrkInConfirm;
          slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_APA_PI_CONFIRM;
        }
        else
        {
          guard2 = true;
        }
      }
      else
      {
        guard2 = true;
      }
    }
    else
    {
      guard1 = true;
    }

    if (guard2)
    {
      if (slave_lsad_fsm_DW.bitsForTID0.bAPAPrkOut)
      {
        slave_lsad_fsm_DW.bitsForTID0.is_APAPrkIn =
          slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
        slave_lsad_fsm_DW.bitsForTID0.is_APAPrkCnfm =
          slave_lsad_fsm_IN_APAPrkOut;
        slave_lsad_fsm_DW.eLsadFuncType = LSAD_PARK_OUT;
        slave_lsad_fsm_DW.bitsForTID0.is_APAPrkOut =
          slave_lsad_fsm_IN_APAPrkOutConfirm;
        slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_APA_PO_CONFIRM;
      }
      else
      {
        guard1 = true;
      }
    }

    if (guard1)
    {
      if (((uint32_T)slave_lsad_fsm_DW.bitsForTID0.is_APAPrkCnfm) ==
          slave_lsad_fsm_IN_APAPrkIn)
      {
        slave_lsad_fsm_DW.eLsadFuncType = LSAD_PARK_IN;
        if (slave_lsad_fsm_DW.bitsForTID0.bAPASuppres)
        {
          slave_lsad_fsm_DW.bitsForTID0.is_APAPrkIn =
            slave_lsad_fsm_IN_APASuppression;
          slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_APA_PI_SUPPRESSION;
        }
        else if (slave_lsad_fsm_DW.bitsForTID0.bAPAPISrch)
        {
          slave_lsad_fsm_DW.bitsForTID0.is_APAPrkIn =
            slave_lsad_fsm_IN_APAPrkInSearch;
          slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_APA_PI_SEARCH;
        }
        else if (*bAPAPICnfm)
        {
          slave_lsad_fsm_DW.bitsForTID0.is_APAPrkIn =
            slave_lsad_fsm_IN_APAPrkInConfirm;
          slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_APA_PI_CONFIRM;
        }
        else
        {
          switch (slave_lsad_fsm_DW.bitsForTID0.is_APAPrkIn)
          {
           case slave_lsad_fsm_IN_APAPrkInConfirm:
            if (*bAPAPICnfm2Hand)
            {
              slave_lsad_fsm_DW.bitsForTID0.is_APAPrkIn =
                slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
              slave_lsad_fsm_DW.bitsForTID0.is_APAPrkCnfm =
                slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
              slave_lsad_fsm_DW.bitsForTID0.is_FuncSelect =
                slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
              slave_lsad_fsm_DW.bitsForTID0.is_c6_slave_lsad_fsm =
                slave_lsad_fsm_IN_FuncAfterSelect;
              slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_AFTER_SELECT;
            }
            else
            {
              slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_APA_PI_CONFIRM;
            }
            break;

           case slave_lsad_fsm_IN_APAPrkInSearch:
            slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_APA_PI_SEARCH;
            break;

           default:
            /* case IN_APASuppression: */
            slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_APA_PI_SUPPRESSION;
            break;
          }
        }
      }
      else
      {
        /* case IN_APAPrkOut: */
        slave_lsad_fsm_DW.eLsadFuncType = LSAD_PARK_OUT;
        if (((uint32_T)slave_lsad_fsm_DW.bitsForTID0.is_APAPrkOut) ==
            slave_lsad_fsm_IN_APAPrkOutConfirm)
        {
          if (*bAPAPOCnfm2Hand)
          {
            slave_lsad_fsm_DW.bitsForTID0.is_APAPrkOut =
              slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
            slave_lsad_fsm_DW.bitsForTID0.is_APAPrkCnfm =
              slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
            slave_lsad_fsm_DW.bitsForTID0.is_FuncSelect =
              slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
            slave_lsad_fsm_DW.bitsForTID0.is_c6_slave_lsad_fsm =
              slave_lsad_fsm_IN_FuncAfterSelect;
            slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_AFTER_SELECT;
          }
          else
          {
            slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_APA_PO_CONFIRM;
          }
        }
        else
        {
          /* case IN_APAPrkOutSuppression: */
          slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_APA_PO_SUPPRESSION;
        }
      }
    }
  }
}

/* Function for Chart: '<Root>/slave_lsad_fsm_stateflow' */
static void slave_lsad_fsm_RPAPrkCnfm(void)
{
  switch (slave_lsad_fsm_DW.bitsForTID0.is_RPAPrkCnfm)
  {
   case slave_lsad_fsm_IN_RPAPrkIn:
    slave_lsad_fsm_DW.eLsadFuncType = LSAD_PARK_IN;
    switch (slave_lsad_fsm_DW.bitsForTID0.is_RPAPrkIn)
    {
     case slave_lsad_fsm_IN_RPAPrkInConfirm:
      slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_RPA_PI_CONFIRM;
      break;

     case slave_lsad_fsm_IN_RPAPrkInSearch:
      slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_RPA_PI_SEARCH;
      break;

     default:
      /* case IN_RPASuppression: */
      slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_RPA_PI_SUPPRESSION;
      break;
    }
    break;

   case slave_lsad_fsm_IN_RPAPrkOutConfirm:
    slave_lsad_fsm_DW.eLsadFuncType = LSAD_PARK_OUT;
    slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_RPA_PO_CONFIRM;
    break;

   default:
    /* case IN_RPAStraight: */
    if (slave_lsad_fsm_DW.bitsForTID0.bRPAStraight2Hand)
    {
      slave_lsad_fsm_DW.bitsForTID0.is_RPAPrkCnfm =
        slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
      slave_lsad_fsm_DW.bitsForTID0.is_FuncSelect =
        slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
      slave_lsad_fsm_DW.bitsForTID0.is_c6_slave_lsad_fsm =
        slave_lsad_fsm_IN_FuncAfterSelect;
      slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_AFTER_SELECT;
    }
    else
    {
      slave_lsad_fsm_DW.eLsadFuncType = LSAD_PARK_STRAIGHT;
      slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_RPA_PARK_STRAIGHT;
    }
    break;
  }
}

/* Function for Chart: '<Root>/slave_lsad_fsm_stateflow' */
static void slave_lsad_fsm_FuncSelect(const boolean_T *bAPA2RPA, const boolean_T
  *bAPAModeSelect, const boolean_T *bAPAPICnfm2Hand, const boolean_T
  *bAPAPOCnfm2Hand, const boolean_T *bAPAPICnfm, const boolean_T *bAPAPrkIn)
{
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  if (slave_lsad_fsm_DW.bitsForTID0.bFuncSelect2Quit)
  {
    slave_lsad_fsm_DW.bitsForTID0.is_APAPrkIn =
      slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
    slave_lsad_fsm_DW.bitsForTID0.is_APAPrkOut =
      slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
    slave_lsad_fsm_DW.bitsForTID0.is_APAPrkCnfm =
      slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
    slave_lsad_fsm_DW.bitsForTID0.is_RPAPrkIn =
      slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
    slave_lsad_fsm_DW.bitsForTID0.is_RPAPrkCnfm =
      slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
    slave_lsad_fsm_DW.bitsForTID0.is_FuncSelect =
      slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
    slave_lsad_fsm_DW.bitsForTID0.is_c6_slave_lsad_fsm =
      slave_lsad_fsm_IN_FuncQuit;
    slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_QUIT;
  }
  else
  {
    guard1 = false;
    guard2 = false;
    switch (slave_lsad_fsm_DW.bitsForTID0.is_FuncSelect)
    {
     case slave_lsad_fsm_IN_APAModeSelect:
      if (*bAPAModeSelect)
      {
        if (*bAPAPrkIn)
        {
          if (slave_lsad_fsm_DW.bitsForTID0.bAPASuppres)
          {
            slave_lsad_fsm_DW.bitsForTID0.is_FuncSelect =
              slave_lsad_fsm_IN_APAPrkCnfm;
            slave_lsad_fsm_DW.bitsForTID0.is_APAPrkCnfm =
              slave_lsad_fsm_IN_APAPrkIn;
            slave_lsad_fsm_DW.eLsadFuncType = LSAD_PARK_IN;
            slave_lsad_fsm_DW.bitsForTID0.is_APAPrkIn =
              slave_lsad_fsm_IN_APASuppression;
            slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_APA_PI_SUPPRESSION;
          }
          else if (slave_lsad_fsm_DW.bitsForTID0.bAPAPISrch)
          {
            slave_lsad_fsm_DW.bitsForTID0.is_FuncSelect =
              slave_lsad_fsm_IN_APAPrkCnfm;
            slave_lsad_fsm_DW.bitsForTID0.is_APAPrkCnfm =
              slave_lsad_fsm_IN_APAPrkIn;
            slave_lsad_fsm_DW.eLsadFuncType = LSAD_PARK_IN;
            slave_lsad_fsm_DW.bitsForTID0.is_APAPrkIn =
              slave_lsad_fsm_IN_APAPrkInSearch;
            slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_APA_PI_SEARCH;
          }
          else if (*bAPAPICnfm)
          {
            slave_lsad_fsm_DW.bitsForTID0.is_FuncSelect =
              slave_lsad_fsm_IN_APAPrkCnfm;
            slave_lsad_fsm_DW.bitsForTID0.is_APAPrkCnfm =
              slave_lsad_fsm_IN_APAPrkIn;
            slave_lsad_fsm_DW.eLsadFuncType = LSAD_PARK_IN;
            slave_lsad_fsm_DW.bitsForTID0.is_APAPrkIn =
              slave_lsad_fsm_IN_APAPrkInConfirm;
            slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_APA_PI_CONFIRM;
          }
          else
          {
            guard2 = true;
          }
        }
        else
        {
          guard2 = true;
        }
      }
      else
      {
        guard1 = true;
      }
      break;

     case slave_lsad_fsm_IN_APAPrkCnfm:
      slave_lsad_fsm_APAPrkCnfm(bAPA2RPA, bAPAPICnfm2Hand, bAPAPOCnfm2Hand,
        bAPAPICnfm, bAPAPrkIn);
      break;

     case slave_lsad_fsm_IN_CruisingReady:
      if (slave_lsad_fsm_DW.bitsForTID0.bCruisingReady2Hand)
      {
        slave_lsad_fsm_DW.bitsForTID0.is_FuncSelect =
          slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
        slave_lsad_fsm_DW.bitsForTID0.is_c6_slave_lsad_fsm =
          slave_lsad_fsm_IN_FuncAfterSelect;
        slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_AFTER_SELECT;
      }
      else
      {
        slave_lsad_fsm_DW.eLsadFuncType = LSAD_CRUISE;
        slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_CRUISE_READY;
      }
      break;

     case slave_lsad_fsm_IN_RA:
      if (slave_lsad_fsm_DW.bitsForTID0.bRAReady2Hand)
      {
        slave_lsad_fsm_DW.bitsForTID0.is_FuncSelect =
          slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
        slave_lsad_fsm_DW.bitsForTID0.is_c6_slave_lsad_fsm =
          slave_lsad_fsm_IN_FuncAfterSelect;
        slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_AFTER_SELECT;
      }
      else
      {
        slave_lsad_fsm_DW.eLsadFuncType = LSAD_RA;
        slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_RA_READY;
      }
      break;

     case slave_lsad_fsm_IN_RPAPrkCnfm:
      slave_lsad_fsm_RPAPrkCnfm();
      break;

     case slave_lsad_fsm_IN_Remote:
      slave_lsad_fsm_DW.bitsForTID0.is_FuncSelect = slave_lsad_fsm_IN_RemoteOK;
      slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_RPA_REMOTE_OK;
      break;

     default:
      /* case IN_RemoteOK: */
      slave_lsad_fsm_DW.bitsForTID0.is_FuncSelect = slave_lsad_fsm_IN_RPAPrkCnfm;
      slave_lsad_fsm_DW.bitsForTID0.is_RPAPrkCnfm =
        slave_lsad_fsm_IN_RPAStraight;
      slave_lsad_fsm_DW.eLsadFuncType = LSAD_PARK_STRAIGHT;
      slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_RPA_PARK_STRAIGHT;
      break;
    }

    if (guard2)
    {
      if (slave_lsad_fsm_DW.bitsForTID0.bAPAPrkOut)
      {
        slave_lsad_fsm_DW.bitsForTID0.is_FuncSelect =
          slave_lsad_fsm_IN_APAPrkCnfm;
        slave_lsad_fsm_DW.bitsForTID0.is_APAPrkCnfm =
          slave_lsad_fsm_IN_APAPrkOut;
        slave_lsad_fsm_DW.eLsadFuncType = LSAD_PARK_OUT;
        slave_lsad_fsm_DW.bitsForTID0.is_APAPrkOut =
          slave_lsad_fsm_IN_APAPrkOutConfirm;
        slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_APA_PO_CONFIRM;
      }
      else
      {
        guard1 = true;
      }
    }

    if (guard1)
    {
      slave_lsad_fsm_DW.eLsadFuncType = LSAD_FUNC_TYPE_NONE;
      slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_APA_MODE_SELECT;
    }
  }
}

/* System initialize for referenced model: 'slave_lsad_fsm' */
void slave_lsad_fsm_Init(void)
{
  /* SystemInitialize for Chart: '<Root>/slave_lsad_fsm_stateflow' */
  slave_lsad_fsm_DW.bitsForTID0.is_FuncSelect =
    slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
  slave_lsad_fsm_DW.bitsForTID0.is_APAPrkCnfm =
    slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
  slave_lsad_fsm_DW.bitsForTID0.is_APAPrkIn = slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
  slave_lsad_fsm_DW.bitsForTID0.is_APAPrkOut = slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
  slave_lsad_fsm_DW.bitsForTID0.is_RPAPrkCnfm =
    slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
  slave_lsad_fsm_DW.bitsForTID0.is_RPAPrkIn = slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
  slave_lsad_fsm_DW.bitsForTID0.is_BackgroundCruiseReady =
    slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
  slave_lsad_fsm_DW.bitsForTID0.is_BackgroundRecord =
    slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
  slave_lsad_fsm_DW.bitsForTID0.is_BackgroundSearch =
    slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
  slave_lsad_fsm_DW.bitsForTID0.is_active_c6_slave_lsad_fsm = 0U;
  slave_lsad_fsm_DW.bitsForTID0.is_c6_slave_lsad_fsm =
    slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
  slave_lsad_fsm_DW.eLsadFuncType = LSAD_FUNC_TYPE_NONE;
  slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_STANDBY;
  slave_lsad_fsm_DW.eBckgrndRecordSts = BACKGROUND_MODULE_STS_DISABLE;
  slave_lsad_fsm_DW.eBckgrndCruiseReadySts = BACKGROUND_MODULE_STS_DISABLE;
  slave_lsad_fsm_DW.eBckgrndSearchSts = BACKGROUND_MODULE_STS_DISABLE;
}

/* Output and update for referenced model: 'slave_lsad_fsm' */
void slave_lsad_fsm(const tPAHmiRx *rtu_sPAHmiRx, const tPaStateCommon
                    *rtu_sPaStateCommon, const tVehCommon *rtu_sVehCommon, const
                    tVehDataRx *rtu_sVehDataRx, const tRelatedModuleInfo
                    *rtu_sRelatedModuleInfo, const boolean_T
                    *rtu_sHpaStateCommon_sHPACondiOverFlag_bHpaQuitDurattime,
                    const tQuitEvnt *rtu_sHpaStateCommon_sHPAEvnt_eHPAQuitEvnt,
                    const tIntrptEvnt
                    *rtu_sHpaStateCommon_sHPAEvnt_eHPAIntrptEvnt, const
                    tHPAHmiRx *rtu_sHPAHmiRx, const tRAHmiRx *rtu_sRAHmiRx,
                    const boolean_T
                    *rtu_sRaStateCommon_sRACondiOverFlag_bRAQuitDurattime, const
                    tRAIntrptEvnt *rtu_sRaStateCommon_sRAEvnt_eRAIntrptEvnt,
                    const tRAQuitEvnt *rtu_sRaStateCommon_sRAEvnt_eRAQuitEvnt,
                    const tDiagInfo *rtu_sDiagInfo, const tMasterLsadFsm
                    *rtu_sLastMasterLsadFsm, const tSlaveLsadFsm
                    *rtu_sLastSlaveLsadFsm, const tPaStateAdptr
                    *rtu_sPaStateAdptr, tSlaveLsadFsm *rty_sSlaveLsadFsm)
{
  int32_T tmp;
  uint8_T LocalVar_u8LsadStSResetPEB;
  boolean_T LocalVar_Equal;
  boolean_T LocalVar_Equal2_m;
  boolean_T LocalVar_Equal3_b;
  boolean_T LocalVar_Equal5;
  boolean_T LocalVar_Equal5_e;
  boolean_T LocalVar_Equal5_i;
  boolean_T LocalVar_Equal7;
  boolean_T LocalVar_OR1;
  boolean_T LocalVar_OR3;
  boolean_T bAPAModeSelect;
  boolean_T bAPAPICnfm;
  boolean_T bAPAPOCnfm2Hand;
  boolean_T bAPAPrkIn;
  boolean_T bBckgrndCruiseReadyDisable2Enable;
  boolean_T bBckgrndRecordDisable2Enable;
  boolean_T bStandby2CruisingReady;
  tLSAD_DriverCtrlCommand LocalVar_eDriverCtrlCommand;
  tLSAD_FuncSts LocalVar_eLsadFuncSts;
  tLSAD_FuncType LocalVar_eLsadFuncType;

  /* RelationalOperator: '<S1>/Equal1' incorporates:
   *  Constant: '<S31>/Constant'
   */
  LocalVar_Equal7 = (rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
                     FUNC_STS_APA_PI_SEARCH);

  /* RelationalOperator: '<S1>/Equal3' incorporates:
   *  Constant: '<S35>/Constant'
   */
  LocalVar_OR3 = (rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
                  FUNC_STS_APA_PO_SUPPRESSION);

  /* RelationalOperator: '<S1>/Equal4' incorporates:
   *  Constant: '<S34>/Constant'
   */
  LocalVar_Equal5_e = (rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
                       FUNC_STS_APA_PI_SUPPRESSION);

  /* RelationalOperator: '<S1>/Equal6' incorporates:
   *  Constant: '<S36>/Constant'
   */
  LocalVar_Equal2_m = (rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
                       FUNC_STS_APA_PI_CONFIRM);

  /* RelationalOperator: '<S1>/Equal7' incorporates:
   *  Constant: '<S37>/Constant'
   */
  LocalVar_Equal3_b = (rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
                       FUNC_STS_APA_PO_CONFIRM);

  /* Logic: '<S1>/Logical Operator1' incorporates:
   *  Constant: '<S33>/Constant'
   *  Logic: '<S1>/Logical Operator'
   *  RelationalOperator: '<S1>/Equal8'
   */
  LocalVar_OR3 = ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
    ((int32_T)((((boolean_T)((int32_T)((LocalVar_Equal5_e ? ((int32_T)1) :
    ((int32_T)0)) | (LocalVar_Equal7 ? ((int32_T)1) : ((int32_T)0))))) ?
                ((int32_T)1) : ((int32_T)0)) | (LocalVar_Equal2_m ? ((int32_T)1)
    : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) | (LocalVar_OR3 ?
    ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
    (LocalVar_Equal3_b ? ((int32_T)1) : ((int32_T)0))))) &
    (rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkWakeup == SWT_ON);

  /* Logic: '<S2>/Logical Operator3' incorporates:
   *  Constant: '<S38>/Constant'
   *  Constant: '<S39>/Constant'
   *  Constant: '<S40>/Constant'
   *  RelationalOperator: '<S2>/Equal1'
   *  RelationalOperator: '<S2>/Equal2'
   *  RelationalOperator: '<S2>/Equal5'
   */
  bAPAModeSelect = ((boolean_T)((int32_T)(((rtu_sPaStateAdptr->sCondiHMI.eAPAMod
    == APA_MODE_PARK_IN) ? ((int32_T)1) : ((int32_T)0)) |
    ((rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_SELF_SELECT) ? ((int32_T)
    1) : ((int32_T)0))))) | (rtu_sPaStateAdptr->sCondiHMI.eAPAMod ==
    APA_MODE_PARK_OUT);

  /* RelationalOperator: '<S3>/Equal7' incorporates:
   *  Constant: '<S46>/Constant'
   */
  LocalVar_Equal7 = (rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
                     FUNC_STS_APA_PI_CONFIRM);

  /* RelationalOperator: '<S3>/Equal9' incorporates:
   *  Constant: '<S47>/Constant'
   */
  LocalVar_Equal3_b = (rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_STANDBY);

  /* Logic: '<S48>/OR1' incorporates:
   *  Constant: '<S44>/Constant'
   *  Logic: '<S48>/NOT'
   *  Logic: '<S48>/OR'
   *  RelationalOperator: '<S3>/Equal5'
   *  UnitDelay: '<S48>/Unit Delay2'
   */
  LocalVar_OR1 = (rtu_sRelatedModuleInfo->eCtrlSts == APA_CTRL_COMPLETE_HPP) |
    ((boolean_T)((int32_T)((((boolean_T)((int32_T)((LocalVar_Equal3_b ?
            ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)) &
       (slave_lsad_fsm_DW.bitsForTID0.UnitDelay2_DSTATE_j ? ((int32_T)1) :
        ((int32_T)0)))));

  /* Logic: '<S3>/Logical Operator' incorporates:
   *  Constant: '<S41>/Constant'
   *  Constant: '<S42>/Constant'
   *  Constant: '<S43>/Constant'
   *  Constant: '<S45>/Constant'
   *  Logic: '<S3>/Logical Operator1'
   *  Logic: '<S3>/Logical Operator2'
   *  Logic: '<S3>/Logical Operator3'
   *  Logic: '<S3>/Logical Operator5'
   *  RelationalOperator: '<S3>/Equal1'
   *  RelationalOperator: '<S3>/Equal2'
   *  RelationalOperator: '<S3>/Equal3'
   *  RelationalOperator: '<S3>/Equal6'
   */
  LocalVar_Equal7 = ((boolean_T)((int32_T)((((boolean_T)((int32_T)
    ((LocalVar_Equal7 ? ((int32_T)1) : ((int32_T)0)) &
     (rtu_sVehDataRx->sVehVCUInfo.bBrkPedal ? ((int32_T)1) : ((int32_T)0))))) ?
    ((int32_T)1) : ((int32_T)0)) & (rtu_sVehCommon->sCondiVeh.bVehStill ?
    ((int32_T)1) : ((int32_T)0))))) & ((boolean_T)((int32_T)((((boolean_T)
    ((int32_T)((((boolean_T)((int32_T)(((rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkWorkMd ==
    PRK_WORK_START) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
    (((rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_PARK_IN) ? ((int32_T)1) :
      ((int32_T)0)) | ((rtu_sPaStateAdptr->sCondiHMI.eAPAMod ==
                        APA_MODE_SELF_SELECT) ? ((int32_T)1) : ((int32_T)0))))) ?
    ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
               (rtu_sVehCommon->sCondiPlatform.bRecomdSlot ? ((int32_T)1) :
                ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)
    ((int32_T)((LocalVar_OR1 ? ((int32_T)1) : ((int32_T)0)) &
               ((rtu_sRelatedModuleInfo->eHandshakeSts == HANDSHAKE_UNCONTROLLED)
                ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)))));

  /* RelationalOperator: '<S4>/Equal4' incorporates:
   *  Constant: '<S52>/Constant'
   */
  LocalVar_Equal2_m = (rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
                       FUNC_STS_APA_PO_CONFIRM);

  /* Logic: '<S4>/Logical Operator' incorporates:
   *  Constant: '<S49>/Constant'
   *  Constant: '<S50>/Constant'
   *  Constant: '<S51>/Constant'
   *  RelationalOperator: '<S4>/Equal1'
   *  RelationalOperator: '<S4>/Equal2'
   *  RelationalOperator: '<S4>/Equal3'
   */
  bAPAPOCnfm2Hand = ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
    ((int32_T)((((boolean_T)((int32_T)((rtu_sVehDataRx->sVehVCUInfo.bBrkPedal ?
    ((int32_T)1) : ((int32_T)0)) & ((rtu_sPaStateAdptr->sCondiHMI.ePODir !=
    PO_DIR_NO_REQ) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)
    0)) & ((rtu_sPaStateAdptr->sCondiHMI.ePOSlotType != PO_SLOT_TYPE_NONE) ?
           ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
    (rtu_sVehCommon->sCondiVeh.bVehStill ? ((int32_T)1) : ((int32_T)0))))) ?
    ((int32_T)1) : ((int32_T)0)) & ((rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkWorkMd ==
    PRK_WORK_START) ? ((int32_T)1) : ((int32_T)0))))) & LocalVar_Equal2_m;

  /* RelationalOperator: '<S5>/Equal4' incorporates:
   *  Constant: '<S56>/Constant'
   */
  LocalVar_Equal3_b = (rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
                       FUNC_STS_APA_PI_SEARCH);

  /* RelationalOperator: '<S5>/Equal3' incorporates:
   *  Constant: '<S55>/Constant'
   */
  LocalVar_Equal = (rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
                    FUNC_STS_APA_PO_CONFIRM);

  /* Logic: '<S5>/Logical Operator6' incorporates:
   *  Constant: '<S53>/Constant'
   *  Constant: '<S54>/Constant'
   *  Logic: '<S5>/EMOR'
   *  Logic: '<S5>/Logical Operator'
   *  Logic: '<S5>/Logical Operator1'
   *  Logic: '<S5>/Logical Operator4'
   *  RelationalOperator: '<S5>/Equal1'
   *  RelationalOperator: '<S5>/Equal2'
   */
  bAPAPICnfm = ((boolean_T)((int32_T)((((boolean_T)((int32_T)
    (((rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_PARK_IN) ? ((int32_T)1) :
      ((int32_T)0)) & (((boolean_T)((int32_T)
    ((rtu_sVehCommon->sCondiPlatform.bRecomdSlot ? ((int32_T)1) : ((int32_T)0))
     & (rtu_sVehCommon->sCondiVeh.bVehStill ? ((int32_T)1) : ((int32_T)0))))) ?
                       ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sPaStateAdptr->sCondiHMI.eAPAMod ==
                      APA_MODE_SELF_SELECT) ? ((int32_T)1) : ((int32_T)0))))) &
    ((boolean_T)((int32_T)((LocalVar_Equal3_b ? ((int32_T)1) : ((int32_T)0)) |
       (LocalVar_Equal ? ((int32_T)1) : ((int32_T)0)))));

  /* Logic: '<S6>/Logical Operator' incorporates:
   *  Constant: '<S57>/Constant'
   *  Constant: '<S58>/Constant'
   *  Constant: '<S6>/Constant23'
   *  Logic: '<S6>/Logical Operator1'
   *  RelationalOperator: '<S6>/Equal'
   *  RelationalOperator: '<S6>/Equal1'
   *  RelationalOperator: '<S6>/Relational Operator8'
   */
  bAPAPrkIn = ((boolean_T)((int32_T)(((rtu_sPaStateAdptr->sCondiHMI.eAPAMod ==
    APA_MODE_PARK_IN) ? ((int32_T)1) : ((int32_T)0)) |
    ((rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_SELF_SELECT) ? ((int32_T)
    1) : ((int32_T)0))))) & (rtu_sVehDataRx->sVehESCInfo.f32VehSpdKph <=
    k_PrkInSrchMaxSpd);

  /* MATLAB Function: '<S7>/APAPrkInSrchDet ' */
  LocalVar_Equal3_b = rtu_sVehCommon->sCondiPlatform.bRecomdSlot ^ 1;
  slave_lsad_fsm_DW.bitsForTID0.bAPAPISrch = (boolean_T)((int32_T)((((boolean_T)
    ((int32_T)((((boolean_T)((int32_T)(((rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
    FUNC_STS_APA_MODE_SELECT) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)
    ((int32_T)(((rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_PARK_IN) ?
                ((int32_T)1) : ((int32_T)0)) |
               ((rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_SELF_SELECT) ?
                ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)))))
                ? ((int32_T)1) : ((int32_T)0)) &
               ((rtu_sVehDataRx->sVehESCInfo.f32VehSpdKph <= k_SuppressQuitSpd) ?
                ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
    (((boolean_T)((int32_T)((((boolean_T)((int32_T)
    (((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_SUPPRESSION) ?
      ((int32_T)1) : ((int32_T)0)) &
     ((rtu_sPaStateAdptr->sPAEvntAdptr.ePASuspendEvnt == SUSPEND_NONE) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
    (((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
    (((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PI_CONFIRM) ?
      ((int32_T)1) : ((int32_T)0)) & ((rtu_sPaStateAdptr->sCondiHMI.eAPAMod ==
    APA_MODE_PARK_IN) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) & (((boolean_T)((int32_T)((((boolean_T)((int32_T)
    ((rtu_sVehCommon->sCondiVeh.bVehStill ? ((int32_T)1) : ((int32_T)0)) ^ 1))) ?
    ((int32_T)1) : ((int32_T)0)) | (LocalVar_Equal3_b ? ((int32_T)1) : ((int32_T)
    0))))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
    (((boolean_T)((int32_T)((((boolean_T)((int32_T)
    (((rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_APA_PO_CONFIRM) ?
      ((int32_T)1) : ((int32_T)0)) & ((rtu_sPaStateAdptr->sCondiHMI.eAPAMod ==
    APA_MODE_PARK_IN) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) & (LocalVar_Equal3_b ? ((int32_T)1) : ((int32_T)0))))) ?
     ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) ?
     ((int32_T)1) : ((int32_T)0))));

  /* RelationalOperator: '<S8>/Equal1' incorporates:
   *  Constant: '<S60>/Constant'
   *  UnitDelay: '<S8>/Unit Delay1'
   */
  LocalVar_Equal3_b = (slave_lsad_fsm_DW.UnitDelay1_DSTATE_e != APA_MODE_PARK_IN);

  /* UnitDelay: '<S8>/Unit Delay2' incorporates:
   *  UnitDelay: '<S8>/Unit Delay1'
   */
  slave_lsad_fsm_DW.UnitDelay1_DSTATE_e = slave_lsad_fsm_DW.UnitDelay2_DSTATE;

  /* RelationalOperator: '<S8>/Equal2' incorporates:
   *  Constant: '<S61>/Constant'
   *  UnitDelay: '<S8>/Unit Delay1'
   */
  LocalVar_Equal = (slave_lsad_fsm_DW.UnitDelay1_DSTATE_e !=
                    APA_MODE_SELF_SELECT);

  /* UnitDelay: '<S8>/Unit Delay3' incorporates:
   *  UnitDelay: '<S8>/Unit Delay1'
   */
  slave_lsad_fsm_DW.UnitDelay1_DSTATE_e = slave_lsad_fsm_DW.UnitDelay3_DSTATE;

  /* Logic: '<S8>/Logical Operator3' incorporates:
   *  Constant: '<S62>/Constant'
   *  Constant: '<S63>/Constant'
   *  Constant: '<S64>/Constant'
   *  Constant: '<S65>/Constant'
   *  Logic: '<S8>/Logical Operator'
   *  Logic: '<S8>/Logical Operator1'
   *  Logic: '<S8>/Logical Operator2'
   *  RelationalOperator: '<S8>/Equal3'
   *  RelationalOperator: '<S8>/Equal4'
   *  RelationalOperator: '<S8>/Equal5'
   *  RelationalOperator: '<S8>/Equal6'
   *  UnitDelay: '<S8>/Unit Delay1'
   */
  slave_lsad_fsm_DW.bitsForTID0.bAPAPrkModChng = (boolean_T)((int32_T)
    ((((boolean_T)((int32_T)((((boolean_T)((int32_T)
    (((rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_PARK_IN) ? ((int32_T)1) :
      ((int32_T)0)) & (LocalVar_Equal3_b ? ((int32_T)1) : ((int32_T)0))))) ?
    ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
    (((rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_SELF_SELECT) ? ((int32_T)
    1) : ((int32_T)0)) & (LocalVar_Equal ? ((int32_T)1) : ((int32_T)0))))) ?
    ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
     (((boolean_T)((int32_T)(((rtu_sPaStateAdptr->sCondiHMI.eAPAMod ==
    APA_MODE_PARK_OUT) ? ((int32_T)1) : ((int32_T)0)) &
    ((slave_lsad_fsm_DW.UnitDelay1_DSTATE_e != APA_MODE_PARK_OUT) ? ((int32_T)1)
     : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))));

  /* RelationalOperator: '<S9>/Equal1' incorporates:
   *  Constant: '<S66>/Constant'
   */
  LocalVar_Equal = (rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
                    FUNC_STS_APA_PI_SEARCH);

  /* RelationalOperator: '<S9>/Equal2' incorporates:
   *  Constant: '<S69>/Constant'
   */
  LocalVar_Equal3_b = (rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
                       FUNC_STS_APA_MODE_SELECT);

  /* RelationalOperator: '<S9>/Equal3' incorporates:
   *  Constant: '<S68>/Constant'
   */
  LocalVar_Equal2_m = (rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
                       FUNC_STS_APA_PI_CONFIRM);

  /* RelationalOperator: '<S9>/Equal4' incorporates:
   *  Constant: '<S70>/Constant'
   */
  LocalVar_Equal5_e = (rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
                       FUNC_STS_APA_PI_SUPPRESSION);

  /* Logic: '<S9>/Logical Operator' incorporates:
   *  Constant: '<S67>/Constant'
   *  Logic: '<S9>/Logical Operator1'
   *  RelationalOperator: '<S9>/Equal'
   */
  slave_lsad_fsm_DW.bitsForTID0.bAPAPrkOut = (boolean_T)((int32_T)
    (((rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_PARK_OUT) ? ((int32_T)1)
      : ((int32_T)0)) & (((boolean_T)((int32_T)((((boolean_T)((int32_T)
    ((((boolean_T)((int32_T)((LocalVar_Equal2_m ? ((int32_T)1) : ((int32_T)0)) |
    (LocalVar_Equal ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)
    0)) | (LocalVar_Equal3_b ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | (LocalVar_Equal5_e ? ((int32_T)1) : ((int32_T)0))))) ?
    ((int32_T)1) : ((int32_T)0))));

  /* RelationalOperator: '<S10>/Equal' incorporates:
   *  Constant: '<S71>/Constant'
   */
  slave_lsad_fsm_DW.bitsForTID0.bAPASuppres =
    (rtu_sPaStateAdptr->sPAEvntAdptr.ePASuspendEvnt != SUSPEND_NONE);

  /* Outputs for Atomic SubSystem: '<Root>/AfterSelect2Standby' */
  /* RelationalOperator: '<S12>/Equal4' incorporates:
   *  Constant: '<S77>/Constant'
   */
  LocalVar_Equal3_b = (rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
                       FUNC_STS_AFTER_SELECT);

  /* Logic: '<S12>/AND' incorporates:
   *  Constant: '<S76>/Constant'
   *  RelationalOperator: '<S12>/Equal1'
   */
  LocalVar_Equal5_e = LocalVar_Equal3_b &
    (rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_STANDBY);

  /* End of Outputs for SubSystem: '<Root>/AfterSelect2Standby' */

  /* Outputs for Atomic SubSystem: '<Root>/BckgrndCruiseReadyDisable2EnableDet' */
  /* RelationalOperator: '<S13>/Equal3' incorporates:
   *  Constant: '<S80>/Constant'
   */
  LocalVar_Equal = (rtu_sLastSlaveLsadFsm->eBckgrndCruiseReadySts ==
                    BACKGROUND_MODULE_STS_DISABLE);

  /* RelationalOperator: '<S13>/Equal5' incorporates:
   *  Constant: '<S79>/Constant'
   */
  LocalVar_Equal3_b = (rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_STANDBY);

  /* Logic: '<S13>/Logical Operator' incorporates:
   *  Constant: '<S78>/Constant'
   *  Delay: '<S13>/Delay'
   *  RelationalOperator: '<S13>/Equal1'
   */
  LocalVar_Equal2_m = ((boolean_T)((int32_T)((((boolean_T)((int32_T)
    ((LocalVar_Equal ? ((int32_T)1) : ((int32_T)0)) &
     (slave_lsad_fsm_DW.Delay_DSTATE_f[0] ? ((int32_T)1) : ((int32_T)0))))) ?
    ((int32_T)1) : ((int32_T)0)) & (LocalVar_Equal3_b ? ((int32_T)1) : ((int32_T)
    0))))) & (rtu_sRelatedModuleInfo->eLocSts == LOC_STATUS_SUCCESS);

  /* Update for Delay: '<S13>/Delay' */
  slave_lsad_fsm_DW.Delay_DSTATE_f[0] = slave_lsad_fsm_DW.Delay_DSTATE_f[1];
  slave_lsad_fsm_DW.Delay_DSTATE_f[1] = slave_lsad_fsm_DW.Delay_DSTATE_f[2];
  slave_lsad_fsm_DW.Delay_DSTATE_f[2] = LocalVar_Equal;

  /* End of Outputs for SubSystem: '<Root>/BckgrndCruiseReadyDisable2EnableDet' */

  /* Outputs for Atomic SubSystem: '<Root>/BckgrndCruiseReadyEnable2DisableDet' */
  /* RelationalOperator: '<S14>/Equal5' incorporates:
   *  Constant: '<S82>/Constant'
   */
  LocalVar_Equal = (rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_STANDBY);

  /* Logic: '<S14>/Logical Operator' incorporates:
   *  Constant: '<S81>/Constant'
   *  RelationalOperator: '<S14>/Equal1'
   */
  bBckgrndCruiseReadyDisable2Enable = LocalVar_Equal &
    (rtu_sRelatedModuleInfo->eLocSts != LOC_STATUS_SUCCESS);

  /* End of Outputs for SubSystem: '<Root>/BckgrndCruiseReadyEnable2DisableDet' */

  /* Outputs for Atomic SubSystem: '<Root>/BckgrndRecordDisable2EnableDet' */
  /* RelationalOperator: '<S15>/Equal5' incorporates:
   *  Constant: '<S85>/Constant'
   */
  LocalVar_Equal3_b = (rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_STANDBY);

  /* Switch: '<S95>/Switch1' incorporates:
   *  Constant: '<S89>/Constant'
   *  Constant: '<S90>/Constant'
   *  Constant: '<S91>/Constant'
   *  Constant: '<S92>/Constant'
   *  Constant: '<S93>/Constant'
   *  Constant: '<S94>/Constant'
   *  Constant: '<S95>/Constant Value2'
   *  Logic: '<S88>/EMNOT'
   *  Logic: '<S88>/Logical Operator10'
   *  Logic: '<S88>/Logical Operator11'
   *  Logic: '<S88>/Logical Operator12'
   *  Logic: '<S88>/Logical Operator13'
   *  Logic: '<S88>/Logical Operator9'
   *  RelationalOperator: '<S88>/Equal1'
   *  RelationalOperator: '<S88>/Equal10'
   *  RelationalOperator: '<S88>/Equal11'
   *  RelationalOperator: '<S88>/Equal12'
   *  RelationalOperator: '<S88>/Equal8'
   *  RelationalOperator: '<S88>/Equal9'
   *  Switch: '<S95>/Switch'
   *  UnitDelay: '<S95>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
               ((((boolean_T)((int32_T)(((WHLSPD_FORWARD ==
      rtu_sVehDataRx->sVehESCInfo.eWhlDirRL) ? ((int32_T)1) : ((int32_T)0)) ^ 1)))
                 ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
      (((WHLSPD_FORWARD == rtu_sVehDataRx->sVehESCInfo.eWhlDirRR) ? ((int32_T)1)
        : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
             ((int32_T)0)) | (((boolean_T)((int32_T)
               (((rtu_sVehDataRx->sVehVCUInfo.eVehActualGear == R_GEAR) ?
                 ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)
              0))))) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
           ((((boolean_T)((int32_T)((((boolean_T)((int32_T)(((WHLSPD_BACKWARD ==
    rtu_sVehDataRx->sVehESCInfo.eWhlDirRL) ? ((int32_T)1) : ((int32_T)0)) ^ 1)))
    ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)(((WHLSPD_BACKWARD ==
    rtu_sVehDataRx->sVehESCInfo.eWhlDirRR) ? ((int32_T)1) : ((int32_T)0)) ^ 1)))
    ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
            (((boolean_T)((int32_T)(((rtu_sVehDataRx->sVehVCUInfo.eVehActualGear
    == D_GEAR) ? ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)
              0))))) ? ((int32_T)1) : ((int32_T)0)))))
  {
    slave_lsad_fsm_DW.UnitDelay1_DSTATE_p = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S95>/Unit Delay1' incorporates:
     *  Constant: '<S88>/Constant3'
     *  Sum: '<S95>/Subtraction'
     */
    slave_lsad_fsm_DW.UnitDelay1_DSTATE_p += s_APPManLoopSec;
  }

  /* End of Switch: '<S95>/Switch1' */

  /* Logic: '<S15>/Logical Operator' incorporates:
   *  Abs: '<S15>/Abs'
   *  Constant: '<S15>/Constant'
   *  Constant: '<S15>/Constant1'
   *  Constant: '<S83>/Constant'
   *  Constant: '<S84>/Constant'
   *  Constant: '<S86>/Constant'
   *  Constant: '<S87>/Constant'
   *  Constant: '<S88>/Constant1'
   *  Logic: '<S15>/NOT1'
   *  Logic: '<S15>/OR2'
   *  Logic: '<S15>/OR3'
   *  RelationalOperator: '<S15>/Equal1'
   *  RelationalOperator: '<S15>/Equal2'
   *  RelationalOperator: '<S15>/Equal3'
   *  RelationalOperator: '<S15>/Equal6'
   *  RelationalOperator: '<S15>/Equal7'
   *  RelationalOperator: '<S15>/Equal8'
   *  RelationalOperator: '<S88>/Relational Operator'
   *  UnitDelay: '<S95>/Unit Delay1'
   */
  bBckgrndRecordDisable2Enable = ((boolean_T)((int32_T)((((boolean_T)((int32_T)
    ((((boolean_T)((int32_T)((LocalVar_Equal3_b ? ((int32_T)1) : ((int32_T)0)) &
    ((rtu_sVehDataRx->sVehESCInfo.f32VehSpdKph <= k_RALimitedVehSpdKph) ?
     ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) & ((fabsf
    (rtu_sVehDataRx->sVehEPSInfo.f32StrWhlAngDeg) <= k_RALimitedStrWhlAngDeg) ?
    ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
    (((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
    ((((boolean_T)((int32_T)((rtu_sVehCommon->sCondiVeh.bVehStill ? ((int32_T)1)
    : ((int32_T)0)) & ((rtu_sVehDataRx->sVehVCUInfo.eVehActualGear == R_GEAR) ?
    ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
     ((rtu_sVehDataRx->sVehVCUInfo.eVehActualGear == P_GEAR) ? ((int32_T)1) :
      ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
    ((rtu_sVehDataRx->sVehVCUInfo.eVehActualGear == N_GEAR) ? ((int32_T)1) :
     ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
    ((rtu_sVehDataRx->sVehVCUInfo.eVehActualGear == D_GEAR) ? ((int32_T)1) :
     ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))))) &
    (slave_lsad_fsm_DW.UnitDelay1_DSTATE_p <= 0.2F);

  /* End of Outputs for SubSystem: '<Root>/BckgrndRecordDisable2EnableDet' */

  /* Outputs for Atomic SubSystem: '<Root>/AfterSelect2Standby' */
  /* Switch: '<S125>/Switch1' incorporates:
   *  Constant: '<S123>/Constant'
   *  Constant: '<S124>/Constant'
   *  Constant: '<S125>/Constant Value2'
   *  Logic: '<S28>/Logical Operator'
   *  Logic: '<S28>/Logical Operator1'
   *  RelationalOperator: '<S12>/Equal1'
   *  RelationalOperator: '<S28>/Equal4'
   *  RelationalOperator: '<S28>/Equal5'
   *  Switch: '<S125>/Switch'
   *  UnitDelay: '<S125>/Unit Delay1'
   */
  if ((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts !=
          LSAD_STS_STANDBY) ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)
          ((int32_T)(((rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkWakeup == SWT_ON) ?
                      ((int32_T)1) : ((int32_T)0)) ^ 1))) ? ((int32_T)1) :
         ((int32_T)0)))))
  {
    slave_lsad_fsm_DW.UnitDelay1_DSTATE = 0.0F;
  }
  else
  {
    /* UnitDelay: '<S125>/Unit Delay1' incorporates:
     *  Constant: '<S28>/Constant9'
     *  Sum: '<S125>/Subtraction'
     */
    slave_lsad_fsm_DW.UnitDelay1_DSTATE += 0.02F;
  }

  /* End of Switch: '<S125>/Switch1' */
  /* End of Outputs for SubSystem: '<Root>/AfterSelect2Standby' */

  /* RelationalOperator: '<S24>/Equal4' incorporates:
   *  Constant: '<S116>/Constant'
   */
  LocalVar_Equal3_b = (rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
                       FUNC_STS_RPA_PARK_STRAIGHT);

  /* Logic: '<S24>/Logical Operator1' */
  slave_lsad_fsm_DW.bitsForTID0.bRPAStraight2Hand = (boolean_T)((int32_T)
    ((((boolean_T)((int32_T)((LocalVar_Equal3_b ? ((int32_T)1) : ((int32_T)0)) &
    (rtu_sVehDataRx->sVehVCUInfo.bBrkPedal ? ((int32_T)1) : ((int32_T)0))))) ?
      ((int32_T)1) : ((int32_T)0)) & (rtu_sVehCommon->sCondiVeh.bVehStill ?
    ((int32_T)1) : ((int32_T)0))));

  /* Outputs for Atomic SubSystem: '<Root>/Standby2CruisingReadyDet' */
  /* RelationalOperator: '<S26>/Equal3' incorporates:
   *  Constant: '<S119>/Constant'
   */
  LocalVar_Equal = (rtu_sLastSlaveLsadFsm->eBckgrndCruiseReadySts ==
                    BACKGROUND_MODULE_STS_ENABLE);

  /* Outputs for Atomic SubSystem: '<Root>/AfterSelect2Standby' */
  /* Logic: '<S26>/Logical Operator1' incorporates:
   *  Constant: '<S117>/Constant'
   *  Constant: '<S118>/Constant'
   *  RelationalOperator: '<S12>/Equal1'
   *  RelationalOperator: '<S26>/Equal2'
   *  RelationalOperator: '<S26>/Equal5'
   */
  bStandby2CruisingReady = ((boolean_T)((int32_T)((((boolean_T)((int32_T)
    ((((boolean_T)((int32_T)(((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
    LSAD_STS_STANDBY) ? ((int32_T)1) : ((int32_T)0)) & (LocalVar_Equal ?
    ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
     ((rtu_sHPAHmiRx->eHPAPrkWorkMd == PRK_WORK_START) ? ((int32_T)1) :
      ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
    (rtu_sVehDataRx->sVehVCUInfo.bBrkPedal ? ((int32_T)1) : ((int32_T)0))))) &
    rtu_sVehCommon->sCondiVeh.bVehStill;

  /* End of Outputs for SubSystem: '<Root>/AfterSelect2Standby' */
  /* End of Outputs for SubSystem: '<Root>/Standby2CruisingReadyDet' */

  /* Outputs for Atomic SubSystem: '<Root>/CruisingReady2HandDet' */
  /* RelationalOperator: '<S17>/Equal5' incorporates:
   *  Constant: '<S101>/Constant'
   */
  LocalVar_Equal5_i = (rtu_sLastSlaveLsadFsm->eLsadFuncSts ==
                       FUNC_STS_CRUISE_READY);

  /* Logic: '<S17>/Logical Operator' incorporates:
   *  Delay: '<S17>/Delay'
   */
  slave_lsad_fsm_DW.bitsForTID0.bCruisingReady2Hand = (boolean_T)((int32_T)
    ((LocalVar_Equal5_i ? ((int32_T)1) : ((int32_T)0)) &
     (slave_lsad_fsm_DW.Delay_DSTATE_j[0] ? ((int32_T)1) : ((int32_T)0))));

  /* End of Outputs for SubSystem: '<Root>/CruisingReady2HandDet' */

  /* Outputs for Atomic SubSystem: '<Root>/Cruising2APAPIConfirmDet' */
  /* RelationalOperator: '<S16>/Equal2' incorporates:
   *  Constant: '<S97>/Constant'
   */
  LocalVar_Equal = (rtu_sLastSlaveLsadFsm->eLsadFuncType == LSAD_CRUISE);

  /* End of Outputs for SubSystem: '<Root>/Cruising2APAPIConfirmDet' */

  /* Outputs for Atomic SubSystem: '<Root>/Standby2RAReadyDet' */
  /* RelationalOperator: '<S27>/Equal3' incorporates:
   *  Constant: '<S122>/Constant'
   */
  LocalVar_Equal3_b = (rtu_sLastSlaveLsadFsm->eBckgrndRecordSts ==
                       BACKGROUND_MODULE_STS_ENABLE);

  /* End of Outputs for SubSystem: '<Root>/Standby2RAReadyDet' */

  /* Outputs for Atomic SubSystem: '<Root>/RAReady2HandDet' */
  /* RelationalOperator: '<S23>/Equal5' incorporates:
   *  Constant: '<S115>/Constant'
   */
  LocalVar_Equal5 = (rtu_sLastSlaveLsadFsm->eLsadFuncSts == FUNC_STS_RA_READY);

  /* Logic: '<S23>/Logical Operator' incorporates:
   *  Delay: '<S23>/Delay'
   */
  slave_lsad_fsm_DW.bitsForTID0.bRAReady2Hand = (boolean_T)((int32_T)
    ((LocalVar_Equal5 ? ((int32_T)1) : ((int32_T)0)) &
     (slave_lsad_fsm_DW.Delay_DSTATE_g[0] ? ((int32_T)1) : ((int32_T)0))));

  /* End of Outputs for SubSystem: '<Root>/RAReady2HandDet' */

  /* Outputs for Atomic SubSystem: '<Root>/CruisingReady2HandDet' */
  /* Update for Delay: '<S17>/Delay' */
  slave_lsad_fsm_DW.Delay_DSTATE_j[0] = slave_lsad_fsm_DW.Delay_DSTATE_j[1];

  /* End of Outputs for SubSystem: '<Root>/CruisingReady2HandDet' */

  /* Outputs for Atomic SubSystem: '<Root>/RAReady2HandDet' */
  /* Update for Delay: '<S23>/Delay' */
  slave_lsad_fsm_DW.Delay_DSTATE_g[0] = slave_lsad_fsm_DW.Delay_DSTATE_g[1];

  /* End of Outputs for SubSystem: '<Root>/RAReady2HandDet' */

  /* Outputs for Atomic SubSystem: '<Root>/CruisingReady2HandDet' */
  /* Update for Delay: '<S17>/Delay' */
  slave_lsad_fsm_DW.Delay_DSTATE_j[1] = slave_lsad_fsm_DW.Delay_DSTATE_j[2];

  /* End of Outputs for SubSystem: '<Root>/CruisingReady2HandDet' */

  /* Outputs for Atomic SubSystem: '<Root>/RAReady2HandDet' */
  /* Update for Delay: '<S23>/Delay' */
  slave_lsad_fsm_DW.Delay_DSTATE_g[1] = slave_lsad_fsm_DW.Delay_DSTATE_g[2];

  /* End of Outputs for SubSystem: '<Root>/RAReady2HandDet' */

  /* Outputs for Atomic SubSystem: '<Root>/CruisingReady2HandDet' */
  /* Update for Delay: '<S17>/Delay' */
  slave_lsad_fsm_DW.Delay_DSTATE_j[2] = LocalVar_Equal5_i;

  /* End of Outputs for SubSystem: '<Root>/CruisingReady2HandDet' */

  /* Outputs for Atomic SubSystem: '<Root>/RAReady2HandDet' */
  /* Update for Delay: '<S23>/Delay' */
  slave_lsad_fsm_DW.Delay_DSTATE_g[2] = LocalVar_Equal5;

  /* End of Outputs for SubSystem: '<Root>/RAReady2HandDet' */

  /* Outputs for Atomic SubSystem: '<Root>/Prepare2QuitDet' */
  /* Outputs for Atomic SubSystem: '<Root>/AfterSelect2Standby' */
  /* Logic: '<S21>/AND' incorporates:
   *  Constant: '<S106>/Constant'
   *  Constant: '<S107>/Constant'
   *  Constant: '<S108>/Constant'
   *  Constant: '<S109>/Constant'
   *  Constant: '<S110>/Constant'
   *  Logic: '<S21>/AND1'
   *  Logic: '<S21>/AND2'
   *  RelationalOperator: '<S12>/Equal1'
   *  RelationalOperator: '<S21>/Equal'
   *  RelationalOperator: '<S21>/Equal1'
   *  RelationalOperator: '<S21>/Equal2'
   *  RelationalOperator: '<S21>/Equal3'
   *  RelationalOperator: '<S21>/Equal4'
   */
  slave_lsad_fsm_DW.bitsForTID0.bFuncSelect2Quit = (boolean_T)((int32_T)
    ((((boolean_T)((int32_T)((((boolean_T)((int32_T)
    ((((*rtu_sRaStateCommon_sRAEvnt_eRAQuitEvnt) != RA_QUIT_NONE) ? ((int32_T)1)
      : ((int32_T)0)) | ((rtu_sPaStateAdptr->sPAEvntAdptr.ePAQuitEvnt !=
    QUIT_NONE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
    (((*rtu_sHpaStateCommon_sHPAEvnt_eHPAQuitEvnt) != QUIT_NONE) ? ((int32_T)1) :
     ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
    (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_PREPARE) ? ((int32_T)1)
      : ((int32_T)0)) | ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
    LSAD_STS_PREPARE_SUSPEND) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0))));

  /* End of Outputs for SubSystem: '<Root>/AfterSelect2Standby' */
  /* End of Outputs for SubSystem: '<Root>/Prepare2QuitDet' */

  /* Logic: '<S22>/Logical Operator' incorporates:
   *  Constant: '<S111>/Constant'
   *  Constant: '<S112>/Constant'
   *  Constant: '<S113>/Constant'
   *  Constant: '<S114>/Constant'
   *  RelationalOperator: '<S22>/Equal'
   *  RelationalOperator: '<S22>/Equal1'
   *  RelationalOperator: '<S22>/Equal2'
   *  RelationalOperator: '<S22>/Equal3'
   */
  LocalVar_Equal5_i = ((boolean_T)((int32_T)((((boolean_T)((int32_T)
    ((((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
    ((rtu_sPaStateCommon->sCondiOverFlag.bQuitDurattime ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sPaStateAdptr->sPAEvntAdptr.ePAQuitEvnt ==
    QUIT_MANUAL_DEACTIVATE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
    ((int32_T)0)) | ((rtu_sPaStateAdptr->sPAEvntAdptr.ePAQuitEvnt ==
                      QUIT_RPA_APP_EXIT) ? ((int32_T)1) : ((int32_T)0))))) ?
    ((int32_T)1) : ((int32_T)0)) |
    ((*rtu_sHpaStateCommon_sHPACondiOverFlag_bHpaQuitDurattime) ? ((int32_T)1) :
     ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
     (((*rtu_sHpaStateCommon_sHPAEvnt_eHPAQuitEvnt) == QUIT_MANUAL_DEACTIVATE) ?
      ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
    ((*rtu_sRaStateCommon_sRACondiOverFlag_bRAQuitDurattime) ? ((int32_T)1) :
     ((int32_T)0))))) | ((*rtu_sRaStateCommon_sRAEvnt_eRAQuitEvnt) ==
    RA_QUIT_MANUAL_DEACTIVATE);

  /* Chart: '<Root>/slave_lsad_fsm_stateflow' incorporates:
   *  Constant: '<S100>/Constant'
   *  Constant: '<S102>/Constant'
   *  Constant: '<S103>/Constant'
   *  Constant: '<S105>/Constant'
   *  Constant: '<S120>/Constant'
   *  Constant: '<S121>/Constant'
   *  Constant: '<S28>/Constant8'
   *  Constant: '<S72>/Constant'
   *  Constant: '<S73>/Constant'
   *  Constant: '<S74>/Constant'
   *  Constant: '<S75>/Constant'
   *  Constant: '<S96>/Constant'
   *  Constant: '<S98>/Constant'
   *  Constant: '<S99>/Constant'
   *  Logic: '<S11>/AND'
   *  Logic: '<S11>/AND1'
   *  Logic: '<S15>/NOT'
   *  Logic: '<S16>/Logical Operator'
   *  Logic: '<S16>/OR'
   *  Logic: '<S16>/OR1'
   *  Logic: '<S19>/EMNOT'
   *  Logic: '<S20>/Logical Operator'
   *  Logic: '<S20>/Logical Operator1'
   *  Logic: '<S27>/Logical Operator1'
   *  RelationalOperator: '<S11>/Equal'
   *  RelationalOperator: '<S11>/Equal1'
   *  RelationalOperator: '<S11>/Equal2'
   *  RelationalOperator: '<S11>/Equal3'
   *  RelationalOperator: '<S12>/Equal1'
   *  RelationalOperator: '<S16>/Equal1'
   *  RelationalOperator: '<S16>/Equal3'
   *  RelationalOperator: '<S16>/Equal4'
   *  RelationalOperator: '<S16>/Equal5'
   *  RelationalOperator: '<S20>/Equal1'
   *  RelationalOperator: '<S20>/Equal3'
   *  RelationalOperator: '<S20>/Equal5'
   *  RelationalOperator: '<S27>/Equal'
   *  RelationalOperator: '<S27>/Equal2'
   *  RelationalOperator: '<S27>/Equal5'
   *  RelationalOperator: '<S28>/Relational Operator5'
   *  UnitDelay: '<S125>/Unit Delay1'
   */
  if (((uint32_T)slave_lsad_fsm_DW.bitsForTID0.is_active_c6_slave_lsad_fsm) ==
      0U)
  {
    slave_lsad_fsm_DW.bitsForTID0.is_active_c6_slave_lsad_fsm = 1U;
    slave_lsad_fsm_DW.bitsForTID0.is_c6_slave_lsad_fsm =
      slave_lsad_fsm_IN_FuncStandby;
    slave_lsad_fsm_DW.eLsadFuncType = LSAD_FUNC_TYPE_NONE;
    slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_STANDBY;
    slave_lsad_fsm_DW.bitsForTID0.is_BackgroundRecord =
      slave_lsad_fsm_IN_BackgroundRecordDisable;
    slave_lsad_fsm_DW.eBckgrndRecordSts = BACKGROUND_MODULE_STS_DISABLE;
    slave_lsad_fsm_DW.bitsForTID0.is_BackgroundCruiseReady =
      slave_lsad_fsm_IN_BackgroundCruiseReadyDisable;
    slave_lsad_fsm_DW.eBckgrndCruiseReadySts = BACKGROUND_MODULE_STS_DISABLE;
    slave_lsad_fsm_DW.bitsForTID0.is_BackgroundSearch =
      slave_lsad_fsm_IN_BackgroundSearchDisable;
    slave_lsad_fsm_DW.eBckgrndSearchSts = BACKGROUND_MODULE_STS_DISABLE;
  }
  else
  {
    switch (slave_lsad_fsm_DW.bitsForTID0.is_c6_slave_lsad_fsm)
    {
     case slave_lsad_fsm_IN_Eol:
      if ((boolean_T)((int32_T)((rtu_sPAHmiRx->sAPAHmiRx.bEolReq ? ((int32_T)1) :
             ((int32_T)0)) ^ 1)))
      {
        slave_lsad_fsm_DW.bitsForTID0.is_c6_slave_lsad_fsm =
          slave_lsad_fsm_IN_FuncStandby;
        slave_lsad_fsm_DW.eLsadFuncType = LSAD_FUNC_TYPE_NONE;
        slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_STANDBY;
        slave_lsad_fsm_DW.bitsForTID0.is_BackgroundRecord =
          slave_lsad_fsm_IN_BackgroundRecordDisable;
        slave_lsad_fsm_DW.eBckgrndRecordSts = BACKGROUND_MODULE_STS_DISABLE;
        slave_lsad_fsm_DW.bitsForTID0.is_BackgroundCruiseReady =
          slave_lsad_fsm_IN_BackgroundCruiseReadyDisable;
        slave_lsad_fsm_DW.eBckgrndCruiseReadySts = BACKGROUND_MODULE_STS_DISABLE;
        slave_lsad_fsm_DW.bitsForTID0.is_BackgroundSearch =
          slave_lsad_fsm_IN_BackgroundSearchDisable;
        slave_lsad_fsm_DW.eBckgrndSearchSts = BACKGROUND_MODULE_STS_DISABLE;
      }
      else
      {
        slave_lsad_fsm_DW.eLsadFuncType = LSAD_EOL;
        slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_EOL_ACTIVE;
      }
      break;

     case slave_lsad_fsm_IN_FuncAfterSelect:
      /* Outputs for Atomic SubSystem: '<Root>/AfterSelect2Quit' */
      /* Outputs for Atomic SubSystem: '<Root>/AfterSelect2Standby' */
      if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
                   ((((*rtu_sHpaStateCommon_sHPAEvnt_eHPAQuitEvnt) != QUIT_NONE)
                     ? ((int32_T)1) : ((int32_T)0)) |
                    (((*rtu_sRaStateCommon_sRAEvnt_eRAQuitEvnt) != RA_QUIT_NONE)
                     ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                 ((int32_T)0)) | ((rtu_sPaStateAdptr->sPAEvntAdptr.ePAQuitEvnt
                  != QUIT_NONE) ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
             : ((int32_T)0)) & ((rtu_sLastMasterLsadFsm->eLsadSystemSts ==
              LSAD_STS_HANDSHAKE) ? ((int32_T)1) : ((int32_T)0)))))
      {
        slave_lsad_fsm_DW.bitsForTID0.is_c6_slave_lsad_fsm =
          slave_lsad_fsm_IN_FuncQuit;
        slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_QUIT;
      }
      else if (LocalVar_Equal5_e)
      {
        slave_lsad_fsm_DW.bitsForTID0.is_c6_slave_lsad_fsm =
          slave_lsad_fsm_IN_FuncStandby;
        slave_lsad_fsm_DW.eLsadFuncType = LSAD_FUNC_TYPE_NONE;
        slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_STANDBY;
        slave_lsad_fsm_DW.bitsForTID0.is_BackgroundRecord =
          slave_lsad_fsm_IN_BackgroundRecordDisable;
        slave_lsad_fsm_DW.eBckgrndRecordSts = BACKGROUND_MODULE_STS_DISABLE;
        slave_lsad_fsm_DW.bitsForTID0.is_BackgroundCruiseReady =
          slave_lsad_fsm_IN_BackgroundCruiseReadyDisable;
        slave_lsad_fsm_DW.eBckgrndCruiseReadySts = BACKGROUND_MODULE_STS_DISABLE;
        slave_lsad_fsm_DW.bitsForTID0.is_BackgroundSearch =
          slave_lsad_fsm_IN_BackgroundSearchDisable;
        slave_lsad_fsm_DW.eBckgrndSearchSts = BACKGROUND_MODULE_STS_DISABLE;
      }
      else
      {
        /* Outputs for Atomic SubSystem: '<Root>/Cruising2APAPIConfirmDet' */
        if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
                     ((LocalVar_Equal ? ((int32_T)1) : ((int32_T)0)) &
                      (((boolean_T)((int32_T)
            (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE) ?
              ((int32_T)1) : ((int32_T)0)) |
             ((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_ACTIVE_SUSPEND)
              ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)))))
                   ? ((int32_T)1) : ((int32_T)0)) & (((boolean_T)((int32_T)
                     (((rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkWorkMd == PRK_WORK_START)
                       ? ((int32_T)1) : ((int32_T)0)) |
                      ((rtu_sRelatedModuleInfo->eCtrlSts ==
                        APA_CTRL_COMPLETE_HPP) ? ((int32_T)1) : ((int32_T)0)))))
                   ? ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)
                0)) & (rtu_sVehCommon->sCondiPlatform.bRecomdSlot ? ((int32_T)1)
                       : ((int32_T)0)))))
        {
          slave_lsad_fsm_DW.bitsForTID0.is_c6_slave_lsad_fsm =
            slave_lsad_fsm_IN_FuncSelect;
          slave_lsad_fsm_DW.bitsForTID0.is_FuncSelect =
            slave_lsad_fsm_IN_APAPrkCnfm;
          slave_lsad_fsm_DW.bitsForTID0.is_APAPrkCnfm =
            slave_lsad_fsm_IN_APAPrkIn;
          slave_lsad_fsm_DW.eLsadFuncType = LSAD_PARK_IN;
          slave_lsad_fsm_DW.bitsForTID0.is_APAPrkIn =
            slave_lsad_fsm_IN_APAPrkInConfirm;
          slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_APA_PI_CONFIRM;
        }
        else
        {
          slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_AFTER_SELECT;
        }

        /* End of Outputs for SubSystem: '<Root>/Cruising2APAPIConfirmDet' */
      }

      /* End of Outputs for SubSystem: '<Root>/AfterSelect2Standby' */
      /* End of Outputs for SubSystem: '<Root>/AfterSelect2Quit' */
      break;

     case slave_lsad_fsm_IN_FuncQuit:
      if (LocalVar_Equal5_i)
      {
        slave_lsad_fsm_DW.bitsForTID0.is_c6_slave_lsad_fsm =
          slave_lsad_fsm_IN_FuncStandby;
        slave_lsad_fsm_DW.eLsadFuncType = LSAD_FUNC_TYPE_NONE;
        slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_STANDBY;
        slave_lsad_fsm_DW.bitsForTID0.is_BackgroundRecord =
          slave_lsad_fsm_IN_BackgroundRecordDisable;
        slave_lsad_fsm_DW.eBckgrndRecordSts = BACKGROUND_MODULE_STS_DISABLE;
        slave_lsad_fsm_DW.bitsForTID0.is_BackgroundCruiseReady =
          slave_lsad_fsm_IN_BackgroundCruiseReadyDisable;
        slave_lsad_fsm_DW.eBckgrndCruiseReadySts = BACKGROUND_MODULE_STS_DISABLE;
        slave_lsad_fsm_DW.bitsForTID0.is_BackgroundSearch =
          slave_lsad_fsm_IN_BackgroundSearchDisable;
        slave_lsad_fsm_DW.eBckgrndSearchSts = BACKGROUND_MODULE_STS_DISABLE;
      }
      else
      {
        slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_QUIT;
      }
      break;

     case slave_lsad_fsm_IN_FuncSelect:
      slave_lsad_fsm_FuncSelect(&LocalVar_OR3, &bAPAModeSelect, &LocalVar_Equal7,
        &bAPAPOCnfm2Hand, &bAPAPICnfm, &bAPAPrkIn);
      break;

     default:
      /* case IN_FuncStandby: */
      if (slave_lsad_fsm_DW.UnitDelay1_DSTATE > 0.1F)
      {
        slave_lsad_fsm_DW.bitsForTID0.is_BackgroundSearch =
          slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
        slave_lsad_fsm_DW.bitsForTID0.is_BackgroundCruiseReady =
          slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
        slave_lsad_fsm_DW.bitsForTID0.is_BackgroundRecord =
          slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
        slave_lsad_fsm_DW.bitsForTID0.is_c6_slave_lsad_fsm =
          slave_lsad_fsm_IN_FuncSelect;
        slave_lsad_fsm_DW.bitsForTID0.is_FuncSelect = slave_lsad_fsm_IN_Remote;
        slave_lsad_fsm_DW.eLsadFuncType = LSAD_FUNC_TYPE_NONE;
        slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_RPA_REMOTE_CONNECT;
      }
      else
      {
        /* Outputs for Atomic SubSystem: '<Root>/Idle2APADet' */
        /* Outputs for Atomic SubSystem: '<Root>/AfterSelect2Standby' */
        if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
                     ((((boolean_T)((int32_T)
            (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_STANDBY) ?
              ((int32_T)1) : ((int32_T)0)) &
             ((rtu_sPAHmiRx->sAPAHmiRx.eAPAPrkWakeup == SWT_ON) ? ((int32_T)1) :
              ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
                      ((rtu_sPAHmiRx->sRPAHmiRx.eRPAPrkWakeup != SWT_ON) ?
                       ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) :
                   ((int32_T)0)) & (rtu_sVehCommon->sCondiVeh.bExterActualNorm ?
                   ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0))
              & (((boolean_T)((int32_T)((rtu_sDiagInfo->bPASysFail ? ((int32_T)1)
                   : ((int32_T)0)) ^ 1))) ? ((int32_T)1) : ((int32_T)0)))))
        {
          slave_lsad_fsm_DW.bitsForTID0.is_BackgroundSearch =
            slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
          slave_lsad_fsm_DW.bitsForTID0.is_BackgroundCruiseReady =
            slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
          slave_lsad_fsm_DW.bitsForTID0.is_BackgroundRecord =
            slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
          slave_lsad_fsm_DW.bitsForTID0.is_c6_slave_lsad_fsm =
            slave_lsad_fsm_IN_FuncSelect;
          slave_lsad_fsm_DW.bitsForTID0.is_FuncSelect =
            slave_lsad_fsm_IN_APAModeSelect;
          slave_lsad_fsm_DW.eLsadFuncType = LSAD_FUNC_TYPE_NONE;
          slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_APA_MODE_SELECT;
        }
        else if (rtu_sPAHmiRx->sAPAHmiRx.bEolReq)
        {
          slave_lsad_fsm_DW.bitsForTID0.is_BackgroundSearch =
            slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
          slave_lsad_fsm_DW.bitsForTID0.is_BackgroundCruiseReady =
            slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
          slave_lsad_fsm_DW.bitsForTID0.is_BackgroundRecord =
            slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
          slave_lsad_fsm_DW.bitsForTID0.is_c6_slave_lsad_fsm =
            slave_lsad_fsm_IN_Eol;
          slave_lsad_fsm_DW.eLsadFuncType = LSAD_EOL;
          slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_EOL_ACTIVE;
        }
        else if (bStandby2CruisingReady)
        {
          slave_lsad_fsm_DW.bitsForTID0.is_BackgroundSearch =
            slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
          slave_lsad_fsm_DW.bitsForTID0.is_BackgroundCruiseReady =
            slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
          slave_lsad_fsm_DW.bitsForTID0.is_BackgroundRecord =
            slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
          slave_lsad_fsm_DW.bitsForTID0.is_c6_slave_lsad_fsm =
            slave_lsad_fsm_IN_FuncSelect;
          slave_lsad_fsm_DW.bitsForTID0.is_FuncSelect =
            slave_lsad_fsm_IN_CruisingReady;
          slave_lsad_fsm_DW.eLsadFuncType = LSAD_CRUISE;
          slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_CRUISE_READY;
        }
        else
        {
          /* Outputs for Atomic SubSystem: '<Root>/Standby2RAReadyDet' */
          if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)
                      ((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
              (((rtu_sLastMasterLsadFsm->eLsadSystemSts == LSAD_STS_STANDBY) ?
              ((int32_T)1) : ((int32_T)0)) & (LocalVar_Equal3_b ? ((int32_T)1) :
            ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
              ((rtu_sRAHmiRx->eRAPrkWorkMd == PRK_WORK_START) ? ((int32_T)1) :
               ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) &
                                 (rtu_sVehDataRx->sVehVCUInfo.bBrkPedal ?
                                  ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1)
                     : ((int32_T)0)) & (rtu_sVehCommon->sCondiVeh.bVehStill ?
                     ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)
                  0)) & ((rtu_sRelatedModuleInfo->f32RARecordedDist >= 5.0F) ?
                         ((int32_T)1) : ((int32_T)0)))))
          {
            slave_lsad_fsm_DW.bitsForTID0.is_BackgroundSearch =
              slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
            slave_lsad_fsm_DW.bitsForTID0.is_BackgroundCruiseReady =
              slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
            slave_lsad_fsm_DW.bitsForTID0.is_BackgroundRecord =
              slave_lsad_fsm_IN_NO_ACTIVE_CHILD;
            slave_lsad_fsm_DW.bitsForTID0.is_c6_slave_lsad_fsm =
              slave_lsad_fsm_IN_FuncSelect;
            slave_lsad_fsm_DW.bitsForTID0.is_FuncSelect = slave_lsad_fsm_IN_RA;
            slave_lsad_fsm_DW.eLsadFuncType = LSAD_RA;
            slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_RA_READY;
          }
          else
          {
            slave_lsad_fsm_DW.eLsadFuncType = LSAD_FUNC_TYPE_NONE;
            slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_STANDBY;
            if (((uint32_T)slave_lsad_fsm_DW.bitsForTID0.is_BackgroundRecord) ==
                slave_lsad_fsm_IN_BackgroundRecordDisable)
            {
              if (bBckgrndRecordDisable2Enable)
              {
                slave_lsad_fsm_DW.bitsForTID0.is_BackgroundRecord =
                  slave_lsad_fsm_IN_BackgroundRecordEnable;
                slave_lsad_fsm_DW.eBckgrndRecordSts =
                  BACKGROUND_MODULE_STS_ENABLE;
              }
              else
              {
                slave_lsad_fsm_DW.eBckgrndRecordSts =
                  BACKGROUND_MODULE_STS_DISABLE;
              }
            }
            else
            {
              /* Outputs for Atomic SubSystem: '<Root>/BckgrndRecordDisable2EnableDet' */
              /* case IN_BackgroundRecordEnable: */
              if ((boolean_T)((int32_T)((bBckgrndRecordDisable2Enable ?
                     ((int32_T)1) : ((int32_T)0)) ^ 1)))
              {
                slave_lsad_fsm_DW.bitsForTID0.is_BackgroundRecord =
                  slave_lsad_fsm_IN_BackgroundRecordDisable;
                slave_lsad_fsm_DW.eBckgrndRecordSts =
                  BACKGROUND_MODULE_STS_DISABLE;
              }
              else
              {
                slave_lsad_fsm_DW.eBckgrndRecordSts =
                  BACKGROUND_MODULE_STS_ENABLE;
              }

              /* End of Outputs for SubSystem: '<Root>/BckgrndRecordDisable2EnableDet' */
            }

            if (((uint32_T)
                 slave_lsad_fsm_DW.bitsForTID0.is_BackgroundCruiseReady) ==
                slave_lsad_fsm_IN_BackgroundCruiseReadyDisable)
            {
              if (LocalVar_Equal2_m)
              {
                slave_lsad_fsm_DW.bitsForTID0.is_BackgroundCruiseReady =
                  slave_lsad_fsm_IN_BackgroundCruiseReadyEnable;
                slave_lsad_fsm_DW.eBckgrndCruiseReadySts =
                  BACKGROUND_MODULE_STS_ENABLE;
              }
              else
              {
                slave_lsad_fsm_DW.eBckgrndCruiseReadySts =
                  BACKGROUND_MODULE_STS_DISABLE;
              }

              /* case IN_BackgroundCruiseReadyEnable: */
            }
            else if (bBckgrndCruiseReadyDisable2Enable)
            {
              slave_lsad_fsm_DW.bitsForTID0.is_BackgroundCruiseReady =
                slave_lsad_fsm_IN_BackgroundCruiseReadyDisable;
              slave_lsad_fsm_DW.eBckgrndCruiseReadySts =
                BACKGROUND_MODULE_STS_DISABLE;
            }
            else
            {
              slave_lsad_fsm_DW.eBckgrndCruiseReadySts =
                BACKGROUND_MODULE_STS_ENABLE;
            }

            if (((uint32_T)slave_lsad_fsm_DW.bitsForTID0.is_BackgroundSearch) ==
                slave_lsad_fsm_IN_BackgroundSearchDisable)
            {
              slave_lsad_fsm_DW.eBckgrndSearchSts =
                BACKGROUND_MODULE_STS_DISABLE;
            }
            else
            {
              /* case IN_BackgroundSearchEnable: */
              slave_lsad_fsm_DW.eBckgrndSearchSts = BACKGROUND_MODULE_STS_ENABLE;
            }
          }

          /* End of Outputs for SubSystem: '<Root>/Standby2RAReadyDet' */
        }

        /* End of Outputs for SubSystem: '<Root>/AfterSelect2Standby' */
        /* End of Outputs for SubSystem: '<Root>/Idle2APADet' */
      }
      break;
    }
  }

  /* End of Chart: '<Root>/slave_lsad_fsm_stateflow' */

  /* MATLAB Function: '<Root>/SeatbltDebugHandshakeFcn' incorporates:
   *  Delay: '<Root>/Delay'
   *  Delay: '<Root>/Delay1'
   */
  if (k_EnSeatbltDebugHandshake)
  {
    if (rtu_sVehDataRx->sVehBCMInfo.eDrvSeatbltSts == SEATBLT_ACTIVE)
    {
      switch (slave_lsad_fsm_DW.Delay1_DSTATE[0U])
      {
       case FUNC_STS_STANDBY:
        LocalVar_eLsadFuncType = LSAD_FUNC_TYPE_NONE;
        LocalVar_eLsadFuncSts = FUNC_STS_APA_MODE_SELECT;
        break;

       case FUNC_STS_APA_MODE_SELECT:
        LocalVar_eLsadFuncType = LSAD_PARK_IN;
        LocalVar_eLsadFuncSts = FUNC_STS_APA_PI_SEARCH;
        break;

       case FUNC_STS_APA_PI_SEARCH:
        LocalVar_eLsadFuncType = LSAD_PARK_IN;
        LocalVar_eLsadFuncSts = FUNC_STS_APA_PI_CONFIRM;
        break;

       case FUNC_STS_APA_PI_CONFIRM:
        LocalVar_eLsadFuncType = LSAD_PARK_IN;
        LocalVar_eLsadFuncSts = FUNC_STS_AFTER_SELECT;
        break;

       default:
        LocalVar_eLsadFuncType = slave_lsad_fsm_DW.Delay_DSTATE[0];
        LocalVar_eLsadFuncSts = slave_lsad_fsm_DW.Delay1_DSTATE[0];
        break;
      }
    }
    else if (slave_lsad_fsm_DW.Delay1_DSTATE[0U] == FUNC_STS_AFTER_SELECT)
    {
      LocalVar_eLsadFuncType = LSAD_PARK_IN;
      LocalVar_eLsadFuncSts = FUNC_STS_QUIT;
    }
    else
    {
      LocalVar_eLsadFuncType = LSAD_FUNC_TYPE_NONE;
      LocalVar_eLsadFuncSts = FUNC_STS_STANDBY;
    }
  }
  else
  {
    if (rtu_sPaStateAdptr->sCondiHMI.eAPAMod == APA_MODE_SELF_SELECT)
    {
      LocalVar_eLsadFuncType = LSAD_DRAG_PARK_IN;
    }
    else
    {
      LocalVar_eLsadFuncType = slave_lsad_fsm_DW.eLsadFuncType;
    }

    LocalVar_eLsadFuncSts = slave_lsad_fsm_DW.eLsadFuncSts;
  }

  /* End of MATLAB Function: '<Root>/SeatbltDebugHandshakeFcn' */

  /* MATLAB Function: '<Root>/DriverCtrlCommandFcn' */
  switch (rtu_sPaStateAdptr->sCondiHMI.eAPAMod)
  {
   case APA_MODE_PARK_OUT:
    switch (rtu_sPaStateAdptr->sCondiHMI.ePOSlotType)
    {
     case PO_SLOT_TYPE_PARALLEL:
      switch (rtu_sPaStateAdptr->sCondiHMI.ePODir)
      {
       case PO_HEAD_DIR_LEFT:
        LocalVar_eDriverCtrlCommand = DRIVER_CTRL_PKOUT_SIDE_LEFT;
        break;

       case PO_HEAD_DIR_RIGHT:
        LocalVar_eDriverCtrlCommand = DRIVER_CTRL_PKOUT_SIDE_RIGHT;
        break;

       default:
        LocalVar_eDriverCtrlCommand = DRIVER_CTRL_NONE;
        break;
      }
      break;

     case PO_SLOT_TYPE_PERPENDI:
     case PO_SLOT_TYPE_OBLIQUE:
      switch (rtu_sPaStateAdptr->sCondiHMI.ePODir)
      {
       case PO_HEAD_DIR_LEFT:
        LocalVar_eDriverCtrlCommand = DRIVER_CTRL_PKOUT_FRONT_LEFT;
        break;

       case PO_HEAD_DIR_STRAIGHT:
        LocalVar_eDriverCtrlCommand = DRIVER_CTRL_PKOUT_FRONT_MIDDLE;
        break;

       case PO_HEAD_DIR_RIGHT:
        LocalVar_eDriverCtrlCommand = DRIVER_CTRL_PKOUT_FRONT_RIGHT;
        break;

       case PO_TAIL_DIR_LEFT:
        LocalVar_eDriverCtrlCommand = DRIVER_CTRL_PKOUT_REAR_LEFT;
        break;

       case PO_TAIL_DIR_STRAIGHT:
        LocalVar_eDriverCtrlCommand = DRIVER_CTRL_PKOUT_REAR_MIDDLE;
        break;

       case PO_TAIL_DIR_RIGHT:
        LocalVar_eDriverCtrlCommand = DRIVER_CTRL_PKOUT_REAR_RIGHT;
        break;

       default:
        LocalVar_eDriverCtrlCommand = DRIVER_CTRL_NONE;
        break;
      }
      break;

     default:
      LocalVar_eDriverCtrlCommand = DRIVER_CTRL_NONE;
      break;
    }
    break;

   case APA_MODE_STRAIGHT:
    switch (rtu_sPAHmiRx->sRCAHmiRx.eRCAPrkDircMd)
    {
     case RCA_PRK_AHEAD:
      LocalVar_eDriverCtrlCommand = DRIVER_CTRL_STRAIGHT_FORWARD;
      break;

     case RCA_PRK_BACK:
      LocalVar_eDriverCtrlCommand = DRIVER_CTRL_STRAIGHT_BACKWARD;
      break;

     default:
      LocalVar_eDriverCtrlCommand = DRIVER_CTRL_STRAIGHT_STOP;
      break;
    }
    break;

   default:
    LocalVar_eDriverCtrlCommand = DRIVER_CTRL_NONE;
    break;
  }

  /* End of MATLAB Function: '<Root>/DriverCtrlCommandFcn' */

  /* MATLAB Function: '<S29>/u8LsadStSResetPEBDet' incorporates:
   *  UnitDelay: '<S29>/Unit Delay'
   *  UnitDelay: '<S29>/Unit Delay1'
   *  UnitDelay: '<S29>/Unit Delay2'
   *  UnitDelay: '<S29>/Unit Delay3'
   *  UnitDelay: '<S29>/Unit Delay4'
   */
  LocalVar_OR3 = slave_lsad_fsm_DW.bitsForTID0.UnitDelay2_DSTATE_f;
  if ((boolean_T)((int32_T)((((boolean_T)((int32_T)((((boolean_T)((int32_T)
               (((rtu_sPaStateCommon->sPAEvnt.ePAIntrptEvnt ==
                  INTERRUPT_OBSTACLE) ? ((int32_T)1) : ((int32_T)0)) &
                ((slave_lsad_fsm_DW.UnitDelay_DSTATE != INTERRUPT_OBSTACLE) ?
                 ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)) |
            (((boolean_T)((int32_T)
                          ((((*rtu_sHpaStateCommon_sHPAEvnt_eHPAIntrptEvnt) ==
      INTERRUPT_OBSTACLE) ? ((int32_T)1) : ((int32_T)0)) &
                ((slave_lsad_fsm_DW.UnitDelay3_DSTATE_p != INTERRUPT_OBSTACLE) ?
                 ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)))))
         ? ((int32_T)1) : ((int32_T)0)) | (((boolean_T)((int32_T)
           ((((*rtu_sRaStateCommon_sRAEvnt_eRAIntrptEvnt) ==
              RA_INTERRUPT_OBSTACLE) ? ((int32_T)1) : ((int32_T)0)) &
            ((slave_lsad_fsm_DW.UnitDelay4_DSTATE != RA_INTERRUPT_OBSTACLE) ?
             ((int32_T)1) : ((int32_T)0))))) ? ((int32_T)1) : ((int32_T)0)))))
  {
    LocalVar_u8LsadStSResetPEB = 1U;
    LocalVar_OR3 = true;
    tmp = (int32_T)((uint32_T)(((uint32_T)slave_lsad_fsm_DW.UnitDelay1_DSTATE_g)
      + 1U));
    if ((((uint32_T)slave_lsad_fsm_DW.UnitDelay1_DSTATE_g) + 1U) > 255U)
    {
      tmp = 255;
    }

    slave_lsad_fsm_DW.UnitDelay1_DSTATE_g = (uint8_T)tmp;
  }
  else if (((int32_T)slave_lsad_fsm_DW.UnitDelay1_DSTATE_g) >= 3)
  {
    slave_lsad_fsm_DW.UnitDelay1_DSTATE_g = 0U;
    LocalVar_OR3 = false;
    LocalVar_u8LsadStSResetPEB = 0U;
  }
  else if (slave_lsad_fsm_DW.bitsForTID0.UnitDelay2_DSTATE_f)
  {
    tmp = (int32_T)((uint32_T)(((uint32_T)slave_lsad_fsm_DW.UnitDelay1_DSTATE_g)
      + 1U));
    if ((((uint32_T)slave_lsad_fsm_DW.UnitDelay1_DSTATE_g) + 1U) > 255U)
    {
      tmp = 255;
    }

    slave_lsad_fsm_DW.UnitDelay1_DSTATE_g = (uint8_T)tmp;
    LocalVar_u8LsadStSResetPEB = 1U;
  }
  else
  {
    slave_lsad_fsm_DW.UnitDelay1_DSTATE_g = 0U;
    LocalVar_OR3 = false;
    LocalVar_u8LsadStSResetPEB = 0U;
  }

  /* End of MATLAB Function: '<S29>/u8LsadStSResetPEBDet' */
  (void)memset(rty_sSlaveLsadFsm, 0, sizeof(tSlaveLsadFsm));

  /* BusAssignment: '<Root>/Bus Assignment' */
  rty_sSlaveLsadFsm->eLsadFuncType = LocalVar_eLsadFuncType;
  rty_sSlaveLsadFsm->eLsadFuncSts = LocalVar_eLsadFuncSts;
  rty_sSlaveLsadFsm->eDriverCtrlCommand = LocalVar_eDriverCtrlCommand;
  rty_sSlaveLsadFsm->eBckgrndSearchSts = slave_lsad_fsm_DW.eBckgrndSearchSts;
  rty_sSlaveLsadFsm->eBckgrndRecordSts = slave_lsad_fsm_DW.eBckgrndRecordSts;
  rty_sSlaveLsadFsm->eBckgrndCruiseReadySts =
    slave_lsad_fsm_DW.eBckgrndCruiseReadySts;
  rty_sSlaveLsadFsm->u8LsadStSResetPEB = LocalVar_u8LsadStSResetPEB;

  /* Update for UnitDelay: '<S48>/Unit Delay2' */
  slave_lsad_fsm_DW.bitsForTID0.UnitDelay2_DSTATE_j = LocalVar_OR1;

  /* Update for UnitDelay: '<S8>/Unit Delay1' */
  slave_lsad_fsm_DW.UnitDelay1_DSTATE_e = rtu_sPaStateAdptr->sCondiHMI.eAPAMod;

  /* Update for UnitDelay: '<S8>/Unit Delay2' */
  slave_lsad_fsm_DW.UnitDelay2_DSTATE = rtu_sPaStateAdptr->sCondiHMI.eAPAMod;

  /* Update for UnitDelay: '<S8>/Unit Delay3' */
  slave_lsad_fsm_DW.UnitDelay3_DSTATE = rtu_sPaStateAdptr->sCondiHMI.eAPAMod;

  /* Update for Delay: '<Root>/Delay' */
  slave_lsad_fsm_DW.Delay_DSTATE[0] = slave_lsad_fsm_DW.Delay_DSTATE[1];

  /* Update for Delay: '<Root>/Delay1' */
  slave_lsad_fsm_DW.Delay1_DSTATE[0] = slave_lsad_fsm_DW.Delay1_DSTATE[1];

  /* Update for Delay: '<Root>/Delay' */
  slave_lsad_fsm_DW.Delay_DSTATE[1] = slave_lsad_fsm_DW.Delay_DSTATE[2];

  /* Update for Delay: '<Root>/Delay1' */
  slave_lsad_fsm_DW.Delay1_DSTATE[1] = slave_lsad_fsm_DW.Delay1_DSTATE[2];

  /* Update for Delay: '<Root>/Delay' */
  slave_lsad_fsm_DW.Delay_DSTATE[2] = LocalVar_eLsadFuncType;

  /* Update for Delay: '<Root>/Delay1' */
  slave_lsad_fsm_DW.Delay1_DSTATE[2] = LocalVar_eLsadFuncSts;

  /* Update for UnitDelay: '<S29>/Unit Delay' */
  slave_lsad_fsm_DW.UnitDelay_DSTATE = rtu_sPaStateCommon->sPAEvnt.ePAIntrptEvnt;

  /* Update for UnitDelay: '<S29>/Unit Delay3' */
  slave_lsad_fsm_DW.UnitDelay3_DSTATE_p =
    *rtu_sHpaStateCommon_sHPAEvnt_eHPAIntrptEvnt;

  /* Update for UnitDelay: '<S29>/Unit Delay4' */
  slave_lsad_fsm_DW.UnitDelay4_DSTATE =
    *rtu_sRaStateCommon_sRAEvnt_eRAIntrptEvnt;

  /* Update for UnitDelay: '<S29>/Unit Delay2' */
  slave_lsad_fsm_DW.bitsForTID0.UnitDelay2_DSTATE_f = LocalVar_OR3;
}

/* Model initialize function */
void slave_lsad_fsm_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)&slave_lsad_fsm_DW, 0,
                sizeof(DW_slave_lsad_fsm_f_T));

  {
    slave_lsad_fsm_DW.eLsadFuncType = LSAD_FUNC_TYPE_NONE;
    slave_lsad_fsm_DW.eLsadFuncSts = FUNC_STS_STANDBY;
    slave_lsad_fsm_DW.eBckgrndRecordSts = BACKGROUND_MODULE_STS_DISABLE;
    slave_lsad_fsm_DW.eBckgrndCruiseReadySts = BACKGROUND_MODULE_STS_DISABLE;
    slave_lsad_fsm_DW.eBckgrndSearchSts = BACKGROUND_MODULE_STS_DISABLE;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
