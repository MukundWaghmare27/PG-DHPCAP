#include<stdio.h>
#include<omp.h>
#include <stdlib.h>

#define N 100000
#define T 10

int main(){
    int *arr = malloc(sizeof(int)*N);
    long long sum=0, sqSum =0;
    for(int i=0; i<N; i++){
        arr[i] = i+1;
    }

    #pragma omp parallel num_threads(4)  
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                printf("thread %d executing array sum program\n", omp_get_thread_num());
                for(int i=0; i<N; i++)
                    sum += arr[i];
            }
            #pragma omp section
            {    
                printf("thread %d executing square of array program\n", omp_get_thread_num());
                for(int i=0; i<N; i++){
                    sqSum += arr[i] * arr[i];
                }
            }
        }   
    }

    printf("sum of Array elements: %lld\n", sum);
    printf("sum of square of Array elements: %lld\n", sqSum);

    free(arr);
    return 0;
}
   



