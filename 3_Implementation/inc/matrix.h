/**
 * @file matrix.h
 * @author VatsalShah
 * @brief header file for main function 
 */
#ifndef __MATRIX_OPERATIONS_H__
#define __MATRIX_OPERATIONS_H__

#include <stdio.h>
#include <stdlib.h>


/**
 * @brief Enum test case success or failure
 * 
 */
typedef enum{SUCCESS=1,FAILURE=0}error_t;

/**
 * @brief structure for matrix elements
 * 
 */
typedef struct{

float **matrix_1;
float **matrix_2;
float result;

}mat;

/**
 * @brief Dynamically allocate memory for input matrix 
 * 
 * @param matrix 
 * @param n 
 * @return float**
 */
float ** alloc_input_matrix(float **matrix, int n);

/**
 * @brief Dynamically allocate memory for matrix
 * 
 * @param matrix 
 * @param n 
 */
void dynamic_alloc_mat(float **matrix,int n);

/**
 * @brief Display matrix
 * 
 * @param matrix 
 * @param n 
 */
void output_matrix(float **matrix,int n);

/**
 * @brief Free the space of dynamically allocated matrix
 * 
 * @param m 
 */
void release_matrix_memory(mat *m);

/**
 * @brief For addition
 * 
 * @param matrix1 
 * @param matrix2 
 * @param n 
 * @return error_t 
 */
error_t matrix_addition(float **matrix1,float **matrix2,int n);

/**
 * @brief For difference
 * 
 * @param matrix1 
 * @param matrix2 
 * @param n 
 * @return error_t 
 */
error_t matrix_subtraction(float **matrix1,float **matrix2, int n);
/**
 * @brief For product
 * 
 * @param matrix1 
 * @param matrix2 
 * @param n 
 * @return error_t
 */
error_t matrix_multiplication(float **matrix1,float **matrix2, int n);
/**
 * @brief For deteminant
 * 
 * @param matrix 
 * @return float 
 */
float matrix_determinant(float **matrix,int k);

/**
 * @brief For transpose
 * 
 * @param matrix 
 * @param n 
 * @return error_t
 */
error_t matrix_transpose(float **matrix,int n);

/**
 * @brief For inverse
 * 
 * @param num 
 * @param f 
 * @return error_t 
 */
error_t matrix_inverse(float **num, int f);

/**
 * @brief For power
 * 
 * @param exp 
 * @return float 
 */
float power(int exp);
 



#endif