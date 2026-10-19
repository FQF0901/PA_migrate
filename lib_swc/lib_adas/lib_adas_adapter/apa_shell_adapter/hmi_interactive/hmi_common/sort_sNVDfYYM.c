/*
 * File: sort_sNVDfYYM.c
 *
 * Code generated for Simulink model 'hmi_common'.
 *
 * Model version                  : 1.1008
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Fri Nov 29 10:38:57 2024
 */

#include "rtwtypes.h"
#include <string.h>
#include "asr_s32.h"
#include "merge_Syul3li4.h"
#include "sort_sNVDfYYM.h"

/* Function for MATLAB Function: '<Root>/SlotGroupDet' */
void sort_sNVDfYYM(real_T x[20], int32_T idx[20])
{
  real_T xwork[20];
  real_T x4[4];
  real_T tmp;
  real_T tmp_0;
  int32_T iwork[20];
  int32_T i;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T ib;
  int8_T idx4[4];
  int8_T perm[4];
  x4[0] = 0.0;
  idx4[0] = 0;
  x4[1] = 0.0;
  idx4[1] = 0;
  x4[2] = 0.0;
  idx4[2] = 0;
  x4[3] = 0.0;
  idx4[3] = 0;
  ib = -1;
  for (i = 0; i < 20; i++)
  {
    idx[i] = 0;
    ib++;
    idx4[ib] = (int8_T)(i + 1);
    x4[ib] = x[i];
    if ((ib + 1) == 4)
    {
      if (x4[0] <= x4[1])
      {
        ib = 1;
        i2 = 2;
      }
      else
      {
        ib = 2;
        i2 = 1;
      }

      if (x4[2] <= x4[3])
      {
        i3 = 3;
        i4 = 4;
      }
      else
      {
        i3 = 4;
        i4 = 3;
      }

      tmp = x4[ib - 1];
      tmp_0 = x4[i3 - 1];
      if (tmp <= tmp_0)
      {
        tmp = x4[i2 - 1];
        if (tmp <= tmp_0)
        {
          perm[0] = (int8_T)ib;
          perm[1] = (int8_T)i2;
          perm[2] = (int8_T)i3;
          perm[3] = (int8_T)i4;
        }
        else if (tmp <= x4[i4 - 1])
        {
          perm[0] = (int8_T)ib;
          perm[1] = (int8_T)i3;
          perm[2] = (int8_T)i2;
          perm[3] = (int8_T)i4;
        }
        else
        {
          perm[0] = (int8_T)ib;
          perm[1] = (int8_T)i3;
          perm[2] = (int8_T)i4;
          perm[3] = (int8_T)i2;
        }
      }
      else
      {
        tmp_0 = x4[i4 - 1];
        if (tmp <= tmp_0)
        {
          if (x4[i2 - 1] <= tmp_0)
          {
            perm[0] = (int8_T)i3;
            perm[1] = (int8_T)ib;
            perm[2] = (int8_T)i2;
            perm[3] = (int8_T)i4;
          }
          else
          {
            perm[0] = (int8_T)i3;
            perm[1] = (int8_T)ib;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)i2;
          }
        }
        else
        {
          perm[0] = (int8_T)i3;
          perm[1] = (int8_T)i4;
          perm[2] = (int8_T)ib;
          perm[3] = (int8_T)i2;
        }
      }

      idx[i - 3] = (int32_T)idx4[perm[0] - 1];
      idx[i - 2] = (int32_T)idx4[perm[1] - 1];
      idx[i - 1] = (int32_T)idx4[perm[2] - 1];
      idx[i] = (int32_T)idx4[perm[3] - 1];
      x[i - 3] = x4[perm[0] - 1];
      x[i - 2] = x4[perm[1] - 1];
      x[i - 1] = x4[perm[2] - 1];
      x[i] = x4[perm[3] - 1];
      ib = -1;
    }
  }

  if ((ib + 1) > 0)
  {
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    switch (ib + 1)
    {
     case 1:
      perm[0] = 1;
      break;

     case 2:
      if (x4[0] <= x4[1])
      {
        perm[0] = 1;
        perm[1] = 2;
      }
      else
      {
        perm[0] = 2;
        perm[1] = 1;
      }
      break;

     default:
      if (x4[0] <= x4[1])
      {
        if (x4[1] <= x4[2])
        {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        }
        else if (x4[0] <= x4[2])
        {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        }
        else
        {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      }
      else if (x4[0] <= x4[2])
      {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      }
      else if (x4[1] <= x4[2])
      {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      }
      else
      {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }
      break;
    }

    for (i = 0; i <= ib; i++)
    {
      i2 = ((int32_T)perm[i]) - 1;
      i3 = (i - ib) + 19;
      idx[i3] = (int32_T)idx4[i2];
      x[i3] = x4[i2];
    }
  }

  (void)memset(&xwork[0], 0, 20U * (sizeof(real_T)));
  (void)memset(&iwork[0], 0, 20U * (sizeof(int32_T)));
  ib = 5;
  i = 4;
  while (ib > 1)
  {
    if ((((uint32_T)ib) & 1U) != 0U)
    {
      ib--;
      i2 = i * ib;
      if ((20 - i2) > i)
      {
        merge_Syul3li4(idx, x, i2, i, 20 - (i2 + i), iwork, xwork);
      }
    }

    i2 = i * 2;
    ib = asr_s32(ib, 1U);
    for (i3 = 0; i3 < ib; i3++)
    {
      merge_Syul3li4(idx, x, i3 * i2, i, i, iwork, xwork);
    }

    i = i2;
  }

  if (20 > i)
  {
    merge_Syul3li4(idx, x, 0, i, 20 - i, iwork, xwork);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
