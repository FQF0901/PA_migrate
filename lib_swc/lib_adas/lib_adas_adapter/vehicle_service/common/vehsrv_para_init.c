#include "vehsrv_para_init.h"

uint8_t VehsrvAllGlobalParaInit(void);

static uint8_t VehsrvInputInit(void);
static uint8_t VehsrvProsessInit(void);
static uint8_t VehsrvOutputInit(void);

/*	=====================================================================
*						        Init Func
*	===================================================================*/

uint8_t VehsrvAllGlobalParaInit(void)		
{
	VehsrvInputInit();
	VehsrvProsessInit();
	VehsrvOutputInit();

    return E_OK;
}

static uint8_t VehsrvInputInit(void)
{
    g_stVehsrvInput.f32VehsrvInput1 = 0.0f;
    g_stVehsrvInput.f32VehsrvInput2 = 0.0f;
    g_stVehsrvInput.f32VehsrvInput3 = 0.0f;
    
    return E_OK;
};

static uint8_t VehsrvProsessInit(void)
{
    g_stVehsrvProsess.eVehsrvSts = VEHSRV_STANDBY;
    g_stVehsrvProsess.f32VehsrvProsess2 = 0.0f;
    g_stVehsrvProsess.f32VehsrvProsess3 = 0.0f;

    return E_OK;
};

static uint8_t VehsrvOutputInit(void)
{
    // output demo
    g_stVehsrvOutput.f32VehsrvOutput1 = 0.0f;
    g_stVehsrvOutput.f32VehsrvOutput2 = 0.0f;
    g_stVehsrvOutput.f32VehsrvOutput3 = 0.0f;

    // g_stVehsrv2CtrlData init
    for (int i = 0; i < 12; i ++)
    {
        g_stVehsrv2CtrlData.res_sts[i] = 0;
    }

    for (int i = 0; i < 10; i ++)
    {
        g_stVehsrv2CtrlData.res_val[i] = 0.0f;
    }

    return E_OK;
};
