#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 20

int *arr;

void *hello(void *threadId){
	int tid = *(int*)threadId;
	//int i=tid;
	arr[tid]=tid;
	//if(tid==i){
	printf("on tid %d value if %d\n", tid, arr[tid]);
	free(threadId);		
	//	i++;
	//}
}

int main(){
	pthread_t *t;
	int i;
	arr = malloc(sizeof(int)*N);
	t=malloc(sizeof(pthread_t)*N);
	
	for(i=0; i<N; i++){
		int *a;
		a=malloc(sizeof(int));
		*a=i;
		pthread_create(&t[i], NULL, hello, (void*)a);
				
	}

	for(i=0;i<N; i++){
		pthread_join(t[i], NULL);
		printf("%d ", arr[i]);
	}
	
		
	free(t);

	return 0;
}
