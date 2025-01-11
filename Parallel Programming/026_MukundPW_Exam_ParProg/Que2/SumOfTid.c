#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define T 15

int sum = 0;
pthread_mutex_t mutex;

void *SumOfTid(void *threadId) {
    int tid = *(int*)threadId;

    pthread_mutex_lock(&mutex);
    sum += tid;
    pthread_mutex_unlock(&mutex);

    free(threadId);
    return NULL;
}

int main() {
    pthread_t *t;

    pthread_mutex_init(&mutex, NULL);
    t = (pthread_t*)malloc(sizeof(pthread_t) * T);

    for (int i = 0; i < T; i++) {
        int *a = (int*)malloc(sizeof(int));
        *a = i;
        pthread_create(&t[i], NULL, SumOfTid, (void*)a);
    }

    for (int i = 0; i < T; i++) {
        pthread_join(t[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    printf("Sum of All Thread Id's is %d\n", sum);

    free(t);

    return 0;
}
