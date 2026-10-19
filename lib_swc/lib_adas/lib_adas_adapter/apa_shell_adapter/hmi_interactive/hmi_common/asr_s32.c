/*
 * File: asr_s32.c
 *
 * Code generated for Simulink model 'hmi_common'.
 *
 * Model version                  : 1.1008
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Fri Nov 29 10:38:57 2024
 */

#include "rtwtypes.h"
#include "asr_s32.h"

int32_T asr_s32(int32_T u, uint32_T n)
{
  int32_T y;
  if (u >= 0)
  {
    y = (int32_T)((uint32_T)(((uint32_T)u) >> n));
  }
  else
  {
    y = (-((int32_T)((uint32_T)(((uint32_T)((int32_T)(-1 - u))) >> n)))) - 1;
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
