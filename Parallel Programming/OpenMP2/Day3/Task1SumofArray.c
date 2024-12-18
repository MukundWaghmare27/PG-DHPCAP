//Task1: c[i] = a[i] + b[i] with Serial & paralle method and measure time

#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define N 1000000
#define T 10

int main(){
    long long *a, *b, *c;
    a = (long long*)malloc(sizeof(long long) * N);
    b = (long long*)malloc(sizeof(long long) * N);
    c = (long long*)malloc(sizeof(long long) * N);
    //int a[N], b[N], c[N];

    for(long long i=0; i<N; i++){
        a[i] = i+1;
        b[i] = i+1;
    }
    double startTime = omp_get_wtime();
    #pragma omp parallel for num_threads(T)
    for(long long i=0; i<N;i++){
        c[i] = a[i] + b[i];
    }
    double EndTime = omp_get_wtime();
    double ParTime = EndTime - startTime;

    startTime = omp_get_wtime();
    for(long long i=0; i<N; i++){
        c[i] = a[i] + b[i];
    }
    EndTime = omp_get_wtime();
    double SerTime = EndTime - startTime;

    printf("Parallel Resultant Array of size %d: \n", N);
    for(int i=N-5; i<N; i++){
        printf("%lld ", c[i]);
    }
    printf("\n");
    printf("Serial Resultant Array of size: %d \n", N);
    for(int i=N-5; i<N; i++){
        printf("%lld ", c[i]);
    }
    printf("\n\n");

    printf("Parallel Time: %lf\n", ParTime);
    printf("Serial Time: %lf\n", SerTime);

    free(a);
    free(b);
    free(c);
    return 0;
}