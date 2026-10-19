
#include "adas_logger.h"
#include "ctrl_global_variables.h"


//static enum LOG_LEVEL logger=LOG_LEVEL_WARN;

void printCtrl2PP()
{
    ADAS_LOG(LOG_LEVEL_WARN, "adas log ctrl2pp start");

    ADAS_LOG(LOG_LEVEL_INFO, "%d %d %d %d", g_stCtrlToPathPlannerInfo.u16CurPathid, g_stCtrlToPathPlannerInfo.u8CtrlState,
                                 g_stCtrlToPathPlannerInfo.u8CtrlSubstate, g_stCtrlToPathPlannerInfo.u8PathPEBDir);

    ADAS_LOG(LOG_LEVEL_WARN, "%s", "adas log ctrl2pp end");
}

void printLog()
{
    ADAS_LOG(LOG_LEVEL_WARN, "adas log test start");

    ADAS_LOG(LOG_LEVEL_INFO, "%d %d %d %d", g_stCtrlToPathPlannerInfo.u16CurPathid, g_stCtrlToPathPlannerInfo.u8CtrlState,
                                 g_stCtrlToPathPlannerInfo.u8CtrlSubstate, g_stCtrlToPathPlannerInfo.u8PathPEBDir);

    ADAS_LOG(LOG_LEVEL_WARN, "%s %d\r\n", "adas log test end", 456);
}

