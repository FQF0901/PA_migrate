#ifndef _H_S2SCOM_H
#define _H_S2SCOM_H

#include "emdc_transIf.h"
#include "Std_Types.h"

#define EMDC_RECV_BUFFER_LEN    25000

#define EMOS_MCU2SOC_MCUFREESPACE_START_INTERVAL  (-6)
#define EMOS_MCU2SOC_USOBSTACLE_START_INTERVAL  (-8)
#define EMOS_MCU2SOC_OBJDETECTION_START_INTERVAL  (-6)
#define EMOS_MCU2SOC_LOCALISITION_START_INTERVAL  (-6)
#define EMOS_MCU2SOC_PF_START_INTERVAL  (-2)
#define EMOS_MCU2SOC_PDC_START_INTERVAL  (-6)
#define EMOS_MCU2SOC_CTRLERRCODE_START_INTERVAL  2
#define EMOS_MCU2SOC_APASTATE_START_INTERVAL  1


#define RETURN_ERROR(x)         return (-x);
#define RETURN_IF_POINTER_NULL(p)  {if(p == NULL) return -1;}
#define RETURN_NOERROR          {return ERR_NOERROR;}
#define IS_OK(s)                       ( ( s ) == 0L )
#define IS_FAILED(s)                   ( ( s ) != 0L )
#define RETURN_IF_FAILED(s)            { int32_t __result = (s); if (IS_FAILED(__result)) { return (__result); } }
#define EMOS_TASK_STACK_SIZE           1024
#define EMOS_MAX_TASK_NAME_LEN         32
#define EMOS_MAX_SIGNAL_NUM            256

#define LOGE(...)
#define LOGW(...)
#define LOGI(...)                 
#define s2s_align    __align(4)

enum
{
    ERR_NOERROR                    = 0,
    ERR_UNKNOWN                    = 2, 
    ERR_UNEXPECTED                 = 3, 
    ERR_POINTER                    = 4, 
    ERR_INVALID_ARG                = 5, 
    ERR_INVALID_FUNCTION           = 6, 
    ERR_INVALID_ADDRESS            = 7, 
    ERR_INVALID_HANDLE             = 8, 
    ERR_INVALID_FLAGS              = 9, 
    ERR_INVALID_INDEX              = 10,
    ERR_INVALID_FILE               = 11,
    ERR_MEMORY                     = 12,
    ERR_TIMEOUTED                  = 13,
    ERR_OUT_OF_SYNC                = 14,
    ERR_RESOURCE_IN_USE            = 15,
    ERR_NOT_IMPL                   = 16,
    ERR_NO_INTERFACE               = 17,
    ERR_NO_CLASS                   = 18,
    ERR_NOT_SUPPORTED              = 19,
    ERR_NOT_FOUND                  = 20,
    ERR_CANCELLED                  = 21,
    ERR_RETRY                      = 22,
    ERR_FILE_NOT_FOUND             = 23,
    ERR_PATH_NOT_FOUND             = 24,
    ERR_ACCESS_DENIED              = 25,
    ERR_NOT_READY                  = 26,
    ERR_OPEN_FAILED                = 27,
    ERR_IO_INCOMPLETE              = 28,
    ERR_IO_PENDING                 = 29,
    ERR_NOACCESS                   = 30,
    ERR_BAD_DEVICE                 = 31,
    ERR_DEVICE_IO                  = 32,
    ERR_DEVICE_NOT_READY           = 33,
    ERR_DEVICE_IN_USE              = 34,
    ERR_NOT_CONNECTED              = 35,
    ERR_UNKNOWN_FORMAT             = 36,
    ERR_NOT_INITIALISED            = 37,
    ERR_FAILED                     = 38,
    ERR_END_OF_FILE                = 39,
    ERR_INVALID_STATE              = 40,
    ERR_EXCEPTION_RAISED           = 41,
    ERR_INVALID_TYPE               = 42,
    ERR_EMPTY                      = 43,
    ERR_INVALID_VERSION            = 44,
    ERR_INVALID_LICENSE            = 45,
    ERR_SERVICE_NOT_FOUND          = 46,
    ERR_DAU                        = 47,
    ERR_IDLE_NOWAIT                = 48,
    ERR_OUT_OF_RANGE               = 49,
    ERR_KNOWN_PROBLEM              = 50,
	ERR_CONTAINNER_FULL            = 51
};

typedef unsigned char tResult;
typedef unsigned long long tUInt64;
typedef long long tInt64;
typedef unsigned int tUInt32;
typedef int tInt32;
typedef unsigned short tUInt16;
typedef short tInt16;
typedef unsigned char tUInt8;
typedef char tInt8;
typedef char tChar;
typedef void tVoid;

typedef int (*emos_task_init)(void);
typedef void (*emos_task_routine)(void *pData);

typedef struct _emosTaskStruct
{
	emos_task_init pInit;
    emos_task_routine pCb;
	void *pData;
	unsigned int period;
	unsigned int delay;
	char name[EMOS_MAX_TASK_NAME_LEN];
}tEmosTaskStruct;

typedef struct _stMcuSpinLock
{
    unsigned int m_lock;//should use lock interface from AutoSar CP
}stMcuSpinLock;

tResult EMC_EmdcCom_Init(tVoid *pBuf);
tVoid   EMC_EmdcCom_Exit();
tResult EMC_EmdcCom_SendNodeCreate(tUInt8 portID, tUInt16 bufLen);
tResult EMC_EmdcCom_RecvNodeCreate(tUInt8 portID, tUInt16 bufLen);
tResult EMC_EmdcCom_TaskStart(tChar *ifname, tChar *pDstMac, RECV_CB pCb);
tResult EMC_EmdcCom_SendTo(tUInt8 portID, tChar *pData, tUInt16 len);
extern Std_ReturnType MCU_SpinLock(stMcuSpinLock *pLock);
extern Std_ReturnType MCU_SpinUnLock(stMcuSpinLock *pLock);
extern Std_ReturnType MCU_SpinLock_C(stMcuSpinLock *pLock);

#endif // _H_S2SCOM_H
