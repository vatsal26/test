/**
 * @file matrix_multiplication
 * @author VatsalShah
 * @brief Multiplication function
 */
#include "matrix.h"
error_t matrix_multiplication(float **matrix1,float **matrix2, int n){
    int i,j,k;
    float **result;
    result = (float **)calloc(n,sizeof(float));
    for(int i=0;i<n;i++){
        result[i] = (float *)calloc(n,sizeof(float));
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            result[i][j] = 0;
            for(k = 0;k < n; k++){
            result[i][j]+= matrix1[i][k] * matrix2[k][j];
            }
    }
    }

    printf("The product of the matrices is: \n");
    output_matrix(result,n);
    free(result);
    return SUCCESS;
}