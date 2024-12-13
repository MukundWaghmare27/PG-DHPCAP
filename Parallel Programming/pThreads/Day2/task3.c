#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 10000 

pthread_mutex_t mutex;

int *arr;
int sum=0;

void *hello(void *threadId){
	int tid = *(int*)threadId;

	arr[tid]=tid;

	pthread_mutex_lock(&mutex);
	sum+=arr[tid];
	pthread_mutex_unlock(&mutex);
	free(threadId);
}

int main(){
	pthread_t *t;
	int i;
	arr = malloc(sizeof(int)*N);
	pthread_mutex_init(&mutex, NULL);
	t=malloc(sizeof(pthread_t)*N);
	
	for(i=0; i<N; i++){
		int *a;
		a=malloc(sizeof(int));
		*a=i;
		pthread_create(&t[i], NULL, hello, (void*)a);
				
	}

	for(i=0;i<N; i++){
		pthread_join(t[i], NULL);
		//printf("%d ", arr[i]);
	}

  	pthread_mutex_destroy(&mutex);
	
	for(i=0; i<N;i++){
		
	}	
	printf("sum: %d \n", sum);	
		
	free(t);

	return 0;
}

