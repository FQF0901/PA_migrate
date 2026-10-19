#ifndef __CFM_FALSH_H__
#define __CFM_FALSH_H__
#include<stdint.h>
#include "cfm_common.h"

uint32_t GetCRC32(uint32_t addr, uint32_t len, uint32_t *CRC32_data);
uint32_t GetSeq(e_BlockID block);
int32_t GetValueFromFlash(char *key, void *value, int32_t type);

#endif //__CFM_FALSH_H__
