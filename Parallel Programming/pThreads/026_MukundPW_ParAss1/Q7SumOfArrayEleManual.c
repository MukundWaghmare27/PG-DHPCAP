#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 20

int *arr;
int sum = 0;

void *hello(void *threadId) {
    int tid = *(int *)threadId;
    arr[tid] = tid; 

    printf("On tid %d, value is %d\n", tid, arr[tid]);
    free(threadId);
    return NULL;
}

int main() {
    pthread_t *t;
    int i;

    arr = malloc(sizeof(int) * N);
    t = malloc(sizeof(pthread_t) * N);

    for (i = 0; i < N; i++) {
        int *a = malloc(sizeof(int));
        *a = i;
        pthread_create(&t[i], NULL, hello, (void *)a);
    }

    for (i = 0; i < N; i++) {
        pthread_join(t[i], NULL); 
    }

    for (i = 0; i < N; i++) {
        sum += arr[i];
    }

    printf("Sum of array elements is %d\n", sum);

    free(arr);
    free(t);
    return 0;
}
