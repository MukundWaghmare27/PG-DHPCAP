//Task2: Define Array, initialize it and print it paralally

#include <stdio.h>
#include <omp.h>

#define N 100

int main(){
    int sum=0;

	#pragma omp parallel num_threads(10)  
	{
        #pragma omp for
        for(int i=1; i<N; i++){    
            sum += i;
        }
    }
    printf("%d\n", sum);

	return 0;
}

//Race Condition is occuring in this program while calculating sum

