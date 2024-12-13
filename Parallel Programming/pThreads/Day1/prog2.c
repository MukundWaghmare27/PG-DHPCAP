#include <stdio.h>
#include <pthread.h>

void *hello(){
	printf("Helllllloo\n");
}

void *bye(){
	printf("Byeeeeeeeeee...!\n");
}

int main(){
	pthread_t t;
	pthread_create(&t, NULL, hello, NULL);
	pthread_join(t, NULL);

	pthread_t t2;
	pthread_create(&t2, NULL, bye, NULL);
	pthread_join(t2, NULL);

	return 0;
}
