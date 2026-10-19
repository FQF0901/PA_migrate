/*
 * File: rt_hypotf.c
 *
 * Code generated for Simulink model 'hmi_common'.
 *
 * Model version                  : 1.1008
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Fri Nov 29 10:38:57 2024
 */

#include "rtwtypes.h"
#include <math.h>
#include "rt_hypotf.h"

real32_T rt_hypotf(real32_T u0, real32_T u1)
{
  real32_T a;
  real32_T b;
  real32_T y;
  a = fabsf(u0);
  b = fabsf(u1);
  if (a < b)
  {
    a /= b;
    y = sqrtf((a * a) + 1.0F) * b;
  }
  else if (a > b)
  {
    b /= a;
    y = sqrtf((b * b) + 1.0F) * a;
  }
  else
  {
    y = a * 1.41421354F;
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
