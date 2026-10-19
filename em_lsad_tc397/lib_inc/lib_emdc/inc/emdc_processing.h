/*
 * emdc_processing.h
 *
 *  Created on: 2022/11/9
 *      
 */

#ifndef EMDC_PROCESSING_H
#define EMDC_PROCESSING_H

#include "emdc_innerIf.h"

extern int emdc_InitCheck(void);

extern int emdc_SetLocalAddr(const char* ifname);

extern int emdc_SetDstAddr(EM_U8* dstAddr);

extern int emdc_Deinit(void);

extern int emdc_CreateSocketFD(const char* ifname, EM_U8 priority);

extern int emdc_SetMemPool(void* pMemPtr, EM_U32 length);

extern int emdc_AddNewSendPort(EM_U8 portID, EM_U16 bufLen);

extern int emdc_AddNewRecvPort(EM_U8 portID, EM_U16 bufLen, RECV_CB recv_cbk, void* pUserData);

extern int emdc_RecvStop_Processing(void);

extern int emdc_Sendto_Processing(EM_U8 portID, EM_U8* pData, EM_U16 len);

extern int emdc_RecvLoop(void);

extern int emdc_GetPacketLostCount(EM_U8 portID);

#endif /*EMDC_PROCESSING_H*/
