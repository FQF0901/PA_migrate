/*
 * Diag_ErrManager.h
 *
 *  Created on: 2022年2月18日
 *      
 */

#ifndef EM_SERVICESLAYER_SERVICE_DIAG_MANAGER_DIAG_ERRMANAGER_H_
#define EM_SERVICESLAYER_SERVICE_DIAG_MANAGER_DIAG_ERRMANAGER_H_
#include "Diag_ErrType_Enum.h"
#include "Platform_Types.h"
#define DIAG_ERRORLIST_MAX          20

typedef struct
{
    Diag_Errortype ErrorHistoryList[DIAG_ERRORLIST_MAX + 5u];
    Diag_Errortype ErrorList_Current[DIAG_ERRORLIST_MAX + 5U];
    uint8 IsErrorOccur_Flag;
    uint8 ErrorHistoryClear_Ena;
    uint8 ErrorRTlistClear_Ena;
}DiagInfo_Type;

extern void Diag_ErrInfoManagement_MainFunction(void);
extern void Diag_MainFunc_Test(void);
extern void Diag_CmdRead_Test(uint32 cmd, uint32 errid);
extern void Task_DiagErrManager_50ms(void);
extern void TaskStart_DiagErrManager(void);

#define COMMAND_DIAG                "diag"
#define COMMAND_DIAG_HELP_TEXT      ": Diag test"

// extern boolean DiagManagerTest(pchar args, void *data, IfxStdIf_DPipe *io);
#endif /* EM_SERVICESLAYER_SERVICE_DIAG_MANAGER_DIAG_ERRMANAGER_H_ */
