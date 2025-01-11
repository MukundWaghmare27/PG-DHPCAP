#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#define N 100000

int main(){
    long *arr = (long*)malloc(sizeof(long)*N);
    long sum = 0;
    for(int i=0; i<N; i++){
        arr[i] = i+1;
    }

    double starttime = omp_get_wtime();
    #pragma omp parallel for default(none) shared(arr) reduction(+:sum) num_threads(13)
    for(int i=0; i<N; i++){
        sum += arr[i];
    }
    double endtime = omp_get_wtime();

    printf("Sum of Array Elements is %ld\n", sum);
    printf("Time taken: %lf\n", endtime - starttime);

    free(arr);
    return 0;

}
