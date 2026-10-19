/*
 * emdc_transIf.h
 *
 *  Created on: 2022/11/9
 *      
 */

#ifndef EMDC_MAIN_H
#define EMDC_MAIN_H

#include "emdc_types.h"
// #include "Eth_GeneralTypes.h"
extern int emdc_GetVersion(void);

extern int emdc_Init(const char * ifname, EM_U8* dstAddr, int priority, void*pMemPtr, EM_U32 length);


extern int emdc_CreateSendPort(EM_U8 portID, EM_U32 bufLen);

extern int emdc_CreateRecvPort(EM_U8 portID, EM_U32 bufLen, RECV_CB recv_cbk , void *pUserData);

extern int emdc_Sendto(EM_U8 portID, EM_U8 *pData, EM_U32 bufLen);

extern int emdc_RecvStart(void);

extern int emdc_RecvStop(void);

extern int emdc_SetOpt(EM_U8 recvPortID, EM_U8 opt, void *pData);


extern int emdc_GetOpt(EM_U8 recvPortID, EM_U8 opt, void *pData);

// extern void EthIf_Emdc_RxIndication(uint8 CtrlIdx,
//         Eth_FrameType FrameType,
//         boolean IsBroadcast,
//         P2VAR(uint8, AUTOMATIC, ETHIF_APPL_DATA) PhysAddrPtr,
//         P2VAR(uint8, AUTOMATIC, ETHIF_APPL_DATA) DataPtr,
//         uint16 LenByte);


#endif /*EMDC_MAIN_H*/
