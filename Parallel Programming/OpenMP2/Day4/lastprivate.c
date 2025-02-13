//lastprivate is clause which carry the last value of variable to outside of the parallel region

#include <stdio.h>
#include <omp.h>
#define T 10
#define N 20

int main(){
    int a=5;
    #pragma omp parallel for lastprivate(a) num_threads(T)
    for(int i=0; i<N; i++){
        a=i;      //last 'a' value will be 19, so outside parallel region the value of 'a' will be 19 
    }
    printf("a = %d\n", a);

    return 0;
}