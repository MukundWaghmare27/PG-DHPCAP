//Sum of N natural numbers

#include <stdio.h>
#include <omp.h>

#define N 100000
#define T 10

int main(){
    long long sum=0;
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
        #pragma omp critical
        {
        sum += localsum;
        }
    }
    printf("Calculated sum = %lld\n", sum);

    long long expectedSum = (N * ((N + 1) * 1L) / 2);
    printf("Expected sum = %lld\n", expectedSum);
    if(sum == expectedSum){
        printf("_____Passed_____\n");
    }
    else printf("_____Failed_____\n");


    return 0;
}