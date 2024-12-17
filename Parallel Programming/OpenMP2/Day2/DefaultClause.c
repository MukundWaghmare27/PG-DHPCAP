//Task1: create 10 threads, one shared (a) variable, for thread 0 a=7 & for other threads a=5
#include <stdio.h>
#include <omp.h>

int main(){
    int a = 5;

	#pragma omp parallel default(none) shared(a) num_threads(10)   
	{
        int tid = omp_get_thread_num();
        if(tid==3) a=7;        //a=7 for tid =0
        printf("on thread %d value of a = %d address of a = %p\n", tid, a, &a); //for tid!=3, a=5
    }

    printf("after parallel region thread= %d value of a = %d address of a= %p\n",omp_get_thread_num(), a, &a);
    
	return 0;
}

//Now Race Condition is Not Occuring


