#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 20

void *hello(void *threadId){
	int tid = *(int*)threadId;

	printf("Hello tid %d of size %d\n", tid, N);
}

int main(){
	pthread_t *t;
	int i;

	t=malloc(sizeof(pthread_t)*N);
	
	for(i=0; i<N; i++){
		pthread_create(&t[i], NULL, hello, (void*)&i);
		///sleep(1);
	}

	for(i=0;i<N; i++){
		pthread_join(t[i], NULL);
	}

	free(t);

	return 0;
}
