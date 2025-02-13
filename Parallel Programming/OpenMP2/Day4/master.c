//in the master section, only master thread (thread=0) can access and perform operation

#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#define T 10

int main(){
    #pragma omp parallel num_threads(T)
    {
        #pragma omp master
        {
            printf("%d have an extra statement to execute\n", omp_get_thread_num());
        }
        printf("Hi, I am thread %d\n", omp_get_thread_num());
    }

    return 0;
}