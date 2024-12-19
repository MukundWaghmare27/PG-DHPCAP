//lastprivate is clause which carry the last value of variable to outside of the parallel region

#include <stdio.h>
#include <omp.h>
#define T 5
#define N 20

int main(){
    int a=5;
    #pragma omp parallel for lastprivate(a) num_threads(T)
    for(int i=0; i<N; i++){
        if(i>15){
            continue;
        }
        a=i;     
    }
    printf("a = %d\n", a);

    return 0;
}

//In this program we have skipping the iteration after 15 which are allocated for the 5th thread to perform, so the last thread don't initialized with any value, so outside of parallel region value of 'a' will be 0/garbage 
