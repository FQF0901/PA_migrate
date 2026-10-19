#ifndef EM_DIAG_CONFIG_H__
#define EM_DIAG_CONFIG_H__
#include <stdint.h>
#include "proj_global.h"

#define EM_DIAG_SIZE        226U
#define ENABLE_CP_DM        0U
#define EM_UNKNOW_EVENT     0U
#define EM_SOC_EVENT        1U
#define EM_MCU_EVENT        2U
#define DIAG_RETURN_OK      2U
#define DIAG_RETUREN_N_OK   3U

typedef uint16_t EM_EventIdType;
typedef uint8_t EM_EventStatusType;
typedef uint8_t EM_EventSourceType;
typedef struct
{
    EM_EventIdType      id;
    EM_EventStatusType  status;
    EM_EventSourceType  chip;
}EM_DiagEventListType;

EM_DiagEventListType* GetEventList(void);
uint16_t GetNumberOfEvent(void);
uint16_t GetNumberOfMcuEvent(void);
uint16_t GetNumberOfSocEvent(void);

#endif