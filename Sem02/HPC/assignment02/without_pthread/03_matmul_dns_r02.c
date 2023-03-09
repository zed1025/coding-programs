#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<unistd.h>

int N,M,L,max_threads; 
  
int a[] = { {2, 1, 4, 9}, {5, 3, 6, 10} ,{2, 1, 5,10},{15,9,11,13}}; 
int b[] = { {2, 1, 4, 9}, {5, 3, 6, 10} ,{2, 1, 5,10},{15,9,11,13}}; 

void printArray(int *c)  { 
    int i, j; 
    for (i = 0; i < N; i++) 
        for (j = 0; j < M; j++) 
            printf("%d ",c[i][j]);
    printf("\n");
} 

struct iter_arg{
    int *a,*b;
    int l,m,k;
};

void* matMulti(void* arg) {
    struct iter_arg *marg=(struct iter_arg *)arg;
    int i = *marg.l, j = *marg.m, k = *marg.k;
    c[i][k]=(*marg).a[i][k] * (*marg).b[k][j];

    return arg;
}


  
int main()  { 
    // int arr[] = {12, 34, 54, 2, 3}, i; 
    // int n = sizeof(arr)/sizeof(arr[0]); 
    N = sizeof(a)/sizeof(a[0]); 
    M=sizeof(a[0])/sizeof(a[0][0]);
    L=sizeof(b[0])/sizeof(b[0][0]);
    max_threads=N*M*L;
    pthread_t threads[max_threads]; 
    struct iter_arg iarg[max_threads];
    
    printf("Array :");
    printArray(a); 
  
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<N;k++){
                iarg[i*N+j*M+k].a=a;
                iarg[i*N+j*M+k].b=b;
                iarg[i*N+j*M+k].l=i;
                iarg[i*N+j*M+k].m=j;
                iarg[i*N+j*M+k].k=k;
                pthread_create(&threads[i*N+j*M+k],NULL,matMulti,(void *)iarg[i*N+j*M+k]);
            }
        }
    }
  
    printf("\nSorted array is: ");
    printArray(a); 
  
    return 0; 
} 