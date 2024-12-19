//Take Array initialize it parallely, and calculate sum parallely
//'for' have implicit barrier, so the threads will only start next task after previous task get completed

#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#define N 1000000
#define T 13

int main(){
    long long *a, sum=0;
    a= malloc(sizeof(long long) * N);
                                                             
    #pragma omp parallel num_threads(T)
    {
        #pragma omp for
        for(int i=0; i<N; i++){
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


