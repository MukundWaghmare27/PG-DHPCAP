//Task1: create 10 threads, one shared (a) variable, for thread 0 a=7 & for other threads a=5

#include <stdio.h>
#include <omp.h>

int main(){
    int a = 5;

	#pragma omp parallel private(a) num_threads(10) //a is private declared for every thread, a=0/garbage
            //address of a will be different for all threads  
	{
        int tid = omp_get_thread_num();
        if(tid==3) a=7;        //a=7 for tid =0
        printf("on thread %d value of a = %d\n", tid, a); //for tid!=0 value of a=0/garbage
    }

    printf("after parallel region thread= %d value of a = %d\n",omp_get_thread_num(), a);
    
	return 0;
}


