#include <math.h>
#include <stdint.h>
#include "dr_filter.h"

#if DR_EKF_ON
ST_VEHICLE_IMU_INFO g_stVehilceIMUdata;

float valxPred[] = { 0,0,0,0 };/*此处从soc端看能不能得到一个GPS或者是拟合的初始位置，不用太精确*/
float zPred[] = { 0,0,0 };
float valY[] = { 0,0,0 };

Mat xPred;
Mat J_F;
Mat J_H;
Mat J_H_trans;
Mat J_F_trans;
Mat PEst;
Mat PPred;
Mat Q;
Mat R;
Mat S;
Mat CalTemp;
Mat CalTemp2;
Mat S_temp1;
Mat S_temp2;
Mat S_Inv;

Mat K;
Mat K_temp1;
Mat K_temp2;

Mat xEst_temp1;
Mat xEst;
Mat pEst;
Mat pEst_temp1;
Mat pEst_temp2;
Mat pEst_temp3;

Mat Y;
Mat eyeXest;

//MATH_RAD2DEG()
//MATH_DEG2RAD()


EM_ADAS_ReturnType DR_filtering_Init()//初始化，所有的临时变量赋初值
{
    
    float valx_Est[] = {0,0,0,0 };
    
    float valP_Est[] = 
    {
        1.0,   0,    0,     0,
        0,   1.0,    0,     0,
        0,     0,  1.0,     0,
        0,     0,    0,   1.0
    };


    float valCal_Temp[] = 
    {
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0
    };

    float valQ[] = 
    {
        0.01,   0 ,   0,    0,
        0,   0.01,    0,    0,
        0,     0,  0.03,    0,
        0,     0,    0,  0.5
    };

    float valR[] = 
    {
        0.05,   0 ,   0,
        0,   0.05,    0,
        0,     0,  0.001,
    };

    float valS[] = 
    {
        0,0,0,
        0,0,0,
        0,0,0
    };

    float valeyeXest[] = 
    {
        1.0,   0,    0,    0,
        0,   1.0,    0,    0,
        0,     0,  1.0,    0,
        0,     0,    0,  1.0
    };

    MatCreate(&J_F, 4, 4);
    MatCreate(&J_F_trans, 4, 4);
    MatCreate(&PEst, 4, 4);
    MatCreate(&PPred, 4, 4);
    MatCreate(&CalTemp, 4, 4);
    MatCreate(&CalTemp2, 4, 4);
    MatCreate(&Q, 4, 4);

    MatCreate(&xPred, 4, 1);
    MatSetVal(&xPred, valxPred);

    MatSetVal(&PEst, valP_Est);
    MatSetVal(&CalTemp, valCal_Temp);
    MatSetVal(&Q, valQ);

    MatCreate(&R, 3, 3);
    MatSetVal(&R, valR);

    MatCreate(&eyeXest, 4, 4);
    MatSetVal(&eyeXest, valeyeXest);

    MatCreate(&xEst, 4, 1);
    MatSetVal(&xEst, valx_Est);

    MatCreate(&xPred, 4, 1);
    MatCreate(&J_H, 3, 4);
    MatCreate(&J_H_trans, 4, 3);
    MatCreate(&S, 3, 3);
    MatCreate(&S_temp1, 3, 4);
    MatCreate(&S_temp2, 3, 3);
    MatCreate(&S_Inv, 3, 3);
    MatCreate(&K, 4, 3);
    MatCreate(&K_temp1, 4, 3);
    MatCreate(&pEst, 4, 4);
    MatCreate(&pEst_temp1, 4, 4);
    MatCreate(&pEst_temp2, 4, 4);
    MatCreate(&pEst_temp3, 4, 4);
    MatCreate(&Y, 3, 1);
    MatCreate(&xEst_temp1, 4, 1);

    return ADAS_RETURN_OK;
}


/*控制量:前轮转角速率yaw_rate、车身速度speed，观测量：车世界坐标系：x、y，和车身姿态Theta*/
EM_ADAS_ReturnType DR_filtering(PST_DR_INFO    Obs_Position,
                                ST_VEHICLE_IMU_INFO* Input_YawRate,
                                tVehi_VehicleDataRx* Input_Speed)//观测测量量命名  轮端脉冲差Yaw_rate  IMU||感知-》Theta
{
    float f32DT = 0.02;//dt，计算周期
    
    valxPred[0] = xEst.element[0][0];//最优估计值作为下一次迭代的输入
    valxPred[1] = xEst.element[1][0];
    valxPred[2] = xEst.element[2][0];
    valxPred[3] = xEst.element[3][0];

    valxPred[0] = valxPred[0] + f32DT * cosf(valxPred[2]) * valxPred[3];    // x_{t+1} = x_t+v*dt*cos(yaw)
    valxPred[1] = valxPred[1] + f32DT * sinf(valxPred[2]) * valxPred[3];//y_{ t + 1 } = y_t + v * dt * sin(yaw)
    valxPred[2] = valxPred[2] + f32DT * Input_YawRate->f32Yaw_Rate;//yaw_{t + 1 } = yaw_t + omega * dt
    valxPred[3] = Input_Speed->stVehESCInfo.f32VehicleSpeed;//v_{ t + 1 } = v{ t }
    MatSetVal(&xPred, valxPred); //将值填入矩阵

    float valJ_F[] = 
    {
        1.0,  0, -1*f32DT * valxPred[3] * f32DT * sinf(MATH_DEG2RAD(valxPred[2])), f32DT * cosf(MATH_DEG2RAD(valxPred[2])),
        0,  1.0,  f32DT * valxPred[3] * f32DT * cosf(MATH_DEG2RAD(valxPred[2])), f32DT * sinf(MATH_DEG2RAD(valxPred[2])),
        0,  0,    1.0,  0,
        0,  0,    0,  0
    };//状态转移阵
    MatSetVal(&J_F, valJ_F);
    float valJ_H[] = 
    {
        1.0,   0,   0,   0,
          0, 1.0,   0,   0,
          0,   0, 1.0,   0
    };//观测阵
    MatSetVal(&J_H, valJ_H);

    //Xpred = Motion(xEst,ud);
    //jF = Jacob_F(xEst,ud);

  //Predict 求Pk+1
    MatTrans(&J_F, &J_F_trans);  //求转置F
    MatMul(&J_F, &PEst, &CalTemp);  //求FP(t-1)
    MatMul(&CalTemp, &J_F_trans, &CalTemp2);//求FP(t-1)Ft
    MatAdd(&CalTemp2, &Q, &PPred);//得到当前的误差协方差阵P-

    MatTrans(&J_H, &J_H_trans);//求H转置Ht
    MatMul(&J_H, &PPred, &S_temp1);//求HP-
    MatMul(&S_temp1, &J_H_trans, &S_temp2);//求HP-Ht
    MatAdd(&S_temp2, &R, &S);//求HP-Ht+R
    MatInv(&S, &S_Inv);//求（HP-Ht+R）-1
    MatMul(&PPred, &J_H_trans, &K_temp1);//求P-Ht
    MatMul(&K_temp1, &S_Inv, &K);//求kk =P-Ht（HP-Ht+R）-1

    zPred[0] = valxPred[0] * 1;//求观测值的预估值Hx-
    zPred[1] = valxPred[1] * 1;
    zPred[2] = valxPred[2] * 1;

    valY[0] = Obs_Position->stNowPose.f32X_Coor - zPred[0];//求观测偏差z（t-1）-Hx-
    valY[1] = Obs_Position->stNowPose.f32Y_Coor - zPred[1];
    valY[2] = MATH_DEG2RAD(Obs_Position->stNowPose.f32Theta) - zPred[2];

    MatSetVal(&Y, valY);//将z（t-1）-Hx-填入矩阵
    MatMul(&K, &Y, &xEst_temp1);//K(z（t-1）-Hx-)
    MatAdd(&xPred, &xEst_temp1, &xEst);//求最优估计值xhat=x-+K(z（t-1）-Hx-)
    MatMul(&K, &J_H, &pEst_temp1);//KH
    MatSub(&eyeXest, &pEst_temp1, &pEst_temp2);//I-KH
    MatMul(&pEst_temp2, &PPred, &pEst);            //求Pk，值要回归p-(I-KH)

    return ADAS_RETURN_OK;
}

EM_ADAS_ReturnType DR_filtering_Clear() //备用，用于释放滤波产生的内存占用
{
    MatDelete(&xPred);
    MatDelete(&J_F);
    MatDelete(&J_H);
    MatDelete(&J_H_trans);
    MatDelete(&J_F_trans);
    MatDelete(&PEst);
    MatDelete(&Q);
    MatDelete(&R);
    MatDelete(&S);
    MatDelete(&CalTemp);
    MatDelete(&CalTemp2);
    MatDelete(&S_temp1);
    MatDelete(&S_temp2);
    MatDelete(&S_Inv);
    MatDelete(&K);
    MatDelete(&K_temp1);
    MatDelete(&K_temp2);
    MatDelete(&xEst_temp1);
    MatDelete(&xEst);
    MatDelete(&pEst);
    MatDelete(&pEst_temp1);
    MatDelete(&pEst_temp2);
    MatDelete(&pEst_temp3);
    MatDelete(&Y);
    MatDelete(&eyeXest);

    return ADAS_RETURN_OK;
}
#endif

