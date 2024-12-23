//4. WAP to demonstrate pthread_exit

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N 1000000
#define T 20

int arr[N];

void *hello(void* threadId) {
    long tid = (long)threadId;
    long localSum = 0;
    int chunk_size = N / T;
    int start = tid * chunk_size;
    int end = (tid + 1) * chunk_size;
    if (tid == T - 1) {
        end = N;
    }

    for (int i = start; i < end; i++) {
        localSum += arr[i];
    }

    pthread_exit((void*) localSum);
}

int main() {
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    pthread_t threads[T];
    void *status;
    long sum = 0; 

    for (long i = 0; i < T; i++) {
        pthread_create(&threads[i], NULL, hello, (void*)i);
    }

    for (long i = 0; i < T; i++) {
        pthread_join(threads[i], &status);
        sum += (long)status;
    }

    printf("Sum using manual reduction: %ld\n", sum);

    return 0;
}
