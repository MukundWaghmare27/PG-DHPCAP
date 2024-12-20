#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


void *hello(){
	printf("Helloo...!\n");
	sleep(2);
	printf("world\n");
}

int main(){
	int N;
	printf("Enter number of threads: \n");
	scanf("%d", &N);

	pthread_t t[N];
	for(int i=0; i<N; i++){
		pthread_create(&t[i], NULL, hello, NULL);
	        //printf("%d\n", t[i]);	
	}
	for(int i=0; i<N;i++){
		pthread_join(t[i], NULL);
	}
	
	return 0;
}
