#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 10000
#define T 10

int *arr;
long *arr2;
long Sum=0;

//pthread_mutex_t mutex;

void *ArrSum(void* threadId){

	long tid = *(long*)threadId;
	long localSum=0;
	int chunksize=N/T;
	long start = tid * chunksize;
	long end = start + chunksize;
	
	for(long i=start; i<end; i++){
		localSum+=(long)arr[i];
	}
	
//	for(int i=0; i<T; i++){
	arr2[tid]=localSum;	
//	}	
	//pthread_mutex_lock(&mutex);
	//Sum+=localSum;
	//pthread_mutex_unlock(&mutex);
	return NULL;
}

int main(){
	pthread_t *t;
	//long Sum=0;
//	pthread_mutex_init(&mutex, NULL);
	t=malloc(sizeof(pthread_t)*T);
	arr2=malloc(sizeof(long)*T);	
	arr=malloc(sizeof(int)*N);
	for(long i=0; i<N;i++){
		arr[i]=i+1;
	}	
	
	
	for(int i=0; i<T; i++){
		int *a = malloc(sizeof(int));
		*a=i;
		pthread_create(&t[i], NULL, ArrSum, (void*)a);
	}
	for(int i=0; i<T; i++){
		pthread_join(t[i], NULL);
	}

//	pthread_mutex_destroy(&mutex);
	
	//printf("Sum of Array: %ld\n", Sum);
	for(int i=0; i<T; i++){
		Sum +=arr2[i];		
	}
	printf("Sum of Array: %ld\n", Sum);	
	
	return 0;
}
