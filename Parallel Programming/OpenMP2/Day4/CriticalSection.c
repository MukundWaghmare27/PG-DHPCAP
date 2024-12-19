//Critical Section is clause which used to avoid Race Condition in the code by locking & unlocking the thread access to the critical section

#include <stdio.h>
#include <omp.h>
#define T 5
#define N 100

int main(){
    int sum=0;
    #pragma omp parallel for num_threads(T)
    for(int i=0; i<N; i++){
        #pragma omp critical 
        {
            sum+=i+1;
        }     
    }
    printf("sum = %d\n", sum);

    return 0;
}

