#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/resource.h>
#include<stdlib.h>
#include <utime.h>

pthread_barrier_t barrier;
int *arr;
int arrSize;
int numThreads;
typedef struct thread_data {
    int threadId;
    int *a;
   int N;
} thread_data_t;

float CPUtime()
{ 	struct rusage rusage;
	getrusage(RUSAGE_SELF,&rusage);
	return rusage.ru_utime.tv_sec+rusage.ru_utime.tv_usec/1000000.0
	+ rusage.ru_stime.tv_sec+rusage.ru_stime.tv_usec/1000000.0;
}
float elapsedTime()
{ 
	return (10000.0*time(NULL))/CLOCKS_PER_SEC;
}
void *shellsort(void *arg)
{
	thread_data_t *threadWork=(thread_data_t*) arg;
	int *a;
	int N;
	int group;
	int i,j,h;
	int v;
	float startCPU,startTime;
	a=threadWork->a;
	N=threadWork->N;
	pthread_barrier_wait(&barrier);
	startCPU=CPUtime();
	startTime=elapsedTime();
for (h=1;h<=N/9; h=3*h+1) ;
for (;h>0; h /= 3)
{ 
	for (group=threadWork->threadId; group<h; group+=numThreads)

	for (i=group+h; i<N; i+=h)
	{ v=a[i];
	  j=i;
	  while (j>=h && a[j-h]>v)
	  { a[j]=a[j-h];
	    j -= h;
	  }
	 a[j]=v;
       }
  pthread_barrier_wait(&barrier);
}
printf("CPU used by thread %d is %f\n",threadWork->threadId,
CPUtime()-startCPU);
printf("Elapsed time for thread %d is %f\n",threadWork->threadId,
elapsedTime()-startTime);
pthread_barrier_wait(&barrier);
}
int main()
{
thread_data_t *threadWork;
pthread_t thread;
int i,status;
unsigned seed;
printf("enter number of threads:");
scanf("%d",&numThreads);
if (pthread_barrier_init (&barrier, NULL,numThreads))
printf("barrier_init problem\n");;
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
for (i=0;i<arrSize;i++)
arr[i]=random();
for (i=1;i<numThreads;i++)
{ threadWork=(thread_data_t*) malloc(sizeof(thread_data_t));
threadWork->threadId=i;
threadWork->a=arr;
threadWork->N=arrSize;
status = pthread_create (
&thread, NULL, shellsort, (void*) threadWork);
if (status != 0)
{ printf("failed to create thread\n");
exit(0);
}
}
threadWork=(thread_data_t*) malloc(sizeof(thread_data_t));
threadWork->threadId=0;
threadWork->a=arr;
threadWork->N=arrSize;
shellsort((void*) threadWork);
printf("Verifying sort . . .\n");
for (i=1;i<arrSize;i++)
if (arr[i-1]>arr[i])
break;
if (i<arrSize)
printf("sort failed\n");
else
printf("sort succeeded\n");

return 0;
}

