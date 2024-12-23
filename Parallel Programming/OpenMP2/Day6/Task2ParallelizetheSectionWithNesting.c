#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define N 10000
#define T 10

int main(){
    int *arr = malloc(sizeof(int)*N);
    long long sum=0, sqSum =0;
    for(int i=0; i<N; i++){
        arr[i] = i+1;
    }
    omp_set_nested(1);
    double startTime = omp_get_wtime();
    #pragma omp parallel num_threads(T)  
    {
        #pragma omp sections 
        {
            #pragma omp section 
            {
                #pragma omp parallel for num_threads(T)
                for(int i=0; i<N; i++){
                    #pragma omp atomic
                    sum += arr[i];
                }
            }
            #pragma omp section
            {    
                #pragma omp parallel for num_threads(T)
                for(int i=0; i<N; i++){
                    #pragma omp atomic
                    sqSum += arr[i] * arr[i];
                }
            }
        }
    }
    double endTime = omp_get_wtime();   

    printf("sum of Array elements: %lld\n", sum);
    printf("sum of square of Array elements: %lld\n", sqSum);
    printf("Time: %lf\n", endTime - startTime);
  
    free(arr);
    return 0;
}




   



