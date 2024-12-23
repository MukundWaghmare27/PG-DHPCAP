#include <stdio.h>
#include <omp.h>
#define N 10000
#define T 10

int main(){
    int sum=0;
    #pragma omp parallel for num_threads(T)
    for(int i=0; i<N; i++){
        #pragma omp atomic 
        sum += i+1;
    }
    printf("Sum = %d\n", sum);

    return 0;
}

