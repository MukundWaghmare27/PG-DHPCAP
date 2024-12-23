#include<stdio.h>
#include<omp.h>
#define N 20
#define T 6

int main(){
    #pragma omp parallel for schedule(static, 3) num_threads(T)
    for(int i = 0; i < N; i++){
        printf("thread\t%d\t:\ti\t%d\n", omp_get_thread_num(), i);
    }
}

//Static Scheduling-->clause-->schedule(static,3)

//threads = 3
//chunksize = 3

//iteration:  1    2   3    4   5   6  7   8   9    10
//           -----------   ----------  ----------   --- 
//            Thread 0      Thread 1    Thread 2   Thread 0




