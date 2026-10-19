#ifndef EMDC_TYPES_H
#define EMDC_TYPES_H

/*
 * emdc_types.h
 *
 *  Created on: 2022/11/2
 *      
 */
#include <stddef.h>
#include <string.h>

#define EMDC_VERSION    "EMDC_V_2_2_0"



typedef unsigned int EM_U32;
typedef int EM_S32;
typedef unsigned short EM_U16;
typedef short EM_S16;
typedef unsigned char EM_U8;
typedef char EM_S8;
typedef char EM_BOOL;
//typedef uintptr_t EMDC_THREAD;

typedef EM_U8  EM_idType;
typedef EM_U16 EM_DataLenType;
typedef EM_U16 EM_IdNumType;
typedef EM_U16 EM_SequenceType;
typedef EM_U8  EM_SliceType;

#define ETHMTU          1500U
#define PAYLOADMTU      1408U
#define HEADER_LEN      8U
#define MAC_LEN         6U
#define ETH_HEADER      14U

#define EMDC_TYPE  0x33ff


typedef void (*RECV_CB)(EM_idType RxPort, void* data, EM_U16 len, void *pUserData);


enum EMDC_status
{
    EMDC_SUCCESS = 0,
	EMDC_FAILED = -1,
	EMDC_INVALID_PARAM = -2, 
	EMDC_NO_MEMORY = -3,
	EMDC_NOT_INITED = -4,
	EMDC_TIMEOUT = -5,
	EMDC_INVALID_HANDLE = -6,
	EMDC_BUF_OVERFLOW = -7,
	EMDC_INVALID_DATA = -8,
    EMDC_SYS = -9,
	EMDC_PACKET_LOST = -10,
    EMDC_CREATEPORT_FAILED = -11,
    EMDC_CREATE_SENDFD_FAILED = -12,
    EMDC_CREATE_RECVFD_FAILED = -13,
    EMDC_CREATE_PRIORITY_FAILED = -14,
    EMDC_INVALID_PORT = -15,
    EMDC_INVALID_PRIORITY = -16,
    ENDC_REPEAT_INIT = -17
};

typedef struct
{
    EM_DataLenType      length;
    EM_SequenceType     sequence;
}EMDC_sendMsgInfo;

typedef struct
{
    EM_U8*              recvPtr;
    EM_DataLenType      length;
    RECV_CB             recvCallBack;
    void*               pUserData;
    EM_SequenceType     sequence;
    EM_SliceType        sliceindex;
    EM_U32              recv_lost;

}EMDC_recvMsgInfo;




#endif /*EMDC_TYPES_H*/
