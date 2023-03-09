/**
 * ./a.out 8 8
 * 
 * 
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <pthread.h>

void fillMatrix(int N, double** A, double* b);
void partialPivot(int N, double** A, double* b, int currentPosition);
void printMatrix(int N, double** A, double* b);
void backSubstitution(int N, double** A, double* b, double* x, int numThreads);
void printSolutionVector(double* x, int N);
void checkAnswer(double** A, double* x, double* b, int N);
void *eliminate(void *threadarg);

struct Thread_Data {
	double** A;
	double* b;
	int N;
	int j;
	int numThreads;
} thread_data;

int main(int argc, char** argv){

	//--------------------Initialize Matrices, Vectors, and other Variables------------------//

	int N = atoi(argv[1]);
	int numThreads = atoi(argv[2]);
	struct timeval startTime, endElimination, endSubstitution;
	double eliminationTime, substitutionTime, totalTime;
	pthread_t elimination_threads[numThreads];

	// Ax = b

	//Allocate Matrix 'A'
	double **A = (double **)calloc(N,sizeof(double*));
	for (int q=0; q < N; q++)
		A[q] = (double*)calloc(N,sizeof(double*));

	//Allocate Vector 'b'
	double* b = (double*) malloc(sizeof(double)*N);
	double* x = (double*) malloc(sizeof(double)*N);

	fillMatrix(N, A, b); //Fill in matrix A and vector B with random floating points between 0 and 1000

	if (N <= 8)
	printf("\nPerforming gaussian elimination with the following matrix (A) and vector (b):\n\n");
	printMatrix(N, A, b);

	//Make sure that A, b, N, and the number of threads are all global and can be shared by the different threads.
	thread_data.A = A;
	thread_data.b = b;
	thread_data.N = N;
	thread_data.numThreads = numThreads;

	//Create an array that can be used to pass the thread_indices to the pthread function
	int *index = calloc (numThreads, sizeof (int));
	for(int i = 0; i < numThreads; i++)
    {
    	index[i] = i;
    }


    //--------------------Perform Gaussian Elimination and Back Substituion------------------//

	gettimeofday(&startTime, NULL);

	//Gaussian Elimination
	for (int j=0; j < N-1; j++){
		partialPivot(N, A, b, j);

		thread_data.j = j;

		for (int thread_index = 0; thread_index < numThreads; thread_index++){
			pthread_create(&elimination_threads[thread_index], NULL, eliminate, (void*)&index[thread_index]);
		}

		for (int thread_index = 0; thread_index < numThreads; thread_index++){
			pthread_join(elimination_threads[thread_index], NULL);
		}
	}

	gettimeofday(&endElimination, NULL); //Set execution time for elimination

	printf("\n-------Gaussian Elimination Complete-------\n");
	if (N <= 8){
		printf("\nPerforming back substitution with the following matrix (A) and vector (b):\n\n");
		printMatrix(N,A,b);
	}

	backSubstitution(N, A, b, x, numThreads);
	printf("\n--------Back Substitution Complete---------\n");

	gettimeofday(&endSubstitution, NULL); //Set execution time for substitution



	//---------------------------Calculate Run Times and print out Solutions---------------------------------//

	eliminationTime = ((endElimination.tv_sec  - startTime.tv_sec) * 1000000u + endElimination.tv_usec - startTime.tv_usec) / 1.e6;
	substitutionTime = ((endSubstitution.tv_sec  - endElimination.tv_sec) * 1000000u + endSubstitution.tv_usec - endElimination.tv_usec) / 1.e6;
	totalTime = ((endSubstitution.tv_sec  - startTime.tv_sec) * 1000000u + endSubstitution.tv_usec - startTime.tv_usec) / 1.e6;

	printSolutionVector(x, N);
	checkAnswer(A,x,b,N);

	printf("Substitution execution time: %.3f seconds.\n", eliminationTime);
	printf("Substitution execution time: %.3f seconds.\n", substitutionTime);
	printf("Total execution: \n%.3f seconds elapsed with %d threads used.\n\n", totalTime, numThreads);
}



void partialPivot(int n, double** a, double* b, int j){

	int   i,k,m,rowx;
	double xfac, temp, temp1, amax;

	amax = (double) fabs(a[j][j]) ;
    m = j;
    for (i=j+1; i<n; i++){   /* Find the row with largest pivot */
    	xfac = (double) fabs(a[i][j]);
    	if(xfac > amax) {amax = xfac; m=i;}
    }

    if(m != j) {  /* Row interchanges */
    	rowx = rowx+1;
    	temp1 = b[j];
    	b[j]  = b[m];
    	b[m]  = temp1;
    	for(k=j; k<n; k++) {
    		temp = a[j][k];
    		a[j][k] = a[m][k];
    		a[m][k] = temp;
    	}
    }
}

void *eliminate(void *threadarg){
	int *thread_index = (int*)threadarg;
	double** A = thread_data.A;
	double* b = thread_data.b;
	int N = thread_data.N;
	int j = thread_data.j;
	int numThreads = thread_data.numThreads;
	int i, k;
	double m;

	for (k=j+1+ *thread_index; k<N; k += numThreads){
		m = A[k][j]/A[j][j];
		for (i=j; i<N; i++){
			A[k][i] = A[k][i] - (m * A[j][i]);
		}
		b[k] = b[k] - (m * b[j]);
	}
}

void fillMatrix(int N, double** A, double* b){
	int i, j;
	for (i=0; i<N; i++){
		for (j=0; j<N; j++){
			A[i][j] = (drand48()*1000);
		}
		b[i] = (drand48()*1000);
	}
}

void printMatrix(int N, double** A, double* b){
	if (N <= 8){
		for (int x=0; x<N; x++){
			printf("| ");
			for(int y=0; y<N; y++)
				printf("%7.2f ", A[x][y]);
			printf("| | %7.2f |\n", b[x]);
		}
	}
	else{
		printf("\nPerforming gaussian elimination with a matrix and vector too large to print out.\n");
		printf("If you would like to see output, try again with a matrix of length 8 or less.\n");
	}
}

void printSolutionVector(double* x, int N){
	if (N <= 8){
		printf("\nSolution Vector (x):\n\n");
		for (int i=0; i<N; i++){
			printf("|%10.6f|\n", x[i]);
		}
	}
}

void backSubstitution(int N, double** A, double* b, double* x, int numThreads){
	int i,j;
	for (i=N-1; i >= 0; i--){
		x[i] = b[i];
		for (j=i+1; j<N; j++){
			x[i] -= A[i][j]*x[j];
		}
		x[i] = x[i] / A[i][i];
	}
}

void checkAnswer(double** A, double* x, double* b, int N){

	double* result_vector = (double*) malloc(sizeof(double)*N);
	double row_sum; 

	for (int j=0; j<N; j++){
		row_sum = 0;
		for (int k=0; k<N; k++){
			row_sum += A[j][k]*x[k];
		}
		result_vector[j] = row_sum;
	}

	double sumOfSquares = 0;
	double entryOfResidual;
	for (int i=0; i<N; i++){
		entryOfResidual = result_vector[i] - b[i];
		sumOfSquares += entryOfResidual*entryOfResidual;
	}
	//sumOfSquares = sqrt(sumOfSquares);
        double temp,sqrt;
 
    sqrt = sumOfSquares/2;
    temp =0;
  while(sqrt!=temp){
temp = sqrt;

sqrt = (sumOfSquares/temp+temp)/2;

}
 	

printf("\nThe L2-Norm of the result vector from Ax-b is: %.20f\n", sqrt);
}

