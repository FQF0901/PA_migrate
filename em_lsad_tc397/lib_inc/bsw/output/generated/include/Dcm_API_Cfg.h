/**
 * \file
 *
 * \brief AUTOSAR Dcm
 *
 * This file contains the implementation of the AUTOSAR
 * module Dcm.
 *
 * \version 5.0.11
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef DCM_API_CFG_H
#define DCM_API_CFG_H

/*==================[includes]===================================================================*/

#include <Dcm_Types.h>

/*==================[macros]=====================================================================*/



/*==================[type definitions]===========================================================*/

/*==================[external function declarations]=============================================*/

#define DCM_START_SEC_CALLOUT_CODE
#include <Dcm_MemMap.h>

extern FUNC(Std_ReturnType, DCM_APPL_CODE) SecurityGetSeedADR0(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) SecurityAccessDataRecord,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Seed,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);

/* !LINKSTO Dcm.EB.ServiceAPI.SecurityAccess,1 */

extern FUNC(Std_ReturnType, DCM_APPL_CODE) SecurityCompareKey0(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) Key, Dcm_OpStatusType OpStatus);

/* !LINKSTO Dcm.EB.ServiceAPI.SecurityAccess,1 */

/* !LINKSTO Dcm.ReadDataById.ConditionCheckRead.AsyncAPI,1 */
extern FUNC(Std_ReturnType, DCM_APPL_CODE) ReadDIDDataCondition0(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);

extern FUNC(Std_ReturnType, DCM_APPL_CODE) ReadDIDDataLength0(
    P2VAR(uint16, AUTOMATIC, DCM_VAR) DataLength);

/* !LINKSTO Dcm.ReadDataById.ReadData.AsyncAPI,1 */
extern FUNC(Std_ReturnType, DCM_APPL_CODE) ReadDIDData0(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data);

/* !LINKSTO Dcm.WriteDataById.WriteData.FixLength.AsyncAPI,1 */
extern FUNC(Std_ReturnType, DCM_APPL_CODE) WriteDIDData0(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) Data,
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);

/* !LINKSTO Dcm.ReadDataById.ReadData.SyncAPI,1 */
extern FUNC(Std_ReturnType, DCM_APPL_CODE) Dcm_Internalf186Readout(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data);


extern Std_ReturnType Routine0_Start(
    sint8 inParam0,
    uint8 inParam1,
    Dcm_OpStatusType OpStatus,
    P2VAR(sint16, AUTOMATIC, DCM_VAR) outParam0,
    P2VAR(sint32, AUTOMATIC, DCM_VAR) outParam1,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
extern Std_ReturnType Routine0_Stop(
    uint16 inParam0,
    uint8 inParam1,
    Dcm_OpStatusType OpStatus,
    P2VAR(boolean, AUTOMATIC, DCM_VAR) outParam0,
    P2VAR(uint32, AUTOMATIC, DCM_VAR) outParam1,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
extern Std_ReturnType Routine0_RequestResult(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) outParam0,
    P2VAR(boolean, AUTOMATIC, DCM_VAR) outParam1,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* !LINKSTO Dcm.ReadData.DcmDspPid.SyncFnc,1 */
#define DCM_STOP_SEC_CALLOUT_CODE
#include <Dcm_MemMap.h>
/*==================[internal function declarations]=============================================*/

/*==================[external constants]=========================================================*/

/*==================[internal data]==============================================================*/

/*==================[external function definitions]==============================================*/

/*==================[internal function definitions]==============================================*/

#endif /* ifndef DCM_API_CFG_H */
/*==================[end of file]================================================================*/
