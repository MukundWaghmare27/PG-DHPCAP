//2. Implementation of reduction in pthread (alternative)

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define N 100000
#define T 16

long globalArraySum[T];
int arr[N];

void *hello(void* threadId){
    long tid = (long)threadId;
    long localSum = 0;
    int chunk_size = N / T;
    int start = tid * chunk_size;
    int end = (tid + 1) * chunk_size;
    if (tid == T - 1) {
        end = N;
    }
    for (int i = start; i < end; i++) {
        localSum += (long)arr[i];
    }
    globalArraySum[tid] = localSum;
    return NULL;
}

int main(){
    for(int i = 0; i < N; i++){
        arr[i] = i + 1;
    }
    pthread_t* t;
    t = malloc(sizeof(pthread_t) * N);

    for(long i = 0; i < T; i++)
        pthread_create(&t[i], NULL, hello, (void*)i);
    for(long i = 0; i < T; i++)
        pthread_join(t[i], NULL);
    long sum = 0;
    for(int i = 0; i < T; i++){
        sum+= globalArraySum[i];
    }
    
    printf("Sum using manual reduction: %ld\n", sum);
   
    free(t);
    return 0;
}
