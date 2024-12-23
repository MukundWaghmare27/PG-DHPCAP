#include<stdio.h>
#include<omp.h>
#define N 10000
#define T 10

int main(){
    #pragma omp parallel num_threads(4)  
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                printf("This section %d is executed by thread %d\n", omp_get_thread_num());
            }
            #pragma omp section
            {
                printf("This section 2 is executed by thread %d\n", omp_get_thread_num());
            }
            #pragma omp section
            {
                printf("This section 3 is executed by thread %d\n", omp_get_thread_num());
            }
            #pragma omp section
            {
                printf("This section 4 is executed by thread %d\n", omp_get_thread_num());
            }
        }
    }
}

//if section numbers = total threads, every thread will execute each section
//if section numbers > total threads, which threads are free they will execute the program