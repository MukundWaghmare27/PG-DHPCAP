#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define T 5

void *Func(){
	int *localVal;
	localVal = malloc(sizeof(int));
	*localVal = 786;
	return (void*)localVal;
}

int main(){
	pthread_t *t;
	t=malloc(sizeof(pthread_t)*T);
	int localVal;
	for(int i=0; i<T; i++){
		pthread_create(&t[i], NULL, Func, NULL);
	}
	for(int i=0; i<T; i++){
		pthread_join(t[i], (void**)&localVal);
		printf("%d from thread %d\n", localVal, i);
	}
	free(t);

	return 0;
}


