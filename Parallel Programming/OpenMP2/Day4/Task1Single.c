//Take Array initialize it using single or master section, and calculate sum parallely
//Note:
//if we are using master section to initialize values, then can be happen that master thread get busy in initializing the data, and other threads can start computation of the uninitialized data, so it can/will be result in wrong output
//so we used single section to initialize data, the single will start initialize the data, till the data is initializing, others threads will wait till the initialisation get completed, 'single' have implicit/inbuilt barrier

#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#define N 1000000
#define T 13

int main(){
    long long *a, sum=0;
    a= malloc(sizeof(long long) * N);

    #pragma omp parallel num_threads(T)
    {
        #pragma omp single
        //if(omp_get_thread_num()==7)
        {
            for(int i=0; i<N; i++){
                a[i] = i+1;
            }
        }
        #pragma omp for reduction(+:sum)
        for(int i=0; i<N; i++){
            sum += a[i];
        }
    }
    printf("sum = %lld\n", sum);

    return 0;
}


