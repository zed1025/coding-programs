
#include <stdio.h>
#include<pthread.h>
#define N 2

#define MAX 6 //max number of threads

void shift_left(int matrix[][2], int i, int count) {
    int ind = 0;
    while (ind < count) {
        int temp = matrix[i][0];
        int indl = N - 1;
        for (int j = 0; j < indl; j++)
            matrix[i][j] = matrix[i][j + 1];
        matrix[i][indl] = temp;
        ind++;
    }
}
 void shift_up(int matrix[][2], int j, int count) {
    int ind = 0;
    while (ind < count)
    {
        int temp = matrix[0][j];
        int indl = N - 1;
        for (int i = 0; i < indl; i++)
            matrix[i][j] = matrix[i + 1][j];
        matrix[indl][j] = temp;
        ind++;
    }
}

void matmul_cannon(int A[][2], int B[][2]) {   
    pthread_t t[MAX];
    int i,j,k;
    int C[N][N];
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            C[i][j] = 0;
    for (int i = 0; i < N; i++){
        shift_left(A, i, i);
    }

    for (int i = 0; i < N; i++) {
        shift_up(B, i, i);
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int m = (i + j + k) % N;
                C[i][j] += A[i][m] * B[m][j];
                shift_left(A, i, 1);
                shift_up(B, j, 1);
            }
        }
    };

    printf("\nMatrix Multiplication : \n");
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }

}

int main(void) {
    int matA[][2]={{1,2},{3,4}};
    int matB[][2]={{5,6},{7,8}};
    printf("Matrix A: \n");
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            printf("%d ", matA[i][j]);
        }printf("\n");
    }
    printf("Matrix B: \n");
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            printf("%d ", matB[i][j]);
        }printf("\n");
    }
    matmul_cannon(matA,matB);
	return 0;
}

