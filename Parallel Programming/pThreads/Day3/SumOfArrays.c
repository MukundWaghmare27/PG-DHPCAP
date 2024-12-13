#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 100
#define T 10

int *arr1;
int *arr2;
int *arr3;

void *ArrSum(void* threadId){
    int tid = *(int*)threadId;
    int chunksize = N / T;
    int start = tid * chunksize;
    int end = (tid+1) * chunksize;

    for(int i=start; i<end; i++){
        arr3[i] = arr1[i] + arr2[i];
    }
}

int main(){
	pthread_t *t;
	t=malloc(sizeof(pthread_t)*T);
	
	arr1=malloc(sizeof(int)*N);
    arr2=malloc(sizeof(int)*N);
    arr3=malloc(sizeof(int)*N);

	for(long i=0; i<N;i++){
		arr1[i]=i+1;
        arr2[i]=i+1;
	}	
	
	for(int i=0; i<T; i++){
		int *a = malloc(sizeof(int));
		*a=i;
		pthread_create(&t[i], NULL, ArrSum, (void*)a);
	}
	for(int i=0; i<T; i++){
		pthread_join(t[i], NULL);
	}

    printf("Sum of Array1 and Arr2:\n");
    for(int i=0; i<N; i++){
        printf("%d ", arr3[i]);
    }

	
	return 0;
}
