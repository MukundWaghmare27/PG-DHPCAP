#include <stdio.h>
#include <omp.h>

#define N 20
#define T 3

int main(){
    
    omp_set_schedule(omp_sched_dynamic, 4);   //used to specify globally, applied on every parallel region
    #pragma omp parallel for schedule(runtime) num_threads(T)
    for(int i=0; i<N; i++){
        printf("thread\t%d\t:i\t%d\n", omp_get_thread_num(), i);
    }
}

//if you want to use separate 'Schedule' for another Parallel region, can use the Clause
//Clause have more priority over global scheduling, because clause is local  



