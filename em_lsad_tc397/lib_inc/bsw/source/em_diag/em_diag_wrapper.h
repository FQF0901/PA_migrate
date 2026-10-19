#ifndef EM_DIAG_WRAPPER_H__
#define EM_DIAG_WRAPPER_H__

#include "em_diag_process.h"
#include "emos_rte.h"

extern TaskPeriodTestType bsw_task_c0_test;
extern TaskPeriodTestType bsw_10ms_c0_test;
extern TaskPeriodTestType app_10ms_c0_test;
extern TaskPeriodTestType app_5ms_c0_test;
extern TaskPeriodTestType app_25ms_c0_test;
extern TaskPeriodTestType bsw_20ms_c1_test;
extern TaskPeriodTestType uss_5ms_c1_test;
extern TaskPeriodTestType uss_10ms_c1_test;
extern TaskPeriodTestType uss_20ms_c1_test;
extern TaskPeriodTestType uss_50ms_c1_test;
extern TaskPeriodTestType bsw_20ms_c2_test;
extern TaskPeriodTestType app_5ms_c2_test;
extern TaskPeriodTestType app_10ms_c2_test;
extern TaskPeriodTestType app_20ms_c2_test;
extern TaskPeriodTestType app_50ms_c2_test;

void Diag_IsSocEmdcActive();
void EntryPoint_EM_App_5ms_C0_test();
void ExitPoint_EM_App_5ms_C0_test();
void EntryPoint_EM_Bsw_10ms_C0_test();
void EntryPoint_EM_App_10ms_C0_test();
void ExitPoint_EM_Bsw_10ms_C0_test();
void ExitPoint_EM_App_10ms_C0_test();
void EntryPoint_EM_Bsw_Task_C0_test();
void ExitPoint_EM_Bsw_Task_C0_test();
void EntryPoint_EM_App_25ms_C0_test();
void ExitPoint_EM_App_25ms_C0_test();
void EntryPoint_EM_Uss_5ms_C1_test();
void ExitPoint_EM_Uss_5ms_C1_test();
void EntryPoint_EM_Uss_10ms_C1_test();
void ExitPoint_EM_Uss_10ms_C1_test();
void EntryPoint_EM_Bsw_20ms_C1_test();
void EntryPoint_EM_Uss_20ms_C1_test();
void ExitPoint_EM_Bsw_20ms_C1_test();
void ExitPoint_EM_Uss_20ms_C1_test();
void EntryPoint_EM_Uss_50ms_C1_test();
void ExitPoint_EM_Uss_50ms_C1_test();
void EntryPoint_EM_App_5ms_C2_test();
void ExitPoint_EM_App_5ms_C2_test();
void EntryPoint_EM_App_10ms_C2_test();
void ExitPoint_EM_App_10ms_C2_test();
void EntryPoint_EM_Bsw_20ms_C2_test();
void EntryPoint_EM_App_20ms_C2_test();
void ExitPoint_EM_Bsw_20ms_C2_test();
void ExitPoint_EM_App_20ms_C2_test();
void EntryPoint_EM_App_50ms_C2_test();
void ExitPoint_EM_App_50ms_C2_test();
void McuLog_Send();
#endif