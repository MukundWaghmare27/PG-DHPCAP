#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 20

int *arr;
int sum=0;

void *hello(void *threadId){
	int tid = *(int*)threadId;

	arr[tid]=tid;

	printf("on tid %d value if %d\n", tid, arr[tid]);
	free(threadId);		

}

void *Sum(void *threadId){
	int tid= *(int*)threadId;
	arr[tid]=tid;
	sum+=arr[tid];
}

int main(){
	pthread_t *t, *t2;
	int i, sum=0;
	arr = malloc(sizeof(int)*N);
	t=malloc(sizeof(pthread_t)*N);
	t2=malloc(sizeof(pthread_t)*N);
	
	for(i=0; i<N; i++){
		int *a;
		a=malloc(sizeof(int));
		*a=i;
		pthread_create(&t[i], NULL, hello, (void*)a);
				
	}
	
	for(i=0; i<N; i++){
		int *a;
                a=malloc(sizeof(int));
                *a=i;
		pthread_create(&t2[i], NULL, Sum, (void*)a);
	}
	

	for(i=0;i<N; i++){
		pthread_join(t[i], NULL);
		//printf("%d ", arr[i]);
	}
	
		
	
	printf("sum of array element is %d\n", sum);
		
	free(t);

	return 0;
}
