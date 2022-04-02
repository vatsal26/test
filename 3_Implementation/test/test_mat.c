/**
 * @file test_main
 * @author VatsalShah
 * @brief test function
 */
#include "unity.h"
#include "matrix.h"


#define PROJECT_NAME    "Matrix Calculator"


/**
 * @brief Addition test
 * 
 */
void test_add_mat(void);

/**
 * @brief Subtraction test
 * 
 */
void test_sub_mat(void);

/**
 * @brief Multiplication test
 * 
 */
void test_mul_mat(void);

/**
 * @brief Determinat test
 * 
 */
void test_det_mat(void);

/**
 * @brief Inverse test
 * 
 */
void test_inv_mat(void);

/**
 * @brief Power test
 * 
 */
void test_pow(void);

/**
 * @brief Transpose test
 * 
 */
void test_transp_mat(void);


/* Basic structure for unity testing */
void setUp(){}

void tearDown(){}

/* Main for testing */
int main()
{
/* Start Unity testing */
  UNITY_BEGIN();

/* calling functions for testing */
  RUN_TEST(test_add_mat);
  RUN_TEST(test_sub_mat);
  RUN_TEST(test_mul_mat);
  RUN_TEST(test_pow);
  RUN_TEST(test_det_mat);
  RUN_TEST(test_inv_mat);
  RUN_TEST(test_transp_mat);


  /* End functions */
  return UNITY_END();
}

/* Test functions */ 
void test_add_mat(void) {

  float **test_mat1, **test_mat2;
  test_mat1 = (float **)calloc(2,sizeof(float));
  test_mat2 = (float **)calloc(2,sizeof(float));
    for(int i=0;i<2;i++){
        test_mat1[i] = (float *)calloc(2,sizeof(float));
        test_mat2[i] = (float *)calloc(2,sizeof(float));
    }

  test_mat1[0][0] = 1;
  test_mat1[0][1] = 1;
  test_mat1[1][0] = 1;
  test_mat1[1][1] = 1;

  test_mat2[0][0] = 5;
  test_mat2[0][1] = 6;
  test_mat2[1][0] = 7;
  test_mat2[1][1] = 8;

  TEST_ASSERT_EQUAL(SUCCESS,matrix_addition(test_mat1,test_mat2,2));


  free(test_mat1);
  free(test_mat2);

}

void test_sub_mat(void) {

  float **test_mat1, **test_mat2;
  test_mat1 = (float **)calloc(2,sizeof(float));
  test_mat2 = (float **)calloc(2,sizeof(float));
    for(int i=0;i<2;i++){
        test_mat1[i] = (float *)calloc(2,sizeof(float));
        test_mat2[i] = (float *)calloc(2,sizeof(float));
    }

  test_mat1[0][0] = 7;
  test_mat1[0][1] = 8;
  test_mat1[1][0] = 9;
  test_mat1[1][1] = 0;

  test_mat2[0][0] = 8;
  test_mat2[0][1] = 8;
  test_mat2[1][0] = 9;
  test_mat2[1][1] = 9;

  TEST_ASSERT_EQUAL(SUCCESS,matrix_subtraction(test_mat1,test_mat2,2));


  free(test_mat1);
  free(test_mat2);

}

void test_mul_mat(void){
    float **test_mat1, **test_mat2;
  test_mat1 = (float **)calloc(2,sizeof(float));
  test_mat2 = (float **)calloc(2,sizeof(float));
    for(int i=0;i<2;i++){
        test_mat1[i] = (float *)calloc(2,sizeof(float));
        test_mat2[i] = (float *)calloc(2,sizeof(float));
    }

  test_mat1[0][0] = 1;
  test_mat1[0][1] = 1;
  test_mat1[1][0] = 1;
  test_mat1[1][1] = 1;

  test_mat2[0][0] = 2;
  test_mat2[0][1] = 2;
  test_mat2[1][0] = 2;
  test_mat2[1][1] = 2;

  TEST_ASSERT_EQUAL(SUCCESS,matrix_multiplication(test_mat1,test_mat2,2));


  free(test_mat1);
  free(test_mat2);

}


void test_det_mat(void){
      
    float **test_mat1;
    test_mat1 = (float **)calloc(2,sizeof(float));
    for(int i=0;i<2;i++){
        test_mat1[i] = (float *)calloc(2,sizeof(float));
    }

  test_mat1[0][0] = 5;
  test_mat1[0][1] = 3;
  test_mat1[1][0] = 5;
  test_mat1[1][1] = 4;


  TEST_ASSERT_EQUAL(5.0000,matrix_determinant(test_mat1,2));


  free(test_mat1);


}

void test_inv_mat(void){
  float **test_mat1;
    test_mat1 = (float **)calloc(3,sizeof(float));
    for(int i=0;i<3;i++){
        test_mat1[i] = (float *)calloc(3,sizeof(float));
    }

  test_mat1[0][0] = 1;
  test_mat1[0][1] = 2;
  test_mat1[0][2] = 3;
  test_mat1[1][0] = 4;
  test_mat1[1][1] = 5;
  test_mat1[1][2] = 6;
  test_mat1[2][0] = 7;
  test_mat1[2][1] = 8;
  test_mat1[2][2] = 9;


  TEST_ASSERT_EQUAL(SUCCESS,matrix_inverse(test_mat1,3));

  free(test_mat1);

}

void test_pow(void){


  TEST_ASSERT_EQUAL(1,power(2));
  TEST_ASSERT_EQUAL(-1,power(3));

}

void test_transp_mat(void){
    float **test_mat1;
    test_mat1 = (float **)calloc(3,sizeof(float));
    for(int i=0;i<3;i++){
        test_mat1[i] = (float *)calloc(3,sizeof(float));
    }

  test_mat1[0][0] = 3;
  test_mat1[0][1] = 5;
  test_mat1[0][2] = 2;
  test_mat1[1][0] = 1;
  test_mat1[1][1] = 5;
  test_mat1[1][2] = 8;
  test_mat1[2][0] = 3;
  test_mat1[2][1] = 9;
  test_mat1[2][2] = 2;

TEST_ASSERT_EQUAL(SUCCESS,matrix_transpose(test_mat1,3));

free(test_mat1);

}