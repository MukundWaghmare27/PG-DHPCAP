#include <stdio.h>
#include <omp.h>

#define N 20
#define T 3

int main(){
    #pragma omp parallel for schedule(runtime) num_threads(T)
    for(int i=0; i<N; i++){
        printf("thread\t%d\t:i\t%d\n", omp_get_thread_num(), i);
    }
}