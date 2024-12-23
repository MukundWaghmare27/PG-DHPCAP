#include <stdio.h>
#include <omp.h>

int main(){
    omp_set_nested(1);   //routine call for enabling nesting
    #pragma omp parallel num_threads(2)
    {
        int tid = omp_get_thread_num();
        printf("Level tid : %d\n", tid);
        #pragma omp parallel num_threads(4)
        {
            printf("Level 2 tid %d created by %d\n", omp_get_thread_num(), tid);
        }
    }

    return 0;
}


