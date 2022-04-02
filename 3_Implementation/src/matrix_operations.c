/**
 * @file matrix_operations
 * @author VatsalShah
 * @brief operation function
 */
#include "matrix.h"



/**
 * @brief Frees memory
 * 
 * @param m 
 */
void release_matrix_memory(mat *m){
    free(m->matrix_1);
    free(m->matrix_2);
}

/**
 * @brief Allocate matrix memory
 * 
 * @param matrix 
 * @param n 
 */
void dynamic_alloc_mat(float **matrix,int n){
    matrix = (float **)calloc(n,sizeof(float));
    for(int i=0;i<n;i++){
        matrix[i] = (float *)calloc(n,sizeof(float));
    }
}



/**
 * @brief Allocate memory and input the elements
 * 
 * @param matrix 
 * @param n 
 * @return float** 
 */
float ** alloc_input_matrix(float **matrix,int n){
    int i,j;
    matrix = (float **)calloc(n,sizeof(float));
    for(i=0;i<n;i++){
        matrix[i] = (float *)calloc(n,sizeof(float));
    }

    float element;
    printf("Enter the matrix: \n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%f", &element);
            matrix[i][j]= element;
        }
    }
    return matrix;
}

/**
 * @brief A function to output the matrix
 * 
 * @param matrix 
 * @param n 
 */

void output_matrix(float **matrix,int n){
    int i,j;
    float x;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            //x = **(matrix + i*n + j);
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
}


float power(int exp){
    float result=1;
    while(exp != 0){
        result*=(-1);
        exp--;
    }
    return result;

}