#ifndef CDD_FLASHCP_H
#define CDD_FLASHCP_H
#include "Fls_17_Dmu.h"
#include "SchM_Fls_17_Dmu.h"
Std_ReturnType Cdd_FlashErase(uint32 addr, uint32 length);
Std_ReturnType Cdd_FlashRead(uint32 addr, uint8 *pBuf, uint32 bytes);
Std_ReturnType Cdd_FlashWrite(uint32 addr, uint8 *pBuf, uint32 bytes);
Std_ReturnType Cdd_FlashBlabkCheck(uint32 addr, uint32 length);




#endif