#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#define N 10000000
#define T 10
int main(){
    long long  sum = 0;
    double startCritical = omp_get_wtime();
    #pragma omp parallel for num_threads(10)
    for(long long i = 0; i < N; i++){
        #pragma omp critical
        {
            sum+= i + 1;
        }
    }
    printf("Critical Sum = %lld\n", sum);
    double endCritical = omp_get_wtime();

    sum = 0;
    double startAtomic = omp_get_wtime();
    #pragma omp parallel for num_threads(10)
    for(long long i = 0; i < N; i++){
        #pragma omp atomic
        sum+= i + 1;
    }
    printf("Atomic Sum = %lld\n", sum);
    double endAtomic = omp_get_wtime();
    printf("Time taken by critical section : %lf\n", endCritical - startCritical);
    printf("Time taken by atomic: %lf\n", endAtomic - startAtomic);

    return 0;
}

//measuring time difference between critical section and atomic section