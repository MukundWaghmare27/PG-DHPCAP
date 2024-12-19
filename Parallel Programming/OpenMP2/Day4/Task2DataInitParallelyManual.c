//Take Array initialize it parallely(manual), and calculate sum parallely

#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#define N 1000000
#define T 13

int main(){
    long long *a, sum=0;
    a= malloc(sizeof(long long) * N);
    int chunksize = N/T;

    #pragma omp parallel num_threads(T)
    {
        int tid = omp_get_thread_num();
        int start = tid * chunksize;
        int end = start + chunksize;
        if (tid = T-1) end = N;
        for(int i=start; i<end; i++){
            a[i] = i+1;
        }
        
        #pragma omp for reduction(+:sum)
        for(int i=0; i<N; i++){
            sum += a[i];
        }
    }
    printf("sum = %lld\n", sum);

    return 0;
}


