//Task2: Define Array, initialize it and print it paralally


#include <stdio.h>
#include <omp.h>

#define N 100
#define T 10

int main(){
    int a[N];
    for(int i=0; i<N; i++){
        a[i]=i;
    }
   
	#pragma omp parallel num_threads(T)  
	{
        int sum=0;
        #pragma omp for
        for(int i=0; i<N; i++){    
            printf("%d ", a[i]);
        }
        printf("\n");
    }
	return 0;
}



