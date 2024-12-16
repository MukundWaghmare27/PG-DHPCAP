//Task2: create 4 threads, one shared (a) variable, 2 private variable (b,c) to region, for thread 2 b=12 & for other threads b=5, calc c=a+b+tid 

#include <stdio.h>
#include <omp.h>

int main(){
    int tid;
	//omp_set_num_threads(2);   //OpenMP routine call
	#pragma omp parallel num_threads(4)
	{
        int a = 100;
        tid = omp_get_thread_num();
        if(tid == 0){
            int b = 5;
            int c = a + b + tid;
		    printf("on thread %d result of c = %d + %d + %d = %d\n", tid, a, b, tid, c);
        }
        else if(tid == 1){
            int b = 5;
            int c = a + b + tid;
		    printf("on thread %d result of c = %d + %d + %d = %d\n", tid, a, b, tid, c);
        }
        else if(tid == 2){
            int b = 10;
            int c = a + b + tid;
		    printf("on thread %d result of c = %d + %d + %d = %d\n", tid, a, b, tid, c);
        }
        else if(tid == 3){
            int b = 5;
            int c = a + b + tid;
		    printf("on thread %d result of c = %d + %d + %d = %d\n", tid, a, b, tid, c);
        }
	}

	return 0;
}


