/**
 * @file matrix_inverse
 * @author VatsalShah
 * @brief invese function
 */
#include "matrix.h"
error_t matrix_inverse(float **num, int f)
{
 float **matb, **fac,**transp, **invers, d;

    int mem;
    matb = (float **)calloc(f,sizeof(float));
    fac = (float **)calloc(f,sizeof(float));
    transp = (float **)calloc(f,sizeof(float));
    invers = (float **)calloc(f,sizeof(float));
    for(int mem=0;mem<f;mem++){
        matb[mem] = (float *)calloc(f,sizeof(float));
        fac[mem] = (float *)calloc(f,sizeof(float));
        transp[mem] = (float *)calloc(f,sizeof(float));
        invers[mem] = (float *)calloc(f,sizeof(float));
    }


 int p, q, m, n, i, j;
 for (q = 0;q < f; q++)
 {
   for (p = 0;p < f; p++)
    {
     m = 0;
     n = 0;
     for (i = 0;i < f; i++)
     {
       for (j = 0;j < f; j++)
        {
          if (i != q && j != p)
          {
            matb[m][n] = num[i][j];
            if (n < (f - 2))
             n++;
            else
             {
               n = 0;
               m++;
               }
            }
        }
      }
      fac[q][p] = power(q + p) * matrix_determinant(matb, f - 1);
    }
  }

  d = matrix_determinant(num, f);
    for (i = 0;i < f; i++)
    {
     for (j = 0;j < f; j++)
       {
         transp[i][j] = fac[j][i];
        }
    }

  for (i = 0;i < f; i++)
    {
     for (j = 0;j < f; j++)
       {
        invers[i][j] = transp[i][j] / d;
        }
    }
    printf("Inverse is :\n");
    output_matrix(invers,f);
  free(matb);
  free(fac);
  free(transp);
  free(invers);
  return SUCCESS;
}