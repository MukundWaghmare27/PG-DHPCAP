//Task2: Define Array, initialize it and print it paralally

#include <stdio.h>
#include <omp.h>

#define N 100
#define T 10

int main(){
    int a[N];
    for(int i=0; i<N; i++){
        a[i]=i;
    }
    int chunksize = N / T;

	#pragma omp parallel num_threads(T)  
	{
        int tid = omp_get_thread_num();
        int start = tid * chunksize;
        int end = (tid+1) * chunksize;

        for(int i=start; i<end; i++){       //manually dividing data into threads
            printf("tid %d = %d\n",tid, a[i]);
        }
        //printf("\n");
    }
	return 0;
}



