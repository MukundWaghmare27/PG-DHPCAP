#include<stdio.h>
#include<omp.h>
#define N 10000
#define T 10

int main(){
    #pragma omp parallel num_threads(4)  
    {
        #pragma omp sections 
        {
            for(int i=0; i<4; i++)
        
            #pragma omp section
            {
                printf("This section is executed by thread %d\n", omp_get_thread_num());
            }
        }
    }
}

//if section numbers = total threads 