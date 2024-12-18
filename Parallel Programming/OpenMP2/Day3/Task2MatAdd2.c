//Task1: c[i][j] = a[i][j] + b[i][j] with Serial & paralle method and measure time

#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define N 100000
#define T 10

int main(){
    long long** a = (long long**)malloc(N * sizeof(long long*));
    long long** b = (long long**)malloc(N * sizeof(long long*));
    long long** c = (long long**)malloc(N * sizeof(long long*));
    for (int i = 0; i < N; i++) {
        a[i] = (long long*)malloc(N * sizeof(long long));
        b[i] = (long long*)malloc(N * sizeof(long long));
        c[i] = (long long*)malloc(N * sizeof(long long));
    }
    //int a[N][N], b[N][N], c[N][N];

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            a[i][j] = j+1;
            b[i][j] = j+1;
        }
    }
    double startTime = omp_get_wtime();
    #pragma omp parallel for num_threads(T)
    for(int i=0; i<N;i++){
        for(int j=0; j<N; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    double EndTime = omp_get_wtime();
    double ParTime = EndTime - startTime;

    startTime = omp_get_wtime();
    for(int i=N-10; i<N; i++){
        for(int j=0; j<N; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    EndTime = omp_get_wtime();
    double SerTime = EndTime - startTime;

    printf("Parallel Resultant matrix of size %d: \n", N);
    for(int i=N-5; i<N; i++){
        for(int j=N-5; j<N; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Serial Resultant matrix of size: %d \n", N);
    for(int i=N-5; i<N; i++){
        for(int j=N-5; j<N; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Parallel Time: %lf\n", ParTime);
    printf("Serial Time: %lf\n", SerTime);

    free(a);
    free(b);
    free(c);
    return 0;
}