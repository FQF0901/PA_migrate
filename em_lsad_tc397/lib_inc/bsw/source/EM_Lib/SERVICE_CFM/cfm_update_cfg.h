#ifndef __CFM_UPDATE_CFG_H__
#define __CFM_UPDATE_CFG_H__

#include "cfm_common.h"
#include "cfm_flash.h"

#define ONE_PACKAGE_DATA_SIZE 1024
#define CFM_PERIOD 20
#define SOC_READY 1
#define SOC_NOT_READY 0
#define SOC_RES_SUCCESS 1
#define SOC_RES_FAILED 2


enum enCFMMessageType_SOCMCU_CmdType{
    SOC_MCU_SEND_FRAME = 1,
    SOC_MCU_GET_BIN,
    SOC_MCU_FRAME_RES,
    MCU_SOC_SEND_FRAME,
    MCU_SOC_FRAME_RES,
};

enum enCFMMessageType_SOCMCU_ResType{
    MCU_RECV_PACKAGE_SUCCESS = 1,
    MCU_RECV_PACKAGE_FAILED,
    SOC_RECV_PACKAGE_SUCCESS,
    SOC_RECV_PACKAGE_FAILED,
};

int cfm_update_bin(void);

#endif
