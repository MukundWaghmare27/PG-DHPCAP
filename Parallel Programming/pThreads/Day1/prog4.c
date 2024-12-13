#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *hello(){
	printf("Helllllloo\n");
	sleep(5);
	printf("Worlddddddd\n");
}

void *bye(){
	printf("Byeeeeeeeeee...!\n");
	sleep(5);
	printf("Good Night\n");
}

int main(){
	pthread_t t[5], t2[5];

	for(int i=0; i<5;i++){
		pthread_create(&t[i], NULL, hello, NULL);
        	pthread_create(&t2[i], NULL, bye, NULL);
        	pthread_join(t[i], NULL);
        	pthread_join(t2[i], NULL);
	}
	
	return 0;
}
