/**
 * @file matrix_addition
 * @author VatsalShah
 * @brief addition function
 */
#include "matrix.h"
error_t matrix_addition(float **matrix1,float **matrix2, int n){
    int i,j;
    float **result;

    result = (float **)calloc(n,sizeof(float));
    for(int i=0;i<n;i++){
        result[i] = (float *)calloc(n,sizeof(float));
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("The sum of the matrices is: \n");
    output_matrix(result,n);
    free(result);
    return SUCCESS;

}