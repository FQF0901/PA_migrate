/**
 * @file    rte.h
 * @brief   This is a brief description of file rte.h.
 * @details This is the detail description.
 * 
 * @date    2021年8月5日 (created)
 * @version 0.0.1
 * @par Copyright (C):
 *      
 * @par Encoding:
 *            UTF-8
 * @par Description:
 *    1. Hardware Descriptions:
 *        None.
 *    2. Program Architecture:
 *        None.
 *    3. File Usage:
 *        None.
 *    4. Limitations:
 *        None.
 *    5. Else:
 *        None.
 * @par Modification:
 *    -# Date     : 2020.--.--;
 *       Revision : 0.0.1;
 *       
 *       Contents : Co.
 */

#ifndef EM_RTE_RTE_H_
#define EM_RTE_RTE_H_

/*    ===========================================================================
 *                                header files
 *    =========================================================================*/
#include "Std_Types.h"
#include "emos_rte.h"
#include "apa_shell.h"
#include "rte_ultrasonic_types.h"
#include "adas_struct.h"
 #include "vehicle_service_type.h"

#ifndef _GPIO_DATA_STRUCT_H_
#define _GPIO_DATA_STRUCT_H_

typedef struct tGPIO_Info_T
{
    /* data */
    uint8 u8apa_en;
    uint8 u8emergency_info;
    uint8 u8park_uss_info;
    uint8 u8hud_info;
    uint8 u8key_continue_info;
    uint8 reserve[3];       //4 byte alignment
}
tGPIO_Info;
#endif
/*    ===========================================================================
 *                            macros & constants
 *    =========================================================================*/

/*    ===========================================================================
 *                        data structure declarations
 *    =========================================================================*/
typedef uint8 u8RTE_COM_0x529_Data_T [8];
/*    ===========================================================================
 *                        global variable declarations
 *    =========================================================================*/

/*    ===========================================================================
 *                        global function declarations
 *    =========================================================================*/
extern Std_ReturnType Rte_Read_CTRL2CHASSIS                             (tVehi_VehicleDataTx            *msgMnger_ctrl_data);
extern Std_ReturnType Rte_Write_CTRL2CHASSIS                            (const tVehi_VehicleDataTx      *msgMnger_ctrl_data);
extern Std_ReturnType Rte_Read_CTRL2SM                                  (tAPA_CtrlSts                   *msgMnger_ctrl_sm);
extern Std_ReturnType Rte_Write_CTRL2SM                                 (const tAPA_CtrlSts             *msgMnger_ctrl_sm);
extern Std_ReturnType Rte_Read_GPIO_INFO                                (tGPIO_Info                     *msgMnger_GPIO_INFO   );
extern Std_ReturnType Rte_Write_GPIO_INFO                               (const tGPIO_Info               *msgMnger_GPIO_INFO   );
extern Std_ReturnType Rte_Read_COM_0x529_DATA                           (u8RTE_COM_0x529_Data_T         *msgMnger_COM_DATA);
extern Std_ReturnType Rte_Write_COM_0x529_DATA                          (const u8RTE_COM_0x529_Data_T   *msgMnger_COM_DATA);
extern Std_ReturnType Rte_Read_AllTime_DR_Data                          (tObjProperty3D                 *msgMnger_DR_DATA);
extern Std_ReturnType Rte_Write_AllTime_DR_Data                         (const tObjProperty3D           *msgMnger_DR_DATA); // no used
extern Std_ReturnType Rte_Read_HanshakeStatus                           (uint8                          *msgMnger_HandShakeSts);
extern Std_ReturnType Rte_Write_HanshakeStatus                          (const uint8                    *msgMnger_HandShakeSts);
extern Std_ReturnType Rte_Read_SelectedBerthId                          (uint8                          *msgMnger_SelectedBerthID);
extern Std_ReturnType Rte_Write_SelectedBerthId                         (const uint8                    *msgMnger_SelectedBerthID);
extern Std_ReturnType Rte_Read_USH_UltrasonicSysSwt                     (tAPA_UltrasonicSwtCtrl         *msgMnger_UssSysSwt);
extern Std_ReturnType Rte_Write_USH_UltrasonicSysSwt                    (const tAPA_UltrasonicSwtCtrl   *msgMnger_UssSysSwt);
extern Std_ReturnType Rte_Read_USH_PdcAssociatedSysAbnormal             (tNormalSts                     *msgMnger_UssAlgoAbnor);
extern Std_ReturnType Rte_Write_USH_PdcAssociatedSysAbnormal            (const tNormalSts               *msgMnger_UssAlgoAbnor);
extern Std_ReturnType Rte_Read_USH_UltrasonicSysDtc                     (tUSH_UsSysDtcSts               *msgMnger_UssSysDtc); // no used
extern Std_ReturnType Rte_Write_USH_UltrasonicSysDtc                    (const tUSH_UsSysDtcSts         *msgMnger_UssSysDtc);
extern Std_ReturnType Rte_Read_USH_DtcSnapshot                          (tUSH_UsSysDtcSnapshot          *msgMnger_UsSysDtcSnap); // no used
extern Std_ReturnType Rte_Write_USH_DtcSnapshot                         (const tUSH_UsSysDtcSnapshot    *msgMnger_UsSysDtcSnap);
extern Std_ReturnType Rte_Read_USH_UsPwrFaultSts                        (tFaultSts                      *msgMnger_UsPwrFaultSts);
extern Std_ReturnType Rte_Write_USH_UsPwrFaultSts                       (const tFaultSts                *msgMnger_UsPwrFaultSts);
extern Std_ReturnType Rte_Read_USH_UsPwrSwtSts                          (tSwitchSts                     *msgMnger_UsPwrSwtSts);  // no used
extern Std_ReturnType Rte_Write_USH_UsPwrSwtSts                         (const tSwitchSts               *msgMnger_UsPwrSwtSts);  // no used
extern Std_ReturnType Rte_Read_USH_UsSysInfo                            (tUSH_UsSysInfo                 *msgMnger_UsSysInfo);
extern Std_ReturnType Rte_Write_USH_UsSysInfo                           (const tUSH_UsSysInfo           *msgMnger_UsSysInfo);
extern Std_ReturnType Rte_Read_USH_UsSysVersion                         (tUSH_UsSysVersion              *msgMnger_UsSysVersion);
extern Std_ReturnType Rte_Write_USH_UsSysVersion                        (const tUSH_UsSysVersion        *msgMnger_UsSysVersion);
extern Std_ReturnType Rte_Read_CTRL2SM_ReqStatus                        (tAPA_CtrlReqStatus             *msgMnger_ctrlrequest);
extern Std_ReturnType Rte_Write_CTRL2SM_ReqStatus                       (const tAPA_CtrlReqStatus       *msgMnger_ctrlrequest);
extern Std_ReturnType Rte_Read_VEHSRV2CHASSIS                           (tVehi_VehicleDataTx            *msgMnger_ctrl_data); // no used
extern Std_ReturnType Rte_Write_VEHSRV2CHASSIS                          (const tVehi_VehicleDataTx      *msgMnger_ctrl_data);
#if(EM_VEHI_TYPE == VEHI_TYPE_HAN)
extern Std_ReturnType Rte_Read_XAVIER_HandShakeResp                     (tMsgMnger_HPPShakeHands        *msgMnger_XAVIER_HandShakeResp); // no used
extern Std_ReturnType Rte_Write_XAVIER_HandShakeResp                    (const tMsgMnger_HPPShakeHands  *msgMnger_XAVIER_HandShakeResp);
#endif
extern Std_ReturnType Rte_Read_MsgManager_HandShakeState(tMsgMnger_ApaState *msgMnger_ApaState);
extern Std_ReturnType Rte_Write_MsgManager_HandShakeState(const tMsgMnger_ApaState *msgMnger_ApaState);

extern Std_ReturnType Rte_Read_MsgManager_APPVehData(tVehDataRx *msgMnger_AppVehData);
extern Std_ReturnType Rte_Write_MsgManager_APPVehData(const tVehDataRx *msgMnger_AppVehData);

// extern Std_ReturnType Rte_Read_CTRL2VEHSRV       (        tCtrl2Vehsrv            *msgMnger_ctrl2vehsrv_data   );
// extern Std_ReturnType Rte_Write_CTRL2VEHSRV      (  const tCtrl2Vehsrv            *msgMnger_ctrl2vehsrv_data   );
extern Std_ReturnType Rte_Read_VEHSRV2CTRL      (        tVehsrv2Ctrl            *msgMnger_vehsrv2ctrl_data   );
extern Std_ReturnType Rte_Write_VEHSRV2CTRL      (  const tVehsrv2Ctrl            *msgMnger_vehsrv2ctrl_data   );

extern Std_ReturnType Rte_Read_USH_UsBlindZoneUnlockTrigger         (        uint16                  *blindZoneUnlockTriggerBitMask);
extern Std_ReturnType Rte_Write_USH_UsBlindZoneUnlockTrigger         ( const uint16                  *blindZoneUnlockTriggerBitMask);

extern Std_ReturnType Rte_Read_HandShakeDiagErr(uint32 *msgMnger_HandShakeDiagErr);
extern Std_ReturnType Rte_Write_HandShakeDiagErr(const uint32 *msgMnger_HandShakeDiagErr);

extern Std_ReturnType Rte_Read_HandShakeInfo(ST_VEHICLE_HANDSHAKE_INFO *msgMnger_HandShakeInfo);
extern Std_ReturnType Rte_Write_HandShakeInfo(const ST_VEHICLE_HANDSHAKE_INFO *msgMnger_HandShakeInfo);

extern Std_ReturnType Rte_Read_ActuaSrvTx(tActuaSrvTx *msgMnger_ActuaSrvTx);
extern Std_ReturnType Rte_Write_ActuaSrvTx(const tActuaSrvTx *msgMnger_ActuaSrvTx);
/*    ===========================================================================
 *                                submodule
 *    =========================================================================*/

/* vehicle gear */
extern tVehiGear Rte_Read_CanSig_eVehiGear(void);
extern tValidity Rte_Read_CanSig_eVehiGearValidity(void);
/* vehicle speed kph */
extern float32 Rte_Read_CanSig_fVehiSpeed_kph(void);
extern tValidity Rte_Read_CanSig_fVehiSpeedValidity(void);
/* brake active status */
extern tActiveSts Rte_Read_CanSig_eBrakeActiveSts(void);
extern tValidity Rte_Read_CanSig_eBrakeActiveStsValidity(void);
/* outside air temperature */
extern float32 Rte_Read_CanSig_fOutsdAirTemp_degC(void);
extern tValidity Rte_Read_CanSig_fOutsdAirTempValidity(void);
extern void Rte_Init(void);
#endif /* EM_RTE_RTE_H_ */
/******************************************************************************
 *                                    EOF
 *****************************************************************************/
