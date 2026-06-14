/* 
  Simple Pthread Program to find the sum of a vector.
  Uses mutex locks to update the global sum. 
  Author: Purushotham Bangalore
  Date: Jan 25, 2009

  To Compile: gcc -O -Wall pthread_psum.c -lpthread
  To Run: ./a.out 1000 4
*/

// https://www.geeksforgeeks.org/thread-functions-in-c-c/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THREADS 100
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;


struct ThreadVariables {
    double *a;
    double sum;
    int N;
    int size;
    long int tid;
};

void *compute(void *arg) {
    struct ThreadVariables *threadVar = (struct ThreadVariables *)arg;
    int myStart, myEnd, myN, i;
    long tid = threadVar->tid;
    double *a = threadVar -> a;


    myN = threadVar->N / threadVar->size;
    myStart = tid * myN;
    myEnd = myStart + myN;
    if (tid == (threadVar->size - 1)) myEnd = threadVar->N;

    double mysum = 0.0;
    for (i = myStart; i < myEnd; i++)
        mysum += a[i];

    // Acquire the mutex lock before updating the shared variable
    pthread_mutex_lock(&mutex);
    threadVar->sum += mysum;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(int argc, char **argv) {

    if (argc != 3) {
        printf("Usage: %s <# of elements> <# of threads>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int N = atoi(argv[1]);
    int size = atoi(argv[2]);

    pthread_t total_threads[MAX_THREADS];
    struct ThreadVariables threadVariables[MAX_THREADS];
    double *a = (double *)malloc(sizeof(double) * N);

    if (a == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < N; i++)
        a[i] = (double)(i + 1);

    int rem = N % size;
    int eachThreadSize = N / size;

    for (int i = 0; i < size; i++) {
        threadVariables[i].tid = i;
        threadVariables[i].N = N;
        threadVariables[i].size = size; 
        threadVariables[i].a = a;
        threadVariables[i].sum = 0;

        
        pthread_create(&total_threads[i], NULL, compute, (void *)&threadVariables[i]);
    }

    for (int i = 0; i < size; i++)
        pthread_join(total_threads[i], NULL);

    double total_sum = 0;
    for (int i = 0; i < size; i++){
    //   printf("threadVar sum = %g", threadVariables[i].sum);
      total_sum += threadVariables[i].sum;
    }
    printf("The total is %g, it should be equal to %g\n", total_sum, ((double)N * (N + 1)) / 2);

    free(a); // Free allocated memory
    return 0;
}

