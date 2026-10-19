#ifndef _CTRL_ERRCODE_H_
#define _CTRL_ERRCODE_H_

#include "ctrl_module_id.h"

/********************************Error Code Definition********************************/
#define CTRL_ERRCODE_DEF(module_id, err_id)     (uint16_t)(0x0000 | ((module_id) << 12)  | (err_id))

/**< Init Error Define */
#define CTRL_ERR_INIT                                CTRL_ERRCODE_DEF(CTRL_MODULE_ID_INIT, 0x0001)     /**< 资源初始化失败 */

/**< Input Error Define */
#define CTRL_ERR_INPUT_CAN                           CTRL_ERRCODE_DEF(CTRL_MODULE_ID_INPUT, 0x0000)    /**< CAN数据 诊断码 */
    #define CTRL_ERR_INPUT_CHASSIS                   CTRL_ERRCODE_DEF(CTRL_MODULE_ID_INPUT, 0x0100)    /**< Chassis 诊断码 */
        #define CTRL_ERR_INPUT_CHASSIS_OVERSPEED     CTRL_ERRCODE_DEF(CTRL_MODULE_ID_INPUT, 0x0101)    /**< VCU 诊断码 - 超速 */
        #define CTRL_ERR_INPUT_CHASSIS_STEER_INVALID CTRL_ERRCODE_DEF(CTRL_MODULE_ID_INPUT, 0x0102)    /**< EPS 诊断码 - 方向盘转角无效值 */
        #define CTRL_ERR_INPUT_CHASSIS_PULSE_INVALID CTRL_ERRCODE_DEF(CTRL_MODULE_ID_INPUT, 0x0103)    /**< ESC 诊断码 - 轮速脉冲无效值 */
    #define CTRL_ERR_INPUT_USS                       CTRL_ERRCODE_DEF(CTRL_MODULE_ID_INPUT, 0x0200)    /**< USS 诊断码 */
        #define CTRL_ERR_INPUT_USS_INVALID_VALUE     CTRL_ERRCODE_DEF(CTRL_MODULE_ID_INPUT, 0x0201)    /**< PDC 无效值 */
        #define CTRL_ERR_INPUT_USS_DANGER_DIS        CTRL_ERRCODE_DEF(CTRL_MODULE_ID_INPUT, 0x0202)    /**< PDC 危险区域，包含盲区 */
        #define CTRL_ERR_INPUT_USS_SYSTEM_ERROR      CTRL_ERRCODE_DEF(CTRL_MODULE_ID_INPUT, 0x0203)    /**< USS 系统故障 */
    #define CTRL_ERR_INPUT_SM                        CTRL_ERRCODE_DEF(CTRL_MODULE_ID_INPUT, 0x0300)    /**< APA SHELL 诊断码  */
        #define CTRL_ERR_INPUT_SM_STS_INVALID        CTRL_ERRCODE_DEF(CTRL_MODULE_ID_INPUT, 0x0301)    /**< APA SHELL 无效状态 */
        #define CTRL_ERR_INPUT_SM_TYPE_INVALID       CTRL_ERRCODE_DEF(CTRL_MODULE_ID_INPUT, 0x0302)    /**< APA SHELL 无效类型 */
        #define CTRL_ERR_INPUT_SM_STS_TERMINATED     CTRL_ERRCODE_DEF(CTRL_MODULE_ID_INPUT, 0x0303)    /**< APA SHELL 控制器终止 */
        #define CTRL_ERR_INPUT_SM_STS_CANCEL         CTRL_ERRCODE_DEF(CTRL_MODULE_ID_INPUT, 0x0304)    /**< APA SHELL 驾驶员终止 */
        #define CTRL_ERR_INPUT_SM_STS_FAILURE        CTRL_ERRCODE_DEF(CTRL_MODULE_ID_INPUT, 0x0305)    /**< APA SHELL 系统故障 */
#define CTRL_ERR_INPUT_SOC                           CTRL_ERRCODE_DEF(CTRL_MODULE_ID_INPUT, 0x0400)    /**< SOC数据 诊断码 */
    #define CTRL_ERR_INPUT_PP                        CTRL_ERRCODE_DEF(CTRL_MODULE_ID_INPUT, 0x0410)    /**< PP 诊断码 */
        #define CTRL_ERR_INPUT_PP_FAILURE            CTRL_ERRCODE_DEF(CTRL_MODULE_ID_INPUT, 0x0411)    /**< PP 规划失败 */
        #define CTRL_ERR_INPUT_PP_NO_PATH            CTRL_ERRCODE_DEF(CTRL_MODULE_ID_INPUT, 0x0412)    /**< PP 规划无路 */
        #define CTRL_ERR_INPUT_PP_REPLAN_FAIL        CTRL_ERRCODE_DEF(CTRL_MODULE_ID_INPUT, 0x0413)    /**< PP 重规划失败 */
    #define CTRL_ERR_INPUT_DF                        CTRL_ERRCODE_DEF(CTRL_MODULE_ID_INPUT, 0x0500)    /**< DF 诊断码 - 待完善 */

/**< Ouput Error Define */
#define CTRL_ERR_OUTPUT_CHASSIS                      CTRL_ERRCODE_DEF(CTRL_MODULE_ID_OUTPUT, 0x0000)    /**< Chassis 诊断码 */
    #define CTRL_ERR_OUTPUT_STEER_UNREACHED          CTRL_ERRCODE_DEF(CTRL_MODULE_ID_OUTPUT, 0x0001)    /**< 方向盘执行器未达指定的大角度(暂定±400°) */

#define CTRL_ERR_OUTPUT_SOC                          CTRL_ERRCODE_DEF(CTRL_MODULE_ID_OUTPUT, 0x0100)    /**< SOC数据 诊断码 */


/**< Handshake Error Define */
#define CTRL_ERR_HANDSHAKE_EXECUTE_FAIL              CTRL_ERRCODE_DEF(CTRL_MODULE_ID_HANDSHAKE, 0x0001)  /**< 控车握手失败 */
#define CTRL_ERR_HANDSHAKE_EXIT_FAIL                 CTRL_ERRCODE_DEF(CTRL_MODULE_ID_HANDSHAKE, 0x0002)  /**< 控车握手解除失败 */


/**< USER Error Define */
#define CTRL_ERR_USER                                CTRL_ERRCODE_DEF(CTRL_MODULE_ID_USER, 0x0000)       /**< 用户行为 */
#define CTRL_ERR_USER_CANCEL                         CTRL_ERRCODE_DEF(CTRL_MODULE_ID_USER, 0x0001)       /**< 用户取消泊车 */
#define CTRL_ERR_USER_PAUSE                          CTRL_ERRCODE_DEF(CTRL_MODULE_ID_USER, 0x0002)       /**< 用户暂停泊车 */
#define CTRL_ERR_USER_CANCEL_PAUSE                   CTRL_ERRCODE_DEF(CTRL_MODULE_ID_USER, 0x0003)       /**< 用户取消暂停 */
#define CTRL_ERR_USER_STEER                          CTRL_ERRCODE_DEF(CTRL_MODULE_ID_USER, 0x0004)       /**< 用户转动方向盘 */
#define CTRL_ERR_USER_BREAK                          CTRL_ERRCODE_DEF(CTRL_MODULE_ID_USER, 0x0005)       /**< 用户踩刹车 */
#define CTRL_ERR_USER_THROTTLE                       CTRL_ERRCODE_DEF(CTRL_MODULE_ID_USER, 0x0006)       /**< 用户踩油门/电门 */
#define CTRL_ERR_USER_DOOR_OPEN                      CTRL_ERRCODE_DEF(CTRL_MODULE_ID_USER, 0x0007)       /**< 用户打开车门 */
#define CTRL_ERR_USER_SAFETY_BELT_UNFASTENED         CTRL_ERRCODE_DEF(CTRL_MODULE_ID_USER, 0x0008)       /**< 用户解开安全带 */


/**< Peb Error Define */
#define CTRL_ERR_PEB                                 CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PEB, 0x0000)        /**< PEB错误 */
#define CTRL_ERR_PEB_MISINFO                         CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PEB, 0x0001)        /**< 误报消息 */
#define CTRL_ERR_PEB_DANGER_DISTANCE                 CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PEB, 0x0002)        /**< 危险距离 */


/**< DR Error Define */
#define CTRL_ERR_DR                                  CTRL_ERRCODE_DEF(CTRL_MODULE_ID_DR, 0x0000)         /**< DR错误 */
#define CTRL_ERR_DR_TIMESTAMP                        CTRL_ERRCODE_DEF(CTRL_MODULE_ID_DR, 0x0001)         /**< 时间戳 */


/**< Park Error Define */
#define CTRL_ERR_PARK                                CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0000)       /**< 泊车错误 */
    #define CTRL_ERR_PARK_TOUCH_MAX                  CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0100)       /**< 达到最大值 */
        #define CTRL_ERR_PARK_GEAR_CHANGE_MAX        CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0101)       /**< 档位切换达到最大值 */
        #define CTRL_ERR_PARK_PEB_MAX                CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0102)       /**< PEB触发次数达到最大值 */
        #define CTRL_ERR_PARK_PAUSE_MAX              CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0103)       /**< 暂停次数达到最大值 */
        #define CTRL_ERR_PARK_WAIT_TIMEOUT           CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0104)       /**< 等待时间超时 */
        #define CTRL_ERR_PARK_WAIT_NEW_PATH_TIMEOUT  CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0105)       /**< 等待PP新路超时 - 10秒 */
        #define CTRL_ERR_PARK_WAIT_FIRSTPATH_TIMEOUT CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0106)       /**< 等待PP第一段路超时 - 2秒 */
        #define CTRL_ERR_PARK_HORIZON_OFFSET_MAX     CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0107)       /**< 横向偏差超过最大值 */

    #define CTRL_ERR_PARK_PATH_ERROR                 CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0200)       /**< PP信息错误 */
        #define CTRL_ERR_PARK_PP_STS_INVALID         CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0201)       /**< PP状态无效，无第一段路输出 */
        #define CTRL_ERR_PARK_PP_REPLAN_INVALID      CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0202)       /**< PP重规划状态无效 */
        #define CTRL_ERR_PARK_PATH_ID_INVALID        CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0203)       /**< PathID无效 */
        #define CTRL_ERR_PARK_PATH_P_GEAR            CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0204)       /**< PP给出P档位 */
        #define CTRL_ERR_PARK_PATH_GEAR_WRONG        CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0205)       /**< 档位错误 */

    #define CTRL_ERR_PARK_ENV                        CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0300)       /**< 周围环境导致的错误 */
        #define CTRL_ERR_PARK_NEAR_END_POSE_PARALLEL CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0301)       /**< 水平车位接近终点 25cm*/
        #define CTRL_ERR_PARK_NEAR_END_POSE_VERTICAL CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0302)       /**< 垂直车位接近终点 1m*/
        #define CTRL_ERR_PARK_TRAPPED                CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0304)       /**< 车辆同时被前后PEB困住 */
        #define CTRL_ERR_PARK_FRONT_SPACE_LIMITED    CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0305)       /**< 前方空间受限 */
        #define CTRL_ERR_PARK_SIDE_SPACE_LIMITED     CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0306)       /**< 侧方空间受限 */
        #define CTRL_ERR_PARK_REAR_SPACE_LIMITED     CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0307)       /**< 后方空间受限 */
        #define CTRL_ERR_PARK_VERTICAL_CHOCK         CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0310)       /**< 垂直库位撞击轮挡或卡住 */
        #define CTRL_ERR_PARK_HORIZONTAL_CHOCK       CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0311)       /**< 水平库位卡住 */
        #define CTRL_ERR_PARK_GENERAL_CHOCK          CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0312)       /**< 一般情况卡住 */
        #define CTRL_ERR_PARK_UNKNOWN_LONG_STOP      CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0313)       /**< 未知原因长时间停住 */
    #define CTRL_ERR_PARK_SYSTEM_ERROR               CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0400)       /**< 系统错误 */
    #define CTRL_ERR_PARK_COMPLETE                   CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0500)       /**< 正常退出 */
    #define CTRL_ERR_PARK_PREVENT_BLOCK              CTRL_ERRCODE_DEF(CTRL_MODULE_ID_PARK, 0x0600)       /**< 控制主动退出，防止阻塞 */


/**< HEADout(No PathPlanner) Error Define */
#define CTRL_ERR_HEADOUT                             CTRL_ERRCODE_DEF(CTRL_MODULE_ID_HEADOUT, 0x0000)    /**< 泊出错误 */
#define CTRL_ERR_HEADOUT_PEB                         CTRL_ERRCODE_DEF(CTRL_MODULE_ID_HEADOUT, 0x0001)    /**< PEB发生 */


/**< Cruise Error Define */
#define CTRL_ERR_CRUISE                              CTRL_ERRCODE_DEF(CTRL_MODULE_ID_CRUISE, 0x0000)     /**< 巡航错误 */


/**< Unknown Error Define */
#define CTRL_ERR_UNKNOWN                             CTRL_ERRCODE_DEF(CTRL_MODULE_ID_UNKNOWN, 0x0001)    /**< 未知错误 */


/** ====End of Error Code Definition==== */

#endif //_CTRL_ERRCODE_H_

