//Sum of N natural numbers with Manual Reduction

#include <stdio.h>
#include <omp.h>

#define N 1000000000
#define T 10

int main(){
    long long sum[T];
    long long chunksize = N/T;

    #pragma omp parallel num_threads(T)
    {
        int tid = omp_get_thread_num();
        long long localsum = 0;
        int start = tid * chunksize;
        int end = start + chunksize;
        if(tid == T-1) end = N;
        for(int i=start; i<end; i++){
            localsum += i+1;
        }
        sum[tid] = localsum;
    }
    long long totalsum =0;
    for(int i=0; i<T; i++){
        totalsum += sum[i];
    }
    printf("Total Sum : %lld\n", totalsum);
    printf("Calculated sum = %lld\n", totalsum);
    long long expectedSum = (N * ((N + 1) * 1L) / 2);
    printf("Expected sum = %lld\n", expectedSum);
    if(totalsum == expectedSum){
        printf("_____Passed_____\n");
    }
    else printf("_____Failed_____\n");


    return 0;
}