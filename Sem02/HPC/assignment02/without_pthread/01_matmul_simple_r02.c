#include <stdio.h>

void matmul_simple(int matrixA, int matrixB, int mat1[][matrixB], int n1, int n2, int mat2[][n2]) {
	int x, i, j;
	int res[matrixA][n2];
	for (i = 0; i < matrixA; i++) {
		for (j = 0; j < n2; j++) {
			res[i][j] = 0;
			for (x = 0; x < matrixB; x++) {
				*(*(res + i) + j) += *(*(mat1 + i) + x)* *(*(mat2 + x) + j);
			}
		}
	}
	for (i = 0; i < matrixA; i++) {
		for (j = 0; j < n2; j++) {
			printf("%d ", *(*(res + i) + j));
		}
		printf("\n");
	}
}

int main() {
	int mat1[][3] = { { 2, 4, 7 }, { 3, 4, 4 }, {1, 5, 7} };
	int mat2[][3] = { { 1, 2, 1 }, { 1, 3, 2 }, {3, 6, 9} };
	int matrixA = 3, matrixB = 3, n1 = 3, n2 = 3;

	// Function call
	matmul_simple(matrixA, matrixB, mat1, n1, n2, mat2);
	return 0;
}
