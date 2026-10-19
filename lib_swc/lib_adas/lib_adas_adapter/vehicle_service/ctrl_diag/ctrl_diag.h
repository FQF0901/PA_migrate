/*
 * ctrl_diag.h
 *
 *  Created on: Jul 13, 2021
 *      
 */

#ifndef SRC_APL_APP_CTRL_ALGO_INCLUDE_CTRL_DIAG_H_
#define SRC_APL_APP_CTRL_ALGO_INCLUDE_CTRL_DIAG_H_

#include "ctrl_struct.h"
#include "adas_project_input.h"
#include "rtwtypes.h"
#include "lsad_fsm_api.h"

void Ctrl_VehDiagReset_20ms(void);
uint8_t Ctrl_VehDiag_20ms(void);
void Ctrl_VehDiagPrint_20ms(void);


uint16_t Ctrl_DiagHandShake(void);
uint16_t Ctrl_DiagInputChassis(tMsgMnger_VehicleInfo   *pstVehicleInfo);
uint16_t Ctrl_DiagInputUss(tMsgMnger_PDC *pstPdcData);
// uint16_t Ctrl_DiagAPAShell(ExtY_apa_shell_ctrl_T *pstApaState);
uint16_t Ctrl_DiagInputPpInfo(tMsgMnger_PathPlanner  *pstPpInfo);
uint16_t Ctrl_DiagOutputChassis(tVehi_VehicleDataTx  *pstVehicleData);

void Ctrl_DiagSetPebErrCode(uint16_t errCode);
void Ctrl_DiagSetDrErrCode(uint16_t errCode);
void Ctrl_DiagSetParkErrCode(uint16_t errCode);
void Ctrl_DiagSetParkoutErrCode(uint16_t errCode);
void Ctrl_DiagSetCruiseErrCode(uint16_t errCode);


#endif /* SRC_APL_APP_CTRL_ALGO_INCLUDE_CTRL_DIAG_H_ */
