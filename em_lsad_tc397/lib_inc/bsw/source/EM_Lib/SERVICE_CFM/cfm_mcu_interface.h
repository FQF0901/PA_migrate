#ifndef __CFM_MCU_INTERFACE_H__
#define __CFM_MCU_INTERFACE_H__

#include<stdint.h>
void InitConfig();
int32_t cfm_get_int(char *key, int *value);
int32_t cfm_get_float(char *key, float *value);

#endif //__CFM_MCU_INTERFACE_H__