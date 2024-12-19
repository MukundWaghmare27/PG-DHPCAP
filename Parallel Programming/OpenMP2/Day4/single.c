//in the single section, any one thread can access the section and perform operation
//in master section only master (thread=0) can access the section, so the master thread can be overburden or accupied by another work, to overcome that problem we use single section

#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#define T 10

int main(){
    #pragma omp parallel num_threads(T)
    {
        #pragma omp single
        {
            printf("%d have an extra statement to execute\n", omp_get_thread_num());
        }
        printf("Hi, I am thread %d\n", omp_get_thread_num());
    }

    return 0;
}

