#include <stdio.h>
#include <omp.h>

int main(){
    int tid;
	//omp_set_num_threads(2);   //OpenMP routine call
	#pragma omp parallel num_threads(2)
	{
        tid = omp_get_thread_num();
        if(tid == 0){
		    printf("Hello Shavak from thread: %d\n", tid);
        }
        else if(tid == 1){
            printf("Bye shavak from thread: %d\n", tid);
        }
	}

	return 0;
}


