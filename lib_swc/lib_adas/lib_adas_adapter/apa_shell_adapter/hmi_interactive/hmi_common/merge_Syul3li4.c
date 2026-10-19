/*
 * File: merge_Syul3li4.c
 *
 * Code generated for Simulink model 'hmi_common'.
 *
 * Model version                  : 1.1008
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Fri Nov 29 10:38:57 2024
 */

#include "rtwtypes.h"
#include "merge_Syul3li4.h"

/* Function for MATLAB Function: '<Root>/SlotGroupDet' */
void merge_Syul3li4(int32_T idx[20], real_T x[20], int32_T offset, int32_T np,
                    int32_T nq, int32_T iwork[20], real_T xwork[20])
{
  int32_T exitg1;
  int32_T iout;
  int32_T offset1;
  int32_T p;
  int32_T q;
  if (nq != 0)
  {
    offset1 = np + nq;
    for (p = 0; p < offset1; p++)
    {
      q = offset + p;
      iwork[p] = idx[q];
      xwork[p] = x[q];
    }

    p = 0;
    q = np;
    iout = offset - 1;
    do
    {
      exitg1 = 0;
      iout++;
      if (xwork[p] <= xwork[q])
      {
        idx[iout] = iwork[p];
        x[iout] = xwork[p];
        if ((p + 1) < np)
        {
          p++;
        }
        else
        {
          exitg1 = 1;
        }
      }
      else
      {
        idx[iout] = iwork[q];
        x[iout] = xwork[q];
        if ((q + 1) < offset1)
        {
          q++;
        }
        else
        {
          offset1 = iout - p;
          while ((p + 1) <= np)
          {
            q = (offset1 + p) + 1;
            idx[q] = iwork[p];
            x[q] = xwork[p];
            p++;
          }

          exitg1 = 1;
        }
      }
    }
    while (exitg1 == 0);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
