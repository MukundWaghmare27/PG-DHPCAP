//Don't Try this on your Own laptop

#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#define N 20000
#define T 13

int main(){
    int **a, **b, **c;
    a = (int**) malloc(sizeof(int*) * N);
    b = (int**) malloc(sizeof(int*) * N);
    c = (int**) malloc(sizeof(int*) * N);

    for(int i = 0; i < N; i++){
        a[i] = (int*) malloc(sizeof(int) * N);
        b[i] = (int*) malloc(sizeof(int) * N);
        c[i] = (int*) malloc(sizeof(int) * N);
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            a[i][j] = j + 1;
            b[i][j] = j + 1;
            c[i][j] = 0;
        }
    }
    double startTime = omp_get_wtime();
    #pragma omp parallel for num_threads(T)
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    double endTime = omp_get_wtime();
    double ParTime = endTime - startTime;

    startTime = omp_get_wtime();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    endTime = omp_get_wtime();
    double SerTime = endTime - startTime;

    for(int i = N - 1; i < N; i++){
        for(int j = N - 50; j < N; j++){
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    printf("parallel Time: %lf\n", ParTime);
    printf("Serial Time: %lf\n", SerTime);

    for(int i = 0; i < N; i++){
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);

    return 0;
}