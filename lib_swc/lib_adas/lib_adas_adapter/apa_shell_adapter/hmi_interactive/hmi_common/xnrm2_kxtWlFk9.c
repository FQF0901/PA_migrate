/*
 * File: xnrm2_kxtWlFk9.c
 *
 * Code generated for Simulink model 'hmi_common'.
 *
 * Model version                  : 1.1008
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Fri Nov 29 10:38:57 2024
 */

#include "rtwtypes.h"
#include <math.h>
#include "xnrm2_kxtWlFk9.h"

/* Function for MATLAB Function: '<Root>/ADCS9PlotFitCalc' */
real32_T xnrm2_kxtWlFk9(int32_T n, const real32_T x[16], int32_T ix0)
{
  int32_T k;
  int32_T kend;
  real32_T absxk;
  real32_T scale;
  real32_T t;
  real32_T y;
  y = 0.0F;
  if (n >= 1)
  {
    if (n == 1)
    {
      y = fabsf(x[ix0 - 1]);
    }
    else
    {
      scale = 1.29246971E-26F;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++)
      {
        absxk = fabsf(x[k - 1]);
        if (absxk > scale)
        {
          t = scale / absxk;
          y = ((y * t) * t) + 1.0F;
          scale = absxk;
        }
        else
        {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrtf(y);
    }
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
