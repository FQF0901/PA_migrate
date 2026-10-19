/*
 * uss_test_app.h
 *
 *  Created on: 2022/08/02
 *      
 */

#ifndef EM_MCAL_MCAL_DEV_USS_MCAL_USS_TEST_APP_H_
#define EM_MCAL_MCAL_DEV_USS_MCAL_USS_TEST_APP_H_

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/

#include "Std_Types.h"
#include "us_driver_elmos.h"
#if (COMPILE_VEHI_TYPE != VEHI_TYPE_PC)
#include "Bsp.h"
#endif
#include "us_infineon_general.h"
#include "us_common.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define PRINTF_DRIVER_TEST(...)


//EE_READ执行次数
#define EE_READ_N 100

#define USS_DEV_CNTS                (0xCU)

/*打印宏在压力测试的时候不能全开,会导致队列填满*/
//显示所有探头参数
#define PRINT_DATA_OK       0
//报错时显示所有探头参数
#define PRINT_DATA_ERROR    1

//发送命令延时
#define TYPE_SEND_A_DELAY           20
#define TYPE_RECEIVE_A_DELAY        20
#define TYPE_SEND_B_DELAY           15
#define TYPE_RECEIVE_B_DELAY        15
#define TYPE_SEND_C_DELAY           35
#define TYPE_RECEIVE_C_DELAY        35
#define TYPE_CAL_PULSES_DELAY       14
#define TYPE_ENVELOPE_SEND_A_DELAY  34
#define TYPE_ENVELOPE_REC_A_DELAY   34
#define TYPE_THRES_SETUP_DELAY      13
#define TYPE_READ_THRES_SETUP_DELAY 13
#define TYPE_MEAS_SETUP_DELAY       8
#define TYPE_READ_MEAS_SETUP_DELAY  8
#define TYPE_READ_STATUS_DELAY      3
#define TYPE_READ_TEMP_DELAY        3
#define TYPE_CALIB_WRITE_DELAY      9
#define TYPE_CALIB_READ_DELAY       9
#define TYPE_EE_COPY_DELAY          45
#define TYPE_EE_READ_DELAY          24
#define TYPE_READ_ID_DELAY          6
#define TYPE_STANDBY_DELAY          2
#define TYPE_WAKE_UP_DELAY          2

/*********************************************************************************************************************/
/*--------------------------------------------------Data Structures--------------------------------------------------*/
/*********************************************************************************************************************/



/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/



/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/

void UsDriverAutoTestAppInit(void);

void UsDriverAutoFunctionalTestApp(void);

void UsDriverAutoTest_1(void);
void UsDriverAutoTest_2(void);
void UsDriverAutoTest_3(void);
void UsDriverAutoTest_4(void);
void UsDriverAutoTest_5(void);

void UsDriverAutoStressTestApp(void);

#endif
