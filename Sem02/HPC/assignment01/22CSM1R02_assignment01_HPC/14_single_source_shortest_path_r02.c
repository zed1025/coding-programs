#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <limits.h> 
#include <pthread.h> 

#define V 5 
#define THREAD_COUNT 4 

int graph[V][V] = 
	     {{0, 2, 0, 6, 0},
              {2, 0, 3, 8, 5},
              {0, 3, 0, 0, 7},
              {6, 8, 0, 0, 9},
              {0, 5, 7, 9, 0},
             };

int minDistance(int dist[], bool sptSet[]) 
{ 
   int min = INT_MAX, min_index; 
  
   for (int v = 0; v < V; v++) 
     if (sptSet[v] == false && dist[v] <= min) 
         min = dist[v], min_index = v; 
  
   return min_index; 
} 

void printSolution(int dist[], int n) 
{ 
   printf("Vertex Distance from Source\n"); 
   for (int i = 0; i < V; i++) 
      printf("%d tt %d\n", i, dist[i]); 
} 

void *dijkstra(void *threadid) 
{ 
   long tid; 
   tid = (long)threadid; 
   int part = V / THREAD_COUNT; 
   int start = tid * part; 
   int end = start + part; 
   int dist[V]; 
   bool sptSet[V]; 
  
   for (int i = start; i < end; i++) 
   { 
      dist[i] = INT_MAX; 
      sptSet[i] = false; 
   } 
  
   dist[0] = 0; 
  
   for (int count = 0; count < V-1; count++) 
   { 
      int u = minDistance(dist, sptSet); 
      sptSet[u] = true; 
      for (int v = 0; v < V; v++) 
        if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX  
                                       && dist[u]+graph[u][v] < dist[v]) 
          dist[v] = dist[u] + graph[u][v]; 
   } 
  
   printSolution(dist, V); 
   pthread_exit(NULL); 
} 

int main() 
{ 
   pthread_t threads[THREAD_COUNT]; 
   int rc; 
   long t; 
   for(t=0;t<THREAD_COUNT;t++) 
   { 
      rc = pthread_create(&threads[t], NULL, dijkstra, (void *)t); 
      if (rc) 
      { 
         printf("ERROR; return code from pthread_create() is %d\n", rc); 
         exit(-1); 
      } 
   } 
   pthread_exit(NULL); 
   return 0; 
} 

