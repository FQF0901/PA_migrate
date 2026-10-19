/*
 * File: qrpf_lcXs6Mkx.c
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
#include "xnrm2_kxtWlFk9.h"
#include "qrpf_lcXs6Mkx.h"

/* Function for MATLAB Function: '<Root>/ADCS9PlotFitCalc' */
void qrpf_lcXs6Mkx(real32_T A[16], int32_T ia0, int32_T m, int32_T n, real32_T
                   tau[4], int32_T jpvt[4])
{
  int32_T b_j;
  int32_T c_ix;
  int32_T e;
  int32_T exitg1;
  int32_T ia;
  int32_T ii;
  int32_T ix;
  int32_T iy;
  int32_T k;
  int32_T minmn;
  int32_T mmi;
  int32_T nmi;
  int32_T pvt;
  real32_T vn1[4];
  real32_T vn2[4];
  real32_T work[4];
  real32_T beta1;
  real32_T smax;
  boolean_T exitg2;
  if (m < n)
  {
    minmn = m;
  }
  else
  {
    minmn = n;
  }

  work[0] = 0.0F;
  vn1[0] = 0.0F;
  vn2[0] = 0.0F;
  work[1] = 0.0F;
  vn1[1] = 0.0F;
  vn2[1] = 0.0F;
  work[2] = 0.0F;
  vn1[2] = 0.0F;
  vn2[2] = 0.0F;
  work[3] = 0.0F;
  vn1[3] = 0.0F;
  vn2[3] = 0.0F;
  for (b_j = 0; b_j < n; b_j++)
  {
    vn1[b_j] = xnrm2_kxtWlFk9(m, A, (b_j * 4) + ia0);
    vn2[b_j] = vn1[b_j];
  }

  for (b_j = 0; b_j < minmn; b_j++)
  {
    iy = (b_j * 4) + ia0;
    ii = (iy + b_j) - 1;
    nmi = n - b_j;
    mmi = m - b_j;
    if (nmi < 1)
    {
      pvt = -1;
    }
    else
    {
      pvt = 0;
      if (nmi > 1)
      {
        ix = b_j;
        smax = fabsf(vn1[b_j]);
        for (k = 2; k <= nmi; k++)
        {
          ix++;
          beta1 = fabsf(vn1[ix]);
          if (beta1 > smax)
          {
            pvt = k - 1;
            smax = beta1;
          }
        }
      }
    }

    pvt += b_j;
    if ((pvt + 1) != (b_j + 1))
    {
      ix = ((pvt * 4) + ia0) - 1;
      iy--;
      for (k = 0; k < m; k++)
      {
        smax = A[ix];
        A[ix] = A[iy];
        A[iy] = smax;
        ix++;
        iy++;
      }

      iy = jpvt[pvt];
      jpvt[pvt] = jpvt[b_j];
      jpvt[b_j] = iy;
      vn1[pvt] = vn1[b_j];
      vn2[pvt] = vn2[b_j];
    }

    if ((b_j + 1) < m)
    {
      smax = A[ii];
      tau[b_j] = 0.0F;
      if (mmi > 0)
      {
        beta1 = xnrm2_kxtWlFk9(mmi - 1, A, ii + 2);
        if (beta1 != 0.0F)
        {
          beta1 = rt_hypotf(A[ii], beta1);
          if (A[ii] >= 0.0F)
          {
            beta1 = -beta1;
          }

          if (fabsf(beta1) < 9.86076132E-32F)
          {
            iy = -1;
            pvt = ii + mmi;
            do
            {
              iy++;
              for (ix = ii + 1; ix < pvt; ix++)
              {
                A[ix] *= 1.01412048E+31F;
              }

              beta1 *= 1.01412048E+31F;
              smax *= 1.01412048E+31F;
            }
            while (fabsf(beta1) < 9.86076132E-32F);

            beta1 = rt_hypotf(smax, xnrm2_kxtWlFk9(mmi - 1, A, ii + 2));
            if (smax >= 0.0F)
            {
              beta1 = -beta1;
            }

            tau[b_j] = (beta1 - smax) / beta1;
            smax = 1.0F / (smax - beta1);
            for (ix = ii + 1; ix < pvt; ix++)
            {
              A[ix] *= smax;
            }

            for (pvt = 0; pvt <= iy; pvt++)
            {
              beta1 *= 9.86076132E-32F;
            }

            smax = beta1;
          }
          else
          {
            tau[b_j] = (beta1 - A[ii]) / beta1;
            smax = 1.0F / (A[ii] - beta1);
            iy = ii + mmi;
            for (pvt = ii + 1; pvt < iy; pvt++)
            {
              A[pvt] *= smax;
            }

            smax = beta1;
          }
        }
      }

      A[ii] = smax;
    }
    else
    {
      tau[b_j] = 0.0F;
    }

    if ((b_j + 1) < n)
    {
      smax = A[ii];
      A[ii] = 1.0F;
      if (tau[b_j] != 0.0F)
      {
        iy = mmi - 1;
        pvt = (ii + mmi) - 1;
        while (((iy + 1) > 0) && (A[pvt] == 0.0F))
        {
          iy--;
          pvt--;
        }

        nmi -= 2;
        exitg2 = false;
        while ((!exitg2) && ((nmi + 1) > 0))
        {
          pvt = ((nmi * 4) + ii) + 5;
          ix = pvt;
          do
          {
            exitg1 = 0;
            if (ix <= (pvt + iy))
            {
              if (A[ix - 1] != 0.0F)
              {
                exitg1 = 1;
              }
              else
              {
                ix++;
              }
            }
            else
            {
              nmi--;
              exitg1 = 2;
            }
          }
          while (exitg1 == 0);

          if (exitg1 == 1)
          {
            exitg2 = true;
          }
        }
      }
      else
      {
        iy = -1;
        nmi = -1;
      }

      if ((iy + 1) > 0)
      {
        if ((nmi + 1) != 0)
        {
          for (pvt = 0; pvt <= nmi; pvt++)
          {
            work[pvt] = 0.0F;
          }

          pvt = 0;
          ix = ((nmi * 4) + ii) + 5;
          for (k = ii + 5; k <= ix; k += 4)
          {
            c_ix = ii;
            beta1 = 0.0F;
            e = k + iy;
            for (ia = k; ia <= e; ia++)
            {
              beta1 += A[ia - 1] * A[c_ix];
              c_ix++;
            }

            work[pvt] += beta1;
            pvt++;
          }
        }

        if ((-tau[b_j]) != 0.0F)
        {
          pvt = ii + 4;
          ix = 0;
          for (k = 0; k <= nmi; k++)
          {
            if (work[ix] != 0.0F)
            {
              beta1 = work[ix] * (-tau[b_j]);
              c_ix = ii;
              e = iy + pvt;
              for (ia = pvt; ia < (e + 1); ia++)
              {
                A[ia] += A[c_ix] * beta1;
                c_ix++;
              }
            }

            ix++;
            pvt += 4;
          }
        }
      }

      A[ii] = smax;
    }

    for (ii = b_j + 1; ii < n; ii++)
    {
      nmi = (ia0 + b_j) + (ii * 4);
      if (vn1[ii] != 0.0F)
      {
        smax = fabsf(A[nmi - 1]) / vn1[ii];
        smax = 1.0F - (smax * smax);
        if (smax < 0.0F)
        {
          smax = 0.0F;
        }

        beta1 = vn1[ii] / vn2[ii];
        beta1 = (beta1 * beta1) * smax;
        if (beta1 <= 0.000345266977F)
        {
          if ((b_j + 1) < m)
          {
            vn1[ii] = xnrm2_kxtWlFk9(mmi - 1, A, nmi + 1);
            vn2[ii] = vn1[ii];
          }
          else
          {
            vn1[ii] = 0.0F;
            vn2[ii] = 0.0F;
          }
        }
        else
        {
          vn1[ii] *= sqrtf(smax);
        }
      }
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
