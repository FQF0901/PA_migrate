#ifndef SRC_APA_SHELL_H_
#define SRC_APA_SHELL_H_

#include "emos_rte.h"
#include "rte.h"
#include "lsad_fsm_core_type.h"

void SetAPAShellCoreInput(void);
void SetMsgMnger_TextDisp(void);
void DragPLTest(void);
Std_ReturnType APA_ShellInit(void);
Std_ReturnType APA_ShellStep(void);

#endif /* SRC_APA_SHELL_H_ */