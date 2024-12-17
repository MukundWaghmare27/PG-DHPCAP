//Task1: create 10 threads, one shared (a) variable, for thread 0 a=7 & for other threads a=5

#include <stdio.h>
#include <omp.h>

int main(){
    int a = 5;

	#pragma omp parallel shared (a) num_threads(10)  //by default a is shared so no need to give clause 'shared'
	{
        int tid = omp_get_thread_num();
        if(tid==0) a=7;
        printf("on thread %d value of a = %d\n", tid, a);
    }

    printf("after parallel region thread= %d value of a = %d\n",omp_get_thread_num(), a);
    
	return 0;
}

//Race Condition Occured here

