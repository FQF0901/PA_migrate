/*
 * File: polyfit_ZTjQ9uNU.c
 *
 * Code generated for Simulink model 'hmi_common'.
 *
 * Model version                  : 1.1008
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Fri Nov 29 10:38:57 2024
 */

#include "rtwtypes.h"
#include "qrpf_lcXs6Mkx.h"
#include "polyfit_ZTjQ9uNU.h"

/* Function for MATLAB Function: '<Root>/ADCS9PlotFitCalc' */
void polyfit_ZTjQ9uNU(const real32_T x[4], const real32_T y[4], real32_T p[4])
{
  int32_T jpvt[4];
  int32_T V_tmp;
  int32_T V_tmp_0;
  int32_T assumedRank;
  real32_T V[16];
  real32_T B[4];
  real32_T tau[4];
  real32_T wj;
  V[12] = 1.0F;
  V[8] = x[0];
  V[13] = 1.0F;
  V[9] = x[1];
  V[14] = 1.0F;
  V[10] = x[2];
  V[15] = 1.0F;
  V[11] = x[3];
  for (assumedRank = 0; assumedRank < 2; assumedRank++)
  {
    V_tmp = (2 - assumedRank) * 4;
    V_tmp_0 = (1 - assumedRank) * 4;
    V[V_tmp_0] = V[V_tmp] * x[0];
    V[V_tmp_0 + 1] = V[V_tmp + 1] * x[1];
    V[V_tmp_0 + 2] = V[V_tmp + 2] * x[2];
    V[V_tmp_0 + 3] = V[V_tmp + 3] * x[3];
  }

  jpvt[0] = 1;
  tau[0] = 0.0F;
  jpvt[1] = 2;
  tau[1] = 0.0F;
  jpvt[2] = 3;
  tau[2] = 0.0F;
  jpvt[3] = 4;
  tau[3] = 0.0F;
  qrpf_lcXs6Mkx(V, 1, 4, 4, tau, jpvt);
  assumedRank = -1;
  if (V[0] != 0.0F)
  {
    assumedRank = 0;
  }

  p[0] = 0.0F;
  B[0] = y[0];
  if (V[5] != 0.0F)
  {
    assumedRank++;
  }

  p[1] = 0.0F;
  B[1] = y[1];
  if (V[10] != 0.0F)
  {
    assumedRank++;
  }

  p[2] = 0.0F;
  B[2] = y[2];
  if (V[15] != 0.0F)
  {
    assumedRank++;
  }

  p[3] = 0.0F;
  B[3] = y[3];
  if (tau[0] != 0.0F)
  {
    wj = y[0];
    for (V_tmp = 1; (V_tmp + 1) < 5; V_tmp++)
    {
      wj += V[V_tmp] * B[V_tmp];
    }

    wj *= tau[0];
    if (wj != 0.0F)
    {
      B[0] = y[0] - wj;
      for (V_tmp = 1; (V_tmp + 1) < 5; V_tmp++)
      {
        B[V_tmp] -= V[V_tmp] * wj;
      }
    }
  }

  if (tau[1] != 0.0F)
  {
    wj = B[1];
    for (V_tmp = 2; (V_tmp + 1) < 5; V_tmp++)
    {
      wj += V[V_tmp + 4] * B[V_tmp];
    }

    wj *= tau[1];
    if (wj != 0.0F)
    {
      B[1] -= wj;
      for (V_tmp = 2; (V_tmp + 1) < 5; V_tmp++)
      {
        B[V_tmp] -= V[V_tmp + 4] * wj;
      }
    }
  }

  if (tau[2] != 0.0F)
  {
    wj = B[2];
    for (V_tmp = 3; (V_tmp + 1) < 5; V_tmp++)
    {
      wj += V[V_tmp + 8] * B[V_tmp];
    }

    wj *= tau[2];
    if (wj != 0.0F)
    {
      B[2] -= wj;
      for (V_tmp = 3; (V_tmp + 1) < 5; V_tmp++)
      {
        B[V_tmp] -= V[V_tmp + 8] * wj;
      }
    }
  }

  if (tau[3] != 0.0F)
  {
    wj = tau[3] * B[3];
    if (wj != 0.0F)
    {
      B[3] -= wj;
    }
  }

  for (V_tmp = 0; V_tmp <= assumedRank; V_tmp++)
  {
    p[jpvt[V_tmp] - 1] = B[V_tmp];
  }

  while ((assumedRank + 1) > 0)
  {
    V_tmp = assumedRank * 4;
    p[jpvt[assumedRank] - 1] /= V[V_tmp + assumedRank];
    for (V_tmp_0 = 0; V_tmp_0 < assumedRank; V_tmp_0++)
    {
      p[jpvt[V_tmp_0] - 1] -= V[V_tmp + V_tmp_0] * p[jpvt[assumedRank] - 1];
    }

    assumedRank--;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
