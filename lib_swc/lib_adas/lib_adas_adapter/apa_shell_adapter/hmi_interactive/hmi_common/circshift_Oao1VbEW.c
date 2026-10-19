/*
 * File: circshift_Oao1VbEW.c
 *
 * Code generated for Simulink model 'hmi_common'.
 *
 * Model version                  : 1.1008
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Fri Nov 29 10:38:57 2024
 */

#include "rtwtypes.h"
#include <string.h>
#include "circshift_Oao1VbEW.h"

/* Function for MATLAB Function: '<Root>/SlotGroupDet' */
void circshift_Oao1VbEW(real_T a[20], real_T p)
{
  real_T a__1[10];
  int32_T d_k;
  int32_T ns;
  boolean_T shiftright;
  if (p < 0.0)
  {
    ns = (int32_T)((real_T)(-p));
    shiftright = false;
  }
  else
  {
    ns = 0;
    shiftright = true;
  }

  if (ns > 20)
  {
    ns -= (ns / 20) * 20;
  }

  if (ns > 10)
  {
    ns = 20 - ns;
    shiftright = shiftright ^ 1;
  }

  (void)memset(&a__1[0], 0, 10U * (sizeof(real_T)));
  if (ns > 0)
  {
    if (shiftright)
    {
      for (d_k = 0; d_k < ns; d_k++)
      {
        a__1[d_k] = a[(d_k - ns) + 20];
      }

      for (d_k = 19; (d_k + 1) >= (ns + 1); d_k--)
      {
        a[d_k] = a[d_k - ns];
      }

      for (d_k = 0; d_k < ns; d_k++)
      {
        a[d_k] = a__1[d_k];
      }
    }
    else
    {
      for (d_k = 0; d_k < ns; d_k++)
      {
        a__1[d_k] = a[d_k];
      }

      for (d_k = 0; d_k <= (19 - ns); d_k++)
      {
        a[d_k] = a[d_k + ns];
      }

      for (d_k = 0; d_k < ns; d_k++)
      {
        a[(d_k - ns) + 20] = a__1[d_k];
      }
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
