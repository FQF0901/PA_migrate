#ifndef CTRL_CONTROLLERS_H_
#define CTRL_CONTROLLERS_H_

#include <stdint.h>

/*===========================
*		Pure Pursuit
*==========================*/

typedef struct _CTRL_PURE_PURSUIT_
{
    float m_deltaS; 
    float m_distMP; 
    float m_Ld;
    float m_alpha;  

    float m_x_end; 
    float m_y_end;
    float m_fai_end;
    float m_kcur_end;

    uint8_t m_index;

    uint16_t u16PreviewPathPointId;       
    float f32LatErrorOutput;    
    float f32LatSteerUpLimit;   
    float f32LatSteerLowLimit;  
    float f32PurePursuitReqSteer;
}tCtrlPurePursuit;


/*===========================
*		Stanley
*==========================*/

typedef struct _CTRL_STANLEY_
{
    float f32ReqSteer;
}tCtrlStanley;


/*===========================
*		PID
*==========================*/

typedef struct _CTRL_PID_
{

    float f32LatKp;
    float f32LatKi;
    float f32LatKd;
    float f32LatIntegral;
    float f32LatUmax;
    float f32LatUmin;
    float f32LatTs;

    float farr32LatIntegral[10];
    uint8_t  u8CompsationIndex;  

    float f32LatCompenSteer;
}tCtrlPid;   


/*===========================
*		LQR
*==========================*/

typedef struct _CTRL_LQR_STAT_PARA_
{
    float          f32Ts;
    float          f32K1;
    float          f32K2;
    float          f32K3;
    float          f32K4;
    float          f32LateralErrorCoefficient;
    float          f32ThetaErrorCoefficient;

    float          f32SinglePointFeedforwardAngle;
    float          f32MultiPointFeedforwardAngle;
    float          f32FeedbackAngleRaw;
}tCtrlLqr;     

// to change to tCtrlLqr  

/*===========================
*		MPC
*==========================*/

typedef struct _CTRL_MPC_
{
    float f32ReqSteer;
}tCtrlMpc;

#endif
