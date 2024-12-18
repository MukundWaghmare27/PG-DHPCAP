//Calculating Time For Serial & Parallel Code

#include<stdio.h>
#include<omp.h>
#define N 1000000000
#define T 13

int main(){
    long long sum = 0;
    double startTime, EndTime, parallelTime, SerialTime;
    startTime = omp_get_wtime();
    #pragma omp parallel for reduction(+ : sum) num_threads(T)
    for(int i = 0; i < N; i++){
        sum += i + 1;
    }
    EndTime = omp_get_wtime();
    parallelTime = EndTime - startTime;

    startTime = omp_get_wtime();
    long long serialSum =0;
    for(long i=0; i<N; i++){
        serialSum += i+1;
    }
    EndTime = omp_get_wtime();
    SerialTime = EndTime - startTime;

    printf("Parallel Time = %lf\n", parallelTime);
    printf("Serial Time = %lf\n", SerialTime);

    printf("Calculated sum = %lld\n", sum);
    long long expectedSum = (N * ((N + 1) * 1L) / 2);
    printf("Expected sum = %lld\n", expectedSum);
    if(sum == expectedSum){
        printf("_____Passed_____\n");
    }
    else printf("_____Failed_____\n");

    return 0;
}