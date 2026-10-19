
3.0.9


#1 config 
calib.cfg

#1集成说明
相关函数可见于adas_interface.h

1. 初始化需要调用
EM_ADAS_ReturnType Ctrl_TaskInit(void);
EM_ADAS_ReturnType Dr_Init_20ms_Task(void);

2.20ms任务需要调用
EM_ADAS_ReturnType Ctrl_Task_20ms(void);  //控制20ms任务
EM_ADAS_ReturnType Dr_Process_20ms_Task(void);  //DR20ms任务
uint8_t EM_ADAS_to_AdInterface(void);   //ADAS2APP Interface接口
uint8_t VehsrvTask_20ms()               //Vehicle Service任务