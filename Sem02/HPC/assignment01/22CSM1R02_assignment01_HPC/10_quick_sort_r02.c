#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <pthread.h>
#include<stdlib.h>
pthread_barrier_t barrier;
int numThreads;
typedef struct thread_data {
int threadId;
} thread_data_t;
float CPUtime()
{ struct rusage rusage;
getrusage(RUSAGE_SELF,&rusage);
return rusage.ru_utime.tv_sec+rusage.ru_utime.tv_usec/1000000.0
+ rusage.ru_stime.tv_sec+rusage.ru_stime.tv_usec/1000000.0;
}
float elapsedTime()
{ return (10000.0*time(NULL))/CLOCKS_PER_SEC;
}
int *arr;
int arrSize;
int zeroActive=1,partitionAvailable=0,leftEnd,rightEnd;
int maxThreshold;
int partition(arr,p,r)
int *arr,p,r;
{
int x,i,j,temp;
/*
printf("Input\n");
for (i=p;i<=r;i++)
printf("%d %d\n",i,arr[i]);
19
*/
x=arr[p];
i=p-1;
j=r+1;
while (1)
{ while (arr[--j]>x);
while (arr[++i]<x);
if (i<j)
{ temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
else
{
/* printf("Left output\n");
for (i=p;i<=j;i++)
printf("%d %d\n",i,arr[i]);
printf("Right output\n");
for (i=j+1;i<=r;i++)
printf("%d %d\n",i,arr[i]);
*/ return j;
}
}
}
void quickSort(int *a,int p,int r)
{
int q;
if (p<r)
{ q=partition(a,p,r);
quickSort(a,p,q);
quickSort(a,q+1,r);
}
}
void quickSort2(int *a,int p,int r)
{
int q,k;
if (p<r)
{ q=partition(a,p,r);
k=r-p+1;
if (partitionAvailable || k>maxThreshold)
quickSort2(a,p,q);
else
{ leftEnd=p;
rightEnd=q;
partitionAvailable=1;
}
k=r-q;
if (partitionAvailable || k>maxThreshold)
quickSort2(a,q+1,r);
else
{ leftEnd=q+1;
rightEnd=r;
partitionAvailable=1;
}
}
}
void *quickSort0(void *arg)
{
thread_data_t *threadWork=(thread_data_t*) arg;
float startCPU,startTime;
pthread_barrier_wait(&barrier);
startCPU=CPUtime();
startTime=elapsedTime();
quickSort2(arr,0,arrSize-1);
zeroActive=0;
pthread_barrier_wait(&barrier);
printf("CPU used by thread 0 is %f\n",CPUtime()-startCPU);
printf("Elapsed time for thread 0 is %f\n",elapsedTime()-startTime);
pthread_barrier_wait(&barrier);
}
void *quickSort1(void *arg)
{
thread_data_t *threadWork=(thread_data_t*) arg;
float startCPU,startTime;
pthread_barrier_wait(&barrier);
startCPU=CPUtime();
startTime=elapsedTime();
while (zeroActive || partitionAvailable)
if (partitionAvailable)
{ quickSort(arr,leftEnd,rightEnd);
partitionAvailable=0;
}
pthread_barrier_wait(&barrier);
printf("CPU used by thread 1 is %f\n",CPUtime()-startCPU);
printf("Elapsed time for thread 1 is %f\n",elapsedTime()-startTime);
pthread_barrier_wait(&barrier);
}
int main()
{
int i;
unsigned seed;
thread_data_t *threadWork;
pthread_t thread;
int status;
printf("enter number of keys\n");
scanf("%d",&arrSize);
arr=(int*) malloc(sizeof(int)*arrSize);
if (!arr)
{ printf("malloc failed\n");
abort();
}
printf("enter seed\n");
scanf("%u",&seed);
srandom(seed);
srandom(seed);
for (i=0;i<arrSize;i++)
arr[i]=random();
numThreads=2;
zeroActive=1;
if (pthread_barrier_init (&barrier, NULL,numThreads))
printf("barrier_init problem\n");
threadWork=(thread_data_t*) malloc(sizeof(thread_data_t));
threadWork->threadId=1;
status = pthread_create (
&thread, NULL, quickSort1, (void*) threadWork);
if (status != 0)
{ printf("failed to create thread\n");
exit(0);
}
threadWork=(thread_data_t*) malloc(sizeof(thread_data_t));
threadWork->threadId=0;
maxThreshold=arrSize/4;
quickSort0((void*) threadWork);
}

