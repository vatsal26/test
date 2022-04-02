/**
 * @file main.c
 * @author VatsalShah
 * @brief  main file
 */
#include "matrix.h"

/* Valid and NotValid defination*/
#define VALID   (1)
#define NOTVALID (0)

/* User requested function call*/
unsigned int operation = 0;

int n;
mat operands;
error_t err;


/* Available function */
enum opers{ADDITION=1,SUBTRACTION,MULTIPLICATION,TRANSPOSE,DETERMINANT,INVERSE,EXIT};

/* Available choices */
void choices(void);
/* Option selected by user is valid or not */
int oper_valid(int oper);


/**
 * @brief Main function
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[])
{
    while(1)
    {
        choices();
    }
}

/**
 * @brief Display available choices
 * 
 */
void choices(void)
{
    printf("\n\tEnter your choice\n");
    printf("\n1.ADDITION");
    printf("\n2.SUBTRACTION");
    printf("\n3.MULTIPLICATE");
    printf("\n4.TRANSPOSE");
    printf("\n5.DETERMINANT");
    printf("\n6.INVERSE");
    printf("\n7.EXIT\n");
    
   
     fflush(stdin);
    scanf("%d", &operation);

    if(EXIT == operation)
    {
        printf("\nSee You \n");
        exit(0);
    }

    if(NOTVALID != oper_valid(operation))
    {
        printf("\n\tEnter elements of matrix with space in between them ");

        printf("\nOrder of matrix: ");
        scanf("%d", &n);
        operands.matrix_1 = alloc_input_matrix(operands.matrix_1,n);
        if(((operation != DETERMINANT )&&(operation != TRANSPOSE )&&(operation != INVERSE))){
            operands.matrix_2 = alloc_input_matrix(operands.matrix_2,n);
        }
    }
    else
    {
        printf("\nWRONG INPUT\n");
        return;
        
    }
    switch(operation)
    {
        
        case ADDITION:
            err = matrix_addition(operands.matrix_1,operands.matrix_2,n);
            release_matrix_memory(&operands);
            break;
        case SUBTRACTION:
            err = matrix_subtraction(operands.matrix_1,operands.matrix_2,n);
            release_matrix_memory(&operands);
            break;
        case MULTIPLICATION:
            err = matrix_multiplication(operands.matrix_1,operands.matrix_2,n);
            release_matrix_memory(&operands);
            break;
        case TRANSPOSE:
            err = matrix_transpose(operands.matrix_1,n);
            release_matrix_memory(&operands);
            break;
        case DETERMINANT:
            operands.result = matrix_determinant(operands.matrix_1,n);
            printf("Determinant of the matrix is: %f \n\n\n",operands.result);
            break;
        case INVERSE:
            if(matrix_determinant(operands.matrix_1,n) == 0.00){
                printf("Inverse of this matrix is not possible because matrix_determinant of this matrix is zero \n");
            }
            else{
                err = matrix_inverse(operands.matrix_1,n);
                release_matrix_memory(&operands);
            }
            break;
        case EXIT:
            release_matrix_memory(&operands);
            exit(0);
            break;
    }
}

/**
 * @brief function to check choice is in limit or not
 * 
 * @param oper 
 * @return int 
 */
int oper_valid(int oper)
{
    return ((ADDITION <= oper) && (EXIT >= oper)) ? VALID: NOTVALID;
}