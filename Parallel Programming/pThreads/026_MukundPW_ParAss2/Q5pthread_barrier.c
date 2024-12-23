//5. WAP to demonstrate pthread_barrier

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N 1000000
#define T 16

int arr[N];
pthread_barrier_t barrier;

void *hello(void* threadId) {
    long tid = (long)threadId;
    long *localSum = malloc(sizeof(long)); 
    *localSum = 0;
    int chunk_size = N / T;
    int start = tid * chunk_size;
    int end = (tid + 1) * chunk_size;
    if (tid == T - 1) {
        end = N;
    }
    
    if(tid == 0){
        for (int i = 0; i < N; i++) {
                arr[i] = i + 1;
        }
    }
    pthread_barrier_wait(&barrier);

    for (int i = start; i < end; i++) {
        *localSum += arr[i];
    }

    return (void*)localSum;
}

int main() {
    pthread_t threads[T];
    void *status;
    long sum = 0;

    pthread_barrier_init(&barrier, NULL, T);

    for (long i = 0; i < T; i++) {
        pthread_create(&threads[i], NULL, hello, (void*)i);
    }

    for (long i = 0; i < T; i++) {
        pthread_join(threads[i], &status);
        sum += *(long*)status;
        free(status); 
    }

    pthread_barrier_destroy(&barrier);

    printf("Sum using manual reduction: %ld\n", sum);

    return 0;
}
