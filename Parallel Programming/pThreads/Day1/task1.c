#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


void *hello(){
	printf("Helloo...!\n");
	sleep(20);
	printf("world\n");
}

int main(){
	pthread_t t[50];
	for(int i=0; i<50; i++){
		pthread_create(&t[i], NULL, hello, NULL);
	        //printf("%d\n", t[i]);	
	}
	for(int i=0; i<50;i++){
		pthread_join(t[i], NULL);
	}
	
	return 0;
}
