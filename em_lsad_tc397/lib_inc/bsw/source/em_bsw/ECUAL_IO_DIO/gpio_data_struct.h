#ifndef _GPIO_DATA_STRUCT_H_
#define _GPIO_DATA_STRUCT_H_

#include "Platform_Types.h"

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
