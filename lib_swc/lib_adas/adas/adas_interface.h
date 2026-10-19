
#ifndef LIB_SWC_ADAS_INTERFACE_H_
#define LIB_SWC_ADAS_INTERFACE_H_

#include "adas_struct.h"

EM_ADAS_ReturnType Ctrl_TaskInit(void);
EM_ADAS_ReturnType vehicle_interface_Task_20ms();
EM_ADAS_ReturnType Ctrl_Task_20ms(void);
EM_ADAS_ReturnType actuator_handshake_Task_20ms(void);

EM_ADAS_ReturnType Dr_Init_20ms_Task(void);
EM_ADAS_ReturnType Dr_Process_20ms_Task(void);
EM_ADAS_ReturnType Get_VehiPosAllTimeInfo3D(void);


#endif //LIB_SWC_ADAS_INTERFACE_H_
