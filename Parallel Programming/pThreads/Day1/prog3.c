#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *hello(){
	printf("Helllllloo\n");
	sleep(10);
	printf("Worlddddddd\n");
}

void *bye(){
	printf("Byeeeeeeeeee...!\n");
	sleep(10);
	printf("Good Night\n");
}

int main(){
	pthread_t t, t2;
	pthread_create(&t, NULL, hello, NULL);
	pthread_create(&t2, NULL, bye, NULL);
	pthread_join(t, NULL);
	pthread_join(t2, NULL);

	return 0;
}
