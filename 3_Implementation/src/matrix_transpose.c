/**
 * @file matrix_transpose
 * @author VatsalShah
 * @brief transpose function
 */
#include "matrix.h"

error_t matrix_transpose(float **matrix,int n){
    float **result;
    int i,j;
    result = (float **)calloc(n,sizeof(float));
    for(int i=0;i<n;i++){
        result[i] = (float *)calloc(n,sizeof(float));
    }
    for (i = 0;i < n; i++)
    {
     for (j = 0;j < n; j++)
       {
         result[i][j] = matrix[j][i];
        }
    }

    printf("The Transpose of the matrix is: \n");
    output_matrix(result,n);
    free(result);
    return SUCCESS;
    
}