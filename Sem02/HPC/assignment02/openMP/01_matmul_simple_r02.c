/*
************************************************************************************
    NITW-MTech CSE
    Name: 			Amit Kumar
    Roll No: 		22CSM1R02
    Subject: 		HPC
    Description: 	Simple Matrix Multiplication using OpenMP
    Notes:          - For generating random matrices
                        https://onlinemathtools.com/generate-random-matrix
                    - Running the program
                        gcc 01_matmul_simple_r02.c -fopenmp
                        ./a.out
************************************************************************************
*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<math.h>
//Extra libraries
#include<omp.h>
#include<time.h>


//utility function to print a matrix
void printMatrix(int n1, int n2, int mat[][n2]) {
    for(int i=0; i<n1; i++) {
        for(int j=0; j<n2; j++) {
            printf("%d\t", mat[i][j]);
        } printf("\n");
    } printf("\n");
}

//matrix multiplication using OpenMP
void matrixMultiplication(int n1, int n2, int matA[][n2], int n3, int n4, int matB[][n4]) {
    // printf("Entered Matrices: \n");
    // printMatrix(n1, n2, matA);
    // printMatrix(n3, n4, matB);

    int matC[n1][n4];
    int temp;

    #pragma omp parallel for
    {
    // int num_threads = omp_get_num_threads();
    // printf("Executing with %d threads.\n", num_threads);
    // #pragma omp for
    for(int i=0; i<n1; i++) {
        #pragma omp parallel for
        for(int j=0; j<n4; j++) {
            matC[i][j]=0;
            temp=0;
            #pragma omp parallel for
            for(int k=0; k<n2; k++) {
                temp += matA[i][k] * matB[k][j];
            }
            matC[i][j] = temp;
        }
    }
    }

    // printf("Resultant Matrix: \n");
    // printMatrix(n1, n4, matC);
}

//matrix multiplication without OpenMP
void matrixMultiplicationNoMP(int n1, int n2, int matA[][n2], int n3, int n4, int matB[][n4]) {
    // printf("Entered Matrices: \n");
    // printMatrix(n1, n2, matA);
    // printMatrix(n3, n4, matB);

    int matC[n1][n4];
    int temp;

    for(int i=0; i<n1; i++) {
        for(int j=0; j<n4; j++) {
            matC[i][j]=0;
            temp=0;
            for(int k=0; k<n2; k++) {
                temp += matA[i][k] * matB[k][j];
            }
            matC[i][j] = temp;
        }
    }

    // printf("Resultant Matrix: \n");
    // printMatrix(n1, n4, matC);
}

int main(int argc, char* argv[]){
    int n1, n2, n3, n4;
    printf("Enter matrix A dimension(a b): ");
    scanf("%d %d", &n1, &n2);
    printf("Enter matrix B dimension(a b): ");
    scanf("%d %d", &n3, &n4);
    if(n2 != n3) {
        printf("Incompatible matrices!");
        exit(0);
    }
    int matA[n1][n2];
    int matB[n3][n4];
    printf("Enter matrix A: ");
    for(int i=0; i<n1; i++) {
        for(int j=0; j<n2; j++) {
            scanf("%d", &matA[i][j]);
        }
    }
    printf("Enter matrix B: ");
    for(int i=0; i<n1; i++) {
        for(int j=0; j<n2; j++) {
            scanf("%d", &matB[i][j]);
        }
    }

    clock_t start1, end1;
    double cpu_time_used1;

    //Non-Parallel Execution
    start1 = clock();
    matrixMultiplicationNoMP(n1, n2, matA, n3, n4, matB);
    end1 = clock();
    cpu_time_used1 = ((double) (end1 - start1)) / CLOCKS_PER_SEC;
    printf("CPU Time Used for Non-Parallel execution: %f\n", cpu_time_used1);


    clock_t start2, end2;
    double cpu_time_used2;

    //Parallel Execution
    start2 = clock();
    matrixMultiplication(n1, n2, matA, n3, n4, matB);
    end2= clock();
    cpu_time_used2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC;
    printf("CPU Time Used for Parallel execution: %f\n", cpu_time_used2);
    double difference = cpu_time_used1-cpu_time_used2;
    printf("Difference: %0.6f\n", difference);

    return 0;
}

/*
    Outputs -> tested on 100x100 matric multiplication
    - without any schedule
        CPU Time Used for Non-Parallel execution: 0.001505
        CPU Time Used for Parallel execution: 0.001421
    - using schedule(strict)
        CPU Time Used for Non-Parallel execution: 0.001781
        CPU Time Used for Parallel execution: 0.001799
    - using schedule(dynamic)
        CPU Time Used for Non-Parallel execution: 0.001816
        CPU Time Used for Parallel execution: 0.001813
    - using schedule(guided)
        CPU Time Used for Non-Parallel execution: 0.003235
        CPU Time Used for Parallel execution: 0.005509
    - using schedule(runtime)
        CPU Time Used for Non-Parallel execution: 0.001828
        CPU Time Used for Parallel execution: 0.001767  
*/